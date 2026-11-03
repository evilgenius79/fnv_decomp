// bsmenu/tile.cpp: Tile, Tile__FloatAction, LoadingMenu, TileListBoxCalls and more (86 functions)

#include "Tile__FloatAction.h"

// @fnv 0x00a0c000
float Tile__FloatAction::GetStoredFloatValue()
{
    return fValue;
}

#include "tile_packet_decls.h"

// @fnv 0x00a01530
float Tile::GetInterfaceScale()
{
    return Menu::GetMenuScale();
}

// @fnv 0x00a0bae0
bool Tile::IsPointInside(float x,float y)
{
    return true;
}

// @fnv 0x0071aa80
bool Tile::GetSpeechChallengeFailure()
{
    return m_bSpeechChallengeFailure;
}

// @fnv 0x00a04620
void Tile::SetSpeechChallengeFailure(bool recursive)
{
    UpdateAll(false);
}

// Sets the given trait to the integer value cast to float, delegating to the float overload with the third argument true.
// @fnv 0x00700320
void Tile::Set(int trait,int value)
{
    Set(trait,(float)value,true);
}

// @fnv 0x00a03c60
bool Tile::IsMenuRendered()
{
    Menu* menu=GetMenu(); bool rendered=menu->m_bIsSpecial; return rendered;
}

// Returns true if the bit at position trait is set in floatFlags.
// @fnv 0x00458110
bool LoadingMenu::GetFloat(int trait) { return (floatFlags & (1 << trait)) != 0; }

// Returns the element of the given list item and advances pos to the item's previous node.
// @fnv 0x00683520
Tile*& NiTPointerList<Tile*>::GetPrev(NiTListItem<Tile*>*& pos)
{
    Tile*& result=pos->m_element;
    pos=pos->m_pkPrev;
    return result;
}

// Sets the given trait to the given unsigned value by forwarding to the float overload with the third argument true.
// @fnv 0x00715c60
void Tile::Set(int trait,unsigned int value)
{
    Set(trait,(float)value,true);
}

// Returns the float value of the tile's value for the given trait, or 0.0f if no such value exists.
// @fnv 0x00a011b0
float TileListBoxCalls::GetFloat(int trait)
{
    Tile::Value* value=((Tile*)this)->GetValue(trait);
    if (value) { float result=value->fValue; return result; }
    return 0.0f;
}

