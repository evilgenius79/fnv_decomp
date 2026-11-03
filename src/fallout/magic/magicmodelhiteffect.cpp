// fallout/magic/magicmodelhiteffect.cpp: MagicModelHitEffect, Candidate (22 functions)

#include "magicmodelhiteffect_decls.h"
#include "magicmodelhiteffect_layout.h"

// @fnv 0x0081c950
bool MagicModelHitEffect::Init()
{
    if (reinterpret_cast<NiAVObject*>(this)->GetParent())
    {
        this->m_fFirstFloatValue = reinterpret_cast<ActiveEffect*>(reinterpret_cast<NiAVObject*>(this)->GetParent())->GetAge();
        this->bWasPlaying = !reinterpret_cast<ActiveEffect*>(reinterpret_cast<NiAVObject*>(this)->GetParent())
                                 ->GetEffectSetting()
                                 ->IsFlagSet(0x400);
    }

    if (this->pTarget)
    {
        if (this->pTarget->GetNiNode())
        {
            if (this->pTarget == reinterpret_cast<TESObjectREFR*>(g_thePlayer))
                this->b3rdPerson = g_thePlayer->FUN_004eaf60();

            if (this->pFilename)
            {
                if (*this->pFilename)
                {
                    NiNode* model = g_modelLoader->LoadFile(this->pFilename, 0, true, false, false, false);
                    if (model)
                    {
                        NiControllerManager* manager = reinterpret_cast<NiControllerManager*>(FUN_00653270(
                            &DAT_011f36ac,
                            reinterpret_cast<NiProperty*>(reinterpret_cast<NiObjectNET*>(model)->GetControllers())));
                        if (manager)
                        {
                            NiControllerSequence* sequence;
                            sequence = manager->FindSequenceByName(NiFixedString(kMagicModelHitEffectName));
                            if (!sequence)
                                return false;
                        }
                    }

                    this->spRetainedObject = LoadAndCloneModel(this->pFilename);
                    g_modelLoader->QueueModelLoad(this->pFilename, false, 1);
                    if (reinterpret_cast<NiPointer<NiNode>*>(&this->spRetainedObject)->operator->())
                    {
                        if (this->pTarget->GetNiNode())
                        {
                            this->AttachToTarget();
                            FUN_00c4b500(reinterpret_cast<NiAVObject*>(
                                reinterpret_cast<NiPointer<NiNode>*>(&this->spRetainedObject)->operator->()));

                            {
                                NiUpdateData map(
                                    static_cast<float>(static_cast<double>(g_timeGlobal.GetTimeStamp()) / 1000.0), true,
                                    false);
                                reinterpret_cast<NiAVObject*>(
                                    reinterpret_cast<NiPointer<NiNode>*>(&this->spRetainedObject)->operator->())
                                    ->Update(map);
                            }

                            NiControllerManager* targetManager = reinterpret_cast<NiControllerManager*>(FUN_00653270(
                                &DAT_011f36ac,
                                reinterpret_cast<NiProperty*>(
                                    reinterpret_cast<NiObjectNET*>(
                                        reinterpret_cast<NiPointer<NiNode>*>(&this->spRetainedObject)->operator->())
                                        ->GetControllers())));
                            if (targetManager)
                            {
                                NiControllerSequence* targetSequence;
                                targetSequence =
                                    targetManager->FindSequenceByName(NiFixedString(kMagicModelHitEffectName));
                                if (targetSequence)
                                {
                                    targetManager->DeactivateAllSequences(0.0f);
                                    targetManager->ActivateControllerSequence(targetSequence, 0, false, 1.0f, 0.0f, 0);
                                    targetManager->FUN_0047aa40(true);
                                    if (this->m_fFirstFloatValue > 0.0f)
                                        targetSequence->SetSequenceTime(this->m_fFirstFloatValue, false);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

struct S_0081c600
{
    char pad[0x3c];
    void FUN_0081c810();
    static void __cdecl operator delete(void*, unsigned int);
    S_0081c600* DestroyIfFlagged(unsigned int flags);
};
// @fnv 0x0081c600
S_0081c600* S_0081c600::DestroyIfFlagged(unsigned int flags)
{
    FUN_0081c810();
    if (flags & 1)
        S_0081c600::operator delete(this, 0x3c);
    return this;
}

struct Sub_0081c630
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5();
};
struct ES_0081c630
{
    char pad[0x18];
    Sub_0081c630 sub;
};
struct MI_0081c630
{
    ES_0081c630* GetEffectSettingForRange(int);
};
struct AE_0081c630
{
    MI_0081c630* GetMagicItem();
};
struct NP_0081c630
{
    void* p;
    NP_0081c630(int);
    ~NP_0081c630();
    NP_0081c630& operator=(void*);
};
struct CF_0081c630
{
    int f;
    CF_0081c630();
};
struct Base_0081c630
{
    char pad[0x24];
    Base_0081c630(TESObjectREFR*, AE_0081c630*);
    virtual ~Base_0081c630();
};
struct FUN_0081c630 : Base_0081c630
{
    bool b28;
    bool b29;
    int f2c;
    NP_0081c630 spA;
    NP_0081c630 spB;
    CF_0081c630 flags;
    FUN_0081c630(TESObjectREFR* ref, AE_0081c630* ae);
    virtual ~FUN_0081c630();
};
// Initialises the base with ref and ae, clears spA/spB, b29 and b28, and stores the magic item's sub.v5() result in f2c.
// @fnv 0x0081c630
FUN_0081c630::FUN_0081c630(TESObjectREFR* ref, AE_0081c630* ae) : Base_0081c630(ref, ae), spA(0), spB(0)
{
    spA = 0;
    spB = 0;
    b29 = false;
    f2c = 0;
    f2c = ae->GetMagicItem()->GetEffectSettingForRange(0)->sub.v5();
    b28 = false;
}

struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiQuaternion;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    struct blob4 GetChangeFlags();
    void SetChangeFlags(struct blob4);
    struct blob4 GetOldChangeFlags();
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];
struct FUN_0081db90_shell : public BGSLoadFormBuffer
{
    void FUN_0081db90();
};

void __fastcall FUN_008646f0(void*);

// @fnv 0x0081db90
void FUN_0081db90_shell::FUN_0081db90()
{
    FUN_008646f0(this);
}

extern const NiRTTI g_011dc724;

struct FUN_0081c5f0_shell
{
    const NiRTTI* GetRTTI();
};

// @fnv 0x0081c5f0
const NiRTTI* FUN_0081c5f0_shell::GetRTTI()
{
    return &g_011dc724;
}

namespace fnv_0081c720 {
extern double _gModifierZero;
struct GO
{
    GO(int);
    ~GO();
    NiNode* m_pObject;
};
struct NP
{
    NP& operator=(void*);
};
struct CF_0081c630
{
    CF_0081c630();
    char* pBuffer;
};
struct Base_0081c630 : public MagicHitEffect
{
    Base_0081c630(TESObjectREFR* apTarget, ActiveEffect* apEffect);
};
struct FUN_0081c720 : public Base_0081c630
{
    bool m_bFirstPerson;
    bool b3rdPerson;
    const char* pFilename;
    GO m_pRenderedNodeEntry;
    GO spClone;
    CF_0081c630 kSubBuffer;
    FUN_0081c720(TESObjectREFR* apTarget, const char* apFilename, float afLifetime);
    ~FUN_0081c720();
};
// Initialises the effect with the target, filename and lifetime (clamped to FLT_MAX when negative), clearing the object and clone pointers.
// @fnv 0x0081c720
FUN_0081c720::FUN_0081c720(TESObjectREFR* apTarget, const char* apFilename, float afLifetime)
    : Base_0081c630(apTarget, 0), m_pRenderedNodeEntry(0), spClone(0)
{
    (NP&)m_pRenderedNodeEntry = 0;
    (NP&)spClone = 0;
    b3rdPerson = false;
    pFilename = apFilename;
    m_bFirstPerson = false;
    if (afLifetime < _gModifierZero)
    {
        m_fParticleParameter5 = 3.402823466e+38F;
    }
    else
    {
        m_fParticleParameter5 = afLifetime;
    }
}
}  // namespace fnv_0081c720

struct ActiveEffect;
struct TESObjectREFR;
struct Flt
{
    operator unsigned int() const;
};
unsigned short __cdecl FUN_0055fdb0(NiControllerManager*);
struct FUN_0081d0b0_t
{
    unsigned short GetSaveSize(ActiveEffect* apEffect, TESObjectREFR* apTarget);
    unsigned short FUN_0081d0b0(ActiveEffect* apEffect, TESObjectREFR* apTarget);
};
// @fnv 0x0081d0b0
unsigned short FUN_0081d0b0_t::FUN_0081d0b0(ActiveEffect* apEffect, TESObjectREFR* apTarget)
{
    unsigned short isize = 0;
    isize += GetSaveSize(apEffect, apTarget);
    isize += 2;
    if (*(Flt*)((char*)this + 0x30))
    {
        NiControllerManager* pmanager = (NiControllerManager*)FUN_00653270(
            &DAT_011f36ac, (NiProperty*)((NiObjectNET*)(unsigned int)*(Flt*)((char*)this + 0x30))->GetControllers());
        if (pmanager)
        {
            isize += FUN_0055fdb0(pmanager);
        }
    }
    return isize;
}

struct FUN_0081be50_s
{
    void SetTargetCell(ActiveEffect*, TESObjectREFR*);
};

struct FUN_0081d390_s
{
    void FUN_0081d390(ActiveEffect* apEffect, TESObjectREFR* apRefr);
};

// @fnv 0x0081d390
void FUN_0081d390_s::FUN_0081d390(ActiveEffect* apEffect, TESObjectREFR* apRefr)
{
    ((FUN_0081be50_s*)this)->SetTargetCell(apEffect, apRefr);
}

struct FUN_0081d5a0_Holder
{
    char _00[24];
    int _18;
    int _1c;
    char _20[12];
    const char* _2c;
    bool FUN_0081d5a0();
};
// Returns true when _18 is zero and both _1c and _2c are non-zero; otherwise returns false.
// @fnv 0x0081d5a0
bool FUN_0081d5a0_Holder::FUN_0081d5a0()
{
    if (_18)
        return false;
    if (!_1c || !_2c)
        return false;
    return true;
}

namespace fnv_0081c810 {
struct Flt
{
    operator unsigned int();
};
struct GO
{
    void* p;
    ~GO();
    void operator=(void*);
};
struct FUN_00435b20_shell
{
    int d[3];
    void FUN_00435b20();
};
struct FUN_0081b6d0_s
{
    virtual ~FUN_0081b6d0_s();
    int pad[9];
};
struct SNode
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
    virtual void InsertChild(unsigned int);
};
void __cdecl _Deallocate(void*);
struct FUN_0081c810 : FUN_0081b6d0_s
{
    bool m_bFirstPerson;
    char* pPath;
    GO m_pRenderedNodeEntry;
    GO spAttach;
    FUN_00435b20_shell kList;
    ~FUN_0081c810();
};
// @fnv 0x0081c810
FUN_0081c810::~FUN_0081c810()
{
    if (*(Flt*)&m_pRenderedNodeEntry)
    {
        NiNode* pparent = ((NiAVObject*)(unsigned int)*(Flt*)&m_pRenderedNodeEntry)->GetParent();
        if (pparent)
            ((SNode*)pparent)->InsertChild(*(Flt*)&m_pRenderedNodeEntry);
        m_pRenderedNodeEntry = 0;
    }
    spAttach = 0;
    if (pPath && *pPath)
    {
        g_modelLoader->QueueModelLoad(pPath, false, 1);
        if (m_bFirstPerson)
            delete pPath;
    }
    pPath = 0;
    kList.FUN_00435b20();
}
}  // namespace fnv_0081c810

namespace fnv_0081d800 {
struct NiControllerManager;
struct BGSSaveFormBuffer
{
    unsigned int FUN_00865f20();
    void FUN_00865ff0(int, unsigned int);
};
struct Animation
{
    float FUN_00453700();
};
struct Actor_0081d800
{
    virtual void av000();
    virtual void av001();
    virtual void av002();
    virtual void av003();
    virtual void av004();
    virtual void av005();
    virtual void av006();
    virtual void av007();
    virtual void av008();
    virtual void av009();
    virtual void av010();
    virtual void av011();
    virtual void av012();
    virtual void av013();
    virtual void av014();
    virtual void av015();
    virtual void av016();
    virtual void av017();
    virtual void av018();
    virtual void av019();
    virtual void av020();
    virtual void av021();
    virtual void av022();
    virtual void av023();
    virtual void av024();
    virtual void av025();
    virtual void av026();
    virtual void av027();
    virtual void av028();
    virtual void av029();
    virtual void av030();
    virtual void av031();
    virtual void av032();
    virtual void av033();
    virtual void av034();
    virtual void av035();
    virtual void av036();
    virtual void av037();
    virtual void av038();
    virtual void av039();
    virtual void av040();
    virtual void av041();
    virtual void av042();
    virtual void av043();
    virtual void av044();
    virtual void av045();
    virtual void av046();
    virtual void av047();
    virtual void av048();
    virtual void av049();
    virtual void av050();
    virtual void av051();
    virtual void av052();
    virtual void av053();
    virtual void av054();
    virtual void av055();
    virtual void av056();
    virtual void av057();
    virtual void av058();
    virtual void av059();
    virtual void av060();
    virtual void av061();
    virtual void av062();
    virtual void av063();
    virtual void av064();
    virtual void av065();
    virtual void av066();
    virtual void av067();
    virtual void av068();
    virtual void av069();
    virtual void av070();
    virtual void av071();
    virtual void av072();
    virtual void av073();
    virtual void av074();
    virtual void av075();
    virtual void av076();
    virtual void av077();
    virtual void av078();
    virtual void av079();
    virtual void av080();
    virtual void av081();
    virtual void av082();
    virtual void av083();
    virtual void av084();
    virtual void av085();
    virtual void av086();
    virtual void av087();
    virtual void av088();
    virtual void av089();
    virtual void av090();
    virtual void av091();
    virtual void av092();
    virtual void av093();
    virtual void av094();
    virtual void av095();
    virtual void av096();
    virtual void av097();
    virtual void av098();
    virtual void av099();
    virtual void av100();
    virtual void av101();
    virtual void av102();
    virtual void av103();
    virtual void av104();
    virtual void av105();
    virtual void av106();
    virtual void av107();
    virtual void av108();
    virtual void av109();
    virtual void av110();
    virtual void av111();
    virtual void av112();
    virtual void av113();
    virtual void av114();
    virtual void av115();
    virtual void av116();
    virtual void av117();
    virtual void av118();
    virtual void av119();
    virtual void av120();
    virtual Animation* GetAnimation();
};
struct BGSSaveGameBuffer
{
    virtual void sv0();
    virtual void sv1();
    virtual Actor_0081d800* GetActor();
    void SaveGameString(const char*, int);
};
struct FUN_0081be80_s
{
    void FUN_0081be80(BGSSaveFormBuffer*);
};
struct Flt
{
    operator unsigned int();
};
void __cdecl FUN_00563f30(NiControllerManager*, BGSSaveGameBuffer*, float);
struct FUN_0081d800_t
{
    void FUN_0081d800(BGSSaveGameBuffer* apSaveGameBuffer);
};
// @fnv 0x0081d800
void FUN_0081d800_t::FUN_0081d800(BGSSaveGameBuffer* apSaveGameBuffer)
{
    NiControllerManager* pmanager;
    ((FUN_0081be80_s*)this)->FUN_0081be80((BGSSaveFormBuffer*)apSaveGameBuffer);
    apSaveGameBuffer->SaveGameString(*(const char**)((char*)this + 0x2c), 0);
    pmanager = 0;
    if (*(Flt*)((char*)this + 0x30))
        pmanager = (NiControllerManager*)FUN_00653270(
            &DAT_011f36ac, (NiProperty*)((NiObjectNET*)(unsigned int)*(Flt*)((char*)this + 0x30))->GetControllers());
    {
        unsigned int uiStartPosition = ((BGSSaveFormBuffer*)apSaveGameBuffer)->FUN_00865f20();
        unsigned int uiFormIdBefore = ((TESForm*)apSaveGameBuffer)->GetFormID();
        if (pmanager)
        {
            Actor_0081d800* pactor = apSaveGameBuffer->GetActor();
            Animation* panim = pactor ? pactor->GetAnimation() : 0;
            float ftime = panim ? panim->FUN_00453700() : -1.0f;
            FUN_00563f30(pmanager, apSaveGameBuffer, -1.0f);
        }
        unsigned int uiFormIdAfter = ((TESForm*)apSaveGameBuffer)->GetFormID();
        ((BGSSaveFormBuffer*)apSaveGameBuffer)->FUN_00865ff0(uiFormIdAfter - uiFormIdBefore, uiStartPosition);
    }
}
}  // namespace fnv_0081d800

unsigned int __cdecl FUN_0044a670(const char*);

struct FUN_0081d5d0_Class
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2()
    {}
    virtual void v3()
    {}
    virtual void v4()
    {}
    virtual void v5()
    {}
    virtual void v6()
    {}
    virtual void v7()
    {}
    virtual void v8()
    {}
    virtual void v9()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual void v45()
    {}
    virtual void v46()
    {}
    virtual void v47()
    {}
    virtual void v48()
    {}
    virtual void v49()
    {}
    virtual void v50()
    {}
    virtual void v51()
    {}
    virtual unsigned short v52(int, int)
    {
        return 0;
    }

    char pad00[0x18];
    int unk1c;
    char pad20[0x0c];
    const char* unk2c;

    unsigned short __thiscall FUN_0081d5d0();
};

// @fnv 0x0081d5d0
unsigned short __thiscall FUN_0081d5d0_Class::FUN_0081d5d0()
{
    unsigned short usSize = 0;

    usSize += 4;
    usSize += 1;
    usSize += FUN_0044a670(unk2c);
    usSize += v52(0, unk1c);

    return usSize;
}

struct FUN_0081d640_target
{
    unsigned int GetKey();
};

struct FUN_0081d640_mgr
{
    void Add(void* p, unsigned int n);
    void Set(void* p, unsigned int n);
};

extern FUN_0081d640_mgr* g_mgr;
unsigned char __cdecl Query_0044a670(unsigned int v);

struct FUN_0081d640_cls
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
    virtual void v53(unsigned int a, void* b);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    void* m_1c;
    int unk20;
    int unk24;
    int unk28;
    unsigned int m_2c;

    void FUN_0081d640();
};

// Reads the key of the object at m_1c, adds it to g_mgr, queries m_2c for a flag, sets it, and calls v53(0, m_1c).
// @fnv 0x0081d640
void FUN_0081d640_cls::FUN_0081d640()
{
    unsigned int uiKey = ((FUN_0081d640_target*)m_1c)->GetKey();
    g_mgr->Add(&uiKey, 4);
    unsigned char flag = Query_0044a670(m_2c);
    g_mgr->Set(&flag, 1);
    g_mgr->Set((void*)m_2c, flag);
    v53(0, m_1c);
}

class B81D920LoadBuffer
{
  public:
    char* LoadString(char* pcBuffer);
};

class B81D920SubBuffer
{
  public:
    void LoadGame(B81D920LoadBuffer* pkBuffer);
};

class B81D920Loadable
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void* GetModelFilePath();
};

class B81D920Primary
{
  public:
    virtual ~B81D920Primary();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class B81D920Object
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    B81D920Loadable m_kLoadable;
};

class B81D920Handle
{
  public:
    B81D920Object* GetObject();
};

class B81D920Ref
{
  public:
    B81D920Handle* GetHandle();
};

class B81D920ModelLoader
{
  public:
    void ProcessModelRequest(void* pvModel, int iPriority, bool bA, bool bB, int iC, int iD, int iE);
};

extern B81D920ModelLoader* g_pkB81D920ModelLoader;

class B81D920Base
{
  public:
    void LoadGame(B81D920LoadBuffer* pkBuffer);
};

class FUN_0081d920_cls : public B81D920Base
{
  public:
    void FUN_0081d920(B81D920LoadBuffer* pkBuffer);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    B81D920Ref* m_pkRef;
    int unk1C;
    int unk20;
    int unk24;
    bool m_bLoadComplete;
    char* m_pcName;
    int unk30;
    int unk34;
    B81D920SubBuffer m_kSubBuffer;
};

// @fnv 0x0081d920
void FUN_0081d920_cls::FUN_0081d920(B81D920LoadBuffer* pkBuffer)
{
    B81D920Base::LoadGame(pkBuffer);
    m_pcName = pkBuffer->LoadString(0);
    m_bLoadComplete = true;
    m_kSubBuffer.LoadGame(pkBuffer);
    if (m_pkRef && m_pkRef->GetHandle()->GetObject()->m_kLoadable.GetModelFilePath())
        g_pkB81D920ModelLoader->ProcessModelRequest(m_pkRef->GetHandle()->GetObject()->m_kLoadable.GetModelFilePath(),
                                                    5, 0, 0, 1, 0, 0);
}

struct D9D0Effect
{
    void Apply(void* pkTarget);
    void ApplyEffect(void* pkTarget);
};

// @fnv 0x0081d9d0
void D9D0Effect::ApplyEffect(void* pkTarget)
{
    Apply(pkTarget);
}

class FUN_0081cc70_refvt
{
  public:
    virtual void s000();
    virtual void s001();
    virtual void s002();
    virtual void s003();
    virtual void s004();
    virtual void s005();
    virtual void s006();
    virtual void s007();
    virtual void s008();
    virtual void s009();
    virtual void s010();
    virtual void s011();
    virtual void s012();
    virtual void s013();
    virtual void s014();
    virtual void s015();
    virtual void s016();
    virtual void s017();
    virtual void s018();
    virtual void s019();
    virtual void s020();
    virtual void s021();
    virtual void s022();
    virtual void s023();
    virtual void s024();
    virtual void s025();
    virtual void s026();
    virtual void s027();
    virtual void s028();
    virtual void s029();
    virtual void s030();
    virtual void s031();
    virtual void s032();
    virtual void s033();
    virtual void s034();
    virtual void s035();
    virtual void s036();
    virtual void s037();
    virtual void s038();
    virtual void s039();
    virtual void s040();
    virtual void s041();
    virtual void s042();
    virtual void s043();
    virtual void s044();
    virtual void s045();
    virtual void s046();
    virtual void s047();
    virtual void s048();
    virtual void s049();
    virtual void s050();
    virtual void s051();
    virtual void s052();
    virtual void s053();
    virtual void s054();
    virtual void s055();
    virtual void s056();
    virtual void s057();
    virtual void s058();
    virtual void s059();
    virtual void s060();
    virtual void s061();
    virtual void s062();
    virtual void s063();
    virtual void s064();
    virtual void s065();
    virtual void s066();
    virtual void s067();
    virtual void s068();
    virtual void s069();
    virtual void s070();
    virtual void s071();
    virtual void s072();
    virtual void s073();
    virtual void s074();
    virtual void s075();
    virtual void s076();
    virtual void s077();
    virtual void s078();
    virtual void s079();
    virtual void s080();
    virtual void s081();
    virtual void s082();
    virtual void s083();
    virtual void s084();
    virtual void s085();
    virtual void s086();
    virtual void s087();
    virtual void s088();
    virtual void s089();
    virtual void s090();
    virtual void s091();
    virtual void s092();
    virtual void s093();
    virtual void s094();
    virtual void s095();
    virtual void s096();
    virtual void s097();
    virtual void s098();
    virtual void s099();
    virtual void s100();
    virtual void s101();
    virtual void s102();
    virtual void s103();
    virtual void s104();
    virtual void s105();
    virtual void s106();
    virtual void s107();
    virtual void s108();
    virtual void s109();
    virtual void s110();
    virtual void s111();
    virtual void s112();
    virtual void s113();
    virtual void s114();
    virtual void s115();
    virtual int s116();
};
class FUN_0081cc70_thisvt
{
  public:
    virtual void s000();
    virtual void s001();
    virtual void s002();
    virtual void s003();
    virtual void s004();
    virtual void s005();
    virtual void s006();
    virtual void s007();
    virtual void s008();
    virtual void s009();
    virtual void s010();
    virtual void s011();
    virtual void s012();
    virtual void s013();
    virtual void s014();
    virtual void s015();
    virtual void s016();
    virtual void s017();
    virtual void s018();
    virtual void s019();
    virtual void s020();
    virtual void s021();
    virtual void s022();
    virtual void s023();
    virtual void s024();
    virtual void s025();
    virtual void s026();
    virtual void s027();
    virtual void s028();
    virtual void s029();
    virtual void s030();
    virtual void s031();
    virtual void s032();
    virtual void s033();
    virtual void s034();
    virtual void s035();
    virtual void s036();
    virtual void s037();
    virtual void s038();
    virtual void s039();
    virtual void s040();
    virtual void s041();
    virtual void s042();
    virtual void s043();
    virtual void s044();
    virtual void s045();
    virtual void s046();
    virtual void s047();
    virtual void s048();
    virtual void s049();
    virtual void s050();
    virtual void s051();
};
class FUN_0081cc70_seqvt
{
  public:
    virtual void s000();
    virtual void s001();
    virtual void s002();
    virtual void s003();
    virtual void s004();
    virtual void s005();
    virtual void s006();
    virtual void s007();
    virtual void s008();
    virtual void s009();
    virtual void s010();
    virtual void s011();
    virtual void s012();
    virtual void s013();
    virtual void s014();
    virtual void s015();
    virtual void s016();
    virtual void s017();
    virtual void s018();
    virtual void s019();
    virtual void s020();
    virtual void s021();
    virtual void s022();
    virtual void s023();
    virtual void s024();
    virtual void s025();
    virtual void s026();
    virtual void s027();
    virtual void s028();
    virtual void s029();
    virtual void s030();
    virtual void s031();
    virtual void s032();
    virtual void s033();
    virtual void s034();
    virtual void s035(float, bool);
};

struct FUN_0081cc70_helper
{
    NiAVObject* FUN_00559450();
};

struct FUN_0081cc70_helper2
{
    NiProperty* FUN_0043b230();
};

struct FUN_0081cc70_seqm
{
    float FUN_00508120();
    float FUN_00508100();
    int FUN_008041a0();
    int FUN_0059bb30();
};

class FUN_0081cc70_cls : public MagicModelHitEffect
{
  public:
    bool UpdateMagicHitEffect(float afTime);
    bool FUN_0081cc70(float afTime);
};

// @fnv 0x0081cc70
bool FUN_0081cc70_cls::FUN_0081cc70(float afTime)
{
    if (pTarget == 0 || ((FUN_0081cc70_refvt*)pTarget)->s116() == 0 || !UpdateMagicHitEffect(afTime))
    {
        return false;
    }
    if (((FUN_0081cc70_helper*)&spRetainedObject)->FUN_00559450() != 0)
    {
        ((FUN_0081cc70_thisvt*)this)->s051();
        SkyShaderProperty* prop = FUN_00653270(
            &DAT_011f36ac,
            ((FUN_0081cc70_helper2*)((FUN_0081cc70_helper*)&spRetainedObject)->FUN_00559450())->FUN_0043b230());
        if (prop != 0)
        {
            NiControllerSequence* seq =
                ((NiControllerManager*)prop)->FindSequenceByName(NiFixedString("SpecialIdle_HitEffect"));
            if (seq != 0)
            {
                if (((FUN_0081cc70_seqm*)seq)->FUN_00508100() > ((FUN_0081cc70_seqm*)seq)->FUN_00508120() &&
                    ((FUN_0081cc70_seqm*)seq)->FUN_008041a0())
                {
                    if (((FUN_0081cc70_seqm*)seq)->FUN_0059bb30() == 2 || bWasPlaying != 0)
                    {
                        bWasPlaying = 1;
                        ((FUN_0081cc70_seqvt*)seq)->s035(0.0f, false);
                        m_fParticleParameter5 = m_fFirstFloatValue;
                    }
                }
            }
        }
    }
    if (bWasPlaying != 0)
    {
        if ((double)m_fParticleParameter5 + 2.0 < m_fFirstFloatValue)
        {
            return false;
        }
    }
    return true;
}

struct B006815c0
{
    float x, y, z;
    B006815c0();
    bool FUN_00439090(const B006815c0&);
};
struct Node505
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Node505* IsSceneNode();
    unsigned int FUN_0043b480();
    Node505* FUN_0043b4a0(unsigned int);
    B006815c0& FUN_0043c490();
    const B006815c0& FUN_0045bb80();
    Node505* FUN_0043d450();
    B006815c0& FUN_006815c0();
    void FUN_00440460(const B006815c0&);
    void* FUN_006a9540();
    void FUN_0043fa80(void*);
};
struct Form505
{
    int FUN_00401170();
};
struct Player505
{
    Node505* FUN_00950bb0(bool);
};
struct Holder505
{
    Node505* FUN_00559450();
};
extern B006815c0 DAT_011f426c;
struct Shell505 : MagicModelHitEffect
{
    void FUN_0081bc70(Node505*);
    void UpdateHitEffectNode();
};
// @fnv 0x0081ce20
void Shell505::UpdateHitEffectNode()
{
    Node505* node = 0;
    if (pTarget == reinterpret_cast<TESObjectREFR*>(g_thePlayer))
    {
        b3rdPerson = g_thePlayer->FUN_004eaf60();
        node = reinterpret_cast<Player505*>(g_thePlayer)->FUN_00950bb0(false);
    }
    else
    {
        node = reinterpret_cast<Node505*>(pTarget->GetNiNode());
    }
    FUN_0081bc70(reinterpret_cast<Holder505*>(&spRetainedObject)->FUN_00559450());
    if (node)
    {
        B006815c0 vecPosition;
        if ((pTarget->IsActor() && pTarget->Unk_8B(false)) || pTarget->Unk_8C())
        {
            bool lower = true;
            Node505* root = node->IsSceneNode();
            if (root && root->FUN_0043b480() > 0)
            {
                Node505* pBranchNode = root->FUN_0043b4a0(0);
                Node505* pChildNode = pBranchNode ? pBranchNode->IsSceneNode() : 0;
                if (pChildNode && pChildNode->FUN_0043b480() > 0)
                {
                    pBranchNode = pChildNode->FUN_0043b4a0(0);
                    Node505* pLeafNode = pBranchNode ? pBranchNode->IsSceneNode() : 0;
                    if (pLeafNode && pLeafNode->FUN_0043c490().FUN_00439090(DAT_011f426c))
                        lower = false;
                }
            }
            vecPosition = node->FUN_0045bb80();
            if (lower)
                vecPosition.z -= 64.0;
        }
        else if (pTarget->GetObjectReference() &&
                 reinterpret_cast<Form505*>(pTarget->GetObjectReference())->FUN_00401170() == 28)
        {
            vecPosition = node->FUN_0043d450()->FUN_006815c0();
            vecPosition.z = node->FUN_0045bb80().z;
        }
        else
        {
            vecPosition = node->FUN_0045bb80();
        }
        if (reinterpret_cast<Holder505*>(&spRetainedObject)->FUN_00559450())
        {
            reinterpret_cast<Holder505*>(&spRetainedObject)->FUN_00559450()->FUN_00440460(vecPosition);
            reinterpret_cast<Holder505*>(&spRetainedObject)->FUN_00559450()->FUN_0043fa80(node->FUN_006a9540());
        }
    }
}

class AnimationLocal
{
  public:
    float FUN_00453700();
};
class BaseProcess
{
  public:
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
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual AnimationLocal* GetAnimation();
};
class MiddleHighProcess : public BaseProcess
{
};
struct ActorLocal : TESObjectREFR
{
    BaseProcess* FUN_008d8520();
};
struct EffectItemLocal
{
    ES_0081c630* FUN_00825c00();
};
struct EffectLocal
{
    EffectItemLocal* FUN_0084e3a0();
};
struct ObjectPtrLocal
{
    NiAVObject* object;
    NiAVObject* FUN_00559450();
};
struct SaveManagerLocal
{
    const char* FUN_00825c00();
    void FUN_00600ab0(const char*);
    void FUN_008579e0(void*, unsigned int);
};
extern SaveManagerLocal* DAT_011de45c;
extern const float DAT_01012054;
void* __cdecl FUN_00653270(const NiRTTI*, NiTimeController*);
void __cdecl FUN_0055ffa0(void*, NiAVObject*, float);
void __cdecl FormHeap_Free(void*);
struct Candidate : MagicModelHitEffect
{
    void FUN_008d05e0(EffectLocal*, TESObjectREFR*, int);
    void SetFilenameAndInit(EffectLocal*, TESObjectREFR*, const char*);
};
// @fnv 0x0081d3b0
void Candidate::SetFilenameAndInit(EffectLocal* effect, TESObjectREFR* target, const char* pFilenameArg)
{
    FUN_008d05e0(effect, target, 0);
    const char* previous = pFilename;
    if (effect)
    {
        pFilename = reinterpret_cast<const char*>(effect->FUN_0084e3a0()->FUN_00825c00()->sub.v5());
    }
    else
    {
        pFilename = pFilenameArg;
    }
    float age = MagicHitEffect::m_fFirstFloatValue;
    bool finished = bWasPlaying;
    Init();
    MagicHitEffect::m_fFirstFloatValue = age;
    bWasPlaying = finished;
    const char* saved = DAT_011de45c->FUN_00825c00();
    DAT_011de45c->FUN_00600ab0(previous);
    unsigned short version3;
    DAT_011de45c->FUN_008579e0(&version3, 2);
    if (reinterpret_cast<ObjectPtrLocal*>(&spRetainedObject)->FUN_00559450())
    {
        void* controller4 = FUN_00653270(
            &DAT_011f36ac,
            reinterpret_cast<NiObjectNET*>(reinterpret_cast<ObjectPtrLocal*>(&spRetainedObject)->FUN_00559450())
                ->GetControllers());
        if (controller4)
        {
            float time_ = DAT_01012054;
            ActorLocal* actor4 = target && target->IsActor() ? reinterpret_cast<ActorLocal*>(target) : 0;
            MiddleHighProcess* aProcess;
            if (actor4 && effect && (aProcess = dynamic_cast<MiddleHighProcess*>(actor4->FUN_008d8520())) &&
                aProcess->GetAnimation())
                time_ = aProcess->GetAnimation()->FUN_00453700();
            FUN_0055ffa0(controller4, reinterpret_cast<ObjectPtrLocal*>(&spRetainedObject)->FUN_00559450(), time_);
        }
    }
    DAT_011de45c->FUN_00600ab0(saved);
    FormHeap_Free(const_cast<char*>(previous));
    Update(0.0f);
}

struct AnimDataStub
{
    float FUN_00453700();
};
struct ActorStub
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual AnimDataStub* GetAnimData();
};
struct LoadFormBufferStub : public BGSLoadFormBuffer
{
    ~LoadFormBufferStub();
};
struct SubBufferAccess
{
    char* pBuffer;
    operator char*() const;
    LoadFormBufferStub* CreateLoadBuffer(int);
    void Release();
};
struct ModelObjectStub
{
    NiObject* GetRoot();
};
struct ModelPtrAccess
{
    ModelObjectStub* m_pObject;
    operator ModelObjectStub*() const;
};
NiNode* __cdecl NiDynamicCastNode(const NiRTTI*, NiObject*);
void __cdecl ApplyLoadedModelData(NiNode*, LoadFormBufferStub*, float);

struct FUN_0081d9f0_shell : public MagicModelHitEffect
{
    void LoadMagicModelHitEffect(BGSLoadGameBuffer* apBuffer);
};

// @fnv 0x0081d9f0
void FUN_0081d9f0_shell::LoadMagicModelHitEffect(BGSLoadGameBuffer* apBuffer)
{
    MagicHitEffect::ApplyLoadBuffer(apBuffer);
    float fSavedAge = m_fFirstFloatValue;
    bool bSavedFinished5 = bWasPlaying;
    Init();
    m_fFirstFloatValue = fSavedAge;
    bWasPlaying = bSavedFinished5;
    if (*(SubBufferAccess*)&m_kLoadGameSubBuffer)
    {
        NiNode* pNodeX = 0;
        if (*(ModelPtrAccess*)&spRetainedObject)
            pNodeX =
                NiDynamicCastNode(&DAT_011f36ac, ((ModelObjectStub*)*(ModelPtrAccess*)&spRetainedObject)->GetRoot());
        if (pNodeX)
        {
            ActorStub* pActor4 = (ActorStub*)apBuffer->GetActor();
            AnimDataStub* pAnim2 = pActor4 ? pActor4->GetAnimData() : 0;
            float fTime = pAnim2 ? pAnim2->FUN_00453700() : -1.0f;
            LoadFormBufferStub* pLoadBuffer = ((SubBufferAccess*)&m_kLoadGameSubBuffer)->CreateLoadBuffer(0);
            ApplyLoadedModelData(pNodeX, pLoadBuffer, fTime);
            delete pLoadBuffer;
        }
    }
    ((SubBufferAccess*)&m_kLoadGameSubBuffer)->Release();
    Update(0.0f);
}

struct FUN_0081bd80_shell
{
    void FUN_0081bd80(ActiveEffect*, TESObjectREFR*);
};
unsigned short __cdecl FUN_0055fdb0(NiControllerManager*);
void __cdecl FUN_0055fe70(NiControllerManager*, float);
struct TESSaveLoadGame
{
    void FUN_008579b0(void*, int);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct Animation
{
    float FUN_00453700();
};
struct RefV_0081d150
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
    virtual bool IsActor();
};
struct TES
{
    void* GetLogDate();
};

struct FUN_0081d150_t
{
    void FUN_0081d150(ActiveEffect* apEffect, TESObjectREFR* apTarget);
};

// Calls the base helper, passes a 16-bit value to g_TESSaveLoadGame, and may update a controller manager using an actor's animation time.
// @fnv 0x0081d150
void FUN_0081d150_t::FUN_0081d150(ActiveEffect* apEffect, TESObjectREFR* apTarget)
{
    ((FUN_0081bd80_shell*)this)->FUN_0081bd80(apEffect, apTarget);
    NiControllerManager* pmanager = 0;
    if ((unsigned int)*(Flt*)((char*)this + 0x30))
        pmanager = (NiControllerManager*)FUN_00653270(
            &DAT_011f36ac, (NiProperty*)((NiObjectNET*)(unsigned int)*(Flt*)((char*)this + 0x30))->GetControllers());
    unsigned short usState = 0;
    if (pmanager)
        usState = FUN_0055fdb0(pmanager);
    g_TESSaveLoadGame->FUN_008579b0(&usState, 2);
    if (usState)
    {
        float ftime = -1.0f;
        TES* pactor = (apTarget && ((RefV_0081d150*)apTarget)->IsActor()) ? (TES*)apTarget : 0;
        if (pactor && apEffect)
        {
            MiddleHighProcess* pprocess = dynamic_cast<MiddleHighProcess*>((BaseProcess*)pactor->GetLogDate());
            if (pprocess && pprocess->GetAnimation())
                ftime = pprocess->GetAnimation()->FUN_00453700();
        }
        FUN_0055fe70(pmanager, ftime);
    }
}

#include <string.h>
namespace fnv_0081d2a0 {
class TESModel : public BaseFormComponent
{
  public:
    virtual ~TESModel();
    virtual const char* GetModelFilePath();
};
struct QueueHelper
{
    void FUN_00444040(int, int, int, int, bool, bool, bool);
};
struct TESSaveLoadGame
{
    void FUN_008579e0(void* apData, unsigned int auiSize);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct FUN_0081d2a0_t
{
    void SaveLoad(ActiveEffect* apEffect, TESObjectREFR* apTarget);
    void FUN_0081d2a0(ActiveEffect* apEffect, TESObjectREFR* apTarget);
};
// Calls SaveLoad, queues the effect model for loading if present, and reads a size-prefixed buffer from the save stream into the object.
// @fnv 0x0081d2a0
void FUN_0081d2a0_t::FUN_0081d2a0(ActiveEffect* apEffect, TESObjectREFR* apTarget)
{
    unsigned short isize;
    char* pbuffer;
    SaveLoad(apEffect, apTarget);
    if (apEffect &&
        ((TESModel*)(((TimeGlobal*)((TESForm*)apEffect)->GetFormID())->GetTimeStamp() + 0x18))->GetModelFilePath())
    {
        ((QueueHelper*)g_modelLoader)
            ->FUN_00444040((int)((TESModel*)(((TimeGlobal*)((TESForm*)apEffect)->GetFormID())->GetTimeStamp() + 0x18))
                               ->GetModelFilePath(),
                           5, 0, 0, true, false, false);
    }
    g_TESSaveLoadGame->FUN_008579e0(&isize, 2);
    if (isize)
    {
        pbuffer = (char*)operator new(isize + 2);
        memcpy(pbuffer, &isize, 2);
        g_TESSaveLoadGame->FUN_008579e0(pbuffer + 2, isize);
        *(char**)((char*)this + 0x2c) = pbuffer;
    }
}
}  // namespace fnv_0081d2a0

namespace fnv_0081d6c0 {
class TESSaveLoadGame
{
  public:
    void ValidateFormIDArray(unsigned int* apID, unsigned int auiSize);
    void FUN_008579e0(void* apData, unsigned int auiSize);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
TESForm* GetFormByID(unsigned int aiID);

struct FUN_0081d6c0_shell : public MagicModelHitEffect
{
    bool FUN_0081d6c0();
};

// MagicModelHitEffect::LoadGame (vB4)
// Validates a form ID and target cell, reads a string, then calls LoadGame, InitLoadGame and FinishLoadGameTES on the target.
// @fnv 0x0081d6c0
bool FUN_0081d6c0_shell::FUN_0081d6c0()
{
    bool bSuccess = true;
    unsigned int iformID;
    g_TESSaveLoadGame->ValidateFormIDArray(&iformID, 4);
    pTarget = dynamic_cast<TESObjectREFR*>(GetFormByID(iformID));
    if (!pTarget || !pTarget->GetParentCell() || !pTarget->GetParentCell()->IsOutdoorCell())
        bSuccess = false;
    {
        unsigned char isize;
        g_TESSaveLoadGame->FUN_008579e0(&isize, 1);
        char* pBuffer = new char[isize + 1];
        memset(pBuffer, 0, isize + 1);
        g_TESSaveLoadGame->FUN_008579e0(pBuffer, isize);
        m_bFirstPerson = true;
        LoadGame(0, pTarget);
        if (bSuccess)
        {
            InitLoadGame(0, pTarget);
            FinishLoadGameTES(0, pTarget, pBuffer);
        }
    }
    return bSuccess;
}
}  // namespace fnv_0081d6c0
