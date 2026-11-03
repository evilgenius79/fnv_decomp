
// src/bsmenu/tile_ob1_variant.cpp - flag-variant unit created 2026-10-17 for tile.cpp functions whose originals inline helpers (/Od /Ob1).
// tile.cpp itself cannot take /Ob1 (its 50 accepted functions call those helpers out of line), so these come from a
// different object; same declarations as tile.cpp. Move them to their real unit once identified.

#include "Tile__FloatAction.h"
#include "tile_packet_decls.h"

class NiNode;
class NiProperty;
class NiAVObject {
public:
    virtual ~NiAVObject();
    virtual void* GetRTTI() const;
    virtual NiNode* IsFadeNode();
    virtual NiNode* IsSceneNode();
    virtual void* IsSwitchNode();
    virtual void* IsMultiBoundNode();
    virtual void* IsGeometry();
};
template<class T> class ChildPtr {
public:
    T* m_pObject;
    __forceinline operator T*() const { return m_pObject; }
};
template<class T> class ChildArray {
public:
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    __forceinline T& GetAt(unsigned int uiIndex) const { return m_pBase[uiIndex]; }
};
class NiNode : public NiAVObject {
public:
    ChildArray<ChildPtr<NiAVObject> >& GetChildren() { return *(ChildArray<ChildPtr<NiAVObject> >*)((char*)this + 0xa0); }
};
struct TileShaderProperty;
struct PropHelper { TileShaderProperty* GetProperty(unsigned int auType); };
struct FUN_00a08720_t {
    void FUN_00a08720(NiAVObject* apObject, float afPct);
};

// @fnv 0x00a08720
void FUN_00a08720_t::FUN_00a08720(NiAVObject* apObject, float afPct)
{
    NiNode* pnode2;
    unsigned int i;
    TileShaderProperty* ptsp;
    if (!apObject)
        return;
    pnode2 = apObject->IsSceneNode();
    for (i = 0; pnode2 && i < ((ChildArray<ChildPtr<NiAVObject> >*)((char*)pnode2 + 0xa0))->m_usSize; i++)
        FUN_00a08720(((ChildArray<ChildPtr<NiAVObject> >*)((char*)pnode2 + 0xa0))->GetAt(i), afPct);
    if (apObject->IsGeometry()) {
        ptsp = ((PropHelper*)apObject)->GetProperty(3);
        if (ptsp)
            *(float*)((char*)ptsp + 0x78) = afPct;
    }
}

struct NiAVObject;
struct SoundPlaybackHandle {
    void Clear();
    bool Play(bool);
    bool SchedulePlayback(unsigned int, int);
    bool Pause();
    bool Stop();
    bool IsPlaying();
    bool IsValid();
    int GetSoundType();
    float GetVolume();
    bool SetVolume(float);
    bool SetFrequency(float);
    bool SetPlaybackFrequency(float);
    bool SetFrequencyVariance(unsigned char);
    bool SetBalance(int);
    bool SetStaticAttenuation(unsigned short);
    int GetDuration();
    bool SetPosition(void*);
    bool SetPosition(float, float, float);
    bool SetBeamEnd(void*);
    bool SetBeamEnd(float, float, float);
    void SetDistanceRange(float, float);
    void SetSoundParameters(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);
    void SetReverbAttenuation(unsigned short);
    bool SetBeamStart(float, float, float);
    unsigned int GetID();
    void SetObjectToFollow(NiAVObject*);
    void Seek(unsigned int);
    void SetFollowsListener(bool);
    void SetCompletionCallback(int*, void*);
    void SetPlayCallback(int*, void*);
    static void SetAddMovingSoundCallback(int*);
    bool Release();
    bool SetFadeInTime(unsigned int);
    bool StopWithFade(unsigned int);
    bool SetPlaybackTime(unsigned int);
    void SetTimeConstraints(unsigned char, unsigned char);
    void SetSynchStartTime(unsigned int);
    void IsSoundPlaying();
    void SetPriority(unsigned int);
    void SetAssumeSuccess(bool);
    int QState();
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    char _pad_5[3];
    int eState;
};
typedef char _sizecheck_BSSoundHandle[sizeof(SoundPlaybackHandle) == 12 ? 1 : -1];
struct FUN_00a0b110_shell : public Tile {
    void FUN_00a0b110(int);
};

struct FUN_00a011f0_shell {
    char const* FUN_00a011f0(int);
};

struct BSSoundHandleEx {
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    int eState;

    BSSoundHandleEx() : m_uiSoundResourceID(0xffffffff), m_bLooping(false), eState(0) {}
    ~BSSoundHandleEx() {}

    BSSoundHandleEx& operator=(const BSSoundHandleEx& rhs) {
        m_uiSoundResourceID = rhs.m_uiSoundResourceID;
        m_bLooping = rhs.m_bLooping;
        eState = rhs.eState;
        return *this;
    }

    bool Play(bool flag = false);
};

struct BSAudio {
    BSSoundHandleEx GetSoundHandleByEditorID(const char*, unsigned int);
};
extern BSAudio* DAT_011f6d98;

inline BSAudio* GetAudio() {
    return DAT_011f6d98;
}

// @fnv 0x00a0b110
void FUN_00a0b110_shell::FUN_00a0b110(int aiSoundType) {
    BSSoundHandleEx soundHand;
    const char* strSoundName = reinterpret_cast<FUN_00a011f0_shell*>(this)->FUN_00a011f0(aiSoundType);
    Menu* pmenu = GetMenu();

    if (pmenu && *(int*)((char*)pmenu + 0x24) == 1 && strSoundName && *strSoundName) {
        soundHand = GetAudio()->GetSoundHandleByEditorID(strSoundName, 0x121);
        soundHand.Play(false);
    }
}

extern int DAT_01094e1c;
void _NiFreeAlias(void*);
struct S00a0d390
{
    void* f0;
    int f4;
    void* f8;
    void ClearAll();
    void FUN_00a0d390();
};
// @fnv 0x00a0d390
void S00a0d390::FUN_00a0d390()
{
    int pad1;
    int pad2;
    f0 = &DAT_01094e1c;
    ClearAll();
    _NiFreeAlias(f8);
}

struct NiNode;
struct EmptyPolymorphicObject {
    void* __vecDelDtor(unsigned int);
    char _pad_0[1];
};
typedef char _sizecheck_AutoTileLock[sizeof(EmptyPolymorphicObject) == 1 ? 1 : -1];
struct FUN_00a03c90_shell : public Tile {
    Menu* FUN_00a03c90();
};

void __cdecl FUN_00a044f0();
void __cdecl _FUN_00a04500();

struct AutoTileLock_Local {
    AutoTileLock_Local() { FUN_00a044f0(); }
    ~AutoTileLock_Local() { _FUN_00a04500(); }
};

struct FUN_00a03d40_shell {
    Tile* FUN_00a03d40();
};

struct Tile_Helper {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int GetType();
};

struct TileMenu {
    char pad[0x3c];
    Menu* pMenu;
};

// @fnv 0x00a03c90
Menu* FUN_00a03c90_shell::FUN_00a03c90() {
    AutoTileLock_Local __my_auto_tile_lock;
    Tile* ptile = reinterpret_cast<FUN_00a03d40_shell*>(this)->FUN_00a03d40();
    if (ptile && reinterpret_cast<Tile_Helper*>(ptile)->GetType() == 0x389) {
        TileMenu* pmenu = (TileMenu*)ptile;
        if (pmenu)
            return pmenu->pMenu;
    }
    return 0;
}

int __cdecl FUN_00a01630(void*);
void __fastcall _FUN_00a7b300(void*);

struct GO {
    GO& operator=(void*);
};

struct Member0C {
    char pad[0x28];
    int member_28;
    GO member_2c;
};

struct Member10 {
    char pad[0x18];
    void* member_18;
};

struct __declspec(novtable) Base_00a0abe0 {
    virtual ~Base_00a0abe0() {
        _FUN_00a7b300(this);
    }
};

struct FUN_00a0abe0 : Base_00a0abe0 {
    char pad_04[0x08];
    Member0C* member_0c;
    Member10* member_10;

    virtual ~FUN_00a0abe0();
};

