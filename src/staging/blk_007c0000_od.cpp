
// src/staging/blk_007c0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

extern "C" void* DAT_010771d8;

struct GlobalObject_00869f00
{
    void* p;
    void Clear(bool b);
    void ResetToGlobal();
};

// @fnv 0x007d9ff0
void GlobalObject_00869f00::ResetToGlobal()
{
    p = &DAT_010771d8;
    Clear(true);
}

extern int DAT_010771ec;
struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
    AX* FUN_007da010();
};
// @fnv 0x007da010
AX* AX::FUN_007da010()
{
    *reinterpret_cast<int**>(this) = reinterpret_cast<int*>(&DAT_010771ec);
    FUN_006b3eb0(0, 0);
    return this;
}

namespace fnv_007da070 {
extern "C" void* DAT_010771ec;

struct GlobalObject_00869f00
{
    void* p;
    void Clear(bool);
    void InitAndClear();
};

void GlobalObject_00869f00::Clear(bool)
{}

// @fnv 0x007da070
void GlobalObject_00869f00::InitAndClear()
{
    p = &DAT_010771ec;
    Clear(true);
}
}  // namespace fnv_007da070

extern void* DAT_01077200;
struct FUN_007da090_Class
{
    void* vtable;
    void FUN_007da110(int a, int b);
    void* FUN_007da090();
};
// Sets the vtable to DAT_01077200, calls FUN_007da110 with 0, 0, and returns this.
// @fnv 0x007da090
void* FUN_007da090_Class::FUN_007da090()
{
    vtable = &DAT_01077200;
    FUN_007da110(0, 0);
    return this;
}

namespace fnv_007da0f0 {
struct GlobalObject_007da090
{
    void FUN_007d8e20(bool);
};

extern int DAT_01077200;

struct NavMeshSearchLOSArray
{
    int m_p;
    void FUN_007d8e20(bool);
    void Init();
};

// @fnv 0x007da0f0
void NavMeshSearchLOSArray::Init()
{
    m_p = (int)&DAT_01077200;
    FUN_007d8e20(true);
}
}  // namespace fnv_007da0f0

// @fnv 0x007dc0c0
int* DecrementInt(int* value)
{
    --*value;
    return value;
}

extern "C" void __cdecl FUN_007c5fc0(int);

// @fnv 0x007c5fb0
void __cdecl FUN_007c5fb0()
{
    FUN_007c5fc0(0x23);
}

extern int* DAT_011daa38;
struct FUN_007c9dc0_Class
{
    void FUN_007c9dc0(int);
    void InvokeCallbacksForSlot();
};
// If DAT_011daa38 is set and its byte at offset 0x54 is nonzero, calls FUN_007c9dc0(1) and InvokeCallbacksForSlot on it.
// @fnv 0x007cabb0
void FUN_007cabb0()
{
    if (DAT_011daa38 && *(unsigned char*)((unsigned char*)DAT_011daa38 + 0x54))
    {
        ((FUN_007c9dc0_Class*)DAT_011daa38)->FUN_007c9dc0(1);
        ((FUN_007c9dc0_Class*)DAT_011daa38)->InvokeCallbacksForSlot();
    }
}

namespace fnv_007cabf0 {
extern int* DAT_011daa38;
struct FUN_007c9dc0_Class
{
    void FUN_007c9dc0(int a);
    void InvokeCallbacksForSlot();
};
// If DAT_011daa38 is set and its byte at offset 0x54 is nonzero, calls FUN_007c9dc0(0) and InvokeCallbacksForSlot on it.
// @fnv 0x007cabf0
void FUN_007cabf0()
{
    if (DAT_011daa38 && *(unsigned char*)((char*)DAT_011daa38 + 0x54))
    {
        ((FUN_007c9dc0_Class*)DAT_011daa38)->FUN_007c9dc0(0);
        ((FUN_007c9dc0_Class*)DAT_011daa38)->InvokeCallbacksForSlot();
    }
}
}  // namespace fnv_007cabf0

struct FUN_007cc680_Class
{
    void SetFlag80(bool set);
};

// @fnv 0x007cc680
void FUN_007cc680_Class::SetFlag80(bool set)
{
    if (set)
        *(unsigned int*)((char*)this + 0x244) |= 0x80;
    else
        *(unsigned int*)((char*)this + 0x244) &= ~0x80;
}

struct FUN_00570f40_Class
{
    bool FUN_00570f40() const;
};
struct FUN_007d6bd0_Class : FUN_00570f40_Class
{
    unsigned int m_uiInitializationFlags;
    bool FUN_007d6bd0(bool abValue);
};
// Calls FUN_00570f40, then sets or clears bit 0 at offset 0x244 based on abValue, returning the earlier result.
// @fnv 0x007d6bd0
bool FUN_007d6bd0_Class::FUN_007d6bd0(bool abValue)
{
    bool bret = FUN_00570f40();
    if (!abValue)
        ((unsigned int*)((char*)this + 0x244))[0] |= 1;
    else
        ((unsigned int*)((char*)this + 0x244))[0] &= ~1;
    return bret;
}

struct GlobalObject_007da090
{
    ~GlobalObject_007da090();
    void* Destroy(unsigned int flags);
};

