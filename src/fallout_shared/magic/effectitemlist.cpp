// fallout_shared/magic/effectitemlist.cpp: EffectItemList, EILStandIn, EffectListCmp, EffectItemListFind and more (28 functions)

#include "effectitemlist.h"

// Out-of-line reference for the inline ActorPathHandler::CompleteNoPathUpdate so the
// translation unit emits the method body attributed to the header.
ActorPathHandler::PATH_HANDLER_RESULT CallNoPathUpdate(ActorPathHandler* pHandler, float fSeconds)
{
    return pHandler->CompleteNoPathUpdate(fSeconds);
}

// @fnv 0x00405d80
bool __fastcall FUN_00405d80(int* pThis)
{
    return pThis[3] > 0;
}

namespace MagicEffectSystem {
struct _Type
{
    enum Type
    {
    };
};
bool __cdecl IsFlagSet(_Type::Type, unsigned int);
}

struct EffectSetting
{
    int GetArchetype();
};

// @fnv 0x004064b0
bool __fastcall IsArchetypeFlagSet(EffectSetting* pThis)
{
    return MagicEffectSystem::IsFlagSet((MagicEffectSystem::_Type::Type)pThis->GetArchetype(), 0x7c);
}

struct Actor;
struct EffectSetting;
struct MagicItem;
struct Script;
struct PerkEntryConditionSet;
struct TESFile;
struct TESForm;
struct blob8
{
    char b[8];
};
struct EffectItem
{
    void Save();
    bool Load(TESFile*, char*);
    void Copy(EffectItem*);
    bool Compare(EffectItem*);
    bool MatchesEffect(EffectItem*);
    void InitItem(TESForm*);
    struct blob8 GetEffectString(MagicItem*, float);
    struct blob8 GetEffectString(int, float, bool, bool, bool);
    EffectSetting* GetEffectSetting();
    char* GetIcon();
    int GetMagnitude();
    bool SetMagnitude(int);
    int GetArea();
    bool SetArea(int);
    int GetDuration();
    bool SetDuration(int);
    int GetRange();
    bool SetRange(int);
    int IsAssociatedItemUsed();
    bool IsActorValueUsed();
    bool IsScriptEffect();
    bool IsDisabled();
    bool IsHostile();
    void SetHostile(bool);
    bool IsScriptBasedEffect();
    void GetEffectName(char*);
    struct blob8 GetEffectName();
    int GetEffectID();
    int GetAffectedActorValue();
    void SetActorValueIndex(int);
    Script* GetScript();
    float GetCost(Actor*);
    float GetRawCost();
    PerkEntryConditionSet* GetConditions();
    void PausePlayback(PerkEntryConditionSet*);
    void SetEffectAt(EffectSetting*);
    void Initialize(EffectSetting*);
    void* __vecDelDtor(unsigned int);
    char data[20];
    EffectSetting* m_pEffectSetting;
    float m_fCost;
    char Conditions[8];
};
typedef char _sizecheck_EffectItem[sizeof(EffectItem) == 36 ? 1 : -1];

struct EffectItemList_shell
{
    EffectItem* FindCostliestEffectItem(int, int);
};

// @fnv 0x004065e0
int __fastcall FUN_004065e0(EffectItemList_shell* pthis)
{
    int eresult = -1;
    EffectItem* peffect = pthis->FindCostliestEffectItem(3, 0);
    if (peffect)
    {
        eresult = peffect->GetEffectID();
    }
    return eresult;
}

double __cdecl FUN_00ec6940(double);

// @fnv 0x00406ce0
float __cdecl FUN_00406ce0(float afValue)
{
    return static_cast<float>(FUN_00ec6940(afValue));
}

int __cdecl _vsprintf_s(char*, int, const char*, char*);

// Calls _vsprintf_s to format the variadic arguments following apFormat into apString1 using aiSize as the buffer size.
// @fnv 0x00406d00
int __cdecl FUN_00406d00(char* apString1, int aiSize, const char* apFormat, ...)
{
    char* vList = (char*)(&apFormat + 1);
    return _vsprintf_s(apString1, aiSize, apFormat, vList);
}

