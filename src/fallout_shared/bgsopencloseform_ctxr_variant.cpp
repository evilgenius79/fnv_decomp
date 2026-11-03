
// bgsopencloseform_ctxr_variant.cpp: rename variant for 0x0047a560 (integration 2026-10-30): the unit's skeleton with ExtraDataList renamed, whose names are bound elsewhere.
#include "bgsopencloseform_packet_decls.h"
class ExtraDataList_r0047a560
{
  public:
    void CallExtraDataListMethod36(TESObjectREFR*);
};

class CtlV;
class NiAVObject;
class ModelOps;
struct NiPoint3
{
    float x;
    float y;
    float z;
};

class RefV
{
  public:
    virtual void d000();
    virtual void d001();
    virtual void d002();
    virtual void d003();
    virtual void d004();
    virtual void d005();
    virtual void d006();
    virtual void d007();
    virtual void d008();
    virtual void d009();
    virtual void d010();
    virtual void d011();
    virtual void d012();
    virtual void d013();
    virtual void d014();
    virtual void d015();
    virtual void d016();
    virtual void d017();
    virtual void v048(unsigned int);
    virtual void d019();
    virtual void d020();
    virtual void d021();
    virtual void d022();
    virtual void d023();
    virtual void d024();
    virtual void d025();
    virtual void d026();
    virtual void d027();
    virtual void d028();
    virtual void d029();
    virtual void d030();
    virtual void d031();
    virtual void d032();
    virtual void d033();
    virtual void d034();
    virtual void d035();
    virtual void d036();
    virtual void d037();
    virtual void d038();
    virtual void d039();
    virtual void d040();
    virtual void d041();
    virtual void d042();
    virtual void d043();
    virtual void d044();
    virtual void d045();
    virtual void d046();
    virtual void d047();
    virtual void d048();
    virtual void d049();
    virtual void d050();
    virtual void d051();
    virtual void d052();
    virtual void d053();
    virtual void d054();
    virtual void d055();
    virtual void d056();
    virtual void d057();
    virtual void d058();
    virtual void d059();
    virtual void d060();
    virtual void d061();
    virtual void d062();
    virtual void d063();
    virtual bool v100();
    virtual void d065();
    virtual void d066();
    virtual void d067();
    virtual void d068();
    virtual void d069();
    virtual void d070();
    virtual void d071();
    virtual void d072();
    virtual void d073();
    virtual void d074();
    virtual void d075();
    virtual void d076();
    virtual void d077();
    virtual void d078();
    virtual void d079();
    virtual void d080();
    virtual void d081();
    virtual void d082();
    virtual void d083();
    virtual void d084();
    virtual void d085();
    virtual void d086();
    virtual void d087();
    virtual void d088();
    virtual void d089();
    virtual void d090();
    virtual void d091();
    virtual void d092();
    virtual void d093();
    virtual void d094();
    virtual void d095();
    virtual void d096();
    virtual void d097();
    virtual void d098();
    virtual void d099();
    virtual void d100();
    virtual void d101();
    virtual void d102();
    virtual void d103();
    virtual void d104();
    virtual void d105();
    virtual void d106();
    virtual void d107();
    virtual void d108();
    virtual void d109();
    virtual void d110();
    virtual void d111();
    virtual void d112();
    virtual void d113();
    virtual void d114();
    virtual void d115();
    virtual ModelOps* v1d0();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual NiPoint3* v1f4();
};

class ModelOps
{
  public:
    CtlV* GetObject3D();
};
class MgrX
{
  public:
    NiControllerSequence* FUN_0047a520(const NiFixedString&);
    void FUN_0047aa40(bool);
    bool FUN_0047aab0(NiControllerSequence*, int, int, float, float, int);
};
class SeqX
{
  public:
    int FUN_008041a0();
    void FUN_0098adb0(float);
};
class DoorX
{
  public:
    void* FUN_00407820();
    unsigned int FUN_00407840();
};
class Door2
{
  public:
    bool FUN_00518080();
};
class SoundH
{
  public:
    unsigned int FUN_0084e3a0(unsigned int);
};
class BSAudio;
class BSAudioSoundHandle;
class BSAudioS_
{
  public:
    static BSAudio* GetSingleton();
};
class BSAudio2
{
  public:
    BSAudioSoundHandle FUN_00ad73b0(unsigned int);
};
class TaskQ2
{
  public:
    void QueueTaskIfPresent(void*);
};
class RefX
{
  public:
    void SetQuickKeysEnabled(int);
};
class OCF
{
  public:
    virtual void v0(TESObjectREFR*, TESObjectREFR*);
    virtual void v1(TESObjectREFR*, TESObjectREFR*);
    virtual bool v2();
};
class FUN_00572d50_shell
{
  public:
    void FUN_00572d50(int);
};
class FUN_00572db0_shell
{
  public:
    void FUN_00572db0(int);
};
struct TSETTING_VALUE
{
    unsigned char b;
};
class SettingX
{
  public:
    TSETTING_VALUE* Bool();
};
extern SettingX DAT_011c4c64;

class BSAudioSoundHandle
{
  public:
    int m0;
    unsigned char m4;
    int m8;
    BSAudioSoundHandle();
    ~BSAudioSoundHandle();
    void FUN_00418890(const void*);
    bool Play(bool);
    bool SetPos(float, float, float);
};

