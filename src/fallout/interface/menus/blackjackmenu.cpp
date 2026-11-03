
// src/fallout/interface/menus/blackjackmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/blackjackmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_007316f0_shell
{
    void ClearField();
};

// @fnv 0x007316f0
void FUN_007316f0_shell::ClearField()
{
    ((int*)this)[0xdb0 / 4] = 0;
}

struct BlackJackMenu
{
    int __thiscall FUN_00731790();
};

// @fnv 0x00731790
int __thiscall BlackJackMenu::FUN_00731790()
{
    return 0x439;
}

namespace fnv_007317a0 {
struct Tile;
struct BlackJackMenu
{
    char mBase[0x34];
    Tile* m_pTiles[40];
    void SetTile(int aiID, Tile* apTile);
};

// Stores apTile into the tile slot array at index aiID when aiID is in [0,10).
// @fnv 0x007317a0
void BlackJackMenu::SetTile(int aiID, Tile* apTile)
{
    if (aiID >= 0 && aiID < 10)
    {
        m_pTiles[aiID] = apTile;
    }
}
}  // namespace fnv_007317a0

// @fnv 0x00733f80
int __cdecl FUN_00733f80()
{
    return 0x439;
}

struct FUN_007399d0_shell
{
    void FUN_007399d0();
};

// Multiplies the value at offset 0xd9c by 0x34 and stores the result at offset 0xda0.
// @fnv 0x007399d0
void FUN_007399d0_shell::FUN_007399d0()
{
    ((int*)this)[0xda0 / 4] = ((int*)this)[0xd9c / 4] * 0x34;
}

struct FUN_00734d30_shell
{
    int __thiscall HasFlag(int aFlag);
};
// @fnv 0x00734d30
int __thiscall FUN_00734d30_shell::HasFlag(int aFlag)
{
    return (*(reinterpret_cast<int*>(this) + 0xdb0 / 4) & aFlag) != 0;
}

struct FUN_007317d0_shell
{
    void* __thiscall DestroyIfFlagged(unsigned int);
};
struct Helper731800
{
    void __thiscall FUN_00731800();
};
void _Deallocate(void*);
// Calls FUN_00731800 on this, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x007317d0
void* __thiscall FUN_007317d0_shell::DestroyIfFlagged(unsigned int flags)
{
    ((Helper731800*)this)->FUN_00731800();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Proc_S
{
    void* GetNext();
};
struct Tile
{
    void Set(int, float, bool);
};
void* __cdecl FUN_004b7210();
struct DAT_011d9050_S
{
    char _pad[0x28];
    int v28;
};
extern DAT_011d9050_S* DAT_011d9050;
// @fnv 0x00731d30
void FUN_00731d30()
{
    if (DAT_011d9050 != 0)
    {
        DAT_011d9050->v28 = 13;
        ((Tile*)((Proc_S*)FUN_004b7210())->GetNext())->Set(0xFA9, 255.0f, true);
    }
}

struct Helper62d0
{
    void* operator=(const void*);
};
struct FUN_007324f0_shell
{
    int m0;
    int m4;
    int m8;
    int mC;
    FUN_007324f0_shell& operator=(const FUN_007324f0_shell&);
};
// Copies the four fields of s into this object and returns a reference to this object.
// @fnv 0x007324f0
FUN_007324f0_shell& FUN_007324f0_shell::operator=(const FUN_007324f0_shell& aSource)
{
    m0 = aSource.m0;
    m4 = aSource.m4;
    *(Helper62d0*)((char*)this + 8) = (const void*)&aSource.m8;
    *(Helper62d0*)((char*)this + 12) = (const void*)&aSource.mC;
    return *this;
}

struct FUN_00733f50_shell
{
    int m0;
    int m1;
    short m2;
    FUN_00733f50_shell* FUN_00733f50();
};
// Sets the three fields m0, m1 and m2 to zero and returns this.
// @fnv 0x00733f50
FUN_00733f50_shell* FUN_00733f50_shell::FUN_00733f50()
{
    m0 = 0;
    m1 = 0;
    m2 = 0;
    return this;
}

struct FUN_00733f90_shell
{
    char __thiscall FUN_00733f90();
};

// Checks the ten int fields starting at offset 13 and returns 1 only if none of them is zero, otherwise 0.
// @fnv 0x00733f90
char __thiscall FUN_00733f90_shell::FUN_00733f90()
{
    for (int i = 0; i < 10; ++i)
    {
        if (((int*)this)[13 + i] == 0)
            return 0;
    }
    return 1;
}

struct FUN_00738fb0_shell
{
    int __thiscall GetAdjustedValue(int a1);
};
// Returns 10 for inputs 9-11, 11 for input 12, and otherwise the input plus 2.
// @fnv 0x00738fb0
int FUN_00738fb0_shell::GetAdjustedValue(int aiValue)
{
    switch (aiValue)
    {
    case 9:
    case 10:
    case 11:
        return 10;
    case 12:
        return 11;
    default:
        return aiValue + 2;
    }
}

struct NiAVObject
{
    void __thiscall SetAppCulled(bool);
};
struct SceneObjectLookup
{
    static NiAVObject* __cdecl GetObjectByName(NiAVObject*, char const*);
};
struct FUN_00739ad0_Holder
{
    char _pad[0xDB4];
    NiAVObject* m_pTreeNode;
    void __thiscall HideArrowNodes();
};
// Looks up the nodes "Hand1_Arrow:0" and "Hand1_Arrow:0@#2" by name and culls both.
// @fnv 0x00739ad0
void __thiscall FUN_00739ad0_Holder::HideArrowNodes()
{
    NiAVObject* pavobj;
    pavobj = SceneObjectLookup::GetObjectByName(m_pTreeNode, "Hand1_Arrow:0");
    pavobj->SetAppCulled(true);
    pavobj = SceneObjectLookup::GetObjectByName(m_pTreeNode, "Hand1_Arrow:0@#2");
    pavobj->SetAppCulled(true);
}

struct FUN_00733fd0_shell
{
    char _pad_0[0xf8];
    float m_fMinimum;  // +0xf8
    void __thiscall FUN_00733fd0(float fMin);
};

// @fnv 0x00733fd0
void __thiscall FUN_00733fd0_shell::FUN_00733fd0(float fMin)
{
    m_fMinimum = fMin;
}

struct FUN_00734d50_holder
{
    unsigned char _pad[0xDB0];
    int _flags;
    void SetFlag(int flag, bool value);
};
// Sets or clears the bit given by flag in _flags according to value.
// @fnv 0x00734d50
void FUN_00734d50_holder::SetFlag(int flag, bool value)
{
    value ? _flags |= flag : _flags &= ~flag;
}

class AnimIdle;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T*);
    ~NiPointer();
    NiPointer& operator=(T*);
    operator T*() const;
};
struct S148c0
{
    void FUN_007148c0(int, int);
};
S148c0* FUN_0043c4b0();
struct Accum_00733500
{
    void FUN_00c4f270(int);
    void FUN_004a0fd0(AnimIdle*);
    void FUN_00c4f2d0();
};
struct Node_00733500
{
    Accum_00733500* GetProcessInteger();
    AnimIdle* GetAnimationData();
};
Node_00733500* FUN_0045c670();
struct Mgr_00733500
{
    AnimIdle* FUN_007fd640();
};

void __cdecl UpdateCameraFrustum(AnimIdle*, float);
void* __cdecl FUN_00450b80(int);
void __cdecl FUN_00b6bee0(AnimIdle*, void*, Accum_00733500*);
struct BSShaderRenderUtility
{
    static void __cdecl SetRenderCamera(AnimIdle*, AnimIdle*, bool);
};
extern const float g_011db5ec_arg1;
extern NiPointer<AnimIdle> g_011d90bc;

// @fnv 0x00733500
void __cdecl FUN_00733500()
{
    FUN_0043c4b0()->FUN_007148c0(0, 4);
    Node_00733500* pPlayerNode = FUN_0045c670();
    Accum_00733500* pAccumulator = pPlayerNode->GetProcessInteger();
    pAccumulator->FUN_00c4f270(1);
    AnimIdle* pCamera = g_011d90bc;
    UpdateCameraFrustum(pCamera, g_011db5ec_arg1);
    NiPointer<AnimIdle> m_pParentNode(((Mgr_00733500*)FUN_004b7210())->FUN_007fd640());
    pAccumulator->FUN_004a0fd0(m_pParentNode);
    AnimIdle* pRenderCamera = pCamera ? pCamera : pPlayerNode->GetAnimationData();
    FUN_00b6bee0(pRenderCamera, FUN_00450b80(1), pAccumulator);
    BSShaderRenderUtility::SetRenderCamera(pRenderCamera, m_pParentNode, false);
    pAccumulator->FUN_004a0fd0(0);
    m_pParentNode = 0;
    pAccumulator->FUN_00c4f2d0();
}

struct FUN_00739650_shell : FUN_00734d50_holder
{
    bool FUN_00739650(bool bFlag);
};

// Compares a field at offset 0x74 against sums of fields at 0x6c and 0x70, then calls SetFlag with 0x200 or 0x40 depending on bFlag and returns the result.
// @fnv 0x00739650
bool FUN_00739650_shell::FUN_00739650(bool bFlag)
{
    bool bResult = true;
    if (bFlag)
    {
        if (*(int*)((char*)this + 0x74) < *(int*)((char*)this + 0x6c) + *(int*)((char*)this + 0x70) * 2)
            bResult = false;
    }
    if (!bFlag)
    {
        if (*(int*)((char*)this + 0x74) < *(int*)((char*)this + 0x70) + *(int*)((char*)this + 0x6c) * 2)
            bResult = false;
    }
    if (bFlag)
        SetFlag(0x200, bResult);
    else
        SetFlag(0x40, bResult);
    return bResult;
}

struct NiUpdateData
{
    float m_fTime;
    bool m_bUpdate;
    bool m_bForce;
    unsigned char _padding[6];

    NiUpdateData(float, bool, bool);
};

struct NiNode
{
    void __thiscall Update(NiUpdateData const&);
};

struct LodObject
{
    void __thiscall SetAppCulled(bool);
};

struct GO
{
    operator unsigned int() const;
};

extern GO g_011d9098;

extern char str_01070e34[];
extern char str_01070e20[];
extern char str_01070e0c[];
extern char str_01070dfc[];
extern char str_01070de8[];
extern char str_01070dd4[];
extern char str_01070dc4[];
extern char str_01070db0[];
extern char str_01070d9c[];

int _sprintf_s(char*, unsigned int, const char*, ...);

struct FUN_00738270_shell
{
    unsigned char _pad[0xdb8];
    NiAVObject* m_pCardObject1;
    NiAVObject* m_pCardObject2;
    NiAVObject* m_pCardObject3;

    void __thiscall UncullCardObjects();
};

