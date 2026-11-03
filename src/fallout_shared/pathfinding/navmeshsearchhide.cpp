
// src/fallout_shared/pathfinding/navmeshsearchhide.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/navmeshsearchhide.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NavMeshSearchHide
{
    void FUN_006a9d60();
    void* DestroyIfFlagged(unsigned int flags);
};

void* _Deallocate(void*);

// Calls FUN_006a9d60, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x006a9d30
void* NavMeshSearchHide::DestroyIfFlagged(unsigned int flags)
{
    FUN_006a9d60();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct A9F60Point3
{
    float x;
    float y;
    float z;

    A9F60Point3 operator-(const A9F60Point3& pt) const;
    float Length() const;
};

void __cdecl FUN_005330e0(float* pfValue, float fMin, float fScaledValue);

struct A9F60Actor
{
    A9F60Point3 GetNodePosition(unsigned short usNode);
};

struct A9F60Entry
{
    int unk00;
    float m_fScore;
    A9F60Actor* m_pkActor;
    unsigned short m_usNode;
    unsigned short unk0E;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
};

struct A9F60Block256
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
};

struct A9F60Tracker
{
    A9F60Block256 unk0000;
    A9F60Block256 unk0100;
    A9F60Block256 unk0200;
    A9F60Block256 unk0300;
    A9F60Block256 unk0400;
    A9F60Block256 unk0500;
    A9F60Block256 unk0600;
    A9F60Block256 unk0700;
    A9F60Block256 unk0800;
    A9F60Block256 unk0900;
    A9F60Block256 unk0A00;
    A9F60Block256 unk0B00;
    A9F60Block256 unk0C00;
    A9F60Block256 unk0D00;
    A9F60Block256 unk0E00;
    A9F60Block256 unk0F00;
    A9F60Block256 unk1000;
    A9F60Block256 unk1100;
    A9F60Block256 unk1200;
    A9F60Block256 unk1300;
    A9F60Block256 unk1400;
    A9F60Block256 unk1500;
    A9F60Block256 unk1600;
    A9F60Block256 unk1700;
    A9F60Block256 unk1800;
    A9F60Block256 unk1900;
    A9F60Block256 unk1A00;
    A9F60Block256 unk1B00;
    A9F60Block256 unk1C00;
    A9F60Block256 unk1D00;
    A9F60Block256 unk1E00;
    A9F60Block256 unk1F00;
    int unk2000;
    int unk2004;
    int unk2008;
    int unk200C;
    int unk2010;
    int unk2014;
    int unk2018;
    int unk201C;
    int unk2020;
    int unk2024;
    int unk2028;
    int unk202C;
    int unk2030;
    int unk2034;
    int unk2038;
    int unk203C;
    int unk2040;
    int unk2044;
    int unk2048;
    int unk204C;
    int unk2050;
    int unk2054;
    int unk2058;
    int unk205C;
    int unk2060;
    int unk2064;
    int unk2068;
    int unk206C;
    int unk2070;
    int unk2074;
    int unk2078;
    int unk207C;
    int unk2080;
    int unk2084;
    int unk2088;
    int unk208C;
    int unk2090;
    int unk2094;
    int unk2098;
    int unk209C;
    int unk20A0;
    int unk20A4;
    int unk20A8;
    int unk20AC;
    int unk20B0;
    int unk20B4;
    int unk20B8;
    A9F60Point3 m_kStartPoint;
    float m_fFirstLightParameter;

    void InitEntry(A9F60Entry* pkEntry, A9F60Actor* pkActor, unsigned short usNode);
};

