
// src/fallout/interface/menus/recipemenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/recipemenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct RecipeMenu
{
    int FUN_00726f00();
};

// @fnv 0x00726f00
int RecipeMenu::FUN_00726f00()
{
    return 0x435;
}

struct GlobalObject_0072ce30
{
};

GlobalObject_0072ce30 g_011d8f08;

// @fnv 0x00726f10
GlobalObject_0072ce30* FUN_00726f10()
{
    return &g_011d8f08;
}

struct WeatherEntry;

struct BSSimpleList_WeatherEntry
{
    void __thiscall Sort(int(__cdecl*)(WeatherEntry*, WeatherEntry*)) const;
};

struct FUN_0072b580_shell
{
    int m_auiShapeKeys;
    BSSimpleList_WeatherEntry m_kNode;
    void __thiscall FUN_0072b580(int(__cdecl*)(WeatherEntry*, WeatherEntry*));
    void __thiscall FUN_0072c700();
};

// Sorts the weather entry list using the given comparison function, then calls FUN_0072c700.
// @fnv 0x0072b580
void __thiscall FUN_0072b580_shell::FUN_0072b580(int(__cdecl* cmp)(WeatherEntry*, WeatherEntry*))
{
    m_kNode.Sort(cmp);
    FUN_0072c700();
}

struct FUN_0072b9c0_shell
{
    void* FUN_0072b9c0(unsigned int flags);
    void FUN_00729a70();
};

void __cdecl _Deallocate(void*);

// Calls FUN_00729a70, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0072b9c0
void* FUN_0072b9c0_shell::FUN_0072b9c0(unsigned int flags)
{
    FUN_00729a70();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_0072ba80_shell
{
    void FUN_0072ba80(void* apFirstAddr, unsigned int aiCount);
};

// @fnv 0x0072ba80
void FUN_0072ba80_shell::FUN_0072ba80(void* apFirstAddr, unsigned int aiCount)
{
    for (unsigned int i = 0; i < aiCount; ++i)
    {
    }
}

struct RecipeMenu_00726f20
{
    void __thiscall FUN_00726f50();
    void* __thiscall FUN_00726f20(unsigned int flags);
};

// @fnv 0x00726f20
void* __thiscall RecipeMenu_00726f20::FUN_00726f20(unsigned int flags)
{
    FUN_00726f50();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int DAT_011d8e90;
extern char DAT_011d8ea4;

struct FUN_00727680_shell
{
    void __thiscall PopulateChallengeList(int, int);
};

// If abNow is set, calls PopulateChallengeList on DAT_011d8e90 when non-null and clears DAT_011d8ea4; otherwise sets DAT_011d8ea4 to 1.
// @fnv 0x00728a30
void __cdecl FUN_00728a30(bool abNow)
{
    if (abNow)
    {
        if (DAT_011d8e90 != 0)
        {
            reinterpret_cast<FUN_00727680_shell*>(DAT_011d8e90)->PopulateChallengeList(0, 0);
        }
        DAT_011d8ea4 = 0;
    }
    else
    {
        DAT_011d8ea4 = 1;
    }
}

struct FNStub
{
    char const* GetFullName();
};
int __cdecl _mbscmp(unsigned char const*, unsigned char const*);
// Compares the full names of two WeatherEntry objects via GetFullName and _mbscmp, returning the comparison result.
// @fnv 0x007278c0
int __cdecl CompareWeatherEntryNames(WeatherEntry* apEntryA, WeatherEntry* apEntryB)
{
    const char* pNameA;
    {
        void* v2;
        {
            int r;
            {
                const char* pNameB;
                {
                    void* v1;
                    v1 = *(void**)apEntryA;
                    v2 = *(void**)apEntryB;
                    pNameA = ((FNStub*)((char*)v1 + 0x18))->GetFullName();
                    pNameB = ((FNStub*)((char*)v2 + 0x18))->GetFullName();
                    r = 0;
                    r = _mbscmp((unsigned char const*)pNameA, (unsigned char const*)pNameB);
                    return r;
                }
            }
        }
    }
}

struct TESChallenge
{
    int GetThreshold();
};
struct BSSimpleArray
{
    unsigned int& GetAt(int);
};
extern int DAT_0119fbf4;
// Returns false if DAT_0119fbf4 is -1; otherwise returns true when the challenge's threshold differs from the array element at that index.
// @fnv 0x00728d60
bool IsThresholdDifferent(TESChallenge* apChallenge)
{
    if (DAT_0119fbf4 == -1)
        return false;
    else if (apChallenge->GetThreshold() != (int)((BSSimpleArray*)FUN_00726f10())->GetAt(DAT_0119fbf4))
        return true;
    return false;
}

void __cdecl FUN_00ec6f20(int, int, int, int);
struct FUN_00729970_shell
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    void __thiscall FUN_00729970(int aiParam);
};
// @fnv 0x00729970
void __thiscall FUN_00729970_shell::FUN_00729970(int aiParam)
{
    FUN_00ec6f20(m_kPointB, m_iThirdValue, 4, aiParam);
}

struct FUN_00729fb0_shell
{
    void __thiscall BuildMenuEntries();
    void __thiscall FUN_00729fb0(int(__cdecl*)(WeatherEntry*, WeatherEntry*));
};
// Sorts the WeatherEntry list at this+4 using cmp, then calls BuildMenuEntries.
// @fnv 0x00729fb0
void __thiscall FUN_00729fb0_shell::FUN_00729fb0(int(__cdecl* cmp)(WeatherEntry*, WeatherEntry*))
{
    ((const BSSimpleList_WeatherEntry*)((char*)this + 4))->Sort(cmp);
    BuildMenuEntries();
}

struct WeatherEntry;
struct BSSimpleList
{
    void __thiscall Sort(int(__cdecl*)(WeatherEntry*, WeatherEntry*));
};
struct FUN_0072add0_shell
{
    int m_auiShapeKeys;
    BSSimpleList m_kNode;
    void __thiscall FUN_0072add0(int(__cdecl*)(WeatherEntry*, WeatherEntry*));
};
struct FUN_0072c130_shell
{
    void __thiscall ProcessSlots();
};
// Sorts the list at offset 4 using the given comparator, then calls ProcessSlots on this object.
// @fnv 0x0072add0
void __thiscall FUN_0072add0_shell::FUN_0072add0(int(__cdecl* cmp)(WeatherEntry*, WeatherEntry*))
{
    ((BSSimpleList*)((char*)this + 4))->Sort(cmp);
    ((FUN_0072c130_shell*)this)->ProcessSlots();
}

void __cdecl FUN_0072a890(void*);
struct FUN_0072b9f0_shell
{
    void __thiscall FUN_0072a890();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};
// Calls FUN_0072a890, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x0072b9f0
void* __thiscall FUN_0072b9f0_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_0072a890();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl FUN_0072b2e0(void*);

struct FUN_0072ba20_shell
{
    void __thiscall FUN_0072b2e0();
    void* __thiscall FUN_0072ba20(unsigned int flags);
};

// Calls FUN_0072b2e0, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0072ba20
void* __thiscall FUN_0072ba20_shell::FUN_0072ba20(unsigned int flags)
{
    FUN_0072b2e0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_0072ba50_shell
{
    void* m_vt;
    int m_auiShapeKeys;
    int __thiscall GetFilteredCount(int a);
    void __thiscall FUN_0072ba50();
};
// Calls the virtual function at vtable slot 5 with this and the value returned by GetFilteredCount(0) minus one.
// @fnv 0x0072ba50
void __thiscall FUN_0072ba50_shell::FUN_0072ba50()
{
    ((void(__thiscall*)(void*, int))(*(int**)this)[5])(this, GetFilteredCount(0) - 1);
}

struct Unk_7879c0
{
    virtual ~Unk_7879c0();
};
struct FUN_00724090_shell
{
    ~FUN_00724090_shell();
};
struct ListX
{
    ~ListX();
};
struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
};
extern int DAT_011d9fdc;
struct FUN_00784bf0 : Menu_007a8b10
{
    char m_auiShapeKeys[0x60];
    FUN_00724090_shell m_kPointA;
    char m_pAuxiliaryObject[0x2c];
    Unk_7879c0 m_kPointB;
    char m_pad3[0x2c];
    ListX m_iThirdValue;
    ~FUN_00784bf0();
};
// Destructor that clears the global DAT_011d9fdc flag to 0.
// @fnv 0x00784bf0
FUN_00784bf0::~FUN_00784bf0()
{
    DAT_011d9fdc = 0;
}

struct TGF
{
    float GetFloat(int);
};
int __cdecl GetTileValueID(char const*, int);
struct VATSMenu
{
    int GetSelectedTargetIndex();
};
extern int DAT_011d8f4c;
extern int DAT_011d8f50;
struct FUN_0072bab0_shell
{
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    int m_pad3;
    TGF* m_tile;
    int __thiscall GetFilteredCount();
};
// Returns the VATS menu's count minus the float value read from m_tile for the _num_filtered setting.
// @fnv 0x0072bab0
int __thiscall FUN_0072bab0_shell::GetFilteredCount()
{
    static int numFiltered = GetTileValueID("_num_filtered", -1);
    return ((VATSMenu*)this)->GetSelectedTargetIndex() - (unsigned int)m_tile->GetFloat(numFiltered);
}

struct InterfaceH
{
    static bool __cdecl GetSelectedTargetIndex(int menuID);
};

extern char DAT_011d8ea5;

struct FUN_00728420_shell
{
    virtual void FUN_00728420_v00() = 0;
    virtual void FUN_00728420_v04() = 0;
    virtual void FUN_00728420_v08() = 0;
    virtual void FUN_00728420_v0c(int value1, int value2) = 0;
    virtual void FUN_00728420_v10(int value1, int value2) = 0;

    bool HandleMenuButton(int aiButton, float afValue);
};

// @fnv 0x00728420
bool FUN_00728420_shell::HandleMenuButton(int aiButton, float afValue)
{
    bool bHandled = false;

    if (InterfaceH::GetSelectedTargetIndex(0x435))
    {
        switch (aiButton)
        {
        case 3:
        case 4:
            this->FUN_00728420_v0c((aiButton - 4) ? 2 : 0, 0);
            bHandled = true;
            break;

        case 14:
            this->FUN_00728420_v10(6, 0);
            DAT_011d8ea5 = 1;
            bHandled = true;
            break;

        case 13:
            this->FUN_00728420_v10(3, 0);
            DAT_011d8ea5 = 0;
            bHandled = true;
            break;

        default:
            break;
        }
    }

    return bHandled;
}

int __cdecl FUN_00727920(void* recipe);

struct FUN_00728c10_entry
{
    char m_auiShapeKeys[4];
    void* m_pRecipe;
};

// @fnv 0x00728c10
int __cdecl CompareRecipes(FUN_00728c10_entry* pLeftEntry, FUN_00728c10_entry* pRightEntry)
{
    int leftName;
    char const* leftCanMake;
    int rightCanMake;
    int rightName;
    char const* result;

    leftCanMake = reinterpret_cast<FNStub*>(reinterpret_cast<char*>(pLeftEntry->m_pRecipe) + 0x18)->GetFullName();
    result = reinterpret_cast<FNStub*>(reinterpret_cast<char*>(pRightEntry->m_pRecipe) + 0x18)->GetFullName();
    rightCanMake = 0;
    rightName = FUN_00727920(pLeftEntry->m_pRecipe);
    leftName = FUN_00727920(pRightEntry->m_pRecipe);

    if ((rightName > 0 && leftName > 0) || (rightName <= 0 && leftName <= 0))
    {
        rightCanMake = _mbscmp(reinterpret_cast<unsigned char const*>(leftCanMake),
                               reinterpret_cast<unsigned char const*>(result));
    }
    else if (rightName > 0)
    {
        rightCanMake = -1;
    }
    else if (leftName > 0)
    {
        rightCanMake = 1;
    }
    else
    {
        rightCanMake = _mbscmp(reinterpret_cast<unsigned char const*>(leftCanMake),
                               reinterpret_cast<unsigned char const*>(result));
    }

    return rightCanMake;
}

struct FUN_007240c0
{
    int m_auiShapeKeys;
    FUN_007240c0();
};

FUN_007240c0::FUN_007240c0()
{}

struct SL
{
    int m_iWordAt00;
    int m_iWordAt04;

    SL();
    ~SL();
};

SL::SL()
{}

SL::~SL()
{}

struct TESQuest;
struct Tile;

template <class T> struct ListBox;

template <> struct ListBox<TESQuest*>
{
    void __thiscall SetSelectedTile(Tile* tile, bool selected);
};

extern void* DAT_01070638[];

void __cdecl AddToHeadList(void* ptr);

struct FUN_0072b210 : public FUN_007240c0, public SL
{
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    short m_1c;
    float m_20;
    float m_24;
    float m_28;
    short m_2c;

    FUN_0072b210();
};

// Initialises the object's vtable and zeroes its fields, clears the selected tile, then calls AddToHeadList on this.
// @fnv 0x0072b210
FUN_0072b210::FUN_0072b210()
{
    reinterpret_cast<void**>(this)[0] = DAT_01070638;
    m_14 = 0;
    m_10 = 0;
    m_0c = 0;
    m_18 = 0;
    m_2c = 0;
    m_1c = 0;
    m_28 = 0.0f;
    m_24 = 0.0f;
    m_20 = 0.0f;

    reinterpret_cast<ListBox<TESQuest*>*>(this)->SetSelectedTile((Tile*)0, true);
    AddToHeadList(this);
}

struct Tile
{
    bool __thiscall ContainsTrait(int);
};

struct FUN_0072bc30_shell
{
    int m_auiShapeKeys[3];
    Tile* m_tile;

    bool __thiscall FUN_0072bc30();
};

// Returns true if m_tile is set and its enabled check passes for the cached "_enabled" trait index.
// @fnv 0x0072bc30
bool __thiscall FUN_0072bc30_shell::FUN_0072bc30()
{
    static int trait = GetTileValueID("_enabled", -1);

    return m_tile && m_tile->ContainsTrait(trait);
}

struct GameTimerRecord
{
    unsigned int __thiscall GetTime() const;
};

struct Tile_Set_shell
{
    void __thiscall Set(int value, float position, bool visible);
};

struct FUN_00728a70_shell
{
    void __thiscall FUN_00728a70();
};

void __cdecl FUN_005330e0(float& value, float minimum, float maximum);

extern float DAT_0106f498;
extern float DAT_0106f49c;
extern unsigned char DAT_0119fbf0;
extern unsigned char DAT_011d8ea6;
extern Tile* DAT_011d8eac;
extern Tile* DAT_011d8eb0;
extern float DAT_011d8eb8;
extern unsigned int DAT_011d8ebc;

GameTimerRecord g_timeGlobal;

// @fnv 0x00728a70
void FUN_00728a70_shell::FUN_00728a70()
{
    if ((unsigned char)DAT_011d8ea4 == 1)
        FUN_00728a30(true);

    if (DAT_0119fbf0)
    {
        unsigned int deltaTime;
        unsigned int brightnessValue;
        float stepValue = DAT_0106f49c;
        float currentValue = DAT_0106f498;
        float maximumValue = 0.25f;
        float minimumValue = DAT_011d8eb8;
        float currentTime;

        FUN_005330e0(minimumValue, 0.0f, 255.0f);
        currentTime = 255.0 - minimumValue;
        FUN_005330e0(currentTime, 0.0f, 255.0f);

        if (DAT_011d8eb0 != 0 && DAT_011d8eac != 0)
        {
            reinterpret_cast<Tile_Set_shell*>(DAT_011d8eb0)->Set(4009, currentTime, true);
            reinterpret_cast<Tile_Set_shell*>(DAT_011d8eac)->Set(4009, minimumValue, true);
        }

        deltaTime = g_timeGlobal.GetTime();
        brightnessValue = deltaTime - DAT_011d8ebc;
        DAT_011d8ebc = deltaTime;

        if (DAT_011d8ea6)
            DAT_011d8eb8 -= brightnessValue * maximumValue;
        else
            DAT_011d8eb8 += brightnessValue * maximumValue;

        FUN_005330e0(DAT_011d8eb8, currentValue, stepValue);

        if (DAT_011d8eb8 >= stepValue)
            DAT_011d8ea6 = 1;
        if (DAT_011d8eb8 <= currentValue)
            DAT_011d8ea6 = 0;
    }
}

struct RecipeBase_b4821
{
    virtual ~RecipeBase_b4821();
};

struct SubA_b4821
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
    ~SubA_b4821();
};

