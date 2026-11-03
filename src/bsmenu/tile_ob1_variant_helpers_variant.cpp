// src/bsmenu/tile_ob1_variant_helpers_variant.cpp - helper variant unit created 2026-11-01 by helper_variants.py: the reworked code of these functions uses the
// approved helpers of fnv_asm_helpers.h, which src/bsmenu/tile_ob1_variant.cpp cannot include without changing its accepted functions.
// Same flags (/MT /Od /Oy- /GS /EHsc /Gy /Ob1); declarations copied from that unit's skeleton.
#include "fnv_asm_helpers.h"


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
struct TileValue_00a0a270 {
    void FUN_00a0a270(float afValue, bool abClearActions);
};
struct TileValueOwner_00a01000 {
    TileValue_00a0a270* GetOrCreateTraitValue(int aiTrait);
};
struct FUN_00a012d0_t {
    void FUN_00a012d0(int aiTrait, float afValue, bool abClearActions);
};
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
int TraitNameToID(const char* apText);
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
bool __cdecl FUN_00a0bb00(char const*);
void __cdecl FUN_009ff8a0(char const*, int);
extern int DAT_011a6d74;
extern BSMapBase<unsigned long, ScrapHeapBuffer*> DAT_011f32f4;
int __cdecl TraitNameToIDAdd(char const* apString, int aiIndex);
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
void __cdecl FUN_009ff8a0(char const* apName, int aiValue);
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
ScrapHeapBuffer* __cdecl FUN_00a01a70(unsigned int requestedKey);
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
void __cdecl FUN_00a07690(FlaggedTile* apTile);
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
void __cdecl FUN_00a0ba50();
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
ReuseNode* FUN_00a0b950(int a, float f, const char* s, int b, int c);
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
int __cdecl FUN_00a09030(int id);
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

