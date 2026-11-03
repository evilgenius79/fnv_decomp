
// src/fallout/interface/menus/lockpickmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/lockpickmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct LockPickMenu
{
    int FUN_0078da90();
};

// @fnv 0x0078da90
int LockPickMenu::FUN_0078da90()
{
    return 0x3f6;
}

namespace fnv_0078daa0 {
struct Tile
{
    void* m_pRenderedNodeEntry;
};

struct LockPickMenu
{
    Tile* m_pTiles[64];
    void SetTile(int id, Tile* tile);
};

// Stores tile into the menu's tile array at index id when id is in [0,16).
// @fnv 0x0078daa0
void LockPickMenu::SetTile(int id, Tile* tile)
{
    if (id >= 0 && id < 16)
    {
        ((Tile**)((char*)this + 0x2c))[id] = tile;
    }
}
}  // namespace fnv_0078daa0

// @fnv 0x0078e080
int FUN_0078e080()
{
    return 1014;
}

void __fastcall FUN_0078e0f0(void*);
void __cdecl _Deallocate(void*);
struct LockPickMenuProxy
{
    void* FUN_0078dad0(unsigned int);
};
// Calls FUN_0078e0f0 on this, frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0078dad0
void* LockPickMenuProxy::FUN_0078dad0(unsigned int flags)
{
    FUN_0078e0f0(this);
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
struct FUN_007902b0_shell
{
    void FUN_007902b0(int, Tile*);
};
// If aiID is 13, gets the next entry from FUN_004b7210 and calls Set(0xfa9, 0.0f, true) on it as a Tile.
// @fnv 0x007902b0
void FUN_007902b0_shell::FUN_007902b0(int aiID, Tile* apTarget)
{
    if (aiID == 13)
    {
        reinterpret_cast<Tile*>(reinterpret_cast<Proc_S*>(FUN_004b7210())->GetNext())->Set(0xfa9, 0.0f, true);
    }
}

namespace fnv_007902f0 {
struct Tile
{
    void Set(int, float, bool);
};
struct Proc_S
{
    void* GetNext();
};
void* __cdecl FUN_004b7210();
struct Target
{
    void FUN_007902f0(int aiID, Tile* apTarget);
};
// If aiID equals 0xD, gets the next object from FUN_004b7210 and calls Set(0xFA9, 255.0f, true) on it as a Tile.
// @fnv 0x007902f0
void Target::FUN_007902f0(int aiID, Tile* apTarget)
{
    if (aiID == 0xD)
    {
        ((Tile*)((Proc_S*)FUN_004b7210())->GetNext())->Set(0xFA9, 255.0f, true);
    }
}
}  // namespace fnv_007902f0

struct NiPoint3
{
    float x, y, z;
    NiPoint3(float, float, float);
    NiPoint3 FUN_004a0bd0();
    NiPoint3 FUN_00439e90(const NiPoint3&);
    NiPoint3 FUN_00439ef0(const NiPoint3&);
};
struct ThreeByThreeMatrix
{
    float values[3][3];
    ThreeByThreeMatrix();
    void FUN_0043f850(float);
    NiPoint3 FUN_004b4500(const NiPoint3&);
    ThreeByThreeMatrix FUN_0043f8d0(const ThreeByThreeMatrix&);
};
struct NiUpdateData
{
    float time;
    bool updateControllers, multithreaded, updateTransforms, updateBounds, updateProperties;
    NiUpdateData(float, bool, bool);
};
struct Object
{
    void FUN_00440460(const NiPoint3&);
    void FUN_0043fa80(const ThreeByThreeMatrix&);
    void FUN_00a59c60(const NiUpdateData&);
};
struct ObjectRef
{
    Object* FUN_0043b4a0();
};
struct Manager
{
    ObjectRef* FUN_00559450(int);
};
extern Manager DAT_011da24c;
struct ValueTile
{
    float FUN_00a011b0(int);
};
struct LockPickState
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
    ValueTile* tile;
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
    ThreeByThreeMatrix rotation;
    NiPoint3 position;
    void UpdateLockRotation(float amount);
};
// Rotates the lock object by an angle derived from amount and tile->FUN_00a011b0(0xfb1), then applies the rotation and position and updates it.
// @fnv 0x00790df0
void LockPickState::UpdateLockRotation(float amount)
{
    Object* object;
    {
        ThreeByThreeMatrix matrix;
        object = DAT_011da24c.FUN_00559450(1)->FUN_0043b4a0();
        NiUpdateData kUpdateData(0.0f, false, false);
        NiPoint3 offset = position.FUN_004a0bd0().FUN_00439e90(NiPoint3(0.0f, 0.0f, 0.6f));
        matrix.FUN_0043f850((float)((amount / tile->FUN_00a011b0(0xfb1) * -180.0 + 90.0) * 0.01745329238474369));
        object->FUN_00440460(position.FUN_00439e90(offset).FUN_00439ef0(matrix.FUN_004b4500(offset)));
        matrix = matrix.FUN_0043f8d0(rotation);
        object->FUN_0043fa80(matrix);
        object->FUN_00a59c60(kUpdateData);
    }
}

namespace fnv_00790f40 {
struct NiUpdateData
{
    float m_fTime;
    bool m_bUpdate;
    bool m_bIsMultiThreaded;
    int m_iUnk08;
    NiUpdateData(float afTime, bool abUpdateControllers, bool abIsMultiThreaded);
};

struct NiAVObject
{
    void Update(NiUpdateData& arData);
};

struct NiNode
{
    NiAVObject* GetAt(unsigned int auiIndex);
};

struct NiNodePointer
{
    NiNode* m_pObject;
    NiNode* GetObject();
};

extern NiNodePointer g_011da24c;

struct Sequence
{
    float GetStartTime(int aiIndex);
    float GetEndTime();
    float GetCurrentTime();
    void SetTime(float afTime);
};

struct FUN_00790f40_cls
{
    int unk00[35];
    float m_fSequenceTime;
    int unk90[4];
    Sequence* m_pSequence;
    void AdvanceSequence(float afDelta);
};

// @fnv 0x00790f40
void FUN_00790f40_cls::AdvanceSequence(float afDelta)
{
    float fSequenceTimeRatio = (float)((m_fSequenceTime + afDelta) / 90.0);
    NiUpdateData kData(0.0f, true, false);
    if (m_pSequence)
    {
        m_pSequence->SetTime((float)(m_pSequence->GetStartTime(0) +
                                     (m_pSequence->GetEndTime() - m_pSequence->GetCurrentTime()) * fSequenceTimeRatio));
        g_011da24c.GetObject()->GetAt(0)->Update(kData);
    }
}
}  // namespace fnv_00790f40

extern char DAT_011da224;
extern float DAT_01030ff4;

struct SingletonGetter
{
    void* FUN_00559450();
};

struct ProcBase
{
    void FUN_007148c0();
};

struct ObjB
{
    void* FUN_008d80e0();
    void* FUN_006629f0();
};

struct ObjC
{
    void FUN_00c4f270(int);
    void FUN_00c4f2d0();
    void FUN_004a0fd0(void*);
};

struct ObjD
{
    void* FUN_007fd640();
};

struct Guard : SingletonGetter
{
    int unk00;

    Guard(void* p);
    ~Guard();
    void FUN_0066b0d0(int);
};

void* __stdcall FUN_0043c4b0(int, int);
void* __cdecl FUN_0045c670();
void* __cdecl FUN_004b7210();
int __cdecl FUN_00450b80(int);
void __cdecl UpdateCameraFrustum(void*, float);
void __cdecl FUN_00b6bee0(void*, int, void*);
void __cdecl FUN_00b6c0d0(void*, void*, int);

// @fnv 0x0078e7c0
void __cdecl FUN_0078e7c0()
{
    void* v6;
    void* v14;
    void* v18;
    void* v1c3;
    void* v24;

    if (reinterpret_cast<SingletonGetter*>(&DAT_011da24c)->FUN_00559450() == 0)
    {
        return;
    }
    reinterpret_cast<ProcBase*>(FUN_0043c4b0(0, 4))->FUN_007148c0();
    v6 = FUN_0045c670();
    v1c3 = reinterpret_cast<ObjB*>(v6)->FUN_008d80e0();
    reinterpret_cast<ObjC*>(v1c3)->FUN_00c4f270(1);
    v18 = reinterpret_cast<SingletonGetter*>(&DAT_011da224)->FUN_00559450();
    UpdateCameraFrustum(v18, DAT_01030ff4);
    Guard g(reinterpret_cast<ObjD*>(FUN_004b7210())->FUN_007fd640());
    reinterpret_cast<ObjC*>(v1c3)->FUN_004a0fd0(g.FUN_00559450());
    if (v18 != 0)
    {
        v24 = v18;
    }
    else
    {
        v24 = reinterpret_cast<ObjB*>(v6)->FUN_006629f0();
    }
    v14 = v24;
    FUN_00b6bee0(v14, FUN_00450b80(1), v1c3);
    FUN_00b6c0d0(v14, g.FUN_00559450(), 0);
    reinterpret_cast<ObjC*>(v1c3)->FUN_004a0fd0(0);
    g.FUN_0066b0d0(0);
    reinterpret_cast<ObjC*>(v1c3)->FUN_00c4f2d0();
}

