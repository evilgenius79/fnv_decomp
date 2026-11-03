// src/fallout/ai/actor_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/ai/actor.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "Actor.h"

#include <xmmintrin.h>
namespace ActorUpdate3D {

struct NiPoint3
{
    float x, y, z;
    NiPoint3();
    NiPoint3(float afX, float afY, float afZ);
    NiPoint3 FUN_00439e90(const NiPoint3& arOther) const;
    NiPoint3 FUN_00439ef0(const NiPoint3& arOther) const;
    float FUN_00457990() const;
};

struct ThreeByThreeMatrix
{
    float m[9];
    ThreeByThreeMatrix();
    void FUN_004a0c90(float afAngle);
    NiPoint3 FUN_004b4500(const NiPoint3& arPoint) const;
};

struct NiBound
{
    float fData[4];
    NiPoint3* FUN_006815c0();
    float FUN_0084d030();
};

struct AlignedRotation
{
    __m128 vec;
    AlignedRotation(float afA, float afB, float afC, float afD);
};

struct FormType
{
    int iData;
    FormType();
    int FUN_0043b4d0();
};

struct HandleRef
{
    int iData;
    HandleRef();
    int FUN_004a3a20();
};

struct NiObject
{
    float GetFloatAtOffsetB0();
};

struct NiNode
{
    virtual void vn000();
    virtual void vn001();
    virtual void vn002();
    virtual void vn003();
    virtual NiObject* FUN_vt10();
    NiBound* FUN_0043d450();
};

struct NiAVObject
{
    int FUN_006838b0();
};

struct ProfileMarker
{
    void FUN_00483710();
};

struct Clock
{
    float FUN_0084d030();
};

struct ActorList
{
    unsigned int FUN_0044ddc0();
    float FUN_009c8d60();
};

struct CombatController
{
    void FUN_008879d0(bool abFar);
    void FUN_00810610(bool abValue);
};

struct Process
{
    virtual void vp000();
    virtual void vp001();
    virtual void vp002();
    virtual void vp003();
    virtual void vp004();
    virtual void vp005();
    virtual void vp006();
    virtual void vp007();
    virtual void vp008();
    virtual void vp009();
    virtual void FUN_vt28();
    virtual void vp00b();
    virtual void vp00c();
    virtual void vp00d();
    virtual void vp00e();
    virtual void vp00f();
    virtual void vp010();
    virtual void vp011();
    virtual void vp012();
    virtual void vp013();
    virtual void vp014();
    virtual void vp015();
    virtual void vp016();
    virtual void vp017();
    virtual void vp018();
    virtual void vp019();
    virtual void vp01a();
    virtual void vp01b();
    virtual void vp01c();
    virtual void vp01d();
    virtual void vp01e();
    virtual void vp01f();
    virtual void vp020();
    virtual void vp021();
    virtual void vp022();
    virtual void vp023();
    virtual void vp024();
    virtual void vp025();
    virtual void vp026();
    virtual void vp027();
    virtual void vp028();
    virtual void vp029();
    virtual void vp02a();
    virtual void vp02b();
    virtual void vp02c();
    virtual void vp02d();
    virtual void vp02e();
    virtual void vp02f();
    virtual void vp030();
    virtual void vp031();
    virtual void vp032();
    virtual void vp033();
    virtual void vp034();
    virtual void vp035();
    virtual void vp036();
    virtual void vp037();
    virtual void vp038();
    virtual void vp039();
    virtual void vp03a();
    virtual void vp03b();
    virtual void vp03c();
    virtual void vp03d();
    virtual void vp03e();
    virtual void vp03f();
    virtual void vp040();
    virtual void vp041();
    virtual void vp042();
    virtual void vp043();
    virtual void vp044();
    virtual void vp045();
    virtual void vp046();
    virtual void vp047();
    virtual void vp048();
    virtual void vp049();
    virtual void vp04a();
    virtual void vp04b();
    virtual void vp04c();
    virtual void vp04d();
    virtual void vp04e();
    virtual void vp04f();
    virtual void vp050();
    virtual void vp051();
    virtual void vp052();
    virtual void vp053();
    virtual void vp054();
    virtual void vp055();
    virtual void vp056();
    virtual void vp057();
    virtual void vp058();
    virtual void vp059();
    virtual void vp05a();
    virtual void vp05b();
    virtual void vp05c();
    virtual void vp05d();
    virtual void vp05e();
    virtual void vp05f();
    virtual void vp060();
    virtual void vp061();
    virtual void vp062();
    virtual void vp063();
    virtual void vp064();
    virtual void vp065();
    virtual void vp066();
    virtual void vp067();
    virtual void vp068();
    virtual void vp069();
    virtual void vp06a();
    virtual void vp06b();
    virtual void vp06c();
    virtual void vp06d();
    virtual void vp06e();
    virtual void vp06f();
    virtual void vp070();
    virtual void vp071();
    virtual void vp072();
    virtual void vp073();
    virtual void vp074();
    virtual void vp075();
    virtual void vp076();
    virtual void vp077();
    virtual void vp078();
    virtual void vp079();
    virtual void vp07a();
    virtual void vp07b();
    virtual void vp07c();
    virtual void vp07d();
    virtual void vp07e();
    virtual void vp07f();
    virtual void vp080();
    virtual void vp081();
    virtual void vp082();
    virtual void vp083();
    virtual void vp084();
    virtual void vp085();
    virtual void vp086();
    virtual void vp087();
    virtual void vp088();
    virtual void vp089();
    virtual void vp08a();
    virtual void vp08b();
    virtual void vp08c();
    virtual void vp08d();
    virtual void vp08e();
    virtual void vp08f();
    virtual void vp090();
    virtual void vp091();
    virtual void vp092();
    virtual void vp093();
    virtual void vp094();
    virtual void vp095();
    virtual void vp096();
    virtual void vp097();
    virtual void vp098();
    virtual void vp099();
    virtual void vp09a();
    virtual void vp09b();
    virtual void vp09c();
    virtual void vp09d();
    virtual void vp09e();
    virtual void vp09f();
    virtual void vp0a0();
    virtual void vp0a1();
    virtual void vp0a2();
    virtual CombatController* FUN_vt28c();
};

struct Holder
{
    virtual void vh000();
    virtual void vh001();
    virtual void vh002();
    virtual void vh003();
    virtual void vh004();
    virtual void vh005();
    virtual void vh006();
    virtual void vh007();
    virtual int FUN_vt20();
    virtual bool FUN_vt24(NiPoint3* apPos);
};

struct PathMover
{
    void GetMovement(NiPoint3* apPos, void* apActor, int aiA, int aiB);
};

struct LookTarget
{
    bool FUN_00450ff0();
};

struct CameraNode
{
    NiPoint3* FUN_0045bb80();
};

struct LodManager
{
    int GetStringAtOffset13C();
    void UpdateOrAddItem(int aiRefID, NiBound* apBound, bool abVisible);
};

struct BaseForm
{
    int FUN_00401170();
};

struct Havok
{
    bool FUN_00552490();
    void FUN_00c7c150(int aiValue);
};

struct Ragdoll
{
    void FUN_00ca2ad0(NiNode* apRoot, int aiValue);
};

struct AnimSequence
{
    float FUN_00508100();
    void FUN_0098adb0(float afTime);
};

struct AnimController
{
    bool FUN_00494710(int aiGroup);
    void FUN_004955c0(int aiA, int aiGroup, int aiB, float afC, int aiD);
    AnimSequence* FUN_00491040(int aiValue);
    void FUN_00491180(void* apActor, float afA, float afB);
    void FUN_00493900(void* apActor);
};

struct ListNode;

struct ChildPtr
{
    NiAVObject* FUN_00559450();
};

struct ListNode
{
    ChildPtr* FUN_006815c0();
    ListNode* FUN_00726070();
};

struct ShaderProp
{
    struct ShaderData* FUN_00887a10();
    void FUN_00887a80(int aiValue);
    void FUN_00887ac0(float afValue);
};

struct ShaderData
{
    float GetFloatAt0xC8();
    float FUN_00644a50();
};

struct PropertyHolder
{
    virtual void vr000();
    virtual void vr001();
    virtual void vr002();
    virtual void vr003();
    virtual void vr004();
    virtual void vr005();
    virtual void vr006();
    virtual void vr007();
    virtual void vr008();
    virtual void vr009();
    virtual void vr00a();
    virtual void vr00b();
    virtual void vr00c();
    virtual void vr00d();
    virtual void vr00e();
    virtual void vr00f();
    virtual void vr010();
    virtual ShaderProp* FUN_vt44();
};

struct FaceProp
{
    void ForwardToScriptLocals(int aiValue);
    void FUN_00887af0(AlignedRotation* apRot);
};

struct GeomData
{
    virtual void vz000();
    virtual void vz001();
    virtual void vz002();
    virtual void vz003();
    virtual void vz004();
    virtual void vz005();
    virtual void vz006();
    virtual void vz007();
    virtual void vz008();
    virtual void vz009();
    virtual void vz00a();
    virtual void vz00b();
    virtual void vz00c();
    virtual void vz00d();
    virtual void vz00e();
    virtual void vz00f();
    virtual void vz010();
    virtual void vz011();
    virtual void vz012();
    virtual void vz013();
    virtual void vz014();
    virtual void vz015();
    virtual void vz016();
    virtual void vz017();
    virtual void vz018();
    virtual void vz019();
    virtual void vz01a();
    virtual void vz01b();
    virtual void vz01c();
    virtual void vz01d();
    virtual void vz01e();
    virtual void vz01f();
    virtual void vz020();
    virtual void vz021();
    virtual void vz022();
    virtual void vz023();
    virtual void vz024();
    virtual int FUN_vt94();
    ListNode* FUN_007d6bb0();
    int FUN_00517630();
    void UpdateMatchingNodes(int aiValue);
    FormType FUN_0043b4f0();
    void FUN_00561580(int aiValue);
};

struct Geometry
{
    GeomData* FUN_006fa820();
};

struct FaceAnim
{
    void SetPairIfEnabled();
};

struct Actor;

extern ProfileMarker DAT_011df69e;
extern Clock DAT_011f6394;
extern ActorList DAT_011f2250;
extern Actor* DAT_011f21cc;
extern Actor* DAT_011dea3c;
extern NiPoint3 DAT_011f426c;
extern NiPoint3 DAT_011a9484;
extern CameraNode* DAT_011e07d4;
extern CameraNode* DAT_011e07d0;
extern int DAT_01267e64;
extern int DAT_012683ec;
extern const double DAT_01012060;
extern const double DAT_01021798;

float __cdecl FUN_007d1d00(int aiSetting);
LodManager* __cdecl FUN_00b4f5c0();
bool __cdecl FUN_00525420();
void __cdecl FUN_00c9b670(NiNode* apRoot, NiPoint3* apDir, int aiA, float afB, int aiC);
const char* __cdecl FUN_0087e9a0();
const char* __cdecl FUN_00887a00();
NiAVObject* __cdecl FUN_004ade00(NiNode* apRoot, const char* apName);
void* __cdecl FUN_00653270(int* apType, int aiObject);
bool __cdecl FUN_00c8cce0(int* apValue);
void __cdecl FUN_00c6a350(NiAVObject* apObject, int a, int b, int c, int d);
int __cdecl FUN_00621480(int aiValue);
void __cdecl FUN_00c804d0(NiNode* apRoot, int aiValue);
float __cdecl FUN_005b9e80(float afValue);
float __cdecl FUN_005c53d0(float afValue);
void __cdecl FUN_005330e0(float* apValue, float afMin, float afMax);
bool __cdecl FUN_008c7aa0();
FaceAnim* __stdcall FUN_004537b0(Actor* apActor, NiAVObject* apObject);
void __cdecl SetTlsValueAndReset(NiAVObject* apObject, int aiValue);
NiPoint3 __cdecl FUN_004a3760(float afScale, const NiPoint3& arPoint);

struct Actor
{
    virtual void va000();
    virtual void va001();
    virtual void va002();
    virtual void va003();
    virtual void va004();
    virtual void va005();
    virtual void va006();
    virtual void va007();
    virtual void va008();
    virtual void va009();
    virtual void va00a();
    virtual void va00b();
    virtual void va00c();
    virtual void va00d();
    virtual void va00e();
    virtual void va00f();
    virtual void va010();
    virtual void va011();
    virtual void FUN_vt48(int aiFlags);
    virtual void va013();
    virtual void va014();
    virtual void va015();
    virtual void va016();
    virtual void va017();
    virtual void va018();
    virtual void va019();
    virtual void va01a();
    virtual void va01b();
    virtual void va01c();
    virtual void va01d();
    virtual void va01e();
    virtual void va01f();
    virtual void va020();
    virtual void va021();
    virtual void va022();
    virtual void va023();
    virtual void va024();
    virtual void va025();
    virtual void va026();
    virtual void va027();
    virtual void va028();
    virtual void va029();
    virtual void va02a();
    virtual void va02b();
    virtual void va02c();
    virtual void va02d();
    virtual void va02e();
    virtual void va02f();
    virtual void va030();
    virtual void va031();
    virtual void va032();
    virtual void va033();
    virtual void va034();
    virtual void va035();
    virtual void va036();
    virtual void va037();
    virtual void va038();
    virtual void va039();
    virtual void va03a();
    virtual void va03b();
    virtual void va03c();
    virtual void va03d();
    virtual void va03e();
    virtual void va03f();
    virtual void va040();
    virtual void va041();
    virtual void va042();
    virtual void va043();
    virtual void va044();
    virtual void va045();
    virtual void va046();
    virtual void va047();
    virtual void va048();
    virtual void va049();
    virtual void va04a();
    virtual void va04b();
    virtual void va04c();
    virtual void va04d();
    virtual void va04e();
    virtual void va04f();
    virtual void va050();
    virtual void va051();
    virtual void va052();
    virtual void va053();
    virtual void va054();
    virtual void va055();
    virtual void va056();
    virtual void va057();
    virtual void va058();
    virtual void va059();
    virtual void va05a();
    virtual void va05b();
    virtual void va05c();
    virtual void va05d();
    virtual void va05e();
    virtual void va05f();
    virtual void va060();
    virtual void va061();
    virtual void va062();
    virtual void va063();
    virtual void va064();
    virtual void va065();
    virtual void va066();
    virtual void va067();
    virtual void va068();
    virtual void va069();
    virtual void va06a();
    virtual void va06b();
    virtual void va06c();
    virtual void va06d();
    virtual void va06e();
    virtual void va06f();
    virtual void va070();
    virtual void va071();
    virtual void va072();
    virtual void va073();
    virtual NiNode* FUN_vt1d0();
    virtual void va075();
    virtual void va076();
    virtual void va077();
    virtual void va078();
    virtual AnimController* FUN_vt1e4();
    virtual void va07a();
    virtual void va07b();
    virtual void va07c();
    virtual NiPoint3* FUN_vt1f4();
    virtual void va07e();
    virtual void va07f();
    virtual void va080();
    virtual void va081();
    virtual void va082();
    virtual void va083();
    virtual void va084();
    virtual void va085();
    virtual void va086();
    virtual void va087();
    virtual void va088();
    virtual void va089();
    virtual void va08a();
    virtual bool FUN_vt22c(int aiValue);
    virtual void va08c();
    virtual void va08d();
    virtual void va08e();
    virtual void va08f();
    virtual void va090();
    virtual void va091();
    virtual void va092();
    virtual void va093();
    virtual void FUN_vt250(float afDelta, NiPoint3* apPos, int aiValue);
    virtual void va095();
    virtual void va096();
    virtual void va097();
    virtual void va098();
    virtual void va099();
    virtual void va09a();
    virtual void va09b();
    virtual void va09c();
    virtual void va09d();
    virtual void va09e();
    virtual void va09f();
    virtual void va0a0();
    virtual void va0a1();
    virtual void va0a2();
    virtual void va0a3();
    virtual void va0a4();
    virtual void va0a5();
    virtual void va0a6();
    virtual void va0a7();
    virtual void FUN_vt2a0();
    virtual void va0a9();
    virtual void va0aa();
    virtual void va0ab();
    virtual void va0ac();
    virtual void va0ad();
    virtual void va0ae();
    virtual float FUN_vt2bc(int aiValue);
    virtual void va0b0();
    virtual void va0b1();
    virtual void va0b2();
    virtual void va0b3();
    virtual void va0b4();
    virtual void va0b5();
    virtual void va0b6();
    virtual void va0b7();
    virtual void va0b8();
    virtual void va0b9();
    virtual void va0ba();
    virtual void va0bb();
    virtual void va0bc();
    virtual void va0bd();
    virtual void va0be();
    virtual void va0bf();
    virtual void va0c0();
    virtual void va0c1();
    virtual void va0c2();
    virtual void va0c3();
    virtual void va0c4();
    virtual void va0c5();
    virtual void va0c6();
    virtual void va0c7();
    virtual void va0c8();
    virtual void va0c9();
    virtual void va0ca();
    virtual void va0cb();
    virtual void va0cc();
    virtual void va0cd();
    virtual void va0ce();
    virtual void va0cf();
    virtual void va0d0();
    virtual void va0d1();
    virtual void va0d2();
    virtual void va0d3();
    virtual void va0d4();
    virtual void va0d5();
    virtual void va0d6();
    virtual void va0d7();
    virtual void va0d8();
    virtual void va0d9();
    virtual void va0da();
    virtual void va0db();
    virtual void va0dc();
    virtual void va0dd();
    virtual void va0de();
    virtual void va0df();
    virtual void va0e0();
    virtual void va0e1();
    virtual void va0e2();
    virtual bool FUN_vt38c();
    virtual void va0e4();
    virtual void va0e5();
    virtual void va0e6();
    virtual void va0e7();
    virtual void va0e8();
    virtual void va0e9();
    virtual void va0ea();
    virtual void va0eb();
    virtual void va0ec();
    virtual void va0ed();
    virtual void va0ee();
    virtual void va0ef();
    virtual void va0f0();
    virtual void va0f1();
    virtual void va0f2();
    virtual void va0f3();
    virtual void va0f4();
    virtual void va0f5();
    virtual void va0f6();
    virtual void va0f7();
    virtual void va0f8();
    virtual void va0f9();
    virtual void va0fa();
    virtual void va0fb();
    virtual void va0fc();
    virtual void va0fd();
    virtual void va0fe();
    virtual void va0ff();
    virtual void va100();
    virtual void va101();
    virtual void va102();
    virtual void va103();
    virtual void va104();
    virtual void va105();
    virtual void va106();
    virtual void va107();
    virtual void va108();
    virtual void va109();
    virtual void va10a();
    virtual void va10b();
    virtual void va10c();
    virtual void va10d();
    virtual void va10e();
    virtual void va10f();
    virtual void va110();
    virtual void va111();
    virtual void va112();
    virtual void va113();
    virtual void va114();
    virtual void va115();
    virtual void va116();
    virtual void va117();
    virtual void va118();
    virtual void va119();
    virtual void va11a();
    virtual void va11b();
    virtual void va11c();
    virtual void va11d();
    virtual void va11e();
    virtual void va11f();
    virtual void va120();
    virtual void va121();
    virtual void va122();
    virtual void va123();
    virtual void va124();
    virtual void va125();
    virtual void va126();
    virtual void va127();
    virtual void va128();
    virtual void va129();
    virtual void va12a();
    virtual void va12b();
    virtual void va12c();
    virtual bool FUN_vt4b4();
    char pad04[0x20];
    float fScale24;
    char pad28[0x40];
    Process* pProcess;
    char pad6C[0x40];
    Havok* pHavok;
    Ragdoll* pRagdoll;
    char padB4[0x64];
    bool bResetPose;
    char pad119[0x77];
    Holder* pHolder;
    char pad194[4];

