// src/fallout/ai/middlehighprocess_gs_nogs_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/ai/middlehighprocess.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /Od /Oy- /GS- /EHsc /Gy (unit lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


#include "middlehighprocess_decls.h"
bool IsValidSandboxProcedure(int aiProcedure);
int __fastcall FUN_006377e0(int param_1);
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct TESForm;
struct TESObjectREFR;
struct PackageTargetRecord
{
    int GetTargetKind();
    TESForm* GetTargetForm();
    int GetTargetObjectType();
    int GetTargValue();
    float GetTargAcquireRadius();
    void SetTargetKind(int);
    void SetTargetObjectReference(TESObjectREFR*);
    void SetTargObject(TESForm*);
    void SetTargObjectType(int);
    void SetTargValue(int);
    void SetTargAcquireRadius(float);
    bool GetIsValidTarget(TESForm*);
    void Copy(PackageTargetRecord*);
    bool Compare(PackageTargetRecord*);
    void Save(int);
    void InitItem(TESForm*);
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame();
    void InitLoadGame(BGSLoadFormBuffer*);
    void InitLoadGame();
    TESObjectREFR* GetReferenceTarget();
    void* __vecDelDtor(unsigned int);
    unsigned char m_uiTargetType;
    char _pad_1[3];
    int eObjType;
    int iValue;
    float m_fTargetValue;
};
typedef char _sizecheck_PackageTarget[sizeof(PackageTargetRecord) == 16 ? 1 : -1];
struct FUN_006801a0_shell : public PackageTargetRecord
{
    void FUN_006801a0(PackageTargetRecord*);
};
struct ObjA
{
    void FUN_0044dd60();
    void FUN_0092c870();
};
struct FUN_006f74f0_cls
{
    ObjA* p;
    FUN_006f74f0_cls* FUN_006f74f0(ObjA* o);
};
struct BGSSaveLoadGame
{
    bool FUN_0042ce10();
};
struct DH
{
    bool FUN_004226e0();
};
struct TESObjectREFRHelper
{
    void SetMarkerState(unsigned char a, bool b);
    void SetMarkerState(int a, bool b);
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern DH* g_dataHandler;
struct FUN_00914b40_cls
{
    char pad0[0x40];
    TESObjectREFRHelper* ref40;
    char pad1[0x140 - 0x44];
    TESObjectREFRHelper* furniture;
    unsigned char furnIndex;
    char pad2[0x1a8 - 0x145];
    int idx1a8;
    void FUN_00914b40();
};
struct FUN_00915400_shell : public MiddleHighProcess
{
    void FUN_00915400();
};
void __fastcall FUN_00483710(void*);
void __fastcall FUN_00914b40(void*);
struct LowProcess_helper
{
    void SetFlag40(int);
};
struct Actor;
struct ActorCause;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct CHUNK;
struct CellMopp;
struct GameFormRecord;
struct DialogueResponse;
struct TeleportableReference;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct BooleanIntegerAccessor;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct MapMarkerData;
struct MobileObject;
struct Point3Offset;
struct NiAVObject;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkCharacterController;
struct bhkNiCollisionObject;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};
struct FUN_00915ef0_shell : public MiddleHighProcess
{
    bool FUN_00915ef0(Actor*);
};
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
struct TESAnimGroup;
struct TESIdleForm;
struct TESObjectREFR;
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
    NiPoint3 m_kNodeTranslation;
    NiPoint3 m_kRootTranslation;
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
struct FUN_0091fe80_shell : public MiddleHighProcess
{
    void FUN_0091fe80(Animation*);
};
void* __cdecl memset(void*, int, unsigned int);
void __cdecl AddAnimationToGarbageCollector(Animation*);
bool __cdecl FUN_0092a980(int aeProcedure);
struct AVOwnerIf
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual double V0c(int av);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual double V20(int av);
};
struct ExtraDataListX
{
    bool FUN_00418a80() const;
};
struct ActorX
{
    char pad[0xa4];
    AVOwnerIf avOwner;
    const ExtraDataListX* GetExtra() const;
};
struct FUN_0092c720_cls
{
    void FUN_008acf70(unsigned int flag, bool v);
    void UpdateActorFlags(ActorX* actor);
};
struct ObjB
{
    void FUN_004b0ef0();
    void FUN_0092c870();
};
struct FUN_0092c8b0_cls
{
    ObjB* p;
    FUN_0092c8b0_cls* FUN_0092c8b0(ObjB* o);
};
struct P03MM
{
    void* Allocate(unsigned int);
};
struct MemoryManager
{
    void* Allocate(unsigned int);
};
MemoryManager* __cdecl FUN_00401020(void);
void* __cdecl FormHeap_Allocate(unsigned int size);
struct QueuedItemList
{
    PaddedFloatRecord** _ref_006815c0();
    QueuedItemList* _ref_00726070();
};
struct MiddleHighProcessQ
{
    bool HasMatchingQueuedItem(TESBoundObject* apObject, ExtraDataList* apExtra, bool abEquipped);
};
extern NiFixedString* DAT_011c61b0;
NiFixedString* FUN_00920b60();
extern NiFixedString* DAT_011c61b8;
NiFixedString* FUN_00920b70();
struct FUN_008843a0_shell
{
    bool FUN_008843a0();
};
struct FUN_00568650_shell
{
    float FUN_00568650();
};
struct FUN_008bb5c0_shell
{
    bool FUN_008bb5c0(float afAngle, int aiFlags);
};
struct FUN_00921350_shell : public MiddleHighProcess
{
    void UpdateFurnitureAlignment(Actor* apActor);
};
struct DummyFlags
{
    int FUN_00621270(int);
    bool FUN_009269f0();
};
struct T_
{
    void FUN_004a3f10(void*);
    void ForwardToMember(int param);
};
struct StandIn_00929220
{
    void FUN_00929220(int value);
};
struct FUN_00929240_Class
{
    char m_auiShapeKeys[0x34];
    float m_f34;
    void FUN_00929240(float value);
};
struct FUN_00929d20Class
{
    unsigned char m_00;
    unsigned char m_01;
    unsigned char m_02;
    unsigned char m_03;
    unsigned char m_04;
    bool FUN_00929d20();
};
struct FUN_0092b440_Class
{
    unsigned char m_auiShapeKeys[5];
    unsigned char m_byte5;
    unsigned int GetByte5();
};
struct FUN_0092b7f0_Class
{
    void ClearState();
};
struct FUN_009b4d90
{
    void* pSource;
    void* pTarget;
    void* pProjectile;
    unsigned int eWeaponAV;
    int iHitLocation;
    float m_fDamage;
    float fWeaponBaseDamage;
    float m_fHealthDamage;
    float fLimbDamage;
    float fBlockDTMod;
    float m_fSneakAttackMultiplier;
    float fWeaponDamage;
    void* pWeapon;
    float fHealthPercent;
    NiPoint3 ImpactPos;
    NiPoint3 ImpactAngle;
    bool bFlag50;
    void* pExtra;
    unsigned int uiFlags;
    float m_fDamageMultiplier;
    int iUnk60;
    FUN_009b4d90();
    void FUN_009b4ec0(FUN_009b4d90* apData);
};
struct MiddleHighProcessS : MiddleHighProcess
{
    void FUN_0092c400(FUN_009b4d90* apData);
};
struct VirtObj
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
};
struct Host
{
    void FUN_00913a20(int);
    void FUN_00913fb0(VirtObj*);
};
struct FUN_009145c0
{
    float __thiscall GetControllerPhase();
};
void _Deallocate(void*);
struct S9145e0
{
    void FUN_00914610();
    void* FUN_009145e0(unsigned int);
};
void __cdecl _Deallocate(void*);
struct Unk147
{
    void FUN_00914ae0();
    void* FUN_00914ab0(unsigned int);
};
struct GO
{
    int x;
    ~GO();
};
extern int _data_011c16bc;
struct FUN_00914ae0
{
    int _00;
    int _04;
    GO _08;
    GO _0c;
    ~FUN_00914ae0();
};
struct Proxy00917770
{
    void FUN_00917770(Actor* apActor);
    void FUN_0091d3c0(Actor* a, float b, bool c);
};
struct Thunk0091f100
{
    void FUN_0091f100(class Actor* apActor);
};
struct MiddleHighProcessStandIn
{
    char _pad[0x12C];
    void* m_pActorNode;
    void* FUN_00922b20(void* apBiped);
};
struct FUN_00922b60
{
    void SetFlag(bool abFlag);
};
struct FUN_00495480_shell
{
    void FUN_00495480(float);
};
struct Host00929570
{
    char _pad[0x1C4];
    FUN_00495480_shell* seqs[8];
    void FUN_00929570(int aeDirection, FUN_00495480_shell* apSeq);
};
struct ActorPackage_GetTarget_Helper : ActorPackageContext
{
    TESObjectREFR* GetTarget();
    TESObjectREFR* GetTargetFromOffset();
};
TESObjectREFR* ActorPackage_GetTarget_Helper::GetTarget()
{
    return pTarget;
}
struct FakeProcess
{
    char _pad[0x1DC];
    void* _arr[15];
    int _a218;
    int _a21C;
    void SetLimbNode(int aeLimb, void* apNode);
};
struct LipSyncAnimation
{
    ~LipSyncAnimation();
};
struct MidHighStub
{
    void SetLipsynchAnim(LipSyncAnimation*);
};
struct Calendar
{
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p40();
    virtual void p41();
    virtual void p42();
    virtual void p43();
    virtual void p44();
    virtual void p45();
    virtual void p46();
    virtual void p47();
    virtual void p48();
    virtual void p49();
    virtual void p50();
    virtual void p51();
    virtual void p52();
    virtual void p53();
    virtual void p54();
    virtual void p55();
    virtual void p56();
    virtual void p57();
    virtual void p58();
    virtual void p59();
    virtual void p60();
    virtual void p61();
    virtual void p62();
    virtual void p63();
    virtual void p64();
    virtual void p65();
    virtual void p66();
    virtual void p67();
    virtual void p68();
    virtual void p69();
    virtual void p70();
    virtual void p71();
    virtual void p72();
    virtual void p73();
    virtual void p74();
    virtual void p75();
    virtual void p76();
    virtual void p77();
    virtual void p78();
    virtual bool V4F(Actor* actor, int a, float f, int b);
    unsigned int GetDaysPassed();
};
struct FUN_009f4640_holder
{
    int GetFlagsMappedValue();
};
extern int* DAT_011a3ff0[];
struct FUN_008e7c00_shell
{
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void RunFourthVirtual();
    virtual void InvokeFifthVirtualFunction();
    virtual void q5();
    virtual void RunSeventhVirtualOperation();
    virtual void q7();
    virtual void q8();
    virtual void q9();
    virtual void q10();
    virtual void q11();
    virtual void q12();
    virtual void q13();
    virtual void q14();
    virtual void q15();
    virtual void q16();
    virtual void q17();
    virtual void q18();
    virtual void q19();
    virtual void q20();
    virtual void q21();
    virtual void q22();
    virtual void q23();
    virtual void q24();
    virtual void q25();
    virtual void q26();
    virtual void q27();
    virtual void q28();
    virtual void q29();
    virtual void q30();
    virtual void q31();
    virtual void q32();
    virtual void q33();
    virtual void q34();
    virtual void q35();
    virtual void q36();
    virtual void q37();
    virtual void q38();
    virtual void q39();
    virtual void q40();
    virtual void q41();
    virtual void q42();
    virtual void q43();
    virtual void q44();
    virtual void q45();
    virtual void q46();
    virtual void q47();
    virtual void q48();
    virtual void q49();
    virtual void q50();
    virtual void q51();
    virtual void q52();
    virtual void q53();
    virtual void q54();
    virtual void q55();
    virtual void q56();
    virtual void q57();
    virtual void q58();
    virtual void q59();
    virtual void q60();
    virtual void q61();
    virtual void q62();
    virtual void q63();
    virtual void q64();
    virtual void q65();
    virtual void q66();
    virtual void q67();
    virtual void q68();
    virtual void q69();
    virtual void q70();
    virtual void q71();
    virtual void q72();
    virtual void q73();
    virtual void q74();
    virtual void q75();
    virtual void q76();
    virtual void q77();
    virtual void q78();
    virtual void q79();
    virtual void q80();
    virtual void q81();
    virtual void q82();
    virtual void q83();
    virtual void q84();
    virtual void q85();
    virtual void q86();
    virtual void q87();
    virtual void q88();
    virtual void q89();
    virtual void q90();
    virtual void q91();
    virtual void q92();
    virtual void q93();
    virtual void q94();
    virtual void q95();
    virtual void q96();
    virtual void q97();
    virtual void q98();
    virtual void q99();
    virtual void q100();
    virtual void q101();
    virtual void q102();
    virtual void q103();
    virtual void q104();
    virtual void q105();
    virtual void q106();
    virtual void q107();
    virtual void q108();
    virtual void q109();
    virtual void q110();
    virtual void q111();
    virtual void q112();
    virtual void q113();
    virtual void q114();
    virtual void q115();
    virtual void q116();
    virtual void q117();
    virtual void q118();
    virtual void q119();
    virtual void q120();
    virtual void q121();
    virtual void q122();
    virtual void q123();
    virtual void q124();
    virtual void q125();
    virtual void q126();
    virtual void q127();
    virtual void q128();
    virtual void q129();
    virtual void q130();
    virtual void q131();
    virtual void q132();
    virtual void q133();
    virtual void q134();
    virtual void q135();
    virtual void q136();
    virtual void q137();
    virtual void q138();
    virtual void q139();
    virtual void q140();
    virtual void q141();
    virtual void q142();
    virtual void q143();
    virtual void q144();
    virtual void q145();
    virtual void q146();
    virtual void q147();
    virtual void q148();
    virtual void q149();
    virtual void q150();
    virtual void q151();
    virtual void q152();
    virtual void q153();
    virtual void q154();
    virtual void q155();
    virtual void q156();
    virtual FUN_009f4640_holder* V9D();
    virtual void V9E();
    virtual Calendar* V9F();
    virtual int VA0();
    bool IsFlag40Set();
};
struct FUN_00929820_shell : FUN_008e7c00_shell
{
    bool FUN_00929820(Actor* actor);
};
struct TESObjectWEAP
{
    int GetWeaponType();
};
struct Crime
{
    TESObjectREFR* GetTarget();
};
struct FUN_0091e780_s
{
    void UpdateWeaponTypeFlags();
};
// FUN_009139b0 : clears a 0x14-byte state block, resets a sub-object and returns this.
struct Member14_b5364
{
    void FUN_00528cb0(int a1);
};
struct FUN_009139b0_cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned char m_0c;
    unsigned char m_0d;
    unsigned char m_0e;
    unsigned char m_0f;
    unsigned char m_10;
    unsigned char m_11;
    unsigned short m_12;
    Member14_b5364 m_14;
    FUN_009139b0_cls* FUN_009139b0();
};
struct FUN_00867510
{
    FUN_00867510();
    int n_00;
    int n_04;
    int n_08;
    int n_0c;
    int n_10;
    int n_14;
    int n_18;
    int n_1c;
    int n_20;
    int n_24;
    int n_28;
    int n_2c;
    int n_30;
    int n_34;
    int n_38;
    int n_3c;
    int n_40;
    int n_44;
};
struct FUN_0096a2d0
{
    FUN_0096a2d0();
    ~FUN_0096a2d0();
    int m_00;
    int m_04;
};
struct FUN_008c5e20
{
    FUN_008c5e20();
    ~FUN_008c5e20();
    void FUN_008c5ef0();
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};
struct FUN_006815c0
{
    FUN_006815c0();
    int f_00;
    int f_04;
    int f_08;
    int f_0c;
    int f_10;
    unsigned char f_14;
    unsigned char f_15;
    unsigned char f_16;
    unsigned char f_17;
    int f_18;
    int f_1c;
};
struct FUN_00528cb0
{
    FUN_00528cb0(int);
    ~FUN_00528cb0();
    void FUN_006f74f0(int);
    void FUN_0092c8b0(int);
    int m_00;
};
struct FUN_00633c90
{
    FUN_00633c90(int);
    ~FUN_00633c90();
    void FUN_0066b0d0(int);
    int f_00;
    int f_04;
    int f_08;
    int f_0c;
};
struct FUN_00509890
{
    FUN_00509890(int);
    void FUN_00c54550(float);
    void FUN_00568ab0(int);
    void FUN_0098ddd0(void*);
    int f_00;
    int f_04;
    int f_08;
    int f_0c;
    int f_10;
    int f_14;
    int f_18;
    int f_1c;
    unsigned char f_20;
    unsigned char f_21;
    unsigned char f_22;
    unsigned char f_23;
    int f_24;
    float f_28;
    float f_2c;
    int f_30;
    unsigned char f_34;
    unsigned char f_35;
    unsigned char f_36;
    unsigned char f_37;
    unsigned char f_38;
    unsigned char f_39;
    unsigned char f_3a;
    unsigned char f_3b;
    int f_3c;
    unsigned char f_40;
    unsigned char f_41;
    unsigned char f_42;
    unsigned char f_43;
    unsigned char f_44;
    unsigned char f_45;
    unsigned char f_46;
    unsigned char f_47;
    int f_48;
    int f_4c;
    float f_50;
    unsigned char f_54;
    unsigned char f_55;
    unsigned char f_56;
    unsigned char f_57;
    int f_58;
    int f_5c;
    int f_60;
    int f_64;
};
struct FUN_0092c950
{
    virtual void v00();
    FUN_0092c950();
    ~FUN_0092c950();
    int b_04;
    int b_08;
    int b_0c;
    int b_10;
    int b_14;
    int b_18;
    int b_1c;
    int b_20;
    int b_24;
    int b_28;
    FUN_00867510* p_2c;
    int b_30;
    int b_34;
    int b_38;
    int b_3c;
    int b_40;
    int b_44;
    int b_48;
    int b_4c;
    int b_50;
    int b_54;
    int m_58;
    int b_5c;
    int b_60;
    int b_64;
    int b_68;
    int b_6c;
    int b_70;
    int b_74;
    int b_78;
    int b_7c;
    int b_80;
    int b_84;
    int b_88;
    int b_8c;
    int b_90;
    int b_94;
    int b_98;
    int b_9c;
    int b_a0;
    float f_a4;
    int b_a8;
    int b_ac;
    int b_b0;
    int b_b4;
    int b_b8;
    int b_bc;
    int b_c0;
    int b_c4;
};
extern char DAT_011f426c;
extern float DAT_01012054;
void* __cdecl memset(void*, int, unsigned int);
struct FUN_00913fe0 : FUN_0092c950
{
    void FUN_008d8140(int);
    void FUN_008d8180(int);
    void FUN_0061cc40(int);
    FUN_00913fe0();
    FUN_0096a2d0 m_c8;
    FUN_0096a2d0 m_d0;
    float m_d8;
    float m_dc;
    unsigned char m_e0;
    unsigned char m_e1;
    unsigned char m_e2;
    unsigned char m_e3;
    FUN_008c5e20 m_e4;
    FUN_006815c0 m_fc;
    FUN_00528cb0 m_11c;
    FUN_00528cb0 m_120;
    unsigned char m_124;
    unsigned char m_125;
    unsigned char m_126;
    unsigned char m_127;
    unsigned char m_128;
    unsigned char m_129;
    unsigned char m_12a;
    unsigned char m_12b;
    int m_12c;
    int m_130;
    unsigned char m_134;
    unsigned char m_135;
    unsigned char m_136;
    unsigned char m_137;
    FUN_00633c90 m_138;
    FUN_00509890 m_148;
    FUN_0096a2d0 m_1b0;
    FUN_0096a2d0* m_1b8;
    int m_1bc;
    int m_1c0;
    int m_1c4;
    int m_1c8;
    int m_1cc;
    float m_1d0;
    float m_1d4;
    unsigned char m_1d8;
    unsigned char m_1d9;
    unsigned char m_1da;
    unsigned char m_1db;
    int arr_1dc[15];
    int m_218;
    int m_21c;
    FUN_00633c90 m_220;
    int m_230;
    float m_234;
    float m_238;
    float m_23c;
    int m_240;
    int m_244;
    int m_248;
    int m_24c;
    int m_250;
    int m_254;
    int m_258;
};
class TESBoundObject
{
  public:
    virtual void Unused();
};
class TESNPC
{
  public:
    void FUN_006047c0(Actor*, bool, bool, bool, bool);
};
class TESCreature
{
  public:
    void FUN_005f9e00(Actor*, bool, bool, bool);
};
class TESPackage
{
  public:
    int FUN_0041ca90();
    bool FUN_00441b00();
};
struct ProcessUpdate : MiddleHighProcess
{
    void FUN_00915bc0(Actor*, bool, bool);
};
struct FUN_00915d20_shell : public MiddleHighProcess
{
    void FUN_00915d20(unsigned char value);
};
extern "C" Actor* DAT_011dea3c;
struct WeaponEquipmentAccess
{
    unsigned char HasEffect(int operation, int value);
    int FUN_0044ddc0(int value, unsigned char result);
};
struct ActorWeaponAccess
{
    void FUN_00884f80();
};
struct WeaponDrawProcess : MiddleHighProcess
{
    void FUN_00915d60(Actor* actor, bool drawn);
};
struct ActorCalls
{
    int FUN_00931850();
    bool FUN_00437bf0();
    bool FUN_00437bd0();
    bool FUN_005a2030();
    bool FUN_0087f3b0();
    bool FUN_0087f570();
    bool FUN_00493bb0();
    void* FUN_005d43c0();
    float FUN_00572380(NiPoint3*);
    int FUN_008a8230(Actor*);
    void FUN_0093a690(Actor*);
    int FUN_00953c20();
};
struct PackageCalls
{
    int FUN_0041ca90();
    bool FUN_00678610();
    bool HasFlag400000();
    unsigned int FUN_00676280(Actor*);
};
struct ControllerCalls
{
    bool FUN_0097fa10();
};
struct GlobalCallContext
{
    bool FUN_008d0300(Actor*, Actor*);
};
struct TimingSettings
{
    int* FUN_0043d4d0();
};
struct ProcessToken
{
    void* FUN_0041cb10();
};
extern GlobalCallContext* DAT_011f1958;
extern TimingSettings DAT_011ccffc;
extern Actor* DAT_011dea3c;
extern float DAT_01012054;
extern double DAT_01012070;
extern float DAT_0101786c;
typedef bool(__thiscall* PackageFilter)(TESPackage*, Actor*, Actor*, int, float, int);
typedef ControllerCalls*(__thiscall* ControllerForTarget)(Actor*, Actor*);
typedef void(__thiscall* ImmediateAction)(Actor*, Actor*, int, int, int, int, int, float, float);
typedef void(__thiscall* ProcessAction)(Actor*, Actor*, int, bool, bool, bool, int, bool, int);
struct FUN_00916880_shell : MiddleHighProcess
{
    void FUN_0090dc10(Actor*, Actor*, bool, bool, int, bool, bool, bool, bool, bool, int, int, int);
    bool TryStartCombatAction(Actor*, Actor*, bool, bool, int, bool, bool, bool, bool, bool, bool, bool, int);
};
extern float DAT_01012054;
class FUN_009180b0_cls
{
  public:
    unsigned char FUN_008b3690(NiPoint3* pos, unsigned int a4, unsigned int a5, float fTime, unsigned int a7);
    unsigned char FUN_009180b0(Actor* self, NiPoint3 a1, unsigned int a4, unsigned int a5);
};
struct PackageForTarget
{
    int FUN_00671d10();
    int FUN_0041ca90();
};
struct TargetData
{
    TESObjectREFR* FUN_0041c8d0();
};
struct TargetReference : TESObjectREFR
{
    bool FUN_00576d30();
    bool FUN_00440d80();
    TargetData* FUN_005d43c0();
    void FUN_00564db0(bool);
};
struct TargetProcess : MiddleHighProcess
{
    virtual void unkSlot493();
    virtual void unkSlot494();
    virtual void unkSlot495();
    virtual void unkSlot496();
    virtual void unkSlot497();
    virtual void unkSlot498();
    virtual void unkSlot499();
    virtual void unkSlot500();
    virtual void unkSlot501();
    virtual void unkSlot502();
    virtual void unkSlot503();
    virtual void unkSlot504();
    virtual void unkSlot505();
    virtual void unkSlot506();
    virtual void unkSlot507();
    virtual void unkSlot508();
    virtual void unkSlot509();
    virtual void unkSlot510();
    virtual void unkSlot511();
    virtual void unkSlot512();
    virtual void unkSlot513();
    virtual void unkSlot514();
    virtual void unkSlot515();
    virtual TESObjectREFR* ResolveTarget(Actor*, TESPackage*);
    bool FUN_0091aca0(Actor* actor);
};
struct InventoryItemLookup
{
    void** FUN_006815c0();
};
struct InventoryLookup
{
    InventoryItemLookup* FUN_00559450();
    void* FUN_0044ddc0(void* item, bool enabled);
};
struct ActorInventoryAccess
{
    InventoryLookup* FUN_00891d30();
    void FUN_008c1de0(void* item);
};
struct FUN_0091d790_shell : MiddleHighProcess
{
    bool FUN_0091d790(ActorInventoryAccess* actor);
};
// StopActorMoving  (image 0x0091efc0, 27 bytes)
//
// The image's call target 0x008b3ab0 is Actor::StopMoving(); it is reached as
// a this-call on the argument, so the argument is an actor pointer and the
// member never touches its own `this`.
//
//   0091efc0  push ebp
//   0091efc1  mov  ebp, esp
//   0091efc3  push ecx                 ; /Od homing slot for `this`
//   0091efc4  mov  dword ptr [ebp-4], ecx
//   0091efc7  cmp  dword ptr [ebp+8], 0
//   0091efcb  je   0x0091efd5
//   0091efcd  mov  ecx, dword ptr [ebp+8]
//   0091efd0  call 0x008b3ab0           ; actor->StopMoving()
//   0091efd5  mov  esp, ebp
//   0091efd7  pop  ebp
//   0091efd8  ret  4
// Stand-in for the actor the argument points at.
struct Actor0091efc0
{
    void StopMoving();
};
// Stand-in for the class that owns StopActorMoving.
struct FUN_0091efc0_owner
{
    void StopActorMoving(Actor0091efc0* apActor);
};
class B91FD90Package;
class B91FD90Actor
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11C();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12C();
    virtual void vfn130();
    virtual void vfn134();
    virtual void vfn138();
    virtual void vfn13C();
    virtual void vfn140();
    virtual void vfn144();
    virtual void vfn148();
    virtual void vfn14C();
    virtual void vfn150();
    virtual void vfn154();
    virtual void vfn158();
    virtual void vfn15C();
    virtual void vfn160();
    virtual void vfn164();
    virtual void vfn168();
    virtual void vfn16C();
    virtual void vfn170();
    virtual void vfn174();
    virtual void vfn178();
    virtual void vfn17C();
    virtual void vfn180();
    virtual void vfn184();
    virtual void vfn188();
    virtual void vfn18C();
    virtual void vfn190();
    virtual void vfn194();
    virtual void vfn198();
    virtual void vfn19C();
    virtual void vfn1A0();
    virtual void vfn1A4();
    virtual void vfn1A8();
    virtual void vfn1AC();
    virtual void vfn1B0();
    virtual void vfn1B4();
    virtual void vfn1B8();
    virtual void vfn1BC();
    virtual void vfn1C0();
    virtual void vfn1C4();
    virtual void vfn1C8();
    virtual void vfn1CC();
    virtual void vfn1D0();
    virtual void vfn1D4();
    virtual void vfn1D8();
    virtual void vfn1DC();
    virtual void vfn1E0();
    virtual void vfn1E4();
    virtual void vfn1E8();
    virtual void vfn1EC();
    virtual void vfn1F0();
    virtual void vfn1F4();
    virtual void vfn1F8();
    virtual void vfn1FC();
    virtual void vfn200();
    virtual void vfn204();
    virtual void vfn208();
    virtual void vfn20C();
    virtual void vfn210();
    virtual void vfn214();
    virtual void vfn218();
    virtual void vfn21C();
    virtual void vfn220();
    virtual void vfn224();
    virtual void vfn228();
    virtual void vfn22C();
    virtual void vfn230();
    virtual void vfn234();
    virtual void vfn238();
    virtual void vfn23C();
    virtual void vfn240();
    virtual void vfn244();
    virtual void vfn248();
    virtual void vfn24C();
    virtual void vfn250();
    virtual void vfn254();
    virtual void vfn258();
    virtual void vfn25C();
    virtual void vfn260();
    virtual void vfn264();
    virtual void vfn268();
    virtual void vfn26C();
    virtual void vfn270();
    virtual void vfn274();
    virtual void vfn278();
    virtual void vfn27C();
    virtual void vfn280();
    virtual void vfn284();
    virtual void ResetCombat();

    void* GetProcessTarget();
};
class B91FD90Package
{
  public:
    B91FD90Actor* FUN_008d80e0();
    B91FD90Actor* FUN_009ee040();
    void FUN_009ee0a0(int iState);

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
    float m_fTimer;
};
class B91FD90TimeGlobal
{
  public:
    float GetMovementDelta();
};
extern const double gModifierZero;
extern B91FD90TimeGlobal g_kB91FD90Time;
class B91FD90Owner
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void MarkDone(bool bPickResultFound);
    virtual bool IsReady();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12C();
    virtual void vfn130();
    virtual void vfn134();
    virtual void vfn138();
    virtual void vfn13C();
    virtual void vfn140();
    virtual void vfn144();
    virtual void vfn148();
    virtual void vfn14C();
    virtual void vfn150();
    virtual void vfn154();
    virtual void vfn158();
    virtual void vfn15C();
    virtual void vfn160();
    virtual void vfn164();
    virtual void vfn168();
    virtual void vfn16C();
    virtual void vfn170();
    virtual void vfn174();
    virtual void vfn178();
    virtual void vfn17C();
    virtual void vfn180();
    virtual void vfn184();
    virtual void vfn188();
    virtual void vfn18C();
    virtual void vfn190();
    virtual void vfn194();
    virtual void vfn198();
    virtual void vfn19C();
    virtual void vfn1A0();
    virtual void vfn1A4();
    virtual void vfn1A8();
    virtual void vfn1AC();
    virtual void vfn1B0();
    virtual void vfn1B4();
    virtual void vfn1B8();
    virtual void vfn1BC();
    virtual void vfn1C0();
    virtual void vfn1C4();
    virtual void vfn1C8();
    virtual void vfn1CC();
    virtual void vfn1D0();
    virtual void vfn1D4();
    virtual void vfn1D8();
    virtual void vfn1DC();
    virtual void vfn1E0();
    virtual void vfn1E4();
    virtual void vfn1E8();
    virtual void vfn1EC();
    virtual void vfn1F0();
    virtual void vfn1F4();
    virtual void vfn1F8();
    virtual void vfn1FC();
    virtual void vfn200();
    virtual void vfn204();
    virtual void vfn208();
    virtual void vfn20C();
    virtual void vfn210();
    virtual void vfn214();
    virtual void vfn218();
    virtual void vfn21C();
    virtual void vfn220();
    virtual void vfn224();
    virtual void vfn228();
    virtual void vfn22C();
    virtual void vfn230();
    virtual void vfn234();
    virtual void vfn238();
    virtual void vfn23C();
    virtual void vfn240();
    virtual void vfn244();
    virtual void vfn248();
    virtual void vfn24C();
    virtual void vfn250();
    virtual void vfn254();
    virtual void vfn258();
    virtual void vfn25C();
    virtual void vfn260();
    virtual void vfn264();
    virtual void vfn268();
    virtual void vfn26C();
    virtual void vfn270();
    virtual void vfn274();
    virtual void vfn278();
    virtual B91FD90Package* GetAssignedPackage();

    void FUN_0091fd90(B91FD90Actor* pkActor);
};
struct SSLookData
{
    void FUN_00629670(unsigned int flags, bool set);
};
struct SSHighData
{
    int unk000;
};
struct SSTaskQueue
{
    static SSTaskQueue* GetSingleton();
    void SendEvent(NiAVObject* node, bool a, bool b, bool c);
};
struct SSFurnRef
{
    void FUN_00568020(unsigned char idx, bool b);
};
struct SSMarker
{
    unsigned int FUN_005094b0();
};
struct SSActor
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V0A();
    virtual void V0B();
    virtual void V0C();
    virtual void V0D();
    virtual void V0E();
    virtual void V0F();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V1A();
    virtual void V1B();
    virtual void V1C();
    virtual void V1D();
    virtual void V1E();
    virtual void V1F();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V2A();
    virtual void V2B();
    virtual void V2C();
    virtual void V2D();
    virtual void V2E();
    virtual void V2F();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V3A();
    virtual void V3B();
    virtual void V3C();
    virtual void V3D();
    virtual void V3E();
    virtual void V3F();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual void V48();
    virtual void V49();
    virtual void V4A();
    virtual void V4B();
    virtual void V4C();
    virtual void V4D();
    virtual void V4E();
    virtual void V4F();
    virtual void V50();
    virtual void V51();
    virtual void V52();
    virtual void V53();
    virtual void V54();
    virtual void V55();
    virtual void V56();
    virtual void V57();
    virtual void V58();
    virtual void V59();
    virtual void V5A();
    virtual void V5B();
    virtual void V5C();
    virtual void V5D();
    virtual void V5E();
    virtual void V5F();
    virtual void V60();
    virtual void V61();
    virtual void V62();
    virtual void V63();
    virtual void V64();
    virtual void V65();
    virtual void V66();
    virtual void V67();
    virtual void V68();
    virtual void V69();
    virtual void V6A();
    virtual void V6B();
    virtual void V6C();
    virtual void V6D();
    virtual void V6E();
    virtual void V6F();
    virtual void V70();
    virtual void V71();
    virtual void V72();
    virtual void V73();
    virtual NiAVObject* GetNiNode();
    virtual void V75();
    virtual void V76();
    virtual void V77();
    virtual void V78();
    virtual void V79();
    virtual void V7A();
    virtual void V7B();
    virtual void V7C();
    virtual void V7D();
    virtual void V7E();
    virtual void V7F();
    virtual void V80();
    virtual void V81();
    virtual void V82();
    virtual void V83();
    virtual void V84();
    virtual void V85();
    virtual void V86();
    virtual void V87();
    virtual void V88();
    virtual void V89();
    virtual void V8A();
    virtual void V8B();
    virtual void V8C();
    virtual void V8D();
    virtual void V8E();
    virtual void V8F();
    virtual void V90();
    virtual void V91();
    virtual void V92();
    virtual void V93();
    virtual void V94();
    virtual void V95();
    virtual void V96();
    virtual void V97();
    virtual void V98();
    virtual void V99();
    virtual void V9A();
    virtual void V9B();
    virtual void V9C();
    virtual void V9D();
    virtual void V9E();
    virtual void V9F();
    virtual void VA0();
    virtual void VA1();
    virtual void VA2();
    virtual void VA3();
    virtual void VA4();
    virtual void VA5();
    virtual void VA6();
    virtual void VA7();
    virtual void VA8();
    virtual void VA9();
    virtual void VAA();
    virtual void VAB();
    virtual void VAC();
    virtual void VAD();
    virtual void VAE();
    virtual void VAF();
    virtual void VB0();
    virtual void VB1();
    virtual void VB2();
    virtual void VB3();
    virtual void VB4();
    virtual void VB5();
    virtual void VB6();
    virtual void VB7();
    virtual void SetLookingTarget(float);
    float GetLooking() const;
    void ClampLookAngle(float);
    char* FUN_009306d0();
    void FUN_00931fb0(bool);
    void SetCurrentSitSleepState(int state);
};
bool FUN_008c7aa0();
void FUN_00c69fc0(NiAVObject* node, bool a, bool b, bool c);
extern SSActor* g_thePlayer;
struct SSProcess : public MiddleHighProcess
{
    void UpdateSitSleepState(SSActor* actor, int state, TESObjectREFR* furniture, unsigned char index);
};
struct FUN_00921250_Item;
struct FUN_00921250_Node;
struct FUN_00921250_Mgr
{
    bool FUN_004eaf60();
    void FUN_005c4210(int);
    FUN_00921250_Item* FUN_00950a60(int);
};
struct FUN_00921250_Svc
{
    FUN_00921250_Node* FUN_00600950(void* a, int b);
};
struct FUN_00921250_Node
{
    int GetFlagsMasked();
};
struct FUN_00921250_Item
{
    void FUN_00498030(void* a, void* b, int c);
};
extern FUN_00921250_Mgr* g_pMgr;
extern FUN_00921250_Svc* g_pSvc;
class FUN_00921250_cls
{
  public:
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
    virtual void v064();
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
    virtual void v209();
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
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void vCall(void* a, int b, int c, unsigned char d);
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
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int m_f140;
    unsigned char m_f144;

