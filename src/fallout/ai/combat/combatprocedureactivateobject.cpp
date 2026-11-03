// fallout/ai/combat/combatprocedureactivateobject.cpp: CombatProcedureActivateObject, CombatProcedure, C_Ranged, ScriptableFormForward and more (14 functions)

#include "CombatProcedure.h"

// @fnv 0x006ecd40
void CombatProcedure::Initialize(CombatController* apCombatController)
{
    m_pCombatController = apCombatController;
}

struct CombatProcedureActivateObject : CombatProcedure
{
    int FUN_006e4ba0();
};

// @fnv 0x006e4ba0
int CombatProcedureActivateObject::FUN_006e4ba0()
{
    return 8;
}

struct TESObjectREFR;
struct TESBoundObject;
struct TESObjectREFRHelper
{
    void SetTargetingState(int);
};
struct FUN_009ca680_base
{
    CombatController* m_pCombatController;
    int eStatus;
    const char* m_pcProcedureName;
    FUN_009ca680_base();
    virtual ~FUN_009ca680_base();
};
struct FUN_009ca5f0 : FUN_009ca680_base
{
    TESObjectREFR* m_pReference;
    TESBoundObject* m_pBaseObject;
    char m_cValue24;
    FUN_009ca5f0(TESObjectREFR*, TESBoundObject*);
    virtual ~FUN_009ca5f0();
};
// Stores both pointers, sets m_cValue24 to zero, and calls SetTargetingState(1) when m_pReference is non-null.
// @fnv 0x009ca5f0
FUN_009ca5f0::FUN_009ca5f0(TESObjectREFR* apTargetRef, TESBoundObject* apBoundObject)
{
    m_pReference = apTargetRef;
    m_pBaseObject = apBoundObject;
    m_cValue24 = 0;
    if (m_pReference)
        ((TESObjectREFRHelper*)m_pReference)->SetTargetingState(1);
}

struct CPStandIn009ca710
{
    void FUN_009ca740();
    void* Destroy(unsigned int flags);
};

// Calls FUN_009ca740, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x009ca710
void* CPStandIn009ca710::Destroy(unsigned int flags)
{
    FUN_009ca740();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_009ca6c0_shell
{
    void FUN_009ca6c0();
};
extern int DAT_0109082c;

struct CPStandIn009ca740 : FUN_009ca6c0_shell
{
    int* vptr;
    void FUN_009ca740();
};

// @fnv 0x009ca740
void CPStandIn009ca740::FUN_009ca740()
{
    vptr = &DAT_0109082c;
    FUN_009ca6c0();
}

#include <string.h>
#include <stdlib.h>
class S_BaseProcess;
class S_Idle;
class S_HY;
class S_FileEntry;
class S_FileSub;
class S_Tile;
class S_TileProv;

class Actor
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual S_Idle* GetIdle();
    S_BaseProcess* GetProcess();
    bool FUN_00493bb0();
};

class S_BaseProcess
{
  public:
    int GetProcessLevel();
    bool FUN_008ff0b0(Actor* actor, unsigned int refid, void* target);
};

class S_FileSub
{
  public:
    virtual const char* v0();
    virtual const char* v1();
    virtual const char* v2();
    virtual const char* v3();
    virtual const char* v4();
    virtual const char* v5();
};

class S_FileEntry
{
  public:
    char pad[0x18];
    S_FileSub sub;
};

class S_Idle
{
  public:
    bool FUN_004985f0();
    bool HasIdleForm(void* form);
    bool FUN_00498f80();
    S_FileEntry* GetFileEntry();
    S_HY* FUN_00921e30();
    float FUN_00453700();
};

class S_HY
{
  public:
    float FUN_004eec60(float v);
};

class S_Tile
{
  public:
    void* GetActionAtIndex(int i);
    void FUN_0099a780(int obj);
    void EvaluateWeaponScores();
};

class S_TileProv
{
  public:
    S_Tile* FUN_00586150();
};