// @fnv 0x00a0abe0
FUN_00a0abe0::~FUN_00a0abe0() {
    void* arg;
    void* local1;
    void* local2;
    if (member_0c) {
        local2 = member_10->member_18;
        member_0c->member_28 = FUN_00a01630(local2);
        Member0C* p = member_0c;
        p->member_2c = 0;
    }
    member_0c = 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern int EmptyFS;

struct Tile__TileTemplate {
    void Clear();
};

struct NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile__TileTemplateItem___ {
    ~NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile__TileTemplateItem___() {}
    void RemoveAll();
};

struct ItemList : NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile__TileTemplateItem___ {
    ~ItemList() {
        RemoveAll();
    }
};

struct BSFixedString_Local {
    int m_str;
    ~BSFixedString_Local() {
        if (m_str == EmptyFS) {
        } else {
            long* p = (long*)(m_str - 8);
            InterlockedDecrement(p);
        }
    }
};

struct FUN_00a0c190 : Tile__TileTemplate {
    BSFixedString_Local m_str;
    char pad[8 - sizeof(BSFixedString_Local)];
    ItemList m_items;

    ~FUN_00a0c190();
};

// @fnv 0x00a0c190
FUN_00a0c190::~FUN_00a0c190() {
    int v1; int v2; int v3;
    Clear();
}

struct TileValue_00a0a270 {
    void FUN_00a0a270(float afValue, bool abClearActions);
};
struct TileValueOwner_00a01000 {
    TileValue_00a0a270* GetOrCreateTraitValue(int aiTrait);
};
struct FUN_00a012d0_t {
    void FUN_00a012d0(int aiTrait, float afValue, bool abClearActions);
};

// @fnv 0x00a012d0
void FUN_00a012d0_t::FUN_00a012d0(int aiTrait, float afValue, bool abClearActions)
{
    TileValue_00a0a270* pvalue = ((TileValueOwner_00a01000*)this)->GetOrCreateTraitValue(aiTrait);
    if (pvalue != 0)
    {
        AutoTileLock_Local __my_auto_tile_lock;
        pvalue->FUN_00a0a270(afValue, abClearActions);
    }
}

namespace fnv_00a01350 {
struct EmptyPolymorphicObject {
    void* __vecDelDtor(unsigned int);
    char _pad_0[1];
};
typedef char _sizecheck_AutoTileLock[sizeof(EmptyPolymorphicObject) == 1 ? 1 : -1];
struct FUN_00a01350_shell : public Tile {
    void FUN_00a01350(int, char*, bool);
};

struct FUN_00a01350_Value;
struct FUN_00a01350_Obj {
    FUN_00a01350_Value* GetOrCreateTraitValue(int);
};
struct FUN_00a01350_Value {
    void SetString(char*, bool);
};

// @fnv 0x00a01350
void FUN_00a01350_shell::FUN_00a01350(int aiTrait, char* apValue, bool abClearActions)
{
    FUN_00a01350_Value* pvalue = ((FUN_00a01350_Obj*)this)->GetOrCreateTraitValue(aiTrait);
    if (pvalue) {
        AutoTileLock_Local __my_auto_tile_lock;
        pvalue->SetString(apValue, abClearActions);
    }
}
}  // namespace fnv_00a01350

class ScrapHeapBuffer;
template<class K, class V> struct BSMapEntry {
    BSMapEntry* m_pkNext;
    K m_key;
    V m_val;
};
template<class K, class V> struct BSMapBase {
    virtual ~BSMapBase();
    virtual unsigned int KeyToHashIndex(K key);
    virtual bool IsKeysEqual(K key1, K key2);
    unsigned int m_uiHashSize;
    BSMapEntry<K, V>** m_ppkHashTable;
    bool GetAt(K key, V& val)
    {
        unsigned int uiIndex = KeyToHashIndex(key);
        BSMapEntry<K, V>* pkItem = m_ppkHashTable[uiIndex];
        while (pkItem) {
            if (IsKeysEqual(pkItem->m_key, key)) {
                val = pkItem->m_val;
                return true;
            }
            pkItem = pkItem->m_pkNext;
        }
        return false;
    }
};
extern BSMapBase<unsigned long, ScrapHeapBuffer*> DAT_011f32f4;
// @fnv 0x00a01860
int TraitNameToID(const char* apText)
{
    AutoTileLock_Local __my_auto_tile_lock;
    int iret = 0x80000000;
    DAT_011f32f4.GetAt((unsigned long)apText, (ScrapHeapBuffer*&)iret);
    return iret;
}

namespace fnv_00a03da0 {
struct EmptyPolymorphicObject {
    void* __vecDelDtor(unsigned int);
    char _pad_0[1];
};
typedef char _sizecheck_AutoTileLock[sizeof(EmptyPolymorphicObject) == 1 ? 1 : -1];
struct FUN_00a03da0_shell : public Tile {
    Tile* FUN_00a03da0(char*);
};

int __cdecl FUN_00ec6da0(char const*, char const*);

struct TileChildNode {
    TileChildNode* m_pkNext;
    TileChildNode* m_pkPrev;
    Tile* m_element;
};

struct TileChildList {
    TileChildNode* m_pkHead;
    TileChildNode* m_pkTail;
    unsigned int m_uiCount;
    TileChildNode* GetHeadPos() const { return m_pkHead; }
    Tile*& GetNext(TileChildNode*& kPos) const {
        Tile*& element = kPos->m_element;
        kPos = kPos->m_pkNext;
        return element;
    }
};

struct TileNameString {
    char* m_data;
    unsigned short m_dataLen;
    unsigned short m_bufLen;
    char* c_str() const { return m_data; }
};

// @fnv 0x00a03da0
Tile* FUN_00a03da0_shell::FUN_00a03da0(char* apName)
{
    AutoTileLock_Local __my_auto_tile_lock;
    TileChildNode* xelem = ((TileChildList*)((char*)this + 4))->GetHeadPos();
    while (xelem && apName) {
        Tile* ptile = ((TileChildList*)((char*)this + 4))->GetNext(xelem);
        if (((TileNameString*)((char*)ptile + 0x20))->c_str() &&
            !FUN_00ec6da0(((TileNameString*)((char*)ptile + 0x20))->c_str(), apName)) {
            return ptile;
        } else {
            Tile* pchild = ((FUN_00a03da0_shell*)ptile)->FUN_00a03da0(apName);
            if (pchild) {
                return pchild;
            }
        }
    }
    return 0;
}
}  // namespace fnv_00a03da0

namespace fnv_00a03f70 {
struct EmptyPolymorphicObject {
    void* __vecDelDtor(unsigned int);
    char _pad_0[1];
};
typedef char _sizecheck_AutoTileLock[sizeof(EmptyPolymorphicObject) == 1 ? 1 : -1];
struct FUN_00a03f70_shell : public Tile {
    Tile* FUN_00a03f70(int, int*);
};

struct TileParent_00a03f70 {
    char pad[0x28];
    Tile* pParent;
    Tile* GetParent() { return pParent; }
};
struct TileAction_00a03f70 {
    virtual void v0();
    virtual Tile::Value* GetValue();
    int m_iValueId;
    TileAction_00a03f70* pNext;
};

// @fnv 0x00a03f70
Tile* FUN_00a03f70_shell::FUN_00a03f70(int aiTrait, int* aiType)
{
    AutoTileLock_Local __my_auto_tile_lock;
    Tile::Value* pvalue = GetValue(aiTrait);
    Tile* preturnTile = 0;
    if (pvalue) {
        TileAction_00a03f70* pcurrAction = *(TileAction_00a03f70**)((char*)pvalue + 0x10);
        bool bfound = false;
        while (pcurrAction && !bfound) {
            if (pcurrAction->m_iValueId == 0x7e7 && pcurrAction->GetValue()) {
                preturnTile = pcurrAction->GetValue()->pTile;
                *aiType = pcurrAction->GetValue()->m_iValueId;
                bfound = true;
            }
            pcurrAction = pcurrAction->pNext;
        }
    }
    else if (((TileParent_00a03f70*)this)->GetParent()) {
        return ((FUN_00a03f70_shell*)((TileParent_00a03f70*)this)->GetParent())->FUN_00a03f70(aiTrait, aiType);
    }
    return preturnTile;
}
}  // namespace fnv_00a03f70

struct FUN_00a087d0_shell : public Tile {
    void FUN_00a087d0(Tile*, Tile*);
};

struct TileListNode_00a087d0 {
    TileListNode_00a087d0* m_pkNext;
    TileListNode_00a087d0* m_pkPrev;
    Tile* m_element;
};
TileListNode_00a087d0* NewItem_00a087d0();
struct TileChildList_00a087d0 {
    TileListNode_00a087d0* m_pkHead;
    TileListNode_00a087d0* m_pkTail;
    unsigned int m_uiCount;
    void* GetHeadPos() const { return m_pkHead; }
    Tile* GetNext(void*& kPos) const {
        Tile** pElement = &((TileListNode_00a087d0*)kPos)->m_element;
        kPos = ((TileListNode_00a087d0*)kPos)->m_pkNext;
        return *pElement;
    }
    void FUN_00a0ca70(void* kPos, Tile* const& element) {
        TileListNode_00a087d0* pkNode = NewItem_00a087d0();
        TileListNode_00a087d0* pkA = 0;
        TileListNode_00a087d0* pkB = 0;
        TileListNode_00a087d0* pkC = 0;
        pkNode->m_element = element;
        TileListNode_00a087d0* pkPrev = (TileListNode_00a087d0*)kPos;
        pkA = pkB = pkC = pkPrev;
        pkNode->m_pkPrev = pkPrev;
        pkNode->m_pkNext = pkPrev->m_pkNext;
        if (pkPrev->m_pkNext) pkPrev->m_pkNext->m_pkPrev = pkNode; else m_pkTail = pkNode;
        pkPrev->m_pkNext = pkNode;
        m_uiCount++;
    }
    void FUN_00a0c9f0(Tile* const& element) {
        TileListNode_00a087d0* pkNode = NewItem_00a087d0();
        TileListNode_00a087d0* pkA = 0;
        TileListNode_00a087d0* pkB = 0;
        TileListNode_00a087d0* pkC = 0;
        TileListNode_00a087d0* pkD = 0;
        pkA = pkB = pkC = pkD = pkNode;
        pkNode->m_element = element;
        pkNode->m_pkNext = 0;
        pkNode->m_pkPrev = m_pkTail;
        if (m_pkTail) m_pkTail->m_pkNext = pkNode; else m_pkHead = pkNode;
        m_pkTail = pkNode;
        m_uiCount++;
    }
};
struct TileFlags_00a087d0 {
    char pad[0x30];
    unsigned int uiFlags;
    bool GetFlag(unsigned int uiFlag) const { return !!(uiFlags & uiFlag); }
};
template<> class NiTPointerListBase<NiTPointerAllocator<unsigned int>, Script*> {
public:
    TileListNode_00a087d0* m_pkHead;
    TileListNode_00a087d0* m_pkTail;
    unsigned int m_uiCount;
    Script* Remove(Script*& element) {
        TileListNode_00a087d0* pkNode = m_pkHead;
        TileListNode_00a087d0* pkFound = 0;
        TileListNode_00a087d0* pkPrev = 0;
        TileListNode_00a087d0* pkNext = 0;
        Script* pResult = 0;
        unsigned int ItemUpdateArray = 0;
        while (pkNode) {
            if ((Script*)pkNode->m_element == element) { pkFound = pkNode; break; }
            pkNode = pkNode->m_pkNext;
        }
        if (!pkFound) return 0;
        pkPrev = pkFound->m_pkPrev;
        pkNext = pkFound->m_pkNext;
        if (pkPrev) pkPrev->m_pkNext = pkNext; else m_pkHead = pkNext;
        if (pkNext) pkNext->m_pkPrev = pkPrev; else m_pkTail = pkPrev;
        pResult = (Script*)pkFound->m_element;
        ItemUpdateArray = m_uiCount;
        m_uiCount = ItemUpdateArray - 1;
        NewItem_00a087d0();
        return pResult;
    }
};
typedef NiTPointerListBase<NiTPointerAllocator<unsigned int>, Script*> ScriptList_00a087d0;

// @fnv 0x00a087d0
void FUN_00a087d0_shell::FUN_00a087d0(Tile* apParent, Tile* apReplacedTile)
{
    if (*(Tile**)((char*)this + 0x28) && !((TileFlags_00a087d0*)*(Tile**)((char*)this + 0x28))->GetFlag(0x2000)) {
        (*(Tile**)((char*)this + 0x28))->Set(0xfb6, (float)((*(Tile**)((char*)this + 0x28))->GetFloat(0xfb6) - 1.0), true);
        ((ScriptList_00a087d0*)((char*)*(Tile**)((char*)this + 0x28) + 4))->Remove(const_cast<Script*&>(static_cast<Script* const&>((Script*)(Tile*)this)));
    }
    *(Tile**)((char*)this + 0x28) = apParent;
    if (*(Tile**)((char*)this + 0x28)) {
        (*(Tile**)((char*)this + 0x28))->Set(0xfb6, (float)((*(Tile**)((char*)this + 0x28))->GetFloat(0xfb6) + 1.0), true);
        if (apReplacedTile) {
            void* xelem;
            void* xlast_elem;
            bool got_it = false;
            xlast_elem = 0;
            xelem = ((TileChildList_00a087d0*)((char*)*(Tile**)((char*)this + 0x28) + 4))->GetHeadPos();
            while (xelem) {
                xlast_elem = xelem;
                Tile* pitem = ((TileChildList_00a087d0*)((char*)*(Tile**)((char*)this + 0x28) + 4))->GetNext(xelem);
                if (pitem == apReplacedTile) {
                    ((ScriptList_00a087d0*)((char*)*(Tile**)((char*)this + 0x28) + 4))->Remove(const_cast<Script*&>(static_cast<Script* const&>((Script*)(Tile*)this)));
                    ((TileChildList_00a087d0*)((char*)*(Tile**)((char*)this + 0x28) + 4))->FUN_00a0ca70(xlast_elem, this);
                    got_it = true;
                    break;
                }
            }
            if (!got_it)
                ((TileChildList_00a087d0*)((char*)*(Tile**)((char*)this + 0x28) + 4))->FUN_00a0c9f0(this);
        } else {
            ((TileChildList_00a087d0*)((char*)*(Tile**)((char*)this + 0x28) + 4))->FUN_00a0c9f0(this);
        }
    }
}

struct MemoryManager { void Deallocate(void*); };
extern MemoryManager _g_memoryManager;
struct TileCollection : FUN_00a0c190 {
    ~TileCollection() { int a; int b; int c; int d; int e; }
    static void operator delete(void* p) { _g_memoryManager.Deallocate(p); }
};
struct FUN_00a0ad40 {
    TileCollection* pTemplate;
    BSSimpleList<TileCollection*> xList;
    int iUnk0C;
    bool bOwns;
    ~FUN_00a0ad40();
};
// @fnv 0x00a0ad40
FUN_00a0ad40::~FUN_00a0ad40()
{
    if (pTemplate)
        delete pTemplate;
    iUnk0C = 0;
    if (bOwns) {
        BSSimpleList<TileCollection*>* pCurrentElementNext = &xList;
        while (pCurrentElementNext) {
            TileCollection* ptemp = pCurrentElementNext->m_item;
            if (ptemp)
                delete ptemp;
            pCurrentElementNext = pCurrentElementNext->m_pkNext;
        }
    }
    xList.RemoveAll();
}

namespace fnv_00a0b8d0 {
struct BSStr {
    bool Set(char const*, unsigned int);
    void Clear() { Set(0, 0); }
    ~BSStr() { Clear(); }
};
struct MemoryManager {
    void Deallocate(void*);
    static MemoryManager& GetSingleton();
};
extern MemoryManager _g_memoryManager;
inline void MemFree(void* p) { _g_memoryManager.Deallocate(p); }
struct TileElement {
    int m_uiSoundID;
    int iType;
    BSStr kValue;
    ~TileElement() { char acBuffer[28]; }
    static void operator delete(void* p) { MemFree(p); }
};
extern TileElement* DAT_011f329c[10];
extern unsigned int DAT_011f32dc;
// @fnv 0x00a0b8d0
void __cdecl FUN_00a0b8d0(TileElement* apItem)
{
    if (DAT_011f32dc < 10) {
        DAT_011f329c[DAT_011f32dc] = apItem;
        DAT_011f32dc++;
    } else {
        delete apItem;
    }
}
}  // namespace fnv_00a0b8d0

bool __cdecl FUN_00a0bb00(char const*);
void __cdecl FUN_009ff8a0(char const*, int);

extern int DAT_011a6d74;
extern BSMapBase<unsigned long, ScrapHeapBuffer*> DAT_011f32f4;

// @fnv 0x00a00940
int __cdecl TraitNameToIDAdd(char const* apString, int aiIndex)
{
    AutoTileLock_Local __my_auto_tile_lock;
    ScrapHeapBuffer* pData = 0;

    if (DAT_011f32f4.GetAt(reinterpret_cast<unsigned long>(apString), pData))
        return reinterpret_cast<int>(pData);

    if (aiIndex == -1)
    {
        aiIndex = DAT_011a6d74;
        DAT_011a6d74 = DAT_011a6d74 + 1;
    }

    if (aiIndex >= 10000 && FUN_00a0bb00(apString))
    {
        FUN_009ff8a0(apString, aiIndex);
        return aiIndex;
    }

    return 0x80000000;
}

class ScrapMapShell {
public:
    void Insert(char const* apName, int aiValue);
};

class ScrapListShell {
public:
    void Add(int aiValue, ScrapHeapBuffer* apHeap);
};

struct FrameLocals {
    int unk00;
    int unk18;
    int unk1C;
    int unk20;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ScrapHeapBuffer* heap;
};

extern ScrapListShell DAT_011f3308;
ScrapHeapBuffer* __cdecl FUN_00a01a20(char const* apName);

// @fnv 0x009ff8a0
void __cdecl FUN_009ff8a0(char const* apName, int aiValue)
{
    FrameLocals locals;
    if (apName == 0 || *apName == 0) {
        return;
    }
    AutoTileLock_Local lock;
    reinterpret_cast<ScrapMapShell*>(&DAT_011f32f4)->Insert(apName, aiValue);
    if (FUN_00a0bb00(apName) && aiValue >= 10000) {
        if (DAT_011a6d74 <= aiValue) {
            DAT_011a6d74 = aiValue + 1;
        }
        locals.heap = FUN_00a01a20(apName);
        if (locals.heap != 0) {
            DAT_011f3308.Add(aiValue, locals.heap);
        }
    }
}

struct TileNode;
struct TileObject {
    void* unk00;
    TileNode* unk04;
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
    unsigned int uiFlags;
    bool GetFlag(unsigned int uiFlag) const { return !!(uiFlags & uiFlag); }
    void FUN_00a00b50();
};
struct TileNode {
    TileNode* pkNext;
    TileNode* pkPrev;
    TileObject* pTile;
};
// @fnv 0x00a00b50
void TileObject::FUN_00a00b50() {
    AutoTileLock_Local lock;
    if (!GetFlag(0x2000) && !GetFlag(0x4000)) {
        uiFlags |= 0x4000;
        TileNode* iter = unk04;
        TileNode* current = iter;
        while (current) {
            TileObject** pChild = &current->pTile;
            current = current->pkNext;
            (*pChild)->FUN_00a00b50();
        }
    }
}

struct MapIterator_00a0c850 {
    void** m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    BSMapEntry<unsigned long, ScrapHeapBuffer*>** m_ppkHashTable;
    void FUN_00a0c850(void** position, ScrapHeapBuffer** value, unsigned int* key) {
        typedef BSMapEntry<unsigned long, ScrapHeapBuffer*> Entry;
        Entry* current = (Entry*)*position;
        *key = current->m_key;
        *value = current->m_val;
        *position = current->m_pkNext;
        if (*position != 0) return;
        unsigned int bucket = ((BSMapBase<unsigned long, ScrapHeapBuffer*>*)this)->KeyToHashIndex(*key);
        for (++bucket; bucket < m_uiHashSize; ++bucket) {
            if (m_ppkHashTable[bucket] != 0) {
                *position = m_ppkHashTable[bucket];
                break;
            }
        }
    }
};
__forceinline BSMapEntry<unsigned long, ScrapHeapBuffer*>* FindFirstHeapEntry(
    BSMapBase<unsigned long, ScrapHeapBuffer*>& map)
{
    unsigned int bucketIndex = 0;
    for (; bucketIndex < map.m_uiHashSize; ++bucketIndex) {
        if (map.m_ppkHashTable[bucketIndex] != 0)
            return map.m_ppkHashTable[bucketIndex];
    }
    return 0;
}
// @fnv 0x00a01a70
ScrapHeapBuffer* __cdecl FUN_00a01a70(unsigned int requestedKey) {
    ScrapHeapBuffer* result;
    unsigned int key;
    void* position = FindFirstHeapEntry(DAT_011f32f4);
    while (position) {
        ((MapIterator_00a0c850*)&DAT_011f32f4)->FUN_00a0c850(&position, &result, &key);
        if (key == requestedKey) return result;
    }
    return 0;
}

void __cdecl FUN_00a044f0();
void __cdecl _FUN_00a04500();

struct TileLockGuard {
    TileLockGuard() { FUN_00a044f0(); }
    ~TileLockGuard() { _FUN_00a04500(); }
};

struct FlaggedTile {
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
    unsigned int uiFlags;
    bool GetFlag(unsigned int uiFlag) const { return (uiFlags & uiFlag) != 0; }
    template<unsigned int F> void SetFlag(bool abSet) {
        abSet ? (uiFlags |= F) : (uiFlags &= ~F);
    }
};

struct TileListNode {
    TileListNode* m_pkNext;
    TileListNode* m_pkPrev;
    FlaggedTile* m_element;
};
TileListNode* NewTileListNode();
void FreeTileListNode(TileListNode* apNode);

struct TileList {
    TileListNode* m_pkHead;
    TileListNode* m_pkTail;
    unsigned int m_uiCount;
    void AddTail(FlaggedTile* const& element) {
        TileListNode* pkNode = NewTileListNode();
        TileListNode* pkA = 0;
        pkA = pkNode;
        pkNode->m_element = element;
        pkNode->m_pkNext = 0;
        pkNode->m_pkPrev = m_pkTail;
        if (m_pkTail) m_pkTail->m_pkNext = pkNode; else m_pkHead = pkNode;
        m_pkTail = pkNode;
        m_uiCount++;
    }
    FlaggedTile* Remove(FlaggedTile*& element) {
        TileListNode* pkNode = m_pkHead;
        TileListNode* pkFound = 0;
        TileListNode* pkPrev = 0;
        TileListNode* pkNext = 0;
        FlaggedTile* pResult = 0;
        unsigned int ItemUpdateArray = 0;
        TileListNode* pkX = 0;
        TileListNode* pkY = 0;
        TileListNode* pkZ = 0;
        pkX = pkY = pkZ = pkFound;
        while (pkNode) {
            if (pkNode->m_element == element) { pkFound = pkNode; break; }
            pkNode = pkNode->m_pkNext;
        }
        if (!pkFound) return 0;
        pkPrev = pkFound->m_pkPrev;
        pkNext = pkFound->m_pkNext;
        if (pkPrev) pkPrev->m_pkNext = pkNext; else m_pkHead = pkNext;
        if (pkNext) pkNext->m_pkPrev = pkPrev; else m_pkTail = pkPrev;
        pResult = pkFound->m_element;
        ItemUpdateArray = m_uiCount;
        m_uiCount = ItemUpdateArray - 1;
        FreeTileListNode(pkFound);
        return pResult;
    }
};

extern TileList g_kPendingTiles;
extern TileList g_kRemovedTiles;

// @fnv 0x00a07690
void __cdecl FUN_00a07690(FlaggedTile* apTile) {
    if (!apTile) return;
    TileLockGuard kLock;
    if (!apTile->GetFlag(0x400)) {
        g_kPendingTiles.AddTail(apTile);
        apTile->SetFlag<0x400>(true);
    }
    if (apTile->GetFlag(0x800)) {
        g_kRemovedTiles.Remove(apTile);
        apTile->SetFlag<0x800>(false);
    }
}

class A0B1F0Tile {
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
    ChildPtr<NiNode> m_spNode;

    NiNode* GetNode() const { return m_spNode; }
    TileShaderProperty* FUN_00a0b1f0();
};

static inline NiAVObject* A0B1F0GetChild(NiNode* pkNode, unsigned int uiIndex) {
    if (uiIndex >= pkNode->GetChildren().m_usSize)
        return 0;
    else
        return pkNode->GetChildren().GetAt(uiIndex);
}

// @fnv 0x00a0b1f0
TileShaderProperty* A0B1F0Tile::FUN_00a0b1f0() {
    TileShaderProperty* pkProperty = 0;
    NiNode* pkNode = GetNode();
    NiAVObject* pkCurrentObject = pkNode ? A0B1F0GetChild(pkNode, 0) : 0;
    if (pkCurrentObject)
        pkProperty = reinterpret_cast<PropHelper*>(pkCurrentObject)->GetProperty(3);
    return pkProperty;
}

extern int DAT_01094d9c;

class FUN_00a0d220_pool {
public:
    void FUN_00aa4060(void* apMemory);
};
extern FUN_00a0d220_pool DAT_011f6238;

struct FUN_00a0d220_frame {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};

struct FUN_00a0d220_cls {
    int m_vptr;
    int unk04;

    void BaseCleanup();

    FUN_00a0d220_cls* FUN_00a0d220(unsigned int auiFlags);
};

// @fnv 0x00a0d220
FUN_00a0d220_cls* FUN_00a0d220_cls::FUN_00a0d220(unsigned int auiFlags)
{
    FUN_00a0d220_frame frame;
    m_vptr = (int)&DAT_01094d9c;
    BaseCleanup();
    if (auiFlags & 1) {
        DAT_011f6238.FUN_00aa4060(this);
    }
    return this;
}

// Claim: clm_0814eff69ec3418ebf5d -> FUN_00a0d280 (0x00a0d280, 24 bytes)
// Flags: /MT /Od /Oy- /GS /EHsc /Gy /Ob1
//
// Shape: a tiny __thiscall member of the tile-template class.  The body only
// forwards to a method of the sub-object that lives at this+0x0C.  MSVC /Od
// spills 'this' into the frame (the slot sits below every named local) and
// reloads it with the sub-object adjustment right before the call:
//
//   push ebp / mov ebp,esp / sub esp,0x20
//   mov  [ebp-0x20],ecx
//   mov  ecx,[ebp-0x20]
//   add  ecx,0x0C
//   call FUN_0043a010
//
// The 0x20 frame comes from the 0x1C-byte scratch area the original kept in
// the frame, so the same-sized local is declared here.



// Callee reached through the embedded sub-object at this+0x0C.
struct Sub_0043a010 {
    void FUN_0043a010();
};

// 0x1C bytes of scratch space held in the caller's frame.
struct TileScratch_00a0d280 {
    int m_iScratch00;
    int m_iScratch04;
    int m_iScratch08;
    int m_iScratch0C;
    int m_iScratch10;
    int m_iScratch14;
    int m_iScratch18;
};

// Stand-in for the owning class: 0x0C bytes of leading members, then the
// embedded sub-object whose method is invoked.
struct FUN_00a0d280_cls {
    int m_00;
    int m_04;
    int m_08;
    Sub_0043a010 m_sub;

    void FUN_00a0d280();
};

// @fnv 0x00a0d280
void FUN_00a0d280_cls::FUN_00a0d280()
{
    TileScratch_00a0d280 scratch;
    (void)scratch;
    m_sub.FUN_0043a010();
}

struct MM {
    void* Allocate(unsigned int auiSize);
};

extern MM g_mm;

struct NiGlobalStringTable {
    static char* AddString(const char* apString);
};

extern int EmptyFS;

class TileTemplate_00a0ae70 {
public:
    const char* m_name;
    void* m_pOwnerObject;
    int m_unk08;
    int m_unk0c;
    int m_unk10;

    TileTemplate_00a0ae70(const char* apName, void* apOwner) {
        m_name = (const char*)EmptyFS;
        m_unk10 = 0;
        m_unk08 = 0;
        m_unk0c = 0;
        if (m_name != apName) {
            const char* pOld = m_name;
            m_name = NiGlobalStringTable::AddString(apName);
            if (pOld != (const char*)EmptyFS) {
                InterlockedDecrement((long*)(pOld - 8));
            }
        }
        m_pOwnerObject = apOwner;
    }
    static void* operator new(unsigned int auiSize) { return g_mm.Allocate(auiSize); }
};

struct TemplateList_00a0ae70 {
    TileTemplate_00a0ae70* m_item;
    TemplateList_00a0ae70* m_pkNext;

    TemplateList_00a0ae70(TileTemplate_00a0ae70* apItem) : m_item(apItem), m_pkNext(0) {}
    static void* operator new(unsigned int auiSize) { return g_mm.Allocate(auiSize); }

    void AddTail(TileTemplate_00a0ae70** apItem) {
        if (*apItem == 0) return;
        TemplateList_00a0ae70* pkNode = this;
        while (pkNode->m_pkNext != 0) {
            pkNode = pkNode->m_pkNext;
        }
        if (pkNode->m_item != 0) {
            TemplateList_00a0ae70* pkNew = new TemplateList_00a0ae70(*apItem);
            pkNode->m_pkNext = pkNew;
        } else {
            pkNode->m_item = *apItem;
        }
    }
};

struct Storage_00a0ae70 {
    int m_unk00;
    TemplateList_00a0ae70 m_kNode;
    TileTemplate_00a0ae70* m_pTileTemplate;
    bool m_owns;

    TileTemplate_00a0ae70* FUN_00a0ae70(const char* apName);
};

// @fnv 0x00a0ae70
TileTemplate_00a0ae70* Storage_00a0ae70::FUN_00a0ae70(const char* apName)
{
    TileTemplate_00a0ae70* pTemplate = new TileTemplate_00a0ae70(apName, this);
    m_kNode.AddTail(&pTemplate);
    return pTemplate;
}

struct NiTexture;
struct TileShaderProperty { void FUN_00bb7a10(NiTexture* apTexture); };
struct FUN_00a07530_shell { void FUN_00a07530(int); };
struct A0B020Child {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
};
struct A0B020Node { A0B020Node* m_pkNext; A0B020Node* m_pkPrev; A0B020Child* m_element; };
struct A0B020List {
    A0B020Node* m_pkHead;
    A0B020Node* GetHeadPos() const { return m_pkHead; }
    A0B020Child*& GetNext(A0B020Node*& pos) { A0B020Child*& r = pos->m_element; pos = pos->m_pkNext; return r; }
};
class A0B020Tile {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual int GetType();
    A0B020List m_kChildList;
    int unk, unk0C, unkCur, unkValue, uNewnk, unk1C, uTmpnk, unk24, unk28;
    ChildPtr<NiNode> m_spNode;
    NiNode* GetNode() const { return m_spNode; }
    void FUN_00a0b020();
};
// @fnv 0x00a0b020
void A0B020Tile::FUN_00a0b020()
{
    A0B020Node* pos2;
    NiAVObject* pNewkChild;
    TileShaderProperty* pkProp;
    A0B020Child* pkTile;
    if (GetNode())
    {
        pNewkChild = A0B1F0GetChild(GetNode(), 0);
        if (GetType() == 0x386 && pNewkChild)
        {
            pkProp = ((PropHelper*)pNewkChild)->GetProperty(3);
            if (pkProp)
            {
                pkProp->FUN_00bb7a10(0);
                ((FUN_00a07530_shell*)this)->FUN_00a07530(0x20);
            }
        }
    }
    pos2 = m_kChildList.GetHeadPos();
    while (pos2)
    {
        pkTile = m_kChildList.GetNext(pos2);
        if (!((FUN_00a03c90_shell*)pkTile)->FUN_00a03c90()) pkTile->v07();
    }
}

extern int DAT_011f32dc;
extern void* DAT_011f329c[];

struct StrMem_00a0ba50 {
    bool Set(const char*, unsigned int);
};

struct Item_00a0ba50 {
    int unk00;
    int unk04;
    StrMem_00a0ba50 m_str;
    int unk10;
    int unk14;

    ~Item_00a0ba50()
    {
        // The string helper's own frame slots stay reserved when its body is inlined away.
        char* pNewData;
        unsigned int uiNewLen;
        unsigned int uiOldLen;
        unsigned int uiMaxLen;
        char* pReferenceEntry;
        char* pNewText;
        int iExtra;
        int iAllocSize;
        m_str.Set(0, 0);
    }

    static void operator delete(void* apMemory) { DAT_011f6238.FUN_00aa4060(apMemory); }
};

// @fnv 0x00a0ba50
void __cdecl FUN_00a0ba50()
{
    while (DAT_011f32dc-- != 0) {
        Item_00a0ba50* pItem = (Item_00a0ba50*)DAT_011f329c[DAT_011f32dc];
        delete pItem;
    }
    DAT_011f32dc = 0;
}

void __cdecl FUN_00a044f0();
extern "C" void __cdecl FUN_00a04500();

struct TileSearchLock {
    TileSearchLock() { FUN_00a044f0(); }
    ~TileSearchLock() { FUN_00a04500(); }
};

struct TileFloatList {
    void* m_vtbl;
    NiTListItem<Tile*>* m_pkHead;
    NiTListItem<Tile*>* GetHeadPos() const { return m_pkHead; }
    Tile*& GetNext(NiTListItem<Tile*>*& kPos) {
        Tile*& element = kPos->m_element;
        kPos = kPos->m_pkNext;
        return element;
    }
    Tile* FUN_00a03eb0(int iValue);
};

// @fnv 0x00a03eb0
Tile* TileFloatList::FUN_00a03eb0(int iValue)
{
    TileSearchLock kLock;
    NiTListItem<Tile*>* kPos = GetHeadPos();
    while (kPos) {
        Tile* pkTile = GetNext(kPos);
        if (pkTile->GetFloat(0xfaa) == iValue)
            return pkTile;
    }
    return 0;
}

struct TilePool_ac80 {
    void* FUN_00aa3e40(unsigned int auiSize);
};

struct TileTemplateList_ac80 {
    TileCollection* m_item;
    TileTemplateList_ac80* m_pkNext;
    TileTemplateList_ac80() { m_item = 0; m_pkNext = 0; }
    ~TileTemplateList_ac80();
};
struct FixedString_ac80 {
    int m_str;
    FixedString_ac80() { m_str = EmptyFS; }
    ~FixedString_ac80();
    FixedString_ac80& operator=(const char* apString) {
        if (m_str != (int)apString) {
            int iOld = m_str;
            m_str = (int)NiGlobalStringTable::AddString(apString);
            if (iOld == EmptyFS) {
            } else {
                long* p = (long*)(iOld - 8);
                InterlockedDecrement(p);
            }
        }
        return *this;
    }
};
struct TemplateItemList_ac80 {
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
    TemplateItemList_ac80() { m_uiCount = 0; m_pkHead = 0; m_pkTail = 0; }
    ~TemplateItemList_ac80();
};
struct TileTemplateNew_ac80 {
    FixedString_ac80 m_kName;
    void* m_pkOwnerManager;
    TemplateItemList_ac80 m_kUnsortedGeometryList;
    TileTemplateNew_ac80(const char* apName, void* apOwner) {
        m_kName = apName;
        m_pkOwnerManager = apOwner;
    }
    static void* operator new(unsigned int auiSize) { return ((TilePool_ac80*)&DAT_011f6238)->FUN_00aa3e40(auiSize); }
    static void operator delete(void* apMem) { DAT_011f6238.FUN_00aa4060(apMem); }
};
struct FUN_00a0ac80 {
    TileCollection* pTemplate;
    TileTemplateList_ac80 xList;
    int iUnk0C;
    bool bOwns;
    FUN_00a0ac80();
};
// @fnv 0x00a0ac80
FUN_00a0ac80::FUN_00a0ac80()
{
    pTemplate = (TileCollection*)new TileTemplateNew_ac80("main", this);
    iUnk0C = 0;
    bOwns = true;
}

void FUN_00a044f0();
void FUN_00a04500();



class TileV;

class TileItemV
{
public:
    TileItemV* m_pkNext;
    TileItemV* m_pkPrev;
    TileV* m_element;
};

class TileValueV
{
public:
    int m_iValueId;
    TileValueV* m_pkNext;
    float fValue;
    const char* pString;
};

class FnvTileLock
{
public:
    FnvTileLock() { FUN_00a044f0(); }
    ~FnvTileLock() { FUN_00a04500(); }
};

inline bool HasValue(TileValueV* pList, int m_iValueId)
{
    while (pList != 0 && pList->m_iValueId != m_iValueId)
        pList = pList->m_pkNext;
    return pList != 0;
}

class TileV : public FUN_00a07530_shell
{
public:
    int unk00;
    TileItemV* m_pkChildList;
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
    unsigned int unk30;
    TileItemV* GetHeadPos() { return m_pkChildList; }
    TileV*& GetNext(TileItemV*& pos) { TileV*& element = pos->m_element; pos = pos->m_pkNext; return element; }
    float GetFloat(int);
    void FUN_00a0b420(TileValueV* pValues, float fValue);
};

// @fnv 0x00a0b420
void TileV::FUN_00a0b420(TileValueV* pValues, float fValue)
{
    FnvTileLock aKLock;
    float f = GetFloat(0xff4);
    if (f == 0.0)
        f = fValue;
    {
    int iValue3 = (int)f;
    if (HasValue(pValues, iValue3))
        FUN_00a07530(8);
    }
    TileItemV* pkIter = GetHeadPos();
    while (pkIter)
        GetNext(pkIter)->FUN_00a0b420(pValues, f);
}

struct Vec { float x,y,z; Vec() {} Vec(float a,float b,float c):x(a),y(b),z(c) {} Vec operator+(const Vec& v) const { return Vec(x+v.x,y+v.y,z+v.z); } Vec operator-(const Vec& v) const { return Vec(x-v.x,y-v.y,z-v.z); } };
void FUN_004169a0(float,float&,float&);
struct Mat { float m00,m01,m02,m10,m11,m12,m20,m21,m22; void FUN_0043f850(float angle) { float sn,cs; FUN_004169a0(angle,sn,cs); float negativeSin=-sn; float cosine=cs; m00=cosine; m01=0; m02=negativeSin; m10=0; m11=1; m12=0; m20=sn; m21=0; m22=cosine; } Vec FUN_004b4500(const Vec* v) { return Vec(m00*v->x+m01*v->y+m02*v->z,m10*v->x+m11*v->y+m12*v->z,m20*v->x+m21*v->y+m22*v->z); } };
extern const Vec NiPoint3_ZERO;
extern const double DAT_0106f290;
struct Rtti { const char* name; Rtti* parent; };
extern Rtti g_011f4a40;
struct Scene {
 virtual void v0(); virtual void v1(); virtual Rtti* GetRTTI();
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
 Mat rotation; Vec translation;
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
 Scene** children; unsigned short capacity; unsigned short size; unsigned short count;
 __forceinline Scene*& At(unsigned index) { return children[index]; }
 __forceinline unsigned Count() { return count; }
};
__forceinline void TranslateScene(Scene* object, Mat& rotation, const Vec& center, const Vec& pivot) {
 object->translation=(center+pivot)-rotation.FUN_004b4500(&pivot);
}
__forceinline void ReadSceneType(Scene* object, Rtti*& type, bool& valid) {
 type=object->GetRTTI();
 while(type) { if(type==&g_011f4a40) {valid=true;return;} type=type->parent; }
 valid=false;
}
struct TileWork;
struct Link { Link* next; Link* prev; TileWork* item; };
struct TileWorkList { Link* head; __forceinline Link* First() { return head; }
__forceinline TileWork* Next(Link*& pos) { TileWork** data=&pos->item; pos=pos->next; return *data; } };
struct TileWork {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual int Kind();
 Link* children;
 int unk08;
 int unk0c;
 int unk10;
 int unk14;
 int unk18;
 int unk1c;
 int unk20;
 int unk24;
 int unk28;
 Scene* model;
 __forceinline Scene* Model() {return model;}
 float ReadTrait(int);
 bool ReadBooleanTrait(int);
 void WriteTrait(int,float,bool);
 void FUN_00a0b520();
};
// @fnv 0x00a0b520
void TileWork::FUN_00a0b520() {
 float local37;
 float local35;
 bool valid_31;
 Rtti* type3;
 Scene* objectX;
 Scene** sceneEntryX;
 Scene* model_2;
 Scene* node1;
 TileWork** local14;
 Link* first;
 Mat rotationA;
 Vec pivotA;
 Scene* found;
 unsigned indexB;
 Vec center;
 float depth_;
 Scene* rootUpdate6;
 float yg1;
 float heightSquaredX;
 float cy5;
 float cx2;
 float widthTmp;
 float x15;
 TileWork* childVal5;
 Link* pos2;
 first=children; pos2=first;
 while(pos2) {
 local14=&pos2->item; pos2=pos2->next; childVal5=*local14;
 if(childVal5) {
 x15=ReadTrait(4001);
 yg1=ReadTrait(4002);
 widthTmp=ReadTrait(4091);
 heightSquaredX=ReadTrait(4092);
 cx2=childVal5->ReadTrait(4001);
 cy5=childVal5->ReadTrait(4002);
 if(ReadBooleanTrait(4008)) { cx2+=x15; cy5+=yg1; }
 childVal5->WriteTrait(4091,x15+widthTmp-cx2,true);
 childVal5->WriteTrait(4092,yg1+heightSquaredX-cy5,true);
 childVal5->WriteTrait(4090,ReadTrait(4090),true);
 if(childVal5->ReadBooleanTrait(4008) && childVal5->Kind()==902) {
 depth_=childVal5->ReadTrait(4013);
 center=NiPoint3_ZERO;
 node1=childVal5->model; node1->translation=center;
 center.x+=childVal5->ReadTrait(4001);
 center.z+=-childVal5->ReadTrait(4002);
 center.y+=depth_*DAT_0106f290;
 model_2=childVal5->model; rootUpdate6=model_2;
 for(indexB=0;rootUpdate6 && indexB<rootUpdate6->count;++indexB) {
 sceneEntryX=&rootUpdate6->children[indexB]; objectX=*sceneEntryX;
 if(!objectX) found=0;
 else {
 ReadSceneType(objectX,type3,valid_31);
 found=valid_31?objectX:0;
 }
 local37=childVal5->ReadTrait(4091);
 local35=-childVal5->ReadTrait(4092);
 {pivotA.x=local37; pivotA.y=0; pivotA.z=local35;}

 rotationA.FUN_0043f850(childVal5->ReadTrait(4090));
 if(found) {
 found->rotation=rotationA;
 TranslateScene(found,rotationA,center,pivotA);
 }
 }
 }
 childVal5->FUN_00a0b520();
 }
 }
}

unsigned int BSStringLength(const char*);
inline unsigned int BSStringCapacityMaximum(unsigned int a, unsigned int b) { return a > b ? a : b; }
void* __cdecl memcpy(void*, const void*, unsigned int);
void* operator new(unsigned int size);
void operator delete(void* memory);
struct ReuseString {
    char* pString;
    unsigned short length;
    unsigned short capacity;
    ReuseString() { Init(); }
    void Init() { pString = 0; SetLength(0); SetMaxLength(0); }
    ~ReuseString() { Set(0, 0); }
    void SetLength(unsigned int n) { length = n <= 65535 ? (unsigned short)n : 65535; }
    void SetMaxLength(unsigned int n) { capacity = n <= 65535 ? (unsigned short)n : 65535; }
    ReuseString& operator=(const char* str) { Set(str, 0); return *this; }
    unsigned int MaxLength() { return capacity; }
    bool Set(const char* text, unsigned int size) {
        unsigned int newLength = text ? BSStringLength(text) : 0;
        unsigned int newCapacity = BSStringCapacityMaximum(newLength, size);
        if (newCapacity <= MaxLength()) {
            if (newCapacity) {
                if (text) memcpy(pString, text, newLength + 1);
                else pString[0] = 0;
            } else {
                if (pString) { char* oldData = pString; delete oldData; }
                pString = 0;
                newCapacity = 0;
                SetMaxLength(newCapacity);
            }
        } else {
            char* oldString = pString;
            char* newString = new char[newCapacity + 1];
            pString = newString;
            if (text) memcpy(pString, text, newLength + 1);
            else pString[0] = 0;
            if (oldString) delete oldString;
            SetMaxLength(newCapacity);
        }
        SetLength(newLength);
        return newLength != 0;
    }
};
struct ReuseNode {
    int trait;
    float value;
    ReuseString text;
    int flags;
    int owner;
    ReuseNode(int a, float f, const char* s, int b, int c) {
        trait = a;
        value = f;
        text.Set(s, 31);
        flags = b;
        owner = c;
    }
    void Init(int a, float f, const char* s, int b, int c) {
        trait = a;
        value = f;
        text = s;
        flags = b;
        owner = c;
    }
};
inline void* operator new(unsigned int size) { return g_mm.Allocate(size); }
void operator delete(void* memory);
// @fnv 0x00a0b950
ReuseNode* FUN_00a0b950(int a, float f, const char* s, int b, int c) {
    ReuseNode* node;
    if ((unsigned int)DAT_011f32dc > 0) {
        DAT_011f32dc = DAT_011f32dc - 1;
        node = (ReuseNode*)DAT_011f329c[DAT_011f32dc];
        node->Init(a, f, s, b, c);
    } else {
        node = new ReuseNode(a, f, s, b, c);
    }
    return node;
}

struct Sub_00a0c020 {
    int unk00;
    int unk04;
    float unk08;

    float GetVal() { return unk08; }
};

struct Target_00a0c020 {
    int unk00;
    int unk04;
    int unk08;
    Sub_00a0c020* unk0c;

    float FUN_00a0c020();
};

// @fnv 0x00a0c020
float Target_00a0c020::FUN_00a0c020() {
    return unk0c ? unk0c->GetVal() : 0.0f;
}

extern void* DAT_010173f0;

struct S00ac5490_Str {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    void Init(int a, int b);
    S00ac5490_Str* Set(const S00ac5490_Str* src, int a, void* g);
    void Free(int a, int b);
    __forceinline S00ac5490_Str(const S00ac5490_Str& o) {
        int e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17;
        Init(0, 0);
        Set(&o, 0, DAT_010173f0);
    }
    ~S00ac5490_Str() { int g1, g2, g3, g4, g5; Free(1, 0); }
};

struct S00ac5490_Base {
    int unk04;
    S00ac5490_Base(S00ac5490_Str s);
    virtual ~S00ac5490_Base();
};

struct FUN_00ac5490 : public S00ac5490_Base {
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
    FUN_00ac5490(S00ac5490_Str a);
};

// @fnv 0x00ac5490
FUN_00ac5490::FUN_00ac5490(S00ac5490_Str a) : S00ac5490_Base(a)
{
    int d1;
    unk40 = 0;
    unk44 = 0;
}

struct _RTL_CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

class FUN_009ff340;
struct S009ff340_List { int FUN_0057c730(FUN_009ff340* const& p); };
extern char DAT_011f3330;
extern S009ff340_List DAT_011f3318;
extern S009ff340_List DAT_011f3324;
extern int DAT_011f32d8;
extern char str_01093f44[];
void FUN_005b5e40(const char*, ...);

struct S009ff340_RefObj {
    virtual ~S009ff340_RefObj();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
    void DecRefCount() { if (!InterlockedDecrement(&m_iObjectReferenceCount)) DeleteThis(); }
};
void FUN_00c45830(S009ff340_RefObj*);
struct S009ff340_Ptr {
    S009ff340_RefObj* m_obj;
    ~S009ff340_Ptr() { if (m_obj) m_obj->DecRefCount(); }
};
struct S009ff340_Str {
    int unk00;
    int unk04;
    int unk08;
    void FUN_004037f0(int, int);
    ~S009ff340_Str() { int scratch[13]; FUN_004037f0(0, 0); }
};
struct S009ff340_M10 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void InitAndClear();
    ~S009ff340_M10() { InitAndClear(); }
};
struct S009ff340_Empty {
    int unk00;
    ~S009ff340_Empty() {}
};
struct S009ff340_Base04 {
    int unk00;
    int unk04;
    S009ff340_Empty e;
    void FUN_004ed900();
    ~S009ff340_Base04() { FUN_004ed900(); }
};
inline void S009ff340_Detach(S009ff340_RefObj* p) { int scratch[10]; FUN_00c45830(p); }