    bool ProcessNode(void* arg);
};
struct BipedAnimStandIn
{
    void FUN_0088d640();
};
struct FUN_00922ad0_owner
{
    void FUN_00922ad0(BipedAnimStandIn* apBiped);
};
struct FUN_00922b40_cls
{
    int unk00[118];
    unsigned short unk01;
    unsigned char m_bFlag;
    unsigned char FUN_00922b40();
};
struct CvPoint3
{
    float x;
    float y;
    float z;
};
struct CvPosSource
{
    CvPoint3* GetPosA();
    CvPoint3* GetPosB();
};
struct CvInfo
{
    CvPoint3* GetPosA();
    CvPoint3* GetPosB();
};
struct CvList;
struct CvItem
{
    float Evaluate(CvPoint3 pos, CvList* other);
    CvInfo* GetInfo();
};
struct CvList
{
    CvItem* GetFirst(int* iter);
    CvItem* GetNext(int* iter);
};
struct CvScopeList
{
    CvList* GetList();
};
struct CvMgr
{
    CvItem* GetItem();
    float EvaluatePlayer(CvPoint3 pos, int* count, float* outA, float* outB, CvList* other);
};
struct CvState
{
    bool IsActive();
};
struct CvScope
{
    CvScope(int a);
    ~CvScope();
    int unk00;
};
struct CvTimer
{
    float GetTime();
};
struct CvActor
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
    virtual void v064();
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
    virtual CvPoint3 GetFootPos();
    virtual CvPoint3 GetHeadPos();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual CvPoint3* GetPos();
    CvScopeList* GetHolder();
    int GetId();
    void Notify(int id);
    CvState* GetState();
    void* Prepare(int a);
};
extern CvActor* g_cvPlayer;
extern CvTimer g_cvTimer;
CvMgr* __cdecl CvGetMgr(int a);
float __cdecl CvMax(float a, float b);
extern const double dbl_01012060;
extern const double dbl_01012070;
extern const double dbl_01011590;
extern const double dbl_01017a40;
extern const float flt_01016410;
extern const double dbl_01031148;
extern const double dbl_01021928;
struct CvOwner
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
    virtual void v064();
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
    virtual void v209();
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
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual float GetValue();
    virtual void SetValue(float v);
    virtual void v325();
    virtual void v326();
    virtual void v327();
    virtual void v328();
    virtual void v329();
    virtual void v330();
    virtual void v331();
    virtual void v332();
    virtual void v333();
    virtual void v334();
    virtual void v335();
    virtual void v336();
    virtual void v337();
    virtual void v338();
    virtual void v339();
    virtual void v340();
    virtual void v341();
    virtual void v342();
    virtual void v343();
    virtual void v344();
    virtual void v345();
    virtual void v346();
    virtual void v347();
    virtual void v348();
    virtual void v349();
    virtual void v350();
    virtual void v351();
    virtual void v352();
    virtual void v353();
    virtual void v354();
    virtual void v355();
    virtual void v356();
    virtual void v357();
    virtual void v358();
    virtual void v359();
    virtual void v360();
    virtual void v361();
    virtual void v362();
    virtual void v363();
    virtual void v364();
    virtual void v365();
    virtual void v366();
    virtual void v367();
    virtual void v368();
    virtual void v369();
    virtual void v370();
    virtual void v371();
    virtual void v372();
    virtual void v373();
    virtual void v374();
    virtual void v375();
    virtual void v376();
    virtual void v377();
    virtual void v378();
    virtual void v379();
    virtual void v380();
    virtual void v381();
    virtual void v382();
    virtual void v383();
    virtual void v384();
    virtual void v385();
    virtual void v386();
    virtual void v387();
    virtual void v388();
    virtual void v389();
    virtual void v390();
    virtual void v391();
    virtual void v392();
    virtual void v393();
    virtual void v394();
    virtual void v395();
    virtual void v396();
    virtual void v397();
    virtual void v398();
    virtual void v399();
    virtual void v400();
    virtual void v401();
    virtual void v402();
    virtual void v403();
    virtual void v404();
    virtual void v405();
    virtual void v406();
    virtual void v407();
    virtual void v408();
    virtual void v409();
    virtual void v410();
    virtual void v411();
    virtual void v412();
    virtual void v413();
    virtual void v414();
    virtual void v415();
    virtual void v416();
    virtual void v417();
    virtual void v418();
    virtual void v419();
    virtual void v420();
    virtual void v421();
    virtual void v422();
    virtual void v423();
    virtual void v424();
    virtual void v425();
    virtual void v426();
    virtual void v427();
    virtual void v428();
    virtual void v429();
    virtual void v430();
    virtual void v431();
    virtual void v432();
    virtual void v433();
    virtual void v434();
    virtual void v435();
    virtual void v436();
    virtual void v437();
    virtual void v438();
    virtual void v439();
    virtual void v440();
    virtual void v441();
    virtual void v442();
    virtual void v443();
    virtual void v444();
    virtual void v445();
    virtual void v446();
    virtual void v447();
    virtual void v448();
    virtual void v449();
    virtual void v450();
    virtual void v451();
    virtual void v452();
    virtual void v453();
    virtual void v454();
    virtual void v455();
    virtual void v456();
    virtual void v457();
    virtual void v458();
    virtual void v459();
    virtual void v460();
    virtual void v461();
    virtual void SetLevel(float v);
    char unk004[0x21c];
    CvScopeList m220;
    void UpdateLevel(CvActor* target, bool useTarget);
};
struct AcquireObject
{
    void* FUN_007b3fa0(unsigned int);
};
struct AcquireList
{
    bool FUN_008256d0();
    AcquireObject** FUN_006815c0();
    void FUN_00905330(AcquireObject**);
};
struct RefListClear
{
    void FUN_00470470();
};
struct ResetActor : Actor
{
    void FUN_008b3d30();
    void FUN_005ce9d0(int);
};
struct ResetProcess : MiddleHighProcess
{
    void FUN_00914b40();
    void SetFlag40(int);
    void ResetForActor(ResetActor* actor);
};
struct LstItem;
struct ListA
{
    int a0;
    int a4;
    int a8;
    int aC;
    bool Has();
    LstItem** Ref();
    void Pop();
    void Push(LstItem**);
};
struct ListB
{
    int b0;
    int b4;
    int b8;
    LstItem** Ref();
    void Pop();
    void Clear();
};
struct Dat011c
{
    float* Get();
};
struct Mgr
{
    void Run(unsigned int id, NiPoint3* pos, float f, NiPoint3* p2, float g, void* cb, Actor* a);
};
extern Mgr* DAT_011c3f2c;
extern Dat011c DAT_011cdebc;
void FUN_0090e660();
struct Sched
{
    int Kind();
    int GetA();
    int GetB();
    int GetC();
    bool Chk();
};
struct RefX
{
    Sched* F672dd0();
    Sched* F55b980();
    bool F6728a0(Actor*, float*);
};
struct ActX
{
    int F569b80();
    unsigned int F8d6f30();
};
struct FUN_00923e40_cls
{
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
    ListA listA;
    ListB listB;
    int f88;
    int f8c;
    int RunScheduledAction(Actor* actor, RefX* ref, bool flag);
};
struct RecordVector
{
    float x, y, z;
    void FUN_006815c0();
};
struct RecordData
{
    void FUN_00812b00(RecordVector*);
    void FUN_0066ca00(RecordVector*);
};
struct RecordValue
{
    unsigned int FUN_00ca9600();
};
struct RecordFlags
{
    unsigned int FUN_00621270(int mask);
};
struct SaveBuffer
{
    void FUN_008579b0(const void* data, unsigned int count);
    unsigned char FUN_008df040();
};
extern SaveBuffer* DAT_011de45c;
struct SaveGameRecordWriter
{
    void SaveActorRecord(void* actor);
};
typedef RecordData*(__thiscall* GetRecordFunction)(SaveGameRecordWriter*);
typedef bool(__thiscall* GetStateFunction)(void*, int);
typedef bool(__thiscall* GetSwitchFunction)(void*);
struct FUN_00914ab0
{
    ~FUN_00914ab0();
};
struct LoadFlags
{
    int flags;
    bool FUN_004280f0(unsigned);
};
struct LoadBuffer
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Actor* GetActor();
    LoadFlags FUN_0042ce30();
    bool FUN_00562d00();
};
struct PackageLoad
{
    void FUN_008c6c80(LoadBuffer*);
};
struct AnimationLoad
{
    void FUN_0049bb70(LoadBuffer*);
};
void __cdecl FUN_00806ba0(LoadBuffer*, BSSimpleList<ActiveEffect*>*);
struct FUN_009280f0_Class : MiddleHighProcess
{
    void FUN_0092eb00(LoadBuffer*);
    void FUN_009280f0(LoadBuffer*);
};
struct SaveVector
{
    float x, y, z;
    SaveVector();
};
struct SaveFlags
{
    unsigned int data;
    int FUN_00621270(int);
};
int __fastcall FUN_00ca9600(char*);
struct ControllerState
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
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
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    SaveFlags flags;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    struct Block4f0
    {
        float x, y, z, w;
    } block4f0;
    struct Block500
    {
        float x, y, z, w;
    } block500;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    void FUN_00812b00(SaveVector*);
    void FUN_0066ca00(SaveVector*);
};
struct SaveActor
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
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual void Slot75();
    virtual void Slot76();
    virtual void Slot77();
    virtual void Slot78();
    virtual void Slot79();
    virtual void Slot80();
    virtual void Slot81();
    virtual void Slot82();
    virtual void Slot83();
    virtual void Slot84();
    virtual void Slot85();
    virtual void Slot86();
    virtual void Slot87();
    virtual void Slot88();
    virtual void Slot89();
    virtual void Slot90();
    virtual void Slot91();
    virtual void Slot92();
    virtual void Slot93();
    virtual void Slot94();
    virtual void Slot95();
    virtual void Slot96();
    virtual void Slot97();
    virtual void Slot98();
    virtual void Slot99();
    virtual void Slot100();
    virtual void Slot101();
    virtual void Slot102();
    virtual void Slot103();
    virtual void Slot104();
    virtual void Slot105();
    virtual void Slot106();
    virtual void Slot107();
    virtual void Slot108();
    virtual void Slot109();
    virtual void Slot110();
    virtual void Slot111();
    virtual void Slot112();
    virtual void Slot113();
    virtual void Slot114();
    virtual void Slot115();
    virtual void Slot116();
    virtual void Slot117();
    virtual void Slot118();
    virtual void Slot119();
    virtual void Slot120();
    virtual void Slot121();
    virtual void Slot122();
    virtual void Slot123();
    virtual void Slot124();
    virtual void Slot125();
    virtual void Slot126();
    virtual void Slot127();
    virtual void Slot128();
    virtual void Slot129();
    virtual void Slot130();
    virtual void Slot131();
    virtual void Slot132();
    virtual void Slot133();
    virtual void Slot134();
    virtual void Slot135();
    virtual void Slot136();
    virtual void Slot137();
    virtual void Slot138();
    virtual bool SkipSave(int);
};
struct ControllerSaveBuffer
{
    virtual void Slot0();
    virtual void Slot1();
    virtual SaveActor* GetActor();
    void FUN_00865e50(void*, unsigned int, int);
};
struct SaveProcess
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
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual void Slot75();
    virtual void Slot76();
    virtual void Slot77();
    virtual void Slot78();
    virtual void Slot79();
    virtual void Slot80();
    virtual void Slot81();
    virtual void Slot82();
    virtual void Slot83();
    virtual void Slot84();
    virtual void Slot85();
    virtual void Slot86();
    virtual void Slot87();
    virtual void Slot88();
    virtual void Slot89();
    virtual void Slot90();
    virtual void Slot91();
    virtual void Slot92();
    virtual void Slot93();
    virtual void Slot94();
    virtual void Slot95();
    virtual void Slot96();
    virtual void Slot97();
    virtual void Slot98();
    virtual void Slot99();
    virtual void Slot100();
    virtual void Slot101();
    virtual void Slot102();
    virtual void Slot103();
    virtual void Slot104();
    virtual void Slot105();
    virtual void Slot106();
    virtual void Slot107();
    virtual void Slot108();
    virtual void Slot109();
    virtual void Slot110();
    virtual void Slot111();
    virtual void Slot112();
    virtual void Slot113();
    virtual void Slot114();
    virtual void Slot115();
    virtual void Slot116();
    virtual void Slot117();
    virtual void Slot118();
    virtual void Slot119();
    virtual void Slot120();
    virtual void Slot121();
    virtual void Slot122();
    virtual void Slot123();
    virtual void Slot124();
    virtual void Slot125();
    virtual void Slot126();
    virtual void Slot127();
    virtual void Slot128();
    virtual void Slot129();
    virtual void Slot130();
    virtual void Slot131();
    virtual void Slot132();
    virtual void Slot133();
    virtual void Slot134();
    virtual void Slot135();
    virtual void Slot136();
    virtual void Slot137();
    virtual void Slot138();
    virtual void Slot139();
    virtual void Slot140();
    virtual void Slot141();
    virtual void Slot142();
    virtual void Slot143();
    virtual void Slot144();
    virtual void Slot145();
    virtual void Slot146();
    virtual void Slot147();
    virtual void Slot148();
    virtual void Slot149();
    virtual void Slot150();
    virtual void Slot151();
    virtual void Slot152();
    virtual void Slot153();
    virtual void Slot154();
    virtual void Slot155();
    virtual void Slot156();
    virtual void Slot157();
    virtual void Slot158();
    virtual void Slot159();
    virtual void Slot160();
    virtual void Slot161();
    virtual void Slot162();
    virtual ControllerState* GetController();
    void SaveControllerState(ControllerSaveBuffer* buffer);
};
struct S_9292e0_Obj
{
    int FUN_007df1d0();
};
struct S_9292e0_Node
{
    bool FUN_008256d0();
    S_9292e0_Obj** FUN_006815c0();
    S_9292e0_Node* FUN_00726070();
};
int __cdecl FUN_0040df90(int);
int __cdecl FUN_00929390(int a, int b);
struct S_9292e0
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
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    unsigned char dirty;
    int flags;
    int FUN_009292e0(S_9292e0_Node* node, int mask);
};
bool FUN_00929390(unsigned int a, unsigned int b);
struct ArrowListRemoveHelper
{
    void FUN_00905330(ArrowProjectile* const& projectile);
};
struct MiddleHighProcess_00929470 : MiddleHighProcess
{
    void RemoveArrowProjectile(ArrowProjectile* projectile);
};
struct S_0092adb0_Data
{
    bool InitPatrolPackage(Actor* actor, TESPackage* package);
};
struct S_0092adb0_Proc : public MiddleHighProcess
{
    virtual void unk493();
    virtual void unk494();
    virtual void unk495();
    virtual void unk496();
    virtual void unk497();
    virtual void unk498();
    virtual void unk499();
    virtual void unk500();
    virtual void unk501();
    virtual void unk502();
    virtual void unk503();
    virtual void unk504();
    virtual void unk505();
    virtual void unk506();
    virtual void unk507();
    virtual void unk508();
    virtual void unk509();
    virtual void unk510();
    virtual void unk511();
    virtual void unk512();
    virtual void unk513();
    virtual void unk514();
    virtual void unk515();
    virtual void unk516();
    virtual void unk517();
    virtual void unk518();
    virtual void unk519();
    virtual void unk520();
    virtual void unk521();
    virtual void unk522();
    virtual void unk523();
    virtual void unk524();
    virtual void unk525();
    virtual void unk526();
    virtual void unk527();
    virtual void unk528();
    virtual void unk529();
    virtual void unk530();
    virtual void unk531();
    virtual void unk532();
    virtual void unk533();
    virtual void unk534(Actor* actor, S_0092adb0_Data* data);
    bool CheckPackageAndRun(Actor* actor, S_0092adb0_Data* data);
};
struct FUN_0092b460_cls
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
    virtual void v169(FUN_0092b460_cls* a, void* b, int c, int d, int e, int f);
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
    virtual bool v195();
    char pad_04[0x194];
    float m_198;
    void FUN_00912960(FUN_0092b460_cls* a, FUN_0092b460_cls* b);
    void FUN_008b3d30();
    FUN_0092b460_cls* FUN_009f3390();
    FUN_0092b460_cls* FUN_007af430();
    int FUN_00401170();
    FUN_0092b460_cls* FUN_005d43c0();
    FUN_0092b460_cls* FUN_0041fe90();
    FUN_0092b460_cls* GetTargetFromOffset();
    FUN_0092b460_cls* FUN_008d8520();
    FUN_0092b460_cls* FUN_008d0430();
    void Execute(FUN_0092b460_cls* a, int b, int c, int d);
    void FUN_0092b460(FUN_0092b460_cls* a1, FUN_0092b460_cls* a2);
};
struct FUN_0092b9c0_Class : public MiddleHighProcess
{
    unsigned int GetAtOffset1DC(int index);
};
// Thiscall wrapper: pass the argument as this to FUN_008b3d30, make a virtual call on this, then clear the flag at +0xe1.
struct FUN_008b3d30_s
{
    void FUN_008b3d30();
};
class FUN_0092bf20_cls
{
  public:
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
    virtual void v00A();
    virtual void v00B();
    virtual void v00C();
    virtual void v00D();
    virtual void v00E();
    virtual void v00F();
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
    virtual void v01A();
    virtual void v01B();
    virtual void v01C();
    virtual void v01D();
    virtual void v01E();
    virtual void v01F();
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
    virtual void v02A();
    virtual void v02B();
    virtual void v02C();
    virtual void v02D();
    virtual void v02E();
    virtual void v02F();
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
    virtual void v03A();
    virtual void v03B();
    virtual void v03C();
    virtual void v03D();
    virtual void v03E();
    virtual void v03F();
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
    virtual void v04A();
    virtual void v04B();
    virtual void v04C();
    virtual void v04D();
    virtual void v04E();
    virtual void v04F();
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
    virtual void v05A();
    virtual void v05B();
    virtual void v05C();
    virtual void v05D();
    virtual void v05E();
    virtual void v05F();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06A();
    virtual void v06B();
    virtual void v06C();
    virtual void v06D();
    virtual void v06E();
    virtual void v06F();
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
    virtual void v07A();
    virtual void v07B();
    virtual void v07C();
    virtual void v07D();
    virtual void v07E();
    virtual void v07F();
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
    virtual void v08A();
    virtual void v08B();
    virtual void v08C();
    virtual void v08D();
    virtual void v08E();
    virtual void v08F();
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
    virtual void v09A();
    virtual void v09B();
    virtual void v09C();
    virtual void v09D();
    virtual void v09E();
    virtual void v09F();
    virtual void v0A0();
    virtual void v0A1();
    virtual void v0A2();
    virtual void v0A3();
    virtual void v0A4();
    virtual void v0A5();
    virtual void v0A6();
    virtual void v0A7();
    virtual void v0A8();
    virtual void v0A9();
    virtual void v0AA();
    virtual void v0AB();
    virtual void v0AC();
    virtual void v0AD();
    virtual void v0AE();
    virtual void v0AF();
    virtual void v0B0();
    virtual void v0B1();
    virtual void v0B2();
    virtual void v0B3();
    virtual void v0B4();
    virtual void v0B5();
    virtual void v0B6();
    virtual void v0B7();
    virtual void v0B8();
    virtual void v0B9();
    virtual void v0BA();
    virtual void v0BB();
    virtual void v0BC();
    virtual void v0BD();
    virtual void v0BE();
    virtual void v0BF();
    virtual void v0C0();
    virtual void v0C1();
    virtual void v0C2();
    virtual void v0C3();
    virtual void v0C4();
    virtual void v0C5();
    virtual void v0C6();
    virtual void v0C7();
    virtual void v0C8();
    virtual void v0C9();
    virtual void v0CA();
    virtual void v0CB();
    virtual void v0CC();
    virtual void v0CD();
    virtual void v0CE();
    virtual void v0CF();
    virtual void v0D0();
    virtual void v0D1();
    virtual void v0D2();
    virtual void v0D3();
    virtual void v0D4();
    virtual void v0D5();
    virtual void v0D6();
    virtual void v0D7();
    virtual void v0D8();
    virtual void v0D9();
    virtual void v0DA();
    virtual void v0DB();
    virtual void v0DC();
    virtual void v0DD();
    virtual void v0DE();
    virtual void v0DF();
    virtual void v0E0();
    virtual void v0E1();
    virtual void v0E2();
    virtual void v0E3();
    virtual void v0E4();
    virtual void v0E5();
    virtual void v0E6();
    virtual void v0E7();
    virtual void v0E8();
    virtual void v0E9();
    virtual void v0EA();
    virtual void v0EB();
    virtual void v0EC();
    virtual void v0ED();
    virtual void v0EE();
    virtual void v0EF();
    virtual void v0F0();
    virtual void v0F1();
    virtual void v0F2();
    virtual void v0F3();
    virtual void v0F4();
    virtual void v0F5();
    virtual void v0F6();
    virtual void v0F7();
    virtual void v0F8();
    virtual void v0F9();
    virtual void v0FA();
    virtual void v0FB();
    virtual void v0FC();
    virtual void v0FD();
    virtual void v0FE();
    virtual void v0FF();
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
    virtual void v10A();
    virtual void v10B();
    virtual void v10C();
    virtual void vSlot10D(int);
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
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    unsigned char unkE0;
    unsigned char m_e1;
    void FUN_0092bf20(FUN_008b3d30_s* p);
};
template <> NiPointer<NiNode>& NiPointer<NiNode>::operator=(NiNode*);
class MiddleHighProcess__DeferredHideLimb
{
  public:
    float fTime;
    int iLimbIndex;
    NiPointer<NiNode> spLimbNode;
    NiPointer<NiNode> spReplacementNode;
    bool m_bHideLimb;
    MiddleHighProcess__DeferredHideLimb();
};
struct FUN_0092bff0_shell : public MiddleHighProcess
{
    void QueueDeferredHideLimb(int aiLimbIndex, NiNode* apLimbNode, NiNode* apReplacementNode, bool abExplosion);
};
struct FUN_00493830_shell
{
    bool FUN_00493830();
};
struct FUN_00494710_shell
{
    bool FUN_00494710(unsigned short);
};
struct FUN_0092c340_shell : public MiddleHighProcess
{
    bool FUN_0092c340(int aiMovement);
};
struct CFItem;
struct CFList
{
    CFItem* pItem;
    CFList* pNext;

