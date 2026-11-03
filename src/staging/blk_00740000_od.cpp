
// src/staging/blk_00740000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_00740960_Class
{
    unsigned int FUN_00740960();
};

// @fnv 0x00740960
unsigned int FUN_00740960_Class::FUN_00740960()
{
    return *(unsigned int*)((char*)this + 0x628);
}

struct FUN_00752df0_class
{
    int CompareToTwentyOneToTwentySix(int value);
};

// Returns -1 if value is below 0x15, 1 if above 0x1a, and 0 when value is in that range.
// @fnv 0x00752df0
int FUN_00752df0_class::CompareToTwentyOneToTwentySix(int value)
{
    if (value < 0x15)
        return -1;
    if (value > 0x1a)
        return 1;
    return 0;
}

extern "C" void* DAT_01071aec;

struct AX
{
    void __thiscall FUN_006b3eb0(unsigned int, unsigned int);
    AX* __thiscall FUN_00753070();
};

// Sets the object's vtable pointer to DAT_01071aec, calls FUN_006b3eb0(0, 0), and returns this.
// @fnv 0x00753070
AX* __thiscall AX::FUN_00753070()
{
    *(void**)this = &DAT_01071aec;
    FUN_006b3eb0(0, 0);
    return this;
}

namespace fnv_007530a0 {
extern int DAT_01071aec;

struct GlobalObject_00869f00
{
    void Clear(bool);
    void FUN_007530a0();
};

// @fnv 0x007530a0
void GlobalObject_00869f00::FUN_007530a0()
{
    *reinterpret_cast<int**>(this) = &DAT_01071aec;
    Clear(true);
}
}  // namespace fnv_007530a0

extern int DAT_01071b00;

struct GlobalObject_00869f00
{
    int* p;
    void Clear(bool);
    void FUN_007530f0();
};

// @fnv 0x007530f0
void GlobalObject_00869f00::FUN_007530f0()
{
    p = &DAT_01071b00;
    Clear(true);
}

namespace fnv_00753110 {
struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
    AX* FUN_00753110();
};

extern void* DAT_01071b14;

// Sets the object's vtable pointer to DAT_01071b14, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x00753110
AX* AX::FUN_00753110()
{
    *reinterpret_cast<void**>(this) = &DAT_01071b14;
    FUN_006b3eb0(0, 0);
    return this;
}
}  // namespace fnv_00753110