namespace fnv_0078e900 {
// Stand-in types are named after the game function whose constructor they wrap.
struct FUN_00416870
{  // 3-float vector
    float unk00;
    float unk04;
    float unk08;
    FUN_00416870(float, float, float);
};
struct FUN_00414430
{  // 4-float rectangle (viewport)
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    FUN_00414430(float, float, float, float);
};
struct FUN_00a71b70
{  // frustum: four edges, near, far, orthographic flag
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    bool unk18;
    FUN_00a71b70(int);
};
struct FUN_0043d410
{  // small 12-byte value object
    float unk00;
    int unk04;
    int unk08;
    FUN_0043d410(float, int, int);
};
struct Setting
{
    float* FUN_00403e20();
};
struct Renderer
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual float vf64();  // vtable slot 0x100: returns the far-plane distance
};
struct FUN_00aa13e0
{  // allocator base: supplies the class operator new
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct FUN_00a712f0 : FUN_00aa13e0
{  // camera object, size 0x114
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
    FUN_00a712f0();
    void FUN_00712e60(FUN_00414430*);
    void FUN_00507700(float);
    void FUN_00a6faf0(FUN_00a71b70*);
    void SetLookAt(const FUN_00416870&, const FUN_00416870&);
    void FUN_00733fd0(float);
    void FUN_00a59c60(FUN_0043d410*);
};
struct FUN_0078e900_shell
{
    FUN_00a712f0* FUN_0078e900();
};

Renderer* FUN_0045c670();
int FUN_004dc200();
int FUN_004dc1f0();
float __cdecl FUN_0057dd70(float);
extern Setting DAT_01203144;
extern Setting DAT_01203150;
extern bool DAT_011f9426;
extern int DAT_011f9434;
extern float DAT_01016264;
extern double DAT_01023128;
extern double DAT_01070c80;

// Builds a camera: viewport, frustum from a field-of-view setting and the
// screen aspect ratio, far/near ratio, and a default orientation.
// Local names are chosen only to reproduce the original stack layout:
//   b = camera, f = viewport rect, c = frustum, g = aspect ratio,
//   d = frustum scale, e = view angle, a = trailing value object.
// @fnv 0x0078e900
FUN_00a712f0* FUN_0078e900_shell::FUN_0078e900()
{
    float g;
    FUN_00a712f0* b = new FUN_00a712f0;
    FUN_00414430 f(0.0f, 1.0f, 1.0f, 0.0f);
    float d;
    b->FUN_00712e60(&f);
    FUN_00a71b70 c(0);
    float e;
    c.unk14 = FUN_0045c670()->vf64();
    c.unk10 = *DAT_01203144.FUN_00403e20();
    b->FUN_00507700(c.unk14 / c.unk10);
    g = (double)(DAT_011f9426 ? DAT_011f9434 : FUN_004dc200()) / FUN_004dc1f0();
    d = DAT_01016264;
    e = *DAT_01203150.FUN_00403e20() * DAT_01023128 * DAT_01070c80;
    c.unk00 = -FUN_0057dd70(e) * d;
    c.unk04 = FUN_0057dd70(e) * d;
    c.unk0c = -FUN_0057dd70(e) * g * d;
    c.unk08 = FUN_0057dd70(e) * g * d;
    c.unk18 = false;
    b->FUN_00a6faf0(&c);
    b->SetLookAt(FUN_00416870(0.0f, 0.0f, 1.0f), FUN_00416870(0.0f, 0.0f, 1.0f));
    b->FUN_00733fd0(1.0f);
    FUN_0043d410 a(0.0f, 0, 0);
    b->FUN_00a59c60(&a);
    return b;
}
}  // namespace fnv_0078e900

unsigned char __cdecl FUN_00709d40();

// @fnv 0x00790290
int __cdecl FUN_00790290()
{
    return ((FUN_00709d40() != 0 ? -1 : 0) & 8) + 0x14;
}

struct BSStringT
{
    char* m_data;
    unsigned short m_dataLen;
    unsigned short m_bufLen;
    BSStringT();
    ~BSStringT();
    const char* FUN_00559450();
};
int __cdecl FUN_00406f60(BSStringT* pkStr, const char* pFormat, ...);

struct LockTile
{
    void FUN_00a01350(int aiID, const char* apString, bool abPropagate);
    void FUN_00700320(int aiID, int aiValue);
    float FUN_00a011b0(int aiID, bool abFlag);
    void FUN_00a012d0(int aiID, float afValue);
    LockTile* FUN_00a03eb0(int aiIndex);
};

struct LockAnimNode
{
    int* FUN_0043d4d0();
    void FUN_0045ce80(int aiValue);
};
extern LockAnimNode* g_apLockNodes0_011a0328[5];
extern LockAnimNode* g_apLockNodes1_011a033c[5];
extern LockAnimNode* g_apLockNodes2_011a0350[5];
extern LockAnimNode* g_apLockNodes3_011a0364[5];

struct PathingActorState
{
    int unk00, unk04, unk08;
    int iBreakCount;
};
struct LockRef
{
    PathingActorState* FUN_00569160();
    void FUN_005789b0();
};

struct ActorValueOwnerStandIn
{
    int FUN_0066ef20(int aiAV);
};
struct PlayerStandIn
{
    char pad00[0xa4];
    ActorValueOwnerStandIn kAVOwner;
};
extern PlayerStandIn* g_player_011dea3c;

struct RNG
{
    unsigned int FUN_00aa5230(unsigned int auiMax);
};
RNG* __cdecl FUN_00476c00();
void __cdecl FUN_005e58f0(int aiEntryPoint, PlayerStandIn* apActor, float* apValue);
int __cdecl FUN_00648d30(int aiSkill, int aiLockLevel);
struct StringSetting
{
    const char* FUN_00403df0();
};
extern StringSetting g_setting_011d3e98;
void __cdecl DispatchMessageToSink(const char* apText, int a2, const char* apIcon, const char* apSound, float afTime,
                                   int a6);
void __cdecl FUN_0078e0d0();
float __cdecl FUN_0040ebd0(float afA, float afB);
float __cdecl FUN_00404010(float afA, float afB);

extern int g_aiLockLevels_011da28c[6];
extern int g_iPickAngle_011da208;
extern int g_iDriverAngle_011da20c;

static const char s_szLockBroken[] = "LOCK BROKEN!  :(";
static const char s_szForceFailIcon[] = "Interface\\Icons\\Message Icons\\glow_message_vaultboy_surprised.dds";
static const char s_szForceFailSound[] = "UILockpickingForceFail";
static const char s_szIntFormat[] = "%d";
extern const char g_szLockPickEnd[] = "";

struct LockPickMenuImpl
{
    char pad00[0x28];
    int unk28;
    char pad2c[0x3c - 0x2c];
    LockTile* unk3c;
    char pad40[0x48 - 0x40];
    LockTile* unk48;
    char pad4c[0x58 - 0x4c];
    LockTile* unk58;
    char pad5c[0x64 - 0x5c];
    LockTile* unk64;
    char pad68[4];
    LockRef* unk6c;
    int unk70;
    int unk74;
    char pad78[0x88 - 0x78];
    int unk88;
    char pad8c[4];
    float unk90;
    char pad94[4];
    unsigned char unk98;

    void HandleLockPickAction(int aiCode, int aiUnused);
};