    CFItem** GetItem();
    CFList* GetNext();
    void AddTail(CFItem*& arItem);
};
struct CFActor
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual bool v78();
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    CFList* pCopiedFollowerList;
    CFList* pListB;
    int unk264;
    int unk268;
    int unk26C;
    char cFlag270;
    char unk271;
    char unk272;
    char unk273;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    char unk29C;
    char cFlag29D;
    char unk29E;
    char unk29F;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int iValue2AC;
    int unk2B0;
    float fValue2B4;
    float fValue2B8;
    float fValue2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int iValue2E4;
    int iValue2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    char cFlag348;
    char unk349;
    char unk34A;
    char unk34B;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int iValue370;
    char unk374;
    char cFlag375;
    char unk376;
    char unk377;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int iValue3AC;
    int iValue3B0;
    int unk3B4;
    char unk3B8;
    char cFlag3B9;
    char unk3BA;
    char unk3BB;
    int unk3BC;
    int unk3C0;
    float fValue3C4;
    int unk3C8;
    int iValue3CC;
    char cFlag3D0;
    char unk3D1;
    char unk3D2;
    char unk3D3;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    char unk458;
    char cFlag459;
    char unk45A;
    char unk45B;

    float GetField2B4();
    void CopyFromActor(CFActor* apSource);
};
#include <stdio.h>
class PathingLocation
{
  public:
    PathingLocation(const NiPoint3&, TESObjectCELL*);
    ~PathingLocation();
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
};
class PathingRequestClosePoint
{
  public:
    PathingRequestClosePoint();
    virtual ~PathingRequestClosePoint();
    void SetOrigin(const PathingLocation&);
    void FUN_00507610(float);
    void FUN_006e5ee0(float);
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
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
};
struct WanderPackage
{
    int GetProcedureType();
    NiPoint3 FUN_00675de0(Actor*);
    unsigned int FUN_00676280(Actor*);
};
struct WanderActor : Actor
{
    TESWorldSpace* FUN_00575d70();
    void FUN_008b3690(NiPoint3*, TESObjectCELL*, TESWorldSpace*, float, int);
};
struct WanderDataHandler
{
    TESObjectCELL* FUN_00461bc0(float, float, TESWorldSpace*, bool);
};
Actor* FUN_00703180();
void DebugLog(const char*, ...);
void GetObjectPosition(PathingRequestClosePoint*, NiPoint3*);
struct WanderProcess : LowProcess
{
    bool WanderToPoint(WanderActor*, int);
};
struct MgrObj
{
    void FUN_00444d40(void* a, int b, void* c);
    void* FUN_00447330(void* p);
    void FUN_00446500(void* a, int b, void* c);
};
extern MgrObj* DAT_011c3b3c;
extern int DAT_0118a838[];
unsigned short FUN_005f2370(int a, int b, int c, int d);
struct ObjB913
{
    int FUN_00496940();
    bool FUN_00494710(unsigned short a);
};
struct ResObj
{
    ~ResObj();
};
struct Proc
{
    virtual void vfn_000();
    virtual void vfn_001();
    virtual void vfn_002();
    virtual void vfn_003();
    virtual void vfn_004();
    virtual void vfn_005();
    virtual void vfn_006();
    virtual void vfn_007();
    virtual void vfn_008();
    virtual void vfn_009();
    virtual void vfn_010();
    virtual void vfn_011();
    virtual void vfn_012();
    virtual void vfn_013();
    virtual void vfn_014();
    virtual void vfn_015();
    virtual void vfn_016();
    virtual void vfn_017();
    virtual void vfn_018();
    virtual void vfn_019();
    virtual void vfn_020();
    virtual void vfn_021();
    virtual void vfn_022();
    virtual void vfn_023();
    virtual void vfn_024();
    virtual void vfn_025();
    virtual void vfn_026();
    virtual void vfn_027();
    virtual void vfn_028();
    virtual void vfn_029();
    virtual void vfn_030();
    virtual void vfn_031();
    virtual void vfn_032();
    virtual void vfn_033();
    virtual void vfn_034();
    virtual void vfn_035();
    virtual void vfn_036();
    virtual void vfn_037();
    virtual void vfn_038();
    virtual void vfn_039();
    virtual void vfn_040();
    virtual void vfn_041();
    virtual void vfn_042();
    virtual void vfn_043();
    virtual void vfn_044();
    virtual void vfn_045();
    virtual void vfn_046();
    virtual void vfn_047();
    virtual void vfn_048();
    virtual void vfn_049();
    virtual void vfn_050();
    virtual void vfn_051();
    virtual void vfn_052();
    virtual void vfn_053();
    virtual void vfn_054();
    virtual void vfn_055();
    virtual void vfn_056();
    virtual void vfn_057();
    virtual void vfn_058();
    virtual void vfn_059();
    virtual void vfn_060();
    virtual void vfn_061();
    virtual void vfn_062();
    virtual void vfn_063();
    virtual void vfn_064();
    virtual void vfn_065();
    virtual void vfn_066();
    virtual void vfn_067();
    virtual void vfn_068();
    virtual void vfn_069();
    virtual void vfn_070();
    virtual void vfn_071();
    virtual void vfn_072();
    virtual void vfn_073();
    virtual void vfn_074();
    virtual void vfn_075();
    virtual void vfn_076();
    virtual void vfn_077();
    virtual void vfn_078();
    virtual void vfn_079();
    virtual void vfn_080();
    virtual void vfn_081();
    virtual void vfn_082();
    virtual void vfn_083();
    virtual void vfn_084();
    virtual void vfn_085();
    virtual void vfn_086();
    virtual void vfn_087();
    virtual void vfn_088();
    virtual void vfn_089();
    virtual void vfn_090();
    virtual void vfn_091();
    virtual void vfn_092();
    virtual void vfn_093();
    virtual void vfn_094();
    virtual void vfn_095();
    virtual void vfn_096();
    virtual void vfn_097();
    virtual void vfn_098();
    virtual void vfn_099();
    virtual void vfn_100();
    virtual void vfn_101();
    virtual void vfn_102();
    virtual void vfn_103();
    virtual void vfn_104();
    virtual void vfn_105();
    virtual void vfn_106();
    virtual void vfn_107();
    virtual void vfn_108();
    virtual void vfn_109();
    virtual ObjB913* vfn_110();
    virtual void vfn_111();
    virtual void vfn_112();
    virtual void vfn_113();
    virtual void vfn_114();
    virtual void vfn_115();
    virtual void vfn_116();
    virtual void vfn_117();
    virtual void vfn_118();
    virtual void vfn_119();
    virtual void vfn_120();
    virtual void vfn_121();
    virtual void vfn_122();
    virtual void vfn_123();
    virtual void vfn_124();
    virtual void vfn_125();
    virtual void vfn_126();
    virtual void vfn_127();
    virtual void vfn_128();
    virtual void vfn_129();
    virtual void vfn_130();
    virtual void vfn_131();
    virtual void vfn_132();
    virtual void vfn_133();
    virtual void vfn_134();
    virtual bool vfn_135();
    int FUN_00401170();
    Proc* FUN_008d8520();
    int FUN_00446390();
    void* FUN_005715d0(int a, int b, int c);
};
struct FUN_00c3c590
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
    FUN_00c3c590(int a);
};
struct Sub14
{
    void* m_00;
    Sub14* FUN_006f74f0(FUN_00c3c590* o);
    void* FUN_00559450(void* a);
};
struct Host913
{
    Proc* m_00;
    int m_04;
    int m_08;
    unsigned char m_0c;
    unsigned char m_0d;
    unsigned char m_0e;
    unsigned char m_0f;
    int m_10;
    Sub14 m_14;
    bool FUN_00913a20(Proc* apProc);
};
struct Active96
{
    virtual ~Active96();
};
struct Arrow96
{
    void FUN_008d0240();
};
struct Hidden96
{
    ~Hidden96();
};
struct Item96
{
    ~Item96();
};
struct Lip96
{
    ~Lip96();
};
template <class T> struct List96
{
    T* value;
    List96* next;
    ~List96();
    T*& FUN_006815c0();
    List96* FUN_00726070();
    bool FUN_008256d0();
    void FUN_00470470();
    void FUN_0063f7b0();
};
struct Ptr96
{
    void* p;
    ~Ptr96();
    void FUN_0066b0d0(void*);
};
struct PtrA96
{
    void* p;
    ~PtrA96();
    void FUN_006f74f0(void*);
};
struct PtrB96
{
    void* p;
    ~PtrB96();
    void FUN_0092c8b0(void*);
};
struct Package96
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    ~Package96();
};
struct Base96
{

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
    int* raw;
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
    virtual ~Base96();
};
extern void* DAT_0108904c[];
struct Global96
{
    bool FUN_0047c850();
    void FUN_0085a2e0(void*);
};
struct FUN_00914610 : Base96
{
    List96<int> dead;
    List96<int> refs;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    Package96 package;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    Item96* weapon;
    Item96* ammo;
    PtrA96 preload;
    PtrB96 clone;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    Ptr96 controller;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    Lip96* lip;
    int unk1a4;
    int unk1a8;
    List96<Arrow96>* arrows;
    List96<Hidden96> hidden;
    List96<Active96>* effects;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    Ptr96 shader;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int* raw240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    ~FUN_00914610();
    void* FUN_008d83e0();
    void FUN_0091ee70();
    void FUN_0091fe80(int);
    void FUN_00914b40();
    void ClearQueuedItems();
};
struct QueueTask
{
    bool FUN_0043caa0();
};
struct TaskPointer
{
    QueueTask* pointer;
    QueueTask* FUN_00559450();
};
struct QueueObject
{
    int FUN_00401170();
    void FUN_004f15a0(int);
};
class PaddedFloatRecord
{
  public:
    QueueObject* object;
    ExtraDataList* extra;
    int count;
    bool equip;
    bool equipFlag1;
    bool equipFlag2;
    bool flag3;
    bool unequipFlag1;
    bool unequipFlag2;
    TaskPointer task;
    ~PaddedFloatRecord();
};
struct QueueActor
{
    int FUN_008a7570();
    TESObjectWEAP* FUN_008a1710();
    bool FUN_00894cc0(bool);
    void FUN_0088c830(QueueObject*, int, ExtraDataList*, bool, bool, bool);
    bool FUN_0088d7d0(QueueObject*, int, ExtraDataList*, bool, bool, bool);
    const char* FUN_005715d0();
};
struct QueueAnimation
{
    bool FUN_00494710(unsigned short);
    void FUN_00490400(void*);
};
struct QueueModelLoader
{
    void* FUN_00447330(const char*, bool, bool, bool);
};
extern QueueModelLoader* g_modelLoader;
unsigned short __cdecl FUN_005f2370(int, int, int, bool);
struct QueueProcess : MiddleHighProcess
{
    void ProcessQueuedItems(QueueActor* actor);
};
struct PendingObject
{
    int group;
    int value;
    int flags08;
    int flags0c;
    int flags10;
    InventoryLookup resource;
    void* __thiscall FUN_00915790(unsigned int deletingFlags);
};
struct PendingListNode
{
    PendingObject** FUN_006815c0();
    PendingListNode* FUN_00726070();
    void FUN_00905330(PendingObject** item);
};
struct PendingResourceManager
{
    void RunQueuedTask(InventoryItemLookup* item, unsigned int unused);
};
extern PendingResourceManager* DAT_01202d98;
struct PendingProcess : MiddleHighProcess
{
    void __thiscall RemovePendingByGroupAndValue(int group, int value);
};
struct P114Point
{
    float x, y, z;
    void FUN_006815c0();
    P114Point FUN_00439ef0(const P114Point&) const;
    float FUN_00457990() const;
};
struct P114RefOps
{
    ~P114RefOps();
    unsigned int FUN_0084e3a0();
    int FUN_0044ddc0();
    P114RefOps* FUN_00559450();
    P114RefOps** FUN_006815c0();
    TESObjectREFR* FUN_0041c8d0();
    TESObjectREFR* FUN_0067f390();
    void* FUN_0055d310();
    TESBoundObject* FUN_007af430();
    unsigned int FUN_004459e0(unsigned int);
};
struct P114Package
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
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual bool Check(Actor*, int, float, int);
    P114RefOps* FUN_00671d10();
    P114RefOps* FUN_0055b980();
    bool FUN_00674d40();
    int FUN_0041ca90();
    int FUN_00672930();
    bool FUN_00678610();
    P114Point FUN_00675de0(Actor*);
    void* FUN_00675a50(Actor*);
    void* FUN_00675c20(Actor*);
};
struct P114ActorOps
{
    P114RefOps* FUN_008a2d40();
    bool FUN_00575450(unsigned int);
    bool FUN_008b3bb0();
    void FUN_00892e90(int, P114RefOps*, TESObjectREFR*, int, unsigned int);
    TESObjectCELL* FUN_008d6f30();
    void FUN_0087faa0();
};
struct P114ActorView : TESObjectREFR
{
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void slot186();
    virtual void slot187();
    virtual void slot188();
    virtual void slot189();
    virtual void slot190();
    virtual void slot191();
    virtual void slot192();
    virtual void slot193();
    virtual void slot194();
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual void slot198();
    virtual void slot199();
    virtual void slot200();
    virtual void slot201();
    virtual void slot202();
    virtual void slot203();
    virtual void slot204();
    virtual void slot205();
    virtual void slot206();
    virtual void slot207();
    virtual void slot208();
    virtual void slot209();
    virtual void slot210();
    virtual void slot211();
    virtual void slot212();
    virtual void slot213();
    virtual void slot214();
    virtual void slot215();
    virtual void slot216();
    virtual void slot217();
    virtual void slot218();
    virtual void slot219();
    virtual void slot220();
    virtual void slot221();
    virtual void slot222();
    virtual void slot223();
    virtual void slot224();
    virtual void slot225();
    virtual void slot226();
    virtual void slot227();
    virtual void slot228();
    virtual void slot229();
    virtual void slot230();
    virtual void slot231();
    virtual void slot232();
    virtual void slot233();
    virtual void slot234();
    virtual void slot235();
    virtual void slot236();
    virtual void slot237();
    virtual void slot238();
    virtual void slot239();
    virtual void slot240();
    virtual void slot241();
    virtual void slot242();
    virtual void SetDestination(int, P114RefOps*, int, P114Point*, int);
};
struct P114Settings
{
    float* FUN_00403e20();
};
struct P114Cell
{
    bool FUN_00425fd0();
};
struct P114Clock
{
    float FUN_00867da0();
};
struct P114Global
{
    float FUN_00526ac0();
};
extern P114Settings DAT_011cdbac;
extern P114Settings DAT_011cd82c;
extern P114Clock DAT_011de7b8;
extern TESBoundObject* DAT_011ca244;
extern TESBoundObject* DAT_011ca248;
P114Global* __cdecl LookupFormByID(unsigned int);
struct P114Process : MiddleHighProcess
{
    virtual void slot493();
    virtual void slot494();
    virtual void slot495();
    virtual void slot496();
    virtual void slot497();
    virtual void slot498();
    virtual void slot499();
    virtual void slot500();
    virtual void slot501();
    virtual void slot502();
    virtual void slot503();
    virtual void slot504();
    virtual void slot505();
    virtual void slot506();
    virtual void slot507();
    virtual void slot508();
    virtual void slot509();
    virtual void slot510();
    virtual void slot511();
    virtual void slot512();
    virtual void slot513();
    virtual void slot514();
    virtual void slot515();
    virtual void slot516();
    virtual void slot517();
    virtual void slot518();
    virtual void slot519();
    virtual void slot520();
    virtual bool Move(Actor*, P114Point, void*, void*);
    float FUN_007df1f0();
    void FUN_00916df0(Actor* actor);
};
struct Target;
struct Node
{
    bool empty();
    int size();
    Target** value();
    Node* next();
    void remove(Target* const&);
    void clear();
    int data;
    Node* link;
};
struct Target
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
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual int state();
    virtual bool active();
    void* owner();
};
struct Gate
{
    bool ready();
    void reset();
};
extern Gate g_011e043c;
unsigned int randomValue();
struct Process
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
    virtual void update(Target*, int, int, int, int, int);
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
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void finish(int);
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void setTarget(Target*);
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void slot186();
    virtual void slot187();
    virtual void slot188();
    virtual void slot189();
    virtual void slot190();
    virtual void slot191();
    virtual void slot192();
    virtual void slot193();
    virtual void slot194();
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual void slot198();
    virtual void slot199();
    virtual void slot200();
    virtual void slot201();
    virtual void slot202();
    virtual void slot203();
    virtual void slot204();
    virtual void slot205();
    virtual void slot206();
    virtual void slot207();
    virtual void slot208();
    virtual void slot209();
    virtual void slot210();
    virtual void slot211();
    virtual void slot212();
    virtual void slot213();
    virtual void slot214();
    virtual void slot215();
    virtual void slot216();
    virtual void slot217();
    virtual void slot218();
    virtual void slot219();
    virtual void slot220();
    virtual void slot221();
    virtual void slot222();
    virtual void slot223();
    virtual void slot224();
    virtual void slot225();
    virtual void slot226();
    virtual void slot227();
    virtual void slot228();
    virtual void slot229();
    virtual void slot230();
    virtual void slot231();
    virtual void slot232();
    virtual void slot233();
    virtual void slot234();
    virtual void slot235();
    virtual void slot236();
    virtual void slot237();
    virtual void slot238();
    virtual void slot239();
    virtual void slot240();
    virtual void slot241();
    virtual void slot242();
    virtual void slot243();
    virtual void slot244();
    virtual void slot245();
    virtual void slot246();
    virtual void slot247();
    virtual void slot248();
    virtual void slot249();
    virtual void slot250();
    virtual void slot251();
    virtual void slot252();
    virtual void slot253();
    virtual void slot254();
    virtual void slot255();
    virtual void slot256();
    virtual void slot257();
    virtual void slot258();
    virtual void slot259();
    virtual void slot260();
    virtual void slot261();
    virtual void slot262();
    virtual void slot263();
    virtual void slot264();
    virtual void slot265();
    virtual void slot266();
    virtual void slot267();
    virtual void slot268();
    virtual void slot269();
    virtual void slot270();
    virtual void slot271();
    virtual void slot272();
    virtual void slot273();
    virtual void slot274();
    virtual void slot275();
    virtual void slot276();
    virtual void slot277();
    virtual void slot278();
    virtual void slot279();
    virtual void slot280();
    virtual void slot281();
    virtual void slot282();
    virtual void slot283();
    virtual void slot284();
    virtual void slot285();
    virtual void slot286();
    virtual void slot287();
    virtual void slot288();
    virtual void slot289();
    virtual void slot290();
    virtual void slot291();
    virtual void slot292();
    virtual void slot293();
    virtual void slot294();
    virtual void slot295();
    virtual void slot296();
    virtual void slot297();
    virtual void slot298();
    virtual void slot299();
    virtual void slot300();
    virtual void slot301();
    virtual void slot302();
    virtual void slot303();
    virtual void slot304();
    virtual void slot305();
    virtual void slot306();
    virtual void slot307();
    virtual void slot308();
    virtual void slot309();
    virtual void slot310();
    virtual void slot311();
    virtual void slot312();
    virtual void slot313();
    virtual void slot314();
    virtual void slot315();
    virtual void slot316();
    virtual void slot317();
    virtual void slot318();
    virtual void slot319();
    virtual void slot320();
    virtual void slot321();
    virtual void slot322();
    virtual void slot323();
    virtual void slot324();
    virtual void slot325();
    virtual void slot326();
    virtual void slot327();
    virtual void slot328();
    virtual void slot329();
    virtual void slot330();
    virtual void slot331();
    virtual void slot332();
    virtual void slot333();
    virtual void slot334();
    virtual void slot335();
    virtual void slot336();
    virtual void slot337();
    virtual void slot338();
    virtual void slot339();
    virtual void slot340();
    virtual void slot341();
    virtual void slot342();
    virtual void slot343();
    virtual void slot344();
    virtual void slot345();
    virtual void slot346();
    virtual void slot347();
    virtual void slot348();
    virtual void slot349();
    virtual void slot350();
    virtual void slot351();
    virtual void slot352();
    virtual void slot353();
    virtual void slot354();
    virtual void slot355();
    virtual void slot356();
    virtual void slot357();
    virtual void slot358();
    virtual void slot359();
    virtual void slot360();
    virtual void slot361();
    virtual void slot362();
    virtual void slot363();
    virtual void slot364();
    virtual void slot365();
    virtual void slot366();
    virtual void slot367();
    virtual void slot368();
    virtual void slot369();
    virtual void slot370();
    virtual void slot371();
    virtual void slot372();
    virtual void slot373();
    virtual void slot374();
    virtual void slot375();
    virtual void slot376();
    virtual void slot377();
    virtual void slot378();
    virtual void slot379();
    virtual void slot380();
    virtual void slot381();
    virtual void slot382();
    virtual void slot383();
    virtual void slot384();
    virtual void slot385();
    virtual void slot386();
    virtual void slot387();
    virtual void slot388();
    virtual void slot389();
    virtual void slot390();
    virtual void slot391();
    virtual void slot392();
    virtual void slot393();
    virtual void slot394();
    virtual void slot395();
    virtual void slot396();
    virtual void slot397();
    virtual void slot398();
    virtual void slot399();
    virtual void slot400();
    virtual void slot401();
    virtual void slot402();
    virtual void slot403();
    virtual void slot404();
    virtual void slot405();
    virtual void slot406();
    virtual void slot407();
    virtual void slot408();
    virtual void slot409();
    virtual void slot410();
    virtual void slot411();
    virtual void slot412();
    virtual void slot413();
    virtual void slot414();
    virtual void slot415();
    virtual void slot416();
    virtual void slot417();
    virtual void slot418();
    virtual void slot419();
    virtual void slot420();
    virtual void slot421();
    virtual void slot422();
    virtual void slot423();
    virtual void slot424();
    virtual void slot425();
    virtual void slot426();
    virtual void slot427();
    virtual void slot428();
    virtual void slot429();
    virtual void slot430();
    virtual void slot431();
    virtual void slot432();
    virtual void slot433();
    virtual void slot434();
    virtual void slot435();
    virtual void slot436();
    virtual void slot437();
    virtual void slot438();
    virtual void slot439();
    virtual void slot440();
    virtual void slot441();
    virtual void slot442();
    virtual void slot443();
    virtual void slot444();
    virtual void slot445();
    virtual void slot446();
    virtual void slot447();
    virtual void slot448();
    virtual void slot449();
    virtual void slot450();
    virtual void slot451();
    virtual void slot452();
    virtual void slot453();
    virtual void slot454();
    virtual void slot455();
    virtual void slot456();
    virtual void slot457();
    virtual void slot458();
    virtual void slot459();
    virtual void slot460();
    virtual void slot461();
    virtual void slot462();
    virtual void slot463();
    virtual void slot464();
    virtual void slot465();
    virtual void slot466();
    virtual void slot467();
    virtual void slot468();
    virtual void slot469();
    virtual void slot470();
    virtual void slot471();
    virtual void slot472();
    virtual void slot473();
    virtual void slot474();
    virtual void slot475();
    virtual void slot476();
    virtual void slot477();
    virtual void slot478();
    virtual void slot479();
    virtual void slot480();
    virtual void slot481();
    virtual void slot482();
    virtual void slot483();
    virtual void slot484();
    virtual void slot485();
    virtual void slot486();
    virtual void slot487();
    virtual void slot488();
    virtual void slot489();
    virtual void slot490();
    virtual void slot491();
    virtual void slot492();
    virtual void slot493();
    virtual void slot494();
    virtual void slot495();
    virtual void slot496();
    virtual void slot497();
    virtual void act(Target*, int);
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
    Node list;
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
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    Target* selected;
    void prepare(Target*, int, int);
    void changed();
    bool completed(Target*);
    void UpdateTargetSelection(Target* actor);
};
class MagicItem
{
  public:
    virtual ~MagicItem();
};
struct P3
{
    float x;
    float y;
    float z;
};
struct FormCls
{
    virtual void u0000();
    int FUN_00401170();
};
struct OwnerForm : public FormCls
{
};
struct NodeCls
{
    void* item;
    NodeCls* next;
    bool FUN_008256d0();
    void** FUN_006815c0();
    NodeCls* FUN_00726070();
    void FUN_00905330(void** p);
};
struct Proc4c
{
    NodeCls* FUN_00500940();
};
struct CellCls
{
    bool FUN_00425fd0();
};
struct ItemCls
{
    virtual void u0000();
    virtual void u0001();
    virtual void u0002();
    virtual void u0003();
    virtual void u0004();
    virtual void u0005();
    virtual void u0006();
    virtual void u0007();
    virtual void u0008();
    virtual void u0009();
    virtual void u000a();
    virtual void u000b();
    virtual void u000c();
    virtual void u000d();
    virtual void u000e();
    virtual void u000f();
    virtual void u0010();
    virtual void u0011();
    virtual void u0012();
    virtual void u0013();
    virtual void u0014();
    virtual void u0015();
    virtual void u0016();
    virtual void u0017();
    virtual void u0018();
    virtual void u0019();
    virtual void u001a();
    virtual void u001b();
    virtual void u001c();
    virtual void u001d();
    virtual void u001e();
    virtual void u001f();
    virtual void u0020();
    virtual void u0021();
    virtual void u0022();
    virtual void u0023();
    virtual void u0024();
    virtual void u0025();
    virtual void u0026();
    virtual void u0027();
    virtual void u0028();
    virtual void u0029();
    virtual void u002a();
    virtual void u002b();
    virtual void u002c();
    virtual void u002d();
    virtual void u002e();
    virtual void u002f();
    virtual void u0030();
    virtual void u0031();
    virtual void u0032();
    virtual void u0033();
    virtual void u0034();
    virtual void u0035();
    virtual void u0036();
    virtual void u0037();
    virtual void u0038();
    virtual void u0039();
    virtual void u003a();
    virtual void u003b();
    virtual void u003c();
    virtual void u003d();
    virtual void u003e();
    virtual void u003f();
    virtual bool V100();
    void* f00;
    OwnerForm* FUN_00567790();
    int FUN_005682c0(int a);
};
struct Cont
{
    ItemCls* p0;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int f18;
};
struct TESIdleForm
{
    void* FUN_0067f390();
};
struct Script
{
    TESIdleForm* GetText();
};
struct ObjC
{
    void* FUN_0067f390();
};
struct P0
{
    virtual void u0000();
    virtual void u0001();
    virtual void u0002();
    virtual void u0003();
    virtual void u0004();
    virtual void u0005();
    virtual void u0006();
    virtual void u0007();
    virtual void u0008();
    virtual void u0009();
    virtual void u000a();
    virtual void u000b();
    virtual void u000c();
    virtual void u000d();
    virtual void u000e();
    virtual void u000f();
    virtual void u0010();
    virtual void u0011();
    virtual void u0012();
    virtual void u0013();
    virtual void u0014();
    virtual void u0015();
    virtual void u0016();
    virtual void u0017();
    virtual void u0018();
    virtual void u0019();
    virtual void u001a();
    virtual void u001b();
    virtual void u001c();
    virtual void u001d();
    virtual void u001e();
    virtual void u001f();
    virtual void u0020();
    virtual void u0021();
    virtual void u0022();
    virtual void u0023();
    virtual void u0024();
    virtual void u0025();
    virtual void u0026();
    virtual void u0027();
    virtual void u0028();
    virtual void u0029();
    virtual void u002a();
    virtual void u002b();
    virtual void u002c();
    virtual void u002d();
    virtual void u002e();
    virtual void u002f();
    virtual void u0030();
    virtual void u0031();
    virtual void u0032();
    virtual void u0033();
    virtual void u0034();
    virtual void u0035();
    virtual void u0036();
    virtual void u0037();
    virtual void u0038();
    virtual void u0039();
    virtual void u003a();
    virtual void u003b();
    virtual void u003c();
    virtual void u003d();
    virtual void u003e();
    virtual void u003f();
    virtual void u0040();
    virtual void u0041();
    virtual void u0042();
    virtual void u0043();
    virtual void u0044();
    virtual void u0045();
    virtual void u0046();
    virtual void u0047();
    virtual void u0048();
    virtual void u0049();
    virtual void u004a();
    virtual void u004b();
    virtual void u004c();
    virtual void u004d();
    virtual void u004e();
    virtual void u004f();
    virtual void u0050();
    virtual void u0051();
    virtual void u0052();
    virtual void u0053();
    virtual void u0054();
    virtual void u0055();
    virtual void u0056();
    virtual void u0057();
    virtual void u0058();
    virtual void u0059();
    virtual void u005a();
    virtual void u005b();
    virtual void u005c();
    virtual void u005d();
    virtual void u005e();
    virtual void u005f();
    virtual void u0060();
    virtual void u0061();
    virtual void u0062();
    virtual void u0063();
    virtual void u0064();
    virtual void u0065();
    virtual void u0066();
    virtual void u0067();
    virtual void u0068();
    virtual void u0069();
    virtual void u006a();
    virtual void u006b();
    virtual void u006c();
    virtual void u006d();
    virtual void u006e();
    virtual void u006f();
    virtual void u0070();
    virtual void u0071();
    virtual void u0072();
    virtual void u0073();
    virtual void u0074();
    virtual void u0075();
    virtual void u0076();
    virtual void u0077();
    virtual void u0078();
    virtual void u0079();
    virtual void u007a();
    virtual void u007b();
    virtual void u007c();
    virtual void* V1f4();
    virtual void u007e();
    virtual void u007f();
    virtual void u0080();
    virtual void u0081();
    virtual void u0082();
    virtual void u0083();
    virtual void u0084();
    virtual void u0085();
    virtual void u0086();
    virtual void u0087();
    virtual void u0088();
    virtual void u0089();
    virtual void u008a();
    virtual bool V22c(int);
    void* FUN_00569b80_asP0();
    P0* FUN_00569b80();
    CellCls* FUN_008d6f30();
    void FUN_004534f0(unsigned int a);
    bool FUN_00493bb0();
};
struct ObjE
{
    virtual void u0000();
    virtual void u0001();
    virtual void u0002();
    virtual void u0003();
    virtual void u0004();
    virtual void u0005();
    virtual void u0006();
    virtual void u0007();
    virtual void u0008();
    virtual void u0009();
    virtual void u000a();
    virtual void u000b();
    virtual void u000c();
    virtual void u000d();
    virtual void u000e();
    virtual void u000f();
    virtual void u0010();
    virtual void u0011();
    virtual void u0012();
    virtual void u0013();
    virtual void u0014();
    virtual void u0015();
    virtual void u0016();
    virtual void u0017();
    virtual void u0018();
    virtual void u0019();
    virtual void u001a();
    virtual void u001b();
    virtual void u001c();
    virtual void u001d();
    virtual void u001e();
    virtual void u001f();
    virtual void u0020();
    virtual void u0021();
    virtual void u0022();
    virtual void u0023();
    virtual void u0024();
    virtual void u0025();
    virtual void u0026();
    virtual void u0027();
    virtual void u0028();
    virtual void u0029();
    virtual void u002a();
    virtual void u002b();
    virtual void u002c();
    virtual void u002d();
    virtual void u002e();
    virtual void u002f();
    virtual void u0030();
    virtual void u0031();
    virtual void u0032();
    virtual void u0033();
    virtual void u0034();
    virtual void u0035();
    virtual void u0036();
    virtual void u0037();
    virtual void u0038();
    virtual void u0039();
    virtual void u003a();
    virtual void u003b();
    virtual void u003c();
    virtual void u003d();
    virtual void u003e();
    virtual void u003f();
    virtual void u0040();
    virtual void u0041();
    virtual void u0042();
    virtual void u0043();
    virtual void u0044();
    virtual void u0045();
    virtual void u0046();
    virtual void u0047();
    virtual void u0048();
    virtual void u0049();
    virtual void u004a();
    virtual void u004b();
    virtual void u004c();
    virtual void u004d();
    virtual void u004e();
    virtual void u004f();
    virtual void u0050();
    virtual void u0051();
    virtual void u0052();
    virtual void u0053();
    virtual void u0054();
    virtual void u0055();
    virtual void u0056();
    virtual void u0057();
    virtual void u0058();
    virtual void u0059();
    virtual void u005a();
    virtual void u005b();
    virtual void u005c();
    virtual void u005d();
    virtual void u005e();
    virtual void u005f();
    virtual void u0060();
    virtual void u0061();
    virtual void u0062();
    virtual void u0063();
    virtual void u0064();
    virtual void u0065();
    virtual void u0066();
    virtual void u0067();
    virtual void u0068();
    virtual void u0069();
    virtual void u006a();
    virtual void u006b();
    virtual void u006c();
    virtual void u006d();
    virtual void u006e();
    virtual void u006f();
    virtual void u0070();
    virtual void u0071();
    virtual void u0072();
    virtual void u0073();
    virtual void u0074();
    virtual void u0075();
    virtual void u0076();
    virtual void u0077();
    virtual void u0078();
    virtual void u0079();
    virtual void u007a();
    virtual void u007b();
    virtual void u007c();
    virtual void u007d();
    virtual void u007e();
    virtual void u007f();
    virtual void u0080();
    virtual void u0081();
    virtual void u0082();
    virtual void u0083();
    virtual void u0084();
    virtual void u0085();
    virtual void u0086();
    virtual void u0087();
    virtual void u0088();
    virtual void u0089();
    virtual void u008a();
    virtual bool V22c(int);
};
struct ObjF : public FormCls
{
    virtual void u0000();
    virtual void u0001();
    virtual void u0002();
    virtual void u0003();
    virtual void u0004();
    virtual void u0005();
    virtual void u0006();
    virtual void u0007();
    virtual void u0008();
    virtual void u0009();
    virtual void u000a();
    virtual void u000b();
    virtual void u000c();
    virtual void u000d();
    virtual void u000e();
    virtual void u000f();
    virtual void u0010();
    virtual void u0011();
    virtual void u0012();
    virtual void u0013();
    virtual void u0014();
    virtual void u0015();
    virtual void u0016();
    virtual void u0017();
    virtual void u0018();
    virtual void u0019();
    virtual void u001a();
    virtual void u001b();
    virtual void u001c();
    virtual void u001d();
    virtual void u001e();
    virtual void u001f();
    virtual void u0020();
    virtual void u0021();
    virtual void u0022();
    virtual void u0023();
    virtual void u0024();
    virtual void u0025();
    virtual void u0026();
    virtual void u0027();
    virtual void u0028();
    virtual void u0029();
    virtual void u002a();
    virtual void u002b();
    virtual void u002c();
    virtual void u002d();
    virtual void u002e();
    virtual void u002f();
    virtual void u0030();
    virtual void u0031();
    virtual void u0032();
    virtual void u0033();
    virtual void u0034();
    virtual void u0035();
    virtual void u0036();
    virtual void u0037();
    virtual void u0038();
    virtual bool Ve4();
};
struct P2
{
    int FUN_00519b00();
    ObjE* FUN_00680020();
    ObjF* FUN_00680050();
    int FUN_00680080();
};
struct Pkg
{
    int FUN_0041ca90();
    ObjC* FUN_0055b980();
    bool FUN_00674d40();
    void FUN_00674e70(void* o, int a);
    void* FUN_00672f20();
    unsigned int FUN_006758a0(P0* a);
    void* FUN_006757e0(P0* a);
    P3 FUN_00675830(P0* a);
    int FUN_00672930();
    bool FUN_00678d00();
};
struct IdleCls
{
    bool FUN_006728a0();
};
struct PkgB
{
    bool FUN_00674d40();
};
struct P2B
{
    int FUN_00519b00();
};
struct DH46
{
    void FUN_0046f280(void* a1, P3* a2, float a3, void* a4, float a5, void* a6, P0* a7);
};
struct SetCls
{
    float* FUN_00403e20();
};
struct GCls
{
    ItemCls* FUN_00970a20(void* a, int b);
};
extern GCls DAT_011e0e80;
extern float DAT_01016970;
extern int DAT_01183028;
extern int DAT_01183140;
bool __cdecl CheckPackageMatch(TESObjectREFR* a, long b);
bool __fastcall FUN_00425fd0(TESObjectCELL* c);
void* __cdecl FUN_00ec43fb(void* a1, int a2, void* a3, void* a4, int a5);
struct FUN_00672930_cls
{
    int FUN_00672930();
};
struct FUN_00678d00_shell
{
    bool FUN_00678d00();
};
struct FUN_00905330
{
    void Remove(void* p);
};
struct FUN_004534f0_shell
{
    void FUN_004534f0(unsigned int a);
};
struct MobileObject;
struct Proxy758a0
{
    unsigned int FUN_006758a0(MobileObject* a);
};
struct ProcessQuery
{
    virtual void u0000();
    virtual void u0001();
    virtual void u0002();
    virtual void u0003();
    virtual void u0004();
    virtual void u0005();
    virtual void u0006();
    virtual void u0007();
    virtual void u0008();
    virtual void u0009();
    virtual void u000a();
    virtual void u000b();
    virtual void u000c();
    virtual void u000d();
    virtual void u000e();
    virtual void u000f();
    virtual void u0010();
    virtual void u0011();
    virtual void u0012();
    virtual void u0013();
    virtual void u0014();
    virtual void u0015();
    virtual void u0016();
    virtual void u0017();
    virtual void u0018();
    virtual void u0019();
    virtual void u001a();
    virtual void u001b();
    virtual void u001c();
    virtual void u001d();
    virtual void u001e();
    virtual void u001f();
    virtual void u0020();
    virtual void u0021();
    virtual void u0022();
    virtual void u0023();
    virtual void u0024();
    virtual void u0025();
    virtual void u0026();
    virtual void u0027();
    virtual void u0028();
    virtual void u0029();
    virtual void u002a();
    virtual void u002b();
    virtual void u002c();
    virtual void u002d();
    virtual void u002e();
    virtual void u002f();
    virtual void u0030();
    virtual void u0031();
    virtual void u0032();
    virtual void u0033();
    virtual void u0034();
    virtual void u0035();
    virtual void u0036();
    virtual void u0037();
    virtual void u0038();
    virtual void u0039();
    virtual void u003a();
    virtual void u003b();
    virtual void u003c();
    virtual void u003d();
    virtual void u003e();
    virtual void u003f();
    virtual void u0040();
    virtual void u0041();
    virtual void u0042();
    virtual void u0043();
    virtual void u0044();
    virtual void u0045();
    virtual void u0046();
    virtual void u0047();
    virtual void u0048();
    virtual void u0049();
    virtual void u004a();
    virtual void u004b();
    virtual void u004c();
    virtual void u004d();
    virtual void u004e();
    virtual void u004f();
    virtual void u0050();
    virtual void u0051();
    virtual void u0052();
    virtual void u0053();
    virtual void u0054();
    virtual void u0055();
    virtual void u0056();
    virtual void u0057();
    virtual void u0058();
    virtual void u0059();
    virtual void u005a();
    virtual void u005b();
    virtual void u005c();
    virtual void u005d();
    virtual void u005e();
    virtual void u005f();
    virtual void u0060();
    virtual void u0061();
    virtual void u0062();
    virtual void u0063();
    virtual void u0064();
    virtual void u0065();
    virtual void u0066();
    virtual void u0067();
    virtual void u0068();
    virtual void u0069();
    virtual void u006a();
    virtual void u006b();
    virtual void u006c();
    virtual void u006d();
    virtual void u006e();
    virtual void u006f();
    virtual void u0070();
    virtual void u0071();
    virtual void u0072();
    virtual void u0073();
    virtual void u0074();
    virtual void u0075();
    virtual void u0076();
    virtual void u0077();
    virtual void u0078();
    virtual void u0079();
    virtual void u007a();
    virtual void u007b();
    virtual void u007c();
    virtual void u007d();
    virtual void u007e();
    virtual void u007f();
    virtual void u0080();
    virtual void u0081();
    virtual void u0082();
    virtual void u0083();
    virtual void u0084();
    virtual void u0085();
    virtual void u0086();
    virtual void u0087();
    virtual void u0088();
    virtual void u0089();
    virtual void u008a();
    virtual IdleCls* Query();
};
struct ThisCls
{
    virtual void u0000();
    virtual void u0001();
    virtual void u0002();
    virtual void u0003();
    virtual void u0004();
    virtual void u0005();
    virtual void u0006();
    virtual void u0007();
    virtual void u0008();
    virtual void u0009();
    virtual void u000a();
    virtual void u000b();
    virtual void u000c();
    virtual void u000d();
    virtual void u000e();
    virtual void u000f();
    virtual void u0010();
    virtual void u0011();
    virtual void u0012();
    virtual void u0013();
    virtual void u0014();
    virtual void u0015();
    virtual void u0016();
    virtual void u0017();
    virtual void u0018();
    virtual void u0019();
    virtual void u001a();
    virtual void u001b();
    virtual void u001c();
    virtual void u001d();
    virtual void u001e();
    virtual void u001f();
    virtual void u0020();
    virtual void u0021();
    virtual void u0022();
    virtual void u0023();
    virtual void u0024();
    virtual void u0025();
    virtual void u0026();
    virtual void u0027();
    virtual void u0028();
    virtual void u0029();
    virtual void u002a();
    virtual void u002b();
    virtual void u002c();
    virtual void u002d();
    virtual void u002e();
    virtual void u002f();
    virtual void u0030();
    virtual void u0031();
    virtual void u0032();
    virtual void u0033();
    virtual void u0034();
    virtual void u0035();
    virtual void u0036();
    virtual void u0037();
    virtual void u0038();
    virtual void u0039();
    virtual void u003a();
    virtual void u003b();
    virtual void u003c();
    virtual void u003d();
    virtual void u003e();
    virtual void u003f();
    virtual void u0040();
    virtual void u0041();
    virtual void u0042();
    virtual void u0043();
    virtual void u0044();
    virtual void u0045();
    virtual void u0046();
    virtual void u0047();
    virtual void u0048();
    virtual void u0049();
    virtual void u004a();
    virtual void u004b();
    virtual void u004c();
    virtual void u004d();
    virtual void u004e();
    virtual void u004f();
    virtual void u0050();
    virtual void u0051();
    virtual void u0052();
    virtual void u0053();
    virtual void u0054();
    virtual void u0055();
    virtual void u0056();
    virtual void u0057();
    virtual void u0058();
    virtual void u0059();
    virtual void u005a();
    virtual void u005b();
    virtual void u005c();
    virtual void u005d();
    virtual void u005e();
    virtual void u005f();
    virtual void u0060();
    virtual void u0061();
    virtual void u0062();
    virtual void u0063();
    virtual void u0064();
    virtual void u0065();
    virtual void u0066();
    virtual void u0067();
    virtual void u0068();
    virtual void u0069();
    virtual void u006a();
    virtual void u006b();
    virtual void u006c();
    virtual void u006d();
    virtual void u006e();
    virtual void u006f();
    virtual void u0070();
    virtual void u0071();
    virtual void u0072();
    virtual void u0073();
    virtual void u0074();
    virtual void u0075();
    virtual void u0076();
    virtual void u0077();
    virtual void u0078();
    virtual void u0079();
    virtual void u007a();
    virtual void u007b();
    virtual void u007c();
    virtual void u007d();
    virtual void u007e();
    virtual void u007f();
    virtual void u0080();
    virtual void u0081();
    virtual void u0082();
    virtual void u0083();
    virtual void u0084();
    virtual void u0085();
    virtual void u0086();
    virtual void u0087();
    virtual void u0088();
    virtual void u0089();
    virtual void u008a();
    virtual IdleCls* V22c(void* a, void* b);
    virtual void u008c();
    virtual void u008d();
    virtual void u008e();
    virtual void u008f();
    virtual void u0090();
    virtual void u0091();
    virtual void u0092();
    virtual void u0093();
    virtual void u0094();
    virtual void u0095();
    virtual void u0096();
    virtual void u0097();
    virtual void u0098();
    virtual void u0099();
    virtual void u009a();
    virtual void u009b();
    virtual void u009c();
    virtual void u009d();
    virtual void u009e();
    virtual void u009f();
    virtual void u00a0();
    virtual void u00a1();
    virtual void u00a2();
    virtual void u00a3();
    virtual void u00a4();
    virtual void u00a5();
    virtual void u00a6();
    virtual void u00a7();
    virtual void u00a8();
    virtual void u00a9();
    virtual void u00aa();
    virtual void u00ab();
    virtual void u00ac();
    virtual void u00ad();
    virtual void u00ae();
    virtual void u00af();
    virtual void u00b0();
    virtual void u00b1();
    virtual void u00b2();
    virtual void u00b3();
    virtual void u00b4();
    virtual void u00b5();
    virtual void u00b6();
    virtual void u00b7();
    virtual void u00b8();
    virtual void u00b9();
    virtual void u00ba();
    virtual void u00bb();
    virtual void u00bc();
    virtual void u00bd();
    virtual void u00be();
    virtual void u00bf();
    virtual void u00c0();
    virtual void u00c1();
    virtual void u00c2();
    virtual void u00c3();
    virtual void u00c4();
    virtual void u00c5();
    virtual void u00c6();
    virtual void u00c7();
    virtual void u00c8();
    virtual void u00c9();
    virtual void u00ca();
    virtual void u00cb();
    virtual void u00cc();
    virtual void u00cd();
    virtual void u00ce();
    virtual void u00cf();
    virtual void u00d0();
    virtual void u00d1();
    virtual void u00d2();
    virtual void u00d3();
    virtual void u00d4();
    virtual void u00d5();
    virtual void u00d6();
    virtual void u00d7();
    virtual void u00d8();
    virtual void u00d9();
    virtual void u00da();
    virtual void u00db();
    virtual void u00dc();
    virtual void u00dd();
    virtual void u00de();
    virtual void u00df();
    virtual void u00e0();
    virtual void u00e1();
    virtual void u00e2();
    virtual void u00e3();
    virtual void u00e4();
    virtual void u00e5();
    virtual void u00e6();
    virtual void u00e7();
    virtual void u00e8();
    virtual void u00e9();
    virtual void u00ea();
    virtual void u00eb();
    virtual void u00ec();
    virtual void u00ed();
    virtual void u00ee();
    virtual void u00ef();
    virtual void u00f0();
    virtual void u00f1();
    virtual void u00f2();
    virtual void u00f3();
    virtual void u00f4();
    virtual void u00f5();
    virtual void u00f6();
    virtual void u00f7();
    virtual void u00f8();
    virtual void u00f9();
    virtual void u00fa();
    virtual void u00fb();
    virtual void u00fc();
    virtual void u00fd();
    virtual void u00fe();
    virtual void u00ff();
    virtual void u0100();
    virtual void u0101();
    virtual void u0102();
    virtual void u0103();
    virtual void u0104();
    virtual void u0105();
    virtual void u0106();
    virtual void u0107();
    virtual void u0108();
    virtual void u0109();
    virtual void u010a();
    virtual void u010b();
    virtual void u010c();
    virtual void u010d();
    virtual void u010e();
    virtual void u010f();
    virtual void u0110();
    virtual void u0111();
    virtual void u0112();
    virtual void u0113();
    virtual void u0114();
    virtual void u0115();
    virtual void u0116();
    virtual void u0117();
    virtual void u0118();
    virtual void u0119();
    virtual void u011a();
    virtual void u011b();
    virtual void u011c();
    virtual void u011d();
    virtual void u011e();
    virtual void u011f();
    virtual void u0120();
    virtual void u0121();
    virtual void u0122();
    virtual void u0123();
    virtual void u0124();
    virtual void u0125();
    virtual void u0126();
    virtual void u0127();
    virtual void u0128();
    virtual void u0129();
    virtual void u012a();
    virtual void u012b();
    virtual void u012c();
    virtual void u012d();
    virtual void u012e();
    virtual void u012f();
    virtual void u0130();
    virtual void u0131();
    virtual void* V4c8();
    virtual void u0133();
    virtual void u0134();
    virtual void u0135();
    virtual void u0136();
    virtual void u0137();
    virtual void u0138();
    virtual void u0139();
    virtual void u013a();
    virtual void u013b();
    virtual void u013c();
    virtual void u013d();
    virtual void u013e();
    virtual void u013f();
    virtual void u0140();
    virtual void u0141();
    virtual void u0142();
    virtual void u0143();
    virtual void u0144();
    virtual void u0145();
    virtual void u0146();
    virtual void u0147();
    virtual void u0148();
    virtual void u0149();
    virtual void u014a();
    virtual void u014b();
    virtual void u014c();
    virtual void u014d();
    virtual void u014e();
    virtual void u014f();
    virtual void u0150();
    virtual void u0151();
    virtual void u0152();
    virtual void u0153();
    virtual void u0154();
    virtual void u0155();
    virtual void u0156();
    virtual void u0157();
    virtual void u0158();
    virtual void u0159();
    virtual void u015a();
    virtual void u015b();
    virtual void u015c();
    virtual void u015d();
    virtual void u015e();
    virtual void u015f();
    virtual void u0160();
    virtual void u0161();
    virtual void u0162();
    virtual void u0163();
    virtual void u0164();
    virtual void u0165();
    virtual void u0166();
    virtual void u0167();
    virtual void u0168();
    virtual void u0169();
    virtual void u016a();
    virtual void u016b();
    virtual void u016c();
    virtual void u016d();
    virtual void u016e();
    virtual void u016f();
    virtual void u0170();
    virtual void u0171();
    virtual void u0172();
    virtual void u0173();
    virtual void u0174();
    virtual void u0175();
    virtual void u0176();
    virtual void u0177();
    virtual void u0178();
    virtual void u0179();
    virtual void u017a();
    virtual void u017b();
    virtual void u017c();
    virtual void u017d();
    virtual void u017e();
    virtual void u017f();
    virtual void u0180();
    virtual void u0181();
    virtual void u0182();
    virtual void u0183();
    virtual void u0184();
    virtual void u0185();
    virtual void u0186();
    virtual void u0187();
    virtual void u0188();
    virtual void u0189();
    virtual void u018a();
    virtual void u018b();
    virtual void u018c();
    virtual void u018d();
    virtual void u018e();
    virtual void u018f();
    virtual void u0190();
    virtual void u0191();
    virtual void u0192();
    virtual void u0193();
    virtual void u0194();
    virtual void u0195();
    virtual void u0196();
    virtual void u0197();
    virtual void u0198();
    virtual void u0199();
    virtual void u019a();
    virtual void u019b();
    virtual void u019c();
    virtual void u019d();
    virtual void u019e();
    virtual void u019f();
    virtual void u01a0();
    virtual void u01a1();
    virtual void u01a2();
    virtual void u01a3();
    virtual void u01a4();
    virtual void u01a5();
    virtual void u01a6();
    virtual void u01a7();
    virtual void u01a8();
    virtual void u01a9();
    virtual void u01aa();
    virtual void u01ab();
    virtual void u01ac();
    virtual void u01ad();
    virtual void u01ae();
    virtual void u01af();
    virtual void u01b0();
    virtual void u01b1();
    virtual void u01b2();
    virtual void u01b3();
    virtual void u01b4();
    virtual void u01b5();
    virtual void u01b6();
    virtual void u01b7();
    virtual void u01b8();
    virtual void u01b9();
    virtual void u01ba();
    virtual void u01bb();
    virtual void u01bc();
    virtual void u01bd();
    virtual void u01be();
    virtual void u01bf();
    virtual void u01c0();
    virtual void u01c1();
    virtual void u01c2();
    virtual void u01c3();
    virtual void u01c4();
    virtual void u01c5();
    virtual void u01c6();
    virtual void u01c7();
    virtual void u01c8();
    virtual void u01c9();
    virtual void u01ca();
    virtual void u01cb();
    virtual void u01cc();
    virtual void u01cd();
    virtual void u01ce();
    virtual void u01cf();
    virtual void u01d0();
    virtual void u01d1();
    virtual void u01d2();
    virtual void u01d3();
    virtual void u01d4();
    virtual void u01d5();
    virtual void u01d6();
    virtual void u01d7();
    virtual void u01d8();
    virtual void u01d9();
    virtual void u01da();
    virtual void u01db();
    virtual void u01dc();
    virtual void u01dd();
    virtual void u01de();
    virtual void u01df();
    virtual void u01e0();
    virtual void u01e1();
    virtual void u01e2();
    virtual void u01e3();
    virtual void u01e4();
    virtual void u01e5();
    virtual void u01e6();
    virtual void u01e7();
    virtual void u01e8();
    virtual void u01e9();
    virtual void u01ea();
    virtual void u01eb();
    virtual void u01ec();
    virtual void u01ed();
    virtual void u01ee();
    virtual void u01ef();
    virtual void u01f0();
    virtual void u01f1();
    virtual void u01f2();
    virtual void u01f3();
    virtual void u01f4();
    virtual void u01f5();
    virtual void u01f6();
    virtual void u01f7();
    virtual void u01f8();
    virtual void u01f9();
    virtual void u01fa();
    virtual void u01fb();
    virtual void u01fc();
    virtual void u01fd();
    virtual void u01fe();
    virtual void u01ff();
    virtual void u0200();
    virtual void u0201();
    virtual void u0202();
    virtual void u0203();
    virtual void u0204();
    virtual void u0205();
    virtual void V818(void* a);
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
    void* f40;
    int unk044;
    int unk048;
    Proc4c* f4c;
    short f50;
    short unk052;
    int unk054;
    int f58;
    NodeCls list5c;
    Cont* f64;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    void* f84;
    int unk088;
    int f8c;
    void* f90;
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
    int unk100;
    int unk104;
    int f108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    void* f164;
    void* CollectSearchResults(P0* a, void* b, int c);
    void* FUN_0091ae00(P0* arg0, Pkg* arg1, P2* arg2);
};
struct PackageTargetAccess
{
    int FUN_00678ca0();
};
struct PackageAccess : TESForm
{
    virtual void PackageSlot78();
    virtual bool IsEffectValid(Actor*, int, float, int);
    bool FUN_008a6290();
    void SetFlag10000(bool);
    float GetPackageResult(Actor*, bool);
    int FUN_0041ca90();
    PackageTargetAccess* FUN_0055b980();
    bool FUN_00674d40();
};
struct PlayerPackageAccess
{
    bool HasExtraFollowerForm(Actor*);
    int FUN_00962620();
};
struct ReferenceAccess
{
    float FUN_005723b0(TESObjectREFR*, int, int);
    TESWorldSpace* FUN_00575d70();
    bool FUN_008b3bb0();
    void FUN_0087faa0();
};
struct SettingIntAccess
{
    int* FUN_0043d4d0();
};
struct SettingFloatAccess
{
    float* FUN_00403e20();
};
extern SettingIntAccess DAT_011cdad0;
extern SettingFloatAccess DAT_011cd950;
struct FollowProcess : TargetProcess
{
    virtual void FollowSlot517();
    virtual void FollowSlot518();
    virtual void FollowSlot519();
    virtual void FollowSlot520();
    virtual bool UpdateDestination(Actor*, NiPoint3, TESObjectCELL*, TESWorldSpace*);
    bool FUN_0091d3c0(Actor* actor, float elapsed, bool advance);
};
struct ActivationPackage : TESForm
{
    virtual void Package4e();
    virtual void Package4f();
    virtual void Package50();
    virtual bool IsNear(Actor*, int);
    virtual bool IsEffectValid(Actor*, int);
};
struct ActivationReference : TESObjectREFR
{
    void* FUN_00568e50();
    const NiPoint3& FUN_00568fa0();
    bool FUN_00440d80();
    bool Activate(Actor*, bool, TESBoundObject*, int);
};
struct ActivationPlayer : Actor
{
    int unknown1b4;
    int unknown1b8;
    int unknown1bc;
    int unknown1c0;
    int unknown1c4;
    int unknown1c8;
    int unknown1cc;
    int unknown1d0;
    int unknown1d4;
    int unknown1d8;
    int unknown1dc;
    int unknown1e0;
    int unknown1e4;
    int unknown1e8;
    int unknown1ec;
    int unknown1f0;
    int unknown1f4;
    int unknown1f8;
    int unknown1fc;
    int unknown200;
    int unknown204;
    int unknown208;
    bool busy;
    bool IsSleepingOrResting();
    void FUN_005c1a00(bool, int);
};
struct NiPoint3_ext : NiPoint3
{
    NiPoint3_ext();
};
struct ActivationProcess : MiddleHighProcess
{
    bool CheckActivationTarget(Actor* actor);
};
struct ProcedureSetting
{
    float* FUN_00403e20();
};
extern ProcedureSetting DAT_011cd6cc;
extern const float DAT_01084838;
struct ProcedureRef
{
    bool FUN_00440da0();
};
struct ProcedureProcess
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
    virtual void Update();
};
struct ProcedureActor
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
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual void Slot75();
    virtual void Slot76();
    virtual void Slot77();
    virtual void Slot78();
    virtual void Slot79();
    virtual void Slot80();
    virtual void Slot81();
    virtual void Slot82();
    virtual void Slot83();
    virtual void Slot84();
    virtual void Slot85();
    virtual void Slot86();
    virtual void Slot87();
    virtual void Slot88();
    virtual void Slot89();
    virtual void Slot90();
    virtual void Slot91();
    virtual void Slot92();
    virtual void Slot93();
    virtual void Slot94();
    virtual void Slot95();
    virtual void Slot96();
    virtual void Slot97();
    virtual void Slot98();
    virtual void Slot99();
    virtual void Slot100();
    virtual void Slot101();
    virtual void Slot102();
    virtual void Slot103();
    virtual void Slot104();
    virtual void Slot105();
    virtual void Slot106();
    virtual void Slot107();
    virtual void Slot108();
    virtual void Slot109();
    virtual void Slot110();
    virtual void Slot111();
    virtual void Slot112();
    virtual void Slot113();
    virtual void Slot114();
    virtual void Slot115();
    virtual void Slot116();
    virtual void Slot117();
    virtual void Slot118();
    virtual void Slot119();
    virtual void Slot120();
    virtual void Slot121();
    virtual void Slot122();
    virtual void Slot123();
    virtual void Slot124();
    virtual void Slot125();
    virtual void Slot126();
    virtual void Slot127();
    virtual void Slot128();
    virtual void Slot129();
    virtual void Slot130();
    virtual void Slot131();
    virtual void Slot132();
    virtual void Slot133();
    virtual void Slot134();
    virtual void Slot135();
    virtual void Slot136();
    virtual void Slot137();
    virtual void Slot138();
    virtual bool IsBusy(int);
    virtual void Slot140();
    virtual void Slot141();
    virtual void Slot142();
    virtual void Slot143();
    virtual void Slot144();
    virtual void Slot145();
    virtual void Slot146();
    virtual void Slot147();
    virtual void Slot148();
    virtual void Slot149();
    virtual void Slot150();
    virtual void Slot151();
    virtual void Slot152();
    virtual void Slot153();
    virtual void Slot154();
    virtual void Slot155();
    virtual void Slot156();
    virtual void Slot157();
    virtual void Slot158();
    virtual void Slot159();
    virtual void Slot160();
    virtual void Slot161();
    virtual void Slot162();
    virtual void Slot163();
    virtual void Slot164();
    virtual void Slot165();
    virtual void Slot166();
    virtual void Slot167();
    virtual void Slot168();
    virtual void Slot169();
    virtual void Slot170();
    virtual void Slot171();
    virtual void Slot172();
    virtual void Slot173();
    virtual void Slot174();
    virtual void Slot175();
    virtual void Slot176();
    virtual void Slot177();
    virtual void Slot178();
    virtual void Slot179();
    virtual void Slot180();
    virtual void Slot181();
    virtual void Slot182();
    virtual void Slot183();
    virtual void Slot184();
    virtual void Slot185();
    virtual void Slot186();
    virtual void Slot187();
    virtual void Slot188();
    virtual void Slot189();
    virtual void Slot190();
    virtual void Slot191();
    virtual void Slot192();
    virtual void Slot193();
    virtual void Slot194();
    virtual void Slot195();
    virtual void Slot196();
    virtual void Slot197();
    virtual void Slot198();
    virtual void Slot199();
    virtual void Slot200();
    virtual void Slot201();
    virtual void Slot202();
    virtual void Slot203();
    virtual void Slot204();
    virtual void Slot205();
    virtual void Slot206();
    virtual void Slot207();
    virtual void Slot208();
    virtual void Slot209();
    virtual void Slot210();
    virtual void Slot211();
    virtual void Slot212();
    virtual void Slot213();
    virtual void Slot214();
    virtual void Slot215();
    virtual void Slot216();
    virtual void Slot217();
    virtual void Slot218();
    virtual void Slot219();
    virtual void Slot220();
    virtual void Slot221();
    virtual void Slot222();
    virtual void Slot223();
    virtual void Slot224();
    virtual void Slot225();
    virtual void Slot226();
    virtual void Slot227();
    virtual void Slot228();
    virtual void Slot229();
    virtual void Slot230();
    virtual void Slot231();
    virtual void Slot232();
    virtual void Slot233();
    virtual void Slot234();
    virtual void Slot235();
    virtual void Slot236();
    virtual void Slot237();
    virtual void Slot238();
    virtual void Slot239();
    virtual void Slot240();
    virtual void Slot241();
    virtual void Slot242();
    virtual void Slot243();
    virtual void Slot244();
    virtual void Slot245();
    virtual void Slot246();
    virtual void Slot247();
    virtual void Slot248();
    virtual void Slot249();
    virtual void Slot250();
    virtual void Slot251();
    virtual void Slot252();
    virtual void Slot253();
    virtual void Slot254();
    virtual void Slot255();
    virtual void Slot256();
    virtual void Slot257();
    virtual void Slot258();
    virtual void Slot259();
    virtual void Slot260();
    virtual void Slot261();
    virtual void Slot262();
    virtual void Slot263();
    virtual void Slot264();
    virtual void Slot265();
    virtual void Slot266();
    virtual void Slot267();
    virtual void Slot268();
    virtual void ResetTargetPointer(Actor*);
    virtual void Advance();
    void FUN_00881680(int);
    float FUN_005723b0(Actor*, int, int);
    ProcedureProcess* FUN_008d8520();
};
struct FollowProcedure
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
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void AcquireTarget(ProcedureActor*);
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
    TESObjectREFR* targetReference;
    void FUN_0091d3c0(ProcedureActor*, float, bool);
    bool FUN_0091dd30(ProcedureActor*, void*);
};
struct RefQuery
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
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual bool IsActor();
};
struct CrimeEntry;
struct CrimeNode
{
    CrimeEntry** Head();
    CrimeNode* Next();
};
struct AlarmInfo
{
    char* GetData();
    CrimeNode* GetCrimeNode();
};
struct CrimeEntry
{
    TESObjectREFR* Reference();
    bool Done();
    int Kind();
};
struct ClassInfo
{
    bool Guard();
};
struct CrimeContext
{
    void* Resolve();
};
struct SettingValue
{
    int* IntValue();
};
extern SettingValue crimeSetting;
void CrimeCallback();
struct CrimeHandler
{
    void Process(void*, int, int, void (*)(), CrimeEntry*);
};
extern CrimeHandler* crimeHandler;
struct CrimeActor
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
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual void Slot75();
    virtual void Slot76();
    virtual void Slot77();
    virtual void Slot78();
    virtual void Slot79();
    virtual void Slot80();
    virtual void Slot81();
    virtual void Slot82();
    virtual void Slot83();
    virtual void Slot84();
    virtual void Slot85();
    virtual void Slot86();
    virtual void Slot87();
    virtual void Slot88();
    virtual void Slot89();
    virtual void Slot90();
    virtual void Slot91();
    virtual void Slot92();
    virtual void Slot93();
    virtual void Slot94();
    virtual void Slot95();
    virtual void Slot96();
    virtual void Slot97();
    virtual void Slot98();
    virtual void Slot99();
    virtual void Slot100();
    virtual void Slot101();
    virtual void Slot102();
    virtual void Slot103();
    virtual void Slot104();
    virtual void Slot105();
    virtual void Slot106();
    virtual void Slot107();
    virtual void Slot108();
    virtual void Slot109();
    virtual void Slot110();
    virtual void Slot111();
    virtual void Slot112();
    virtual void Slot113();
    virtual void Slot114();
    virtual void Slot115();
    virtual void Slot116();
    virtual void Slot117();
    virtual void Slot118();
    virtual void Slot119();
    virtual void Slot120();
    virtual void Slot121();
    virtual void Slot122();
    virtual void Slot123();
    virtual void Slot124();
    virtual int Value(float);
    ClassInfo* Class();
    void* Extra();
    bool Evaluate(void*, int, int*, int);
};
struct CrimeProcess
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
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual void Slot75();
    virtual void Slot76();
    virtual void Slot77();
    virtual void Slot78();
    virtual void Slot79();
    virtual void Slot80();
    virtual void Slot81();
    virtual void Slot82();
    virtual void Slot83();
    virtual void Slot84();
    virtual void Slot85();
    virtual void Slot86();
    virtual void Slot87();
    virtual void Slot88();
    virtual void Slot89();
    virtual void Slot90();
    virtual void Slot91();
    virtual void Slot92();
    virtual void Slot93();
    virtual void Slot94();
    virtual void Slot95();
    virtual void Slot96();
    virtual void Slot97();
    virtual void Slot98();
    virtual void Slot99();
    virtual void Slot100();
    virtual void Slot101();
    virtual void Slot102();
    virtual void Slot103();
    virtual void Slot104();
    virtual void Slot105();
    virtual void Slot106();
    virtual void Slot107();
    virtual void Slot108();
    virtual void Slot109();
    virtual void Slot110();
    virtual void Slot111();
    virtual void Slot112();
    virtual void Slot113();
    virtual void Slot114();
    virtual void Slot115();
    virtual void Slot116();
    virtual void Slot117();
    virtual void Slot118();
    virtual void Slot119();
    virtual void Slot120();
    virtual void Slot121();
    virtual void Slot122();
    virtual void Slot123();
    virtual void Slot124();
    virtual void Slot125();
    virtual void Slot126();
    virtual void Slot127();
    virtual void Slot128();
    virtual void Slot129();
    virtual void Slot130();
    virtual void Slot131();
    virtual void Slot132();
    virtual void Slot133();
    virtual void Slot134();
    virtual void Slot135();
    virtual void Slot136();
    virtual void Slot137();
    virtual void Slot138();
    virtual AlarmInfo* Alarm();
    virtual void Slot140();
    virtual void Slot141();
    virtual void Slot142();
    virtual void Slot143();
    virtual void Slot144();
    virtual void Slot145();
    virtual void Slot146();
    virtual void Slot147();
    virtual void Slot148();
    virtual void Slot149();
    virtual void Slot150();
    virtual void Slot151();
    virtual void Slot152();
    virtual void Slot153();
    virtual void Slot154();
    virtual void Slot155();
    virtual void Slot156();
    virtual void Slot157();
    virtual void Slot158();
    virtual void Slot159();
    virtual void Slot160();
    virtual void Slot161();
    virtual void Reject(CrimeActor*, int);
    virtual void Slot163();
    virtual void Slot164();
    virtual void Slot165();
    virtual void Slot166();
    virtual void Slot167();
    virtual void Slot168();
    virtual void Slot169();
    virtual void Slot170();
    virtual void Slot171();
    virtual void Slot172();
    virtual void Slot173();
    virtual void Slot174();
    virtual void Slot175();
    virtual void Slot176();
    virtual void Slot177();
    virtual void Slot178();
    virtual void Slot179();
    virtual void Slot180();
    virtual void Slot181();
    virtual void Slot182();
    virtual void Slot183();
    virtual void Slot184();
    virtual void Slot185();
    virtual void Slot186();
    virtual void Slot187();
    virtual void Slot188();
    virtual void Slot189();
    virtual void Slot190();
    virtual void Slot191();
    virtual void Slot192();
    virtual void Slot193();
    virtual void Slot194();
    virtual void Slot195();
    virtual void Slot196();
    virtual void Slot197();
    virtual void Slot198();
    virtual void Slot199();
    virtual void Slot200();
    virtual void Slot201();
    virtual void Slot202();
    virtual void Slot203();
    virtual void Slot204();
    virtual void Slot205();
    virtual void Slot206();
    virtual void Accept(CrimeActor*, void*, int, int, int, int, int, int, int, int, int, int, int);
    void FUN_0091ded0(CrimeActor* actor);
};
struct PackageTargetView
{
    int FUN_00680080();
    void* FUN_00680020();
};
struct PackageView
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
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual bool Test(Actor*, int, float, int);
    PackageTargetView* FUN_00671d10();
    int FUN_00672930();
    int FUN_0041ca90();
    int FUN_009611e0();
};
struct RefView
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
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual bool ContainsActor();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual bool IsNPC();
    bool FUN_00440d80();
    bool FUN_00440da0();
    TESBoundObject* FUN_007af430();
    int FUN_00931850();
    int GetCellLoadState();
};
struct AcquireView
{
    void* object;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int kind;
};
struct ListView
{
    int first;
    int next;
    bool FUN_008256d0();
    AcquireView** FUN_006815c0();
    void FUN_00905330(AcquireView* const&);
};
struct ProcessView
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
    virtual void FindTarget(RefView*);
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void SetObject(void*);
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual int GetFlag();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual PackageView* GetAssignedPackage();
    virtual int GetIndex();
    virtual void SetIndex(int);
    virtual void Advance(RefView*, int);
    virtual void slot163();
    virtual void slot164();
    virtual void EndMove(RefView*);
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void slot186();
    virtual void slot187();
    virtual void slot188();
    virtual void slot189();
    virtual void slot190();
    virtual void slot191();
    virtual void slot192();
    virtual void slot193();
    virtual void slot194();
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual void slot198();
    virtual void slot199();
    virtual void slot200();
    virtual void slot201();
    virtual void slot202();
    virtual void slot203();
    virtual void slot204();
    virtual void slot205();
    virtual void slot206();
    virtual void slot207();
    virtual void slot208();
    virtual void slot209();
    virtual void slot210();
    virtual void slot211();
    virtual void slot212();
    virtual void slot213();
    virtual void slot214();
    virtual void slot215();
    virtual void slot216();
    virtual void slot217();
    virtual void slot218();
    virtual void slot219();
    virtual void slot220();
    virtual void slot221();
    virtual void slot222();
    virtual void slot223();
    virtual void slot224();
    virtual void slot225();
    virtual void slot226();
    virtual void slot227();
    virtual void slot228();
    virtual void slot229();
    virtual void slot230();
    virtual void slot231();
    virtual void slot232();
    virtual void slot233();
    virtual void slot234();
    virtual void slot235();
    virtual void slot236();
    virtual void slot237();
    virtual void slot238();
    virtual void slot239();
    virtual void slot240();
    virtual void slot241();
    virtual void slot242();
    virtual void slot243();
    virtual void slot244();
    virtual void slot245();
    virtual void slot246();
    virtual void slot247();
    virtual void slot248();
    virtual void slot249();
    virtual void slot250();
    virtual void slot251();
    virtual void slot252();
    virtual void slot253();
    virtual void slot254();
    virtual void slot255();
    virtual void slot256();
    virtual void slot257();
    virtual void slot258();
    virtual void slot259();
    virtual void slot260();
    virtual void slot261();
    virtual void slot262();
    virtual void slot263();
    virtual void slot264();
    virtual void slot265();
    virtual void slot266();
    virtual void slot267();
    virtual void slot268();
    virtual void slot269();
    virtual void slot270();
    virtual void slot271();
    virtual void slot272();
    virtual void slot273();
    virtual void slot274();
    virtual void slot275();
    virtual void slot276();
    virtual void slot277();
    virtual void slot278();
    virtual void slot279();
    virtual void slot280();
    virtual void slot281();
    virtual void slot282();
    virtual void slot283();
    virtual void slot284();
    virtual void slot285();
    virtual void slot286();
    virtual void slot287();
    virtual void slot288();
    virtual void slot289();
    virtual void slot290();
    virtual void slot291();
    virtual void slot292();
    virtual void slot293();
    virtual void slot294();
    virtual void slot295();
    virtual void slot296();
    virtual void slot297();
    virtual void slot298();
    virtual void slot299();
    virtual void slot300();
    virtual void slot301();
    virtual void slot302();
    virtual void slot303();
    virtual void slot304();
    virtual void slot305();
    virtual void slot306();
    virtual void slot307();
    virtual void slot308();
    virtual void slot309();
    virtual void slot310();
    virtual void slot311();
    virtual void slot312();
    virtual void slot313();
    virtual void slot314();
    virtual void slot315();
    virtual void slot316();
    virtual void slot317();
    virtual void slot318();
    virtual void slot319();
    virtual void slot320();
    virtual void slot321();
    virtual void slot322();
    virtual void slot323();
    virtual void slot324();
    virtual void slot325();
    virtual void slot326();
    virtual void slot327();
    virtual void slot328();
    virtual void slot329();
    virtual void slot330();
    virtual void slot331();
    virtual void slot332();
    virtual void slot333();
    virtual void slot334();
    virtual void slot335();
    virtual void slot336();
    virtual void slot337();
    virtual void slot338();
    virtual void slot339();
    virtual void slot340();
    virtual void slot341();
    virtual void slot342();
    virtual void slot343();
    virtual void slot344();
    virtual void slot345();
    virtual void slot346();
    virtual void slot347();
    virtual void slot348();
    virtual void slot349();
    virtual void slot350();
    virtual void slot351();
    virtual void slot352();
    virtual void slot353();
    virtual void slot354();
    virtual void slot355();
    virtual void slot356();
    virtual void slot357();
    virtual void slot358();
    virtual void slot359();
    virtual void slot360();
    virtual void slot361();
    virtual void slot362();
    virtual void slot363();
    virtual void slot364();
    virtual void slot365();
    virtual void slot366();
    virtual void slot367();
    virtual void slot368();
    virtual void slot369();
    virtual void slot370();
    virtual void slot371();
    virtual void slot372();
    virtual void slot373();
    virtual void slot374();
    virtual void slot375();
    virtual void slot376();
    virtual void slot377();
    virtual void slot378();
    virtual void slot379();
    virtual void slot380();
    virtual void slot381();
    virtual void slot382();
    virtual void slot383();
    virtual void slot384();
    virtual void slot385();
    virtual void slot386();
    virtual void slot387();
    virtual void slot388();
    virtual void slot389();
    virtual void slot390();
    virtual void slot391();
    virtual void slot392();
    virtual void slot393();
    virtual void slot394();
    virtual void slot395();
    virtual void slot396();
    virtual void slot397();
    virtual void slot398();
    virtual void slot399();
    virtual void slot400();
    virtual void slot401();
    virtual void slot402();
    virtual void slot403();
    virtual void slot404();
    virtual void slot405();
    virtual void slot406();
    virtual void slot407();
    virtual void slot408();
    virtual void slot409();
    virtual void slot410();
    virtual void slot411();
    virtual void slot412();
    virtual void slot413();
    virtual void slot414();
    virtual void slot415();
    virtual void slot416();
    virtual void slot417();
    virtual void slot418();
    virtual void slot419();
    virtual void slot420();
    virtual void slot421();
    virtual void slot422();
    virtual void slot423();
    virtual void slot424();
    virtual void slot425();
    virtual void slot426();
    virtual void slot427();
    virtual void slot428();
    virtual void slot429();
    virtual void slot430();
    virtual void slot431();
    virtual void slot432();
    virtual void slot433();
    virtual void slot434();
    virtual void slot435();
    virtual void slot436();
    virtual void slot437();
    virtual void slot438();
    virtual void slot439();
    virtual void slot440();
    virtual void slot441();
    virtual void slot442();
    virtual void slot443();
    virtual void slot444();
    virtual void slot445();
    virtual void slot446();
    virtual void slot447();
    virtual void slot448();
    virtual void slot449();
    virtual void slot450();
    virtual void slot451();
    virtual void slot452();
    virtual void slot453();
    virtual void slot454();
    virtual void slot455();
    virtual void slot456();
    virtual void slot457();
    virtual void slot458();
    virtual void slot459();
    virtual void slot460();
    virtual void slot461();
    virtual void slot462();
    virtual void slot463();
    virtual void slot464();
    virtual void slot465();
    virtual void slot466();
    virtual void slot467();
    virtual void slot468();
    virtual void slot469();
    virtual void slot470();
    virtual void slot471();
    virtual void slot472();
    virtual void slot473();
    virtual void slot474();
    virtual void slot475();
    virtual void slot476();
    virtual void slot477();
    virtual void slot478();
    virtual void slot479();
    virtual void slot480();
    virtual void slot481();
    virtual void slot482();
    virtual void slot483();
    virtual void slot484();
    virtual void slot485();
    virtual void slot486();
    virtual void slot487();
    virtual void slot488();
    virtual void slot489();
    virtual void slot490();
    virtual void slot491();
    virtual void slot492();
    virtual void slot493();
    virtual void slot494();
    virtual void slot495();
    virtual void slot496();
    virtual void slot497();
    virtual void SetTargetMode(RefView*, int);
    virtual void slot499();
    virtual void slot500();
    virtual void slot501();
    virtual void slot502();
    virtual void slot503();
    virtual void slot504();
    virtual void slot505();
    virtual void slot506();
    virtual void slot507();
    virtual void slot508();
    virtual void slot509();
    virtual void slot510();
    virtual void slot511();
    virtual void slot512();
    virtual void slot513();
    virtual void slot514();
    virtual bool Evaluate(RefView*, int);
    virtual void slot516();
    virtual void slot517();
    virtual void slot518();
    virtual void slot519();
    virtual void slot520();
    virtual void slot521();
    virtual void slot522();
    virtual void slot523();
    virtual void HandleOther(RefView*);
    virtual void HandleThree(RefView*);
    virtual void HandleFour(RefView*);
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
    RefView* target;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    ListView queued;
    AcquireView* acquire;
    void FUN_0091f130(RefView* actor);
};
struct P130Anim;
struct P130Ref;
struct P130Node;
struct P130Actor;
struct P130Ref
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
    virtual const char* GetTextValue();
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
    virtual int GetNumericValue();
    bool FUN_00567f80(int, bool);
    void FUN_00568020(int, bool);
    void FUN_00568150(int, bool);
    struct P130Marker* FUN_007af430();
};
struct P130Seq
{
    int FUN_008041a0();
};
struct P130Idle
{
    int FUN_00825c00();
    int FUN_0044ddc0();
};
struct P130IdlePtr
{
    P130Idle* FUN_00559450();
};
struct P130Anim : Animation
{
    bool FUN_00498f80();
    bool IsFlaggedAsTwo();
    void FUN_00498910(bool, bool);
    void FUN_00497ca0(P130Node*, int);
    void CopyGlobalPosition();
    bool FUN_004981f0();
    P130Seq* FUN_00491040(int);
    void FUN_00498230(P130Actor*);
    bool FUN_004985f0();
    void FUN_004974a0();
    void FUN_004994f0(int, bool);
    int FUN_00921e30();
};
struct P130Node
{
    int GetFlagsMasked();
};
struct P130Service
{
    P130Node* FUN_00600950(P130Actor*, TESObjectREFR*);
};
extern P130Service* DAT_011cb6a0;
extern int* DAT_011a3ff0[];
struct P130Controller
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
    virtual void SetState(bool, bool);
};
struct P130Actor
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
    virtual P130Anim* GetAnimation();
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
    virtual void SetMarker(NiPoint3*);
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void SetFurnitureHeading(float);
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
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual bool IsPlayer();
    virtual void v217();
    virtual void v218();
    virtual bool IsDead();
    void SetWantsWeaponOut(int);
    int FUN_008a7570();
    bool HasAnyFlag();
    bool FUN_004997b0();
    void FUN_00884f80();
    void ForwardToVtSlot(int);
    void FUN_008b3ab0();
    void FUN_00895110(float, float);
    void FUN_00931fb0(bool);
    void FUN_008a73e0(int, bool);
    void FUN_00931d30(float);
    P130Controller* FUN_008adcb0();
    void FUN_0088d640();
};
struct P130Marker
{
    int FUN_005094b0();
    float GetFurnitureHeading(int);
    NiPoint3* FUN_006815c0();
    float FUN_00568650();
    void FUN_00c54550(float);
    void FUN_00568ab0(int);
    void FUN_0098ddd0(const NiPoint3*);
};
struct P130Package
{
    int FUN_0041ca90();
    int FUN_009611e0();
};
class HighProcess : public MiddleHighProcess
{
};
void UpdateVisibilityState(int);
bool FUN_005094f0(int);
bool FUN_00509510(int);
void FNV_Warning(const char*, ...);
extern const NiPoint3 pathingrequestZero;
struct P130Process : public MiddleHighProcess
{
    virtual void v493();
    virtual void v494();
    virtual void v495();
    virtual void v496();
    virtual void v497();
    virtual void v498();
    virtual void v499();
    virtual void v500();
    virtual void v501();
    virtual void v502();
    virtual void v503();
    virtual void v504();
    virtual void v505();
    virtual void v506();
    virtual void v507();
    virtual void v508();
    virtual void v509();
    virtual void v510();
    virtual void v511();
    virtual void v512();
    virtual void v513();
    virtual void v514();
    virtual void v515();
    virtual void v516();
    virtual void v517();
    virtual void v518();
    virtual void v519();
    virtual void v520();
    virtual void v521();
    virtual void v522();
    virtual void v523();
    virtual void v524();
    virtual void v525();
    virtual void v526();
    virtual void v527();
    virtual void v528();
    virtual void v529();
    virtual void StartIdle(P130Actor*, int, int);
    bool FUN_009213e0(P130Actor* actor);
};
struct ItemChangeStub;
struct EquipListStub
{
    ItemChangeStub* FindItem(int aiType, int aiUnk);
};
struct ExtraListStub
{
    EquipListStub* GetEquipList();
};
struct ItemChangeStub
{
    TESForm* GetObject();
};
struct RefStub
{
    ExtraListStub* GetExtraList();
    void ResetWeaponModel();
    void SetWeaponForm(TESForm* apForm);
    void Update3DParts();
    void SetAmmoForm(TESForm* apForm);
};
struct ActorStub
{
    void ClearWeaponState(int aiUnk);
};
struct MiddleHighProcess_00924100 : MiddleHighProcess
{
    void ResetWeaponAndAmmo(MobileObject* apRef);
};
struct ResetList
{
    void RemoveAll();
    ~ResetList();
};
struct ResetAnimation
{
    void Reset(MobileObject*);
};
struct LoadResetActor926
{
    void Clear(int);
};
struct ResetPackage
{
    void Clear(int);
};
struct ResetBase
{
    void Reset(unsigned int, MobileObject*);
};
struct ResetLoader
{
    bool IsLoading();
};
extern ResetLoader* g_TESSaveLoadGame;
void ClearEffects(void*, Actor*);
struct LoadResetProcess926
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
    virtual void v160(int, int, int);
    virtual void v164(int);
    virtual void v168(int);
    virtual void v16c(int);
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
    virtual void v218(int);
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
    virtual void v294(Actor*);
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
    virtual void v468();
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
    virtual void v4c0(Actor*, int, int, int);
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
    int f70;
    int f74;
    int f78;
    int f7c;
    int f80;
    int f84;
    int f88;
    int f8c;
    int f90;
    int f94;
    int f98;
    int f9c;
    int fa0;
    float fa4;
    int fa8;
    int fac;
    int fb0;
    int fb4;
    int fb8;
    int fbc;
    int fc0;
    int fc4;
    int fc8;
    int fcc;
    int fd0;
    int fd4;
    float fd8;
    float fdc;
    unsigned char fe0;
    unsigned char fe1;
    unsigned char fe2;
    unsigned char fe3;
    int fe4;
    int fe8;
    int fec;
    int ff0;
    int ff4;
    int ff8;
    int ffc;
    int f100;
    int f104;
    int f108;
    int f10c;
    int f110;
    int f114;
    int f118;
    int f11c;
    int f120;
    unsigned char f124;
    unsigned char f125;
    unsigned char f126;
    unsigned char f127;
    int f128;
    int f12c;
    int f130;
    unsigned char f134;
    unsigned char f135;
    unsigned char f136;
    unsigned char f137;
    int f138;
    int f13c;
    int f140;
    unsigned char f144;
    unsigned char f145;
    unsigned char f146;
    unsigned char f147;
    int f148;
    int f14c;
    int f150;
    int f154;
    int f158;
    int f15c;
    int f160;
    int f164;
    unsigned char f168;
    unsigned char f169;
    unsigned char f16a;
    unsigned char f16b;
    int f16c;
    float f170;
    float f174;
    int f178;
    unsigned char f17c;
    unsigned char f17d;
    unsigned char f17e;
    unsigned char f17f;
    unsigned char f180;
    unsigned char f181;
    unsigned char f182;
    unsigned char f183;
    int f184;
    unsigned char f188;
    unsigned char f189;
    unsigned char f18a;
    unsigned char f18b;
    int f18c;
    int f190;
    int f194;
    int f198;
    int f19c;
    int f1a0;
    int f1a4;
    int f1a8;
    ResetList* f1ac;
    int f1b0;
    int f1b4;
    void* f1b8;
    int f1bc;
    ResetAnimation* f1c0;
    int f1c4;
    int f1c8;
    int f1cc;
    int f1d0;
    int f1d4;
    unsigned char f1d8;
    unsigned char f1d9;
    unsigned char f1da;
    unsigned char f1db;
    int f1dc;
    int f1e0;
    int f1e4;
    int f1e8;
    int f1ec;
    int f1f0;
    int f1f4;
    int f1f8;
    int f1fc;
    int f200;
    int f204;
    int f208;
    int f20c;
    int f210;
    int f214;
    int f218;
    int f21c;
    int f220;
    int f224;
    int f228;
    int f22c;
    int f230;
    int f234;
    int f238;
    int f23c;
    int f240;
    int f244;
    int f248;
    int f24c;
    int f250;
    void FUN_00926000(unsigned int flags, MobileObject* mobile);
};
struct SaveBuffer58;
struct Flag58
{
    unsigned int bits;
    bool FUN_004280f0();
};
struct SaveBuffer58
{
    virtual void v0();
    virtual void v1();
    virtual unsigned int v2();
    void FUN_00865e50(void*, unsigned int, int);
    void FUN_00865df0(void*, int);
    unsigned int FUN_00865f20();
    void FUN_00865ff0(unsigned int, unsigned int);
    Flag58 FUN_00428110(unsigned int);
    unsigned int FUN_0084e3a0();
    void FUN_00865db0(unsigned int, int);
};
struct SavedItem58
{
    void FUN_00913d60(SaveBuffer58*);
};
struct SaveNode58
{
    SavedItem58* item;
    SaveNode58* next;
    SavedItem58** FUN_006815c0();
    SaveNode58* FUN_00726070();
};
struct FormNode58
{
    void* form;
    FormNode58* next;
    void** FUN_006815c0();
    FormNode58* FUN_00726070();
};
struct SavedPart58
{
    void SavePackage(SaveBuffer58*);
    void SaveAnimData(SaveBuffer58*);
    unsigned int FUN_0040a1e0();
    unsigned int RefreshItem();
    unsigned int FUN_00726070();
};
void __cdecl FUN_00806a10(SaveBuffer58*, void*);
struct ProcessSave58
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    FormNode58 list;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned char unk0e0;
    unsigned char unk0e1;
    unsigned char unk0e2;
    unsigned char unk0e3;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned char unk110;
    unsigned char unk111;
    unsigned char unk112;
    unsigned char unk113;
    unsigned int unk114;
    SavedPart58* counter;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned char unk134;
    unsigned char unk135;
    unsigned char unk136;
    unsigned char unk137;
    unsigned int unk138;
    unsigned char unk13c;
    unsigned char unk13d;
    unsigned char unk13e;
    unsigned char unk13f;
    unsigned int unk140;
    unsigned char unk144;
    unsigned char unk145;
    unsigned char unk146;
    unsigned char unk147;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned short unk154;
    unsigned char unk156;
    unsigned char unk157;
    unsigned int unk158;
    unsigned int unk15c;
    SavedPart58* field160;
    SavedPart58* field164;
    unsigned char unk168;
    unsigned char unk169;
    unsigned char unk16a;
    unsigned char unk16b;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned char unk188;
    unsigned char unk189;
    unsigned char unk18a;
    unsigned char unk18b;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned char unk19c;
    unsigned char unk19d;
    unsigned char unk19e;
    unsigned char unk19f;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    SavedPart58* field1bc;
    SavedPart58* field1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned char unk1d8;
    unsigned char unk1d9;
    unsigned char unk1da;
    unsigned char unk1db;
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
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned char unk228;
    unsigned char unk229;
    unsigned short unk22a;
    unsigned int unk22c;
    SaveNode58* savedlist;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    void LoadFromStream(SaveBuffer58*);
    void FUN_00926a20(SaveBuffer58*);
};
struct P124Point
{
    float x, y, z;
    P124Point();
    P124Point operator+(const P124Point&) const;
};
struct P124Matrix
{
    P124Matrix();
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    void FUN_004a0c90(float);
    P124Point FUN_004b4500(const P124Point*);
};
struct P124Marker
{
    P124Point position;
    unsigned short heading;
    unsigned char number, flags;
    P124Point& FUN_006815c0();
    unsigned int FUN_005094b0();
    float FUN_00568650();
    void FUN_00568ab0(unsigned int);
    void FUN_0098ddd0(P124Point*);
    void FUN_00c54550(float);
};
struct P124Base
{
    P124Point FUN_00509920(unsigned int, float);
    float GetFurnitureHeading(unsigned int);
};
struct P124Furniture
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
    virtual void v064();
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
    virtual NiNode* GetNode();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual P124Point* GetPosition();
    P124Base* FUN_007af430();
    P124Matrix FUN_0056fa00();
    const P124Point& FUN_00430830();
};
struct P124Controller
{
    void FUN_005620e0(P124Point*);
};
struct P124Actor
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
    virtual void v064();
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
    virtual void SetPosition(P124Point*);
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void SetAngle(float);
    float FUN_00567400();
    void FUN_00931d30(float);
    P124Controller* FUN_009306d0();
};
struct P124Input
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual P124Actor* GetActor();
};
struct P124Model
{
    P124Marker& FUN_005094d0(unsigned int);
};
P124Model* FUN_00c54400(NiNode*);
void FUN_00806b50(P124Input*, Animation*);
void FUN_00a582f0(const P124Matrix*, P124Point*, bool, P124Point*, P124Point*);
struct P124Package
{
    void FUN_008c6b20(P124Input*);
};
struct P124Process : MiddleHighProcess
{
    void FUN_008d1050(P124Input*);
    void UpdateFurnitureAnimation(P124Input*);
};
struct P124Fallback
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
    virtual void Reset(P124Actor*);
};
struct TimeGlobal
{
    float FUN_0084d030();
};
extern TimeGlobal g_timeGlobal;
class GlobalObject_0044f440
{
  public:
    float* Float();
};
extern GlobalObject_0044f440 g_011c5724;
extern GlobalObject_0044f440 g_011e0474;
extern GlobalObject_0044f440 g_011e048c;
extern GlobalObject_0044f440 g_011e0498;
float FUN_0040ebd0(float, float);
float FUN_00404010(float, float);
struct AimProcess : MiddleHighProcess
{
    void UpdateAimTurn(MobileObject* actor);
};
struct WeapStub
{
    bool IsAutomatic();
    float GetFireRate();
    float GetRateMult(bool);
};
struct WeapEntryStub
{
    WeapStub* GetLoadedForm();
    bool HasModFlag(int);
};
struct AnimStub
{
    float GetSpeedMult();
};
struct TimerStub
{
    float GetMovementDelta();
};
struct SettingStub
{
    float* Float();
};
struct VATSStub
{
    float GetPlayerTimeMult();
    float GetTargetTimeMult();
};
extern TimerStub g_timerStub;
extern SettingStub g_settingStub;
extern VATSStub g_vatsStub;
extern Actor* g_playerStub;
extern Actor* g_vatsTargetStub;
extern double g_zeroStub;
struct AutoFireProcess : MiddleHighProcess
{
    unsigned char UpdateAutoFire(Actor* apActor);
};
struct Actor9;
struct ObjA9;
struct ObjB9;
struct ObjC9;
struct ObjPkg9;
struct Obj309;
class TESObjectCELL;
bool __fastcall FUN_00425fd0(TESObjectCELL*);
struct EP_008c48d0
{
    void* GetEntryPoint();
};
struct Twin_00639b40
{
    char* GetEntryPoint();
};
class TESActorBase;
struct TESTopicInfo
{
    TESActorBase* GetSpeaker();
};
class NiTriBasedGeom;
struct FUN_00559450_h
{
    NiTriBasedGeom* FUN_00559450();
};
struct FUN_0057c6a0Class
{
    void* FUN_00559450();
};
struct Pt9
{
    float x;
    float y;
    float z;
    float FUN_004a7290();
    void FUN_00439ef0();
};
struct RequestLocation9
{
    void* vtable;
    NiPoint3 position;
    void* field10;
    void* field14;
    void* field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
};
struct PathingRequest
{
    virtual ~PathingRequest();
    unsigned int refCount;
    unsigned int field08;
    RequestLocation9 start;
    RequestLocation9 destination;
    NiPoint3 direction;
    float field68, field6c, field70, radius, field78;
    NiPoint3 field7c;
    float field88, field8c, field90;
    void* field94;
    bool field98, field99, field9a, field9b, field9c, field9d, field9e, field9f;
    bool fielda0, fielda1, fielda2, fielda3, fielda4;
    unsigned int fielda8;
    bool fieldac;
    PathingRequest();
    void SetUseSoft(bool);
};
struct Field1909
{
    void* FUN_006838b0();
    bool HasPathingSolution();
};
struct Obj309
{
    unsigned int FUN_00441110();
    ObjC9* FUN_006dd4f0();
    NiPoint3 FUN_005c3420();
};
struct Obj309Ref
{
    Obj309* FUN_006a9540();
};
struct GlobalObject_00633c90
{
    void* p;
    GlobalObject_00633c90(int);
    ~GlobalObject_00633c90();
    Obj309Ref* FUN_00559450();
};
struct ObjC9 : TESObjectREFR
{
    void* FUN_00575d70();
    ObjC9* FUN_008d6f30();
    float FUN_005723b0(void*, int, int);
    bool FUN_00425fd0();
};
struct ObjPkg9
{
    unsigned int FUN_00676280(Actor9*);
};
struct ObjB9
{
    unsigned int FUN_00676280(Actor9*);
    int FUN_0055b980();
    void* FUN_00675a50(Actor9*);
    void* FUN_00675c20(Actor9*);
    NiPoint3 FUN_00675de0(Actor9*);
};
struct ObjA9
{
    void* m_00;
    int m_04;
    bool FUN_009f56b0(Actor9*, float);
    void* FUN_00639b40();
    ObjC9* FUN_0044edb0();
    void ClearTargetReferences(Actor9*, ObjB9*);
    void SelectSandboxActivity(Actor9*, ObjB9*);
    bool FUN_009f4300(Actor9*, int);
    bool FUN_009f43c0(Actor9*);
    bool FUN_009f3c10();
    void FUN_009f3af0(Actor9*, int);
    unsigned int FUN_0044ddc0();
};
struct Actor9 : Actor
{
    bool FUN_008b3bd0();
    void PathToLocation(PathingRequest*, NiPoint3 const&, void*, void*, float, int);
    void SetPathingRequestAvoidNodes(PathingRequest*);
    void FUN_008b3d30();
};
ObjC9* FUN_0044edb0(ObjA9*);
bool __cdecl FUN_0092a980(int);
float __cdecl FUN_00404010(float, float);
float __cdecl FUN_006e25d0();
bool __cdecl HasPathingSolution(void*);
extern float DAT_010231d0;
extern float DAT_01012054;
extern double DAT_01012060;
struct Proc9 : MiddleHighProcess
{
    virtual void v493();
    virtual void v494();
    virtual void vt7bc(Actor9*, void*);
    virtual void v496();
    virtual void v497();
    virtual void v498();
    virtual void v499();
    virtual void v500();
    virtual void v501();
    virtual void v502();
    virtual void v503();
    virtual void v504();
    virtual void v505();
    virtual void v506();
    virtual void v507();
    virtual void v508();
    virtual void v509();
    virtual void v510();
    virtual void v511();
    virtual void v512();
    virtual void v513();
    virtual void v514();
    virtual void v515();
    virtual void v516();
    virtual void v517();
    virtual void v518();
    virtual void v519();
    virtual void v520();
    virtual void v521();
    virtual void v522();
    virtual void v523();
    virtual void v524();
    virtual void v525();
    virtual void v526();
    virtual void v527();
    virtual void v528();
    virtual bool vt844(Actor9*, void*);
    virtual void v530();
    virtual void vt84c(Actor9*, int, float);
    virtual bool vt850(Actor9*, void*);
    virtual void v533();
    virtual void v534();
    virtual void v535();
    virtual void v536();
    virtual void v537();
    virtual void vt868(Actor9*, void*);
    ObjA9* FUN_008d0430();
    void UpdatePackageState(Actor9* arg);
};
struct FurnitureReference : TESObjectREFR
{
    bool FUN_00568680();
};
struct FurnitureBase
{
    bool FUN_005093f0();
};
struct FurnitureMarkerAccess
{
    void FUN_00c54550(float);
    void FUN_00568ab0(int);
    void FUN_0098ddd0(void*);
};
struct SleepController
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void FlushUsageData();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual bool IsActive();
    virtual void SetActive(bool, bool);
};
struct FurnitureActorAccess
{
    SleepController* FUN_008adcb0();
};
struct FurnitureProcess : MiddleHighProcess
{
    virtual void unused493();
    virtual void unused494();
    virtual void unused495();
    virtual void unused496();
    virtual void unused497();
    virtual void BeginFurniture(Actor*, int);
    void FUN_0092c680();
    bool TryUseFurniture(Actor* actor, TESObjectREFR* furniture);
};
struct B570TargetData
{
    int unk00;
    int unk04;
    float elapsed;
    TESObjectREFR* FUN_009f3390();
    bool AdvancePatrolIndex(int);
};
struct B570ActorCalls : Actor
{
    bool FUN_008b3bb0();
    bool IsNodeKindSupported();
};
struct B570FormCalls
{
    int FUN_00401170();
};
struct B570PatrolData
{
    float FUN_006a7f50();
};
struct B570ExtraCalls
{
    B570PatrolData* FUN_0041fe90();
};
struct B570RefCalls : TESObjectREFR
{
    B570ExtraCalls* FUN_005d43c0();
};
struct B570PackageCalls
{
    unsigned int FUN_00676280(Actor*);
};
struct B570PointCalls : NiPoint3
{
    float GetSquaredXYLength() const;
};
struct B570TimeCalls
{
    float FUN_0084d030();
};
extern B570TimeCalls DAT_011f6394;
extern TESBoundObject* DAT_011ca248;
float FUN_006e25d0();
float FUN_00404010(float, float);
double FUN_00408860(float);
struct B570ProcessCalls : MiddleHighProcess
{
    virtual void unknown493();
    virtual void unknown494();
    virtual void unknown495();
    virtual void unknown496();
    virtual void unknown497();
    virtual void unknown498();
    virtual void unknown499();
    virtual void unknown500();
    virtual void unknown501();
    virtual void unknown502();
    virtual void unknown503();
    virtual void unknown504();
    virtual void unknown505();
    virtual void unknown506();
    virtual void unknown507();
    virtual void unknown508();
    virtual void unknown509();
    virtual void unknown510();
    virtual void unknown511();
    virtual void unknown512();
    virtual void unknown513();
    virtual void unknown514();
    virtual void unknown515();
    virtual void unknown516();
    virtual void unknown517();
    virtual void unknown518();
    virtual void unknown519();
    virtual void unknown520();
    virtual void unknown521();
    virtual void unknown522();
    virtual void unknown523();
    virtual void unknown524();
    virtual void unknown525();
    virtual void unknown526();
    virtual void unknown527();
    virtual void unknown528();
    virtual void unknown529();
    virtual void unknown530();
    virtual void unknown531();
    virtual void unknown532();
    virtual void unknown533();
    virtual void FinishTarget(Actor*, B570TargetData*);
    virtual void unknown535();
    virtual void unknown536();
    virtual void unknown537();
    virtual void UpdateActiveEffects(Actor*, TESObjectREFR*);
    void UpdateTargetTracking(B570ActorCalls* actor, B570TargetData* data);
};
struct WeaponObjStub
{
    bool IsWeaponFlag();
    int GetWeaponSkillIndex();
};
struct InventoryStackRecord
{
    WeaponObjStub* GetWeaponObj();
    float GetWeaponConditionHealth(bool abBase);
};
float RoundScaledValue(float afValue);
struct MHP_0092b9e0_Owner : MiddleHighProcess
{
    int FUN_0092b9e0(Actor* apActor);
};
struct ArmorForm : TESForm
{
    int FUN_00401170();
};
struct TESBipedModelForm
{
    bool FUN_00480d30();
    bool IsPowerArmor();
    bool FUN_00480af0(int, bool, bool);
    bool GetIsHeavyArmor() const;
};
struct TESObjectARMO : ArmorForm
{
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
    TESBipedModelForm bipedModel;
};
struct InventoryItem
{
    ArmorForm* GetObject();
    bool FUN_004bddd0(bool);
};
class InventoryChanges
{
  public:
    BSSimpleList<InventoryItem*>* items;
    static InventoryChanges* GetOrAddInventoryChanges(TESObjectREFR*);
};
struct ArmorActor : Actor
{
    Animation* FUN_008b70d0();
    BipedAnim* FUN_005d9f90();
};
struct ArmorProcess : MiddleHighProcess
{
    void UpdatePowerArmorState(ArmorActor* actor);
};
namespace ProcessActivate {

struct ActPoint
{
    float x, y, z;
    ActPoint FUN_00439ef0(const ActPoint& arOther) const;
    float FUN_00457990() const;
};

struct ActActor
{
    virtual void a000();
    virtual void a001();
    virtual void a002();
    virtual void a003();
    virtual void a004();
    virtual void a005();
    virtual void a006();
    virtual void a007();
    virtual void a008();
    virtual void a009();
    virtual void a00a();
    virtual void a00b();
    virtual void a00c();
    virtual void a00d();
    virtual void a00e();
    virtual void a00f();
    virtual void a010();
    virtual void a011();
    virtual void a012();
    virtual void a013();
    virtual void a014();
    virtual void a015();
    virtual void a016();
    virtual void a017();
    virtual void a018();
    virtual void a019();
    virtual void a01a();
    virtual void a01b();
    virtual void a01c();
    virtual void a01d();
    virtual void a01e();
    virtual void a01f();
    virtual void a020();
    virtual void a021();
    virtual void a022();
    virtual void a023();
    virtual void a024();
    virtual void a025();
    virtual void a026();
    virtual void a027();
    virtual void a028();
    virtual void a029();
    virtual void a02a();
    virtual void a02b();
    virtual void a02c();
    virtual void a02d();
    virtual void a02e();
    virtual void a02f();
    virtual void a030();
    virtual void a031();
    virtual void a032();
    virtual void a033();
    virtual void a034();
    virtual void a035();
    virtual void a036();
    virtual void a037();
    virtual void a038();
    virtual void a039();
    virtual void a03a();
    virtual void a03b();
    virtual void a03c();
    virtual void a03d();
    virtual void a03e();
    virtual void a03f();
    virtual void a040();
    virtual void a041();
    virtual void a042();
    virtual void a043();
    virtual void a044();
    virtual void a045();
    virtual void a046();
    virtual void a047();
    virtual void a048();
    virtual void a049();
    virtual void a04a();
    virtual void a04b();
    virtual void a04c();
    virtual void a04d();
    virtual void a04e();
    virtual void a04f();
    virtual void a050();
    virtual void a051();
    virtual void a052();
    virtual void a053();
    virtual void a054();
    virtual void a055();
    virtual void a056();
    virtual void a057();
    virtual void a058();
    virtual void a059();
    virtual void a05a();
    virtual void a05b();
    virtual void a05c();
    virtual void a05d();
    virtual void a05e();
    virtual void a05f();
    virtual void a060();
    virtual void a061();
    virtual void a062();
    virtual void a063();
    virtual void a064();
    virtual void a065();
    virtual void a066();
    virtual void a067();
    virtual void a068();
    virtual void a069();
    virtual void a06a();
    virtual void a06b();
    virtual void a06c();
    virtual void a06d();
    virtual void a06e();
    virtual void a06f();
    virtual void a070();
    virtual void a071();
    virtual void a072();
    virtual void a073();
    virtual void a074();
    virtual void a075();
    virtual void a076();
    virtual void a077();
    virtual void a078();
    virtual void a079();
    virtual void a07a();
    virtual void a07b();
    virtual void a07c();
    virtual ActPoint* GetPos();
    virtual void a07e();
    virtual void a07f();
    virtual void a080();
    virtual void a081();
    virtual void a082();
    virtual void a083();
    virtual void a084();
    virtual int FUN_vt214();
    virtual void a086();
    virtual void a087();
    virtual void a088();
    virtual void a089();
    virtual void a08a();
    virtual void a08b();
    virtual void a08c();
    virtual void a08d();
    virtual void a08e();
    virtual void a08f();
    virtual void a090();
    virtual void a091();
    virtual void a092();
    virtual void a093();
    virtual void a094();
    virtual void a095();
    virtual void a096();
    virtual void a097();
    virtual void a098();
    virtual void a099();
    virtual void a09a();
    virtual void a09b();
    virtual void a09c();
    virtual void a09d();
    virtual void a09e();
    virtual void a09f();
    virtual void a0a0();
    virtual void a0a1();
    virtual void FUN_vt288();
    virtual void a0a3();
    virtual void a0a4();
    virtual void a0a5();
    virtual void a0a6();
    virtual void a0a7();
    virtual void a0a8();
    virtual void a0a9();
    virtual void a0aa();
    virtual void a0ab();
    virtual void a0ac();
    virtual void a0ad();
    virtual void a0ae();
    virtual void a0af();
    virtual void a0b0();
    virtual void a0b1();
    virtual void a0b2();
    virtual void a0b3();
    virtual void a0b4();
    virtual void a0b5();
    virtual void a0b6();
    virtual void a0b7();
    virtual void a0b8();
    virtual void a0b9();
    virtual void a0ba();
    virtual void a0bb();
    virtual void a0bc();
    virtual void a0bd();
    virtual void a0be();
    virtual void a0bf();
    virtual void a0c0();
    virtual void a0c1();
    virtual void a0c2();
    virtual void a0c3();
    virtual void a0c4();
    virtual void a0c5();
    virtual void a0c6();
    virtual void a0c7();
    virtual void a0c8();
    virtual void a0c9();
    virtual void a0ca();
    virtual void a0cb();
    virtual void a0cc();
    virtual void a0cd();
    virtual void a0ce();
    virtual void a0cf();
    virtual void a0d0();
    virtual void a0d1();
    virtual void a0d2();
    virtual void a0d3();
    virtual void a0d4();
    virtual void a0d5();
    virtual void a0d6();
    virtual void a0d7();
    virtual void a0d8();
    virtual void a0d9();
    virtual void a0da();
    virtual void a0db();
    virtual void a0dc();
    virtual void a0dd();
    virtual void a0de();
    virtual void a0df();
    virtual void a0e0();
    virtual void a0e1();
    virtual void a0e2();
    virtual void a0e3();
    virtual void a0e4();
    virtual void a0e5();
    virtual void a0e6();
    virtual void a0e7();
    virtual void a0e8();
    virtual void a0e9();
    virtual void a0ea();
    virtual void a0eb();
    virtual void a0ec();
    virtual void a0ed();
    virtual void a0ee();
    virtual void a0ef();
    virtual void a0f0();
    virtual void a0f1();
    virtual void a0f2();
    virtual void a0f3();
    virtual void a0f4();
    virtual void a0f5();
    virtual void a0f6();
    virtual void a0f7();
    virtual void a0f8();
    virtual void a0f9();
    virtual void a0fa();
    virtual void a0fb();
    virtual void a0fc();
    virtual void a0fd();
    virtual void a0fe();
    virtual void a0ff();
    virtual void a100();
    virtual void a101();
    virtual void a102();
    virtual void a103();
    virtual void a104();
    virtual void a105();
    virtual void FUN_vt418();
    bool FUN_008b3bb0();
    int FUN_00931850();
    int GetCellLoadState();
};

struct ActRef
{
    virtual void r000();
    virtual void r001();
    virtual void r002();
    virtual void r003();
    virtual void r004();
    virtual void r005();
    virtual void r006();
    virtual void r007();
    virtual void r008();
    virtual void r009();
    virtual void r00a();
    virtual void r00b();
    virtual void r00c();
    virtual void r00d();
    virtual void r00e();
    virtual void r00f();
    virtual void r010();
    virtual void r011();
    virtual void r012();
    virtual void r013();
    virtual void r014();
    virtual void r015();
    virtual void r016();
    virtual void r017();
    virtual void r018();
    virtual void r019();
    virtual void r01a();
    virtual void r01b();
    virtual void r01c();
    virtual void r01d();
    virtual void r01e();
    virtual void r01f();
    virtual void r020();
    virtual void r021();
    virtual void r022();
    virtual void r023();
    virtual void r024();
    virtual void r025();
    virtual void r026();
    virtual void r027();
    virtual void r028();
    virtual void r029();
    virtual void r02a();
    virtual void r02b();
    virtual void r02c();
    virtual void r02d();
    virtual void r02e();
    virtual void r02f();
    virtual void r030();
    virtual void r031();
    virtual void r032();
    virtual void r033();
    virtual void r034();
    virtual void r035();
    virtual void r036();
    virtual void r037();
    virtual void r038();
    virtual void r039();
    virtual void r03a();
    virtual void r03b();
    virtual void r03c();
    virtual void r03d();
    virtual void r03e();
    virtual void r03f();
    virtual bool IsActor();
    virtual void r041();
    virtual void r042();
    virtual void r043();
    virtual void r044();
    virtual void r045();
    virtual void r046();
    virtual void r047();
    virtual void r048();
    virtual void r049();
    virtual void r04a();
    virtual void r04b();
    virtual void r04c();
    virtual void r04d();
    virtual void r04e();
    virtual void r04f();
    virtual void r050();
    virtual void r051();
    virtual void r052();
    virtual void r053();
    virtual void r054();
    virtual void r055();
    virtual void r056();
    virtual void r057();
    virtual void r058();
    virtual void r059();
    virtual void r05a();
    virtual void r05b();
    virtual void r05c();
    virtual void r05d();
    virtual void r05e();
    virtual void r05f();
    virtual void r060();
    virtual void r061();
    virtual void r062();
    virtual void r063();
    virtual void r064();
    virtual void r065();
    virtual void r066();
    virtual void r067();
    virtual void r068();
    virtual void r069();
    virtual void r06a();
    virtual void r06b();
    virtual void r06c();
    virtual void r06d();
    virtual void r06e();
    virtual void r06f();
    virtual void r070();
    virtual void r071();
    virtual void r072();
    virtual void r073();
    virtual void r074();
    virtual void r075();
    virtual void r076();
    virtual void r077();
    virtual void r078();
    virtual void r079();
    virtual void r07a();
    virtual void r07b();
    virtual void r07c();
    virtual ActPoint* GetPos();
    bool FUN_00440d80();
    void* FUN_007af430();
    bool FUN_00568680();
    void* FUN_00568e50();
    ActPoint* FUN_00568fa0();
    bool FUN_00567f80(unsigned char aucMarker, int aiFlags);
    void* FUN_008d6f30();
    void* FUN_00575d70();
    bool FUN_005686b0(ActPoint* apPos, int a2, int a3, ActPoint* apOut, int* apMarker, int a6);
    bool Activate(ActActor* apActor, int aiActivate, void* apItem, int a4);
    void FUN_00565870();
};

struct ActPackage
{
    virtual void k000();
    virtual void k001();
    virtual void k002();
    virtual void k003();
    virtual void k004();
    virtual void k005();
    virtual void k006();
    virtual void k007();
    virtual void k008();
    virtual void k009();
    virtual void k00a();
    virtual void k00b();
    virtual void k00c();
    virtual void k00d();
    virtual void k00e();
    virtual void k00f();
    virtual void k010();
    virtual void k011();
    virtual void k012();
    virtual void k013();
    virtual void k014();
    virtual void k015();
    virtual void k016();
    virtual void k017();
    virtual void k018();
    virtual void k019();
    virtual void k01a();
    virtual void k01b();
    virtual void k01c();
    virtual void k01d();
    virtual void k01e();
    virtual void k01f();
    virtual void k020();
    virtual void k021();
    virtual void k022();
    virtual void k023();
    virtual void k024();
    virtual void k025();
    virtual void k026();
    virtual void k027();
    virtual void k028();
    virtual void k029();
    virtual void k02a();
    virtual void k02b();
    virtual void k02c();
    virtual void k02d();
    virtual void k02e();
    virtual void k02f();
    virtual void k030();
    virtual void k031();
    virtual void k032();
    virtual void k033();
    virtual void k034();
    virtual void k035();
    virtual void k036();
    virtual void k037();
    virtual void k038();
    virtual void k039();
    virtual void k03a();
    virtual void k03b();
    virtual void k03c();
    virtual void k03d();
    virtual void k03e();
    virtual void k03f();
    virtual void k040();
    virtual void k041();
    virtual void k042();
    virtual void k043();
    virtual void k044();
    virtual void k045();
    virtual void k046();
    virtual void k047();
    virtual void k048();
    virtual void k049();
    virtual void k04a();
    virtual void k04b();
    virtual void k04c();
    virtual void k04d();
    virtual void k04e();
    virtual void k04f();
    virtual void k050();
    virtual bool FUN_vt144(ActActor* apActor, int aiFlags);
    virtual bool FUN_vt148(ActActor* apActor, int aiDistance);
    ActRef* FUN_00676140(ActActor* apActor);
    int FUN_0041ca90();
    bool FUN_0067efd0();
};

struct ActAcquire
{
    ActRef* pObject;
    void* pItem;
    ~ActAcquire();
};

struct ActIntSetting
{
    int* FUN_0043d4d0();
};
extern ActIntSetting DAT_011cde98;

struct ActCalendar
{
    float FUN_00867da0();
};
extern ActCalendar DAT_011de7b8;

struct ActGlobal
{
    float FUN_00526ac0();
};

extern void* DAT_011ca248;
extern void* DAT_011ca244;
ActGlobal* __cdecl LookupFormByID(unsigned int auiFormID);

struct ActProcess
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
    virtual void p00a();
    virtual void p00b();
    virtual void p00c();
    virtual void p00d();
    virtual void p00e();
    virtual void p00f();
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
    virtual void p01a();
    virtual void p01b();
    virtual void p01c();
    virtual void p01d();
    virtual void p01e();
    virtual void p01f();
    virtual void p020();
    virtual void FUN_vt84(ActActor* apActor);
    virtual void p022();
    virtual bool FindPackageTarget(ActActor* apActor);
    virtual void p024();
    virtual void p025();
    virtual void p026();
    virtual void p027();
    virtual void p028();
    virtual void p029();
    virtual void p02a();
    virtual void p02b();
    virtual void p02c();
    virtual void p02d();
    virtual void p02e();
    virtual void p02f();
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
    virtual void p03a();
    virtual void p03b();
    virtual void p03c();
    virtual void p03d();
    virtual void p03e();
    virtual void p03f();
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
    virtual void p04a();
    virtual void FUN_vt12c(int aiValue);
    virtual void p04c();
    virtual void p04d();
    virtual void p04e();
    virtual void p04f();
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
    virtual void p05a();
    virtual void p05b();
    virtual void p05c();
    virtual void p05d();
    virtual void p05e();
    virtual void p05f();
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
    virtual void p06a();
    virtual void p06b();
    virtual void p06c();
    virtual void p06d();
    virtual void p06e();
    virtual void p06f();
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
    virtual void p07a();
    virtual void p07b();
    virtual void p07c();
    virtual void p07d();
    virtual void p07e();
    virtual void p07f();
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
    virtual void p08a();
    virtual ActPackage* GetCurrentPackage();
    virtual void p08c();
    virtual void p08d();
    virtual void p08e();
    virtual void p08f();
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
    virtual void p09a();
    virtual void p09b();
    virtual void p09c();
    virtual void p09d();
    virtual void p09e();
    virtual ActPackage* FUN_vt27c();
    virtual void p0a0();
    virtual void p0a1();
    virtual void SetProcessTarget(ActActor* apActor, int aiIndex);
    virtual void p0a3();
    virtual void p0a4();
    virtual void FUN_vt294(ActActor* apActor);
    virtual void p0a6();
    virtual void p0a7();
    virtual void p0a8();
    virtual void p0a9();
    virtual void p0aa();
    virtual void p0ab();
    virtual void p0ac();
    virtual void p0ad();
    virtual void p0ae();
    virtual void p0af();
    virtual void p0b0();
    virtual void p0b1();
    virtual void p0b2();
    virtual void p0b3();
    virtual void p0b4();
    virtual void p0b5();
    virtual void p0b6();
    virtual void p0b7();
    virtual void p0b8();
    virtual void p0b9();
    virtual void p0ba();
    virtual void p0bb();
    virtual void p0bc();
    virtual void p0bd();
    virtual void p0be();
    virtual void p0bf();
    virtual void p0c0();
    virtual void p0c1();
    virtual void p0c2();
    virtual void p0c3();
    virtual void p0c4();
    virtual void p0c5();
    virtual void p0c6();
    virtual void p0c7();
    virtual void p0c8();
    virtual void p0c9();
    virtual void p0ca();
    virtual void p0cb();
    virtual void p0cc();
    virtual void p0cd();
    virtual void p0ce();
    virtual void p0cf();
    virtual void p0d0();
    virtual void p0d1();
    virtual void p0d2();
    virtual void p0d3();
    virtual void p0d4();
    virtual void p0d5();
    virtual void p0d6();
    virtual void p0d7();
    virtual void p0d8();
    virtual void p0d9();
    virtual void p0da();
    virtual void p0db();
    virtual void p0dc();
    virtual void p0dd();
    virtual void p0de();
    virtual void p0df();
    virtual void p0e0();
    virtual void p0e1();
    virtual void p0e2();
    virtual void p0e3();
    virtual void p0e4();
    virtual void p0e5();
    virtual void p0e6();
    virtual void p0e7();
    virtual void p0e8();
    virtual void p0e9();
    virtual void p0ea();
    virtual void p0eb();
    virtual void p0ec();
    virtual void p0ed();
    virtual void p0ee();
    virtual void p0ef();
    virtual void p0f0();
    virtual void p0f1();
    virtual void p0f2();
    virtual void p0f3();
    virtual void p0f4();
    virtual void p0f5();
    virtual void p0f6();
    virtual void p0f7();
    virtual void p0f8();
    virtual void p0f9();
    virtual void p0fa();
    virtual void p0fb();
    virtual void p0fc();
    virtual void p0fd();
    virtual void p0fe();
    virtual void p0ff();
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
    virtual void p10a();
    virtual void p10b();
    virtual void p10c();
    virtual void p10d();
    virtual void p10e();
    virtual void p10f();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual void p116();
    virtual void p117();
    virtual void p118();
    virtual void p119();
    virtual void p11a();
    virtual void p11b();
    virtual void p11c();
    virtual void p11d();
    virtual void p11e();
    virtual void p11f();
    virtual void p120();
    virtual void p121();
    virtual void p122();
    virtual void p123();
    virtual void p124();
    virtual void p125();
    virtual void p126();
    virtual void p127();
    virtual void p128();
    virtual void p129();
    virtual void p12a();
    virtual void p12b();
    virtual void p12c();
    virtual void p12d();
    virtual void p12e();
    virtual void p12f();
    virtual void p130();
    virtual void p131();
    virtual void p132();
    virtual void p133();
    virtual void p134();
    virtual void p135();
    virtual void p136();
    virtual void p137();
    virtual void p138();
    virtual void p139();
    virtual void p13a();
    virtual void FUN_vt4ec(int aiValue);
    virtual void p13c();
    virtual void p13d();
    virtual void p13e();
    virtual void p13f();
    virtual void p140();
    virtual void p141();
    virtual void p142();
    virtual void p143();
    virtual void p144();
    virtual void p145();
    virtual void p146();
    virtual void p147();
    virtual void p148();
    virtual void p149();
    virtual void p14a();
    virtual void p14b();
    virtual void p14c();
    virtual void p14d();
    virtual void p14e();
    virtual void p14f();
    virtual void p150();
    virtual void p151();
    virtual void p152();
    virtual void p153();
    virtual void p154();
    virtual void p155();
    virtual void p156();
    virtual void p157();
    virtual void p158();
    virtual void p159();
    virtual void p15a();
    virtual void p15b();
    virtual void p15c();
    virtual void p15d();
    virtual void p15e();
    virtual void p15f();
    virtual void p160();
    virtual void p161();
    virtual void p162();
    virtual void p163();
    virtual void p164();
    virtual void p165();
    virtual void p166();
    virtual void p167();
    virtual void p168();
    virtual void p169();
    virtual void p16a();
    virtual void p16b();
    virtual void p16c();
    virtual void p16d();
    virtual void p16e();
    virtual void p16f();
    virtual void p170();
    virtual void p171();
    virtual void p172();
    virtual void p173();
    virtual void p174();
    virtual void p175();
    virtual void p176();
    virtual void p177();
    virtual void p178();
    virtual void p179();
    virtual void p17a();
    virtual void p17b();
    virtual void p17c();
    virtual void p17d();
    virtual void p17e();
    virtual void p17f();
    virtual void p180();
    virtual void p181();
    virtual void p182();
    virtual void p183();
    virtual void p184();
    virtual void p185();
    virtual void p186();
    virtual void p187();
    virtual void p188();
    virtual void p189();
    virtual void FUN_vt628(ActRef* apRef);
    virtual void p18b();
    virtual void p18c();
    virtual void p18d();
    virtual void p18e();
    virtual void p18f();
    virtual void p190();
    virtual void p191();
    virtual void p192();
    virtual void p193();
    virtual void p194();
    virtual void p195();
    virtual void p196();
    virtual void p197();
    virtual void p198();
    virtual void p199();
    virtual void p19a();
    virtual void p19b();
    virtual void p19c();
    virtual void p19d();
    virtual void p19e();
    virtual void p19f();
    virtual void p1a0();
    virtual void p1a1();
    virtual void p1a2();
    virtual void p1a3();
    virtual void p1a4();
    virtual void p1a5();
    virtual void p1a6();
    virtual void p1a7();
    virtual void p1a8();
    virtual void p1a9();
    virtual void p1aa();
    virtual void p1ab();
    virtual void p1ac();
    virtual void p1ad();
    virtual void p1ae();
    virtual void p1af();
    virtual void p1b0();
    virtual void p1b1();
    virtual void p1b2();
    virtual void p1b3();
    virtual void p1b4();
    virtual void p1b5();
    virtual void p1b6();
    virtual void p1b7();
    virtual void p1b8();
    virtual void p1b9();
    virtual void p1ba();
    virtual void p1bb();
    virtual void p1bc();
    virtual void p1bd();
    virtual void p1be();
    virtual void p1bf();
    virtual void p1c0();
    virtual void p1c1();
    virtual void p1c2();
    virtual void p1c3();
    virtual void p1c4();
    virtual void p1c5();
    virtual void p1c6();
    virtual void p1c7();
    virtual void p1c8();
    virtual void p1c9();
    virtual void p1ca();
    virtual void p1cb();
    virtual void p1cc();
    virtual void p1cd();
    virtual void p1ce();
    virtual void p1cf();
    virtual void p1d0();
    virtual void p1d1();
    virtual void p1d2();
    virtual void p1d3();
    virtual void p1d4();
    virtual void p1d5();
    virtual void p1d6();
    virtual void p1d7();
    virtual void p1d8();
    virtual void p1d9();
    virtual void p1da();
    virtual void p1db();
    virtual void p1dc();
    virtual void p1dd();
    virtual void p1de();
    virtual void p1df();
    virtual void p1e0();
    virtual void p1e1();
    virtual void p1e2();
    virtual void p1e3();
    virtual void p1e4();
    virtual void p1e5();
    virtual void p1e6();
    virtual void p1e7();
    virtual void p1e8();
    virtual void p1e9();
    virtual void p1ea();
    virtual void p1eb();
    virtual void p1ec();
    virtual void p1ed();
    virtual void p1ee();
    virtual void p1ef();
    virtual void p1f0();
    virtual void p1f1();
    virtual void p1f2();
    virtual void p1f3();
    virtual void p1f4();
    virtual void p1f5();
    virtual void p1f6();
    virtual void p1f7();
    virtual void p1f8();
    virtual void p1f9();
    virtual void p1fa();
    virtual void p1fb();
    virtual void p1fc();
    virtual void p1fd();
    virtual void p1fe();
    virtual void p1ff();
    virtual void p200();
    virtual void p201();
    virtual void p202();
    virtual void p203();
    virtual void p204();
    virtual void p205();
    virtual void p206();
    virtual void p207();
    virtual void p208();
    virtual bool FUN_vt824(ActActor* apActor, ActPoint kPos, void* apCell, void* apWorld);
    char pad04[0x3c];
    ActRef* pTarget;
    int iTargetState;
    char pad48[0x1c];
    ActAcquire* m_pDetectionData60;
    char pad68[0xdc];
    unsigned char ucMarker;
    char pad145[3];
    ActPoint kMarkerPos;
    char pad154[0xd6];
    short sActivated;

