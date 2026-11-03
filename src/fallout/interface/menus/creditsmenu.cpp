
// src/fallout/interface/menus/creditsmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/creditsmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct CreditsMenu
{
    virtual ~CreditsMenu();  // polymorphic: its RTTI is used (rtti_fix.py)
    int FUN_0075f1c0();
};

// @fnv 0x0075f1c0
int CreditsMenu::FUN_0075f1c0()
{
    return 0x417;
}

struct Tile;

struct FUN_0075f8e0
{
    char m[0x28];
    Tile* m_pFirstTile;
    Tile* m_pSecondTile;

    void AssignTileByID(int aiID, Tile* apTile);
};

// Stores apTile into the slot selected by aiID: slot 1 for ID 1, slot 0 for ID 0.
// @fnv 0x0075f8e0
void FUN_0075f8e0::AssignTileByID(int aiID, Tile* apTile)
{
    if (aiID == 1)
    {
        m_pFirstTile = apTile;
    }
    else if (aiID == 0)
    {
        m_pSecondTile = apTile;
    }
}

// placeholder declarations
void __cdecl FUN_0075f600(void);
struct SM7d6
{
    void __thiscall FUN_0075f6f0(int, int);
};
char __cdecl ConsumeByteAtE4(void);
void __cdecl FUN_00761460(bool);
void __cdecl FUN_008304f0(void);
struct FUN_008467b0_shell
{
    bool __thiscall LoadSaveEntry(void);
};
extern int DAT_011d9474;
extern SM7d6* DAT_011daac0;

// @fnv 0x00761410
void __cdecl FUN_00761410()
{
    FUN_0075f600();
    DAT_011daac0->FUN_0075f6f0(0x40000000, 0);
    if (!ConsumeByteAtE4())
    {
        if (DAT_011d9474 != 0)
        {
            FUN_00761460(false);
            FUN_008304f0();
            ((FUN_008467b0_shell*)DAT_011d9474)->LoadSaveEntry();
        }
    }
}

extern unsigned char DAT_011dcfa5;

// @fnv 0x00761460
void FUN_00761460(unsigned char value)
{
    DAT_011dcfa5 = value;
}

