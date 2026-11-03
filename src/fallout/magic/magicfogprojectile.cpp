
// src/fallout/magic/magicfogprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/magicfogprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct MagicFogProjectile
{
    void FUN_008196e0();
    void* DestroyIfFlagged(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_008196e0, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00819330
void* MagicFogProjectile::DestroyIfFlagged(unsigned int flags)
{
    FUN_008196e0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct RefH
{
    bool IsDeleted() const;
};
struct FUN_0081a920_shell : public RefH
{
    bool FUN_0081a920();
};
// Returns true when the int at offset 0xb4 is not 1 and the object is not deleted.
// @fnv 0x0081a920
bool FUN_0081a920_shell::FUN_0081a920()
{
    return *(int*)((char*)this + 0xb4) != 1 && !IsDeleted();
}

namespace fnv_0081ad00 {
struct TESSaveLoadGame
{
    unsigned char FUN_008df040();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct MagicFogProjectile
{
    unsigned short GetSaveRecordSize(unsigned int);
    unsigned short FUN_0081ad00(unsigned int flags);
};
// @fnv 0x0081ad00
unsigned short MagicFogProjectile::FUN_0081ad00(unsigned int flags)
{
    struct VirtualInterface
    {
        VirtualInterface* next;
    };
    unsigned short isize = 0;
    isize += GetSaveRecordSize(flags);
    isize += 4;
    isize += 4;
    isize += 4;
    isize += 4;
    isize += 4;
    if (*(int*)((char*)this + 0xb4) == 1)
        isize += 4;
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x71)
    {
        isize += 4;
        isize += 2;
        VirtualInterface* pNode = *(VirtualInterface**)((char*)this + 0xc8);
        while (pNode)
        {
            isize += 4;
            isize += 1;
            pNode = *(VirtualInterface**)((char*)pNode + 8);
        }
    }
    return isize;
}
}  // namespace fnv_0081ad00

namespace fnv_00818ba0 {
extern double _gModifierZero;
struct MagicFogProjectile
{
    unsigned char _pad[20];
    float _m14;
    bool IsAboveZero();
};
// Returns true when _m14 is greater than _gModifierZero.
// @fnv 0x00818ba0
bool MagicFogProjectile::IsAboveZero()
{
    return _m14 > _gModifierZero;
}
}  // namespace fnv_00818ba0

namespace fnv_00819830 {
struct MagicFogProjectile
{
    char _pad[0xC8];
    struct VirtualInterface
    {
        char _pad2[8];
        VirtualInterface* next;
    }* pActiveTargetList;
    void DeleteAllNodes();
};
// @fnv 0x00819830
void MagicFogProjectile::DeleteAllNodes()
{
    VirtualInterface* pNode;
    while (pActiveTargetList)
    {
        pNode = pActiveTargetList;
        pActiveTargetList = pActiveTargetList->next;
        delete pNode;
    }
    pActiveTargetList = 0;
}
}  // namespace fnv_00819830

struct FUN_0081eb50_shell
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
    virtual void v49(int);
    char _pad[0x90];
    int m94;
    bool ClearIfMatches(int);
};
// If a equals m94, resets m94 to 0, calls v49(1), and returns true; otherwise returns false.
// @fnv 0x0081eb50
bool FUN_0081eb50_shell::ClearIfMatches(int aiValue)
{
    bool r = false;
    if (aiValue == m94)
    {
        m94 = 0;
        r = true;
        v49(1);
    }
    return r;
}

struct Setting
{
    float* FUN_00403e20();
};
extern Setting DAT_011d1890, DAT_011d1bd4, DAT_011d19f0;
struct RTTI
{
};
extern RTTI DAT_012024e0, DAT_01202550, DAT_01202540;
struct Object
{
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void* AsNode();
};
bool FUN_0043b300(const RTTI*, Object*);
void* FUN_00653270(const RTTI*, Object*);
struct Emitter
{
    float FUN_00759450();
    void FUN_00819a70(float);
};
struct Controller
{
    float FUN_00639aa0();
    void FUN_0098adb0(float);
    float FUN_004a7bd0();
    void FUN_00819a50(float);
    float FUN_00792760();
    void FUN_00444020(float);
};
struct Particle : Object
{
    unsigned FUN_004d7d50();
    Object* GetByIndex(unsigned);
};
struct Node : Object
{
    unsigned FUN_0043b480();
    Object* FUN_0043b4a0(unsigned);
};
struct Effect
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    float sizeScale, speedScale;
    void ScaleEffect(Object*);
};
// Scales the effect's size and speed settings and applies the scaled values to each particle's emitter and controller, recursing into child nodes.
// @fnv 0x00819890
void Effect::ScaleEffect(Object* object)
{
    float fSpeedFactor;
    {
        float fSpeedFactor2;
        {
            float fSizeFactor = sizeScale * *DAT_011d1890.FUN_00403e20();
            fSpeedFactor = speedScale * *DAT_011d1bd4.FUN_00403e20();
            fSpeedFactor2 = speedScale * *DAT_011d19f0.FUN_00403e20();
            if (FUN_0043b300(&DAT_012024e0, object))
            {
                Particle* particle = (Particle*)object;
                for (unsigned i = 0; i < particle->FUN_004d7d50(); ++i)
                {
                    Controller* controller;
                    {
                        Emitter* emitter;
                        {
                            Object* entry = particle->GetByIndex(i);
                            emitter = (Emitter*)FUN_00653270(&DAT_01202550, entry);
                            if (emitter)
                                emitter->FUN_00819a70(emitter->FUN_00759450() * fSizeFactor);
                            controller = (Controller*)FUN_00653270(&DAT_01202540, entry);
                            if (controller)
                            {
                                controller->FUN_0098adb0(controller->FUN_00639aa0() * fSizeFactor);
                                controller->FUN_00819a50(controller->FUN_004a7bd0() * fSpeedFactor2);
                                controller->FUN_00444020(controller->FUN_00792760() * fSpeedFactor);
                            }
                        }
                    }
                }
            }
            else if (object && object->AsNode())
            {
                Node* node = (Node*)object;
                for (unsigned i = 0; i < node->FUN_0043b480(); ++i)
                {
                    Object* child = node->FUN_0043b4a0(i);
                    ScaleEffect(child);
                }
            }
        }
    }
}

void* __cdecl operator new(unsigned int);
struct Form
{
};
struct FUN_0081aa80
{
    Form* form;
    unsigned char flags;
    FUN_0081aa80* next;
    FUN_0081aa80(Form*, unsigned char, FUN_0081aa80*);
};
struct SaveManager
{
    void FUN_008579e0(void*, unsigned);
    unsigned char FUN_008df040();
};
extern SaveManager* DAT_011de45c;
void* __cdecl FUN_00401460(void*, const void*, unsigned);
struct Projectile
{
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19();
    virtual void method20();
    virtual void method21();
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void method25();
    virtual void method26();
    virtual void method27();
    virtual void method28();
    virtual void method29();
    virtual void method30();
    virtual void method31();
    virtual void method32();
    virtual void method33();
    virtual void method34();
    virtual void method35();
    virtual void method36();
    virtual void method37();
    virtual void method38();
    virtual void method39();
    virtual void method40();
    virtual void method41();
    virtual void method42();
    virtual void method43();
    virtual void method44();
    virtual void method45();
    virtual void method46();
    virtual void method47();
    virtual void method48();
    virtual void method49();
    virtual void method50();
    virtual void method51();
    virtual void method52();
    virtual void method53();
    virtual void method54();
    virtual void method55();
    virtual void method56();
    virtual void method57();
    virtual void method58();
    virtual void method59();
    virtual void method60();
    virtual void method61();
    virtual void method62();
    virtual void method63();
    virtual void method64();
    virtual void method65();
    virtual void method66();
    virtual void method67();
    virtual void method68();
    virtual void method69();
    virtual void method70();
    virtual void method71();
    virtual void method72();
    virtual void method73();
    virtual void method74();
    virtual void method75();
    virtual void method76();
    virtual void method77();
    virtual void method78();
    virtual void method79();
    virtual void method80();
    virtual void method81();
    virtual void method82();
    virtual void method83();
    virtual void method84();
    virtual void method85();
    virtual void method86();
    virtual void method87();
    virtual void method88();
    virtual void method89();
    virtual void method90();
    virtual void method91();
    virtual void method92();
    virtual void method93();
    virtual void method94();
    virtual void method95();
    virtual void method96();
    virtual void method97();
    virtual void method98();
    virtual void method99();
    virtual void method100();
    virtual void method101();
    virtual void method102();
    virtual void method103();
    virtual void method104();
    virtual void method105();
    virtual void method106();
    virtual void method107();
    virtual void method108();
    virtual void method109();
    virtual void method110();
    virtual void method111();
    virtual void method112();
    virtual void Reset();
    int unk4;
    int unk8;
    int unkC;
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
    FUN_0081aa80* head;
    unsigned id;
    void DeleteAllNodes();
    void FUN_0081e980(int, int);
    void FUN_00484d00(void*, unsigned);
    void FUN_00484d40(void*, unsigned);
    void LoadFromStream(int, int);
};
// Resets the projectile, reads several 4-byte fields and a form ID from the stream, then reads a list of form/flag records when the save version is at least 0x71.
// @fnv 0x0081afa0
void Projectile::LoadFromStream(int a, int b)
{
    DeleteAllNodes();
    Reset();
    FUN_0081e980(a, b);
    FUN_00484d00(&unkA8, 4);
    FUN_00484d00(&unk88, 4);
    FUN_00484d00(&unkAC, 4);
    DAT_011de45c->FUN_008579e0(&unkB4, 4);
    FUN_00484d00(&unkB8, 4);
    if (unkB4 == 1)
    {
        unsigned formID;
        FUN_00484d00(&formID, 4);
        FUN_00401460(&id, &formID, 4);
    }
    if (DAT_011de45c->FUN_008df040() >= 0x71)
    {
        FUN_00484d00(&unkB0, 4);
        unsigned short count;
        FUN_00484d00(&count, 2);
        for (unsigned i = 0; i < count; ++i)
        {
            FUN_0081aa80* record;
            {
                Form* form;
                {
                    unsigned char flags;
                    FUN_00484d40(&form, 4);
                    FUN_00484d00(&flags, 1);
                    record = new FUN_0081aa80(form, flags, head);
                    head = record;
                }
            }
        }
    }
}

struct FxPoint3
{
    float x, y, z;
};
struct FxMatrix3
{
    float m[9];
    FxMatrix3();
    void FUN_00a59660(float fZ, float fX, float fY);
};
struct FxFixedString
{
    const char* m_kHandle;
    FxFixedString(const char* pcString);
    ~FxFixedString();
};
struct FxTransformTime
{
    int unk00, unk04, unk08;
    FxTransformTime(float fTime, int a2, int a3);
};

struct FxAVObject;
struct FxSequence
{
    void FUN_0098adb0(float fTime);
};
struct FxControllerManager
{
    FxSequence* FUN_0047a520(const FxFixedString& kName);
    void FUN_0048fef0(float fTime);
    bool FUN_0047aab0(FxSequence* pkSeq, int a2, int a3, float fWeight, float fEase, int a6);
    void FUN_0047aa40(int i);
};
struct FxNode
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
    virtual FxAVObject* GetObjectByName(const FxFixedString& kName);

    void FUN_00440490(float fScale);
    void FUN_00440460(const FxPoint3& kPos);
    void FUN_0043fa80(const FxMatrix3& kRot);
    void* FUN_0043b230();
    void FUN_00a59c60(FxTransformTime* pkTime);
};
void __cdecl FUN_00c4b500(FxNode* pkNode);
FxControllerManager* __cdecl FUN_00653270(void* pkRTTI, void* pkController);
extern char g_kNiControllerManagerRTTI_011f36ac[];
extern const float g_fInfinity_0107ad40;
extern float g_fGameTime_011c3c08;

