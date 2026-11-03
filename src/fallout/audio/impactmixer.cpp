
// src/fallout/audio/impactmixer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/audio/impactmixer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_011dd878;

// @fnv 0x00839da0
bool FUN_00839da0()
{
    return (DAT_011dd878 & 2) != 0;
}

extern int DAT_011dd878;

// @fnv 0x00839dc0
void FUN_00839dc0(bool abSet)
{
    int tmp;
    if (abSet)
        tmp = DAT_011dd878 | 2;
    else
        tmp = DAT_011dd878 & 0xfffffffd;
    DAT_011dd878 = tmp;
}

extern int DAT_011a17f8[0x24];

// @fnv 0x0083a910
int GetTypeValue(int aiType)
{
    if (aiType <= 0 || aiType >= 0x24)
        return 0;
    return DAT_011a17f8[aiType];
}

struct FUN_00acbb70_shell
{
    int FUN_00acbb70();
};

// @fnv 0x00acbb70
int __thiscall FUN_00acbb70_shell::FUN_00acbb70()
{
    return 0;
}

struct FUN_008397d0_shell
{
    unsigned char GetByteAt7C6();
};

// @fnv 0x008397d0
unsigned char FUN_008397d0_shell::GetByteAt7C6()
{
    return ((unsigned char*)this)[0x7c6];
}

struct AutoMemHelper
{
    int m;
    AutoMemHelper(int, bool, char const*, int);
    ~AutoMemHelper();
};
// @fnv 0x00837520
void FUN_00837520()
{
    AutoMemHelper tempMemContext(0xB, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Audio\\ImpactMixer.cpp",
                                 0x10F);
}

extern int DAT_01000000;
struct DummyFlags
{
    int FUN_00621270(int);
};
struct FUN_00838750_shell
{
    bool FUN_00838750();
};
// Calls FUN_00621270 on the DummyFlags sub-object at offset 0x410 with DAT_01000000 and returns whether the result is non-zero.
// @fnv 0x00838750
bool FUN_00838750_shell::FUN_00838750()
{
    return ((DummyFlags*)((char*)this + 0x410))->FUN_00621270((int)&DAT_01000000) != 0;
}

struct FUN_00541570_shell
{
    char _pad[0x1c];
    unsigned char m_0x1c;
    unsigned int GetField1C();
};
// @fnv 0x00541570
unsigned int FUN_00541570_shell::GetField1C()
{
    return m_0x1c;
}

void __cdecl FUN_00839dc0(bool b);
extern float DAT_01016970;
// If the init check fails, calls FUN_00839dc0(true), then zeroes two ints and sets a float from DAT_01016970 for each of 20 slots.
// @fnv 0x00839d30
void __cdecl InitializeSlots()
{
    if (FUN_00839da0())
    {
        return;
        goto initialize;
    }
    FUN_00839dc0(true);
initialize:
    for (int i = 0; i < 20; ++i)
    {
        *(int*)((char*)&DAT_011dd878 + 0x188 + i * 0x24) = 0;
        *(int*)((char*)&DAT_011dd878 + 0x18c + i * 0x24) = 0;
        *(float*)((char*)&DAT_011dd878 + 0x190 + i * 0x24) = DAT_01016970;
    }
}

struct FUN_0063a3c0_cls
{
    int unk00;
    int unk04;

    void BaseRelease();
    FUN_0063a3c0_cls* FUN_0063a3c0(unsigned int auiFlags);
    static void operator delete(void* apMemory) throw();
};

// Releases the base object and, if bit 0 of auiFlags is set, deletes this instance, then returns this.
// @fnv 0x0063a3c0
FUN_0063a3c0_cls* FUN_0063a3c0_cls::FUN_0063a3c0(unsigned int auiFlags)
{
    BaseRelease();
    if (auiFlags & 1)
    {
        operator delete(this);
    }
    return this;
}

struct NiPoint3
{
    float x, y, z;
};

struct SoundPlaybackHandle
{
    int unk00;
    int unk04;
    int unk08;
    SoundPlaybackHandle();
    ~SoundPlaybackHandle();
    SoundPlaybackHandle& operator=(const SoundPlaybackHandle& kOther);
    void FUN_00ad89e0(float m_fSoundVolume);
    bool Play(int iFlags);
    void SetPos(float fX, float fY, float fZ);
    void SetNiNode(void* pkNode);
};

struct BGSSoundDescriptor;
struct BSAudioStandIn
{
    static BSAudioStandIn* GetSingleton();
    SoundPlaybackHandle FUN_00ad73b0(BGSSoundDescriptor* pkSound);
};

struct BGSImpactData
{
    BGSSoundDescriptor* FUN_0084e3a0(int iType);
};

struct BGSImpactDataEntry
{
    BGSImpactData* pkImpact;
    int unk04[9];
};
extern BGSImpactDataEntry g_akImpactData_011dd670[];

struct TESWorldSpace;
struct FootstepActor
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
    virtual bool IsActor();
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
    virtual void v115();
    virtual void* Get3D();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const NiPoint3& GetPos();

    bool FUN_005a2030();
    float FUN_0057b0a0();
    bool GetByteAt7C6();
    bool FUN_00524d10();
};
extern FootstepActor* g_player_011dea3c;

struct MaterialRecord
{
    int GetField1C();
};

struct NavQueryResult
{
    int unk00[6];
    unsigned char unk18;
    unsigned char unk19;
    unsigned short unk1a;
    int unk1c[8];
    unsigned short unk3c;
    unsigned short unk3e;
    int unk40[4];
    NavQueryResult();
};

struct CellNavInfo
{
    void FUN_0053b550(NavQueryResult* pkResult, NiPoint3* pkPos, int iFlag);
    MaterialRecord* FUN_0053a630(unsigned char ucA, unsigned short usB);
};

struct FootstepCell
{
    bool FUN_00425fd0();
    bool FUN_004518e0();
    CellNavInfo* FUN_00546fb0();
    bool FUN_005547c0(NiPoint3* pkPos, float* pfHeight);
};

struct TESStandIn
{
    FootstepCell* FUN_005f36f0();
    TESWorldSpace* FUN_004fd3e0(int iUnk);
};
extern TESStandIn* g_TES_011dea10;

struct DataHandlerStandIn
{
    FootstepCell* FUN_00461bc0(float fX, float fY, TESWorldSpace* pkWorld);
    BGSImpactData* FUN_004616c0(const char* pEditorID);
};
extern DataHandlerStandIn* g_dataHandler_011c3f2c;

int __cdecl GetTypeValue(int iMaterial);
float __cdecl FUN_00476b70(float fMin, float fScaledValue);
bool __cdecl FUN_0082eca0(BGSImpactData* pkImpact, NiPoint3 kPos, float fScale);
extern float g_fFootstepRand_0101e2bc;

static const char s_szBabyLand[] = "FSTBabyLand";
extern const char g_szFootstepEnd[] = "";