class FUN_009ff340 : public S009ff340_Base04 {
public:
    virtual ~FUN_009ff340();
    S009ff340_M10 m10;
    S009ff340_Str m20;
    S009ff340_Ptr m2c;
    unsigned int flags;
    bool GetFlag(unsigned int m) { return (flags & m) != 0; }
    template<unsigned int M> void SetFlag(bool b) { b ? (flags |= M) : (flags &= ~M); }
    void FUN_009ff690();
    
};
void ClearInterfaceRefs(FUN_009ff340*);

// @fnv 0x009ff340
FUN_009ff340::~FUN_009ff340()
{
    EnterCriticalSection((_RTL_CRITICAL_SECTION*)&DAT_011f3330);
    ClearInterfaceRefs(this);
    if (!GetFlag(0x2000)) {
        FUN_005b5e40(str_01093f44);
        FUN_009ff690();
    }
    if (GetFlag(0x400))
        DAT_011f3318.FUN_0057c730(this);
    SetFlag<0x400>(false);
    if (DAT_011f3324.FUN_0057c730(this) && GetFlag(0x800))
        --DAT_011f32d8;
    SetFlag<0x800>(false);
    SetFlag<0x1000>(false);
    S009ff340_Detach(m2c.m_obj);
    LeaveCriticalSection((_RTL_CRITICAL_SECTION*)&DAT_011f3330);
}

namespace fnv_009ff690 {
extern __declspec(thread) int DAT_012722b4;
__forceinline int GetMemoryContext() { return DAT_012722b4; }
__forceinline void SetMemoryContext(int context) { DAT_012722b4 = context; }
struct MemoryContextGuard {
    int previous;
    __forceinline MemoryContextGuard(int context) {
        previous = GetMemoryContext();
        SetMemoryContext(context);
    }
    __forceinline ~MemoryContextGuard() { SetMemoryContext(previous); }
};
void __cdecl FUN_00a044f0();
void __cdecl FUN_00a04500();
struct TileReleaseLock { __forceinline ~TileReleaseLock() { FUN_00a04500(); } };
struct XmlAllocator {
    void* FUN_00aa3e40(unsigned int bytes);
    void FUN_00aa4060(void* memory);
};
extern XmlAllocator DAT_011f6238;
struct ReleaseValue {
    __forceinline ~ReleaseValue();
    static __forceinline void operator delete(void* memory) {
        DAT_011f6238.FUN_00aa4060(memory);
    }
};
struct ReleaseArray {
    void* vtable;
    ReleaseValue** buffer;
    unsigned int size;
    unsigned int capacity;
    __forceinline unsigned int GetSize() { return size; }
    inline void DestroyElements(ReleaseValue**, unsigned int count) {
        for (unsigned int index = 0; index < count; ++index) {}
    }
    void FreeStorage();
    inline void FUN_008454f0(bool freeMemory) {
        if (buffer) {
            DestroyElements(buffer, size);
            if (freeMemory) { FreeStorage(); buffer = 0; capacity = 0; }
            size = 0;
        }
    }
};
struct ReleaseNode {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void RemoveObject(ReleaseNode*);
    unsigned int references;
    void* name;
    void* extraData;
    unsigned short extraSize;
    unsigned short extraCapacity;
    unsigned int flags;
    ReleaseNode* parent;
    __forceinline ReleaseNode* GetParent() { return parent; }
};
struct ReleaseChild { virtual ~ReleaseChild(); };
struct ReleaseLink { ReleaseLink* next; ReleaseLink* prev; ReleaseChild* value; };
struct ChildPoolBlock { ChildPoolBlock* next; void* data; };
extern ChildPoolBlock* DAT_011c5f58;
unsigned int __cdecl gm_GetCurrentThreadId();
int __cdecl FUN_0043b460(volatile long*, long, long);
void __cdecl FUN_0040fca0(unsigned long);
void __cdecl FUN_0040fbe0();
struct ChildPoolLock {
    volatile long thread;
    unsigned int depth;
    inline void Lock(const char*) {
        unsigned int id = gm_GetCurrentThreadId();
        if (thread == id) ++depth;
        else {
            unsigned int retries = 0;
            while (FUN_0043b460(&thread, 0, id)) {
                ++retries;
                if (retries > 10000) FUN_0040fca0(1);
                else FUN_0040fca0(0);
            }
            FUN_0040fbe0();
            depth = 1;
        }
    }
    void Unlock();
};
extern ChildPoolLock g_011c5f80;
struct ChildAllocator {
    unsigned int count;
    __forceinline void Deallocate(void* pointer) {
        g_011c5f80.Lock(0);
        ChildPoolBlock* block = (ChildPoolBlock*)pointer;
        block->data = 0;
        block->next = DAT_011c5f58;
        DAT_011c5f58 = block;
        g_011c5f80.Unlock();
    }
};
struct ReleaseChildren {
    ReleaseLink* head; ReleaseLink* tail; ChildAllocator allocator;
    __forceinline unsigned int GetCount() { return allocator.count; }
    __forceinline void DeleteItem(ReleaseLink* item) {
        item->value = 0;
        allocator.Deallocate(item);
    }
    inline ReleaseChild* PopFrontScript() {
        ReleaseLink* old = head;
        head = head->next;
        if (head) head->prev = 0;
        else tail = 0;
        ReleaseChild* value = old->value;
        DeleteItem(old);
        --allocator.count;
        return value;
    }
};
struct ReleaseTile {
    void* vtable;
    ReleaseChildren children;
    ReleaseArray values;
    BSStringT<char> name;
    Tile* parent;
    NiPointer<ReleaseNode> node;
    unsigned int flags;
    void FUN_00a00b50();
    void FUN_00a01750();
    void FUN_00a087d0(Tile*, Tile*);
    void RemoveFadeItemsForTile(unsigned int);
    void FUN_009ff690();
};
void __cdecl ClearInterfaceRefs(ReleaseTile*);
// @fnv 0x009ff690
void ReleaseTile::FUN_009ff690() {
    unsigned int i;
    MemoryContextGuard guard(13);
    FUN_00a044f0();
    TileReleaseLock lock;
    FUN_00a00b50();
    ClearInterfaceRefs(this);
    flags |= 0x2000;
    FUN_00a01750();
    FUN_00a087d0(0, 0);
    for (i = 0; i < values.GetSize(); ++i) {
        delete values.buffer[i];
    }
    values.FUN_008454f0(true);
    RemoveFadeItemsForTile(0x80000000);
    if (node && node->GetParent()) {
        node->GetParent()->RemoveObject(node);
    }
    while (children.GetCount()) {
        delete children.PopFrontScript();
    }
}
}  // namespace fnv_009ff690

namespace fnv_00a00a30 {
class MemoryManagerA00 {
public:
    void FUN_00aa4060(void* pvMem); // Deallocate
};

extern MemoryManagerA00 DAT_011f6238;

void __cdecl FUN_00a044f0(); // EnterCriticalSection on the menu lock
void __cdecl FUN_00a04500(); // LeaveCriticalSection

class TileTemplateA00 {
public:
    ~TileTemplateA00(); // FUN_00a0bb50
    static void operator delete(void* pvMem) { DAT_011f6238.FUN_00aa4060(pvMem); }
};

class FadeNodeA00 {
public:
    static void operator delete(void* pvMem) { DAT_011f6238.FUN_00aa4060(pvMem); }
};

template <class T> class SimpleListA00 {
public:
    static void operator delete(void* pvMem) { DAT_011f6238.FUN_00aa4060(pvMem); }
    ~SimpleListA00() {}

    void FUN_00ae83e0()
    {
        while (m_pkNext)
        {
            SimpleListA00<T>* pkNext = m_pkNext->m_pkNext;
            m_pkNext->m_pkNext = 0;
            delete m_pkNext;
            m_pkNext = pkNext;
        }
        m_item = 0;
    }

    T m_item;
    SimpleListA00<T>* m_pkNext;
};

struct MapItemA00 {
    MapItemA00* m_pkNext;
    unsigned int m_key;
    void* m_val;
};

class MapA00 {
public:
    virtual ~MapA00();
    virtual unsigned int KeyToHashIndex(unsigned int key) const;
    virtual bool IsKeysEqual(unsigned int key1, unsigned int key2) const;
    virtual void SetValue(MapItemA00* pkItem, unsigned int key, void* val);
    virtual void ClearValue(MapItemA00* pkItem);
    virtual MapItemA00* NewItem();
    virtual void DeleteItem(MapItemA00* pkItem);

    void ClearAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                MapItemA00* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }

    unsigned int m_uiHashSize;
    MapItemA00** m_ppkHashTable;
    unsigned int m_uiCount;
    int m_unk10;
};

extern MapA00 DAT_011f32f4;
extern MapA00 DAT_011f3308;
extern SimpleListA00<TileTemplateA00*> DAT_011f3350;
extern SimpleListA00<FadeNodeA00*> DAT_011f3348;

class MenuLockA00 {
public:
    MenuLockA00() { FUN_00a044f0(); }
    ~MenuLockA00() { FUN_00a04500(); }
};

// @fnv 0x00a00a30
void __cdecl FUN_00a00a30()
{
    MenuLockA00 kLock;
    DAT_011f32f4.ClearAll();
    DAT_011f3308.ClearAll();

    for (SimpleListA00<TileTemplateA00*>* pkIter = &DAT_011f3350; pkIter && pkIter->m_item; pkIter = pkIter->m_pkNext)
    {
        delete pkIter->m_item;
    }
    DAT_011f3350.FUN_00ae83e0();

    for (SimpleListA00<FadeNodeA00*>* pkIter2 = &DAT_011f3348; pkIter2 && pkIter2->m_item; pkIter2 = pkIter2->m_pkNext)
    {
        delete pkIter2->m_item;
    }
    DAT_011f3348.FUN_00ae83e0();
}
}  // namespace fnv_00a00a30

