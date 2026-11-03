
// src/staging/blk_00760000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

extern int DAT_01072514;

struct FUN_007614a0_class
{
    int* p;
    void FUN_007615d0(int);
    void InitializeWithGlobal();
};

// @fnv 0x007614a0
void FUN_007614a0_class::InitializeWithGlobal()
{
    p = &DAT_01072514;
    FUN_007615d0(1);
}

struct TESSound;
struct EffectSetting
{
    TESSound* GetCastSound();
};
extern bool* DAT_011d9510;

// @fnv 0x007624d0
TESSound* FUN_007624d0()
{
    if (DAT_011d9510)
        return reinterpret_cast<EffectSetting*>(DAT_011d9510)->GetCastSound();
    return 0;
}

struct FUN_0076b610_Class
{
    bool FUN_0076b610();
};

// @fnv 0x0076b610
bool FUN_0076b610_Class::FUN_0076b610()
{
    return *(int*)((char*)this + 8) == 0;
}

struct Flt
{
    operator unsigned int();
    bool Equals(unsigned int value);
};

// @fnv 0x0076b780
bool Flt::Equals(unsigned int value)
{
    return value == (unsigned int)*this;
}

unsigned int __cdecl gm_GetTickCount();

struct FUN_0076bda0_class
{
    FUN_0076bda0_class* __thiscall FUN_0076bda0();
    void __thiscall FUN_00aa50f0(unsigned int);
};

// @fnv 0x0076bda0
FUN_0076bda0_class* __thiscall FUN_0076bda0_class::FUN_0076bda0()
{
    FUN_00aa50f0(gm_GetTickCount());
    return this;
}

struct FUN_00778950_Class
{
    unsigned int GetField188();
};

// @fnv 0x00778950
unsigned int FUN_00778950_Class::GetField188()
{
    return *(unsigned int*)((char*)this + 0x188);
}

struct FUN_0077a450_class
{
    void SetFloats(float a, float b);
};

// Stores the two float arguments at offsets 0x7c and 0x80 of this object.
// @fnv 0x0077a450
void FUN_0077a450_class::SetFloats(float afValue1, float afValue2)
{
    *(float*)((char*)this + 0x7c) = afValue1;
    *(float*)((char*)this + 0x80) = afValue2;
}

extern int DAT_010738cc;
struct AX
{
    void FUN_006b3eb0(unsigned int a, unsigned int b);
    void* vtable;
    AX* FUN_0077f970();
};
// Sets the vtable to DAT_010738cc, calls FUN_006b3eb0 with 0 and 0, and returns this.
// @fnv 0x0077f970
AX* AX::FUN_0077f970()
{
    vtable = &DAT_010738cc;
    FUN_006b3eb0(0, 0);
    return this;
}