static const char s_szAreaEffect[] = "AreaEffect";
static const char s_szSpecialIdle[] = "SpecialIdle_Projectile";
extern const char g_szFogInitEnd[] = "";

struct FogProjectileInit
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
    virtual void v115();

    virtual FxNode* Get3D();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const FxPoint3& GetPos();

    char pad004[0xb8 - 4];
    float m_fScale;

    const FxPoint3& FUN_00430830();
    void ScaleEffect(FxAVObject* pkObject);
    void InitProjectileEffect();
};

// @fnv 0x00819a90
void FogProjectileInit::InitProjectileEffect()
{
    FxNode* pkNode = Get3D();
    if (pkNode)
    {
        pkNode->FUN_00440490(m_fScale);
        pkNode->FUN_00440460(GetPos());
        FxPoint3 kAngleX = FUN_00430830();
        FxMatrix3 kKRot;
        kKRot.FUN_00a59660(kAngleX.z, kAngleX.x, kAngleX.y);
        pkNode->FUN_0043fa80(kKRot);
        FUN_00c4b500(pkNode);
        FxAVObject* pkArea_2 = pkNode->GetObjectByName(FxFixedString(s_szAreaEffect));
        if (pkArea_2)
            ScaleEffect(pkArea_2);
        FxControllerManager* pkManagerTmp = FUN_00653270(g_kNiControllerManagerRTTI_011f36ac, pkNode->FUN_0043b230());
        if (pkManagerTmp)
        {
            FxSequence* pkSeqCur = pkManagerTmp->FUN_0047a520(FxFixedString(s_szSpecialIdle));
            if (pkSeqCur)
            {
                pkManagerTmp->FUN_0048fef0(0.0f);
                pkManagerTmp->FUN_0047aab0(pkSeqCur, 0, 0, 1.0f, 0.0f, 0);
                pkManagerTmp->FUN_0047aa40(1);
                pkSeqCur->FUN_0098adb0(-g_fInfinity_0107ad40);
                FxTransformTime kTimeY(g_fGameTime_011c3c08 - 0.1f, 1, 0);
                pkNode->FUN_00a59c60(&kTimeY);
            }
        }
    }
}