struct StandIn_75f1d0
{
    void FUN_0075f200();
    void* FUN_0075f1d0(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_0075f200, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0075f1d0
void* StandIn_75f1d0::FUN_0075f1d0(unsigned int flags)
{
    FUN_0075f200();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int EmptyFS;

struct FUN_007613f0_shell
{
    int* __thiscall FUN_007613f0();
};

// @fnv 0x007613f0
int* __thiscall FUN_007613f0_shell::FUN_007613f0()
{
    *(int*)this = EmptyFS;
    return (int*)this;
}

extern int DAT_01072514;
struct FUN_007616d0_shell
{
    void __thiscall InitializeBuffer(int, int);
};
struct FUN_00761470_shell
{
    FUN_00761470_shell* __thiscall Construct();
};
// @fnv 0x00761470
FUN_00761470_shell* __thiscall FUN_00761470_shell::Construct()
{
    *reinterpret_cast<int**>(this) = &DAT_01072514;
    reinterpret_cast<FUN_007616d0_shell*>(this)->InitializeBuffer(0, 0);
    return this;
}

struct FUN_00760b40_shell
{
    char pad[0x34];
    unsigned int m_34;
    int m_38;
    char* m_3c;
    void AdvanceToNewline();
};

// Advances m_34 while the byte at m_3c[m_34] is not 0xa and m_34 is less than m_38.
// @fnv 0x00760b40
void FUN_00760b40_shell::AdvanceToNewline()
{
    while (m_3c[m_34] != 0xa && m_34 < m_38)
        m_34++;
}

struct FUN_00760b80_shell
{
    char _pad[0x34];
    unsigned int m34;
    unsigned int m38;
    char* m3c;
    void FUN_00760b80();
};
// @fnv 0x00760b80
void FUN_00760b80_shell::FUN_00760b80()
{
    while (m3c[m34++] != '>')
    {
        if (m34 >= m38)
            break;
    }
}

struct S_0075f200_Base
{
    virtual void vfn_00();
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
    ~S_0075f200_Base();
};
struct S_0075f200_M30
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
    ~S_0075f200_M30();
};
struct S_0075f200_M60
{
    int unk00;
    ~S_0075f200_M60();
};
struct S_0075f200_Tile
{
    int unk00;
    void FUN_0046dce0(float f);
};
struct S_0075f200_Mgr
{
    int unk00;
    void FUN_007d6c90();
};
extern S_0075f200_Tile* DAT_011c3f3c;

struct FUN_0075f200 : S_0075f200_Base
{
    S_0075f200_M30 unk30;
    S_0075f200_M60 unk60;
    ~FUN_0075f200();
};

// @fnv 0x0075f200
FUN_0075f200::~FUN_0075f200()
{
    DAT_011c3f3c->FUN_0046dce0(0.0f);
    if (DAT_011daac0)
        ((S_0075f200_Mgr*)DAT_011daac0)->FUN_007d6c90();
}

struct CallbackTarget
{
    virtual void unk_vf_00();
    virtual void unk_vf_01();
    virtual void unk_vf_02();
    virtual void unk_vf_03();
    virtual void unk_vf_04();
    virtual void unk_vf_05();
    virtual void unk_vf_06();
    virtual void unk_vf_07();
    virtual void unk_vf_08();
    virtual void unk_vf_09();
    virtual void unk_vf_10();
    virtual void unk_vf_11();
    virtual void unk_vf_12();
    virtual void unk_vf_13();
    virtual void unk_vf_14();
    virtual void unk_vf_15();
    virtual void unk_vf_16();
    virtual void unk_vf_17();
    virtual void unk_vf_18();
    virtual void unk_vf_19();
    virtual void unk_vf_20();
    virtual void unk_vf_21();
    virtual void unk_vf_22();
    virtual void unk_vf_23();
    virtual void unk_vf_24();
    virtual void unk_vf_25();
    virtual void unk_vf_26();
    virtual void unk_vf_27();
    virtual void unk_vf_28();
    virtual void unk_vf_29();
    virtual void unk_vf_30();
    virtual void unk_vf_31();
    virtual void unk_vf_32();
    virtual void unk_vf_33();
    virtual void unk_vf_34();
    virtual void unk_vf_35();
    virtual void unk_vf_36();
    virtual void unk_vf_37();
    virtual void unk_vf_38();
    virtual void unk_vf_39();
    virtual void unk_vf_40();
    virtual void unk_vf_41();
    virtual void unk_vf_42();
    virtual void unk_vf_43();
    virtual void unk_vf_44();
    virtual void unk_vf_45();
    virtual void unk_vf_46();
    virtual void unk_vf_47();
    virtual void unk_vf_48();
    virtual void unk_vf_49();
    virtual void unk_vf_50();
    virtual void unk_vf_51();
    virtual void unk_vf_52();
    virtual void unk_vf_53();
    virtual void unk_vf_54();
    virtual void unk_vf_55();
    virtual void unk_vf_56();
    virtual void unk_vf_57();
    virtual void HandleValue(void*);
};
struct ValueSource
{
    CallbackTarget* FUN_009611e0();
};
struct InputState
{
    bool FUN_0052aa80(int);
    ValueSource* FUN_00559450();
    void FUN_0066b0d0(int);
};
struct Screen
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
    InputState input;
    void FUN_00a1d910();
};
struct Menu
{
    virtual ~Menu();  // polymorphic: its RTTI is used (rtti_fix.py)
    Screen* FUN_00a03c90();
    void FUN_00700320(int, int);
};
struct GlobalView
{
    void FUN_004a0370();
    void FUN_004a03c0();
};
extern SM7d6* DAT_011daac0;
Menu* __cdecl FUN_00a09030(int);
GlobalView* __cdecl FUN_004bc3f0();

// @fnv 0x0075f600
void __cdecl FUN_0075f600()
{
    Menu* menu = FUN_00a09030(0x417);
    if (menu == 0)
        return;
    {
        Screen* screen = menu->FUN_00a03c90();
        if (screen != 0)
        {
            FUN_004bc3f0()->FUN_004a0370();
            if (screen->input.FUN_0052aa80(0))
            {
                if (screen->input.FUN_00559450()->FUN_009611e0() != 0)
                {
                    CallbackTarget* pCallbackTarget = screen->input.FUN_00559450()->FUN_009611e0();
                    pCallbackTarget->HandleValue(screen->input.FUN_00559450());
                }
            }
            screen->input.FUN_0066b0d0(0);
            menu->FUN_00700320(0x1772, 1);
            screen->FUN_00a1d910();
            FUN_004bc3f0()->FUN_004a03c0();
        }
        DAT_011daac0->FUN_0075f6f0(0x2000000, 1);
    }
}

struct NiPoint3
{
    float x;
    float y;
    float z;
};
struct NiBound
{
    float GetRadius() const;
};
struct NiUpdateData
{
    NiUpdateData(float afTime, bool abUpdateControllers, bool abIsMultiThreaded);
    int unk00;
    int unk04;
    int unk08;
};
struct NiNode
{
    NiPoint3& GetLocalTranslate();
    void SetLocalTranslate(const NiPoint3& arPos);
    void Update(NiUpdateData& arData);
    const NiBound& GetBoundingVolume() const;
};
struct NiNodePtr
{
    operator NiNode*() const;
    NiNode* operator->() const;
    NiNode* m_pObject;
};
struct NiFixedString
{
    operator const char*() const;
    const char* m_kHandle;
};
struct NiFixedStringArray
{
    unsigned int GetSize();
    NiFixedString& GetAt(unsigned int auiIndex);
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
struct Tile
{
    virtual ~Tile();  // polymorphic: its RTTI is used (rtti_fix.py)
    void Set(int aiID, int aiValue);
    void Set(int aiID, const char* apStr, bool abPropagate);
};
struct InputManager
{
    int FUN_00a23a50(int, int);
    int FUN_00a24660(int, int);
};
struct OSGlobals
{
    InputManager* GetInputManager();
};
struct TimeGlobal
{
    float GetMovementDelta();
};
struct SettingF
{
    float* Float();
};

extern OSGlobals* g_osGlobals;
extern TimeGlobal g_timeGlobal;
extern SettingF g_creditsScrollSpeed;
extern unsigned char g_creditsActive;

bool __cdecl FUN_00702680(int aiMenu, unsigned int auiFlags);
int __cdecl FUN_00717a40(int, int);
void __cdecl CheckSaveNameConflict();

struct CreditsMenuX
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
    Tile* m_pFirstTile;
    Tile* m_pCurrentLineTile;
    NiNodePtr m_pController;
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
    NiFixedStringArray kLines;
    float fLineDelay;
    float m_fPackageValue;
    unsigned int uiLineIndex;