void _Deallocate(void*);
struct S00761510
{
    void* FUN_00761510(unsigned int);
};
// @fnv 0x00761510
void* S00761510::FUN_00761510(unsigned int flags)
{
    ((FUN_007614a0_class*)this)->InitializeWithGlobal();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct NavMeshSearchLOSArray
{
    void FUN_006a8500();
};
struct FUN_00761760_class
{
    void FUN_00761760(int, int);
};
struct FUN_007615d0_class
{
    int pad;
    int* data;
    int size;
    int capacity;
    void FUN_007615d0(bool freeStorage);
};
// @fnv 0x007615d0
void FUN_007615d0_class::FUN_007615d0(bool freeStorage)
{
    if (data)
    {
        ((FUN_00761760_class*)this)->FUN_00761760((int)data, size);
        if (freeStorage)
        {
            ((NavMeshSearchLOSArray*)this)->FUN_006a8500();
            data = 0;
            capacity = 0;
        }
        size = 0;
    }
}

struct Holder_004b9900
{
    int FUN_004b9900(int);
};
struct NiFixedString
{
    void FUN_00761760(int* data, unsigned int n);
};
// Calls FUN_004b9900(0) on each of n consecutive int slots starting at data.
// @fnv 0x00761760
void NiFixedString::FUN_00761760(int* data, unsigned int n)
{
    for (unsigned int i = 0; i < n; ++i)
        ((Holder_004b9900*)(data + i))->FUN_004b9900(0);
}

struct GlobalObject_0076b930
{
    void __thiscall FUN_0076b930();
    GlobalObject_0076b930* __thiscall FUN_0076b870(unsigned int flags);
};
// Calls FUN_0076b930 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x0076b870
GlobalObject_0076b930* __thiscall GlobalObject_0076b930::FUN_0076b870(unsigned int flags)
{
    this->FUN_0076b930();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct SoundPlaybackHandle
{
    ~SoundPlaybackHandle();
};
struct FUN_0076b8a0_class
{
    BSSimpleList<SoundPlaybackHandle> m_kNode;
    ~FUN_0076b8a0_class();
};
// Destructor that removes all elements from the contained BSSimpleList.
// @fnv 0x0076b8a0
FUN_0076b8a0_class::~FUN_0076b8a0_class()
{
    m_kNode.RemoveAll();
}

namespace fnv_0076b900 {
struct SoundPlaybackHandle
{
    int m0;
    int m4;
    int m8;
    SoundPlaybackHandle(SoundPlaybackHandle const&);
};
struct FUN_0076b900 : SoundPlaybackHandle
{
    int fldC;
    FUN_0076b900(FUN_0076b900 const&);
};
// @fnv 0x0076b900
FUN_0076b900::FUN_0076b900(FUN_0076b900 const& o) : SoundPlaybackHandle(o)
{
    fldC = 0;
}
}  // namespace fnv_0076b900

namespace fnv_0076b930 {
struct SoundPlaybackHandle
{
    int _00;
    int _04;
    int _08;
    SoundPlaybackHandle(bool);
};
struct FUN_0076b930
{
    SoundPlaybackHandle _00;
    int _0C;
    FUN_0076b930();
};
// Initializes the object: constructs the first member with false and sets the field at offset 0x0C to 0.
// @fnv 0x0076b930
FUN_0076b930::FUN_0076b930() : _00(false)
{
    _0C = 0;
}
}  // namespace fnv_0076b930

struct WeatherEntry;
struct G2
{
    void __thiscall AddHead(WeatherEntry*&);
};
extern int g_011d970c;
int __cdecl FUN_0076bb00(WeatherEntry*, WeatherEntry*);
// Adds a WeatherEntry to the list at g_011d970c and sorts it using FUN_0076bb00 as the comparison.
// @fnv 0x0076baa0
void __cdecl FUN_0076baa0(WeatherEntry* apEntry)
{
    ((G2*)&g_011d970c)->AddHead(apEntry);
    ((BSSimpleList<WeatherEntry*>*)&g_011d970c)->Sort(&FUN_0076bb00);
}

// Compares the int at offset 0x214 of two objects, returning 1 if the first is greater, -1 if less, else 0.
// @fnv 0x0076bb00
int __cdecl FUN_0076bb00(void* pLeft, void* pRight)
{
    if (*((int*)((char*)pLeft + 0x214)) > *((int*)((char*)pRight + 0x214)))
        return 1;
    else if (*((int*)((char*)pLeft + 0x214)) < *((int*)((char*)pRight + 0x214)))
        return -1;
    else
        return 0;
}

extern "C" void* _pme;

// If _pme is set and its field at offset 0x1b8 equals param_1, clears that field to 0 and returns true; otherwise returns false.
// @fnv 0x00778b40
bool __cdecl ClearPmeIfMatches(int aiValue)
{
    if (_pme && *(int*)((char*)_pme + 0x1b8) == aiValue)
    {
        *(int*)((char*)_pme + 0x1b8) = 0;
        return true;
    }
    return false;
}

// @fnv 0x0077f9c0
int __cdecl FUN_0077f9c0(int a)
{
    return a * a;
}

void __cdecl operator delete(void*);
struct FUN_0077f9d0_class
{
    void ClearActorArray();
    void* FUN_0077f9d0(unsigned int flags);
};
// Calls ClearActorArray, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x0077f9d0
void* FUN_0077f9d0_class::FUN_0077f9d0(unsigned int flags)
{
    ClearActorArray();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct S2f850
{
    unsigned int FUN_00761540();
};
struct FUN_00761630_shell
{
    void ConstructSlotItems(int*, int);
};
struct FUN_0043ba10_shell
{
    FUN_0043ba10_shell* FUN_0043ba10(unsigned int);
};

struct FUN_007614c0_shell
{
    int m_iElementCount;
    int* m_data;
    unsigned int FUN_007614c0(unsigned int index);
};

// @fnv 0x007614c0
unsigned int FUN_007614c0_shell::FUN_007614c0(unsigned int index)
{
    unsigned int size = ((S2f850*)this)->FUN_00761540();
    ((FUN_00761630_shell*)this)->ConstructSlotItems(m_data + size, 1);
    ((FUN_0043ba10_shell*)(m_data + size))->FUN_0043ba10(index);
    return size;
}

struct FUN_007616d0_class
{
    virtual void v0();
    virtual int Write(unsigned int);
    void ConstructSlotItems(int, unsigned int);
    int iSize;
    int iPosition;
    int iDataLength;
    void InitializeBuffer(unsigned int requested, unsigned int savedSize);
};
// @fnv 0x007616d0
void FUN_007616d0_class::InitializeBuffer(unsigned int requested, unsigned int savedSize)
{
    iSize = 0;
    iPosition = 0;
    iDataLength = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        iSize = Write(requested);
        iDataLength = requested;
    }
    if (savedSize > 0)
    {
        ConstructSlotItems(iSize, savedSize);
        iPosition = savedSize;
    }
}

struct GO
{
    operator unsigned int() const;
    bool IsNotEqual(unsigned int value);
};

// @fnv 0x0076a3b0
bool GO::IsNotEqual(unsigned int value)
{
    return value != (unsigned int)*this;
}

struct TESFaction_RankDataView
{
    unsigned char* GetRankDataList();
    bool HasFlag40();
};
// @fnv 0x0077a590
bool TESFaction_RankDataView::HasFlag40()
{
    return (GetRankDataList()[0] & 0x40) != 0;
}

struct BSSimpleArrayActor
{
    void* vtbl;
    void Clear(bool);
};

struct FUN_0077f9a0_class
{
    void* vtbl;
    void ClearActorArray();
};

// @fnv 0x0077f9a0
void FUN_0077f9a0_class::ClearActorArray()
{
    vtbl = &DAT_010738cc;
    ((BSSimpleArrayActor*)this)->Clear(true);
}

struct FUN_00761540_cls
{
    virtual void v0();
    virtual int v1(int arg);
    int m_04;
    int m_08;
    int m_0c;
    bool FUN_00438b90();
    int FUN_009a3910();
    void FUN_0042fc00(int a, int b);
    unsigned int FUN_00761540();
};

// @fnv 0x00761540
unsigned int FUN_00761540_cls::FUN_00761540()
{
    if (FUN_00438b90())
    {
        if (m_0c == 0)
        {
            int v = 4;
            m_04 = v1(v);
            m_0c = v;
        }
        else
        {
            int p = FUN_009a3910();
            FUN_0042fc00(p, m_08);
            m_0c = p;
        }
    }
    m_08 = m_08 + 1;
    return m_08 - 1;
}

struct SlotItem
{
    int m_iWordAt00;
    SlotItem();
    void* operator new(unsigned int size, void* where);
    void operator delete(void* p, void* where);
};

SlotItem::SlotItem()
{}

void* SlotItem::operator new(unsigned int size, void* where)
{
    return where;
}

void SlotItem::operator delete(void* p, void* where)
{}

// Placement-constructs count SlotItem objects into the array arr.
// @fnv 0x00761630
void FUN_00761630_shell::ConstructSlotItems(int* pItems, int count)
{
    for (unsigned int i = 0; i < (unsigned int)count; i++)
    {
        new (&((SlotItem*)pItems)[i]) SlotItem;
    }
}

class B766A50Menu
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
    void* m_apSlots[8];

    bool HasAllSlots(int& riIndex);
};

// Returns false if any of the 8 m_apSlots entries is null, otherwise true; riIndex is left at 8 after the loop.
// @fnv 0x00766a50
bool B766A50Menu::HasAllSlots(int& riSlotIndex)
{
    for (riSlotIndex = 0; riSlotIndex < 8; riSlotIndex++)
    {
        if (!m_apSlots[riSlotIndex])
            return false;
    }
    return true;
}

class B76B560Object
{
  public:
    virtual ~B76B560Object();
};

class B76B560Base
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

    ~B76B560Base();
};