    float FUN_007df1f0();
    bool FUN_00915ef0(ActActor* apActor);
    void UpdateFurnitureAlignment(ActActor* apActor);
    bool FUN_00915f10(ActActor* apActor, bool abActivate);
};

// @fnv 0x00915f10
bool ActProcess::FUN_00915f10(ActActor* apActor, bool abActivate)
{
    ActPackage* pPackage = 0;
    pPackage = FUN_vt27c();
    if (pTarget == 0 || pTarget->FUN_00440d80())
        FindPackageTarget(apActor);
    if (pTarget == 0)
    {
        SetProcessTarget(apActor, 1);
    }
    else
    {
        ActRef* pRef = pPackage->FUN_00676140(apActor);
        if (pRef && pRef->FUN_00568680() &&
            (pTarget->FUN_007af430() == DAT_011ca248 || pTarget->FUN_007af430() == DAT_011ca244))
        {
            FUN_vt628(pRef);
            return true;
        }
        if (pPackage->FUN_0041ca90() == 9 && !pPackage->FUN_vt148(apActor, 300))
            SetProcessTarget(apActor, -1);
        void* pFurniture = pTarget->FUN_00568e50();
        bool bDoneEntry = false;
        if (pFurniture)
        {
            ActPoint kDelta = pTarget->FUN_00568fa0()->FUN_00439ef0(*apActor->GetPos());
            if (kDelta.FUN_00457990() <= *DAT_011cde98.FUN_0043d4d0())
                bDoneEntry = true;
        }
        else if (pTarget->FUN_00568680() && apActor->FUN_vt214())
        {
            bDoneEntry = true;
        }
        else if (pTarget->FUN_00568680() && !apActor->FUN_vt214() && pTarget->FUN_00567f80(ucMarker, 1) &&
                 !apActor->FUN_008b3bb0())
        {
            FUN_vt84(apActor);
            FUN_vt294(apActor);
            FUN_vt12c(0);
            return false;
        }
        else
        {
            bDoneEntry = pPackage->FUN_vt144(apActor, 0);
        }

        if (!bDoneEntry && !FUN_00915ef0(apActor))
        {
            if (apActor->FUN_vt214() == 4 || apActor->FUN_vt214() == 9)
            {
                apActor->FUN_vt418();
                return true;
            }
            if (apActor->FUN_008b3bb0())
            {
                void* pSitTarget = pTarget->FUN_00568e50();
                if (pSitTarget == 0)
                {
                    if (!FUN_vt824(apActor, *pTarget->GetPos(), pTarget->FUN_008d6f30(), pTarget->FUN_00575d70()))
                        return false;
                }
                else if (pTarget->FUN_00568680())
                {
                    ActPoint kActorPos = *apActor->GetPos();
                    int iMarkerTmp = 0;
                    if (pTarget->FUN_005686b0(&kActorPos, 1, 1, &kMarkerPos, &iMarkerTmp, 1))
                    {
                        if (!FUN_vt824(apActor, kMarkerPos, pTarget->FUN_008d6f30(), pTarget->FUN_00575d70()))
                            return false;
                        ucMarker = iMarkerTmp;
                    }
                    else
                    {
                        FUN_vt84(apActor);
                        FUN_vt294(apActor);
                        FUN_vt12c(0);
                        return false;
                    }
                }
                else
                {
                    if (!FUN_vt824(apActor, *pTarget->FUN_00568fa0(), pTarget->FUN_008d6f30(), pTarget->FUN_00575d70()))
                        return false;
                }
            }
            if (!apActor->FUN_008b3bb0())
            {
                ActGlobal* pHourGlobal = LookupFormByID(0x3a);
                float fNowCur = DAT_011de7b8.FUN_00867da0();
                if (FUN_007df1f0() > fNowCur)
                    fNowCur = fNowCur + 24.0;
                float fElapsedVal = fNowCur - FUN_007df1f0();
                fElapsedVal = 3600.0 / pHourGlobal->FUN_00526ac0() * fElapsedVal;
                if (apActor->FUN_00931850() != 1 || apActor->GetCellLoadState() != 1)
                {
                    return false;
                }
                else
                {
                    bDoneEntry = pPackage->FUN_vt144(apActor, 0);
                }
            }
        }

        if (bDoneEntry || FUN_00915ef0(apActor))
        {
            if (!apActor->FUN_008b3bb0())
                FUN_vt294(apActor);
            if (GetCurrentPackage()->FUN_0041ca90() == 0x1c && FUN_00915ef0(apActor))
            {
                apActor->FUN_vt288();
                return false;
            }
            if (abActivate)
            {
                ActRef* pActivated = pTarget;
                if (!FUN_00915ef0(apActor) && !pPackage->FUN_0067efd0())
                    SetProcessTarget(apActor, 1);
                if (!FUN_00915ef0(apActor))
                {
                    if (pTarget->FUN_00568680())
                    {
                        if (apActor->FUN_vt214() != 4 && apActor->FUN_vt214() != 9)
                        {
                            if (sActivated == 0)
                            {
                                SetProcessTarget(apActor, 1);
                                iTargetState = 0;
                                FUN_vt294(apActor);
                                sActivated = 1;
                                return true;
                            }
                            else
                            {
                                UpdateFurnitureAlignment(apActor);
                            }
                        }
                        else
                        {
                            SetProcessTarget(apActor, 1);
                            FUN_vt4ec(1);
                            return true;
                        }
                    }
                    else if (m_pDetectionData60)
                    {
                        pTarget->Activate(apActor, 1, m_pDetectionData60->pItem, 1);
                    }
                    else if (!pTarget->IsActor() && !pTarget->Activate(apActor, 1, 0, 1) &&
                             pPackage->FUN_0067efd0())
                    {
                        SetProcessTarget(apActor, -1);
                    }
                }
                if (pActivated)
                    pActivated->FUN_00565870();
            }
            else
            {
                ActRef* pUsed = pTarget;
                if (!FUN_00915ef0(apActor))
                {
                    if (pTarget->FUN_00568680())
                    {
                        if (apActor->FUN_vt214() != 4 && apActor->FUN_vt214() != 9)
                        {
                            if (sActivated == 0)
                            {
                                SetProcessTarget(apActor, 1);
                                iTargetState = 0;
                                FUN_vt294(apActor);
                                sActivated = 1;
                                return true;
                            }
                            else
                            {
                                UpdateFurnitureAlignment(apActor);
                            }
                        }
                        else
                        {
                            FUN_vt4ec(1);
                            return true;
                        }
                    }
                    else if (m_pDetectionData60)
                    {
                        pTarget->Activate(apActor, 0, m_pDetectionData60->pItem, 1);
                    }
                    else
                    {
                        pTarget->Activate(apActor, 0, 0, 1);
                    }
                }
                if (pUsed)
                    pUsed->FUN_00565870();
            }
            delete m_pDetectionData60;
            m_pDetectionData60 = 0;
            FUN_vt12c(0);
            if (!FUN_00915ef0(apActor))
                return true;
            else
                return false;
        }
    }
    return false;
}

}
struct VTag
{
};
template <int N> struct Slots : Slots<N - 1>
{
    virtual void slot(Slots<N>*);
};
template <> struct Slots<0>
{
    virtual void slot(Slots<0>*);
};
struct Self91 : Slots<9>
{
    virtual void v028();
};
struct Ref91;
struct Point91;
struct SelfFull91 : Slots<432>
{
    virtual void v6c4();
    void FUN_0091fee0(Ref91*, Point91, float);
};
struct Actor91 : Slots<132>
{
    virtual int v214();
};
struct ActorFull91 : Slots<226>
{
    virtual bool v38c();
};
struct Point91
{
    float off00, off04, off08;
    Point91();
    Point91 operator-(const Point91&) const;
    void unitize();
    Point91* scale(float);
};
__declspec(align(16)) struct Aligned91
{
    char off00[16];
    Aligned91();
};
struct Body91
{
    void position(Point91*);
    void impulse(Point91*, float);
};
struct Ragdoll91
{
    void a(int);
    void b(int);
};
struct Filter91
{
    int value();
};
struct Pen91
{
    void apply(NiNode*, int);
};
struct Ref91
{
    char off000[0xac];
    Ragdoll91* off0ac;
    Pen91* off0b0;
    bool valid();
    Body91* body();
    void prepare();
    NiNode* node();
    Filter91* filter(int*);
    void* weapon();
};
struct Queue91
{
    static Queue91* GetSingleton();
    void enqueue(Ref91*, float, float, float, float);
};
struct SettingValue91
{
    float off00;
};
struct Setting91
{
    SettingValue91* Float();
};
extern Setting91 settingA91, settingB91, settingC91;
struct Player91
{
    NiNode* GetNode(bool);
};
extern Player91* player91;
struct Update91
{
    float off00;
    int off04, off08;
    void init(float, bool, bool);
};
struct Node91
{
    void Update(const Update91&);
};
extern bool FUN_008c7aa0();
extern void FUN_00c6a350(NiNode*, int, bool, bool, bool);
extern void FUN_004a3e00(void*, const Point91&);
extern void impulse91(NiNode*, const Aligned91*, float, int);
namespace proc92a {
struct N92Proc
{
    int unk00;
    int iState;
    int FUN_009f3390();
};
struct N92Actor
{
    virtual void a_000();
    virtual void a_001();
    virtual void a_002();
    virtual void a_003();
    virtual void a_004();
    virtual void a_005();
    virtual void a_006();
    virtual void a_007();
    virtual void a_008();
    virtual void a_009();
    virtual void a_00a();
    virtual void a_00b();
    virtual void a_00c();
    virtual void a_00d();
    virtual void a_00e();
    virtual void a_00f();
    virtual void a_010();
    virtual void a_011();
    virtual void a_012();
    virtual void a_013();
    virtual void a_014();
    virtual void a_015();
    virtual void a_016();
    virtual void a_017();
    virtual void a_018();
    virtual void a_019();
    virtual void a_01a();
    virtual void a_01b();
    virtual void a_01c();
    virtual void a_01d();
    virtual void a_01e();
    virtual void a_01f();
    virtual void a_020();
    virtual void a_021();
    virtual void a_022();
    virtual void a_023();
    virtual void a_024();
    virtual void a_025();
    virtual void a_026();
    virtual void a_027();
    virtual void a_028();
    virtual void a_029();
    virtual void a_02a();
    virtual void a_02b();
    virtual void a_02c();
    virtual void a_02d();
    virtual void a_02e();
    virtual void a_02f();
    virtual void a_030();
    virtual void a_031();
    virtual void a_032();
    virtual void a_033();
    virtual void a_034();
    virtual void a_035();
    virtual void a_036();
    virtual void a_037();
    virtual void a_038();
    virtual void a_039();
    virtual void a_03a();
    virtual void a_03b();
    virtual void a_03c();
    virtual void a_03d();
    virtual void a_03e();
    virtual void a_03f();
    virtual void a_040();
    virtual void a_041();
    virtual void a_042();
    virtual void a_043();
    virtual void a_044();
    virtual void a_045();
    virtual void a_046();
    virtual void a_047();
    virtual void a_048();
    virtual void a_049();
    virtual void a_04a();
    virtual void a_04b();
    virtual void a_04c();
    virtual void a_04d();
    virtual void a_04e();
    virtual void a_04f();
    virtual void a_050();
    virtual void a_051();
    virtual void a_052();
    virtual void a_053();
    virtual void a_054();
    virtual void a_055();
    virtual void a_056();
    virtual void a_057();
    virtual void a_058();
    virtual void a_059();
    virtual void a_05a();
    virtual void a_05b();
    virtual void a_05c();
    virtual void a_05d();
    virtual void a_05e();
    virtual void a_05f();
    virtual void a_060();
    virtual void a_061();
    virtual void a_062();
    virtual void a_063();
    virtual void a_064();
    virtual void a_065();
    virtual void a_066();
    virtual void a_067();
    virtual void a_068();
    virtual void a_069();
    virtual void a_06a();
    virtual void a_06b();
    virtual void a_06c();
    virtual void a_06d();
    virtual void a_06e();
    virtual void a_06f();
    virtual void a_070();
    virtual void a_071();
    virtual void a_072();
    virtual void a_073();
    virtual void a_074();
    virtual void a_075();
    virtual void a_076();
    virtual void a_077();
    virtual void a_078();
    virtual void a_079();
    virtual void a_07a();
    virtual void a_07b();
    virtual void a_07c();
    virtual void a_07d();
    virtual void a_07e();
    virtual void a_07f();
    virtual void a_080();
    virtual void a_081();
    virtual void a_082();
    virtual void a_083();
    virtual void a_084();
    virtual int Get214();
    virtual void a_086();
    virtual void a_087();
    virtual void a_088();
    virtual void a_089();
    virtual void a_08a();
    virtual void a_08b();
    virtual void a_08c();
    virtual void a_08d();
    virtual void a_08e();
    virtual void a_08f();
    virtual void a_090();
    virtual void a_091();
    virtual void a_092();
    virtual void a_093();
    virtual void a_094();
    virtual void a_095();
    virtual void a_096();
    virtual void a_097();
    virtual void a_098();
    virtual void a_099();
    virtual void a_09a();
    virtual void a_09b();
    virtual void a_09c();
    virtual void a_09d();
    virtual void a_09e();
    virtual void a_09f();
    virtual void a_0a0();
    virtual void a_0a1();
    virtual void a_0a2();
    virtual void a_0a3();
    virtual void a_0a4();
    virtual void a_0a5();
    virtual void a_0a6();
    virtual void a_0a7();
    virtual void a_0a8();
    virtual void a_0a9();
    virtual void a_0aa();
    virtual void a_0ab();
    virtual void a_0ac();
    virtual void a_0ad();
    virtual void a_0ae();
    virtual void a_0af();
    virtual void a_0b0();
    virtual void a_0b1();
    virtual void a_0b2();
    virtual void a_0b3();
    virtual void a_0b4();
    virtual void a_0b5();
    virtual void a_0b6();
    virtual void a_0b7();
    virtual void a_0b8();
    virtual void a_0b9();
    virtual void a_0ba();
    virtual void a_0bb();
    virtual void a_0bc();
    virtual void a_0bd();
    virtual void a_0be();
    virtual void a_0bf();
    virtual void a_0c0();
    virtual void a_0c1();
    virtual void a_0c2();
    virtual void a_0c3();
    virtual void a_0c4();
    virtual void a_0c5();
    virtual void a_0c6();
    virtual void a_0c7();
    virtual void a_0c8();
    virtual void a_0c9();
    virtual void a_0ca();
    virtual void a_0cb();
    virtual void a_0cc();
    virtual void a_0cd();
    virtual void a_0ce();
    virtual void a_0cf();
    virtual void a_0d0();
    virtual void a_0d1();
    virtual void a_0d2();
    virtual void a_0d3();
    virtual void a_0d4();
    virtual void a_0d5();
    virtual void a_0d6();
    virtual void a_0d7();
    virtual void a_0d8();
    virtual void a_0d9();
    virtual void a_0da();
    virtual void a_0db();
    virtual void a_0dc();
    virtual void a_0dd();
    virtual void a_0de();
    virtual void a_0df();
    virtual void a_0e0();
    virtual void a_0e1();
    virtual void a_0e2();
    virtual void a_0e3();
    virtual void a_0e4();
    virtual void a_0e5();
    virtual void a_0e6();
    virtual void a_0e7();
    virtual void a_0e8();
    virtual void a_0e9();
    virtual void a_0ea();
    virtual void a_0eb();
    virtual void a_0ec();
    virtual void a_0ed();
    virtual void a_0ee();
    virtual void a_0ef();
    virtual void a_0f0();
    virtual void a_0f1();
    virtual void a_0f2();
    virtual void a_0f3();
    virtual void a_0f4();
    virtual void a_0f5();
    virtual void a_0f6();
    virtual void a_0f7();
    virtual void a_0f8();
    virtual void a_0f9();
    virtual void a_0fa();
    virtual void a_0fb();
    virtual void a_0fc();
    virtual void a_0fd();
    virtual void a_0fe();
    virtual void a_0ff();
    virtual void a_100();
    virtual void a_101();
    virtual void a_102();
    virtual void a_103();
    virtual void a_104();
    virtual void a_105();
    virtual void Do418();
};
struct N92Procedure
{
    virtual void s_000();
    virtual void s_001();
    virtual void s_002();
    virtual void s_003();
    virtual void s_004();
    virtual void s_005();
    virtual void s_006();
    virtual void s_007();
    virtual void s_008();
    virtual void s_009();
    virtual void s_00a();
    virtual void s_00b();
    virtual void s_00c();
    virtual void s_00d();
    virtual void s_00e();
    virtual void s_00f();
    virtual void s_010();
    virtual void s_011();
    virtual void s_012();
    virtual void s_013();
    virtual void s_014();
    virtual void s_015();
    virtual void s_016();
    virtual void s_017();
    virtual void s_018();
    virtual void s_019();
    virtual void s_01a();
    virtual void s_01b();
    virtual void s_01c();
    virtual void s_01d();
    virtual void s_01e();
    virtual void s_01f();
    virtual void s_020();
    virtual void s_021();
    virtual void s_022();
    virtual void s_023();
    virtual void s_024();
    virtual void s_025();
    virtual void s_026();
    virtual void s_027();
    virtual void s_028();
    virtual void s_029();
    virtual void s_02a();
    virtual void s_02b();
    virtual void s_02c();
    virtual void s_02d();
    virtual void s_02e();
    virtual void s_02f();
    virtual void s_030();
    virtual void s_031();
    virtual void s_032();
    virtual void s_033();
    virtual void s_034();
    virtual void s_035();
    virtual void s_036();
    virtual void s_037();
    virtual void s_038();
    virtual void s_039();
    virtual void s_03a();
    virtual void s_03b();
    virtual void s_03c();
    virtual void s_03d();
    virtual void s_03e();
    virtual void s_03f();
    virtual void s_040();
    virtual void s_041();
    virtual void s_042();
    virtual void s_043();
    virtual void s_044();
    virtual void s_045();
    virtual void s_046();
    virtual void s_047();
    virtual void s_048();
    virtual void s_049();
    virtual void s_04a();
    virtual void s_04b();
    virtual void s_04c();
    virtual void s_04d();
    virtual void s_04e();
    virtual void s_04f();
    virtual void s_050();
    virtual void s_051();
    virtual void s_052();
    virtual void s_053();
    virtual void s_054();
    virtual void s_055();
    virtual void s_056();
    virtual void s_057();
    virtual void s_058();
    virtual void s_059();
    virtual void s_05a();
    virtual void s_05b();
    virtual void s_05c();
    virtual void s_05d();
    virtual void s_05e();
    virtual void s_05f();
    virtual void s_060();
    virtual void s_061();
    virtual void s_062();
    virtual void s_063();
    virtual void s_064();
    virtual void s_065();
    virtual void s_066();
    virtual void s_067();
    virtual void s_068();
    virtual void s_069();
    virtual void s_06a();
    virtual void s_06b();
    virtual void s_06c();
    virtual void s_06d();
    virtual void s_06e();
    virtual void s_06f();
    virtual void s_070();
    virtual void s_071();
    virtual void s_072();
    virtual void s_073();
    virtual void s_074();
    virtual void s_075();
    virtual void s_076();
    virtual void s_077();
    virtual void s_078();
    virtual void s_079();
    virtual void s_07a();
    virtual void s_07b();
    virtual void s_07c();
    virtual void s_07d();
    virtual void s_07e();
    virtual void s_07f();
    virtual void s_080();
    virtual void s_081();
    virtual void s_082();
    virtual void s_083();
    virtual void s_084();
    virtual void s_085();
    virtual void s_086();
    virtual void s_087();
    virtual void s_088();
    virtual void s_089();
    virtual void s_08a();
    virtual void s_08b();
    virtual void s_08c();
    virtual void s_08d();
    virtual void s_08e();
    virtual void s_08f();
    virtual void s_090();
    virtual void s_091();
    virtual void s_092();
    virtual void s_093();
    virtual void s_094();
    virtual void s_095();
    virtual void s_096();
    virtual void s_097();
    virtual void s_098();
    virtual void s_099();
    virtual void s_09a();
    virtual void s_09b();
    virtual void s_09c();
    virtual void s_09d();
    virtual void s_09e();
    virtual void s_09f();
    virtual void s_0a0();
    virtual void Fail(int code);
    virtual void s_0a2();
    virtual void s_0a3();
    virtual void s_0a4();
    virtual void s_0a5();
    virtual void s_0a6();
    virtual void s_0a7();
    virtual void s_0a8();
    virtual void s_0a9();
    virtual void s_0aa();
    virtual void s_0ab();
    virtual void s_0ac();
    virtual void s_0ad();
    virtual void s_0ae();
    virtual void s_0af();
    virtual void s_0b0();
    virtual void s_0b1();
    virtual void s_0b2();
    virtual void s_0b3();
    virtual void s_0b4();
    virtual void s_0b5();
    virtual void s_0b6();
    virtual void s_0b7();
    virtual void s_0b8();
    virtual void s_0b9();
    virtual void s_0ba();
    virtual void s_0bb();
    virtual void s_0bc();
    virtual void s_0bd();
    virtual void s_0be();
    virtual void s_0bf();
    virtual void s_0c0();
    virtual void s_0c1();
    virtual void s_0c2();
    virtual void s_0c3();
    virtual void s_0c4();
    virtual void s_0c5();
    virtual void s_0c6();
    virtual void s_0c7();
    virtual void s_0c8();
    virtual void s_0c9();
    virtual void s_0ca();
    virtual void s_0cb();
    virtual void s_0cc();
    virtual void s_0cd();
    virtual void s_0ce();
    virtual void s_0cf();
    virtual void s_0d0();
    virtual void s_0d1();
    virtual void s_0d2();
    virtual void s_0d3();
    virtual void s_0d4();
    virtual void s_0d5();
    virtual void s_0d6();
    virtual void s_0d7();
    virtual void s_0d8();
    virtual void s_0d9();
    virtual void s_0da();
    virtual void s_0db();
    virtual void s_0dc();
    virtual void s_0dd();
    virtual void s_0de();
    virtual void s_0df();
    virtual void s_0e0();
    virtual void s_0e1();
    virtual void s_0e2();
    virtual void s_0e3();
    virtual void s_0e4();
    virtual void s_0e5();
    virtual void s_0e6();
    virtual void s_0e7();
    virtual void s_0e8();
    virtual void s_0e9();
    virtual void s_0ea();
    virtual void s_0eb();
    virtual void s_0ec();
    virtual void s_0ed();
    virtual void s_0ee();
    virtual void s_0ef();
    virtual void s_0f0();
    virtual void s_0f1();
    virtual void s_0f2();
    virtual void s_0f3();
    virtual void s_0f4();
    virtual void s_0f5();
    virtual void s_0f6();
    virtual void s_0f7();
    virtual void s_0f8();
    virtual void s_0f9();
    virtual void s_0fa();
    virtual void s_0fb();
    virtual void s_0fc();
    virtual void s_0fd();
    virtual void s_0fe();
    virtual void s_0ff();
    virtual void s_100();
    virtual void s_101();
    virtual void s_102();
    virtual void s_103();
    virtual void s_104();
    virtual void s_105();
    virtual void s_106();
    virtual void s_107();
    virtual void s_108();
    virtual void s_109();
    virtual void s_10a();
    virtual void s_10b();
    virtual void s_10c();
    virtual void s_10d();
    virtual void s_10e();
    virtual void s_10f();
    virtual void s_110();
    virtual void s_111();
    virtual void s_112();
    virtual void s_113();
    virtual void s_114();
    virtual void s_115();
    virtual void s_116();
    virtual void s_117();
    virtual void s_118();
    virtual void s_119();
    virtual void s_11a();
    virtual void s_11b();
    virtual void s_11c();
    virtual void s_11d();
    virtual void s_11e();
    virtual void s_11f();
    virtual void s_120();
    virtual void s_121();
    virtual void s_122();
    virtual void s_123();
    virtual void s_124();
    virtual void s_125();
    virtual void s_126();
    virtual void s_127();
    virtual void s_128();
    virtual void s_129();
    virtual void s_12a();
    virtual void s_12b();
    virtual void s_12c();
    virtual void s_12d();
    virtual void s_12e();
    virtual void s_12f();
    virtual void s_130();
    virtual void s_131();
    virtual void s_132();
    virtual void s_133();
    virtual void s_134();
    virtual void s_135();
    virtual void s_136();
    virtual void s_137();
    virtual void s_138();
    virtual void s_139();
    virtual void s_13a();
    virtual void s_13b();
    virtual void s_13c();
    virtual void s_13d();
    virtual void s_13e();
    virtual void s_13f();
    virtual void s_140();
    virtual void s_141();
    virtual void s_142();
    virtual void s_143();
    virtual void s_144();
    virtual void s_145();
    virtual void s_146();
    virtual void s_147();
    virtual void s_148();
    virtual void s_149();
    virtual void s_14a();
    virtual void s_14b();
    virtual void s_14c();
    virtual void s_14d();
    virtual void s_14e();
    virtual void s_14f();
    virtual void s_150();
    virtual void s_151();
    virtual void s_152();
    virtual void s_153();
    virtual void s_154();
    virtual void s_155();
    virtual void s_156();
    virtual void s_157();
    virtual void s_158();
    virtual void s_159();
    virtual void s_15a();
    virtual void s_15b();
    virtual void s_15c();
    virtual void s_15d();
    virtual void s_15e();
    virtual void s_15f();
    virtual void s_160();
    virtual void s_161();
    virtual void s_162();
    virtual void s_163();
    virtual void s_164();
    virtual void s_165();
    virtual void s_166();
    virtual void s_167();
    virtual void s_168();
    virtual void s_169();
    virtual void s_16a();
    virtual void s_16b();
    virtual void s_16c();
    virtual void s_16d();
    virtual void s_16e();
    virtual void s_16f();
    virtual void s_170();
    virtual void s_171();
    virtual void s_172();
    virtual void s_173();
    virtual void s_174();
    virtual void s_175();
    virtual void s_176();
    virtual void s_177();
    virtual void s_178();
    virtual void s_179();
    virtual void s_17a();
    virtual void s_17b();
    virtual void s_17c();
    virtual void s_17d();
    virtual void s_17e();
    virtual void s_17f();
    virtual void s_180();
    virtual void s_181();
    virtual void s_182();
    virtual void s_183();
    virtual void s_184();
    virtual void s_185();
    virtual void s_186();
    virtual void s_187();
    virtual void s_188();
    virtual void s_189();
    virtual void s_18a();
    virtual void s_18b();
    virtual void s_18c();
    virtual void s_18d();
    virtual void s_18e();
    virtual void s_18f();
    virtual void s_190();
    virtual void s_191();
    virtual void s_192();
    virtual void s_193();
    virtual void s_194();
    virtual void s_195();
    virtual void s_196();
    virtual void s_197();
    virtual void s_198();
    virtual void s_199();
    virtual void s_19a();
    virtual void s_19b();
    virtual void s_19c();
    virtual void s_19d();
    virtual void s_19e();
    virtual void s_19f();
    virtual void s_1a0();
    virtual void s_1a1();
    virtual void s_1a2();
    virtual void s_1a3();
    virtual void s_1a4();
    virtual void s_1a5();
    virtual void s_1a6();
    virtual void s_1a7();
    virtual void s_1a8();
    virtual void s_1a9();
    virtual void s_1aa();
    virtual void s_1ab();
    virtual void s_1ac();
    virtual void s_1ad();
    virtual void s_1ae();
    virtual void s_1af();
    virtual void s_1b0();
    virtual void s_1b1();
    virtual void s_1b2();
    virtual void s_1b3();
    virtual void s_1b4();
    virtual void s_1b5();
    virtual void s_1b6();
    virtual void s_1b7();
    virtual void s_1b8();
    virtual void s_1b9();
    virtual void s_1ba();
    virtual void s_1bb();
    virtual void s_1bc();
    virtual void s_1bd();
    virtual void s_1be();
    virtual void s_1bf();
    virtual void s_1c0();
    virtual void s_1c1();
    virtual void s_1c2();
    virtual void s_1c3();
    virtual void s_1c4();
    virtual void s_1c5();
    virtual void s_1c6();
    virtual void s_1c7();
    virtual void s_1c8();
    virtual void s_1c9();
    virtual void s_1ca();
    virtual void s_1cb();
    virtual void s_1cc();
    virtual void s_1cd();
    virtual void s_1ce();
    virtual void s_1cf();
    virtual void s_1d0();
    virtual void s_1d1();
    virtual void s_1d2();
    virtual void s_1d3();
    virtual void s_1d4();
    virtual void s_1d5();
    virtual void s_1d6();
    virtual void s_1d7();
    virtual void s_1d8();
    virtual void s_1d9();
    virtual void s_1da();
    virtual void s_1db();
    virtual void s_1dc();
    virtual void s_1dd();
    virtual void s_1de();
    virtual void s_1df();
    virtual void s_1e0();
    virtual void s_1e1();
    virtual void s_1e2();
    virtual void s_1e3();
    virtual void s_1e4();
    virtual void s_1e5();
    virtual void s_1e6();
    virtual void s_1e7();
    virtual void s_1e8();
    virtual void s_1e9();
    virtual void s_1ea();
    virtual void s_1eb();
    virtual void s_1ec();
    virtual void s_1ed();
    virtual void s_1ee();
    virtual void s_1ef();
    virtual void s_1f0();
    virtual void s_1f1();
    virtual void s_1f2();
    virtual void s_1f3();
    virtual void s_1f4();
    virtual void s_1f5();
    virtual void s_1f6();
    virtual void s_1f7();
    virtual void s_1f8();
    virtual void s_1f9();
    virtual void s_1fa();
    virtual void s_1fb();
    virtual void s_1fc();
    virtual void s_1fd();
    virtual void s_1fe();
    virtual void s_1ff();
    virtual void s_200();
    virtual void s_201();
    virtual void s_202();
    virtual void s_203();
    virtual void s_204();
    virtual void s_205();
    virtual void s_206();
    virtual void s_207();
    virtual void s_208();
    virtual void s_209();
    virtual void s_20a();
    virtual void s_20b();
    virtual void s_20c();
    virtual void s_20d();
    virtual void s_20e();
    virtual void s_20f();
    virtual void s_210();
    virtual void s_211();
    virtual void s_212();
    virtual void s_213();
    virtual void s_214();
    virtual void Run0(N92Actor* actor, N92Proc* proc);
    virtual void s_216();
    virtual void Run1(N92Actor* actor, N92Proc* proc);
    virtual void s_218();
    virtual void Run2(N92Actor* actor, N92Proc* proc);
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
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int m140;
    N92Proc* FUN_008d0430();
    void FUN_0092acd0(N92Actor* actor);
};
}
using namespace proc92a;
namespace s44b130 {

struct Lock
{
    bool FUN_0044b130();
};

// @fnv 0x0044b130
bool Lock::FUN_0044b130()
{
    bool bResult = DAT_00fdf1b0(this) ? 1 : 0;
    return bResult;
}

}
struct xNode;
struct xLog;
struct xActor;
struct xBuf;
struct xChangeFlags
{
    unsigned int uiFlags;
    xChangeFlags(unsigned int f);
    operator bool() const;
};
struct xIdList
{
    void* pHead;
    void* pTail;
    int iCount;
    void AddHead(int* p);
};
struct xEntry
{
    int aiData[6];
    xEntry();
    void Load(xBuf* buf);
};
struct PointerListNode
{
    void* pItem;
    void* pNext;
    PointerListNode();
    void AddHead(xEntry** p);
};
struct xPackageCall
{
    int iData;
    void LoadGame(xBuf* buf);
};
struct xItem
{
    void* GetForm();
    bool IsQuestItem(int a, int b);
    void SetCount(unsigned int n);
};
struct xInventory
{
    static xInventory* Get(xActor* pkRef);
    int GetObjectCount(void* qAhbO);
};
struct xExtraData
{
    void* GetItem(int a, int b);
};
struct xExtra
{
    xExtraData* GetData();
};
struct xNpc
{
    void Refresh(xActor* a, int b, int c, int d);
};
struct xSaveLoad
{
    void Load(int a, xBuf* buf, int b);
};
struct xSpinLock
{
    bool TryLock();
    void Unlock();
};
struct xBuf
{
    virtual unsigned char GetVersion();
    virtual void v004();
    virtual void v008();
    virtual xActor* GetForm();
    void Read(void* p, int n);
    void ReadRef(void* p);
    unsigned int ReadFormID();
    unsigned int ReadCount();
    xChangeFlags GetChangeFlags(unsigned int mask);
};
struct xActor
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
    virtual xNode* Get3D();
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
    virtual bool IsPlayerTeammate();
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
    virtual void Equip(void* a, int b, bool c);
    void SetFurnitureState(unsigned char c);
    xExtra* GetExtra();
    const char* GetFullName();
    void SetItem(void* p);
    xLog* GetLog();
    xNpc* GetBase();
    void* ComputePositionAtTime(xActor* a);
    bool CheckAnim(int a, void* b);
    void Reset3D();
};
struct xLog
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
    virtual void Log168(int a);
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
    virtual void Log1cc(bool b);
};
struct xProcess
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
    virtual void SetEquipped(void* a, xNode* b, int c);
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
    virtual void OnSitStateChange(xActor* a);
    char _pad004[0xc4];
    xIdList m_0c8;
    char _pad0d4[0x4];
    unsigned int m_0d8;
    unsigned int m_0dc;
    unsigned char m_0e0;
    unsigned char m_0e1;
    char _pad0e2[0x2];
    xPackageCall m_0e4;
    char _pad0e8[0x14];
    float m_0fc[3];
    unsigned int m_108;
    TESIdleForm* m_10c;
    unsigned char m_110;
    char _pad111[0x3];
    xItem* m_114;
    xItem* m_118;
    char _pad11c[0x18];
    unsigned char m_134;
    unsigned char m_135;
    char _pad136[0x6];
    char m_13c;
    unsigned char m_13d;
    char _pad13e[0x2];
    unsigned int m_140;
    unsigned char m_144;
    char _pad145[0x3];
    float m_148[3];
    unsigned short m_154;
    unsigned char m_156;
    char _pad157[0x1];
    unsigned int m_158;
    char _pad15c[0x4];
    unsigned int m_160;
    unsigned int m_164;
    unsigned char m_168;
    char _pad169[0x7];
    unsigned int m_170;
    unsigned int m_174;
    char _pad178[0x10];
    unsigned char m_188;
    unsigned char m_189;
    char _pad18a[0x1];
    unsigned char m_18b;
    char _pad18c[0x4];
    unsigned int m_190;
    TESIdleForm* m_194;
    unsigned int m_198;
    unsigned char m_19c;
    unsigned char m_19d;
    char _pad19e[0xa];
    unsigned int m_1a8;
    char _pad1ac[0xc];
    void* m_1b8;
    unsigned int m_1bc;
    char _pad1c0[0x10];
    unsigned int m_1d0;
    unsigned int m_1d4;
    unsigned char m_1d8;
    unsigned char m_1d9;
    unsigned char m_1da;
    char _pad1db[0x4d];
    unsigned char m_228;
    char _pad229[0x1];
    unsigned short m_22a;
    char _pad22c[0x4];
    PointerListNode* m_230;
    unsigned int m_234;
    unsigned int m_238;
    unsigned int m_23c;
    char _pad240[0x4];
    unsigned int m_244;
    int m_248;
    void BaseLoadGame(xBuf* buf);
    void FUN_00927000(xBuf* buf);
};
TESForm* xLookupForm(unsigned int id);
int __cdecl xStrcmp(const char* a, const char* b);
void xLoadActiveEffects(xBuf* buf, void* list);
extern xSaveLoad* xg_pSaveLoad;
extern xActor* xg_pPlayer;
extern xSpinLock xg_kLock;
struct CellStandIn_9294b0
{
    void FUN_00548740(ArrowProjectile*);
};
struct MatchQueue_9294b0
{
    void Drop(ArrowProjectile*);
};
namespace ArrowDrop_9294b0 {
extern "C" MatchQueue_9294b0 DAT_011e0e80;
}
struct S_9294b0 : public MiddleHighProcess
{
    void FUN_009294b0(TESObjectREFR* apAttachedRef);
};
class QueuedFileAccess
{
  public:
    int refs;
    int type;
    int state;
    int flags;
    int filename;
    int context;
    int request;
    int model;
    int task;
    int result;
    QueuedFileAccess(int);
};
class MemContextAccess
{
    int saved;

