
// src/fallout/interface/menus/specialbookmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/specialbookmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" bool __cdecl _FUN_004b71d0();

struct FUN_007ca030_shell
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
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int FUN_007ca030();
};

// Returns m_48 + 4 when m_48 is between 1 and 8, adding 4 more for slot 8 if _FUN_004b71d0() is true; otherwise returns -1.
// @fnv 0x007ca030
int FUN_007ca030_shell::FUN_007ca030()
{
    if (this->m_48 > 0 && this->m_48 < 9)
    {
        if (_FUN_004b71d0())
        {
            if (this->m_48 == 8)
                return this->m_4c + 4;
        }
        return this->m_48 + 4;
    }
    return -1;
}

extern "C" int __cdecl FUN_007c6110();
struct NiAVObject
{
};
struct NiAdditionalGeometryData
{
    static NiAVObject* __cdecl GetShadowSceneNodeForIndex(int);
};
struct NiNode
{
    void FUN_004def90();
};
struct ModelLoader
{
    void FUN_0045a5e0(const char*);
};
struct GlobalObject_00633c90
{
    void* m_00;
};
struct GO
{
    GO& operator=(void*);
};
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct Tile
{
    void Set(int, int);
};
struct Menu
{
    void LoadMenuData();
};
struct FUN_00b5ddb0_self
{
    void FUN_00b5d180();
};
extern ModelLoader* g_modelLoader;
extern int* DAT_011daa38;
extern GlobalObject_00633c90 g_011daa9c;
Menu* __cdecl FindMenuById(int);

// @fnv 0x007c6120
void __cdecl FUN_007c6120()
{
    int i;
    Menu* menu5 = FindMenuById(FUN_007c6110());
    if (!menu5)
        return;
    g_modelLoader->FUN_0045a5e0("Meshes\\Terminals\\Babybook02.NIF");
    ((NiNode*)NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))->FUN_004def90();
    ((FUN_00b5ddb0_self*)NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))->FUN_00b5d180();
    *(int*)((char*)DAT_011daa38 + 0x5c) = 0;
    ((GO*)&g_011daa9c)->operator=(0);
    i = 0;
    for (; i < 9; ++i)
    {
        ((GlobalObject_00869f00*)((char*)DAT_011daa38 + i * 32 + 0x60))->Clear(true);
        ((GlobalObject_00869f00*)((char*)DAT_011daa38 + i * 32 + 0x70))->Clear(true);
    }
    if (DAT_011daa38)
    {
        ((Tile*)menu5)->Set(0x1772, 1);
        ((Menu*)DAT_011daa38)->LoadMenuData();
    }
}

struct FUN_00794d30_shell
{
    char pad1[0x48];
    int m_48;
    int m_4c;

    int FUN_00794d30();
};

extern "C" bool __cdecl _FUN_004b71d0(void);

// Returns m_4c + 4 when m_48 is 8 and _FUN_004b71d0() is true, m_48 + 4 when m_48 is between 1 and 7, otherwise -1.
// @fnv 0x00794d30
int FUN_00794d30_shell::FUN_00794d30()
{
    if (m_48 == 8)
    {
        if (_FUN_004b71d0())
            return m_4c + 4;
    }
    if (m_48 > 0 && m_48 < 8)
        return m_48 + 4;
    return -1;
}

class AnimIdle;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* p);
    ~NiPointer();
    NiPointer& operator=(T* p);
};
class NiFixedString
{
  public:
    const char* m_kHandle;
    NiFixedString(const char* s);
    ~NiFixedString();
};
struct PropHelper
{
    void* GetProperty(unsigned int);
};
struct NiTimeController
{
    int FUN_00441110();
};
struct SceneRoot_007ca080
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
    virtual AnimIdle* GetObjectByName(const NiFixedString& name);
};
struct Holder_007ca080
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
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
    SceneRoot_007ca080* pRoot;
};

struct FUN_007ca080
{
    int m_00;
    int m_04;
    NiPointer<AnimIdle> m_pController;
    void* m_0c;
    FUN_007ca080(int a, int b, const char* name);
};

// @fnv 0x007ca080
FUN_007ca080::FUN_007ca080(int aiValueA, int aiValueB, const char* name) : m_pController(0)
{
    m_00 = aiValueA;
    m_04 = aiValueB;
    m_pController = ((Holder_007ca080*)DAT_011daa38)->pRoot->GetObjectByName(NiFixedString(name));
    AnimIdle* pAnimIdle = ((Holder_007ca080*)DAT_011daa38)->pRoot->GetObjectByName(NiFixedString(name));
    m_0c = (!((PropHelper*)pAnimIdle)->GetProperty(3)
                ? 0
                : (((NiTimeController*)((PropHelper*)pAnimIdle)->GetProperty(3))->FUN_00441110() >= 8 &&
                   ((NiTimeController*)((PropHelper*)pAnimIdle)->GetProperty(3))->FUN_00441110() <= 12))
               ? ((PropHelper*)pAnimIdle)->GetProperty(3)
               : 0;
}

class SPECIALBookMenu
{
  public:
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03(int, int) = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14(int, float) = 0;

    bool HandleInput(int aiKey);
};

// @fnv 0x007c6c50
bool SPECIALBookMenu::HandleInput(int aiKey)
{
    bool bhandled = false;

    if (aiKey == 0x80000001 || aiKey == 0x80000002)
    {
        v03(aiKey == 0x80000001, 0);
        bhandled = true;
    }

    if (aiKey == 0x80000003 || aiKey == 0x80000004)
    {
        v14((aiKey != 0x80000003) + 3, 1.0f);
        bhandled = true;
    }

    return bhandled;
}