// Destroys the object and, when flags has bit 0 set, frees its memory, then returns the pointer.
// @fnv 0x007da0c0
void* GlobalObject_007da090::Destroy(unsigned int flags)
{
    GlobalObject_007da090::~GlobalObject_007da090();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_007da110_StandIn
{
    virtual void v0();
    virtual int Write(unsigned int size);
    void ConstructRecords(int size, unsigned int savedSize);
    void FUN_007da110(unsigned int requested, unsigned int savedSize);
};

// @fnv 0x007da110
void FUN_007da110_StandIn::FUN_007da110(unsigned int uiRequestedSize, unsigned int savedSize)
{
    ((int*)this)[1] = 0;
    ((int*)this)[2] = 0;
    ((int*)this)[3] = 0;
    if (savedSize > uiRequestedSize)
    {
        uiRequestedSize = savedSize;
    }
    if (uiRequestedSize > 0)
    {
        ((int*)this)[1] = Write(uiRequestedSize);
        ((int*)this)[3] = uiRequestedSize;
    }
    if (savedSize > 0)
    {
        ConstructRecords(((int*)this)[1], savedSize);
        ((int*)this)[2] = savedSize;
    }
}

struct Tile
{
    void Set(int x, int y);
};
struct StartMenu
{
    bool IsFlagSet(int f);
};
struct SM7d6 : StartMenu
{
    void* GetNext();
};
extern SM7d6* DAT_011daac0;
bool __cdecl FUN_004b71d0();
void __cdecl FUN_007d30b0(char);
void __cdecl HandleBackAction();
// If DAT_011daac0 exists, sets its next tile to (0x1009, FUN_004b71d0()), calls FUN_007d30b0 with that value, and calls HandleBackAction when flag 0x1000 is set.
// @fnv 0x007d6c30
void __cdecl UpdateStartMenuTile()
{
    if (DAT_011daac0)
    {
        ((Tile*)DAT_011daac0->GetNext())->Set(0x1009, FUN_004b71d0());
        FUN_007d30b0(FUN_004b71d0());
        if (DAT_011daac0->IsFlagSet(0x1000))
            HandleBackAction();
    }
}

int __cdecl FUN_00408b20(char const* a, char const* b);
struct AVH
{
    enum Index
    {
        kAVHealth,
        kAVDamageResist
    };
    static char const* GetActorValueName(Index index);
};
struct FUN_007da270_T
{
    int pad;
    AVH::Index index;
};
// Looks up the actor value names for both structs' index fields and returns the result of comparing those names.
// @fnv 0x007da270
int CompareActorValueNames(FUN_007da270_T* apLeft, FUN_007da270_T* apRight)
{
    char const* nameA = AVH::GetActorValueName(apLeft->index);
    char const* nameB6 = AVH::GetActorValueName(apRight->index);
    int result = FUN_00408b20(nameA, nameB6);
    return result;
}

struct GO
{
    operator unsigned int() const;
};

int __fastcall FUN_00794d80(void* value);

struct FUN_007ca530_CallbackBase
{
    virtual void FUN_00000000()
    {}
    virtual void FUN_00000004()
    {}
    virtual void FUN_00000008()
    {}
    virtual void FUN_0000000c()
    {}
    virtual void FUN_00000010()
    {}
    virtual void FUN_00000014()
    {}
    virtual void FUN_00000018()
    {}
    virtual void FUN_0000001c()
    {}
    virtual void FUN_00000020()
    {}
    virtual void FUN_00000024()
    {}
    virtual void FUN_00000028()
    {}
    virtual void FUN_0000002c()
    {}
    virtual void FUN_00000030()
    {}
    virtual void FUN_00000034()
    {}
    virtual void FUN_00000038()
    {}
    virtual void FUN_0000003c()
    {}
    virtual void FUN_00000040()
    {}
    virtual void FUN_00000044()
    {}
    virtual void FUN_00000048()
    {}
    virtual void FUN_0000004c()
    {}
    virtual void FUN_00000050()
    {}
    virtual void FUN_00000054()
    {}
    virtual void FUN_00000058()
    {}
    virtual void FUN_0000005c()
    {}
    virtual void FUN_00000060()
    {}
    virtual void FUN_00000064()
    {}
    virtual void FUN_00000068()
    {}
    virtual void FUN_0000006c()
    {}
    virtual void FUN_00000070()
    {}
    virtual void FUN_00000074()
    {}
    virtual void FUN_00000078()
    {}
    virtual void FUN_0000007c()
    {}
    virtual void FUN_00000080()
    {}
    virtual void FUN_00000084()
    {}
    virtual void FUN_00000088()
    {}
    virtual void FUN_0000008c()
    {}
    virtual void FUN_00000090()
    {}
    virtual void FUN_00000094()
    {}
    virtual void FUN_00000098()
    {}
    virtual void FUN_0000009c()
    {}
    virtual void FUN_000000a0()
    {}
    virtual void FUN_000000a4()
    {}
    virtual void FUN_000000a8()
    {}
    virtual void FUN_000000ac()
    {}
    virtual void FUN_000000b0()
    {}
    virtual void FUN_000000b4()
    {}
    virtual void FUN_000000b8()
    {}
    virtual void FUN_000000bc()
    {}
    virtual void FUN_000000c0()
    {}
    virtual void FUN_000000c4()
    {}
    virtual void FUN_000000c8()
    {}
    virtual void FUN_000000cc()
    {}
    virtual void FUN_000000d0()
    {}
    virtual void FUN_000000d4()
    {}
    virtual void FUN_000000d8()
    {}
    virtual void FUN_000000dc()
    {}
    virtual void FUN_000000e0()
    {}
    virtual void FUN_000000e4()
    {}
    virtual void FUN_000000e8()
    {}
    virtual void FUN_000000ec()
    {}
    virtual void FUN_000000f0(unsigned int, unsigned int, unsigned int)
    {}
    virtual void FUN_000000f4()
    {}
    virtual void FUN_000000f8()
    {}
    virtual void FUN_000000fc(unsigned int, unsigned int)
    {}
};

struct FUN_007ca530_Params
{
    void* context;
    FUN_007ca530_CallbackBase* callback;
};

// Computes a state from DAT_011daa38 and calls one of the callback's virtual methods with a value from the matching offset.
// @fnv 0x007ca530
void DispatchStateCallback(FUN_007ca530_Params* params)
{
    int state = *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(DAT_011daa38) + 0x58) -
                FUN_00794d80(reinterpret_cast<void*>(DAT_011daa38));

    if (state > 1)
    {
        params->callback->FUN_000000fc(
            0, reinterpret_cast<GO*>(reinterpret_cast<unsigned char*>(DAT_011daa38) + 0x1b0)->operator unsigned int());
    }
    else if (state == 1)
    {
        params->callback->FUN_000000f0(
            0, 0,
            reinterpret_cast<GO*>(reinterpret_cast<unsigned char*>(DAT_011daa38) + 0x1b4)->operator unsigned int());
    }
    else if (state == 0)
    {
        params->callback->FUN_000000f0(
            0, 0,
            reinterpret_cast<GO*>(reinterpret_cast<unsigned char*>(DAT_011daa38) + 0x1b8)->operator unsigned int());
    }
}

namespace fnv_007ca5f0 {
struct GO
{
    unsigned int value;
    operator unsigned int() const;
};

struct LodObject
{
    void SetAppCulled(bool);
};

struct VirtualBase
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
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
    virtual void v52()
    {}
    virtual void v53()
    {}
    virtual void v54()
    {}
    virtual void v55()
    {}
    virtual void v56()
    {}
    virtual void v57()
    {}
    virtual void v58()
    {}
    virtual void v59()
    {}
    virtual unsigned int v60(unsigned int, unsigned int, unsigned int)
    {
        return 0;
    }
};

struct GameGlobal
{
    unsigned char pad0[0x58];
    int timestamp;
    unsigned char pad1[0x124];
    GO gos[16];
};

struct FUN_007ca5f0_Argument
{
    unsigned char pad0[4];
    VirtualBase* field4;
    VirtualBase* field8;
    LodObject* fieldC;
    LodObject* field10;
};

int __fastcall FUN_00794d80(void*);