    void FUN_0075f910();
};

// @fnv 0x0075f910
void CreditsMenuX::FUN_0075f910()
{
    InputManager* pInput5 = g_osGlobals->GetInputManager();
    if (FUN_00702680(0x3e9, 0))
    {
        m_pFirstTile->Set(0xfad, 0);
        m_pFirstTile->Set(0xfa3, 0);
        g_creditsActive = 1;
        return;
    }
    else if (g_creditsActive)
    {
        g_creditsActive = 0;
        CheckSaveNameConflict();
    }
    if (pInput5->FUN_00a23a50(0, 1) || pInput5->FUN_00a24660(0x1c, 1) || FUN_00717a40(9, 1) == 2)
        CheckSaveNameConflict();
    if (!m_pController)
        return;
    if (kLines.GetSize())
    {
        m_fPackageValue -= g_timeGlobal.GetMovementDelta();
        if (m_fPackageValue < 0.0 && uiLineIndex < kLines.GetSize())
        {
            m_pCurrentLineTile->Set(0xfcc, kLines.GetAt(uiLineIndex++), true);
            m_fPackageValue = fLineDelay;
        }
    }
    NiPoint3 kPos = m_pController->GetLocalTranslate();
    kPos.z += *g_creditsScrollSpeed.Float() * g_timeGlobal.GetMovementDelta();
    m_pController->SetLocalTranslate(kPos);
    NiUpdateData kData(0.0f, false, false);
    m_pController->Update(kData);
    float fHeight4 = m_pController->GetBoundingVolume().GetRadius() * 2.0;
    if (kPos.z > fHeight4)
        CheckSaveNameConflict();
}

bool __cdecl FUN_00702450(int iMenu);
bool __cdecl B75FB30IsMenuVisible(int iMenu);
void __cdecl CheckSaveNameConflict();

class B75FB30Menu
{
  public:
    bool IsKeyHandled(int iKey, int iUnused);
};

// @fnv 0x0075fb30
bool B75FB30Menu::IsKeyHandled(int iKey, int iUnused)
{
    switch (iKey)
    {
    case -1:
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        return false;
    default:
        if (FUN_00702450(0x417) && !B75FB30IsMenuVisible(0x3e9))
        {
            CheckSaveNameConflict();
            return true;
        }
        return false;
    }
}

struct OutputA
{
    void FUN_004037f0(const char*, bool);
};
struct HostA
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
    unsigned int index;
    unsigned int length;
    char* text;
    void WriteTextUntilDelimiter(OutputA*);
};
// @fnv 0x00760bd0
void HostA::WriteTextUntilDelimiter(OutputA* output)
{
    char ch = text[index];
    int i = 0;
    char buffer[260];
    while (ch != 13 && ch != '<' && ch != '>' && ch != '*' && index < length)
    {
        buffer[i] = ch;
        i++;
        index++;
        if (index < length)
            ch = text[index];
    }
    buffer[i] = 0;
    output->FUN_004037f0(buffer, false);
}

namespace n75f750 {

struct TESGlobalX
{
    void FUN_0046dce0(float afValue);
};
struct StartMenuX
{
    bool FUN_004a4080(int aeFlag);
};
struct StrHolder
{
    const char* FUN_00559450();
};
struct ValueReferencePair
{
    bool FUN_00846b10();
    char* FUN_0075f8c0();
    const char* FUN_00559450();
};
struct SaveNode
{
    SaveNode* FUN_00559450();
    ValueReferencePair** FUN_006815c0();
    SaveNode* FUN_00726070();
};
struct SaveMgr
{
    SaveNode* FUN_00559450();
    void FUN_00851330();
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
    StrHolder kName;
};
struct SettingGS
{
    const char* FUN_00403df0();
};
struct SettingStr
{
    const char* FUN_004c69f0();
};

}

using namespace n75f750;

extern SaveMgr* DAT_011de134;
extern SettingGS DAT_011d3684;
extern SettingGS DAT_011d34f8;
extern SettingStr DAT_011d39b4;
unsigned int __cdecl FUN_0044a670(const char* apString);
int __cdecl FUN_004b75a0(const char* apA, const char* apB);
void __cdecl ShowMessageBox(const char* apMessage, int a2, int a3, void(__cdecl* apCallback)(), int a5, int a6, float a7,
                          float a8, const char* apButton1, const char* apButton2, int a11);