#include <math.h>
namespace fnv_00a09410 {
void* __cdecl operator new(unsigned,void*);
int __cdecl FUN_00ec6da0(const char*, const char*);
unsigned int __cdecl strlen(const char*);
int __cdecl strcpy_s(char*, unsigned int, const char*);
int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
double __cdecl FUN_00ec6940(double);
double __cdecl FUN_00ec9e10(double);
double __cdecl fabs(double);
extern const char DAT_01020764[];
struct P03MM { void* Allocate(unsigned int); void Deallocate(void*); };
extern P03MM g_memoryManager;
extern int DAT_0106cc64;
extern __declspec(thread) int DAT_012722b4;
__forceinline int GetMemoryContext() { return DAT_012722b4; }
__forceinline void SetMemoryContext(int value) { DAT_012722b4=value; }
struct ValueContext {
 int saved;
 __forceinline ValueContext() { saved=GetMemoryContext(); SetMemoryContext(13); }
 __forceinline ~ValueContext() { SetMemoryContext(saved); }
};
struct StackAllocation { virtual void Destroy(); virtual float* Allocate(unsigned); };
struct EvalStack {
 __forceinline unsigned GetSize() { return size; }
 __forceinline float& GetAt(unsigned index) { return data[index]; }
 int* vtable; float* data; unsigned size; unsigned capacity;
 inline void FUN_006b3eb0(unsigned reserved,unsigned initial) {
 data=0; size=0; capacity=0;
 if(initial>reserved) reserved=initial;
 if(reserved>0) { data=((StackAllocation*)this)->Allocate(reserved); capacity=reserved; }
 if(initial>0) { Construct(data,initial); size=initial; }
 }
 __forceinline void Construct(float* start,unsigned count) { for(unsigned i=0;i<count;++i) { operator new(sizeof(float),start+i); } }
 unsigned FUN_00761540();
 inline unsigned AppendFloat(float* value) {
 unsigned index=FUN_00761540();
 Construct(data+index,1);
 data[index]=*value;
 return index;
 }
 void FUN_006db720();
 __forceinline EvalStack(unsigned start=0,unsigned growth=0) { vtable=&DAT_0106cc64; FUN_006b3eb0(start,growth); }
 __forceinline ~EvalStack() { FUN_006db720(); }
 __forceinline void RemoveLast(unsigned count) {
  if(!size) return;
  for(unsigned i=0;i<count;++i) {}
  size-=count;
 }
};
struct EvalTile;
struct EvalValue;
struct EvalReference { int trait; EvalTile* tile; float value; const char* text; };
struct EvalAction {
 virtual float GetFloat();
 virtual EvalReference* GetReference();
 int operation; EvalAction* next;
};
struct EvalTile {
 virtual void v0(); virtual void v1(); virtual void v2();
 virtual void v3(); virtual void v4(); virtual void v5();
 virtual int ChangeValue(int,float,const char*);
 int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;
 unsigned flags;
 __forceinline bool Flag(unsigned mask) { return (flags&mask)!=0; }
 EvalReference* FUN_00a0a0b0(int,int);
 void FUN_00a037e0(int,float,const char*);
};
struct TraitLookup { bool FUN_00a1e380(int,int*); };
extern TraitLookup DAT_011f3308;
void __cdecl NotifyHandlersByKey(EvalValue*);
__forceinline float Minimum(float a,float b) { return a<b?a:b; }
__forceinline float Maximum(float a,float b) { return a>b?a:b; }
__forceinline float FloorValue(float a) { return (float)FUN_00ec6940(a); }
__forceinline float CeilValue(float a) { return (float)FUN_00ec9e10(a); }
__forceinline float AbsValue(float a) { return (float)fabs(a); }
__forceinline double RoundMultiple(float a,const float& b) { float quotient=a/b; return ((int)quotient+(quotient-(int)quotient<0.5?0:1))*b; }
struct EvalValue {
 int m_iValueId; EvalTile* pTile; float fValue; char* pString; EvalAction* actions;
 __forceinline char* String() { return pString; }
 void Refresh(bool);
};
// @fnv 0x00a09410
void EvalValue::Refresh(bool update) {
 if((pTile->flags&0x10000) && m_iValueId!=4004) return;
 if(!pTile || pTile->Flag(0x4000)) return;

 char* newNumberText_;
 char* oldNumberTextTmp;
 char* newText;
 char* oldText4;
 int remaining;
 int digits2;
 int numberTmp;
 unsigned lengthVal3;
 float saved9;
 EvalReference* resolvedA;
 int lookup4;
 EvalReference* reference5;
 float operandTmp;
 const char* text3;
 int operationX;
 EvalAction* action43;
 bool changedVal3;
 float oldValue9;
 ValueContext context4_2;
 action43=actions;
 oldValue9=fValue;
 EvalStack stackVal;
 changedVal3=false;
 while(action43) {
  operandTmp=action43->GetFloat();
  text3=0;
  if(action43->GetReference()) {
   reference5=action43->GetReference();
   lookup4=0;
   text3=reference5->text;
   if(reference5->trait>=10000) DAT_011f3308.FUN_00a1e380(reference5->trait,&lookup4);
   if(lookup4==-1) {
    resolvedA=reference5->tile->FUN_00a0a0b0(reference5->trait,fnv_FloatToInt(fValue));
    if(resolvedA) { operandTmp=resolvedA->value; text3=resolvedA->text; }
   }
  }
  operationX=action43->operation;
  if(operationX==2024) { stackVal.AppendFloat(&fValue); fValue=0; }
  else if(operationX==2025) {
   saved9=stackVal.data[stackVal.size-1];
   operationX=fnv_FloatToInt(action43->GetFloat());
   operandTmp=fValue;
   fValue=saved9;
   stackVal.RemoveLast(1);
  }
  switch(operationX) {
   case 2000:
    if(text3) {
     lengthVal3=strlen(text3);
     changedVal3=!pString || FUN_00ec6da0(String(),text3);
     if(pString) { oldText4=pString; g_memoryManager.Deallocate(oldText4); pString=0; }
     newText=(char*)g_memoryManager.Allocate(lengthVal3+1); pString=newText;
     strcpy_s(String(),lengthVal3+1,text3);
    } else fValue=operandTmp;
    break;
   case 2001: fValue+=operandTmp; break;
   case 2002: fValue-=operandTmp; break;
   case 2003: fValue*=operandTmp; break;
   case 2004: if(operandTmp!=0.0) fValue/=operandTmp; break;
   case 2005: fValue=Minimum(fValue,operandTmp); break;
   case 2006: fValue=Maximum(fValue,operandTmp); break;
   case 2007: if(operandTmp!=0.0) {
    fValue=fnv_FloatToInt(fValue)%fnv_FloatToInt(operandTmp);
   } break;
   case 2008: fValue=(double)FloorValue(fValue+operandTmp); break;
   case 2009: fValue=(double)CeilValue(fValue+operandTmp); break;
   case 2010: fValue=(double)AbsValue(fValue+operandTmp); break;
   case 2011: fValue=RoundMultiple(fValue,operandTmp); break;
   case 2012: fValue=fValue>operandTmp?1:0; break;
   case 2013: fValue=fValue>=operandTmp?1:0; break;
   case 2014: fValue=fValue==operandTmp?1:0; break;
   case 2015: fValue=fValue!=operandTmp?1:0; break;
   case 2016: fValue=fValue<operandTmp?1:0; break;
   case 2017: fValue=fValue<=operandTmp?1:0; break;
   case 2018:
    if(text3) fValue=fValue!=0.0 && text3?1:0;
    else fValue=fValue!=0.0 && operandTmp!=0.0?1:0;
    break;
   case 2019:
    if(text3) fValue=fValue!=0.0 || text3?1:0;
    else fValue=fValue!=0.0 || operandTmp!=0.0?1:0;
    break;
   case 2020:
    if(text3) fValue=!text3;
    else fValue=operandTmp==0.0?1:0;
    break;
   case 2021: if(operandTmp==0.0 && !text3) fValue=0; break;
   case 2022: if(operandTmp!=0.0 || text3) fValue=0; break;
  }
  action43=action43->next;
 }
 if(!pString) changedVal3=oldValue9!=fValue;
 if(oldValue9!=fValue && m_iValueId==4036) {
  numberTmp=fnv_FloatToInt(fValue);
  digits2=numberTmp==0;
  for(remaining=numberTmp;remaining;remaining/=10) ++digits2;
  if(numberTmp<0) ++digits2;
  if(!pString || (pString && strlen(String())!=digits2)) {
   oldNumberTextTmp=pString; g_memoryManager.Deallocate(oldNumberTextTmp);
   newNumberText_=(char*)g_memoryManager.Allocate(digits2+1); pString=newNumberText_;
  }
  sprintf_s(pString,digits2+1,DAT_01020764,numberTmp);
  changedVal3=true;
 }
 if(changedVal3 || update) {
  NotifyHandlersByKey(this);
  if(pTile && !pTile->Flag(0x2000)) {
   if(!pTile->ChangeValue(m_iValueId,fValue,pString)) pTile->FUN_00a037e0(m_iValueId,fValue,pString);
  }
 }
}
}  // namespace fnv_00a09410

