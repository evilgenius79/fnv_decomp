
// src/staging/blk_00920000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct ObjB
{
    void FUN_004b0ef0();
};

struct FUN_0092c890_class
{
    void FUN_0092c890();
};

// @fnv 0x0092c890
void FUN_0092c890_class::FUN_0092c890()
{
    if (reinterpret_cast<int*>(this)[0])
        reinterpret_cast<ObjB*>(reinterpret_cast<int*>(this)[0])->FUN_004b0ef0();
}

struct bhkCharacterController
{
    int __fastcall FUN_005c0880(char*);
};
int __fastcall FUN_005c0880(char*);
// @fnv 0x009306b0
bool __fastcall FUN_009306b0(bhkCharacterController* self)
{
    return FUN_005c0880(reinterpret_cast<char*>(self)) == 5;
}

struct FUN_0042ed70_
{
    void FUN_0042ed70();
};

struct XActor
{
    FUN_0042ed70_* GetExtra();
    void FUN_00934430();
};

void FUN_0042ed70_::FUN_0042ed70()
{}

FUN_0042ed70_* XActor::GetExtra()
{
    return 0;
}

// @fnv 0x00934430
void XActor::FUN_00934430()
{
    GetExtra()->FUN_0042ed70();
}

struct FUN_00935a10_Class
{
    void* p;
    int i;
    float f;
    void* SetValues(void* p0, int i0, float f0);
};

// Stores the three arguments into the object's fields and returns the object pointer.
// @fnv 0x00935a10
void* FUN_00935a10_Class::SetValues(void* pValue, int iValue, float fValue)
{
    p = pValue;
    i = iValue;
    f = fValue;
    return this;
}

struct FUN_00937d30_cls
{
    unsigned char m_kPointA;
    unsigned char m_kPointB;
    unsigned char m_iThirdValue;
    unsigned char m_iFourthElementInteger;
    float m_usTrailingValue;
    FUN_00937d30_cls* FUN_00937d30();
};

// @fnv 0x00937d30
FUN_00937d30_cls* FUN_00937d30_cls::FUN_00937d30()
{
    m_kPointA = 0;
    m_usTrailingValue = 0.0f;
    return this;
}

struct ActorValueModifierList
{
    void RemoveAllModifiers();
    void FUN_00937d50(int a);
};

// @fnv 0x00937d50
void ActorValueModifierList::FUN_00937d50(int aiUnused)
{
    RemoveAllModifiers();
}

extern int DAT_011e0750;

struct FUN_00937f40_Class
{
    void** m_Array;
    void FreeArrayItems();
};

// If DAT_011e0750 is nonzero and m_Array is set, deletes each non-null element, deletes the array, and clears m_Array.
// @fnv 0x00937f40
void FUN_00937f40_Class::FreeArrayItems()
{
    void* pArray;
    void* pItem2;
    int i;
    if (DAT_011e0750 != 0 && m_Array != 0)
    {
        for (i = 0; i < DAT_011e0750; i++)
        {
            if (m_Array[i] != 0)
            {
                pItem2 = m_Array[i];
                ::operator delete(pItem2);
            }
        }
        pArray = m_Array;
        ::operator delete(pArray);
        m_Array = 0;
    }
}

struct TaskQueueInterface
{
    void SetTaskFlagDWord(bool, unsigned int);
    void SetEnabledFlag(bool);
};

void TaskQueueInterface::SetTaskFlagDWord(bool, unsigned int)
{}

// @fnv 0x00938160
void TaskQueueInterface::SetEnabledFlag(bool enabled)
{
    SetTaskFlagDWord(enabled, 0x8000000);
}

struct FUN_0093a5d0_class
{
    unsigned char __thiscall GetByteAt798();
};
// @fnv 0x0093a5d0
unsigned char __thiscall FUN_0093a5d0_class::GetByteAt798()
{
    return ((unsigned char*)this)[0x798];
}

// @fnv 0x0093a640
char __fastcall FUN_0093a640(int param_1)
{
    return *(char*)(param_1 + 0x799);
}

struct FUN_0093c1e0_Class
{
    bool IsFlag2Set();
};

// @fnv 0x0093c1e0
bool FUN_0093c1e0_Class::IsFlag2Set()
{
    return ((signed char)*((char*)this + 0x66d) & 2) != 0;
}

extern float DAT_011ac3a4;
extern float DAT_011ac3a8;

// @fnv 0x0093e750
void CopyGlobalFloat()
{
    DAT_011ac3a8 = DAT_011ac3a4;
}

struct ObjA
{
    void FUN_0092c870();
};
struct FUN_0092c900_shell
{
    ObjB* p;
    FUN_0092c900_shell* AssignPointer(FUN_0092c900_shell* src);
};
// @fnv 0x0092c900
FUN_0092c900_shell* FUN_0092c900_shell::AssignPointer(FUN_0092c900_shell* apSource)
{
    if (p != apSource->p)
    {
        if (p)
            p->FUN_004b0ef0();
        p = apSource->p;
        if (p)
            ((ObjA*)p)->FUN_0092c870();
    }
    return this;
}

struct M94
{
    ~M94();
};
struct FUN_00906fe0
{
    ~FUN_00906fe0();
};
struct FUN_0092c950
{
    virtual ~FUN_0092c950();
};
struct FUN_0092ca00 : FUN_0092c950
{
    char m_data[0xb4];
    M94 m_m94;
    ~FUN_0092ca00();
};
// Destructor for FUN_0092ca00; empty body, base and member destructors run automatically.
// @fnv 0x0092ca00
FUN_0092ca00::~FUN_0092ca00()
{}

struct TESForm
{
    virtual void v0();
    virtual bool IsEnabled();
};
struct _Dummy_004bc4a0
{
    void SetAccumulate(bool b);
};
struct FUN_00936aa0_shell
{
    void FUN_00936aa0(bool b);
};
TESForm* __cdecl _ref_004839c0(int id);
// Looks up a TESForm by id; if it exists and IsEnabled returns true, calls SetAccumulate(true) and FUN_00936aa0(b) on it.
// @fnv 0x00936ac0
void FUN_00936ac0(int aiFormId, bool b)
{
    int iFormId = aiFormId;
    TESForm* p = _ref_004839c0(iFormId);
    if (p && ((bool(__thiscall*)(TESForm*))(*(void***)p)[63])(p))
    {
        TESForm* q = p;
        if (q)
        {
            ((_Dummy_004bc4a0*)q)->SetAccumulate(true);
            ((FUN_00936aa0_shell*)q)->FUN_00936aa0(b);
        }
    }
}

struct ListX
{
    ~ListX();
};
struct FUN_00937030_Class : public ListX
{
    ~FUN_00937030_Class();
};
// @fnv 0x00937030
FUN_00937030_Class::~FUN_00937030_Class()
{
    ((ActorValueModifierList*)this)->RemoveAllModifiers();
}

struct FUN_0055a2b0_Class
{
    void __thiscall FUN_006208d0();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};

// Calls FUN_006208d0, then deletes this if bit 0 of flags is set, and returns this.
// @fnv 0x0093a5a0
void* __thiscall FUN_0055a2b0_Class::DestroyIfFlagged(unsigned int flags)
{
    FUN_006208d0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct TESResponse
{
    TESResponse* GetNext();
};
// Returns 0 for a null response, otherwise counts the response and its chained GetNext() responses.
// @fnv 0x009369d0
int __fastcall GetResponseCount(TESResponse* apResponse)
{
    if (!apResponse)
        return 0;
    TESResponse* next;
    {
        int count = 1;
        next = apResponse->GetNext();
        while (next)
        {
            count = count + 1;
            next = next->GetNext();
        }
        return count;
    }
}

struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
    unsigned int FUN_00865f20();
    void FUN_00865ff0(int, unsigned int);
};
struct Node_006815c0
{
    void** _ref_006815c0();
};
struct Item_00937b50
{
    char a;
    int b;
};
struct FUN_00937b50_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    Item_00937b50*** m_aiIndexedValues;
    void FUN_00937b50(BGSSaveFormBuffer* buf);
};
// @fnv 0x00937b50
void FUN_00937b50_cls::FUN_00937b50(BGSSaveFormBuffer* buf)
{
    unsigned int uiPos;
    int iCount = 0;
    uiPos = buf->FUN_00865f20();
    BSSimpleList<Item_00937b50*>* node = (BSSimpleList<Item_00937b50*>*)this;
    while (node)
    {
        Item_00937b50* item = (Item_00937b50*)*((Node_006815c0*)node)->_ref_006815c0();
        if (item)
        {
            buf->SaveData(item, 1, 0);
            buf->SaveData(&item->b, 4, 0);
            iCount++;
        }
        node = node->GetNext();
    }
    if (m_aiIndexedValues)
    {
        for (unsigned int i = 0; i < (unsigned int)DAT_011e0750; i++)
        {
            if ((*m_aiIndexedValues)[i])
            {
                buf->SaveData((*m_aiIndexedValues)[i], 1, 0);
                buf->SaveData(&(*m_aiIndexedValues)[i]->b, 4, 0);
                iCount++;
            }
        }
    }
    buf->FUN_00865ff0(iCount, uiPos);
}

struct NiAVObject
{
};
struct NiNode
{
    unsigned int GetNumChildren();
    NiAVObject* GetAt(unsigned int);
};
struct FUN_009380e0_shell
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual NiNode* FUN_009380e0_get();
};

void FUN_009380e0_rec(NiAVObject* obj);

// @fnv 0x009380e0
void FUN_009380e0(TaskQueueInterface* self)
{
    if (!self)
        return;
    self->SetEnabledFlag(true);
    if (((FUN_009380e0_shell*)self)->FUN_009380e0_get())
    {
        NiNode* node = ((FUN_009380e0_shell*)self)->FUN_009380e0_get();
        for (unsigned int i = 0; i < node->GetNumChildren(); i++)
        {
            NiAVObject* child = node->GetAt(i);
            if (child)
                FUN_009380e0_rec(child);
        }
    }
}

struct P09H
{
    int GetReferenceType();
};
struct FUN_008e56b0_cls
{
    void ClearNode();
};
void* __cdecl GetObjectFromNode(NiAVObject*, bool, int);

// @fnv 0x00930870
bool __fastcall FUN_00930870(Actor* pActor)
{
    bool result;
    NiAVObject* anim;

    if (*(TESResponse**)((char*)pActor + 0x68) != 0)
    {
        if (((TESResponse*)*(void**)((char*)pActor + 0x68))->GetNext() == 0)
        {
            ((FUN_008e56b0_cls*)*(void**)((char*)pActor + 0x68))->ClearNode();
        }
    }
    result = (*(bool(__thiscall*)(Actor*))((*(void***)pActor)[0x2a0 / 4]))(pActor);
    anim = (NiAVObject*)((P09H*)pActor)->GetReferenceType();
    if (anim != 0)
    {
        GetObjectFromNode(anim, true, 0);
        result = result | 1;
    }
    return result;
}

struct FUN_00cbc510
{
    int __thiscall Call(int);
};
struct FUN_00933810
{
    int __thiscall Method();
};
// Calls Call on the object stored at this+0x3ec, passing the value at this+0x3f0, and returns its result.
// @fnv 0x00933810
int FUN_00933810::Method()
{
    int result = ((FUN_00cbc510*)*((int*)((char*)this + 0x3ec)))->Call(*(int*)((char*)this + 0x3f0));
    return result;
}

namespace fnv_00935cc0 {
enum PTYPE
{
    PTYPE_COUNT
};

struct TESPackage
{
    PTYPE GetPackType();
};

struct Actor
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
    virtual bool IsEnabled();
};

struct FUN_009344a0_shell
{
    TESPackage* GetCurrentPackage();
};

// @fnv 0x00935cc0
void FUN_00935cc0(int param_1)
{
    int form = param_1;
    TESForm* pForm = _ref_004839c0(form);

    if (pForm != 0)
    {
        if (reinterpret_cast<Actor*>(pForm)->IsEnabled())
        {
            Actor* actor = reinterpret_cast<Actor*>(pForm);

            if (actor != 0)
            {
                reinterpret_cast<unsigned char*>(actor)[0x7f] = 1;

                if (reinterpret_cast<unsigned char*>(actor)[0x7d])
                {
                    reinterpret_cast<unsigned char*>(actor)[0x7c] = 1;
                }

                TESPackage* currentPackage = reinterpret_cast<FUN_009344a0_shell*>(actor)->GetCurrentPackage();
                TESPackage* dialoguePackage = 0;

                if (currentPackage != 0 && currentPackage->GetPackType() == 28)
                {
                    dialoguePackage = currentPackage;
                }

                if (dialoguePackage != 0)
                {
                    if (reinterpret_cast<unsigned char*>(actor)[0x7f])
                    {
                        *reinterpret_cast<float*>(reinterpret_cast<char*>(dialoguePackage) + 0x90) =
                            0.30000001192092896f;
                    }
                    else
                    {
                        *reinterpret_cast<float*>(reinterpret_cast<char*>(dialoguePackage) + 0x90) = 20.0f;
                    }
                }
            }
        }
    }
}
}  // namespace fnv_00935cc0

struct FUN_009369a0_shell
{
    TESResponse* m_next;
    int FUN_009369a0();
};
// Returns the result of GetResponseCount on m_next, or 0 when m_next is null.
// @fnv 0x009369a0
int FUN_009369a0_shell::FUN_009369a0()
{
    return m_next ? GetResponseCount(m_next) : 0;
}

extern int DAT_01000000;
struct FUN_00456630_helper
{
    bool FUN_00456630(unsigned int);
};
struct FUN_00936fb0_shell
{
    void FUN_00936fb0();
};
// @fnv 0x00936fb0
void FUN_00936fb0_shell::FUN_00936fb0()
{
    ((FUN_00456630_helper*)this)->FUN_00456630((unsigned int)&DAT_01000000);
}

struct SL
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    SL();
};

struct FUN_00937000 : public SL
{
    unsigned char m_flag;
    int m_uiFilterValue;

    FUN_00937000();
};

// @fnv 0x00937000
FUN_00937000::FUN_00937000() : SL()
{
    m_uiFilterValue = 0;
    m_flag = 0;
}

struct FUN_00986500_shell
{
    void RemoveByTarget(int);
};
struct FUN_0093a660_class
{
    void __thiscall FUN_0093a660(int apActor);
};
// If the pointer at this+0xd64 is non-null, forwards apActor to its RemoveByTarget method.
// @fnv 0x0093a660
void FUN_0093a660_class::FUN_0093a660(int apActor)
{
    if (*(void**)((char*)this + 0xd64) == 0)
        return;
    ((FUN_00986500_shell*)*(void**)((char*)this + 0xd64))->RemoveByTarget(apActor);
}

struct GameTimerRecord
{
    void SetGlobalTimeMultiplier(float, bool);
};
struct FUN_0093e840_shell : GameTimerRecord
{
    void ApplyGlobalTimeMultiplier();
};
// @fnv 0x0093e840
void FUN_0093e840_shell::ApplyGlobalTimeMultiplier()
{
    SetGlobalTimeMultiplier(DAT_011ac3a8, false);
}

struct Vec3_00921e00
{
    int m_uiX;
    int m_uiY;
    int m_uiZ;
};

extern Vec3_00921e00 g_011f426c;

struct FUN_00921e00_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Vec3_00921e00 m_pos;
    void CopyGlobalPosition();
};

// Copies the global position g_011f426c into the m_pos field of this object.
// @fnv 0x00921e00
void FUN_00921e00_cls::CopyGlobalPosition()
{
    m_pos = g_011f426c;
}

struct VirtualElement
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};
struct StateObject
{
    VirtualElement* FUN_00933810();
};
struct OwnerObject
{
    StateObject* FUN_009306d0();
    bool FUN_009337b0();
};
// Returns true if the state object obtained from FUN_009306d0 has a virtual element whose v3() equals 2.
// @fnv 0x009337b0
bool OwnerObject::FUN_009337b0()
{
    StateObject* pointer;
    bool result = false;
    pointer = FUN_009306d0();
    if (pointer && pointer->FUN_00933810())
    {
        if (pointer->FUN_00933810()->v3() == 2)
        {
            result = true;
        }
    }
    return result;
}

// FUN_00934450: forwards to m_68 virtual slots 0x230 (with arg) then 0x244.
struct FUN_00934450_Obj68
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
    virtual void v140(int a1, struct FUN_00934450_cls* self);
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
};

struct FUN_00934450_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    FUN_00934450_Obj68* m_68;
    void FUN_00934450(int a1, int a2, int a3);
};

// @fnv 0x00934450
void FUN_00934450_cls::FUN_00934450(int a1, int a2, int a3)
{
    m_68->v140(a1, this);
    m_68->v145();
}

struct NiRTTI
{
    int unk00;
};
extern NiRTTI DAT_011f36ac;

struct NiControllerSequence
{
    int unk00;
};

struct NiControllerManager
{
    NiControllerSequence* FUN_0047a520(const char* name);
    void FUN_0047b220(NiControllerSequence* seq, float f);
};
void __cdecl SetSequenceProgress(float f, NiControllerManager* mgr, NiControllerSequence* seq);

struct NiAVObj
{
    NiControllerManager* GetController(const NiRTTI* rtti);
};

struct Obj3D
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual NiAVObj* Get3D();
};

struct Proc
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
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
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
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
    virtual void v08a();
    virtual void v08b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
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
    virtual void v09a();
    virtual void v09b();
    virtual void v09c();
    virtual void v09d();
    virtual void v09e();
    virtual void v09f();
    virtual void v0a0();
    virtual void v0a1();
    virtual void v0a2();
    virtual void v0a3();
    virtual void v0a4();
    virtual void v0a5();
    virtual void v0a6();
    virtual void v0a7();
    virtual void v0a8();
    virtual void v0a9();
    virtual void v0aa();
    virtual void v0ab();
    virtual void v0ac();
    virtual void v0ad();
    virtual void v0ae();
    virtual void v0af();
    virtual void v0b0();
    virtual void v0b1();
    virtual void v0b2();
    virtual void v0b3();
    virtual void v0b4();
    virtual void v0b5();
    virtual void v0b6();
    virtual void v0b7();
    virtual void v0b8();
    virtual void v0b9();
    virtual void v0ba();
    virtual void v0bb();
    virtual void v0bc();
    virtual void v0bd();
    virtual void v0be();
    virtual void v0bf();
    virtual void v0c0();
    virtual void v0c1();
    virtual void v0c2();
    virtual void v0c3();
    virtual void v0c4();
    virtual void v0c5();
    virtual void v0c6();
    virtual void v0c7();
    virtual void v0c8();
    virtual void v0c9();
    virtual void v0ca();
    virtual void v0cb();
    virtual void v0cc();
    virtual void v0cd();
    virtual void v0ce();
    virtual void v0cf();
    virtual void v0d0();
    virtual void v0d1();
    virtual void v0d2();
    virtual void v0d3();
    virtual void v0d4();
    virtual void v0d5();
    virtual void v0d6();
    virtual void v0d7();
    virtual void v0d8();
    virtual void v0d9();
    virtual void v0da();
    virtual void v0db();
    virtual void v0dc();
    virtual void v0dd();
    virtual void v0de();
    virtual void v0df();
    virtual void v0e0();
    virtual void v0e1();
    virtual void v0e2();
    virtual void v0e3();
    virtual void v0e4();
    virtual void v0e5();
    virtual void v0e6();
    virtual void v0e7();
    virtual void v0e8();
    virtual void v0e9();
    virtual void v0ea();
    virtual void v0eb();
    virtual void v0ec();
    virtual void v0ed();
    virtual void v0ee();
    virtual void v0ef();
    virtual void v0f0();
    virtual void v0f1();
    virtual void v0f2();
    virtual void v0f3();
    virtual void v0f4();
    virtual void v0f5();
    virtual void v0f6();
    virtual void v0f7();
    virtual void v0f8();
    virtual void v0f9();
    virtual void v0fa();
    virtual void v0fb();
    virtual void v0fc();
    virtual void v0fd();
    virtual void v0fe();
    virtual void v0ff();
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
    virtual void v10a();
    virtual void v10b();
    virtual void v10c();
    virtual void v10d();
    virtual void v10e();
    virtual void v10f();
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
    virtual void v11a();
    virtual void v11b();
    virtual void v11c();
    virtual void v11d();
    virtual void v11e();
    virtual void v11f();
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
    virtual void v12a();
    virtual void v12b();
    virtual void v12c();
    virtual void v12d();
    virtual void v12e();
    virtual void v12f();
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
    virtual void v13a();
    virtual void v13b();
    virtual void v13c();
    virtual void v13d();
    virtual void v13e();
    virtual void v13f();
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
    virtual void v14a();
    virtual void v14b();
    virtual void v14c();
    virtual void v14d();
    virtual void v14e();
    virtual void v14f();
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
    virtual void v15a();
    virtual void v15b();
    virtual void v15c();
    virtual void v15d();
    virtual void v15e();
    virtual void v15f();
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
    virtual void v16a();
    virtual void v16b();
    virtual void v16c();
    virtual void v16d();
    virtual void v16e();
    virtual void v16f();
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
    virtual void v17a();
    virtual void v17b();
    virtual void v17c();
    virtual void v17d();
    virtual void v17e();
    virtual void v17f();
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
    virtual void v18a();
    virtual void v18b();
    virtual void v18c();
    virtual void v18d();
    virtual void v18e();
    virtual void v18f();
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
    virtual void v19a();
    virtual void v19b();
    virtual void v19c();
    virtual void v19d();
    virtual void v19e();
    virtual void v19f();
    virtual void v1a0();
    virtual void v1a1();
    virtual void v1a2();
    virtual void v1a3();
    virtual void v1a4();
    virtual void v1a5();
    virtual void v1a6();
    virtual void v1a7();
    virtual void v1a8();
    virtual void v1a9();
    virtual void v1aa();
    virtual void v1ab();
    virtual void v1ac();
    virtual void v1ad();
    virtual void v1ae();
    virtual void v1af();
    virtual void v1b0();
    virtual void v1b1();
    virtual void v1b2();
    virtual void v1b3();
    virtual void v1b4();
    virtual void v1b5();
    virtual void v1b6();
    virtual void v1b7();
    virtual void v1b8();
    virtual void v1b9();
    virtual void v1ba();
    virtual void v1bb();
    virtual void v1bc();
    virtual void v1bd();
    virtual void v1be();
    virtual void v1bf();
    virtual void v1c0();
    virtual void v1c1();
    virtual void v1c2();
    virtual void v1c3();
    virtual void v1c4();
    virtual void v1c5();
    virtual void v1c6();
    virtual void v1c7();
    virtual void v1c8();
    virtual void v1c9();
    virtual void v1ca();
    virtual void v1cb();
    virtual void v1cc();
    virtual void v1cd();
    virtual void v1ce();
    virtual void v1cf();
    virtual void v1d0();
    virtual void Func744(int);
    virtual void v1d2();
    virtual void Func74c(int);
};