// @fnv 0x007ca5f0
void UpdateLodVisibility(FUN_007ca5f0_Argument* p)
{
    if (!p->field4 || !p->field8)
        return;

    int difference = reinterpret_cast<GameGlobal*>(DAT_011daa38)->timestamp - FUN_00794d80(DAT_011daa38);

    if (difference == 0)
    {
        p->fieldC->SetAppCulled(true);
        p->field10->SetAppCulled(true);
        return;
    }

    int remainder;
    int quotient;
    remainder = difference / 10;
    quotient = difference % 10;

    if (remainder > 0)
    {
        p->fieldC->SetAppCulled(false);
        p->field4->v60(0, 0, reinterpret_cast<GameGlobal*>(DAT_011daa38)->gos[remainder].operator unsigned int());
    }
    else
    {
        p->fieldC->SetAppCulled(true);
    }

    p->field10->SetAppCulled(false);
    p->field8->v60(0, 0, reinterpret_cast<GameGlobal*>(DAT_011daa38)->gos[quotient].operator unsigned int());
}
}  // namespace fnv_007ca5f0

struct SoundPlaybackHandle
{
    unsigned int handle;
    ~SoundPlaybackHandle();
    void Play(bool play);
};

struct BSAudio
{
    static BSAudio* __cdecl GetSingleton();
    SoundPlaybackHandle __thiscall GetSoundHandleByEditorID(char const* editorID, unsigned int flags);
};

int __fastcall FUN_00794d80(void* object);
void __cdecl FUN_007c6120();

// If DAT_011daa38 is set and FUN_00794d80 returns its element 22, calls FUN_007c6120; otherwise plays the "UIActivateNothing" sound via BSAudio.
// @fnv 0x007cac30
void __cdecl FUN_007cac30()
{
    unsigned long long padding;

    if (DAT_011daa38 && FUN_00794d80(DAT_011daa38) == DAT_011daa38[22])
    {
        FUN_007c6120();
    }
    else
    {
        BSAudio::GetSingleton()->GetSoundHandleByEditorID("UIActivateNothing", 0x121).Play(false);
    }
}

struct FUN_005aa3f0_Class
{
    void FUN_005aa3f0(int);
};

struct FUN_007d9e80_Class
{
    void FUN_007d9e80(FUN_005aa3f0_Class* apArray, unsigned int aiCount);
};

// Calls FUN_005aa3f0(0) on each 12-byte element of apArray for aiCount elements.
// @fnv 0x007d9e80
void FUN_007d9e80_Class::FUN_007d9e80(FUN_005aa3f0_Class* apArray, unsigned int aiCount)
{
    for (unsigned int i = 0; i < aiCount; ++i)
        ((FUN_005aa3f0_Class*)((char*)apArray + i * 12))->FUN_005aa3f0(0);
}

struct FUN_007d9f90 : AX
{
    void* vtable;
    FUN_007d9f90();
};

// Sets the vtable pointer to DAT_010771d8 and calls FUN_006b3eb0 with 0, 0.
// @fnv 0x007d9f90
FUN_007d9f90::FUN_007d9f90()
{
    vtable = &DAT_010771d8;
    FUN_006b3eb0(0, 0);
}

struct GlobalObject_007d9f90
{
    void ResetToGlobal();
    void* FUN_007d9fc0(unsigned int flags);
};
// Calls ResetToGlobal, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x007d9fc0
void* GlobalObject_007d9f90::FUN_007d9fc0(unsigned int flags)
{
    ResetToGlobal();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct GlobalObject_007da010
{
    void* FUN_007da010();
    void* FUN_007da040(unsigned int flags);
    ~GlobalObject_007da010();
};

// Calls FUN_007da010, then if flags has bit 0 set deletes this, and returns this.
// @fnv 0x007da040
void* GlobalObject_007da010::FUN_007da040(unsigned int flags)
{
    FUN_007da010();
    if (flags & 1)
        operator delete(this);
    return this;
}

// @fnv 0x007c6110
int __cdecl FUN_007c6110()
{
    return (int)1060u;
}

extern char* DAT_011dea3c;
extern int* DAT_011daa38;

struct FUN_007ca700_Virt
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual int v07(int value);
};

struct FUN_00450f90_Obj
{
    void FUN_00450f90();
};

struct FUN_00559450_Owner
{
    FUN_00450f90_Obj* FUN_00559450(int flag);
};

bool __cdecl FUN_004b71d0();

// @fnv 0x007ca700
void __cdecl FUN_007ca700(void* pObject)
{
    int iValue = *(int*)((char*)pObject + 0x24);
    if (((FUN_007ca700_Virt*)(DAT_011dea3c + 0xa4))->v07(iValue) > 1)
    {
        ((FUN_00559450_Owner*)((char*)pObject + 8))->FUN_00559450(0)->FUN_00450f90();
    }
    else
    {
        ((FUN_00559450_Owner*)((char*)pObject + 8))->FUN_00559450(1)->FUN_00450f90();
    }
    if (FUN_004b71d0())
    {
        if (*(int*)((char*)DAT_011daa38 + 0x48) == 8)
        {
            if (iValue != *(int*)((char*)DAT_011daa38 + 0x4c) + 4)
            {
                ((FUN_00559450_Owner*)((char*)pObject + 8))->FUN_00559450(1)->FUN_00450f90();
            }
        }
    }
}

struct FUN_007ca860_Obj
{
    void* FUN_00559450();
};
struct FUN_007ca860_Vt
{
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc30();
    virtual void vfunc31();
    virtual void vfunc32();
    virtual void vfunc33();
    virtual void vfunc34();
    virtual void vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc40();
    virtual void vfunc41();
    virtual void vfunc42();
    virtual void vfunc43();
    virtual void vfunc44();
    virtual void vfunc45();
    virtual void vfunc46();
    virtual void vfunc47();
    virtual void vfunc48();
    virtual void vfunc49();
    virtual void vfunc50();
    virtual void vfunc51();
    virtual void vfunc52();
    virtual void vfunc53();
    virtual void vfunc54();
    virtual void vfunc55();
    virtual void vfunc56();
    virtual void vfunc57();
    virtual void vfunc58();
    virtual void vfunc59();
    virtual void vfunc60(int a, int b, void* c);
};
struct FUN_007ca860_Arg
{
    int unk00;
    int unk04;
    int unk08;
    FUN_007ca860_Vt* unk0C;
};
extern int* DAT_011daa38;

// Calls vfunc60 on arg->unk0C with (0, 0, result of FUN_00559450 on DAT_011daa38 + 0x1c0).
// @fnv 0x007ca860
void __cdecl CallVfunc60WithGlobalOffset(FUN_007ca860_Arg* arg)
{
    arg->unk0C->vfunc60(
        0, 0, reinterpret_cast<FUN_007ca860_Obj*>(reinterpret_cast<char*>(DAT_011daa38) + 0x1c0)->FUN_00559450());
}