struct Input02D40 { unsigned int m00; char* m04; };
typedef unsigned short U16_02D40;
extern char str_01094a64[], str_01094a4c[], str_01021184[];
extern "C" char* __cdecl FUN_00ec7750(const char*, const char*);
extern "C" char* __cdecl FUN_00ec7690(const char*, int);
extern "C" void* __cdecl FUN_00ec61c0(void*, int, unsigned int);
extern "C" int __cdecl FUN_00ec8d5f(char*, unsigned int, const char*, unsigned int);
extern "C" int __cdecl FUN_00ec65a6(char*, unsigned int, const char*);
extern "C" char* __cdecl FUN_00ecc5f8(char*, const char*, char**);
extern "C" unsigned int __cdecl FUN_00ec6130(const char*);
extern void* __cdecl FormHeap_Allocate(unsigned);
extern void __cdecl FormHeap_Free(void*);
extern void* __cdecl FUN_00401460(void*, const void*, unsigned);
__forceinline void* __cdecl operator new[](unsigned size) { return ((TilePool_ac80*)&DAT_011f6238)->FUN_00aa3e40(size); }
__forceinline void __cdecl operator delete[](void* data) { DAT_011f6238.FUN_00aa4060(data); }
__forceinline int RenderCopyData(char* dest, unsigned capacity, const char* source) { return FUN_00ec65a6(dest, capacity, source); }
__forceinline void CopyPrefix(char* dest, const char* source, const char* begin) {
    unsigned length = begin - source;
    FUN_00ec8d5f(dest, length + 1, source, length);
}
__forceinline void CopyMiddle(char* dest, const char* begin, unsigned skip, const char* next) {
    unsigned length = next - begin - skip;
    FUN_00ec8d5f(dest, length + 1, begin + skip, length);
}
template<class T> __forceinline unsigned StringLength(const T* text) { return FUN_00ec6130(text); }
__forceinline unsigned CapacityMaximum(unsigned a, unsigned b) { return a > b ? a : b; }
struct StrMem {
    union {
        struct { char* m00; unsigned short m04, m06; };
    };
    inline bool Set(const char*, unsigned int);
    inline StrMem& FUN_00404820(const char*);
    __forceinline void SetLength(unsigned int n) { m04 = n <= 65535U ? (unsigned short)n : 65535; }
    __forceinline void SetCapacity(unsigned int n) { m06 = n <= 65535U ? (unsigned short)n : 65535; }
    __forceinline unsigned MaxLength() const { return m06; }
    __forceinline void Init() { m00 = 0; SetLength(0); SetCapacity(0); }
    __forceinline StrMem() { Init(); }
    __forceinline ~StrMem() { Set(0, 0); }
    __forceinline const char* String() const { return m00; }
    __forceinline unsigned int Length() const { return m04 == 65535 ? StringLength(m00) : m04; }
};
inline bool StrMem::Set(const char* text, unsigned int capacity) {
    unsigned int length = text ? StringLength(text) : 0;
    unsigned int needed = CapacityMaximum(length, capacity);
    unsigned int previousCapacity = MaxLength();
    char* previousBuffer = m00;
    if (needed <= previousCapacity) {
        if (needed) {
            if (text) FUN_00401460(previousBuffer, text, length + 1);
            else previousBuffer[0] = 0;
        } else {
            if (previousBuffer) delete[] previousBuffer;
            m00 = 0;
            needed = 0;
            SetCapacity(needed);
        }
    } else {
        char* old = previousBuffer;
        m00 = new char[needed + 1];
        if (text) FUN_00401460(m00, text, length + 1);
        else m00[0] = 0;
        if (old) delete[] old;
        SetCapacity(needed);
    }
    SetLength(length);
    return length != 0;
}
inline StrMem& StrMem::FUN_00404820(const char* text) {
    if (text) {
        const char* current = String();
        if (current) {
            unsigned int extra = text ? StringLength(text) : 0;
            unsigned int needed = Length() + extra;
            if (needed > MaxLength()) Set(current, needed);
            FUN_00401460(m00 + Length(), text, extra + 1);
            SetLength(needed);
        } else Set(text, 0);
    }
    return *this;
}
extern int __cdecl FUN_00406f60(StrMem*, const char*, ...);
struct Record02D40 {
    unsigned int m00;
    char* m04;
    void FUN_00a0be70();
    inline ~Record02D40() { FUN_00a0be70(); }
    inline void operator delete(void* p) { DAT_011f6238.FUN_00aa4060(p); }
};
extern Record02D40* __cdecl GetOrLoadXML(const char*, int);
// @fnv 0x00a02d40
bool __cdecl FUN_00a02d40(Input02D40* arg) {
    char* source3 = arg->m04;
    char* begin_2 = FUN_00ec7750(source3, str_01094a64);
    if (begin_2) {
        StrMem i;
        unsigned int h = arg->m00 + 1;
        char* p9 = new char[h];
        FUN_00ec61c0(p9, 0, h);
        CopyPrefix(p9, source3, begin_2);
        i.Set(p9, 0x4000);
        bool a = false;
        while (!a) {
            StrMem tokenA;
            unsigned int skip = FUN_00ec7690(begin_2, '>') - begin_2 + 1;
            FUN_00ec61c0(p9, 0, h);
            char* context_2;
            FUN_00ecc5f8(begin_2, str_01021184, &context_2);
            FUN_00406f60(&tokenA, str_01094a4c, FUN_00ecc5f8(0, str_01021184, &context_2));
            Record02D40* record = GetOrLoadXML(tokenA.String(), 0);
            i.FUN_00404820(record->m04);
            delete record;
            char* next9 = FUN_00ec7750(begin_2 + skip, str_01094a64);
            FUN_00ec61c0(p9, 0, h);
            if (next9) {
                CopyMiddle(p9, begin_2, skip, next9);
                begin_2 = next9;
            } else {
                FUN_00ec65a6(p9, h, begin_2 + skip);
                a = true;
            }
            i.FUN_00404820(p9);

        }
        delete[] arg->m04;
        arg->m04 = new char[i.Length() + 1];
        RenderCopyData(arg->m04, i.Length() + 1, i.String());
        arg->m00 = i.Length();
        delete[] p9;
        FUN_00a02d40(arg);
        return true;
    }
    return false;
}