struct RefrForm
{
    bool IsTalkingActivator();
    Obj3D* GetProgressValue();
    Proc* GetCurrentProcess();
};

struct FormX
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual bool IsReference();
};

struct GlobalState
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
    bool unk7c;
    bool unk7d;
};
extern GlobalState* DAT_011e0548;

struct GameSettingF
{
    float* Float();
};
extern GameSettingF DAT_011d32c4;
extern float DAT_011d951c;

FormX* __cdecl _ref_004839c0(unsigned int id);
const char* FUN_00935ef0();

// @fnv 0x00935d90
void FUN_00935d90(unsigned int id, bool b)
{
    unsigned int formID = id;
    FormX* form4 = _ref_004839c0(formID);
    if (form4 && form4->IsReference())
    {
        RefrForm* ref = (RefrForm*)form4;
        if (DAT_011e0548)
        {
            DAT_011e0548->unk7d = false;
            DAT_011e0548->unk7c = true;
            if (ref && ref->IsTalkingActivator())
            {
                Obj3D* obj5 = ref->GetProgressValue();
                NiControllerManager* mgr_2 = obj5->Get3D()->GetController(&DAT_011f36ac);
                if (mgr_2)
                {
                    NiControllerSequence* seq = mgr_2->FUN_0047a520(FUN_00935ef0());
                    if (seq)
                    {
                        SetSequenceProgress(0.0f, mgr_2, seq);
                        mgr_2->FUN_0047b220(seq, 0.0f);
                    }
                }
                {
                    Proc* proc = ref->GetCurrentProcess();
                    proc->Func744(0);
                }
                {
                    Proc* proc8 = ref->GetCurrentProcess();
                    proc8->Func74c(0);
                }
            }
        }
        if (!b)
        {
            DAT_011d951c = *DAT_011d32c4.Float();
        }
    }
    DAT_011e0548 = 0;
}

namespace fnv_00935ef0 {
extern int DAT_011c6268;
// @fnv 0x00935ef0
int __cdecl FUN_00935ef0()
{
    return DAT_011c6268;
}
}  // namespace fnv_00935ef0

struct PlayerVirtual
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
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual unsigned int GetCurrentValue();
};
extern PlayerVirtual* g_011dea3c;
struct GlobalScalar
{
    float* FUN_00403e20();
};
extern GlobalScalar g_011cd2f4;
struct FUN_00936ef0_Class
{
    float FUN_00572380(unsigned int value);
    int FUN_00936ef0();
};
// Reads the current value from g_011dea3c, converts it via FUN_00572380, and returns whether the result is at or below the value from g_011cd2f4.FUN_00403e20().
// @fnv 0x00936ef0
int FUN_00936ef0_Class::FUN_00936ef0()
{
    float currentValue = FUN_00572380(g_011dea3c->GetCurrentValue());
    int bAtOrBelow = currentValue <= *g_011cd2f4.FUN_00403e20();
    return bAtOrBelow;
}

struct FUN_0066e920_Class
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
};

extern int DAT_011e0618[77];
extern unsigned char DAT_011e074c;
extern int DAT_011e0750;

FUN_0066e920_Class* __cdecl GetActorValueInfo(int index);

// If not yet built, maps each of 0x4d objects whose unk44 bit 0 is set to a running count in DAT_011e0618, stores the total in DAT_011e0750 and sets DAT_011e074c.
// @fnv 0x00937fd0
void __cdecl FUN_00937fd0()
{
    if (!DAT_011e074c)
    {
        int count = 0;

        for (int index = 0; index < 0x4d; ++index)
        {
            FUN_0066e920_Class* object = GetActorValueInfo(index);

            if (object && (object->unk44 & 1))
            {
                DAT_011e0618[index] = count;
                ++count;
            }
            else
            {
                DAT_011e0618[index] = 0x4d;
            }
        }

        DAT_011e0750 = count;
        DAT_011e074c = 1;
    }
}

class FUN_0093a850_cls;
class FUN_0093a850_shell;
class FUN_0093a850_cls
{
  public:
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
    virtual void v290();
    virtual float v291(int a, bool* b);
    virtual void v292(int a, float f);
    void FUN_008808f0(int a, int b);
    void FUN_0093a850(int a1, float f);
};
class FUN_0093a850_shell
{
  public:
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
    virtual void v100(int a, float f);
};
FUN_0093a850_shell* __fastcall FUN_004181e0(FUN_0093a850_cls* self);
void __cdecl FUN_00704e10(int a);

// Reads a bool via v291; if set calls v292 with the float, otherwise forwards to the shell's v100, then calls FUN_00704e10 and FUN_008808f0.
// @fnv 0x0093a850
void FUN_0093a850_cls::FUN_0093a850(int a1, float f)
{
    bool b = false;
    float r = v291(a1, &b);
    if (b)
    {
        v292(a1, f);
    }
    else
    {
        FUN_004181e0(this)->v100(a1, f);
    }
    FUN_00704e10(a1);
    FUN_008808f0(a1, 1);
}

// Load-game step: attach a timestamped data record to this reference (or its proxy) and flag it changed.

extern unsigned int g_u5920Hour;
extern signed char g_c5920Minute;
extern unsigned int g_u5920Day;
extern float g_f5920GameTime;

class F5920ExtraDataList
{
  public:
    void AddRecord(void* pvRecord);
};

class F5920Record
{
  public:
    int unk00;
    int unk04;
    int unk08;

    F5920Record(void* pvLoadBuffer, int iStamp, float fTime);
};

class F5920Ref
{
  public:
    virtual void Unk00();
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
    virtual void Unk34();
    virtual void Unk38();
    virtual void Unk3C();
    virtual void Unk40();
    virtual void Unk44();
    virtual void MarkChanged(unsigned int uiFlags);

    bool HasProxy() const;
    F5920Ref* GetProxy();
    F5920ExtraDataList* GetExtraData();

    void LoadRecord(void* pvLoadBuffer);
};

// Builds a timestamp from the game hour, minute and day, creates a record from the load buffer, adds it to the target's extra data and marks the target changed.
// @fnv 0x00935920
void F5920Ref::LoadRecord(void* pvLoadBuffer)
{
    int iStamp = (g_u5920Hour << 9) | g_c5920Minute | (g_u5920Day << 13);
    F5920Record* pkRecord = new F5920Record(pvLoadBuffer, iStamp, g_f5920GameTime);
    F5920Ref* pkTarget = this;
    if (HasProxy())
        pkTarget = GetProxy();
    pkTarget->GetExtraData()->AddRecord(pkRecord);
    pkTarget->MarkChanged(0x80000000);
}

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
struct Vec122
{
    float x, y, z;
    Vec122();  //0x6815c0
};
struct List122
{
    int first, last;
    List122();   //0x96a2d0
    ~List122();  //0x46ffb0
    void FUN_00470470();
};
struct Smart122
{
    void* value;
    Smart122(int);  //0x633c90
    ~Smart122();    //0x45cec0
    void FUN_0066b0d0(int);
};
struct Handle122
{
    int a, b, c;
    Handle122();                             //0x41a250
    ~Handle122();                            //0x483710
    Handle122& operator=(const Handle122&);  //0x418900
};
struct Action122
{
    bool available;
    int group;
    bool enabled;
};
struct Member6f8
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    Member6f8();   //0x6f48b0
    ~Member6f8();  //0x6f4930
};
struct Member764
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    Member764(int);  //0x4f6320
    ~Member764();    //0x4f64b0
};
struct Member854
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    Member854(int);  //0x96a280
    ~Member854();    //0x96a4b0
};
struct Member878
{
    int unk0;
    Member878();   //0x8d4360
    ~Member878();  //0x8d4380
};
struct Memberdf4
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    Memberdf4();   //0x96a570
    ~Memberdf4();  //0x96a5a0
};
struct Membere3c
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    Membere3c();   //0x96a5c0
    ~Membere3c();  //0x96a5f0
    void FUN_007cb2e0(const int&);
};
struct Member21c
{
    int unk0;
    int unk4;
    Member21c(float, int);  //0x620850
};
struct Allocated122
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    Allocated122();  //0x939880
};
struct Process122
{
    virtual ~Process122();
    virtual void v4(Process122*);
    virtual void unused8();
    virtual void unusedc();
    virtual void unused10();
    virtual void unused14();
    virtual void unused18();
    virtual void unused1c();
    virtual void unused20();
    virtual void unused24();
    virtual void unused28();
    virtual void unused2c();
    virtual void unused30();
    virtual void unused34();
    virtual void unused38();
    virtual void unused3c();
    virtual void unused40();
    virtual void unused44();
    virtual void unused48();
    virtual void unused4c();
    virtual void unused50();
    virtual void unused54();
    virtual void unused58();
    virtual void unused5c();
    virtual void unused60();
    virtual void unused64();
    virtual void unused68();
    virtual void unused6c();
    virtual void unused70();
    virtual void unused74();
    virtual void unused78();
    virtual void unused7c();
    virtual void unused80();
    virtual void unused84();
    virtual void unused88();
    virtual void unused8c();
    virtual void unused90();
    virtual void unused94();
    virtual void unused98();
    virtual void unused9c();
    virtual void unuseda0();
    virtual void unuseda4();
    virtual void unuseda8();
    virtual void unusedac();
    virtual void unusedb0();
    virtual void unusedb4();
    virtual void unusedb8();
    virtual void unusedbc();
    virtual void unusedc0();
    virtual void unusedc4();
    virtual void unusedc8();
    virtual void unusedcc();
    virtual void unusedd0();
    virtual void unusedd4();
    virtual void unusedd8();
    virtual void unuseddc();
    virtual void unusede0();
    virtual void unusede4();
    virtual void unusede8();
    virtual void unusedec();
    virtual void unusedf0();
    virtual void unusedf4();
    virtual void unusedf8();
    virtual void unusedfc();
    virtual void unused100();
    virtual void unused104();
    virtual void unused108();
    virtual void unused10c();
    virtual void unused110();
    virtual void unused114();
    virtual void unused118();
    virtual void unused11c();
    virtual void unused120();
    virtual void unused124();
    virtual void unused128();
    virtual void unused12c();
    virtual void unused130();
    virtual void unused134();
    virtual void unused138();
    virtual void unused13c();
    virtual void unused140();
    virtual void unused144();
    virtual void unused148();
    virtual void unused14c();
    virtual void unused150();
    virtual void unused154();
    virtual void unused158();
    virtual void unused15c();
    virtual void unused160();
    virtual void unused164();
    virtual void unused168();
    virtual void unused16c();
    virtual void unused170();
    virtual void unused174();
    virtual void unused178();
    virtual void unused17c();
    virtual void unused180();
    virtual void unused184();
    virtual void unused188();
    virtual void unused18c();
    virtual void unused190();
    virtual void unused194();
    virtual void unused198();
    virtual void unused19c();
    virtual void unused1a0();
    virtual void unused1a4();
    virtual void unused1a8();
    virtual void unused1ac();
    virtual void unused1b0();
    virtual void unused1b4();
    virtual void unused1b8();
    virtual void unused1bc();
    virtual void unused1c0();
    virtual void unused1c4();
    virtual void unused1c8();
    virtual void unused1cc();
    virtual void unused1d0();
    virtual void unused1d4();
    virtual void unused1d8();
    virtual void unused1dc();
    virtual void unused1e0();
    virtual void unused1e4();
    virtual void unused1e8();
    virtual void unused1ec();
    virtual void unused1f0();
    virtual void unused1f4();
    virtual void unused1f8();
    virtual void unused1fc();
    virtual void unused200();
    virtual void unused204();
    virtual void unused208();
    virtual void unused20c();
    virtual void unused210();
    virtual void unused214();
    virtual void unused218();
    virtual void unused21c();
    virtual void unused220();
    virtual void unused224();
    virtual void unused228();
    virtual void unused22c();
    virtual void unused230();
    virtual void unused234();
    virtual void unused238();
    virtual void unused23c();
    virtual void unused240();
    virtual void unused244();
    virtual void unused248();
    virtual void unused24c();
    virtual void unused250();
    virtual void unused254();
    virtual void unused258();
    virtual void unused25c();
    virtual void unused260();
    virtual void unused264();
    virtual void unused268();
    virtual void unused26c();
    virtual void unused270();
    virtual void unused274();
    virtual void unused278();
    virtual void unused27c();
    virtual void unused280();
    virtual void unused284();
    virtual void unused288();
    virtual void unused28c();
    virtual void unused290();
    virtual void unused294();
    virtual void unused298();
    virtual void unused29c();
    virtual void unused2a0();
    virtual void unused2a4();
    virtual void unused2a8();
    virtual void unused2ac();
    virtual void unused2b0();
    virtual void unused2b4();
    virtual void unused2b8();
    virtual void unused2bc();
    virtual void unused2c0();
    virtual void unused2c4();
    virtual void unused2c8();
    virtual void unused2cc();
    virtual void unused2d0();
    virtual void unused2d4();
    virtual void unused2d8();
    virtual void unused2dc();
    virtual void unused2e0();
    virtual void unused2e4();
    virtual void unused2e8();
    virtual void unused2ec();
    virtual void unused2f0();
    virtual void unused2f4();
    virtual void unused2f8();
    virtual void unused2fc();
    virtual void unused300();
    virtual void unused304();
    virtual void unused308();
    virtual void unused30c();
    virtual void unused310();
    virtual void unused314();
    virtual void unused318();
    virtual void unused31c();
    virtual void unused320();
    virtual void unused324();
    virtual void unused328();
    virtual void unused32c();
    virtual void unused330();
    virtual void unused334();
    virtual void unused338();
    virtual void unused33c();
    virtual void unused340();
    virtual void unused344();
    virtual void unused348();
    virtual void unused34c();
    virtual void unused350();
    virtual void unused354();
    virtual void unused358();
    virtual void unused35c();
    virtual void unused360();
    virtual void unused364();
    virtual void unused368();
    virtual void unused36c();
    virtual void unused370();
    virtual void unused374();
    virtual void unused378();
    virtual void unused37c();
    virtual void unused380();
    virtual void unused384();
    virtual void unused388();
    virtual void unused38c();
    virtual void unused390();
    virtual void unused394();
    virtual void unused398();
    virtual void unused39c();
    virtual void unused3a0();
    virtual void unused3a4();
    virtual void unused3a8();
    virtual void unused3ac();
    virtual void unused3b0();
    virtual void unused3b4();
    virtual void unused3b8();
    virtual void unused3bc();
    virtual void unused3c0();
    virtual void unused3c4();
    virtual void unused3c8();
    virtual void unused3cc();
    virtual void unused3d0();
    virtual void unused3d4();
    virtual void unused3d8();
    virtual void unused3dc();
    virtual void unused3e0();
    virtual void unused3e4();
    virtual void unused3e8();
    virtual void unused3ec();
    virtual void unused3f0();
    virtual void unused3f4();
    virtual void unused3f8();
    virtual void unused3fc();
    virtual void unused400();
    virtual void unused404();
    virtual void unused408();
    virtual void unused40c();
    virtual void unused410();
    virtual void unused414();
    virtual void unused418();
    virtual void unused41c();
    virtual void unused420();
    virtual void unused424();
    virtual void unused428();
    virtual void unused42c();
    virtual void unused430();
    virtual void unused434();
    virtual void unused438();
    virtual void unused43c();
    virtual void unused440();
    virtual void unused444();
    virtual void unused448();
    virtual void unused44c();
    virtual void unused450();
    virtual void unused454();
    virtual void unused458();
    virtual void unused45c();
    virtual void unused460();
    virtual void unused464();
    virtual void unused468();
    virtual void unused46c();
    virtual void unused470();
    virtual void unused474();
    virtual void unused478();
    virtual void unused47c();
    virtual void unused480();
    virtual void unused484();
    virtual void unused488();
    virtual void unused48c();
    virtual void unused490();
    virtual void unused494();
    virtual void unused498();
    virtual void unused49c();
    virtual void unused4a0();
    virtual void unused4a4();
    virtual void unused4a8();
    virtual void unused4ac();
    virtual void unused4b0();
    virtual void unused4b4();
    virtual void unused4b8();
    virtual void unused4bc();
    virtual void unused4c0();
    virtual void unused4c4();
    virtual void unused4c8();
    virtual void unused4cc();
    virtual void unused4d0();
    virtual void unused4d4();
    virtual void unused4d8();
    virtual void unused4dc();
    virtual void unused4e0();
    virtual void unused4e4();
    virtual void unused4e8();
    virtual void unused4ec();
    virtual void unused4f0();
    virtual void unused4f4();
    virtual void unused4f8();
    virtual void unused4fc();
    virtual void unused500();
    virtual void unused504();
    virtual void unused508();
    virtual void unused50c();
    virtual void unused510();
    virtual void unused514();
    virtual void unused518();
    virtual void unused51c();
    virtual void unused520();
    virtual void unused524();
    virtual void unused528();
    virtual void unused52c();
    virtual void unused530();
    virtual void unused534();
    virtual void unused538();
    virtual void unused53c();
    virtual void unused540();
    virtual void unused544();
    virtual void unused548();
    virtual void unused54c();
    virtual void unused550();
    virtual void unused554();
    virtual void unused558();
    virtual void unused55c();
    virtual void unused560();
    virtual void unused564();
    virtual void unused568();
    virtual void unused56c();
    virtual void unused570();
    virtual void unused574();
    virtual void unused578();
    virtual void unused57c();
    virtual void unused580();
    virtual void unused584();
    virtual void unused588();
    virtual void unused58c();
    virtual void unused590();
    virtual void unused594();
    virtual void unused598();
    virtual void unused59c();
    virtual void unused5a0();
    virtual void unused5a4();
    virtual void unused5a8();
    virtual void unused5ac();
    virtual void unused5b0();
    virtual void unused5b4();
    virtual void unused5b8();
    virtual void unused5bc();
    virtual void unused5c0();
    virtual void unused5c4();
    virtual void unused5c8();
    virtual void unused5cc();
    virtual void unused5d0();
    virtual void unused5d4();
    virtual void unused5d8();
    virtual void unused5dc();
    virtual void unused5e0();
    virtual void unused5e4();
    virtual void unused5e8();
    virtual void unused5ec();
    virtual void unused5f0();
    virtual void unused5f4();
    virtual void unused5f8();
    virtual void unused5fc();
    virtual void unused600();
    virtual void unused604();
    virtual void unused608();
    virtual void unused60c();
    virtual void unused610();
    virtual void unused614();
    virtual void unused618();
    virtual void unused61c();
    virtual void unused620();
    virtual void unused624();
    virtual void unused628();
    virtual void unused62c();
    virtual void unused630();
    virtual void unused634();
    virtual void unused638();
    virtual void unused63c();
    virtual void unused640();
    virtual void unused644();
    virtual void unused648();
    virtual void unused64c();
    virtual void unused650();
    virtual void unused654();
    virtual void unused658();
    virtual void unused65c();
    virtual void unused660();
    virtual void unused664();
    virtual void unused668();
    virtual void unused66c();
    virtual void unused670();
    virtual void unused674();
    virtual void unused678();
    virtual void unused67c();
    virtual void unused680();
    virtual void unused684();
    virtual void unused688();
    virtual void unused68c();
    virtual void unused690();
    virtual void unused694();
    virtual void unused698();
    virtual void unused69c();
    virtual void unused6a0();
    virtual void unused6a4();
    virtual void unused6a8();
    virtual void unused6ac();
    virtual void unused6b0();
    virtual void unused6b4();
    virtual void unused6b8();
    virtual void unused6bc();
    virtual void unused6c0();
    virtual void unused6c4();
    virtual void unused6c8();
    virtual void unused6cc();
    virtual void unused6d0();
    virtual void unused6d4();
    virtual void unused6d8();
    virtual void unused6dc();
    virtual void v6e0(int);
};
struct NewProcess122 : Process122
{
    int unk4;
    int unk8;
    int unkc;
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
    NewProcess122();  //0x8d7510
};
struct Base000
{
    virtual ~Base000();
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
};
struct Base018
{
    virtual ~Base018();
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
    Process122* f68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
};
struct Base088
{
    virtual ~Base088();
    int unk8c;
    int unk90;
    void SetField18c(int);
    void FUN_00939840(int);
};
struct Base094
{
    virtual ~Base094();
    int unk98;
    int unk9c;
    int unka0;
};
struct Base0a4
{
    virtual ~Base0a4();
};
struct Base0a8
{
    virtual ~Base0a8();
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
    int f1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    Action122 f1c8[3];
    int f1ec;
    int f1f0;
    float f1f4;
    bool f1f8;
    char unk1f9;
    char unk1fa;
    char unk1fb;
    int f1fc;
    int f200;
    bool f204;
    bool f205;
    char unk206;
    char unk207;
    int f208;
    bool f20c;
    char unk20d;
    char unk20e;
    char unk20f;
    List122* f210;
    int unk214;
    int unk218;
    Member21c* f21c;
    int unk220;
    int f224;
    int f228;
    float f22c;
    int f230;
    float f234;
    List122* f238;
    int f23c;
    bool f240;
    char unk241;
    char unk242;
    char unk243;
    float f244[77];
    float f378[77];
    float f4ac;
    float f4b0[77];
};
struct Actor122 : Base000, Base018, Base088, Base094, Base0a4, Base0a8
{
    Actor122();   //0x8d1d30
    ~Actor122();  //0x8d2060
};
struct Controller122
{
    void FUN_00939860(int);
    void FUN_00c6d770(int);
    void FUN_0070c440(int&);
};
struct FUN_00938180 : Actor122
{
    List122 f5e4;
    int f5ec;
    int f5f0;
    int f5f4;
    bool f5f8;
    bool f5f9;
    char unk5fa;
    char unk5fb;
    List122 f5fc;
    int f604;
    bool f608;
    char unk609;
    char unk60a;
    char unk60b;
    int f60c;
    List122* f610;
    List122* f614;
    List122* f618;
    int f61c;
    int f620;
    int f624;
    int f628;
    int f62c;
    int f630;
    Smart122 f634;
    int f638;
    int f63c;
    float f640;
    float f644;
    bool f648;
    bool f649;
    bool f64a;
    bool f64b;
    bool f64c;
    bool f64d;
    bool f64e;
    bool f64f;
    bool f650;
    bool f651;
    bool f652;
    char unk653;
    int f654;
    bool f658;
    char unk659;
    char unk65a;
    char unk65b;
    int unk65c;
    float f660;
    float f664;
    float f668;
    char unk66c;
    bool f66d;
    bool f66e;
    char unk66f;
    float f670;
    float f674;
    float f678;
    int f67c;
    bool f680;
    bool f681;
    char unk682;
    char unk683;
    float f684;
    int unk688;
    int f68c;
    int f690;
    Smart122 f694;
    float f698;
    Smart122 f69c;
    int f6a0;
    int f6a4;
    List122 f6a8;
    List122 f6b0;
    int f6b8;
    List122 f6bc;
    List122 f6c4;
    bool f6cc;
    char unk6cd;
    char unk6ce;
    char unk6cf;
    int unk6d0;
    int f6d4;
    bool f6d8;
    char unk6d9;
    char unk6da;
    char unk6db;
    int f6dc;
    int unk6e0;
    float f6e4;
    bool f6e8;
    char unk6e9;
    char unk6ea;
    char unk6eb;
    int f6ec;
    int f6f0;
    int f6f4;
    Member6f8 f6f8;
    float f730;
    int f734;
    int f738;
    int f73c;
    int f740;
    int f744[5];
    int f758;
    bool f75c;
    bool f75d;
    bool f75e;
    char unk75f;
    int f760;
    Member764 f764;
    List122 f774;
    Handle122 f77c;
    int f788;
    int unk78c;
    int f790;
    void* f794;
    char unk798;
    char unk799;
    bool f79a;
    bool f79b;
    bool f79c;
    bool f79d;
    char unk79e;
    char unk79f;
    Vec122 f7a0;
    int f7ac;
    int f7b0;
    int f7b4;
    int f7b8;
    int unk7bc;
    int f7c0;
    bool f7c4;
    bool f7c5;
    bool f7c6;
    bool f7c7;
    List122 f7c8;
    int f7d0;
    List122 f7d4;
    int f7dc;
    float f7e0;
    float f7e4;
    Vec122 f7e8;
    int f7f4;
    Handle122 f7f8;
    Handle122 f804[6];
    List122 f84c;
    Member854 f854;
    Smart122 f864;
    Smart122 f868;
    int unk86c;
    float f870;
    float f874;
    Member878 f878;
    List122 f87c;
    List122 f884[74];
    List122 fad4;
    List122 fadc[74];
    int fd2c;
    Vec122 fd30;
    Smart122 fd3c;
    bool fd40;
    char unkd41;
    char unkd42;
    char unkd43;
    int fd44;
    int fd48;
    float fd4c;
    float fd50;
    bool fd54;
    char unkd55;
    char unkd56;
    char unkd57;
    Vec122 fd58;
    int fd64;
    int fd68;
    float fd6c;
    float fd70;
    int fd74[24];
    Vec122 fdd4;
    Vec122 fde0;
    Smart122 fdec;
    bool fdf0;
    bool fdf1;
    char unkdf2;
    char unkdf3;
    Memberdf4 fdf4;
    bool fe08;
    char unke09;
    char unke0a;
    char unke0b;
    int fe0c;
    int unke10;
    int unke14;
    float fe18;
    float fe1c;
    bool fe20;
    bool fe21;
    char unke22;
    char unke23;
    float fe24;
    float fe28;
    bool fe2c;
    bool fe2d;
    bool fe2e;
    char unke2f;
    float fe30;
    int unke34;
    bool fe38;
    char unke39;
    char unke3a;
    char unke3b;
    Membere3c fe3c;
    int fe4c;
    FUN_00938180();
    virtual ~FUN_00938180();
    void FUN_00484ab0(int);
    void FUN_005d14d0(int);
    int FUN_00931850();
    void FUN_00930c70();
    Controller122* FUN_009306d0();
    void FUN_004534f0(int);
    float FUN_00950610(float);
    void SetField688(int);
    void FUN_00851d10();
    void FUN_0093a5f0(int);
    void FUN_0093a6f0(int);
    void FUN_00969e90(int, int);
    void FUN_009627f0();
    int FUN_0044ddc0();
    void FUN_00403550(int);
    void ResetMover();
    void FUN_00567dd0(void*);
    void FUN_005dadd0(int);
    void FUN_00969110(int);
    void SetSightingNode(int);
};
struct Profile122
{
    int active;
    Profile122(int, int, const char*, int);  //0x404eb0
    ~Profile122();                           //0x404ee0
};
struct Setting122
{
    float* FUN_00403e20();
    bool* FUN_00408d60();
    int* FUN_0043d4d0();
    void FUN_004ed780(float);
};
struct Global122
{
    void FUN_0096d470(FUN_00938180*, int);
};
extern Global122 DAT_011e0e80;
extern Setting122 DAT_011ccf2c, DAT_011e0934, DAT_011e0b4c, DAT_01203150, DAT_011e0940, DAT_011e087c, DAT_011cd8f0,
    DAT_0120315c, DAT_011cda58, DAT_01203168;