class S_REFR
{
  public:
    unsigned int GetRefID();
    int FUN_00575610(int obj);
    bool Activate(Actor* actor, bool a2, void* bound, int count);
};

class C_Ranged
{
  public:
    void* vt;
    S_TileProv* prov;
    int pad8;
    int padc;
    S_REFR* target;
    unsigned int refID;
    signed char status;
    void FUN_009ca760();
    void FUN_009caac0(const char* msg);
    Actor* FUN_00996de0();
    void SetState();
};

// Checks the target and actor idle state, updates status, activates the target reference, and may evaluate weapon scores.
// @fnv 0x009ca760
void C_Ranged::FUN_009ca760()
{
    if (this->target == 0)
    {
        this->FUN_009caac0("Targeted reference is NULL for some reason");
        return;
    }
    Actor* actor = this->FUN_00996de0();
    S_Idle* idle = actor->GetIdle();
    if (actor->GetProcess()->GetProcessLevel() == 0 && idle != 0)
    {
        if (this->status == 0)
        {
            if (idle && (!idle->FUN_004985f0() || idle->HasIdleForm(0)))
                return;
            S_BaseProcess* proc = actor->GetProcess();
            bool ok = proc->FUN_008ff0b0(actor, this->target->GetRefID(), this->target);
            if (ok)
            {
                this->status = 1;
                return;
            }
            else
            {
                this->status = -1;
            }
        }
        else if (this->status == 1 || this->status == 3)
        {
            if (idle && (!idle->FUN_004985f0() || idle->FUN_00498f80()))
            {
                if (this->status == 1)
                {
                    S_FileEntry* fe = idle->GetFileEntry();
                    if (fe)
                    {
                        const char* str = fe->sub.v5();
                        if (str)
                        {
                            S_HY* hy;
                            float val = 0.0f;
                            const char* b = strrchr(str, '_');
                            if (b)
                                val = (float)atof(b + 1);
                            hy = idle->FUN_00921e30();
                            if (!hy || val < hy->FUN_004eec60(idle->FUN_00453700()))
                                this->status = 2;
                        }
                    }
                }
                if (this->status != 2)
                    return;
            }
        }
    }
    if (this->status != 3)
    {
        S_Tile* tile = this->prov->FUN_00586150();
        if (this->target->GetRefID() != this->refID)
        {
            unsigned int cnt;
            int arr[5];
            memset(arr, 0, sizeof(arr));
            cnt = 0;
            for (unsigned int i = 0; i < 5; i++)
            {
                int* item = (int*)tile->GetActionAtIndex(i);
                if (item && *item == (int)this->target)
                {
                    arr[cnt] = item[1];
                    cnt++;
                }
            }
            tile->FUN_0099a780((int)this->target);
            for (unsigned int j = 0; j < cnt; j++)
            {
                int c = this->target->FUN_00575610(arr[j]);
                if (c)
                {
                    if (c < 0)
                        c = -c;
                    this->target->Activate(actor, 1, (void*)arr[j], c);
                }
            }
        }
        else
        {
            tile->FUN_0099a780((int)this->target);
            this->target->Activate(actor, 1, 0, 1);
        }
        if (!actor->FUN_00493bb0())
            return;
        tile->EvaluateWeaponScores();
    }
    if (this->status == 2)
    {
        this->status = 3;
        return;
    }
    this->SetState();
}

struct FUN_009caac0_shell
{
    void __thiscall FUN_009caac0(int arg1);
};

// @fnv 0x009caac0
void __thiscall FUN_009caac0_shell::FUN_009caac0(int arg1)
{
    ((int*)this)[3] = arg1;
    ((int*)this)[2] = 1;
}

struct CPStandIn009caae0
{
    int field0;
    int field4;
    int mState;
    void SetState();
};

// @fnv 0x009caae0
void CPStandIn009caae0::SetState()
{
    mState = 2;
}

