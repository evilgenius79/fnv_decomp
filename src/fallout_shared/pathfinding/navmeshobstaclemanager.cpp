
#include "navmeshobstaclemanager_decls.h"
// Locks the manager's lock, appends task to the array at offset 0x14c, then unlocks.
// @fnv 0x006c4f70
void NavMeshObstacleManager::AddProcessedTask(ObstacleTaskData* task)
{
    ((RecursiveSpinLock*)((char*)this + 0x160))->Lock("NavMeshObstacleManager::AddProcessedTask()");
    ((BSSimpleArray<NavMeshInfo*, 1024>*)((char*)this + 0x14c))->Add((NavMeshInfo*&)task);
    ((RecursiveSpinLock*)((char*)this + 0x160))->Unlock();
}
// @fnv 0x006c4540
bool NavMeshObstacleManager::ClearBackgroundTasks()
{
    unsigned int size = ((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)this + 0x14c))->GetSize();
    for (unsigned int i = 0; i < size; i++)
    {
        delete (ObstacleTaskData*)((NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >*)((char*)this + 0x14c))
            ->GetAt(i);
    }
    ((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)this + 0x14c))->Clear(true);
    ((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)this + 0x13c))->Clear(true);
    return true;
}
// @fnv 0x006c4ec0
void NavMeshObstacleManager::QueueObstacleTasks()
{
    struct
    {
        TESFile* key;
        ObstacleTaskData* task;
        TESFile* iterator;
    } locals;
    locals.iterator = (TESFile*)((BGSReconstructFormsInAllFilesMap*)((char*)this + 0x12c))->GetFirstPos();
    while (locals.iterator)
    {
        ((BGSReconstructFormsInAllFilesMap*)((char*)this + 0x12c))
            ->GetNext((void*&)locals.iterator, locals.key, (BGSReconstructFormsInFileMap*&)locals.task);
        if (((SettingT<INISettingCollection>*)&g_011d71a0)->Bool()->b)
            ProcessObstacleTask(locals.task);
        else
        {
            ((RecursiveSpinLock*)((char*)this + 0x160))->Lock(0);
            ((BSSimpleArray<NavMeshInfo*, 1024>*)((char*)this + 0x13c))->Add((NavMeshInfo*&)locals.task);
            ((RecursiveSpinLock*)((char*)this + 0x160))->Unlock();
            locals.task->Run();
        }
    }
    ((NiTPointerMap<unsigned int, unsigned int>*)((char*)this + 0x12c))->RemoveAll();
}
// @fnv 0x006c47e0
void NavMeshObstacleManager::ClearObstacles()
{
    BSSimpleList<BGSPerkEntry*>* item = (BSSimpleList<BGSPerkEntry*>*)((char*)this + 0x34);
    while (item && !((BSSimpleList<BGSCameraShot*>*)item)->IsEmpty())
    {
        unsigned int auiFormId = (unsigned int)item->GetItem();
        item = item->GetNext();
        NiPointer<AnimIdle> spReference((AnimIdle*)0);
        if (((NiTMapBase<DFALL<NiTMapItem<bhkRigidBody*, NiPointer<ObstacleData> > >, bhkRigidBody*,
                         NiPointer<ObstacleData> >*)((char*)this + 0x1c))
                ->GetAt((bhkRigidBody*)auiFormId, (NiPointer<ObstacleData>&)spReference))
        {
            for (unsigned int i = 0;
                 i < ((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)(AnimIdle*)spReference + 0xc))->GetSize();
                 i++)
            {
                ((BSSimpleList<NiPointer<ObstacleData> >*)((char*)this + 0x3c))
                    ->Remove((const NiPointer<
                              ObstacleData>&)((NiTArray<TESObjectREFR*,
                                                        NiTNewInterface<TESObjectREFR*> >*)((char*)(AnimIdle*)
                                                                                                spReference +
                                                                                            0xc))
                                 ->GetAt(i));
            }
        }
        RemoveObstaclesForReference(auiFormId);
    }
    ((BSSimpleList<ActorCause*>*)((char*)this + 0x34))->RemoveAll();
}

struct S4ee810
{
    int base;
    int x;
    void GlobalObject_00633c90(int);
    S4ee810* FUN_004ee810();
};
// Calls GlobalObject_00633c90 with 0, sets x to 0, and returns this.
// @fnv 0x004ee810
S4ee810* S4ee810::FUN_004ee810()
{
    GlobalObject_00633c90(0);
    x = 0;
    return this;
}

struct DummyStruct_00631820
{
    void* m_pObject;
    bool IsNotEqual(const DummyStruct_00631820& ptr) const;
};

// @fnv 0x00631820
bool DummyStruct_00631820::IsNotEqual(const DummyStruct_00631820& aOther) const
{
    return m_pObject != aOther.m_pObject;
}

struct FUN_006c07d0_shell : public NavMeshObstacleManager
{
    bool FUN_006c07d0();
};

void* __cdecl operator new(unsigned int);

struct BSWin32TaskletManager
{
    bool GetTaskletValue(void*);
};

BSWin32TaskletManager& __cdecl GetTaskletManager(void);

struct Struct_128
{
    bool FUN_006c08e0();
};

struct Struct_120
{
    int dummy;
    Struct_120()
    {
        FUN_006c00b0();
    }
    void FUN_006c00b0();
};

struct Struct_124
{
    int dummy;
    Struct_124()
    {
        FUN_006c0210();
    }
    void FUN_006c0210();
};

// Checks the tasklet manager and the object at offset 0x128, then allocates two objects stored at offsets 0x120 and 0x124; returns false on either check failing.
// @fnv 0x006c07d0
bool FUN_006c07d0_shell::FUN_006c07d0()
{
    if (!GetTaskletManager().GetTaskletValue((char*)this + 0x128))
        return false;
    if (!((Struct_128*)((char*)this + 0x128))->FUN_006c08e0())
        return false;
    *(Struct_120**)((char*)this + 0x120) = new Struct_120;
    *(Struct_124**)((char*)this + 0x124) = new Struct_124;
    return true;
}

class BSWin32TaskletManager;
BSWin32TaskletManager& __cdecl GetTaskletManager(void);

struct FUN_00b00ae0_shell
{
    void FUN_00b00ae0(void*);
};

// @fnv 0x006c08e0
void __fastcall FUN_006c08e0(void* pThis)
{
    reinterpret_cast<FUN_00b00ae0_shell&>(GetTaskletManager()).FUN_00b00ae0(pThis);
}

class BSWin32TaskletManager;
BSWin32TaskletManager& __cdecl GetTaskletManager(void);
void __fastcall FUN_00b00bc0(BSWin32TaskletManager*, int, void*);

struct Dummy006c09d0
{
    void f();
};
typedef void (Dummy006c09d0::*MemFn)(void*);

// @fnv 0x006c09d0
void __fastcall FUN_006c09d0(void* pThis)
{
    ((void(__thiscall*)(BSWin32TaskletManager*, void*)) & FUN_00b00bc0)(&GetTaskletManager(), pThis);
}

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
struct BGSTextureSet;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BipedAnim;
struct CHUNK;
struct CellMopp;
struct GameFormRecord;
struct TeleportableReference;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanIntegerAccessor;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct MagicCaster;
struct MagicTarget;
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
struct NiPoint3;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
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
struct TESFullName;
struct TESGlobal;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESObjectARMO;
struct TESObjectCELL;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESFormList;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESSound;
struct FileEntryList;
struct TESTopic;
struct TESTopicInfo;
struct TESWaterForm;
struct TESWorldSpace;
struct DistantTreeTextureInfo;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkNiCollisionObject;
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
struct FUN_006c0f10_shell : public NavMeshObstacleManager
{
    void UpdateDoorObstacle(TESObjectREFR*);
};

struct TESObjectDOOR;
TESBoundObject* __fastcall _FNV_GetObjectReference(TESObjectREFR*);
unsigned int __fastcall _FNV_GetFormType(TESBoundObject*);
bool __fastcall FUN_00518080(TESObjectDOOR*);
bhkRigidBody* __fastcall _ref_0084e3a0(TESObjectREFR*);

struct Call_006c0c80
{
    void FUN_006c0c80(TESObjectREFR*);
};
struct Call_00905330
{
    void _ref_00905330(bhkRigidBody**);
};
class GlobalObject_0044fae0
{
  public:
    GlobalObject_0044fae0();
    ~GlobalObject_0044fae0();
    char m_acData[0x18];
};
class FUN_006c5fc0
{
  public:
    FUN_006c5fc0(unsigned int uiSize);
    ~FUN_006c5fc0();
    int m_kNextStreamField[4];
};
class GlobalObject2_0096a2d0
{
  public:
    GlobalObject2_0096a2d0();
    ~GlobalObject2_0096a2d0();
    void* m_pkItem;
    void* m_pkNext;
};
class GlobalObject_004ee810
{
  public:
    GlobalObject_004ee810();
    ~GlobalObject_004ee810();
    int m_kNextStreamField[9];
};
template <class T> class LockFreeQueue
{
  public:
    LockFreeQueue(unsigned int uiSize, unsigned int uiGrow);
    ~LockFreeQueue();
    int m_kNextStreamField[16];
};
class FUN_006c6070
{
  public:
    FUN_006c6070(unsigned int uiSize);
    ~FUN_006c6070();
    int m_kNextStreamField[4];
};
class GlobalObject_0044dee0
{
  public:
    GlobalObject_0044dee0();
    ~GlobalObject_0044dee0();
    int m_iData;
};
class FUN_006c60a0
{
  public:
    FUN_006c60a0(unsigned int uiSize);
    ~FUN_006c60a0();
    int m_kNextStreamField[4];
};
class FUN_006c6c10
{
  public:
    FUN_006c6c10();
    ~FUN_006c6c10();
    int m_kNextStreamField[4];
};
class StrList
{
  public:
    StrList();
    void* m_pkItem;
    void* m_pkNext;
};
class GlobalObject_00633c90
{
  public:
    GlobalObject_00633c90(int iValue);
    ~GlobalObject_00633c90();
    void* m_pPointer;
};
class GlobalObject_0045d260
{
  public:
    GlobalObject_0045d260(const char* pcCategory, const char* pcName, int iEnabled, int iVisible);
    bool m_bValue;
};
class AutoMemContext
{
  public:
    AutoMemContext(MEM_CONTEXT aeMemoryContext, bool bPush, const char* pcFile, int iLine);
    ~AutoMemContext();
    int m_iContext;
};
struct GlobalObject_0044dee0_d00483710 : GlobalObject_0044dee0
{
    ~GlobalObject_0044dee0_d00483710();
};
class FUN_006c02c0 : public GlobalObject_0044fae0
{
  public:
    FUN_006c02c0();
    bool m_bModifierActive;
    FUN_006c5fc0 m_kTasks;
    GlobalObject2_0096a2d0 m_kAdded;
    GlobalObject2_0096a2d0 m_kRemoved;
    GlobalObject_004ee810 m_kLock;
    LockFreeQueue<bhkRigidBody*> m_kAddQueue;
    LockFreeQueue<bhkRigidBody*> m_kRemoveQueue;
    FUN_006c6070 m_kObstacles;
    GlobalObject2_0096a2d0 m_kPending;
    GlobalObject2_0096a2d0 m_kProcessed;
    FUN_006c5fc0 m_kTasksB;
    FUN_006c5fc0 m_kTasksC;
    int m_iCount120;
    int m_iCount124;
    GlobalObject_0044dee0_d00483710 m_kTimer;
    FUN_006c60a0 m_kRefMap;
    FUN_006c6c10 m_kQueueA;
    FUN_006c6c10 m_kQueueB;
    int m_iPad15C;
    StrList m_kRefs;
    int m_aiPad168[6];
    GlobalObject2_0096a2d0 m_kCurrent;
    GlobalObject2_0096a2d0 m_kDone;
    int m_iTask190;
    float m_fInterval;
    bool m_bPaused;
    char m_acPad199[3];
    GlobalObject_00633c90 m_spTask;
    GlobalObject_0045d260 m_kUpdateTimer;
    GlobalObject_0045d260 m_kBackgroundTimer;
};

// @fnv 0x006c0f10
void FUN_006c0f10_shell::UpdateDoorObstacle(TESObjectREFR* apDoorRef)
{
    typedef NiTMapBase<DFALL<NiTMapItem<bhkRigidBody*, NiPointer<ObstacleData> > >, bhkRigidBody*,
                       NiPointer<ObstacleData> >
        DoorMapType;

    TESBoundObject* pbaseObject = _FNV_GetObjectReference(apDoorRef);
    if (_FNV_GetFormType(pbaseObject) == 0x1c)
    {
        TESObjectDOOR* pdoor = (TESObjectDOOR*)pbaseObject;
        if (!FUN_00518080(pdoor))
        {
            ((Call_006c0c80*)this)->FUN_006c0c80(apDoorRef);
        }
    }

    GlobalObject_00633c90 spdummy(0);
    if (!((DoorMapType*)((char*)this + 0x100))->GetAt(_ref_0084e3a0(apDoorRef), *(NiPointer<ObstacleData>*)&spdummy))
    {
        Actor* id1 = (Actor*)_ref_0084e3a0(apDoorRef);
        if (((BSSimpleList<Actor*>*)((char*)this + 0xf8))->IsInList(id1))
        {
            bhkRigidBody* id2 = _ref_0084e3a0(apDoorRef);
            ((Call_00905330*)((char*)this + 0xf8))->_ref_00905330(&id2);
        }
    }

    if (!((DoorMapType*)((char*)this + 0x110))->GetAt(_ref_0084e3a0(apDoorRef), *(NiPointer<ObstacleData>*)&spdummy))
    {
        if (!((BSSimpleList<Actor*>*)((char*)this + 0xf0))->IsInList(*(Actor**)&apDoorRef))
        {
            ((BSSimpleList<char const*>*)((char*)this + 0xf0))->AddHead(*(char const**)&apDoorRef);
        }
    }
}

// @fnv 0x006c1170
void __fastcall FUN_006c1170(char* pThis)
{
    pThis[0x18] = 1;
}

namespace fnv_006c34f0 {
template <typename T> class BSStringT
{
  public:
    operator char const*() const;
};

void* __fastcall _ref_0084e3a0(void* _this);
void __cdecl ClearStringAndCheck(void* param1, BSStringT<char>* param2);

// Stores the result of _ref_0084e3a0(param1) at offset 8 of param2's string, then calls ClearStringAndCheck(param1, param2).
// @fnv 0x006c34f0
void __cdecl FUN_006c34f0(void* param1, BSStringT<char>* pString)
{
    *(void**)(const_cast<char*>(pString->operator char const*()) + 8) = _ref_0084e3a0(param1);
    ClearStringAndCheck(param1, pString);
}
}  // namespace fnv_006c34f0

struct BSStringT_char
{
    operator const char*() const;
};
struct Arr3520
{
    void RemoveAll(bool);
};
struct Obj3520
{
    void** vt;
};
typedef void*(__thiscall* Fn3520)(Obj3520*);
bool RegisterCollisionObstacles(void*, BSStringT_char*);
// @fnv 0x006c3520
bool ClearStringAndCheck(Obj3520* pObj, BSStringT_char* pString)
{
    ((Arr3520*)((const char*)*pString + 0xc))->RemoveAll(true);
    if (((Fn3520)pObj->vt[116])(pObj))
        return RegisterCollisionObstacles(((Fn3520)pObj->vt[116])(pObj), pString);
    else
        return false;
}

struct S6c4350
{
    int a;
    short b;
    int c;
    void _ref_006815c0();
    S6c4350* FUN_006c4350(const S6c4350& o);
};
// Calls _ref_006815c0, then copies fields a, b and c from o into this and returns this.
// @fnv 0x006c4350
S6c4350* S6c4350::FUN_006c4350(const S6c4350& aOther)
{
    _ref_006815c0();
    a = aOther.a;
    b = aOther.b;
    c = aOther.c;
    return this;
}

namespace fnv_006c44d0 {
struct FUN_006c44d0_shell : public NavMeshObstacleManager
{
    bool FUN_006c44d0();
};

bool __fastcall FUN_006c85e0(unsigned int);

struct TESObjectREFR
{
    unsigned int GetFlags(void);
};

template <> class BSSimpleArray<unsigned int, 1024>
{
  public:
    unsigned int& GetAt(unsigned int);
};

// Iterates the task array at this+0x14c, calls FUN_006c85e0 on each task, and returns whether any call succeeded.
// @fnv 0x006c44d0
bool FUN_006c44d0_shell::FUN_006c44d0()
{
    bool bNavmeshesUpdated = false;
    unsigned int icount = ((TESObjectREFR*)((char*)this + 0x14c))->GetFlags();
    for (unsigned int t = 0; t < icount; ++t)
    {
        unsigned int ptask = ((BSSimpleArray<unsigned int, 1024>*)((char*)this + 0x14c))->GetAt(t);
        if (FUN_006c85e0(ptask))
        {
            bNavmeshesUpdated = true;
        }
    }
    return bNavmeshesUpdated;
}
}  // namespace fnv_006c44d0

struct FUN_006c4900_shell : public NavMeshObstacleManager
{
    bool FUN_006c4900();
};

bool __fastcall _ref_008256d0(void* pThis);
int* __fastcall _ref_006815c0(void* pThis);
void __cdecl FUN_00694500(int, int);
BSSimpleList<int>* __fastcall _ref_00726070(void* pThis);

// Iterates the list at this+0x180, calls FUN_00694500 on each entry's value, then removes all entries and returns true.
// @fnv 0x006c4900
bool FUN_006c4900_shell::FUN_006c4900()
{
    BSSimpleList<int>* pCurrentElementNext = reinterpret_cast<BSSimpleList<int>*>(reinterpret_cast<char*>(this) + 0x180);
    while (pCurrentElementNext && !_ref_008256d0(pCurrentElementNext))
    {
        int meshID = *_ref_006815c0(pCurrentElementNext);
        FUN_00694500(meshID, 0);
        pCurrentElementNext = _ref_00726070(pCurrentElementNext);
    }
    reinterpret_cast<BSSimpleList<int>*>(reinterpret_cast<char*>(this) + 0x180)->RemoveAll();
    return true;
}

extern int DAT_0106c5d8;

// Sets pThis[0] to the address of DAT_0106c5d8 and pThis[1] to 0, then returns pThis.
// @fnv 0x006c5e40
int* __fastcall FUN_006c5e40(int* pObject)
{
    pObject[0] = (int)&DAT_0106c5d8;
    pObject[1] = 0;
    return pObject;
}

extern int DAT_0106c5d8;

// @fnv 0x006c5e70
void __fastcall FUN_006c5e70(int** ppObject)
{
    *ppObject = &DAT_0106c5d8;
}

namespace fnv_006c5ec0 {
struct TM6c5ec0
{
    void TryProcessPair(void*, void*, bool);
};
TM6c5ec0& __cdecl GetTaskletManager();
struct S6c5ec0
{
    void FUN_006c5ec0(void* task, bool last);
};
// Forwards this object, task and last to the tasklet manager's TryProcessPair.
// @fnv 0x006c5ec0
void S6c5ec0::FUN_006c5ec0(void* task, bool last)
{
    GetTaskletManager().TryProcessPair(this, task, last);
}
}  // namespace fnv_006c5ec0

extern int DAT_0106c5e0;

struct FUN_006c5fc0_shell
{
    void* vftable;
    void FUN_006c6260(unsigned int uiHashSize);
    FUN_006c5fc0_shell* FUN_006c5fc0(unsigned int uiHashSize);
};

// Calls FUN_006c6260 with uiHashSize, sets the vftable to DAT_0106c5e0, and returns this.
// @fnv 0x006c5fc0
FUN_006c5fc0_shell* FUN_006c5fc0_shell::FUN_006c5fc0(unsigned int uiHashSize)
{
    FUN_006c6260(uiHashSize);
    vftable = &DAT_0106c5e0;
    return this;
}

extern int DAT_0106c600;

struct FUN_006c6070_Class
{
    void* vftable;
    void FUN_006c68b0(unsigned int);
    void* FUN_006c6070(unsigned int uiHashSize);
};