extern Vec122 DAT_011f426c, DAT_011e0808;
extern float DAT_011e0b5c, DAT_011e0768;
extern bool DAT_011e07c3;
extern Allocated122* DAT_011e0774;
extern Allocated122* DAT_011e0760;
struct Anim122
{
    signed char flag;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
};
extern Anim122 DAT_011a3ad4[];
void LoadWeaponWobbleModels();
void FUN_008d1820();
void* GetTime64(int);
void* FUN_00546a90();
void* FUN_00403d30(void*, int, unsigned int);
// @fnv 0x00938180
FUN_00938180::FUN_00938180() : f634(0), f694(0), f69c(0), f764(1), f854(0x25), f864(0), f868(0), fd3c(0), fdec(0)
{
    Profile122 profile4(0x34, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\PlayerCharacter.cpp", 0x2c7);
    FUN_00484ab0(0);
    fdd4 = DAT_011f426c;
    fde0 = DAT_011f426c;
    LoadWeaponWobbleModels();
    FUN_008d1820();
    DAT_011e0b5c = *DAT_011ccf2c.FUN_00403e20();
    f79a = 0;
    for (int i = 0; i < 77; i++)
    {
        f244[i] = 0.f;
        f378[i] = 0.f;
        f4b0[i] = 0.f;
    }
    f1f4 = 0.f;
    f1f8 = 0;
    f4ac = 0.f;
    f654 = 0;
    f660 = 0.f;
    f664 = 0.f;
    f668 = 0.f;
    f6dc = 0;
    f734 = 0;
    f20c = 0;
    f66d = 0;
    FUN_005d14d0(1);
    f66e = 1;
    f75c = 0;
    f75d = 1;
    f738 = 0x4d;
    f73c = 0;
    f60c = 0;
    fd2c = 0;
    fd30 = DAT_011f426c;
    fd44 = 0;
    f79b = 0;
    f740 = 0;
    f204 = 0;
    f864.FUN_0066b0d0(0);
    f868.FUN_0066b0d0(0);
    f205 = 1;
    Process122* process39 = new NewProcess122;
    process39->v4(f68);
    DAT_011e0e80.FUN_0096d470(this, FUN_00931850());
    delete f68;
    f68 = process39;
    DAT_011e0e80.FUN_0096d470(this, FUN_00931850());
    SetField18c(0);
    FUN_00939840(0);
    f210 = new List122;
    FUN_00930c70();
    Controller122* controller10 = FUN_009306d0();
    if (controller10)
    {
        controller10->FUN_00939860(1000);
        FUN_004534f0(1);
        int mode4 = 9;
        controller10->FUN_00c6d770(mode4);
        int unknown10;
        controller10->FUN_0070c440(unknown10);
        f21c = new Member21c(*DAT_011e0934.FUN_00403e20(), mode4);
    }
    else
        f21c = 0;
    f649 = 0;
    f648 = 0;
    f64a = 0;
    f64b = 0;
    f64c = 0;
    f64d = 0;
    f64e = 0;
    f64f = 0;
    f650 = 0;
    f651 = *DAT_011e0b4c.FUN_00408d60();
    f652 = 0;
    FUN_00950610(*DAT_01203150.FUN_00403e20());
    f68c = 0;
    f690 = 0;
    f694.FUN_0066b0d0(0);
    f698 = 118.f;
    f69c.FUN_0066b0d0(0);
    f6a0 = 0;
    f6a0 = 0;
    DAT_011e0808 = DAT_011f426c;
    DAT_011e0768 = 0.f;
    DAT_011e07c3 = 0;
    f6cc = 0;
    f680 = 0;
    f208 = 0;
    f681 = 0;
    f684 = 5.f;
    f6d4 = 0;
    f6e4 = 0.f;
    f6d8 = 0;
    f6e8 = 0;
    f6ec = 0;
    f6f0 = 0;
    f6f4 = 0;
    f6b8 = 0;
    f238 = new List122;
    f23c = 0;
    f67c = 0;
    SetField688(0);
    f658 = 0;
    f758 = 0;
    f75e = 0;
    f760 = 0;
    f634.FUN_0066b0d0(0);
    f638 = 0;
    f63c = 0;
    f640 = 0.f;
    f644 = 0.f;
    f788 = 0;
    f790 = 0;
    FUN_00851d10();
    for (int j = 0; j < 5; j++)
        f744[j] = 0;
    f794 = GetTime64(0);
    FUN_0093a5f0(0);
    FUN_0093a6f0(0);
    f79c = 0;
    f79d = 0;
    f7a0 = DAT_011f426c;
    f7ac = 0;
    f7b4 = 0;
    f7b0 = 0;
    f610 = new List122;
    f614 = new List122;
    f618 = new List122;
    f61c = 0;
    f620 = 0;
    f624 = 0;
    f628 = 0;
    f62c = 0;
    f630 = 0;
    FUN_00969e90(0, 0);
    fe38 = 1;
    f7b8 = *DAT_011e0940.FUN_0043d4d0();
    f7c0 = *DAT_011e087c.FUN_0043d4d0();
    f6a4 = 0;
    f7c4 = 0;
    f7c5 = 0;
    f7c6 = 0;
    f7c7 = 0;
    f200 = 0;
    f7d0 = 0;
    f7e0 = 0.f;
    f7e4 = 0.f;
    f7e8 = DAT_011f426c;
    f240 = 1;
    f7f4 = 0;
    f7f8 = Handle122();
    for (int k = 0; k < 6; k++)
        f804[k] = Handle122();
    f604 = 0;
    f84c.FUN_00470470();
    FUN_009627f0();
    DAT_011cd8f0.FUN_004ed780(0.f);
    f870 = 0.f;
    f874 = 0.f;
    int flags24 = FUN_0044ddc0();
    flags24 |= 0x400;
    FUN_00403550(flags24);
    f670 = *DAT_0120315c.FUN_00403e20();
    f678 = *DAT_011cda58.FUN_00403e20();
    f674 = *DAT_01203168.FUN_00403e20();
    f68->v6e0(0);
    ResetMover();
    f730 = 0.f;
    f228 = 0;
    f22c = -1.f;
    f230 = 0;
    f234 = -1.f;
    fd48 = 0;
    fd54 = 0;
    fd4c = 0.f;
    fd50 = 0.f;
    f5ec = 0;
    f5f0 = 0;
    f5f4 = 0;
    fd58 = DAT_011f426c;
    f608 = 0;
    f1ec = 0;
    f1f0 = 0;
    fd64 = 0;
    fd68 = 0;
    fdf0 = 0;
    fdf1 = 0;
    fd6c = 0.f;
    fd70 = 0.f;
    fdec.FUN_0066b0d0(0);
    FUN_00567dd0(FUN_00546a90());
    FUN_005dadd0(0);
    DAT_011e0774 = new Allocated122;
    DAT_011e0760 = new Allocated122;
    FUN_00403d30(fd74, 0, 0x60);
    FUN_00969110(0);
    f224 = 0;
    f5f8 = 0;
    f1fc = 0;
    fd3c.FUN_0066b0d0(0);
    fd40 = 0;
    fe08 = 0;
    fe21 = 0;
    fe0c = 0;
    fe18 = 0.f;
    fe1c = 0.f;
    fe20 = 0;
    f1a0 = 0;
    f5f9 = 0;
    fe24 = -1.f;
    for (int n = 0; n < 3; n++)
    {
        f1c8[n].available = 0;
        f1c8[n].group = 0;
        f1c8[n].enabled = ~(DAT_011a3ad4[n].flag & 2);
    }
    f7dc = 0;
    fe28 = 0.f;
    fe2c = 0;
    fe2d = 0;
    fe2e = 0;
    fe30 = 0.f;
    SetSightingNode(0);
    int count3 = 8;
    for (int m = 0; m < count3; m++)
        fe3c.FUN_007cb2e0(0);
    fe4c = 0;
}

class GlobalObject_006815c0
{
  public:
    int unk00;
    int unk04;
    int unk08;
};

extern GlobalObject_006815c0 g_011e05e0;

struct FUN_00933700_Target
{
    void FUN_0050ea50(GlobalObject_006815c0* a);
};

struct FUN_00933700_Obj68
{
    virtual void* v000();
    virtual void* v001();
    virtual void* v002();
    virtual void* v003();
    virtual void* v004();
    virtual void* v005();
    virtual void* v006();
    virtual void* v007();
    virtual void* v008();
    virtual void* v009();
    virtual void* v00A();
    virtual void* v00B();
    virtual void* v00C();
    virtual void* v00D();
    virtual void* v00E();
    virtual void* v00F();
    virtual void* v010();
    virtual void* v011();
    virtual void* v012();
    virtual void* v013();
    virtual void* v014();
    virtual void* v015();
    virtual void* v016();
    virtual void* v017();
    virtual void* v018();
    virtual void* v019();
    virtual void* v01A();
    virtual void* v01B();
    virtual void* v01C();
    virtual void* v01D();
    virtual void* v01E();
    virtual void* v01F();
    virtual void* v020();
    virtual void* v021();
    virtual void* v022();
    virtual void* v023();
    virtual void* v024();
    virtual void* v025();
    virtual void* v026();
    virtual void* v027();
    virtual void* v028();
    virtual void* v029();
    virtual void* v02A();
    virtual void* v02B();
    virtual void* v02C();
    virtual void* v02D();
    virtual void* v02E();
    virtual void* v02F();
    virtual void* v030();
    virtual void* v031();
    virtual void* v032();
    virtual void* v033();
    virtual void* v034();
    virtual void* v035();
    virtual void* v036();
    virtual void* v037();
    virtual void* v038();
    virtual void* v039();
    virtual void* v03A();
    virtual void* v03B();
    virtual void* v03C();
    virtual void* v03D();
    virtual void* v03E();
    virtual void* v03F();
    virtual void* v040();
    virtual void* v041();
    virtual void* v042();
    virtual void* v043();
    virtual void* v044();
    virtual void* v045();
    virtual void* v046();
    virtual void* v047();
    virtual void* v048();
    virtual void* v049();
    virtual void* v04A();
    virtual void* v04B();
    virtual void* v04C();
    virtual void* v04D();
    virtual void* v04E();
    virtual void* v04F();
    virtual void* v050();
    virtual void* v051();
    virtual void* v052();
    virtual void* v053();
    virtual void* v054();
    virtual void* v055();
    virtual void* v056();
    virtual void* v057();
    virtual void* v058();
    virtual void* v059();
    virtual void* v05A();
    virtual void* v05B();
    virtual void* v05C();
    virtual void* v05D();
    virtual void* v05E();
    virtual void* v05F();
    virtual void* v060();
    virtual void* v061();
    virtual void* v062();
    virtual void* v063();
    virtual void* v064();
    virtual void* v065();
    virtual void* v066();
    virtual void* v067();
    virtual void* v068();
    virtual void* v069();
    virtual void* v06A();
    virtual void* v06B();
    virtual void* v06C();
    virtual void* v06D();
    virtual void* v06E();
    virtual void* v06F();
    virtual void* v070();
    virtual void* v071();
    virtual void* v072();
    virtual void* v073();
    virtual void* v074();
    virtual void* v075();
    virtual void* v076();
    virtual void* v077();
    virtual void* v078();
    virtual void* v079();
    virtual void* v07A();
    virtual void* v07B();
    virtual void* v07C();
    virtual void* v07D();
    virtual void* v07E();
    virtual void* v07F();
    virtual void* v080();
    virtual void* v081();
    virtual void* v082();
    virtual void* v083();
    virtual void* v084();
    virtual void* v085();
    virtual void* v086();
    virtual void* v087();
    virtual void* v088();
    virtual void* v089();
    virtual void* v08A();
    virtual void* v08B();
    virtual void* v08C();
    virtual void* v08D();
    virtual void* v08E();
    virtual void* v08F();
    virtual void* v090();
    virtual void* v091();
    virtual void* v092();
    virtual void* v093();
    virtual void* v094();
    virtual void* v095();
    virtual void* v096();
    virtual void* v097();
    virtual void* v098();
    virtual void* v099();
    virtual void* v09A();
    virtual void* v09B();
    virtual void* v09C();
    virtual void* v09D();
    virtual void* v09E();
    virtual void* v09F();
    virtual void* v0A0();
    virtual void* v0A1();
    virtual void* v0A2();
    virtual void* v0A3();
    virtual void* v0A4();
    virtual void* v0A5();
    virtual void* v0A6();
    virtual void* v0A7();
    virtual void* v0A8();
    virtual void* v0A9();
    virtual void* v0AA();
    virtual void* v0AB();
    virtual void* v0AC();
    virtual void* v0AD();
    virtual void* v0AE();
    virtual void* v0AF();
    virtual void* v0B0();
    virtual void* v0B1();
    virtual void* v0B2();
    virtual void* v0B3();
    virtual void* v0B4();
    virtual void* v0B5();
    virtual void* v0B6();
    virtual void* v0B7();
    virtual void* v0B8();
    virtual void* v0B9();
    virtual void* v0BA();
    virtual void* v0BB();
    virtual void* v0BC();
    virtual void* v0BD();
    virtual void* v0BE();
    virtual void* v0BF();
    virtual void* v0C0();
    virtual void* v0C1();
    virtual void* v0C2();
    virtual void* v0C3();
    virtual void* v0C4();
    virtual void* v0C5();
    virtual void* v0C6();
    virtual void* v0C7();
    virtual void* v0C8();
    virtual void* v0C9();
    virtual void* v0CA();
    virtual void* v0CB();
    virtual void* v0CC();
    virtual void* v0CD();
    virtual void* v0CE();
    virtual void* v0CF();
    virtual void* v0D0();
    virtual void* v0D1();
    virtual void* v0D2();
    virtual void* v0D3();
    virtual void* v0D4();
    virtual void* v0D5();
    virtual void* v0D6();
    virtual void* v0D7();
    virtual void* v0D8();
    virtual void* v0D9();
    virtual void* v0DA();
    virtual void* v0DB();
    virtual void* v0DC();
    virtual void* v0DD();
    virtual void* v0DE();
    virtual void* v0DF();
    virtual void* v0E0();
    virtual void* v0E1();
    virtual void* v0E2();
    virtual void* v0E3();
    virtual void* v0E4();
    virtual void* v0E5();
    virtual void* v0E6();
    virtual void* v0E7();
    virtual void* v0E8();
    virtual void* v0E9();
    virtual void* v0EA();
    virtual void* v0EB();
    virtual void* v0EC();
    virtual void* v0ED();
    virtual void* v0EE();
    virtual void* v0EF();
    virtual void* v0F0();
    virtual void* v0F1();
    virtual void* v0F2();
    virtual void* v0F3();
    virtual void* v0F4();
    virtual void* v0F5();
    virtual void* v0F6();
    virtual void* v0F7();
    virtual void* v0F8();
    virtual void* v0F9();
    virtual void* v0FA();
    virtual void* v0FB();
    virtual void* v0FC();
    virtual void* v0FD();
    virtual void* v0FE();
    virtual void* v0FF();
    virtual void* v100();
    virtual void* v101();
    virtual void* v102();
    virtual void* v103();
    virtual void* v104();
    virtual void* v105();
    virtual void* v106();
    virtual void* v107();
    virtual void* v108();
    virtual void* v109();
    virtual void* v10A();
    virtual void* v10B();
    virtual void* v10C();
    virtual void* v10D();
    virtual void* v10E();
    virtual void* v10F();
    virtual void* v110();
    virtual void* v111();
    virtual void* v112();
    virtual void* v113();
    virtual void* v114();
    virtual void* v115();
    virtual void* v116();
    virtual void* v117();
    virtual void* v118();
    virtual void* v119();
    virtual void* v11A();
    virtual void* v11B();
    virtual void* v11C();
    virtual void* v11D();
    virtual void* v11E();
    virtual void* v11F();
    virtual void* v120();
    virtual void* v121();
    virtual void* v122();
    virtual void* v123();
    virtual void* v124();
    virtual void* v125();
    virtual void* v126();
    virtual void* v127();
    virtual void* v128();
    virtual void* v129();
    virtual void* v12A();
    virtual void* v12B();
    virtual void* v12C();
    virtual void* v12D();
    virtual void* v12E();
    virtual void* v12F();
    virtual void* v130();
    virtual void* v131();
    virtual void* v132();
    virtual void* v133();
    virtual void* v134();
    virtual void* v135();
    virtual void* v136();
    virtual void* v137();
    virtual void* v138();
    virtual void* v139();
    virtual void* v13A();
    virtual void* v13B();
    virtual void* v13C();
    virtual void* v13D();
    virtual void* v13E();
    virtual void* v13F();
    virtual void* v140();
    virtual void* v141();
    virtual void* v142();
    virtual void* v143();
    virtual void* v144();
    virtual void* v145();
    virtual void* v146();
    virtual void* v147();
    virtual void* v148();
    virtual void* v149();
    virtual void* v14A();
    virtual void* v14B();
    virtual void* v14C();
    virtual void* v14D();
    virtual void* v14E();
    virtual void* v14F();
    virtual void* v150();
    virtual void* v151();
    virtual void* v152();
    virtual void* v153();
    virtual void* v154();
    virtual void* v155();
    virtual void* v156();
    virtual void* v157();
    virtual void* v158();
    virtual void* v159();
    virtual void* v15A();
    virtual void* v15B();
    virtual void* v15C();
    virtual void* v15D();
    virtual void* v15E();
    virtual void* v15F();
    virtual void* v160();
    virtual void* v161();
    virtual void* v162();
    virtual void* v163();
    virtual void* v164();
    virtual void* v165();
    virtual void* v166();
    virtual void* v167();
    virtual void* v168();
    virtual void* v169();
    virtual void* v16A();
    virtual void* v16B();
    virtual void* v16C();
    virtual void* v16D();
    virtual void* v16E();
    virtual void* v16F();
    virtual void* v170();
    virtual void* v171();
    virtual void* v172();
    virtual void* v173();
    virtual void* v174();
    virtual void* v175();
    virtual void* v176();
    virtual void* v177();
    virtual void* v178();
    virtual void* v179();
    virtual void* v17A();
    virtual void* v17B();
    virtual void* v17c();
};

struct FUN_00933700_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    FUN_00933700_Obj68* m_68;
    void FUN_0056fba0(GlobalObject_006815c0* a);
    GlobalObject_006815c0* GetGlobalObject(GlobalObject_006815c0* out);
};