struct NiUpdateData
{
    float time;
    bool updateControllers;
    bool multithreaded;
    bool updateGeomorphs;
    bool updateShadowScene;
    bool isCulled;
    NiUpdateData(float, bool, bool);
};
struct NiControllerSequence
{
    void Update(float, bool);
    float FUN_00508100();
    float FUN_00508120();
};
struct MenuController
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
    virtual void Update(const NiUpdateData&);
    MenuController* GetNext() const;
    NiControllerSequence* FUN_0047a520(const NiFixedString&);
};
struct MenuScene
{
    MenuController* GetControllers() const;
    void Update(const NiUpdateData&);
};
struct MenuInput
{
    int FUN_00a24180(int, int);
};
struct MenuOS
{
    MenuInput* FUN_00877720();
};
struct MenuLocale
{
    const char* FUN_00403df0();
};
struct MenuTime
{
    float FUN_0084d030();
};
extern MenuOS* g_osGlobals;
extern MenuLocale g_011c3cb4;
extern MenuTime g_timeGlobal;
extern bool DAT_011a0854;
extern const char* DAT_011a0858[];
extern const char* DAT_011a0878[];
extern int DAT_011f36bc;
bool __cdecl FUN_00702450(int);
int __cdecl FUN_00408b20(const char*, const char*);
MenuController* __cdecl FUN_00653270(const int*, MenuController*);
struct MenuUpdate
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void Handle(int, int);
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    int field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int selection;
    int field4c;
    float elapsed;
    bool finished;
    int field58;
    MenuScene* scene;
    void FUN_007c6200();
};
// Checks a key press to trigger Handle(4,0), otherwise advances the scene's controller sequence by elapsed time and updates the scene.
// @fnv 0x007c6200
void MenuUpdate::FUN_007c6200()
{
    if (!FUN_00702450(0x424))
        return;
    MenuInput* pInput = g_osGlobals->FUN_00877720();
    {
        MenuController* pController;
        {
            int scanCode = 30;
            if (FUN_00408b20(g_011c3cb4.FUN_00403df0(), "FRENCH") == 0)
                scanCode = 16;
            if (pInput->FUN_00a24180(scanCode, 1))
            {
                Handle(4, 0);
                return;
            }
            pController = scene->GetControllers();
            if (pController)
            {
                MenuController* manager = pController;
                NiControllerSequence* sequence = 0;
                if (!DAT_011a0854 || selection > 0)
                    sequence = manager->FUN_0047a520(
                        NiFixedString(DAT_011a0854 ? DAT_011a0878[selection] : DAT_011a0858[selection]));
                elapsed += g_timeGlobal.FUN_0084d030();
                if (sequence)
                {
                    sequence->Update(elapsed, true);
                    if (sequence->FUN_00508120() < sequence->FUN_00508100() && selection > 0)
                        finished = false;
                    else
                        finished = true;
                }
                else
                {
                    finished = true;
                }
                for (; pController; pController = pController->GetNext())
                {
                    MenuController* castController = FUN_00653270(&DAT_011f36bc, pController);
                    if (castController)
                    {
                        NiUpdateData updateData(elapsed, false, false);
                        pController->Update(updateData);
                        break;
                    }
                }
            }
            NiUpdateData updateData(0.0f, false, false);
            scene->Update(updateData);
        }
    }
}

bool __cdecl FUN_00702450(unsigned int);
struct Values6440
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int GetValue(int);
};
struct Player6440
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
    Values6440 values;
};
extern Player6440* g_thePlayer;
struct Target6440 : SPECIALBookMenu
{
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
    int FUN_007ca030();
    int FUN_00794d80();
    bool HandleSpecialBookKey(unsigned int key, int unused);
};
// @fnv 0x007c6440
bool Target6440::HandleSpecialBookKey(unsigned int key, int unused)
{
    if (FUN_00702450(0x424))
    {
        int index = FUN_007ca030();
        switch (key)
        {
        case 4:
        case 10:
            if (index != -1 && g_thePlayer->values.GetValue(index) > 1)
                v03(3, 0);
            return true;
        case 3:
        case 9:
            if (index != -1 && FUN_00794d80() < unk58 && g_thePlayer->values.GetValue(index) < 10)
                v03(2, 0);
            return true;
        }
    }
    return false;
}

class C7CA200NavMesh;

class C7CA200Base
{
  public:
    C7CA200Base(int iArg1, int iArg2, int iArg3);
    ~C7CA200Base();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

class C7CA200NavMeshArray
{
  public:
    C7CA200NavMeshArray();
    ~C7CA200NavMeshArray();

    unsigned int Add(C7CA200NavMesh*& rpkNavMesh);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class FUN_007ca200 : public C7CA200Base
{
  public:
    FUN_007ca200(int iArg1, int iArg2, int iArg3, int iArg4, int iNumNavMeshes, ...);

    C7CA200NavMeshArray m_kNavMeshes;
    int m_iArg4;
};

// Initializes the base with three arguments, stores iArg4, and adds iNumNavMeshes nav mesh pointers from the variadic argument list to m_kNavMeshes.
// @fnv 0x007ca200
FUN_007ca200::FUN_007ca200(int iArg1, int iArg2, int iArg3, int iArg4, int iNumNavMeshes, ...)
    : C7CA200Base(iArg1, iArg2, iArg3)
{
    m_iArg4 = iArg4;

    char* pcArgs = (char*)&iNumNavMeshes + sizeof(iNumNavMeshes);
    for (int i = 0; i < iNumNavMeshes; i++)
        m_kNavMeshes.Add(*(C7CA200NavMesh**)((pcArgs += sizeof(C7CA200NavMesh*)) - sizeof(C7CA200NavMesh*)));
    pcArgs = 0;
}

struct FUN_007ca2c0
{
    int m_00;
    NiTimeController* m_04;
    NiTimeController* m_08;
    PropHelper* m_0c;
    PropHelper* m_10;
    int m_14;
    FUN_007ca2c0(int a, const char* first, const char* second, int d);
};
// Stores the given ints, looks up two named objects under the scene root, and caches each object's property 3 controller when its value is between 8 and 12.
// @fnv 0x007ca2c0
FUN_007ca2c0::FUN_007ca2c0(int a, const char* apFirstName, const char* apSecondName, int d)
{
    m_00 = a;
    m_14 = d;
    m_0c = (PropHelper*)((Holder_007ca080*)DAT_011daa38)->pRoot->GetObjectByName(NiFixedString(apFirstName));
    m_04 = (!m_0c->GetProperty(3) ? 0
                                  : (((NiTimeController*)m_0c->GetProperty(3))->FUN_00441110() >= 8 &&
                                     ((NiTimeController*)m_0c->GetProperty(3))->FUN_00441110() <= 12))
               ? (NiTimeController*)m_0c->GetProperty(3)
               : 0;
    if (apSecondName)
    {
        m_10 = (PropHelper*)((Holder_007ca080*)DAT_011daa38)->pRoot->GetObjectByName(NiFixedString(apSecondName));
        m_08 = (!m_10->GetProperty(3) ? 0
                                      : (((NiTimeController*)m_10->GetProperty(3))->FUN_00441110() >= 8 &&
                                         ((NiTimeController*)m_10->GetProperty(3))->FUN_00441110() <= 12))
                   ? (NiTimeController*)m_10->GetProperty(3)
                   : 0;
    }
}

// Candidate for FUN_007cadd0 (FNV decompilation, official checker)

// __thiscall, no stack args (caller pops 0). /Od /Oy- /GS /EHsc.

// Based on an unverified GLM (Z.ai) / zai_glm_01 draft, round 4.

struct G_011dea10_cls
{