  public:
    MemContextAccess(int, bool, const char*, int);
    ~MemContextAccess();
};
extern char DAT_010898c0[];
extern int DAT_0118a838[];
extern int DAT_011e0410;
class SoundAccess
{
  public:
    const char* FUN_00511840();
};
class WeaponBaseAccess
{
  public:
    int FUN_00446390();
    SoundAccess* FUN_005215a0(bool);
    SoundAccess* GetValueByFlag(bool);
    SoundAccess* GetPointerByFlag(bool);
    SoundAccess* GetField22C();
    void FUN_00525510(int, QueuedFileAccess*, bool);
};
class ItemChangeAccess
{
  public:
    ~ItemChangeAccess();
    WeaponBaseAccess* FUN_0044ddc0();
    bool HasEffect(int);
};
class AnimAccess
{
  public:
    NiNode* FUN_005585e0();
    NiControllerManager* FUN_00496940();
};
class PlayerAccess
{
  public:
    Animation* FUN_00950a60(bool);
    NiNode* FUN_00950bb0(bool);
    BaseProcess* FUN_008d8520();
    void SetByteAtOffset1F8(char);
};
class AudioAccess
{
  public:
    void FUN_00ad8100(const char*, unsigned int, SoundAccess*);
};
AudioAccess* FUN_00453a70();
void FUN_008d6a80(const char*, NiNode*);
class WeaponPreloadAccess
{
  public:
    WeaponPreloadAccess* FUN_006f74f0(QueuedFileAccess*);
    QueuedFileAccess* FUN_00559450();
};
class CloneAccess
{
  public:
    void FUN_0092c8b0(void*);
};
class WeaponProcess : public MiddleHighProcess
{
  public:
    bool FUN_0091e100(InventoryStackRecord*, NiNode*, bool);
    void UpdateWeaponTypeFlags();
};
class NiUpdateData
{
  public:
    float fTime;
    unsigned int unk4;
    unsigned int unk8;
    NiUpdateData(float, bool, bool);
};
class NiAVObject
{
  public:
    virtual ~NiAVObject();
    void Update(const NiUpdateData&);
};
class NiNode : public NiAVObject
{
};
class S_006815c0
{
  public:
    void* _ref_006815c0();
};
class ThreeByThreeMatrix : public S_006815c0
{
  public:
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
    void FUN_004a0c90(float);
    NiPoint3 FUN_004b4500(const NiPoint3*) const;
};
using ::TESBoundObject;
__if_not_exists(TESBoundObject::TESBoundObject)
{
    class TESBoundObject : public TESForm
    {
    };
}
class TESFurniture : public TESBoundObject
{
  public:
    NiPoint3 FUN_00509920(unsigned int, float);
    float GetFurnitureHeading(unsigned int);
};
struct TESObjectREFRExt : public TESObjectREFR
{
    NiAVObject* Get3DSimple();
    void FUN_00568020(unsigned int, bool);
    ThreeByThreeMatrix FUN_0056fa00();
    ::NiNode* GetNiNode();
    NiPoint3* GetPos() const;
};
class bhkCharacterController
{
  public:
    void FUN_005620e0(void*);
};
class PlayerCharacter : public Actor
{
  public:
    Animation* GetAnimation(bool);
    BipedAnim* GetBipedAnim(bool);
    NiNode* GetNode(bool);
    bool FUN_004eaf60();
    void ToggleFirstPerson(bool);
    void FUN_005098c0();
};
extern PlayerCharacter* _g_thePlayer;
class FinishLoadSaveGameView
{
  public:
    void AddFormToList(MobileObject*);
};
namespace FinishLoadGlobals {
extern FinishLoadSaveGameView* DAT_011de45c;
}
struct LocalMarker : public S_006815c0
{
    NiPoint3 Position;
    unsigned short m_usMarkerId;
    unsigned char m_ucFlags;
    unsigned char pad;
    unsigned int FUN_005094b0();
    void FUN_00568ab0(unsigned char);
    void FUN_0098ddd0(const NiPoint3&);
    float FUN_00568650();
    void FUN_00c54550(float);
};
class FurnitureNodeStandIn : public NiAVObject
{
  public:
    unsigned int FUN_00509490();
    LocalMarker* FUN_005094d0(unsigned char);
};
class ActorStandIn : public Actor
{
  public:
    void FUN_00931d30(float);
    float GetScale();
    bhkCharacterController* GetPhysicsCharacterController();
};
namespace FinishLoadCalls {
NiAVObject* FUN_00c54400(::NiNode*);
}
void FUN_00a582f0(const ThreeByThreeMatrix&, NiPoint3*, int, const NiPoint3*, const NiPoint3*);
void FUN_00c69fc0(NiAVObject*, bool, bool, bool);
void FUN_00c6a350(NiAVObject*, bool, bool, bool, bool);
void FUN_00806130(void*, Actor*);
class ObjectWithVFuncD8
{
  public:
    virtual void vf000();
    virtual void vf001();
    virtual void vf002();
    virtual void vf003();
    virtual void vf004();
    virtual void vf005();
    virtual void vf006();
    virtual void vf007();
    virtual void vf008();
    virtual void vf009();
    virtual void vf00A();
    virtual void vf00B();
    virtual void vf00C();
    virtual void vf00D();
    virtual void vf00E();
    virtual void vf00F();
    virtual void vf010();
    virtual void vf011();
    virtual void vf012();
    virtual void vf013();
    virtual void vf014();
    virtual void vf015();
    virtual void vf016();
    virtual void vf017();
    virtual void vf018();
    virtual void vf019();
    virtual void vf01A();
    virtual void vf01B();
    virtual void vf01C();
    virtual void vf01D();
    virtual void vf01E();
    virtual void vf01F();
    virtual void vf020();
    virtual void vf021();
    virtual void vf022();
    virtual void vf023();
    virtual void vf024();
    virtual void vf025();
    virtual void vf026();
    virtual void vf027();
    virtual void vf028();
    virtual void vf029();
    virtual void vf02A();
    virtual void vf02B();
    virtual void vf02C();
    virtual void vf02D();
    virtual void vf02E();
    virtual void vf02F();
    virtual void vf030();
    virtual void vf031();
    virtual void vf032();
    virtual void vf033();
    virtual void vf034();
    virtual void vf035();
    virtual void FUN_00d8(int, int);
};
class ObjectWithVFunc1b8
{
  public:
    virtual void vf000();
    virtual void vf001();
    virtual void vf002();
    virtual void vf003();
    virtual void vf004();
    virtual void vf005();
    virtual void vf006();
    virtual void vf007();
    virtual void vf008();
    virtual void vf009();
    virtual void vf00A();
    virtual void vf00B();
    virtual void vf00C();
    virtual void vf00D();
    virtual void vf00E();
    virtual void vf00F();
    virtual void vf010();
    virtual void vf011();
    virtual void vf012();
    virtual void vf013();
    virtual void vf014();
    virtual void vf015();
    virtual void vf016();
    virtual void vf017();
    virtual void vf018();
    virtual void vf019();
    virtual void vf01A();
    virtual void vf01B();
    virtual void vf01C();
    virtual void vf01D();
    virtual void vf01E();
    virtual void vf01F();
    virtual void vf020();
    virtual void vf021();
    virtual void vf022();
    virtual void vf023();
    virtual void vf024();
    virtual void vf025();
    virtual void vf026();
    virtual void vf027();
    virtual void vf028();
    virtual void vf029();
    virtual void vf02A();
    virtual void vf02B();
    virtual void vf02C();
    virtual void vf02D();
    virtual void vf02E();
    virtual void vf02F();
    virtual void vf030();
    virtual void vf031();
    virtual void vf032();
    virtual void vf033();
    virtual void vf034();
    virtual void vf035();
    virtual void vf036();
    virtual void vf037();
    virtual void vf038();
    virtual void vf039();
    virtual void vf03A();
    virtual void vf03B();
    virtual void vf03C();
    virtual void vf03D();
    virtual void vf03E();
    virtual void vf03F();
    virtual void vf040();
    virtual void vf041();
    virtual void vf042();
    virtual void vf043();
    virtual void vf044();
    virtual void vf045();
    virtual void vf046();
    virtual void vf047();
    virtual void vf048();
    virtual void vf049();
    virtual void vf04A();
    virtual void vf04B();
    virtual void vf04C();
    virtual void vf04D();
    virtual void vf04E();
    virtual void vf04F();
    virtual void vf050();
    virtual void vf051();
    virtual void vf052();
    virtual void vf053();
    virtual void vf054();
    virtual void vf055();
    virtual void vf056();
    virtual void vf057();
    virtual void vf058();
    virtual void vf059();
    virtual void vf05A();
    virtual void vf05B();
    virtual void vf05C();
    virtual void vf05D();
    virtual void vf05E();
    virtual void vf05F();
    virtual void vf060();
    virtual void vf061();
    virtual void vf062();
    virtual void vf063();
    virtual void vf064();
    virtual void vf065();
    virtual void vf066();
    virtual void vf067();
    virtual void vf068();
    virtual void vf069();
    virtual void vf06A();
    virtual void vf06B();
    virtual void vf06C();
    virtual void vf06D();
    virtual void* FUN_001b8(int);
};
class FinishInitLoadProcessView : public MiddleHighProcess
{
  public:
    void FUN_00925700(unsigned int, unsigned int, MobileObject*);
};
namespace fnv_00928510 {
using ::Actor;
using ::MiddleHighProcess;
using ::NiNode;
using ::SIT_SLEEP_STATE;
using ::TESObjectREFR;

class Animation;
struct NiAVObject;
namespace FurnitureDecls {
extern "C" NiAVObject* __cdecl FUN_00c54400(NiNode*);
}
int __fastcall FUN_00509490(NiAVObject*);

struct Cls140
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
    virtual NiNode* v116();
};