// Checks the save name against listed entries, shows a dialog on a match, and otherwise calls two follow-up functions.
// @fnv 0x0075f750
void __cdecl CheckSaveNameConflict()
{
    ((TESGlobalX*)DAT_011c3f3c)->FUN_0046dce0(0.0f);
    if (((StartMenuX*)DAT_011daac0)->FUN_004a4080(0x40000000) && FUN_0044a670(DAT_011de134->kName.FUN_00559450()))
    {
        DAT_011de134->FUN_00851330();
        if (DAT_011de134 && DAT_011de134->FUN_00559450())
        {
            SaveNode* pkNode = DAT_011de134->FUN_00559450();
            while (pkNode && *pkNode->FUN_006815c0())
            {
                DAT_011d9474 = (int)*pkNode->FUN_006815c0();
                if (((ValueReferencePair*)DAT_011d9474)->FUN_00846b10() &&
                    ((ValueReferencePair*)DAT_011d9474)->FUN_0075f8c0() &&
                    FUN_004b75a0(DAT_011de134->kName.FUN_00559450(),
                                 ((ValueReferencePair*)DAT_011d9474)->FUN_00559450()))
                {
                    ShowMessageBox(DAT_011d39b4.FUN_004c69f0(), 0, 0, FUN_00761410, 0, 0x12, 0.0f, 0.0f,
                                 DAT_011d34f8.FUN_00403df0(), DAT_011d3684.FUN_00403df0(), 0);
                    return;
                }
                pkNode = pkNode->FUN_00726070();
            }
        }
    }
    DAT_011daac0->FUN_0075f6f0(0x40000000, 0);
    FUN_0075f600();
}

struct CreditVertex
{
    float x, y, z;
    CreditVertex();
    CreditVertex(float afX, float afY, float afZ);
};

struct CreditTexCoord
{
    float u, v;
    CreditTexCoord();
    CreditTexCoord(float afU, float afV);
};

struct CreditFixedString
{
    const char* m_kHandle;
    CreditFixedString();
    CreditFixedString(const char* apString);
    ~CreditFixedString();
};

struct CreditMemObject
{
    static void* operator new(unsigned int auiSize);
    static void operator delete(void* apMem, unsigned int);
};

struct CreditProperty : CreditMemObject
{
    CreditProperty();
    char data[0x1c];
    void FUN_0049ed90(int aiMode);
};

struct CreditTexture;

struct CreditTextureEffect : CreditMemObject
{
    CreditTextureEffect(int aiType);
    char data[0xb0];
    void FUN_00bb7a10(CreditTexture* apTexture);
    void FUN_00821600(float afScroll);
};

struct CreditAlphaProperty : CreditMemObject
{
    CreditAlphaProperty();
    char data[0x4c];
    void FUN_004bc450(void* apKey);
    void FUN_004534f0(void* apKey);
};

struct CreditGeometryData
{
    void ComputeBoundingSphere();
};

struct CreditShape : CreditMemObject
{
    CreditShape(unsigned short ausVertices, CreditVertex* apVertices, void* apNormals, void* apColors,
                CreditTexCoord* apTexCoords, unsigned short ausTexSets, int aeNBT, unsigned short ausTriangles,
                unsigned short* apTriList);
    char data[0xc4];
    void AssignFixedString(const CreditFixedString& arName);
    void FUN_00439410(void* apProperty);
    CreditGeometryData* GetSourceFilesFromForm(int aiFlags, CreditVertex* apVertices);
};

struct CreditNode : CreditMemObject
{
    CreditNode(int aiChildren);
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
    virtual void AttachChildInAvailableSlot(CreditShape* apChild, bool abFirstAvail);
    char data[0xa8];
    void FUN_004bc1f0(float afX, float afY, float afZ);
    void FUN_00439410(void* apProperty);
};

struct CreditTextureSource
{
    const char* FUN_00559450();
};

extern char DAT_011a9598;
extern char DAT_011a9b7c;
void* __cdecl FUN_00aa1070(unsigned int auiSize);
int __cdecl FUN_00406d00(char* apBuffer, unsigned int auiSize, const char* apFormat, ...);
CreditTexture* __cdecl FUN_00a5fd70(const CreditFixedString& arName, void* apPrefs, bool abLoadDirectly, int aiFlags);
void __cdecl FUN_00b57e30(CreditNode* apNode, int aiFlags, bool abRecurse);

struct CreditsQuadRenderer
{
    char pad00[0x44];
    int iAlignment;
    int iX;
    int iY;

    CreditNode* FUN_00760cf0(CreditTextureSource* apSource, int aiWidth, int aiHeight, float afScroll);
};