struct ItemA
{
    int FUN_0084e3a0();
};
struct ItemB
{
    unsigned char FindEffectItemIndex();
};
struct ItemC
{
    float FUN_00621b00();
};
struct Node2
{
    ItemA* m0;
    void* m4;
    Node2* next;
};
struct SaveMgrExt
{
    void FUN_008579b0(void*, unsigned int);
    unsigned short* FUN_00825c00();
    unsigned char FUN_008df040();
};

class FUN_0081ade0_cls
{
  public:
    void FUN_0081e8c0(int);
    void FUN_00484ce0(void*, unsigned int);
    void ForwardToSaveLoadGame(void*, unsigned int);
    int FUN_00810fd0();
    int FUN_00810fd0(int);
    void SaveToStream(int a1);

    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84;
    int m88;
    int unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int unkBC, unkC0, unkC4;
    Node2* m_c8;
    ItemC* m_cc;
};

// @fnv 0x0081ade0
void FUN_0081ade0_cls::SaveToStream(int a1)
{
    float f;
    unsigned short* out;
    FUN_0081e8c0(a1);
    FUN_00484ce0(&m_a8, 4);
    FUN_00484ce0(&m88, 4);
    FUN_00484ce0(&m_ac, 4);
    ((SaveMgrExt*)DAT_011de45c)->FUN_008579b0(&m_b4, 4);
    FUN_00484ce0(&m_b8, 4);
    if (m_b4 == 1)
    {
        f = 0.0f;
        if (m_cc != 0)
        {
            f = m_cc->FUN_00621b00();
        }
        FUN_00484ce0(&f, 4);
    }
    if ((int)((SaveMgrExt*)DAT_011de45c)->FUN_008df040() >= 0x71)
    {
        Node2* cur;
        unsigned short cnt;
        FUN_00484ce0(&m_b0, 4);
        cnt = 0;
        out = ((SaveMgrExt*)DAT_011de45c)->FUN_00825c00();
        FUN_00484ce0(&cnt, 2);
        cur = m_c8;
        while (cur != 0)
        {
            int tmp = 0;
            if (cur->m0 != 0)
            {
                tmp = cur->m0->FUN_0084e3a0();
            }
            ForwardToSaveLoadGame(&tmp, 4);
            unsigned char flag = 0;
            if (FUN_00810fd0() != 0 && cur->m4 != 0)
            {
                flag = ((ItemB*)(FUN_00810fd0((int)cur->m4) + 0xc))->FindEffectItemIndex();
            }
            FUN_00484ce0(&flag, 1);
            cnt++;
            cur = cur->next;
        }
        *out = cnt;
    }
}