struct ActorStandIn
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
    virtual void SetLookingTarget(float);
};

struct ActorEx : Actor
{
    void FUN_00931fb0(bool);
};

class PlayerCharacter : public Actor
{
  public:
    bool FUN_004eaf60();
    Animation* GetAnimation(bool);
    void FUN_005c4210(bool);
};

extern PlayerCharacter* g_thePlayer;

class TESIdleForm
{
  public:
    int GetFlagsMasked();
};

class Animation
{
  public:
    void FUN_00498030(TESIdleForm*, Actor*, int);
};

struct TIM_008b2010
{
    TESIdleForm* FUN_00600950(Actor*, TESObjectREFR*);
};
extern TIM_008b2010* DAT_011cb6a0;

struct FurnEx
{
    void FUN_00568020(unsigned char, bool);
};

struct FUN_005094b0_shell
{
    unsigned int FUN_005094b0();
};

struct Helper_00629670
{
    void FUN_00629670(int, bool);
};

class bhkCharacterController
{
  public:
    int unk_0000;
    int unk_0004;
    int unk_0008;
    int unk_000c;
    int unk_0010;
    int unk_0014;
    int unk_0018;
    int unk_001c;
    int unk_0020;
    int unk_0024;
    int unk_0028;
    int unk_002c;
    int unk_0030;
    int unk_0034;
    int unk_0038;
    int unk_003c;
    int unk_0040;
    int unk_0044;
    int unk_0048;
    int unk_004c;
    int unk_0050;
    int unk_0054;
    int unk_0058;
    int unk_005c;
    int unk_0060;
    int unk_0064;
    int unk_0068;
    int unk_006c;
    int unk_0070;
    int unk_0074;
    int unk_0078;
    int unk_007c;
    int unk_0080;
    int unk_0084;
    int unk_0088;
    int unk_008c;
    int unk_0090;
    int unk_0094;
    int unk_0098;
    int unk_009c;
    int unk_00a0;
    int unk_00a4;
    int unk_00a8;
    int unk_00ac;
    int unk_00b0;
    int unk_00b4;
    int unk_00b8;
    int unk_00bc;
    int unk_00c0;
    int unk_00c4;
    int unk_00c8;
    int unk_00cc;
    int unk_00d0;
    int unk_00d4;
    int unk_00d8;
    int unk_00dc;
    int unk_00e0;
    int unk_00e4;
    int unk_00e8;
    int unk_00ec;
    int unk_00f0;
    int unk_00f4;
    int unk_00f8;
    int unk_00fc;
    int unk_0100;
    int unk_0104;
    int unk_0108;
    int unk_010c;
    int unk_0110;
    int unk_0114;
    int unk_0118;
    int unk_011c;
    int unk_0120;
    int unk_0124;
    int unk_0128;
    int unk_012c;
    int unk_0130;
    int unk_0134;
    int unk_0138;
    int unk_013c;
    int unk_0140;
    int unk_0144;
    int unk_0148;
    int unk_014c;
    int unk_0150;
    int unk_0154;
    int unk_0158;
    int unk_015c;
    int unk_0160;
    int unk_0164;
    int unk_0168;
    int unk_016c;
    int unk_0170;
    int unk_0174;
    int unk_0178;
    int unk_017c;
    int unk_0180;
    int unk_0184;
    int unk_0188;
    int unk_018c;
    int unk_0190;
    int unk_0194;
    int unk_0198;
    int unk_019c;
    int unk_01a0;
    int unk_01a4;
    int unk_01a8;
    int unk_01ac;
    int unk_01b0;
    int unk_01b4;
    int unk_01b8;
    int unk_01bc;
    int unk_01c0;
    int unk_01c4;
    int unk_01c8;
    int unk_01cc;
    int unk_01d0;
    int unk_01d4;
    int unk_01d8;
    int unk_01dc;
    int unk_01e0;
    int unk_01e4;
    int unk_01e8;
    int unk_01ec;
    int unk_01f0;
    int unk_01f4;
    int unk_01f8;
    int unk_01fc;
    int unk_0200;
    int unk_0204;
    int unk_0208;
    int unk_020c;
    int unk_0210;
    int unk_0214;
    int unk_0218;
    int unk_021c;
    int unk_0220;
    int unk_0224;
    int unk_0228;
    int unk_022c;
    int unk_0230;
    int unk_0234;
    int unk_0238;
    int unk_023c;
    int unk_0240;
    int unk_0244;
    int unk_0248;
    int unk_024c;
    int unk_0250;
    int unk_0254;
    int unk_0258;
    int unk_025c;
    int unk_0260;
    int unk_0264;
    int unk_0268;
    int unk_026c;
    int unk_0270;
    int unk_0274;
    int unk_0278;
    int unk_027c;
    int unk_0280;
    int unk_0284;
    int unk_0288;
    int unk_028c;
    int unk_0290;
    int unk_0294;
    int unk_0298;
    int unk_029c;
    int unk_02a0;
    int unk_02a4;
    int unk_02a8;
    int unk_02ac;
    int unk_02b0;
    int unk_02b4;
    int unk_02b8;
    int unk_02bc;
    int unk_02c0;
    int unk_02c4;
    int unk_02c8;
    int unk_02cc;
    int unk_02d0;
    int unk_02d4;
    int unk_02d8;
    int unk_02dc;
    int unk_02e0;
    int unk_02e4;
    int unk_02e8;
    int unk_02ec;
    int unk_02f0;
    int unk_02f4;
    int unk_02f8;
    int unk_02fc;
    int unk_0300;
    int unk_0304;
    int unk_0308;
    int unk_030c;
    int unk_0310;
    int unk_0314;
    int unk_0318;
    int unk_031c;
    int unk_0320;
    int unk_0324;
    int unk_0328;
    int unk_032c;
    int unk_0330;
    int unk_0334;
    int unk_0338;
    int unk_033c;
    int unk_0340;
    int unk_0344;
    int unk_0348;
    int unk_034c;
    int unk_0350;
    int unk_0354;
    int unk_0358;
    int unk_035c;
    int unk_0360;
    int unk_0364;
    int unk_0368;
    int unk_036c;
    int unk_0370;
    int unk_0374;
    int unk_0378;
    int unk_037c;
    int unk_0380;
    int unk_0384;
    int unk_0388;
    int unk_038c;
    int unk_0390;
    int unk_0394;
    int unk_0398;
    int unk_039c;
    int unk_03a0;
    int unk_03a4;
    int unk_03a8;
    int unk_03ac;
    int unk_03b0;
    int unk_03b4;
    int unk_03b8;
    int unk_03bc;
    int unk_03c0;
    int unk_03c4;
    int unk_03c8;
    int unk_03cc;
    int unk_03d0;
    int unk_03d4;
    int unk_03d8;
    int unk_03dc;
    int unk_03e0;
    int unk_03e4;
    int unk_03e8;
    int unk_03ec;
    int unk_03f0;
    int unk_03f4;
    int unk_03f8;
    int unk_03fc;
    int unk_0400;
    int unk_0404;
    int unk_0408;
    int unk_040c;
    Helper_00629670 sub410;
};