// If m_68 and its v17c() are non-null, calls FUN_0050ea50 on the result and copies g_011e05e0 to out; otherwise calls FUN_0056fba0(out).
// @fnv 0x00933700
GlobalObject_006815c0* FUN_00933700_cls::GetGlobalObject(GlobalObject_006815c0* out)
{
    if (m_68 != 0 && m_68->v17c() != 0)
    {
        FUN_00933700_Target* target = (FUN_00933700_Target*)m_68->v17c();
        target->FUN_0050ea50(&g_011e05e0);
        *out = g_011e05e0;
        return out;
    }
    FUN_0056fba0(out);
    return out;
}

struct FUN_00935f00_form
{
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual bool s63();
};

struct FUN_004bc4a0_obj
{
    void SetAccumulate(int a1);
};

// Looks up a form by formID, and if found and its s63 check passes, sets its accumulate mode to 3.
// @fnv 0x00935f00
void __cdecl SetFormAccumulate(int formID)
{
    int id = formID;
    FUN_00935f00_form* pForm2 = reinterpret_cast<FUN_00935f00_form*>(_ref_004839c0(id));
    if (pForm2 != 0 && pForm2->s63())
    {
        FUN_004bc4a0_obj* pObj = reinterpret_cast<FUN_004bc4a0_obj*>(pForm2);
        if (pObj == 0)
            return;
        pObj->SetAccumulate(3);
    }
}

struct xVDel
{
    virtual ~xVDel();
};
struct xVList
{
    virtual ~xVList();
    void RemoveAll();
};
struct xVDel4
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~xVDel4();
};
struct xPod
{
    int a;
};
struct xList
{
    ~xList();
    void RemoveAll();
    bool IsEmpty();
    void** Head();
    void RemoveHead();
    xList* Next();
    int m_kPointA, m_kPointB;
};
struct x55
{
    ~x55();
};
struct xGO
{
    ~xGO();
    void operator=(void*);
    int m_p;
};
struct xSound
{
    xSound();
    ~xSound();
    xSound& operator=(const xSound&);
    bool IsValid();
    void Stop();
    int m_kPointA, m_kPointB, m_iThirdValue;
};
struct xTeleportPath
{
    ~xTeleportPath();
    int m_kPointA[27];
};
struct xM764
{
    ~xM764();
    int m_iWordAt00;
    xList m_kNode;
};
struct xM854
{
    ~xM854();
    int m_kPointA[2];
};
struct xM878
{
    ~xM878();
    int m_kPointA;
};
struct xMdf4
{
    ~xMdf4();
    int m_kPointA[18];
};
struct xMe3c
{
    ~xMe3c();
    int m_kPointA;
};
struct x6ec
{
    void F(bool);
};
struct xSaveLoad
{
    void F(int);
};
struct xPoint3
{
    float x, y, z;
};
struct xPickGlobal
{
    void Clear(void*);
    void Set(const xPoint3*, const xPoint3*, int);
};
extern xSaveLoad* xg_SaveLoad;
extern xPickGlobal xg_Pick;
extern const xPoint3 xg_Zero;
extern xPod* xg_Buf774;
extern xPod* xg_Buf760;
void xFree8d68d0();
void xFree8d1920();

struct xB0
{
    virtual void b0();
    int m_04[5];
};
struct xB1
{
    virtual void b1();
    int m_1c[19];
    xVDel* m_68;
    int m_6c[7];
};
struct xB2
{
    virtual void b2();
    int m_8c[2];
};
struct xB3
{
    virtual void b3();
    int m_98[3];
};
struct xB4
{
    virtual void b4();
};
struct xB5
{
    virtual void b5();
};
struct xCharacter : xB0, xB1, xB2, xB3, xB4, xB5
{
    ~xCharacter();
    int m_uiStandInValue[89];
    xList* m_210;
    int m_iValueAfterStandIn[2];
    x55* m_21c;
    int m_pAuxiliaryObject[6];
    xList* m_238;
    xList* m_23c;
    int m_pad3[233];
};

struct FUN_009398d0 : xCharacter
{
    ~FUN_009398d0();
    void F947d10();
    void F948050();
    void F950c20(int);
    void F8b3180();
    void F967290();
    void F9690a0();
    void F94eb40(void*, unsigned char);
    void F961f90();
    void F962490(void*, unsigned char);
    void F9655a0();
    void F9655e0();
    void F952f90();
    xList m_5e4;
    int m_uiStandInValue[4];
    xList m_5fc;
    int m_iValueAfterStandIn[2];
    xList* m_60c;
    xList* m_610;
    xList* m_614;
    xList* m_618;
    int m_pAuxiliaryObject[6];
    xGO m_634;
    int m_pad3[23];
    xGO m_694;
    int m_pad4[1];
    xGO m_69c;
    int m_pad5[1];
    xVDel* m_6a4;
    xList m_6a8;
    xList m_6b0;
    int m_pad6[1];
    xList m_6bc;
    xList m_6c4;
    int m_pad7[8];
    x6ec* m_6ec;
    int m_pad8[2];
    xTeleportPath m_6f8;
    xM764 m_764;
    int m_pad9[1];
    xList m_774;
    xSound m_77c;
    int m_788;
    int m_pad10[9];
    xVList* m_7b0;
    int m_pad11[5];
    xList m_7c8;
    int m_pad12[1];
    xList m_7d4;
    int m_pad13[7];
    xSound m_7f8;
    xSound m_804[6];
    xList m_84c;
    xM854 m_854;
    int m_pad14[2];
    xGO m_864;
    xGO m_868;
    int m_pad15[3];
    xM878 m_878;
    xList m_87c;
    xList m_884[0x4a];
    xList m_ad4;
    xList m_adc[0x4a];
    int m_aiValuesD34[4];
    xGO m_d3c;
    int m_pad17[43];
    xGO m_dec;
    int m_pad18[1];
    xMdf4 m_df4;
    xMe3c m_e3c;
};

// Destroys the character by releasing owned lists, auxiliary objects, sounds, and global pick state.
// @fnv 0x009398d0
FUN_009398d0::~FUN_009398d0()
{
    xList* NODE;
    int iIndex;
    F947d10();
    F948050();
    m_764.m_kNode.RemoveAll();
    xFree8d68d0();
    xFree8d1920();
    F950c20(0);
    delete m_68;
    m_68 = 0;
    if (m_238)
    {
        m_238->RemoveAll();
        delete m_238;
    }
    if (m_23c)
    {
        m_23c->RemoveAll();
        delete m_23c;
    }
    delete m_21c;
    m_634 = 0;
    if (m_6ec)
        m_6ec->F(true);
    if (m_210)
    {
        while (m_210 && !m_210->IsEmpty())
        {
            delete *(xVDel**)m_210->Head();
            m_210->RemoveHead();
        }
        delete m_210;
    }
    if (m_60c)
    {
        while (m_60c && *m_60c->Head())
        {
            delete *(xPod**)m_60c->Head();
            m_60c->RemoveHead();
        }
        delete m_60c;
    }
    if (m_610 && !m_610->IsEmpty())
    {
        while (m_610 && *m_610->Head())
        {
            delete *(xPod**)m_610->Head();
            m_610->RemoveHead();
        }
        delete m_610;
    }
    if (m_614 && !m_614->IsEmpty())
    {
        while (m_614 && *m_614->Head())
        {
            delete *(xVDel4**)m_614->Head();
            m_614->RemoveHead();
        }
        delete m_614;
    }
    if (m_618 && !m_618->IsEmpty())
    {
        while (m_618 && *m_618->Head())
        {
            delete *(xVDel4**)m_618->Head();
            m_618->RemoveHead();
        }
        delete m_618;
    }
    F8b3180();
    m_6a8.RemoveAll();
    m_6b0.RemoveAll();
    m_6c4.RemoveAll();
    m_6bc.RemoveAll();
    F967290();
    F9690a0();
    if (m_6a4)
        delete m_6a4;
    F94eb40(0, 1);
    if (m_788)
        xg_SaveLoad->F(m_788);
    if (m_7b0)
    {
        m_7b0->RemoveAll();
        delete m_7b0;
        m_7b0 = 0;
    }
    F961f90();
    for (iIndex = 0; iIndex < 6; iIndex++)
    {
        if (m_804[iIndex].IsValid())
        {
            m_804[iIndex].Stop();
            m_804[iIndex] = xSound();
        }
    }
    m_84c.RemoveAll();
    F962490(0, 1);
    F962490(0, 0);
    xg_Pick.Clear(0);
    xg_Pick.Set(&xg_Zero, &xg_Zero, 0);
    {
        NODE = &m_87c;
        while (NODE)
        {
            xPod* pPod = *(xPod**)NODE->Head();
            delete pPod;
            NODE = NODE->Next();
        }
        m_87c.RemoveAll();
        for (unsigned int J = 0; J < 0x4a; J++)
            m_884[J].RemoveAll();
    }
    {
        NODE = &m_ad4;
        while (NODE)
        {
            xPod* P2 = *(xPod**)NODE->Head();
            delete P2;
            NODE = NODE->Next();
        }
        m_ad4.RemoveAll();
        for (unsigned int K = 0; K < 0x4a; K++)
            m_adc[K].RemoveAll();
    }
    m_5e4.RemoveAll();
    F9655a0();
    F9655e0();
    F952f90();
    delete xg_Buf774;
    delete xg_Buf760;
}