    int FUN_00931850();
    void UpdateFlag800State();
    bool PlaceAtPosition(NiPoint3* apPos);
    PathMover* FUN_008b70d0();
    LookTarget* FUN_008d6f30();
    bool FUN_0094df60();
    NiPoint3* FUN_00430830();
    void FUN_00575830(const NiPoint3& arPos);
    bool FUN_00493bb0();
    void UpdateControllerFlag();
    bool FUN_004eaf60();
    float FUN_008be940();
    NiPoint3* FUN_00436aa0();
    int FUN_0084e3a0();
    int FUN_008d8520();
    NiNode* FUN_0043fcd0();
    BaseForm* FUN_007af430();
    HandleRef FUN_00931ed0();
    void FUN_008a1800(int aiValue);
    void TryMakeTargetThing();
    bool FUN_0087eeb0();
    bool FUN_00437bd0();
    void FUN_00886cb0(float afDelta, int aiUnused);
};

// @fnv 0x00886cb0
void Actor::FUN_00886cb0(float afDelta, int aiUnused)
{
    DAT_011df69e.FUN_00483710();
    float fTimeSinceScaleStart = afDelta;
    if (fTimeSinceScaleStart == DAT_01012060 && !FUN_00931850())
    {
        if (DAT_011f2250.FUN_0044ddc0() == 4 && this == DAT_011f21cc)
            fTimeSinceScaleStart = DAT_011f6394.FUN_0084d030() * DAT_011f2250.FUN_009c8d60();
        else
            fTimeSinceScaleStart = DAT_011f6394.FUN_0084d030();
    }
    UpdateFlag800State();
    if (this != DAT_011dea3c)
    {
        NiPoint3 kTarget = DAT_011f426c;
        int iTargetFlags = 0;
        if (!FUN_vt4b4() && !PlaceAtPosition(&kTarget))
        {
            iTargetFlags = pHolder->FUN_vt20();
            if (!pHolder->FUN_vt24(&kTarget))
            {
                PathMover* pMover = FUN_008b70d0();
                if (pMover)
                    pMover->GetMovement(&kTarget, this, 0, 1);
            }
        }
        LookTarget* pLook = FUN_008d6f30();
        if (pLook && pLook->FUN_00450ff0() && !DAT_011dea3c->FUN_0094df60())
        {
            FUN_vt250(fTimeSinceScaleStart, &kTarget, iTargetFlags);
        }
        else
        {
            ThreeByThreeMatrix kRotate;
            kRotate.FUN_004a0c90(FUN_00430830()->z);
            FUN_00575830(FUN_vt1f4()->FUN_00439e90(kRotate.FUN_004b4500(kTarget)));
        }
    }
    if (FUN_00493bb0())
        UpdateControllerFlag();
    CombatController* pCombat = pProcess ? pProcess->FUN_vt28c() : 0;
    if (this != DAT_011dea3c)
    {
        NiNode* p3D = FUN_vt1d0();
        if (this != DAT_011dea3c && p3D)
        {
            NiPoint3 kCameraPos;
            if (DAT_011dea3c->FUN_004eaf60() && DAT_011e07d4)
                kCameraPos = *DAT_011e07d4->FUN_0045bb80();
            else if (DAT_011e07d0)
                kCameraPos = *DAT_011e07d0->FUN_0045bb80();
            else
                kCameraPos = DAT_011dea3c->FUN_00436aa0()->FUN_00439e90(
                    FUN_004a3760(DAT_011dea3c->FUN_008be940(), DAT_011a9484));
            NiBound kBound = *p3D->FUN_0043d450();
            float fDistance =
                kCameraPos.FUN_00439ef0(*kBound.FUN_006815c0()).FUN_00457990() - kBound.FUN_0084d030() * DAT_01021798;
            bool bFar = false;
            NiObject* pFade = p3D->FUN_vt10();
            if (pFade)
            {
                float fRatio = fDistance / FUN_007d1d00(3);
                bFar = fRatio > pFade->GetFloatAtOffsetB0();
            }
            LodManager* pLod = FUN_00b4f5c0();
            if (pLod && pLod->GetStringAtOffset13C())
            {
                bool bVisible = bFar ? false : fDistance > DAT_01012060;
                pLod->UpdateOrAddItem(FUN_0084e3a0(), &kBound, bVisible);
            }
            if (pCombat)
                pCombat->FUN_008879d0(bFar);
        }
    }
    if (pCombat)
        pCombat->FUN_00810610(FUN_00525420());
    if (bResetPose && FUN_008d8520())
    {
        NiNode* pRoot = FUN_0043fcd0();
        if (pRoot)
        {
            bool bUpright = true;
            Actor* pCreature = 0;
            if (FUN_007af430()->FUN_00401170() == 0x2b)
                pCreature = this;
            if (pCreature && !pCreature->FUN_vt38c())
                bUpright = false;
            if (pHavok && pHavok->FUN_00552490())
                pHavok->FUN_00c7c150(1);
            if (pRagdoll)
                pRagdoll->FUN_00ca2ad0(pRoot, FUN_00931ed0().FUN_004a3a20());
            FUN_008a1800(1);
            FUN_vt2a0();
            if (bUpright)
            {
                ThreeByThreeMatrix kHeading;
                kHeading.FUN_004a0c90(FUN_vt2bc(0));
                NiPoint3 kForward(0.0f, 1.0f, 0.0f);
                kForward = kHeading.FUN_004b4500(kForward);
                FUN_00c9b670(pRoot, &kForward, 1, 0.0f, 0);
                FUN_vt48(4);
                pProcess->FUN_vt28();
            }
            else
            {
                AnimController* pAnim = FUN_vt1e4();
                if (pAnim && pAnim->FUN_00494710(0xe0))
                {
                    pAnim->FUN_004955c0(0x14, 0xe0, -1, 0.0f, -1);
                    AnimSequence* pSequence = pAnim->FUN_00491040(1);
                    if (pSequence)
                    {
                        pSequence->FUN_0098adb0(pSequence->FUN_00508100());
                        pAnim->FUN_00491180(this, 0.0f, pSequence->FUN_00508100());
                        pAnim->FUN_00493900(this);
                    }
                    TryMakeTargetThing();
                }
            }
            bResetPose = false;
        }
    }
    if (FUN_0087eeb0() && !FUN_vt22c(0) && !FUN_00437bd0())
    {
        NiNode* pFaceRoot = FUN_vt1d0();
        NiAVObject* pObject = FUN_004ade00(pFaceRoot, FUN_0087e9a0());
        bool bChanged = false;
        if (pObject)
        {
            int iObject = pObject->FUN_006838b0();
            Geometry* m_pShaderGeometry = (Geometry*)FUN_00653270(&DAT_01267e64, pObject->FUN_006838b0());
            if (m_pShaderGeometry)
            {
                GeomData* pData = m_pShaderGeometry->FUN_006fa820();
                ListNode* pIter = pData->FUN_007d6bb0();
                int iSkin = pData->FUN_00517630();
                if (!FUN_00c8cce0(&iSkin))
                {
                    FUN_00c6a350(pObject, 1, 1, 1, 1);
                    int iNewSkin = FUN_00621480(pData->FUN_vt94());
                    pData->UpdateMatchingNodes(iNewSkin);
                    bChanged = true;
                }
                FormType kType = pData->FUN_0043b4f0();
                if (kType.FUN_0043b4d0() == 0x1d)
                    FUN_00c804d0(pFaceRoot, 8);
                pData->FUN_00561580(1);
                while (pIter && pIter->FUN_006815c0()->FUN_00559450())
                {
                    FaceProp* pFace =
                        (FaceProp*)FUN_00653270(&DAT_012683ec, (int)pIter->FUN_006815c0()->FUN_00559450());
                    if (pFace)
                    {
                        float fDesiredHeadingAngle = FUN_vt2bc(0);
                        AlignedRotation kRotationBasis(FUN_005c53d0(fDesiredHeadingAngle), FUN_005b9e80(fDesiredHeadingAngle), 0.0f, 0.0f);
                        pFace->ForwardToScriptLocals(1);
                        pFace->FUN_00887af0(&kRotationBasis);
                        break;
                    }
                    pIter = pIter->FUN_00726070();
                }
                if (FUN_008c7aa0())
                    FUN_004537b0(this, pObject)->SetPairIfEnabled();
                else
                    SetTlsValueAndReset(pObject, 2);
            }
        }
        pObject = FUN_004ade00(pFaceRoot, FUN_00887a00());
        if (pObject)
        {
            int iObject = pObject->FUN_006838b0();
            Geometry* m_pShaderGeometry = (Geometry*)FUN_00653270(&DAT_01267e64, pObject->FUN_006838b0());
            if (m_pShaderGeometry)
            {
                GeomData* pData = m_pShaderGeometry->FUN_006fa820();
                ListNode* pIter = pData->FUN_007d6bb0();
                int iSkin = pData->FUN_00517630();
                if (!FUN_00c8cce0(&iSkin))
                {
                    FUN_00c6a350(pObject, 1, 1, 1, 1);
                    int iNewSkin = FUN_00621480(pData->FUN_vt94());
                    pData->UpdateMatchingNodes(iNewSkin);
                    bChanged = true;
                }
                FormType kType = pData->FUN_0043b4f0();
                if (kType.FUN_0043b4d0() == 0x1d)
                    FUN_00c804d0(pFaceRoot, 8);
                pData->FUN_00561580(1);
                while (pIter && pIter->FUN_006815c0()->FUN_00559450())
                {
                    PropertyHolder* pProps = (PropertyHolder*)pIter->FUN_006815c0()->FUN_00559450();
                    ShaderProp* pShader = pProps->FUN_vt44();
                    if (pShader)
                    {
                        ShaderData* m_pSPData = pShader->FUN_00887a10();
                        float fScale = fScale24;
                        FUN_005330e0(&fScale, m_pSPData->FUN_00644a50(), m_pSPData->GetFloatAt0xC8());
                        pShader->FUN_00887a80(1);
                        pShader->FUN_00887ac0(fScale);
                        break;
                    }
                    pIter = pIter->FUN_00726070();
                }
                if (FUN_008c7aa0())
                    FUN_004537b0(this, pObject)->SetPairIfEnabled();
                else
                    SetTlsValueAndReset(pObject, 2);
            }
        }
        if (bChanged)
            FUN_vt48(4);
    }
    DAT_011df69e.FUN_00483710();
}

}