// Calls FUN_006c68b0 with uiHashSize, sets the vftable to DAT_0106c600, and returns this.
// @fnv 0x006c6070
void* FUN_006c6070_Class::FUN_006c6070(unsigned int uiHashSize)
{
    FUN_006c68b0(uiHashSize);
    vftable = &DAT_0106c600;
    return this;
}

extern int DAT_01031fac;

struct FUN_006c60a0_arg
{
    unsigned int val;
};

void __fastcall FUN_005890c0(int* self, FUN_006c60a0_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x006c60a0
int* __fastcall FUN_006c60a0(int* self, FUN_006c60a0_arg aArg)
{
    FUN_005890c0(self, aArg);
    *self = (int)&DAT_01031fac;
    return self;
}

struct Item62d0
{
    Item62d0* next;
    unsigned int key;
    void* val;
};
struct Map62d0
{
    virtual ~Map62d0();
    virtual unsigned int HashFunction(unsigned int);
    virtual bool IsKeysEqual(unsigned int, unsigned int);
    int pad;
    Item62d0** buckets;
    bool FUN_006c62d0(unsigned int key, void** out);
};
struct Helper62d0
{
    Helper62d0& operator=(void* const&);
};
// Hashes the key, scans that bucket's chain for a matching key, and if found writes its value to out and returns true.
// @fnv 0x006c62d0
bool Map62d0::FUN_006c62d0(unsigned int key, void** out)
{
    unsigned int uiBucketIndex = HashFunction(key);
    {
        Item62d0* it = buckets[uiBucketIndex];
        while (it)
        {
            if (IsKeysEqual(key, it->key))
            {
                *(Helper62d0*)out = it->val;
                return true;
            }
            it = it->next;
        }
    }
    return false;
}

namespace fnv_006c6c10 {
class NavMeshInfo;
template <> class BSSimpleArray<NavMeshInfo*, 1024>
{
  public:
    void FUN_006b3eb0(unsigned int, bool);
};

// Sets the object's first field to the string "0rl" and calls FUN_006b3eb0(0, false) on the array, returning pThis.
// @fnv 0x006c6c10
void* __fastcall FUN_006c6c10(void* pThis)
{
    *reinterpret_cast<const char**>(pThis) = "0rl";
    reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(pThis)->FUN_006b3eb0(0, false);
    return pThis;
}
}  // namespace fnv_006c6c10

extern int DAT_0106c708;

struct GlobalObject_00869f00
{
    void Clear(bool);
};

// @fnv 0x006c6de0
void __fastcall FUN_006c6de0(GlobalObject_00869f00* pThis)
{
    *(int**)pThis = &DAT_0106c708;
    pThis->Clear(true);
}

struct PathingInfo
{
    PathingInfo();
    ~PathingInfo();
    virtual void v0();
    char pad[4];
};
struct FUN_006c6160_cls
{
    FUN_006c6160_cls();
    char pad[4];
};
struct FUN_006c1480_holder : public PathingInfo
{
    int f8;
    FUN_006c6160_cls m;
    FUN_006c1480_holder();
    virtual void v0();
};
// Initializes the holder by setting its f8 field to 0.
// @fnv 0x006c1480
FUN_006c1480_holder::FUN_006c1480_holder()
{
    f8 = 0;
}

namespace fnv_006c3570 {
struct NiPoint3
{
    float x;
    float y;
    float z;
    NiPoint3 operator-(const NiPoint3&) const;
};
struct Flt
{
    operator unsigned int() const;
};
NiPoint3* __cdecl FUN_004b3ae0(NiPoint3*, const NiPoint3&, const float*);
// @fnv 0x006c3570
bool FUN_006c3570(NiPoint3* pPoint, Flt* b, float c, float fMaxZ)
{
    NiPoint3 r;
    FUN_004b3ae0(&r, *pPoint - *(NiPoint3*)((unsigned int)*b + 0x10), (const float*)((unsigned int)*b + 0x1c));
    if (r.z < -c || r.z > fMaxZ)
        return false;
    if (r.x < *(float*)((unsigned int)*b + 0x40) || r.x > *(float*)((unsigned int)*b + 0x4c))
        return false;
    if (r.y < *(float*)((unsigned int)*b + 0x44) || r.y > *(float*)((unsigned int)*b + 0x50))
        return false;
    return true;
}
}  // namespace fnv_006c3570

struct ArrSI
{
    unsigned int GetFlags();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct FUN_006c4540_obj
{
    virtual ~FUN_006c4540_obj();
};
// Deletes every object stored in the array at this+0x14c, then clears the containers at this+0x14c and this+0x13c, returning true.
// @fnv 0x006c4540
bool __fastcall ClearOwnedObjects(char* this_ptr)
{
    unsigned int icount = ((ArrSI*)(this_ptr + 0x14c))->GetFlags();
    for (unsigned int t = 0; t < icount; t++)
    {
        delete (FUN_006c4540_obj*)*((Arr*)(this_ptr + 0x14c))->GetAt(t);
    }
    ((GlobalObject_00869f00*)(this_ptr + 0x14c))->Clear(true);
    ((GlobalObject_00869f00*)(this_ptr + 0x13c))->Clear(true);
    return true;
}

struct ProcessLists
{
    unsigned char* GetLifeStateControlFlag();
};
struct FUN_006c4ec0_vt
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
// @fnv 0x006c4ec0
void __fastcall ProcessObstacleTasks(NavMeshObstacleManager* pObstacleManager)
{
    void* taskIt;
    taskIt = ((BGSReconstructFormsInAllFilesMap*)((char*)pObstacleManager + 0x12c))->GetFirstPos();
    while (taskIt)
    {
        ObstacleTaskData* ptaskData;
        TESFile* formID;
        ((BGSReconstructFormsInAllFilesMap*)((char*)pObstacleManager + 0x12c))
            ->GetNext(taskIt, formID, (BGSReconstructFormsInFileMap*&)ptaskData);
        if (*((ProcessLists*)&g_011d71a0)->GetLifeStateControlFlag())
        {
            pObstacleManager->ProcessObstacleTask(ptaskData);
        }
        else
        {
            ((RecursiveSpinLock*)((char*)pObstacleManager + 0x160))->Lock(0);
            ((BSSimpleArray<void*, 1024>*)((char*)pObstacleManager + 0x13c))->Add((void*&)ptaskData);
            ((RecursiveSpinLock*)((char*)pObstacleManager + 0x160))->Unlock();
            ((FUN_006c4ec0_vt*)ptaskData)->v2();
        }
    }
    ((NiTPointerMap<unsigned int, unsigned int>*)((char*)pObstacleManager + 0x12c))->RemoveAll();
}

namespace fnv_006c5ef0 {
struct Flt
{
    operator unsigned int() const;
};
struct DummyPointerMap
{
    void SetAt(unsigned int, unsigned int);
    bool GetAt(unsigned int, unsigned int&) const;
};
struct FUN_006c77a0_cls
{
    FUN_006c77a0_cls(Flt*);
    char pad[0x58];
};
struct FUN_006c5ef0_arg
{
    Flt* nav;
};
// @fnv 0x006c5ef0
FUN_006c77a0_cls* __fastcall FUN_006c5ef0(char* this_ptr, FUN_006c5ef0_arg aNavArg)
{
    FUN_006c77a0_cls* ptask = 0;
    if (!((DummyPointerMap*)(this_ptr + 0x12c))->GetAt(*aNavArg.nav, (unsigned int&)ptask))
    {
        ptask = new FUN_006c77a0_cls(aNavArg.nav);
        ((DummyPointerMap*)(this_ptr + 0x12c))->SetAt(*aNavArg.nav, (unsigned int)ptask);
    }
    return ptask;
}
}  // namespace fnv_006c5ef0

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_004ee360(unsigned int flags);
};
// @fnv 0x004ee360
void* DelStandIn::FUN_004ee360(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

struct FUN_0042f830_struct
{
    void FUN_0042f9c0(unsigned char);
};
struct NavMeshArr
{
    virtual void Unused0();
    ~NavMeshArr();
};
namespace FUN_006c6ce0 {
struct FUN_006c6c60 : public NavMeshArr
{
    ~FUN_006c6c60();
};
}

// Destructor that calls FUN_0042f9c0 with argument 1 on this object.
// @fnv 0x006c6ce0
FUN_006c6ce0::FUN_006c6c60::~FUN_006c6c60()
{
    ((FUN_0042f830_struct*)this)->FUN_0042f9c0(1);
}

struct GO
{
    int v;
    GO(int);
    ~GO();
};

struct GO2
{
    int v;
    GO2(int);
};

struct B006815c0
{
    int a, b, c;
    B006815c0();
};

struct SA0
{
    int a, b, c, d;
    SA0();
    ~SA0();
};

struct PathingInfoX
{
    virtual ~PathingInfoX();
    int a, b;
    PathingInfoX();
};

struct FUN_006c23c0 : PathingInfoX
{
    GO go1;
    B006815c0 b0;
    B006815c0 b1;
    int pad1[6];
    B006815c0 b2;
    B006815c0 b3;
    B006815c0 b4;
    B006815c0 b5;
    int pad2;
    bool flag;
    SA0 arr;
    GO2 go2;
    FUN_006c23c0();
    virtual ~FUN_006c23c0();
};

// Constructs the object, initialising go1 and go2 to 0 and setting flag to true.
// @fnv 0x006c23c0
FUN_006c23c0::FUN_006c23c0() : go1(0), flag(true), go2(0)
{}

struct FUN_006c4c30_shell : public NavMeshObstacleManager
{
    void FUN_006c4c30();
};

struct ArrBox
{
    unsigned int GetFlags();
    unsigned int* GetAt(int);
};

struct ObstArr
{
    char pad[0xc];
    ArrBox arr;
};

struct SpArr
{
    ObstArr* p;
    SpArr(int);
    ~SpArr();
    operator ObstArr*() const;
};

struct SpObst
{
    void* p;
    SpObst(unsigned int*);
    ~SpObst();
};

struct MapX
{
    void* GetFirstPos();
    void FUN_00559120(void*&, unsigned int&, SpArr&);
};

struct MgrX
{
    void FUN_006c1760(SpObst&);
};

// @fnv 0x006c4c30
void FUN_006c4c30_shell::FUN_006c4c30()
{
    void* it = ((MapX*)((char*)this + 0x1c))->GetFirstPos();
    while (it)
    {
        unsigned int formID;
        SpArr spArray(0);
        ((MapX*)((char*)this + 0x1c))->FUN_00559120(it, formID, spArray);
        for (unsigned int i = 0; i < static_cast<ObstArr*>(spArray)->arr.GetFlags(); ++i)
        {
            SpObst m_spRegisteredObstacle(static_cast<ObstArr*>(spArray)->arr.GetAt(i));
            ((MgrX*)this)->FUN_006c1760(m_spRegisteredObstacle);
        }
    }
}

extern int DAT_011d6e2c;

// @fnv 0x00552ba0
int __cdecl FUN_00552ba0()
{
    return DAT_011d6e2c;
}

extern int DAT_0106c3c4;

struct FUN_006c0150_shell
{
    void FUN_006c0150();
};

// @fnv 0x006c0150
void FUN_006c0150_shell::FUN_006c0150()
{
    *reinterpret_cast<int*>(this) = (int)&DAT_0106c3c4;
}

struct G2
{
    void AddHead(int**);
};

struct FUN_006c1150_shell
{
    void FUN_006c1150(int* apParam);
};

// @fnv 0x006c1150
void FUN_006c1150_shell::FUN_006c1150(int* apParam)
{
    ((G2*)((char*)this + 0x188))->AddHead(&apParam);
}

struct FUN_006c5ff0_cls
{
    void FUN_006c5ff0(int* p);
};

struct FUN_006c1c70_shell
{
    char pad[0x60];
    void FUN_006c1c70(int arg);
};

// @fnv 0x006c1c70
void FUN_006c1c70_shell::FUN_006c1c70(int arg)
{
    ((FUN_006c5ff0_cls*)((char*)this + 0x60))->FUN_006c5ff0(&arg);
}

struct FUN_006c5ff0_shell
{
    void __thiscall FUN_006c5ff0(void* apArg);
};

void FUN_006c5ff0_shell::FUN_006c5ff0(void* apArg)
{}

struct FUN_006c1c90_shell
{
    void __thiscall ForwardToSubObject(void* apArg);
};

// @fnv 0x006c1c90
void FUN_006c1c90_shell::ForwardToSubObject(void* apArg)
{
    ((FUN_006c5ff0_shell*)((char*)this + 0xa0))->FUN_006c5ff0(&apArg);
}

struct ScriptLocalsX
{
    void* GetLocalData();
    void FUN_006c1dd0(void* arg);
};

struct FUN_00c9c700_target
{
    void FUN_00c9c700(void* arg);
};

// @fnv 0x006c1dd0
void ScriptLocalsX::FUN_006c1dd0(void* arg)
{
    void* result = GetLocalData();
    if (result)
        ((FUN_00c9c700_target*)result)->FUN_00c9c700(arg);
}

namespace fnv_006c1e40 {
struct ScriptLocalsX
{
    void* GetLocalData();
};

struct hkpEntity
{
    void FUN_00c9c670(void* arg1);
};

struct FUN_006c1e40_shell
{
    void FUN_006c1e40(void* arg1);
};

// @fnv 0x006c1e40
void FUN_006c1e40_shell::FUN_006c1e40(void* arg1)
{
    void* result = ((ScriptLocalsX*)this)->GetLocalData();
    if (result)
    {
        ((hkpEntity*)result)->FUN_00c9c670(arg1);
    }
}
}  // namespace fnv_006c1e40

namespace fnv_006c1e70 {
struct ScriptLocalsX
{
    int GetLocalData();
};

struct FUN_00c9c0f0_shell
{
    void RemoveListener(int a1);
};

struct FUN_006c1e70_shell
{
    void FUN_006c1e70(int a1);
};

// @fnv 0x006c1e70
void FUN_006c1e70_shell::FUN_006c1e70(int a1)
{
    int result = ((ScriptLocalsX*)this)->GetLocalData();
    if (result)
    {
        ((FUN_00c9c0f0_shell*)result)->RemoveListener(a1);
    }
}
}  // namespace fnv_006c1e70

extern "C" void __cdecl __Dummy_00b6fef0(void*, unsigned int);

struct ObstacleData_shell
{
    void __thiscall DestroyMembers();
    void* __thiscall FUN_006c2490(unsigned int flags);
};

// @fnv 0x006c2490
void* __thiscall ObstacleData_shell::FUN_006c2490(unsigned int flags)
{
    this->DestroyMembers();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0x8c);
    return this;
}

void __fastcall FUN_006c5e70(int**);
void __cdecl operator delete(void*);

struct FUN_006c5e90_shell
{
    void* __thiscall FUN_006c5e90(unsigned int flags);
};

// Calls FUN_006c5e70 on this object, deletes it when flags has bit 0 set, and returns this.
// @fnv 0x006c5e90
void* __thiscall FUN_006c5e90_shell::FUN_006c5e90(unsigned int flags)
{
    FUN_006c5e70((int**)this);
    if (flags & 1)
        operator delete(this);
    return this;
}

namespace fnv_006c0120 {
struct FUN_006c0150_shell
{
    void FUN_006c0150(void);
};

extern void _Deallocate(void*);

struct FUN_006c0120_shell : FUN_006c0150_shell
{
    void* FUN_006c0120(unsigned int flags);
};

// Calls FUN_006c0150, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x006c0120
void* FUN_006c0120_shell::FUN_006c0120(unsigned int flags)
{
    FUN_006c0150();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_006c0120

namespace fnv_006c0170 {
struct FUN_006c0150_shell
{
    void FUN_006c0150();
    void FUN_006c0170();
};

// @fnv 0x006c0170
void FUN_006c0150_shell::FUN_006c0170()
{
    FUN_006c0150();
}
}  // namespace fnv_006c0170

namespace fnv_006c1d60 {
struct ScriptLocalsX
{
    void __thiscall FUN_006c1dd0(void*);
    void __thiscall FUN_006c1da0(void*);
};

struct FUN_006c1d60_shell
{
    void __thiscall FUN_006c1d60(ScriptLocalsX* arg);
};

// Calls two methods on arg, passing the pointers stored at this+0x120 and this+0x124.
// @fnv 0x006c1d60
void __thiscall FUN_006c1d60_shell::FUN_006c1d60(ScriptLocalsX* arg)
{
    arg->FUN_006c1dd0(*(void**)(this + 0x120));
    arg->FUN_006c1da0(*(void**)(this + 0x124));
}
}  // namespace fnv_006c1d60

struct hkpEntity;
struct FUN_0061f580_shell
{
    const char* m_p;
    hkpEntity* FUN_0061f580();
};
// @fnv 0x0061f580
hkpEntity* FUN_0061f580_shell::FUN_0061f580()
{
    m_p = "pFU";
    return (hkpEntity*)this;
}

struct NavMeshClosedDoorInfo
{
    NavMeshClosedDoorInfo();
};
struct FUN_006923c0
{
    int f0;
    NavMeshClosedDoorInfo f4;
    FUN_006923c0();
};
// Initializes the object by setting f0 to -1.
// @fnv 0x006923c0
FUN_006923c0::FUN_006923c0()
{
    f0 = -1;
}

void __cdecl _Deallocate(void*);
struct Dummy
{
    void FUN_006c0170();
    void* FUN_006c00d0(unsigned int);
};
// Calls FUN_006c0170, then if the low bit of flags is set calls _Deallocate on this, and returns this.
// @fnv 0x006c00d0
void* Dummy::FUN_006c00d0(unsigned int flags)
{
    FUN_006c0170();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_006c01d0 {
void* __cdecl FUN_004b5a80(void const*);
struct hkpEntity
{
};
struct bhkRigidBody
{
};
struct FUN_006c1c70_shell
{
    void FUN_006c1c70(int);
};
struct bhkObstacleDeactivationListener
{
    void OnEntityDeactivated(hkpEntity*);
};
NavMeshObstacleManager* __cdecl MyGetSingleton();
// @fnv 0x006c01d0
void bhkObstacleDeactivationListener::OnEntityDeactivated(hkpEntity* entity)
{
    bhkRigidBody* pb;
    pb = (bhkRigidBody*)FUN_004b5a80(entity);
    if (pb)
    {
        ((FUN_006c1c70_shell*)MyGetSingleton())->FUN_006c1c70((int)pb);
    }
}
}  // namespace fnv_006c01d0

struct FUN_006c0210_shell
{
    int* vtbl;
    FUN_006c0210_shell();
    void FUN_0061f580();
};

extern int DAT_0106c3d4;

// @fnv 0x006c0210
FUN_006c0210_shell::FUN_006c0210_shell()
{
    FUN_0061f580();
    vtbl = &DAT_0106c3d4;
}

void __fastcall FUN_006c0260(void*);
void __cdecl _Deallocate(void*);
struct FUN_006c0230_shell
{
    void* FUN_006c0230(unsigned int);
};
// @fnv 0x006c0230
void* FUN_006c0230_shell::FUN_006c0230(unsigned int flags)
{
    FUN_006c0260(this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_006c0c30 {
union TSETTING_VALUE;
struct SettingT_GameSettingCollection_
{
    TSETTING_VALUE* Bool();
};
extern GlobalObject_0045cf30 g_011d73e4;
struct Actor;
struct LH
{
    bool IsInList(Actor*&);
};
struct G2
{
    void AddHead(int*);
};
struct Mgr006c0c30
{
    void FUN_006c0c30(Actor*);
};
// If the game setting is enabled and apRef is not already in the list at this+0x2c, adds apRef to the head of that list.
// @fnv 0x006c0c30
void Mgr006c0c30::FUN_006c0c30(Actor* apRef)
{
    if (!*(unsigned char*)(((SettingT_GameSettingCollection_*)&g_011d73e4)->Bool()))
        return;
    if (!((LH*)((char*)this + 0x2c))->IsInList(apRef))
        ((G2*)((char*)this + 0x2c))->AddHead((int*)&apRef);
}
}  // namespace fnv_006c0c30

namespace fnv_006c1130 {
struct G2
{
    void AddHead(int**);
};
struct FUN_006c1130_shell
{
    G2 m;
    void FUN_006c1130(int* p);
};
// @fnv 0x006c1130
void FUN_006c1130_shell::FUN_006c1130(int* pItem)
{
    ((G2*)((char*)this + 0x180))->AddHead(&pItem);
}
}  // namespace fnv_006c1130

struct ReferenceObstacleArray
{
    void FUN_006c1520();
    void* DestroyIfFlagged(unsigned int);
};
void _delete(void*, unsigned int);
// @fnv 0x006c14f0
void* ReferenceObstacleArray::DestroyIfFlagged(unsigned int flags)
{
    this->FUN_006c1520();
    if (flags & 1)
        _delete(this, 0x1c);
    return this;
}

namespace fnv_006c1da0 {
struct ScriptLocalsX
{
    void* GetLocalData();
    void FUN_006c1da0(int);
};
struct S_00c9c5b0
{
    void FUN_00c9c5b0(int);
};
// @fnv 0x006c1da0
void ScriptLocalsX::FUN_006c1da0(int a)
{
    void* p = GetLocalData();
    if (p)
        ((S_00c9c5b0*)p)->FUN_00c9c5b0(a);
}
}  // namespace fnv_006c1da0

struct S_param
{
    void FUN_006c1e70(int);
    void FUN_006c1e40(int);
};
struct S_this
{
    char _pad[0x120];
    int f120;
    int f124;
    void FUN_006c1e00(S_param*);
};
// @fnv 0x006c1e00
void S_this::FUN_006c1e00(S_param* apParam)
{
    apParam->FUN_006c1e70(f120);
    apParam->FUN_006c1e40(f124);
}

struct C006c6fe0
{
    bool FUN_006c6fe0();
};
struct C00449f80
{
    C006c6fe0* FUN_00449f80(void*);
};
struct C006c6030
{
    bool FUN_006c6030(void*);
};
// Locks the object at offset 0x20, calls FUN_00449f80 on a1 and FUN_006c6fe0 on the result, unlocks, and returns that bool.
// @fnv 0x006c6030
bool C006c6030::FUN_006c6030(void* apArg)
{
    ((RecursiveSpinLock*)((char*)this + 0x20))->Lock(0);
    bool b = ((C00449f80*)this)->FUN_00449f80(apArg)->FUN_006c6fe0();
    ((RecursiveSpinLock*)((char*)this + 0x20))->Unlock();
    return b;
}

namespace fnv_006c0260 {
extern void* DAT_0106c3d4;
struct FUN_00554650_shell
{
    void FUN_00554650();
};
struct FUN_006c0260_shell
{
    void FUN_006c0260();
};
// @fnv 0x006c0260
void FUN_006c0260_shell::FUN_006c0260()
{
    *(void**)this = &DAT_0106c3d4;
    ((FUN_00554650_shell*)this)->FUN_00554650();
}
}  // namespace fnv_006c0260

namespace fnv_006c1ea0 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct TES
{
    TESObjectCELL* GetDetailedActorPathHandler();
};
extern TES* g_TES;
bool __fastcall FUN_00425fd0(TESObjectCELL*);
class TESWorldSpace
{
  public:
    TESObjectCELL* GetCellAtGridPosition(int, int);
};
class DoorCell
{
  public:
    TESWorldSpace* GetParentWorldSpace();
};
struct Flt
{
    operator unsigned int();
};
bool __cdecl DoBoundsOverlap(const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&);
struct NiPoint3Ex
{
    float x;
    float y;
    float z;
    NiPoint3Ex(float, float, float);
};
extern float _DAT_01015f5c;

// @fnv 0x006c1ea0
bool __cdecl CollectCellsNearObstacle(Flt& kObstacle, BSSimpleArray<void*, 1024>* pCells)
{
    ((GlobalObject_00869f00*)pCells)->Clear(false);
    TESObjectCELL* pCell = g_TES->GetDetailedActorPathHandler();
    if (!pCell)
        return false;
    if (FUN_00425fd0(pCell))
    {
        pCells->Add(reinterpret_cast<void*&>(pCell));
    }
    else
    {
        int m_iGridPositionX = (int)*(float*)((unsigned int)kObstacle + 0x10) >> 12;
        int m_iGridCoordinateY = (int)*(float*)((unsigned int)kObstacle + 0x14) >> 12;
        for (int x = m_iGridPositionX - 1; x <= m_iGridPositionX + 1; x++)
        {
            for (int y = m_iGridCoordinateY - 1; y <= m_iGridCoordinateY + 1; y++)
            {
                TESObjectCELL* pAdjCell = ((DoorCell*)pCell)->GetParentWorldSpace()->GetCellAtGridPosition(x, y);
                if (pAdjCell && pAdjCell->IsOutdoorCell())
                {
                    NiPoint3Ex kMinBoundsCur((float)(x << 12), (float)(y << 12), _DAT_01015f5c);
                    NiPoint3Ex kMaxPoint((float)(kMinBoundsCur.x + 4096.0), (float)(kMinBoundsCur.y + 4096.0), 3.402823466e+38F);
                    if (DoBoundsOverlap(*(NiPoint3*)&kMinBoundsCur, *(NiPoint3*)&kMaxPoint,
                                        *(NiPoint3*)((unsigned int)kObstacle + 0x58),
                                        *(NiPoint3*)((unsigned int)kObstacle + 0x64)))
                        pCells->Add(reinterpret_cast<void*&>(pAdjCell));
                }
            }
        }
    }
    return true;
}
}  // namespace fnv_006c1ea0

namespace fnv_006c2050 {
struct Flt
{
    void* p;
    operator unsigned int();
};
struct NavMeshPtr : Flt
{
    ~NavMeshPtr();
};
struct S2f850
{
    unsigned int AppendValue(const NavMeshPtr&);
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct EffectSetting
{
    int GetEffectID();
};
struct FUN_006969e0_shell
{
    bool FUN_006969e0(NiPoint3*, NiPoint3*);
};
struct NMA
{
    NavMeshPtr GetNavMeshAt(unsigned int);
};
struct P3Ctor
{
    void _ref_006815c0();
};
struct CellArr
{
    CellArr(unsigned int, unsigned int, unsigned int);
    ~CellArr();
    void* a;
    void* b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
};
int __fastcall GetReferenceFlags(void*);
bool __cdecl CollectCellsNearObstacle(const Flt*, CellArr*);
bool __cdecl DoBoundsOverlap(const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&);

// @fnv 0x006c2050
bool FUN_006c2050(const Flt* apData, S2f850* apReturnNavMeshArray)
{
    NiPoint3 navmeshMin;
    ((P3Ctor*)&navmeshMin)->_ref_006815c0();
    NiPoint3 navmeshMax;
    ((P3Ctor*)&navmeshMax)->_ref_006815c0();
    CellArr cells(0x20, 0, 0);
    if (CollectCellsNearObstacle(apData, &cells))
    {
        for (unsigned int i = 0; i < ((ArrSI*)&cells)->GetFlags(); i++)
        {
            NMA* parray = (NMA*)((EffectSetting*)*((Arr*)&cells)->GetAt(i))->GetEffectID();
            if (parray)
            {
                for (unsigned int j = 0; j < (unsigned int)GetReferenceFlags(parray); j++)
                {
                    if (((FUN_006969e0_shell*)(unsigned int)parray->GetNavMeshAt(j))
                            ->FUN_006969e0(&navmeshMin, &navmeshMax))
                    {
                        navmeshMax.z += 128.0;
                        if (DoBoundsOverlap(navmeshMin, navmeshMax, *(NiPoint3*)((unsigned int)*(Flt*)apData + 0x58),
                                            *(NiPoint3*)((unsigned int)*(Flt*)apData + 0x64)))
                        {
                            apReturnNavMeshArray->AppendValue(parray->GetNavMeshAt(j));
                        }
                    }
                }
            }
        }
    }
    return true;
}
}  // namespace fnv_006c2050

namespace fnv_006c2210 {
class NiAVObject;
struct NavMeshPtr
{
    void* m_pObject;
};
struct Flt : NavMeshPtr
{
    operator unsigned int();
};
struct GO : Flt
{
    GO(int);
    ~GO();
    void operator=(void*);
};
struct bhkFilter
{
    bhkFilter();
    unsigned int uiFilterInfo;
    int FUN_0043b4d0();
};
struct bhkWorldObject
{
    bhkFilter FUN_0043b4f0();
};
struct bhkCollisionObject
{
    static bhkCollisionObject* __cdecl GetFromNiAVObject(NiAVObject*);
    bhkWorldObject* FUN_006fa820();
};
struct NiNode
{
    unsigned int GetNumChildren();
    NiAVObject* GetAt(unsigned int);
};
struct Obj_006c2210
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual NiNode* IsSceneNode();
};
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct FUN_006c23c0 : BSFadeNode
{
    FUN_006c23c0();
    char pad[0x8c];
};
struct Obstacle_006c2210
{
    char pad[8];
    unsigned int uiOwner;
    GO m_pGameObject;
};
struct S2f850
{
    unsigned int FUN_006c61b0(const NavMeshPtr&);
};
struct Owner_006c2210
{
    char pad[0xc];
    S2f850 kArray;
};
void __cdecl UpdateObstacleBounds(unsigned int);

// @fnv 0x006c2210
bool __cdecl RegisterCollisionObstacles(NiAVObject* apObject, Flt* apOwner)
{
    NiNode* pkNode;
    {
        bhkCollisionObject* pCollision = bhkCollisionObject::GetFromNiAVObject(apObject);
        if (pCollision)
        {
            bhkWorldObject* pWorldObject = pCollision->FUN_006fa820();
            if (pWorldObject)
            {
                int iLayer = pWorldObject->FUN_0043b4f0().FUN_0043b4d0();
                if (iLayer == 2 || iLayer == 4 || iLayer == 10 || iLayer == 0x14 || iLayer == 0x1c)
                {
                    GO m_spRegisteredObstacle((int)new FUN_006c23c0);
                    ((Obstacle_006c2210*)(unsigned int)m_spRegisteredObstacle)->uiOwner = (unsigned int)*apOwner;
                    ((Obstacle_006c2210*)(unsigned int)m_spRegisteredObstacle)->m_pGameObject = pWorldObject;
                    UpdateObstacleBounds((unsigned int)m_spRegisteredObstacle);
                    ((Owner_006c2210*)(unsigned int)*apOwner)->kArray.FUN_006c61b0(m_spRegisteredObstacle);
                }
            }
        }
    }
    pkNode = ((Obj_006c2210*)apObject)->IsSceneNode();
    if (pkNode)
    {
        for (unsigned int i = 0; i < pkNode->GetNumChildren(); i++)
        {
            if (pkNode->GetAt(i))
                RegisterCollisionObstacles(pkNode->GetAt(i), apOwner);
        }
    }
    return true;
}
}  // namespace fnv_006c2210

namespace fnv_006c47e0 {
struct FUN_006c47e0_shell : public NavMeshObstacleManager
{
    void FUN_006c47e0();
};

class BSTempEffect;
struct UList;
bool __fastcall _ref_008256d0(UList*);
unsigned int* __fastcall _ref_006815c0(UList*);
struct GridArray
{
    int GetCenterX() const;
};
struct GO
{
    void* p;
    GO(int);
    ~GO();
};
struct FGModelMap
{
    bool GetAt(void*, GO&);
};
struct Flt
{
    operator unsigned int();
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct List_009e03e0
{
    void RemoveAll();
};
// @fnv 0x006c47e0
void FUN_006c47e0_shell::FUN_006c47e0()
{
    UList* pNode = (UList*)((char*)this + 0x34);
    while (pNode && !_ref_008256d0(pNode))
    {
        unsigned int prefID = *_ref_006815c0(pNode);
        pNode = (UList*)((GridArray*)pNode)->GetCenterX();
        GO spArray(0);
        if (((FGModelMap*)((char*)this + 0x1c))->GetAt((void*)prefID, spArray))
        {
            for (unsigned int i = 0; i < ((ArrSI*)((unsigned int)*(Flt*)&spArray + 0xc))->GetFlags(); i++)
                ((BSSimpleList<NiPointer<BSTempEffect> >*)((char*)this + 0x3c))
                    ->Remove(*(NiPointer<BSTempEffect>*)((Arr*)((unsigned int)*(Flt*)&spArray + 0xc))->GetAt(i));
        }
        RemoveObstaclesForReference(prefID);
    }
    ((List_009e03e0*)((char*)this + 0x34))->RemoveAll();
}
}  // namespace fnv_006c47e0

namespace fnv_006c4fb0 {
struct FUN_006c4fb0_shell : public NavMeshObstacleManager
{
    bool ProcessDoorObstacles();
};

struct UNode;
bool __fastcall _ref_008256d0(void*);
unsigned int* __fastcall _ref_006815c0(UNode*);
UNode* __fastcall _ref_00726070(UNode*);
struct GO
{
    GO(int);
    ~GO();
    void* p;
};
struct Flt
{
    operator unsigned int();
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct FGModelMap
{
    bool GetAt(void*, GO&);
};
struct MapH
{
    bool RemoveAt(unsigned int);
};
struct SpObst
{
    SpObst(unsigned int*);
    SpObst(const SpObst&);
    ~SpObst();
    void* p;
};
struct Map6920
{
    void FUN_006c6920(unsigned int, SpObst);
};
struct List_009e03e0
{
    void RemoveAll();
};
struct ObstacleTaskData_Op : ObstacleTaskData
{
    bool AddOperation(const unsigned int&, int);
};
struct FUN_006c5ef0_shell
{
    ObstacleTaskData_Op* FUN_006c5ef0(unsigned int);
};

// Iterates the node list at this+0xf8, adds operations for each door found in the map at this+0x110, removes those entries, then clears the list and returns true.
// @fnv 0x006c4fb0
bool FUN_006c4fb0_shell::ProcessDoorObstacles()
{
    UNode* pCurrentElementNext;
    if (_ref_008256d0((char*)this + 0xf8))
        return false;
    pCurrentElementNext = (UNode*)((char*)this + 0xf8);
    while (pCurrentElementNext)
    {
        unsigned int doorId = *_ref_006815c0(pCurrentElementNext);
        pCurrentElementNext = _ref_00726070(pCurrentElementNext);
        GO spArray(0);
        if (((FGModelMap*)((char*)this + 0x110))->GetAt((void*)doorId, spArray))
        {
            unsigned int i;
            for (i = 0; i < ((ArrSI*)((unsigned int)*(Flt*)&spArray + 0xc))->GetFlags(); i++)
            {
                unsigned int j;
                for (j = 0;
                     j < ((ArrSI*)((unsigned int)*(Flt*)((Arr*)((unsigned int)*(Flt*)&spArray + 0xc))->GetAt(i) + 0x78))
                             ->GetFlags();
                     j++)
                {
                    ((FUN_006c5ef0_shell*)this)
                        ->FUN_006c5ef0(
                            *((Arr*)((unsigned int)*(Flt*)((Arr*)((unsigned int)*(Flt*)&spArray + 0xc))->GetAt(i) +
                                     0x78))
                                 ->GetAt(j))
                        ->AddOperation(*((Arr*)((unsigned int)*(Flt*)&spArray + 0xc))->GetAt(i), 0x40);
                }
            }
            ((MapH*)((char*)this + 0x110))->RemoveAt(doorId);
            ((Map6920*)((char*)this + 0x100))->FUN_006c6920(doorId, (unsigned int*)&spArray);
        }
    }
    ((List_009e03e0*)((char*)this + 0xf8))->RemoveAll();
    return true;
}
}  // namespace fnv_006c4fb0

namespace fnv_006c5ce0 {
struct BSTaskletData;
struct FUN_006c5ce0_shell : public NavMeshObstacleManager
{
    bool FUN_006c5ce0(ObstacleTaskData*);
};

void FUN_0040fca0(unsigned long);
bool FUN_009a3830(const int*, const int*);
namespace FUN_006c5e40 {
struct FUN_006c5e70
{
    unsigned int data[2];
    FUN_006c5e70();
    ~FUN_006c5e70();
};
}
struct TESRaceForm
{
    void Initialize(unsigned int);
};
struct LS3de0
{
    unsigned int Find(unsigned int&, unsigned int, bool (*)(const int*, const int*));
};
struct GlobalObject_00869f00
{
    void Remove(unsigned int, bool);
};
struct FUN_006c5ec0_s
{
    bool FUN_006c5ec0(FUN_006c5e40::FUN_006c5e70&, int);
};
// @fnv 0x006c5ce0
bool FUN_006c5ce0_shell::FUN_006c5ce0(ObstacleTaskData* apTaskData)
{
    FUN_006c5e40::FUN_006c5e70 task;
    reinterpret_cast<TESRaceForm*>(&task)->Initialize((unsigned int)apTaskData);
    ((RecursiveSpinLock*)((char*)this + 0x160))->Lock(0);
    ((BSSimpleArray<void*, 1024>*)((char*)this + 0x13c))->Add((void*&)apTaskData);
    ((RecursiveSpinLock*)((char*)this + 0x160))->Unlock();
    const unsigned int iMaxAttachTaskAttempts = 100;
    unsigned int itryCount = 0;
    while (!((FUN_006c5ec0_s*)((char*)this + 0x128))->FUN_006c5ec0(task, 0))
    {
        itryCount++;
        if (itryCount >= iMaxAttachTaskAttempts)
        {
            ((RecursiveSpinLock*)((char*)this + 0x160))->Lock(0);
            unsigned int iremoveIndex =
                ((LS3de0*)((char*)this + 0x13c))->Find((unsigned int&)apTaskData, 0, FUN_009a3830);
            if (iremoveIndex != -1)
                ((GlobalObject_00869f00*)((char*)this + 0x13c))->Remove(iremoveIndex, true);
            ((RecursiveSpinLock*)((char*)this + 0x160))->Unlock();
            return false;
        }
        FUN_0040fca0(0);
    }
    return true;
}
}  // namespace fnv_006c5ce0

namespace fnv_006c39c0 {
struct FUN_006c39c0_shell : public NavMeshObstacleManager
{
    void ForceUpdate();
};

void __cdecl FUN_0040fca0(unsigned long);
struct ATM
{
    void QueryPerformanceCounter(const char*);
    void WaitForTasksDuringRendering();
};
struct PathManager
{
    static PathManager* GetRandomGenerator();
    void FUN_006ebcd0();
};
struct FUN_006ebc70_shell
{
    void FUN_006ebc70();
};
struct FUN_006ebc90_shell
{
    bool FUN_006ebc90();
};
struct ScriptLocals
{
    void ProcessPendingTasks();
};
struct CellX
{
    unsigned char FUN_00552bb0();
    void FUN_006a5ca0();
};
CellX* __cdecl FUN_00552ba0();
struct NMOM
{
    unsigned int GetProcessedTaskCount();
    unsigned int GetBackgroundTaskCount();
    void MatchPortalEdges();
    void FUN_006c44d0();
    void ProcessAddedRefs();
    void FUN_006c47e0();
    void FUN_006c4d30();
    void ProcessDoorObstacles();
    void FUN_006c5190();
    void ProcessObstacleTasks();
};
struct FUN_006c4c30_shell
{
    void FUN_006c4c30();
};
bool __fastcall ClearOwnedObjects(char*);
extern float DAT_0106c398;

// Waits for processed and background task counts to match, runs path manager and navmesh update steps, resets offset 0x190/0x194, and waits for rendering tasks.
// @fnv 0x006c39c0
void FUN_006c39c0_shell::ForceUpdate()
{
    unsigned int iProcessedTaskCount;
    unsigned int iBackgroundTaskCount;
    ((ATM*)this)->QueryPerformanceCounter("NavMeshObstacleManager::ForceUpdate()");
    iProcessedTaskCount = ((NMOM*)this)->GetProcessedTaskCount();
    iBackgroundTaskCount = ((NMOM*)this)->GetBackgroundTaskCount();
    while (iProcessedTaskCount != iBackgroundTaskCount)
    {
        FUN_0040fca0(0);
        iProcessedTaskCount = ((NMOM*)this)->GetProcessedTaskCount();
        iBackgroundTaskCount = ((NMOM*)this)->GetBackgroundTaskCount();
    }
    ((FUN_006ebc70_shell*)PathManager::GetRandomGenerator())->FUN_006ebc70();
    while (!((FUN_006ebc90_shell*)PathManager::GetRandomGenerator())->FUN_006ebc90())
        ((ScriptLocals*)PathManager::GetRandomGenerator())->ProcessPendingTasks();
    ((NMOM*)this)->MatchPortalEdges();
    ((NMOM*)this)->FUN_006c44d0();
    ClearOwnedObjects((char*)this);
    ((NMOM*)this)->ProcessObstacleTasks();
    iProcessedTaskCount = ((NMOM*)this)->GetProcessedTaskCount();
    iBackgroundTaskCount = ((NMOM*)this)->GetBackgroundTaskCount();
    while (iProcessedTaskCount != iBackgroundTaskCount)
    {
        FUN_0040fca0(0);
        iProcessedTaskCount = ((NMOM*)this)->GetProcessedTaskCount();
        iBackgroundTaskCount = ((NMOM*)this)->GetBackgroundTaskCount();
    }
    ((NMOM*)this)->MatchPortalEdges();
    ((NMOM*)this)->FUN_006c44d0();
    ClearOwnedObjects((char*)this);
    ((NMOM*)this)->FUN_006c47e0();
    ((NMOM*)this)->ProcessAddedRefs();
    ((FUN_006c4c30_shell*)this)->FUN_006c4c30();
    ((NMOM*)this)->FUN_006c4d30();
    ((NMOM*)this)->ProcessDoorObstacles();
    ((NMOM*)this)->FUN_006c5190();
    ((NMOM*)this)->ProcessObstacleTasks();
    iProcessedTaskCount = ((NMOM*)this)->GetProcessedTaskCount();
    iBackgroundTaskCount = ((NMOM*)this)->GetBackgroundTaskCount();
    while (iProcessedTaskCount != iBackgroundTaskCount)
    {
        FUN_0040fca0(0);
        iProcessedTaskCount = ((NMOM*)this)->GetProcessedTaskCount();
        iBackgroundTaskCount = ((NMOM*)this)->GetBackgroundTaskCount();
    }
    ((NMOM*)this)->MatchPortalEdges();
    ((NMOM*)this)->FUN_006c44d0();
    ClearOwnedObjects((char*)this);
    *(int*)((char*)this + 0x190) = 0;
    *(float*)((char*)this + 0x194) = DAT_0106c398;
    if (FUN_00552ba0()->FUN_00552bb0())
        FUN_00552ba0()->FUN_006a5ca0();
    PathManager::GetRandomGenerator()->FUN_006ebcd0();
    ((ATM*)this)->WaitForTasksDuringRendering();
}
}  // namespace fnv_006c39c0

namespace fnv_006c45e0 {
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
struct BipedAnim;
struct CHUNK;
struct CellMopp;
struct GameFormRecord;
struct TeleportableReference;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanIntegerAccessor;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct MagicCaster;
struct MagicTarget;
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
struct NiPoint3;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
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
struct TESModel;
struct TESObjectARMO;
struct TESObjectCELL;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkNiCollisionObject;
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
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct TESChildCell
{
    virtual TESObjectCELL* GetSaveParentCell();
};
typedef char _sizecheck_TESChildCell[sizeof(TESChildCell) == 4 ? 1 : -1];
struct FUN_006c45e0_shell : public NavMeshObstacleManager
{
    void ProcessAddedRefs();
};

namespace FUN_005e04c0 {
struct FUN_005e04f0
{
    unsigned int unk00;
    void* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    FUN_005e04f0();
    ~FUN_005e04f0();
};
}
struct GO
{
    void* p;
    GO(int);
    ~GO();
};
struct Flt
{
    operator unsigned int();
};
namespace FUN_006c23c0 {
struct FUN_006c24d0
{
    unsigned int unk00, unk04, unk08;
    Flt form;
    unsigned int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44,
        unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84,
        unk88;
    FUN_006c24d0();
    ~FUN_006c24d0();
};
}
struct FUN_008256d0_s
{
    bool FUN_008256d0();
};
struct FUN_006815c0_s
{
    TESObjectREFR** FUN_006815c0();
};
struct Map62d0
{
    bool FUN_006c62d0(unsigned int, GO&);
};
struct FUN_006c1920_s
{
    void RebuildRefObstacles(unsigned int, TESObjectREFR*);
};
struct FUN_006c1190_s
{
    void RegisterKey(TESObjectREFR*);
};
struct FUN_00905330_s
{
    void FUN_00905330(unsigned int*);
};
struct ListStand
{
    ListStand* FUN_00726070();
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct RefStand
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
    virtual void* GetData();
};
struct FormStand
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
    virtual int IsQuestItem();
};
struct FormIDView_006c45e0
{
    unsigned int GetFormID();
};
bool FindNodeData(void*, FUN_006c23c0::FUN_006c24d0*);
// @fnv 0x006c45e0
void FUN_006c45e0_shell::ProcessAddedRefs()
{
    FUN_005e04c0::FUN_005e04f0 addedRefs;
    ListStand* pCurrentElementNext = (ListStand*)((char*)this + 0x2c);
    while (pCurrentElementNext && !((FUN_008256d0_s*)pCurrentElementNext)->FUN_008256d0())
    {
        TESObjectREFR* pref = *((FUN_006815c0_s*)pCurrentElementNext)->FUN_006815c0();
        pCurrentElementNext = pCurrentElementNext->FUN_00726070();
        GO spArray(0);
        if (((Map62d0*)((char*)this + 0x1c))->FUN_006c62d0(((FormIDView_006c45e0*)pref)->GetFormID(), spArray))
        {
            ((FUN_006c1920_s*)this)->RebuildRefObstacles(((FormIDView_006c45e0*)pref)->GetFormID(), pref);
            ((BSSimpleArray<void*, 1024>*)&addedRefs)->Add((void*&)pref);
        }
        else if (((RefStand*)pref)->GetData())
        {
            FUN_006c23c0::FUN_006c24d0 refData;
            if (FindNodeData(((RefStand*)pref)->GetData(), &refData))
            {
                if (((FormStand*)(unsigned int)refData.form)->IsQuestItem())
                {
                    ((FUN_006c1190_s*)this)->RegisterKey(pref);
                    ((BSSimpleArray<void*, 1024>*)&addedRefs)->Add((void*&)pref);
                }
            }
        }
    }
    for (unsigned int i = 0; i < ((ArrSI*)&addedRefs)->GetFlags(); i++)
        ((FUN_00905330_s*)((char*)this + 0x2c))->FUN_00905330(((Arr*)&addedRefs)->GetAt(i));
}
}  // namespace fnv_006c45e0

class Tile;
class Flt
{
  public:
    operator unsigned int();
};
class TL : public Flt
{
  public:
    Tile*& GetNext(void*& pos);
};
class Tile
{
  public:
    int m_iWordAt00;
    TL m_kList;
    float GetFloat(int id);
    void Set(int id, int value);
    void Set(int id, const char* str, bool b);
    const char* GetString(int id);
    bool ContainsTrait(int id);
    const char* FUN_00700300();
};
struct NiPoint2
{
    float x, y;
    NiPoint2(float fx, float fy);
    NiPoint2 Subtract(const NiPoint2& o) const;
    NiPoint2& Scale(float f);
    float FUN_00589850() const;
};
class SoundPlaybackHandle
{
  public:
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    ~SoundPlaybackHandle();
    bool Play(bool b);
};
class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    SoundPlaybackHandle GetSoundHandleByEditorID(const char* name, unsigned int flags);
};
int GetTileValueID(const char* name, int id);
int __stricmp(const char* a, const char* b);
const char* FUN_00ec7750(const char* s, const char* sub);
extern const double DAT_01074f60;
extern int DAT_011da348;
extern int DAT_011da34c;
extern int DAT_011da350;

struct FUN_00799dc0_class
{
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
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    Tile* m_pTile40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    Tile* m_pTile54;
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
    Tile* m_pMapTile;
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
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    Tile* m_pHighlighted;
    void UpdateMapHighlight();
};

// Finds the nearest map marker tile to the cursor within range, marks it highlighted, plays a sound and updates the title and highlight state.
// @fnv 0x00799dc0
void FUN_00799dc0_class::UpdateMapHighlight()
{
    if (!m_pMapTile)
        return;
    NiPoint2 kCursor(m_pTile40->GetFloat(0xfa1) + m_pTile40->GetFloat(0xfb1) / 2.0,
                     m_pTile40->GetFloat(0xfa2) + m_pTile40->GetFloat(0xfb0) / 2.0);
    Tile* pBest;
    {
        void* pos = (void*)(unsigned int)m_pMapTile->m_kList;
        float fClosest = 3.402823466e+38F;
        pBest = 0;
        kCursor.x -= m_pMapTile->GetFloat(0xfa1);
        kCursor.y -= m_pMapTile->GetFloat(0xfa2);
        while (pos)
        {
            Tile* pTile = m_pMapTile->m_kList.GetNext(pos);
            if (pTile->GetFloat(0xfaa) == DAT_01074f60 && !FUN_00ec7750(pTile->FUN_00700300(), " Marker"))
            {
                NiPoint2 kPos(pTile->GetFloat(DAT_011da350), pTile->GetFloat(DAT_011da34c));
                float fDist = 0.0f;
                kPos.Scale(m_pMapTile->GetFloat(0xfb1));
                fDist = kCursor.Subtract(kPos).FUN_00589850();
                if (fDist < fClosest && m_pTile40->GetFloat(0xfb0) / 2.0 > fDist)
                {
                    fClosest = fDist;
                    pBest = pTile;
                }
                pTile->Set(DAT_011da348, 0);
            }
        }
    }
    if (pBest)
    {
        pBest->Set(DAT_011da348, 1);
        if (pBest != m_pHighlighted)
        {
            BSAudio::GetSingleton()->GetSoundHandleByEditorID("UIPipBoyHighlight", 0x121).Play(false);
            if (__stricmp(pBest->GetString(GetTileValueID("_LocationName", -1)), "Companion"))
                m_pTile40->Set(GetTileValueID("_Title", -1), pBest->GetString(GetTileValueID("_LocationName", -1)),
                               true);
            m_pHighlighted = pBest;
            m_pTile54->Set(0xfaf, pBest->ContainsTrait(0x1004));
        }
    }
    else
    {
        m_pTile40->Set(GetTileValueID("_Title", -1), "", true);
        m_pHighlighted = 0;
        m_pTile54->Set(0xfaf, 0);
    }
}

namespace fnv_00807790 {
struct FUN_006234b0
{
    FUN_006234b0();
    ~FUN_006234b0();
    virtual void v0();
};
struct FUN_0061f580
{
    FUN_0061f580();
    ~FUN_0061f580();
    virtual void v0();
};
struct FUN_006c0100
{
    FUN_006c0100();
    ~FUN_006c0100();
    virtual void v0();
};
struct CF845
{
    unsigned int uiFlags;
    CF845(int i);
};
struct ScriptLocalsX
{
    void FUN_008078b0(void* p);
    void FUN_006c1da0(void* p);
    void FUN_006c1dd0(void* p);
};
struct FUN_00807790 : public FUN_006234b0, public FUN_0061f580, public FUN_006c0100
{
    int m_0c;
    ScriptLocalsX* m_10;
    CF845 m_kFlags;
    bool m_18;
    FUN_00807790(int a1, ScriptLocalsX* a2, unsigned int a3);
};

// @fnv 0x00807790
FUN_00807790::FUN_00807790(int a1, ScriptLocalsX* a2, unsigned int auiFlags) : m_kFlags(0)
{
    m_0c = a1;
    m_10 = a2;
    m_kFlags.uiFlags = auiFlags;
    m_18 = false;
    m_10->FUN_008078b0(this);
    m_10->FUN_006c1da0(static_cast<FUN_0061f580*>(this));
    m_10->FUN_006c1dd0(static_cast<FUN_006c0100*>(this));
}
}  // namespace fnv_00807790

namespace fnv_006c1cb0 {
struct bhkRigidBody;
struct TESObjectREFR;

struct GO
{
    unsigned int value;

    GO(int);
    ~GO();
    operator unsigned int() const;
};

struct FGModelMap
{
    bool GetAt(void*, GO&);
};

struct ReferenceObstacleArray
{
    unsigned int pad0;
    unsigned int pad1;
    unsigned int formID;
};

struct ObstacleData
{
    unsigned int pad0;
    unsigned int pad1;
    ReferenceObstacleArray* m_pReferenceObstacleArray;
};

struct Call_006c0c80
{
    void FUN_006c0c80(TESObjectREFR*);
    void HandleRigidBodyObstacle(bhkRigidBody*);
};

extern unsigned int _data_011c16bc;

TESObjectREFR* _GetFormByNumericID(unsigned int);

GO::GO(int)
{}

GO::~GO()
{}

GO::operator unsigned int() const
{
    return 0;
}

bool FGModelMap::GetAt(void*, GO&)
{
    return false;
}

void Call_006c0c80::FUN_006c0c80(TESObjectREFR*)
{}

// Looks up the rigid body in the model map at offset 0xe0, resolves the referenced form by its formID and passes it to FUN_006c0c80 if found.
// @fnv 0x006c1cb0
void Call_006c0c80::HandleRigidBodyObstacle(bhkRigidBody* apRigidBody)
{
    TESObjectREFR* pref;
    GO go(0);

    if (reinterpret_cast<FGModelMap*>(reinterpret_cast<char*>(this) + 0xe0)->GetAt(apRigidBody, go))
    {
        pref = _GetFormByNumericID(
            reinterpret_cast<ObstacleData*>(static_cast<unsigned int>(go))->m_pReferenceObstacleArray->formID);

        if (pref)
            this->FUN_006c0c80(pref);
    }
}
}  // namespace fnv_006c1cb0

extern int DAT_0106c3c4;

struct FUN_006c0100_t
{
    int v;
    void* __thiscall FUN_006c0100();
};

// @fnv 0x006c0100
void* __thiscall FUN_006c0100_t::FUN_006c0100()
{
    v = (int)&DAT_0106c3c4;
    return this;
}

class TargetObj
{
  public:
    void UnkCall();
};

void* __cdecl UnkLookup(int id);
TargetObj* __stdcall UnkResolve(void* obj);

class FUN_006c0280_cls
{
  public:
    void CallResolvedObject(int id);
};

// Looks up an object by id; if found, resolves it and calls UnkCall on the result.
// @fnv 0x006c0280
void FUN_006c0280_cls::CallResolvedObject(int id)
{
    void* obj = UnkLookup(id);
    if (obj != 0)
    {
        UnkResolve(obj)->UnkCall();
    }
}

struct S_006c0900_release
{
    virtual int Release(bool);
};

struct S_006c0900
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
    S_006c0900_release* unk120;
    S_006c0900_release* unk124;
    int unk128;

    void FUN_006c0900();
};

void __fastcall FUN_006c09f0(void* pThis);
void __fastcall FUN_006c09d0(void* pThis);
void* __stdcall FUN_00b00a00(void* pObject);
void __fastcall ReleaseItem(void* pThis);

// @fnv 0x006c0900
void S_006c0900::FUN_006c0900()
{
    FUN_006c09f0(this);

    if (this->unk120)
    {
        S_006c0900_release* a = this->unk120;
        S_006c0900_release* p = a;
        p ? p->Release(true) : 0;
        this->unk120 = 0;
    }

    if (this->unk124)
    {
        S_006c0900_release* b = this->unk124;
        S_006c0900_release* q = b;
        q ? q->Release(true) : 0;
        this->unk124 = 0;
    }

    FUN_006c09d0(&this->unk128);
    ReleaseItem(FUN_00b00a00(&this->unk128));
}

// FUN_006c1520 - ReferenceObstacleArray::~ReferenceObstacleArray
//
// The original is the scalar destructor of ReferenceObstacleArray
// (RTTI .?AVReferenceObstacleArray@@, vftable 0x0106c484), whose base is
// NiRefObject (vftable 0x0101dce4, destructor 0x00496910) and whose member at
// +0x0c is a BSSimpleArray<NiPointer<ObstacleData> > (vftable 0x0106c640,
// destructor 0x006c6190).  The object is 0x1c bytes long.
//
// The stand-in classes below reproduce only what the destructor touches:
//   +0x00  vptr (shared with the base)
//   +0x04  base member
//   +0x08  int member that is cleared
//   +0x0c  member object with its own destructor
//
// The destructor itself is named after the tag so that the checker can find it.

struct FNV_NiRefObjectStandIn
{
    virtual ~FNV_NiRefObjectStandIn();
    int m_iObjectReferenceCount;
};

struct FNV_RobArrayStandIn
{
    virtual ~FNV_RobArrayStandIn();
    void* m_pData;
    int m_iElementCount;
    int m_pRayCursor;
};

struct FUN_006c1520_Class : public FNV_NiRefObjectStandIn
{
    virtual ~FUN_006c1520_Class();
    int m_08;
    FNV_RobArrayStandIn m_0c;
};

// Destructor that resets the m_08 field to zero.
// @fnv 0x006c1520
FUN_006c1520_Class::~FUN_006c1520_Class()
{
    m_08 = 0;
}

struct NavMeshInfoX;
struct NavMeshX
{
    NavMeshInfoX* FUN_0068efb0();
};
struct NavMeshPtrX
{
    NavMeshX* m_pObject;
    NavMeshX* Get() const;
};
struct InfoArrX
{
    void* vt;
    NavMeshInfoX** data;
    unsigned int cap;
    unsigned int count;
    unsigned int GetSize();
    NavMeshInfoX*& GetAt(unsigned int i);
    void Clear(bool b);
    unsigned int Add(NavMeshInfoX*& item);
};
struct ObstacleDataX
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
    int unk6C;
    int unk70;
    bool bFlag74;
    InfoArrX kNavMeshInfos;
};
struct ObstPtrX
{
    ObstacleDataX* m_pObject;
    ObstacleDataX* Get() const;
};
struct NavMeshPtrArrX
{
    void* vt;
    NavMeshPtrX* data;
    unsigned int cap;
    unsigned int count;
    char unk10;
    NavMeshPtrArrX();
    ~NavMeshPtrArrX();
    unsigned int GetSize();
    NavMeshPtrX& GetAt(unsigned int i);
};
struct TaskDataX
{
    bool AddOperation(const ObstPtrX& obst, int type);
};
void __cdecl UpdateObstacleBounds(ObstacleDataX* p);
void __cdecl FUN_006c3440(const ObstPtrX& obst);
bool __cdecl FUN_006c2050(const ObstPtrX& obst, NavMeshPtrArrX& arr);

struct ObstacleMgrX
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
    bool bFlag198;
    TaskDataX* GetTaskData(NavMeshInfoX* info);
    void FUN_006c5b20(const ObstPtrX& obst);
    void FUN_006c1760(const ObstPtrX& obst);
};

// @fnv 0x006c1760
void ObstacleMgrX::FUN_006c1760(const ObstPtrX& apObstacle)
{
    if (apObstacle.Get()->bFlag74)
    {
        for (unsigned int i = 0; i < apObstacle.Get()->kNavMeshInfos.GetSize(); i++)
        {
            GetTaskData(apObstacle.Get()->kNavMeshInfos.GetAt(i))->AddOperation(apObstacle, 0x21);
        }
        apObstacle.Get()->kNavMeshInfos.Clear(true);
    }
    UpdateObstacleBounds(apObstacle.Get());
    FUN_006c3440(apObstacle);
    if (bFlag198)
    {
        FUN_006c5b20(apObstacle);
    }
    if (apObstacle.Get()->bFlag74)
    {
        NavMeshPtrArrX kArr;
        if (FUN_006c2050(apObstacle, kArr))
        {
            for (unsigned int j = 0; j < kArr.GetSize(); j++)
            {
                GetTaskData(kArr.GetAt(j).Get()->FUN_0068efb0())->AddOperation(apObstacle, 0x11);
                NavMeshInfoX* pInfo = kArr.GetAt(j).Get()->FUN_0068efb0();
                apObstacle.Get()->kNavMeshInfos.Add(pInfo);
            }
        }
    }
}

struct FUN_00496910_Base
{
    ~FUN_00496910_Base();
};

struct Member_45cec0
{
    ~Member_45cec0();
};

struct Member_69af10
{
    ~Member_69af10();
};

struct FUN_006c24d0 : FUN_00496910_Base
{
    char pad00[0x0c];
    Member_45cec0 m1;
    char pad0c[0x78 - 0x0c - sizeof(Member_45cec0)];
    Member_69af10 m2;
    char pad78[0x88 - 0x78 - sizeof(Member_69af10)];
    Member_45cec0 m3;

    ~FUN_006c24d0();
};

// @fnv 0x006c24d0
FUN_006c24d0::~FUN_006c24d0()
{}

struct FNVNode;
struct FNVNodeList
{
    unsigned int FUN_00453470();
    FNVNode* func_0x0043b4a0(unsigned int index);
};
struct FNVNode
{
    virtual void Unknown0();
    virtual void Unknown1();
    virtual void Unknown2();
    virtual FNVNodeList* GetChildren();
};
struct FNVType
{
    int FUN_0043b4d0();
};
struct FNVData
{
    FNVType* func_0x0043b4f0(int* value);
};
struct FNVObject
{
    FNVData* func_0x006fa820();
};
FNVObject* __cdecl func_0x0043b610(FNVNode* node);
struct FNVResultMember
{
    void func_0x0066b0d0(FNVData* data);
};
struct FNVResult
{
    int unk00;
    int unk04;
    int unk08;
    FNVResultMember record;
};
void __cdecl func_0x006c2650(FNVResult* result);
// Looks up a node's data; if its type is one of 2,1,4,10,20,28, stores it in result and returns true, otherwise recurses over children.
// @fnv 0x006c2550
bool __cdecl FindNodeData(FNVNode* node, FNVResult* result)
{
    FNVNodeList* children5;
    FNVObject* object5 = func_0x0043b610(node);
    FNVData* data;
    int type_2;
    unsigned int indexVal;
    int value7;
    if (object5)
    {
        data = object5->func_0x006fa820();
        if (data)
        {
            type_2 = data->func_0x0043b4f0(&value7)->FUN_0043b4d0();
            if (type_2 == 2 || type_2 == 1 || type_2 == 4 || type_2 == 10 || type_2 == 20 || type_2 == 28)
            {
                result->unk08 = 0;
                result->record.func_0x0066b0d0(data);
                func_0x006c2650(result);
                return true;
            }
        }
    }
    children5 = node->GetChildren();
    if (children5)
    {
        for (indexVal = 0; indexVal < children5->FUN_00453470(); ++indexVal)
        {
            if (children5->func_0x0043b4a0(indexVal))
            {
                if (FindNodeData(children5->func_0x0043b4a0(indexVal), result))
                    return true;
            }
        }
    }
    return false;
}

struct KeyX
{
    KeyX();
    int a;
    int b;
    short c;
};

struct ObjB
{
    short GetWord();
    ObjB* Next();
    void Run();
};

struct ObjA
{
    ObjB* Find(KeyX* key);
    ObjB* Add(short w, int d, short t);
};

struct SrcB
{
    int u0;
    short w4;
    short pad6;
    int d8;
};

struct SrcC
{
    int d0;
    short w4;
};

struct FUN_006c4460_cls
{
    bool AddAndRunFromSources(ObjA* p1, SrcB* p2, SrcC* p3);
};

// Builds a key from p3, finds a word via p1, then adds p2's fields and runs the next entry.
// @fnv 0x006c4460
bool FUN_006c4460_cls::AddAndRunFromSources(ObjA* apObjA, SrcB* apSrcB, SrcC* apSrcC)
{
    KeyX key4;
    key4.b = apSrcC->d0;
    key4.c = apSrcC->w4;
    short tmp = apObjA->Find(&key4)->GetWord();
    apObjA->Add(apSrcB->w4, apSrcB->d8, tmp)->Next()->Run();
    return true;
}

struct FUN_006c6d40_base
{
  public:
    virtual void unk00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    FUN_006c6d40_base();
    ~FUN_006c6d40_base();
};
struct FUN_006c6d40_helper
{
  public:
    void* FUN_00aa42e0();
};
void* __cdecl FUN_00401020();
struct FUN_006c6d40_cls : public FUN_006c6d40_base
{
  public:
    virtual void unk00();
    void* m_10;
    void FUN_006b3eb0(unsigned int a, unsigned int b);
    FUN_006c6d40_cls(unsigned int a, unsigned int b, void* p);
};
// Sets m_10 to p or a default from FUN_00401020, then calls FUN_006b3eb0 with a and b.
// @fnv 0x006c6d40
FUN_006c6d40_cls::FUN_006c6d40_cls(unsigned int auiParam1, unsigned int auiParam2, void* p)
{
    m_10 = p ? p : ((FUN_006c6d40_helper*)FUN_00401020())->FUN_00aa42e0();
    FUN_006b3eb0(auiParam1, auiParam2);
}

// FUN_006c0190
//
// A member function that takes one 4-byte parameter, resolves it through a
// cdecl lookup helper, and, when the lookup succeeds, hands the resolved
// pointer to a singleton object's member routine.

struct FUN_006c0190_cls
{
    void FUN_006c0190(void* apParam);
};

// Lookup helper: cdecl, one argument, returns the resolved pointer.
extern void* __cdecl FUN_004b5a80(void* apParam);

// Singleton accessor: cdecl, no arguments, returns the global manager.
extern void* __cdecl GetNavMeshObstacleManager();

// @fnv 0x006c0190
void FUN_006c0190_cls::FUN_006c0190(void* apParam)
{
    void* pResolved = FUN_004b5a80(apParam);
    if (pResolved != 0)
    {
        ((FUN_006c1c90_shell*)GetNavMeshObstacleManager())->ForwardToSubObject(pResolved);
    }
}

struct ObstacleManagerBase
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    ~ObstacleManagerBase();
};
struct ObstaclePointerMap
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    ~ObstaclePointerMap();
};
struct ObstacleList
{
    unsigned int unk00;
    unsigned int unk04;
    ~ObstacleList();
};
struct ObstacleArrayState
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    ~ObstacleArrayState();
};
struct ObstacleTaskMap
{
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
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    ~ObstacleTaskMap();
};
struct ObstacleReferenceMap
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    ~ObstacleReferenceMap();
};
struct ObstacleTimer
{
    unsigned int unk00;
    ~ObstacleTimer();
};
struct ObstacleInfoMap
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    ~ObstacleInfoMap();
};
struct ObstacleTaskArray
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    ~ObstacleTaskArray();
};
struct ObstacleOwner
{
    unsigned int unk00;
    ~ObstacleOwner();
};
struct ObstacleOwnedObject
{
    virtual ~ObstacleOwnedObject();
};
struct FUN_006c0510 : ObstacleManagerBase
{
    ObstaclePointerMap obstacles;        // 0x1C
    ObstacleList pending;                // 0x2C
    ObstacleList processed;              // 0x34
    ObstacleArrayState arrayState;       // 0x3C
    ObstacleTaskMap tasks;               // 0x60
    ObstacleTaskMap removedTasks;        // 0xA0
    ObstacleReferenceMap references;     // 0xE0
    ObstacleList removed;                // 0xF0
    ObstacleList added;                  // 0xF8
    ObstaclePointerMap active;           // 0x100
    ObstaclePointerMap queued;           // 0x110
    ObstacleOwnedObject* currentTasks;   // 0x120
    ObstacleOwnedObject* finishedTasks;  // 0x124
    ObstacleTimer timer;                 // 0x128
    ObstacleInfoMap info;                // 0x12C
    ObstacleTaskArray taskArray;         // 0x13C
    ObstacleTaskArray processedArray;    // 0x14C
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    ObstacleList waiting;    // 0x180
    ObstacleList completed;  // 0x188
    unsigned int unk190;
    float unk194;
    bool unk198;
    ObstacleOwner owner;  // 0x19C
    void FUN_006c09f0();
    ~FUN_006c0510();
};
// Runs cleanup via FUN_006c09f0, then deletes currentTasks and finishedTasks if they are set.
// @fnv 0x006c0510
FUN_006c0510::~FUN_006c0510()
{
    FUN_006c09f0();
    if (currentTasks)
        delete currentTasks;
    if (finishedTasks)
        delete finishedTasks;
}