// Builds card, card-back and shadow node names for indices 1-7 on three objects, un-culls each found node, then updates g_011d9098.
// @fnv 0x00738270
void FUN_00738270_shell::UncullCardObjects()
{
    char cardBackRefName[30];
    NiAVObject* pavobj;
    char cardRefName[30];
    char shadowRefName[30];

    for (int i = 1; i <= 7; ++i)
    {
        _sprintf_s(cardRefName, 30, str_01070e34, i, i - 1);
        _sprintf_s(cardBackRefName, 30, str_01070e20, i);
        _sprintf_s(shadowRefName, 30, str_01070e0c, i);

        pavobj = SceneObjectLookup::GetObjectByName(m_pCardObject1, cardRefName);
        reinterpret_cast<LodObject*>(pavobj)->SetAppCulled(false);

        pavobj = SceneObjectLookup::GetObjectByName(m_pCardObject1, cardBackRefName);
        reinterpret_cast<LodObject*>(pavobj)->SetAppCulled(false);

        pavobj = SceneObjectLookup::GetObjectByName(m_pCardObject1, shadowRefName);
        reinterpret_cast<LodObject*>(pavobj)->SetAppCulled(false);
    }

    for (int i = 1; i <= 7; ++i)
    {
        _sprintf_s(cardRefName, 30, str_01070dfc, i);
        _sprintf_s(cardBackRefName, 30, str_01070de8, i);
        _sprintf_s(shadowRefName, 30, str_01070dd4, i);

        pavobj = SceneObjectLookup::GetObjectByName(m_pCardObject3, cardRefName);
        reinterpret_cast<LodObject*>(pavobj)->SetAppCulled(false);

        pavobj = SceneObjectLookup::GetObjectByName(m_pCardObject3, cardBackRefName);
        reinterpret_cast<LodObject*>(pavobj)->SetAppCulled(false);

        pavobj = SceneObjectLookup::GetObjectByName(m_pCardObject3, shadowRefName);
        reinterpret_cast<LodObject*>(pavobj)->SetAppCulled(false);
    }

    for (int i = 1; i <= 7; ++i)
    {
        _sprintf_s(cardRefName, 30, str_01070dc4, i, i - 1);
        _sprintf_s(cardBackRefName, 30, str_01070db0, i);
        _sprintf_s(shadowRefName, 30, str_01070d9c, i);

        pavobj = SceneObjectLookup::GetObjectByName(m_pCardObject2, cardRefName);
        reinterpret_cast<LodObject*>(pavobj)->SetAppCulled(false);

        pavobj = SceneObjectLookup::GetObjectByName(m_pCardObject2, cardBackRefName);
        reinterpret_cast<LodObject*>(pavobj)->SetAppCulled(false);

        pavobj = SceneObjectLookup::GetObjectByName(m_pCardObject2, shadowRefName);
        reinterpret_cast<LodObject*>(pavobj)->SetAppCulled(false);
    }

    reinterpret_cast<NiNode*>(g_011d9098.operator unsigned int())->Update(NiUpdateData(0.0f, false, false));
}

struct StartMenu
{
    char const* __thiscall GetMenuTitle();
};

extern StartMenu g_011d25ec;
extern StartMenu g_011d30fc;
extern StartMenu g_011d3354;
extern StartMenu g_011d33fc;
extern StartMenu g_011d37f8;
extern StartMenu g_011d3da8;
extern StartMenu g_011d4234;
extern StartMenu g_011d487c;
extern StartMenu g_011d4c78;
extern StartMenu g_011d4e28;

struct FUN_00a01290_shell
{
    void __thiscall SetTraitAndReset(int, float);
};

struct P09TileS
{
    void __thiscall Set(int, char const*, bool);
};

struct Tile2
{
    void __thiscall Set(int, int);
};

struct FUN_00738c30_shell
{
    void __thiscall FUN_00738c30(int, float);
};

struct BlackJackMenu_Layout
{
    char _pad[0x40];
    Tile* m40;
    Tile* m44;
    Tile* m48;
    Tile* m4C;
    Tile* m50;
    Tile* m54;
};

// @fnv 0x00738cc0
void __cdecl UpdateBetTiles(bool bBetTiles)
{
    if (!bBetTiles)
    {
        reinterpret_cast<FUN_00a01290_shell*>(reinterpret_cast<BlackJackMenu_Layout*>(DAT_011d9050)->m44)
            ->SetTraitAndReset(0xfc4, 1.0f);
        reinterpret_cast<P09TileS*>(reinterpret_cast<BlackJackMenu_Layout*>(DAT_011d9050)->m44)
            ->Set(0xfc4, g_011d4c78.GetMenuTitle(), true);

        reinterpret_cast<FUN_00a01290_shell*>(reinterpret_cast<BlackJackMenu_Layout*>(DAT_011d9050)->m48)
            ->SetTraitAndReset(0xfc4, 1.0f);
        reinterpret_cast<P09TileS*>(reinterpret_cast<BlackJackMenu_Layout*>(DAT_011d9050)->m48)
            ->Set(0xfc4, g_011d4234.GetMenuTitle(), true);

        reinterpret_cast<FUN_00a01290_shell*>(reinterpret_cast<BlackJackMenu_Layout*>(DAT_011d9050)->m4C)
            ->SetTraitAndReset(0xfc4, 1.0f);
        reinterpret_cast<P09TileS*>(reinterpret_cast<BlackJackMenu_Layout*>(DAT_011d9050)->m4C)
            ->Set(0xfc4, g_011d4e28.GetMenuTitle(), true);

        reinterpret_cast<FUN_00a01290_shell*>(reinterpret_cast<BlackJackMenu_Layout*>(DAT_011d9050)->m50)
            ->SetTraitAndReset(0xfc4, 1.0f);
        reinterpret_cast<P09TileS*>(reinterpret_cast<BlackJackMenu_Layout*>(DAT_011d9050)->m50)
            ->Set(0xfc4, g_011d25ec.GetMenuTitle(), true);

        reinterpret_cast<FUN_00a01290_shell*>(reinterpret_cast<BlackJackMenu_Layout*>(DAT_011d9050)->m54)
            ->SetTraitAndReset(0xfc4, 1.0f);
        reinterpret_cast<P09TileS*>(reinterpret_cast<BlackJackMenu_Layout*>(DAT_011d9050)->m54)
            ->Set(0xfc4, g_011d30fc.GetMenuTitle(), true);

        reinterpret_cast<Tile2*>(reinterpret_cast<BlackJackMenu_Layout*>(DAT_011d9050)->m40)->Set(0xfa3, 1);
    }
    else
    {
        reinterpret_cast<FUN_00a01290_shell*>(reinterpret_cast<BlackJackMenu_Layout*>(DAT_011d9050)->m44)
            ->SetTraitAndReset(0xfc4, 1.0f);
        reinterpret_cast<P09TileS*>(reinterpret_cast<BlackJackMenu_Layout*>(DAT_011d9050)->m44)
            ->Set(0xfc4, g_011d3da8.GetMenuTitle(), true);
        reinterpret_cast<FUN_00738c30_shell*>(DAT_011d9050)->FUN_00738c30(4, 255.0f);

        reinterpret_cast<FUN_00a01290_shell*>(reinterpret_cast<BlackJackMenu_Layout*>(DAT_011d9050)->m48)
            ->SetTraitAndReset(0xfc4, 1.0f);
        reinterpret_cast<P09TileS*>(reinterpret_cast<BlackJackMenu_Layout*>(DAT_011d9050)->m48)
            ->Set(0xfc4, g_011d3354.GetMenuTitle(), true);
        reinterpret_cast<FUN_00738c30_shell*>(DAT_011d9050)->FUN_00738c30(5, 255.0f);

        reinterpret_cast<FUN_00a01290_shell*>(reinterpret_cast<BlackJackMenu_Layout*>(DAT_011d9050)->m4C)
            ->SetTraitAndReset(0xfc4, 1.0f);
        reinterpret_cast<P09TileS*>(reinterpret_cast<BlackJackMenu_Layout*>(DAT_011d9050)->m4C)
            ->Set(0xfc4, g_011d487c.GetMenuTitle(), true);
        reinterpret_cast<FUN_00738c30_shell*>(DAT_011d9050)->FUN_00738c30(6, 255.0f);

        reinterpret_cast<FUN_00a01290_shell*>(reinterpret_cast<BlackJackMenu_Layout*>(DAT_011d9050)->m50)
            ->SetTraitAndReset(0xfc4, 1.0f);
        reinterpret_cast<P09TileS*>(reinterpret_cast<BlackJackMenu_Layout*>(DAT_011d9050)->m50)
            ->Set(0xfc4, g_011d37f8.GetMenuTitle(), true);
        reinterpret_cast<FUN_00738c30_shell*>(DAT_011d9050)->FUN_00738c30(7, 255.0f);

        reinterpret_cast<FUN_00a01290_shell*>(reinterpret_cast<BlackJackMenu_Layout*>(DAT_011d9050)->m54)
            ->SetTraitAndReset(0xfc4, 1.0f);
        reinterpret_cast<P09TileS*>(reinterpret_cast<BlackJackMenu_Layout*>(DAT_011d9050)->m54)
            ->Set(0xfc4, g_011d33fc.GetMenuTitle(), true);
        reinterpret_cast<FUN_00738c30_shell*>(DAT_011d9050)->FUN_00738c30(8, 255.0f);

        reinterpret_cast<Tile2*>(reinterpret_cast<BlackJackMenu_Layout*>(DAT_011d9050)->m40)->Set(0xfa3, 0);
    }
}

struct Padding16ByteBlock
{
    int _pad[4];
};

struct G2
{
    bool __thiscall _ref_008256d0();
    void __thiscall _ref_00726c60(Padding16ByteBlock* const& value);
    void __thiscall AddHead(Padding16ByteBlock* const& value);
};

struct SoundListView
{
    void __thiscall AddTail(Padding16ByteBlock* const& value);
};

struct FUN_007393f0_shell
{
    unsigned char _pad0[0x2c];
    int _handResult0;
    int _handResult1;
    unsigned char _pad1[0x5c];
    Padding16ByteBlock _deck[208];
    G2* _dealerHand;
    G2* _playerHand;

    int DrawCard(int a1, int a2, int a3);
    int DrawCard(G2* hand, int a1, int a2);
    void FUN_00738ff0(G2* hand);

    void __thiscall DealInitialCards();
};

// @fnv 0x007393f0
void __thiscall FUN_007393f0_shell::DealInitialCards()
{
    int cardindex;

    this->_handResult0 = 0;
    this->_handResult1 = 0;

    cardindex = this->DrawCard(0, 0, 0);
    if (this->_dealerHand == 0 || this->_dealerHand->_ref_008256d0())
        this->_dealerHand->_ref_00726c60(&this->_deck[cardindex]);
    else
        this->_dealerHand->AddHead(&this->_deck[cardindex]);

    cardindex = this->DrawCard(0, 0, 0);
    if (this->_playerHand == 0 || this->_playerHand->_ref_008256d0())
        this->_playerHand->_ref_00726c60(&this->_deck[cardindex]);
    else
        this->_dealerHand->AddHead(&this->_deck[cardindex]);

    cardindex = this->DrawCard(this->_dealerHand, 1, 1);
    reinterpret_cast<SoundListView*>(this->_dealerHand)->AddTail(&this->_deck[cardindex]);

    cardindex = this->DrawCard(this->_playerHand, 1, 0);
    reinterpret_cast<SoundListView*>(this->_playerHand)->AddTail(&this->_deck[cardindex]);

    this->FUN_00738ff0(this->_playerHand);
}

namespace fnv_007395a0 {
struct Padding16ByteBlock
{
    int m_uiFilterValue;
};

struct BSSimpleList
{
    Padding16ByteBlock** __thiscall _ref_006815c0();
    BSSimpleList* __thiscall _ref_00726070();
};

struct FUN_007395a0_shell
{
    unsigned char _pad00[0x6C];
    int m_iValueAtOffset6C;
    unsigned char _pad70[4];
    int m_iValueAtOffset74;
    unsigned char _pad78[0xD94 - 0x78];
    BSSimpleList* m_pSimpleList;

    bool __thiscall FUN_007395a0();
};

// @fnv 0x007395a0
bool __thiscall FUN_007395a0_shell::FUN_007395a0()
{
    int numCards;
    BSSimpleList* clist;
    Padding16ByteBlock* cd;
    bool bCanSplit;

    clist = m_pSimpleList;
    cd = 0;
    numCards = 0;
    bCanSplit = false;

    while (clist && *clist->_ref_006815c0())
    {
        if (numCards == 0)
        {
            cd = *clist->_ref_006815c0();
        }
        else if (numCards == 1)
        {
            if (cd->m_uiFilterValue == (*clist->_ref_006815c0())->m_uiFilterValue)
            {
                if (m_iValueAtOffset74 >= m_iValueAtOffset6C * 2)
                    bCanSplit = true;
            }
        }
        else
        {
            bCanSplit = false;
            break;
        }

        clist = clist->_ref_00726070();
        ++numCards;
    }

    reinterpret_cast<FUN_00734d50_holder*>(this)->SetFlag(4, bCanSplit);
    return bCanSplit;
}
}  // namespace fnv_007395a0

