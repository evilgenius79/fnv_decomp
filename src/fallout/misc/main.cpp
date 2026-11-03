// fallout/misc/main.cpp: Interface, SomeClass, BSFadeNodeCuller, Mover and more (192 functions)
#include "main.h"

extern int DAT_011c70cc;

// @fnv 0x004dc310
bool __cdecl FUN_004dc310()
{
    return DAT_011c70cc >= 2;
}

extern NiPointer<NiNode> g_011dee84;

// Creates a new SceneGraph named "Menu" and stores it in the global NiPointer g_011dee84.
// @fnv 0x004dc5c0
void FUN_004dc5c0()
{
    g_011dee84 = reinterpret_cast<NiNode*>(new SceneGraph("Menu", true, 0));
}

struct Node
{
    char pad[8];
    int v;
};
struct FUN_004ed8c0_shell
{
    Node* FUN_0049fa80();
    void FUN_00559a70(Node*);
    void FUN_004ed8c0(int* e);
};
// Gets a Node via FUN_0049fa80, stores the int pointed to by e into its v field, then passes the node to FUN_00559a70.
// @fnv 0x004ed8c0
void FUN_004ed8c0_shell::FUN_004ed8c0(int* piValue)
{
    Node* n = FUN_0049fa80();
    n->v = *piValue;
    FUN_00559a70(n);
}

struct BGSAddonNode;
struct Arr86
{
    void SetAt(unsigned int, BGSAddonNode*&);
};
struct Idx86
{
    unsigned int FUN_00877a50(unsigned int&);
};
struct S86
{
    char p[0xad4];
    Idx86 i;
    char q[0xae4 - 0xad5];
    Arr86 a;
    unsigned int FUN_0086bae0(unsigned int key, BGSAddonNode* node);
};
// @fnv 0x0086bae0
unsigned int S86::FUN_0086bae0(unsigned int key, BGSAddonNode* node)
{
    unsigned int idx = i.FUN_00877a50(key);
    a.SetAt(idx, node);
    return idx;
}

namespace fnv_0086bbd0 {
struct BGSAddonNode;
struct Arr86
{
    void SetAt(unsigned int, BGSAddonNode*&);
};
struct Idx86
{
    unsigned int FUN_00877a50(unsigned int&);
};
struct S86b
{
    char p[0xaf4];
    Idx86 i;
    char q[0xb04 - 0xaf5];
    Arr86 a;
    unsigned int FUN_0086bbd0(unsigned int key, BGSAddonNode* node);
};
// @fnv 0x0086bbd0
unsigned int S86b::FUN_0086bbd0(unsigned int key, BGSAddonNode* node)
{
    unsigned int idx = i.FUN_00877a50(key);
    a.SetAt(idx, node);
    return idx;
}
}  // namespace fnv_0086bbd0

struct Dummy_0086bce0
{
    void FUN_00afdda0(int);
};
extern Dummy_0086bce0* _g_fileFinder;

// @fnv 0x0086bce0
void __cdecl FUN_0086bce0(int aiValue)
{
    if (_g_fileFinder)
        _g_fileFinder->FUN_00afdda0(aiValue);
}

void __cdecl FUN_00b013f0();
void __cdecl FUN_0086bd90(void(__cdecl*)());

// @fnv 0x0086bd70
void __cdecl FUN_0086bd70()
{
    FUN_0086bd90(FUN_00b013f0);
}

// @fnv 0x0086bda0
void __fastcall FUN_0086bda0(int param_1)
{
    if (*(int*)(param_1 + 0x5c) == 1 || *(int*)(param_1 + 0x5c) == 2)
    {
        *(int*)(param_1 + 0x5c) = 3;
    }
}

class BGSLoadGameBuffer;

class Interface
{
  public:
    static void __cdecl PrintDebugMessage(BGSLoadGameBuffer*);
};

class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag(void);
};

class GlobalObject_0044f440
{
  public:
    float FUN_00450410(void);
};

class GlobalObject_0045cf30
{
};

void __cdecl FUN_005c5a60(int);
void __cdecl FUN_0086a480();
void __cdecl FUN_0086bff0(void(__cdecl*)());
void __cdecl FUN_0086c000(unsigned char);

extern GlobalObject_0044f440 g_011deb70;
extern GlobalObject_0044f440 g_011dec18;
extern GlobalObject_0045cf30 g_011ded68;
extern GlobalObject_0045cf30 g_011deea8;

extern unsigned char DAT_011f9443;
extern float DAT_011f9480;
extern float DAT_011f9484;

// @fnv 0x0086bf70
void __cdecl FUN_0086bf70()
{
    Interface::PrintDebugMessage((BGSLoadGameBuffer*)"Initializing Shader System...");
    FUN_005c5a60(0);
    FUN_0086bff0(FUN_0086a480);
    FUN_0086c000(*reinterpret_cast<ProcessLists*>(&g_011ded68)->GetLifeStateControlFlag());
    DAT_011f9443 = *reinterpret_cast<ProcessLists*>(&g_011deea8)->GetLifeStateControlFlag();
    DAT_011f9484 = g_011dec18.FUN_00450410();
    DAT_011f9480 = g_011deb70.FUN_00450410();
}

namespace fnv_0086d490 {
struct NiPoint3_local
{
    int x, y, z;
};

class TESObjectREFR
{
  public:
    void SetReferencePosition(NiPoint3_local aPoint);
};

struct FUN_0086d490_class : public TESObjectREFR
{
    void __thiscall impl(const NiPoint3_local& arPoint);
};

// @fnv 0x0086d490
void __thiscall FUN_0086d490_class::impl(const NiPoint3_local& arPoint)
{
    SetReferencePosition(arPoint);
}
}  // namespace fnv_0086d490

int __cdecl FUN_004da670(int, int);
const char* __cdecl FUN_0086d580();
int __cdecl sprintf(char*, const char*, ...);
__declspec(dllimport) int __stdcall MessageBoxA(void*, const char*, const char*, unsigned int);
__declspec(dllimport) void __stdcall ExitProcess(unsigned int);

// Calls FUN_004da670 with pThis[2] and pThis[3]; on failure formats an error message with FUN_0086d580, shows a MessageBoxA and calls ExitProcess(0).
// @fnv 0x0086d500
void __fastcall FUN_0086d500(int* pThis)
{
    char buf[512];
    if (!FUN_004da670(pThis[2], pThis[3]))
    {
        sprintf(buf, "Failed to initialize renderer.\n%s", FUN_0086d580());
        MessageBoxA(0, buf, "Fallout", 0);
        ExitProcess(0);
    }
}

class NiGeometryData;

class NiScreenElementsData
{
  public:
    bool FUN_00a87ae0(int, int, int);
};

class NiGeometry
{
  public:
    NiGeometryData* FUN_005495f0(void);
};

struct FUN_0086e3f0_shell : public NiGeometry
{
    bool FUN_0086e3f0(unsigned short usNumVertices, unsigned short usNumTriangles, int ausTriList);
};

// Forwards the vertex count, triangle count and triangle list to the geometry data's FUN_00a87ae0 and returns its result.
// @fnv 0x0086e3f0
bool FUN_0086e3f0_shell::FUN_0086e3f0(unsigned short usNumVertices, unsigned short usNumTriangles, int ausTriList)
{
    return ((NiScreenElementsData*)FUN_005495f0())->FUN_00a87ae0(usNumVertices, usNumTriangles, ausTriList);
}

namespace fnv_0086e420 {
struct NiGeometryData;
struct NiGeometry
{
    NiGeometryData* FUN_005495f0();
};
struct NiScreenElementsData
{
    bool SetRectangleBounds(int, float, float, float, float);
};
struct FUN_0086e420_shell : NiGeometry
{
    void FUN_0086e420(int a, float b, float c, float d, float e);
};
// @fnv 0x0086e420
void FUN_0086e420_shell::FUN_0086e420(int a, float b, float c, float d, float e)
{
    ((NiScreenElementsData*)FUN_005495f0())->SetRectangleBounds(a, b, c, d, e);
}
}  // namespace fnv_0086e420

namespace fnv_0086e460 {
struct NiScreenElementsData
{
    bool SetRectangleBounds(int, unsigned short, float, float, float, float);
};
struct NiGeometry
{
    NiScreenElementsData* FUN_005495f0();
};
struct FUN_0086e460_shell : public NiGeometry
{
    bool FUN_0086e460(int, unsigned short, float, float, float, float);
};
// Forwards the polygon, set and rectangle coordinates to the screen elements data returned by FUN_005495f0 and returns its result.
// @fnv 0x0086e460
bool FUN_0086e460_shell::FUN_0086e460(int iPolygon, unsigned short usSet, float fLeft, float fTop, float fRight,
                                      float fBottom)
{
    return ((NiScreenElementsData*)FUN_005495f0())->SetRectangleBounds(iPolygon, usSet, fLeft, fTop, fRight, fBottom);
}
}  // namespace fnv_0086e460

namespace fnv_0086e4b0 {
class NiGeometryData;

class NiGeometry
{
  public:
    NiGeometryData* FUN_005495f0();
};

class NiScreenElementsData
{
  public:
    void FUN_00a87900();
};

// @fnv 0x0086e4b0
void __fastcall FUN_0086e4b0(NiGeometry* apGeometry)
{
    ((NiScreenElementsData*)apGeometry->FUN_005495f0())->FUN_00a87900();
}
}  // namespace fnv_0086e4b0

struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};

extern char DAT_011f9308[];

// @fnv 0x0086e4e0
void __cdecl FUN_0086e4e0(const char* apPath)
{
    TaskQueueInterface::CopyStringToBuffer(DAT_011f9308, 0x104, apPath);
}

extern NiPointer<NiNode> DAT_011f9508;

// @fnv 0x0086e520
void __cdecl FUN_0086e520(NiNode* apRenderer)
{
    DAT_011f9508 = apRenderer;
}

namespace fnv_0086e540 {
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag();
};

extern ProcessLists g_011c7154;

// @fnv 0x0086e540
unsigned char FUN_0086e540()
{
    return *g_011c7154.GetLifeStateControlFlag();
}
}  // namespace fnv_0086e540

namespace fnv_0086e560 {
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag();
};

extern ProcessLists g_011c7544;

// @fnv 0x0086e560
unsigned char FUN_0086e560()
{
    return *g_011c7544.GetLifeStateControlFlag();
}
}  // namespace fnv_0086e560

namespace fnv_0086e580 {
struct ProcessLists
{
    unsigned char* GetLifeStateControlFlag();
};

extern ProcessLists g_011c712c;

// @fnv 0x0086e580
unsigned char FUN_0086e580()
{
    return *g_011c712c.GetLifeStateControlFlag();
}
}  // namespace fnv_0086e580

namespace fnv_0086e5a0 {
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag(void);
};

extern ProcessLists g_011c7180;

// @fnv 0x0086e5a0
unsigned char FUN_0086e5a0()
{
    return *g_011c7180.GetLifeStateControlFlag();
}
}  // namespace fnv_0086e5a0

namespace fnv_0086e5c0 {
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag();
};
extern ProcessLists g_011c7368;

// @fnv 0x0086e5c0
unsigned char FUN_0086e5c0()
{
    return *g_011c7368.GetLifeStateControlFlag();
}
}  // namespace fnv_0086e5c0

namespace fnv_0086e5e0 {
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag(void);
};
extern ProcessLists g_011c7380;

// @fnv 0x0086e5e0
unsigned char FUN_0086e5e0()
{
    return *g_011c7380.GetLifeStateControlFlag();
}
}  // namespace fnv_0086e5e0

namespace fnv_0086e600 {
struct ProcessLists
{
    unsigned char* GetLifeStateControlFlag();
};

extern ProcessLists g_011c7550;

// @fnv 0x0086e600
unsigned char FUN_0086e600()
{
    return *g_011c7550.GetLifeStateControlFlag();
}
}  // namespace fnv_0086e600

extern NiPointer<NiNode> g_011d86bc;

// @fnv 0x0086e630
void FUN_0086e630(NiNode* apTreeNode)
{
    g_011d86bc = apTreeNode;
}

extern int DAT_011f9138;

// @fnv 0x0086ef40
void FUN_0086ef40()
{
    DAT_011f9138 = DAT_011f9138 + 1;
}

class StartMenu
{
  public:
    enum Flag
    {
    };
    bool IsFlagSet(Flag);
};

extern StartMenu* DAT_011daac0;

// @fnv 0x0086efa0
bool FUN_0086efa0()
{
    return DAT_011daac0 && DAT_011daac0->IsFlagSet((StartMenu::Flag)0x10000);
}

namespace fnv_0086f260 {
struct TG
{
};
struct PL
{
    unsigned char* GetLifeStateControlFlag();
};
struct GlobalA
{
};
struct SetA
{
    float* Float();
};
struct BGSLoadFormBuffer
{
    void FUN_008a8150(unsigned char);
};
struct GameTimerRecord
{
    void Update();
};
struct Twin_0084d030
{
    float GetStoredFloatValue();
};
struct TESObjectREFR
{
    unsigned int GetFlags();
};
extern TG g_timeGlobal;
extern PL g_011dedbc;
extern SetA g_011c5724;
extern SetA originalRuntimeFloatSetting807;
extern bool DAT_011dea2b;
extern float DAT_011afe60;
extern float DAT_011dea30;
extern TESObjectREFR DAT_011f2250;
void __cdecl FUN_00aa4e40();
bool __cdecl FUN_00525420();
void __cdecl FUN_00c66760(float, bool, bool);
void __cdecl FUN_0086f330();
struct Mover
{
    void FUN_0086f260();
};
// @fnv 0x0086f260
void Mover::FUN_0086f260()
{
    ((BGSLoadFormBuffer*)&g_timeGlobal)->FUN_008a8150(*g_011dedbc.GetLifeStateControlFlag());
    if (!DAT_011dea2b)
        FUN_00aa4e40();
    ((GameTimerRecord*)&g_timeGlobal)->Update();
    DAT_011afe60 = *originalRuntimeFloatSetting807.Float();
    FUN_00c66760(((Twin_0084d030*)&g_timeGlobal)->GetStoredFloatValue(), FUN_00525420(), DAT_011f2250.GetFlags() == 4);
    FUN_0086f330();
    DAT_011dea30 =
        (float)(DAT_011dea2b ? 0.0 : ((Twin_0084d030*)&g_timeGlobal)->GetStoredFloatValue() * *g_011c5724.Float());
}
}  // namespace fnv_0086f260

extern float(__cdecl* DAT_011f91f0)(int);
extern float DAT_011f940c[4];

// Fills the four-element DAT_011f940c array by calling DAT_011f91f0 for each index, or storing 0.0f when the function pointer is null.
// @fnv 0x0086f330
void FUN_0086f330()
{
    for (int i = 0; i < 4; i++)
    {
        DAT_011f940c[i] = DAT_011f91f0 ? DAT_011f91f0(i) : 0.0f;
    }
}

namespace fnv_0086f390 {
struct FUN_0086f390_shell : public Main
{
    void FUN_0086f390();
};

struct PlayerCharacter
{
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p40();
    virtual void p41();
    virtual void p42();
    virtual void p43();
    virtual void p44();
    virtual void p45();
    virtual void p46();
    virtual void p47();
    virtual void p48();
    virtual void p49();
    virtual void p50();
    virtual void p51();
    virtual void p52();
    virtual void p53();
    virtual void p54();
    virtual void p55();
    virtual void p56();
    virtual void p57();
    virtual void p58();
    virtual void p59();
    virtual void p60();
    virtual void p61();
    virtual void p62();
    virtual void p63();
    virtual void p64();
    virtual void p65();
    virtual void p66();
    virtual void p67();
    virtual void p68();
    virtual void p69();
    virtual void p70();
    virtual void p71();
    virtual void p72();
    virtual void p73();
    virtual void p74();
    virtual void p75();
    virtual void p76();
    virtual void p77();
    virtual void p78();
    virtual void p79();
    virtual void p80();
    virtual void p81();
    virtual void p82();
    virtual void p83();
    virtual void p84();
    virtual void p85();
    virtual void p86();
    virtual void p87();
    virtual void p88();
    virtual void p89();
    virtual void p90();
    virtual void p91();
    virtual void p92();
    virtual void p93();
    virtual void p94();
    virtual void p95();
    virtual void p96();
    virtual void p97();
    virtual void p98();
    virtual void p99();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual void p116();
    virtual void p117();
    virtual void p118();
    virtual void p119();
    virtual void p120();
    virtual void p121();
    virtual void p122();
    virtual void p123();
    virtual void p124();
    virtual void p125();
    virtual void p126();
    virtual void p127();
    virtual void p128();
    virtual void p129();
    virtual void p130();
    virtual void p131();
    virtual void p132();
    virtual void p133();
    virtual void p134();
    virtual void p135();
    virtual void p136();
    virtual void p137();
    virtual void p138();
    virtual bool V8B(int);
    static bool UpdatePlayerStatus();
    bool FUN_007d1360();
};
struct TESObjectREFR
{
    unsigned int GetFlags();
};
struct TimeGlobal
{
    float GetSecondsPassed();
};
struct Interface
{
    enum enumMenus
    {
        MENU_DUMMY
    };
    static bool IsMenuActive(enumMenus, unsigned int);
};
struct HotkeyWheelDisplay
{
    void FUN_00a23010();
    void FUN_00a257c0(float);
    void FUN_00a253d0();
};
extern PlayerCharacter* pPlayer;
extern TESObjectREFR DAT_011f2250;
extern TimeGlobal g_timeGlobal;
HotkeyWheelDisplay* __cdecl FUN_007fdf30();
bool __cdecl FUN_00709bc0();
// @fnv 0x0086f390
void FUN_0086f390_shell::FUN_0086f390()
{
    FUN_007fdf30()->FUN_00a23010();
    FUN_007fdf30()->FUN_00a257c0(g_timeGlobal.GetSecondsPassed());
    if (!*((unsigned char*)this + 6) && !pPlayer->V8B(0))
    {
        if ((DAT_011f2250.GetFlags() == 4 && !pPlayer->FUN_007d1360()) || FUN_00709bc0())
        {
            if (!Interface::IsMenuActive((Interface::enumMenus)0x3e9, 0) && !PlayerCharacter::UpdatePlayerStatus())
                FUN_007fdf30()->FUN_00a253d0();
        }
    }
}
}  // namespace fnv_0086f390

struct FUN_0086f640_shell : public Main
{
    void FUN_0086f640();
};

class BSAudio
{
  public:
    static BSAudio* __cdecl GetSingleton();
    void Update(bool);
};

class FalloutRadio
{
  public:
    static bool __cdecl Update(bool);
};

class FalloutAudioMedia
{
  public:
    static void __cdecl Update();
};

class SoundPlaybackManager
{
  public:
    static void __cdecl ProcessPendingSounds();
};

// @fnv 0x0086f640
void FUN_0086f640_shell::FUN_0086f640()
{
    BSAudio::GetSingleton()->Update(true);
    FalloutRadio::Update(false);
    FalloutAudioMedia::Update();
    SoundPlaybackManager::ProcessPendingSounds();
}

struct FUN_0086f670_shell : public Main
{
    void FUN_0086f670();
};

extern unsigned char DAT_012682f8;
extern unsigned char DAT_011df678;
extern unsigned char DAT_011dea2a;
class TES;
extern TES* g_TES;

void __cdecl FUN_005a38e0();
void __fastcall FUN_00455490(TES* pTES);

// @fnv 0x0086f670
void FUN_0086f670_shell::FUN_0086f670()
{
    DAT_012682f8 = 0;
    DAT_011df678 = 0;
    DAT_011dea2a = 0;
    FUN_005a38e0();
    FUN_00455490(g_TES);
}

// @fnv 0x0086f840
bool __fastcall FUN_0086f840(char* pThis)
{
    return *(bool*)(pThis + 0x16c);
}

extern bool* DAT_011d9510;

// Returns the byte at offset 0x131 of the object pointed to by DAT_011d9510, or false if that pointer is null.
// @fnv 0x0086f860
bool FUN_0086f860()
{
    return DAT_011d9510 ? DAT_011d9510[0x131] : false;
}

struct FUN_0086f890_shell : public Main
{
    void FUN_0086f890();
};

struct GlobalObject2_0040c150
{
    int* Int(void);
};

extern GlobalObject2_0040c150 g_011c3ea4;
extern bool DAT_011dea2b;
extern bool DAT_011dea2d;
extern bool DAT_011dea2e;
extern PlayerCharacter* pPlayer;
extern int DAT_011e0e80;
extern int DAT_011e0fe0;
extern TESWorldSpace* BGSSaveLoadGlobalDataWorldspacePtr;

void __fastcall FUN_0096eb40(void* pThis);
void __fastcall FUN_008c94e0(void* pThis);
void __fastcall FUN_00991dc0(void* pThis);
void __fastcall FUN_0096d810(void* pThis);
void __fastcall FUN_00964260(void* pThis);

// @fnv 0x0086f890
void FUN_0086f890_shell::FUN_0086f890()
{
    if (*g_011c3ea4.Int() == 1)
    {
        FUN_0096eb40(&DAT_011e0e80);
    }

    if ((!DAT_011dea2b || DAT_011dea2d) && !DAT_011dea2e && !((unsigned char*)this)[7])
    {
        if (*g_011c3ea4.Int() == 1)
        {
            FUN_008c94e0(&DAT_011e0fe0);
            FUN_00991dc0(BGSSaveLoadGlobalDataWorldspacePtr);
        }
        FUN_0096d810(&DAT_011e0e80);
    }
    else if (DAT_011dea2b || ((unsigned char*)this)[7])
    {
        FUN_00964260(pPlayer);
    }
}

void __cdecl FUN_007027e0();
void __cdecl FUN_00702810();
void __cdecl FUN_00702840();

// @fnv 0x0086fd70
void __fastcall FUN_0086fd70(void* pThis)
{
    FUN_007027e0();
    FUN_00702810();
    FUN_00702840();
}

extern float DAT_011c96fc;

// @fnv 0x0086ff50
void __cdecl FUN_0086ff50(float afDelta)
{
    DAT_011c96fc += afDelta;
}

namespace fnv_008705d0 {
struct GlobalObject2_0040c150
{
    int* Int();
};

extern GlobalObject2_0040c150 g_011c3ea4;

void __fastcall FUN_0086f640(void* pThis);
void __fastcall FUN_0086f890(void* pThis);
void __cdecl FUN_00552570();
void __fastcall FUN_0086f670(void* pThis);

// Calls FUN_0086f640, FUN_0086f890, then FUN_00552570 if *g_011c3ea4.Int() > 1, and finally FUN_0086f670 on pThis.
// @fnv 0x008705d0
void __fastcall FUN_008705d0(void* pThis)
{
    FUN_0086f640(pThis);
    FUN_0086f890(pThis);
    if (*g_011c3ea4.Int() > 1)
    {
        FUN_00552570();
    }
    FUN_0086f670(pThis);
}
}  // namespace fnv_008705d0

namespace fnv_00870610 {
struct FUN_00870610_shell : public Main
{
    void FUN_00870610();
};

class GlobalObject2_0040c150
{
  public:
    int* Int(void);
};

class TaskQueueInterface
{
  public:
    static TaskQueueInterface* __cdecl GetSingleton(void);
    void ProcessTaskQueue(void);
};

class DebugText
{
  public:
    static DebugText* __cdecl Instance(bool);
};

extern GlobalObject2_0040c150 g_011c3ea4;

void* __cdecl FUN_004b7210(void);
void __cdecl FUN_005aa720(void);
void __cdecl FUN_007094f0(void);
void __fastcall FUN_00870680(void*);
void __fastcall FUN_0087a6f0(TaskQueueInterface*);
void __fastcall FUN_0087a710(TaskQueueInterface*);
void __fastcall FUN_00a0e770(DebugText*);

// @fnv 0x00870610
void FUN_00870610_shell::FUN_00870610()
{
    FUN_005aa720();
    if (*g_011c3ea4.Int() > 1)
    {
        FUN_0087a710(TaskQueueInterface::GetSingleton());
        TaskQueueInterface::GetSingleton()->ProcessTaskQueue();
        FUN_0087a6f0(TaskQueueInterface::GetSingleton());
    }
    FUN_007094f0();
    FUN_00870680(FUN_004b7210());
    FUN_00a0e770(DebugText::Instance(true));
}
}  // namespace fnv_00870610

void __cdecl FUN_00706320(int);

// If the byte at offset 0x4cc is set, calls FUN_00706320(0) and clears that byte.
// @fnv 0x00870680
void __fastcall FUN_00870680(int param_1)
{
    if (*(unsigned char*)(param_1 + 0x4cc))
    {
        FUN_00706320(0);
        *(unsigned char*)(param_1 + 0x4cc) = 0;
    }
}

namespace fnv_008706b0 {
struct BSRenderedTexture;
struct FUN_008706b0_shell : public Main
{
    void FUN_008706b0(BSRenderedTexture*, bool, bool);
};

struct P3
{
    float x, y, z;
};
struct ShadowSceneNode
{
    bool FUN_00870770();
    void FUN_00870790(P3);
};
struct NiNode
{
    const P3& FUN_0045bb80() const;
};
struct BSFaceGenAnimationData : public NiNode
{
};
struct BSFaceGenNiNode
{
    BSFaceGenAnimationData* GetAnimationData();
};
struct NiAdditionalGeometryData
{
    static ShadowSceneNode* GetShadowSceneNodeForIndex(int);
};
struct Interface
{
    enum enumMenus
    {
        MENU_DUMMY
    };
    static bool IsMenuActive(enumMenus, unsigned int);
};
struct MainStub
{
    void FUN_008707c0(BSRenderedTexture*, bool);
    void FUN_00870a00(BSRenderedTexture*, bool);
    void FUN_00870bd0(BSRenderedTexture*, bool);
};
BSFaceGenNiNode* __cdecl FUN_0045c670();
// @fnv 0x008706b0
void FUN_008706b0_shell::FUN_008706b0(BSRenderedTexture* pTexture, bool bCheckMenu, bool bFlag)
{
    bool f = NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)->FUN_00870770();
    NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)->FUN_00870790(
        FUN_0045c670()->GetAnimationData()->FUN_0045bb80());
    if (bCheckMenu && !Interface::IsMenuActive((Interface::enumMenus)0x3f5, 0))
        ((MainStub*)this)->FUN_008707c0(pTexture, f);
    else if (f)
        ((MainStub*)this)->FUN_00870a00(pTexture, bFlag);
    else
        ((MainStub*)this)->FUN_00870bd0(pTexture, bFlag);
}
}  // namespace fnv_008706b0

// @fnv 0x00870770
bool __fastcall FUN_00870770(const char* pThis)
{
    return *(const bool*)(pThis + 0x131);
}

struct NiStream;
struct blob12
{
    char b[12];
};

struct _Fake_FUN_00870790
{
    char pad[0x1f0];
    NiPoint3 pos;
};

// Stores aPosition into the pos field of the object at offset 0x1f0.
// @fnv 0x00870790
void __fastcall FUN_00870790(_Fake_FUN_00870790* pThis, NiPoint3 aPosition)
{
    pThis->pos = aPosition;
}

// Returns whether the float at offset 0x70 of pThis is greater than zero.
// @fnv 0x00871220
bool __fastcall FUN_00871220(char* pObject)
{
    return *(float*)(pObject + 0x70) > 0.0;
}

struct NiNode871
{
    unsigned int FUN_00453470();
};
struct GO871
{
    operator NiNode871*() const;
};
extern GO871 g_011c7810;
// Returns false if g_011c7810 is null, otherwise returns whether its FUN_00453470 result is greater than zero.
// @fnv 0x00871260
bool FUN_00871260()
{
    if (!(NiNode871*)g_011c7810)
        return false;
    return ((NiNode871*)g_011c7810)->FUN_00453470() > 0;
}

namespace fnv_00871a10 {
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag();
};

extern ProcessLists g_011c74d4;

// @fnv 0x00871a10
unsigned char FUN_00871a10()
{
    return *g_011c74d4.GetLifeStateControlFlag();
}
}  // namespace fnv_00871a10

// @fnv 0x00871a30
int __fastcall FUN_00871a30(int param_1)
{
    return param_1 + 0x88;
}

namespace fnv_00871c90 {
struct ProcessLists
{
    unsigned char* GetLifeStateControlFlag();
};
struct HotkeyWheelDisplay
{
    void FUN_00a23010();
};
struct GameTimerRecord
{
    void Enable();
};
struct GlobalObject_0045cf30
{
};
struct TimeGlobal
{
};
extern GlobalObject_0045cf30 g_011deed8;
extern TimeGlobal g_timeGlobal;
HotkeyWheelDisplay* FUN_007fdf30();
void __fastcall FUN_00a237b0(HotkeyWheelDisplay*);
void __fastcall FUN_00a253d0(HotkeyWheelDisplay*);
void __fastcall FUN_00aa50a0(TimeGlobal*);
struct FUN_00871c90_shell
{
    char pad[3];
    bool f;
    void FUN_00871c90(bool b);
};
// @fnv 0x00871c90
void FUN_00871c90_shell::FUN_00871c90(bool abEnabled)
{
    if (*((ProcessLists*)&g_011deed8)->GetLifeStateControlFlag())
        abEnabled = 1;
    if (FUN_007fdf30())
    {
        FUN_00a237b0(FUN_007fdf30());
        FUN_007fdf30()->FUN_00a23010();
        FUN_00a253d0(FUN_007fdf30());
    }
    if (abEnabled)
        ((GameTimerRecord*)&g_timeGlobal)->Enable();
    else
        FUN_00aa50a0(&g_timeGlobal);
    f = abEnabled;
}
}  // namespace fnv_00871c90

struct O872
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
    virtual int vf();
};
struct H872
{
    int pad;
    operator O872*() const;
};
struct S872
{
    char p[0x30];
    H872 h[1];
    int FUN_00872370(unsigned int i);
};
// Returns the virtual call result of the element at index i, or 0 when that element is null.
// @fnv 0x00872370
int S872::FUN_00872370(unsigned int uiIndex)
{
    return h[uiIndex] ? ((O872*)h[uiIndex])->vf() : 0;
}

namespace fnv_008723d0 {
struct O872
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
    virtual int vf();
};
struct H872
{
    int pad;
    operator O872*() const;
};
struct S872
{
    char p[0x30];
    H872 h[1];
    int FUN_008723d0(unsigned int i);
};
// Returns the result of the virtual call on the object at index i, or 0 if that slot is null.
// @fnv 0x008723d0
int S872::FUN_008723d0(unsigned int uiIndex)
{
    return h[uiIndex] ? ((O872*)h[uiIndex])->vf() : 0;
}
}  // namespace fnv_008723d0

struct FUN_00874460_cls
{
    char pad[0xc0];
    int m_field_c0;
    void set(int v);
};

// @fnv 0x00874460
void FUN_00874460_cls::set(int aiValue)
{
    m_field_c0 = aiValue;
}

// @fnv 0x00874480
int __fastcall FUN_00874480(char* pThis)
{
    return *(int*)(pThis + 0xfc);
}

// @fnv 0x00874670
void* __fastcall FUN_00874670(char* pThis)
{
    return pThis + 0x138;
}

// @fnv 0x00874900
float __fastcall FUN_00874900(const char* pThis)
{
    return *(const float*)(pThis + 0x674);
}

namespace fnv_00874ac0 {
struct FUN_00874ac0_shell : public Main
{
    void FUN_00874ac0(bool);
};

struct StrG
{
    operator const char*() const;
};
extern StrG g_011deb38;
enum BSRENDERSTATE_LOCK
{
    BSRS_LOCK_DUMMY
};
struct BSRenderStateManager
{
    static void SetColorWriteMask(unsigned int, BSRENDERSTATE_LOCK);
};
struct BSRenderedTexture
{
    static void EndAllAndResetRendererState();
};
struct KFModel
{
    void* GetControllerSequence();
    void FUN_00800f30(const char*, int, int, int, int, int);
};
struct ShadowLightData : public KFModel
{
};
struct Interface
{
    static ShadowLightData* GetVATSEffect();
};
void __cdecl FUN_004eced0(int);
// @fnv 0x00874ac0
void FUN_00874ac0_shell::FUN_00874ac0(bool b)
{
    void* seq = Interface::GetVATSEffect()->GetControllerSequence();
    if (seq)
    {
        BSRenderedTexture::EndAllAndResetRendererState();
        BSRenderStateManager::SetColorWriteMask(0, (BSRENDERSTATE_LOCK)1);
        Interface::GetVATSEffect()->FUN_00800f30((const char*)g_011deb38, 0, 0, 1, 7, 0);
        FUN_004eced0(1);
        Interface::GetVATSEffect()->FUN_00800f30((const char*)g_011deb38, 0, 0, 0, 1, 1);
    }
}
}  // namespace fnv_00874ac0

struct BSRenderedTexture;
struct ImageSpaceEffect;
struct ImageSpaceEffectParam;
struct ImageSpaceTexture;
struct RgbaColor;
struct NiPoint2;
struct NiScreenElements;
struct NiTexture;
struct GraphicsRenderer;
struct blob16
{
    char b[16];
};
struct ImageSpaceManager
{
    void Initialize();
    void Shutdown();
    void InitDefaultParameter();
    ImageSpaceEffect* GetEffect(int);
    void AddEffect(int, ImageSpaceEffect*);
    bool IsEffectActive(int);
    void SetupEffects();
    void SetupShader();
    void RenderEndOfFrameEffects(GraphicsRenderer*, BSRenderedTexture**, BSRenderedTexture**);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*,
                      bool);
    void RenderEffect(int, GraphicsRenderer*, NiTexture*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, BSRenderedTexture*,
                      ImageSpaceEffectParam*, bool);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*,
                      ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void ModifyParameterData(int, unsigned int, int, float);
    void ApplyCurrentParameterData(bool);
    void SetBaseParameterData(void*);
    void SetOverrideBaseParameterData(void*);
    void ResetToBaseParameterData();
    void ResetWeatherData();
    void BeginParamModifiers();
    void ApplyParamModifier(int, unsigned int, float*, float);
    void ApplyParamModifierWeather(int, unsigned int, float*, float);
    void ApplyTintColorParamModifier(RgbaColor*);
    void ApplyTintColorParamModifierWeather(RgbaColor*);
    void SetFadeColorParamModifier(RgbaColor*);
    void ApplyFadeColorParamModifierWeather(RgbaColor*);
    void SetBlurRadiusParamModifier(float);
    void ApplyBlurRadiusParamModifierWeather(float);
    void ApplyDoubleVisionParamModifier(float);
    void ApplyDoubleVisionParamModifierWeather(float);
    void SetRadialBlurParameters(float, float, float, float, float, void*);
    void ApplyRadialBlurParamModifierWeather(float, float, float, float, float, void*);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, float, float, void*);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, void*);
    void SetDepthOfFieldParameters(float, unsigned int, float, float, float);
    void SetDepthOfFieldParameters(float, unsigned int, float, void*);
    void ApplyDepthOfFieldParamModifierWeather(float, unsigned int, float, float, float);
    void ApplyMotionBlurStrengthParamModifier(float);
    void ApplyMotionBlurStrengthParamModifierWeather(float);
    void EndWeatherModifiers();
    void EndParamModifiers();
    float ApplyOperation(int, float, float);
    void GetRadialBlurCenterFromWorldBound(void*, NiPoint2*);
    void GetDepthOfFieldParamsFromWorldBound(void*, NiPoint2*);
    void EnableSunbeams(bool);
    void SetSunPosition(void*);
    BSRenderedTexture* GetRefractionNormalsTexture(bool);
    BSRenderedTexture* GetVolumetricFogTexture();
    void ReturnVolumetricFogTexture();
    float GetHDREmissiveMult();
    float GetHDRBlurRadius();
    float GetHDRBrightClamp();
    float GetHDRBrightScale();
    float GetHDREyeAdaptSpeed();
    float GetHDRTargetLUM();
    float GetHDRUpperLUMClamp();
    void SetVolumetricFogProps(struct blob16);
    void SetMotionBlurConst(float);
    void SetMenuBGBlendEnabled(bool);
    void SetMenuBGBlendValue(float);
    void EnablePartialRender(bool, NiScreenElements*);
    void SetMenuBackgroundBlend(float, float, void*);
    NiTexture* GetDepthTexture();
    ImageSpaceTexture* GetDepthImageSpaceTexture();
    BSRenderedTexture* GetDepthRenderedTexture();
    void SetDepthTexture(BSRenderedTexture*);
    void SetDepthTexture(NiTexture*);
    void ReturnDepthTexture();
    NiScreenElements* GetMenuUnpackGeom();
    void SetMenuUnpackGeom(NiScreenElements*);
    void SetRefractionTint(void*);
    void* GetRefractionTint();
    void SetCustomViewPort(float, float, float, float);
    void ClearCustomViewPort();
    void* GetCustomViewport();
    BSRenderedTexture* GetSwapTarget();
    void InitEffects();
    void CreateMenuBackgroundGeometry();
    void ShutdownEffects();
    void ShutdownGeometry();
    void PrepareEndOfFrameEffects();
    void* __vecDelDtor(unsigned int);
    BSRenderedTexture* m_pCurrentRenderedTexture;
    char pEffectList[16];
    char m_kBlendedParameterData[152];
    void* m_pCurrentModifierParameterData;
    void* m_pPreviousModifierParameterData;
    char m_kModifierParameterData[304];
    bool m_bEndOfFrameEffectsEnabled;
    char _pad_1e5[3];
    int m_iEndOfFrameEffectCount;
    int m_eEndOfFrameEffect;
    char m_pMenuBackgroundScreenGeometry[4];
    char m_pMenuBackgroundScreenElementsData[4];
    char m_pMenuBackgroundScreenElements[4];
    bool m_bPartialRenderEnabled;
    char _pad_1fd[3];
    char m_pPartialRenderScreenElements[4];
    char m_kDepthTexture[16];
    char m_kModifierColor[16];
    char m_kPartialRenderColor[16];
    float m_fPartialRenderBlend;
    char m_kAccumulatedColor[16];
    char m_kWeatherFadeColor[16];
    float m_fFadeColorAlpha;
    float m_fDoubleVisionStrength;
    float m_fWeatherBlurRadius;
    float m_fWeatherDoubleVisionStrength;
    float m_fAdditionalImageSpaceValue;
    float m_fRadialBlurStrength;
    float m_fRadialBlurRampUp;
    float m_fRadialBlurStart;
    float m_fRadialBlurRampDown;
    float m_fRadialBlurDownStart;
    float m_fWeatherRadialBlurStrength;
    float m_fWeatherRadialBlurRampUp;
    float m_fWeatherRadialBlurStart;
    float m_fWeatherRadialBlurRampDown;
    float m_fWeatherRadialBlurDownStart;
    char m_kRadialBlurCenter[8];
    char m_kWeatherRadialBlurCenter[8];
    float m_fDepthOfFieldStrength;
    float m_fDepthOfFieldMaskConstant;
    float m_fDepthOfFieldDistance;
    float m_fDepthOfFieldRange;
    float m_fDepthOfFieldEffectStrength;
    float m_fDepthOfFieldEffectDistance;
    float m_fDepthOfFieldEffectRange;
    float m_fDepthOfFieldMaskValue;
    int m_eDepthOfFieldMode;
    int m_eDepthOfFieldTargetMode;
    bool m_bDepthOfFieldUsesObject;
    bool m_bMenuBackgroundBlendEnabled;
    char _pad_2ce[2];
    float m_fBlurRadius;
    float m_fRadialBlurTransition;
    float m_fRadialBlurStartValue;
    float m_fRadialBlurDistance;
    float m_fRadialBlurRange;
    char m_kRadialBlurOrigin[8];
    int m_eRadialBlurMode;
    float m_fMenuBackgroundBlendValue;
    float m_fMenuBackgroundBlendTarget;
    char m_kMenuBackgroundTint[16];
    char m_kMenuBackgroundRect[16];
    BSRenderedTexture* m_pMenuBackgroundTexture;
};
typedef char _sizecheck_ImageSpaceManager[sizeof(ImageSpaceManager) == 796 ? 1 : -1];
struct FUN_00874b50_shell : public Main
{
    void FUN_00874b50(BSRenderedTexture*, bool, unsigned int);
};

struct NiRenderTargetGroup;
struct BSRenderedTexture
{
    NiRenderTargetGroup* GetGroup(void);
};

bool __cdecl FUN_004e9510(void);
ImageSpaceManager* __cdecl FUN_004e3270(void);
void* __cdecl FUN_004a0e90(void);
void __cdecl FUN_00b6b8d0(unsigned int, NiRenderTargetGroup*);

// @fnv 0x00874b50
void FUN_00874b50_shell::FUN_00874b50(BSRenderedTexture* apRenderTexture, bool abMultiSampleEnabled,
                                      unsigned int auiClearMode)
{
    if (FUN_004e9510())
    {
        ImageSpaceManager* apImagespaceManager = FUN_004e3270();
        void* apRenderer = FUN_004a0e90();
        FUN_00b6b8d0(auiClearMode, apRenderTexture->GetGroup());
    }
}

namespace fnv_00874b90 {
struct BSRenderedTexture;
struct ImageSpaceEffect;
struct ImageSpaceEffectParam;
struct ImageSpaceTexture;
struct RgbaColor;
struct NiPoint2;
struct NiScreenElements;
struct NiTexture;
struct GraphicsRenderer;
struct blob16
{
    char b[16];
};
struct ImageSpaceManager
{
    void Initialize();
    void Shutdown();
    void InitDefaultParameter();
    ImageSpaceEffect* GetEffect(int);
    void AddEffect(int, ImageSpaceEffect*);
    bool IsEffectActive(int);
    void SetupEffects();
    void SetupShader();
    void RenderEndOfFrameEffects(GraphicsRenderer*, BSRenderedTexture**, BSRenderedTexture**);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*,
                      bool);
    void RenderEffect(int, GraphicsRenderer*, NiTexture*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, BSRenderedTexture*,
                      ImageSpaceEffectParam*, bool);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*,
                      ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void ModifyParameterData(int, unsigned int, int, float);
    void ApplyCurrentParameterData(bool);
    void SetBaseParameterData(void*);
    void SetOverrideBaseParameterData(void*);
    void ResetToBaseParameterData();
    void ResetWeatherData();
    void BeginParamModifiers();
    void ApplyParamModifier(int, unsigned int, float*, float);
    void ApplyParamModifierWeather(int, unsigned int, float*, float);
    void ApplyTintColorParamModifier(RgbaColor*);
    void ApplyTintColorParamModifierWeather(RgbaColor*);
    void SetFadeColorParamModifier(RgbaColor*);
    void ApplyFadeColorParamModifierWeather(RgbaColor*);
    void SetBlurRadiusParamModifier(float);
    void ApplyBlurRadiusParamModifierWeather(float);
    void ApplyDoubleVisionParamModifier(float);
    void ApplyDoubleVisionParamModifierWeather(float);
    void SetRadialBlurParameters(float, float, float, float, float, void*);
    void ApplyRadialBlurParamModifierWeather(float, float, float, float, float, void*);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, float, float, void*);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, void*);
    void SetDepthOfFieldParameters(float, unsigned int, float, float, float);
    void SetDepthOfFieldParameters(float, unsigned int, float, void*);
    void ApplyDepthOfFieldParamModifierWeather(float, unsigned int, float, float, float);
    void ApplyMotionBlurStrengthParamModifier(float);
    void ApplyMotionBlurStrengthParamModifierWeather(float);
    void EndWeatherModifiers();
    void EndParamModifiers();
    float ApplyOperation(int, float, float);
    void GetRadialBlurCenterFromWorldBound(void*, NiPoint2*);
    void GetDepthOfFieldParamsFromWorldBound(void*, NiPoint2*);
    void EnableSunbeams(bool);
    void SetSunPosition(void*);
    BSRenderedTexture* GetRefractionNormalsTexture(bool);
    BSRenderedTexture* GetVolumetricFogTexture();
    void ReturnVolumetricFogTexture();
    float GetHDREmissiveMult();
    float GetHDRBlurRadius();
    float GetHDRBrightClamp();
    float GetHDRBrightScale();
    float GetHDREyeAdaptSpeed();
    float GetHDRTargetLUM();
    float GetHDRUpperLUMClamp();
    void SetVolumetricFogProps(struct blob16);
    void SetMotionBlurConst(float);
    void SetMenuBGBlendEnabled(bool);
    void SetMenuBGBlendValue(float);
    void EnablePartialRender(bool, NiScreenElements*);
    void SetMenuBackgroundBlend(float, float, void*);
    NiTexture* GetDepthTexture();
    ImageSpaceTexture* GetDepthImageSpaceTexture();
    BSRenderedTexture* GetDepthRenderedTexture();
    void SetDepthTexture(BSRenderedTexture*);
    void SetDepthTexture(NiTexture*);
    void ReturnDepthTexture();
    NiScreenElements* GetMenuUnpackGeom();
    void SetMenuUnpackGeom(NiScreenElements*);
    void SetRefractionTint(void*);
    void* GetRefractionTint();
    void SetCustomViewPort(float, float, float, float);
    void ClearCustomViewPort();
    void* GetCustomViewport();
    BSRenderedTexture* GetSwapTarget();
    void InitEffects();
    void CreateMenuBackgroundGeometry();
    void ShutdownEffects();
    void ShutdownGeometry();
    void PrepareEndOfFrameEffects();
    void* __vecDelDtor(unsigned int);
    BSRenderedTexture* m_pCurrentRenderedTexture;
    char pEffectList[16];
    char m_kBlendedParameterData[152];
    void* m_pCurrentModifierParameterData;
    void* m_pPreviousModifierParameterData;
    char m_kModifierParameterData[304];
    bool m_bEndOfFrameEffectsEnabled;
    char _pad_1e5[3];
    int m_iEndOfFrameEffectCount;
    int m_eEndOfFrameEffect;
    char m_pMenuBackgroundScreenGeometry[4];
    char m_pMenuBackgroundScreenElementsData[4];
    char m_pMenuBackgroundScreenElements[4];
    bool m_bPartialRenderEnabled;
    char _pad_1fd[3];
    char m_pPartialRenderScreenElements[4];
    char m_kDepthTexture[16];
    char m_kModifierColor[16];
    char m_kPartialRenderColor[16];
    float m_fPartialRenderBlend;
    char m_kAccumulatedColor[16];
    char m_kWeatherFadeColor[16];
    float m_fFadeColorAlpha;
    float m_fDoubleVisionStrength;
    float m_fWeatherBlurRadius;
    float m_fWeatherDoubleVisionStrength;
    float m_fAdditionalImageSpaceValue;
    float m_fRadialBlurStrength;
    float m_fRadialBlurRampUp;
    float m_fRadialBlurStart;
    float m_fRadialBlurRampDown;
    float m_fRadialBlurDownStart;
    float m_fWeatherRadialBlurStrength;
    float m_fWeatherRadialBlurRampUp;
    float m_fWeatherRadialBlurStart;
    float m_fWeatherRadialBlurRampDown;
    float m_fWeatherRadialBlurDownStart;
    char m_kRadialBlurCenter[8];
    char m_kWeatherRadialBlurCenter[8];
    float m_fDepthOfFieldStrength;
    float m_fDepthOfFieldMaskConstant;
    float m_fDepthOfFieldDistance;
    float m_fDepthOfFieldRange;
    float m_fDepthOfFieldEffectStrength;
    float m_fDepthOfFieldEffectDistance;
    float m_fDepthOfFieldEffectRange;
    float m_fDepthOfFieldMaskValue;
    int m_eDepthOfFieldMode;
    int m_eDepthOfFieldTargetMode;
    bool m_bDepthOfFieldUsesObject;
    bool m_bMenuBackgroundBlendEnabled;
    char _pad_2ce[2];
    float m_fBlurRadius;
    float m_fRadialBlurTransition;
    float m_fRadialBlurStartValue;
    float m_fRadialBlurDistance;
    float m_fRadialBlurRange;
    char m_kRadialBlurOrigin[8];
    int m_eRadialBlurMode;
    float m_fMenuBackgroundBlendValue;
    float m_fMenuBackgroundBlendTarget;
    char m_kMenuBackgroundTint[16];
    char m_kMenuBackgroundRect[16];
    BSRenderedTexture* m_pMenuBackgroundTexture;
};
typedef char _sizecheck_ImageSpaceManager[sizeof(ImageSpaceManager) == 796 ? 1 : -1];
struct FUN_00874b90_shell : public Main
{
    void FUN_00874b90(ImageSpaceManager*, GraphicsRenderer*, bool, BSRenderedTexture*);
};

struct StrG
{
    operator const char*() const;
};
extern StrG g_011ded3c;
enum BSRENDERSTATE_LOCK
{
    BSRS_LOCK_DUMMY
};
struct BSRenderStateManager
{
    static void SetDepthBufferEnabled(bool, BSRENDERSTATE_LOCK);
    static void SetColorWriteMask(unsigned int, BSRENDERSTATE_LOCK);
};
struct ISMStub
{
    void FUN_00b97550(int, GraphicsRenderer*, const char*, unsigned int, int, int);
};
void __cdecl FUN_00714ae0(int);
void __cdecl FUN_004eced0(int);
// @fnv 0x00874b90
void FUN_00874b90_shell::FUN_00874b90(ImageSpaceManager* pManager, GraphicsRenderer* r, bool c, BSRenderedTexture* d)
{
    if ((const char*)g_011ded3c)
    {
        BSRenderStateManager::SetColorWriteMask(7, (BSRENDERSTATE_LOCK)1);
        BSRenderStateManager::SetDepthBufferEnabled(false, (BSRENDERSTATE_LOCK)1);
        ((ISMStub*)pManager)->FUN_00b97550(0x22, r, (const char*)g_011ded3c, c ? 0u : (unsigned int)d, 0, 1);
        FUN_00714ae0(1);
        FUN_004eced0(1);
    }
}
}  // namespace fnv_00874b90

struct _Fake_FUN_008750e0
{
    char pad[0x1e4];
    NiPoint3 kIntersectionOffset;
    void FUN_008750e0(NiPoint3 a_kOffset);
};

// Stores the given NiPoint3 offset into the object's point field.
// @fnv 0x008750e0
void _Fake_FUN_008750e0::FUN_008750e0(NiPoint3 a_kOffset)
{
    kIntersectionOffset = a_kOffset;
}

namespace fnv_00876d20 {
class StartMenu
{
  public:
    char const* GetMenuTitle(void);
};

class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag(void);
};

class GlobalObject2_0040c150
{
  public:
    int* Int(void);
};

extern StartMenu g_011c4030;
extern GlobalObject2_0040c150 g_011deaa0;
extern GlobalObject2_0040c150 g_011deb24;
extern StartMenu g_011deb94;
extern ProcessLists g_011debdc;
extern GlobalObject2_0040c150 g_011dec40;
extern ProcessLists g_011dec4c;
extern StartMenu g_011dec68;
extern ProcessLists g_011dee3c;

void __cdecl FUN_00af43a0(unsigned char, const char*, const char*, int);
void __cdecl FUN_00af4460(unsigned char);
void __cdecl FUN_00af4470(int, int, int);
void __cdecl FUN_00af4490(unsigned char, const char*);
void __cdecl FUN_00af4550();

// @fnv 0x00876d20
void __cdecl FUN_00876d20()
{
    FUN_00af43a0(*g_011dee3c.GetLifeStateControlFlag(), g_011c4030.GetMenuTitle(), g_011deb94.GetMenuTitle(), 0x200000);
    FUN_00af4460(*g_011debdc.GetLifeStateControlFlag());
    FUN_00af4470(*g_011deb24.Int(), *g_011deaa0.Int(), *g_011dec40.Int());
    FUN_00af4490(*g_011dec4c.GetLifeStateControlFlag(), g_011dec68.GetMenuTitle());
    FUN_00af4550();
}
}  // namespace fnv_00876d20

namespace fnv_00877430 {
struct FUN_00877430_shell : public Main
{
    void FUN_00877430();
};

struct StrG
{
    operator const char*() const;
};
extern StrG g_011ded3c;
extern bool DAT_011dea29;
struct BSRenderedTexture;
struct BSTextureManager
{
    void AddRenderedTexture();
};
struct ImageSpaceManager
{
    static ImageSpaceManager* FUN_004e3270();
    void FUN_007123f0(float);
    void FUN_007123a0(int);
};
BSTextureManager* __stdcall FUN_004a0ea0(const char*);
// @fnv 0x00877430
void FUN_00877430_shell::FUN_00877430()
{
    if ((const char*)g_011ded3c)
    {
        FUN_004a0ea0((const char*)g_011ded3c)->AddRenderedTexture();
        *(NiPointer<NiNode>*)&g_011ded3c = (NiNode*)0;
        ImageSpaceManager::FUN_004e3270()->FUN_007123f0(0.0f);
        ImageSpaceManager::FUN_004e3270()->FUN_007123a0(0);
    }
    DAT_011dea29 = false;
}
}  // namespace fnv_00877430

struct Controls;
struct FUN_00877720_shell : public Main
{
    Controls* FUN_00877720();
};

Controls* __cdecl FUN_007fdf30();

// @fnv 0x00877720
Controls* FUN_00877720_shell::FUN_00877720()
{
    return FUN_007fdf30();
}

struct FUN_00936aa0_shell
{
    char pad[0x85];
    bool f;
    void FUN_00936aa0(bool b);
};
// @fnv 0x00936aa0
void FUN_00936aa0_shell::FUN_00936aa0(bool abValue)
{
    f = abValue;
}

struct Dummy_00a239e0
{
    int FUN_00a239e0(int a2);
};

// Returns the int stored at offset 0x1B24, 0x1B28 or 0x1B2C of this object depending on a2 (1, 2 or 3), otherwise 0.
// @fnv 0x00a239e0
int Dummy_00a239e0::FUN_00a239e0(int aiIndex)
{
    switch (aiIndex)
    {
    case 1:
        return *(int*)((char*)this + 0x1B24);
    case 2:
        return *(int*)((char*)this + 0x1B28);
    case 3:
        return *(int*)((char*)this + 0x1B2C);
    default:
        return 0;
    }
}

namespace fnv_0086fbe0 {
struct TES
{
    int FindCellAtPosition(NiPoint3 const*, bool);
    TESWorldSpace* GetHitSound();
    bool FUN_00451530();
};
struct TopicH
{
    NiPoint3* GetAddTopicList();
};
struct BGSCameraPath
{
    BGSCameraPath* GetPrevPath();
};
struct RefrHelper
{
    TESWorldSpace* GetParentWorldSpace();
};
struct PC7d;
extern PC7d* g_thePlayer;
extern TES* g_TES;
extern bool DAT_011dea2b;
extern bool DAT_011d8907;
struct MainStandIn
{
    char pad[7];
    bool flag7;
    void FUN_0086fbe0();
};
// @fnv 0x0086fbe0
void MainStandIn::FUN_0086fbe0()
{
    if (!DAT_011dea2b && !DAT_011d8907 && !flag7)
    {
        g_TES->FindCellAtPosition(((TopicH*)g_thePlayer)->GetAddTopicList(), true);
        if (g_TES->FUN_00451530() && !((BGSCameraPath*)g_TES)->GetPrevPath())
        {
            if (((RefrHelper*)g_thePlayer)->GetParentWorldSpace() == g_TES->GetHitSound())
            {
            }
        }
    }
}
}  // namespace fnv_0086fbe0

struct Flt
{
    operator unsigned int() const;
};
struct Helper62d0
{
    Helper62d0& operator=(void* const&);
};
struct Obj008731d0
{
    char pad0[8];
    Helper62d0 h;
    char pad1[0x20 - 9];
    void* f;
    void FUN_008731d0();
};
// If the pointer field f is non-null, assigns it to the helper member h.
// @fnv 0x008731d0
void Obj008731d0::FUN_008731d0()
{
    if (*(Flt*)&f)
        h = f;
}

namespace fnv_008749b0 {
struct NiRenderer;
struct BSRenderedTexture;
struct BSTextureManager
{
    BSRenderedTexture* CreateRenderTargetTexture(NiRenderer*, int, unsigned int, BSRenderedTexture*, unsigned int);
};
struct NP_0081c630
{
    NP_0081c630& operator=(void*);
};
struct Flt
{
    operator unsigned int() const;
};
struct KFModel
{
    void* GetControllerSequence();
};
struct VATSEffect
{
    bool FUN_00874aa0();
    void FUN_00800f30(unsigned int, int, int, int, int, int);
};
struct Interface
{
    static VATSEffect* __cdecl GetVATSEffect();
};
NiRenderer* __cdecl FUN_0043c4b0();
BSTextureManager* __stdcall FUN_004a0ea0();
extern NP_0081c630 g_011deb38;

// @fnv 0x008749b0
bool __fastcall FUN_008749b0(void* self)
{
    bool bissuedVATSQuery = false;
    if (((KFModel*)Interface::GetVATSEffect())->GetControllerSequence())
    {
        if (!(unsigned int)*(Flt*)&g_011deb38)
        {
            g_011deb38 = FUN_004a0ea0()->CreateRenderTargetTexture(FUN_0043c4b0(), 0x2f, 0, 0, 0);
        }
        if (!(unsigned int)*(Flt*)Interface::GetVATSEffect() && (unsigned int)*(Flt*)&g_011deb38 &&
            ((KFModel*)Interface::GetVATSEffect())->GetControllerSequence() &&
            Interface::GetVATSEffect()->FUN_00874aa0())
        {
            Interface::GetVATSEffect()->FUN_00800f30((unsigned int)*(Flt*)&g_011deb38, 0, 1, 0, 7, 0);
            Interface::GetVATSEffect()->FUN_00800f30((unsigned int)*(Flt*)&g_011deb38, 1, 1, 0, 1, 1);
            bissuedVATSQuery = true;
        }
    }
    return bissuedVATSQuery;
}
}  // namespace fnv_008749b0

struct Arr
{
    unsigned int GetSize(void);
    unsigned int* GetAt(int);
};

struct SomeClass
{
    int m_ucUnknownByte[0xad4 / 4];
    Arr m_aiIndexedValues;
    int FUN_0086bb70(unsigned int value);
};

// @fnv 0x0086bb70
int SomeClass::FUN_0086bb70(unsigned int value)
{
    for (int i = 0; i < m_aiIndexedValues.GetSize(); i++)
    {
        if (*m_aiIndexedValues.GetAt(i) == value)
            return i;
    }
    return -1;
}

extern unsigned char DAT_011f4448;

// @fnv 0x0086bcc0
void FUN_0086bcc0(unsigned char value)
{
    DAT_011f4448 = value;
}

void* DAT_011f6e08;

// @fnv 0x0086bcd0
void FUN_0086bcd0(void* obj)
{
    DAT_011f6e08 = obj;
}

extern int DAT_011f6224;

// @fnv 0x0086bd90
void FUN_0086bd90(int value)
{
    DAT_011f6224 = value;
}

struct GlobalObject_0083b5e0
{
    void RemoveAll();
};

extern GlobalObject_0083b5e0 g_011dd948;

// @fnv 0x0086bdd0
void FUN_0086bdd0()
{
    g_011dd948.RemoveAll();
}

extern double(__cdecl* DAT_011f9134)(void*);

// @fnv 0x0086bde0
void FUN_0086bde0(double(__cdecl* value)(void*))
{
    DAT_011f9134 = value;
}

extern int DAT_011d5c44;

// @fnv 0x0086be80
void FUN_0086be80(int value)
{
    DAT_011d5c44 = value;
}

extern NiNode* DAT_011d59ec;

// @fnv 0x0086be90
void FUN_0086be90(NiNode* value)
{
    DAT_011d59ec = value;
}

extern bool DAT_011a31f4;

// @fnv 0x0086bea0
void FUN_0086bea0(bool value)
{
    DAT_011a31f4 = value;
}

struct GlobalObject_00633c90
{
    GlobalObject_00633c90& operator=(void*);
};

extern GlobalObject_00633c90 g_011d8690;
extern GlobalObject_00633c90 g_011d86a8;
extern NiPointer<NiNode> g_011d86bc;

// Clears the three global objects by assigning null to g_011d86bc, g_011d86a8 and g_011d8690.
// @fnv 0x0086beb0
void FUN_0086beb0()
{
    g_011d86bc = 0;
    g_011d86a8 = 0;
    g_011d8690 = 0;
}

struct FUN_0086bf40
{
    void __thiscall FUN_0086c880();
    void* __thiscall DeleteThis(unsigned int flags);
};

// Calls FUN_0086c880, frees this when flags has bit 0 set, and returns this.
// @fnv 0x0086bf40
void* __thiscall FUN_0086bf40::DeleteThis(unsigned int flags)
{
    FUN_0086c880();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern int DAT_011dea18;

// @fnv 0x0086d470
int __cdecl FUN_0086d470()
{
    return DAT_011dea18;
}

extern int DAT_01202e98;

// @fnv 0x0086d480
int* __cdecl FUN_0086d480()
{
    return &DAT_01202e98;
}

namespace fnv_0086d580 {
extern int DAT_011c6fc8;

// @fnv 0x0086d580
int* __cdecl FUN_0086d580()
{
    return &DAT_011c6fc8;
}
}  // namespace fnv_0086d580

class NiAVObject;
extern unsigned int(__cdecl* DAT_011f91ec)(NiAVObject*);

// @fnv 0x0086e4d0
void FUN_0086e4d0(unsigned int(__cdecl* apObjectTypeFunc)(NiAVObject*))
{
    DAT_011f91ec = apObjectTypeFunc;
}

extern bool DAT_011f91de;

// @fnv 0x0086e500
void FUN_0086e500(bool abSeparateAmbientLight)
{
    DAT_011f91de = abSeparateAmbientLight;
}

extern unsigned char DAT_011f91dd;

// @fnv 0x0086e510
void FUN_0086e510(unsigned char value)
{
    DAT_011f91dd = value;
}

extern int DAT_011f9644;

// @fnv 0x0086e620
void FUN_0086e620(int apLODTreeParent)
{
    DAT_011f9644 = apLODTreeParent;
}

extern unsigned char DAT_012677a2;

// @fnv 0x0086ef30
void FUN_0086ef30()
{
    DAT_012677a2 = 0;
}

extern unsigned char DAT_011f4461;

// @fnv 0x0086ef60
unsigned char FUN_0086ef60()
{
    return DAT_011f4461;
}

extern "C" float DAT_01267c1c;

// @fnv 0x0086ef90
void FUN_0086ef90()
{
    DAT_01267c1c = 0.0f;
}

namespace fnv_0086efe0 {
struct SettingFloat
{
    float* Float();
};
struct TESWorldSpace
{
    enum PARENT_USE_FLAG
    {
        USE_LAND = 1
    };
    TESWorldSpace* GetParentWorld(PARENT_USE_FLAG flag);
};
struct TES
{
    TESWorldSpace* GetParentWorldSpace();
};
struct ActorS
{
    TESObjectCELL* GetParentCell();
};
struct PC7d : ActorS
{
};
extern TES* g_TES;
extern PC7d* g_thePlayer;
extern SettingFloat g_011dea80;
extern SettingFloat g_011deb10;
extern SettingFloat g_011dec24;
extern SettingFloat g_011dec7c;
extern SettingFloat g_011decc8;
extern SettingFloat g_011ded8c;
extern SettingFloat g_011ded98;
extern SettingFloat g_011deddc;
extern SettingFloat g_011dee54;
bool __cdecl FUN_00525420();
bool __fastcall FUN_00425fd0(TESObjectCELL* cell);
void __cdecl FUN_0086f160(float);
void __cdecl FUN_0086f170(float);
void __cdecl FUN_0086f180(float);

struct FUN_0086efe0_t
{
    void FUN_0086efe0();
};

// @fnv 0x0086efe0
void FUN_0086efe0_t::FUN_0086efe0()
{
    if (FUN_00525420())
    {
        FUN_0086f160(*g_011dec24.Float());
        FUN_0086f170(*g_011deb10.Float());
        FUN_0086f180(*g_011ded8c.Float());
    }
    else if (g_TES->GetParentWorldSpace() && g_TES->GetParentWorldSpace()->GetParentWorld(TESWorldSpace::USE_LAND))
    {
        FUN_0086f160(*g_011dec7c.Float());
        FUN_0086f170(*g_011dee54.Float());
        FUN_0086f180(*g_011ded98.Float());
    }
    else if (g_thePlayer && g_thePlayer->GetParentCell() && FUN_00425fd0(g_thePlayer->GetParentCell()))
    {
        FUN_0086f160(*g_011dea80.Float());
        FUN_0086f170(*g_011deddc.Float());
        FUN_0086f180(*g_011decc8.Float());
    }
    else
    {
        FUN_0086f160(1.0f);
        FUN_0086f170(1.0f);
        FUN_0086f180(1.0f);
    }
}
}  // namespace fnv_0086efe0

extern float DAT_011ad804;

// @fnv 0x0086f160
void FUN_0086f160(float value)
{
    DAT_011ad804 = value;
}

extern float DAT_011ad800;

// @fnv 0x0086f170
void FUN_0086f170(float value)
{
    DAT_011ad800 = value;
}

extern float DAT_011ad7fc;

// @fnv 0x0086f180
void FUN_0086f180(float value)
{
    DAT_011ad7fc = value;
}

extern float DAT_011c40ec;

// @fnv 0x0086f830
void FUN_0086f830(float value)
{
    DAT_011c40ec = value;
}

extern unsigned char DAT_011dcfa6;

// @fnv 0x0086fba0
void FUN_0086fba0(unsigned char value)
{
    DAT_011dcfa6 = value;
}

class BGSAcousticSpace;
extern BGSAcousticSpace* DAT_011dcfb8;

// @fnv 0x0086fbb0
void FUN_0086fbb0(BGSAcousticSpace* value)
{
    DAT_011dcfb8 = value;
}

namespace fnv_0086fc60 {
struct NiUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    char _pad_9[3];
};
typedef char _sizecheck_NiUpdateData[sizeof(NiUpdateData) == 12 ? 1 : -1];
struct FUN_0086fc60_shell : public Main
{
    void FUN_0086fc60();
};

extern bool DAT_011dea2b;
extern bool DAT_011dea2c;
extern bool DAT_011dea2d;
extern float DAT_011dea30;
struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011c3ea4;
struct Twin_0084d030
{
    float GetStoredFloatValue();
};
extern Twin_0084d030 g_timeGlobal;
struct ProcessListsH
{
    void FUN_009746c0(float afTimeDelta);
    void FUN_00974420(float afTimeDelta);
};
extern ProcessListsH DAT_011e0e80;
struct NiUpdateDataH
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    void FUN_0043d410(float afTime, bool abUpdateControllers, bool abParallelUpdate);
};
class TES
{
  public:
    void FUN_00453550(float afTimeDelta);
    void FUN_004537c0();
};
extern TES* g_TES;
struct SceneGraphH
{
    void FUN_00c50610(NiUpdateDataH* apUpdateData);
};
SceneGraphH* __cdecl FUN_0045a190();
// @fnv 0x0086fc60
void FUN_0086fc60_shell::FUN_0086fc60()
{
    NiUpdateDataH UpdateData;
    if ((!DAT_011dea2b || DAT_011dea2c || DAT_011dea2d) && !*((bool*)this + 7))
    {
        if (*g_011c3ea4.Int() > 1)
        {
            DAT_011e0e80.FUN_009746c0(g_timeGlobal.GetStoredFloatValue());
        }
        else
        {
            DAT_011e0e80.FUN_00974420(g_timeGlobal.GetStoredFloatValue());
        }
        if (*g_011c3ea4.Int() == 1 && !DAT_011dea2b)
        {
            g_TES->FUN_00453550(DAT_011dea30);
        }
        else
        {
            g_TES->FUN_004537c0();
        }
        UpdateData.FUN_0043d410(DAT_011dea30, true, false);
        if (*g_011c3ea4.Int() > 1)
        {
            FUN_0045a190()->FUN_00c50610(&UpdateData);
        }
        else
        {
            FUN_0045a190()->FUN_00c50610(&UpdateData);
        }
    }
}
}  // namespace fnv_0086fc60

extern unsigned char DAT_0118abb0;

// @fnv 0x0086ff40
unsigned char __cdecl FUN_0086ff40()
{
    return DAT_0118abb0;
}

extern char DAT_01189184;

// @fnv 0x008705c0
char __cdecl FUN_008705c0()
{
    return DAT_01189184;
}

extern unsigned char DAT_011f91a4;

// @fnv 0x008709f0
unsigned char FUN_008709f0()
{
    return DAT_011f91a4;
}

struct HWND__;
extern "C" __declspec(dllimport) HWND__* __stdcall GetForegroundWindow();
struct Controls
{
    int FUN_00711e00();
};
Controls* __cdecl FUN_007fdf30();
struct InterfaceH
{
    static bool IsSaveLoadActive();
    static bool GetSelectedTargetIndex(int menu);
};
int __cdecl FUN_004dc1f0();
int __cdecl FUN_004dc200();
void __cdecl FUN_00703080(float x, float y);
void __cdecl FUN_00706230(int x, int y);

struct FUN_00871d10_t
{
    bool FUN_00871d10(int x, int y);
};

// @fnv 0x00871d10
bool FUN_00871d10_t::FUN_00871d10(int x, int y)
{
    if (GetForegroundWindow() != *(HWND__**)((char*)this + 8))
        return false;
    if (!InterfaceH::IsSaveLoadActive() || !FUN_007fdf30()->FUN_00711e00())
        return false;
    if (!InterfaceH::GetSelectedTargetIndex(0x41e))
        FUN_00703080((float)(x / (double)FUN_004dc1f0()), (float)(y / (double)FUN_004dc200()));
    else
        FUN_00706230(x, y);
    return true;
}

namespace fnv_008727d0 {
struct FUN_008727d0_shell : public Main
{
    void FUN_008727d0();
};

struct BSFaceGenAnimationData;
struct ShadowSceneNode
{
    bool FUN_005f9ad0();
    void SetCreatureType(unsigned char);
};
struct NiAdditionalGeometryData
{
    static ShadowSceneNode* GetShadowSceneNodeForIndex(int);
};
struct ProcessLists
{
    unsigned char* GetLifeStateControlFlag();
};
struct MobileObjectCellAccess
{
    bool FUN_004518e0() const;
};
struct WaterZoneManager
{
    int m_uiPathPointIndex;
    void FUN_004e1bc0(BSFaceGenAnimationData* data, ShadowSceneNode* scene);
    static void FUN_00872930(int index);
};
struct TES
{
    TESObjectCELL* IsCellInterior();
    WaterZoneManager* GetActorScale();
};
struct FUN_004e2120_s
{
    void f(bool);
};
struct FUN_004e2190_shell
{
    FUN_004e2120_s* FUN_004e2190();
};
struct MTRenderingSystem_Helper
{
    void FUN_00ba30f0(int, int);
    void FUN_00ba3130(int, int);
};
struct TaskThreadManager : MTRenderingSystem_Helper
{
    static TaskThreadManager* GetSingleton();
};
bool __cdecl FUN_005468f0(int);
BSFaceGenAnimationData* __cdecl FUN_00524c90();
extern int DAT_011a9608;
extern ProcessLists g_011c7adc;
extern FUN_004e2190_shell* g_osGlobals;
extern TES* g_TES;
extern bool DAT_011ff104;
extern bool DAT_011ff8c4;

// @fnv 0x008727d0
void FUN_008727d0_shell::FUN_008727d0()
{
    if (*g_011c7adc.GetLifeStateControlFlag())
    {
        int isavemaxaniso = DAT_011a9608;
        DAT_011a9608 = 1;
        if (!FUN_005468f0(11) &&
            (!g_TES->IsCellInterior() || ((MobileObjectCellAccess*)g_TES->IsCellInterior())->FUN_004518e0()))
        {
            ShadowSceneNode* pscene = NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0);
            bool bwasLightUpdateDisabled = pscene->FUN_005f9ad0();
            pscene->SetCreatureType(1);
            g_TES->GetActorScale()->FUN_004e1bc0(FUN_00524c90(), pscene);
            pscene->SetCreatureType(bwasLightUpdateDisabled);
        }
        else
        {
            DAT_011ff104 = false;
            g_TES->GetActorScale()->m_uiPathPointIndex = 0;
            g_osGlobals->FUN_004e2190()->f(false);
            DAT_011ff8c4 = false;
            g_TES->GetActorScale()->FUN_00872930(0);
        }
        DAT_011a9608 = isavemaxaniso;
    }
    for (int i = g_TES->GetActorScale()->m_uiPathPointIndex + 1; i < 17; i++)
    {
        TaskThreadManager::GetSingleton()->FUN_00ba30f0(0, i);
        TaskThreadManager::GetSingleton()->FUN_00ba3130(1, i);
    }
}
}  // namespace fnv_008727d0

extern unsigned char DAT_011c7a59;

// @fnv 0x00872930
void FUN_00872930(unsigned char value)
{
    DAT_011c7a59 = value;
}

extern bool DAT_011f9fc3;
extern bool DAT_011f9fc4;

// @fnv 0x00872dd0
void __cdecl FUN_00872dd0(bool abFlag1, bool abFlag2)
{
    DAT_011f9fc3 = abFlag1;
    DAT_011f9fc4 = abFlag2;
}

struct GlobalObjectO2_00a7b610
{
};
extern GlobalObjectO2_00a7b610 g_01201f7c;

class BSFadeNodeCuller
{
  public:
    GlobalObjectO2_00a7b610* FUN_00872ef0();
};

// @fnv 0x00872ef0
GlobalObjectO2_00a7b610* BSFadeNodeCuller::FUN_00872ef0()
{
    return &g_01201f7c;
}

namespace fnv_00872f00 {
struct BSFadeNodeCuller
{
    void __thiscall FUN_00872f30();
    void* __thiscall FUN_00872f00(unsigned int flags);
};

void __cdecl _Deallocate(void*);

// Calls FUN_00872f30, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00872f00
void* __thiscall BSFadeNodeCuller::FUN_00872f00(unsigned int flags)
{
    FUN_00872f30();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00872f00

struct FUN_00874650Class
{
    char FUN_00874650();
};

// @fnv 0x00874650
char FUN_00874650Class::FUN_00874650()
{
    return ((char*)this)[0x1dc];
}

namespace fnv_00874690 {
class GlobalObject_00633c90
{
  public:
    void* operator->() const;
};

GlobalObject_00633c90 g_011c7840;

// @fnv 0x00874690
void FUN_00874690()
{
    g_011c7840.operator->();
}
}  // namespace fnv_00874690

namespace fnv_008746b0 {
struct GlobalObject_00633c90
{
    operator unsigned int() const;
    int* operator->() const;
};

extern GlobalObject_00633c90 g_011c781c;

// @fnv 0x008746b0
int* FUN_008746b0()
{
    return g_011c781c.operator->();
}
}  // namespace fnv_008746b0

extern int DAT_011ff0f0;

// @fnv 0x008746c0
void FUN_008746c0()
{
    DAT_011ff0f0 = 0;
}

struct BSTextureManager
{
    enum RenderTargetType
    {
    };
};

struct BSRenderedTexture;

struct ImageSpaceTexture
{
    void CreateRenderTargetTexture(BSTextureManager::RenderTargetType);
    BSRenderedTexture* GetRenderedTexture() const;
    void FUN_008748d0();
};

// @fnv 0x008748d0
void ImageSpaceTexture::FUN_008748d0()
{
    ((ImageSpaceTexture*)((char*)this + 0x7c))->CreateRenderTargetTexture((BSTextureManager::RenderTargetType)0x27);
    ((ImageSpaceTexture*)((char*)this + 0x7c))->GetRenderedTexture();
}

struct AutoMemHelper
{
    AutoMemHelper(int context, bool push, const char* file, int line);
    ~AutoMemHelper();
    int iOldContext;
};
struct BSRenderedTexture;
struct BSFaceGenNiNode
{
    void* GetAnimationData();
};
struct BSShaderAccumulator
{
    void FUN_00b64570(void* camera, BSRenderedTexture* texture);
};
BSFaceGenNiNode* __cdecl FUN_0045c670();

struct FUN_00874920_t
{
    void FUN_00874920(BSShaderAccumulator* apShaderAccum, BSRenderedTexture* apRenderTexture);
};

// Gets the face-gen scene node and passes its animation data with the render texture to the shader accumulator.
// @fnv 0x00874920
void FUN_00874920_t::FUN_00874920(BSShaderAccumulator* apShaderAccum, BSRenderedTexture* apRenderTexture)
{
    BSFaceGenNiNode* pscene;
    AutoMemHelper tempMemContext(0x27, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 0x20d5);
    pscene = FUN_0045c670();
    apShaderAccum->FUN_00b64570(pscene->GetAnimationData(), apRenderTexture);
}

struct FUN_00a235d0_class
{
    int __thiscall FUN_00a235d0(int a1, int a2);
};

// @fnv 0x00a235d0
int __thiscall FUN_00a235d0_class::FUN_00a235d0(int a1, int a2)
{
    return 1;
}

struct FUN_00a236b0_Class
{
    int FUN_00a236b0(int index);
};

// @fnv 0x00a236b0
int __thiscall FUN_00a236b0_Class::FUN_00a236b0(int index)
{
    return *(int*)(this + 0x1764 + index * 0x2c);
}

struct FUN_0086ba60_Class
{
    bool FUN_0086ba60(void* a1, void* a2);
};

// Returns true if the pointer stored at offset 0x200 of this object equals a2.
// @fnv 0x0086ba60
bool FUN_0086ba60_Class::FUN_0086ba60(void* apUnused, void* a2)
{
    if (*(void**)((char*)this + 0x200) == a2)
        return true;
    return false;
}

namespace fnv_0086bb20 {
struct GlobalObject_00869b10
{
    void RemoveAt(unsigned int);
};

struct SomeClass
{
    int FUN_0086bb70(unsigned int);
    bool FUN_0086bb20(unsigned int index);
};

// Looks up index via FUN_0086bb70; if found, removes that entry from the two lists at offsets 0xad4 and 0xae4 and returns true, else false.
// @fnv 0x0086bb20
bool SomeClass::FUN_0086bb20(unsigned int index)
{
    int result = FUN_0086bb70(index);
    if (result == -1)
        return false;
    (reinterpret_cast<GlobalObject_00869b10*>(reinterpret_cast<unsigned char*>(this) + 0xad4))->RemoveAt(result);
    (reinterpret_cast<GlobalObject_00869b10*>(reinterpret_cast<unsigned char*>(this) + 0xae4))->RemoveAt(result);
    return true;
}
}  // namespace fnv_0086bb20

struct TESGrass
{
    unsigned char GetMinimumSlopeDegrees(void);
};

struct BSSystemUtility
{
    static BSSystemUtility* ms_pSystemUtility;
};

// @fnv 0x0086bdf0
char FUN_0086bdf0()
{
    int result;
    if (BSSystemUtility::ms_pSystemUtility && ((TESGrass*)BSSystemUtility::ms_pSystemUtility)->GetMinimumSlopeDegrees())
        result = 1;
    else
        result = 0;
    return (char)result;
}

// Returns the smaller of the two arguments, comparing the float against the double and returning it as a double.
// @fnv 0x008731a0
double FUN_008731a0(double adValue, float afValue)
{
    double d;
    if (afValue > adValue)
        d = adValue;
    else
        d = afValue;
    return d;
}

namespace fnv_008746a0 {
struct Flt
{
    operator unsigned int(void);
};

extern Flt g_011c7810;

// @fnv 0x008746a0
void FUN_008746a0()
{
    g_011c7810.operator unsigned int();
}
}  // namespace fnv_008746a0

struct FUN_00874aa0_Class
{
    char FUN_00874aa0();
};

// @fnv 0x00874aa0
char FUN_00874aa0_Class::FUN_00874aa0()
{
    return *(char*)((char*)this + 0x118);
}

struct FUN_008776e0
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    void SetFlags();
};

// @fnv 0x008776e0
void FUN_008776e0::SetFlags()
{
    b2 = 0;
    b5 = 0;
}

struct SoundPlaybackHandle
{
    bool StopWithFade(unsigned int);
    bool FUN_00877700();
};

// @fnv 0x00877700
bool SoundPlaybackHandle::FUN_00877700()
{
    return ((SoundPlaybackHandle*)((char*)this + 0x77c))->StopWithFade(0x3e8);
}

struct FUN_0086ef70_Class
{
    char FUN_0086ef70();
};

// @fnv 0x0086ef70
char FUN_0086ef70_Class::FUN_0086ef70()
{
    return *(char*)((char*)this + 0x52);
}

struct FUN_0086fbc0_Class
{
    char m_05f9;
    void FUN_0086fbc0(char value);
};

// @fnv 0x0086fbc0
void FUN_0086fbc0_Class::FUN_0086fbc0(char value)
{
    *(char*)((char*)this + 0x5f9) = value;
}

struct FUN_008727b0_Class
{
    char __thiscall FUN_008727b0() const;
};
// @fnv 0x008727b0
char __thiscall FUN_008727b0_Class::FUN_008727b0() const
{
    return *(int*)((char*)this + 0x20) != 0;
}

extern "C" void __cdecl FUN_00a693e0();

struct FUN_00872f30_class
{
    void __thiscall FUN_00a693e0();
    void __thiscall FUN_00872f30();
};

// @fnv 0x00872f30
void __thiscall FUN_00872f30_class::FUN_00872f30()
{
    FUN_00a693e0();
}

namespace fnv_00875bd0 {
struct Flt
{
    operator unsigned int();
};

struct FUN_00875bd0_Class
{
    unsigned int __thiscall FUN_00875bd0(int idx);
};

// @fnv 0x00875bd0
unsigned int __thiscall FUN_00875bd0_Class::FUN_00875bd0(int aiIndex)
{
    return ((Flt*)((char*)this + 0xf4 + aiIndex * 4))->operator unsigned int();
}
}  // namespace fnv_00875bd0

struct FUN_00456630_helper
{
    bool FUN_00456630(unsigned int);
    void FUN_00876810();
};

// @fnv 0x00876810
void FUN_00456630_helper::FUN_00876810()
{
    FUN_00456630(0x800);
}

namespace fnv_00876830 {
struct BSRenderedTexture
{
    static void __cdecl EndAllAndResetRendererState();
    void __thiscall FUN_00876830(int, int);
};

// @fnv 0x00876830
void __thiscall BSRenderedTexture::FUN_00876830(int, int)
{
    EndAllAndResetRendererState();
}
}  // namespace fnv_00876830

struct FUN_00877a50Class
{
    unsigned char _pad_000a[0xa];
    unsigned short m_000a;
    void FUN_00877e10(unsigned short a, int b);
    void FUN_00877a50(int param_2);
};

// Calls FUN_00877e10 with m_000a and param_2.
// @fnv 0x00877a50
void FUN_00877a50Class::FUN_00877a50(int param_2)
{
    FUN_00877e10(m_000a, param_2);
}

struct FUN_00a23490_Class
{
    int FUN_00a23490(int a, unsigned int b);
};

// Returns whether the bit at position b is set in the int stored at this + a*8 + 0x18b8.
// @fnv 0x00a23490
int FUN_00a23490_Class::FUN_00a23490(int aiIndex, unsigned int auiBit)
{
    return (1 << auiBit) & *(int*)((char*)this + aiIndex * 8 + 0x18b8);
}

struct FUN_00a23690_class
{
    int FUN_00a23690(int index);
};

// @fnv 0x00a23690
int FUN_00a23690_class::FUN_00a23690(int index)
{
    return *(int*)((char*)this + 0x1760 + index * 0x2c);
}

struct FUN_00a236d0_class
{
    int __thiscall FUN_00a236d0(int index);
};

// @fnv 0x00a236d0
int __thiscall FUN_00a236d0_class::FUN_00a236d0(int index)
{
    return *(int*)((char*)this + 0x1768 + index * 0x2c);
}

extern "C" void __cdecl _Deallocate(void*);

struct FUN_0086bd40_class
{
    void __thiscall FUN_00afdcf0();
    void* __thiscall FUN_0086bd40(unsigned int flags);
};

// @fnv 0x0086bd40
void* __thiscall FUN_0086bd40_class::FUN_0086bd40(unsigned int flags)
{
    FUN_00afdcf0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);

struct FUN_0086bee0_class
{
    void __thiscall FUN_00450770();
    void* __thiscall FUN_0086bee0(unsigned int flags);
};

// @fnv 0x0086bee0
void* __thiscall FUN_0086bee0_class::FUN_0086bee0(unsigned int flags)
{
    FUN_00450770();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl _Deallocate(void*);
void __cdecl FUN_00700650();
struct FUN_0086bf10
{
    void __thiscall FUN_00700650();
    void* __thiscall DeleteThis(unsigned int flags);
};
// Calls FUN_00700650, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0086bf10
void* __thiscall FUN_0086bf10::DeleteThis(unsigned int flags)
{
    FUN_00700650();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_0086f6a0 {
struct ActiveEffect;
struct Actor;
struct ActorCause;
struct AlchemyItem;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct BSRenderedTexture;
struct BSShaderNoLightingProperty;
struct SoundPlaybackHandle;
struct BaseFormComponent;
struct BaseProcess;
struct BipedAnim;
struct CHUNK;
struct CellMopp;
struct GameFormRecord;
struct DialogueResponse;
struct TeleportableReference;
struct EffectItem;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanIntegerAccessor;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MapMarkerData;
struct MobileObject;
struct Point3Offset;
struct NiAVObject;
struct NiCamera;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPoint3;
struct NiPointLight;
struct NiTexture;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct ShadowSceneNode;
struct SpellItem;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct Tile;
struct TrapEntry;
struct WaterZone;
struct bhkCharacterController;
struct bhkNiCollisionObject;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};
struct FUN_0086f6a0_shell : public Main
{
    void FUN_0086f6a0();
};

template <int N> struct FUN_0086f6a0_vs : FUN_0086f6a0_vs<N - 1>
{
    virtual void vf(int (*)[N + 1]);
};
template <> struct FUN_0086f6a0_vs<0>
{
    virtual void vf0();
};
struct FUN_0086f6a0_mob : FUN_0086f6a0_vs<63>
{
    virtual bool IsSlot64();
};
struct FUN_0086f6a0_act : FUN_0086f6a0_vs<256>
{
    virtual void Slot257(float);
};
struct FOPipboyManager
{
    void FUN_007fa990();
};
struct GlobalObject_0045cfe0
{
    int* Int();
};
struct GlobalObject2_0040c150;
struct TaskQueueInterface
{
    static TaskQueueInterface* GetInstance();
    static void ThreadProcessSecondaryInput();
    static void ThreadProcessInput(unsigned int);
    void FUN_0087a790();
};
struct FUN_0087a6b0_shell
{
    void FUN_0087a6b0();
};
struct FUN_0087a6d0_shell
{
    void FUN_0087a6d0();
};
struct Interface
{
    static bool IsConsoleActive();
    static FOPipboyManager* GetPipboyManagerInstance();
};
struct DialogH
{
    static bool IsInDialog();
};
struct Twin_0084d030
{
    float GetStoredFloatValue();
};
struct ProcessLists
{
    void UpdateMagicTempEffects(float);
    void FUN_0096c860();
    void FUN_009781d0(float);
};
struct FUN_0096c970_shell
{
    void FUN_0096c970();
};
struct FUN_00991600_t
{
    void FUN_00991600(bool);
};
struct GameTimerRecord;
void FUN_0054ae30();
void FUN_00552570();
FUN_0086f6a0_mob* FUN_007624d0();
void FUN_0086f830(float);
bool __fastcall FUN_0086f840(char*);
bool FUN_0086f860();
void __fastcall FUN_0096c710(ProcessLists*);
extern float DAT_011c3c08;
extern GlobalObject_0045cfe0 g_011c3ea4;
extern GlobalObject2_0040c150 g_011d10d4;
extern bool DAT_011dea2b;
extern bool DAT_011dea2d;
extern ProcessLists DAT_011e0e80;
extern FUN_00991600_t* BGSSaveLoadGlobalDataWorldspacePtr;
extern GameTimerRecord g_timeGlobal;

// @fnv 0x0086f6a0
void FUN_0086f6a0_shell::FUN_0086f6a0()
{
    FOPipboyManager* ppipboy;
    FUN_0086f6a0_mob* pmob;
    FUN_0086f6a0_act* pact;
    if (DialogH::IsInDialog() && !Interface::IsConsoleActive() && !FUN_0086f860())
    {
        pmob = FUN_007624d0();
        if (pmob && pmob->IsSlot64())
        {
            pact = (FUN_0086f6a0_act*)pmob;
            pact->Slot257(0.0f);
        }
    }
    DAT_011e0e80.UpdateMagicTempEffects(0.0f);
    if (*g_011c3ea4.Int() > 1)
        ((FUN_0096c970_shell*)&DAT_011e0e80)->FUN_0096c970();
    else
        DAT_011e0e80.FUN_0096c860();
    FUN_0096c710(&DAT_011e0e80);
    DAT_011e0e80.FUN_009781d0(((Twin_0084d030*)&g_timeGlobal)->GetStoredFloatValue());
    ppipboy = Interface::GetPipboyManagerInstance();
    if (FUN_0086f840((char*)ppipboy))
        ppipboy->FUN_007fa990();
    if (*g_011c3ea4.Int() > 1)
    {
        FUN_0054ae30();
        ((FUN_0087a6d0_shell*)TaskQueueInterface::GetInstance())->FUN_0087a6d0();
        TaskQueueInterface::GetInstance()->FUN_0087a790();
        FUN_00552570();
        FUN_0086f830(DAT_011c3c08);
        ((FUN_0087a6b0_shell*)TaskQueueInterface::GetInstance())->FUN_0087a6b0();
    }
    TaskQueueInterface::ThreadProcessInput(*((GlobalObject_0045cfe0*)&g_011d10d4)->Int());
    TaskQueueInterface::ThreadProcessSecondaryInput();
    BGSSaveLoadGlobalDataWorldspacePtr->FUN_00991600(DAT_011dea2b || DAT_011dea2d || *((bool*)this + 7));
}
}  // namespace fnv_0086f6a0

namespace fnv_0086fd90 {
struct FUN_0086fd90_shell : public Main
{
    void FUN_0086fd90(bool);
};

struct Twin_0084d030
{
    float GetStoredFloatValue();
};
struct GameTimerRecord : Twin_0084d030
{
};
extern GameTimerRecord g_timeGlobal;
struct ImageSpaceManager
{
    void BeginParamModifiers();
    void FUN_00b8b500();
    void FUN_00b8aea0();
    void FUN_00b8ccb0();
    void FUN_00b8d020();
    void FUN_00b8b440(bool);
};
ImageSpaceManager* __cdecl FUN_004e3270();
unsigned char __cdecl FUN_0086ff40();
void __cdecl FUN_0086ff50(float);
struct ISMI_0086fd90
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
    virtual bool IsExpired();
    virtual void Update();
    int iPad4;
    bool bActive;
};
struct Flt
{
    operator unsigned int();
};
struct GO
{
    GO(ISMI_0086fd90*);
    ~GO();
    void* p;
};
struct ISMList_0086fd90
{
    Flt& FUN_006815c0();
    ISMList_0086fd90* GetNext();
    void Remove(const GO&);
};
struct TES
{
    ISMList_0086fd90* FUN_0043b5d0();
};
extern TES* g_TES;
// @fnv 0x0086fd90
void FUN_0086fd90_shell::FUN_0086fd90(bool abAdvanceTime)
{
    FUN_004e3270()->FUN_00b8b500();
    FUN_004e3270()->BeginParamModifiers();
    if (abAdvanceTime)
        FUN_0086ff50(g_timeGlobal.GetStoredFloatValue());
    ISMList_0086fd90* pModifierList = g_TES->FUN_0043b5d0();
    int iActiveCount = 0;
    int iactiveWeatherCount = 0;
    while (pModifierList)
    {
        ISMI_0086fd90* pModifier = (ISMI_0086fd90*)(unsigned int)pModifierList->FUN_006815c0();
        if (pModifier)
        {
            if (pModifier->bActive)
                ++iActiveCount;
            if (pModifier->IsExpired())
            {
                pModifierList->Remove(pModifier);
                continue;
            }
            else if (FUN_0086ff40())
            {
                pModifier->Update();
                if (((Twin_0084d030*)pModifier)->GetStoredFloatValue() > 0.0 && pModifier->bActive)
                    ++iactiveWeatherCount;
            }
        }
        pModifierList = pModifierList->GetNext();
        if (iActiveCount == 4)
        {
            if (!iactiveWeatherCount)
                FUN_004e3270()->FUN_00b8aea0();
            FUN_004e3270()->FUN_00b8ccb0();
            iActiveCount = 0;
        }
    }
    FUN_004e3270()->FUN_00b8d020();
    FUN_004e3270()->FUN_00b8b440(false);
}
}  // namespace fnv_0086fd90

namespace fnv_008746d0 {
struct BSRenderedTexture;
struct NiStream;
struct RgbaColor
{
    void Clamp();
    void Scale();
    static void LoadBinary(NiStream*, RgbaColor*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, RgbaColor*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float Luminance();
    void __dflt_ctor_closure();
    float r;
    float g;
    float b;
    float a;
};
typedef char _sizecheck_NiColorA[sizeof(RgbaColor) == 16 ? 1 : -1];
struct FUN_008746d0_shell : public Main
{
    void FUN_008746d0(BSRenderedTexture*);
};

struct NiNode;
struct NiRenderTargetGroup;
struct NiColor;
struct ImageSpaceEffectParam
{
    ImageSpaceEffectParam(float, float, float, float);
    float r, g, b, a;
};
struct NiAVObject
{
    bool FUN_00456610();
    void SetAppCulled(bool);
};
struct BSRenderedTexture
{
    NiRenderTargetGroup* GetGroup();
    static void EndAllAndResetRendererState();
};
struct ImageSpaceTexture
{
    BSRenderedTexture* FUN_008748d0();
};
struct S4
{
    ImageSpaceTexture* FUN_004ebbc0(int);
};
struct FUN_004a0fd0_shell
{
    void FUN_004a0fd0(unsigned int);
};
struct MiddleLowProcess
{
    FUN_004a0fd0_shell* GetProcessInteger();
};
struct BSFaceGenNiNode
{
    void* GetAnimationData();
};
struct SceneGraph_008746d0
{
    void SetCameraFOV(float, int, int, int);
};
struct PC_00605d70
{
    NiNode* GetNode(bool);
};
struct FUN_008bbc10_shell
{
    bool FUN_008bbc10();
};
struct Flt
{
    operator unsigned int();
};
struct BSShaderManager
{
    static void SetFOV(float);
};
struct BSShaderRenderUtility
{
    static void SetRenderCamera(void*, unsigned int, bool);
};
struct BSRenderStateManager
{
    static void SetColorWriteMask(unsigned int, unsigned int);
};
struct Renderer_008746d0
{
    virtual void rv00();
    virtual void rv01();
    virtual void rv02();
    virtual void rv03();
    virtual void rv04();
    virtual void rv05();
    virtual void rv06();
    virtual void rv07();
    virtual void rv08();
    virtual void rv09();
    virtual void rv10();
    virtual void rv11();
    virtual void rv12();
    virtual void rv13();
    virtual void rv14();
    virtual void rv15();
    virtual void rv16();
    virtual void rv17();
    virtual void rv18();
    virtual void rv19();
    virtual void rv20();
    virtual void rv21();
    virtual void rv22();
    virtual void rv23();
    virtual void rv24();
    virtual void rv25();
    virtual void rv26();
    virtual void rv27();
    virtual void rv28();
    virtual void rv29();
    virtual void rv30();
    virtual void rv31();
    virtual void rv32();
    virtual void rv33();
    virtual void rv34();
    virtual void rv35();
    virtual void rv36();
    virtual void rv37();
    virtual void rv38();
    virtual void rv39();
    virtual void rv40();
    virtual void rv41();
    virtual void rv42();
    virtual void SetBackgroundColor(ImageSpaceEffectParam*);
    virtual void SetBackgroundColorRGB(NiColor*);
    virtual void GetBackgroundColor(ImageSpaceEffectParam*);
};
S4* __cdecl FUN_004e3270();
Renderer_008746d0* __cdecl FUN_004a0e90();
SceneGraph_008746d0* __cdecl FUN_0045c670();
void __cdecl FUN_00b6b8d0(unsigned int, NiRenderTargetGroup*);
void __cdecl FUN_00b6bee0(void*, NiAVObject*, FUN_004a0fd0_shell*);
void __cdecl FUN_004eced0(unsigned int);
float __fastcall FUN_00874900(PC_00605d70*);
float __fastcall FUN_00710ab0(PC_00605d70*);
extern NiColor DAT_011f4998;
// @fnv 0x008746d0
void FUN_008746d0_shell::FUN_008746d0(BSRenderedTexture* apRenderTexture)
{
    S4* pimagespacemanager = FUN_004e3270();
    Renderer_008746d0* prenderer = FUN_004a0e90();
    NiNode* pscenegraph = ((PC_00605d70*)g_thePlayer)->GetNode(true);
    SceneGraph_008746d0* p1stperson3d = FUN_0045c670();
    FUN_004a0fd0_shell* pculler = ((MiddleLowProcess*)p1stperson3d)->GetProcessInteger();
    bool m_kFieldAfterWeaponFlags = ((FUN_008bbc10_shell*)g_thePlayer)->FUN_008bbc10();
    BSRenderedTexture* p1stpersonBuffer = 0;
    ImageSpaceEffectParam savedBackground(0.0f, 0.0f, 0.0f, 0.0f);
    if (m_kFieldAfterWeaponFlags)
    {
        p1stpersonBuffer = pimagespacemanager->FUN_004ebbc0(4)->FUN_008748d0();
        BSRenderedTexture::EndAllAndResetRendererState();
        prenderer->GetBackgroundColor(&savedBackground);
        prenderer->SetBackgroundColorRGB(&DAT_011f4998);
        FUN_00b6b8d0(1, p1stpersonBuffer->GetGroup());
    }
    else
    {
        BSRenderStateManager::SetColorWriteMask(0, 1);
    }
    NiAVObject* p1stPersonNode = (NiAVObject*)pscenegraph;
    bool bwas1stPersonCulled = p1stPersonNode->FUN_00456610();
    p1stPersonNode->SetAppCulled(false);
    p1stperson3d->SetCameraFOV(FUN_00874900((PC_00605d70*)g_thePlayer), 0, 0, 0);
    BSShaderManager::SetFOV(FUN_00874900((PC_00605d70*)g_thePlayer));
    pculler->FUN_004a0fd0(*(Flt*)((char*)this + 0x90));
    FUN_00b6bee0(((BSFaceGenNiNode*)p1stperson3d)->GetAnimationData(), p1stPersonNode, pculler);
    BSShaderRenderUtility::SetRenderCamera(((BSFaceGenNiNode*)p1stperson3d)->GetAnimationData(),
                                           *(Flt*)((char*)this + 0x90), false);
    pculler->FUN_004a0fd0(0);
    p1stperson3d->SetCameraFOV(FUN_00710ab0((PC_00605d70*)g_thePlayer), 0, 0, 0);
    BSShaderManager::SetFOV(FUN_00710ab0((PC_00605d70*)g_thePlayer));
    p1stPersonNode->SetAppCulled(bwas1stPersonCulled);
    if (m_kFieldAfterWeaponFlags)
    {
        prenderer->SetBackgroundColor(&savedBackground);
        BSRenderedTexture::EndAllAndResetRendererState();
    }
    else
    {
        FUN_004eced0(1);
    }
}
}  // namespace fnv_008746d0

namespace fnv_00875e40 {
class NiCamera;
class BSRenderedTexture;
struct AutoMemHelper
{
    int m;
    AutoMemHelper(int id, bool b, const char* file, int line);
    ~AutoMemHelper();
};
struct ArrSI
{
    unsigned int GetFlags();
};
extern ArrSI DAT_011f2250;
unsigned int __cdecl FUN_0045c670(void);
struct NiObjectCopyInfo
{
    int a, b, c, d;
    NiObjectCopyInfo(unsigned int flags);
    ~NiObjectCopyInfo();
};
struct FUN_00875e40_Clone
{
    virtual ~FUN_00875e40_Clone();
};
struct FUN_00875e40_Src
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
    virtual FUN_00875e40_Clone* Clone(NiObjectCopyInfo& info);
};
struct BSFaceGenNiNode
{
    void* GetAnimationData();
    void SetCameraFOV(float f, int a, void* b, int c);
};
struct FUN_00710ab0_Class;
float __fastcall FUN_00710ab0(FUN_00710ab0_Class* p);
float __fastcall FUN_00874900(const char* p);
struct BSShaderManager
{
    static void __cdecl SetFOV(float fov);
};
struct BSShaderAccumulator
{
    void SetupDepth(NiCamera* a, NiCamera* b, BSRenderedTexture* c);
};
struct FUN_00875e40_shell
{
    void FUN_00875e40(BSShaderAccumulator* pAccum, BSRenderedTexture* pTexture);
};

// Clones the scene graph's animation data as a camera, sets FOV and depth via pAccum->SetupDepth, then deletes the cloned camera.
// @fnv 0x00875e40
void FUN_00875e40_shell::FUN_00875e40(BSShaderAccumulator* pAccum, BSRenderedTexture* pTexture)
{
    BSFaceGenNiNode* pkSceneGraph = (BSFaceGenNiNode*)FUN_0045c670();
    if (DAT_011f2250.GetFlags() != 4)
        pkSceneGraph->SetCameraFOV(FUN_00710ab0((FUN_00710ab0_Class*)g_thePlayer), 0, 0, 0);
    BSShaderManager::SetFOV(FUN_00710ab0((FUN_00710ab0_Class*)g_thePlayer));
    {
        NiObjectCopyInfo kInfo(0x101);
        FUN_00875e40_Clone* pkCamera = ((FUN_00875e40_Src*)pkSceneGraph->GetAnimationData())->Clone(kInfo);
        if (DAT_011f2250.GetFlags() != 4)
            pkSceneGraph->SetCameraFOV(FUN_00874900((const char*)g_thePlayer), 0, pkCamera, 0);
        AutoMemHelper kMemHelper(0x27, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 0x234c);
        pAccum->SetupDepth((NiCamera*)pkSceneGraph->GetAnimationData(), (NiCamera*)pkCamera, pTexture);
        delete pkCamera;
    }
}
}  // namespace fnv_00875e40

namespace fnv_00875fa0 {
unsigned int __cdecl FUN_0045c670(void);
struct BSFaceGenNiNode
{
    void* GetAnimationData(void);
};
struct Param00875fa0
{
    void FUN_00b651e0(void*, void*);
};
struct Outer00875fa0
{
    void FUN_00875fa0(Param00875fa0*, void*);
};
// Calls FUN_0045c670 to get a BSFaceGenNiNode, then passes its animation data and b to FUN_00b651e0 on a.
// @fnv 0x00875fa0
void Outer00875fa0::FUN_00875fa0(Param00875fa0* pParam, void* b)
{
    BSFaceGenNiNode* tmp = (BSFaceGenNiNode*)FUN_0045c670();
    pParam->FUN_00b651e0(tmp->GetAnimationData(), b);
}
}  // namespace fnv_00875fa0

namespace fnv_00876850 {
struct BSRenderedTexture;
struct BSShaderAccumulator;
struct ShaderRenderType;
struct GeometryDeviceType;
struct ShaderComRelatedType;
struct ComRenderSupportType;
struct ComGraphicsSupportType;
struct COMBaseInterface;
struct GeometryBufferData;
struct VertexBufferBlock;
struct GeometryRelatedType;
struct NiIBBlock;
struct NiDX9BufferManager;
struct NiDX9VertexDeclaration;
struct Direct3DRenderState;
struct NiDX9TextureData;
struct Direct3D9RenderSystem;
struct COMUnknownInterface;
struct RenderableGeometry;
struct ImageSpaceEffectRenderer;
struct Direct3D;
struct ImageSpaceEffect;
struct ImageSpaceEffectParam;
struct ImageSpaceTexture;
struct NiBillboardNode;
struct NiCamera;
struct RgbaColor;
struct NiDirectionalLight;
struct NiNode;
struct NiPick;
struct NiPoint2;
struct NiScreenElements;
struct NiTexture;
struct NiTriShape;
struct GraphicsRenderer;
struct Sky;
struct Sun;
struct Direct3DRendererType;
struct _D3DCAPS9;
struct _D3DDEVICE_CREATION_PARAMETERS;
struct _D3DDISPLAYMODE;
struct _D3DGAMMARAMP;
struct _D3DPRESENT_PARAMETERS_;
struct Direct3DPresentationType;
struct _D3DRASTER_STATUS;
struct Direct3DViewportSupportType;
struct _D3DVIEWPORT9;
struct Direct3DStructure;
struct FourComponentNumericValue;
struct tagRECT;
struct blob4
{
    char b[4];
};
struct blob16
{
    char b[16];
};
struct ImageSpaceManager
{
    void Initialize();
    void Shutdown();
    void InitDefaultParameter();
    ImageSpaceEffect* GetEffect(int);
    void AddEffect(int, ImageSpaceEffect*);
    bool IsEffectActive(int);
    void SetupEffects();
    void SetupShader();
    void RenderEndOfFrameEffects(GraphicsRenderer*, BSRenderedTexture**, BSRenderedTexture**);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*,
                      bool);
    void RenderEffect(int, GraphicsRenderer*, NiTexture*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, BSRenderedTexture*,
                      ImageSpaceEffectParam*, bool);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*,
                      ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void ModifyParameterData(int, unsigned int, int, float);
    void ApplyCurrentParameterData(bool);
    void SetBaseParameterData(void*);
    void SetOverrideBaseParameterData(void*);
    void ResetToBaseParameterData();
    void ResetWeatherData();
    void BeginParamModifiers();
    void ApplyParamModifier(int, unsigned int, float*, float);
    void ApplyParamModifierWeather(int, unsigned int, float*, float);
    void ApplyTintColorParamModifier(RgbaColor*);
    void ApplyTintColorParamModifierWeather(RgbaColor*);
    void SetFadeColorParamModifier(RgbaColor*);
    void ApplyFadeColorParamModifierWeather(RgbaColor*);
    void SetBlurRadiusParamModifier(float);
    void ApplyBlurRadiusParamModifierWeather(float);
    void ApplyDoubleVisionParamModifier(float);
    void ApplyDoubleVisionParamModifierWeather(float);
    void SetRadialBlurParameters(float, float, float, float, float, void*);
    void ApplyRadialBlurParamModifierWeather(float, float, float, float, float, void*);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, float, float, void*);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, void*);
    void SetDepthOfFieldParameters(float, unsigned int, float, float, float);
    void SetDepthOfFieldParameters(float, unsigned int, float, void*);
    void ApplyDepthOfFieldParamModifierWeather(float, unsigned int, float, float, float);
    void ApplyMotionBlurStrengthParamModifier(float);
    void ApplyMotionBlurStrengthParamModifierWeather(float);
    void EndWeatherModifiers();
    void EndParamModifiers();
    float ApplyOperation(int, float, float);
    void GetRadialBlurCenterFromWorldBound(void*, NiPoint2*);
    void GetDepthOfFieldParamsFromWorldBound(void*, NiPoint2*);
    void EnableSunbeams(bool);
    void SetSunPosition(void*);
    BSRenderedTexture* GetRefractionNormalsTexture(bool);
    BSRenderedTexture* GetVolumetricFogTexture();
    void ReturnVolumetricFogTexture();
    float GetHDREmissiveMult();
    float GetHDRBlurRadius();
    float GetHDRBrightClamp();
    float GetHDRBrightScale();
    float GetHDREyeAdaptSpeed();
    float GetHDRTargetLUM();
    float GetHDRUpperLUMClamp();
    void SetVolumetricFogProps(struct blob16);
    void SetMotionBlurConst(float);
    void SetMenuBGBlendEnabled(bool);
    void SetMenuBGBlendValue(float);
    void EnablePartialRender(bool, NiScreenElements*);
    void SetMenuBackgroundBlend(float, float, void*);
    NiTexture* GetDepthTexture();
    ImageSpaceTexture* GetDepthImageSpaceTexture();
    BSRenderedTexture* GetDepthRenderedTexture();
    void SetDepthTexture(BSRenderedTexture*);
    void SetDepthTexture(NiTexture*);
    void ReturnDepthTexture();
    NiScreenElements* GetMenuUnpackGeom();
    void SetMenuUnpackGeom(NiScreenElements*);
    void SetRefractionTint(void*);
    void* GetRefractionTint();
    void SetCustomViewPort(float, float, float, float);
    void ClearCustomViewPort();
    void* GetCustomViewport();
    BSRenderedTexture* GetSwapTarget();
    void InitEffects();
    void CreateMenuBackgroundGeometry();
    void ShutdownEffects();
    void ShutdownGeometry();
    void PrepareEndOfFrameEffects();
    void* __vecDelDtor(unsigned int);
    BSRenderedTexture* m_pCurrentRenderedTexture;
    char pEffectList[16];
    char m_kBlendedParameterData[152];
    void* m_pCurrentModifierParameterData;
    void* m_pPreviousModifierParameterData;
    char m_kModifierParameterData[304];
    bool m_bEndOfFrameEffectsEnabled;
    char _pad_1e5[3];
    int m_iEndOfFrameEffectCount;
    int m_eEndOfFrameEffect;
    char m_pMenuBackgroundScreenGeometry[4];
    char m_pMenuBackgroundScreenElementsData[4];
    char m_pMenuBackgroundScreenElements[4];
    bool m_bPartialRenderEnabled;
    char _pad_1fd[3];
    char m_pPartialRenderScreenElements[4];
    char m_kDepthTexture[16];
    char m_kModifierColor[16];
    char m_kPartialRenderColor[16];
    float m_fPartialRenderBlend;
    char m_kAccumulatedColor[16];
    char m_kWeatherFadeColor[16];
    float m_fFadeColorAlpha;
    float m_fDoubleVisionStrength;
    float m_fWeatherBlurRadius;
    float m_fWeatherDoubleVisionStrength;
    float m_fAdditionalImageSpaceValue;
    float m_fRadialBlurStrength;
    float m_fRadialBlurRampUp;
    float m_fRadialBlurStart;
    float m_fRadialBlurRampDown;
    float m_fRadialBlurDownStart;
    float m_fWeatherRadialBlurStrength;
    float m_fWeatherRadialBlurRampUp;
    float m_fWeatherRadialBlurStart;
    float m_fWeatherRadialBlurRampDown;
    float m_fWeatherRadialBlurDownStart;
    char m_kRadialBlurCenter[8];
    char m_kWeatherRadialBlurCenter[8];
    float m_fDepthOfFieldStrength;
    float m_fDepthOfFieldMaskConstant;
    float m_fDepthOfFieldDistance;
    float m_fDepthOfFieldRange;
    float m_fDepthOfFieldEffectStrength;
    float m_fDepthOfFieldEffectDistance;
    float m_fDepthOfFieldEffectRange;
    float m_fDepthOfFieldMaskValue;
    int m_eDepthOfFieldMode;
    int m_eDepthOfFieldTargetMode;
    bool m_bDepthOfFieldUsesObject;
    bool m_bMenuBackgroundBlendEnabled;
    char _pad_2ce[2];
    float m_fBlurRadius;
    float m_fRadialBlurTransition;
    float m_fRadialBlurStartValue;
    float m_fRadialBlurDistance;
    float m_fRadialBlurRange;
    char m_kRadialBlurOrigin[8];
    int m_eRadialBlurMode;
    float m_fMenuBackgroundBlendValue;
    float m_fMenuBackgroundBlendTarget;
    char m_kMenuBackgroundTint[16];
    char m_kMenuBackgroundRect[16];
    BSRenderedTexture* m_pMenuBackgroundTexture;
};
typedef char _sizecheck_ImageSpaceManager[sizeof(ImageSpaceManager) == 796 ? 1 : -1];
struct FUN_00876850_shell : public Main
{
    void FUN_00876850(BSRenderedTexture*, ImageSpaceManager*, GraphicsRenderer*, Sun*);
};

struct Dev9
{
    virtual void __stdcall v0();
    virtual void __stdcall v1();
    virtual void __stdcall v2();
    virtual void __stdcall v3();
    virtual void __stdcall v4();
    virtual void __stdcall v5();
    virtual void __stdcall v6();
    virtual void __stdcall v7();
    virtual void __stdcall v8();
    virtual void __stdcall v9();
    virtual void __stdcall v10();
    virtual void __stdcall v11();
    virtual void __stdcall v12();
    virtual void __stdcall v13();
    virtual void __stdcall v14();
    virtual void __stdcall v15();
    virtual void __stdcall v16();
    virtual void __stdcall v17();
    virtual void __stdcall v18();
    virtual void __stdcall v19();
    virtual void __stdcall v20();
    virtual void __stdcall v21();
    virtual void __stdcall v22();
    virtual void __stdcall v23();
    virtual void __stdcall v24();
    virtual void __stdcall v25();
    virtual void __stdcall v26();
    virtual void __stdcall v27();
    virtual void __stdcall v28();
    virtual void __stdcall v29();
    virtual void __stdcall v30();
    virtual void __stdcall v31();
    virtual void __stdcall v32();
    virtual void __stdcall v33();
    virtual void __stdcall v34();
    virtual void __stdcall v35();
    virtual void __stdcall v36();
    virtual void __stdcall v37();
    virtual void __stdcall v38();
    virtual void __stdcall v39();
    virtual void __stdcall v40();
    virtual void __stdcall v41();
    virtual void __stdcall v42();
    virtual void __stdcall v43();
    virtual void __stdcall v44();
    virtual void __stdcall v45();
    virtual void __stdcall v46();
    virtual void __stdcall v47();
    virtual void __stdcall v48();
    virtual void __stdcall v49();
    virtual void __stdcall v50();
    virtual void __stdcall v51();
    virtual void __stdcall v52();
    virtual void __stdcall v53();
    virtual void __stdcall v54();
    virtual void __stdcall v55();
    virtual void __stdcall v56();
    virtual void __stdcall v57();
    virtual void __stdcall v58();
    virtual void __stdcall v59();
    virtual void __stdcall v60();
    virtual void __stdcall v61();
    virtual void __stdcall v62();
    virtual void __stdcall v63();
    virtual void __stdcall v64();
    virtual void __stdcall v65();
    virtual void __stdcall v66();
    virtual void __stdcall v67();
    virtual void __stdcall v68();
    virtual void __stdcall v69();
    virtual void __stdcall v70();
    virtual void __stdcall v71();
    virtual void __stdcall v72();
    virtual void __stdcall v73();
    virtual void __stdcall v74();
    virtual void __stdcall v75();
    virtual void __stdcall v76();
    virtual void __stdcall v77();
    virtual void __stdcall v78();
    virtual void __stdcall v79();
    virtual void __stdcall v80();
    virtual void __stdcall v81();
    virtual void __stdcall v82();
    virtual void __stdcall v83();
    virtual void __stdcall v84();
    virtual void __stdcall v85();
    virtual void __stdcall v86();
    virtual void __stdcall v87();
    virtual void __stdcall v88();
    virtual void __stdcall v89();
    virtual void __stdcall v90();
    virtual void __stdcall v91();
    virtual void __stdcall v92();
    virtual void __stdcall v93();
    virtual void __stdcall v94();
    virtual void __stdcall v95();
    virtual void __stdcall v96();
    virtual void __stdcall v97();
    virtual void __stdcall v98();
    virtual void __stdcall v99();
    virtual void __stdcall v100(int, int, int, int);
    virtual void __stdcall v101();
    virtual void __stdcall v102();
    virtual void __stdcall v103();
    virtual void __stdcall v104(int);
};
struct Flt
{
    operator unsigned int();
};
struct FUN_00b65660_s
{
    void FUN_00b65660();
};
struct FUN_00b630c0_s
{
    void FUN_00b630c0();
};
unsigned int __cdecl FUN_0045c670();
void* __cdecl FUN_004a0e90();
struct BSTextureManager
{
    void AddRenderedTexture(BSRenderedTexture*);
};
BSTextureManager* __stdcall FUN_004a0ea0();
struct FUN_004dc020_Class
{
    Dev9* FUN_004dc020();
};
struct S5;
struct S4
{
    S5* FUN_004ebbc0(int);
};
struct FUN_00876a00_Class
{
    void FUN_00876a00();
};
struct FUN_00642890_Class
{
    void FUN_00642890();
};
struct BSFaceGenNiNode
{
    void* GetAnimationData();
};
struct GO
{
    void operator=(void*);
};
struct MiddleLowProcess
{
    int GetProcessInteger();
};
struct ArrSI
{
    unsigned int GetFlags();
};
int __cdecl FUN_00683a60();
int __cdecl FUN_00714900();
void __cdecl FUN_00b4f510();
void __cdecl FUN_00b540b0();
void __cdecl FUN_00b988e0();
void __cdecl FUN_00bad4a0();
void __cdecl FUN_00ba9420(void*);
struct FUN_004d61b0
{
    char pad[0x30];
    FUN_004d61b0(unsigned int, unsigned int, unsigned int, const char*, unsigned int, unsigned int, int, int);
};
extern unsigned char DAT_011f9440;
extern Flt DAT_011fa008;

// @fnv 0x00876850
void FUN_00876850_shell::FUN_00876850(BSRenderedTexture* apRenderTexture, ImageSpaceManager* apImagespaceManager,
                                      GraphicsRenderer* apRenderer, Sun* apSun)
{
    Dev9* pd3ddevice;
    int apCuller;
    unsigned int apSceneGraph;
    apSceneGraph = FUN_0045c670();
    apCuller = ((MiddleLowProcess*)apSceneGraph)->GetProcessInteger();
    if (apSun)
        ((FUN_00642890_Class*)apSun)->FUN_00642890();
    FUN_00ba9420(((BSFaceGenNiNode*)apSceneGraph)->GetAnimationData());
    if (apRenderTexture)
        FUN_004a0ea0()->AddRenderedTexture(apRenderTexture);
    ((FUN_00b65660_s*)(unsigned int)*(Flt*)((char*)this + 0x88))->FUN_00b65660();
    ((FUN_00b630c0_s*)(unsigned int)*(Flt*)((char*)this + 0x94))->FUN_00b630c0();
    FUN_00b540b0();
    FUN_00b4f510();
    ((FUN_00876a00_Class*)((S4*)apImagespaceManager)->FUN_004ebbc0(4))->FUN_00876a00();
    if (DAT_011f9440)
        FUN_00bad4a0();
    pd3ddevice = ((FUN_004dc020_Class*)FUN_004a0e90())->FUN_004dc020();
    pd3ddevice->v104(0);
    pd3ddevice->v100(0, 0, 0, 0);
    if (FUN_00683a60())
        FUN_00714900();
    if ((unsigned int)DAT_011fa008)
    {
        new FUN_004d61b0(((TESForm*)this)->GetFormID(), ((ArrSI*)this)->GetFlags(), (unsigned int)DAT_011fa008,
                         "Render Passes", 0x80000000, 0x80000000, 800, 600);
        (GO&)DAT_011fa008 = 0;
    }
    FUN_00b988e0();
}
}  // namespace fnv_00876850

namespace fnv_00877260 {
struct NiStream;
struct blob12
{
    char b[12];
};
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];
struct NiUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    char _pad_9[3];
};
typedef char _sizecheck_NiUpdateData[sizeof(NiUpdateData) == 12 ? 1 : -1];
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];

class GridCell;
class NiNode;
class IOManager;
class TESObjectREFR;
class ThreeByThreeMatrix
{
  public:
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
struct M3 : public ThreeByThreeMatrix
{
};
struct V3;
class NiAVObject
{
  public:
    void UpdateSceneObject();
    void SetLocalRotation(const ThreeByThreeMatrix& kRot);
};
class NiNode
{
  public:
    void Update(const NiUpdateData& kData);
};
struct NiNode_00558310;
NiAVObject* __fastcall FUN_00558310(NiNode_00558310*);
unsigned int __cdecl FUN_0045c670();
struct FUN_0056fa00_S
{
    M3 FUN_0056fa00();
};
class TES
{
  public:
    GridCell* FUN_00457050(int, int);
};
struct CP_008c48d0
{
    int GetPrevPath();
};
struct GlobalObject_0045cfe0
{
    int* Int();
};
extern GlobalObject_0045cfe0 g_011c63cc;
extern int g_TES;
struct FUN_0054cfd0_S
{
    bool FUN_0054cfd0(::NiPoint3* apPos, ::NiPoint3* apRot);
};
struct FUN_00548230_S
{
    void FUN_00548230(TESObjectREFR* apRef, bool abFlag);
};
struct FUN_00456520_Class
{
    void FUN_00456520();
};
extern IOManager* DAT_01202d98;
class AutoMemHelper
{
  public:
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
    int iOld;
};
struct PC_00605d70
{
    NiNode* GetNode(bool);
};
class NiAdditionalGeometryData
{
  public:
    static NiAVObject* __cdecl GetShadowSceneNodeForIndex(int);
};
struct FUN_00b5cbd0_S
{
    void FUN_00b5cbd0(NiNode* apNode);
};
struct FUN_00565730_S
{
    void FUN_00565730();
};
struct FUN_00440460_S
{
    void FUN_00440460(const V3*);
};
struct UpdData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    void NiUpdateData(float, bool, bool);
};
class PlayerVT
{
  public:
    virtual void vf000();
    virtual void vf001();
    virtual void vf002();
    virtual void vf003();
    virtual void vf004();
    virtual void vf005();
    virtual void vf006();
    virtual void vf007();
    virtual void vf008();
    virtual void vf009();
    virtual void vf010();
    virtual void vf011();
    virtual void vf012();
    virtual void vf013();
    virtual void vf014();
    virtual void vf015();
    virtual void vf016();
    virtual void vf017();
    virtual void vf018();
    virtual void vf019();
    virtual void vf020();
    virtual void vf021();
    virtual void vf022();
    virtual void vf023();
    virtual void vf024();
    virtual void vf025();
    virtual void vf026();
    virtual void vf027();
    virtual void vf028();
    virtual void vf029();
    virtual void vf030();
    virtual void vf031();
    virtual void vf032();
    virtual void vf033();
    virtual void vf034();
    virtual void vf035();
    virtual void vf036();
    virtual void vf037();
    virtual void vf038();
    virtual void vf039();
    virtual void vf040();
    virtual void vf041();
    virtual void vf042();
    virtual void vf043();
    virtual void vf044();
    virtual void vf045();
    virtual void vf046();
    virtual void vf047();
    virtual void vf048();
    virtual void vf049();
    virtual void vf050();
    virtual void vf051();
    virtual void vf052();
    virtual void vf053();
    virtual void vf054();
    virtual void vf055();
    virtual void vf056();
    virtual void vf057();
    virtual void vf058();
    virtual void vf059();
    virtual void vf060();
    virtual void vf061();
    virtual void vf062();
    virtual void vf063();
    virtual void vf064();
    virtual void vf065();
    virtual void vf066();
    virtual void vf067();
    virtual void vf068();
    virtual void vf069();
    virtual void vf070();
    virtual void vf071();
    virtual void vf072();
    virtual void vf073();
    virtual void vf074();
    virtual void vf075();
    virtual void vf076();
    virtual void vf077();
    virtual void vf078();
    virtual void vf079();
    virtual void vf080();
    virtual void vf081();
    virtual void vf082();
    virtual void vf083();
    virtual void vf084();
    virtual void vf085();
    virtual void vf086();
    virtual void vf087();
    virtual void vf088();
    virtual void vf089();
    virtual void vf090();
    virtual void vf091();
    virtual void vf092();
    virtual void vf093();
    virtual void vf094();
    virtual void vf095();
    virtual void vf096();
    virtual void vf097();
    virtual void vf098();
    virtual void vf099();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual void vf125();
    virtual void vf126();
    virtual void vf127();
    virtual void vf128();
    virtual void vf129();
    virtual void vf130();
    virtual void vf131();
    virtual void vf132();
    virtual void vf133();
    virtual void vf134();
    virtual void vf135();
    virtual void vf136();
    virtual void vf137();
    virtual void vf138();
    virtual void vf139();
    virtual void vf140();
    virtual void vf141();
    virtual void vf142();
    virtual void vf143();
    virtual void vf144();
    virtual void vf145();
    virtual void vf146();
    virtual void vf147();
    virtual void vf148();
    virtual void vf149();
    virtual void vf150();
    virtual void vf151();
    virtual void vf152();
    virtual void vf153();
    virtual void vf154();
    virtual void vf155();
    virtual void vf156();
    virtual void vf157();
    virtual void vf158();
    virtual void vf159();
    virtual void vf160();
    virtual void vf161();
    virtual void vf162();
    virtual void vf163();
    virtual void vf164();
    virtual void vf165();
    virtual void vf166();
    virtual void vf167();
    virtual void vf168();
    virtual void vf169();
    virtual void SetPositionV(::NiPoint3* apPos);
    virtual void vf171();
    virtual void vf172();
    virtual void vf173();
    virtual void vf174();
    virtual void vf175();
    virtual void vf176();
    virtual void SetZRotV(float afZ);
};
extern PlayerVT* _g_thePlayer;

// @fnv 0x00877260
void __cdecl FUN_00877260(::NiPoint3 apos)
{
    TESObjectCELL* pcell = (TESObjectCELL*)((CP_008c48d0*)g_TES)->GetPrevPath();
    UpdData UpdateData;
    ::NiPoint3 rot = ::NiPoint3::ZERO;
    if (!pcell)
    {
        pcell = *(TESObjectCELL**)((TES*)g_TES)
                     ->FUN_00457050((unsigned int)*g_011c63cc.Int() >> 1, (unsigned int)*g_011c63cc.Int() >> 1);
    }
    if (pcell)
    {
        ((FUN_0054cfd0_S*)pcell)->FUN_0054cfd0(&apos, &rot);
    }
    _g_thePlayer->SetZRotV(rot.z);
    _g_thePlayer->SetPositionV(&apos);
    if (pcell)
    {
        ((FUN_00548230_S*)pcell)->FUN_00548230((TESObjectREFR*)_g_thePlayer, false);
        ((FUN_00456520_Class*)DAT_01202d98)->FUN_00456520();
        AutoMemHelper tempMemContext(0x34, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp",
                                     0x2612);
        ((NiAVObject*)((PC_00605d70*)_g_thePlayer)->GetNode(false))->UpdateSceneObject();
        ((FUN_00b5cbd0_S*)NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))
            ->FUN_00b5cbd0(((PC_00605d70*)_g_thePlayer)->GetNode(false));
    }
    ((FUN_00565730_S*)_g_thePlayer)->FUN_00565730();
    ((FUN_00440460_S*)FUN_00558310((NiNode_00558310*)FUN_0045c670()))->FUN_00440460((const V3*)&apos);
    FUN_00558310((NiNode_00558310*)FUN_0045c670())->SetLocalRotation(((FUN_0056fa00_S*)_g_thePlayer)->FUN_0056fa00());
    UpdateData.NiUpdateData(0.0f, false, false);
    ((NiNode*)FUN_00558310((NiNode_00558310*)FUN_0045c670()))->Update(*(NiUpdateData*)&UpdateData);
}
}  // namespace fnv_00877260

struct GlobalObject_00869b10
{
    void RemoveAt(unsigned int);
};

struct FUN_0086bc10_t
{
    char pad[0xaf4];
    GlobalObject_00869b10 a;
    char pad2[0xb04 - 0xaf4 - 1];
    GlobalObject_00869b10 b;
    int FUN_0086bc60(int);
    bool FUN_0086bc10(int);
};

// Looks up arg via FUN_0086bc60; if found, removes that index from a and b and returns true, otherwise returns false.
// @fnv 0x0086bc10
bool FUN_0086bc10_t::FUN_0086bc10(int arg)
{
    int idx = FUN_0086bc60(arg);
    if (idx == -1)
        return false;
    a.RemoveAt(idx);
    b.RemoveAt(idx);
    return true;
}

namespace fnv_0086bc60 {
struct Arr
{
    unsigned int GetSize();
    unsigned int* GetAt(int);
};

struct FUN_0086bc60_t
{
    char m_data[0xaf4];
    Arr arr;
    int FUN_0086bc60(int value);
};

// Searches arr for the first element equal to value and returns its index, or -1 if not found.
// @fnv 0x0086bc60
int FUN_0086bc60_t::FUN_0086bc60(int value)
{
    for (unsigned int i = 0; i < arr.GetSize(); i++)
    {
        if (*arr.GetAt(i) == value)
            return i;
    }
    return -1;
}
}  // namespace fnv_0086bc60

namespace fnv_00872940 {
struct S148c0
{
};

struct ImageSpaceManager
{
};

struct BSRenderedTexture
{
};

struct NiParallelUpdateTaskManager
{
    void SetupTaskWorkers();
};

struct Interface
{
  public:
    enum enumMenus
    {
        MENU_ID_0x3f6 = 0x3f6,
        MENU_ID_0x41e = 0x41e,
        MENU_ID_0x424 = 0x424,
        MENU_ID_0x432 = 0x432,
        MENU_ID_0x438 = 0x438,
        MENU_ID_0x439 = 0x439,
        MENU_ID_0x43a = 0x43a,
        MENU_ID_0x43b = 0x43b
    };

    static bool __cdecl IsMenuActive(enumMenus menuID, unsigned int parameter);
};

S148c0* __cdecl FUN_0043c4b0(void);
ImageSpaceManager* __cdecl FUN_004e3270(void);
bool __cdecl FUN_004dc310(void);
unsigned char __cdecl FUN_008709f0(void);

void __cdecl FUN_00709ae0(void);
void __cdecl FUN_00709af0(void);
void __cdecl FUN_00709b00(void);
void __cdecl FUN_00709b10(void);
void __cdecl FUN_00709b20(void);
void __cdecl FUN_00709b30(void);
void __cdecl FUN_007948d0(void);
void __cdecl FUN_007c9ca0(void);

struct MainTarget
{
    int FUN_00872f50(S148c0* prenderer, BSRenderedTexture* apDestination, int parameter, bool bmultiSampleEnabled);
    void FUN_00874b90(ImageSpaceManager* pimagespacemanager, S148c0* prenderer, bool bmultiSampleEnabled,
                      BSRenderedTexture* apDestination);
    void FUN_00875fd0(bool bmultiSampleEnabled, int result, S148c0* prenderer, BSRenderedTexture* apDestination);
    void FUN_00876830(bool bmultiSampleEnabled, BSRenderedTexture* apDestination);
    void FUN_00876850(int result, ImageSpaceManager* pimagespacemanager, S148c0* prenderer, int parameter);

    void FUN_00872940(BSRenderedTexture* apDestination);
};

// @fnv 0x00872940
void MainTarget::FUN_00872940(BSRenderedTexture* apDestination)
{
    S148c0* prenderer = FUN_0043c4b0();
    ImageSpaceManager* pimagespacemanager = FUN_004e3270();
    const bool bmultiSampleEnabled = FUN_004dc310();
    int result;

    reinterpret_cast<NiParallelUpdateTaskManager*>(this)->SetupTaskWorkers();

    result = FUN_00872f50(prenderer, apDestination, 0, bmultiSampleEnabled);

    FUN_00874b90(pimagespacemanager, prenderer, bmultiSampleEnabled, apDestination);

    if (Interface::IsMenuActive(Interface::MENU_ID_0x41e, 0))
        FUN_00709ae0();

    if (Interface::IsMenuActive(Interface::MENU_ID_0x3f6, 0))
        FUN_00709af0();

    if (Interface::IsMenuActive(Interface::MENU_ID_0x438, 0))
        FUN_00709b00();

    if (Interface::IsMenuActive(Interface::MENU_ID_0x439, 0))
        FUN_00709b10();

    if (Interface::IsMenuActive(Interface::MENU_ID_0x43a, 0))
        FUN_00709b20();

    if (Interface::IsMenuActive(Interface::MENU_ID_0x43b, 0))
        FUN_00709b30();

    if (Interface::IsMenuActive(Interface::MENU_ID_0x432, 0))
        FUN_007948d0();

    if (FUN_008709f0())
    {
        FUN_00875fd0(bmultiSampleEnabled, result, prenderer, apDestination);
    }
    else if (apDestination)
    {
        FUN_00876830(bmultiSampleEnabled, apDestination);
    }

    FUN_00876850(result, pimagespacemanager, prenderer, 0);

    if (Interface::IsMenuActive(Interface::MENU_ID_0x424, 0))
        FUN_007c9ca0();
}
}  // namespace fnv_00872940

class FUN_004505a0_target
{
  public:
    int Get();
};

class FUN_004505a0_cls
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
    FUN_004505a0_target* m_28;
    int FUN_004505a0();
};

// Returns the result of calling Get on m_28 if it is non-null, otherwise returns 0.
// @fnv 0x004505a0
int FUN_004505a0_cls::FUN_004505a0()
{
    return (m_28 != 0) ? m_28->Get() : 0;
}

// FUN_0086ba90 candidate
struct OffScreenFrameHost
{
    virtual bool v00();
    virtual bool v01();
    virtual bool v02();
    virtual bool v03();
    virtual bool v04();
    virtual bool v05();
    virtual bool v06();
    virtual bool v07();
    virtual bool v08();
    virtual bool v09();
    virtual bool v0A();
    virtual bool v0B();
    virtual bool v0C();
    virtual bool v0D();
    virtual bool v0E();
    virtual bool v0F();
    virtual bool v10();
    virtual bool v11();
    virtual bool v12();
    virtual bool v13();
    virtual bool v14();
    virtual bool v15();
    virtual bool v16();
    virtual bool v17();
    virtual bool v18();
    virtual bool v19();
    virtual bool v1A();
    virtual bool v1B();
    virtual bool v1C();
    virtual bool v1D();
    virtual bool v1E();
    virtual bool v1F();
    virtual bool v20();
    virtual bool v21();
    virtual bool v22();
    virtual bool v23();
    virtual bool v24();
    virtual bool v25();
    virtual bool v26();
    virtual bool v27();
    virtual bool v28();
    virtual bool v29();
    virtual bool v2A();
    virtual bool v2B();
    virtual bool v2C();
    virtual bool v2D();
    virtual bool v2E();
    virtual bool v2F();
    virtual bool v30();
    virtual bool v31();
    virtual bool v32();
    virtual bool v33();
    virtual bool v34();
    virtual bool v35();
    virtual bool v36();
    virtual bool v37();
    virtual bool v38();
    virtual bool v39();
    virtual bool v3A();
    virtual bool v3B();
    virtual bool v3C();
    virtual bool v3D();
    virtual bool v3E();
    virtual bool v3F();
    virtual bool v40();
    virtual bool v41();
    virtual bool v42();
    virtual bool v43();
    virtual bool v44();
    virtual bool v45();
    virtual bool v46();
    virtual bool v47();
    virtual bool v48();
    virtual bool v49();
    virtual bool v4A();
    virtual bool v4B();
    virtual bool v4C();
    virtual bool v4D();
    virtual bool v4E();
    virtual bool v4F();
    virtual bool v50();
    virtual bool v51();
    virtual bool v52();
    virtual bool v53();
    virtual bool v54();
    virtual bool v55();
    virtual bool v56();
    virtual bool v57();
    virtual bool v58();
    virtual bool v59();
    virtual bool v5A();
    virtual bool v5B();
    virtual bool v5C();
    virtual bool v5D();
    virtual bool v5E();
    virtual bool v5F();
    virtual bool v60();
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
    int m_200;
    bool FUN_0086ba60(const char* name, int flags);
    bool FUN_0086ba90();
};
// Calls FUN_0086ba60 with "EndOffScreenFrame" and flags 2, then v60; on success clears m_200 and returns true.
// @fnv 0x0086ba90
bool OffScreenFrameHost::FUN_0086ba90()
{
    if (!FUN_0086ba60("EndOffScreenFrame", 2))
    {
        return false;
    }
    if (!v60())
    {
        return false;
    }
    m_200 = 0;
    return true;
}

class Sky86B
{
  public:
    virtual ~Sky86B();

    static Sky86B* pInstance;
};

class SkyOwner86B
{
  public:
    void FUN_0086be30();
};

// Deletes the Sky86B singleton instance and clears its static pointer.
// @fnv 0x0086be30
void SkyOwner86B::FUN_0086be30()
{
    delete Sky86B::pInstance;
    Sky86B::pInstance = 0;
}

class C86D4C0Timer
{
  public:
    int unk00;
    float m_fInterval;

    void FUN_0086d4c0(unsigned int uiFrequency);
};

// Stores the timer interval as 1000 divided by uiFrequency, or 0 when uiFrequency is zero.
// @fnv 0x0086d4c0
void C86D4C0Timer::FUN_0086d4c0(unsigned int uiFrequency)
{
    m_fInterval = uiFrequency ? 1000.0 / uiFrequency : 0.0;
}

class B86F190Process
{
  public:
    bool FUN_00483710();
};

class B86F190Actor
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11C();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12C();
    virtual void vfn130();
    virtual void vfn134();
    virtual void vfn138();
    virtual void vfn13C();
    virtual void vfn140();
    virtual void vfn144();
    virtual void vfn148();
    virtual void vfn14C();
    virtual void vfn150();
    virtual void vfn154();
    virtual void vfn158();
    virtual void vfn15C();
    virtual void vfn160();
    virtual void vfn164();
    virtual void vfn168();
    virtual void vfn16C();
    virtual void vfn170();
    virtual void vfn174();
    virtual void vfn178();
    virtual void vfn17C();
    virtual void vfn180();
    virtual void vfn184();
    virtual void vfn188();
    virtual void vfn18C();
    virtual void vfn190();
    virtual void vfn194();
    virtual void vfn198();
    virtual void vfn19C();
    virtual void vfn1A0();
    virtual void vfn1A4();
    virtual void vfn1A8();
    virtual void vfn1AC();
    virtual void vfn1B0();
    virtual void vfn1B4();
    virtual void vfn1B8();
    virtual void vfn1BC();
    virtual void vfn1C0();
    virtual void vfn1C4();
    virtual void vfn1C8();
    virtual void vfn1CC();
    virtual void* GetNiNode();

    int FUN_00931850();
    B86F190Process* GetProcess();
};

class B86F190ActorList
{
  public:
    unsigned int GetCount(int iUnused);
    B86F190Actor* GetAt(unsigned int uiIndex);
};

class B86F190Manager
{
  public:
    B86F190ActorList* GetActors();
};

extern bool g_bB86F190Enabled;
extern bool g_bB86F190Pending;
extern B86F190Manager g_kB86F190Manager;

class B86F190Owner
{
  public:
    void FUN_0086f190();
};

// @fnv 0x0086f190
void B86F190Owner::FUN_0086f190()
{
    if (g_bB86F190Enabled)
    {
        if (g_bB86F190Pending)
        {
            B86F190ActorList* pkList = g_kB86F190Manager.GetActors();
            B86F190Actor* pkActor = 0;
            for (unsigned int i = 0; i < pkList->GetCount(0); i++)
            {
                pkActor = pkList->GetAt(i);
                if (pkActor && !pkActor->FUN_00931850() && pkActor->GetNiNode())
                {
                    B86F190Process* pkProcess = pkActor->GetProcess();
                    pkProcess->FUN_00483710();
                }
            }
            reinterpret_cast<B86F190Actor*>(g_thePlayer)->GetProcess()->FUN_00483710();
        }
        g_bB86F190Pending = false;
    }
    else
    {
        g_bB86F190Pending = true;
    }
}

extern "C" __declspec(dllimport) void __stdcall DebugBreak();

struct FUN_00872ed0_shell
{
    void FUN_00872ed0(int param_1);
};

// @fnv 0x00872ed0
void FUN_00872ed0_shell::FUN_00872ed0(int aiUnused)
{
    DebugBreak();
}

struct Point3Ctor
{
    float x;
    float y;
    float z;
    Point3Ctor(float fX, float fY, float fZ);
};

struct ScaleSource
{
    NiPoint3 GetScale3() const;
};

NiPoint3* __fastcall FUN_0045bb80(ScaleSource* pObj);

extern NiPoint3 DAT_011a9490;
extern bool DAT_012003cc;
extern NiPoint3 DAT_012003d4;
extern NiPoint3 DAT_012003e0;

// Compares the object's current scale vectors against stored ones, sets DAT_012003cc when any component ratio exceeds 1.1, and stores the new vectors.
// @fnv 0x008744a0
void __cdecl FUN_008744a0(ScaleSource* apScaleSource)
{
    if (apScaleSource == 0)
    {
        DAT_012003d4 = DAT_011a9490;
        DAT_012003cc = false;
        return;
    }
    NiPoint3 kCurA = *FUN_0045bb80(apScaleSource);
    NiPoint3 kCurB = apScaleSource->GetScale3();
    NiPoint3 kDiffA_2 = kCurA - DAT_012003e0;
    NiPoint3 kDiffB5 = kCurB - DAT_012003d4;
    Point3Ctor kRatioA(kDiffA_2.x / DAT_012003e0.x, kDiffA_2.y / DAT_012003e0.y, kDiffA_2.z / DAT_012003e0.z);
    Point3Ctor kRatioB4(kDiffB5.x / DAT_012003d4.x, kDiffB5.y / DAT_012003d4.y, kDiffB5.z / DAT_012003d4.z);
    if (kRatioA.x > 1.1 || kRatioA.y > 1.1 || kRatioA.z > 1.1 || kRatioB4.x > 1.1 || kRatioB4.y > 1.1 ||
        kRatioB4.z > 1.1)
    {
        DAT_012003cc = true;
    }
    else
    {
        DAT_012003cc = false;
    }
    DAT_012003e0 = kCurA;
    DAT_012003d4 = kCurB;
}

struct FlagBlock_a234c0
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
    unsigned char flags[0x20];
};

struct FlagPair_a234c0
{
    FlagBlock_a234c0 first;
    FlagBlock_a234c0 second;
};

struct FlagOwner_a234c0
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
    FlagPair_a234c0 pairs[4];

    int FUN_00a234c0(int index, int bit, int mode);
};

// Compares the 0x80 bit of flags[bit] in the first and second flag blocks of pairs[index] according to mode and returns 1 if the mode's condition holds.
// @fnv 0x00a234c0
int FlagOwner_a234c0::FUN_00a234c0(int index, int bit, int mode)
{
    FlagBlock_a234c0* first = &pairs[index].first;
    FlagBlock_a234c0* second6 = &pairs[index].second;
    int result5 = 0;
    switch (mode)
    {
    case 0:
        if (first->flags[bit] & 0x80)
            result5 = 1;
        break;
    case 1:
        if (!(second6->flags[bit] & 0x80) && (first->flags[bit] & 0x80))
            result5 = 1;
        break;
    case 2:
        if (!(first->flags[bit] & 0x80) && (second6->flags[bit] & 0x80))
            result5 = 1;
        break;
    case 3:
        if ((first->flags[bit] & 0x80) != (second6->flags[bit] & 0x80))
            result5 = 1;
        break;
    }
    return result5;
}

struct FUN_00a235f0_Row
{
    unsigned int m_value00;
    unsigned int m_value01;
    unsigned int m_value02;
    unsigned int m_value03;
    unsigned int m_value04;
    unsigned int m_value05;
    unsigned int m_value06;
    unsigned int m_value07;
    unsigned int m_value08;
    unsigned int m_value09;
    unsigned int m_value10;
    unsigned int m_value11;
    unsigned int m_value12;
    unsigned int m_value13;
    unsigned int m_value14;
    unsigned int m_value15;
    unsigned int m_value16;
    unsigned int m_value17;
    unsigned int m_value18;
    unsigned int m_value19;
    unsigned int m_value20;
    unsigned int m_value21;
    unsigned int m_value22;
    unsigned int m_value23;
    unsigned int m_value24;
    unsigned int m_value25;
    unsigned int m_value26;
    unsigned int m_value27;
    unsigned int m_value28;
    unsigned int m_value29;
    unsigned int m_value30;
    unsigned int m_value31;
    unsigned int m_field80;
    unsigned int m_field84;
    unsigned int m_field88;
    unsigned int m_field8c;
    unsigned int m_field90;
    unsigned int m_field94;
    unsigned int m_field98;
    unsigned int m_field9c;
};

struct FUN_00a235f0_Class
{
    unsigned int m_field00;
    unsigned int m_field04;
    unsigned int m_field08;
    unsigned int m_field0c;
    unsigned int m_field10;
    unsigned int m_field14;
    unsigned int m_field18;
    unsigned int m_field1c;
    unsigned int m_field20;
    unsigned int m_field24;
    unsigned int m_field28;
    unsigned int m_field2c;
    unsigned int m_field30;
    FUN_00a235f0_Row m_row;

    int __thiscall FUN_00a235f0(int param_1, int param_2);
};

// Reads a 32-bit value from the row at offset param_1*0xa0+0x34, returns -1 if its low 16 bits are 0xffff, else value/0x1194+0x20.
// @fnv 0x00a235f0
int __thiscall FUN_00a235f0_Class::FUN_00a235f0(int aiRowIndex, int aiColumnIndex)
{
    unsigned int* row = reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + aiRowIndex * 0xa0 + 0x34);
    int value = static_cast<int>(row[aiColumnIndex + 8]);

    if (static_cast<unsigned short>(value & 0xffff) == 0xffff)
        return -1;

    return value / 0x1194 + 0x20;
}

struct FUN_00a23650_entry
{
    unsigned int m_flags;
    char unk04[0x244 - 4];
};

struct FUN_00a23650_cls
{
    char unk000[0x558];
    FUN_00a23650_entry m_entries[1];
    int FUN_00a23650(int index);
};

// Reads the byte at bits 8-15 of the flags of the entry at index and returns 2 for that case, otherwise -1.
// @fnv 0x00a23650
int FUN_00a23650_cls::FUN_00a23650(int index)
{
    switch ((unsigned char)((m_entries[index].m_flags >> 8) & 0xff))
    {
    case 2:
        return 2;
    }
    return -1;
}

struct FUN_00a236f0_data
{
    unsigned int m_iElementCount;
    unsigned int m_flags;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};

class FUN_00a236f0_item
{
  public:
    virtual void __stdcall v00();
    virtual void __stdcall v01();
    virtual void __stdcall v02();
    virtual void __stdcall v03();
    virtual void __stdcall v04();
    virtual void __stdcall v05();
    virtual void __stdcall v06(int code, void* data);
};

class FUN_00a236f0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_00a236f0_item* m_items[1];
    void FUN_00a236f0(int index, int a2, int a3);
};

// Builds a data block with the given values and dispatches it to the item at index via v06 with code 4.
// @fnv 0x00a236f0
void FUN_00a236f0_cls::FUN_00a236f0(int index, int aiValue1, int aiValue2)
{
    FUN_00a236f0_item* pItem = m_items[index];
    FUN_00a236f0_data data;
    data.m_iElementCount = 0x18;
    data.m_flags = 0x10;
    data.unk0C = 0;
    data.unk08 = 0;
    data.unk10 = aiValue1;
    data.unk14 = aiValue2;
    pItem->v06(4, &data);
}

typedef unsigned int DWORD;
struct DIPROPHEADER
{
    DWORD dwSize;
    DWORD dwHeaderSize;
    DWORD dwObj;
    DWORD dwHow;
};
struct DIPROPDWORD
{
    DIPROPHEADER diph;
    DWORD dwData;
};
struct InputDevice
{
    virtual unsigned int __stdcall QueryInterface(void*, void**);
    virtual unsigned int __stdcall AddRef();
    virtual unsigned int __stdcall Release();
    virtual unsigned int __stdcall GetCapabilities(void*);
    virtual unsigned int __stdcall EnumObjects(void*, void*, DWORD);
    virtual unsigned int __stdcall GetProperty(const void*, DIPROPHEADER*);
    virtual unsigned int __stdcall SetProperty(const void*, const DIPROPHEADER*);
};
struct InputManager
{
    int unk00;
    int unk04;
    int unk08;
    InputDevice* devices[1];
    void FUN_00a23750(int index, float value);
};
// Scales value by 10000 and sets property 5 on the input device at index via SetProperty.
// @fnv 0x00a23750
void InputManager::FUN_00a23750(int index, float value)
{
    InputDevice* device = devices[index];
    DIPROPDWORD property;
    property.diph.dwSize = sizeof(DIPROPDWORD);
    property.diph.dwHeaderSize = sizeof(DIPROPHEADER);
    property.diph.dwHow = 0;
    property.diph.dwObj = 0;
    property.dwData = (int)(value * 10000.0);
    device->SetProperty((const void*)5, &property.diph);
}

class A237F0Object
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
    void* m_pResource;

    int Lookup(int iKey);
    int FUN_00a237f0(int iKey);
};

// @fnv 0x00a237f0
int A237F0Object::FUN_00a237f0(int iKey)
{
    if (m_pResource && Lookup(iKey) == 1)
        return 1;
    return 0;
}

struct FUN_00a23820_tmp
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class FUN_00a23820_callee
{
  public:
    virtual void Unk_00(void);
    virtual void Unk_01(void);
    virtual void Unk_02(void);
    virtual void Unk_03(void);
    virtual void Unk_04(void);
    virtual void Unk_05(void);
    virtual void Unk_06(void);
    virtual void Unk_07(void);
    virtual void Unk_08(void);
    virtual void Unk_09(void);
    virtual int __stdcall Unk_0A(int size, FUN_00a23820_tmp* out, int* flag, int zero);
};

class FUN_00a23820_cls
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
    FUN_00a23820_callee* m_pCallee;
    int FUN_00a23820(int* out);
};

// Calls m_pCallee->Unk_0A with size 0x14 and, on success with flag set, writes tmp.unk00 to out and returns 2 or 1 depending on bit 0x80 of tmp.unk04.
// @fnv 0x00a23820
int FUN_00a23820_cls::FUN_00a23820(int* piOut)
{
    int pad;
    if ((m_pCallee != 0) != false)
    {
        int flag = 1;
        int r;
        FUN_00a23820_tmp tmp;
        if (m_pCallee->Unk_0A(0x14, &tmp, &flag, 0) == 0 && flag != 0)
        {
            r = ((tmp.unk04 & 0x80) != 0 ? -1 : 0) + 2;
            *piOut = tmp.unk00;
            return r;
        }
    }
    return 0;
}

typedef unsigned short WORD245;
typedef unsigned long DWORD245;

class InputManager245
{
  public:
    int GetKeyboardState(unsigned char ucKey, int iState);
    int GetMouseState(unsigned char ucKey, int iState);
    int GetOtherState(unsigned char ucKey, int iState);
    int GetJoystickButtonState(int iJoystick, unsigned char ucButton, int iState);
    int GetJoystickPOV(int iJoystick, int m_uiTrailingValue);
    int FUN_00a24560(int iControlSlot, unsigned char ucKey, int iState);

    int unk0000, unk0004, unk0008, unk000C, unk0010, unk0014, unk0018, unk001C;
    int unk0020, unk0024, unk0028, unk002C, unk0030, unk0034, unk0038, unk003C;
    int unk0040, unk0044, unk0048, unk004C, unk0050, unk0054, unk0058, unk005C;
    int unk0060, unk0064, unk0068, unk006C, unk0070, unk0074, unk0078, unk007C;
    int unk0080, unk0084, unk0088, unk008C, unk0090, unk0094, unk0098, unk009C;
    int unk00A0, unk00A4, unk00A8, unk00AC, unk00B0, unk00B4, unk00B8, unk00BC;
    int unk00C0, unk00C4, unk00C8, unk00CC, unk00D0, unk00D4, unk00D8, unk00DC;
    int unk00E0, unk00E4, unk00E8, unk00EC, unk00F0, unk00F4, unk00F8, unk00FC;
    int unk0100, unk0104, unk0108, unk010C, unk0110, unk0114, unk0118, unk011C;
    int unk0120, unk0124, unk0128, unk012C, unk0130, unk0134, unk0138, unk013C;
    int unk0140, unk0144, unk0148, unk014C, unk0150, unk0154, unk0158, unk015C;
    int unk0160, unk0164, unk0168, unk016C, unk0170, unk0174, unk0178, unk017C;
    int unk0180, unk0184, unk0188, unk018C, unk0190, unk0194, unk0198, unk019C;
    int unk01A0, unk01A4, unk01A8, unk01AC, unk01B0, unk01B4, unk01B8, unk01BC;
    int unk01C0, unk01C4, unk01C8, unk01CC, unk01D0, unk01D4, unk01D8, unk01DC;
    int unk01E0, unk01E4, unk01E8, unk01EC, unk01F0, unk01F4, unk01F8, unk01FC;
    int unk0200, unk0204, unk0208, unk020C, unk0210, unk0214, unk0218, unk021C;
    int unk0220, unk0224, unk0228, unk022C, unk0230, unk0234, unk0238, unk023C;
    int unk0240, unk0244, unk0248, unk024C, unk0250, unk0254, unk0258, unk025C;
    int unk0260, unk0264, unk0268, unk026C, unk0270, unk0274, unk0278, unk027C;
    int unk0280, unk0284, unk0288, unk028C, unk0290, unk0294, unk0298, unk029C;
    int unk02A0, unk02A4, unk02A8, unk02AC, unk02B0, unk02B4, unk02B8, unk02BC;
    int unk02C0, unk02C4, unk02C8, unk02CC, unk02D0, unk02D4, unk02D8, unk02DC;
    int unk02E0, unk02E4, unk02E8, unk02EC, unk02F0, unk02F4, unk02F8, unk02FC;
    int unk0300, unk0304, unk0308, unk030C, unk0310, unk0314, unk0318, unk031C;
    int unk0320, unk0324, unk0328, unk032C, unk0330, unk0334, unk0338, unk033C;
    int unk0340, unk0344, unk0348, unk034C, unk0350, unk0354, unk0358, unk035C;
    int unk0360, unk0364, unk0368, unk036C, unk0370, unk0374, unk0378, unk037C;
    int unk0380, unk0384, unk0388, unk038C, unk0390, unk0394, unk0398, unk039C;
    int unk03A0, unk03A4, unk03A8, unk03AC, unk03B0, unk03B4, unk03B8, unk03BC;
    int unk03C0, unk03C4, unk03C8, unk03CC, unk03D0, unk03D4, unk03D8, unk03DC;
    int unk03E0, unk03E4, unk03E8, unk03EC, unk03F0, unk03F4, unk03F8, unk03FC;
    int unk0400, unk0404, unk0408, unk040C, unk0410, unk0414, unk0418, unk041C;
    int unk0420, unk0424, unk0428, unk042C, unk0430, unk0434, unk0438, unk043C;
    int unk0440, unk0444, unk0448, unk044C, unk0450, unk0454, unk0458, unk045C;
    int unk0460, unk0464, unk0468, unk046C, unk0470, unk0474, unk0478, unk047C;
    int unk0480, unk0484, unk0488, unk048C, unk0490, unk0494, unk0498, unk049C;
    int unk04A0, unk04A4, unk04A8, unk04AC, unk04B0, unk04B4, unk04B8, unk04BC;
    int unk04C0, unk04C4, unk04C8, unk04CC, unk04D0, unk04D4, unk04D8, unk04DC;
    int unk04E0, unk04E4, unk04E8, unk04EC, unk04F0, unk04F4, unk04F8, unk04FC;
    int unk0500, unk0504, unk0508, unk050C, unk0510, unk0514, unk0518, unk051C;
    int unk0520, unk0524, unk0528, unk052C, unk0530, unk0534, unk0538, unk053C;
    int unk0540, unk0544, unk0548, unk054C, unk0550, unk0554, unk0558, unk055C;
    int unk0560, unk0564, unk0568, unk056C, unk0570, unk0574, unk0578, unk057C;
    int unk0580, unk0584, unk0588, unk058C, unk0590, unk0594, unk0598, unk059C;
    int unk05A0, unk05A4, unk05A8, unk05AC, unk05B0, unk05B4, unk05B8, unk05BC;
    int unk05C0, unk05C4, unk05C8, unk05CC, unk05D0, unk05D4, unk05D8, unk05DC;
    int unk05E0, unk05E4, unk05E8, unk05EC, unk05F0, unk05F4, unk05F8, unk05FC;
    int unk0600, unk0604, unk0608, unk060C, unk0610, unk0614, unk0618, unk061C;
    int unk0620, unk0624, unk0628, unk062C, unk0630, unk0634, unk0638, unk063C;
    int unk0640, unk0644, unk0648, unk064C, unk0650, unk0654, unk0658, unk065C;
    int unk0660, unk0664, unk0668, unk066C, unk0670, unk0674, unk0678, unk067C;
    int unk0680, unk0684, unk0688, unk068C, unk0690, unk0694, unk0698, unk069C;
    int unk06A0, unk06A4, unk06A8, unk06AC, unk06B0, unk06B4, unk06B8, unk06BC;
    int unk06C0, unk06C4, unk06C8, unk06CC, unk06D0, unk06D4, unk06D8, unk06DC;
    int unk06E0, unk06E4, unk06E8, unk06EC, unk06F0, unk06F4, unk06F8, unk06FC;
    int unk0700, unk0704, unk0708, unk070C, unk0710, unk0714, unk0718, unk071C;
    int unk0720, unk0724, unk0728, unk072C, unk0730, unk0734, unk0738, unk073C;
    int unk0740, unk0744, unk0748, unk074C, unk0750, unk0754, unk0758, unk075C;
    int unk0760, unk0764, unk0768, unk076C, unk0770, unk0774, unk0778, unk077C;
    int unk0780, unk0784, unk0788, unk078C, unk0790, unk0794, unk0798, unk079C;
    int unk07A0, unk07A4, unk07A8, unk07AC, unk07B0, unk07B4, unk07B8, unk07BC;
    int unk07C0, unk07C4, unk07C8, unk07CC, unk07D0, unk07D4, unk07D8, unk07DC;
    int unk07E0, unk07E4, unk07E8, unk07EC, unk07F0, unk07F4, unk07F8, unk07FC;
    int unk0800, unk0804, unk0808, unk080C, unk0810, unk0814, unk0818, unk081C;
    int unk0820, unk0824, unk0828, unk082C, unk0830, unk0834, unk0838, unk083C;
    int unk0840, unk0844, unk0848, unk084C, unk0850, unk0854, unk0858, unk085C;
    int unk0860, unk0864, unk0868, unk086C, unk0870, unk0874, unk0878, unk087C;
    int unk0880, unk0884, unk0888, unk088C, unk0890, unk0894, unk0898, unk089C;
    int unk08A0, unk08A4, unk08A8, unk08AC, unk08B0, unk08B4, unk08B8, unk08BC;
    int unk08C0, unk08C4, unk08C8, unk08CC, unk08D0, unk08D4, unk08D8, unk08DC;
    int unk08E0, unk08E4, unk08E8, unk08EC, unk08F0, unk08F4, unk08F8, unk08FC;
    int unk0900, unk0904, unk0908, unk090C, unk0910, unk0914, unk0918, unk091C;
    int unk0920, unk0924, unk0928, unk092C, unk0930, unk0934, unk0938, unk093C;
    int unk0940, unk0944, unk0948, unk094C, unk0950, unk0954, unk0958, unk095C;
    int unk0960, unk0964, unk0968, unk096C, unk0970, unk0974, unk0978, unk097C;
    int unk0980, unk0984, unk0988, unk098C, unk0990, unk0994, unk0998, unk099C;
    int unk09A0, unk09A4, unk09A8, unk09AC, unk09B0, unk09B4, unk09B8, unk09BC;
    int unk09C0, unk09C4, unk09C8, unk09CC, unk09D0, unk09D4, unk09D8, unk09DC;
    int unk09E0, unk09E4, unk09E8, unk09EC, unk09F0, unk09F4, unk09F8, unk09FC;
    int unk0A00, unk0A04, unk0A08, unk0A0C, unk0A10, unk0A14, unk0A18, unk0A1C;
    int unk0A20, unk0A24, unk0A28, unk0A2C, unk0A30, unk0A34, unk0A38, unk0A3C;
    int unk0A40, unk0A44, unk0A48, unk0A4C, unk0A50, unk0A54, unk0A58, unk0A5C;
    int unk0A60, unk0A64, unk0A68, unk0A6C, unk0A70, unk0A74, unk0A78, unk0A7C;
    int unk0A80, unk0A84, unk0A88, unk0A8C, unk0A90, unk0A94, unk0A98, unk0A9C;
    int unk0AA0, unk0AA4, unk0AA8, unk0AAC, unk0AB0, unk0AB4, unk0AB8, unk0ABC;
    int unk0AC0, unk0AC4, unk0AC8, unk0ACC, unk0AD0, unk0AD4, unk0AD8, unk0ADC;
    int unk0AE0, unk0AE4, unk0AE8, unk0AEC, unk0AF0, unk0AF4, unk0AF8, unk0AFC;
    int unk0B00, unk0B04, unk0B08, unk0B0C, unk0B10, unk0B14, unk0B18, unk0B1C;
    int unk0B20, unk0B24, unk0B28, unk0B2C, unk0B30, unk0B34, unk0B38, unk0B3C;
    int unk0B40, unk0B44, unk0B48, unk0B4C, unk0B50, unk0B54, unk0B58, unk0B5C;
    int unk0B60, unk0B64, unk0B68, unk0B6C, unk0B70, unk0B74, unk0B78, unk0B7C;
    int unk0B80, unk0B84, unk0B88, unk0B8C, unk0B90, unk0B94, unk0B98, unk0B9C;
    int unk0BA0, unk0BA4, unk0BA8, unk0BAC, unk0BB0, unk0BB4, unk0BB8, unk0BBC;
    int unk0BC0, unk0BC4, unk0BC8, unk0BCC, unk0BD0, unk0BD4, unk0BD8, unk0BDC;
    int unk0BE0, unk0BE4, unk0BE8, unk0BEC, unk0BF0, unk0BF4, unk0BF8, unk0BFC;
    int unk0C00, unk0C04, unk0C08, unk0C0C, unk0C10, unk0C14, unk0C18, unk0C1C;
    int unk0C20, unk0C24, unk0C28, unk0C2C, unk0C30, unk0C34, unk0C38, unk0C3C;
    int unk0C40, unk0C44, unk0C48, unk0C4C, unk0C50, unk0C54, unk0C58, unk0C5C;
    int unk0C60, unk0C64, unk0C68, unk0C6C, unk0C70, unk0C74, unk0C78, unk0C7C;
    int unk0C80, unk0C84, unk0C88, unk0C8C, unk0C90, unk0C94, unk0C98, unk0C9C;
    int unk0CA0, unk0CA4, unk0CA8, unk0CAC, unk0CB0, unk0CB4, unk0CB8, unk0CBC;
    int unk0CC0, unk0CC4, unk0CC8, unk0CCC, unk0CD0, unk0CD4, unk0CD8, unk0CDC;
    int unk0CE0, unk0CE4, unk0CE8, unk0CEC, unk0CF0, unk0CF4, unk0CF8, unk0CFC;
    int unk0D00, unk0D04, unk0D08, unk0D0C, unk0D10, unk0D14, unk0D18, unk0D1C;
    int unk0D20, unk0D24, unk0D28, unk0D2C, unk0D30, unk0D34, unk0D38, unk0D3C;
    int unk0D40, unk0D44, unk0D48, unk0D4C, unk0D50, unk0D54, unk0D58, unk0D5C;
    int unk0D60, unk0D64, unk0D68, unk0D6C, unk0D70, unk0D74, unk0D78, unk0D7C;
    int unk0D80, unk0D84, unk0D88, unk0D8C, unk0D90, unk0D94, unk0D98, unk0D9C;
    int unk0DA0, unk0DA4, unk0DA8, unk0DAC, unk0DB0, unk0DB4, unk0DB8, unk0DBC;
    int unk0DC0, unk0DC4, unk0DC8, unk0DCC, unk0DD0, unk0DD4, unk0DD8, unk0DDC;
    int unk0DE0, unk0DE4, unk0DE8, unk0DEC, unk0DF0, unk0DF4, unk0DF8, unk0DFC;
    int unk0E00, unk0E04, unk0E08, unk0E0C, unk0E10, unk0E14, unk0E18, unk0E1C;
    int unk0E20, unk0E24, unk0E28, unk0E2C, unk0E30, unk0E34, unk0E38, unk0E3C;
    int unk0E40, unk0E44, unk0E48, unk0E4C, unk0E50, unk0E54, unk0E58, unk0E5C;
    int unk0E60, unk0E64, unk0E68, unk0E6C, unk0E70, unk0E74, unk0E78, unk0E7C;
    int unk0E80, unk0E84, unk0E88, unk0E8C, unk0E90, unk0E94, unk0E98, unk0E9C;
    int unk0EA0, unk0EA4, unk0EA8, unk0EAC, unk0EB0, unk0EB4, unk0EB8, unk0EBC;
    int unk0EC0, unk0EC4, unk0EC8, unk0ECC, unk0ED0, unk0ED4, unk0ED8, unk0EDC;
    int unk0EE0, unk0EE4, unk0EE8, unk0EEC, unk0EF0, unk0EF4, unk0EF8, unk0EFC;
    int unk0F00, unk0F04, unk0F08, unk0F0C, unk0F10, unk0F14, unk0F18, unk0F1C;
    int unk0F20, unk0F24, unk0F28, unk0F2C, unk0F30, unk0F34, unk0F38, unk0F3C;
    int unk0F40, unk0F44, unk0F48, unk0F4C, unk0F50, unk0F54, unk0F58, unk0F5C;
    int unk0F60, unk0F64, unk0F68, unk0F6C, unk0F70, unk0F74, unk0F78, unk0F7C;
    int unk0F80, unk0F84, unk0F88, unk0F8C, unk0F90, unk0F94, unk0F98, unk0F9C;
    int unk0FA0, unk0FA4, unk0FA8, unk0FAC, unk0FB0, unk0FB4, unk0FB8, unk0FBC;
    int unk0FC0, unk0FC4, unk0FC8, unk0FCC, unk0FD0, unk0FD4, unk0FD8, unk0FDC;
    int unk0FE0, unk0FE4, unk0FE8, unk0FEC, unk0FF0, unk0FF4, unk0FF8, unk0FFC;
    int unk1000, unk1004, unk1008, unk100C, unk1010, unk1014, unk1018, unk101C;
    int unk1020, unk1024, unk1028, unk102C, unk1030, unk1034, unk1038, unk103C;
    int unk1040, unk1044, unk1048, unk104C, unk1050, unk1054, unk1058, unk105C;
    int unk1060, unk1064, unk1068, unk106C, unk1070, unk1074, unk1078, unk107C;
    int unk1080, unk1084, unk1088, unk108C, unk1090, unk1094, unk1098, unk109C;
    int unk10A0, unk10A4, unk10A8, unk10AC, unk10B0, unk10B4, unk10B8, unk10BC;
    int unk10C0, unk10C4, unk10C8, unk10CC, unk10D0, unk10D4, unk10D8, unk10DC;
    int unk10E0, unk10E4, unk10E8, unk10EC, unk10F0, unk10F4, unk10F8, unk10FC;
    int unk1100, unk1104, unk1108, unk110C, unk1110, unk1114, unk1118, unk111C;
    int unk1120, unk1124, unk1128, unk112C, unk1130, unk1134, unk1138, unk113C;
    int unk1140, unk1144, unk1148, unk114C, unk1150, unk1154, unk1158, unk115C;
    int unk1160, unk1164, unk1168, unk116C, unk1170, unk1174, unk1178, unk117C;
    int unk1180, unk1184, unk1188, unk118C, unk1190, unk1194, unk1198, unk119C;
    int unk11A0, unk11A4, unk11A8, unk11AC, unk11B0, unk11B4, unk11B8, unk11BC;
    int unk11C0, unk11C4, unk11C8, unk11CC, unk11D0, unk11D4, unk11D8, unk11DC;
    int unk11E0, unk11E4, unk11E8, unk11EC, unk11F0, unk11F4, unk11F8, unk11FC;
    int unk1200, unk1204, unk1208, unk120C, unk1210, unk1214, unk1218, unk121C;
    int unk1220, unk1224, unk1228, unk122C, unk1230, unk1234, unk1238, unk123C;
    int unk1240, unk1244, unk1248, unk124C, unk1250, unk1254, unk1258, unk125C;
    int unk1260, unk1264, unk1268, unk126C, unk1270, unk1274, unk1278, unk127C;
    int unk1280, unk1284, unk1288, unk128C, unk1290, unk1294, unk1298, unk129C;
    int unk12A0, unk12A4, unk12A8, unk12AC, unk12B0, unk12B4, unk12B8, unk12BC;
    int unk12C0, unk12C4, unk12C8, unk12CC, unk12D0, unk12D4, unk12D8, unk12DC;
    int unk12E0, unk12E4, unk12E8, unk12EC, unk12F0, unk12F4, unk12F8, unk12FC;
    int unk1300, unk1304, unk1308, unk130C, unk1310, unk1314, unk1318, unk131C;
    int unk1320, unk1324, unk1328, unk132C, unk1330, unk1334, unk1338, unk133C;
    int unk1340, unk1344, unk1348, unk134C, unk1350, unk1354, unk1358, unk135C;
    int unk1360, unk1364, unk1368, unk136C, unk1370, unk1374, unk1378, unk137C;
    int unk1380, unk1384, unk1388, unk138C, unk1390, unk1394, unk1398, unk139C;
    int unk13A0, unk13A4, unk13A8, unk13AC, unk13B0, unk13B4, unk13B8, unk13BC;
    int unk13C0, unk13C4, unk13C8, unk13CC, unk13D0, unk13D4, unk13D8, unk13DC;
    int unk13E0, unk13E4, unk13E8, unk13EC, unk13F0, unk13F4, unk13F8, unk13FC;
    int unk1400, unk1404, unk1408, unk140C, unk1410, unk1414, unk1418, unk141C;
    int unk1420, unk1424, unk1428, unk142C, unk1430, unk1434, unk1438, unk143C;
    int unk1440, unk1444, unk1448, unk144C, unk1450, unk1454, unk1458, unk145C;
    int unk1460, unk1464, unk1468, unk146C, unk1470, unk1474, unk1478, unk147C;
    int unk1480, unk1484, unk1488, unk148C, unk1490, unk1494, unk1498, unk149C;
    int unk14A0, unk14A4, unk14A8, unk14AC, unk14B0, unk14B4, unk14B8, unk14BC;
    int unk14C0, unk14C4, unk14C8, unk14CC, unk14D0, unk14D4, unk14D8, unk14DC;
    int unk14E0, unk14E4, unk14E8, unk14EC, unk14F0, unk14F4, unk14F8, unk14FC;
    int unk1500, unk1504, unk1508, unk150C, unk1510, unk1514, unk1518, unk151C;
    int unk1520, unk1524, unk1528, unk152C, unk1530, unk1534, unk1538, unk153C;
    int unk1540, unk1544, unk1548, unk154C, unk1550, unk1554, unk1558, unk155C;
    int unk1560, unk1564, unk1568, unk156C, unk1570, unk1574, unk1578, unk157C;
    int unk1580, unk1584, unk1588, unk158C, unk1590, unk1594, unk1598, unk159C;
    int unk15A0, unk15A4, unk15A8, unk15AC, unk15B0, unk15B4, unk15B8, unk15BC;
    int unk15C0, unk15C4, unk15C8, unk15CC, unk15D0, unk15D4, unk15D8, unk15DC;
    int unk15E0, unk15E4, unk15E8, unk15EC, unk15F0, unk15F4, unk15F8, unk15FC;
    int unk1600, unk1604, unk1608, unk160C, unk1610, unk1614, unk1618, unk161C;
    int unk1620, unk1624, unk1628, unk162C, unk1630, unk1634, unk1638, unk163C;
    int unk1640, unk1644, unk1648, unk164C, unk1650, unk1654, unk1658, unk165C;
    int unk1660, unk1664, unk1668, unk166C, unk1670, unk1674, unk1678, unk167C;
    int unk1680, unk1684, unk1688, unk168C, unk1690, unk1694, unk1698, unk169C;
    int unk16A0, unk16A4, unk16A8, unk16AC, unk16B0, unk16B4, unk16B8, unk16BC;
    int unk16C0, unk16C4, unk16C8, unk16CC, unk16D0, unk16D4, unk16D8, unk16DC;
    int unk16E0, unk16E4, unk16E8, unk16EC, unk16F0, unk16F4, unk16F8, unk16FC;
    int unk1700, unk1704, unk1708, unk170C, unk1710, unk1714, unk1718, unk171C;
    int unk1720, unk1724, unk1728, unk172C, unk1730, unk1734, unk1738, unk173C;
    int unk1740, unk1744, unk1748, unk174C, unk1750, unk1754, unk1758, unk175C;
    int unk1760, unk1764, unk1768, unk176C, unk1770, unk1774, unk1778, unk177C;
    int unk1780, unk1784, unk1788, unk178C, unk1790, unk1794, unk1798, unk179C;
    int unk17A0, unk17A4, unk17A8, unk17AC, unk17B0, unk17B4, unk17B8, unk17BC;
    int unk17C0, unk17C4, unk17C8, unk17CC, unk17D0, unk17D4, unk17D8, unk17DC;
    int unk17E0, unk17E4, unk17E8, unk17EC, unk17F0, unk17F4, unk17F8, unk17FC;
    int unk1800, unk1804, unk1808, unk180C, unk1810, unk1814, unk1818, unk181C;
    int unk1820, unk1824, unk1828, unk182C, unk1830, unk1834, unk1838, unk183C;
    int unk1840, unk1844, unk1848, unk184C, unk1850, unk1854, unk1858, unk185C;
    int unk1860, unk1864, unk1868, unk186C, unk1870, unk1874, unk1878, unk187C;
    int unk1880, unk1884, unk1888, unk188C, unk1890, unk1894, unk1898, unk189C;
    int unk18A0, unk18A4, unk18A8, unk18AC, unk18B0, unk18B4, unk18B8, unk18BC;
    int unk18C0, unk18C4, unk18C8, unk18CC, unk18D0, unk18D4, unk18D8, unk18DC;
    int unk18E0, unk18E4, unk18E8, unk18EC, unk18F0;
    int m_iNumJoysticks;
};

// Dispatches a key/button state query to the keyboard, mouse, other, or joystick handlers based on the device id, returning 0 for unknown devices.
// @fnv 0x00a24560
int InputManager245::FUN_00a24560(int iControlSlot, unsigned char ucKeyCode, int iState)
{
    switch (iControlSlot)
    {
    case 0xff:
        return 0;
    case 0:
        return GetKeyboardState(ucKeyCode, iState);
    case 1:
        return GetMouseState(ucKeyCode, iState);
    case 3:
        return GetOtherState(ucKeyCode, iState);
    }

    if (iControlSlot - 2 >= m_iNumJoysticks)
        return 0;

    if (ucKeyCode < 0x20)
    {
        return GetJoystickButtonState(iControlSlot - 2, ucKeyCode, iState);
    }
    else
    {
        int iPOV = GetJoystickPOV(iControlSlot - 2, ((WORD245)((((DWORD245)(ucKeyCode)) >> 16) & 0xffff)));
        int iValue = ((WORD245)(((DWORD245)(ucKeyCode)) & 0xffff));
        if (iPOV == iValue)
            return 1;
    }
    return 0;
}

struct FUN_00ec1800_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int hObject;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    bool m_bQueryPending;
    void __thiscall FUN_00ec1800();
};

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(unsigned long, unsigned long);

// @fnv 0x00ec1800
void __thiscall FUN_00ec1800_cls::FUN_00ec1800()
{
    if (hObject != 0)
    {
        m_bQueryPending = true;
        WaitForSingleObject(hObject, 0xffffffffu);
        hObject = 0;
        m_bQueryPending = false;
    }
}

class Menu
{
  public:
    virtual ~Menu();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual unsigned int GetID();
};
class SPECIALBookMenu : public Menu
{
};
class LoveTesterMenu : public Menu
{
};
class TileList
{
  public:
    void* GetHeadPos() const;
    Tile*& GetNext(void*&);
    Tile* Remove(Tile*&);
};
class Tile
{
  public:
    virtual ~Tile();
    TileList children;
    Menu* GetMenu();
};
class InterfaceManager
{
  public:
    Tile* FUN_00586150();
};
InterfaceManager* __cdecl FUN_004b7210();
extern "C" bool s_bAllowDetach;
void __cdecl FUN_007c6120();
void __cdecl FUN_007917a0();
bool __cdecl IsStartMenuFlag1Set();

// Enables detach, walks the root tile's children and removes tiles by menu ID, calling handlers for the book and love tester menus, then disables detach.
// @fnv 0x00706320
void __cdecl FUN_00706320(int)
{
    s_bAllowDetach = true;
    Tile* root = FUN_004b7210()->FUN_00586150();
    {
        void* position = root->children.GetHeadPos();
        while (position)
        {
            Tile* tile = root->children.GetNext(position);
            if (tile && tile->GetMenu())
            {
                unsigned int id = tile->GetMenu()->GetID();
                switch (id)
                {
                case 1002:
                case 1003:
                case 1004:
                case 1007:
                case 1023:
                case 1035:
                case 1061:
                    break;
                case 1060: {
                    SPECIALBookMenu* pBookMenu = tile ? dynamic_cast<SPECIALBookMenu*>(tile->GetMenu()) : 0;
                    if (pBookMenu)
                        FUN_007c6120();
                    delete root->children.Remove(tile);
                    break;
                }
                case 1074: {
                    LoveTesterMenu* pLoveMenu = tile ? dynamic_cast<LoveTesterMenu*>(tile->GetMenu()) : 0;
                    if (pLoveMenu)
                        FUN_007917a0();
                    delete root->children.Remove(tile);
                    break;
                }
                case 1013:
                    if (IsStartMenuFlag1Set())
                    {
                        delete root->children.Remove(tile);
                    }
                    break;
                default:
                    delete root->children.Remove(tile);
                    break;
                }
            }
        }
    }
    s_bAllowDetach = false;
}

struct Manager86
{
    virtual void First();
    virtual void Second();
    virtual void Stop();
};
struct Device86
{
    virtual int __stdcall QueryInterface(void*, void*);
    virtual int __stdcall AddRef();
    virtual int __stdcall Release();
    virtual int __stdcall TestCooperativeLevel();
};
struct Rect86
{
    int left;
    int top;
    int right;
    int bottom;
};
struct Point86
{
    float x;
    float y;
    float z;
    void FUN_00416870(float, float, float);
};
struct Receiver86
{
    Receiver86* FUN_00afdc60(const char*, int, int);
    Receiver86* FUN_0086c160(unsigned int, unsigned int);
    Receiver86* FUN_007005d0();

    void FUN_0066b0d0(int);
    void FUN_00b6da10(int);
    void FUN_00448420();
    void FUN_008c73a0();
    Receiver86* FUN_008d8520();
    void FUN_0086be30();
    void FUN_006c0900();
    void* FUN_0086bee0(unsigned int);
    void* FUN_0086bf10(unsigned int);
    void* FUN_0086bf40(unsigned int);
    void FUN_006eb980();
    void* FUN_00717e50();
    void FUN_005e01b0(void*);
    void FUN_0086bb20(void*);
    void FUN_0086bc10(void*);
    int FUN_00aa47c0(void*, int);

    void FUN_0086bda0();
    Receiver86* FUN_00460140();
    int* FUN_006815c0();
    void FUN_00458200(int);
    void ClearIdleAnims();
    void FUN_008a8150(int);
    void FUN_00970d50();
    void FUN_004614e0();
    void FUN_007d6bd0(int);
    void FUN_00483710();
    void FUN_004f15a0(int);
    int FUN_008d6f30();
    void FUN_004650a0(int);
    void FUN_00ec1800();
    void FUN_00456520();
    int FUN_0044ddc0();
    unsigned char FUN_00451530();
    int FUN_00559450();
    Device86* FUN_004dc020();
    void FUN_0086ba10();
    void FUN_0086ba90();
    void FUN_0086e650();
    void FUN_00ad8740();
    void FUN_00ad8700();
    void FUN_00ad7740(int);
    unsigned int FUN_0044edb0();
    Receiver86* FUN_004e2190();
    void FUN_00b63620();
    void FUN_004a4340();
    void FUN_008026b0();
    bool FUN_005dc960();
    unsigned char FUN_00678ce0();
    void FUN_008774a0(int);

    void FUN_00b012f0(const char*, const char*);
    void FUN_004a0370();
    void FUN_0086bbd0(void*, int);
    void FUN_0086bae0(void*, int);
    void FUN_004a03c0();
    void FUN_00ec16d0(const char*, int, int, int, int, float);
    void FUN_0086cf20(Receiver86*);
    int FUN_006629f0();
    void FUN_006eb8c0();
    void FUN_006c07d0();
    void FUN_008c7290();
    void FUN_0086d500();
    void FUN_0086d590();
    void FUN_00871c90(int);

    Receiver86* FUN_008526c0();
    void FUN_004fb090(void*);
    void FUN_006ecd40(int(__cdecl*)(...));
    void FUN_006ff880(int);
    void FUN_005e0200(const void*);
};
struct Setting86
{
    unsigned char* FUN_00408d60() throw();
    int* Int() throw();
    const char* FUN_00403df0() throw();
};
extern Setting86 g_011dec88, g_011dee20, g_011ded74;
struct SystemInfo86
{
    unsigned int architecture;
    void* pageSize;
    void* minAddress;
    void* maxAddress;
    unsigned int mask;
    unsigned int processors;
    unsigned int type;
    unsigned int granularity;
    unsigned short level;
    unsigned short revision;
};
struct Context86
{
    int previous;
    void FUN_00404eb0(int, bool, void*, int);
    void FUN_00404f00(int, bool, void*, int);
    void FUN_00404f70();
    void FUN_00404ee0();
};
struct Text86
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void FUN_008783c0(void*);
    void FUN_008784d0();
};
extern Setting86 g_011dee78, g_011ded2c, g_011dece4, g_011dee6c, g_011de72c, g_011d73e4;
extern Receiver86* DAT_0126fac4;
struct WindowClass86
{
    unsigned int style;
    void* procedure;
    int classExtra;
    int windowExtra;
    unsigned int instance;
    unsigned int icon;
    unsigned int cursor;
    unsigned int background;
    unsigned int menu;
    char* className;
};
struct Message86
{
    unsigned int window;
    unsigned int id;
    unsigned int wparam;
    unsigned int lparam;
    unsigned int time;
    int x;
    int y;
};
void* __cdecl operator new(unsigned int);
extern Receiver86* g_dataHandler;
extern Receiver86* g_TESSaveLoadGame;
extern Receiver86* g_BGSSaveLoadGame;
extern Receiver86 g_011deb30;
extern Setting86 g_011deed8;
extern Receiver86 g_011ded3c, g_011dec64, g_011deb38;
extern Receiver86* g_modelLoader;
typedef int(__cdecl* code)(...);

int __cdecl FUN_00408d60(...);
int __cdecl FUN_0086a580(...);
int __cdecl FUN_00c3bd30(...);
int __cdecl FUN_00c3bb90(...);
int __cdecl FUN_00c3bbe0(...);
int __cdecl FUN_00c3bc30(...);
int __cdecl FUN_00c3bc80(...);
int __cdecl FUN_00876ad0(...);
int __cdecl FUN_004b4a30(...);
Receiver86* __cdecl FUN_00af2640();
int __cdecl FUN_004fb090(...);
int __cdecl FUN_0086a020(...);
int __cdecl FUN_008526c0(...);
int __cdecl FUN_006ecd40(...);
int __cdecl FUN_00aa20b0(...);
int __cdecl FUN_00c5d4e0(...);
int __cdecl FUN_004b7920(...);
int __cdecl FUN_00a1c6f0(...);
int __cdecl FUN_00bc2940(...);
int __cdecl FUN_0045b020(...);
int __cdecl FUN_00404f30(...);
int __cdecl FUN_0086bde0(...);
int __cdecl FUN_0086a050(...);
int __cdecl FUN_0086bcd0(...);
int __cdecl FUN_0086bcc0(...);
int __cdecl FUN_00c3a6d0(...);
int __cdecl FUN_00404eb0(...);
int __cdecl FUN_00453720(...);
int __cdecl FUN_00404f70(...);

int __cdecl FUN_00a61ad0(...);
int __cdecl FUN_006ff610(...);
int __cdecl FUN_00ecc071(...);
Receiver86* __cdecl FUN_006ff580();
int __cdecl FUN_006ff880(...);
Receiver86* __cdecl FUN_00877950(...);
int __cdecl FUN_005e0200(...);
Receiver86* __cdecl FUN_0044f560(...);
int __cdecl FUN_004dc110(...);
int __cdecl FUN_00406d30(...);
int __cdecl FUN_00406d50(...);
Receiver86* __cdecl FUN_004de490(...);
Receiver86* __cdecl FUN_0045d180(...);
unsigned char __cdecl FUN_004da570();
int __cdecl FUN_004da4d0(...);
Manager86* __cdecl FUN_00b00a00();
int __cdecl FUN_00876a70(...);
int __cdecl FUN_00404ee0(...);
int __cdecl FUN_00403df0(...);
Receiver86* __cdecl FUN_00aff100();
int __cdecl FUN_00b012f0(...);

int __cdecl FUN_0086bce0(...);
int __cdecl FUN_0040fbe0(...);
int __cdecl FUN_0086bda0(...);
int __cdecl FUN_00876d20(...);

int __cdecl FUN_0086d500(...);
Receiver86* __cdecl FUN_0043c4b0();
int __cdecl FUN_004a0370(...);
int __cdecl SUB_005d4a40(...);
int __cdecl FUN_0086bbd0(...);
int __cdecl FUN_0086bae0(...);
int __cdecl FUN_0086d590(...);
int __cdecl FUN_00702250(...);
int __cdecl FUN_006519f0(...);
int __cdecl FUN_00871c90(...);
int __cdecl FUN_006a2920(...);
int __cdecl FUN_0086c010(...);
int __cdecl FUN_004a03c0(...);
int __cdecl FUN_00866ff0(...);
int __cdecl FUN_00ec16d0(...);
int __cdecl FUN_0086cf20(...);
int __cdecl FUN_006629f0(...);
int __cdecl FUN_0086be90(...);
int __cdecl FUN_0086be80(...);
Receiver86* __cdecl FUN_00713d80();
int __cdecl FUN_008c7290(...);
int __cdecl FUN_006d0870(...);
Receiver86* __cdecl GetPathManager();
int __cdecl FUN_006eb8c0(...);
Receiver86* __cdecl GetNavMeshObstacleManager();
int __cdecl FUN_006c07d0(...);
int __cdecl FUN_004e0540(...);
int __cdecl FUN_004deb30(...);
int __cdecl FUN_00416870(...);
int __cdecl FUN_00460140(...);
int __cdecl FUN_006815c0(...);
int __cdecl FUN_00458200(...);
int __cdecl ClearIdleAnims(...);
int __cdecl FUN_008a8150(...);
int __cdecl FUN_00970d50(...);
int __cdecl FUN_004614e0(...);
int __cdecl FUN_007d6bd0(...);
int __cdecl FUN_00876dd0(...);
int __cdecl FUN_00877260(...);
int __cdecl FUN_007022c0(...);
int __cdecl FUN_00483710(...);
int __cdecl FUN_004f15a0(...);
int __cdecl FUN_00af4540(...);
int __cdecl FUN_008d6f30(...);
int __cdecl FUN_004650a0(...);
int __cdecl FUN_007053f0(...);
int __cdecl FUN_00ec1800(...);
int __cdecl FUN_00456520(...);
int __cdecl FUN_00403d30(...);
int __cdecl FUN_0044ddc0(...);
int __cdecl FUN_00451530(...);
int __cdecl FUN_00559450(...);
int __cdecl FUN_004dc020(...);
int __cdecl FUN_0086ba10(...);
int __cdecl FUN_0086ba90(...);
int __cdecl FUN_0086e650(...);
Receiver86* __cdecl FUN_00453a70();
int __cdecl FUN_00ad8740(...);
int __cdecl FUN_00830660(...);
int __cdecl FUN_00832ad0(...);
int __cdecl FUN_00ad7740(...);
unsigned char __cdecl FUN_00446e10();
int __cdecl FUN_0078d020(...);
int __cdecl FUN_0044edb0(...);
int __cdecl FUN_0078cfc0(...);
int __cdecl FUN_00ad8700(...);
int __cdecl FUN_00830640(...);
int __cdecl FUN_004e2190(...);
int __cdecl FUN_00b63620(...);
Receiver86* __cdecl FUN_0049fef0();
int __cdecl FUN_004a4340(...);
Receiver86* __cdecl FUN_00705910();
int __cdecl FUN_008026b0(...);
int __cdecl FUN_005dc960(...);
int __cdecl FUN_00678ce0(...);
int __cdecl FUN_008774a0(...);
int __cdecl FUN_006ff620(...);
int __cdecl FUN_00703610(...);
int __cdecl FUN_00706320(...);
Receiver86* __cdecl FUN_004a0ea0();
int __cdecl FUN_00b6da10(...);
int __cdecl FUN_0066b0d0(...);
int __cdecl FUN_0086bea0(...);
int __cdecl FUN_00683a60(...);
int __cdecl FUN_00a819e0(...);
int __cdecl FUN_00448420(...);
int __cdecl FUN_008c73a0(...);
int __cdecl FUN_00867090(...);
int __cdecl FUN_004dc560(...);
int __cdecl FUN_004dc590(...);
int __cdecl FUN_00702330(...);
int __cdecl FUN_008d8520(...);
int __cdecl FUN_0086be30(...);
int __cdecl FUN_004e0800(...);
int __cdecl FUN_004def20(...);
int __cdecl FUN_007ffe00(...);
int __cdecl FUN_00832010(...);
int __cdecl FUN_008304a0(...);
int __cdecl FUN_0082f9c0(...);
int __cdecl FUN_0049ff80(...);
int __cdecl FUN_00622bc0(...);
int __cdecl FUN_00626f10(...);
int __cdecl FUN_006c0900(...);
int __cdecl FUN_0086bee0(...);
int __cdecl FUN_006eb980(...);
int __cdecl FUN_00651ab0(...);
int __cdecl FUN_00990ff0(...);
int __cdecl FUN_00664940(...);
int __cdecl FUN_00526eb0(...);
int __cdecl FUN_00408de0(...);
int __cdecl FUN_0086bf10(...);
int __cdecl FUN_0086bf40(...);
int __cdecl FUN_00717e50(...);
int __cdecl FUN_005e01b0(...);
int __cdecl FUN_0086bb20(...);
int __cdecl FUN_0086bc10(...);
int __cdecl FUN_006a29a0(...);
int __cdecl FUN_00a62090(...);
int __cdecl FUN_00bc2960(...);
int __cdecl FUN_0086bd00(...);
int __cdecl FUN_0045b050(...);
int __cdecl FUN_00c5d520(...);
int __cdecl FUN_004b8cf0(...);
int __cdecl FUN_00a1c790(...);
int __cdecl FUN_00aa2170(...);
int __cdecl FUN_008783c0(...);
Receiver86* __cdecl FUN_00401020();
int __cdecl FUN_00aa47c0(...);
int __cdecl FUN_008784d0(...);

extern unsigned int _DAT_011c16bc;
extern char str_01082ab8[];
extern char str_01082a7c[];
extern char str_0104df38[];
extern unsigned char UNK_01082a38;
extern unsigned char UNK_01082a28;
extern unsigned char UNK_01082a10;
extern unsigned char UNK_01082a00;
extern char* _DAT_011a2fe8;
extern unsigned char UNK_00869f30;
extern unsigned char UNK_00b4dfb0;
extern unsigned char UNK_010829c4;
extern unsigned char UNK_010829b4;
extern unsigned char UNK_01082990;
extern char* _DAT_011a2ff0;
extern char* _DAT_011a2ff8;
extern unsigned char UNK_01082978;
extern unsigned char UNK_0105bb14;
extern unsigned char UNK_0086a0a0;
extern unsigned char* _DAT_011dea0c;
extern unsigned int _DAT_011d8804;
extern unsigned char UNK_0108295c;
extern unsigned char DAT_011f4509;
extern unsigned char UNK_00872570;
extern float _DAT_01018bfc;
extern float _DAT_0101e704;
extern unsigned int _DAT_011c3f2c;
extern unsigned char UNK_0108293c;
extern unsigned char UNK_01082924;
extern unsigned char UNK_01082910;
extern unsigned int _DAT_011dea3c;
extern unsigned int _DAT_01202d98;
extern unsigned char UNK_010828fc;
extern unsigned int _DAT_011dea10;
extern unsigned char UNK_010828ec;
extern char str_01082a48[];

__declspec(dllimport) unsigned int __stdcall CreateMutexA(int, int, const void*);
__declspec(dllimport) unsigned int __stdcall GetLastError();
__declspec(dllimport) int __stdcall MessageBoxA(int, const void*, const void*, int);
__declspec(dllimport) int __stdcall GetSystemMetrics(int);
__declspec(dllimport) void __stdcall GetSystemInfo(void*);
__declspec(dllimport) int __stdcall FindWindowA(const char*, int);
__declspec(dllimport) int __stdcall GetCommandLineW();
__declspec(dllimport) int __stdcall CommandLineToArgvW(int, int*);
__declspec(dllimport) int __stdcall LocalFree(void*);
__declspec(dllimport) int __stdcall ShellExecuteA(int, int, const void*, int, int, int);
__declspec(dllimport) int __stdcall LoadIconA(int, int);
__declspec(dllimport) int __stdcall GetStockObject(int);
__declspec(dllimport) int __stdcall RegisterClassA(void*);
__declspec(dllimport) int __stdcall AdjustWindowRect(void*, int, int);
__declspec(dllimport) int __stdcall CreateWindowExA(int, const char*, const char*, int, int, int, int, int, int, int,
                                                    int, int);
__declspec(dllimport) int __stdcall PeekMessageA(void*, int, int, int, int);
__declspec(dllimport) int __stdcall TranslateMessage(void*);
__declspec(dllimport) int __stdcall DispatchMessageA(void*);

__declspec(dllimport) void __stdcall Sleep(int);
__declspec(dllimport) int __stdcall GetWindowLongA(int, int);
__declspec(dllimport) int __stdcall AdjustWindowRectEx(void*, int, int, int);
__declspec(dllimport) int __stdcall SetWindowPos(int, int, int, int, int, int, int);
__declspec(dllimport) int __stdcall GetCurrentThreadId();
__declspec(dllimport) int __stdcall SetForegroundWindow(int);

// Creates the game window and subsystems, runs the message/render loop until exit, then tears everything down and returns 0.
// @fnv 0x0086a850
int __stdcall FUN_0086a850(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4)

{
    Rect86 inactiveRect3;
    unsigned int inactiveStyle3;
    Rect86 activeRect5;
    unsigned int activeStyle1;
    int deviceStatus13;
    char launchPath0[260];
    int shellResult10;
    unsigned short* option6;
    int argumentIndex33;
    int argumentCount8;
    unsigned short** arguments5;
    unsigned char enableMemory0;
    Point86 position25;
    SystemInfo86 systemInfo7;
    unsigned int startupState3;
    WindowClass86 windowClass10;
    Message86 message0;
    Context86 memoryContext11;
    Text86 shutdownText46;
    int gameWindow3;
    char path2[260];
    unsigned int window1;
    unsigned int mutex17;
    Rect86 windowRect0;
    unsigned char paused1;
    unsigned int startupFlags3;
    int existingWindow30;

    mutex17 = CreateMutexA(0, 0, &str_01082ab8);
    if (GetLastError() == 0xb7)
    {
        MessageBoxA(0, &str_01082a7c, &str_0104df38, 0);
        return 0;
    }
    if (GetSystemMetrics(0x1000))
    {
        MessageBoxA(0, &str_01082a48, &str_0104df38, 0);
        return 0;
    }
    {
        {
            enableMemory0 = 0;
            enableMemory0 = 1;
            FUN_00c3bd30(enableMemory0, *g_011dec88.FUN_00408d60(), *g_011dee20.FUN_00408d60(),
                         *g_011ded74.FUN_00408d60(), FUN_0086a580);
            FUN_00c3bb90(&UNK_01082a38);
            FUN_00c3bbe0(&UNK_01082a28);
            FUN_00c3bc30(&UNK_01082a10);
            FUN_00c3bc80(&UNK_01082a00);
            GetSystemInfo(&systemInfo7);
            *g_011c3ea4.Int() = systemInfo7.processors;
            FUN_00876ad0(path2);
            if (*g_011c3ea4.Int() == 1)
            {
                *g_011c3ea4.Int() = 2;
            }
            existingWindow30 = FindWindowA(_DAT_011a2fe8, 0);
            if (existingWindow30 != 0)
            {
                SetForegroundWindow(existingWindow30);
                return 0;
            }
            {
                int result5;
                Receiver86* globalsToDelete3;
                Receiver86* globalsDeleteTarget3;
                Receiver86* interfaceToDelete85;
                Receiver86* interfaceDeleteTarget24;
                Receiver86* tesToDelete37;
                Receiver86* tesDeleteTarget23;
                Receiver86* interfaceAllocation2;
                Receiver86* newInterface17;
                Receiver86* globalsAllocation7;
                Receiver86* newGlobals20;
                Receiver86* fileAllocation4;
                Receiver86* fileSystem2;
                int shellExitResult20;
                FUN_004b4a30(_DAT_011a2fe8);
                FUN_00af2640()->FUN_004fb090(&UNK_00869f30);
                FUN_00af2640()->FUN_008526c0()->FUN_006ecd40(FUN_0086a020);
                FUN_00aa20b0(0);
                FUN_00c5d4e0();
                FUN_004b7920();
                FUN_00a1c6f0();
                FUN_00bc2940();
                FUN_0045b020();
                FUN_00404f30(0x3b);
                FUN_0086bde0(FUN_0086a050);
                FUN_0086bcd0(&UNK_00b4dfb0);
                FUN_0086bcc0(1);
                FUN_00c3a6d0();
                FUN_0086bd70();
                memoryContext11.FUN_00404eb0(0x10, 1, &UNK_010829c4, 0x8e0);
                FUN_00453720();
                memoryContext11.FUN_00404f70();
                memoryContext11.FUN_00404f00(0xf, 1, &UNK_010829c4, 0x8e6);
                FUN_00a61ad0();
                memoryContext11.FUN_00404f70();
                FUN_006ff610();
                argumentCount8 = 0;
                arguments5 = (unsigned short**)CommandLineToArgvW(GetCommandLineW(), &argumentCount8);
                if (arguments5 != 0)
                {
                    for (argumentIndex33 = 0; argumentIndex33 < argumentCount8; argumentIndex33 = argumentIndex33 + 1)
                    {
                        if ((arguments5[argumentIndex33] != 0) && (*arguments5[argumentIndex33] == 0x2d))
                        {
                            option6 = arguments5[argumentIndex33] + 1;
                            if (FUN_00ecc071(option6, &UNK_010829b4) == 0)
                            {
                                FUN_006ff580()->FUN_006ff880(0);
                            }
                        }
                    }
                    LocalFree(arguments5);
                }
                FUN_00877950()->FUN_005e0200(&UNK_01082990);
                FUN_0044f560()->FUN_005e0200(path2);
                FUN_00406d30(path2, 0x104, FUN_004dc110());
                FUN_00406d50(path2, 0x104, _DAT_011a2ff0);
                FUN_004de490()->FUN_005e0200(path2);
                FUN_00406d30(path2, 0x104, FUN_004dc110());
                FUN_00406d50(path2, 0x104, _DAT_011a2ff8);
                FUN_0045d180()->FUN_005e0200(path2);
                FUN_004de490()->FUN_005e0200(path2);
                if (*g_011c3ea4.Int() == 1)
                {
                    *g_011c3ea4.Int() = 2;
                }
                if (FUN_004da570())
                {
                    FUN_004da4d0(1);
                    FUN_00b00a00()->Stop();
                    FUN_00876a70(launchPath0, 0x104);
                    FUN_00406d50(launchPath0, 0x104, &UNK_01082978);
                    shellResult10 = ShellExecuteA(0, 0, launchPath0, 0, 0, 1);
                    if (shellResult10 != 0)
                    {
                        shellExitResult20 = 0;
                        memoryContext11.FUN_00404ee0();
                        return shellExitResult20;
                    }
                }
                FUN_00aff100()->FUN_00b012f0(g_011dee78.FUN_00403df0(), g_011ded2c.FUN_00403df0());
                fileAllocation4 = (Receiver86*)operator new(16);
                fileSystem2 = fileAllocation4
                                  ? fileAllocation4->FUN_00afdc60(g_011dece4.FUN_00403df0(), *g_011dee6c.Int(), 0)
                                  : 0;
                FUN_0086bce0(&UNK_0105bb14);
                FUN_00c3bd30(enableMemory0, *g_011dec88.FUN_00408d60(), *g_011dee20.FUN_00408d60(),
                             *g_011ded74.FUN_00408d60(), FUN_0086a580);
                FUN_00c3bb90(&UNK_01082a38);
                FUN_00c3bbe0(&UNK_01082a28);
                FUN_00c3bc30(&UNK_01082a10);
                FUN_00c3bc80(&UNK_01082a00);
                memoryContext11.FUN_00404f00(0x18, 1, &UNK_010829c4, 0x992);
                FUN_0040fbe0();
                FUN_00aff100()->FUN_0086bda0();
                memoryContext11.FUN_00404f70();
                memoryContext11.FUN_00404f00(0x13, 1, &UNK_010829c4, 0x99c);
                FUN_00876d20();
                memoryContext11.FUN_00404f70();
                windowClass10.style = 3;
                windowClass10.procedure = &UNK_0086a0a0;
                windowClass10.classExtra = 0;
                windowClass10.windowExtra = 0;
                windowClass10.instance = param_1;
                windowClass10.icon = LoadIconA(param_1, 0x65);
                windowClass10.cursor = 0;
                windowClass10.background = GetStockObject(4);
                windowClass10.className = _DAT_011a2fe8;
                windowClass10.menu = 0;
                RegisterClassA(&windowClass10);
                windowRect0.left = 0;
                windowRect0.top = 0;
                windowRect0.right = 0x140;
                windowRect0.bottom = 0xf0;
                AdjustWindowRect(&windowRect0, 0x10000000, 0);
                window1 = CreateWindowExA(0, _DAT_011a2fe8, _DAT_011a2fe8, 0x10000000, 0, 0,
                                          windowRect0.right - windowRect0.left, windowRect0.bottom - windowRect0.top, 0,
                                          0, param_1, 0);
                globalsAllocation7 = (Receiver86*)operator new(0xa4);
                newGlobals20 = globalsAllocation7 ? globalsAllocation7->FUN_0086c160(window1, param_1) : 0;
                _DAT_011dea0c = (unsigned char*)newGlobals20;
                memoryContext11.FUN_00404f00(0xd, 1, &UNK_010829c4, 0x9f8);
                interfaceAllocation2 = (Receiver86*)operator new(8);
                newInterface17 = interfaceAllocation2 ? interfaceAllocation2->FUN_007005d0() : 0;
                _DAT_011d8804 = (unsigned int)newInterface17;
                memoryContext11.FUN_00404f70();
                FUN_0040fbe0(&UNK_0108295c);
                ((Receiver86*)_DAT_011dea0c)->FUN_0086d500();
                DAT_011f4509 = 1;
                FUN_0043c4b0()->FUN_004a0370();
                FUN_0043c4b0()->FUN_0086bbd0(&SUB_005d4a40, 0);
                FUN_0043c4b0()->FUN_0086bae0(&UNK_00872570, 0);
                FUN_0086bf70();
                ((Receiver86*)_DAT_011dea0c)->FUN_0086d590();
                FUN_00702250(1);
                FUN_006519f0();
                ((Receiver86*)_DAT_011dea0c)->FUN_00871c90(1);
                FUN_006a2920();
                FUN_0086c010();
                FUN_0043c4b0()->FUN_004a03c0();
                FUN_00866ff0();
                DAT_0126fac4->FUN_00ec16d0(g_011de72c.FUN_00403df0(), 0, -1, 1, 1, 0.0f);
                memoryContext11.FUN_00404f70();
                ((Receiver86*)_DAT_011dea0c)->FUN_0086cf20((Receiver86*)FUN_0045c670());
                FUN_0086be90(((Receiver86*)FUN_0045c670())->FUN_006629f0());
                FUN_0086be80(((Receiver86*)FUN_0045c670())->FUN_006629f0());
                if (*g_011c3ea4.Int() > 1)
                {
                    FUN_00713d80()->FUN_008c7290();
                }
                FUN_006d0870();
                GetPathManager()->FUN_006eb8c0();
                if (*g_011d73e4.FUN_00408d60())
                {
                    GetNavMeshObstacleManager()->FUN_006c07d0();
                }
                FUN_004e0540();
                FUN_004deb30();
                startupState3 = 0;
                startupFlags3 = 0;
                position25.FUN_00416870(_DAT_01018bfc, _DAT_01018bfc, _DAT_0101e704);
                ((Receiver86*)_DAT_011dea10)->FUN_00458200(*g_dataHandler->FUN_00460140()->FUN_006815c0());
                ((Receiver86*)_DAT_011dea3c)->ClearIdleAnims();
                g_TESSaveLoadGame->FUN_008a8150(1);
                FUN_0040fbe0(&UNK_0108293c);
                ((Receiver86*)&DAT_011e0e80)->FUN_00970d50();
                g_dataHandler->FUN_004614e0();
                g_BGSSaveLoadGame->FUN_007d6bd0(1);
                FUN_0040fbe0(&UNK_01082924);
                FUN_00876dd0(startupFlags3, &position25);
                FUN_0040fbe0(&UNK_01082910);
                FUN_00877260(position25);
                FUN_007022c0();
                ((Receiver86*)_DAT_011dea3c)->FUN_00483710();
                ((Receiver86*)_DAT_011dea0c)->FUN_004f15a0(1);
                FUN_00af4540();
                if (!((Receiver86*)_DAT_011dea3c)->FUN_008d6f30())
                {
                    g_dataHandler->FUN_004650a0(-1);
                    FUN_0040fbe0();
                    FUN_007053f0();
                    DAT_0126fac4->FUN_00ec1800();
                    FUN_0040fbe0();
                }
                else
                {
                    DAT_0126fac4->FUN_00ec1800();
                }
                ((Receiver86*)_DAT_01202d98)->FUN_00456520();
                FUN_0040fbe0(&UNK_010828fc);
                FUN_00403d30(&message0, 0, 0x1c);
                gameWindow3 = ((Receiver86*)_DAT_011dea0c)->FUN_0044ddc0();
                paused1 = '\0';
                while (true)
                {
                    while (PeekMessageA(&message0, 0, 0, 0, 1))
                    {
                        TranslateMessage(&message0);
                        DispatchMessageA(&message0);
                    }
                    if ((int)GetForegroundWindow() == gameWindow3 || ((Receiver86*)_DAT_011dea10)->FUN_00451530() ||
                        g_011deb30.FUN_00559450() || *g_011deed8.FUN_00408d60())
                    {
                        deviceStatus13 = FUN_0043c4b0()->FUN_004dc020()->TestCooperativeLevel();
                        if (deviceStatus13 < 0)
                        {
                            FUN_0043c4b0()->FUN_0086ba10();
                            FUN_0043c4b0()->FUN_0086ba90();
                            Sleep(0x32);
                        }
                        else
                        {
                            ((Receiver86*)_DAT_011dea0c)->FUN_0086e650();
                        }
                        if (paused1 != '\0')
                        {
                            paused1 = '\0';
                            FUN_00453a70()->FUN_00ad8740();
                            FUN_00830660();
                            FUN_00832ad0(0);
                            FUN_00453a70()->FUN_00ad7740(1);
                            if (FUN_00446e10())
                            {
                                activeRect5.left = 0;
                                activeRect5.top = 0;
                                activeRect5.right = FUN_004dc1f0();
                                activeRect5.bottom = FUN_004dc200();
                                activeStyle1 = 0;
                                activeStyle1 = GetWindowLongA(window1, 0xfffffff0);
                                AdjustWindowRectEx(&activeRect5, activeStyle1, 0, 0);
                                SetWindowPos(window1, 0, activeRect5.left, activeRect5.bottom,
                                             activeRect5.right - activeRect5.left, activeRect5.top - activeRect5.bottom,
                                             0);
                            }
                        }
                        if (((paused1 == '\0') && (*_DAT_011dea0c != '\0')) && (deviceStatus13 >= 0))
                        {
                            FUN_0078d020();
                            *_DAT_011dea0c = '\0';
                        }
                    }
                    else
                    {
                        if (paused1 == '\0')
                        {
                            paused1 = '\x01';
                            if (!(unsigned char)FUN_0086bdf0())
                            {
                                if (GetCurrentThreadId() == ((Receiver86*)_DAT_011dea0c)->FUN_0044edb0())
                                {
                                    FUN_0078cfc0();
                                    *_DAT_011dea0c = '\x01';
                                }
                            }
                            FUN_00453a70()->FUN_00ad8700();
                            FUN_00830640();
                            FUN_00832ad0(0);
                            FUN_00453a70()->FUN_00ad7740(1);
                            ((Receiver86*)_DAT_011dea0c)->FUN_004e2190()->FUN_00b63620();
                            FUN_0049fef0()->FUN_004a4340();
                            FUN_00705910()->FUN_008026b0();
                            if (FUN_00446e10())
                            {
                                inactiveRect3.left = 0;
                                inactiveRect3.top = 0;
                                inactiveRect3.right = FUN_004dc1f0();
                                inactiveRect3.bottom = FUN_004dc200();
                                inactiveStyle3 = 0;
                                inactiveStyle3 = GetWindowLongA(window1, 0xfffffff0);
                                AdjustWindowRectEx(&inactiveRect3, inactiveStyle3, 0, 0);
                                SetWindowPos(window1, 0, inactiveRect3.left, inactiveRect3.bottom,
                                             inactiveRect3.right - inactiveRect3.left,
                                             inactiveRect3.top - inactiveRect3.bottom, 0);
                            }
                        }
                        Sleep(0x32);
                    }
                    if (((Receiver86*)_DAT_011dea0c)->FUN_005dc960())
                        break;
                    if (((Receiver86*)_DAT_011dea0c)->FUN_00678ce0())
                    {
                        ((Receiver86*)_DAT_011dea0c)->FUN_008774a0(1);
                    }
                }
                ((Receiver86*)_DAT_011dea0c)->FUN_004f15a0(0);
                FUN_006ff620();
                FUN_00703610();
                FUN_00706320(0);
                if (g_011ded3c.FUN_00559450())
                {
                    FUN_004a0ea0()->FUN_00b6da10(g_011ded3c.FUN_00559450());
                    g_011ded3c.FUN_0066b0d0(0);
                }
                if (g_011dec64.FUN_00559450())
                {
                    FUN_004a0ea0()->FUN_00b6da10(g_011dec64.FUN_00559450());
                    g_011dec64.FUN_0066b0d0(0);
                }
                if (g_011deb38.FUN_00559450())
                {
                    FUN_004a0ea0()->FUN_00b6da10(g_011deb38.FUN_00559450());
                    g_011deb38.FUN_0066b0d0(0);
                }
                FUN_0086bea0(0);
                if (FUN_00683a60())
                {
                    FUN_00a819e0();
                }
                g_modelLoader->FUN_00448420();
                if (*g_011c3ea4.Int() > 1)
                {
                    FUN_00713d80()->FUN_008c73a0();
                }
                FUN_00867090();
                FUN_004dc560();
                FUN_004dc590();
                FUN_00702330();
                if (((Receiver86*)_DAT_011dea10)->FUN_008d8520())
                {
                    ((Receiver86*)_DAT_011dea10)->FUN_008d8520()->FUN_0086be30();
                }
                FUN_004e0800();
                FUN_004def20();
                FUN_007ffe00();
                FUN_00832010();
                FUN_008304a0();
                FUN_0082f9c0();
                ((Manager86*)FUN_00453a70())->Stop();
                FUN_0040fbe0();
                FUN_0049ff80();
                FUN_00622bc0();
                FUN_00626f10();
                if (*g_011d73e4.FUN_00408d60())
                {
                    GetNavMeshObstacleManager()->FUN_006c0900();
                }
                tesToDelete37 = (Receiver86*)_DAT_011dea10;
                tesDeleteTarget23 = tesToDelete37;
                tesDeleteTarget23 ? tesDeleteTarget23->FUN_0086bee0(1) : 0;
                FUN_0086beb0();
                GetPathManager()->FUN_006eb980();
                FUN_00651ab0();
                FUN_00990ff0();
                ((Manager86*)FUN_00b00a00())->Stop();
                FUN_00664940();
                FUN_00526eb0();
                FUN_00408de0();
                FUN_0086bdd0();
                interfaceToDelete85 = (Receiver86*)_DAT_011d8804;
                interfaceDeleteTarget24 = interfaceToDelete85;
                interfaceDeleteTarget24 ? interfaceDeleteTarget24->FUN_0086bf10(1) : 0;
                globalsToDelete3 = (Receiver86*)_DAT_011dea0c;
                globalsDeleteTarget3 = globalsToDelete3;
                globalsDeleteTarget3 ? globalsDeleteTarget3->FUN_0086bf40(1) : 0;
                _DAT_011dea0c = (unsigned char*)0x0;
                ((Manager86*)FUN_00aff100())->Stop();
                FUN_004de490()->FUN_005e01b0(FUN_004de490()->FUN_00717e50());
                FUN_0043c4b0()->FUN_0086bb20(&UNK_00872570);
                FUN_0043c4b0()->FUN_0086bc10(&SUB_005d4a40);
                FUN_006a29a0();
                FUN_00a62090();
                FUN_00bc2960();
                FUN_004da4d0(1);
                FUN_0086bd00();
                FUN_0045b050();
                FUN_00c5d520();
                FUN_004b8cf0();
                FUN_00a1c790();
                FUN_00aa2170();
                shutdownText46.FUN_008783c0(&UNK_010828ec);
                FUN_00401020()->FUN_00aa47c0(&shutdownText46, 0);
                result5 = 0;
                shutdownText46.FUN_008784d0();
                memoryContext11.FUN_00404ee0();
                return result5;
            }
        }
    }
}

extern void* DAT_01082acc;

struct FUN_0086ba10_virtual
{
    virtual bool unk00();
    virtual bool unk01();
    virtual bool unk02();
    virtual bool unk03();
    virtual bool unk04();
    virtual bool unk05();
    virtual bool unk06();
    virtual bool unk07();
    virtual bool unk08();
    virtual bool unk09();
    virtual bool unk0a();
    virtual bool unk0b();
    virtual bool unk0c();
    virtual bool unk0d();
    virtual bool unk0e();
    virtual bool unk0f();
    virtual bool unk10();
    virtual bool unk11();
    virtual bool unk12();
    virtual bool unk13();
    virtual bool unk14();
    virtual bool unk15();
    virtual bool unk16();
    virtual bool unk17();
    virtual bool unk18();
    virtual bool unk19();
    virtual bool unk1a();
    virtual bool unk1b();
    virtual bool unk1c();
    virtual bool unk1d();
    virtual bool unk1e();
    virtual bool unk1f();
    virtual bool unk20();
    virtual bool unk21();
    virtual bool unk22();
    virtual bool unk23();
    virtual bool unk24();
    virtual bool unk25();
    virtual bool unk26();
    virtual bool unk27();
    virtual bool unk28();
    virtual bool unk29();
    virtual bool unk2a();
    virtual bool unk2b();
    virtual bool unk2c();
    virtual bool unk2d();
    virtual bool unk2e();
    virtual bool unk2f();
    virtual bool unk30();
    virtual bool unk31();
    virtual bool unk32();
    virtual bool unk33();
    virtual bool unk34();
    virtual bool unk35();
    virtual bool unk36();
    virtual bool unk37();
    virtual bool unk38();
    virtual bool unk39();
    virtual bool unk3a();
    virtual bool unk3b();
    virtual bool unk3c();
    virtual bool unk3d();
    virtual bool unk3e();
    virtual bool unk3f();
    virtual bool unk40();
    virtual bool unk41();
    virtual bool unk42();
    virtual bool unk43();
    virtual bool unk44();
    virtual bool unk45();
    virtual bool unk46();
    virtual bool unk47();
    virtual bool unk48();
    virtual bool unk49();
    virtual bool unk4a();
    virtual bool unk4b();
    virtual bool unk4c();
    virtual bool unk4d();
    virtual bool unk4e();
    virtual bool unk4f();
    virtual bool unk50();
    virtual bool unk51();
    virtual bool unk52();
    virtual bool unk53();
    virtual bool unk54();
    virtual bool unk55();
    virtual bool unk56();
    virtual bool unk57();
    virtual bool unk58();
    virtual bool unk59();
    virtual bool unk5a();
    virtual bool unk5b();
    virtual bool unk5c();
    virtual bool unk5d();
    virtual bool unk5e();
    virtual bool unk5f();
};

struct FUN_0086ba10_fields
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
};

struct FUN_0086ba10_target
{
    bool FUN_0086ba10();
};

// Calls FUN_0086ba60 with DAT_01082acc and 0, then unk5f; on success sets unk200 to 2 and returns true.
// @fnv 0x0086ba10
bool FUN_0086ba10_target::FUN_0086ba10()
{
    if (!reinterpret_cast<FUN_0086ba60_Class*>(this)->FUN_0086ba60(&DAT_01082acc, 0))
        return false;

    if (!reinterpret_cast<FUN_0086ba10_virtual*>(this)->unk5f())
        return false;

    reinterpret_cast<FUN_0086ba10_fields*>(this)->unk200 = 2;
    return true;
}

extern FUN_0086bd40_class* DAT_011f81dc;

// If the global object pointer DAT_011f81dc is non-null, calls its FUN_0086bd40 method with 1.
// @fnv 0x0086bd00
void __cdecl FUN_0086bd00(void)
{
    if (DAT_011f81dc)
    {
        FUN_0086bd40_class* pObject = DAT_011f81dc;
        FUN_0086bd40_class* pThis = pObject;

        {
            void* pResult;
            if (pThis)
            {
                pResult = pThis->FUN_0086bd40(1);
            }
            else
            {
                pResult = 0;
            }
        }
    }
}

struct MemScope
{
    int context;
    MemScope(int, bool, const char*, int);
    ~MemScope();
    void Enter(int, bool, const char*, int);
    void Leave();
};
struct UpdateInfo
{
    float time;
    int flags;
    int unk08;
    UpdateInfo(float, bool, bool);
};
struct ScenePart
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual ScenePart* AsNode();
    ScenePart* Child(unsigned int);
    void Link();
    void Reset();
    void Update(UpdateInfo&);
};
struct SkyInit
{
    static SkyInit* GetInstance();
    ScenePart* Attach(ScenePart*);
};
extern SkyInit* DAT_011dea20;
extern int DAT_011dea1c;
void FUN_00877730();
int FUN_0086d470();
ScenePart* FUN_007a1480();
void LogInit(const char*, ...);
struct WorldInit
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
    WorldInit(const char*, int, ScenePart*, SkyInit*, int);
    void Start();
    void LoadTerrain();
    void LoadLandscape();
    void Extra();
    void Finish();
};
extern WorldInit* worldInstance;
void CreateTrees(bool);
struct TaskInit
{
    void Activate();
};
TaskInit& GetTasks();
void FUN_00526e10();
void FUN_00990f20();
struct InitSetting
{
    const char* String();
    int Value();
    int* Int();
    bool* Bool();
};
extern InitSetting g_011debf0;
extern InitSetting g_011deb88;
extern InitSetting g_011decf8;
extern InitSetting g_011dee9c;
extern InitSetting g_011dec34;
extern InitSetting g_011dee0c;
extern InitSetting g_011ded14;
extern InitSetting g_011dee48;
extern InitSetting g_011dea70;
extern InitSetting g_011ded48;
extern InitSetting g_011c7adc;
extern InitSetting g_011dee60;
struct FileInit
{
    void Enable(bool);
    const char* Filename();
};
struct HandlerInit
{
    FileInit* Find(const char*);
    void Load(bool);
    void Scripts();
};
extern HandlerInit* handlerInstance;
extern int DAT_011a2ffc;
int* FUN_0086d480();
const char* PrepareScriptMessage(const char*, bool);
extern "C" unsigned int __cdecl strlen(const char*);
struct PointInit
{
    float x, y, z;
    PointInit(float, float, float);
};
struct ValueInit
{
    virtual void v0();
    virtual void v4();
    virtual int Get(int);
};
struct PlayerInit
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void Refresh();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void SetID(unsigned int, bool);
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void SetAngles(const PointInit&);
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
    ValueInit values;
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
    int unke48;
    int unke4c;
    PlayerInit();
    void SetBase(void*);
    void Position(const PointInit&);
    void Enable(bool);
};
extern PlayerInit* playerInstance;
void FUN_005f5880();
void FUN_0068b3e0();

class TESNPC : public TESForm
{
};
TESForm* LookupForm(unsigned int);
extern PointInit zeroPoint;
struct TimeInit
{
    void Set(int);
};
extern TimeInit timeInstance;
struct BootInit
{
    bool LoadPlugins(int*, int);
    void FUN_0086cf20(ScenePart*);
};
// Initializes the game world, plugins, player, terrain, and scripts in sequence, logging each stage.
// @fnv 0x0086cf20
void BootInit::FUN_0086cf20(ScenePart* scene)
{
    MemScope memory5(10, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 0xe4f);
    memory5.Enter(10, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 0xe51);
    DAT_011dea20 = SkyInit::GetInstance();
    FUN_00877730();
    int mode = FUN_0086d470();
    ScenePart* root_2 = FUN_007a1480();
    if (root_2)
    {
        DAT_011dea20->Attach(root_2)->Link();
        ScenePart* child4 = root_2->Child(0);
        root_2 = child4 ? child4->AsNode() : 0;
    }
    LogInit("Initializing TES...");
    worldInstance = new WorldInit("DATA\\", mode, root_2, DAT_011dea20, DAT_011dea1c);
    memory5.Leave();
    worldInstance->Start();
    LogInit("Initializing TreeManager...");
    CreateTrees(false);
    LogInit("Activating Tasklet Threads...");
    GetTasks().Activate();
    FUN_00526e10();
    FUN_00990f20();
    memory5.Enter(25, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 0xe85);
    scene->Reset();
    UpdateInfo update9(0.0f, false, false);
    scene->Update(update9);
    memory5.Leave();
    bool found3 = false;
    InitSetting* plugins3[10] = {&g_011debf0, &g_011deb88, &g_011decf8, &g_011dee9c, &g_011dec34,
                                 &g_011dee0c, &g_011ded14, &g_011dee48, &g_011dea70, &g_011ded48};
    for (int index2 = 0; index2 < 10; ++index2)
    {
        if (plugins3[index2]->String() && strlen(plugins3[index2]->String()))
        {
            FileInit* aFile = handlerInstance->Find(PrepareScriptMessage(plugins3[index2]->String(), false));
            if (aFile)
            {
                aFile->Enable(true);
                found3 = true;
            }
        }
    }
    if (LoadPlugins(FUN_0086d480(), DAT_011a2ffc))
        found3 = true;
    if (!found3)
    {
        FileInit* _fallback = handlerInstance->Find("Fallout.esm");
        if (_fallback)
            _fallback->Enable(true);
    }
    memory5.Enter(52, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 0xecb);
    playerInstance = new PlayerInit;
    playerInstance->SetID(20, true);
    memory5.Leave();
    LogInit("Loading Files...");
    handlerInstance->Load(false);
    FUN_005f5880();
    worldInstance->LoadTerrain();
    worldInstance->LoadLandscape();
    if (*g_011c7adc.Bool())
        worldInstance->Extra();
    worldInstance->Finish();
    FUN_0068b3e0();
    LogInit("Initializing Player...");
    memory5.Enter(52, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 0xf00);
    {
        TESNPC* base2 = dynamic_cast<TESNPC*>(LookupForm(7));
        playerInstance->SetBase(base2);
        playerInstance->SetAngles(PointInit(2048.0f, 2048.0f, 0.0f));
        playerInstance->Position(zeroPoint);
        playerInstance->Refresh();
        playerInstance->Enable(false);
        int healthB = playerInstance->values.Get(16);
        if (!healthB)
            LogInit("ERROR: Health value is 0 on the Player. Fix '%s' with the editor.",
                    reinterpret_cast<FileInit*>(base2->GetFile(0))->Filename());
    }
    LogInit("Initializing Scripts...");
    handlerInstance->Scripts();
    if (g_011dee60.Value() > 0 && g_011dee60.Value() < 200)
        timeInstance.Set(*g_011dee60.Int());
}

extern "C" __declspec(dllimport) short __stdcall GetAsyncKeyState(int);
namespace FrameUpdate {
struct Service;
struct Values
{
    virtual void v0();
    virtual void v4();
    virtual int Get(int);
};
struct Service
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void Update();
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
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void Advance(float);
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void* Position();
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
    Values values;
    void FUN_006ff860();
    bool FUN_00701450(bool);
    void FUN_00851d90();
    void FUN_00c3dbf0();
    void FUN_00457d70(int, int, int);
    void FUN_00b6dd00(Service*, bool);
    void FUN_007011d0(bool);
    bool FUN_00451530();
    bool FUN_0086ef70();
    void FUN_004556d0(int);
    Service* FUN_00559450();
    float FUN_0084d030();
    void FUN_00867a40(float);
    int* FUN_0043d4d0();
    void FUN_00455640();
    void Lock(int);
    void FUN_00978550();
    void FUN_009777a0();
    void FUN_0096eb40();
    void FUN_0096e9b0();
    void FUN_008d0600(float, int);
    void Unlock();
    void FUN_00878080(bool);
    void FUN_0049fff0();
    void FUN_00712e60(void*);
    int FUN_0044ddc0();
    float FUN_00710ab0();
    void SetCameraFOV(float, int, int, bool);
    void* FUN_006629f0();
    void FUN_0045bc80(bool, bool);
    void FUN_00b5ac90(void*);
    void FUN_0045b070(void*);
    void FUN_008c78c0();
    void FUN_008ca070();
    void FUN_006ebc50();
    void FUN_006a61b0();
    bool* FUN_00408d60();
    void FUN_006c3640();
    void FUN_00991500(bool);
    void FUN_008c7990();
    void FUN_008ca300();
    bool FUN_00950090();
    signed char FUN_00424940();
    void* FUN_008d6f30();
};
Service* __cdecl FUN_00af2640();
bool __cdecl FUN_00702360();
bool __cdecl FUN_00709bc0();
bool __cdecl FUN_007050d0();
bool __cdecl FUN_00703d50();
void* __cdecl FUN_00707ad0();
void* __cdecl FUN_00705990();
Service* __cdecl FUN_004b7210();
Service* __cdecl FUN_006ff580();
bool __cdecl FUN_0086efa0();
bool __cdecl FUN_0070edf0();
bool __cdecl FUN_00705ea0();
Service* __cdecl FUN_00524c90();
Service* __cdecl FUN_004a0ea0();
int __cdecl FUN_00683a60();
Service* __cdecl FUN_00446ef0();
bool __cdecl FUN_0086ef60();
Service* __cdecl FUN_0049fef0();
Service* __cdecl FUN_0045c670();
Service* __cdecl FUN_00713d80();
Service* __cdecl GetPathManager();
Service* __cdecl FUN_00552ba0();
Service* __cdecl GetNavMeshObstacleManager();
bool __cdecl FUN_00714a00();
int __cdecl FUN_007023c0();
bool __cdecl FUN_007056f0();
bool __cdecl FUN_0070ed10();
void __cdecl FUN_008782b0();
void __cdecl FUN_0086ef30();
void __cdecl FUN_0086ef90();
void __cdecl FUN_004e1610();
void __cdecl FUN_0086ef40();
void __cdecl FUN_0078cfc0();
void __cdecl FUN_004e0110();
void __cdecl FUN_004de600();
void __cdecl FUN_00a81a20();
void __cdecl FUN_00a81a80();
void __cdecl FUN_00a61cd0();
void __cdecl FUN_00868850();
void __cdecl FUN_00868d10();
void __cdecl FUN_007058e0();
void __cdecl FUN_0057ab70();
void __cdecl FUN_00b60040();
void __cdecl RecreateRenderDevice();
void __cdecl FUN_00703e10();
void __cdecl FUN_00a29680();
void __cdecl FUN_005ae270();
void __cdecl FUN_005a9d60();
float __cdecl FUN_006da7c0(void*, void*, int, int);
void __cdecl FUN_006652e0(Service*, bool);
void __cdecl FUN_00b54000(float);
Service* __cdecl FUN_00450b80(int);
void __cdecl FUN_008c80e0(bool);
int __cdecl FUN_0047e040(float);
void __cdecl FUN_0070ed20(int);
void __cdecl FUN_00aa7290(unsigned int);
extern Service* DAT_011d8804;
extern Service* DAT_011dea3c;
extern Service* DAT_011de134;
extern Service* DAT_01202d98;
extern Service* DAT_011dea10;
extern Service* DAT_011f1958;
extern Service DAT_011deb7c;
extern Service DAT_011f6394;
extern Service DAT_011de7b8;
extern Service DAT_011c3ea4;
extern Service DAT_011f11a0;
extern Service DAT_011e0e80;
extern Service DAT_011f2250;
extern Service DAT_011e0fe0;
extern Service DAT_011d73e4;
extern bool DAT_011dea2b;
extern bool DAT_011dea2c;
extern bool DAT_011dea2d;
extern bool DAT_011dea2e;
extern bool DAT_011deefc;
extern bool DAT_011c6fbb;
extern unsigned char DAT_011deef5;
extern float DAT_011a3010, DAT_011deef8;
extern int DAT_011a2fe0, DAT_011df674;
extern char DAT_011ad840;
struct MainLoop
{
    int unk00;
    char unk04, unk05, unk06;
    bool paused;
    void FUN_0086f940();
    void FUN_0086f190();
    void FUN_00483710();
    void FUN_0086f260();
    void FUN_0086f390();
    void FUN_0086efe0();
    void FUN_0086f450();
    void FUN_0086fbe0();
    void FUN_0086fd70();
    void FUN_0086fc60();
    void FUN_00871dc0();
    void FUN_0086ff70();
    void FUN_008705d0();
    void FUN_0086f6a0();
    void FUN_00870610();
    void FUN_0086a830(float);
    void FUN_0086fd90(bool);
    void FUN_0086e650();
};
// @fnv 0x0086e650
void MainLoop::FUN_0086e650()
{
    FUN_0086a830(DAT_011a3010);
    short key4;
    key4 = GetAsyncKeyState(9);
    if ((key4 >> 15) & 1)
    {
        key4 = GetAsyncKeyState(18);
        if ((key4 >> 15) & 1)
            return;
    }
    FUN_00af2640()->Update();
    DAT_011dea2b = FUN_00702360() || FUN_00709bc0();
    DAT_011dea2c = FUN_007050d0();
    DAT_011dea2d = DAT_011d8804->FUN_00701450(true);
    DAT_011dea2e = FUN_00703d50();
    bool differentMenu = FUN_00707ad0() && FUN_00707ad0() != FUN_00705990();
    if (FUN_004b7210()->FUN_00424940() == 3 && !differentMenu)
        FUN_008782b0();
    FUN_0086f940();
    FUN_006ff580()->FUN_006ff860();
    FUN_0086fd90(!DAT_011dea2b && !paused);
    DAT_011dea2b = FUN_00702360() || FUN_00709bc0();
    DAT_011dea2c = FUN_007050d0();
    DAT_011dea2d = DAT_011d8804->FUN_00701450(true);
    DAT_011dea2e = FUN_00703d50();
    if (DAT_011deefc)
        FUN_006da7c0(DAT_011dea3c->FUN_008d6f30(), DAT_011dea3c->Position(), 2, 100);
    DAT_011de134->FUN_00851d90();
    FUN_0086ef30();
    FUN_0086ef90();
    FUN_0086f190();
    FUN_00483710();
    FUN_004e1610();
    ++DAT_011a2fe0;
    DAT_011df674 = 0;
    if (!DAT_011dea2b)
        FUN_0086ef40();
    FUN_0086f260();
    FUN_0086f390();
    DAT_01202d98->FUN_00c3dbf0();
    if (!FUN_0086efa0())
    {
        if (FUN_0070edf0())
            FUN_0078cfc0();
        else if (FUN_00705ea0())
            DAT_011dea10->FUN_00457d70(0, 0, 0);
    }
    FUN_0086efe0();
    FUN_004a0ea0()->FUN_00b6dd00(FUN_00524c90(), DAT_011dea2b);
    FUN_0086f450();
    DAT_011d8804->FUN_007011d0(true);
    if (!DAT_011dea2b && !paused)
    {
        FUN_004e0110();
        FUN_004de600();
    }
    if (FUN_00683a60())
        FUN_00a81a20();
    if (!DAT_011dea2b && !paused)
    {
        if (DAT_011dea10->FUN_00451530() && !DAT_011dea10->FUN_0086ef70())
            DAT_011dea10->FUN_004556d0(0);
        DAT_011deb7c.FUN_00559450()->Advance(DAT_011f6394.FUN_0084d030());
        DAT_011de7b8.FUN_00867a40(DAT_011f6394.FUN_0084d030());
        if (*DAT_011c3ea4.FUN_0043d4d0() == 1)
            DAT_011dea10->FUN_00455640();
    }
    DAT_011f11a0.Lock(0);
    DAT_011e0e80.FUN_00978550();
    if (*DAT_011c3ea4.FUN_0043d4d0() != 1)
    {
        if ((!DAT_011dea2b || DAT_011dea2d) && !DAT_011dea2e && !paused)
        {
            DAT_011e0e80.FUN_009777a0();
            DAT_011e0e80.FUN_0096eb40();
            DAT_011e0e80.FUN_0096e9b0();
        }
    }
    else
    {
        if ((!DAT_011dea2b || DAT_011dea2d) && !DAT_011dea2e && !paused)
        {
            DAT_011e0e80.FUN_009777a0();
            DAT_011e0e80.FUN_008d0600(0.0f, 0);
            DAT_011e0e80.FUN_0096eb40();
            DAT_011e0e80.FUN_0096e9b0();
        }
    }
    DAT_011f11a0.Unlock();
    FUN_00446ef0()->FUN_00878080(true);
    if (FUN_0086ef60())
        FUN_00a61cd0();
    FUN_00868850();
    FUN_00868d10();
    FUN_006652e0(FUN_00524c90(), DAT_011dea2b || paused);
    FUN_0086fbe0();
    if (*DAT_011c3ea4.FUN_0043d4d0() == 1)
        FUN_0086fd70();
    FUN_00483710();
    FUN_0049fef0()->FUN_0049fff0();
    FUN_00524c90()->FUN_00712e60(&DAT_011ad840);
    if (DAT_011f2250.FUN_0044ddc0() != 4)
        FUN_0045c670()->SetCameraFOV(DAT_011dea3c->FUN_00710ab0(), 0, 0, true);
    FUN_00b54000(DAT_011dea3c->FUN_00710ab0());
    void* sceneB = DAT_011deb7c.FUN_00559450()->FUN_006629f0();
    void* replacement5 = 0;
    DAT_011dea10->FUN_0045bc80(true, true);
    FUN_00450b80(0)->FUN_00b5ac90(replacement5 ? replacement5 : sceneB);
    DAT_011dea10->FUN_0045b070(replacement5 ? replacement5 : sceneB);
    bool update = (!DAT_011dea2b || DAT_011dea2d) && !DAT_011dea2e && !paused;
    if (update)
    {
        if (*DAT_011c3ea4.FUN_0043d4d0() > 1)
        {
            FUN_008c80e0(true);
            FUN_00713d80()->FUN_008c78c0();
        }
        else
            DAT_011e0fe0.FUN_008ca070();
    }
    FUN_0086fc60();
    if (*DAT_011c3ea4.FUN_0043d4d0() > 1 && !update)
    {
        FUN_0086fd70();
        if (FUN_00702360())
            FUN_007058e0();
    }
    if (!paused)
        GetPathManager()->FUN_006ebc50();
    FUN_00552ba0()->FUN_006a61b0();
    if (*DAT_011c3ea4.FUN_0043d4d0() == 1)
    {
        if (*DAT_011d73e4.FUN_00408d60())
            GetNavMeshObstacleManager()->FUN_006c3640();
        DAT_011f1958->FUN_00991500(DAT_011dea2b || DAT_011dea2d || paused);
    }
    if (FUN_00714a00())
        FUN_00a81a80();
    if (FUN_007023c0() == 0x3f4 && FUN_007056f0())
        FUN_00871dc0();
    FUN_0057ab70();
    FUN_00b60040();
    int mode4 = FUN_0047e040((float)DAT_011dea3c->values.Get(23));
    if (mode4 > 2)
    {
        if (mode4 == 3)
            mode4 = 0;
        else
            mode4 = 2;
    }
    FUN_0086ff70();
    FUN_008705d0();
    if (DAT_011c6fbb)
    {
        RecreateRenderDevice();
        DAT_011c6fbb = false;
    }
    if ((!DAT_011dea2b || DAT_011dea2d) && !DAT_011dea2e && !paused)
    {
        if (*DAT_011c3ea4.FUN_0043d4d0() > 1)
            FUN_00713d80()->FUN_008c7990();
        else
            DAT_011e0fe0.FUN_008ca300();
    }
    FUN_0086f6a0();
    FUN_00870610();
    if (FUN_0070ed10())
    {
        FUN_0070ed20(0);
        FUN_00703e10();
    }
    FUN_00a29680();
    FUN_005ae270();
    FUN_005a9d60();
    DAT_011deef8 += DAT_011f6394.FUN_0084d030();
    if (FUN_00702360() || (DAT_011dea3c && DAT_011dea3c->FUN_00950090()) || DAT_011deef8 >= 45.0)
    {
        DAT_011deef8 = 0.0f;
        FUN_00aa7290(DAT_011deef5++);
        if (DAT_011deef5 == 256)
            DAT_011deef5 = 0;
    }
}
}

namespace fnv_008707c0 {
typedef ImageSpaceManager ISMgr;
struct Rend;
struct RootNode;
struct AnimData;
struct StrObj
{
    operator const char*() const;
};

struct MTHelper
{
    void FUN_00ba30f0(int a, int b);
    void FUN_00ba3130(int a, int b);
};
MTHelper* __cdecl FUN_004ea970();

struct RMenu
{
    RootNode* FUN_007fa950();
};
RMenu* __cdecl FUN_00707ad0();
Rend* __cdecl FUN_0043c4b0();
bool __cdecl FUN_004dc310();
bool __cdecl FUN_00705a00();
unsigned char __cdecl FUN_008709f0();
void __cdecl FUN_008c80e0(int);

struct FNode
{
    void FUN_004a0fd0(const char* s);
    void FUN_0041fd00(AnimData* a);
};
struct FGen
{
    FNode* FUN_008d80e0();
};
AnimData* __cdecl FUN_00524c90();
struct SSN
{
    void FUN_00b5e870(FNode* n);
};
SSN* __cdecl FUN_00450b80(int);

struct RenderMgr
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
    StrObj name;

    void FUN_00872ad0();
    void FUN_00871290();
    int FUN_00872f50(Rend* r, int p1, bool p2, bool b);
    void FUN_00874b90(ISMgr* m, Rend* r, bool b, int p1);
    void FUN_00874c10();
    void FUN_00875110(Rend* r, RootNode* root, int z, int res);
    void FUN_00875bf0();
    void FUN_00875fd0(bool b, int res, Rend* r, int p1);
    void FUN_008761e0(RootNode* root, Rend* r);
    void FUN_00876830(bool b, int p1);
    void FUN_00876850(int res, ISMgr* m, Rend* r, int z);

    void FUN_008707c0(int p1, bool p2);
};

// Runs the render update: resets helpers, computes a result via FUN_00872f50, sets up a node when FUN_00705a00 is true, and dispatches the remaining render steps.
// @fnv 0x008707c0
void RenderMgr::FUN_008707c0(int p1, bool p2)
{
    ISMgr* ism2 = FUN_004e3270();
    Rend* renderer = FUN_0043c4b0();
    bool flag_ = FUN_004dc310();
    RootNode* root2 = FUN_00707ad0() ? FUN_00707ad0()->FUN_007fa950() : 0;
    FUN_00872ad0();
    for (int i4 = 1; i4 < 0x11; i4++)
    {
        FUN_004ea970()->FUN_00ba30f0(0, i4);
        FUN_004ea970()->FUN_00ba3130(1, i4);
    }
    FUN_00871290();
    int res4 = FUN_00872f50(renderer, p1, p2, flag_);
    FUN_00874b90(ism2, renderer, flag_, p1);
    if (*g_011c3ea4.Int() > 1)
        FUN_008c80e0(0);
    FUN_004ea970()->FUN_00ba30f0(0, 0x15);
    FUN_004ea970()->FUN_00ba3130(1, 0x15);
    if (FUN_00705a00())
    {
        AnimData* anim3 = FUN_00524c90();
        FGen* fg7 = (FGen*)FUN_0045c670();
        FNode* pNode = fg7->FUN_008d80e0();
        pNode->FUN_004a0fd0(name);
        pNode->FUN_0041fd00(anim3);
        FUN_00450b80(0)->FUN_00b5e870(pNode);
        FUN_00874c10();
        FUN_00875110(renderer, root2, 0, res4);
    }
    else
    {
        FUN_004ea970()->FUN_00ba30f0(0, 0x16);
        FUN_004ea970()->FUN_00ba3130(1, 0x16);
    }
    FUN_00875bf0();
    if (FUN_008709f0() && !p2)
    {
        FUN_00875fd0(flag_, res4, renderer, p1);
        if (root2)
            FUN_008761e0(root2, renderer);
    }
    else if (p1)
    {
        FUN_00876830(flag_, p1);
    }
    FUN_00876850(res4, ism2, renderer, 0);
}
}  // namespace fnv_008707c0

struct RendererStub870;
struct ISManagerStub870;
struct RTexStub870;
struct TexStub870;

struct AVObjStub870
{
    bool FUN_00456610();
};
struct PlayerStub870
{
    AVObjStub870* GetNode(bool firstPerson);
};

struct MenuStub870
{
    void* GetMenuRoot();
};
struct RenderSysStub870
{
    void EnableA(int a, int b);
    void EnableB(int a, int b);
};

RendererStub870* GetRenderer870();
ISManagerStub870* GetISManager870();
bool IsFlag870();
void SetupState870(int a, int b);
MenuStub870* GetMenu870();
bool MenuCheck870();
RenderSysStub870* GetRenderSys870();
void SetState870(int a);

struct SceneRendererStub870
{
    void Prepare1();
    TexStub870* GetTexture();
    void Prepare2();
    bool CheckX();
    void Prepare3();
    RTexStub870* RenderMain(RendererStub870* renderer, TexStub870* target, int unk, bool flag);
    void ShaderPassEntry(TexStub870* tex, bool draw, bool unk, bool x);
    void Finish1();
    void FUN_00874b50(RTexStub870* rt, bool flag, unsigned int unk);
    void Composite(RendererStub870* renderer, int unk, TexStub870* tex, RTexStub870* rt);
    void CopyTarget(bool flag, TexStub870* target);
    void RenderAlt(bool flag, RTexStub870* rt, RendererStub870* renderer, TexStub870* target);
    void RenderImageSpace(RTexStub870* rt, ISManagerStub870* ism, RendererStub870* renderer, int unk);

    void FUN_00870a00(TexStub870* target, bool skip);
};

// @fnv 0x00870a00
void SceneRendererStub870::FUN_00870a00(TexStub870* target, bool skip)
{
    RendererStub870* renderer2 = GetRenderer870();
    ISManagerStub870* ism = GetISManager870();
    TexStub870* tex2 = 0;
    bool nodeFlag4 = ((PlayerStub870*)g_thePlayer)->GetNode(true)->FUN_00456610();
    bool flagVal = IsFlag870();
    SetupState870(1, 1);
    Prepare1();
    tex2 = GetTexture();
    Prepare2();
    bool checkXA = CheckX();
    Prepare3();
    RTexStub870* rt4 = RenderMain(renderer2, target, 0, flagVal);
    bool draw2 = !nodeFlag4 && !skip && !GetMenu870()->GetMenuRoot() && !MenuCheck870();
    ShaderPassEntry(tex2, draw2, true, checkXA);
    if (draw2)
    {
        Finish1();
        FUN_00874b50(rt4, flagVal, 0);
        Composite(renderer2, 0, tex2, rt4);
    }
    else
    {
        GetRenderSys870()->EnableA(0, 0x16);
        GetRenderSys870()->EnableB(1, 0x16);
    }
    if (target)
        CopyTarget(flagVal, target);
    SetState870(1);
    if (FUN_008709f0())
    {
        RenderAlt(flagVal, rt4, renderer2, target);
    }
    else if (target)
    {
        CopyTarget(flagVal, target);
    }
    RenderImageSpace(rt4, ism, renderer2, 0);
}

struct ShadowActor;
struct ShadowNode;
struct ShadowView;
struct ShadowMap;
struct ShadowVector
{
    float x, y, z;
};
struct ShadowBound
{
    float x, y, z, radius;
    float FUN_0084d030();
};
struct ShadowUpdate
{
    float time;
    int flags, frame;
    ShadowUpdate(float, bool, bool);
};
struct ShadowExtra
{
    const ShadowVector& FUN_00500940();
};
struct ShadowTransform
{
    void* FUN_0045bbe0();
};
struct ShadowNode
{
    int FUN_009611e0();
    ShadowExtra* FUN_00a5bdd0(int);
    ShadowBound* FUN_0043d450();
    bool FUN_00456610();
    void FUN_00450f90(bool);
    const ShadowVector& FUN_0045bb80();
    void FUN_00a59c60(ShadowUpdate*);
};
struct ShadowView
{
    void FUN_0041fd00(ShadowTransform*);
    void FUN_00a694a0(void*);
};
struct ShadowScene
{
    ShadowView* FUN_008d80e0();
    ShadowTransform* FUN_006629f0();
};
struct ShadowMap
{
    ShadowNode* FUN_004e6540();
    ShadowNode* FUN_005bf820();
    bool FUN_004e6580();
    void FUN_00b9bb10(float, bool);
    void UpdateOutputLight(int, ShadowVector);
    void FUN_00b9e970(ShadowView*);
    unsigned short FUN_004e6560();
    float GetFirstLightParameter();
    void UpdateShadow(ShadowView*, int);
    void FUN_00b9fba0();
    void FUN_00ba0110(ShadowNode*);
    void FUN_00ba02b0();
};
struct ShadowSystem
{
    void FUN_00b5b1f0();
    void FUN_00b5b060();
    void FUN_00b5c3c0();
    void* FUN_00b5cbd0(ShadowNode*);
    void FUN_00b5cde0(void*);
    ShadowMap* FUN_00b5afc0();
    ShadowMap* FUN_00b5b010();
    void* FUN_00454b30();
    void FUN_00b5d300(ShadowMap*);
    void FUN_00b5b880(ShadowView*);
};
struct ShadowRenderer
{
    void ResizeActivePool();
};
struct ShadowTarget
{
    void FUN_00ba30f0();
    void FUN_00ba3130();
};
struct ShadowEnvironment
{
    int FUN_005f36f0();
};
struct ShadowIntSetting
{
    int* FUN_0043d4d0();
};
struct ShadowBoolSetting
{
    bool* FUN_00408d60();
};
struct ShadowLock
{
    void Lock(int);
    void Unlock();
};
struct ShadowActors
{
    ShadowActor** FUN_00871a30();
    int FUN_00472380();
};
extern ShadowEnvironment* DAT_011dea10;
extern ShadowActor* DAT_011dea3c;
extern ShadowIntSetting DAT_011c72d8, DAT_011c72e4;
extern ShadowBoolSetting DAT_011c71dc, DAT_011c7664;
extern ShadowLock DAT_011f1180;
extern const ShadowVector DAT_011f426c;
extern bool DAT_011def08;
const double DAT_01021928 = 3.0;
const double DAT_01082cb0 = 0.05;
bool FUN_005bf7b0();
bool FUN_00525420();
void FUN_005bf770(bool);
bool FUN_00871a10();
void FUN_00b4f570();
ShadowSystem* FUN_00450b80(int);
void* __stdcall FUN_0043c4b0(int);
ShadowRenderer* __stdcall FUN_004a0ea0(void*);
int FUN_0050ea90();
float FUN_00404010(float, float);
ShadowNode* FUN_0054f4c0();
void FUN_004e20b0(bool);
ShadowTarget* __stdcall FUN_004ea970(int, int);
struct ShadowActor
{
    virtual void Slot0();
    virtual void Slot4();
    virtual void Slot8();
    virtual void SlotC();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1C();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2C();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3C();
    virtual void Slot40();
    virtual void Slot44();
    virtual void Slot48();
    virtual void Slot4C();
    virtual void Slot50();
    virtual void Slot54();
    virtual void Slot58();
    virtual void Slot5C();
    virtual void Slot60();
    virtual void Slot64();
    virtual void Slot68();
    virtual void Slot6C();
    virtual void Slot70();
    virtual void Slot74();
    virtual void Slot78();
    virtual void Slot7C();
    virtual void Slot80();
    virtual void Slot84();
    virtual void Slot88();
    virtual void Slot8C();
    virtual void Slot90();
    virtual void Slot94();
    virtual void Slot98();
    virtual void Slot9C();
    virtual void SlotA0();
    virtual void SlotA4();
    virtual void SlotA8();
    virtual void SlotAC();
    virtual void SlotB0();
    virtual void SlotB4();
    virtual void SlotB8();
    virtual void SlotBC();
    virtual void SlotC0();
    virtual void SlotC4();
    virtual void SlotC8();
    virtual void SlotCC();
    virtual void SlotD0();
    virtual void SlotD4();
    virtual void SlotD8();
    virtual void SlotDC();
    virtual void SlotE0();
    virtual void SlotE4();
    virtual void SlotE8();
    virtual void SlotEC();
    virtual void SlotF0();
    virtual void SlotF4();
    virtual void SlotF8();
    virtual void SlotFC();
    virtual void Slot100();
    virtual void Slot104();
    virtual void Slot108();
    virtual void Slot10C();
    virtual void Slot110();
    virtual void Slot114();
    virtual void Slot118();
    virtual void Slot11C();
    virtual void Slot120();
    virtual void Slot124();
    virtual void Slot128();
    virtual void Slot12C();
    virtual void Slot130();
    virtual void Slot134();
    virtual void Slot138();
    virtual void Slot13C();
    virtual void Slot140();
    virtual void Slot144();
    virtual void Slot148();
    virtual void Slot14C();
    virtual void Slot150();
    virtual void Slot154();
    virtual void Slot158();
    virtual void Slot15C();
    virtual void Slot160();
    virtual void Slot164();
    virtual void Slot168();
    virtual void Slot16C();
    virtual void Slot170();
    virtual void Slot174();
    virtual void Slot178();
    virtual void Slot17C();
    virtual void Slot180();
    virtual void Slot184();
    virtual void Slot188();
    virtual void Slot18C();
    virtual void Slot190();
    virtual void Slot194();
    virtual void Slot198();
    virtual void Slot19C();
    virtual void Slot1A0();
    virtual void Slot1A4();
    virtual void Slot1A8();
    virtual void Slot1AC();
    virtual void Slot1B0();
    virtual void Slot1B4();
    virtual void Slot1B8();
    virtual void Slot1BC();
    virtual void Slot1C0();
    virtual void Slot1C4();
    virtual void Slot1C8();
    virtual void Slot1CC();
    virtual ShadowNode* Get3D();
    virtual void Slot1D4();
    virtual void Slot1D8();
    virtual void Slot1DC();
    virtual void Slot1E0();
    virtual void Slot1E4();
    virtual void Slot1E8();
    virtual void Slot1EC();
    virtual void Slot1F0();
    virtual void Slot1F4();
    virtual void Slot1F8();
    virtual void Slot1FC();
    virtual void Slot200();
    virtual void Slot204();
    virtual void Slot208();
    virtual void Slot20C();
    virtual void Slot210();
    virtual int GetState();
    bool FUN_004eaf60();
    bool FUN_00950090();
    bool FUN_008c51c0();
    ShadowNode* FUN_00950bb0(int);
    bool FUN_0087f200();
};
struct ShadowHost
{
    void FUN_00871290();
    void FUN_00871a50();
};
// Toggles shadow rendering based on two flags, builds the shadow map from actors, renders visible shadow maps up to a limit, and resets unused shadow targets.
// @fnv 0x00871290
void ShadowHost::FUN_00871290()
{
    if (FUN_005bf7b0() && FUN_00525420())
    {
        DAT_011def08 = FUN_005bf7b0();
        FUN_005bf770(false);
        ShadowSystem* system = FUN_00450b80(0);
        system->FUN_00b5b1f0();
        FUN_004a0ea0(FUN_0043c4b0(0))->ResizeActivePool();
    }
    else if (DAT_011def08 && !FUN_00525420())
    {
        DAT_011def08 = false;
        FUN_005bf770(true);
        int limit = DAT_011dea10->FUN_005f36f0() ? *DAT_011c72d8.FUN_0043d4d0() : *DAT_011c72e4.FUN_0043d4d0();
        FUN_004a0ea0(FUN_0043c4b0(limit))->ResizeActivePool();
    }
    if (FUN_005bf7b0() && FUN_00871a10())
    {
        FUN_00b4f570();
        ShadowSystem* system = FUN_00450b80(0);
        system->FUN_00b5b060();
        int limit = DAT_011dea10->FUN_005f36f0() ? *DAT_011c72d8.FUN_0043d4d0() : *DAT_011c72e4.FUN_0043d4d0();
        FUN_004a0ea0(FUN_0043c4b0(limit))->ResizeActivePool();
        if (!limit)
            system->FUN_00b5c3c0();
        else
        {
            void* playerShadow32 = 0;
            int count33 = 0;
            if ((DAT_011dea3c->FUN_004eaf60() || DAT_011dea3c->FUN_00950090()) && !DAT_011dea3c->FUN_008c51c0())
            {
                playerShadow32 = system->FUN_00b5cbd0(DAT_011dea3c->FUN_00950bb0(0));
                ++count33;
            }
            DAT_011f1180.Lock(0);
            ShadowActor** actors8 = ((ShadowActors*)&DAT_011e0e80)->FUN_00871a30();
            int actorCount72 = ((ShadowActors*)&DAT_011e0e80)->FUN_00472380();
            for (int i = 0; i < actorCount72 && count33 < limit; ++i)
            {
                ShadowActor* actor = actors8[i];
                if (actor->Get3D() && actor->Get3D()->FUN_009611e0() && actor->FUN_0087f200() &&
                    actor->GetState() != 4 && !actor->FUN_008c51c0())
                {
                    ShadowExtra* extra6 = actor->Get3D()->FUN_00a5bdd0(FUN_0050ea90());
                    ShadowVector dimensions4 = extra6 ? extra6->FUN_00500940() : DAT_011f426c;
                    float maximum37 = FUN_00404010(FUN_00404010(dimensions4.x, dimensions4.y), dimensions4.z);
                    if (maximum37 * DAT_01021928 > actor->Get3D()->FUN_0043d450()->FUN_0084d030())
                    {
                        system->FUN_00b5cbd0(actor->Get3D());
                        ++count33;
                    }
                }
            }
            DAT_011f1180.Unlock();
            system->FUN_00b5cde0(playerShadow32);
            ShadowNode* playerNode50 = DAT_011dea3c->FUN_00950bb0(1);
            if (playerNode50)
            {
                ShadowScene* scene9 = (ShadowScene*)FUN_0045c670();
                ShadowView* view8 = scene9->FUN_008d80e0();
                view8->FUN_0041fd00(scene9->FUN_006629f0());
                view8->FUN_00a694a0(scene9->FUN_006629f0()->FUN_0045bbe0());
                bool playerHidden14 = playerNode50->FUN_00456610();
                playerNode50->FUN_00450f90(true);
                ShadowNode* specialNode3 = FUN_0054f4c0();
                FUN_004e20b0(false);
                bool specialHidden29 = false;
                if (specialNode3)
                {
                    specialHidden29 = specialNode3->FUN_00456610();
                    if (!*DAT_011c71dc.FUN_00408d60())
                        specialNode3->FUN_00450f90(true);
                }
                ShadowMap* shadow4 = system->FUN_00b5afc0();
                int rendered62 = 0;
                while (shadow4)
                {
                    if (shadow4->FUN_004e6540() && shadow4->FUN_005bf820())
                    {
                        if (!shadow4->FUN_004e6580() && shadow4->FUN_004e6540()->FUN_00456610())
                        {
                            if (shadow4->FUN_005bf820()->FUN_00456610())
                                shadow4->FUN_00b9bb10(0.0f, true);
                            else
                            {
                                if (rendered62 < limit)
                                    shadow4->FUN_004e6540()->FUN_00450f90(false);
                                shadow4->FUN_00b9bb10(0.0f, false);
                            }
                        }
                        if (rendered62 < limit && !shadow4->FUN_004e6540()->FUN_00456610() &&
                            !shadow4->FUN_005bf820()->FUN_00456610())
                        {
                            ShadowBound bounds = *shadow4->FUN_005bf820()->FUN_0043d450();
                            shadow4->UpdateOutputLight(0, shadow4->FUN_005bf820()->FUN_0045bb80());
                            shadow4->FUN_00b9e970(view8);
                            if (shadow4->FUN_004e6560() != 255 && shadow4->GetFirstLightParameter() >= DAT_01082cb0)
                            {
                                ++rendered62;
                                ShadowUpdate update53(0.0f, false, false);
                                shadow4->FUN_004e6540()->FUN_00a59c60(&update53);
                                shadow4->UpdateShadow(view8, rendered62 - 1);
                                shadow4->FUN_00b9fba0();
                                void* renderer12 = FUN_00450b80(0)->FUN_00454b30();
                                FUN_00450b80(0)->FUN_00b5d300(shadow4);
                                if (*DAT_011c7664.FUN_00408d60())
                                    shadow4->FUN_00ba0110(shadow4->FUN_005bf820());
                                shadow4->FUN_00ba02b0();
                            }
                            else
                                shadow4->FUN_004e6540()->FUN_00450f90(true);
                        }
                        else
                            shadow4->FUN_004e6540()->FUN_00450f90(true);
                    }
                    shadow4 = system->FUN_00b5b010();
                }
                while (rendered62 + 17 < 21)
                {
                    FUN_004ea970(0, rendered62 + 17)->FUN_00ba30f0();
                    ++rendered62;
                }
                if (specialNode3)
                    specialNode3->FUN_00450f90(specialHidden29);
                FUN_004e20b0(true);
                system->FUN_00b5b880(view8);
                playerNode50->FUN_00450f90(playerHidden14);
            }
        }
    }
    else
    {
        for (int i = 17; i < 21; ++i)
        {
            FUN_004ea970(0, i)->FUN_00ba30f0();
            FUN_004ea970(1, i)->FUN_00ba3130();
        }
    }
    FUN_00871a50();
}

namespace fnv_00871a50 {
extern bool __cdecl FUN_00702360();
extern bool __cdecl FUN_007079b0();
extern bool __cdecl FUN_00705a00();
extern void __cdecl FUN_007058e0();
extern bool __cdecl FUN_00707b30();
extern bool __cdecl FUN_00702680(unsigned int, int);
struct RenderFlag
{
    bool* FUN_00408d60();
};
extern RenderFlag DAT_011db2cc, DAT_011d8ba0;
struct RenderNode
{
    void FUN_007fae70(int);
    bool FUN_00456610();
    void FUN_00450f90(bool);
};
struct UiMenu
{
    RenderNode* FUN_0056c7f0();
};
extern UiMenu* __cdecl FUN_00a09030(unsigned int);
extern RenderNode* __cdecl FUN_00705990();
struct UiRenderer
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void Draw(RenderNode*, bool, int);
};
extern UiRenderer* __cdecl FUN_00707ad0();
struct RenderHolder
{
    RenderNode* FUN_00559450();
    void FUN_0066b0d0(RenderNode*);
};
extern RenderHolder DAT_011dec64;
struct RenderTextureSource
{
    RenderNode* FUN_00b6e110();
};
extern RenderTextureSource* __stdcall FUN_004a0ea0(void*, int, int, int, int);
extern void* __cdecl FUN_0043c4b0();
extern const char DAT_010829c4[];
struct HudRenderPass
{
    void FUN_00871a50();
};
// When the HUD conditions hold, ensures the render holder has a node, draws it via the UI renderer, and temporarily hides menu 1001's node while drawing.
// @fnv 0x00871a50
void HudRenderPass::FUN_00871a50()
{
    if (FUN_00702360() && (*DAT_011db2cc.FUN_00408d60() || *DAT_011d8ba0.FUN_00408d60()) && FUN_007079b0())
    {
        AutoMemHelper kContext(13, true, DAT_010829c4, 0x1ade);
        bool wasActive = FUN_00705a00();
        if (FUN_00702360())
            FUN_007058e0();
        if (!DAT_011dec64.FUN_00559450())
            DAT_011dec64.FUN_0066b0d0(FUN_004a0ea0(FUN_0043c4b0(), 45, 0, 0, 0)->FUN_00b6e110());
        if (!wasActive)
            FUN_00705990()->FUN_007fae70(0);
        bool show = FUN_00707b30() || FUN_00a09030(1001) || FUN_00a09030(1016) || FUN_00a09030(1059);
        if (FUN_007079b0() && show)
        {
            bool hide = wasActive && FUN_00702680(1001, 0);
            bool previous5 = 0;
            RenderNode* node_2 = 0;
            if (hide)
            {
                node_2 = FUN_00a09030(1001)->FUN_0056c7f0();
                previous5 = node_2->FUN_00456610();
                node_2->FUN_00450f90(true);
            }

            FUN_00707ad0()->Draw(DAT_011dec64.FUN_00559450(), true, 0);
            if (hide)
                node_2->FUN_00450f90(previous5);
        }
    }
    else if (FUN_00702360())
        FUN_007058e0();
}
}  // namespace fnv_00871a50

namespace fnv_00871dc0 {
struct RenderSurface
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
    virtual unsigned int Width(unsigned int);
    virtual unsigned int Height(unsigned int);
};
struct NiRenderer
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
    virtual RenderSurface* Target();
    void FUN_004a0370();
    void FUN_004a03c0();
};
NiRenderer* FUN_0043c4b0();
struct MTRenderer
{
    void FUN_00ba2f30();
    void FUN_00ba2fa0();
    void FUN_00ba30f0(int, int);
    void FUN_00ba3130(int, int);
};
MTRenderer* FUN_004ea970();
void FUN_00a044f0();
void FUN_00a04500();
struct MenuTarget
{
    unsigned int FUN_00872370(unsigned int);
    unsigned int FUN_008723d0(unsigned int);
};
struct MenuTargetPointer
{
    MenuTarget* value;
    MenuTarget* Get() const;
    void operator=(MenuTarget*);
};
extern MenuTargetPointer g_011ded3c;
struct TextureMgr
{
    void FUN_00b6da10(MenuTarget*);
    MenuTarget* FUN_00b6e110(NiRenderer*, int, int, int, int);
};
TextureMgr* __stdcall FUN_004a0ea0();
extern bool DAT_011ad884;
extern bool DAT_011f9426;
extern bool DAT_011dea29;
struct Rect
{
    float left, right, top, bottom;
    Rect(float, float, float, float);
};
struct Camera
{
    void FUN_00712e60(const Rect&);
};
Camera* FUN_00524c90();
extern Rect DAT_011ad840;
float FUN_0040ebd0(float, float);
struct Modifier;
struct InterfaceManager
{
    Modifier* FUN_00718ab0();
};
InterfaceManager* FUN_004b7210();
Modifier* FUN_005d2860();
void FUN_00529c90(Modifier*);
void FUN_005299a0(Modifier*, float, void*);
bool FUN_00705a00();
bool FUN_00702680(int, unsigned int);
bool IsStartMenuFlag1Set();
struct RenderMenu
{
    void* FUN_008b6200();
    void* GetMenuRoot();
};
RenderMenu* FUN_00707ad0();
struct BSCullingProcess
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
    BSCullingProcess(void*);
    ~BSCullingProcess();
    void FUN_0041fd00(void*);
    void FUN_004a0fd0(MenuTarget*);
};
struct SceneObject
{
    void FUN_004a1020(void*);
};
void* FUN_00450b80(int);
void FUN_00b6bee0(void*, void*, BSCullingProcess*);
void FUN_00b6c0d0(void*, MenuTarget*, int);
struct FUN_00871dc0_class
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
    MenuTargetPointer unk98;
    bool unk9c;
    void FUN_0086fd90(int);
    void FUN_008706b0(MenuTarget*, int, bool);
    void FUN_00871dc0();
};
// @fnv 0x00871dc0
void FUN_00871dc0_class::FUN_00871dc0()
{
    AutoMemHelper modifier(13, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 7193);
    if (!g_thePlayer->GetParentCell() || !g_thePlayer->GetNiNode())
        return;
    bool menu = DAT_011ad884;
    DAT_011ad884 = true;
    unk9c = true;
    FUN_0043c4b0()->FUN_004a0370();
    FUN_00a044f0();
    FUN_004ea970()->FUN_00ba2f30();
    if (g_011ded3c.Get())
        FUN_004a0ea0()->FUN_00b6da10(g_011ded3c.Get());
    g_011ded3c = FUN_004a0ea0()->FUN_00b6e110(FUN_0043c4b0(), 6, 0, 0, 0);
    if (FUN_0043c4b0()->Target()->Width(0) != g_011ded3c.Get()->FUN_00872370(0) ||
        FUN_0043c4b0()->Target()->Height(0) != g_011ded3c.Get()->FUN_008723d0(0))
    {
        float x =
            FUN_0040ebd0((float)FUN_0043c4b0()->Target()->Width(0) / (float)g_011ded3c.Get()->FUN_00872370(0), 1.0f);
        float y =
            FUN_0040ebd0((float)FUN_0043c4b0()->Target()->Height(0) / (float)g_011ded3c.Get()->FUN_008723d0(0), 1.0f);
        FUN_00524c90()->FUN_00712e60(Rect(0, x, y, 0));
    }
    else if (DAT_011f9426)
        FUN_00524c90()->FUN_00712e60(DAT_011ad840);
    Modifier* mem = FUN_004b7210()->FUN_00718ab0();
    FUN_00529c90(FUN_005d2860());
    if (mem)
    {
        FUN_005299a0(mem, 1.0f, 0);
        FUN_0086fd90(0);
    }
    bool old = FUN_00705a00();
    if (FUN_00702680(0x3f5, 0))
        old = false;
    FUN_008706b0(g_011ded3c.Get(), 0, old);
    if (FUN_00702680(0x40c, 0) && IsStartMenuFlag1Set())
    {
        BSCullingProcess cull(0);
        void* camera = FUN_00707ad0()->FUN_008b6200();
        cull.FUN_0041fd00(camera);
        cull.FUN_004a0fd0(unk98.Get());
        ((SceneObject*)unk98.Get())->FUN_004a1020(FUN_00450b80(1));
        FUN_00b6bee0(camera, FUN_00707ad0()->GetMenuRoot(), &cull);
        FUN_00b6c0d0(camera, unk98.Get(), 0);
        cull.FUN_004a0fd0(0);
    }
    if (mem)
    {
        FUN_00529c90(mem);
        FUN_0086fd90(0);
    }
    FUN_004ea970()->FUN_00ba30f0(0, 0x17);
    FUN_004ea970()->FUN_00ba3130(1, 0x17);
    FUN_004ea970()->FUN_00ba2fa0();
    DAT_011dea29 = true;
    FUN_00524c90()->FUN_00712e60(Rect(0, 1, 1, 0));
    FUN_00a04500();
    FUN_0043c4b0()->FUN_004a03c0();
    unk9c = false;
    DAT_011ad884 = menu;
}
}  // namespace fnv_00871dc0

struct FUN_00872780_Class
{
    int unk00;
    int unk04;
    int unk08;
    FUN_008727b0_Class* callback;
    char FUN_00872780();
};
// Returns the result of calling callback->FUN_008727b0() if callback is set, otherwise returns 0.
// @fnv 0x00872780
char FUN_00872780_Class::FUN_00872780()
{
    return callback ? callback->FUN_008727b0() : static_cast<char>(0);
}

extern double DAT_01082d20;
extern const char str_010829c4[];

struct NiRenderTargetGroup;
struct BSRenderedTexture;
struct TexObj
{
    unsigned int FUN_00872370(unsigned int i);
    unsigned int FUN_008723d0(unsigned int i);
    void FUN_008731d0();
};
extern BSRenderedTexture* DAT_011f9438;

struct P1
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual NiRenderTargetGroup* GetRenderGroup();
    unsigned int FUN_004dee10();
    unsigned int FUN_004dee70();
};

struct Mgr
{
    BSRenderedTexture* FUN_00b6e110();
};
Mgr* __stdcall FUN_004a0ea0(P1* a, int b, int c, int d, int e);

unsigned char FUN_008709f0();
double FUN_008731a0(double b, float a);
void __cdecl FUN_00b6b8d0(unsigned int id, NiRenderTargetGroup* ausAnimationGroup);
void __cdecl FUN_00b6b890(unsigned int id, NiRenderTargetGroup* ausAnimationGroup);

struct ImageSpaceEffectParam
{
    ImageSpaceEffectParam(float a, float b, float c, float d);
    float m_kPointA;
    float m_kPointB;
    float m_iThirdValue;
    float m_iFourthElementInteger;
};
struct _Rect16_00712e60
{
    float m_kPointA;
    float m_kPointB;
    float m_iThirdValue;
    float m_iFourthElementInteger;
};
struct _Cam_00712e60
{
    void FUN_00712e60(const _Rect16_00712e60& r);
};
_Cam_00712e60* __cdecl FUN_00524c90();

struct Host
{
    BSRenderedTexture* FUN_00872f50(P1* a1, BSRenderedTexture* a2, unsigned char a3, unsigned char a4);
};

// @fnv 0x00872f50
BSRenderedTexture* Host::FUN_00872f50(P1* apSource, BSRenderedTexture* apFallbackTexture, unsigned char abSkipCreate,
                                      unsigned char abUseSourceGroup)
{
    BSRenderedTexture* tex = 0;
    if (FUN_008709f0() && !abSkipCreate)
    {
        AutoMemHelper helper(0x27, true, str_010829c4, 0x1e6d);
        tex = FUN_004a0ea0(apSource, 4, 0, 0, 0)->FUN_00b6e110();
        ((TexObj*)tex)->FUN_008731d0();
        DAT_011f9438 = tex;
        if (apSource->FUN_004dee10() != ((TexObj*)tex)->FUN_00872370(0) ||
            apSource->FUN_004dee70() != ((TexObj*)tex)->FUN_008723d0(0))
        {
            float fa;
            fa = (float)FUN_008731a0(
                (double)apSource->FUN_004dee10() * DAT_01082d20 / (double)((TexObj*)tex)->FUN_00872370(0), 1.0f);
            float fb;
            fb = (float)FUN_008731a0(
                (double)apSource->FUN_004dee70() * DAT_01082d20 / (double)((TexObj*)tex)->FUN_008723d0(0), 1.0f);
            FUN_00524c90()->FUN_00712e60((_Rect16_00712e60&)ImageSpaceEffectParam(0.0f, fa, fb, 0.0f));
        }
        FUN_00b6b8d0(7, tex->GetGroup());
    }
    else
    {
        AutoMemHelper helper(0x26, true, str_010829c4, 0x1e84);
        if (apFallbackTexture)
        {
            if (abUseSourceGroup)
            {
                FUN_00b6b8d0(7, apSource->GetRenderGroup());
            }
            else
            {
                FUN_00b6b8d0(7, apFallbackTexture->GetGroup());
            }
        }
        else
        {
            FUN_00b6b890(7, 0);
        }
    }
    return tex;
}

namespace fnv_00874c10 {
struct BSFaceGenNiNode;
BSFaceGenNiNode* __cdecl FUN_0045c670();

struct BSFaceGenAnimationData
{
    void FUN_00712e60(void*);
};
BSFaceGenAnimationData* __cdecl FUN_00524c90();

struct TransformState
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    float tx, ty, tz;
    float scale;
};

struct AnimDataHelper
{
    float FUN_006447f0();
    void* FUN_0045bbe0();
    void* FUN_004a0d10();
    TransformState* FUN_00461130();
};

struct NiUpdateData
{
    float fTime;
    int b1;
    int b2;
    NiUpdateData(float time, int m_bUpdateEnabled, int bUpdateGeom);
};

struct NiPoint3WithNeg : public NiPoint3
{
    NiPoint3 FUN_004a0bd0() const;
};

struct NiNode
{
    void FUN_00450f90(bool);
    bool FUN_00456610();
    NiPoint3WithNeg* FUN_0045bb80();
    NiPoint3* FUN_0043c490();
    void FUN_00440460(const NiPoint3*);
    void Update(NiUpdateData*);
    void FUN_00546780(bool);
};

struct PlayerObjectHelper
{
    NiPoint3* FUN_0045bb80();
};

struct PlayerHelper
{
    NiNode* FUN_00950bb0(bool);
    PlayerObjectHelper* FUN_007721a0();
    bool FUN_008a8870();
    bool FUN_00967ae0();
};

struct AudioGlobalHelper
{
    bool FUN_005bb4d0();
};
extern AudioGlobalHelper* DAT_011dea0c;

struct CameraHelper
{
    NiPoint3* FUN_0045bb80();
};
extern CameraHelper* DAT_011e07d0;

struct VATSHelper
{
    bool FUN_00525430();
};
extern VATSHelper DAT_011f2250;

struct BGSBodyPart
{
    NiPoint3* FUN_0045bb80();
    void FUN_004f00e0(const NiPoint3&);
};

struct FORenderedMenu
{
    BGSBodyPart* FUN_006838b0();
};
FORenderedMenu* __cdecl FUN_00705990();
FORenderedMenu* __cdecl FUN_00707ad0();

struct MTRenderingSystem_Helper
{
    void FUN_00ba30f0(int, int);
    void FUN_00ba3390(void*, int, void*, int, int, void*, int, int, int);
};
MTRenderingSystem_Helper* __cdecl FUN_004ea970();

struct ObjectA0
{
    void FUN_00507700(float);
    void FUN_00a6faf0(void*);
    void FUN_00712e60(void*);
    void FUN_004f00e0(const NiPoint3&);
    void FUN_00688430(TransformState*);
    NiPoint3* FUN_0045bb80();
};

struct Object8C
{
};

template <class T> struct TargetPointer
{
    T* m_pObject;
    T* operator->() const
    {
        return m_pObject;
    }
    operator T*() const
    {
        return m_pObject;
    }
};

struct NiRenderer
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
    virtual void v30();
    virtual void v31();
    virtual int v50();
    virtual int v51();
};
NiRenderer* __cdecl FUN_0043c4b0();

struct FaceGenHelper
{
    void SetCameraFOV(float, int, int, int);
};

void* __cdecl FUN_00450b80(int);

extern const char str_010829c4[];
extern unsigned char DAT_011f9426;
extern int DAT_011ad840;
extern unsigned char DAT_011de9d1;

struct MainShell
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
    TargetPointer<Object8C> spObj8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    TargetPointer<ObjectA0> spObjA0;

    void FUN_00874c10();
};

// Updates the player's face gen node and render objects, toggling DAT_011de9d1 and submitting spObjA0/spObj8C to the rendering system.
// @fnv 0x00874c10
void MainShell::FUN_00874c10()
{
    AutoMemHelper memHelper5(0x34, 1, str_010829c4, 0x21b1);
    BSFaceGenNiNode* pFaceGenNode2 = FUN_0045c670();
    BSFaceGenAnimationData* pAnimData = FUN_00524c90();
    NiNode* _pPlayerNode = ((PlayerHelper*)g_thePlayer)->FUN_00950bb0(1);
    _pPlayerNode->FUN_00450f90(0);

    if (DAT_011f9426)
    {
        if (FUN_0043c4b0()->v51() == 0 || FUN_0043c4b0()->v51() == FUN_0043c4b0()->v50())
        {
            FUN_00524c90()->FUN_00712e60(&DAT_011ad840);
        }
    }

    ((FaceGenHelper*)pFaceGenNode2)->SetCameraFOV(FUN_00874900((const char*)g_thePlayer), 0, 0, 0);

    if (((!((PlayerHelper*)g_thePlayer)->FUN_00950bb0(0)->FUN_00456610() &&
          !((PlayerHelper*)g_thePlayer)->FUN_00950bb0(1)->FUN_00456610() == 0) ||
         (!((PlayerHelper*)g_thePlayer)->FUN_00950bb0(0)->FUN_00456610() == 0 &&
          !((PlayerHelper*)g_thePlayer)->FUN_00950bb0(1)->FUN_00456610())) &&
        !DAT_011dea0c->FUN_005bb4d0())
    {
        NiPoint3 pt_5c3 = _pPlayerNode->FUN_0045bb80()->FUN_004a0bd0();
        NiUpdateData updateData7(0.0f, 0, 0);
        DAT_011de9d1 = 1;

        spObjA0->FUN_00507700(((AnimDataHelper*)pAnimData)->FUN_006447f0());
        spObjA0->FUN_00a6faf0(((AnimDataHelper*)pAnimData)->FUN_0045bbe0());
        spObjA0->FUN_00712e60(((AnimDataHelper*)pAnimData)->FUN_004a0d10());

        TransformState kTransform = *((AnimDataHelper*)pAnimData)->FUN_00461130();
        spObjA0->FUN_004f00e0(*DAT_011e07d0->FUN_0045bb80() + pt_5c3);
        spObjA0->FUN_00688430(&kTransform);

        if (((PlayerHelper*)g_thePlayer)->FUN_007721a0() && !((PlayerHelper*)g_thePlayer)->FUN_008a8870() &&
            !DAT_011f2250.FUN_00525430())
        {
            spObjA0->FUN_004f00e0(*((PlayerHelper*)g_thePlayer)->FUN_007721a0()->FUN_0045bb80() + pt_5c3);
        }

        NiPoint3 pt_6c_ = *_pPlayerNode->FUN_0043c490();
        _pPlayerNode->FUN_00440460(&NiPoint3::ZERO);
        _pPlayerNode->Update(&updateData7);
        _pPlayerNode->FUN_00440460(&pt_6c_);

        BGSBodyPart* pBodyPart3 =
            ((PlayerHelper*)g_thePlayer)->FUN_00967ae0() ? (pBodyPart3 = FUN_00705990()->FUN_006838b0()) : 0;
        _pPlayerNode->FUN_00546780(1);

        if (pBodyPart3)
        {
            pBodyPart3->FUN_004f00e0(*pBodyPart3->FUN_0045bb80() - pt_5c3);
        }

        FUN_00870790((_Fake_FUN_00870790*)FUN_00450b80(0), *spObjA0->FUN_0045bb80());
        ((_Fake_FUN_008750e0*)FUN_00450b80(0))->FUN_008750e0(pt_5c3);
    }
    else
    {
        DAT_011de9d1 = 0;
    }

    if (FUN_00707ad0() && FUN_00707ad0() != FUN_00705990())
    {
    }
    else
    {
        FUN_004ea970()->FUN_00ba3390(spObjA0, 0, _pPlayerNode, 0, 0, spObj8C, 0, 0x16, 0);
    }
    FUN_004ea970()->FUN_00ba30f0(0, 0x16);
}
}  // namespace fnv_00874c10

namespace SetRenderCamera {
struct Scene;
struct Context;
struct Pointer;
struct List;
struct Vec
{
    float x, y, z;
    Vec(float, float, float);
    Vec FUN_00439ef0(const Vec&);
    Vec FUN_00439e90(const Vec&);
};
struct Rect
{
    float left, right, top, bottom;
    Rect(float, float, float, float);
};
struct Update
{
    float time;
    unsigned int flags, other;
    Update(float, int, int);
};
struct Guard
{
    unsigned int state;
    Guard(int, int, const char*, int);
    ~Guard();
};
struct VecRef
{
    Vec* FUN_0043c490();
};
struct Scene
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual Scene* Node();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual bool Active();
    virtual void slotc4();
    virtual void* Secondary();
    virtual void* Primary();
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned short unk38;
    unsigned char visible, unk3b;
    void FUN_00450f90(bool);
    void FUN_007148c0(int, int);
    void FUN_00712e60(const Rect&);
    void FUN_00a6faf0(void*);
    void FUN_007fae70(int);
    Scene* FUN_007fa950();
    Scene* FUN_00875bd0(int);
    Scene* FUN_00a59d30(void*);
    void FUN_0049ed90(int);
    Vec* FUN_0045bb80();
    void* FUN_0045bbe0();
    void FUN_004f00e0(const Vec&);
    void FUN_00936aa0(bool);
    void FUN_00a29680();
    void* FUN_00b6b260();
    void FUN_00b64570(Scene*, Scene*);
    void FUN_00a59c60(const Update&);
    void FUN_00546780(int);
    VecRef* FUN_009611e0();
    void FUN_00870790(Vec);
    void FUN_008750e0(Vec);
    Scene* FUN_0043b230();
    bool FUN_00456610();
    void FUN_006426a0(int, Scene*, Scene*);
    Context* FUN_008d80e0();
    Scene* FUN_006629f0();
    void SetCameraFOV(float, int, int, int);
    void FUN_00ba3130(int, int);
};
struct Output : Scene
{
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    Output(int, int, int);
    static __forceinline void* operator new(unsigned int);
    static __forceinline void operator delete(void*)
    {}
};
void* FUN_00aa13e0(unsigned int);
__forceinline void* Output::operator new(unsigned int n)
{
    return FUN_00aa13e0(n);
}
struct Pointer
{
    Scene* value;
    Pointer(Scene*);
    Pointer(const Pointer&);
    ~Pointer();
    Scene* FUN_00559450();
    void FUN_0066b0d0(Scene*);
};
struct Context
{
    void FUN_00c4f270(int);
    void FUN_004a0fd0(Scene*);
    void FUN_00c4f2d0();
};
struct List
{
    bool FUN_004a4460();
    Pointer* FUN_006815c0();
    List* FUN_00726070();
};
struct ListRef
{
    List* FUN_0043c490();
};
struct Mode
{
    bool FUN_00525430();
    int FUN_0044ddc0();
};
struct Player
{
    Scene* FUN_00950bb0(int);
    float FUN_00874900();
    float FUN_00710ab0();
    bool FUN_008c51c0();
    Scene* FUN_007721a0();
    bool FUN_008a8870();
};
extern Player* DAT_011dea3c;
extern bool DAT_011f9426, DAT_011de9d1;
extern Rect DAT_011ad840;
extern const char DAT_010829c4[];
extern Scene* DAT_011f9438;
extern ListRef DAT_011e0e80;
extern Mode DAT_011f2250;
extern Scene* DAT_011e07d0;
extern Vec DAT_011f426c;
extern Pointer DAT_011deb7c;
Scene* FUN_0045c670();
Scene* FUN_004ea970();
Scene* FUN_0043c4b0();
void FUN_00b54000(float);
Scene* FUN_00707ad0();
Scene* FUN_00705990();
bool FUN_007079b0();
bool FUN_00705a00();
void* FUN_0040df90();
void FUN_00b6bee0(Scene*, Scene*, Context*);
void FUN_00b6c0d0(Scene*, Scene*, int);
void FUN_00b98380(int, int);
void FUN_004eced0(int);
bool FUN_005b9b00();
void FUN_00b6b790();
void FUN_00b6b8d0(int, void*);
Scene* FUN_00524c90();
Scene* FUN_00450b80(int);
struct Main
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    Pointer texture, surface;
    unsigned int unk90, unk94, unk98, unk9c;
    Pointer camera;
    void FUN_00874b50(Scene*, int, int);
    void FUN_00875110(Scene*, Scene*, Scene*, Scene*);
};
// @fnv 0x00875110
void Main::FUN_00875110(Scene* root, Scene* firstPerson, Scene* extra, Scene* pass)
{
    Scene* renderSlot52 = FUN_0045c670();
    Context* contextSlot26 = renderSlot52->FUN_008d80e0();
    Scene* playerSceneSlot0 = DAT_011dea3c->FUN_00950bb0(1);
    playerSceneSlot0->FUN_00450f90(0);
    Scene* viewSlot23 = renderSlot52->FUN_006629f0();
    Scene* aliasSlot0 = playerSceneSlot0;
    FUN_004ea970()->FUN_00ba3130(1, 22);
    surface.FUN_00559450()->visible = 0;
    Guard guardSlot1(0x34, 1, DAT_010829c4, 0x221f);
    root->FUN_007148c0(0, 4);
    if (DAT_011f9426 && (!FUN_0043c4b0()->Primary() || FUN_0043c4b0()->Primary() == FUN_0043c4b0()->Secondary()))
        camera.FUN_00559450()->FUN_00712e60(DAT_011ad840);
    else
        camera.FUN_00559450()->FUN_00712e60(Rect(0, 1, 1, 0));
    renderSlot52->SetCameraFOV(DAT_011dea3c->FUN_00874900(), 0, 0, 0);
    FUN_00b54000(DAT_011dea3c->FUN_00874900());
    camera.FUN_00559450()->FUN_00a6faf0(viewSlot23->FUN_0045bbe0());
    if (firstPerson)
    {
        FUN_00707ad0()->FUN_007fae70(0);
        firstPerson->FUN_00450f90(0);
        if (FUN_007079b0())
        {
            if (FUN_00705a00() && DAT_011dea3c->FUN_008c51c0())
                FUN_00707ad0()->FUN_007fa950()->FUN_00450f90(1);
            Pointer tempTextureSlot13(new Output(99, 1, 759));
            contextSlot26->FUN_00c4f270(1);
            Scene* property = FUN_00707ad0()->FUN_007fa950()->FUN_00a59d30(FUN_0040df90());
            if (property)
                property->FUN_0049ed90(0);
            FUN_00707ad0()->FUN_007fae70(0);
            contextSlot26->FUN_004a0fd0(tempTextureSlot13.FUN_00559450());
            if (FUN_00705a00() && DAT_011dea3c->FUN_008c51c0())
            {
                FUN_00b6bee0(camera.FUN_00559450(), FUN_00705990()->FUN_00875bd0(0), contextSlot26);
                FUN_00b6bee0(camera.FUN_00559450(), FUN_00705990()->FUN_00875bd0(1), contextSlot26);
                FUN_00b6bee0(camera.FUN_00559450(), FUN_00705990()->FUN_00875bd0(2), contextSlot26);
            }
            FUN_00b6bee0(camera.FUN_00559450(), FUN_00707ad0()->FUN_007fa950(), contextSlot26);
            FUN_00b6c0d0(camera.FUN_00559450(), tempTextureSlot13.FUN_00559450(), 0);
            contextSlot26->FUN_004a0fd0(0);
            tempTextureSlot13.FUN_0066b0d0(0);
            contextSlot26->FUN_00c4f2d0();
            if (FUN_00705a00() && DAT_011dea3c->FUN_008c51c0())
                FUN_00707ad0()->FUN_007fa950()->FUN_00450f90(0);
        }
    }
    if (FUN_00707ad0() && FUN_00707ad0() != FUN_00705990())
    {
    }
    else if (!FUN_00705a00() || !DAT_011dea3c->FUN_008c51c0())
    {
        FUN_00b98380(15, 1);
        FUN_004ea970()->FUN_00ba3130(1, 22);
        FUN_00b6c0d0(camera.FUN_00559450(), surface.FUN_00559450(), 0);
        FUN_004eced0(1);
        List* list = DAT_011e0e80.FUN_0043c490();
        if (list && !list->FUN_004a4460())
        {
            Vec offset(0, 0, 0);
            if (DAT_011dea3c->FUN_007721a0() && !DAT_011dea3c->FUN_008a8870() && !DAT_011f2250.FUN_00525430())
                offset = DAT_011dea3c->FUN_007721a0()->FUN_0045bb80()->FUN_00439ef0(*DAT_011e07d0->FUN_0045bb80());
            Scene* render2Slot14 = FUN_0045c670();
            Scene* view2Slot10 = render2Slot14->FUN_006629f0();
            Context* context2Slot0 = render2Slot14->FUN_008d80e0();
            Pointer texture2Slot11(texture);
            Vec savedPosSlot10 = *view2Slot10->FUN_0045bb80();
            view2Slot10->FUN_004f00e0(savedPosSlot10.FUN_00439e90(offset));
            context2Slot0->FUN_004a0fd0(texture2Slot11.FUN_00559450());
            texture2Slot11.FUN_00559450()->FUN_00936aa0(1);
            bool renderedSlot0 = false;
            while (list)
            {
                Scene* object = list->FUN_006815c0()->FUN_00559450();
                list = list->FUN_00726070();
                if (object && object->Active())
                {
                    renderedSlot0 = true;
                    object->Node()->FUN_00450f90(0);
                    FUN_00b6bee0(view2Slot10, object->Node(), context2Slot0);
                    object->Node()->FUN_00450f90(1);
                }
            }
            if (renderedSlot0)
                FUN_00b6c0d0(view2Slot10, texture2Slot11.FUN_00559450(), 0);
            context2Slot0->FUN_004a0fd0(0);
            texture2Slot11.FUN_00559450()->FUN_00936aa0(0);
            texture2Slot11.FUN_0066b0d0(0);
            view2Slot10->FUN_004f00e0(savedPosSlot10);
        }
    }
    if (FUN_005b9b00())
    {
        Guard guard2Slot0(0x27, 1, DAT_010829c4, 0x22b5);
        if (FUN_00705a00() && FUN_005b9b00() && DAT_011dea3c->FUN_008c51c0())
        {
            FUN_00b6b790();
            DAT_011f9438->FUN_00a29680();
            FUN_00b6b8d0(6, pass->FUN_00b6b260());
            if (DAT_011f9426)
                FUN_00524c90()->FUN_00712e60(DAT_011ad840);
        }
        Scene* render3Slot0 = FUN_0045c670();
        surface.FUN_00559450()->FUN_00b64570(camera.FUN_00559450(), pass);
        FUN_00874b50(pass, 0, 0);
    }
    if (DAT_011de9d1)
    {
        Update update(0.0f, 0, 0);
        aliasSlot0->FUN_00a59c60(update);
        aliasSlot0->FUN_00546780(0);
        FUN_00450b80(0)->FUN_00870790(*viewSlot23->FUN_009611e0()->FUN_0043c490());
        FUN_00450b80(0)->FUN_008750e0(DAT_011f426c);
    }
    if (DAT_011f2250.FUN_0044ddc0() != 4)
        FUN_0045c670()->SetCameraFOV(DAT_011dea3c->FUN_00710ab0(), 0, 0, 0);
    FUN_00b54000(DAT_011dea3c->FUN_00710ab0());
    if (extra && !extra->FUN_0043b230()->FUN_00456610())
    {
        bool previousSlot0 = extra->FUN_0043b230()->FUN_00456610();
        extra->FUN_0043b230()->FUN_00450f90(0);
        Scene* render4Slot20 = FUN_0045c670();
        Scene* view4Slot48 = render4Slot20->FUN_006629f0();
        Context* context4 = render4Slot20->FUN_008d80e0();
        Pointer texture4(texture);
        context4->FUN_004a0fd0(texture4.FUN_00559450());
        texture4.FUN_00559450()->FUN_00936aa0(1);
        FUN_00b6bee0(view4Slot48, extra->FUN_0043b230(), context4);
        FUN_00b6c0d0(view4Slot48, texture4.FUN_00559450(), 0);
        context4->FUN_004a0fd0(0);
        texture4.FUN_00559450()->FUN_00936aa0(0);
        texture4.FUN_0066b0d0(0);
        extra->FUN_0043b230()->FUN_00450f90(previousSlot0);
    }
    if (extra)
        extra->FUN_006426a0(2, texture.FUN_00559450(), DAT_011deb7c.FUN_00559450()->FUN_006629f0());
    renderSlot52->SetCameraFOV(DAT_011dea3c->FUN_00874900(), 0, 0, 0);
    FUN_00b54000(DAT_011dea3c->FUN_00874900());
}
}

namespace fnv_00875fd0 {
struct SaveGameRenderState
{
    bool FUN_0042ce10();
    bool FUN_005621d0();
};
extern SaveGameRenderState* g_BGSSaveLoadGame;
bool __cdecl FUN_00705a00();
bool __cdecl FUN_00702360();
bool __cdecl FUN_00705e80();
void __cdecl FUN_00702870();
void __cdecl FUN_00b6b790();
bool __cdecl FUN_007079b0();
struct RenderEffectManager
{
    void FUN_00801a60(void*, BSShaderAccumulator*, int, unsigned char);
    void FUN_008019d0();
};
RenderEffectManager* __cdecl FUN_00705910();
struct AccumulatorPointer
{
    BSShaderAccumulator* FUN_00559450() const;
    void FUN_0066b0d0(BSShaderAccumulator*);
};
extern AccumulatorPointer DAT_011deb38;
extern bool DAT_011dea29;
extern bool DAT_012005a2;
extern float DAT_011add08;
extern void* DAT_011f917c;
struct RenderedMenu
{
    virtual void UnkVirtual0();
    virtual void UnkVirtual1();
    virtual void UnkVirtual2();
    virtual void UnkVirtual3();
    virtual void UnkVirtual4();
    virtual void UnkVirtual5();
    virtual void UnkVirtual6();
    virtual void UnkVirtual7();
    virtual void UnkVirtual8();
    virtual void UnkVirtual9();
    virtual void UnkVirtual10();
    virtual float GetRenderScale();
};
RenderedMenu* __cdecl FUN_00707ad0();
void __cdecl FUN_00b55ac0(void*, void*, void*);
struct TextureReturnManager
{
    void FUN_00b6da10(BSShaderAccumulator*);
};
TextureReturnManager* __stdcall FUN_004a0ea0();
struct ImageSpaceEffectParam
{
    ImageSpaceEffectParam(float, float, float, float);
    float left;
    float right;
    float top;
    float bottom;
};
struct ViewportCamera
{
    void FUN_00712e60(const ImageSpaceEffectParam&);
};
ViewportCamera* __cdecl FUN_00524c90();
struct FrameRenderer
{
    unsigned int unk00;
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
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    bool bSkipScene;
    void FUN_00875fd0(void*, void*, void*, void*);
};

// @fnv 0x00875fd0
void FrameRenderer::FUN_00875fd0(void* unused, void* renderer, void* scene, void* target)
{
    AutoMemHelper m_uiMemoryContext(39, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 9058);
    if (!FUN_004e9510())
        FUN_00b6b790();
    if (!FUN_00705a00() && !FUN_00702360() && !FUN_00705e80() && !g_BGSSaveLoadGame->FUN_0042ce10() &&
        !g_BGSSaveLoadGame->FUN_005621d0() && !bSkipScene)
        FUN_00702870();
    if (DAT_011deb38.FUN_00559450())
        FUN_00705910()->FUN_00801a60(renderer, DAT_011deb38.FUN_00559450(), 0, 0);
    bool menuActive = FUN_007079b0() && !bSkipScene && DAT_011dea29;
    if (menuActive)
    {
        DAT_012005a2 = true;
        float renderScale = FUN_00707ad0()->GetRenderScale();
        DAT_011add08 = renderScale;
    }
    DAT_011f917c = FUN_0045c670()->GetAnimationData();
    FUN_00b55ac0(scene, renderer, target);
    if (DAT_011deb38.FUN_00559450())
    {
        FUN_00705910()->FUN_008019d0();
        FUN_004a0ea0()->FUN_00b6da10(DAT_011deb38.FUN_00559450());
        DAT_011deb38.FUN_0066b0d0(0);
    }
    if (menuActive)
    {
        DAT_012005a2 = false;
        DAT_011add08 = 1.0f;
    }
    FUN_00524c90()->FUN_00712e60(ImageSpaceEffectParam(0.0f, 1.0f, 1.0f, 0.0f));
}
}  // namespace fnv_00875fd0

namespace fnv_008761e0 {
struct V876
{
    float x, y, z;
    void FUN_0043d410(float, int, int);
};
struct T876
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    V876 pos;
    float scale;
    void FUN_00476a80();
    void FUN_00a86bf0();
};
struct R876
{
    float l, r, t, b;
};
struct Camera876
{
    bool FUN_00876810();
    T876* FUN_006a9540();
    void FUN_00440460(V876*);
    void FUN_00a59c60(V876*);
    void FUN_00546780(bool);
    Camera876* FUN_009611e0();
    Camera876* FUN_006629f0();
    Camera876* FUN_008b6200();
    Camera876* FUN_005585e0();
    R876* FUN_004a0d10();
    void FUN_00712e60(R876*);
    Camera876* FUN_0045bb80();
    V876* FUN_004a0bd0(V876*);
    void FUN_004fb0b0(bool);
    void FUN_0041fd00(Camera876*);
    void FUN_004a0fd0(void*);
    void FUN_004a1020(void*);
    void FUN_00b63b90(int);
    void FUN_0049ed90(bool);
    void FUN_00439340(int);
    void FUN_00439390(int);
    Camera876* FUN_00a59d30(void*);
    void FUN_00a5a040();
    Camera876* FUN_007fa950();
    void FUN_007fae70(void*);
    Camera876* FUN_00559450();
    void* FUN_004bc320(int);
};
struct Player876
{
    Camera876* FUN_008d80e0();
    Camera876* FUN_006629f0();
};
struct Global876
{
    bool FUN_00967ae0();
    bool FUN_008c51c0();
};
struct Input876
{
    int FUN_00a23a50(int, int);
    void FUN_007148c0(int, int);
};
struct Mode876
{
    bool FUN_007f8720(bool, bool, float*, float*, int*);
    Camera876* FUN_00875bd0(int);
};
extern Global876* DAT_011dea3c;
extern Camera876* DAT_011e07d0;
extern Camera876 g_011dec64;
extern V876 DAT_011f426c;
extern bool DAT_011f9426;
extern R876 DAT_011ad840;
Camera876* FUN_00707ad0();
Mode876* FUN_00705990();
bool FUN_00705a00();
void FUN_00709b50(bool, float, float, int);
void FUN_00b98380(int, int);
void FUN_00b97e30(int, int);
void FUN_00b97de0(int, int);
void FUN_00b6bee0(Camera876*, Camera876*, Camera876*);
void FUN_00b6c0d0(Camera876*, Camera876*, int);
void FUN_004eced0(int);
void* FUN_0040df90();
void FUN_00714a60(int);
void FUN_00714a40(int);
_Fake_FUN_008750e0* FUN_00450b80(int);
struct Virtual876
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
    virtual int width();
    virtual int height();
};
Virtual876* FUN_0043c4b0();
struct Shell876
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
    Camera876 a8c;
    int unk90;
    int unk94;
    Camera876 a98;
    int unk9c;
    Camera876 aa0;
    Input876* FUN_00877720();
    void FUN_008761e0(int, Input876*);
};
// Sets up the player camera and scene nodes, applies camera transforms and render passes, then restores the previous camera state.
// @fnv 0x008761e0
void Shell876::FUN_008761e0(int unused, Input876* input)
{
    Player876* p;
    R876 h;
    Camera876* a;
    Camera876* i;
    Camera876* s;
    Camera876* f;
    bool eb;
    V876 cf;
    Camera876* q;
    T876 b;
    T876 ba;
    bool k;
    int l;
    float c;
    float e;
    V876 j;
    p = (Player876*)FUN_0045c670();
    s = p->FUN_008d80e0();
    i = FUN_00707ad0()->FUN_008b6200();
    input->FUN_007148c0(0, 4);
    f = FUN_00707ad0()->FUN_005585e0();
    s->FUN_004fb0b0(true);
    cf.FUN_0043d410(0.0f, 0, 0);
    b.FUN_00476a80();
    eb = f->FUN_00876810();
    a = i ? i : p->FUN_006629f0();

    if (DAT_011dea3c->FUN_00967ae0())
    {
        ba = *f->FUN_006a9540();
        f->FUN_00440460(&DAT_011f426c);
        f->FUN_00a59c60(&cf);
        f->FUN_00440460(&ba.pos);
        b.FUN_00a86bf0();
        if (a && a->FUN_009611e0())
        {
            b = *a->FUN_009611e0()->FUN_006a9540();
            a->FUN_009611e0()->FUN_00440460((V876*)DAT_011e07d0->FUN_0045bb80());
            a->FUN_009611e0()->FUN_00a59c60(&cf);
        }

        FUN_00450b80(0)->FUN_008750e0(*(NiPoint3*)f->FUN_0045bb80()->FUN_004a0bd0(&j));
    }
    if (FUN_00705a00())
    {
        l = 0;
        k = FUN_00705990()->FUN_007f8720(FUN_00877720()->FUN_00a23a50(0, 1) > 0, FUN_00877720()->FUN_00a23a50(0, 2) > 0,
                                         &e, &c, &l);
        FUN_00709b50(k, e, c, l);
    }
    i = i ? i : p->FUN_006629f0();
    if (!i)
        i = aa0.FUN_00559450();
    h = *i->FUN_004a0d10();
    if (DAT_011f9426 && FUN_0043c4b0()->height() == FUN_0043c4b0()->width())
        i->FUN_00712e60(&DAT_011ad840);
    FUN_00b98380(0, 1);
    s->FUN_0041fd00(i);
    s->FUN_004a0fd0(a8c.FUN_00559450());
    a8c.FUN_00559450()->FUN_004a1020(FUN_00450b80(0));
    FUN_00b6bee0(i, f, s);
    FUN_00b6c0d0(i, a8c.FUN_00559450(), 0);
    a8c.FUN_00559450()->FUN_00b63b90(6);
    s->FUN_004a0fd0(0);
    FUN_004eced0(1);
    q = FUN_00707ad0()->FUN_007fa950()->FUN_00a59d30(FUN_0040df90());
    if (q)
    {
        q->FUN_0049ed90(true);
        q->FUN_00439340(6);
        q->FUN_00439390(0);
        FUN_00707ad0()->FUN_007fa950()->FUN_00a5a040();
    }
    FUN_00707ad0()->FUN_007fae70(g_011dec64.FUN_00559450()->FUN_004bc320(0));
    s->FUN_0041fd00(i);
    s->FUN_004a0fd0(a98.FUN_00559450());
    FUN_00b97e30(0, 1);
    if (DAT_011dea3c->FUN_008c51c0() && FUN_00705a00())
    {
        FUN_00b6bee0(i, FUN_00705990()->FUN_00875bd0(0), s);
        FUN_00b6bee0(i, FUN_00705990()->FUN_00875bd0(1), s);
        FUN_00b6bee0(i, FUN_00705990()->FUN_00875bd0(2), s);
        FUN_00b97de0(0, 1);
    }
    FUN_00b6bee0(i, FUN_00707ad0()->FUN_007fa950(), s);
    FUN_00b6c0d0(i, a98.FUN_00559450(), 0);
    FUN_00714a60(1);
    if (DAT_011dea3c->FUN_008c51c0() && FUN_00705a00())
        FUN_00714a40(1);
    s->FUN_004a0fd0(0);
    FUN_00707ad0()->FUN_007fae70(0);
    if (q)
        q->FUN_0049ed90(false);
    i->FUN_00712e60(&h);
    if (DAT_011dea3c->FUN_00967ae0())
    {
        f->FUN_00a59c60(&cf);
        f->FUN_00546780(eb);
        if (a && a->FUN_009611e0())
        {
            a->FUN_009611e0()->FUN_00440460(&b.pos);
            a->FUN_009611e0()->FUN_00a59c60(&cf);
        }
        FUN_00450b80(0)->FUN_008750e0(*(NiPoint3*)&DAT_011f426c);
    }
    s->FUN_004fb0b0(false);
}
}  // namespace fnv_008761e0

struct SLPoint3
{
    float x;
    float y;
    float z;
};

struct SLWorldSpace;

struct SLCell
{
    bool IsInterior();
    SLWorldSpace* GetParentWorldSpace();
    int GetPosX();
    int GetPosY();
};

struct SLWorldSpace
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual const char* GetEditorID();

    SLCell* GetCellAtCoords(int aiX, int aiY);
};

struct SLWorldSpaceList
{
    SLWorldSpace* pItem;
    SLWorldSpaceList* pNext;

    bool IsEmpty();
    SLWorldSpace** GetItem();
    SLWorldSpaceList* GetNext();
};

struct SLDataHandler
{
    SLWorldSpaceList* GetWorldSpaces();
    SLCell* GetCellByName(const char* apName);
    SLWorldSpace* GetWorldSpaceForCell(const char* apName, int* apX, int* apY);
    SLCell* GetContainingCell(int aiX, int aiY, SLWorldSpace* apWorld, bool abCreate);
    void FUN_004650a0(int aiValue);
};

struct SLSky
{
    void FUN_004ba7d0();
};

struct SLTES
{
    void AssignWorldSpace(SLWorldSpace* apWorld);
    void SetPosition(SLPoint3* apPos);
    void SetInteriorCell(SLCell* apCell, SLPoint3* apPos);
    void LoadArea(SLPoint3* apPos, bool abFlag);
    SLSky* GetSky();
};

struct SLSetting
{
    const char* GetString();
};

unsigned int __cdecl BSStringLength(const char* apString);
const char* __cdecl PrepareScriptMessage(const char* apString, bool abFlag);
void __cdecl FNV_Warning(const char* apFormat, ...);
long __cdecl SLStrToLong(const char* apString);
int __cdecl SLStrICmp(const char* apString1, const char* apString2);

extern SLDataHandler* g_pSLDataHandler;
extern SLTES* g_pSLTES;
extern SLSetting g_kStartingCell;
extern SLSetting g_kStartingCellX;
extern SLSetting g_kStartingCellY;
extern SLSetting g_kStartingWorld;
extern double g_dCellHalfSize;

// Resolves the starting cell from a name or the starting-cell INI settings, positions the player there, and warns if the cell cannot be found.
// @fnv 0x00876dd0
void __cdecl FUN_00876dd0(const char* apCellName, SLPoint3* apPos)
{
    SLCell* pCell4 = 0;
    bool bWarn = true;
    bool bLoad7 = true;

    if ((apCellName && BSStringLength(apCellName)) || strlen(g_kStartingCell.GetString()))
    {
        if (apCellName && BSStringLength(apCellName))
            pCell4 = g_pSLDataHandler->GetCellByName(apCellName);
        else
            pCell4 = g_pSLDataHandler->GetCellByName(PrepareScriptMessage(g_kStartingCell.GetString(), false));
        if (!pCell4)
        {
            int iX = 0;
            int iY4 = 0;
            SLWorldSpace* pWorld8 = g_pSLDataHandler->GetWorldSpaceForCell(
                PrepareScriptMessage(g_kStartingCell.GetString(), false), &iX, &iY4);
            if (pWorld8)
            {
                g_pSLTES->AssignWorldSpace(pWorld8);
                apPos->x = (iX << 12) + g_dCellHalfSize;
                apPos->y = (iY4 << 12) + g_dCellHalfSize;
                apPos->z = 0.0f;
                g_pSLTES->SetPosition(apPos);
                pCell4 = g_pSLDataHandler->GetContainingCell(iX, iY4, pWorld8, false);
                bLoad7 = false;
            }
        }
    }
    else if (strlen(g_kStartingCellX.GetString()) && strlen(g_kStartingCellY.GetString()))
    {
        int m_iGridPositionX = SLStrToLong(PrepareScriptMessage(g_kStartingCellX.GetString(), false));
        int iCellY8 = SLStrToLong(PrepareScriptMessage(g_kStartingCellY.GetString(), false));
        SLWorldSpace* pWorldA = *g_pSLDataHandler->GetWorldSpaces()->GetItem();
        SLWorldSpaceList* pIter_ = g_pSLDataHandler->GetWorldSpaces();
        while (pIter_ && !pIter_->IsEmpty())
        {
            SLWorldSpace* m_pContainingWorldspace = *pIter_->GetItem();
            if (!SLStrICmp(m_pContainingWorldspace->GetEditorID(), g_kStartingWorld.GetString()))
            {
                pWorldA = m_pContainingWorldspace;
                break;
            }
            pIter_ = pIter_->GetNext();
        }
        if (pWorldA)
        {
            pCell4 = pWorldA->GetCellAtCoords(m_iGridPositionX, iCellY8);
            if (!pCell4)
                pCell4 = g_pSLDataHandler->GetContainingCell(m_iGridPositionX, iCellY8, pWorldA, true);
        }
    }
    else
    {
        bWarn = false;
        bLoad7 = false;
    }

    if (bLoad7)
    {
        if (pCell4)
        {
            if (pCell4->IsInterior())
            {
                g_pSLTES->SetInteriorCell(pCell4, apPos);
            }
            else
            {
                g_pSLTES->AssignWorldSpace(pCell4->GetParentWorldSpace());
                apPos->x = (pCell4->GetPosX() << 12) + g_dCellHalfSize;
                apPos->y = (pCell4->GetPosY() << 12) + g_dCellHalfSize;
                apPos->z = 0.0f;
                g_pSLTES->SetPosition(apPos);
            }
            bLoad7 = false;
        }
        else if (bWarn)
        {
            if (g_kStartingCell.GetString() && *g_kStartingCell.GetString())
            {
                FNV_Warning("CELLS: Could not find starting cell '%s'.", g_kStartingCell.GetString());
            }
            else if (g_kStartingCellX.GetString() && g_kStartingCellY.GetString() && *g_kStartingCellX.GetString() &&
                     *g_kStartingCellY.GetString())
            {
                if (g_kStartingWorld.GetString() && *g_kStartingWorld.GetString())
                    FNV_Warning("CELLS: Could not find starting cell (%s, %s) in worldspace '%s'.",
                                g_kStartingCellX.GetString(), g_kStartingCellY.GetString(),
                                g_kStartingWorld.GetString());
                else
                    FNV_Warning("CELLS: Could not find starting cell (%s, %s) in default Tamriel worldspace",
                                g_kStartingCellX.GetString(), g_kStartingCellY.GetString());
            }
            else
            {
                FNV_Warning("CELLS: Could not find starting cell for INI data.");
            }
        }
        g_pSLDataHandler->FUN_004650a0(-1);
        if (bLoad7)
        {
            g_pSLTES->LoadArea(apPos, true);
            g_pSLTES->GetSky()->FUN_004ba7d0();
        }
    }
}

namespace fnv_008774a0 {
struct FUN_009611e0_ctrl
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058(void* apNode);
};

struct FUN_008774a0_node
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual FUN_008774a0_node* v003();
    FUN_009611e0_ctrl* FUN_009611e0();
};

struct FUN_0054ca90_cell
{
    void FUN_0054ca90(void* apRef);
};

struct FUN_008774a0_player
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
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
    virtual void v115(int a1, int a2);
    void FUN_00877700();
    FUN_0054ca90_cell* FUN_008d6f30();
    FUN_008774a0_node* FUN_00950bb0(bool abFirstPerson);
};

struct FUN_007d6bd0_save
{
    bool FUN_007d6bd0(bool abFlag);
    void FUN_0084a840();
};

struct FUN_004539a0_tes
{
    void FUN_004539a0(int a1, int a2);
    void FUN_007037c0(int aiValue);
    void FUN_0061cc40(int aiValue);
    void FUN_0045ac80();
};

struct FUN_00ad8780_audio
{
    void FUN_00ad8780(int aiValue);
};
struct FUN_006c09f0_mgr
{
    void FUN_006c09f0();
};
struct FUN_00970d50_lists
{
    void FUN_00970d50();
};
struct FUN_004614e0_dh
{
    void FUN_004614e0();
};
struct FUN_00b631d0_obj
{
    void FUN_00b631d0();
};

FUN_00ad8780_audio* FUN_00453a70();
void __cdecl FUN_008324e0(int aiValue);
FUN_006c09f0_mgr* GetNavMeshObstacleManager();
void FUN_00868d70(int aiValue);
void FUN_00c459d0(int aiValue);
FUN_00b631d0_obj* FUN_00b4f5c0();
void __cdecl FUN_0040fbe0();
void FUN_00706320(int aiValue);
void __cdecl FUN_007053f0();

extern FUN_008774a0_player* DAT_011dea3c;
extern FUN_007d6bd0_save* DAT_011ddf38;
extern FUN_004539a0_tes* DAT_011dea10;
extern FUN_004614e0_dh* DAT_011c3f2c;

struct FUN_008774a0_shell
{
    bool FUN_004f1540();
    void FUN_004f15a0(int aiValue);
    void FUN_008776e0();
    void FUN_008774a0(bool abFlag);
};

extern FUN_008774a0_shell* DAT_011dea0c;

// @fnv 0x008774a0
void FUN_008774a0_shell::FUN_008774a0(bool abFlag)
{
    bool bState = FUN_004f1540();
    FUN_004f15a0(0);
    DAT_011dea3c->FUN_00877700();
    bool bSaveFlag = DAT_011ddf38->FUN_007d6bd0(false);
    FUN_00453a70()->FUN_00ad8780(-1);
    FUN_008324e0(0);
    if (DAT_011dea3c->FUN_008d6f30())
        DAT_011dea3c->FUN_008d6f30()->FUN_0054ca90(DAT_011dea3c);

    FUN_008774a0_node* pNode = DAT_011dea3c->FUN_00950bb0(true);
    FUN_008774a0_node* pRoot = pNode ? pNode->v003() : 0;
    if (pRoot && pRoot->FUN_009611e0())
        pRoot->FUN_009611e0()->v058(pNode);
    pNode = DAT_011dea3c->FUN_00950bb0(false);
    pRoot = pNode ? pNode->v003() : 0;
    if (pRoot && pRoot->FUN_009611e0())
        pRoot->FUN_009611e0()->v058(pNode);

    DAT_011dea10->FUN_004539a0(0, 0);
    DAT_011dea10->FUN_007037c0(0x7fffffff);
    DAT_011dea10->FUN_0061cc40(0x7fffffff);
    GetNavMeshObstacleManager()->FUN_006c09f0();
    FUN_00868d70(0);
    FUN_00c459d0(0);
    DAT_011dea3c->v115(0, 0);
    DAT_011ddf38->FUN_0084a840();
    ((FUN_00970d50_lists*)&DAT_011e0e80)->FUN_00970d50();
    DAT_011c3f2c->FUN_004614e0();
    FUN_00b4f5c0()->FUN_00b631d0();
    FUN_0040fbe0();
    FUN_00706320(0);
    DAT_011dea10->FUN_0045ac80();
    if (abFlag)
        FUN_007053f0();
    DAT_011ddf38->FUN_007d6bd0(bSaveFlag);
    DAT_011dea0c->FUN_008776e0();
    DAT_011dea0c->FUN_004f15a0(bState);
}
}  // namespace fnv_008774a0

namespace fnv_00873200 {
// Scene traversal, visibility batching, and the main and auxiliary render passes.
// Local-name suffixes preserve the VC++ 2008 stack-slot allocation.

struct ViewNode;
struct ViewGeometry;
struct ViewList;
struct ViewHandle
{
    ViewNode* value;
    ViewNode* FUN_00559450();
};
struct ViewList
{
    void* FUN_00559450();
    ViewHandle* FUN_0057cbe0(void** position);
    bool FUN_0076b610();
};
struct ViewNode
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual ViewNode* AsNode();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void SetCamera(ViewNode* camera);
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
    bool m_38;
    unsigned char unk39;
    bool m_3a;
    ViewNode* FUN_008d80e0();
    ViewNode* FUN_006629f0();
    ViewNode* FUN_00950bb0(bool);
    bool FUN_00456610();
    void FUN_00450f90(bool);
    ViewNode* FUN_004ebbc0(int);
    bool FUN_00871220();
    void FUN_0041fd00(ViewNode*);
    void* FUN_0045bbe0();
    void FUN_00a694a0(void*);
    void FUN_004a0fd0(ViewNode*);
    ViewNode* FUN_0045bc00(unsigned int);
    unsigned int FUN_0043b480();
    ViewNode* FUN_0043b4a0(unsigned int);
    ViewNode* FUN_005f36f0();
    bool FUN_00874650();
    ViewNode* FUN_00454b30();
    ViewList* FUN_00436aa0();
    ViewList* FUN_006ab360();
    ViewGeometry* FUN_0045c4c0();
    bool FUN_00c4f320(ViewGeometry*);
    int FUN_00874480();
    int FUN_009b4440();
    ViewNode* FUN_0084e3a0();
    void FUN_00b5ba80(ViewNode*, ViewNode*);
    ViewList* FUN_007d6bb0();
    ViewNode* FUN_00457070();
    ViewNode* FUN_009d9f20();
    unsigned int FUN_00c5b5d0();
    ViewNode* FUN_00c5b5a0(int);
    void FUN_00b5e870(ViewNode*);
    ViewNode* FUN_00874670();
    void FUN_00c49850();
    void FUN_004dc540(ViewNode*);
    void FUN_00a89af0(ViewNode*);
    void FUN_004fb0b0(bool);
    void FUN_00642860();
    void FUN_006426a0(bool, ViewNode*, ViewNode*);
    int* FUN_0043d4d0();
};
struct ViewGeometry : ViewNode
{
};
struct VisibleList
{
    int unk00;
    int unk04;
    int unk08;
    VisibleList();
    ~VisibleList();
    void FUN_004ed8c0(ViewNode* const&);
    void FUN_004ed900();
};
struct MemoryContext
{
    int unk00;
    MemoryContext(int, bool, const char*, int);
    ~MemoryContext();
    void FUN_00404f70();
};
struct LocalCull
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
    LocalCull(void*);
    ~LocalCull();
    void FUN_0041fd00(ViewNode*);
    void FUN_004a0fd0(ViewNode*);
    void FUN_00874460(ViewNode*);
};
struct RenderSystem
{
    void FUN_00ba3390(ViewNode*, ViewNode*, int, VisibleList*, int, ViewNode*, int, int, bool);
    void FUN_00ba30f0(int, int);
    void FUN_00ba3130(int, int);
};
struct InterfaceSystem
{
    void FUN_00800f30(int, int, int, int, int, int);
};
ViewNode* FUN_0045c670();
ViewNode* FUN_004e3270();
ViewNode* FUN_00450b80(int);
ViewNode* FUN_0043c4b0();
RenderSystem* FUN_004ea970();
InterfaceSystem* FUN_00705910();
ViewNode* FUN_00874690();
ViewNode* FUN_008746b0();
ViewNode* FUN_008746a0();
ViewNode* FUN_005bac50();
void* FUN_004a0e90();
void FUN_008746c0();
void FUN_00b54ac0(ViewNode*);
void FUN_00b6bfc0(ViewNode*, VisibleList*, LocalCull*);
void FUN_00b6bee0(ViewNode*, ViewNode*, ViewNode*);
void FUN_00b6ba20(ViewNode*, ViewNode*, bool);
void FUN_00b6b930(ViewNode*, ViewNode*, bool);
void FUN_00b6c0d0(ViewNode*, ViewNode*, bool);
void FUN_00b98380(int, int);
void FUN_004eced0(int);
void FUN_00b803b0(ViewNode*);
void FUN_008c80e0(int);
void FUN_008744a0(ViewNode*);
void FUN_00872dd0(bool, bool);
extern ViewNode* DAT_011dea3c;
extern ViewNode* DAT_011dea10;
extern ViewHandle DAT_011deb7c;
extern ViewNode DAT_011c3ea4;
extern ViewNode* DAT_011f9684;
extern bool DAT_011f94b4;
extern bool DAT_011f94a9;
extern const char DAT_010829c4[];
extern __declspec(thread) int DAT_012722bc;
struct MainView
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
    ViewHandle m_88;
    ViewHandle m_8c;
    int unk90;
    ViewHandle m_94;
    void FUN_00873200(ViewNode* listener, int unused, bool hide, bool drawInterface);
};
// Builds visible lists from the scene graph, renders the main view and secondary passes, and restores the saved visibility state.
// @fnv 0x00873200
void MainView::FUN_00873200(ViewNode* listener, int unused, bool hide, bool drawInterface)
{
    ViewNode* root3 = FUN_0045c670();
    ViewNode* process = root3->FUN_008d80e0();
    ViewNode* otherProcess;
    ViewNode* cameraX;
    void* renderer2;
    DAT_011f9684 = root3->FUN_006629f0();
    if (listener)
        listener->FUN_00642860();
    bool savedVisibility = DAT_011dea3c->FUN_00950bb0(true)->FUN_00456610();
    DAT_011dea3c->FUN_00950bb0(true)->FUN_00450f90(true);
    m_88.FUN_00559450()->m_38 = !hide;
    ViewNode* imageEffect5 = FUN_004e3270()->FUN_004ebbc0(4);
    m_88.FUN_00559450()->m_3a = !hide && imageEffect5->FUN_00871220();
    m_8c.FUN_00559450()->m_3a = !hide && imageEffect5->FUN_00871220();
    MemoryContext memory7(15, true, DAT_010829c4, 0x1eb7);
    cameraX = 0;
    cameraX = root3->FUN_006629f0();
    process->FUN_0041fd00(cameraX);
    process->FUN_00a694a0(cameraX->FUN_0045bbe0());
    process->FUN_004a0fd0(m_88.FUN_00559450());
    // Partition visible objects between the two culling passes.
    if (DAT_011f94b4)
    {
        VisibleList leftList2;
        VisibleList rightList4;
        VisibleList commonList3;
        ViewNode* graph = FUN_00450b80(0);
        ViewNode* node2 = 0;
        ViewNode* branch = 0;
        node2 = graph->FUN_0045bc00(0);
        if (node2 && !node2->FUN_00456610())
            commonList3.FUN_004ed8c0(node2);
        node2 = graph->FUN_0045bc00(1);
        if (node2 && !node2->FUN_00456610())
            commonList3.FUN_004ed8c0(node2);
        node2 = graph->FUN_0045bc00(2);
        if (node2 && !node2->FUN_00456610())
            branch = node2->AsNode();
        if (branch)
        {
            node2 = branch->FUN_0045bc00(0);
            if (node2 && !node2->FUN_00456610())
                leftList2.FUN_004ed8c0(node2);
            node2 = branch->FUN_0045bc00(1);
            if (node2 && !node2->FUN_00456610())
                leftList2.FUN_004ed8c0(node2);
            node2 = branch->FUN_0045bc00(2);
            if (node2 && !node2->FUN_00456610())
                leftList2.FUN_004ed8c0(node2);
        }
        node2 = graph->FUN_0045bc00(3);
        branch = node2->AsNode();
        // Exterior and interior scenes organize their child nodes differently.
        if (!DAT_011dea10->FUN_005f36f0())
        {
            if (branch && !branch->FUN_00456610())
            {
                for (int i = 0; i < branch->FUN_0043b480(); ++i)
                {
                    node2 = branch->FUN_0043b4a0(i);
                    if (node2)
                    {
                        ViewNode* section = node2->AsNode();
                        if (section && !section->FUN_00456610())
                        {
                            for (int j = 0; j < section->FUN_0043b480(); ++j)
                            {
                                ViewNode* item = section->FUN_0043b4a0(j);
                                if (item)
                                {
                                    ViewNode* nested = item->AsNode();
                                    if (nested)
                                    {
                                        if (!nested->FUN_00456610())
                                        {
                                            int k = 0;
                                            if (j == 6)
                                                k = 1;
                                            for (; k < nested->FUN_0043b480(); ++k)
                                            {
                                                ViewNode* leaf = nested->FUN_0043b4a0(k);
                                                if (leaf && !leaf->FUN_00456610())
                                                {
                                                    if (i % 2)
                                                        leftList2.FUN_004ed8c0(leaf);
                                                    else
                                                        rightList4.FUN_004ed8c0(leaf);
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (i % 2)
                                            leftList2.FUN_004ed8c0(item);
                                        else
                                            rightList4.FUN_004ed8c0(item);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            if (FUN_00450b80(0)->FUN_00874650())
            {
                node2 = branch->FUN_0045bc00(0);
                if (node2 && !node2->FUN_00456610())
                    rightList4.FUN_004ed8c0(node2);
                node2 = branch->FUN_0045bc00(1);
                if (node2 && !node2->FUN_00456610())
                    leftList2.FUN_004ed8c0(node2);
                node2 = branch->FUN_0045bc00(2);
                if (node2)
                {
                    branch = node2->AsNode();
                    if (branch && !branch->FUN_00456610())
                    {
                        for (int outerIndex = 0; outerIndex < branch->FUN_0043b480(); ++outerIndex)
                        {
                            node2 = branch->FUN_0043b4a0(outerIndex);
                            if (node2 && outerIndex != 4 && outerIndex != 0)
                            {
                                ViewNode* section2 = node2->AsNode();
                                if (section2 && !section2->FUN_00456610())
                                {
                                    int childIndex = 0;
                                    if (outerIndex == 6)
                                        childIndex = 1;
                                    for (; childIndex < section2->FUN_0043b480(); ++childIndex)
                                    {
                                        ViewNode* leaf2 = section2->FUN_0043b4a0(childIndex);
                                        if (leaf2 && !leaf2->FUN_00456610())
                                        {
                                            if (childIndex % 2)
                                                leftList2.FUN_004ed8c0(leaf2);
                                            else
                                                rightList4.FUN_004ed8c0(leaf2);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                node2 = branch->FUN_0045bc00(2);
                if (node2)
                {
                    branch = node2->AsNode();
                    if (branch && !branch->FUN_00456610())
                    {
                        node2 = branch->FUN_0045bc00(7);
                        if (node2)
                        {
                            branch = node2->AsNode();
                            if (branch)
                            {
                                for (int index3 = 0; index3 < branch->FUN_0043b480(); ++index3)
                                {
                                    ViewNode* leaf3 = branch->FUN_0043b4a0(index3);
                                    if (leaf3 && !leaf3->FUN_00456610())
                                    {
                                        if (index3 % 2)
                                            leftList2.FUN_004ed8c0(leaf3);
                                        else
                                            rightList4.FUN_004ed8c0(leaf3);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            ViewNode* area = FUN_00450b80(0)->FUN_00454b30();
            ViewList* roomsTmp = area ? area->FUN_00436aa0() : 0;
            void* roomPosition4 = roomsTmp ? roomsTmp->FUN_00559450() : 0;
            int visibleCount = 0;
            while (roomPosition4)
            {
                ViewNode* room = area->FUN_00436aa0()->FUN_0057cbe0(&roomPosition4)->FUN_00559450();
                if (room && !room->FUN_006ab360()->FUN_0076b610())
                {
                    void* itemPosition = room->FUN_006ab360()->FUN_00559450();
                    while (itemPosition)
                    {
                        ViewNode* object = room->FUN_006ab360()->FUN_0057cbe0(&itemPosition)->value;
                        if (object && process->FUN_00c4f320(object->FUN_0045c4c0()))
                        {
                            ViewGeometry* geometry = object->FUN_0045c4c0();
                            if (geometry)
                            {
                                if (object->FUN_00874480() && object->FUN_009b4440())
                                {
                                    FUN_00450b80(0)->FUN_00b5ba80(process->FUN_0084e3a0(), object);
                                }
                                if (visibleCount % 2)
                                    leftList2.FUN_004ed8c0(geometry);
                                else
                                    rightList4.FUN_004ed8c0(geometry);
                                ++visibleCount;
                            }
                        }
                    }
                }
            }
            if (FUN_00450b80(0)->FUN_00874650())
            {
                void* objectPosition = area->FUN_007d6bb0()->FUN_00559450();
                while (objectPosition)
                {
                    ViewNode* object2 = area->FUN_007d6bb0()->FUN_0057cbe0(&objectPosition)->value;
                    if (object2 && process->FUN_00c4f320(object2->FUN_0045c4c0()))
                    {
                        ViewGeometry* geometry2 = object2->FUN_0045c4c0();
                        if (geometry2)
                        {
                            if (visibleCount % 2)
                                leftList2.FUN_004ed8c0(geometry2);
                            else
                                rightList4.FUN_004ed8c0(geometry2);
                            ++visibleCount;
                        }
                    }
                }
            }
            ViewNode* extra6 = DAT_011dea10->FUN_00457070()->FUN_009d9f20();
            if (extra6)
            {
                for (int extraIndex = 0; extraIndex < extra6->FUN_00c5b5d0(); ++extraIndex)
                {
                    ViewNode* extraNode = extra6->FUN_00c5b5a0(extraIndex);
                    if (extraNode)
                        commonList3.FUN_004ed8c0(extraNode);
                }
            }
        }
        node2 = graph->FUN_0045bc00(4);
        if (node2 && !node2->FUN_00456610())
            commonList3.FUN_004ed8c0(node2);
        node2 = graph->FUN_0045bc00(5);
        if (node2 && !node2->FUN_00456610())
            commonList3.FUN_004ed8c0(node2);
        node2 = graph->FUN_0045bc00(6);
        if (node2 && !node2->FUN_00456610())
            leftList2.FUN_004ed8c0(node2);
        for (int tailIndex = 7; tailIndex < graph->FUN_0043b480(); ++tailIndex)
        {
            node2 = graph->FUN_0043b4a0(tailIndex);
            if (node2 && !node2->FUN_00456610())
            {
                if (tailIndex % 2)
                    leftList2.FUN_004ed8c0(node2);
                else
                    rightList4.FUN_004ed8c0(node2);
            }
        }
        process->FUN_0041fd00(cameraX);
        FUN_00450b80(0)->FUN_00b5e870(process);
        if (FUN_00450b80(0)->FUN_00874670())
            FUN_00450b80(0)->FUN_00874670()->FUN_00c49850();
        m_88.FUN_00559450()->SetCamera(cameraX);
        FUN_00b54ac0(m_88.FUN_00559450());
        FUN_0043c4b0()->FUN_004dc540(m_88.FUN_00559450());
        FUN_004ea970()->FUN_00ba3390(cameraX, FUN_00450b80(0)->FUN_00874670(), 0, &leftList2, 0, m_88.FUN_00559450(), 0,
                                     21, true);
        FUN_004ea970()->FUN_00ba30f0(0, 21);
        DAT_012722bc = 0;
        LocalCull localProcess(0);
        localProcess.FUN_0041fd00(cameraX);
        localProcess.FUN_004a0fd0(m_88.FUN_00559450());
        localProcess.FUN_00874460(FUN_00450b80(0)->FUN_00874670());
        FUN_00b6bfc0(cameraX, &rightList4, &localProcess);
        localProcess.FUN_00874460(0);
        FUN_00b6bfc0(cameraX, &commonList3, &localProcess);
        FUN_004ea970()->FUN_00ba3130(1, 21);
        leftList2.FUN_004ed900();
        rightList4.FUN_004ed900();
    }
    else
    {
        FUN_00b6bee0(cameraX, root3, process);
    }
    // Finish the main scene and draw the requested interface layer.
    FUN_00b6ba20(root3->FUN_006629f0(), m_88.FUN_00559450(), true);
    if (drawInterface)
    {
        FUN_00b98380(0, 1);
        FUN_00705910()->FUN_00800f30(0, 2, 1, 0, 0, 0);
        FUN_004eced0(1);
    }
    FUN_00b6b930(root3->FUN_006629f0(), m_88.FUN_00559450(), true);
    if (DAT_011f94b4)
        FUN_00450b80(0)->FUN_00a89af0(process);
    process->FUN_004a0fd0(0);
    memory7.FUN_00404f70();
    m_88.FUN_00559450()->m_38 = false;
    m_88.FUN_00559450()->m_3a = false;
    FUN_008746c0();
    // Render the auxiliary scene views through the secondary culling process.
    renderer2 = FUN_004a0e90();
    otherProcess = FUN_0045c670()->FUN_008d80e0();
    otherProcess->FUN_004fb0b0(true);
    FUN_00b803b0(DAT_011deb7c.FUN_00559450()->FUN_006629f0());
    otherProcess->FUN_0041fd00(FUN_00874690());
    otherProcess->FUN_004a0fd0(m_94.FUN_00559450());
    FUN_00b6bee0(FUN_00874690(), FUN_005bac50(), otherProcess);
    FUN_00b6c0d0(FUN_00874690(), m_94.FUN_00559450(), false);
    process->FUN_004a0fd0(0);
    otherProcess->FUN_004fb0b0(false);
    FUN_008746c0();
    renderer2 = FUN_004a0e90();
    otherProcess = FUN_0045c670()->FUN_008d80e0();
    otherProcess->FUN_004fb0b0(true);
    FUN_00b803b0(DAT_011deb7c.FUN_00559450()->FUN_006629f0());
    otherProcess->FUN_0041fd00(FUN_008746b0());
    otherProcess->FUN_004a0fd0(m_94.FUN_00559450());
    FUN_00b6bee0(FUN_008746b0(), FUN_008746a0(), otherProcess);
    FUN_00b6c0d0(FUN_008746b0(), m_94.FUN_00559450(), false);
    process->FUN_004a0fd0(0);
    otherProcess->FUN_004fb0b0(false);
    if (*DAT_011c3ea4.FUN_0043d4d0() > 1)
        FUN_008c80e0(0);
    if (DAT_011f94a9)
        FUN_008744a0(root3->FUN_006629f0());
    if (listener)
        listener->FUN_006426a0(true, m_88.FUN_00559450(), DAT_011deb7c.FUN_00559450()->FUN_006629f0());
    FUN_00872dd0(false, false);
    DAT_011dea3c->FUN_00950bb0(true)->FUN_00450f90(savedVisibility);
}
}  // namespace fnv_00873200

namespace fnv_00877730 {
struct GlobalObject_0045cf30;
class ImageSpaceManager;
struct AutoMemHelper
{
    unsigned int previousContext;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
union SETTING_VALUE
{
    bool b;
    int i;
};

struct NiUpdateData
{
    NiUpdateData(float f, bool bb, bool g);
    float m_f;
    bool m_kPointB;
    bool m_g;
    bool flag06, flag07, flag08;
};

struct NiObject;
struct TESLevItem;
class NiNode
{
  public:
    void Update(const NiUpdateData& data);
    void FUN_00a5a040();
    void AttachProperty(NiObject* p);
};

struct GO00
{
    NiNode* FUN_00559450();
};
struct GO34
{
    NiNode* FUN_00559450();
};
struct GOa4
{
    NiNode* FUN_00559450();
};
extern GO00 DAT_011deb00;
extern GO34 DAT_011deb34;
extern GOa4 g_011deda4;
extern GO34 DAT_011deb34;

class INISettingCollection;
template <class Collection> class SettingT
{
  public:
    SETTING_VALUE* Bool();
};
extern GlobalObject_0045cf30 g_011deadc;

struct ProcObj
{
    void FUN_0063a630(void* a, void* b);
    void* FUN_0045cd60();
    void* FUN_004505a0();
};
extern ProcObj* DAT_011dea20;

struct ModelOps
{
    void* FUN_0043b230();
};

struct FUN_0049ec80_Property : NiRefObject
{
    void* unknown08;
    void* unknown0c;
    void* unknown10;
    unsigned int unknown14;
    unsigned short flags18;
    unsigned char alphaThreshold1a;
    unsigned char unknown1b;
    unsigned int unknown1c;
    unsigned int unknown20;
    FUN_0049ec80_Property();
    void FUN_0049ed90(bool b);
    void FUN_0049ede0(unsigned int value);
    void FUN_0050f9a0(unsigned int value);
};
typedef FUN_0049ec80_Property NiAlphaProperty;
struct HostV
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37(void* p, int i);
};

struct LightShell
{
    void FUN_00b5aac0(void* p);
};

struct ISM2
{
    void FUN_00b8b200(bool b);
};

void FUN_0040fbe0(const char* s);
LightShell* FUN_00450b80(unsigned int i);
ImageSpaceManager* FUN_004e3270();
void FUN_00b57e30(void* p, int a, int b);

// @fnv 0x00877730
void FUN_00877730()
{
    AutoMemHelper helper8(0x21, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 0x26bd);
    FUN_0040fbe0("Initializing Sky...");
    DAT_011dea20->FUN_0063a630(DAT_011deb34.FUN_00559450(), DAT_011deb00.FUN_00559450());
    ((HostV*)g_011deda4.FUN_00559450())->v37(((ModelOps*)(void*)DAT_011dea20->FUN_0045cd60())->FUN_0043b230(), 1);
    ((LightShell*)FUN_00450b80(0))->FUN_00b5aac0((void*)DAT_011dea20->FUN_004505a0());
    DAT_011deb34.FUN_00559450()->FUN_00a5a040();
    ((ISM2*)FUN_004e3270())->FUN_00b8b200(((SettingT<INISettingCollection>*)&g_011deadc)->Bool()->b);
    if (((SettingT<INISettingCollection>*)&g_011deadc)->Bool()->b)
    {
        NiAlphaProperty* obj = new NiAlphaProperty;
        ((NiAlphaProperty*)obj)->FUN_0049ed90(true);
        obj->FUN_0049ede0(2);
        obj->FUN_0050f9a0(0xff);
        DAT_011deb34.FUN_00559450()->AttachProperty((NiObject*)obj);
    }
    NiUpdateData upd1(0.0f, false, false);
    DAT_011deb34.FUN_00559450()->Update(upd1);
    g_011deda4.FUN_00559450()->FUN_00a5a040();
    NiUpdateData updTmp(0.0f, false, false);
    g_011deda4.FUN_00559450()->Update(updTmp);
    FUN_00b57e30(DAT_011deb34.FUN_00559450(), 0, 0);
    FUN_00b57e30(((ModelOps*)(void*)DAT_011dea20->FUN_0045cd60())->FUN_0043b230(), 0, 0);
}
}  // namespace fnv_00877730

struct IDIDevice8
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall GetCapabilities(void* caps);
    virtual long __stdcall EnumObjects(void* cb, void* ref, unsigned long flags);
    virtual long __stdcall GetProperty(const void* guid, void* prop);
    virtual long __stdcall SetProperty(const void* guid, const void* prop);
    virtual long __stdcall Acquire();
    virtual long __stdcall Unacquire();
    virtual long __stdcall GetDeviceState(unsigned long cb, void* data);
    virtual long __stdcall GetDeviceData(unsigned long cbObjectData, void* rgdod, unsigned long* pdwInOut,
                                         unsigned long flags);
};
struct DIDeviceOwner
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
    IDIDevice8* m_pDirectInputDevice;
    void FUN_00a237b0();
};
// @fnv 0x00a237b0
void DIDeviceOwner::FUN_00a237b0()
{
    if (m_pDirectInputDevice)
    {
        unsigned long dwItems = 0xffffffff;
        m_pDirectInputDevice->GetDeviceData(0x14, 0, &dwItems, 0);
    }
}

extern short DAT_011f35b0;
extern short DAT_011f35b2;
extern short DAT_011f35b4;
extern short DAT_011f35b6;
extern bool DAT_011f35c8;

struct FUN_00a23390_t
{
    int GetAxisState(int device, int axis);
};

// Returns the state of the specified controller axis, reading from per-device state or global fallback values for axes 7-10.
// @fnv 0x00a23390
int FUN_00a23390_t::GetAxisState(int device, int axis)
{
    int* pAxisState = (int*)((char*)this + device * 0xa0 + 0x34);
    switch (axis)
    {
    case 1:
        return pAxisState[0];
    case 2:
        return pAxisState[1];
    case 3:
        return pAxisState[2];
    case 4:
        return pAxisState[3];
    case 5:
        return pAxisState[4];
    case 6:
        return pAxisState[5];
    case 7:
        if (DAT_011f35c8)
            return DAT_011f35b0;
        break;
    case 8:
        if (DAT_011f35c8)
            return DAT_011f35b2;
        break;
    case 9:
        if (DAT_011f35c8)
            return DAT_011f35b4;
        break;
    case 10:
        if (DAT_011f35c8)
            return DAT_011f35b6;
        break;
    }
    return 0;
}

namespace sa238a0 {

extern unsigned char DAT_011a7440[256];
extern unsigned char DAT_011a7540[256];
extern unsigned char DAT_011a7640[256];
extern unsigned char DAT_011a7740[256];
extern unsigned char DAT_011a7840[256];
extern unsigned char DAT_011a7940[256];
extern unsigned char DAT_011a7a40[256];
extern unsigned char DAT_011a7b40[256];
extern unsigned char DAT_011a7c40[256];
extern unsigned char DAT_011a7d40[256];

int FUN_00a22cb0();

struct CharTable
{
    int FUN_00a238a0(int iChar, int iMode);
};

// Bounds-checks iChar, then returns a byte from a 256-entry table selected by iMode and FUN_00a22cb0().
// @fnv 0x00a238a0
int CharTable::FUN_00a238a0(int iChar, int iMode)
{
    if (iChar < 0 || iChar > 0xff)
        return -1;
    if (iMode == 0xff)
        return DAT_011a7540[iChar];
    switch (FUN_00a22cb0())
    {
    case 3:
        return iMode ? DAT_011a7b40[iChar] : DAT_011a7a40[iChar];
    case 4:
        return iMode ? DAT_011a7d40[iChar] : DAT_011a7c40[iChar];
    case 2:
        return iMode ? DAT_011a7940[iChar] : DAT_011a7840[iChar];
    case 1:
        return iMode ? DAT_011a7740[iChar] : DAT_011a7640[iChar];
    default:
        return iMode ? DAT_011a7540[iChar] : DAT_011a7440[iChar];
    }
}

}

namespace fnv_00872b00 {
struct ImageSpaceEffectParam
{
    float f0;
    float f4;
    float f8;
    float fC;
    ImageSpaceEffectParam(float a, float b, float c, float d);
};
struct NiUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool bIsMultiThreaded;
    int iFlags;
    NiUpdateData(float t, bool a, bool b);
};
struct ISMgr
{
    void FUN_00712e60(const ImageSpaceEffectParam& p);
};
struct ISHolder
{
    void SetCameraFOV(float f, int a, int b, bool c);
};
extern ImageSpaceEffectParam DAT_011ad840;
struct StateObj
{
    unsigned int CallGetFlags();
};
extern StateObj DAT_011f2250;
struct PlayerCharacter;
float __fastcall FUN_00710ab0(PlayerCharacter* p);
extern PlayerCharacter* g_thePlayer;
struct BSShaderManager
{
    static void __cdecl SetFOV(float f);
};
struct NiCamera;
struct NiAVObject
{
    NiPoint3& FUN_0043c490();
    void FUN_00440460(const NiPoint3& p);
    void Update(NiUpdateData& d);
};
struct CamNode
{
    NiAVObject* FUN_00558310();
    NiCamera* GetAnimationData();
};
struct CamNodePtr
{
    operator CamNode*() const;
};
struct NodePtr
{
    operator NiAVObject*() const;
};
extern CamNodePtr g_011deb7c;
extern NodePtr g_011deb34;
extern NodePtr g_011deda4;
struct BoolSetting
{
    bool* Bool();
};
extern BoolSetting g_011ded80;
extern BoolSetting g_011decd8;
extern BoolSetting g_011deb60;
struct CamWatcher
{
    int unk00;
    CamWatcher();
    ~CamWatcher();
    void FUN_008d6f50(NiCamera* cam);
};
extern unsigned char DAT_011f9fc0;
extern unsigned char DAT_011f9fc1;
extern unsigned char DAT_011f94a5;
void __cdecl FUN_00872dd0(bool a, bool b);
void __cdecl FUN_00872df0(bool a);
struct Sky
{
    void* FUN_0045cd60();
    int FUN_00476c90();
};
struct TES
{
    Sky* FUN_008d8520();
};
extern TES* g_TES;

struct MainX
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
    bool bFlag9C;
    void* UpdateCamera();
};

// Applies image-space parameters, sets FOV, updates two scene objects from camera data, and returns a sky-provided pointer when conditions match.
// @fnv 0x00872b00
void* MainX::UpdateCamera()
{
    ((ISMgr*)FUN_0045c670()->GetAnimationData())->FUN_00712e60(DAT_011ad840);
    if (DAT_011f2250.CallGetFlags() != 4)
    {
        ((ISHolder*)FUN_0045c670())->SetCameraFOV(FUN_00710ab0(g_thePlayer), 0, 0, true);
    }
    BSShaderManager::SetFOV(FUN_00710ab0(g_thePlayer));
    if (bFlag9C)
    {
        ((ISMgr*)FUN_0045c670()->GetAnimationData())->FUN_00712e60(ImageSpaceEffectParam(0.0f, 1.0f, 1.0f, 0.0f));
    }
    NiCamera* pCamera = ((CamNode*)g_011deb7c)->GetAnimationData();
    NiCamera* pOverride6 = 0;
    if (*g_011ded80.Bool())
    {
        static CamWatcher kWatcher;
        kWatcher.FUN_008d6f50(pOverride6 ? pOverride6 : pCamera);
    }
    ((NiAVObject*)g_011deb34)->FUN_00440460(((CamNode*)g_011deb7c)->FUN_00558310()->FUN_0043c490());
    NiUpdateData kData5(0.0f, false, false);
    ((NiAVObject*)g_011deb34)->Update(kData5);
    ((NiAVObject*)g_011deda4)->FUN_00440460(((CamNode*)g_011deb7c)->FUN_00558310()->FUN_0043c490());
    NiUpdateData kData2(0.0f, false, false);
    ((NiAVObject*)g_011deda4)->Update(kData2);
    if (DAT_011f9fc0)
    {
        DAT_011f9fc0 = 0;
        DAT_011f9fc1 = 1;
    }
    FUN_00872dd0(*g_011decd8.Bool(), true);
    FUN_00872df0(*g_011deb60.Bool());
    DAT_011f94a5 = 0;
    void* pResult = 0;
    if (g_TES->FUN_008d8520() && g_TES->FUN_008d8520()->FUN_0045cd60() &&
        (g_TES->FUN_008d8520()->FUN_00476c90() == 3 || g_TES->FUN_008d8520()->FUN_00476c90() == 2))
    {
        pResult = g_TES->FUN_008d8520()->FUN_0045cd60();
    }
    return pResult;
}
}  // namespace fnv_00872b00

namespace fnv_0086ff70 {
struct Main86 : Main
{
    void FUN_0086ff70();
    void FUN_00871dc0();
    void FUN_00877430();
    void FUN_008706b0(int, int, int);
    void FUN_00871a50();
    void FUN_00872940(int);
    void FUN_00874b90(int);
};
struct Extra86
{
    void FUN_0096cfa0();
};
struct PlayerState86
{
    virtual bool vfn_000();
    virtual bool vfn_004();
    virtual bool vfn_008();
    virtual bool vfn_00c();
    virtual bool vfn_010();
    virtual bool vfn_014();
    virtual bool vfn_018();
    virtual bool vfn_01c();
    virtual bool vfn_020();
    virtual bool vfn_024();
    virtual bool vfn_028();
    virtual bool vfn_02c();
    virtual bool vfn_030();
    virtual bool vfn_034();
    virtual bool vfn_038();
    virtual bool vfn_03c();
    virtual bool vfn_040();
    virtual bool vfn_044();
    virtual bool vfn_048();
    virtual bool vfn_04c();
    virtual bool vfn_050();
    virtual bool vfn_054();
    virtual bool vfn_058();
    virtual bool vfn_05c();
    virtual bool vfn_060();
    virtual bool vfn_064();
    virtual bool vfn_068();
    virtual bool vfn_06c();
    virtual bool vfn_070();
    virtual bool vfn_074();
    virtual bool vfn_078();
    virtual bool vfn_07c();
    virtual bool vfn_080();
    virtual bool vfn_084();
    virtual bool vfn_088();
    virtual bool vfn_08c();
    virtual bool vfn_090();
    virtual bool vfn_094();
    virtual bool vfn_098();
    virtual bool vfn_09c();
    virtual bool vfn_0a0();
    virtual bool vfn_0a4();
    virtual bool vfn_0a8();
    virtual bool vfn_0ac();
    virtual bool vfn_0b0();
    virtual bool vfn_0b4();
    virtual bool vfn_0b8();
    virtual bool vfn_0bc();
    virtual bool vfn_0c0();
    virtual bool vfn_0c4();
    virtual bool vfn_0c8();
    virtual bool vfn_0cc();
    virtual bool vfn_0d0();
    virtual bool vfn_0d4();
    virtual bool vfn_0d8();
    virtual bool vfn_0dc();
    virtual bool vfn_0e0();
    virtual bool vfn_0e4();
    virtual bool vfn_0e8();
    virtual bool vfn_0ec();
    virtual bool vfn_0f0();
    virtual bool vfn_0f4();
    virtual bool vfn_0f8();
    virtual bool vfn_0fc();
    virtual bool vfn_100();
    virtual bool vfn_104();
    virtual bool vfn_108();
    virtual bool vfn_10c();
    virtual bool vfn_110();
    virtual bool vfn_114();
    virtual bool vfn_118();
    virtual bool vfn_11c();
    virtual bool vfn_120();
    virtual bool vfn_124();
    virtual bool vfn_128();
    virtual bool vfn_12c();
    virtual bool vfn_130();
    virtual bool vfn_134();
    virtual bool vfn_138();
    virtual bool vfn_13c();
    virtual bool vfn_140();
    virtual bool vfn_144();
    virtual bool vfn_148();
    virtual bool vfn_14c();
    virtual bool vfn_150();
    virtual bool vfn_154();
    virtual bool vfn_158();
    virtual bool vfn_15c();
    virtual bool vfn_160();
    virtual bool vfn_164();
    virtual bool vfn_168();
    virtual bool vfn_16c();
    virtual bool vfn_170();
    virtual bool vfn_174();
    virtual bool vfn_178();
    virtual bool vfn_17c();
    virtual bool vfn_180();
    virtual bool vfn_184();
    virtual bool vfn_188();
    virtual bool vfn_18c();
    virtual bool vfn_190();
    virtual bool vfn_194();
    virtual bool vfn_198();
    virtual bool vfn_19c();
    virtual bool vfn_1a0();
    virtual bool vfn_1a4();
    virtual bool vfn_1a8();
    virtual bool vfn_1ac();
    virtual bool vfn_1b0();
    virtual bool vfn_1b4();
    virtual bool vfn_1b8();
    virtual bool vfn_1bc();
    virtual bool vfn_1c0();
    virtual bool vfn_1c4();
    virtual bool vfn_1c8();
    virtual bool vfn_1cc();
    virtual int vfn_1d0();
    PlayerState86* FUN_00950bb0(int);
};
struct PlayerContext86
{
    bool FUN_00456610();
    void FUN_00450f90(int);
};
struct Core86
{
    void FUN_004a0370();
    void FUN_005585e0();
    int FUN_004e9530();
    void FUN_004a03c0();
};
struct Input86
{
    bool FUN_00701450(int);
    void FUN_007010e0(int, int);
    bool IsFaderActive(int);
};
struct Topic86
{
    void FUN_004baf10();
};
struct Engine86
{
    void FUN_00457d70(int, int, int);
    int FUN_005f36f0();
    Engine86* FUN_004fd3e0();
    const char* FUN_00548210();
    Topic86* FUN_0044ddc0();
    void FUN_004baf10();
};
struct Global86
{
    int FUN_00559450();
    void FUN_0066b0d0(int);
};
struct Resource86
{
    void FUN_00c51f20();
};
struct Options86
{
    int* FUN_0043d4d0();
    void FUN_0045ce80(int);
};
struct Frame86
{
    float FUN_007013e0();
    void FUN_0086d4c0(int);
};
struct Node86
{
    void FUN_004534f0(int);
    bool FUN_0047c850();
    void FUN_00483710();
};
struct Sound86
{
    void FUN_00ba2f30();
    void FUN_00ba30f0();
    void FUN_00ba3130();
    void FUN_00ba2fa0();
};
struct GlobalText86
{
    int FUN_00403df0();
};
struct ControlItem86
{
    bool FUN_00a24660();
    bool FUN_00a24180();
};
struct Settings86
{
    int* FUN_0043d4d0();
};
struct Sink86
{
    void FUN_00701450(int);
};
struct ContextResult86
{
    bool FUN_004e9530();
};
struct MenuHandler86
{
    void FUN_0086d4c0(int);
};
struct Receiver86;
extern Receiver86* __cdecl FUN_0043c4b0();
extern Sound86* __cdecl FUN_004ea970();
extern Sound86* __stdcall FUN_004ea970(int, int);
extern char __cdecl FUN_00702680(int, int);
extern bool __cdecl FUN_0070edf0();
extern bool __cdecl FUN_007079b0();
extern bool __cdecl FUN_007079b0(int);
extern bool __cdecl FUN_00702360();
extern bool __cdecl FUN_005d4a40();
extern void __cdecl FUN_00b55a10();
extern void __cdecl FUN_00709b40();
extern void __cdecl FUN_00a29680();
extern int __cdecl FUN_0040fbe0(...);
extern void __cdecl ApplyGammaRamp();
extern void __cdecl FUN_0070edf0_unused();
extern void __cdecl SaveScreenshot(int);
extern void __cdecl FUN_00c458f0();
extern void __cdecl FUN_00b6b730();
extern void __cdecl FUN_00c51f20();
extern void __cdecl FUN_008c80e0(int);
extern void __cdecl FUN_00406d00(char*, unsigned int, const char*, int, int);
extern "C" __declspec(dllimport) int __stdcall CreateDirectoryA(const char*, void*);
extern int __stdcall FUN_004e3270(Core86*, int, int);
extern void __cdecl RenderOrFallback(int, int);
struct SwapMessage86
{
    void FUN_00b6da10();
};
extern SwapMessage86* __stdcall FUN_004a0ea0(int);
extern void __cdecl FUN_00b6da10();
extern bool __cdecl FUN_004dc310();
extern int DAT_011e0e80;
extern void __cdecl FUN_004da670();
extern char __cdecl FUN_00707000_unused();
extern unsigned char DAT_011d890a, DAT_011c6fb8, DAT_011dea29;
extern bool DAT_011dea40;
extern int DAT_011def04, DAT_011dea44;
extern float DAT_011def00;
extern double DAT_01012070;
extern PlayerState86* DAT_011dea3c;
extern Engine86* DAT_011dea10;
extern Input86* DAT_011d8804;
extern Node86* DAT_011de45c;
extern Global86 DAT_011ded3c, DAT_011dec64, DAT_011deb7c;
extern Options86 DAT_011deecc, DAT_011dee00, DAT_011c3ea4;
extern Frame86 DAT_011f6394;
extern GlobalText86 DAT_011deb04;
extern ControlItem86 DAT_011fdf30_dummy;
extern const char DAT_01082ca4[];
extern unsigned char DAT_011dea29;
extern int DAT_011c6fb8_dummy;
extern int DAT_011dea40_dummy;
extern int DAT_011def04;
extern char __cdecl FUN_008705c0();
extern void __cdecl FUN_004ea970_set();
extern void __cdecl FUN_0045cd60();
extern void __cdecl FUN_00870680();
extern void __cdecl FUN_00702840();
extern void __cdecl FUN_00702810();
extern void __cdecl FUN_007027e0();
extern void __cdecl FUN_00a29680();
extern void __cdecl FUN_00c458f0();
extern void __cdecl FUN_00878660();
extern int __cdecl FUN_0040fbe0(...);
extern void __cdecl FUN_004a03c0();
extern float __cdecl FUN_00450820();
extern void __cdecl FUN_00702840();
extern void __cdecl RenderOrFallback(int, int);
struct Control86
{
    int FUN_00a24660();
    int FUN_00a24180();
};
extern Control86* __stdcall FUN_007fdf30(int, int);
extern Control86* __cdecl FUN_007fdf30_control(int, int);
struct Receiver86;
extern Receiver86* __cdecl FUN_0043c4b0();
extern int __cdecl FUN_004e3270_variant(int, int);
extern void __cdecl FUN_00450f90_variant(int);
extern int __cdecl FUN_004dc310_variant(int);
extern void __cdecl FUN_004ea970_variant();
extern void __cdecl FUN_00b6da10();
extern void __cdecl FUN_00c51f20();
extern void __cdecl FUN_004e9530_dummy();
extern int __cdecl FUN_0043c4b0_unused();
extern int __cdecl FUN_0044ddc0_unused();
extern void __cdecl FUN_007028b0_unused();
extern int __cdecl FUN_00559450_unused();
// Runs player, input, audio, and state update calls, then performs frame cleanup and resource updates.
// @fnv 0x0086ff70
void Main86::FUN_0086ff70()
{
    Core86* core = reinterpret_cast<Core86*>(FUN_0043c4b0());
    core->FUN_004a0370();
    if (DAT_011d890a)
    {
        DAT_011d890a = 0;
        bool first = reinterpret_cast<PlayerContext86*>(DAT_011dea3c->FUN_00950bb0(1))->FUN_00456610();
        bool second = reinterpret_cast<PlayerContext86*>(DAT_011dea3c->FUN_00950bb0(0))->FUN_00456610();
        reinterpret_cast<PlayerContext86*>(DAT_011dea3c->FUN_00950bb0(1))->FUN_00450f90(1);
        reinterpret_cast<PlayerContext86*>(DAT_011dea3c->FUN_00950bb0(0))->FUN_00450f90(1);
        FUN_00871dc0();
        reinterpret_cast<PlayerContext86*>(DAT_011dea3c->FUN_00950bb0(1))->FUN_00450f90(first);
        reinterpret_cast<PlayerContext86*>(DAT_011dea3c->FUN_00950bb0(0))->FUN_00450f90(second);
    }
    reinterpret_cast<Core86*>(FUN_0043c4b0())->FUN_005585e0();
    FUN_00a29680();
    FUN_0040fbe0();
    FUN_004ea970()->FUN_00ba2f30();
    if (DAT_011c6fb8)
        ApplyGammaRamp();
    if (DAT_011d8804->FUN_00701450(1) || DAT_011d8804->FUN_00701450(2))
    {
        if (!DAT_011def04)
        {
            DAT_011dea10->FUN_00457d70(0, 0, 0);
            FUN_0040fbe0();
            reinterpret_cast<Extra86*>(&DAT_011e0e80)->FUN_0096cfa0();
        }
        DAT_011def00 += DAT_011f6394.FUN_007013e0();
        ++DAT_011def04;
        if (DAT_011def00 >= DAT_01012070 && DAT_011def04 >= 10)
        {
            DAT_011d8804->FUN_007010e0(1, 0);
            DAT_011d8804->FUN_007010e0(2, 0);
            DAT_011de45c->FUN_004534f0(0);
            if (DAT_011de45c->FUN_0047c850())
            {
                DAT_011de45c->FUN_004534f0(0);
                DAT_011de45c->FUN_00483710();
            }
            FUN_00877430();
        }
    }
    else
    {
        DAT_011def00 = 0.0f;
        DAT_011def04 = 0;
    }
    int eventState = 0;
    if (!DAT_011dea29 && !FUN_0070edf0() && DAT_011dea3c->vfn_1d0() && !DAT_011d8804->IsFaderActive(1))
    {
        if (!DAT_011dea10->FUN_005f36f0())
        {
            if (DAT_011dea10->FUN_004fd3e0()->FUN_00548210()[0] && DAT_011dea10->FUN_0044ddc0())
            {
                DAT_011dea10->FUN_0044ddc0();
                if ((unsigned char)FUN_008705c0())
                    DAT_011dea10->FUN_0044ddc0()->FUN_004baf10();
            }
        }
        FUN_008706b0(0, 0, 0);
    }
    else if ((FUN_007079b0() || !FUN_00702360()) && !(unsigned char)FUN_00702680(0x3f5, 0))
    {
        if (DAT_011dea3c->vfn_1d0())
            FUN_008706b0(0, FUN_007079b0(), 0);
    }
    else
    {
        for (int i = 1; i < 23; ++i)
        {
            FUN_004ea970(0, i)->FUN_00ba30f0();
            FUN_004ea970(1, i)->FUN_00ba3130();
        }
        FUN_00871a50();
        if ((unsigned char)FUN_00702680(0x41e, 0) || (unsigned char)FUN_00702680(0x3f6, 0) ||
            (unsigned char)FUN_00702680(0x424, 0) || (unsigned char)FUN_00702680(0x432, 0) ||
            (unsigned char)FUN_00702680(0x438, 0) || (unsigned char)FUN_00702680(0x439, 0) ||
            (unsigned char)FUN_00702680(0x43a, 0) || (unsigned char)FUN_00702680(0x43b, 0))
            FUN_00872940(0);
        else if (DAT_011ded3c.FUN_00559450())
            FUN_00874b90(FUN_004e3270(core, FUN_004dc310(), 0));
    }
    if (FUN_005d4a40() == 1)
        FUN_00b55a10();
    FUN_00709b40();
    RenderOrFallback(eventState, DAT_011dec64.FUN_00559450());
    FUN_004ea970()->FUN_00ba2fa0();
    if (DAT_011dec64.FUN_00559450())
    {
        FUN_004a0ea0(DAT_011dec64.FUN_00559450())->FUN_00b6da10();
        DAT_011dec64.FUN_0066b0d0(0);
    }
    if (FUN_007fdf30(0x1e, 1)->FUN_00a24660())
    {
        if (FUN_007fdf30(0x9d, 0)->FUN_00a24180() || DAT_011dea40)
        {
            DAT_011dea40 = !DAT_011dea40;
            if (DAT_011dea40)
            {
                DAT_011dea44 = 0;
                DAT_011deecc.FUN_0045ce80(*DAT_011deecc.FUN_0043d4d0() + 1);
                char outputDirectory[0x104];
                FUN_00406d00(outputDirectory, 0x104, DAT_01082ca4, DAT_011deb04.FUN_00403df0(),
                             *DAT_011deecc.FUN_0043d4d0());
                CreateDirectoryA(outputDirectory, 0);
                DAT_011f6394.FUN_0086d4c0(*DAT_011dee00.FUN_0043d4d0());
            }
            else
                DAT_011f6394.FUN_0086d4c0(0);
        }
        else
            SaveScreenshot(0);
    }
    FUN_00c458f0();
    if (core->FUN_004e9530())
        FUN_00b6b730();
    if (eventState)
    {
        FUN_004a0ea0(eventState)->FUN_00b6da10();
        eventState = 0;
    }
    reinterpret_cast<Resource86*>(DAT_011deb7c.FUN_00559450())->FUN_00c51f20();
    core->FUN_004a03c0();
    if (*DAT_011c3ea4.FUN_0043d4d0() > 1)
        FUN_008c80e0(0);
}
}  // namespace fnv_0086ff70

namespace fnv_00870bd0 {
struct FUN_00414430;
struct NiPoint2;
struct BSRenderedTexture;
struct ImageView;
struct ProjectionView;
ImageView* FUN_004e3270();
ProjectionView* FUN_0045c670();
bool FUN_004dc310();
unsigned char FUN_008709f0();
bool FUN_00871260();
struct RenderNode
{
    bool FUN_00456610();
    void FUN_00450f90(bool);
};
struct ModelView
{
    RenderNode* FUN_0043b230();
};
struct PlayerView
{
    RenderNode* FUN_00950bb0(bool);
};
struct MenuView
{
    int FUN_005585e0();
};
struct WorldView
{
    int FUN_005f36f0();
};
struct PointView
{
    const NiPoint3& FUN_0045bb80();
};
struct CameraView
{
    virtual void v0();
    virtual PointView* v1();
};
struct CameraHolder
{
    CameraView* FUN_0045cd60();
};
struct ProjectionResult
{
    bool ProjectPointToScreen();
};
struct ProjectionView
{
    ProjectionResult* FUN_006629f0(const NiPoint3&, float&, float&, float&, float);
};
struct RenderView
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
    virtual void v43(void*);
    unsigned FUN_004dee10();
    unsigned FUN_004dee70();
    void FUN_007148c0(FUN_00414430*, bool);
};
struct EffectView
{
    bool FUN_00871220();
};
struct ImageView
{
    EffectView* FUN_004ebbc0(int);
    bool FUN_00b8b390(int);
    void FUN_00b8b1e0(const NiPoint2&);
};
struct ShaderView
{
    unsigned SumItemSubValues();
};
struct ShaderHolder
{
    ShaderView* FUN_00559450();
};
struct SettingView
{
    float* FUN_00403e20();
};
struct BoolSettingView
{
    bool* FUN_00408d60();
};
struct ToggleView
{
    void FUN_00ba3130();
    void FUN_00ba30f0();
};
struct NiPoint2
{
    float x, y;
    NiPoint2(float, float);
};
struct FUN_00414430
{
    float a, b, c, d;
    FUN_00414430(float, float, float, float);
};
extern PlayerView* DAT_011dea3c;
extern WorldView* DAT_011dea10;
extern CameraHolder* DAT_011dea20;
extern SettingView DAT_011dea8c;
extern BoolSettingView DAT_011deadc;
extern int DAT_011a9bd0;
RenderView* FUN_0043c4b0();
MenuView* FUN_00705910();
bool FUN_00705100();
bool FUN_004de080();
bool FUN_00709cb0();
bool FUN_005b9b00();
bool FUN_005bac20();
bool FUN_00705a00();
float FUN_00706e70();
void FUN_00b4f540(unsigned, unsigned, unsigned, unsigned);
ToggleView* __stdcall FUN_004ea970(int, int);

void FUN_00b540d0();
struct RenderCoordinator
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c,
        unk80, unk84;
    ShaderHolder shaders;
    void FUN_00872ad0();
    ModelView* UpdateCamera();
    void FUN_008727d0();
    bool FUN_008749b0();
    void FUN_00871290();
    BSRenderedTexture* FUN_00872f50(RenderView*, int, int, bool);
    void FUN_00874ac0(bool);
    void FUN_00874b50(BSRenderedTexture*, bool, unsigned);
    void FUN_00873200(ModelView*, bool, int, bool);
    void FUN_008746d0(BSRenderedTexture*);
    void FUN_00874920(ShaderView*, BSRenderedTexture*);
    void FUN_00874c10();
    void FUN_00875110(RenderView*, int, ModelView*, BSRenderedTexture*);
    void FUN_00875e40(ShaderView*, BSRenderedTexture*);
    void FUN_00875fa0(ShaderView*, BSRenderedTexture*);
    void FUN_00875fd0(bool, BSRenderedTexture*, RenderView*, int);
    void FUN_00876a20(RenderView*);
    void FUN_00876830(bool, int);
    void FUN_00876850(BSRenderedTexture*, ImageView*, RenderView*, ModelView*);
    void FUN_00870bd0(int, bool);
};
// Renders the scene into a BSRenderedTexture, applying effects, post-processing, and camera projection based on the given argument and skip flag.
// @fnv 0x00870bd0
void RenderCoordinator::FUN_00870bd0(int arg, bool skip)
{
    RenderView* l = FUN_0043c4b0();
    ImageView* h = (ImageView*)FUN_004e3270();
    ModelView* s = 0;
    bool p = DAT_011dea3c->FUN_00950bb0(true)->FUN_00456610();
    bool q = FUN_004dc310();
    FUN_00872ad0();
    s = UpdateCamera();
    FUN_008727d0();
    bool i = FUN_008749b0();
    FUN_00871290();
    BSRenderedTexture* j = FUN_00872f50(l, arg, 0, q);
    FUN_00874ac0(i);
    FUN_00874b50(j, q, 5);
    bool cf = !p && !skip && !FUN_00705910()->FUN_005585e0() && !FUN_00705100();
    bool a = false;
    if (cf && s)
    {
        a = s->FUN_0043b230()->FUN_00456610();
        s->FUN_0043b230()->FUN_00450f90(true);
    }
    bool eb = true;
    if (FUN_004de080())
        eb = false;
    bool e = FUN_00709cb0();
    if (e)
    {
        unsigned j = l->FUN_004dee10();
        unsigned c = l->FUN_004dee70();
        float l = *DAT_011dea8c.FUN_00403e20() * FUN_00706e70() * 0.5;
        float e = j * l;
        float k = j - e;
        if (eb)
            FUN_00b4f540((unsigned)e, 0, (unsigned)k, c);
    }
    FUN_00873200(s, cf, 0, i);
    if (cf && s)
        s->FUN_0043b230()->FUN_00450f90(a);
    EffectView* k = h->FUN_004ebbc0(4);
    bool c = k->FUN_00871220();
    bool j7 = (h->FUN_00b8b390(9) && !DAT_011dea10->FUN_005f36f0() && *DAT_011deadc.FUN_00408d60()) ? true : false;
    const bool ba = false;
    const bool f = false;
    bool b = false;
    if ((c || ba || f) && cf)
    {
        b = true;
        FUN_008746d0(j);
        FUN_00874b50(j, q, 0);
    }
    if (FUN_005b9b00() && shaders.FUN_00559450()->SumItemSubValues() > 0)
        FUN_00874920(shaders.FUN_00559450(), j);
    if (cf)
    {
        FUN_00874c10();
        FUN_00874b50(j, q, 0);
        if (!b)
            FUN_004ea970(1, 22)->FUN_00ba3130();
        FUN_00875110(l, 0, s, j);
    }
    else
    {
        FUN_004ea970(0, 22)->FUN_00ba30f0();
        FUN_004ea970(1, 22)->FUN_00ba3130();
    }
    if (c || ba)
        FUN_00875e40(shaders.FUN_00559450(), j);
    if (f)
        FUN_00875fa0(shaders.FUN_00559450(), j);
    if (j7 && !DAT_011dea10->FUN_005f36f0() && DAT_011dea20 && DAT_011dea20->FUN_0045cd60())
    {
        NiPoint3 v = DAT_011dea20->FUN_0045cd60()->v1()->FUN_0045bb80();
        float w, u, n;
        w = u = n = 0.0f;
        ProjectionView* a = (ProjectionView*)FUN_0045c670();
        bool f = a->FUN_006629f0(v, w, u, n, 0.00001f)->ProjectPointToScreen();
        ((ImageView*)FUN_004e3270())->FUN_00b8b1e0(NiPoint2(w, u));
    }
    if (FUN_008709f0())
    {
        FUN_00875fd0(q, j, l, arg);
        if ((FUN_00871260() || FUN_005bac20()) && !FUN_00705a00())
            FUN_00876a20(l);
    }
    else if (arg)
        FUN_00876830(q, arg);
    if (e)
    {
        if (eb)
            FUN_00b540d0();
        if (FUN_004de080())
        {
            FUN_0043c4b0()->v43(&DAT_011a9bd0);
            FUN_00414430 param(0, 0, 0, 0);
            param.a = 0;
            param.b = 0.33f;
            param.c = 1;
            param.d = 0;
            FUN_0043c4b0()->FUN_007148c0(&param, true);
            param.a = 0.66f;
            param.b = 1;
            param.c = 1;
            param.d = 0;
            FUN_0043c4b0()->FUN_007148c0(&param, true);
        }
    }
    FUN_00876850(j, h, l, s);
}
}  // namespace fnv_00870bd0

namespace fnv_00872570 {
struct HWND__;
class BGSMoviePlayer_ML
{
  public:
    bool FUN_00ec17c0();
    void FUN_00ec29b0();
    void FUN_00ec1800();
    bool FUN_00872780();
    void FUN_00ec25e0();
};
struct RenderManager_ML
{
    void FUN_00b631d0();
};
RenderManager_ML* __cdecl FUN_00b4f5c0();
struct CellState_ML
{
    int unk00;
    int active;
};
struct CellUpdate_ML
{
    void FUN_005477f0(void**, CellState_ML**);
};
struct GridCell_ML
{
    CellUpdate_ML* cell;
};
struct CellGrid_ML
{
    int FUN_0084e3a0();
};
struct WorldAudio_ML
{
    void ReleaseWaterResources(int, int);
    void FUN_004e65d0();
};
class TES_ML
{
  public:
    CellGrid_ML* FUN_0044ddc0();
    GridCell_ML* FUN_00457050(int, int);
    WorldAudio_ML* FUN_0070ec90();
};
class OSGlobals_ML
{
  public:
    int unk00;
    int unk04;
    HWND__* window;
    void FUN_00877430();
};
void __cdecl FUN_0040fca0(unsigned long);
unsigned char __cdecl FUN_00446e10();
unsigned char __cdecl FUN_005d2a40();
void __cdecl FUN_00bad4a0();
extern unsigned char DAT_011f941e;
struct WindowRect_ML
{
    long left, top, right, bottom;
};
extern "C" __declspec(dllimport) long __stdcall GetWindowLongA(HWND__*, int);
extern "C" __declspec(dllimport) int __stdcall AdjustWindowRectEx(WindowRect_ML*, unsigned long, int, unsigned long);
extern "C" __declspec(dllimport) int __stdcall SetWindowPos(HWND__*, HWND__*, int, int, int, int, unsigned int);

namespace MainLoopGlobals {
extern "C" BGSMoviePlayer_ML* DAT_0126fac4;
extern "C" TES_ML* DAT_011dea10;
extern "C" OSGlobals_ML* g_osGlobals;
extern "C" bool __cdecl FUN_0086bdf0();
extern "C" long __cdecl FUN_004dc1f0();
extern "C" long __cdecl FUN_004dc200();
}

// When active, waits for a condition and updates render, cell, and window state; otherwise, it performs audio-related calls.
// @fnv 0x00872570
bool __cdecl FUN_00872570(bool active)
{
    if (active)
    {
        while (!(unsigned char)MainLoopGlobals::FUN_0086bdf0())
            FUN_0040fca0(5);
        if (MainLoopGlobals::DAT_0126fac4->FUN_00ec17c0())
        {
            MainLoopGlobals::DAT_0126fac4->FUN_00ec29b0();
            MainLoopGlobals::DAT_0126fac4->FUN_00ec1800();
        }
        if (MainLoopGlobals::DAT_0126fac4->FUN_00872780())
            MainLoopGlobals::DAT_0126fac4->FUN_00ec25e0();
        RenderManager_ML* renderer = FUN_00b4f5c0();
        if (renderer)
            renderer->FUN_00b631d0();
        {
            int count = MainLoopGlobals::DAT_011dea10->FUN_0044ddc0()->FUN_0084e3a0();
            for (int x = 0; x < count; ++x)
            {
                for (int y = 0; y < count; ++y)
                {
                    CellUpdate_ML* cell = MainLoopGlobals::DAT_011dea10->FUN_00457050(x, y)->cell;
                    if (cell)
                    {
                        void* object;
                        CellState_ML* state;
                        cell->FUN_005477f0(&object, &state);
                        if (object && state && state->active)
                            state->active = 0;
                    }
                }
            }
            MainLoopGlobals::g_osGlobals->FUN_00877430();
            if (FUN_00446e10())
            {
                long style;
                {
                    WindowRect_ML rectWindow;
                    rectWindow.left = 0;
                    rectWindow.top = 0;
                    rectWindow.right = MainLoopGlobals::FUN_004dc1f0();
                    rectWindow.bottom = MainLoopGlobals::FUN_004dc200();
                    style = 0;
                    style = GetWindowLongA(MainLoopGlobals::g_osGlobals->window, -16);
                    AdjustWindowRectEx(&rectWindow, style, 0, 0);
                    SetWindowPos(MainLoopGlobals::g_osGlobals->window, 0, rectWindow.left, rectWindow.bottom,
                                 rectWindow.right - rectWindow.left, rectWindow.top - rectWindow.bottom, 0);
                }
            }
        }
    }
    else
    {
        if (DAT_011f941e)
            FUN_00bad4a0();
        if (MainLoopGlobals::DAT_011dea10->FUN_0070ec90() && FUN_005d2a40())
        {
            MainLoopGlobals::DAT_011dea10->FUN_0070ec90()->ReleaseWaterResources(1, 0);
            MainLoopGlobals::DAT_011dea10->FUN_0070ec90()->FUN_004e65d0();
        }
    }
    return true;
}
}  // namespace fnv_00872570

#include <string.h>
namespace fnv_00a24830 {
struct DIGuid
{
    unsigned long Data1;
    unsigned short Data2, Data3;
    unsigned char Data4[8];
};
struct DIDEVICEOBJECTINSTANCEA;
struct DIDEVICEINSTANCEA
{
    unsigned long dwSize;
    DIGuid guidInstance, guidProduct;
    unsigned long dwDevType;
    char tszInstanceName[260], tszProductName[260];
    DIGuid guidFFDriver;
    unsigned short wUsagePage, wUsage;
};
struct DIDEVCAPS
{
    unsigned long dwSize, dwFlags, dwDevType, dwAxes, dwButtons, dwPOVs, dwFFSamplePeriod, dwFFMinTimeResolution,
        dwFirmwareRevision, dwHardwareRevision, dwFFDriverVersion;
};
struct IDirectInputDevice8A
{
    virtual long __stdcall Q();
    virtual long __stdcall A();
    virtual long __stdcall R();
    virtual long __stdcall GetCapabilities(DIDEVCAPS*);
    virtual long __stdcall EnumObjects(int(__stdcall*)(const DIDEVICEOBJECTINSTANCEA*, void*), void*, unsigned long);
    virtual long __stdcall GetProperty();
    virtual long __stdcall SetProperty();
    virtual long __stdcall Acquire();
    virtual long __stdcall Unacquire();
    virtual long __stdcall GetDeviceState();
    virtual long __stdcall GetDeviceData();
    virtual long __stdcall SetDataFormat(const void*);
    virtual long __stdcall SetEventNotification();
    virtual long __stdcall SetCooperativeLevel(void*, unsigned long);
};
struct IDirectInput8A
{
    virtual long __stdcall Q();
    virtual long __stdcall A();
    virtual long __stdcall R();
    virtual long __stdcall CreateDevice(const DIGuid&, IDirectInputDevice8A**, void*);
};
extern "C" __declspec(dllimport) void* __stdcall GetForegroundWindow();
extern const unsigned char DAT_01100ebc[];

void* _fnv_zlib_memset(void*, int, unsigned int);
int __stdcall MatchObjectGuids(const DIDEVICEOBJECTINSTANCEA*, void*);
struct JoystickCounts
{
    unsigned int axes, buttons;
};
struct InputOwner
{
    unsigned int unk00, unk04;
    IDirectInput8A* input;
    IDirectInputDevice8A* devices[8];
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
    DIDEVICEINSTANCEA instances[8];
    DIDEVCAPS caps[8];
    JoystickCounts counters[8];
    unsigned int count;
    void FUN_00a236f0(unsigned int, int, int);
    void FUN_00a23750(unsigned int, float);
};
// Accepts instances whose low device type byte is 20 or 21, creates a device, queries capabilities and object counts, and stores it.
// @fnv 0x00a24830
int __stdcall FUN_00a24830(const DIDEVICEINSTANCEA* instance, void* context)
{
    InputOwner* manager = (InputOwner*)context;
    if ((unsigned char)(instance->dwDevType & 255) != 20 && (unsigned char)(instance->dwDevType & 255) != 21)
        return 1;
    DIDEVICEINSTANCEA* deviceOut = &manager->instances[manager->count];
    memcpy(deviceOut, instance, 0x244);
    IDirectInputDevice8A* saved;
    manager->input->CreateDevice(instance->guidInstance, &saved, 0);
    IDirectInputDevice8A* device = saved;
    device->SetCooperativeLevel(GetForegroundWindow(), 6);
    device->SetDataFormat(DAT_01100ebc);
    DIDEVCAPS* caps = &manager->caps[manager->count];
    _fnv_zlib_memset(caps, 0, 0x2c);
    manager->caps[manager->count].dwSize = 0x2c;
    device->GetCapabilities(&manager->caps[manager->count]);
    manager->counters[manager->count].axes = 0;
    manager->counters[manager->count].buttons = 0;
    device->EnumObjects(MatchObjectGuids, &manager->counters[manager->count], 0);
    manager->devices[manager->count] = device;
    manager->FUN_00a236f0(manager->count, -100, 100);
    manager->FUN_00a23750(manager->count, 0.1f);
    manager->count++;
    if (manager->count == 8)
        return 0;
    return 1;
}
}  // namespace fnv_00a24830

namespace fnv_0086f940 {
class BGSAcousticSpace;
// Required virtual interface: the pack leaves the update slot untyped.
class PlayerUpdate : public TESObjectREFR
{
  public:
    virtual void StartHighProcess(void);
    virtual void Unk_91(void);
    virtual void Unk_92(void);
    virtual void Unk_93(void);
    virtual void Unk_94(void);
    virtual void Unk_95(void);
    virtual void Unk_96(void);
    virtual void Unk_97(void);
    virtual void Unk_98(void);
    virtual void Unk_99(void);
    virtual void Unk_9A(float arg0);
    virtual void Unk_9B(void);
    virtual void Unk_9C(void);
    virtual void Unk_9D(void);
    virtual void Unk_9E(void);
    virtual void Unk_9F(void* arg0);
    virtual void Unk_A0(void);
    virtual void Unk_A1(void);
    virtual void Unk_A2(void);
    virtual void Unk_A3(void* arg0, bool arg1);
    virtual void Unk_A4(void);
    virtual void Unk_A5(void);
    virtual void Unk_A6(void);
    virtual void Unk_A7(void);
    virtual void Unk_A8(void);
    virtual void Unk_A9(void);
    virtual void Unk_AA(NiPoint3& arg0);
    virtual void Unk_AB(NiPoint3& result);
    virtual void Unk_AC(void);
    virtual void Unk_AD(void);
    virtual void Unk_AE(void);
    virtual float GetCurrentTargetDistance(bool ignoreImmobile);
    virtual void Unk_B0(void);
    virtual void SetFurnitureHeading(float heading);
    virtual TESObjectREFR* GetCurrentTarget();
    virtual void Unk_B3(void);
    virtual void Unk_B4(void);
    virtual void Unk_B5(void);
    virtual void Unk_B6(void);
    virtual void SetActorEssentialState(int value);
    virtual void Unk_B8(void);
    virtual void Unk_B9(void);
    virtual bool Unk_BA();
    virtual void Unk_BB(void);
    virtual void Unk_BC(void);
    virtual void Unk_BD(void);
    virtual void Unk_BE(float delta);
};
struct PlayerCalls
{
    bool FUN_0093bea0();
    void FUN_009481d0();
    void FUN_009466d0(float delta, unsigned char mode);
    NiPoint3* GetAddTopicList();
    void FUN_0086fbc0(char value);
};
struct CellCalls
{
    bool IsInterior();
    bool FUN_00550200(const NiPoint3& position);
    TESWorldSpace* FUN_0054ddd0();
    bool FUN_00450fb0();
    bool FUN_00450ff0();
    void AddReference(TESObjectREFR*, bool);
    BGSAcousticSpace* GetAcousticSpace();
};
struct DataHandlerCalls
{
    TESObjectCELL* FUN_00461bc0(float x, float y, TESWorldSpace*, bool);
};
struct Receiver86;
extern Receiver86* g_dataHandler;
class WorldUpdateCalls
{
  public:
    void FUN_00452580(const NiPoint3&, bool);
    bool FUN_00451530();
    void FUN_00457d70(int, int, int);
};
extern unsigned int _DAT_011dea10;
struct TimeGlobal
{
    float FUN_0084d030();
};
extern TimeGlobal g_timeGlobal;
struct UpdateScale
{
    float FUN_009c8cc0();
};
extern UpdateScale DAT_011f2250;
extern unsigned char DAT_011e07a8;
bool FUN_00709bc0();
extern bool DAT_011dea2b;
void FUN_0086fba0(bool);
void FUN_0086fbb0(BGSAcousticSpace*);
struct RenderManager
{
    void FUN_00b655b0();
};
RenderManager* FUN_00b4f5c0();
struct PlayerUpdateState
{
    unsigned int updateFlags;
    unsigned short updateState;
    bool specialUpdate;
    unsigned char updateMode;
    void FUN_0086f940();
};

// Updates player state and may transfer the player to a destination cell when the current cell is exterior and a position check fails.
// @fnv 0x0086f940
void PlayerUpdateState::FUN_0086f940()
{
    bool bChanged;
    if (!reinterpret_cast<PlayerCalls*>(g_thePlayer)->FUN_0093bea0())
    {
        if (DAT_011dea2b && !FUN_00709bc0())
        {
            reinterpret_cast<PlayerCalls*>(g_thePlayer)->FUN_009481d0();
        }
        else if (specialUpdate)
        {
            if (g_thePlayer->GetNiNode())
            {
                reinterpret_cast<PlayerCalls*>(g_thePlayer)->FUN_009466d0(g_timeGlobal.FUN_0084d030(), updateMode);
            }
        }
        else
        {
            if (g_thePlayer->GetNiNode())
            {
                ++DAT_011e07a8;
                reinterpret_cast<PlayerUpdate*>(g_thePlayer)
                    ->Unk_BE(g_timeGlobal.FUN_0084d030() * DAT_011f2250.FUN_009c8cc0());
                --DAT_011e07a8;
            }
            bChanged = false;
            TESObjectCELL* cell = g_thePlayer->GetParentCell();
            NiPoint3 position = *reinterpret_cast<PlayerCalls*>(g_thePlayer)->GetAddTopicList();
            if (cell && !reinterpret_cast<CellCalls*>(cell)->IsInterior() &&
                !reinterpret_cast<CellCalls*>(cell)->FUN_00550200(position))
            {
                TESObjectCELL* destination =
                    reinterpret_cast<DataHandlerCalls*>(g_dataHandler)
                        ->FUN_00461bc0(position.x, position.y, reinterpret_cast<CellCalls*>(cell)->FUN_0054ddd0(),
                                       true);
                if (destination)
                {
                    if (!reinterpret_cast<CellCalls*>(destination)->FUN_00450fb0() &&
                        !reinterpret_cast<CellCalls*>(destination)->FUN_00450ff0())
                    {
                        reinterpret_cast<WorldUpdateCalls*>(_DAT_011dea10)->FUN_00452580(position, true);
                        if (reinterpret_cast<WorldUpdateCalls*>(_DAT_011dea10)->FUN_00451530())
                        {
                            reinterpret_cast<WorldUpdateCalls*>(_DAT_011dea10)->FUN_00457d70(0, 0, 0);
                        }
                    }
                    FUN_0086fba0(1);
                    reinterpret_cast<PlayerCalls*>(g_thePlayer)->FUN_0086fbc0(1);
                    reinterpret_cast<CellCalls*>(destination)->AddReference(g_thePlayer, false);
                    FUN_0086fbb0(reinterpret_cast<CellCalls*>(destination)->GetAcousticSpace());
                    reinterpret_cast<PlayerCalls*>(g_thePlayer)->FUN_0086fbc0(0);
                    FUN_0086fba0(0);
                    RenderManager* manager = FUN_00b4f5c0();
                    if (manager)
                    {
                        manager->FUN_00b655b0();
                    }
                }
                bChanged = true;
            }
        }
    }
}
}  // namespace fnv_0086f940

namespace fnv_0086d590 {
struct NiAVObject;
struct AutoMemHelper
{
    int context;
    AutoMemHelper(int, int, const char*, int);
    ~AutoMemHelper();
};
void FUN_0086e520(NiNode*);
void FUN_0086e500(bool);
void FUN_0086e510(bool);
void FUN_0086e4d0(unsigned int(__cdecl*)(NiAVObject*));
void FUN_0086e620(int);
void FUN_0086e630(NiNode*);

struct NiFixedString
{
    int value;
    NiFixedString(const char*);
    ~NiFixedString();
    const char* FUN_00438170(const char*);
    void FUN_004381b0();
};
struct ResourceObject;
struct Resource
{
    ResourceObject* object;
    ResourceObject* FUN_00559450();
    void FUN_0066b0d0(void* item);
};
struct ResourceObject
{
    ResourceObject* FUN_006629f0();
    void FUN_00712e60(void*);
    void FUN_0070b760(int);
    void FUN_004a1020(void*);
    ResourceObject* FUN_00558310();
    void FUN_00a5a040();
    void FUN_00a59c60(void*);
    void AssignFixedString(const NiFixedString&);
    void FUN_005468d0(int);
    void FUN_005467c0(int);
    void FUN_00546780(int);
    void SetDepthParams(float);
    void FUN_0049ed90(int);
    void FUN_00439410(void*);
    void FUN_004bc1f0(float, float, float);
    void FUN_004bc450(void*);
    void FUN_005b8fc0(int);
    void FUN_0060aeb0(int);
    void FUN_004f3200(int);
    int FUN_004bc320(int);
    void FUN_0086e3f0(int, int, int);
    void FUN_0086e420(int, float, float, float, float);
    void FUN_0086e4b0();
    void FUN_0086e460(int, int, float, float, float, float);
};
struct ModuleRoot
{
    virtual void virtual_00();
    virtual void virtual_04();
    virtual void virtual_08();
    virtual void virtual_0c();
    virtual void virtual_10();
    virtual void virtual_14();
    virtual void virtual_18();
    virtual void virtual_1c();
    virtual void virtual_20();
    virtual void virtual_24();
    virtual void virtual_28();
    virtual void virtual_2c();
    virtual void virtual_30();
    virtual void virtual_34();
    virtual void virtual_38();
    virtual void virtual_3c();
    virtual void virtual_40();
    virtual void virtual_44();
    virtual void virtual_48();
    virtual void virtual_4c();
    virtual void virtual_50();
    virtual void virtual_54();
    virtual void virtual_58();
    virtual void virtual_5c();
    virtual void virtual_60();
    virtual void virtual_64();
    virtual void virtual_68();
    virtual void virtual_6c();
    virtual void virtual_70();
    virtual void virtual_74();
    virtual void virtual_78();
    virtual void virtual_7c();
    virtual void virtual_80();
    virtual void virtual_84();
    virtual void virtual_88();
    virtual void virtual_8c();
    virtual void virtual_90();
    virtual void virtual_94();
    virtual void virtual_98();
    virtual void virtual_9c();
    virtual void virtual_a0();
    virtual void virtual_a4();
    virtual void virtual_a8();
    virtual void virtual_ac();
    virtual void virtual_b0();
    virtual void virtual_b4();
    virtual void virtual_b8();
    virtual void virtual_bc();
    virtual void virtual_c0();
    virtual void virtual_c4();
    virtual void virtual_c8();
    virtual void virtual_cc();
    virtual void virtual_d0();
    virtual void virtual_d4();
    virtual void virtual_d8();
    virtual void virtual_dc(void*, int);
    virtual void virtual_e0();
    virtual void virtual_e4();
    virtual void virtual_e8();
    virtual void virtual_ec();
    virtual void virtual_f0();
    virtual void virtual_f4();
    virtual void virtual_f8(int, void*);
};

struct SceneObject : ModuleRoot
{
    SceneObject* FUN_00878610(const char*, int, int);
    void FUN_0086e420(float, float, float, float, int);
};
struct DataObject : ModuleRoot
{
    DataObject* FUN_00b5e0f0();
    void FUN_004dc540(void*);
};
struct InputObject : ModuleRoot
{
    InputObject* FUN_00bb8180();
    InputObject* FUN_00c46970();
    InputObject* FUN_00a5ecb0(int);
    InputObject* FUN_00bc2980();
    InputObject* FUN_00c503d0();
    InputObject* FUN_00a87810(void*);
    InputObject* FUN_00a881e0(int, int, int, int, int, int, int, int, int);
    InputObject* FUN_00a75650();
    InputObject* FUN_00a6aa40();
    void FUN_005468d0(int);
    void FUN_00546780(int);
    void FUN_005467c0(int);
    void AssignFixedString(const NiFixedString&);
    void FUN_004bc450(void*);
    void FUN_005b8fc0(int);
    void FUN_0060aeb0(int);
    void FUN_004f3200(int);
    void SetDepthParams(float);
    void FUN_0049ed90(int);
    void FUN_0086e3f0(int, int, int);
    void FUN_0086e420(int, float, float, float, float);
    void FUN_0086e4b0();
    void FUN_0086e460(int, int, float, float, float, float);
};
struct RenderSystem
{
    void FUN_0086d590();
    int unknown_00;
    int unknown_04;
    int unknown_08;
    int unknown_0c;
    int unknown_10;
    int unknown_14;
    int unknown_18;
    int unknown_1c;
    int unknown_20;
    int unknown_24;
    int unknown_28;
    int unknown_2c;
    int unknown_30;
    int unknown_34;
    int unknown_38;
    int unknown_3c;
    int unknown_40;
    int unknown_44;
    int unknown_48;
    int unknown_4c;
    int unknown_50;
    int unknown_54;
    int unknown_58;
    int unknown_5c;
    int unknown_60;
    int unknown_64;
    int unknown_68;
    int unknown_6c;
    int unknown_70;
    int unknown_74;
    int unknown_78;
    int unknown_7c;
    int unknown_80;
    int unknown_84;
    Resource resource88;
    Resource resource8c;
    Resource resource90;
    Resource resource94;
    Resource resource98;
};

extern Resource DAT_011deb7c;
extern Resource DAT_011deb00;
extern Resource DAT_011deb34;
extern Resource DAT_011deda4;
extern Resource DAT_011ded58;
extern Resource DAT_011dec94;
extern Resource DAT_011ded3c;
extern Resource DAT_011f95d8;
extern int DAT_011ad82c;
extern float DAT_011fd870;
extern float DAT_011ad808;
extern unsigned char DAT_011dea28;
extern InputObject* DAT_011dea14;
extern int DAT_011dea18;
extern int DAT_011dea1c;
extern const char str_010829c4[];
extern const char str_01082c9c[];
extern const char str_01082c8c[];
extern const char str_01082c88[];
extern const char str_01082c80[];
extern const char str_01082c78[];
extern const char str_01082c68[];
extern const char str_01082c5c[];
extern const char str_01082c50[];
extern const char str_01082c40[];
extern const char str_01082c28[];
extern float DAT_0101e704;
extern int DAT_011a9b7c;
extern int DAT_011ad840;
extern NiNode* FUN_004bc3f0();
extern unsigned char FUN_004bc400();

extern void FUN_0086e4e0(const char*);
extern void InitRenderSystem();
extern void FUN_00b4f2f0(int, void*);
extern int FUN_00450b80(int);

extern bool FUN_0086e540();
extern bool FUN_0086e560();
extern bool FUN_0086e5a0();
extern bool FUN_0086e580();
extern int FUN_004dc060(int);
extern void FUN_004bc3d0(int);
extern bool FUN_0086e5c0();
extern bool FUN_0086e5e0();
extern unsigned int FUN_00564360(NiAVObject*);
extern void FUN_00b55540(int, void*);
extern void FUN_004dc5c0();
extern void FUN_004dc650();

extern void FUN_004bc1f0();
extern void* FUN_00b4f5c0();
extern unsigned char FUN_0086e600();
extern void UpdateTerrainLODMaxRange();
extern int FUN_004bc320(int);
extern DataObject* FUN_0043c4b0();
extern void* __cdecl FUN_00aa13e0(unsigned int);
struct FUN_00b5e0f0 : NiMemObject
{
    FUN_00b5e0f0();
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
    unsigned int unknown_94;
    unsigned int unknown_98;
    unsigned int unknown_9c;
    unsigned int unknown_a0;
    unsigned int unknown_a4;
    unsigned int unknown_a8;
    unsigned int unknown_ac;
    unsigned int unknown_b0;
    unsigned int unknown_b4;
    unsigned int unknown_b8;
    unsigned int unknown_bc;
    unsigned int unknown_c0;
    unsigned int unknown_c4;
    unsigned int unknown_c8;
    unsigned int unknown_cc;
    unsigned int unknown_d0;
    unsigned int unknown_d4;
    unsigned int unknown_d8;
    unsigned int unknown_dc;
    unsigned int unknown_e0;
    unsigned int unknown_e4;
    unsigned int unknown_e8;
    unsigned int unknown_ec;
    unsigned int unknown_f0;
    unsigned int unknown_f4;
    unsigned int unknown_f8;
    unsigned int unknown_fc;
    unsigned int unknown_100;
    unsigned int unknown_104;
    unsigned int unknown_108;
    unsigned int unknown_10c;
    unsigned int unknown_110;
    unsigned int unknown_114;
    unsigned int unknown_118;
    unsigned int unknown_11c;
    unsigned int unknown_120;
    unsigned int unknown_124;
    unsigned int unknown_128;
    unsigned int unknown_12c;
    unsigned int unknown_130;
    unsigned int unknown_134;
    unsigned int unknown_138;
    unsigned int unknown_13c;
    unsigned int unknown_140;
    unsigned int unknown_144;
    unsigned int unknown_148;
    unsigned int unknown_14c;
    unsigned int unknown_150;
    unsigned int unknown_154;
    unsigned int unknown_158;
    unsigned int unknown_15c;
    unsigned int unknown_160;
    unsigned int unknown_164;
    unsigned int unknown_168;
    unsigned int unknown_16c;
    unsigned int unknown_170;
    unsigned int unknown_174;
    unsigned int unknown_178;
    unsigned int unknown_17c;
    unsigned int unknown_180;
    unsigned int unknown_184;
    unsigned int unknown_188;
    unsigned int unknown_18c;
    unsigned int unknown_190;
    unsigned int unknown_194;
    unsigned int unknown_198;
    unsigned int unknown_19c;
    unsigned int unknown_1a0;
    unsigned int unknown_1a4;
    unsigned int unknown_1a8;
    unsigned int unknown_1ac;
    unsigned int unknown_1b0;
    unsigned int unknown_1b4;
    unsigned int unknown_1b8;
    unsigned int unknown_1bc;
    unsigned int unknown_1c0;
    unsigned int unknown_1c4;
    unsigned int unknown_1c8;
    unsigned int unknown_1cc;
    unsigned int unknown_1d0;
    unsigned int unknown_1d4;
    unsigned int unknown_1d8;
    unsigned int unknown_1dc;
    unsigned int unknown_1e0;
    unsigned int unknown_1e4;
    unsigned int unknown_1e8;
    unsigned int unknown_1ec;
    unsigned int unknown_1f0;
    unsigned int unknown_1f4;
    unsigned int unknown_1f8;
    unsigned int unknown_1fc;
};
struct BSFogProperty : NiMemObject
{
    BSFogProperty();
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
};
struct FUN_00c46970 : NiMemObject
{
    FUN_00c46970();
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
    unsigned int unknown_94;
    unsigned int unknown_98;
    unsigned int unknown_9c;
    unsigned int unknown_a0;
    unsigned int unknown_a4;
    unsigned int unknown_a8;
    unsigned int unknown_ac;
    unsigned int unknown_b0;
};
struct FUN_00a5ecb0 : NiMemObject
{
    FUN_00a5ecb0(unsigned int);
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
    unsigned int unknown_94;
    unsigned int unknown_98;
    unsigned int unknown_9c;
    unsigned int unknown_a0;
    unsigned int unknown_a4;
    unsigned int unknown_a8;
};
struct FUN_00bc2980 : NiMemObject
{
    FUN_00bc2980();
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
    unsigned int unknown_94;
    unsigned int unknown_98;
    unsigned int unknown_9c;
    unsigned int unknown_a0;
    unsigned int unknown_a4;
    unsigned int unknown_a8;
    unsigned int unknown_ac;
    unsigned int unknown_b0;
    unsigned int unknown_b4;
};
struct FUN_00c503d0 : NiMemObject
{
    FUN_00c503d0();
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
    unsigned int unknown_94;
    unsigned int unknown_98;
    unsigned int unknown_9c;
    unsigned int unknown_a0;
    unsigned int unknown_a4;
    unsigned int unknown_a8;
    unsigned int unknown_ac;
    unsigned int unknown_b0;
    unsigned int unknown_b4;
};
struct FUN_00a87810 : NiMemObject
{
    FUN_00a87810(void*);
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
    unsigned int unknown_94;
    unsigned int unknown_98;
    unsigned int unknown_9c;
    unsigned int unknown_a0;
    unsigned int unknown_a4;
    unsigned int unknown_a8;
    unsigned int unknown_ac;
    unsigned int unknown_b0;
    unsigned int unknown_b4;
    unsigned int unknown_b8;
    unsigned int unknown_bc;
    unsigned int unknown_c0;
};
struct FUN_00a881e0 : NiMemObject
{
    FUN_00a881e0(int, int, int, int, int, int, int, int, int);
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
};
struct FUN_00a75650 : NiMemObject
{
    FUN_00a75650();
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
};
struct FUN_00a6aa40 : NiMemObject
{
    FUN_00a6aa40();
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
};
struct NiUpdateData
{
    float time;
    bool updateControllers;
    bool multithreaded;
    unsigned int unknown_08;
    NiUpdateData(float, bool, bool);
};
struct SettingView
{
    float* FUN_00403e20();
};
extern SettingView DAT_011dedc8;
extern const char str_0101fe78[];
// Creates a SceneGraph, associates resources and input objects, configures render state, and initializes additional scene objects.
// @fnv 0x0086d590
void RenderSystem::FUN_0086d590()
{
    // Memory context, scene root, and graph construction.
    AutoMemHelper h(25, 1, str_010829c4, 0xf4c);
    DAT_011deb7c.FUN_0066b0d0(new SceneGraph(str_01082c9c, false, 0));

    DataObject* p = (DataObject*)new FUN_00b5e0f0;
    (FUN_0086e520)(FUN_004bc3f0());
    FUN_0086e4e0(str_01082c8c);
    InitRenderSystem();
    DAT_011deb7c.FUN_00559450()->FUN_006629f0()->FUN_00712e60(&DAT_011ad840);
    ((ResourceObject*)p)->FUN_0070b760(0);
    FUN_00b4f2f0(0, p);
    this->resource88.FUN_00559450()->FUN_004a1020(p);
    this->resource8c.FUN_00559450()->FUN_004a1020(p);
    this->resource90.FUN_00559450()->FUN_004a1020(p);
    this->resource94.FUN_00559450()->FUN_004a1020(p);
    this->resource98.FUN_00559450()->FUN_004a1020((void*)FUN_00450b80(1));
    FUN_0086e500(0);
    FUN_0086e510(0);
    unsigned int f = (FUN_0086e540() == 1 ? 1u : 0u);
    f |= (FUN_0086e560() == 1 ? 2u : 0u);
    f |= (FUN_0086e5a0() == 1 ? 4u : 0u);
    f |= (FUN_0086e580() == 1 ? 8u : 0u);
    f |= 0x10;
    f |= (FUN_004bc400() && FUN_004dc060(0) >= 2) ? 0x20 : 0;
    FUN_004bc3d0(f);
    unsigned int eb = FUN_0086e5c0() ? 8 : 0;
    eb |= FUN_0086e5e0() ? 2 : 0;
    DAT_011ad82c = eb;
    FUN_0086e4d0(FUN_00564360);
    DAT_011fd870 = 0.0f;
    DAT_011f95d8.FUN_0066b0d0(DAT_011deb7c.FUN_00559450()->FUN_006629f0());
    ((ModuleRoot*)DAT_011deb7c.FUN_00559450())->virtual_dc(p, 1);

    DAT_011deb00.FUN_0066b0d0((InputObject*)new BSFogProperty());
    DAT_011deb00.FUN_00559450()->FUN_0049ed90(1);
    DAT_011deb00.FUN_00559450()->SetDepthParams(1.0f);
    FUN_00b55540(0, DAT_011deb00.FUN_00559450());

    DAT_011deb34.FUN_0066b0d0((InputObject*)new FUN_00c46970());
    DAT_011deb34.FUN_00559450()->FUN_005468d0(1);
    DAT_011deb34.FUN_00559450()->FUN_005467c0(1);
    DAT_011deb34.FUN_00559450()->AssignFixedString(NiFixedString(str_01082c88));
    p->virtual_f8(0, DAT_011deb34.FUN_00559450());

    DAT_011deda4.FUN_0066b0d0((InputObject*)new FUN_00a5ecb0(0));
    DAT_011deda4.FUN_00559450()->FUN_00546780(1);
    DAT_011deda4.FUN_00559450()->FUN_005467c0(1);
    DAT_011deda4.FUN_00559450()->AssignFixedString(NiFixedString(str_0101fe78));
    p->virtual_f8(1, DAT_011deda4.FUN_00559450());
    FUN_004dc5c0();
    FUN_004dc650();

    DAT_011dea14 = (InputObject*)new FUN_00bc2980();
    DAT_011dea14->AssignFixedString(NiFixedString(str_01082c80));
    p->virtual_f8(2, DAT_011dea14);

    // s is the active scene parent; a is its tree child.
    InputObject* s = (InputObject*)new FUN_00a5ecb0(0);
    s->FUN_00546780(1);
    s->FUN_005467c0(1);
    s->AssignFixedString(NiFixedString(str_01082c78));
    DAT_011dea14->virtual_dc(s, 1);

    DAT_011ad808 = *DAT_011dedc8.FUN_00403e20();
    s = (InputObject*)new FUN_00a5ecb0(0);
    s->FUN_00546780(1);
    s->FUN_005467c0(1);
    s->AssignFixedString(NiFixedString(str_01082c68));
    DAT_011dea14->virtual_dc(s, 1);

    DAT_011dea1c = (int)(InputObject*)new FUN_00a5ecb0(0);
    ((InputObject*)DAT_011dea1c)->FUN_00546780(1);
    ((InputObject*)DAT_011dea1c)->FUN_005467c0(1);
    ((InputObject*)DAT_011dea1c)->AssignFixedString(NiFixedString(str_01082c5c));
    DAT_011dea14->virtual_dc((InputObject*)DAT_011dea1c, 1);

    InputObject* a = (InputObject*)new FUN_00a5ecb0(0);
    a->FUN_00546780(1);
    a->FUN_005467c0(1);
    a->AssignFixedString(NiFixedString(str_01082c50));
    s->virtual_dc(a, 1);
    FUN_0086e620((int)a);
    (FUN_0086e630)((NiNode*)a);

    DAT_011dea18 = (int)(InputObject*)new FUN_00a5ecb0(0);
    ((InputObject*)DAT_011dea18)->FUN_00546780(1);
    ((InputObject*)DAT_011dea18)->FUN_005467c0(1);
    ((InputObject*)DAT_011dea18)->AssignFixedString(NiFixedString(str_01082c40));
    p->virtual_f8(3, ((InputObject*)DAT_011dea18));

    DAT_011ded58.FUN_0066b0d0((InputObject*)new FUN_00c503d0());
    DAT_011ded58.FUN_00559450()->AssignFixedString(NiFixedString(str_01082c28));
    p->virtual_f8(5, DAT_011ded58.FUN_00559450());

    DAT_011deb7c.FUN_00559450()->FUN_00558310()->FUN_004bc1f0(0.0f, 0.0f, DAT_0101e704);
    DAT_011deb7c.FUN_00559450()->FUN_00a5a040();
    NiUpdateData i(0.0f, false, false);
    DAT_011deb7c.FUN_00559450()->FUN_00a59c60(&i);
    FUN_0043c4b0()->FUN_004dc540(FUN_00b4f5c0());
    DAT_011dea28 = FUN_0086e600();

    if (!DAT_011dec94.FUN_00559450())
    {
        DAT_011dec94.FUN_0066b0d0((InputObject*)new FUN_00a87810(new FUN_00a881e0(0, 0, 1, 1, 1, 4, 1, 2, 1)));
        DAT_011dec94.FUN_00559450()->FUN_0086e3f0(4, 0, 0);
        DAT_011dec94.FUN_00559450()->FUN_0086e420(0, 0.0f, 0.0f, 1.0f, 1.0f);
        DAT_011dec94.FUN_00559450()->FUN_0086e4b0();
        DAT_011dec94.FUN_00559450()->FUN_0086e460(0, 0, 0.0f, 0.0f, 1.0f, 1.0f);
        InputObject* p = (InputObject*)new FUN_00a75650();
        p->FUN_004bc450((void*)&DAT_011a9b7c);
        DAT_011dec94.FUN_00559450()->FUN_00439410(p);
        InputObject* h = (InputObject*)new FUN_00a6aa40();
        h->FUN_005b8fc0(DAT_011ded3c.FUN_00559450()->FUN_004bc320(0));
        h->FUN_0060aeb0(0);
        h->FUN_004f3200(0);
        DAT_011dec94.FUN_00559450()->FUN_00439410(h);
        DAT_011dec94.FUN_00559450()->FUN_00a5a040();
        NiUpdateData i(0.0f, false, false);
        DAT_011dec94.FUN_00559450()->FUN_00a59c60(&i);
    }
    UpdateTerrainLODMaxRange();
}
}  // namespace fnv_0086d590

struct S00875bf0_Cam875
{
    void FUN_00712e60(const struct S00875bf0_Color875&);
};
struct S00875bf0_Color875
{
    float x, y, z, w;
    S00875bf0_Color875(float, float, float, float);
};
struct S00875bf0_Scene875
{
    void FUN_00c4f270(int);
    void FUN_0041fd00(S00875bf0_Cam875*);
    void FUN_004a0fd0(void*);
    void FUN_00c4f2d0();
};
struct S00875bf0_Face875
{
    S00875bf0_Scene875* FUN_008d80e0();
};
struct FORenderedMenu
{
    virtual void v0();
    virtual void v1();
    virtual void* v2();
    S00875bf0_Cam875* FUN_008b6200();
};
FORenderedMenu* FUN_00707ad0();
FORenderedMenu* FUN_00705990();
struct S00875bf0_Ptr875
{
    void* FUN_00559450();
};
struct S00875bf0_Render875
{
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
    virtual void* v6();
    virtual void* v7();
    virtual void* v8();
    virtual void* v9();
    virtual void* v10();
    virtual void* v11();
    virtual void* v12();
    virtual void* v13();
    virtual void* v14();
    virtual void* v15();
    virtual void* v16();
    virtual void* v17();
    virtual void* v18();
    virtual void* v19();
    virtual void* v20();
    virtual void* v21();
    virtual void* v22();
    virtual void* v23();
    virtual void* v24();
    virtual void* v25();
    virtual void* v26();
    virtual void* v27();
    virtual void* v28();
    virtual void* v29();
    virtual void* v30();
    virtual void* v31();
    virtual void* v32();
    virtual void* v33();
    virtual void* v34();
    virtual void* v35();
    virtual void* v36();
    virtual void* v37();
    virtual void* v38();
    virtual void* v39();
    virtual void* v40();
    virtual void* v41();
    virtual void* v42();
    virtual void* v43();
    virtual void* v44();
    virtual void* v45();
    virtual void* v46();
    virtual void* v47();
    virtual void* v48();
    virtual void* v49();
    virtual void* v50();
    virtual void* v51();
};
extern unsigned char DAT_011f9426;
extern S00875bf0_Color875 DAT_011ad840;
void FUN_00b6bee0(S00875bf0_Cam875*, void*, S00875bf0_Scene875*);
struct BSShaderManagerRenderMode
{
    static void SetRenderMode(unsigned int);
};
void FUN_00b97e30(unsigned int, unsigned int);
void FUN_00b98380(int, int);
void FUN_00b6c0d0(S00875bf0_Cam875*, void*, int);
void FUN_004eced0(unsigned int);
void FUN_00714a60(int);
struct S00875bf0_BSA_
{
    void FUN_004a1020(void*);
};
class ShadowSceneNode;
struct S00875bf0_FaceNode875
{
    void* GetAnimationData();
};
struct S00875bf0_Shell875
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
    S00875bf0_Ptr875 scene;
    void FUN_00875bf0();
};
// Sets up the face scene and camera, invokes rendering calls with the target scene, and restores the scene state.
// @fnv 0x00875bf0
void S00875bf0_Shell875::FUN_00875bf0()
{
    if (!g_011deb38.FUN_00559450() && FUN_00707ad0() && FUN_00707ad0() != FUN_00705990())
    {
        S00875bf0_FaceNode875* face = (S00875bf0_FaceNode875*)FUN_0045c670();
        S00875bf0_Scene875* scene = ((S00875bf0_Face875*)face)->FUN_008d80e0();
        scene->FUN_00c4f270(1);
        S00875bf0_Cam875* camera = FUN_00707ad0()->FUN_008b6200() ? FUN_00707ad0()->FUN_008b6200()
                                                                  : (S00875bf0_Cam875*)face->GetAnimationData();
        scene->FUN_0041fd00(camera);
        scene->FUN_004a0fd0(this->scene.FUN_00559450());
        ((S00875bf0_BSA_*)this->scene.FUN_00559450())->FUN_004a1020(FUN_00450b80(0));
        if (DAT_011f9426 &&
            (!((S00875bf0_Render875*)FUN_0043c4b0())->v51() ||
             ((S00875bf0_Render875*)FUN_0043c4b0())->v51() == ((S00875bf0_Render875*)FUN_0043c4b0())->v50()))
            camera->FUN_00712e60(DAT_011ad840);
        else
            camera->FUN_00712e60(S00875bf0_Color875(0.0f, 1.0f, 1.0f, 0.0f));
        FUN_00b6bee0(camera, FUN_00707ad0()->v2(), scene);
        BSShaderManagerRenderMode::SetRenderMode(15);
        FUN_00b97e30(0, 1);
        FUN_00b98380(8, 1);
        FUN_00b6c0d0(camera, this->scene.FUN_00559450(), 0);
        BSShaderManagerRenderMode::SetRenderMode(0);
        FUN_004eced0(1);
        FUN_00714a60(1);
        FUN_00b6bee0(camera, FUN_00707ad0()->v2(), scene);
        FUN_00b6c0d0(camera, this->scene.FUN_00559450(), 0);
        scene->FUN_004a0fd0(0);
        scene->FUN_00c4f2d0();
    }
}