// @fnv 0x00790330
void LockPickMenuImpl::HandleLockPickAction(int aiCode, int aiUnused)
{
    int iStep = 5;
    switch (aiCode)
    {
    case 10:
        FUN_0078e0d0();
        break;
    case 9: {
        float fPerk = 0.0f;
        FUN_005e58f0(0x20, g_player_011dea3c, &fPerk);
        if (FUN_00476c00()->FUN_00aa5230(100) <
            (unsigned int)FUN_00648d30(g_player_011dea3c->kAVOwner.FUN_0066ef20(0x24), g_aiLockLevels_011da28c[unk70]))
        {
            unk98 = 1;
            unk90 = 90.0f;
            unk28 = 3;
        }
        else if (!unk6c && fPerk == 0.0)
        {
            unk58->FUN_00a01350(0xfc4, s_szLockBroken, true);
            unk58->FUN_00700320(0xfa3, 1);
            unk28 = 6;
        }
        else
        {
            unk6c->FUN_00569160()->iBreakCount++;
            unk6c->FUN_005789b0();
            DispatchMessageToSink(g_setting_011d3e98.FUN_00403df0(), 0, s_szForceFailIcon, s_szForceFailSound, 2.0f, 0);
            FUN_0078e0d0();
        }
        break;
    }
    case 3:
    case 5: {
        int m_eRange = g_aiLockLevels_011da28c[unk70 + 1] - g_aiLockLevels_011da28c[unk70];
        float fT =
            FUN_00404010(FUN_0040ebd0((float)(unk74 - g_aiLockLevels_011da28c[unk70]) / (m_eRange * 2.0f), 1.0f), 0.0f);
        int iDelta = (aiCode != 5 ? 1 : -1) * iStep;
        BSStringT kStr;
        g_iPickAngle_011da208 += iDelta;
        unk88 += iDelta / 2;
        FUN_00406f60(&kStr, s_szIntFormat, g_iPickAngle_011da208);
        unk3c->FUN_00a01350(0xfc4, kStr.FUN_00559450(), true);
        g_apLockNodes0_011a0328[unk70]->FUN_0045ce80(*g_apLockNodes0_011a0328[unk70]->FUN_0043d4d0() +
                                                     (int)(iDelta * (1.0f - fT)));
        g_apLockNodes1_011a033c[unk70]->FUN_0045ce80(*g_apLockNodes1_011a033c[unk70]->FUN_0043d4d0() +
                                                     (int)(iDelta * fT));
        for (int i = 0; i < 6; i++)
        {
            LockTile* pTile = unk64->FUN_00a03eb0(i + 0x11);
            pTile->FUN_00a012d0(0xfb1, pTile->FUN_00a011b0(0xfb1, true) + iDelta);
            pTile->FUN_00a012d0(0xfa1, pTile->FUN_00a011b0(0xfa1, true) - iDelta / 2);
        }
        break;
    }
    case 6:
    case 8: {
        int iRange7 = g_aiLockLevels_011da28c[unk70 + 1] - g_aiLockLevels_011da28c[unk70];
        float fT2_2 =
            FUN_00404010(FUN_0040ebd0((float)(unk74 - g_aiLockLevels_011da28c[unk70]) / (iRange7 * 2.0f), 1.0f), 0.0f);
        int iDeltaX = (aiCode != 8 ? 1 : -1) * iStep;
        BSStringT kStrTmp;
        g_iDriverAngle_011da20c += iDeltaX;
        unk88 += iDeltaX;
        FUN_00406f60(&kStrTmp, s_szIntFormat, g_iDriverAngle_011da20c);
        unk48->FUN_00a01350(0xfc4, kStrTmp.FUN_00559450(), true);
        g_apLockNodes2_011a0350[unk70]->FUN_0045ce80(*g_apLockNodes2_011a0350[unk70]->FUN_0043d4d0() +
                                                     (int)(iDeltaX * (1.0f - fT2_2)));
        g_apLockNodes3_011a0364[unk70]->FUN_0045ce80(*g_apLockNodes3_011a0364[unk70]->FUN_0043d4d0() +
                                                     (int)(iDeltaX * fT2_2));
        for (int j = 1; j < 6; j++)
        {
            LockTile* pTile2 = unk64->FUN_00a03eb0(j + 0x11);
            pTile2->FUN_00a012d0(0xfb1, pTile2->FUN_00a011b0(0xfb1, true) + 2.0 * j * iDeltaX / 5.0);
            pTile2->FUN_00a012d0(0xfa1, pTile2->FUN_00a011b0(0xfa1, true) - j * iDeltaX / 5.0);
        }
        break;
    }
    }
}

extern float DAT_0102978c;
extern double DAT_010718f0;
extern float DAT_01017718;
extern double DAT_01072310;
extern double DAT_01012060;
extern double DAT_01011590;
extern double DAT_010356f8;
extern double DAT_01034208;
extern double DAT_01066808;
extern double DAT_01015a38;
extern char DAT_0107462c;
extern void* DAT_011da1fc;
extern float DAT_011da2c0;

struct OSGlobals
{
    void* FUN_00877720();
};
extern OSGlobals* DAT_011dea0c;

struct FooA
{
    int __thiscall GetAxisState(int a0, int a1);
};
struct DummyA
{
    int __thiscall FUN_00a239e0(int a0);
};

bool __cdecl FUN_004b71d0();
double __cdecl FUN_00408820(float x);
float __cdecl FUN_006494b0(float a0, float a1);
double __cdecl FUN_00715d40();
double __cdecl FUN_00706e50();
float __cdecl FUN_00404010(float a0, float a1);
float __cdecl FUN_0040ebd0(float a0, float a1);
void* __stdcall FUN_00476c00(int n);

struct Checker
{
    int __thiscall FUN_00aa5230();
};

struct BSSoundHandleEx
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    bool __thiscall Play(bool b);
    ~BSSoundHandleEx();
};
struct BSAudio
{
    BSSoundHandleEx __thiscall GetSoundHandleByEditorID(const char* id, unsigned int a1);
};
struct BSAudioS_
{
    static BSAudio* GetSingleton();
};

struct Tile;
struct TileList
{
    void* __thiscall GetHeadPos() const;
    Tile*& __thiscall GetNext(void*& pos);
};
struct ArgObj
{
    float __thiscall FUN_00a011b0(int arg);
    void __thiscall FUN_00a012d0(int id, float v, bool b);
};
struct Obj64 : ArgObj
{
    int m_iWordAt00;
    TileList m_iWordAt04;
};
struct Obj : ArgObj
{
};

struct C
{
    int m_00[25];
    Obj64* m_64;
    Obj* m_68;
    int m_6c[6];
    float m_84;
    int m_88;
    int m_8c;
    float m_90;
    void __thiscall UpdateLockRotation(float v);
    void __thiscall FUN_007908f0();
};

// Computes a sound value from game state, clamps it, plays a sound on threshold crossings, stores it, and updates m_90 from nearby tiles.
// @fnv 0x007908f0
void __thiscall C::FUN_007908f0()
{
    float RunSeventhVirtualOperation = 0.0f;
    long cnt4 = 0;
    float denom;
    denom = DAT_0102978c;
    if (FUN_004b71d0())
    {
        cnt4 = ((FooA*)DAT_011dea0c->FUN_00877720())->GetAxisState(0, 7);
        if (FUN_00408820((float)cnt4) <= DAT_010718f0)
        {
            cnt4 = 0;
        }
        RunSeventhVirtualOperation = (float)(FUN_006494b0((float)cnt4 / denom, DAT_01017718) * DAT_01072310);
    }
    else
    {
        RunSeventhVirtualOperation = (float)((double)((DummyA*)DAT_011dea0c->FUN_00877720())->FUN_00a239e0(1) *
                                             (FUN_00715d40() / FUN_00706e50()));
    }
    float kVal = m_68->FUN_00a011b0((int)DAT_011da1fc) + RunSeventhVirtualOperation;
    int remA8 = (int)m_68->FUN_00a011b0((int)DAT_011da1fc) % 100;
    int val3 = (int)kVal % 100;
    kVal = FUN_00404010(kVal, 0.0f);
    kVal = FUN_0040ebd0(kVal, m_64->FUN_00a011b0(0xfb1));

    if (((RunSeventhVirtualOperation > DAT_01012060 && remA8 > val3) ||
         (RunSeventhVirtualOperation < DAT_01012060 && val3 > remA8)) &&
        ((Checker*)FUN_00476c00(10))->FUN_00aa5230() == 0)
    {
        BSAudioS_::GetSingleton()->GetSoundHandleByEditorID(&DAT_0107462c, 0x101).Play(false);
    }
    else if (RunSeventhVirtualOperation != DAT_01012060 && DAT_011da2c0 == DAT_01012060)
    {
        BSAudioS_::GetSingleton()->GetSoundHandleByEditorID(&DAT_0107462c, 0x101).Play(false);
    }
    m_68->FUN_00a012d0((int)DAT_011da1fc, kVal, true);
    DAT_011da2c0 = RunSeventhVirtualOperation;
    UpdateLockRotation(kVal);
    float x9 = (float)FUN_00408820(kVal - m_84);
    if (x9 < (float)m_88)
    {
        unsigned long res4;
        float aV5;
        void* elem9 = m_64->m_iWordAt04.GetHeadPos();
        aV5 = m_64->FUN_00a011b0(0xfb1);
        res4 = 0;
        while (elem9 != 0)
        {
            Tile* bestElem6 = m_64->m_iWordAt04.GetNext(elem9);
            float a3 = (float)(((ArgObj*)bestElem6)->FUN_00a011b0(0xfb1) / DAT_01011590);
            if (a3 < aV5 && x9 < a3)
            {
                aV5 = a3;
                res4 = (int)bestElem6;
            }
        }
        if (res4 != 0)
        {
            m_90 = (float)((1.0 - (((ArgObj*)(void*)res4)->FUN_00a011b0(0xfaa) - DAT_010356f8) / DAT_01034208) *
                           DAT_01066808);
            m_68->FUN_00a012d0(0xfb2, ((ArgObj*)(void*)res4)->FUN_00a011b0(0xfb2), true);
            m_68->FUN_00a012d0(0xfb3, ((ArgObj*)(void*)res4)->FUN_00a011b0(0xfb3), true);
            m_68->FUN_00a012d0(0xfb4, ((ArgObj*)(void*)res4)->FUN_00a011b0(0xfb4), true);
        }
    }
    else
    {
        float resultB_2;
        resultB_2 = (float)(((double)m_88 + x9 - m_64->FUN_00a011b0(0xfb1)) /
                            ((double)m_88 * DAT_01011590 - m_64->FUN_00a011b0(0xfb1)));
        m_90 = (float)(resultB_2 * DAT_01015a38);
        m_68->FUN_00a012d0(0xfb2, m_64->FUN_00a011b0(0xfb2), true);
        m_68->FUN_00a012d0(0xfb3, m_64->FUN_00a011b0(0xfb3), true);
        m_68->FUN_00a012d0(0xfb4, m_64->FUN_00a011b0(0xfb4), true);
    }
}