class TESForm
{
  public:
    virtual void v000();
};
class TESObjectREFR : public TESForm
{
  public:
};
TESForm* __cdecl LookupFormByID(unsigned int auiFormId);

struct FogSoundHandle
{
    int unk00, unk04, unk08;
    ~FogSoundHandle();
    FogSoundHandle& operator=(const FogSoundHandle& kOther);
    bool FUN_00ad8ce0();
    void FUN_00ad8d10();
};

struct FogSoundForm
{
    unsigned int FUN_0084e3a0();
};
struct FogBaseForm
{
    FogSoundForm* FUN_004fd3c0();
    FogSoundForm* FUN_004fd380();
};

struct FogLight
{
    int unk00[7];
    FogLight(unsigned int auiFormId, void* pkNode);
    void* operator new(unsigned int uiSize);
    void operator delete(void* pvMem);
    void FUN_0081c470(int iUnk, float fRadius);
    void FUN_00621b20(float fFadeAmount);
};

struct FogProcess
{
    void FUN_00548230(void* pkProjectile, int iUnk);
};

struct FogRefNode
{
    TESForm* m_pkForm;
    int m_iValue;
    FogRefNode* m_pkNext;
};

struct FogIndexList
{
    int FUN_00406ee0(unsigned char m_ucClipIdentifier);
};
struct FogFile
{
    int unk00, unk04, unk08;
    FogIndexList kList;
};