// Resolves the footstep material and impact data for an actor, adjusts the position, and plays the corresponding first- or third-person footstep sound.
// @fnv 0x008391b0
void __cdecl PlayFootstepImpact(FootstepActor* pActor, int iMaterial)
{
    SoundPlaybackHandle kHandle_;
    BGSImpactData* pImpactX = 0;
    BGSImpactData* pImpact_ = 0;
    NiPoint3 kPosOut = pActor->GetPos();
    FootstepCell* pCell_ = g_TES_011dea10->FUN_005f36f0();
    FootstepActor* pActorRef4 = 0;
    if (pActor->IsActor())
        pActorRef4 = pActor;
    else
        return;

    if (!pCell_)
        pCell_ = g_dataHandler_011c3f2c->FUN_00461bc0(kPosOut.x, kPosOut.y, g_TES_011dea10->FUN_004fd3e0(0));

    if (pActor->IsActor() && pCell_)
    {
        if ((pCell_->FUN_00425fd0() && pCell_->FUN_004518e0()) || !pCell_->FUN_00425fd0())
        {
            if (!pActorRef4->FUN_005a2030() && pActorRef4->FUN_0057b0a0() > kPosOut.z)
                iMaterial = 8;
        }
    }

    if (iMaterial == 0x24 && !pCell_->FUN_00425fd0() && pCell_->FUN_00546fb0())
    {
        NavQueryResult kResult_2;
        pCell_->FUN_00546fb0()->FUN_0053b550(&kResult_2, &kPosOut, 1);
        MaterialRecord* pMaterialTmp = pCell_->FUN_00546fb0()->FUN_0053a630(kResult_2.unk18, kResult_2.unk3c);
        if (pMaterialTmp)
        {
            float m_fGlyphExtent = 0.0f;
            iMaterial = pMaterialTmp->GetField1C();
            if (pCell_->FUN_005547c0(&kPosOut, &m_fGlyphExtent))
                kPosOut.z = m_fGlyphExtent;
        }
    }

    int iIndexZ = GetTypeValue(iMaterial);
    pImpactX = g_akImpactData_011dd670[iIndexZ].pkImpact;
    if (pActor == g_player_011dea3c && g_player_011dea3c->GetByteAt7C6())
        pImpactX = g_dataHandler_011c3f2c->FUN_004616c0(s_szBabyLand);

    bool bPlayerFirstPerson7 = false;
    if (pActor == g_player_011dea3c && !g_player_011dea3c->FUN_00524d10())
        bPlayerFirstPerson7 = true;

    if (bPlayerFirstPerson7)
    {
        int iSound = 0x4109;
        if (pImpactX)
        {
            kHandle_ = BSAudioStandIn::GetSingleton()->FUN_00ad73b0(pImpactX->FUN_0084e3a0(iSound));
            kHandle_.FUN_00ad89e0(0.95f - FUN_00476b70(0.0f, g_fFootstepRand_0101e2bc));
            kHandle_.Play(0);
        }
        if (pImpact_)
        {
            kHandle_ = BSAudioStandIn::GetSingleton()->FUN_00ad73b0(pImpact_->FUN_0084e3a0(iSound));
            kHandle_.FUN_00ad89e0(0.95f - FUN_00476b70(0.0f, g_fFootstepRand_0101e2bc));
            kHandle_.Play(0);
        }
    }
    else
    {
        if (!FUN_0082eca0(pImpactX, kPosOut, 1.0f) && !FUN_0082eca0(pImpact_, kPosOut, 1.0f))
            return;
        int iSound2 = 0x410a;
        if (pImpactX)
        {
            kHandle_ = BSAudioStandIn::GetSingleton()->FUN_00ad73b0(pImpactX->FUN_0084e3a0(iSound2));
            kHandle_.SetPos(kPosOut.x, kPosOut.y, kPosOut.z);
            kHandle_.SetNiNode(pActor->Get3D());
            kHandle_.FUN_00ad89e0(0.95f - FUN_00476b70(0.0f, g_fFootstepRand_0101e2bc));
            kHandle_.Play(0);
        }
        if (pImpact_)
        {
            kHandle_ = BSAudioStandIn::GetSingleton()->FUN_00ad73b0(pImpact_->FUN_0084e3a0(iSound2));
            kHandle_.SetPos(kPosOut.x, kPosOut.y, kPosOut.z);
            kHandle_.SetNiNode(pActor->Get3D());
            kHandle_.FUN_00ad89e0(0.95f - FUN_00476b70(0.0f, g_fFootstepRand_0101e2bc));
            kHandle_.Play(0);
        }
    }
}

namespace fnv_00839ab0 {
struct BGSImpactDataStandIn;

struct DataHandlerFootstep
{
    BGSImpactDataStandIn* FUN_004616c0(const char* pEditorID);
};
extern DataHandlerFootstep* g_dataHandler_011c3f2c;

extern unsigned char g_bFootstepsInit_011dd85c;
extern BGSImpactDataStandIn* g_aapkFootstepImpacts_011dd650[13][10];
extern const char* g_apszFootstepTypes_011a18bc[10];
extern int g_aiMaterialFallback_011a17c4[13];

const char* __cdecl FUN_008374b0(int iMaterial);
int __cdecl FUN_00406d00(char* pBuffer, unsigned int uiSize, const char* pFormat, ...);

static const char s_szFootstepFormat[] = "FST%s%s";
static const char s_szDefaultFootstep[] = "FSTConcSolidWalkR";
extern const char g_szFootstepInitEnd[] = "";

// Builds each material/type footstep impact name, looks it up via the data handler with fallbacks, and stores the result in g_aapkFootstepImpacts_011dd650.
// @fnv 0x00839ab0
void __cdecl InitFootstepImpacts()
{
    if (g_bFootstepsInit_011dd85c)
        return;
    else
        g_bFootstepsInit_011dd85c = 1;

    char acNameLoc[0x104];
    int iUnusedLoc = 0;
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            FUN_00406d00(acNameLoc, 0x103, s_szFootstepFormat, FUN_008374b0(i), g_apszFootstepTypes_011a18bc[j]);
            g_aapkFootstepImpacts_011dd650[i][j] = g_dataHandler_011c3f2c->FUN_004616c0(acNameLoc);
            if (!g_aapkFootstepImpacts_011dd650[i][j] && g_aiMaterialFallback_011a17c4[i] != 13)
            {
                FUN_00406d00(acNameLoc, 0x103, s_szFootstepFormat, FUN_008374b0(g_aiMaterialFallback_011a17c4[i]),
                             g_apszFootstepTypes_011a18bc[j]);
                g_aapkFootstepImpacts_011dd650[i][j] = g_dataHandler_011c3f2c->FUN_004616c0(acNameLoc);
                if (!g_aapkFootstepImpacts_011dd650[i][j] &&
                    g_aiMaterialFallback_011a17c4[g_aiMaterialFallback_011a17c4[i]] != 13)
                {
                    FUN_00406d00(acNameLoc, 0x103, s_szFootstepFormat,
                                 FUN_008374b0(g_aiMaterialFallback_011a17c4[g_aiMaterialFallback_011a17c4[i]]),
                                 g_apszFootstepTypes_011a18bc[j]);
                    g_aapkFootstepImpacts_011dd650[i][j] = g_dataHandler_011c3f2c->FUN_004616c0(acNameLoc);
                }
            }
            if (!g_aapkFootstepImpacts_011dd650[i][j])
                g_aapkFootstepImpacts_011dd650[i][j] = g_dataHandler_011c3f2c->FUN_004616c0(s_szDefaultFootstep);
        }
    }
}
}  // namespace fnv_00839ab0

struct SetObj
{
    float* FUN_00403e20();
};
struct StrObj
{
    int FUN_004616c0(const char* s);
};

extern SetObj DAT_011dd9c8;
extern SetObj DAT_011dd9b0;
extern SetObj DAT_011dd918;
extern SetObj DAT_011dd9bc;
extern SetObj DAT_011dd8e8;
extern SetObj DAT_011dd8f4;
extern SetObj DAT_011dd8cc;
extern SetObj DAT_011dd930;
extern SetObj DAT_011dd9d8;
extern SetObj DAT_011dd9a0;
extern SetObj DAT_011dd924;
extern StrObj* DAT_011c3f2c;
extern double DAT_01032980;
extern double DAT_01034208;
extern double DAT_01015a38;
extern double DAT_01073568;