namespace fnv_006c09f0 {
class NavMesh
{
  public:
    void FUN_006993c0();
};
struct NavMeshPtr
{
    NavMesh* object;
    NavMeshPtr();
    ~NavMeshPtr();
    NavMesh* FUN_00559450();
};
struct MeshInfoView
{
    bool FUN_00690860(NavMeshPtr& mesh);
};
struct MeshInfoArray
{
    unsigned int GetFlags();
    MeshInfoView*& GetAt(unsigned int index);
};
class ObstacleData
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    SpArr reference;
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
    MeshInfoArray meshes;
};
template <> class NiPointer<ObstacleData>
{
  public:
    ObstacleData* m_pObject;
    NiPointer(const NiPointer& other);
    ~NiPointer();
    ObstacleData* operator->() const;
};
struct ClearMapView
{
    unsigned int vtable;
    unsigned int hashSize;
    unsigned int buckets;
    unsigned int count;
    void RemoveAll();
};
struct RefListView
{
    unsigned int item;
    unsigned int next;
    bool IsInList(unsigned int& value);
    void RemoveAll();
};
struct ClearArrayView
{
    void FUN_004ee920();
};
struct ObstacleTreeView
{
    void ClearQueue(bool release);
};
struct ManagerView
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    MapX obstacles;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    RefListView pending;
    RefListView removed;
    ClearArrayView processed;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    ObstacleTreeView treeA;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    ObstacleTreeView treeB;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    ClearMapView mapE0;
    RefListView listF0;
    RefListView listF8;
    ClearMapView map100;
    ClearMapView map110;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    bool active;
    void FUN_006c09f0();
    void FUN_006c1e00(ObstArr* reference);
    void SetEnabled(bool value);
};
// @fnv 0x006c09f0
void ManagerView::FUN_006c09f0()
{
    SpArr records(0);
    void* position = obstacles.GetFirstPos();
    unsigned int key;
    while (position)
    {
        obstacles.FUN_00559120(position, key, records);
        for (unsigned int i = 0; i < static_cast<ObstArr*>(records)->arr.GetFlags(); ++i)
        {
            NiPointer<ObstacleData> obstacle(
                *reinterpret_cast<NiPointer<ObstacleData>*>(static_cast<ObstArr*>(records)->arr.GetAt(i)));
            if (!removed.IsInList(key))
            {
                FUN_006c1e00(static_cast<ObstArr*>(obstacle->reference));
            }
            for (unsigned int j = 0; j < obstacle->meshes.GetFlags(); ++j)
            {
                NavMeshPtr mesh;
                if (obstacle->meshes.GetAt(j)->FUN_00690860(mesh))
                {
                    mesh.FUN_00559450()->FUN_006993c0();
                }
            }
        }
    }
    reinterpret_cast<ClearMapView*>(&obstacles)->RemoveAll();
    map100.RemoveAll();
    map110.RemoveAll();
    mapE0.RemoveAll();
    listF0.RemoveAll();
    listF8.RemoveAll();
    pending.RemoveAll();
    removed.RemoveAll();
    processed.FUN_004ee920();
    treeA.ClearQueue(false);
    treeB.ClearQueue(false);
    if (active)
        SetEnabled(false);
}
}  // namespace fnv_006c09f0

