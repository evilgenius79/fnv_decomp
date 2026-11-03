
// tesnpc_ctx_variant.cpp: context variant of src/fallout_shared/tesnpc.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "tesnpc_pc_decls.h"

class Helper009f8770
{
  public:
    void FUN_00484d00(void* apDst, int aiSize);
};
class FUN_00484d40_Host
{
  public:
    void FUN_00484d40(unsigned int* apFormID, int aiSize);
};
class FUN_004ac110_shell
{
  public:
    TESRace* FUN_004ac110();
};
class FUN_009611e0_shell
{
  public:
    int FUN_009611e0();
};
class FUN_006141f0_shell
{
  public:
    void BuildAppearance(TESActorBase* apBase, void* apData, SEX aeSex, bool abFlag);
};
class FUN_008b70d0_shell
{
  public:
    Animation* FUN_008b70d0();
};
class FUN_004eaf60_shell
{
  public:
    bool FUN_004eaf60();
};
class FUN_0043c610_shell
{
  public:
    void RunVirtualMethod28();
};
class ActorView
{
  public:
    TESActorBase* GetActorBase();
};
class GlobalObject_0040c150
{
  public:
    const char* FUN_00403df0();
};
extern GlobalObject_0040c150 g_011d2b38, g_011d2718, g_011d3e44;
extern bool DAT_011c5cb4;
int __fastcall FUN_005d9f90(char* apRef);
TESForm* LookupFormByID(unsigned int auiFormID);
void FNV_Warning(const char* apFormat, ...);
void __cdecl FUN_00a6e8e0(NiNode* apNode, NiControllerManager* apManager);
void __cdecl ApplyFaceGenTextures(NiNode* apNode, void* apData);
class ActorFace
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
    virtual NiNode* GetHeadRootNode(bool);
    virtual NiNode* GetFaceRootNode(bool);
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void UpdateHead();
};
class NodeFace
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
    virtual void InsertChild(NiAVObject*);
};
class ModelFace
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void SetModelFilePath(const char*);
};
class NPCModelView
{
  public:
    int pad[0xdc / 4];
    ModelFace kModel;
};
class FaceRefr
{
  public:
    void Set3D(NiNode* apNode, bool abQueue);
    NiNode* FUN_0087e060(bool abFlag);
};
class PlayerFace
{
  public:
    void ToggleFirstPerson(bool abFlag);
    void FUN_0094eaf0(NiNode* apNode, bool abFlag);
};
class NPCFace
{
  public:
    void FUN_005dd560();
    void FUN_00606820(Actor* apActor, int aiValue);
};
class FUN_005dd590
{
  public:
    int data[0x3c];
    FUN_005dd590();
    ~FUN_005dd590();
};
class FaceGenPaletteEntry
{
  public:
    int data[0xe];
    ~FaceGenPaletteEntry();
};
class QHeadLocal : public FaceGenPaletteEntry
{
  public:
    QHeadLocal(TESNPC* apNPC, int aiFlag);
    void FUN_0043ecb0();
    void FUN_0043ed90(Actor* apActor, int aiValue);
};
class MiddleHighProcess : public BaseProcess
{
};
class TESNPCFace : public TESNPC
{
  public:
    void FUN_00609f60(Actor* apActor);
};