struct FUN_00559450_Source
{
    unsigned int __thiscall FUN_00559450();
};
struct FUN_007ca8e0_Params
{
    unsigned int m_unknown00;
    unsigned int m_unknown04;
    unsigned int m_unknown08;
    FUN_007ca530_CallbackBase* callback;
};
// Calls the callback with a value from one of two source objects on DAT_011daa38, chosen by comparing FUN_00794d80's result against the field at offset 0x58.
// @fnv 0x007ca8e0
void __cdecl DispatchSourceCallback(FUN_007ca8e0_Params* params)
{
    if (FUN_00794d80(DAT_011daa38) < *(int*)((char*)DAT_011daa38 + 0x58))
    {
        params->callback->FUN_000000f0(0, 0, ((FUN_00559450_Source*)((char*)DAT_011daa38 + 0x1d0))->FUN_00559450());
    }
    else
    {
        params->callback->FUN_000000f0(0, 0, ((FUN_00559450_Source*)((char*)DAT_011daa38 + 0x1cc))->FUN_00559450());
    }
}

struct Callback
{
    void(__cdecl* onPrimary)(Callback*);
    void(__cdecl* onSecondary)(Callback*);
};
struct CallbackCollection
{
    unsigned int FUN_0044ddc0();
    Callback** FUN_006a7ad0(unsigned int index);
};
// @fnv 0x007cacd0
void FUN_007c9dc0_Class::InvokeCallbacksForSlot()
{
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x48) < 9)
    {
        for (unsigned int i = 0; i < reinterpret_cast<CallbackCollection*>(
                                         reinterpret_cast<char*>(this) + 0x70 +
                                         (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x48) << 5))
                                         ->FUN_0044ddc0();
             ++i)
        {
            (*reinterpret_cast<CallbackCollection*>(
                  reinterpret_cast<char*>(this) + 0x70 +
                  (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x48) << 5))
                  ->FUN_006a7ad0(i))
                ->onPrimary(*reinterpret_cast<CallbackCollection*>(
                                 reinterpret_cast<char*>(this) + 0x70 +
                                 (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x48) << 5))
                                 ->FUN_006a7ad0(i));
        }
        for (unsigned int uiSecondaryIndex = 0;
             uiSecondaryIndex < reinterpret_cast<CallbackCollection*>(
                                    reinterpret_cast<char*>(this) + 0x60 +
                                    (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x48) << 5))
                                    ->FUN_0044ddc0();
             ++uiSecondaryIndex)
        {
            (*reinterpret_cast<CallbackCollection*>(
                  reinterpret_cast<char*>(this) + 0x60 +
                  (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x48) << 5))
                  ->FUN_006a7ad0(uiSecondaryIndex))
                ->onSecondary(*reinterpret_cast<CallbackCollection*>(
                                   reinterpret_cast<char*>(this) + 0x60 +
                                   (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x48) << 5))
                                   ->FUN_006a7ad0(uiSecondaryIndex));
        }
    }
}

struct Menu
{
    Menu();
    virtual ~Menu();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
};
struct FUN_007cb540
{
    FUN_007cb540();
    ~FUN_007cb540();
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
};
struct FUN_007642f0
{
    FUN_007642f0();
    ~FUN_007642f0();
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
};
struct FUN_007d7c60
{
    FUN_007d7c60();
    ~FUN_007d7c60();
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
};
struct GlobalObject_00633c90
{
    int p;
    GlobalObject_00633c90(int);
    ~GlobalObject_00633c90();
};
extern int DAT_011daab4;
extern char DAT_01070244;
void* __cdecl TraitNameToIDAdd(const char*, int);
void __cdecl FUN_00403d30(void*, int, unsigned);
struct AudioView
{
    void FUN_0070bbe0();
};
struct FUN_007cb330 : Menu
{
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
    FUN_007cb540 unk084;
    FUN_007cb540 unk0b4;
    FUN_007cb540 unk0e4;
    FUN_007cb540 unk114;
    FUN_007642f0 unk144;
    FUN_007d7c60 unk174;
    int unk1a4;
    int unk1a8;
    float unk1ac;
    int unk1b0;
    int unk1b4;
    GlobalObject_00633c90 unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    void* unk1d0;
    FUN_007cb330();
    virtual ~FUN_007cb330();
};
// @fnv 0x007cb330
FUN_007cb330::FUN_007cb330() : unk1b8(0)
{
    unk1d0 = TraitNameToIDAdd(&DAT_01070244, -1);
    FUN_00403d30(&unk028, 0, 0x5c);
    unk1a8 = 0;
    unk1a4 = 0;
    unk1ac = 0.0f;
    unk1b0 = 0;
    unk1c4 = 0;
    unk1c0 = 0;
    unk1bc = 0;
    unk1c8 = 0xff;
    unk1cc = 0;
    DAT_011daab4 = 0;
    unk1b4 = 0;
    ((AudioView*)BSAudio::GetSingleton())->FUN_0070bbe0();
}

// @fnv 0x007cc5f0
bool __cdecl FUN_007cc5f0(int id)
{
    switch (id)
    {
    case 0x3f0:
    case 0x3f1:
    case 0x3f4:
    case 0x3f6:
    case 0x3f8:
    case 0x403:
    case 0x417:
    case 0x418:
    case 0x41b:
    case 0x41d:
    case 0x420:
    case 0x423:
    case 0x433:
    case 0x434:
    case 0x435:
    case 0x438:
    case 0x439:
    case 0x43a:
    case 0x43b:
    case 0x43c:
        return true;
    default:
        return false;
    }
}

// @fnv 0x007cc6d0
int __cdecl FUN_007cc6d0()
{
    return (int)1059u;
}

class B7CE970Object
{
  public:
    virtual ~B7CE970Object();
};

// Deletes the object passed in pkObject.
// @fnv 0x007ce970
void FUN_007ce970(void* pvContext, B7CE970Object* pkObject)
{
    delete pkObject;
}

class C7D8EE0List
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void SetSelection(int iIndex);

    int GetCount(int iFilter);
    void SelectLast();
};

// Selects the last entry by calling SetSelection with GetCount(0) minus one.
// @fnv 0x007d8ee0
void C7D8EE0List::SelectLast()
{
    SetSelection(GetCount(0) - 1);
}

void* __cdecl operator new(unsigned int size, void* location);
void __cdecl operator delete(void* object, void* location);
struct FUN_007da240
{
    int first;
    int second;
    int third;
    FUN_007da240();
};
struct CopyCollection
{
    void ConstructRecords(FUN_007da240* records, unsigned count);
};
// Default-constructs each of the count FUN_007da240 records in place via placement new.
// @fnv 0x007da1a0
void CopyCollection::ConstructRecords(FUN_007da240* records, unsigned count)
{
    for (unsigned i = 0; i < count; ++i)
    {
        new (&records[i]) FUN_007da240();
    }
}