namespace fnv_00753210 {
extern int DAT_01071b14;
struct GlobalObject_00869f00
{
    int* p;
    void Clear(bool);
};
struct FUN_00753210Class
{
    int* p;
    void FUN_00753210();
};
// @fnv 0x00753210
void __thiscall FUN_00753210Class::FUN_00753210()
{
    p = &DAT_01071b14;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_00753210

struct FUN_00754a00_cls
{
    void __thiscall SetTraitSelected(int a1, int a2);
    void __thiscall FUN_00754930(int a1);
};

// @fnv 0x00754930
void __thiscall FUN_00754a00_cls::FUN_00754930(int a1)
{
    SetTraitSelected(a1, 2);
}

struct FUN_00759540_class
{
    bool IsFlag8Set();
};

// @fnv 0x00759540
bool FUN_00759540_class::IsFlag8Set()
{
    return reinterpret_cast<const unsigned char*>(this)[0xa5] & 8;
}

struct FUN_00759d80_Class
{
    char m_padded[0x29];
    unsigned char m_flag;
    unsigned char FUN_00759d80();
};

// @fnv 0x00759d80
unsigned char FUN_00759d80_Class::FUN_00759d80()
{
    return m_flag;
}

struct S007530c0
{
    S007530c0* __thiscall FUN_007530c0();
};
// Sets the vtable pointer to DAT_01071b00, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x007530c0
S007530c0* __thiscall S007530c0::FUN_007530c0()
{
    *(int*)this = (int)&DAT_01071b00;
    ((AX*)this)->FUN_006b3eb0(0, 0);
    return this;
}

struct FUN_0072ba80_shell
{
    char _pad[4];
    int* m_data;
    int m_uiItemCount;
    void __thiscall FUN_0072ba80(void*, unsigned int);
    void __thiscall FUN_00753140();
};
// @fnv 0x00753140
void __thiscall FUN_0072ba80_shell::FUN_00753140()
{
    if (m_uiItemCount == 0)
        return;
    FUN_0072ba80(m_data + m_uiItemCount - 1, 1);
    m_uiItemCount--;
}

extern "C" void Deallocate(void*);

struct FUN_00753180_Class
{
    void __thiscall FUN_007530a0();
    void* __thiscall FUN_00753180(unsigned int flags);
};

// @fnv 0x00753180
void* __thiscall FUN_00753180_Class::FUN_00753180(unsigned int flags)
{
    FUN_007530a0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void _Deallocate(void*);
struct FUN_007531b0_Class
{
    void* __thiscall FUN_007531b0(unsigned int);
};
// @fnv 0x007531b0
void* __thiscall FUN_007531b0_Class::FUN_007531b0(unsigned int flags)
{
    ((GlobalObject_00869f00*)this)->FUN_007530f0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_00753210_Class
{
    void __thiscall FUN_00753210();
};
struct FUN_007531e0_Class
{
    void* __thiscall FUN_007531e0(unsigned int flags);
};
// @fnv 0x007531e0
void* __thiscall FUN_007531e0_Class::FUN_007531e0(unsigned int flags)
{
    ((FUN_00753210_Class*)this)->FUN_00753210();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct StrMem
{
    StrMem();
    ~StrMem();
    void FUN_006ffe10();
};
struct FUN_00759f20_holder
{
    char* AssignString(const char*);
};
struct FUN_00759eb0 : public StrMem
{
    FUN_00759eb0(const char* s);
};
// @fnv 0x00759eb0
FUN_00759eb0::FUN_00759eb0(const char* s)
{
    FUN_006ffe10();
    ((FUN_00759f20_holder*)this)->AssignString(s);
}

struct FNStub
{
    char* GetFullName();
};
struct BGSNote
{
    FNStub* GetNoteTexture();
};
struct Tile
{
    void Set(int, int);
    void Set(int, const char*, bool);
};
struct TileProcessor
{
    void ProcessAllTiles();
};
struct FUN_00759470_Class
{
    void UpdateNoteDisplay(BGSNote* a1);
};
// @fnv 0x00759470
void FUN_00759470_Class::UpdateNoteDisplay(BGSNote* pNote)
{
    ((TileProcessor*)*((int*)this + 0x3a))->ProcessAllTiles();
    ((Tile*)*((int*)this + 0xb))->Set(0xfa3, 0);
    ((Tile*)*((int*)this + 0xc))->Set(0xfa9, 255);
    ((Tile*)*((int*)this + 0xc))->Set(0xfa3, 1);
    ((Tile*)*((int*)this + 0x18))->Set(0xfa3, 0);
    if (((FUN_00759540_class*)*((int*)this + 0x2a))->IsFlag8Set())
    {
        ((Tile*)*((int*)this + 0x11))->Set(0xfa3, 0);
        ((Tile*)*((int*)this + 0x19))->Set(0xfa3, 0);
    }
    ((Tile*)*((int*)this + 0xc))->Set(0xfcc, pNote->GetNoteTexture()->GetFullName(), true);
}

struct SL
{
    SL();
    ~SL();
};

struct Str6a70 : public StrMem
{
    char m_ucUnknownByte[7];
    Str6a70& operator=(const char*);
};

extern const char $SG3295[];

struct FUN_00759330 : public Str6a70
{
    int m_w;
    int m_h;
    int m_s;
    int m_usTrailingValue;
    int m_zero;
    char m_iThirdValue;
    char m_ucUnknownByte[3];
    SL m_sl;

    FUN_00759330(int w, int h, int s, int e, char c);
};

// @fnv 0x00759330
FUN_00759330::FUN_00759330(int aiWidth, int aiHeight, int s, int aiExtra, char c)
{
    this->Str6a70::operator=($SG3295);
    m_w = aiWidth;
    m_h = aiHeight;
    m_s = s;
    m_usTrailingValue = aiExtra;
    m_zero = 0;
    m_iThirdValue = c;
}

struct FUN_00752cb0_Slot
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int __thiscall FUN_0044ddc0();
};

struct FUN_00752cb0_Group
{
    FUN_00752cb0_Slot items[7];
};

struct FUN_00752cb0_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* __thiscall FUN_006a7ad0(int flags);
};

struct FUN_00752cb0_Inner
{
    int __thiscall FUN_008d80e0();
};

struct FUN_00752cb0_cls
{
    int __thiscall FUN_00752cb0(int a1, int a2);
};

// Counts up to 7 slots whose FUN_0044ddc0 value is positive and whose FUN_008d80e0 result equals a2, returning the count multiplied by a2.
// @fnv 0x00752cb0
int __thiscall FUN_00752cb0_cls::FUN_00752cb0(int aiGroupIndex, int aiMatchValue)
{
    int i = 0;
    int count = 0;
    while (i < 7 && ((FUN_00752cb0_Group*)((char*)this + 0xb44))[aiGroupIndex].items[i].FUN_0044ddc0() > 0)
    {
        if (((FUN_00752cb0_Inner*)*(
                 void**)((FUN_00752cb0_Holder*)&((FUN_00752cb0_Group*)((char*)this + 0xb44))[aiGroupIndex].items[i])
                 ->FUN_006a7ad0(0))
                ->FUN_008d80e0() == aiMatchValue)
        {
            count++;
        }
        i++;
    }
    return count * aiMatchValue;
}

class Menu
{
  public:
    Menu();
    virtual ~Menu();
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
};

struct ListBox_ItemChange___
{
    ListBox_ItemChange___();
    ~ListBox_ItemChange___();
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
};

struct FUN_0057bd10_S
{
    FUN_0057bd10_S(int);
    ~FUN_0057bd10_S();
    int unk00;
    char unk04;
    int unk08;
};

struct GlobalObject_0041a250
{
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
    void Assign(const FUN_0057bd10_S& src);
    int unk00;
    char unk04;
    int unk08;
};

extern int DAT_011d93fc;

class FUN_0075b0d0 : public Menu
{
  public:
    FUN_0075b0d0();
    virtual ~FUN_0075b0d0();
    BSSimpleList<int*> list78;
    int unk80;
    int unk84;
    char unk88;
    char unk89;
    int unk8C;
    int unk90;
    int unk94;
    ListBox_ItemChange___ list98;
    ListBox_ItemChange___ listC8;
    int unkF8;
    int unkFC;
    GlobalObject_0041a250 obj100;
};

// @fnv 0x0075b0d0
FUN_0075b0d0::FUN_0075b0d0()
{
    DAT_011d93fc = 0;
    unkF8 = 0;
    unk84 = 0;
    unk88 = 0;
    unk89 = 0;
    unk90 = 0;
    unk8C = 0;
    unk94 = 3;
    {
        FUN_0057bd10_S tmp(0);
        obj100.Assign(tmp);
    }
}

namespace fnv_0075f070 {
class Menu
{
  public:
    Menu();
    virtual ~Menu();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

struct MenuRefObj
{
    void IncRefCount();
    void DecRefCount();
};

struct ImageSpaceEffectParamStub
{
    float a;
    float b;
    float c;
    float d;
    ImageSpaceEffectParamStub(float a1, float b1, float c1, float d1);
};

struct MenuListStub
{
    MenuListStub();
    ~MenuListStub();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

extern ImageSpaceEffectParamStub g_defaultImageSpaceParam;
extern int g_menuGlobalState;

class FUN_0075f070 : public Menu
{
  public:
    FUN_0075f070();
    virtual ~FUN_0075f070();
    int unk28;
    int unk2C;
    NiPointer<MenuRefObj> unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    ImageSpaceEffectParamStub unk50;
    MenuListStub unk60;
    int unk70;
    int unk74;
    float unk78;
    int unk7C;
};

// Initializes the menu's fields to zero/default values, assigns g_defaultImageSpaceParam to unk50, and resets g_menuGlobalState to 0.
// @fnv 0x0075f070
FUN_0075f070::FUN_0075f070() : unk30(0), unk50(0.0f, 0.0f, 0.0f, 0.0f)
{
    unk28 = 0;
    unk34 = 0;
    unk38 = 0;
    unk3C = 0;
    unk30 = 0;
    unk40 = 1;
    unk44 = 1;
    unk48 = 0;
    unk4C = 0;
    unk50 = g_defaultImageSpaceParam;
    unk2C = 0;
    unk70 = 0;
    unk78 = 0.0f;
    unk7C = 0;
    g_menuGlobalState = 0;
}
}  // namespace fnv_0075f070

// @fnv 0x0075f5f0
int __cdecl FUN_0075f5f0()
{
    return (int)1047u;
}

struct FUN_00752d40_Obj
{
    int __thiscall FUN_004036b0();
    int __thiscall FUN_008d80e0();
};
struct FUN_00752d40_Item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int __thiscall FUN_0044ddc0();
    FUN_00752d40_Obj*& __thiscall FUN_006a7ad0(int index);
};
struct FUN_00752d40_cls
{
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C;
    int unk150, unk154, unk158, unk15C, unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4, unk1A8, unk1AC;
    int unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    int unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC, unk200, unk204, unk208, unk20C;
    int unk210, unk214, unk218, unk21C, unk220, unk224, unk228, unk22C, unk230, unk234, unk238, unk23C;
    int unk240, unk244, unk248, unk24C, unk250, unk254, unk258, unk25C, unk260, unk264, unk268, unk26C;
    int unk270, unk274, unk278, unk27C, unk280, unk284, unk288, unk28C, unk290, unk294, unk298, unk29C;
    int unk2A0, unk2A4, unk2A8, unk2AC, unk2B0, unk2B4, unk2B8, unk2BC, unk2C0, unk2C4, unk2C8, unk2CC;
    int unk2D0, unk2D4, unk2D8, unk2DC, unk2E0, unk2E4, unk2E8, unk2EC, unk2F0, unk2F4, unk2F8, unk2FC;
    int unk300, unk304, unk308, unk30C, unk310, unk314, unk318, unk31C, unk320, unk324, unk328, unk32C;
    int unk330, unk334, unk338, unk33C, unk340, unk344, unk348, unk34C, unk350, unk354, unk358, unk35C;
    int unk360, unk364, unk368, unk36C, unk370, unk374, unk378, unk37C, unk380, unk384, unk388, unk38C;
    int unk390, unk394, unk398, unk39C, unk3A0, unk3A4, unk3A8, unk3AC, unk3B0, unk3B4, unk3B8, unk3BC;
    int unk3C0, unk3C4, unk3C8, unk3CC, unk3D0, unk3D4, unk3D8, unk3DC, unk3E0, unk3E4, unk3E8, unk3EC;
    int unk3F0, unk3F4, unk3F8, unk3FC, unk400, unk404, unk408, unk40C, unk410, unk414, unk418, unk41C;
    int unk420, unk424, unk428, unk42C, unk430, unk434, unk438, unk43C, unk440, unk444, unk448, unk44C;
    int unk450, unk454, unk458, unk45C, unk460, unk464, unk468, unk46C, unk470, unk474, unk478, unk47C;
    int unk480, unk484, unk488, unk48C, unk490, unk494, unk498, unk49C, unk4A0, unk4A4, unk4A8, unk4AC;
    int unk4B0, unk4B4, unk4B8, unk4BC, unk4C0, unk4C4, unk4C8, unk4CC, unk4D0, unk4D4, unk4D8, unk4DC;
    int unk4E0, unk4E4, unk4E8, unk4EC, unk4F0, unk4F4, unk4F8, unk4FC, unk500, unk504, unk508, unk50C;
    int unk510, unk514, unk518, unk51C, unk520, unk524, unk528, unk52C, unk530, unk534, unk538, unk53C;
    int unk540, unk544, unk548, unk54C, unk550, unk554, unk558, unk55C, unk560, unk564, unk568, unk56C;
    int unk570, unk574, unk578, unk57C, unk580, unk584, unk588, unk58C, unk590, unk594, unk598, unk59C;
    int unk5A0, unk5A4, unk5A8, unk5AC, unk5B0, unk5B4, unk5B8, unk5BC, unk5C0, unk5C4, unk5C8, unk5CC;
    int unk5D0, unk5D4, unk5D8, unk5DC, unk5E0, unk5E4, unk5E8, unk5EC, unk5F0, unk5F4, unk5F8, unk5FC;
    int unk600, unk604, unk608, unk60C, unk610, unk614, unk618, unk61C, unk620, unk624, unk628, unk62C;
    int unk630, unk634, unk638, unk63C, unk640, unk644, unk648, unk64C, unk650, unk654, unk658, unk65C;
    int unk660, unk664, unk668, unk66C, unk670, unk674, unk678, unk67C, unk680, unk684, unk688, unk68C;
    int unk690, unk694, unk698, unk69C, unk6A0, unk6A4, unk6A8, unk6AC, unk6B0, unk6B4, unk6B8, unk6BC;
    int unk6C0, unk6C4, unk6C8, unk6CC, unk6D0, unk6D4, unk6D8, unk6DC, unk6E0, unk6E4, unk6E8, unk6EC;
    int unk6F0, unk6F4, unk6F8, unk6FC, unk700, unk704, unk708, unk70C, unk710, unk714, unk718, unk71C;
    int unk720, unk724, unk728, unk72C, unk730, unk734, unk738, unk73C, unk740, unk744, unk748, unk74C;
    int unk750, unk754, unk758, unk75C, unk760, unk764, unk768, unk76C, unk770, unk774, unk778, unk77C;
    int unk780, unk784, unk788, unk78C, unk790, unk794, unk798, unk79C, unk7A0, unk7A4, unk7A8, unk7AC;
    int unk7B0, unk7B4, unk7B8, unk7BC, unk7C0, unk7C4, unk7C8, unk7CC, unk7D0, unk7D4, unk7D8, unk7DC;
    int unk7E0, unk7E4, unk7E8, unk7EC, unk7F0, unk7F4, unk7F8, unk7FC, unk800, unk804, unk808, unk80C;
    int unk810, unk814, unk818, unk81C, unk820, unk824, unk828, unk82C, unk830, unk834, unk838, unk83C;
    int unk840, unk844, unk848, unk84C, unk850, unk854, unk858, unk85C, unk860, unk864, unk868, unk86C;
    int unk870, unk874, unk878, unk87C, unk880, unk884, unk888, unk88C, unk890, unk894, unk898, unk89C;
    int unk8A0, unk8A4, unk8A8, unk8AC, unk8B0, unk8B4, unk8B8, unk8BC, unk8C0, unk8C4, unk8C8, unk8CC;
    int unk8D0, unk8D4, unk8D8, unk8DC, unk8E0, unk8E4, unk8E8, unk8EC, unk8F0, unk8F4, unk8F8, unk8FC;
    int unk900, unk904, unk908, unk90C, unk910, unk914, unk918, unk91C, unk920, unk924, unk928, unk92C;
    int unk930, unk934, unk938, unk93C, unk940, unk944, unk948, unk94C, unk950, unk954, unk958, unk95C;
    int unk960, unk964, unk968, unk96C, unk970, unk974, unk978, unk97C, unk980, unk984, unk988, unk98C;
    int unk990, unk994, unk998, unk99C, unk9A0, unk9A4, unk9A8, unk9AC, unk9B0, unk9B4, unk9B8, unk9BC;
    int unk9C0, unk9C4, unk9C8, unk9CC, unk9D0, unk9D4, unk9D8, unk9DC, unk9E0, unk9E4, unk9E8, unk9EC;
    int unk9F0, unk9F4, unk9F8, unk9FC, unkA00, unkA04, unkA08, unkA0C, unkA10, unkA14, unkA18, unkA1C;
    int unkA20, unkA24, unkA28, unkA2C, unkA30, unkA34, unkA38, unkA3C, unkA40, unkA44, unkA48, unkA4C;
    int unkA50, unkA54, unkA58, unkA5C, unkA60, unkA64, unkA68, unkA6C, unkA70, unkA74, unkA78, unkA7C;
    int unkA80, unkA84, unkA88, unkA8C, unkA90, unkA94, unkA98, unkA9C, unkAA0, unkAA4, unkAA8, unkAAC;
    int unkAB0, unkAB4, unkAB8, unkABC, unkAC0, unkAC4, unkAC8, unkACC, unkAD0, unkAD4, unkAD8, unkADC;
    int unkAE0, unkAE4, unkAE8, unkAEC, unkAF0, unkAF4, unkAF8, unkAFC, unkB00, unkB04, unkB08, unkB0C;
    int unkB10, unkB14, unkB18, unkB1C, unkB20, unkB24, unkB28, unkB2C, unkB30, unkB34, unkB38, unkB3C;
    int unkB40;
    FUN_00752d40_Item slots[8][7];
    int __thiscall FUN_00752d40(int group, int type);
};
// Counts, over the filled slots of a group, the sum returned by FUN_008d80e0 for slots whose first entry's FUN_004036b0 equals type.
// @fnv 0x00752d40
int __thiscall FUN_00752d40_cls::FUN_00752d40(int group, int type)
{
    int i = 0;
    int count = 0;
    while (i < 7 && slots[group][i].FUN_0044ddc0() > 0)
    {
        if (slots[group][i].FUN_006a7ad0(0)->FUN_004036b0() == type)
            count += slots[group][i].FUN_006a7ad0(0)->FUN_008d80e0();
        i++;
    }
    return count;
}

struct Tile759f90;

struct Base759f90
{
    Base759f90();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
};

struct FUN_00759f90 : public Base759f90, public BSSimpleList<int*>
{
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short unk1c;
    unsigned short unk1e;
    float unk20;
    float unk24;
    float unk28;
    unsigned short unk2c;
    unsigned short unk2e;

    FUN_00759f90();
    virtual ~FUN_00759f90();
    void SetSelectedTile(Tile759f90* tile, bool selected);
};

void __cdecl RegisterMenu759f90(FUN_00759f90* menu);

// @fnv 0x00759f90
FUN_00759f90::FUN_00759f90()
{
    unk14 = 0;
    unk10 = 0;
    unk0c = 0;
    unk18 = 0;
    unk2c = 0;
    unk1c = 0;
    unk28 = 0.0f;
    unk24 = 0.0f;
    unk20 = 0.0f;
    SetSelectedTile(0, true);
    RegisterMenu759f90(this);
}

// Complete Caravan decision reconstruction; inferred layouts, checked against local instructions.
struct CaravanDecision
{
    int total, band, action, lane, row, card, score;
    void FUN_00403550(int);
    void FUN_00984f60(int);
    void FUN_0041fd00(int);
    void FUN_00437730(int);
    void FUN_00600ab0(int);
    int FUN_009611e0();
};
struct CaravanCard
{
    int FUN_008d80e0();
};
typedef int(__cdecl* CaravanCompare)(const void*, const void*);
int __cdecl CompareCalendarDays(const void*, const void*);
void __cdecl FormHeap_Free(void*);
int __cdecl FUN_00ec7d40(int);
struct PointerArray
{
    virtual ~PointerArray();
    void** data;
    unsigned int count, capacity;
    unsigned int FUN_0044ddc0();
    void** FUN_006a7ad0(unsigned int);
    void** FUN_00877a30(unsigned int);
    int FUN_007cb2e0(void**);
    void FUN_00729970(CaravanCompare);
    bool FUN_0076b610();
    void** FUN_006f2270();
    void FUN_00753140();
};
struct FUN_00753110 : PointerArray
{
    FUN_00753110();
    virtual ~FUN_00753110();
};
struct CaravanLane
{
    PointerArray rows[7];
};
struct CaravanTotal
{
    int total;
    int unknown04;
    int unknown08;
};
struct CaravanOwner : Menu
{
    int unknown078;
    int unknown07c;
    int unknown080;
    int unknown084;
    int unknown088;
    int unknown08c;
    int unknown090;
    int unknown094;
    int unknown098;
    int unknown09c;
    int unknown0a0;
    int unknown0a4;
    int unknown0a8;
    int unknown0ac;
    int unknown0b0;
    int unknown0b4;
    int unknown0b8;
    int unknown0bc;
    int unknown0c0;
    int unknown0c4;
    int unknown0c8;
    int unknown0cc;
    int unknown0d0;
    int unknown0d4;
    int unknown0d8;
    int unknown0dc;
    int unknown0e0;
    int unknown0e4;
    int unknown0e8;
    int unknown0ec;
    int unknown0f0;
    int unknown0f4;
    int unknown0f8;
    int unknown0fc;
    int unknown100;
    int unknown104;
    int mode;
    int unknown10c;
    int unknown110;
    int unknown114;
    int unknown118;
    int unknown11c;
    int unknown120;
    int unknown124;
    int unknown128;
    int unknown12c;
    int unknown130;
    int unknown134;
    int unknown138;
    int unknown13c;
    int unknown140;
    int unknown144;
    int unknown148;
    int unknown14c;
    int unknown150;
    int unknown154;
    int unknown158;
    int unknown15c;
    int unknown160;
    int unknown164;
    int unknown168;
    int unknown16c;
    int unknown170;
    int unknown174;
    int unknown178;
    int unknown17c;
    int unknown180;
    int unknown184;
    int unknown188;
    int unknown18c;
    int unknown190;
    int unknown194;
    int unknown198;
    int unknown19c;
    int unknown1a0;
    int unknown1a4;
    int unknown1a8;
    int unknown1ac;
    int unknown1b0;
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
    int unknown20c;
    int unknown210;
    int unknown214;
    int unknown218;
    int unknown21c;
    int unknown220;
    int unknown224;
    int unknown228;
    int unknown22c;
    int unknown230;
    int unknown234;
    int unknown238;
    int unknown23c;
    int unknown240;
    int unknown244;
    int unknown248;
    int unknown24c;
    int unknown250;
    int unknown254;
    int unknown258;
    int unknown25c;
    int unknown260;
    int unknown264;
    int unknown268;
    int unknown26c;
    int unknown270;
    int unknown274;
    int unknown278;
    int unknown27c;
    int unknown280;
    int unknown284;
    int unknown288;
    int unknown28c;
    int unknown290;
    int unknown294;
    int unknown298;
    int unknown29c;
    int unknown2a0;
    int unknown2a4;
    int unknown2a8;
    int unknown2ac;
    int unknown2b0;
    int unknown2b4;
    int unknown2b8;
    int unknown2bc;
    int unknown2c0;
    int unknown2c4;
    int unknown2c8;
    int unknown2cc;
    int unknown2d0;
    int unknown2d4;
    int unknown2d8;
    int unknown2dc;
    int unknown2e0;
    int unknown2e4;
    int unknown2e8;
    int unknown2ec;
    int unknown2f0;
    int unknown2f4;
    int unknown2f8;
    int unknown2fc;
    int unknown300;
    int unknown304;
    int unknown308;
    int unknown30c;
    int unknown310;
    int unknown314;
    int unknown318;
    int unknown31c;
    int unknown320;
    int unknown324;
    int unknown328;
    int unknown32c;
    int unknown330;
    int unknown334;
    int unknown338;
    int unknown33c;
    int unknown340;
    int unknown344;
    int unknown348;
    int unknown34c;
    int unknown350;
    int unknown354;
    int unknown358;
    int unknown35c;
    int unknown360;
    int unknown364;
    int unknown368;
    int unknown36c;
    int unknown370;
    int unknown374;
    int unknown378;
    int unknown37c;
    int unknown380;
    int unknown384;
    int unknown388;
    int unknown38c;
    int unknown390;
    int unknown394;
    int unknown398;
    int unknown39c;
    int unknown3a0;
    int unknown3a4;
    int unknown3a8;
    int unknown3ac;
    int unknown3b0;
    int unknown3b4;
    int unknown3b8;
    int unknown3bc;
    int unknown3c0;
    int unknown3c4;
    int unknown3c8;
    int unknown3cc;
    int unknown3d0;
    int unknown3d4;
    int unknown3d8;
    int unknown3dc;
    int unknown3e0;
    int unknown3e4;
    int unknown3e8;
    int unknown3ec;
    int unknown3f0;
    int unknown3f4;
    int unknown3f8;
    int unknown3fc;
    int unknown400;
    int unknown404;
    int unknown408;
    int unknown40c;
    int unknown410;
    int unknown414;
    int unknown418;
    int unknown41c;
    int unknown420;
    int unknown424;
    int unknown428;
    int unknown42c;
    int unknown430;
    int unknown434;
    int unknown438;
    int unknown43c;
    int unknown440;
    int unknown444;
    int unknown448;
    int unknown44c;
    int unknown450;
    int unknown454;
    int unknown458;
    int unknown45c;
    int unknown460;
    int unknown464;
    int unknown468;
    int unknown46c;
    int unknown470;
    int unknown474;
    int unknown478;
    int unknown47c;
    int unknown480;
    int unknown484;
    int unknown488;
    int unknown48c;
    int unknown490;
    int unknown494;
    int unknown498;
    int unknown49c;
    int unknown4a0;
    int unknown4a4;
    int unknown4a8;
    int unknown4ac;
    int unknown4b0;
    int unknown4b4;
    int unknown4b8;
    int unknown4bc;
    int unknown4c0;
    int unknown4c4;
    int unknown4c8;
    int unknown4cc;
    int unknown4d0;
    int unknown4d4;
    int unknown4d8;
    int unknown4dc;
    int unknown4e0;
    int unknown4e4;
    int unknown4e8;
    int unknown4ec;
    int unknown4f0;
    int unknown4f4;
    int unknown4f8;
    int unknown4fc;
    int unknown500;
    int unknown504;
    int unknown508;
    int unknown50c;
    int unknown510;
    int unknown514;
    int unknown518;
    int unknown51c;
    int unknown520;
    int unknown524;
    int unknown528;
    int unknown52c;
    int unknown530;
    int unknown534;
    int unknown538;
    int unknown53c;
    int unknown540;
    int unknown544;
    int unknown548;
    int unknown54c;
    int unknown550;
    int unknown554;
    int unknown558;
    int unknown55c;
    int unknown560;
    int unknown564;
    int unknown568;
    int unknown56c;
    int unknown570;
    int unknown574;
    int unknown578;
    int unknown57c;
    int unknown580;
    int unknown584;
    int unknown588;
    int unknown58c;
    int unknown590;
    int unknown594;
    int unknown598;
    int unknown59c;
    int unknown5a0;
    int unknown5a4;
    int unknown5a8;
    int unknown5ac;
    int unknown5b0;
    int unknown5b4;
    int unknown5b8;
    int unknown5bc;
    int unknown5c0;
    int unknown5c4;
    int unknown5c8;
    int unknown5cc;
    int unknown5d0;
    int unknown5d4;
    int unknown5d8;
    int unknown5dc;
    int unknown5e0;
    int unknown5e4;
    int unknown5e8;
    int unknown5ec;
    int unknown5f0;
    int unknown5f4;
    int unknown5f8;
    int unknown5fc;
    int unknown600;
    int unknown604;
    int unknown608;
    int unknown60c;
    int unknown610;
    int unknown614;
    int unknown618;
    int unknown61c;
    int unknown620;
    int unknown624;
    int unknown628;
    int unknown62c;
    int unknown630;
    int unknown634;
    int unknown638;
    int unknown63c;
    int unknown640;
    int unknown644;
    int unknown648;
    int unknown64c;
    int unknown650;
    int unknown654;
    int unknown658;
    int unknown65c;
    int unknown660;
    int unknown664;
    int unknown668;
    int unknown66c;
    int unknown670;
    int unknown674;
    int unknown678;
    int unknown67c;
    int unknown680;
    int unknown684;
    int unknown688;
    int unknown68c;
    int unknown690;
    int unknown694;
    int unknown698;
    int unknown69c;
    int unknown6a0;
    int unknown6a4;
    int unknown6a8;
    int unknown6ac;
    int unknown6b0;
    int unknown6b4;
    int unknown6b8;
    int unknown6bc;
    int unknown6c0;
    int unknown6c4;
    int unknown6c8;
    int unknown6cc;
    int unknown6d0;
    int unknown6d4;
    int unknown6d8;
    int unknown6dc;
    int unknown6e0;
    int unknown6e4;
    int unknown6e8;
    int unknown6ec;
    int unknown6f0;
    int unknown6f4;
    int unknown6f8;
    int unknown6fc;
    int unknown700;
    int unknown704;
    int unknown708;
    int unknown70c;
    int unknown710;
    int unknown714;
    int unknown718;
    int unknown71c;
    int unknown720;
    int unknown724;
    int unknown728;
    int unknown72c;
    int unknown730;
    int unknown734;
    int unknown738;
    int unknown73c;
    int unknown740;
    int unknown744;
    int unknown748;
    int unknown74c;
    int unknown750;
    int unknown754;
    int unknown758;
    int unknown75c;
    int unknown760;
    int unknown764;
    int unknown768;
    int unknown76c;
    int unknown770;
    int unknown774;
    int unknown778;
    int unknown77c;
    int unknown780;
    int unknown784;
    int unknown788;
    int unknown78c;
    int unknown790;
    int unknown794;
    int unknown798;
    int unknown79c;
    int unknown7a0;
    int unknown7a4;
    int unknown7a8;
    int unknown7ac;
    int unknown7b0;
    int unknown7b4;
    int unknown7b8;
    int unknown7bc;
    int unknown7c0;
    int unknown7c4;
    int unknown7c8;
    int unknown7cc;
    int unknown7d0;
    int unknown7d4;
    int unknown7d8;
    int unknown7dc;
    int unknown7e0;
    int unknown7e4;
    int unknown7e8;
    int unknown7ec;
    int unknown7f0;
    int unknown7f4;
    int unknown7f8;
    int unknown7fc;
    int unknown800;
    int unknown804;
    int unknown808;
    int unknown80c;
    int unknown810;
    int unknown814;
    int unknown818;
    int unknown81c;
    int unknown820;
    int unknown824;
    int unknown828;
    int unknown82c;
    int unknown830;
    int unknown834;
    int unknown838;
    int unknown83c;
    int unknown840;
    int unknown844;
    int unknown848;
    int unknown84c;
    int unknown850;
    int unknown854;
    int unknown858;
    int unknown85c;
    int unknown860;
    int unknown864;
    int unknown868;
    int unknown86c;
    int unknown870;
    int unknown874;
    int unknown878;
    int unknown87c;
    int unknown880;
    int unknown884;
    int unknown888;
    int unknown88c;
    int unknown890;
    int unknown894;
    int unknown898;
    int unknown89c;
    int unknown8a0;
    int unknown8a4;
    int unknown8a8;
    int unknown8ac;
    int unknown8b0;
    int unknown8b4;
    int unknown8b8;
    int unknown8bc;
    int unknown8c0;
    int unknown8c4;
    int unknown8c8;
    int unknown8cc;
    int unknown8d0;
    int unknown8d4;
    int unknown8d8;
    int unknown8dc;
    int unknown8e0;
    int unknown8e4;
    int unknown8e8;
    int unknown8ec;
    int unknown8f0;
    int unknown8f4;
    int unknown8f8;
    int unknown8fc;
    int unknown900;
    int unknown904;
    int unknown908;
    int unknown90c;
    int unknown910;
    int unknown914;
    int unknown918;
    int unknown91c;
    int unknown920;
    int unknown924;
    int unknown928;
    int unknown92c;
    int unknown930;
    int unknown934;
    int unknown938;
    int unknown93c;
    int unknown940;
    int unknown944;
    int unknown948;
    int unknown94c;
    int unknown950;
    int unknown954;
    int unknown958;
    int unknown95c;
    int unknown960;
    int unknown964;
    int unknown968;
    int unknown96c;
    int unknown970;
    int unknown974;
    int unknown978;
    int unknown97c;
    int unknown980;
    int unknown984;
    int unknown988;
    int unknown98c;
    int unknown990;
    int unknown994;
    int unknown998;
    int unknown99c;
    int unknown9a0;
    int unknown9a4;
    int unknown9a8;
    int unknown9ac;
    int unknown9b0;
    int unknown9b4;
    int unknown9b8;
    int unknown9bc;
    int unknown9c0;
    int unknown9c4;
    int unknown9c8;
    int unknown9cc;
    int unknown9d0;
    int unknown9d4;
    int unknown9d8;
    int unknown9dc;
    int unknown9e0;
    int unknown9e4;
    int unknown9e8;
    int unknown9ec;
    int unknown9f0;
    int unknown9f4;
    int unknown9f8;
    int unknown9fc;
    int unknowna00;
    int unknowna04;
    int unknowna08;
    int unknowna0c;
    int unknowna10;
    int unknowna14;
    int unknowna18;
    int unknowna1c;
    int unknowna20;
    int unknowna24;
    int unknowna28;
    int unknowna2c;
    int unknowna30;
    int unknowna34;
    int unknowna38;
    int unknowna3c;
    int unknowna40;
    int unknowna44;
    int unknowna48;
    int unknowna4c;
    int unknowna50;
    int unknowna54;
    int unknowna58;
    int unknowna5c;
    int unknowna60;
    int unknowna64;
    int unknowna68;
    int unknowna6c;
    int unknowna70;
    int unknowna74;
    int unknowna78;
    int unknowna7c;
    int unknowna80;
    int unknowna84;
    int unknowna88;
    int unknowna8c;
    int unknowna90;
    int unknowna94;
    int unknowna98;
    int unknowna9c;
    int unknownaa0;
    int unknownaa4;
    int unknownaa8;
    int unknownaac;
    int unknownab0;
    int unknownab4;
    int unknownab8;
    int unknownabc;
    int unknownac0;
    int unknownac4;
    int unknownac8;
    int unknownacc;
    int unknownad0;
    int unknownad4;
    int unknownad8;
    int unknownadc;
    int unknownae0;
    int unknownae4;
    int unknownae8;
    int unknownaec;
    int unknownaf0;
    int unknownaf4;
    int unknownaf8;
    int unknownafc;
    int unknownb00;
    int unknownb04;
    int unknownb08;
    int unknownb0c;
    int unknownb10;
    PointerArray opponentHand;
    int unknownb24, unknownb28, unknownb2c, unknownb30;
    PointerArray hand;
    CaravanLane lanes[6];
    int unknownde4, unknownde8;
    CaravanTotal laneTotals[6];
    void UpdateHandStats(int);
    bool FUN_00740f10(unsigned int);
    int CompareToTwentyOneToTwentySix(int);
    int FUN_0074f600(int, int);
    int FUN_00752cb0(int, int);
    int FUN_00752d40(int, int);
    bool CanPlaceCard(int, int, unsigned int, bool);
    CaravanDecision FUN_0074fdc0();
};
typedef char CaravanDecisionSize[(sizeof(CaravanDecision) == 28) ? 1 : -1];
typedef char CaravanArraySize[(sizeof(PointerArray) == 16) ? 1 : -1];
typedef char CaravanChoicesSize[(sizeof(FUN_00753110) == 16) ? 1 : -1];
// @fnv 0x0074fdc0
CaravanDecision CaravanOwner::FUN_0074fdc0()
{
    unsigned int local_188Value2;
    unsigned int local_184Value1;
    int local_180Value40;
    int local_17cValue5;
    unsigned int local_178Value31;
    unsigned int local_174Value5;
    int local_170Value0;
    int local_16cValue10;
    int local_168Value13;
    int local_164Value11;
    unsigned int local_160Value33;
    int local_15cValue23;
    int local_158Value12;
    int local_154Value1;
    int local_150Value42;
    unsigned int local_14cValue41;
    int local_148Value2;
    int local_144Value42;
    int local_140Value41;
    int local_13cValue13;
    unsigned int local_138Value1;
    int local_134Value3;
    int local_130Value0;
    int local_12cValue4;
    int local_128Value10;
    int local_124Value5;
    int local_120Value1;
    int laneAdvantageValue23[3];
    int candidateScoreValue10;
    int removedAdvantageValue23;
    int local_108Value13;
    int local_104Value53;
    int laneLossValue16[6];
    unsigned int local_e8Value5;
    int local_e4Value13;
    int local_e0Value0;
    int local_dcValue4;
    unsigned int local_d8Value0;
    int local_d4Value39;
    int local_d0Value6;
    int local_ccValue0;
    int local_c8Value6;
    unsigned int local_c4Value23;
    int local_c0Value21;
    int local_bcValue3;
    int local_b8Value45;
    int local_b4Value16;
    unsigned int local_b0Value32;
    int local_acValue61;
    int local_a8Value19;
    unsigned int local_a4Value36;
    unsigned int local_a0Value29;
    int local_9cValue4;
    unsigned int local_98Value0;
    int local_94Value52;
    int local_90Value13;
    unsigned int local_8cValue1;
    unsigned int local_88Value23;
    int local_84Value8;
    unsigned int local_80Value12;
    int local_7cValue34;
    int local_78Value0;
    unsigned int local_74Value37;
    unsigned int local_70Value0;
    int local_6cValue34;
    unsigned int local_68Value14;
    CaravanDecision openingValue36;
    int local_48Value18;
    CaravanDecision* local_44Value6;
    CaravanDecision* currentValue29;
    int local_3cValue39;
    int local_38Value22;
    int local_34Value10;
    CaravanDecision selectedValue4;
    FUN_00753110* choicesValue1;

    for (local_48Value18 = 0; local_48Value18 < 6; local_48Value18 = local_48Value18 + 1)
    {
        this->UpdateHandStats(local_48Value18);
    }

    if ((this->FUN_00740f10(0x800)))
    {
        openingValue36.FUN_00403550(4);
        if (mode < 1)
        {
            local_6cValue34 = 0;
            local_70Value0 = 0;
            local_68Value14 = 0;
            local_74Value37 = 0;
            for (; local_74Value37 < (((PointerArray*)((void*)((int)&hand)))->FUN_0044ddc0());
                 local_74Value37 = local_74Value37 + 1)
            {

                if ((((CaravanCard*)(*(((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_74Value37))))
                         ->FUN_008d80e0()) <= 10)
                {
                    local_6cValue34 = local_6cValue34 + 1;
                    local_68Value14 = local_74Value37;
                }
                else
                {
                    local_70Value0 = local_74Value37;
                }
            }

            if ((((PointerArray*)((void*)((int)&hand)))->FUN_0044ddc0()) - local_6cValue34 > 5)
            {
                openingValue36.FUN_00403550(6);
                openingValue36.FUN_00600ab0(local_70Value0);
                return openingValue36;
            }
            {
                openingValue36.FUN_00600ab0(local_68Value14);
                return openingValue36;
            }
        }
        else if (mode < 3)
        {
            local_7cValue34 = 0;
            local_78Value0 = 0;
            local_80Value12 = 0;
            for (; local_80Value12 < (((PointerArray*)((void*)((int)&hand)))->FUN_0044ddc0());
                 local_80Value12 = local_80Value12 + 1)
            {

                if ((((CaravanCard*)(*(((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_80Value12))))
                         ->FUN_008d80e0()) > 5 &&
                    (((CaravanCard*)(*(((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_80Value12))))
                         ->FUN_008d80e0()) <= 10)
                {
                    local_7cValue34 = local_7cValue34 + 1;
                }
                else if ((((CaravanCard*)(*(((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_80Value12))))
                              ->FUN_008d80e0()) < 4)
                {
                    local_78Value0 = local_78Value0 + 1;
                }
            }

            if (5 < ((((PointerArray*)((void*)((int)&hand)))->FUN_0044ddc0()) - local_78Value0) - local_7cValue34)
            {
                local_84Value8 = 0;
                openingValue36.FUN_00403550(6);
                local_88Value23 = 0;
                for (; local_88Value23 < (((PointerArray*)((void*)((int)&hand)))->FUN_0044ddc0());
                     local_88Value23 = local_88Value23 + 1)
                {

                    if (10 < (((CaravanCard*)(*(((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_88Value23))))
                                  ->FUN_008d80e0()))
                    {

                        if ((((CaravanCard*)(*(((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_88Value23))))
                                 ->FUN_008d80e0()) == 0xf)
                        {
                            openingValue36.FUN_00600ab0(local_88Value23);
                            break;
                        }
                        if (local_84Value8 == 0)
                        {
                            openingValue36.FUN_00600ab0(local_88Value23);

                            local_84Value8 =
                                ((CaravanCard*)(*(
                                     ((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_88Value23))))
                                    ->FUN_008d80e0();
                        }
                        else if (local_84Value8 == 0xc)
                        {
                            openingValue36.FUN_00600ab0(local_88Value23);

                            local_84Value8 =
                                ((CaravanCard*)(*(
                                     ((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_88Value23))))
                                    ->FUN_008d80e0();
                        }
                        else if (local_84Value8 == 0xe)
                        {

                            if ((((CaravanCard*)(*(
                                      ((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_88Value23))))
                                     ->FUN_008d80e0()) != 0xc)
                            {
                                openingValue36.FUN_00600ab0(local_88Value23);

                                local_84Value8 =
                                    ((CaravanCard*)(*(
                                         ((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_88Value23))))
                                        ->FUN_008d80e0();
                            }
                        }
                    }
                }
                return openingValue36;
            }
            local_8cValue1 = 0;
            for (; local_8cValue1 < (((PointerArray*)((void*)((int)&hand)))->FUN_0044ddc0());
                 local_8cValue1 = local_8cValue1 + 1)
            {
                if (local_7cValue34 > local_78Value0)
                {

                    if (5 < (((CaravanCard*)(*(((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_8cValue1))))
                                 ->FUN_008d80e0()))
                    {

                        if ((((CaravanCard*)(*(((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_8cValue1))))
                                 ->FUN_008d80e0()) <= 10)
                        {
                            openingValue36.FUN_00600ab0(local_8cValue1);
                            break;
                        }
                    }
                }
                else if (local_78Value0 != 0)
                {

                    if ((((CaravanCard*)(*(((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_8cValue1))))
                             ->FUN_008d80e0()) < 4)
                    {
                        openingValue36.FUN_00600ab0(local_8cValue1);
                        break;
                    }
                }
            }
        }
        else
        {
            local_90Value13 = 0;
            local_98Value0 = 0;
            for (; local_98Value0 < (((PointerArray*)((void*)((int)&hand)))->FUN_0044ddc0());
                 local_98Value0 = local_98Value0 + 1)
            {

                if ((((CaravanCard*)(*(((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_98Value0))))
                         ->FUN_008d80e0()) <= 10)
                {
                    local_90Value13 = local_90Value13 + 1;
                }
            }

            if (5 < (((PointerArray*)((void*)((int)&hand)))->FUN_0044ddc0()) - local_90Value13)
            {
                local_9cValue4 = 0;
                openingValue36.FUN_00403550(6);
                local_a0Value29 = 0;
                for (; local_a0Value29 < (((PointerArray*)((void*)((int)&hand)))->FUN_0044ddc0());
                     local_a0Value29 = local_a0Value29 + 1)
                {

                    if (10 < (((CaravanCard*)(*(((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_a0Value29))))
                                  ->FUN_008d80e0()))
                    {

                        if ((((CaravanCard*)(*(((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_a0Value29))))
                                 ->FUN_008d80e0()) == 0xf)
                        {
                            openingValue36.FUN_00600ab0(local_a0Value29);
                            break;
                        }
                        if (local_9cValue4 == 0)
                        {
                            openingValue36.FUN_00600ab0(local_a0Value29);

                            local_9cValue4 =
                                ((CaravanCard*)(*(
                                     ((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_a0Value29))))
                                    ->FUN_008d80e0();
                        }
                        else if (local_9cValue4 == 0xc)
                        {
                            openingValue36.FUN_00600ab0(local_a0Value29);

                            local_9cValue4 =
                                ((CaravanCard*)(*(
                                     ((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_a0Value29))))
                                    ->FUN_008d80e0();
                        }
                        else if (local_9cValue4 == 0xe)
                        {

                            if ((((CaravanCard*)(*(
                                      ((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_a0Value29))))
                                     ->FUN_008d80e0()) != 0xc)
                            {
                                openingValue36.FUN_00600ab0(local_a0Value29);

                                local_9cValue4 =
                                    ((CaravanCard*)(*(
                                         ((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_a0Value29))))
                                        ->FUN_008d80e0();
                            }
                        }
                    }
                }
                return openingValue36;
            }

            local_94Value52 = FUN_00ec7d40(
                (((CaravanCard*)(*(((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(0))))->FUN_008d80e0()) + -6);
            openingValue36.FUN_00600ab0(0);
            local_a4Value36 = 0;
            for (; local_a4Value36 < (((PointerArray*)((void*)((int)&hand)))->FUN_0044ddc0());
                 local_a4Value36 = local_a4Value36 + 1)
            {

                if ((FUN_00ec7d40(
                        (((CaravanCard*)(*(((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_a4Value36))))
                             ->FUN_008d80e0()) +
                        -6)) < local_94Value52)
                {
                    openingValue36.FUN_00600ab0(local_a4Value36);

                    local_94Value52 = FUN_00ec7d40(
                        (((CaravanCard*)(*(((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_a4Value36))))
                             ->FUN_008d80e0()) +
                        -6);
                }
            }
        }
        return openingValue36;
    }
    {
        choicesValue1 = new FUN_00753110;
        currentValue29 = new CaravanDecision();
        for (local_a8Value19 = 3; local_a8Value19 < 6; local_a8Value19 = local_a8Value19 + 1)
        {
            currentValue29->FUN_0041fd00(local_a8Value19);
            local_acValue61 = laneTotals[local_a8Value19].total;

            if ((this->CompareToTwentyOneToTwentySix(local_acValue61)) < 0)
            {
                local_b0Value32 = 0;
                for (; local_b0Value32 < (((PointerArray*)((void*)((int)&hand)))->FUN_0044ddc0());
                     local_b0Value32 = local_b0Value32 + 1)
                {
                    currentValue29->FUN_00600ab0(local_b0Value32);

                    if ((((CaravanCard*)(*(((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_b0Value32))))
                             ->FUN_008d80e0()) > 10)
                    {

                        if ((((CaravanCard*)(*(((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_b0Value32))))
                                 ->FUN_008d80e0()) == 0xe)
                        {
                            local_b4Value16 = 0;
                            while ((local_b4Value16 < 7 &&
                                    ((((PointerArray*)((void*)((int)&lanes[local_a8Value19].rows[local_b4Value16])))
                                          ->FUN_0044ddc0()) != 0)))
                            {
                                currentValue29->FUN_00437730(local_b4Value16);

                                if ((((PointerArray*)((void*)((int)&lanes[local_a8Value19].rows[local_b4Value16])))
                                         ->FUN_0044ddc0()) > 3)
                                {
                                    local_b4Value16 = local_b4Value16 + 1;
                                    continue;
                                }

                                local_b8Value45 = this->FUN_0074f600(local_a8Value19, local_b4Value16) +
                                                  laneTotals[local_a8Value19].total;

                                if (((this->CompareToTwentyOneToTwentySix(local_b8Value45)) < 1) &&
                                    ((this->CanPlaceCard(local_a8Value19, local_b4Value16, local_b0Value32, true))))
                                {
                                    currentValue29->total = local_b8Value45;

                                    currentValue29->band = (this->CompareToTwentyOneToTwentySix(local_b8Value45));
                                    currentValue29->FUN_00984f60((mode == 2 ? -5 : 1) + local_b8Value45);
                                    currentValue29->FUN_00403550(0);
                                    ((PointerArray*)(choicesValue1))->FUN_007cb2e0((void**)&currentValue29);
                                    currentValue29 = new CaravanDecision();
                                    currentValue29->FUN_00437730(local_b4Value16);
                                    currentValue29->FUN_00600ab0(local_b0Value32);
                                    currentValue29->FUN_0041fd00(local_a8Value19);
                                }
                                local_b4Value16 = local_b4Value16 + 1;
                            }
                        }
                    }
                    else
                    {
                        local_c0Value21 = 0;
                        while ((local_c0Value21 < 7 &&
                                ((((PointerArray*)((void*)((int)&lanes[local_a8Value19].rows[local_c0Value21])))
                                      ->FUN_0044ddc0()) != 0)))
                        {
                            local_c0Value21 = local_c0Value21 + 1;
                        }
                        currentValue29->FUN_00437730(local_c0Value21);
                        if (local_c0Value21 == 7)
                            continue;

                        local_bcValue3 =
                            ((CaravanCard*)(*(((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_b0Value32))))
                                ->FUN_008d80e0() +
                            laneTotals[local_a8Value19].total;

                        if (((this->CompareToTwentyOneToTwentySix(local_bcValue3)) < 1) &&
                            ((this->CanPlaceCard(local_a8Value19, local_c0Value21, local_b0Value32, true))))
                        {
                            currentValue29->total = local_bcValue3;

                            currentValue29->band = (this->CompareToTwentyOneToTwentySix(local_bcValue3));
                            currentValue29->FUN_00984f60(local_bcValue3);
                            currentValue29->FUN_00403550(0);
                            ((PointerArray*)(choicesValue1))->FUN_007cb2e0((void**)&currentValue29);
                            currentValue29 = new CaravanDecision();
                            currentValue29->FUN_00437730(local_c0Value21);
                            currentValue29->FUN_00600ab0(local_b0Value32);
                            currentValue29->FUN_0041fd00(local_a8Value19);
                        }
                    }
                }
            }
            else
            {
                if ((this->CompareToTwentyOneToTwentySix(local_acValue61)) == 0)
                {
                    if ((local_acValue61 < laneTotals[(5 - local_a8Value19)].total) &&
                        (laneTotals[(5 - local_a8Value19)].total < 0x1b))
                    {
                        local_c4Value23 = 0;
                        for (; local_c4Value23 < (((PointerArray*)((void*)((int)&hand)))->FUN_0044ddc0());
                             local_c4Value23 = local_c4Value23 + 1)
                        {
                            currentValue29->FUN_00600ab0(local_c4Value23);

                            local_c8Value6 =
                                ((CaravanCard*)(*(
                                     ((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_c4Value23))))
                                    ->FUN_008d80e0();
                            if (local_c8Value6 > 10)
                            {
                                local_ccValue0 = laneTotals[(5 - local_a8Value19)].total - local_acValue61;
                                if (local_c8Value6 == 0xc)
                                {
                                    for (local_d0Value6 = 0; local_d0Value6 < 7; local_d0Value6 = local_d0Value6 + 1)
                                    {
                                        currentValue29->FUN_00437730(local_d0Value6);
                                        local_d8Value0 =
                                            ((PointerArray*)((
                                                 void*)((int)&lanes[(5 - local_a8Value19)].rows[local_d0Value6])))
                                                ->FUN_0044ddc0();
                                        if (local_d8Value0 == 0)
                                            break;
                                        local_d4Value39 = this->FUN_0074f600(5 - local_a8Value19, local_d0Value6);
                                        if (local_d4Value39 > local_ccValue0)
                                        {
                                            local_dcValue4 =
                                                local_acValue61 -
                                                (laneTotals[(5 - local_a8Value19)].total - local_d4Value39);
                                            if (laneTotals[(5 - local_a8Value19)].total - local_d4Value39 > 21)
                                            {
                                                currentValue29->FUN_00984f60(100 - local_dcValue4);
                                            }
                                            else
                                            {
                                                currentValue29->FUN_00984f60(local_dcValue4 + 0x4b);
                                            }

                                            if ((this->CanPlaceCard(local_a8Value19, local_d0Value6, local_c4Value23,
                                                                    true)))
                                            {
                                                currentValue29->total = local_acValue61;

                                                currentValue29->band =
                                                    (this->CompareToTwentyOneToTwentySix(local_acValue61));
                                                currentValue29->FUN_00403550(7);
                                                ((PointerArray*)(choicesValue1))->FUN_007cb2e0((void**)&currentValue29);
                                                currentValue29 = new CaravanDecision();
                                                currentValue29->FUN_00437730(local_d0Value6);
                                                currentValue29->FUN_00600ab0(local_c4Value23);
                                                currentValue29->FUN_0041fd00(local_a8Value19);
                                            }
                                        }
                                    }
                                }
                                else if ((mode >= 1) && (local_c8Value6 == 0xf))
                                {
                                    for (local_e0Value0 = 0; local_e0Value0 < 7; local_e0Value0 = local_e0Value0 + 1)
                                    {
                                        currentValue29->FUN_00437730(local_e0Value0);
                                        local_e8Value5 =
                                            ((PointerArray*)((
                                                 void*)((int)&lanes[local_a8Value19].rows[local_e0Value0])))
                                                ->FUN_0044ddc0();
                                        if (local_e8Value5 == 0)
                                            break;

                                        if (!((this->CanPlaceCard(local_a8Value19, local_e0Value0, local_c4Value23,
                                                                  true))))
                                            continue;

                                        local_e4Value13 =
                                            ((CaravanCard*)(*(
                                                 ((PointerArray*)((
                                                      void*)((int)&lanes[local_a8Value19].rows[local_e0Value0])))
                                                     ->FUN_006a7ad0(0))))
                                                ->FUN_008d80e0();
                                        if (local_e4Value13 == 1)
                                        {
                                            for (local_104Value53 = 0; local_104Value53 < 6;
                                                 local_104Value53 = local_104Value53 + 1)
                                            {

                                                laneLossValue16[local_104Value53] =
                                                    (this->FUN_00752cb0(local_104Value53, local_e4Value13));
                                            }
                                        }
                                        else
                                        {
                                            for (local_108Value13 = 0; local_108Value13 < 6;
                                                 local_108Value13 = local_108Value13 + 1)
                                            {

                                                laneLossValue16[local_108Value13] = (this->FUN_00752d40(
                                                    local_108Value13,
                                                    (((CaravanCard*)(*(
                                                          ((PointerArray*)((void*)((int)&lanes[local_a8Value19]
                                                                                       .rows[local_e0Value0])))
                                                              ->FUN_006a7ad0(0))))
                                                         ->FUN_008d80e0())));
                                            }
                                        }
                                        laneLossValue16[local_a8Value19] =
                                            laneLossValue16[local_a8Value19] + local_e4Value13;
                                        if (mode < 3)
                                        {
                                            removedAdvantageValue23 = ((laneTotals[local_a8Value19].total -
                                                                        laneLossValue16[local_a8Value19]) -
                                                                       laneTotals[(5 - local_a8Value19)].total) -
                                                                      laneLossValue16[5 - local_a8Value19];
                                            if ((0 < removedAdvantageValue23) &&
                                                ((this->CanPlaceCard(local_a8Value19, local_e0Value0, local_c4Value23,
                                                                     true))))
                                            {
                                                currentValue29->FUN_00984f60(removedAdvantageValue23 + 0x32);
                                                currentValue29->FUN_00403550(3);
                                                ((PointerArray*)(choicesValue1))->FUN_007cb2e0((void**)&currentValue29);
                                                currentValue29 = new CaravanDecision();
                                                currentValue29->FUN_00437730(local_e0Value0);
                                                currentValue29->FUN_00600ab0(local_c4Value23);
                                                currentValue29->FUN_0041fd00(local_a8Value19);
                                            }
                                        }
                                        else
                                        {
                                            for (local_120Value1 = 0; local_120Value1 < 3;
                                                 local_120Value1 = local_120Value1 + 1)
                                            {
                                                laneAdvantageValue23[local_120Value1] =
                                                    ((laneTotals[(local_120Value1 + 3)].total -
                                                      laneLossValue16[local_120Value1 + 3]) -
                                                     laneTotals[local_120Value1].total) -
                                                    laneLossValue16[local_120Value1];
                                            }
                                            candidateScoreValue10 = 0;
                                            if (0 < laneAdvantageValue23[5 - local_a8Value19])
                                            {
                                                candidateScoreValue10 = candidateScoreValue10 + 0x4b;
                                            }
                                            for (local_124Value5 = 0; local_124Value5 < 3;
                                                 local_124Value5 = local_124Value5 + 1)
                                            {
                                                if (((0x14 < laneTotals[(local_124Value5 + 3)].total) &&
                                                     (laneTotals[(local_124Value5 + 3)].total < 0x1b)) &&
                                                    (laneTotals[(local_124Value5 + 3)].total -
                                                         laneLossValue16[local_124Value5 + 3] <
                                                     0x15))
                                                {
                                                    candidateScoreValue10 =
                                                        candidateScoreValue10 -
                                                        (0x19 - (0x15 - (laneTotals[(local_124Value5 + 3)].total -
                                                                         laneLossValue16[local_124Value5 + 3])));
                                                }

                                                if ((this->CompareToTwentyOneToTwentySix(
                                                        laneTotals[(local_124Value5 + 3)].total)) >= 0)
                                                {
                                                    if ((laneTotals[(local_124Value5 + 3)].total < 0x1b) &&
                                                        (laneTotals[(local_124Value5 + 3)].total -
                                                             laneLossValue16[local_124Value5 + 3] <
                                                         0x15))
                                                    {
                                                        candidateScoreValue10 =
                                                            candidateScoreValue10 -
                                                            ((0x15 - laneTotals[(local_124Value5 + 3)].total) -
                                                             laneLossValue16[local_124Value5 + 3]);
                                                    }
                                                    if (((laneTotals[(local_124Value5 + 3)].total < 0x1b) &&
                                                         (laneAdvantageValue23[local_124Value5] < 0)) &&
                                                        ((this->CompareToTwentyOneToTwentySix(
                                                             laneTotals[local_124Value5].total -
                                                             laneLossValue16[local_124Value5])) == 0))
                                                    {
                                                        candidateScoreValue10 =
                                                            candidateScoreValue10 -
                                                            (laneAdvantageValue23[local_124Value5] + 0x19);
                                                    }

                                                    if ((0 < (this->CompareToTwentyOneToTwentySix(
                                                                 laneTotals[(local_124Value5 + 3)].total))) &&
                                                        ((this->CompareToTwentyOneToTwentySix(
                                                             laneTotals[(local_124Value5 + 3)].total -
                                                             laneLossValue16[local_124Value5 + 3])) <= 0))
                                                    {
                                                        candidateScoreValue10 =
                                                            (laneTotals[(local_124Value5 + 3)].total -
                                                             laneLossValue16[local_124Value5 + 3]) +
                                                            candidateScoreValue10;
                                                    }
                                                }

                                                if ((0 < (this->CompareToTwentyOneToTwentySix(
                                                             laneTotals[(local_124Value5 + 3)].total))) &&
                                                    (0 < laneLossValue16[local_124Value5 + 3]))
                                                {
                                                    local_128Value10 = laneTotals[(local_124Value5 + 3)].total -
                                                                       laneLossValue16[local_124Value5 + 3];
                                                    if ((this->CompareToTwentyOneToTwentySix(local_128Value10)) == 0)
                                                    {
                                                        candidateScoreValue10 =
                                                            candidateScoreValue10 + 0x19 + local_128Value10;
                                                    }
                                                    else
                                                    {

                                                        if ((this->CompareToTwentyOneToTwentySix(local_128Value10)) < 0)
                                                        {
                                                            candidateScoreValue10 =
                                                                candidateScoreValue10 + local_128Value10;
                                                        }
                                                        else
                                                        {
                                                            candidateScoreValue10 =
                                                                candidateScoreValue10 +
                                                                laneLossValue16[local_124Value5 + 3];
                                                        }
                                                    }
                                                }

                                                if (((this->CompareToTwentyOneToTwentySix(
                                                         laneTotals[local_124Value5].total)) == 0) &&
                                                    ((this->CompareToTwentyOneToTwentySix(
                                                         laneTotals[local_124Value5].total -
                                                         laneLossValue16[local_124Value5])) < 0))
                                                {
                                                    candidateScoreValue10 = (0x2e - laneTotals[local_124Value5].total) +
                                                                            laneLossValue16[local_124Value5] +
                                                                            candidateScoreValue10;
                                                }
                                                if ((0 < candidateScoreValue10) &&
                                                    ((this->CanPlaceCard(local_a8Value19, local_e0Value0,
                                                                         local_c4Value23, true))))
                                                {
                                                    currentValue29->FUN_00984f60(candidateScoreValue10);
                                                    currentValue29->FUN_00403550(3);
                                                    ((PointerArray*)(choicesValue1))
                                                        ->FUN_007cb2e0((void**)&currentValue29);
                                                    currentValue29 = new CaravanDecision();
                                                    currentValue29->FUN_00437730(local_e0Value0);
                                                    currentValue29->FUN_00600ab0(local_c4Value23);
                                                    currentValue29->FUN_0041fd00(local_a8Value19);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                local_130Value0 = 0;
                                while ((local_130Value0 < 7 &&
                                        ((((PointerArray*)((void*)((int)&lanes[local_a8Value19].rows[local_130Value0])))
                                              ->FUN_0044ddc0()) != 0)))
                                {
                                    local_130Value0 = local_130Value0 + 1;
                                }
                                currentValue29->FUN_00437730(local_130Value0);
                                local_12cValue4 = local_c8Value6 + laneTotals[local_a8Value19].total;
                                if ((local_12cValue4 < 0x1b) &&
                                    (local_12cValue4 > laneTotals[(5 - local_a8Value19)].total))
                                {
                                    local_134Value3 = local_12cValue4 - laneTotals[(5 - local_a8Value19)].total;
                                    currentValue29->FUN_00984f60(100 - local_134Value3);
                                    currentValue29->FUN_00403550(0);
                                }
                                else if ((local_12cValue4 < 0x1b) &&
                                         (local_12cValue4 == laneTotals[(5 - local_a8Value19)].total))
                                {
                                    currentValue29->FUN_00984f60(0x32);
                                    currentValue29->FUN_00403550(0);
                                }
                                else if (local_12cValue4 < 0x1b)
                                {
                                    currentValue29->FUN_00984f60(0x19 - (0x1a - local_12cValue4));
                                    currentValue29->FUN_00403550(0);
                                }

                                if ((this->CanPlaceCard(local_a8Value19, local_130Value0, local_c4Value23, true)))
                                {
                                    currentValue29->total = local_12cValue4;

                                    currentValue29->band = (this->CompareToTwentyOneToTwentySix(local_12cValue4));
                                    ((PointerArray*)(choicesValue1))->FUN_007cb2e0((void**)&currentValue29);
                                    currentValue29 = new CaravanDecision();
                                    currentValue29->FUN_00437730(local_130Value0);
                                    currentValue29->FUN_00600ab0(local_c4Value23);
                                    currentValue29->FUN_0041fd00(local_a8Value19);
                                }
                            }
                        }
                    }
                    else
                    {
                        for (local_138Value1 = 0;
                             local_138Value1 < (((PointerArray*)((void*)((int)&hand)))->FUN_0044ddc0());
                             local_138Value1 = local_138Value1 + 1)
                        {
                            currentValue29->FUN_00600ab0(local_138Value1);

                            local_13cValue13 =
                                ((CaravanCard*)(*(
                                     ((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_138Value1))))
                                    ->FUN_008d80e0();
                            if (local_13cValue13 > 10)
                            {

                                if ((((CaravanCard*)(*(
                                          ((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_138Value1))))
                                         ->FUN_008d80e0()) == 0xe)
                                {
                                    for (local_140Value41 = 0; local_140Value41 < 7;
                                         local_140Value41 = local_140Value41 + 1)
                                    {
                                        currentValue29->FUN_00437730(local_140Value41);
                                        local_144Value42 = this->FUN_0074f600(local_a8Value19, local_140Value41);

                                        if (((this->CompareToTwentyOneToTwentySix(local_acValue61 +
                                                                                  local_144Value42 * 2)) < 1) &&
                                            ((this->CanPlaceCard(local_a8Value19, local_140Value41, local_138Value1,
                                                                 true))))
                                        {
                                            currentValue29->total = local_acValue61 + local_144Value42 * 2;

                                            currentValue29->band = (this->CompareToTwentyOneToTwentySix(
                                                local_acValue61 + local_144Value42 * 2));
                                            currentValue29->FUN_00984f60(local_acValue61 + local_144Value42 * 2);
                                            currentValue29->FUN_00403550(0);
                                            ((PointerArray*)(choicesValue1))->FUN_007cb2e0((void**)&currentValue29);
                                            currentValue29 = new CaravanDecision();
                                            currentValue29->FUN_00437730(local_140Value41);
                                            currentValue29->FUN_00600ab0(local_138Value1);
                                            currentValue29->FUN_0041fd00(local_a8Value19);
                                        }
                                    }
                                }
                            }
                            else
                            {
                                local_148Value2 = 0;
                                while ((local_148Value2 < 7 &&
                                        ((((PointerArray*)((void*)((int)&lanes[local_a8Value19].rows[local_148Value2])))
                                              ->FUN_0044ddc0()) != 0)))
                                {
                                    local_148Value2 = local_148Value2 + 1;
                                }
                                currentValue29->FUN_00437730(local_148Value2);

                                if (!((this->CanPlaceCard(local_a8Value19, local_148Value2, local_138Value1, true))))
                                    continue;
                                if (((this->CompareToTwentyOneToTwentySix(local_13cValue13 +
                                                                          laneTotals[local_a8Value19].total)) < 1))
                                {
                                    currentValue29->total = local_13cValue13 + laneTotals[local_a8Value19].total;

                                    currentValue29->band = (this->CompareToTwentyOneToTwentySix(
                                        local_13cValue13 + laneTotals[local_a8Value19].total));
                                    currentValue29->FUN_00984f60(local_13cValue13 + laneTotals[local_a8Value19].total);
                                    currentValue29->FUN_00403550(0);
                                    ((PointerArray*)(choicesValue1))->FUN_007cb2e0((void**)&currentValue29);
                                    currentValue29 = new CaravanDecision();
                                    currentValue29->FUN_00437730(local_148Value2);
                                    currentValue29->FUN_00600ab0(local_138Value1);
                                    currentValue29->FUN_0041fd00(local_a8Value19);
                                }
                            }
                        }
                    }
                }
                else
                {

                    if (0 < (this->CompareToTwentyOneToTwentySix(local_acValue61)))
                    {
                        for (local_14cValue41 = 0;
                             local_14cValue41 < (((PointerArray*)((void*)((int)&hand)))->FUN_0044ddc0());
                             local_14cValue41 = local_14cValue41 + 1)
                        {
                            currentValue29->FUN_00600ab0(local_14cValue41);

                            local_150Value42 =
                                ((CaravanCard*)(*(
                                     ((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_14cValue41))))
                                    ->FUN_008d80e0();
                            if ((10 < local_150Value42) && (local_150Value42 == 0xc))
                            {
                                for (local_154Value1 = 0; local_154Value1 < 7; local_154Value1 = local_154Value1 + 1)
                                {
                                    currentValue29->FUN_00437730(local_154Value1);
                                    local_158Value12 = this->FUN_0074f600(local_a8Value19, local_154Value1);
                                    if ((local_acValue61 - local_158Value12 < 0x1b) &&
                                        ((this->CanPlaceCard(local_a8Value19, local_154Value1, local_14cValue41,
                                                             true))))
                                    {
                                        currentValue29->total = local_acValue61 - local_158Value12;

                                        currentValue29->band =
                                            (this->CompareToTwentyOneToTwentySix(local_acValue61 - local_158Value12));
                                        currentValue29->FUN_00984f60(100 -
                                                                     ((0x1a - local_acValue61) + local_158Value12));
                                        currentValue29->FUN_00403550(2);
                                        ((PointerArray*)(choicesValue1))->FUN_007cb2e0((void**)&currentValue29);
                                        currentValue29 = new CaravanDecision();
                                        currentValue29->FUN_00437730(local_154Value1);
                                        currentValue29->FUN_00600ab0(local_14cValue41);
                                        currentValue29->FUN_0041fd00(local_a8Value19);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (1)
        {
        }
        for (local_15cValue23 = 0; local_15cValue23 < 3; local_15cValue23++)
        {
            currentValue29->FUN_0041fd00(local_15cValue23);
            for (local_160Value33 = 0; local_160Value33 < (((PointerArray*)((void*)((int)&hand)))->FUN_0044ddc0());
                 local_160Value33++)
            {

                currentValue29->FUN_00600ab0(local_160Value33);
                if (10 < (((CaravanCard*)(*(((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_160Value33))))
                              ->FUN_008d80e0()))
                {

                    local_164Value11 = 0;
                    while ((local_164Value11 < 7 &&
                            ((((PointerArray*)((void*)((int)&lanes[local_15cValue23].rows[local_164Value11])))
                                  ->FUN_0044ddc0()) != 0)))
                    {
                        currentValue29->FUN_00437730(local_164Value11);

                        if ((((PointerArray*)((void*)((int)&lanes[local_15cValue23].rows[local_164Value11])))
                                 ->FUN_0044ddc0()) > 3)
                        {
                            local_164Value11 = local_164Value11 + 1;
                            continue;
                        }

                        switch (
                            ((CaravanCard*)(*(((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_160Value33))))
                                ->FUN_008d80e0())
                        {
                        case 12: {

                            local_168Value13 = laneTotals[local_15cValue23].total -
                                               (this->FUN_0074f600(local_15cValue23, local_164Value11));
                            if ((this->CompareToTwentyOneToTwentySix(laneTotals[local_15cValue23].total)) == 0)
                            {
                                currentValue29->FUN_00984f60((0x1a - local_168Value13) + 0x19);
                                currentValue29->FUN_00403550(7);
                                ((PointerArray*)(choicesValue1))->FUN_007cb2e0((void**)&currentValue29);
                                currentValue29 = new CaravanDecision();
                                currentValue29->FUN_00437730(local_164Value11);
                                currentValue29->FUN_00600ab0(local_160Value33);
                                currentValue29->FUN_0041fd00(local_15cValue23);
                            }
                            else
                            {

                                if ((this->CompareToTwentyOneToTwentySix(laneTotals[local_15cValue23].total)) < 0)
                                {
                                    currentValue29->FUN_00984f60(0x1a - local_168Value13);
                                    currentValue29->FUN_00403550(7);
                                    ((PointerArray*)(choicesValue1))->FUN_007cb2e0((void**)&currentValue29);
                                    currentValue29 = new CaravanDecision();
                                    currentValue29->FUN_00437730(local_164Value11);
                                    currentValue29->FUN_00600ab0(local_160Value33);
                                    currentValue29->FUN_0041fd00(local_15cValue23);
                                }
                            }

                            break;
                        }
                        case 14: {

                            local_16cValue10 = laneTotals[local_15cValue23].total +
                                               (this->FUN_0074f600(local_15cValue23, local_164Value11));
                            if ((this->CompareToTwentyOneToTwentySix(local_16cValue10)) == 1)
                            {
                                currentValue29->FUN_00984f60(local_16cValue10 + -1);
                                currentValue29->FUN_00403550(7);
                                ((PointerArray*)(choicesValue1))->FUN_007cb2e0((void**)&currentValue29);
                                currentValue29 = new CaravanDecision();
                                currentValue29->FUN_00437730(local_164Value11);
                                currentValue29->FUN_00600ab0(local_160Value33);
                                currentValue29->FUN_0041fd00(local_15cValue23);
                            }

                            break;
                        }
                        case 13: {

                            if ((1 < local_164Value11) &&
                                ((((PointerArray*)((void*)((int)&lanes[local_15cValue23].rows[local_164Value11])))
                                      ->FUN_0044ddc0()) == 0))
                            {

                                local_170Value0 =
                                    (((CaravanCard*)(*(((PointerArray*)((void*)((int)&lanes[local_15cValue23]
                                                                                    .rows[(local_164Value11 + -1)])))
                                                           ->FUN_00877a30(0))))
                                         ->FUN_008d80e0()) +
                                    (((CaravanCard*)(*(((PointerArray*)((void*)((int)&lanes[local_15cValue23]
                                                                                    .rows[(local_164Value11 + -2)])))
                                                           ->FUN_00877a30(0))))
                                         ->FUN_008d80e0());
                                if (local_170Value0 < 8)
                                {

                                    if ((((CaravanCard*)(*(
                                              ((PointerArray*)((
                                                   void*)((int)&lanes[local_15cValue23].rows[(local_164Value11 + -1)])))
                                                  ->FUN_00877a30(0))))
                                             ->FUN_008d80e0()) >
                                        (((CaravanCard*)(*(
                                              ((PointerArray*)((
                                                   void*)((int)&lanes[local_15cValue23].rows[(local_164Value11 + -2)])))
                                                  ->FUN_00877a30(0))))
                                             ->FUN_008d80e0()))
                                    {
                                        currentValue29->FUN_00437730(local_164Value11 + -1);
                                        currentValue29->FUN_00984f60(0x23 - local_170Value0);
                                        currentValue29->FUN_00403550(1);
                                        ((PointerArray*)(choicesValue1))->FUN_007cb2e0((void**)&currentValue29);
                                        currentValue29 = new CaravanDecision();
                                        currentValue29->FUN_00437730(local_164Value11);
                                        currentValue29->FUN_00600ab0(local_160Value33);
                                        currentValue29->FUN_0041fd00(local_15cValue23);
                                    }
                                }
                                else if (0x10 < local_170Value0)
                                {

                                    if ((((CaravanCard*)(*(
                                              ((PointerArray*)((
                                                   void*)((int)&lanes[local_15cValue23].rows[(local_164Value11 + -1)])))
                                                  ->FUN_00877a30(0))))
                                             ->FUN_008d80e0()) <
                                        (((CaravanCard*)(*(
                                              ((PointerArray*)((
                                                   void*)((int)&lanes[local_15cValue23].rows[(local_164Value11 + -2)])))
                                                  ->FUN_00877a30(0))))
                                             ->FUN_008d80e0()))
                                    {
                                        currentValue29->FUN_00437730(local_164Value11 + -1);
                                        currentValue29->FUN_00984f60(local_170Value0 + 0x19);
                                        currentValue29->FUN_00403550(1);
                                        ((PointerArray*)(choicesValue1))->FUN_007cb2e0((void**)&currentValue29);
                                        currentValue29 = new CaravanDecision();
                                        currentValue29->FUN_00437730(local_164Value11);
                                        currentValue29->FUN_00600ab0(local_160Value33);
                                        currentValue29->FUN_0041fd00(local_15cValue23);
                                    }
                                }
                            }

                            break;
                        }
                        }

                        local_164Value11 = local_164Value11 + 1;
                    }
                }
            }
        }
        if ((((PointerArray*)(choicesValue1))->FUN_0044ddc0()) == 0)
        {
            local_174Value5 = 0;
            for (local_178Value31 = 0; local_178Value31 < (((PointerArray*)((void*)((int)&hand)))->FUN_0044ddc0());
                 local_178Value31 = local_178Value31 + 1)
            {

                if ((((CaravanCard*)(*(((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_178Value31))))
                         ->FUN_008d80e0()) >
                    (((CaravanCard*)(*(((PointerArray*)((void*)((int)&hand)))->FUN_006a7ad0(local_174Value5))))
                         ->FUN_008d80e0()))
                {
                    local_174Value5 = local_178Value31;
                }
            }
            currentValue29->FUN_00600ab0(local_174Value5);
            currentValue29->FUN_00403550(6);
            currentValue29->FUN_00984f60(local_174Value5);
            ((PointerArray*)(choicesValue1))->FUN_007cb2e0((void**)&currentValue29);
            currentValue29 = new CaravanDecision();
            for (local_17cValue5 = 3; local_17cValue5 < 6; local_17cValue5 = local_17cValue5 + 1)
            {

                if ((this->CompareToTwentyOneToTwentySix(laneTotals[local_17cValue5].total)) != 0)
                {
                    currentValue29->FUN_0041fd00(local_17cValue5);
                    currentValue29->FUN_00403550(5);
                    if (mode < 1)
                    {
                        currentValue29->FUN_00984f60(laneTotals[local_17cValue5].total + -0x1a);
                    }
                    else if (mode < 3)
                    {
                        currentValue29->FUN_00984f60(laneTotals[local_17cValue5].total * 2 + -0x34);
                    }
                    else if (mode >= 3)
                    {
                        local_180Value40 = 0;
                        for (local_184Value1 = 0;
                             local_184Value1 < (((PointerArray*)((void*)((int)&opponentHand)))->FUN_0044ddc0());
                             local_184Value1 = local_184Value1 + 1)
                        {

                            if ((((CaravanCard*)(*(
                                      ((PointerArray*)((void*)((int)&opponentHand)))->FUN_006a7ad0(local_184Value1))))
                                     ->FUN_008d80e0()) == 0xc)
                            {
                                local_180Value40 = local_180Value40 + 1;
                            }
                        }
                        currentValue29->FUN_00984f60((laneTotals[local_17cValue5].total * 2 - 0x34) -
                                                     local_180Value40 * 5);
                    }
                    ((PointerArray*)(choicesValue1))->FUN_007cb2e0((void**)&currentValue29);
                    currentValue29 = new CaravanDecision();
                    currentValue29->FUN_0041fd00(local_17cValue5);
                }
            }
        }
        ((PointerArray*)(choicesValue1))->FUN_00729970(CompareCalendarDays);

        local_3cValue39 = ((CaravanDecision*)(*(((PointerArray*)(choicesValue1))->FUN_006a7ad0(0))))->FUN_009611e0();
        local_38Value22 = 0;
        for (local_188Value2 = 0; local_188Value2 < (((PointerArray*)(choicesValue1))->FUN_0044ddc0());
             local_188Value2 = local_188Value2 + 1)
        {

            if ((((CaravanDecision*)(*(((PointerArray*)(choicesValue1))->FUN_006a7ad0(local_188Value2))))
                     ->FUN_009611e0()) == local_3cValue39)
            {
                local_38Value22 = local_38Value22 + 1;
            }
            else
            {
                break;
            }
        }
        local_34Value10 = local_3cValue39;

        local_44Value6 = (CaravanDecision*)*(((PointerArray*)(choicesValue1))->FUN_006a7ad0(0));
        selectedValue4 = *local_44Value6;
        local_44Value6 = 0;
        while (!(((PointerArray*)(choicesValue1))->FUN_0076b610()))
        {

            currentValue29 = (CaravanDecision*)*(((PointerArray*)(choicesValue1))->FUN_006f2270());
            ((PointerArray*)(choicesValue1))->FUN_00753140();
            delete currentValue29;
        }
        delete choicesValue1;
        currentValue29 = 0;
        choicesValue1 = 0;
        return selectedValue4;
    }
}