struct TESObjectREFR;
struct TESBoundObject;
struct TESObjectDOOR;

struct RefSP0dc0
{
    void* m_pObject;
    RefSP0dc0(int);
    ~RefSP0dc0();
};

struct RefList0dc0
{
    void* m_item;
    RefList0dc0* m_pkNext;
    bool IsInList(TESObjectREFR*& item);
    void Remove(TESObjectREFR* const& item);
};

struct IdList0dc0
{
    unsigned int m_item;
    IdList0dc0* m_pkNext;
    bool IsInList(const unsigned int& item);
    void AddHead(const unsigned int& item);
};

struct Map0dc0
{
    void* vtbl;
    int unk04;
    int unk08;
    int unk0C;
    bool GetAt(unsigned int key, RefSP0dc0& val);
};

TESBoundObject* __fastcall GetBaseObject0dc0(TESObjectREFR* ref);
unsigned int __fastcall GetFormType0dc0(TESBoundObject* form);
bool __fastcall IsDoorX0dc0(TESObjectDOOR* door);
unsigned int __fastcall GetRefID0dc0(TESObjectREFR* ref);

struct ObstMgr0dc0
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
    RefList0dc0 kRemovedRefs;
    IdList0dc0 kPendingIDs;
    Map0dc0 kMap100;
    Map0dc0 kMap110;
    void HandleDoor(TESObjectREFR* ref);
    void FUN_006c0dc0(TESObjectREFR* ref);
};