struct SubB_b4821
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
    ~SubB_b4821();
};

struct SubC_b4821
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ~SubC_b4821();
};

struct GlobalHolder_b4821
{
    void FUN_0046fb20();
};

extern GlobalHolder_b4821* DAT_011c3f2c;
extern int DAT_011d8e90;

struct FUN_00726f50_cls : RecipeBase_b4821
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
    SubA_b4821 m_6c;
    SubB_b4821 m_a0;
    SubC_b4821 m_d0;
    virtual ~FUN_00726f50_cls();
};

// Calls FUN_0046fb20 on DAT_011c3f2c and sets DAT_011d8e90 to 0 during destruction.
// @fnv 0x00726f50
FUN_00726f50_cls::~FUN_00726f50_cls()
{
    DAT_011c3f2c->FUN_0046fb20();
    DAT_011d8e90 = 0;
}

struct FNVVirtualTarget
{
    bool(__thiscall** vtable)(FNVVirtualTarget*, int);
};
struct FNVAuxController
{
    FNVVirtualTarget* FUN_008d8520();
    void FUN_00950030();
};
extern FNVAuxController* DAT_011dea3c;
extern int DAT_011d8e90;
struct FNVMenuAction
{
    void FUN_00700320(int id, int value);
};
struct FNVRecipeMenu
{
    int field00;
    FNVMenuAction* action;
    void FUN_00a1d910();
};
void __cdecl StartDialogueForTopic(int value);

// @fnv 0x00727430
void __cdecl FUN_00727430()
{
    if (DAT_011d8e90 != 0)
    {
        FNVVirtualTarget* target = DAT_011dea3c->FUN_008d8520();
        if (target->vtable[0x474 / 4](target, 1))
        {
            DAT_011dea3c->FUN_00950030();
        }

        int value = 0;
        StartDialogueForTopic(value);
        ((FNVRecipeMenu*)DAT_011d8e90)->action->FUN_00700320(0x1772, 1);
        ((FNVRecipeMenu*)DAT_011d8e90)->FUN_00a1d910();
    }
}

extern char DAT_010705d4;

struct FUN_007299a0 : FUN_007240c0, SL
{
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    short m_1c;
    float m_20;
    float m_24;
    float m_28;
    short m_2c;

    FUN_007299a0();
    void FUN_007a1950(int a, int b);
};

// Initializes the object's vtable pointer and zeroes its integer, short and float members, then calls FUN_007a1950(0, 1) and AddToHeadList.
// @fnv 0x007299a0
FUN_007299a0::FUN_007299a0()
{
    *(void**)this = &DAT_010705d4;
    this->m_14 = 0;
    this->m_10 = 0;
    this->m_0c = 0;
    this->m_18 = 0;
    this->m_2c = 0;
    this->m_1c = 0;
    this->m_28 = 0.0f;
    this->m_24 = 0.0f;
    this->m_20 = 0.0f;
    this->FUN_007a1950(0, 1);
    AddToHeadList(this);
}

struct RecipeEntry;
struct MenuNode
{
    MenuNode* FUN_00a03c90(MenuNode* context, int choice, int flags);
    RecipeEntry* AddTileFromTemplate();
    int FUN_00a00f30(int key);
    void FUN_00700320(int key, int value);
    void FUN_00a01350(int key, int value, int flags);
    float FUN_00a011b0(int index);
    MenuNode* FindTraitValue(int key);
    void RemoveFromReactions();
    void FUN_00a09130(int property, RecipeEntry* source, int key);
    void AppendFloatAction(int property, float value);
    void Refresh(int flags);
};

struct RecipeEntry
{
    int m_iResultCode;
    int m_item;
    int m_data;
    RecipeEntry(RecipeEntry* parent, int* selection);
    int FUN_00a00f30(int key);
    void FUN_00700320(int key, int value);
    void FUN_00a01350(int key, int value, int flags);
};

struct RecipeList
{
    int m_pHeadNode;
    int m_last;
    void FUN_007a7eb0(RecipeEntry* recipe, int aiRecipeIndex);
    void FUN_00905820(RecipeEntry* const& recipe);
};

extern "C" double DAT_01012060;
extern "C" char UNK_0106f860;
int __cdecl TraitNameToIDAdd(const void* key, int fallback);

struct RecipePanel
{
    int m_iValueAtOffset0C;
    RecipeList m_recipes;
    MenuNode* m_parent;
    int m_unused10;
    int m_unused14;
    int m_defaultItem;
    unsigned short m_nextIndex;
    unsigned short m_flags;
    int m_updateCounter;
    int m_uiContentCount;
    int m_lastAction;

    bool FUN_007242c0(int flags);
    void BuildMenuEntries();
    void AccumulateTileHeight(RecipeEntry* recipe);
    void FUN_0072c000();
    int GetRaceCount();
    RecipeEntry* FUN_00729ae0(int selection, int updateChoice, int aiRecipeIndex, int parentId);
};

// @fnv 0x00729ae0
RecipeEntry* RecipePanel::FUN_00729ae0(int selection, int updateChoice, int aiRecipeIndex, int parentId)
{
    if (m_parent != 0 && (m_defaultItem != 0 || parentId != 0))
    {
        RecipeEntry* current =
            m_parent->FUN_00a03c90(m_parent, parentId != 0 ? parentId : m_defaultItem, 0)->AddTileFromTemplate();
        if (!current->FUN_00a00f30(0xfaa))
            current->FUN_00700320(0xfaa, -1);
        if (updateChoice != 0)
            current->FUN_00a01350(0xfc4, updateChoice, 1);

        if (aiRecipeIndex != 0)
        {
            m_recipes.FUN_007a7eb0(new RecipeEntry(current, &selection), aiRecipeIndex);
            if (FUN_007242c0(0))
                BuildMenuEntries();
        }
        else
        {
            m_recipes.FUN_00905820(new RecipeEntry(current, &selection));
            if (FUN_007242c0(0))
            {
                AccumulateTileHeight(current);
                FUN_0072c000();
            }
            current->FUN_00700320(0xfac, m_nextIndex++);
        }

        if (GetRaceCount() == 1)
        {
            if (m_parent->FUN_00a011b0(TraitNameToIDAdd(&UNK_0106f860, -1)) > DAT_01012060)
            {
                MenuNode* notifier = m_parent->FindTraitValue(0xfb0);
                notifier->RemoveFromReactions();
                notifier->FUN_00a09130(0x7d0, current, 0xfb0);
                notifier->AppendFloatAction(0x7d3, m_parent->FUN_00a011b0(TraitNameToIDAdd(&UNK_0106f860, -1)));
                notifier->Refresh(0);
            }
        }
        return current;
    }
    else
    {
        return 0;
    }
}

struct Item
{
    bool __thiscall IsTraitNonZero(int);
};
extern int UNK_01070244;
int __cdecl TraitNameToIDAdd(int*, int);

struct Object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Item* current;
    bool __thiscall FUN_0072bc30();
    bool __thiscall ContainsKey(Item*);
    void __thiscall RefreshHighlight();
    bool __thiscall SetCurrentItem(Item* input);
};

// If the object is ready and the input passes the checks, stores input as current, calls RefreshHighlight and returns true; otherwise returns false.
// @fnv 0x0072a250
bool __thiscall Object::SetCurrentItem(Item* pItem)
{
    if (FUN_0072bc30() && (!pItem || (ContainsKey(pItem) && pItem->IsTraitNonZero(TraitNameToIDAdd(&UNK_01070244, -1)))))
    {
        current = pItem;
        RefreshHighlight();
        return true;
    }
    else
    {
        return false;
    }
}

extern void* DAT_01070610[];
void __cdecl AddToHeadList(void*);

struct FUN_0072a7c0 : FUN_007240c0, SL
{
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    short m_1c;
    float m_20;
    float m_24;
    float m_28;
    short m_2c;

    void FUN_007a1950(int, int);
    FUN_0072a7c0();
};

// @fnv 0x0072a7c0
FUN_0072a7c0::FUN_0072a7c0() : FUN_007240c0(), SL()
{
    m_auiShapeKeys = reinterpret_cast<int>(DAT_01070610);
    m_14 = 0;
    m_10 = 0;
    m_0c = 0;
    m_18 = 0;
    m_2c = 0;
    m_1c = 0;
    m_28 = 0.0f;
    m_24 = 0.0f;
    m_20 = 0.0f;
    FUN_007a1950(0, 1);
    AddToHeadList(this);
}

struct Member_72a890
{
    ~Member_72a890();
    int unk00;
};

void __cdecl FUN_007211c0(void* obj);

class FUN_0072a890_cls
{
  public:
    virtual ~FUN_0072a890_cls();
    Member_72a890 m_04;
    void ClearItems();
};

// Destructor that calls ClearItems, then passes this to FUN_007211c0.
// @fnv 0x0072a890
FUN_0072a890_cls::~FUN_0072a890_cls()
{
    ClearItems();
    FUN_007211c0(this);
}

extern "C" char DAT_01070244;
extern "C" void* __cdecl TraitNameToIDAdd(const char* name, int lookupMode);

struct SelectedOption
{
    bool IsTraitNonZero(void* item);
};

struct SelectionManager
{
    void* vtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    SelectedOption* selectedOption;

    bool FUN_0072c7d0();
    bool ContainsKey(SelectedOption* option);
    void FUN_0072c880();
    bool FUN_0072b5b0(SelectedOption* option);
};

// @fnv 0x0072b5b0
bool SelectionManager::FUN_0072b5b0(SelectedOption* option)
{
    if (FUN_0072c7d0() && (!option || (ContainsKey(option) && option->IsTraitNonZero(TraitNameToIDAdd(&DAT_01070244, -1)))))
    {
        selectedOption = option;
        FUN_0072c880();
        return true;
    }
    else
    {
        return false;
    }
}

struct MenuEntryItem
{
    void __thiscall FUN_00700320(int action, unsigned int index);
};
struct MenuEntry
{
    MenuEntryItem* m_item;
    int m_unknown04;
    unsigned char m_disabled;
};
struct EntryNode
{
    int m_data;
    int m_next;
    MenuEntry** __thiscall FUN_006815c0();
    EntryNode* __thiscall FUN_00726070();
};
struct MenuBody
{
    int m_kHeader;
    EntryNode m_entries;
    int m_unknown0c;
    int m_unknown10;
    int m_unknown14;
    int m_unknown18;
    unsigned short m_uiItemCount;
    unsigned short m_unknown1e;
    float m_uiFilterValue;
    void __thiscall AccumulateTileHeight(MenuEntryItem*);
    void __thiscall FUN_0072c000();
    void __thiscall RefreshHighlight();
};
// Resets the entry count and value, then for each enabled entry assigns an action and index, adds its item, and calls the two finalize methods.
// @fnv 0x0072bb60
void __thiscall FUN_00729fb0_shell::BuildMenuEntries()
{
    ((MenuBody*)this)->m_uiItemCount = 0;
    ((MenuBody*)this)->m_uiFilterValue = 0.0f;
    for (EntryNode* pNode = this != 0 ? &((MenuBody*)this)->m_entries : 0; pNode != 0 && *pNode->FUN_006815c0() != 0;
         pNode = pNode->FUN_00726070())
    {
        if ((*pNode->FUN_006815c0())->m_disabled == 0)
        {
            (*pNode->FUN_006815c0())->m_item->FUN_00700320(0xfac, ((MenuBody*)this)->m_uiItemCount++);
            ((MenuBody*)this)->AccumulateTileHeight((*pNode->FUN_006815c0())->m_item);
        }
    }
    ((MenuBody*)this)->FUN_0072c000();
    ((MenuBody*)this)->RefreshHighlight();
}

struct Target_b9223
{
    void Call(int a, int b);
};

struct Inner_b9223
{
    int m_00;
    int m_04;
    unsigned char m_08;
};

struct Node_b9223
{
    Node_b9223* Next();
    Inner_b9223** Slot();
};

struct FUN_0072c130_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_1c;
    float m_20;

    void Log(int v);
    void Finish1();
    void Finish2();
    void ProcessSlots();
};