class MiddleHighProcessExt : public MiddleHighProcess
{
  public:
    void FUN_00928510(Actor* a1, Animation* a2);
};

// @fnv 0x00928510
void MiddleHighProcessExt::FUN_00928510(Actor* a1, Animation* a2)
{
    if (m_pFurnitureReference)
    {
        ::TESBoundObject* boundObj = m_pFurnitureReference->GetObjectReference();
        NiAVObject* avObjVal = FurnitureDecls::FUN_00c54400(((Cls140*)m_pFurnitureReference)->v116());
        if (!avObjVal || (unsigned int)m_ucFurnitureMarkerIndex >= (unsigned int)FUN_00509490(avObjVal))
        {
            ProcessFurniture(a1);
        }
        else
        {
            unsigned char savedState = m_ucFurnitureInteractionState;
            switch (m_ucFurnitureInteractionState)
            {
            case 1:
            case 2:
            case 3:
            case 4:
                m_ucFurnitureInteractionState = 1;
                break;
            case 6:
            case 7:
            case 8:
            case 9:
                m_ucFurnitureInteractionState = 6;
                break;
            default:
                break;
            }
            a1->SetCurrentSitSleepState((SIT_SLEEP_STATE)m_ucFurnitureInteractionState);
            if (m_ucFurnitureInteractionState)
            {
                ((FurnEx*)m_pFurnitureReference)->FUN_00568020(m_ucFurnitureMarkerIndex, true);
                bool b3 = false;
                if (a1 == g_thePlayer)
                {
                    b3 = g_thePlayer->FUN_004eaf60();
                    if (a2 != g_thePlayer->GetAnimation(!b3))
                    {
                        g_thePlayer->FUN_005c4210(!b3);
                    }
                }
                TESIdleForm* idle = DAT_011cb6a0->FUN_00600950(a1, m_pFurnitureReference);
                if (idle)
                {
                    a2->FUN_00498030(idle, a1, idle->GetFlagsMasked());
                }
                if (a1 == g_thePlayer)
                {
                    g_thePlayer->FUN_005c4210(b3);
                }
            }
            m_ucFurnitureInteractionState = savedState;
            bool shouldDisableB =
                IsFurnitureType(m_pFurnitureReference, ((FUN_005094b0_shell*)&FurnitureMarker)->FUN_005094b0());
            bhkCharacterController* pControllerVal = (bhkCharacterController*)GetPhysicsCharacterController();
            if (shouldDisableB && m_ucFurnitureInteractionState)
            {
                ((ActorStandIn*)a1)->SetLookingTarget(0.1f);
                ((ActorEx*)a1)->FUN_00931fb0(true);
                if (pControllerVal)
                {
                    pControllerVal->sub410.FUN_00629670(0x8000000, true);
                }
            }
            else
            {
                ((ActorStandIn*)a1)->SetLookingTarget(0.0f);
                ((ActorEx*)a1)->FUN_00931fb0(false);
                if (pControllerVal)
                {
                    pControllerVal->sub410.FUN_00629670(0x8000000, false);
                }
            }
            a1->SetCurrentSitSleepState((SIT_SLEEP_STATE)m_ucFurnitureInteractionState);
        }
    }
}
}
class AutoMemContext
{
  public:
    AutoMemContext(MEM_CONTEXT aeContext, bool abPush, const char* apFile, int aiLine);
    ~AutoMemContext();
    int iPrevContext;
};
class QueuedItemSV
{
  public:
    QueuedItemSV();
    void FUN_00913a20(Actor* apActor);
    TESBoundObject* pObject;
    ExtraDataList* pExtraData;
    int iCount;
    bool m_bFirstStateFlag;
    bool bUnk0D;
    bool bUnk0E;
    bool bUnk0F;
    bool bUnk10;
    bool bUnk11;
    unsigned char ucPad12;
    unsigned char ucPad13;
    int iUnk14;
};
struct FUN_00915950_shell : public MiddleHighProcess
{
    void FUN_00915950(Actor* apActor, bool abEquip, TESBoundObject* apObject, int aiCount, ExtraDataList* apExtraData,
                      bool abArg6, bool abArg7, bool abArg8, bool abArg9, bool abArg10, bool abArg11);
};
namespace queued_item_load913 {

using ::TESBoundObject;
using ::TESForm;

struct InventoryChangesView
{
    void* GetExtraValueAtPosition(TESBoundObject* obj, int iIndex);
};
struct ExtraDataView
{
    InventoryChangesView* FUN_00418520();
};
struct ReferenceView
{
    ExtraDataView* FUN_005d43c0();
};

struct BufferView
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual ReferenceView* GetRef();
    unsigned int FUN_008648a0();
    void FUN_00864980(void* dst, unsigned int size);
};

struct ItemLoadState913e80
{
    TESBoundObject* object;
    void* entry;
    int unk08;
    unsigned char unk0C;
    unsigned char unk0D;
    unsigned char unk0E;
    unsigned char unk0F;
    unsigned char unk10;
    unsigned char unk11;
    void FUN_00913e80(BufferView* buffer);
};

// @fnv 0x00913e80
void ItemLoadState913e80::FUN_00913e80(BufferView* buffer)
{
    ReferenceView* ref = buffer->GetRef();
    object = dynamic_cast<TESBoundObject*>(reinterpret_cast<TESForm*>(::LookupFormByID(buffer->FUN_008648a0())));
    int iIndex = -1;
    buffer->FUN_00864980(&iIndex, 4);
    if (iIndex != -1)
    {
        InventoryChangesView* holder = ref ? ref->FUN_005d43c0()->FUN_00418520() : 0;
        if (holder)
        {
            entry = holder->GetExtraValueAtPosition(object, iIndex);
        }
    }
    buffer->FUN_00864980(&unk08, 4);
    buffer->FUN_00864980(&unk0C, 1);
    buffer->FUN_00864980(&unk0D, 1);
    buffer->FUN_00864980(&unk0E, 1);
    buffer->FUN_00864980(&unk0F, 1);
    buffer->FUN_00864980(&unk10, 1);
    buffer->FUN_00864980(&unk11, 1);
}

}
struct SetTargetProcess : public MiddleHighProcess
{
    void FUN_0091ea40(TESObjectREFR*);
};
struct SetFlagsX
{
    void SetFlags(unsigned int);
};
struct TgtX
{
    void SetTargetingState(bool);
};
struct MarkerX
{
    void SetMarkerState(int, bool);
};
void __fastcall FUN_00914b40(void*);
struct FUN_005682c0_caller
{
    int FUN_005682c0(bool);
};
__if_not_exists(FUN_00678d00_shell::FUN_00678d00)
{
    struct FUN_00678d00_shell
    {
        bool FUN_00678d00();
    };
}
struct MHPVtX
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
    virtual FUN_00678d00_shell* v139();
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
    virtual SetFlagsX* v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165(TESObjectREFR*);
};
using ::ActorPackageData;
using ::TESObjectREFR;
using ::MiddleHighProcess;
namespace DeletedPackageDetail {
class InstanceView
{
  public:
    virtual ~InstanceView();
    virtual void SetReferenceTarget(::TESObjectREFR*);
};

class PackageView
{
  public:
    void FUN_008c5ec0(::TESObjectREFR*);
};

class CurrentDataView
{
  public:
    ::ActorPackageData* FUN_008d0430();
};
}
struct PackageReferenceProcess : public ::MiddleHighProcess
{
    void FUN_00914be0(::TESObjectREFR* reference);
};
namespace queued_item_save913 {

using ::Actor;
using ::TESObjectREFR;
using ::ExtraDataList;
using ::InventoryChanges;

struct SaveFormIDHelper
{
    virtual void Slot00();
    virtual void Slot04();
    virtual Actor* GetActor();

    void FUN_00865df0(void* formID, int flag);
};

struct SaveBufferView : public SaveFormIDHelper
{
    void FUN_00865e50(void* data, int size, int count);
};

struct InventoryIndexView
{
    int FindItemIndex(void* object, ExtraDataList* extraData);
};

struct PaddedFloatRecord
{
    void* pObject;
    ExtraDataList* pExtra;
    int m_iCountChange;
    unsigned char byte0C;
    unsigned char byte0D;
    unsigned char byte0E;
    unsigned char byte0F;
    unsigned char byte10;
    unsigned char byte11;