// Builds a CreditNode with a textured quad shape, applies alignment, texture, scroll effect, and alpha properties, then returns the node.
// @fnv 0x00760cf0
CreditNode* CreditsQuadRenderer::FUN_00760cf0(CreditTextureSource* apSource, int aiWidth, int aiHeight, float afScroll)
{
    CreditVertex* pVerticesTmp = new CreditVertex[4];
    CreditTexCoord* pTexCoordsRef = new CreditTexCoord[4];
    unsigned short* pTriList = (unsigned short*)FUN_00aa1070(12);

    pVerticesTmp[0] = CreditVertex(0.0f, 0.01f, 0.0f);
    pVerticesTmp[1] = CreditVertex(0.0f, 0.01f, (float)-aiHeight);
    pVerticesTmp[2] = CreditVertex((float)aiWidth, 0.01f, 0.0f);
    pVerticesTmp[3] = CreditVertex((float)aiWidth, 0.01f, (float)-aiHeight);

    pTexCoordsRef[0] = CreditTexCoord(0.0f, 0.0f);
    pTexCoordsRef[1] = CreditTexCoord(0.0f, 1.0f);
    pTexCoordsRef[2] = CreditTexCoord(1.0f, 0.0f);
    pTexCoordsRef[3] = CreditTexCoord(1.0f, 1.0f);

    pTriList[0] = 0;
    pTriList[1] = 1;
    pTriList[2] = 2;
    pTriList[3] = 2;
    pTriList[4] = 1;
    pTriList[5] = 3;

    CreditNode* pNodeCur = new CreditNode(0);
    int iX = this->iX;
    if (iAlignment == 2)
        iX -= aiWidth / 2;
    else if (iAlignment == 4)
        iX -= aiWidth;
    pNodeCur->FUN_004bc1f0((float)iX, 0.0f, (float)iY);

    CreditProperty* pProperty = new CreditProperty();
    pProperty->FUN_0049ed90(1);
    pNodeCur->FUN_00439410(pProperty);

    CreditShape* pShapeCur = new CreditShape(4, pVerticesTmp, 0, 0, pTexCoordsRef, 1, 0, 2, pTriList);
    pNodeCur->AttachChildInAvailableSlot(pShapeCur, true);

    CreditFixedString kNameNew;
    char acPathCur[260];
    FUN_00406d00(acPathCur, 260, "Textures\\Interface\\Credits\\%s", apSource->FUN_00559450());
    pShapeCur->AssignFixedString(CreditFixedString(acPathCur));
    CreditTexture* pTextureOld = FUN_00a5fd70(CreditFixedString(acPathCur), &DAT_011a9598, true, 0);

    CreditTextureEffect* pEffectInfo = new CreditTextureEffect(0);
    pEffectInfo->FUN_00bb7a10(pTextureOld);
    pEffectInfo->FUN_00821600(afScroll);
    pShapeCur->FUN_00439410(pEffectInfo);

    CreditAlphaProperty* pAlpha = new CreditAlphaProperty();
    pAlpha->FUN_004bc450(&DAT_011a9b7c);
    pAlpha->FUN_004534f0(&DAT_011a9b7c);
    pShapeCur->FUN_00439410(pAlpha);

    pShapeCur->GetSourceFilesFromForm(4, pVerticesTmp)->ComputeBoundingSphere();
    FUN_00b57e30(pNodeCur, 0, true);
    return pNodeCur;
}

void* FUN_00ec61c0(void*, int, unsigned int);
struct CreditPathPrefix
{
    char text[6];
};
class TESForm
{
  public:
    virtual ~TESForm();
};
class BGSPerk : public TESForm
{
};
struct CreditInput
{
    int FUN_00a24180(int, int);
};
struct CreditInputManager
{
    CreditInput* FUN_00877720();
};
struct CreditPlayer
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual bool HasPerk(BGSPerk*, int);
};
struct CreditGlobal
{
    float FUN_00526ac0();
};
extern CreditInputManager* DAT_011dea0c;
extern CreditPlayer* DAT_011dea3c;
TESForm* LookupFormByID(unsigned int);
int FUN_004b7220();
const char* FUN_004b7650(int);
void FUN_00406d50(char*, unsigned int, const char*);
void FUN_00406d30(char*, unsigned int, const char*);
extern char DAT_01013444[], DAT_010724d4[], DAT_010724c8[], DAT_010724b0[], DAT_0107249c[], DAT_01072484[],
    DAT_01072470[], DAT_01072454[], DAT_0107243c[], DAT_010724e8[], DAT_01072420[];