struct FUN_00501c10_Class
{
    void CallAndReturnSelf(int a);
};
struct FUN_007df120_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void FUN_007df120(int a);
};
// @fnv 0x007df120
void FUN_007df120_Class::FUN_007df120(int aiValue)
{
    ((FUN_00501c10_Class*)((char*)this + 0x20))->CallAndReturnSelf(aiValue);
}

struct ImageSpaceEffectParam
{
    float left, right, top, bottom;
    ImageSpaceEffectParam(float, float, float, float);
};
struct NiFrustum
{
    float left, right, top, bottom, nearPlane, farPlane;
    bool orthographic;
    NiFrustum(bool);
};
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3(float, float, float);
};
class NiUpdateData
{
  public:
    float time;
    bool updateControllers, isMultiThreaded;
    unsigned int flags;
    NiUpdateData(float, bool, bool);
};
class NiFixedString
{
  public:
    const char* text;
    NiFixedString(const char*);
    ~NiFixedString();
};
struct FUN_00a712f0
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    FUN_00a712f0();
    void FUN_00712e60(const ImageSpaceEffectParam&);
    void FUN_00507700(float);
    void FUN_00a6faf0(const NiFrustum&);
    void FUN_004bc1f0(float, float, float);
    void FUN_00a59c60(NiUpdateData&);
    void SetLookAt(const NiPoint3&, const NiPoint3&);
    void FUN_00733fd0(float);
    void AssignFixedString(const NiFixedString&);
};
struct CameraContext
{
    FUN_00a712f0* CreateSurgery3DCamera();
};
struct Renderer
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
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
    virtual float GetScale();
};
Renderer* FUN_0045c670();
struct SettingFloat
{
    float* Float();
};
extern SettingFloat DAT_01203144;
extern SettingFloat DAT_01203150;
extern bool DAT_011f9426;
extern int DAT_011f9434;
extern ImageSpaceEffectParam DAT_011ad840;
int FUN_004dc200();
int FUN_004dc1f0();
float FUN_0057dd70(float);

// Allocates a camera object, configures its viewport, frustum, aspect ratio, transform and name, and returns it.
// @fnv 0x007c99c0
FUN_00a712f0* CameraContext::CreateSurgery3DCamera()
{
    // Local identifiers and declaration order preserve the MSVC9 /Od stack layout.
    float frustum;                              // Viewport aspect ratio.
    FUN_00a712f0* distance = new FUN_00a712f0;  // Newly allocated camera.
    ImageSpaceEffectParam viewport(0.0f, 1.0f, 1.0f, 0.0f);
    if (DAT_011f9426)
        viewport = DAT_011ad840;
    distance->FUN_00712e60(viewport);
    NiFrustum angle(false);  // Perspective frustum.
    angle.farPlane = FUN_0045c670()->GetScale();
    angle.nearPlane = *DAT_01203144.Float();
    distance->FUN_00507700(angle.farPlane / angle.nearPlane);
    frustum = float(DAT_011f9426 ? DAT_011f9434 : FUN_004dc200()) / FUN_004dc1f0();
    float camera = 0.75f;  // Frustum scale.
    float update = *DAT_01203150.Float() * 0.01745329238474369 * 0.15000000596046448;
    angle.left = -FUN_0057dd70(update) * camera;
    angle.right = FUN_0057dd70(update) * camera;
    angle.bottom = -FUN_0057dd70(update) * frustum * camera;
    angle.top = FUN_0057dd70(update) * frustum * camera;
    angle.orthographic = false;
    distance->FUN_00a6faf0(angle);
    distance->FUN_004bc1f0(0.0f, 0.0f, 1.0f);
    NiUpdateData aspect(0.0f, false, false);  // Initial scene update.
    distance->FUN_00a59c60(aspect);
    distance->SetLookAt(NiPoint3(0.0f, 0.0f, 0.0f), NiPoint3(0.0f, 1.0f, 0.0f));
    distance->FUN_00733fd0(1.0f);
    distance->AssignFixedString(NiFixedString("Surgery3DCamera"));
    return distance;
}

// Show the rank title for the entry's skill level on the entry's tile.

class CA4D0AVOwner
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual int GetRank(int m_eAssociatedActorValue);
};

class CA4D0Player
{
  public:
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
    CA4D0AVOwner m_kAVOwner;
};
extern CA4D0Player* g_pkCA4D0Player;

class CA4D0Title
{
  public:
    const char* GetText();
    int m_iData;
};

class CA4D0RankData
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    CA4D0Title m_akTitles[8];
};
extern CA4D0RankData* g_pkCA4D0RankData;

class CA4D0Tile
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
    virtual void SetText(int iA, int iB, const char* pcText);
};

struct CA4D0Entry
{
    int unk00;
    CA4D0Tile* m_pkTile;
    int unk08;
    int unk0C;
    int unk10;
    int m_iActorValue;
};

// Gets the player's rank for the entry's actor value and sets the entry tile's text to that rank's title.
// @fnv 0x007ca4d0
void __cdecl UpdateEntryRankText(CA4D0Entry* pkEntry)
{
    int m_iRank = g_pkCA4D0Player->m_kAVOwner.GetRank(pkEntry->m_iActorValue);
    pkEntry->m_pkTile->SetText(0, 0, g_pkCA4D0RankData->m_akTitles[m_iRank].GetText());
}

struct CsVObj
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual int vf07(int value);
};
struct CsTarget
{
    void FUN_00450f90();
};
struct CsSub
{
    CsTarget* FUN_00559450(int flag);
};
struct CsParam
{
    int unk00;
    int unk04;
    CsSub sub08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
};
extern char* DAT_011dea3c;

// @fnv 0x007ca7a0
void __cdecl FUN_007ca7a0(CsParam* param_1)
{
    int iValue = param_1->unk24;
    if (((CsVObj*)(DAT_011dea3c + 0xa4))->vf07(iValue) < 10 &&
        (DAT_011daa38 == 0 || FUN_00794d80(DAT_011daa38) < *(int*)((char*)DAT_011daa38 + 0x58)))
    {
        param_1->sub08.FUN_00559450(0)->FUN_00450f90();
    }
    else
    {
        param_1->sub08.FUN_00559450(1)->FUN_00450f90();
    }

    if (FUN_004b71d0() && *(int*)((char*)DAT_011daa38 + 0x48) == 8)
    {
        if (iValue != *(int*)((char*)DAT_011daa38 + 0x4c) + 4)
        {
            param_1->sub08.FUN_00559450(1)->FUN_00450f90();
        }
    }
}

class Obj7CA;

class Handle7CA
{
  public:
    Obj7CA* Get() const;

    Obj7CA* m_pPointer;
};