// Resets m_1c and m_20, walks the node list calling Call(0xfac, m_1c++) and Log on each slot with m_08 == 0, then calls Finish1 and Finish2.
// @fnv 0x0072c130
void FUN_0072c130_cls::ProcessSlots()
{
    m_1c = 0;
    m_20 = 0.0f;
    for (Node_b9223* cur = this ? (Node_b9223*)&unk04 : 0; cur != 0 && *cur->Slot() != 0; cur = cur->Next())
    {
        if ((*cur->Slot())->m_08 == 0)
        {
            ((Target_b9223*)(*cur->Slot())->m_00)->Call(0xfac, m_1c++);
            Log((*cur->Slot())->m_00);
        }
    }
    Finish1();
    Finish2();
}

namespace fnv_0072c200 {
extern const char DAT_01070244[];
extern void* __cdecl TraitNameToIDAdd(const char* name, int fallback);

struct TileValueChecker
{
    bool IsTraitNonZero(void* value);
};

struct MenuTileControl
{
    int menuID;
    int state;
    int selected;
    TileValueChecker* tile;

    bool FUN_0072c200();
};

// Returns true if tile is non-null and its checker accepts the cached value obtained from TraitNameToIDAdd.
// @fnv 0x0072c200
bool MenuTileControl::FUN_0072c200()
{
    static void* cachedValue = TraitNameToIDAdd(DAT_01070244, -1);
    return tile != 0 && tile->IsTraitNonZero(cachedValue);
}
}  // namespace fnv_0072c200

struct TileStub
{
    float GetValueFloat(int id);
    void SetFloat(int id, float value, bool propagate);
    void SetInt(int id, int value);
};

float __cdecl CeilF(float x);
int __cdecl MaxI(int a, int b);
int __cdecl TraitID(const char* name);

struct ScrollBarHelper
{
    int unk00;
    int unk04;
    int unk08;
    TileStub* m_tile;
    int unk10;
    TileStub* m_countTile;
    int unk18;
    int unk1c;
    float m_height;

    unsigned int GetItemCount();
    void FUN_0072c5d0();
};

float __cdecl CeilF(float x);
int __cdecl MaxI(int a, int b);
int __cdecl TraitID(const char* name);

// Computes the scroll step from the tile's visible value and m_height, sets the _scroll_delta float and the _number_of_items count on the tiles.
// @fnv 0x0072c5d0
void ScrollBarHelper::FUN_0072c5d0()
{
    if (m_tile)
    {
        float visibleVal = m_tile->GetValueFloat(0xfb0);
        int count = 1;
        if (m_height > 0 && visibleVal > 0)
        {
            if (m_height > visibleVal)
            {
                count = MaxI((int)CeilF(GetItemCount() * (m_height - visibleVal) / m_height) + 1, 2);
            }
            if (count > 1)
            {
                m_tile->SetFloat(TraitID("_scroll_delta"), (m_height - visibleVal) / (count - 1), true);
            }
        }
        if (m_countTile)
        {
            m_countTile->SetInt(TraitID("_number_of_items"), count);
        }
    }
}

namespace fnv_0072c7d0 {
extern "C" const char kListBoxEnabled[];

int __cdecl TraitNameToIDAdd(const char* pcTrait, int iIndex);

class B2C7D0Tile
{
  public:
    bool GetBool(int m_iValueId);
};

class B2C7D0Menu
{
  public:
    int unk00;
    int unk04;
    int unk08;
    B2C7D0Tile* m_pkTile;
    bool FUN_0072c7d0();
};

// Returns true when m_pkTile exists and its GetBool returns true for the cached list-box-enabled trait index.
// @fnv 0x0072c7d0
bool B2C7D0Menu::FUN_0072c7d0()
{
    static int s_iEnabled = TraitNameToIDAdd(kListBoxEnabled, -1);
    return m_pkTile && m_pkTile->GetBool(s_iEnabled);
}
}  // namespace fnv_0072c7d0

int __cdecl CMSprintf(char* apBuffer, int aiSize, const char* apFormat, ...);

struct CMForm;
struct CMTile
{
    void SetInt(int aiID, int aiValue);
};

struct CMTileRef
{
    CMTile** Get();
};

struct CMItem
{
    int unk00;
    CMTileRef kTile;
};

struct CMConditions
{
    bool Evaluate(int aiRef, int aiUnk);
};

struct CMCounter
{
    unsigned int GetCount();
};

struct CMCounterList
{
    CMCounter** GetFirst();
};

struct CMFullName
{
    const char* GetName();
};

struct CMChallenge
{
    int unk00[6];
    CMFullName kFullName;

    int GetChallengeType();
    CMConditions* GetConditions();
    CMForm* GetForm();
    CMCounterList* GetCounters();
};

struct CMChallengeList
{
    CMChallenge* pItem;
    CMChallengeList* pNext;

    bool IsEmpty();
    CMChallenge** GetItem();
    CMChallengeList* GetNext();
};

struct CMDataHandler
{
    CMChallengeList* GetChallengeList();
};

struct CMPlayer
{
    int unk00[0x18];
    int iRef60;
};

struct CMFormArray
{
    unsigned int Find(CMForm*& arItem, unsigned int auiStart,
                      bool(__cdecl* apfnCompare)(CMForm* const&, CMForm* const&));
    unsigned int GetSize();
    unsigned int Add(CMForm*& arItem);
};

struct CMListBox
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void Sort(int(__cdecl* apfnCompare)(void*, void*));

    CMItem* Insert(CMChallenge* apChallenge, const char* apText, int aiUnk1, int aiUnk2);
};

struct CMSorter
{
    void Sort(int(__cdecl* apfnCompare)(void*, void*));
};

bool __cdecl CMCompareForms(CMForm* const& arA, CMForm* const& arB);
int __cdecl CMCompareItems(void* apA, void* apB);
int __cdecl CMCompareEntries(void* apA, void* apB);
CMFormArray* __cdecl CMGetFormArray();
int __cdecl CMIsChallengeDone(CMChallenge* apChallenge);

extern CMDataHandler* g_pCMDataHandler;
extern CMPlayer* g_pCMPlayer;
extern CMSorter g_kCMSorter;

struct CMMenu
{
    int unk00[0x1b];
    CMListBox kList;

    void PopulateChallengeList(int aiUnused, int aiType);
};

// @fnv 0x00727680
void CMMenu::PopulateChallengeList(int aiUnused, int aiType)
{
    int iType8;
    CMChallengeList* pIter6;
    CMChallenge* pChallenge6;
    int iCount8;
    int iChallengeType2;
    CMForm* pForm4;
    CMItem* pItem;
    char cBuffer[256];

    iType8 = aiType;
    pIter6 = g_pCMDataHandler->GetChallengeList();
    pChallenge6 = 0;
    iCount8 = 0;
    while (pIter6 && !pIter6->IsEmpty())
    {
        pChallenge6 = *pIter6->GetItem();
        pIter6 = pIter6->GetNext();
        iChallengeType2 = pChallenge6->GetChallengeType();
        if (iType8 && iType8 != iChallengeType2)
            continue;
        if (pChallenge6->GetConditions()->Evaluate(g_pCMPlayer->iRef60, 0))
        {
            pForm4 = pChallenge6->GetForm();
            if (pForm4 && CMGetFormArray()->Find(pForm4, 0, CMCompareForms) >= CMGetFormArray()->GetSize())
            {
                CMGetFormArray()->Add(pForm4);
                iCount8++;
            }
            if (*pChallenge6->GetCounters()->GetFirst() && (*pChallenge6->GetCounters()->GetFirst())->GetCount() > 1)
                CMSprintf(cBuffer, 256, "%s (%d)", pChallenge6->kFullName.GetName(),
                          (*pChallenge6->GetCounters()->GetFirst())->GetCount());
            else
                CMSprintf(cBuffer, 256, "%s", pChallenge6->kFullName.GetName());
            pItem = kList.Insert(pChallenge6, cBuffer, 0, 0);
            if (!CMIsChallengeDone(pChallenge6))
                (*pItem->kTile.Get())->SetInt(0xfa9, 0x7f);
            else
                (*pItem->kTile.Get())->SetInt(0xfa9, 0xff);
        }
    }
    kList.Sort(CMCompareItems);
    g_kCMSorter.Sort(CMCompareEntries);
}

extern char DAT_010705d4;

struct FUN_00729d80_shell
{
    void __thiscall ClearList();
};

struct FUN_00729a70
{
    ListX m_kNode;
    virtual ~FUN_00729a70();
};

// @fnv 0x00729a70
FUN_00729a70::~FUN_00729a70()
{
    ((FUN_00729d80_shell*)this)->ClearList();
    FUN_007211c0(this);
}

struct OwnedItem49
{
    virtual ~OwnedItem49();
};
struct FUN_004459e0
{
    ~FUN_004459e0();
};
struct Pair49
{
    OwnedItem49* item;
    FUN_004459e0* extra;
};
struct FUN_004702f0
{
    Pair49** FUN_006815c0();
    FUN_004702f0* FUN_00726070();
    void FUN_006ecd40(int);
    ~FUN_004702f0();
};
struct Tile49
{
    void FUN_00a012d0(int, float, bool);
};
extern unsigned char DAT_011d8909;
extern char DAT_0106f8d0;
int __cdecl TraitNameToID(const char*);
struct List49
{
    int context;
    Pair49* first;
    FUN_004702f0* nodes;
    Tile49* tile;
    int selected;
    int field14;
    int field18;
    unsigned short count;
    unsigned short field1e;
    float value;
    bool FUN_007242c0(int);
    void FUN_0072c000();
    void RefreshHighlight();
    void ClearList();
};
// @fnv 0x00729d80
void List49::ClearList()
{
    while (nodes && *nodes->FUN_006815c0())
    {
        FUN_004702f0* next = nodes->FUN_00726070();
        if (!DAT_011d8909)
            delete (*nodes->FUN_006815c0())->item;
        if (FUN_007242c0(1))
            delete (*nodes->FUN_006815c0())->extra;
        delete *nodes->FUN_006815c0();
        nodes->FUN_006ecd40(0);
        delete nodes;
        nodes = next;
    }
    if (first)
    {
        if (!DAT_011d8909)
            delete first->item;
        if (FUN_007242c0(1))
            delete first->extra;
        delete first;
    }
    first = 0;
    count = 0;
    value = 0.0f;
    if (tile)
        tile->FUN_00a012d0(TraitNameToID(&DAT_0106f8d0), 0.0f, true);
    FUN_0072c000();
    selected = 0;
    RefreshHighlight();
}

struct LBTile
{
    float GetFloat(int aiTrait);
    void SetInt(int aiTrait, int aiValue);
    void SetUInt(int aiTrait, unsigned int auiValue);
};

int __cdecl LBTraitNameToID(const char* apName, int aiDefault);

struct LBItem
{
    LBTile* pTile;
    void* pObject;
    bool m_bFiltered;
};

struct LBList
{
    LBItem* pItem;
    LBList* pNext;

    LBItem*& Item();
    LBList* GetNext();
};

struct LBBase
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual LBTile* GetTileByIndex(int aiIndex, bool abFlag);
};

struct LBListBox : LBBase, LBList
{
    LBTile* pParentTile;
    LBTile* pSelected;
    int unk14;
    int unk18;
    unsigned short usItemCount;
    float fScroll;

    void AddTile(LBTile* apTile);
    void FUN_0072c000();
    LBTile* FUN_0072ba50();
    void RefreshHighlight();
    void ApplyFilter(bool(__cdecl* apFilter)(void*));
};

// Marks each item by apFilter, rebuilds the tile list and item count, updates the _num_filtered trait, and restores the selected tile.
// @fnv 0x00729fe0
void LBListBox::ApplyFilter(bool(__cdecl* apFilter)(void*))
{
    int iNumFiltered = 0;
    int iSelectedIndex = -1;
    static int s_iNumFilteredTrait = LBTraitNameToID("_num_filtered", -1);

    usItemCount = 0;
    fScroll = 0.0f;
    for (LBList* pIter = this; pIter && pIter->Item(); pIter = pIter->GetNext())
    {
        pIter->Item()->m_bFiltered = apFilter && apFilter(pIter->Item()->pObject);
        if (pIter->Item()->m_bFiltered)
        {
            if (pIter->Item()->pTile == pSelected)
            {
                iSelectedIndex = pIter->Item()->pTile->GetFloat(0xfac);
                pSelected = 0;
            }
            pIter->Item()->pTile->SetInt(0xfac, -1);
            iNumFiltered++;
        }
        else
        {
            if (iSelectedIndex >= 0 && usItemCount == iSelectedIndex)
                pSelected = pIter->Item()->pTile;
            pIter->Item()->pTile->SetInt(0xfac, usItemCount++);
            AddTile(pIter->Item()->pTile);
        }
    }

    pParentTile->SetUInt(s_iNumFilteredTrait, iNumFiltered);
    FUN_0072c000();
    if (!pSelected && iSelectedIndex >= 0)
        pSelected = GetTileByIndex(iSelectedIndex, false);
    if (!pSelected && iSelectedIndex >= 0)
        pSelected = FUN_0072ba50();
    RefreshHighlight();
}

struct TileX
{
    float GetValueFloat(int id);
    bool GetValueBool(int id);
};
int TraitNameToID(char const* name);
int __cdecl TraitNameToIDX(char const* name, int def);
float __cdecl ClampScroll(float value, float minv);

struct ListItemX
{
    TileX* tile;
};
struct ListNodeX
{
    ListItemX* m_item;
    ListNodeX* m_next;
    ListNodeX* NextNode();
    ListItemX*& ItemRef();
};
struct ListBoxBaseX
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual TileX* GetTileByIndex(int index, bool flag);
};
struct ListBoxX : ListBoxBaseX, ListNodeX
{
    TileX* m_0c;
    TileX* m_10;
    int m_14;
    int m_18;
    unsigned short m_1c;

    bool IsActiveX();
    TileX* GetNextEnabledTile(int aiKey);
};