namespace fnv_00a00c20 {
struct XmlAllocator {
    void* FUN_00aa3e40(unsigned int bytes);
    void FUN_00aa4060(void* memory);
};
extern XmlAllocator DAT_011f6238;
struct NodeRef { void Assign(int); int value; };
struct SmallArray {
    void* data; unsigned short size; unsigned short capacity;
    __forceinline SmallArray(unsigned int count=0, unsigned int limit=0) {
        void* initialData = 0;
        unsigned int elementLimit = 0xffff;
        unsigned int initialSize = count > elementLimit ? elementLimit : count;
        unsigned int initialCapacity = limit > elementLimit ? elementLimit : limit;
        data = initialData; size = (unsigned short)initialSize; capacity = (unsigned short)initialCapacity;
    }
    ~SmallArray();
};
struct Tile3D {
    static __forceinline void* operator new(unsigned int bytes) {
        return DAT_011f6238.FUN_00aa3e40(bytes);
    }
    static __forceinline void operator delete(void* memory) {
        DAT_011f6238.FUN_00aa4060(memory);
    }
    Tile3D();
    virtual ~Tile3D();
    void SetParent(Tile3D*, Tile3D*);
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; NodeRef unk2c; int unk30; int unk34; int unk38;
};
struct TileRect : Tile3D {
    __forceinline TileRect() {}
    virtual ~TileRect();
};
struct TileMenu : TileRect {
    __forceinline TileMenu() : unk3c(0) {}
    virtual ~TileMenu();
    int unk3c;
};
struct TileImage : Tile3D {
    TileImage();
    int unk3c; int unk40; int unk44;
};
struct TileText : Tile3D {
    __forceinline TileText(Tile3D* parent = 0) {
        if (parent) SetParent(parent, 0);
        unk48 = 0;
    }
    virtual ~TileText();
    int unk3c; int unk40; int unk44;
    char unk48;
};
struct FUN_00a0bc80 : Tile3D {
    inline FUN_00a0bc80() { unk2c.Assign(0); unk38=0; unk3c=0; }
    int unk3c; SmallArray first; SmallArray second;
};
struct FUN_00a21660 : TileImage {
    FUN_00a21660();
};
// @fnv 0x00a00c20
Tile* __cdecl FUN_00a00c20(int aiType)
{
    switch (aiType) {
    case 0x385: return (Tile*)new TileRect;
    case 0x386:
    case 0x38a: return (Tile*)new TileImage;
    case 0x388: return (Tile*)new FUN_00a0bc80;
    case 0x387: return (Tile*)new TileText;
    case 0x389: return (Tile*)new TileMenu;
    case 0x38c: return (Tile*)new FUN_00a21660;
    }
    return 0;
}
}  // namespace fnv_00a00c20

namespace tileext {

class ExtraObject {
public:
    virtual ~ExtraObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    int unk08;
    int m_iValue;
    void IncRefCount() { InterlockedIncrement((volatile long*)&m_uiRefCount); }
    void DecRefCount() { if (!InterlockedDecrement((volatile long*)&m_uiRefCount)) DeleteThis(); }
};

extern const char* DAT_011f34cc;

void FUN_00a044f0();
void FUN_00a04500();

struct TileListLock {
    TileListLock() { FUN_00a044f0(); }
    ~TileListLock() { FUN_00a04500(); }
};

struct ExtraNode {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ExtraNode* m_pParentNode;

    ExtraNode* GetParent() { return m_pParentNode; }
    static const char* GetKey() { return DAT_011f34cc; }
    ExtraObject* FUN_00a5bdd0(const char* pcKey);
};

// @fnv 0x00a01630
int FUN_00a01630(ExtraNode* pkNode)
{
    TileListLock kLock;
    int iValue = 0;
    if (pkNode)
    {
        NiPointer<ExtraObject> spExtra = pkNode->FUN_00a5bdd0(ExtraNode::GetKey());
        if (!spExtra && pkNode->GetParent())
            spExtra = pkNode->GetParent()->FUN_00a5bdd0(ExtraNode::GetKey());
        if (spExtra)
            iValue = spExtra->m_iValue;
    }
    return iValue;
}

}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* lpAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* lpAddend);

void __cdecl FUN_00a044f0();
void __cdecl FUN_00a04500();

class MenuLockA01 {
public:
    MenuLockA01() { FUN_00a044f0(); }
    ~MenuLockA01() { FUN_00a04500(); }
};

class RefObjectA01 {
public:
    virtual ~RefObjectA01();
    virtual void DeleteThis();

    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }

    long m_uiRefCount;
};


class ActionA01;
class ActionA01 : public RefObjectA01 {
public:
    int m_unk08;
    void* m_pkOwnerManager;
};

class ListA01 {
public:
    RefObjectA01* FUN_00a5bdd0(void* pKey);
    unsigned short GetCount() const { return m_usElementCount; }
    ActionA01* FindA(void* pKey) { return (ActionA01*)FUN_00a5bdd0(pKey); }
    ActionA01* FindN(void* pKey);
    RefObjectA01* FindR(void* pKey) { return FUN_00a5bdd0(pKey); }

    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
    unsigned short m_usElementCount;
};

extern void* DAT_011f34cc;

inline void* GetActionKeyA01() { return DAT_011f34cc; }

class TileA01 {
public:
    ListA01* GetList() const { return m_pkList; }
    ActionA01* FindAction(void* pKey) { ActionA01* pkFound = (ActionA01*)GetList()->FUN_00a5bdd0(pKey); return pkFound; }
    ActionA01* FindAction2() { ActionA01* pkFound = (ActionA01*)GetList()->FUN_00a5bdd0(GetActionKeyA01()); return pkFound; }
    void FUN_00a01750();

    int m_unk[11];
    ListA01* m_pkList;
};

inline void IncRefA01(ActionA01*& pkObject) { pkObject->IncRefCount(); }
inline void DecRefA01(ActionA01*& pkObject) { pkObject->DecRefCount(); }

inline ActionA01* ListA01::FindN(void* pKey)
{
    ActionA01* pkFound = (ActionA01*)FUN_00a5bdd0(pKey);
    return pkFound;
}

// @fnv 0x00a01750
void TileA01::FUN_00a01750()
{
    MenuLockA01 kLock;
    if (!GetList() || !GetList()->GetCount())
        return;

    NiPointer<ActionA01> spAction = (ActionA01*)GetList()->FUN_00a5bdd0(GetActionKeyA01());
    if (spAction)
        spAction->m_pkOwnerManager = 0;
}

namespace fnv_00a01e20 {
struct XmlAllocator {
    void* FUN_00aa3e40(unsigned int bytes);
    void FUN_00aa4060(void* memory);
};
extern XmlAllocator DAT_011f6238;
struct FUN_00a0ac80;
typedef FUN_00a0ac80 XmlNode;
struct FUN_00a0ac80 {
    static __forceinline void* operator new(unsigned int bytes) {
        return DAT_011f6238.FUN_00aa3e40(bytes);
    }
    static __forceinline void operator delete(void*) {}
    FUN_00a0ac80();
    XmlNode* m_pTreeNode;
    XmlNode* m_parent;
    XmlNode* m_iFirstChild;
    XmlNode* m_bSlotEnabled;
    unsigned int m_flags;
    void FUN_00a0a410(unsigned int kind, const char* name, unsigned int line, unsigned int flags);
};
struct XmlFile {
    unsigned int length;
    const char* data;
    ~XmlFile() {
        if (data) {
            const char* old = data;
            DAT_011f6238.FUN_00aa4060((void*)old);
        }
        data = 0;
    }
    static __forceinline void operator delete(void* p) {
        DAT_011f6238.FUN_00aa4060(p);
    }
};
extern unsigned char DAT_011f32c8;
extern const char DAT_01094a08[];
extern const char DAT_01094a3c[];
extern const char DAT_010949f0[];
extern const char DAT_010949d8[];
extern const char DAT_010949b0[];
extern const char DAT_0109498c[];
extern const char DAT_01094970[];
extern const char DAT_01094934[];
extern const char DAT_01094904[];
extern const char DAT_010948dc[];
XmlFile* __cdecl GetOrLoadXML(const char*, unsigned int);
void __cdecl FUN_00a02d40(XmlFile*);
int __cdecl TraitNameToID(const char*);
unsigned int __cdecl FUN_00ec6130(const char*);
bool __cdecl ResolveSettingString(const char*, char*);
void __cdecl FUN_005b5e40(const char*, ...);
// @fnv 0x00a01e20
XmlNode* __cdecl FUN_00a01e20(const char* filename, const char* source, unsigned int sourceLength)
{
    XmlNode* root3 = 0;
    root3 = new XmlNode;
    XmlFile* sourceFile3 = 0;
    const char* text_2 = 0;
    unsigned int length = 0;
    int tokenLimit4 = 0x1000;
    int tokenLength3 = 0;
    if (source != 0) {
        text_2 = source;
        length = sourceLength;
    } else {
        sourceFile3 = GetOrLoadXML(filename, 0);
        if (sourceFile3 != 0) {
            FUN_00a02d40(sourceFile3);
            text_2 = sourceFile3->data;
            length = sourceFile3->length;
        }
    }
    char value5[4096];
    char converted7[4096];
    char tag[128];
    value5[0] = 0;
    int aState = 0;
    int parameterType4 = 0;
    bool hasWhitespace8 = false;
    bool quotedB = false;
    bool kClosing = false;
    unsigned int line5 = 1;
    unsigned int offset_ = 0;
    for (offset_ = 0; offset_ < length; offset_++) {
        if (aState == 0) {
            if (text_2[offset_] == '<') {
                if (offset_ + 3 < length && text_2[offset_ + 1] == '!' &&
                    text_2[offset_ + 2] == '-' && text_2[offset_ + 3] == '-') {
                    hasWhitespace8 = false;
                    aState = 4;
                } else {
                    aState = 1;
                    tag[0] = 0;
                    kClosing = false;
                    tokenLength3 = 0;
                }
            }
        } else if (aState == 1) {
            if (tag[0] == 0 && text_2[offset_] == '/') {
                kClosing = true;
            } else if (text_2[offset_] == '>' ||
                       (offset_ + 1 < length && text_2[offset_] == '/' && text_2[offset_ + 1] == '>')) {
                if (tag[0] != 0 && kClosing) {
                    (root3->m_bSlotEnabled ? root3->m_bSlotEnabled : root3->m_pTreeNode)->FUN_00a0a410(1, tag, line5, 0);
                } else if (tag[0] != 0 && !kClosing) {
                    (root3->m_bSlotEnabled ? root3->m_bSlotEnabled : root3->m_pTreeNode)->FUN_00a0a410(0, tag, line5, 0);
                } else if (!hasWhitespace8) {
                    FUN_005b5e40(DAT_01094a08, DAT_01094a3c, filename, line5);
                    DAT_011f32c8 = 1;
                    return 0;
                }
                tokenLength3 = 0;
                if (text_2[offset_] == '/')
                    aState = 2;
                else
                    aState = 3;
                hasWhitespace8 = false;
                line5++;
            } else if ((unsigned char)text_2[offset_] <= ' ') {
                if (tag[0] != 0) {
                    if (kClosing)
                        (root3->m_bSlotEnabled ? root3->m_bSlotEnabled : root3->m_pTreeNode)->FUN_00a0a410(1, tag, line5, 0);
                    else
                        (root3->m_bSlotEnabled ? root3->m_bSlotEnabled : root3->m_pTreeNode)->FUN_00a0a410(0, tag, line5, 0);
                    tokenLength3 = 0;
                    hasWhitespace8 = true;
                    line5++;
                }
            } else if (hasWhitespace8) {
                offset_--;
                aState = 5;
                hasWhitespace8 = false;
            } else {
                tag[tokenLength3] = text_2[offset_];
                tokenLength3++;
                tag[tokenLength3] = 0;
            }
        } else if (aState == 4) {
            if (offset_ + 2 < length && text_2[offset_] == '-' &&
                text_2[offset_ + 1] == '-' && text_2[offset_ + 2] == '>') {
                offset_ += 2;
                aState = 3;
                hasWhitespace8 = false;
            }
        } else if (aState == 5) {
            if (text_2[offset_] == '>' ||
                (offset_ + 1 < length && text_2[offset_] == '/' && text_2[offset_ + 1] == '>')) {
                FUN_005b5e40(DAT_01094a08, DAT_010949f0, filename, line5);
                DAT_011f32c8 = 1;
                return 0;
            } else if (text_2[offset_] == '=') {
                if (value5[0] == 0) {
                    FUN_005b5e40(DAT_01094a08, DAT_010949d8, filename, line5);
                    DAT_011f32c8 = 1;
                    return 0;
                }
                parameterType4 = TraitNameToID(value5);
                value5[0] = 0;
                tokenLength3 = 0;
                aState = 6;
                hasWhitespace8 = false;
            } else if ((unsigned char)text_2[offset_] <= ' ') {
                if (value5[0] != 0) {
                    parameterType4 = TraitNameToID(value5);
                    value5[0] = 0;
                    tokenLength3 = 0;
                    hasWhitespace8 = true;
                }
            } else if (hasWhitespace8) {
                FUN_005b5e40(DAT_01094a08, DAT_010949b0, filename, line5);
                DAT_011f32c8 = 1;
                return 0;
            } else {
                value5[tokenLength3] = text_2[offset_];
                tokenLength3++;
                value5[tokenLength3] = 0;
                if (tokenLength3 > tokenLimit4)
                    FUN_005b5e40(DAT_0109498c);
            }
        } else if (aState == 6) {
            if (text_2[offset_] == '"') {
                quotedB = !quotedB;
            } else if (quotedB) {
                value5[tokenLength3] = text_2[offset_];
                tokenLength3++;
                value5[tokenLength3] = 0;
                if (tokenLength3 > tokenLimit4)
                    FUN_005b5e40(DAT_0109498c);
            } else if (text_2[offset_] == '>' ||
                       (offset_ + 1 < length && text_2[offset_] == '/' && text_2[offset_ + 1] == '>')) {
                if (value5[0] != 0) {
                    (root3->m_bSlotEnabled ? root3->m_bSlotEnabled : root3->m_pTreeNode)->FUN_00a0a410(parameterType4, value5, line5, 0);
                } else if (!hasWhitespace8) {
                    FUN_005b5e40(DAT_01094a08, DAT_01094970, filename, line5);
                    DAT_011f32c8 = 1;
                    return 0;
                }
                value5[0] = 0;
                tokenLength3 = 0;
                if (text_2[offset_] == '/')
                    aState = 2;
                else
                    aState = 3;
                hasWhitespace8 = false;
            } else if ((unsigned char)text_2[offset_] <= ' ') {
                if (value5[0] != 0) {
                    (root3->m_bSlotEnabled ? root3->m_bSlotEnabled : root3->m_pTreeNode)->FUN_00a0a410(parameterType4, value5, line5, 0);
                    value5[0] = 0;
                    tokenLength3 = 0;
                    hasWhitespace8 = true;
                }
            } else if (hasWhitespace8) {
                offset_--;
                aState = 5;
                hasWhitespace8 = false;
            } else {
                value5[tokenLength3] = text_2[offset_];
                tokenLength3++;
                value5[tokenLength3] = 0;
                if (tokenLength3 > tokenLimit4)
                    FUN_005b5e40(DAT_0109498c);
            }
        } else if (aState == 2) {
            if (text_2[offset_] == '>') {
                (root3->m_bSlotEnabled ? root3->m_bSlotEnabled : root3->m_pTreeNode)->FUN_00a0a410(1, tag, line5, 0);
                aState = 3;
                tag[0] = 0;
            } else {
                FUN_005b5e40(DAT_01094a08, DAT_01094934, filename, line5);
                DAT_011f32c8 = 1;
                return 0;
            }
        } else if (aState == 3) {
            if (text_2[offset_] == '<') {
                if (offset_ + 3 < length && text_2[offset_ + 1] == '!' &&
                    text_2[offset_ + 2] == '-' && text_2[offset_ + 3] == '-') {
                    hasWhitespace8 = false;
                    aState = 4;
                } else {
                    if (value5[0] != 0) {
                        for (tokenLength3 = FUN_00ec6130(value5) - 1;
                             (unsigned int)tokenLength3 >= 0 && (unsigned char)value5[tokenLength3] <= ' ';
                             tokenLength3--) {
                        }
                        value5[tokenLength3 + 1] = 0;
                        if (value5[0] == '&') {
                            if (value5[1] == '-') {
                                bool ok2 = ResolveSettingString(value5, converted7);
                                if (ok2)
                                    (root3->m_bSlotEnabled ? root3->m_bSlotEnabled : root3->m_pTreeNode)->FUN_00a0a410(0xbb9, converted7, line5, 0);
                            } else {
                                (root3->m_bSlotEnabled ? root3->m_bSlotEnabled : root3->m_pTreeNode)->FUN_00a0a410(0xbb9, value5, line5, 0);
                            }
                        } else if (value5[0] != 0) {
                            (root3->m_bSlotEnabled ? root3->m_bSlotEnabled : root3->m_pTreeNode)->FUN_00a0a410(0xbb9, value5, line5, 1);
                        }
                    }
                    value5[0] = 0;
                    tokenLength3 = 0;
                    hasWhitespace8 = false;
                    kClosing = false;
                    aState = 1;
                    tag[0] = 0;
                }
            } else if (offset_ + 1 < length && text_2[offset_] == '/' && text_2[offset_ + 1] == '>') {
                FUN_005b5e40(DAT_01094a08, DAT_01094904, filename, line5);
                DAT_011f32c8 = 1;
                return 0;
            } else if (text_2[offset_] == '>') {
                FUN_005b5e40(DAT_01094a08, DAT_010948dc, filename, line5);
                DAT_011f32c8 = 1;
                return 0;
            } else if ((unsigned char)text_2[offset_] > ' ' || hasWhitespace8 == true) {
                value5[tokenLength3] = text_2[offset_];
                tokenLength3++;
                value5[tokenLength3] = 0;
                if (tokenLength3 > tokenLimit4)
                    FUN_005b5e40(DAT_0109498c);
                hasWhitespace8 = true;
            }
        }
    }
    if (sourceFile3)
        delete sourceFile3;
    return root3;
}
}  // namespace fnv_00a01e20

namespace fnv_00a04200 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern char DAT_011f3330;
void __cdecl FUN_00a078e0();
extern __declspec(thread) int g_tlsMemContext;
inline int GetMemoryContext() { return g_tlsMemContext; }
inline void SetMemoryContext(int value) { g_tlsMemContext = value; }
struct AutoMemContext {
    int previous;
    AutoMemContext(int value) { previous = GetMemoryContext(); SetMemoryContext(value); }
    ~AutoMemContext() { SetMemoryContext(previous); }
};
struct UpdateTreeNode {
    void* vtable;
    void* children;
    void* childTail;
    unsigned int childCount;
    void* values;
    unsigned int valueCount;
    unsigned int reservedValues;
    const char* name;
    void* unknown20;
    void* unknown24;
    void* pParent;
    void* GetParent() { void* parent = pParent; return parent; }
    void* model;
    unsigned int flags;
    unsigned char changed;
    bool FUN_00a04640(bool);
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float, bool);
};
struct UpdateManager {
    void FUN_00713da0(UpdateTreeNode*);
    void FUN_00713e20();
};
extern UpdateManager* DAT_011d8a80;
extern void* DAT_011f3320;
inline void* GetPendingTiles() { void* pending = DAT_011f3320; return pending; }
extern bool DAT_011f32c9;
UpdateTreeNode* __cdecl FUN_00a07580(bool);
void* __cdecl FUN_00706cd0();
bool __cdecl FUN_00706d70();
void __cdecl FUN_00706db0(bool);
void __cdecl FUN_00a61cd0();

// @fnv 0x00a04200
void __cdecl FUN_00a04200(bool update)
{
    AutoMemContext autoMemContext(13);
    EnterCriticalSection(&DAT_011f3330);
    bool changed = false;
    DAT_011f32c9 = false;
    UpdateTreeNode* pTile;
    while (GetPendingTiles()) {
        pTile = FUN_00a07580(true);
        if (!pTile || (pTile->flags & 0x6800) || !(pTile->flags & 0x3ff))
            continue;
        changed = pTile->FUN_00a04640(true);
        pTile->changed = pTile->changed | changed;
        if (changed)
            DAT_011d8a80->FUN_00713da0(pTile);
        if (pTile->GetParent() == FUN_00706cd0()) {
            if (pTile->FUN_00a011b0(0xfa7) == 102.0)
                pTile->FUN_00a012d0(0xfa7, 6006.0f, true);
            else if (pTile->FUN_00a011b0(0xfa7) == 103.0)
                pTile->FUN_00a012d0(0xfa7, 6007.0f, true);
        }
    }
    if (DAT_011f32c9) {
        FUN_00a078e0();
        FUN_00a04200(update);
        LeaveCriticalSection(&DAT_011f3330);
        return;
    }
    if (update) {
        AutoMemContext kRenderContext(13);
        DAT_011d8a80->FUN_00713e20();
    }
    if (FUN_00706d70()) {
        AutoMemContext refreshContext(13);
        FUN_00706db0(false);
        FUN_00a61cd0();
    }
    LeaveCriticalSection(&DAT_011f3330);
}
}  // namespace fnv_00a04200