// @fnv 0x006a9f60
void A9F60Tracker::InitEntry(A9F60Entry* pkEntry, A9F60Actor* pkActor, unsigned short usNode)
{
    pkEntry->m_pkActor = pkActor;
    pkEntry->m_usNode = usNode;
    A9F60Point3 kPos4 = pkActor->GetNodePosition(usNode);
    pkEntry->m_fVectorY = kPos4.x;
    pkEntry->m_fVectorZ = kPos4.y;
    pkEntry->m_fScalarPart = kPos4.z;
    A9F60Point3 kDiff = kPos4 - m_kStartPoint;
    float fScore6 = m_fFirstLightParameter - kDiff.Length();
    FUN_005330e0(&fScore6, 0.0f, m_fFirstLightParameter);
    pkEntry->m_fScore = fScore6;
}

struct NiPoint3
{
    float x, y, z;
    NiPoint3 FUN_00439ef0(const NiPoint3& kOther) const;
    float FUN_00589850() const;
    float FUN_00457990() const;
    float DotProduct(const NiPoint3& kOther) const;
};

struct NavMeshTriangle
{
    bool FUN_00691140(unsigned int uiFlag);
};

struct NavMeshStandIn
{
    bool FindAdjacentEdge(unsigned short usTri, int iSide, NavMeshStandIn** m_ppLandNodes, unsigned short* pusTri,
                          int* piUnk);
    int* FUN_0068f230(unsigned short usTri, int iSide);
    NavMeshTriangle* FUN_005582f0(unsigned short usTri);
    unsigned int* FUN_00699af0(unsigned short usTri);
    NiPoint3 FUN_00558220(unsigned short usTri);
};

struct NavMeshTriRef
{
    NavMeshStandIn* m_pMesh;
    unsigned short m_usTri;
    NiPoint3 FUN_006a6eb0();
};

struct NavSearchNodeInfo
{
    float m_fCost;
    int unk04;
    NavMeshTriRef m_kRef;
    int FUN_0045cd60();
};

struct NavSearchNode
{
    char pad00[0x1c];
    NavMeshStandIn* m_pMesh;
    unsigned short m_usTri;
    int m_iSide;
};

struct NavSearchNodeList
{
    void FUN_007cb2e0(NavSearchNode** ppNode);
};

struct ActorPosSource
{
    NiPoint3 FUN_005c3420();
};

struct HideTarget
{
    float SumNodeValues(NiPoint3* pkPoint);
};

struct ActorStandIn
{
    ActorPosSource* GetOffsetC();
    bool FUN_0073cb80();
    float GetFloatAtOffset68();
    HideTarget* GetString();
};

struct FloatSetting
{
    float* FUN_00403e20();
};
extern FloatSetting g_setting_011d6ef0;

struct TESForm;
extern "C" TESForm* __cdecl LookupFormByID(unsigned int auiFormId);

struct DoorCheckSource
{
    void* FUN_006c9900();
};

struct DoorFormStandIn;
struct DoorBase
{
    bool FUN_00518000();
};
struct TESFormStandIn
{
    DoorBase* FUN_007af430();
};

struct DoorCheck
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    DoorCheck(TESForm* pkForm);
    ~DoorCheck();
    bool FUN_00502450(void* pkSource, TESForm* pkForm, bool* pbResult);
};

float __cdecl FUN_00404010(float fA, float fB);

struct HideSearch
{
    char pad0000[0x2058];
    DoorCheckSource* unk2058;
    char pad205c[0x20a4 - 0x205c];
    ActorStandIn* m_pActor;
    char pad20a8[0x20cc - 0x20a8];
    NiPoint3 m_kTargetPos;

    int FUN_006a94f0(NavMeshStandIn* pMesh, unsigned short usTri, float m_fPathingCostCur, NavSearchNode** ppNode);
    int FUN_006a7e00(int iResult);
    void InitEntry(NavSearchNode* pNode, NavMeshStandIn* pMesh, unsigned short usTri);
    bool ExpandNeighbors(NavSearchNodeInfo* pkInfo, NavSearchNodeList* pkList);
};