class FUN_0076b560 : public B76B560Base
{
  public:
    B76B560Object* m_pkFirst;
    B76B560Object* m_pkSecond;

    ~FUN_0076b560();
};

// Destructor that deletes m_pkFirst and m_pkSecond.
// @fnv 0x0076b560
FUN_0076b560::~FUN_0076b560()
{
    delete m_pkFirst;
    delete m_pkSecond;
}

struct FUN_0076b900
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_0076b900* next;
    FUN_0076b900(GO* owner);
};

struct Owner : GO
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_0076b900* first;

    void FUN_00418900(Flt* value);
    void FUN_0076b6a0(Flt* value);
};

// If value does not pass Equals(0) and IsNotEqual(0) is true, prepends a new FUN_0076b900 node to first, then calls FUN_00418900(value).
// @fnv 0x0076b6a0
void Owner::FUN_0076b6a0(Flt* value)
{
    if (value->Equals(0))
    {
    }
    else
    {
        if (IsNotEqual(0))
        {
            FUN_0076b900* entry = new FUN_0076b900(this);
            entry->next = first;
            first = entry;
            FUN_00418900(value);
        }
        else
        {
            FUN_00418900(value);
        }
    }
}

struct Menu
{
    Menu();
    virtual ~Menu();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
};
struct ListStub
{
    int item;
    ListStub* next;
    ListStub();
    ~ListStub();
};
struct AXStub
{
    int a0;
    int a4;
    int a8;
    int ac;
    AXStub();
    ~AXStub();
};
struct GO41a250
{
    int b0;
    int b4;
    int b8;
    GO41a250();
    ~GO41a250();
};
struct B6815c0
{
    int c0;
    int c4;
    int c8;
    int cc;
    int d0;
    int d4;
    int d8;
    int dc;
    int e0;
    int e4;
    int e8;
    int ec;
    int f0;
    B6815c0();
    ~B6815c0();
};
struct C76bda0
{
    int e0;
    int e4;
    int e8;
    int ec;
    int f0;
    int f4;
    int f8;
    int fc;
    C76bda0();
};
struct TimeGlobalStub
{
    int GetTime();
};
struct GO709f00Stub
{
    bool Check();
};
extern TimeGlobalStub g_timeGlobal;
extern GO709f00Stub g_011d8a38;
extern int DAT_011d96ac;