class Target7CA
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3C();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4C();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual void vfn5C();
    virtual void vfn60();
    virtual void vfn64();
    virtual void vfn68();
    virtual void vfn6C();
    virtual void vfn70();
    virtual void vfn74();
    virtual void vfn78();
    virtual void vfn7C();
    virtual void vfn80();
    virtual void vfn84();
    virtual void vfn88();
    virtual void vfn8C();
    virtual void vfn90();
    virtual void vfn94();
    virtual void vfn98();
    virtual void vfn9C();
    virtual void vfnA0();
    virtual void vfnA4();
    virtual void vfnA8();
    virtual void vfnAC();
    virtual void vfnB0();
    virtual void vfnB4();
    virtual void vfnB8();
    virtual void vfnBC();
    virtual void vfnC0();
    virtual void vfnC4();
    virtual void vfnC8();
    virtual void vfnCC();
    virtual void vfnD0();
    virtual void vfnD4();
    virtual void vfnD8();
    virtual void vfnDC();
    virtual void vfnE0();
    virtual void vfnE4();
    virtual void vfnE8();
    virtual void vfnEC();
    virtual void Apply(int iFirst, int iSecond, Obj7CA* pkObject);
};

class Owner7CA
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    Handle7CA m_kHandle;
};

extern Owner7CA* g_pkOwner7CA;

class Event7CA
{
  public:
    int unk00;
    int unk04;
    int unk08;
    Target7CA* m_pkTarget;
};

// Calls Apply on the event's target with first and second set to 0 and the owner's handle object.
// @fnv 0x007ca8a0
void __cdecl FUN_007ca8a0(Event7CA* pkEvent)
{
    pkEvent->m_pkTarget->Apply(0, 0, g_pkOwner7CA->m_kHandle.Get());
}

class Mgr
{
  public:
    int FUN_00559450();
    void FUN_004037f0(int v);
    void FUN_007b52a0();
    int FUN_00403df0(int v);
    int FUN_00403df0();
    char* FUN_004c69f0();
    void FUN_007cb2e0(void* const& pp);
};
extern Mgr DAT_011d1e84;
extern Mgr DAT_011d1f50;
extern Mgr DAT_011d1fe0;
extern Mgr DAT_011d216c;
extern Mgr DAT_011d219c;
extern Mgr DAT_011d2580;
extern Mgr DAT_011d2730;
extern Mgr DAT_011d29f4;
extern Mgr DAT_011d34f8;
extern Mgr DAT_011d3564;
extern Mgr DAT_011d3684;
extern Mgr DAT_011d375c;
extern Mgr DAT_011d3828;
extern Mgr DAT_011d3b8c;
extern Mgr DAT_011d3d90;
extern Mgr DAT_011d42e8;
extern Mgr DAT_011d433c;
extern Mgr DAT_011d4354;
extern Mgr DAT_011d4630;
extern Mgr DAT_011d46b4;
extern Mgr DAT_011d4888;
extern Mgr DAT_011daad0;
extern Mgr DAT_011dab88;
extern Mgr DAT_011dabcc;
class Holder
{
  public:
    void* m_00;
};
class FUN_007ce620
{
  public:
    void* type;
    char* name;
    char* description;
    int flags;
    FUN_007ce620(char*, char*, int);
};
class FUN_007d6350
{
  public:
    void* type;
    char* name;
    char* description;
    int flags;
    int value;
    int count;
    int mode;
    int fTargetUpperBound;
    int fMinimumInputValue;
    int step;
    int extra;
    int state;
    FUN_007d6350(char*, char*, int, ...);
};
void __cdecl ClearStartMenuEntries();
void* __cdecl FormHeap_Allocate(int size);
extern char DAT_007d0440[];
extern char DAT_007d0490[];
extern char DAT_007d04d0[];
extern char DAT_007d0550[];
extern char DAT_007d0680[];
extern char DAT_007d06c0[];
extern char DAT_007d0700[];
extern char DAT_007d0770[];
extern char DAT_007d0a10[];
extern char DAT_007d0a70[];
extern char DAT_007d0bf0[];
extern char DAT_007d0c50[];
extern char DAT_007d0d40[];
extern char DAT_007d0d70[];
extern char DAT_007d0dc0[];
extern char DAT_007d0df0[];
extern char DAT_007d0e40[];
extern char DAT_007d3190[];
extern char DAT_007d32b0[];
extern char DAT_007d3470[];
extern char DAT_007d35c0[];
extern char DAT_007d3620[];