extern unsigned int* g_011d61c8[];

// @fnv 0x00406d70
bool __cdecl FUN_00406d70(int aiIndex, int aiFlag)
{
    return (g_011d61c8[aiIndex][0x11] & aiFlag) != 0;
}

struct EI;
struct LN
{
    EI** _ref_006815c0();
    LN* _ref_00726070();
};
void _FNV_Warning(const char*);
struct HX
{
    EI* FUN_00406ee0(unsigned char);
};
// @fnv 0x00406ee0
EI* HX::FUN_00406ee0(unsigned char aiIndex)
{
    unsigned char uiCurrentIndex = 0;
    LN* pCurrentElementNext = this ? (LN*)((char*)this + 4) : 0;
    while (pCurrentElementNext)
    {
        if (uiCurrentIndex == aiIndex)
            return *pCurrentElementNext->_ref_006815c0();
        uiCurrentIndex++;
        pCurrentElementNext = pCurrentElementNext->_ref_00726070();
    }
    _FNV_Warning(
        "GAME EFFECTS: When trying to get an effect item by its index, the index was larger than the size of the list.");
    return 0;
}

int __cdecl FUN_00ec6cc4(char*, const char*, char*);

// @fnv 0x00407000
int __cdecl FUN_00407000(char* apString1, const char* apFormat, char* aList)
{
    return FUN_00ec6cc4(apString1, apFormat, aList);
}

class RecursiveSpinLock
{
  public:
    RecursiveSpinLock();
};

extern int DAT_01070020;

// @fnv 0x0071f540
void* __fastcall ConstructWithVTable(void* apObject)
{
    reinterpret_cast<RecursiveSpinLock*>(reinterpret_cast<char*>(apObject) + 4)->RecursiveSpinLock::RecursiveSpinLock();
    *reinterpret_cast<int**>(apObject) = &DAT_01070020;
    return apObject;
}

extern int DAT_01011cf4;
extern int DAT_01011d0c;
namespace stand {
struct TESFullName
{
    TESFullName();
    ~TESFullName();
    void* vt0;
    char pad0[8];
};
}
struct FUN_004056a0
{
    FUN_004056a0();
    ~FUN_004056a0();
    void* vt1;
};
struct FUN_00402c90 : public stand::TESFullName, public FUN_004056a0
{
    FUN_00402c90();
};
// Sets the two vtable pointers of the object to DAT_01011d0c and DAT_01011cf4.
// @fnv 0x00402c90
FUN_00402c90::FUN_00402c90()
{
    vt0 = &DAT_01011d0c;
    vt1 = &DAT_01011cf4;
}

namespace fnv_00405f30 {
struct LN
{
    bool _ref_008256d0();
    EffectItem** _ref_006815c0();
    LN* _ref_00726070();
};
struct EIHelper
{
    int _ref_0084e3a0();
    bool IsDetrimental();
};
struct EILPad
{
    int vtbl;
};
struct EILStandIn : EILPad, LN
{
    bool HasNonDetrimentalEffect();
};
// @fnv 0x00405f30
bool EILStandIn::HasNonDetrimentalEffect()
{
    EILStandIn* pCurrentElementNext = this;
    if (pCurrentElementNext->_ref_008256d0())
        return false;
    bool bfound = false;
    while (pCurrentElementNext && !bfound)
    {
        EffectItem* pitem = *pCurrentElementNext->_ref_006815c0();
        if (pitem && ((EIHelper*)pitem)->_ref_0084e3a0() == 2 && !((EIHelper*)pitem)->IsDetrimental())
            bfound = true;
        pCurrentElementNext = (EILStandIn*)pCurrentElementNext->_ref_00726070();
    }
    return bfound;
}
}  // namespace fnv_00405f30

struct EffectItemHeader
{
    int header;
};
struct EffectItemDetrimental
{
    bool IsDetrimental();
};
struct EffectItemNode
{
    EffectItem* item;
    EffectItemNode* next;
    EffectItem** _ref_006815c0();
    EffectItemNode* _ref_00726070();
    bool _ref_008256d0();
};