struct FUN_0076bb40 : Menu
{
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
    int unk180;
    int unk184;
    float unk188;
    ListStub list18c;
    int unk194;
    AXStub ax198;
    int unk1a8;
    GO41a250 go1ac;
    int unk1b8;
    int unk1bc;
    unsigned int flags1c0;
    int unk1c4;
    B6815c0 b1c8;
    bool unk1fc;
    int unk200;
    bool unk204;
    bool unk205;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    C76bda0 c224;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    bool unk254;
    ListStub list258;
    bool unk260;
    bool unk261;
    ListStub list264;
    ListStub list26c;
    float unk274;
    FUN_0076bb40();
    virtual ~FUN_0076bb40();
};

void* __cdecl memset(void*, int, unsigned int);

// @fnv 0x0076bb40
FUN_0076bb40::FUN_0076bb40()
{
    memset(&unk28, 0, 0x158);
    unk184 = 0;
    unk188 = 0.0f;
    unk1b8 = 0;
    unk21c = 0;
    unk244 = 0;
    unk248 = g_timeGlobal.GetTime();
    unk24c = -1;
    unk250 = -1;
    flags1c0 = (g_011d8a38.Check() ? 0x40 : 0) | 0x3f | 0x80 | 0x100 | 0x200 | 0x400 | 0x800 | 0x1000 | 0x2000 |
               0x4000 | 0x8000 | 0x10000;
    unk1c4 = 4;
    unk254 = false;
    DAT_011d96ac = g_timeGlobal.GetTime();
    unk1fc = false;
    unk200 = 0;
    unk274 = 0.0f;
    unk204 = false;
    unk194 = 0;
    unk1a8 = 0;
    unk205 = false;
    unk260 = false;
    unk261 = false;
    unk20c = 0;
}