// @fnv 0x006aa000
bool HideSearch::ExpandNeighbors(NavSearchNodeInfo* pkInfo, NavSearchNodeList* pkList)
{
    NiPoint3 kPosX = pkInfo->FUN_0045cd60() ? pkInfo->m_kRef.FUN_006a6eb0() : m_pActor->GetOffsetC()->FUN_005c3420();
    for (int i9 = 0; i9 < 3; i9++)
    {
        NavMeshStandIn* pMesh5;
        unsigned short usTriZ;
        int iUnkZ;
        if (pkInfo->m_kRef.m_pMesh->FindAdjacentEdge(pkInfo->m_kRef.m_usTri, i9, &pMesh5, &usTriZ, &iUnkZ))
        {
            int* pEdgeWork = pkInfo->m_kRef.m_pMesh->FUN_0068f230(pkInfo->m_kRef.m_usTri, i9);
            if (pEdgeWork && *pEdgeWork == 1)
                continue;
            float fMultY = 1.0f;
            if (pMesh5->FUN_005582f0(usTriZ)->FUN_00691140(0x1000))
            {
                if (m_pActor->FUN_0073cb80())
                    continue;
                else
                {
                    unsigned int uiFormIDOut = *pMesh5->FUN_00699af0(usTriZ);
                    TESForm* pForm2 = LookupFormByID(uiFormIDOut);
                    if (pForm2)
                    {
                        DoorCheck kCheck_2(pForm2);
                        void* pSource_2 = unk2058->FUN_006c9900();
                        bool bResultZ;
                        if (!kCheck_2.FUN_00502450(pSource_2, pForm2, &bResultZ))
                            continue;
                        if (((TESFormStandIn*)pForm2)->FUN_007af430()->FUN_00518000())
                            fMultY = 100.0f;
                    }
                }
            }
            if (m_pActor->GetFloatAtOffset68() > *g_setting_011d6ef0.FUN_00403e20() &&
                pMesh5->FUN_005582f0(usTriZ)->FUN_00691140(0x10))
                continue;
            NiPoint3 kCenterTmp = pMesh5->FUN_00558220(usTriZ);
            NiPoint3 kDeltaW = kCenterTmp.FUN_00439ef0(kPosX);
            float fCost_ = kDeltaW.FUN_00589850() * fMultY + pkInfo->m_fCost;
            float fExtraZ = 0.0f;
            if (m_pActor->GetString())
                fExtraZ = m_pActor->GetString()->SumNodeValues(&kCenterTmp);
            float fDist6 = kCenterTmp.FUN_00439ef0(m_kTargetPos).FUN_00589850();
            float fNearOut = 1.0f - fDist6 / 512.0;
            fExtraZ += FUN_00404010(fNearOut, 0.0f);
            NiPoint3 kToTargetWork = m_kTargetPos.FUN_00439ef0(kPosX);
            float fDot_2 = kToTargetWork.DotProduct(kDeltaW);
            float fLenA_2 = kToTargetWork.FUN_00457990();
            float fLenBY = kDeltaW.FUN_00457990();
            if (fLenA_2 == 0.0 || fLenBY == 0.0)
                fDot_2 = 0.0f;
            else
                fDot_2 = fDot_2 / (fLenA_2 * fLenBY);
            fExtraZ += FUN_00404010(fDot_2, 0.0f);
            fCost_ = (1.0f + fExtraZ) * fCost_;
            NavSearchNode* pNode;
            switch (FUN_006a7e00(FUN_006a94f0(pMesh5, usTriZ, fCost_, &pNode)))
            {
            case 0:
                InitEntry(pNode, pMesh5, usTriZ);
            case 1:
                pNode->m_pMesh = pkInfo->m_kRef.m_pMesh;
                pNode->m_usTri = pkInfo->m_kRef.m_usTri;
                pNode->m_iSide = i9;
                pkList->FUN_007cb2e0(&pNode);
                break;
            }
        }
    }
    return true;
}

struct HideTgtx
{
    float FUN_006dc9f0(NiPoint3* pkPoint, NiPoint3* pkOrigin);
};