namespace fnv_0073ab40 {
struct StartMenu
{
    char const* __thiscall GetMenuTitle();
};

struct GlobalObject_0040c150 : public StartMenu
{
};

struct FNStub
{
    char* __thiscall GetFullName();
};

struct TileHelper
{
    void Set(int, char const*, bool);
};

struct FUN_0073ab40_shell
{
    unsigned char _pad[0x3C];
    TileHelper* m_tile;

    void __thiscall UpdateTileText();
};

extern GlobalObject_0040c150 g_011d3e08;
extern int* DAT_011d9054;
extern void* DAT_011d9058;
extern int DAT_011d9044;
extern unsigned int _data_011c16bc;
extern char const $SG2721[];
extern char const $SG2727[];
extern char const DAT_01012058[];

int __cdecl _sprintf_s(char*, unsigned int, char const*, ...);
int __cdecl _BSStringLength(char const*);

// @fnv 0x0073ab40
void FUN_0073ab40_shell::UpdateTileText()
{
    char tstring[260];
    int ilen;
    int i;

    _sprintf_s(tstring, 0x104, $SG2721,
               reinterpret_cast<FNStub*>(reinterpret_cast<unsigned char*>(DAT_011d9058) + 0x18)->GetFullName(),
               g_011d3e08.GetMenuTitle(), DAT_011d9054[1]);

    ilen = _BSStringLength(tstring);
    if (ilen < 0x17)
    {
        _sprintf_s(tstring, 0x104, DAT_01012058,
                   reinterpret_cast<FNStub*>(reinterpret_cast<unsigned char*>(DAT_011d9058) + 0x18)->GetFullName(),
                   g_011d3e08.GetMenuTitle());

        for (i = 0; i < 0x17 - ilen; ++i)
        {
            tstring[ilen - 1 + i] = ' ';
            tstring[ilen + i] = 0;
        }

        _sprintf_s(tstring, 0x104, $SG2727, tstring, DAT_011d9054[1]);
    }

    m_tile->Set(DAT_011d9044, tstring, true);
}
}  // namespace fnv_0073ab40

extern "C" void* _ReadWriteBarrier_unused;

struct SetBase
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;

    SetBase();
    virtual ~SetBase();
};

struct SetElem
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    SetElem();
    ~SetElem();
};

struct SetMgr
{
    void* FUN_007316d0();
};

struct SetMgrB
{
    int FUN_00575610(int);
};

struct SetMgrC
{
    void ClearField();
};

extern SetMgr* DAT_011d9058;
extern SetMgrB* DAT_011dea3c;
extern void* DAT_011d9044;
extern void* DAT_011d9048;
void* __cdecl TraitNameToIDAdd(const char*, int);

class FUN_007315e0 : public SetBase
{
  public:
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
    void* m74;
    unsigned int unk78;
    unsigned int m7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    SetElem m90[208];

    FUN_007315e0();
    virtual ~FUN_007315e0();
    void ClearField();
};

// @fnv 0x007315e0
FUN_007315e0::FUN_007315e0()
{
    DAT_011d9044 = TraitNameToIDAdd("_Value", -1);
    DAT_011d9048 = TraitNameToIDAdd("_x", -1);
    unk28 = 10;
    m7C = 0;
    if (DAT_011d9058->FUN_007316d0() != 0)
        m74 = (void*)DAT_011dea3c->FUN_00575610((int)DAT_011d9058->FUN_007316d0());
    ClearField();
}

struct Member731710A
{
    int m_00;
    Member731710A(int v);
    ~Member731710A();
};

struct Member731710B
{
    int m_00;
    Member731710B(int v);
};

struct FUN_00731710_cls
{
    int m_00;
    int m_04;
    Member731710A m_08;
    Member731710B m_0c;

    FUN_00731710_cls();
};

// Initializes m_00 to 0xe and m_04 to 5, and constructs m_08 and m_0c with 0.
// @fnv 0x00731710
FUN_00731710_cls::FUN_00731710_cls() : m_08(0), m_0c(0)
{
    m_00 = 0xe;
    m_04 = 5;
}

namespace fnv_00731800 {
struct PlayerStub
{
    void FUN_00969b20();
};
extern PlayerStub* g_thePlayer;

struct NiNodeStub
{
    void DetachAllChildren();
};
template <class T> struct NiPtr
{
    T* m_pObject;
    NiPtr& operator=(T*);
    operator T*() const;
};
extern NiPtr<NiNodeStub> g_rootA;
extern NiPtr<NiNodeStub> g_rootB;

struct PathObj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual const char* GetPath();
};
struct PathList
{
    PathObj* FUN_00504e00(int);
};
extern PathList* DAT_011d9058;
extern int DAT_011d9054;
extern void* g_d9050;

struct LoaderStub
{
    void FUN_0045a5e0(const char*);
};
extern LoaderStub* g_modelLoader;

struct SSNStub
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
    virtual void AttachNode(NiNodeStub*);
    void FUN_00b5d180();
};

int strcpy_s(char*, unsigned int, const char*);
unsigned int BSStringLength(const char*);

extern const char str_010709c0[];
extern const char str_01070988[];
extern const char str_01070950[];
extern const char str_01070944[];

struct ListStub
{
    int unk0;
    ~ListStub();
};

struct ElemStub
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    ~ElemStub();
};

struct MenuBase
{
    virtual ~MenuBase();
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
};

struct FUN_00731800 : MenuBase
{
    ElemStub m_pElements[208];
    ListStub* m_d90;
    ListStub* m_d94;
    ListStub* m_d98;
    int m_d9c;
    int m_da0;
    int m_da4;
    int m_da8;
    int m_dac;
    int m_db0;
    int m_db4;
    int m_db8;
    int m_dbc;
    int m_dc0;
    int m_dc4[6];
    int m_ddc[6];
    int m_df4;
    int m_df8;
    int m_dfc;
    int m_e00;
    int m_e04;
    int m_e08;
    int m_e0c[8];
    int m_e2c[8];
    int m_e4c[8];
    int m_e6c;
    virtual ~FUN_00731800();
};

// @fnv 0x00731800
FUN_00731800::~FUN_00731800()
{
    g_thePlayer->FUN_00969b20();
    g_rootA = 0;
    g_modelLoader->FUN_0045a5e0(DAT_011d9058->FUN_00504e00(8)->GetPath());
    g_modelLoader->FUN_0045a5e0(str_010709c0);
    g_modelLoader->FUN_0045a5e0(str_01070988);
    g_modelLoader->FUN_0045a5e0(str_01070950);
    ((SSNStub*)FUN_00450b80(1))->AttachNode(g_rootB);
    ((SSNStub*)FUN_00450b80(1))->FUN_00b5d180();
    ((NiNodeStub*)g_rootB)->DetachAllChildren();
    g_rootB = 0;
    m_db4 = 0;
    m_db8 = 0;
    m_dbc = 0;
    m_dc0 = 0;
    m_df4 = 0;
    m_df8 = 0;
    m_dfc = 0;
    g_rootA = 0;
    int i;
    for (i = 0; i < 8; i++)
    {
        m_e0c[i] = 0;
        m_e2c[i] = 0;
        m_e4c[i] = 0;
    }
    int j;
    for (j = 0; j < 6; j++)
    {
        char* ext = 0;
        char buf[0x104];
        strcpy_s(buf, 0x104, DAT_011d9058->FUN_00504e00(j)->GetPath());
        for (unsigned int k = 0; k < BSStringLength(buf); k++)
        {
            if (buf[k] == '.')
            {
                ext = &buf[k];
                break;
            }
        }
        if (ext)
            strcpy_s(ext, 0xf, str_01070944);
        g_modelLoader->FUN_0045a5e0(DAT_011d9058->FUN_00504e00(j)->GetPath());
        g_modelLoader->FUN_0045a5e0(buf);
        m_dc4[j] = 0;
        m_ddc[j] = 0;
    }
    for (int m = 0; m < 6; m++)
    {
        m_dc4[m] = 0;
        m_ddc[m] = 0;
    }
    m_e6c = 0;
    m_e04 = 0;
    m_e08 = 0;
    m_d90 = 0;
    m_d94 = 0;
    m_d98 = 0;
    DAT_011d9054 = 0;
    DAT_011d9058 = 0;
    g_d9050 = 0;
    delete m_d94;
    delete m_d98;
    delete m_d90;
}
}  // namespace fnv_00731800