struct CreditFile
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
    virtual unsigned int Length();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual bool Valid();
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
    CreditFile(const char*, int, int, int);
    ~CreditFile();
    bool FUN_00affc60();
    unsigned int ReadBytes(char*, unsigned int);
};
struct CreditString
{
    char* data;
    unsigned int size;
    CreditString();
    ~CreditString();
    const char* FUN_00559450();
};
struct CreditTextureName
{
    const char* data;
    CreditTextureName(const char*);
    ~CreditTextureName();
};
struct CreditPoint
{
    float x, y, z;
    CreditPoint(float, float, float);
};
struct CreditUpdate
{
    float time;
    int flags;
    int unk08;
    CreditUpdate(float, int, int);
};
struct CreditMaterial
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    CreditMaterial();
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    void FUN_0049ed90(bool);
};
struct CreditSceneNode
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
    virtual void Attach(CreditSceneNode*, bool);
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
    CreditSceneNode(int);
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    void FUN_00440460(const CreditPoint&);
    void FUN_00439410(CreditMaterial*);
    void FUN_004bc1f0(float, float, float);
    void FUN_00a29680();
    void FUN_00a59c60(const CreditUpdate&);
};
void* FUN_00aa13e0(unsigned int);
void FUN_00aa13f0(void*);
__forceinline void* CreditSceneNode::operator new(unsigned int n)
{
    return FUN_00aa13e0(n);
}
__forceinline void CreditSceneNode::operator delete(void* p, unsigned int)
{
    FUN_00aa13f0(p);
}
__forceinline void* CreditMaterial::operator new(unsigned int n)
{
    return FUN_00aa13e0(n);
}
__forceinline void CreditMaterial::operator delete(void* p, unsigned int)
{
    FUN_00aa13f0(p);
}
struct CreditNodePtr
{
    CreditSceneNode* data;
    void FUN_0066b0d0(CreditSceneNode*);
    CreditSceneNode* FUN_00559450();
};
struct CreditTile
{
    CreditSceneNode* FUN_0056c7f0();
};