struct NiStream;
struct blob8 { char b[8]; };
struct NiPoint2 {
    static struct blob8 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float Dot(void*);
    float Unitize();
    static void LoadBinary(NiStream*, NiPoint2*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint2*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float x;
    float y;
};
typedef char _sizecheck_NiPoint2[sizeof(NiPoint2) == 8 ? 1 : -1];
struct FUN_004e8880_shell : public NiPoint2 {
    struct blob8 Subtract();
};

namespace fnv_anon_tile {} using namespace fnv_anon_tile; namespace fnv_anon_tile {
struct NiPoint2_Sub : public NiPoint2 {
    NiPoint2* Subtract(NiPoint2* __ret, const NiPoint2& pt) const;
};
}

// Returns a copy of this NiPoint2 with pt's x and y subtracted from it.
// @fnv 0x004e8880
NiPoint2* NiPoint2_Sub::Subtract(NiPoint2* pResult, const NiPoint2& aPoint) const
{
    NiPoint2 result = *this;
    result.x -= aPoint.x;
    result.y -= aPoint.y;
    *pResult = result;
    return pResult;
}

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern "C" void* __fastcall FUN_00718c90(void*);

struct Dummy_00718c90 {
    char pad[0x10];
    Dummy_00718c90() {
        FUN_00718c90(this);
    }
};

extern Dummy_00718c90* DAT_011d8a88;

// Returns the global Dummy_00718c90 instance, allocating and constructing it first if it is null.
// @fnv 0x00718b60
Dummy_00718c90* __cdecl FUN_00718b60()
{
    if (!DAT_011d8a88)
        DAT_011d8a88 = new Dummy_00718c90;
    return DAT_011d8a88;
}

struct FUN_00a011f0_shell : public Tile {
    char* FUN_00a011f0(int);
};

// @fnv 0x00a011f0
char* FUN_00a011f0_shell::FUN_00a011f0(int trait) {
    Tile::Value* pvalue = GetValue(trait);
    if (pvalue) {
        char* result = *reinterpret_cast<char**>(reinterpret_cast<char*>(pvalue) + 0xc);
        return result;
    }
    return 0;
}

struct FUN_00a01230_shell : public Tile {
    bool IsTraitNonZero(int);
};

// Looks up the Value for aeTrait and returns whether its fValue is non-zero, or false if no Value exists.
// @fnv 0x00a01230
bool FUN_00a01230_shell::IsTraitNonZero(int aeTrait)
{
    Value* pvalue = GetValue(aeTrait);
    if (pvalue)
    {
        float fval = pvalue->fValue;
        return fval != 0.0;
    }
    return false;
}

struct FUN_00a01290_shell : public Tile {
    void SetTraitAndReset(int, float);
};

// Sets the given trait to afValue and then immediately resets it to 0.0f, both with the third argument true.
// @fnv 0x00a01290
void FUN_00a01290_shell::SetTraitAndReset(int aiTrait, float afValue)
{
    Set(aiTrait, afValue, true);
    Set(aiTrait, 0.0f, true);
}

struct FUN_00a013d0_shell : public Tile {
    float GetTotalFloat();
};

// Sums GetFloat(0xfa1) for this tile and each linked tile whose GetFloat(0xfa8) is nonzero, returning the total.
// @fnv 0x00a013d0
float FUN_00a013d0_shell::GetTotalFloat()
{
    float fTotal = GetFloat(0xfa1);
    Tile* ptile = *(Tile**)((char*)this + 0x28);
    while (ptile)
    {
        if (ptile->GetFloat(0xfa8) != 0.0)
        {
            fTotal += ptile->GetFloat(0xfa1);
        }
        ptile = *(Tile**)((char*)ptile + 0x28);
    }
    return fTotal;
}

struct FUN_00a01440_shell : public Tile {
    float GetAccumulatedFloat();
};

extern const double gModifierZero;

// Sums GetFloat(0xfa2) over this tile and its 0x28-linked chain, adding each linked tile's 0xfa2 when its 0xfa8 differs from gModifierZero.
// @fnv 0x00a01440
float FUN_00a01440_shell::GetAccumulatedFloat()
{
    float fTotal = GetFloat(0xfa2);
    Tile* ptile = *(Tile**)((char*)this + 0x28);
    while (ptile != 0)
    {
        if (ptile->GetFloat(0xfa8) != gModifierZero)
        {
            fTotal = ptile->GetFloat(0xfa2) + fTotal;
        }
        ptile = *(Tile**)((char*)ptile + 0x28);
    }
    return fTotal;
}

int __cdecl TraitNameToID(const char*);

// Copies characters before '(' into text and characters inside parentheses into apParam, then passes text to TraitNameToID and returns its result.
// @fnv 0x00a018d0
int __cdecl ParseTextAndParams(const char* apText, char* apParam)
{
    if (!apText || !*apText || !apParam)
        return 0x80000000;

    int iParamIndex = -1;
    char text[256];
    *apParam = 0;
    text[0] = 0;

    for (int a = 0; a < 0xff && apText[a]; ++a)
    {
        apParam[a + 1] = 0;
        text[a + 1] = 0;
        if (apText[a] == '(')
        {
            iParamIndex = 0;
        }
        else if (apText[a] == ')')
        {
            a = 0x100;
        }
        else if (iParamIndex >= 0)
        {
            apParam[iParamIndex] = apText[a];
            ++iParamIndex;
        }
        else
        {
            text[a] = apText[a];
        }
    }

    return TraitNameToID(text);
}

const char* __cdecl strrchr(const char*, int);
long __cdecl FUN_00eca6d3(const char*);

// Finds the last '_' in apTraitName and returns FUN_00eca6d3 of the text after it, -1 if that text is empty, or 0 if there is no '_'.
// @fnv 0x00a01a20
int __cdecl FUN_00a01a20(const char* apTraitName)
{
    const char* plast_ = strrchr(apTraitName, '_');
    if (plast_) {
        return *(plast_ + 1) ? FUN_00eca6d3(plast_ + 1) : -1;
    } else {
        return 0;
    }
}

extern int DAT_011f3330;
__declspec(dllimport) void __stdcall EnterCriticalSection(void* lpCriticalSection);

// @fnv 0x00a044f0
void __cdecl FUN_00a044f0()
{
    EnterCriticalSection(&DAT_011f3330);
}

namespace fnv_00a04500 {
extern _RTL_CRITICAL_SECTION DAT_011f3330;
extern void (__stdcall * const __imp__LeaveCriticalSection)(_RTL_CRITICAL_SECTION *);

// @fnv 0x00a04500
void __cdecl FUN_00a04500()
{
    __imp__LeaveCriticalSection(&DAT_011f3330);
}
}  // namespace fnv_00a04500

struct FUN_00a074d0_shell : public Tile {
    void FUN_00a074d0(int);
};

void __cdecl FUN_00a07690(Tile*);

// @fnv 0x00a074d0
void FUN_00a074d0_shell::FUN_00a074d0(int aiFlag)
{
    if ((unsigned int)aiFlag > 0x3ff) {
        return;
    }
    unsigned int iold = *(unsigned int*)((char*)this + 0x30);
    *(unsigned int*)((char*)this + 0x30) &= 0xfffffc00;
    *(unsigned int*)((char*)this + 0x30) |= aiFlag;
    if (*(unsigned int*)((char*)this + 0x30) != iold) {
        FUN_00a07690(this);
    }
}

struct FUN_00a07530_shell : public Tile {
    void FUN_00a07530(int);
};

void __cdecl FUN_00a07690(Tile*);

// ORs aiFlag into the flags at offset 0x30 when aiFlag is at most 0x3ff, and calls FUN_00a07690 if the flags changed.
// @fnv 0x00a07530
void FUN_00a07530_shell::FUN_00a07530(int aiFlag)
{
    if ((unsigned int)aiFlag > 0x3ff)
        return;
    unsigned int iold = *(unsigned int*)((char*)this + 0x30);
    *(unsigned int*)((char*)this + 0x30) |= aiFlag;
    if (*(unsigned int*)((char*)this + 0x30) != iold)
        FUN_00a07690(this);
}

struct FUN_00a07ed0_shell : public Tile {
    bool FUN_00a07ed0(int);
};

struct FadeControlItem {
    char pad[0x10];
    int m_iValueId;
    Tile* pTile;
};

struct FadeControlNode {
    FadeControlItem* m_item;
    FadeControlNode* m_pkNext;
};

extern FadeControlNode DAT_011f3348;

// Walks the DAT_011f3348 fade-control list and returns true if an item matches aiTrait and points to this tile.
// @fnv 0x00a07ed0
bool FUN_00a07ed0_shell::FUN_00a07ed0(int aiTrait)
{
    for (FadeControlNode* pfade = &DAT_011f3348; pfade && pfade->m_item; pfade = pfade->m_pkNext) {
        if (pfade->m_item->m_iValueId == aiTrait && pfade->m_item->pTile == this) {
            return true;
        }
    }
    return false;
}

namespace fnv_00a07f30 {
struct FUN_00a07f30_shell : public Tile {
    float GetTraitFloat(int);
};

struct FadeItem_00a07f30 {
    int pad0;
    float m_fAlpha;
    int pad8;
    int padC;
    int m_iValueId;
    Tile* pTile;
};

struct FadeNode_00a07f30 {
    FadeItem_00a07f30* m_item;
    FadeNode_00a07f30* m_pkNext;
};

extern FadeNode_00a07f30 DAT_011f3348;

// @fnv 0x00a07f30
float FUN_00a07f30_shell::GetTraitFloat(int aiTrait)
{
    int iendValue = -1;
    for (FadeNode_00a07f30* pfade = &DAT_011f3348; pfade && pfade->m_item; pfade = pfade->m_pkNext) {
        if (pfade->m_item->m_iValueId == aiTrait && pfade->m_item->pTile == this) {
            iendValue = pfade->m_item->m_fAlpha;
        }
    }
    return iendValue == -1.0 ? GetFloat(aiTrait) : iendValue;
}
}  // namespace fnv_00a07f30

namespace fnv_00a07fc0 {
struct FUN_00a07fc0_shell : public Tile {
    bool FUN_00a07fc0(int);
};

__declspec(dllimport) unsigned long __stdcall timeGetTime();

struct FadeControlDummy {
    float fStart;             // +0x00
    float m_fEndValue;               // +0x04
    unsigned int m_uiState; // +0x08
    float fDuration;          // +0x0c
    int m_iValueId;               // +0x10
    Tile* pTile;              // +0x14
    int iType;                // +0x18
};

struct FadeListDummy {
    FadeControlDummy* m_item;
    FadeListDummy* m_pkNext;
};

extern FadeListDummy DAT_011f3348;

// @fnv 0x00a07fc0
bool FUN_00a07fc0_shell::FUN_00a07fc0(int aiTrait)
{
    for (FadeListDummy* pfade = &DAT_011f3348; pfade && pfade->m_item; pfade = pfade->m_pkNext)
    {
        if (pfade->m_item->m_iValueId == aiTrait && pfade->m_item->pTile == this)
        {
            if (pfade->m_item->iType != 1)
            {
                unsigned int now = timeGetTime();
                return ((float)(now - pfade->m_item->m_uiState) / pfade->m_item->fDuration >= 1.0) ? true : false;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
}  // namespace fnv_00a07fc0

struct NiNode;
struct TileX {
    char pad[0x28];
    TileX* pParent;
    NiNode* m_pRenderedNodeEntry;
    NiNode* GetNiNode();
};
// Walks up the parent chain until a tile with a non-null NiNode is found and returns that NiNode, or null if none exists.
// @fnv 0x00a089c0
NiNode* TileX::GetNiNode()
{
    TileX* ptile = this;
    NiNode* m;
    while (ptile && (m = ptile->m_pRenderedNodeEntry, !m)) {
        ptile = ptile->pParent;
    }
    if (ptile) {
        NiNode* a = ptile->m_pRenderedNodeEntry;
        if (a) {
            NiNode* b = ptile->m_pRenderedNodeEntry;
            return b;
        }
    }
    return 0;
}

struct FUN_00a0a0b0_shell : public Tile {
    void* FUN_00a0a0b0(int, int);
};

const char* __cdecl FUN_00a01a70(int);
int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
int __cdecl TraitNameToID(const char*);

// Builds a value name from the base trait name and ID, then returns the value looked up by that name.
// @fnv 0x00a0a0b0
void* FUN_00a0a0b0_shell::FUN_00a0a0b0(int aiBaseTrait, int aiID)
{
    char strValueName[260];
    const char* strBaseName = FUN_00a01a70(aiBaseTrait);
    _sprintf_s(strValueName, sizeof(strValueName), "%s%d", strBaseName, aiID);
    return GetValue(TraitNameToID(strValueName));
}

struct MemoryManager { void Deallocate(void* p); };
extern MemoryManager g_memoryManager;
struct Tile3DStub {
    void FUN_00a20650();
    Tile3DStub* FUN_00a0bde0(unsigned int flags);
};
// Calls FUN_00a20650, deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00a0bde0
Tile3DStub* Tile3DStub::FUN_00a0bde0(unsigned int flags)
{
    FUN_00a20650();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

namespace fnv_00a0be10 {
struct MenuValueDescriptor {
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiValueId;
    char* m_pName;
};
typedef char _sizecheck_XMLStorage[sizeof(MenuValueDescriptor) == 8 ? 1 : -1];
struct FUN_00a0be10_shell : public MenuValueDescriptor {
    void FUN_00a0be10();
};

struct MemoryManager { void Deallocate(void*); };
extern MemoryManager g_memoryManager;
struct XMLStorageX : public MenuValueDescriptor {
    MenuValueDescriptor* FUN_00a0be10(unsigned int flags);
};
// @fnv 0x00a0be10
MenuValueDescriptor* XMLStorageX::FUN_00a0be10(unsigned int flags)
{
    if (m_pName) {
        char* p = m_pName;
        g_memoryManager.Deallocate(p);
    }
    m_pName = 0;
    if (flags & 1) {
        g_memoryManager.Deallocate(this);
    }
    return this;
}
}  // namespace fnv_00a0be10

void __cdecl FUN_00a07690(Tile*);
struct TV { bool IsVisible(); };
struct XL { void* head; void* RemovePos(void*&); };
extern XL DAT_011f3324;
// Iterates the tile list, and for each visible tile clears flags 0x800 and 0x1000, calls FUN_00a07690, and removes it from the list.
// @fnv 0x00a078e0
void FUN_00a078e0()
{
    void* xelem = DAT_011f3324.head;
    while (xelem) {
        Tile* ptile = *(Tile**)((char*)xelem + 8);
        char pad[0x20];
        if (((TV*)ptile)->IsVisible()) {
            0 ? (*(unsigned int*)((char*)ptile + 0x30) |= 0x800) : (*(unsigned int*)((char*)ptile + 0x30) &= ~0x800);
            0 ? (*(unsigned int*)((char*)ptile + 0x30) |= 0x1000) : (*(unsigned int*)((char*)ptile + 0x30) &= ~0x1000);
            FUN_00a07690(ptile);
            DAT_011f3324.RemovePos(xelem);
        } else {
            xelem = xelem ? *(void**)xelem : 0;
        }
    }
}

struct FUN_00a079d0_shell : public Tile {
    void UpdateTileChildren();
};

struct ListNode_00a079d0 {
    ListNode_00a079d0* next;
    void* prev;
    Tile* item;
};

// Walks the linked list at this+4 and, for each Tile, calls FUN_00a07530(0x80) if IsTraitNonZero(0xfa6) is true, otherwise recurses into UpdateTileChildren.
// @fnv 0x00a079d0
void FUN_00a079d0_shell::UpdateTileChildren()
{
    ListNode_00a079d0* kPos;
    Tile* pitem;
    {
        ListNode_00a079d0* head = *(ListNode_00a079d0**)((char*)this + 4);
        kPos = head;
    }
    while (kPos) {
        Tile** xelem = &kPos->item;
        kPos = kPos->next;
        pitem = *xelem;
        if (((FUN_00a01230_shell*)pitem)->IsTraitNonZero(0xfa6))
            ((FUN_00a07530_shell*)pitem)->FUN_00a07530(0x80);
        else
            ((FUN_00a079d0_shell*)pitem)->UpdateTileChildren();
    }
}

namespace fnv_00a0a270 {
struct MemoryManager { void Deallocate(void*); };
extern MemoryManager g_memoryManager;
struct VX { char pad[8]; float fValue; void* ptr; void RemoveFromReactions(); void Refresh(bool); };
struct BW { bool v; };
struct FW { float f; };
// Stores afValue.f into fValue, frees ptr if set, optionally calls RemoveFromReactions, then calls Refresh with whether the value changed or ptr was non-null.
// @fnv 0x00a0a270
void __fastcall FUN_00a0a270(VX* self, FW afValue, BW abClearActions)
{
    bool bforceUpdate = self->fValue != afValue.f || self->ptr != 0;
    self->fValue = afValue.f;
    if (self->ptr) {
        void* p = self->ptr;
        g_memoryManager.Deallocate(p);
        self->ptr = 0;
    }
    if (abClearActions.v)
        self->RemoveFromReactions();
    self->Refresh(bforceUpdate);
}
}  // namespace fnv_00a0a270

struct FUN_009ff600_shell : public Tile {
    void InitTile(Tile*, char*, Tile*);
};

struct StrMem { bool Set(const char*, unsigned int); };
struct NP_0081c630 { NP_0081c630& operator=(void*); };
struct TileStandIn_009ff600 { void SetParent(Tile*, Tile*); };

// @fnv 0x009ff600
void FUN_009ff600_shell::InitTile(Tile* apParent, char* apName, Tile* apReplacedTile)
{
    *(Tile**)((char*)this + 0x28) = 0;
    ((NP_0081c630*)((char*)this + 0x2c))->operator=(0);
    {
        int aiPad1[10];
        StrMem* pName = (StrMem*)((char*)this + 0x20);
        pName->Set("", 0);
    }
    *((char*)this + 0x35) = 0;
    *(unsigned int*)((char*)this + 0x30) = 0;
    if (apParent)
        ((TileStandIn_009ff600*)this)->SetParent(apParent, apReplacedTile);
    if (apName)
    {
        int aiPad1[8];
        StrMem* pName = (StrMem*)((char*)this + 0x20);
        pName->Set(apName, 0);
    }
}

struct FUN_00a00e90_shell : public Tile {
    void* FindTraitValue(int);
};

extern int DAT_011f3330;
__declspec(dllimport) void __stdcall EnterCriticalSection(void*);
__declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
// @fnv 0x00a00e90
void* FUN_00a00e90_shell::FindTraitValue(int aiTrait)
{
 unsigned int uiIndex;
 {
 Tile::Value* pFoundValue;
 {
 unsigned int uiSizeA;
 {
 unsigned int uiSizeB;
    pFoundValue = 0;
    uiIndex = 0;
    EnterCriticalSection(&DAT_011f3330);
    while ((uiSizeA = *(unsigned int*)((char*)this + 0x18), uiIndex < uiSizeA)
           && (*(Tile::Value***)((char*)this + 0x14))[uiIndex]->m_iValueId < aiTrait)
        uiIndex++;
    if ((uiSizeB = *(unsigned int*)((char*)this + 0x18), uiIndex < uiSizeB)
        && (*(Tile::Value***)((char*)this + 0x14))[uiIndex]->m_iValueId == aiTrait)
        pFoundValue = (*(Tile::Value***)((char*)this + 0x14))[uiIndex];
    LeaveCriticalSection(&DAT_011f3330);
    return pFoundValue;
 }
 }
 }
}

namespace fnv_00a01000 {
struct FUN_00a01000_shell : public Tile {
    void* GetOrCreateTraitValue(int);
};

struct MemoryManager { void* Allocate(unsigned int); };
extern MemoryManager g_memoryManager;
struct P09Value { int m_uiSoundID; void* pParent; float fValue; void* p0c; void* p10; };
int __cdecl FUN_00a01160(const void*, const void*);
void __cdecl FUN_00fda2a0();
int __cdecl _atexit(void (__cdecl*)());
struct P09Traits {
    unsigned int BinarySearch(P09Value*&, int (__cdecl*)(const void*, const void*));
    void InsertInSortedOrder(P09Value*&, int (__cdecl*)(const void*, const void*));
};
extern int DAT_011f3330;
__declspec(dllimport) void __stdcall EnterCriticalSection(void*);
__declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern int DAT_011f338c;
extern void* DAT_011f3390;
extern float DAT_011f3394;
extern void* DAT_011f3398;
extern void* DAT_011f339c;
extern unsigned int DAT_011f33a0;
// Looks up a P09Value by aiTrait in the map at this+0x10, allocating and inserting a new one if absent, under a critical section.
// @fnv 0x00a01000
void* FUN_00a01000_shell::GetOrCreateTraitValue(int aiTrait)
{
    P09Value* preturnVal = 0;
    EnterCriticalSection(&DAT_011f3330);
    if (!(DAT_011f33a0 & 1)) {
        DAT_011f33a0 |= 1;
        DAT_011f338c = 0x80000000;
        DAT_011f3390 = 0;
        DAT_011f3394 = 0.0f;
        DAT_011f3398 = 0;
        DAT_011f339c = 0;
        _atexit(FUN_00fda2a0);
    }
    unsigned int uifoundIndex = (unsigned int)-1;
    DAT_011f338c = aiTrait;
    {
        P09Value* pSearchKey = (P09Value*)&DAT_011f338c;
        uifoundIndex = ((P09Traits*)((char*)this + 0x10))->BinarySearch(pSearchKey, FUN_00a01160);
    }
    if (uifoundIndex != (unsigned int)-1) {
        preturnVal = (*(P09Value***)((char*)this + 0x14))[uifoundIndex];
    } else {
        P09Value* pNew = (P09Value*)g_memoryManager.Allocate(0x14);
        P09Value* pInitValue = pNew ? (pNew->m_uiSoundID = 0x80000000, pNew->pParent = 0, pNew->fValue = 0.0f,
            pNew->p0c = 0, pNew->p10 = 0, pNew) : 0;
        preturnVal = pInitValue;
        preturnVal->m_uiSoundID = aiTrait;
        preturnVal->pParent = this;
        ((P09Traits*)((char*)this + 0x10))->InsertInSortedOrder(preturnVal, FUN_00a01160);
    }
    LeaveCriticalSection(&DAT_011f3330);
    return preturnVal;
}
}  // namespace fnv_00a01000

struct FUN_00a031b0_shell : public Tile {
    Tile* CreateMenuTiles(void*);
};

struct P09Item { int eType; float fValue; void* pName; int i0c; Tile* pTile; };
struct P09VTile { virtual void f0(); virtual void Init(Tile*, void*, int); };
struct P09TileS { void Set(int, const char*, bool); void SetImageFlags(int); };
struct P09Setting { void* pVtbl; const char* volatile pValue; };
extern P09Setting g_011f3368;
extern double DAT_01094a80;
Tile* __cdecl FUN_00a00c20(int);
void __cdecl _FNV_Warning(const char*, ...);
// @fnv 0x00a031b0
Tile* FUN_00a031b0_shell::CreateMenuTiles(void* apTemplate)
{
 Tile* pfirst_tile;
 {
 P09Item* pitem;
 {
 char* xelem;
 {
 Tile* pparent;
 {
 Tile* ptile;
    pparent = this;
    pfirst_tile = 0;
    {
        char* pHead = *(char**)((char*)apTemplate + 8);
        xelem = pHead;
    }
    pitem = 0;
    while (xelem) {
        {
            P09Item** ppData = (P09Item**)(xelem + 8);
            xelem = *(char**)xelem;
            pitem = *ppData;
        }
        if (pitem->eType == 6) {
            ptile = FUN_00a00c20((int)pitem->fValue);
            if (!ptile) {
                _FNV_Warning("MENUS: Unable to create tile. Aborting menu creation.");
                return 0;
            }
            {
                void* pName = pitem->pName;
                ((P09VTile*)ptile)->Init(pparent, pName, 0);
            }
            if (pitem->fValue == DAT_01094a80) {
                ptile->Set(0xfaa, -1.0f, true);
                ptile->Set(0xfaf, 1.0f, true);
                ptile->Set(0xff5, -1.0f, true);
                ptile->Set(0xfb2, 255.0f, true);
                ptile->Set(0xfb3, 255.0f, true);
                ptile->Set(0xfb4, 255.0f, true);
                ptile->Set(0xfa9, 0.0f, true);
                ((P09TileS*)ptile)->Set(0xfcc, "solid.dds", true);
                ((P09TileS*)ptile)->Set(0xff9, &g_011f3368 ? g_011f3368.pValue : 0, true);
                ((P09TileS*)ptile)->SetImageFlags(0x20);
            }
            if (!pfirst_tile)
                pfirst_tile = ptile;
            pitem->pTile = ptile;
            pparent = ptile;
        } else if (pitem->eType == 7) {
            pparent = *(Tile**)((char*)pparent + 0x28);
        }
    }
    return pfirst_tile;
 }
 }
 }
 }
}

struct EmptyPolymorphicObject {
    void* __vecDelDtor(unsigned int);
    char _pad_0[1];
};
typedef char _sizecheck_AutoTileLock[sizeof(EmptyPolymorphicObject) == 1 ? 1 : -1];
struct FUN_00a03d40_shell : public Tile {
    Tile* FUN_00a03d40();
};

void __cdecl FUN_00a044f0();
namespace fnv_00a04500 { void __cdecl FUN_00a04500(); }

// @fnv 0x00a03d40
Tile* FUN_00a03d40_shell::FUN_00a03d40()
{
    FUN_00a044f0();
    Tile* ptile = this;
    EmptyPolymorphicObject lock;
    Tile* r;
    {
        Tile* a;
        Tile* b;
        Tile* c;
        while (ptile && (a = *(Tile**)((char*)ptile + 0x28)) != 0
               && (c = *(Tile**)((char*)(b = *(Tile**)((char*)ptile + 0x28)) + 0x28)) != 0)
            ptile = *(Tile**)((char*)ptile + 0x28);
    }
    r = ptile;
    fnv_00a04500::FUN_00a04500();
    return r;
}

namespace fnv_00a077c0 {
struct NiTPointerListBase_00a077c0 { int iVal; void* AddHead(); };
extern NiTPointerListBase_00a077c0 DAT_011f332c;
struct FUN_004ed8c0_shell_00a077c0 { void FUN_00559a70(void*); };
extern FUN_004ed8c0_shell_00a077c0 DAT_011f3324;
extern int DAT_011f32d8;
extern void** DAT_011f3328;

// If apTile is valid, lacks flag 0x800 and is not the excluded list entry, adds it to DAT_011f332c, increments DAT_011f32d8, sets flag 0x800 and clears 0x1000.
// @fnv 0x00a077c0
void FUN_00a077c0(Tile* apTile)
{
    void* pNode;
    {
    int iUnused;
    {
    Tile* pTile1;
    {
    Tile* pTile2;
    {
    unsigned int uiFlags1;
    {
    unsigned int uiFlags2;
    if (apTile && !(bool)(int)((*(unsigned int*)((char*)apTile + 0x30) & 0x800) != 0)
        && ((bool)(int)(DAT_011f332c.iVal == 0) || apTile != DAT_011f3328[2]))
    {
        DAT_011f32d8++;
        pNode = DAT_011f332c.AddHead();
        ((void**)pNode)[2] = apTile;
        DAT_011f3324.FUN_00559a70(pNode);
        pTile1 = apTile;
        if (1)
        {
            *(unsigned int*)((char*)pTile1 + 0x30) |= 0x800;
            uiFlags1 = *(unsigned int*)((char*)pTile1 + 0x30);
        }
        else
        {
            *(unsigned int*)((char*)pTile1 + 0x30) &= ~0x800;
            uiFlags1 = *(unsigned int*)((char*)pTile1 + 0x30);
        }
        pTile2 = apTile;
        if (0)
        {
            *(unsigned int*)((char*)pTile2 + 0x30) |= 0x1000;
            uiFlags2 = *(unsigned int*)((char*)pTile2 + 0x30);
        }
        else
        {
            *(unsigned int*)((char*)pTile2 + 0x30) &= ~0x1000;
            uiFlags2 = *(unsigned int*)((char*)pTile2 + 0x30);
        }
    }
    }
    }
    }
    }
    }
}
}  // namespace fnv_00a077c0

namespace fnv_00a07c60 {
struct FUN_00a07c60_shell : public Tile {
    void StartFade(int, float, float, float, int);
};

struct MemoryManager { void* Allocate(unsigned int); };
extern MemoryManager g_memoryManager;
struct P09Fade { float fStart; float m_fEndValue; unsigned long m_uiState; float fScaleMultiplier; int m_iValueId; Tile* pTile; int eType; };
struct FUN_00a0c7c0_Helper { void AddToHead(P09Fade**); };
extern FUN_00a0c7c0_Helper DAT_011f3348;
struct P09TileFade { void UpdateTrait(int); };
int __cdecl GetTileValueID(const char*, int);
extern double DAT_01011588;
extern double _gModifierZero;
__declspec(dllimport) unsigned long __stdcall GetTickCount();
// Starts a fade on this tile: allocates a P09Fade, fills start/end/length/type and tick, sets flash traits for types 2 and 3, then queues it via DAT_011f3348.
// @fnv 0x00a07c60
void FUN_00a07c60_shell::StartFade(int aiTrait, float afStart, float afEnd, float afLength, int aeFadeType)
{
    P09Fade* pFade;
    if (afStart != afEnd && afLength > _gModifierZero) {
        float ftotalFlashes;
        ((P09TileFade*)this)->UpdateTrait(aiTrait);
        {
            void* pMem = g_memoryManager.Allocate(0x1c);
            pFade = (P09Fade*)pMem;
        }
        pFade->pTile = this;
        pFade->m_iValueId = aiTrait;
        pFade->fStart = afStart;
        pFade->m_fEndValue = afEnd;
        pFade->fScaleMultiplier = afLength * 1000.0;
        {
            unsigned long ulFadeStartTimeTick = GetTickCount();
            pFade->m_uiState = ulFadeStartTimeTick;
        }
        pFade->eType = aeFadeType;
        if (aeFadeType == 3) {
            ftotalFlashes = afLength / DAT_01011588;
            int iFlash = GetTileValueID("_FlashCount", -1);
            Set(iFlash, 0.0f, true);
            Set(GetTileValueID("_TotalFlashCount", -1), ftotalFlashes - 2.0, true);
            pFade->fScaleMultiplier = afLength / ftotalFlashes * 1000.0;
        }
        if (aeFadeType == 2) {
            int iFlash2 = GetTileValueID("_FlashCount", -1);
            Set(iFlash2, 0.0f, true);
        }
        DAT_011f3348.AddToHead(&pFade);
        {
            int iPad0, iPad1, iPad2;
        }
    }
}
}  // namespace fnv_00a07c60

namespace fnv_00a07dc0 {
struct FUN_00a07dc0_shell : public Tile {
    void RemoveFadeItemsForTile(int);
};

class MemoryManager { public: void Deallocate(void*); };
extern MemoryManager g_memoryManager;
struct P03FadeItem { char pad[0x10]; int m_iValueId; Tile* pTile; };
struct P03FadeNode { P03FadeItem* item; P03FadeNode* next; };
struct P03FadeList { P03FadeItem* item; P03FadeNode* next; void FUN_00a0cbe0(P03FadeItem**); };
extern P03FadeList DAT_011f3348;
struct FUN_00a0c7c0_Helper { void AddToHead(Tile__TileTemplate**); };
struct FUN_00ae83e0 { P03FadeItem* item; P03FadeNode* next; ~FUN_00ae83e0(); };
// @fnv 0x00a07dc0
void FUN_00a07dc0_shell::RemoveFadeItemsForTile(int aiTrait)
{
    FUN_00ae83e0 ptoBeDeleted = { 0, 0 };
    P03FadeNode* removeList;
    P03FadeNode* pDel;
    P03FadeItem* pfade;
    void* premove;
    for (removeList = (P03FadeNode*)&DAT_011f3348; removeList && removeList->item; removeList = removeList->next) {
        if ((removeList->item->m_iValueId == aiTrait || aiTrait == (int)0x80000000) && removeList->item->pTile == this)
            ((FUN_00a0c7c0_Helper*)&ptoBeDeleted)->AddToHead((Tile__TileTemplate**)removeList);
    }
    for (pDel = (P03FadeNode*)&ptoBeDeleted; pDel && pDel->item; pDel = pDel->next) {
        pfade = pDel->item;
        DAT_011f3348.FUN_00a0cbe0(&pfade);
        premove = pfade;
        g_memoryManager.Deallocate(premove);
    }
    { struct P03Pad { int a[18]; } aiPad; }
    ((BSSimpleList<unsigned char*>*)&ptoBeDeleted)->RemoveAll();
}
}  // namespace fnv_00a07dc0

int __cdecl __stricmp(const char*, const char*);
struct P03Node { P03Node* next; P03Node* prev; Tile* data; };
// Recursively searches apTarget and its linked child tiles for one whose name matches apName case-insensitively, returning the match or null.
// @fnv 0x00a08f20
Tile* __cdecl FindTileByName(Tile* apTarget, const char* apName)
{
    Tile* xelem;
    P03Node* pitem;
    if (!apTarget)
        return 0;
    {
        const char* pTileName = *(const char**)((char*)apTarget + 0x20);
        if (pTileName) {
            const char* pTileName2 = *(const char**)((char*)apTarget + 0x20);
            if (!__stricmp(pTileName2, apName))
                return apTarget;
        }
    }
    {
        P03Node* pHead = *(P03Node**)((char*)apTarget + 4);
        pitem = pHead;
    }
    while (pitem) {
        Tile** ppData = &pitem->data;
        pitem = pitem->next;
        xelem = FindTileByName(*ppData, apName);
        if (xelem)
            return xelem;
    }
    return 0;
}

extern MemoryManager g_memoryManager;
extern void* DAT_01094c2c;
extern void* DAT_01094c38;
struct P03MM { void* Allocate(unsigned int); };
struct P03Value { void AppendFloatAction(int aiActionType, float afValue); };
// Allocates a Tile__FloatAction with the given action type and value, then appends it to the end of the action list at this+0x10 or sets it as the head.
// @fnv 0x00a09080
void P03Value::AppendFloatAction(int aiActionType, float afValue)
{
    Tile__Action* pNew = *(Tile__Action**)((char*)this + 0x10);
    Tile__FloatAction* pMem;
    void* ptail = ((P03MM*)&g_memoryManager)->Allocate(0x10);
    Tile__FloatAction* pnewAction = ptail ? (((Tile__Action*)ptail)->m_ppVirtualMethodTable = (void**)&DAT_01094c38,
        ((Tile__Action*)ptail)->eActionType = (Tile__VALUE_ACTION)2000,
        ((Tile__Action*)ptail)->m_pActionSuccessor = 0,
        ((Tile__Action*)ptail)->m_ppVirtualMethodTable = (void**)&DAT_01094c2c,
        (Tile__FloatAction*)ptail) : 0;
    pMem = pnewAction;
    pMem->eActionType = (Tile__VALUE_ACTION)aiActionType;
    pMem->fValue = afValue;
    if (pNew) {
        while (pNew->m_pActionSuccessor)
            pNew = pNew->m_pActionSuccessor;
        pNew->m_pActionSuccessor = pMem;
    } else {
        *(Tile__Action**)((char*)this + 0x10) = pMem;
    }
}

namespace fnv_00a09200 {
struct MemoryManager_00a09200 { void Deallocate(void*); };
extern MemoryManager_00a09200 g_memoryManager;
struct Value_00a09200;
struct Reaction_00a09200 { Value_00a09200* pValue; Reaction_00a09200* pNext; };
struct Action_00a09200 {
    virtual void v0();
    virtual unsigned long GetRef();
    int iType;
    Action_00a09200* pNext;
};
struct BSMapBase_00a09200 {
    bool GetAt(unsigned long, Reaction_00a09200*&);
    void FUN_00a1e240(unsigned long);
    void InsertOrUpdate(unsigned long, Reaction_00a09200*);
};
extern BSMapBase_00a09200 DAT_011f3358;
struct Value_00a09200 {
    void RemoveFromReactions();
};

// Walks the action list, removes this value from each referenced reaction list, updates or clears the map entry, and deletes the actions.
// @fnv 0x00a09200
void Value_00a09200::RemoveFromReactions()
{
    Action_00a09200* pcurrAction;
    {
    Action_00a09200** ppcurrAction;
    {
    Reaction_00a09200* preactionListA;
    {
    Reaction_00a09200* pcurrReaction;
    {
    Reaction_00a09200** ppcurrReaction;
    {
    Reaction_00a09200* pOriginalHead;
    {
    void* pDeletedReaction;
    {
    void* pDeletedAction;
    {
    int aiPad[8];
    {
    int iActionIndex;
    ppcurrAction = (Action_00a09200**)((char*)this + 0x10);
    while ((pcurrAction = *ppcurrAction) != 0)
    {
        if (pcurrAction->GetRef())
        {
            preactionListA = 0;
            if (DAT_011f3358.GetAt(pcurrAction->GetRef(), preactionListA))
            {
                ppcurrReaction = &preactionListA;
                pOriginalHead = *ppcurrReaction;
                while ((pcurrReaction = *ppcurrReaction) != 0)
                {
                    if (pcurrReaction->pValue != this)
                    {
                        ppcurrReaction = &pcurrReaction->pNext;
                    }
                    else
                    {
                        *ppcurrReaction = pcurrReaction->pNext;
                        pDeletedReaction = pcurrReaction;
                        g_memoryManager.Deallocate(pDeletedReaction);
                    }
                }
                if (!preactionListA)
                    DAT_011f3358.FUN_00a1e240(pcurrAction->GetRef());
                else if (preactionListA != pOriginalHead)
                    DAT_011f3358.InsertOrUpdate(pcurrAction->GetRef(), preactionListA);
            }
        }
        *ppcurrAction = pcurrAction->pNext;
        pDeletedAction = pcurrAction;
        g_memoryManager.Deallocate(pDeletedAction);
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
}
}  // namespace fnv_00a09200

namespace fnv_00a0ab70 {
struct MemoryManager { void Deallocate(void*); };
extern MemoryManager g_memoryManager;
struct StrMem { bool Set(char const*, unsigned int); char pad[8]; };
struct SoundMessageRecord {
    char pad[8];
    StrMem str;
};
struct OH2List {
    SoundMessageRecord* RemoveHead();
    char pad[8];
    unsigned int count;
};
struct OH2TileTemplate {
    char pad[8];
    OH2List list;
    void ClearList();
};
// @fnv 0x00a0ab70
void OH2TileTemplate::ClearList()
{
    SoundMessageRecord* p;
    {
        SoundMessageRecord* pMsg;
        {
            unsigned int count;
            {
                int inl[13];
                while ((count = list.count) != 0) {
                    pMsg = list.RemoveHead();
                    p = pMsg;
                    p ? (p->str.Set(0, 0), (((0, 1) & 1) ? g_memoryManager.Deallocate(p) : (void)0), p) : 0;
                }
            }
        }
    }
}
}  // namespace fnv_00a0ab70

__declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct NiGlobalStringTable { static char* __cdecl AddString(const char*); };
int __cdecl FUN_00ec6da0(const char*, const char*);
extern char* EmptyFS;
struct TileTemplate_00a0af10 { char* m_kName; };
struct TemplateList_00a0af10 { TileTemplate_00a0af10* pItem; TemplateList_00a0af10* pNext; };

struct BuildStorage_00a0af10
{
    char pad[4];
    TileTemplate_00a0af10* FindTemplateByName(const char* pName);
};

// Looks up a template in the list at this+4 by name, comparing interned strings, and returns the matching template or null.
// @fnv 0x00a0af10
TileTemplate_00a0af10* BuildStorage_00a0af10::FindTemplateByName(const char* pName)
{
    char* nm;
    {
    TemplateList_00a0af10* pNode;
    {
    TileTemplate_00a0af10* pResult;
    {
    TileTemplate_00a0af10* pZero;
    {
    char* pOther;
    {
    TileTemplate_00a0af10* pTemplate;
    {
    bool bEqual;
    {
    long* pRef1;
    {
    long* pRef2;
    pNode = (TemplateList_00a0af10*)((char*)this + 4);
    if (!pName)
        nm = EmptyFS;
    else
        nm = NiGlobalStringTable::AddString(pName);
    while (pNode && pNode->pItem)
    {
        pTemplate = pNode->pItem;
        pOther = pTemplate->m_kName;
        if (nm == pOther)
            bEqual = true;
        else if (!pOther || !nm)
            bEqual = false;
        else
            bEqual = FUN_00ec6da0(nm, pOther) == 0;
        if (bEqual)
        {
            pResult = pNode->pItem;
            if (nm == EmptyFS)
            {
            }
            else
            {
                pRef1 = (long*)(nm - 8);
                InterlockedDecrement(pRef1);
            }
            return pResult;
        }
        pNode = pNode->pNext;
    }
    pZero = 0;
    if (nm == EmptyFS)
    {
    }
    else
    {
        pRef2 = (long*)(nm - 8);
        InterlockedDecrement(pRef2);
    }
    return pZero;
    }
    }
    }
    }
    }
    }
    }
    }
}

struct RgbaColor;
struct NiNode;
struct NiStream;
struct NiTexture;
struct TileShaderProperty;
struct blob4 { char b[4]; };
struct FUN_00a0b280_shell : public Tile {
    void ApplyAlphaAndColorToChildren(NiNode*, float, void*);
};

struct PropHelper { void* GetProperty(unsigned int); };
struct OH3Color { float r, g, b, a; };
struct OH3Child {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual PropHelper* v6();
};
// @fnv 0x00a0b280
void FUN_00a0b280_shell::ApplyAlphaAndColorToChildren(NiNode* apNode, float afAlpha, void* apColor)
{
    if (!apNode)
        return;
    for (unsigned int ui = 0; ui < *(unsigned short*)((char*)apNode + 0xa6); ui++) {
        OH3Child* pchild;
        PropHelper* pgeom;
        {
            void* pprop;
            char* ptsp;
            {
                OH3Child** pa = &(*(OH3Child***)((char*)apNode + 0xa0))[ui];
                {
                    OH3Child* pv = *pa;
                    pchild = pv;
                }
            }
            pgeom = pchild ? pchild->v6() : 0;
            if (pgeom) {
                pprop = pgeom->GetProperty(3);
                ptsp = (char*)pprop;
                *(float*)(ptsp + 0x78) = afAlpha;
                *(OH3Color*)(ptsp + 0x68) = *(OH3Color*)apColor;
            }
        }
    }
}

struct FUN_00a00f30_shell : public Tile {
    void* FUN_00a00f30(int);
};

extern int DAT_011f3330;
int __cdecl _atexit(void (__cdecl*)());
int __cdecl FUN_00a01160(const void*, const void*);
void __cdecl FUN_00fda290();
extern void (__stdcall *DAT_00fdf05c)(void*);
extern void (__stdcall *DAT_00fdf100)(void*);
extern unsigned int DAT_011f3388;
extern unsigned int DAT_011f3374;
extern int DAT_011f3378;
extern float DAT_011f337c;
extern int DAT_011f3380;
extern int DAT_011f3384;

template<> class BSSimpleArray<Tile::Value*,8> {
public:
    void** m_ppVirtualMethodTable; Tile::Value** pBuffer; unsigned int iSize; unsigned int SimpleArrayStorage;
    unsigned int BinarySearch(Tile::Value*&, int (__cdecl*)(const void*, const void*));
};

// Locks a global, stores aiTrait in it, looks up the matching Tile::Value in the array at offset 0x10 and returns it, or null if not found.
// @fnv 0x00a00f30
void* FUN_00a00f30_shell::FUN_00a00f30(int aiTrait)
{
    Tile::Value* preturnVal = 0;
    DAT_00fdf05c(&DAT_011f3330);
    if (!(DAT_011f3388 & 1)) {
        DAT_011f3388 |= 1;
        DAT_011f3374 = 0x80000000;
        DAT_011f3378 = 0;
        DAT_011f337c = 0.0f;
        DAT_011f3380 = 0;
        DAT_011f3384 = 0;
        _atexit(FUN_00fda290);
    }
    unsigned int uifoundIndex = 0xffffffff;
    DAT_011f3374 = aiTrait;
    {
        Tile::Value* pkey = (Tile::Value*)&DAT_011f3374;
        uifoundIndex = ((BSSimpleArray<Tile::Value*,8>*)((char*)this + 0x10))->BinarySearch(pkey, FUN_00a01160);
    }
    if (uifoundIndex != 0xffffffff)
        preturnVal = (*(Tile::Value***)((char*)this + 0x14))[uifoundIndex];
    DAT_00fdf100(&DAT_011f3330);
    return preturnVal;
}

namespace fnv_00a09330 {
class MemoryManager { public: void Deallocate(void*); };
extern MemoryManager g_memoryManager;
struct ScrapHeapBuffer;
template<class K, class V> struct BSMapBase {
    bool GetAt(K, V&);
    void FUN_00a1e240(K);
};
extern BSMapBase<unsigned long, ScrapHeapBuffer*> DAT_011f3358;
struct Action_00a09330 {
    virtual void v0();
    virtual void* GetValue();
    int pad4;
    Action_00a09330* pNext;
    void* pValue;
};
struct Reaction_00a09330 { char pad[0x10]; Action_00a09330* pActions; };
struct Node_00a09330 { Reaction_00a09330* pData; Node_00a09330* pNext; };
struct FUN_00a09330_shell {
    int m_iValueId;
    int iVal4;
    float fValue;
    void* pBuf;
    void RemoveFromReactions();
    void ClearActionsAndFreeBuffer();
};
// Calls RemoveFromReactions, clears matching action values and frees the preaction list nodes, then frees pBuf and resets fValue and iVal4.
// @fnv 0x00a09330
void FUN_00a09330_shell::ClearActionsAndFreeBuffer()
{
    Node_00a09330* preactionListA = 0;
    RemoveFromReactions();
    if (DAT_011f3358.GetAt((unsigned long)this, (ScrapHeapBuffer*&)preactionListA)) {
        while (preactionListA) {
            Action_00a09330* pcurrAction = preactionListA->pData->pActions;
            while (pcurrAction) {
                if (pcurrAction->GetValue() == this)
                    pcurrAction->pValue = 0;
                pcurrAction = pcurrAction->pNext;
            }
            Node_00a09330* premove = preactionListA;
            preactionListA = preactionListA->pNext;
            {
                void* pMem = premove;
                g_memoryManager.Deallocate(pMem);
            }
        }
        DAT_011f3358.FUN_00a1e240((unsigned long)this);
    }
    if (pBuf) {
        void* pMem = pBuf;
        int unused[6];
        g_memoryManager.Deallocate(pMem);
    }
    fValue = 0.0f;
    iVal4 = 0;
}
}  // namespace fnv_00a09330

template<> class NiTPointerListBase<NiTPointerAllocator<unsigned int>, char*> { public: void* AddHead(); };
struct NiTMapItem_00a0c900 { NiTMapItem_00a0c900* m_pkNext; const char* m_key; int m_val; };
struct FUN_00a0c900_shell {
    virtual void v0();
    virtual unsigned int KeyToHashIndex(const char*);
    virtual bool IsKeysEqual(const char*, const char*);
    virtual void SetValue(NiTMapItem_00a0c900*, const char*, int);
    unsigned int m_uiHashSize;
    NiTMapItem_00a0c900** m_ppkHashTable;
    unsigned int m_uiCount;
    bool m_bCopy;
    void FUN_00a0c900(const char* pcKey, int val);
};
// @fnv 0x00a0c900
void FUN_00a0c900_shell::FUN_00a0c900(const char* pcKey, int val)
{
    unsigned int uiIndex = KeyToHashIndex(pcKey);
    NiTMapItem_00a0c900* pkItem = m_ppkHashTable[uiIndex];
    unsigned int uiDepth = 0;
    while (pkItem) {
        uiDepth++;
        if (IsKeysEqual(pcKey, pkItem->m_key)) {
            int unused[7];
            if (!m_bCopy)
                pkItem->m_key = pcKey;
            pkItem->m_val = val;
            return;
        }
        pkItem = pkItem->m_pkNext;
    }
    pkItem = (NiTMapItem_00a0c900*)((NiTPointerListBase<NiTPointerAllocator<unsigned int>, char*>*)&m_uiCount)->AddHead();
    SetValue(pkItem, pcKey, val);
    pkItem->m_pkNext = m_ppkHashTable[uiIndex];
    m_ppkHashTable[uiIndex] = pkItem;
    m_uiCount++;
}

struct FUN_007000b0_shell {
    void HasFlag(int);
    void FUN_007000b0();
};
// @fnv 0x007000b0
void FUN_007000b0_shell::FUN_007000b0()
{
    HasFlag(1);
}

struct FUN_007000d0_shell {
    void HasFlag(int);
    void FUN_007000d0();
};
// @fnv 0x007000d0
void FUN_007000d0_shell::FUN_007000d0()
{
    HasFlag(2);
}

struct FUN_007000f0_shell {
    bool HasFlag(int mask);
};
// @fnv 0x007000f0
bool FUN_007000f0_shell::HasFlag(int mask)
{
    return (*(unsigned char*)((char*)this + 0x28) & mask) != 0;
}

int __cdecl GetTileValueID(const char* apName, int aiIndex);
struct VATSMenu {
    int GetSelectedTargetIndex();
    int FUN_007267c0();
};

// @fnv 0x007267c0
int VATSMenu::FUN_007267c0()
{
    static int iNumFilteredTrait = GetTileValueID("_num_filtered", -1);
    return GetSelectedTargetIndex() - (unsigned int)(*(Tile**)((char*)this + 0xc))->GetFloat(iNumFilteredTrait);
}

// @fnv 0x00a01160
int __cdecl FUN_00a01160(int** pFirst, int** pSecond)
{
    int** pa = pFirst;
    int** pb = pSecond;
    if (**pa < **pb)
        return -1;
    if (**pa > **pb)
        return 1;
    return 0;
}

extern "C" void __cdecl FUN_00a04500();

struct FUN_00a0baf0_class {
    void FUN_00a0baf0();
};

// @fnv 0x00a0baf0
void FUN_00a0baf0_class::FUN_00a0baf0()
{
    FUN_00a04500();
}

struct TileText {
    const char* FUN_00a0bbe0();
};

// @fnv 0x00a0bbe0
const char* TileText::FUN_00a0bbe0()
{
    return "TEXT";
}

struct Tile3D
{
    virtual ~Tile3D();
    const char* __thiscall FUN_00a0bdd0();
};

// @fnv 0x00a0bdd0
const char* __thiscall Tile3D::FUN_00a0bdd0()
{
    return "3DAN";
}

struct FUN_00a0c060_shell {
    int GetField0C();
};
// @fnv 0x00a0c060
int FUN_00a0c060_shell::GetField0C()
{
    return *(int*)((char*)this + 0xc);
}

extern const char g_011c7820_arg1[];
struct FUN_00a0c080_shell {
    const char* GetArg1String();
};
// @fnv 0x00a0c080
const char* FUN_00a0c080_shell::GetArg1String()
{
    return g_011c7820_arg1;
}

void __cdecl __Dummy_00b6fef0(void*, unsigned int);

struct FUN_00a0c090_Class {
    void FUN_00a0abe0();
    void* FUN_00a0c090(unsigned int flags);
};

// Calls FUN_00a0abe0, then if bit 0 of flags is set calls __Dummy_00b6fef0 with this and 0x14, and returns this.
// @fnv 0x00a0c090
void* FUN_00a0c090_Class::FUN_00a0c090(unsigned int flags)
{
    this->FUN_00a0abe0();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0x14);
    return this;
}

struct FUN_00a0d260_Class {
    int m_iWordAt00;
    int m_iWordAt04;
    unsigned int Modulo(unsigned int param);
};

// @fnv 0x00a0d260
unsigned int __thiscall FUN_00a0d260_Class::Modulo(unsigned int auiValue) {
    return auiValue % m_iWordAt04;
}

struct FUN_00a04100_shell {
    int unk[10];
    Tile* pTile;
    bool FUN_00a04100();
};
// Walks the Tile chain via offset 0x28, checking GetFloat(0xfaa) against 110.0, and always returns false.
// @fnv 0x00a04100
bool FUN_00a04100_shell::FUN_00a04100()
{
    Tile* t = pTile;
    while (t) {
        if (t->GetFloat(0xfaa) == 110.0)
            t = *(Tile**)((char*)t + 0x28);
    }
    return false;
}

void _NiFreeAlias(void*);

struct NiTMapItem_ {
    char const* m_key;
    int m_uiFilterValue;
};

struct NiTStringTemplateMap_ {
    void* m_map;
    char pad[12];
    bool m_bCopy;
    void FUN_00a0d4a0(NiTMapItem_* pkItem);
};

// @fnv 0x00a0d4a0
void NiTStringTemplateMap_::FUN_00a0d4a0(NiTMapItem_* pkItem)
{
    if (m_bCopy)
        _NiFreeAlias((void*)(pkItem->m_uiFilterValue));
}

struct FUN_00a011b0_cls {
    float __thiscall FUN_00a011b0(int value);
};

struct FUN_0072ccd0_cls {
    int unk00;
    int unk04;
    int unk08;
    FUN_00a011b0_cls* m_0c;
    int GetRaceCount();
    int FUN_0072ccd0();
};

int __cdecl TraitNameToIDAdd(const char* name, int len);

// Returns GetRaceCount() minus the value FUN_00a011b0 computes from the static _num_filtered setting via m_0c.
// @fnv 0x0072ccd0
int FUN_0072ccd0_cls::FUN_0072ccd0()
{
    static int numFiltered = TraitNameToIDAdd("_num_filtered", -1);
    return GetRaceCount() - (unsigned int)m_0c->FUN_00a011b0(numFiltered);
}

namespace fnv_0075b020 {
struct FUN_00a011b0_cls {
    float __thiscall FUN_00a011b0(int value);
};

struct FUN_0075b020_cls {
    int unk00;
    int unk04;
    int unk08;
    FUN_00a011b0_cls* m_0c;
    int GetRaceCount();
    int FUN_0075b020();
};

int __cdecl TraitNameToIDAdd(const char* name, int len);

// Returns the result of GetRaceCount minus the value FUN_00a011b0 computes from the cached _num_filtered setting.
// @fnv 0x0075b020
int FUN_0075b020_cls::FUN_0075b020()
{
    static int numFiltered = TraitNameToIDAdd("_num_filtered", -1);
    return GetRaceCount() - (unsigned int)m_0c->FUN_00a011b0(numFiltered);
}
}  // namespace fnv_0075b020

namespace fnv_007a71b0 {
struct FUN_00a011b0_cls {
    float __thiscall FUN_00a011b0(int value);
};

struct FUN_007a71b0_cls {
    int unk00;
    int unk04;
    int unk08;
    FUN_00a011b0_cls* m_0c;
    int GetRaceCount();
    int FUN_007a71b0();
};

int __cdecl TraitNameToIDAdd(const char* name, int len);

// Returns the result of GetRaceCount minus the value FUN_00a011b0 computes from the cached "_num_filtered" setting.
// @fnv 0x007a71b0
int FUN_007a71b0_cls::FUN_007a71b0()
{
    static int numFiltered = TraitNameToIDAdd("_num_filtered", -1);
    return GetRaceCount() - (unsigned int)m_0c->FUN_00a011b0(numFiltered);
}
}  // namespace fnv_007a71b0

struct RecurseItem;
struct RecurseNode;

extern const double DAT_01012060;

float __cdecl FUN_00a01540(RecurseItem* self);

struct RecurseItem {
    void* unk00;
    RecurseNode* m_pkChildren;
    float FUN_00a011b0(int ordinal);
};

struct RecurseNode {
    RecurseNode* m_pkNext;
    void* unk04;
    RecurseItem* m_pInventoryEntryData;
};

// @fnv 0x00a01540
float __cdecl FUN_00a01540(RecurseItem* self)
{
    float result2 = self->FUN_00a011b0(0xfad);
    RecurseItem* child_ = 0;
    RecurseNode* pos5 = self->m_pkChildren;
    RecurseNode* cur = pos5;
    while (cur != 0) {
        RecurseItem* const& element3 = cur->m_pInventoryEntryData;
        cur = cur->m_pkNext;
        child_ = element3;
        if (self->FUN_00a011b0(0xfa8) != DAT_01012060) {
            float childF = self->FUN_00a011b0(0xfad) + FUN_00a01540(child_);
            result2 = result2 > childF ? result2 : childF;
        } else {
            float childF = FUN_00a01540(child_);
            result2 = result2 > childF ? result2 : childF;
        }
    }
    return result2;
}

struct FNVSearchItem {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_iKey10;
    void* m_pOwner14;
    int m_iValue18;
};

struct FNVSearchNode {
    FNVSearchItem* m_pInventoryEntryData;
    FNVSearchNode* m_pNext;
};

extern FNVSearchNode g_fnvSearchHead;

class FNVSearchOwner {
public:
    int FindValueByKey(int key);
};

// Walks the global search list and returns m_iValue18 of the first item whose m_iKey10 equals key and whose m_pOwner14 is this, else 0.
// @fnv 0x00a08070
int FNVSearchOwner::FindValueByKey(int key) {
    for (FNVSearchNode* node = &g_fnvSearchHead; node != 0 && node->m_pInventoryEntryData != 0; node = node->m_pNext) {
        if (node->m_pInventoryEntryData->m_iKey10 == key && node->m_pInventoryEntryData->m_pOwner14 == (void*)this) {
            return node->m_pInventoryEntryData->m_iValue18;
        }
    }
    return 0;
}

struct TileNode; struct TileNodeList { TileNodeList* next; TileNode* parent; TileNode* child; };
struct TileNode { void* virtualTable; TileNodeList* children; float __thiscall FUN_00a011b0(int trait); };
// Recursively searches root and its child nodes for the first TileNode whose trait 0xFAA equals target, returning it or null.
// @fnv 0x00a08fb0
TileNode* __cdecl FindTileNodeByTrait(TileNode* root, int target) {
    TileNodeList* cursor;
    {
        TileNode* found;
        {
            if (root && root->FUN_00a011b0(0xFAA) == target) return root;
            TileNodeList* head = root->children;
            cursor = head;
            while (cursor) {
                TileNode** ppLink = &cursor->child;
                cursor = cursor->next;
                found = FindTileNodeByTrait(*ppLink, target);
                if (found) return found;
            }
        }
    }
    return 0;
}

// Look up the handler list registered for a key and notify every handler in it.

struct A0A220Handler {
    void Notify(int iArg);
};

struct A0A220Node {
    A0A220Handler* m_pkItem;
    A0A220Node* m_pkNext;
};

struct A0A220HandlerMap {
    bool GetAt(unsigned int uiKey, A0A220Node*& rpkHead);
};

extern A0A220HandlerMap g_kA0A220Handlers;

// Looks up the handler list for uiKey and calls Notify(0) on each handler in the chain.
// @fnv 0x00a0a220
void __cdecl NotifyHandlersByKey(unsigned int uiKey)
{
    A0A220Node* pkIter = 0;
    A0A220Handler* pkItem;  // declared but never used in this build
    unsigned int ItemUpdateArray;      // declared but never used in this build
    if (g_kA0A220Handlers.GetAt(uiKey, pkIter)) {
        while (pkIter) {
            pkIter->m_pkItem->Notify(0);
            pkIter = pkIter->m_pkNext;
        }
    }
}

class InventoryMenuSetting {
public:
    const char* FUN_00403df0();
};
struct SystemLocaleState : InventoryMenuSetting {};
extern SystemLocaleState gSystemLocaleState;
class GlobalObject_0040c150 : public InventoryMenuSetting {};
extern GlobalObject_0040c150 g_011d4378;
extern InventoryMenuSetting DAT_011d29b8;
extern InventoryMenuSetting DAT_011d4d50;
extern InventoryMenuSetting DAT_011d40b4;
extern InventoryMenuSetting DAT_011d2acc;
extern GlobalObject_0040c150 g_011d4918;
int __cdecl FUN_00408b20(const char*, const char*);
int __cdecl strcpy_s(char*, unsigned int, const char*);
void __cdecl FUN_00730490(char*, int);
struct FUN_0055d520_shell { char* FUN_0055d520(); };
struct Menu_007301f0 {
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
    P09TileS* primaryTile;
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
    FUN_0055d520_shell* selectedObject;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int primaryCategory;
    int secondaryCategory;
    void UpdateTileText(P09TileS* tile);
};

// @fnv 0x007301f0
void Menu_007301f0::UpdateTileText(P09TileS* tile)
{
    char text[260];
    int selection = tile == primaryTile ? primaryCategory : secondaryCategory;
    bool isLocalized = FUN_00408b20(gSystemLocaleState.FUN_00403df0(), "ENGLISH") != 0;
    switch (selection) {
    case 0:
        if (tile == primaryTile) {
            strcpy_s(text, 260, g_011d4378.FUN_00403df0());
            if (!isLocalized)
                FUN_00730490(text, 260);
        } else {
            strcpy_s(text, 260, selectedObject->FUN_0055d520());
        }
        break;
    case 1:
        strcpy_s(text, 260, DAT_011d29b8.FUN_00403df0());
        if (!isLocalized)
            FUN_00730490(text, 260);
        break;
    case 2:
        strcpy_s(text, 260, DAT_011d4d50.FUN_00403df0());
        if (!isLocalized)
            FUN_00730490(text, 260);
        break;
    case 3:
        strcpy_s(text, 260, DAT_011d40b4.FUN_00403df0());
        if (!isLocalized)
            FUN_00730490(text, 260);
        break;
    case 4:
        strcpy_s(text, 260, DAT_011d2acc.FUN_00403df0());
        if (!isLocalized)
            FUN_00730490(text, 260);
        break;
    case 5:
        strcpy_s(text, 260, g_011d4918.FUN_00403df0());
        if (!isLocalized)
            FUN_00730490(text, 260);
        break;
    }
    tile->Set(0xfc4, text, true);
}

namespace TraitRegistration {
void FUN_009ff8a0(const char*,int);bool FUN_00707b40();extern unsigned char DAT_011d8a84,DAT_011d8c50;
extern char DAT_010345e4;
extern char DAT_0103a454;
extern char DAT_0103c034;
extern char DAT_0103c83c;
extern char DAT_01044c0c;
extern char DAT_0106ec74;
extern char DAT_0106ec7c;
extern char DAT_0106f488;
extern char DAT_0106f490;
extern char DAT_0106fc9c;
extern char DAT_01076f20;
extern char DAT_01076f38;
extern char DAT_01077c6c;
extern char DAT_01077c78;
extern char DAT_01078bc0;
extern char DAT_01086f50;
extern char DAT_0108dff8;
extern char DAT_01093f84;
extern char DAT_01093f8c;
extern char DAT_01093f98;
extern char DAT_01093fa0;
extern char DAT_01093fa8;
extern char DAT_01093fac;
extern char DAT_01093fb0;
extern char DAT_01093fc4;
extern char DAT_01093fcc;
extern char DAT_01093fd4;
extern char DAT_01093fdc;
extern char DAT_01093fe4;
extern char DAT_01093fe8;
extern char DAT_01093ff4;
extern char DAT_01094004;
extern char DAT_01094010;
extern char DAT_0109401c;
extern char DAT_01094028;
extern char DAT_01094034;
extern char DAT_01094040;
extern char DAT_0109404c;
extern char DAT_01094058;
extern char DAT_01094064;
extern char DAT_01094070;
extern char DAT_0109407c;
extern char DAT_01094088;
extern char DAT_01094090;
extern char DAT_0109409c;
extern char DAT_010940a8;
extern char DAT_010940b0;
extern char DAT_010940b8;
extern char DAT_010940c0;
extern char DAT_010940c8;
extern char DAT_010940d0;
extern char DAT_010940d8;
extern char DAT_010940e0;
extern char DAT_010940e8;
extern char DAT_010940f0;
extern char DAT_010940f8;
extern char DAT_01094100;
extern char DAT_01094108;
extern char DAT_01094110;
extern char DAT_01094118;
extern char DAT_01094120;
extern char DAT_01094128;
extern char DAT_01094130;
extern char DAT_01094138;
extern char DAT_01094144;
extern char DAT_01094150;
extern char DAT_01094158;
extern char DAT_01094168;
extern char DAT_01094178;
extern char DAT_01094184;
extern char DAT_01094190;
extern char DAT_0109419c;
extern char DAT_010941b0;
extern char DAT_010941c0;
extern char DAT_010941c4;
extern char DAT_010941cc;
extern char DAT_010941d8;
extern char DAT_010941e4;
extern char DAT_010941f0;
extern char DAT_010941f8;
extern char DAT_01094204;
extern char DAT_0109420c;
extern char DAT_01094218;
extern char DAT_01094220;
extern char DAT_01094228;
extern char DAT_0109422c;
extern char DAT_01094234;
extern char DAT_0109423c;
extern char DAT_01094244;
extern char DAT_01094250;
extern char DAT_0109425c;
extern char DAT_01094268;
extern char DAT_01094274;
extern char DAT_0109427c;
extern char DAT_01094284;
extern char DAT_01094290;
extern char DAT_0109429c;
extern char DAT_010942a8;
extern char DAT_010942b4;
extern char DAT_010942c0;
extern char DAT_010942cc;
extern char DAT_010942d8;
extern char DAT_010942e4;
extern char DAT_010942ec;
extern char DAT_010942f4;
extern char DAT_010942fc;
extern char DAT_01094308;
extern char DAT_01094314;
extern char DAT_01094320;
extern char DAT_01094330;
extern char DAT_0109433c;
extern char DAT_01094344;
extern char DAT_0109434c;
extern char DAT_01094358;
extern char DAT_01094364;
extern char DAT_01094370;
extern char DAT_01094378;
extern char DAT_01094384;
extern char DAT_0109438c;
extern char DAT_01094394;
extern char DAT_01094398;
extern char DAT_010943a0;
extern char DAT_010943a4;
extern char DAT_010943ac;
extern char DAT_010943b0;
extern char DAT_010943bc;
extern char DAT_010943c4;
extern char DAT_010943c8;
extern char DAT_010943cc;
extern char DAT_010943d4;
extern char DAT_010943d8;
extern char DAT_010943dc;
extern char DAT_010943e0;
extern char DAT_010943e4;
extern char DAT_010943e8;
extern char DAT_010943ec;
extern char DAT_010943f0;
extern char DAT_010943f8;
extern char DAT_010943fc;
extern char DAT_01094400;
extern char DAT_01094408;
extern char DAT_01094410;
extern char DAT_01094414;
extern char DAT_01094418;
extern char DAT_0109441c;
extern char DAT_01094428;
extern char DAT_01094438;
extern char DAT_01094448;
extern char DAT_01094458;
extern char DAT_01094468;
extern char DAT_0109447c;
extern char DAT_01094490;
extern char DAT_010944a4;
extern char DAT_010944bc;
extern char DAT_010944d0;
extern char DAT_010944dc;
extern char DAT_010944ec;
extern char DAT_010944fc;
extern char DAT_0109450c;
extern char DAT_0109451c;
extern char DAT_0109452c;
extern char DAT_01094544;
extern char DAT_01094554;
extern char DAT_01094564;
extern char DAT_01094574;
extern char DAT_01094580;
extern char DAT_0109458c;
extern char DAT_0109459c;
extern char DAT_010945ac;
extern char DAT_010945bc;
extern char DAT_010945c8;
extern char DAT_010945d8;
extern char DAT_010945e8;
extern char DAT_010945f8;
extern char DAT_01094604;
extern char DAT_01094614;
extern char DAT_01094624;
extern char DAT_01094634;
extern char DAT_01094644;
extern char DAT_01094654;
extern char DAT_01094664;
extern char DAT_01094674;
extern char DAT_01094684;
extern char DAT_01094690;
extern char DAT_0109469c;
extern char DAT_010946a4;
extern char DAT_010946ac;
extern char DAT_010946b8;
extern char DAT_010946c0;
extern char DAT_010946c8;
extern char DAT_010946cc;
extern char DAT_010946d0;
extern char DAT_010946d8;
extern char DAT_010946e0;
extern char DAT_010946ec;
extern char DAT_010946f8;
extern char DAT_01094704;
extern char DAT_01094710;
extern char DAT_0109471c;
extern char DAT_01094728;
extern char DAT_01094734;
extern char DAT_01094740;
extern char DAT_0109474c;
extern char DAT_01094758;
extern char DAT_0109476c;
extern char DAT_01094778;
extern char DAT_01094788;
extern char DAT_01094798;
extern char DAT_010947a8;
extern char DAT_010947b8;
extern char DAT_010947c8;
extern char DAT_010947d8;
extern char DAT_010947e4;
extern char DAT_010947f0;
extern char DAT_01094800;
extern char DAT_01094814;
extern char DAT_01094824;
extern char DAT_01094834;
extern char DAT_0109483c;
extern char DAT_01094844;
extern char DAT_0109484c;
extern char DAT_01094854;
extern char DAT_01094860;
extern char DAT_01094868;
// @fnv 0x009ff970
void FUN_009ff970(){
FUN_009ff8a0(&DAT_01094868, -1);
FUN_009ff8a0(&DAT_0106ec74, 0);
FUN_009ff8a0(&DAT_0106ec7c, 1);
FUN_009ff8a0(&DAT_01094860, 1);
FUN_009ff8a0(&DAT_01094854, 2);
FUN_009ff8a0(&DAT_0109484c, 4);
FUN_009ff8a0(&DAT_01094844, 5);
FUN_009ff8a0(&DAT_0109483c, 6);
FUN_009ff8a0(&DAT_01094834, -1);
FUN_009ff8a0(&DAT_01094824, 101);
FUN_009ff8a0(&DAT_01094814, 102);
FUN_009ff8a0(&DAT_01094800, 6008);
FUN_009ff8a0(&DAT_010947f0, 103);
FUN_009ff8a0(&DAT_0106f490, (unsigned char)((DAT_011d8a84 && bool(DAT_011d8c50 ? 0 : 1)) ? 1 : 0));
FUN_009ff8a0(&DAT_010947e4, 0);
FUN_009ff8a0(&DAT_0106f488, (unsigned char)((DAT_011d8a84 && bool(DAT_011d8c50 ? 0 : 1)) ? 1 : 0));
FUN_009ff8a0(&DAT_010947d8, 1);
FUN_009ff8a0(&DAT_010947c8, FUN_00707b40());
FUN_009ff8a0(&DAT_010947b8, 110);
FUN_009ff8a0(&DAT_010947a8, 111);
FUN_009ff8a0(&DAT_01094798, 112);
FUN_009ff8a0(&DAT_01094788, -1);
FUN_009ff8a0(&DAT_01094778, 0);
FUN_009ff8a0(&DAT_0109476c, -1);
FUN_009ff8a0(&DAT_01094758, 9);
FUN_009ff8a0(&DAT_0109474c, 9);
FUN_009ff8a0(&DAT_01094740, 10);
FUN_009ff8a0(&DAT_01094734, 11);
FUN_009ff8a0(&DAT_01094728, 12);
FUN_009ff8a0(&DAT_0109471c, 13);
FUN_009ff8a0(&DAT_01094710, 14);
FUN_009ff8a0(&DAT_01094704, 15);
FUN_009ff8a0(&DAT_010946f8, 16);
FUN_009ff8a0(&DAT_01077c78, 17);
FUN_009ff8a0(&DAT_01077c6c, 18);
FUN_009ff8a0(&DAT_010946ec, 17);
FUN_009ff8a0(&DAT_010946e0, 18);
FUN_009ff8a0(&DAT_010946d8, 902);
FUN_009ff8a0(&DAT_010946d0, 905);
FUN_009ff8a0(&DAT_010946cc, 904);
FUN_009ff8a0(&DAT_010946c8, 904);
FUN_009ff8a0(&DAT_010946c0, 901);
FUN_009ff8a0(&DAT_010946b8, 906);
FUN_009ff8a0(&DAT_010946ac, 999);
FUN_009ff8a0(&DAT_0103c83c, 903);
FUN_009ff8a0(&DAT_010946a4, 907);
FUN_009ff8a0(&DAT_0109469c, 908);
FUN_009ff8a0(&DAT_01094690, 1017);
FUN_009ff8a0(&DAT_01094684, 1026);
FUN_009ff8a0(&DAT_01094674, 1048);
FUN_009ff8a0(&DAT_01094664, 1008);
FUN_009ff8a0(&DAT_01094654, 1009);
FUN_009ff8a0(&DAT_01094644, 1020);
FUN_009ff8a0(&DAT_01094634, 1004);
FUN_009ff8a0(&DAT_01094624, 1002);
FUN_009ff8a0(&DAT_01094614, 1007);
FUN_009ff8a0(&DAT_01094604, 1014);
FUN_009ff8a0(&DAT_010945f8, 1023);
FUN_009ff8a0(&DAT_010945e8, 1001);
FUN_009ff8a0(&DAT_010945d8, 1059);
FUN_009ff8a0(&DAT_010945c8, 1051);
FUN_009ff8a0(&DAT_010945bc, 1013);
FUN_009ff8a0(&DAT_010945ac, 1016);
FUN_009ff8a0(&DAT_0109459c, 1036);
FUN_009ff8a0(&DAT_0109458c, 1012);
FUN_009ff8a0(&DAT_01094580, 1003);
FUN_009ff8a0(&DAT_01094574, 1018);
FUN_009ff8a0(&DAT_01094564, 1027);
FUN_009ff8a0(&DAT_01094554, 1035);
FUN_009ff8a0(&DAT_01094544, 1061);
FUN_009ff8a0(&DAT_0109452c, 1058);
FUN_009ff8a0(&DAT_0109451c, 1047);
FUN_009ff8a0(&DAT_0109450c, 1053);
FUN_009ff8a0(&DAT_010944fc, 1054);
FUN_009ff8a0(&DAT_010944ec, 1055);
FUN_009ff8a0(&DAT_010944dc, 1057);
FUN_009ff8a0(&DAT_010944d0, 1056);
FUN_009ff8a0(&DAT_010944bc, 1060);
FUN_009ff8a0(&DAT_010944a4, 1075);
FUN_009ff8a0(&DAT_01094490, 1074);
FUN_009ff8a0(&DAT_0109447c, 1076);
FUN_009ff8a0(&DAT_01094468, 1080);
FUN_009ff8a0(&DAT_01094458, 1081);
FUN_009ff8a0(&DAT_01094448, 1082);
FUN_009ff8a0(&DAT_01094438, 1077);
FUN_009ff8a0(&DAT_01094428, 1083);
FUN_009ff8a0(&DAT_0109441c, 1084);
FUN_009ff8a0(&DAT_01094418, 2010);
FUN_009ff8a0(&DAT_01094414, 2001);
FUN_009ff8a0(&DAT_01094410, 2018);
FUN_009ff8a0(&DAT_01094408, 2009);
FUN_009ff8a0(&DAT_01094400, 2000);
FUN_009ff8a0(&DAT_010943fc, 2004);
FUN_009ff8a0(&DAT_010943f8, 2014);
FUN_009ff8a0(&DAT_010943f0, 2008);
FUN_009ff8a0(&DAT_010943ec, 2012);
FUN_009ff8a0(&DAT_010943e8, 2013);
FUN_009ff8a0(&DAT_01076f38, 2016);
FUN_009ff8a0(&DAT_010943e4, 2017);
FUN_009ff8a0(&DAT_010943e0, 2006);
FUN_009ff8a0(&DAT_010943dc, 2005);
FUN_009ff8a0(&DAT_010943d8, 2007);
FUN_009ff8a0(&DAT_010943d4, 2003);
FUN_009ff8a0(&DAT_010943cc, 2003);
FUN_009ff8a0(&DAT_010943c8, 2015);
FUN_009ff8a0(&DAT_010943c4, 2020);
FUN_009ff8a0(&DAT_010943bc, 2021);
FUN_009ff8a0(&DAT_010943b0, 2022);
FUN_009ff8a0(&DAT_010943ac, 2019);
FUN_009ff8a0(&DAT_01044c0c, 2023);
FUN_009ff8a0(&DAT_010943a4, 2011);
FUN_009ff8a0(&DAT_010943a0, 2002);
FUN_009ff8a0(&DAT_01094398, 3002);
FUN_009ff8a0(&DAT_01094394, 3003);
FUN_009ff8a0(&DAT_0109438c, 3004);
FUN_009ff8a0(&DAT_01094384, 3001);
FUN_009ff8a0(&DAT_0103a454, 4009);
FUN_009ff8a0(&DAT_01094378, 4050);
FUN_009ff8a0(&DAT_01094370, 4020);
FUN_009ff8a0(&DAT_01094364, 4085);
FUN_009ff8a0(&DAT_01094358, 4022);
FUN_009ff8a0(&DAT_0109434c, 4022);
FUN_009ff8a0(&DAT_01094344, 4004);
FUN_009ff8a0(&DAT_0109433c, 4039);
FUN_009ff8a0(&DAT_01094330, 4043);
FUN_009ff8a0(&DAT_01094320, 4072);
FUN_009ff8a0(&DAT_01094314, 4011);
FUN_009ff8a0(&DAT_01094308, 4032);
FUN_009ff8a0(&DAT_010942fc, 4031);
FUN_009ff8a0(&DAT_010942f4, 4032);
FUN_009ff8a0(&DAT_010942ec, 4031);
FUN_009ff8a0(&DAT_010942e4, 4014);
FUN_009ff8a0(&DAT_010942d8, 4006);
FUN_009ff8a0(&DAT_0103c034, 4013);
FUN_009ff8a0(&DAT_010942cc, 4073);
FUN_009ff8a0(&DAT_010942c0, 4078);
FUN_009ff8a0(&DAT_010942b4, 4079);
FUN_009ff8a0(&DAT_010942a8, 4074);
FUN_009ff8a0(&DAT_0109429c, 4075);
FUN_009ff8a0(&DAT_01094290, 4076);
FUN_009ff8a0(&DAT_01094284, 4077);
FUN_009ff8a0(&DAT_0109427c, 4080);
FUN_009ff8a0(&DAT_01094274, 4081);
FUN_009ff8a0(&DAT_01094268, 4034);
FUN_009ff8a0(&DAT_0109425c, 4046);
FUN_009ff8a0(&DAT_01094250, 4044);
FUN_009ff8a0(&DAT_01094244, 4045);
FUN_009ff8a0(&DAT_0109423c, 4025);
FUN_009ff8a0(&DAT_01094234, 4019);
FUN_009ff8a0(&DAT_0109422c, 4016);
FUN_009ff8a0(&DAT_01094228, 4010);
FUN_009ff8a0(&DAT_01094220, 4030);
FUN_009ff8a0(&DAT_01094218, 4023);
FUN_009ff8a0(&DAT_0109420c, 4052);
FUN_009ff8a0(&DAT_01094204, 4087);
FUN_009ff8a0(&DAT_010941f8, 4012);
FUN_009ff8a0(&DAT_010941f0, 4008);
FUN_009ff8a0(&DAT_010941e4, 4033);
FUN_009ff8a0(&DAT_010941d8, 4035);
FUN_009ff8a0(&DAT_010941cc, 4053);
FUN_009ff8a0(&DAT_010941c4, 4029);
FUN_009ff8a0(&DAT_010941c0, 4018);
FUN_009ff8a0(&DAT_010941b0, 4047);
FUN_009ff8a0(&DAT_0109419c, 4048);
FUN_009ff8a0(&DAT_01094190, 4090);
FUN_009ff8a0(&DAT_01094184, 4091);
FUN_009ff8a0(&DAT_01094178, 4092);
FUN_009ff8a0(&DAT_01094168, 4037);
FUN_009ff8a0(&DAT_01094158, 4007);
FUN_009ff8a0(&DAT_01094150, 4036);
FUN_009ff8a0(&DAT_01094144, 4084);
FUN_009ff8a0(&DAT_0108dff8, 4015);
FUN_009ff8a0(&DAT_01094138, 4089);
FUN_009ff8a0(&DAT_01094130, 4021);
FUN_009ff8a0(&DAT_01094128, 4100);
FUN_009ff8a0(&DAT_01094120, 4101);
FUN_009ff8a0(&DAT_01094118, 4102);
FUN_009ff8a0(&DAT_01094110, 4103);
FUN_009ff8a0(&DAT_01094108, 4104);
FUN_009ff8a0(&DAT_01094100, 4105);
FUN_009ff8a0(&DAT_010940f8, 4106);
FUN_009ff8a0(&DAT_010940f0, 4107);
FUN_009ff8a0(&DAT_010940e8, 4108);
FUN_009ff8a0(&DAT_010940e0, 4109);
FUN_009ff8a0(&DAT_010940d8, 4110);
FUN_009ff8a0(&DAT_010940d0, 4111);
FUN_009ff8a0(&DAT_010940c8, 4112);
FUN_009ff8a0(&DAT_010940c0, 4113);
FUN_009ff8a0(&DAT_010940b8, 4114);
FUN_009ff8a0(&DAT_010940b0, 4115);
FUN_009ff8a0(&DAT_010940a8, 4116);
FUN_009ff8a0(&DAT_0106fc9c, 4003);
FUN_009ff8a0(&DAT_0109409c, 4082);
FUN_009ff8a0(&DAT_01094090, 4083);
FUN_009ff8a0(&DAT_01094088, 4017);
FUN_009ff8a0(&DAT_0109407c, 4027);
FUN_009ff8a0(&DAT_01094070, 4028);
FUN_009ff8a0(&DAT_01094064, 4026);
FUN_009ff8a0(&DAT_01094058, 4061);
FUN_009ff8a0(&DAT_0109404c, 4062);
FUN_009ff8a0(&DAT_01094040, 4063);
FUN_009ff8a0(&DAT_01094034, 4064);
FUN_009ff8a0(&DAT_01094028, 4065);
FUN_009ff8a0(&DAT_0109401c, 4066);
FUN_009ff8a0(&DAT_01094010, 4067);
FUN_009ff8a0(&DAT_01094004, 4068);
FUN_009ff8a0(&DAT_01093ff4, 4071);
FUN_009ff8a0(&DAT_01093fe8, 4054);
FUN_009ff8a0(&DAT_01093fe4, 4055);
FUN_009ff8a0(&DAT_01093fdc, 4056);
FUN_009ff8a0(&DAT_01093fd4, 4057);
FUN_009ff8a0(&DAT_01093fcc, 4058);
FUN_009ff8a0(&DAT_010345e4, 4001);
FUN_009ff8a0(&DAT_01076f20, 4002);
FUN_009ff8a0(&DAT_01093fc4, 4024);
FUN_009ff8a0(&DAT_01093fb0, 4088);
FUN_009ff8a0(&DAT_01086f50, 5005);
FUN_009ff8a0(&DAT_01093fac, 5002);
FUN_009ff8a0(&DAT_01093fa8, 5008);
FUN_009ff8a0(&DAT_01093fa0, 5001);
FUN_009ff8a0(&DAT_01078bc0, 5006);
FUN_009ff8a0(&DAT_01093f98, 5004);
FUN_009ff8a0(&DAT_01093f8c, 5009);
FUN_009ff8a0(&DAT_01093f84, 5007);
}
}

struct MenuDepthController;
struct UpdateTreeNode;
struct UpdateNode { UpdateNode* next; UpdateNode* prev; UpdateTreeNode* data; };
struct MenuDepthController {
 virtual void m0(); virtual void SetDepth(int, UpdateTreeNode*);
 int unk04, unk08, unk0c, unk10, unk14;
 int depth;
};
struct UpdateTreeNode {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual int GetType();
 UpdateNode* children;
 int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
 UpdateTreeNode* parent;
 __forceinline UpdateTreeNode* GetParent() { return parent; }
 __forceinline UpdateNode* GetChildren() { return children; }
 float FUN_00a011b0(int);
 const char* FUN_00a011f0(int);
 MenuDepthController* FUN_00a03c90();
 UpdateTreeNode* FUN_00a03d40();
 void FUN_00a07530(int);
 void FUN_00a012d0(int,float,bool);
 UpdateTreeNode* FUN_00a037e0(int, float, int);
};
// @fnv 0x00a037e0
UpdateTreeNode* UpdateTreeNode::FUN_00a037e0(int trait, float value, int unused)
{
 UpdateTreeNode* aBound; MenuDepthController* aCurrent; float aLast; UpdateTreeNode* aReadObject;
 UpdateNode* aBipedNode; MenuDepthController* aOther; UpdateTreeNode* aContext; UpdateTreeNode* aList1; UpdateTreeNode* aPrevious; int aMargin; UpdateNode* aOuter2; UpdateTreeNode** aLocation;
 if (trait == 0xfa1 || trait == 0xfa2 || trait == 0xfad) {
  if (trait == 0xfad) {
   aLast = value;
   aReadObject = this;
   while ((aContext = aReadObject->parent) && (aList1 = aReadObject->parent, aPrevious = aList1->parent)) {
    if (aReadObject->FUN_00a011b0(0xfa8) != 0.0) aLast += aReadObject->FUN_00a011b0(0xfad);
    aReadObject = aReadObject->parent;
   }
   aCurrent = FUN_00a03c90();
   aBound = FUN_00a03d40();
   if (aCurrent && aBound && aBound != this && aCurrent && aLast > (aMargin = aCurrent->depth)) aCurrent->depth = (int)aLast;
  }
  if (FUN_00a011b0(0xfa6) != 0.0) FUN_00a07530(0x80);
  FUN_00a07530(1); return this;
 }
 if (GetType() == 0x387 && (trait == 0xfba || trait == 0xfbb || trait == 0xfbc || trait == 0xff7 || trait == 0xfbd || trait == 0xfbe || trait == 0xfb9 || trait == 0xfb7)) {
  FUN_00a07530(2); return this;
 }
 if ((trait == 0xfb1 || trait == 0xfb0 || trait == 0xfc0 || trait == 0xfbf) && GetType() == 0x386) {
  if (FUN_00a011b0(0xfa6) != 0.0) FUN_00a07530(0x80);
  FUN_00a07530(0x10); return this;
 }
 if (trait == 0xfa6 && (GetType() == 0x386 || GetType() == 0x385)) { FUN_00a07530(0x80); return this; }
 if (trait == 0xfae && (GetType() == 0x386 || GetType() == 0x387)) {
  FUN_00a07530(0x100);
  aOuter2 = children;
  aBipedNode = aOuter2;
  while (aBipedNode) {
   aLocation = &aBipedNode->data;
   aBipedNode = aBipedNode->next;
   (*aLocation)->FUN_00a012d0(0xfae,FUN_00a011b0(0xfae),true);
  }
  return this;
 }
 if (trait == 0xfa3) { FUN_00a07530(4); return this; }
 if (trait == 0xfa9 || trait == 0xfb2 || trait == 0xfb3 || trait == 0xfb4 || trait == 0xff4 || trait == 0xff5) {
  if (GetType() == 0x386 || GetType() == 0x387) FUN_00a07530(8);
  return this;
 }
 if (trait == 0xfcc && GetType() == 0x386 && FUN_00a011f0(0xfcc)) { FUN_00a07530(0x20); return this; }
 if (trait == 0xfcc && GetType() == 0x388 && FUN_00a011f0(0xfcc)) { FUN_00a07530(0x40); return this; }
 if (trait == 0xfa8) { FUN_00a07530(0x200); return this; }
 if (trait == 0xfaa) {
  aOther = FUN_00a03c90();
  if (aOther) aOther->SetDepth((int)value,this);
 }
 if (trait == 0xffa || trait == 0xffb || trait == 0xffc) { FUN_00a07530(1); return this; }
 return 0;
}

namespace fnv_00a0a300 {
int __cdecl FUN_00ec6da0(const char*, const char*);
unsigned int __cdecl strlen(const char*);
int __cdecl strcpy_s(char*, unsigned int, const char*);

struct TileValueStr {
    int m_iValueId;
    Tile* pTile;
    float fValue;
    char* pString;
    void RefreshA();
    void RefreshB(bool);
    void SetString(const char* apString, bool abUpdate);
};

// @fnv 0x00a0a300
void TileValueStr::SetString(const char* apString, bool abUpdate)
{
    const char* pCur;
    char* pOld;
    unsigned int uiLen6;
    char* pNew3;
    char* pDest4;
    bool kBChanged = (!pString && apString) || (pString && !apString) ||
                    (pString && apString && (pCur = pString, FUN_00ec6da0(pCur, apString)));
    if (pString) {
        pOld = pString;
        g_memoryManager.Deallocate(pOld);
        pString = 0;
    }
    if (apString) {
        uiLen6 = strlen(apString);
        pNew3 = (char*)((P03MM*)&g_memoryManager)->Allocate(uiLen6 + 1);
        pString = pNew3;
        pDest4 = pString;
        strcpy_s(pDest4, uiLen6 + 1, apString);
    }
    fValue = 0.0f;
    if (abUpdate)
        RefreshA();
    RefreshB(kBChanged);
}
}  // namespace fnv_00a0a300

extern "C" int __cdecl tolower(int c);

struct FUN_00a0d1b0_cls {
    int unk00;
    unsigned int m_04;

    unsigned int HashKey(const char* key);
};

// Computes a rolling hash of the lowercased characters of key and returns it modulo m_04.
// @fnv 0x00a0d1b0
unsigned int FUN_00a0d1b0_cls::HashKey(const char* key) {
    unsigned int hash = 0;
    while (*key) {
        char c;
        hash = (hash << 5) + hash + (c = tolower(*key++));
    }
    return hash % m_04;
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

int __cdecl GetTrait(const char*, int);
extern int DAT_011d8e64;
extern int DAT_011d8e68;
struct ListOwner { int Mode(); };
struct FUN_00726920_StandIn { char pad0[0xc]; Tile* pTile; int FUN_00726920(); };
// @fnv 0x00726920
int FUN_00726920_StandIn::FUN_00726920()
{
    static int numFiltered = GetTrait("_num_filtered", -1);
    return ((ListOwner*)this)->Mode() - (unsigned int)pTile->GetFloat(numFiltered);
}

class StrMapW {
public:
    void* vtbl;
    unsigned int m_uiHashSize;
    unsigned int FUN_00a0d440(const char* pKey);
};
// Computes a hash of the pKey string and returns it modulo m_uiHashSize.
// @fnv 0x00a0d440
unsigned int StrMapW::FUN_00a0d440(const char* pKey)
{
    unsigned int uiHash = 0;
    while (*pKey)
    {
        char c = *pKey;
        uiHash = uiHash + (c + (uiHash << 5));
        pKey++;
    }
    return uiHash % m_uiHashSize;
}

int __cdecl TraitNameToIDAdd(const char*, int);
int __fastcall GetRaceCount(char*);
extern const char DAT_0106f8d0[];

struct FilteredList {
    int unk00;
    int unk04;
    int unk08;
    Tile* tile;
    unsigned int FUN_00726870();
};

// Returns the total race count minus the value stored in the tile's float field at the index resolved from the static string constant.
// @fnv 0x00726870
unsigned int FilteredList::FUN_00726870()
{
    static int s_iNumFiltered = TraitNameToIDAdd(DAT_0106f8d0, -1);
    return GetRaceCount((char*)this) - (unsigned int)tile->GetFloat(s_iNumFiltered);
}

int __cdecl TraitNameToIDAdd(const char* name, int index);
namespace filt72c {
struct F2Tile {
    float FUN_00a011b0(int trait);
};
struct F2Menu {
    int unk00;
    int unk04;
    int unk08;
    F2Tile* pList;
    int GetRaceCount();
    int FUN_0072cd80();
};
}
using namespace filt72c;

// Returns the number of races that are not filtered out by the _num_filtered trait.
// @fnv 0x0072cd80
int F2Menu::FUN_0072cd80()
{
    static int s_iNumFiltered = TraitNameToIDAdd("_num_filtered", -1);
    return GetRaceCount() - (unsigned int)pList->FUN_00a011b0(s_iNumFiltered);
}

extern const char DAT_0106f8d0[];
int __cdecl TraitNameToIDAdd(const char*, int);
struct TraitSource {
    float FUN_00a011b0(int);
};
struct ItemCounter {
    int unk00;
    int unk04;
    int unk08;
    TraitSource* tile;
    int GetRaceCount();
    unsigned int FUN_007a8030();
};
// Returns the race count minus the trait value from the tile's TraitSource for the static trait id.
// @fnv 0x007a8030
unsigned int ItemCounter::FUN_007a8030() {
    static int trait = TraitNameToIDAdd(DAT_0106f8d0, -1);
    return GetRaceCount() - (unsigned int)tile->FUN_00a011b0(trait);
}

int __cdecl TraitNameToIDAdd(const char* name, int index);
namespace filt7a8 {
struct F7Tile {
    float FUN_00a011b0(int trait);
};
struct F7Menu {
    int unk00;
    int unk04;
    int unk08;
    F7Tile* pList;
    int GetRaceCount();
    int FUN_007a86e0();
};
}
using namespace filt7a8;

// Returns the total race count minus the number of races filtered out by the _num_filtered trait.
// @fnv 0x007a86e0
int F7Menu::FUN_007a86e0()
{
    static int s_iNumFiltered = TraitNameToIDAdd("_num_filtered", -1);
    return GetRaceCount() - (unsigned int)pList->FUN_00a011b0(s_iNumFiltered);
}

extern double g_dZero;
Tile* FUN_00706cd0();

struct S00a014b0_Tile : Tile {
    float FUN_00a014b0();
};

// Adds this tile's 0xfad value, then linked tiles' values when 0xfa8 is nonzero or the next pointer matches FUN_00706cd0().
// @fnv 0x00a014b0
float S00a014b0_Tile::FUN_00a014b0()
{
    Tile* pChild;
    float fTotal = GetFloat(0xfad);
    pChild = *(Tile**)((char*)this + 0x28);
    while (pChild) {
        Tile* pNext2;
        if (pChild->GetFloat(0xfa8) != g_dZero || (pNext2 = *(Tile**)((char*)pChild + 0x28), pNext2 == FUN_00706cd0()))
            fTotal += pChild->GetFloat(0xfad);
        pChild = *(Tile**)((char*)pChild + 0x28);
    }
    return fTotal;
}

namespace sa040a0 {

struct Child {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    Child* m_pkNext;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    unsigned int m_uiValue1;
};

struct Owner {
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
    Child* m_pkFirst;

    bool IsAllChildrenFlag0();
};

// Walks the m_pkFirst linked list of Child nodes and returns true if no node has bit 0 of m_uiValue1 set.
// @fnv 0x00a040a0
bool Owner::IsAllChildrenFlag0()
{
    Child* pkChild = m_pkFirst;
    bool bFound = false;
    while (!bFound && pkChild)
    {
        bFound |= (unsigned char)((pkChild->m_uiValue1 & 1) ? 1 : 0);
        pkChild = pkChild->m_pkNext;
    }
    return bFound == 0;
}

}

extern int DAT_011f32d4;
extern int DAT_011f3320;

// @fnv 0x00a04510
void FUN_00a04510()
{
    int iCount;
    {
    void* xelem;
    {
    Tile* ptile;
    {
    int iTemp;
    {
    int aiPad[16];
    {
    int iPad2;
    {
    unsigned int uiFlags1;
    {
    unsigned int uiFlags2;
    iTemp = DAT_011f3320;
    iCount = DAT_011f32d4 + iTemp;
    if (iCount > 10)
        return;
    iCount = 11 - iCount;
    xelem = *(void**)&DAT_011f3324;
    while (xelem && iCount)
    {
        ptile = *(Tile**)((char*)xelem + 8);
        if (ptile)
        {
            if (0)
            {
                *(unsigned int*)((char*)ptile + 0x30) |= 0x800;
                uiFlags1 = *(unsigned int*)((char*)ptile + 0x30);
            }
            else
            {
                *(unsigned int*)((char*)ptile + 0x30) &= ~0x800;
                uiFlags1 = *(unsigned int*)((char*)ptile + 0x30);
            }
            if (1)
            {
                *(unsigned int*)((char*)ptile + 0x30) |= 0x1000;
                uiFlags2 = *(unsigned int*)((char*)ptile + 0x30);
            }
            else
            {
                *(unsigned int*)((char*)ptile + 0x30) &= ~0x1000;
                uiFlags2 = *(unsigned int*)((char*)ptile + 0x30);
            }
            FUN_00a07690(ptile);
        }
        DAT_011f3324.RemovePos(xelem);
        iCount = iCount - 1;
    }

    }

    }

    }

    }

    }

    }

    }
}