// @fnv 0x006c0dc0
void ObstMgr0dc0::FUN_006c0dc0(TESObjectREFR* ref)
{
    TESBoundObject* pBase6 = GetBaseObject0dc0(ref);
    if (GetFormType0dc0(pBase6) == 0x1c)
    {
        TESObjectDOOR* pPathNodeDoor = (TESObjectDOOR*)pBase6;
        if (!IsDoorX0dc0(pPathNodeDoor))
            HandleDoor(ref);
    }
    RefSP0dc0 spScreenData(0);
    if (!kMap110.GetAt(GetRefID0dc0(ref), spScreenData))
    {
        if (kRemovedRefs.IsInList(ref))
            kRemovedRefs.Remove(ref);
    }
    if (!kMap100.GetAt(GetRefID0dc0(ref), spScreenData))
    {
        if (!kPendingIDs.IsInList(GetRefID0dc0(ref)))
            kPendingIDs.AddHead(GetRefID0dc0(ref));
    }
}

template <class T> struct Ptr_c1190
{
    T* m_pObject;
    Ptr_c1190(T* p);
    Ptr_c1190(const Ptr_c1190& other);
    ~Ptr_c1190();
    Ptr_c1190& operator=(T* p);
    operator T*() const;
    T* operator->() const;
};
struct Mesh_c1190;
struct Info_c1190;
struct Mesh_c1190
{
    Info_c1190* FUN_0068efb0();
};
struct MeshArr_c1190
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    MeshArr_c1190();
    ~MeshArr_c1190();
    unsigned int FUN_0044ddc0();
    Ptr_c1190<Mesh_c1190>& FUN_00877a30(unsigned int i);
};
struct InfoArr_c1190
{
    int unk00;
    unsigned int FUN_007cb2e0(Info_c1190* const& item);
};
struct Kind_c1190
{
    bool FUN_005609b0();
};
struct ObsArr_c1190;
struct Obs_c1190
{
    int unk00;
    int unk04;
    int unk08;
    Ptr_c1190<Kind_c1190> m_spKind;
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
    bool bFlag74;
    InfoArr_c1190 kInfos;
};
struct ObsArr_c1190
{
    unsigned int FUN_0044ddc0();
    Ptr_c1190<Obs_c1190>& FUN_00877a30(unsigned int i);
};
struct Holder_c1190
{
    int unk00;
    int unk04;
    int unk08;
    ObsArr_c1190 kObstacles;
    int unk10;
    int unk14;
    int unk18;
    Holder_c1190();
    static void* operator new(unsigned int size);
    static void operator delete(void* p, unsigned int);
};
struct Task_c1190
{
    bool FUN_006c7a30(const Ptr_c1190<Obs_c1190>& obst, int type);
};
struct Key_c1190
{
    unsigned int FUN_0084e3a0();
};
struct HolderMap_c1190
{
    bool FUN_006c62d0(unsigned int key, Ptr_c1190<Holder_c1190>* out);
    void FUN_006c6920(unsigned int key, Ptr_c1190<Holder_c1190> val);
};
struct ObsMap_c1190
{
    void FUN_006c6920(Kind_c1190* key, Ptr_c1190<Obs_c1190> val);
};
void __cdecl FUN_006c34f0(Key_c1190* key, Ptr_c1190<Holder_c1190>& holder);
void __cdecl FUN_006c3440(const Ptr_c1190<Obs_c1190>& obst);
bool __cdecl FUN_006c2050(const Ptr_c1190<Obs_c1190>& obst, MeshArr_c1190& arr);
struct Mgr_c1190
{
    void FUN_006c1c70(Kind_c1190* kind);
    void FUN_006c1d60(Kind_c1190* kind);
    void FUN_006c5b20(const Ptr_c1190<Obs_c1190>& obst);
    Task_c1190* FUN_006c5ef0(Info_c1190* info);
    void RegisterKey(Key_c1190* key);
};
// @fnv 0x006c1190
void Mgr_c1190::RegisterKey(Key_c1190* key)
{
    Ptr_c1190<Holder_c1190> spHolder(0);
    if (!((HolderMap_c1190*)((char*)this + 0x1c))->FUN_006c62d0(key->FUN_0084e3a0(), &spHolder))
    {
        spHolder = new Holder_c1190;
        FUN_006c34f0(key, spHolder);
        ((HolderMap_c1190*)((char*)this + 0x1c))->FUN_006c6920(key->FUN_0084e3a0(), spHolder);
    }
    for (unsigned int i = 0; i < spHolder->kObstacles.FUN_0044ddc0(); i++)
    {
        Ptr_c1190<Obs_c1190> spObst(spHolder->kObstacles.FUN_00877a30(i));
        ((ObsMap_c1190*)((char*)this + 0xe0))->FUN_006c6920(spObst->m_spKind, spObst);
        FUN_006c1d60(spObst->m_spKind);
        if (spObst->m_spKind->FUN_005609b0())
        {
            FUN_006c1c70(spObst->m_spKind);
        }
        FUN_006c3440(spObst);
        if (*((bool*)this + 0x198))
        {
            FUN_006c5b20(spObst);
        }
        if (spObst->bFlag74)
        {
            MeshArr_c1190 kMeshes;
            if (FUN_006c2050(spObst, kMeshes))
            {
                for (unsigned int j = 0; j < kMeshes.FUN_0044ddc0(); j++)
                {
                    FUN_006c5ef0(kMeshes.FUN_00877a30(j)->FUN_0068efb0())->FUN_006c7a30(spObst, 0x10);
                    spObst->kInfos.FUN_007cb2e0(kMeshes.FUN_00877a30(j)->FUN_0068efb0());
                }
            }
        }
    }
}

struct InnerPtr
{
    void* FUN_00559450();
};
struct InnerArr
{
    unsigned int FUN_0044ddc0();
    bool FUN_0076b610();
    unsigned int* FUN_00877a30(unsigned int);
    void FUN_008454f0(bool);
};
struct ObView
{
    int unk000;
    int unk004;
    int unk008;
    InnerPtr inner;
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
    InnerArr arr;
};
struct ObPointerView
{
    ObView* FUN_00559450();
};
struct TaskView
{
    bool FUN_006c7a30(SpObst&, int);
};
struct MapView
{
    bool FUN_006c62d0(unsigned int, SpArr&);
    void RemoveKey(unsigned int);
};
struct PtrMapView
{
    void RemoveKey(void*);
};
struct ListView
{
    void FUN_00631620(SpObst&);
};
struct HostA
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    MapView map;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    ListView list;
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
    PtrMapView ptrMap;
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
    bool flag;
    void AttachChildFromSource(SpObst&);
    TaskView* FUN_006c5ef0(unsigned int);
    void RemoveEntry(unsigned int);
};
// @fnv 0x006c1590
void HostA::RemoveEntry(unsigned int key)
{
    SpArr array(0);
    if (!map.FUN_006c62d0(key, array))
        return;
    map.RemoveKey(key);
    for (unsigned int i = 0; i < ((ObstArr*)array)->arr.GetFlags(); i++)
    {
        SpObst item(((ObstArr*)array)->arr.GetAt(i));
        ptrMap.RemoveKey(((ObPointerView*)&item)->FUN_00559450()->inner.FUN_00559450());
        list.FUN_00631620(item);
        if (flag)
            AttachChildFromSource(item);
        if (!((ObPointerView*)&item)->FUN_00559450()->arr.FUN_0076b610())
        {
            for (unsigned int j = 0; j < ((ObPointerView*)&item)->FUN_00559450()->arr.FUN_0044ddc0(); j++)
                FUN_006c5ef0(*((ObPointerView*)&item)->FUN_00559450()->arr.FUN_00877a30(j))->FUN_006c7a30(item, 0x20);
            ((ObPointerView*)&item)->FUN_00559450()->arr.FUN_008454f0(true);
        }
    }
}

struct RigidBodyPtr1920
{
    void* m_pObject;
    void* Get() const;
};