struct CreditColor
{
    float r, g, b, a;
};
struct CreditFont
{
    float FUN_00759450();
    CreditSceneNode* FUN_00a12460(float, float, float, const CreditString&, unsigned int*, int, const CreditColor&,
                                  bool, bool);
};
struct CreditFontManager
{
    CreditFont* FUN_005bd5c0();
};
CreditFontManager* __stdcall FUN_005bd5b0(int);
struct CreditBackgrounds
{
    void FUN_007614c0(const CreditTextureName&);
};
int FUN_00eca6d3(const char*);
void FUN_00406f60(CreditString*, const char*, ...);
void FUN_00b57e30(CreditSceneNode*, int, int);
struct CreditMenu
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
    CreditTile* tile;
    CreditTile* background;
    CreditNodePtr root;
    unsigned int cursor, length;
    char* buffer;
    int font, align, x, y;
    CreditColor color;
    CreditBackgrounds backgrounds;
    int unk64, unk68, unk6c;
    int height;
    void FUN_0075fb90();
    void AdvanceToNewline();
    void FUN_00760b80();
    void WriteTextUntilDelimiter(CreditString&);
    CreditSceneNode* FUN_00760cf0(const CreditString&, int, int, float);
};
// Reads a credit text file, parses markup tags for position, font, color, images and backgrounds, and builds the credit scene node graph.
// @fnv 0x0075fb90
void CreditMenu::FUN_0075fb90()
{
    CreditInput* input9 = DAT_011dea0c->FUN_00877720();
    BGSPerk* perk3 = dynamic_cast<BGSPerk*>(LookupFormByID(0xed568));
    bool wacky = input9->FUN_00a24180(0x1d, 0) || input9->FUN_00a24180(0x9d, 0) || DAT_011dea3c->HasPerk(perk3, 0);
    if (DAT_011c3f3c && reinterpret_cast<CreditGlobal*>(DAT_011c3f3c)->FUN_00526ac0() == 2.0)
        wacky = true;
    char path_40[260];
    reinterpret_cast<CreditPathPrefix&>(path_40) = *reinterpret_cast<const CreditPathPrefix*>(DAT_010724e8);
    FUN_00ec61c0(path_40 + 6, 0, 254);
    int language6 = FUN_004b7220();
    FUN_00406d50(path_40, 260, FUN_004b7650(language6));
    FUN_00406d50(path_40, 260, DAT_01013444);
    FUN_00406d50(path_40, 260, wacky ? DAT_010724d4 : DAT_010724c8);
    CreditFile local(path_40, 0, 0x4000, 0);
    CreditFile fallback(wacky ? DAT_010724b0 : DAT_0107249c, 0, 0x4000, 0);
    FUN_00406d30(path_40, 260, DAT_010724e8);
    FUN_00406d50(path_40, 260, FUN_004b7650(language6));
    FUN_00406d50(path_40, 260, DAT_01013444);
    FUN_00406d50(path_40, 260, wacky ? DAT_01072484 : DAT_01072470);
    CreditFile localExtra(path_40, 0, 0x4000, 0);
    CreditFile fallbackExtraA(wacky ? DAT_01072454 : DAT_0107243c, 0, 0x4000, 0);
    CreditFile* selected_0;
    if (local.FUN_00affc60())
        selected_0 = localExtra.FUN_00affc60() ? &localExtra : &local;
    else
        selected_0 = fallbackExtraA.FUN_00affc60() ? &fallbackExtraA : &fallback;
    if (!selected_0 || !selected_0->Valid())
        return;
    length = selected_0->Length() + 1;
    buffer = new char[length];
    buffer[length - 1] = 0;
    if (selected_0->ReadBytes(buffer, length - 1) != length - 1)
    {
        delete[] buffer;
        buffer = 0;
        return;
    }
    root.FUN_0066b0d0(new CreditSceneNode(0));
    root.FUN_00559450()->FUN_00440460(CreditPoint(0.0f, 0.0f, -1020.0f));
    FUN_004bc3f0()->FUN_004a0370();
    tile->FUN_0056c7f0()->Attach(root.FUN_00559450(), true);
    CreditMaterial* material6 = new CreditMaterial;
    material6->FUN_0049ed90(true);
    root.FUN_00559450()->FUN_00439410(material6);
    CreditFont* face8 = FUN_005bd5b0(font)->FUN_005bd5c0();
    CreditString token_10;
    while (cursor < length)
    {
        if (buffer[cursor] == '\r')
        {
            y -= (int)face8->FUN_00759450();
            height += (int)face8->FUN_00759450();
        }
        while (buffer[cursor] != '\n' && cursor < length)
        {
            switch (buffer[cursor])
            {
            case '*':
                AdvanceToNewline();
                break;
            case '<':
                ++cursor;
                switch ((int)buffer[cursor])
                {
                case 'X':
                    if (buffer[cursor + 2] == '+')
                        x += FUN_00eca6d3(&buffer[cursor + 3]);
                    else if (buffer[cursor + 2] == '-')
                        x -= FUN_00eca6d3(&buffer[cursor + 3]);
                    else
                        x = FUN_00eca6d3(&buffer[cursor + 2]);
                    break;
                case 'Y':
                    if (buffer[cursor + 2] == '+')
                        y -= FUN_00eca6d3(&buffer[cursor + 3]);
                    else if (buffer[cursor + 2] == '-')
                        y += FUN_00eca6d3(&buffer[cursor + 3]);
                    else
                        y = FUN_00eca6d3(&buffer[cursor + 2]);
                    break;
                case 'I': {
                    int imageWidth7 = FUN_00eca6d3(&buffer[cursor + 2]);
                    int imageHeight = FUN_00eca6d3(&buffer[cursor + 7]);
                    float alpha_11 = FUN_00eca6d3(&buffer[cursor + 12]) / 255.0;
                    cursor += 16;
                    WriteTextUntilDelimiter(token_10);
                    CreditSceneNode* image6 = FUN_00760cf0(token_10, imageWidth7, imageHeight, alpha_11);
                    root.FUN_00559450()->Attach(image6, true);
                    y -= imageHeight;
                    height += imageHeight;
                    break;
                }
                case 'J':
                    if (buffer[cursor + 2] == 'C')
                        align = 2;
                    else if (buffer[cursor + 2] == 'R')
                        align = 4;
                    else
                        align = 1;
                    break;
                case 'F':
                    font = buffer[cursor + 2] - '1';
                    face8 = FUN_005bd5b0(font)->FUN_005bd5c0();
                    break;
                case 'C':
                    color.r = FUN_00eca6d3(&buffer[cursor + 2]) / 255.0;
                    color.g = FUN_00eca6d3(&buffer[cursor + 6]) / 255.0;
                    color.b = FUN_00eca6d3(&buffer[cursor + 10]) / 255.0;
                    color.a = FUN_00eca6d3(&buffer[cursor + 14]) / 255.0;
                    break;
                case 'B': {
                    cursor += 2;
                    WriteTextUntilDelimiter(token_10);
                    CreditString texture;
                    FUN_00406f60(&texture, DAT_01072420, token_10);
                    backgrounds.FUN_007614c0(CreditTextureName(texture.FUN_00559450()));
                    break;
                }
                }
                FUN_00760b80();
                break;
            default: {
                if ((unsigned char)buffer[cursor] < 32)
                {
                    ++cursor;
                    break;
                }
                WriteTextUntilDelimiter(token_10);
                unsigned int options = 0x500;
                CreditSceneNode* text =
                    face8->FUN_00a12460(0.0f, 0.0f, 0.0f, token_10, &options, align, color, true, true);
                text->FUN_004bc1f0((float)x, 0.0f, (float)y);
                root.FUN_00559450()->Attach(text, true);
                y -= (int)face8->FUN_00759450();
                height += (int)face8->FUN_00759450();
                break;
            }
            }
        }
        AdvanceToNewline();
        ++cursor;
    }
    delete[] buffer;
    buffer = 0;
    FUN_00b57e30(root.FUN_00559450(), 0, 0);
    root.FUN_00559450()->FUN_00a29680();
    CreditUpdate update(0.0f, 0, 0);
    root.FUN_00559450()->FUN_00a59c60(update);
    FUN_004bc3f0()->FUN_004a03c0();
}

extern "C" const char DAT_0119f49c;
extern "C" const char DAT_0119f4cc;
extern "C" const char DAT_011a0034;
extern "C" const char DAT_0119f34c;
extern "C" unsigned char DAT_011d947c;
extern "C" void* __cdecl FUN_00ec43fb(void*, long, const void*, const void*, int);