extern TESObjectREFR* _g_thePlayer;
OCF* GetOpenCloseForm(TESBoundObject*);
bool FUN_008c7aa0();
void FUN_00c6a270(NiAVObject*, bool, bool, int);
void FUN_00c69ee0(void*, bool, bool);
NiFixedString& FUN_0047a500();
NiFixedString& FUN_0047a510();

// @fnv 0x0047a560
void FUN_0047a560(TESObjectREFR* apRefr, TESObjectREFR* apActor, BGSOpenCloseForm* apForm)
{
    if (!apRefr)
        return;
    bool bFlag = false;
    if (((RefV*)apRefr)->v1d0())
    {
        if (((RefV*)apRefr)->v1d0()->GetObject3D())
        {
            CtlV* p3d = ((RefV*)apRefr)->v1d0()->GetObject3D();
            NiAVObject* pAV = (NiAVObject*)FUN_00653270(&DAT_011f36ac, (NiProperty*)p3d);
            if (pAV)
            {
                NiControllerSequence* pSeqA = ((MgrX*)pAV)->FUN_0047a520(FUN_0047a500());
                NiControllerSequence* pSeqB = ((MgrX*)pAV)->FUN_0047a520(FUN_0047a510());
                if (pSeqA && pSeqB)
                {
                    bFlag = true;
                    if (((SeqX*)pSeqA)->FUN_008041a0() != 1 && ((SeqX*)pSeqB)->FUN_008041a0() != 1)
                    {
                        NiControllerSequence* p2c;
                        SoundH* p28 = 0;
                        TESObjectDOOR* pPathNodeDoor = dynamic_cast<TESObjectDOOR*>(apForm);
                        if (!apRefr->GetAction(ACTION_OPEN))
                        {
                            if (pPathNodeDoor)
                                p28 = (SoundH*)((DoorX*)pPathNodeDoor)->FUN_00407820();
                            p2c = pSeqA;
                            ((FUN_00572d50_shell*)apRefr)->FUN_00572d50(4);
                        }
                        else
                        {
                            if (pPathNodeDoor)
                                p28 = (SoundH*)((DoorX*)pPathNodeDoor)->FUN_00407840();
                            p2c = pSeqB;
                            ((FUN_00572db0_shell*)apRefr)->FUN_00572db0(4);
                        }
                        if (!((SettingX*)&DAT_011c4c64)->Bool()->b && apActor && ((RefV*)apActor)->v100() &&
                            apActor != _g_thePlayer && ((RefV*)apRefr)->v1d0())
                        {
                            bool bSkip = true;
                            if (apRefr->GetObjectReference()->GetFormType() == ENUM_FORM_ID_DOOR_ID)
                            {
                                TESBoundObject* pObj = apRefr->GetObjectReference();
                                if (((Door2*)pObj)->FUN_00518080())
                                    bSkip = false;
                            }
                            if (bSkip)
                            {
                                void* pNi = ((RefV*)apRefr)->v1d0();
                                if (FUN_008c7aa0())
                                {
                                    ((TaskQ2*)TaskQueueInterface::GetSingleton())->QueueTaskIfPresent(pNi);
                                }
                                else
                                {
                                    FUN_00c6a270((NiAVObject*)pNi, 1, 1, 0);
                                    FUN_00c69ee0(pNi, 1, 1);
                                }
                            }
                        }
                        ((MgrX*)pAV)->FUN_0047aa40(true);
                        ((MgrX*)pAV)->FUN_0047aab0(p2c, 0, 0, 1.0f, 0.0f, 0);
                        p2c->FUN_0098adb0(-DAT_0101ab70);
                        if (p28)
                        {
                            BSAudioSoundHandle h;
                            if (apActor == _g_thePlayer)
                            {
                                h.FUN_00418890(&((BSAudio2*)BSAudioS_::GetSingleton())
                                                    ->FUN_00ad73b0(p28->FUN_0084e3a0(0x80000121u)));
                            }
                            else
                            {
                                h.FUN_00418890(
                                    &((BSAudio2*)BSAudioS_::GetSingleton())->FUN_00ad73b0(p28->FUN_0084e3a0(0x102)));
                                NiPoint3 pt = *((RefV*)apRefr)->v1f4();
                                h.SetPos(pt.x, pt.y, pt.z);
                            }
                            h.Play(false);
                        }
                        ((ExtraDataList_r0047a560*)apRefr->GetExtraData())->CallExtraDataListMethod36(apActor);
                        ((RefV*)apRefr)->v048(0x80000000u);
                        if (p2c == pSeqA && apActor == _g_thePlayer)
                        {
                            OCF* pOCF = GetOpenCloseForm(apRefr->GetObjectReference());
                            if (pOCF && pOCF->v2())
                                ((RefX*)_g_thePlayer)->SetQuickKeysEnabled(1);
                        }
                    }
                }
            }
        }
    }
    if (!bFlag)
    {
        bool bOpen = false;
        switch (BGSOpenCloseForm::GetOpenState(apRefr))
        {
        case BGSOpenCloseForm::OPEN:
        case BGSOpenCloseForm::OPENING:
            ((FUN_00572db0_shell*)apRefr)->FUN_00572db0(4);
            break;
        default:
            bOpen = true;
            ((FUN_00572d50_shell*)apRefr)->FUN_00572d50(4);
            break;
        }
        OCF* pOCF2 = GetOpenCloseForm(apRefr->GetObjectReference());
        if (pOCF2)
        {
            if (bOpen)
                pOCF2->v0(apRefr, apActor);
            else
                pOCF2->v1(apRefr, apActor);
        }
    }
}