namespace fnv_00a07580 {
void __cdecl FUN_00a044f0();
void __cdecl FUN_00a04500();

struct LockGuard_00a07580 {
    LockGuard_00a07580() { ::FUN_00a044f0(); }
    ~LockGuard_00a07580() { ::FUN_00a04500(); }
};

struct TileResult_00a07580 {
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
    unsigned int flags;
    void SetFlag(bool set) {
        int a1; int a2; int a3;
        set ? (flags |= 0x400) : (flags &= ~0x400);
    }
};

struct TileNode_00a07580 {
    TileNode_00a07580* next;
    void* prev;
    TileResult_00a07580* item;
};

struct TileQueue_00a07580 {
    TileNode_00a07580* head;
    int unk04;
    int count;
    TileResult_00a07580* PopFrontScript();
    bool IsEmpty() { return count == 0; }
    TileResult_00a07580* Front() { return head->item; }
};

extern TileQueue_00a07580 DAT_011f3318;

// @fnv 0x00a07580
TileResult_00a07580* FUN_00a07580(bool pop) {
    LockGuard_00a07580 guard;
    if (DAT_011f3318.IsEmpty()) {
        return 0;
    } else if (pop) {
        TileResult_00a07580* tile = DAT_011f3318.PopFrontScript();
        if (tile) {
            tile->SetFlag(false);
        }
        return tile;
    } else {
        return DAT_011f3318.Front();
    }
}
}  // namespace fnv_00a07580

struct ClipRect { int left, top, right, bottom; };
struct ClipProperty {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    unsigned int unk80, unk84, unk88, unk8c, unk90, unk94, unk98;
    ClipRect clip;
    void FUN_00bb79d0(bool);
};
struct ClipGeometry { ClipProperty* GetProperty(unsigned int); };
struct ClipArray;
inline void __fastcall FUN_004afc80(ClipArray*);
void __fastcall TrimTrailingNullPointers(void*);
struct ClipPointer {
    ClipGeometry* pointer;
    __forceinline ClipGeometry* operator->() { return pointer; }
};
struct ClipArray {
    void* vtable;
    ClipPointer* data;
    unsigned short capacity, size, count, grow;
    __forceinline ClipPointer& At(unsigned int index) { return data[index]; }
};

ClipPointer* __cdecl AllocateClipArray(unsigned int);
void __cdecl FreeClipArray(ClipPointer*);
inline void __fastcall FUN_004afc80(ClipArray* array) {
    ClipPointer* oldData;
    unsigned short source;
    unsigned short destination;
    if (array->count == array->size) return;
    if (array->count) {
        destination = 0;
        for (source = 0; source < array->size; ++source) {
            if (array->data[source].pointer) {
                if (source != destination) array->data[destination] = array->data[source];
                ++destination;
            }
        }
    }
    oldData = array->data;
    array->capacity = array->size = array->count;
    if (array->capacity) {
        array->data = AllocateClipArray(array->capacity);
        for (source = 0; source < array->size; ++source)
            array->data[source] = oldData[source];
    } else array->data = 0;
    FreeClipArray(oldData);
}

struct ClipNode {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    unsigned int unk80, unk84, unk88, unk8c, unk90, unk94, unk98;
    ClipArray children;
};
struct ClipTile;
struct ClipListNode { ClipListNode* next; void* prev; ClipTile* item; };
struct ClipTile {
    void* vtable; ClipListNode* children;
    unsigned int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    ClipNode* model;
    __forceinline ClipNode* Model() { return model; }
    bool IsTraitNonZero(int);
    bool FUN_00a03c60();
    void FUN_00a07a40(float left, float top, float right, float bottom);
};
float __cdecl FUN_00706e40();
float __cdecl FUN_00706e10();
float __cdecl FUN_00706e80();
float __cdecl FUN_00706e90();
__forceinline float ClipMax(float a, float b) { return a > b ? a : b; }
// @fnv 0x00a07a40
void ClipTile::FUN_00a07a40(float left, float top, float right, float bottom)
{
    ClipListNode* position;
    ClipTile* child;
    unsigned int index;
    ClipProperty* property;
    float width;
    float height;
    {
    ClipRect rect;
    ClipListNode* head = children;
    position = head;
    while (position) {
        ClipTile*& entry = position->item;
        position = position->next;
        child = entry;
        if (child->IsTraitNonZero(0xfae)) {
            ClipNode* modelCheck = child->model;
            if (modelCheck) {
            index = 0;
            ClipNode* modelCompact = child->model;
            FUN_004afc80(&modelCompact->children);
            TrimTrailingNullPointers(&modelCompact->children);

            {
            while (index < child->Model()->children.count) {
                {
                property = child->Model()->children.At(index)->GetProperty(3);
                if (property) {
                    height = FUN_00706e40();
                    width = FUN_00706e10();
                    if (FUN_00a03c60()) {
                        height = FUN_00706e80();
                        width = FUN_00706e90();
                    }
                    rect.left = (int)ClipMax(left, 0.0f);
                    rect.top = (int)ClipMax(top, 0.0f);
                    rect.right = (int)(right < height ? right : height);
                    rect.bottom = (int)(bottom < width ? bottom : width);
                    property->clip = rect;
                    property->FUN_00bb79d0(true);
                }
                }
                ++index;
            }
        }
        }
        }
        child->FUN_00a07a40(left, top, right, bottom);
    }
    }
}

class SceneRefObject {
public:
    virtual ~SceneRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount() { InterlockedIncrement((volatile long*)&m_uiRefCount); }
    void DecRefCount() { if (!InterlockedDecrement((volatile long*)&m_uiRefCount)) DeleteThis(); }
};

class SceneNode;

class SceneParent {
public:
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
    virtual void InsertChild(SceneNode* pkChild);
};

class SceneNode : public SceneRefObject {
public:
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    SceneParent* m_pParentNode;
    SceneParent* GetParent() { return m_pParentNode; }
};

class SceneNodeOwner {
public:
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
    NiPointer<SceneNode> m_spNode;
    SceneNode* GetNode() { return m_spNode; }
    void FUN_00a01750();
    void FUN_00a08a20();
};

// @fnv 0x00a08a20
void SceneNodeOwner::FUN_00a08a20()
{
    SceneNode* pkNode = GetNode();
    if (!pkNode)
        return;
    FUN_00a01750();
    if (pkNode->GetParent())
        pkNode->GetParent()->InsertChild(pkNode);
    NiPointer<SceneNode> spHold = pkNode;
    m_spNode = 0;
    spHold = 0;
}

struct MenuArray {
    void* vtbl;
    int* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    unsigned int GetSize() { return m_usSize; }
    int& GetAt(unsigned int index) { return m_pBase[index]; }
};
extern MenuArray DAT_011f3508;

// @fnv 0x00a09030
int __cdecl FUN_00a09030(int id)
{
    int result;
    if (id >= 0x3e9 && id <= 0x43c && DAT_011f3508.GetSize() > (unsigned int)(id - 0x3e9)) {
        result = DAT_011f3508.GetAt(id - 0x3e9);
    } else {
        result = 0;
    }
    return result;
}

namespace fnv_00a0a130 {
struct MemoryHeap_a0a130 {
    void* FUN_00aa3e40(unsigned int uiSize);
    void FUN_00aa4060(void* pvMem);
};
extern MemoryHeap_a0a130 DAT_011f6238;

struct ListNode_a0a130 {
    int m_item;
    ListNode_a0a130* m_pkNext;
    ListNode_a0a130() { m_item = 0; m_pkNext = 0; }
    static void* operator new(unsigned int uiSize) { return DAT_011f6238.FUN_00aa3e40(uiSize); }
    static void operator delete(void* pvMem)
    {
        int unused[5];   // frame space the original's inlined pool free reserves (never touched)
        DAT_011f6238.FUN_00aa4060(pvMem);
    }
};

struct ListMap_a0a130 {
    bool FUN_00a1e380(int iKey, ListNode_a0a130*& rpkNode);
    void InsertOrUpdate(int iKey, ListNode_a0a130* pkCur);
};
extern ListMap_a0a130 DAT_011f3358;

// @fnv 0x00a0a130
void __cdecl FUN_00a0a130(int iKey, int iItem)
{
    ListNode_a0a130* pkNew = new ListNode_a0a130;
    ListNode_a0a130* pkCur = 0;
    pkNew->m_item = iItem;
    if (DAT_011f3358.FUN_00a1e380(iKey, pkCur)) {
        bool bFound = pkCur->m_item == iItem;
        while (pkCur->m_pkNext) {
            pkCur = pkCur->m_pkNext;
            bFound = pkCur->m_item == iItem;
        }
        if (!bFound)
            pkCur->m_pkNext = pkNew;
        else
            delete pkNew;
    } else {
        DAT_011f3358.InsertOrUpdate(iKey, pkNew);
    }
}
}  // namespace fnv_00a0a130

void __cdecl FUN_00a044f0();
void __cdecl FUN_00a04500();
extern const double _gModifierZero;

class MenuLockB35 {
public:
    MenuLockB35() { FUN_00a044f0(); }
    ~MenuLockB35() { FUN_00a04500(); }
};

class TileB35;

class TileListB35 {
public:
    NiTListItem<TileB35*>* GetHeadPos() const { return m_pkHead; }
    TileB35*& GetNext(NiTListItem<TileB35*>*& pkPos)
    {
        TileB35*& pkElement = pkPos->m_element;
        pkPos = pkPos->m_pkNext;
        return pkElement;
    }

    NiTListItem<TileB35*>* m_pkHead;
};

class TileB35 {
public:
    void FUN_00a07530(int);
    void FUN_00a0b350(int iValue, float fDefault);

    void* m_pVTable;
    TileListB35 m_kChildList;
};

// @fnv 0x00a0b350
void TileB35::FUN_00a0b350(int iValue, float fDefault)
{
    MenuLockB35 kLock;
    float fValue = ((Tile*)this)->GetFloat(0xff4);
    if (fValue == _gModifierZero)
        fValue = fDefault;
    if ((float)iValue == fValue)
        FUN_00a07530(8);

    NiTListItem<TileB35*>* pkPos = m_kChildList.GetHeadPos();
    while (pkPos)
        m_kChildList.GetNext(pkPos)->FUN_00a0b350(iValue, fValue);
}

unsigned int __cdecl FUN_0044a670(const char* text);
unsigned int __cdecl FUN_00403940(unsigned int a, unsigned int b);
void* __cdecl FormHeap_Allocate(unsigned int size);
void __cdecl FormHeap_Free(void* p);
void* __cdecl FUN_00401460(void* dst, const void* src, unsigned int size);

template <> inline void BSStringT<char>::SetLength(unsigned int length)
{
    sLen = length <= 0xFFFF ? (unsigned short)length : 0xFFFF;
}

template <> inline void BSStringT<char>::SetMaxLength(unsigned int length)
{
    sMaxLen = length <= 0xFFFF ? (unsigned short)length : 0xFFFF;
}

template <> inline BSStringT<char>::BSStringT()
{
    pString = 0;
    SetLength(0);
    SetMaxLength(0);
}

template <> inline bool BSStringT<char>::Set(const char* text, unsigned int length)
{
    unsigned int srcLen = text ? FUN_0044a670(text) : 0;
    unsigned int newLen = FUN_00403940(srcLen, length);
    unsigned int maxLen = MaxLength();
    if (newLen > maxLen) {
        char* oldString = pString;
        char* newString = (char*)FormHeap_Allocate(newLen + 1);
        pString = newString;
        if (text)
            FUN_00401460(pString, text, srcLen + 1);
        else
            *pString = 0;
        if (oldString) {
            char* p = oldString;
            FormHeap_Free(p);
        }
        SetMaxLength(newLen);
    } else if (newLen) {
        if (text)
            FUN_00401460(pString, text, srcLen + 1);
        else
            *pString = 0;
    } else {
        if (pString) {
            char* p = pString;
            FormHeap_Free(p);
        }
        pString = 0;
        newLen = 0;
        SetMaxLength(newLen);
    }
    SetLength(srcLen);
    bool result = srcLen != 0;
    return result;
}

class FUN_00a0c220 {
public:
    FUN_00a0c220(int aiType, float afValue, const char* apText, int aiParam1, int aiParam2);
    int m_iType;
    float m_fValue;
    BSStringT<char> m_kText;
    int m_iParam1;
    int m_iParam2;
};

// @fnv 0x00a0c220
FUN_00a0c220::FUN_00a0c220(int aiType, float afValue, const char* apText, int aiParam1, int aiParam2)
{
    m_iType = aiType;
    m_fValue = afValue;
    m_kText.Set(apText, 0x1F);
    m_iParam1 = aiParam1;
    m_iParam2 = aiParam2;
}

void __cdecl NiFreeD3C0(void* pvMem);

struct MemoryManagerD3C0 {
    void Deallocate(void* pvMem);
};
extern MemoryManagerD3C0 g_kMemoryManagerD3C0;

struct MapItemD3C0 {
    MapItemD3C0* m_pkNext;
    const char* m_key;
    void* m_val;
};

class MapBaseD3C0 {
public:
    static void operator delete(void* pvMem) { g_kMemoryManagerD3C0.Deallocate(pvMem); }
    virtual ~MapBaseD3C0()
    {
        RemoveAll();
        NiFreeD3C0(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(MapItemD3C0* pkItem, const char* key, void* val);
    virtual void ClearValue(MapItemD3C0* pkItem);
    virtual MapItemD3C0* NewItem();
    virtual void DeleteItem(MapItemD3C0* pkItem);
    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++) {
            while (m_ppkHashTable[i]) {
                MapItemD3C0* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }
    unsigned int m_uiHashSize;
    MapItemD3C0** m_ppkHashTable;
    unsigned int m_uiCount;
};
class FUN_00a0d3c0 : public MapBaseD3C0 {
public:
    virtual ~FUN_00a0d3c0();
};

// @fnv 0x00a0d3c0
FUN_00a0d3c0::~FUN_00a0d3c0()
{
    RemoveAll();
}

namespace fnv_00a1e1d0 {
struct A1E1D0_Pool { void __thiscall FUN_00aa4060(void* p); };
extern A1E1D0_Pool DAT_011f6238;
struct FUN_00a0c190
{
    int m_00;
    ~FUN_00a0c190();
    static void operator delete(void* p) { int unused[4]; (void)unused; DAT_011f6238.FUN_00aa4060(p); }
};
struct A1E1D0_Holder
{
    FUN_00a0c190* m_entry;
    void FUN_00a1e1d0(FUN_00a0c190* entry);
};
// @fnv 0x00a1e1d0
void A1E1D0_Holder::FUN_00a1e1d0(FUN_00a0c190* entry)
{
    if (m_entry)
        delete m_entry;
    m_entry = entry;
}
}  // namespace fnv_00a1e1d0

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* value);
extern int DAT_0109b220;
extern const void* DAT_01094cfc[];

extern "C" char* __cdecl FUN_00a5b690(const char* text);

class NiFixedString {
public:
    char* text;
    __forceinline NiFixedString(const char* str) {
        if (str == 0) {
            text = (char*)DAT_0109b220;
            return;
        }
        text = FUN_00a5b690(str);
    }
    __forceinline ~NiFixedString() {
        if (text == (char*)DAT_0109b220) {} else {
            char* p = text - 8;
            InterlockedDecrement((long volatile*)p);
        }
    }
};

class FUN_00a7b2e0
{
public:
    const void** vtable;
    ~FUN_00a7b2e0();
    int m_04;
    int m_08;
    FUN_00a7b2e0();
};

class FUN_00a1f610 : public FUN_00a7b2e0
{
public:
    int m_0c;
    int m_10;
    FUN_00a1f610(int a, int b);
    void AssignFixedString(const NiFixedString& name);
};

// @fnv 0x00a1f610
FUN_00a1f610::FUN_00a1f610(int a, int b)
    : FUN_00a7b2e0()
{
    vtable = DAT_01094cfc;
    m_0c = a;
    m_10 = b;
    AssignFixedString(NiFixedString("Tileptr"));
}

namespace fnv_00aaa7d0 {
// FUN_00aaa7d0 -- reads the "FRCTL001" fractal header through the archive stream.
//
// NOTE on the frame: the original reserves 0x54 bytes of frame that no instruction
// references.  They are the frames of two /Ob1 inline candidates that the compiler
// started to inline and then declined (it allocates their locals in the caller's
// frame anyway, see the "declined inline" reservation behaviour of VC9 /Od+/Ob1):
//   * the FUN_00ac5490 constructor (12 dwords) -- reserved after the bool temps,
//     which is what puts the argument-address temp at [ebp-0xc0] (-0x30).
//   * FractalHeader::FUN_00aaa720 (9 dwords) -- reserved after it, which is what
//     puts the discarded call-result temps at [ebp-0xe8..-0xf1] (-0x54).
// Both bodies below are therefore sized to reproduce those reservations (and are
// big enough that the inliner declines them instead of expanding them).
extern const unsigned int DAT_010173f0;
namespace std {
template<class T> struct char_traits {};
template<class T> struct allocator {};
template<class T, class Traits, class Alloc> struct basic_string {
    unsigned int allocator;
    union Storage { char buffer[16]; char* pointer; } storage;
    unsigned int length;
    unsigned int capacity;
    basic_string(const char*);
    void _Tidy(bool, unsigned int);
    basic_string& assign(const basic_string&, unsigned int, unsigned int);
    __forceinline basic_string(const basic_string& rhs) {
        _Tidy(false, 0);
        assign(rhs, 0, DAT_010173f0);
    }
    __forceinline ~basic_string() { _Tidy(true, 0); }
};

}
typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > GameString;

extern void* DAT_010a2c38[];
struct FUN_00aaaa80 {
    GameString signature;
    GameString filename;
    unsigned int flags;
    FUN_00aaaa80();
    virtual ~FUN_00aaaa80();
};
struct FUN_00ac5490 : FUN_00aaaa80 {
    void* file;
    void* archive;
    FUN_00ac5490(GameString signature);
    bool FUN_00ac5540(GameString filename, bool binary);
    bool FUN_00ac5e00(void* buffer, unsigned int size, unsigned int count);
    void ClearHolders();
    __forceinline ~FUN_00ac5490() {
        ClearHolders();
    }
};
struct FractalHeader {
    unsigned int width;
    unsigned int height;
    unsigned int values[2][2];
    void FUN_00aaa720();
};
struct FractalReaderA { bool FUN_00aaac10(FUN_00ac5490*, unsigned int (*)[2]); };
struct FractalReaderB { bool FUN_00aaaf10(FUN_00ac5490*, unsigned int (*)[2]); };

inline FUN_00ac5490::FUN_00ac5490(GameString signature)
{
    int c00, c01, c02, c03, c04, c05, c06, c07, c08, c09, c10;
    c00 = (int)&signature; c01 = c00 + 1; c02 = c01 + 1; c03 = c02 + 1;
    c04 = c03 + 1; c05 = c04 + 1; c06 = c05 + 1; c07 = c06 + 1;
    c08 = c07 + 1; c09 = c08 + 1; c10 = c09 + 1;
}

inline void FractalHeader::FUN_00aaa720()
{
    int u00, u01, u02, u03, u04, u05, u06, u07, u08;
    u00 = 0; u01 = 1; u02 = 2; u03 = 3; u04 = 4; u05 = 5; u06 = 6; u07 = 7; u08 = 8;
    u00 = u01 + u02; u01 = u02 + u03; u02 = u03 + u04; u03 = u04 + u05; u04 = u05 + u06;
    u05 = u06 + u07; u06 = u07 + u08; u07 = u08 + u00; u08 = u00 + u01; u00 = u01 * u02;
    u01 = u02 * u03; u02 = u03 * u04; u03 = u04 * u05; u04 = u05 * u06; u05 = u06 * u07;
    u06 = u07 * u08; u07 = u08 * u00; u08 = u00 + u01; u00 = u01 + u02; u01 = u02 + u03;
}

// @fnv 0x00aaa7d0
bool __cdecl FUN_00aaa7d0(const GameString& filename, unsigned int* width,
    unsigned int* height, unsigned int values[2][2], FractalReaderA* a, FractalReaderB* b)
{
    FUN_00ac5490 stream("FRCTL001");
    if (!stream.FUN_00ac5540(filename, true))
        return false;
    FractalHeader header;
    if (!stream.FUN_00ac5e00(&header, 1, 24))
        return false;
    header.FUN_00aaa720();
    *width = header.width;
    *height = header.height;
    for (unsigned int i = 0; i < 2; i++)
        for (unsigned int j = 0; j < 2; j++)
            values[i][j] = header.values[i][j];
    if (!a->FUN_00aaac10(&stream, values))
        return false;
    if (!b->FUN_00aaaf10(&stream, values))
        return false;
    return true;
}
}  // namespace fnv_00aaa7d0

// Scalar deleting destructor of a Tile subclass: its inline destructor releases the tile's
// resources unless flag 0x2000 is set, then the Tile base destructor runs and the memory goes
// back to the game heap.
struct TileBaseA0BBF0 {
    virtual ~TileBaseA0BBF0();
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    unsigned int uiFlags;

    bool GetFlag(unsigned int uiFlag) const { return (uiFlags & uiFlag) != 0; }
    void Release();
    static void operator delete(void* p) { _g_memoryManager.Deallocate(p); }
};

struct FUN_00a0bbf0 : TileBaseA0BBF0 {
// @fnv 0x00a0bbf0
    virtual ~FUN_00a0bbf0()
    {
        if (!GetFlag(0x2000))
            Release();
    }
};

TileBaseA0BBF0* CreateTileA0BBF0()
{
    return new FUN_00a0bbf0;
}

namespace fnv_00a0c0c0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);
char* __cdecl FUN_00a5b690(const char* text);
struct A0C0C0_String
{
    char* m_handle;
    A0C0C0_String(const A0C0C0_String& other) : m_handle(other.m_handle) {}
    ~A0C0C0_String();
    A0C0C0_String& operator=(const char* text);
};
extern A0C0C0_String DAT_0109b220;
inline A0C0C0_String& A0C0C0_String::operator=(const char* text)
{
    if (m_handle != text) {
        char* old = m_handle;
        m_handle = FUN_00a5b690(text);
        if (old == DAT_0109b220.m_handle)
            return *this;
        long* header = (long*)(old - 8);
        InterlockedDecrement(header);
    }
    return *this;
}
struct A0C0C0_Range
{
    int m_kRayStart;
    int m_kRayEnd;
    int m_uiItemCount;
    A0C0C0_Range() { m_uiItemCount = 0; m_kRayStart = 0; m_kRayEnd = 0; }
    ~A0C0C0_Range();
};
struct A0C0C0_Entry
{
    A0C0C0_String m_name;
    int m_uiFilterValue;
    A0C0C0_Range m_range;
    A0C0C0_Entry(const char* name, int value);
};
// @fnv 0x00a0c0c0
A0C0C0_Entry::A0C0C0_Entry(const char* name, int value) : m_name(DAT_0109b220)
{
    m_name = name;
    m_uiFilterValue = value;
}
}  // namespace fnv_00a0c0c0