struct EffectItemList : public EffectItemHeader, public EffectItemNode
{
    bool FUN_00405da0();
};

// @fnv 0x00405da0
bool EffectItemList::FUN_00405da0()
{
    EffectItemList* pCurrentElementNext = this;
    if (pCurrentElementNext->_ref_008256d0())
        return false;
    while (pCurrentElementNext)
    {
        EffectItem* pitem = *pCurrentElementNext->_ref_006815c0();
        if (pitem && !((EffectItemDetrimental*)pitem)->IsDetrimental() && !pitem->IsHostile())
            return false;
        pCurrentElementNext = static_cast<EffectItemList*>(pCurrentElementNext->_ref_00726070());
    }
    return true;
}

namespace fnv_00406340 {
struct EffectItemHeader
{
    int header;
};
struct EffectItemNode
{
    EffectItem* item;
    EffectItemNode* next;
    EffectItem** _ref_006815c0();
    void _ref_0063f7b0();
    EffectItemNode* _ref_00726070();
};
struct EffectItemDeleter
{
    ~EffectItemDeleter();
};

struct EffectItemList : public EffectItemHeader, public EffectItemNode
{
    void FUN_00406340();
};

// @fnv 0x00406340
void EffectItemList::FUN_00406340()
{
    EffectItemList* pCurrentElementNext = this;
    while (pCurrentElementNext)
    {
        EffectItem* pitem = *pCurrentElementNext->_ref_006815c0();
        if (pitem)
        {
            delete (EffectItemDeleter*)pitem;
            pCurrentElementNext->_ref_0063f7b0();
        }
        else
        {
            pCurrentElementNext = static_cast<EffectItemList*>(pCurrentElementNext->_ref_00726070());
        }
    }
}
}  // namespace fnv_00406340

namespace fnv_00403ca0 {
class EffectSetting;
struct EffectItem
{
    EffectSetting* GetEffectSetting();
};
struct FUN_00403ba0
{
    FUN_00403ba0();
    int m_iMagnitude;
    int m_iArea;
    int m_iPayloadInteger;
    int m_eRange;
    int m_eAssociatedActorValue;
};
struct PerkEntryConditionSet
{
    PerkEntryConditionSet();
    ~PerkEntryConditionSet();
    void* pHead;
    void* pNext;
};

struct FUN_00403ca0
{
    FUN_00403ba0 data;
    EffectSetting* m_pEffectSetting;
    float m_fCost;
    PerkEntryConditionSet Conditions;
    FUN_00403ca0(EffectItem* other);
    void FUN_00403be0(EffectSetting* setting);
    void CopyFrom(EffectItem* other);
};

// @fnv 0x00403ca0
FUN_00403ca0::FUN_00403ca0(EffectItem* pEffectItem)
{
    FUN_00403be0(pEffectItem->GetEffectSetting());
    m_pEffectSetting = 0;
    CopyFrom(pEffectItem);
}
}  // namespace fnv_00403ca0

namespace fnv_004062a0 {
struct EffectItem;
struct EffectItemDetrimental
{
    bool IsDetrimental();
};
struct EffectItemNode
{
    bool FUN_008256d0();
    EffectItem** FUN_006815c0();
    EffectItemNode* FUN_00726070();
    EffectItem* item;
    EffectItemNode* next;
};

struct EffectItemList : public EffectItemNode
{
    virtual ~EffectItemList();
    bool HasDetrimentalEffect();
};

// @fnv 0x004062a0
bool EffectItemList::HasDetrimentalEffect()
{
    bool bDetrimental = false;
    EffectItemList* pCurrentElementNext = this;
    if (pCurrentElementNext->FUN_008256d0())
        return false;
    while (pCurrentElementNext && !bDetrimental)
    {
        EffectItem* pitem = *pCurrentElementNext->FUN_006815c0();
        if (pitem && reinterpret_cast<EffectItemDetrimental*>(pitem)->IsDetrimental())
            bDetrimental = true;
        pCurrentElementNext = static_cast<EffectItemList*>(pCurrentElementNext->FUN_00726070());
    }
    return bDetrimental;
}
}  // namespace fnv_004062a0