namespace fnv_00731d70 {
class NiSourceTexture
{
};
struct VObj731
{
    virtual void u00();
    virtual void u04();
    virtual void u08();
    virtual void u0c();
    virtual void u10();
    virtual char* GetName();
};
struct NameObj731
{
    char* FUN_00408da0();
};
struct GlobObj731
{
    char* FUN_00504e60();
    VObj731* FUN_00504e00(int aIdx);
    NameObj731* FUN_00504e20(int aIdx);
};
extern GlobObj731* DAT_011d9058;
extern float DAT_01016088;
extern float DAT_0101622c;
extern const char str_01070944[];
extern const char str_0101996c[];
extern const char str_01070a18[];
extern const char str_01070a08[];
extern const char str_010709f8[];
int __cdecl strcpy_s(char* aDst, unsigned int aSize, const char* aSrc);
unsigned int __cdecl FUN_0044a670(const char* aStr);
char* __cdecl FUN_004812f0(const char* aStr, const char* aSub);
extern const char DAT_01013444[];
void __cdecl FUN_004b7240(char* aDst, char* aSrc, unsigned int aSize);
struct ModelLoader731
{
    NiNode* __thiscall LoadFile(const char* aName, int a2, bool a3, bool a4, bool a5, bool a6);
};
extern ModelLoader731* g_modelLoader;
struct NiPtrC731
{
    NiSourceTexture* m_pObject;
    NiPtrC731& operator=(const NiPointer<NiSourceTexture>&);
};
struct TES731
{
    void __thiscall CreateTextureImage(const char* aPath, NiPointer<NiSourceTexture>& aTex, bool a4, bool a5);
};
extern TES731* g_TES;
struct CardT731
{
    int m0;
    int m4;
    NiPointer<NiSourceTexture> p8;
    NiPtrC731 pC;
    CardT731();
    ~CardT731();
    CardT731& operator=(const CardT731&);
};
struct This731
{
    char _pad00[0x60];
    float f60;
    float f64;
    char _pad68[0x18];
    unsigned char b80;
    char _pad81[3];
    int arr84[3];
    CardT731 cards[1];
    char _pad94[0xcfc];
    int m_d9c;
    int m_da0;
    char _pad_da4[8];
    unsigned char b_dac;
    char _pad_dad[7];
    NiNode* m_db4;
    char _pad_db8[0xc];
    NiNode* arrDC4[6];
    NiNode* arrDDC[6];
    bool __thiscall LoadCardDeckResources();
};

// Loads deck model and card textures from DAT_011d9058, fills f60/f64/m_d9c/b_dac/m_db4/arrDC4/arrDDC and the cards array, and sets m_da0, arr84 and b80.
// @fnv 0x00731d70
bool __thiscall This731::LoadCardDeckResources()
{
    if (DAT_011d9058 != 0)
    {
        int k2;
        char chTensTmp;
        int j6;
        int _j;
        char buf4[0x104];
        char* pDot9;
        int i4;
        char exts3[4];
        char outBuf4[0x104];
        char* pCur;
        char dir2[0x20];
        char pathBufVal[0x104];
        char dir3[0x20];
        char nameBuf3[0x104];
        this->f60 = *(float*)(DAT_011d9058->FUN_00504e60() + 4);
        this->f64 = *(float*)DAT_011d9058->FUN_00504e60();
        this->m_d9c = *(int*)(DAT_011d9058->FUN_00504e60() + 0x24);
        this->b_dac = (unsigned char)DAT_011d9058->FUN_00504e60()[0x34];
        this->m_db4 = g_modelLoader->LoadFile(DAT_011d9058->FUN_00504e00(8)->GetName(), 0, true, false, false, false);
        for (i4 = 0; i4 < 6; i4++)
        {
            this->arrDC4[i4] =
                g_modelLoader->LoadFile(DAT_011d9058->FUN_00504e00(i4)->GetName(), 0, true, false, false, false);
            pDot9 = 0;
            strcpy_s(buf4, 0x104, DAT_011d9058->FUN_00504e00(i4)->GetName());
            for (_j = 0; _j < FUN_0044a670(buf4); _j++)
            {
                if (buf4[_j] == '.')
                {
                    pDot9 = &buf4[_j];
                    break;
                }
            }
            if (pDot9 != 0)
            {
                strcpy_s(pDot9, 0xf, str_01070944);
                this->arrDDC[i4] = g_modelLoader->LoadFile(buf4, 0, true, false, false, false);
            }
        }
        if (this->m_d9c == 0)
            this->m_d9c = 1;
        if (this->f60 == 0.0)
            this->f60 = DAT_01016088;
        if (this->f64 == 0.0)
            this->f64 = DAT_0101622c;
        CardT731 card3;
        exts3[0] = 'h';
        exts3[1] = 'c';
        exts3[2] = 'd';
        exts3[3] = 's';
        for (j6 = 0; j6 < this->m_d9c; j6++)
        {
            int m9;
            char chOnes;
            strcpy_s(nameBuf3, 0x104, DAT_011d9058->FUN_00504e20(j6 + 7)->FUN_00408da0());
            pCur = FUN_004812f0(nameBuf3, DAT_01013444);
            pCur++;
            pCur = FUN_004812f0(pCur, DAT_01013444);
            pCur++;
            k2 = 0;
            while (pCur != 0 && *pCur != '\\')
            {
                dir3[k2] = *pCur;
                pCur++;
                k2++;
            }
            pCur++;
            dir3[k2] = '\\';
            k2++;
            dir3[k2] = 0;
            k2 = 0;
            while (pCur != 0 && *pCur != '_')
            {
                dir2[k2] = *pCur;
                pCur++;
                k2++;
            }
            dir2[k2] = 0;
            _sprintf_s(nameBuf3, 0x104, str_0101996c, str_01070a18, dir3);
            chTensTmp = '0';
            chOnes = '1';
            k2 = 0;
            _sprintf_s(outBuf4, 0x104, str_01070a08, nameBuf3, dir2);
            NiPointer<NiSourceTexture> spTex((NiSourceTexture*)0);
            FUN_004b7240(outBuf4, pathBufVal, 0x104);
            g_TES->CreateTextureImage(pathBufVal, spTex, false, false);
            for (m9 = 0; m9 < 0x34; m9++)
            {
                card3.m0 = (m9 + 12) % 13;
                card3.m4 = m9 / 13;
                _sprintf_s(outBuf4, 0x104, str_010709f8, nameBuf3, dir2, exts3[k2], chTensTmp, chOnes);
                FUN_004b7240(outBuf4, pathBufVal, 0x104);
                g_TES->CreateTextureImage(pathBufVal, card3.p8, false, false);
                card3.pC = spTex;
                this->cards[j6 * 52 + m9] = card3;
                chOnes++;
                if (chOnes > '9')
                {
                    chOnes = '0';
                    chTensTmp++;
                }
                if (chTensTmp == '1' && chOnes == '4')
                {
                    chTensTmp = '0';
                    chOnes = '1';
                    k2++;
                }
            }
        }
        {
            int n2;
            this->m_da0 = this->m_d9c * 0x34;
            for (n2 = 0; n2 < 3; n2++)
                this->arr84[n2] = 1;
            this->b80 = 0;
        }
        return true;
    }
    return false;
}
}  // namespace fnv_00731d70

struct Local12_cls
{
    int m0;
    int m4;
    int m8;
    void __thiscall FUN_0043d410(float a1, int a2, int a3);
};

struct Node_cls
{
    void __thiscall FUN_00450f90(int);
};

struct Tail2_cls
{
    void __thiscall FUN_00a59c60();
};

struct Tail1_cls
{
    Tail2_cls* __thiscall FUN_0043b4a0();
};

struct Mgr_cls
{
    Tail1_cls* __thiscall FUN_00559450(int, Local12_cls*);
};

extern Mgr_cls DAT_011d9098;
extern char str_01070e58[];
extern char str_01070e44[];

Node_cls* __cdecl FUN_004aae30(int value, char const* name);

struct FUN_007399f0_cls
{
    unsigned char _pad0[0xdb4];
    int m_db4;

    bool __thiscall HasFlag(int aFlag);
    void __thiscall FUN_007399f0();
};

// @fnv 0x007399f0
void __thiscall FUN_007399f0_cls::FUN_007399f0()
{
    Local12_cls tmp;
    Node_cls* node;

    if (HasFlag(0x10))
    {
        node = FUN_004aae30(m_db4, str_01070e58);
        node->FUN_00450f90(1);
        node = FUN_004aae30(m_db4, str_01070e44);
        node->FUN_00450f90(0);
    }
    else
    {
        node = FUN_004aae30(m_db4, str_01070e58);
        node->FUN_00450f90(0);
        node = FUN_004aae30(m_db4, str_01070e44);
        node->FUN_00450f90(1);
    }

    tmp.FUN_0043d410(0.0f, 0, 0);
    DAT_011d9098.FUN_00559450(1, &tmp)->FUN_0043b4a0()->FUN_00a59c60();
}

struct ChipNodeX
{
    void SetLocalRotation(float afX, float afY, float afZ);
};
struct UpdateDataX
{
    float fTime;
    bool m_bUpdateEnabled;
    bool bIsMultiThreaded;
    short sPad;
    int iActionIndex;
    UpdateDataX(float afTime, bool abUpdateControllers, bool abIsMultiThreaded);
};
struct RootNodeX
{
    void Update(const UpdateDataX& arData);
};
struct RootPtrX
{
    RootNodeX* m_pObject;
    operator RootNodeX*() const;
};
extern RootPtrX xspTableRoot;
struct BlackJackChipsX
{
    char _pad00[0x6c];
    int iBet;
    char _pad70[0xdc4 - 0x70];
    ChipNodeX* apChips[12];
    void UpdateChipPositions();
};
// Positions the twelve chip nodes along Z according to the bet amount, then updates the table root node with a zero-time update.
// @fnv 0x00739b30
void BlackJackChipsX::UpdateChipPositions()
{
    if (iBet < 7)
    {
        apChips[0]->SetLocalRotation(0.0f, 0.0f, iBet * 0.18000000000000002);
        apChips[1]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[2]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[3]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[4]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[5]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[6]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[7]->SetLocalRotation(0.0f, 0.0f, -5.0f);
        apChips[8]->SetLocalRotation(0.0f, 0.0f, -5.0f);
        apChips[9]->SetLocalRotation(0.0f, 0.0f, -5.0f);
        apChips[10]->SetLocalRotation(0.0f, 0.0f, -5.0f);
        apChips[11]->SetLocalRotation(0.0f, 0.0f, -5.0f);
    }
    else if (iBet < 40)
    {
        apChips[0]->SetLocalRotation(0.0f, 0.0f, (iBet % 5 + 5) * 0.18000000000000002);
        apChips[1]->SetLocalRotation(0.0f, 0.0f, (iBet / 5 - 1) * 0.18000000000000002);
        apChips[2]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[3]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[4]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[5]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[6]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        iBet > 10 ? apChips[7]->SetLocalRotation(0.0f, 0.0f, 0.0f) : apChips[7]->SetLocalRotation(0.0f, 0.0f, -5.0f);
        apChips[8]->SetLocalRotation(0.0f, 0.0f, -5.0f);
        apChips[9]->SetLocalRotation(0.0f, 0.0f, -5.0f);
        apChips[10]->SetLocalRotation(0.0f, 0.0f, -5.0f);
        apChips[11]->SetLocalRotation(0.0f, 0.0f, -5.0f);
    }
    else if (iBet <= 100)
    {
        apChips[0]->SetLocalRotation(0.0f, 0.0f, 0.9f);
        apChips[1]->SetLocalRotation(0.0f, 0.0f, 0.9f);
        apChips[2]->SetLocalRotation(0.0f, 0.0f, (iBet / 10 - 3) * 0.18000000000000002);
        apChips[3]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[4]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[5]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[6]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[7]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[8]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[9]->SetLocalRotation(0.0f, 0.0f, -5.0f);
        apChips[10]->SetLocalRotation(0.0f, 0.0f, -5.0f);
        apChips[11]->SetLocalRotation(0.0f, 0.0f, -5.0f);
    }
    else if (iBet <= 300)
    {
        apChips[0]->SetLocalRotation(0.0f, 0.0f, 1.8f);
        apChips[1]->SetLocalRotation(0.0f, 0.0f, 1.44f);
        apChips[2]->SetLocalRotation(0.0f, 0.0f, (iBet % 25 / 10 + 5) * 0.18000000000000002);
        apChips[3]->SetLocalRotation(0.0f, 0.0f, (iBet / 25 - 4) * 0.18000000000000002);
        apChips[4]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[5]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[6]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[7]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[8]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        iBet / 25 - 4 ? apChips[9]->SetLocalRotation(0.0f, 0.0f, 0.0f)
                      : apChips[9]->SetLocalRotation(0.0f, 0.0f, -5.0f);
        apChips[10]->SetLocalRotation(0.0f, 0.0f, -5.0f);
        apChips[11]->SetLocalRotation(0.0f, 0.0f, -5.0f);
    }
    else if (iBet <= 500)
    {
        apChips[0]->SetLocalRotation(0.0f, 0.0f, 1.8f);
        apChips[1]->SetLocalRotation(0.0f, 0.0f, 1.44f);
        apChips[2]->SetLocalRotation(0.0f, 0.0f, 0.9f);
        apChips[4]->SetLocalRotation(0.0f, 0.0f, 0.36f);
        apChips[3]->SetLocalRotation(0.0f, 0.0f, (iBet / 25 - 12) * 0.18000000000000002);
        apChips[5]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[6]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[7]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[8]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[9]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[10]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[11]->SetLocalRotation(0.0f, 0.0f, -5.0f);
    }
    else if (iBet < 1000)
    {
        apChips[0]->SetLocalRotation(0.0f, 0.0f, 1.8f);
        apChips[1]->SetLocalRotation(0.0f, 0.0f, 1.8f);
        apChips[2]->SetLocalRotation(0.0f, 0.0f, 1.62f);
        apChips[3]->SetLocalRotation(0.0f, 0.0f, (iBet % 100 / 25 + 6) * 0.18000000000000002);
        apChips[4]->SetLocalRotation(0.0f, 0.0f, (iBet / 100 - 3) * 0.18000000000000002);
        apChips[5]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[6]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[7]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[8]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[9]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        iBet / 100 - 3 ? apChips[10]->SetLocalRotation(0.0f, 0.0f, 0.0f)
                       : apChips[10]->SetLocalRotation(0.0f, 0.0f, -5.0f);
        apChips[10]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[11]->SetLocalRotation(0.0f, 0.0f, -5.0f);
    }
    else if (iBet < 1500)
    {
        apChips[0]->SetLocalRotation(0.0f, 0.0f, 1.8f);
        apChips[1]->SetLocalRotation(0.0f, 0.0f, 1.8f);
        apChips[2]->SetLocalRotation(0.0f, 0.0f, 1.62f);
        apChips[3]->SetLocalRotation(0.0f, 0.0f, 1.8f);
        apChips[5]->SetLocalRotation(0.0f, 0.0f, 0.18f);
        apChips[4]->SetLocalRotation(0.0f, 0.0f, (iBet / 100 - 9) * 0.18000000000000002);
        apChips[6]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[7]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[8]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[9]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[10]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[11]->SetLocalRotation(0.0f, 0.0f, 0.0f);
    }
    else
    {
        int iStackCount = iBet / 500 - 3 > 10 ? 10 : iBet / 500 - 3;
        apChips[0]->SetLocalRotation(0.0f, 0.0f, 1.8f);
        apChips[1]->SetLocalRotation(0.0f, 0.0f, 1.8f);
        apChips[2]->SetLocalRotation(0.0f, 0.0f, 1.8f);
        apChips[3]->SetLocalRotation(0.0f, 0.0f, 1.8f);
        apChips[4]->SetLocalRotation(0.0f, 0.0f, 1.8f);
        apChips[5]->SetLocalRotation(0.0f, 0.0f, iStackCount * 0.18000000000000002);
        apChips[6]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[7]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[8]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[9]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        apChips[10]->SetLocalRotation(0.0f, 0.0f, 0.0f);
        iBet == 1500 ? apChips[11]->SetLocalRotation(0.0f, 0.0f, -5.0f)
                     : apChips[11]->SetLocalRotation(0.0f, 0.0f, 0.0f);
    }
    UpdateDataX kData(0.0f, false, false);
    ((RootNodeX*)xspTableRoot)->Update(kData);
}