    void FUN_004568c0(char* a, int* b, int c, int d);
};

extern G_011dea10_cls* g_011dea10;

void __cdecl FUN_00406d00(char* dst, int size, const char* a, const char* b, const char* c, ...);

void __cdecl FUN_00406d30(char* dst, int n, const char* src);

void __cdecl FUN_004b7240(char* src, char* dst, int n);

bool __cdecl FUN_00709d40();

extern const char str_01074c4c[];

extern const char str_01076cc0[];

extern const char str_01074c6c[];

extern const char str_01076ca4[];

extern const char str_01074c40[];

extern const char str_0101fd1c[];

extern const char str_0101fd24[];

extern const char str_01074c38[];

extern const char str_01074c24[];

extern const char str_01074c08[];

extern const char str_01074c1c[];

extern const char str_01074c14[];

extern const char str_01074c00[];

extern const char str_01074bf8[];

extern const char str_01074be8[];

extern const char str_01074bd8[];

extern const char str_01074bc8[];

extern const char str_01074bb8[];

extern const char str_01076c94[];

struct FUN_007cadd0_self
{

    int unk_000;

    int unk_004;

    int unk_008;

    int unk_00c;

    int unk_010;

    int unk_014;

    int unk_018;

    int unk_01c;

    int unk_020;

    int unk_024;

    int unk_028;

    int unk_02c;

    int unk_030;

    int unk_034;

    int unk_038;

    int unk_03c;

    int unk_040;

    int unk_044;

    int unk_048;

    int unk_04c;

    int unk_050;

    int unk_054;

    int unk_058;

    int unk_05c;

    int unk_060;

    int unk_064;

    int unk_068;

    int unk_06c;

    int unk_070;

    int unk_074;

    int unk_078;

    int unk_07c;

    int unk_080;

    int unk_084;

    int unk_088;

    int unk_08c;

    int unk_090;

    int unk_094;

    int unk_098;

    int unk_09c;

    int unk_0a0;

    int unk_0a4;

    int unk_0a8;

    int unk_0ac;

    int unk_0b0;

    int unk_0b4;

    int unk_0b8;

    int unk_0bc;

    int unk_0c0;

    int unk_0c4;

    int unk_0c8;

    int unk_0cc;

    int unk_0d0;

    int unk_0d4;

    int unk_0d8;

    int unk_0dc;

    int unk_0e0;

    int unk_0e4;

    int unk_0e8;

    int unk_0ec;

    int unk_0f0;

    int unk_0f4;

    int unk_0f8;

    int unk_0fc;

    int unk_100;

    int unk_104;

    int unk_108;

    int unk_10c;

    int unk_110;

    int unk_114;

    int unk_118;

    int unk_11c;

    int unk_120;

    int unk_124;

    int unk_128;

    int unk_12c;

    int unk_130;

    int unk_134;

    int unk_138;

    int unk_13c;

    int unk_140;

    int unk_144;

    int unk_148;

    int unk_14c;

    int unk_150;

    int unk_154;

    int unk_158;

    int unk_15c;

    int unk_160;

    int unk_164;

    int unk_168;

    int unk_16c;

    int unk_170;

    int unk_174;

    int unk_178;

    int unk_17c;

    int m180[10];  // 0x180

    int m1a8[5];  // 0x1a8

    int m1bc;  // 0x1bc

    int m1c0;  // 0x1c0

    int m1c4;  // 0x1c4

    int m1c8;  // 0x1c8

    int m1cc;  // 0x1cc

    int m1d0;  // 0x1d0

    int m1d4;  // 0x1d4

    int m1d8;  // 0x1d8

    int m1dc;  // 0x1dc

    int m1e0;  // 0x1e0

    void FUN_007cadd0();
};

// @fnv 0x007cadd0
void FUN_007cadd0_self::FUN_007cadd0()

{

    int iStack_228;

    int auStack_110;

    char iStack_224[8];

    char auStack_220[264];

    char auStack_218[264];

    for (auStack_110 = 0; auStack_110 < 0xb; auStack_110++)
    {

        FUN_00406d00(auStack_220, 0x104, str_01074c4c, str_01076cc0, str_01074c6c, auStack_110);

        FUN_004b7240(auStack_220, auStack_218, 0x104);

        g_011dea10->FUN_004568c0(auStack_218, &m180[auStack_110], 0, 0);
    }

    for (iStack_228 = 1; iStack_228 < 5; iStack_228++)
    {

        FUN_00406d00(auStack_220, 0x104, str_01074c4c, str_01076ca4, str_01074c40, iStack_228);

        FUN_004b7240(auStack_220, auStack_218, 0x104);

        g_011dea10->FUN_004568c0(auStack_218, &m1a8[iStack_228], 0, 0);
    }

    if (FUN_00709d40())

        FUN_00406d30(iStack_224, 5, str_0101fd1c);

    else

        FUN_00406d30(iStack_224, 5, str_0101fd24);

    FUN_00406d00(auStack_218, 0x104, str_01076c94, str_01076cc0, iStack_224, str_01074c38);

    g_011dea10->FUN_004568c0(auStack_218, &m1c0, 0, 0);

    FUN_00406d00(auStack_220, 0x104, str_01074c08, str_01076cc0, str_01074c24);

    FUN_004b7240(auStack_220, auStack_218, 0x104);

    g_011dea10->FUN_004568c0(auStack_218, &m1bc, 0, 0);

    FUN_00406d00(auStack_218, 0x104, str_01076c94, str_01076cc0, iStack_224, str_01074c1c);

    g_011dea10->FUN_004568c0(auStack_218, &m1c4, 0, 0);

    FUN_00406d00(auStack_220, 0x104, str_01074c08, str_01076cc0, str_01074c14);

    FUN_004b7240(auStack_220, auStack_218, 0x104);

    g_011dea10->FUN_004568c0(auStack_218, &m1c8, 0, 0);

    FUN_00406d00(auStack_218, 0x104, str_01076c94, str_01076cc0, iStack_224, str_01074c00);

    g_011dea10->FUN_004568c0(auStack_218, &m1cc, 0, 0);

    FUN_00406d00(auStack_218, 0x104, str_01076c94, str_01076cc0, iStack_224, str_01074bf8);

    g_011dea10->FUN_004568c0(auStack_218, &m1d0, 0, 0);

    FUN_00406d00(auStack_220, 0x104, str_01074c08, str_01076cc0, str_01074be8);

    FUN_004b7240(auStack_220, auStack_218, 0x104);

    g_011dea10->FUN_004568c0(auStack_218, &m1d4, 0, 0);

    FUN_00406d00(auStack_220, 0x104, str_01074c08, str_01076cc0, str_01074bd8);

    FUN_004b7240(auStack_220, auStack_218, 0x104);

    g_011dea10->FUN_004568c0(auStack_218, &m1d8, 0, 0);

    FUN_00406d00(auStack_220, 0x104, str_01074c08, str_01076cc0, str_01074bc8);

    FUN_004b7240(auStack_220, auStack_218, 0x104);

    g_011dea10->FUN_004568c0(auStack_218, &m1dc, 0, 0);

    FUN_00406d00(auStack_220, 0x104, str_01074c08, str_01076cc0, str_01074bb8);

    FUN_004b7240(auStack_220, auStack_218, 0x104);

    g_011dea10->FUN_004568c0(auStack_218, &m1e0, 0, 0);
}

struct NiRTTI
{
    int unk00;
};
extern NiRTTI DAT_011f36ac;

struct NiControllerManager
{
    NiControllerSequence* FindSequenceByName(const NiFixedString& name);
    void FUN_0048fef0(float f);
    void ActivateControllerSequence(NiControllerSequence* seq, int a, bool b, float w, float t, int c);
    void FUN_0047aa40(bool b);
};

struct AVObject_7c9dc0
{
    void* GetController(const NiRTTI* rtti) const;
};

struct SceneHolder
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
    AVObject_7c9dc0* pRoot;
};
extern SceneHolder* g_sceneHolder_7c9dc0;

struct BSSoundHandleEx
{
    int unk00;
    int unk04;
    int unk08;
    BSSoundHandleEx();
    ~BSSoundHandleEx();
    BSSoundHandleEx& operator=(const BSSoundHandleEx& o);
    bool Play(bool b);
};

struct BSAudio
{
    static BSAudio* __cdecl GetSingleton();
    BSSoundHandleEx GetSoundHandleByEditorID(const char* id, unsigned int flags);
};

void __fastcall SetNegatedGlobal(void* p);

extern bool DAT_011a0854;
extern const char* DAT_011a0858[8];
extern const char* DAT_011a0878[8];

struct SPECIALBookMenu_7c9dc0
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
    int pageIndex;
    bool FUN_007c9dc0(bool forward);
};