// @fnv 0x0072a2c0
TileX* ListBoxX::GetNextEnabledTile(int aiKey)
{
    TileX* result2 = 0;
    int delta8 = 0;
    switch (aiKey)
    {
    case 2:
        delta8 = 1;
        break;
    case 1:
        delta8 = -1;
        break;
    case 15:
        delta8 = m_0c ? (int)ClampScroll(
                            -m_0c->GetValueFloat(0xfb0) / m_0c->GetValueFloat(TraitNameToID("_scroll_delta")), 1.0f)
                      : 0;
        break;
    case 16:
        delta8 = m_0c ? (int)ClampScroll(
                            m_0c->GetValueFloat(0xfb0) / m_0c->GetValueFloat(TraitNameToID("_scroll_delta")), 1.0f)
                      : 0;
        break;
    }
    if (IsActiveX() && delta8 && m_1c)
    {
        int idxTmp;
        int aMaxIdx = m_1c - 1;
        if (m_10)
        {
            int cur = (int)m_10->GetValueFloat(0xfac);
            if ((idxTmp = cur + delta8) < 0)
                idxTmp = 0;
            else if (idxTmp > aMaxIdx)
                idxTmp = aMaxIdx;
        }
        else if (delta8 > 0)
        {
            idxTmp = 0;
        }
        else
        {
            idxTmp = aMaxIdx;
        }
        while (1)
        {
            ListNodeX* node;
            for (node = this; !result2 && node && node->ItemRef(); node = node->NextNode())
            {
                if (node->ItemRef()->tile->GetValueFloat(0xfac) == idxTmp)
                    result2 = node->ItemRef()->tile;
            }
            if (result2 && !result2->GetValueBool(TraitNameToIDX("_enabled", -1)))
            {
                result2 = 0;
                if (delta8 > 0 && ++idxTmp > aMaxIdx)
                {
                    idxTmp = aMaxIdx - 1;
                    while ((!result2 || !result2->GetValueBool(TraitNameToIDX("_enabled", -1))) && idxTmp >= 0)
                        result2 = GetTileByIndex(idxTmp--, false);
                    break;
                }
                else if (delta8 < 0 && --idxTmp < 0)
                {
                    idxTmp = 1;
                    while ((!result2 || !result2->GetValueBool(TraitNameToIDX("_enabled", -1))) && idxTmp <= aMaxIdx)
                        result2 = GetTileByIndex(idxTmp++, false);
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    return result2 != m_10 ? result2 : 0;
}

struct SelectionTile;
struct SelectionMenu
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void HandleClick(int, SelectionTile*);
};
struct SelectionMenuLink
{
    SelectionMenu* FUN_00a03c90();
};
struct SelectionTile
{
    void FUN_00a012d0(int, float, bool);
    void SetTraitAndReset(int, float);
    float FUN_00a011b0(int);
    SelectionMenuLink* FUN_00a03d40();
};
struct SelectionInterface
{
    void FUN_00715860(SelectionTile*, int, bool);
};
SelectionInterface* FUN_004b7210();
bool FUN_004b71d0();
int TraitNameToID(const char*);
float FUN_0040ebd0(float, float);
struct SelectionList
{
    virtual void SetSelected(SelectionTile*);
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual SelectionTile* GetTile(unsigned int);
    int unk04;
    int unk08;
    SelectionTile* container;
    int unk10;
    SelectionTile* scrollBar;
    int unk18;
    short unk1c;
    short unk1e;
    float unk20;
    float storedIndex;
    float storedScroll;
    unsigned int GetFilteredCount(int);
    void UpdateSelection(bool);
};
// Updates the scroll bar value, selects the tile at the stored index, notifies the interface, and handles a click when not in a certain state.
// @fnv 0x0072a660
void SelectionList::UpdateSelection(bool abNotify)
{
    SelectionTile* selected = 0;
    if (container && scrollBar)
    {
        scrollBar->FUN_00a012d0(TraitNameToID("_current_value"), storedScroll, false);
        scrollBar->SetTraitAndReset(TraitNameToID("_SetInCode"), 1.0f);
        selected = GetTile((unsigned int)FUN_0040ebd0(storedIndex, (float)(GetFilteredCount(0) - 1.0)));
        FUN_004b7210()->FUN_00715860(selected, 0xfc3, abNotify);
        SetSelected(selected);
        if (!FUN_004b71d0())
        {
            if (selected)
            {

                container->FUN_00a03d40()->FUN_00a03c90()->HandleClick((int)selected->FUN_00a011b0(0xfaa), selected);
            }
            SetSelected(0);
        }
    }
}

struct FUN_007a62e0
{
    int m_iResultCode;
    int m_item;
    int m_data;
    FUN_007a62e0(RecipeEntry*, int*);
};
struct EntryList515
{
    int first;
    int last;
    void FUN_007a7eb0(FUN_007a62e0*, int);
    void FUN_00905820(FUN_007a62e0* const&);
};
struct Panel515
{
    int context;
    EntryList515 entries;
    MenuNode* parent;
    int unknown10;
    int unknown14;
    int defaultItem;
    unsigned short nextIndex;
    unsigned short flags;
    bool FUN_007242c0(int);
    void ProcessSlots();
    void AccumulateTileHeight(RecipeEntry*);
    void FUN_0072c5d0();
    int GetRaceCount();
    RecipeEntry* FUN_0072a900(int selection, int choice, int aiRecipeIndex, int parentId);
};
// @fnv 0x0072a900
RecipeEntry* Panel515::FUN_0072a900(int selection, int choice, int aiRecipeIndex, int parentId)
{
    if (parent && (defaultItem || parentId))
    {
        RecipeEntry* entry = parent->FUN_00a03c90(parent, parentId ? parentId : defaultItem, 0)->AddTileFromTemplate();
        if (!entry->FUN_00a00f30(0xfaa))
            entry->FUN_00700320(0xfaa, -1);
        if (choice)
            entry->FUN_00a01350(0xfc4, choice, 1);
        if (aiRecipeIndex)
        {
            entries.FUN_007a7eb0(new FUN_007a62e0(entry, &selection), aiRecipeIndex);
            if (FUN_007242c0(0))
                ProcessSlots();
        }
        else
        {
            entries.FUN_00905820(new FUN_007a62e0(entry, &selection));
            if (FUN_007242c0(0))
            {
                AccumulateTileHeight(entry);
                FUN_0072c5d0();
            }
            entry->FUN_00700320(0xfac, nextIndex++);
        }
        if (GetRaceCount() == 1 && parent->FUN_00a011b0((int)TraitNameToIDAdd(&UNK_0106f860, -1)) > DAT_01012060)
        {
            MenuNode* tile = parent->FindTraitValue(0xfb0);
            tile->RemoveFromReactions();
            tile->FUN_00a09130(0x7d0, entry, 0xfb0);
            tile->AppendFloatAction(0x7d3, parent->FUN_00a011b0((int)TraitNameToIDAdd(&UNK_0106f860, -1)));
            tile->Refresh(0);
        }
        return entry;
    }
    else
        return 0;
}

struct ListValue
{
    virtual ~ListValue();
};
struct ListTile
{
    ~ListTile();
    void FUN_00a012d0(int property, float value, bool propagate);
};
struct ListItem
{
    ListValue* value;
    ListTile* tile;
};
struct ListItemNode
{
    ListItem* item;
    ListItemNode* next;
    ListItem** FUN_006815c0();
    ListItemNode* FUN_00726070();
    void FUN_006ecd40(ListItem* item);
    ~ListItemNode();
};
extern bool _s_bAllowDetach;
int __cdecl TraitNameToID(const char* name);
struct ListPanel
{
    void* vtable;
    ListItem* head;
    ListItemNode* next;
    ListTile* tile;
    int selection;
    int unk14;
    int unk18;
    unsigned short count;
    unsigned short flags;
    float position;
    bool FUN_007242c0(unsigned int flags);
    void FUN_0072c5d0();
    void FUN_0072c2b0();
    void ClearItems();
};
// @fnv 0x0072aba0
void ListPanel::ClearItems()
{
    while (next && *next->FUN_006815c0())
    {
        ListItemNode* following = next->FUN_00726070();
        if (!_s_bAllowDetach)
            delete (*next->FUN_006815c0())->value;
        if (FUN_007242c0(1))
            delete (*next->FUN_006815c0())->tile;
        delete *next->FUN_006815c0();
        next->FUN_006ecd40(0);
        delete next;
        next = following;
    }
    if (head)
    {
        if (!_s_bAllowDetach)
            delete head->value;
        if (FUN_007242c0(1))
            delete head->tile;
        delete head;
    }
    head = 0;
    count = 0;
    position = 0.0f;
    if (tile)
        tile->FUN_00a012d0(TraitNameToID("_num_filtered"), 0.0f, true);
    FUN_0072c5d0();
    selection = 0;
    FUN_0072c2b0();
}

int __cdecl TraitNameToID(const char* name);
float __cdecl FUN_004bd510(float value, float unit);
struct NavigationItem : MenuNode
{
    bool IsTraitNonZero(int property);
};
struct NavigationEntry
{
    NavigationItem* item;
};
struct NavigationNode
{
    NavigationEntry* entry;
    NavigationNode* next;
    NavigationEntry** FUN_006815c0();
    NavigationNode* FUN_00726070();
};
struct NavigationList
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual NavigationItem* FindItem(int last, int flags);
    NavigationNode entries;
    MenuNode* scrollTile;
    NavigationItem* current;
    int unknown14;
    int unknown18;
    unsigned short count;
    bool FUN_0072c200();
    NavigationItem* GetNextItem(int action);
};
// @fnv 0x0072ae70
NavigationItem* NavigationList::GetNextItem(int action)
{
    NavigationItem* selected = 0;
    int step = 0;
    switch (action)
    {
    case 2:
        step = 1;
        break;
    case 1:
        step = -1;
        break;
    case 15:
        step = scrollTile ? (int)FUN_004bd510(-scrollTile->FUN_00a011b0(0xfb0) /
                                                  scrollTile->FUN_00a011b0(TraitNameToID("_scroll_delta")),
                                              1.0f)
                          : 0;
        break;
    case 16:
        step = scrollTile ? (int)FUN_004bd510(scrollTile->FUN_00a011b0(0xfb0) /
                                                  scrollTile->FUN_00a011b0(TraitNameToID("_scroll_delta")),
                                              1.0f)
                          : 0;
        break;
    }
    if (FUN_0072c200() && step && count)
    {
        int index = count - 1;
        int last;
        if (current)
        {
            int previous = (int)current->FUN_00a011b0(0xfac);
            if ((last = previous + step) < 0)
                last = 0;
            else if (last > index)
                last = index;
        }
        else
        {
            if (step > 0)
                last = 0;
            else
                last = index;
        }
        while (true)
        {
            for (NavigationNode* node = this ? &entries : 0; !selected && node && *node->FUN_006815c0();
                 node = node->FUN_00726070())
            {
                if ((*node->FUN_006815c0())->item->FUN_00a011b0(0xfac) == last)
                    selected = (*node->FUN_006815c0())->item;
            }
            if (selected && !selected->IsTraitNonZero(TraitNameToIDAdd(&UNK_01070244, -1)))
            {
                selected = 0;
                if (step > 0 && ++last > index)
                {
                    last = index - 1;
                    while ((!selected || !selected->IsTraitNonZero(TraitNameToIDAdd(&UNK_01070244, -1))) && last >= 0)
                    {
                        selected = FindItem(last--, 0);
                    }
                    break;
                }
                else if (step < 0 && --last < 0)
                {
                    last = 1;
                    while ((!selected || !selected->IsTraitNonZero(TraitNameToIDAdd(&UNK_01070244, -1))) && last <= index)
                    {
                        selected = FindItem(last++, 0);
                    }
                    break;
                }
            }
            else
                break;
        }
    }
    return selected != current ? selected : 0;
}

struct OwnedMenuObject
{
    virtual ~OwnedMenuObject();
};
struct OwnedMenuTile
{
    ~OwnedMenuTile();
};
struct OwnedMenuEntry
{
    OwnedMenuObject* object;
    OwnedMenuTile* tile;
};
struct OwnedEntryNode
{
    OwnedMenuEntry* entry;
    OwnedEntryNode* next;
    OwnedMenuEntry** FUN_006815c0();
    OwnedEntryNode* FUN_00726070();
    void FUN_006ecd40(int value);
    ~OwnedEntryNode();
};
extern unsigned char s_bAllowDetach;
int __cdecl TraitNameToID(const char* name);
struct MenuValueTile
{
    void Set(int trait, float value, bool propagate);
};
struct RecipeListOwner
{
    int context;
    OwnedMenuEntry* first;
    OwnedEntryNode* remaining;
    MenuValueTile* tile;
    int selected;
    int unk14;
    int unk18;
    unsigned short count;
    unsigned short flags;
    float value;
    bool FUN_007242c0(unsigned int flags);
    void FUN_0072cba0();
    void FUN_0072c880();
    void ClearEntries();
};
// @fnv 0x0072b350
void RecipeListOwner::ClearEntries()
{
    while (remaining && *remaining->FUN_006815c0())
    {
        OwnedEntryNode* next = remaining->FUN_00726070();
        if (!s_bAllowDetach)
            delete (*remaining->FUN_006815c0())->object;
        if (FUN_007242c0(1))
            delete (*remaining->FUN_006815c0())->tile;
        delete *remaining->FUN_006815c0();
        remaining->FUN_006ecd40(0);
        delete remaining;
        remaining = next;
    }
    if (first)
    {
        if (!s_bAllowDetach)
            delete first->object;
        if (FUN_007242c0(1))
            delete first->tile;
        delete first;
    }
    first = 0;
    count = 0;
    value = 0.0f;
    if (tile)
        tile->Set(TraitNameToID("_num_filtered"), 0.0f, true);
    FUN_0072cba0();
    selected = 0;
    FUN_0072c880();
}

struct NavTile
{
    float FUN_00a011b0(int);

    bool IsTraitNonZero(void*);
};
int TraitNameToID(const char*);
float FUN_004bd510(float, float);
struct NavEntry
{
    NavTile* tile;
};
struct NavNode
{
    NavEntry* data;
    NavNode* next;
    NavEntry** FUN_006815c0();
    NavNode* FUN_00726070();
};
struct NavBase
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual NavTile* Get(int, bool);
};
struct NavList
{
    NavNode head;
};
struct Navigation : NavBase, NavList
{
    NavTile* scroll;
    NavTile* current;
    int unk14;
    int unk18;
    unsigned short count;
    bool FUN_0072c7d0();
    NavTile* FUN_0072b620(int action);
};
// @fnv 0x0072b620
NavTile* Navigation::FUN_0072b620(int action)
{
    NavTile* foundVal = 0;
    int delta8 = 0;
    switch (action)
    {
    case 2:
        delta8 = 1;
        break;
    case 1:
        delta8 = -1;
        break;
    case 15:
        delta8 =
            scroll
                ? (int)FUN_004bd510(
                      (float)(-scroll->FUN_00a011b0(0xfb0) / scroll->FUN_00a011b0(TraitNameToID("_scroll_delta"))), 1.0f)
                : 0;
        break;
    case 16:
        delta8 =
            scroll
                ? (int)FUN_004bd510(
                      (float)(scroll->FUN_00a011b0(0xfb0) / scroll->FUN_00a011b0(TraitNameToID("_scroll_delta"))), 1.0f)
                : 0;
        break;
    }
    if (FUN_0072c7d0() && delta8 && count)
    {
        int maximum = count - 1;
        int index;
        if (current)
        {
            int oldIndex4 = (int)current->FUN_00a011b0(0xfac);
            index = oldIndex4 + delta8;
            if (index < 0)
                index = 0;
            else if (index > maximum)
                index = maximum;
        }
        else if (delta8 > 0)
            index = 0;
        else
            index = maximum;
        while (true)
        {
            for (NavNode* node = (NavNode*)static_cast<NavList*>(this); !foundVal && node && *node->FUN_006815c0();
                 node = node->FUN_00726070())
            {
                if ((*node->FUN_006815c0())->tile->FUN_00a011b0(0xfac) == index)
                    foundVal = (*node->FUN_006815c0())->tile;
            }
            if (foundVal && !foundVal->IsTraitNonZero(TraitNameToIDAdd(&DAT_01070244, -1)))
            {
                foundVal = 0;
                if (delta8 > 0 && ++index > maximum)
                {
                    index = maximum - 1;
                    while ((!foundVal || !foundVal->IsTraitNonZero(TraitNameToIDAdd(&DAT_01070244, -1))) && index >= 0)
                    {
                        foundVal = Get(index--, false);
                    }
                    break;
                }
                else if (delta8 < 0 && --index < 0)
                {
                    index = 1;
                    while ((!foundVal || !foundVal->IsTraitNonZero(TraitNameToIDAdd(&DAT_01070244, -1))) &&
                           index <= maximum)
                    {
                        foundVal = Get(index++, false);
                    }
                    break;
                }
            }
            else
                break;
        }
    }
    return foundVal != current ? foundVal : 0;
}

struct List271
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    SelectedOption* current;
    bool FUN_0072c200();
    bool ContainsKey(SelectedOption* option);
    void FUN_0072c2b0();
    bool FUN_0072ae00(SelectedOption* option);
};
// @fnv 0x0072ae00
bool List271::FUN_0072ae00(SelectedOption* option)
{
    if (FUN_0072c200() && (!option || (ContainsKey(option) && option->IsTraitNonZero(TraitNameToIDAdd(&DAT_01070244, -1)))))
    {
        current = option;
        FUN_0072c2b0();
        return true;
    }
    else
    {
        return false;
    }
}