// InitLockInterface v1 worker20: faithful transcription from capstone ORIG
struct ModelLoader
{
    void* LoadModel(const char* path, int a, bool b, bool c, bool d, bool e);
};
extern ModelLoader* DAT_011c3b3c;
struct SetHelper
{
    int m_00;
    int m_04;
    int m_08;
    NiPoint3* Set(float a, float b, float c);
};
struct NiNode
{
    void FUN_00440460(NiPoint3& p);
    void FUN_0043fa80(void* child);
    void FUN_00a59c60(void* upd);
    void FUN_004bc1f0(float a, float b, float c);
};
struct SortNode
{
    SortNode* FUN_00a5ecb0(unsigned int a);
};
class NiMemObject
{
  public:
    static void* operator new(unsigned int sz);
    static void operator delete(void*, unsigned int);
};
class NiSortAdjustNode : public NiMemObject
{
  public:
    NiSortAdjustNode(unsigned int a);
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
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
};
extern "C" void* __cdecl FUN_00aa13e0(unsigned int n);
struct Glob
{
    void FUN_0066b0d0(void* p);
    void* FUN_00559450();
};
extern void* DAT_011f36ac;
struct MatA
{
    int m_00[9];
    void FUN_006815c0();
    void FUN_00524ac0(float f);
};
struct MatB
{
    int m_00[9];
    void FUN_006815c0();
    void FUN_004a0c90(float f);
};
struct MatrixResult
{
    int values[9];
};
struct Comb
{
    MatrixResult FUN_0043f8d0(void* a);
};
struct UpdData
{
    float time;
    bool updateControllers, multithreaded, updateTransforms, updateBounds, updateProperties;
    void FUN_0043d410(float a, bool b, bool c);
};
struct AVObj
{
    void* FUN_00a5c570(void* rtti);
    NiPoint3* FUN_0043d450();
};
struct NiFixedString
{
    void* m_00;
    NiFixedString(const char* s);
    ~NiFixedString();
};
struct CtrlNode
{
    void* FUN_0047a520(const NiFixedString& str);
    void FUN_0048fef0(float f);
    void FUN_0047aab0(void* child, int a, int b, float c, float d, int e);
};
struct ChildObj
{
    bool FUN_007408d0(int a);
};
extern "C" void __cdecl FUN_00a6d2d0(void* p);
extern "C" void* __cdecl FUN_00450b80(unsigned int a);
struct TimeObj
{
    float FUN_0084d030();
};
struct SceneNode
{
    void FUN_00b5ca70(void* a, float f);
};
struct VObj
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
    virtual void f38();
    virtual void f3c();
    virtual void f40();
    virtual void f44();
    virtual void f48();
    virtual void f4c();
    virtual void f50();
    virtual void f54();
    virtual void f58();
    virtual void f5c();
    virtual void f60();
    virtual void f64();
    virtual void f68();
    virtual void f6c();
    virtual void f70();
    virtual void f74();
    virtual void f78();
    virtual void f7c();
    virtual void f80();
    virtual void f84();
    virtual void f88();
    virtual void f8c();
    virtual void f90();
    virtual void f94();
    virtual void f98();
    virtual void f9c();
    virtual void fa0();
    virtual void fa4();
    virtual void fa8();
    virtual void fac();
    virtual void fb0();
    virtual void fb4();
    virtual void fb8();
    virtual void fbc();
    virtual void fc0();
    virtual void fc4();
    virtual void fc8();
    virtual void fcc();
    virtual void fd0();
    virtual void fd4();
    virtual void fd8();
    virtual void m_dc(void* a, int b);
};
struct Mat9
{
    int d[9];
};
extern unsigned char DAT_011a9448;
struct ThisCls
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
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    CtrlNode* m_9c;
    ChildObj* m_a0;
    CtrlNode* m_a4;
    ChildObj* m_a8;
    int m_ac;
    ChildObj* m_b0;
    Mat9 m_b4;
    NiPoint3 m_d8;
    void* FUN_0078e900();
    void InitLockInterface();
};

// Loads the lock interface and bobby pin NIFs, sets up their scene nodes and controllers, and attaches the resulting node to the scene.
// @fnv 0x0078e1c0
void ThisCls::InitLockInterface()
{
    void* pin;
    pin = DAT_011c3b3c->LoadModel("Meshes\\Terminals\\LockInterface01.NIF", 0, true, false, false, false);
    void* idx;
    idx = DAT_011c3b3c->LoadModel("Meshes\\Terminals\\BobbyPin01.NIF", 0, true, false, false, false);
    *(Mat9*)&m_b4 = *(Mat9*)&DAT_011a9448;
    {
        SetHelper n;
        m_d8 = *n.Set(0.0f, 0.0f, -1.6f);
    }
    ((NiNode*)idx)->FUN_00440460(m_d8);
    ((NiNode*)idx)->FUN_0043fa80(&m_b4);
    ((Glob*)&DAT_011da24c)->FUN_0066b0d0(new NiSortAdjustNode(0));
    ((VObj*)((Glob*)&DAT_011da24c)->FUN_00559450())->m_dc(pin, 1);
    ((VObj*)((Glob*)&DAT_011da24c)->FUN_00559450())->m_dc(idx, 1);
    MatA ptr;
    ptr.FUN_006815c0();
    MatB z;
    z.FUN_006815c0();
    ptr.FUN_00524ac0(1.57079637f);
    z.FUN_004a0c90(1.57079637f);
    ((NiNode*)((Glob*)&DAT_011da24c)->FUN_00559450())->FUN_0043fa80(&((Comb*)&ptr)->FUN_0043f8d0(&z));
    ((NiNode*)((Glob*)&DAT_011da24c)->FUN_00559450())->FUN_004bc1f0(125.0f, 0.0f, 0.0f);
    UpdData i;
    i.FUN_0043d410(0.0f, false, false);
    ((NiNode*)((Glob*)&DAT_011da24c)->FUN_00559450())->FUN_00a59c60(&i);
    void* s;
    s = ((AVObj*)pin)->FUN_00a5c570(&DAT_011f36ac);
    CtrlNode* r;
    if (!!s)
    {
        r = (CtrlNode*)s;
        m_9c = (CtrlNode*)r->FUN_0047a520(NiFixedString("Forward"));
        m_a0 = (ChildObj*)r->FUN_0047a520(NiFixedString("Backward"));
        r->FUN_0048fef0(0.0f);
        if (!!m_9c)
        {
            r->FUN_0047aab0(m_9c, 0, 1, 1.0f, 0.0f, 0);
        }
        if (!!m_a0)
        {
            m_a0->FUN_007408d0(2);
        }
        FUN_00a6d2d0(pin);
    }
    void* cnt;
    cnt = ((AVObj*)idx)->FUN_00a5c570(&DAT_011f36ac);
    if (!!cnt)
    {
        m_a4 = (CtrlNode*)cnt;
        m_a8 = (ChildObj*)m_a4->FUN_0047a520(NiFixedString("Forward"));
        m_ac = (int)m_a4->FUN_0047a520(NiFixedString("Backward"));
        m_b0 = (ChildObj*)m_a4->FUN_0047a520(NiFixedString("Left"));
        m_a4->FUN_0048fef0(0.0f);
        if (!!m_a8)
        {
            m_a4->FUN_0047aab0(m_a8, 0, 1, 1.0f, 0.0f, 0);
        }
        if (!!m_b0)
        {
            m_b0->FUN_007408d0(2);
        }
        FUN_00a6d2d0(idx);
    }
    ((Glob*)&DAT_011da224)->FUN_0066b0d0(FUN_0078e900());
    ((VObj*)FUN_00450b80(1))->m_dc(((Glob*)&DAT_011da24c)->FUN_00559450(), 1);
    float val;
    val = (float)(((TimeObj*)((AVObj*)((Glob*)&DAT_011da24c)->FUN_00559450())->FUN_0043d450())->FUN_0084d030() * 3.0);
    ((SceneNode*)FUN_00450b80(1))->FUN_00b5ca70(((Glob*)&DAT_011da24c)->FUN_00559450(), val);
}

struct ImageSpaceEffectParam
{
    float r, g, b, a;
    ImageSpaceEffectParam(float, float, float, float);
    ImageSpaceEffectParam FUN_00532ec0(const ImageSpaceEffectParam&);
    ImageSpaceEffectParam ScaleVector4(float);
    ImageSpaceEffectParam AddDelta(const ImageSpaceEffectParam&);
};
struct StrMem
{
    char* data;
    unsigned short length, capacity;
    StrMem();
    ~StrMem();
    const char* FUN_00559450();
};
int __cdecl FUN_00406f60(StrMem*, const char*, ...);
struct PickTile
{
    void FUN_00a04150();
    void FUN_00a01350(int, const char*, bool);
    float FUN_00a011b0(int);
    void FUN_00700320(int, int);
    void FUN_00a012d0(int, float, bool);
};
struct PickTemplate
{
    PickTile* AddTileFromTemplate();
};
struct PickWrapper
{
    PickTemplate* FUN_00639b40();
};
struct PickRandom
{
    float FUN_004dff60();
};