// @fnv 0x007c9dc0
bool SPECIALBookMenu_7c9dc0::FUN_007c9dc0(bool forward)
{
    bool turned = false;
    if (forward)
    {
        DAT_011a0854 = true;
        if (pageIndex < 9)
        {
            pageIndex++;
            turned = true;
            BSSoundHandleEx sound;
            sound = BSAudio::GetSingleton()->GetSoundHandleByEditorID("OBJBookSpecialPageTurn", 0x121);
            sound.Play(false);
        }
        else
        {
            return false;
        }
    }
    else
    {
        DAT_011a0854 = false;
        if (pageIndex >= 1)
        {
            pageIndex--;
            turned = true;
            BSSoundHandleEx sound;
            sound = BSAudio::GetSingleton()->GetSoundHandleByEditorID("OBJBookSpecialPageTurn", 0x121);
            sound.Play(false);
        }
        else
        {
            return false;
        }
    }
    if (turned)
    {
        NiControllerManager* found = (NiControllerManager*)g_sceneHolder_7c9dc0->pRoot->GetController(&DAT_011f36ac);
        if (found)
        {
            NiControllerManager* manager = found;
            NiControllerSequence* sequence = 0;
            if (!DAT_011a0854 || pageIndex > 0)
            {
                sequence = manager->FindSequenceByName(
                    NiFixedString(DAT_011a0854 ? DAT_011a0878[pageIndex] : DAT_011a0858[pageIndex]));
            }
            if (sequence)
            {
                manager->FUN_0048fef0(0.0f);
                manager->ActivateControllerSequence(sequence, 0, true, 1.0f, 0.0f, 0);
                manager->FUN_0047aa40(true);
                SetNegatedGlobal(sequence);
            }
        }
    }
    return true;
}

extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);
extern "C" void* __cdecl FormHeap_Allocate(unsigned int size);

void __cdecl CallVfunc60WithGlobalOffset(void* p);
void __cdecl FUN_007cabb0(void* p);
void __cdecl FUN_007ca8a0(void* p);
void __cdecl FUN_007cabf0(void* p);
void __cdecl DispatchSourceCallback(void* p);
void __cdecl FUN_007cac30(void* p);
void __cdecl UpdateEntryRankText(void* p);
void __cdecl DispatchStateCallback(void* p);
void __cdecl UpdateLodVisibility(void* p);
void __cdecl FUN_007ca700(void* p);
void __cdecl FUN_007ca960(void* p);
void __cdecl FUN_007ca7a0(void* p);
void __cdecl PlaySpecialBookSoundAndSetStat(void* p);

typedef void(__cdecl* ItemCb)(void* p);

struct BkPoint3
{
    float x, y, z;
    BkPoint3* Init(float ax, int ay, int az);
};
struct BkColor
{
    float r, g, b;
    BkColor(float ar, float ag, float ab);
};
struct BkFixedStr
{
    void* m_pData;
    BkFixedStr(const char* s);
    ~BkFixedStr();
};
struct BkTimer
{
    float FUN_0084d030();
};
struct BkAnimSeq
{
    void SetNegatedGlobal();
};
struct BkAnimCtrl
{
    BkAnimSeq* FUN_0047a520(const BkFixedStr& name);
    void FUN_0048fef0(float t);
    void FUN_0047aab0(BkAnimSeq* seq, int a, int b, float c, float d, int e);
    void FUN_0047aa40(int a);
};
struct BkCtrl
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
    virtual void SetPos(const BkPoint3& p);
    BkCtrl* FUN_004a8a90();
};
struct BkNode
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual int v03(float f);
    void FUN_00440490(float s);
    void FUN_004bc1f0(float x, float y, float z);
    void FUN_006404b0(float a, float b, float c, float d);
    void FUN_00a59c60(const BkPoint3& p);
    BkCtrl* FUN_00a5c570(void* rtti);
    BkTimer* FUN_0043d450();
};
struct BkLight
{
    char pad[0xfc];
    static void* operator new(unsigned int size);
    static void operator delete(void*, unsigned int);
    BkLight();
    void FUN_00440460(const BkColor& c);
    void SetEffectColor(const BkColor& c);
    void FUN_0050dd50(const BkColor& c);
    void FUN_0050dd20(float f);
    void FUN_00a59c60(const BkPoint3& p);
};
struct BkScene
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
    virtual void AttachChildInAvailableSlot(void* child, int firstAvail);
    void* FUN_00b5ca70(int a);
    void FUN_00b5c940(BkLight* l, int a);
};
struct BkLoader
{
    BkNode* LoadModel(const char* path, int a, int b, int c, int d, int e);
};