struct RcMenu;

struct RcTile
{
    RcTile* ReadXML(const char* path);
    RcMenu* FUN_00a03c90();
    float FUN_00a011b0(int trait);
    void FUN_00a012d0(int trait, float value, bool propagate);
    void FUN_00a01350(int trait, const char* value, bool propagate);
};

struct RcListBox
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
    void FUN_0075a0d0(RcTile* parent, const char* templateName);
};

struct RcMenu
{
    virtual ~RcMenu();
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
    RcTile* tile2C;
    int unk30;
    RcTile* tile34;
    int unk38;
    int unk3C;
    RcTile* tile40;
    RcTile* tile44;
    RcTile* tile48;
    int unk4C;
    int unk50;
    RcTile* tile54;
    RcTile* tile58;
    RcTile* tile5C;
    int unk60;
    int unk64;
    int unk68;
    RcListBox list6C;
    int unk9C;
    RcListBox listA0;
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
    char unk100;

    void FUN_00a1dc70(RcTile* tile, bool flag);
    bool FUN_007273f0();
    void FUN_00a1dc20(int value);
    void PopulateChallengeList(int unused, int type);
    int FUN_00726070();
};

struct RcIMSub
{
    bool FUN_00718840(int id);
    bool SetFlag2(int id);
};

struct RcIM : SelectionInterface
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
    RcIMSub sub4D4;
    RcTile* FUN_00586150();
};

class TESForm
{
  public:
    virtual ~TESForm();
};

class BGSMessage : public TESForm
{
  public:
};

class GlobalObject_0040c150
{
  public:
    const char* FUN_00403df0();
};

extern GlobalObject_0040c150 g_011d2088;
extern GlobalObject_0040c150 g_011d2b08;
extern GlobalObject_0040c150 g_011d3090;
extern GlobalObject_0040c150 g_011d50f8;
extern GlobalObject_0040c150 g_011d26f4;
extern GlobalObject_0040c150 g_011d33fc;

extern Tile* DAT_011d8eb4;

void FNV_Warning(int level, const char* fmt, ...);
void FNV_Warning(const char* fmt, ...);
int FUN_007273e0();
RcMenu* FUN_00a09030(int menuID);
float FUN_00a01530();
void FUN_00763ff0();
void FUN_00717280(int value);
TESForm* FUN_00483a00(const char* editorID);
char InitTutorialMenu(BGSMessage* message, int flags);

// @fnv 0x00726ff0
RcTile* CreateRecipeMenu(int vendor, int type)
{
    RcIM* im2 = static_cast<RcIM*>(FUN_004b7210());
    if (!vendor)
    {
        FNV_Warning(0x12, "Recipe menu called with NULL vendor!  Oh, noes!");
        return 0;
    }
    RcMenu* oldMenu = FUN_00a09030(FUN_007273e0());
    if (oldMenu)
    {
        delete oldMenu;
    }
    RcTile* tile2 = im2->FUN_00586150()->ReadXML("Data\\Menus\\recipe_menu.xml");
    DAT_011d8e90 = (int)(tile2 ? tile2->FUN_00a03c90() : 0);
    DAT_011d8eac = 0;
    DAT_011d8eb0 = 0;
    DAT_011d8eb4 = 0;
    if (DAT_011d8e90 && ((RcMenu*)DAT_011d8e90)->GetID() == FUN_007273e0())
    {
        ((RcMenu*)DAT_011d8e90)->FUN_00a1dc70(tile2, false);
        if (!((RcMenu*)DAT_011d8e90)->FUN_007273f0())
        {
            FNV_Warning("MENUS: Recipe Menu Creation Failed... Are your menu and art resources up to date?");
        }
        if (tile2->FUN_00a011b0(0xfa7) == 6006.0 || tile2->FUN_00a011b0(0xfa7) == 102.0)
        {
            tile2->FUN_00a012d0(0xfad, FUN_00a01530(), true);
        }
        FUN_00763ff0();
        ((RcMenu*)DAT_011d8e90)->list6C.FUN_0075a0d0(((RcMenu*)DAT_011d8e90)->tile34, "CM_list_template");
        ((RcMenu*)DAT_011d8e90)->listA0.FUN_0075a0d0(((RcMenu*)DAT_011d8e90)->tile40, "CM_list_template");
        ((RcMenu*)DAT_011d8e90)->tile2C->FUN_00a01350(0xfc4, g_011d2088.FUN_00403df0(), true);
        ((RcMenu*)DAT_011d8e90)->tile5C->FUN_00a01350(0xfc4, g_011d2b08.FUN_00403df0(), true);
        ((RcMenu*)DAT_011d8e90)->tile54->FUN_00a01350(0xfc4, g_011d3090.FUN_00403df0(), true);
        ((RcMenu*)DAT_011d8e90)->tile58->FUN_00a01350(0xfc4, g_011d50f8.FUN_00403df0(), true);
        ((RcMenu*)DAT_011d8e90)->tile44->FUN_00a01350(0xfc4, g_011d26f4.FUN_00403df0(), true);
        ((RcMenu*)DAT_011d8e90)->tile48->FUN_00a01350(0xfc4, g_011d33fc.FUN_00403df0(), true);
        ((RcMenu*)DAT_011d8e90)
            ->tile44->FUN_00a012d0(0xfa1, ((RcMenu*)DAT_011d8e90)->tile44->FUN_00a011b0(0xfa1) - 20.0, true);
        ((RcMenu*)DAT_011d8e90)
            ->tile48->FUN_00a012d0(0xfa1, ((RcMenu*)DAT_011d8e90)->tile48->FUN_00a011b0(0xfa1) - 20.0, true);
        ((RcMenu*)DAT_011d8e90)->unk60 = vendor;
        ((RcMenu*)DAT_011d8e90)->unk64 = type;
        FUN_00717280(0x24);
        if (!static_cast<RcIM*>(FUN_004b7210())->sub4D4.FUN_00718840(0x26))
        {
            BGSMessage* message = dynamic_cast<BGSMessage*>(FUN_00483a00("HelpCrafting"));
            if (message)
            {
                ((RcMenu*)DAT_011d8e90)->unk100 = InitTutorialMenu(message, 0);
                static_cast<RcIM*>(FUN_004b7210())->sub4D4.SetFlag2(0x26);
            }
        }
        ((RcMenu*)DAT_011d8e90)->FUN_00a1dc20(0);
        ((RcMenu*)DAT_011d8e90)->PopulateChallengeList(0, type);
        return tile2;
    }
    else if (DAT_011d8e90 && ((RcMenu*)DAT_011d8e90)->FUN_00726070())
    {
        delete (RcMenu*)DAT_011d8e90;
    }
    return 0;
}

int __cdecl HLTraitNameToID(const char* apName, int aiDefault);

struct HLItem;

struct HLTileValue
{
    void SetFormula(int aiOperator, HLItem* apSource, int aiTrait);
    void Refresh(int aiFlags);
};

struct HLTile
{
    HLTileValue* GetValue(int aiTrait);
    HLTile* GetChild(const char* apName);
    void SetVisible(bool abVisible);
    void SetFlags(int aiFlags);
    void SetInt(int aiTrait, int aiValue);
};

struct HLItem
{
    bool IsSelected();
};

HLTile* __cdecl HLFindTile(HLTile* apParent, const char* apName);

struct HLListItem
{
    int unk00;
    int unk04;
    int unk08;
    HLTile* pTile;
    HLItem* pItem;

    void RefreshHighlight();
};

// Updates the _highlight_y and _selected_height tile values from pItem, then shows or hides the lb_highlight_box children based on pItem->IsSelected().
// @fnv 0x0072bce0
void HLListItem::RefreshHighlight()
{
    static int s_iHighlightY = HLTraitNameToID("_highlight_y", -1);
    static int s_iSelectedHeight = HLTraitNameToID("_selected_height", -1);

    if (pTile)
    {
        if (pItem)
        {
            HLTileValue* pHighlightY = pTile->GetValue(s_iHighlightY);
            HLTileValue* pSelectedHeight = pTile->GetValue(s_iSelectedHeight);
            pHighlightY->SetFormula(0x7d0, pItem, 0xfa2);
            pHighlightY->Refresh(0);
            pSelectedHeight->SetFormula(0x7d0, pItem, 0xfb0);
            pSelectedHeight->Refresh(0);
            if (pItem->IsSelected())
            {
                HLTile* pBox = HLFindTile(pTile, "lb_highlight_box");
                if (pBox)
                {
                    HLTile* pRetrievedObject = pBox->GetChild("top");
                    if (pRetrievedObject)
                    {
                        pRetrievedObject->SetVisible(true);
                        pRetrievedObject->SetFlags(8);
                        pRetrievedObject = pBox->GetChild("bottom");
                        pRetrievedObject->SetVisible(true);
                        pRetrievedObject->SetFlags(8);
                        pRetrievedObject = pBox->GetChild("left");
                        pRetrievedObject->SetVisible(true);
                        pRetrievedObject->SetFlags(8);
                        pRetrievedObject = pBox->GetChild("right");
                        pRetrievedObject->SetVisible(true);
                        pRetrievedObject->SetFlags(8);
                    }
                    pBox->SetVisible(true);
                    pBox->SetFlags(8);
                }
            }
            else
            {
                HLTile* pBox = HLFindTile(pTile, "lb_highlight_box");
                if (pBox)
                {
                    HLTile* pRetrievedObject = pBox->GetChild("top");
                    if (pRetrievedObject)
                    {
                        pRetrievedObject->SetVisible(false);
                        pRetrievedObject->SetFlags(8);
                        pRetrievedObject = pBox->GetChild("bottom");
                        pRetrievedObject->SetVisible(false);
                        pRetrievedObject->SetFlags(8);
                        pRetrievedObject = pBox->GetChild("left");
                        pRetrievedObject->SetVisible(false);
                        pRetrievedObject->SetFlags(8);
                        pRetrievedObject = pBox->GetChild("right");
                        pRetrievedObject->SetVisible(false);
                        pRetrievedObject->SetFlags(8);
                    }
                    pBox->SetVisible(false);
                    pBox->SetFlags(8);
                }
            }
        }
        else
        {
            pTile->SetInt(s_iHighlightY, -1);
            pTile->SetInt(s_iSelectedHeight, 0);
        }
    }
}

struct HighlightTile
{
    HighlightTile* GetValue(int);
    void Link(int, HighlightTile*, int);
    void Update(int);
    bool GetSpeechChallengeFailure();
    HighlightTile* Child(const char*);
    void SetQuestCompleted(bool);
    void Refresh(int);
    void SetInt(int, int);
};
int __cdecl RegisterTrait(const char*, int);
HighlightTile* __cdecl FindHighlight(HighlightTile*, const char*);
struct HighlightList
{
    int unk00;
    int unk04;
    int unk08;
    HighlightTile* root;
    HighlightTile* selected;
    void FUN_0072c2b0();
};
// @fnv 0x0072c2b0
void HighlightList::FUN_0072c2b0()
{
    static int highlightY = RegisterTrait("_highlight_y", -1);
    static int selectedHeight = RegisterTrait("_selected_height", -1);
    if (root)
    {
        if (selected)
        {
            HighlightTile* pHighlightY = root->GetValue(highlightY);
            HighlightTile* pSelectedHeight = root->GetValue(selectedHeight);
            pHighlightY->Link(2000, selected, 4002);
            pHighlightY->Update(0);
            pSelectedHeight->Link(2000, selected, 4016);
            pSelectedHeight->Update(0);
            if (selected->GetSpeechChallengeFailure())
            {
                HighlightTile* pHighlightBox = FindHighlight(root, "lb_highlight_box");
                if (pHighlightBox)
                {
                    HighlightTile* edge7 = pHighlightBox->Child("top");
                    if (edge7)
                    {
                        edge7->SetQuestCompleted(true);
                        edge7->Refresh(8);
                        edge7 = pHighlightBox->Child("bottom");
                        edge7->SetQuestCompleted(true);
                        edge7->Refresh(8);
                        edge7 = pHighlightBox->Child("left");
                        edge7->SetQuestCompleted(true);
                        edge7->Refresh(8);
                        edge7 = pHighlightBox->Child("right");
                        edge7->SetQuestCompleted(true);
                        edge7->Refresh(8);
                    }
                    pHighlightBox->SetQuestCompleted(true);
                    pHighlightBox->Refresh(8);
                }
            }
            else
            {
                HighlightTile* box2 = FindHighlight(root, "lb_highlight_box");
                if (box2)
                {
                    HighlightTile* edge2 = box2->Child("top");
                    if (edge2)
                    {
                        edge2->SetQuestCompleted(false);
                        edge2->Refresh(8);
                        edge2 = box2->Child("bottom");
                        edge2->SetQuestCompleted(false);
                        edge2->Refresh(8);
                        edge2 = box2->Child("left");
                        edge2->SetQuestCompleted(false);
                        edge2->Refresh(8);
                        edge2 = box2->Child("right");
                        edge2->SetQuestCompleted(false);
                        edge2->Refresh(8);
                    }
                    box2->SetQuestCompleted(false);
                    box2->Refresh(8);
                }
            }
        }
        else
        {
            root->SetInt(highlightY, -1);
            root->SetInt(selectedHeight, 0);
        }
    }
}