struct ObstData1920
{
    int unk00;
    int unk04;
    int unk08;
    RigidBodyPtr1920 m_pRigidBody;
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
    bool bFlag74;
    InfoArrX kNavMeshInfos;
};

struct ObstPtr1920
{
    ObstData1920* m_pObject;
    ObstPtr1920(const ObstPtr1920& other);
    ~ObstPtr1920();
    ObstData1920* Get() const;
};

struct ObstArr1920
{
    unsigned int GetSize();
    ObstPtr1920& GetAt(unsigned int i);
};

struct RefObstData1920
{
    int unk00;
    int unk04;
    int unk08;
    ObstArr1920 kObstacles;
};

struct RefObstPtr1920
{
    RefObstData1920* m_pObject;
    RefObstPtr1920(int p);
    ~RefObstPtr1920();
    RefObstData1920* Get() const;
};

struct Map1C_1920
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    bool GetAt(unsigned int key, RefObstPtr1920& out);
};

struct List3C_1920
{
    int unk00;
    int unk04;
    void Remove(const ObstPtr1920& item);
};

struct MapE0_1920
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    bool RemoveAt(void* key);
};

struct TaskData1920
{
    bool AddOperation(const ObstPtr1920& obst, int type);
};

void __cdecl BuildRefObstacles1920(void* pRef, RefObstPtr1920& spArr);
void __cdecl UpdateObstacle1920(const ObstPtr1920& obst);
bool __cdecl FindNavMeshes1920(const ObstPtr1920& obst, NavMeshPtrArrX& arr);

struct ObstMgr1920
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    Map1C_1920 map1C;
    List3C_1920 list3C;
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
    MapE0_1920 mapE0;
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
    bool bFlag198;

    TaskData1920* GetTaskData(NavMeshInfoX* info);
    void RemoveFromOctree1920(const ObstPtr1920& obst);
    void AddToOctree1920(const ObstPtr1920& obst);
    void OnRemoveBody1920(void* body);
    void OnAddBody1920(void* body);
    void RebuildRefObstacles(unsigned int formID, void* pRef);
};

// @fnv 0x006c1920
void ObstMgr1920::RebuildRefObstacles(unsigned int formID, void* pRef)
{
    RefObstPtr1920 spArr(0);
    if (!this->map1C.GetAt(formID, spArr))
    {
        return;
    }
    for (unsigned int i = 0; i < spArr.Get()->kObstacles.GetSize(); i++)
    {
        ObstPtr1920 spObst = spArr.Get()->kObstacles.GetAt(i);
        if (spObst.Get()->bFlag74)
        {
            for (unsigned int j = 0; j < spObst.Get()->kNavMeshInfos.GetSize(); j++)
            {
                this->GetTaskData(spObst.Get()->kNavMeshInfos.GetAt(j))->AddOperation(spObst, 0x21);
            }
            spObst.Get()->kNavMeshInfos.Clear(true);
        }
        if (this->bFlag198)
        {
            this->RemoveFromOctree1920(spObst);
        }
        this->OnRemoveBody1920(spObst.Get()->m_pRigidBody.Get());
        this->mapE0.RemoveAt(spObst.Get()->m_pRigidBody.Get());
        this->list3C.Remove(spObst);
    }
    BuildRefObstacles1920(pRef, spArr);
    for (unsigned int k = 0; k < spArr.Get()->kObstacles.GetSize(); k++)
    {
        ObstPtr1920 spObst2 = spArr.Get()->kObstacles.GetAt(k);
        UpdateObstacle1920(spObst2);
        if (spObst2.Get()->bFlag74)
        {
            NavMeshPtrArrX kNavMeshes;
            if (FindNavMeshes1920(spObst2, kNavMeshes))
            {
                for (unsigned int m = 0; m < kNavMeshes.GetSize(); m++)
                {
                    this->GetTaskData(kNavMeshes.GetAt(m).Get()->FUN_0068efb0())->AddOperation(spObst2, 0x11);
                    NavMeshInfoX* pInfo = kNavMeshes.GetAt(m).Get()->FUN_0068efb0();
                    spObst2.Get()->kNavMeshInfos.Add(pInfo);
                }
            }
        }
        if (this->bFlag198)
        {
            this->AddToOctree1920(spObst2);
        }
        this->OnAddBody1920(spObst2.Get()->m_pRigidBody.Get());
    }
}

namespace ObstacleBounds {
struct Vec
{
    float x, y, z;
    Vec();
    Vec(float, float, float);
    Vec FUN_004a0bd0();
    Vec FUN_0053d1a0(const Vec&);
    Vec FUN_004b3800(const Vec&);
    Vec FUN_00439e90(const Vec&);
    Vec FUN_00439ef0(const Vec&);
};
struct PlainVec
{
    float x, y, z;
};
struct Mat
{
    float entries[3][3];
    Mat();
    void DecomposeToEulerAngles(float&, float&, float&);
    void FUN_00439f50(unsigned int, Vec&);
    void FUN_004769c0(int, const Vec&);
    Mat FUN_004768c0();
    Mat FUN_0043f8d0(const Mat&);
    Vec FUN_004b4500(const Vec&);
};
struct Transform
{
    Mat rotation;
    PlainVec position;
    float scale;
};
union __declspec(align(16)) HkVec
{
    float lanes[4];
    unsigned char bytes[16];
};
struct __declspec(align(16)) HkTransform
{
    HkVec col0, col1, col2, translation;
    HkTransform(const void*);
};
struct __declspec(align(16)) Bounds
{
    HkVec minimum, maximum;
    Bounds();
};
struct Body
{
    const void* FUN_004b4f00();
};
struct Collision
{
    Body* GetReferenceFlags();
    void GetAabb(Bounds&);
};
struct Pointer
{
    Collision* value;
    Collision* FUN_00559450();
};
struct Obstacle
{
    unsigned int unk0, unk4, unk8;
    Pointer collision;
    Vec position;
    Mat rotation;
    Vec localMin, localMax, worldMin, worldMax;
    unsigned int generation;
};
void FUN_00624ad0(Transform&, const HkTransform&);
void FUN_00458620(Vec&, const HkVec&);
float FUN_00408840(float);
float FUN_004b1500(float, float);
float FUN_0040ebd0(float, float);
float FUN_00404010(float, float);
struct Manager
{
    unsigned int FUN_00825c00();
};
extern Manager DAT_011f6394;
extern Vec DAT_011a9484;
extern double DAT_01012060;
extern float DAT_01017a3c, DAT_0106c3ac, DAT_01016970, DAT_01015f5c;
// Rebuilds an obstacle's position, rotation, local and world bounds from its collision body's transform and bounds, then bumps the generation counter.
// @fnv 0x006c2650
bool UpdateObstacleBounds(Obstacle* obstacle)
{
    Collision* collision = obstacle->collision.FUN_00559450();
    if (!collision)
        return false;
    Body* body = collision->GetReferenceFlags();
    if (!body)
        return false;
    HkTransform hkTransform(body->FUN_004b4f00());
    Transform transform;
    transform.scale = 1.0f;
    FUN_00624ad0(transform, hkTransform);
    Bounds bounds;
    collision->GetAabb(bounds);
    float angleX, angleY, angleZ;
    transform.rotation.DecomposeToEulerAngles(angleX, angleY, angleZ);
    Vec minimum, maximum;
    FUN_00458620(minimum, bounds.minimum);
    FUN_00458620(maximum, bounds.maximum);
    obstacle->position = reinterpret_cast<const Vec&>(transform.position);
    Vec axisVectors[3];
    for (unsigned int axis = 0; axis < 3; axis++)
        transform.rotation.FUN_00439f50(axis, axisVectors[axis]);
    Vec upAxis, sideAxis, forwardAxis;
    if (FUN_00408840(axisVectors[0].z) > FUN_00408840(axisVectors[1].z))
    {
        if (FUN_00408840(axisVectors[0].z) > FUN_00408840(axisVectors[2].z))
        {
            upAxis = axisVectors[0];
            forwardAxis = axisVectors[1];
            sideAxis = axisVectors[2];
        }
        else
        {
            upAxis = axisVectors[2];
            forwardAxis = axisVectors[0];
            sideAxis = axisVectors[1];
        }
    }
    else
    {
        if (FUN_00408840(axisVectors[1].z) > FUN_00408840(axisVectors[2].z))
        {
            upAxis = axisVectors[1];
            forwardAxis = axisVectors[2];
            sideAxis = axisVectors[0];
        }
        else
        {
            upAxis = axisVectors[2];
            forwardAxis = axisVectors[0];
            sideAxis = axisVectors[1];
        }
    }
    if (upAxis.z < DAT_01012060)
    {
        upAxis = upAxis.FUN_004a0bd0();
        forwardAxis = forwardAxis.FUN_004a0bd0();
    }
    upAxis = DAT_011a9484;
    sideAxis = upAxis.FUN_0053d1a0(forwardAxis);
    forwardAxis = sideAxis.FUN_004b3800(upAxis).FUN_004a0bd0();
    obstacle->rotation.FUN_004769c0(0, forwardAxis);
    obstacle->rotation.FUN_004769c0(1, sideAxis);
    obstacle->rotation.FUN_004769c0(2, upAxis);
    Mat toLocalMat = obstacle->rotation.FUN_004768c0().FUN_0043f8d0(transform.rotation);
    Vec localCorners[8];
    localCorners[0] = toLocalMat.FUN_004b4500(Vec(minimum.x, minimum.y, minimum.z));
    localCorners[1] = toLocalMat.FUN_004b4500(Vec(maximum.x, minimum.y, minimum.z));
    localCorners[2] = toLocalMat.FUN_004b4500(Vec(minimum.x, maximum.y, minimum.z));
    localCorners[3] = toLocalMat.FUN_004b4500(Vec(maximum.x, maximum.y, minimum.z));
    localCorners[4] = toLocalMat.FUN_004b4500(Vec(minimum.x, minimum.y, maximum.z));
    localCorners[5] = toLocalMat.FUN_004b4500(Vec(maximum.x, minimum.y, maximum.z));
    localCorners[6] = toLocalMat.FUN_004b4500(Vec(minimum.x, maximum.y, maximum.z));
    localCorners[7] = toLocalMat.FUN_004b4500(Vec(maximum.x, maximum.y, maximum.z));
    Vec worldCorners[8];
    for (unsigned int worldIndex = 0; worldIndex < 8; worldIndex++)
        worldCorners[worldIndex] =
            obstacle->rotation.FUN_004b4500(localCorners[worldIndex]).FUN_00439e90(obstacle->position);
    Mat fromWorldMat = obstacle->rotation.FUN_004768c0();
    for (unsigned int snap = 0; snap < 8; snap++)
    {
        if (FUN_00408840(FUN_004b1500(worldCorners[snap].x, DAT_01017a3c)) < DAT_0106c3ac)
        {
            worldCorners[snap].x += DAT_0106c3ac * 2.0f;
            localCorners[snap] = fromWorldMat.FUN_004b4500(worldCorners[snap].FUN_00439ef0(obstacle->position));
        }
        if (FUN_00408840(FUN_004b1500(worldCorners[snap].y, DAT_01017a3c)) < DAT_0106c3ac)
        {
            worldCorners[snap].y += DAT_0106c3ac * 2.0f;
            localCorners[snap] = fromWorldMat.FUN_004b4500(worldCorners[snap].FUN_00439ef0(obstacle->position));
        }
    }
    obstacle->localMin = Vec(DAT_01016970, DAT_01016970, DAT_01016970);
    obstacle->localMax = Vec(DAT_01015f5c, DAT_01015f5c, DAT_01015f5c);
    for (unsigned int localIndex = 0; localIndex < 8; localIndex++)
    {
        obstacle->localMin.x = FUN_0040ebd0(obstacle->localMin.x, localCorners[localIndex].x);
        obstacle->localMin.y = FUN_0040ebd0(obstacle->localMin.y, localCorners[localIndex].y);
        obstacle->localMin.z = FUN_0040ebd0(obstacle->localMin.z, localCorners[localIndex].z);
        obstacle->localMax.x = FUN_00404010(obstacle->localMax.x, localCorners[localIndex].x);
        obstacle->localMax.y = FUN_00404010(obstacle->localMax.y, localCorners[localIndex].y);
        obstacle->localMax.z = FUN_00404010(obstacle->localMax.z, localCorners[localIndex].z);
    }
    obstacle->worldMin = Vec(DAT_01016970, DAT_01016970, DAT_01016970);
    obstacle->worldMax = Vec(DAT_01015f5c, DAT_01015f5c, DAT_01015f5c);
    for (unsigned int boundIndex = 0; boundIndex < 8; boundIndex++)
    {
        obstacle->worldMin.x = FUN_0040ebd0(obstacle->worldMin.x, worldCorners[boundIndex].x);
        obstacle->worldMin.y = FUN_0040ebd0(obstacle->worldMin.y, worldCorners[boundIndex].y);
        obstacle->worldMin.z = FUN_0040ebd0(obstacle->worldMin.z, worldCorners[boundIndex].z);
        obstacle->worldMax.x = FUN_00404010(obstacle->worldMax.x, worldCorners[boundIndex].x);
        obstacle->worldMax.y = FUN_00404010(obstacle->worldMax.y, worldCorners[boundIndex].y);
        obstacle->worldMax.z = FUN_00404010(obstacle->worldMax.z, worldCorners[boundIndex].z);
    }
    obstacle->generation = DAT_011f6394.FUN_00825c00();
    return true;
}
}

struct DebugUpdateData
{
    float time;
    bool updateControllers;
    bool isMultithreaded;
    bool flag06;
    bool flag07;
    bool flag08;
    DebugUpdateData(float, bool, bool);
};
struct DebugColor
{
    float red, green, blue;
    DebugColor(float, float, float);
};
struct DebugSceneObject;
template <class T> struct DebugPointer
{
    T* object;
    DebugPointer(T*);
    DebugPointer(const DebugPointer&);
    ~DebugPointer();
    T* operator->() const;
    operator T*() const;
    DebugPointer& operator=(T*);
};
struct DebugSceneObject
{
    virtual void Unknown00();
    virtual void Unknown01();
    virtual void Unknown02();
    virtual void Unknown03();
    virtual void Unknown04();
    virtual void Unknown05();
    virtual void Unknown06();
    virtual void Unknown07();
    virtual void Unknown08();
    virtual void Unknown09();
    virtual void Unknown10();
    virtual void Unknown11();
    virtual void Unknown12();
    virtual void Unknown13();
    virtual void Unknown14();
    virtual void Unknown15();
    virtual void Unknown16();
    virtual void Unknown17();
    virtual void Unknown18();
    virtual void Unknown19();
    virtual void Unknown20();
    virtual void Unknown21();
    virtual void Unknown22();
    virtual void Unknown23();
    virtual void Unknown24();
    virtual void Unknown25();
    virtual void Unknown26();
    virtual void Unknown27();
    virtual void Unknown28();
    virtual void Unknown29();
    virtual void Unknown30();
    virtual void Unknown31();
    virtual void Unknown32();
    virtual void Unknown33();
    virtual void Unknown34();
    virtual void Unknown35();
    virtual void Unknown36();
    virtual void Unknown37();
    virtual void Unknown38();
    virtual void Unknown39();
    virtual void Unknown40();
    virtual void Unknown41();
    virtual void Unknown42();
    virtual void Unknown43();
    virtual void Unknown44();
    virtual void Unknown45();
    virtual void Unknown46();
    virtual void Unknown47();
    virtual void Unknown48();
    virtual void Unknown49();
    virtual void Unknown50();
    virtual void Unknown51();
    virtual void Unknown52();
    virtual void Unknown53();
    virtual void Unknown54();
    virtual void AttachChildInAvailableSlot(DebugSceneObject*, bool);
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
    DebugSceneObject(unsigned short);
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    void FUN_004def90();
    void AttachProperty(void*);
    void FUN_00a5a040();
    void FUN_00a59c60(const DebugUpdateData&);
};
struct DebugAlphaProperty
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    DebugAlphaProperty();
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    void FUN_0049ed90(bool);
};
struct DebugMaterialProperty
{
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
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    DebugMaterialProperty();
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    void FUN_004bc450(const DebugColor*);
    void FUN_0068c9f0(float);
};
struct DebugObjectArray
{
    unsigned int GetSize();
    DebugPointer<DebugSceneObject>& GetAt(unsigned int);
};
struct DebugObstacleArray
{
    unsigned int unk00, unk04, unk08;
    DebugObjectArray objects;
};
struct DebugObstacleMap
{
    unsigned int unk00, unk04, unk08, unk0c;
    void* GetFirstPos();
    void FUN_00559120(void*&, unsigned int&, DebugPointer<DebugObstacleArray>&);
};
struct DebugTES
{
    DebugSceneObject* FUN_0084e3a0();
};
extern DebugTES* g_TES;
extern const float DAT_0101622c;
struct DebugObstacleManager
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    DebugObstacleMap obstacles;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    bool enabled;
    DebugPointer<DebugSceneObject> scene;
    void CreateObstacleBox(const DebugPointer<DebugSceneObject>&, DebugPointer<DebugSceneObject>&);
    void SetEnabled(bool show);
};
// @fnv 0x006c5460
void DebugObstacleManager::SetEnabled(bool show)
{
    if (show)
    {
        if (scene)
        {
            scene->FUN_004def90();
        }
        else
        {
            scene = new DebugSceneObject(0);
            DebugPointer<DebugAlphaProperty> h = new DebugAlphaProperty;
            h->FUN_0049ed90(true);
            DebugPointer<DebugMaterialProperty> p = new DebugMaterialProperty;
            p->FUN_004bc450(&DebugColor(1.0f, 0.0f, 1.0f));
            p->FUN_0068c9f0(DAT_0101622c);
            scene->AttachProperty(h);
            scene->AttachProperty(p);
            g_TES->FUN_0084e3a0()->AttachChildInAvailableSlot(scene, true);
            DebugUpdateData a(0.0f, false, false);
            g_TES->FUN_0084e3a0()->FUN_00a59c60(a);
        }
        void* position = obstacles.GetFirstPos();
        while (position)
        {
            unsigned int l;
            DebugPointer<DebugObstacleArray> k(0);
            obstacles.FUN_00559120(position, l, k);
            for (unsigned int c = 0; c < k->objects.GetSize(); ++c)
            {
                DebugPointer<DebugSceneObject> e(k->objects.GetAt(c));
                DebugPointer<DebugSceneObject> j(0);
                CreateObstacleBox(e, j);
                scene->AttachChildInAvailableSlot(j, true);
            }
        }
        scene->FUN_00a5a040();
        DebugUpdateData update(0.0f, false, false);
        scene->FUN_00a59c60(update);
        enabled = true;
    }
    else
    {
        if (scene)
        {
            scene->FUN_004def90();
        }
        enabled = false;
    }
}