namespace fnv_004064d0 {
struct MagicEffectEntry
{
    unsigned int FUN_0084e3a0();
};
struct EffectItemDetrimental
{
    bool IsDetrimental();
};
struct EffectItemNode
{
    bool FUN_008256d0();
    EffectItem** FUN_006815c0();
    EffectItemNode* FUN_00726070();
    EffectItem* item;
    EffectItemNode* next;
};

struct EffectItemList : public EffectItemNode
{
    virtual ~EffectItemList();
    EffectItem* FindCostliestEffectItem(int aeRange, bool abAreaOnly);
};

// Scans the effect list for the non-detrimental item with the highest cost matching the range (and area if requested), returning it or null.
// @fnv 0x004064d0
EffectItem* EffectItemList::FindCostliestEffectItem(int aeRange, bool abAreaOnly)
{
    EffectItemList* pCurrentElementNext;
    EffectItem* pBestItem;
    int imaxCost;
    pBestItem = 0;
    pCurrentElementNext = this;
    if (pCurrentElementNext->FUN_008256d0())
        return 0;
    imaxCost = -1;
    while (pCurrentElementNext)
    {
        EffectItem* pitem;
        int iItemCost;
        pitem = *pCurrentElementNext->FUN_006815c0();
        iItemCost = (int)pitem->GetCost(0);
        if (!reinterpret_cast<EffectItemDetrimental*>(pitem)->IsDetrimental() && iItemCost > imaxCost)
        {
            if (abAreaOnly ? pitem->GetArea() > 0 : 1)
            {
                if (aeRange == 3 ||
                    (aeRange != 3 && reinterpret_cast<MagicEffectEntry*>(pitem)->FUN_0084e3a0() == aeRange))
                {
                    pBestItem = pitem;
                    imaxCost = iItemCost;
                }
            }
        }
        pCurrentElementNext = static_cast<EffectItemList*>(pCurrentElementNext->FUN_00726070());
    }
    return pBestItem;
}
}  // namespace fnv_004064d0