static const char kStr_CStoneStatic[] = "CStoneStatic";
static const char kStr_CStoneSmall[] = "CStoneSmall";
static const char kStr_CStoneMedium[] = "CStoneMedium";
static const char kStr_CStoneLarge[] = "CStoneLarge";
static const char kStr_CEarthSmall[] = "CEarthSmall";
static const char kStr_CEarthMedium[] = "CEarthMedium";
static const char kStr_CEarthLarge[] = "CEarthLarge";
static const char kStr_CGrassSmall[] = "CGrassSmall";
static const char kStr_CGrassMedium[] = "CGrassMedium";
static const char kStr_CGrassLarge[] = "CGrassLarge";
static const char kStr_PHYGenericMetalStaticL[] = "PHYGenericMetalStaticL";
static const char kStr_PHYGenericMetalSmallL[] = "PHYGenericMetalSmallL";
static const char kStr_PHYGenericMetalMediumL[] = "PHYGenericMetalMediumL";
static const char kStr_PHYGenericMetalLargeL[] = "PHYGenericMetalLargeL";
static const char kStr_PHYGenericMetalStaticH[] = "PHYGenericMetalStaticH";
static const char kStr_PHYGenericMetalSmallH[] = "PHYGenericMetalSmallH";
static const char kStr_PHYGenericMetalMediumH[] = "PHYGenericMetalMediumH";
static const char kStr_PHYGenericMetalLargeH[] = "PHYGenericMetalLargeH";
static const char kStr_CWoodStatic[] = "CWoodStatic";
static const char kStr_CWoodSmall[] = "CWoodSmall";
static const char kStr_CWoodMedium[] = "CWoodMedium";
static const char kStr_CWoodLarge[] = "CWoodLarge";
static const char kStr_PHYGenericClothL[] = "PHYGenericClothL";
static const char kStr_PHYGenericClothH[] = "PHYGenericClothH";
static const char kStr_COrganicSmall[] = "COrganicSmall";
static const char kStr_PHYSkinSmallL[] = "PHYSkinSmallL";
static const char kStr_PHYSkinMediumL[] = "PHYSkinMediumL";
static const char kStr_PHYSkinLargeL[] = "PHYSkinLargeL";
static const char kStr_PHYSkinSmallH[] = "PHYSkinSmallH";
static const char kStr_PHYSkinMediumH[] = "PHYSkinMediumH";
static const char kStr_PHYSkinLargeH[] = "PHYSkinLargeH";
static const char kStr_CGlassSmall[] = "CGlassSmall";
static const char kStr_CGlassMedium[] = "CGlassMedium";
static const char kStr_CGlassLarge[] = "CGlassLarge";
static const char kStr_PHYChain[] = "PHYChain";
static const char kStr_CSpecialHeavyStone[] = "CSpecialHeavyStone";
static const char kStr_CSpecialHeavyMetal[] = "CSpecialHeavyMetal";
static const char kStr_CSpecialHeavyWood[] = "CSpecialHeavyWood";
static const char kStr_PHYGenericMetalHollowStatic[] = "PHYGenericMetalHollowStatic";
static const char kStr_PHYGenericMetalHollowSmall[] = "PHYGenericMetalHollowSmall";
static const char kStr_PHYGenericMetalHollowMedium[] = "PHYGenericMetalHollowMedium";
static const char kStr_PHYGenericMetalHollowLarge[] = "PHYGenericMetalHollowLarge";
static const char kStr_PHYGenericMetalSheetStatic[] = "PHYGenericMetalSheetStatic";
static const char kStr_PHYGenericMetalSheetSmall[] = "PHYGenericMetalSheetSmall";
static const char kStr_PHYGenericMetalSheetMedium[] = "PHYGenericMetalSheetMedium";
static const char kStr_PHYGenericMetalSheetLarge[] = "PHYGenericMetalSheetLarge";
static const char kStr_PHYVehicleMetalBodyL[] = "PHYVehicleMetalBodyL";
static const char kStr_PHYVehicleMetalBodyH[] = "PHYVehicleMetalBodyH";
static const char kStr_PHYVehicleMetalSolidL[] = "PHYVehicleMetalSolidL";
static const char kStr_PHYVehicleMetalSolidH[] = "PHYVehicleMetalSolidH";
static const char kStr_PHYVehicleMetalHollowL[] = "PHYVehicleMetalHollowL";
static const char kStr_PHYVehicleMetalHollowH[] = "PHYVehicleMetalHollowH";
static const char kStr_PHYBarrelL[] = "PHYBarrelL";
static const char kStr_PHYBarrelH[] = "PHYBarrelH";
static const char kStr_PHYBottleL[] = "PHYBottleL";
static const char kStr_PHYBottleH[] = "PHYBottleH";
static const char kStr_PHYCanSodaL[] = "PHYCanSodaL";
static const char kStr_PHYCanSodaH[] = "PHYCanSodaH";
static const char kStr_PHYWeaponPistolL[] = "PHYWeaponPistolL";
static const char kStr_PHYWeaponPistolH[] = "PHYWeaponPistolH";
static const char kStr_PHYWeaponRifleL[] = "PHYWeaponRifleL";
static const char kStr_PHYWeaponRifleH[] = "PHYWeaponRifleH";
static const char kStr_PHYShoppingCartL[] = "PHYShoppingCartL";
static const char kStr_PHYShoppingCartH[] = "PHYShoppingCartH";
static const char kStr_PHYLunchboxL[] = "PHYLunchboxL";
static const char kStr_PHYLunchboxH[] = "PHYLunchboxH";
static const char kStr_PHYBabyRattle[] = "PHYBabyRattle";
static const char kStr_PHYRubberBall[] = "PHYRubberBall";
static const char kStr_PHYBottlecaps[] = "PHYBottlecaps";
static const char kStr_PHYChainlink[] = "PHYChainlink";
static const char kStr_PHYTile[] = "PHYTile";
static const char kStr_PHYCarpet[] = "PHYCarpet";
static const char kStr_PHYTumbleweed[] = "PHYTumbleweed";