#include <xmmintrin.h>
struct MPt
{
    float x, y, z;
    MPt();
    MPt(float, float, float);
    MPt operator-(const MPt&) const;
    MPt operator*(float) const;
    MPt& operator*=(float);
    MPt& operator-=(const MPt&);
    float Dot(const MPt&) const;
    void Unitize();
    float FUN_00457990();
    float FUN_004a7290() const;
    void FUN_004a0c10();
    MPt& operator+=(const MPt&);
    MPt operator+(const MPt&) const;
    MPt& FUN_00524c40();
};
struct __declspec(align(16)) MVec4
{
    __m128 q;
    MVec4();
};
struct MSetting
{
    int* FUN_0043d4d0();
    float* FUN_00403e20();
    unsigned char* FUN_00408d60();
};
struct VSlotRoot
{
};
template <class B, int N> struct VSlot : VSlot<B, N - 1>
{
    virtual void slot(VSlot<B, N>*);
};
template <class B> struct VSlot<B, 0> : B
{
};
struct TickPlayer;
struct TickProc;
struct TickCell;
struct TickFace;
struct TickVisual;
struct TickRefList;
struct TickInput
{
    int FUN_00a24660(int, int);
    void FUN_00a24280(int);
    int GetAxisState(int, int);
};
struct TickGlobals
{
    TickInput* FUN_00877720();
    bool FUN_009443c0();
    void FUN_0086fd90(bool);
};
struct TickAnimGroup
{
    bool FUN_005f4db0();
    int FUN_005f2420();
};
struct TickSequence
{
    TickAnimGroup* FUN_0048f7f0();
};
struct TickAnimation
{
    void FUN_0088b030(float);
    void FUN_00922650(int, int);
    bool FUN_004985f0();
    unsigned short FUN_004301b0(int);
    TickSequence* FUN_00491040(int);
    void FUN_004974a0();
    void FUN_004994f0(int, bool);
    float FUN_009442a0() const;
    float FUN_00508070();
    void SetMoveSpeed(float);
    void FUN_004c0c90(float);
};
struct TickWeapon
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c,
        unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0;
    struct Clip
    {
        bool FUN_00474a80();
    } unka4;
    bool IsFlagSet() const;
    bool FUN_004ad030();
    void* FUN_00525980(TickPlayer*);
    unsigned char GetByteAt102();
    bool FUN_006450c0();
    float FUN_00709430(bool);
    int GetFlaggedValue(bool);
};
struct TickEquip
{
    TickWeapon* FUN_0044ddc0();
    bool HasEffect(int);
};
struct TickVatsEntry
{
    int unk00, unk04;
    bool unk08;
};
struct TickVATS
{
    int FUN_0044ddc0();
    bool FUN_00525430();
    void FUN_009c8950(bool, bool);
    TickVatsEntry* FUN_009c71c0();
    void CreateCommandAndUpdateHUD();
};
struct TickAvo
{
    virtual void v00();
    virtual void v04();
    virtual int vf008(int);
};
struct TickSmart
{
    void* value;
    void* FUN_00559450();
    void FUN_0066b0d0(int);
};
struct TickExtraActivate;
struct RV0 : VSlot<VSlotRoot, 64>
{
    virtual bool vf100();
};
struct RV1 : VSlot<RV0, 8>
{
    virtual void vf124(int, TickPlayer*, int, int, int);
};
struct RV2 : VSlot<RV1, 42>
{
    virtual TickVisual* vf1d0();
};
struct RV3 : VSlot<RV2, 8>
{
    virtual MPt* vf1f4();
};
struct RV4 : VSlot<RV3, 11>
{
    virtual bool vf224();
};
struct RV5 : VSlot<RV4, 1>
{
    virtual bool vf22c(int);
};
struct TickRef : VSlot<RV5, 0>
{
    bool Activate(TickPlayer*, bool, void*, int);
    bool FUN_00568680();
    TickProc* FUN_008d8520();
    int GetExtraDataShort();
    TickCell* FUN_008d6f30();
    bool FUN_00885520(MPt*, TickCell*, float);
    TickExtraActivate* FUN_00569160();
    bool FUN_0057b460();
    int FUN_00401170();
    void* FUN_007af430();
};
struct TickController
{
    bool HasFlag20000();
    bool HasFlag400();
    int FUN_005c0880();
    void FUN_005620e0(MPt*);
    void FUN_0080fb00(void*);
};
struct TickSky
{
    float GetFieldEC();
    float FUN_00595f50();
    float FUN_00595fc0();
};
struct TickCell
{
    bool FUN_00425fd0();
    void UpdateRefPlacement(TickPlayer*, int, int);
    int FUN_005474b0(int);
    bool FUN_005444c0();
    TickRefList* FUN_009604f0();
};
struct TickTES
{
    TickSky* FUN_008d8520();
    void FUN_004581e0(const char*);
};
struct TickData
{
    void* GetField630();
    void* FUN_0089f4e0();
};
struct TickLists
{
    void FUN_00974af0(void*);
    void FUN_00973de0();
    void FUN_0096e570();
    bool HasNearbyDetectedActor(unsigned char);
    bool IsFlagged();
};
struct BSSoundHandleEx
{
    int id;
    int state;
    int flags;
    BSSoundHandleEx();
    ~BSSoundHandleEx();
    BSSoundHandleEx& operator=(const BSSoundHandleEx&);
    bool FUN_00ad8ce0();
    void FUN_00ad8da0(int);
    bool Play(bool);
    void FUN_00ad88f0();
    bool FUN_00ad8930();
    void SetPositionFromArray(MPt*);
};
class AutoMemContext
{
  public:
    int active;
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
};
struct TickAudio
{
    float FUN_00ad7c80();
    void FUN_00ad7ec0();
    void FUN_00ad7da0(float);
    BSSoundHandleEx FUN_00ad7550(const char*, int);
    BSSoundHandleEx FUN_00ad7480(const char*, int, struct TickSoundForm*);
    BSSoundHandleEx FUN_00ad73b0(unsigned int, unsigned int);
};
struct TickTime
{
    void FUN_00aa4db0(float, bool);
    void ApplyGlobalTimeMultiplier();
    float FUN_0084d030();
};
struct TickAmmoList
{
    int FUN_00726070();
    void FUN_006ecd40(unsigned int);
};
struct TickMode
{
    void FUN_00ca1410();
};
struct TickMover
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void vf00c(unsigned short);
    virtual void v10();
    virtual void vf014(float);
    virtual void vf018(float);
    void FUN_009ea570(const MPt&);
    void FUN_009ea360(int, int);
};
struct TickSave
{
    bool FUN_008512f0();
    bool IsField5Set();
    bool LoadQuickSave();
    void FUN_008509a0();
};
struct TickStringSetting
{
    const char* FUN_00403df0();
};
struct TickShadow
{
    void FUN_00b5d9f0(void*, bool);
};
struct TickSoundForm
{
    const char* FUN_00511840();
};
struct TickContext
{
    void SetValueFromExtraData(BSSoundHandleEx*);
    void FUN_00418940(BSSoundHandleEx*);
    void FUN_0041a090(BSSoundHandleEx*);
    void* FUN_0041cd70();
    void FUN_0041cda0();
};
struct TickTargetCast
{
    void* FUN_008ce390();
};
struct TickList
{
    void* item;
    void* next;
    TickList();
    ~TickList();
    bool FUN_008256d0();
};
struct TickMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    TickMatrix();
    void FUN_00439f50(int, MPt*);
    void FUN_00524ac0(float);
};
struct TickSceneNode
{
    TickMatrix* FUN_006a9540();
};
struct TickScene
{
    TickSceneNode* FUN_00558310();
};
struct TickPoint2
{
    float x, y;
    TickPoint2();
    float FUN_00589850() const;
};
struct TickMagicTarget
{
    bool FUN_00822e00();
};
struct TickExtraActivate
{
    int FUN_004309e0(TickRef*);
};
struct TickFlagSetting
{
    bool FUN_004b9930();
};
struct TickDebugObj
{
    void FUN_005610f0(MPt*);
    void FUN_005615d0(const MPt&);
};
struct TickAction
{
    void FUN_009bb080(float, TickPlayer*);
};
struct TickLoader
{
    bool FUN_00447950(TickCell*);
    void UpdateRelationStates(TickCell*);
};
struct TickIO
{
    void FUN_00c3dfa0(int);
};
struct TickMenu
{
    bool FUN_008d51f0();
    void LevelUpPlayer();
};
struct TickPending
{
    void ShowMessageBox();
};
struct TickVisual
{
    float GetHeadTail();
};
struct TickRefList
{
    TickRef** FUN_006815c0();
    TickRefList* FUN_00726070();
};
class TESBoundObject
{
  public:
    virtual void v00();
};
class TESObjectSTAT : public TESBoundObject
{
  public:
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40,
        unk44, unk48, unk4c;
    signed char unk50;
};
struct TickSoundID
{
    unsigned int FUN_0084e3a0();
};
class TESContainer
{
  public:
    int unk00, unk04, unk08;
    TESContainer();
    ~TESContainer();
    void FUN_004818e0(void*, int, int);
    void FUN_004821a0(TickPlayer*, int);
};
struct PV0 : VSlot<VSlotRoot, 53>
{
    virtual void vfd4(TickPlayer*);
};
struct PV1 : VSlot<PV0, 11>
{
    virtual void vf104();
};
struct PV2 : VSlot<PV1, 16>
{
    virtual TickEquip* vf148();
};
struct PV3 : VSlot<PV2, 0>
{
    virtual TickAmmoList* vf14c();
};
struct PV4 : VSlot<PV3, 47>
{
    virtual int vf20c();
};
struct PV5 : VSlot<PV4, 1>
{
    virtual void vf214();
};
struct PV6 : VSlot<PV5, 4>
{
    virtual bool vf228(TickPlayer*);
};
struct PV7 : VSlot<PV6, 0>
{
    virtual int vf22c();
};
struct PV8 : VSlot<PV7, 1>
{
    virtual void vf234();
};
struct PV9 : VSlot<PV8, 17>
{
    virtual int vf27c();
};
struct PV10 : VSlot<PV9, 12>
{
    virtual bool vf2b0(TickPlayer*);
};
struct PV11 : VSlot<PV10, 1>
{
    virtual bool vf2b8(TickPlayer*);
};
struct PV12 : VSlot<PV11, 3>
{
    virtual void vf2c8(float);
};
struct PV13 : VSlot<PV12, 70>
{
    virtual int vf3e4();
};
struct PV14 : VSlot<PV13, 4>
{
    virtual bool vf3f8();
};
struct PV15 : VSlot<PV14, 4>
{
    virtual int vf40c();
};
struct PV16 : VSlot<PV15, 3>
{
    virtual void vf41c(TickPlayer*);
};
struct PV17 : VSlot<PV16, 5>
{
    virtual void vf434(int);
};
struct PV18 : VSlot<PV17, 3>
{
    virtual float vf444();
};
struct PV19 : VSlot<PV18, 3>
{
    virtual bool vf454();
};
struct PV20 : VSlot<PV19, 3>
{
    virtual void vf464(TickPlayer*);
};
struct PV21 : VSlot<PV20, 3>
{
    virtual bool vf474(bool);
};
struct PV22 : VSlot<PV21, 11>
{
    virtual void vf4a4(float);
};
struct PV23 : VSlot<PV22, 5>
{
    virtual int vf4bc();
};
struct PV24 : VSlot<PV23, 2>
{
    virtual TickRef* vf4c8();
};
struct PV25 : VSlot<PV24, 13>
{
    virtual void vf500(TickPlayer*, int);
};
struct PV26 : VSlot<PV25, 67>
{
    virtual int vf610();
};
struct PV27 : VSlot<PV26, 1>
{
    virtual int vf618();
};
struct PV28 : VSlot<PV27, 0>
{
    virtual int vf61c();
};
struct PV29 : VSlot<PV28, 14>
{
    virtual void vf658();
};
struct PV30 : VSlot<PV29, 0>
{
    virtual float vf65c();
};
struct PV31 : VSlot<PV30, 22>
{
    virtual TickAction* vf6b8();
};
struct PV32 : VSlot<PV31, 8>
{
    virtual bool vf6dc();
};
struct PV33 : VSlot<PV32, 10>
{
    virtual void vf708(int);
};
struct PV34 : VSlot<PV33, 22>
{
    virtual float vf764();
};
struct TickProc : VSlot<PV34, 0>
{
    bool FUN_008fec10(TickPlayer*);
};
struct TickFaceV0 : VSlot<VSlotRoot, 45>
{
    virtual void vfb4(float, int, int, int, int, int);
};
struct TickFaceV1 : VSlot<TickFaceV0, 23>
{
    virtual void vf114(int, float);
};
struct TickFace : VSlot<TickFaceV1, 0>
{
};
struct TickHeldV0 : VSlot<VSlotRoot, 196>
{
    virtual void vf310(float);
};
struct TickHeld : VSlot<TickHeldV0, 0>
{
    void FUN_009ab9a0(TickPlayer*);
};
struct AV0 : VSlot<VSlotRoot, 116>
{
    virtual void* vf1d0();
};
struct AV1 : VSlot<AV0, 3>
{
    virtual void vf1e0();
};
struct AV2 : VSlot<AV1, 0>
{
    virtual TickAnimation* vf1e4();
};
struct AV3 : VSlot<AV2, 3>
{
    virtual MPt* vf1f4();
};
struct AV4 : VSlot<AV3, 7>
{
    virtual int vf214();
};
struct AV5 : VSlot<AV4, 5>
{
    virtual bool vf22c(int);
};
struct AV6 : VSlot<AV5, 0>
{
    virtual bool vf230();
};
struct AV7 : VSlot<AV6, 0>
{
    virtual bool vf234();
};
struct AV8 : VSlot<AV7, 7>
{
    virtual void vf254();
};
struct AV9 : VSlot<AV8, 18>
{
    virtual void vf2a0();
};
struct AV10 : VSlot<AV9, 1>
{
    virtual void vf2a8(const MPt&);
};
struct AV11 : VSlot<AV10, 2>
{
    virtual float vf2b4();
};
struct AV12 : VSlot<AV11, 0>
{
    virtual void vf2b8();
};
struct AV13 : VSlot<AV12, 11>
{
    virtual bool vf2e8();
};
struct AV14 : VSlot<AV13, 21>
{
    virtual void vf340(int);
};
struct AV15 : VSlot<AV14, 5>
{
    virtual bool vf358();
};
struct AV16 : VSlot<AV15, 59>
{
    virtual bool vf448();
};
struct AV17 : VSlot<AV16, 12>
{
    virtual void vf47c(int, int);
};
struct TickPlayer : VSlot<AV17, 0>
{
    int unk4, unk8;
    int unkc, unk10;
    int unk14, unk18;
    int unk1c, unk20;
    int unk24, unk28;
    int unk2c, unk30;
    int unk34, unk38;
    int unk3c, unk40;
    int unk44, unk48;
    int unk4c, unk50;
    int unk54, unk58;
    int unk5c, unk60, unk64;
    TickProc* unk68;
    int unk6c, unk70;
    int unk74, unk78;
    int unk7c, unk80;
    int unk84, unk88;
    int unk8c, unk90;
    TickMagicTarget unk94;
    int unk98, unk9c, unka0;
    TickAvo unka4;
    int unka8, unkac;
    TickMode* unkb0;
    int unkb4, unkb8;
    int unkbc, unkc0;
    int unkc4, unkc8;
    int unkcc, unkd0;
    int unkd4, unkd8;
    int unkdc, unke0;
    int unke4, unke8;
    int unkec, unkf0;
    int unkf4, unkf8;
    int unkfc, unk100;
    int unk104, unk108;
    int unk10c, unk110;
    int unk114, unk118;
    int unk11c, unk120;
    int unk124, unk128;
    int unk12c, unk130;
    int unk134, unk138;
    int unk13c, unk140;
    int unk144, unk148;
    int unk14c, unk150;
    float unk154;
    int unk158, unk15c;
    int unk160, unk164;
    int unk168, unk16c;
    int unk170, unk174;
    int unk178, unk17c;
    int unk180, unk184;
    int unk188, unk18c;
    TickMover* unk190;
    int unk194, unk198, unk19c;
    TickHeld* unk1a0;
    int unk1a4, unk1a8;
    int unk1ac, unk1b0;
    int unk1b4, unk1b8;
    int unk1bc, unk1c0;
    int unk1c4, unk1c8;
    int unk1cc, unk1d0;
    int unk1d4, unk1d8;
    int unk1dc, unk1e0;
    int unk1e4, unk1e8;
    int unk1ec, unk1f0;
    int unk1f4, unk1f8;
    int unk1fc, unk200;
    char unk204;
    bool unk205;
    char unk206;
    char unk207;
    int unk208, unk20c;
    int unk210, unk214;
    int unk218, unk21c;
    int unk220, unk224, unk228;
    float unk22c;
    int unk230;
    float unk234;
    int unk238, unk23c;
    int unk240, unk244;
    int unk248, unk24c;
    int unk250, unk254;
    int unk258, unk25c;
    int unk260, unk264;
    int unk268, unk26c;
    int unk270, unk274;
    int unk278, unk27c;
    int unk280, unk284;
    int unk288, unk28c;
    int unk290, unk294;
    int unk298, unk29c;
    int unk2a0, unk2a4;
    int unk2a8, unk2ac;
    int unk2b0, unk2b4;
    int unk2b8, unk2bc;
    int unk2c0, unk2c4;
    int unk2c8, unk2cc;
    int unk2d0, unk2d4;
    int unk2d8, unk2dc;
    int unk2e0, unk2e4;
    int unk2e8, unk2ec;
    int unk2f0, unk2f4;
    int unk2f8, unk2fc;
    int unk300, unk304;
    int unk308, unk30c;
    int unk310, unk314;
    int unk318, unk31c;
    int unk320, unk324;
    int unk328, unk32c;
    int unk330, unk334;
    int unk338, unk33c;
    int unk340, unk344;
    int unk348, unk34c;
    int unk350, unk354;
    int unk358, unk35c;
    int unk360, unk364;
    int unk368, unk36c;
    int unk370, unk374;
    int unk378, unk37c;
    int unk380, unk384;
    int unk388, unk38c;
    int unk390, unk394;
    int unk398, unk39c;
    int unk3a0, unk3a4;
    int unk3a8, unk3ac;
    int unk3b0, unk3b4;
    int unk3b8, unk3bc;
    int unk3c0, unk3c4;
    int unk3c8, unk3cc;
    int unk3d0, unk3d4;
    int unk3d8, unk3dc;
    int unk3e0, unk3e4;
    int unk3e8, unk3ec;
    int unk3f0, unk3f4;
    int unk3f8, unk3fc;
    int unk400, unk404;
    int unk408, unk40c;
    int unk410, unk414;
    int unk418, unk41c;
    int unk420, unk424;
    int unk428, unk42c;
    int unk430, unk434;
    int unk438, unk43c;
    int unk440, unk444;
    int unk448, unk44c;
    int unk450, unk454;
    int unk458, unk45c;
    int unk460, unk464;
    int unk468, unk46c;
    int unk470, unk474;
    int unk478, unk47c;
    int unk480, unk484;
    int unk488, unk48c;
    int unk490, unk494;
    int unk498, unk49c;
    int unk4a0, unk4a4;
    int unk4a8, unk4ac;
    int unk4b0, unk4b4;
    int unk4b8, unk4bc;
    int unk4c0, unk4c4;
    int unk4c8, unk4cc;
    int unk4d0, unk4d4;
    int unk4d8, unk4dc;
    int unk4e0, unk4e4;
    int unk4e8, unk4ec;
    int unk4f0, unk4f4;
    int unk4f8, unk4fc;
    int unk500, unk504;
    int unk508, unk50c;
    int unk510, unk514;
    int unk518, unk51c;
    int unk520, unk524;
    int unk528, unk52c;
    int unk530, unk534;
    int unk538, unk53c;
    int unk540, unk544;
    int unk548, unk54c;
    int unk550, unk554;
    int unk558, unk55c;
    int unk560, unk564;
    int unk568, unk56c;
    int unk570, unk574;
    int unk578, unk57c;
    int unk580, unk584;
    int unk588, unk58c;
    int unk590, unk594;
    int unk598, unk59c;
    int unk5a0, unk5a4;
    int unk5a8, unk5ac;
    int unk5b0, unk5b4;
    int unk5b8, unk5bc;
    int unk5c0, unk5c4;
    int unk5c8, unk5cc;
    int unk5d0, unk5d4;
    int unk5d8, unk5dc;
    int unk5e0, unk5e4;
    int unk5e8, unk5ec;
    int unk5f0, unk5f4;
    int unk5f8, unk5fc;
    int unk600, unk604;
    int unk608, unk60c;
    int unk610, unk614;
    int unk618, unk61c;
    int unk620, unk624;
    int unk628, unk62c, unk630;
    TickSmart unk634;
    int unk638, unk63c;
    float unk640;
    int unk644;
    bool unk648;
    bool unk649;
    bool unk64a;
    bool unk64b;
    bool unk64c;
    bool unk64d;
    bool unk64e;
    bool unk64f;
    char unk650;
    bool unk651;
    bool unk652;
    char unk653;
    int unk654, unk658, unk65c;
    float unk660;
    float unk664;
    float unk668;
    bool unk66c;
    char unk66d;
    char unk66e;
    char unk66f;
    int unk670, unk674;
    int unk678, unk67c;
    char unk680;
    bool unk681;
    char unk682;
    char unk683;
    float unk684;
    int unk688, unk68c;
    int unk690, unk694;
    int unk698, unk69c;
    int unk6a0, unk6a4;
    int unk6a8, unk6ac;
    int unk6b0, unk6b4;
    int unk6b8, unk6bc;
    int unk6c0, unk6c4;
    int unk6c8, unk6cc;
    int unk6d0, unk6d4;
    int unk6d8, unk6dc;
    float unk6e0;
    int unk6e4, unk6e8;
    int unk6ec, unk6f0;
    int unk6f4, unk6f8;
    int unk6fc, unk700;
    int unk704, unk708;
    int unk70c, unk710;
    int unk714, unk718;
    int unk71c, unk720;
    int unk724, unk728;
    int unk72c, unk730;
    int unk734, unk738;
    int unk73c, unk740;
    int unk744, unk748;
    int unk74c, unk750;
    int unk754, unk758;
    int unk75c, unk760;
    int unk764, unk768;
    int unk76c, unk770;
    int unk774, unk778;
    int unk77c, unk780;
    int unk784, unk788;
    int unk78c, unk790, unk794;
    char unk798;
    char unk799;
    bool unk79a;
    char unk79b;
    char unk79c;
    bool unk79d;
    char unk79e;
    char unk79f;
    int unk7a0, unk7a4;
    int unk7a8, unk7ac;
    int unk7b0, unk7b4;
    int unk7b8, unk7bc, unk7c0;
    bool unk7c4;
    char unk7c5;
    char unk7c6;
    char unk7c7;
    int unk7c8, unk7cc;
    int unk7d0, unk7d4;
    int unk7d8, unk7dc;
    int unk7e0, unk7e4;
    int unk7e8, unk7ec;
    int unk7f0, unk7f4;
    int unk7f8, unk7fc;
    int unk800, unk804;
    int unk808, unk80c;
    int unk810, unk814;
    int unk818, unk81c;
    int unk820, unk824;
    int unk828, unk82c;
    int unk830, unk834;
    int unk838, unk83c;
    int unk840, unk844;
    int unk848, unk84c;
    int unk850, unk854;
    int unk858, unk85c;
    int unk860, unk864;
    int unk868, unk86c;
    float unk870;
    float unk874;
    int unk878, unk87c;
    int unk880, unk884;
    int unk888, unk88c;
    int unk890, unk894;
    int unk898, unk89c;
    int unk8a0, unk8a4;
    int unk8a8, unk8ac;
    int unk8b0, unk8b4;
    int unk8b8, unk8bc;
    int unk8c0, unk8c4;
    int unk8c8, unk8cc;
    int unk8d0, unk8d4;
    int unk8d8, unk8dc;
    int unk8e0, unk8e4;
    int unk8e8, unk8ec;
    int unk8f0, unk8f4;
    int unk8f8, unk8fc;
    int unk900, unk904;
    int unk908, unk90c;
    int unk910, unk914;
    int unk918, unk91c;
    int unk920, unk924;
    int unk928, unk92c;
    int unk930, unk934;
    int unk938, unk93c;
    int unk940, unk944;
    int unk948, unk94c;
    int unk950, unk954;
    int unk958, unk95c;
    int unk960, unk964;
    int unk968, unk96c;
    int unk970, unk974;
    int unk978, unk97c;
    int unk980, unk984;
    int unk988, unk98c;
    int unk990, unk994;
    int unk998, unk99c;
    int unk9a0, unk9a4;
    int unk9a8, unk9ac;
    int unk9b0, unk9b4;
    int unk9b8, unk9bc;
    int unk9c0, unk9c4;
    int unk9c8, unk9cc;
    int unk9d0, unk9d4;
    int unk9d8, unk9dc;
    int unk9e0, unk9e4;
    int unk9e8, unk9ec;
    int unk9f0, unk9f4;
    int unk9f8, unk9fc;
    int unka00, unka04;
    int unka08, unka0c;
    int unka10, unka14;
    int unka18, unka1c;
    int unka20, unka24;
    int unka28, unka2c;
    int unka30, unka34;
    int unka38, unka3c;
    int unka40, unka44;
    int unka48, unka4c;
    int unka50, unka54;
    int unka58, unka5c;
    int unka60, unka64;
    int unka68, unka6c;
    int unka70, unka74;
    int unka78, unka7c;
    int unka80, unka84;
    int unka88, unka8c;
    int unka90, unka94;
    int unka98, unka9c;
    int unkaa0, unkaa4;
    int unkaa8, unkaac;
    int unkab0, unkab4;
    int unkab8, unkabc;
    int unkac0, unkac4;
    int unkac8, unkacc;
    int unkad0, unkad4;
    int unkad8, unkadc;
    int unkae0, unkae4;
    int unkae8, unkaec;
    int unkaf0, unkaf4;
    int unkaf8, unkafc;
    int unkb00, unkb04;
    int unkb08, unkb0c;
    int unkb10, unkb14;
    int unkb18, unkb1c;
    int unkb20, unkb24;
    int unkb28, unkb2c;
    int unkb30, unkb34;
    int unkb38, unkb3c;
    int unkb40, unkb44;
    int unkb48, unkb4c;
    int unkb50, unkb54;
    int unkb58, unkb5c;
    int unkb60, unkb64;
    int unkb68, unkb6c;
    int unkb70, unkb74;
    int unkb78, unkb7c;
    int unkb80, unkb84;
    int unkb88, unkb8c;
    int unkb90, unkb94;
    int unkb98, unkb9c;
    int unkba0, unkba4;
    int unkba8, unkbac;
    int unkbb0, unkbb4;
    int unkbb8, unkbbc;
    int unkbc0, unkbc4;
    int unkbc8, unkbcc;
    int unkbd0, unkbd4;
    int unkbd8, unkbdc;
    int unkbe0, unkbe4;
    int unkbe8, unkbec;
    int unkbf0, unkbf4;
    int unkbf8, unkbfc;
    int unkc00, unkc04;
    int unkc08, unkc0c;
    int unkc10, unkc14;
    int unkc18, unkc1c;
    int unkc20, unkc24;
    int unkc28, unkc2c;
    int unkc30, unkc34;
    int unkc38, unkc3c;
    int unkc40, unkc44;
    int unkc48, unkc4c;
    int unkc50, unkc54;
    int unkc58, unkc5c;
    int unkc60, unkc64;
    int unkc68, unkc6c;
    int unkc70, unkc74;
    int unkc78, unkc7c;
    int unkc80, unkc84;
    int unkc88, unkc8c;
    int unkc90, unkc94;
    int unkc98, unkc9c;
    int unkca0, unkca4;
    int unkca8, unkcac;
    int unkcb0, unkcb4;
    int unkcb8, unkcbc;
    int unkcc0, unkcc4;
    int unkcc8, unkccc;
    int unkcd0, unkcd4;
    int unkcd8, unkcdc;
    int unkce0, unkce4;
    int unkce8, unkcec;
    int unkcf0, unkcf4;
    int unkcf8, unkcfc;
    int unkd00, unkd04;
    int unkd08, unkd0c;
    int unkd10, unkd14;
    int unkd18, unkd1c;
    int unkd20, unkd24;
    int unkd28, unkd2c;
    int unkd30, unkd34, unkd38;
    TickSmart unkd3c;
    bool unkd40;
    char unkd41;
    char unkd42;
    char unkd43;
    int unkd44, unkd48, unkd4c;
    float unkd50;
    int unkd54, unkd58;
    int unkd5c, unkd60;
    int unkd64, unkd68;
    float unkd6c;
    float unkd70;
    int unkd74, unkd78;
    int unkd7c, unkd80;
    int unkd84, unkd88;
    int unkd8c, unkd90;
    int unkd94, unkd98;
    int unkd9c, unkda0;
    int unkda4, unkda8;
    int unkdac, unkdb0;
    int unkdb4, unkdb8;
    int unkdbc, unkdc0;
    int unkdc4, unkdc8;
    int unkdcc, unkdd0;
    int unkdd4, unkdd8;
    int unkddc, unkde0;
    int unkde4, unkde8;
    int unkdec, unkdf0;
    int unkdf4, unkdf8;
    int unkdfc, unke00, unke04;
    bool unke08;
    char unke09;
    char unke0a;
    char unke0b;
    TickPending* unke0c;
    int unke10, unke14;
    float unke18;
    float unke1c;
    bool unke20;
    bool unke21;
    char unke22;
    char unke23;
    float unke24;
    int unke28;
    char unke2c;
    bool unke2d;
    bool unke2e;
    char unke2f;
    float unke30;
    int unke34, unke38;
    int unke3c, unke40;
    int unke44, unke48, unke4c;
    void FUN_0093e860(float);
    void ToggleFirstPerson(bool);
    bool FUN_004eaf60();
    TickAnimation* FUN_00950a60(bool);
    void FUN_0093e770(int, bool);
    float GetFieldE28();
    void SetFieldE28(float);
    void FUN_00571760(int);
    void FUN_008bbdb0();
    void FUN_00962d00();
    int GetReferenceFromPhysicsController();
    void SetEffectValue(int, float, int);
    int GetActorFromPhysicsController();
    void FUN_008bc240(int);
    bool FUN_008bbc10();
    TickCell* FUN_008d6f30();
    void FUN_00963e00(int, int);
    int FUN_00964100(int);
    void FUN_0093dd80();
    void FUN_0093df50();
    void RemoveExpiredItems();
    bool FUN_004d1360();
    void FUN_00969c30();
    TickProc* FUN_008d8520();
    bool FUN_009678a0();
    TickController* FUN_009306d0();
    void FUN_00962190();
    void RestorePlayerLocation(bool);
    TickRef* GetField688();
    void SetField688(int);
    unsigned int GetVtbl20Result();
    bool FUN_004997b0();
    bool FUN_004938e0();
    bool FUN_005a2030();
    bool FUN_009445b0(float, int, unsigned short*, bool);
    void FUN_0095f6a0();
    void FUN_009481d0();
    void UpdateFaceAnimation(float);
    void FUN_008885e0(TickAnimation*, float);
    void UpdateCamera(bool, bool);
    int FUN_008a7570();
    void FUN_00950340(bool);
    bool FUN_0093a740();
    bool FUN_005a03f0(unsigned int);
    void FUN_00951a10(bool);
    unsigned char FUN_0093a640();
    void FUN_0093a6f0(bool);
    void FUN_0093a5f0(bool);
    void FUN_0088d640();
    unsigned char GetByteAt798();
    void FUN_00886360(float);
    int FUN_004f8960();
    void FUN_00895110(float, float);
    void FUN_008c3c40(int, int);
    bool FUN_00967ae0();
    bool FUN_005721e0();
    unsigned char GetByteAtOffset681();
    TickContext* FUN_005d43c0();
    void FUN_00953d40();
    void UpdatePlayerStateIfActive();
    bool FUN_008a16d0();
    void FUN_009462c0(bool, bool);
    bool FUN_008843a0();
    bool FUN_008a6970();
    void SetWantsWeaponOut(bool);
    void FUN_009673d0(float);
    bool FUN_00437bf0();
    bool FUN_00437bd0();
    void SetActiveState(int, int, int);
    bool FUN_00894cc0(bool);
    MPt* FUN_00436aa0();
    bool FUN_0050d4a0();
    bool FUN_009613c0(float);
    void FUN_00962350();
    float FUN_008a0b10();
    float FUN_00931d70();
    void FUN_00884f80();
    void FUN_009503d0();
    void FUN_00950530();
    bool FUN_00948310();
    bool FUN_008849c0();
    bool FUN_00894d60();
    void FUN_008a73e0(int, int);
    void SetAnimationGroupFromFlags(unsigned char);
    unsigned char FUN_005a03d0();
    bool HasActorsByPackage();
    bool FUN_00885520(MPt*, TickCell*, float);
    unsigned char FUN_00575d10();
    unsigned char GetByteAt66E();
    bool FUN_005a1e50();
    void FUN_0094df80();
    void FUN_00693ef0(bool);
    void FUN_00947b10();
    bool FUN_00950090();
    void FUN_009500a0();
    void FUN_0095f6c0(float);
    void UpdateScopeZoom(float);
    void ProcessEvents();
    TickMenu* FUN_00464e10();
    bool FUN_00953c50(bool*);
    bool FUN_005c7870();
    void FUN_009444d0(float);
    bool FUN_00894900();
    TickFace* FUN_008adcb0();
    int FUN_00967da0();
    float FUN_00944300();
    void FUN_009442e0(float);
    void FUN_0088c830(void*, int, int, bool, bool, bool);
    void FUN_00964260();
};
extern TickGlobals* DAT_011dea0c;
extern TickPlayer* DAT_011dea3c;
extern TickVATS DAT_011f2250;
extern float DAT_011e07e8;
extern bool DAT_011f21d0, DAT_011f21d1;
extern BSSoundHandleEx DAT_011f6df0;
extern MSetting DAT_011ca7c0, DAT_011d0fa8, DAT_011cdde0, DAT_011d0658, DAT_011d0b08;
extern const float DAT_01017870, DAT_0108b084, DAT_010162c0, DAT_01017868, DAT_01012054;
extern const char DAT_0108b088[], DAT_0108b078[], DAT_0108a8e0[];
extern TickTime DAT_011f6394;
extern TickTES* DAT_011dea10;
extern TickData* DAT_011c3f2c;
extern int DAT_011e077c;
TickAudio* FUN_00453a70();
extern "C" void* FUN_00483a00(const char*);
extern "C" void FUN_005299a0(void*, float, void*);
extern "C" void FUN_00529c90(void*);
extern "C" float FUN_00716440();
extern "C" void* FUN_0056f930(void*);
extern "C" void UpdateTargetHealthHUD(void*, bool);
extern "C" TickScene* FUN_0045c670();
extern "C" void FUN_005e58f0(int, ...);
extern "C" int FUN_007038a0();
extern bool DAT_011e07b8, DAT_011e07c1;
extern TickRef* DAT_011e0788;
extern float DAT_011e0798;
extern double DAT_01015a38;
extern float DAT_011a3b34, DAT_011a3b3c, DAT_011a3b40;
extern bool DAT_011e07c0;
extern TickSave* DAT_011de134;
extern MSetting DAT_011cd62c, DAT_011cd5c8;
extern TickStringSetting DAT_011d4528, DAT_011d400c, DAT_011d4b40;
extern char DAT_011a28e0, DAT_011841cc;
extern "C" void FUN_00709c40(int);
void FUN_007d0a70();
void FUN_00961d50();
extern "C" void ShowMessageBox(const char*, int, int, void (*)(), int, int, float, float, const char*, const char*, int);
extern "C" TickShadow* FUN_00450b80(int);
extern "C" bool FUN_00702360();
extern "C" TickRef* FUN_00703350();
extern "C" void* FUN_00ec43fb(void*, int, void*, void*, int);
extern "C" void FUN_007062e0(int, int, int);
extern "C" bool BuildActionMenu(TickList*, TickRef*);
extern "C" TickSoundForm* GetUIActivateNothingSound();
extern "C" int FUN_00717a40(int, int);
extern "C" bool FUN_00709bc0();
extern "C" bool FUN_004b71d0();
extern "C" int FUN_00ec7d40(int);
extern MSetting DAT_011cd158, DAT_011cdfcc, DAT_011e0964;
extern float DAT_011e07e0;
extern bool DAT_011e0bc1;
extern const char DAT_0108b064[], DAT_0108b050[];
extern const double DAT_01016ff0, DAT_0108b048;
extern const float DAT_01016088;
extern MSetting DAT_011e0b94, DAT_011d097c, DAT_011e0b78;
extern const double DAT_0107d1b8, DAT_010217d8, DAT_01066808;
extern const float DAT_01030ff0, DAT_01018238, DAT_01053154, DAT_0101e2bc, DAT_0108b044;
extern "C" float FUN_00408840(float);
extern "C" float LinearInterpolate(float, float, float, float, float);
extern "C" MPt FUN_004b3ae0(const MPt&, const TickMatrix*);
extern bool DAT_011e07aa, DAT_011e07b9;
extern int DAT_011e07ac;
extern float DAT_011e07b0;
extern "C" bool FUN_005f2670(unsigned short);
extern TickStringSetting DAT_011d4474, DAT_011d28b0, DAT_011d4948, DAT_011d2e50, DAT_011d3e20, DAT_011d20ac,
    DAT_011d4b10, DAT_011d47d4;