void _Deallocate(void*);
struct Fake406e40
{
    void FUN_00406de0();
    void* FUN_00406e40(unsigned int);
};
// Calls FUN_00406de0, then frees this via _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00406e40
void* Fake406e40::FUN_00406e40(unsigned int flags)
{
    FUN_00406de0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

float __fastcall FUN_008a0c20(void*);
struct Mid93
{
    virtual void f0();
    virtual void f1();
    virtual int f2(int);
};
struct Obj93
{
    char _p[0xA4];
    Mid93 m;
    void __thiscall GetTwoValues(float*, float*);
};
// Stores FUN_008a0c20(this) into *p2 and the result of m.f2(46) into *p1.
// @fnv 0x0093abe0
void __thiscall Obj93::GetTwoValues(float* pfValue, float* pfResult)
{
    *pfResult = FUN_008a0c20(this);
    *pfValue = (float)m.f2(46);
}

namespace fnv_00405fe0 {
struct EffectItem_acc : EffectItem
{
    int _ref_0084e3a0();
    bool IsDetrimental();
};

struct BSSimpleList_Standin
{
    bool _ref_008256d0();
    EffectItem** _ref_006815c0();
    BSSimpleList_Standin* _ref_00726070();
};

struct EffectItemList : public BSSimpleList_Standin
{
    virtual ~EffectItemList();
    int m_iEffectCount;

    bool FUN_00405fe0();
};

// @fnv 0x00405fe0
bool EffectItemList::FUN_00405fe0()
{
    EffectItemList* pCurrentElementNext = this;
    if (pCurrentElementNext->_ref_008256d0())
        return false;

    bool bfound = false;
    while (pCurrentElementNext && !bfound)
    {
        EffectItem* pitem = *pCurrentElementNext->_ref_006815c0();
        if (pitem && ((EffectItem_acc*)pitem)->_ref_0084e3a0() == 1 && !((EffectItem_acc*)pitem)->IsDetrimental())
            bfound = true;

        pCurrentElementNext = (EffectItemList*)pCurrentElementNext->_ref_00726070();
    }
    return bfound;
}
}  // namespace fnv_00405fe0

namespace fnv_00406090 {
class EffectItem
{
  public:
    int _ref_0084e3a0();
    bool IsDetrimental();
};

class BSSimpleList
{
  public:
    bool _ref_008256d0();
    EffectItem** _ref_006815c0();
    BSSimpleList* _ref_00726070();
};

class EffectItemListPrefix
{
  public:
    int m_prefix;
};

class EffectItemList : public EffectItemListPrefix, public BSSimpleList
{
  public:
    bool FUN_00406090();
};

// @fnv 0x00406090
bool EffectItemList::FUN_00406090()
{
    EffectItemList* pCurrentElementNext;
    bool bfound;

    pCurrentElementNext = this;

    if (pCurrentElementNext->_ref_008256d0())
        return false;

    bfound = false;

    while (pCurrentElementNext && !bfound)
    {
        EffectItem* pitem;

        pitem = *pCurrentElementNext->_ref_006815c0();

        if (pitem && !pitem->_ref_0084e3a0() && !pitem->IsDetrimental())
            bfound = true;

        pCurrentElementNext = (EffectItemList*)pCurrentElementNext->_ref_00726070();
    }

    return bfound;
}
}  // namespace fnv_00406090

struct EffectItemCmp
{
    bool Compare(EffectItemCmp*);
};

struct EffectListHdr
{
    int header;
};
struct EffectListNode
{
    EffectItemCmp* item;
    EffectListNode* next;
    int GetSize();
    bool IsEmpty();
    EffectItemCmp** GetItem();
    EffectListNode* GetNext();
};
struct EffectListCmp : public EffectListHdr, public EffectListNode
{
    bool FUN_00405a00(EffectListCmp* apOther);
};

// Returns true if the two effect lists differ.
// @fnv 0x00405a00
bool EffectListCmp::FUN_00405a00(EffectListCmp* apOther)
{
    if (apOther->GetSize() != GetSize())
        return true;
    if (!IsEmpty())
    {
        EffectListCmp* pNodeA = this;
        EffectListCmp* pNodeB = apOther;
        while (pNodeA)
        {
            EffectItemCmp* pItemB = *pNodeA->GetItem();
            EffectItemCmp* pElement = *pNodeB->GetItem();
            if (pItemB && pElement && pItemB->Compare(pElement))
                return true;
            pNodeA = static_cast<EffectListCmp*>(pNodeA->GetNext());
            pNodeB = static_cast<EffectListCmp*>(pNodeB->GetNext());
        }
    }
    return false;
}

void* __cdecl FormHeap_Allocate(unsigned int uiSize);

class B5B10ItemCopy
{
  public:
    B5B10ItemCopy(EffectItem* pkSource);

    static void* operator new(unsigned int uiSize)
    {
        return FormHeap_Allocate(uiSize);
    }
    static void operator delete(void* pvMem);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

class B5B10Owner
{
  public:
    void Clear();
    void AddItem(B5B10ItemCopy* pkItem);
    void CopyItemsFromList(EffectItemList* pkList);
};

// Clears the owner, then walks the linked EffectItemList and adds a B5B10ItemCopy for each non-null EffectItem.
// @fnv 0x00405b10
void B5B10Owner::CopyItemsFromList(EffectItemList* pkList)
{
    Clear();
    EffectItemList* pkNode = pkList;
    while (pkNode)
    {
        EffectItem* pkItem = *pkNode->_ref_006815c0();
        if (pkItem)
        {
            B5B10ItemCopy* pkCopy = new B5B10ItemCopy(pkItem);
            AddItem(pkCopy);
        }
        pkNode = static_cast<EffectItemList*>(pkNode->_ref_00726070());
    }
}

struct EffectSetting_6140
{
    bool IsFlagSet(unsigned int auiFlag);
};

struct EffectItem_6140
{
    EffectSetting_6140* GetEffectSetting();
    bool IsDetrimental();
};

struct EffectItemNode_6140
{
    EffectItem_6140* item;
    EffectItemNode_6140* next;
    EffectItem_6140** _ref_006815c0();
    EffectItemNode_6140* _ref_00726070();
    bool _ref_008256d0();
};

struct EffectItemList_6140 : public EffectItemHeader, public EffectItemNode_6140
{
    bool HasNonDetrimentalEffectWithFlag(unsigned int auiFlag);
};

// @fnv 0x00406140
bool EffectItemList_6140::HasNonDetrimentalEffectWithFlag(unsigned int auiFlag)
{
    EffectItemList_6140* pNode2 = this;
    if (pNode2->_ref_008256d0())
        return false;
    bool bResultTmp = false;
    while (pNode2 && !bResultTmp)
    {
        EffectItem_6140* pItem = *pNode2->_ref_006815c0();
        if (pItem && pItem->GetEffectSetting()->IsFlagSet(auiFlag) && !pItem->IsDetrimental())
        {
            bResultTmp = true;
        }
        pNode2 = static_cast<EffectItemList_6140*>(pNode2->_ref_00726070());
    }
    return bResultTmp;
}

class Entry406
{
  public:
    unsigned int GetTimeStamp();
};

unsigned int GetUsageMonitorEntry406();

class List406
{
  public:
    bool IsEmpty();
    Entry406** GetItem();
    List406* GetNext();
};

class Head406
{
  public:
    int unk00;
};

class Node406 : public Head406, public List406
{
  public:
    Entry406* FindEntryByTimeStamp();
};

// Walks the node list and returns the first entry whose GetTimeStamp equals GetUsageMonitorEntry406(), or null.
// @fnv 0x00406200
Entry406* Node406::FindEntryByTimeStamp()
{
    Entry406* pkResult = 0;
    Node406* pkNode = this;
    while (pkNode && !pkNode->IsEmpty() && !pkResult)
    {
        Entry406* pkEntry = *pkNode->GetItem();
        if (pkEntry->GetTimeStamp() == GetUsageMonitorEntry406())
            pkResult = pkEntry;
        else
            pkNode = static_cast<Node406*>(pkNode->GetNext());
    }
    return pkResult;
}

extern double DAT_01012060;
float __cdecl FUN_00404040(float);
struct S_004063e0 : EffectItemList
{
    float GetTotalCost(Actor* actor);
};
// @fnv 0x004063e0
float S_004063e0::GetTotalCost(Actor* actor)
{
    float total;
    EffectItemList* p5 = this;
    if (p5->_ref_008256d0())
        return 0.0f;
    total = 0.0f;
    while (p5)
    {
        EffectItem* item = *p5->_ref_006815c0();
        if (!reinterpret_cast<EffectItemDetrimental*>(item)->IsDetrimental())
            total += item->GetCost(actor);
        p5 = static_cast<EffectItemList*>(p5->_ref_00726070());
    }
    return total < DAT_01012060 ? 0.0f : FUN_00404040(total);
}

struct EffectItemListFind
{
    int header;
    EffectItemNode node;
    unsigned char FindEffectItemIndex(int aiFormID);
};

// @fnv 0x00406e70
unsigned char EffectItemListFind::FindEffectItemIndex(int aiFormID)
{
    unsigned char idx3 = 0;
    EffectItemNode* cur = this ? &node : 0;
    while (cur != 0)
    {
        if (aiFormID == (int)*cur->_ref_006815c0())
        {
            return idx3;
        }
        idx3++;
        cur = cur->_ref_00726070();
    }
    _FNV_Warning(
        "GAME EFFECTS: When trying to get an effect item index, the effect item was not found in the effect item list.");
    return 0;
}

struct FaceGenStr
{
    char* pString;
    unsigned short usLen;
    unsigned short usMaxLen;
    FaceGenStr();
    ~FaceGenStr();
    operator const char*() const;
};
int __cdecl FUN_00406f60(FaceGenStr* apStr, const char* apFormat, ...);
void FNV_Warning(const char*);

struct FaceGenModel
{
    unsigned int GetDataSize();
    unsigned int GetTextureSize();
    int GetRefCount();
};

template <class T> struct FaceGenPtr
{
    T* m_pObject;
    FaceGenPtr(T* apObject);
    ~FaceGenPtr();
    operator T*() const;
};

struct FaceGenEntry
{
    int unk00;
    int unk04;
    FaceGenPtr<FaceGenModel> m_pRenderedNodeEntry;
};

struct FaceGenMap
{
    void* GetFirstPos();
    void GetNext(void*& rpPos, const char*& rpKey, FaceGenPtr<FaceGenEntry>& rspVal);
};

struct FaceGenLog
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2c();
    virtual void f30();
    virtual void f34();
    virtual void AddLine(FaceGenStr* apLine, bool abFlag);
};

struct FaceGenCache
{
    int unk00;
    FaceGenMap kMap;
    void FUN_0064fe80(FaceGenLog* apLog);
};

// Iterates the cache map and logs each entry's ref count, key, texture size and data size, warning and optionally adding the line to apLog.
// @fnv 0x0064fe80
void FaceGenCache::FUN_0064fe80(FaceGenLog* apLog)
{
    void* pPos3 = kMap.GetFirstPos();
    const char* pKey2;
    FaceGenPtr<FaceGenEntry> spEntry3(0);
    while (pPos3)
    {
        kMap.GetNext(pPos3, pKey2, spEntry3);
        if (spEntry3)
        {
            FaceGenStr kLine;
            FUN_00406f60(&kLine, "FACEGEN:\t%3d\t%s\t%iKB\t%iKB\r\n",
                         ((FaceGenModel*)((FaceGenEntry*)spEntry3)->m_pRenderedNodeEntry)->GetRefCount() - 1, pKey2,
                         ((FaceGenModel*)((FaceGenEntry*)spEntry3)->m_pRenderedNodeEntry)->GetTextureSize() >> 10,
                         ((FaceGenModel*)((FaceGenEntry*)spEntry3)->m_pRenderedNodeEntry)->GetDataSize() >> 10);
            FNV_Warning(kLine);
            if (apLog)
                apLog->AddLine(&kLine, true);
        }
    }
}

struct Text
{
    char* text;
    unsigned short length;
    unsigned short capacity;
    ~Text();
    operator const char*() const;
};
struct Condition
{
    bool _ref_00680c60(void*, int, bool*, int);
};
struct Setting
{
    bool _ref_00403e60(unsigned int);
};
struct EI
{
    int magnitude;
    int area;
    int duration;
    int range;
    int actorValue;
    bool _ref_00404730();
    Condition* _ref_00409140();
    Setting* _ref_00825c00();
    Text EffectName();
};
struct Node
{
    EI* item;
    Node* next;
    EI** _ref_006815c0();
    Node* _ref_00726070();
};
struct ListBase
{
    Node head;
};
struct TempList : ListBase
{
    virtual void Stub();
    TempList();
    ~TempList();
    void Add(EI*);
};
struct Player
{
    double _ref_008bebb0();
    double _ref_008bec80();
    float _ref_008c4330();
};
extern Player* _g_thePlayer;
void ApplyPerkModifiers(int, Player*, ...);
bool FUN_00406d70(int, int);
float floor(float);
int TruncateFloatToInt(float);
const char* ValueEffectName(int);
int CopyText(char*, unsigned int, const char*);
int strcat_s(char*, unsigned int, const char*);
int sprintf_s(char*, unsigned int, const char*, ...);
struct Description : ListBase
{
    virtual bool First();
    virtual bool Second();
    void BuildDescription(char*, unsigned int);
};
static const char kDurationFormat[] = "%s %+i(%.1f%c)";
// @fnv 0x00406620
void Description::BuildDescription(char* acBuffer, unsigned int size)
{
    char bufferA[128];
    {
        bool s = false;
        TempList p9;
        bool i = First();
        bool hA = Second();
        bool aA = false;
        *acBuffer = 0;
        bufferA[0] = 0;
        for (Node* nodeB = this ? &head : 0; nodeB && *nodeB->_ref_006815c0(); nodeB = nodeB->_ref_00726070())
        {
            if ((*nodeB->_ref_006815c0())->_ref_00404730())
                continue;
            if (!(*nodeB->_ref_006815c0())->_ref_00409140() ||
                (*nodeB->_ref_006815c0())->_ref_00409140()->_ref_00680c60(_g_thePlayer, 0, &s, 0))
            {
                if ((*nodeB->_ref_006815c0())->_ref_00825c00()->_ref_00403e60(0x2000))
                {
                    CopyText(bufferA, 128, (*nodeB->_ref_006815c0())->EffectName());
                    if (aA)
                    {
                        strcat_s(acBuffer, size, "\n");
                        strcat_s(acBuffer, size, bufferA);
                    }
                    else
                    {
                        strcat_s(acBuffer, size, bufferA);
                        aA = true;
                    }
                }
                else
                    p9.Add(*nodeB->_ref_006815c0());
            }
        }
        for (Node* current5 = (Node*)(ListBase*)&p9; current5 && *current5->_ref_006815c0();
             current5 = current5->_ref_00726070())
        {
            if ((*current5->_ref_006815c0())->magnitude && (*current5->_ref_006815c0())->actorValue != -1)
            {
                int iValueVal = (*current5->_ref_006815c0())->actorValue;
                int kAMagnitude = (*current5->_ref_006815c0())->magnitude;
                float pDuration2 = (float)(*current5->_ref_006815c0())->duration;
                char hUnit4 = 's';
                if (pDuration2 >= 3600.0)
                {
                    pDuration2 /= 3600.0;
                    hUnit4 = 'h';
                }
                else if (pDuration2 >= 60.0)
                {
                    pDuration2 /= 60.0;
                    hUnit4 = 'm';
                }
                if (FUN_00406d70(iValueVal, 0x200))
                    kAMagnitude = -kAMagnitude;
                if (i)
                {
                    float scaled5 = kAMagnitude * _g_thePlayer->_ref_008bebb0();
                    if (iValueVal == 16)
                        ApplyPerkModifiers(12, _g_thePlayer, &scaled5);
                    kAMagnitude = (int)scaled5;
                }
                if (hA && iValueVal != 54)
                {
                    float scaledOther4 = kAMagnitude * _g_thePlayer->_ref_008bec80();
                    if (iValueVal == 16)
                        ApplyPerkModifiers(12, _g_thePlayer, &scaledOther4);
                    kAMagnitude = (int)scaledOther4;
                }
                if (iValueVal == 54 && kAMagnitude > 0)
                    kAMagnitude = (int)floor(kAMagnitude * _g_thePlayer->_ref_008c4330());
                if (hA && iValueVal == 54)
                {
                    float multiplier6 = 1.0f;
                    ApplyPerkModifiers(44, _g_thePlayer, &multiplier6);
                    kAMagnitude = (int)(kAMagnitude * multiplier6);
                }
                if (kAMagnitude >= 0 && kAMagnitude < 1)
                    kAMagnitude = 1;
                if (*acBuffer)
                    strcat_s(acBuffer, 128, ", ");
                if ((*current5->_ref_006815c0())->duration)
                {
                    if (pDuration2 != floor(pDuration2))
                        sprintf_s(bufferA, 128, kDurationFormat, ValueEffectName(iValueVal), kAMagnitude, pDuration2,
                                  hUnit4);
                    else
                        sprintf_s(bufferA, 128, "%s %+i(%d%c)", ValueEffectName(iValueVal), kAMagnitude,
                                  TruncateFloatToInt(pDuration2), hUnit4);
                }
                else
                    sprintf_s(bufferA, 128, "%s %+i", ValueEffectName(iValueVal), kAMagnitude);
                strcat_s(acBuffer, size, bufferA);
            }
        }
    }
}