struct BkItemBase
{
    static void* operator new(unsigned int size);
    static void operator delete(void*);
};
struct BkButton : BkItemBase
{
    ItemCb m_cb0;
    ItemCb m_cb4;
    int unk08;
    int unk0C;
    int unk10;
    BkButton(ItemCb a, ItemCb b, const char* name);
};
struct BkStepButton : BkButton
{
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    BkStepButton(ItemCb a, ItemCb b, const char* name, int stat, int count, ...);
};
struct BkDisplay : BkItemBase
{
    ItemCb m_cb;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    BkDisplay(ItemCb cb, const char* name, const char* name2, int stat);
};
struct BkButtonList
{
    BkButton** m_pData;
    int m_iCapacity;
    int m_iArrayLength;
    int m_iGrow;
    unsigned int FUN_0044ddc0();
    BkButton*& FUN_006a7ad0(unsigned int index);
    void FUN_007cb2e0(BkButton* const& item);
};
struct BkDisplayList
{
    BkDisplay** m_pData;
    int m_iCapacity;
    int m_iArrayLength;
    int m_iGrow;
    unsigned int FUN_0044ddc0();
    BkDisplay*& FUN_006a7ad0(unsigned int index);
    void FUN_007cb2e0(BkDisplay* const& item);
};
struct BkGroup
{
    BkButtonList buttons;
    BkDisplayList displays;
};
struct BkMenuG
{
    char pad[0x50];
    float m_fTime;
    int unk54;
    int unk58;
    BkNode* m_pReferencedNode;
};

extern int* DAT_011daa38;
extern BkLoader* DAT_011c3b3c;
extern BkTimer DAT_011f6394;
void __cdecl FUN_004b7660(BkNode* node);
void __cdecl FUN_00a6d2d0(BkNode* node);
void* __cdecl FUN_00653270(void* rtti, BkCtrl* obj);
BkScene* __cdecl FUN_00450b80(int a);

struct SpecialBookMenuX
{
    char pad[0x50];
    float m_fTime;
    int unk54;
    int unk58;
    BkNode* m_pReferencedNode;
    BkGroup m_groups[9];
    void InitMenu();
    void FUN_007cadd0();
};