namespace fnv_009cab00 {
struct CombatProcedureAttackRanged
{
    void FUN_009caac0(char const*);
};

struct CombatProcedureBase
{
    char pad[0x10];
};

struct CombatProcedureActivateObject : CombatProcedureBase
{
    TESObjectREFR* m_pReference;  // +0x10

    void FUN_009cab00(TESObjectREFR* apRef);
};

// If m_pReference matches apRef, clears it and passes a message string to FUN_009caac0.
// @fnv 0x009cab00
void CombatProcedureActivateObject::FUN_009cab00(TESObjectREFR* apRef)
{
    if (m_pReference == apRef)
    {
        m_pReference = 0;
        ((CombatProcedureAttackRanged*)this)->FUN_009caac0("Targeted reference pointer was cleared");
    }
}
}  // namespace fnv_009cab00

class NiPoint3
{
  public:
    float x, y, z;
};
class TESForm
{
  public:
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
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();
    virtual void Unk_3B();
    virtual void Unk_3C();
    virtual void Unk_3D();
    virtual void Unk_3E();
    virtual void Unk_3F();
    virtual void Unk_40();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual void Unk_4A();
    virtual void Unk_4B();
    virtual const char* GetEditorName();
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void Unk_55();
    virtual void Unk_56();
    virtual void Unk_57();
    virtual void Unk_58();
    virtual void Unk_59();
    virtual void Unk_5A();
    virtual void Unk_5B();
    virtual void Unk_5C();
    virtual void Unk_5D();
    virtual void Unk_5E();
    virtual void Unk_5F();
    virtual void Unk_60();
    virtual void Unk_61();
    virtual void Unk_62();
    virtual void Unk_63();
    virtual void Unk_64();
    virtual void Unk_65();
    virtual void Unk_66();
    virtual void Unk_67();
    virtual void Unk_68();
    virtual void Unk_69();
    virtual void Unk_6A();
    virtual void Unk_6B();
    virtual void Unk_6C();
    virtual void Unk_6D();
    virtual void Unk_6E();
    virtual void Unk_6F();
    virtual void Unk_70();
    virtual void Unk_71();
    virtual void Unk_72();
    virtual void Unk_73();
    virtual void Unk_74();
    virtual void Unk_75();
    virtual void Unk_76();
    virtual void Unk_77();
    virtual void Unk_78();
    virtual void Unk_79();
    virtual void Unk_7A();
    virtual void Unk_7B();
    virtual void Unk_7C();
    virtual NiPoint3* GetPos();
    unsigned int GetFormID();
};
class TESObjectREFR : public TESForm
{
  public:
    int FUN_00474cb0();
    const char* GetFullName();
};
struct FUN_009cab30_TextOutput
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Print(int aiX, int aiY, const char* apFormat, ...);
};
struct FUN_009cab30_shell : public CombatProcedure
{
    TESObjectREFR* pTarget;
    int iUnk14;
    char cAnimState;
    void FUN_009cab30(FUN_009cab30_TextOutput* apOutput, int aiX, int aiY);
};
// Prints the current animation state and, if pTarget is set, its name, form ID, and position to apOutput at aiX, aiY.
// @fnv 0x009cab30
void FUN_009cab30_shell::FUN_009cab30(FUN_009cab30_TextOutput* apOutput, int aiX, int aiY)
{
    switch (cAnimState)
    {
    case -1:
        apOutput->Print(aiX, aiY, "NO ANIM");
        break;
    case 1:
        apOutput->Print(aiX, aiY, "ANIM PLAYING");
        break;
    case 2:
        apOutput->Print(aiX, aiY, "ANIM GRABBING");
        break;
    case 3:
        apOutput->Print(aiX, aiY, "ANIM FINISHING PLAYING");
        break;
    }
    if (pTarget)
    {
        NiPoint3 kPos = *pTarget->GetPos();
        apOutput->Print(aiX, aiY, "Target: '%s' (%08X) - Position: (%.02f,%.02f,%.02f)",
                        pTarget->FUN_00474cb0() ? pTarget->GetEditorName() : pTarget->GetFullName(),
                        pTarget->GetFormID(), kPos.x, kPos.y, kPos.z);
    }
}