namespace fnv_007c06f0 {
struct Menu
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    Menu();
    virtual ~Menu();
};
class NiNode;
template <class T> class NiPtr
{
  public:
    T* m_pObject;
    NiPtr();
    ~NiPtr();
};
class TESForm;
struct PlayerStandIn
{
    int GetField630();
    int FUN_00575610(TESForm*);
};
extern PlayerStandIn* g_thePlayer;
struct FormHolder
{
    TESForm* FUN_007316d0();
};
extern FormHolder* g_formHolder;
int __cdecl TraitNameToIDAdd(const char*, int);
extern int g_traitValue;
extern int g_traitX;
struct FUN_007c06f0 : Menu
{
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
    NiPtr<NiNode> nodes[8];
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    FUN_007c06f0();
    virtual ~FUN_007c06f0();
};
// @fnv 0x007c06f0
FUN_007c06f0::FUN_007c06f0()
{
    g_traitValue = TraitNameToIDAdd("_Value", -1);
    g_traitX = TraitNameToIDAdd("_x", -1);
    unk28 = 0;
    unkF4 = 0;
    unk154 = g_thePlayer->GetField630();
    unkFC = 1;
    if (g_formHolder->FUN_007316d0())
        unkD4 = g_thePlayer->FUN_00575610(g_formHolder->FUN_007316d0());
}
}  // namespace fnv_007c06f0

struct String90
{
    const char* value;
    String90(const char*);
    ~String90();
};
struct Controller90
{
    void* FUN_0047a520(const String90&);
    void FUN_0048fef0(float);
};
struct Bound90
{
    float FUN_0084d030();
};
struct Update90
{
    float time;
    bool update, force;
    unsigned short unk06;
    int unk08;
    Update90(float, bool, bool);
};
struct Property90;
struct Node90
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
    virtual void v0dc(Node90*, int);
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0(int, int, Node90*);
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
    Node90(int);
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    void FUN_00a59c60(const Update90&);
    Controller90* FUN_00a5c570(const void*);
    Node90* FUN_00a59d30(int);
    int FUN_00441110();
    Bound90* FUN_0043d450();
    void FUN_00b5ca70(Node90*, float);
};
struct Pointer90
{
    Node90* p;
    Pointer90& FUN_0066b0d0(Node90*);
    Node90* FUN_00559450();
};
extern Pointer90 DAT_011d90bc;
extern int DAT_011f36ac;
struct Loader90
{
    Node90* LoadModel(const char*, int, int, int, int, int);
};
extern Loader90* DAT_011c3b3c;
Node90* __cdecl FUN_004aae30(Node90*, const char*);
void __cdecl FUN_00a6d2d0(Node90*);
struct Menu90
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
    Pointer90 scene;
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
    Node90* rootdb4;
    Node90* rootdb8;
    Node90* rootdbc;
    Node90* rootdc0;
    Node90* cards[6];
    Node90* backs[6];
    Controller90* ctrldf4;
    Controller90* ctrldf8;
    Controller90* ctrldfc;
    Controller90* ctrle00;
    void* anime04;
    void* anime08;
    void* anime0c;
    void* anime10;
    void* anime14;
    void* anime18;
    void* anime1c;
    void* anime20;
    void* anime24;
    void* anime28;
    void* anime2c;
    void* anime30;
    void* anime34;
    void* anime38;
    void* anime3c;
    void* anime40;
    void* anime44;
    void* anime48;
    void* anime4c;
    void* anime50;
    void* anime54;
    void* anime58;
    void* anime5c;
    void* anime60;
    void* anime64;
    void* anime68;
    void* anime6c;
    void InitBlackjackScene();
    void UpdateChipPositions();
    void FUN_00739970(int);
    void HideArrowNodes();
    Node90* FUN_007c2180();
};
// @fnv 0x00732540
void Menu90::InitBlackjackScene()
{
    rootdb8 = DAT_011c3b3c->LoadModel("Meshes\\Terminals\\NV_BlackJack\\NV_Blackjack-Hand1.NIF", 0, 1, 0, 0, 0);
    rootdbc = DAT_011c3b3c->LoadModel("Meshes\\Terminals\\NV_BlackJack\\NV_Blackjack-Hand2.NIF", 0, 1, 0, 0, 0);
    rootdc0 = DAT_011c3b3c->LoadModel("Meshes\\Terminals\\NV_BlackJack\\NV_Blackjack-Dealer.NIF", 0, 1, 0, 0, 0);
    Node90* root8 = rootdb4;
    DAT_011d90bc.FUN_0066b0d0(FUN_004aae30(rootdb4, "object1"));
    ((Pointer90*)&DAT_011d9098)->FUN_0066b0d0(new Node90(0));
    ((Pointer90*)&DAT_011d9098)->FUN_00559450()->v0dc(rootdb4, 1);
    ((Pointer90*)&DAT_011d9098)->FUN_00559450()->v0dc(rootdb8, 1);
    ((Pointer90*)&DAT_011d9098)->FUN_00559450()->v0dc(rootdbc, 1);
    ((Pointer90*)&DAT_011d9098)->FUN_00559450()->v0dc(rootdc0, 1);
    for (int i = 0; i < 6; i++)
    {
        ((Pointer90*)&DAT_011d9098)->FUN_00559450()->v0dc(cards[i], 1);
        ((Pointer90*)&DAT_011d9098)->FUN_00559450()->v0dc(backs[i], 1);
    }
    UpdateChipPositions();
    FUN_00739970(0);
    HideArrowNodes();
    Update90 update110(0.0f, false, false);
    ((Pointer90*)&DAT_011d9098)->FUN_00559450()->FUN_00a59c60(update110);
    Controller90* controller158 = rootdb4->FUN_00a5c570(&DAT_011f36ac);
    if (controller158)
    {
        ctrldf4 = controller158;
        anime04 = ctrldf4->FUN_0047a520(String90("Players_Discard"));
        anime08 = ctrldf4->FUN_0047a520(String90("Dealers_Discard"));
        ctrldf4->FUN_0048fef0(0.0f);
        FUN_00a6d2d0(rootdb4);
    }
    Controller90* controller217 = rootdb8->FUN_00a5c570(&DAT_011f36ac);
    if (controller217)
    {
        ctrldf8 = controller217;
        anime0c = ctrldf8->FUN_0047a520(String90("Hand1_Discard"));
        anime10 = ctrldf8->FUN_0047a520(String90("Hand1_01"));
        anime14 = ctrldf8->FUN_0047a520(String90("Hand1_02"));
        anime18 = ctrldf8->FUN_0047a520(String90("Hand1_03"));
        anime1c = ctrldf8->FUN_0047a520(String90("Hand1_04"));
        anime20 = ctrldf8->FUN_0047a520(String90("Hand1_05"));
        anime24 = ctrldf8->FUN_0047a520(String90("Hand1_06"));
        anime28 = ctrldf8->FUN_0047a520(String90("Hand1_07"));
        ctrldf8->FUN_0048fef0(0.0f);
        FUN_00a6d2d0(rootdb8);
    }
    Controller90* controller321 = rootdbc->FUN_00a5c570(&DAT_011f36ac);
    if (controller321)
    {
        ctrldfc = controller321;
        anime2c = ctrldfc->FUN_0047a520(String90("Hand2_Discard"));
        anime30 = ctrldfc->FUN_0047a520(String90("Hand2_01"));
        anime34 = ctrldfc->FUN_0047a520(String90("Hand2_02"));
        anime38 = ctrldfc->FUN_0047a520(String90("Hand2_03"));
        anime3c = ctrldfc->FUN_0047a520(String90("Hand2_04"));
        anime40 = ctrldfc->FUN_0047a520(String90("Hand2_05"));
        anime44 = ctrldfc->FUN_0047a520(String90("Hand2_06"));
        anime48 = ctrldfc->FUN_0047a520(String90("Hand2_07"));
        ctrldfc->FUN_0048fef0(0.0f);
        FUN_00a6d2d0(rootdbc);
    }
    Controller90* controller415 = rootdc0->FUN_00a5c570(&DAT_011f36ac);
    if (controller415)
    {
        ctrle00 = controller415;
        anime4c = ctrle00->FUN_0047a520(String90("Dealer_Discard"));
        anime50 = ctrle00->FUN_0047a520(String90("Dealer_01"));
        anime54 = ctrle00->FUN_0047a520(String90("Dealer_02"));
        anime58 = ctrle00->FUN_0047a520(String90("Dealer_03"));
        anime5c = ctrle00->FUN_0047a520(String90("Dealer_04"));
        anime60 = ctrle00->FUN_0047a520(String90("Dealer_05"));
        anime64 = ctrle00->FUN_0047a520(String90("Dealer_06"));
        anime68 = ctrle00->FUN_0047a520(String90("Dealer_07"));
        anime6c = ctrle00->FUN_0047a520(String90("Dealer_Reveal"));
        ctrle00->FUN_0048fef0(0.0f);
        FUN_00a6d2d0(rootdc0);
    }
    Update90 update210(0.0f, false, false);
    ((Pointer90*)&DAT_011d9098)->FUN_00559450()->FUN_00a59c60(update210);
    if (!DAT_011d90bc.FUN_00559450())
        DAT_011d90bc.FUN_0066b0d0(FUN_007c2180());
    Node90* object33 = FUN_004aae30(rootdb4, "Deck:0");
    Node90* property2 = (!object33->FUN_00a59d30(3) ? false
                                                    : (object33->FUN_00a59d30(3)->FUN_00441110() >= 8 &&
                                                       object33->FUN_00a59d30(3)->FUN_00441110() <= 12))
                            ? object33->FUN_00a59d30(3)
                            : 0;
    if (property2)
        property2->v0f0(0, 0, scene.FUN_00559450());
    ((Node90*)FUN_00450b80(1))->v0dc(((Pointer90*)&DAT_011d9098)->FUN_00559450(), 1);
    float scale18 = ((Pointer90*)&DAT_011d9098)->FUN_00559450()->FUN_0043d450()->FUN_0084d030() * 3.0;
    ((Node90*)FUN_00450b80(1))->FUN_00b5ca70(((Pointer90*)&DAT_011d9098)->FUN_00559450(), scale18);
}