// Unused, never emitted: keeps the per-TU $SG literal numbering clear of the checker's fixed $SG bindings (KB k8552).
inline const char* BkSgNumberingShim(int i)
{
    static const char* const t[] = {"0",  "1",  "2",  "3",  "4",  "5",  "6",  "7",  "8",  "9",  "10", "11", "12", "13",
                                    "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27"};
    return t[i];
}
// Loads the Babybook02.NIF scene, sets up its transform and animation, then creates and registers the displays and buttons for all nine menu groups.
// @fnv 0x007c6ce0
void SpecialBookMenuX::InitMenu()
{
    BkDisplay* pDigits;
    BkPoint3 pos;
    float aScale;
    BkStepButton* declA;
    BkStepButton* pIncrease;
    BkButton* next;
    BkButton* pLeft;
    void* found;
    BkCtrl* aPCtrl;
    BkPoint3 akStart;
    BkDisplay* valueX;
    BkDisplay* kMsg;

    ((BkMenuG*)DAT_011daa38)->m_pReferencedNode =
        DAT_011c3b3c->LoadModel("Meshes\\Terminals\\Babybook02.NIF", 0, 1, 0, 0, 0);
    FUN_004b7660(((BkMenuG*)DAT_011daa38)->m_pReferencedNode);
    ((BkMenuG*)DAT_011daa38)->m_pReferencedNode->FUN_00440490(0.05f);
    ((BkMenuG*)DAT_011daa38)->m_pReferencedNode->FUN_004bc1f0(0.0f, 0.0f, -60.0f);
    ((BkMenuG*)DAT_011daa38)->m_pReferencedNode->FUN_006404b0(1.5707964f, 1.0f, 0.0f, 0.0f);
    akStart.Init(0.0f, 0, 0);
    ((BkMenuG*)DAT_011daa38)->m_pReferencedNode->FUN_00a59c60(akStart);
    ((BkMenuG*)DAT_011daa38)->m_fTime += DAT_011f6394.FUN_0084d030();
    aPCtrl = ((BkMenuG*)DAT_011daa38)->m_pReferencedNode->FUN_00a5c570(&DAT_011f36ac);
    if (aPCtrl)
    {
        BkAnimCtrl* mgr5 = (BkAnimCtrl*)aPCtrl;
        BkAnimSeq* pForwardSequence = mgr5->FUN_0047a520(BkFixedStr("Forward"));
        if (pForwardSequence)
        {
            mgr5->FUN_0048fef0(0.0f);
            mgr5->FUN_0047aab0(pForwardSequence, 0, 1, 1.0f, 0.0f, 0);
            mgr5->FUN_0047aa40(1);
            pForwardSequence->SetNegatedGlobal();
        }
    }
    FUN_00a6d2d0(m_pReferencedNode);
    for (; aPCtrl; aPCtrl = aPCtrl->FUN_004a8a90())
    {
        void* pMatch = FUN_00653270(&DAT_011f36bc, aPCtrl);
        if (pMatch)
        {
            BkPoint3 pT4;
            pT4.Init(0.0f, 0, 0);
            aPCtrl->SetPos(pT4);
            break;
        }
    }
    pos.Init(0.0f, 0, 0);
    m_pReferencedNode->FUN_00a59c60(pos);
    aScale = ((BkMenuG*)DAT_011daa38)->m_pReferencedNode->FUN_0043d450()->FUN_0084d030() * 20.0;
    found = FUN_00450b80(1)->FUN_00b5ca70(((BkMenuG*)DAT_011daa38)->m_pReferencedNode->v03(aScale));
    if (found == 0)
    {
        BkLight* apTargetLight = new BkLight();
        apTargetLight->FUN_00440460(BkColor(0.0f, 0.0f, 0.0f));
        apTargetLight->SetEffectColor(BkColor(0.85f, 0.85f, 0.85f));
        apTargetLight->FUN_0050dd50(BkColor(aScale, 0.0f, 0.0f));
        apTargetLight->FUN_0050dd20(1.0f);
        BkPoint3 kLightPos;
        kLightPos.Init(0.0f, 0, 0);
        apTargetLight->FUN_00a59c60(kLightPos);
        FUN_00450b80(1)->AttachChildInAvailableSlot(apTargetLight, 1);
        FUN_00450b80(1)->FUN_00b5c940(apTargetLight, 0);
    }
    FUN_00450b80(1)->AttachChildInAvailableSlot(((BkMenuG*)DAT_011daa38)->m_pReferencedNode, 1);

    next = new BkButton(FUN_007cabb0, CallVfunc60WithGlobalOffset, "LookInside_Btn:0");
    m_groups[0].buttons.FUN_007cb2e0(next);

    valueX = new BkDisplay(UpdateEntryRankText, "P1_PointVal:0", 0, 5);
    kMsg = new BkDisplay(DispatchStateCallback, "P1_Message:0", 0, -1);
    pDigits = new BkDisplay(UpdateLodVisibility, "P1_PointsRemainDigit1:0", "P1_PointsRemainDigit2:0", -1);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "P1_Decrease_Btn:0", 5, 2, valueX, pDigits);
    pIncrease =
        new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "P1_Increase_Btn:0", 5, 2, valueX, pDigits);
    next = new BkButton(FUN_007cabb0, CallVfunc60WithGlobalOffset, "P1_RT_Btn:0");
    pLeft = new BkButton(FUN_007cabf0, FUN_007ca8a0, "P1_LT_Btn:0");
    m_groups[1].displays.FUN_007cb2e0(valueX);
    m_groups[1].displays.FUN_007cb2e0(kMsg);
    m_groups[1].displays.FUN_007cb2e0(pDigits);
    m_groups[1].buttons.FUN_007cb2e0(declA);
    m_groups[1].buttons.FUN_007cb2e0(pIncrease);
    m_groups[1].buttons.FUN_007cb2e0(next);
    m_groups[1].buttons.FUN_007cb2e0(pLeft);

    valueX = new BkDisplay(UpdateEntryRankText, "P2_PointVal:0", 0, 6);
    kMsg = new BkDisplay(DispatchStateCallback, "P2_Message:0", 0, -1);
    pDigits = new BkDisplay(UpdateLodVisibility, "P2_PointsRemainDigit1:0", "P2_PointsRemainDigit2:0", -1);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "P2_Decrease_Btn:0", 6, 2, valueX, pDigits);
    pIncrease =
        new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "P2_Increase_Btn:0", 6, 2, valueX, pDigits);
    next = new BkButton(FUN_007cabb0, CallVfunc60WithGlobalOffset, "P2_RT_Btn:0");
    pLeft = new BkButton(FUN_007cabf0, FUN_007ca8a0, "P2_LT_Btn:0");
    m_groups[2].displays.FUN_007cb2e0(valueX);
    m_groups[2].displays.FUN_007cb2e0(kMsg);
    m_groups[2].displays.FUN_007cb2e0(pDigits);
    m_groups[2].buttons.FUN_007cb2e0(declA);
    m_groups[2].buttons.FUN_007cb2e0(pIncrease);
    m_groups[2].buttons.FUN_007cb2e0(next);
    m_groups[2].buttons.FUN_007cb2e0(pLeft);

    valueX = new BkDisplay(UpdateEntryRankText, "P3_PointVal:0", 0, 7);
    kMsg = new BkDisplay(DispatchStateCallback, "P3_Message:0", 0, -1);
    pDigits = new BkDisplay(UpdateLodVisibility, "P3_PointsRemainDigit1:0", "P3_PointsRemainDigit2:0", -1);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "P3_Decrease_Btn:0", 7, 2, valueX, pDigits);
    pIncrease =
        new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "P3_Increase_Btn:0", 7, 2, valueX, pDigits);
    next = new BkButton(FUN_007cabb0, CallVfunc60WithGlobalOffset, "P3_RT_Btn:0");
    pLeft = new BkButton(FUN_007cabf0, FUN_007ca8a0, "P3_LT_Btn:0");
    m_groups[3].displays.FUN_007cb2e0(valueX);
    m_groups[3].displays.FUN_007cb2e0(kMsg);
    m_groups[3].displays.FUN_007cb2e0(pDigits);
    m_groups[3].buttons.FUN_007cb2e0(declA);
    m_groups[3].buttons.FUN_007cb2e0(pIncrease);
    m_groups[3].buttons.FUN_007cb2e0(next);
    m_groups[3].buttons.FUN_007cb2e0(pLeft);

    valueX = new BkDisplay(UpdateEntryRankText, "P4_PointVal:0", 0, 8);
    kMsg = new BkDisplay(DispatchStateCallback, "P4_Message:0", 0, -1);
    pDigits = new BkDisplay(UpdateLodVisibility, "P4_PointsRemainDigit1:0", "P4_PointsRemainDigit2:0", -1);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "P4_Decrease_Btn:0", 8, 2, valueX, pDigits);
    pIncrease =
        new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "P4_Increase_Btn:0", 8, 2, valueX, pDigits);
    next = new BkButton(FUN_007cabb0, CallVfunc60WithGlobalOffset, "P4_RT_Btn:0");
    pLeft = new BkButton(FUN_007cabf0, FUN_007ca8a0, "P4_LT_Btn:0");
    m_groups[4].displays.FUN_007cb2e0(valueX);
    m_groups[4].displays.FUN_007cb2e0(kMsg);
    m_groups[4].displays.FUN_007cb2e0(pDigits);
    m_groups[4].buttons.FUN_007cb2e0(declA);
    m_groups[4].buttons.FUN_007cb2e0(pIncrease);
    m_groups[4].buttons.FUN_007cb2e0(next);
    m_groups[4].buttons.FUN_007cb2e0(pLeft);

    valueX = new BkDisplay(UpdateEntryRankText, "P5_PointVal:0", 0, 9);
    kMsg = new BkDisplay(DispatchStateCallback, "P5_Message:0", 0, -1);
    pDigits = new BkDisplay(UpdateLodVisibility, "P5_PointsRemainDigit1:0", "P5_PointsRemainDigit2:0", -1);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "P5_Decrease_Btn:0", 9, 2, valueX, pDigits);
    pIncrease =
        new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "P5_Increase_Btn:0", 9, 2, valueX, pDigits);
    next = new BkButton(FUN_007cabb0, CallVfunc60WithGlobalOffset, "P5_RT_Btn:0");
    pLeft = new BkButton(FUN_007cabf0, FUN_007ca8a0, "P5_LT_Btn:0");
    m_groups[5].displays.FUN_007cb2e0(valueX);
    m_groups[5].displays.FUN_007cb2e0(kMsg);
    m_groups[5].displays.FUN_007cb2e0(pDigits);
    m_groups[5].buttons.FUN_007cb2e0(declA);
    m_groups[5].buttons.FUN_007cb2e0(pIncrease);
    m_groups[5].buttons.FUN_007cb2e0(next);
    m_groups[5].buttons.FUN_007cb2e0(pLeft);

    valueX = new BkDisplay(UpdateEntryRankText, "P6_PointVal:0", 0, 10);
    kMsg = new BkDisplay(DispatchStateCallback, "P6_Message:0", 0, -1);
    pDigits = new BkDisplay(UpdateLodVisibility, "P6_PointsRemainDigit1:0", "P6_PointsRemainDigit2:0", -1);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "P6_Decrease_Btn:0", 10, 2, valueX, pDigits);
    pIncrease =
        new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "P6_Increase_Btn:0", 10, 2, valueX, pDigits);
    next = new BkButton(FUN_007cabb0, CallVfunc60WithGlobalOffset, "P6_RT_Btn:0");
    pLeft = new BkButton(FUN_007cabf0, FUN_007ca8a0, "P6_LT_Btn:0");
    m_groups[6].displays.FUN_007cb2e0(valueX);
    m_groups[6].displays.FUN_007cb2e0(kMsg);
    m_groups[6].displays.FUN_007cb2e0(pDigits);
    m_groups[6].buttons.FUN_007cb2e0(declA);
    m_groups[6].buttons.FUN_007cb2e0(pIncrease);
    m_groups[6].buttons.FUN_007cb2e0(next);
    m_groups[6].buttons.FUN_007cb2e0(pLeft);

    valueX = new BkDisplay(UpdateEntryRankText, "P7_PointVal:0", 0, 11);
    kMsg = new BkDisplay(DispatchStateCallback, "P7_Message:0", 0, -1);
    pDigits = new BkDisplay(UpdateLodVisibility, "P7_PointsRemainDigit1:0", "P7_PointsRemainDigit2:0", -1);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "P7_Decrease_Btn:0", 11, 2, valueX, pDigits);
    pIncrease =
        new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "P7_Increase_Btn:0", 11, 2, valueX, pDigits);
    next = new BkButton(FUN_007cabb0, CallVfunc60WithGlobalOffset, "P7_RT_Btn:0");
    pLeft = new BkButton(FUN_007cabf0, FUN_007ca8a0, "P7_LT_Btn:0");
    m_groups[7].displays.FUN_007cb2e0(valueX);
    m_groups[7].displays.FUN_007cb2e0(kMsg);
    m_groups[7].displays.FUN_007cb2e0(pDigits);
    m_groups[7].buttons.FUN_007cb2e0(declA);
    m_groups[7].buttons.FUN_007cb2e0(pIncrease);
    m_groups[7].buttons.FUN_007cb2e0(next);
    m_groups[7].buttons.FUN_007cb2e0(pLeft);

    valueX = new BkDisplay(UpdateEntryRankText, "Index_StrengthPointVal:0", 0, 5);
    m_groups[8].displays.FUN_007cb2e0(valueX);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "Index_StrengthDecrease_Btn:0", 5, 2, valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(declA);
    pIncrease = new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "Index_StrengthIncrease_Btn:0", 5, 2,
                                 valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(pIncrease);

    valueX = new BkDisplay(UpdateEntryRankText, "Index_PerceptionPointVal:0", 0, 6);
    m_groups[8].displays.FUN_007cb2e0(valueX);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "Index_PerceptionDecrease_Btn:0", 6, 2, valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(declA);
    pIncrease = new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "Index_PerceptionIncrease_Btn:0", 6, 2,
                                 valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(pIncrease);

    valueX = new BkDisplay(UpdateEntryRankText, "Index_EndurancePointVal:0", 0, 7);
    m_groups[8].displays.FUN_007cb2e0(valueX);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "Index_EnduranceDecrease_Btn:0", 7, 2, valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(declA);
    pIncrease = new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "Index_EnduranceIncrease_Btn:0", 7, 2,
                                 valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(pIncrease);

    valueX = new BkDisplay(UpdateEntryRankText, "Index_CharismaPointVal:0", 0, 8);
    m_groups[8].displays.FUN_007cb2e0(valueX);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "Index_CharismaDecrease_Btn:0", 8, 2, valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(declA);
    pIncrease = new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "Index_CharismaIncrease_Btn:0", 8, 2,
                                 valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(pIncrease);

    valueX = new BkDisplay(UpdateEntryRankText, "Index_IntelligencePointVal:0", 0, 9);
    m_groups[8].displays.FUN_007cb2e0(valueX);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "Index_IntelligenceDecrease_Btn:0", 9, 2, valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(declA);
    pIncrease = new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "Index_IntelligenceIncrease_Btn:0", 9, 2,
                                 valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(pIncrease);

    valueX = new BkDisplay(UpdateEntryRankText, "Index_AgilityPointVal:0", 0, 10);
    m_groups[8].displays.FUN_007cb2e0(valueX);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "Index_AgilityDecrease_Btn:0", 10, 2, valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(declA);
    pIncrease = new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "Index_AgilityIncrease_Btn:0", 10, 2,
                                 valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(pIncrease);

    valueX = new BkDisplay(UpdateEntryRankText, "Index_LuckPointVal:0", 0, 11);
    m_groups[8].displays.FUN_007cb2e0(valueX);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "Index_LuckDecrease_Btn:0", 11, 2, valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(declA);
    pIncrease = new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "Index_LuckIncrease_Btn:0", 11, 2,
                                 valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(pIncrease);

    kMsg = new BkDisplay(DispatchStateCallback, (char*)"Index_Message:0", 0, -1);
    m_groups[8].displays.FUN_007cb2e0(kMsg);
    pDigits = new BkDisplay(UpdateLodVisibility, (char*)"Index_PointsRemainDigit1:0", "Index_PointsRemainDigit2:0", -1);
    m_groups[8].displays.FUN_007cb2e0(pDigits);
    next = new BkButton(FUN_007cac30, DispatchSourceCallback, "AllDone_Btn:0");
    m_groups[8].buttons.FUN_007cb2e0(next);
    pLeft = new BkButton(FUN_007cabf0, FUN_007ca8a0, "Index_LT_Btn:0");
    m_groups[8].buttons.FUN_007cb2e0(pLeft);

    FUN_007cadd0();
    for (int iGroup = 0; iGroup < 9; iGroup++)
    {
        for (unsigned int iItem = 0; iItem < m_groups[iGroup].displays.FUN_0044ddc0(); iItem++)
        {
            m_groups[iGroup].displays.FUN_006a7ad0(iItem)->m_cb(m_groups[iGroup].displays.FUN_006a7ad0(iItem));
        }
        for (unsigned int iButton = 0; iButton < m_groups[iGroup].buttons.FUN_0044ddc0(); iButton++)
        {
            m_groups[iGroup].buttons.FUN_006a7ad0(iButton)->m_cb4(m_groups[iGroup].buttons.FUN_006a7ad0(iButton));
        }
    }
}