extern Mgr DAT_011d4fc0;
extern Mgr DAT_011d466c;
extern Mgr DAT_011d4ed0;
extern Mgr DAT_011d366c;
extern Mgr DAT_011dab50;
extern Mgr DAT_011d4dec;
extern Mgr DAT_011d258c;
extern Mgr DAT_011d1d78;
extern Mgr DAT_011c39a8;
extern Mgr DAT_011c3a94;
extern Mgr DAT_011d2fc4;
extern Mgr DAT_011c3a70;
extern Mgr DAT_011c39e8;
extern Mgr DAT_011d1e30;
extern char DAT_007d1260[];
extern char DAT_007d13a0[];
extern char DAT_007d11d0[];
extern char DAT_007d1440[];
extern char DAT_007d1510[];
extern char DAT_007d1570[];
extern char DAT_007d15d0[];
extern char DAT_007d1630[];
extern char DAT_007d1690[];
extern char DAT_007d16f0[];
extern char DAT_007d1750[];
extern char DAT_007d1840[];
extern char DAT_007d1900[];
extern char DAT_007d19c0[];
extern char DAT_007d1b40[];
extern char DAT_007d1bb0[];
extern char DAT_007d1d10[];
extern char DAT_007d1e60[];
extern char DAT_007d1fb0[];
extern char DAT_007d20f0[];
extern char DAT_007d2250[];
extern char DAT_007d23b0[];
extern char DAT_007d2510[];
extern char DAT_007d2650[];
extern char DAT_007d2790[];
extern char DAT_007d28b0[];
extern char DAT_007d29d0[];
extern char DAT_007d2af0[];
extern char DAT_007d2c10[];
extern char DAT_007d2d30[];
extern char DAT_007d2e50[];
extern char DAT_007d2eb0[];
extern char DAT_007d2fc0[];
extern char DAT_007d30e0[];
extern Mgr DAT_011d1dc0;
extern Mgr DAT_011d2124;
extern Mgr DAT_011d21f0;
extern Mgr DAT_011d22bc;
extern Mgr DAT_011d23c4;
extern Mgr DAT_011d2430;
extern Mgr DAT_011d2484;
extern Mgr DAT_011d24e4;
extern Mgr DAT_011d2520;
extern Mgr DAT_011d25c8;
extern Mgr DAT_011d2610;
extern Mgr DAT_011d28f8;
extern Mgr DAT_011d2940;
extern Mgr DAT_011d2afc;
extern Mgr DAT_011d2bec;
extern Mgr DAT_011d2cdc;
extern Mgr DAT_011d2e5c;
extern Mgr DAT_011d2e8c;
extern Mgr DAT_011d2f34;
extern Mgr DAT_011d3054;
extern Mgr DAT_011d31b0;
extern Mgr DAT_011d34d4;
extern Mgr DAT_011d3750;
extern Mgr DAT_011d399c;
extern Mgr DAT_011d3a50;
extern Mgr DAT_011d3b98;
extern Mgr DAT_011d3bec;
extern Mgr DAT_011d3c28;
extern Mgr DAT_011d3ef8;
extern Mgr DAT_011d4270;
extern Mgr DAT_011d4648;
extern Mgr DAT_011d49fc;
extern Mgr DAT_011d4a20;
extern Mgr DAT_011d4abc;
extern Mgr DAT_011d4e40;
extern Mgr DAT_011d5074;
// @fnv 0x007cc6e0
void __cdecl FUN_007cc6e0()
{
    if (!DAT_011dabcc.FUN_00559450())
    {
        DAT_011dabcc.FUN_004037f0(DAT_011d4630.FUN_00403df0(0));
        DAT_011dabcc.FUN_007b52a0();
        DAT_011daad0.FUN_004037f0(DAT_011d4354.FUN_00403df0(0));
        DAT_011daad0.FUN_007b52a0();
    }
    ClearStartMenuEntries();
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d3564.FUN_004c69f0(), DAT_007d0440, 3));
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d216c.FUN_004c69f0(), DAT_007d0490, 1));
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d3b8c.FUN_004c69f0(), DAT_007d06c0, 2));
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d4888.FUN_004c69f0(), DAT_007d0680, 3));
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d1fe0.FUN_004c69f0(), DAT_007d0700, 3));
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d2580.FUN_004c69f0(), DAT_007d0770, 2));
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d46b4.FUN_004c69f0(), DAT_007d04d0, 1));
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d433c.FUN_004c69f0(), DAT_007d0550, 1));
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d42e8.FUN_004c69f0(), DAT_007d0a10, 3));
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d3d90.FUN_004c69f0(), DAT_007d0d40, 4));
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d375c.FUN_004c69f0(), DAT_007d0d70, 4));
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d219c.FUN_004c69f0(), DAT_007d0dc0, 4));
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d1f50.FUN_004c69f0(), DAT_007d0df0, 4));
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d34f8.FUN_004c69f0(), DAT_007d32b0, 128));
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d34f8.FUN_004c69f0(), DAT_007d3190, 256));
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d34f8.FUN_004c69f0(), DAT_007d3470, 512));
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d34f8.FUN_004c69f0(), DAT_007d35c0, 1024));
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d34f8.FUN_004c69f0(), DAT_007d3620, 2048));
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d3684.FUN_004c69f0(), DAT_007d0e40, 3968));
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d2730.FUN_004c69f0(), DAT_007d0a70, 8192));
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d1e84.FUN_004c69f0(), DAT_007d0bf0, 12288));
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d29f4.FUN_004c69f0(), DAT_007d0e40, 12288));
    DAT_011dab88.FUN_007cb2e0(new FUN_007ce620(DAT_011d3828.FUN_004c69f0(), DAT_007d0c50, 64));

    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d366c.FUN_004c69f0(), DAT_007d1260, 8, 0, 3, 0x55,
                                               DAT_011d4ed0.FUN_00403df0(), DAT_011d466c.FUN_00403df0(),
                                               DAT_011d4fc0.FUN_00403df0()));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d1d78.FUN_004c69f0(), DAT_007d13a0, 8, 0, 2, 0,
                                               DAT_011d258c.FUN_00403df0(), DAT_011d4dec.FUN_00403df0()));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d1e30.FUN_004c69f0(), DAT_007d11d0, 8, 0, 5, 0x55,
                                               DAT_011c39e8.FUN_00403df0(), DAT_011c3a70.FUN_00403df0(),
                                               DAT_011d2fc4.FUN_00403df0(), DAT_011c3a94.FUN_00403df0(),
                                               DAT_011c39a8.FUN_00403df0()));

    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d4a20.FUN_004c69f0(), DAT_007d1510, 8, 0, 2, 0,
                                               DAT_011d258c.FUN_00403df0(), DAT_011d4dec.FUN_00403df0()));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d3bec.FUN_004c69f0(), DAT_007d1570, 8, 0, 2, 0,
                                               DAT_011d258c.FUN_00403df0(), DAT_011d4dec.FUN_00403df0()));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d3a50.FUN_004c69f0(), DAT_007d15d0, 8, 0, 2, 0,
                                               DAT_011d258c.FUN_00403df0(), DAT_011d4dec.FUN_00403df0()));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d3ef8.FUN_004c69f0(), DAT_007d16f0, 8, 0, 2, 0,
                                               DAT_011d258c.FUN_00403df0(), DAT_011d4dec.FUN_00403df0()));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d2520.FUN_004c69f0(), DAT_007d19c0, 0x10, 2, 0x10, 0));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d2f34.FUN_004c69f0(), DAT_007d1750, 0x10, 2, 0x10, 0));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d2940.FUN_004c69f0(), DAT_007d1840, 0x10, 0, 4, 0x37,
                                               DAT_011daad0.FUN_00559450(), DAT_011dabcc.FUN_00559450(),
                                               DAT_011d5074.FUN_00403df0(), DAT_011d2124.FUN_00403df0()));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d23c4.FUN_004c69f0(), DAT_007d1900, 0x10, 0, 4, 0x37,
                                               DAT_011daad0.FUN_00559450(), DAT_011dabcc.FUN_00559450(),
                                               DAT_011d5074.FUN_00403df0(), DAT_011d2124.FUN_00403df0()));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d21f0.FUN_004c69f0(), DAT_007d1b40, 0x10, 0, 3, 0x37,
                                               DAT_011d4270.FUN_00403df0(), DAT_011d2cdc.FUN_00403df0(),
                                               DAT_011d2430.FUN_00403df0()));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d4e40.FUN_004c69f0(), DAT_007d1bb0, 0x10, 2, 0x10, 0));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d22bc.FUN_004c69f0(), DAT_007d1d10, 0x10, 2, 0x10, 0));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d31b0.FUN_004c69f0(), DAT_007d1e60, 0x10, 2, 0x10, 0));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d3b98.FUN_004c69f0(), DAT_007d1fb0, 0x10, 2, 0x10, 0));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d2610.FUN_004c69f0(), DAT_007d20f0, 0x10, 2, 0x10, 0));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d34d4.FUN_004c69f0(), DAT_007d2250, 0x10, 2, 0x10, 0));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d2484.FUN_004c69f0(), DAT_007d23b0, 0x10, 2, 0x10, 0));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d2bec.FUN_004c69f0(), DAT_007d2510, 0x10, 2, 0x10, 0));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d2afc.FUN_004c69f0(), DAT_007d2650, 0x10, 2, 0x10, 0));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d28f8.FUN_004c69f0(), DAT_007d1440, 0x10, 0, 2, 0,
                                               DAT_011d258c.FUN_00403df0(), DAT_011d4dec.FUN_00403df0()));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d2e5c.FUN_004c69f0(), DAT_007d1630, 0x10, 0, 2, 0,
                                               DAT_011d258c.FUN_00403df0(), DAT_011d4dec.FUN_00403df0()));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d3c28.FUN_004c69f0(), DAT_007d1690, 0x10, 0, 2, 0,
                                               DAT_011d258c.FUN_00403df0(), DAT_011d4dec.FUN_00403df0()));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d2e8c.FUN_004c69f0(), DAT_007d2790, 0x20, 2, 0x1a, 0));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d3054.FUN_004c69f0(), DAT_007d29d0, 0x20, 2, 0x1a, 0));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d4abc.FUN_004c69f0(), DAT_007d28b0, 0x20, 2, 0x1a, 0));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d24e4.FUN_004c69f0(), DAT_007d2af0, 0x20, 2, 0x1a, 0));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d399c.FUN_004c69f0(), DAT_007d2c10, 0x20, 2, 0x1a, 0));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d1dc0.FUN_004c69f0(), DAT_007d2d30, 0x20, 2, 0x1a, 0));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d4648.FUN_004c69f0(), DAT_007d2e50, 0x40, 0, 2, 0,
                                               DAT_011d258c.FUN_00403df0(), DAT_011d4dec.FUN_00403df0()));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d25c8.FUN_004c69f0(), DAT_007d2eb0, 0x40, 2, 0x10, 0));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d49fc.FUN_004c69f0(), DAT_007d2fc0, 0x40, 0, 2, 0,
                                               DAT_011d258c.FUN_00403df0(), DAT_011d4dec.FUN_00403df0()));
    DAT_011dab50.FUN_007cb2e0(new FUN_007d6350(DAT_011d3750.FUN_004c69f0(), DAT_007d30e0, 0x40, 0, 2, 0,
                                               DAT_011d258c.FUN_00403df0(), DAT_011d4dec.FUN_00403df0()));
}