namespace fnv_007617a0 {
class Menu
{
  public:
    Menu();
    virtual ~Menu();
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
};
struct FUN_007642f0
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
    FUN_007642f0();
    ~FUN_007642f0();
};
struct GlobalObject_0041a250
{
    int unk00;
    int unk04;
    int unk08;
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
};
struct B006815c0
{
    int unk00;
    int unk04;
    B006815c0();
};
extern bool DAT_011d9514;
extern float DAT_011a008c;
void* __cdecl GetInstance();
struct FUN_007617a0 : Menu
{
    FUN_007642f0 member40;
    void* unk70;
    GlobalObject_0041a250 member74;
    int unk80;
    bool unk84;
    char unk85;
    short unk86;
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
    bool unk104;
    char unk105;
    short unk106;
    float unk108;
    int unk10c;
    B006815c0 member110;
    B006815c0 member118;
    B006815c0 member120;
    int unk128;
    int unk12c;
    bool unk130;
    bool unk131;
    short unk132;
    int unk134;
    bool unk138;
    bool unk139;
    bool unk13a;
    FUN_007617a0();
    virtual ~FUN_007617a0();
};
// @fnv 0x007617a0
FUN_007617a0::FUN_007617a0()
{
    unk80 = 0;
    DAT_011d9514 = true;
    unk130 = false;
    unk131 = false;
    unk138 = false;
    unk108 = 0.0f;
    unk28 = 0;
    unk2c = 0;
    unk70 = GetInstance();
    unk84 = false;
    unk104 = false;
    unk12c = 0;
    DAT_011a008c = 100.0f;
    unk139 = false;
    unk13a = false;
    unk10c = 0;
}
}  // namespace fnv_007617a0

struct WeatherEntry
{
    int unk00;
    int kind;
    char title[260];
    char subtitle[260];
    int unk210;
    int priority;
    int titleFont;
    int subtitleFont;
    char icon[260];
};
void* __cdecl operator new(unsigned int);
int __cdecl strcpy_s(char*, unsigned int, const char*);
void __cdecl FUN_005b5e40(int, const char*, ...);
void __cdecl FUN_0076bad0(char*);
// Allocates a WeatherEntry, copies the title, subtitle and icon strings, validates the fonts, and queues the entry by priority.
// @fnv 0x0076b960
void __cdecl FUN_0076b960(const char* title, const char* subtitle, int priority, int extra, int titleFont,
                          int subtitleFont, const char* icon)
{
    WeatherEntry* entry = new WeatherEntry;
    entry->kind = 3;
    strcpy_s(entry->title, 260, title);
    strcpy_s(entry->subtitle, 260, subtitle);
    entry->unk210 = extra;
    entry->priority = priority;
    if (titleFont == 0)
    {
        FUN_005b5e40(
            7,
            "QuestUpdateManager::SetCustomQuestText() - FONT_1 is an invalid value for aiCustomTextTitleFont.  Setting to FONT_NONE.");
        titleFont = -1;
    }
    entry->titleFont = titleFont;
    if (subtitleFont == 0)
    {
        FUN_005b5e40(
            7,
            "QuestUpdateManager::SetCustomQuestText() - FONT_1 is an invalid value for aiCustomTextSubtitleFont.  Setting to FONT_NONE.");
        subtitleFont = -1;
    }
    entry->subtitleFont = subtitleFont;
    strcpy_s(entry->icon, 260, icon);
    switch (priority)
    {
    case 1:
    case 2:
        FUN_0076bad0((char*)entry);
        break;
    case 0:
        FUN_0076baa0(entry);
        break;
    default:
        FUN_005b5e40(
            7,
            "QuestUpdateManager::SetCustomQuestText() - Invalid aiCustomQueuePriority (%i)!  Setting to HCQQP_NORMAL.",
            priority);
        FUN_0076bad0((char*)entry);
        break;
    }
}

struct Arr77a400
{
    int m_unk00;
    void* m_pData;
    unsigned int m_Size;
    unsigned int GetSize();
    int* GetAt(int index);
};

struct C77a400
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
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int m_unk6f4;
    int m_unk6f8;
    int m_unk6fc;
    int m_unk700;
    int m_unk704;
    Arr77a400 m_Arr708;

    unsigned int GetFirstOrFallback();
};

// Returns the first element of m_Arr708 if the array is non-empty, otherwise returns m_unk6f4.
// @fnv 0x0077a400
unsigned int C77a400::GetFirstOrFallback()
{
    return this->m_Arr708.GetSize() > 0 ? (unsigned int)*this->m_Arr708.GetAt(0) : (unsigned int)this->m_unk6f4;
}

class HKTile
{
  public:
    const char* FUN_00a011f0(int m_iValueId);
    float FUN_00a011b0(int m_iValueId);
    void FUN_00a01350(int m_iValueId, const char* pcValue, int iFlag);
    void FUN_00700320(int m_iValueId, int iValue);
    void FUN_00a012d0(int m_iValueId, float fValue, int iFlag);
};