#include <string.h>
struct P164FormType
{
    int FUN_00401170();
};

extern const char DAT_0102fdc8[];
__if_not_exists(TESActorBase::TESActorBase)
{
    struct TESActorBase : TESForm
    {
    };
}
struct P164Flags
{
    unsigned int value;
    bool FUN_004280f0(unsigned int);
};
struct P164Buffer
{
    virtual unsigned char GetVersion();
    void FUN_00864980(void*, unsigned int);
    void FUN_008648e0(void*);
    unsigned int FUN_008648a0();
    unsigned int FUN_00864a60();
    P164Flags FUN_00428110();
};
struct P164Item
{
    TESForm* FUN_0044ddc0();
    ~P164Item();
};
struct P164Inventory
{
    P164Item* FUN_004c8c10(unsigned int, int);
};
P164Inventory* __cdecl FUN_004bf220(TESObjectREFR*);
TESForm* __cdecl LookupFormByID(unsigned int);
struct P164Modifier
{
    void LoadModifiers(P164Buffer*);
};
struct ActorListEntry
{
    float value;
    TESForm* form;
};
struct P164List
{
    void FUN_005ae3d0(ActorListEntry*&);
};
struct P164Clock
{
    float FUN_0096d490();
};
extern P164Clock DAT_011e0e80;
struct P164Biped
{
    TESForm* FUN_0088e0f0(int);
};
struct P164State
{
    int FUN_004f8960();
};
struct P164Actor : Actor
{
    void FUN_008ab3a0(P164Buffer*);
    void FUN_00932a00(P164Buffer*);
    void FUN_00884f80();
    void FUN_008c1ac0(bool);
    void SetFlag40000000(bool);
    bool FUN_00566950();
    const char* FUN_0055d520();
};
struct P164ActorVirtual
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
    virtual P164Biped* GetBipedAnimation();
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
    virtual bool IsCharacter();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool IsDead(int);
};
struct P164Mover
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
    virtual void Load(P164Buffer*);
};
struct P164Process
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
    virtual P164Item* GetLoadedForm();
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
    virtual void Update(bool);
};
// @fnv 0x008ab3a0
void P164Actor::FUN_008ab3a0(P164Buffer* buffer)
{
    int oldState = ((P164State*)this)->FUN_004f8960();
    FUN_00932a00(buffer);
    m_eLifeState = (ACTOR_LIFE_STATE)oldState;
    FUN_00884f80();
    buffer->FUN_00864980(&ActorConditionAndAnimationState, 4);
    ActorConditionAndAnimationState = DAT_011e0e80.FUN_0096d490() - ActorConditionAndAnimationState;
    buffer->FUN_00864980(&ActorStateFlags, 1);
    buffer->FUN_00864980(&ActorReferenceData, 1);
    buffer->FUN_00864980(&m_bFirstActorFlag, 1);
    buffer->FUN_00864980(&m_bActorFlag, 1);
    buffer->FUN_00864980(&m_fFirstValueAfterFlag, 4);
    buffer->FUN_00864980(&m_bSecondBooleanValue, 1);
    buffer->FUN_00864980(&m_eAnimationGroup, 4);
    buffer->FUN_00864980(&m_bHasUpdated, 1);
    buffer->FUN_00864980(&ActorReferenceListData, 1);
    buffer->FUN_00864980(&ActorBaseConfiguration, 1);
    buffer->FUN_00864980(&m_bFlagBeforeActorBase, 1);
    buffer->FUN_00864980(&ActorBaseReference, 1);
    buffer->FUN_00864980(&m_bSecondActorFlag, 1);
    buffer->FUN_00864980(&m_iIntegerBeforeTwoFloatValues, 4);
    buffer->FUN_00864980(&BooleanIntegerTwoFloatData, 4);
    buffer->FUN_00864980(&IntegerFloatFlagSettings, 4);
    buffer->FUN_00864980(&m_bFirstFlagAfterForm, 1);
    buffer->FUN_00864980(&m_bFormFlag, 1);
    buffer->FUN_00864980(&m_bMiddleFlagBeforeActorMover, 1);
    buffer->FUN_00864980(&m_iPackageState, 4);
    buffer->FUN_00864980(&ActorProjectileState, 4);
    buffer->FUN_00864980(&m_bFlagBeforeTwoBooleans, 1);
    buffer->FUN_00864980(&m_bMiddleFlag, 1);
    if (buffer->GetVersion() >= 8)
        buffer->FUN_00864980(&m_eCriticalStage, 4);
    if (buffer->GetVersion() >= 9)
    {
        buffer->FUN_00864980(&m_bActorListValid, 1);
        buffer->FUN_00864980(&m_iIntegerAfterActorListValid, 4);
        buffer->FUN_00864980(&ActorStatusData, 1);
        buffer->FUN_00864980(&m_uiFirstValueAfterInteger, 4);
        buffer->FUN_00864980(&m_uiActorFlags, 4);
        FUN_008c1ac0(false);
        SetFlag40000000(false);
    }
    if (buffer->GetVersion() >= 13)
        buffer->FUN_00864980(&m_uiValueBeforeBooleanFields, 4);
    buffer->FUN_008648e0(&m_pActorReference);
    m_pActorBase = dynamic_cast<TESActorBase*>(LookupFormByID(buffer->FUN_008648a0()));
    buffer->FUN_008648e0(&m_pMobileObject);
    if (buffer->FUN_00428110().FUN_004280f0(0x400))
    {
        unsigned char lifeState = 0;
        buffer->FUN_00864980(&lifeState, 1);
        m_eLifeState = (ACTOR_LIFE_STATE)lifeState;
    }
    if (buffer->FUN_00428110().FUN_004280f0(0x80000))
    {
        unsigned int count = buffer->FUN_00864a60();
        for (unsigned int i = 0; i < count; ++i)
        {
            ActorListEntry* modifier = new ActorListEntry;
            buffer->FUN_008648e0(&modifier->form);
            buffer->FUN_00864980(modifier, 4);
            ((P164List*)&m_kSecondPointerList)->FUN_005ae3d0(modifier);
        }
    }
    if (buffer->FUN_00428110().FUN_004280f0(0x800000))
        ((P164Modifier*)&m_kFirstActorData)->LoadModifiers(buffer);
    if (buffer->FUN_00428110().FUN_004280f0(0x400000))
        ((P164Modifier*)&m_kSecondActorData)->LoadModifiers(buffer);
    ((P164Mover*)m_pActorMover)->Load(buffer);
    if (Get3DSimple() && m_pBaseProcess)
    {
        P164Biped* inventory = ((P164ActorVirtual*)this)->GetBipedAnimation();
        P164Inventory* biped = FUN_004bf220(this);
        if (inventory && biped)
        {
            unsigned int slots[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
            unsigned int slotCount = 19;
            for (unsigned int slot = 0; slot < slotCount; ++slot)
            {
                TESForm* current = inventory->FUN_0088e0f0(slot);
                P164Item* item = biped->FUN_004c8c10(slot, 0);
                TESForm* equipped = item ? item->FUN_0044ddc0() : 0;
                if (current)
                {
                    if (((P164FormType*)current)->FUN_00401170() == 12)
                        current = 0;
                    else if (current->Unk_3D())
                        current = 0;
                }
                if (current != equipped)
                {
                    ((P164Process*)m_pBaseProcess)->Update(true);
                    break;
                }
                delete item;
            }
        }
        else if (biped && ((P164ActorVirtual*)this)->IsCharacter() && FUN_00566950() &&
                 strstr(FUN_0055d520(), DAT_0102fdc8))
        {
            P164Item* weapon = biped->FUN_004c8c10(5, 0);
            TESForm* weaponForm = weapon ? weapon->FUN_0044ddc0() : 0;
            if (((P164Process*)m_pBaseProcess)->GetLoadedForm() &&
                ((P164Process*)m_pBaseProcess)->GetLoadedForm()->FUN_0044ddc0() != weaponForm)
                ((P164Process*)m_pBaseProcess)->Update(true);
        }
    }
    if (!((P164ActorVirtual*)this)->IsDead(0) && m_eCriticalStage != 0)
        m_eCriticalStage = (ACTOR_CRITICAL_STAGE)0;
}