extern int DAT_011da28c[6];
struct PickMenu
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    PickTile* unk3c;
    int unk40, unk44;
    PickTile* unk48;
    int unk4c, unk50, unk54, unk58, unk5c, unk60;
    PickTile* unk64;
    int unk68, unk6c, unk70, unk74, unk78, unk7c, unk80;
    float unk84;
    int unk88;
    PickWrapper* FUN_00726070(PickTile*, const char*, int);
    void UpdateSweetSpot();
};
// Interpolates pick and driver angles from lock nodes, updates the two angle labels, and builds six sweet-spot tiles with fading colors.
// @fnv 0x00791000
void PickMenu::UpdateSweetSpot()
{
    float fraction;
    int angle = DAT_011da28c[unk70 + 1] - DAT_011da28c[unk70];
    fraction = FUN_00404010(FUN_0040ebd0((float)(unk74 - DAT_011da28c[unk70]) / ((float)angle * 2.0f), 1.0f), 0.0f);
    int range = 0;
    int start = 6;
    ImageSpaceEffectParam end(0.0f, 1.0f, 0.0f, 1.0f);
    ImageSpaceEffectParam color(1.0f, 0.0f, 0.0f, 1.0f);
    ImageSpaceEffectParam count = end;
    unk64->FUN_00a04150();
    StrMem text;
    g_iPickAngle_011da208 =
        (int)(*g_apLockNodes0_011a0328[unk70]->FUN_0043d4d0() +
              (*g_apLockNodes1_011a033c[unk70]->FUN_0043d4d0() - *g_apLockNodes0_011a0328[unk70]->FUN_0043d4d0()) *
                  fraction);
    g_iDriverAngle_011da20c =
        (int)(*g_apLockNodes2_011a0350[unk70]->FUN_0043d4d0() +
              (*g_apLockNodes3_011a0364[unk70]->FUN_0043d4d0() - *g_apLockNodes2_011a0350[unk70]->FUN_0043d4d0()) *
                  fraction);
    FUN_00406f60(&text, "%d", g_iPickAngle_011da208);
    unk3c->FUN_00a01350(0xfc4, text.FUN_00559450(), true);
    FUN_00406f60(&text, "%d", g_iDriverAngle_011da20c);
    unk48->FUN_00a01350(0xfc4, text.FUN_00559450(), true);
    unk88 = g_iDriverAngle_011da20c + g_iPickAngle_011da208 / 2;
    unk84 = unk64->FUN_00a011b0(0xfb1) * ((PickRandom*)FUN_00476c00())->FUN_004dff60();
    unk84 = FUN_0040ebd0(FUN_00404010(unk84, (float)unk88), unk64->FUN_00a011b0(0xfb1) - unk88);
    range = (int)(unk84 - g_iPickAngle_011da208 / 2);
    for (int i = 0; i < 6; i++)
    {
        PickTile* tile = FUN_00726070(unk64, "LPM_SweetSpotTemplate", 0)->FUN_00639b40()->AddTileFromTemplate();
        tile->FUN_00700320(0xfaa, i + 17);
        tile->FUN_00a012d0(0xfb1, (unk84 - range) * 2.0f, true);
        tile->FUN_00700320(0xfa1, range);
        tile->FUN_00700320(0xfad, start);
        tile->FUN_00a012d0(0xfb2, (float)(count.r * 255.0), true);
        tile->FUN_00a012d0(0xfb3, (float)(count.g * 255.0), true);
        tile->FUN_00a012d0(0xfb4, (float)(count.b * 255.0), true);
        range -= g_iDriverAngle_011da20c / 5;
        start--;
        count = end.AddDelta(color.FUN_00532ec0(end).ScaleVector4((float)((i + 1) / 5.0)));
    }
}

struct LKSoundHandle
{
    unsigned int m_uiID;
    unsigned int m_uiState;
    unsigned int m_uiValue1;
    ~LKSoundHandle();
    bool Play(bool bLoop);
};

class LKAudio
{
  public:
    static LKAudio* FUN_00453a70();
    LKSoundHandle FUN_00ad7550(const char* pcName, int iFlags);
};

class LKSelection
{
  public:
    virtual ~LKSelection();
};

class LKTile
{
  public:
    float FUN_00a011b0(int m_iValueId);
    void FUN_00a012d0(int m_iValueId, float fValue, int iFlag);
    void FUN_00a01350(int m_iValueId, const char* pcValue, int iFlag);
    void SetTraitAndReset(int m_iValueId, float fValue);
    void FUN_00700320(int m_iValueId, int iValue);
    LKTile* FUN_00a03c90();
    LKTile* FUN_00a03da0(const char* pcName);
};

struct LKMenuFile
{
    LKTile* ReadXML();
};
struct LKInterface
{
    LKMenuFile* FUN_00586150(const char* pcPath);
};

class LKMenu
{
  public:
    virtual ~LKMenu();
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
    virtual int GetID();  // +0x34
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
    LKTile* m_pkSkillTile;  // +0x2c
    LKTile* m_pkHealthBar;  // +0x30
    LKTile* m_pkLevelTile;  // +0x34
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    LKTile* m_pkSkillLabel;  // +0x50
    LKTile* m_pkLevelLabel;  // +0x54
    int unk58;
    LKTile* m_pkHealthLabel;  // +0x5c
    int unk60;
    int unk64;
    int unk68;
    LockRef* m_pkLockRef;  // +0x6c
    int m_iLockLevel;      // +0x70
    int m_iPickCount;      // +0x74

    void FUN_00a1dc70(LKTile* pkTile, int iFlag);
    bool FUN_0078e090();
    LKTile* FUN_00726070();
    void InitLockInterface();
    void UpdateSweetSpot();
    void FUN_00a1dc20(int iFlag);
};

struct LKRef
{
    int FUN_005691b0();
};
struct LKPlayer
{
    int FUN_00575610(int iItem);
};

extern LKMenu* DAT_011da204;
extern int DAT_011da1f8;
extern int DAT_011ca268;
extern StringSetting DAT_011d1efc;
extern StringSetting DAT_011d345c;
extern StringSetting DAT_011c3cb4;
extern StringSetting DAT_011d4d2c;
extern StringSetting DAT_011d4360;
extern StringSetting DAT_011d25bc;
extern StringSetting DAT_011d33fc;
extern StringSetting* DAT_01184a98[];

LKSelection* FUN_00a09030(int m_uiSoundID);
int FUN_00430b40(int iValue);
int FUN_00647b70(int iValue, int iMin);
int MinInt(int iValue, int iMax);
int FUN_00406d00(char* pcBuffer, unsigned int uiSize, const char* pcFormat, ...);
int FUN_00406d50(char* pcBuffer, unsigned int uiSize, const char* pcText);
void FUN_005b5e40(const char* pcMessage);
int TraitNameToID(const char* pcTrait);
float FUN_00a01530();
int FUN_00408b20(const char* pcA, const char* pcB);