struct HKScreen
{
    int unk00[51];
    HKTile* m_pkTextTile;  // +0xcc
};
extern HKScreen* DAT_011d95bc;

struct HKWordNode
{
    char** FUN_006815c0();
    HKWordNode* FUN_00726070();
};

struct HKWordSet
{
    bool FUN_0076a3d0(const char* pcWord);
    void AssignString(const char* pcWord);
    unsigned int FUN_0044edb0(int iFlag);
};

struct HKOffsetMap
{
    int FUN_0049c680(unsigned int* puiOffset, int iFlag);
};

struct HKSoundHandle
{
    unsigned int m_uiID;
    unsigned int m_uiState;
    unsigned int m_uiValue1;
    ~HKSoundHandle();
    void FUN_00ad8d10();
    bool IsNotEqual(int iFlag);
    void FUN_00ad8870(int iDelay);
    bool Play(bool bLoop);
};
struct HKSoundNode
{
    HKSoundHandle* FUN_006815c0();
    HKSoundNode* FUN_0084e3a0();
};
struct HKSoundList : HKSoundNode
{
    void ClearQueue();
    void FUN_0076b6a0(const HKSoundHandle& kSound);
};
extern HKSoundList DAT_011d9604;

class HKAudio
{
  public:
    static HKAudio* FUN_00ad9060();
    HKSoundHandle ResolveAudioHandle(const char* pcName, int iFlags);
};

int FUN_00ec86e1(int iChar);
void* FUN_00403d30(void* pvDst, int iValue, unsigned int uiSize);
void* FUN_00401460(void* pvDst, const void* pvSrc, unsigned int uiSize);
unsigned int FUN_0044a670(const char* pcString);

class HKMenu
{
  public:
    int unk000[56];
    HKWordSet m_kGuessed;  // +0xe0
    int unk0e4[12];
    HKTile* m_pkHighlight;  // +0x114
    int unk118[26];
    HKWordNode m_kWords;  // +0x180
    int unk184;
    HKOffsetMap m_kSymbols;  // +0x188
    int unk18c[7];
    unsigned int m_uiWordCount;      // +0x1a8
    unsigned int m_uiWordLength;     // +0x1ac
    unsigned int* m_puiWordOffsets;  // +0x1b0
    int unk1b4;
    int unk1b8;
    int m_iLastPos;        // +0x1bc
    HKTile* m_pkLastTile;  // +0x1c0
    int unk1c4[5];
    bool m_bShowing;  // +0x1d8

    int GetScaledValue();
    void FUN_00768020();
    void FUN_0076a670(char* pcOut, const char* pcText);
    HKTile* FUN_00767bb0(int iColumn, unsigned int uiLine);
    void UpdateHighlight();
};