namespace fnv_006c5840 {
class ImageSpaceEffectParam
{
  public:
    float afValues[4];
    ImageSpaceEffectParam(float a, float b, float c, float d);
};

namespace _ {
struct FakePoint3
{
    float x, y, z;
    FakePoint3(float fX, float fY, float fZ);
};
}

class AnimIdle
{
  public:
    void FUN_00440460(const NiPoint3& kTranslate);
    void FUN_0043fa80(const void* pvRotate);
};

template <> class NiPointer<AnimIdle>
{
  public:
    AnimIdle* p[1];
    NiPointer(AnimIdle*);
    ~NiPointer();
    operator AnimIdle*() const;
    NiPointer<AnimIdle>& operator=(const NiPointer<AnimIdle>&);
};

class ObstacleData
{
  public:
    char pad00[0x10];
    NiPoint3 kTranslate;
    char acRotate[0x24];
    NiPoint3 kMinBoundsCur;
    NiPoint3 kMaxPoint;
    char pad58[0x30];
    NiPointer<AnimIdle> m_kGeometry;
};

AnimIdle* __cdecl CreateBoxMesh(_::FakePoint3& a, _::FakePoint3& b, _::FakePoint3& c, _::FakePoint3& d,
                                _::FakePoint3& e, _::FakePoint3& f, _::FakePoint3& g, _::FakePoint3& h,
                                ImageSpaceEffectParam& kColor, bool bFlag);

class FUN_006c5840_Class
{
  public:
    void CreateObstacleBox(NiPointer<ObstacleData>& aspObstacleData, NiPointer<AnimIdle>& spResult);
};

// Builds a box geometry from the obstacle's two corner points, applies its translate and rotate, stores it in the obstacle and returns it.
// @fnv 0x006c5840
void FUN_006c5840_Class::CreateObstacleBox(NiPointer<ObstacleData>& aspObstacleData, NiPointer<AnimIdle>& spResult)
{
    NiPoint3 kSize = ((ObstacleData*)aspObstacleData)->kMaxPoint - ((ObstacleData*)aspObstacleData)->kMinBoundsCur;
    ImageSpaceEffectParam kBoxColor(1.0f, 0.0f, 1.0f, 0.5f);
    _::FakePoint3 kCorner6(((ObstacleData*)aspObstacleData)->kMinBoundsCur.x, ((ObstacleData*)aspObstacleData)->kMinBoundsCur.y,
                           ((ObstacleData*)aspObstacleData)->kMinBoundsCur.z);
    _::FakePoint3 kVert0(((ObstacleData*)aspObstacleData)->kMaxPoint.x, ((ObstacleData*)aspObstacleData)->kMinBoundsCur.y,
                         ((ObstacleData*)aspObstacleData)->kMinBoundsCur.z);
    _::FakePoint3 kCorner5(((ObstacleData*)aspObstacleData)->kMaxPoint.x, ((ObstacleData*)aspObstacleData)->kMinBoundsCur.y,
                           ((ObstacleData*)aspObstacleData)->kMaxPoint.z);
    _::FakePoint3 kCorner2(((ObstacleData*)aspObstacleData)->kMinBoundsCur.x, ((ObstacleData*)aspObstacleData)->kMinBoundsCur.y,
                           ((ObstacleData*)aspObstacleData)->kMaxPoint.z);
    _::FakePoint3 kPt2(((ObstacleData*)aspObstacleData)->kMinBoundsCur.x, ((ObstacleData*)aspObstacleData)->kMaxPoint.y,
                       ((ObstacleData*)aspObstacleData)->kMinBoundsCur.z);
    _::FakePoint3 kPoint5(((ObstacleData*)aspObstacleData)->kMaxPoint.x, ((ObstacleData*)aspObstacleData)->kMaxPoint.y,
                          ((ObstacleData*)aspObstacleData)->kMinBoundsCur.z);
    _::FakePoint3 kCorner1(((ObstacleData*)aspObstacleData)->kMaxPoint.x, ((ObstacleData*)aspObstacleData)->kMaxPoint.y,
                           ((ObstacleData*)aspObstacleData)->kMaxPoint.z);
    _::FakePoint3 kVert4(((ObstacleData*)aspObstacleData)->kMinBoundsCur.x, ((ObstacleData*)aspObstacleData)->kMaxPoint.y,
                         ((ObstacleData*)aspObstacleData)->kMaxPoint.z);
    NiPointer<AnimIdle> spBoxGeom(
        CreateBoxMesh(kVert4, kCorner1, kCorner5, kCorner2, kPt2, kPoint5, kVert0, kCorner6, kBoxColor, true));
    ((AnimIdle*)spBoxGeom)->FUN_00440460(((ObstacleData*)aspObstacleData)->kTranslate);
    ((AnimIdle*)spBoxGeom)->FUN_0043fa80(((ObstacleData*)aspObstacleData)->acRotate);
    ((ObstacleData*)aspObstacleData)->m_kGeometry = spBoxGeom;
    spResult = spBoxGeom;
}
}  // namespace fnv_006c5840

template <class T> class SPtr
{
  public:
    T* m_pObject;
    SPtr(T* p);
    ~SPtr();
    operator T*() const;
    T* operator->() const;
};
struct AVObj;
struct UpdData
{
    float fTime;
    bool bA;
    bool bB;
    int unk08;
    UpdData(float t, bool a, bool b);
};
struct NodeX
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual void vfb4();
    virtual void vfb8();
    virtual void vfbc();
    virtual void vfc0();
    virtual void vfc4();
    virtual void vfc8();
    virtual void vfcc();
    virtual void vfd0();
    virtual void vfd4();
    virtual void vfd8();
    virtual void AttachChildX(AVObj* child, bool firstAvail);
    virtual void vfe0();
    virtual void vfe4();
    virtual void DetachChildX(AVObj* child);
    virtual void vfec();
    void Func5a040();
    void UpdateX(UpdData& data);
};
struct Owner88
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
    SPtr<AVObj> pSceneObject;
};
struct ObstMgr6c5b20
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
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    SPtr<NodeX> m_pController;
    void Helper5840(SPtr<Owner88>& owner, SPtr<AVObj>& out);
    void FUN_006c5b20(SPtr<Owner88>& owner);
};

// @fnv 0x006c5b20
void ObstMgr6c5b20::FUN_006c5b20(SPtr<Owner88>& owner)
{
    if (owner->pSceneObject)
    {
        m_pController->DetachChildX(owner->pSceneObject);
    }
    SPtr<AVObj> spChild(0);
    Helper5840(owner, spChild);
    m_pController->AttachChildX(spChild, true);
    m_pController->Func5a040();
    UpdData kData(0.0f, false, false);
    m_pController->UpdateX(kData);
}

class Obj6C5;

class Handle6C5
{
  public:
    Obj6C5* Get() const;
    void Reset(Obj6C5* pkObject);

    Obj6C5* m_pPointer;
};

class Obj6C5
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3C();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4C();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual void vfn5C();
    virtual void vfn60();
    virtual void vfn64();
    virtual void vfn68();
    virtual void vfn6C();
    virtual void vfn70();
    virtual void vfn74();
    virtual void vfn78();
    virtual void vfn7C();
    virtual void vfn80();
    virtual void vfn84();
    virtual void vfn88();
    virtual void vfn8C();
    virtual void vfn90();
    virtual void vfn94();
    virtual void vfn98();
    virtual void vfn9C();
    virtual void vfnA0();
    virtual void vfnA4();
    virtual void vfnA8();
    virtual void vfnAC();
    virtual void vfnB0();
    virtual void vfnB4();
    virtual void vfnB8();
    virtual void vfnBC();
    virtual void vfnC0();
    virtual void vfnC4();
    virtual void vfnC8();
    virtual void vfnCC();
    virtual void vfnD0();
    virtual void vfnD4();
    virtual void vfnD8();
    virtual void vfnDC();
    virtual void vfnE0();
    virtual void vfnE4();
    virtual void Attach(Obj6C5* pkChild);

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
    Handle6C5 m_kChild;
};

class Owner6C5
{
  public:
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
    Handle6C5 m_kRoomNode;

    void AttachChildFromSource(Handle6C5& kSource);
};

// If both this object and the source hold a child, attaches the source's child to this object and clears the source's child handle.
// @fnv 0x006c5c50
void Owner6C5::AttachChildFromSource(Handle6C5& kSource)
{
    if (m_kRoomNode.Get() && kSource.Get()->m_kChild.Get())
    {
        m_kRoomNode.Get()->Attach(kSource.Get()->m_kChild.Get());
        kSource.Get()->m_kChild.Reset(0);
    }
}

struct NavMeshInfoY;
struct NavMeshY
{
    unsigned int GetInfoCount();
    NavMeshInfoY* GetNavMeshInfo();
};
struct NavMeshPtrY
{
    NavMeshY* m_pObject;
    NavMeshY* operator->() const;
};
struct InfoEntryY
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    InfoEntryY(NavMeshInfoY* info, unsigned int index);
};
struct InfoEntryArrY
{
    void* vt;
    InfoEntryY** data;
    unsigned int cap;
    unsigned int count;
    NavMeshInfoY* m_pNavigationMesh;
    unsigned int GetSize();
    void Clear(bool bFree);
    void SetAllocSize(unsigned int uiSize);
    unsigned int Add(InfoEntryY*& item);
    void RebuildFromNavMesh(const NavMeshPtrY& apSearchNavMesh);
};

// @fnv 0x006dfba0
void InfoEntryArrY::RebuildFromNavMesh(const NavMeshPtrY& apNavMesh)
{
    unsigned int ItemUpdateArray = apNavMesh->GetInfoCount();
    if (!m_pNavigationMesh || GetSize() != ItemUpdateArray)
    {
        Clear(false);
        SetAllocSize(ItemUpdateArray);
        for (unsigned int i = 0; i < ItemUpdateArray; i++)
        {
            InfoEntryY* pEntry = new InfoEntryY(apNavMesh->GetNavMeshInfo(), i);
            Add(pEntry);
        }
        m_pNavigationMesh = apNavMesh->GetNavMeshInfo();
    }
}

struct FUN_00963d60_shell
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
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;

    BSSimpleList<int>* unk60c;
    void FUN_00963d60(int param_2);
};
// Walks the list at unk60c and deletes each entry whose stored value at offset 8 equals param_2, restarting from the head after each removal.
// @fnv 0x00963d60
void FUN_00963d60_shell::FUN_00963d60(int param_2)
{
    BSSimpleList<int>* pNode;
    int pEntry;
    int pEntryCopy;

    if (unk60c == 0 || param_2 == 0)
        return;
    pNode = unk60c;
    pEntry = 0;
    while (pNode != 0 && *_ref_006815c0(pNode) != 0)
    {
        pEntry = *_ref_006815c0(pNode);
        if (pEntry != 0 && param_2 == *(int*)((char*)pEntry + 8))
        {
            ((Call_00905330*)pNode)->_ref_00905330((bhkRigidBody**)&pEntry);
            pEntryCopy = pEntry;
            ::operator delete((void*)pEntryCopy);
            pNode = unk60c;
        }
        else
        {
            pNode = _ref_00726070(pNode);
        }
    }
}

namespace s60 {
struct Form;
struct Door;
int __fastcall FUN_00401170(Form* f);
bool __fastcall FUN_00518080(Door* d);
struct Ref
{
    Form* FUN_007af430();
    unsigned int FUN_0084e3a0();
};
struct L1
{
    void* a;
    void* b;
    bool FUN_005f65d0(Ref* const& r);
    void FUN_00905330(Ref* const& r);
};
struct L2
{
    void* a;
    void* b;
    bool FUN_005f65d0(const unsigned int& r);
    void FUN_005ae3d0(const unsigned int& r);
};
}
using namespace s60;
class Own60
{
  public:
    char pad[0x2c];
    L1 m_2c;
    char padCur[0xf0 - 0x34];
    L1 m_f0;
    L2 m_f8;
    void FUN_006c0c80(Ref* r);
    void FUN_006c1060(Ref* ref);
};
// @fnv 0x006c1060
void Own60::FUN_006c1060(Ref* ref)
{
    Form* pForm = ref->FUN_007af430();
    if (FUN_00401170(pForm) == 0x1c)
    {
        Door* door = (Door*)pForm;
        if (!FUN_00518080(door))
            FUN_006c0c80(ref);
    }
    m_2c.FUN_00905330(ref);
    if (m_f0.FUN_005f65d0(ref))
    {
        m_f0.FUN_00905330(ref);
    }
    else if (!m_f8.FUN_005f65d0(ref->FUN_0084e3a0()))
    {
        m_f8.FUN_005ae3d0(ref->FUN_0084e3a0());
    }
}

struct Vector3
{
    float x;
    float y;
    float z;
};

struct RotationMatrix
{
    void FUN_00439ef0(Vector3* result, const Vector3* input);
};

struct WorldObject;

struct Reference
{
    WorldObject* FUN_00559450();
};

extern float g_0106c3a4;
extern float g_0106c3a8;

// @fnv 0x006c3440
void __cdecl FUN_006c3440(Reference* reference)
{
    Vector3 transformed;
    reinterpret_cast<RotationMatrix*>(reinterpret_cast<char*>(reference->FUN_00559450()) + 0x64)
        ->FUN_00439ef0(&transformed,
                       reinterpret_cast<const Vector3*>(reinterpret_cast<char*>(reference->FUN_00559450()) + 0x58));

    if (transformed.z < g_0106c3a4)
    {
        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(reference->FUN_00559450()) + 0x74) = 0;
    }
    else
    {
        float zLimit = g_0106c3a4 * 2.0;
        if (zLimit > transformed.z && transformed.x < g_0106c3a8 && transformed.y < g_0106c3a8)
        {
            *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(reference->FUN_00559450()) + 0x74) = 0;
        }
        else
        {
            *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(reference->FUN_00559450()) + 0x74) = 1;
        }
    }
}

namespace fnv_006c3640 {
struct AutoMemHelper
{
    int old;
    AutoMemHelper(int, bool, char*, int);
    ~AutoMemHelper();
};
extern "C" char DAT_0106c3f0;
extern "C" char DAT_0106c498;
extern "C" char DAT_011d73e4;
extern "C" char DAT_011f6394;
extern "C" char DAT_0106c398;
struct SettingShell
{
    bool* FUN_00408d60();
};
struct TimeShell
{
    float FUN_0084d030();
};
struct TimerShell
{
    bool FUN_00483710();
};
struct ArrayShell
{
    unsigned FUN_0084e3a0();
};
struct PathShell
{
    void FUN_006ebc70();
    bool FUN_006ebc90();
    void FUN_006ebcd0();
};
PathShell* GetPathManager();
struct CellShell
{
    unsigned char FUN_00552bb0();
    void FUN_006a5ca0();
};
CellShell* FUN_00552ba0();
struct C006c3640
{
    char pad0[0x18];
    bool flag;
    char pad19[0x190 - 0x19];
    int state;
    float time;
    char pad198[8];
    TimerShell timer;
    void FUN_004538a0(char*);
    void FUN_004538c0();
    void FUN_006c47e0();
    void ProcessAddedRefs();
    void ProcessDoorObstacles();
    void FUN_006c5190();
    void FUN_006c4970();
    bool FUN_006c4900();
    void FUN_006c4c30();
    void FUN_006c4ad0();
    void FUN_006c49e0();
    void FUN_006c4d30();
    unsigned FUN_006c3920();
    unsigned FUN_006c3970();
    void MatchPortalEdges();
    bool FUN_006c44d0();
    bool ClearOwnedObjects();
    void ProcessObstacleTasks();
    void FUN_006c3640();
};
// @fnv 0x006c3640
void C006c3640::FUN_006c3640()
{
    AutoMemHelper mem(0x2e, true, &DAT_0106c3f0, 0x508);
    if (!*((SettingShell*)&DAT_011d73e4)->FUN_00408d60())
        return;
    FUN_004538a0(&DAT_0106c498);
    timer.FUN_00483710();
    bool changed = false;
    time -= ((TimeShell*)&DAT_011f6394)->FUN_0084d030();
    switch (state)
    {
    case 0: {
        FUN_006c47e0();
        ProcessAddedRefs();
        ProcessDoorObstacles();
        FUN_006c5190();
        FUN_006c4970();
        FUN_006c4900();
        if (flag)
        {
            FUN_006c4c30();
            flag = false;
        }
        else
        {
            FUN_006c4ad0();
            FUN_006c49e0();
        }
        FUN_006c4d30();
        unsigned c = FUN_006c3920();
        unsigned l = FUN_006c3970();
        bool e = ((ArrayShell*)((char*)this + 0x12c))->FUN_0084e3a0() > 0;
        bool j = false;
        if (e)
        {
            if (l > 0)
            {
                if (l == c && time <= 0.0)
                    j = true;
            }
            else if (time <= 0.0)
                j = true;
        }
        else if (l > 0 && l == c && time <= 0.0)
            j = true;
        if (j)
        {
            GetPathManager()->FUN_006ebc70();
            state = 1;
        }
        break;
    }
    case 1:
        if (GetPathManager()->FUN_006ebc90())
        {
            unsigned processed = FUN_006c3920();
            unsigned background = FUN_006c3970();
            if (background > 0)
            {
                MatchPortalEdges();
                changed = FUN_006c44d0();
                ClearOwnedObjects();
            }
            ProcessObstacleTasks();
            GetPathManager()->FUN_006ebcd0();
            state = 0;
            time = *(float*)&DAT_0106c398;
            if (changed && FUN_00552ba0()->FUN_00552bb0())
                FUN_00552ba0()->FUN_006a5ca0();
        }
        break;
    }
    timer.FUN_00483710();
    FUN_004538c0();
}
}  // namespace fnv_006c3640

namespace fnv_006c5190 {
struct ObjX
{
    virtual void v0(), v1(), v2(), v3(), v4(), v5(), v6(), v7(), v8(), v9(), v10(), v11(), v12(), v13(), v14(), v15(),
        v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31(),
        v32(), v33(), v34(), v35(), v36(), v37(), v38(), v39(), v40(), v41(), v42(), v43(), v44(), v45(), v46(), v47(),
        v48(), v49(), v50(), v51(), v52(), v53(), v54(), v55(), v56(), v57(), v58(), v59(), v60(), v61(), v62(), v63(),
        v64(), v65(), v66(), v67(), v68(), v69(), v70(), v71(), v72(), v73(), v74(), v75(), v76(), v77(), v78(), v79(),
        v80(), v81(), v82(), v83(), v84(), v85(), v86(), v87(), v88(), v89(), v90(), v91(), v92(), v93(), v94(), v95(),
        v96(), v97(), v98(), v99(), v100(), v101(), v102(), v103(), v104(), v105(), v106(), v107(), v108(), v109(),
        v110(), v111(), v112(), v113(), v114(), v115();
    virtual int F1d0();
    int FUN_0084e3a0();
};
struct ElemX
{
    int FUN_0068efb0();
    char pad[0x78];
    struct SetX
    {
        void FUN_007cb2e0(const int& k);
    } m78;
};
struct PtrX
{
    void* m_p;
    PtrX(void* p);
    PtrX(const PtrX& o);
    ~PtrX();
    ElemX* FUN_00559450();
};
void* FUN_00aa13e0(unsigned n);
struct NewX
{
    void* operator new(unsigned n)
    {
        return FUN_00aa13e0(n);
    }
    static void operator delete(void*, unsigned int);
    char pad[0x1c];
    NewX();
};
struct ArrX
{
    PtrX& FUN_00877a30(unsigned i);
    unsigned FUN_0044ddc0();
};
struct HolderX
{
    char pad[0xc];
    ArrX arr;
};
struct QArrX : ArrX
{
    int a, b, c, d, e;
    QArrX();
    ~QArrX();
};
bool FUN_006c34f0(ObjX* o, PtrX* p);
bool FUN_006c2050(PtrX& e, QArrX* q);
struct NodeX
{
    bool FUN_008256d0();
    ObjX** FUN_006815c0();
    NodeX* FUN_00726070();
    void FUN_00905330(ObjX** o);
};
struct TblX
{
    void FUN_006c7a30(PtrX& e, int n);
};
struct M100
{
    int RemoveKey(int k);
};
struct M110
{
    void FUN_006c6920(int k, PtrX p);
};
class SelfX
{
  public:
    char pad[0xf0];
    NodeX m_kList;
    char pad2[0x100 - 0xf0 - 1];
    M100 m100;
    char pad3[0xf];
    M110 m110;
    TblX* FUN_006c5ef0(int k);
    bool FUN_006c5190();
};
// For each object passing F1d0, builds data, updates entries through FUN_006c5ef0, removes its key from m100, and passes the data to m110.
// @fnv 0x006c5190
bool SelfX::FUN_006c5190()
{
    if (m_kList.FUN_008256d0())
        return false;
    bool bChanged = false;
    NodeX* pkNode = &m_kList;
    while (pkNode && !pkNode->FUN_008256d0())
    {
        ObjX* pkObj = *pkNode->FUN_006815c0();
        if (pkObj->F1d0())
        {
            PtrX spScreenData(new NewX);
            if (FUN_006c34f0(pkObj, &spScreenData))
            {
                for (unsigned i = 0; i < ((HolderX*)spScreenData.FUN_00559450())->arr.FUN_0044ddc0(); i++)
                {
                    QArrX kArr;
                    if (FUN_006c2050(((HolderX*)spScreenData.FUN_00559450())->arr.FUN_00877a30(i), &kArr))
                    {
                        for (unsigned j = 0; j < kArr.FUN_0044ddc0(); j++)
                        {
                            FUN_006c5ef0(kArr.FUN_00877a30(j).FUN_00559450()->FUN_0068efb0())
                                ->FUN_006c7a30(((HolderX*)spScreenData.FUN_00559450())->arr.FUN_00877a30(i), 0x30);
                            ((HolderX*)spScreenData.FUN_00559450())
                                ->arr.FUN_00877a30(i)
                                .FUN_00559450()
                                ->m78.FUN_007cb2e0(kArr.FUN_00877a30(j).FUN_00559450()->FUN_0068efb0());
                        }
                    }
                }
                m100.RemoveKey(pkObj->FUN_0084e3a0());
                m110.FUN_006c6920(pkObj->FUN_0084e3a0(), spScreenData);
                bChanged = true;
            }
            m_kList.FUN_00905330(&pkObj);
            pkNode = &m_kList;
        }
        else
        {
            pkNode = pkNode->FUN_00726070();
        }
    }
    return bChanged;
}
}  // namespace fnv_006c5190