struct FUN_00733f50
{
    int id;
    int amount;
    short flags;
    FUN_00733f50();
};
struct Node129
{
    FUN_00733f50** FUN_006815c0();
    Node129* FUN_00726070();
    bool FUN_008256d0();
    void FUN_00726c60(FUN_00733f50* const&);
    void FUN_005ae3d0(FUN_00733f50* const&);
};
struct Settings129
{
    const char* FUN_00403df0();
};
struct BSSoundHandleEx
{
    int id;
    int flags;
    int state;
    ~BSSoundHandleEx();
    bool Play(bool);
};
struct Audio129
{
    BSSoundHandleEx FUN_00ad7550(const char*, int);
};
Audio129* FUN_00453a70();
struct Stats129
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
    int limit;
};
struct Name129
{
    const char* FUN_00408da0();
};
struct Casino129
{
    virtual int v00();
    virtual int v04();
    virtual int v08();
    virtual int v0C();
    virtual int v10();
    virtual int v14();
    virtual int v18();
    virtual int v1C();
    virtual int v20();
    virtual int v24();
    virtual int v28();
    virtual int v2C();
    virtual int v30();
    virtual int v34();
    virtual int v38();
    virtual int v3C();
    virtual int v40();
    virtual int v44();
    virtual int v48();
    virtual int v4C();
    virtual int v50();
    virtual int v54();
    virtual int v58();
    virtual int v5C();
    virtual int v60();
    virtual int v64();
    virtual int v68();
    virtual int v6C();
    virtual int v70();
    virtual int v74();
    virtual int v78();
    virtual int v7C();
    virtual int v80();
    virtual int v84();
    virtual int v88();
    virtual int v8C();
    virtual int v90();
    virtual int v94();
    virtual int v98();
    virtual int v9C();
    virtual int vA0();
    virtual int vA4();
    virtual int vA8();
    virtual int vAC();
    virtual int vB0();
    virtual int vB4();
    virtual int vB8();
    virtual int vBC();
    virtual int vC0();
    virtual int vC4();
    virtual int vC8();
    virtual int vCC();
    virtual int vD0();
    virtual int vD4();
    virtual int vD8();
    virtual int vDC();
    virtual int vE0();
    virtual int vE4();
    virtual int vE8();
    virtual int vEC();
    virtual int vF0();
    virtual int vF4();
    virtual int vF8();
    virtual int vFC();
    virtual int v100();
    virtual int v104();
    virtual int v108();
    virtual int v10C();
    virtual int v110();
    virtual int v114();
    virtual int v118();
    virtual int v11C();
    virtual int v120();
    virtual int v124();
    virtual int v128();
    virtual int v12C();
    virtual const char* GetName();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Name129 name;
    int FUN_0084e3a0();
    Stats129* FUN_00504e60();
};
struct Tile129
{
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float);
    void FUN_00a01350(int, const char*, bool);
    void SetTraitAndReset(int, float);
    void FUN_00700320(int, int);
    struct Menu129* FUN_00a03c90();
};
Tile129* FUN_00a08b20(Tile129*, const char*);
struct Xml129
{
    Tile129* ReadXML();
};
struct Interface129
{
    Xml129* FUN_00586150(const char*);
};
struct Menu129
{
    virtual ~Menu129();
    virtual int v04();
    virtual int v08();
    virtual int v0C();
    virtual int v10();
    virtual int v14();
    virtual int v18();
    virtual int v1C();
    virtual int v20();
    virtual int v24();
    virtual int v28();
    virtual int v2C();
    virtual int v30();
    virtual int GetID();
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
    Tile129* tile34;
    Tile129* tile38;
    Tile129* tile3C;
    Tile129* tile40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int setting;
    int bet;
    void FUN_00a1dc70(Tile129*, int);
    bool FUN_00733f90();
    void UpdateTileText();
    bool LoadCardDeckResources();
    void InitBlackjackScene();
    void FUN_00a1dc20(int);
    void ClearField();
    Tile129* FUN_00726070();
};
struct Mode129
{
    int FUN_0066ef20(int);
};
struct Player129
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
    Mode129 mode;
    Node129* FUN_005a6260();
    bool FUN_00969b80();
    int FUN_00969b40();
};
extern FUN_00733f50* DAT_011d9054;
extern int DAT_0119fe40, DAT_0119fe3c;
extern Settings129 DAT_011d451c, DAT_011d3abc, DAT_011d2424, DAT_011d3594, DAT_011d3804, DAT_011d3300, DAT_011d3e08,
    DAT_011d4c84;
extern const float DAT_010162c0;
extern const double DAT_010704f0, DAT_010704e8;
extern const char DAT_01070c58[], DAT_01049638[], DAT_01025cc4[], DAT_01070c38[], DAT_01070be0[], DAT_01070bc0[],
    DAT_01012058[], DAT_01070ba8[];
Menu129* FUN_00a09030(int);
int FUN_00406d00(char*, unsigned int, const char*, ...);
void DispatchMessageToSink(const char*, int, const char*, int, float, int);
void FUN_005b5e40(const char*);
float __stdcall FUN_00a01530(int);
int FUN_0044a670(const char*);

// Validates the player's casino entry against limits and required amount, then opens and initializes the casino bet menu, returning its tile or null on failure.
// @fnv 0x00733630
Tile129* FUN_00733630(SetMgr* casino, int minimum, int maximum, int required)
{
    Menu129* oldMenu = FUN_00a09030(0x439);
    Interface129* pInterface = (Interface129*)FUN_004b7210();
    DAT_011d9058 = casino;
    DAT_0119fe40 = minimum;
    DAT_0119fe3c = maximum;
    DAT_011d9054 = 0;
    Node129* node = ((Player129*)DAT_011dea3c)->FUN_005a6260();
    while (node && *node->FUN_006815c0())
    {
        if (((Casino129*)DAT_011d9058)->FUN_0084e3a0() == (*node->FUN_006815c0())->id)
        {
            DAT_011d9054 = *node->FUN_006815c0();
            break;
        }
        if (!node->FUN_00726070())
            break;
        node = node->FUN_00726070();
    }
    if (!DAT_011d9054)
    {
        FUN_00733f50* entry = new FUN_00733f50;
        entry->id = ((Casino129*)DAT_011d9058)->FUN_0084e3a0();
        entry->amount = 0;
        node = ((Player129*)DAT_011dea3c)->FUN_005a6260();
        if (!node || node->FUN_008256d0())
            node->FUN_00726c60(entry);
        else
            node->FUN_005ae3d0(entry);
        DAT_011d9054 = entry;
    }
    if (((Player129*)DAT_011dea3c)->FUN_00969b80())
    {
        char message[260];
        FUN_00406d00(message, 260, DAT_01070c58, DAT_011d451c.FUN_00403df0(),
                     ((Player129*)DAT_011dea3c)->FUN_00969b40());
        DispatchMessageToSink(message, 0, DAT_01049638, 0, DAT_010162c0, 0);
        FUN_00453a70()->FUN_00ad7550(DAT_01025cc4, 0x121).Play(false);
        return 0;
    }
    if (DAT_011d9054->amount >= ((Casino129*)DAT_011d9058)->FUN_00504e60()->limit)
    {
        char message[260];
        FUN_00406d00(message, 260, DAT_011d3abc.FUN_00403df0());
        DispatchMessageToSink(message, 0, DAT_01049638, 0, DAT_010162c0, 0);
        FUN_00453a70()->FUN_00ad7550(DAT_01025cc4, 0x121).Play(false);
        return 0;
    }
    if (DAT_011dea3c->FUN_00575610((int)DAT_011d9058->FUN_007316d0()) < DAT_0119fe40)
    {
        char message[260];
        FUN_00406d00(message, 260, DAT_011d2424.FUN_00403df0());
        DispatchMessageToSink(message, 0, DAT_01049638, 0, DAT_010162c0, 0);
        FUN_00453a70()->FUN_00ad7550(DAT_01025cc4, 0x121).Play(false);
        return 0;
    }
    if (DAT_011d9054->amount < required && required != 0)
    {
        char message[260];
        FUN_00406d00(message, 260, DAT_011d3594.FUN_00403df0());
        DispatchMessageToSink(message, 0, DAT_01049638, 0, DAT_010162c0, 0);
        FUN_00453a70()->FUN_00ad7550(DAT_01025cc4, 0x121).Play(false);
        return 0;
    }
    if (oldMenu)
        delete oldMenu;
    Tile129* pTile = pInterface->FUN_00586150(DAT_01070c38)->ReadXML();
    DAT_011d9050 = (DAT_011d9050_S*)pTile->FUN_00a03c90();
    if (DAT_011d9050 && ((Menu129*)DAT_011d9050)->GetID() == FUN_00733f80())
    {
        ((Menu129*)DAT_011d9050)->FUN_00a1dc70(pTile, 0);
        if (!((Menu129*)DAT_011d9050)->FUN_00733f90())
        {
            FUN_005b5e40(DAT_01070be0);
            return 0;
        }
        if (pTile->FUN_00a011b0(0xfa7) == DAT_010704f0 || pTile->FUN_00a011b0(0xfa7) == DAT_010704e8)
            pTile->FUN_00a012d0(0xfad, FUN_00a01530(1));
        FUN_00453a70()->FUN_00ad7550(DAT_01070bc0, 0x121).Play(false);
        ((Menu129*)DAT_011d9050)->setting = ((Player129*)DAT_011dea3c)->mode.FUN_0066ef20(11);
        ((Menu129*)DAT_011d9050)->bet = DAT_0119fe40;
        ((Menu129*)DAT_011d9050)->tile34->FUN_00a01350((int)DAT_011d9044, DAT_011d3804.FUN_00403df0(), true);
        ((Menu129*)DAT_011d9050)->tile34->SetTraitAndReset((int)DAT_011d9048, 1.0f);
        ((Menu129*)DAT_011d9050)->tile34->FUN_00700320((int)DAT_011d9048, DAT_0119fe40);
        ((Menu129*)DAT_011d9050)->tile38->FUN_00a01350((int)DAT_011d9044, DAT_011d3300.FUN_00403df0(), true);
        ((Menu129*)DAT_011d9050)->tile38->SetTraitAndReset((int)DAT_011d9048, 1.0f);
        ((Menu129*)DAT_011d9050)
            ->tile38->FUN_00700320((int)DAT_011d9048, DAT_011dea3c->FUN_00575610((int)DAT_011d9058->FUN_007316d0()));
        char label[64];
        if (FUN_0044a670(((Casino129*)DAT_011d9058)->name.FUN_00408da0()))
            FUN_00406d00(label, 64, DAT_01012058, ((Casino129*)DAT_011d9058)->name.FUN_00408da0(),
                         DAT_011d3e08.FUN_00403df0());
        else
            FUN_00406d00(label, 64, DAT_01012058, ((Casino129*)DAT_011d9058)->GetName(), DAT_011d3e08.FUN_00403df0());
        ((Menu129*)DAT_011d9050)->tile3C->FUN_00a01350((int)DAT_011d9044, label, true);
        ((Menu129*)DAT_011d9050)->tile3C->SetTraitAndReset((int)DAT_011d9048, 1.0f);
        ((Menu129*)DAT_011d9050)->tile3C->FUN_00700320((int)DAT_011d9048, DAT_011d9054->amount);
        FUN_00a08b20(((Menu129*)DAT_011d9050)->tile3C, DAT_01070ba8)->FUN_00700320(0xfa3, 0);
        ((Menu129*)DAT_011d9050)->UpdateTileText();
        ((Menu129*)DAT_011d9050)->tile40->SetTraitAndReset(0xfc4, 1.0f);
        ((Menu129*)DAT_011d9050)->tile40->FUN_00a01350(0xfc4, DAT_011d4c84.FUN_00403df0(), true);
        if (!((Menu129*)DAT_011d9050)->LoadCardDeckResources())
            return 0;
        UpdateBetTiles(true);
        ((Menu129*)DAT_011d9050)->InitBlackjackScene();
        ((Menu129*)DAT_011d9050)->FUN_00a1dc20(0);
        ((Menu129*)DAT_011d9050)->tile40->FUN_00700320(0xfa3, 0);
        ((Menu129*)DAT_011d9050)->ClearField();
        return pTile;
    }
    else if (DAT_011d9050 && ((Menu129*)DAT_011d9050)->FUN_00726070())
        delete (Menu129*)DAT_011d9050;
    return 0;
}