// Recomputes the cursor position and the word at it from the text tile, updates the guessed-word state and sounds, and sets m_pkHighlight's text and coordinates.
// @fnv 0x00769b50
void HKMenu::UpdateHighlight()
{
    int iPos = GetScaledValue() - 7;
    if ((iPos == m_iLastPos && DAT_011d95bc->m_pkTextTile == m_pkLastTile) || (iPos < 0 && m_iLastPos < 0))
        return;
    m_iLastPos = iPos;
    m_pkLastTile = DAT_011d95bc->m_pkTextTile;
    if (iPos < 0)
    {
        FUN_00768020();
        m_bShowing = false;
        return;
    }
    if (m_bShowing)
    {
        FUN_00768020();
        if (!FUN_00ec86e1(DAT_011d95bc->m_pkTextTile->FUN_00a011f0(0xfc4)[iPos + 7]))
        {
            m_bShowing = false;
            m_pkLastTile = 0;
        }
        return;
    }
    unsigned int uiElapsedMilliseconds = (unsigned int)((DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0x1004) * 17.0 +
                                                         DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0xfac)) *
                                                            12.0 +
                                                        iPos);
    HKWordNode* pkNodeTmp = &m_kWords;
    for (unsigned int j = 0; j < m_uiWordCount; j++)
    {
        if (uiElapsedMilliseconds >= m_puiWordOffsets[j] &&
            uiElapsedMilliseconds < m_puiWordOffsets[j] + m_uiWordLength)
            break;
        else
            pkNodeTmp = pkNodeTmp->FUN_00726070();
    }
    char acWordNext[32];
    FUN_00403d30(acWordNext, 0, 0x20);
    if (pkNodeTmp)
        FUN_00401460(acWordNext, *pkNodeTmp->FUN_006815c0(), m_uiWordLength);
    else if (!m_kSymbols.FUN_0049c680(&uiElapsedMilliseconds, 0))
        FUN_0076a670(acWordNext, DAT_011d95bc->m_pkTextTile->FUN_00a011f0(0xfc4) + GetScaledValue());
    else
        acWordNext[0] = DAT_011d95bc->m_pkTextTile->FUN_00a011f0(0xfc4)[GetScaledValue()];
    if (m_kGuessed.FUN_0076a3d0(acWordNext))
    {
        m_kGuessed.AssignString(acWordNext);
        for (HKSoundNode* pkSound = &DAT_011d9604; pkSound && pkSound->FUN_006815c0()->IsNotEqual(-1);
             pkSound = pkSound->FUN_0084e3a0())
            pkSound->FUN_006815c0()->FUN_00ad8d10();
        DAT_011d9604.ClearQueue();
        unsigned int ItemUpdateArray = FUN_0044a670(acWordNext);
        while (ItemUpdateArray--)
        {
            HKSoundHandle kSound = HKAudio::FUN_00ad9060()->ResolveAudioHandle("UIHackingCharSingle", 0x121);
            DAT_011d9604.FUN_0076b6a0(kSound);
            if (ItemUpdateArray)
                kSound.FUN_00ad8870((int)(m_kGuessed.FUN_0044edb0(0) * ItemUpdateArray * 1.5));
            else
                kSound.Play(false);
        }
    }
    bool bFound = false;
    iPos = GetScaledValue();
    if (pkNodeTmp)
    {
        const char* pcText = DAT_011d95bc->m_pkTextTile->FUN_00a011f0(0xfc4);
        while (FUN_00ec86e1(pcText[iPos - 1]))
            iPos--;
        for (unsigned int k = 1; !bFound && k < m_uiWordLength; k++)
        {
            int iXNew = (int)DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0xfa1);
            int iY = (int)DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0xfa2);
            int iX2Cur = iXNew + 0x77;
            int iY2 = iY;
            if (!pcText[iPos + k])
            {
                bFound = true;
                iXNew += iPos * 0x11;
                if (DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0xfac) + 1.0 < 17.0)
                    iY2 += (int)DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0xfb0);
                else
                {
                    HKTile* pkLine =
                        FUN_00767bb0(0, (unsigned int)DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0x1004) + 1);
                    iX2Cur = (int)(pkLine->FUN_00a011b0(0xfa1) + 119.0);
                    iY2 = (int)pkLine->FUN_00a011b0(0xfa2);
                }
            }
            else if (!FUN_00ec86e1(pcText[iPos + k]))
            {
                bFound = true;
                k = m_uiWordLength - k;
                if (DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0xfac) != 0.0)
                {
                    iXNew += (0x13 - k) * 0x11;
                    iY -= (int)DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0xfb0);
                }
                else
                {
                    HKTile* pkPrevLine =
                        FUN_00767bb0(0x10, (unsigned int)DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0x1004) - 1);
                    iXNew = (int)(pkPrevLine->FUN_00a011b0(0xfa1) + (0x13 - k) * 0x11);
                    iY = (int)pkPrevLine->FUN_00a011b0(0xfa2);
                }
            }
            if (bFound)
            {
                char cSaved = acWordNext[k];
                acWordNext[k] = 0;
                m_pkHighlight->FUN_00a01350(0x1004, acWordNext, 1);
                m_pkHighlight->FUN_00700320(0x1005, iXNew);
                m_pkHighlight->FUN_00700320(0x1006, iY);
                acWordNext[k] = cSaved;
                m_pkHighlight->FUN_00a01350(0x1007, &acWordNext[k], 1);
                m_pkHighlight->FUN_00700320(0x1008, iX2Cur);
                m_pkHighlight->FUN_00700320(0x1009, iY2);
            }
        }
    }
    if (!bFound)
    {
        m_pkHighlight->FUN_00a01350(0x1004, acWordNext, 1);
        m_pkHighlight->FUN_00a012d0(0x1005, DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0xfa1) + iPos * 0x11, 1);
        m_pkHighlight->FUN_00a012d0(0x1006, DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0xfa2), 1);
        m_pkHighlight->FUN_00700320(0x1008, -1);
    }
}