void __cdecl FUN_00aa10f0(void* p);
struct A0D2A0_Item
{
    A0D2A0_Item* m_pkNext;
    const char* m_key;
    void* m_val;
};
struct A0D2A0_MapBase
{
    virtual ~A0D2A0_MapBase() { int unused[4]; (void)unused; ClearAll(); FUN_00aa10f0(m_ppkHashTable); }
    virtual void ClearAll();
    unsigned int m_uiHashSize;
    A0D2A0_Item** m_ppkHashTable;
    unsigned int m_uiCount;
};
struct A0D2A0_Map : A0D2A0_MapBase
{
    virtual ~A0D2A0_Map() { ClearAll(); }
};
struct A0D2A0_StringMap : A0D2A0_Map
{
    bool m_bCopy;
    virtual ~A0D2A0_StringMap();
};
// @fnv 0x00a0d2a0
A0D2A0_StringMap::~A0D2A0_StringMap()
{
    if (m_bCopy) {
        for (unsigned int i = 0; i < m_uiHashSize; i++) {
            A0D2A0_Item* item = m_ppkHashTable[i];
            while (item) {
                A0D2A0_Item* save = item;
                item = item->m_pkNext;
                FUN_00aa10f0((void*)save->m_key);
            }
        }
    }
}

void __cdecl S_00a04150_Free(void*);
struct S_00a04150_Elem {
    virtual ~S_00a04150_Elem();
};

struct S_00a04150_Node {
    S_00a04150_Node* m_pkNext;
    S_00a04150_Node* m_pkPrev;
    S_00a04150_Elem* m_element;
};

struct S_00a04150_List {
    S_00a04150_Node* m_pkHead;
    S_00a04150_Node* m_pkTail;
    unsigned int m_uiCount;
    void* GetHeadPos() const { return m_pkHead; }
    S_00a04150_Elem* GetNext(void*& kPos) const {
        S_00a04150_Elem*& element = ((S_00a04150_Node*)kPos)->m_element;
        kPos = ((S_00a04150_Node*)kPos)->m_pkNext;
        return element;
    }
    void FUN_004ed900() {
        S_00a04150_Node* pkDel;
        S_00a04150_Node* pkNext;
        S_00a04150_Node* pkPrev;
        S_00a04150_Node* pkCur;
        unsigned int ItemUpdateArray;
        while (m_pkHead) {
            pkDel = m_pkHead;
            pkCur = pkDel;
            pkNext = pkCur->m_pkNext;
            pkPrev = pkCur->m_pkPrev;
            m_pkHead = pkNext;
            if (pkNext) pkNext->m_pkPrev = pkPrev;
            pkDel->m_element = 0;
            S_00a04150_Free(pkDel);
            ItemUpdateArray = m_uiCount;
            m_uiCount = ItemUpdateArray - 1;
        }
        m_pkTail = 0;
    }
};

struct S_00a04150_Class {
    int unk00;
    S_00a04150_List m_kNode;
    void FUN_00a04150();
};

// @fnv 0x00a04150
void S_00a04150_Class::FUN_00a04150()
{
    AutoTileLock_Local kLock;
    void* kPos = m_kNode.GetHeadPos();
    while (kPos) {
        delete m_kNode.GetNext(kPos);
    }
    m_kNode.FUN_004ed900();
}

namespace fnv_00a01b00 {
struct MemoryManager { void Deallocate(void*); };
extern MemoryManager g_memoryManager;
extern __declspec(thread) int DAT_000002b4;
extern void (__stdcall *DAT_00fdf05c)(void*);
extern void (__stdcall *DAT_00fdf100)(void*);
struct FUN_00a031b0_shell { Tile* CreateMenuTiles(void*); };
struct Tile__TileTemplate;

struct TemplateListNode {
    Tile__TileTemplate* pItem;
    TemplateListNode* pNext;
};

struct FUN_00a0ad40 {
    void* unk00;
    TemplateListNode kList;
    void* unk0c;
    bool bUnk10;

    ~FUN_00a0ad40();
    void operator delete(void* p) {
        g_memoryManager.Deallocate(p);
    }
};

extern unsigned int DAT_0126fd98;
extern unsigned char DAT_011f32c8;
struct TileManager {
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
    int criticalSection;
    void Enter() { DAT_00fdf05c(&criticalSection); }
    void Leave() { if(0){} DAT_00fdf100(&criticalSection); }
};
extern TileManager* DAT_011f4748;
__forceinline TileManager* GetDebrisManager() { return DAT_011f4748; }

__forceinline int GetMemContext() { return DAT_000002b4; }
__forceinline void SetMemContext(int context) { DAT_000002b4 = context; }

struct AutoMemContext {
    int m_eOldContext;

    __forceinline AutoMemContext(int aeMemoryContext) {
        m_eOldContext = GetMemContext();
        SetMemContext(aeMemoryContext);
    }
    __forceinline ~AutoMemContext() {
        SetMemContext(m_eOldContext);
    }
};

FUN_00a0ad40* __cdecl FUN_00a01e20(void* a1, int a2, int a3);

struct FUN_00a1dd80_Class : public Menu {
    bool bUnk1d;
    void FUN_00a1dd80(Tile__TileTemplate*);
};

struct TileLoader : public FUN_00a031b0_shell {
    void FUN_00a033b0(void*);
    void FUN_00a04620(bool);
    Tile* ReadXML(void* arg0);
};

// @fnv 0x00a01b00
Tile* TileLoader::ReadXML(void* arg0) {
    AutoMemContext kContext(0xd);
    DAT_011f32c8 = 0;
    Tile* pTile7 = 0;
    FUN_00a0ad40* pTemplate = 0;
    bool bKeep_ = 0;

    pTemplate = FUN_00a01e20(arg0, 0, 0);
    if (DAT_011f32c8)
        return 0;

    pTile7 = this->CreateMenuTiles(pTemplate->unk0c ? pTemplate->unk0c : pTemplate->unk00);
    if (DAT_011f32c8)
        return 0;

    ((TileLoader*)pTile7)->FUN_00a033b0(pTemplate->unk0c ? pTemplate->unk0c : pTemplate->unk00);
    if (DAT_011f32c8)
        return 0;

    FUN_00a1dd80_Class* pMenu = (FUN_00a1dd80_Class*)pTile7->GetMenu();
    if (pMenu) {
        TemplateListNode* pNode = &pTemplate->kList;
        while (pNode && pNode->pItem) {
            pMenu->FUN_00a1dd80(pNode->pItem);
            pMenu->bUnk1d = !bKeep_;
            pTemplate->bUnk10 = bKeep_;
            if (DAT_011f32c8)
                return 0;
            pNode = pNode->pNext;
        }
    }

    if (!bKeep_) {
        delete pTemplate;
        pTemplate = 0;
    }

    GetDebrisManager()->Enter();
    if (pTile7) ((TileLoader*)pTile7)->FUN_00a04620(false);
if(0){} GetDebrisManager()->Leave();

    DAT_011f32c8 = 0;
    return pTile7;
}
}  // namespace fnv_00a01b00

namespace fnv_00a0a410 {
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" int __cdecl sscanf(const char*, const char*, ...);

inline unsigned int __cdecl FUN_0044a670(const char* value) { return strlen(value); }
unsigned int __cdecl FUN_00403940(unsigned int, unsigned int);
void* __cdecl FormHeap_Allocate(unsigned int);
void __cdecl FormHeap_Free(void*);
inline void* __cdecl FUN_00401460(void* d, const void* s, unsigned n) { return memcpy(d,s,n); }
inline void ReleaseParsedString(void* pointer) { FormHeap_Free(pointer); }
extern double DAT_01094ba8, DAT_01012060, DAT_01094ce8, DAT_01094ca0, DAT_01094c98, DAT_01094c90, DAT_01094c88, DAT_01073490, DAT_01094c80;
extern const char DAT_01011584[], DAT_01094cf0[], DAT_01094ca8[], DAT_01094c58[];


struct ParsedText {
    char* text;
    unsigned short length;
    unsigned short capacity;
    bool FUN_004037f0(const char* source, unsigned int reserveMinimum) {
        unsigned int sourceLength = source ? FUN_0044a670(source) : 0;
        unsigned int allocatedLength = FUN_00403940(sourceLength, reserveMinimum);
        if (allocatedLength <= FUN_004039a0()) {
            if (allocatedLength) {
                if (source) FUN_00401460(text, source, sourceLength + 1);
                else text[0] = 0;
            } else {
                if (text) delete[] text;
                text = 0;
                allocatedLength = 0;
                FUN_00403a00(allocatedLength);
            }
        } else {
            char* old = text;
            text = new char[allocatedLength + 1];
            if (source) FUN_00401460(text, source, sourceLength + 1);
            else text[0] = 0;
            if (old) delete[] old;
            FUN_00403a00(allocatedLength);
        }
        FUN_004039c0(sourceLength);
        return sourceLength != 0;
    }
    unsigned int FUN_004048e0() const {
        return length == 0xffff ? FUN_0044a670(text) : length;
    }
    unsigned int FUN_004039a0() const { return capacity; }
    const char* FUN_00559450() const { return text; }
    void FUN_00403a00(unsigned int n) { capacity = n <= 0xffff ? (unsigned short)n : 0xffff; }
    void FUN_004039c0(unsigned int n) { length = n <= 0xffff ? (unsigned short)n : 0xffff; }
    bool FUN_00438470(const ParsedText& rhs) {
        unsigned int n = rhs.FUN_004048e0();
        if (n <= FUN_004039a0()) {
            if (n) FUN_00401460(text, rhs.FUN_00559450(), n + 1);
            else {
                if (text) delete[] text;
                text = 0;
                n = 0;
                FUN_00403a00(n);
            }
        } else {
            char* old = text;
            text = new char[n + 1];
            FUN_00401460(text, rhs.FUN_00559450(), n + 1);
            if (old) delete[] old;
            FUN_00403a00(n);
        }
        FUN_004039c0(n);
        return n != 0;
    }
    __forceinline ParsedText& operator=(const char* source) { FUN_004037f0(source, 0); return *this; }
    __forceinline ParsedText& operator=(const ParsedText& source) { FUN_00438470(source); return *this; }
    ~ParsedText() { FUN_004037f0(0, 0); }
};
struct ParsedToken {
    int kind;
    float value;
    ParsedText text;
    int integer;
    void* context;
    static void operator delete(void* pointer) { DAT_011f6238.FUN_00aa4060(pointer); }
    __forceinline void SetText(const char* value) {
        ParsedText* textObject = &text;
        textObject->FUN_004037f0(value, 0);
    }
    __forceinline void CopyText(const ParsedText& value) {
        ParsedText* textObject = &text;
        textObject->FUN_00438470(value);
    }
};
struct ParsedNode {
    static void* operator new[](unsigned int bytes) { return FormHeap_Allocate(bytes); }
    ParsedNode* next;
    ParsedNode* previous;
    ParsedToken* value;
};
unsigned int FUN_0040fc90();
void FUN_0040fca0(unsigned int);
void FUN_0040fbe0();
unsigned int FUN_0043b460(volatile unsigned int*, unsigned int, unsigned int);
struct ParsedPoolLock {
    volatile unsigned int owner;
    unsigned int recursion;
    void Lock(int) {
        unsigned int thread = FUN_0040fc90();
        if (owner == thread) ++recursion;
        else {
            unsigned int spins = 0;
            while (FUN_0043b460(&owner, 0, thread)) {
                ++spins;
                if (spins > 10000) FUN_0040fca0(1);
                else FUN_0040fca0(0);
            }
            FUN_0040fbe0();
            recursion = 1;
        }
    }
    void Unlock() {
        FUN_0040fbe0();
        --recursion;
        if (!recursion) owner = 0;
    }
};
extern ParsedPoolLock DAT_011c5f80;
extern ParsedNode* DAT_011c5f58;
extern unsigned int DAT_01188f7c;
extern ParsedNode* DAT_011c5f54;
inline void FUN_0043a080() {
    DAT_011c5f58 = new ParsedNode[DAT_01188f7c];
    ParsedNode* node = DAT_011c5f58 + DAT_01188f7c - 1;
    node->next = 0;
    unsigned int index = 1;
    do {
        node = DAT_011c5f58 + index;
        node->next = node + 1;
    } while (index++ < DAT_01188f7c - 2);
    if (DAT_011c5f54) {
        DAT_011c5f58->next = DAT_011c5f54;
        DAT_011c5f54 = DAT_011c5f58;
    } else {
        DAT_011c5f54 = DAT_011c5f58;
        DAT_011c5f54->next = 0;
    }
    ++DAT_011c5f58;
}
struct ParsedAllocator {
    unsigned count;
    ParsedNode* FUN_0043a010() {
        DAT_011c5f80.Lock(0);
        if (!DAT_011c5f58) FUN_0043a080();
        ParsedNode* node = DAT_011c5f58;
        DAT_011c5f58 = DAT_011c5f58->next;
        node->value = 0;
        node->next = 0;
        node->previous = 0;
        DAT_011c5f80.Unlock();
        return node;
    }
    void FUN_0045cee0(ParsedNode* node) {
        DAT_011c5f80.Lock(0);
        ParsedNode* item = node;
        item->previous = 0;
        item->next = DAT_011c5f58;
        DAT_011c5f58 = item;
        DAT_011c5f80.Unlock();
    }
};
struct ParsedList {
    ParsedNode* head;
    ParsedNode* tail;
    ParsedAllocator allocator;
    __forceinline void* GetTailPosition() const { return tail; }
    __forceinline ParsedToken*& GetPrevious(void*& position) {
        ParsedToken*& element = static_cast<ParsedNode*>(position)->value;
        position = static_cast<ParsedNode*>(position)->previous;
        return element;
    }
    ParsedToken* PopFront() {
        ParsedNode* node = tail;
        tail = tail->previous;
        if (tail) tail->next = 0;
        else head = 0;
        ParsedToken* element = node->value;
        node->value = 0;
        allocator.FUN_0045cee0(node);
        --allocator.count;
        return element;
    }
    void FUN_00a11db0(ParsedNode* node) {
        node->next = 0;
        node->previous = tail;
        if (tail) tail->next = node;
        else head = node;
        tail = node;
        ++allocator.count;
    }
    inline ParsedNode* NewItem() { return allocator.FUN_0043a010(); }
    __forceinline void Append(ParsedToken* const& token) {
        ParsedNode* node = NewItem();
        node->value = token;
        FUN_00a11db0(node);
    }
};
struct ParsedParent {
    unsigned unk00, unk04, unk08;
    void* templateData;
    void* FindTemplateByName(const char*);
    void* FUN_00a0ae70(const char*);
    __forceinline void SetTileTemplate(void* value) {
        templateData = value;
    }
};
struct ParsedBuilder {
    unsigned unk00;
    ParsedParent* parent;
    ParsedList tokens;
    void FUN_00a0a410(int, const char*, void*, bool);
};
int TraitNameToID(const char*);
int TraitNameToIDAdd(const char*, int);
ParsedToken* FUN_00a0b950(int, float, const char*, int, void*);


void FUN_00a0b8d0(ParsedToken* token) {
    if ((unsigned int)DAT_011f32dc < 10) ((ParsedToken**)DAT_011f329c)[DAT_011f32dc++] = token;
    else delete token;
}
void FUN_005b5e40(const char*, ...);
extern float DAT_01094cf4;

// @fnv 0x00a0a410
void ParsedBuilder::FUN_00a0a410(int trait, const char* text, void* context, bool literal) {
    float value = DAT_01094cf4;
    if (!literal)
        value = (float)TraitNameToID(text);
    if (value == DAT_01094ba8 && (text[0] == '_' || (text[0] == '&' && text[1] == '_')))
        value = (float)TraitNameToIDAdd(text, -1);
    ParsedToken* createdToken16 = FUN_00a0b950(trait, value, text, (int)value, context);
    bool isNumericX = true;
    for (unsigned i = 0; i < strlen(text); ++i) {
        if ((text[i] < '0' || text[i] > '9') && text[i] != '-' && text[i] != '.') {
            isNumericX = false;
            break;
        }
    }
    if (isNumericX) {
        if (value == DAT_01094ba8)
            sscanf(text, DAT_01094cf0, &value);
        if (value == DAT_01012060)
            sscanf(text, DAT_01094cf0, &value);
        createdToken16->text = DAT_01011584;
        createdToken16->value = value;
        createdToken16->integer = (int)value;
    }
    void* iteratorPosition8 = tokens.GetTailPosition();
    ParsedToken* lastToken15 = 0;
    ParsedToken* previousToken2 = 0;
    ParsedToken* thirdToken12 = 0;
    if (iteratorPosition8) lastToken15 = tokens.GetPrevious(iteratorPosition8);
    if (iteratorPosition8) previousToken2 = tokens.GetPrevious(iteratorPosition8);
    if (iteratorPosition8) thirdToken12 = tokens.GetPrevious(iteratorPosition8);
    if (trait == 3002 && lastToken15 && lastToken15->kind == 0 && lastToken15->value == DAT_01094ce8) {
        if (parent->templateData) {
            FUN_005b5e40(DAT_01094ca8);
        } else {
            parent->SetTileTemplate(parent->FindTemplateByName(text));
            if (!parent->templateData) {
                parent->SetTileTemplate(parent->FUN_00a0ae70(text));
            }
        }
        FUN_00a0b8d0(tokens.PopFront());
        FUN_00a0b8d0(createdToken16);
    } else if (trait == 1 && value == DAT_01094ce8 && parent->templateData) {
        parent->SetTileTemplate(0);
        FUN_00a0b8d0(createdToken16);
    } else if (trait == 3002 && lastToken15 && lastToken15->kind == 0 &&
               lastToken15->value >= DAT_01094ca0 && lastToken15->value <= DAT_01094c98) {
        lastToken15->kind = 6;
        lastToken15->text = text;
        FUN_00a0b8d0(createdToken16);
    } else if (trait == 3002) {
        createdToken16->kind = 8;
        createdToken16->integer = 3002;
        tokens.Append(createdToken16);
    } else if (trait == 1 && lastToken15 && lastToken15->kind == 3001 && previousToken2 &&
               (previousToken2->kind == 4 || previousToken2->kind == 2) && previousToken2->value == value) {
        if ((createdToken16->value >= DAT_01094c90 && createdToken16->value <= DAT_01094c88) || createdToken16->integer >= 10000)
            previousToken2->kind = 8;
        else if (createdToken16->value >= DAT_01073490 && createdToken16->value <= DAT_01094c80)
            previousToken2->kind = 9;
        else {
            previousToken2->kind = -1;
            FUN_005b5e40(DAT_01094c58);
        }
        previousToken2->integer = (int)previousToken2->value;
        previousToken2->value = lastToken15->value;
        previousToken2->text = lastToken15->text;
        FUN_00a0b8d0(tokens.PopFront());
        FUN_00a0b8d0(createdToken16);
    } else if (trait == 1 && lastToken15 && lastToken15->kind == 3004 && previousToken2 &&
               previousToken2->kind == 3003 && thirdToken12 && thirdToken12->kind == 2 && thirdToken12->value == value) {
        thirdToken12->kind = 10;
        thirdToken12->integer = (int)thirdToken12->value;
        thirdToken12->value = lastToken15->value;
        thirdToken12->text = previousToken2->text;
        FUN_00a0b8d0(tokens.PopFront());
        FUN_00a0b8d0(tokens.PopFront());
        FUN_00a0b8d0(createdToken16);
    } else {
        if ((createdToken16->integer >= 4001 && createdToken16->integer <= 4125) || createdToken16->integer >= 10000) {
            if (createdToken16->kind == 0)
                createdToken16->kind = 4;
            else if (createdToken16->kind == 1)
                createdToken16->kind = 5;
        } else if (createdToken16->integer >= 2000 && createdToken16->integer <= 2025) {
            if (createdToken16->kind == 0)
                createdToken16->kind = 2;
            else if (createdToken16->kind == 1 && lastToken15)
                createdToken16->kind = 3;
        } else if (createdToken16->kind == 1 && createdToken16->value >= DAT_01094ca0 && createdToken16->value <= DAT_01094c98) {
            createdToken16->kind = 7;
        }
        tokens.Append(createdToken16);
    }
}
}  // namespace fnv_00a0a410

namespace tile_path_resolver {

struct UITile;

typedef ::NiTListItem<UITile*> TileItem;
typedef ::NiTListBase< ::NiTPointerAllocator<unsigned int>, UITile*> TileChildren;

struct TileMenuRoot {
    int unk00;
    UITile* m_pkTile;
    __forceinline UITile* GetTile() { return m_pkTile; }
};

struct UITile {
    int unk00;
    TileChildren m_kChildList;
    ::NiTObjectArray< ::Tile::Value*> m_kValues;
    ::BSStringT<char> m_kName;
    UITile* m_pParentNode;