// Creates the lockpick UI menu from lockpick_menu.xml, sets skill, level, and pick count labels, and returns the menu tile or null on failure.
// @fnv 0x0078db00
LKTile* CreateLockpickMenu(LockRef* pkLockRef, int aiLockLevel, bool bDebug)
{
    char acMessageVal[260];
    char acLabel[64];
    LKSelection* pkSelection = FUN_00a09030(0x3f6);
    LKInterface* pkInterfaceVal = (LKInterface*)FUN_004b7210();
    int iLockLevelNum = pkLockRef ? FUN_00430b40(((LKRef*)pkLockRef)->FUN_005691b0()) : aiLockLevel;
    iLockLevelNum = MinInt(FUN_00647b70(iLockLevelNum, 0), 4);
    if (pkLockRef && g_player_011dea3c->kAVOwner.FUN_0066ef20(0x24) < g_aiLockLevels_011da28c[iLockLevelNum])
    {
        FUN_00406d00(acMessageVal, 0x104, DAT_011d1efc.FUN_00403df0(), g_aiLockLevels_011da28c[iLockLevelNum]);
        DispatchMessageToSink(acMessageVal, 0, "Interface\\Icons\\Message Icons\\glow_message_padlock.dds", 0, 2.0f, 0);
        LKAudio::FUN_00453a70()->FUN_00ad7550("UIPopUpMessageGeneral", 0x121).Play(false);
        return 0;
    }
    if (pkSelection)
        delete pkSelection;
    LKTile* pkMenuTileNew = pkInterfaceVal->FUN_00586150("Data\\Menus\\lockpick_menu.xml")->ReadXML();
    DAT_011da204 = (LKMenu*)pkMenuTileNew->FUN_00a03c90();
    if (DAT_011da204 && DAT_011da204->GetID() == FUN_0078e080())
    {
        DAT_011da204->FUN_00a1dc70(pkMenuTileNew, 0);
        if (!DAT_011da204->FUN_0078e090())
        {
            FUN_005b5e40("MENUS: Lockpicking Menu Creation Failed... Are your menu and art resources up to date?");
            return 0;
        }
        if (pkMenuTileNew->FUN_00a011b0(0xfa7) == 6006.0 || pkMenuTileNew->FUN_00a011b0(0xfa7) == 102.0)
            pkMenuTileNew->FUN_00a012d0(0xfad, FUN_00a01530(), 1);
        DAT_011da204->m_pkLockRef = pkLockRef;
        DAT_011da204->m_iLockLevel = iLockLevelNum;
        DAT_011da204->FUN_00726070()->FUN_00700320(TraitNameToID("_DebugMode"), bDebug);
        FUN_00406d00(acLabel, 0x40, "%d", DAT_011da204->m_iPickCount);
        DAT_011da204->m_pkSkillTile->FUN_00a01350(DAT_011da1f8, acLabel, 1);
        FUN_00406d00(acLabel, 0x40, "%s [%d", DAT_011d345c.FUN_00403df0(),
                     FUN_00648d30(g_player_011dea3c->kAVOwner.FUN_0066ef20(0x24),
                                  g_aiLockLevels_011da28c[DAT_011da204->m_iLockLevel]));
        FUN_00406d50(acLabel, 0x40, "%]");
        DAT_011da204->m_pkSkillLabel->FUN_00a01350(0xfc4, acLabel, 1);
        DAT_011da204->m_pkLevelTile->FUN_00a01350(DAT_011da1f8,
                                                  DAT_01184a98[DAT_011da204->m_iLockLevel]->FUN_00403df0(), 1);
        DAT_011da204->m_pkHealthLabel->FUN_00a01350(0xfc4, "PICK HEALTH: 100%", 1);
        DAT_011da204->m_pkHealthBar->SetTraitAndReset(DAT_011da1f8, 1.0f);
        DAT_011da204->m_pkHealthBar->FUN_00700320(
            DAT_011da1f8, pkLockRef ? ((LKPlayer*)g_player_011dea3c)->FUN_00575610(DAT_011ca268) : 0);
        if (FUN_00408b20(DAT_011c3cb4.FUN_00403df0(), "ENGLISH"))
        {
            pkMenuTileNew->FUN_00a03da0("LPM_SkillTitle")->FUN_00a01350(0xfc4, DAT_011d4d2c.FUN_00403df0(), 1);
            pkMenuTileNew->FUN_00a03da0("LPM_PickCountTitle")->FUN_00a01350(0xfc4, DAT_011d4360.FUN_00403df0(), 1);
            pkMenuTileNew->FUN_00a03da0("LPM_LevelTitle")->FUN_00a01350(0xfc4, DAT_011d25bc.FUN_00403df0(), 1);
            DAT_011da204->m_pkLevelLabel->FUN_00a01350(0xfc4, DAT_011d33fc.FUN_00403df0(), 1);
        }
        DAT_011da204->InitLockInterface();
        DAT_011da204->UpdateSweetSpot();
        DAT_011da204->FUN_00a1dc20(0);
        return pkMenuTileNew;
    }
    else
    {
        if (DAT_011da204 && DAT_011da204->FUN_00726070())
            delete DAT_011da204;
    }
    return 0;
}

class xMenuBase
{
  public:
    int m_aiBase[9];
    xMenuBase();
    ~xMenuBase();
    virtual void Handle();
};

class xBlock24
{
  public:
    int m_ai[9];
    xBlock24();
};

class xAVOwner
{
  public:
    int GetValue(int iAV);
};
class xPlayerL
{
  public:
    int m_aiPad[0x29];
    xAVOwner m_kAV;
};
extern xPlayerL* xThePlayer;
struct xSetting
{
    float* Float();
};
extern xSetting xS0de0;
extern int xTraitValue;
extern int xTraitX;
int xGetTrait(const char* pName, int i);

class xLevelMenu : public xMenuBase
{
  public:
    int m_i28;
    int m_aiPad1[0x12];
    int m_i74;
    float m_f78;
    int m_i7c;
    int m_i80;
    int m_aiPad2[2];
    float m_f8c;
    int m_i90;
    float m_f94;
    bool m_b98;
    bool m_b99;
    int m_i9c;
    int m_iA0;
    int m_iA4;
    int m_iA8;
    int m_iAC;
    int m_iB0;
    xBlock24 m_kB4;
    xBlock24 m_kD8;
    xLevelMenu();
    virtual void Handle();
};

// Initializes xLevelMenu by reading trait indices and player AV value, then sets default member values.
// @fnv 0x0078d930
xLevelMenu::xLevelMenu()
{
    xTraitValue = xGetTrait("_Value", -1);
    xTraitX = xGetTrait("_x", -1);
    m_i74 = xThePlayer->m_kAV.GetValue(0x24);
    m_f78 = (float)m_i74;
    m_f8c = 0.0f;
    m_f94 = 1.0f + m_f78 * *xS0de0.Float();
    m_i28 = 0;
    m_b98 = false;
    m_i9c = 0;
    m_iA0 = 0;
    m_iA8 = 0;
    m_iAC = 0;
    m_iB0 = 0;
    m_b99 = false;
    m_i80 = 0;
}

namespace fnv_0078eb50 {
struct xUpdateData
{
    xUpdateData(float, bool, bool);
    float m_t;
    bool m_kPointA, m_kPointB, m_iThirdValue, m_iFourthElementInteger, m_usTrailingValue;
};
struct xPoint3
{
    float x, y, z;
};
struct xMat3
{
    float m[9];
};
struct xRTTI
{
    int m_iWordAt00;
};
extern xRTTI xg_rtti_11f36ac;
struct xSeq
{
    float FUN_00508100();
    float FUN_00759450();
    void FUN_00a328b0(float, int);
};
struct xCtrlMgr
{
    void FUN_0047b220(xSeq*, float);
    void FUN_0047aab0(xSeq*, int, int, float, float, int);
    void FUN_0048fef0(float);
};
struct xAV
{
    xAV* FUN_0043b4a0(unsigned int);
    void FUN_00a59c60(const xUpdateData&);
    void* FUN_00a5c570(const xRTTI*);
    const xPoint3& FUN_0043c490();
    void FUN_00440460(const xPoint3&);
    void FUN_0043fa80(const xMat3&);
};
struct xNodePtr
{
    xAV* FUN_00559450();
};
extern xNodePtr xg_spNode_11da24c;
struct xTile
{
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float, bool);
    void FUN_00a01350(int, const char*, bool);
    void FUN_00700320(int, int);
};
struct xMenuMode
{
    bool FUN_00718840(int);
    bool FUN_00718630(int, int, int);
};
struct xIface
{
    char m_auiShapeKeys[0x4d4];
    xMenuMode m_4d4;
    xTile* FUN_0045cd60();
    static bool FUN_004b71d0();
    void FUN_00718930(int);
};
xIface* xF4b7210();
struct xControls
{
    int GetAxisState(int, int);
    void ResetTargetState();
    void FUN_00a255b0(float, float, int, int, int, int, int);
};
struct xOS
{
    xControls* FUN_00877720();
};
extern xOS* xg_os_11dea0c;
struct ClockSource
{
    int FUN_00825c00();
};
extern ClockSource xg_timer_11f6394;
struct xSound
{
    xSound();
    ~xSound();
    xSound& operator=(const xSound&);
    bool Play(bool);
    void FUN_00ad8da0(int);
    int m_iWordAt00, m_iWordAt04, m_8;
};
struct xAudio
{
    static xAudio* FUN_00453a70();
    xSound FUN_00ad7550(const char*, unsigned int);
};
struct xStrSetting
{
    const char* FUN_00403df0();
};
struct xFltSetting
{
    float* FUN_00403e20();
};
extern xStrSetting xg_s_11d34ec;
extern xFltSetting xg_f_11cde20;
extern xFltSetting xg_f_11d41c8;
extern xFltSetting xg_f_11d0de0;
struct xForm
{
    int FUN_00401170();
};
struct xLock
{
    int m_iWordAt00, m_iWordAt04, m_8, m_iThirdValue, m_10;
};
struct xFaction : xForm
{
    bool FUN_0047d7c0();
};

struct xAVOwner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetAV(int);
};

struct xNPC : xForm
{
    char m_auiShapeKeys[0x100];
    xAVOwner m_100;
};
struct xPlayer;
struct xRef : xForm
{
    xLock* FUN_00569160();
    void FUN_005789b0();
    xForm* FUN_00567790();
    void FUN_005692a0();
    xForm* FUN_007af430();
    bool Activate(xPlayer*, int, int, int);
};
struct xCrimeMgr
{
    void* FUN_00970b30(xFaction*, int, int);
    void* FUN_00970a20(xNPC*, int);
};
extern xCrimeMgr xg_crime_11e0e80;

struct xPlayer
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
    virtual void RemoveItem(void*, int, int, int, int, int, int, int, int, int);
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
    virtual void v290(int);
    char m_auiShapeKeys[0x208];
    bool m_20c;
    void FUN_00915d20(int);
    void FUN_008bfa40(void*, int, int, int, xForm*);
    void FUN_0094fd30(int);
};