extern const char DAT_010208a0[], DAT_01077d84[];
extern const float DAT_01084d20;
extern "C" bool DispatchMessageToSink(const char*, int, const char*, const char*, float, bool);
extern "C" void FUN_007054f0(int);
extern "C" unsigned char FUN_00456c70();
extern MSetting DAT_011e0b64;
extern "C" void* FUN_00458b20();
extern "C" bool FUN_00705a00();
extern "C" bool FUN_007f52c0();
float FUN_009443f0();
void* FUN_005d2860();
void FUN_00705640();
extern bool DAT_011e0780, DAT_011a3b31, DAT_011e0bc0;
extern float DAT_011e07c4, DAT_011e0b60, DAT_011e0bbc, DAT_011e07c8, DAT_011e0b58;
extern MSetting DAT_011cde8c;
extern "C" void UpdateVisibilityState(int);
extern MSetting DAT_011cd4cc, DAT_011cd198, DAT_011cd984, DAT_011ccf50;
extern float DAT_011e08fc, DAT_011e0bb8, DAT_011e08f4, DAT_011e07bc;
extern const double DAT_01023128, DAT_0101ff48, DAT_010240c0;
extern TickFlagSetting DAT_011e09e0;
extern TickDebugObj* DAT_011e07ec;
extern unsigned int DAT_011e0bb4;
extern TickCell* DAT_011e0bb0;
extern TickLoader* DAT_011c3b3c;
extern TickIO* DAT_01202d98;
extern const char DAT_0108b028[];
extern "C" float FUN_004e44b0(float);
extern "C" bool FUN_007050d0();
void FUN_00555c20();
unsigned char FUN_009444a0();
unsigned char FUN_00944270();
bool IsSomethingZero();
bool IsStartMenuFlag1Set();
extern float DAT_011e0bac;
extern const float DAT_01016248;
extern MSetting DAT_011ce3a8, DAT_011cedb8, DAT_011d03a0;
extern "C" float FUN_00404010(float, float);
extern "C" unsigned int FUN_00457fe0();
extern unsigned int DAT_011e0ba8;
extern char DAT_01186568, DAT_01183108;
extern "C" TickSoundID* GetBrushSound(int);
extern "C" unsigned int FUN_00944460(int, int);

