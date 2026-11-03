
// src/fallout/interface/menus/caravanmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/caravanmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_0073bb10_shell
{
    void ClearField();
};

// @fnv 0x0073bb10
void FUN_0073bb10_shell::ClearField()
{
    ((int*)this)[0x39d] = 0;
}

struct FUN_0073bb30_shell
{
    int FUN_0073bb30();
};

// @fnv 0x0073bb30
int FUN_0073bb30_shell::FUN_0073bb30()
{
    return 0x43b;
}

struct Tile
{
    unsigned int uiFlags;
};
struct CaravanMenu
{
    void* m_0x00;
    Tile* m_pTiles[204];
    void SetTile(int id, Tile* tile);
};

// Stores tile into the menu's tile array at index id when id is in [0, 0x33).
// @fnv 0x0073bb40
void CaravanMenu::SetTile(int aiIndex, Tile* tile)
{
    if (aiIndex >= 0 && aiIndex < 0x33)
    {
        *(Tile**)((char*)this + 0x30 + aiIndex * 4) = tile;
    }
}

struct FUN_0073cba0_shell
{
    int __thiscall GetField614();
};

// @fnv 0x0073cba0
int __thiscall FUN_0073cba0_shell::GetField614()
{
    return *(int*)((char*)this + 0x614);
}

struct FUN_0073cbc0_shell
{
    unsigned int __thiscall GetField618();
};

// @fnv 0x0073cbc0
unsigned int __thiscall FUN_0073cbc0_shell::GetField618()
{
    return *(unsigned int*)((char*)this + 0x618);
}

// @fnv 0x0073cbe0
int __cdecl FUN_0073cbe0()
{
    return 0x43b;
}

struct FUN_00740900_shell
{
    unsigned int GetFieldAtOffset61C();
};

// @fnv 0x00740900
unsigned int FUN_00740900_shell::GetFieldAtOffset61C()
{
    return ((unsigned int*)this)[0x61c / 4];
}

struct FUN_00740920_struct
{
    unsigned int __thiscall GetField620();
};

// @fnv 0x00740920
unsigned int __thiscall FUN_00740920_struct::GetField620()
{
    return *(unsigned int*)((char*)this + 0x620);
}

struct FUN_00740e50_class
{
    unsigned int member_62c;
    unsigned int GetMember62C();
};

// @fnv 0x00740e50
unsigned int FUN_00740e50_class::GetMember62C()
{
    return ((unsigned int*)this)[0x18B];
}

struct FUN_00740e90_shell
{
    void FUN_00740e90(int value);
};

// @fnv 0x00740e90
void FUN_00740e90_shell::FUN_00740e90(int value)
{
    *(int*)((char*)this + 0x620) = value;
}

struct FUN_00740eb0_shell
{
    void SetField624(int a);
};

// @fnv 0x00740eb0
void FUN_00740eb0_shell::SetField624(int aiValue)
{
    *(int*)((char*)this + 0x624) = aiValue;
}

struct FUN_00740ed0_shell
{
    void SetField628(int value);
};

// @fnv 0x00740ed0
void FUN_00740ed0_shell::SetField628(int value)
{
    *(int*)((char*)this + 0x628) = value;
}

struct FUN_00740ef0_shell
{
    void __thiscall FUN_00740ef0(int value);
};

// @fnv 0x00740ef0
void __thiscall FUN_00740ef0_shell::FUN_00740ef0(int value)
{
    ((int*)((char*)this + 0x62c))[0] = value;
}

struct FUN_00a253d0_shell
{
    void __thiscall FUN_00a253d0(void);
};
struct FUN_0073bab0_shell
{
    void __thiscall SetFlag(int a, int b);
};
struct OSGlobals
{
    void* __thiscall FUN_00877720(void);
};
extern OSGlobals* g_osGlobals;
extern FUN_0073bab0_shell* DAT_011d917c;
char __cdecl ConsumeByteAtE4(void);

// @fnv 0x0074a270
void __cdecl FUN_0074a270()
{
    if (!ConsumeByteAtE4())
    {
        DAT_011d917c->SetFlag(0x20000, 1);
        reinterpret_cast<FUN_00a253d0_shell*>(g_osGlobals->FUN_00877720())->FUN_00a253d0();
    }
    else
    {
        DAT_011d917c->SetFlag(1, 0);
    }
}

struct FUN_00740e70_shell
{
    void __thiscall FUN_00740e70(int value);
};

// @fnv 0x00740e70
void __thiscall FUN_00740e70_shell::FUN_00740e70(int value)
{
    *(unsigned int*)((char*)this + 0x61c) = value;
}

// @fnv 0x0073bab0
void FUN_0073bab0_shell::SetFlag(int auiMask, int abSet)
{
    *(unsigned char*)&abSet ? *(int*)((char*)this + 0xe74) |= auiMask : *(int*)((char*)this + 0xe74) &= ~auiMask;
}

void __cdecl Deallocate(void* p);
struct FUN_0073bb70_shell
{
    void __thiscall FUN_0073bba0();
    void* __thiscall Destroy(unsigned int flags);
};
// Calls FUN_0073bba0, then frees this via Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0073bb70
void* __thiscall FUN_0073bb70_shell::Destroy(unsigned int flags)
{
    FUN_0073bba0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_007414c0_shell
{
    char __thiscall HasAllTiles();
};
// Checks the 0x33 Tile pointers at offset 0x30 and returns 1 only if none of them is null.
// @fnv 0x007414c0
char __thiscall FUN_007414c0_shell::HasAllTiles()
{
    for (int i = 0; i < 0x33; ++i)
    {
        if (reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0x30)[i] == 0)
            return 0;
    }
    return 1;
}

struct FUN_00740f10_shell
{
    char _pad[0xe74];
    unsigned int m_flags;
    bool FUN_00740f10(unsigned int aFlag);
};

// @fnv 0x00740f10
bool FUN_00740f10_shell::FUN_00740f10(unsigned int aFlag)
{
    return (m_flags & aFlag) != 0;
}

struct Tile_Set_Helper
{
    void Set(int, int);
};
struct FUN_00a01290_shell
{
    void SetTraitAndReset(int, float);
};
struct ActorValueOwner
{
    float GetActorValueFloatByIndex(int);
};
struct CaravanMenu_0074a090
{
    void UpdateControls();
    void FUN_00749a40(int);
    void PlaceBillsAndCoins(int, int);
};
int __cdecl MinInt(int, int);
int __cdecl FUN_00647b70(int, int);
extern int DAT_011d9174;
extern char* _g_thePlayer;

// @fnv 0x0074a090
void __cdecl FUN_0074a090(int aiAmount)
{
    int iDelta = aiAmount - (*(int*)((char*)DAT_011d917c + 0xadc));
    (*(int*)((char*)DAT_011d917c + 0xadc)) = (*(int*)((char*)DAT_011d917c + 0xadc)) + aiAmount;
    (*(FUN_00a01290_shell**)((char*)DAT_011d917c + 0x44))->SetTraitAndReset(DAT_011d9174, 1.0f);
    ((Tile_Set_Helper*)(*(FUN_00a01290_shell**)((char*)DAT_011d917c + 0x44)))
        ->Set(DAT_011d9174, (*(int*)((char*)DAT_011d917c + 0xadc)));
    DAT_011d917c->SetFlag(1, 0);
    int iMax = (int)((*(int*)((char*)DAT_011d917c + 0x110)) * (*(float*)((char*)DAT_011d917c + 0x10c)) +
                     (*(int*)((char*)DAT_011d917c + 0x110)) * (*(float*)((char*)DAT_011d917c + 0x10c)) *
                         (((ActorValueOwner*)(_g_thePlayer + 0xa4))->GetActorValueFloatByIndex(0x20) / 100.0));
    iMax = MinInt(iMax, (*(int*)((char*)DAT_011d917c + 0x110)));
    if ((*(int*)((char*)DAT_011d917c + 0xadc)) > (*(int*)((char*)DAT_011d917c + 0xae0)))
    {
        (*(int*)((char*)DAT_011d917c + 0xae0)) = MinInt(iMax, (*(int*)((char*)DAT_011d917c + 0xadc)));
        (*(FUN_00a01290_shell**)((char*)DAT_011d917c + 0x40))->SetTraitAndReset(DAT_011d9174, 1.0f);
        ((Tile_Set_Helper*)(*(FUN_00a01290_shell**)((char*)DAT_011d917c + 0x40)))
            ->Set(DAT_011d9174, (*(int*)((char*)DAT_011d917c + 0xae0)));
    }
    iDelta +=
        FUN_00647b70(MinInt((*(int*)((char*)DAT_011d917c + 0xadc)), iMax) - (*(int*)((char*)DAT_011d917c + 0xae0)), 0);
    ((CaravanMenu_0074a090*)DAT_011d917c)->UpdateControls();
    ((CaravanMenu_0074a090*)DAT_011d917c)->FUN_00749a40(-1);
    ((CaravanMenu_0074a090*)DAT_011d917c)->PlaceBillsAndCoins(iMax, iDelta);
}

struct TGF
{
    float GetFloat(int);
};
struct InterfaceManager
{
    int FUN_00747d00();
};
extern int DAT_011d9170;
extern InterfaceManager* DAT_011d9180;
struct FUN_007492f0_shell
{
    void InitType15State(int aiType, int aiPad);
};
// @fnv 0x007492f0
void FUN_007492f0_shell::InitType15State(int aiType, int aiPad)
{
    ((char*)this)[0xe85] = 0;
    if (*(int*)((char*)this + 0x28) == 1 && aiType == 15 && *(int*)((char*)this + 0x2c) == 0)
    {
        *(int*)((char*)this + 0xaf8) = (int)((TGF*)*(int*)((char*)this + 0x6c))->GetFloat(DAT_011d9170);
        ((char*)this)[0xe85] = 1;
        *(int*)((char*)this + 0xb00) = DAT_011d9180->FUN_00747d00();
    }
}

struct Interface
{
    static void __cdecl PrintDebugMessage(const char*, ...);
};

struct BSSimpleArray
{
    unsigned int& GetAt(int);
};

struct TESCaravanCard
{
    virtual void f00()
    {}
    virtual void f01()
    {}
    virtual void f02()
    {}
    virtual void f03()
    {}
    virtual void f04()
    {}
    virtual void f05()
    {}
    virtual void f06()
    {}
    virtual void f07()
    {}
    virtual void f08()
    {}
    virtual void f09()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void f17()
    {}
    virtual void f18()
    {}
    virtual void f19()
    {}
    virtual void f20()
    {}
    virtual void f21()
    {}
    virtual void f22()
    {}
    virtual void f23()
    {}
    virtual void f24()
    {}
    virtual void f25()
    {}
    virtual void f26()
    {}
    virtual void f27()
    {}
    virtual void f28()
    {}
    virtual void f29()
    {}
    virtual void f30()
    {}
    virtual void f31()
    {}
    virtual void f32()
    {}
    virtual void f33()
    {}
    virtual void f34()
    {}
    virtual void f35()
    {}
    virtual void f36()
    {}
    virtual void f37()
    {}
    virtual void f38()
    {}
    virtual void f39()
    {}
    virtual void f40()
    {}
    virtual void f41()
    {}
    virtual void f42()
    {}
    virtual void f43()
    {}
    virtual void f44()
    {}
    virtual void f45()
    {}
    virtual void f46()
    {}
    virtual void f47()
    {}
    virtual void f48()
    {}
    virtual void f49()
    {}
    virtual void f50()
    {}
    virtual void f51()
    {}
    virtual void f52()
    {}
    virtual void f53()
    {}
    virtual void f54()
    {}
    virtual void f55()
    {}
    virtual void f56()
    {}
    virtual void f57()
    {}
    virtual void f58()
    {}
    virtual void f59()
    {}
    virtual void f60()
    {}
    virtual void f61()
    {}
    virtual void f62()
    {}
    virtual void f63()
    {}
    virtual void f64()
    {}
    virtual void f65()
    {}
    virtual void f66()
    {}
    virtual void f67()
    {}
    virtual void f68()
    {}
    virtual void f69()
    {}
    virtual void f70()
    {}
    virtual void f71()
    {}
    virtual void f72()
    {}
    virtual void f73()
    {}
    virtual void f74()
    {}
    virtual void f75()
    {}
// @fnv 0x0073b730
    virtual char* FUN_0073b730_card()
    {
        return 0;
    }
};

struct NPCHandArrayInfo
{
    int m_0x00;
    int m_0x04;
    int m_0x08;
    int m_0x0c;
    int m_0x10;
    int m_0x14;
    int m_0x18;

    void __thiscall FUN_0073b730(BSSimpleArray* pNPCHandArray);
};

void __thiscall NPCHandArrayInfo::FUN_0073b730(BSSimpleArray* pNPCHandArray)
{
    if (pNPCHandArray)
    {
        Interface::PrintDebugMessage("track:%i row:%i dcard:%i goal:%i calcresult:%i priority:%i card:%s", m_0x0c,
                                     m_0x10, m_0x14, m_0x00, m_0x04, m_0x18,
                                     ((TESCaravanCard*)pNPCHandArray->GetAt(m_0x14))->FUN_0073b730_card());
    }
    else
    {
        Interface::PrintDebugMessage("track:%i row:%i dcard:%i goal:%i calcresult:%i priority:%i", m_0x0c, m_0x10,
                                     m_0x14, m_0x00, m_0x04, m_0x18);
    }
}

struct AnimIdle;
struct Accum_00733500;
struct S148c0;
struct BSFaceGenNiNode;
struct MiddleLowProcess;
struct Mgr_00733500;
struct NiAdditionalGeometryData;
struct BSShaderRenderUtility;
struct GlobalObject_00633c90;

S148c0* __cdecl FUN_0043c4b0();
unsigned int __cdecl FUN_0045c670();
void __cdecl UpdateCameraFrustum(AnimIdle* animation, float value);
void __cdecl FUN_00b6bee0(AnimIdle* animation, void* data, Accum_00733500* package);

struct S148c0
{
    void FUN_007148c0(int a, int b);
};

struct MiddleLowProcess
{
    int GetProcessInteger();
};

struct BSFaceGenNiNode
{
    void* GetAnimationData();
};

struct AnimIdle
{
};

struct Accum_00733500
{
    void FUN_00c4f270(int value);
    void FUN_004a0fd0(AnimIdle* animation);
    void FUN_00c4f2d0();
};

struct Mgr_00733500
{
    AnimIdle* FUN_007fd640();
};

Mgr_00733500* __cdecl _FUN_004b7210();

struct GO
{
    unsigned int value;

    GO(int value);
    operator unsigned int() const;
    void operator=(void* value);
    ~GO();
};

struct GlobalObject_00633c90 : GO
{
    GlobalObject_00633c90();
};

extern GlobalObject_00633c90 g_011d91a8;
extern float const g_011db5ec_arg1;

struct NiAdditionalGeometryData
{
    static void* __cdecl GetShadowSceneNodeForIndex(int value);
};

struct BSShaderRenderUtility
{
    static void __cdecl SetRenderCamera(AnimIdle* a, AnimIdle* b, bool flag);
};

GO::GO(int value) : value(value)
{}

GO::operator unsigned int() const
{
    return value;
}

void GO::operator=(void* value)
{
    this->value = 0;
}

GO::~GO()
{}

GlobalObject_00633c90::GlobalObject_00633c90() : GO(0)
{}

// @fnv 0x00740f30
void __cdecl FUN_00740f30()
{
    void* pBase;
    Accum_00733500* uiGlobal;
    unsigned int pPackage;
    AnimIdle* pSelected;

    FUN_0043c4b0()->FUN_007148c0(0, 4);

    pBase = (void*)FUN_0045c670();
    uiGlobal = (Accum_00733500*)((MiddleLowProcess*)pBase)->GetProcessInteger();
    uiGlobal->FUN_00c4f270(1);

    pPackage = g_011d91a8.operator unsigned int();
    UpdateCameraFrustum((AnimIdle*)pPackage, g_011db5ec_arg1);

    GO animation((int)_FUN_004b7210()->FUN_007fd640());

    uiGlobal->FUN_004a0fd0((AnimIdle*)animation.operator unsigned int());

    pSelected = pPackage ? (AnimIdle*)pPackage : (AnimIdle*)((BSFaceGenNiNode*)pBase)->GetAnimationData();

    FUN_00b6bee0(pSelected, NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1), uiGlobal);
    BSShaderRenderUtility::SetRenderCamera(pSelected, (AnimIdle*)animation.operator unsigned int(), false);

    uiGlobal->FUN_004a0fd0(0);
    animation.operator=(0);
    uiGlobal->FUN_00c4f2d0();
}

namespace fnv_0074f600 {
struct ArrSI
{
    unsigned int GetFlags(void);
};

struct BSSimpleArray : public ArrSI
{
    unsigned int& GetAt(int index);
};

struct MiddleLowProcess
{
    int GetProcessInteger(void);
};

struct FUN_0074f600_shell
{
    int __thiscall FUN_0074f600(int index1, int index2);
};

// @fnv 0x0074f600
int __thiscall FUN_0074f600_shell::FUN_0074f600(int index1, int index2)
{
    int evaluateHour = 0;
    int flags;
    int i;

    flags =
        reinterpret_cast<BSSimpleArray*>(reinterpret_cast<unsigned char*>(this) + 0xB44 + index1 * 0x70 + index2 * 0x10)
            ->GetFlags();

    if (flags > 0)
    {
        evaluateHour = reinterpret_cast<MiddleLowProcess*>(
                           reinterpret_cast<BSSimpleArray*>(reinterpret_cast<unsigned char*>(this) + 0xB44 +
                                                            index1 * 0x70 + index2 * 0x10)
                               ->GetAt(0))
                           ->GetProcessInteger();

        for (i = 1; i < flags; ++i)
        {
            if (reinterpret_cast<MiddleLowProcess*>(
                    reinterpret_cast<BSSimpleArray*>(reinterpret_cast<unsigned char*>(this) + 0xB44 + index1 * 0x70 +
                                                     index2 * 0x10)
                        ->GetAt(i))
                    ->GetProcessInteger() == 14)
            {
                evaluateHour *= 2;
            }
        }
    }

    return evaluateHour;
}
}  // namespace fnv_0074f600

struct BSSimpleListTESRaceSize
{
    int __thiscall GetSize();
    TESCaravanCard** __thiscall _ref_006815c0();
    BSSimpleListTESRaceSize* __thiscall _ref_00726070();
};

struct BSSimpleArrayActor
{
    unsigned int __thiscall Add(void*& value);
};

struct FUN_006e2b50_shell
{
    void __thiscall SetCantOpenDoors(bool value);
};

struct FUN_00729970_shell
{
    void __thiscall FUN_00729970(void(__cdecl* callback)(void));
};

void __cdecl FUN_0059ae10();

struct FUN_0073ced0_shell
{
    bool RebuildCardLists();
};

// @fnv 0x0073ced0
bool FUN_0073ced0_shell::RebuildCardLists()
{
    int i;
    BSSimpleListTESRaceSize* activelist;
    BSSimpleListTESRaceSize* inactivelist;
    TESCaravanCard* pCard;

    inactivelist =
        reinterpret_cast<BSSimpleListTESRaceSize*>(reinterpret_cast<FUN_0073cba0_shell*>(_g_thePlayer)->GetField614());
    activelist =
        reinterpret_cast<BSSimpleListTESRaceSize*>(reinterpret_cast<FUN_0073cbc0_shell*>(_g_thePlayer)->GetField618());

    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0xaec) = activelist->GetSize();
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0xaf0) =
        inactivelist->GetSize() + activelist->GetSize();

    i = 0;

    while (inactivelist && *inactivelist->_ref_006815c0())
    {
        pCard = *inactivelist->_ref_006815c0();
        reinterpret_cast<FUN_006e2b50_shell*>(pCard)->SetCantOpenDoors(false);
        reinterpret_cast<BSSimpleArrayActor*>(reinterpret_cast<char*>(this) + 0xa6c)
            ->Add(reinterpret_cast<void*&>(pCard));
        inactivelist = inactivelist->_ref_00726070();
    }

    {
        TESCaravanCard* pCard;

        while (activelist && *activelist->_ref_006815c0())
        {
            pCard = *activelist->_ref_006815c0();
            reinterpret_cast<FUN_006e2b50_shell*>(pCard)->SetCantOpenDoors(true);
            reinterpret_cast<BSSimpleArrayActor*>(reinterpret_cast<char*>(this) + 0xa6c)
                ->Add(reinterpret_cast<void*&>(pCard));
            activelist = activelist->_ref_00726070();
        }
    }

    reinterpret_cast<FUN_00729970_shell*>(reinterpret_cast<char*>(this) + 0xa6c)->FUN_00729970(FUN_0059ae10);

    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xaf4) =
        (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0xaf0) / 10 > 10)
            ? (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0xaf0) / 10)
            : 10;

    return true;
}

struct Card
{
    bool FUN_0073cb80();
};
struct CardArray
{
    void FUN_00470470();
    unsigned int FUN_0044ddc0();
    Card*& FUN_006a7ad0(unsigned int index);
    void FUN_005ae3d0(Card* const& card);
};
struct Menu
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
    unsigned int state;
    unsigned int selection;
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
    unsigned int unk410;
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
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
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
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66c;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67c;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68c;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69c;
    unsigned int unk6a0;
    unsigned int unk6a4;
    unsigned int unk6a8;
    unsigned int unk6ac;
    unsigned int unk6b0;
    unsigned int unk6b4;
    unsigned int unk6b8;
    unsigned int unk6bc;
    unsigned int unk6c0;
    unsigned int unk6c4;
    unsigned int unk6c8;
    unsigned int unk6cc;
    unsigned int unk6d0;
    unsigned int unk6d4;
    unsigned int unk6d8;
    unsigned int unk6dc;
    unsigned int unk6e0;
    unsigned int unk6e4;
    unsigned int unk6e8;
    unsigned int unk6ec;
    unsigned int unk6f0;
    unsigned int unk6f4;
    unsigned int unk6f8;
    unsigned int unk6fc;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70c;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71c;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72c;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73c;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74c;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75c;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76c;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77c;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78c;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79c;
    unsigned int unk7a0;
    unsigned int unk7a4;
    unsigned int unk7a8;
    unsigned int unk7ac;
    unsigned int unk7b0;
    unsigned int unk7b4;
    unsigned int unk7b8;
    unsigned int unk7bc;
    unsigned int unk7c0;
    unsigned int unk7c4;
    unsigned int unk7c8;
    unsigned int unk7cc;
    unsigned int unk7d0;
    unsigned int unk7d4;
    unsigned int unk7d8;
    unsigned int unk7dc;
    unsigned int unk7e0;
    unsigned int unk7e4;
    unsigned int unk7e8;
    unsigned int unk7ec;
    unsigned int unk7f0;
    unsigned int unk7f4;
    unsigned int unk7f8;
    unsigned int unk7fc;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80c;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81c;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82c;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83c;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84c;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85c;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86c;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87c;
    unsigned int unk880;
    unsigned int unk884;
    unsigned int unk888;
    unsigned int unk88c;
    unsigned int unk890;
    unsigned int unk894;
    unsigned int unk898;
    unsigned int unk89c;
    unsigned int unk8a0;
    unsigned int unk8a4;
    unsigned int unk8a8;
    unsigned int unk8ac;
    unsigned int unk8b0;
    unsigned int unk8b4;
    unsigned int unk8b8;
    unsigned int unk8bc;
    unsigned int unk8c0;
    unsigned int unk8c4;
    unsigned int unk8c8;
    unsigned int unk8cc;
    unsigned int unk8d0;
    unsigned int unk8d4;
    unsigned int unk8d8;
    unsigned int unk8dc;
    unsigned int unk8e0;
    unsigned int unk8e4;
    unsigned int unk8e8;
    unsigned int unk8ec;
    unsigned int unk8f0;
    unsigned int unk8f4;
    unsigned int unk8f8;
    unsigned int unk8fc;
    unsigned int unk900;
    unsigned int unk904;
    unsigned int unk908;
    unsigned int unk90c;
    unsigned int unk910;
    unsigned int unk914;
    unsigned int unk918;
    unsigned int unk91c;
    unsigned int unk920;
    unsigned int unk924;
    unsigned int unk928;
    unsigned int unk92c;
    unsigned int unk930;
    unsigned int unk934;
    unsigned int unk938;
    unsigned int unk93c;
    unsigned int unk940;
    unsigned int unk944;
    unsigned int unk948;
    unsigned int unk94c;
    unsigned int unk950;
    unsigned int unk954;
    unsigned int unk958;
    unsigned int unk95c;
    unsigned int unk960;
    unsigned int unk964;
    unsigned int unk968;
    unsigned int unk96c;
    unsigned int unk970;
    unsigned int unk974;
    unsigned int unk978;
    unsigned int unk97c;
    unsigned int unk980;
    unsigned int unk984;
    unsigned int unk988;
    unsigned int unk98c;
    unsigned int unk990;
    unsigned int unk994;
    unsigned int unk998;
    unsigned int unk99c;
    unsigned int unk9a0;
    unsigned int unk9a4;
    unsigned int unk9a8;
    unsigned int unk9ac;
    unsigned int unk9b0;
    unsigned int unk9b4;
    unsigned int unk9b8;
    unsigned int unk9bc;
    unsigned int unk9c0;
    unsigned int unk9c4;
    unsigned int unk9c8;
    unsigned int unk9cc;
    unsigned int unk9d0;
    unsigned int unk9d4;
    unsigned int unk9d8;
    unsigned int unk9dc;
    unsigned int unk9e0;
    unsigned int unk9e4;
    unsigned int unk9e8;
    unsigned int unk9ec;
    unsigned int unk9f0;
    unsigned int unk9f4;
    unsigned int unk9f8;
    unsigned int unk9fc;
    unsigned int unka00;
    unsigned int unka04;
    unsigned int unka08;
    unsigned int unka0c;
    unsigned int unka10;
    unsigned int unka14;
    unsigned int unka18;
    unsigned int unka1c;
    unsigned int unka20;
    unsigned int unka24;
    unsigned int unka28;
    unsigned int unka2c;
    unsigned int unka30;
    unsigned int unka34;
    unsigned int unka38;
    unsigned int unka3c;
    unsigned int unka40;
    unsigned int unka44;
    unsigned int unka48;
    unsigned int unka4c;
    unsigned int unka50;
    unsigned int unka54;
    unsigned int unka58;
    unsigned int unka5c;
    unsigned int unka60;
    unsigned int unka64;
    unsigned int unka68;
    CardArray cards;
};
struct Manager
{
    CardArray* GetField618();
    CardArray* GetField614();
};
extern Manager* DAT_011dea3c;
int FUN_0073cbe0();
void* FUN_00a09030(int value);
// If the menu exists, sets its selection to 23 and, when state is 1, splits its cards into two arrays by FUN_0073cb80's result.
// @fnv 0x0073ca50
void __cdecl UpdateCardSelection()
{
    if (DAT_011d917c)
    {
        ((Menu*)DAT_011d917c)->selection = 23;
        void* owner = FUN_00a09030(FUN_0073cbe0());
        if (!owner)
            return;
        switch (((Menu*)DAT_011d917c)->state)
        {
        default:
            return;
            break;
        case 1:
            CardArray* second = DAT_011dea3c->GetField618();
            CardArray* first = DAT_011dea3c->GetField614();
            second->FUN_00470470();
            first->FUN_00470470();
            for (unsigned int index = 0; index < ((Menu*)DAT_011d917c)->cards.FUN_0044ddc0(); ++index)
            {
                if (((Menu*)DAT_011d917c)->cards.FUN_006a7ad0(index)->FUN_0073cb80())
                    second->FUN_005ae3d0(((Menu*)DAT_011d917c)->cards.FUN_006a7ad0(index));
                else
                    first->FUN_005ae3d0(((Menu*)DAT_011d917c)->cards.FUN_006a7ad0(index));
            }
            second = 0;
            first = 0;
            break;
        }
    }
}

struct FNV_74A000_Item;

struct FNV_74A000_Action
{
    void __thiscall FUN_00a012d0();
};

struct FNV_74A000_List
{
    FNV_74A000_Item* __thiscall FUN_00559450();
    int* __thiscall FUN_0073ac90();
    FNV_74A000_Action** __thiscall AddEight(FNV_74A000_Item* item, int type, float amount, int flag);
    FNV_74A000_Item* __thiscall DereferenceIfNotNull(FNV_74A000_Item* item);
};

struct FNV_74A000_Slot
{
    int unk00;
    FNV_74A000_List list;
};

struct FNV_74A000_Root
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
    FNV_74A000_Slot* slots[1];
};

struct FNV_74A000_This
{
    void __thiscall FUN_0074a000(int slot, float amount);
};

// @fnv 0x0074a000
void FNV_74A000_This::FUN_0074a000(int slot, float amount)
{
    FNV_74A000_Item* item = reinterpret_cast<FNV_74A000_Root*>(DAT_011d917c)->slots[slot]->list.FUN_00559450();
    FNV_74A000_List* list = &reinterpret_cast<FNV_74A000_Root*>(DAT_011d917c)->slots[slot]->list;

    while (item && list && *list->FUN_0073ac90())
    {
        (*list->AddEight(item, 0xfa9, amount, 1))->FUN_00a012d0();
        item = list->DereferenceIfNotNull(item);
    }
}

struct UIWidget
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
    virtual void SetResource(int, int, unsigned int);
};

struct UIAssetName
{
    const char* FUN_00408da0();
};
struct UIAssetSource
{
    bool FUN_0073cb80();
    UIAssetName* FUN_0050d100();
    UIAssetName* FUN_00503650();
};
struct UIAssetChain
{
    UIAssetSource** FUN_006a7ad0(int);
};
struct UIMenuManager
{
    void FUN_004568c0(char*, GO*, int, int);
};
struct UIOptions
{
    void FUN_00a011b0(int);
};
extern "C" UIMenuManager* DAT_011dea10;
extern char UNK_0101996c, UNK_0101d7fc;
extern "C" int __cdecl FUN_00ec62c0();
extern "C" void __cdecl FUN_00406d00(char*, unsigned int, const char*, const char*, const char*);
extern "C" void __cdecl FUN_004b7240(char*, char*, unsigned int);
struct HudGlyphMenu
{
    void UpdateIconResources(int iconIndex);
};
// @fnv 0x0074af70
void HudGlyphMenu::UpdateIconResources(int iconIndex)
{
    if (*(void**)((char*)this + 0x91c) && *(void**)((char*)this + 0x97c) && *(void**)((char*)this + 0x9dc) &&
        *(void**)((char*)this + 0xa3c))
    {
        (*(UIOptions**)((char*)this + 0x6c))->FUN_00a011b0(DAT_011d9170);
        int imageKey = FUN_00ec62c0();
        char generatedPath[260];
        char resolvedPath[260];
        if ((*((UIAssetChain*)((char*)this + 0xa6c))->FUN_006a7ad0(imageKey))->FUN_0073cb80())
        {
            GO currentIcon(0);

            FUN_00406d00(
                generatedPath, 260, &UNK_0101996c, &UNK_0101d7fc,
                (*((UIAssetChain*)((char*)this + 0xa6c))->FUN_006a7ad0(imageKey))->FUN_0050d100()->FUN_00408da0());
            FUN_004b7240(generatedPath, resolvedPath, 260);
            DAT_011dea10->FUN_004568c0(resolvedPath, &currentIcon, 0, 0);
            if ((unsigned int)currentIcon != 0)
            {
                ((UIWidget*)*(void**)((char*)this + iconIndex * 4 + 0x8ec))
                    ->SetResource(0, 0, (unsigned int)currentIcon);
            }

            FUN_00406d00(
                generatedPath, 260, &UNK_0101996c, &UNK_0101d7fc,
                (*((UIAssetChain*)((char*)this + 0xa6c))->FUN_006a7ad0(imageKey))->FUN_00503650()->FUN_00408da0());
            FUN_004b7240(generatedPath, resolvedPath, 260);
            DAT_011dea10->FUN_004568c0(resolvedPath, &currentIcon, 0, 0);
            if ((unsigned int)currentIcon != 0)
            {
                ((UIWidget*)*(void**)((char*)this + iconIndex * 4 + 0x94c))
                    ->SetResource(0, 0, (unsigned int)currentIcon);
            }

            FUN_00406d00(
                generatedPath, 260, &UNK_0101996c, &UNK_0101d7fc,
                (*((UIAssetChain*)((char*)this + 0xa6c))->FUN_006a7ad0(imageKey))->FUN_00503650()->FUN_00408da0());
            FUN_004b7240(generatedPath, resolvedPath, 260);
            DAT_011dea10->FUN_004568c0(resolvedPath, &currentIcon, 0, 0);
            if ((unsigned int)currentIcon != 0)
            {
                ((UIWidget*)*(void**)((char*)this + iconIndex * 4 + 0x9ac))
                    ->SetResource(0, 0, (unsigned int)currentIcon);
            }

            FUN_00406d00(
                generatedPath, 260, &UNK_0101996c, &UNK_0101d7fc,
                (*((UIAssetChain*)((char*)this + 0xa6c))->FUN_006a7ad0(imageKey))->FUN_0050d100()->FUN_00408da0());
            FUN_004b7240(generatedPath, resolvedPath, 260);
            DAT_011dea10->FUN_004568c0(resolvedPath, &currentIcon, 0, 0);
            if ((unsigned int)currentIcon != 0)
            {
                ((UIWidget*)*(void**)((char*)this + iconIndex * 4 + 0xa0c))
                    ->SetResource(0, 0, (unsigned int)currentIcon);
            }
        }
        else if ((*((UIAssetChain*)((char*)this + 0xa6c))->FUN_006a7ad0(imageKey))->FUN_0050d100())
        {
            GO alternativeIcon(0);

            FUN_00406d00(
                generatedPath, 260, &UNK_0101996c, &UNK_0101d7fc,
                (*((UIAssetChain*)((char*)this + 0xa6c))->FUN_006a7ad0(imageKey))->FUN_0050d100()->FUN_00408da0());
            FUN_004b7240(generatedPath, resolvedPath, 260);
            DAT_011dea10->FUN_004568c0(resolvedPath, &alternativeIcon, 0, 0);
            if ((unsigned int)alternativeIcon != 0)
            {
                ((UIWidget*)*(void**)((char*)this + iconIndex * 4 + 0x9ac))
                    ->SetResource(0, 0, (unsigned int)alternativeIcon);
            }

            FUN_00406d00(
                generatedPath, 260, &UNK_0101996c, &UNK_0101d7fc,
                (*((UIAssetChain*)((char*)this + 0xa6c))->FUN_006a7ad0(imageKey))->FUN_00503650()->FUN_00408da0());
            FUN_004b7240(generatedPath, resolvedPath, 260);
            DAT_011dea10->FUN_004568c0(resolvedPath, &alternativeIcon, 0, 0);
            if ((unsigned int)alternativeIcon != 0)
            {
                ((UIWidget*)*(void**)((char*)this + iconIndex * 4 + 0xa0c))
                    ->SetResource(0, 0, (unsigned int)alternativeIcon);
            }

            FUN_00406d00(
                generatedPath, 260, &UNK_0101996c, &UNK_0101d7fc,
                (*((UIAssetChain*)((char*)this + 0xa6c))->FUN_006a7ad0(imageKey))->FUN_00503650()->FUN_00408da0());
            FUN_004b7240(generatedPath, resolvedPath, 260);
            DAT_011dea10->FUN_004568c0(resolvedPath, &alternativeIcon, 0, 0);
            if ((unsigned int)alternativeIcon != 0)
            {
                ((UIWidget*)*(void**)((char*)this + iconIndex * 4 + 0x8ec))
                    ->SetResource(0, 0, (unsigned int)alternativeIcon);
            }

            FUN_00406d00(
                generatedPath, 260, &UNK_0101996c, &UNK_0101d7fc,
                (*((UIAssetChain*)((char*)this + 0xa6c))->FUN_006a7ad0(imageKey))->FUN_0050d100()->FUN_00408da0());
            FUN_004b7240(generatedPath, resolvedPath, 260);
            DAT_011dea10->FUN_004568c0(resolvedPath, &alternativeIcon, 0, 0);
            if ((unsigned int)alternativeIcon != 0)
            {
                ((UIWidget*)*(void**)((char*)this + iconIndex * 4 + 0x94c))
                    ->SetResource(0, 0, (unsigned int)alternativeIcon);
            }
        }
    }
}

extern float DAT_01017718;

struct FUN_004bc1f0_shell
{
    void __thiscall FUN_004bc1f0(float a, float b, float c);
};

struct FUN_0043d410_shell
{
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int __thiscall FUN_0043d410(float a, int b, int c);
};

struct FUN_00a59c60_shell
{
    void __thiscall FUN_00a59c60(unsigned int v);
};

struct Entry_0074ecb0
{
    unsigned int m_slots[7];
};

struct FUN_0074ecb0_cls
{
    char unk000[0x198];
    Entry_0074ecb0 m_entries[8];

    void FUN_0074ecb0(int a1);
};

// For each of the 7 slots in entry a1, calls FUN_004bc1f0 with zeroed values and DAT_01017718, then FUN_00a59c60 with the result of FUN_0043d410.
// @fnv 0x0074ecb0
void FUN_0074ecb0_cls::FUN_0074ecb0(int aiEntryIndex)
{
    for (int i = 0; i < 7; i++)
    {
        ((FUN_004bc1f0_shell*)m_entries[aiEntryIndex].m_slots[i])->FUN_004bc1f0(0.0f, 0.0f, DAT_01017718);
        FUN_0043d410_shell tmp;
        ((FUN_00a59c60_shell*)m_entries[aiEntryIndex].m_slots[i])->FUN_00a59c60(tmp.FUN_0043d410(0.0f, 0, 0));
    }
}

struct FUN_004bc1f0_S
{
    void __thiscall FUN_004bc1f0(float x, float y, float z);
};

struct NiUpdateData
{
    float time;
    bool a;
    bool b;
    bool c;
    bool d;
    bool e;
    NiUpdateData(float time, bool a, bool b);
};

NiUpdateData::NiUpdateData(float t, bool x, bool y)
{
    this->time = t;
    this->a = x;
    this->b = y;
    this->c = false;
    this->d = false;
    this->e = false;
}

struct NiAVObject : public FUN_004bc1f0_S
{
    void __thiscall Update(const NiUpdateData& data);
};

struct S_0074ed40_Cls
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
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    NiAVObject* m_rows[16][7];
    void __thiscall FUN_0074ed40(int index);
};

// For each of the 7 objects in m_rows[index], calls FUN_004bc1f0 with zero coordinates and Update with a zero-time NiUpdateData.
// @fnv 0x0074ed40
void __thiscall S_0074ed40_Cls::FUN_0074ed40(int aiRowIndex)
{
    for (int i = 0; i < 7; i++)
    {
        this->m_rows[aiRowIndex][i]->FUN_004bc1f0(0.0f, 0.0f, 0.0f);
        this->m_rows[aiRowIndex][i]->Update(NiUpdateData(0.0f, false, false));
    }
}

struct Vec3Temp
{
    float x;
    float y;
    float z;
    Vec3Temp* FUN_0043d410(float, int, int);
};
struct CaravanObj
{
    void FUN_004bc1f0(float, float, float);
    void FUN_00a59c60(Vec3Temp*);
};
struct FUN_0074edd0_cls
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int unk02B4;
    unsigned int unk02B8;
    unsigned int unk02BC;
    unsigned int unk02C0;
    unsigned int unk02C4;
    unsigned int unk02C8;
    unsigned int unk02CC;
    unsigned int unk02D0;
    unsigned int unk02D4;
    unsigned int unk02D8;
    unsigned int unk02DC;
    unsigned int unk02E0;
    unsigned int unk02E4;
    unsigned int unk02E8;
    unsigned int unk02EC;
    unsigned int unk02F0;
    unsigned int unk02F4;
    unsigned int unk02F8;
    unsigned int unk02FC;
    unsigned int unk0300;
    unsigned int unk0304;
    unsigned int unk0308;
    unsigned int unk030C;
    unsigned int unk0310;
    unsigned int unk0314;
    unsigned int unk0318;
    unsigned int unk031C;
    unsigned int unk0320;
    unsigned int unk0324;
    unsigned int unk0328;
    unsigned int unk032C;
    unsigned int unk0330;
    unsigned int unk0334;
    unsigned int unk0338;
    unsigned int unk033C;
    unsigned int unk0340;
    unsigned int unk0344;
    unsigned int unk0348;
    unsigned int unk034C;
    unsigned int unk0350;
    unsigned int unk0354;
    unsigned int unk0358;
    unsigned int unk035C;
    unsigned int unk0360;
    unsigned int unk0364;
    unsigned int unk0368;
    unsigned int unk036C;
    unsigned int unk0370;
    unsigned int unk0374;
    unsigned int unk0378;
    unsigned int unk037C;
    unsigned int unk0380;
    unsigned int unk0384;
    unsigned int unk0388;
    unsigned int unk038C;
    unsigned int unk0390;
    unsigned int unk0394;
    unsigned int unk0398;
    unsigned int unk039C;
    unsigned int unk03A0;
    unsigned int unk03A4;
    unsigned int unk03A8;
    unsigned int unk03AC;
    unsigned int unk03B0;
    unsigned int unk03B4;
    unsigned int unk03B8;
    unsigned int unk03BC;
    unsigned int unk03C0;
    unsigned int unk03C4;
    unsigned int unk03C8;
    unsigned int unk03CC;
    unsigned int unk03D0;
    unsigned int unk03D4;
    unsigned int unk03D8;
    unsigned int unk03DC;
    unsigned int unk03E0;
    unsigned int unk03E4;
    unsigned int unk03E8;
    unsigned int unk03EC;
    unsigned int unk03F0;
    unsigned int unk03F4;
    unsigned int unk03F8;
    unsigned int unk03FC;
    unsigned int unk0400;
    unsigned int unk0404;
    unsigned int unk0408;
    unsigned int unk040C;
    unsigned int unk0410;
    unsigned int unk0414;
    unsigned int unk0418;
    unsigned int unk041C;
    unsigned int unk0420;
    unsigned int unk0424;
    unsigned int unk0428;
    unsigned int unk042C;
    unsigned int unk0430;
    unsigned int unk0434;
    unsigned int unk0438;
    unsigned int unk043C;
    unsigned int unk0440;
    unsigned int unk0444;
    unsigned int unk0448;
    unsigned int unk044C;
    unsigned int unk0450;
    unsigned int unk0454;
    unsigned int unk0458;
    unsigned int unk045C;
    unsigned int unk0460;
    unsigned int unk0464;
    unsigned int unk0468;
    unsigned int unk046C;
    unsigned int unk0470;
    unsigned int unk0474;
    unsigned int unk0478;
    unsigned int unk047C;
    unsigned int unk0480;
    unsigned int unk0484;
    unsigned int unk0488;
    unsigned int unk048C;
    unsigned int unk0490;
    unsigned int unk0494;
    unsigned int unk0498;
    unsigned int unk049C;
    unsigned int unk04A0;
    unsigned int unk04A4;
    unsigned int unk04A8;
    unsigned int unk04AC;
    unsigned int unk04B0;
    unsigned int unk04B4;
    unsigned int unk04B8;
    unsigned int unk04BC;
    unsigned int unk04C0;
    unsigned int unk04C4;
    unsigned int unk04C8;
    unsigned int unk04CC;
    unsigned int unk04D0;
    unsigned int unk04D4;
    unsigned int unk04D8;
    unsigned int unk04DC;
    unsigned int unk04E0;
    unsigned int unk04E4;
    unsigned int unk04E8;
    unsigned int unk04EC;
    unsigned int unk04F0;
    unsigned int unk04F4;
    unsigned int unk04F8;
    unsigned int unk04FC;
    unsigned int unk0500;
    unsigned int unk0504;
    unsigned int unk0508;
    unsigned int unk050C;
    unsigned int unk0510;
    unsigned int unk0514;
    unsigned int unk0518;
    unsigned int unk051C;
    unsigned int unk0520;
    unsigned int unk0524;
    unsigned int unk0528;
    unsigned int unk052C;
    unsigned int unk0530;
    unsigned int unk0534;
    unsigned int unk0538;
    unsigned int unk053C;
    unsigned int unk0540;
    unsigned int unk0544;
    unsigned int unk0548;
    unsigned int unk054C;
    unsigned int unk0550;
    unsigned int unk0554;
    unsigned int unk0558;
    unsigned int unk055C;
    unsigned int unk0560;
    unsigned int unk0564;
    unsigned int unk0568;
    unsigned int unk056C;
    unsigned int unk0570;
    unsigned int unk0574;
    unsigned int unk0578;
    unsigned int unk057C;
    unsigned int unk0580;
    unsigned int unk0584;
    unsigned int unk0588;
    unsigned int unk058C;
    unsigned int unk0590;
    unsigned int unk0594;
    unsigned int unk0598;
    unsigned int unk059C;
    unsigned int unk05A0;
    unsigned int unk05A4;
    unsigned int unk05A8;
    unsigned int unk05AC;
    unsigned int unk05B0;
    unsigned int unk05B4;
    unsigned int unk05B8;
    unsigned int unk05BC;
    unsigned int unk05C0;
    unsigned int unk05C4;
    unsigned int unk05C8;
    unsigned int unk05CC;
    unsigned int unk05D0;
    unsigned int unk05D4;
    unsigned int unk05D8;
    unsigned int unk05DC;
    unsigned int unk05E0;
    unsigned int unk05E4;
    unsigned int unk05E8;
    unsigned int unk05EC;
    unsigned int unk05F0;
    unsigned int unk05F4;
    unsigned int unk05F8;
    unsigned int unk05FC;
    unsigned int unk0600;
    unsigned int unk0604;
    unsigned int unk0608;
    unsigned int unk060C;
    unsigned int unk0610;
    unsigned int unk0614;
    unsigned int unk0618;
    unsigned int unk061C;
    unsigned int unk0620;
    unsigned int unk0624;
    unsigned int unk0628;
    unsigned int unk062C;
    unsigned int unk0630;
    unsigned int unk0634;
    unsigned int unk0638;
    unsigned int unk063C;
    unsigned int unk0640;
    unsigned int unk0644;
    unsigned int unk0648;
    unsigned int unk064C;
    unsigned int unk0650;
    unsigned int unk0654;
    unsigned int unk0658;
    unsigned int unk065C;
    unsigned int unk0660;
    unsigned int unk0664;
    unsigned int unk0668;
    unsigned int unk066C;
    unsigned int unk0670;
    unsigned int unk0674;
    unsigned int unk0678;
    unsigned int unk067C;
    unsigned int unk0680;
    unsigned int unk0684;
    unsigned int unk0688;
    unsigned int unk068C;
    unsigned int unk0690;
    unsigned int unk0694;
    unsigned int unk0698;
    unsigned int unk069C;
    unsigned int unk06A0;
    unsigned int unk06A4;
    unsigned int unk06A8;
    unsigned int unk06AC;
    unsigned int unk06B0;
    unsigned int unk06B4;
    unsigned int unk06B8;
    unsigned int unk06BC;
    unsigned int unk06C0;
    unsigned int unk06C4;
    unsigned int unk06C8;
    unsigned int unk06CC;
    unsigned int unk06D0;
    unsigned int unk06D4;
    unsigned int unk06D8;
    unsigned int unk06DC;
    unsigned int unk06E0;
    unsigned int unk06E4;
    unsigned int unk06E8;
    unsigned int unk06EC;
    unsigned int unk06F0;
    unsigned int unk06F4;
    unsigned int unk06F8;
    unsigned int unk06FC;
    unsigned int unk0700;
    unsigned int unk0704;
    unsigned int unk0708;
    unsigned int unk070C;
    unsigned int unk0710;
    unsigned int unk0714;
    unsigned int unk0718;
    unsigned int unk071C;
    unsigned int unk0720;
    unsigned int unk0724;
    unsigned int unk0728;
    unsigned int unk072C;
    unsigned int unk0730;
    unsigned int unk0734;
    unsigned int unk0738;
    unsigned int unk073C;
    unsigned int unk0740;
    unsigned int unk0744;
    unsigned int unk0748;
    unsigned int unk074C;
    unsigned int unk0750;
    unsigned int unk0754;
    unsigned int unk0758;
    unsigned int unk075C;
    unsigned int unk0760;
    unsigned int unk0764;
    unsigned int unk0768;
    unsigned int unk076C;
    unsigned int unk0770;
    unsigned int unk0774;
    unsigned int unk0778;
    unsigned int unk077C;
    unsigned int unk0780;
    unsigned int unk0784;
    unsigned int unk0788;
    unsigned int unk078C;
    unsigned int unk0790;
    unsigned int unk0794;
    unsigned int unk0798;
    unsigned int unk079C;
    unsigned int unk07A0;
    unsigned int unk07A4;
    unsigned int unk07A8;
    unsigned int unk07AC;
    unsigned int unk07B0;
    unsigned int unk07B4;
    unsigned int unk07B8;
    unsigned int unk07BC;
    unsigned int unk07C0;
    unsigned int unk07C4;
    unsigned int unk07C8;
    unsigned int unk07CC;
    unsigned int unk07D0;
    unsigned int unk07D4;
    unsigned int unk07D8;
    unsigned int unk07DC;
    unsigned int unk07E0;
    unsigned int unk07E4;
    unsigned int unk07E8;
    unsigned int unk07EC;
    unsigned int unk07F0;
    unsigned int unk07F4;
    unsigned int unk07F8;
    unsigned int unk07FC;
    unsigned int unk0800;
    unsigned int unk0804;
    unsigned int unk0808;
    unsigned int unk080C;
    unsigned int unk0810;
    unsigned int unk0814;
    unsigned int unk0818;
    unsigned int unk081C;
    unsigned int unk0820;
    unsigned int unk0824;
    unsigned int unk0828;
    unsigned int unk082C;
    unsigned int unk0830;
    unsigned int unk0834;
    unsigned int unk0838;
    unsigned int unk083C;
    unsigned int unk0840;
    unsigned int unk0844;
    unsigned int unk0848;
    unsigned int unk084C;
    unsigned int unk0850;
    unsigned int unk0854;
    unsigned int unk0858;
    unsigned int unk085C;
    unsigned int unk0860;
    unsigned int unk0864;
    unsigned int unk0868;
    unsigned int unk086C;
    unsigned int unk0870;
    unsigned int unk0874;
    unsigned int unk0878;
    unsigned int unk087C;
    unsigned int unk0880;
    unsigned int unk0884;
    unsigned int unk0888;
    unsigned int unk088C;
    unsigned int unk0890;
    unsigned int unk0894;
    unsigned int unk0898;
    unsigned int unk089C;
    unsigned int unk08A0;
    unsigned int unk08A4;
    unsigned int unk08A8;
    unsigned int unk08AC;
    unsigned int unk08B0;
    unsigned int unk08B4;
    unsigned int unk08B8;
    unsigned int unk08BC;
    unsigned int unk08C0;
    unsigned int unk08C4;
    unsigned int unk08C8;
    unsigned int unk08CC;
    unsigned int unk08D0;
    unsigned int unk08D4;
    unsigned int unk08D8;
    unsigned int unk08DC;
    unsigned int unk08E0;
    unsigned int unk08E4;
    unsigned int unk08E8;
    unsigned int unk08EC;
    unsigned int unk08F0;
    unsigned int unk08F4;
    unsigned int unk08F8;
    unsigned int unk08FC;
    unsigned int unk0900;
    unsigned int unk0904;
    unsigned int unk0908;
    unsigned int unk090C;
    unsigned int unk0910;
    unsigned int unk0914;
    unsigned int unk0918;
    unsigned int unk091C;
    unsigned int unk0920;
    unsigned int unk0924;
    unsigned int unk0928;
    unsigned int unk092C;
    unsigned int unk0930;
    unsigned int unk0934;
    unsigned int unk0938;
    unsigned int unk093C;
    unsigned int unk0940;
    unsigned int unk0944;
    unsigned int unk0948;
    unsigned int unk094C;
    unsigned int unk0950;
    unsigned int unk0954;
    unsigned int unk0958;
    unsigned int unk095C;
    unsigned int unk0960;
    unsigned int unk0964;
    unsigned int unk0968;
    unsigned int unk096C;
    unsigned int unk0970;
    unsigned int unk0974;
    unsigned int unk0978;
    unsigned int unk097C;
    unsigned int unk0980;
    unsigned int unk0984;
    unsigned int unk0988;
    unsigned int unk098C;
    unsigned int unk0990;
    unsigned int unk0994;
    unsigned int unk0998;
    unsigned int unk099C;
    unsigned int unk09A0;
    unsigned int unk09A4;
    unsigned int unk09A8;
    unsigned int unk09AC;
    unsigned int unk09B0;
    unsigned int unk09B4;
    unsigned int unk09B8;
    unsigned int unk09BC;
    unsigned int unk09C0;
    unsigned int unk09C4;
    unsigned int unk09C8;
    unsigned int unk09CC;
    unsigned int unk09D0;
    unsigned int unk09D4;
    unsigned int unk09D8;
    unsigned int unk09DC;
    unsigned int unk09E0;
    unsigned int unk09E4;
    unsigned int unk09E8;
    unsigned int unk09EC;
    unsigned int unk09F0;
    unsigned int unk09F4;
    unsigned int unk09F8;
    unsigned int unk09FC;
    unsigned int unk0A00;
    unsigned int unk0A04;
    unsigned int unk0A08;
    unsigned int unk0A0C;
    unsigned int unk0A10;
    unsigned int unk0A14;
    unsigned int unk0A18;
    unsigned int unk0A1C;
    unsigned int unk0A20;
    unsigned int unk0A24;
    unsigned int unk0A28;
    unsigned int unk0A2C;
    unsigned int unk0A30;
    unsigned int unk0A34;
    unsigned int unk0A38;
    unsigned int unk0A3C;
    unsigned int unk0A40;
    unsigned int unk0A44;
    unsigned int unk0A48;
    unsigned int unk0A4C;
    unsigned int unk0A50;
    unsigned int unk0A54;
    unsigned int unk0A58;
    unsigned int unk0A5C;
    unsigned int unk0A60;
    unsigned int unk0A64;
    unsigned int unk0A68;
    unsigned int unk0A6C;
    unsigned int unk0A70;
    unsigned int unk0A74;
    unsigned int unk0A78;
    unsigned int unk0A7C;
    unsigned int unk0A80;
    unsigned int unk0A84;
    unsigned int unk0A88;
    unsigned int unk0A8C;
    unsigned int unk0A90;
    unsigned int unk0A94;
    unsigned int unk0A98;
    unsigned int unk0A9C;
    unsigned int unk0AA0;
    unsigned int unk0AA4;
    unsigned int unk0AA8;
    unsigned int unk0AAC;
    unsigned int unk0AB0;
    unsigned int unk0AB4;
    unsigned int unk0AB8;
    unsigned int unk0ABC;
    unsigned int unk0AC0;
    unsigned int unk0AC4;
    unsigned int unk0AC8;
    unsigned int unk0ACC;
    unsigned int unk0AD0;
    unsigned int unk0AD4;
    unsigned int unk0AD8;
    unsigned int unk0ADC;
    unsigned int unk0AE0;
    unsigned int unk0AE4;
    unsigned int unk0AE8;
    unsigned int unk0AEC;
    unsigned int unk0AF0;
    unsigned int unk0AF4;
    unsigned int unk0AF8;
    unsigned int unk0AFC;
    unsigned int unk0B00;
    unsigned int unk0B04;
    unsigned int unk0B08;
    unsigned int unk0B0C;
    unsigned int unk0B10;
    unsigned int unk0B14;
    unsigned int unk0B18;
    unsigned int unk0B1C;
    unsigned int unk0B20;
    unsigned int unk0B24;
    unsigned int unk0B28;
    unsigned int unk0B2C;
    unsigned int unk0B30;
    unsigned int unk0B34;
    unsigned int unk0B38;
    unsigned int unk0B3C;
    unsigned int unk0B40;
    unsigned int unk0B44;
    unsigned int unk0B48;
    unsigned int unk0B4C;
    unsigned int unk0B50;
    unsigned int unk0B54;
    unsigned int unk0B58;
    unsigned int unk0B5C;
    unsigned int unk0B60;
    unsigned int unk0B64;
    unsigned int unk0B68;
    unsigned int unk0B6C;
    unsigned int unk0B70;
    unsigned int unk0B74;
    unsigned int unk0B78;
    unsigned int unk0B7C;
    unsigned int unk0B80;
    unsigned int unk0B84;
    unsigned int unk0B88;
    unsigned int unk0B8C;
    unsigned int unk0B90;
    unsigned int unk0B94;
    unsigned int unk0B98;
    unsigned int unk0B9C;
    unsigned int unk0BA0;
    unsigned int unk0BA4;
    unsigned int unk0BA8;
    unsigned int unk0BAC;
    unsigned int unk0BB0;
    unsigned int unk0BB4;
    unsigned int unk0BB8;
    unsigned int unk0BBC;
    unsigned int unk0BC0;
    unsigned int unk0BC4;
    unsigned int unk0BC8;
    unsigned int unk0BCC;
    unsigned int unk0BD0;
    unsigned int unk0BD4;
    unsigned int unk0BD8;
    unsigned int unk0BDC;
    unsigned int unk0BE0;
    unsigned int unk0BE4;
    unsigned int unk0BE8;
    unsigned int unk0BEC;
    unsigned int unk0BF0;
    unsigned int unk0BF4;
    unsigned int unk0BF8;
    unsigned int unk0BFC;
    unsigned int unk0C00;
    unsigned int unk0C04;
    unsigned int unk0C08;
    unsigned int unk0C0C;
    unsigned int unk0C10;
    unsigned int unk0C14;
    unsigned int unk0C18;
    unsigned int unk0C1C;
    unsigned int unk0C20;
    unsigned int unk0C24;
    unsigned int unk0C28;
    unsigned int unk0C2C;
    unsigned int unk0C30;
    unsigned int unk0C34;
    unsigned int unk0C38;
    unsigned int unk0C3C;
    unsigned int unk0C40;
    unsigned int unk0C44;
    unsigned int unk0C48;
    unsigned int unk0C4C;
    unsigned int unk0C50;
    unsigned int unk0C54;
    unsigned int unk0C58;
    unsigned int unk0C5C;
    unsigned int unk0C60;
    unsigned int unk0C64;
    unsigned int unk0C68;
    unsigned int unk0C6C;
    unsigned int unk0C70;
    unsigned int unk0C74;
    unsigned int unk0C78;
    unsigned int unk0C7C;
    unsigned int unk0C80;
    unsigned int unk0C84;
    unsigned int unk0C88;
    unsigned int unk0C8C;
    unsigned int unk0C90;
    unsigned int unk0C94;
    unsigned int unk0C98;
    unsigned int unk0C9C;
    unsigned int unk0CA0;
    unsigned int unk0CA4;
    unsigned int unk0CA8;
    unsigned int unk0CAC;
    unsigned int unk0CB0;
    unsigned int unk0CB4;
    unsigned int unk0CB8;
    unsigned int unk0CBC;
    unsigned int unk0CC0;
    unsigned int unk0CC4;
    unsigned int unk0CC8;
    unsigned int unk0CCC;
    unsigned int unk0CD0;
    unsigned int unk0CD4;
    unsigned int unk0CD8;
    unsigned int unk0CDC;
    unsigned int unk0CE0;
    unsigned int unk0CE4;
    unsigned int unk0CE8;
    unsigned int unk0CEC;
    unsigned int unk0CF0;
    unsigned int unk0CF4;
    unsigned int unk0CF8;
    unsigned int unk0CFC;
    unsigned int unk0D00;
    unsigned int unk0D04;
    unsigned int unk0D08;
    unsigned int unk0D0C;
    unsigned int unk0D10;
    unsigned int unk0D14;
    unsigned int unk0D18;
    unsigned int unk0D1C;
    unsigned int unk0D20;
    unsigned int unk0D24;
    unsigned int unk0D28;
    unsigned int unk0D2C;
    unsigned int unk0D30;
    unsigned int unk0D34;
    unsigned int unk0D38;
    unsigned int unk0D3C;
    unsigned int unk0D40;
    unsigned int unk0D44;
    unsigned int unk0D48;
    unsigned int unk0D4C;
    unsigned int unk0D50;
    unsigned int unk0D54;
    unsigned int unk0D58;
    unsigned int unk0D5C;
    unsigned int unk0D60;
    unsigned int unk0D64;
    unsigned int unk0D68;
    unsigned int unk0D6C;
    unsigned int unk0D70;
    unsigned int unk0D74;
    unsigned int unk0D78;
    unsigned int unk0D7C;
    unsigned int unk0D80;
    unsigned int unk0D84;
    unsigned int unk0D88;
    unsigned int unk0D8C;
    unsigned int unk0D90;
    unsigned int unk0D94;
    unsigned int unk0D98;
    unsigned int unk0D9C;
    unsigned int unk0DA0;
    unsigned int unk0DA4;
    unsigned int unk0DA8;
    unsigned int unk0DAC;
    unsigned int unk0DB0;
    unsigned int unk0DB4;
    unsigned int unk0DB8;
    unsigned int unk0DBC;
    unsigned int unk0DC0;
    unsigned int unk0DC4;
    unsigned int unk0DC8;
    unsigned int unk0DCC;
    unsigned int unk0DD0;
    unsigned int unk0DD4;
    unsigned int unk0DD8;
    unsigned int unk0DDC;
    unsigned int unk0DE0;
    unsigned int unk0DE4;
    unsigned int unk0DE8;
    unsigned int unk0DEC;
    unsigned int unk0DF0;
    unsigned int unk0DF4;
    unsigned int unk0DF8;
    unsigned int unk0DFC;
    unsigned int unk0E00;
    unsigned int unk0E04;
    unsigned int unk0E08;
    unsigned int unk0E0C;
    unsigned int unk0E10;
    unsigned int unk0E14;
    unsigned int unk0E18;
    unsigned int unk0E1C;
    unsigned int unk0E20;
    unsigned int unk0E24;
    unsigned int unk0E28;
    unsigned int unk0E2C;
    unsigned int unk0E30;
    unsigned int unk0E34;
    unsigned int unk0E38;
    unsigned int unk0E3C;
    unsigned int unk0E40;
    unsigned int unk0E44;
    unsigned int unk0E48;
    unsigned int unk0E4C;
    unsigned int unk0E50;
    unsigned int unk0E54;
    unsigned int unk0E58;
    unsigned int unk0E5C;
    unsigned int unk0E60;
    unsigned int unk0E64;
    unsigned int unk0E68;
    CaravanObj* m_0e6c;
    CaravanObj* m_0e70;
    void FUN_0074edd0();
};
extern float DAT_01024100;

// @fnv 0x0074edd0
void FUN_0074edd0_cls::FUN_0074edd0()
{
    Vec3Temp a;
    Vec3Temp b;
    m_0e6c->FUN_004bc1f0(0.0f, 0.0f, DAT_01024100);
    m_0e70->FUN_004bc1f0(0.0f, 0.0f, DAT_01024100);
    m_0e6c->FUN_00a59c60(a.FUN_0043d410(0.0f, 0, 0));
    m_0e70->FUN_00a59c60(b.FUN_0043d410(0.0f, 0, 0));
}

namespace fnv_0074fc00 {
int __cdecl MinInt(int, int);
unsigned int __cdecl GetRandomNumberInRange(int, int);

struct NiRTTI
{
    int unk00;
};
extern NiRTTI g_controllerManagerRTTI;

struct NiFixedString
{
    const char* m_kHandle;
    NiFixedString(const char* s);
    ~NiFixedString();
};

struct NiControllerSequence;

struct NiControllerManager
{
    NiControllerSequence* FUN_0047a520(const NiFixedString& name);
    bool FUN_0047aab0(NiControllerSequence* seq, int priority, int startOver, float weight, float easeInTime,
                      NiControllerSequence* timeSyncSeq);
};

struct NiAVObject
{
    NiAVObject* Clone();
    NiControllerManager* GetController(const NiRTTI* rtti);
};

void __cdecl UpdateNodeTransforms(NiAVObject* node);

struct NodeArray
{
    unsigned int Add(NiAVObject*& node);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct SequenceList
{
    void AddHead(NiControllerSequence*& seq);
};

struct SceneNode
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void AttachChildInAvailableSlot(NiAVObject* child, bool firstAvail);
};

struct SceneNodePtr
{
    SceneNode* m_pObject;
    operator SceneNode*() const;
};
extern SceneNodePtr g_sceneNode;

struct CaravanCardMenu
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
    NiAVObject* cardModels[3];
    int unk128;
    int unk12c;
    int unk130;
    NodeArray cardNodes;
    SequenceList* sequences;

    void PlayCardPlacement(int aiIndex);
};

// @fnv 0x0074fc00
void CaravanCardMenu::PlayCardPlacement(int aiIndex)
{
    aiIndex = MinInt(aiIndex, 2);
    NiAVObject* pNode = cardModels[aiIndex]->Clone();
    unsigned int uiPlace = GetRandomNumberInRange(0, 2);
    NiControllerManager* pController4 = pNode->GetController(&g_controllerManagerRTTI);
    NiControllerSequence* pSequenceTmp;
    switch (uiPlace)
    {
    case 0:
        if (pController4)
        {
            NiControllerManager* pManager5 = pController4;
            pSequenceTmp = pManager5->FUN_0047a520(NiFixedString("Top_Place"));
            pManager5->FUN_0047aab0(pSequenceTmp, 0, 0, 1.0f, 0.0f, 0);
            UpdateNodeTransforms(pNode);
        }
        break;
    case 1:
        if (pController4)
        {
            NiControllerManager* pMgr4 = pController4;
            pSequenceTmp = pMgr4->FUN_0047a520(NiFixedString("Bottom_Place"));
            pMgr4->FUN_0047aab0(pSequenceTmp, 0, 0, 1.0f, 0.0f, 0);
            UpdateNodeTransforms(pNode);
        }
        break;
    }
    cardNodes.Add(pNode);
    sequences->AddHead(pSequenceTmp);
    ((SceneNode*)g_sceneNode)->AttachChildInAvailableSlot(pNode, true);
}
}  // namespace fnv_0074fc00

struct GameList
{
    unsigned int __thiscall FUN_0044ddc0();
    int* __thiscall FUN_006a7ad0(unsigned int index);
    void __thiscall FUN_009a4320(unsigned int index, int removeFlag);
    ~GameList();
};
struct GroupRegistry
{
    bool __thiscall GetAt(void* key, GameList** result);
    void __thiscall RemoveKey(void* key);
    void __thiscall RemoveValueFromGroup(void* key, int value);
};
// Looks up the list for key, scans it for value, and removes that entry (deleting the list and key if it was the only one).
// @fnv 0x009a4120
void __thiscall GroupRegistry::RemoveValueFromGroup(void* key, int value)
{
    GameList* entries = 0;
    if (GetAt(key, &entries))
    {
        for (unsigned int index = 0; index < entries->FUN_0044ddc0(); ++index)
        {
            if (*entries->FUN_006a7ad0(index) == value)
            {
                if (entries->FUN_0044ddc0() == 1)
                {
                    delete entries;
                    RemoveKey(key);
                }
                else
                {
                    entries->FUN_009a4320(index, 1);
                }
                break;
            }
        }
    }
}

struct ConstructorBase
{
    ConstructorBase();
    virtual ~ConstructorBase();
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
};
struct MenuList
{
    MenuList();
    ~MenuList();
    int value;
    int next;
};
struct ArrayMember
{
    ArrayMember();
    ~ArrayMember();
    int a;
    int b;
    int c;
    int d;
    MenuList* list;
    int f;
};
struct SmallMember
{
    SmallMember();
    ~SmallMember();
    int a;
    int b;
    int c;
    int d;
};
struct OtherMember
{
    OtherMember();
    ~OtherMember();
    int a;
    int b;
    int c;
    int d;
};
extern int DAT_011d9170, DAT_011d9174, DAT_011d916c;
int __cdecl RegisterTrait(const char*, int);
struct FUN_0073b7e0 : ConstructorBase
{
    ArrayMember first;
    ArrayMember second;
    SmallMember one;
    SmallMember two;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
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
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    int unk9a8;
    int unk9ac;
    int unk9b0;
    int unk9b4;
    int unk9b8;
    int unk9bc;
    int unk9c0;
    int unk9c4;
    int unk9c8;
    int unk9cc;
    int unk9d0;
    int unk9d4;
    int unk9d8;
    int unk9dc;
    int unk9e0;
    int unk9e4;
    int unk9e8;
    int unk9ec;
    int unk9f0;
    int unk9f4;
    int unk9f8;
    int unk9fc;
    int unka00;
    int unka04;
    int unka08;
    int unka0c;
    int unka10;
    int unka14;
    int unka18;
    int unka1c;
    int unka20;
    int unka24;
    int unka28;
    int unka2c;
    int unka30;
    int unka34;
    int unka38;
    int unka3c;
    int unka40;
    int unka44;
    int unka48;
    int unka4c;
    int unka50;
    int unka54;
    int unka58;
    int unka5c;
    int unka60;
    int unka64;
    int unka68;
    OtherMember third;
    SmallMember hands[6];
    int unkadc;
    int unkae0;
    int unkae4;
    int unkae8;
    int unkaec;
    int unkaf0;
    int unkaf4;
    int unkaf8;
    int unkafc;
    int unkb00;
    OtherMember fourth;
    OtherMember fifth;
    OtherMember sixth;
    OtherMember seventh;
    OtherMember cards[42];
    int unkde4;
    int unkde8;
    int unkdec;
    int unkdf0;
    int unkdf4;
    int unkdf8;
    int unkdfc;
    int unke00;
    int unke04;
    int unke08;
    int unke0c;
    int unke10;
    int unke14;
    int unke18;
    int unke1c;
    int unke20;
    int unke24;
    int unke28;
    int unke2c;
    int unke30;
    int unke34;
    int unke38;
    int unke3c;
    int unke40;
    int unke44;
    int unke48;
    int unke4c;
    int unke50;
    int unke54;
    int unke58;
    int unke5c;
    int unke60;
    int unke64;
    int unke68;
    int unke6c;
    int unke70;
    int unke74;
    char unke78;
    char unke79;
    char unke7a;
    char unke7b;
    int unke7c;
    int unke80;
    char unke84;
    char unke85;
    char unke86;
    FUN_0073b7e0();
    virtual ~FUN_0073b7e0();
    void Initialize();
    void SetState(int, int);
};
// Registers the _current_value, _Value and _x traits, initialises member fields, then calls Initialize and SetState(1,1) and allocates two MenuLists.
// @fnv 0x0073b7e0
FUN_0073b7e0::FUN_0073b7e0()
{
    DAT_011d9170 = RegisterTrait("_current_value", -1);
    DAT_011d9174 = RegisterTrait("_Value", -1);
    DAT_011d916c = RegisterTrait("_x", -1);
    unk02c = 0;
    unk0fc = 0;
    unkadc = 0;
    unkae0 = 0;
    unkae4 = 100;
    unkaec = 25;
    unkaf0 = 100;
    unke2c = 0;
    unke30 = 0;
    unke34 = 0;
    unke38 = 0;
    unkafc = 0;
    unke84 = 0;
    unke85 = 0;
    unke78 = 0;
    unke86 = 1;
    Initialize();
    SetState(1, 1);
    second.list = new MenuList;
    first.list = new MenuList;
}

struct SceneNode;
struct UpdateInfo
{
    float time;
    bool a;
    bool b;
    unsigned int flags;
    UpdateInfo(float, bool, bool);
};
struct FixedName
{
    const char* data;
    FixedName(const char*);
    ~FixedName();
};
struct Controller
{
    void* Find(const FixedName&);
    void SetTime(float);
};
struct Bound
{
    float Radius() const;
};
struct SceneNode
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
    virtual void Attach(SceneNode*, int);
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    SceneNode(unsigned short);
    void Update(UpdateInfo&);
    Controller* GetController(const void*);
    const Bound& GetBound() const;
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
};
struct ScenePtr
{
    SceneNode* p;
    ScenePtr& operator=(SceneNode*);
    operator SceneNode*() const;
};
extern ScenePtr sceneRoot;
extern ScenePtr sceneObject;
struct Loader
{
    SceneNode* LoadFile(const char*, int, bool, bool, bool, bool);
};
extern Loader* loader;
extern int controllerType;
void __cdecl PrepareScene(SceneNode*);
SceneNode* __cdecl FindObject(SceneNode*, const char*);
struct Shadow : SceneNode
{
    void Configure(SceneNode*, float);
};
Shadow* __cdecl GetShadow(int);
struct SceneMenu
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
    SceneNode* model;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
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
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    Controller* controller;
    void* sequence244;
    void* sequence248;
    void* sequence24c;
    SceneNode* Fallback();
    void InitCaravanTable();
};
// @fnv 0x0073cbf0
void SceneMenu::InitCaravanTable()
{
    model = loader->LoadFile("Meshes\\Terminals\\NV_Caravan\\NV_Caravan-Table.NIF", 0, true, false, false, false);
    sceneRoot = new SceneNode(0);
    ((SceneNode*)sceneRoot)->Attach(model, 1);
    UpdateInfo update8(0.0f, false, false);
    ((SceneNode*)sceneRoot)->Update(update8);
    Controller* control3 = model->GetController(&controllerType);
    if (control3)
    {
        controller = control3;
        sequence244 = controller->Find(FixedName("Bet_to_Deck"));
        sequence248 = controller->Find(FixedName("Deck_to_Play"));
        sequence24c = controller->Find(FixedName("Play_to_Bet"));
        controller->SetTime(0.0f);
        PrepareScene(model);
    }
    SceneNode* object = model;
    sceneObject = FindObject(object, "object0");
    if (!sceneObject)
        sceneObject = Fallback();
    GetShadow(1)->Attach(sceneRoot, 1);
    float radius = ((SceneNode*)sceneRoot)->GetBound().Radius() * 2.5;
    GetShadow(1)->Configure(sceneRoot, radius);
}

struct CurrencyForm
{
    int FUN_00401170();
};
struct CurrencyItem
{
    CurrencyForm* FUN_0044ddc0();
    int FUN_00726070();
};
struct CurrencyLink
{
    CurrencyItem** FUN_006815c0();
    CurrencyLink* FUN_00726070();
};
struct CurrencyList
{
    CurrencyLink* head;
    int GetCountableItemCount();
};
struct CurrencyReference;
struct CurrencyHandler
{
    void UpdateInventoryForReference(CurrencyReference* reference);
    CurrencyList* FUN_00740960();
};
extern CurrencyHandler* g_011c3f2c;
extern CurrencyReference* g_011dea3c;
int FUN_0048e8a0(CurrencyForm* form);
struct CurrencyQuery
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
    CurrencyReference* target;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    int targetTotal;
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
    unsigned int unk410;
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
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
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
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66c;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67c;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68c;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69c;
    unsigned int unk6a0;
    unsigned int unk6a4;
    unsigned int unk6a8;
    unsigned int unk6ac;
    unsigned int unk6b0;
    unsigned int unk6b4;
    unsigned int unk6b8;
    unsigned int unk6bc;
    unsigned int unk6c0;
    unsigned int unk6c4;
    unsigned int unk6c8;
    unsigned int unk6cc;
    unsigned int unk6d0;
    unsigned int unk6d4;
    unsigned int unk6d8;
    unsigned int unk6dc;
    unsigned int unk6e0;
    unsigned int unk6e4;
    unsigned int unk6e8;
    unsigned int unk6ec;
    unsigned int unk6f0;
    unsigned int unk6f4;
    unsigned int unk6f8;
    unsigned int unk6fc;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70c;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71c;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72c;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73c;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74c;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75c;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76c;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77c;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78c;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79c;
    unsigned int unk7a0;
    unsigned int unk7a4;
    unsigned int unk7a8;
    unsigned int unk7ac;
    unsigned int unk7b0;
    unsigned int unk7b4;
    unsigned int unk7b8;
    unsigned int unk7bc;
    unsigned int unk7c0;
    unsigned int unk7c4;
    unsigned int unk7c8;
    unsigned int unk7cc;
    unsigned int unk7d0;
    unsigned int unk7d4;
    unsigned int unk7d8;
    unsigned int unk7dc;
    unsigned int unk7e0;
    unsigned int unk7e4;
    unsigned int unk7e8;
    unsigned int unk7ec;
    unsigned int unk7f0;
    unsigned int unk7f4;
    unsigned int unk7f8;
    unsigned int unk7fc;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80c;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81c;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82c;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83c;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84c;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85c;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86c;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87c;
    unsigned int unk880;
    unsigned int unk884;
    unsigned int unk888;
    unsigned int unk88c;
    unsigned int unk890;
    unsigned int unk894;
    unsigned int unk898;
    unsigned int unk89c;
    unsigned int unk8a0;
    unsigned int unk8a4;
    unsigned int unk8a8;
    unsigned int unk8ac;
    unsigned int unk8b0;
    unsigned int unk8b4;
    unsigned int unk8b8;
    unsigned int unk8bc;
    unsigned int unk8c0;
    unsigned int unk8c4;
    unsigned int unk8c8;
    unsigned int unk8cc;
    unsigned int unk8d0;
    unsigned int unk8d4;
    unsigned int unk8d8;
    unsigned int unk8dc;
    unsigned int unk8e0;
    unsigned int unk8e4;
    unsigned int unk8e8;
    unsigned int unk8ec;
    unsigned int unk8f0;
    unsigned int unk8f4;
    unsigned int unk8f8;
    unsigned int unk8fc;
    unsigned int unk900;
    unsigned int unk904;
    unsigned int unk908;
    unsigned int unk90c;
    unsigned int unk910;
    unsigned int unk914;
    unsigned int unk918;
    unsigned int unk91c;
    unsigned int unk920;
    unsigned int unk924;
    unsigned int unk928;
    unsigned int unk92c;
    unsigned int unk930;
    unsigned int unk934;
    unsigned int unk938;
    unsigned int unk93c;
    unsigned int unk940;
    unsigned int unk944;
    unsigned int unk948;
    unsigned int unk94c;
    unsigned int unk950;
    unsigned int unk954;
    unsigned int unk958;
    unsigned int unk95c;
    unsigned int unk960;
    unsigned int unk964;
    unsigned int unk968;
    unsigned int unk96c;
    unsigned int unk970;
    unsigned int unk974;
    unsigned int unk978;
    unsigned int unk97c;
    unsigned int unk980;
    unsigned int unk984;
    unsigned int unk988;
    unsigned int unk98c;
    unsigned int unk990;
    unsigned int unk994;
    unsigned int unk998;
    unsigned int unk99c;
    unsigned int unk9a0;
    unsigned int unk9a4;
    unsigned int unk9a8;
    unsigned int unk9ac;
    unsigned int unk9b0;
    unsigned int unk9b4;
    unsigned int unk9b8;
    unsigned int unk9bc;
    unsigned int unk9c0;
    unsigned int unk9c4;
    unsigned int unk9c8;
    unsigned int unk9cc;
    unsigned int unk9d0;
    unsigned int unk9d4;
    unsigned int unk9d8;
    unsigned int unk9dc;
    unsigned int unk9e0;
    unsigned int unk9e4;
    unsigned int unk9e8;
    unsigned int unk9ec;
    unsigned int unk9f0;
    unsigned int unk9f4;
    unsigned int unk9f8;
    unsigned int unk9fc;
    unsigned int unka00;
    unsigned int unka04;
    unsigned int unka08;
    unsigned int unka0c;
    unsigned int unka10;
    unsigned int unka14;
    unsigned int unka18;
    unsigned int unka1c;
    unsigned int unka20;
    unsigned int unka24;
    unsigned int unka28;
    unsigned int unka2c;
    unsigned int unka30;
    unsigned int unka34;
    unsigned int unka38;
    unsigned int unka3c;
    unsigned int unka40;
    unsigned int unka44;
    unsigned int unka48;
    unsigned int unka4c;
    unsigned int unka50;
    unsigned int unka54;
    unsigned int unka58;
    unsigned int unka5c;
    unsigned int unka60;
    unsigned int unka64;
    unsigned int unka68;
    unsigned int unka6c;
    unsigned int unka70;
    unsigned int unka74;
    unsigned int unka78;
    unsigned int unka7c;
    unsigned int unka80;
    unsigned int unka84;
    unsigned int unka88;
    unsigned int unka8c;
    unsigned int unka90;
    unsigned int unka94;
    unsigned int unka98;
    unsigned int unka9c;
    unsigned int unkaa0;
    unsigned int unkaa4;
    unsigned int unkaa8;
    unsigned int unkaac;
    unsigned int unkab0;
    unsigned int unkab4;
    unsigned int unkab8;
    unsigned int unkabc;
    unsigned int unkac0;
    unsigned int unkac4;
    unsigned int unkac8;
    unsigned int unkacc;
    unsigned int unkad0;
    unsigned int unkad4;
    unsigned int unkad8;
    unsigned int unkadc;
    unsigned int unkae0;
    int playerTotal;
    void ComputePlayerAndTargetTotals();
};
// Sums the player's and target's currency totals by iterating the currency list and adding value times count for form type 0x74.
// @fnv 0x0073d650
void CurrencyQuery::ComputePlayerAndTargetTotals()
{
    playerTotal = 0;
    g_011c3f2c->UpdateInventoryForReference(g_011dea3c);
    CurrencyList* list = g_011c3f2c->FUN_00740960();
    playerTotal = list->GetCountableItemCount();
    CurrencyLink* link5 = list->head;
    CurrencyForm* form = 0;
    while (link5 && *link5->FUN_006815c0())
    {
        int count = 0;
        form = (*link5->FUN_006815c0())->FUN_0044ddc0();
        if (form && form->FUN_00401170() == 0x74)
        {
            if ((*link5->FUN_006815c0())->FUN_00726070() > 0)
            {
                count = (*link5->FUN_006815c0())->FUN_00726070();
                playerTotal += FUN_0048e8a0(form) * count;
            }
        }
        else
            form = 0;
        link5 = link5->FUN_00726070();
    }
    targetTotal = 0;
    g_011c3f2c->UpdateInventoryForReference(target);
    list = g_011c3f2c->FUN_00740960();
    targetTotal = list->GetCountableItemCount();
    link5 = list->head;
    form = 0;
    while (link5 && *link5->FUN_006815c0())
    {
        int count = 0;
        form = (*link5->FUN_006815c0())->FUN_0044ddc0();
        if (form && form->FUN_00401170() == 0x74)
        {
            if ((*link5->FUN_006815c0())->FUN_00726070() > 0)
            {
                count = (*link5->FUN_006815c0())->FUN_00726070();
                targetTotal += FUN_0048e8a0(form) * count;
            }
        }
        else
            form = 0;
        link5 = link5->FUN_00726070();
    }
}

namespace CaravanSetup {
struct FixedString
{
    const char* value;
    FixedString(const char*);
    ~FixedString();
};
struct UpdateData
{
    float time;
    bool updateControllers, m_bUpdateGeometry, unk06, unk07, unk08;
    UpdateData(float, bool, bool);
};
struct Property
{
    int FUN_00441110();
};
struct Node
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
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
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
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
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
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void slot2e();
    virtual void slot2f();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void Attach(Node*, bool);
    void FUN_00a59c60(const UpdateData&);
    Node* FUN_00a5c570(void*);
    Node* FUN_0047a520(const FixedString&);
    void FUN_0048fef0(float);
    Property* FUN_00a59d30(int);
};
struct Loader
{
    Node* LoadModel(const char*, int, bool, int, int, int);
};
extern Loader* DAT_011c3b3c;
struct Scene
{
    Node* FUN_00559450();
};
extern Scene DAT_011d91e4;
extern unsigned int DAT_011f36ac;
struct Array
{
    unsigned int unk00, unk04, unk08, unk0c;
    void FUN_008454f0(bool);
};
struct TileView
{
    void SetTraitAndReset(int, float);
    void FUN_00715c60(int, const char*);
    void FUN_00a01350(int, const char*, bool);
    float FUN_00a011b0(int, bool = true);
    void FUN_00a012d0(int, float);
    void FUN_00a07530(int);
    void FUN_00700320(int, bool);
};
struct PlayerName
{
    const char* FUN_005ae380();
};
struct Player
{
    PlayerName* GetField618();
};
extern Player* DAT_011dea3c;
struct Setting
{
    const char* FUN_00403df0();
};
extern Setting DAT_011d2e68;
extern Setting DAT_011d3d48;
extern Setting DAT_011d2f70;
extern Setting DAT_011d2160;
extern Setting DAT_011d2ec8;
extern Setting DAT_011d3ea4;
extern Setting DAT_011d354c;
extern Setting DAT_011d2784;
extern const char DAT_0107121c[];
extern const char DAT_010711e4[];
extern const char DAT_010714c8[];
extern const char DAT_010714b4[];
extern const char DAT_010714a8[];
extern const char DAT_01071494[];
extern const char DAT_01071480[];
extern const char DAT_01071474[];
extern const char DAT_0107145c[];
extern const char DAT_01071444[];
extern const char DAT_01071430[];
extern const char DAT_01071418[];
extern const char DAT_01071400[];
extern const char DAT_010713f0[];
extern const char DAT_010713e4[];
extern const char DAT_010713d4[];
extern const char DAT_010713c0[];
extern const char DAT_010713a8[];
extern const char DAT_0107139c[];
extern const char DAT_0107138c[];
extern const char DAT_0107137c[];
extern const char DAT_01071368[];
extern const char DAT_01012058[];
extern const char DAT_010633a0[];
extern const char DAT_01071358[];
extern int DAT_011d9174;
int MinInt(int, int);
void FUN_00a6d2d0(Node*);
void FUN_00406d00(char*, unsigned int, const char*, ...);
Node* FUN_004aae30(Node*, const char*);
bool FUN_004b71d0();
int TraitNameToID(const char*);
struct Menu
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
    TileView* unk30;
    TileView* unk34;
    TileView* unk38;
    TileView* unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    TileView* unk50;
    TileView* unk54;
    TileView* unk58;
    TileView* unk5c;
    TileView* unk60;
    TileView* unk64;
    TileView* unk68;
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
    TileView* unkcc;
    int unkd0;
    int unkd4;
    TileView* unkd8;
    TileView* unkdc;
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
    Array array164;
    Array array174;
    int unk184;
    Node* unk188;
    Node* unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
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
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    Node* unk254;
    Node* unk258;
    Node* unk25c;
    Node* unk260;
    Node* unk264;
    Node* unk268;
    Node* unk26c;
    Node* unk270;
    Node* unk274;
    Node* unk278;
    Node* unk27c;
    Node* unk280;
    Node* unk284;
    Node* unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    union
    {
        Property* properties[96];
        struct
        {
            Property* playerFaces[24];
            Property* playerBacks[24];
            Property* npcFaces[24];
            Property* npcBacks[24];
        };
    };
    int unka6c;
    int unka70;
    int unka74;
    int unka78;
    int unka7c;
    int unka80;
    int unka84;
    int unka88;
    int unka8c;
    int unka90;
    int unka94;
    int unka98;
    int unka9c;
    int unkaa0;
    int unkaa4;
    int unkaa8;
    int unkaac;
    int unkab0;
    int unkab4;
    int unkab8;
    int unkabc;
    int unkac0;
    int unkac4;
    int unkac8;
    int unkacc;
    int unkad0;
    int unkad4;
    int unkad8;
    int unkadc;
    int unkae0;
    int unkae4;
    int unkae8;
    int unkaec;
    const char* unkaf0;
    void UpdateCardSlots(int, int);
    void UpdateControls();
    void InitMenu();
};
// @fnv 0x0073d850
void Menu::InitMenu()
{
    unk18c = DAT_011c3b3c->LoadModel(DAT_0107121c, 0, true, 0, 0, 0);
    unk188 = DAT_011c3b3c->LoadModel(DAT_010711e4, 0, true, 0, 0, 0);
    DAT_011d91e4.FUN_00559450()->Attach(unk188, true);
    DAT_011d91e4.FUN_00559450()->Attach(unk18c, true);
    array164.FUN_008454f0(true);
    array174.FUN_008454f0(true);
    DAT_011d91e4.FUN_00559450()->FUN_00a59c60(UpdateData(0, 0, 0));
    unkae8 = MinInt(unkadc, unkae0);
    Node* pNode = unk18c->FUN_00a5c570(&DAT_011f36ac);
    if (pNode)
    {
        unk270 = pNode;
        unk274 = unk270->FUN_0047a520(FixedString(DAT_010714c8));
        unk278 = unk270->FUN_0047a520(FixedString(DAT_010714b4));
        unk27c = unk270->FUN_0047a520(FixedString(DAT_010714a8));
        unk280 = unk270->FUN_0047a520(FixedString(DAT_01071494));
        unk284 = unk270->FUN_0047a520(FixedString(DAT_01071480));
        unk288 = unk270->FUN_0047a520(FixedString(DAT_01071474));
        unk270->FUN_0048fef0(0);
        FUN_00a6d2d0(unk18c);
    }
    pNode = unk188->FUN_00a5c570(&DAT_011f36ac);
    if (pNode)
    {
        unk254 = pNode;
        unk258 = unk254->FUN_0047a520(FixedString(DAT_0107145c));
        unk25c = unk254->FUN_0047a520(FixedString(DAT_01071444));
        unk260 = unk254->FUN_0047a520(FixedString(DAT_01071430));
        unk264 = unk254->FUN_0047a520(FixedString(DAT_01071418));
        unk268 = unk254->FUN_0047a520(FixedString(DAT_01071400));
        unk26c = unk254->FUN_0047a520(FixedString(DAT_010713f0));
        unk254->FUN_0048fef0(0);
        FUN_00a6d2d0(unk188);
    }
    for (int iClearIndex = 0; iClearIndex < 96; ++iClearIndex)
        properties[iClearIndex] = 0;
    for (int index = 0; index < 24; ++index)
    {
        if (index < 9)
        {
            char cardNames[4][25];

            FUN_00406d00(cardNames[0], 25, DAT_010713e4, index + 1, index);
            FUN_00406d00(cardNames[1], 25, DAT_010713d4, index + 1);
            FUN_00406d00(cardNames[2], 25, DAT_010713c0, index + 1, index);
            FUN_00406d00(cardNames[3], 25, DAT_010713a8, index + 1);
            Node* pCardNode = 0;
            pCardNode = FUN_004aae30(unk18c, cardNames[0]);
            playerFaces[index] = (!pCardNode->FUN_00a59d30(3) ? 0
                                                              : (pCardNode->FUN_00a59d30(3)->FUN_00441110() >= 8 &&
                                                                 pCardNode->FUN_00a59d30(3)->FUN_00441110() <= 12))
                                     ? pCardNode->FUN_00a59d30(3)
                                     : 0;
            pCardNode = FUN_004aae30(unk18c, cardNames[1]);
            playerBacks[index] = (!pCardNode->FUN_00a59d30(3) ? 0
                                                              : (pCardNode->FUN_00a59d30(3)->FUN_00441110() >= 8 &&
                                                                 pCardNode->FUN_00a59d30(3)->FUN_00441110() <= 12))
                                     ? pCardNode->FUN_00a59d30(3)
                                     : 0;
            pCardNode = FUN_004aae30(unk188, cardNames[2]);
            npcFaces[index] = (!pCardNode->FUN_00a59d30(3) ? 0
                                                           : (pCardNode->FUN_00a59d30(3)->FUN_00441110() >= 8 &&
                                                              pCardNode->FUN_00a59d30(3)->FUN_00441110() <= 12))
                                  ? pCardNode->FUN_00a59d30(3)
                                  : 0;
            pCardNode = FUN_004aae30(unk188, cardNames[3]);
            npcBacks[index] = (!pCardNode->FUN_00a59d30(3) ? 0
                                                           : (pCardNode->FUN_00a59d30(3)->FUN_00441110() >= 8 &&
                                                              pCardNode->FUN_00a59d30(3)->FUN_00441110() <= 12))
                                  ? pCardNode->FUN_00a59d30(3)
                                  : 0;
        }
        else
        {
            char cardNames[4][25];

            FUN_00406d00(cardNames[0], 25, DAT_0107139c, index + 1, index);
            FUN_00406d00(cardNames[1], 25, DAT_0107138c, index + 1);
            FUN_00406d00(cardNames[2], 25, DAT_0107137c, index + 1, index);
            FUN_00406d00(cardNames[3], 25, DAT_01071368, index + 1);
            Node* pCardNode = 0;
            pCardNode = FUN_004aae30(unk18c, cardNames[0]);
            playerFaces[index] = (!pCardNode->FUN_00a59d30(3) ? 0
                                                              : (pCardNode->FUN_00a59d30(3)->FUN_00441110() >= 8 &&
                                                                 pCardNode->FUN_00a59d30(3)->FUN_00441110() <= 12))
                                     ? pCardNode->FUN_00a59d30(3)
                                     : 0;
            pCardNode = FUN_004aae30(unk18c, cardNames[1]);
            playerBacks[index] = (!pCardNode->FUN_00a59d30(3) ? 0
                                                              : (pCardNode->FUN_00a59d30(3)->FUN_00441110() >= 8 &&
                                                                 pCardNode->FUN_00a59d30(3)->FUN_00441110() <= 12))
                                     ? pCardNode->FUN_00a59d30(3)
                                     : 0;
            pCardNode = FUN_004aae30(unk188, cardNames[2]);
            npcFaces[index] = (!pCardNode->FUN_00a59d30(3) ? 0
                                                           : (pCardNode->FUN_00a59d30(3)->FUN_00441110() >= 8 &&
                                                              pCardNode->FUN_00a59d30(3)->FUN_00441110() <= 12))
                                  ? pCardNode->FUN_00a59d30(3)
                                  : 0;
            pCardNode = FUN_004aae30(unk188, cardNames[3]);
            npcBacks[index] = (!pCardNode->FUN_00a59d30(3) ? 0
                                                           : (pCardNode->FUN_00a59d30(3)->FUN_00441110() >= 8 &&
                                                              pCardNode->FUN_00a59d30(3)->FUN_00441110() <= 12))
                                  ? pCardNode->FUN_00a59d30(3)
                                  : 0;
        }
    }
    UpdateCardSlots(12, 0);
    unk28 = 1;
    unk2c = 1;
    unk54->SetTraitAndReset(DAT_011d9174, 1.0f);
    unk54->FUN_00715c60(DAT_011d9174, unkaf0);
    unk50->SetTraitAndReset(DAT_011d9174, 1.0f);
    unk50->FUN_00715c60(DAT_011d9174, DAT_011dea3c->GetField618()->FUN_005ae380());
    char labelText[260];
    FUN_00406d00(labelText, 260, DAT_01012058, DAT_011d3d48.FUN_00403df0(), DAT_011d2e68.FUN_00403df0());
    unk58->FUN_00a01350(4036, labelText, true);
    unk58->FUN_00a012d0(4001, unk58->FUN_00a011b0(4001) - 150.0);
    unk58->FUN_00a07530(1);
    if (!FUN_004b71d0())
        unk58->FUN_00a01350(TraitNameToID(DAT_01071358), DAT_010633a0, true);
    unk5c->FUN_00a012d0(4001, unk5c->FUN_00a011b0(4001) - 150.0);
    unk5c->FUN_00a07530(1);
    unk30->FUN_00700320(4003, false);
    unk34->FUN_00700320(4003, true);
    unk38->FUN_00700320(4003, false);
    unk3c->FUN_00700320(4003, false);
    unkd8->FUN_00a01350(4036, DAT_011d2e68.FUN_00403df0(), true);
    unkdc->FUN_00a01350(4036, DAT_011d2f70.FUN_00403df0(), true);
    unk5c->FUN_00a01350(4036, DAT_011d2160.FUN_00403df0(), true);
    unkcc->FUN_00a01350(4036, DAT_011d2ec8.FUN_00403df0(), true);
    unk60->FUN_00a01350(4036, DAT_011d3ea4.FUN_00403df0(), true);
    unk64->FUN_00a01350(4036, DAT_011d354c.FUN_00403df0(), true);
    unk68->FUN_00a01350(4036, DAT_011d2784.FUN_00403df0(), true);
    unkcc->FUN_00700320(4003, false);
    unkcc->FUN_00a07530(4);
    UpdateControls();
}
}

struct TileNode
{

    TileNode* FUN_00a03da0(const char*);

    double FUN_00a011b0(unsigned int, int);

    void FUN_00a012d0(unsigned int, float);

    void FUN_00a07530(unsigned int);

    void SetTraitAndReset(int, float);

    void FUN_00715c60(int, unsigned int);

    void FUN_00a01350(int, unsigned int, int);

    void FUN_00700320(int, int);
};

struct Resource
{

    unsigned int m000, m004, m008;

    ~Resource();

    void Play();
};

struct GlobalString
{
    unsigned int FUN_00403df0();
};

struct CaravanState
{

    unsigned int GetFieldAtOffset61C();

    unsigned int GetField620();

    unsigned int GetRegionDataManager();

    unsigned int GetRegionDataManager(unsigned int);

    unsigned int FUN_00740960();

    void FUN_00740e70(unsigned int);

    void SetField624(unsigned int);

    unsigned int GetMember62C();

    void FUN_00740ef0(unsigned int);

    void FUN_00740e90(unsigned int);

    void SetField628(unsigned int);
};

extern int DAT_011d9174;

extern const double DAT_0106c948;

extern const char str_010716a4[];

extern const char str_01071694[];

extern const char UNK_01071684[];

extern const char UNK_010714ec[];

extern GlobalString DAT_011d4b58;

extern GlobalString DAT_011d1e6c;

extern GlobalString DAT_011d309c;

extern GlobalString DAT_011d4f3c;

extern GlobalString DAT_011d2ab4;

extern GlobalString DAT_011d3360;

void __cdecl FUN_004d5c60(int);

struct SoundManager
{
    Resource FUN_00ad7550(const char*, int, int);
};
SoundManager* __cdecl FUN_00453a70();

void __cdecl FUN_00406d00(char*, int, const char*, ...);

struct MenuView
{

    unsigned int m000;

    unsigned int m004;

    unsigned int m008;

    unsigned int m00c;

    unsigned int m010;

    unsigned int m014;

    unsigned int m018;

    unsigned int m01c;

    unsigned int m020;

    unsigned int m024;

    unsigned int m028;

    unsigned int m02c;

    TileNode* m030;

    TileNode* m034;

    TileNode* m038;

    TileNode* m03c;

    unsigned int m040;

    unsigned int m044;

    unsigned int m048;

    unsigned int m04c;

    unsigned int m050;

    unsigned int m054;

    unsigned int m058;

    unsigned int m05c;

    unsigned int m060;

    unsigned int m064;

    unsigned int m068;

    unsigned int m06c;

    unsigned int m070;

    unsigned int m074;

    unsigned int m078;

    unsigned int m07c;

    unsigned int m080;

    unsigned int m084;

    unsigned int m088;

    unsigned int m08c;

    unsigned int m090;

    unsigned int m094;

    unsigned int m098;

    unsigned int m09c;

    unsigned int m0a0;

    unsigned int m0a4;

    unsigned int m0a8;

    TileNode* m0ac;

    TileNode* m0b0;

    TileNode* m0b4;

    TileNode* m0b8;

    TileNode* m0bc;

    unsigned int m0c0;

    unsigned int m0c4;

    unsigned int m0c8;

    unsigned int m0cc;

    unsigned int m0d0;

    unsigned int m0d4;

    unsigned int m0d8;

    unsigned int m0dc;

    unsigned int m0e0;

    unsigned int m0e4;

    unsigned int m0e8;

    TileNode* m0ec;

    TileNode* m0f0;

    TileNode* m0f4;

    TileNode* m0f8;

    unsigned int m0fc;

    unsigned int m100;

    unsigned int m104;

    unsigned int m108;

    unsigned int m10c;

    unsigned int m110;

    unsigned int m114;

    unsigned int m118;

    unsigned int m11c;

    unsigned int m120;

    unsigned int m124;

    unsigned int m128;

    unsigned int m12c;

    unsigned int m130;

    unsigned int m134;

    unsigned int m138;

    unsigned int m13c;

    unsigned int m140;

    unsigned int m144;

    unsigned int m148;

    unsigned int m14c;

    unsigned int m150;

    unsigned int m154;

    unsigned int m158;

    unsigned int m15c;

    unsigned int m160;

    unsigned int m164;

    unsigned int m168;

    unsigned int m16c;

    unsigned int m170;

    unsigned int m174;

    unsigned int m178;

    unsigned int m17c;

    unsigned int m180;

    unsigned int m184;

    unsigned int m188;

    unsigned int m18c;

    unsigned int m190;

    unsigned int m194;

    unsigned int m198;

    unsigned int m19c;

    unsigned int m1a0;

    unsigned int m1a4;

    unsigned int m1a8;

    unsigned int m1ac;

    unsigned int m1b0;

    unsigned int m1b4;

    unsigned int m1b8;

    unsigned int m1bc;

    unsigned int m1c0;

    unsigned int m1c4;

    unsigned int m1c8;

    unsigned int m1cc;

    unsigned int m1d0;

    unsigned int m1d4;

    unsigned int m1d8;

    unsigned int m1dc;

    unsigned int m1e0;

    unsigned int m1e4;

    unsigned int m1e8;

    unsigned int m1ec;

    unsigned int m1f0;

    unsigned int m1f4;

    unsigned int m1f8;

    unsigned int m1fc;

    unsigned int m200;

    unsigned int m204;

    unsigned int m208;

    unsigned int m20c;

    unsigned int m210;

    unsigned int m214;

    unsigned int m218;

    unsigned int m21c;

    unsigned int m220;

    unsigned int m224;

    unsigned int m228;

    unsigned int m22c;

    unsigned int m230;

    unsigned int m234;

    unsigned int m238;

    unsigned int m23c;

    unsigned int m240;

    unsigned int m244;

    unsigned int m248;

    unsigned int m24c;

    unsigned int m250;

    unsigned int m254;

    unsigned int m258;

    unsigned int m25c;

    unsigned int m260;

    unsigned int m264;

    unsigned int m268;

    unsigned int m26c;

    unsigned int m270;

    unsigned int m274;

    unsigned int m278;

    unsigned int m27c;

    unsigned int m280;

    unsigned int m284;

    unsigned int m288;

    unsigned int m28c;

    unsigned int m290;

    unsigned int m294;

    unsigned int m298;

    unsigned int m29c;

    unsigned int m2a0;

    unsigned int m2a4;

    unsigned int m2a8;

    unsigned int m2ac;

    unsigned int m2b0;

    unsigned int m2b4;

    unsigned int m2b8;

    unsigned int m2bc;

    unsigned int m2c0;

    unsigned int m2c4;

    unsigned int m2c8;

    unsigned int m2cc;

    unsigned int m2d0;

    unsigned int m2d4;

    unsigned int m2d8;

    unsigned int m2dc;

    unsigned int m2e0;

    unsigned int m2e4;

    unsigned int m2e8;

    unsigned int m2ec;

    unsigned int m2f0;

    unsigned int m2f4;

    unsigned int m2f8;

    unsigned int m2fc;

    unsigned int m300;

    unsigned int m304;

    unsigned int m308;

    unsigned int m30c;

    unsigned int m310;

    unsigned int m314;

    unsigned int m318;

    unsigned int m31c;

    unsigned int m320;

    unsigned int m324;

    unsigned int m328;

    unsigned int m32c;

    unsigned int m330;

    unsigned int m334;

    unsigned int m338;

    unsigned int m33c;

    unsigned int m340;

    unsigned int m344;

    unsigned int m348;

    unsigned int m34c;

    unsigned int m350;

    unsigned int m354;

    unsigned int m358;

    unsigned int m35c;

    unsigned int m360;

    unsigned int m364;

    unsigned int m368;

    unsigned int m36c;

    unsigned int m370;

    unsigned int m374;

    unsigned int m378;

    unsigned int m37c;

    unsigned int m380;

    unsigned int m384;

    unsigned int m388;

    unsigned int m38c;

    unsigned int m390;

    unsigned int m394;

    unsigned int m398;

    unsigned int m39c;

    unsigned int m3a0;

    unsigned int m3a4;

    unsigned int m3a8;

    unsigned int m3ac;

    unsigned int m3b0;

    unsigned int m3b4;

    unsigned int m3b8;

    unsigned int m3bc;

    unsigned int m3c0;

    unsigned int m3c4;

    unsigned int m3c8;

    unsigned int m3cc;

    unsigned int m3d0;

    unsigned int m3d4;

    unsigned int m3d8;

    unsigned int m3dc;

    unsigned int m3e0;

    unsigned int m3e4;

    unsigned int m3e8;

    unsigned int m3ec;

    unsigned int m3f0;

    unsigned int m3f4;

    unsigned int m3f8;

    unsigned int m3fc;

    unsigned int m400;

    unsigned int m404;

    unsigned int m408;

    unsigned int m40c;

    unsigned int m410;

    unsigned int m414;

    unsigned int m418;

    unsigned int m41c;

    unsigned int m420;

    unsigned int m424;

    unsigned int m428;

    unsigned int m42c;

    unsigned int m430;

    unsigned int m434;

    unsigned int m438;

    unsigned int m43c;

    unsigned int m440;

    unsigned int m444;

    unsigned int m448;

    unsigned int m44c;

    unsigned int m450;

    unsigned int m454;

    unsigned int m458;

    unsigned int m45c;

    unsigned int m460;

    unsigned int m464;

    unsigned int m468;

    unsigned int m46c;

    unsigned int m470;

    unsigned int m474;

    unsigned int m478;

    unsigned int m47c;

    unsigned int m480;

    unsigned int m484;

    unsigned int m488;

    unsigned int m48c;

    unsigned int m490;

    unsigned int m494;

    unsigned int m498;

    unsigned int m49c;

    unsigned int m4a0;

    unsigned int m4a4;

    unsigned int m4a8;

    unsigned int m4ac;

    unsigned int m4b0;

    unsigned int m4b4;

    unsigned int m4b8;

    unsigned int m4bc;

    unsigned int m4c0;

    unsigned int m4c4;

    unsigned int m4c8;

    unsigned int m4cc;

    unsigned int m4d0;

    unsigned int m4d4;

    unsigned int m4d8;

    unsigned int m4dc;

    unsigned int m4e0;

    unsigned int m4e4;

    unsigned int m4e8;

    unsigned int m4ec;

    unsigned int m4f0;

    unsigned int m4f4;

    unsigned int m4f8;

    unsigned int m4fc;

    unsigned int m500;

    unsigned int m504;

    unsigned int m508;

    unsigned int m50c;

    unsigned int m510;

    unsigned int m514;

    unsigned int m518;

    unsigned int m51c;

    unsigned int m520;

    unsigned int m524;

    unsigned int m528;

    unsigned int m52c;

    unsigned int m530;

    unsigned int m534;

    unsigned int m538;

    unsigned int m53c;

    unsigned int m540;

    unsigned int m544;

    unsigned int m548;

    unsigned int m54c;

    unsigned int m550;

    unsigned int m554;

    unsigned int m558;

    unsigned int m55c;

    unsigned int m560;

    unsigned int m564;

    unsigned int m568;

    unsigned int m56c;

    unsigned int m570;

    unsigned int m574;

    unsigned int m578;

    unsigned int m57c;

    unsigned int m580;

    unsigned int m584;

    unsigned int m588;

    unsigned int m58c;

    unsigned int m590;

    unsigned int m594;

    unsigned int m598;

    unsigned int m59c;

    unsigned int m5a0;

    unsigned int m5a4;

    unsigned int m5a8;

    unsigned int m5ac;

    unsigned int m5b0;

    unsigned int m5b4;

    unsigned int m5b8;

    unsigned int m5bc;

    unsigned int m5c0;

    unsigned int m5c4;

    unsigned int m5c8;

    unsigned int m5cc;

    unsigned int m5d0;

    unsigned int m5d4;

    unsigned int m5d8;

    unsigned int m5dc;

    unsigned int m5e0;

    unsigned int m5e4;

    unsigned int m5e8;

    unsigned int m5ec;

    unsigned int m5f0;

    unsigned int m5f4;

    unsigned int m5f8;

    unsigned int m5fc;

    unsigned int m600;

    unsigned int m604;

    unsigned int m608;

    unsigned int m60c;

    unsigned int m610;

    unsigned int m614;

    unsigned int m618;

    unsigned int m61c;

    unsigned int m620;

    unsigned int m624;

    unsigned int m628;

    unsigned int m62c;

    unsigned int m630;

    unsigned int m634;

    unsigned int m638;

    unsigned int m63c;

    unsigned int m640;

    unsigned int m644;

    unsigned int m648;

    unsigned int m64c;

    unsigned int m650;

    unsigned int m654;

    unsigned int m658;

    unsigned int m65c;

    unsigned int m660;

    unsigned int m664;

    unsigned int m668;

    unsigned int m66c;

    unsigned int m670;

    unsigned int m674;

    unsigned int m678;

    unsigned int m67c;

    unsigned int m680;

    unsigned int m684;

    unsigned int m688;

    unsigned int m68c;

    unsigned int m690;

    unsigned int m694;

    unsigned int m698;

    unsigned int m69c;

    unsigned int m6a0;

    unsigned int m6a4;

    unsigned int m6a8;

    unsigned int m6ac;

    unsigned int m6b0;

    unsigned int m6b4;

    unsigned int m6b8;

    unsigned int m6bc;

    unsigned int m6c0;

    unsigned int m6c4;

    unsigned int m6c8;

    unsigned int m6cc;

    unsigned int m6d0;

    unsigned int m6d4;

    unsigned int m6d8;

    unsigned int m6dc;

    unsigned int m6e0;

    unsigned int m6e4;

    unsigned int m6e8;

    unsigned int m6ec;

    unsigned int m6f0;

    unsigned int m6f4;

    unsigned int m6f8;

    unsigned int m6fc;

    unsigned int m700;

    unsigned int m704;

    unsigned int m708;

    unsigned int m70c;

    unsigned int m710;

    unsigned int m714;

    unsigned int m718;

    unsigned int m71c;

    unsigned int m720;

    unsigned int m724;

    unsigned int m728;

    unsigned int m72c;

    unsigned int m730;

    unsigned int m734;

    unsigned int m738;

    unsigned int m73c;

    unsigned int m740;

    unsigned int m744;

    unsigned int m748;

    unsigned int m74c;

    unsigned int m750;

    unsigned int m754;

    unsigned int m758;

    unsigned int m75c;

    unsigned int m760;

    unsigned int m764;

    unsigned int m768;

    unsigned int m76c;

    unsigned int m770;

    unsigned int m774;

    unsigned int m778;

    unsigned int m77c;

    unsigned int m780;

    unsigned int m784;

    unsigned int m788;

    unsigned int m78c;

    unsigned int m790;

    unsigned int m794;

    unsigned int m798;

    unsigned int m79c;

    unsigned int m7a0;

    unsigned int m7a4;

    unsigned int m7a8;

    unsigned int m7ac;

    unsigned int m7b0;

    unsigned int m7b4;

    unsigned int m7b8;

    unsigned int m7bc;

    unsigned int m7c0;

    unsigned int m7c4;

    unsigned int m7c8;

    unsigned int m7cc;

    unsigned int m7d0;

    unsigned int m7d4;

    unsigned int m7d8;

    unsigned int m7dc;

    unsigned int m7e0;

    unsigned int m7e4;

    unsigned int m7e8;

    unsigned int m7ec;

    unsigned int m7f0;

    unsigned int m7f4;

    unsigned int m7f8;

    unsigned int m7fc;

    unsigned int m800;

    unsigned int m804;

    unsigned int m808;

    unsigned int m80c;

    unsigned int m810;

    unsigned int m814;

    unsigned int m818;

    unsigned int m81c;

    unsigned int m820;

    unsigned int m824;

    unsigned int m828;

    unsigned int m82c;

    unsigned int m830;

    unsigned int m834;

    unsigned int m838;

    unsigned int m83c;

    unsigned int m840;

    unsigned int m844;

    unsigned int m848;

    unsigned int m84c;

    unsigned int m850;

    unsigned int m854;

    unsigned int m858;

    unsigned int m85c;

    unsigned int m860;

    unsigned int m864;

    unsigned int m868;

    unsigned int m86c;

    unsigned int m870;

    unsigned int m874;

    unsigned int m878;

    unsigned int m87c;

    unsigned int m880;

    unsigned int m884;

    unsigned int m888;

    unsigned int m88c;

    unsigned int m890;

    unsigned int m894;

    unsigned int m898;

    unsigned int m89c;

    unsigned int m8a0;

    unsigned int m8a4;

    unsigned int m8a8;

    unsigned int m8ac;

    unsigned int m8b0;

    unsigned int m8b4;

    unsigned int m8b8;

    unsigned int m8bc;

    unsigned int m8c0;

    unsigned int m8c4;

    unsigned int m8c8;

    unsigned int m8cc;

    unsigned int m8d0;

    unsigned int m8d4;

    unsigned int m8d8;

    unsigned int m8dc;

    unsigned int m8e0;

    unsigned int m8e4;

    unsigned int m8e8;

    unsigned int m8ec;

    unsigned int m8f0;

    unsigned int m8f4;

    unsigned int m8f8;

    unsigned int m8fc;

    unsigned int m900;

    unsigned int m904;

    unsigned int m908;

    unsigned int m90c;

    unsigned int m910;

    unsigned int m914;

    unsigned int m918;

    unsigned int m91c;

    unsigned int m920;

    unsigned int m924;

    unsigned int m928;

    unsigned int m92c;

    unsigned int m930;

    unsigned int m934;

    unsigned int m938;

    unsigned int m93c;

    unsigned int m940;

    unsigned int m944;

    unsigned int m948;

    unsigned int m94c;

    unsigned int m950;

    unsigned int m954;

    unsigned int m958;

    unsigned int m95c;

    unsigned int m960;

    unsigned int m964;

    unsigned int m968;

    unsigned int m96c;

    unsigned int m970;

    unsigned int m974;

    unsigned int m978;

    unsigned int m97c;

    unsigned int m980;

    unsigned int m984;

    unsigned int m988;

    unsigned int m98c;

    unsigned int m990;

    unsigned int m994;

    unsigned int m998;

    unsigned int m99c;

    unsigned int m9a0;

    unsigned int m9a4;

    unsigned int m9a8;

    unsigned int m9ac;

    unsigned int m9b0;

    unsigned int m9b4;

    unsigned int m9b8;

    unsigned int m9bc;

    unsigned int m9c0;

    unsigned int m9c4;

    unsigned int m9c8;

    unsigned int m9cc;

    unsigned int m9d0;

    unsigned int m9d4;

    unsigned int m9d8;

    unsigned int m9dc;

    unsigned int m9e0;

    unsigned int m9e4;

    unsigned int m9e8;

    unsigned int m9ec;

    unsigned int m9f0;

    unsigned int m9f4;

    unsigned int m9f8;

    unsigned int m9fc;

    unsigned int ma00;

    unsigned int ma04;

    unsigned int ma08;

    unsigned int ma0c;

    unsigned int ma10;

    unsigned int ma14;

    unsigned int ma18;

    unsigned int ma1c;

    unsigned int ma20;

    unsigned int ma24;

    unsigned int ma28;

    unsigned int ma2c;

    unsigned int ma30;

    unsigned int ma34;

    unsigned int ma38;

    unsigned int ma3c;

    unsigned int ma40;

    unsigned int ma44;

    unsigned int ma48;

    unsigned int ma4c;

    unsigned int ma50;

    unsigned int ma54;

    unsigned int ma58;

    unsigned int ma5c;

    unsigned int ma60;

    unsigned int ma64;

    unsigned int ma68;

    unsigned int ma6c;

    unsigned int ma70;

    unsigned int ma74;

    unsigned int ma78;

    unsigned int ma7c;

    unsigned int ma80;

    unsigned int ma84;

    unsigned int ma88;

    unsigned int ma8c;

    unsigned int ma90;

    unsigned int ma94;

    unsigned int ma98;

    unsigned int ma9c;

    unsigned int maa0;

    unsigned int maa4;

    unsigned int maa8;

    unsigned int maac;

    unsigned int mab0;

    unsigned int mab4;

    unsigned int mab8;

    unsigned int mabc;

    unsigned int mac0;

    unsigned int mac4;

    unsigned int mac8;

    unsigned int macc;

    unsigned int mad0;

    unsigned int mad4;

    unsigned int mad8;

    unsigned int madc;

    unsigned int mae0;

    unsigned int mae4;

    unsigned int mae8;

    bool FUN_00740f10(unsigned int);

    void TransferBarterItems(unsigned int);

    void UpdateCaravanMenu();
};

// @fnv 0x00740980
void MenuView::UpdateCaravanMenu()

{

    m02c = 3;

    if (FUN_00740f10(0x400))
    {

        ((CaravanState*)DAT_011dea3c)->FUN_00740e70(((CaravanState*)DAT_011dea3c)->GetFieldAtOffset61C() + mae8);

        ((CaravanState*)DAT_011dea3c)->SetField624(((CaravanState*)DAT_011dea3c)->GetRegionDataManager() + 1);

        if (mae8 > ((CaravanState*)DAT_011dea3c)->GetMember62C())

            ((CaravanState*)DAT_011dea3c)->FUN_00740ef0(mae8);

        FUN_004d5c60(0x25);

        FUN_00453a70()->FUN_00ad7550(str_010716a4, 0x121, 0).Play();
    }
    else
    {

        ((CaravanState*)DAT_011dea3c)->FUN_00740e90(((CaravanState*)DAT_011dea3c)->GetField620() + mae8);

        ((CaravanState*)DAT_011dea3c)->SetField628(((CaravanState*)DAT_011dea3c)->FUN_00740960() + 1);

        FUN_004d5c60(0x26);

        FUN_00453a70()->FUN_00ad7550(str_01071694, 0x121, 0).Play();
    }

    char buffer[0x104];
    {
        TileNode* pGainTile = m03c->FUN_00a03da0(UNK_01071684);

        if (pGainTile != 0)
        {

            pGainTile->FUN_00a012d0(0xfb1, (float)(pGainTile->FUN_00a011b0(0xfb1, 1) + DAT_0106c948));

            pGainTile->FUN_00a07530(0x10);
        }
    }

    FUN_00406d00(buffer, 0x104, UNK_010714ec, ((CaravanState*)DAT_011dea3c)->GetRegionDataManager(),
                 ((CaravanState*)DAT_011dea3c)->FUN_00740960());

    m0ac->SetTraitAndReset(DAT_011d9174, 1.0f);

    m0ac->FUN_00715c60(DAT_011d9174, ((CaravanState*)DAT_011dea3c)->GetFieldAtOffset61C());

    m0b0->SetTraitAndReset(DAT_011d9174, 1.0f);

    m0b0->FUN_00715c60(DAT_011d9174, ((CaravanState*)DAT_011dea3c)->GetField620());

    m0b4->SetTraitAndReset(DAT_011d9174, 1.0f);

    m0b4->FUN_00a01350(DAT_011d9174, (unsigned int)buffer, 1);

    m0b8->SetTraitAndReset(DAT_011d9174, 1.0f);

    m0b8->FUN_00715c60(DAT_011d9174, ((CaravanState*)DAT_011dea3c)->GetMember62C());

    m0bc->FUN_00a01350(0xfc4, FUN_00740f10(0x400) ? DAT_011d4b58.FUN_00403df0() : DAT_011d1e6c.FUN_00403df0(), 1);

    m030->FUN_00700320(0xfa3, 0);

    m034->FUN_00700320(0xfa3, 0);

    m038->FUN_00700320(0xfa3, 0);

    m03c->FUN_00700320(0xfa3, 1);

    m0ec->FUN_00a01350(0xfc4, DAT_011d309c.FUN_00403df0(), 1);

    m0f0->FUN_00a01350(0xfc4, DAT_011d4f3c.FUN_00403df0(), 1);

    m0f4->FUN_00a01350(0xfc4, DAT_011d2ab4.FUN_00403df0(), 1);

    m0f8->FUN_00a01350(0xfc4, DAT_011d3360.FUN_00403df0(), 1);

    TransferBarterItems(FUN_00740f10(0x400));
}

class TESForm
{
  public:
    virtual void f00();
};
class BGSMessage : public TESForm
{
};
extern char DAT_01018dec[];
extern char DAT_01025cc4[];
extern char DAT_01049638[];
extern char DAT_01070250[];
extern char DAT_010716b8[];
extern char DAT_0107170c[];
extern char DAT_01183028[];
extern char DAT_01186130[];
struct IFace
{
    virtual ~IFace();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual int V13();
};

struct Obj6c
{
    int FUN_00a012d0(int id, float v, int z);
    static int TraitNameToID(const char* s);
};

struct Obj917c
{
    virtual ~Obj917c();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual int V13();

    char* m_04;
    unsigned int unk_008;
    unsigned int unk_00c;
    unsigned int unk_010;
    unsigned int unk_014;
    unsigned int unk_018;
    unsigned int unk_01c;
    unsigned int unk_020;
    unsigned int unk_024;
    unsigned int unk_028;
    unsigned int unk_02c;
    unsigned int unk_030;
    unsigned int unk_034;
    unsigned int unk_038;
    unsigned int unk_03c;
    unsigned int unk_040;
    unsigned int unk_044;
    unsigned int unk_048;
    unsigned int unk_04c;
    unsigned int unk_050;
    unsigned int unk_054;
    unsigned int unk_058;
    unsigned int unk_05c;
    unsigned int unk_060;
    unsigned int unk_064;
    unsigned int unk_068;
    Obj6c* m_6c;
    unsigned int unk_070;
    unsigned int unk_074;
    unsigned int unk_078;
    unsigned int unk_07c;
    unsigned int unk_080;
    unsigned int unk_084;
    unsigned int unk_088;
    unsigned int unk_08c;
    unsigned int unk_090;
    unsigned int unk_094;
    unsigned int unk_098;
    unsigned int unk_09c;
    unsigned int unk_0a0;
    unsigned int unk_0a4;
    unsigned int unk_0a8;
    unsigned int unk_0ac;
    unsigned int unk_0b0;
    unsigned int unk_0b4;
    unsigned int unk_0b8;
    unsigned int unk_0bc;
    unsigned int unk_0c0;
    unsigned int unk_0c4;
    unsigned int unk_0c8;
    unsigned int unk_0cc;
    unsigned int unk_0d0;
    unsigned int unk_0d4;
    unsigned int unk_0d8;
    unsigned int unk_0dc;
    unsigned int unk_0e0;
    unsigned int unk_0e4;
    unsigned int unk_0e8;
    unsigned int unk_0ec;
    unsigned int unk_0f0;
    unsigned int unk_0f4;
    unsigned int unk_0f8;
    unsigned int unk_0fc;
    int m_100;
    int m_104;
    int m_108;
    float m_10c;
    unsigned int unk_110;
    unsigned int unk_114;
    unsigned int unk_118;
    unsigned int unk_11c;
    unsigned int unk_120;
    unsigned int unk_124;
    unsigned int unk_128;
    unsigned int unk_12c;
    unsigned int unk_130;
    unsigned int unk_134;
    unsigned int unk_138;
    unsigned int unk_13c;
    unsigned int unk_140;
    unsigned int unk_144;
    unsigned int unk_148;
    unsigned int unk_14c;
    unsigned int unk_150;
    unsigned int unk_154;
    unsigned int unk_158;
    unsigned int unk_15c;
    unsigned int unk_160;
    unsigned int unk_164;
    unsigned int unk_168;
    unsigned int unk_16c;
    unsigned int unk_170;
    unsigned int unk_174;
    unsigned int unk_178;
    unsigned int unk_17c;
    unsigned int unk_180;
    unsigned int unk_184;
    unsigned int unk_188;
    unsigned int unk_18c;
    unsigned int unk_190;
    unsigned int unk_194;
    unsigned int unk_198;
    unsigned int unk_19c;
    unsigned int unk_1a0;
    unsigned int unk_1a4;
    unsigned int unk_1a8;
    unsigned int unk_1ac;
    unsigned int unk_1b0;
    unsigned int unk_1b4;
    unsigned int unk_1b8;
    unsigned int unk_1bc;
    unsigned int unk_1c0;
    unsigned int unk_1c4;
    unsigned int unk_1c8;
    unsigned int unk_1cc;
    unsigned int unk_1d0;
    unsigned int unk_1d4;
    unsigned int unk_1d8;
    unsigned int unk_1dc;
    unsigned int unk_1e0;
    unsigned int unk_1e4;
    unsigned int unk_1e8;
    unsigned int unk_1ec;
    unsigned int unk_1f0;
    unsigned int unk_1f4;
    unsigned int unk_1f8;
    unsigned int unk_1fc;
    unsigned int unk_200;
    unsigned int unk_204;
    unsigned int unk_208;
    unsigned int unk_20c;
    unsigned int unk_210;
    unsigned int unk_214;
    unsigned int unk_218;
    unsigned int unk_21c;
    unsigned int unk_220;
    unsigned int unk_224;
    unsigned int unk_228;
    unsigned int unk_22c;
    unsigned int unk_230;
    unsigned int unk_234;
    unsigned int unk_238;
    unsigned int unk_23c;
    unsigned int unk_240;
    unsigned int unk_244;
    unsigned int unk_248;
    unsigned int unk_24c;
    unsigned int unk_250;
    unsigned int unk_254;
    unsigned int unk_258;
    unsigned int unk_25c;
    unsigned int unk_260;
    unsigned int unk_264;
    unsigned int unk_268;
    unsigned int unk_26c;
    unsigned int unk_270;
    unsigned int unk_274;
    unsigned int unk_278;
    unsigned int unk_27c;
    unsigned int unk_280;
    unsigned int unk_284;
    unsigned int unk_288;
    unsigned int unk_28c;
    unsigned int unk_290;
    unsigned int unk_294;
    unsigned int unk_298;
    unsigned int unk_29c;
    unsigned int unk_2a0;
    unsigned int unk_2a4;
    unsigned int unk_2a8;
    unsigned int unk_2ac;
    unsigned int unk_2b0;
    unsigned int unk_2b4;
    unsigned int unk_2b8;
    unsigned int unk_2bc;
    unsigned int unk_2c0;
    unsigned int unk_2c4;
    unsigned int unk_2c8;
    unsigned int unk_2cc;
    unsigned int unk_2d0;
    unsigned int unk_2d4;
    unsigned int unk_2d8;
    unsigned int unk_2dc;
    unsigned int unk_2e0;
    unsigned int unk_2e4;
    unsigned int unk_2e8;
    unsigned int unk_2ec;
    unsigned int unk_2f0;
    unsigned int unk_2f4;
    unsigned int unk_2f8;
    unsigned int unk_2fc;
    unsigned int unk_300;
    unsigned int unk_304;
    unsigned int unk_308;
    unsigned int unk_30c;
    unsigned int unk_310;
    unsigned int unk_314;
    unsigned int unk_318;
    unsigned int unk_31c;
    unsigned int unk_320;
    unsigned int unk_324;
    unsigned int unk_328;
    unsigned int unk_32c;
    unsigned int unk_330;
    unsigned int unk_334;
    unsigned int unk_338;
    unsigned int unk_33c;
    unsigned int unk_340;
    unsigned int unk_344;
    unsigned int unk_348;
    unsigned int unk_34c;
    unsigned int unk_350;
    unsigned int unk_354;
    unsigned int unk_358;
    unsigned int unk_35c;
    unsigned int unk_360;
    unsigned int unk_364;
    unsigned int unk_368;
    unsigned int unk_36c;
    unsigned int unk_370;
    unsigned int unk_374;
    unsigned int unk_378;
    unsigned int unk_37c;
    unsigned int unk_380;
    unsigned int unk_384;
    unsigned int unk_388;
    unsigned int unk_38c;
    unsigned int unk_390;
    unsigned int unk_394;
    unsigned int unk_398;
    unsigned int unk_39c;
    unsigned int unk_3a0;
    unsigned int unk_3a4;
    unsigned int unk_3a8;
    unsigned int unk_3ac;
    unsigned int unk_3b0;
    unsigned int unk_3b4;
    unsigned int unk_3b8;
    unsigned int unk_3bc;
    unsigned int unk_3c0;
    unsigned int unk_3c4;
    unsigned int unk_3c8;
    unsigned int unk_3cc;
    unsigned int unk_3d0;
    unsigned int unk_3d4;
    unsigned int unk_3d8;
    unsigned int unk_3dc;
    unsigned int unk_3e0;
    unsigned int unk_3e4;
    unsigned int unk_3e8;
    unsigned int unk_3ec;
    unsigned int unk_3f0;
    unsigned int unk_3f4;
    unsigned int unk_3f8;
    unsigned int unk_3fc;
    unsigned int unk_400;
    unsigned int unk_404;
    unsigned int unk_408;
    unsigned int unk_40c;
    unsigned int unk_410;
    unsigned int unk_414;
    unsigned int unk_418;
    unsigned int unk_41c;
    unsigned int unk_420;
    unsigned int unk_424;
    unsigned int unk_428;
    unsigned int unk_42c;
    unsigned int unk_430;
    unsigned int unk_434;
    unsigned int unk_438;
    unsigned int unk_43c;
    unsigned int unk_440;
    unsigned int unk_444;
    unsigned int unk_448;
    unsigned int unk_44c;
    unsigned int unk_450;
    unsigned int unk_454;
    unsigned int unk_458;
    unsigned int unk_45c;
    unsigned int unk_460;
    unsigned int unk_464;
    unsigned int unk_468;
    unsigned int unk_46c;
    unsigned int unk_470;
    unsigned int unk_474;
    unsigned int unk_478;
    unsigned int unk_47c;
    unsigned int unk_480;
    unsigned int unk_484;
    unsigned int unk_488;
    unsigned int unk_48c;
    unsigned int unk_490;
    unsigned int unk_494;
    unsigned int unk_498;
    unsigned int unk_49c;
    unsigned int unk_4a0;
    unsigned int unk_4a4;
    unsigned int unk_4a8;
    unsigned int unk_4ac;
    unsigned int unk_4b0;
    unsigned int unk_4b4;
    unsigned int unk_4b8;
    unsigned int unk_4bc;
    unsigned int unk_4c0;
    unsigned int unk_4c4;
    unsigned int unk_4c8;
    unsigned int unk_4cc;
    unsigned int unk_4d0;
    unsigned int unk_4d4;
    unsigned int unk_4d8;
    unsigned int unk_4dc;
    unsigned int unk_4e0;
    unsigned int unk_4e4;
    unsigned int unk_4e8;
    unsigned int unk_4ec;
    unsigned int unk_4f0;
    unsigned int unk_4f4;
    unsigned int unk_4f8;
    unsigned int unk_4fc;
    unsigned int unk_500;
    unsigned int unk_504;
    unsigned int unk_508;
    unsigned int unk_50c;
    unsigned int unk_510;
    unsigned int unk_514;
    unsigned int unk_518;
    unsigned int unk_51c;
    unsigned int unk_520;
    unsigned int unk_524;
    unsigned int unk_528;
    unsigned int unk_52c;
    unsigned int unk_530;
    unsigned int unk_534;
    unsigned int unk_538;
    unsigned int unk_53c;
    unsigned int unk_540;
    unsigned int unk_544;
    unsigned int unk_548;
    unsigned int unk_54c;
    unsigned int unk_550;
    unsigned int unk_554;
    unsigned int unk_558;
    unsigned int unk_55c;
    unsigned int unk_560;
    unsigned int unk_564;
    unsigned int unk_568;
    unsigned int unk_56c;
    unsigned int unk_570;
    unsigned int unk_574;
    unsigned int unk_578;
    unsigned int unk_57c;
    unsigned int unk_580;
    unsigned int unk_584;
    unsigned int unk_588;
    unsigned int unk_58c;
    unsigned int unk_590;
    unsigned int unk_594;
    unsigned int unk_598;
    unsigned int unk_59c;
    unsigned int unk_5a0;
    unsigned int unk_5a4;
    unsigned int unk_5a8;
    unsigned int unk_5ac;
    unsigned int unk_5b0;
    unsigned int unk_5b4;
    unsigned int unk_5b8;
    unsigned int unk_5bc;
    unsigned int unk_5c0;
    unsigned int unk_5c4;
    unsigned int unk_5c8;
    unsigned int unk_5cc;
    unsigned int unk_5d0;
    unsigned int unk_5d4;
    unsigned int unk_5d8;
    unsigned int unk_5dc;
    unsigned int unk_5e0;
    unsigned int unk_5e4;
    unsigned int unk_5e8;
    unsigned int unk_5ec;
    unsigned int unk_5f0;
    unsigned int unk_5f4;
    unsigned int unk_5f8;
    unsigned int unk_5fc;
    unsigned int unk_600;
    unsigned int unk_604;
    unsigned int unk_608;
    unsigned int unk_60c;
    unsigned int unk_610;
    unsigned int unk_614;
    unsigned int unk_618;
    unsigned int unk_61c;
    unsigned int unk_620;
    unsigned int unk_624;
    unsigned int unk_628;
    unsigned int unk_62c;
    unsigned int unk_630;
    unsigned int unk_634;
    unsigned int unk_638;
    unsigned int unk_63c;
    unsigned int unk_640;
    unsigned int unk_644;
    unsigned int unk_648;
    unsigned int unk_64c;
    unsigned int unk_650;
    unsigned int unk_654;
    unsigned int unk_658;
    unsigned int unk_65c;
    unsigned int unk_660;
    unsigned int unk_664;
    unsigned int unk_668;
    unsigned int unk_66c;
    unsigned int unk_670;
    unsigned int unk_674;
    unsigned int unk_678;
    unsigned int unk_67c;
    unsigned int unk_680;
    unsigned int unk_684;
    unsigned int unk_688;
    unsigned int unk_68c;
    unsigned int unk_690;
    unsigned int unk_694;
    unsigned int unk_698;
    unsigned int unk_69c;
    unsigned int unk_6a0;
    unsigned int unk_6a4;
    unsigned int unk_6a8;
    unsigned int unk_6ac;
    unsigned int unk_6b0;
    unsigned int unk_6b4;
    unsigned int unk_6b8;
    unsigned int unk_6bc;
    unsigned int unk_6c0;
    unsigned int unk_6c4;
    unsigned int unk_6c8;
    unsigned int unk_6cc;
    unsigned int unk_6d0;
    unsigned int unk_6d4;
    unsigned int unk_6d8;
    unsigned int unk_6dc;
    unsigned int unk_6e0;
    unsigned int unk_6e4;
    unsigned int unk_6e8;
    unsigned int unk_6ec;
    unsigned int unk_6f0;
    unsigned int unk_6f4;
    unsigned int unk_6f8;
    unsigned int unk_6fc;
    unsigned int unk_700;
    unsigned int unk_704;
    unsigned int unk_708;
    unsigned int unk_70c;
    unsigned int unk_710;
    unsigned int unk_714;
    unsigned int unk_718;
    unsigned int unk_71c;
    unsigned int unk_720;
    unsigned int unk_724;
    unsigned int unk_728;
    unsigned int unk_72c;
    unsigned int unk_730;
    unsigned int unk_734;
    unsigned int unk_738;
    unsigned int unk_73c;
    unsigned int unk_740;
    unsigned int unk_744;
    unsigned int unk_748;
    unsigned int unk_74c;
    unsigned int unk_750;
    unsigned int unk_754;
    unsigned int unk_758;
    unsigned int unk_75c;
    unsigned int unk_760;
    unsigned int unk_764;
    unsigned int unk_768;
    unsigned int unk_76c;
    unsigned int unk_770;
    unsigned int unk_774;
    unsigned int unk_778;
    unsigned int unk_77c;
    unsigned int unk_780;
    unsigned int unk_784;
    unsigned int unk_788;
    unsigned int unk_78c;
    unsigned int unk_790;
    unsigned int unk_794;
    unsigned int unk_798;
    unsigned int unk_79c;
    unsigned int unk_7a0;
    unsigned int unk_7a4;
    unsigned int unk_7a8;
    unsigned int unk_7ac;
    unsigned int unk_7b0;
    unsigned int unk_7b4;
    unsigned int unk_7b8;
    unsigned int unk_7bc;
    unsigned int unk_7c0;
    unsigned int unk_7c4;
    unsigned int unk_7c8;
    unsigned int unk_7cc;
    unsigned int unk_7d0;
    unsigned int unk_7d4;
    unsigned int unk_7d8;
    unsigned int unk_7dc;
    unsigned int unk_7e0;
    unsigned int unk_7e4;
    unsigned int unk_7e8;
    unsigned int unk_7ec;
    unsigned int unk_7f0;
    unsigned int unk_7f4;
    unsigned int unk_7f8;
    unsigned int unk_7fc;
    unsigned int unk_800;
    unsigned int unk_804;
    unsigned int unk_808;
    unsigned int unk_80c;
    unsigned int unk_810;
    unsigned int unk_814;
    unsigned int unk_818;
    unsigned int unk_81c;
    unsigned int unk_820;
    unsigned int unk_824;
    unsigned int unk_828;
    unsigned int unk_82c;
    unsigned int unk_830;
    unsigned int unk_834;
    unsigned int unk_838;
    unsigned int unk_83c;
    unsigned int unk_840;
    unsigned int unk_844;
    unsigned int unk_848;
    unsigned int unk_84c;
    unsigned int unk_850;
    unsigned int unk_854;
    unsigned int unk_858;
    unsigned int unk_85c;
    unsigned int unk_860;
    unsigned int unk_864;
    unsigned int unk_868;
    unsigned int unk_86c;
    unsigned int unk_870;
    unsigned int unk_874;
    unsigned int unk_878;
    unsigned int unk_87c;
    unsigned int unk_880;
    unsigned int unk_884;
    unsigned int unk_888;
    unsigned int unk_88c;
    unsigned int unk_890;
    unsigned int unk_894;
    unsigned int unk_898;
    unsigned int unk_89c;
    unsigned int unk_8a0;
    unsigned int unk_8a4;
    unsigned int unk_8a8;
    unsigned int unk_8ac;
    unsigned int unk_8b0;
    unsigned int unk_8b4;
    unsigned int unk_8b8;
    unsigned int unk_8bc;
    unsigned int unk_8c0;
    unsigned int unk_8c4;
    unsigned int unk_8c8;
    unsigned int unk_8cc;
    unsigned int unk_8d0;
    unsigned int unk_8d4;
    unsigned int unk_8d8;
    unsigned int unk_8dc;
    unsigned int unk_8e0;
    unsigned int unk_8e4;
    unsigned int unk_8e8;
    unsigned int unk_8ec;
    unsigned int unk_8f0;
    unsigned int unk_8f4;
    unsigned int unk_8f8;
    unsigned int unk_8fc;
    unsigned int unk_900;
    unsigned int unk_904;
    unsigned int unk_908;
    unsigned int unk_90c;
    unsigned int unk_910;
    unsigned int unk_914;
    unsigned int unk_918;
    unsigned int unk_91c;
    unsigned int unk_920;
    unsigned int unk_924;
    unsigned int unk_928;
    unsigned int unk_92c;
    unsigned int unk_930;
    unsigned int unk_934;
    unsigned int unk_938;
    unsigned int unk_93c;
    unsigned int unk_940;
    unsigned int unk_944;
    unsigned int unk_948;
    unsigned int unk_94c;
    unsigned int unk_950;
    unsigned int unk_954;
    unsigned int unk_958;
    unsigned int unk_95c;
    unsigned int unk_960;
    unsigned int unk_964;
    unsigned int unk_968;
    unsigned int unk_96c;
    unsigned int unk_970;
    unsigned int unk_974;
    unsigned int unk_978;
    unsigned int unk_97c;
    unsigned int unk_980;
    unsigned int unk_984;
    unsigned int unk_988;
    unsigned int unk_98c;
    unsigned int unk_990;
    unsigned int unk_994;
    unsigned int unk_998;
    unsigned int unk_99c;
    unsigned int unk_9a0;
    unsigned int unk_9a4;
    unsigned int unk_9a8;
    unsigned int unk_9ac;
    unsigned int unk_9b0;
    unsigned int unk_9b4;
    unsigned int unk_9b8;
    unsigned int unk_9bc;
    unsigned int unk_9c0;
    unsigned int unk_9c4;
    unsigned int unk_9c8;
    unsigned int unk_9cc;
    unsigned int unk_9d0;
    unsigned int unk_9d4;
    unsigned int unk_9d8;
    unsigned int unk_9dc;
    unsigned int unk_9e0;
    unsigned int unk_9e4;
    unsigned int unk_9e8;
    unsigned int unk_9ec;
    unsigned int unk_9f0;
    unsigned int unk_9f4;
    unsigned int unk_9f8;
    unsigned int unk_9fc;
    unsigned int unk_a00;
    unsigned int unk_a04;
    unsigned int unk_a08;
    unsigned int unk_a0c;
    unsigned int unk_a10;
    unsigned int unk_a14;
    unsigned int unk_a18;
    unsigned int unk_a1c;
    unsigned int unk_a20;
    unsigned int unk_a24;
    unsigned int unk_a28;
    unsigned int unk_a2c;
    unsigned int unk_a30;
    unsigned int unk_a34;
    unsigned int unk_a38;
    unsigned int unk_a3c;
    unsigned int unk_a40;
    unsigned int unk_a44;
    unsigned int unk_a48;
    unsigned int unk_a4c;
    unsigned int unk_a50;
    unsigned int unk_a54;
    unsigned int unk_a58;
    unsigned int unk_a5c;
    unsigned int unk_a60;
    unsigned int unk_a64;
    unsigned int unk_a68;
    unsigned int unk_a6c;
    unsigned int unk_a70;
    unsigned int unk_a74;
    unsigned int unk_a78;
    unsigned int unk_a7c;
    unsigned int unk_a80;
    unsigned int unk_a84;
    unsigned int unk_a88;
    unsigned int unk_a8c;
    unsigned int unk_a90;
    unsigned int unk_a94;
    unsigned int unk_a98;
    unsigned int unk_a9c;
    unsigned int unk_aa0;
    unsigned int unk_aa4;
    unsigned int unk_aa8;
    unsigned int unk_aac;
    unsigned int unk_ab0;
    unsigned int unk_ab4;
    unsigned int unk_ab8;
    unsigned int unk_abc;
    unsigned int unk_ac0;
    unsigned int unk_ac4;
    unsigned int unk_ac8;
    unsigned int unk_acc;
    unsigned int unk_ad0;
    unsigned int unk_ad4;
    unsigned int unk_ad8;
    unsigned int unk_adc;
    unsigned int unk_ae0;
    unsigned int unk_ae4;
    unsigned int unk_ae8;
    unsigned int unk_aec;
    unsigned int m_af0;
    unsigned int unk_af4;
    unsigned int unk_af8;
    unsigned int unk_afc;
    unsigned int unk_b00;
    unsigned int unk_b04;
    unsigned int unk_b08;
    unsigned int unk_b0c;
    unsigned int unk_b10;
    unsigned int unk_b14;
    unsigned int unk_b18;
    unsigned int unk_b1c;
    unsigned int unk_b20;
    unsigned int unk_b24;
    unsigned int unk_b28;
    unsigned int unk_b2c;
    unsigned int unk_b30;
    unsigned int unk_b34;
    unsigned int unk_b38;
    unsigned int unk_b3c;
    unsigned int unk_b40;
    unsigned int unk_b44;
    unsigned int unk_b48;
    unsigned int unk_b4c;
    unsigned int unk_b50;
    unsigned int unk_b54;
    unsigned int unk_b58;
    unsigned int unk_b5c;
    unsigned int unk_b60;
    unsigned int unk_b64;
    unsigned int unk_b68;
    unsigned int unk_b6c;
    unsigned int unk_b70;
    unsigned int unk_b74;
    unsigned int unk_b78;
    unsigned int unk_b7c;
    unsigned int unk_b80;
    unsigned int unk_b84;
    unsigned int unk_b88;
    unsigned int unk_b8c;
    unsigned int unk_b90;
    unsigned int unk_b94;
    unsigned int unk_b98;
    unsigned int unk_b9c;
    unsigned int unk_ba0;
    unsigned int unk_ba4;
    unsigned int unk_ba8;
    unsigned int unk_bac;
    unsigned int unk_bb0;
    unsigned int unk_bb4;
    unsigned int unk_bb8;
    unsigned int unk_bbc;
    unsigned int unk_bc0;
    unsigned int unk_bc4;
    unsigned int unk_bc8;
    unsigned int unk_bcc;
    unsigned int unk_bd0;
    unsigned int unk_bd4;
    unsigned int unk_bd8;
    unsigned int unk_bdc;
    unsigned int unk_be0;
    unsigned int unk_be4;
    unsigned int unk_be8;
    unsigned int unk_bec;
    unsigned int unk_bf0;
    unsigned int unk_bf4;
    unsigned int unk_bf8;
    unsigned int unk_bfc;
    unsigned int unk_c00;
    unsigned int unk_c04;
    unsigned int unk_c08;
    unsigned int unk_c0c;
    unsigned int unk_c10;
    unsigned int unk_c14;
    unsigned int unk_c18;
    unsigned int unk_c1c;
    unsigned int unk_c20;
    unsigned int unk_c24;
    unsigned int unk_c28;
    unsigned int unk_c2c;
    unsigned int unk_c30;
    unsigned int unk_c34;
    unsigned int unk_c38;
    unsigned int unk_c3c;
    unsigned int unk_c40;
    unsigned int unk_c44;
    unsigned int unk_c48;
    unsigned int unk_c4c;
    unsigned int unk_c50;
    unsigned int unk_c54;
    unsigned int unk_c58;
    unsigned int unk_c5c;
    unsigned int unk_c60;
    unsigned int unk_c64;
    unsigned int unk_c68;
    unsigned int unk_c6c;
    unsigned int unk_c70;
    unsigned int unk_c74;
    unsigned int unk_c78;
    unsigned int unk_c7c;
    unsigned int unk_c80;
    unsigned int unk_c84;
    unsigned int unk_c88;
    unsigned int unk_c8c;
    unsigned int unk_c90;
    unsigned int unk_c94;
    unsigned int unk_c98;
    unsigned int unk_c9c;
    unsigned int unk_ca0;
    unsigned int unk_ca4;
    unsigned int unk_ca8;
    unsigned int unk_cac;
    unsigned int unk_cb0;
    unsigned int unk_cb4;
    unsigned int unk_cb8;
    unsigned int unk_cbc;
    unsigned int unk_cc0;
    unsigned int unk_cc4;
    unsigned int unk_cc8;
    unsigned int unk_ccc;
    unsigned int unk_cd0;
    unsigned int unk_cd4;
    unsigned int unk_cd8;
    unsigned int unk_cdc;
    unsigned int unk_ce0;
    unsigned int unk_ce4;
    unsigned int unk_ce8;
    unsigned int unk_cec;
    unsigned int unk_cf0;
    unsigned int unk_cf4;
    unsigned int unk_cf8;
    unsigned int unk_cfc;
    unsigned int unk_d00;
    unsigned int unk_d04;
    unsigned int unk_d08;
    unsigned int unk_d0c;
    unsigned int unk_d10;
    unsigned int unk_d14;
    unsigned int unk_d18;
    unsigned int unk_d1c;
    unsigned int unk_d20;
    unsigned int unk_d24;
    unsigned int unk_d28;
    unsigned int unk_d2c;
    unsigned int unk_d30;
    unsigned int unk_d34;
    unsigned int unk_d38;
    unsigned int unk_d3c;
    unsigned int unk_d40;
    unsigned int unk_d44;
    unsigned int unk_d48;
    unsigned int unk_d4c;
    unsigned int unk_d50;
    unsigned int unk_d54;
    unsigned int unk_d58;
    unsigned int unk_d5c;
    unsigned int unk_d60;
    unsigned int unk_d64;
    unsigned int unk_d68;
    unsigned int unk_d6c;
    unsigned int unk_d70;
    unsigned int unk_d74;
    unsigned int unk_d78;
    unsigned int unk_d7c;
    unsigned int unk_d80;
    unsigned int unk_d84;
    unsigned int unk_d88;
    unsigned int unk_d8c;
    unsigned int unk_d90;
    unsigned int unk_d94;
    unsigned int unk_d98;
    unsigned int unk_d9c;
    unsigned int unk_da0;
    unsigned int unk_da4;
    unsigned int unk_da8;
    unsigned int unk_dac;
    unsigned int unk_db0;
    unsigned int unk_db4;
    unsigned int unk_db8;
    unsigned int unk_dbc;
    unsigned int unk_dc0;
    unsigned int unk_dc4;
    unsigned int unk_dc8;
    unsigned int unk_dcc;
    unsigned int unk_dd0;
    unsigned int unk_dd4;
    unsigned int unk_dd8;
    unsigned int unk_ddc;
    unsigned int unk_de0;
    unsigned int unk_de4;
    unsigned int unk_de8;
    unsigned int unk_dec;
    unsigned int unk_df0;
    unsigned int unk_df4;
    unsigned int unk_df8;
    unsigned int unk_dfc;
    unsigned int unk_e00;
    unsigned int unk_e04;
    unsigned int unk_e08;
    unsigned int unk_e0c;
    unsigned int unk_e10;
    unsigned int unk_e14;
    unsigned int unk_e18;
    unsigned int unk_e1c;
    unsigned int unk_e20;
    unsigned int unk_e24;
    unsigned int unk_e28;
    unsigned int unk_e2c;
    unsigned int unk_e30;
    unsigned int unk_e34;
    unsigned int unk_e38;
    unsigned int unk_e3c;
    unsigned int unk_e40;
    unsigned int unk_e44;
    unsigned int unk_e48;
    unsigned int unk_e4c;
    unsigned int unk_e50;
    unsigned int unk_e54;
    unsigned int unk_e58;
    unsigned int unk_e5c;
    unsigned int unk_e60;
    unsigned int unk_e64;
    unsigned int unk_e68;
    unsigned int unk_e6c;
    unsigned int unk_e70;
    unsigned int unk_e74;
    unsigned char m_e78;
    unsigned char unk_e79;
    unsigned short unk_e7a;
    int m_e7c;

    void RebuildCardLists();
    void InitCaravanTable();
    void FUN_0073d020();

    int FUN_00726070();
    void FUN_00a1dc70(void* p, int z);
    void FUN_00a1dc20(int z);
};

struct Mid2
{
    double FUN_00a011b0(int id);
    static float FUN_00a01530();
    int FUN_00a012d0(int id, float v, bool b);
    void* FUN_00a03c90();
};

struct Mid1
{
    Mid2* ReadXML();
};

struct MgrX
{
    Mid1* FUN_00586150(const char* s);
};

struct SysObj
{
    int GetField614();
    unsigned int GetField618();
};

struct Handle
{
    int FUN_005ae380();
};

struct OtherObj
{
    int FUN_0059bb30();
};

struct GlobalF8
{
    const char* FUN_004c69f0();
};

struct BSSoundHandleEx
{
    unsigned int id, state, flags;
    ~BSSoundHandleEx();
    void Play();
};

struct StrHelper
{
    void Play();
};

struct BSAudioLike
{
    BSSoundHandleEx FUN_00ad7550(const char* s, int n, int z);
};

struct AudioFactory
{
    static BSAudioLike* FUN_00453a70();
};

struct SubObj
{
    unsigned char FUN_00718840(int a);
    void SetFlag2(int a);
};

struct CdeclFns
{
    static IFace* FUN_00a09030(int a);
    static int FUN_00406d00(char* buf, int n, const char* s);
    static bool DispatchMessageToSink(char* buf, int a, const char* s, const char* t, float f, bool b);
    static int FUN_005b5e40(const char* s);
    static TESForm* __cdecl FUN_00483a00(const char* a);
    static int FUN_00ec43fb(int a, int z, const char* source, const char* target, int ref);
    static int InitTutorialMenu(BGSMessage* a, int z);
};

extern GlobalF8 g_011d47f8;
extern char DAT_011d9184;

// @fnv 0x00741060
int __cdecl FUN_00741060(int a0, int a1, int a2, float a3, char a4)
{
    IFace* p4 = CdeclFns::FUN_00a09030(0x43b);
    Mid2* mid5;
    DAT_011d9180 = (InterfaceManager*)_FUN_004b7210();
    int sum4 = ((Handle*)(size_t)((SysObj*)DAT_011dea3c)->GetField614())->FUN_005ae380() +
               ((Handle*)(size_t)((SysObj*)DAT_011dea3c)->GetField618())->FUN_005ae380();
    if (sum4 < 0x1e)
    {
        char buf[0x104];
        CdeclFns::FUN_00406d00(buf, 0x104, g_011d47f8.FUN_004c69f0());
        CdeclFns::DispatchMessageToSink(buf, 0, DAT_01049638, 0, 2.0f, false);
        {
            AudioFactory::FUN_00453a70()->FUN_00ad7550(DAT_01025cc4, 0x121, 0).Play();
        }
        return 0;
    }
    a4 = 0;
    if (p4)
    {
        delete p4;
    }
    mid5 = ((MgrX*)DAT_011d9180)->FUN_00586150(DAT_0107170c)->ReadXML();
    DAT_011d917c = (FUN_0073bab0_shell*)mid5->FUN_00a03c90();
    if (DAT_011d917c && ((Obj917c*)DAT_011d917c)->V13() == FUN_0073cbe0())
    {
        ((Obj917c*)DAT_011d917c)->m_100 = a0;
        ((Obj917c*)DAT_011d917c)->m_104 = ((OtherObj*)(size_t)a1)->FUN_0059bb30();
        ((Obj917c*)DAT_011d917c)->m_108 = a2;
        ((Obj917c*)DAT_011d917c)->m_10c = a3;
        ((Obj917c*)DAT_011d917c)->FUN_00a1dc70(mid5, 0);
        if (!(unsigned char)((FUN_007414c0_shell*)DAT_011d917c)->HasAllTiles())
        {
            CdeclFns::FUN_005b5e40(DAT_010716b8);
            UpdateCardSelection();
            return 0;
        }
        if (mid5->FUN_00a011b0(0xfa7) == 6006.0 || mid5->FUN_00a011b0(0xfa7) == 102.0)
        {
            mid5->FUN_00a012d0(0xfad, (float)mid5->FUN_00a01530(), true);
        }
        ((Obj917c*)DAT_011d917c)->RebuildCardLists();
        ((Obj917c*)DAT_011d917c)->m_6c->FUN_00a012d0(0x1004, (float)((Obj917c*)DAT_011d917c)->m_af0, 0);
        ((Obj917c*)DAT_011d917c)->m_6c->FUN_00a012d0(DAT_011d9170, 12.0f, 0);
        ((FUN_00a01290_shell*)((Obj917c*)DAT_011d917c)->m_6c)
            ->SetTraitAndReset(((Obj917c*)DAT_011d917c)->m_6c->TraitNameToID(DAT_01070250), 1.0f);
        DAT_011d9184 = a4;
        ((Obj917c*)DAT_011d917c)->InitCaravanTable();
        ((Obj917c*)DAT_011d917c)->FUN_0073d020();
        DAT_011d917c->SetFlag(1, 0);
        ((Obj917c*)DAT_011d917c)->FUN_00a1dc20(0);
        if (!((SubObj*)((char*)_FUN_004b7210() + 0x4d4))->FUN_00718840(0x1e))
        {
            BGSMessage* r = dynamic_cast<BGSMessage*>(CdeclFns::FUN_00483a00(DAT_01018dec));
            if (r)
            {
                ((Obj917c*)DAT_011d917c)->m_e78 = (unsigned char)CdeclFns::InitTutorialMenu(r, 0);
                ((SubObj*)((char*)_FUN_004b7210() + 0x4d4))->SetFlag2(0x1e);
                ((Obj917c*)DAT_011d917c)->m_e7c = 0x1e;
            }
        }
        return (int)mid5;
    }
    else if (DAT_011d917c)
    {
        if (((Obj917c*)DAT_011d917c)->FUN_00726070())
        {
            delete (Obj917c*)DAT_011d917c;
        }
    }
    return 0;
}

bool __cdecl FUN_004b71d0();
bool __cdecl Check_00702450(int v);
void __cdecl UpdateCardSelection();

struct CaravanInput
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual int GetValue();
    virtual bool HandleA(int id, float f);
    virtual bool HandleB(int id, float f);

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
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    int unk884;
    int unk888;
    int unk88C;
    int unk890;
    int unk894;
    int unk898;
    int unk89C;
    int unk8A0;
    int unk8A4;
    int unk8A8;
    int unk8AC;
    int unk8B0;
    int unk8B4;
    int unk8B8;
    int unk8BC;
    int unk8C0;
    int unk8C4;
    int unk8C8;
    int unk8CC;
    int unk8D0;
    int unk8D4;
    int unk8D8;
    int unk8DC;
    int unk8E0;
    int unk8E4;
    int unk8E8;
    int unk8EC;
    int unk8F0;
    int unk8F4;
    int unk8F8;
    int unk8FC;
    int unk900;
    int unk904;
    int unk908;
    int unk90C;
    int unk910;
    int unk914;
    int unk918;
    int unk91C;
    int unk920;
    int unk924;
    int unk928;
    int unk92C;
    int unk930;
    int unk934;
    int unk938;
    int unk93C;
    int unk940;
    int unk944;
    int unk948;
    int unk94C;
    int unk950;
    int unk954;
    int unk958;
    int unk95C;
    int unk960;
    int unk964;
    int unk968;
    int unk96C;
    int unk970;
    int unk974;
    int unk978;
    int unk97C;
    int unk980;
    int unk984;
    int unk988;
    int unk98C;
    int unk990;
    int unk994;
    int unk998;
    int unk99C;
    int unk9A0;
    int unk9A4;
    int unk9A8;
    int unk9AC;
    int unk9B0;
    int unk9B4;
    int unk9B8;
    int unk9BC;
    int unk9C0;
    int unk9C4;
    int unk9C8;
    int unk9CC;
    int unk9D0;
    int unk9D4;
    int unk9D8;
    int unk9DC;
    int unk9E0;
    int unk9E4;
    int unk9E8;
    int unk9EC;
    int unk9F0;
    int unk9F4;
    int unk9F8;
    int unk9FC;
    int unkA00;
    int unkA04;
    int unkA08;
    int unkA0C;
    int unkA10;
    int unkA14;
    int unkA18;
    int unkA1C;
    int unkA20;
    int unkA24;
    int unkA28;
    int unkA2C;
    int unkA30;
    int unkA34;
    int unkA38;
    int unkA3C;
    int unkA40;
    int unkA44;
    int unkA48;
    int unkA4C;
    int unkA50;
    int unkA54;
    int unkA58;
    int unkA5C;
    int unkA60;
    int unkA64;
    int unkA68;
    int unkA6C;
    int unkA70;
    int unkA74;
    int unkA78;
    int unkA7C;
    int unkA80;
    int unkA84;
    int unkA88;
    int unkA8C;
    int unkA90;
    int unkA94;
    int unkA98;
    int unkA9C;
    int unkAA0;
    int unkAA4;
    int unkAA8;
    int unkAAC;
    int unkAB0;
    int unkAB4;
    int unkAB8;
    int unkABC;
    int unkAC0;
    int unkAC4;
    int unkAC8;
    int unkACC;
    int unkAD0;
    int unkAD4;
    int unkAD8;
    int unkADC;
    int unkAE0;
    int unkAE4;
    int unkAE8;
    int unkAEC;
    int unkAF0;
    int unkAF4;
    int unkAF8;
    int unkAFC;
    int unkB00;
    int unkB04;
    int unkB08;
    int unkB0C;
    int unkB10;
    int unkB14;
    int unkB18;
    int unkB1C;
    int unkB20;
    int unkB24;
    int unkB28;
    int unkB2C;
    int unkB30;
    int unkB34;
    int unkB38;
    int unkB3C;
    int unkB40;
    int unkB44;
    int unkB48;
    int unkB4C;
    int unkB50;
    int unkB54;
    int unkB58;
    int unkB5C;
    int unkB60;
    int unkB64;
    int unkB68;
    int unkB6C;
    int unkB70;
    int unkB74;
    int unkB78;
    int unkB7C;
    int unkB80;
    int unkB84;
    int unkB88;
    int unkB8C;
    int unkB90;
    int unkB94;
    int unkB98;
    int unkB9C;
    int unkBA0;
    int unkBA4;
    int unkBA8;
    int unkBAC;
    int unkBB0;
    int unkBB4;
    int unkBB8;
    int unkBBC;
    int unkBC0;
    int unkBC4;
    int unkBC8;
    int unkBCC;
    int unkBD0;
    int unkBD4;
    int unkBD8;
    int unkBDC;
    int unkBE0;
    int unkBE4;
    int unkBE8;
    int unkBEC;
    int unkBF0;
    int unkBF4;
    int unkBF8;
    int unkBFC;
    int unkC00;
    int unkC04;
    int unkC08;
    int unkC0C;
    int unkC10;
    int unkC14;
    int unkC18;
    int unkC1C;
    int unkC20;
    int unkC24;
    int unkC28;
    int unkC2C;
    int unkC30;
    int unkC34;
    int unkC38;
    int unkC3C;
    int unkC40;
    int unkC44;
    int unkC48;
    int unkC4C;
    int unkC50;
    int unkC54;
    int unkC58;
    int unkC5C;
    int unkC60;
    int unkC64;
    int unkC68;
    int unkC6C;
    int unkC70;
    int unkC74;
    int unkC78;
    int unkC7C;
    int unkC80;
    int unkC84;
    int unkC88;
    int unkC8C;
    int unkC90;
    int unkC94;
    int unkC98;
    int unkC9C;
    int unkCA0;
    int unkCA4;
    int unkCA8;
    int unkCAC;
    int unkCB0;
    int unkCB4;
    int unkCB8;
    int unkCBC;
    int unkCC0;
    int unkCC4;
    int unkCC8;
    int unkCCC;
    int unkCD0;
    int unkCD4;
    int unkCD8;
    int unkCDC;
    int unkCE0;
    int unkCE4;
    int unkCE8;
    int unkCEC;
    int unkCF0;
    int unkCF4;
    int unkCF8;
    int unkCFC;
    int unkD00;
    int unkD04;
    int unkD08;
    int unkD0C;
    int unkD10;
    int unkD14;
    int unkD18;
    int unkD1C;
    int unkD20;
    int unkD24;
    int unkD28;
    int unkD2C;
    int unkD30;
    int unkD34;
    int unkD38;
    int unkD3C;
    int unkD40;
    int unkD44;
    int unkD48;
    int unkD4C;
    int unkD50;
    int unkD54;
    int unkD58;
    int unkD5C;
    int unkD60;
    int unkD64;
    int unkD68;
    int unkD6C;
    int unkD70;
    int unkD74;
    int unkD78;
    int unkD7C;
    int unkD80;
    int unkD84;
    int unkD88;
    int unkD8C;
    int unkD90;
    int unkD94;
    int unkD98;
    int unkD9C;
    int unkDA0;
    int unkDA4;
    int unkDA8;
    int unkDAC;
    int unkDB0;
    int unkDB4;
    int unkDB8;
    int unkDBC;
    int unkDC0;
    int unkDC4;
    int unkDC8;
    int unkDCC;
    int unkDD0;
    int unkDD4;
    int unkDD8;
    int unkDDC;
    int unkDE0;
    int unkDE4;
    int unkDE8;
    int unkDEC;
    int unkDF0;
    int unkDF4;
    int unkDF8;
    int unkDFC;
    int unkE00;
    int unkE04;
    int unkE08;
    int unkE0C;
    int unkE10;
    int unkE14;
    int unkE18;
    int unkE1C;
    int unkE20;
    int unkE24;
    int unkE28;
    int unkE2C;
    int unkE30;
    int unkE34;
    int unkE38;
    int unkE3C;
    int unkE40;
    int unkE44;
    int unkE48;
    int unkE4C;
    int unkE50;
    int unkE54;
    int unkE58;
    int unkE5C;
    int unkE60;
    int unkE64;
    int unkE68;
    int unkE6C;
    int unkE70;
    int unkE74;
    int unkE78;
    int unkE7C;
    int pendingKey;

    bool HandleKey(int key);
};

// @fnv 0x00749360
bool CaravanInput::HandleKey(int key)
{
    pendingKey = 0;
    bool bHandled = false;
    if (!FUN_004b71d0())
    {
        if (unk28 == 3 && Check_00702450(GetValue()))
        {
            UpdateCardSelection();
            return true;
        }
        int a = 0;
        int b = 0;
        int c7 = 0x7fff;
        float x5 = 0.0f;
        float y3 = 0.0f;
        switch (key)
        {
        case 0x57:
        case 0x77:
            bHandled = HandleA(9, 0.0f);
            break;
        case 0x41:
        case 0x61:
            bHandled = HandleA(11, 0.0f);
            break;
        case 0x46:
        case 0x66:
            bHandled = HandleA(12, 0.0f);
            break;
        case 0x52:
        case 0x72:
            bHandled = HandleB(10, 0.0f);
            break;
        case 0x51:
        case 0x71:
            bHandled = HandleA(13, 0.0f);
            break;
        case 0x45:
        case 0x65:
            bHandled = HandleA(14, 0.0f);
            break;
        case 0x53:
        case 0x73:
            bHandled = HandleA(16, 0.0f);
            break;
        case 0x80000001:
        case 0x80000002:
        case 0x80000003:
        case 0x80000004:
            if (unk2C == 0)
                pendingKey = key;
            break;
        }
    }
    return bHandled;
}

struct ActionDispatch
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
    virtual void SetPrimary(unsigned int action, float value);
    virtual void SetSecondary(unsigned int action, float value);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    void* blocked;
    bool FUN_00740f10(unsigned int flag);
    void HandleEvent(unsigned int event, unsigned int unused);
};
// If not blocked and FUN_00740f10(1) is false, maps event codes to SetPrimary/SetSecondary calls with a zero value.
// @fnv 0x00749560
void ActionDispatch::HandleEvent(unsigned int event, unsigned int unused)
{
    if (!blocked && !FUN_00740f10(1))
    {
        switch (event)
        {
        case 7:
            SetPrimary(12, 0.0f);
            break;
        case 36:
            SetPrimary(11, 0.0f);
            break;
        case 37:
            SetPrimary(9, 0.0f);
            break;
        case 38:
            SetSecondary(10, 0.0f);
            break;
        case 10:
            SetPrimary(16, 0.0f);
            break;
        case 12:
            SetPrimary(9, 0.0f);
            break;
        case 13:
            SetPrimary(11, 0.0f);
            break;
        case 14:
            SetPrimary(12, 0.0f);
            break;
        case 19:
            SetPrimary(9, 0.0f);
            break;
        case 20:
            SetPrimary(13, 0.0f);
            break;
        case 21:
            SetPrimary(14, 0.0f);
            break;
        case 22:
            SetSecondary(10, 0.0f);
            break;
        }
    }
}

struct ControlTile
{
    float GetFloat(int);
    void FUN_00a012d0(int, float, bool);
};
struct SelectedCard
{
    bool IsSpecial();
};
struct CardsView
{
    SelectedCard*& At(int);
    unsigned int Count();
};
extern int DAT_011d9170;
struct CaravanControls
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
    int state;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    ControlTile* button;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    ControlTile* selection;
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
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
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
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    int unk9a8;
    int unk9ac;
    int unk9b0;
    int unk9b4;
    int unk9b8;
    int unk9bc;
    int unk9c0;
    int unk9c4;
    int unk9c8;
    int unk9cc;
    int unk9d0;
    int unk9d4;
    int unk9d8;
    int unk9dc;
    int unk9e0;
    int unk9e4;
    int unk9e8;
    int unk9ec;
    int unk9f0;
    int unk9f4;
    int unk9f8;
    int unk9fc;
    int unka00;
    int unka04;
    int unka08;
    int unka0c;
    int unka10;
    int unka14;
    int unka18;
    int unka1c;
    int unka20;
    int unka24;
    int unka28;
    int unka2c;
    int unka30;
    int unka34;
    int unka38;
    int unka3c;
    int unka40;
    int unka44;
    int unka48;
    int unka4c;
    int unka50;
    int unka54;
    int unka58;
    int unka5c;
    int unka60;
    int unka64;
    int unka68;
    int unka6c;
    int unka70;
    int unka74;
    int unka78;
    int unka7c;
    int unka80;
    int unka84;
    int unka88;
    int unka8c;
    int unka90;
    int unka94;
    int unka98;
    int unka9c;
    int unkaa0;
    int unkaa4;
    int unkaa8;
    int unkaac;
    int unkab0;
    int unkab4;
    int unkab8;
    int unkabc;
    int unkac0;
    int unkac4;
    int unkac8;
    int unkacc;
    int unkad0;
    int unkad4;
    int unkad8;
    int score;
    int target;
    int limit;
    int unkae8;
    unsigned int cardCount;
    int unkaf0;
    int unkaf4;
    int unkaf8;
    int unkafc;
    int unkb00;
    int unkb04;
    int unkb08;
    int unkb0c;
    int unkb10;
    int unkb14;
    int unkb18;
    int unkb1c;
    int unkb20;
    int unkb24;
    int unkb28;
    int unkb2c;
    int unkb30;
    int unkb34;
    int unkb38;
    int unkb3c;
    int unkb40;
    int unkb44;
    int unkb48;
    int unkb4c;
    int unkb50;
    int unkb54;
    int unkb58;
    int unkb5c;
    int unkb60;
    int unkb64;
    int unkb68;
    int unkb6c;
    int unkb70;
    int unkb74;
    int unkb78;
    int unkb7c;
    int unkb80;
    int unkb84;
    int unkb88;
    int unkb8c;
    int unkb90;
    int unkb94;
    int unkb98;
    int unkb9c;
    int unkba0;
    int unkba4;
    int unkba8;
    int unkbac;
    int unkbb0;
    int unkbb4;
    int unkbb8;
    int unkbbc;
    int unkbc0;
    int unkbc4;
    int unkbc8;
    int unkbcc;
    int unkbd0;
    int unkbd4;
    int unkbd8;
    int unkbdc;
    int unkbe0;
    int unkbe4;
    int unkbe8;
    int unkbec;
    int unkbf0;
    int unkbf4;
    int unkbf8;
    int unkbfc;
    int unkc00;
    int unkc04;
    int unkc08;
    int unkc0c;
    int unkc10;
    int unkc14;
    int unkc18;
    int unkc1c;
    int unkc20;
    int unkc24;
    int unkc28;
    int unkc2c;
    int unkc30;
    int unkc34;
    int unkc38;
    int unkc3c;
    int unkc40;
    int unkc44;
    int unkc48;
    int unkc4c;
    int unkc50;
    int unkc54;
    int unkc58;
    int unkc5c;
    int unkc60;
    int unkc64;
    int unkc68;
    int unkc6c;
    int unkc70;
    int unkc74;
    int unkc78;
    int unkc7c;
    int unkc80;
    int unkc84;
    int unkc88;
    int unkc8c;
    int unkc90;
    int unkc94;
    int unkc98;
    int unkc9c;
    int unkca0;
    int unkca4;
    int unkca8;
    int unkcac;
    int unkcb0;
    int unkcb4;
    int unkcb8;
    int unkcbc;
    int unkcc0;
    int unkcc4;
    int unkcc8;
    int unkccc;
    int unkcd0;
    int unkcd4;
    int unkcd8;
    int unkcdc;
    int unkce0;
    int unkce4;
    int unkce8;
    int unkcec;
    int unkcf0;
    int unkcf4;
    int unkcf8;
    int unkcfc;
    int unkd00;
    int unkd04;
    int unkd08;
    int unkd0c;
    int unkd10;
    int unkd14;
    int unkd18;
    int unkd1c;
    int unkd20;
    int unkd24;
    int unkd28;
    int unkd2c;
    int unkd30;
    int unkd34;
    int unkd38;
    int unkd3c;
    int unkd40;
    int unkd44;
    int unkd48;
    int unkd4c;
    int unkd50;
    int unkd54;
    int unkd58;
    int unkd5c;
    int unkd60;
    int unkd64;
    int unkd68;
    int unkd6c;
    int unkd70;
    int unkd74;
    int unkd78;
    int unkd7c;
    int unkd80;
    int unkd84;
    int unkd88;
    int unkd8c;
    int unkd90;
    int unkd94;
    int unkd98;
    int unkd9c;
    int unkda0;
    int unkda4;
    int unkda8;
    int unkdac;
    int unkdb0;
    int unkdb4;
    int unkdb8;
    int unkdbc;
    int unkdc0;
    int unkdc4;
    int unkdc8;
    int unkdcc;
    int unkdd0;
    int unkdd4;
    int unkdd8;
    int unkddc;
    int unkde0;
    int unkde4;
    int unkde8;
    int unkdec;
    int unkdf0;
    int unkdf4;
    int unkdf8;
    int unkdfc;
    int unke00;
    int unke04;
    int unke08;
    int unke0c;
    int unke10;
    int unke14;
    int unke18;
    int unke1c;
    int unke20;
    int unke24;
    int unke28;
    int unke2c;
    int unke30;
    int unke34;
    int unke38;
    int unke3c;
    int unke40;
    int unke44;
    void Enable(int, int);
    bool HasFlag(unsigned int);
    void UpdateControls();
};
// Updates the enabled state of control flags based on the current state, score, target, limit, card counts and selection.
// @fnv 0x00749740
void CaravanControls::UpdateControls()
{
    switch (state)
    {
    case 0:
        if (score > 0 || target == 0)
            Enable(2, 0);
        else
            Enable(2, 1);
        if (limit == 0)
        {
            Enable(4, 1);
            Enable(16, 1);
        }
        else if (score > 0)
        {
            Enable(4, 0);
            Enable(16, 0);
            if (score >= target || (score >= limit && score < target))
                Enable(4, 1);
            if (score >= limit)
                Enable(16, 1);
        }
        else
        {
            Enable(4, 0);
            Enable(16, 0);
        }
        break;
    case 1:
        if (((CardsView*)&unka6c)->At((int)selection->GetFloat(DAT_011d9170))->IsSpecial())
        {
            Enable(4, 1);
            Enable(16, 0);
        }
        else
        {
            Enable(4, 0);
            Enable(16, 1);
        }
        if (cardCount < 30)
        {
            Enable(2, 1);
            button->FUN_00a012d0(4009, 128.0f, true);
        }
        else
        {
            Enable(2, 0);
            button->FUN_00a012d0(4009, 255.0f, true);
        }
        if (cardCount < 1)
            Enable(16, 1);
        if (cardCount >= 108)
            Enable(4, 1);
        Enable(32, 1);
        break;
    case 2:
        if (!((CardsView*)&unkb04)->Count())
        {
            unke40 = -1;
            Enable(128, 1);
        }
        if (!((CardsView*)&unkb14)->Count())
            unke44 = -1;
        if ((!((CardsView*)&unkb44)->Count() && !((CardsView*)&unkbb4)->Count() && !((CardsView*)&unkc24)->Count()) ||
            HasFlag(2048))
            Enable(256, 1);
        else
            Enable(256, 0);
        break;
    }
}

struct NiUpdateDataH
{
    float time;
    bool a, b, c, d, e;
    void FUN_0043d410(float, bool, bool);
};
void __cdecl FUN_00406d00_format(char*, unsigned int, const char*, ...);
struct MatchVector
{
    float x, y, z;
    float FUN_0084d030();
};
struct MatchMatrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
};
struct MatchNode
{
    MatchVector& FUN_0043d450();
    MatchMatrix& FUN_006a9540();
    void FUN_0043fa80(const MatchMatrix*);
    void FUN_004bc1f0(float, float, float);
    void Update(const NiUpdateData&);
};
struct MatchPointer
{
    MatchNode* FUN_00559450();
};
extern MatchPointer DAT_011d91e4;
struct MatchScene
{
    void FUN_00b5ca70(MatchNode*, float);
};
MatchScene* __cdecl FUN_00450b80(int);
unsigned int __cdecl GetRandomNumberInRange(int, int);
struct MatchArray
{
    int data, size, capacity, grow;
    unsigned int FUN_0044ddc0();
    int& FUN_006a7ad0(unsigned int);
    void FUN_009a4320(unsigned int, int);
};
MatchNode* __cdecl FUN_004aae30(void*, const char*);
struct MatchMenu
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
    MatchArray array134;
    int extra144;
    int unk148;
    MatchArray array14c;
    int extra15c;
    int unk160;
    MatchArray array164;
    MatchArray array174;
    void PlaceRandomItem(int);
    void PlayCardPlacement(int);
    void PlaceBillsAndCoins(int skill, int amount);
};
// Randomly places bills and coins into the menu's arrays based on skill and amount, then updates the scene node.
// @fnv 0x0074a2c0
void MatchMenu::PlaceBillsAndCoins(int skill, int amount)
{
    NiUpdateDataH zero;
    {
        char name[260];
        {
            int bills = 0;
            int countCoins = 0;
            if (skill < 120)
            {
                while (amount > 0 && bills < 9 && countCoins < 42)
                {
                    int type = GetRandomNumberInRange(0, 9 - bills);
                    int billChance = GetRandomNumberInRange(0, 42 - countCoins);
                    int coinChance = 0;
                    if (1.5 * type > billChance)
                    {
                        coinChance = GetRandomNumberInRange(0, 3);
                        ((MatchMenu*)DAT_011d917c)->PlaceRandomItem(coinChance);
                        amount -= coinChance < 2 ? (coinChance ? 8 : 2) : 40;
                        bills++;
                    }
                    else
                    {
                        coinChance = GetRandomNumberInRange(0, 100);
                        coinChance = coinChance < 90 ? (coinChance < 40 ? 0 : 1) : 2;
                        coinChance = GetRandomNumberInRange(0, 2);
                        ((MatchMenu*)DAT_011d917c)->PlayCardPlacement(coinChance);
                        amount -= coinChance < 2 ? (coinChance ? 4 : 1) : 100;
                        countCoins++;
                    }
                }
            }
            else if (skill < 400)
            {
                while (amount > 0 && bills < 9 && countCoins < 42)
                {
                    int type = GetRandomNumberInRange(0, 9 - bills);
                    int billChance = GetRandomNumberInRange(0, 42 - countCoins);
                    int coinChance = 0;
                    if (1.5 * type > billChance)
                    {
                        coinChance = GetRandomNumberInRange(0, 3);
                        ((MatchMenu*)DAT_011d917c)->PlaceRandomItem(coinChance);
                        amount -= coinChance < 2 ? (coinChance ? 8 : 2) : 40;
                        bills++;
                    }
                    else
                    {
                        coinChance = GetRandomNumberInRange(0, 100);
                        coinChance = coinChance < 75 ? (coinChance < 33 ? 0 : 1) : 2;
                        ((MatchMenu*)DAT_011d917c)->PlayCardPlacement(coinChance);
                        amount -= coinChance < 2 ? (coinChance ? 4 : 1) : 100;
                        countCoins++;
                    }
                }
            }
            else if (skill < 1000)
            {
                while (amount > 0 && bills < 9 && countCoins < 42)
                {
                    int type = GetRandomNumberInRange(0, 9 - bills);
                    int billChance = GetRandomNumberInRange(0, 42 - countCoins);
                    int coinChance = 0;
                    if (1.5 * type > billChance)
                    {
                        coinChance = GetRandomNumberInRange(1, 3);
                        PlaceRandomItem(coinChance);
                        amount -= coinChance < 2 ? (coinChance ? 8 : 2) : 40;
                        bills++;
                    }
                    else
                    {
                        coinChance = GetRandomNumberInRange(0, 100);
                        coinChance = coinChance < 66 ? (coinChance < 33 ? 0 : 1) : 2;
                        PlayCardPlacement(coinChance);
                        amount -= coinChance < 2 ? (coinChance ? 4 : 1) : 100;
                        countCoins++;
                    }
                }
            }
            else if (skill < 2000)
            {
                while (amount > 0 && bills < 9 && countCoins < 42)
                {
                    int type = GetRandomNumberInRange(0, 9 - bills);
                    int billChance = GetRandomNumberInRange(0, 42 - countCoins);
                    int coinChance = 0;
                    if (1.5 * type > billChance)
                    {
                        coinChance = GetRandomNumberInRange(1, 3);
                        PlaceRandomItem(coinChance);
                        amount -= coinChance < 2 ? (coinChance ? 8 : 2) : 40;
                        bills++;
                    }
                    else
                    {
                        coinChance = GetRandomNumberInRange(0, 100);
                        coinChance = coinChance < 20 ? (coinChance < 5 ? 0 : 1) : 2;
                        PlayCardPlacement(coinChance);
                        amount -= coinChance < 2 ? (coinChance ? 4 : 1) : 100;
                        countCoins++;
                    }
                }
            }
            else
            {
                while (amount > 0 && bills < 9 && countCoins < 42)
                {
                    int type = GetRandomNumberInRange(0, 9 - bills);
                    int billChance = GetRandomNumberInRange(0, 42 - countCoins);
                    int coinChance = 0;
                    if (type > billChance)
                    {
                        coinChance = 2;
                        PlaceRandomItem(coinChance);
                        amount -= 40;
                        bills++;
                    }
                    else
                    {
                        coinChance = GetRandomNumberInRange(0, 100);
                        coinChance = coinChance < 10 ? (coinChance < 5 ? 0 : 1) : 2;
                        PlayCardPlacement(coinChance);
                        amount -= coinChance < 2 ? (coinChance ? 4 : 1) : 100;
                        countCoins++;
                    }
                }
            }
            for (unsigned int i = unk160; i < array14c.FUN_0044ddc0(); i++)
            {
                if (!array164.FUN_0044ddc0())
                    break;
                int value = GetRandomNumberInRange(0, array164.FUN_0044ddc0());
                int rotation = array164.FUN_006a7ad0(value);
                array164.FUN_009a4320(value, 1);
                FUN_00406d00_format(name, 260, "Bill-Placement_0%i:0", rotation + 1);
                MatchNode* selected = FUN_004aae30((void*)unk114, name);
                MatchVector placement = selected->FUN_0043d450();
                MatchMatrix position = selected->FUN_006a9540();
                ((MatchNode*)array14c.FUN_006a7ad0(i))->FUN_0043fa80(&position);
                ((MatchNode*)array14c.FUN_006a7ad0(i))->FUN_004bc1f0(placement.x, placement.y, placement.z);
                ((MatchNode*)array14c.FUN_006a7ad0(i))->Update(NiUpdateData(0.0f, false, false));
            }
            for (unsigned int i = unk148; i < array134.FUN_0044ddc0(); i++)
            {
                if (!array174.FUN_0044ddc0())
                    break;
                int value = GetRandomNumberInRange(0, array174.FUN_0044ddc0());
                int rotation = array174.FUN_006a7ad0(value);
                array174.FUN_009a4320(value, 1);
                if (rotation + 1 < 10)
                    FUN_00406d00_format(name, 260, "Coin-Placement_0%i:0", rotation + 1);
                else
                    FUN_00406d00_format(name, 260, "Coin-Placement_%i:0", rotation + 1);
                MatchNode* selected = FUN_004aae30((void*)unk118, name);
                MatchVector placement = selected->FUN_0043d450();
                MatchMatrix position = selected->FUN_006a9540();
                ((MatchNode*)array134.FUN_006a7ad0(i))->FUN_0043fa80(&position);
                ((MatchNode*)array134.FUN_006a7ad0(i))->FUN_004bc1f0(placement.x, placement.y, placement.z);
                ((MatchNode*)array134.FUN_006a7ad0(i))->Update(NiUpdateData(0.0f, false, false));
            }
            if (FUN_00647b70(countCoins, bills) > 0)
                unk02c = 4;
            zero.FUN_0043d410(0.0f, false, false);
            DAT_011d91e4.FUN_00559450()->Update(*(NiUpdateData*)&zero);
            FUN_00450b80(1)->FUN_00b5ca70(DAT_011d91e4.FUN_00559450(),
                                          (float)(DAT_011d91e4.FUN_00559450()->FUN_0043d450().FUN_0084d030() * 2.5));
        }
    }
}

struct Form74
{
    int Type();
};
struct Entry74
{
    Form74* Form();
    int Count();
};
struct Node74
{
    Entry74** Data();
    Node74* Next();
};
struct List74
{
    Node74* head;
    int Caps();
};
struct Ref74
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
    virtual void Remove(Form74*, int, int, int, int, int, int, int, int, int);
    void* Owner();
    int Caps();
};
struct Handler74
{
    void Set(Ref74*);
    List74* List();
    void Remove(Entry74*, int, void*);
};
extern Handler74* g_dataHandler;
extern char* _g_thePlayer;
int __cdecl Value74(Form74*);
Form74* __cdecl Lookup74(int);
struct Container74
{
    int field0;
    int field4;
    int field8;
    Container74();
    ~Container74();
    void Add(Form74*, int, int);
    void Give(Ref74*, int);
};
struct TempEntry74
{
    int field0;
    int field4;
    int field8;
    TempEntry74(Form74*, int);
    ~TempEntry74();
};
struct Menu74
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
    Ref74* partner;
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
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
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
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    int unk9a8;
    int unk9ac;
    int unk9b0;
    int unk9b4;
    int unk9b8;
    int unk9bc;
    int unk9c0;
    int unk9c4;
    int unk9c8;
    int unk9cc;
    int unk9d0;
    int unk9d4;
    int unk9d8;
    int unk9dc;
    int unk9e0;
    int unk9e4;
    int unk9e8;
    int unk9ec;
    int unk9f0;
    int unk9f4;
    int unk9f8;
    int unk9fc;
    int unka00;
    int unka04;
    int unka08;
    int unka0c;
    int unka10;
    int unka14;
    int unka18;
    int unka1c;
    int unka20;
    int unka24;
    int unka28;
    int unka2c;
    int unka30;
    int unka34;
    int unka38;
    int unka3c;
    int unka40;
    int unka44;
    int unka48;
    int unka4c;
    int unka50;
    int unka54;
    int unka58;
    int unka5c;
    int unka60;
    int unka64;
    int unka68;
    int unka6c;
    int unka70;
    int unka74;
    int unka78;
    int unka7c;
    int unka80;
    int unka84;
    int unka88;
    int unka8c;
    int unka90;
    int unka94;
    int unka98;
    int unka9c;
    int unkaa0;
    int unkaa4;
    int unkaa8;
    int unkaac;
    int unkab0;
    int unkab4;
    int unkab8;
    int unkabc;
    int unkac0;
    int unkac4;
    int unkac8;
    int unkacc;
    int unkad0;
    int unkad4;
    int unkad8;
    int unkadc;
    int unkae0;
    int unkae4;
    int budget;
    void TransferBarterItems(bool win);
};
// Moves items and caps between the player and partner up to the budget, either giving the player items (win) or taking them (loss).
// @fnv 0x0074cc70
void Menu74::TransferBarterItems(bool abPlayerReceives)
{
    int remaining = budget;
    if (abPlayerReceives)
    {
        g_dataHandler->Set(partner);
        List74* nodeA = g_dataHandler->List();
        Form74* listA = 0;
        Node74* formA = nodeA->head;
        while (formA && *formA->Data())
        {
            int countA = 0;
            listA = (*formA->Data())->Form();
            if (listA && listA->Type() == 0x74)
            {
                if ((*formA->Data())->Count() > 0)
                {
                    int valueA = Value74(listA);
                    countA = (*formA->Data())->Count();
                    if (valueA * countA > remaining)
                        countA = remaining / valueA;
                    if (countA > 0)
                    {
                        Container74 transferA;
                        transferA.Add(listA, countA, 0);
                        transferA.Give((Ref74*)_g_thePlayer, 0);
                        g_dataHandler->Remove(*formA->Data(), countA, partner->Owner());
                        remaining -= countA * valueA;
                    }
                }
            }
            else
                listA = 0;
            formA = formA->Next();
        }
        if (remaining)
        {
            Container74 entryA;
            entryA.Add(Lookup74(15), remaining, 0);
            entryA.Give((Ref74*)_g_thePlayer, 0);
            TempEntry74 capsA(Lookup74(15), 0);
            if (nodeA->Caps() > remaining)
                g_dataHandler->Remove((Entry74*)&capsA, remaining, partner->Owner());
            else
            {
                g_dataHandler->Remove((Entry74*)&capsA, nodeA->Caps(), partner->Owner());
                partner->Remove(Lookup74(15), 0, remaining - nodeA->Caps(), 0, 0, 0, 0, 0, 1, 0);
            }
        }
    }
    else
    {
        g_dataHandler->Set((Ref74*)_g_thePlayer);
        List74* formB = g_dataHandler->List();
        Form74* listB = 0;
        Node74* nodeB = formB->head;
        while (nodeB && *nodeB->Data())
        {
            int countB = 0;
            listB = (*nodeB->Data())->Form();
            if (listB && listB->Type() == 0x74)
            {
                if ((*nodeB->Data())->Count() > 0)
                {
                    int valueB = Value74(listB);
                    countB = (*nodeB->Data())->Count();
                    if (valueB * countB > remaining)
                        countB = remaining / valueB;
                    if (countB > 0)
                    {
                        Container74 transferB;
                        transferB.Add(listB, countB, 0);
                        transferB.Give(partner, 0);
                        ((Ref74*)_g_thePlayer)->Remove(listB, 0, countB, 0, 0, 0, 0, 0, 1, 0);
                        remaining -= countB * valueB;
                    }
                }
            }
            else
                listB = 0;
            nodeB = nodeB->Next();
        }
        if (remaining)
        {
            Container74 capsB;
            capsB.Add(Lookup74(15), remaining, 0);
            capsB.Give(partner, 0);
            if (((Ref74*)_g_thePlayer)->Caps() > remaining)
                ((Ref74*)_g_thePlayer)->Remove(Lookup74(15), 0, remaining, 0, 0, 0, 0, 0, 1, 0);
            else
                ((Ref74*)_g_thePlayer)->Remove(Lookup74(15), 0, ((Ref74*)_g_thePlayer)->Caps(), 0, 0, 0, 0, 0, 1, 0);
        }
    }
}

static const char opponentDeckName[] = "Opponent-Deck_06:5";
struct Texture;
struct TextureRef
{
    Texture* ptr;
    TextureRef(Texture*);
    ~TextureRef();
    operator Texture*() const;
    TextureRef& operator=(Texture*);
};
struct FullNameComponent
{
    const char* GetFullName();
};
struct CardTexture
{
    FullNameComponent* FUN_0050d100();
    FullNameComponent* FUN_00503650();
};
struct DeckArray
{
    CardTexture** data;
    unsigned int size;
    unsigned int capacity;
    unsigned int grow;
    unsigned int FUN_0044ddc0();
    CardTexture*& FUN_006a7ad0(unsigned int);
};
struct ShaderProperty
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
    virtual void SetTexture(int, int, Texture*);
    int FUN_00441110();
};
struct SceneObject
{
    ShaderProperty* GetProperty(unsigned int);
    void FUN_00450f90(bool);
    void Update(const NiUpdateData&);
};
SceneObject* __cdecl FindObject(SceneObject*, const char*);
int __cdecl strcpy_s(char*, unsigned int, const char*);
int __cdecl FormatPath(char*, unsigned int, const char*, ...);
void __cdecl NormalizePath(const char*, char*, unsigned int);
struct TextureLoader
{
    void CreateTextureImage(const char*, TextureRef&, bool, bool);
};
extern TextureLoader* g_TES;
struct CardMenuTexture
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003c;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004c;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005c;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006c;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007c;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008c;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009c;
    unsigned int unk00a0;
    unsigned int unk00a4;
    unsigned int unk00a8;
    unsigned int unk00ac;
    unsigned int unk00b0;
    unsigned int unk00b4;
    unsigned int unk00b8;
    unsigned int unk00bc;
    unsigned int unk00c0;
    unsigned int unk00c4;
    unsigned int unk00c8;
    unsigned int unk00cc;
    unsigned int unk00d0;
    unsigned int unk00d4;
    unsigned int unk00d8;
    unsigned int unk00dc;
    unsigned int unk00e0;
    unsigned int unk00e4;
    unsigned int unk00e8;
    unsigned int unk00ec;
    unsigned int unk00f0;
    unsigned int unk00f4;
    unsigned int unk00f8;
    unsigned int unk00fc;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010c;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011c;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012c;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013c;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014c;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015c;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016c;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017c;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018c;
    SceneObject* playerRoot;
    SceneObject* opponentRoot;
    unsigned int unk0198;
    unsigned int unk019c;
    unsigned int unk01a0;
    unsigned int unk01a4;
    unsigned int unk01a8;
    unsigned int unk01ac;
    unsigned int unk01b0;
    unsigned int unk01b4;
    unsigned int unk01b8;
    unsigned int unk01bc;
    unsigned int unk01c0;
    unsigned int unk01c4;
    unsigned int unk01c8;
    unsigned int unk01cc;
    unsigned int unk01d0;
    unsigned int unk01d4;
    unsigned int unk01d8;
    unsigned int unk01dc;
    unsigned int unk01e0;
    unsigned int unk01e4;
    unsigned int unk01e8;
    unsigned int unk01ec;
    unsigned int unk01f0;
    unsigned int unk01f4;
    unsigned int unk01f8;
    unsigned int unk01fc;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020c;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021c;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022c;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023c;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024c;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025c;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026c;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027c;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028c;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029c;
    unsigned int unk02a0;
    unsigned int unk02a4;
    unsigned int unk02a8;
    unsigned int unk02ac;
    unsigned int unk02b0;
    unsigned int unk02b4;
    unsigned int unk02b8;
    unsigned int unk02bc;
    unsigned int unk02c0;
    unsigned int unk02c4;
    unsigned int unk02c8;
    unsigned int unk02cc;
    unsigned int unk02d0;
    unsigned int unk02d4;
    unsigned int unk02d8;
    unsigned int unk02dc;
    unsigned int unk02e0;
    unsigned int unk02e4;
    unsigned int unk02e8;
    unsigned int unk02ec;
    unsigned int unk02f0;
    unsigned int unk02f4;
    unsigned int unk02f8;
    unsigned int unk02fc;
    unsigned int unk0300;
    unsigned int unk0304;
    unsigned int unk0308;
    unsigned int unk030c;
    unsigned int unk0310;
    unsigned int unk0314;
    unsigned int unk0318;
    unsigned int unk031c;
    unsigned int unk0320;
    unsigned int unk0324;
    unsigned int unk0328;
    unsigned int unk032c;
    unsigned int unk0330;
    unsigned int unk0334;
    unsigned int unk0338;
    unsigned int unk033c;
    unsigned int unk0340;
    unsigned int unk0344;
    unsigned int unk0348;
    unsigned int unk034c;
    unsigned int unk0350;
    unsigned int unk0354;
    unsigned int unk0358;
    unsigned int unk035c;
    unsigned int unk0360;
    unsigned int unk0364;
    unsigned int unk0368;
    unsigned int unk036c;
    unsigned int unk0370;
    unsigned int unk0374;
    unsigned int unk0378;
    unsigned int unk037c;
    unsigned int unk0380;
    unsigned int unk0384;
    unsigned int unk0388;
    unsigned int unk038c;
    unsigned int unk0390;
    unsigned int unk0394;
    unsigned int unk0398;
    unsigned int unk039c;
    unsigned int unk03a0;
    unsigned int unk03a4;
    unsigned int unk03a8;
    unsigned int unk03ac;
    unsigned int unk03b0;
    unsigned int unk03b4;
    unsigned int unk03b8;
    unsigned int unk03bc;
    unsigned int unk03c0;
    unsigned int unk03c4;
    unsigned int unk03c8;
    unsigned int unk03cc;
    unsigned int unk03d0;
    unsigned int unk03d4;
    unsigned int unk03d8;
    unsigned int unk03dc;
    unsigned int unk03e0;
    unsigned int unk03e4;
    unsigned int unk03e8;
    unsigned int unk03ec;
    unsigned int unk03f0;
    unsigned int unk03f4;
    unsigned int unk03f8;
    unsigned int unk03fc;
    unsigned int unk0400;
    unsigned int unk0404;
    unsigned int unk0408;
    unsigned int unk040c;
    unsigned int unk0410;
    unsigned int unk0414;
    unsigned int unk0418;
    unsigned int unk041c;
    unsigned int unk0420;
    unsigned int unk0424;
    unsigned int unk0428;
    unsigned int unk042c;
    unsigned int unk0430;
    unsigned int unk0434;
    unsigned int unk0438;
    unsigned int unk043c;
    unsigned int unk0440;
    unsigned int unk0444;
    unsigned int unk0448;
    unsigned int unk044c;
    unsigned int unk0450;
    unsigned int unk0454;
    unsigned int unk0458;
    unsigned int unk045c;
    unsigned int unk0460;
    unsigned int unk0464;
    unsigned int unk0468;
    unsigned int unk046c;
    unsigned int unk0470;
    unsigned int unk0474;
    unsigned int unk0478;
    unsigned int unk047c;
    unsigned int unk0480;
    unsigned int unk0484;
    unsigned int unk0488;
    unsigned int unk048c;
    unsigned int unk0490;
    unsigned int unk0494;
    unsigned int unk0498;
    unsigned int unk049c;
    unsigned int unk04a0;
    unsigned int unk04a4;
    unsigned int unk04a8;
    unsigned int unk04ac;
    unsigned int unk04b0;
    unsigned int unk04b4;
    unsigned int unk04b8;
    unsigned int unk04bc;
    unsigned int unk04c0;
    unsigned int unk04c4;
    unsigned int unk04c8;
    unsigned int unk04cc;
    unsigned int unk04d0;
    unsigned int unk04d4;
    unsigned int unk04d8;
    unsigned int unk04dc;
    unsigned int unk04e0;
    unsigned int unk04e4;
    unsigned int unk04e8;
    unsigned int unk04ec;
    unsigned int unk04f0;
    unsigned int unk04f4;
    unsigned int unk04f8;
    unsigned int unk04fc;
    unsigned int unk0500;
    unsigned int unk0504;
    unsigned int unk0508;
    unsigned int unk050c;
    unsigned int unk0510;
    unsigned int unk0514;
    unsigned int unk0518;
    unsigned int unk051c;
    unsigned int unk0520;
    unsigned int unk0524;
    unsigned int unk0528;
    unsigned int unk052c;
    unsigned int unk0530;
    unsigned int unk0534;
    unsigned int unk0538;
    unsigned int unk053c;
    unsigned int unk0540;
    unsigned int unk0544;
    unsigned int unk0548;
    unsigned int unk054c;
    unsigned int unk0550;
    unsigned int unk0554;
    unsigned int unk0558;
    unsigned int unk055c;
    unsigned int unk0560;
    unsigned int unk0564;
    unsigned int unk0568;
    unsigned int unk056c;
    unsigned int unk0570;
    unsigned int unk0574;
    unsigned int unk0578;
    unsigned int unk057c;
    unsigned int unk0580;
    unsigned int unk0584;
    unsigned int unk0588;
    unsigned int unk058c;
    unsigned int unk0590;
    unsigned int unk0594;
    unsigned int unk0598;
    unsigned int unk059c;
    unsigned int unk05a0;
    unsigned int unk05a4;
    unsigned int unk05a8;
    unsigned int unk05ac;
    unsigned int unk05b0;
    unsigned int unk05b4;
    unsigned int unk05b8;
    unsigned int unk05bc;
    unsigned int unk05c0;
    unsigned int unk05c4;
    unsigned int unk05c8;
    unsigned int unk05cc;
    unsigned int unk05d0;
    unsigned int unk05d4;
    unsigned int unk05d8;
    unsigned int unk05dc;
    unsigned int unk05e0;
    unsigned int unk05e4;
    unsigned int unk05e8;
    unsigned int unk05ec;
    unsigned int unk05f0;
    unsigned int unk05f4;
    unsigned int unk05f8;
    unsigned int unk05fc;
    unsigned int unk0600;
    unsigned int unk0604;
    unsigned int unk0608;
    unsigned int unk060c;
    unsigned int unk0610;
    unsigned int unk0614;
    unsigned int unk0618;
    unsigned int unk061c;
    unsigned int unk0620;
    unsigned int unk0624;
    unsigned int unk0628;
    unsigned int unk062c;
    unsigned int unk0630;
    unsigned int unk0634;
    unsigned int unk0638;
    unsigned int unk063c;
    unsigned int unk0640;
    unsigned int unk0644;
    unsigned int unk0648;
    unsigned int unk064c;
    unsigned int unk0650;
    unsigned int unk0654;
    unsigned int unk0658;
    unsigned int unk065c;
    unsigned int unk0660;
    unsigned int unk0664;
    unsigned int unk0668;
    unsigned int unk066c;
    unsigned int unk0670;
    unsigned int unk0674;
    unsigned int unk0678;
    unsigned int unk067c;
    unsigned int unk0680;
    unsigned int unk0684;
    unsigned int unk0688;
    unsigned int unk068c;
    unsigned int unk0690;
    unsigned int unk0694;
    unsigned int unk0698;
    unsigned int unk069c;
    unsigned int unk06a0;
    unsigned int unk06a4;
    unsigned int unk06a8;
    unsigned int unk06ac;
    unsigned int unk06b0;
    unsigned int unk06b4;
    unsigned int unk06b8;
    unsigned int unk06bc;
    unsigned int unk06c0;
    unsigned int unk06c4;
    unsigned int unk06c8;
    unsigned int unk06cc;
    unsigned int unk06d0;
    unsigned int unk06d4;
    unsigned int unk06d8;
    unsigned int unk06dc;
    unsigned int unk06e0;
    unsigned int unk06e4;
    unsigned int unk06e8;
    unsigned int unk06ec;
    unsigned int unk06f0;
    unsigned int unk06f4;
    unsigned int unk06f8;
    unsigned int unk06fc;
    unsigned int unk0700;
    unsigned int unk0704;
    unsigned int unk0708;
    unsigned int unk070c;
    unsigned int unk0710;
    unsigned int unk0714;
    unsigned int unk0718;
    unsigned int unk071c;
    unsigned int unk0720;
    unsigned int unk0724;
    unsigned int unk0728;
    unsigned int unk072c;
    unsigned int unk0730;
    unsigned int unk0734;
    unsigned int unk0738;
    unsigned int unk073c;
    unsigned int unk0740;
    unsigned int unk0744;
    unsigned int unk0748;
    unsigned int unk074c;
    unsigned int unk0750;
    unsigned int unk0754;
    unsigned int unk0758;
    unsigned int unk075c;
    unsigned int unk0760;
    unsigned int unk0764;
    unsigned int unk0768;
    unsigned int unk076c;
    unsigned int unk0770;
    unsigned int unk0774;
    unsigned int unk0778;
    unsigned int unk077c;
    unsigned int unk0780;
    unsigned int unk0784;
    unsigned int unk0788;
    unsigned int unk078c;
    unsigned int unk0790;
    unsigned int unk0794;
    unsigned int unk0798;
    unsigned int unk079c;
    unsigned int unk07a0;
    unsigned int unk07a4;
    unsigned int unk07a8;
    unsigned int unk07ac;
    unsigned int unk07b0;
    unsigned int unk07b4;
    unsigned int unk07b8;
    unsigned int unk07bc;
    unsigned int unk07c0;
    unsigned int unk07c4;
    unsigned int unk07c8;
    unsigned int unk07cc;
    unsigned int unk07d0;
    unsigned int unk07d4;
    unsigned int unk07d8;
    unsigned int unk07dc;
    unsigned int unk07e0;
    unsigned int unk07e4;
    unsigned int unk07e8;
    unsigned int unk07ec;
    unsigned int unk07f0;
    unsigned int unk07f4;
    unsigned int unk07f8;
    unsigned int unk07fc;
    unsigned int unk0800;
    unsigned int unk0804;
    unsigned int unk0808;
    unsigned int unk080c;
    unsigned int unk0810;
    unsigned int unk0814;
    unsigned int unk0818;
    unsigned int unk081c;
    unsigned int unk0820;
    unsigned int unk0824;
    unsigned int unk0828;
    unsigned int unk082c;
    unsigned int unk0830;
    unsigned int unk0834;
    unsigned int unk0838;
    unsigned int unk083c;
    unsigned int unk0840;
    unsigned int unk0844;
    unsigned int unk0848;
    unsigned int unk084c;
    unsigned int unk0850;
    unsigned int unk0854;
    unsigned int unk0858;
    unsigned int unk085c;
    unsigned int unk0860;
    unsigned int unk0864;
    unsigned int unk0868;
    unsigned int unk086c;
    unsigned int unk0870;
    unsigned int unk0874;
    unsigned int unk0878;
    unsigned int unk087c;
    unsigned int unk0880;
    unsigned int unk0884;
    unsigned int unk0888;
    unsigned int unk088c;
    unsigned int unk0890;
    unsigned int unk0894;
    unsigned int unk0898;
    unsigned int unk089c;
    unsigned int unk08a0;
    unsigned int unk08a4;
    unsigned int unk08a8;
    unsigned int unk08ac;
    unsigned int unk08b0;
    unsigned int unk08b4;
    unsigned int unk08b8;
    unsigned int unk08bc;
    unsigned int unk08c0;
    unsigned int unk08c4;
    unsigned int unk08c8;
    unsigned int unk08cc;
    unsigned int unk08d0;
    unsigned int unk08d4;
    unsigned int unk08d8;
    unsigned int unk08dc;
    unsigned int unk08e0;
    unsigned int unk08e4;
    unsigned int unk08e8;
    unsigned int unk08ec;
    unsigned int unk08f0;
    unsigned int unk08f4;
    unsigned int unk08f8;
    unsigned int unk08fc;
    unsigned int unk0900;
    unsigned int unk0904;
    unsigned int unk0908;
    unsigned int unk090c;
    unsigned int unk0910;
    unsigned int unk0914;
    unsigned int unk0918;
    unsigned int unk091c;
    unsigned int unk0920;
    unsigned int unk0924;
    unsigned int unk0928;
    unsigned int unk092c;
    unsigned int unk0930;
    unsigned int unk0934;
    unsigned int unk0938;
    unsigned int unk093c;
    unsigned int unk0940;
    unsigned int unk0944;
    unsigned int unk0948;
    unsigned int unk094c;
    unsigned int unk0950;
    unsigned int unk0954;
    unsigned int unk0958;
    unsigned int unk095c;
    unsigned int unk0960;
    unsigned int unk0964;
    unsigned int unk0968;
    unsigned int unk096c;
    unsigned int unk0970;
    unsigned int unk0974;
    unsigned int unk0978;
    unsigned int unk097c;
    unsigned int unk0980;
    unsigned int unk0984;
    unsigned int unk0988;
    unsigned int unk098c;
    unsigned int unk0990;
    unsigned int unk0994;
    unsigned int unk0998;
    unsigned int unk099c;
    unsigned int unk09a0;
    unsigned int unk09a4;
    unsigned int unk09a8;
    unsigned int unk09ac;
    unsigned int unk09b0;
    unsigned int unk09b4;
    unsigned int unk09b8;
    unsigned int unk09bc;
    unsigned int unk09c0;
    unsigned int unk09c4;
    unsigned int unk09c8;
    unsigned int unk09cc;
    unsigned int unk09d0;
    unsigned int unk09d4;
    unsigned int unk09d8;
    unsigned int unk09dc;
    unsigned int unk09e0;
    unsigned int unk09e4;
    unsigned int unk09e8;
    unsigned int unk09ec;
    unsigned int unk09f0;
    unsigned int unk09f4;
    unsigned int unk09f8;
    unsigned int unk09fc;
    unsigned int unk0a00;
    unsigned int unk0a04;
    unsigned int unk0a08;
    unsigned int unk0a0c;
    unsigned int unk0a10;
    unsigned int unk0a14;
    unsigned int unk0a18;
    unsigned int unk0a1c;
    unsigned int unk0a20;
    unsigned int unk0a24;
    unsigned int unk0a28;
    unsigned int unk0a2c;
    unsigned int unk0a30;
    unsigned int unk0a34;
    unsigned int unk0a38;
    unsigned int unk0a3c;
    unsigned int unk0a40;
    unsigned int unk0a44;
    unsigned int unk0a48;
    unsigned int unk0a4c;
    unsigned int unk0a50;
    unsigned int unk0a54;
    unsigned int unk0a58;
    unsigned int unk0a5c;
    unsigned int unk0a60;
    unsigned int unk0a64;
    unsigned int unk0a68;
    unsigned int unk0a6c;
    unsigned int unk0a70;
    unsigned int unk0a74;
    unsigned int unk0a78;
    unsigned int unk0a7c;
    unsigned int unk0a80;
    unsigned int unk0a84;
    unsigned int unk0a88;
    unsigned int unk0a8c;
    unsigned int unk0a90;
    unsigned int unk0a94;
    unsigned int unk0a98;
    unsigned int unk0a9c;
    unsigned int unk0aa0;
    unsigned int unk0aa4;
    unsigned int unk0aa8;
    unsigned int unk0aac;
    unsigned int unk0ab0;
    unsigned int unk0ab4;
    unsigned int unk0ab8;
    unsigned int unk0abc;
    unsigned int unk0ac0;
    unsigned int unk0ac4;
    unsigned int unk0ac8;
    unsigned int unk0acc;
    unsigned int unk0ad0;
    unsigned int unk0ad4;
    unsigned int unk0ad8;
    unsigned int unk0adc;
    unsigned int unk0ae0;
    unsigned int unk0ae4;
    unsigned int unk0ae8;
    unsigned int unk0aec;
    unsigned int unk0af0;
    unsigned int unk0af4;
    unsigned int unk0af8;
    unsigned int unk0afc;
    unsigned int unk0b00;
    DeckArray playerBack;
    DeckArray opponentBack;
    DeckArray playerCards;
    DeckArray opponentCards;
    unsigned int unk0b44;
    unsigned int unk0b48;
    unsigned int unk0b4c;
    unsigned int unk0b50;
    unsigned int unk0b54;
    unsigned int unk0b58;
    unsigned int unk0b5c;
    unsigned int unk0b60;
    unsigned int unk0b64;
    unsigned int unk0b68;
    unsigned int unk0b6c;
    unsigned int unk0b70;
    unsigned int unk0b74;
    unsigned int unk0b78;
    unsigned int unk0b7c;
    unsigned int unk0b80;
    unsigned int unk0b84;
    unsigned int unk0b88;
    unsigned int unk0b8c;
    unsigned int unk0b90;
    unsigned int unk0b94;
    unsigned int unk0b98;
    unsigned int unk0b9c;
    unsigned int unk0ba0;
    unsigned int unk0ba4;
    unsigned int unk0ba8;
    unsigned int unk0bac;
    unsigned int unk0bb0;
    unsigned int unk0bb4;
    unsigned int unk0bb8;
    unsigned int unk0bbc;
    unsigned int unk0bc0;
    unsigned int unk0bc4;
    unsigned int unk0bc8;
    unsigned int unk0bcc;
    unsigned int unk0bd0;
    unsigned int unk0bd4;
    unsigned int unk0bd8;
    unsigned int unk0bdc;
    unsigned int unk0be0;
    unsigned int unk0be4;
    unsigned int unk0be8;
    unsigned int unk0bec;
    unsigned int unk0bf0;
    unsigned int unk0bf4;
    unsigned int unk0bf8;
    unsigned int unk0bfc;
    unsigned int unk0c00;
    unsigned int unk0c04;
    unsigned int unk0c08;
    unsigned int unk0c0c;
    unsigned int unk0c10;
    unsigned int unk0c14;
    unsigned int unk0c18;
    unsigned int unk0c1c;
    unsigned int unk0c20;
    unsigned int unk0c24;
    unsigned int unk0c28;
    unsigned int unk0c2c;
    unsigned int unk0c30;
    unsigned int unk0c34;
    unsigned int unk0c38;
    unsigned int unk0c3c;
    unsigned int unk0c40;
    unsigned int unk0c44;
    unsigned int unk0c48;
    unsigned int unk0c4c;
    unsigned int unk0c50;
    unsigned int unk0c54;
    unsigned int unk0c58;
    unsigned int unk0c5c;
    unsigned int unk0c60;
    unsigned int unk0c64;
    unsigned int unk0c68;
    unsigned int unk0c6c;
    unsigned int unk0c70;
    unsigned int unk0c74;
    unsigned int unk0c78;
    unsigned int unk0c7c;
    unsigned int unk0c80;
    unsigned int unk0c84;
    unsigned int unk0c88;
    unsigned int unk0c8c;
    unsigned int unk0c90;
    unsigned int unk0c94;
    unsigned int unk0c98;
    unsigned int unk0c9c;
    unsigned int unk0ca0;
    unsigned int unk0ca4;
    unsigned int unk0ca8;
    unsigned int unk0cac;
    unsigned int unk0cb0;
    unsigned int unk0cb4;
    unsigned int unk0cb8;
    unsigned int unk0cbc;
    unsigned int unk0cc0;
    unsigned int unk0cc4;
    unsigned int unk0cc8;
    unsigned int unk0ccc;
    unsigned int unk0cd0;
    unsigned int unk0cd4;
    unsigned int unk0cd8;
    unsigned int unk0cdc;
    unsigned int unk0ce0;
    unsigned int unk0ce4;
    unsigned int unk0ce8;
    unsigned int unk0cec;
    unsigned int unk0cf0;
    unsigned int unk0cf4;
    unsigned int unk0cf8;
    unsigned int unk0cfc;
    unsigned int unk0d00;
    unsigned int unk0d04;
    unsigned int unk0d08;
    unsigned int unk0d0c;
    unsigned int unk0d10;
    unsigned int unk0d14;
    unsigned int unk0d18;
    unsigned int unk0d1c;
    unsigned int unk0d20;
    unsigned int unk0d24;
    unsigned int unk0d28;
    unsigned int unk0d2c;
    unsigned int unk0d30;
    unsigned int unk0d34;
    unsigned int unk0d38;
    unsigned int unk0d3c;
    unsigned int unk0d40;
    unsigned int unk0d44;
    unsigned int unk0d48;
    unsigned int unk0d4c;
    unsigned int unk0d50;
    unsigned int unk0d54;
    unsigned int unk0d58;
    unsigned int unk0d5c;
    unsigned int unk0d60;
    unsigned int unk0d64;
    unsigned int unk0d68;
    unsigned int unk0d6c;
    unsigned int unk0d70;
    unsigned int unk0d74;
    unsigned int unk0d78;
    unsigned int unk0d7c;
    unsigned int unk0d80;
    unsigned int unk0d84;
    unsigned int unk0d88;
    unsigned int unk0d8c;
    unsigned int unk0d90;
    unsigned int unk0d94;
    unsigned int unk0d98;
    unsigned int unk0d9c;
    unsigned int unk0da0;
    unsigned int unk0da4;
    unsigned int unk0da8;
    unsigned int unk0dac;
    unsigned int unk0db0;
    unsigned int unk0db4;
    unsigned int unk0db8;
    unsigned int unk0dbc;
    unsigned int unk0dc0;
    unsigned int unk0dc4;
    unsigned int unk0dc8;
    unsigned int unk0dcc;
    unsigned int unk0dd0;
    unsigned int unk0dd4;
    unsigned int unk0dd8;
    unsigned int unk0ddc;
    unsigned int unk0de0;
    unsigned int unk0de4;
    unsigned int unk0de8;
    unsigned int unk0dec;
    unsigned int unk0df0;
    unsigned int unk0df4;
    unsigned int unk0df8;
    unsigned int unk0dfc;
    unsigned int unk0e00;
    unsigned int unk0e04;
    unsigned int unk0e08;
    unsigned int unk0e0c;
    unsigned int unk0e10;
    unsigned int unk0e14;
    unsigned int unk0e18;
    unsigned int unk0e1c;
    unsigned int unk0e20;
    unsigned int unk0e24;
    unsigned int unk0e28;
    unsigned int unk0e2c;
    unsigned int unk0e30;
    unsigned int unk0e34;
    unsigned int unk0e38;
    unsigned int unk0e3c;
    unsigned int m_uiPlayerIndex;
    unsigned int opponentIndex;
    void UpdateDeckTextures(bool player);
};
static const char textureLiteral0[] = "Player-Deck_06:5";
static const char textureLiteral1[] = "%s%s";
static const char textureLiteral2[] = "Textures\\";
static const char textureLiteral3[] = "Player-Deck_Back:0";
static const char textureLiteral4[] = "Opponent-Deck_Back:0";
static const char textureLiteral5[] = "Textures\\%s";
// Finds the deck and deck-back scene objects under the player or opponent root and sets their texture properties from card/back image paths when available.
// @fnv 0x0074d190
void CardMenuTexture::UpdateDeckTextures(bool player)
{
    SceneObject* root = player ? playerRoot : opponentRoot;
    char path2[260];
    char normalized3[260];
    player ? strcpy_s(path2, 260, textureLiteral0) : strcpy_s(path2, 260, opponentDeckName);
    SceneObject* object5 = FindObject(root, path2);
    ShaderProperty* property3 = (!object5->GetProperty(3) ? false
                                                          : (object5->GetProperty(3)->FUN_00441110() >= 8 &&
                                                             object5->GetProperty(3)->FUN_00441110() <= 12))
                                    ? object5->GetProperty(3)
                                    : 0;
    TextureRef texture(0);
    if (property3 && (player ? playerCards.FUN_0044ddc0() : opponentCards.FUN_0044ddc0()) > 4)
    {
        if (player)
            FormatPath(path2, 260, textureLiteral1, textureLiteral2,
                       playerCards.FUN_006a7ad0(4)->FUN_0050d100()->GetFullName());
        else
            FormatPath(path2, 260, textureLiteral1, textureLiteral2,
                       opponentCards.FUN_006a7ad0(4)->FUN_00503650()->GetFullName());
        NormalizePath(path2, normalized3, 260);
        g_TES->CreateTextureImage(normalized3, texture, false, false);
        if (texture)
            property3->SetTexture(0, 0, texture);
    }
    player ? strcpy_s(path2, 260, textureLiteral3) : strcpy_s(path2, 260, textureLiteral4);
    object5 = FindObject(root, path2);
    property3 = (!object5->GetProperty(3)
                     ? false
                     : (object5->GetProperty(3)->FUN_00441110() >= 8 && object5->GetProperty(3)->FUN_00441110() <= 12))
                    ? object5->GetProperty(3)
                    : 0;
    texture = 0;
    if (property3 && (player ? playerBack.FUN_0044ddc0() > 0 : opponentBack.FUN_0044ddc0() > 0))
    {
        if (player)
            FormatPath(path2, 260, textureLiteral5,
                       playerBack.FUN_006a7ad0(m_uiPlayerIndex)->FUN_00503650()->GetFullName());
        else
            FormatPath(path2, 260, textureLiteral5,
                       opponentBack.FUN_006a7ad0(opponentIndex)->FUN_00503650()->GetFullName());
        NormalizePath(path2, normalized3, 260);
        g_TES->CreateTextureImage(normalized3, texture, false, false);
        if (texture)
            property3->SetTexture(0, 0, texture);
    }
    else
    {
        object5->FUN_00450f90(true);
        NiUpdateData update(0.0f, false, false);
        object5->Update(update);
    }
}

namespace fnv_0074d730 {
struct TexName
{
    const char* FUN_00408da0();
};
struct CardTex
{
    TexName* FUN_0050d100();
    TexName* FUN_00503650();
};
struct TexArray
{
    unsigned int u00, u04, u08, u0c;
    unsigned int FUN_0044ddc0();
    CardTex*& FUN_006a7ad0(int);
};
struct Texture
{
};
struct TexturePtr
{
    Texture* value;
    TexturePtr(Texture*);
    ~TexturePtr();
    operator Texture*() const;
};
struct UpdateInfo
{
    float time;
    bool a, b, c, d, e;
    UpdateInfo(float, bool, bool);
};
struct Shader
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
    virtual void setTexture(int, int, Texture*);
    int FUN_00441110();
};
struct Scene
{
    Shader* GetProperty(int);
    void FUN_00450f90(bool);
    void update(const UpdateInfo&);
};
Scene* __cdecl FUN_004aae30(Scene*, const char*);
int __cdecl formatDeck(char*, unsigned int, const char*, ...);
int __cdecl strcpy_s(char*, unsigned int, const char*);
void __cdecl normalizeDeck(char*, char*, unsigned int);
struct TextureManager
{
    void load(char*, TexturePtr&, bool, bool);
};
extern TextureManager* g_TES;
extern bool DAT_011d9184;
struct DeckMenu
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003c;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004c;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005c;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006c;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007c;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008c;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009c;
    unsigned int unk00a0;
    unsigned int unk00a4;
    unsigned int unk00a8;
    unsigned int unk00ac;
    unsigned int unk00b0;
    unsigned int unk00b4;
    unsigned int unk00b8;
    unsigned int unk00bc;
    unsigned int unk00c0;
    unsigned int unk00c4;
    unsigned int unk00c8;
    unsigned int unk00cc;
    unsigned int unk00d0;
    unsigned int unk00d4;
    unsigned int unk00d8;
    unsigned int unk00dc;
    unsigned int unk00e0;
    unsigned int unk00e4;
    unsigned int unk00e8;
    unsigned int unk00ec;
    unsigned int unk00f0;
    unsigned int unk00f4;
    unsigned int unk00f8;
    unsigned int unk00fc;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010c;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011c;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012c;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013c;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014c;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015c;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016c;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017c;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018c;
    Scene* playerRoot;
    Scene* opponentRoot;
    unsigned int unk0198;
    unsigned int unk019c;
    unsigned int unk01a0;
    unsigned int unk01a4;
    unsigned int unk01a8;
    unsigned int unk01ac;
    unsigned int unk01b0;
    unsigned int unk01b4;
    unsigned int unk01b8;
    unsigned int unk01bc;
    unsigned int unk01c0;
    unsigned int unk01c4;
    unsigned int unk01c8;
    unsigned int unk01cc;
    unsigned int unk01d0;
    unsigned int unk01d4;
    unsigned int unk01d8;
    unsigned int unk01dc;
    unsigned int unk01e0;
    unsigned int unk01e4;
    unsigned int unk01e8;
    unsigned int unk01ec;
    unsigned int unk01f0;
    unsigned int unk01f4;
    unsigned int unk01f8;
    unsigned int unk01fc;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020c;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021c;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022c;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023c;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024c;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025c;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026c;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027c;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028c;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029c;
    unsigned int unk02a0;
    unsigned int unk02a4;
    unsigned int unk02a8;
    unsigned int unk02ac;
    unsigned int unk02b0;
    unsigned int unk02b4;
    unsigned int unk02b8;
    unsigned int unk02bc;
    unsigned int unk02c0;
    unsigned int unk02c4;
    unsigned int unk02c8;
    unsigned int unk02cc;
    unsigned int unk02d0;
    unsigned int unk02d4;
    unsigned int unk02d8;
    unsigned int unk02dc;
    unsigned int unk02e0;
    unsigned int unk02e4;
    unsigned int unk02e8;
    unsigned int unk02ec;
    unsigned int unk02f0;
    unsigned int unk02f4;
    unsigned int unk02f8;
    unsigned int unk02fc;
    unsigned int unk0300;
    unsigned int unk0304;
    unsigned int unk0308;
    unsigned int unk030c;
    unsigned int unk0310;
    unsigned int unk0314;
    unsigned int unk0318;
    unsigned int unk031c;
    unsigned int unk0320;
    unsigned int unk0324;
    unsigned int unk0328;
    unsigned int unk032c;
    unsigned int unk0330;
    unsigned int unk0334;
    unsigned int unk0338;
    unsigned int unk033c;
    unsigned int unk0340;
    unsigned int unk0344;
    unsigned int unk0348;
    unsigned int unk034c;
    unsigned int unk0350;
    unsigned int unk0354;
    unsigned int unk0358;
    unsigned int unk035c;
    unsigned int unk0360;
    unsigned int unk0364;
    unsigned int unk0368;
    unsigned int unk036c;
    unsigned int unk0370;
    unsigned int unk0374;
    unsigned int unk0378;
    unsigned int unk037c;
    unsigned int unk0380;
    unsigned int unk0384;
    unsigned int unk0388;
    unsigned int unk038c;
    unsigned int unk0390;
    unsigned int unk0394;
    unsigned int unk0398;
    unsigned int unk039c;
    unsigned int unk03a0;
    unsigned int unk03a4;
    unsigned int unk03a8;
    unsigned int unk03ac;
    unsigned int unk03b0;
    unsigned int unk03b4;
    unsigned int unk03b8;
    unsigned int unk03bc;
    unsigned int unk03c0;
    unsigned int unk03c4;
    unsigned int unk03c8;
    unsigned int unk03cc;
    unsigned int unk03d0;
    unsigned int unk03d4;
    unsigned int unk03d8;
    unsigned int unk03dc;
    unsigned int unk03e0;
    unsigned int unk03e4;
    unsigned int unk03e8;
    unsigned int unk03ec;
    unsigned int unk03f0;
    unsigned int unk03f4;
    unsigned int unk03f8;
    unsigned int unk03fc;
    unsigned int unk0400;
    unsigned int unk0404;
    unsigned int unk0408;
    unsigned int unk040c;
    unsigned int unk0410;
    unsigned int unk0414;
    unsigned int unk0418;
    unsigned int unk041c;
    unsigned int unk0420;
    unsigned int unk0424;
    unsigned int unk0428;
    unsigned int unk042c;
    unsigned int unk0430;
    unsigned int unk0434;
    unsigned int unk0438;
    unsigned int unk043c;
    unsigned int unk0440;
    unsigned int unk0444;
    unsigned int unk0448;
    unsigned int unk044c;
    unsigned int unk0450;
    unsigned int unk0454;
    unsigned int unk0458;
    unsigned int unk045c;
    unsigned int unk0460;
    unsigned int unk0464;
    unsigned int unk0468;
    unsigned int unk046c;
    unsigned int unk0470;
    unsigned int unk0474;
    unsigned int unk0478;
    unsigned int unk047c;
    unsigned int unk0480;
    unsigned int unk0484;
    unsigned int unk0488;
    unsigned int unk048c;
    unsigned int unk0490;
    unsigned int unk0494;
    unsigned int unk0498;
    unsigned int unk049c;
    unsigned int unk04a0;
    unsigned int unk04a4;
    unsigned int unk04a8;
    unsigned int unk04ac;
    unsigned int unk04b0;
    unsigned int unk04b4;
    unsigned int unk04b8;
    unsigned int unk04bc;
    unsigned int unk04c0;
    unsigned int unk04c4;
    unsigned int unk04c8;
    unsigned int unk04cc;
    unsigned int unk04d0;
    unsigned int unk04d4;
    unsigned int unk04d8;
    unsigned int unk04dc;
    unsigned int unk04e0;
    unsigned int unk04e4;
    unsigned int unk04e8;
    unsigned int unk04ec;
    unsigned int unk04f0;
    unsigned int unk04f4;
    unsigned int unk04f8;
    unsigned int unk04fc;
    unsigned int unk0500;
    unsigned int unk0504;
    unsigned int unk0508;
    unsigned int unk050c;
    unsigned int unk0510;
    unsigned int unk0514;
    unsigned int unk0518;
    unsigned int unk051c;
    unsigned int unk0520;
    unsigned int unk0524;
    unsigned int unk0528;
    unsigned int unk052c;
    unsigned int unk0530;
    unsigned int unk0534;
    unsigned int unk0538;
    unsigned int unk053c;
    unsigned int unk0540;
    unsigned int unk0544;
    unsigned int unk0548;
    unsigned int unk054c;
    unsigned int unk0550;
    unsigned int unk0554;
    unsigned int unk0558;
    unsigned int unk055c;
    unsigned int unk0560;
    unsigned int unk0564;
    unsigned int unk0568;
    unsigned int unk056c;
    unsigned int unk0570;
    unsigned int unk0574;
    unsigned int unk0578;
    unsigned int unk057c;
    unsigned int unk0580;
    unsigned int unk0584;
    unsigned int unk0588;
    unsigned int unk058c;
    unsigned int unk0590;
    unsigned int unk0594;
    unsigned int unk0598;
    unsigned int unk059c;
    unsigned int unk05a0;
    unsigned int unk05a4;
    unsigned int unk05a8;
    unsigned int unk05ac;
    unsigned int unk05b0;
    unsigned int unk05b4;
    unsigned int unk05b8;
    unsigned int unk05bc;
    unsigned int unk05c0;
    unsigned int unk05c4;
    unsigned int unk05c8;
    unsigned int unk05cc;
    unsigned int unk05d0;
    unsigned int unk05d4;
    unsigned int unk05d8;
    unsigned int unk05dc;
    unsigned int unk05e0;
    unsigned int unk05e4;
    unsigned int unk05e8;
    unsigned int unk05ec;
    unsigned int unk05f0;
    unsigned int unk05f4;
    unsigned int unk05f8;
    unsigned int unk05fc;
    unsigned int unk0600;
    unsigned int unk0604;
    unsigned int unk0608;
    unsigned int unk060c;
    unsigned int unk0610;
    unsigned int unk0614;
    unsigned int unk0618;
    unsigned int unk061c;
    unsigned int unk0620;
    unsigned int unk0624;
    unsigned int unk0628;
    unsigned int unk062c;
    unsigned int unk0630;
    unsigned int unk0634;
    unsigned int unk0638;
    unsigned int unk063c;
    unsigned int unk0640;
    unsigned int unk0644;
    unsigned int unk0648;
    unsigned int unk064c;
    unsigned int unk0650;
    unsigned int unk0654;
    unsigned int unk0658;
    unsigned int unk065c;
    unsigned int unk0660;
    unsigned int unk0664;
    unsigned int unk0668;
    unsigned int unk066c;
    unsigned int unk0670;
    unsigned int unk0674;
    unsigned int unk0678;
    unsigned int unk067c;
    unsigned int unk0680;
    unsigned int unk0684;
    unsigned int unk0688;
    unsigned int unk068c;
    unsigned int unk0690;
    unsigned int unk0694;
    unsigned int unk0698;
    unsigned int unk069c;
    unsigned int unk06a0;
    unsigned int unk06a4;
    unsigned int unk06a8;
    unsigned int unk06ac;
    unsigned int unk06b0;
    unsigned int unk06b4;
    unsigned int unk06b8;
    unsigned int unk06bc;
    unsigned int unk06c0;
    unsigned int unk06c4;
    unsigned int unk06c8;
    unsigned int unk06cc;
    unsigned int unk06d0;
    unsigned int unk06d4;
    unsigned int unk06d8;
    unsigned int unk06dc;
    unsigned int unk06e0;
    unsigned int unk06e4;
    unsigned int unk06e8;
    unsigned int unk06ec;
    unsigned int unk06f0;
    unsigned int unk06f4;
    unsigned int unk06f8;
    unsigned int unk06fc;
    unsigned int unk0700;
    unsigned int unk0704;
    unsigned int unk0708;
    unsigned int unk070c;
    unsigned int unk0710;
    unsigned int unk0714;
    unsigned int unk0718;
    unsigned int unk071c;
    unsigned int unk0720;
    unsigned int unk0724;
    unsigned int unk0728;
    unsigned int unk072c;
    unsigned int unk0730;
    unsigned int unk0734;
    unsigned int unk0738;
    unsigned int unk073c;
    unsigned int unk0740;
    unsigned int unk0744;
    unsigned int unk0748;
    unsigned int unk074c;
    unsigned int unk0750;
    unsigned int unk0754;
    unsigned int unk0758;
    unsigned int unk075c;
    unsigned int unk0760;
    unsigned int unk0764;
    unsigned int unk0768;
    unsigned int unk076c;
    unsigned int unk0770;
    unsigned int unk0774;
    unsigned int unk0778;
    unsigned int unk077c;
    unsigned int unk0780;
    unsigned int unk0784;
    unsigned int unk0788;
    unsigned int unk078c;
    unsigned int unk0790;
    unsigned int unk0794;
    unsigned int unk0798;
    unsigned int unk079c;
    unsigned int unk07a0;
    unsigned int unk07a4;
    unsigned int unk07a8;
    unsigned int unk07ac;
    unsigned int unk07b0;
    unsigned int unk07b4;
    unsigned int unk07b8;
    unsigned int unk07bc;
    unsigned int unk07c0;
    unsigned int unk07c4;
    unsigned int unk07c8;
    unsigned int unk07cc;
    unsigned int unk07d0;
    unsigned int unk07d4;
    unsigned int unk07d8;
    unsigned int unk07dc;
    unsigned int unk07e0;
    unsigned int unk07e4;
    unsigned int unk07e8;
    unsigned int unk07ec;
    unsigned int unk07f0;
    unsigned int unk07f4;
    unsigned int unk07f8;
    unsigned int unk07fc;
    unsigned int unk0800;
    unsigned int unk0804;
    unsigned int unk0808;
    unsigned int unk080c;
    unsigned int unk0810;
    unsigned int unk0814;
    unsigned int unk0818;
    unsigned int unk081c;
    unsigned int unk0820;
    unsigned int unk0824;
    unsigned int unk0828;
    unsigned int unk082c;
    unsigned int unk0830;
    unsigned int unk0834;
    unsigned int unk0838;
    unsigned int unk083c;
    unsigned int unk0840;
    unsigned int unk0844;
    unsigned int unk0848;
    unsigned int unk084c;
    unsigned int unk0850;
    unsigned int unk0854;
    unsigned int unk0858;
    unsigned int unk085c;
    unsigned int unk0860;
    unsigned int unk0864;
    unsigned int unk0868;
    unsigned int unk086c;
    unsigned int unk0870;
    unsigned int unk0874;
    unsigned int unk0878;
    unsigned int unk087c;
    unsigned int unk0880;
    unsigned int unk0884;
    unsigned int unk0888;
    unsigned int unk088c;
    unsigned int unk0890;
    unsigned int unk0894;
    unsigned int unk0898;
    unsigned int unk089c;
    unsigned int unk08a0;
    unsigned int unk08a4;
    unsigned int unk08a8;
    unsigned int unk08ac;
    unsigned int unk08b0;
    unsigned int unk08b4;
    unsigned int unk08b8;
    unsigned int unk08bc;
    unsigned int unk08c0;
    unsigned int unk08c4;
    unsigned int unk08c8;
    unsigned int unk08cc;
    unsigned int unk08d0;
    unsigned int unk08d4;
    unsigned int unk08d8;
    unsigned int unk08dc;
    unsigned int unk08e0;
    unsigned int unk08e4;
    unsigned int unk08e8;
    unsigned int unk08ec;
    unsigned int unk08f0;
    unsigned int unk08f4;
    unsigned int unk08f8;
    unsigned int unk08fc;
    unsigned int unk0900;
    unsigned int unk0904;
    unsigned int unk0908;
    unsigned int unk090c;
    unsigned int unk0910;
    unsigned int unk0914;
    unsigned int unk0918;
    unsigned int unk091c;
    unsigned int unk0920;
    unsigned int unk0924;
    unsigned int unk0928;
    unsigned int unk092c;
    unsigned int unk0930;
    unsigned int unk0934;
    unsigned int unk0938;
    unsigned int unk093c;
    unsigned int unk0940;
    unsigned int unk0944;
    unsigned int unk0948;
    unsigned int unk094c;
    unsigned int unk0950;
    unsigned int unk0954;
    unsigned int unk0958;
    unsigned int unk095c;
    unsigned int unk0960;
    unsigned int unk0964;
    unsigned int unk0968;
    unsigned int unk096c;
    unsigned int unk0970;
    unsigned int unk0974;
    unsigned int unk0978;
    unsigned int unk097c;
    unsigned int unk0980;
    unsigned int unk0984;
    unsigned int unk0988;
    unsigned int unk098c;
    unsigned int unk0990;
    unsigned int unk0994;
    unsigned int unk0998;
    unsigned int unk099c;
    unsigned int unk09a0;
    unsigned int unk09a4;
    unsigned int unk09a8;
    unsigned int unk09ac;
    unsigned int unk09b0;
    unsigned int unk09b4;
    unsigned int unk09b8;
    unsigned int unk09bc;
    unsigned int unk09c0;
    unsigned int unk09c4;
    unsigned int unk09c8;
    unsigned int unk09cc;
    unsigned int unk09d0;
    unsigned int unk09d4;
    unsigned int unk09d8;
    unsigned int unk09dc;
    unsigned int unk09e0;
    unsigned int unk09e4;
    unsigned int unk09e8;
    unsigned int unk09ec;
    unsigned int unk09f0;
    unsigned int unk09f4;
    unsigned int unk09f8;
    unsigned int unk09fc;
    unsigned int unk0a00;
    unsigned int unk0a04;
    unsigned int unk0a08;
    unsigned int unk0a0c;
    unsigned int unk0a10;
    unsigned int unk0a14;
    unsigned int unk0a18;
    unsigned int unk0a1c;
    unsigned int unk0a20;
    unsigned int unk0a24;
    unsigned int unk0a28;
    unsigned int unk0a2c;
    unsigned int unk0a30;
    unsigned int unk0a34;
    unsigned int unk0a38;
    unsigned int unk0a3c;
    unsigned int unk0a40;
    unsigned int unk0a44;
    unsigned int unk0a48;
    unsigned int unk0a4c;
    unsigned int unk0a50;
    unsigned int unk0a54;
    unsigned int unk0a58;
    unsigned int unk0a5c;
    unsigned int unk0a60;
    unsigned int unk0a64;
    unsigned int unk0a68;
    unsigned int unk0a6c;
    unsigned int unk0a70;
    unsigned int unk0a74;
    unsigned int unk0a78;
    unsigned int unk0a7c;
    unsigned int unk0a80;
    unsigned int unk0a84;
    unsigned int unk0a88;
    unsigned int unk0a8c;
    unsigned int unk0a90;
    unsigned int unk0a94;
    unsigned int unk0a98;
    unsigned int unk0a9c;
    unsigned int unk0aa0;
    unsigned int unk0aa4;
    unsigned int unk0aa8;
    unsigned int unk0aac;
    unsigned int unk0ab0;
    unsigned int unk0ab4;
    unsigned int unk0ab8;
    unsigned int unk0abc;
    unsigned int unk0ac0;
    unsigned int unk0ac4;
    unsigned int unk0ac8;
    unsigned int unk0acc;
    unsigned int unk0ad0;
    unsigned int unk0ad4;
    unsigned int unk0ad8;
    unsigned int unk0adc;
    unsigned int unk0ae0;
    unsigned int unk0ae4;
    unsigned int unk0ae8;
    unsigned int unk0aec;
    unsigned int unk0af0;
    unsigned int unk0af4;
    unsigned int unk0af8;
    unsigned int unk0afc;
    unsigned int unk0b00;
    TexArray playerCards;
    TexArray opponentCards;
    TexArray playerDeck;
    TexArray opponentDeck;
    unsigned int unk0b44;
    unsigned int unk0b48;
    unsigned int unk0b4c;
    unsigned int unk0b50;
    unsigned int unk0b54;
    unsigned int unk0b58;
    unsigned int unk0b5c;
    unsigned int unk0b60;
    unsigned int unk0b64;
    unsigned int unk0b68;
    unsigned int unk0b6c;
    unsigned int unk0b70;
    unsigned int unk0b74;
    unsigned int unk0b78;
    unsigned int unk0b7c;
    unsigned int unk0b80;
    unsigned int unk0b84;
    unsigned int unk0b88;
    unsigned int unk0b8c;
    unsigned int unk0b90;
    unsigned int unk0b94;
    unsigned int unk0b98;
    unsigned int unk0b9c;
    unsigned int unk0ba0;
    unsigned int unk0ba4;
    unsigned int unk0ba8;
    unsigned int unk0bac;
    unsigned int unk0bb0;
    unsigned int unk0bb4;
    unsigned int unk0bb8;
    unsigned int unk0bbc;
    unsigned int unk0bc0;
    unsigned int unk0bc4;
    unsigned int unk0bc8;
    unsigned int unk0bcc;
    unsigned int unk0bd0;
    unsigned int unk0bd4;
    unsigned int unk0bd8;
    unsigned int unk0bdc;
    unsigned int unk0be0;
    unsigned int unk0be4;
    unsigned int unk0be8;
    unsigned int unk0bec;
    unsigned int unk0bf0;
    unsigned int unk0bf4;
    unsigned int unk0bf8;
    unsigned int unk0bfc;
    unsigned int unk0c00;
    unsigned int unk0c04;
    unsigned int unk0c08;
    unsigned int unk0c0c;
    unsigned int unk0c10;
    unsigned int unk0c14;
    unsigned int unk0c18;
    unsigned int unk0c1c;
    unsigned int unk0c20;
    unsigned int unk0c24;
    unsigned int unk0c28;
    unsigned int unk0c2c;
    unsigned int unk0c30;
    unsigned int unk0c34;
    unsigned int unk0c38;
    unsigned int unk0c3c;
    unsigned int unk0c40;
    unsigned int unk0c44;
    unsigned int unk0c48;
    unsigned int unk0c4c;
    unsigned int unk0c50;
    unsigned int unk0c54;
    unsigned int unk0c58;
    unsigned int unk0c5c;
    unsigned int unk0c60;
    unsigned int unk0c64;
    unsigned int unk0c68;
    unsigned int unk0c6c;
    unsigned int unk0c70;
    unsigned int unk0c74;
    unsigned int unk0c78;
    unsigned int unk0c7c;
    unsigned int unk0c80;
    unsigned int unk0c84;
    unsigned int unk0c88;
    unsigned int unk0c8c;
    unsigned int unk0c90;
    unsigned int unk0c94;
    unsigned int unk0c98;
    unsigned int unk0c9c;
    unsigned int unk0ca0;
    unsigned int unk0ca4;
    unsigned int unk0ca8;
    unsigned int unk0cac;
    unsigned int unk0cb0;
    unsigned int unk0cb4;
    unsigned int unk0cb8;
    unsigned int unk0cbc;
    unsigned int unk0cc0;
    unsigned int unk0cc4;
    unsigned int unk0cc8;
    unsigned int unk0ccc;
    unsigned int unk0cd0;
    unsigned int unk0cd4;
    unsigned int unk0cd8;
    unsigned int unk0cdc;
    unsigned int unk0ce0;
    unsigned int unk0ce4;
    unsigned int unk0ce8;
    unsigned int unk0cec;
    unsigned int unk0cf0;
    unsigned int unk0cf4;
    unsigned int unk0cf8;
    unsigned int unk0cfc;
    unsigned int unk0d00;
    unsigned int unk0d04;
    unsigned int unk0d08;
    unsigned int unk0d0c;
    unsigned int unk0d10;
    unsigned int unk0d14;
    unsigned int unk0d18;
    unsigned int unk0d1c;
    unsigned int unk0d20;
    unsigned int unk0d24;
    unsigned int unk0d28;
    unsigned int unk0d2c;
    unsigned int unk0d30;
    unsigned int unk0d34;
    unsigned int unk0d38;
    unsigned int unk0d3c;
    unsigned int unk0d40;
    unsigned int unk0d44;
    unsigned int unk0d48;
    unsigned int unk0d4c;
    unsigned int unk0d50;
    unsigned int unk0d54;
    unsigned int unk0d58;
    unsigned int unk0d5c;
    unsigned int unk0d60;
    unsigned int unk0d64;
    unsigned int unk0d68;
    unsigned int unk0d6c;
    unsigned int unk0d70;
    unsigned int unk0d74;
    unsigned int unk0d78;
    unsigned int unk0d7c;
    unsigned int unk0d80;
    unsigned int unk0d84;
    unsigned int unk0d88;
    unsigned int unk0d8c;
    unsigned int unk0d90;
    unsigned int unk0d94;
    unsigned int unk0d98;
    unsigned int unk0d9c;
    unsigned int unk0da0;
    unsigned int unk0da4;
    unsigned int unk0da8;
    unsigned int unk0dac;
    unsigned int unk0db0;
    unsigned int unk0db4;
    unsigned int unk0db8;
    unsigned int unk0dbc;
    unsigned int unk0dc0;
    unsigned int unk0dc4;
    unsigned int unk0dc8;
    unsigned int unk0dcc;
    unsigned int unk0dd0;
    unsigned int unk0dd4;
    unsigned int unk0dd8;
    unsigned int unk0ddc;
    unsigned int unk0de0;
    unsigned int unk0de4;
    unsigned int unk0de8;
    unsigned int unk0dec;
    unsigned int unk0df0;
    unsigned int unk0df4;
    unsigned int unk0df8;
    unsigned int unk0dfc;
    unsigned int unk0e00;
    unsigned int unk0e04;
    unsigned int unk0e08;
    unsigned int unk0e0c;
    unsigned int unk0e10;
    unsigned int unk0e14;
    unsigned int unk0e18;
    unsigned int unk0e1c;
    unsigned int unk0e20;
    unsigned int unk0e24;
    unsigned int unk0e28;
    unsigned int unk0e2c;
    unsigned int unk0e30;
    unsigned int unk0e34;
    unsigned int unk0e38;
    unsigned int unk0e3c;
    int playerSelection;
    int opponentSelection;
    bool FUN_00740f10(unsigned int);
    void UpdateDeckCardNodes(bool, int);
};

// @fnv 0x0074d730
void DeckMenu::UpdateDeckCardNodes(bool player, int unused)
{
    char nodeName[260];
    {
        char texturePath[260];
        Scene* node;
        {
            Shader* l;
            int e = player ? playerDeck.FUN_0044ddc0() : opponentDeck.FUN_0044ddc0();
            Scene* c = player ? playerRoot : opponentRoot;
            int j;
            for (j = 0; j < 8; j++)
            {
                if (player)
                    formatDeck(nodeName, 260, "Player-Deck_0%i:%i", j + 1, j);
                else
                    formatDeck(nodeName, 260, "Opponent-Deck_0%i:%i", j + 1, j);
                node = FUN_004aae30(c, nodeName);
                if (j < e)
                {
                    l = (!node->GetProperty(3) ? 0
                                               : (node->GetProperty(3)->FUN_00441110() >= 8 &&
                                                  node->GetProperty(3)->FUN_00441110() <= 12))
                            ? node->GetProperty(3)
                            : 0;
                    TexturePtr texture(0);
                    if (l)
                    {
                        if (player)
                            formatDeck(nodeName, 260, "Textures\\%s",
                                       playerDeck.FUN_006a7ad0(j)->FUN_0050d100()->FUN_00408da0());
                        else if (DAT_011d9184)
                            formatDeck(nodeName, 260, "Textures\\%s",
                                       opponentDeck.FUN_006a7ad0(j)->FUN_0050d100()->FUN_00408da0());
                        else
                            formatDeck(nodeName, 260, "Textures\\%s",
                                       opponentDeck.FUN_006a7ad0(j)->FUN_00503650()->FUN_00408da0());
                        normalizeDeck(nodeName, texturePath, 260);
                        g_TES->load(texturePath, texture, false, false);
                        if (texture)
                            l->setTexture(0, 0, texture);
                    }
                }
                else if (FUN_00740f10(0x800) && j != 5)
                {
                    node->FUN_00450f90(true);
                    UpdateInfo ba(0.0f, false, false);
                    node->update(ba);
                    if (player)
                        formatDeck(nodeName, 260, "Player-Deck_0%i_Shadow:0", j + 1);
                    else
                        formatDeck(nodeName, 260, "Opponent-Deck_0%i_Shadow:0", j + 1);
                    node = FUN_004aae30(c, nodeName);
                    node->FUN_00450f90(true);
                    UpdateInfo b(0.0f, false, false);
                    node->update(b);
                }
                else if (!FUN_00740f10(0x800) && e < 5)
                {
                    node->FUN_00450f90(true);
                    UpdateInfo ba(0.0f, false, false);
                    node->update(ba);
                    if (player)
                        formatDeck(nodeName, 260, "Player-Deck_0%i_Shadow:0", j + 1);
                    else
                        formatDeck(nodeName, 260, "Opponent-Deck_0%i_Shadow:0", j + 1);
                    node = FUN_004aae30(c, nodeName);
                    node->FUN_00450f90(true);
                    UpdateInfo b(0.0f, false, false);
                    node->update(b);
                }
            }
            if (!FUN_00740f10(0x800))
            {
                player ? strcpy_s(nodeName, 260, "Player-Deck_06:5") : strcpy_s(nodeName, 260, "Opponent-Deck_06:5");
                node = FUN_004aae30(c, nodeName);
                l = (!node->GetProperty(3)
                         ? 0
                         : (node->GetProperty(3)->FUN_00441110() >= 8 && node->GetProperty(3)->FUN_00441110() <= 12))
                        ? node->GetProperty(3)
                        : 0;
                TexturePtr texture2(0);
                if (l)
                {
                    if (player ? playerCards.FUN_0044ddc0() > 0 : opponentCards.FUN_0044ddc0() > 0)
                    {
                        if (player)
                            formatDeck(nodeName, 260, "Textures\\%s",
                                       playerCards.FUN_006a7ad0(playerSelection)->FUN_00503650()->FUN_00408da0());
                        else
                            formatDeck(nodeName, 260, "Textures\\%s",
                                       opponentCards.FUN_006a7ad0(opponentSelection)->FUN_00503650()->FUN_00408da0());
                        normalizeDeck(nodeName, texturePath, 260);
                        g_TES->load(texturePath, texture2, false, false);
                        if (texture2)
                            l->setTexture(0, 0, texture2);
                    }
                }
            }
        }
    }
}
}  // namespace fnv_0074d730

extern char UNK_01071a6c;
struct CardShader : UIWidget
{
    int FUN_00441110();
};
struct CardNode
{
    CardShader* FUN_00a59d30(int type);
};
CardNode* __cdecl FUN_004aae30(NiAVObject* root, const char* name);
int __cdecl _sprintf_s(char* buffer, unsigned int size, const char* format, ...);
struct NP
{
    unsigned int value;
    NP(int value);
    ~NP();
    operator int() const;
};
struct CardAssetArray
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    UIAssetSource** FUN_006a7ad0(int index);
};
struct CaravanCardMenu : S_0074ed40_Cls
{
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
    unsigned int unk410;
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
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
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
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66c;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67c;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68c;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69c;
    unsigned int unk6a0;
    unsigned int unk6a4;
    unsigned int unk6a8;
    unsigned int unk6ac;
    unsigned int unk6b0;
    unsigned int unk6b4;
    unsigned int unk6b8;
    unsigned int unk6bc;
    unsigned int unk6c0;
    unsigned int unk6c4;
    unsigned int unk6c8;
    unsigned int unk6cc;
    unsigned int unk6d0;
    unsigned int unk6d4;
    unsigned int unk6d8;
    unsigned int unk6dc;
    unsigned int unk6e0;
    unsigned int unk6e4;
    unsigned int unk6e8;
    unsigned int unk6ec;
    unsigned int unk6f0;
    unsigned int unk6f4;
    unsigned int unk6f8;
    unsigned int unk6fc;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70c;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71c;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72c;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73c;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74c;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75c;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76c;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77c;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78c;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79c;
    unsigned int unk7a0;
    unsigned int unk7a4;
    unsigned int unk7a8;
    unsigned int unk7ac;
    unsigned int unk7b0;
    unsigned int unk7b4;
    unsigned int unk7b8;
    unsigned int unk7bc;
    unsigned int unk7c0;
    unsigned int unk7c4;
    unsigned int unk7c8;
    unsigned int unk7cc;
    unsigned int unk7d0;
    unsigned int unk7d4;
    unsigned int unk7d8;
    unsigned int unk7dc;
    unsigned int unk7e0;
    unsigned int unk7e4;
    unsigned int unk7e8;
    unsigned int unk7ec;
    unsigned int unk7f0;
    unsigned int unk7f4;
    unsigned int unk7f8;
    unsigned int unk7fc;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80c;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81c;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82c;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83c;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84c;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85c;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86c;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87c;
    unsigned int unk880;
    unsigned int unk884;
    unsigned int unk888;
    unsigned int unk88c;
    unsigned int unk890;
    unsigned int unk894;
    unsigned int unk898;
    unsigned int unk89c;
    unsigned int unk8a0;
    unsigned int unk8a4;
    unsigned int unk8a8;
    unsigned int unk8ac;
    unsigned int unk8b0;
    unsigned int unk8b4;
    unsigned int unk8b8;
    unsigned int unk8bc;
    unsigned int unk8c0;
    unsigned int unk8c4;
    unsigned int unk8c8;
    unsigned int unk8cc;
    unsigned int unk8d0;
    unsigned int unk8d4;
    unsigned int unk8d8;
    unsigned int unk8dc;
    unsigned int unk8e0;
    unsigned int unk8e4;
    unsigned int unk8e8;
    unsigned int unk8ec;
    unsigned int unk8f0;
    unsigned int unk8f4;
    unsigned int unk8f8;
    unsigned int unk8fc;
    unsigned int unk900;
    unsigned int unk904;
    unsigned int unk908;
    unsigned int unk90c;
    unsigned int unk910;
    unsigned int unk914;
    unsigned int unk918;
    unsigned int unk91c;
    unsigned int unk920;
    unsigned int unk924;
    unsigned int unk928;
    unsigned int unk92c;
    unsigned int unk930;
    unsigned int unk934;
    unsigned int unk938;
    unsigned int unk93c;
    unsigned int unk940;
    unsigned int unk944;
    unsigned int unk948;
    unsigned int unk94c;
    unsigned int unk950;
    unsigned int unk954;
    unsigned int unk958;
    unsigned int unk95c;
    unsigned int unk960;
    unsigned int unk964;
    unsigned int unk968;
    unsigned int unk96c;
    unsigned int unk970;
    unsigned int unk974;
    unsigned int unk978;
    unsigned int unk97c;
    unsigned int unk980;
    unsigned int unk984;
    unsigned int unk988;
    unsigned int unk98c;
    unsigned int unk990;
    unsigned int unk994;
    unsigned int unk998;
    unsigned int unk99c;
    unsigned int unk9a0;
    unsigned int unk9a4;
    unsigned int unk9a8;
    unsigned int unk9ac;
    unsigned int unk9b0;
    unsigned int unk9b4;
    unsigned int unk9b8;
    unsigned int unk9bc;
    unsigned int unk9c0;
    unsigned int unk9c4;
    unsigned int unk9c8;
    unsigned int unk9cc;
    unsigned int unk9d0;
    unsigned int unk9d4;
    unsigned int unk9d8;
    unsigned int unk9dc;
    unsigned int unk9e0;
    unsigned int unk9e4;
    unsigned int unk9e8;
    unsigned int unk9ec;
    unsigned int unk9f0;
    unsigned int unk9f4;
    unsigned int unk9f8;
    unsigned int unk9fc;
    unsigned int unka00;
    unsigned int unka04;
    unsigned int unka08;
    unsigned int unka0c;
    unsigned int unka10;
    unsigned int unka14;
    unsigned int unka18;
    unsigned int unka1c;
    unsigned int unka20;
    unsigned int unka24;
    unsigned int unka28;
    unsigned int unka2c;
    unsigned int unka30;
    unsigned int unka34;
    unsigned int unka38;
    unsigned int unka3c;
    unsigned int unka40;
    unsigned int unka44;
    unsigned int unka48;
    unsigned int unka4c;
    unsigned int unka50;
    unsigned int unka54;
    unsigned int unka58;
    unsigned int unka5c;
    unsigned int unka60;
    unsigned int unka64;
    unsigned int unka68;
    unsigned int unka6c;
    unsigned int unka70;
    unsigned int unka74;
    unsigned int unka78;
    unsigned int unka7c;
    unsigned int unka80;
    unsigned int unka84;
    unsigned int unka88;
    unsigned int unka8c;
    unsigned int unka90;
    unsigned int unka94;
    unsigned int unka98;
    unsigned int unka9c;
    unsigned int unkaa0;
    unsigned int unkaa4;
    unsigned int unkaa8;
    unsigned int unkaac;
    unsigned int unkab0;
    unsigned int unkab4;
    unsigned int unkab8;
    unsigned int unkabc;
    unsigned int unkac0;
    unsigned int unkac4;
    unsigned int unkac8;
    unsigned int unkacc;
    unsigned int unkad0;
    unsigned int unkad4;
    unsigned int unkad8;
    unsigned int unkadc;
    unsigned int unkae0;
    unsigned int unkae4;
    unsigned int unkae8;
    unsigned int unkaec;
    unsigned int unkaf0;
    unsigned int unkaf4;
    unsigned int unkaf8;
    unsigned int unkafc;
    unsigned int unkb00;
    unsigned int unkb04;
    unsigned int unkb08;
    unsigned int unkb0c;
    unsigned int unkb10;
    unsigned int unkb14;
    unsigned int unkb18;
    unsigned int unkb1c;
    unsigned int unkb20;
    unsigned int unkb24;
    unsigned int unkb28;
    unsigned int unkb2c;
    unsigned int unkb30;
    unsigned int unkb34;
    unsigned int unkb38;
    unsigned int unkb3c;
    unsigned int unkb40;
    CardAssetArray assets[8][7];
    void FUN_0074e220(int track, int row, int card);
};
// @fnv 0x0074e220
void CaravanCardMenu::FUN_0074e220(int track, int row, int card)
{
    // Local names preserve the original MSVC9 stack layout.
    NiAVObject* f = m_rows[track][row];
    char h[260];  // Node name, later reused for the texture filename.
    char a[260];  // Normalized resource path.
    if (track >= 3)
        _sprintf_s(h, 260, &UNK_01071a6c, 4 - card, card);
    else
        _sprintf_s(h, 260, &UNK_01071a6c, card + 1, card);
    CardNode* i = FUN_004aae30(f, h);
    CardShader* s =
        (!i->FUN_00a59d30(3) ? false
                             : (i->FUN_00a59d30(3)->FUN_00441110() >= 8 && i->FUN_00a59d30(3)->FUN_00441110() <= 12))
            ? i->FUN_00a59d30(3)
            : 0;
    NP p(0);  // Owns the loaded texture resource.
    if (s)
    {
        _sprintf_s(h, 260, &UNK_0101996c, &UNK_0101d7fc,
                   (*assets[track][row].FUN_006a7ad0(card))->FUN_0050d100()->FUN_00408da0());
        FUN_004b7240(h, a, 260);
        DAT_011dea10->FUN_004568c0(a, (GO*)&p, 0, 0);
        if (p)
            s->SetResource(0, 0, p);
    }
}

namespace fnv_0074e480 {
struct Position
{
    float x, y, z;
};
struct SceneObject
{
    Position& FUN_0043c490();
    void FUN_004bc1f0(float, float, float);
    void Update(const NiUpdateData&);
};
struct SelectionArray
{
    unsigned int& FUN_006a7ad0(unsigned int);
};
int __cdecl formatName(char*, unsigned int, const char*, ...);
SceneObject* __cdecl GetSelectionItem(void*, const char*);
struct SelectionMenu
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
    void* root;
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
    unsigned int unk410;
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
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
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
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66c;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67c;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68c;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69c;
    unsigned int unk6a0;
    unsigned int unk6a4;
    unsigned int unk6a8;
    unsigned int unk6ac;
    unsigned int unk6b0;
    unsigned int unk6b4;
    unsigned int unk6b8;
    unsigned int unk6bc;
    unsigned int unk6c0;
    unsigned int unk6c4;
    unsigned int unk6c8;
    unsigned int unk6cc;
    unsigned int unk6d0;
    unsigned int unk6d4;
    unsigned int unk6d8;
    unsigned int unk6dc;
    unsigned int unk6e0;
    unsigned int unk6e4;
    unsigned int unk6e8;
    unsigned int unk6ec;
    unsigned int unk6f0;
    unsigned int unk6f4;
    unsigned int unk6f8;
    unsigned int unk6fc;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70c;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71c;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72c;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73c;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74c;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75c;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76c;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77c;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78c;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79c;
    unsigned int unk7a0;
    unsigned int unk7a4;
    unsigned int unk7a8;
    unsigned int unk7ac;
    unsigned int unk7b0;
    unsigned int unk7b4;
    unsigned int unk7b8;
    unsigned int unk7bc;
    unsigned int unk7c0;
    unsigned int unk7c4;
    unsigned int unk7c8;
    unsigned int unk7cc;
    unsigned int unk7d0;
    unsigned int unk7d4;
    unsigned int unk7d8;
    unsigned int unk7dc;
    unsigned int unk7e0;
    unsigned int unk7e4;
    unsigned int unk7e8;
    unsigned int unk7ec;
    unsigned int unk7f0;
    unsigned int unk7f4;
    unsigned int unk7f8;
    unsigned int unk7fc;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80c;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81c;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82c;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83c;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84c;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85c;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86c;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87c;
    unsigned int unk880;
    unsigned int unk884;
    unsigned int unk888;
    unsigned int unk88c;
    unsigned int unk890;
    unsigned int unk894;
    unsigned int unk898;
    unsigned int unk89c;
    unsigned int unk8a0;
    unsigned int unk8a4;
    unsigned int unk8a8;
    unsigned int unk8ac;
    unsigned int unk8b0;
    unsigned int unk8b4;
    unsigned int unk8b8;
    unsigned int unk8bc;
    unsigned int unk8c0;
    unsigned int unk8c4;
    unsigned int unk8c8;
    unsigned int unk8cc;
    unsigned int unk8d0;
    unsigned int unk8d4;
    unsigned int unk8d8;
    unsigned int unk8dc;
    unsigned int unk8e0;
    unsigned int unk8e4;
    unsigned int unk8e8;
    unsigned int unk8ec;
    unsigned int unk8f0;
    unsigned int unk8f4;
    unsigned int unk8f8;
    unsigned int unk8fc;
    unsigned int unk900;
    unsigned int unk904;
    unsigned int unk908;
    unsigned int unk90c;
    unsigned int unk910;
    unsigned int unk914;
    unsigned int unk918;
    unsigned int unk91c;
    unsigned int unk920;
    unsigned int unk924;
    unsigned int unk928;
    unsigned int unk92c;
    unsigned int unk930;
    unsigned int unk934;
    unsigned int unk938;
    unsigned int unk93c;
    unsigned int unk940;
    unsigned int unk944;
    unsigned int unk948;
    unsigned int unk94c;
    unsigned int unk950;
    unsigned int unk954;
    unsigned int unk958;
    unsigned int unk95c;
    unsigned int unk960;
    unsigned int unk964;
    unsigned int unk968;
    unsigned int unk96c;
    unsigned int unk970;
    unsigned int unk974;
    unsigned int unk978;
    unsigned int unk97c;
    unsigned int unk980;
    unsigned int unk984;
    unsigned int unk988;
    unsigned int unk98c;
    unsigned int unk990;
    unsigned int unk994;
    unsigned int unk998;
    unsigned int unk99c;
    unsigned int unk9a0;
    unsigned int unk9a4;
    unsigned int unk9a8;
    unsigned int unk9ac;
    unsigned int unk9b0;
    unsigned int unk9b4;
    unsigned int unk9b8;
    unsigned int unk9bc;
    unsigned int unk9c0;
    unsigned int unk9c4;
    unsigned int unk9c8;
    unsigned int unk9cc;
    unsigned int unk9d0;
    unsigned int unk9d4;
    unsigned int unk9d8;
    unsigned int unk9dc;
    unsigned int unk9e0;
    unsigned int unk9e4;
    unsigned int unk9e8;
    unsigned int unk9ec;
    unsigned int unk9f0;
    unsigned int unk9f4;
    unsigned int unk9f8;
    unsigned int unk9fc;
    unsigned int unka00;
    unsigned int unka04;
    unsigned int unka08;
    unsigned int unka0c;
    unsigned int unka10;
    unsigned int unka14;
    unsigned int unka18;
    unsigned int unka1c;
    unsigned int unka20;
    unsigned int unka24;
    unsigned int unka28;
    unsigned int unka2c;
    unsigned int unka30;
    unsigned int unka34;
    unsigned int unka38;
    unsigned int unka3c;
    unsigned int unka40;
    unsigned int unka44;
    unsigned int unka48;
    unsigned int unka4c;
    unsigned int unka50;
    unsigned int unka54;
    unsigned int unka58;
    unsigned int unka5c;
    unsigned int unka60;
    unsigned int unka64;
    unsigned int unka68;
    unsigned int unka6c;
    unsigned int unka70;
    unsigned int unka74;
    unsigned int unka78;
    unsigned int unka7c;
    unsigned int unka80;
    unsigned int unka84;
    unsigned int unka88;
    unsigned int unka8c;
    unsigned int unka90;
    unsigned int unka94;
    unsigned int unka98;
    unsigned int unka9c;
    unsigned int unkaa0;
    unsigned int unkaa4;
    unsigned int unkaa8;
    unsigned int unkaac;
    unsigned int unkab0;
    unsigned int unkab4;
    unsigned int unkab8;
    unsigned int unkabc;
    unsigned int unkac0;
    unsigned int unkac4;
    unsigned int unkac8;
    unsigned int unkacc;
    unsigned int unkad0;
    unsigned int unkad4;
    unsigned int unkad8;
    unsigned int unkadc;
    unsigned int unkae0;
    unsigned int unkae4;
    unsigned int unkae8;
    unsigned int unkaec;
    unsigned int unkaf0;
    unsigned int unkaf4;
    unsigned int unkaf8;
    unsigned int unkafc;
    unsigned int unkb00;
    unsigned int unkb04;
    unsigned int unkb08;
    unsigned int unkb0c;
    unsigned int unkb10;
    unsigned int unkb14;
    unsigned int unkb18;
    unsigned int unkb1c;
    unsigned int unkb20;
    SelectionArray cards;
    unsigned int unkb28;
    unsigned int unkb2c;
    unsigned int unkb30;
    unsigned int unkb34;
    unsigned int unkb38;
    unsigned int unkb3c;
    unsigned int unkb40;
    unsigned int unkb44;
    unsigned int unkb48;
    unsigned int unkb4c;
    unsigned int unkb50;
    unsigned int unkb54;
    unsigned int unkb58;
    unsigned int unkb5c;
    unsigned int unkb60;
    unsigned int unkb64;
    unsigned int unkb68;
    unsigned int unkb6c;
    unsigned int unkb70;
    unsigned int unkb74;
    unsigned int unkb78;
    unsigned int unkb7c;
    unsigned int unkb80;
    unsigned int unkb84;
    unsigned int unkb88;
    unsigned int unkb8c;
    unsigned int unkb90;
    unsigned int unkb94;
    unsigned int unkb98;
    unsigned int unkb9c;
    unsigned int unkba0;
    unsigned int unkba4;
    unsigned int unkba8;
    unsigned int unkbac;
    unsigned int unkbb0;
    unsigned int unkbb4;
    unsigned int unkbb8;
    unsigned int unkbbc;
    unsigned int unkbc0;
    unsigned int unkbc4;
    unsigned int unkbc8;
    unsigned int unkbcc;
    unsigned int unkbd0;
    unsigned int unkbd4;
    unsigned int unkbd8;
    unsigned int unkbdc;
    unsigned int unkbe0;
    unsigned int unkbe4;
    unsigned int unkbe8;
    unsigned int unkbec;
    unsigned int unkbf0;
    unsigned int unkbf4;
    unsigned int unkbf8;
    unsigned int unkbfc;
    unsigned int unkc00;
    unsigned int unkc04;
    unsigned int unkc08;
    unsigned int unkc0c;
    unsigned int unkc10;
    unsigned int unkc14;
    unsigned int unkc18;
    unsigned int unkc1c;
    unsigned int unkc20;
    unsigned int unkc24;
    unsigned int unkc28;
    unsigned int unkc2c;
    unsigned int unkc30;
    unsigned int unkc34;
    unsigned int unkc38;
    unsigned int unkc3c;
    unsigned int unkc40;
    unsigned int unkc44;
    unsigned int unkc48;
    unsigned int unkc4c;
    unsigned int unkc50;
    unsigned int unkc54;
    unsigned int unkc58;
    unsigned int unkc5c;
    unsigned int unkc60;
    unsigned int unkc64;
    unsigned int unkc68;
    unsigned int unkc6c;
    unsigned int unkc70;
    unsigned int unkc74;
    unsigned int unkc78;
    unsigned int unkc7c;
    unsigned int unkc80;
    unsigned int unkc84;
    unsigned int unkc88;
    unsigned int unkc8c;
    unsigned int unkc90;
    unsigned int unkc94;
    unsigned int unkc98;
    unsigned int unkc9c;
    unsigned int unkca0;
    unsigned int unkca4;
    unsigned int unkca8;
    unsigned int unkcac;
    unsigned int unkcb0;
    unsigned int unkcb4;
    unsigned int unkcb8;
    unsigned int unkcbc;
    unsigned int unkcc0;
    unsigned int unkcc4;
    unsigned int unkcc8;
    unsigned int unkccc;
    unsigned int unkcd0;
    unsigned int unkcd4;
    unsigned int unkcd8;
    unsigned int unkcdc;
    unsigned int unkce0;
    unsigned int unkce4;
    unsigned int unkce8;
    unsigned int unkcec;
    unsigned int unkcf0;
    unsigned int unkcf4;
    unsigned int unkcf8;
    unsigned int unkcfc;
    unsigned int unkd00;
    unsigned int unkd04;
    unsigned int unkd08;
    unsigned int unkd0c;
    unsigned int unkd10;
    unsigned int unkd14;
    unsigned int unkd18;
    unsigned int unkd1c;
    unsigned int unkd20;
    unsigned int unkd24;
    unsigned int unkd28;
    unsigned int unkd2c;
    unsigned int unkd30;
    unsigned int unkd34;
    unsigned int unkd38;
    unsigned int unkd3c;
    unsigned int unkd40;
    unsigned int unkd44;
    unsigned int unkd48;
    unsigned int unkd4c;
    unsigned int unkd50;
    unsigned int unkd54;
    unsigned int unkd58;
    unsigned int unkd5c;
    unsigned int unkd60;
    unsigned int unkd64;
    unsigned int unkd68;
    unsigned int unkd6c;
    unsigned int unkd70;
    unsigned int unkd74;
    unsigned int unkd78;
    unsigned int unkd7c;
    unsigned int unkd80;
    unsigned int unkd84;
    unsigned int unkd88;
    unsigned int unkd8c;
    unsigned int unkd90;
    unsigned int unkd94;
    unsigned int unkd98;
    unsigned int unkd9c;
    unsigned int unkda0;
    unsigned int unkda4;
    unsigned int unkda8;
    unsigned int unkdac;
    unsigned int unkdb0;
    unsigned int unkdb4;
    unsigned int unkdb8;
    unsigned int unkdbc;
    unsigned int unkdc0;
    unsigned int unkdc4;
    unsigned int unkdc8;
    unsigned int unkdcc;
    unsigned int unkdd0;
    unsigned int unkdd4;
    unsigned int unkdd8;
    unsigned int unkddc;
    unsigned int unkde0;
    unsigned int unkde4;
    unsigned int unkde8;
    unsigned int unkdec;
    unsigned int unkdf0;
    unsigned int unkdf4;
    unsigned int unkdf8;
    unsigned int unkdfc;
    unsigned int unke00;
    unsigned int unke04;
    unsigned int unke08;
    unsigned int unke0c;
    unsigned int unke10;
    unsigned int unke14;
    unsigned int unke18;
    unsigned int unke1c;
    unsigned int unke20;
    unsigned int unke24;
    unsigned int unke28;
    unsigned int selection;
    unsigned int unke30;
    unsigned int unke34;
    unsigned int unke38;
    unsigned int unke3c;
    unsigned int unke40;
    unsigned int unke44;
    unsigned int selectedCard;
    SceneObject* first;
    SceneObject* second;
    void UpdateSelection(bool);
};
// Positions and updates the first and second scene objects, then (unless skip) looks up the deck and shadow nodes by name and stores the selected card.
// @fnv 0x0074e480
void SelectionMenu::UpdateSelection(bool skip)
{
    if (first && first->FUN_0043c490().z > 0.0)
    {
        first->FUN_004bc1f0(0.0f, first->FUN_0043c490().y, 0.0f);
        first->Update(NiUpdateData(0.0f, false, false));
        second->FUN_004bc1f0(0.0f, first->FUN_0043c490().y, 0.0f);
        second->Update(NiUpdateData(0.0f, false, false));
    }
    if (skip)
        return;
    char name[30];
    formatName(name, 30, "Player-Deck_0%i:%i", selection + 1, selection);
    first = GetSelectionItem(root, name);
    formatName(name, 30, "Player-Deck_0%i_Shadow:0", selection + 1);
    second = GetSelectionItem(root, name);
    selectedCard = cards.FUN_006a7ad0(selection);
    first->FUN_004bc1f0(0.0f, first->FUN_0043c490().y, 1.0f);
    first->Update(NiUpdateData(0.0f, false, false));
    second->FUN_004bc1f0(0.0f, first->FUN_0043c490().y, 1.0f);
    second->Update(NiUpdateData(0.0f, false, false));
}
}  // namespace fnv_0074e480

struct CValue
{
    int value;
};
struct CCard
{
    CValue* Value();
    int Rank();
    int Suit();
};
struct CRow
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    unsigned int Count();
    CCard*& At(unsigned int);
};
struct CTile
{
    void Float(int, float);
    void Int(int, int);
    void Set(int, float, bool);
};
extern int DAT_011d9174;
struct CStats
{
    int direction;
    int suit;
    int total;
};
struct CMenu
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
    CTile* tiles[6];
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
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
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
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    int unk9a8;
    int unk9ac;
    int unk9b0;
    int unk9b4;
    int unk9b8;
    int unk9bc;
    int unk9c0;
    int unk9c4;
    int unk9c8;
    int unk9cc;
    int unk9d0;
    int unk9d4;
    int unk9d8;
    int unk9dc;
    int unk9e0;
    int unk9e4;
    int unk9e8;
    int unk9ec;
    int unk9f0;
    int unk9f4;
    int unk9f8;
    int unk9fc;
    int unka00;
    int unka04;
    int unka08;
    int unka0c;
    int unka10;
    int unka14;
    int unka18;
    int unka1c;
    int unka20;
    int unka24;
    int unka28;
    int unka2c;
    int unka30;
    int unka34;
    int unka38;
    int unka3c;
    int unka40;
    int unka44;
    int unka48;
    int unka4c;
    int unka50;
    int unka54;
    int unka58;
    int unka5c;
    int unka60;
    int unka64;
    int unka68;
    int unka6c;
    int unka70;
    int unka74;
    int unka78;
    int unka7c;
    int unka80;
    int unka84;
    int unka88;
    int unka8c;
    int unka90;
    int unka94;
    int unka98;
    int unka9c;
    int unkaa0;
    int unkaa4;
    int unkaa8;
    int unkaac;
    int unkab0;
    int unkab4;
    int unkab8;
    int unkabc;
    int unkac0;
    int unkac4;
    int unkac8;
    int unkacc;
    int unkad0;
    int unkad4;
    int unkad8;
    int unkadc;
    int unkae0;
    int unkae4;
    int unkae8;
    int unkaec;
    int unkaf0;
    int unkaf4;
    int unkaf8;
    int unkafc;
    int unkb00;
    int unkb04;
    int unkb08;
    int unkb0c;
    int unkb10;
    int unkb14;
    int unkb18;
    int unkb1c;
    int unkb20;
    int unkb24;
    int unkb28;
    int unkb2c;
    int unkb30;
    int unkb34;
    int unkb38;
    int unkb3c;
    int unkb40;
    CRow rows[6][7];
    CStats stats[6];
    void UpdateHandStats(int hand);
};
// Sums the values of the hand's card rows into stats[hand].total, derives suit and direction, and updates the hand's tile display.
// @fnv 0x0074ee70
void CMenu::UpdateHandStats(int hand)
{
    int total = 0;
    int column = 0;
    for (column = 0; column < 7; column++)
    {
        int value = 0;
        if (!rows[hand][column].Count())
            break;
        for (unsigned int card = 0; card < rows[hand][column].Count(); card++)
        {
            CValue* data = rows[hand][column].At(card)->Value();
            if (card == 0)
                value = data->value;
            else if (data->value == 14)
                value <<= 1;
        }
        total += value;
    }
    stats[hand].total = total;
    switch (column)
    {
    case 0:
        stats[hand].suit = 5;
        stats[hand].direction = 0;
        break;
    case 1:
        stats[hand].suit = rows[hand][0].At(0)->Suit();
        for (unsigned int idx = 1; idx < rows[hand][column - 1].Count(); idx++)
        {
            if (rows[hand][column - 1].At(idx)->Rank() == 13)
                stats[hand].suit = rows[hand][column - 1].At(idx)->Suit();
        }
        stats[hand].direction = 0;
        break;
    default:
        if (rows[hand][column - 1].At(0)->Rank() > rows[hand][column - 2].At(0)->Rank())
            stats[hand].direction = 1;
        else
            stats[hand].direction = -1;
        stats[hand].suit = rows[hand][column - 1].At(0)->Suit();
        for (unsigned int joker = 1; joker < rows[hand][column - 1].Count(); joker++)
        {
            if (rows[hand][column - 1].At(joker)->Rank() == 13)
            {
                stats[hand].suit = rows[hand][column - 1].At(joker)->Suit();
                stats[hand].direction = -stats[hand].direction;
            }
        }
    }
    tiles[hand]->Float(DAT_011d9174, 1.0f);
    tiles[hand]->Int(DAT_011d9174, stats[hand].total);
    if (stats[hand].total < 21)
    {
        tiles[hand]->Int(4084, 4084);
        tiles[hand]->Set(4009, 126.0f, true);
    }
    if (stats[hand].total > 26)
    {
        tiles[hand]->Int(4084, 2);
        tiles[hand]->Set(4009, 255.0f, true);
    }
    else
    {
        tiles[hand]->Int(4084, 1);
        tiles[hand]->Set(4009, 255.0f, true);
    }
}

struct CaravanCard
{
    int FUN_008d80e0();
};

struct CaravanCardArray
{
    void* pVtbl;
    CaravanCard** pData;
    unsigned int uiSize;
    unsigned int uiAlloc;

    unsigned int Count();
    CaravanCard*& GetAt(unsigned int auiIndex);
};

class CaravanMenuGrid
{
  public:
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    int unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
    int unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
    int unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C;
    int unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC;
    int unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC;
    int unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C;
    int unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C;
    int unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C;
    int unk1A0, unk1A4, unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC;
    int unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    int unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC;
    int unk200, unk204, unk208, unk20C, unk210, unk214, unk218, unk21C;
    int unk220, unk224, unk228, unk22C, unk230, unk234, unk238, unk23C;
    int unk240, unk244, unk248, unk24C, unk250, unk254, unk258, unk25C;
    int unk260, unk264, unk268, unk26C, unk270, unk274, unk278, unk27C;
    int unk280, unk284, unk288, unk28C, unk290, unk294, unk298, unk29C;
    int unk2A0, unk2A4, unk2A8, unk2AC, unk2B0, unk2B4, unk2B8, unk2BC;
    int unk2C0, unk2C4, unk2C8, unk2CC, unk2D0, unk2D4, unk2D8, unk2DC;
    int unk2E0, unk2E4, unk2E8, unk2EC, unk2F0, unk2F4, unk2F8, unk2FC;
    int unk300, unk304, unk308, unk30C, unk310, unk314, unk318, unk31C;
    int unk320, unk324, unk328, unk32C, unk330, unk334, unk338, unk33C;
    int unk340, unk344, unk348, unk34C, unk350, unk354, unk358, unk35C;
    int unk360, unk364, unk368, unk36C, unk370, unk374, unk378, unk37C;
    int unk380, unk384, unk388, unk38C, unk390, unk394, unk398, unk39C;
    int unk3A0, unk3A4, unk3A8, unk3AC, unk3B0, unk3B4, unk3B8, unk3BC;
    int unk3C0, unk3C4, unk3C8, unk3CC, unk3D0, unk3D4, unk3D8, unk3DC;
    int unk3E0, unk3E4, unk3E8, unk3EC, unk3F0, unk3F4, unk3F8, unk3FC;
    int unk400, unk404, unk408, unk40C, unk410, unk414, unk418, unk41C;
    int unk420, unk424, unk428, unk42C, unk430, unk434, unk438, unk43C;
    int unk440, unk444, unk448, unk44C, unk450, unk454, unk458, unk45C;
    int unk460, unk464, unk468, unk46C, unk470, unk474, unk478, unk47C;
    int unk480, unk484, unk488, unk48C, unk490, unk494, unk498, unk49C;
    int unk4A0, unk4A4, unk4A8, unk4AC, unk4B0, unk4B4, unk4B8, unk4BC;
    int unk4C0, unk4C4, unk4C8, unk4CC, unk4D0, unk4D4, unk4D8, unk4DC;
    int unk4E0, unk4E4, unk4E8, unk4EC, unk4F0, unk4F4, unk4F8, unk4FC;
    int unk500, unk504, unk508, unk50C, unk510, unk514, unk518, unk51C;
    int unk520, unk524, unk528, unk52C, unk530, unk534, unk538, unk53C;
    int unk540, unk544, unk548, unk54C, unk550, unk554, unk558, unk55C;
    int unk560, unk564, unk568, unk56C, unk570, unk574, unk578, unk57C;
    int unk580, unk584, unk588, unk58C, unk590, unk594, unk598, unk59C;
    int unk5A0, unk5A4, unk5A8, unk5AC, unk5B0, unk5B4, unk5B8, unk5BC;
    int unk5C0, unk5C4, unk5C8, unk5CC, unk5D0, unk5D4, unk5D8, unk5DC;
    int unk5E0, unk5E4, unk5E8, unk5EC, unk5F0, unk5F4, unk5F8, unk5FC;
    int unk600, unk604, unk608, unk60C, unk610, unk614, unk618, unk61C;
    int unk620, unk624, unk628, unk62C, unk630, unk634, unk638, unk63C;
    int unk640, unk644, unk648, unk64C, unk650, unk654, unk658, unk65C;
    int unk660, unk664, unk668, unk66C, unk670, unk674, unk678, unk67C;
    int unk680, unk684, unk688, unk68C, unk690, unk694, unk698, unk69C;
    int unk6A0, unk6A4, unk6A8, unk6AC, unk6B0, unk6B4, unk6B8, unk6BC;
    int unk6C0, unk6C4, unk6C8, unk6CC, unk6D0, unk6D4, unk6D8, unk6DC;
    int unk6E0, unk6E4, unk6E8, unk6EC, unk6F0, unk6F4, unk6F8, unk6FC;
    int unk700, unk704, unk708, unk70C, unk710, unk714, unk718, unk71C;
    int unk720, unk724, unk728, unk72C, unk730, unk734, unk738, unk73C;
    int unk740, unk744, unk748, unk74C, unk750, unk754, unk758, unk75C;
    int unk760, unk764, unk768, unk76C, unk770, unk774, unk778, unk77C;
    int unk780, unk784, unk788, unk78C, unk790, unk794, unk798, unk79C;
    int unk7A0, unk7A4, unk7A8, unk7AC, unk7B0, unk7B4, unk7B8, unk7BC;
    int unk7C0, unk7C4, unk7C8, unk7CC, unk7D0, unk7D4, unk7D8, unk7DC;
    int unk7E0, unk7E4, unk7E8, unk7EC, unk7F0, unk7F4, unk7F8, unk7FC;
    int unk800, unk804, unk808, unk80C, unk810, unk814, unk818, unk81C;
    int unk820, unk824, unk828, unk82C, unk830, unk834, unk838, unk83C;
    int unk840, unk844, unk848, unk84C, unk850, unk854, unk858, unk85C;
    int unk860, unk864, unk868, unk86C, unk870, unk874, unk878, unk87C;
    int unk880, unk884, unk888, unk88C, unk890, unk894, unk898, unk89C;
    int unk8A0, unk8A4, unk8A8, unk8AC, unk8B0, unk8B4, unk8B8, unk8BC;
    int unk8C0, unk8C4, unk8C8, unk8CC, unk8D0, unk8D4, unk8D8, unk8DC;
    int unk8E0, unk8E4, unk8E8, unk8EC, unk8F0, unk8F4, unk8F8, unk8FC;
    int unk900, unk904, unk908, unk90C, unk910, unk914, unk918, unk91C;
    int unk920, unk924, unk928, unk92C, unk930, unk934, unk938, unk93C;
    int unk940, unk944, unk948, unk94C, unk950, unk954, unk958, unk95C;
    int unk960, unk964, unk968, unk96C, unk970, unk974, unk978, unk97C;
    int unk980, unk984, unk988, unk98C, unk990, unk994, unk998, unk99C;
    int unk9A0, unk9A4, unk9A8, unk9AC, unk9B0, unk9B4, unk9B8, unk9BC;
    int unk9C0, unk9C4, unk9C8, unk9CC, unk9D0, unk9D4, unk9D8, unk9DC;
    int unk9E0, unk9E4, unk9E8, unk9EC, unk9F0, unk9F4, unk9F8, unk9FC;
    int unkA00, unkA04, unkA08, unkA0C, unkA10, unkA14, unkA18, unkA1C;
    int unkA20, unkA24, unkA28, unkA2C, unkA30, unkA34, unkA38, unkA3C;
    int unkA40, unkA44, unkA48, unkA4C, unkA50, unkA54, unkA58, unkA5C;
    int unkA60, unkA64, unkA68, unkA6C, unkA70, unkA74, unkA78, unkA7C;
    int unkA80, unkA84, unkA88, unkA8C, unkA90, unkA94, unkA98, unkA9C;
    int unkAA0, unkAA4, unkAA8, unkAAC, unkAB0, unkAB4, unkAB8, unkABC;
    int unkAC0, unkAC4, unkAC8, unkACC, unkAD0, unkAD4, unkAD8, unkADC;
    int unkAE0, unkAE4, unkAE8, unkAEC, unkAF0, unkAF4, unkAF8, unkAFC;
    int unkB00, unkB04, unkB08, unkB0C, unkB10, unkB14, unkB18, unkB1C;
    int unkB20;
    CaravanCardArray kHand;
    int unkB34, unkB38, unkB3C, unkB40;
    CaravanCardArray kGrid[6][7];
    int unkDE4, unkDE8, unkDEC, unkDF0, unkDF4, unkDF8, unkDFC, unkE00;
    int unkE04, unkE08, unkE0C, unkE10, unkE14, unkE18, unkE1C, unkE20;
    int unkE24, unkE28;
    int iHandIndex;
    int iRow;
    int iCol;
    unsigned int uiCellCount;

    void SelectCard(int aiRow, int aiCol);
    bool CanPlaceCard(int aiRow, int aiCol, int aiHandIndex, int aiUnk);
    void SetFlag(int aiID, int aiValue);
    void FUN_00749a40(int aiValue);
    void MoveSelection(int aiDeltaRow, int aiDeltaCol);
};

// @fnv 0x0074f360
void CaravanMenuGrid::MoveSelection(int aiDeltaRow, int aiDeltaCol)
{
    int iPrevRow = iRow;
    int iPrevCol = iCol;
    bool bCardValueLow = kHand.GetAt(iHandIndex)->FUN_008d80e0() <= 10;

    if (aiDeltaRow)
    {
        if (iPrevRow < 3)
        {
            iRow += aiDeltaRow;
            iRow = MinInt(FUN_00647b70(0, iRow), 2);
        }
        else
        {
            iRow -= aiDeltaRow;
            iRow = MinInt(FUN_00647b70(3, iRow), 5);
        }
    }
    if (aiDeltaCol && iPrevCol == iCol)
    {
        iRow < 3 ? iCol += aiDeltaCol : iCol -= aiDeltaCol;
        if (iCol == -1)
        {
            iRow < 3 ? iRow = 5 - iPrevRow : iRow = 5 - iPrevRow;
            iCol = 0;
        }
        else if (iCol == 7)
            iCol = 6;
    }
    if (aiDeltaRow == aiDeltaCol && aiDeltaRow == 0)
    {
        iRow = 0;
        iCol = 0;
        uiCellCount = 0;
    }
    uiCellCount = kGrid[iRow][iCol].Count();
    SelectCard(iRow, iCol);
    if (CanPlaceCard(iRow, iCol, iHandIndex, 0))
        SetFlag(4, 0);
    else
        SetFlag(4, 1);
    FUN_00749a40(-1);
}

struct PlacementCard
{
    int Value();
    int Suit();
};
struct PlacementList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned int Size();
    PlacementCard*& At(int);
};
struct PlacementRow
{
    int direction;
    int suit;
    int unk08;
};
struct PlacementMenu
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
    PlacementList playerHand;
    PlacementList opponentHand;
    PlacementList tracks[6][7];
    PlacementRow rows[6];
    bool HasFlag(unsigned int);
    bool CanPlaceCard(int track, int row, int cardIndex, bool opponent);
};
// Checks whether a card from the player's or opponent's hand can be placed at the given track, row and index, returning true if allowed.
// @fnv 0x0074f6c0
bool PlacementMenu::CanPlaceCard(int track, int row, int cardIndex, bool opponent)
{
    if (track < 0 || track > 5 || row < 0 || row > 6 || cardIndex < 0)
        return false;
    if ((unsigned int)cardIndex > (opponent ? opponentHand.Size() - 1 : playerHand.Size() - 1))
        return false;
    int value = opponent ? opponentHand.At(cardIndex)->Value() : playerHand.At(cardIndex)->Value();
    int suit = opponent ? opponentHand.At(cardIndex)->Suit() : playerHand.At(cardIndex)->Suit();
    if (HasFlag(0x800))
    {
        if (tracks[track][row].Size() == 0 && value <= 10)
            return true;
        else
            return false;
    }
    if (value > 10)
    {
        int count = tracks[track][row].Size();
        if (count < 1 || count > 3)
            return false;
        if (row < 6 && tracks[track][row + 1].Size() != 0 && value == 13)
            return false;
    }
    else
    {
        if (tracks[track][row].Size() != 0)
            return false;
        if (opponent && track < 3)
            return false;
        if (!opponent && track > 2)
            return false;
        if (row != 0)
        {
            if (tracks[track][row - 1].Size() == 0)
                return false;
            int iPreviousValue = tracks[track][row - 1].At(0)->Value();
            if (iPreviousValue == value)
                return false;
            if (rows[track].direction == 1 && iPreviousValue >= value && rows[track].suit != suit)
                return false;
            if (rows[track].direction == -1 && iPreviousValue <= value && rows[track].suit != suit)
                return false;
        }
    }
    return true;
}

namespace fnv_0074f9b0 {
struct NiFixedStringBase
{
    void FUN_004381b0();
};
struct NiFixedString : NiFixedStringBase
{
    const char* m_str;
    NiFixedString(const char*);
    ~NiFixedString();
};
struct RTTIObj
{
    int tag;
};
extern RTTIObj DAT_011f36ac;
struct Ctrl
{
    void* FUN_0047a520(const NiFixedString& name);
    void FUN_0047aab0(void* res, int a, int b, float c, float d, int e);
};
struct Elem
{
    Elem* FUN_00a5d680();
    Ctrl* FUN_00a5c570(RTTIObj* rtti);
};
int __cdecl MinInt(int a, int b);
unsigned int __cdecl GetRandomNumberInRange(int a, int b);
void __cdecl FUN_00a6d2d0(Elem* p);
struct AddObj
{
    int tag;
    unsigned int FUN_007cb2e0(Elem** pp);
};
struct EDObj
{
    int tag;
    void FUN_005ae3d0(void** pp);
};
struct VObj
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55(Elem* p, int n);
};
struct MgrObj
{
    int tag;
    VObj* FUN_00559450();
};
extern MgrObj DAT_011d91e4;
struct Owner
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
    Elem* m_items[9];
    AddObj m_add;
    int f150;
    int f154;
    int f158;
    EDObj* m_ed;
    void PlaceRandomItem(int a1);
};

// @fnv 0x0074f9b0
void Owner::PlaceRandomItem(int aiIndex)
{
    unsigned int v6;
    Elem* cloned6;
    Ctrl* ctrl4;
    void* aRes;
    aiIndex = MinInt(aiIndex, 2);
    cloned6 = m_items[aiIndex]->FUN_00a5d680();
    v6 = GetRandomNumberInRange(0, 3);
    ctrl4 = cloned6->FUN_00a5c570(&DAT_011f36ac);
    switch (v6)
    {
    case 0:
        if (ctrl4)
        {
            Ctrl* p0 = ctrl4;
            aRes = p0->FUN_0047a520(NiFixedString("Top_Place"));
            p0->FUN_0047aab0(aRes, 0, 0, 1.0f, 0.0f, 0);
            FUN_00a6d2d0(cloned6);
        }
        break;
    case 1:
        if (ctrl4)
        {
            Ctrl* p1 = ctrl4;
            aRes = p1->FUN_0047a520(NiFixedString("Bottom_Place"));
            p1->FUN_0047aab0(aRes, 0, 0, 1.0f, 0.0f, 0);
            FUN_00a6d2d0(cloned6);
        }
        break;
    case 2:
        if (ctrl4)
        {
            Ctrl* p5 = ctrl4;
            aRes = p5->FUN_0047a520(NiFixedString("Alt_Place"));
            p5->FUN_0047aab0(aRes, 0, 0, 1.0f, 0.0f, 0);
            FUN_00a6d2d0(cloned6);
        }
        break;
    }
    m_add.FUN_007cb2e0(&cloned6);
    m_ed->FUN_005ae3d0(&aRes);
    DAT_011d91e4.FUN_00559450()->f55(cloned6, 1);
}
}  // namespace fnv_0074f9b0

struct CaravanHandState
{
    int data;
    int capacity;
    int count;
    int growBy;
    unsigned int FUN_0044ddc0();
};
struct CaravanTrackState
{
    int score;
    int direction;
    int suit;
};
struct CaravanResultMenu
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int unk02B4;
    unsigned int unk02B8;
    unsigned int unk02BC;
    unsigned int unk02C0;
    unsigned int unk02C4;
    unsigned int unk02C8;
    unsigned int unk02CC;
    unsigned int unk02D0;
    unsigned int unk02D4;
    unsigned int unk02D8;
    unsigned int unk02DC;
    unsigned int unk02E0;
    unsigned int unk02E4;
    unsigned int unk02E8;
    unsigned int unk02EC;
    unsigned int unk02F0;
    unsigned int unk02F4;
    unsigned int unk02F8;
    unsigned int unk02FC;
    unsigned int unk0300;
    unsigned int unk0304;
    unsigned int unk0308;
    unsigned int unk030C;
    unsigned int unk0310;
    unsigned int unk0314;
    unsigned int unk0318;
    unsigned int unk031C;
    unsigned int unk0320;
    unsigned int unk0324;
    unsigned int unk0328;
    unsigned int unk032C;
    unsigned int unk0330;
    unsigned int unk0334;
    unsigned int unk0338;
    unsigned int unk033C;
    unsigned int unk0340;
    unsigned int unk0344;
    unsigned int unk0348;
    unsigned int unk034C;
    unsigned int unk0350;
    unsigned int unk0354;
    unsigned int unk0358;
    unsigned int unk035C;
    unsigned int unk0360;
    unsigned int unk0364;
    unsigned int unk0368;
    unsigned int unk036C;
    unsigned int unk0370;
    unsigned int unk0374;
    unsigned int unk0378;
    unsigned int unk037C;
    unsigned int unk0380;
    unsigned int unk0384;
    unsigned int unk0388;
    unsigned int unk038C;
    unsigned int unk0390;
    unsigned int unk0394;
    unsigned int unk0398;
    unsigned int unk039C;
    unsigned int unk03A0;
    unsigned int unk03A4;
    unsigned int unk03A8;
    unsigned int unk03AC;
    unsigned int unk03B0;
    unsigned int unk03B4;
    unsigned int unk03B8;
    unsigned int unk03BC;
    unsigned int unk03C0;
    unsigned int unk03C4;
    unsigned int unk03C8;
    unsigned int unk03CC;
    unsigned int unk03D0;
    unsigned int unk03D4;
    unsigned int unk03D8;
    unsigned int unk03DC;
    unsigned int unk03E0;
    unsigned int unk03E4;
    unsigned int unk03E8;
    unsigned int unk03EC;
    unsigned int unk03F0;
    unsigned int unk03F4;
    unsigned int unk03F8;
    unsigned int unk03FC;
    unsigned int unk0400;
    unsigned int unk0404;
    unsigned int unk0408;
    unsigned int unk040C;
    unsigned int unk0410;
    unsigned int unk0414;
    unsigned int unk0418;
    unsigned int unk041C;
    unsigned int unk0420;
    unsigned int unk0424;
    unsigned int unk0428;
    unsigned int unk042C;
    unsigned int unk0430;
    unsigned int unk0434;
    unsigned int unk0438;
    unsigned int unk043C;
    unsigned int unk0440;
    unsigned int unk0444;
    unsigned int unk0448;
    unsigned int unk044C;
    unsigned int unk0450;
    unsigned int unk0454;
    unsigned int unk0458;
    unsigned int unk045C;
    unsigned int unk0460;
    unsigned int unk0464;
    unsigned int unk0468;
    unsigned int unk046C;
    unsigned int unk0470;
    unsigned int unk0474;
    unsigned int unk0478;
    unsigned int unk047C;
    unsigned int unk0480;
    unsigned int unk0484;
    unsigned int unk0488;
    unsigned int unk048C;
    unsigned int unk0490;
    unsigned int unk0494;
    unsigned int unk0498;
    unsigned int unk049C;
    unsigned int unk04A0;
    unsigned int unk04A4;
    unsigned int unk04A8;
    unsigned int unk04AC;
    unsigned int unk04B0;
    unsigned int unk04B4;
    unsigned int unk04B8;
    unsigned int unk04BC;
    unsigned int unk04C0;
    unsigned int unk04C4;
    unsigned int unk04C8;
    unsigned int unk04CC;
    unsigned int unk04D0;
    unsigned int unk04D4;
    unsigned int unk04D8;
    unsigned int unk04DC;
    unsigned int unk04E0;
    unsigned int unk04E4;
    unsigned int unk04E8;
    unsigned int unk04EC;
    unsigned int unk04F0;
    unsigned int unk04F4;
    unsigned int unk04F8;
    unsigned int unk04FC;
    unsigned int unk0500;
    unsigned int unk0504;
    unsigned int unk0508;
    unsigned int unk050C;
    unsigned int unk0510;
    unsigned int unk0514;
    unsigned int unk0518;
    unsigned int unk051C;
    unsigned int unk0520;
    unsigned int unk0524;
    unsigned int unk0528;
    unsigned int unk052C;
    unsigned int unk0530;
    unsigned int unk0534;
    unsigned int unk0538;
    unsigned int unk053C;
    unsigned int unk0540;
    unsigned int unk0544;
    unsigned int unk0548;
    unsigned int unk054C;
    unsigned int unk0550;
    unsigned int unk0554;
    unsigned int unk0558;
    unsigned int unk055C;
    unsigned int unk0560;
    unsigned int unk0564;
    unsigned int unk0568;
    unsigned int unk056C;
    unsigned int unk0570;
    unsigned int unk0574;
    unsigned int unk0578;
    unsigned int unk057C;
    unsigned int unk0580;
    unsigned int unk0584;
    unsigned int unk0588;
    unsigned int unk058C;
    unsigned int unk0590;
    unsigned int unk0594;
    unsigned int unk0598;
    unsigned int unk059C;
    unsigned int unk05A0;
    unsigned int unk05A4;
    unsigned int unk05A8;
    unsigned int unk05AC;
    unsigned int unk05B0;
    unsigned int unk05B4;
    unsigned int unk05B8;
    unsigned int unk05BC;
    unsigned int unk05C0;
    unsigned int unk05C4;
    unsigned int unk05C8;
    unsigned int unk05CC;
    unsigned int unk05D0;
    unsigned int unk05D4;
    unsigned int unk05D8;
    unsigned int unk05DC;
    unsigned int unk05E0;
    unsigned int unk05E4;
    unsigned int unk05E8;
    unsigned int unk05EC;
    unsigned int unk05F0;
    unsigned int unk05F4;
    unsigned int unk05F8;
    unsigned int unk05FC;
    unsigned int unk0600;
    unsigned int unk0604;
    unsigned int unk0608;
    unsigned int unk060C;
    unsigned int unk0610;
    unsigned int unk0614;
    unsigned int unk0618;
    unsigned int unk061C;
    unsigned int unk0620;
    unsigned int unk0624;
    unsigned int unk0628;
    unsigned int unk062C;
    unsigned int unk0630;
    unsigned int unk0634;
    unsigned int unk0638;
    unsigned int unk063C;
    unsigned int unk0640;
    unsigned int unk0644;
    unsigned int unk0648;
    unsigned int unk064C;
    unsigned int unk0650;
    unsigned int unk0654;
    unsigned int unk0658;
    unsigned int unk065C;
    unsigned int unk0660;
    unsigned int unk0664;
    unsigned int unk0668;
    unsigned int unk066C;
    unsigned int unk0670;
    unsigned int unk0674;
    unsigned int unk0678;
    unsigned int unk067C;
    unsigned int unk0680;
    unsigned int unk0684;
    unsigned int unk0688;
    unsigned int unk068C;
    unsigned int unk0690;
    unsigned int unk0694;
    unsigned int unk0698;
    unsigned int unk069C;
    unsigned int unk06A0;
    unsigned int unk06A4;
    unsigned int unk06A8;
    unsigned int unk06AC;
    unsigned int unk06B0;
    unsigned int unk06B4;
    unsigned int unk06B8;
    unsigned int unk06BC;
    unsigned int unk06C0;
    unsigned int unk06C4;
    unsigned int unk06C8;
    unsigned int unk06CC;
    unsigned int unk06D0;
    unsigned int unk06D4;
    unsigned int unk06D8;
    unsigned int unk06DC;
    unsigned int unk06E0;
    unsigned int unk06E4;
    unsigned int unk06E8;
    unsigned int unk06EC;
    unsigned int unk06F0;
    unsigned int unk06F4;
    unsigned int unk06F8;
    unsigned int unk06FC;
    unsigned int unk0700;
    unsigned int unk0704;
    unsigned int unk0708;
    unsigned int unk070C;
    unsigned int unk0710;
    unsigned int unk0714;
    unsigned int unk0718;
    unsigned int unk071C;
    unsigned int unk0720;
    unsigned int unk0724;
    unsigned int unk0728;
    unsigned int unk072C;
    unsigned int unk0730;
    unsigned int unk0734;
    unsigned int unk0738;
    unsigned int unk073C;
    unsigned int unk0740;
    unsigned int unk0744;
    unsigned int unk0748;
    unsigned int unk074C;
    unsigned int unk0750;
    unsigned int unk0754;
    unsigned int unk0758;
    unsigned int unk075C;
    unsigned int unk0760;
    unsigned int unk0764;
    unsigned int unk0768;
    unsigned int unk076C;
    unsigned int unk0770;
    unsigned int unk0774;
    unsigned int unk0778;
    unsigned int unk077C;
    unsigned int unk0780;
    unsigned int unk0784;
    unsigned int unk0788;
    unsigned int unk078C;
    unsigned int unk0790;
    unsigned int unk0794;
    unsigned int unk0798;
    unsigned int unk079C;
    unsigned int unk07A0;
    unsigned int unk07A4;
    unsigned int unk07A8;
    unsigned int unk07AC;
    unsigned int unk07B0;
    unsigned int unk07B4;
    unsigned int unk07B8;
    unsigned int unk07BC;
    unsigned int unk07C0;
    unsigned int unk07C4;
    unsigned int unk07C8;
    unsigned int unk07CC;
    unsigned int unk07D0;
    unsigned int unk07D4;
    unsigned int unk07D8;
    unsigned int unk07DC;
    unsigned int unk07E0;
    unsigned int unk07E4;
    unsigned int unk07E8;
    unsigned int unk07EC;
    unsigned int unk07F0;
    unsigned int unk07F4;
    unsigned int unk07F8;
    unsigned int unk07FC;
    unsigned int unk0800;
    unsigned int unk0804;
    unsigned int unk0808;
    unsigned int unk080C;
    unsigned int unk0810;
    unsigned int unk0814;
    unsigned int unk0818;
    unsigned int unk081C;
    unsigned int unk0820;
    unsigned int unk0824;
    unsigned int unk0828;
    unsigned int unk082C;
    unsigned int unk0830;
    unsigned int unk0834;
    unsigned int unk0838;
    unsigned int unk083C;
    unsigned int unk0840;
    unsigned int unk0844;
    unsigned int unk0848;
    unsigned int unk084C;
    unsigned int unk0850;
    unsigned int unk0854;
    unsigned int unk0858;
    unsigned int unk085C;
    unsigned int unk0860;
    unsigned int unk0864;
    unsigned int unk0868;
    unsigned int unk086C;
    unsigned int unk0870;
    unsigned int unk0874;
    unsigned int unk0878;
    unsigned int unk087C;
    unsigned int unk0880;
    unsigned int unk0884;
    unsigned int unk0888;
    unsigned int unk088C;
    unsigned int unk0890;
    unsigned int unk0894;
    unsigned int unk0898;
    unsigned int unk089C;
    unsigned int unk08A0;
    unsigned int unk08A4;
    unsigned int unk08A8;
    unsigned int unk08AC;
    unsigned int unk08B0;
    unsigned int unk08B4;
    unsigned int unk08B8;
    unsigned int unk08BC;
    unsigned int unk08C0;
    unsigned int unk08C4;
    unsigned int unk08C8;
    unsigned int unk08CC;
    unsigned int unk08D0;
    unsigned int unk08D4;
    unsigned int unk08D8;
    unsigned int unk08DC;
    unsigned int unk08E0;
    unsigned int unk08E4;
    unsigned int unk08E8;
    unsigned int unk08EC;
    unsigned int unk08F0;
    unsigned int unk08F4;
    unsigned int unk08F8;
    unsigned int unk08FC;
    unsigned int unk0900;
    unsigned int unk0904;
    unsigned int unk0908;
    unsigned int unk090C;
    unsigned int unk0910;
    unsigned int unk0914;
    unsigned int unk0918;
    unsigned int unk091C;
    unsigned int unk0920;
    unsigned int unk0924;
    unsigned int unk0928;
    unsigned int unk092C;
    unsigned int unk0930;
    unsigned int unk0934;
    unsigned int unk0938;
    unsigned int unk093C;
    unsigned int unk0940;
    unsigned int unk0944;
    unsigned int unk0948;
    unsigned int unk094C;
    unsigned int unk0950;
    unsigned int unk0954;
    unsigned int unk0958;
    unsigned int unk095C;
    unsigned int unk0960;
    unsigned int unk0964;
    unsigned int unk0968;
    unsigned int unk096C;
    unsigned int unk0970;
    unsigned int unk0974;
    unsigned int unk0978;
    unsigned int unk097C;
    unsigned int unk0980;
    unsigned int unk0984;
    unsigned int unk0988;
    unsigned int unk098C;
    unsigned int unk0990;
    unsigned int unk0994;
    unsigned int unk0998;
    unsigned int unk099C;
    unsigned int unk09A0;
    unsigned int unk09A4;
    unsigned int unk09A8;
    unsigned int unk09AC;
    unsigned int unk09B0;
    unsigned int unk09B4;
    unsigned int unk09B8;
    unsigned int unk09BC;
    unsigned int unk09C0;
    unsigned int unk09C4;
    unsigned int unk09C8;
    unsigned int unk09CC;
    unsigned int unk09D0;
    unsigned int unk09D4;
    unsigned int unk09D8;
    unsigned int unk09DC;
    unsigned int unk09E0;
    unsigned int unk09E4;
    unsigned int unk09E8;
    unsigned int unk09EC;
    unsigned int unk09F0;
    unsigned int unk09F4;
    unsigned int unk09F8;
    unsigned int unk09FC;
    unsigned int unk0A00;
    unsigned int unk0A04;
    unsigned int unk0A08;
    unsigned int unk0A0C;
    unsigned int unk0A10;
    unsigned int unk0A14;
    unsigned int unk0A18;
    unsigned int unk0A1C;
    unsigned int unk0A20;
    unsigned int unk0A24;
    unsigned int unk0A28;
    unsigned int unk0A2C;
    unsigned int unk0A30;
    unsigned int unk0A34;
    unsigned int unk0A38;
    unsigned int unk0A3C;
    unsigned int unk0A40;
    unsigned int unk0A44;
    unsigned int unk0A48;
    unsigned int unk0A4C;
    unsigned int unk0A50;
    unsigned int unk0A54;
    unsigned int unk0A58;
    unsigned int unk0A5C;
    unsigned int unk0A60;
    unsigned int unk0A64;
    unsigned int unk0A68;
    unsigned int unk0A6C;
    unsigned int unk0A70;
    unsigned int unk0A74;
    unsigned int unk0A78;
    unsigned int unk0A7C;
    unsigned int unk0A80;
    unsigned int unk0A84;
    unsigned int unk0A88;
    unsigned int unk0A8C;
    unsigned int unk0A90;
    unsigned int unk0A94;
    unsigned int unk0A98;
    unsigned int unk0A9C;
    unsigned int unk0AA0;
    unsigned int unk0AA4;
    unsigned int unk0AA8;
    unsigned int unk0AAC;
    unsigned int unk0AB0;
    unsigned int unk0AB4;
    unsigned int unk0AB8;
    unsigned int unk0ABC;
    unsigned int unk0AC0;
    unsigned int unk0AC4;
    unsigned int unk0AC8;
    unsigned int unk0ACC;
    unsigned int unk0AD0;
    unsigned int unk0AD4;
    unsigned int unk0AD8;
    unsigned int unk0ADC;
    unsigned int unk0AE0;
    unsigned int unk0AE4;
    unsigned int unk0AE8;
    unsigned int unk0AEC;
    unsigned int unk0AF0;
    unsigned int unk0AF4;
    unsigned int unk0AF8;
    unsigned int unk0AFC;
    unsigned int unk0B00;
    CaravanHandState handB04;
    CaravanHandState handB14;
    CaravanHandState handB24;
    CaravanHandState handB34;
    unsigned int unk0B44;
    unsigned int unk0B48;
    unsigned int unk0B4C;
    unsigned int unk0B50;
    unsigned int unk0B54;
    unsigned int unk0B58;
    unsigned int unk0B5C;
    unsigned int unk0B60;
    unsigned int unk0B64;
    unsigned int unk0B68;
    unsigned int unk0B6C;
    unsigned int unk0B70;
    unsigned int unk0B74;
    unsigned int unk0B78;
    unsigned int unk0B7C;
    unsigned int unk0B80;
    unsigned int unk0B84;
    unsigned int unk0B88;
    unsigned int unk0B8C;
    unsigned int unk0B90;
    unsigned int unk0B94;
    unsigned int unk0B98;
    unsigned int unk0B9C;
    unsigned int unk0BA0;
    unsigned int unk0BA4;
    unsigned int unk0BA8;
    unsigned int unk0BAC;
    unsigned int unk0BB0;
    unsigned int unk0BB4;
    unsigned int unk0BB8;
    unsigned int unk0BBC;
    unsigned int unk0BC0;
    unsigned int unk0BC4;
    unsigned int unk0BC8;
    unsigned int unk0BCC;
    unsigned int unk0BD0;
    unsigned int unk0BD4;
    unsigned int unk0BD8;
    unsigned int unk0BDC;
    unsigned int unk0BE0;
    unsigned int unk0BE4;
    unsigned int unk0BE8;
    unsigned int unk0BEC;
    unsigned int unk0BF0;
    unsigned int unk0BF4;
    unsigned int unk0BF8;
    unsigned int unk0BFC;
    unsigned int unk0C00;
    unsigned int unk0C04;
    unsigned int unk0C08;
    unsigned int unk0C0C;
    unsigned int unk0C10;
    unsigned int unk0C14;
    unsigned int unk0C18;
    unsigned int unk0C1C;
    unsigned int unk0C20;
    unsigned int unk0C24;
    unsigned int unk0C28;
    unsigned int unk0C2C;
    unsigned int unk0C30;
    unsigned int unk0C34;
    unsigned int unk0C38;
    unsigned int unk0C3C;
    unsigned int unk0C40;
    unsigned int unk0C44;
    unsigned int unk0C48;
    unsigned int unk0C4C;
    unsigned int unk0C50;
    unsigned int unk0C54;
    unsigned int unk0C58;
    unsigned int unk0C5C;
    unsigned int unk0C60;
    unsigned int unk0C64;
    unsigned int unk0C68;
    unsigned int unk0C6C;
    unsigned int unk0C70;
    unsigned int unk0C74;
    unsigned int unk0C78;
    unsigned int unk0C7C;
    unsigned int unk0C80;
    unsigned int unk0C84;
    unsigned int unk0C88;
    unsigned int unk0C8C;
    unsigned int unk0C90;
    unsigned int unk0C94;
    unsigned int unk0C98;
    unsigned int unk0C9C;
    unsigned int unk0CA0;
    unsigned int unk0CA4;
    unsigned int unk0CA8;
    unsigned int unk0CAC;
    unsigned int unk0CB0;
    unsigned int unk0CB4;
    unsigned int unk0CB8;
    unsigned int unk0CBC;
    unsigned int unk0CC0;
    unsigned int unk0CC4;
    unsigned int unk0CC8;
    unsigned int unk0CCC;
    unsigned int unk0CD0;
    unsigned int unk0CD4;
    unsigned int unk0CD8;
    unsigned int unk0CDC;
    unsigned int unk0CE0;
    unsigned int unk0CE4;
    unsigned int unk0CE8;
    unsigned int unk0CEC;
    unsigned int unk0CF0;
    unsigned int unk0CF4;
    unsigned int unk0CF8;
    unsigned int unk0CFC;
    unsigned int unk0D00;
    unsigned int unk0D04;
    unsigned int unk0D08;
    unsigned int unk0D0C;
    unsigned int unk0D10;
    unsigned int unk0D14;
    unsigned int unk0D18;
    unsigned int unk0D1C;
    unsigned int unk0D20;
    unsigned int unk0D24;
    unsigned int unk0D28;
    unsigned int unk0D2C;
    unsigned int unk0D30;
    unsigned int unk0D34;
    unsigned int unk0D38;
    unsigned int unk0D3C;
    unsigned int unk0D40;
    unsigned int unk0D44;
    unsigned int unk0D48;
    unsigned int unk0D4C;
    unsigned int unk0D50;
    unsigned int unk0D54;
    unsigned int unk0D58;
    unsigned int unk0D5C;
    unsigned int unk0D60;
    unsigned int unk0D64;
    unsigned int unk0D68;
    unsigned int unk0D6C;
    unsigned int unk0D70;
    unsigned int unk0D74;
    unsigned int unk0D78;
    unsigned int unk0D7C;
    unsigned int unk0D80;
    unsigned int unk0D84;
    unsigned int unk0D88;
    unsigned int unk0D8C;
    unsigned int unk0D90;
    unsigned int unk0D94;
    unsigned int unk0D98;
    unsigned int unk0D9C;
    unsigned int unk0DA0;
    unsigned int unk0DA4;
    unsigned int unk0DA8;
    unsigned int unk0DAC;
    unsigned int unk0DB0;
    unsigned int unk0DB4;
    unsigned int unk0DB8;
    unsigned int unk0DBC;
    unsigned int unk0DC0;
    unsigned int unk0DC4;
    unsigned int unk0DC8;
    unsigned int unk0DCC;
    unsigned int unk0DD0;
    unsigned int unk0DD4;
    unsigned int unk0DD8;
    unsigned int unk0DDC;
    unsigned int unk0DE0;
    unsigned int unk0DE4;
    unsigned int unk0DE8;
    CaravanTrackState tracks[6];
    void UpdateHandStats(int);
    int CompareToTwentyOneToTwentySix(int);
    void SetFlag(int, int);
    bool CheckCaravanResult();
};
// @fnv 0x00752e20
bool CaravanResultMenu::CheckCaravanResult()
{
    int a = 0;       // Number of player track wins.
    int f = 0;       // Number of resolved track pairs.
    int eb = 0;      // Number of opponent track wins.
    int h = 0;       // Unused player total retained from the original function.
    int s = 0;       // Unused opponent total retained from the original function.
    bool p = false;  // Player has won.
    bool i = false;  // Opponent has won.
    for (int track = 0; track < 6; track++)
        UpdateHandStats(track);
    for (int pair = 0; pair < 3; pair++)
    {
        if (CompareToTwentyOneToTwentySix(tracks[pair].score) == 0 &&
            (CompareToTwentyOneToTwentySix(tracks[5 - pair].score) != 0 || tracks[pair].score > tracks[5 - pair].score))
        {
            a++;
            f++;
        }
        if (CompareToTwentyOneToTwentySix(tracks[5 - pair].score) == 0 &&
            (CompareToTwentyOneToTwentySix(tracks[pair].score) != 0 || tracks[pair].score < tracks[5 - pair].score))
        {
            eb++;
            f++;
        }
        if (a > eb && f == 3)
            p = true;
        if (a < eb && f == 3)
            i = true;
    }
    if (p)
    {
        SetFlag(0x400, 1);
        return true;
    }
    else if (i)
    {
        SetFlag(0x400, 0);
        return true;
    }
    if (handB04.FUN_0044ddc0() == 0 && handB24.FUN_0044ddc0() == 0)
    {
        SetFlag(0x400, 0);
        return true;
    }
    else if (handB14.FUN_0044ddc0() == 0 && handB34.FUN_0044ddc0() == 0)
    {
        SetFlag(0x400, 1);
        return true;
    }
    return false;
}

struct PointX
{
    float x, y, z;
};

struct UpdateDataX
{
    float fTime;
    bool m_bUpdateEnabled;
    bool bIsMultiThreaded;
    char _pad6[6];
    UpdateDataX(float afTime, bool abUpdateControllers, bool abIsMultiThreaded);
};

struct NodeX
{
    void GetTransformScale(float afX, float afY, float afZ);
    const PointX& GetTranslate();
    void Update(const UpdateDataX& arData);
};

struct TexturePtrX
{
    void* m_pObject;
    TexturePtrX(int aiNull);
    ~TexturePtrX();
    operator void*() const;
};

struct CardSlotX
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
    virtual void SetTexture(int a1, int a2, void* apTexture);
};

struct CardNameX
{
    const char* GetFullName();
};
struct CardItemX
{
    bool FUN_0073cb80();
    CardNameX* FUN_0050d100();
    CardNameX* FUN_00503650();
};
struct CardArrayX
{
    CardItemX*& GetAt(int aiIndex);
};

struct TESX
{
    void CreateTextureImage(const char* apPath, TexturePtrX& arTexture, bool abArg3, bool abArg4);
};
extern TESX* xDAT_011dea10;

NodeX* xFUN_004aae30(NodeX* apRoot, const char* apName);
void xFUN_004b7240(const char* apSrc, char* apDst, int aiSize);
float __fastcall xFUN_00526ae0(CardSlotX* apSlot);
static const char s_acAvailableShadowFmt[] = "Available_%i_Shadow:0";
int sprintf_s(char* apBuffer, unsigned int auiSize, const char* apFormat, ...);

struct CaravanMenuX
{
    char _pad000[0x188];
    NodeX* pAvailableRoot;
    NodeX* pDeckRoot;
    char _pad190[0x8ec - 0x190];
    CardSlotX* pFronts[24];
    CardSlotX* pBacks[24];
    CardSlotX* pShadows[24];
    CardSlotX* pOverlays[24];
    CardArrayX kCards;
    char _padA70[0xaf0 - 0xa70];
    unsigned int uiNumCards;

    void UpdateCardSlots(int aiFirstCard, bool abFlat);
};

// @fnv 0x0074b700
void CaravanMenuX::UpdateCardSlots(int aiFirstCard, bool abFlat)
{
    for (int i = 0; i < 0x18; i++)
    {
        if (pFronts[i] && pBacks[i] && pShadows[i] && pOverlays[i])
        {
            char acFullPathZ[260];
            int iCardIndex;
            char acPathNum48[260];
            if ((iCardIndex = aiFirstCard - (11 - i)) < 0 || iCardIndex >= uiNumCards)
            {
                int iZOffset = -50;
                if (abFlat)
                {
                    iZOffset = 0;
                }
                NodeX* pNode;
                if (i < 9)
                {
                    char acName[25];
                    sprintf_s(acName, 0x19, "Deck_0%i:%i", i + 1, i);
                    pNode = xFUN_004aae30(pDeckRoot, acName);
                    pNode->GetTransformScale(0.0f, 0.0f, (float)iZOffset);
                    sprintf_s(acName, 0x19, "Deck_0%i_Back:0", i + 1);
                    pNode = xFUN_004aae30(pDeckRoot, acName);
                    pNode->GetTransformScale(0.0f, 0.0f, (float)iZOffset);
                    sprintf_s(acName, 0x19, "Available_0%i:%i", i + 1, i);
                    pNode = xFUN_004aae30(pAvailableRoot, acName);
                    pNode->GetTransformScale(0.0f, 0.0f, (float)iZOffset);
                    sprintf_s(acName, 0x19, "Available_0%i_Back:0", i + 1);
                    pNode = xFUN_004aae30(pAvailableRoot, acName);
                    pNode->GetTransformScale(0.0f, 0.0f, (float)iZOffset);
                    sprintf_s(acName, 0x19, "Deck_0%i_Shadow:0", i + 1);
                    pNode = xFUN_004aae30(pDeckRoot, acName);
                    pNode->GetTransformScale(0.0f, 0.0f, (float)iZOffset);
                    sprintf_s(acName, 0x19, "Available_0%i_Shadow:0", i + 1);
                    pNode = xFUN_004aae30(pAvailableRoot, acName);
                    pNode->GetTransformScale(0.0f, 0.0f, (float)iZOffset);
                }
                else
                {
                    char acName[25];
                    sprintf_s(acName, 0x19, "Deck_%i:%i", i + 1, i);
                    pNode = xFUN_004aae30(pDeckRoot, acName);
                    pNode->GetTransformScale(0.0f, 0.0f, (float)iZOffset);
                    sprintf_s(acName, 0x19, "Deck_%i_Back:0", i + 1);
                    pNode = xFUN_004aae30(pDeckRoot, acName);
                    pNode->GetTransformScale(0.0f, 0.0f, (float)iZOffset);
                    sprintf_s(acName, 0x19, "Available_%i:%i", i + 1, i);
                    pNode = xFUN_004aae30(pAvailableRoot, acName);
                    pNode->GetTransformScale(0.0f, 0.0f, (float)iZOffset);
                    sprintf_s(acName, 0x19, "Available_%i_Back:0", i + 1);
                    pNode = xFUN_004aae30(pAvailableRoot, acName);
                    pNode->GetTransformScale(0.0f, 0.0f, (float)iZOffset);
                    if (i != 12 && i != 11)
                    {
                        sprintf_s(acName, 0x19, "Deck_%i_Shadow:0", i + 1);
                        pNode = xFUN_004aae30(pDeckRoot, acName);
                        pNode->GetTransformScale(0.0f, 0.0f, (float)iZOffset);
                        sprintf_s(acName, 0x19, s_acAvailableShadowFmt, i + 1);
                        pNode = xFUN_004aae30(pAvailableRoot, acName);
                        pNode->GetTransformScale(0.0f, 0.0f, (float)iZOffset);
                    }
                    else
                    {
                        sprintf_s(acName, 0x19, "Deck_%i_Shadow:0", i + 1);
                        pNode = xFUN_004aae30(pDeckRoot, acName);
                        PointX kPos = pNode->GetTranslate();
                        pNode->GetTransformScale(kPos.x, kPos.y, (float)iZOffset);
                        sprintf_s(acName, 0x19, s_acAvailableShadowFmt, i + 1);
                        pNode = xFUN_004aae30(pAvailableRoot, acName);
                        kPos = pNode->GetTranslate();
                        pNode->GetTransformScale(kPos.x, kPos.y, (float)iZOffset);
                    }
                }
                pAvailableRoot->Update(UpdateDataX(0.0f, 0, 0));
                pDeckRoot->Update(UpdateDataX(0.0f, 0, 0));
            }
            else
            {
                NodeX* pNodeB;
                if (i < 9)
                {
                    char acName[25];
                    sprintf_s(acName, 0x19, "Deck_0%i:%i", i + 1, i);
                    pNodeB = xFUN_004aae30(pDeckRoot, acName);
                    pNodeB->GetTransformScale(0.0f, 0.0f, 0.0f);
                    sprintf_s(acName, 0x19, "Deck_0%i_Back:0", i + 1);
                    pNodeB = xFUN_004aae30(pDeckRoot, acName);
                    pNodeB->GetTransformScale(0.0f, 0.0f, 0.0f);
                    sprintf_s(acName, 0x19, "Deck_0%i_Shadow:0", i + 1);
                    pNodeB = xFUN_004aae30(pDeckRoot, acName);
                    pNodeB->GetTransformScale(0.0f, 0.0f, 0.0f);
                    sprintf_s(acName, 0x19, "Available_0%i:%i", i + 1, i);
                    pNodeB = xFUN_004aae30(pAvailableRoot, acName);
                    pNodeB->GetTransformScale(0.0f, 0.0f, 0.0f);
                    sprintf_s(acName, 0x19, "Available_0%i_Back:0", i + 1);
                    pNodeB = xFUN_004aae30(pAvailableRoot, acName);
                    pNodeB->GetTransformScale(0.0f, 0.0f, 0.0f);
                    sprintf_s(acName, 0x19, "Available_0%i_Shadow:0", i + 1);
                    pNodeB = xFUN_004aae30(pAvailableRoot, acName);
                    pNodeB->GetTransformScale(0.0f, 0.0f, 0.0f);
                }
                else
                {
                    char acName[25];
                    sprintf_s(acName, 0x19, "Deck_%i:%i", i + 1, i);
                    pNodeB = xFUN_004aae30(pDeckRoot, acName);
                    pNodeB->GetTransformScale(0.0f, 0.0f, 0.0f);
                    sprintf_s(acName, 0x19, "Deck_%i_Back:0", i + 1);
                    pNodeB = xFUN_004aae30(pDeckRoot, acName);
                    pNodeB->GetTransformScale(0.0f, 0.0f, 0.0f);
                    sprintf_s(acName, 0x19, "Available_%i:%i", i + 1, i);
                    pNodeB = xFUN_004aae30(pAvailableRoot, acName);
                    pNodeB->GetTransformScale(0.0f, 0.0f, 0.0f);
                    sprintf_s(acName, 0x19, "Available_%i_Back:0", i + 1);
                    pNodeB = xFUN_004aae30(pAvailableRoot, acName);
                    pNodeB->GetTransformScale(0.0f, 0.0f, 0.0f);
                    if (i != 12 && i != 11)
                    {
                        sprintf_s(acName, 0x19, "Deck_%i_Shadow:0", i + 1);
                        pNodeB = xFUN_004aae30(pDeckRoot, acName);
                        pNodeB->GetTransformScale(0.0f, 0.0f, 0.0f);
                        sprintf_s(acName, 0x19, s_acAvailableShadowFmt, i + 1);
                        pNodeB = xFUN_004aae30(pAvailableRoot, acName);
                        pNodeB->GetTransformScale(0.0f, 0.0f, 0.0f);
                    }
                    else
                    {
                        sprintf_s(acName, 0x19, "Deck_%i_Shadow:0", i + 1);
                        pNodeB = xFUN_004aae30(pDeckRoot, acName);
                        PointX kPos = pNodeB->GetTranslate();
                        pNodeB->GetTransformScale(kPos.x, kPos.y, 0.0f);
                        sprintf_s(acName, 0x19, s_acAvailableShadowFmt, i + 1);
                        pNodeB = xFUN_004aae30(pAvailableRoot, acName);
                        kPos = pNodeB->GetTranslate();
                        pNodeB->GetTransformScale(kPos.x, kPos.y, 0.0f);
                    }
                }
                pAvailableRoot->Update(UpdateDataX(0.0f, 0, 0));
                pDeckRoot->Update(UpdateDataX(0.0f, 0, 0));
                float fValue = xFUN_00526ae0(pFronts[i]);
                if (kCards.GetAt(iCardIndex)->FUN_0073cb80())
                {
                    TexturePtrX spTexture(0);
                    sprintf_s(acPathNum48, 0x104, "%s%s", "Textures\\",
                              kCards.GetAt(iCardIndex)->FUN_0050d100()->GetFullName());
                    xFUN_004b7240(acPathNum48, acFullPathZ, 0x104);
                    xDAT_011dea10->CreateTextureImage(acFullPathZ, spTexture, 0, 0);
                    if (spTexture)
                    {
                        pFronts[i]->SetTexture(0, 0, spTexture);
                    }
                    sprintf_s(acPathNum48, 0x104, "%s%s", "Textures\\",
                              kCards.GetAt(iCardIndex)->FUN_00503650()->GetFullName());
                    xFUN_004b7240(acPathNum48, acFullPathZ, 0x104);
                    xDAT_011dea10->CreateTextureImage(acFullPathZ, spTexture, 0, 0);
                    if (spTexture)
                    {
                        pBacks[i]->SetTexture(0, 0, spTexture);
                    }
                    sprintf_s(acPathNum48, 0x104, "%s%s", "Textures\\",
                              kCards.GetAt(iCardIndex)->FUN_00503650()->GetFullName());
                    xFUN_004b7240(acPathNum48, acFullPathZ, 0x104);
                    xDAT_011dea10->CreateTextureImage(acFullPathZ, spTexture, 0, 0);
                    if (spTexture)
                    {
                        pShadows[i]->SetTexture(0, 0, spTexture);
                    }
                    sprintf_s(acPathNum48, 0x104, "%s%s", "Textures\\",
                              kCards.GetAt(iCardIndex)->FUN_0050d100()->GetFullName());
                    xFUN_004b7240(acPathNum48, acFullPathZ, 0x104);
                    xDAT_011dea10->CreateTextureImage(acFullPathZ, spTexture, 0, 0);
                    if (spTexture)
                    {
                        pOverlays[i]->SetTexture(0, 0, spTexture);
                    }
                }
                else if (kCards.GetAt(iCardIndex)->FUN_0050d100())
                {
                    TexturePtrX spTexture(0);
                    sprintf_s(acPathNum48, 0x104, "%s%s", "Textures\\",
                              kCards.GetAt(iCardIndex)->FUN_0050d100()->GetFullName());
                    xFUN_004b7240(acPathNum48, acFullPathZ, 0x104);
                    xDAT_011dea10->CreateTextureImage(acFullPathZ, spTexture, 0, 0);
                    if (spTexture)
                    {
                        pShadows[i]->SetTexture(0, 0, spTexture);
                    }
                    sprintf_s(acPathNum48, 0x104, "%s%s", "Textures\\",
                              kCards.GetAt(iCardIndex)->FUN_00503650()->GetFullName());
                    xFUN_004b7240(acPathNum48, acFullPathZ, 0x104);
                    xDAT_011dea10->CreateTextureImage(acFullPathZ, spTexture, 0, 0);
                    if (spTexture)
                    {
                        pOverlays[i]->SetTexture(0, 0, spTexture);
                    }
                    sprintf_s(acPathNum48, 0x104, "%s%s", "Textures\\",
                              kCards.GetAt(iCardIndex)->FUN_00503650()->GetFullName());
                    xFUN_004b7240(acPathNum48, acFullPathZ, 0x104);
                    xDAT_011dea10->CreateTextureImage(acFullPathZ, spTexture, 0, 0);
                    if (spTexture)
                    {
                        pFronts[i]->SetTexture(0, 0, spTexture);
                    }
                    sprintf_s(acPathNum48, 0x104, "%s%s", "Textures\\",
                              kCards.GetAt(iCardIndex)->FUN_0050d100()->GetFullName());
                    xFUN_004b7240(acPathNum48, acFullPathZ, 0x104);
                    xDAT_011dea10->CreateTextureImage(acFullPathZ, spTexture, 0, 0);
                    if (spTexture)
                    {
                        pBacks[i]->SetTexture(0, 0, spTexture);
                    }
                }
                else
                {
                    TexturePtrX spTexture(0);
                    sprintf_s(acPathNum48, 0x104, "%s%s", "Textures\\",
                              kCards.GetAt(iCardIndex)->FUN_00503650()->GetFullName());
                    xFUN_004b7240(acPathNum48, acFullPathZ, 0x104);
                    xDAT_011dea10->CreateTextureImage(acFullPathZ, spTexture, 0, 0);
                    if (spTexture)
                    {
                        pShadows[i]->SetTexture(0, 0, spTexture);
                    }
                    xDAT_011dea10->CreateTextureImage(acFullPathZ, spTexture, 0, 0);
                    if (spTexture)
                    {
                        pFronts[i]->SetTexture(0, 0, spTexture);
                    }
                }
            }
        }
    }
}

// Adapted from a contributor's 2026-10-24 reconstruction of the Caravan menu destructor.
// Unknown member offsets are recorded explicitly, preserving the source binary layout.
struct ArrA
{
    int a0;
    int a1;
    int a2;
    int a3;
    unsigned int FUN_0044ddc0();
    unsigned int* FUN_006f2270();
    void FUN_00753140();
    ~ArrA();
};
struct ObjB
{
    int a0;
    int a1;
    int a2;
    int a3;
    void FUN_008454f0(bool);
    ~ObjB();
};
struct ObjC
{
    int a0;
    int a1;
    int a2;
    int a3;
    unsigned int FUN_0044ddc0();
    void FUN_008454f0(bool);
    ~ObjC();
};
struct ListObj
{
    ~ListObj();
    void** FUN_006815c0();
    void FUN_0063f7b0();
};
struct NodeFromGO
{
    int FUN_00453470();
    void FUN_00572160();
};
struct GlobalPtr
{
    void operator=(void* x4);
};
struct ModelLoader
{
    void FUN_0045a5e0(const char* m26);
};
struct DataHandler
{
    void FUN_0046faf0();
};
extern GlobalPtr DAT_011d91a8;
extern ModelLoader* DAT_011c3b3c;
extern DataHandler* DAT_011c3f2c;
int __cdecl sprintf_s(char* v5, unsigned int n, const char* fmt, ...);
int __cdecl strcpy_s(char* v5, unsigned int n, const char* m26);
struct ShadowSceneNode
{
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void slot58(void* arg);
    void FUN_00b5d180();
};
struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
};
struct Cell1
{
    int vals[7];
};
struct Cell2
{
    int f0;
    int f1;
    int f2;
    int vals[4];
};
union GridU
{
    Cell1 c1[6];
    Cell2 c2[6];
};
struct FUN_0073bba0 : Menu_007a8b10
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
    int m_028;
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
    int m_100;
    int m_104;
    int unk108;
    int unk10c;
    int unk110;
    int m_114;
    int m_118;
    int m_11c[3];
    int m_128[3];
    ArrA m_134;
    ListObj* m_144;
    int f_148;
    ArrA m_14c;
    ListObj* m_15c;
    int f_160;
    ObjB m_164;
    ObjB m_174;
    int m_184;
    int m_188;
    int m_18c;
    int m_190;
    int m_194;
    GridU m_198;
    int m_240;
    int m_244[4];
    int m_254;
    int m_258[6];
    int m_270;
    int m_274[6];
    int m_28c[2];
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int m_304[6][7];
    int m_3ac[6][7][4][2];
    int m_8ec[96];
    ObjC m_a6c;
    ObjB m_a7c[6];
    int unkadc;
    int unkae0;
    int unkae4;
    int unkae8;
    int unkaec;
    int unkaf0;
    int unkaf4;
    int unkaf8;
    int unkafc;
    int unkb00;
    ObjC m_b04;
    ObjC m_b14;
    ObjC m_b24;
    ObjC m_b34;
    ObjC m_b44[6][7];
    int unkde4;
    int unkde8;
    int unkdec;
    int unkdf0;
    int unkdf4;
    int unkdf8;
    int unkdfc;
    int unke00;
    int unke04;
    int unke08;
    int unke0c;
    int unke10;
    int unke14;
    int unke18;
    int unke1c;
    int unke20;
    int unke24;
    int unke28;
    int unke2c;
    int unke30;
    int unke34;
    int unke38;
    int unke3c;
    int unke40;
    int unke44;
    int unke48;
    int unke4c;
    int unke50;
    int m_e54[6];
    int m_e6c;
    int m_e70;
    virtual ~FUN_0073bba0();
};
// @fnv 0x0073bba0
FUN_0073bba0::~FUN_0073bba0()
{
    int z8;
    int q47;
    int q32;
    int q13;
    int x49;
    int x39;
    int x30;
    int x28;
    int x27;
    int x4;
    int m54;
    int m52;
    int m26;
    int m19;
    int m4;
    int n39;
    char n29[260];
    int n8;
    int v59;
    void* v45;
    void* v39;
    unsigned int v28;
    unsigned int v26;
    int v21;
    int v11;
    char v5[260];
    DAT_011d91a8 = 0;
    DAT_011c3b3c->FUN_0045a5e0("Meshes\\Terminals\\NV_Caravan\\NV_Caravan-Table.NIF");
    ((ShadowSceneNode*)FUN_00450b80(1))->slot58((NodeFromGO*)DAT_011d91e4.FUN_00559450());
    ((ShadowSceneNode*)FUN_00450b80(1))->FUN_00b5d180();
    if ((NodeFromGO*)DAT_011d91e4.FUN_00559450())
    {
        if (((NodeFromGO*)DAT_011d91e4.FUN_00559450())->FUN_00453470())
        {
            ((NodeFromGO*)DAT_011d91e4.FUN_00559450())->FUN_00572160();
        }
    }
    m_184 = 0;
    m_240 = 0;
    for (v11 = 0; v11 < 4; v11++)
        m_244[v11] = 0;
    ((GlobalPtr&)DAT_011d91e4) = 0;
    DAT_011d917c = 0;
    m_100 = 0;
    m_104 = 0;
    sprintf_s(v5, 260, "%sCurrency-Bill_Grid.NIF", "Meshes\\Terminals\\NV_Caravan\\");
    DAT_011c3b3c->FUN_0045a5e0(v5);
    sprintf_s(v5, 260, "%sCurrency-Coin_Grid.NIF", "Meshes\\Terminals\\NV_Caravan\\");
    DAT_011c3b3c->FUN_0045a5e0(v5);
    m_114 = 0;
    m_118 = 0;
    for (v21 = 0; v21 < 3; v21++)
    {
        sprintf_s(v5, 260, "%sCurrency-Bill_%i.NIF", "Meshes\\Terminals\\NV_Caravan\\", v21 + 1);
        DAT_011c3b3c->FUN_0045a5e0(v5);
        sprintf_s(v5, 260, "%sCurrency-Coin_%i.NIF", "Meshes\\Terminals\\NV_Caravan\\", v21 + 1);
        DAT_011c3b3c->FUN_0045a5e0(v5);
        m_128[v21] = 0;
        m_11c[v21] = 0;
    }
    while (m_134.FUN_0044ddc0() > 0)
    {
        v26 = *m_134.FUN_006f2270();
        m_134.FUN_00753140();
        v26 = 0;
    }
    while (m_14c.FUN_0044ddc0() > 0)
    {
        v28 = *m_14c.FUN_006f2270();
        m_14c.FUN_00753140();
        v28 = 0;
    }
    while (m_15c != 0 && *m_15c->FUN_006815c0() != 0)
    {
        v39 = *m_15c->FUN_006815c0();
        m_15c->FUN_0063f7b0();
        v39 = 0;
    }
    delete m_15c;
    m_15c = 0;
    while (m_144 != 0 && *m_144->FUN_006815c0() != 0)
    {
        v45 = *m_144->FUN_006815c0();
        m_144->FUN_0063f7b0();
        v45 = 0;
    }
    delete m_144;
    m_144 = 0;
    m_174.FUN_008454f0(true);
    m_164.FUN_008454f0(true);
    if (DAT_011c3f2c != 0)
        DAT_011c3f2c->FUN_0046faf0();
    switch (m_028)
    {
    case 0:
        break;
    case 1: {
        DAT_011c3b3c->FUN_0045a5e0("Meshes\\Terminals\\NV_Caravan\\NV_Caravan-Deck.NIF");
        DAT_011c3b3c->FUN_0045a5e0("Meshes\\Terminals\\NV_Caravan\\NV_Caravan-Available.NIF");
        m_188 = 0;
        m_18c = 0;
        m_270 = 0;
        m_254 = 0;
        for (v59 = 0; v59 < 6; v59++)
        {
            m_258[v59] = 0;
            m_274[v59] = 0;
        }
        if (m_a6c.FUN_0044ddc0() > 0)
            m_a6c.FUN_008454f0(true);
        for (n8 = 0; n8 < 96; n8++)
            m_8ec[n8] = 0;
    }
    break;
    case 2:
        goto sharedStateCleanup;
    case 3:
    sharedStateCleanup: {
        for (n39 = 0; n39 < 2; n39++)
            m_28c[n39] = 0;
        for (m4 = 0; m4 < 2; m4++)
        {
            for (m19 = 0; m19 < 6; m19++)
            {
            }
        }
        for (m26 = 0; m26 < 2; m26++)
        {
            for (m52 = 0; m52 < 8; m52++)
            {
            }
        }
        for (m54 = 0; m54 < 6; m54++)
        {
            for (x4 = 0; x4 < 7; x4++)
                m_304[m54][x4] = 0;
        }
        for (x27 = 0; x27 < 6; x27++)
        {
            for (x28 = 0; x28 < 7; x28++)
            {
                x30 = 0;
                for (; x28 < 4; x28++)
                {
                    for (x39 = 0; x39 < 2; x39++)
                        m_3ac[x27][x28][x30][x39] = 0;
                }
            }
        }
        if (m_b04.FUN_0044ddc0() > 0)
            m_b04.FUN_008454f0(true);
        if (m_b14.FUN_0044ddc0() > 0)
            m_b14.FUN_008454f0(true);
        if (m_b24.FUN_0044ddc0() > 0)
            m_b24.FUN_008454f0(true);
        if (m_b34.FUN_0044ddc0() > 0)
            m_b34.FUN_008454f0(true);
        for (x49 = 0; x49 < 6; x49++)
        {
            for (q13 = 0; q13 < 7; q13++)
            {
                if (m_b44[x49][q13].FUN_0044ddc0())
                    m_b44[x49][q13].FUN_008454f0(true);
            }
        }
        strcpy_s(n29, 260, "PlayerGrid_1.NIF");
        DAT_011c3b3c->FUN_0045a5e0(n29);
        strcpy_s(n29, 260, "PlayerGrid_2.NIF");
        DAT_011c3b3c->FUN_0045a5e0(n29);
        strcpy_s(n29, 260, "PlayerGrid_3.NIF");
        DAT_011c3b3c->FUN_0045a5e0(n29);
        strcpy_s(n29, 260, "OppGrid_1.NIF");
        DAT_011c3b3c->FUN_0045a5e0(n29);
        strcpy_s(n29, 260, "OppGrid_2.NIF");
        DAT_011c3b3c->FUN_0045a5e0(n29);
        strcpy_s(n29, 260, "OppGrid_3.NIF");
        DAT_011c3b3c->FUN_0045a5e0(n29);
        strcpy_s(n29, 260, "Select_Add.NIF");
        DAT_011c3b3c->FUN_0045a5e0(n29);
        strcpy_s(n29, 260, "Select_Remove.NIF");
        DAT_011c3b3c->FUN_0045a5e0(n29);
        m_e6c = 0;
        m_e70 = 0;
        sprintf_s(n29, 260, "%s%s", "Meshes\\Terminals\\NV_Caravan\\", "Player_Deck-Start.NIF");
        DAT_011c3b3c->FUN_0045a5e0(n29);
        sprintf_s(n29, 260, "%s%s", "Meshes\\Terminals\\NV_Caravan\\", "Opponent_Deck-Start.NIF");
        DAT_011c3b3c->FUN_0045a5e0(n29);
        sprintf_s(n29, 260, "%s%s", "Meshes\\Terminals\\NV_Caravan\\", "Player_Deck.NIF");
        DAT_011c3b3c->FUN_0045a5e0(n29);
        sprintf_s(n29, 260, "%s%s", "Meshes\\Terminals\\NV_Caravan\\", "Opponent_Deck.NIF");
        DAT_011c3b3c->FUN_0045a5e0(n29);
        m_190 = 0;
        m_194 = 0;
        for (q32 = 0; q32 < 6; q32++)
            m_e54[q32] = 0;
        for (q47 = 0; q47 < 3; q47++)
        {
            for (z8 = 0; z8 < 7; z8++)
            {
                sprintf_s(n29, 260, "%sPlayer_%i_0%i.NIF", "Meshes\\Terminals\\NV_Caravan\\", q47 + 1, z8 + 1);
                DAT_011c3b3c->FUN_0045a5e0(n29);
                m_198.c1[q47].vals[z8] = 0;
                sprintf_s(n29, 260, "%sOpponent_%i_0%i.NIF", "Meshes\\Terminals\\NV_Caravan\\", q47 + 1, z8 + 1);
                DAT_011c3b3c->FUN_0045a5e0(n29);
                m_198.c2[q47 + 3].vals[z8] = 0;
            }
        }
    }
    break;
    }
}

struct SettingT_GameSettingCollection_
{
    const char* FUN_00403df0();
};
extern SettingT_GameSettingCollection_ g_011d3684;
extern SettingT_GameSettingCollection_ g_011d34f8;
extern SettingT_GameSettingCollection_ g_011d43b4;
bool __cdecl Check_00702450(int v);
void __cdecl UpdateCardSelection();
void __cdecl FUN_0074a270();
void __cdecl FUN_00717de0(int v);
void __cdecl ShowMessageBox(const char* a1, int a2, int a3, void(__cdecl* a4)(), int a5, int a6, float a7, float a8,
                          const char* a9, const char* a10, int a11);
struct Target7490
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int V13();
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
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    int unk884;
    int unk888;
    int unk88C;
    int unk890;
    int unk894;
    int unk898;
    int unk89C;
    int unk8A0;
    int unk8A4;
    int unk8A8;
    int unk8AC;
    int unk8B0;
    int unk8B4;
    int unk8B8;
    int unk8BC;
    int unk8C0;
    int unk8C4;
    int unk8C8;
    int unk8CC;
    int unk8D0;
    int unk8D4;
    int unk8D8;
    int unk8DC;
    int unk8E0;
    int unk8E4;
    int unk8E8;
    int unk8EC;
    int unk8F0;
    int unk8F4;
    int unk8F8;
    int unk8FC;
    int unk900;
    int unk904;
    int unk908;
    int unk90C;
    int unk910;
    int unk914;
    int unk918;
    int unk91C;
    int unk920;
    int unk924;
    int unk928;
    int unk92C;
    int unk930;
    int unk934;
    int unk938;
    int unk93C;
    int unk940;
    int unk944;
    int unk948;
    int unk94C;
    int unk950;
    int unk954;
    int unk958;
    int unk95C;
    int unk960;
    int unk964;
    int unk968;
    int unk96C;
    int unk970;
    int unk974;
    int unk978;
    int unk97C;
    int unk980;
    int unk984;
    int unk988;
    int unk98C;
    int unk990;
    int unk994;
    int unk998;
    int unk99C;
    int unk9A0;
    int unk9A4;
    int unk9A8;
    int unk9AC;
    int unk9B0;
    int unk9B4;
    int unk9B8;
    int unk9BC;
    int unk9C0;
    int unk9C4;
    int unk9C8;
    int unk9CC;
    int unk9D0;
    int unk9D4;
    int unk9D8;
    int unk9DC;
    int unk9E0;
    int unk9E4;
    int unk9E8;
    int unk9EC;
    int unk9F0;
    int unk9F4;
    int unk9F8;
    int unk9FC;
    int unkA00;
    int unkA04;
    int unkA08;
    int unkA0C;
    int unkA10;
    int unkA14;
    int unkA18;
    int unkA1C;
    int unkA20;
    int unkA24;
    int unkA28;
    int unkA2C;
    int unkA30;
    int unkA34;
    int unkA38;
    int unkA3C;
    int unkA40;
    int unkA44;
    int unkA48;
    int unkA4C;
    int unkA50;
    int unkA54;
    int unkA58;
    int unkA5C;
    int unkA60;
    int unkA64;
    int unkA68;
    int unkA6C;
    int unkA70;
    int unkA74;
    int unkA78;
    int unkA7C;
    int unkA80;
    int unkA84;
    int unkA88;
    int unkA8C;
    int unkA90;
    int unkA94;
    int unkA98;
    int unkA9C;
    int unkAA0;
    int unkAA4;
    int unkAA8;
    int unkAAC;
    int unkAB0;
    int unkAB4;
    int unkAB8;
    int unkABC;
    int unkAC0;
    int unkAC4;
    int unkAC8;
    int unkACC;
    int unkAD0;
    int unkAD4;
    int unkAD8;
    int unkADC;
    int unkAE0;
    int unkAE4;
    int unkAE8;
    int unkAEC;
    int unkAF0;
    int unkAF4;
    int unkAF8;
    int unkAFC;
    int unkB00;
    int unkB04;
    int unkB08;
    int unkB0C;
    int unkB10;
    int unkB14;
    int unkB18;
    int unkB1C;
    int unkB20;
    int unkB24;
    int unkB28;
    int unkB2C;
    int unkB30;
    int unkB34;
    int unkB38;
    int unkB3C;
    int unkB40;
    int unkB44;
    int unkB48;
    int unkB4C;
    int unkB50;
    int unkB54;
    int unkB58;
    int unkB5C;
    int unkB60;
    int unkB64;
    int unkB68;
    int unkB6C;
    int unkB70;
    int unkB74;
    int unkB78;
    int unkB7C;
    int unkB80;
    int unkB84;
    int unkB88;
    int unkB8C;
    int unkB90;
    int unkB94;
    int unkB98;
    int unkB9C;
    int unkBA0;
    int unkBA4;
    int unkBA8;
    int unkBAC;
    int unkBB0;
    int unkBB4;
    int unkBB8;
    int unkBBC;
    int unkBC0;
    int unkBC4;
    int unkBC8;
    int unkBCC;
    int unkBD0;
    int unkBD4;
    int unkBD8;
    int unkBDC;
    int unkBE0;
    int unkBE4;
    int unkBE8;
    int unkBEC;
    int unkBF0;
    int unkBF4;
    int unkBF8;
    int unkBFC;
    int unkC00;
    int unkC04;
    int unkC08;
    int unkC0C;
    int unkC10;
    int unkC14;
    int unkC18;
    int unkC1C;
    int unkC20;
    int unkC24;
    int unkC28;
    int unkC2C;
    int unkC30;
    int unkC34;
    int unkC38;
    int unkC3C;
    int unkC40;
    int unkC44;
    int unkC48;
    int unkC4C;
    int unkC50;
    int unkC54;
    int unkC58;
    int unkC5C;
    int unkC60;
    int unkC64;
    int unkC68;
    int unkC6C;
    int unkC70;
    int unkC74;
    int unkC78;
    int unkC7C;
    int unkC80;
    int unkC84;
    int unkC88;
    int unkC8C;
    int unkC90;
    int unkC94;
    int unkC98;
    int unkC9C;
    int unkCA0;
    int unkCA4;
    int unkCA8;
    int unkCAC;
    int unkCB0;
    int unkCB4;
    int unkCB8;
    int unkCBC;
    int unkCC0;
    int unkCC4;
    int unkCC8;
    int unkCCC;
    int unkCD0;
    int unkCD4;
    int unkCD8;
    int unkCDC;
    int unkCE0;
    int unkCE4;
    int unkCE8;
    int unkCEC;
    int unkCF0;
    int unkCF4;
    int unkCF8;
    int unkCFC;
    int unkD00;
    int unkD04;
    int unkD08;
    int unkD0C;
    int unkD10;
    int unkD14;
    int unkD18;
    int unkD1C;
    int unkD20;
    int unkD24;
    int unkD28;
    int unkD2C;
    int unkD30;
    int unkD34;
    int unkD38;
    int unkD3C;
    int unkD40;
    int unkD44;
    int unkD48;
    int unkD4C;
    int unkD50;
    int unkD54;
    int unkD58;
    int unkD5C;
    int unkD60;
    int unkD64;
    int unkD68;
    int unkD6C;
    int unkD70;
    int unkD74;
    int unkD78;
    int unkD7C;
    int unkD80;
    int unkD84;
    int unkD88;
    int unkD8C;
    int unkD90;
    int unkD94;
    int unkD98;
    int unkD9C;
    int unkDA0;
    int unkDA4;
    int unkDA8;
    int unkDAC;
    int unkDB0;
    int unkDB4;
    int unkDB8;
    int unkDBC;
    int unkDC0;
    int unkDC4;
    int unkDC8;
    int unkDCC;
    int unkDD0;
    int unkDD4;
    int unkDD8;
    int unkDDC;
    int unkDE0;
    int unkDE4;
    int unkDE8;
    int unkDEC;
    int unkDF0;
    int unkDF4;
    int unkDF8;
    int unkDFC;
    int unkE00;
    int unkE04;
    int unkE08;
    int unkE0C;
    int unkE10;
    int unkE14;
    int unkE18;
    int unkE1C;
    int unkE20;
    int unkE24;
    int unkE28;
    int unkE2C;
    int unkE30;
    bool FUN_00740f10(unsigned int flag);
    void FUN_0074ed40(int index);
    void FUN_0074edd0();
    void SetFlag(int a, int b);
    void FUN_00749a40(int v);
    bool FUN_007490e0(int aiType, int aiUnused);
};
// Returns false when flag 1 is set or type differs from 10; otherwise branches on unk28 and returns true.
// @fnv 0x007490e0
bool Target7490::FUN_007490e0(int aiType, int aiUnused)
{
    bool bResult = false;
    if (FUN_00740f10(1) || aiType != 10)
        return bResult;
    if (unk28 == 3)
    {
        bResult = true;
        if (Check_00702450(V13()))
            UpdateCardSelection();
    }
    if (unk28 == 0)
    {
        bResult = true;
        if (Check_00702450(V13()))
            UpdateCardSelection();
        ((FUN_00a253d0_shell*)g_osGlobals->FUN_00877720())->FUN_00a253d0();
    }
    else if (unk28 == 1)
    {
        bResult = true;
        if (Check_00702450(V13()))
            UpdateCardSelection();
        ((FUN_00a253d0_shell*)g_osGlobals->FUN_00877720())->FUN_00a253d0();
    }
    else if (unk28 == 2)
    {
        bResult = true;
        if (FUN_00740f10(0x1000))
        {
            if (FUN_00740f10(0x2000))
                FUN_0074ed40(unkE30);
            else
                FUN_0074edd0();
            SetFlag(0x2000, 0);
            SetFlag(0x1000, 0);
            SetFlag(4, 0);
            SetFlag(0x10, 1);
            FUN_00749a40(-1);
        }
        else if (Check_00702450(V13()))
        {
            ShowMessageBox(g_011d43b4.FUN_00403df0(), 0, 0, FUN_0074a270, 0, 0x17, 0.0f, 0.0f, g_011d34f8.FUN_00403df0(),
                         g_011d3684.FUN_00403df0(), 0);
            SetFlag(1, 1);
            bResult = true;
        }
    }
    _FUN_004b7210();
    FUN_00717de0(10);
    return true;
}

namespace fnv_0073d020 {
struct MenuTile
{
    void FUN_00700320(int, int);
    void FUN_00a01350(int, const char*, bool);
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float, bool);
    void SetTraitAndReset(int, float);
    MenuTile* FUN_00a03da0(const char*);
    void FUN_00a07530(int);
};
struct ModelNode
{
};
struct Loader
{
    ModelNode* LoadModel(const char*, int, bool, bool, bool, bool);
};
extern Loader* DAT_011c3b3c;
struct SettingText
{
    const char* FUN_00403df0();
};
extern SettingText DAT_011d2a60, DAT_011d4954, DAT_011d4168, DAT_011d2034, DAT_011d44ec, DAT_011d33fc;
struct NameView
{
    const char* FUN_0055d520();
};
int __cdecl FUN_00406d00(char*, int, const char*, ...);
unsigned __cdecl FUN_0044a670(const char*);
MenuTile* __cdecl FUN_00a08b20(MenuTile*, const char*);
struct IntArray
{
    int unk0, unk4, unk8, unkC;
    unsigned FUN_007cb2e0(const int&);
};
struct ActorStats
{
    float FUN_0066ef50(int);
};
struct ActorView
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
    ActorStats stats;
};
extern ActorView* DAT_011dea3c;
struct FUN_0073d020_Class
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
    int stateA;
    int stateB;
    MenuTile* screenA;
    MenuTile* screenB;
    MenuTile* screenC;
    MenuTile* screenD;
    MenuTile* npcBet;
    MenuTile* playerBet;
    MenuTile* pool;
    MenuTile* labelA;
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
    MenuTile* labelB;
    MenuTile* labelC;
    MenuTile* labelD;
    int unk0CC;
    MenuTile* labelE;
    MenuTile* labelF;
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
    NameView* name;
    int unk104;
    int unk108;
    float multiplier;
    int baseBet;
    ModelNode* billGrid;
    ModelNode* coinGrid;
    ModelNode* coins[3];
    ModelNode* bills[3];
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int stateC;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int stateD;
    IntArray ranks;
    IntArray cards;
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
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    int unk884;
    int unk888;
    int unk88C;
    int unk890;
    int unk894;
    int unk898;
    int unk89C;
    int unk8A0;
    int unk8A4;
    int unk8A8;
    int unk8AC;
    int unk8B0;
    int unk8B4;
    int unk8B8;
    int unk8BC;
    int unk8C0;
    int unk8C4;
    int unk8C8;
    int unk8CC;
    int unk8D0;
    int unk8D4;
    int unk8D8;
    int unk8DC;
    int unk8E0;
    int unk8E4;
    int unk8E8;
    int unk8EC;
    int unk8F0;
    int unk8F4;
    int unk8F8;
    int unk8FC;
    int unk900;
    int unk904;
    int unk908;
    int unk90C;
    int unk910;
    int unk914;
    int unk918;
    int unk91C;
    int unk920;
    int unk924;
    int unk928;
    int unk92C;
    int unk930;
    int unk934;
    int unk938;
    int unk93C;
    int unk940;
    int unk944;
    int unk948;
    int unk94C;
    int unk950;
    int unk954;
    int unk958;
    int unk95C;
    int unk960;
    int unk964;
    int unk968;
    int unk96C;
    int unk970;
    int unk974;
    int unk978;
    int unk97C;
    int unk980;
    int unk984;
    int unk988;
    int unk98C;
    int unk990;
    int unk994;
    int unk998;
    int unk99C;
    int unk9A0;
    int unk9A4;
    int unk9A8;
    int unk9AC;
    int unk9B0;
    int unk9B4;
    int unk9B8;
    int unk9BC;
    int unk9C0;
    int unk9C4;
    int unk9C8;
    int unk9CC;
    int unk9D0;
    int unk9D4;
    int unk9D8;
    int unk9DC;
    int unk9E0;
    int unk9E4;
    int unk9E8;
    int unk9EC;
    int unk9F0;
    int unk9F4;
    int unk9F8;
    int unk9FC;
    int unkA00;
    int unkA04;
    int unkA08;
    int unkA0C;
    int unkA10;
    int unkA14;
    int unkA18;
    int unkA1C;
    int unkA20;
    int unkA24;
    int unkA28;
    int unkA2C;
    int unkA30;
    int unkA34;
    int unkA38;
    int unkA3C;
    int unkA40;
    int unkA44;
    int unkA48;
    int unkA4C;
    int unkA50;
    int unkA54;
    int unkA58;
    int unkA5C;
    int unkA60;
    int unkA64;
    int unkA68;
    int unkA6C;
    int unkA70;
    int unkA74;
    int unkA78;
    int unkA7C;
    int unkA80;
    int unkA84;
    int unkA88;
    int unkA8C;
    int unkA90;
    int unkA94;
    int unkA98;
    int unkA9C;
    int unkAA0;
    int unkAA4;
    int unkAA8;
    int unkAAC;
    int unkAB0;
    int unkAB4;
    int unkAB8;
    int unkABC;
    int unkAC0;
    int unkAC4;
    int unkAC8;
    int unkACC;
    int unkAD0;
    int unkAD4;
    int unkAD8;
    int playerAmount;
    int npcAmount;
    int poolAmount;
    void FUN_0073d020();
    void ComputePlayerAndTargetTotals();
    void UpdateControls();
    void FUN_00749a40(int);
    void PlaceBillsAndCoins(int, int);
};
// Loads currency NIFs, resets state, computes bet totals, updates UI labels and controls, and places bills and coins.
// @fnv 0x0073d020
void FUN_0073d020_Class::FUN_0073d020()
{
    int amount;
    char path[260];
    {
        FUN_00406d00(path, 260, "%sCurrency-Bill_Grid.NIF", "Meshes\\Terminals\\NV_Caravan\\");
        billGrid = DAT_011c3b3c->LoadModel(path, 0, true, false, false, false);
        FUN_00406d00(path, 260, "%sCurrency-Coin_Grid.NIF", "Meshes\\Terminals\\NV_Caravan\\");
        coinGrid = DAT_011c3b3c->LoadModel(path, 0, true, false, false, false);
        for (int i = 0; i < 3; i++)
        {
            FUN_00406d00(path, 260, "%sCurrency-Bill_%i.NIF", "Meshes\\Terminals\\NV_Caravan\\", i + 1);
            bills[i] = DAT_011c3b3c->LoadModel(path, 0, true, false, false, false);
            FUN_00406d00(path, 260, "%sCurrency-Coin_%i.NIF", "Meshes\\Terminals\\NV_Caravan\\", i + 1);
            coins[i] = DAT_011c3b3c->LoadModel(path, 0, true, false, false, false);
        }
        stateA = 0;
        stateB = 0;
        stateD = 0;
        stateC = 0;
        screenA->FUN_00700320(0xfa3, 1);
        screenB->FUN_00700320(0xfa3, 0);
        screenC->FUN_00700320(0xfa3, 0);
        screenD->FUN_00700320(0xfa3, 0);
        labelE->FUN_00a01350(0xfc4, DAT_011d2a60.FUN_00403df0(), true);
        labelF->FUN_00a01350(0xfc4, DAT_011d4954.FUN_00403df0(), true);
        labelC->FUN_00a01350(0xfc4, DAT_011d4168.FUN_00403df0(), true);
        labelB->FUN_00a01350(0xfc4, DAT_011d2034.FUN_00403df0(), true);
        labelA->FUN_00a01350(0xfc4, DAT_011d44ec.FUN_00403df0(), true);
        labelD->FUN_00a01350(0xfc4, DAT_011d33fc.FUN_00403df0(), true);
        ComputePlayerAndTargetTotals();
        npcAmount = (int)(baseBet * multiplier);
        if (FUN_0044a670(name->FUN_0055d520()) > 17)
        {
            int value = FUN_0044a670(name->FUN_0055d520()) - 17;
            value *= 15;
            MenuTile* extra = FUN_00a08b20(npcBet, "CBM_NPCBetValue");
            extra->FUN_00a012d0(0xfa1, extra->FUN_00a011b0(0xfa1) + value, true);
        }
        MenuTile* info = screenA->FUN_00a03da0("CBM_InfoRect");
        if (info)
        {
            info->FUN_00a012d0(0xfb1, info->FUN_00a011b0(0xfb1) + 150.0, true);
            info->FUN_00a07530(16);
        }
        npcBet->FUN_00a01350(0xfc4, name->FUN_0055d520(), true);
        npcBet->SetTraitAndReset(DAT_011d9174, 1.0f);
        npcBet->FUN_00700320(DAT_011d9174, npcAmount);
        playerBet->SetTraitAndReset(DAT_011d9174, 1.0f);
        playerBet->FUN_00700320(DAT_011d9174, playerAmount);
        pool->SetTraitAndReset(DAT_011d9174, 1.0f);
        pool->FUN_00700320(DAT_011d9174, poolAmount);
        UpdateControls();
        FUN_00749a40(0);
        for (int rank = 0; rank < 9; rank++)
            ranks.FUN_007cb2e0(rank);
        for (int card = 0; card < 42; card++)
            cards.FUN_007cb2e0(card);
        amount = (int)(((FUN_0073d020_Class*)DAT_011d917c)->baseBet * ((FUN_0073d020_Class*)DAT_011d917c)->multiplier +
                       ((FUN_0073d020_Class*)DAT_011d917c)->baseBet * ((FUN_0073d020_Class*)DAT_011d917c)->multiplier *
                           (DAT_011dea3c->stats.FUN_0066ef50(32) / 100.0));
        PlaceBillsAndCoins(amount, npcAmount);
    }
}
}  // namespace fnv_0073d020

// 0x741500: CaravanMenu per-frame update (the caravan card game state machine).
struct CaravanGame;
struct CMUpdateData
{
    float time;
    bool a, b, c, d, e;
    CMUpdateData(float t, bool x, bool y);
};
struct CMAVObject
{
    void FUN_00a59c60(const CMUpdateData& data);
    struct A_Point* FUN_0045bb80();
    void FUN_00450f90(bool show);
};
struct CMNode : CMAVObject
{
    CMAVObject* FUN_0043b4a0(unsigned int index);
    bool ProjectToScreen(struct A_Point* pt, float* x, float* y, float tolerance);
};
struct CMNodePtr
{
    CMNode* FUN_00559450();
};
struct CMSound
{
    unsigned int id, state, flags;
    ~CMSound();
    bool Play(bool loop);
};
struct CMAudio
{
    static CMAudio* __cdecl FUN_00453a70();
    CMSound FUN_00ad7550(const char* editorID, unsigned int flags);
};
struct CMTile
{
    void FUN_00a012d0(int trait, float value, bool propagate);
    void FUN_00700320(int trait, int value);
    float FUN_00a011b0(int trait);
    void FUN_00a01350(int trait, const char* value, bool propagate);
    void SetTraitAndReset(int trait, float value);
    void FUN_00715c60(int trait, unsigned int value);
};
struct CMGate
{
    bool FUN_00718840(int id);
    void SetFlag2(int id);
};
struct CMIntfMgr
{
    int u000, u004, u008, u00c, u010, u014, u018, u01c, u020, u024, u028, u02c, u030, u034, u038, u03c;
    int u040, u044, u048, u04c, u050, u054, u058, u05c, u060, u064, u068, u06c, u070, u074, u078, u07c;
    int u080, u084, u088, u08c, u090, u094, u098, u09c, u0a0, u0a4, u0a8, u0ac, u0b0, u0b4, u0b8, u0bc;
    int u0c0, u0c4, u0c8, u0cc, u0d0, u0d4, u0d8, u0dc, u0e0, u0e4, u0e8, u0ec, u0f0, u0f4, u0f8, u0fc;
    int u100, u104, u108, u10c, u110, u114, u118, u11c, u120, u124, u128, u12c, u130, u134, u138, u13c;
    int u140, u144, u148, u14c, u150, u154, u158, u15c, u160, u164, u168, u16c, u170, u174, u178, u17c;
    int u180, u184, u188, u18c, u190, u194, u198, u19c, u1a0, u1a4, u1a8, u1ac, u1b0, u1b4, u1b8, u1bc;
    int u1c0, u1c4, u1c8, u1cc, u1d0, u1d4, u1d8, u1dc, u1e0, u1e4, u1e8, u1ec, u1f0, u1f4, u1f8, u1fc;
    int u200, u204, u208, u20c, u210, u214, u218, u21c, u220, u224, u228, u22c, u230, u234, u238, u23c;
    int u240, u244, u248, u24c, u250, u254, u258, u25c, u260, u264, u268, u26c, u270, u274, u278, u27c;
    int u280, u284, u288, u28c, u290, u294, u298, u29c, u2a0, u2a4, u2a8, u2ac, u2b0, u2b4, u2b8, u2bc;
    int u2c0, u2c4, u2c8, u2cc, u2d0, u2d4, u2d8, u2dc, u2e0, u2e4, u2e8, u2ec, u2f0, u2f4, u2f8, u2fc;
    int u300, u304, u308, u30c, u310, u314, u318, u31c, u320, u324, u328, u32c, u330, u334, u338, u33c;
    int u340, u344, u348, u34c, u350, u354, u358, u35c, u360, u364, u368, u36c, u370, u374, u378, u37c;
    int u380, u384, u388, u38c, u390, u394, u398, u39c, u3a0, u3a4, u3a8, u3ac, u3b0, u3b4, u3b8, u3bc;
    int u3c0, u3c4, u3c8, u3cc, u3d0, u3d4, u3d8, u3dc, u3e0, u3e4, u3e8, u3ec, u3f0, u3f4, u3f8, u3fc;
    int u400, u404, u408, u40c, u410, u414, u418, u41c, u420, u424, u428, u42c, u430, u434, u438, u43c;
    int u440, u444, u448, u44c, u450, u454, u458, u45c, u460, u464, u468, u46c, u470, u474, u478, u47c;
    int u480, u484, u488, u48c, u490, u494, u498, u49c, u4a0, u4a4, u4a8, u4ac, u4b0, u4b4, u4b8, u4bc;
    int u4c0, u4c4, u4c8, u4cc, u4d0;
    CMGate gate;
    static bool __cdecl FUN_004b71d0();
    CMTile* FUN_0045cd60();
};
struct CMInput
{
    int GetAxisState(int a, int b);
};
struct CMOSGlobals
{
    CMInput* FUN_00877720();
};
struct CMTime
{
    unsigned int FUN_00825c00();
};
struct CMFn
{
    static CMIntfMgr* __cdecl FUN_004b7210();
    static bool __cdecl FUN_00702450(unsigned int menuID);
    static float __cdecl FUN_00408820(float v);
};
extern float DAT_011d9208;
extern unsigned int DAT_011d9204;
extern bool DAT_011d9200;
extern CMTime DAT_011f6394;
extern CMNodePtr g_011d91e4;
extern const double DAT_01012060 = 0.0;
extern const double DAT_010718b8 = 120.0;
extern const double DAT_010718b0 = 265.0;
struct A_NodeList
{
    CMAVObject** data;
    unsigned int size, capacity, grow;
    unsigned int FUN_0044ddc0();
    CMAVObject*& FUN_006a7ad0(unsigned int index);
};
struct A_Point
{
    float x, y, z;
};
struct A_Fn
{
    static CMTile* __cdecl FUN_00a08b20(CMTile* tile, const char* name);
    static CMAVObject* __cdecl FUN_004aae30(CMAVObject* root, const char* name);
    static bool __cdecl InitTutorialMenu(BGSMessage* msg, int a);
};
struct A_Setting
{
    const char* FUN_00403df0();
};
extern A_Setting g_011d372c;
struct B_Seq
{
    float FUN_00508100();
};
struct B_CtrlMgr
{
    bool FUN_0047aab0(B_Seq* seq, int priority, bool startOver, float weight, float easeIn, B_Seq* timeSync);
    bool FUN_0047b220(B_Seq* seq, float easeOut);
    void FUN_0048fef0(float time);
};
struct B_Fn
{
    static TESForm* __cdecl FUN_00483a00(const char* editorID);
    static bool __cdecl InitTutorialMenu(BGSMessage* msg, int a);
};
struct C_Card
{
    int FUN_008d80e0();
    unsigned int FUN_004036b0();
};
struct D_Seq
{
    float FUN_00508100();
};
struct D_SeqPair
{
    D_Seq* in;
    D_Seq* out;
};
struct D_CtrlMgr
{
    bool FUN_0047aab0(D_Seq* seq, int priority, bool startOver, float weight, float easeIn, D_Seq* sync);
    bool FUN_0047b220(D_Seq* seq, float easeOut);
};
struct D_Array
{
    void* vtbl;
    int* data;
    unsigned int size, capacity;
    unsigned int FUN_0044ddc0();
    int& FUN_006a7ad0(int index);
    unsigned int FUN_007cb2e0(int& item);
    void FUN_008454f0(bool freeMem);
    void FUN_006bf8f0(unsigned int index, bool shift);
};
extern const float DAT_01012054 = -1.0f;
struct E_Move
{
    int u00, u04, kind, lane, slot, card, priority;
    int FUN_0044ddc0();
    int FUN_0084e3a0();
    int FUN_0044edb0();
    int FUN_00825c00();
    void FUN_0041fd00(int lane);
    void FUN_00437730(int slot);
    void FUN_0073b730(D_Array* list);
};
struct E_Marker
{
    int u0, u4, value;
};
struct E_Wager
{
    float FUN_00639aa0();
    int FUN_00747d00();
};
struct E_Input
{
    int FUN_00a23a50(int device, int button);
};
struct E_OSGlobals
{
    E_Input* FUN_00877720();
};
struct E_Fn
{
    static CMAVObject* __cdecl FUN_004aae30(CMAVObject* root, const char* name);
    static unsigned int __cdecl FUN_00944460(int lo, int hi);
    static int __cdecl FUN_00ec7d40(int v);
    static int __cdecl TraitNameToID(const char* name);
    static float __cdecl FUN_00715d40();
    static float __cdecl FUN_00408840(float v);
};
extern const double DAT_010718f0 = 7849.0;
extern const double DAT_01029790 = 32767.0;
struct CaravanGame
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
    virtual unsigned int GetID();
    int u004, u008, u00c, u010, u014, u018, u01c, u020, u024;
    int mode;
    int state;
    int u030, u034;
    CMTile* mainTile;
    int u03c, u040, u044, u048, u04c, u050, u054, u058, u05c, u060, u064, u068;
    CMTile* rootTile;
    int u070, u074, u078, u07c, u080, u084, u088;
    CMTile* laneTile0;
    CMTile* laneTile1;
    CMTile* laneTile2;
    CMTile* laneTile3;
    CMTile* laneTile4;
    CMTile* laneTile5;
    CMTile* sideTile[2];
    int u0ac, u0b0, u0b4, u0b8;
    CMTile* infoTile;
    int u0c0, u0c4, u0c8, u0cc, u0d0, u0d4, u0d8, u0dc, u0e0, u0e4, u0e8, u0ec, u0f0, u0f4, u0f8;
    unsigned int startTime;
    int u100, u104, u108, u10c, u110, u114, u118, u11c, u120, u124, u128, u12c, u130;
    A_NodeList chipsA;
    int u144;
    unsigned int chipsAShown;
    A_NodeList chipsB;
    int u15c;
    unsigned int chipsBShown;
    int u164, u168, u16c, u170, u174, u178, u17c, u180, u184;
    CMAVObject* boardNodeA;
    CMAVObject* boardNodeB;
    CMAVObject* sideNode[2];
    CMAVObject* cardNode[6][7];
    B_CtrlMgr* menuMgr;
    B_Seq* deckBuildSeq;
    B_Seq* startSeq;
    B_Seq* setupDoneSeq;
    int u250;
    B_CtrlMgr* boardMgrA;
    B_Seq* scrollUpSeqA;
    B_Seq* scrollDownSeqA;
    B_Seq* addRemoveSeqA;
    B_Seq* changeDeckSeqA0;
    B_Seq* changeDeckSeqA;
    B_Seq* deckDoneSeqA;
    B_CtrlMgr* boardMgrB;
    B_Seq* scrollUpSeqB;
    B_Seq* scrollDownSeqB;
    B_Seq* addRemoveSeqB;
    B_Seq* changeDeckSeqB0;
    B_Seq* changeDeckSeqB;
    B_Seq* deckDoneSeqB;
    B_CtrlMgr* sideMgr[2];
    B_Seq* sideSeq[2][6];
    B_Seq* removeSeq[2][8];
    D_CtrlMgr* cardCtrl[6][7];
    D_SeqPair cardSeq[6][7][4];
    int u8ec, u8f0, u8f4, u8f8, u8fc, u900, u904, u908, u90c, u910, u914, u918, u91c, u920, u924, u928;
    int u92c, u930, u934, u938, u93c, u940, u944, u948, u94c, u950, u954, u958, u95c, u960, u964, u968;
    int u96c, u970, u974, u978, u97c, u980, u984, u988, u98c, u990, u994, u998, u99c, u9a0, u9a4, u9a8;
    int u9ac, u9b0, u9b4, u9b8, u9bc, u9c0, u9c4, u9c8, u9cc, u9d0, u9d4, u9d8, u9dc, u9e0, u9e4, u9e8;
    int u9ec, u9f0, u9f4, u9f8, u9fc, ua00, ua04, ua08, ua0c, ua10, ua14, ua18, ua1c, ua20, ua24, ua28;
    int ua2c, ua30, ua34, ua38, ua3c, ua40, ua44, ua48, ua4c, ua50, ua54, ua58, ua5c, ua60, ua64, ua68;
    int ua6c, ua70, ua74, ua78;
    D_Array laneQueue[6];
    int uadc, uae0, uae4, uae8, uaec;
    unsigned int wagerMax;
    int uaf4;
    int wagerValue;
    int scrollPos;
    int wagerBase;
    D_Array deck[2];
    D_Array hand;
    D_Array oppHand;
    D_Array cardList[6][7];
    E_Marker laneMark[6];
    int handIndex;
    int curLane;
    int curCol;
    int animStep;
    float stateTimer;
    int pickPlayer;
    int pickOpponent;
    C_Card* playedCard;
    int e4c;
    int ue50;
    CMAVObject* sceneRoot;
    int ue58, ue5c, ue60, ue64, ue68, ue6c, ue70, ue74;
    bool helpPending;
    char ue79, ue7a, ue7b;
    int helpMessage;
    int pendingAction;
    char ue84;
    bool wagerHeld;
    bool deckChanged;
    char ue87;
    void SetFlag(int flags, int set);
    bool FUN_00740f10(unsigned int flag);
    void FUN_00749a40(int index);
    void UpdateControls();
    CMTile* FUN_00726070();
    void FUN_00a1d910();
    void FUN_00a1d9e0();
    int FUN_0059bb30();
    void ClearField();
    void UpdateCardSlots(int value, bool flag);
    void UpdateIconResources(int value);
    void FUN_0073ea90();
    void UpdateCardTexture();
    void UpdateSelection(int a);
    void UpdateDeckCardNodes(bool player, bool flag);
    void UpdateHandStats(int lane);
    void FUN_0074e220(int lane, int col, int index);
    bool CheckCaravanResult();
    void FUN_0074fdc0(E_Move* move);
    void UpdateDeckTextures(int a);
    void UpdateCaravanMenu();
    void FUN_0074ed40(int lane);
    void FUN_0074ecb0(int lane);
    void MoveSelection(int dx, int dy);
    virtual bool HandleSpecialKeyInput(int code, float value);
    void FUN_00741500();
};
// Advances the CaravanGame state machine, driving animation sequences, input handling, and card movement based on the current state and mode.
// @fnv 0x00741500
void CaravanGame::FUN_00741500()
{
    int dt = 0;
    float scale = 1.0f;
    bool active = CMFn::FUN_00702450(GetID());
    if (helpPending)
    {
        if (active && CMFn::FUN_004b7210()->gate.FUN_00718840(helpMessage))
            helpPending = false;
        else
            return;
    }
    if (!startTime)
    {
        dt = 0;
        DAT_011d9208 = 0.0f;
        DAT_011d9204 = 0;
        stateTimer = 0.0f;
    }
    else if (active)
    {
        SetFlag(0x10000, 1);
        dt = DAT_011f6394.FUN_00825c00() - startTime;
        if (DAT_011d9204 != state)
            DAT_011d9208 = 0.0f;
        else
            DAT_011d9208 += dt / 1000.0;
    }
    else
    {
        SetFlag(0x10000, 0);
        return;
    }
    int padX = 0;
    int padY = 0;
    int minIndex = 0x7fff;
    float mx = 0.0f;
    float my = 0.0f;
    if (CMFn::FUN_004b7210()->FUN_004b71d0())
    {
        padX = ((CMOSGlobals*)g_osGlobals)->FUN_00877720()->GetAxisState(0, 7);
        padY = ((CMOSGlobals*)g_osGlobals)->FUN_00877720()->GetAxisState(0, 8);
        if (CMFn::FUN_00408820((float)padX) <= DAT_010718f0)
            padX = 0;
        mx = padX / DAT_01029790;
        if (CMFn::FUN_00408820((float)padY) <= DAT_010718f0)
            padY = 0;
        my = -padY / DAT_01029790;
    }
    startTime = DAT_011f6394.FUN_00825c00();
    DAT_011d9204 = state;
    if (!active || mode == 1)
        CMFn::FUN_004b7210()->FUN_0045cd60()->FUN_00a012d0(0xfa9, 255.0f, true);
    if (FUN_00740f10(0x20000))
    {
        if (active)
        {
            SetFlag(0x20000, 0);
            state = 0x16;
        }
        return;
    }
    if (mode == 3 && state == 0 && DAT_011d9208 > 1.0)
        SetFlag(1, 0);
    switch (state)
    {
    // group M
    case 23:
        if (FUN_0059bb30() != 2)
        {
            CMFn::FUN_004b7210()->FUN_0045cd60()->FUN_00a012d0(0xfa9, 255.0f, true);
            FUN_00726070()->FUN_00700320(0x1772, 1);
            FUN_00a1d910();
            DAT_011d917c = 0;
            if (DAT_011d9200)
                FUN_00a1d9e0();
            DAT_011d9200 = true;
        }
        break;
    // group A
    case 1: {
        if (!deckBuildSeq)
            break;
        if (DAT_011d9208 == DAT_01012060)
        {
            menuMgr->FUN_0047aab0(deckBuildSeq, 0, false, 1.0f, 0.0f, 0);
            SetFlag(1, 1);
            FUN_00749a40(-1);
        }
        if (true)
        {
            CMUpdateData ud(DAT_011d9208, true, false);
            g_011d91e4.FUN_00559450()->FUN_0043b4a0(0)->FUN_00a59c60(ud);
        }
        if (DAT_011d9208 >= deckBuildSeq->FUN_00508100())
        {
            state = 0;
            menuMgr->FUN_0047b220(deckBuildSeq, 0.0f);
            SetFlag(1, 0);
            FUN_00749a40(-1);
            if (!CMFn::FUN_004b7210()->gate.FUN_00718840(0x1f))
            {
                BGSMessage* msg = dynamic_cast<BGSMessage*>(CdeclFns::FUN_00483a00("HelpCaravanDeckBuilding"));
                if (msg)
                {
                    helpPending = A_Fn::InitTutorialMenu(msg, 0);
                    CMFn::FUN_004b7210()->gate.SetFlag2(0x1f);
                    helpMessage = 0x1f;
                }
            }
        }
        break;
    }
    // group A
    case 2: {
        if (!startSeq || !sideSeq[0][0] || !sideSeq[1][0])
            break;
        if (DAT_011d9208 == DAT_01012060)
        {
            menuMgr->FUN_0047aab0(startSeq, 0, false, 1.0f, 0.0f, 0);
            ClearField();
            SetFlag(1, 1);
            sideMgr[0]->FUN_0047aab0(sideSeq[0][0], 0, false, 1.0f, 0.0f, 0);
            sideMgr[1]->FUN_0047aab0(sideSeq[1][0], 0, false, 1.0f, 0.0f, 0);
            stateTimer = 0.0f;
            CMAudio::FUN_00453a70()->FUN_00ad7550("GAMECaravanStartMatch", 0x121).Play(false);
            FUN_00749a40(-1);
        }
        if (true)
        {
            CMUpdateData udWorld(DAT_011d9208, true, false);
            CMUpdateData udA(DAT_011d9208, true, false);
            CMUpdateData udB(DAT_011d9208, true, false);
            sideNode[0]->FUN_00a59c60(udA);
            sideNode[1]->FUN_00a59c60(udB);
            g_011d91e4.FUN_00559450()->FUN_0043b4a0(0)->FUN_00a59c60(udWorld);
        }
        if (DAT_011d9208 >= startSeq->FUN_00508100() && DAT_011d9208 >= sideSeq[0][0]->FUN_00508100() &&
            DAT_011d9208 >= sideSeq[1][0]->FUN_00508100())
        {
            menuMgr->FUN_0047b220(startSeq, 0.0f);
            sideMgr[0]->FUN_0047b220(sideSeq[0][0], 0.0f);
            sideMgr[1]->FUN_0047b220(sideSeq[1][0], 0.0f);
            SetFlag(0x800, 1);
            float x = 0.0f;
            float y = 0.0f;
            int tileWidth = (int)mainTile->FUN_00a011b0(0xfb1);
            CMAVObject* sel = A_Fn::FUN_004aae30(sceneRoot, "Select1_01:0");
            ((CMNodePtr*)&g_011d91a8)->FUN_00559450()->ProjectToScreen(sel->FUN_0045bb80(), &x, &y, 1e-05f);
            x = tileWidth * x - DAT_010718b8;
            laneTile0->FUN_00a012d0(0xfa1, x, true);
            laneTile5->FUN_00a012d0(0xfa1, x, true);
            x += DAT_010718b0;
            laneTile1->FUN_00a012d0(0xfa1, x, true);
            laneTile4->FUN_00a012d0(0xfa1, x, true);
            x += DAT_010718b0;
            laneTile2->FUN_00a012d0(0xfa1, x, true);
            laneTile3->FUN_00a012d0(0xfa1, x, true);
            A_Fn::FUN_00a08b20(mainTile, "CGM_NPCTrackRect")->FUN_00700320(0xfa3, 1);
            A_Fn::FUN_00a08b20(mainTile, "CGM_PlayerTrackRect")->FUN_00700320(0xfa3, 1);
            UpdateControls();
            FUN_00749a40(-1);
            state = 0x15;
            if (!CMFn::FUN_004b7210()->gate.FUN_00718840(0x20))
            {
                BGSMessage* msg = dynamic_cast<BGSMessage*>(CdeclFns::FUN_00483a00("HelpCaravanStartingCaravans"));
                if (msg)
                {
                    helpPending = A_Fn::InitTutorialMenu(msg, 0);
                    CMFn::FUN_004b7210()->gate.SetFlag2(0x20);
                    helpMessage = 0x20;
                }
            }
        }
        break;
    }
    // group A
    case 3: {
        if (!setupDoneSeq)
            break;
        if (DAT_011d9208 == DAT_01012060)
        {
            menuMgr->FUN_0047aab0(setupDoneSeq, 0, false, 1.0f, 0.0f, 0);
            SetFlag(1, 1);
            FUN_00749a40(-1);
        }
        if (true)
        {
            CMUpdateData ud(DAT_011d9208, true, false);
            g_011d91e4.FUN_00559450()->FUN_0043b4a0(0)->FUN_00a59c60(ud);
        }
        if (DAT_011d9208 >= setupDoneSeq->FUN_00508100())
        {
            state = 0;
            mode = 3;
            menuMgr->FUN_0047b220(setupDoneSeq, 0.0f);
            SetFlag(0x4000, 0);
            infoTile->FUN_00a01350(0xfc4, g_011d372c.FUN_00403df0(), true);
            UpdateControls();
            FUN_00749a40(-1);
        }
        break;
    }
    // group A
    case 4: {
        if (DAT_011d9208 == DAT_01012060)
        {
            SetFlag(1, 1);
            CMAudio::FUN_00453a70()->FUN_00ad7550("GAMECaravanFundsDrop", 0x121).Play(false);
        }
        if (true)
        {
            for (unsigned int i = chipsBShown; i < chipsB.FUN_0044ddc0(); i++)
                chipsB.FUN_006a7ad0(i)->FUN_00a59c60(CMUpdateData(DAT_011d9208, true, false));
            for (unsigned int j = chipsAShown; j < chipsA.FUN_0044ddc0(); j++)
                chipsA.FUN_006a7ad0(j)->FUN_00a59c60(CMUpdateData(DAT_011d9208, true, false));
        }
        if (DAT_011d9208 > 1.0)
        {
            SetFlag(1, 0);
            chipsBShown = chipsB.FUN_0044ddc0();
            chipsAShown = chipsA.FUN_0044ddc0();
            state = 0;
        }
        break;
    }
    // group A
    case 5: {
        if (!scrollUpSeqB && !scrollUpSeqA)
            break;
        if (DAT_011d9208 == DAT_01012060)
        {
            boardMgrB->FUN_0047aab0(scrollUpSeqB, 0, false, 1.0f, 0.0f, 0);
            boardMgrA->FUN_0047aab0(scrollUpSeqA, 0, false, 1.0f, 0.0f, 0);
            SetFlag(1, 1);
            FUN_00749a40(-1);
            scrollPos--;
            CMAudio::FUN_00453a70()->FUN_00ad7550("GAMECaravanNavigate", 0x121).Play(false);
        }
        if (true)
        {
            CMUpdateData udSceneRoot(DAT_011d9208, true, false);
            CMUpdateData udBoardB(DAT_011d9208, true, false);
            CMUpdateData udBoardA(DAT_011d9208, true, false);
            g_011d91e4.FUN_00559450()->FUN_0043b4a0(0)->FUN_00a59c60(udSceneRoot);
            boardNodeB->FUN_00a59c60(udBoardB);
            boardNodeA->FUN_00a59c60(udBoardA);
        }
        if (DAT_011d9208 >= scrollUpSeqB->FUN_00508100())
        {
            UpdateCardSlots(rootTile->FUN_00a011b0(DAT_011d9170) - scrollPos, false);
            CMUpdateData udSceneRoot(0.0f, true, false);
            CMUpdateData udBoardB(0.0f, true, false);
            CMUpdateData udBoardA(0.0f, true, false);
            g_011d91e4.FUN_00559450()->FUN_0043b4a0(0)->FUN_00a59c60(udSceneRoot);
            boardNodeB->FUN_00a59c60(udBoardB);
            boardNodeA->FUN_00a59c60(udBoardA);
            if (scrollPos <= 0)
            {
                state = 0;
                boardMgrB->FUN_0047b220(scrollUpSeqB, 0.0f);
                boardMgrA->FUN_0047b220(scrollUpSeqA, 0.0f);
                SetFlag(1, 0);
                UpdateControls();
                FUN_00749a40(-1);
            }
            else
            {
                DAT_011d9208 = 0.0f;
                scrollPos--;
            }
            pendingAction = 0;
        }
        break;
    }
    // group A
    case 6: {
        if (!scrollDownSeqB && !scrollDownSeqA)
            break;
        if (DAT_011d9208 == DAT_01012060)
        {
            boardMgrB->FUN_0047aab0(scrollDownSeqB, 0, false, 1.0f, 0.0f, 0);
            boardMgrA->FUN_0047aab0(scrollDownSeqA, 0, false, 1.0f, 0.0f, 0);
            SetFlag(1, 1);
            FUN_00749a40(-1);
            scrollPos--;
            UpdateCardSlots(rootTile->FUN_00a011b0(DAT_011d9170) + scrollPos, false);
            CMAudio::FUN_00453a70()->FUN_00ad7550("GAMECaravanNavigate", 0x121).Play(false);
        }
        if (true)
        {
            CMUpdateData udSceneRoot(DAT_011d9208, true, false);
            CMUpdateData udBoardB(DAT_011d9208, true, false);
            CMUpdateData udBoardA(DAT_011d9208, true, false);
            g_011d91e4.FUN_00559450()->FUN_0043b4a0(0)->FUN_00a59c60(udSceneRoot);
            boardNodeB->FUN_00a59c60(udBoardB);
            boardNodeA->FUN_00a59c60(udBoardA);
        }
        if (DAT_011d9208 >= scrollDownSeqB->FUN_00508100())
        {
            if (scrollPos <= 0)
            {
                state = 0;
                boardMgrB->FUN_0047b220(scrollDownSeqB, 0.0f);
                boardMgrA->FUN_0047b220(scrollDownSeqA, 0.0f);
                SetFlag(1, 0);
                UpdateControls();
                FUN_00749a40(-1);
            }
            else
            {
                DAT_011d9208 = 0.0f;
                if (scrollPos <= 0)
                {
                    state = 0;
                    boardMgrB->FUN_0047b220(scrollUpSeqB, 0.0f);
                    boardMgrA->FUN_0047b220(scrollUpSeqA, 0.0f);
                    SetFlag(1, 0);
                    UpdateControls();
                    FUN_00749a40(-1);
                }
                else
                {
                    DAT_011d9208 = 0.0f;
                    scrollPos--;
                }
            }
            pendingAction = 0;
        }
        break;
    }
    // group A
    case 8: {
        if (!changeDeckSeqB0 && !changeDeckSeqA0)
            break;
        if (DAT_011d9208 == DAT_01012060)
        {
            UpdateCardSlots(rootTile->FUN_00a011b0(DAT_011d9170), false);
            boardMgrB->FUN_0047aab0(changeDeckSeqB0, 0, false, 1.0f, 0.0f, 0);
            boardMgrA->FUN_0047aab0(changeDeckSeqA0, 0, false, 1.0f, 0.0f, 0);
            SetFlag(1, 1);
            FUN_00749a40(-1);
            CMAudio::FUN_00453a70()->FUN_00ad7550("GAMECaravanChangeDeck", 0x121).Play(false);
        }
        if (true)
        {
            CMUpdateData udSceneRoot(DAT_011d9208, true, false);
            CMUpdateData udBoardB(DAT_011d9208, true, false);
            CMUpdateData udBoardA(DAT_011d9208, true, false);
            g_011d91e4.FUN_00559450()->FUN_0043b4a0(0)->FUN_00a59c60(udSceneRoot);
            boardNodeB->FUN_00a59c60(udBoardB);
            boardNodeA->FUN_00a59c60(udBoardA);
        }
        if (DAT_011d9208 >= changeDeckSeqB0->FUN_00508100())
        {
            state = 0;
            boardMgrB->FUN_0047b220(changeDeckSeqB0, 0.0f);
            boardMgrA->FUN_0047b220(changeDeckSeqA0, 0.0f);
            SetFlag(1, 0);
            UpdateControls();
            FUN_00749a40(-1);
            pendingAction = 0;
        }
        break;
    }
    // group B
    case 9: {
        if (!changeDeckSeqB && !changeDeckSeqA)
            break;
        if (DAT_011d9208 == DAT_01012060)
        {
            boardMgrB->FUN_0047aab0(changeDeckSeqB, 0, false, 1.0f, 0.0f, 0);
            boardMgrA->FUN_0047aab0(changeDeckSeqA, 0, false, 1.0f, 0.0f, 0);
            SetFlag(1, 1);
            FUN_00749a40(-1);
            CMAudio::FUN_00453a70()->FUN_00ad7550("GAMECaravanChangeDeck", 0x121).Play(false);
        }
        if (true)
        {
            CMUpdateData udSceneRoot(DAT_011d9208, true, false);
            CMUpdateData udBoardB(DAT_011d9208, true, false);
            CMUpdateData udBoardA(DAT_011d9208, true, false);
            g_011d91e4.FUN_00559450()->FUN_0043b4a0(0)->FUN_00a59c60(udSceneRoot);
            boardNodeB->FUN_00a59c60(udBoardB);
            boardNodeA->FUN_00a59c60(udBoardA);
        }
        if (DAT_011d9208 >= changeDeckSeqB->FUN_00508100())
        {
            state = 0;
            UpdateCardSlots(rootTile->FUN_00a011b0(DAT_011d9170), false);
            boardMgrB->FUN_0047b220(changeDeckSeqB, 0.0f);
            boardMgrA->FUN_0047b220(changeDeckSeqA, 0.0f);
            SetFlag(1, 0);
            UpdateControls();
            FUN_00749a40(-1);
            pendingAction = 0;
        }
        break;
    }
    // group B
    case 7: {
        if (!addRemoveSeqB && !addRemoveSeqA)
            break;
        if (DAT_011d9208 == DAT_01012060)
        {
            boardMgrB->FUN_0047aab0(addRemoveSeqB, 0, false, 1.0f, 0.0f, 0);
            boardMgrA->FUN_0047aab0(addRemoveSeqA, 0, false, 1.0f, 0.0f, 0);
            SetFlag(1, 1);
            FUN_00749a40(-1);
            CMAudio::FUN_00453a70()->FUN_00ad7550("GAMECaravanAddRemove", 0x121).Play(false);
        }
        if (true)
        {
            CMUpdateData udSceneRoot(DAT_011d9208, true, false);
            CMUpdateData udBoardB(DAT_011d9208, true, false);
            CMUpdateData udBoardA(DAT_011d9208, true, false);
            g_011d91e4.FUN_00559450()->FUN_0043b4a0(0)->FUN_00a59c60(udSceneRoot);
            boardNodeB->FUN_00a59c60(udBoardB);
            boardNodeA->FUN_00a59c60(udBoardA);
        }
        if (DAT_011d9208 >= addRemoveSeqB->FUN_00508100())
        {
            state = 0;
            UpdateIconResources(0xb);
            CMUpdateData udSceneRoot(0.0f, true, false);
            CMUpdateData udBoardB(0.0f, true, false);
            CMUpdateData udBoardA(0.0f, true, false);
            g_011d91e4.FUN_00559450()->FUN_0043b4a0(0)->FUN_00a59c60(udSceneRoot);
            boardNodeB->FUN_00a59c60(udBoardB);
            boardNodeA->FUN_00a59c60(udBoardA);
            boardMgrB->FUN_0047b220(addRemoveSeqB, 0.0f);
            boardMgrA->FUN_0047b220(addRemoveSeqA, 0.0f);
            SetFlag(1, 0);
            UpdateControls();
            FUN_00749a40(-1);
        }
        break;
    }
    // group B
    case 10: {
        if (!deckDoneSeqB && !deckDoneSeqA)
            break;
        if (DAT_011d9208 == DAT_01012060)
        {
            boardMgrB->FUN_0047aab0(deckDoneSeqB, 0, false, 1.0f, 0.0f, 0);
            boardMgrA->FUN_0047aab0(deckDoneSeqA, 0, false, 1.0f, 0.0f, 0);
            SetFlag(1, 1);
            FUN_00749a40(-1);
            CMAudio::FUN_00453a70()->FUN_00ad7550("GAMECaravanChangeDeck", 0x121).Play(false);
        }
        if (true)
        {
            CMUpdateData udSceneRoot(DAT_011d9208, true, false);
            CMUpdateData udBoardB(DAT_011d9208, true, false);
            CMUpdateData udBoardA(DAT_011d9208, true, false);
            g_011d91e4.FUN_00559450()->FUN_0043b4a0(0)->FUN_00a59c60(udSceneRoot);
            boardNodeB->FUN_00a59c60(udBoardB);
            boardNodeA->FUN_00a59c60(udBoardA);
        }
        if (DAT_011d9208 >= deckDoneSeqB->FUN_00508100())
        {
            state = 0;
            UpdateIconResources(0xb);
            CMUpdateData udSceneRoot(DAT_011d9208, true, false);
            CMUpdateData udBoardB(DAT_011d9208, true, false);
            CMUpdateData udBoardA(DAT_011d9208, true, false);
            g_011d91e4.FUN_00559450()->FUN_0043b4a0(0)->FUN_00a59c60(udSceneRoot);
            boardNodeB->FUN_00a59c60(udBoardB);
            boardNodeA->FUN_00a59c60(udBoardA);
            boardMgrB->FUN_0047b220(deckDoneSeqB, 0.0f);
            boardMgrA->FUN_0047b220(deckDoneSeqA, 0.0f);
            deckChanged = true;
            SetFlag(0x4000, 1);
            UpdateControls();
            FUN_00749a40(-1);
            FUN_0073ea90();
        }
        break;
    }
    // group B
    case 11: {
        int side = FUN_00740f10(0x4000);
        if (!removeSeq[side][handIndex] || !cardSeq[curLane][curCol][animStep].in)
            break;
        if (DAT_011d9208 == DAT_01012060)
        {
            UpdateCardTexture();
            sideMgr[side]->FUN_0047aab0(removeSeq[side][handIndex], 0, false, 1.0f, 0.0f, 0);
            cardCtrl[curLane][curCol]->FUN_0047aab0(cardSeq[curLane][curCol][animStep].in, 0, false, 1.0f, 0.0f, 0);
            if (side == 0)
                UpdateSelection(1);
            SetFlag(1, 1);
            stateTimer = 0.0f;
            CMAudio::FUN_00453a70()->FUN_00ad7550("GAMECaravanConfirmAddtoDeck", 0x121).Play(false);
        }
        if (true)
        {
            CMUpdateData udSide(DAT_011d9208, true, false);
            sideNode[side]->FUN_00a59c60(udSide);
            CMUpdateData udCardSlot(DAT_011d9208, true, false);
            cardNode[curLane][curCol]->FUN_00a59c60(udCardSlot);
        }
        if (DAT_011d9208 >= removeSeq[side][handIndex]->FUN_00508100() &&
            DAT_011d9208 >= cardSeq[curLane][curCol][animStep].in->FUN_00508100())
        {
            sideMgr[side]->FUN_0047b220(removeSeq[side][handIndex], 0.0f);
            cardCtrl[curLane][curCol]->FUN_0047b220(cardSeq[curLane][curCol][animStep].in, 0.0f);
            if ((cardList[2][0].FUN_0044ddc0() && !FUN_00740f10(0x4000)) ||
                (cardList[3][0].FUN_0044ddc0() && FUN_00740f10(0x4000)))
            {
                UpdateDeckCardNodes(!FUN_00740f10(0x4000), FUN_00740f10(0x800));
                sideMgr[side]->FUN_0047aab0(sideSeq[side][1], 0, false, 1.0f, 0.0f, 0);
                CMUpdateData udWar(0.0f, true, false);
                sideNode[side]->FUN_00a59c60(udWar);
                sideMgr[side]->FUN_0047b220(sideSeq[side][1], 0.0f);
                if (!FUN_00740f10(0x4000) && cardList[2][0].FUN_0044ddc0() && cardList[3][0].FUN_0044ddc0())
                {
                    SetFlag(0x800, 0);
                    if (!CMFn::FUN_004b7210()->gate.FUN_00718840(0x21))
                    {
                        BGSMessage* msg = dynamic_cast<BGSMessage*>(B_Fn::FUN_00483a00("HelpCaravanContractWar"));
                        if (msg)
                        {
                            helpPending = B_Fn::InitTutorialMenu(msg, 0);
                            CMFn::FUN_004b7210()->gate.SetFlag2(0x21);
                            helpMessage = 0x21;
                        }
                    }
                }
            }
            else
            {
                UpdateDeckCardNodes(!FUN_00740f10(0x4000), true);
                sideMgr[side]->FUN_0047aab0(removeSeq[side][0], 0, false, 1.0f, 0.0f, 0);
                CMUpdateData udDeck(0.0f, true, false);
                sideNode[side]->FUN_00a59c60(udDeck);
                sideMgr[side]->FUN_0047b220(removeSeq[side][0], 0.0f);
            }
            sideMgr[side]->FUN_0048fef0(0.0f);
            if (side == 1)
            {
                handIndex = hand.FUN_0044ddc0() - 1;
                UpdateSelection(0);
                if (FUN_00740f10(0x800) && ((C_Card*)hand.FUN_006a7ad0(handIndex))->FUN_008d80e0() > 10)
                    SetFlag(4, 1);
            }
            sideTile[side]->SetTraitAndReset(DAT_011d9174, 1.0f);
            sideTile[side]->FUN_00715c60(DAT_011d9174, side == 0 ? deck[0].FUN_0044ddc0() : deck[1].FUN_0044ddc0());
            UpdateControls();
            FUN_00749a40(-1);
            state = 0x15;
        }
        break;
    }
    // group C
    case 12: {
        int side = FUN_00740f10(0x4000);
        if (!removeSeq[side][handIndex])
            break;
        if (DAT_011d9208 == DAT_01012060)
        {
            sideMgr[side]->FUN_0047aab0(removeSeq[side][handIndex], 0, false, 1.0f, 0.0f, 0);
            if (side == 0)
                UpdateSelection(true);
            SetFlag(1, 1);
            stateTimer = 0.0f;
            CMAudio::FUN_00453a70()->FUN_00ad7550("GAMECaravanRemoveCard", 0x121).Play(false);
        }
        if (true)
        {
            CMUpdateData ud(DAT_011d9208, true, false);
            sideNode[side]->FUN_00a59c60(ud);
        }
        if (DAT_011d9208 >= removeSeq[side][handIndex]->FUN_00508100())
        {
            sideMgr[side]->FUN_0047b220(removeSeq[side][handIndex], 0.0f);
            if ((cardList[2][0].FUN_0044ddc0() && !FUN_00740f10(0x4000)) ||
                (cardList[3][0].FUN_0044ddc0() && FUN_00740f10(0x4000)))
            {
                UpdateDeckCardNodes(!FUN_00740f10(0x4000), FUN_00740f10(0x800));
                sideMgr[side]->FUN_0047aab0(sideSeq[side][1], 0, false, 1.0f, 0.0f, 0);
                CMUpdateData ud(0.0f, true, false);
                sideNode[side]->FUN_00a59c60(ud);
                sideMgr[side]->FUN_0047b220(sideSeq[side][1], 0.0f);
            }
            else
            {
                UpdateDeckCardNodes(!FUN_00740f10(0x4000), true);
                sideMgr[side]->FUN_0047aab0(removeSeq[side][0], 0, false, 1.0f, 0.0f, 0);
                CMUpdateData ud(0.0f, true, false);
                sideNode[side]->FUN_00a59c60(ud);
                sideMgr[side]->FUN_0047b220(removeSeq[side][0], 0.0f);
            }
            sideMgr[side]->FUN_0048fef0(0.0f);
            if (side == 0)
            {
                handIndex = hand.FUN_0044ddc0() - 1;
                UpdateSelection(false);
                if (FUN_00740f10(0x800) && ((C_Card*)hand.FUN_006a7ad0(handIndex))->FUN_008d80e0() > 10)
                    SetFlag(4, 1);
            }
            sideTile[side]->SetTraitAndReset(DAT_011d9174, 1.0f);
            sideTile[side]->FUN_00715c60(DAT_011d9174, side == 0 ? deck[0].FUN_0044ddc0() : deck[1].FUN_0044ddc0());
            UpdateControls();
            FUN_00749a40(-1);
            if (FUN_00740f10(0x4000))
            {
                state = 0x15;
            }
            else
            {
                state = 0;
                SetFlag(1, 0);
            }
        }
        break;
    }
    // group C
    case 13: {
        int side = FUN_00740f10(0x4000);
        if (!sideSeq[side][handIndex + 1] || !cardSeq[curLane][curCol][animStep].in)
            break;
        if (DAT_011d9208 == DAT_01012060)
        {
            UpdateCardTexture();
            if ((side == 0 ? pickPlayer : pickOpponent) == -1)
                sideMgr[side]->FUN_0047aab0(removeSeq[side][handIndex], 0, false, 1.0f, 0.0f, 0);
            else
                sideMgr[side]->FUN_0047aab0(sideSeq[side][handIndex + 1], 0, false, 1.0f, 0.0f, 0);
            cardCtrl[curLane][curCol]->FUN_0047aab0(cardSeq[curLane][curCol][animStep].in, 0, false, 1.0f, 0.0f, 0);
            if (side == 0)
                UpdateSelection(true);
            SetFlag(1, 1);
            stateTimer = 0.0f;
            CMAudio::FUN_00453a70()->FUN_00ad7550("GAMECaravanConfirmAddToTrack", 0x121).Play(false);
        }
        if (true)
        {
            CMUpdateData ud(DAT_011d9208, true, false);
            sideNode[side]->FUN_00a59c60(ud);
            CMUpdateData cardUd(DAT_011d9208, true, false);
            cardNode[curLane][curCol]->FUN_00a59c60(cardUd);
        }
        if (DAT_011d9208 >= sideSeq[side][handIndex]->FUN_00508100() &&
            DAT_011d9208 >= cardSeq[curLane][curCol][animStep].in->FUN_00508100())
        {
            sideMgr[side]->FUN_0047b220(sideSeq[side][handIndex + 1], 0.0f);
            cardCtrl[curLane][curCol]->FUN_0047b220(cardSeq[curLane][curCol][animStep].in, 0.0f);
            UpdateDeckCardNodes(!FUN_00740f10(0x4000), FUN_00740f10(0x800));
            sideMgr[side]->FUN_0047aab0(sideSeq[side][1], 0, false, 1.0f, 0.0f, 0);
            CMUpdateData ud(0.0f, true, false);
            sideNode[side]->FUN_00a59c60(ud);
            sideMgr[side]->FUN_0047b220(sideSeq[side][1], 0.0f);
            if (side == 1 && playedCard->FUN_008d80e0() != 12 && playedCard->FUN_008d80e0() != 15)
            {
                handIndex = hand.FUN_0044ddc0() - 1;
                UpdateSelection(false);
                if (FUN_00740f10(0x800) && ((C_Card*)hand.FUN_006a7ad0(handIndex))->FUN_008d80e0() > 10)
                    SetFlag(4, 1);
            }
            else if (playedCard->FUN_008d80e0() == 12 || playedCard->FUN_008d80e0() == 15)
            {
                sideTile[side]->SetTraitAndReset(DAT_011d9174, 1.0f);
                sideTile[side]->FUN_00715c60(DAT_011d9174, side == 0 ? deck[0].FUN_0044ddc0() : deck[1].FUN_0044ddc0());
                state = playedCard->FUN_008d80e0() != 12 ? 0x13 : 0x11;
                if (state == 0x13)
                {
                    int value = ((C_Card*)cardList[curLane][curCol].FUN_006a7ad0(0))->FUN_008d80e0();
                    unsigned int suitType = ((C_Card*)cardList[curLane][curCol].FUN_006a7ad0(0))->FUN_004036b0();
                    for (int i = 0; i < 6; i++)
                    {
                        for (int j = 0; j < 7; j++)
                        {
                            if (!cardList[i][j].FUN_0044ddc0())
                                break;
                            if (value != 1)
                            {
                                if (((C_Card*)cardList[i][j].FUN_006a7ad0(0))->FUN_008d80e0() == value &&
                                    (i != curLane || j != curCol))
                                    laneQueue[i].FUN_007cb2e0(j);
                            }
                            else
                            {
                                if (((C_Card*)cardList[i][j].FUN_006a7ad0(0))->FUN_004036b0() == suitType &&
                                    (i != curLane || j != curCol))
                                    laneQueue[i].FUN_007cb2e0(j);
                            }
                        }
                    }
                    curLane = 0;
                }
                break;
            }
            sideTile[side]->SetTraitAndReset(DAT_011d9174, 1.0f);
            sideTile[side]->FUN_00715c60(DAT_011d9174, side == 0 ? deck[0].FUN_0044ddc0() : deck[1].FUN_0044ddc0());
            UpdateControls();
            FUN_00749a40(-1);
            state = 0x15;
        }
        break;
    }
    // group C
    case 14: {
        int side = FUN_00740f10(0x4000);
        if (!sideSeq[side][handIndex + 1])
            break;
        if (DAT_011d9208 == DAT_01012060)
        {
            if ((side == 0 ? pickPlayer : pickOpponent) == -1)
            {
                sideMgr[side]->FUN_0047aab0(removeSeq[side][handIndex], 0, false, 1.0f, 0.0f, 0);
                CMAudio::FUN_00453a70()->FUN_00ad7550("GAMECaravanRemoveCard", 0x121).Play(false);
            }
            else
            {
                sideMgr[side]->FUN_0047aab0(sideSeq[side][handIndex + 1], 0, false, 1.0f, 0.0f, 0);
                CMAudio::FUN_00453a70()->FUN_00ad7550("GAMECaravanAddRemoveCard", 0x121).Play(false);
            }
            if (side == 0)
                UpdateSelection(true);
            SetFlag(1, 1);
            stateTimer = 0.0f;
        }
        if (true)
        {
            CMUpdateData ud(DAT_011d9208, true, false);
            sideNode[side]->FUN_00a59c60(ud);
        }
        if (DAT_011d9208 >= sideSeq[side][handIndex]->FUN_00508100())
        {
            UpdateDeckCardNodes(side == 0, false);
            sideMgr[side]->FUN_0047b220(sideSeq[side][handIndex + 1], 0.0f);
            sideMgr[side]->FUN_0047aab0(sideSeq[side][1], 0, false, 1.0f, 0.0f, 0);
            CMUpdateData ud(0.0f, true, false);
            sideNode[side]->FUN_00a59c60(ud);
            sideMgr[side]->FUN_0047b220(sideSeq[side][1], 0.0f);
            UpdateControls();
            FUN_00749a40(-1);
            sideTile[side]->SetTraitAndReset(DAT_011d9174, 1.0f);
            sideTile[side]->FUN_00715c60(DAT_011d9174, side == 0 ? deck[0].FUN_0044ddc0() : deck[1].FUN_0044ddc0());
            state = 0x15;
            handIndex = hand.FUN_0044ddc0() - 1;
            if (FUN_00740f10(0x800) && ((C_Card*)hand.FUN_006a7ad0(handIndex))->FUN_008d80e0() > 10)
                SetFlag(4, 1);
            if ((side == 1 && !FUN_00740f10(0x800)) || (side == 0 && FUN_00740f10(0x800)))
                UpdateSelection(false);
        }
        break;
    }
    // group D
    case 15: {
        if (!cardSeq[curLane][0][0].out)
            break;
        int played = 0;
        if (DAT_011d9208 == DAT_01012060)
        {
            animStep = 4;
            while (!played && animStep > 0)
            {
                animStep--;
                for (int i = 0; i < 7; i++)
                {
                    int n = cardList[curLane][i].FUN_0044ddc0();
                    if (n > animStep)
                    {
                        cardCtrl[curLane][i]->FUN_0047aab0(cardSeq[curLane][i][animStep].out, 0, false, 1.0f, 0.0f, 0);
                        played++;
                    }
                }
            }
            SetFlag(1, 1);
            stateTimer = 0.0f;
            CMAudio::FUN_00453a70()->FUN_00ad7550("GAMECaravanRemoveCard", 0x121).Play(false);
        }
        for (int i = 0; i < 7; i++)
        {
            if (!cardList[curLane][i].FUN_0044ddc0())
                break;
            cardNode[curLane][i]->FUN_00a59c60(CMUpdateData(DAT_011d9208, true, false));
        }
        if (DAT_011d9208 > cardSeq[curLane][0][animStep].out->FUN_00508100())
        {
            for (int i = 0; i < 7; i++)
                cardCtrl[curLane][i]->FUN_0047b220(cardSeq[curLane][i][animStep].out, 0.0f);
            while (!played && animStep > 0)
            {
                animStep--;
                for (int i = 0; i < 7; i++)
                {
                    int n = cardList[curLane][i].FUN_0044ddc0();
                    if (n > animStep)
                    {
                        cardCtrl[curLane][i]->FUN_0047aab0(cardSeq[curLane][i][animStep].out, 0, false, 1.0f, 0.0f, 0);
                        played++;
                    }
                }
            }
            if (played)
                DAT_011d9208 = 0.0f;
            else
            {
                for (int i = 0; i < 7; i++)
                    cardList[curLane][i].FUN_008454f0(true);
                state = 0x15;
                if (FUN_00740f10(0x4000))
                {
                    handIndex = hand.FUN_0044ddc0() - 1;
                    UpdateSelection(0);
                }
                UpdateHandStats(curLane);
                SetFlag(0x2000, 0);
                SetFlag(0x1000, 0);
            }
        }
        break;
    }
    // group D
    case 17: {
        if (!cardSeq[curLane][curCol][0].out)
            break;
        int played = 0;
        if (DAT_011d9208 == DAT_01012060)
        {
            animStep = 4;
            while (!played && animStep > 0)
            {
                animStep--;
                for (int i = curCol; i < 7; i++)
                {
                    int n = cardList[curLane][i].FUN_0044ddc0();
                    if (n > animStep)
                    {
                        cardCtrl[curLane][i]->FUN_0047aab0(cardSeq[curLane][i][animStep].out, 0, false, 1.0f, 0.0f, 0);
                        played++;
                    }
                }
            }
            SetFlag(1, 1);
        }
        if (true)
        {
            for (int i = curCol; i < 7; i++)
            {
                if (!cardList[curLane][i].FUN_0044ddc0())
                    break;
                cardNode[curLane][i]->FUN_00a59c60(CMUpdateData(DAT_011d9208, true, false));
            }
        }
        if (DAT_011d9208 > cardSeq[curLane][curCol][animStep].out->FUN_00508100())
        {
            for (int i = curCol; i < 7; i++)
                cardCtrl[curLane][i]->FUN_0047b220(cardSeq[curLane][i][animStep].out, 0.0f);
            while (!played && animStep > 0)
            {
                animStep--;
                for (int i = curCol; i < 7; i++)
                {
                    int n = cardList[curLane][i].FUN_0044ddc0();
                    if (n > animStep)
                    {
                        cardCtrl[curLane][i]->FUN_0047aab0(cardSeq[curLane][i][animStep].out, 0, false, 1.0f, 0.0f, 0);
                        played++;
                    }
                }
            }
            if (played)
                DAT_011d9208 = 0.0f;
            else
            {
                if (!FUN_00740f10(0x8000))
                {
                    for (int i = curCol; i < 6; i++)
                    {
                        cardList[curLane][i].FUN_008454f0(true);
                        D_Array* next = &cardList[curLane][i + 1];
                        for (unsigned int j = 0; j < next->FUN_0044ddc0(); j++)
                        {
                            cardList[curLane][i].FUN_007cb2e0(next->FUN_006a7ad0(j));
                            FUN_0074e220(curLane, i, j);
                        }
                    }
                    cardList[curLane][6].FUN_008454f0(true);
                }
                else
                {
                    bool more = true;
                    int colStart = curCol;
                    while (more)
                    {
                        for (int i = colStart; i < 6; i++)
                        {
                            cardList[curLane][i].FUN_008454f0(true);
                            D_Array* next = &cardList[curLane][i + 1];
                            for (unsigned int j = 0; j < next->FUN_0044ddc0(); j++)
                            {
                                cardList[curLane][i].FUN_007cb2e0(next->FUN_006a7ad0(j));
                                FUN_0074e220(curLane, i, j);
                            }
                        }
                        laneQueue[curLane].FUN_006bf8f0(0, true);
                        if (laneQueue[curLane].FUN_0044ddc0() > 0)
                        {
                            int prev = colStart;
                            colStart = laneQueue[curLane].FUN_006a7ad0(0);
                            if (colStart > prev)
                                colStart--;
                        }
                        else
                            more = false;
                    }
                }
                state = 0x12;
            }
        }
        break;
    }
    // group D
    case 18: {
        if (!cardSeq[curLane][curCol][0].in)
            break;
        int played = 0;
        bool none = false;
        if (DAT_011d9208 == DAT_01012060)
        {
            animStep = -1;
            while (!played && animStep < 4)
            {
                animStep++;
                for (int i = curCol; i < 7; i++)
                {
                    int n = cardList[curLane][i].FUN_0044ddc0();
                    if (n > animStep)
                    {
                        cardCtrl[curLane][i]->FUN_0047aab0(cardSeq[curLane][i][animStep].in, 0, false, 1.0f, 0.0f, 0);
                        played++;
                    }
                }
            }
            if (!played)
                none = true;
            SetFlag(1, 1);
        }
        if (true && !none)
        {
            for (int i = curCol; i < 7; i++)
            {
                if (!cardList[curLane][i].FUN_0044ddc0())
                    break;
                cardNode[curLane][i]->FUN_00a59c60(CMUpdateData(DAT_011d9208, true, false));
            }
        }
        if (none || DAT_011d9208 > cardSeq[curLane][curCol][animStep].in->FUN_00508100())
        {
            if (!none)
            {
                for (int i = curCol; i < 7; i++)
                    cardCtrl[curLane][i]->FUN_0047b220(cardSeq[curLane][i][animStep].in, 0.0f);
                while (!played && animStep < 4)
                {
                    animStep++;
                    for (int i = curCol; i < 7; i++)
                    {
                        int n = cardList[curLane][i].FUN_0044ddc0();
                        if (n > animStep)
                        {
                            cardCtrl[curLane][i]->FUN_0047aab0(cardSeq[curLane][i][animStep].in, 0, false, 1.0f, 0.0f,
                                                               0);
                            played++;
                        }
                    }
                }
            }
            if (played)
                DAT_011d9208 = 0.0f;
            else
            {
                UpdateHandStats(curLane);
                if (FUN_00740f10(0x8000))
                    state = 0x13;
                else
                    state = 0x15;
            }
        }
        UpdateControls();
        break;
    }
    // group D
    case 19:
        SetFlag(0x8000, 1);
        while (curLane < 6 && !laneQueue[curLane].FUN_0044ddc0())
            curLane++;
        if (curLane >= 6)
        {
            state = 0x15;
            SetFlag(0x8000, 0);
        }
        else
        {
            curCol = laneQueue[curLane].FUN_006a7ad0(0);
            state = 0x11;
        }
        break;
    // group E
    case 21: {
        // opponent turn: pick and play a move
        SetFlag(0x4000, 1);
        if (CheckCaravanResult())
        {
            state = 0x16;
            break;
        }
        if (!deckChanged)
        {
            handIndex = hand.FUN_0044ddc0() - 1;
            curLane = 0;
            playedCard = 0;
            e4c = 0;
            UpdateSelection(0);
            deckChanged = !deckChanged;
            state = 0;
            SetFlag(1, 0);
            UpdateControls();
            FUN_00749a40(-1);
            SetFlag(0x4000, 0);
            break;
        }
        deckChanged = false;
        E_Move move;
        FUN_0074fdc0(&move);
        if (FUN_00740f10(0x800))
        {
            if (move.FUN_0044ddc0() == 6)
            {
                handIndex = move.FUN_00825c00();
                playedCard = (C_Card*)oppHand.FUN_006a7ad0(handIndex);
                int drawn = deck[1].FUN_006a7ad0(pickOpponent);
                int old = oppHand.FUN_006a7ad0(handIndex);
                oppHand.FUN_006bf8f0(handIndex, true);
                oppHand.FUN_007cb2e0(drawn);
                deck[1].FUN_006bf8f0(pickOpponent, true);
                pickOpponent = E_Fn::FUN_00944460(0, deck[1].FUN_0044ddc0());
                UpdateDeckTextures(0);
                deckChanged = true;
                state = 0xc;
            }
            else
            {
                int i = 5;
                while (i > 2)
                {
                    if (!cardList[i][0].FUN_0044ddc0())
                        break;
                    i--;
                }
                curLane = i;
                handIndex = move.FUN_00825c00();
                curCol = 0;
                animStep = cardList[i][curCol].FUN_0044ddc0();
                playedCard = (C_Card*)oppHand.FUN_006a7ad0(handIndex);
                move.FUN_0041fd00(i);
                move.FUN_00437730(0);
                if ((unsigned char)DAT_011d9184)
                    move.FUN_0073b730(&oppHand);
                int cardId = oppHand.FUN_006a7ad0(handIndex);
                oppHand.FUN_006bf8f0(handIndex, true);
                cardList[i][curCol].FUN_007cb2e0(cardId);
                state = 0xb;
            }
        }
        else if (move.FUN_0044ddc0() == 6)
        {
            if (pickOpponent != -1)
            {
                handIndex = move.FUN_00825c00();
                int drawn = deck[1].FUN_006a7ad0(pickOpponent);
                int old = oppHand.FUN_006a7ad0(handIndex);
                oppHand.FUN_006bf8f0(handIndex, true);
                oppHand.FUN_007cb2e0(drawn);
                deck[1].FUN_006bf8f0(pickOpponent, true);
                if (!deck[1].FUN_0044ddc0())
                    pickOpponent = -1;
                else
                    pickOpponent = E_Fn::FUN_00944460(0, deck[1].FUN_0044ddc0());
                UpdateDeckTextures(0);
            }
            else
            {
                handIndex = move.FUN_00825c00();
                int old = oppHand.FUN_006a7ad0(handIndex);
                oppHand.FUN_006bf8f0(handIndex, true);
                UpdateDeckTextures(0);
            }
            state = 0xe;
        }
        else if (move.FUN_0044ddc0() == 5)
        {
            curLane = move.FUN_0084e3a0();
            laneMark[curLane].value = 0;
            state = 0xf;
        }
        else
        {
            if (pickOpponent != -1)
            {
                curLane = move.FUN_0084e3a0();
                curCol = move.FUN_0044edb0();
                animStep = cardList[curLane][curCol].FUN_0044ddc0();
                handIndex = move.FUN_00825c00();
                playedCard = (C_Card*)oppHand.FUN_006a7ad0(handIndex);
                int drawn = deck[1].FUN_006a7ad0(pickOpponent);
                int cardId = oppHand.FUN_006a7ad0(handIndex);
                oppHand.FUN_006bf8f0(handIndex, true);
                oppHand.FUN_007cb2e0(drawn);
                if ((unsigned char)DAT_011d9184)
                    move.FUN_0073b730(&oppHand);
                deck[1].FUN_006bf8f0(pickOpponent, true);
                if (!deck[1].FUN_0044ddc0())
                    pickOpponent = -1;
                else
                    pickOpponent = E_Fn::FUN_00944460(0, deck[1].FUN_0044ddc0());
                cardList[curLane][curCol].FUN_007cb2e0(cardId);
                UpdateDeckTextures(0);
            }
            else
            {
                CMAVObject* deckNode = E_Fn::FUN_004aae30(sideNode[1], "Opponent-Deck_06:5");
                if (deckNode)
                {
                    deckNode->FUN_00450f90(true);
                    CMUpdateData ud(0.0f, false, false);
                    deckNode->FUN_00a59c60(ud);
                }
                deckNode = E_Fn::FUN_004aae30(sideNode[1], "Opponent-Deck_Back:0");
                if (deckNode)
                {
                    deckNode->FUN_00450f90(true);
                    CMUpdateData ud(0.0f, false, false);
                    deckNode->FUN_00a59c60(ud);
                }
                deckNode = E_Fn::FUN_004aae30(sideNode[1], "Opponent-Deck_06_Shadow:0");
                if (deckNode)
                {
                    deckNode->FUN_00450f90(true);
                    CMUpdateData ud(0.0f, false, false);
                    deckNode->FUN_00a59c60(ud);
                }
                deckNode = E_Fn::FUN_004aae30(sideNode[1], "Opponent-Deck_Back_Shadow:0");
                if (deckNode)
                {
                    deckNode->FUN_00450f90(true);
                    CMUpdateData ud(0.0f, false, false);
                    deckNode->FUN_00a59c60(ud);
                }
                curLane = move.FUN_0084e3a0();
                curCol = move.FUN_0044edb0();
                animStep = cardList[curLane][curCol].FUN_0044ddc0();
                handIndex = move.FUN_00825c00();
                playedCard = (C_Card*)oppHand.FUN_006a7ad0(handIndex);
                int cardId = oppHand.FUN_006a7ad0(handIndex);
                oppHand.FUN_006bf8f0(handIndex, true);
                if ((unsigned char)DAT_011d9184)
                    move.FUN_0073b730(&oppHand);
                cardList[curLane][curCol].FUN_007cb2e0(cardId);
            }
            state = 0xd;
        }
        break;
    }
    // group E
    case 22:
        SetFlag(1, 1);
        UpdateCaravanMenu();
        state = 3;
        break;
    // group E
    case 0: {
        // idle: wager input (mode 1), card selection (mode 2), leave (mode 3)
        if (mode == 1)
        {
            if (padX)
            {
                int pos = (int)(rootTile->FUN_00a011b0(DAT_011d9170) + mx / E_Fn::FUN_00408840(mx));
                if (pos >= 0 && pos < wagerMax)
                {
                    scrollPos = 1;
                    rootTile->FUN_00a012d0(DAT_011d9170, (float)pos, false);
                    rootTile->SetTraitAndReset(E_Fn::TraitNameToID("_SetInCode"), 1.0f);
                    state = mx > DAT_01012060 ? 5 : 6;
                }
            }
            if (!CMIntfMgr::FUN_004b71d0())
            {
                if (((E_Wager*)DAT_011d9180)->FUN_00639aa0() == DAT_01012060 && wagerHeld && mode == 1)
                {
                    scrollPos = 0;
                    wagerHeld = false;
                    int cur = (int)rootTile->FUN_00a011b0(DAT_011d9170);
                    int diff;
                    if (!(diff = cur - wagerValue) && false)
                    {
                        int step = (int)(E_Fn::FUN_00715d40() / wagerMax);
                        int base = ((E_Wager*)DAT_011d9180)->FUN_00747d00();
                        diff = ((E_Wager*)DAT_011d9180)->FUN_00747d00() - wagerBase;
                        diff = diff / -step;
                        if (diff)
                        {
                            rootTile->FUN_00a012d0(DAT_011d9170,
                                                   (float)MinInt(FUN_00647b70(wagerValue + diff, 0), wagerMax), false);
                            rootTile->SetTraitAndReset(E_Fn::TraitNameToID("_SetInCode"), 1.0f);
                            if (E_Fn::FUN_00ec7d40(diff) < 5)
                            {
                                scrollPos = E_Fn::FUN_00ec7d40(diff);
                                state = diff > 0 ? 5 : 6;
                            }
                            else
                                state = diff > 0 ? 8 : 9;
                        }
                    }
                    else if (diff <= -1)
                    {
                        if (diff > -5)
                        {
                            scrollPos = -diff;
                            state = 6;
                        }
                        else
                            state = 9;
                    }
                    else if (diff >= 1)
                    {
                        if (diff < 5)
                        {
                            scrollPos = diff;
                            state = 5;
                        }
                        else
                            state = 8;
                    }
                    wagerValue = cur;
                }
                else if (!wagerHeld && ((E_Wager*)DAT_011d9180)->FUN_00639aa0() > DAT_01012060)
                {
                    wagerValue = (int)rootTile->FUN_00a011b0(DAT_011d9170);
                    wagerHeld = true;
                    wagerBase = ((E_Wager*)DAT_011d9180)->FUN_00747d00();
                }
                if (state == 0)
                {
                    if (pendingAction == 0x80000003)
                    {
                        pendingAction = 0;
                        padY = -1;
                    }
                    else if (pendingAction == 0x80000004)
                    {
                        pendingAction = 0;
                        padY = 1;
                    }
                    else if (pendingAction == 0x80000002)
                    {
                        pendingAction = 0;
                        padX = 1;
                    }
                    else if (pendingAction == 0x80000001)
                    {
                        pendingAction = 0;
                        padX = -1;
                    }
                    if (padX || padY)
                    {
                        if (startTime - stateTimer > 0.25)
                        {
                            stateTimer = startTime;
                            if (mode == 1 && padX)
                            {
                                int pos = (int)(rootTile->FUN_00a011b0(DAT_011d9170) + padX);
                                if (pos >= 0 && pos < wagerMax)
                                {
                                    rootTile->FUN_00a012d0(DAT_011d9170, (float)pos, false);
                                    rootTile->SetTraitAndReset(E_Fn::TraitNameToID("_SetInCode"), 1.0f);
                                    state = padX > 0 ? 5 : 6;
                                    scrollPos = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        else if (mode == 2)
        {
            if (state == 0)
            {
                if (pendingAction == 0x80000003)
                {
                    pendingAction = 0;
                    padY = -1;
                    my = DAT_01012054;
                }
                else if (pendingAction == 0x80000004)
                {
                    pendingAction = 0;
                    padY = 1;
                    my = 1.0f;
                }
                else if (pendingAction == 0x80000002)
                {
                    pendingAction = 0;
                    padX = 1;
                    mx = 1.0f;
                }
                else if (pendingAction == 0x80000001)
                {
                    pendingAction = 0;
                    padX = -1;
                    mx = DAT_01012054;
                }
            }
            if (padX || padY)
            {
                if (DAT_011d9208 - stateTimer > 0.25)
                {
                    stateTimer = DAT_011d9208;
                    if (!FUN_00740f10(0x1000))
                    {
                        handIndex = (int)(mx / E_Fn::FUN_00408840(mx) + handIndex);
                        int count = hand.FUN_0044ddc0();
                        if (handIndex > count - 1)
                            handIndex = 0;
                        else if (handIndex < 0)
                            handIndex = count - 1;
                        CMAudio::FUN_00453a70()->FUN_00ad7550("GAMECaravanSwitchCard", 0x121).Play(false);
                        UpdateSelection(0);
                        if (FUN_00740f10(0x800) && ((C_Card*)hand.FUN_006a7ad0(handIndex))->FUN_008d80e0() > 10)
                            SetFlag(4, 1);
                        else
                            SetFlag(4, 0);
                        FUN_00749a40(-1);
                    }
                    else if (!FUN_00740f10(0x800))
                    {
                        int stepX = (int)(E_Fn::FUN_00408840(mx) < 1.1 ? 0.0 : mx / E_Fn::FUN_00408840(mx));
                        int stepY = (int)(E_Fn::FUN_00408840(my) < 1.1 ? 0.0 : my / E_Fn::FUN_00408840(my));
                        if (FUN_00740f10(0x2000))
                        {
                            FUN_0074ed40(curLane);
                            curLane = curLane + stepX;
                            curLane = MinInt(FUN_00647b70(0, curLane), 2);
                            CMAudio::FUN_00453a70()->FUN_00ad7550("GAMECaravanToggleTrack", 0x121).Play(false);
                            FUN_0074ecb0(curLane);
                        }
                        else
                            MoveSelection(stepX, stepY);
                    }
                }
            }
        }
        else if (mode == 3)
        {
            if (((E_OSGlobals*)g_osGlobals)->FUN_00877720()->FUN_00a23a50(0, 1) ||
                ((E_OSGlobals*)g_osGlobals)->FUN_00877720()->FUN_00a23a50(1, 1))
                HandleSpecialKeyInput(9, 0.0f);
        }
        UpdateControls();
        FUN_00749a40(-1);
    }
    }
}

struct xUpdateData
{
    xUpdateData(float, bool, bool);
    float m_t;
    bool m_kPointA, m_kPointB, m_iThirdValue, m_iFourthElementInteger, m_usTrailingValue;
};
struct xNode
{
    void FUN_00450f90(bool);
    void FUN_00a59c60(const xUpdateData&);
};
xNode* xFUN_004aae30(xNode*, const char*);
struct xTile
{
    void SetTraitAndReset(int, float);
    void FUN_00700320(int, int);
    void FUN_00715c60(int, unsigned int);
    float FUN_00a011b0(int);
};
struct xCard
{
    void SetCantOpenDoors(bool);
    bool FUN_0073cb80() const;
};
template <class T> struct xArr
{
    xArr();
    ~xArr();
    unsigned int FUN_0044ddc0();
    T& FUN_006a7ad0(unsigned int);
    void FUN_006bf8f0(unsigned int, bool);
    unsigned int FUN_007cb2e0(T&);
    void FUN_008454f0(bool);
    int m_iWordAt00, m_iWordAt04, m_8, m_iThirdValue;
};
struct xSound
{
    xSound();
    ~xSound();
    bool Play(bool);
    int m_iWordAt00, m_iWordAt04, m_8;
};
struct xAudio
{
    static xAudio* FUN_00453a70();
    xSound FUN_00ad7550(const char*, unsigned int);
};
struct xAVOwner
{
    float FUN_0066ef50(int);
};
struct xPlayer
{
    char m_auiShapeKeys[0xa4];
    xAVOwner m_av;
};
extern xPlayer* xg_player_11dea3c;
struct xTrack
{
    int m_iWordAt00, m_iWordAt04, m_8;
};
bool xFUN_00702450(void*);
void xFUN_0073ca50();
int xFUN_004a8f20(int, int);
unsigned int xFUN_00944460(int, int);
void xFUN_007aba00(int, void (*)(int), int);
void xFUN_0074a090(int);
extern int xg_11d9174;
extern int xg_11d9170;

struct xCaravan
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
    virtual void* v13();
    int m_pad004[9];
    int m_28;
    int m_2c;
    int m_pad030[5];
    xTile* m_44;
    int m_pad048[2];
    xTile* m_50;
    int m_pad054[6];
    xTile* m_6c;
    int m_pad070[72];
    xNode* m_190;
    int m_pad194[566];
    xArr<xCard*> m_a6c;
    int m_pada7c[24];
    int m_adc;
    int m_ae0;
    int m_ae4;
    int m_padae8;
    unsigned int m_aec;
    int m_padaf0[5];
    xArr<xCard*> m_b04;
    int m_padb14[4];
    xArr<xCard*> m_b24;
    int m_padb34[4];
    xArr<xCard*> m_b44[6][7];
    int m_padde4[2];
    xTrack m_dec[5];
    int m_pade28;
    int m_e2c;
    int m_e30;
    int m_e34;
    int m_e38;
    int m_pade3c;
    int m_e40;
    int m_pade44[13];
    unsigned char m_e78;
    int m_10c_dummy;

    bool FUN_00740f10(unsigned int);
    void SetFlag(int, int);
    void PlaceBillsAndCoins(int, int);
    void UpdateControls();
    void FUN_00749a40(int);
    void SelectCard(int, int);
    void UpdateSelection(bool);
    void MoveSelection(int, int);
    void FUN_0074ed40(int);
    void FUN_0074edd0();
    void UpdateDeckTextures(bool);
    void InitMenu();
    void UpdateCardSlots(int, bool);
    void FUN_0074ecb0(int);
    bool FUN_00747d30(int aiKey, int aiUnused);
};
struct xGameState
{
    char m_auiShapeKeys[0x10c];
    float m_10c;
    int m_110;
};
extern xGameState* xg_11d917c;

// Processes a key press for the caravan card game, updating bets, dealing cards, and managing deck and hand state based on the current game phase.
// @fnv 0x00747d30
bool xCaravan::FUN_00747d30(int aiKey, int aiUnused)
{
    bool handled = false;
    if (FUN_00740f10(1) || m_e78 || !FUN_00740f10(0x10000))
        return m_2c == 3;
    if (FUN_00740f10(0x4000) || m_2c != 0)
        return false;

    switch (aiKey)
    {
    case 9:
        if (FUN_00740f10(4))
            return false;
        if (m_28 == 3)
        {
            handled = true;
            if (xFUN_00702450(v13()))
                xFUN_0073ca50();
        }
        if (m_28 == 0)
        {
            int OLDBET = m_adc;
            m_adc = xFUN_004a8f20(m_ae0, m_ae4);
            m_44->SetTraitAndReset(xg_11d9174, 1.0f);
            m_44->FUN_00700320(xg_11d9174, *(int*)((char*)xg_11d917c + 0xadc));
            handled = true;
            int CAPS =
                (int)(xg_11d917c->m_110 * xg_11d917c->m_10c +
                      xg_11d917c->m_110 * xg_11d917c->m_10c * (xg_player_11dea3c->m_av.FUN_0066ef50(0x20) / 100.0));
            PlaceBillsAndCoins(CAPS, m_adc - OLDBET);
            UpdateControls();
            FUN_00749a40(-1);
        }
        else if (m_28 == 1)
        {
            m_aec = m_aec + 1;
            m_50->SetTraitAndReset(xg_11d9174, 1.0f);
            m_50->FUN_00715c60(xg_11d9174, m_aec);
            int IDX = (int)m_6c->FUN_00a011b0(xg_11d9170);
            m_a6c.FUN_006a7ad0(IDX)->SetCantOpenDoors(true);
            handled = true;
            m_2c = 7;
        }
        else if (m_28 == 2)
        {
            if (FUN_00740f10(0x800) && !FUN_00740f10(0x1000))
            {
                m_e30 = 0;
                m_e34 = 0;
                m_e38 = 0;
                while (m_b44[m_e30][0].FUN_0044ddc0())
                    m_e30 = m_e30 + 1;
                if (m_e30 < 3)
                    SelectCard(m_e30, m_e34);
                UpdateSelection(true);
                xAudio::FUN_00453a70()->FUN_00ad7550("GAMECaravanAddToTrack", 0x121).Play(false);
                FUN_00749a40(-1);
                SetFlag(0x1000, 1);
                handled = true;
            }
            else if (!FUN_00740f10(0x1000))
            {
                xAudio::FUN_00453a70()->FUN_00ad7550("GAMECaravanAddToTrack", 0x121).Play(false);
                SetFlag(0x1000, 1);
                m_e30 = 0;
                m_e34 = 0;
                m_e38 = 0;
                MoveSelection(0, 0);
                handled = true;
            }
            else
            {
                if (FUN_00740f10(0x2000))
                {
                    FUN_0074ed40(m_e30);
                    m_dec[m_e30].m_iWordAt00 = 0;
                    m_2c = 15;
                    return true;
                }
                if (FUN_00740f10(0x1000))
                {
                    if (FUN_00740f10(0x800))
                    {
                        SetFlag(0x1000, 0);
                        FUN_0074edd0();
                        m_2c = 11;
                        xCard* CARD1 = m_b24.FUN_006a7ad0(m_e2c);
                        m_b24.FUN_006bf8f0(m_e2c, true);
                        m_b44[m_e30][m_e34].FUN_007cb2e0(CARD1);
                    }
                    else
                    {
                        SetFlag(0x1000, 0);
                        FUN_0074edd0();
                        m_2c = 13;
                        if (m_e40 == -1)
                        {
                            xNode* NODE = xFUN_004aae30(m_190, "Player-Deck_06_Back:0");
                            if (NODE)
                            {
                                NODE->FUN_00450f90(true);
                                xUpdateData UD1(0.0f, false, false);
                                NODE->FUN_00a59c60(UD1);
                            }
                            NODE = xFUN_004aae30(m_190, "Player-Deck_06:5");
                            if (NODE)
                            {
                                NODE->FUN_00450f90(true);
                                xUpdateData UD2(0.0f, false, false);
                                NODE->FUN_00a59c60(UD2);
                            }
                            NODE = xFUN_004aae30(m_190, "Player-Deck_06:5");
                            if (NODE)
                            {
                                NODE->FUN_00450f90(true);
                                xUpdateData UD3(0.0f, false, false);
                                NODE->FUN_00a59c60(UD3);
                            }
                            NODE = xFUN_004aae30(m_190, "Player-Deck_Back:0");
                            if (NODE)
                            {
                                NODE->FUN_00450f90(true);
                                xUpdateData UD4(0.0f, false, false);
                                NODE->FUN_00a59c60(UD4);
                            }
                            NODE = xFUN_004aae30(m_190, "Player-Deck_Back_Shadow:0");
                            if (NODE)
                            {
                                NODE->FUN_00450f90(true);
                                xUpdateData UD5(0.0f, false, false);
                                NODE->FUN_00a59c60(UD5);
                            }
                        }
                        if (m_e40 != -1)
                        {
                            xCard* qsSDDgz = m_b04.FUN_006a7ad0(m_e40);
                            xCard* qfTOqo = m_b24.FUN_006a7ad0(m_e2c);
                            m_b24.FUN_006bf8f0(m_e2c, true);
                            m_b24.FUN_007cb2e0(qsSDDgz);
                            m_b04.FUN_006bf8f0(m_e40, true);
                            m_b44[m_e30][m_e34].FUN_007cb2e0(qfTOqo);
                            if (!m_b04.FUN_0044ddc0())
                                m_e40 = -1;
                            else
                                m_e40 = xFUN_00944460(0, m_b04.FUN_0044ddc0());
                            UpdateDeckTextures(true);
                        }
                        else
                        {
                            xCard* CARD2 = m_b24.FUN_006a7ad0(m_e2c);
                            m_b24.FUN_006bf8f0(m_e2c, true);
                            m_b44[m_e30][m_e34].FUN_007cb2e0(CARD2);
                        }
                    }
                    handled = true;
                }
            }
        }
        break;
    case 11:
        if (FUN_00740f10(0x10))
            return false;
        if (m_28 == 3)
        {
            handled = true;
            if (xFUN_00702450(v13()))
                xFUN_0073ca50();
        }
        if (m_28 == 0)
        {
            SetFlag(1, 1);
            UpdateControls();
            FUN_00749a40(-1);
            if (m_ae4 - m_adc > 0)
                xFUN_007aba00(m_ae4 - m_adc, xFUN_0074a090, 0x7fffffff);
            handled = true;
        }
        else if (m_28 == 1)
        {
            m_aec = m_aec - 1;
            m_50->SetTraitAndReset(xg_11d9174, 1.0f);
            m_50->FUN_00715c60(xg_11d9174, m_aec);
            m_a6c.FUN_006a7ad0((int)m_6c->FUN_00a011b0(xg_11d9170))->SetCantOpenDoors(false);
            handled = true;
            m_2c = 7;
        }
        break;
    case 12:
        if (1)
        {
        }
        if (FUN_00740f10(2))
            return false;
        if (m_28 == 3)
        {
            handled = true;
            if (xFUN_00702450(v13()))
                xFUN_0073ca50();
        }
        if (m_28 == 0)
        {
            if (m_adc > 0 || m_ae0 == 0)
            {
                InitMenu();
                xAudio::FUN_00453a70()->FUN_00ad7550("UIMenuOK", 0x121).Play(false);
            }
            handled = true;
        }
        else if (m_28 == 1)
        {
            if (m_aec >= 30)
                m_2c = 10;
            handled = true;
        }
        break;
    case 15:
        if (1)
        {
        }
        if (m_28 == 3)
        {
            handled = true;
            if (xFUN_00702450(v13()))
                xFUN_0073ca50();
        }
        if (FUN_00740f10(0x20))
            return false;
        if (m_28 == 0)
        {
        }
        else if (m_28 == 1)
        {
            handled = true;
        }
        break;
    case 16:
        if (1)
        {
        }
        if (m_28 == 3)
        {
            handled = true;
            if (xFUN_00702450(v13()))
                xFUN_0073ca50();
        }
        if (FUN_00740f10(0x40))
            return false;
        if (m_28 == 0)
        {
        }
        else if (m_28 == 1)
        {
            xArr<int> qxQHW;
            int qArxcFu = m_a6c.FUN_0044ddc0();
            for (int I = 0; I < qArxcFu; I++)
            {
                qxQHW.FUN_007cb2e0(I);
                m_a6c.FUN_006a7ad0(I)->SetCantOpenDoors(false);
                m_aec = 0;
            }
            int qAhbO = qArxcFu > 30 ? xFUN_00944460(30, qArxcFu) : 30;
            for (int J = 0; J < qAhbO; J++)
            {
                int PICK = xFUN_00944460(0, qxQHW.FUN_0044ddc0());
                int CARDIDX = qxQHW.FUN_006a7ad0(PICK);
                qxQHW.FUN_006bf8f0(PICK, true);
                if (!m_a6c.FUN_006a7ad0(CARDIDX)->FUN_0073cb80())
                {
                    m_aec = m_aec + 1;
                    m_a6c.FUN_006a7ad0(CARDIDX)->SetCantOpenDoors(true);
                }
            }
            qxQHW.FUN_008454f0(true);
            m_50->SetTraitAndReset(xg_11d9174, 1.0f);
            m_50->FUN_00715c60(xg_11d9174, m_aec);
            UpdateControls();
            FUN_00749a40(-1);
            UpdateCardSlots((int)m_6c->FUN_00a011b0(xg_11d9170), false);
            handled = true;
        }
        break;
    case 13:
        if (1)
        {
        }
        if (m_28 == 3)
        {
            handled = true;
            if (xFUN_00702450(v13()))
                xFUN_0073ca50();
        }
        if (FUN_00740f10(0x80))
            return false;
        if (m_28 == 0)
        {
        }
        else if (m_28 == 1)
        {
        }
        else if (m_28 == 2)
        {
            if (!FUN_00740f10(0x1000) && m_b04.FUN_0044ddc0() > 0)
            {
                m_2c = FUN_00740f10(0x800) ? 12 : 14;
                if (m_e40 != -1)
                {
                    xCard* DECKCARD2 = m_b04.FUN_006a7ad0(m_e40);
                    xCard* HANDCARD2 = m_b24.FUN_006a7ad0(m_e2c);
                    m_b24.FUN_006bf8f0(m_e2c, true);
                    m_b24.FUN_007cb2e0(DECKCARD2);
                    m_b04.FUN_006bf8f0(m_e40, true);
                    if (!m_b04.FUN_0044ddc0())
                        m_e40 = -1;
                    else
                        m_e40 = xFUN_00944460(0, m_b04.FUN_0044ddc0());
                    UpdateDeckTextures(true);
                }
                else
                {
                    xCard* CARD3 = m_b24.FUN_006a7ad0(m_e2c);
                    m_b24.FUN_006bf8f0(m_e2c, true);
                }
            }
        }
        break;
    case 14:
        if (m_28 == 3)
        {
            handled = true;
            if (xFUN_00702450(v13()))
                xFUN_0073ca50();
        }
        if (FUN_00740f10(0x100))
            return false;
        if (m_28 == 0)
        {
        }
        else if (m_28 == 1)
        {
        }
        else if (m_28 == 2)
        {
            if (!FUN_00740f10(0x1000) && !FUN_00740f10(0x800))
            {
                SetFlag(0x2000, 1);
                SetFlag(0x1000, 1);
                m_e30 = 0;
                FUN_0074ecb0(m_e30);
            }
        }
        break;
    case 5:
    case 6:
    case 17:
    case 18:
        if (m_28 == 3)
        {
            handled = true;
            if (xFUN_00702450(v13()))
                xFUN_0073ca50();
        }
        break;
    }
    FUN_00749a40(-1);
    return handled;
}

struct List_749a40
{
    FNV_74A000_Action** FUN_0073ac90(int, float, int);
};
struct Slot_749a40
{
    int unk00;
    List_749a40 list;
};
struct Root_749a40 : FNV_74A000_Root
{
};
struct Menu_749a40 : Menu
{
    unsigned int unka70;
    unsigned int unka74;
    unsigned int unka78;
    unsigned int unka7c;
    unsigned int unka80;
    unsigned int unka84;
    unsigned int unka88;
    unsigned int unka8c;
    unsigned int unka90;
    unsigned int unka94;
    unsigned int unka98;
    unsigned int unka9c;
    unsigned int unkaa0;
    unsigned int unkaa4;
    unsigned int unkaa8;
    unsigned int unkaac;
    unsigned int unkab0;
    unsigned int unkab4;
    unsigned int unkab8;
    unsigned int unkabc;
    unsigned int unkac0;
    unsigned int unkac4;
    unsigned int unkac8;
    unsigned int unkacc;
    unsigned int unkad0;
    unsigned int unkad4;
    unsigned int unkad8;
    unsigned int unkadc;
    unsigned int unkae0;
    unsigned int unkae4;
    unsigned int unkae8;
    unsigned int unkaec;
    void FUN_00749a40(int slot);
};
// Updates slots with 128.0f or 255.0f according to flag checks, recursively processing grouped slots.
// @fnv 0x00749a40
void Menu_749a40::FUN_00749a40(int slot)
{
    if (slot == -1)
        slot = state;
    switch (slot)
    {
    case 0:
        FUN_00749a40(7);
        FUN_00749a40(37);
        FUN_00749a40(36);
        break;
    case 1:
        FUN_00749a40(8);
        FUN_00749a40(9);
        FUN_00749a40(11);
        FUN_00749a40(10);
        FUN_00749a40(12);
        FUN_00749a40(13);
        FUN_00749a40(14);
        break;
    case 2:
        FUN_00749a40(20);
        FUN_00749a40(21);
        FUN_00749a40(19);
        FUN_00749a40(22);
        break;
    case 3:
    case 4:
    case 5:
    case 6:
        break;
    case 7:
        if (((FUN_00740f10_shell*)this)->FUN_00740f10(2) || ((FUN_00740f10_shell*)this)->FUN_00740f10(1))
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 128.0f);
        else
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 255.0f);
        break;
    case 37:
        if (((FUN_00740f10_shell*)this)->FUN_00740f10(4) || ((FUN_00740f10_shell*)this)->FUN_00740f10(1))
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 128.0f);
        else
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 255.0f);
        break;
    case 36:
        if (((FUN_00740f10_shell*)this)->FUN_00740f10(16) || ((FUN_00740f10_shell*)this)->FUN_00740f10(1))
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 128.0f);
        else
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 255.0f);
        break;
    case 8:
        if (((FUN_00740f10_shell*)this)->FUN_00740f10(2))
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 128.0f);
        else
        {
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 255.0f);
            if (unkaec < 30)
                (*((Slot_749a40*)((FNV_74A000_Root*)this)->slots[slot])->list.FUN_0073ac90(4009, 128.0f, 1))
                    ->FUN_00a012d0();
            else
                (*((Slot_749a40*)((FNV_74A000_Root*)this)->slots[slot])->list.FUN_0073ac90(4009, 255.0f, 1))
                    ->FUN_00a012d0();
        }
        break;
    case 9:
        ((FNV_74A000_This*)this)->FUN_0074a000(slot, 255.0f);
        break;
    case 10:
        if (((FUN_00740f10_shell*)this)->FUN_00740f10(64))
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 128.0f);
        else
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 255.0f);
        break;
    case 11:
        ((FNV_74A000_This*)this)->FUN_0074a000(slot, 255.0f);
        break;
    case 12:
        if (((FUN_00740f10_shell*)this)->FUN_00740f10(4) || ((FUN_00740f10_shell*)this)->FUN_00740f10(1))
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 128.0f);
        else
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 255.0f);
        break;
    case 13:
        if (((FUN_00740f10_shell*)this)->FUN_00740f10(16) || ((FUN_00740f10_shell*)this)->FUN_00740f10(1))
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 128.0f);
        else
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 255.0f);
        break;
    case 14:
        if (((FUN_00740f10_shell*)this)->FUN_00740f10(2) || ((FUN_00740f10_shell*)this)->FUN_00740f10(1))
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 128.0f);
        else
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 255.0f);
        break;
    case 20:
        if (((FUN_00740f10_shell*)this)->FUN_00740f10(128) || ((FUN_00740f10_shell*)this)->FUN_00740f10(1))
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 128.0f);
        else
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 255.0f);
        break;
    case 21:
        if (((FUN_00740f10_shell*)this)->FUN_00740f10(256) || ((FUN_00740f10_shell*)this)->FUN_00740f10(1))
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 128.0f);
        else
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 255.0f);
        break;
    case 19:
        if (((FUN_00740f10_shell*)this)->FUN_00740f10(4) || ((FUN_00740f10_shell*)this)->FUN_00740f10(1))
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 128.0f);
        else
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 255.0f);
        break;
    case 22:
        if (((FUN_00740f10_shell*)this)->FUN_00740f10(8) || ((FUN_00740f10_shell*)this)->FUN_00740f10(1))
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 128.0f);
        else
            ((FNV_74A000_This*)this)->FUN_0074a000(slot, 255.0f);
        break;
    }
}

namespace fnv_0073ea90 {
struct CardBase0
{
    int m_iType;
};
struct CardBase1
{
    int m_iType;
};
struct Card
{
    bool FUN_0073cb80();
};
struct CardList
{
    void FUN_00470470();
    void FUN_005ae3d0(Card* const& card);
};
struct CardNode
{
    Card** FUN_006815c0();
    CardNode* FUN_00726070();
};
struct CardArray
{
    Card** m_pData;
    int m_iCapacity;
    int m_iArrayLength;
    int m_iGrow;
    unsigned int FUN_0044ddc0();
    Card*& FUN_006a7ad0(unsigned int index);
    void FUN_007cb2e0(Card* const& card);
    void FUN_009a4320(int index, int count);
    void FUN_008454f0(int flag);
};
struct CaravanGame
{
    CardList* GetField618();
    CardList* GetField614();
    int FUN_00740960();
    int GetRegionDataManager();
    int GetFieldAtOffset61C();
    int GetField620();
};
struct FixedStr
{
    void* m_pData;
    FixedStr(const char* str);
    ~FixedStr();
};
struct Point3
{
    float x;
    float y;
    float z;
    Point3(float ax, int ay, int az);
};
struct AnimSeq
{
    void FUN_007408d0(int state);
};
struct AnimCtrl
{
    AnimSeq* FUN_0047a520(const FixedStr& name);
    void FUN_0048fef0(float time);
};
struct SceneNode
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
    virtual void AttachChildInAvailableSlot(SceneNode* child, int firstAvail);
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void RemoveChildAt(int index);
    void FUN_00450f90(int visible);
    void FUN_00a59c60(const Point3& pos);
    void FUN_004bc1f0(float x, float y, float z);
    AnimCtrl* FUN_00a5c570(void* rtti);
    int FUN_00453470();
};
struct SceneRoot
{
    SceneNode* FUN_00559450();
};
struct ModelLoader
{
    void FUN_0045a5e0(const char* path);
    SceneNode* LoadModel(const char* path, int a, int b, int c, int d, int e);
};
struct UiTile
{
    void SetTraitAndReset(int id, float value);
    void FUN_00700320(int id, int value);
    void FUN_00a01350(int id, const char* value, int propagate);
    void FUN_00715c60(int id, int value);
    UiTile* FUN_00a03da0(const char* name);
    float FUN_00a011b0(int id, int flag);
    void FUN_00a012d0(int id, float value);
    void FUN_00a07530(int value);
};
struct GameSetting
{
    const char* FUN_00403df0();
};
struct AnimPair
{
    AnimSeq* pIn;
    AnimSeq* pOut;
};
struct CardAnims
{
    AnimPair pairs[4];
};
struct SlotState
{
    int iA;
    int iB;
    int iC;
};

extern CaravanGame* DAT_011dea3c;
extern ModelLoader* DAT_011c3b3c;
extern SceneRoot DAT_011d91e4;
extern char DAT_011f36ac;
extern const float DAT_0102caf8;
extern const double DAT_0106c948;
extern GameSetting DAT_011d1fec;
extern GameSetting DAT_011d2964;
extern GameSetting DAT_011d24b4;
extern GameSetting DAT_011d41f8;
extern GameSetting DAT_011d4204;
extern GameSetting DAT_011d4d80;
extern GameSetting DAT_011d4198;
extern GameSetting DAT_011d29f4;
int __cdecl FUN_00944460(int lo, int hi);
int __cdecl FUN_00406d00(char* buf, int size, const char* fmt, ...);
void __cdecl FUN_00a6d2d0(SceneNode* node);

struct CaravanMenuX
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int m_28;
    int m_2c;
    UiTile* m_pTile30;
    UiTile* m_pTile34;
    UiTile* m_pTile38;
    UiTile* m_pTile3c;
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
    UiTile* m_pTile70;
    UiTile* m_pTile74;
    UiTile* m_pTile78;
    UiTile* m_pTile7c;
    UiTile* m_pTile80;
    UiTile* m_pTile84;
    UiTile* m_pTile88;
    UiTile* m_pTile8c;
    UiTile* m_pTile90;
    UiTile* m_pTile94;
    UiTile* m_pTile98;
    UiTile* m_pTile9c;
    UiTile* m_pTilea0;
    UiTile* m_pTilea4;
    UiTile* m_pTilea8;
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
    UiTile* m_pTilee0;
    UiTile* m_pTilee4;
    UiTile* m_pTilee8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    CardNode* m_pPending;
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
    int m_188;
    int m_18c;
    SceneNode* m_pDecks[2];
    SceneNode* m_pCardNodes[6][7];
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int m_254;
    int m_258[6];
    int m_270;
    int m_274[6];
    AnimCtrl* m_pDeckCtrl[2];
    AnimSeq* m_pDeckSeqA[2][6];
    AnimSeq* m_pDeckSeqB[2][8];
    AnimCtrl* m_pCardCtrl[6][7];
    CardAnims m_cardAnims[6][7];
    int m_8ec[0x60];
    CardArray m_hand;
    int unkA7C;
    int unkA80;
    int unkA84;
    int unkA88;
    int unkA8C;
    int unkA90;
    int unkA94;
    int unkA98;
    int unkA9C;
    int unkAA0;
    int unkAA4;
    int unkAA8;
    int unkAAC;
    int unkAB0;
    int unkAB4;
    int unkAB8;
    int unkABC;
    int unkAC0;
    int unkAC4;
    int unkAC8;
    int unkACC;
    int unkAD0;
    int unkAD4;
    int unkAD8;
    int unkADC;
    int unkAE0;
    int unkAE4;
    int m_ae8;
    int unkAEC;
    int unkAF0;
    int unkAF4;
    int unkAF8;
    int unkAFC;
    int unkB00;
    CardArray m_deckA;
    CardArray m_deckB;
    CardArray m_drawA;
    CardArray m_drawB;
    CardArray m_slots[6][7];
    SlotState m_slotState[6];
    int unkE2C;
    int unkE30;
    int unkE34;
    int unkE38;
    int unkE3C;
    int m_e40;
    int m_e44;
    int m_e48;
    int m_e4c;
    int m_e50;
    SceneNode* m_pPlayerGrid[3];
    SceneNode* m_pOppGrid[3];
    SceneNode* m_pSelectAdd;
    SceneNode* m_pSelectRemove;
    void FUN_0073ea90();
    void UpdateHandStats(int index);
    void SetFlag(int flag, int set);
    void UpdateDeckCardNodes(int which, int set);
    void ClearField();
    void UpdateControls();
};

// Routes m_hand cards to player and opponent lists, draws eight cards from each deck, builds scene nodes and animation controls, and updates UI tiles.
// @fnv 0x0073ea90
void CaravanMenuX::FUN_0073ea90()
{
    CardList* pPlayerList = DAT_011dea3c->GetField618();
    CardList* pOpponent = DAT_011dea3c->GetField614();
    pPlayerList->FUN_00470470();
    pOpponent->FUN_00470470();

    for (unsigned int i = 0; i < m_hand.FUN_0044ddc0(); i++)
    {
        if (m_hand.FUN_006a7ad0(i)->FUN_0073cb80())
        {
            pPlayerList->FUN_005ae3d0(m_hand.FUN_006a7ad0(i));
            m_deckA.FUN_007cb2e0(m_hand.FUN_006a7ad0(i));
        }
        else
        {
            pOpponent->FUN_005ae3d0(m_hand.FUN_006a7ad0(i));
        }
    }

    while (m_pPending && *m_pPending->FUN_006815c0())
    {
        m_deckB.FUN_007cb2e0(*m_pPending->FUN_006815c0());
        m_pPending = m_pPending->FUN_00726070();
    }

    for (int iDraw = 0; iDraw < 8; iDraw++)
    {
        int iPick = FUN_00944460(0, m_deckA.FUN_0044ddc0());
        m_drawA.FUN_007cb2e0(m_deckA.FUN_006a7ad0(iPick));
        m_deckA.FUN_009a4320(iPick, 1);
        iPick = FUN_00944460(0, m_deckB.FUN_0044ddc0());
        m_drawB.FUN_007cb2e0(m_deckB.FUN_006a7ad0(iPick));
        m_deckB.FUN_009a4320(iPick, 1);
    }

    m_e40 = FUN_00944460(0, m_deckA.FUN_0044ddc0());
    m_e44 = FUN_00944460(0, m_deckB.FUN_0044ddc0());
    m_pPending = 0;
    pPlayerList = 0;
    pOpponent = 0;

    if (m_hand.FUN_0044ddc0() > 0)
    {
        m_hand.FUN_008454f0(1);
    }
    for (int iClear = 0; iClear < 0x60; iClear++)
    {
        m_8ec[iClear] = 0;
    }
    m_hand.FUN_008454f0(1);
    m_254 = 0;
    m_270 = 0;
    for (int iLane = 0; iLane < 6; iLane++)
    {
        m_258[iLane] = 0;
        m_274[iLane] = 0;
    }
    for (int iClear2 = 0; iClear2 < 0x60; iClear2++)
    {
        m_8ec[iClear2] = 0;
    }

    DAT_011d91e4.FUN_00559450()->RemoveChildAt(DAT_011d91e4.FUN_00559450()->FUN_00453470() - 1);
    DAT_011d91e4.FUN_00559450()->RemoveChildAt(DAT_011d91e4.FUN_00559450()->FUN_00453470() - 1);
    DAT_011c3b3c->FUN_0045a5e0("Meshes\\Terminals\\NV_Caravan\\NV_Caravan-Deck.NIF");
    DAT_011c3b3c->FUN_0045a5e0("Meshes\\Terminals\\NV_Caravan\\NV_Caravan-Available.NIF");
    m_188 = 0;
    m_18c = 0;

    char szModel[0x104];
    for (int iSide = 0; iSide < 3; iSide++)
    {
        for (int iCard = 0; iCard < 7; iCard++)
        {
            FUN_00406d00(szModel, 0x104, "%sPlayer_%i_0%i.NIF", "Meshes\\Terminals\\NV_Caravan\\", iSide + 1,
                         iCard + 1);
            m_pCardNodes[iSide][iCard] = DAT_011c3b3c->LoadModel(szModel, 0, 1, 0, 0, 0);
            DAT_011d91e4.FUN_00559450()->AttachChildInAvailableSlot(m_pCardNodes[iSide][iCard], 1);
            FUN_00406d00(szModel, 0x104, "%sOpponent_%i_0%i.NIF", "Meshes\\Terminals\\NV_Caravan\\", iSide + 1,
                         iCard + 1);
            m_pCardNodes[iSide + 3][iCard] = DAT_011c3b3c->LoadModel(szModel, 0, 1, 0, 0, 0);
            DAT_011d91e4.FUN_00559450()->AttachChildInAvailableSlot(m_pCardNodes[iSide + 3][iCard], 1);
        }
    }

    for (int iGrid = 0; iGrid < 3; iGrid++)
    {
        FUN_00406d00(szModel, 0x104, "%sPlayerGrid_%i.NIF", "Meshes\\Terminals\\NV_Caravan\\", iGrid + 1);
        m_pPlayerGrid[iGrid] = DAT_011c3b3c->LoadModel(szModel, 0, 1, 0, 0, 0);
        FUN_00406d00(szModel, 0x104, "%sOppGrid_%i.NIF", "Meshes\\Terminals\\NV_Caravan\\", iGrid + 1);
        m_pOppGrid[iGrid] = DAT_011c3b3c->LoadModel(szModel, 0, 1, 0, 0, 0);
    }

    FUN_00406d00(szModel, 0x104, "%sSelect_Add.NIF", "Meshes\\Terminals\\NV_Caravan\\");
    m_pSelectAdd = DAT_011c3b3c->LoadModel(szModel, 0, 1, 0, 0, 0);
    DAT_011d91e4.FUN_00559450()->AttachChildInAvailableSlot(m_pSelectAdd, 1);
    FUN_00406d00(szModel, 0x104, "%sSelect_Remove.NIF", "Meshes\\Terminals\\NV_Caravan\\");
    m_pSelectRemove = DAT_011c3b3c->LoadModel(szModel, 0, 1, 0, 0, 0);
    DAT_011d91e4.FUN_00559450()->AttachChildInAvailableSlot(m_pSelectRemove, 1);

    FUN_00406d00(szModel, 0x104, "%s%s", "Meshes\\Terminals\\NV_Caravan\\", "Player_Deck.NIF");
    m_pDecks[0] = DAT_011c3b3c->LoadModel(szModel, 0, 1, 0, 0, 0);
    FUN_00406d00(szModel, 0x104, "%s%s", "Meshes\\Terminals\\NV_Caravan\\", "Opponent_Deck.NIF");
    m_pDecks[1] = DAT_011c3b3c->LoadModel(szModel, 0, 1, 0, 0, 0);
    DAT_011d91e4.FUN_00559450()->AttachChildInAvailableSlot(m_pDecks[0], 1);
    DAT_011d91e4.FUN_00559450()->AttachChildInAvailableSlot(m_pDecks[1], 1);

    for (int iGridPos = 0; iGridPos < 6; iGridPos++)
    {
        m_pPlayerGrid[iGridPos]->FUN_00450f90(1);
        m_pPlayerGrid[iGridPos]->FUN_00a59c60(Point3(0.0f, 0, 0));
    }
    m_pSelectAdd->FUN_00a59c60(Point3(0.0f, 0, 0));
    m_pSelectRemove->FUN_00a59c60(Point3(0.0f, 0, 0));
    m_pSelectAdd->FUN_004bc1f0(0.0f, 0.0f, DAT_0102caf8);
    m_pSelectRemove->FUN_004bc1f0(0.0f, 0.0f, DAT_0102caf8);
    m_pSelectAdd->FUN_00a59c60(Point3(0.0f, 0, 0));
    m_pSelectRemove->FUN_00a59c60(Point3(0.0f, 0, 0));

    AnimCtrl* pCtrl;
    for (int iDeck = 0; iDeck < 2; iDeck++)
    {
        pCtrl = m_pDecks[iDeck]->FUN_00a5c570(&DAT_011f36ac);
        if (pCtrl != 0)
        {
            m_pDeckCtrl[iDeck] = pCtrl;
            m_pDeckSeqA[iDeck][0] = m_pDeckCtrl[iDeck]->FUN_0047a520(FixedStr("Deck-Cards_In"));
            m_pDeckSeqA[iDeck][1] = m_pDeckCtrl[iDeck]->FUN_0047a520(FixedStr("Deck-Card1_Out"));
            m_pDeckSeqA[iDeck][2] = m_pDeckCtrl[iDeck]->FUN_0047a520(FixedStr("Deck-Card2_Out"));
            m_pDeckSeqA[iDeck][3] = m_pDeckCtrl[iDeck]->FUN_0047a520(FixedStr("Deck-Card3_Out"));
            m_pDeckSeqA[iDeck][4] = m_pDeckCtrl[iDeck]->FUN_0047a520(FixedStr("Deck-Card4_Out"));
            m_pDeckSeqA[iDeck][5] = m_pDeckCtrl[iDeck]->FUN_0047a520(FixedStr("Deck-Card5_Out"));
            m_pDeckSeqB[iDeck][0] = m_pDeckCtrl[iDeck]->FUN_0047a520(FixedStr("Deck8-Card1_Out"));
            m_pDeckSeqB[iDeck][1] = m_pDeckCtrl[iDeck]->FUN_0047a520(FixedStr("Deck8-Card2_Out"));
            m_pDeckSeqB[iDeck][2] = m_pDeckCtrl[iDeck]->FUN_0047a520(FixedStr("Deck8-Card3_Out"));
            m_pDeckSeqB[iDeck][3] = m_pDeckCtrl[iDeck]->FUN_0047a520(FixedStr("Deck8-Card4_Out"));
            m_pDeckSeqB[iDeck][4] = m_pDeckCtrl[iDeck]->FUN_0047a520(FixedStr("Deck8-Card5_Out"));
            m_pDeckSeqB[iDeck][5] = m_pDeckCtrl[iDeck]->FUN_0047a520(FixedStr("Deck8-Card6_Out"));
            m_pDeckSeqB[iDeck][6] = m_pDeckCtrl[iDeck]->FUN_0047a520(FixedStr("Deck8-Card7_Out"));
            m_pDeckSeqB[iDeck][7] = m_pDeckCtrl[iDeck]->FUN_0047a520(FixedStr("Deck8-Card8_Out"));
            m_pDeckCtrl[iDeck]->FUN_0048fef0(0.0f);
            FUN_00a6d2d0(m_pDecks[iDeck]);
        }
    }

    for (int iRow = 0; iRow < 6; iRow++)
    {
        for (int iCol = 0; iCol < 7; iCol++)
        {
            pCtrl = m_pCardNodes[iRow][iCol]->FUN_00a5c570(&DAT_011f36ac);
            if (pCtrl != 0)
            {
                m_pCardCtrl[iRow][iCol] = pCtrl;
                m_cardAnims[iRow][iCol].pairs[0].pIn = m_pCardCtrl[iRow][iCol]->FUN_0047a520(FixedStr("Card1_In"));
                m_cardAnims[iRow][iCol].pairs[1].pIn = m_pCardCtrl[iRow][iCol]->FUN_0047a520(FixedStr("Card2_In"));
                m_cardAnims[iRow][iCol].pairs[2].pIn = m_pCardCtrl[iRow][iCol]->FUN_0047a520(FixedStr("Card3_In"));
                m_cardAnims[iRow][iCol].pairs[3].pIn = m_pCardCtrl[iRow][iCol]->FUN_0047a520(FixedStr("Card4_In"));
                m_cardAnims[iRow][iCol].pairs[0].pOut = m_pCardCtrl[iRow][iCol]->FUN_0047a520(FixedStr("Card1_Out"));
                m_cardAnims[iRow][iCol].pairs[1].pOut = m_pCardCtrl[iRow][iCol]->FUN_0047a520(FixedStr("Card2_Out"));
                m_cardAnims[iRow][iCol].pairs[2].pOut = m_pCardCtrl[iRow][iCol]->FUN_0047a520(FixedStr("Card3_Out"));
                m_cardAnims[iRow][iCol].pairs[3].pOut = m_pCardCtrl[iRow][iCol]->FUN_0047a520(FixedStr("Card4_Out"));
                m_pCardCtrl[iRow][iCol]->FUN_0048fef0(0.0f);
                for (int iAnim = 0; iAnim < 4; iAnim++)
                {
                    m_cardAnims[iRow][iCol].pairs[iAnim].pIn->FUN_007408d0(2);
                    m_cardAnims[iRow][iCol].pairs[iAnim].pOut->FUN_007408d0(2);
                }
                FUN_00a6d2d0(m_pCardNodes[iRow][iCol]);
                m_slots[iRow][iCol].FUN_008454f0(1);
            }
        }
    }

    DAT_011d91e4.FUN_00559450()->FUN_00a59c60(Point3(0.0f, 0, 0));

    for (int iSlot = 0; iSlot < 6; iSlot++)
    {
        m_slotState[iSlot].iC = 0;
        m_slotState[iSlot].iB = 5;
        m_slotState[iSlot].iA = 0;
        UpdateHandStats(iSlot);
    }

    SetFlag(0x800, 1);
    UpdateDeckCardNodes(1, 1);
    UpdateDeckCardNodes(0, 1);
    m_e48 = 0;
    m_e4c = 0;
    m_e50 = 0;
    ClearField();
    SetFlag(0x4000, 1);
    SetFlag(1, 1);

    char szCountBuf[0x104];
    FUN_00406d00(szCountBuf, 0x104, "%i/%i", DAT_011dea3c->GetRegionDataManager(), DAT_011dea3c->FUN_00740960());
    m_pTile70->SetTraitAndReset(DAT_011d9174, 1.0f);
    m_pTile70->FUN_00700320(DAT_011d9174, m_ae8 * 2);
    m_pTile74->SetTraitAndReset(DAT_011d9174, 1.0f);
    int nLeft = DAT_011dea3c->GetFieldAtOffset61C() - DAT_011dea3c->GetField620();
    m_pTile74->FUN_00700320(DAT_011d9174, nLeft);
    m_pTile78->SetTraitAndReset(DAT_011d9174, 1.0f);
    m_pTile78->FUN_00a01350(DAT_011d9174, szCountBuf, 1);
    m_pTile98->SetTraitAndReset(DAT_011d9174, 1.0f);
    m_pTile98->FUN_00700320(DAT_011d9174, 0);
    m_pTile9c->SetTraitAndReset(DAT_011d9174, 1.0f);
    m_pTile9c->FUN_00700320(DAT_011d9174, 0);
    m_pTilea0->SetTraitAndReset(DAT_011d9174, 1.0f);
    m_pTilea0->FUN_00700320(DAT_011d9174, 0);
    m_pTile8c->SetTraitAndReset(DAT_011d9174, 1.0f);
    m_pTile8c->FUN_00700320(DAT_011d9174, 0);
    m_pTile90->SetTraitAndReset(DAT_011d9174, 1.0f);
    m_pTile90->FUN_00700320(DAT_011d9174, 0);
    m_pTile94->SetTraitAndReset(DAT_011d9174, 1.0f);
    m_pTile94->FUN_00700320(DAT_011d9174, 0);
    m_pTilea4->SetTraitAndReset(DAT_011d9174, 1.0f);
    m_pTilea4->FUN_00715c60(DAT_011d9174, m_deckA.FUN_0044ddc0());
    m_pTilea8->SetTraitAndReset(DAT_011d9174, 1.0f);
    m_pTilea8->FUN_00715c60(DAT_011d9174, m_deckB.FUN_0044ddc0());
    m_28 = 2;
    m_2c = 2;

    UiTile* pInfoRect = m_pTile38->FUN_00a03da0("CGM_InfoRect");
    if (pInfoRect != 0)
    {
        pInfoRect->FUN_00a012d0(0xfb1, pInfoRect->FUN_00a011b0(0xfb1, 1) + DAT_0106c948);
        pInfoRect->FUN_00a012d0(0xfa1, pInfoRect->FUN_00a011b0(0xfa1, 1) - DAT_0106c948);
        pInfoRect->FUN_00a07530(0x11);
    }

    m_pTile88->FUN_00a01350(0xfc4, DAT_011d1fec.FUN_00403df0(), 1);
    m_pTile30->FUN_00700320(0xfa3, 0);
    m_pTile34->FUN_00700320(0xfa3, 0);
    m_pTile38->FUN_00700320(0xfa3, 1);
    m_pTile3c->FUN_00700320(0xfa3, 0);
    m_pTilee0->FUN_00a01350(0xfc4, DAT_011d2964.FUN_00403df0(), 1);
    m_pTilee4->FUN_00a01350(0xfc4, DAT_011d24b4.FUN_00403df0(), 1);
    m_pTilee8->FUN_00a01350(0xfc4, DAT_011d41f8.FUN_00403df0(), 1);
    m_pTile7c->FUN_00a01350(0xfc4, DAT_011d4204.FUN_00403df0(), 1);
    m_pTile80->FUN_00a01350(0xfc4, DAT_011d4d80.FUN_00403df0(), 1);
    m_pTile84->FUN_00a01350(0xfc4, DAT_011d4198.FUN_00403df0(), 1);
    m_pTile88->FUN_00a01350(0xfc4, DAT_011d29f4.FUN_00403df0(), 1);
    UpdateControls();
}
}  // namespace fnv_0073ea90

class NiSourceTexture;
template <class T> class NiPointer
{
    T* ptr;

  public:
    NiPointer(T*);
    ~NiPointer();
    operator T*() const;
};
// @fnv 0x0074df90
void CaravanGame::UpdateCardTexture()
{
    CMAVObject* tableVal = cardNode[curLane][curCol];
    char _buf[260];
    if (curLane >= 3)
    {
        _sprintf_s(_buf, 260u, "Card_0%i:%i", 4 - animStep, animStep);
    }
    else
    {
        _sprintf_s(_buf, 260u, "Card_0%i:%i", animStep + 1, animStep);
    }
    CardNode* objFoundX = FUN_004aae30((NiAVObject*)tableVal, _buf);
    CardShader* prop6 = (!objFoundX->FUN_00a59d30(3) ? 0
                                                     : (objFoundX->FUN_00a59d30(3)->FUN_00441110() >= 8 &&
                                                        objFoundX->FUN_00a59d30(3)->FUN_00441110() <= 12))
                            ? objFoundX->FUN_00a59d30(3)
                            : 0;
    char buf2[260];
    NiPointer<NiSourceTexture> objTmp(0);
    if (prop6)
    {
        _sprintf_s(_buf, 260u, "%s%s", "Textures\\", ((UIAssetSource*)playedCard)->FUN_0050d100()->FUN_00408da0());
        FUN_004b7240(_buf, buf2, 260);
        g_TES->CreateTextureImage(buf2, (TextureRef&)objTmp, false, false);
        if ((unsigned int)(NiSourceTexture*)objTmp)
        {
            prop6->SetResource(0, 0, (unsigned int)(NiSourceTexture*)objTmp);
        }
    }
}

struct R74SelectableV;
struct R74Str;
struct R74Point
{
    float x, y, z;
    R74Point();
    R74Point* Center();
};
struct R74Matrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    R74Matrix();
    void FUN_004a0c90(float);
    R74Matrix FUN_0043f8d0(R74Matrix&);
};
struct R74Sound
{
    unsigned int id, state, frequency;
    ~R74Sound();
    void Play();
};
struct R74Resource
{
    R74Sound GetSoundByEditorID(const char*, unsigned int, unsigned int);
};
struct R74CardSlot
{
    unsigned int unk00, unk04, unk08, unk0c;
    int FUN_0044ddc0();
};
struct R74Positioner
{
    void FUN_004bc1f0(float, float, float);
};
struct R74Animator
{
    void FUN_0043fa80(R74Matrix*);
    void FUN_00440460(R74Point*);
};
struct R74TextureNode
{
    R74Matrix* FUN_006a9540();
    R74Point* FUN_0043d450();
    void Update(const NiUpdateData&);
};
struct R74Node
{
    R74SelectableV* FUN_00a59d30(int);
};
struct R74ExternalRef
{
    R74Str* FUN_0050d100();
};
struct R74Str
{
    const char* FUN_00408da0();
};
struct R74SelectableV
{
    int FUN_00441110();
    virtual void reserved0();
    virtual void reserved1();
    virtual void reserved2();
    virtual void reserved3();
    virtual void FunctionAtSlot4();
    virtual void FunctionAtSlot5();
    virtual void FunctionAtSlot6();
    virtual void VirtualFunction7();
    virtual void VirtualFunction8();
    virtual void VirtualFunction9();
    virtual void VirtualFunction10();
    virtual void ReplaceImpactData();
    virtual void reserved12();
    virtual void VirtualFunction13();
    virtual void reserved14();
    virtual void reserved15();
    virtual void reserved16();
    virtual void reserved17();
    virtual void reserved18();
    virtual void reserved19();
    virtual void reserved20();
    virtual void reserved21();
    virtual void VirtualFunction22();
    virtual void VirtualFunction23();
    virtual void VirtualFunction24();
    virtual void VirtualFunction25();
    virtual void VirtualFunction26();
    virtual void VirtualFunction27();
    virtual void VirtualFunction28();
    virtual void VirtualFunction29();
    virtual void reserved30();
    virtual void reserved31();
    virtual void reserved32();
    virtual void reserved33();
    virtual void reserved34();
    virtual void reserved35();
    virtual void reserved36();
    virtual void reserved37();
    virtual void reserved38();
    virtual void reserved39();
    virtual void reserved40();
    virtual void reserved41();
    virtual void reserved42();
    virtual void reserved43();
    virtual void reserved44();
    virtual void reserved45();
    virtual void reserved46();
    virtual void reserved47();
    virtual void reserved48();
    virtual void reserved49();
    virtual void reserved50();
    virtual void reserved51();
    virtual void reserved52();
    virtual void reserved53();
    virtual void reserved54();
    virtual void reserved55();
    virtual void reserved56();
    virtual void reserved57();
    virtual void reserved58();
    virtual void reserved59();
    virtual void OnCardSelection(int, int, void*);
};

extern "C" const char DAT_01071aac[];
extern "C" const char DAT_01071728[];
extern "C" const char DAT_01071a84[];
extern "C" const char DAT_01071aa4[];
extern "C" const char DAT_01071a78[];
extern "C" const char DAT_0101996c[];
extern "C" const char DAT_0101d7fc[];
extern "C" const float DAT_0104f7c4;
extern "C" const float DAT_0101ff38;
struct R74Menu
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003c;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004c;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005c;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006c;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007c;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008c;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009c;
    unsigned int unk00a0;
    unsigned int unk00a4;
    unsigned int unk00a8;
    unsigned int unk00ac;
    unsigned int unk00b0;
    unsigned int unk00b4;
    unsigned int unk00b8;
    unsigned int unk00bc;
    unsigned int unk00c0;
    unsigned int unk00c4;
    unsigned int unk00c8;
    unsigned int unk00cc;
    unsigned int unk00d0;
    unsigned int unk00d4;
    unsigned int unk00d8;
    unsigned int unk00dc;
    unsigned int unk00e0;
    unsigned int unk00e4;
    unsigned int unk00e8;
    unsigned int unk00ec;
    unsigned int unk00f0;
    unsigned int unk00f4;
    unsigned int unk00f8;
    unsigned int unk00fc;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010c;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011c;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012c;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013c;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014c;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015c;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016c;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017c;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018c;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019c;
    unsigned int unk01a0;
    unsigned int unk01a4;
    unsigned int unk01a8;
    unsigned int unk01ac;
    unsigned int unk01b0;
    unsigned int unk01b4;
    unsigned int unk01b8;
    unsigned int unk01bc;
    unsigned int unk01c0;
    unsigned int unk01c4;
    unsigned int unk01c8;
    unsigned int unk01cc;
    unsigned int unk01d0;
    unsigned int unk01d4;
    unsigned int unk01d8;
    unsigned int unk01dc;
    unsigned int unk01e0;
    unsigned int unk01e4;
    unsigned int unk01e8;
    unsigned int unk01ec;
    unsigned int unk01f0;
    unsigned int unk01f4;
    unsigned int unk01f8;
    unsigned int unk01fc;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020c;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021c;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022c;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023c;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024c;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025c;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026c;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027c;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028c;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029c;
    unsigned int unk02a0;
    unsigned int unk02a4;
    unsigned int unk02a8;
    unsigned int unk02ac;
    unsigned int unk02b0;
    unsigned int unk02b4;
    unsigned int unk02b8;
    unsigned int unk02bc;
    unsigned int unk02c0;
    unsigned int unk02c4;
    unsigned int unk02c8;
    unsigned int unk02cc;
    unsigned int unk02d0;
    unsigned int unk02d4;
    unsigned int unk02d8;
    unsigned int unk02dc;
    unsigned int unk02e0;
    unsigned int unk02e4;
    unsigned int unk02e8;
    unsigned int unk02ec;
    unsigned int unk02f0;
    unsigned int unk02f4;
    unsigned int unk02f8;
    unsigned int unk02fc;
    unsigned int unk0300;
    unsigned int unk0304;
    unsigned int unk0308;
    unsigned int unk030c;
    unsigned int unk0310;
    unsigned int unk0314;
    unsigned int unk0318;
    unsigned int unk031c;
    unsigned int unk0320;
    unsigned int unk0324;
    unsigned int unk0328;
    unsigned int unk032c;
    unsigned int unk0330;
    unsigned int unk0334;
    unsigned int unk0338;
    unsigned int unk033c;
    unsigned int unk0340;
    unsigned int unk0344;
    unsigned int unk0348;
    unsigned int unk034c;
    unsigned int unk0350;
    unsigned int unk0354;
    unsigned int unk0358;
    unsigned int unk035c;
    unsigned int unk0360;
    unsigned int unk0364;
    unsigned int unk0368;
    unsigned int unk036c;
    unsigned int unk0370;
    unsigned int unk0374;
    unsigned int unk0378;
    unsigned int unk037c;
    unsigned int unk0380;
    unsigned int unk0384;
    unsigned int unk0388;
    unsigned int unk038c;
    unsigned int unk0390;
    unsigned int unk0394;
    unsigned int unk0398;
    unsigned int unk039c;
    unsigned int unk03a0;
    unsigned int unk03a4;
    unsigned int unk03a8;
    unsigned int unk03ac;
    unsigned int unk03b0;
    unsigned int unk03b4;
    unsigned int unk03b8;
    unsigned int unk03bc;
    unsigned int unk03c0;
    unsigned int unk03c4;
    unsigned int unk03c8;
    unsigned int unk03cc;
    unsigned int unk03d0;
    unsigned int unk03d4;
    unsigned int unk03d8;
    unsigned int unk03dc;
    unsigned int unk03e0;
    unsigned int unk03e4;
    unsigned int unk03e8;
    unsigned int unk03ec;
    unsigned int unk03f0;
    unsigned int unk03f4;
    unsigned int unk03f8;
    unsigned int unk03fc;
    unsigned int unk0400;
    unsigned int unk0404;
    unsigned int unk0408;
    unsigned int unk040c;
    unsigned int unk0410;
    unsigned int unk0414;
    unsigned int unk0418;
    unsigned int unk041c;
    unsigned int unk0420;
    unsigned int unk0424;
    unsigned int unk0428;
    unsigned int unk042c;
    unsigned int unk0430;
    unsigned int unk0434;
    unsigned int unk0438;
    unsigned int unk043c;
    unsigned int unk0440;
    unsigned int unk0444;
    unsigned int unk0448;
    unsigned int unk044c;
    unsigned int unk0450;
    unsigned int unk0454;
    unsigned int unk0458;
    unsigned int unk045c;
    unsigned int unk0460;
    unsigned int unk0464;
    unsigned int unk0468;
    unsigned int unk046c;
    unsigned int unk0470;
    unsigned int unk0474;
    unsigned int unk0478;
    unsigned int unk047c;
    unsigned int unk0480;
    unsigned int unk0484;
    unsigned int unk0488;
    unsigned int unk048c;
    unsigned int unk0490;
    unsigned int unk0494;
    unsigned int unk0498;
    unsigned int unk049c;
    unsigned int unk04a0;
    unsigned int unk04a4;
    unsigned int unk04a8;
    unsigned int unk04ac;
    unsigned int unk04b0;
    unsigned int unk04b4;
    unsigned int unk04b8;
    unsigned int unk04bc;
    unsigned int unk04c0;
    unsigned int unk04c4;
    unsigned int unk04c8;
    unsigned int unk04cc;
    unsigned int unk04d0;
    unsigned int unk04d4;
    unsigned int unk04d8;
    unsigned int unk04dc;
    unsigned int unk04e0;
    unsigned int unk04e4;
    unsigned int unk04e8;
    unsigned int unk04ec;
    unsigned int unk04f0;
    unsigned int unk04f4;
    unsigned int unk04f8;
    unsigned int unk04fc;
    unsigned int unk0500;
    unsigned int unk0504;
    unsigned int unk0508;
    unsigned int unk050c;
    unsigned int unk0510;
    unsigned int unk0514;
    unsigned int unk0518;
    unsigned int unk051c;
    unsigned int unk0520;
    unsigned int unk0524;
    unsigned int unk0528;
    unsigned int unk052c;
    unsigned int unk0530;
    unsigned int unk0534;
    unsigned int unk0538;
    unsigned int unk053c;
    unsigned int unk0540;
    unsigned int unk0544;
    unsigned int unk0548;
    unsigned int unk054c;
    unsigned int unk0550;
    unsigned int unk0554;
    unsigned int unk0558;
    unsigned int unk055c;
    unsigned int unk0560;
    unsigned int unk0564;
    unsigned int unk0568;
    unsigned int unk056c;
    unsigned int unk0570;
    unsigned int unk0574;
    unsigned int unk0578;
    unsigned int unk057c;
    unsigned int unk0580;
    unsigned int unk0584;
    unsigned int unk0588;
    unsigned int unk058c;
    unsigned int unk0590;
    unsigned int unk0594;
    unsigned int unk0598;
    unsigned int unk059c;
    unsigned int unk05a0;
    unsigned int unk05a4;
    unsigned int unk05a8;
    unsigned int unk05ac;
    unsigned int unk05b0;
    unsigned int unk05b4;
    unsigned int unk05b8;
    unsigned int unk05bc;
    unsigned int unk05c0;
    unsigned int unk05c4;
    unsigned int unk05c8;
    unsigned int unk05cc;
    unsigned int unk05d0;
    unsigned int unk05d4;
    unsigned int unk05d8;
    unsigned int unk05dc;
    unsigned int unk05e0;
    unsigned int unk05e4;
    unsigned int unk05e8;
    unsigned int unk05ec;
    unsigned int unk05f0;
    unsigned int unk05f4;
    unsigned int unk05f8;
    unsigned int unk05fc;
    unsigned int unk0600;
    unsigned int unk0604;
    unsigned int unk0608;
    unsigned int unk060c;
    unsigned int unk0610;
    unsigned int unk0614;
    unsigned int unk0618;
    unsigned int unk061c;
    unsigned int unk0620;
    unsigned int unk0624;
    unsigned int unk0628;
    unsigned int unk062c;
    unsigned int unk0630;
    unsigned int unk0634;
    unsigned int unk0638;
    unsigned int unk063c;
    unsigned int unk0640;
    unsigned int unk0644;
    unsigned int unk0648;
    unsigned int unk064c;
    unsigned int unk0650;
    unsigned int unk0654;
    unsigned int unk0658;
    unsigned int unk065c;
    unsigned int unk0660;
    unsigned int unk0664;
    unsigned int unk0668;
    unsigned int unk066c;
    unsigned int unk0670;
    unsigned int unk0674;
    unsigned int unk0678;
    unsigned int unk067c;
    unsigned int unk0680;
    unsigned int unk0684;
    unsigned int unk0688;
    unsigned int unk068c;
    unsigned int unk0690;
    unsigned int unk0694;
    unsigned int unk0698;
    unsigned int unk069c;
    unsigned int unk06a0;
    unsigned int unk06a4;
    unsigned int unk06a8;
    unsigned int unk06ac;
    unsigned int unk06b0;
    unsigned int unk06b4;
    unsigned int unk06b8;
    unsigned int unk06bc;
    unsigned int unk06c0;
    unsigned int unk06c4;
    unsigned int unk06c8;
    unsigned int unk06cc;
    unsigned int unk06d0;
    unsigned int unk06d4;
    unsigned int unk06d8;
    unsigned int unk06dc;
    unsigned int unk06e0;
    unsigned int unk06e4;
    unsigned int unk06e8;
    unsigned int unk06ec;
    unsigned int unk06f0;
    unsigned int unk06f4;
    unsigned int unk06f8;
    unsigned int unk06fc;
    unsigned int unk0700;
    unsigned int unk0704;
    unsigned int unk0708;
    unsigned int unk070c;
    unsigned int unk0710;
    unsigned int unk0714;
    unsigned int unk0718;
    unsigned int unk071c;
    unsigned int unk0720;
    unsigned int unk0724;
    unsigned int unk0728;
    unsigned int unk072c;
    unsigned int unk0730;
    unsigned int unk0734;
    unsigned int unk0738;
    unsigned int unk073c;
    unsigned int unk0740;
    unsigned int unk0744;
    unsigned int unk0748;
    unsigned int unk074c;
    unsigned int unk0750;
    unsigned int unk0754;
    unsigned int unk0758;
    unsigned int unk075c;
    unsigned int unk0760;
    unsigned int unk0764;
    unsigned int unk0768;
    unsigned int unk076c;
    unsigned int unk0770;
    unsigned int unk0774;
    unsigned int unk0778;
    unsigned int unk077c;
    unsigned int unk0780;
    unsigned int unk0784;
    unsigned int unk0788;
    unsigned int unk078c;
    unsigned int unk0790;
    unsigned int unk0794;
    unsigned int unk0798;
    unsigned int unk079c;
    unsigned int unk07a0;
    unsigned int unk07a4;
    unsigned int unk07a8;
    unsigned int unk07ac;
    unsigned int unk07b0;
    unsigned int unk07b4;
    unsigned int unk07b8;
    unsigned int unk07bc;
    unsigned int unk07c0;
    unsigned int unk07c4;
    unsigned int unk07c8;
    unsigned int unk07cc;
    unsigned int unk07d0;
    unsigned int unk07d4;
    unsigned int unk07d8;
    unsigned int unk07dc;
    unsigned int unk07e0;
    unsigned int unk07e4;
    unsigned int unk07e8;
    unsigned int unk07ec;
    unsigned int unk07f0;
    unsigned int unk07f4;
    unsigned int unk07f8;
    unsigned int unk07fc;
    unsigned int unk0800;
    unsigned int unk0804;
    unsigned int unk0808;
    unsigned int unk080c;
    unsigned int unk0810;
    unsigned int unk0814;
    unsigned int unk0818;
    unsigned int unk081c;
    unsigned int unk0820;
    unsigned int unk0824;
    unsigned int unk0828;
    unsigned int unk082c;
    unsigned int unk0830;
    unsigned int unk0834;
    unsigned int unk0838;
    unsigned int unk083c;
    unsigned int unk0840;
    unsigned int unk0844;
    unsigned int unk0848;
    unsigned int unk084c;
    unsigned int unk0850;
    unsigned int unk0854;
    unsigned int unk0858;
    unsigned int unk085c;
    unsigned int unk0860;
    unsigned int unk0864;
    unsigned int unk0868;
    unsigned int unk086c;
    unsigned int unk0870;
    unsigned int unk0874;
    unsigned int unk0878;
    unsigned int unk087c;
    unsigned int unk0880;
    unsigned int unk0884;
    unsigned int unk0888;
    unsigned int unk088c;
    unsigned int unk0890;
    unsigned int unk0894;
    unsigned int unk0898;
    unsigned int unk089c;
    unsigned int unk08a0;
    unsigned int unk08a4;
    unsigned int unk08a8;
    unsigned int unk08ac;
    unsigned int unk08b0;
    unsigned int unk08b4;
    unsigned int unk08b8;
    unsigned int unk08bc;
    unsigned int unk08c0;
    unsigned int unk08c4;
    unsigned int unk08c8;
    unsigned int unk08cc;
    unsigned int unk08d0;
    unsigned int unk08d4;
    unsigned int unk08d8;
    unsigned int unk08dc;
    unsigned int unk08e0;
    unsigned int unk08e4;
    unsigned int unk08e8;
    unsigned int unk08ec;
    unsigned int unk08f0;
    unsigned int unk08f4;
    unsigned int unk08f8;
    unsigned int unk08fc;
    unsigned int unk0900;
    unsigned int unk0904;
    unsigned int unk0908;
    unsigned int unk090c;
    unsigned int unk0910;
    unsigned int unk0914;
    unsigned int unk0918;
    unsigned int unk091c;
    unsigned int unk0920;
    unsigned int unk0924;
    unsigned int unk0928;
    unsigned int unk092c;
    unsigned int unk0930;
    unsigned int unk0934;
    unsigned int unk0938;
    unsigned int unk093c;
    unsigned int unk0940;
    unsigned int unk0944;
    unsigned int unk0948;
    unsigned int unk094c;
    unsigned int unk0950;
    unsigned int unk0954;
    unsigned int unk0958;
    unsigned int unk095c;
    unsigned int unk0960;
    unsigned int unk0964;
    unsigned int unk0968;
    unsigned int unk096c;
    unsigned int unk0970;
    unsigned int unk0974;
    unsigned int unk0978;
    unsigned int unk097c;
    unsigned int unk0980;
    unsigned int unk0984;
    unsigned int unk0988;
    unsigned int unk098c;
    unsigned int unk0990;
    unsigned int unk0994;
    unsigned int unk0998;
    unsigned int unk099c;
    unsigned int unk09a0;
    unsigned int unk09a4;
    unsigned int unk09a8;
    unsigned int unk09ac;
    unsigned int unk09b0;
    unsigned int unk09b4;
    unsigned int unk09b8;
    unsigned int unk09bc;
    unsigned int unk09c0;
    unsigned int unk09c4;
    unsigned int unk09c8;
    unsigned int unk09cc;
    unsigned int unk09d0;
    unsigned int unk09d4;
    unsigned int unk09d8;
    unsigned int unk09dc;
    unsigned int unk09e0;
    unsigned int unk09e4;
    unsigned int unk09e8;
    unsigned int unk09ec;
    unsigned int unk09f0;
    unsigned int unk09f4;
    unsigned int unk09f8;
    unsigned int unk09fc;
    unsigned int unk0a00;
    unsigned int unk0a04;
    unsigned int unk0a08;
    unsigned int unk0a0c;
    unsigned int unk0a10;
    unsigned int unk0a14;
    unsigned int unk0a18;
    unsigned int unk0a1c;
    unsigned int unk0a20;
    unsigned int unk0a24;
    unsigned int unk0a28;
    unsigned int unk0a2c;
    unsigned int unk0a30;
    unsigned int unk0a34;
    unsigned int unk0a38;
    unsigned int unk0a3c;
    unsigned int unk0a40;
    unsigned int unk0a44;
    unsigned int unk0a48;
    unsigned int unk0a4c;
    unsigned int unk0a50;
    unsigned int unk0a54;
    unsigned int unk0a58;
    unsigned int unk0a5c;
    unsigned int unk0a60;
    unsigned int unk0a64;
    unsigned int unk0a68;
    unsigned int unk0a6c;
    unsigned int unk0a70;
    unsigned int unk0a74;
    unsigned int unk0a78;
    unsigned int unk0a7c;
    unsigned int unk0a80;
    unsigned int unk0a84;
    unsigned int unk0a88;
    unsigned int unk0a8c;
    unsigned int unk0a90;
    unsigned int unk0a94;
    unsigned int unk0a98;
    unsigned int unk0a9c;
    unsigned int unk0aa0;
    unsigned int unk0aa4;
    unsigned int unk0aa8;
    unsigned int unk0aac;
    unsigned int unk0ab0;
    unsigned int unk0ab4;
    unsigned int unk0ab8;
    unsigned int unk0abc;
    unsigned int unk0ac0;
    unsigned int unk0ac4;
    unsigned int unk0ac8;
    unsigned int unk0acc;
    unsigned int unk0ad0;
    unsigned int unk0ad4;
    unsigned int unk0ad8;
    unsigned int unk0adc;
    unsigned int unk0ae0;
    unsigned int unk0ae4;
    unsigned int unk0ae8;
    unsigned int unk0aec;
    unsigned int unk0af0;
    unsigned int unk0af4;
    unsigned int unk0af8;
    unsigned int unk0afc;
    unsigned int unk0b00;
    unsigned int unk0b04;
    unsigned int unk0b08;
    unsigned int unk0b0c;
    unsigned int unk0b10;
    unsigned int unk0b14;
    unsigned int unk0b18;
    unsigned int unk0b1c;
    unsigned int unk0b20;
    unsigned int unk0b24;
    unsigned int unk0b28;
    unsigned int unk0b2c;
    unsigned int unk0b30;
    unsigned int unk0b34;
    unsigned int unk0b38;
    unsigned int unk0b3c;
    unsigned int unk0b40;
    R74CardSlot slots[6][7];
    unsigned int unk0de4;
    unsigned int unk0de8;
    unsigned int unk0dec;
    unsigned int unk0df0;
    unsigned int unk0df4;
    unsigned int unk0df8;
    unsigned int unk0dfc;
    unsigned int unk0e00;
    unsigned int unk0e04;
    unsigned int unk0e08;
    unsigned int unk0e0c;
    unsigned int unk0e10;
    unsigned int unk0e14;
    unsigned int unk0e18;
    unsigned int unk0e1c;
    unsigned int unk0e20;
    unsigned int unk0e24;
    unsigned int unk0e28;
    void* selection;
    unsigned int unk0e30;
    unsigned int unk0e34;
    unsigned int unk0e38;
    unsigned int unk0e3c;
    unsigned int unk0e40;
    unsigned int unk0e44;
    R74ExternalRef* external;
    unsigned int unke4c, unke50;
    void* cards[6];
    void* left;
    void* right;

    bool CanPlaceCard(int, int, void*, int);
    void SelectCard(int row, int column);
};
// Checks whether placement is allowed, plays a sound, positions a left or right node at the card, and invokes its selection callback.
// @fnv 0x0074e6d0
void R74Menu::SelectCard(int row, int column)
{
    void* sel;
    R74Point pos3;
    char buf2[260];
    R74Matrix orientation;
    bool sideTmp = CanPlaceCard(row, column, selection, 0);
    int modeValue = slots[row][column].FUN_0044ddc0();
    if (modeValue > 3)
        modeValue = 3;
    char aBuf1[260];
    FUN_00406d00(aBuf1, 0x104u, DAT_01071aac, reinterpret_cast<const char*>(column + 1),
                 reinterpret_cast<const char*>(modeValue + 1));
    R74TextureNode* card4 = reinterpret_cast<R74TextureNode*>(FUN_004aae30(cards[row], aBuf1));
    if (card4)
    {
        if (sideTmp)
        {
            reinterpret_cast<R74Resource*>(FUN_00453a70())->GetSoundByEditorID(DAT_01071728, 0x121, 0).Play();
            sel = left;
            reinterpret_cast<R74Positioner*>(right)->FUN_004bc1f0(0.0f, 0.0f, DAT_0104f7c4);
            reinterpret_cast<R74TextureNode*>(right)->Update(NiUpdateData(0.0f, false, false));
            R74Matrix scale;
            scale.FUN_004a0c90(DAT_0101ff38);
            orientation = *card4->FUN_006a9540();
            orientation = orientation.FUN_0043f8d0(scale);
            pos3 = *card4->FUN_0043d450()->Center();
            reinterpret_cast<R74Animator*>(sel)->FUN_0043fa80(&orientation);
            reinterpret_cast<R74Animator*>(sel)->FUN_00440460(&pos3);
            reinterpret_cast<R74TextureNode*>(sel)->Update(NiUpdateData(0.0f, false, false));
            sel = FUN_004aae30(sel, DAT_01071aa4);
        }
        else
        {
            reinterpret_cast<R74Resource*>(FUN_00453a70())->GetSoundByEditorID(DAT_01071a84, 0x121, 0).Play();
            sel = right;
            reinterpret_cast<R74Positioner*>(left)->FUN_004bc1f0(0.0f, 0.0f, DAT_0104f7c4);
            reinterpret_cast<R74TextureNode*>(left)->Update(NiUpdateData(0.0f, false, false));
            R74Matrix scale;
            scale.FUN_004a0c90(DAT_0101ff38);
            orientation = *card4->FUN_006a9540();
            orientation = orientation.FUN_0043f8d0(scale);
            pos3 = *card4->FUN_0043d450()->Center();
            reinterpret_cast<R74Animator*>(sel)->FUN_0043fa80(&orientation);
            reinterpret_cast<R74Animator*>(sel)->FUN_00440460(&pos3);
            reinterpret_cast<R74TextureNode*>(sel)->Update(NiUpdateData(0.0f, false, false));
            sel = FUN_004aae30(sel, DAT_01071a78);
        }
        R74SelectableV* selectable = (reinterpret_cast<R74Node*>(sel)->FUN_00a59d30(3) == 0
                                          ? 0
                                          : (reinterpret_cast<R74Node*>(sel)->FUN_00a59d30(3)->FUN_00441110() >= 8 &&
                                             reinterpret_cast<R74Node*>(sel)->FUN_00a59d30(3)->FUN_00441110() <= 12))
                                         ? reinterpret_cast<R74Node*>(sel)->FUN_00a59d30(3)
                                         : 0;
        GO uiReq_(0);
        if (selectable != 0)
        {
            FUN_00406d00(aBuf1, 0x104u, DAT_0101996c, DAT_0101d7fc,
                         reinterpret_cast<R74ExternalRef*>(external)->FUN_0050d100()->FUN_00408da0());
            FUN_004b7240(aBuf1, buf2, 0x104);
            DAT_011dea10->FUN_004568c0(buf2, &uiReq_, 0, 0);
            if ((unsigned int)uiReq_ != 0)
            {
                selectable->OnCardSelection(0, 0, (void*)(unsigned int)uiReq_);
            }
        }
    }
}