namespace s6c3ba0 {

extern const float DAT_0106c3a0;

void FUN_005b5e40(const char* pcFormat, ...);

static const char s_szBadTriangle[] =
    "PATHFINDING: (NavMesh Obstacle Manager) Bad triangle index while trying to reconnect portals";

struct NiPoint3
{
    float x;
    float y;
    float z;

    NiPoint3 FUN_00439ef0(const NiPoint3& kOther) const;
    float GetSquaredXYLength() const;
};

struct EdgeVertices
{
    NiPoint3* m_pkStart;
    NiPoint3* m_pkEnd;

    EdgeVertices();
};

struct Triangle
{
    bool FUN_00691140(unsigned int uiFlag);
};

struct NavMesh
{
    unsigned int FUN_00558200();
    Triangle* FUN_005582f0(unsigned short m_usTriangleID);
    EdgeVertices FUN_0068f040(unsigned short m_usTriangleID, int m_iEdgeNumber);
};

template <class T> class NiPointer
{
  public:
    NiPointer();
    ~NiPointer();

    NiPointer& FUN_0042f4c0(const NiPointer& kOther);
    T* FUN_00458b50() const;
    operator T*() const;

    T* m_pObject;
};

struct NavMeshInfo;

struct Portal
{
    int unk00;
    int unk04;
    int unk08;
};

struct PortalInfo
{
    NavMeshInfo* m_pkInfo;
    unsigned short m_usTriangle;
    int m_iEdge;

    PortalInfo();
    PortalInfo(const Portal* pkPortal);
};

struct EdgeLink
{
    int unk00;
    int m_iID;
    unsigned short m_usTriangle;
};

struct PortalLink
{
    int m_iID;
    unsigned short m_usTriangle;

    PortalLink(int m_uiSoundID, unsigned short m_usTriangleID);
};

struct NavMeshInfo
{
    void FUN_0069ad00(NiPointer<NavMesh>& apSearchNavMesh);
    bool FUN_0068f340(PortalInfo& kFirstPortal, PortalInfo& kLinked);
    EdgeLink* FUN_0068f230(unsigned short m_usTriangleID, int m_iEdgeNumber);
};

struct PortalArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;

    unsigned int FUN_0044ddc0();
    Portal* FUN_006a1440(unsigned int uiIndex);
    void FUN_00691c90(unsigned int uiIndex, bool bShift);
};

struct PortalSet
{
    PortalArray m_kPortals;
    PortalArray m_kOpenPortals;
};

struct Obstacle
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    NavMeshInfo* m_pkInfo;
    NiPointer<NavMeshInfo> m_spInfo;
    NiPointer<NavMesh> m_spNavMesh;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    PortalSet m_kPortalSet;
    bool m_bValueAt0C;
};

struct ObstacleArray
{
    unsigned int FUN_0044ddc0();
    Obstacle*& FUN_00877a30(unsigned int uiIndex);
};

struct ObstacleManager
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
    ObstacleArray m_kObstacles;

    void ConnectEdges(NiPointer<NavMesh>& spMeshA, PortalInfo& kPortalA, NiPointer<NavMesh>& spMeshB,
                      PortalInfo& kPortalB);
    void AddAndRunFromSources(NiPointer<NavMesh>& apSearchNavMesh, PortalInfo& kFirstPortal, PortalLink& kLink);
    bool MatchPortalEdges();
};

// Checks portal edges across obstacles and open portals, calling connection routines when endpoints are within the squared-distance threshold.
// @fnv 0x006c3ba0
bool ObstacleManager::MatchPortalEdges()
{
    unsigned int ItemUpdateArray = m_kObstacles.FUN_0044ddc0();
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        Obstacle* pkOwner = m_kObstacles.FUN_00877a30(i);
        if (!pkOwner->m_spNavMesh.FUN_00458b50())
            continue;
        PortalSet* pkSet = &pkOwner->m_kPortalSet;
        for (unsigned int j = 0; j < pkSet->m_kPortals.FUN_0044ddc0(); j++)
        {
            PortalInfo kFirstPortal(pkSet->m_kPortals.FUN_006a1440(j));
            if (kFirstPortal.m_usTriangle >= ((NavMesh*)pkOwner->m_spNavMesh)->FUN_00558200())
            {
                FUN_005b5e40(s_szBadTriangle);
                continue;
            }
            NiPoint3 kEdgeStart = *((NavMesh*)pkOwner->m_spNavMesh)
                                       ->FUN_0068f040(kFirstPortal.m_usTriangle, kFirstPortal.m_iEdge)
                                       .m_pkStart;
            NiPoint3 kCornerB = *((NavMesh*)pkOwner->m_spNavMesh)
                                     ->FUN_0068f040(kFirstPortal.m_usTriangle, kFirstPortal.m_iEdge)
                                     .m_pkEnd;
            bool bPortalEdgeMatched = false;
            for (unsigned int k = 0; k < ItemUpdateArray; k++)
            {
                if (k == i)
                    continue;
                Obstacle* pkOtherObstacle = m_kObstacles.FUN_00877a30(k);
                if (!pkOtherObstacle->m_spNavMesh.FUN_00458b50())
                    continue;
                PortalSet* pkOtherPortals = &pkOtherObstacle->m_kPortalSet;
                for (unsigned int l = 0; l < pkOtherPortals->m_kPortals.FUN_0044ddc0(); l++)
                {
                    PortalInfo kOther(pkOtherPortals->m_kPortals.FUN_006a1440(l));
                    if (kOther.m_usTriangle >= ((NavMesh*)pkOtherObstacle->m_spNavMesh)->FUN_00558200())
                    {
                        FUN_005b5e40(s_szBadTriangle);
                        continue;
                    }
                    NiPoint3 kStartA = *((NavMesh*)pkOtherObstacle->m_spNavMesh)
                                            ->FUN_0068f040(kOther.m_usTriangle, kOther.m_iEdge)
                                            .m_pkStart;
                    NiPoint3 kB2 = *((NavMesh*)pkOtherObstacle->m_spNavMesh)
                                        ->FUN_0068f040(kOther.m_usTriangle, kOther.m_iEdge)
                                        .m_pkEnd;
                    if (kCornerB.FUN_00439ef0(kStartA).GetSquaredXYLength() < DAT_0106c3a0 &&
                        kEdgeStart.FUN_00439ef0(kB2).GetSquaredXYLength() < DAT_0106c3a0)
                    {
                        ConnectEdges(pkOwner->m_spNavMesh, kFirstPortal, pkOtherObstacle->m_spNavMesh, kOther);
                        if (1)
                        {
                        }
                        pkOwner->m_bValueAt0C = true;
                        pkOtherObstacle->m_bValueAt0C = true;
                        pkSet->m_kPortals.FUN_00691c90(j, true);
                        j--;
                        pkOtherPortals->m_kPortals.FUN_00691c90(l, true);
                        l--;
                        bPortalEdgeMatched = true;
                        break;
                    }
                }
                if (bPortalEdgeMatched)
                    break;
                if (bPortalEdgeMatched)
                    break;
            }
            if (!bPortalEdgeMatched)
            {
                for (unsigned int m = 0; m < pkSet->m_kOpenPortals.FUN_0044ddc0(); m++)
                {
                    PortalInfo kOpenInfo(pkSet->m_kOpenPortals.FUN_006a1440(m));
                    PortalInfo kLinked;
                    if (((NavMeshInfo*)pkOwner->m_spInfo)->FUN_0068f340(kOpenInfo, kLinked))
                    {
                        if (kOpenInfo.m_pkInfo == kLinked.m_pkInfo)
                            continue;
                        NiPointer<NavMesh> apSearchNavMesh;
                        Obstacle* pkMatched = 0;
                        for (unsigned int n = 0; n < ItemUpdateArray; n++)
                        {
                            if (m_kObstacles.FUN_00877a30(n)->m_pkInfo == kLinked.m_pkInfo)
                            {
                                apSearchNavMesh.FUN_0042f4c0(m_kObstacles.FUN_00877a30(n)->m_spNavMesh);
                                pkMatched = m_kObstacles.FUN_00877a30(n);
                                break;
                            }
                        }
                        if (!(NavMesh*)apSearchNavMesh)
                        {
                            kLinked.m_pkInfo->FUN_0069ad00(apSearchNavMesh);
                            pkMatched = 0;
                        }
                        if (!(NavMesh*)apSearchNavMesh)
                        {
                            PortalInfo kInfo2(pkSet->m_kOpenPortals.FUN_006a1440(m));
                            EdgeLink* pkEdge =
                                ((NavMeshInfo*)pkOwner->m_spInfo)->FUN_0068f230(kInfo2.m_usTriangle, kInfo2.m_iEdge);
                            if (pkEdge)
                            {
                                PortalLink kLink(pkEdge->m_iID, pkEdge->m_usTriangle);
                                AddAndRunFromSources(pkOwner->m_spNavMesh, kFirstPortal, kLink);
                                if (1)
                                {
                                }
                                pkSet->m_kPortals.FUN_00691c90(j, true);
                                j--;
                                bPortalEdgeMatched = true;
                                break;
                            }
                        }
                        else
                        {
                            if (kLinked.m_usTriangle >= ((NavMesh*)apSearchNavMesh)->FUN_00558200())
                                continue;
                            if (((NavMesh*)apSearchNavMesh)->FUN_005582f0(kLinked.m_usTriangle)->FUN_00691140(0x20))
                                continue;
                            NiPoint3 kA3 = *((NavMesh*)apSearchNavMesh)
                                                ->FUN_0068f040(kLinked.m_usTriangle, kLinked.m_iEdge)
                                                .m_pkStart;
                            NiPoint3 kB3 = *((NavMesh*)apSearchNavMesh)
                                                ->FUN_0068f040(kLinked.m_usTriangle, kLinked.m_iEdge)
                                                .m_pkEnd;
                            if (kCornerB.FUN_00439ef0(kA3).GetSquaredXYLength() < DAT_0106c3a0 &&
                                kEdgeStart.FUN_00439ef0(kB3).GetSquaredXYLength() < DAT_0106c3a0)
                            {
                                ConnectEdges(pkOwner->m_spNavMesh, kFirstPortal, apSearchNavMesh, kLinked);
                                if (1)
                                {
                                }
                                pkOwner->m_bValueAt0C = true;
                                if (pkMatched)
                                    pkMatched->m_bValueAt0C = true;
                                pkSet->m_kPortals.FUN_00691c90(j, true);
                                j--;
                                bPortalEdgeMatched = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

}

struct LocalLink
{
    unsigned int id;
    unsigned short triangle;
};
struct LocalEdge
{
    LocalLink link;
    int edge;
};
struct LocalConnection
{
    unsigned int unk00;
    LocalLink link;
    LocalConnection();
};
struct LocalTriangle
{
    void Connect(int, unsigned short);
};
struct LocalMesh
{
    unsigned short AddConnection(const LocalConnection&);
    LocalTriangle* GetTriangle(unsigned short);
};
struct LocalMeshPtr
{
    LocalMesh* Get();
};
struct LocalConnector
{
    bool ConnectEdges(LocalMeshPtr&, const LocalEdge&, LocalMeshPtr&, const LocalEdge&);
};
// Adds cross-referencing connections between two mesh triangles via their edges and returns true.
// @fnv 0x006c4390
bool LocalConnector::ConnectEdges(LocalMeshPtr& first, const LocalEdge& firstEdge, LocalMeshPtr& second,
                                  const LocalEdge& secondEdge)
{
    LocalConnection firstConnection4;
    firstConnection4.link.id = secondEdge.link.id;
    firstConnection4.link.triangle = secondEdge.link.triangle;
    unsigned short firstIndex = first.Get()->AddConnection(firstConnection4);
    first.Get()->GetTriangle(firstEdge.link.triangle)->Connect(firstEdge.edge, firstIndex);
    LocalConnection secondConnection5;
    secondConnection5.link.id = firstEdge.link.id;
    secondConnection5.link.triangle = firstEdge.link.triangle;
    unsigned short secondIndex3 = second.Get()->AddConnection(secondConnection5);
    second.Get()->GetTriangle(secondEdge.link.triangle)->Connect(secondEdge.edge, secondIndex3);
    return true;
}

#include <xmmintrin.h>
namespace fnv_006c4d30 {
struct V3
{
    float x, y, z;
    void FUN_006815c0();
    V3* FUN_00439ef0(V3* ret, const V3* other);
    float FUN_004a7290();
};
struct BodyRef
{
    void* FUN_004b4ec0();
};
struct RigidBody
{
    BodyRef* GetReferenceFlags();
};
struct RigidBodyPtr1920
{
    RigidBody* m_pObject;
    RigidBody* FUN_00559450() const;
};
struct ObstData1920
{
    int unk00;
    int unk04;
    int unk08;
    RigidBodyPtr1920 m_pRigidBody;
    V3 pos;
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
    unsigned int lastUpdate;
};
struct ObstPtr1920
{
    ObstData1920* m_pObject;
    ObstPtr1920(const ObstPtr1920& other);
    ~ObstPtr1920();
    ObstData1920* FUN_00559450() const;
};
struct ObstList
{
    ObstPtr1920& FUN_006815c0();
    ObstList* FUN_00726070();
    bool FUN_004a4460();
};
__declspec(align(16)) struct Holder3
{
    __m128 q;
    void FUN_004a3c90(void* n);
};
extern "C" void __cdecl FUN_00458620(V3* out, Holder3* in);
extern const float kObsDist;
struct GlobalObject_0044f440
{
    float* FUN_00403e20();
};
extern GlobalObject_0044f440 g_011d71b0;
struct TimeGlobal
{
    unsigned int FUN_00825c00();
};
extern TimeGlobal g_timeGlobal;
struct ObsMgr
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
    ObstList list3C;
    void FUN_006c1760(ObstPtr1920* sp);
    void FUN_006c4d30();
};

// For each obstacle, compares a converted vector with its position and calls a method when distance and elapsed-time thresholds are met.
// @fnv 0x006c4d30
void ObsMgr::FUN_006c4d30()
{
    unsigned int uiTimeLimitMs = (unsigned int)(*g_011d71b0.FUN_00403e20() * 1000.0);
    for (ObstList* node = &list3C; node && !node->FUN_004a4460();)
    {
        ObstPtr1920 item(node->FUN_006815c0());
        node = node->FUN_00726070();
        Holder3 h;
        h.FUN_004a3c90(item.FUN_00559450()->m_pRigidBody.FUN_00559450()->GetReferenceFlags()->FUN_004b4ec0());
        V3 v;
        v.FUN_006815c0();
        FUN_00458620(&v, &h);
        V3 tmp;
        if (v.FUN_00439ef0(&tmp, &item.FUN_00559450()->pos)->FUN_004a7290() > kObsDist &&
            g_timeGlobal.FUN_00825c00() - item.FUN_00559450()->lastUpdate >= uiTimeLimitMs)
            FUN_006c1760(&item);
    }
}
}  // namespace fnv_006c4d30

static const float s_fDefaultInterval = 0.5f;

// Initializes the NavMeshObstacleManager, setting up task queues, timers, and default update interval.
// @fnv 0x006c02c0
FUN_006c02c0::FUN_006c02c0()
    : m_kTasks(0x25), m_kAddQueue(7, 8), m_kRemoveQueue(7, 8), m_kObstacles(0x25), m_kTasksB(0x25), m_kTasksC(0x25),
      m_kRefMap(0x25), m_spTask(0), m_kUpdateTimer("Pathing", "Obstacle Manager Update", 1, 1),
      m_kBackgroundTimer("Pathing", "Navmesh Background Update", 0, 1)
{
    AutoMemContext kMemContext(
        MEM_CONTEXT_MEM_CONTEXT_NAVMESH, true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Pathfinding\\NavMeshObstacleManager.cpp", 0xb8);
    m_iCount120 = 0;
    m_iCount124 = 0;
    m_bPaused = false;
    m_iTask190 = 0;
    m_fInterval = s_fDefaultInterval;
    m_bModifierActive = false;
}

namespace fnv_006c0720 {
struct AutoMemContextScope
{
    int m_eMemoryContext;
    AutoMemContextScope(int, bool, const char*, int);
    ~AutoMemContextScope();
};
struct NavMeshObstacleManagerObj
{
    unsigned char data[0x1c0];
    NavMeshObstacleManagerObj();
    ~NavMeshObstacleManagerObj();
};
// Returns the address of a function-local static NavMeshObstacleManagerObj after creating an AutoMemContextScope.
// @fnv 0x006c0720
NavMeshObstacleManagerObj* GetNavMeshObstacleManager()
{
    AutoMemContextScope tempMemContext(
        0x2e, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Pathfinding\\NavMeshObstacleManager.cpp",
        0xd2);
    static NavMeshObstacleManagerObj kInstance;
    return &kInstance;
}
}  // namespace fnv_006c0720

namespace fnv_006c5ff0 {
struct FUN_006c6e60_shell
{
    void Push();
};
struct FUN_006c5ff0_shell
{
    char _pad0[32];
    RecursiveSpinLock _lock20;
    FUN_006c6e60_shell* FUN_00449f80(int*);
    void FUN_006c5ff0(int*);
};
// Locks _lock20, calls Push on the object returned by FUN_00449f80(a1), then unlocks _lock20.
// @fnv 0x006c5ff0
void FUN_006c5ff0_shell::FUN_006c5ff0(int* a1)
{
    _lock20.Lock(0);
    FUN_00449f80(a1)->Push();
    _lock20.Unlock();
}
}  // namespace fnv_006c5ff0

struct PendingRefs0c80
{
    ::TESObjectREFR* item;
    PendingRefs0c80* next;
    void FUN_00905330(::TESObjectREFR** item);
};

struct RemovedIDs0c80
{
    unsigned int item;
    RemovedIDs0c80* next;
    bool IsInList(const unsigned int& item);
    void AddTail(const unsigned int& item);
};

struct ReferenceMap0c80
{
    void* vtable;
    unsigned int bucketCount;
    void* buckets;
    unsigned int count;
    bool FUN_006c62d0(unsigned int key, ::RefObstPtr1920& value);
};

struct RemoveObstacleManagerView
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    ReferenceMap0c80 references;
    PendingRefs0c80 pending;
    RemovedIDs0c80 removed;
    void FUN_006c0c80(::TESObjectREFR* ref);
};

// Adds ref to pending; if its FormID is not removed and has a map entry, processes each obstacle and records the FormID.
// @fnv 0x006c0c80
void RemoveObstacleManagerView::FUN_006c0c80(::TESObjectREFR* ref)
{
    if (!reinterpret_cast< ::SettingT< ::INISettingCollection>*>(&::fnv_006c0c30::g_011d73e4)->Bool()->b)
        return;
    pending.FUN_00905330(&ref);
    if (!removed.IsInList(reinterpret_cast< ::TESForm*>(ref)->GetFormID()))
    {
        ::RefObstPtr1920 spArray(0);
        unsigned int i;
        if (references.FUN_006c62d0(reinterpret_cast< ::TESForm*>(ref)->GetFormID(), spArray))
        {
            for (i = 0; i < spArray.Get()->kObstacles.GetSize(); i++)
                reinterpret_cast< ::S_this*>(this)->FUN_006c1e00(
                    static_cast< ::S_param*>(spArray.Get()->kObstacles.GetAt(i).Get()->m_pRigidBody.Get()));
            removed.AddTail(reinterpret_cast< ::TESForm*>(ref)->GetFormID());
        }
    }
}