// Maps a material type and two size values to a material name string via DAT_011c3f2c->FUN_004616c0, returning the resulting id.
// @fnv 0x00839e00
int __cdecl FUN_00839e00(int aiMaterialType, float afSizeA, float afSizeB)
{
    int result = 0;

    switch (aiMaterialType)
    {
    case 0:
    case 15:
        if (afSizeA < DAT_01032980)
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CStoneStatic);
        }
        else if (afSizeA < *DAT_011dd9c8.FUN_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CStoneSmall);
        }
        else if (afSizeA < *DAT_011dd9b0.FUN_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CStoneMedium);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CStoneLarge);
        }
        break;
    case 2:
        if (afSizeA < *DAT_011dd918.FUN_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CEarthSmall);
        }
        else if (afSizeA < *DAT_011dd9bc.FUN_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CEarthMedium);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CEarthLarge);
        }
        break;
    case 4:
        if (afSizeA < DAT_01034208)
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CGrassSmall);
        }
        else if (afSizeA < DAT_01073568)
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CGrassMedium);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CGrassLarge);
        }
        break;
    case 5:
        if (afSizeB < *DAT_011dd8e8.FUN_00403e20())
        {
            if (afSizeA < DAT_01032980)
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalStaticL);
            }
            else if (afSizeA < *DAT_011dd8f4.FUN_00403e20())
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalSmallL);
            }
            else if (afSizeA < *DAT_011dd8cc.FUN_00403e20())
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalMediumL);
            }
            else
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalLargeL);
            }
        }
        else
        {
            if (afSizeA < DAT_01032980)
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalStaticH);
            }
            else if (afSizeA < *DAT_011dd8f4.FUN_00403e20())
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalSmallH);
            }
            else if (afSizeA < *DAT_011dd8cc.FUN_00403e20())
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalMediumH);
            }
            else
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalLargeH);
            }
        }
        break;
    case 9:
        if (afSizeA < DAT_01032980)
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CWoodStatic);
        }
        else if (afSizeA < *DAT_011dd930.FUN_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CWoodSmall);
        }
        else if (afSizeA < *DAT_011dd9d8.FUN_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CWoodMedium);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CWoodLarge);
        }
        break;
    case 1:
        if (afSizeB < *DAT_011dd8e8.FUN_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericClothL);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericClothH);
        }
        break;
    case 6:
        result = DAT_011c3f2c->FUN_004616c0(kStr_COrganicSmall);
        break;
    case 7:
        if (afSizeB < *DAT_011dd8e8.FUN_00403e20())
        {
            if (afSizeA < *DAT_011dd9a0.FUN_00403e20())
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYSkinSmallL);
            }
            else if (afSizeA < *DAT_011dd924.FUN_00403e20())
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYSkinMediumL);
            }
            else
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYSkinLargeL);
            }
        }
        else
        {
            if (afSizeA < *DAT_011dd9a0.FUN_00403e20())
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYSkinSmallH);
            }
            else if (afSizeA < *DAT_011dd924.FUN_00403e20())
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYSkinMediumH);
            }
            else
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYSkinLargeH);
            }
        }
        break;
    case 3:
        if (afSizeA < DAT_01034208)
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CGlassSmall);
        }
        else if (afSizeA < DAT_01015a38)
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CGlassMedium);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CGlassLarge);
        }
        break;
    case 8:
        if (afSizeA < DAT_01034208)
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CWoodSmall);
        }
        else if (afSizeA < DAT_01015a38)
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CWoodMedium);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CWoodLarge);
        }
        break;
    case 13:
        result = DAT_011c3f2c->FUN_004616c0(kStr_PHYChain);
        break;
    case 10:
        result = DAT_011c3f2c->FUN_004616c0(kStr_CSpecialHeavyStone);
        break;
    case 11:
        result = DAT_011c3f2c->FUN_004616c0(kStr_CSpecialHeavyMetal);
        break;
    case 12:
        result = DAT_011c3f2c->FUN_004616c0(kStr_CSpecialHeavyWood);
        break;
    case 16:
        if (afSizeA < DAT_01032980)
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalHollowStatic);
        }
        else if (afSizeA < *DAT_011dd8f4.FUN_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalHollowSmall);
        }
        else if (afSizeA < *DAT_011dd8cc.FUN_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalHollowMedium);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalHollowLarge);
        }
        break;
    case 17:
        if (afSizeA < DAT_01032980)
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalSheetStatic);
        }
        else if (afSizeA < *DAT_011dd8f4.FUN_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalSheetSmall);
        }
        else if (afSizeA < *DAT_011dd8cc.FUN_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalSheetMedium);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalSheetLarge);
        }
        break;
    case 18:
        break;
    case 19:
        result = 0;
        break;
    case 20:
        if (afSizeB < *DAT_011dd8e8.FUN_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYVehicleMetalBodyL);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYVehicleMetalBodyH);
        }
        break;
    case 21:
        if (afSizeB < *DAT_011dd8e8.FUN_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYVehicleMetalSolidL);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYVehicleMetalSolidH);
        }
        break;
    case 22:
        if (afSizeB < *DAT_011dd8e8.FUN_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYVehicleMetalHollowL);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYVehicleMetalHollowH);
        }
        break;
    case 23:
        if (afSizeB < *DAT_011dd8e8.FUN_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYBarrelL);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYBarrelH);
        }
        break;
    case 24:
        if (afSizeB < *DAT_011dd8e8.FUN_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYBottleL);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYBottleH);
        }
        break;
    case 25:
        if (afSizeB < *DAT_011dd8e8.FUN_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYCanSodaL);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYCanSodaH);
        }
        break;
    case 26:
        if (afSizeB < *DAT_011dd8e8.FUN_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYWeaponPistolL);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYWeaponPistolH);
        }
        break;
    case 27:
        if (afSizeB < *DAT_011dd8e8.FUN_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYWeaponRifleL);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYWeaponRifleH);
        }
        break;
    case 28:
        if (afSizeB < *DAT_011dd8e8.FUN_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYShoppingCartL);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYShoppingCartH);
        }
        break;
    case 29:
        if (afSizeB < *DAT_011dd8e8.FUN_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYLunchboxL);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYLunchboxH);
        }
        break;
    case 30:
        result = DAT_011c3f2c->FUN_004616c0(kStr_PHYBabyRattle);
        break;
    case 31:
        result = DAT_011c3f2c->FUN_004616c0(kStr_PHYRubberBall);
        break;
    case 14:
        result = DAT_011c3f2c->FUN_004616c0(kStr_PHYBottlecaps);
        break;
    case 32:
        result = DAT_011c3f2c->FUN_004616c0(kStr_PHYChainlink);
        break;
    case 33:
        result = DAT_011c3f2c->FUN_004616c0(kStr_PHYTile);
        break;
    case 34:
        result = DAT_011c3f2c->FUN_004616c0(kStr_PHYCarpet);
        break;
    case 35:
        result = DAT_011c3f2c->FUN_004616c0(kStr_PHYTumbleweed);
        break;
    }
    return result;
}

struct S_0083a930_Point3
{
    float x;
    float y;
    float z;
};

struct S_0083a930_NiNode;
class TESSound;

struct S_0083a930_SoundHandle
{
    int unk0;
    int unk4;
    int unk8;
    S_0083a930_SoundHandle();
    ~S_0083a930_SoundHandle();
    S_0083a930_SoundHandle& operator=(const S_0083a930_SoundHandle& other);
    bool SetPos(float x, float y, float z);
    void SetNiNode(S_0083a930_NiNode* node);
    bool FUN_00ad89e0(float volume);
    bool Play(bool flag);
};

struct S_0083a930_Audio
{
    static S_0083a930_Audio* FUN_00453a70();
    S_0083a930_SoundHandle FUN_00ad7480(const char* path, unsigned int flags, TESSound* sound);
};

class TESForm
{
  public:
    virtual void v000();
};

class TESBoundObject : public TESForm
{
};

class TESSound : public TESBoundObject
{
  public:
    const char* FUN_00511840();
};

class TESObjectWEAP : public TESBoundObject
{
  public:
    TESSound* GetField238();
    TESSound* GetField23C();
};

struct S_0083a930_EntryData
{
    TESBoundObject* FUN_0044ddc0();
};

struct S_0083a930_Process
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
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
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
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual S_0083a930_EntryData* GetWeaponInfo();  // +0x148
};

class TESObjectREFR
{
  public:
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
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
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
    virtual S_0083a930_NiNode* GetNode();  // +0x1d0
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual S_0083a930_Point3* GetPos();  // +0x1f4
};

class Actor : public TESObjectREFR
{
  public:
    S_0083a930_Process* FUN_008d8520();
    bool FUN_004997b0();
};

struct S_0083a930_Setting
{
    float* FUN_00403e20();
};

extern S_0083a930_Setting DAT_011dd900;
extern Actor* DAT_011dea3c;
extern const float DAT_010231a8;
bool FUN_0082eca0(TESSound* sound, S_0083a930_Point3 pos, float volume);