// @fnv 0x00609f60
void TESNPCFace::FUN_00609f60(Actor* apActor)
{
    bool bChanged = false;
    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 2; j++)
        {
            unsigned int uiNumRows = m_kFaceGenCoordinates[i][j].FUN_009611e0();
            unsigned int uiNumCols = m_kFaceGenCoordinates[i][j].FUN_00441110();
            for (unsigned int r = 0; r < uiNumRows; r++)
            {
                for (unsigned int c = 0; c < uiNumCols; c++)
                {
                    float fValue;
                    ((Helper009f8770*)this)->FUN_00484d00(&fValue, 4);
                    if (*m_kFaceGenCoordinates[i][j].FUN_0060b370(r, c).FUN_00629ab0() != fValue)
                    {
                        *(float*)m_kFaceGenCoordinates[i][j].FUN_0060b370(r, c).FUN_00629ab0() = fValue;
                        bChanged = true;
                    }
                }
            }
        }
    }
    bool bPrevHadRace = false;
    if (((FUN_004ac110_shell*)this)->FUN_004ac110())
        bPrevHadRace = false;
    else
        FNV_Warning("MODELS: %s has a bad current race when loading facegen", TESFullName::GetFullName());
    unsigned int uiNewRace;
    ((FUN_00484d40_Host*)this)->FUN_00484d40(&uiNewRace, 4);
    TESRace* pRace = dynamic_cast<TESRace*>(LookupFormByID(uiNewRace));
    if (uiNewRace && !pRace)
        FNV_Warning("MODELS: NPC %s could not find race %08X", TESFullName::GetFullName(), uiNewRace);
    if (GetFormRace() != pRace)
        bChanged = true;
    SetFormRace(pRace);
    bool bNowHasRace = false;
    if (((FUN_004ac110_shell*)this)->FUN_004ac110())
        bNowHasRace = false;
    else
        FNV_Warning("MODELS: %s has a bad new race when loading facegen", TESFullName::GetFullName());
    unsigned int uiNewHairFormID;
    ((FUN_00484d40_Host*)this)->FUN_00484d40(&uiNewHairFormID, 4);
    TESHair* pReadHair = dynamic_cast<TESHair*>(LookupFormByID(uiNewHairFormID));
    if (uiNewHairFormID && !pReadHair)
        FNV_Warning("MODELS: NPC %s could not find hair %08X", TESFullName::GetFullName(), uiNewHairFormID);
    if (m_pHair != pReadHair)
        bChanged = true;
    m_pHair = pReadHair;
    unsigned int uiEyes;
    ((FUN_00484d40_Host*)this)->FUN_00484d40(&uiEyes, 4);
    TESEyes* pCurEyeForm = dynamic_cast<TESEyes*>(LookupFormByID(uiEyes));
    if (uiEyes && !pCurEyeForm)
        FNV_Warning("MODELS: NPC %s could not find eyes %08X", TESFullName::GetFullName(), uiEyes);
    if (m_pEyes != pCurEyeForm)
        bChanged = true;
    m_pEyes = pCurEyeForm;
    float fScaleMultiplier;
    ((Helper009f8770*)this)->FUN_00484d00(&fScaleMultiplier, 4);
    unsigned int uiCurHairColor;
    ((Helper009f8770*)this)->FUN_00484d00(&uiCurHairColor, 4);
    if (m_fHairLength != fScaleMultiplier || iHairColor != uiCurHairColor)
        bChanged = true;
    m_fHairLength = fScaleMultiplier;
    iHairColor = uiCurHairColor;
    bool bLoadedFemale;
    ((Helper009f8770*)this)->FUN_00484d00(&bLoadedFemale, 1);
    if (TESActorBaseData::GetFlag(1) != bLoadedFemale)
        bChanged = true;
    TESActorBaseData::UpdateFlagBit(1, bLoadedFemale, true);
    if (bChanged)
    {
        NiAVObject* p3D = apActor->Get3DSimple();
        NiNode* pNode = 0;
        if (p3D)
            pNode = p3D->IsSceneNode();
        if (bPrevHadRace == bNowHasRace)
        {
            if (pNode)
            {
                NiControllerManager* pAnimManager = 0;
                if (((FUN_008b70d0_shell*)apActor)->FUN_008b70d0() &&
                    ((ActorAnimData*)((FUN_008b70d0_shell*)apActor)->FUN_008b70d0())->FUN_00496940())
                    pAnimManager = ((ActorAnimData*)((FUN_008b70d0_shell*)apActor)->FUN_008b70d0())
                                       ->FUN_00496940()
                                       ->GetStringAtOffset();
                NiControllerManager* pkManager = pAnimManager;
                NiNode* pFace = ((ActorFace*)apActor)->GetFaceRootNode(false);
                if (pFace && ((FUN_009611e0_shell*)pFace)->FUN_009611e0())
                {
                    FUN_00a6e8e0(pFace, pkManager);
                    ((NodeFace*)((FUN_009611e0_shell*)pFace)->FUN_009611e0())->InsertChild(pFace);
                }
                pFace = ((ActorFace*)apActor)->GetHeadRootNode(false);
                if (pFace && ((FUN_009611e0_shell*)pFace)->FUN_009611e0())
                {
                    FUN_00a6e8e0(pFace, pkManager);
                    ((NodeFace*)((FUN_009611e0_shell*)pFace)->FUN_009611e0())->InsertChild(pFace);
                }
            }
            ((NPCFace*)this)->FUN_005dd560();
            if (FUN_005d9f90((char*)apActor))
                ((NPCFace*)this)->FUN_00606820(apActor, FUN_005d9f90((char*)apActor));
            if (((ActorFace*)apActor)->GetHeadRootNode(false) && ((ActorFace*)apActor)->GetFaceRootNode(false))
            {
                FUN_005dd590 kData;
                ((FUN_006141f0_shell*)GetFormRace())->BuildAppearance(this, &kData, MALE, false);
                ApplyFaceGenTextures(((ActorFace*)apActor)->GetHeadRootNode(false), &kData);
                ApplyFaceGenTextures(((ActorFace*)apActor)->GetFaceRootNode(false), &kData);
            }
        }
        else
        {
            NiNode* pParent = 0;
            ((NPCFace*)this)->FUN_005dd560();
            bool bWasFirstPerson = ((FUN_004eaf60_shell*)g_thePlayer)->FUN_004eaf60();
            ((PlayerFace*)g_thePlayer)->ToggleFirstPerson(false);
            if (pNode && bPrevHadRace != bNowHasRace)
            {
                pParent = (NiNode*)((FUN_009611e0_shell*)apActor->Get3DSimple())->FUN_009611e0();
                ((FaceRefr*)apActor)->Set3D(0, true);
            }
            if (bNowHasRace)
                ((NPCModelView*)this)->kModel.SetModelFilePath(g_011d2b38.FUN_00403df0());
            else if (GetSex() == FEMALE)
                ((NPCModelView*)this)->kModel.SetModelFilePath(g_011d2718.FUN_00403df0());
            else
                ((NPCModelView*)this)->kModel.SetModelFilePath(g_011d3e44.FUN_00403df0());
            if (pParent)
            {
                DAT_011c5cb4 = true;
                NiNode* pNew3D = ((FaceRefr*)apActor)->FUN_0087e060(false);
                if (!((ActorFace*)apActor)->GetFaceRootNode(false) && !((ActorFace*)apActor)->GetHeadRootNode(false))
                {
                    TESNPC* m_pActorBaseFormItem = (TESNPC*)((ActorView*)apActor)->GetActorBase();
                    QHeadLocal kHead(m_pActorBaseFormItem, 0);
                    kHead.FUN_0043ecb0();
                    ((FUN_0043c610_shell*)&kHead)->RunVirtualMethod28();
                    kHead.FUN_0043ed90(apActor, FUN_005d9f90((char*)apActor));
                }
                pParent->AttachChildInAvailableSlot(pNew3D, true);
                DAT_011c5cb4 = false;
                if (apActor == g_thePlayer)
                    ((PlayerFace*)g_thePlayer)->FUN_0094eaf0(pNew3D, false);
                ((ActorFace*)apActor)->UpdateHead();
                MiddleHighProcess* pProcess = dynamic_cast<MiddleHighProcess*>(apActor->GetProcess());
                if (pProcess)
                    pProcess->ApplyProcessLevelChange(apActor);
            }
            ((PlayerFace*)g_thePlayer)->ToggleFirstPerson(!bWasFirstPerson);
        }
    }
}