struct ActorX
{
    ActorPosSource* GetOffsetC();
    HideTgtx* GetString();
    ActorPosSource* FUN_00984230();
};

struct MeshX
{
    NiPoint3 FUN_00558220(unsigned short usTri);
};

struct TriRef20
{
    MeshX* m_pMesh;
    unsigned short m_usTri;
    unsigned short unk06;
    NiPoint3 m_kPt;
};

struct InfoF
{
    MeshX* m_pMesh;
    unsigned short m_usTri;
    unsigned short unk06;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;

    NiPoint3* FUN_006a6eb0(NiPoint3* pOut);
};

struct ParamX
{
    bool FUN_0076b610();
};

void __cdecl FUN_005330e0(float* pfValue, float fMin, float fScaledValue);

extern NiPoint3 DAT_011f426c;

struct Block256x
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
};

struct HideSearchX
{
    Block256x m_kBlocks[32];
    int unk2000;
    int unk2004;
    int unk2008;
    int unk200C;
    int unk2010;
    int unk2014;
    int unk2018;
    int unk201C;
    int unk2020;
    int unk2024;
    int unk2028;
    int unk202C;
    int unk2030;
    int unk2034;
    int unk2038;
    int unk203C;
    int unk2040;
    int unk2044;
    int unk2048;
    int unk204C;
    int unk2050;
    int unk2054;
    ActorX* unk2058;
    int unk205C;
    int unk2060;
    int unk2064;
    int unk2068;
    int unk206C;
    int unk2070;
    int unk2074;
    int unk2078;
    int unk207C;
    int unk2080;
    int unk2084;
    int unk2088;
    int unk208C;
    int unk2090;
    int unk2094;
    int unk2098;
    int unk209C;
    int unk20A0;
    ActorX* m_pActor;
    TriRef20 m_kInfo;
    NiPoint3 m_kStartPoint;
    float m_fFirstLightParameter;
    NiPoint3 m_kTargetPos;

    int FUN_006a94f0(MeshX* pMesh, unsigned short usTri);
    void FUN_006a7c90(int iPacked, InfoF* pkInfo, float fVal);
    void FUN_006a7d60(ParamX* pkObj, int iArg, int iOne);
    int SetupActorTarget(ActorX* pkActor, TriRef20* pkInfo, ParamX* pkObj, int iArg);
};

// @fnv 0x006a9d80
int HideSearchX::SetupActorTarget(ActorX* pkActor, TriRef20* pkInfo, ParamX* pkObj, int iArg)
{
    unk2058 = pkActor;
    m_pActor = pkActor;
    m_kInfo = *pkInfo;

    NiPoint3 kActorPos5 = pkActor->GetOffsetC()->FUN_005c3420();
    m_kStartPoint = DAT_011f426c;
    m_fFirstLightParameter = 0.0f;
    if (m_pActor->GetString())
    {
        m_fFirstLightParameter = m_pActor->GetString()->FUN_006dc9f0(&kActorPos5, &m_kStartPoint);
    }

    InfoF kInfo3;
    kInfo3.m_pMesh = pkInfo->m_pMesh;
    kInfo3.m_usTri = pkInfo->m_usTri;
    NiPoint3 kTmp_2 = kInfo3.m_pMesh->FUN_00558220(kInfo3.m_usTri);
    kInfo3.m_fVectorY = kTmp_2.x;
    kInfo3.m_fVectorZ = kTmp_2.y;
    kInfo3.m_fScalarPart = kTmp_2.z;

    NiPoint3 kTriPt2;
    NiPoint3 kDiff = kInfo3.FUN_006a6eb0(&kTriPt2)->FUN_00439ef0(m_kStartPoint);
    float fVal6 = m_fFirstLightParameter - kDiff.FUN_00457990();
    FUN_005330e0(&fVal6, 0.0f, m_fFirstLightParameter);

    FUN_006a7c90(FUN_006a94f0(kInfo3.m_pMesh, kInfo3.m_usTri), &kInfo3, fVal6);

    m_kTargetPos = m_pActor->FUN_00984230()->FUN_005c3420();

    FUN_006a7d60(pkObj, iArg, 1);
    return !pkObj->FUN_0076b610();
}