// @fnv 0x0083a930
void PlayWeaponImpactSound(TESObjectREFR* ref, int type)
{
    AutoMemHelper ctx(0xb, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Audio\\ImpactMixer.cpp", 0x6a3);
    S_0083a930_Point3 pos = *ref->GetPos();
    float value = *DAT_011dd900.FUN_00403e20();
    bool bUnused = false;
    Actor* actor = dynamic_cast<Actor*>(ref);
    if (actor && actor->FUN_008d8520())
    {
        S_0083a930_SoundHandle sound;
        S_0083a930_EntryData* entry = actor->FUN_008d8520()->GetWeaponInfo();
        TESBoundObject* invObject = entry ? entry->FUN_0044ddc0() : 0;
        TESObjectWEAP* weapon = invObject ? dynamic_cast<TESObjectWEAP*>(invObject) : 0;
        if (weapon)
        {
            TESSound* snd = 0;
            switch (type)
            {
            case 9:
                snd = weapon->GetField238();
                break;
            case 10:
                snd = weapon->GetField23C();
                break;
            }
            if (!snd || !FUN_0082eca0(snd, pos, 1.0f))
                return;
            bool sneaking = actor->FUN_004997b0();
            if (actor == DAT_011dea3c)
            {
                sound = S_0083a930_Audio::FUN_00453a70()->FUN_00ad7480(snd->FUN_00511840(), 0x80004101, snd);
            }
            else
            {
                sound = S_0083a930_Audio::FUN_00453a70()->FUN_00ad7480(snd->FUN_00511840(), 0x4102, snd);
                sound.SetPos(pos.x, pos.y, pos.z);
                sound.SetNiNode(ref->GetNode());
            }
            if (sneaking)
                sound.FUN_00ad89e0(DAT_010231a8);
            else
                sound.FUN_00ad89e0(1.0f);
            sound.Play(false);
        }
    }
}

struct FootstepQuery
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned char materialKind;
    unsigned char unk19;
    unsigned short unk1a;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    unsigned short triangle;
    unsigned short unk3e;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    FootstepQuery();
};
struct NavOps
{
    void FUN_0053b550(FootstepQuery*, NiPoint3*, int);
};
extern const char armorPowerRightName[];
extern const char armorPowerLeftName[];
extern const char armorRightName[];
extern const char armorLeftName[];
bool FUN_00702360();
bool FUN_00525420();
struct PointOps : NiPoint3
{
    NiPoint3& Subtract(const NiPoint3&);
    float FUN_00457990();
};
struct ListenerOps
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual const NiPoint3& GetPosition();
};
struct SoundOps
{
    unsigned char GetField45();
    BGSSoundDescriptor* FUN_0084e3a0(int);
    const char* FUN_00511840();
};
class TESCreature : public TESBoundObject
{
  public:
    SoundOps* FUN_005f92d0(int);
    void* FUN_00acbb70();
};
struct MaterialOps
{
    int FUN_0059bb30();
};
struct SkinOps
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
    MaterialOps material;
    bool FUN_00838750();
};
struct ActorOps
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
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
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
    virtual bool IsCreature();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool SuppressFootsteps(int);
    TESBoundObject* FUN_007af430();
    bool FUN_005a2030();
    float FUN_0057b0a0();
    SkinOps* FUN_009306d0();
    bool FUN_004997b0();
    bool FUN_00884730();
    bool FUN_008ba410();
    bool FUN_008ba440();
};
struct AudioOps
{
    static AudioOps* FUN_00453a70();
    ListenerOps* FUN_0044edb0();
    SoundPlaybackHandle FUN_00ad73b0(BGSSoundDescriptor*);
    SoundPlaybackHandle FUN_00ad7480(const char*, unsigned int, SoundOps*);
};
extern S_0083a930_Setting DAT_011dd988;
extern SoundOps* DAT_011dd860;
extern SoundOps* DAT_011dd864;
extern SoundOps* DAT_011dd868;
extern SoundOps* DAT_011dd86c;
struct FootstepEntry
{
    SoundOps* sounds[10];
};
extern FootstepEntry DAT_011dd650[];
// Selects a footstep sound for the given foot from the cell material and actor state, then plays it at the actor position or in first person.
// @fnv 0x00837cc0
void PlayFootstepSound(FootstepActor* apActor, int foot)
{
    bool pos;
    SoundOps* memory;
    float armor;
    AutoMemHelper range(11, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Audio\\ImpactMixer.cpp", 735);
    if (FUN_00702360())
        return;
    NiPoint3 firstPerson = apActor->GetPos();
    SoundPlaybackHandle primary;
    SoundPlaybackHandle secondary;
    memory = 0;
    SoundOps* sound = 0;
    pos = false;
    float distance = *DAT_011dd900.FUN_00403e20();
    if (FUN_00525420())
        distance /= 2.0;
    armor = 0.0f;
    if (AudioOps::FUN_00453a70()->FUN_0044edb0())
    {
        PointOps delta;
        static_cast<NiPoint3&>(delta) = AudioOps::FUN_00453a70()->FUN_0044edb0()->GetPosition();
        delta.Subtract(firstPerson);
        armor = delta.FUN_00457990();
        if (delta.FUN_00457990() > distance)
            return;
    }
    if (apActor->IsActor())
    {
        ActorOps* actorOps =
            reinterpret_cast<ActorOps*>(dynamic_cast<Actor*>(reinterpret_cast<TESObjectREFR*>(apActor)));
        if (actorOps->SuppressFootsteps(0))
            return;
        if (actorOps->IsCreature())
        {
            TESBoundObject* base = reinterpret_cast<ActorOps*>(apActor)->FUN_007af430();
            TESCreature* creature = dynamic_cast<TESCreature*>(base);
            SoundOps* creatureSound = creature->FUN_005f92d0(foot);
            memory = creatureSound;
            if (memory && armor <= memory->GetField45() * 100)
            {
                primary = AudioOps::FUN_00453a70()->FUN_00ad73b0(memory->FUN_0084e3a0(266));
            }
            primary.SetPos(firstPerson.x, firstPerson.y, firstPerson.z);
            if (creature->FUN_00acbb70())
                primary.SetNiNode(creature->FUN_00acbb70());
            primary.FUN_00ad89e0(0.98f);
            primary.Play(0);
        }
        else
        {
            int materialIndex = 0;
            FootstepCell* cell = g_TES_011dea10->FUN_005f36f0();
            if (!cell)
                cell =
                    g_dataHandler_011c3f2c->FUN_00461bc0(firstPerson.x, firstPerson.y, g_TES_011dea10->FUN_004fd3e0(0));
            bool soundType = false;
            bool movingActor = false;
            if (!actorOps->FUN_005a2030() && cell && firstPerson.z < actorOps->FUN_0057b0a0() &&
                ((cell->FUN_00425fd0() && cell->FUN_004518e0()) || !cell->FUN_00425fd0()))
                soundType = true;
            ActorOps* material = actorOps;
            if (material->FUN_009306d0()->FUN_00838750())
                movingActor = true;
            if (!g_TES_011dea10->FUN_005f36f0() && cell && cell->FUN_00546fb0())
            {
                MaterialRecord* result;
                FootstepQuery height;
                reinterpret_cast<NavOps*>(cell->FUN_00546fb0())->FUN_0053b550(&height, &firstPerson, 1);
                result = cell->FUN_00546fb0()->FUN_0053a630(height.materialKind, height.triangle);
                float record = 0.0f;
                materialIndex = 0;
                if (soundType)
                    materialIndex = 8;
                else if (material && material->FUN_009306d0() &&
                         material->FUN_009306d0()->material.FUN_0059bb30() != 36)
                    materialIndex = material->FUN_009306d0()->material.FUN_0059bb30();
                else if (result)
                {
                    materialIndex = result->GetField1C();
                    if (cell->FUN_005547c0(&firstPerson, &record))
                        firstPerson.z = record;
                }
            }
            else
            {
                if (soundType)
                    materialIndex = 8;
                else if (material && material->FUN_009306d0())
                    materialIndex = material->FUN_009306d0()->material.FUN_0059bb30();
            }
            if (foot > 1)
                foot -= 2;
            int special = foot == 0;
            int water = 0;
            if (actorOps->FUN_004997b0())
                special = foot ? 4 : 5;
            else if (movingActor)
                special = foot ? 6 : 7;
            else if (actorOps->FUN_00884730())
                special = foot ? 2 : 3;
            water = GetTypeValue(materialIndex);
            memory = DAT_011dd650[water].sounds[special];
            if (actorOps->FUN_008ba410())
            {
                if (!DAT_011dd860 || !DAT_011dd864)
                {
                    DAT_011dd864 =
                        reinterpret_cast<SoundOps*>(g_dataHandler_011c3f2c->FUN_004616c0(armorPowerRightName));
                    DAT_011dd860 =
                        reinterpret_cast<SoundOps*>(g_dataHandler_011c3f2c->FUN_004616c0(armorPowerLeftName));
                }
                sound = foot ? DAT_011dd860 : DAT_011dd864;
            }
            else if (actorOps->FUN_008ba440())
            {
                if (!DAT_011dd868 || !DAT_011dd86c)
                {
                    DAT_011dd86c = reinterpret_cast<SoundOps*>(g_dataHandler_011c3f2c->FUN_004616c0(armorRightName));
                    DAT_011dd868 = reinterpret_cast<SoundOps*>(g_dataHandler_011c3f2c->FUN_004616c0(armorLeftName));
                }
                sound = foot ? DAT_011dd868 : DAT_011dd86c;
            }
            if (apActor == g_player_011dea3c && !g_player_011dea3c->FUN_00524d10())
                pos = true;
            if (pos)
            {
                unsigned int flags = 0x4109;
                if (memory)
                {
                    primary = AudioOps::FUN_00453a70()->FUN_00ad7480(memory->FUN_00511840(), flags, memory);
                    primary.FUN_00ad89e0(*DAT_011dd988.FUN_00403e20());
                    primary.Play(0);
                }
                if (sound)
                {
                    secondary = AudioOps::FUN_00453a70()->FUN_00ad7480(sound->FUN_00511840(), flags, sound);
                    secondary.FUN_00ad89e0(*DAT_011dd988.FUN_00403e20());
                    secondary.Play(0);
                }
            }
            else
            {
                unsigned int flags = 0x410a;
                if (memory && armor <= memory->GetField45() * 100)
                {
                    primary = AudioOps::FUN_00453a70()->FUN_00ad7480(memory->FUN_00511840(), flags, memory);
                    primary.SetPos(firstPerson.x, firstPerson.y, firstPerson.z - 128.0);
                    if (apActor->Get3D())
                        primary.SetNiNode(apActor->Get3D());
                    primary.FUN_00ad89e0(FUN_00476b70(0.9f, 1.0f));
                    primary.Play(0);
                }
                if (sound && armor <= sound->GetField45() * 100)
                {
                    secondary = AudioOps::FUN_00453a70()->FUN_00ad7480(sound->FUN_00511840(), flags, sound);
                    secondary.SetPos(firstPerson.x, firstPerson.y, firstPerson.z - 128.0);
                    if (apActor->Get3D())
                        secondary.SetNiNode(apActor->Get3D());
                    secondary.FUN_00ad89e0(1.0 - FUN_00476b70(0.0f, g_fFootstepRand_0101e2bc));
                    secondary.Play(0);
                }
            }
        }
    }
}

struct FUN_00ad8b60_h
{
    bool SetPos(float x, float y, float z);
};

struct FUN_00ad8830_shell : FUN_00ad8b60_h
{
    bool Play(bool flag);
};

struct SH_00418890 : FUN_00ad8830_shell
{
    void FUN_copy(const void* src);
};

struct GlobalObject_0041a250 : SH_00418890
{
    int unk00;
    int unk04;
    int unk08;
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
};

struct BSSoundHandleEx
{
    int unk00;
    int unk04;
    int unk08;
    ~BSSoundHandleEx();
};

class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    BSSoundHandleEx FUN_00ad7480(const char* path, unsigned int flags, unsigned int sound);
    BSSoundHandleEx GetSoundHandleByEditorID(const char* name, unsigned int flags);
};