NiAVObject* __cdecl FUN_004aae30(NiAVObject*, const char*);
struct Menu737e50
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
    NiAVObject* table;
    NiAVObject* hand;
    NiAVObject* split;
    void UpdateCulledNodes();
};
// @fnv 0x00737e50
void Menu737e50::UpdateCulledNodes()
{
    char p[30];
    char h[30];
    NiAVObject* a;
    char i[30];
    for (int j = 1; j <= 7; j++)
    {
        _sprintf_s(h, 30, str_01070e34, j, j - 1);
        _sprintf_s(i, 30, str_01070e20, j);
        _sprintf_s(p, 30, str_01070e0c, j);
        a = FUN_004aae30(table, h);
        if (j >= unk084)
        {
            a->SetAppCulled(true);
            a = FUN_004aae30(table, i);
            a->SetAppCulled(true);
            a = FUN_004aae30(table, p);
            a->SetAppCulled(true);
        }
        else
        {
            a->SetAppCulled(false);
            a = FUN_004aae30(table, i);
            a->SetAppCulled(false);
            a = FUN_004aae30(table, p);
            a->SetAppCulled(false);
        }
    }
    for (int k = 1; k <= 7; k++)
    {
        _sprintf_s(h, 30, str_01070dfc, k);
        _sprintf_s(i, 30, str_01070de8, k);
        _sprintf_s(p, 30, str_01070dd4, k);
        a = FUN_004aae30(split, h);
        if (k >= unk08c)
        {
            a->SetAppCulled(true);
            a = FUN_004aae30(split, i);
            a->SetAppCulled(true);
            a = FUN_004aae30(split, p);
            a->SetAppCulled(true);
        }
        else
        {
            a->SetAppCulled(false);
            a = FUN_004aae30(split, i);
            a->SetAppCulled(false);
            a = FUN_004aae30(split, p);
            a->SetAppCulled(false);
        }
    }
    for (int l = 1; l <= 7; l++)
    {
        _sprintf_s(h, 30, str_01070dc4, l, l - 1);
        _sprintf_s(i, 30, str_01070db0, l);
        _sprintf_s(p, 30, str_01070d9c, l);
        a = FUN_004aae30(hand, h);
        if (l >= unk088)
        {
            a->SetAppCulled(true);
            a = FUN_004aae30(hand, i);
            a->SetAppCulled(true);
            a = FUN_004aae30(hand, p);
            a->SetAppCulled(true);
        }
        else
        {
            a->SetAppCulled(false);
            a = FUN_004aae30(hand, i);
            a->SetAppCulled(false);
            a = FUN_004aae30(hand, p);
            a->SetAppCulled(false);
        }
    }
    ((NiNode*)(unsigned int)g_011d9098)->Update(NiUpdateData(0.0f, false, false));
}

extern float DAT_0101e704, DAT_01023cd8;
struct BlackjackButtonMenu
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    int state;
    bool HasFlag(unsigned int);
    void FUN_00738c30(int, float);
    void UpdateButtonState(int);
};
// @fnv 0x00738560
void BlackjackButtonMenu::UpdateButtonState(int button)
{
    if (state == 10)
        return;
    switch (button)
    {
    case 10:
        if (HasFlag(0x10))
        {
            if (HasFlag(0x800))
            {
                FUN_00738c30(3, DAT_0101e704);
                FUN_00738c30(4, DAT_0101e704);
            }
            else
            {
                FUN_00738c30(3, DAT_01023cd8);
                HasFlag(0x100) ? FUN_00738c30(4, DAT_01023cd8) : FUN_00738c30(4, DAT_0101e704);
            }
            FUN_00738c30(5, DAT_0101e704);
            FUN_00738c30(7, DAT_0101e704);
            FUN_00738c30(8, DAT_01023cd8);
            HasFlag(0x400) ? FUN_00738c30(6, DAT_0101e704) : FUN_00738c30(6, DAT_01023cd8);
        }
        else
        {
            if (HasFlag(0x400) || HasFlag(0x20))
            {
                FUN_00738c30(3, DAT_0101e704);
                FUN_00738c30(4, DAT_0101e704);
                FUN_00738c30(5, DAT_0101e704);
                FUN_00738c30(7, DAT_0101e704);
            }
            else
            {
                FUN_00738c30(3, DAT_01023cd8);
                HasFlag(0x40) ? FUN_00738c30(4, DAT_01023cd8) : FUN_00738c30(4, DAT_0101e704);
                HasFlag(4) ? FUN_00738c30(5, DAT_01023cd8) : FUN_00738c30(5, DAT_0101e704);
                HasFlag(1) ? FUN_00738c30(7, DAT_0101e704) : FUN_00738c30(7, DAT_01023cd8);
            }
            HasFlag(0x20) && (!HasFlag(8) || HasFlag(0x800)) ? FUN_00738c30(8, DAT_0101e704)
                                                             : FUN_00738c30(8, DAT_01023cd8);
            !HasFlag(0x800) && HasFlag(8) ? FUN_00738c30(6, DAT_01023cd8) : FUN_00738c30(6, DAT_0101e704);
        }
        break;
    case 3:
        if (HasFlag(0x10))
        {
            HasFlag(0x800) ? FUN_00738c30(3, DAT_0101e704) : FUN_00738c30(3, DAT_01023cd8);
        }
        else
        {
            HasFlag(0x400) ? FUN_00738c30(3, DAT_0101e704) : FUN_00738c30(3, DAT_01023cd8);
        }
        break;
    case 4:
        if (HasFlag(0x10))
        {
            HasFlag(0x100) ? FUN_00738c30(4, DAT_01023cd8) : FUN_00738c30(4, DAT_0101e704);
        }
        else
        {
            HasFlag(0x40) ? FUN_00738c30(4, DAT_01023cd8) : FUN_00738c30(4, DAT_0101e704);
        }
        break;
    case 5:
        if (HasFlag(0x10))
        {
            FUN_00738c30(5, DAT_0101e704);
        }
        else
        {
            HasFlag(4) ? FUN_00738c30(5, DAT_01023cd8) : FUN_00738c30(5, DAT_0101e704);
        }
        break;
    case 6:
        if (HasFlag(0x10))
        {
            HasFlag(0x400) ? FUN_00738c30(6, DAT_0101e704) : FUN_00738c30(6, DAT_01023cd8);
        }
        else
        {
            !HasFlag(0x800) && HasFlag(8) ? FUN_00738c30(6, DAT_01023cd8) : FUN_00738c30(6, DAT_0101e704);
        }
        break;
    case 7:
        HasFlag(1) ? FUN_00738c30(7, DAT_0101e704) : FUN_00738c30(7, DAT_01023cd8);
        break;
    case 8:
        FUN_00738c30(8, DAT_01023cd8);
        break;
    }
}

struct BJCard
{
    int rank;
    int suit;
    int other;
    int ref;
    BJCard();
    ~BJCard();
    BJCard& operator=(const BJCard&);
};
int __cdecl GetRandomNumberInRange(int, int);
int __cdecl FUN_00ec7d40(int);
struct BJDeck
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
    bool flag78;
    bool flag79;
    short unk7a;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    BJCard cards[209];
    int count;
    void Shuffle();
    int HandValue(void*);
    int CardValue(int);
    int DrawCard(void*, bool, bool);
};
// @fnv 0x00739090
int BJDeck::DrawCard(void* hand, bool useSkill, bool split)
{
    BJCard last;
    BJCard selected3;
    int chosen9 = 0;
    if (count < 5)
        Shuffle();
    if (!hand || !useSkill || (split && unk68 > 4) || (!split && unk68 < 6))
    {
        chosen9 = GetRandomNumberInRange(0, count--);
    }
    else
    {
        int total6 = HandValue(hand);
        int bestIndex_2 = 0;
        int lowIndex3 = 0;
        int best_ = total6;
        int low2 = total6;
        int trials9 = FUN_00ec7d40(unk68 - 5);
        int indices[5];
        for (int fill2 = 0; fill2 < trials9; fill2++)
            indices[fill2] = GetRandomNumberInRange(0, count);
        for (int scan = 0; scan < trials9; scan++)
        {
            int value_ = CardValue(cards[indices[scan]].rank);
            if (value_ == 11)
                value_ = value_ + total6 > 21 ? 1 : 11;
            if (total6 > 9)
            {
                int sumHigh = value_ + total6;
                if (sumHigh > best_ && sumHigh < 22)
                {
                    best_ = sumHigh;
                    bestIndex_2 = scan;
                }
            }
            else
            {
                int sumLowA = value_ + total6;
                if (21 - sumLowA < best_ && sumLowA < 22)
                {
                    best_ = 21 - sumLowA;
                    bestIndex_2 = scan;
                }
                if (11 - sumLowA < low2 && sumLowA < 12)
                {
                    low2 = 11 - sumLowA;
                    lowIndex3 = scan;
                }
            }
            if (best_ < 4)
            {
                chosen9 = indices[bestIndex_2];
                if (bestIndex_2)
                    split ? flag79 = true : flag78 = true;
            }
            else if (low2 < best_ && low2 < 2)
            {
                chosen9 = indices[lowIndex3];
                if (lowIndex3)
                    split ? flag79 = true : flag78 = true;
            }
            else
                chosen9 = indices[bestIndex_2];
        }
    }
    selected3 = cards[chosen9];
    last = cards[count];
    cards[count] = selected3;
    cards[chosen9] = last;
    return count--;
}

class TESObjectREFR;
template <class C> class BSStringT
{
  public:
    operator const C*() const;
};
template <class T> class NiTPointerList
{
  public:
    T& AddEight(void* pos) const;
    void* DereferenceIfNotNull(void* pos) const;
    int* FUN_0073ac90();
};
struct FUN_00a012d0_t
{
    void FUN_00a012d0(int, float, bool);
};
struct Entry738c
{
    int m_00;
    NiTPointerList<TESObjectREFR*> m_kList;
};
struct Table738c
{
    char _pad[0x34];
    Entry738c* m_apEntries[1];
};

// Iterates the reference list of entry iIndex in table DAT_011d9050 and calls FUN_00a012d0(0xfa9, fValue, true) on each element.
// @fnv 0x00738c30
void FUN_00738c30_shell::FUN_00738c30(int iIndex, float fValue)
{
    void* pos = (void*)(const char*)*(BSStringT<char>*)&((Table738c*)DAT_011d9050)->m_apEntries[iIndex]->m_kList;
    NiTPointerList<TESObjectREFR*>* pkList = &((Table738c*)DAT_011d9050)->m_apEntries[iIndex]->m_kList;
    while (pos && pkList && *pkList->FUN_0073ac90())
    {
        ((FUN_00a012d0_t*)pkList->AddEight(pos))->FUN_00a012d0(0xfa9, fValue, true);
        pos = pkList->DereferenceIfNotNull(pos);
    }
}

struct CardInfo
{
    int unk00;
    int unk04;
    Pointer90 unk08;
    Pointer90 unk0c;
};

struct TableNode : Node90
{
    Node90* __thiscall FUN_0043b4a0(int index);
};

struct GlobalPtr
{
    TableNode* FUN_00559450();
};

struct BlackjackMenuShell
{
    void FUN_007396e0(int a1, int a2, CardInfo* a3);
};