extern const double DAT_01012060;

struct FUN_006815c0
{
    FUN_006815c0();
    float m_fCoefficientA;
    float m_fB;
    float m_fC;
};

bool __cdecl FUN_006b9790(const NiPoint3& kA, const NiPoint3& kB, const NiPoint3& kC, const NiPoint3& kPoint,
                          FUN_006815c0* pkOut);

struct NavMesh6aa4
{
    const NiPoint3& FUN_0068f0a0(unsigned short m_usVertexId);
};

struct NavInfo6aa4
{
    bool HasFlags();
    void GetTripleShorts(unsigned short* pusA, unsigned short* pusB, unsigned short* pusC);
    unsigned short FUN_00698030(unsigned short usSide);
};

struct NavList6aa4
{
    NavMesh6aa4* m_pkMesh;
    NavInfo6aa4* FUN_006a78d0();
};

struct NavData6aa4
{
    float m_fCost;
    int unk04;
    NavMeshTriRef m_kRef;
    NavList6aa4* FUN_00413f40();
};

struct Target6aa4
{
    float SumNodeValues(NiPoint3* pkPoint);
};

struct Range6aa4
{
    float FUN_00885bd0();
    Target6aa4* GetString();
};

struct FUN_006aa470_cls
{
    char pad0000[0x20a4];
    Range6aa4* m_pkActor;
    char pad20a8[0x20cc - 0x20a8];
    NiPoint3 m_kTargetPos;

    bool FUN_006aa470(NavData6aa4* pkData);
};

// @fnv 0x006aa470
bool FUN_006aa470_cls::FUN_006aa470(NavData6aa4* pkData)
{
    NavList6aa4* pkList = pkData->FUN_00413f40();
    NavInfo6aa4* pkInfo7 = pkList->FUN_006a78d0();
    if (!pkInfo7->HasFlags())
        return false;

    NiPoint3 kPos = pkData->m_kRef.FUN_006a6eb0();
    float aFLength = m_kTargetPos.FUN_00439ef0(kPos).FUN_00589850();
    if (aFLength < m_pkActor->FUN_00885bd0())
        return false;

    NavMesh6aa4* pkMesh6 = pkList->m_pkMesh;
    unsigned short usA5, usB, usC;
    pkInfo7->GetTripleShorts(&usA5, &usB, &usC);
    FUN_006815c0 kOut3;
    bool bFound8 = false;
    FUN_006b9790(pkMesh6->FUN_0068f0a0(usA5), pkMesh6->FUN_0068f0a0(usB), pkMesh6->FUN_0068f0a0(usC), m_kTargetPos,
                 &kOut3);
    if (kOut3.m_fCoefficientA < DAT_01012060 && pkInfo7->FUN_00698030(1) > 0)
        bFound8 = true;
    else if (kOut3.m_fC < DAT_01012060 && pkInfo7->FUN_00698030(0) > 0)
        bFound8 = true;
    if (!bFound8)
        return false;

    float fDist_2 = 0.0f;
    if (m_pkActor->GetString())
        fDist_2 = m_pkActor->GetString()->SumNodeValues(&kPos);
    return fDist_2 <= DAT_01012060;
}

struct NavMeshSearch
{
    void FUN_006a6b00();
};
extern int DAT_0106b7dc;

// @fnv 0x006a9d60
void NavMeshSearchHide::FUN_006a9d60()
{
    *reinterpret_cast<void**>(this) = &DAT_0106b7dc;
    reinterpret_cast<NavMeshSearch*>(this)->FUN_006a6b00();
}