namespace fnv_0072c880 {
int __cdecl HLTraitNameToID(const char* apName, int aiDefault);

struct HLItem
{
    bool GetSpeechChallengeFailure();
};

struct HLValue
{
    void SetFromItem(int aiOperator, HLItem* apItem, int aiTrait);
    void Update(int aiFlags);
};

struct HLTile
{
    HLValue* GetValue(int aiTrait);
    HLTile* GetChild(const char* apName);
    void SetEnabled(bool abEnabled);
    void SetFlag(int aiFlag);
    void SetInt(int aiTrait, int aiValue);
};

HLTile* __cdecl HLFindTile(HLTile* apParent, const char* apName);

struct HLListItem
{
    int unk00;
    int unk04;
    int unk08;
    HLTile* pTile;
    HLItem* pItem;

    void FUN_0072c880();
};

// Sets the tile's _highlight_y and _selected_height values from pItem, then enables or disables the lb_highlight_box sides based on GetSpeechChallengeFailure.
// @fnv 0x0072c880
void HLListItem::FUN_0072c880()
{
    static int s_iHighlightY = HLTraitNameToID("_highlight_y", -1);
    static int s_iSelectedHeight = HLTraitNameToID("_selected_height", -1);

    if (pTile)
    {
        if (pItem)
        {
            HLValue* pHighlightY = pTile->GetValue(s_iHighlightY);
            HLValue* pSelectedHeight = pTile->GetValue(s_iSelectedHeight);
            pHighlightY->SetFromItem(0x7d0, pItem, 0xfa2);
            pHighlightY->Update(0);
            pSelectedHeight->SetFromItem(0x7d0, pItem, 0xfb0);
            pSelectedHeight->Update(0);
            if (pItem->GetSpeechChallengeFailure())
            {
                HLTile* pBox = HLFindTile(pTile, "lb_highlight_box");
                if (pBox)
                {
                    HLTile* pSideTile = pBox->GetChild("top");
                    if (pSideTile)
                    {
                        pSideTile->SetEnabled(true);
                        pSideTile->SetFlag(8);
                        pSideTile = pBox->GetChild("bottom");
                        pSideTile->SetEnabled(true);
                        pSideTile->SetFlag(8);
                        pSideTile = pBox->GetChild("left");
                        pSideTile->SetEnabled(true);
                        pSideTile->SetFlag(8);
                        pSideTile = pBox->GetChild("right");
                        pSideTile->SetEnabled(true);
                        pSideTile->SetFlag(8);
                    }
                    pBox->SetEnabled(true);
                    pBox->SetFlag(8);
                }
            }
            else
            {
                HLTile* pBox = HLFindTile(pTile, "lb_highlight_box");
                if (pBox)
                {
                    HLTile* pSideTile = pBox->GetChild("top");
                    if (pSideTile)
                    {
                        pSideTile->SetEnabled(false);
                        pSideTile->SetFlag(8);
                        pSideTile = pBox->GetChild("bottom");
                        pSideTile->SetEnabled(false);
                        pSideTile->SetFlag(8);
                        pSideTile = pBox->GetChild("left");
                        pSideTile->SetEnabled(false);
                        pSideTile->SetFlag(8);
                        pSideTile = pBox->GetChild("right");
                        pSideTile->SetEnabled(false);
                        pSideTile->SetFlag(8);
                    }
                    pBox->SetEnabled(false);
                    pBox->SetFlag(8);
                }
            }
        }
        else
        {
            pTile->SetInt(s_iHighlightY, -1);
            pTile->SetInt(s_iSelectedHeight, 0);
        }
    }
}
}  // namespace fnv_0072c880

class FUN_0046ffb0
{
  public:
    ~FUN_0046ffb0();
    void* m_item;
    void* m_pkNext;
};

void __cdecl FUN_007211c0(void* pObj);

class FUN_0072b2e0
{
  public:
    virtual ~FUN_0072b2e0();

    void ClearEntries();

    FUN_0046ffb0 m_kList;
};

// Destroys the entry list by clearing its entries and then calling FUN_007211c0 on itself.
// @fnv 0x0072b2e0
FUN_0072b2e0::~FUN_0072b2e0()
{
    ClearEntries();
    FUN_007211c0(this);
}

struct CategoryChallenge
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FNStub fullName;
};
struct CategoryArray
{
    unsigned int FUN_0044ddc0();
    CategoryChallenge*& FUN_006a7ad0(int index);
};
struct CategoryList
{
    virtual void SetSelected(RcTile* tile);
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual RcTile* GetTile(int index, bool flag);
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
    void FUN_007312e0();
    void ApplyFilter(bool(__cdecl* filter)(TESChallenge*));
    void UpdateSelection(bool flag);
};
extern void* DAT_011d8ea8;
void CraftRecipe();
void CreateQuantityMenu(void* object, void(__cdecl* callback)(), int count);
void FUN_00706f30(int value);
struct CategoryMenu
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
    RcTile* tiles[14];
    int unk60;
    int unk64;
    int unk68;
    CategoryList list6C;
    void OnAction(int action, RcTile* tile);
};

// Handles a menu action: opens a quantity menu for action 7, resets state for 8, or cycles the selected category and refreshes the list for 0-2.
// @fnv 0x007274b0
void CategoryMenu::OnAction(int action, RcTile* tile)
{
    if (!tile && action >= 0 && action < 14)
        tile = tiles[action];
    switch (action)
    {
    case 7:
        CreateQuantityMenu(DAT_011d8ea8, CraftRecipe, 0x7fffffff);
        break;
    case 8:
        DAT_011d8ea5 = 0;
        FUN_00727430();
        break;
    case 0:
    case 1:
    case 2:
        if ((unsigned char)DAT_011d8ea5)
            break;
        FUN_00706f30(unk68);
        DAT_0119fbf4 += action ? 1 : -1;
        if (DAT_0119fbf4 < -1)
            DAT_0119fbf4 = ((CategoryArray*)FUN_00726f10())->FUN_0044ddc0() - 1;
        else if ((unsigned int)DAT_0119fbf4 >= ((CategoryArray*)FUN_00726f10())->FUN_0044ddc0())
            DAT_0119fbf4 = -1;
        if (DAT_0119fbf4 != -1)
            tiles[1]->FUN_00a01350(
                0xfc4, ((CategoryArray*)FUN_00726f10())->FUN_006a7ad0(DAT_0119fbf4)->fullName.GetFullName(), true);
        else
            tiles[1]->FUN_00a01350(0xfc4, g_011d2088.FUN_00403df0(), true);
        list6C.SetSelected(list6C.GetTile(0, false));
        list6C.v10();
        list6C.FUN_007312e0();
        list6C.ApplyFilter(IsThresholdDifferent);
        list6C.UpdateSelection(true);
        break;
    }
}

class TESFullName
{
  public:
    virtual ~TESFullName();
};
struct FUN_00726070_shell
{
    TESForm* FUN_00726070();
};

struct FUN_00726070_shell_b
{
    TESForm* FUN_00726070();
};

struct FUN_00408da0_shell
{
    void* FUN_00408da0();
};

struct FUN_00728cd0_pair
{
    int m_00;
    FUN_00726070_shell* m_04;
};

struct FUN_00728cd0_pair_b
{
    int m_00;
    FUN_00726070_shell_b* m_04;
};

extern int DAT_01183028;
extern int DAT_01183158;
void* __cdecl FUN_00ec43fb(void*, bool, int*, int*, int);
int __cdecl FUN_00469880(void*, void*);

// Compares the full names of two forms by casting their TESForm pointers to TESFullName and calling FUN_00469880 on the resulting name data.
// @fnv 0x00728cd0
int __cdecl FUN_00728cd0(FUN_00728cd0_pair* apRight, FUN_00728cd0_pair_b* apLeft)
{
    FUN_00408da0_shell* right = (FUN_00408da0_shell*)dynamic_cast<TESFullName*>(apRight->m_04->FUN_00726070());
    FUN_00408da0_shell* left = (FUN_00408da0_shell*)dynamic_cast<TESFullName*>(apLeft->m_04->FUN_00726070());
    void* l = right->FUN_00408da0();
    void* r = left->FUN_00408da0();
    int result = 0;
    result = FUN_00469880(l, r);
    return result;
}

namespace fnv_00726df0 {
struct FUN_00a1c4a0
{
    virtual void MenuVirtual();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    FUN_00a1c4a0();
    ~FUN_00a1c4a0();
};
struct FUN_007299a0
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
    int m_28;
    int m_2c;
    FUN_007299a0* m_pOwnerObject;
    FUN_007299a0();
    ~FUN_007299a0();
};
struct FUN_0072a7c0
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
    int m_28;
    int m_2c;
    FUN_0072a7c0();
    ~FUN_0072a7c0();
};
extern char str_0106ed20[];
extern char str_0106ed18[];
extern char str_01070474[];
extern int DAT_011d8e98;
extern int DAT_011d8e9c;
extern int DAT_011d8ea0;
extern int DAT_011d8e94;
extern int DAT_011d8ea8;
int __cdecl TraitNameToID(char const*);
struct Manager726
{
    void FUN_008454f0(int);
};
struct FUN_00726df0 : FUN_00a1c4a0
{
    FUN_007299a0 m_6c;
    FUN_0072a7c0 m_a0;
    FUN_0072b210 m_d0;
    bool m_100;
    virtual void MenuVirtual();
    FUN_00726df0();
};
// Initializes global string handles, sets m_6c owner, calls FUN_008454f0, and sets m_68 and m_100.
// @fnv 0x00726df0
FUN_00726df0::FUN_00726df0()
{
    DAT_011d8e98 = TraitNameToID(str_0106ed20);
    DAT_011d8e9c = TraitNameToID(str_0106ed18);
    DAT_011d8ea0 = TraitNameToID(str_01070474);
    DAT_011d8e94 = 0;
    m_6c.m_pOwnerObject = &m_6c;
    DAT_011d8ea8 = 0;
    reinterpret_cast<Manager726*>(FUN_00726f10())->FUN_008454f0(1);
    m_68 = 3;
    m_100 = false;
}
}  // namespace fnv_00726df0