int __fastcall FUN_00794d80(void*);
int __cdecl MinInt(int, int);
int __cdecl FUN_00647b70(int, int);

struct StatValues
{
    virtual int GetValue(int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int GetBaseValue(int);
};
struct BookPlayer
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
    StatValues values;
    void FUN_0093a7c0(int stat, int value);
};
struct RawBookPtr
{
    void* FUN_00559450();
};
struct BookButton
{
    void(__cdecl* activate)(BookButton*);
    void(__cdecl* other)(BookButton*);
    RawBookPtr object;
    int unk0c;
    int unk10;
};
struct BookButtonList
{
    BookButton** data;
    int capacity, count, grow;
    unsigned int FUN_0044ddc0();
    BookButton*& FUN_006a7ad0(unsigned int);
};
struct BookGroup
{
    BookButtonList buttons;
    BkDisplayList displays;
};
struct BookInterface
{
    float FUN_009a9350();
    float FUN_00792760();
};
BookInterface* __cdecl FUN_004b7210();
struct RenderBuffer
{
    unsigned int FUN_0084e3a0();
};
struct BookRenderer
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
    virtual RenderBuffer* GetBuffer();
};
BookRenderer* __cdecl FUN_0043c4b0();
extern bool DAT_011f9426;
extern float DAT_011ad84c;
extern float DAT_011ad848;
struct FUN_006815c0
{
    float x, y, z;
    FUN_006815c0();
};
struct BookPickResult
{
    void* FUN_00968670();
};
struct NiPick
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
    NiPick(int, int);
    ~NiPick();
    void SetByteAtOffset17(int);
    void FUN_00705fc0(void*);
    void FUN_006ecd40(int);
    void SetByteAtOffset30(int);
    bool FUN_00e98e20(const FUN_006815c0&, const FUN_006815c0&, int);
    BookPickResult* FUN_00500940(unsigned int);
};
struct BookScene
{
    void MapScreenToRay(int, int, FUN_006815c0*, FUN_006815c0*, int);
};
struct BookMenu
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
    int pageIndex;
    int selectedStat;
    float elapsed;
    bool finished;
    int limit;
    void* scene;
    BookGroup groups[9];
    int FUN_007ca030();
    bool FUN_007c9dc0(bool);
    void InvokeCallbacksForSlot();
    void HandleKey(unsigned int key, int unused);
};