struct FUN_005224e0_class
{
    unsigned int GetField230();
};

struct FUN_00522df0_shell : FUN_005224e0_class
{
    int FUN_00446390();
};

struct NiPoint3_ext : NiPoint3
{
    NiPoint3_ext();
};

float FUN_0040ebd0(float a, float b);
float FUN_00404010(float a, float b);

// @fnv 0x008397f0
void PlayBlockSound(int aUnused, FUN_00522df0_shell* pObject, float x0, float y0, float z0, float x1, float y1,
                    float z1)
{
    GlobalObject_0041a250 p;
    if (pObject != 0 && pObject->GetField230() != 0)
    {
        p.FUN_copy(&BSAudio::GetSingleton()->FUN_00ad7480(((TESSound*)pObject->GetField230())->FUN_00511840(), 0x182,
                                                          pObject->GetField230()));
    }
    else
    {
        int weaponType = (pObject != 0) ? pObject->FUN_00446390() : -1;
        switch (weaponType)
        {
        case -1:
            p.FUN_copy(&BSAudio::GetSingleton()->GetSoundHandleByEditorID("WPNBlockHand", 0x182));
            break;
        default:
            p.FUN_copy(&BSAudio::GetSingleton()->GetSoundHandleByEditorID("WPNBlockMelee", 0x182));
            break;
        }
    }
    NiPoint3_ext v;
    v.x = (float)(FUN_0040ebd0(x0, x1) + (FUN_00404010(x0, x1) - FUN_0040ebd0(x0, x1)) / 2.0);
    v.y = (float)(FUN_0040ebd0(y0, y1) + (FUN_00404010(y0, y1) - FUN_0040ebd0(y0, y1)) / 2.0);
    v.z = (float)(FUN_0040ebd0(z0, z1) + (FUN_00404010(z0, z1) - FUN_0040ebd0(z0, z1)) / 2.0);
    p.SetPos(v.x, v.y, v.z);
    p.Play(false);
}