extern xPlayer* xg_player_11dea3c;
extern void* xg_pLockpick_11ca268;
extern float xg_fElapsed_11da2ac;
extern int xg_iLastState_11da2a8;
extern bool xg_bMsg_11da2a4;
extern int xg_iTileId_11da1f8;
extern int xg_iTileId2_11da1fc;
extern int xg_iDir_11a0394;
bool xF702450(int);
int xF790290();
int xF78e080();
float xF408820(float);
bool xF5d4a40();
float xF404010(float, float);
float xF40ebd0(float, float);
void xF4d5c60(int);
int xF6705b0(int, int);
void xF75b6e0(int);
int xF47e040(float);
void xF78e0d0();
float xF4bd510(float, float);
int xSprintf(char*, unsigned int, const char*, ...);
bool xQueueMsg(const char*, int, const char*, const char*, float, int);

static const char s_szIcon[] = "Interface\\Icons\\Message Icons\\glow_message_vaultboy_surprised.dds";
static const char s_szEnter[] = "UILockpickingEnter";
static const char s_szTurn[] = "UILockpickingCylinderTurn";
static const char s_szSqueakA[] = "UILockpickingCylinderSqueakA";
static const char s_szSqueakB[] = "UILockpickingCylinderSqueakB";
static const char s_szUnlock[] = "UILockpickingUnlock";
static const char s_szOpened[] = "LOCK OPENED!  :D";
static const char s_szStop[] = "UILockpickingCylinderStop";
static const char s_szTension[] = "UILockpickingPickTensionLPM";
static const char s_szHealthFmt[] = "PICK HEALTH: %d%s";
static const char s_szPercent[] = "%";
static const char s_szBreak[] = "UILockpickingPickBreak";
static const char s_szHealthFull[] = "PICK HEALTH: 100%";
extern const char s_litEnd78eb50[] = "";

struct xLockPickMenu
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
    virtual int v13();

    int m_pad04[9];
    int m_28;
    int m_2c;
    xTile* m_30;
    int m_pad34[9];
    xTile* m_58;
    xTile* m_5c;
    int m_60;
    xTile* m_64;
    xTile* m_68;
    xRef* m_6c;
    int m_70;
    int m_74;
    float m_78;
    int m_7c;
    int m_80;
    int m_84, m_88;
    float m_8c;
    float m_90;
    float m_94;
    bool m_98;
    bool m_99;
    xSeq* m_9c;
    xSeq* m_a0;
    xCtrlMgr* m_a4;
    xSeq* m_a8;
    xSeq* m_ac;
    xSeq* m_b0;
    xMat3 m_b4;
    xPoint3 m_d8;
    void FUN_007908f0();
    void AdvanceSequence(float);
    void UpdateLockRotation(float);
    bool FUN_00791540(bool);
    void UpdateSweetSpot();
    xTile* FUN_00726070();
    void FUN_00a1d910();
    int FUN_0059bb30();
    void FUN_0078eb50();
};