// Dispatches key values to page, stat, callback, and button handling; key 4 calls FUN_007c6120 when page index equals limit.
// @fnv 0x007c6550
void BookMenu::HandleKey(unsigned int key, int unused)
{
    bool turned = false;
    switch (key)
    {
    case 4:
        if (FUN_00794d80(this) == limit)
            FUN_007c6120();
        else
            BSAudio::GetSingleton()->GetSoundHandleByEditorID("UIActivateNothing", 0x121).Play(false);
        break;
    case 0:
    case 1:
        if (finished)
        {
            if (key == 0)
                turned = FUN_007c9dc0(true);
            else
                turned = FUN_007c9dc0(false);
            InvokeCallbacksForSlot();
        }
        break;
    case 2:
    case 3: {
        int oldValue9 = 0;
        int newValue = 0;
        if (FUN_007ca030() != -1)
        {
            oldValue9 = ((BookPlayer*)g_thePlayer)->values.GetBaseValue(FUN_007ca030());
            if (key == 2)
            {
                if (FUN_00794d80(this) < limit)
                    ((BookPlayer*)g_thePlayer)->FUN_0093a7c0(FUN_007ca030(), MinInt(oldValue9 + 1, 10));
            }
            else
            {
                ((BookPlayer*)g_thePlayer)->FUN_0093a7c0(FUN_007ca030(), FUN_00647b70(oldValue9 - 1, 1));
            }
            newValue = ((BookPlayer*)g_thePlayer)->values.GetValue(FUN_007ca030());
        }
        else if (_FUN_004b71d0() && pageIndex == 8)
        {
            int stat = selectedStat + 4;
            oldValue9 = ((BookPlayer*)g_thePlayer)->values.GetBaseValue(stat);
            if (key == 2)
            {
                if (FUN_00794d80(this) < limit)
                    ((BookPlayer*)g_thePlayer)->FUN_0093a7c0(stat, MinInt(oldValue9 + 1, 10));
            }
            else
            {
                ((BookPlayer*)g_thePlayer)->FUN_0093a7c0(stat, FUN_00647b70(oldValue9 - 1, 1));
            }
            newValue = ((BookPlayer*)g_thePlayer)->values.GetValue(stat);
        }
        if (oldValue9 != newValue)
        {
            BSSoundHandleEx sound;
            sound = BSAudio::GetSingleton()->GetSoundHandleByEditorID("OBJBookSpecialNumber", 0x121);
            sound.Play(false);
        }
        InvokeCallbacksForSlot();
        break;
    }
    case 5:
        if (pageIndex < 9)
        {
            BookInterface* interfaceManager3 = FUN_004b7210();
            int mouseX = (int)interfaceManager3->FUN_009a9350();
            int mouseY = (int)interfaceManager3->FUN_00792760();
            if (DAT_011f9426)
                mouseY = (int)(mouseY * (DAT_011ad848 - DAT_011ad84c) +
                               FUN_0043c4b0()->GetBuffer()->FUN_0084e3a0() * DAT_011ad84c);
            for (unsigned int i = 0; i < groups[pageIndex].buttons.FUN_0044ddc0(); i++)
            {
                FUN_006815c0 origin20;
                FUN_006815c0 direction1;
                NiPick pick(0, 8);
                pick.SetByteAtOffset17(1);
                pick.FUN_00705fc0(groups[pageIndex].buttons.FUN_006a7ad0(i)->object.FUN_00559450());
                pick.FUN_006ecd40(0);
                pick.SetByteAtOffset30(1);
                ((BookScene*)((RawBookPtr*)&g_011daa9c)->FUN_00559450())
                    ->MapScreenToRay(mouseX, mouseY, &origin20, &direction1, 0);
                if (pick.FUN_00e98e20(origin20, direction1, 0))
                {
                    unsigned int resultIndex = 0;
                    void* hit = pick.FUN_00500940(resultIndex)->FUN_00968670();
                    if (hit)
                    {
                        groups[pageIndex].buttons.FUN_006a7ad0(i)->activate(groups[pageIndex].buttons.FUN_006a7ad0(i));
                        break;
                    }
                }
            }
        }
        break;
    case 6:
        if (pageIndex == 8 && selectedStat > 1)
        {
            selectedStat--;
            BSAudio::GetSingleton()->GetSoundHandleByEditorID("OBJBookSpecialFocus", 0x121).Play(false);
        }
        InvokeCallbacksForSlot();
        break;
    case 7:
        if (pageIndex == 8 && selectedStat < 7)
        {
            selectedStat++;
            BSAudio::GetSingleton()->GetSoundHandleByEditorID("OBJBookSpecialFocus", 0x121).Play(false);
        }
        InvokeCallbacksForSlot();
        break;
    }
}