class TESIcon
{
  public:
    int FUN_0048cee0();
    const char* FUN_00408da0();
};
struct ArmorNames
{
    const char* FUN_00481280(int);
};
class TESObjectARMO
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C,
        unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C;
    ArmorNames names;
};
struct StatValues
{
    int FUN_0066ef20(int);
};
struct RecipeInventoryCount
{
    unsigned FUN_00726070();
};
class TESBoundObject
{
};
struct ActorData
{
    virtual void unkV00();
    virtual void unkV01();
    virtual void unkV02();
    virtual void unkV03();
    virtual void unkV04();
    virtual void unkV05();
    virtual void unkV06();
    virtual void unkV07();
    virtual void unkV08();
    virtual void unkV09();
    virtual void unkV0A();
    virtual void unkV0B();
    virtual void unkV0C();
    virtual void unkV0D();
    virtual void unkV0E();
    virtual void unkV0F();
    virtual void unkV10();
    virtual void unkV11();
    virtual void unkV12();
    virtual void unkV13();
    virtual void unkV14();
    virtual void unkV15();
    virtual void unkV16();
    virtual void unkV17();
    virtual void unkV18();
    virtual void unkV19();
    virtual void unkV1A();
    virtual void unkV1B();
    virtual void unkV1C();
    virtual void unkV1D();
    virtual void unkV1E();
    virtual void unkV1F();
    virtual void unkV20();
    virtual void unkV21();
    virtual void unkV22();
    virtual void unkV23();
    virtual void unkV24();
    virtual void unkV25();
    virtual void unkV26();
    virtual void unkV27();
    virtual void unkV28();
    virtual void unkV29();
    virtual void unkV2A();
    virtual void unkV2B();
    virtual void unkV2C();
    virtual void unkV2D();
    virtual void unkV2E();
    virtual void unkV2F();
    virtual void unkV30();
    virtual void unkV31();
    virtual void unkV32();
    virtual void unkV33();
    virtual void unkV34();
    virtual void unkV35();
    virtual void unkV36();
    virtual void unkV37();
    virtual void unkV38();
    virtual void unkV39();
    virtual void unkV3A();
    virtual void unkV3B();
    virtual void unkV3C();
    virtual void unkV3D();
    virtual void unkV3E();
    virtual void unkV3F();
    virtual bool IsValid();
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
    StatValues stats;
    FUN_004459e0* FUN_00576260(TESBoundObject*, int);
};
struct Entry
{
    TESForm* FUN_00726070();
    unsigned FUN_00559450();
};
struct EntryListNode
{
    Entry*& FUN_006815c0();
    EntryListNode* FUN_00726070();
    unsigned FUN_005ae380();
    bool FUN_008256d0();
};
struct Category
{
    int unk0, unk4, unk8, unkC, unk10, unk14;
    FNStub name;
};
struct RecipeData
{
    Category* GetField54();
    EntryListNode* FUN_005a8080();
    EntryListNode* FUN_005d43c0();
    Category* FUN_006286d0();
    int FUN_0059bb30();
    int FUN_0045cd60();
};
struct RecipeTiles
{
    void FUN_00700320(int, int);
    void FUN_00a01350(int, const char*, bool);
};
struct TileRef
{
    RecipeTiles*& FUN_007b5370();
};
struct RecipeAddedItem
{
    int unk0;
    TileRef tile;
};
struct RecipeBox
{
    virtual void SetSelected(TESForm*);
    virtual Entry* GetSelected();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual TESForm* SelectAt(int, bool);
    virtual void v6();
    virtual void Clear();
    virtual void Sort(int(__cdecl*)(FUN_00728cd0_pair*, FUN_00728cd0_pair_b*));
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    RecipeBox* current;
    void FUN_007312e0();
    void UpdateSelection(int);
    Entry* FUN_007a1910();
    RecipeAddedItem* FUN_0072a900(Entry*, const char*, int, int);
};
extern RecipeData* DAT_011d8e94;
int __cdecl FUN_00406d00(char*, int, const char*, ...);
const char* __cdecl FUN_00464f30(const char*, bool);
const char* __cdecl FUN_0066e950(int);
int __cdecl FUN_00480f80(TESObjectARMO*, FNVAuxController*);
struct SexData
{
    int FUN_0087f4c0();
};
struct RecipeEnterMenu
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Refresh(int, Entry*);
    virtual void Activate(int, int);
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    RecipeTiles* tiles[14];
    ActorData* actor;
    Category* category;
    int unk68;
    RecipeBox first, second;
    void FUN_00728da0(TESForm*, RecipeTiles*);
    void FUN_00727b10(int, RecipeTiles*);
};
// Handles actions 3, 6, and 15 to switch recipe views, rebuild ingredient details, and update selected item tiles.
// @fnv 0x00727b10
void RecipeEnterMenu::FUN_00727b10(int id, RecipeTiles* tile)
{
    if (!tile && id >= 0 && id < 14)
        tile = tiles[id];
    switch (id)
    {
    case 3:
        Activate(6, 0);
        first.FUN_007312e0();
        second.SetSelected(0);
        first.UpdateSelection(0);
        break;
    case 6:
        Activate(3, 0);
        first.SetSelected(0);
        FUN_004b7210();
        if (FUN_004b71d0())
            second.SetSelected(second.SelectAt(0, false));
        DAT_011d8ea5 = 1;
        Refresh(15, second.GetSelected());
        break;
    case 15: {
        Entry* selected = 0;
        bool alternate = false;
        if ((unsigned char)DAT_011d8ea5)
        {
            if (second.FUN_007a1910())
                selected = second.FUN_007a1910();
        }
        else
        {
            tiles[10]->FUN_00700320(0xfa3, 0);
            tiles[9]->FUN_00700320(0xfa3, 0);
            if (first.current->FUN_007a1910())
                DAT_011d8e94 = (RecipeData*)first.current->FUN_007a1910();
            ActorData* owner =
                ((RecipeEnterMenu*)DAT_011d8e90)->actor && ((RecipeEnterMenu*)DAT_011d8e90)->actor->IsValid()
                    ? ((RecipeEnterMenu*)DAT_011d8e90)->actor
                    : 0;
            if (DAT_011d8e94)
            {
                const char* categoryName = "*** MISSING CATEGORY ***";
                if (DAT_011d8e94->GetField54())
                    categoryName = DAT_011d8e94->GetField54()->name.GetFullName();
                ((RecipeEnterMenu*)DAT_011d8e90)->tiles[4]->FUN_00a01350(0xfc4, categoryName, true);
                if (((RecipeEnterMenu*)DAT_011d8e90)->category == DAT_011d8e94->GetField54())
                    ((RecipeEnterMenu*)DAT_011d8e90)->tiles[4]->FUN_00700320(0xfa9, 255);
                else
                    ((RecipeEnterMenu*)DAT_011d8e90)->tiles[4]->FUN_00700320(0xfa9, 127);
                EntryListNode* list = DAT_011d8e94->FUN_005a8080();
                second.Clear();
                selected = DAT_011d8e94->FUN_005d43c0()->FUN_006815c0();
                if (DAT_011d8e94->FUN_005d43c0()->FUN_005ae380() > 1 &&
                    DAT_011d8e94->FUN_005a8080()->FUN_005ae380() == 1)
                {
                    list = DAT_011d8e94->FUN_005d43c0();
                    ((RecipeEnterMenu*)DAT_011d8e90)
                        ->tiles[11]
                        ->FUN_00a01350(0xfc4, DAT_011d8e94->FUN_006286d0()->name.GetFullName(), true);
                    alternate = true;
                }
                else
                    ((RecipeEnterMenu*)DAT_011d8e90)->tiles[11]->FUN_00a01350(0xfc4, g_011d3090.FUN_00403df0(), true);
                while (list && !list->FUN_008256d0())
                {
                    char label[256];
                    TESFullName* name = dynamic_cast<TESFullName*>(list->FUN_006815c0()->FUN_00726070());
                    if (name && owner)
                    {
                        TESBoundObject* bound = dynamic_cast<TESBoundObject*>(list->FUN_006815c0()->FUN_00726070());
                        if (bound)
                        {
                            FUN_004459e0* have = owner->FUN_00576260(bound, 0);
                            unsigned inventory = have ? ((RecipeInventoryCount*)have)->FUN_00726070() : 0;
                            delete have;
                            if (alternate)
                                FUN_00406d00(label, 256, "%s (%d)", ((FNStub*)name)->GetFullName(),
                                             list->FUN_006815c0()->FUN_00559450());
                            else
                                FUN_00406d00(label, 256, "%s (%d/%d)", ((FNStub*)name)->GetFullName(), inventory,
                                             list->FUN_006815c0()->FUN_00559450());
                            RecipeAddedItem* added = second.FUN_0072a900(list->FUN_006815c0(), label, 0, 0);
                            if (inventory < list->FUN_006815c0()->FUN_00559450() && !alternate)
                                added->tile.FUN_007b5370()->FUN_00700320(0xfa9, 127);
                            else
                                added->tile.FUN_007b5370()->FUN_00700320(0xfa9, 255);
                        }
                    }
                    else
                        second.FUN_0072a900(list->FUN_006815c0(), FUN_00464f30("ERROR WITH CAST", false), 0, 0);
                    list = list->FUN_00726070();
                }
                second.Sort(FUN_00728cd0);
                if (owner)
                {
                    char skill[256];
                    skill[0] = 0;
                    if (DAT_011d8e94->FUN_0059bb30() > -1)
                        FUN_00406d00(skill, 256, "%s (%d/%d)", FUN_0066e950(DAT_011d8e94->FUN_0059bb30()),
                                     owner->stats.FUN_0066ef20(DAT_011d8e94->FUN_0059bb30()),
                                     DAT_011d8e94->FUN_0045cd60());
                    ((RecipeEnterMenu*)DAT_011d8e90)->tiles[5]->FUN_00a01350(0xfc4, skill, true);
                    if (DAT_011d8e94->FUN_0059bb30() > -1 &&
                        owner->stats.FUN_0066ef20(DAT_011d8e94->FUN_0059bb30()) < DAT_011d8e94->FUN_0045cd60())
                        ((RecipeEnterMenu*)DAT_011d8e90)->tiles[5]->FUN_00700320(0xfa9, 127);
                    else
                        ((RecipeEnterMenu*)DAT_011d8e90)->tiles[5]->FUN_00700320(0xfa9, 255);
                }
                if (FUN_00727920(DAT_011d8e94))
                    ((RecipeEnterMenu*)DAT_011d8e90)->tiles[7]->FUN_00700320(0xfaf, 1);
                else
                    ((RecipeEnterMenu*)DAT_011d8e90)->tiles[7]->FUN_00700320(0xfaf, 0);
            }
        }
        if (selected)
        {
            FUN_00728da0(selected->FUN_00726070(), tiles[10]);
            tiles[10]->FUN_00700320(0xfa3, 1);
            TESIcon* icon = dynamic_cast<TESIcon*>(selected->FUN_00726070());
            if (icon && icon->FUN_0048cee0())
            {
                tiles[9]->FUN_00a01350(0xfcc, icon->FUN_00408da0(), true);
                tiles[9]->FUN_00700320(0xfa3, 1);
            }
            else
            {
                TESObjectARMO* armor = dynamic_cast<TESObjectARMO*>(selected->FUN_00726070());
                if (armor && FUN_00480f80(armor, DAT_011dea3c))
                {
                    tiles[9]->FUN_00a01350(0xfcc, armor->names.FUN_00481280(((SexData*)DAT_011dea3c)->FUN_0087f4c0()),
                                           true);
                    tiles[9]->FUN_00700320(0xfa3, 1);
                }
                else
                    tiles[9]->FUN_00700320(0xfa3, 0);
            }
        }
        else
            tiles[9]->FUN_00700320(0xfa3, 0);
        break;
    }
    }
}

int __cdecl TraitNameToID(const char* apName);
float __cdecl FUN_004e4430(float afValue);
int __cdecl FUN_00647b70(int a, int b);

struct RecipeScrollMetrics
{
    int unk00;
    int unk04;
    int unk08;
    TileStub* pScrollTile;
    int unk10;
    TileStub* pCountTile;
    int unk18;
    int unk1c;
    float fTotal;

    unsigned int GetFilteredCount();
    void FUN_0072c000();
};

// Uses fTotal and the scroll tile's 0xfb0 value to set scroll delta and item count.
// @fnv 0x0072c000
void RecipeScrollMetrics::FUN_0072c000()
{
    if (pScrollTile)
    {
        float fVisible = pScrollTile->GetValueFloat(0xfb0);
        int iItemCount = 1;
        if (fTotal > 0.0 && fVisible > 0.0)
        {
            if (fTotal > fVisible)
            {
                iItemCount = FUN_00647b70((int)FUN_004e4430(GetFilteredCount() * (fTotal - fVisible) / fTotal) + 1, 2);
            }
            if (iItemCount > 1)
            {
                pScrollTile->SetFloat(TraitNameToID("_scroll_delta"), (fTotal - fVisible) / (iItemCount - 1), true);
            }
        }
        if (pCountTile)
        {
            pCountTile->SetInt(TraitNameToID("_number_of_items"), iItemCount);
        }
    }
}

struct ReqData
{
    unsigned int FUN_00559450();
    TESForm* FUN_00726070();
};

struct ReqNode
{
    ReqData** FUN_006815c0();
    bool FUN_008256d0();
    ReqNode* FUN_00726070();
};

struct ItemEntry
{
    unsigned int FUN_00726070();
    ~ItemEntry();
};

struct ItemList
{
    int FUN_0066ef20(int aiIndex);
};

struct ChallengeOwner
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
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool v40();

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
    ItemList kItems;

    ItemEntry* FUN_00576260(TESBoundObject* apObject, int aiFlags);
};

struct RecipeCanMakeView
{
    int GetChallengeType();
    int GetThreshold();
    int FUN_0059bb30();
    int FUN_0045cd60();
    ReqNode* FUN_005a8080();
};

// Checks challenge prerequisites and, with an owner, limits the count by bound-object inventory ratios; otherwise it starts at 100.
// @fnv 0x00727920
int __cdecl FUN_00727920(void* apChallenge)
{
    ChallengeOwner* pOwner =
        (((ChallengeOwner*)((RcMenu*)DAT_011d8e90)->unk60) && ((ChallengeOwner*)((RcMenu*)DAT_011d8e90)->unk60)->v40())
            ? ((ChallengeOwner*)((RcMenu*)DAT_011d8e90)->unk60)
            : 0;
    reinterpret_cast<int&>(DAT_011d8ea8) = 100;
    if (!static_cast<RecipeCanMakeView*>(apChallenge)->GetChallengeType() ||
        !static_cast<RecipeCanMakeView*>(apChallenge)->GetThreshold())
        return 0;
    if (pOwner)
    {
        if (static_cast<RecipeCanMakeView*>(apChallenge)->FUN_0059bb30() > -1 &&
            pOwner->kItems.FUN_0066ef20(static_cast<RecipeCanMakeView*>(apChallenge)->FUN_0059bb30()) <
                static_cast<RecipeCanMakeView*>(apChallenge)->FUN_0045cd60())
            return 0;
        if (((RcMenu*)DAT_011d8e90)->unk64 != static_cast<RecipeCanMakeView*>(apChallenge)->GetChallengeType())
            return 0;
        ReqNode* pNode = static_cast<RecipeCanMakeView*>(apChallenge)->FUN_005a8080();
        while (pNode && !pNode->FUN_008256d0())
        {
            ReqData* pReq = *pNode->FUN_006815c0();
            TESBoundObject* pObject = dynamic_cast<TESBoundObject*>((*pNode->FUN_006815c0())->FUN_00726070());
            if (pObject)
            {
                ItemEntry* pEntry = pOwner->FUN_00576260(pObject, 0);
                unsigned int uiHave = pEntry ? pEntry->FUN_00726070() : 0;
                delete pEntry;
                if (uiHave < pReq->FUN_00559450())
                {
                    return 0;
                }
                else
                {
                    int iTimes = uiHave / pReq->FUN_00559450();
                    if (iTimes < reinterpret_cast<int&>(DAT_011d8ea8))
                        reinterpret_cast<int&>(DAT_011d8ea8) = iTimes;
                }
            }
            pNode = pNode->FUN_00726070();
        }
    }
    return reinterpret_cast<int&>(DAT_011d8ea8);
}

extern const char str_0106ed20[];
extern const char str_0106ed18[];
extern const char str_0106ecf4[];
extern const char str_0106ece8[];
extern const char str_0106ecc8[];
extern const char str_01020764[];
extern const char str_01020768[];
extern const char str_01019f08[];
extern const char str_01047008[];
extern double DAT_01012060;
extern double DAT_01012070;
extern float DAT_01023cd8;

struct TileObj
{
    void FUN_00a01350(int a, const char* b, bool c);
    void FUN_00700320(int a, int b);
    void FUN_00a012d0(int a, float b, bool c);
};

struct ListLinks
{
    void* FUN_00683520(void** a);
    void* FUN_00726070();
};

struct MenuTileList
{
    int m_00;
    ListLinks links;
    double FUN_00a011b0(int a);
};

class RecipeStatsFormView
{
  public:
    virtual ~RecipeStatsFormView();
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
    int nameComponent;
    int FUN_00401170();
};

struct TESObjectWEAP : public TESForm
{
    int GetField19C();
    void* FUN_00525980(int a);
    float FUN_00709430(int a);
    int FUN_00525b20(int a, int b, int c);
};