extern SoundOps* DAT_011dd870;
extern SoundOps* DAT_011dd874;
// Plays a footstep or jump sound for ref, choosing the material sound and optional armor/jump sound based on the surface and actor state.
// @fnv 0x00838780
void __cdecl FUN_00838780(TESObjectREFR* apRefr)
{
    AutoMemHelper memCtx5(11, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Audio\\ImpactMixer.cpp", 941);
    if (FUN_00702360())
        return;
    S_0083a930_Point3 pos20 = *apRefr->GetPos();
    SoundPlaybackHandle handle12;
    SoundPlaybackHandle handle6;
    SoundOps* impact1 = 0;
    SoundOps* second9 = 0;
    bool isBaby9 = false;
    float scale2 = *DAT_011dd900.FUN_00403e20();
    if (FUN_00525420())
        scale2 /= 2.0;
    float distBX = 0.0f;
    if (AudioOps::FUN_00453a70()->FUN_0044edb0())
    {
        PointOps vec = *(PointOps*)&AudioOps::FUN_00453a70()->FUN_0044edb0()->GetPosition();
        vec.Subtract(*(NiPoint3*)&pos20);
        distBX = vec.FUN_00457990();
        if (scale2 < vec.FUN_00457990())
            return;
    }
    if (((FootstepActor*)apRefr)->IsActor())
    {
        ActorOps* pActor = (ActorOps*)dynamic_cast<Actor*>(apRefr);
        if (pActor->SuppressFootsteps(0))
            return;
        if (pActor->IsCreature())
        {
            TESBoundObject* bolt6 = ((ActorOps*)apRefr)->FUN_007af430();
            TESCreature* creature6 = dynamic_cast<TESCreature*>(bolt6);
            SoundOps* csnd = creature6->FUN_005f92d0(0x14);
            impact1 = csnd;
            if (impact1)
            {
                if ((float)(impact1->GetField45() * 100) >= distBX)
                {
                    handle12 = AudioOps::FUN_00453a70()->FUN_00ad73b0(impact1->FUN_0084e3a0(0x10a));
                }
            }
            handle12.SetPos(pos20.x, pos20.y, pos20.z);
            if (creature6->FUN_00acbb70())
                handle12.SetNiNode(creature6->FUN_00acbb70());
            handle12.FUN_00ad89e0(0.98f);
            handle12.Play(0);
        }
        else
        {
            int material6 = 0;
            FootstepCell* cell8 = g_TES_011dea10->FUN_005f36f0();
            if (!cell8)
                cell8 = g_dataHandler_011c3f2c->FUN_00461bc0(pos20.x, pos20.y, g_TES_011dea10->FUN_004fd3e0(0));
            bool flagWater6 = false;
            bool local2 = false;
            if (!pActor->FUN_005a2030())
            {
                if (cell8 && pos20.z < pActor->FUN_0057b0a0())
                {
                    if ((cell8->FUN_00425fd0() && cell8->FUN_004518e0()) || !cell8->FUN_00425fd0())
                        flagWater6 = true;
                }
            }
            ActorOps* pq = pActor;
            if (pq->FUN_009306d0()->FUN_00838750())
                local2 = true;
            if (!g_TES_011dea10->FUN_005f36f0() && cell8 && cell8->FUN_00546fb0())
            {
                FootstepQuery query4;
                cell8->FUN_00546fb0()->FUN_0053b550((NavQueryResult*)&query4, (NiPoint3*)&pos20, 1);
                MaterialRecord* localA = cell8->FUN_00546fb0()->FUN_0053a630(query4.materialKind, query4.triangle);
                float heightStepB = 0.0f;
                material6 = 0;
                if (flagWater6)
                    material6 = 8;
                else if (pq && pq->FUN_009306d0() && pq->FUN_009306d0()->material.FUN_0059bb30() != 0x24)
                    material6 = pq->FUN_009306d0()->material.FUN_0059bb30();
                else if (localA)
                {
                    material6 = localA->GetField1C();
                    if (cell8->FUN_005547c0((NiPoint3*)&pos20, &heightStepB))
                        pos20.z = heightStepB;
                }
            }
            else
            {
                if (flagWater6)
                    material6 = 8;
                else if (pq && pq->FUN_009306d0())
                    material6 = pq->FUN_009306d0()->material.FUN_0059bb30();
            }
            int idx11 = 9;
            int typeY = 0;
            typeY = GetTypeValue(material6);
            impact1 = DAT_011dd650[typeY].sounds[idx11];
            if (pActor->FUN_008ba410())
            {
                if (!DAT_011dd874)
                    DAT_011dd874 = (SoundOps*)g_dataHandler_011c3f2c->FUN_004616c0("FSTJumpPower");
                second9 = DAT_011dd870;
            }
            else if (pActor->FUN_008ba440())
            {
                if (!DAT_011dd870)
                    DAT_011dd870 = (SoundOps*)g_dataHandler_011c3f2c->FUN_004616c0("FSTJumpArmor");
                second9 = DAT_011dd870;
            }
            if (apRefr == (TESObjectREFR*)g_player_011dea3c)
            {
                if (!g_player_011dea3c->FUN_00524d10())
                    isBaby9 = true;
            }
            if (isBaby9)
            {
                int flags = 0x4109;
                if (impact1)
                {
                    handle12 = AudioOps::FUN_00453a70()->FUN_00ad7480(impact1->FUN_00511840(), flags, impact1);
                    handle12.FUN_00ad89e0(*DAT_011dd988.FUN_00403e20());
                    handle12.Play(0);
                }
                if (second9)
                {
                    handle6 = AudioOps::FUN_00453a70()->FUN_00ad7480(second9->FUN_00511840(), flags, second9);
                    handle6.FUN_00ad89e0(*DAT_011dd988.FUN_00403e20());
                    handle6.Play(0);
                }
            }
            else
            {
                int flags2 = 0x410a;
                if (!FUN_0082eca0((TESSound*)impact1, pos20, 1.0f) && !FUN_0082eca0((TESSound*)second9, pos20, 1.0f))
                    return;
                if (impact1)
                {
                    if ((float)(impact1->GetField45() * 100) >= distBX)
                    {
                        handle12 = AudioOps::FUN_00453a70()->FUN_00ad7480(impact1->FUN_00511840(), flags2, impact1);
                        handle12.SetPos(pos20.x, pos20.y, (float)(pos20.z - 128.0));
                        if (apRefr->GetNode())
                            handle12.SetNiNode(apRefr->GetNode());
                        handle12.FUN_00ad89e0(FUN_00476b70(0.9f, 1.0f));
                        handle12.Play(0);
                    }
                }
                if (second9)
                {
                    if ((float)(second9->GetField45() * 100) >= distBX)
                    {
                        handle6 = AudioOps::FUN_00453a70()->FUN_00ad7480(second9->FUN_00511840(), flags2, second9);
                        handle6.SetPos(pos20.x, pos20.y, (float)(pos20.z - 128.0));
                        if (apRefr->GetNode())
                            handle6.SetNiNode(apRefr->GetNode());
                        handle6.FUN_00ad89e0(1.0f - FUN_00476b70(0.0f, g_fFootstepRand_0101e2bc));
                        handle6.Play(0);
                    }
                }
            }
        }
    }
}

namespace ImpactSound {

typedef NiPoint3 ImpactPoint;

struct ImpactMemContext
{
    int iOldContext;
    ImpactMemContext(int aiContext, bool abPush, const char* apFile, int aiLine);
    ~ImpactMemContext();
};

struct ImpactTimer
{
    int iData;
    ImpactTimer();
    ~ImpactTimer();
    void FUN_004538a0(const char* apName);
    void FUN_004538c0();
};

struct ImpactFormType
{
    int iData;
    ImpactFormType();
    int FUN_0043b4d0();
};

struct ImpactObject
{
    float FUN_0062ab20();
    ImpactFormType FUN_0043b4f0();
};

struct ImpactData
{
    ImpactPoint kPos;
    float fImpulse;
    int iUnk10;
    char cMaterialA;
    char cMaterialB;
    short sUnk16;
    unsigned int uiKey;
    ImpactObject* pObjectA;
    ImpactObject* pObjectB;
};

struct ImpactSoundForm
{
    unsigned int FUN_0084e3a0();
};

struct ImpactDataHandler
{
    ImpactSoundForm* FUN_004616c0(const char* apEditorID);
};

struct ImpactSoundHandle
{
    int m_uiSoundID;
    int iState;
    int iFlags;
    ImpactSoundHandle();
    ~ImpactSoundHandle();
    ImpactSoundHandle& operator=(const ImpactSoundHandle& arOther);
    void FUN_00ad9030(unsigned int auiVolume);
    bool SetPos(float afX, float afY, float afZ);
    bool SetStaticAttenuation(unsigned short ausFrequency);
    void FUN_00ad8a90(float afValue);
    bool Play(bool abFlag);
};

struct ImpactAudio
{
    static ImpactAudio* FUN_00453a70();
    ImpactSoundHandle FUN_00ad73b0(unsigned int auiFormID, unsigned int auiFlags);
};

struct ImpactHistory
{
    bool GetAt(unsigned int auiKey, unsigned int& arTime);
    void FUN_00844700(unsigned int auiKey, unsigned int auiTime);
    void* FUN_004b9ba0();
    void FUN_006b7f20(void*& arIter, unsigned int& arKey, int& arTime);
    bool RemoveKey(unsigned int auiKey);
    void FUN_00438af0();
};

struct ImpactIntSetting
{
    int* FUN_0043d4d0();
};

struct ImpactClock
{
    unsigned int FUN_00825c00();
};

extern ImpactHistory DAT_011dd948;
extern ImpactIntSetting DAT_011dd968;
extern ImpactClock DAT_011f6394;
extern ImpactPoint DAT_011dd958;
extern ImpactDataHandler* DAT_011c3f2c;
extern const double DAT_010179e0;

ImpactSoundForm* __cdecl FUN_00839e00(int aiMaterial, float afMass, float afImpulse);
bool __cdecl FUN_0040eb10(float afValue, float afTarget, float afRange);
bool __cdecl FUN_0082eca0(ImpactSoundForm* apForm, ImpactPoint akPos, float afScale);

static const char kCollisionSourcePath[] = "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Audio\\ImpactMixer.cpp";
static const char s_szTimerName[] = "ImpactMixer::PlayCollisionSound";
static const char s_szShotgun[] = "PHYCasingShotgun";
static const char s_szPistol[] = "PHYCasingPistol";
static const char s_szRifle[] = "PHYCasingRifle";

// Selects impact sounds from collision materials and object masses, adjusts frequency and volume from impulse, and prunes impact history.
// @fnv 0x00837550
void FUN_00837550(ImpactData* apImpact)
{
    ImpactMemContext kMemContext(0xb, true, kCollisionSourcePath, 0x234);
    if (apImpact->pObjectA == apImpact->pObjectB && apImpact->pObjectA)
        return;
    static ImpactTimer s_kTimer;
    s_kTimer.FUN_004538a0(s_szTimerName);
    float fScaledImpulseRes = apImpact->fImpulse * 0.014287499710917473;
    float fWaterLevelItem = apImpact->fImpulse / DAT_010179e0;
    unsigned int uiFlagsTmp = 0;
    if (apImpact->cMaterialA == 0x24 && apImpact->cMaterialB == 6)
        fWaterLevelItem *= 4.0;
    {
        float fMassASample = apImpact->pObjectA ? apImpact->pObjectA->FUN_0062ab20() : 5.0f;
        float fMassOfB = apImpact->pObjectB ? apImpact->pObjectB->FUN_0062ab20() : 5.0f;
        bool bCasingVal = false;
        ImpactSoundForm* pSoundA = 0;
        ImpactSoundForm* pSoundBNew = 0;
        if ((apImpact->pObjectA && apImpact->pObjectA->FUN_0043b4f0().FUN_0043b4d0() == 0x19) ||
            (apImpact->pObjectB && apImpact->pObjectB->FUN_0043b4f0().FUN_0043b4d0() == 0x19))
            bCasingVal = true;
        if (!bCasingVal)
        {
            pSoundA = FUN_00839e00(apImpact->cMaterialA, fMassASample, apImpact->fImpulse);
            pSoundBNew = FUN_00839e00(apImpact->cMaterialB, fMassOfB, apImpact->fImpulse);
        }
        else
        {
            uiFlagsTmp = 0x80;
            float fMass = fMassASample > fMassOfB ? fMassASample : fMassOfB;
            if (fMass < 1.0)
                pSoundA = DAT_011c3f2c->FUN_004616c0(s_szShotgun);
            else if (FUN_0040eb10(fMass, 2.0f, 0.25f))
                pSoundA = DAT_011c3f2c->FUN_004616c0(s_szPistol);
            else
                pSoundA = DAT_011c3f2c->FUN_004616c0(s_szRifle);
            pSoundBNew = 0;
        }
        if (!FUN_0082eca0(pSoundA, apImpact->kPos, 1.0f) && !FUN_0082eca0(pSoundBNew, apImpact->kPos, 1.0f))
        {
            s_kTimer.FUN_004538c0();
            return;
        }
        ImpactSoundHandle kHandleAResult;
        ImpactSoundHandle kHandleB;
        unsigned int uiNow = DAT_011f6394.FUN_00825c00();
        unsigned int uiLastTime = 0;
        if (DAT_011dd948.GetAt(apImpact->uiKey, uiLastTime) &&
            uiNow - uiLastTime < (unsigned int)*DAT_011dd968.FUN_0043d4d0())
        {
            s_kTimer.FUN_004538c0();
            return;
        }
        else
        {
            DAT_011dd948.FUN_00844700(apImpact->uiKey, uiNow);
        }
        if (pSoundA && !(apImpact->cMaterialA == 7 && apImpact->cMaterialB == 7))
            kHandleAResult =
                ImpactAudio::FUN_00453a70()->FUN_00ad73b0(pSoundA->FUN_0084e3a0(), uiFlagsTmp | 2 | 0x100 | 0x4000);
        if (pSoundBNew && !(apImpact->cMaterialA == 7 && apImpact->cMaterialB == 7))
            kHandleB =
                ImpactAudio::FUN_00453a70()->FUN_00ad73b0(pSoundBNew->FUN_0084e3a0(), uiFlagsTmp | 2 | 0x100 | 0x4000);
        unsigned int uiFrequencyVal =
            (unsigned int)((1.0 - (apImpact->fImpulse / 400.0 > 1.0 ? 1.0 : apImpact->fImpulse / 400.0)) * 3000.0);
        float fVolumeLoc = uiFrequencyVal < 0x5dc ? 1.0 : (uiFrequencyVal - 4500.0) / -3000.0;
        if (pSoundA)
        {
            kHandleAResult.FUN_00ad9030(0xff);
            kHandleAResult.SetPos(apImpact->kPos.x, apImpact->kPos.y, apImpact->kPos.z);
            kHandleAResult.SetStaticAttenuation(uiFrequencyVal);
            kHandleAResult.FUN_00ad8a90(fVolumeLoc);
            kHandleAResult.Play(false);
        }
        if (pSoundBNew)
        {
            kHandleB.FUN_00ad9030(0xff);
            kHandleB.SetPos(apImpact->kPos.x, apImpact->kPos.y, apImpact->kPos.z);
            kHandleB.SetStaticAttenuation(uiFrequencyVal);
            kHandleB.FUN_00ad8a90(fVolumeLoc);
            kHandleB.Play(false);
        }
        DAT_011dd958 = apImpact->kPos;
    }
    int iMaxAge = *DAT_011dd968.FUN_0043d4d0() * 4;
    void* pIter = DAT_011dd948.FUN_004b9ba0();
    int iNowCur = DAT_011f6394.FUN_00825c00();
    unsigned int uiVisited = 0;
    while (pIter)
    {
        uiVisited++;
        unsigned int uiEntryKeyVal;
        int iEntryTime;
        DAT_011dd948.FUN_006b7f20(pIter, uiEntryKeyVal, iEntryTime);
        if (iNowCur - iEntryTime > iMaxAge)
        {
            DAT_011dd948.RemoveKey(uiEntryKeyVal);
            pIter = DAT_011dd948.FUN_004b9ba0();
        }
        if (uiVisited > 0x100)
        {
            DAT_011dd948.FUN_00438af0();
            pIter = 0;
        }
    }
    s_kTimer.FUN_004538c0();
}

}