// @fnv 0x007396e0
void BlackjackMenuShell::FUN_007396e0(int a1, int aiIndex, CardInfo* apCardInfo)
{
    Node90* _prop;
    char aBuf1[30];
    Node90* node2;
    char buf2[30];

    a1++;
    if (aiIndex > 7 || aiIndex < 1 || !apCardInfo)
        return;

    switch (a1)
    {
    case 1:
        _sprintf_s(aBuf1, 30, str_01070e34, aiIndex, aiIndex - 1);
        _sprintf_s(buf2, 30, str_01070e20, aiIndex);
        break;
    case 2:
        _sprintf_s(aBuf1, 30, str_01070dc4, aiIndex, aiIndex - 1);
        _sprintf_s(buf2, 30, str_01070db0, aiIndex);
        break;
    case 3:
        _sprintf_s(aBuf1, 30, str_01070dfc, aiIndex);
        _sprintf_s(buf2, 30, str_01070de8, aiIndex);
        break;
    default:
        return;
    }

    node2 = FUN_004aae30(((GlobalPtr*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(a1), aBuf1);
    _prop = (!node2->FUN_00a59d30(3)
                 ? 0
                 : (node2->FUN_00a59d30(3)->FUN_00441110() >= 8 && node2->FUN_00a59d30(3)->FUN_00441110() <= 12))
                ? node2->FUN_00a59d30(3)
                : 0;
    if (_prop)
    {
        _prop->v0f0(0, 0, apCardInfo->unk08.FUN_00559450());
    }

    node2 = FUN_004aae30(((GlobalPtr*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(a1), buf2);
    _prop = (!node2->FUN_00a59d30(3)
                 ? 0
                 : (node2->FUN_00a59d30(3)->FUN_00441110() >= 8 && node2->FUN_00a59d30(3)->FUN_00441110() <= 12))
                ? node2->FUN_00a59d30(3)
                : 0;
    if (_prop)
    {
        _prop->v0f0(0, 0, apCardInfo->unk0c.FUN_00559450());
    }
}

struct OwnQ
{
    int FUN_00738ff0(Node129* pList);
};
// Sums adjusted card values, counts entries with value 12, then subtracts 10 per such entry while total exceeds 21.
// @fnv 0x00738ff0
int OwnQ::FUN_00738ff0(Node129* pList)
{
    int iTotal;
    int iAces;
    int* pCard_biq;
    Node129* pIter_lcjr;
    iTotal = 0;
    iAces = 0;
    pIter_lcjr = pList;
    while (pIter_lcjr && *pIter_lcjr->FUN_006815c0())
    {
        pCard_biq = (int*)*pIter_lcjr->FUN_006815c0();
        iTotal += ((FUN_00738fb0_shell*)this)->GetAdjustedValue(*pCard_biq);
        if (*pCard_biq == 12)
            iAces++;
        pIter_lcjr = pIter_lcjr->FUN_00726070();
    }
    while (iTotal > 21 && iAces > 0)
    {
        iTotal -= 10;
        iAces--;
    }
    return iTotal;
}

struct CardHand
{
    CardInfo** FUN_006815c0();
    CardHand* FUN_00726070();
    bool FUN_008256d0();
    void FUN_00726c60(CardInfo* const&);
    void FUN_005ae3d0(CardInfo* const&);
    void FUN_00905820(CardInfo* const&);
};
struct MenuGlobalView : Menu129
{
};
extern const char DAT_01070cc0[], DAT_01070ca4[], DAT_01070c88[];
struct InputMenu
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
    int state;
    int result;
    int splitResult;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    P09TileS* text;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int bet;
    int splitBet;
    int funds;
    bool flag78;
    bool flag79;
    short unk7a;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    CardInfo cards[208];
    CardHand* dealer;
    CardHand* hand;
    CardHand* split;
    void HandleAction(int, void*);
    void UpdateButtonState(int);
    bool HasFlag(int);
    void SetFlag(int, bool);
    int DrawCard(void*, bool, bool);
    int FUN_00738ff0(CardHand*);
    void ClearField();
    void FUN_00738c30(int, float);
    void DealInitialCards();
    bool FUN_00739650(bool);
    void UpdateChipPositions();
    void FUN_007396e0(int, int, CardInfo*);
    void FUN_007399f0();
};
// Dispatches a UI action (hit, double, split, raise, lower, max, stand) to the appropriate blackjack state transition and card logic.
// @fnv 0x00733ff0
void InputMenu::HandleAction(int action, void* tile)
{
    if (state == 10 || state == 4)
    {
        switch (action)
        {
        case 8:
            if (state == 10)
                FUN_00731d30();
            else if (state == 4)
            {
                state = 8;
                UpdateButtonState(10);
            }
            break;
        case 3:
            if (state == 4)
            {
                int hitTotal7 = 0;
                int hitIndex7 = 0;
                state = 2;
                SetFlag(1, true);
                UpdateButtonState(7);
                SetFlag(0x100, false);
                SetFlag(0x40, false);
                SetFlag(4, false);
                if (HasFlag(0x10) && !HasFlag(0x800))
                {
                    hitIndex7 = DrawCard(split, true, false);
                    split->FUN_00905820(&cards[hitIndex7]);
                    hitTotal7 = FUN_00738ff0(split);
                    if (hitTotal7 >= 21)
                    {
                        SetFlag(0x800, true);
                        if (hitTotal7 > 21)
                            splitResult = 4;
                    }
                    SetFlag(0x100, false);
                    CardHand* splitWalk5 = split;
                    int splitCount = 0;
                    while (splitWalk5 && *splitWalk5->FUN_006815c0())
                    {
                        splitCount++;
                        splitWalk5 = splitWalk5->FUN_00726070();
                    }
                    if (splitCount >= 7)
                    {
                        SetFlag(0x800, true);
                        text->Set(0xfc4, DAT_01070cc0, true);
                    }
                }
                else if (!HasFlag(0x10) && !HasFlag(0x400))
                {
                    hitIndex7 = DrawCard(hand, true, false);
                    hand->FUN_00905820(&cards[hitIndex7]);
                    hitTotal7 = FUN_00738ff0(hand);
                    if (hitTotal7 >= 21)
                    {
                        SetFlag(0x400, true);
                        if (hitTotal7 > 21)
                            result = 4;
                    }
                    SetFlag(0x40, false);
                    CardHand* handWalk6 = hand;
                    int handCountA = 0;
                    while (handWalk6 && *handWalk6->FUN_006815c0())
                    {
                        handCountA++;
                        handWalk6 = handWalk6->FUN_00726070();
                    }
                    if (handCountA >= 7)
                    {
                        SetFlag(0x400, true);
                        text->Set(0xfc4, DAT_01070cc0, true);
                    }
                }
                UpdateButtonState(10);
            }
            break;
        case 4:
            if (state == 10)
            {
                state = 1;
                ClearField();
                flag79 = false;
                flag78 = false;
                splitBet = 0;
                SetFlag(0x40, true);
                FUN_00738c30(4, DAT_0101e704);
                FUN_00738c30(5, DAT_0101e704);
                FUN_00738c30(6, DAT_0101e704);
                FUN_00738c30(7, DAT_0101e704);
                FUN_00738c30(8, DAT_0101e704);
                DealInitialCards();
            }
            else if (state == 4)
            {
                if (HasFlag(0x10) && HasFlag(0x100))
                {
                }
                else if (HasFlag(0x40))
                {
                    bet *= 2;
                    SetFlag(0x80, true);
                    SetFlag(0x400, true);
                    int doubleIndex = 0;
                    doubleIndex = DrawCard(hand, true, false);
                    hand->FUN_00905820(&cards[doubleIndex]);
                    if (!HasFlag(0x400) && HasFlag(0x40))
                        FUN_00739650(false);
                    state = 2;
                    SetFlag(1, true);
                    ((Menu129*)DAT_011d9050)->tile34->SetTraitAndReset((int)DAT_011d9048, 1.0f);
                    ((Menu129*)DAT_011d9050)->tile34->FUN_00700320((int)DAT_011d9048, splitBet + bet);
                    int aDoubleTotal = FUN_00738ff0(hand);
                    if (aDoubleTotal > 21)
                        result = 4;
                    SetFlag(0x40, false);
                }
                UpdateButtonState(10);
            }
            break;
        case 5:
            if (state == 10)
            {
                int oldIncreaseTmp = bet;
                if (bet < 10)
                    bet++;
                else if (bet < 40)
                    bet += 5;
                else if (bet < 100)
                    bet += 10;
                else if (bet < 400)
                    bet += 25;
                else if (bet < 1500)
                    bet += 100;
                else
                    bet += 500;
                if (bet > funds)
                    bet = funds;
                if (bet > DAT_0119fe3c)
                    bet = DAT_0119fe3c;
                if (oldIncreaseTmp < bet)
                    FUN_00453a70()->FUN_00ad7550(DAT_01070ca4, 0x121).Play(false);
                UpdateChipPositions();
                ((Menu129*)DAT_011d9050)->tile34->SetTraitAndReset((int)DAT_011d9048, 1.0f);
                ((Menu129*)DAT_011d9050)->tile34->FUN_00700320((int)DAT_011d9048, bet);
            }
            else if (state == 4)
            {
                if (HasFlag(4))
                {
                    SetFlag(0x100, false);
                    SetFlag(0x40, false);
                    state = 3;
                    SetFlag(1, true);
                    CardHand* secondNode3 = hand->FUN_00726070();
                    CardInfo* splitCard7 = *secondNode3->FUN_006815c0();
                    int splitIndex = 0;
                    splitBet = bet;
                    if (!split || split->FUN_008256d0())
                        split->FUN_00726c60(splitCard7);
                    else
                        split->FUN_005ae3d0(splitCard7);
                    FUN_007396e0(1, 1, splitCard7);
                    splitIndex = DrawCard(hand, false, false);
                    secondNode3->FUN_00726c60(&cards[splitIndex]);
                    splitIndex = DrawCard(split, false, false);
                    split->FUN_00905820(&cards[splitIndex]);
                    int handTotal8 = FUN_00738ff0(hand);
                    int splitTotal2 = FUN_00738ff0(hand);
                    if (handTotal8 == 21)
                    {
                        result = 5;
                        SetFlag(0x400, true);
                    }
                    FUN_00739650(false);
                    if (splitTotal2 == 21)
                    {
                        splitResult = 5;
                        SetFlag(0x800, true);
                    }
                    FUN_00739650(true);
                    SetFlag(8, true);
                    SetFlag(4, false);
                    FUN_007399f0();
                    UpdateButtonState(10);
                    ((Menu129*)DAT_011d9050)->tile34->SetTraitAndReset((int)DAT_011d9048, 1.0f);
                    ((Menu129*)DAT_011d9050)->tile34->FUN_00700320((int)DAT_011d9048, splitBet + bet);
                }
            }
            break;
        case 6:
            if (state == 10)
            {
                int kOldDecrease = bet;
                if (bet <= 10)
                    bet--;
                else if (bet <= 40)
                    bet = bet % 5 ? bet / 5 * 5 : bet - 5;
                else if (bet <= 100)
                    bet = bet % 10 ? bet / 10 * 10 : bet - 10;
                else if (bet <= 400)
                    bet = bet % 25 ? bet / 25 * 25 : bet - 25;
                else if (bet <= 1500)
                    bet = bet % 100 ? bet / 100 * 100 : bet - 100;
                else
                    bet = bet % 500 ? bet / 500 * 500 : bet - 500;
                if (bet < DAT_0119fe40)
                    bet = DAT_0119fe40;
                if (kOldDecrease > bet)
                    FUN_00453a70()->FUN_00ad7550(DAT_01070c88, 0x121).Play(false);
                UpdateChipPositions();
                ((Menu129*)DAT_011d9050)->tile34->SetTraitAndReset((int)DAT_011d9048, 1.0f);
                ((Menu129*)DAT_011d9050)->tile34->FUN_00700320((int)DAT_011d9048, bet);
            }
            else if (state == 4)
            {
                if (HasFlag(8))
                {
                    if (HasFlag(0x10) && !HasFlag(0x400))
                        SetFlag(0x10, false);
                    else if (!HasFlag(0x10) && !HasFlag(0x800))
                        SetFlag(0x10, true);
                    FUN_007399f0();
                    text->Set(0xfc4, "", true);
                    UpdateButtonState(10);
                }
            }
            break;
        case 7:
            if (state == 10)
            {
                bet = DAT_0119fe3c;
                if (bet > funds)
                    bet = funds;
                UpdateChipPositions();
                ((Menu129*)DAT_011d9050)->tile34->SetTraitAndReset((int)DAT_011d9048, 1.0f);
                ((Menu129*)DAT_011d9050)->tile34->FUN_00700320((int)DAT_011d9048, bet);
            }
            if (state == 4)
            {
                if (!HasFlag(1))
                {
                    SetFlag(0x400, true);
                    result = 6;
                    state = 8;
                    UpdateButtonState(10);
                }
            }
            break;
        }
    }
}