    void FUN_00913d60(SaveBufferView* apSaveGameBuffer);
};

// @fnv 0x00913d60
void PaddedFloatRecord::FUN_00913d60(SaveBufferView* apSaveGameBuffer)
{
    int iextraIndex;
    Actor* pactor;
    InventoryChanges* pinventory;

    pactor = apSaveGameBuffer->GetActor();
    apSaveGameBuffer->FUN_00865df0(pObject, 0);
    iextraIndex = -1;

    if (pExtra)
    {
        pinventory = pactor ? ((TESObjectREFR*)pactor)->GetExtraData()->GetContainerChangeData() : 0;

        if (pinventory)
            iextraIndex = ((InventoryIndexView*)pinventory)->FindItemIndex(pObject, pExtra);
    }

    apSaveGameBuffer->FUN_00865e50(&iextraIndex, 4, 0);
    apSaveGameBuffer->FUN_00865e50(&m_iCountChange, 4, 0);
    apSaveGameBuffer->FUN_00865e50(&byte0C, 1, 0);
    apSaveGameBuffer->FUN_00865e50(&byte0D, 1, 0);
    apSaveGameBuffer->FUN_00865e50(&byte0E, 1, 0);
    apSaveGameBuffer->FUN_00865e50(&byte0F, 1, 0);
    apSaveGameBuffer->FUN_00865e50(&byte10, 1, 0);
    apSaveGameBuffer->FUN_00865e50(&byte11, 1, 0);
}

}
namespace PackageEvaluationDetail {
using ::Actor;
using ::LowProcess;
using ::MiddleHighProcess;
using ::TESBoundObject;
using ::TESNPC;
using ::TESCreature;
using ::TESPackage;

class TargetDoorController
{

  public:
    ~TargetDoorController();

    static void operator delete(void*);
};

class PackageActorView : public Actor
{

  public:
    bool FUN_00493bb0();

    bool FUN_009336c0();

    bool FUN_008a61b0();
};

bool __fastcall FUN_00881570(Actor* pActor);

class PackageClockView
{

  public:
    float FUN_00867da0();
};

extern "C" PackageClockView DAT_011de7b8;

class PackageLowProcessView : public LowProcess
{

  public:
    bool FUN_0090a1a0(Actor* pActor, bool bArg2);

    void SetFlag40(int);
};

class PackageProcessView : public MiddleHighProcess
{

  public:
    bool FUN_00917df0(Actor* pActor, bool bArg2);
};

// @fnv 0x00917df0
bool PackageProcessView::FUN_00917df0(Actor* pActor, bool bArg2)
{

    if (((PackageActorView*)pActor)->FUN_00493bb0() ||

        ((PackageActorView*)pActor)->FUN_009336c0() ||

        ((PackageActorView*)pActor)->FUN_008a61b0() ||

        FUN_00881570(pActor))
    {

        return false;
    }

    switch (pActor->Unk_85())
    {

    case 0:

    case 4:

    case 9:

        break;

    default:

        return false;
    }

    if (GetRunOncePackage())
    {

        StopRunOncePackage();
    }

    float fGameHour = DAT_011de7b8.FUN_00867da0();

    bool bResultTmp = false;

    TESPackage* pPackage7 = (TESPackage*)pActor->GetCurrentPackage();

    bool bUnequipWeapon = false;

    if (pPackage7 != NULL)
    {

        if (pPackage7->FUN_0041ca90() == 4 ||

            pPackage7->FUN_00441b00())
        {

            bUnequipWeapon = true;
        }
    }

    if (bArg2 || !GetCurrentPackage() || m_iValueB4 != (int)fGameHour)
    {

        bResultTmp = ((PackageLowProcessView*)this)->FUN_0090a1a0(pActor, bArg2);

        m_iValueB4 = (int)fGameHour;
    }

    if (bResultTmp)
    {

        m_sBoundDataValue = 2;

        SetAnimationEnabled(false);

        SetAnimationComplete(false);

        ((PackageLowProcessView*)this)->SetFlag40(0);

        SetProcessConditionMet(false);

        while (!ReferenceListNode.IsEmpty())
        {

            ::TargetDoorController* pItem = ReferenceListNode.GetItem();

            delete reinterpret_cast<TargetDoorController*>(pItem);

            ReferenceListNode.Remove(pItem);
        }

        if (bUnequipWeapon)
        {

            TESNPC* pNPC2 = dynamic_cast<TESNPC*>(pActor->GetObjectReference());

            TESCreature* pCreature7 = dynamic_cast<TESCreature*>(pActor->GetObjectReference());

            TESPackage* pCurPkg = (TESPackage*)GetCurrentPackage();

            bool bFlag1 = true;

            bool bFlag6 = true;

            if (pCurPkg != NULL && pCurPkg->FUN_00441b00())
            {

                bFlag6 = false;
            }

            if (pNPC2 != NULL)
            {

                pNPC2->FUN_006047c0(pActor, bFlag1, bFlag6, 0, 1);
            }
            else if (pCreature7 != NULL)
            {

                pCreature7->FUN_005f9e00(pActor, bFlag1, bFlag6, 1);
            }
        }
    }

    return bResultTmp;
}

}
using ::TESBoundObject;
using ::TESNPC;
using ::TESCreature;
namespace ProcessUseItem {

struct UsePoint
{
    float x, y, z;
    UsePoint();
    UsePoint FUN_00439ef0(const UsePoint& arOther) const;
    float FUN_00457990() const;
};

struct UseProcess;
struct UsePackage;

struct UseCell
{
    bool FUN_00425fd0();
};

struct UseRef
{
    virtual void r000();
    virtual void r001();
    virtual void r002();
    virtual void r003();
    virtual void r004();
    virtual void r005();
    virtual void r006();
    virtual void r007();
    virtual void r008();
    virtual void r009();
    virtual void r00a();
    virtual void r00b();
    virtual void r00c();
    virtual void r00d();
    virtual void r00e();
    virtual void r00f();
    virtual void r010();
    virtual void r011();
    virtual void r012();
    virtual void r013();
    virtual void r014();
    virtual void r015();
    virtual void r016();
    virtual void r017();
    virtual void r018();
    virtual void r019();
    virtual void r01a();
    virtual void r01b();
    virtual void r01c();
    virtual void r01d();
    virtual void r01e();
    virtual void r01f();
    virtual void r020();
    virtual void r021();
    virtual void r022();
    virtual void r023();
    virtual void r024();
    virtual void r025();
    virtual void r026();
    virtual void r027();
    virtual void r028();
    virtual void r029();
    virtual void r02a();
    virtual void r02b();
    virtual void r02c();
    virtual void r02d();
    virtual void r02e();
    virtual void r02f();
    virtual void r030();
    virtual void r031();
    virtual void r032();
    virtual void r033();
    virtual void r034();
    virtual void r035();
    virtual void r036();
    virtual void r037();
    virtual void r038();
    virtual void r039();
    virtual void r03a();
    virtual void r03b();
    virtual void r03c();
    virtual void r03d();
    virtual void r03e();
    virtual void r03f();
    virtual bool IsActor();
    virtual void r041();
    virtual void r042();
    virtual void r043();
    virtual void r044();
    virtual void r045();
    virtual void r046();
    virtual void r047();
    virtual void r048();
    virtual void r049();
    virtual void r04a();
    virtual void r04b();
    virtual void r04c();
    virtual void r04d();
    virtual void r04e();
    virtual void r04f();
    virtual void r050();
    virtual void r051();
    virtual void r052();
    virtual void r053();
    virtual void r054();
    virtual void r055();
    virtual void r056();
    virtual void r057();
    virtual void r058();
    virtual void r059();
    virtual void r05a();
    virtual void r05b();
    virtual void r05c();
    virtual void r05d();
    virtual void r05e();
    virtual void r05f();
    virtual void r060();
    virtual void r061();
    virtual void r062();
    virtual void r063();
    virtual void r064();
    virtual void r065();
    virtual void r066();
    virtual void r067();
    virtual void r068();
    virtual void r069();
    virtual void r06a();
    virtual void r06b();
    virtual void r06c();
    virtual void r06d();
    virtual void r06e();
    virtual void r06f();
    virtual void r070();
    virtual void r071();
    virtual void r072();
    virtual void r073();
    virtual void r074();
    virtual void r075();
    virtual void r076();
    virtual void r077();
    virtual void r078();
    virtual void r079();
    virtual void r07a();
    virtual void r07b();
    virtual void r07c();
    virtual UsePoint* GetPos();
    virtual void r07e();
    virtual void r07f();
    virtual void r080();
    virtual void r081();
    virtual void r082();
    virtual void r083();
    virtual void r084();
    virtual void r085();
    virtual bool FUN_vt218();
    virtual void r087();
    virtual void r088();
    virtual void r089();
    virtual void r08a();
    virtual void r08b();
    virtual void r08c();
    virtual void r08d();
    virtual void r08e();
    virtual void r08f();
    virtual void r090();
    virtual void r091();
    virtual void r092();
    virtual void r093();
    virtual void r094();
    virtual void r095();
    virtual void r096();
    virtual void r097();
    virtual void r098();
    virtual void r099();
    virtual void r09a();
    virtual void r09b();
    virtual void r09c();
    virtual void r09d();
    virtual void r09e();
    virtual void r09f();
    virtual void r0a0();
    virtual void r0a1();
    virtual void r0a2();
    virtual void r0a3();
    virtual void r0a4();
    virtual void r0a5();
    virtual void r0a6();
    virtual void r0a7();
    virtual void r0a8();
    virtual void r0a9();
    virtual void r0aa();
    virtual void r0ab();
    virtual void r0ac();
    virtual void r0ad();
    virtual void r0ae();
    virtual void r0af();
    virtual void r0b0();
    virtual void r0b1();
    virtual void r0b2();
    virtual void r0b3();
    virtual void r0b4();
    virtual void r0b5();
    virtual void r0b6();
    virtual void r0b7();
    virtual void r0b8();
    virtual void r0b9();
    virtual void r0ba();
    virtual void r0bb();
    virtual void r0bc();
    virtual void r0bd();
    virtual void r0be();
    virtual void r0bf();
    virtual void r0c0();
    virtual void r0c1();
    virtual void r0c2();
    virtual void r0c3();
    virtual void r0c4();
    virtual void r0c5();
    virtual void r0c6();
    virtual void r0c7();
    virtual void r0c8();
    virtual void r0c9();
    virtual void r0ca();
    virtual void r0cb();
    virtual void r0cc();
    virtual void r0cd();
    virtual void r0ce();
    virtual void r0cf();
    virtual void r0d0();
    virtual void r0d1();
    virtual void r0d2();
    virtual void r0d3();
    virtual void r0d4();
    virtual void r0d5();
    virtual void r0d6();
    virtual void r0d7();
    virtual void r0d8();
    virtual void r0d9();
    virtual void r0da();
    virtual void r0db();
    virtual void r0dc();
    virtual void r0dd();
    virtual void r0de();
    virtual void r0df();
    virtual void r0e0();
    virtual void r0e1();
    virtual void r0e2();
    virtual void r0e3();
    virtual void r0e4();
    virtual void r0e5();
    virtual void r0e6();
    virtual void r0e7();
    virtual void r0e8();
    virtual void r0e9();
    virtual void r0ea();
    virtual void r0eb();
    virtual void r0ec();
    virtual void r0ed();
    virtual void r0ee();
    virtual void r0ef();
    virtual void r0f0();
    virtual void r0f1();
    virtual void r0f2();
    virtual void FUN_vt3cc(void* apItem);
    void* FUN_0084e3a0();
    struct UseEntry* FUN_008a2d40();
    bool FUN_00575450(void* apOwner);
    struct UseEntry* FUN_00576260(void* apItem, int aiCount);
    bool FUN_008b3bb0();
    UseCell* FUN_008d6f30();
    void FUN_00892e90(void* apItem);
    TESBoundObject* FUN_007af430();
    float FUN_005723b0(UseRef* apRef, int a2, int a3);
    UseProcess* FUN_008d8520();
    void FUN_0087faa0();
    int FUN_0055d310();
};

struct UseExtraList
{
    UseRef* FUN_0041c8d0();
};

struct UseExtraNode
{
    UseExtraList** FUN_006815c0();
};

struct UseEntry
{
    UseExtraNode* FUN_00559450();
    void* FUN_0044ddc0(UseExtraList* apXData, UseRef* apLocation, int aiCount, void* apOwner);
    void* FUN_0044ddc0(UseExtraList* apXData, int aiCount, UsePoint* apPos, int aiFlags);
    ~UseEntry();
};

struct UsePackageTarget
{
    UseRef* FUN_0067f390();
};

struct UsePackageLocation
{
    int FUN_00680020();
    int FUN_00680080();
    int FUN_0044ddc0();
};

struct UsePackage
{
    virtual void k000();
    virtual void k001();
    virtual void k002();
    virtual void k003();
    virtual void k004();
    virtual void k005();
    virtual void k006();
    virtual void k007();
    virtual void k008();
    virtual void k009();
    virtual void k00a();
    virtual void k00b();
    virtual void k00c();
    virtual void k00d();
    virtual void k00e();
    virtual void k00f();
    virtual void k010();
    virtual void k011();
    virtual void k012();
    virtual void k013();
    virtual void k014();
    virtual void k015();
    virtual void k016();
    virtual void k017();
    virtual void k018();
    virtual void k019();
    virtual void k01a();
    virtual void k01b();
    virtual void k01c();
    virtual void k01d();
    virtual void k01e();
    virtual void k01f();
    virtual void k020();
    virtual void k021();
    virtual void k022();
    virtual void k023();
    virtual void k024();
    virtual void k025();
    virtual void k026();
    virtual void k027();
    virtual void k028();
    virtual void k029();
    virtual void k02a();
    virtual void k02b();
    virtual void k02c();
    virtual void k02d();
    virtual void k02e();
    virtual void k02f();
    virtual void k030();
    virtual void k031();
    virtual void k032();
    virtual void k033();
    virtual void k034();
    virtual void k035();
    virtual void k036();
    virtual void k037();
    virtual void k038();
    virtual void k039();
    virtual void k03a();
    virtual void k03b();
    virtual void k03c();
    virtual void k03d();
    virtual void k03e();
    virtual void k03f();
    virtual void k040();
    virtual void k041();
    virtual void k042();
    virtual void k043();
    virtual void k044();
    virtual void k045();
    virtual void k046();
    virtual void k047();
    virtual void k048();
    virtual void k049();
    virtual void k04a();
    virtual void k04b();
    virtual void k04c();
    virtual void k04d();
    virtual void k04e();
    virtual bool IsPackageRunningForActor(UseRef* apActor, int a2, float afTime, bool abFlag);
    UsePackageTarget* FUN_0055b980();
    UsePackageLocation* FUN_00671d10();
    int FUN_00672930();
    int FUN_0041ca90();
    bool FUN_00674d40();
    float GetPackageResult(UseRef* apActor, bool abFlag);
    bool FUN_00441b00();
};

struct UseAcquire
{
    UseRef* pObject;
    void* pItem;
    ~UseAcquire();
};

struct UseAcquireList
{
    void* pHead;
    void* pNext;
    bool FUN_008256d0();
    UseAcquire** FUN_006815c0();
    void FUN_00905330(UseAcquire** appItem);
};

struct UseSetting
{
    float* FUN_00403e20();
};
extern UseSetting DAT_011cdbac;
extern UseSetting DAT_011cd82c;
extern UseRef* DAT_011dea3c;
extern void* DAT_011ca244;
extern void* DAT_011ca248;

struct UseProcess
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
    virtual void FUN_vt24(UseRef* apActor, int aiValue);
    virtual void p00a();
    virtual void p00b();
    virtual void p00c();
    virtual void p00d();
    virtual void p00e();
    virtual void p00f();
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
    virtual void p01a();
    virtual void p01b();
    virtual void p01c();
    virtual void p01d();
    virtual void p01e();
    virtual void p01f();
    virtual void p020();
    virtual void p021();
    virtual void p022();
    virtual bool FindPackageTarget(UseRef* apActor);
    virtual void p024();
    virtual void p025();
    virtual void p026();
    virtual void p027();
    virtual void p028();
    virtual void p029();
    virtual void p02a();
    virtual void p02b();
    virtual void p02c();
    virtual void p02d();
    virtual void p02e();
    virtual void p02f();
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
    virtual void p03a();
    virtual void p03b();
    virtual void p03c();
    virtual void p03d();
    virtual void p03e();
    virtual void p03f();
    virtual void p040();
    virtual void p041();
    virtual void p042();
    virtual void p043();
    virtual void p044();
    virtual void p045();
    virtual void FUN_vt118(int aiValue);
    virtual void p047();
    virtual void p048();
    virtual void p049();
    virtual void p04a();
    virtual void FUN_vt12c(UseRef* apRef);
    virtual void p04c();
    virtual void p04d();
    virtual void p04e();
    virtual void p04f();
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
    virtual void p05a();
    virtual void p05b();
    virtual void p05c();
    virtual void p05d();
    virtual void p05e();
    virtual void p05f();
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
    virtual void p06a();
    virtual void p06b();
    virtual void p06c();
    virtual void p06d();
    virtual void p06e();
    virtual void p06f();
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
    virtual void p07a();
    virtual void p07b();
    virtual void p07c();
    virtual void p07d();
    virtual void p07e();
    virtual void p07f();
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
    virtual void p08a();
    virtual UsePackage* GetCurrentPackage();
    virtual void p08c();
    virtual void FUN_vt234();
    virtual void p08e();
    virtual void p08f();
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
    virtual void p09a();
    virtual void p09b();
    virtual void p09c();
    virtual void p09d();
    virtual void p09e();
    virtual UsePackage* FUN_vt27c();
    virtual void p0a0();
    virtual void FUN_vt284(int aiValue);
    virtual void SetProcessTarget(UseRef* apActor, int aiIndex);
    virtual void p0a3();
    virtual void p0a4();
    virtual void FUN_vt294(UseRef* apActor);
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
    UseRef* pTarget;
    UseRef* m_pReference40;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    UseAcquireList kAcquireList;
    UseAcquire* m_pDetectionData60;

    bool FUN_0091c810(UseRef* apActor);
};

// @fnv 0x0091c810
bool UseProcess::FUN_0091c810(UseRef* apActor)
{
    UsePackage* pPackage = 0;
    pPackage = FUN_vt27c();
    if (!pPackage)
        return false;
    UseEntry* pEntryOut = apActor->FUN_008a2d40();
    bool bCreatedTmp = false;
    if (!pEntryOut && (!pTarget || (!pTarget->IsActor() && !apActor->FUN_00575450(pTarget->FUN_0084e3a0()))))
    {
        FindPackageTarget(apActor);
        if (!pTarget || (!pTarget->IsActor() && !apActor->FUN_00575450(pTarget->FUN_0084e3a0())))
        {
            SetProcessTarget(apActor, 1);
            if (!apActor->FUN_008b3bb0())
                FUN_vt294(apActor);
            return false;
        }
    }
    if (!pEntryOut && m_pDetectionData60 && m_pDetectionData60->pObject == apActor)
    {
        pEntryOut = apActor->FUN_00576260(m_pDetectionData60->pItem, 0);
        bCreatedTmp = true;
    }
    bool bTargetActor = false;
    if (pTarget && pTarget->IsActor() && pTarget != apActor)
    {
        bTargetActor = true;
        UseRef* pTargetActor = (UseRef*)dynamic_cast<Actor*>((TESObjectREFR*)pTarget);
        UsePackage* pTargetPackageRes = pTargetActor->FUN_008d8520()->GetCurrentPackage();
        if (pTarget != DAT_011dea3c &&
            (!pTargetPackageRes || (pTargetPackageRes->FUN_0041ca90() != 1 && !pTargetPackageRes->FUN_00674d40())))
        {
            FUN_vt284(0);
            return false;
        }
    }
    UsePoint kDelta = *apActor->GetPos();
    if (bTargetActor)
        kDelta = apActor->GetPos()->FUN_00439ef0(*pTarget->GetPos());
    float fRangeEntry = 0.0f;
    UseRef* pRangeTargetTmp = 0;
    UsePoint kFromVal;
    UsePoint kToInfo;
    int iMinDistanceNum;
    if (bTargetActor)
    {
        pRangeTargetTmp = pTarget;
        fRangeEntry = 0.0f;
        int iDistance = pPackage->FUN_00671d10()->FUN_0044ddc0();
        if (iDistance <= 0)
            iDistance = 200;
        if (pTarget == DAT_011dea3c && fRangeEntry == 0.0)
            fRangeEntry = iDistance;
        else if (fRangeEntry == 0.0 && apActor->FUN_008d6f30()->FUN_00425fd0())
            fRangeEntry = *DAT_011cdbac.FUN_00403e20();
        else if (fRangeEntry == 0.0)
            fRangeEntry = iDistance * *DAT_011cd82c.FUN_00403e20();
    }
    if (pPackage->FUN_0055b980() && pPackage->IsPackageRunningForActor(apActor, 0, -1.0f, false))
    {
        if (!bTargetActor)
        {
            UsePackageTarget* pPackageTarget = pPackage->FUN_0055b980();
            UsePackageLocation* pPackageLocationTmp = pPackage->FUN_00671d10();
            if (pEntryOut)
            {
                UseExtraList* pXData = 0;
                if (pEntryOut->FUN_00559450())
                    pXData = *pEntryOut->FUN_00559450()->FUN_006815c0();
                void* pOwner = 0;
                if (pXData && pXData->FUN_0041c8d0())
                    pOwner = pXData->FUN_0041c8d0()->FUN_0084e3a0();
                UseRef* pLocationCur = pPackage->FUN_0055b980()->FUN_0067f390();
                if (!pLocationCur)
                    pLocationCur = m_pReference40;
                if (pLocationCur && pLocationCur->FUN_0055d310())
                {
                    apActor->FUN_00892e90(
                        pEntryOut->FUN_0044ddc0(pXData, pLocationCur, pPackage->FUN_00672930(), pOwner));
                }
                else
                {
                    if (pEntryOut->FUN_00559450())
                        pXData = *pEntryOut->FUN_00559450()->FUN_006815c0();
                    UsePoint* pPos = 0;
                    if (pPackageTarget)
                    {
                        UseRef* pContainer = pPackageTarget->FUN_0067f390();
                        if (!pContainer)
                            pContainer = m_pReference40;
                        if (pContainer &&
                            (pContainer->FUN_007af430() == DAT_011ca244 || pContainer->FUN_007af430() == DAT_011ca248))
                            pPos = pContainer->GetPos();
                    }
                    int iCount = 1;
                    if (!pPackageLocationTmp->FUN_00680020())
                        iCount = pPackage->FUN_00672930();
                    apActor->FUN_vt3cc(pEntryOut->FUN_0044ddc0(pXData, iCount, pPos, 0));
                }
                delete pEntryOut;
                if (pPackageLocationTmp->FUN_00680080() == 0xc ||
                    (pPackageLocationTmp->FUN_00680080() >= 0x13 && pPackageLocationTmp->FUN_00680080() <= 0x17))
                {
                    while (!kAcquireList.FUN_008256d0())
                    {
                        m_pDetectionData60 = *kAcquireList.FUN_006815c0();
                        kAcquireList.FUN_00905330(&m_pDetectionData60);
                        FUN_vt12c(m_pDetectionData60->pObject);
                        pEntryOut = apActor->FUN_00576260(m_pDetectionData60->pItem, 0);
                        delete m_pDetectionData60;
                        m_pDetectionData60 = 0;
                        if (pLocationCur && pLocationCur->FUN_0055d310())
                        {
                            apActor->FUN_00892e90(
                                pEntryOut->FUN_0044ddc0(pXData, pLocationCur, pPackage->FUN_00672930(), pOwner));
                        }
                        else
                        {
                            if (pEntryOut->FUN_00559450())
                                pXData = *pEntryOut->FUN_00559450()->FUN_006815c0();
                            UsePoint* pItemPosTmp = 0;
                            if (pPackageTarget)
                            {
                                UseRef* pItemContainer = pPackageTarget->FUN_0067f390();
                                if (!pItemContainer)
                                    pItemContainer = m_pReference40;
                                if (pItemContainer && (pItemContainer->FUN_007af430() == DAT_011ca244 ||
                                                       pItemContainer->FUN_007af430() == DAT_011ca248))
                                    pItemPosTmp = pItemContainer->GetPos();
                            }
                            int iItemCount = 1;
                            if (!pPackageLocationTmp->FUN_00680020())
                                iItemCount = pPackage->FUN_00672930();
                            apActor->FUN_vt3cc(pEntryOut->FUN_0044ddc0(pXData, iItemCount, pItemPosTmp, 0));
                        }
                        delete pEntryOut;
                        pEntryOut = 0;
                    }
                    bool bUpdateA = true;
                    bool bUpdateB = true;
                    if (GetCurrentPackage() && GetCurrentPackage()->FUN_00441b00())
                        bUpdateB = false;
                    if (apActor->FUN_vt218())
                    {
                        TESNPC* pNPC = dynamic_cast<TESNPC*>(apActor->FUN_007af430());
                        if (pNPC)
                            pNPC->FUN_006047c0((::Actor*)apActor, bUpdateA, bUpdateB, 0, 1);
                    }
                    else
                    {
                        TESCreature* pCreature = dynamic_cast<TESCreature*>(apActor->FUN_007af430());
                        if (pCreature)
                            pCreature->FUN_005f9e00((::Actor*)apActor, bUpdateA, bUpdateB, 1);
                    }
                }
                FUN_vt118(1);
            }
            SetProcessTarget(apActor, 1);
        }
        else
        {
            if (kDelta.FUN_00457990() <= fRangeEntry && kFromVal.FUN_00457990() <= kToInfo.FUN_00457990())
            {
                SetProcessTarget(apActor, 1);
                UseRef* m_pReference = pTarget;
                if (m_pReference->FUN_008d8520()->FUN_vt27c())
                {
                    m_pReference->FUN_008d8520()->SetProcessTarget(apActor, 1);
                    if (m_pReference->FUN_008d8520()->FUN_vt27c()->FUN_00674d40())
                    {
                        m_pReference->FUN_008d8520()->FUN_vt234();
                        if (m_pReference->FUN_008b3bb0())
                            m_pReference->FUN_0087faa0();
                        FUN_vt118(1);
                        FUN_vt24(apActor, 0);
                        return false;
                    }
                }
            }
        }
        if (!apActor->FUN_008b3bb0())
            FUN_vt294(apActor);
        return false;
    }
    iMinDistanceNum = (int)GetCurrentPackage()->GetPackageResult(apActor, false);
    if (pTarget && pTarget->IsActor())
    {
        if (apActor->FUN_005723b0(pTarget, 0, 0) < iMinDistanceNum)
        {
        }
    }
    return false;
}

}
struct PackageTargetData
{
    TESObjectREFR* FUN_00680020();
};
struct PackageMethods : TESPackage
{
    PackageTargetData* FUN_00671d10();
    bool FUN_00678ec0(Actor*);
    TESObjectREFR* FUN_006780e0(Actor*, int);
};
struct SpecificPackage : TESPackage
{
    TESObjectREFR* FUN_008d80e0();
};
struct PackageRuntime
{
    TESObjectREFR* FUN_009f3390();
};
TESObjectREFR* FUN_009f2d40(Actor*, TESPackage*);
struct ProcessTarget : MiddleHighProcess
{
    TESObjectREFR* FUN_0091ae00(Actor*, TESPackage*, PackageTargetData*);
    PackageRuntime* FUN_008d0430();
    TESObjectREFR* FUN_0091ab30(Actor*, TESPackage*);
};
struct S00926350_CharController
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    DummyFlags flags;
};
struct S00926350_SaveLoadGame
{
    unsigned char FUN_008df040();
};
struct S00926350_Target926350 : MiddleHighProcess
{
    unsigned short FUN_00926350(Actor* actor);
};

using ::TESForm;
using ::TESObjectREFR;
using ::Actor;
using ::MiddleHighProcess;
using ::TESNPC;

namespace OrderAcquireGlobals {
extern int DAT_011e0e80;
}

struct PackageTargetObj
{

    ~PackageTargetObj();

    TESObjectREFR* rememberedCharacter;

    TESForm* form;

    bool shouldEquip;

    bool shouldRemove;

    unsigned short queueFlags;

    void* extraData;

    unsigned int operationHandle;

    int operationAuxiliary;

    int operationState;
};

struct Reference0091 : TESObjectREFR
{

    bool FUN_00566950();

    TESForm* FUN_00567790();

    int FUN_00569160();

    void FUN_00564db0(int);

    void* FUN_004181e0(TESForm*);
};

struct Package0091
{

    bool FUN_008e30e0();

    bool IsFlag400Set();

    bool FUN_008e3100();
};

struct Actor0091 : Actor
{

    int FUN_00891d70();

    bool FUN_00493bb0();

    bool FUN_00891db0(int, int, int, int, unsigned int*);

    void FUN_005723b0(TESObjectREFR*, int, int);

    TESForm* FUN_007af430();

    bool FUN_00566950();
};

struct EquippedList0091
{
    PackageTargetObj** FUN_006815c0();
    EquippedList0091* FUN_00726070();
    void FUN_00470470();
    void FUN_00905820(PackageTargetObj**);
};

struct EquipCheckingObject0091
{

    bool FUN_0047f600();
};

struct EquipBase0091
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
    EquipCheckingObject0091 equipment;
};

struct EquipRegistry0091
{

    TESObjectREFR* FUN_00970a20(TESNPC*, int);
};

extern int DAT_011ca268;

extern int DAT_01183028;

extern int DAT_01183a1c;

int __cdecl FUN_0048e8a0(TESForm*);

unsigned int __cdecl FUN_00ec43fb(int, int, int*, int*, int);

unsigned int __cdecl FUN_00ec62c0();

struct MiddleHigh0091 : MiddleHighProcess
{

    void FUN_0091b580();

    void FUN_0091b640();

    void FUN_0091b700(Actor*);
};

// @fnv 0x0091b700
void MiddleHigh0091::FUN_0091b700(Actor* apActor)

{

    EquippedList0091* package = reinterpret_cast<EquippedList0091*>(&m_kDetectionDataList);

    Package0091* position = reinterpret_cast<Package0091*>(GetOneTimePackage());

    bool allowEquip = position ? position->FUN_008e30e0() : false;

    bool allowMove = position ? position->IsFlag400Set() : false;

    bool allowRemove = position ? position->FUN_008e3100() : false;

    while (package && *package->FUN_006815c0())
    {

        TESForm* form;
        PackageTargetObj* item = reinterpret_cast<PackageTargetObj*>(*package->FUN_006815c0());

        Reference0091* rememberedCharacter = reinterpret_cast<Reference0091*>(item->rememberedCharacter);
        Reference0091* livingReference = 0;

        Reference0091* reference = rememberedCharacter->IsActor() ? rememberedCharacter : 0;

        form = item->form;

        bool changed = false;

        bool save = true;

        if (reference && reference->FUN_00566950())
        {

            save = false;
        }

        if (rememberedCharacter->FUN_00567790() || rememberedCharacter->IsActor())
        {

            bool remove = false;

            bool equip = false;

            int required = FUN_0048e8a0(form);

            TESNPC* matchedHandle = 0;

            if (!rememberedCharacter->Unk_8B(false) &&
                reinterpret_cast<Actor0091*>(apActor)->FUN_00891d70() >= required)
            {

                Reference0091* matched = 0;

                if (rememberedCharacter->IsCharacter())
                {

                    matched = rememberedCharacter;
                }
                else
                {

                    matchedHandle = dynamic_cast<TESNPC*>(rememberedCharacter->FUN_00567790());

                    if (matchedHandle)
                    {

                        matched = reinterpret_cast<Reference0091*>(
                            reinterpret_cast<EquipRegistry0091*>(&OrderAcquireGlobals::DAT_011e0e80)
                                ->FUN_00970a20(matchedHandle, 0));
                    }
                }

                if (matched && allowEquip)
                {

                    if (reinterpret_cast<EquipBase0091*>(matched->FUN_004181e0(form))->equipment.FUN_0047f600())
                    {

                        if (reinterpret_cast<Actor0091*>(apActor)->FUN_00891d70() >= FUN_0048e8a0(item->form))
                        {

                            if (!reinterpret_cast<Actor0091*>(apActor)->FUN_00493bb0())
                            {

                                item->operationState = 2;

                                reinterpret_cast<Actor0091*>(apActor)->FUN_005723b0(rememberedCharacter, 0, 0);

                                item->operationHandle = FUN_00ec62c0();

                                changed = true;
                            }
                            else
                            {

                                save = false;
                            }
                        }
                    }
                }
            }

            if (!changed && (!reference || !reference->FUN_00566950()))
            {

                if (!rememberedCharacter->IsActor())
                {

                    if (allowMove)
                        remove = true;
                }
                else if (rememberedCharacter->Unk_8B(false))
                {

                    save = true;
                }
                else if (rememberedCharacter->IsCharacter())
                {
                    livingReference = rememberedCharacter;

                    if (allowMove)
                        remove = true;

                    if (allowRemove)
                        equip = true;
                }

                if ((remove || equip) && (!reference || !reference->FUN_00566950()))
                {

                    if (!rememberedCharacter->IsActor())
                    {

                        if (item->operationState == 1)
                        {

                            unsigned int operationResult = 0;

                            item->operationState = 4;

                            bool success = reinterpret_cast<Actor0091*>(apActor)->FUN_00891db0(DAT_011ca268, 0, 1, 0,
                                                                                               &operationResult);

                            if (!success && rememberedCharacter->FUN_00569160())
                                save = false;
                        }
                        else
                        {

                            item->operationState = 3;
                        }
                    }
                    else if (remove)
                    {

                        if (!reinterpret_cast<Actor0091*>(apActor)->FUN_00493bb0())
                            item->operationState = 4;

                        else
                            save = false;
                    }
                    else if (equip)
                    {

                        if (!reinterpret_cast<Actor0091*>(apActor)->FUN_00493bb0() &&
                            !reinterpret_cast<Actor0091*>(apActor)->FUN_00566950())
                        {

                            if (!reference || (reference && !reference->FUN_00566950()))

                                item->operationState = 5;
                        }
                        else
                        {

                            save = false;
                        }
                    }

                    item->shouldEquip = remove;

                    item->shouldRemove = equip;
                }
                else
                {

                    if (reinterpret_cast<Actor0091*>(apActor)->Unk_87())
                    {

                        save = false;
                    }
                    else if (rememberedCharacter->IsActor() && !rememberedCharacter->IsCharacter() &&

                             rememberedCharacter->FUN_00567790() !=
                                 reinterpret_cast<Actor0091*>(apActor)->FUN_007af430() &&

                             !reinterpret_cast<Actor0091*>(apActor)->FUN_00566950())
                    {

                        if (reference && !reference->FUN_00566950())
                        {

                            item->operationState = 5;

                            save = true;
                        }
                    }
                    else
                    {

                        save = false;
                    }
                }
            }
        }
        else
        {

            reinterpret_cast<Actor0091*>(apActor)->FUN_005723b0(rememberedCharacter, 0, 0);

            item->operationHandle = FUN_00ec62c0();
        }

        if (save)
        {

            reinterpret_cast<Reference0091*>(item->rememberedCharacter)->FUN_00564db0(1);

            reinterpret_cast<EquippedList0091*>(&ReferenceListNode)->FUN_00905820(&item);
        }
        else
        {

            delete item;
        }

        package = reinterpret_cast<EquippedList0091*>(package->FUN_00726070());
    }

    FUN_0091b580();

    FUN_0091b640();

    reinterpret_cast<EquippedList0091*>(&m_kDetectionDataList)->FUN_00470470();
}