struct RecipeStatsArmorView : public TESForm
{
    float FUN_004be060();
};

struct SoundObj
{
    const char* FUN_00408da0();
};

struct AmmoObj
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
    SoundObj name;
    const char* GetStringAtOffsetC4();
};

struct InvChanges
{
    int FUN_004c8f30(void* ammo);
};

struct ProcessObj
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
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual int v51();
    virtual int v52();
    virtual int v53();
};

struct RecipeStatsPlayerView
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
    int actorValues;
    ProcessObj* FUN_008d8520();
};

bool __fastcall FUN_004d1360(RecipeStatsPlayerView* a);

struct SettingObj
{
    const char* FUN_00403df0();
};

extern SettingObj DAT_011d20c4;
extern SettingObj DAT_011d412c;
extern SettingObj DAT_011d2c7c;
extern SettingObj DAT_011d2aa8;
extern SettingObj DAT_011d26a0;
extern SettingObj DAT_011d4da4;
extern SettingObj DAT_011d4edc;
extern SettingObj DAT_011d4024;
extern SettingObj DAT_011d330c;

InvChanges* __cdecl FUN_004bf220(void* player);
float __cdecl GetWeaponDamage(TESObjectWEAP* weapon, float condition, int a, int b);
float __cdecl FUN_00646360(int rating, float condition);
float __cdecl FUN_00476b20(float rating);
int __cdecl TraitNameToID(const char* a);
int __cdecl FUN_0048e8a0(void* a);
float __cdecl ComputeItemValue(float a, float b);
float __cdecl FUN_0048ebc0(void* a, int b);
float __cdecl FUN_00645380(void* actorValues, TESObjectWEAP* weapon, float condition, int p4, int p5, int p6, int p7,
                           int p8, float p9, float p10, int p11, int p12, int p13);
float __cdecl FUN_004bd510(float a, float b);
float __cdecl FUN_0040ebd0(float a, float b);
int __cdecl FUN_00406d00(char* a, int b, const char* c, ...);
int __cdecl FUN_00406d30(char* a, int b, const char* c);
void* __cdecl FUN_004be330(void* a);
unsigned int __cdecl FUN_0044a670(const char* a);

struct ListHead
{
    int unk00;
    int links;
    int* FUN_006815c0();
    void BuildDescription(char* a, int b);
};

struct NamedList
{
    int unk00;
    ListHead entries;
};

struct HolderObj
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
    void* m_24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    void* m_3c;
    unsigned char FUN_0040e210(int a);
};

struct SelfObj
{
    void FUN_00728da0(TESForm* a1, MenuTileList* a2);
};

// Populates a 12-tile menu with item stats, labels, and visibility flags based on the form type and player values.
// @fnv 0x00728da0
void SelfObj::FUN_00728da0(TESForm* apForm, MenuTileList* apTiles)
{
    char j[16];
    {
        float qfTOqo;
        unsigned int qsSDDgz;
        TileObj* qrEZrs[12];
        float qpqRa;
        int qSVM;
        float qdqWL;
        float qpTd;
        int qvyWyw;
        int qHXYKT;
        int qbGYp;
        void* qnuVZg;
        TESBoundObject* qSuoDt;
        {
            char strMod[128];
            float qkbsJ;
            void* qhxpxJd;
            void* qjXCGmG;
            qsSDDgz = 0;
            qHXYKT = TraitNameToID(str_0106ed20);
            qvyWyw = TraitNameToID(str_0106ed18);
            qSVM = 0x1009;
            qpqRa = 0.0f;
            qdqWL = 0.0f;
            qfTOqo = ComputeItemValue((float)FUN_0048e8a0(apForm), 1.0f);
            qpTd = FUN_0048ebc0(apForm, (int)FUN_004d1360((RecipeStatsPlayerView*)DAT_011dea3c));
            if (apForm && apTiles)
            {
                qjXCGmG = apTiles->links.FUN_00726070();
                qbGYp = 0;
                while (qjXCGmG != 0 && 12 > qbGYp)
                {
                    qrEZrs[qbGYp] = (TileObj*)(*(int*)apTiles->links.FUN_00683520(&qjXCGmG));
                    qbGYp += 1;
                }
                while (12 > qbGYp)
                {
                    qrEZrs[qbGYp] = 0;
                    qbGYp++;
                }
                switch (((RecipeStatsFormView*)apForm)->FUN_00401170())
                {
                case 0x28: {
                    unsigned int count30;
                    float local19;
                    int local31;
                    const char* local9;
                    int local_;
                    unsigned int local67;
                    int loaded;
                    unsigned char local10;
                    TESObjectWEAP* weapon4 = (TESObjectWEAP*)apForm;
                    int skillA = weapon4->GetField19C();
                    float damage_2;
                    damage_2 = 0.0f;
                    float localX = 0.0f;
                    float conditionalColorA = 1.0f;
                    localX = FUN_00645380(DAT_011dea3c ? &((RecipeStatsPlayerView*)DAT_011dea3c)->actorValues : 0,
                                          weapon4, conditionalColorA, 1, 0, 0, 0, -1, 0.0f, 0.0f, 0, 0, 0);
                    if (conditionalColorA <= 0.0f)
                    {
                        damage_2 = 0.0f;
                    }
                    else
                    {
                        damage_2 = GetWeaponDamage(weapon4, conditionalColorA, 0, 0);
                    }
                    char local2[128];
                    FUN_00406d00(local2, 0x80, str_01020764, (int)FUN_004bd510(localX, 1.0f));
                    qrEZrs[1]->FUN_00a01350(qvyWyw, local2, true);
                    DAT_011d8eac = (Tile*)qrEZrs[1];
                    count30 = (unsigned char)weapon4->FUN_00525b20(0, 0, 0);
                    if (count30 > 1)
                    {
                        local19 = damage_2 / (float)count30;
                        FUN_00406d00(local2, 0x80, str_0106ecf4, (double)local19, count30);
                    }
                    else
                    {
                        FUN_00406d00(local2, 0x80, str_01020764, (int)FUN_004bd510(damage_2, 1.0f));
                    }
                    qrEZrs[11]->FUN_00a01350(qvyWyw, local2, true);
                    DAT_011d8eb0 = (Tile*)qrEZrs[11];
                    qrEZrs[4]->FUN_00a012d0(qSVM, FUN_0040ebd0(conditionalColorA, 1.0f), true);
                    FUN_00406d00(local2, 0x80, str_01020764, skillA);
                    if (qrEZrs[10])
                    {
                        qrEZrs[10]->FUN_00a01350(qvyWyw, local2, true);
                    }
                    DAT_011d8eb4 = (Tile*)qrEZrs[10];
                    if (weapon4->FUN_00525980(0))
                    {
                        local31 = ((RecipeStatsPlayerView*)DAT_011dea3c)->FUN_008d8520()->v52();
                        local_ = ((RecipeStatsPlayerView*)DAT_011dea3c)->FUN_008d8520()->v53();
                        local9 = ((AmmoObj*)weapon4->FUN_00525980(0))->GetStringAtOffsetC4();
                        local67 = FUN_004bf220(DAT_011dea3c)->FUN_004c8f30(weapon4->FUN_00525980(0));
                        loaded = 0;
                        if (!local9 || *local9 == 0)
                        {
                            local9 = ((AmmoObj*)weapon4->FUN_00525980(0))->name.FUN_00408da0();
                        }
                        local10 = (weapon4->FUN_00709430(0) == 0.0) ? (unsigned char)0 : (unsigned char)1;
                        if (local10)
                        {
                            FUN_00406d00(local2, 0x80, str_01019f08, local9);
                        }
                        else
                        {
                            FUN_00406d00(local2, 0x80, str_0106ece8, local9, loaded, local67 - loaded);
                        }
                    }
                    else
                    {
                        FUN_00406d30(local2, 0x80, str_01047008);
                    }
                    qrEZrs[5]->FUN_00a01350(qHXYKT, local2, true);
                    qsSDDgz = 0xc3e;
                    break;
                }
                case 0x18:
                case 0x1a: {
                    char local14[128];
                    float local3 = 1.0f;
                    FUN_00406d00(
                        local14, 0x80, str_01020764,
                        (int)FUN_00476b20(FUN_00646360((int)((RecipeStatsArmorView*)apForm)->FUN_004be060(), local3)));
                    qrEZrs[0]->FUN_00a01350(qvyWyw, local14, true);
                    qsSDDgz = 0x1d;
                    break;
                }
                default:
                    qsSDDgz = 0xc;
                    break;
                }

                qnuVZg = 0;
                qSuoDt = dynamic_cast<TESBoundObject*>(apForm);
                qhxpxJd = FUN_004be330(qSuoDt);
                if (qhxpxJd && !((HolderObj*)qhxpxJd)->FUN_0040e210(4))
                {
                    qnuVZg = qhxpxJd ? &((HolderObj*)qhxpxJd)->m_24 : 0;
                }
                if (((RecipeStatsFormView*)apForm)->FUN_00401170() == 0x1d)
                {
                    qnuVZg = apForm ? &((RecipeStatsFormView*)apForm)->nameComponent : 0;
                }
                else if (((RecipeStatsFormView*)apForm)->FUN_00401170() == 0x2f)
                {
                    qnuVZg = qSuoDt ? &((RecipeStatsFormView*)qSuoDt)->nameComponent : 0;
                }
                else
                {
                    void* i = FUN_004be330(apForm);
                    if (i && !((HolderObj*)i)->FUN_0040e210(4))
                    {
                        qnuVZg = i ? &((HolderObj*)i)->m_24 : 0;
                    }
                }

                if (qnuVZg && *((NamedList*)qnuVZg)->entries.FUN_006815c0())
                {
                    char nameBuf[256];
                    ((ListHead*)qnuVZg)->BuildDescription(nameBuf, 0x100);
                    if (FUN_0044a670(nameBuf) > 0)
                    {
                        qrEZrs[6]->FUN_00a01350(qvyWyw, nameBuf, true);
                        qsSDDgz |= 0x40;
                    }
                    else
                    {
                        qsSDDgz &= ~0x40;
                    }
                }
                else
                {
                    qsSDDgz &= ~0x40;
                }

                if (qfTOqo > 0.0f)
                {
                    if (qfTOqo >= 1.0)
                    {
                        FUN_00406d00(j, 0x10, str_0106ecc8, (double)qfTOqo);
                    }
                    else
                    {
                        FUN_00406d00(j, 0x10, str_01020768, (double)qfTOqo);
                    }
                }
                else
                {
                    FUN_00406d30(j, 0x10, str_01047008);
                }
                qrEZrs[3]->FUN_00a01350(qvyWyw, j, true);

                if (qpTd > 0.0f)
                {
                    if (qpTd >= 1.0)
                    {
                        FUN_00406d00(j, 0x10, str_0106ecc8, (double)qpTd);
                    }
                    else
                    {
                        FUN_00406d00(j, 0x10, str_01020768, (double)qpTd);
                    }
                }
                else
                {
                    FUN_00406d30(j, 0x10, str_01047008);
                }
                qrEZrs[2]->FUN_00a01350(qvyWyw, j, true);

                qrEZrs[0]->FUN_00a01350(qHXYKT, DAT_011d20c4.FUN_00403df0(), true);
                qrEZrs[1]->FUN_00a01350(qHXYKT, DAT_011d412c.FUN_00403df0(), true);
                qrEZrs[11]->FUN_00a01350(qHXYKT, DAT_011d2c7c.FUN_00403df0(), true);
                qrEZrs[2]->FUN_00a01350(qHXYKT, DAT_011d2aa8.FUN_00403df0(), true);
                qrEZrs[3]->FUN_00a01350(qHXYKT, DAT_011d26a0.FUN_00403df0(), true);
                qrEZrs[4]->FUN_00a01350(qHXYKT, DAT_011d4da4.FUN_00403df0(), true);
                qrEZrs[6]->FUN_00a01350(qHXYKT, DAT_011d4edc.FUN_00403df0(), true);
                qrEZrs[7]->FUN_00a01350(qHXYKT, DAT_011d4024.FUN_00403df0(), true);
                qrEZrs[10]->FUN_00a01350(qHXYKT, DAT_011d330c.FUN_00403df0(), true);

                qrEZrs[0]->FUN_00700320(0xfa3, (qsSDDgz & 1) ? 1 : 0);
                qrEZrs[1]->FUN_00700320(0xfa3, (2 & qsSDDgz) ? 1 : 0);
                qrEZrs[11]->FUN_00700320(0xfa3, (qsSDDgz & 0x800) ? 1 : 0);
                qrEZrs[2]->FUN_00700320(0xfa3, (qsSDDgz & 4) ? 1 : 0);
                qrEZrs[3]->FUN_00700320(0xfa3, (8 & qsSDDgz) ? 1 : 0);
                qrEZrs[4]->FUN_00700320(0xfa3, (qsSDDgz & 0x10) ? 1 : 0);
                qrEZrs[5]->FUN_00700320(0xfa3, (qsSDDgz & 0x20) ? 1 : 0);
                qrEZrs[6]->FUN_00700320(0xfa3, (qsSDDgz & 0x40) ? 1 : 0);
                qrEZrs[7]->FUN_00700320(0xfa3, (qsSDDgz & 0x80) ? 1 : 0);
                qrEZrs[8]->FUN_00700320(0xfa3, (qsSDDgz & 0x100) ? 1 : 0);
                qrEZrs[9]->FUN_00700320(0xfa3, (qsSDDgz & 0x200) ? 1 : 0);

                if (qrEZrs[10])
                {
                    qrEZrs[10]->FUN_00700320(0xfa3, (qsSDDgz & 0x400) ? 1 : 0);
                    qrEZrs[10]->FUN_00a012d0(0xfa9, DAT_01023cd8, true);
                }

                qkbsJ = (float)(apTiles->FUN_00a011b0(0xfb0) / 2.0 - 20.0);
                if ((qsSDDgz & 0x10) || (qsSDDgz & 0x20))
                {
                    qkbsJ = qkbsJ * 2.0f;
                }
                qrEZrs[6]->FUN_00a012d0(0xfa2, qkbsJ, true);
                qrEZrs[7]->FUN_00a012d0(0xfa2, qkbsJ, true);
                qrEZrs[8]->FUN_00a012d0(0xfa2, qkbsJ + qpqRa, true);
                qrEZrs[9]->FUN_00a012d0(0xfa2, qkbsJ + qdqWL, true);
            }
        }
    }
}