struct FogSaveManager
{
    unsigned char FUN_008df040();
};
extern FogSaveManager* g_pkSaveManager_011de45c;

struct FogProjectileLoad
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
    virtual void v115();

    virtual void* Get3D();

    char pad004[0xac - 4];
    float m_fBoundRadius;
    char pad0b0[0xb4 - 0xb0];
    int unkb4;
    char pad0b8[0xbc - 0xb8];
    FogSoundHandle m_kSound;
    FogRefNode* m_pkRefs;
    FogLight* m_pkLight;

    void ResolveMagicReferences(int a1, int a2);
    void InitProjectileEffect();
    FogProcess* FUN_008d6f30();
    FogBaseForm* FUN_004fd400();
    FogSoundHandle PlaySoundByFormID(unsigned int auiFormId, int a2, int a3, int a4);
    FogFile* FUN_00810fd0();
    void LoadProjectile(int a1, int a2);
};

// Runs the projectile load steps, rebuilds the sound handle and light, and remaps reference forms and indices when the save version is at least 0x71.
// @fnv 0x0081b180
void FogProjectileLoad::LoadProjectile(int a1, int a2)
{
    ResolveMagicReferences(a1, a2);
    InitProjectileEffect();
    FUN_008d6f30()->FUN_00548230(this, 0);
    if (unkb4 != 1 && FUN_004fd400()->FUN_004fd3c0())
    {
        unsigned int uiProjectileSoundFormID = FUN_004fd400()->FUN_004fd3c0()->FUN_0084e3a0();
        if (m_kSound.FUN_00ad8ce0())
            m_kSound.FUN_00ad8d10();
        m_kSound = PlaySoundByFormID(uiProjectileSoundFormID, 1, 0x40000102, 1);
    }
    float fFadeAmount;
    FUN_00401460(&fFadeAmount, &m_pkLight, 4);
    m_pkLight = 0;
    if (Get3D() && FUN_004fd400()->FUN_004fd380())
    {
        m_pkLight = new FogLight(FUN_004fd400()->FUN_004fd380()->FUN_0084e3a0(), Get3D());
        if (m_pkLight)
        {
            m_pkLight->FUN_0081c470(0, m_fBoundRadius);
            m_pkLight->FUN_00621b20(fFadeAmount);
        }
    }
    if (g_pkSaveManager_011de45c->FUN_008df040() >= 0x71)
    {
        FogRefNode* pkNode = m_pkRefs;
        while (pkNode)
        {
            unsigned int uiFormID_2 = (unsigned int)pkNode->m_pkForm;
            unsigned char ucIndexZ = (unsigned char)pkNode->m_iValue;
            if (uiFormID_2)
                pkNode->m_pkForm = dynamic_cast<TESObjectREFR*>(LookupFormByID(uiFormID_2));
            if (FUN_00810fd0())
                pkNode->m_iValue = FUN_00810fd0()->kList.FUN_00406ee0(ucIndexZ);
            pkNode = pkNode->m_pkNext;
        }
    }
}

extern unsigned int DAT_011dea3c;
extern Setting DAT_011d15f8;
void __cdecl FUN_0080fc90(float);

struct FUN_0080fcc0
{
    ~FUN_0080fcc0();
};

struct FUN_00483710
{
    int unk00, unk04, unk08, unk0C;
    ~FUN_00483710();
    bool FUN_00ad8ce0();
    void FUN_00ad88f0();
    void FUN_00ad8d10();
};

struct MagicFogObject8196
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
    virtual unsigned int v11();
};

struct FUN_0081de70
{
    virtual ~FUN_0081de70();
    int unk04, unk08, unk0C, unk10, unk14;
};