struct BookMenu;
struct BookTile
{
    virtual ~BookTile();
    BookTile* ReadXML(const char*);
    BookMenu* FUN_00a03c90();
};
struct BookInterface
{
    BookTile* FUN_00586150();
};
BookInterface* FUN_004b7210();
int FUN_007c6110();
void FUN_005b5e40(const char*, ...);
void FUN_007037e0();
void FUN_005cfcb0(bool);
struct BookMenu
{
    virtual ~BookMenu();
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
    virtual int GetID();
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
    int bookValue;
    void FUN_00a1dc70(BookTile*, bool);
    bool HasAllFlagsSet(int*);
    void InitMenu();
    void* CreateSurgery3DCamera();
    void FUN_00a1dc20(bool);
    void* FUN_00726070();
};
struct BookNodePointer
{
    void FUN_0066b0d0(void*);
};
extern BookNodePointer DAT_011daa9c;
// Creates the SPECIAL book menu from its XML, checks its ID, stores the value, and reports a missing index on failure.
// @fnv 0x007c5fc0
extern "C" void FUN_007c5fc0(int value)
{
    BookTile* menu = FUN_004b7210()->FUN_00586150()->ReadXML("Data\\Menus\\CharGen\\SPECIALBookMenu.xml");
    BookMenu* tile = menu->FUN_00a03c90();
    if (tile && tile->GetID() == FUN_007c6110())
    {
        tile->FUN_00a1dc70(menu, false);
        DAT_011daa38 = reinterpret_cast<int*>(tile);
        int index;
        if (!reinterpret_cast<BookMenu*>(DAT_011daa38)->HasAllFlagsSet(&index))
        {
            FUN_005b5e40("MENUS:  Special book menu creation failed... Missing index = #%d", index);
            delete menu;
            FUN_007037e0();
            return;
        }
        reinterpret_cast<BookMenu*>(DAT_011daa38)->bookValue = value;
        reinterpret_cast<BookMenu*>(DAT_011daa38)->InitMenu();
        DAT_011daa9c.FUN_0066b0d0(reinterpret_cast<BookMenu*>(DAT_011daa38)->CreateSurgery3DCamera());
        FUN_005cfcb0(true);
        tile->FUN_00a1dc20(false);
    }
    else if (tile && tile->FUN_00726070())
    {
        delete tile;
    }
}

struct SH_00418890
{
    int unk00[3];
    void FUN_copy(const void* apOther);
};
struct BSSoundHandleEx : SH_00418890
{
    ~BSSoundHandleEx();
    bool Play(bool abUnk);
};
struct GlobalObject_0041a250 : BSSoundHandleEx
{
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
};
struct FUN_00ad7550_shell
{
    BSSoundHandleEx FUN_00ad7550(const char* apEditorID, unsigned int auiFlags);
};
int __cdecl FUN_00647b70(int a, int b);

struct FUN_007ca960_Owner
{
    int unk00[41];
    FUN_007ca700_Virt kSub;
    void FUN_0093a7c0(int a, int b);
};

// @fnv 0x007ca960
void __cdecl FUN_007ca960(void* apSelf)
{
    if (!DAT_011daa38)
        return;
    int m_uiSoundID = ((int*)apSelf)[9];
    if (m_uiSoundID != -1)
    {
        int iCount = ((FUN_007ca960_Owner*)DAT_011dea3c)->kSub.v07(m_uiSoundID);
        if (iCount > 1)
        {
            GlobalObject_0041a250 kSound;
            kSound.FUN_copy(
                &((FUN_00ad7550_shell*)BSAudio::GetSingleton())->FUN_00ad7550("OBJBookSpecialNumber", 0x121));
            kSound.Play(false);
        }
        ((FUN_007ca960_Owner*)DAT_011dea3c)->FUN_0093a7c0(m_uiSoundID, FUN_00647b70(iCount - 1, 1));
    }
    ((FUN_007c9dc0_Class*)DAT_011daa38)->InvokeCallbacksForSlot();
}

struct FUN_007da240_Class
{
    void* unk00;
    unsigned int unk04;
    unsigned short unk08;
    unsigned short unk0A;

    void FUN_004037b0();
    void* FUN_007da240();
};

// Calls FUN_004037b0, zeroes unk08 and unk0A, and returns this.
// @fnv 0x007da240
void* FUN_007da240_Class::FUN_007da240()
{
    this->FUN_004037b0();
    this->unk08 = 0;
    this->unk0A = 0;
    return this;
}