namespace CreditsCreateDetail {

class CreditsCreateMenu;

class CreditsCreateTile
{
  public:
    virtual ~CreditsCreateTile();
    CreditsCreateTile* ReadFile(const char* apPath);
    CreditsCreateMenu* GetMenu();
    float FUN_00a011b0(int aiID);
    void Set(int aiID, float afVal, bool abPropagate);
    void Set(int aiID, int aiValue);
    void Set(int aiID, const char* apStr, bool abPropagate);
    NiNode* FUN_0056c7f0();
};

class CreditsCreateMenu
{
  public:
    virtual ~CreditsCreateMenu();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual int GetID();

    void FUN_00a1dc70(void* apTile, bool abFlag);
    int FUN_00726070();
};

struct CreditsCreateLineArray
{
    unsigned int GetSize();
    NiFixedString& GetAt(unsigned int auiIndex);
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class CreditsCreateState : public CreditsCreateMenu
{
  public:
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    CreditsCreateTile* m_pFirstTile;
    CreditsCreateTile* m_pCurrentLineTile;
    NiNodePtr m_pController;
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
    CreditsCreateLineArray kLines;
    unsigned int m_uiPlaybackFlags;
    float fLineDelay;
    float m_fPackageValue;
    unsigned int uiLineIndex;

    bool FUN_0073af60();
    void FUN_0075fb90();
};

struct CreditsCreateInterface
{
    CreditsCreateTile* FUN_00586150();
    bool FUN_007023a0();
};

CreditsCreateInterface* __cdecl FUN_004b7210();
float __cdecl FUN_00a01530();
int __cdecl FUN_0075f5f0();
void __cdecl FNV_Warning(const char* apFmt, ...);
int __cdecl FUN_004dc200();
int __cdecl FUN_004dc1f0();

}

// Creates the credits menu from credits_menu.xml, computes line scroll delay, and adjusts the first tile position for non-4:3 aspect ratios.
// @fnv 0x0075f2a0
bool __cdecl FUN_0075f2a0()
{
    using namespace CreditsCreateDetail;
    CreditsCreateMenu* pOldMenu5 = reinterpret_cast<CreditsCreateMenu*>(FUN_00a09030(0x417));
    if (pOldMenu5)
        delete pOldMenu5;

    CreditsCreateInterface* pIM = CreditsCreateDetail::FUN_004b7210();
    float fSafeZoneVal = CreditsCreateDetail::FUN_00a01530();
    CreditsCreateTile* pTileX = pIM->FUN_00586150()->ReadFile("Data\\Menus\\Options\\credits_menu.xml");
    CreditsCreateMenu* pMenu6 = pTileX->GetMenu();
    if (pMenu6 && pMenu6->GetID() == CreditsCreateDetail::FUN_0075f5f0())
    {
        pMenu6->FUN_00a1dc70(FUN_00ec43fb(pTileX, 0, &DAT_0119f4cc, &DAT_0119f49c, 0), false);
        CreditsCreateState* pCreditsMenu =
            reinterpret_cast<CreditsCreateState*>(FUN_00ec43fb(pMenu6, 0, &DAT_0119f34c, &DAT_011a0034, 0));
        if (!pCreditsMenu->FUN_0073af60())
        {
            CreditsCreateDetail::FNV_Warning(
                "Credits Menu Creation Failed... Are your menu and art resources up to date?");
            return false;
        }
        if (pTileX->FUN_00a011b0(0xfa7) == 6006.0 || pTileX->FUN_00a011b0(0xfa7) == 102.0)
        {
            pTileX->Set(0xfad, fSafeZoneVal, true);
        }
        pTileX->Set(0x1004, pIM->FUN_007023a0());
        pCreditsMenu->FUN_0075fb90();
        if (pCreditsMenu->kLines.GetSize())
        {
            pCreditsMenu->fLineDelay =
                ((double)pCreditsMenu->m_uiPlaybackFlags - pCreditsMenu->m_pController->GetLocalTranslate().z) /
                *g_creditsScrollSpeed.Float() / (double)pCreditsMenu->kLines.GetSize();
            pCreditsMenu->m_fPackageValue = pCreditsMenu->fLineDelay;
            pCreditsMenu->m_pCurrentLineTile->Set(0xfcc, pCreditsMenu->kLines.GetAt(pCreditsMenu->uiLineIndex++), true);
        }
        else if ((DAT_011d947c || !pCreditsMenu->kLines.GetSize()) && pCreditsMenu->m_pCurrentLineTile)
        {
            pCreditsMenu->m_pCurrentLineTile->Set(0xfa9, 0);
        }
        if ((double)CreditsCreateDetail::FUN_004dc200() / (double)CreditsCreateDetail::FUN_004dc1f0() != 0.75)
        {
            NiNode* pNode = pCreditsMenu->m_pFirstTile->FUN_0056c7f0();
            NiPoint3 kPos = pNode->GetLocalTranslate();
            kPos.x = (float)((double)kPos.x + 214.0);
            pNode->SetLocalTranslate(kPos);
            NiUpdateData kUpdate2(0.0f, false, false);
            pNode->Update(kUpdate2);
        }
        return true;
    }
    else if (pMenu6 && pMenu6->FUN_00726070())
    {
        delete pMenu6;
    }
    return false;
}