struct ElemT;
struct ObjX;
struct NiTimeController
{
    virtual void z00();
    virtual void z01();
    virtual void z02();
    virtual void z03();
    virtual void z04();
    virtual void z05();
    virtual void z06();
    virtual void z07();
    virtual void z08();
    virtual void z09();
    virtual void z10();
    virtual void z11();
    virtual void z12();
    virtual void z13();
    virtual void z14();
    virtual void z15();
    virtual void z16();
    virtual void z17();
    virtual void z18();
    virtual void z19();
    virtual void z20();
    virtual void z21();
    virtual void z22();
    virtual void z23();
    virtual void z24();
    virtual void z25();
    virtual void z26();
    virtual void z27();
    virtual void z28();
    virtual void z29();
    virtual void z30();
    virtual void z31();
    virtual void z32();
    virtual void z33();
    virtual void z34();
    virtual void z35();
    virtual void z36();
    virtual void z37();
    virtual void z38();
    virtual void z39();
    virtual void z40();
    virtual void z41();
    virtual void z42();
    virtual void z43();
    virtual void z44();
    virtual void z45();
    virtual void z46();
    virtual void z47();
    virtual void z48();
    virtual void z49();
    virtual void z50();
    virtual void z51();
    virtual void z52();
    virtual void z53();
    virtual void z54();
    virtual void z55();
    virtual void z56();
    virtual void z57();
    virtual void z58();
    virtual void z59();
    virtual void z60();
    virtual void z61();
    virtual void z62();
    virtual void v63(int, void*);
    unsigned int FUN_00441110();
};
struct NiFixedString
{
    NiFixedString(const char*);
    ~NiFixedString();
    operator const char*() const;
    int f0;
};
struct ElemRet;
struct ListT
{
    virtual void y00();
    virtual void y01();
    virtual void y02();
    virtual void y03();
    virtual void y04();
    virtual void y05();
    virtual void y06();
    virtual void y07();
    virtual void y08();
    virtual void y09();
    virtual void y10();
    virtual void y11();
    virtual void y12();
    virtual void y13();
    virtual void y14();
    virtual void y15();
    virtual void y16();
    virtual void y17();
    virtual void y18();
    virtual void y19();
    virtual void y20();
    virtual void y21();
    virtual void y22();
    virtual void y23();
    virtual void y24();
    virtual void y25();
    virtual void y26();
    virtual void y27();
    virtual void y28();
    virtual void y29();
    virtual void y30();
    virtual void y31();
    virtual void y32();
    virtual void y33();
    virtual void y34();
    virtual void y35();
    virtual void y36();
    virtual void y37();
    virtual void y38();
    virtual ElemT* v39(const NiFixedString&);
    unsigned int FUN_0043b480();
    ElemT* FUN_0043b4a0(unsigned int);
    NiObjectNET* FUN_0050d100();
    int FUN_00a59d30(int);
    void FUN_00a5b230(int);
    void FUN_00439410(void*);
};
struct PartT;
struct ElemT
{
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual PartT* v7();
    NiFixedString& GetName();
};
struct NiObjectNET
{
    NiTimeController* GetControllers() const;
};
struct FUN_00633c90
{
    FUN_00633c90(int);
    ~FUN_00633c90();
    ListT* FUN_00559450();
    void FUN_0066b0d0(PartT*);
    int f0;
};
struct FUN_004037b0
{
    FUN_004037b0();
    ~FUN_004037b0();
    void* FUN_00559450();
    int f0;
    int f4;
};
struct NiMemObject
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct FUN_00a6aa40 : NiMemObject
{
    FUN_00a6aa40();
    void FUN_005b8fc0(void*);
    void FUN_004f3200(int);
    void FUN_0060aeb0(int);
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
};
struct MgrT
{
    void FUN_004568c0(void*, FUN_00633c90*, int, int);
};
extern MgrT* DAT_011dea10;
extern char DAT_0104aac0;
extern char DAT_0104aab0;
extern char DAT_0104aa80;
extern char DAT_0104a64c;
int __cdecl FUN_00408b20(char const*, char const*);
void __cdecl FUN_00406f60(void*, const char*, ...);
void __cdecl FUN_00b57e30(void*, int, int);
struct ParamSub
{
    const char* FUN_00408da0();
};
struct ParamT
{
    char pad24[0x24];
    ParamSub sub;
};
struct ThisT
{
    char pad1c4[0x1c4];
    FUN_00633c90 holder;
    void FUN_0060a950(ParamT*);
};
// @fnv 0x0060a950
void ThisT::FUN_0060a950(ParamT* param)
{
    FUN_00633c90 a(0);
    FUN_00633c90 eye(0);
    ElemT* cur;
    if (holder.FUN_00559450())
    {
        long count;
        count = holder.FUN_00559450()->FUN_0043b480();
        unsigned int ptr;
        for (ptr = 0; ptr < count; ptr++)
        {
            cur = holder.FUN_00559450()->FUN_0043b4a0(ptr);
            if (FUN_00408b20((const char*)cur->GetName(), &DAT_0104aac0) == 0)
                a.FUN_0066b0d0(cur->v7());
            if (FUN_00408b20((const char*)cur->GetName(), &DAT_0104aab0) == 0)
                eye.FUN_0066b0d0(cur->v7());
        }
        if (a.FUN_00559450() && eye.FUN_00559450())
        {
            FUN_004037b0 p40;
            if (param)
                FUN_00406f60(&p40, &DAT_0104a64c, param->sub.FUN_00408da0());
            else
                FUN_00406f60(&p40, &DAT_0104aa80);
            FUN_00633c90 c(0);
            DAT_011dea10->FUN_004568c0(p40.FUN_00559450(), &c, 0, 0);
            if (c.FUN_00559450())
            {
                NiObjectNET* x;
                x = a.FUN_00559450()->FUN_0050d100();
                NiObjectNET* x2;
                x2 = eye.FUN_00559450()->FUN_0050d100();
                if (x && x2)
                {
                    NiTimeController* b3;
                    b3 = x->GetControllers();
                    (!b3 ? 0 : ((int)b3->FUN_00441110() >= 8 && (int)b3->FUN_00441110() <= 12));
                    NiTimeController* nw;
                    nw = (!b3 ? 0 : ((int)b3->FUN_00441110() >= 8 && (int)b3->FUN_00441110() <= 12)) ? b3 : 0;
                    NiTimeController* m40;
                    m40 = x2->GetControllers();
                    NiTimeController* found;
                    found = (!m40 ? 0 : ((int)m40->FUN_00441110() >= 8 && (int)m40->FUN_00441110() <= 12)) ? m40 : 0;
                    if (nw && found)
                    {
                        nw->v63(0, c.FUN_00559450());
                        found->v63(0, c.FUN_00559450());
                        return;
                    }
                }
                FUN_00a6aa40* p44;
                p44 = new FUN_00a6aa40;
                p44->FUN_005b8fc0(c.FUN_00559450());
                p44->FUN_004f3200(3);
                p44->FUN_0060aeb0(2);
                if (a.FUN_00559450()->FUN_00a59d30(5))
                    a.FUN_00559450()->FUN_00a5b230(5);
                a.FUN_00559450()->FUN_00439410(p44);
                if (eye.FUN_00559450()->FUN_00a59d30(5))
                    eye.FUN_00559450()->FUN_00a5b230(5);
                eye.FUN_00559450()->FUN_00439410(p44);
            }
        }
        cur = holder.FUN_00559450()->v39(NiFixedString(&DAT_0104aac0));
        if (cur)
            FUN_00b57e30(cur, 0, 0);
        cur = holder.FUN_00559450()->v39(NiFixedString(&DAT_0104aab0));
        if (cur)
            FUN_00b57e30(cur, 0, 0);
    }
}