struct BGSSaveFormBuffer
{
    void SerializeFormData(void*, int);
    void SaveData(void*, int, int);
};
struct TESObjectREFR;
struct TESBoundObject;
struct FUN_009cacb0_shell : CombatProcedure
{
    TESObjectREFR* m_pReference;
    TESBoundObject* m_pBaseObject;
    char bFlag;
    void SaveGame(BGSSaveFormBuffer*);
    void FUN_009cacb0(BGSSaveFormBuffer*);
};
// Saves the combat procedure state by calling SaveGame, serializing m_pReference and m_pBaseObject, and saving bFlag.
// @fnv 0x009cacb0
void FUN_009cacb0_shell::FUN_009cacb0(BGSSaveFormBuffer* apSaveBuffer)
{
    SaveGame(apSaveBuffer);
    apSaveBuffer->SerializeFormData(m_pReference, 0);
    apSaveBuffer->SerializeFormData(m_pBaseObject, 0);
    apSaveBuffer->SaveData(&bFlag, 1, 0);
}

struct CPStandIn004534f0
{
    void FUN_004534f0(unsigned int);
};
struct CPStandIn00564db0
{
    void FUN_00564db0(int);
};
extern "C" TESForm* __cdecl LookupFormByID(TESObjectREFR*);

struct FUN_009cad70_shell : public CombatProcedure
{
    TESObjectREFR* m_pReference;
    void FUN_009cad70(unsigned int);
};

// Calls FUN_004534f0 with arg, assigns the cast result of LookupFormByID to m_pReference, then calls FUN_00564db0(1) if non-null.
// @fnv 0x009cad70
void FUN_009cad70_shell::FUN_009cad70(unsigned int arg)
{
    ((CPStandIn004534f0*)this)->FUN_004534f0(arg);
    m_pReference = m_pReference ? dynamic_cast<TESObjectREFR*>(LookupFormByID(m_pReference)) : 0;
    if (m_pReference)
        ((CPStandIn00564db0*)m_pReference)->FUN_00564db0(1);
}

class TESScriptableForm
{
  public:
    void Initialize(unsigned int);
};

struct ScriptableFormForward : public TESScriptableForm
{
    void FUN_009cc4b0(unsigned int a);
};

// @fnv 0x009cc4b0
void ScriptableFormForward::FUN_009cc4b0(unsigned int auiInitData)
{
    TESScriptableForm::Initialize(auiInitData);
}

struct BGSLoadFormBuffer
{
    void ReadFormIdentifier(void*);
    void ReadTypedData(void*, int);
};
struct BGSLoadGameBuffer
{
    unsigned int ReadFormIdentifier();
};
using ::TESBoundObject;
class TESBoundObject
{
  public:
    virtual void v0();
};
::TESForm* __cdecl LookupFormByID(unsigned int);
struct ActivateObjectLoadView : CombatProcedure
{
    void* m_pReference;
    TESBoundObject* m_pBaseObject;
    char bFlag;
    void FUN_00996ef0(BGSLoadFormBuffer*);
    void FUN_009cad00(BGSLoadFormBuffer*);
};
// Reads the activate object load view from a form buffer, loading the reference, base object, and flag.
// @fnv 0x009cad00
void ActivateObjectLoadView::FUN_009cad00(BGSLoadFormBuffer* apBuffer)
{
    FUN_00996ef0(apBuffer);
    apBuffer->ReadFormIdentifier(&m_pReference);
    m_pBaseObject =
        dynamic_cast< ::TESBoundObject*>(LookupFormByID(((BGSLoadGameBuffer*)apBuffer)->ReadFormIdentifier()));
    apBuffer->ReadTypedData(&bFlag, 1);
}