// @fnv 0x0093e860
void TickPlayer::FUN_0093e860(float elapsed)
{
    TickInput* input = DAT_011dea0c->FUN_00877720();
    DAT_011e07e8 -= elapsed;
    if (DAT_011f21d0)
    {
        if (DAT_011f21d1)
            DAT_011dea3c->ToggleFirstPerson(true);
        else
            DAT_011dea3c->ToggleFirstPerson(false);
        DAT_011f21d0 = false;
    }
    switch (DAT_011f2250.FUN_0044ddc0())
    {
    case 0:
        FUN_00453a70();
        if (DAT_011f6df0.FUN_00ad8ce0())
        {
            FUN_00453a70();
            DAT_011f6df0.FUN_00ad8da0(1500);
        }
        if (FUN_00453a70()->FUN_00ad7c80() < 0.99f)
            FUN_00453a70()->FUN_00ad7ec0();
        break;
    default:
        if (FUN_00453a70()->FUN_00ad7c80() > 0.99f && *DAT_011ca7c0.FUN_00403e20() < 0.99f)
        {
            FUN_00453a70()->FUN_00ad7da0(*DAT_011ca7c0.FUN_00403e20());
            if (!DAT_011f6df0.FUN_00ad8ce0())
                DAT_011f6df0 = FUN_00453a70()->FUN_00ad7550(DAT_0108b088, 0x31);
            DAT_011f6df0.Play(false);
        }
    }
    if (unke1c > 0.0)
        unke1c -= elapsed;
    bool slowing = false;
    if (unke18 > 0.0)
    {
        if (input->FUN_00a24660(5, 1))
            unke18 = 0.0f;
        unke18 -= elapsed;
        DAT_011f6394.FUN_00aa4db0(DAT_01017870, false);
        if (unke20)
        {
            FUN_00950a60(!FUN_004eaf60())->FUN_0088b030(DAT_0108b084);
            FUN_00950a60(FUN_004eaf60())->FUN_0088b030(DAT_0108b084);
        }
        if (unke18 <= 0.0)
            FUN_0093e770(unk7c0, false);
        else
            slowing = true;
    }
    else
    {
        FUN_00950a60(!FUN_004eaf60())->FUN_0088b030(1.0f);
        FUN_00950a60(FUN_004eaf60())->FUN_0088b030(1.0f);
    }
    if (GetFieldE28() > 0.0)
    {
        SetFieldE28(GetFieldE28() - elapsed);
    }
    if (unka4.vf008(0x33) > 0 && !slowing)
    {
        if (!unke21)
        {
            CopyGlobalFloat();
            void* effect = FUN_00483a00(DAT_0108b078);
            FUN_005299a0(effect, 1.0f, 0);
            unke21 = true;
        }
        DAT_011f6394.FUN_00aa4db0(*DAT_011d0fa8.FUN_00403e20(), false);
        float animSpeed = 1.0f / FUN_00716440();
        FUN_00950a60(!FUN_004eaf60())->FUN_0088b030(animSpeed);
        FUN_00950a60(FUN_004eaf60())->FUN_0088b030(animSpeed);
    }
    else if (!slowing)
    {
        void* effect = FUN_00483a00(DAT_0108b078);
        FUN_00529c90(effect);
        if (unke21)
            DAT_011f6394.ApplyGlobalTimeMultiplier();
        unke21 = false;
    }
    if (unk1f0 && !unk68->vf474(true))
    {
        FUN_00571760(unk1f0);
        unk1f0 = 0;
    }
    if (unk681 && !DAT_011dea0c->FUN_009443c0())
    {
        unk684 -= elapsed;
        if (unk684 < 0.0)
        {
            unk684 = 0.0f;
            unk681 = false;
        }
    }
    DAT_011e077c = 0;
    void* pickedRef = FUN_0056f930(unkd3c.FUN_00559450());
    UpdateTargetHealthHUD(pickedRef, unkd40);
    unkd3c.FUN_0066b0d0(0);
    FUN_008bbdb0();
    AutoMemContext mem((MEM_CONTEXT)0x34, true, DAT_0108a8e0, 0xc41);
    TickScene* scene = FUN_0045c670();
    TickWeapon* weapon = unk68->vf148() ? unk68->vf148()->FUN_0044ddc0() : 0;
    TickAnimation* thirdPersonAnim = FUN_00950a60(false);
    TickAnimation* firstPersonAnim = FUN_00950a60(true);
    bool flag = false;
    unsigned short animGroup = 0;
    BSSoundHandleEx sound;
    unk870 = 0.0f;
    unk874 = 0.0f;
    if (unk154 > 0.0)
        unk154 -= DAT_011f6394.FUN_0084d030();
    else
        unk150 = 0;
    FUN_00962d00();
    unk68->vf464(this);
    if (GetReferenceFromPhysicsController())
        SetEffectValue(7, DAT_010162c0, GetReferenceFromPhysicsController());
    if (GetActorFromPhysicsController() && unk154 <= 0.0)
        FUN_008bc240(*DAT_011cdde0.FUN_0043d4d0());
    bool weaponDrawn = FUN_008bbc10();
    if (weaponDrawn && unk68->vf454())
    {
        bool night = false;
        if (FUN_008d6f30()->FUN_00425fd0())
            night = true;
        else
        {
            TickSky* sky = DAT_011dea10->FUN_008d8520();
            float hour = sky->GetFieldEC();
            float sunrise = sky->FUN_00595f50();
            float sunset = sky->FUN_00595fc0();
            if (hour >= sunset || hour <= sunrise)
                night = true;
        }
        if (DAT_011f2250.FUN_0044ddc0() || unke18 > 0.0)
            night = false;
        TickEquip* equipped = unk68->vf148();
        TickWeapon* nightWeapon = equipped ? equipped->FUN_0044ddc0() : 0;
        if (nightWeapon && nightWeapon->IsFlagSet() && !unke08 && night &&
            (!nightWeapon->FUN_004ad030() || equipped->HasEffect(0xe)))
        {
            unke08 = true;
            void* effect = _ref_004839c0((unsigned int)0x8cd8c);
            FUN_005299a0(effect, 1.0f, 0);
        }
        else if (!night)
        {
            void* effect = _ref_004839c0((unsigned int)0x8cd8c);
            FUN_00529c90(effect);
            FUN_00963e00(9, 0);
            unke08 = false;
        }
        if (!FUN_00964100(9))
            SetEffectValue(9, DAT_01017868, 0);
    }
    else
    {
        if (unke08)
        {
            void* effect = _ref_004839c0((unsigned int)0x8cd8c);
            FUN_00529c90(effect);
            unke08 = false;
        }
        FUN_00963e00(9, 0);
    }
    if (weaponDrawn && !unke2e && DAT_011f2250.FUN_0044ddc0() != 4)
    {
        float perk = 0.0f;
        FUN_005e58f0(0x46, DAT_011dea3c, &perk);
        if (perk > 0.0)
        {
            unke2e = true;
            FUN_0093dd80();
        }
    }
    else if (unke2e && !weaponDrawn)
    {
        ((TickLists*)&DAT_011e0e80)->FUN_00974af0(DAT_011c3f2c->GetField630());
        unke2e = false;
    }
    if (unka4.vf008(0x32) > 0)
        unke2d = true;
    else if (unke2d && unka4.vf008(0x32) <= 0)
    {
        ((TickLists*)&DAT_011e0e80)->FUN_00974af0(DAT_011c3f2c->FUN_0089f4e0());
        unke2d = false;
    }
    float perk = 0.0f;
    FUN_005e58f0(0x47, DAT_011dea3c, &perk);
    unke30 -= elapsed;
    if (perk > 0.0 && unke30 <= 0.0 && weaponDrawn)
    {
        unke30 = *DAT_011d0658.FUN_00403e20();
        FUN_0093df50();
    }
    RemoveExpiredItems();
    if (FUN_004d1360())
        FUN_00969c30();
    TickProc* process = FUN_008d8520();
    process->vf500(this, 0);
    if (FUN_009678a0() && !vf214())
    {
        if (!FUN_00964100(8))
            SetEffectValue(8, DAT_01017868, 0);
    }
    else
        FUN_00963e00(8, 0);
    TickController* controller = FUN_009306d0();
    if (controller && controller->HasFlag20000())
    {
        if (!unk205)
        {
            ((TickLists*)&DAT_011e0e80)->FUN_00973de0();
            unk205 = true;
        }
    }
    else
        unk205 = false;
    TickProc* processB = FUN_008d8520();
    if (processB->vf65c() > 0.0)
    {
        TickProc* processC = FUN_008d8520();
        processC->vf658();
    }
    else
    {
        TickProc* processC = FUN_008d8520();
        processC->vf4a4(0.0f);
    }
    if (unk7c4)
    {
        if (vf2b4() <= 0.0)
        {
            FUN_00962190();
            TickProc* processC = FUN_008d8520();
            processC->vf2c8(*DAT_011d0b08.FUN_00403e20());
        }
        else
            vf2b8();
    }
    if (unk22c > 0.0)
        unk22c -= elapsed;
    else
        unk22c = DAT_01012054;
    if (unk234 > 0.0)
        unk234 -= elapsed;
    else
        unk234 = DAT_01012054;
    if (unk6e0 <= 0.0)
    {
        ((TickLists*)&DAT_011e0e80)->FUN_0096e570();
        unk6e0 = *DAT_011cd8f0.FUN_00403e20();
    }
    else
        unk6e0 -= elapsed;
    if (unk79d)
    {
        unk79d = false;
        RestorePlayerLocation(true);
    }
    if (GetField688())
    {
        GetField688()->Activate(this, false, 0, 1);
        SetField688(0);
        return;
    }

    TickProc* processC = FUN_008d8520();
    processC->vfd4(this);
    int processFlags = unk68->vf618();
    unk68->vf61c();
    if ((processFlags & 4) && !unk68->vf2b0(this))
        unk68->vf708(0);
    if ((processFlags & 8) && !unk68->vf2b8(this))
        unk68->vf708(0);
    unsigned short movement = GetVtbl20Result();
    if (FUN_004997b0() && FUN_004938e0())
    {
        if (FUN_007038a0() < 3 && unk66c)
        {
            if (unk668 > 1.0)
            {
                vf47c(0x2a, 0);
                unk668 = 0.0f;
            }
            else
                unk668 += elapsed;
        }
    }
    else if (FUN_005a2030() && FUN_004938e0())
    {
        if (unk664 > 1.0)
            unk664 = 0.0f;
        else
            unk664 += elapsed;
    }
    else if ((movement & 0x200) && FUN_004938e0())
    {
        if (unk660 > 1.0)
            unk660 = 0.0f;
        else
            unk660 += elapsed;
    }
    animGroup = movement & 0xcc00;
    unkb0->FUN_00ca1410();
    if (FUN_009445b0(elapsed, 0, &animGroup, false))
        flag = true;
    if ((!DAT_011e07b8 && !DAT_011e07c1 || unk68->vf610()) && unk68->FUN_008fec10(this))
    {
        if (unk634.FUN_00559450())
            FUN_0095f6a0();
        FUN_009481d0();
        unk64a = !unk64a;
        UpdateFaceAnimation(elapsed);
        FUN_008885e0(FUN_00950a60(!unk64a), elapsed);
        unk64a = !unk64a;
        UpdateFaceAnimation(elapsed);
        FUN_008885e0(FUN_00950a60(!unk64a), elapsed);
        UpdateCamera(false, false);
        return;
    }
    TickProc* processD = FUN_008d8520();
    if (processD->vf6dc() && !DAT_011f2250.FUN_00525430() && unk68->vf148())
    {
        int action = FUN_008a7570();
        if (action == 2 || action == 3 || action == 4 || action == 5 || action == 6)
        {
            TickWeapon* ammoWeapon = unk68->vf148()->FUN_0044ddc0();
            if (ammoWeapon)
            {
                bool enoughAmmo = true;
                if (ammoWeapon->FUN_00525980(DAT_011dea3c))
                {
                    TickAmmoList* ammo = unk68->vf14c();
                    if (!ammo)
                        enoughAmmo = false;
                    else if (ammo->FUN_00726070() < ammoWeapon->GetByteAt102())
                        enoughAmmo = false;
                }
            }
        }
    }
    if (unk68->vf40c() || vf234())
    {
        DAT_011f2250.FUN_009c8950(false, false);
        unk79a = false;
        DAT_011e0788 = 0;
        if (!unk64a)
            FUN_00950340(true);
    }

    if (FUN_0093a740() || vf22c(0))
    {
        if (unk64b && !unk64a && FUN_005a03f0(0x10))
            FUN_00951a10(true);
        unk190->vf00c(animGroup);
        if (DAT_011e0798 > DAT_01015a38 && (!vf214() || vf214() == 4))
        {
            if (FUN_0093a640() && vf214() == 4)
            {
                FUN_0093a6f0(false);
                unk68->vf214();
            }
            else if (vf22c(0) || !vf214())
            {
                unk68->vf214();
                FUN_0093a5f0(false);
                DAT_011e0798 = 0.0f;
            }
            FUN_0088d640();
            DAT_011e0798 = 0.0f;
            return;
        }
        if (GetByteAt798())
        {
            DAT_011e0798 += elapsed;
            if (unk68->vf228(this) || vf214() == 4 || unk68->vf4bc() == 9 || !unk68->vf27c())
            {
                FUN_0093a5f0(false);
                unk68->vf214();
                DAT_011e0798 = 0.0f;
            }
        }
        else if (FUN_0093a640())
        {
            DAT_011e0798 += elapsed;
            if (!vf214())
            {
                FUN_0093a6f0(false);
                unk68->vf214();
                DAT_011e0798 = 0.0f;
            }
        }
        if (unk64c == unk64a)
            FUN_00886360(elapsed);
        unk190->FUN_009ea570(*(MPt*)&DAT_011f426c);
        unk190->vf014(elapsed);

        if (*DAT_011cd62c.FUN_00403e20() > 0.0)
        {
            if (FUN_004f8960() == 2 || FUN_004f8960() == 1)
            {
                if (DAT_011a3b34 < 0.0)
                {
                    FUN_00709c40(0);
                    DAT_011a3b34 = *DAT_011cd62c.FUN_00403e20();
                }
                DAT_011a3b34 -= elapsed;
                if (DAT_011a3b34 < 0.0)
                {
                    DAT_011a3b34 = DAT_01012054;
                    if (!DAT_011de134->FUN_008512f0())
                        FUN_007d0a70();
                }
            }
            else
                DAT_011a3b34 = DAT_01012054;
        }
        else if (FUN_004f8960() == 2 && !DAT_011e07c0)
        {
            vf2a0();
            FUN_00709c40(0);
            if (DAT_011de134->IsField5Set())
                ShowMessageBox(DAT_011d4b40.FUN_00403df0(), 0, 0, FUN_00961d50, 1, 0x17, 0.0f, 0.0f,
                             DAT_011d400c.FUN_00403df0(), DAT_011d4528.FUN_00403df0(), 0);
            else
                FUN_007d0a70();
            DAT_011e07c0 = true;
        }
        vf1e0();
        if (unk64a)
            FUN_00895110(DAT_011a3b3c, DAT_011a3b40);
        unk64a = !unk64a;
        if (unk64a)
            FUN_00895110(DAT_011a3b3c, DAT_011a3b40);
        UpdateFaceAnimation(elapsed);
        FUN_008885e0(FUN_00950a60(!unk64a), elapsed);
        unk64a = !unk64a;
        UpdateFaceAnimation(elapsed);
        FUN_008885e0(FUN_00950a60(!unk64a), elapsed);
        UpdateCamera(false, false);
        FUN_008d6f30()->UpdateRefPlacement(this, 1, 0);
        FUN_00450b80(0)->FUN_00b5d9f0(vf1d0(), true);
        unk7b4 = FUN_008d6f30()->FUN_005474b0(0);
        if (unk79a)
        {
            if (DAT_011e0788)
            {
                static float repeatDelay = *DAT_011cd5c8.FUN_00403e20();
                if ((input->FUN_00a24660(5, 1) || input->FUN_00a24660(5, 0)) && !FUN_005a03f0(1))
                {
                    vf1e4()->FUN_00922650(7, 1);
                    repeatDelay -= elapsed;
                    while (repeatDelay < 0.0)
                    {
                        repeatDelay += *DAT_011cd5c8.FUN_00403e20();
                        if (DAT_011e0788)
                            DAT_011e0788->vf124(0, this, 0, 0, 0);
                    }
                }
                else
                {
                    BSSoundHandleEx repeatSound;
                    DAT_011dea3c->FUN_005d43c0()->SetValueFromExtraData(&repeatSound);
                    repeatSound.FUN_00ad88f0();
                    vf1e4()->FUN_00922650(7, 0);
                    repeatDelay = *DAT_011cd5c8.FUN_00403e20();
                    DAT_011e0788 = 0;
                }
            }
            if (vf1e4()->FUN_004985f0() && unk68->vf3e4() == -1 && !unk68->vf40c())
            {
                unk79a = false;
                DAT_011e0788 = 0;
            }
        }
        if (input->FUN_00a24660(0x1a, 1) && DAT_011de134->LoadQuickSave())
            DAT_011a3b34 = DAT_01012054;
        if (!vf22c(0) && !vf2e8())
        {
            FUN_008c3c40(0, 0);
            if (input->FUN_00a24660(5, 1) && !FUN_00967ae0() && !FUN_00702360() && !vf234() && !FUN_005721e0())
            {
                TickRef* target = FUN_00703350();
                bool activateFallback = true;
                bool blocked = false;
                if (target && target->FUN_00568680() && weaponDrawn)
                    blocked = true;
                if (FUN_005a03f0(1))
                    blocked = true;
                if (target && target->vf224())
                {
                    TickTargetCast* cast = (TickTargetCast*)FUN_00ec43fb(target, 0, &DAT_011841cc, &DAT_011a28e0, 0);
                    if (cast && !cast->FUN_008ce390())
                        blocked = true;
                }
                if (target && target->vf100())
                {
                    TickRef* actor = target;
                    TickProc* targetProcess = actor->FUN_008d8520();
                    if (targetProcess->vf610() == 5 || targetProcess->vf610() == 6)
                        blocked = true;
                }
                switch (vf214())
                {
                case 1:
                case 2:
                case 3:
                case 5:
                case 6:
                case 7:
                case 8:
                case 10:
                    blocked = true;
                    break;
                }
                switch (FUN_008a7570())
                {
                case -1:
                    break;
                default:
                    blocked = true;
                }
                if (unk64c != unk64a)
                    blocked = true;
                if (GetByteAtOffset681())
                    blocked = true;
                bool failed = false;
                if (!blocked)
                {
                    FUN_007062e0(0, 0, 0);
                    if (target)
                    {
                        TickList list;
                        FUN_005e58f0(0x1b, this, target, &list, target);
                        if (!list.FUN_008256d0())
                        {
                            if (!BuildActionMenu(&list, target))
                            {
                                int count = target->GetExtraDataShort();
                                if (target->Activate(this, false, 0, count))
                                    activateFallback = false;
                            }
                        }
                        else
                        {
                            int count = target->GetExtraDataShort();
                            if (target->Activate(this, false, 0, count))
                                activateFallback = false;
                        }
                    }
                    else
                        failed = true;
                    if (activateFallback && unk68->vf4c8())
                    {
                        if (!unk68->vf4c8()->Activate(this, false, 0, 1))
                            failed = true;
                        else
                            failed = false;
                    }
                    else if (activateFallback)
                        failed = true;
                }
                if (failed || blocked)
                {
                    FUN_005d43c0()->FUN_00418940(&sound);
                    TickSoundForm* errorSound = GetUIActivateNothingSound();
                    if (!sound.FUN_00ad8ce0() && errorSound)
                        sound = FUN_00453a70()->FUN_00ad7480(errorSound->FUN_00511840(), 0x121, errorSound);
                    if (!sound.FUN_00ad8930())
                        sound.Play(false);
                    FUN_005d43c0()->FUN_0041a090(&sound);
                }
                flag = true;
            }
        }
        return;
    }
    else
    {
        if (DAT_011dea3c->unk68->vf22c())
            DAT_011dea3c->unk68->vf234();
        if (DAT_011dea3c->unk68->vf20c())
            DAT_011dea3c->unk68->vf214();
    }

    FUN_00953d40();
    UpdatePlayerStateIfActive();
    bool weaponToggled = false;
    unkd50 += elapsed;
    if (input->FUN_00a24660(0x12, 1) && unk68->vf148() && FUN_008a16d0())
    {
        int key1 = FUN_00717a40(1, 0);
        int key4 = FUN_00717a40(4, 0);
        int key3 = FUN_00717a40(3, 0);
        bool available1 = key1 == 2 || key1 == 0;
        bool available4 = key4 == 2 || key4 == 0;
        bool available3 = key3 == 2 || key3 == 0;
        if (!available1 || available1 && !available4 && !available3)
        {
            bool toggle = unkd50 > *DAT_011cd158.FUN_00403e20() ? true : false;
            FUN_009462c0(toggle, false);
            if (toggle)
                unkd50 = 0.0f;
        }
    }
    if (input->FUN_00a24660(7, 1) || input->FUN_00a24660(7, 0))
    {
        if (!FUN_005a03f0(8))
        {
            DAT_011e07e0 += elapsed;
            if (FUN_008843a0() && FUN_008a7570() == -1)
            {
                if (!DAT_011e0bc1 &&
                    (DAT_011e07e0 > *DAT_011cdfcc.FUN_00403e20() || !weapon ||
                     !weapon->FUN_00525980(DAT_011dea3c) && !weapon->unka4.FUN_00474a80()) &&
                    FUN_008a6970())
                {
                    weaponToggled = true;
                    SetWantsWeaponOut(false);
                    DAT_011e0bc1 = true;
                }
                else if (!DAT_011e0bc1 && !FUN_008a6970())
                {
                    if (!(GetVtbl20Result() & 0x800))
                        SetWantsWeaponOut(true);
                    DAT_011e0bc1 = true;
                }
            }
        }
    }
    else if (!input->FUN_00a24660(7, 2))
    {
        DAT_011e07e0 = 0.0f;
        DAT_011e0bc1 = false;
    }
    FUN_009673d0(elapsed);
    if (input->FUN_00a24660(0xa, 1))
        unk651 = !unk651;
    if (input->FUN_00a24660(0xb, 1))
        unk652 = !unk652;
    if (unk652 && !FUN_00709bc0() && !FUN_00702360())
    {
        if (input->FUN_00a24660(0, 0) || input->FUN_00a24660(1, 0) || input->FUN_00a24660(3, 0) ||
            input->FUN_00a24660(2, 0))
            unk652 = false;
        else
            input->FUN_00a24280(0);
    }
    bool sneakPressed = false;
    if (input->FUN_00a24660(8, 1))
    {
        if (!vf234() && !vf22c(0) && !vf230() && !FUN_00437bf0() && !FUN_00437bd0() && !FUN_005a03f0(0x40) && !vf214())
        {
            switch (FUN_008a7570())
            {
            case -1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 9:
            case 17:
                if (animGroup & 0x400)
                {
                    animGroup &= ~0x400;
                    sound = FUN_00453a70()->FUN_00ad7550(DAT_0108b064, 0x40102);
                    sound.SetPositionFromArray(vf1f4());
                    sound.Play(false);
                    vf340(0xb);
                }
                else
                {
                    animGroup |= 0x400;
                    sound = FUN_00453a70()->FUN_00ad7550(DAT_0108b050, 0x40102);
                    sound.SetPositionFromArray(vf1f4());
                    sound.Play(false);
                    vf340(0xa);
                }
                if (!unk64f)
                {
                    SetActiveState(0, 0, 0);
                    FUN_00894cc0(false);
                }
                break;
            }
        }
        sneakPressed = true;
    }

    TickMatrix cameraMatrix = *scene->FUN_00558310()->FUN_006a9540();
    MPt origin = *FUN_00436aa0();
    MPt oldOrigin = origin;
    MPt forward;
    MPt side;
    side = MPt(1.0f, 0.0f, 0.0f);
    cameraMatrix.FUN_00439f50(1, &forward);
    if (!FUN_0050d4a0())
    {
        forward.z = 0.0f;
        forward.FUN_004a0c10();
    }
    else
        cameraMatrix.FUN_00439f50(0, &side);
    bool adjusted = false;
    if (unk63c == 2)
        adjusted = FUN_009613c0(elapsed);
    FUN_00962350();
    int axisX = 0;
    int axisY = 0;
    int axisZ = 0;
    if (!FUN_004b71d0())
        goto axesDone;
    {
        axisX = input->GetAxisState(0, 7);
        axisZ = input->GetAxisState(0, 9);
        axisY = input->GetAxisState(0, 8);
        if (FUN_00ec7d40(axisX) < 0x1ea9)
            axisX = 0;
        if (FUN_00ec7d40(axisY) < 0x1ea9)
            axisY = 0;
        if (FUN_00ec7d40(axisZ) < 0x21f1)
            axisZ = 0;
        axisX = axisX * 100 / 0x7fff;
        axisY = axisY * 100 / 0x7fff;
        axisZ = axisZ / 0x7fff;
    }
axesDone:
    if (!FUN_004b71d0())
    {
        if (axisX)
        {
            if (axisX > 0)
                input->FUN_00a24280(3);
            else if (axisX < 0)
                input->FUN_00a24280(2);
            DAT_011a3b40 = (float)(FUN_00ec7d40(axisX) * (double)*DAT_011e0964.FUN_00403e20());
            if (DAT_011a3b40 > DAT_01016ff0)
                DAT_011a3b40 = DAT_01016088;
        }
        if (FUN_00ec7d40(axisY) < FUN_00ec7d40(axisX))
        {
            DAT_011a3b3c = (float)(FUN_00ec7d40(axisX) * DAT_0108b048);
            if (axisX < 0)
                animGroup |= 4;
            else
                animGroup |= 8;
        }
        else if (axisY)
        {
            if (axisY < 0)
                input->FUN_00a24280(0);
            else if (axisY > 0)
                input->FUN_00a24280(1);
            DAT_011a3b3c = (float)(FUN_00ec7d40(axisY) * DAT_0108b048);
        }
    }
    TickEquip* currentEquip = unk68->vf148();
    TickWeapon* currentWeapon = currentEquip ? currentEquip->FUN_0044ddc0() : 0;
    if (DAT_011a3b3c > 1.0)
        DAT_011a3b3c = 1.0f;
    bool gamepad = FUN_004b71d0();
    // Analog and keyboard movement are reconstructed in following regions.

    if (gamepad)
    {
        float analogX = 0.0f;
        float analogY = 0.0f;
        float analogZ = 0.0f;
        analogX = (float)(axisX / 100.0);
        analogY = (float)(axisY / 100.0);
        analogZ = (float)(axisZ / 100.0);
        if (FUN_008a7570() == 0xb)
        {
            analogX = 0.0f;
            analogY = 0.0f;
            analogZ = 0.0f;
        }
        MPt move;
        bool yDominant = FUN_00408840(analogX) < FUN_00408840(*DAT_011e0b94.FUN_00403e20() * analogY);
        if (!yDominant)
        {
            if (analogX < 0.0)
                animGroup |= 4;
            else if (analogX > 0.0)
                animGroup |= 8;
        }
        if (yDominant)
        {
            if (analogY < 0.0)
                animGroup |= 2;
            else if (analogY > 0.0)
                animGroup |= 1;
        }
        move.x = analogX;
        move.y = analogY;
        move.z = 0.0f;
        DAT_011a3b3c = 0.0f;
        bool running = false;
        MPt planar;
        planar.x = analogX;
        planar.y = analogY;
        planar.z = 0.0f;
        float magnitude = planar.FUN_00457990() > 1.0 ? 1.0f : planar.FUN_00457990();
        if (DAT_011a3b3c < 1.0)
        {
            if (magnitude > DAT_0107d1b8)
            {
                DAT_011a3b3c = 1.0f;
                running = true;
            }
            else if (magnitude > DAT_010217d8)
            {
                DAT_011a3b3c = LinearInterpolate(DAT_01018238, 1.0f, DAT_01030ff0, 1.0f, magnitude);
                running = true;
            }
            else
                DAT_011a3b3c = LinearInterpolate(DAT_0101e2bc, DAT_01053154, 0.0f, DAT_01030ff0, magnitude);
        }
        if (move.FUN_00457990() > 0.0)
        {
            if (input->FUN_00a24660(9, 1) || input->FUN_00a24660(9, 0) || running)
            {
                if (unk68->vf3e4() != 7 && !vf358() && !FUN_008bbc10() && unk640 <= *DAT_011d097c.FUN_00403e20())
                    animGroup |= 0x200;
                else
                {
                    DAT_011a3b3c = *DAT_011e0b78.FUN_00403e20();
                    animGroup |= 0x100;
                }
            }
            else
                animGroup |= 0x100;
        }
        if (DAT_011a3b3c > 1.0 && vf358())
            DAT_011a3b3c = 1.0f;
        if (DAT_011a3b3c > 1.0 && FUN_008bbc10())
            DAT_011a3b3c = 1.0f;
        if (FUN_00408840(analogZ) > FUN_00408840(analogX) && FUN_00408840(analogZ) > FUN_00408840(analogY))
            DAT_011a3b40 = (float)(FUN_00408840(analogZ) * DAT_01016ff0);
        else
            DAT_011a3b40 = (float)(FUN_00408840(analogX) * DAT_01016ff0);
        move *= FUN_008a0b10() * DAT_011a3b3c;
        if (FUN_0050d4a0())
        {
            TickMatrix pitch;
            pitch.FUN_00524ac0(-FUN_00931d70());
            move = FUN_004b3ae0(move, &pitch);
        }
        move *= DAT_0108b044;
        origin += move;
        side = move;
    }
    else
    {
        DAT_011a3b3c = 1.0f;
        animGroup |= 0x40;
        TickPoint2 planar;
        planar.x = (float)axisX;
        planar.y = (float)axisY;
        if (planar.FUN_00589850() > DAT_01066808)
        {
            input->FUN_00a24280(9);
            if (unk68->vf3e4() != 7 && !vf358() && !FUN_008bbc10())
                animGroup |= 0x200;
        }
        if (!FUN_004b71d0() && unk651)
        {
            if (!input->FUN_00a24660(9, 1) && !input->FUN_00a24660(9, 0) && unk68->vf3e4() != 7 && !vf358() &&
                !FUN_008bbc10())
            {
                input->FUN_00a24280(9);
                animGroup |= 0x200;
            }
        }
        else if ((input->FUN_00a24660(9, 1) || input->FUN_00a24660(9, 0)) && unk68->vf3e4() != 7 && !vf358() &&
                 !FUN_008bbc10())
            animGroup |= 0x200;
        if (unk640 > *DAT_011d097c.FUN_00403e20())
            animGroup &= ~0x200;
        float speed = FUN_008a0b10();
        side *= speed * DAT_011a3b3c;
        forward *= speed * DAT_011a3b3c;
        if (input->FUN_00a24660(0, 1) || input->FUN_00a24660(0, 0))
        {
            origin += forward;
            if (!(animGroup & 0x200))
                animGroup |= 0x100;
            animGroup |= 1;
        }
        if (input->FUN_00a24660(1, 1) || input->FUN_00a24660(1, 0))
        {
            origin -= forward;
            if (!(animGroup & 0x200))
                animGroup |= 0x100;
            animGroup |= 2;
        }
        if (input->FUN_00a24660(2, 1) || input->FUN_00a24660(2, 0))
        {
            origin -= side;
            if (!(animGroup & 0x200))
                animGroup |= 0x100;
            animGroup |= 4;
        }
        if (input->FUN_00a24660(3, 1) || input->FUN_00a24660(3, 0))
        {
            origin += side;
            if (!(animGroup & 0x200))
                animGroup |= 0x100;
            animGroup |= 8;
        }
    }
    if (DAT_011f2250.FUN_0044ddc0() == 4)
        animGroup &= ~0x3f;
    unk190->vf00c(animGroup);
    if (sneakPressed)
        FUN_00884f80();
    unk190->vf018(elapsed);
    FUN_009503d0();
    FUN_00950530();
    unk648 = unk64a;
    unk649 = true;
    unk64a = true;
    if (!(input->FUN_00a24660(4, 0) && DAT_011e07aa && unk68->vf14c() && FUN_008a6970()) && unk68->vf444() != 0.0 &&
        !(DAT_011f2250.FUN_0044ddc0() == 4 && DAT_011f2250.FUN_009c71c0() && DAT_011f2250.FUN_009c71c0()->unk08))
        unk68->vf434(0);
    bool controlsBlocked = false;
    if (vf230() || vf234() || FUN_004f8960() || FUN_008a7570() == 0xa || unk68->vf4bc())
        controlsBlocked = true;
    if (controlsBlocked || FUN_005a03f0(1))
        unk190->FUN_009ea360(0x33f, 0);

    if (!controlsBlocked && !FUN_005a03f0(8))
    {
        if (unk63c != 2 && unk63c != 3)
        {
            if (input->FUN_00a24660(6, 1) || input->FUN_00a24660(6, 0))
            {
                if (unk68->vf3e4() != 7 && !FUN_008bbc10() && unk64c == unk64b && !FUN_00967ae0() && unk68->vf3f8())
                {
                    if ((weapon && (!weapon->FUN_006450c0() || !FUN_008a16d0())) || (!weapon && !FUN_008a16d0()))
                        SetActiveState(1, 0, 0);
                    else
                        FUN_00894cc0(true);
                    if (!DAT_011e07b8 || DAT_011e07b9)
                        flag = true;
                }
            }
            else if (input->FUN_00a24660(6, 2) || !input->FUN_00a24660(6, 0) || FUN_00967ae0())
            {
                if (FUN_008bbc10() || unk68->vf3e4() == 7)
                {
                    SetActiveState(0, 0, 0);
                    FUN_00894cc0(false);
                    flag = true;
                }
            }
            if (unk68->vf3f8() && !(animGroup & 0x800))
            {
                if (FUN_00948310())
                    flag = true;
            }
            else
            {
                DAT_011e07ac = 0;
                DAT_011e07b0 = 0.0f;
            }
        }
        else
        {
            DAT_011e07ac = 0;
            DAT_011e07b0 = 0.0f;
        }
    }
    if (!controlsBlocked && !FUN_005a03f0(1) && input->FUN_00a24660(0xc, 1) && !vf358() &&
        !FUN_005f2670(vf1e4()->FUN_004301b0(4)) && FUN_008a7570() != 0xb)
    {
        TickAnimation* jumpAnim = vf1e4();
        if (FUN_008a7570() == 0xc && jumpAnim->FUN_00491040(1) &&
            jumpAnim->FUN_00491040(1)->FUN_0048f7f0()->FUN_005f4db0())
            FUN_008a73e0(-1, 0);
        if (FUN_008a7570() != 0xc)
        {
            bool ready = !FUN_008849c0() && !FUN_005a2030();
            bool aiming = input->FUN_00a24660(6, 0) != 0;
            bool special = FUN_00894d60();
            if (aiming)
            {
                if (!FUN_00703350() && (animGroup | 0xf))
                {
                    if (!FUN_009306d0()->FUN_005c0880())
                        SetAnimationGroupFromFlags((unsigned char)animGroup);
                }
                else if (!special && FUN_009306d0()->HasFlag400())
                    vf254();
            }
            else if (FUN_009306d0()->HasFlag400())
                vf254();
            FUN_0095f6a0();
            flag = true;
        }
    }
    if (!vf448() && FUN_005d43c0()->FUN_0041cd70())
        FUN_005d43c0()->FUN_0041cda0();

    bool menuBusy = false;
    if (input->FUN_00a24660(0xf, 1) && !FUN_005a03d0())
    {
        if (vf448())
            DispatchMessageToSink(DAT_011d4474.FUN_00403df0(), 0, DAT_010208a0, 0, DAT_010162c0, false);
        else if (HasActorsByPackage())
            DispatchMessageToSink(DAT_011d28b0.FUN_00403df0(), 0, DAT_010208a0, 0, DAT_010162c0, false);
        else if (FUN_00885520(vf1f4(), FUN_008d6f30(), DAT_01084d20))
            DispatchMessageToSink(DAT_011d4948.FUN_00403df0(), 0, DAT_010208a0, 0, DAT_010162c0, false);
        else if (((TickLists*)&DAT_011e0e80)->HasNearbyDetectedActor(DAT_011dea3c->FUN_00575d10()))
            DispatchMessageToSink(DAT_011d2e50.FUN_00403df0(), 0, DAT_010208a0, 0, DAT_010162c0, false);
        else if (DAT_011dea3c->FUN_009306d0()->FUN_005c0880() == 1 || DAT_011dea3c->FUN_009306d0()->FUN_005c0880() == 2)
            DispatchMessageToSink(DAT_011d3e20.FUN_00403df0(), 0, DAT_010208a0, 0, DAT_010162c0, false);
        else if (DAT_011dea3c->FUN_008d6f30()->FUN_005444c0() || !DAT_011dea3c->GetByteAt66E())
            DispatchMessageToSink(DAT_011d20ac.FUN_00403df0(), 0, DAT_010208a0, 0, DAT_010162c0, false);
        else if (((TickLists*)&DAT_011e0e80)->IsFlagged())
            DispatchMessageToSink(DAT_011d4b10.FUN_00403df0(), 0, DAT_010208a0, 0, DAT_010162c0, false);
        else if (FUN_008d8520() && FUN_008d8520()->vf764() != 0.0)
            DispatchMessageToSink(DAT_011d4b10.FUN_00403df0(), 0, DAT_010208a0, 0, DAT_010162c0, false);
        else if (DAT_011dea3c->unk94.FUN_00822e00())
            DispatchMessageToSink(DAT_011d47d4.FUN_00403df0(), 0, DAT_010208a0, 0, DAT_010162c0, false);
        else
            FUN_007054f0(0);
    }
    unk64a = true;
    vf1e0();
    FUN_00895110(DAT_011a3b3c, DAT_011a3b40);
    unk68->vf41c(this);
    unk64a = unk648;
    unk649 = false;
    if (FUN_005a1e50())
        FUN_0094df80();
    if (FUN_00456c70() || *DAT_011e0b64.FUN_00408d60())
    {
        if (!FUN_0050d4a0())
        {
            MVec4 scratch;
            TickController* controller = FUN_009306d0();
            if (controller)
            {
                controller->FUN_005620e0(&origin);
                controller->FUN_0080fb00(FUN_00458b20());
            }
            FUN_00693ef0(true);
        }
        MPt delta = origin - oldOrigin;
        delta *= elapsed;
        vf2a8(oldOrigin + MPt(0.0f, 0.0f, delta.z));
    }
    else
        FUN_00693ef0(false);
    unk190->FUN_009ea570(side);
    unk190->vf014(elapsed);
    FUN_00947b10();
    if (animGroup & 0xf)
        flag = true;
    if (input->FUN_00a24660(0x19, 1))
        DAT_011de134->FUN_008509a0();
    if (input->FUN_00a24660(0x1a, 1))
        DAT_011de134->LoadQuickSave();

    bool povPressed = input->FUN_00a24660(0x10, 1) > 0;
    if (DAT_011e0780 ||
        (povPressed && !FUN_005a03f0(8) && !vf214() && DAT_011f2250.FUN_0044ddc0() != 4 && !FUN_00967ae0() &&
         !FUN_00705a00() && !DAT_011f2250.FUN_0044ddc0() && !(GetVtbl20Result() & 0x800)))
    {
        if (FUN_007f52c0())
        {
            if (povPressed)
                DAT_011f21d1 = !DAT_011dea3c->FUN_004eaf60();
            bool switchNow = false;
            switch (FUN_008a7570())
            {
            case -1:
            case 7: {
                TickSequence* sequence = thirdPersonAnim->FUN_00491040(4);
                TickSequence* sequence2 = thirdPersonAnim->FUN_00491040(4);
                TickAnimGroup* group = sequence ? sequence->FUN_0048f7f0() : 0;
                int type = group ? group->FUN_005f2420() : 0xff;
                if (type < 0xc4 || type >= 0xc7)
                    switchNow = true;
                else if (sequence)
                {
                    thirdPersonAnim->FUN_004974a0();
                    thirdPersonAnim->FUN_004994f0(4, false);
                    if (sequence2)
                    {
                        firstPersonAnim->FUN_004974a0();
                        firstPersonAnim->FUN_004994f0(4, false);
                    }
                }
                break;
            }
            }
            if (switchNow && !unk64f && FUN_00716440() == FUN_009443f0() && !unk64d && FUN_008a16d0() &&
                !FUN_00950090() && !unk64a && unk64c == unk64a)
            {
                FUN_00529c90(FUN_005d2860());
                DAT_011dea0c->FUN_0086fd90(true);
                FUN_00705640();
                DAT_011e0780 = false;
            }
            else
            {
                DAT_011e0780 = true;
                SetWantsWeaponOut(true);
                if (FUN_00950090() || unk64a)
                {
                    FUN_009500a0();
                    FUN_00951a10(true);
                    unk64c = false;
                    unk64a = false;
                }
            }
        }
        else
        {
            FUN_00453a70()->FUN_00ad7550(DAT_01077d84, 0x121).Play(false);
            DAT_011e0780 = false;
        }
        flag = true;
    }
    if (!FUN_00967ae0() && !DAT_011e0788 && !unk64f && (!unk64d || DAT_011e07b8) && !DAT_011e0780)
    {
        if ((input->FUN_00a24660(0xd, 1) || input->FUN_00a24660(0xd, 0)) && !FUN_005a03f0(0x10))
        {
            if (!FUN_00702360() && DAT_011a3b31)
            {
                flag = true;
                DAT_011e07c1 = true;
                if (!DAT_011e07b8)
                {
                    DAT_011e0bc0 = unk64b;
                    ToggleFirstPerson(false);
                    DAT_011e07c4 = 0.0f;
                    DAT_011e07b9 = false;
                    DAT_011e07b8 = true;
                    UpdateVisibilityState(0x14);
                    DAT_011e0b60 = 0.0f;
                    DAT_011e0bbc = DAT_011e0b5c;
                }
                DAT_011e07c8 += elapsed;
            }
        }
        else if (input->FUN_00a24660(0xd, 2) || (DAT_011e07b8 && !DAT_011e07b9))
        {
            DAT_011e07c4 = 0.0f;
            DAT_011e07b9 = false;
            DAT_011e07b8 = false;
            UpdateVisibilityState(1);
            if (DAT_011e07c8 < *DAT_011cde8c.FUN_00403e20() && (FUN_004b71d0() || DAT_011e0bbc == DAT_011e0b5c) &&
                !FUN_005a03f0(0x10))
            {
                if (DAT_011e0bc0)
                    ToggleFirstPerson(!unk64e);
                unk64d = false;
                unk64e = false;
            }
            DAT_011e07c8 = 0.0f;
            flag = true;
            DAT_011e07c1 = false;
            DAT_011e0b58 = 0.0f;
            DAT_011e0b60 = 0.0f;
        }
    }

    bool movingTarget = false;
    if (unk68->vf4c8() && (animGroup & 0xf))
        movingTarget = true;
    if ((input->FUN_00a24660(5, 1) || movingTarget) && !DAT_011e0780 && !FUN_00967ae0() && !FUN_00702360() &&
        !vf234() && !adjusted && !FUN_005721e0())
    {
        TickRef* target = FUN_00703350();
        bool activateFallback = true;
        bool blocked = false;
        if (target && target->FUN_00568680() && weaponDrawn)
            blocked = true;
        if (FUN_005a03f0(1))
            blocked = true;
        if (target && target->vf224())
        {
            TickTargetCast* cast = (TickTargetCast*)FUN_00ec43fb(target, 0, &DAT_011841cc, &DAT_011a28e0, 0);
            if (cast && !cast->FUN_008ce390())
                blocked = true;
        }
        if (target && target->vf100())
        {
            TickRef* actor = target;
            TickProc* targetProcess = actor->FUN_008d8520();
            if (!actor->vf22c(0) &&
                (actor->FUN_00885520(actor->vf1f4(), actor->FUN_008d6f30(), DAT_01084d20) ||
                 DAT_011dea3c->FUN_00885520(DAT_011dea3c->vf1f4(), FUN_008d6f30(), DAT_01084d20) ||
                 (targetProcess && targetProcess->vf610() == 5) || (targetProcess && targetProcess->vf610() == 6)))
                blocked = true;
        }
        switch (vf214())
        {
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
        case 7:
        case 8:
        case 10:
            blocked = true;
            break;
        }
        switch (FUN_008a7570())
        {
        case -1:
            break;
        default:
            blocked = true;
        }
        if (unk64c != unk64a)
            blocked = true;
        if (GetByteAtOffset681())
            blocked = true;
        bool failed = false;
        if (!blocked)
        {
            if (!target || !target->vf100())
                FUN_007062e0(0, 0, 0);
            if (target && !movingTarget)
            {
                TickList list;
                FUN_005e58f0(0x1b, this, target, &list, target);
                if (!list.FUN_008256d0())
                {
                    if (!BuildActionMenu(&list, target))
                    {
                        int count = target->GetExtraDataShort();
                        if (target->Activate(this, false, 0, count))
                            activateFallback = false;
                    }
                }
                else
                {
                    int count = target->GetExtraDataShort();
                    if (target->Activate(this, false, 0, count))
                        activateFallback = false;
                    else if (target->FUN_00569160() && target->FUN_00569160()->FUN_004309e0(target) != 5 &&
                             !target->FUN_0057b460())
                        activateFallback = false;
                }
            }
            else
                failed = true;
            if (activateFallback && unk68->vf4c8())
            {
                if (!unk68->vf4c8()->Activate(this, false, 0, 1))
                    failed = true;
                else
                    failed = false;
            }
            else if (activateFallback)
                failed = true;
        }
        if (failed || blocked)
        {
            BSSoundHandleEx failSound;
            FUN_005d43c0()->FUN_00418940(&failSound);
            TickSoundForm* errorSound = GetUIActivateNothingSound();
            if (!failSound.FUN_00ad8ce0() && errorSound)
                failSound = FUN_00453a70()->FUN_00ad7480(errorSound->FUN_00511840(), 0x121, errorSound);
            if (!failSound.FUN_00ad8930())
                failSound.Play(false);
            FUN_005d43c0()->FUN_0041a090(&failSound);
        }
        flag = true;
    }
    if (DAT_011e07b9)
    {
        if (flag || FUN_005a03f0(0x10))
            FUN_009500a0();
        else
        {
            DAT_011e08fc -= *DAT_011cd4cc.FUN_00403e20() * DAT_01023128 * elapsed;
            DAT_011e0bb8 += *DAT_011cd198.FUN_00403e20() * DAT_01023128 * elapsed;
            DAT_011e08f4 = (float)(FUN_004e44b0(DAT_011e0bb8) * (double)*DAT_011cd984.FUN_00403e20() * DAT_01023128);
            if (DAT_011e0bb8 > DAT_0101ff48)
                DAT_011e0bb8 = (float)(DAT_011e0bb8 - DAT_0101ff48);
        }
    }
    else if (!DAT_011e07b8)
    {
        if (flag)
            DAT_011e07c4 = 0.0f;
        else
            DAT_011e07c4 += elapsed;
        if (DAT_011e09e0.FUN_004b9930() && DAT_011e07c4 > *DAT_011ccf50.FUN_00403e20() && !FUN_005a03f0(0x10))
        {
            DAT_011e07bc = DAT_011e0b5c;
            DAT_011e08fc = 0.0f;
            if (unk64a)
                DAT_011e08f4 = FUN_00931d70();
            else
                DAT_011e08f4 = 0.0f;
            FUN_00950340(true);
            DAT_011e07b9 = true;
            DAT_011e07b8 = true;
            UpdateVisibilityState(0x14);
            DAT_011e07c3 = true;
        }
    }
    FUN_0095f6c0(elapsed);
    if (DAT_011e07ec && DAT_011e0bb4++ < 0x14)
    {
        MPt debugPos = origin;
        debugPos.z += 128.0;
        debugPos.y += DAT_010240c0;
        debugPos.x += DAT_010240c0;
        DAT_011e07ec->FUN_005610f0(&debugPos);
        DAT_011e07ec->FUN_005615d0(*(MPt*)&DAT_011f426c);
    }
    if (!vf22c(0) && !vf2e8())
        FUN_008c3c40(0, 0);
    firstPersonAnim->SetMoveSpeed(thirdPersonAnim->FUN_009442a0());
    firstPersonAnim->FUN_004c0c90(thirdPersonAnim->FUN_00508070());
    if (!FUN_007050d0())
        UpdateScopeZoom(elapsed);
    unk64a = !unk64a;
    UpdateFaceAnimation(elapsed);
    FUN_008885e0(FUN_00950a60(!unk64a), elapsed);
    unk64a = !unk64a;
    UpdateFaceAnimation(elapsed);
    FUN_008885e0(FUN_00950a60(!unk64a), elapsed);
    ProcessEvents();
    if (!DAT_011f21d0)
        UpdateCamera(false, false);
    FUN_008d6f30()->UpdateRefPlacement(this, 1, 0);
    FUN_00450b80(0)->FUN_00b5d9f0(vf1d0(), true);
    if (unk68->vf6b8())
        unk68->vf6b8()->FUN_009bb080(elapsed, this);
    if (vf22c(0) &&
        !(DAT_011f2250.FUN_0044ddc0() == 4 && DAT_011f2250.FUN_009c71c0() && DAT_011f2250.FUN_009c71c0()->unk00 == 0xf))
        DAT_011f2250.CreateCommandAndUpdateHUD();
    FUN_00555c20();
    if (!DAT_011e0bb0 || DAT_011e0bb0 != FUN_008d6f30())
    {
        DAT_011e0bb0 = FUN_008d6f30();
        if (DAT_011c3b3c->FUN_00447950(DAT_011e0bb0))
        {
            DAT_011dea10->FUN_004581e0(DAT_0108b028);
            DAT_011c3b3c->UpdateRelationStates(DAT_011e0bb0);
            DAT_01202d98->FUN_00c3dfa0(0);
        }
    }
    menuBusy = false;
    if (FUN_00464e10()->FUN_008d51f0() && !FUN_00953c50(&menuBusy) && !DAT_011f2250.FUN_00525430() && FUN_009444a0() &&
        IsSomethingZero() && !FUN_00944270() && !FUN_005c7870())
        FUN_00464e10()->LevelUpPlayer();
    if (unke0c && !FUN_00953c50(&menuBusy) && !DAT_011f2250.FUN_00525430() && !FUN_007050d0() && !IsStartMenuFlag1Set())
    {
        unke0c->ShowMessageBox();
        unke0c = 0;
    }
    if (unk68)
        unk68->vf104();
    FUN_009444d0(elapsed);

    if (DAT_011dea3c->FUN_00894900())
    {
        if (DAT_011e0bac < 1.0)
        {
            DAT_011e0bac = 1.0f;
            TickFace* face = FUN_008adcb0();
            if (face)
                face->vf114(0xe, 1.0f);
        }
    }
    else if (DAT_011e0bac > 0.0)
    {
        DAT_011e0bac = 0.0f;
        TickFace* face = FUN_008adcb0();
        if (face)
            face->vfb4(DAT_01016248, 1, 0, 0, 0, 0);
    }
    if (weaponToggled && unkd6c < *DAT_011ce3a8.FUN_00403e20() && unkd70 <= 0.0 && FUN_00967da0())
        unkd70 = *DAT_011cedb8.FUN_00403e20();
    if (unkd70 > 0.0)
    {
        unkd70 -= elapsed;
        unkd70 = FUN_00404010(unkd70, 0.0f);
    }
    if (unk68->vf148())
    {
        TickWeapon* regenWeapon = unk68->vf148()->FUN_0044ddc0();
        if (regenWeapon->FUN_00709430(unk68->vf148()->HasEffect(6)) > 0.0)
        {
            FUN_009442e0(FUN_00944300() - DAT_011f6394.FUN_0084d030());
            if (unk68->vf14c() && FUN_00944300() <= 0.0)
            {
                FUN_009442e0(regenWeapon->FUN_00709430(unk68->vf148()->HasEffect(6)));
                int ammo = unk68->vf14c()->FUN_00726070();
                if (ammo < regenWeapon->GetFlaggedValue(unk68->vf148()->HasEffect(2)))
                {
                    ++ammo;
                    unk68->vf14c()->FUN_006ecd40(ammo);
                }
            }
            else if (FUN_00944300() <= 0.0)
            {
                TESContainer container;
                container.FUN_004818e0(weapon->FUN_00525980(DAT_011dea3c), 1, 0);
                container.FUN_004821a0(DAT_011dea3c, 1);
                DAT_011dea3c->FUN_0088c830(weapon->FUN_00525980(DAT_011dea3c), 1, 0, true, false, false);
            }
        }
    }
    if (FUN_004938e0())
    {
        TickCell* cell = FUN_008d6f30();
        if (cell)
        {
            TickRefList* item = cell->FUN_009604f0();
            if (DAT_011e0ba8 < FUN_00457fe0())
            {
                while (item && *item->FUN_006815c0())
                {
                    if ((*item->FUN_006815c0())->FUN_00401170() == 0x3a)
                    {
                        TESObjectSTAT* stat =
                            dynamic_cast<TESObjectSTAT*>((TESBoundObject*)(*item->FUN_006815c0())->FUN_007af430());
                        if (stat && stat->unk50 != -1)
                        {
                            TickRef* refA = *item->FUN_006815c0();
                            if (refA->vf1d0())
                            {
                                TickRef* refB = *item->FUN_006815c0();
                                float radius = refB->vf1d0()->GetHeadTail();
                                radius *= radius;
                                TickRef* refC = *item->FUN_006815c0();
                                if ((double)radius > (*refC->vf1f4() - *vf1f4()).FUN_004a7290())
                                {
                                    TickSoundID* ambient = GetBrushSound(stat->unk50);
                                    if (ambient)
                                    {
                                        FUN_00453a70()
                                            ->FUN_00ad73b0(ambient->FUN_0084e3a0(), 0x101)
                                            .Play(false);
                                        DAT_011e0ba8 = FUN_00457fe0() + FUN_00944460(1500, 2000);
                                    }
                                }
                            }
                        }
                    }
                    item = item->FUN_00726070();
                }
            }
        }
    }
    FUN_00964260();
    if (unk1a0)
    {
        bool enoughAmmo = true;
        TickAmmoList* ammo = unk68->vf14c();
        if (!ammo)
            enoughAmmo = false;
        else if (ammo->FUN_00726070() < weapon->GetByteAt102())
            enoughAmmo = false;
        if (!enoughAmmo || input->FUN_00a24660(4, 2) || !input->FUN_00a24660(4, 0))
            unk1a0->FUN_009ab9a0(this);
        unk1a0->vf310(0.0f);
    }
    if (unke24 > 0.0 && (double)FUN_00457fe0() - unke24 > *DAT_011d03a0.FUN_00403e20() * 1000.0)
        unke24 = DAT_01012054;
}