// Updates the lockpicking menu state machine, advancing sequences, adjusting tension, and handling lock success or pick breakage.
// @fnv 0x0078eb50
void xLockPickMenu::FUN_0078eb50()
{
    int qSVM = 0;
    float qrEZrs = 1.0f;
    static xSound s_kTension;
    bool qpqRa = xF702450(v13());
    if (m_80 == 0)
    {
        qSVM = 0;
        xg_fElapsed_11da2ac = 0.0f;
        xg_iLastState_11da2a8 = 0;
    }
    else
    {
        qSVM = xg_timer_11f6394.FUN_00825c00() - m_80;
        if (xg_iLastState_11da2a8 != m_28)
            xg_fElapsed_11da2ac = 0.0f;
        else
            xg_fElapsed_11da2ac += qSVM / 1000.0;
    }
    m_80 = xg_timer_11f6394.FUN_00825c00();
    xg_iLastState_11da2a8 = m_28;
    if (m_99)
    {
        if (qpqRa && xF4b7210()->m_4d4.FUN_00718840(xF790290()))
            m_99 = false;
        else
            return;
    }
    if (!qpqRa)
        xF4b7210()->FUN_0045cd60()->FUN_00a012d0(0xfa9, 255.0f, true);
    int qsSDDgz = 0;
    int qfTOqo = 0x7fff;
    if (xF4b7210()->FUN_004b71d0())
    {
        qsSDDgz = xg_os_11dea0c->FUN_00877720()->GetAxisState(0, 9);
        if (xF408820((float)qsSDDgz) <= 8689.0)
            qsSDDgz = 0;
        qrEZrs = -qsSDDgz / 32767.0;
    }
    switch (m_28)
    {
    case 0:
        if (m_9c && m_a8)
        {
            xUpdateData UPD0(xg_fElapsed_11da2ac, true, false);
            xUpdateData UPD1(xg_fElapsed_11da2ac, true, false);
            xg_spNode_11da24c.FUN_00559450()->FUN_0043b4a0(0)->FUN_00a59c60(UPD0);
            if (xg_fElapsed_11da2ac == 0.0 || !m_6c || m_30->FUN_00a011b0(xg_iTileId_11da1f8) > 0.0)
                xg_spNode_11da24c.FUN_00559450()->FUN_0043b4a0(1)->FUN_00a59c60(UPD1);
            if (xg_fElapsed_11da2ac == 0.0 && m_6c)
            {
                if (m_30->FUN_00a011b0(xg_iTileId_11da1f8) <= 0.0)
                    xQueueMsg(xg_s_11d34ec.FUN_00403df0(), 0, s_szIcon, 0, 2.0f, 0);
                else
                    xAudio::FUN_00453a70()->FUN_00ad7550(s_szEnter, 0x121).Play(false);
            }
            if (m_9c->FUN_00508100() <= xg_fElapsed_11da2ac)
            {
                xCtrlMgr* qArxcFu =
                    (xCtrlMgr*)xg_spNode_11da24c.FUN_00559450()->FUN_0043b4a0(0)->FUN_00a5c570(&xg_rtti_11f36ac);
                xAV* qAhbO = xg_spNode_11da24c.FUN_00559450()->FUN_0043b4a0(0)->FUN_0043b4a0(0)->FUN_0043b4a0(2);
                xPoint3 qxQHW = qAhbO->FUN_0043c490();
                m_28 = 2;
                qArxcFu->FUN_0047b220(m_9c, 0.0f);
                qArxcFu->FUN_0047aab0(m_a0, 0, 1, 1.0f, 0.0f, 0);
                m_a4->FUN_0047b220(m_a8, 0.0f);
                m_a4->FUN_0047aab0(m_ac, 0, 1, 1.0f, 0.0f, 0);
            }
        }
        break;
    case 1:
        if (m_a8)
        {
            xUpdateData UPDB(xg_fElapsed_11da2ac, true, false);
            xg_spNode_11da24c.FUN_00559450()->FUN_0043b4a0(1)->FUN_00a59c60(UPDB);
            if (m_a8->FUN_00508100() <= xg_fElapsed_11da2ac)
            {
                m_28 = 2;
                m_a4->FUN_0047b220(m_a8, 0.0f);
                m_a4->FUN_0047aab0(m_ac, 0, 1, 1.0f, 0.0f, 0);
            }
        }
        break;
    case 2:
        if (xF5d4a40() && !xF4b7210()->m_4d4.FUN_00718840(xF790290()))
        {
            m_99 = xF4b7210()->m_4d4.FUN_00718630(xF790290(), xF78e080(), 0);
        }
        else if (qpqRa)
        {
            if (!m_6c || m_30->FUN_00a011b0(xg_iTileId_11da1f8) > 0.0)
            {
                if ((xIface::FUN_004b71d0() && qrEZrs > 0.0) || (!xIface::FUN_004b71d0() && FUN_00791540(true)))
                {
                    xAudio::FUN_00453a70()->FUN_00ad7550(s_szTurn, 0x121).Play(false);
                    m_28 = 3;
                }
                FUN_007908f0();
            }
            if (m_8c > 0.0)
            {
                float OLD2 = m_8c;
                m_8c -= qSVM * 90 / 1000.0;
                m_8c = xF404010(m_8c, 0.0f);
                AdvanceSequence(0.0f);
                if (m_8c < 30.0 && OLD2 > 30.0)
                    xAudio::FUN_00453a70()->FUN_00ad7550(s_szSqueakA, 0x101).Play(false);
                if (m_8c < 60.0 && OLD2 > 60.0)
                    xAudio::FUN_00453a70()->FUN_00ad7550(s_szSqueakB, 0x101).Play(false);
            }
        }
        break;
    case 3:
        if (!m_98 &&
            (!qpqRa || (xIface::FUN_004b71d0() && qrEZrs <= 0.0) || (!xIface::FUN_004b71d0() && !FUN_00791540(false))))
        {
            xg_os_11dea0c->FUN_00877720()->ResetTargetState();
            m_28 = 2;
        }
        else
        {
            float OLD3 = m_8c;
            if (m_98)
                qrEZrs = 1.0f;
            if (m_8c <= m_90)
            {
                m_8c += qSVM * 90 * qrEZrs / 1000.0;
                m_8c = xF40ebd0(m_8c, m_90);
            }
            AdvanceSequence(0.0f);
            if (xIface::FUN_004b71d0())
                xg_os_11dea0c->FUN_00877720()->FUN_00a255b0(0.1f, 0.0f, 0xfa, 0x7d, 3, 1, 0);
            if (OLD3 < 30.0 && m_8c > 30.0)
                xAudio::FUN_00453a70()->FUN_00ad7550(s_szSqueakA, 0x101).Play(false);
            if (OLD3 < 60.0 && m_8c > 60.0)
                xAudio::FUN_00453a70()->FUN_00ad7550(s_szSqueakB, 0x101).Play(false);
            if (m_8c >= m_90)
            {
                if (m_8c >= 90.0)
                {
                    if (m_6c)
                    {
                        xF4d5c60(4);
                        if (m_6c->FUN_00569160()->m_10 == 0)
                        {
                            xg_player_11dea3c->v290(xF6705b0(3, m_70));
                            m_6c->FUN_00569160()->m_10++;
                            m_6c->FUN_005789b0();
                        }
                        if (m_6c->FUN_00567790())
                        {
                            xForm* OWNER = m_6c->FUN_00567790();
                            void* CRIME = 0;
                            if (OWNER->FUN_00401170() == 8)
                            {
                                xFaction* FACA = (xFaction*)OWNER;
                                CRIME = xg_crime_11e0e80.FUN_00970b30(FACA, 1, 1);
                            }
                            else
                            {
                                xNPC* NPCA = (xNPC*)OWNER;
                                CRIME = xg_crime_11e0e80.FUN_00970a20(NPCA, 1);
                            }
                            if (CRIME)
                            {
                                xg_player_11dea3c->FUN_00915d20(1);
                                xg_player_11dea3c->FUN_008bfa40(CRIME, 0, 0, 0, OWNER);
                            }
                            else
                            {
                                bool BOUNTY = false;
                                if (OWNER && OWNER->FUN_00401170() == 8)
                                {
                                    xFaction* FACB = (xFaction*)OWNER;
                                    if (!FACB->FUN_0047d7c0())
                                        BOUNTY = true;
                                }
                                else if (OWNER)
                                {
                                    xNPC* NPCB = (xNPC*)OWNER;
                                    if (NPCB)
                                    {
                                        int DISP = xF47e040(NPCB->m_100.GetAV(0x17));
                                        if (DISP != 2 && DISP != 4)
                                            BOUNTY = true;
                                    }
                                }
                                if (BOUNTY)
                                    xg_player_11dea3c->FUN_0094fd30((int)*xg_f_11cde20.FUN_00403e20());
                            }
                        }
                        xAudio::FUN_00453a70()->FUN_00ad7550(s_szUnlock, 0x101).Play(false);
                        m_6c->FUN_005692a0();
                        if (m_6c->FUN_00401170() == 0x1c)
                            xg_player_11dea3c->m_20c = true;
                        if (m_6c->FUN_007af430() && m_6c->FUN_007af430()->FUN_00401170() == 0x1b)
                            xF75b6e0(1);
                        m_6c->Activate(xg_player_11dea3c, 0, 0, 1);
                        if (m_6c->FUN_00401170() == 0x1c)
                            xg_player_11dea3c->m_20c = false;
                        xF78e0d0();
                    }
                    else
                    {
                        m_58->FUN_00a01350(0xfc4, s_szOpened, true);
                        m_58->FUN_00700320(0xfa3, 1);
                        if (!m_6c)
                            m_30->FUN_00700320(xg_iTileId_11da1f8, 0);
                        xg_bMsg_11da2a4 = true;
                        m_28 = 6;
                    }
                }
                else
                {
                    xAudio::FUN_00453a70()->FUN_00ad7550(s_szStop, 0x101).Play(false);
                    s_kTension = xAudio::FUN_00453a70()->FUN_00ad7550(s_szTension, 1);
                    s_kTension.Play(true);
                    m_28 = 4;
                }
                xg_os_11dea0c->FUN_00877720()->ResetTargetState();
            }
        }
        break;
    case 4:
        if (!qpqRa || (xF4b7210()->FUN_004b71d0() && qrEZrs <= 0.0) ||
            (!xF4b7210()->FUN_004b71d0() && !FUN_00791540(false)))
        {
            s_kTension.FUN_00ad8da0(500);
            xg_os_11dea0c->FUN_00877720()->ResetTargetState();
            m_28 = 2;
        }
        else
        {
            xUpdateData qxWmVch(0.0f, true, false);
            float qQMZREG = qSVM / 1000.0;
            char qJDuOZ[0x20];
            if (*xg_f_11d41c8.FUN_00403e20() != 0.0)
                m_94 -= qQMZREG / *xg_f_11d41c8.FUN_00403e20();
            m_94 = xF404010(m_94, 0.0f);
            AdvanceSequence(xg_iDir_11a0394 * 0.25);
            if (xIface::FUN_004b71d0())
                xg_os_11dea0c->FUN_00877720()->FUN_00a255b0(0.5f, 0.0f, 0xfa, 0, 0, 0, 0);
            if (m_ac)
            {
                m_ac->FUN_00a328b0(m_ac->FUN_00759450() + (1.0 - m_94) * (m_ac->FUN_00508100() - m_ac->FUN_00759450()),
                                   0);
                xg_spNode_11da24c.FUN_00559450()->FUN_00a59c60(qxWmVch);
            }
            UpdateLockRotation(m_68->FUN_00a011b0(xg_iTileId2_11da1fc) + xg_iDir_11a0394 * 2.5);
            xg_iDir_11a0394 = -xg_iDir_11a0394;
            xSprintf(qJDuOZ, 0x20, s_szHealthFmt, (int)xF4bd510(m_94 * 100.0, 1.0f), s_szPercent);
            m_5c->FUN_00a01350(0xfc4, qJDuOZ, true);
            if (m_94 <= 0.0)
            {
                s_kTension.FUN_00ad8da0(100);
                xAudio::FUN_00453a70()->FUN_00ad7550(s_szBreak, 0x101).Play(false);
                if (m_6c)
                    xg_player_11dea3c->RemoveItem(xg_pLockpick_11ca268, 0, 1, 0, 0, 0, 0, 0, 1, 0);
                m_30->FUN_00a012d0(xg_iTileId_11da1f8, m_30->FUN_00a011b0(xg_iTileId_11da1f8) - 1.0, true);
                m_a4->FUN_0047b220(m_ac, 0.0f);
                m_a4->FUN_0047aab0(m_b0, 0, 1, 1.0f, 0.0f, 0);
                xg_os_11dea0c->FUN_00877720()->ResetTargetState();
                m_28 = 5;
            }
        }
        break;
    case 5:
        if (m_b0 && qpqRa)
        {
            xUpdateData UPD5(xg_fElapsed_11da2ac, true, false);
            xg_spNode_11da24c.FUN_00559450()->FUN_0043b4a0(1)->FUN_00a59c60(UPD5);
            if (m_b0->FUN_00508100() <= xg_fElapsed_11da2ac)
                m_28 = 6;
        }
        break;
    case 6:
        if (xg_fElapsed_11da2ac >= 1.0 && qpqRa)
        {
            m_58->FUN_00700320(0xfa3, 0);
            m_5c->FUN_00a01350(0xfc4, s_szHealthFull, true);
            m_94 = 1.0f + m_78 * *xg_f_11d0de0.FUN_00403e20();
            m_8c = 0.0f;
            AdvanceSequence(0.0f);
            m_68->FUN_00a012d0(xg_iTileId2_11da1fc, m_64->FUN_00a011b0(0xfb1) / 2.0, true);
            xg_spNode_11da24c.FUN_00559450()->FUN_0043b4a0(1)->FUN_00440460(m_d8);
            xg_spNode_11da24c.FUN_00559450()->FUN_0043b4a0(1)->FUN_0043fa80(m_b4);
            m_a4->FUN_0048fef0(0.0f);
            m_a4->FUN_0047aab0(m_a8, 0, 1, 1.0f, 0.0f, 0);
            if (xg_bMsg_11da2a4)
            {
                UpdateSweetSpot();
                xg_bMsg_11da2a4 = false;
            }
            if (m_6c && m_30->FUN_00a011b0(xg_iTileId_11da1f8) == 0.0)
            {
                xQueueMsg(xg_s_11d34ec.FUN_00403df0(), 0, s_szIcon, 0, 2.0f, 0);
                m_58->FUN_00700320(0xfa3, 0);
                xUpdateData UPD6(0.0f, true, false);
                xg_spNode_11da24c.FUN_00559450()->FUN_0043b4a0(1)->FUN_00a59c60(UPD6);
                m_28 = 2;
            }
            else
            {
                m_28 = 1;
            }
        }
        break;
    case 7:
        if (FUN_0059bb30() != 2)
        {
            xF4b7210()->FUN_0045cd60()->FUN_00a012d0(0xfa9, 255.0f, true);
            xF4b7210()->FUN_00718930(1);
            FUN_00726070()->FUN_00700320(0x1772, 1);
            FUN_00a1d910();
        }
        break;
    }
}
}  // namespace fnv_0078eb50