    __forceinline UITile* GetParent() const { return m_pParentNode; }
    __forceinline unsigned int GetChildCount() const { return m_kChildList.m_kItemCount.m_uiCount; }
    __forceinline TileItem* GetHeadPos() const { return m_kChildList.m_pkHead; }
    __forceinline UITile*& GetNext(TileItem*& pos) {
        UITile*& element = pos->m_element;
        pos = pos->m_pkNext;
        return element;
    }
    __forceinline const char* GetName() const { return m_kName.pString; }
    TileMenuRoot* FUN_00a03c90();
    UITile* FUN_00a03d40();
    UITile* FUN_00a03da0(const char* pcName);
};

enum { TilePathLayout = 1 / (sizeof(UITile) == 0x2c) };
enum { TileChildrenLayout = 1 / (sizeof(TileChildren) == 0xc) };

int ParseTextAndParams(const char* pcPath, char* pcName);
int FUN_00ec68e4(const char* pcA, const char* pcB);
UITile* FUN_00706cd0();
UITile* FUN_00706cf0();
UITile* FindTileByName(UITile* pkRoot, const char* pcPath);

// @fnv 0x00a08b20
UITile* FUN_00a08b20(UITile* pTile, const char* pcPath)
{
    UITile* pResultTmp = 0;
    int m_iValueId;
    {
    char acName[0x800];
    acName[0] = 0;
    m_iValueId = ParseTextAndParams(pcPath, acName);

    switch (m_iValueId)
    {
    case 0x1391:
        return pTile->GetParent() ? pTile->GetParent()->GetParent() : 0;
    case 0x1389:
        return pTile->GetParent();
    case 0x138a:
        return pTile;
    case 0x1390:
        return pTile->FUN_00a03c90()->GetTile();
    case 0x138c:
        if (!acName[0] && pTile->GetParent()->GetChildCount())
        {
            TileItem* kPos = pTile->GetParent()->GetHeadPos();
            while (kPos)
            {
                if (pTile->GetParent()->GetNext(kPos) == pTile)
                    break;
            }
            if (kPos)
                return pTile->GetParent()->GetNext(kPos);
            else
                return pTile->GetParent()->m_kChildList.m_pkHead->m_element;
        }
        else if (acName[0] && pTile->GetParent()->GetChildCount())
        {
            TileItem* kPos2 = pTile->GetParent()->GetHeadPos();
            while (kPos2)
            {
                UITile* pChild = pTile->GetParent()->GetNext(kPos2);
                if (pChild->GetName() && !FUN_00ec68e4(pChild->GetName(), acName))
                {
                    pResultTmp = pChild;
                    break;
                }
            }
            return pResultTmp;
        }
        else
            return 0;
    case 0x138d:
        if (!acName[0] && pTile->GetChildCount())
            return pTile->m_kChildList.m_pkHead->m_element;
        else if (pTile && acName[0] && pTile->GetChildCount())
            return pTile->FUN_00a03da0(acName);
        else
            return 0;
    case 0x138e:
        return FUN_00706cd0();
    case 0x138f:
        return FUN_00706cf0();
    default:
        if (pTile)
            pResultTmp = FindTileByName(pTile->FUN_00a03d40(), pcPath);
        else
            pResultTmp = FindTileByName(FUN_00706cd0(), pcPath);
        return pResultTmp;
    }
    }
}

}

__declspec(dllimport) unsigned long __stdcall GetTickCount();
extern "C" double __cdecl fabs(double);

class NiAVObject;
struct FadeTile {
    virtual void V0(); virtual void V1(); virtual void V2(); virtual int GetType();
    int field04; int field08; int field0c; int field10; int field14; int field18; int field1c;
    int field20; int field24; FadeTile* parent; NiAVObject* model;
    float FUN_00a011b0(int);
    void FUN_00a012d0(int,float,bool);
    void FUN_00a08720(NiAVObject*,float);
};
struct FadePtr { FadeTile* ptr; inline FadeTile* operator->() const { return ptr; } };
struct FadeRecord {
    float start; float end; unsigned int time; float duration; int trait; FadeTile* tile; unsigned int type;
};
struct LocalManager { void Deallocate(void*); void* Allocate(unsigned int); };
extern LocalManager g_memoryManager;
struct FadeList {
    FadeRecord* item; FadeList* next;
    static void operator delete(void* p) { g_memoryManager.Deallocate(p); }
    ~FadeList() { RemoveAll(); }
    inline void RemoveAll() { while (next) { FadeList* after=next->next; next->next=0; delete next; next=after; } item=0; }
    inline void FUN_00a0cbe0(FadeRecord*& p) {
        if (!p || (!next && !item)) return;
        FadeList* cur=this; FadeList* prev=this;
        while(cur && cur->item != p) { prev=cur; cur=cur->next; }
        if(!cur) return;
        if(cur==this) { if(next) { prev=next; next=prev->next; item=prev->item; prev->next=0; delete prev; } else item=0; }
        else { prev->next=cur->next; cur->next=0; delete cur; }
    }
};
extern FadeList DAT_011f3348;
int __cdecl TraitNameToID(const char*);
struct FUN_00ae83e0 {
    FadeRecord* item; FUN_00ae83e0* next;
    static void* operator new(unsigned int size) {return g_memoryManager.Allocate(size);}
    static void operator delete(void* p) {g_memoryManager.Deallocate(p);}
    ~FUN_00ae83e0();
    inline void RemoveAll() { while (next) { FUN_00ae83e0* after=next->next; next->next=0; delete next; next=after; } item=0; }
    inline void AddToHead(FadeRecord*& p) {
        if (!p) return;
        if (item) { FUN_00ae83e0* fresh = new FUN_00ae83e0; FUN_00ae83e0* node=fresh; node->item=item; node->next=0; node->next=next; next=node; }
        item=p;
    }

};
typedef FUN_00ae83e0 FadePending;
struct FadePendingClear { void FUN_00ae83e0(); };
extern const float DAT_01094c18;
extern const float DAT_01094c0c;
extern const double DAT_01011590;
inline NiAVObject* modelOf(FadeTile* tile) { NiAVObject* model=tile->model; return model; }
inline unsigned tick() { unsigned time=GetTickCount(); return time; }
inline float minFloat(float a, float b) { return a < b ? a : b; }
inline float linear(float x, float x0, float x1, float y0, float y1) { return ((x-x0)/(x1-x0)) * (y1-y0) + y0; }
// @fnv 0x00a080d0
void __cdecl FUN_00a080d0()
{
    if ((unsigned char)((DAT_011f3348.next == 0 && DAT_011f3348.item == 0) ? 1 : 0)) return;
    float fraction5;
    FadeList* list6 = reinterpret_cast<FadeList*>(&DAT_011f3348);
    FadePending local2 = {0,0};
    FadeList* local1;
    float start13, local11, count1, total5, valueA9, valueB6, blend;
    int trait2;
    unsigned int type2;
    FadePending* pending3;
    FadeRecord* item;
    FadeRecord* local18;
    for (local1 = reinterpret_cast<FadeList*>(&DAT_011f3348); local1 && local1->item; local1=local1->next) {
        local11 = local1->item->end;
        start13 = local1->item->start;
        trait2 = local1->item->trait;
        switch (local1->item->type) {
        case 0: {
            fraction5 = (tick()-local1->item->time)/local1->item->duration;
            fraction5 = minFloat(fraction5, 1.0f);
            if (static_cast<FadeTile* volatile&>(local1->item->tile)->GetType() == 0x388 && trait2 == 0xfa9) {
                local1->item->tile->FUN_00a08720(modelOf(local1->item->tile),(start13+(local11-start13)*fraction5)/255.0);
            }
            local1->item->tile->FUN_00a012d0(trait2,start13+(local11-start13)*fraction5,true);
            if (fraction5 >= 1.0) local2.AddToHead(local1->item);
            break;
        }
        case 1: case 2: case 3: {
            type2 = local1->item->type;
            count1 = local1->item->tile->FUN_00a011b0(TraitNameToID("_FlashCount"));
            total5 = local1->item->tile->FUN_00a011b0(TraitNameToID("_TotalFlashCount"));
            fraction5 = (tick()-local1->item->time)/local1->item->duration;
            if (fraction5 >= 1.0) {
                if ((type2==2 && count1 < 3.0) || (type2==3 && count1 < total5) || type2==1) {
                    local1->item->time=tick();
                    fraction5=0.0f;
                }
                if (type2==2 || type2==3) {
                    local1->item->tile->FUN_00a012d0(TraitNameToID("_FlashCount"),count1+1.0,true);
                    if (type2==2 && count1 > 3.0) local1->item->tile->FUN_00a012d0(trait2,local11,true);
                    else if (type2==3 && count1>total5) {
                        local1->item->tile->FUN_00a012d0(trait2,start13,true);
                        local2.AddToHead(local1->item);
                    }
                }
            }
            if (type2==2 && count1 >= 3.0) {
                valueA9 = start13+(local11-start13)*fraction5;
                local1->item->tile->FUN_00a012d0(trait2,valueA9 > local11 ? local11:valueA9,true);
                if (valueA9 >= local11) local2.AddToHead(local1->item);
            } else {
                blend = 1.0f-(float)fabs((double)(float)(fraction5*DAT_01011590-1.0));
                valueB6 = start13+(local11-start13)*blend;
                local1->item->tile->FUN_00a012d0(trait2,valueB6,true);
            }
            break;
        }
        case 4: {
            fraction5=(tick()-local1->item->time)/local1->item->duration;
            if (fraction5 < 0.16665999591350555) {
                local1->item->tile->FUN_00a012d0(trait2,linear(fraction5,0.0f,DAT_01094c18,start13,local11),true);
            } else if (fraction5 < 0.8333399891853333) {
                local1->item->tile->FUN_00a012d0(trait2,local11,true);
            } else if (fraction5 >= 1.0) {
                local1->item->tile->FUN_00a012d0(trait2,start13,true);
                local2.AddToHead(local1->item);
            } else {
                local1->item->tile->FUN_00a012d0(trait2,linear(fraction5,DAT_01094c0c,1.0f,local11,start13),true);
            }
            break;
        }
        }
    }
    for (pending3=&local2; pending3 && pending3->item; pending3=pending3->next) {
        item=pending3->item;
        reinterpret_cast<FadeList*>(&DAT_011f3348)->FUN_00a0cbe0(item);
        local18=item;
        g_memoryManager.Deallocate(local18);
    }
    local2.RemoveAll();
}

// 1 Nov: fnv_FloatToInt / fnv_SinCos for functions added below (0x00a033b0, contributor flag). Included last: an include above
// the accepted functions renumbers their string literals ($SG...), which the manifest binds.
#include "fnv_asm_helpers.h"

namespace fnv_00a033b0 {
extern double DAT_01094ba8;

extern const char str_01094b78[];

extern const char str_01094b4c[];

extern const char str_01094b18[];

extern const char str_01094aec[];

extern const char str_01094ac0[];

typedef unsigned short R_u16;

typedef unsigned int R_u32;



extern "C" unsigned strlen(const char*);
inline unsigned FUN_0044a670(const char* s){return strlen(s);}
struct R_Str {

    char* pString;

    R_u16 sLen;

    R_u16 sMaxLen;

    inline unsigned FUN_004048e0() const {return sLen==65535?FUN_0044a670(pString):sLen;}
    inline const char* FUN_00559450() const {return pString;}

};



struct R_Val {

    int trait;

    float fvalue;

    R_Str str;

    int m10;

    void* context;

};



struct R_Act { R_Act* next; R_Act* prev; R_Val* data; };



struct R_Menu {

    int unk00; int unk04;

    R_Act* acts;

};



struct R_Tile;

struct R_SetF { void FUN_00a012d0(int, float, bool); };

struct R_SetS { void FUN_00a01350(int, const char*, bool); };

struct R_ValOwner { R_Val* GetOrCreateTraitValue(int); };

struct R_P03 { void AppendFloatAction(int, float); };

struct R_P09 { void FUN_00a09130(int, void*, int); };

struct R_P04 { void Refresh(bool); };

struct R_P08 { void FUN_00a07530(int); };

struct R_HeapManager : FUN_00a0d220_pool { void* FUN_00aa3e40(unsigned); };
inline R_HeapManager* FUN_00401020(){return static_cast<R_HeapManager*>(&DAT_011f6238);}
inline void* FormHeap_Allocate(unsigned n){return FUN_00401020()->FUN_00aa3e40(n);}
inline void FormHeap_Free(void*p){FUN_00401020()->FUN_00aa4060(p);}
inline void* FUN_00401460(void*dst,const void*src,unsigned n){return memcpy(dst,src,n);}
extern "C" unsigned strlen(const char*);

struct R_SH {

    char* pString; unsigned short sLen, sMaxLen;

    inline unsigned FUN_004039a0() const {return sMaxLen;}
    inline void FUN_00403a00(unsigned value) {sMaxLen=value<=65535?(unsigned short)value:65535;}
    inline void FUN_004039c0(unsigned value) {sLen=value<=65535?(unsigned short)value:65535;}
    inline bool FUN_00438470(const R_Str& src) {
        unsigned len=src.FUN_004048e0();
        char* old;
        if(len<=FUN_004039a0()) {
            if(len)FUN_00401460(pString,src.FUN_00559450(),len+1);
            else {
                if(pString){char* deleted=pString;FormHeap_Free(deleted);}
                pString=0;len=0;FUN_00403a00(len);
            }
        } else {
            old=pString;
            char* allocated=(char*)FormHeap_Allocate(len+1);
            pString=allocated;
            FUN_00401460(pString,src.FUN_00559450(),len+1);
            if(old){char* deletedOld=old;FormHeap_Free(deletedOld);}
            FUN_00403a00(len);
        }
        FUN_004039c0(len);
        return len!=0;
    }

    inline R_SH& operator=(const R_Str& src){FUN_00438470(src);return *this;}

};

struct R_Vt4 { virtual void v0(); virtual void v1(); virtual void v2(); virtual int v3(); };



struct R_Tile {

    void** vtbl;

    int unk04; int unk08; int unk0c; int unk10;

    R_Val** parr;

    R_u32 count;

    int unk1c;

    R_Str str20;

    R_Tile* next28;

    int unk2c;

    R_u32 flags30;

};











extern "C" unsigned int strlen(const char* s);

extern void FNV_Warning(const char* fmt, ...);

extern void* FUN_00a08b20(R_Tile* t, const char* name);



class C00a033b0 {

public:

    void FUN_00a033b0(R_Menu* a1);

};



// @fnv 0x00a033b0
void C00a033b0::FUN_00a033b0(R_Menu* a1)

{

    R_Tile* aw = 0;        // first tile

    R_Tile* ad = 0;        // current tile

    int aa = 0;            // current value index

    R_Val* ao;             // current value

    R_Act* ah;             // list head

    R_Act* af;               // list cursor

    unsigned an;           // loop counter

    int* aj;               // link result

    ah = (R_Act*)a1->acts;

    af = ah;

    ao = 0;

    while (af)

    {

        R_Val** Str = &af->data;

        af = af->next;

        ao = *Str;

        if (ao->trait == 6)

        {

            ad = (R_Tile*)ao->m10;

            if (!aw)

                aw = ad;

            ((R_P08*)ad)->FUN_00a07530(0x10000);

        }

        else if (ao->trait == 7)

        {

            unsigned n;

            if (ad->flags30 & 0x10000)

                ad->flags30 ^= 0x10000;

            EnterCriticalSection(reinterpret_cast<_RTL_CRITICAL_SECTION*>(&DAT_011f3330));

            for (an = 0; an < (n = ad->count); an++)

            {

                if (ad->parr[an]->trait != 4004)

                    ((R_P04*)ad->parr[an])->Refresh(true);

            }

            LeaveCriticalSection(reinterpret_cast<_RTL_CRITICAL_SECTION*>(&DAT_011f3330));

            ad = ad->next28;

        }

        else if (ao->trait == 8)

        {

            R_Str* t3;

            const char* ax;

            if (ad)

            {

              if (!((ao->fvalue == DAT_01094ba8

                      && (((t3 = &ao->str)->sLen == 0xffff

                           ? strlen(ax = t3->pString)

                           : (unsigned int)t3->sLen) != 0))

                     || ao->m10 == 0xfc4

                     || ao->m10 == 0xfcc))

            {

                ((R_SetF*)ad)->FUN_00a012d0(ao->m10, ao->fvalue, true);

            }

            else

            {

                if (ao->m10 == 0xbba)

                {

                    *reinterpret_cast<R_SH*>(&ad->str20)=ao->str;

                }

                else if (ao->m10 == 0xfcc && ((R_Vt4*)ad)->v3() == 0x386)

                {

                    ((R_SetS*)ad)->FUN_00a01350(ao->m10, ao->str.FUN_00559450(), true);

                    ((R_P08*)ad)->FUN_00a07530(0x20);

                }

                else

                {

                    ((R_SetS*)ad)->FUN_00a01350(ao->m10, ao->str.FUN_00559450(), true);

                }

            }

            }

            else

            {

                FNV_Warning(str_01094b78);

            }

        }

        else if (ao->trait == 4)

        {

            aa = (int)ao->fvalue;

        }

        else if (ao->trait == 5)

        {

            aa = 0;

        }

        else if (ao->trait == 9)

        {

            if (aa)

                ((R_P03*)((R_ValOwner*)ad)->GetOrCreateTraitValue(aa))->AppendFloatAction(ao->m10, ao->fvalue);

            else

                FNV_Warning(str_01094b4c);

        }

        else if (ao->trait == 0xA)

        {

            if (aa)

            {

                aj = (int*)FUN_00a08b20(ad, ao->str.FUN_00559450());

                if (aj)

                {

                    ((R_P09*)((R_ValOwner*)ad)->GetOrCreateTraitValue(aa))->FUN_00a09130(ao->m10, aj, fnv_FloatToInt(ao->fvalue));

                }

            }

            else

                FNV_Warning(str_01094b18);

        }

        else if (ao->trait == 2)

        {

            if (aa)

            {

                ((R_P03*)((R_ValOwner*)ad)->GetOrCreateTraitValue(aa))->AppendFloatAction(2024, (float)fnv_FloatToInt(ao->fvalue));

            }

            else

                FNV_Warning(str_01094aec);

        }

        else if (ao->trait == 3)

        {

            if (aa)

            {

                ((R_P03*)((R_ValOwner*)ad)->GetOrCreateTraitValue(aa))->AppendFloatAction(2025, (float)fnv_FloatToInt(ao->fvalue));

            }

            else

                FNV_Warning(str_01094ac0);

        }

    }

}
}  // namespace fnv_00a033b0

__declspec(dllimport) void __stdcall EnterCriticalSection(void*);
__declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
int __cdecl FUN_00ec6da0(const char*,const char*);
struct RenderAtlasSetting { int unk00; const char* pValue; __forceinline const char* GetValue() { return this ? pValue : 0; } };
extern RenderAtlasSetting g_011f3368;
__declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
__declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct RenderTLS { int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc; int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c; int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c; int unk240; int unk244; int unk248; int unk24c; int unk250; int unk254; int unk258; int unk25c; int unk260; int unk264; int unk268; int unk26c; int unk270; int unk274; int unk278; int unk27c; int unk280; int unk284; int unk288; int unk28c; int unk290; int unk294; int unk298; int unk29c; int unk2a0; int unk2a4; int unk2a8; int unk2ac; int unk2b0; int heapIndex; };
extern __declspec(thread) RenderTLS renderTLS;
struct RenderHeapScope {
    int saved;
    __forceinline RenderHeapScope() { { int current = renderTLS.heapIndex; saved = current; } renderTLS.heapIndex = 13; }
    __forceinline ~RenderHeapScope() { int restore = saved; renderTLS.heapIndex = restore; }
};
struct RenderPoint2 { float x,y; __forceinline RenderPoint2(float a,float b):x(a),y(b){} };
struct RenderPoint3 {
    float x,y,z;
    __forceinline RenderPoint3() {}
    __forceinline RenderPoint3(float a,float b,float c):x(a),y(b),z(c){}
    RenderPoint3 operator+(const RenderPoint3&) const;
    RenderPoint3 operator-(const RenderPoint3&) const;
};
__forceinline void RenderSinCos(float angle,float& sine2,float& cosine2) {
    fnv_SinCos(angle,sine2,cosine2);
}