struct MagicFogIface8196
{
    virtual void v00();
};

struct FUN_008196e0 : public FUN_0081de70, public MagicFogIface8196
{
    int unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8;
    FUN_00483710 m_kSound;
    FUN_0080fcc0* m_pkCc;
    virtual ~FUN_008196e0();
    void* FUN_009185e0();
    void DeleteAllNodes();
};

// @fnv 0x008196e0
FUN_008196e0::~FUN_008196e0()
{
    unsigned int uiValue = FUN_009185e0() ? ((MagicFogObject8196*)FUN_009185e0())->v11() : 0;
    if (uiValue != DAT_011dea3c)
        FUN_0080fc90(*DAT_011d15f8.FUN_00403e20());
    DeleteAllNodes();
    if (m_kSound.FUN_00ad8ce0())
    {
        m_kSound.FUN_00ad88f0();
        m_kSound.FUN_00ad8d10();
    }
    if (m_pkCc)
        delete m_pkCc;
    m_pkCc = 0;
}

struct FogColor
{
    unsigned int m_uiColor;
    FogColor();
    void FUN_004a39f0(int iAlpha);
    void FUN_0059ce80(int iColor);
};

struct FogColorSource
{
    unsigned int m_uiCurrentValue;
    FogColorSource();
    int FUN_004a3a20();
};
struct FogColorHolder
{
    FogColorSource FUN_0043b4f0();
};
struct FogRace
{
    FogColorHolder* FUN_006fa820();
};
FogRace* __cdecl FUN_004b5260(void* pkNode);
int __cdecl FUN_005dbe10();
void __cdecl FUN_0080fae0(float fValue);

class FogReference3DView
{
  public:
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
    virtual void v115();

    virtual void* Get3D();
};
class Actor : public TESObjectREFR
{
  public:
    FogColorSource FUN_00931ed0();
};
extern Actor* g_thePlayer_011dea3c;

struct FogCasterSrc
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
    virtual TESObjectREFR* GetRef();
};

struct FogShader
{
    FogColor FUN_0070c440();
    void FUN_00810ff0(FogColor kColor);
};

struct SettingStandIn
{
    float* FUN_00403e20();
};
extern SettingStandIn g_s_011d15f8;

struct FogProjectileImpl
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
    virtual void v115();

    virtual void* Get3D();

    void UpdateFlags(int a1, int a2);
    FogShader* FUN_009306d0();
    FogCasterSrc* FUN_009185e0();
    void FUN_0081b430(int a1, int a2);
};

// @fnv 0x0081b430
void FogProjectileImpl::FUN_0081b430(int a1, int a2)
{
    UpdateFlags(a1, a2);
    FogShader* pkShaderZ = FUN_009306d0();
    if (pkShaderZ)
    {
        int iColor;
        if (FUN_009185e0() && FUN_009185e0()->GetRef())
        {
            TESObjectREFR* pkRef = FUN_009185e0()->GetRef();
            Actor* pkActor = dynamic_cast<Actor*>(pkRef);
            if (pkActor)
            {
                iColor = pkActor->FUN_00931ed0().FUN_004a3a20();
            }
            else
            {
                FogRace* pkRaceA = FUN_004b5260(reinterpret_cast<FogReference3DView*>(pkRef)->Get3D());
                FogColorHolder* pkHolderPtr = pkRaceA ? pkRaceA->FUN_006fa820() : 0;
                iColor = pkHolderPtr ? pkHolderPtr->FUN_0043b4f0().FUN_004a3a20() : FUN_005dbe10();
            }
        }
        else
        {
            FogRace* pkRace2 = FUN_004b5260(Get3D());
            FogColorHolder* pkHolder2 = pkRace2 ? pkRace2->FUN_006fa820() : 0;
            iColor = pkHolder2 ? pkHolder2->FUN_0043b4f0().FUN_004a3a20() : FUN_005dbe10();
        }
        FogColor kColor = pkShaderZ->FUN_0070c440();
        kColor.FUN_004a39f0(7);
        kColor.FUN_0059ce80(iColor);
        pkShaderZ->FUN_00810ff0(kColor);
    }
    TESObjectREFR* _pkCaster = FUN_009185e0() ? FUN_009185e0()->GetRef() : 0;
    if (_pkCaster != g_thePlayer_011dea3c)
        FUN_0080fae0(*g_s_011d15f8.FUN_00403e20());
}