struct RenderMatrix { float xx,xy,xz,yx,yy,yz,zx,zy,zz;
    RenderPoint3 operator*(const RenderPoint3& point) const {
        RenderPoint3 product;
        product.x=xx*point.x+xy*point.y+xz*point.z;
        product.y=yx*point.x+yy*point.y+yz*point.z;
        product.z=zx*point.x+zy*point.y+zz*point.z;
        return product;
    }
    __forceinline void SetRotation(float angle) {
        float sine2,cosine2; RenderSinCos(angle,sine2,cosine2);
        xx=cosine2; xy=0.0f; xz=-sine2;
        yx=0.0f; yy=1.0f; yz=0.0f;
        zx=sine2; zy=0.0f; zz=cosine2;
    }
};
struct RenderRect { float left,right,top,bottom; __forceinline RenderRect():left(0),right(0),top(0),bottom(0){} };
struct RenderColor { float r,g,b,a; void Scale(float); };
struct RenderRTTI { void* name; RenderRTTI* parent; };
extern RenderRTTI renderTriShapeRTTI;
struct RenderTexture {
    virtual void v0(); virtual void Destroy();
    long refs;
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
    virtual unsigned int Width(); virtual unsigned int Height();
    __forceinline void IncRefCount() { InterlockedIncrement(&refs); }
    __forceinline void DecRefCount() { if (!InterlockedDecrement(&refs)) Destroy(); }
};
struct RenderPtr {
    RenderTexture* object;
    __forceinline RenderPtr(RenderTexture* p=0) { object=p; if(object) object->IncRefCount(); }
    __forceinline RenderPtr(const RenderPtr& p) { object=p.object; if(object) object->IncRefCount(); }
    __forceinline ~RenderPtr() { if(object) object->DecRefCount(); }
    __forceinline operator RenderTexture*() const { return object; }
    __forceinline RenderTexture* operator->() const { return object; }
};
struct RenderString { char* text; unsigned short len,maxLen; RenderString(const char*); bool Set(const char*,unsigned int); __forceinline ~RenderString(){ Set(0,0); } __forceinline const char* String() const { return text; } };
struct RenderShader {
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; RenderPtr texture;
    int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int textureMode;
    int unk090; int unk094; int unk098;
    struct ClipRect { int left,top,right,bottom; } clip;
    void SetTexture(RenderTexture*);
    void SetClipping(bool);
    __forceinline RenderTexture* Texture() { RenderTexture* result=texture; return result; }
};
struct RenderData {
    int unk000,unk004; unsigned short vertexCount,unk00a,unk00c,flags;
    struct Bound { void Recalculate(unsigned short,RenderPoint3*); } bound;
    int unk014,unk018,unk01c;
    RenderPoint3* vertices; int unk024,unk028; RenderPoint2* uvs;
    void SetFlags(int); void Update(bool);
    __forceinline RenderPoint3* Vertices() { RenderPoint3* points=vertices; return points; }
    __forceinline RenderPoint2* UVs() { RenderPoint2* points=uvs; return points; }
    __forceinline unsigned short VertexCount() { return vertexCount; }
};
struct RenderObject;
struct RenderObjectRef {
    RenderObject* object;
    RenderObjectRef(RenderObject* value=0);
    ~RenderObjectRef();
    bool operator!=(const RenderObjectRef&) const;
    RenderObjectRef& operator=(const RenderObjectRef&);
};
RenderObjectRef* RenderAllocateChildren(unsigned int);
void RenderFreeChildren(RenderObjectRef*);
struct RenderObject {
    virtual void v0(); virtual void v1(); virtual RenderRTTI* GetRTTI(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual RenderObject* AsGeometry(); virtual void v8(); virtual RenderObject* AsNode();
    int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; unsigned int flags;
    RenderMatrix rotation; RenderPoint3 translation;
    int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098;
    struct Children {
        void* vtable; RenderObjectRef* buffer; unsigned short capacity,size,end,grow;
        void Begin() {
            if(end==size) return;
            unsigned short index;
            if(end) {
                unsigned short output=0;
                for(index=0;index<size;++index) {
                    if(buffer[index]!=RenderObjectRef(0)) {
                        if(buffer[output]!=buffer[index]) buffer[output]=buffer[index];
                        ++output;
                    }
                }
            }
            RenderObjectRef* old=buffer;
            size=end; capacity=size;
            if(capacity>0) {
                buffer=RenderAllocateChildren(capacity);
                for(index=0;index<size;++index) buffer[index]=old[index];
            } else buffer=0;
            RenderFreeChildren(old);
        }
        void End() {
            while(size>0) {
                if(buffer[size-1]!=RenderObjectRef(0)) break;
                --size;
            }
        }
        __forceinline RenderObject* At(unsigned int idx) {
            RenderObjectRef* slot=buffer+idx; RenderObject* item=slot->object; return item;
        }
    } children;
    int unk0ac; int unk0b0; int unk0b4; RenderData* data;
    __forceinline void Transform(const RenderMatrix& matrix,const RenderPoint3& position,const RenderPoint3& center) {
        rotation=matrix; translation=RenderPoint3((position+center)-(matrix*center));
    }
    __forceinline void PrepareChildren() { children.Begin(); children.End(); }
    __forceinline RenderObject* GetAt(unsigned int idx) { return children.At(idx); }
    RenderShader* GetProperty(unsigned int);
    __forceinline RenderData* Data() { RenderData* result=data; return result; }
    __forceinline unsigned int ChildCount() { return children.end; }
    __forceinline RenderObject* GetChild(unsigned int idx) { if (children.size <= idx) return 0; else return children.At(idx); }
    __forceinline bool Hidden() { return (flags & 1)!=0; }
    __forceinline void SetHidden(bool value, unsigned int bit=1) { if (value) flags |= bit; else flags &= ~bit; }
};
__forceinline bool RenderHasType(RenderRTTI* type) {
    while(type) {
        if(type==&renderTriShapeRTTI) return true;
        type=type->parent;
    }
    return false;
}
__forceinline RenderObject* RenderAsShape(RenderObject* object) {
    if(!object) return 0;
    return RenderHasType(object->GetRTTI()) ? object : 0;
}
__forceinline float RenderMaximum(float a,float b) { return b > a ? b : a; }
__forceinline float RenderMinimum(float a,float b) { return a < b ? a : b; }
struct RenderValue { int trait; void* owner; float value; char* string; void* extra; };
struct RenderTile {
    virtual void v0(); virtual void v1(); virtual void* HasModel(); virtual int Type();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void SetColor(RenderObject*,float,RenderColor*);
    int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; const char* name; int unk024;
    RenderTile* parent; RenderObject* model; unsigned int flags;
    unsigned char unk034; bool speechFailure; unsigned short unk036;
    float textureScale; RenderPtr cachedTexture;
    float GetFloat(int); bool GetBool(int); RenderValue* GetValue(int); char* GetString(int);
    void Set(int,const char*,bool); void Set(int,float,bool); bool IsVisible();
    void FUN_00a08a20(); void SetImageFlags(int); void UpdateChildrenPosition(); void Update3D();
    bool IsRenderedMenu(); void* GetMenu(); float PositionX(); float PositionY();
    void SetBounds(float,float,float,float);
    __forceinline RenderObject* Model() { RenderObject* result=model; return result; }
    __forceinline bool Flag(unsigned int bit) { return (flags & bit)!=0; }
    __forceinline float TextureScale() { float scale=textureScale; return scale; }
    __forceinline RenderPoint3 Center() {
        float x=GetFloat(0xffb); float y=-GetFloat(0xffc);
        return RenderPoint3(x,0.0f,y);
    }
    __forceinline void UpdateText() { RenderTile* text=this; text->Update3D(); }
    __forceinline RenderTile* Parent() { RenderTile* result=parent; return result; }
    __forceinline bool SpeechFailure() { bool result=speechFailure; return result; }
    __forceinline const char* Name() { const char* result=name; return result; }
    bool FUN_00a04640(bool clear);
};
extern bool renderVisibilityChanged;
extern int renderUpdateCount;
bool RenderResetTextures(); void RenderTextChanged(bool); void RenderQueue(RenderTile*);
RenderTile* RenderRoot(); float RenderScreenWidth(); float RenderScreenHeight();
float RenderTargetWidth(); float RenderTargetHeight(); float RenderMenuWidth(); float RenderMenuHeight();
float RenderAspect(); bool RenderWideMenu(void*);
void RenderParseAtlas(const char*,const char*,RenderString*,RenderRect*);
void RenderLoadTexture(const char*,float*,RenderPtr*,float,RenderPtr);
struct RenderColorManager { bool GetColor(int,RenderColor&); static RenderColorManager* GetSingleton(); };
extern RenderPoint3 renderZero;
extern const double renderDepthScale;
extern float renderSpeechRed;
extern const char renderDefaultTexture[];
extern const char renderEmpty[];
extern const char renderHighlight[];
extern const char* volatile renderDefaultAtlas;

// @fnv 0x00a04640
bool RenderTile::FUN_00a04640(bool clear) {
    EnterCriticalSection(&DAT_011f3330);
    bool changed=false;
    bool imageB;
    bool dynamicGeometry;
    if (flags & 0x3ff) {
        RenderHeapScope var1C;
        if (flags & 2) {
            FUN_00a08a20();
            if (HasModel()) {
                if (Type()==0x387) RenderTextChanged(true);
                changed=true;
                if(clear && (flags & 2)) flags ^= 2;
            }
        }
        if ((flags & 4) && Model()) {
            bool oldHiddenTmp=Model()->Hidden();
            Model()->SetHidden(GetFloat(0xfa3)==0.0);
            changed=true;
            if(oldHiddenTmp && oldHiddenTmp!=Model()->Hidden()) renderVisibilityChanged=true;
            if(clear && (flags & 4)) flags ^= 4;
        }
        if (RenderResetTextures() && Model()) {
            RenderObject* childVal5=Model()->GetChild(0);
            if(Type()==0x386 && childVal5) {
                RenderShader* var28=childVal5->GetProperty(3);
                if(var28) { var28->SetTexture(0); SetImageFlags(0x20); }
            }
        }
        imageB=(Type()==0x386 || Type()==0x38a);
        RenderRect sheet_2;
        sheet_2.bottom=-1.0f; sheet_2.left=-1.0f; sheet_2.right=-1.0f; sheet_2.top=-1.0f;
        if (imageB && (flags & 0x20) && Model()) {
            RenderObject* varE9=Model()->GetChild(0);
            if (imageB && varE9 && (Flag(0x1000) || IsVisible())) {
                RenderShader* varF9=varE9->GetProperty(3);
                if (varF9) {
                    RenderTile* tileA=this;
                    RenderPtr textureCheck9;
                    RenderValue* valueX2=GetValue(0xfcc);
                    void* extra11=0;
                    const char* var6c9=0;
                    bool fallbackX=false;
                    if(valueX2) { extra11=valueX2->extra; var6c9=valueX2->string; }
                    if((!var6c9 || !*var6c9) && !extra11) {
                        Set(0xfcc,"Interface\\Shared\\empty.dds",true);
                        var6c9=GetString(0xfcc);
                        fallbackX=true;
                    }
                    if(var6c9 && *var6c9) {
                        if(fallbackX || GetValue(0xff9)) {
                            RenderString resolved4("");
                            const char* sheetName_=fallbackX ? g_011f3368.GetValue() : GetString(0xff9);
                            RenderParseAtlas(sheetName_,GetString(0xfcc),&resolved4,&sheet_2);
                            RenderLoadTexture(resolved4.String(),&tileA->textureScale,&textureCheck9,tileA->GetFloat(0xfb8),tileA->cachedTexture);
                        }
                        if(!textureCheck9) {
                            RenderLoadTexture(var6c9,&tileA->textureScale,&textureCheck9,tileA->GetFloat(0xfb8),tileA->cachedTexture);
                        }
                    }
                    if(textureCheck9) {
                        varF9->SetTexture(textureCheck9);
                        if(GetBool(0xfb5)) varF9->textureMode=2; else varF9->textureMode=0;
                        float var4=GetFloat(0xfb8);
                        const char* pathY=GetString(0xfcc);
                        float width2=(float)textureCheck9->Width();
                        float heightSquaredX=(float)textureCheck9->Height();
                        if(GetFloat(0xfb5)==-1.0) {
                            if(!pathY || !*pathY || (*pathY==' ' && !pathY[1])) {
                                Set(0xfcd,width2,true); Set(0xfce,heightSquaredX,true);
                            } else {
                                Set(0xfcd,width2/tileA->textureScale,true); Set(0xfce,heightSquaredX/tileA->textureScale,true);
                            }
                            SetImageFlags(0x10);
                            var4=-1.0f;
                        }
                        if(var4>=0.0) {
                            if(var4==0.0) var4=100.0f;
                            if(!pathY || !*pathY || (*pathY==' ' && !pathY[1])) {
                                Set(0xfcd,width2*(var4/100.0),true); Set(0xfce,heightSquaredX*(var4/100.0),true);
                            } else {
                                Set(0xfcd,width2*(var4/100.0)/tileA->textureScale,true);
                                Set(0xfce,heightSquaredX*(var4/100.0)/tileA->textureScale,true);
                            }
                            SetImageFlags(0x10);
                        }
                        changed=true;
                        if(clear && (flags & 0x20)) flags ^= 0x20;
                    } else if(clear && !GetBool(0xfa3) && (flags & 0x20)) flags ^= 0x20;
                }
            }
        }
        dynamicGeometry=false;
        if ((flags & 0x10) && Model()) {
            RenderObject* childNode4=Model()->GetChild(0);
            RenderObject* geometryX=childNode4 ? childNode4->AsGeometry() : 0;
            RenderData* var8c3=geometryX ? geometryX->Data() : 0;
            if(var8c3 && (var8c3->flags & 0x7000)==0x4000) dynamicGeometry=true;
        }
        if ((flags & 0x10) && Model()) {
            RenderObject* childB=Model()->GetChild(0);
            float widthX=GetFloat(0xfb1);
            float var4cVal=GetFloat(0xfb0);
            float var64=GetFloat(0xfc0);
            float var8=GetFloat(0xfbf);
            RenderObject* geometry9=childB;
            if(geometry9 && Type()==0x386) {
                if(!dynamicGeometry && geometry9->Data()->Vertices()) {
                    RenderPoint3* verticesTmp=geometry9->Data()->Vertices();
                    verticesTmp[0]=RenderPoint3(0.0f,0.0f,0.0f);
                    verticesTmp[1]=RenderPoint3(0.0f,0.0f,-var4cVal);
                    verticesTmp[2]=RenderPoint3(widthX,0.0f,0.0f);
                    verticesTmp[3]=RenderPoint3(widthX,0.0f,-var4cVal);
                }
                float textureWidth4=widthX;
                float textureHeight2=var4cVal;
                RenderShader* propA=childB->GetProperty(3);
                if(propA && imageB && propA->Texture()) {
                    if(GetFloat(0xfb5)!=0.0) propA->textureMode=2; else propA->textureMode=0;
                    float zoom=GetFloat(0xfb8);
                    if(GetFloat(0xfb5)==-1.0) {
                        textureWidth4=propA->Texture()->Width()*(var4cVal/propA->Texture()->Height());
                    } else if(zoom>=0.0) {
                        if(zoom==0.0) zoom=100.0f;
                        const char* path2=GetString(0xfcc);
                        if(!path2 || !*path2 || (*path2==' ' && !path2[1])) {
                            textureWidth4=propA->Texture()->Width()*(zoom/100.0);
                            textureHeight2=propA->Texture()->Height()*(zoom/100.0);
                        } else {
                            RenderTile* tile14=this;
                            textureWidth4=propA->Texture()->Width()*(zoom/100.0)/tile14->TextureScale();
                            textureHeight2=propA->Texture()->Height()*(zoom/100.0)/tile14->TextureScale();
                        }
                    } else { textureWidth4=widthX; textureHeight2=var4cVal; }
                }
                RenderPoint2* var6c=geometry9->Data()->UVs();
                if(var6c) {
                    float left8=var64/textureWidth4;
                    float top2=var8/textureHeight2;
                    float uWidth4=widthX/textureWidth4;
                    float vHeight4=var4cVal/textureHeight2;
                    if(GetValue(0xff9)) {
                        RenderRect subrect4;
                        float sheetWidthXEx=0.0f;
                        float varC7=0.0f;
                        if(sheet_2.right!=-1.0 && sheet_2.bottom!=-1.0) subrect4=sheet_2;
                        else RenderParseAtlas(GetString(0xff9),GetString(0xfcc),0,&subrect4);
                        sheetWidthXEx=subrect4.right-subrect4.left;
                        varC7=subrect4.bottom-subrect4.top;
                        if(sheetWidthXEx>0.0 && varC7>0.0) {
                            left8=left8*sheetWidthXEx+subrect4.left;
                            top2=top2*varC7+subrect4.top;
                            uWidth4=sheetWidthXEx; vHeight4=varC7;
                        }
                        float var14=GetFloat(0xfb8);
                        if(var14>0.0) {
                            var14=(float)(var14/100.0);
                            uWidth4=(GetFloat(0xfb1)/GetFloat(0xfcd))*var14;
                            vHeight4=(GetFloat(0xfb0)/GetFloat(0xfce))*var14;
                        }
                    }
                    var6c[0]=RenderPoint2(left8,top2);
                    var6c[1]=RenderPoint2(left8,top2+vHeight4);
                    var6c[2]=RenderPoint2(left8+uWidth4,top2);
                    var6c[3]=RenderPoint2(left8+uWidth4,top2+vHeight4);
                }
                if(!dynamicGeometry) {
                    if(geometry9->Data()) geometry9->Data()->SetFlags(9);
                    RenderPoint3* verticesCheck2=geometry9->Data()->Vertices();
                    geometry9->Data()->bound.Recalculate(geometry9->Data()->VertexCount(),verticesCheck2);
                }
                changed=true;
                RenderData* data8=geometry9->Data();
                if(data8) data8->Update(false);
            }
            if(clear && (flags & 0x10)) flags ^= 0x10;
        }
        if((flags & 0x40) && Model()) {
            if(Type()==0x388) { RenderTile* text_=this; text_->Update3D(); }
            changed=true;
            if(clear && (flags & 0x40)) flags ^= 0x40;
        }
        if((flags & 1) && Model()) {
            if(GetBool(0xfa8) || parent==RenderRoot()) {
                float depth_=GetFloat(0xfad);
                RenderPoint3 position22=renderZero;
                position22.x=GetFloat(0xfa1);
                position22.z=-GetFloat(0xfa2);
                position22.y=(float)(depth_*renderDepthScale);
                if(parent==RenderRoot()) {
                    position22.x-=RenderScreenWidth()/2.0;
                    position22.z=(float)((position22.z+RenderScreenHeight())-RenderScreenHeight()/2.0);
                }
                Model()->translation=position22;
                if(flags & 0x200) {
                    RenderObject* node1=Model();
                    for(unsigned int index1=0; node1 && index1<node1->ChildCount(); ++index1) {
                        RenderObject* childValA=node1->GetChild(index1);
                        RenderObject* childNodeA=childValA ? childValA->AsNode() : 0;
                        if(childNodeA && !Flag(0x8000)) childNodeA->translation=renderZero;
                    }
                }
                UpdateChildrenPosition();
            } else {
                float varCA=GetFloat(0xfad);
                RenderPoint3 position5=renderZero;
                Model()->translation=position5;
                position5.x+=GetFloat(0xfa1);
                position5.z+=-GetFloat(0xfa2);
                position5.y+=varCA*renderDepthScale;
                RenderObject* node7=Model();
                for(unsigned int indexA6=0; node7 && indexA6<node7->ChildCount(); ++indexA6) {
                    RenderObject* shapeB=RenderAsShape(node7->children.At(indexA6));
                    RenderPoint3 center3=Center();
                    RenderMatrix rotationW5;
                    rotationW5.SetRotation(GetFloat(0xffa));
                    if(shapeB) shapeB->Transform(rotationW5,position5,center3);
                }
            }
            changed=true;
            if(clear && (flags & 1)) flags ^= 1;
        }
        if(clear && (flags & 0x200)) flags ^= 0x200;
        if(Model() && (flags & 0x80)) {
            float widthTmp=RenderTargetWidth();
            float var50=RenderTargetHeight();
            if(IsRenderedMenu()) { widthTmp=RenderMenuWidth(); var50=RenderMenuHeight(); }
            float scaleX3=widthTmp/RenderScreenWidth();
            float varF6=var50/RenderScreenHeight();
            if(RenderWideMenu(GetMenu())) scaleX3*=RenderAspect();
            float leftNode7=PositionX();
            float topic2=PositionY();
            float rightA=(leftNode7+GetFloat(0xfb1))*scaleX3;
            float varE7=(topic2+GetFloat(0xfb0))*varF6;
            leftNode7*=scaleX3; topic2*=varF6;
            SetBounds(leftNode7,topic2,rightA,varE7);
            changed=true;
            if(clear && (flags & 0x80)) flags ^= 0x80;
        }
        if(Model() && (flags & 0x100)) {
            RenderTile* clipParent=parent;
            while(clipParent) {
                if(clipParent->GetBool(0xfa6)) break;
                clipParent=clipParent->parent;
            }
            if(clipParent) {
                float widthTmp=RenderTargetWidth();
                float var114=RenderTargetHeight();
                if(IsRenderedMenu()) { widthTmp=RenderMenuWidth(); var114=RenderMenuHeight(); }
                float varF2=widthTmp/RenderScreenWidth();
                float var70=var114/RenderScreenHeight();
                if(RenderWideMenu(GetMenu())) varF2*=RenderAspect();
                float leftNodeA=clipParent->PositionX();
                float topicCount8=clipParent->PositionY();
                float right5=(leftNodeA+clipParent->GetFloat(0xfb1))*varF2;
                float var4c=(topicCount8+clipParent->GetFloat(0xfb0))*var70;
                leftNodeA*=varF2; topicCount8*=var70;
                unsigned int indexB_=0;
                Model()->PrepareChildren();
                while(indexB_<Model()->ChildCount()) {
                    RenderObject* child_=Model()->GetAt(indexB_);
                    RenderShader* _prop=child_->GetProperty(3);
                    if(_prop) {
                        RenderShader::ClipRect rect24 = {
                            (int)RenderMaximum(0.0f,leftNodeA), (int)RenderMaximum(0.0f,topicCount8),
                            (int)RenderMinimum(right5,widthTmp), (int)RenderMinimum(var4c,var114)
                        };
                        _prop->clip=rect24;
                        _prop->SetClipping(true);
                    }
                    ++indexB_;
                }
            }
            changed=true;
            if(clear && (flags & 0x100)) flags ^= 0x100;
        }
        if(flags & 8) {
            RenderColor color9;
            color9.r=1.0f; color9.g=1.0f; color9.b=1.0f; color9.a=1.0f;
            float alphaB=(float)(GetFloat(0xfa9)/255.0);
            float brightness_=GetFloat(0xff5);
            if(brightness_>=0.0) brightness_=(float)(brightness_/255.0);
            if(brightness_>=0.0) {
                int colorID5=0;
                RenderTile* ancestor3=this;
                while(ancestor3 && !ancestor3->GetValue(0xff4) && ancestor3->GetFloat(0xfaa)!=111.0) {
                    if(ancestor3->Parent() && ancestor3->Parent()->Parent() && !ancestor3->Parent()->Parent()->Parent() && ancestor3->GetFloat(0xfaa)==110.0) {
                        colorID5=(int)ancestor3->GetFloat(0xff4);
                        if(!colorID5) colorID5=(int)ancestor3->Parent()->GetFloat(0xff4);
                        if(!colorID5) colorID5=1;
                        ancestor3=0; break;
                    }
                    ancestor3=ancestor3->parent;
                }
                if(ancestor3) colorID5=(int)ancestor3->GetFloat(0xff4);
                if(RenderColorManager::GetSingleton()->GetColor(colorID5,color9)) color9.Scale(brightness_);
                else brightness_=-1.0f;
            }
            if(brightness_==-1.0) {
                color9.r=(float)(GetFloat(0xfb2)/255.0);
                color9.g=(float)(GetFloat(0xfb3)/255.0);
                color9.b=(float)(GetFloat(0xfb4)/255.0);
            }
            if(SpeechFailure()) {
                if(FUN_00ec6da0(Name(),"lb_highlight_box")==0) {
                    color9.r=renderSpeechRed; color9.g=0.0f; color9.b=0.0f; alphaB=0.2f;
                } else if(Parent() && FUN_00ec6da0(Parent()->Name(),"lb_highlight_box")==0) {
                    color9.r=renderSpeechRed; color9.g=0.0f; color9.b=0.0f; alphaB=1.0f;
                }
            }
            SetColor(Model(),alphaB,&color9);
            if(clear && (flags & 8)) flags ^= 8;
        }
    }
    if(clear && (flags & 0x3ff)) RenderQueue(this); else ++renderUpdateCount;
    LeaveCriticalSection(&DAT_011f3330);
    return changed;
}
