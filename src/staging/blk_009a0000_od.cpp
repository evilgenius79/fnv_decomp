
// src/staging/blk_009a0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_0099a9a0_shell
{
    void FUN_009a03d0(int);
};

struct FUN_009a0370_shell
{
    void SetFieldE4(int a);
};

// Calls FUN_009a03d0 with 0 on this object, then stores a at offset 0xe4.
// @fnv 0x009a0370
void FUN_009a0370_shell::SetFieldE4(int aiValue)
{
    ((FUN_0099a9a0_shell*)this)->FUN_009a03d0(0);
    *(int*)((char*)this + 0xe4) = aiValue;
}

namespace fnv_009a03a0 {
struct FUN_0099a9a0_shell
{
    void ReleaseStageHolder(int);
};

struct FUN_009a03a0_shell
{
    void SetFieldE8(int a);
};

// Calls ReleaseStageHolder with 0, then stores the int argument at offset 0xe8 of this object.
// @fnv 0x009a03a0
void FUN_009a03a0_shell::SetFieldE8(int aiValue)
{
    ((FUN_0099a9a0_shell*)this)->ReleaseStageHolder(0);
    *(int*)((char*)this + 0xe8) = aiValue;
}
}  // namespace fnv_009a03a0

struct CombatFlagHolder
{
    bool HasCombatFlag(unsigned int);
    bool FUN_009a1240();
};

// @fnv 0x009a1240
bool CombatFlagHolder::FUN_009a1240()
{
    return HasCombatFlag(4);
}

struct FUN_009a1260_Class
{
    float GetFloatAt0xC8();
};

// @fnv 0x009a1260
float FUN_009a1260_Class::GetFloatAt0xC8()
{
    return *(float*)((char*)this + 0xc8);
}

extern int DAT_0108b4c8;

struct AX
{
    void FUN_006b3eb0(unsigned int a, unsigned int b);
    AX* FUN_009a3750(unsigned int a, unsigned int b);
};

// @fnv 0x009a3750
AX* AX::FUN_009a3750(unsigned int a, unsigned int b)
{
    *(int*)this = (int)&DAT_0108b4c8;
    FUN_006b3eb0(a, b);
    return this;
}

extern "C" void* DAT_0108e0a4;

struct FUN_006cf9d0
{
    void FUN_009a3d00(unsigned int, unsigned int);
    FUN_006cf9d0* FUN_009a37e0(unsigned int, unsigned int);
};

// @fnv 0x009a37e0
FUN_006cf9d0* FUN_006cf9d0::FUN_009a37e0(unsigned int a, unsigned int b)
{
    *(void**)this = &DAT_0108e0a4;
    FUN_009a3d00(a, b);
    return this;
}

namespace fnv_009a3810 {
extern int DAT_0108e0a4;

struct GlobalObject_00869f00
{
    void Clear(bool);
    void FUN_009a3810();
};

// @fnv 0x009a3810
void GlobalObject_00869f00::FUN_009a3810()
{
    *reinterpret_cast<int**>(this) = &DAT_0108e0a4;
    Clear(true);
}
}  // namespace fnv_009a3810

struct CombatTargetTimestamp;

CombatTargetTimestamp* __fastcall FUN_004300a0(CombatTargetTimestamp*);

struct FUN_009a3d90_class
{
    int m0;
    CombatTargetTimestamp* __thiscall FUN_009a3d90();
};

// @fnv 0x009a3d90
CombatTargetTimestamp* __thiscall FUN_009a3d90_class::FUN_009a3d90()
{
    FUN_004300a0(reinterpret_cast<CombatTargetTimestamp*>(this + 1));
    return reinterpret_cast<CombatTargetTimestamp*>(this);
}

extern int DAT_0108e1e8;
struct FUN_009a3e90
{
    void* vfn_00;
    void __thiscall FUN_009a4290(int);
    FUN_009a3e90();
};
// Calls FUN_009a4290 with 0x25, then sets vfn_00 to point at DAT_0108e1e8.
// @fnv 0x009a3e90
FUN_009a3e90::FUN_009a3e90()
{
    FUN_009a4290(0x25);
    vfn_00 = &DAT_0108e1e8;
}

extern int DAT_0108e258;
struct FUN_009a4290_class
{
    void __thiscall InitArray(int a);
    int* __thiscall FUN_009a4290(int a);
};
// @fnv 0x009a4290
int* __thiscall FUN_009a4290_class::FUN_009a4290(int a)
{
    InitArray(a);
    *(int**)this = &DAT_0108e258;
    return (int*)this;
}

namespace fnv_009a42f0 {
extern int DAT_01084fec;
struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
    AX* FUN_009a42f0(unsigned int a, unsigned int b);
};
void AX::FUN_006b3eb0(unsigned int a, unsigned int b)
{}
// @fnv 0x009a42f0
AX* AX::FUN_009a42f0(unsigned int a, unsigned int b)
{
    *(int*)this = (int)&DAT_01084fec;
    FUN_006b3eb0(a, b);
    return this;
}
}  // namespace fnv_009a42f0

struct FUN_009a5480_class
{
    float __thiscall GetFieldE4Float();
};

// @fnv 0x009a5480
float __thiscall FUN_009a5480_class::GetFieldE4Float()
{
    return *(float*)((char*)this + 0xe4);
}

extern int DAT_0108e308;

struct FUN_009a5d20_class
{
    int* p;
    void Construct(int a);
    int* FUN_009a5d20(int a);
};

// Calls Construct with a, sets p to point at DAT_0108e308, and returns this as an int pointer.
// @fnv 0x009a5d20
int* FUN_009a5d20_class::FUN_009a5d20(int a)
{
    Construct(a);
    p = &DAT_0108e308;
    return (int*)this;
}

struct FUN_009aa470_Class
{
    void FUN_009aa4b0();
    void* FUN_009aa470();
};

// @fnv 0x009aa470
void* FUN_009aa470_Class::FUN_009aa470()
{
    FUN_009aa4b0();
    return this;
}

struct CombatStateArray
{
    void CopyFrom(CombatStateArray* pArg);
    CombatStateArray* FUN_009aa490(CombatStateArray* pArg);
};

// @fnv 0x009aa490
CombatStateArray* CombatStateArray::FUN_009aa490(CombatStateArray* pArg)
{
    CopyFrom(pArg);
    return this;
}

struct FUN_009b2c90_class
{
    char m_data[6];
    int __thiscall FUN_009b2c90();
};

// @fnv 0x009b2c90
int __thiscall FUN_009b2c90_class::FUN_009b2c90()
{
    return reinterpret_cast<int>(this) + static_cast<signed char>(m_data[5]);
}

// Returns the larger of the two integer arguments.
// @fnv 0x009b65d0
int FUN_009b65d0(unsigned short ausValue, int aiValue)
{
    int result;
    if (ausValue > aiValue)
        result = ausValue;
    else
        result = aiValue;
    return result;
}

struct BGSProjectile
{
    bool GetFlag(unsigned int flag) const;
    bool FUN_009b88e0();
};

bool BGSProjectile::GetFlag(unsigned int flag) const
{
    return false;
}

// @fnv 0x009b88e0
bool BGSProjectile::FUN_009b88e0()
{
    return GetFlag(0x800);
}

struct FUN_009bd540_Class
{
    float FUN_009bd540();
};
// @fnv 0x009bd540
float FUN_009bd540_Class::FUN_009bd540()
{
    return *(float*)((char*)this + 0x730);
}

struct GO
{
    void* operator=(void*);
};
struct FUN_009bd560_Class
{
    void SetObject(void* p);
};
// @fnv 0x009bd560
void FUN_009bd560_Class::SetObject(void* p)
{
    ((GO*)((char*)this + 0x11c))->operator=(p);
}

struct FUN_009bd580_class
{
    void FUN_009bd580(float value);
};

// @fnv 0x009bd580
void FUN_009bd580_class::FUN_009bd580(float value)
{
    *(float*)((char*)this + 0xec) = value;
}

struct FUN_009bd5a0_Class
{
    void FUN_009bd5a0(float value);
};

// @fnv 0x009bd5a0
void FUN_009bd5a0_Class::FUN_009bd5a0(float value)
{
    *(float*)((char*)this + 0xf0) = value;
}

struct FUN_009bd760_Class
{
    void FUN_009bd760(float value);
};

// @fnv 0x009bd760
void FUN_009bd760_Class::FUN_009bd760(float value)
{
    *(float*)((char*)this + 0xe4) = value;
}

struct FUN_009bdf60_class
{
    void FUN_009bdf60(int value);
};
// @fnv 0x009bdf60
void FUN_009bdf60_class::FUN_009bdf60(int value)
{
    *(int*)((char*)this + 0xf8) = value;
}

struct FUN_009beae0_class
{
    void __thiscall SetByte95(char value);
};

// @fnv 0x009beae0
void __thiscall FUN_009beae0_class::SetByte95(char value)
{
    ((char*)this)[0x95] = value;
}

extern "C" void NiFreeAlias(void*);
extern int DAT_0108e278;
struct FUN_009a4480_Class
{
    void* vfn_00;
    void* vfn_04;
    void* p;
    void __thiscall RemoveAll();
    void __thiscall FUN_009a4480();
};
// Sets the vtable pointer, calls RemoveAll, then frees the p member with NiFreeAlias.
// @fnv 0x009a4480
void __thiscall FUN_009a4480_Class::FUN_009a4480()
{
    vfn_00 = &DAT_0108e278;
    RemoveAll();
    NiFreeAlias(p);
}

extern void* DAT_0108e328;

void __cdecl NiFreeAlias(void* p);

struct CombatThreatRecord
{
    void* vfn_00;
    int pad_04;
    void* p_08;
    void __thiscall FUN_009a5e50();
};

// Sets the vtable pointer, clears the pointer map, and frees p_08.
// @fnv 0x009a5e50
void __thiscall CombatThreatRecord::FUN_009a5e50()
{
    *reinterpret_cast<void**>(this) = &DAT_0108e328;
    reinterpret_cast<NiTPointerMap<int, int>*>(this)->RemoveAll();
    NiFreeAlias(p_08);
}

struct GlobalObject_00869f00
{
};
void __fastcall FUN_009a3410(GlobalObject_00869f00*);
void __cdecl operator delete(void*);
struct FUN_009a3850_Class : public GlobalObject_00869f00
{
    void* __thiscall FUN_009a3850(unsigned int flags);
};
// Calls FUN_009a3410 on this, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x009a3850
void* __thiscall FUN_009a3850_Class::FUN_009a3850(unsigned int flags)
{
    FUN_009a3410(this);
    if (flags & 1)
        operator delete(this);
    return this;
}

extern "C" void Deallocate(void* p);
struct FUN_009a3460_shell
{
    void FUN_009a3460();
    void* __thiscall FUN_009a3880(unsigned int flags);
};
// @fnv 0x009a3880
void* FUN_009a3460_shell::FUN_009a3880(unsigned int flags)
{
    FUN_009a3460();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_009a35f0_class
{
    void __thiscall FUN_009a35f0();
};
struct FUN_009a38b0_class
{
    void __thiscall FUN_009a38b0();
    void* __thiscall FUN_009a38b0(unsigned int flags);
};
// @fnv 0x009a38b0
void* __thiscall FUN_009a38b0_class::FUN_009a38b0(unsigned int flags)
{
    ((FUN_009a35f0_class*)this)->FUN_009a35f0();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_009a38e0_Class
{
    void __thiscall FUN_009a3810();
    void* __thiscall FUN_009a38e0(unsigned int flags);
};
// Calls FUN_009a3810, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x009a38e0
void* __thiscall FUN_009a38e0_Class::FUN_009a38e0(unsigned int flags)
{
    FUN_009a3810();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void* p);
struct FUN_009a42c0_Class
{
    void __thiscall FUN_009a4420();
    void* __thiscall FUN_009a42c0(unsigned int flags);
};
// Calls FUN_009a4420, frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x009a42c0
void* FUN_009a42c0_Class::FUN_009a42c0(unsigned int flags)
{
    FUN_009a4420();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void* __cdecl NiMalloc(unsigned int size);
void* __cdecl memset(void* dest, int value, unsigned int count);
struct FUN_009a4290_class2
{
    void* __thiscall InitArray(int a);
};
// @fnv 0x009a43b0
void* FUN_009a4290_class2::InitArray(int a)
{
    *(int**)this = &DAT_0108e278;
    ((int*)this)[1] = a;
    ((int*)this)[3] = 0;
    int size = ((int*)this)[1] << 2;
    ((int**)this)[2] = (int*)NiMalloc(size);
    memset(((int**)this)[2], 0, ((int*)this)[1] << 2);
    return this;
}

struct FUN_009a44b0_Class : public FUN_009a4480_Class
{
    void* __thiscall FUN_009a44b0(unsigned int flags);
};

// Calls the base cleanup and, when bit 0 of flags is set, deletes this object; returns this.
// @fnv 0x009a44b0
void* __thiscall FUN_009a44b0_Class::FUN_009a44b0(unsigned int flags)
{
    FUN_009a4480();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
};
struct CombatTargetTimestamp
{
    void SaveTimeStamp(BGSSaveFormBuffer*);
};
struct FUN_009a4e90_shell
{
    void FUN_009a4e90(BGSSaveFormBuffer* buffer);
};
// @fnv 0x009a4e90
void FUN_009a4e90_shell::FUN_009a4e90(BGSSaveFormBuffer* buffer)
{
    buffer->SaveData((char*)this + 4, 4, 0);
    ((CombatTargetTimestamp*)((char*)this + 8))->SaveTimeStamp(buffer);
    ((CombatTargetTimestamp*)((char*)this + 12))->SaveTimeStamp(buffer);
    buffer->SaveData((char*)this + 16, 4, 0);
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_009a45e0_class
{
    void __thiscall FUN_009a45e0();
};
struct FUN_009a51b0_class : public FUN_009a45e0_class
{
    void* __thiscall FUN_009a51b0(unsigned int flags);
};
// Calls FUN_009a45e0, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x009a51b0
void* __thiscall FUN_009a51b0_class::FUN_009a51b0(unsigned int flags)
{
    FUN_009a45e0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern void* DAT_0108e328;
void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
struct FUN_009a5d80_class
{
    void* vfn_00;
    int pad_04;
    void* p_08;
    void* p_0c;
    FUN_009a5d80_class* __thiscall Construct(unsigned int size);
};
// Sets the vtable, stores size, allocates size*4 zeroed bytes into p_08 and returns this.
// @fnv 0x009a5d80
FUN_009a5d80_class* FUN_009a5d80_class::Construct(unsigned int size)
{
    vfn_00 = &DAT_0108e328;
    pad_04 = (int)size;
    p_0c = 0;
    unsigned int uiAllocSize = pad_04 << 2;
    p_08 = NiMalloc(uiAllocSize);
    memset(p_08, 0, pad_04 << 2);
    return this;
}

struct TESObjectWEAP
{
    bool IsRangedWeapon();
};
struct ActH2
{
    void* GetActiveWeapon();
};
// @fnv 0x009a96c0
bool FUN_009a96c0(ActH2* a)
{
    TESObjectWEAP* p = static_cast<TESObjectWEAP*>(a->GetActiveWeapon());
    if (p && p->IsRangedWeapon())
        return true;
    return false;
}

struct FUN_009aa280_Class
{
    int m0;
    int m4;
    bool __thiscall FUN_009aa280(int a);
};

// Returns true if a equals m4, or either value is -1; otherwise returns false.
// @fnv 0x009aa280
bool __thiscall FUN_009aa280_Class::FUN_009aa280(int aiValue)
{
    if (aiValue == m4 || aiValue == -1 || m4 == -1)
        return true;
    return false;
}

struct CombatWorldStateListNode
{
    CombatWorldStateListNode* GetNext();
    CombatWorldStateListNode* operator->();
};
struct FUN_009aa250_Class
{
    bool FUN_009aa250(unsigned int, unsigned int);
};
struct FUN_009aa3b0_Class
{
    bool HasMatchingEntry(unsigned int a, unsigned int b);
};
// Walks the linked list from this, calling FUN_009aa250 on each node's first pointer, and returns true if any returns true.
// @fnv 0x009aa3b0
bool FUN_009aa3b0_Class::HasMatchingEntry(unsigned int auiFirst, unsigned int auiSecond)
{
    CombatWorldStateListNode* p = (CombatWorldStateListNode*)this;
    while (p)
    {
        FUN_009aa250_Class* pEntry = (FUN_009aa250_Class*)((CombatWorldStateListNode**)p->operator->())[0];
        if (pEntry && pEntry->FUN_009aa250(auiFirst, auiSecond))
            return true;
        p = p->GetNext();
    }
    return false;
}

struct DummyFontManager
{
    int FUN_005bd5c0(int a);
};
struct FUN_009aad00Class
{
    void FUN_009aad00(int a, int b);
};
extern unsigned char DAT_011a55b4[256];

struct FUN_009aae10_Class
{
    void FUN_009aae10(int a, unsigned int b);
};

// If the per-index byte in DAT_011a55b4 is set, ORs bit b into the flags from FUN_005bd5c0 and passes them to FUN_009aad00; otherwise passes b.
// @fnv 0x009aae10
void FUN_009aae10_Class::FUN_009aae10(int aiIndex, unsigned int auiBit)
{
    if (DAT_011a55b4[aiIndex * 8])
    {
        int flags = ((DummyFontManager*)this)->FUN_005bd5c0(aiIndex);
        ((FUN_009aad00Class*)this)->FUN_009aad00(aiIndex, (1 << auiBit) | flags);
    }
    else
    {
        ((FUN_009aad00Class*)this)->FUN_009aad00(aiIndex, auiBit);
    }
}

struct FourDimensionalVector
{
    float x, y, z, w;
};
struct FUN_004b4e50_shell
{
    FourDimensionalVector* SetFromScaledVector3(void*);
};
struct FUN_009ae4d0_shell
{
    void FUN_009ae4d0(void*);
};
void __cdecl FUN_009ae4d0(void*);
struct FUN_009ae4a0_class
{
    void* __thiscall FUN_009ae4a0(void* arg);
};
// Calls FUN_009ae4d0 on this with arg, then SetFromScaledVector3 on the object at this+0x30 with arg+0x24, and returns this.
// @fnv 0x009ae4a0
void* __thiscall FUN_009ae4a0_class::FUN_009ae4a0(void* arg)
{
    ((FUN_009ae4d0_shell*)this)->FUN_009ae4d0(arg);
    ((FUN_004b4e50_shell*)((char*)this + 0x30))->SetFromScaledVector3((char*)arg + 0x24);
    return this;
}

struct hkpRigidBody
{
    void SetCollisionShape(void* p);
};
struct ScriptLocalsX
{
    hkpRigidBody* GetLocalData();
};
struct ScriptX
{
    void GetLocalData();
};
struct FUN_009b0c50_Class
{
    void FUN_009b0c50(int a);
};
// @fnv 0x009b0c50
void FUN_009b0c50_Class::FUN_009b0c50(int a)
{
    hkpRigidBody* p = reinterpret_cast<ScriptLocalsX*>(this)->GetLocalData();
    if (p)
    {
        reinterpret_cast<ScriptX*>(this)->GetLocalData();
        p->SetCollisionShape(reinterpret_cast<void*>(a));
        reinterpret_cast<ScriptX*>(this)->GetLocalData();
    }
}

namespace fnv_009b0cf0 {
struct ScriptLocalsX
{
    void* __thiscall GetLocalData();
};
struct ScriptX
{
    void __thiscall GetLocalData();
};
struct FUN_009b0d30_shell
{
    void FUN_009b0d30(int a);
};
struct FUN_009b0cf0_class
{
    void __thiscall FUN_009b0cf0(int a);
};
// @fnv 0x009b0cf0
void __thiscall FUN_009b0cf0_class::FUN_009b0cf0(int a)
{
    void* p = ((ScriptLocalsX*)this)->GetLocalData();
    if (p)
    {
        ((ScriptX*)this)->GetLocalData();
        ((FUN_009b0d30_shell*)p)->FUN_009b0d30(a);
        ((ScriptX*)this)->GetLocalData();
    }
}
}  // namespace fnv_009b0cf0

struct NiAVObject;
struct NiAdditionalGeometryData
{
    static NiAVObject* __cdecl GetShadowSceneNodeForIndex(int);
};
struct ExtraDataList
{
    void Set3DObject(NiAVObject*);
};
struct Flt
{
    operator unsigned int();
};
struct FUN_009b12d0_Class
{
    void FUN_009b12d0();
};
// @fnv 0x009b12d0
void FUN_009b12d0_Class::FUN_009b12d0()
{
    if (*(Flt*)((char*)this + 0xc4))
    {
        ((ExtraDataList*)NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))
            ->Set3DObject((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 0xc4));
        *(GO*)((char*)this + 0xc4) = 0;
    }
}

namespace fnv_009b3130 {
struct FUN_009b3f80_shell
{
    void __thiscall FUN_009b3f80();
};
void* __cdecl Deallocate(void* p);
struct FUN_009b3130_class
{
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};
// @fnv 0x009b3130
void* __thiscall FUN_009b3130_class::DestroyIfFlagged(unsigned int flags)
{
    ((FUN_009b3f80_shell*)this)->FUN_009b3f80();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}  // namespace fnv_009b3130

void __cdecl InitFromObjects(int a1, int a2, int a3, int a4, int a5);
void __cdecl InitHitData(int a1, int a2, int a3, int a4, unsigned char a5);

// Calls InitFromObjects with a6 when a6 is nonzero, otherwise calls InitHitData with a5, forwarding a1-a4.
// @fnv 0x009b5120
void __cdecl FUN_009b5120(int aiArg1, int aiArg2, int aiArg3, int aiArg4, unsigned char a5, int a6, int a7)
{
    if (a6)
        InitFromObjects(aiArg1, aiArg2, aiArg3, aiArg4, a6);
    else
        InitHitData(aiArg1, aiArg2, aiArg3, aiArg4, a5);
}

struct FUN_009b7970_shell
{
    void InitializeAndClear();
    void* __thiscall FUN_009b79f0(unsigned int flags);
};
// @fnv 0x009b79f0
void* __thiscall FUN_009b7970_shell::FUN_009b79f0(unsigned int flags)
{
    InitializeAndClear();
    if (flags & 1)
        operator delete(this);
    return this;
}

namespace fnv_009bb7f0 {
struct TESChallenge
{
    TESForm* GetFormOne();
};
struct NiAVObject;
struct NiLight;
struct TESObjectLIGH
{
    NiLight* CreateLight(TESObjectREFR*, NiAVObject*, bool);
};
struct Flt
{
    operator unsigned int();
};
struct FUN_009bb7f0_shell
{
    void UpdateLightFromChallenge();
};
// @fnv 0x009bb7f0
void FUN_009bb7f0_shell::UpdateLightFromChallenge()
{
    if (reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0xc)->operator unsigned int() &&
        reinterpret_cast<TESChallenge*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x14))->GetFormOne())
    {
        reinterpret_cast<GO*>(reinterpret_cast<char*>(this) + 0x10)
            ->
            operator=(
                reinterpret_cast<TESObjectLIGH*>(
                    reinterpret_cast<TESChallenge*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x14))
                        ->GetFormOne())
                    ->CreateLight(
                        0,
                        reinterpret_cast<NiAVObject*>(
                            reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0xc)->operator unsigned int()),
                        true));
    }
}
}  // namespace fnv_009bb7f0

struct S9b46c0
{
    bool FUN_00444d00(int a);
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
};
struct FUN_009bec90_class
{
    void __thiscall FUN_009bec90();
};
// @fnv 0x009bec90
void __thiscall FUN_009bec90_class::FUN_009bec90()
{
    if (((S9b46c0*)this)->FUN_00444d00(1))
        ((S9b46c0*)this)->vfn_328();
}

struct CombatThreatEntry
{
    char m0[20];
};
void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int size);
struct FUN_009a3b20_Class
{
    void CopyCombatThreatEntries(CombatThreatEntry* a, CombatThreatEntry* b, unsigned int c);
};
// Copies c 20-byte CombatThreatEntry records from b to a, forward if a<b and backward if a>b.
// @fnv 0x009a3b20
void FUN_009a3b20_Class::CopyCombatThreatEntries(CombatThreatEntry* apDest, CombatThreatEntry* apSrc,
                                                 unsigned int auiCount)
{
    if (auiCount <= 0)
        return;
    if (apDest < apSrc)
    {
        for (unsigned int i = 0; i < auiCount; i++)
            FUN_00ec7230((char*)(apDest + i), (const char*)(apSrc + i), 20);
    }
    else if (apDest > apSrc)
    {
        for (int i = (int)auiCount - 1; i >= 0; i--)
            FUN_00ec7230((char*)(apDest + i), (const char*)(apSrc + i), 20);
    }
}

struct FUN_006a8a30_class
{
    void FUN_006a8a30(int, unsigned int);
};
struct FUN_009a3d00_class
{
    virtual void* vfn_00();
    virtual int FUN_009a3d00(unsigned int a);
    int m4;
    int m8;
    int mc;
    void FUN_009a3d00(unsigned int a, unsigned int b);
};
// @fnv 0x009a3d00
void FUN_009a3d00_class::FUN_009a3d00(unsigned int a, unsigned int b)
{
    m4 = 0;
    m8 = 0;
    mc = 0;
    if (b > a)
        a = b;
    if (a > 0)
    {
        m4 = FUN_009a3d00(a);
        mc = a;
    }
    if (b > 0)
    {
        ((FUN_006a8a30_class*)this)->FUN_006a8a30(m4, b);
        m8 = b;
    }
}

struct Projectile
{
    Projectile(bool b);
    ~Projectile();
    void SetFormType(int type);
};
struct FUN_009b3160 : Projectile
{
    FUN_009b3160(bool b);
};
// Initialises a Projectile: installs two vtables, sets form type 0x40, and zeroes the floats at offsets 0x150 and 0x154.
// @fnv 0x009b3160
FUN_009b3160::FUN_009b3160(bool b) : Projectile(b)
{
    *(void**)((char*)this + 0) = (void*)0x0108f2f4;
    *(void**)((char*)this + 0x18) = (void*)0x0108f2e8;
    SetFormType(0x40);
    *(float*)((char*)this + 0x150) = 0.0f;
    *(float*)((char*)this + 0x154) = 0.0f;
}

namespace fnv_009b5650 {
struct Sky
{
    int FUN_00476c90();
};
struct IC
{
    float GetConditionPercent(bool);
};
struct TESObjectREFR
{
    float GetScale();
};
struct Obj
{
    float GetFieldDC();
};
struct BooleanFloatQuery
{
    void* a;
    void* b;
    void* p_08;
    float p_14;
    float p_18;
    int p_30;
    float p_34;
    void ApplyCriticalHit();
    void FUN_009b5a30(bool);
    void FUN_009b6620(void*);
    void ApplyDamageEffects();
};
// @fnv 0x009b5650
void InitFromObjects(BooleanFloatQuery* hd, void* target, void* weapon, void* source, void* extra)
{
    if (!hd)
        return;
    hd->a = target;
    hd->b = weapon;
    ((int*)hd)[12] = extra ? ((Sky*)extra)->FUN_00476c90() : 0;
    ((float*)hd)[13] = source ? ((IC*)source)->GetConditionPercent(true) : 1.0f;
    hd->p_08 = extra;
    ((float*)hd)[5] = ((Obj*)extra)->GetFieldDC();
    if (target)
        ((float*)hd)[5] *= ((TESObjectREFR*)target)->GetScale();
    ((float*)hd)[6] = ((float*)hd)[5];
    hd->ApplyCriticalHit();
    hd->FUN_009b5a30(true);
    hd->FUN_009b6620(extra);
    hd->ApplyDamageEffects();
}
}  // namespace fnv_009b5650

struct NiLight;
struct ShadowSceneLight;
struct ShadowSceneNode
{
    ShadowSceneLight* GetShadowSceneLight(NiLight*, bool);
};
struct FUN_00b5b4a0_holder
{
    int FUN_00b5b4a0(unsigned int);
};
struct NiPointLight
{
    void FUN_0050dd20(float);
};
struct FUN_009bb8a0_Class
{
    unsigned char m0;
    int m4;
    int m8;
    int mc;
    Flt mf;
    void __thiscall UpdateLightVisibility();
};
// @fnv 0x009bb8a0
void __thiscall FUN_009bb8a0_Class::UpdateLightVisibility()
{
    char b;
    if ((unsigned int)mf)
    {
        if (m0)
        {
            if (!((FUN_00b5b4a0_holder*)NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))
                     ->FUN_00b5b4a0((unsigned int)mf))
            {
                b = 0;
                ((ShadowSceneNode*)NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))
                    ->GetShadowSceneLight((NiLight*)(unsigned int)mf, true);
            }
        }
        ((NiPointLight*)(unsigned int)mf)->FUN_0050dd20(m0 ? 1.0f : 0.0f);
    }
}

int _sprintf_s(char*, unsigned int, const char*, ...);
int __cdecl FUN_009aa1b0(int a, int b);
int __cdecl GetKeywordName(int a);
extern char $SG3667[];
struct FUN_009aa150_Class
{
    int m0;
    int m4;
    int __thiscall GetKeywordName();
    void __thiscall FUN_009aa150(char* a, unsigned int b, int c);
};
// @fnv 0x009aa150
void __thiscall FUN_009aa150_Class::FUN_009aa150(char* pBuffer, unsigned int uiBufferSize, int c)
{
    if (c == -1)
        c = m4;
    int v = FUN_009aa1b0(m0, c);
    _sprintf_s(pBuffer, uiBufferSize, "%s: %s", GetKeywordName(), v);
}

struct NiPoint3
{
    float x, y, z;
};
struct M9c10
{
    void FUN_00439f50(unsigned int, NiPoint3&);
};
struct FUN_009ae540_Class
{
    void* __thiscall FUN_009ae540(NiPoint3&);
    void* p10;
    void* p20;
};
struct BSSimpleListX
{
    BGSPerk** GetItem();
};
struct FUN_009ae4d0_Class : FUN_009ae540_Class
{
    FUN_009ae540_Class* __thiscall FUN_009ae4d0(void* a);
};
// @fnv 0x009ae4d0
FUN_009ae540_Class* __thiscall FUN_009ae4d0_Class::FUN_009ae4d0(void* a)
{
    NiPoint3 l;
    ((BSSimpleListX*)&l)->GetItem();
    ((M9c10*)a)->FUN_00439f50(0, l);
    this->FUN_009ae540(l);
    ((M9c10*)a)->FUN_00439f50(1, l);
    ((FUN_009ae540_Class*)((char*)this + 0x10))->FUN_009ae540(l);
    ((M9c10*)a)->FUN_00439f50(2, l);
    ((FUN_009ae540_Class*)((char*)this + 0x20))->FUN_009ae540(l);
    return this;
}

struct TESObjectLIGH
{
    void* CreateLight(void* a, void* b, bool c);
};
struct XActor
{
    void* GetActorBase();
};
struct EffectSetting
{
    EffectSetting* GetCastSound() const;
};
struct FUN_009b1260_Class
{
    virtual void vf_00();
    virtual void vf_04();
    virtual void vf_08();
    virtual void vf_0c();
    virtual void vf_10();
    virtual void vf_14();
    virtual void vf_18();
    virtual void vf_1c();
    virtual void vf_20();
    virtual void vf_24();
    virtual void vf_28();
    virtual void vf_2c();
    virtual void vf_30();
    virtual void vf_34();
    virtual void vf_38();
    virtual void vf_3c();
    virtual void vf_40();
    virtual void vf_44();
    virtual void vf_48();
    virtual void vf_4c();
    virtual void vf_50();
    virtual void vf_54();
    virtual void vf_58();
    virtual void vf_5c();
    virtual void vf_60();
    virtual void vf_64();
    virtual void vf_68();
    virtual void vf_6c();
    virtual void vf_70();
    virtual void vf_74();
    virtual void vf_78();
    virtual void vf_7c();
    virtual void vf_80();
    virtual void vf_84();
    virtual void vf_88();
    virtual void vf_8c();
    virtual void vf_90();
    virtual void vf_94();
    virtual void vf_98();
    virtual void vf_9c();
    virtual void vf_a0();
    virtual void vf_a4();
    virtual void vf_a8();
    virtual void vf_ac();
    virtual void vf_b0();
    virtual void vf_b4();
    virtual void vf_b8();
    virtual void vf_bc();
    virtual void vf_c0();
    virtual void vf_c4();
    virtual void vf_c8();
    virtual void vf_cc();
    virtual void vf_d0();
    virtual void vf_d4();
    virtual void vf_d8();
    virtual void vf_dc();
    virtual void vf_e0();
    virtual void vf_e4();
    virtual void vf_e8();
    virtual void vf_ec();
    virtual void vf_f0();
    virtual void vf_f4();
    virtual void vf_f8();
    virtual void vf_fc();
    virtual void vf_100();
    virtual void vf_104();
    virtual void vf_108();
    virtual void vf_10c();
    virtual void vf_110();
    virtual void vf_114();
    virtual void vf_118();
    virtual void vf_11c();
    virtual void vf_120();
    virtual void vf_124();
    virtual void vf_128();
    virtual void vf_12c();
    virtual void vf_130();
    virtual void vf_134();
    virtual void vf_138();
    virtual void vf_13c();
    virtual void vf_140();
    virtual void vf_144();
    virtual void vf_148();
    virtual void vf_14c();
    virtual void vf_150();
    virtual void vf_154();
    virtual void vf_158();
    virtual void vf_15c();
    virtual void vf_160();
    virtual void vf_164();
    virtual void vf_168();
    virtual void vf_16c();
    virtual void vf_170();
    virtual void vf_174();
    virtual void vf_178();
    virtual void vf_17c();
    virtual void vf_180();
    virtual void vf_184();
    virtual void vf_188();
    virtual void vf_18c();
    virtual void vf_190();
    virtual void vf_194();
    virtual void vf_198();
    virtual void vf_19c();
    virtual void vf_1a0();
    virtual void vf_1a4();
    virtual void vf_1a8();
    virtual void vf_1ac();
    virtual void vf_1b0();
    virtual void vf_1b4();
    virtual void vf_1b8();
    virtual void vf_1bc();
    virtual void vf_1c0();
    virtual void vf_1c4();
    virtual void vf_1c8();
    virtual void vf_1cc();
    virtual void* vf_1d0();
    virtual void UpdateCastSound();
};

// @fnv 0x009b1260
void FUN_009b1260_Class::UpdateCastSound()
{
    if (vf_1d0() && ((EffectSetting*)((XActor*)this)->GetActorBase())->GetCastSound())
    {
        ((GO*)((char*)this + 0xc4))
            ->
            operator=(((TESObjectLIGH*)((EffectSetting*)((XActor*)this)->GetActorBase())->GetCastSound())
                          ->CreateLight((XActor*)this, vf_1d0(), false));
    }
}

struct FUN_009b5a30_Class
{
    void* vfn_00;
    void* vfn_04;
    void* vfn_08;
    void* vfn_0c;
    void* vfn_10;
    float f14;
    float f18;
    int i1c;
    void __thiscall FUN_009b5a30(int a);
    void __thiscall ApplyDamageEffects();
};

// @fnv 0x009b5720
void __cdecl FUN_009b5720(FUN_009b5a30_Class* a, int b, int c, float afValue)
{
    if (!a)
        return;
    a->vfn_00 = (void*)b;
    a->vfn_04 = (void*)c;
    a->vfn_08 = (void*)b;
    a->f14 = afValue;
    a->f18 = afValue;
    a->FUN_009b5a30(0);
    a->ApplyDamageEffects();
}

struct ShadowNode
{
    void* m0;
    void* m4;
    void* m8;
    void* mc;
    Flt m10;
    void* m14;
    void FUN_009bb850();
};
// @fnv 0x009bb850
void ShadowNode::FUN_009bb850()
{
    if (m10)
    {
        ((ExtraDataList*)NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))
            ->Set3DObject((NiAVObject*)(unsigned int)m10);
        ((GO*)((char*)this + 0x10))->operator=(0);
    }
}

struct FUN_009a39f0_class
{
    virtual void FUN_009a39f0_virtual0();
    virtual int FUN_009a39f0_virtual1(unsigned int size);

    int m4;
    int m8;
    int mc;

    void __thiscall ConstructObjects(int a, int b);
    void __thiscall FUN_009a39f0(unsigned int requested, unsigned int savedSize);
};

// @fnv 0x009a39f0
inline void FUN_009a39f0_class::FUN_009a39f0_virtual0()
{}

inline int FUN_009a39f0_class::FUN_009a39f0_virtual1(unsigned int size)
{
    return 0;
}

void __thiscall FUN_009a39f0_class::FUN_009a39f0(unsigned int requested, unsigned int savedSize)
{
    m4 = 0;
    m8 = 0;
    mc = 0;

    if (savedSize > requested)
    {
        requested = savedSize;
    }

    if (requested > 0)
    {
        m4 = FUN_009a39f0_virtual1(requested);
        mc = requested;
    }

    if (savedSize > 0)
    {
        ConstructObjects(m4, savedSize);
        m8 = savedSize;
    }
}

struct FUN_009a3bc0_class
{
    virtual void vfn_00() = 0;
    virtual int Write(unsigned int size) = 0;

    int m_uiLogicalSize;
    int m_iPosition;
    int m_iDataLength;

    void __thiscall Initialize(unsigned int requested, unsigned int savedSize);
    void __thiscall ConstructEntries(unsigned int a, unsigned int b);
};

// @fnv 0x009a3bc0
void FUN_009a3bc0_class::Initialize(unsigned int uiRequestedSize, unsigned int savedSize)
{
    m_uiLogicalSize = 0;
    m_iPosition = 0;
    m_iDataLength = 0;

    if (savedSize > uiRequestedSize)
    {
        uiRequestedSize = savedSize;
    }

    if (uiRequestedSize > 0)
    {
        m_uiLogicalSize = Write(uiRequestedSize);
        m_iDataLength = uiRequestedSize;
    }

    if (savedSize > 0)
    {
        ConstructEntries(m_uiLogicalSize, savedSize);
        m_iPosition = savedSize;
    }
}

struct BGSLoadFormBuffer
{
    void ReadTypedData(void*, unsigned int);
};

struct CombatTimeStamp_LoadGameHelper
{
    void LoadGame(BGSLoadFormBuffer* buffer);
};

struct FUN_009a4ef0_Class
{
    void FUN_009a4ef0(BGSLoadFormBuffer* buffer);
};

// @fnv 0x009a4ef0
void FUN_009a4ef0_Class::FUN_009a4ef0(BGSLoadFormBuffer* buffer)
{
    buffer->ReadTypedData((char*)this + 4, 4);
    ((CombatTimeStamp_LoadGameHelper*)((char*)this + 8))->LoadGame(buffer);
    ((CombatTimeStamp_LoadGameHelper*)((char*)this + 0xc))->LoadGame(buffer);
    buffer->ReadTypedData((char*)this + 0x10, 4);
}

struct RegionPoint
{
    float GetX() const;
};
struct FUN_009a5170_Class
{
    char m0;
    char m1;
    char m2;
    char m3;
    char m4;
    char m5;
    char m6;
    char m7;
    char m8;
    char m9;
    char ma;
    char mb;
    RegionPoint pt;
    bool IsXLessThan(float value);
};

// Returns whether pt.GetX() is less than value.
// @fnv 0x009a5170
bool FUN_009a5170_Class::IsXLessThan(float value)
{
    return pt.GetX() < value;
}

struct NiTMap
{
    void GetNext(void*& position, unsigned int& key, void*& value);
};

struct MapX : public NiTMap
{
    void* GetFirstPos();
};

struct CombatThreatMap : public MapX
{
    void SaveThreats(BGSSaveFormBuffer* buffer);
};

struct FUN_00865f20_shell
{
    unsigned int __thiscall FUN_00865f20();
};

struct FUN_00865ff0_shell
{
    void __thiscall FUN_00865ff0(int count, unsigned int size);
};

struct FUN_00865db0_shell
{
    void __thiscall FUN_00865db0(unsigned int key, unsigned int flags);
};

// @fnv 0x009a59e0
void CombatThreatMap::SaveThreats(BGSSaveFormBuffer* buffer)
{
    unsigned int position = 0;
    unsigned int size = reinterpret_cast<FUN_00865f20_shell*>(buffer)->FUN_00865f20();
    void* count = GetFirstPos();

    while (count)
    {
        unsigned int uiThreatKey;
        void* key = 0;
        GetNext(count, uiThreatKey, key);

        if (key)
        {
            reinterpret_cast<FUN_00865db0_shell*>(buffer)->FUN_00865db0(uiThreatKey, 0);
            reinterpret_cast<FUN_009a4e90_shell*>(key)->FUN_009a4e90(buffer);
            ++position;
        }
    }

    reinterpret_cast<FUN_00865ff0_shell*>(buffer)->FUN_00865ff0(position, size);
}

struct FUN_009a5df0
{
    virtual ~FUN_009a5df0();
};
struct FUN_009a5d50_class : FUN_009a5df0
{
    virtual void* FUN_009a5d50(unsigned int flags);
};
// Runs the base destructor, frees this when flags has bit 0 set, and returns this.
// @fnv 0x009a5d50
void* FUN_009a5d50_class::FUN_009a5d50(unsigned int flags)
{
    FUN_009a5df0::~FUN_009a5df0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);

struct FUN_009a5e80 : CombatThreatRecord
{
    void* FUN_009a5e81(unsigned int flags);
};

// Calls FUN_009a5e50, then if the low bit of flags is set calls Deallocate on this, and returns this.
// @fnv 0x009a5e80
void* FUN_009a5e80::FUN_009a5e81(unsigned int flags)
{
    FUN_009a5e50();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern float DAT_011f1c00;
float FUN_004587d0(float);
struct CellHelper
{
    static void* GetExteriorbhkWorld();
};
struct FUN_009a6080_Class
{
    void* FUN_009a6080();
};
struct bhkCharacterController
{
    float& GetVectorElement(int);
};
// @fnv 0x009a6050
void NegateCharacterControllerValue()
{
    DAT_011f1c00 =
        -FUN_004587d0(reinterpret_cast<bhkCharacterController*>(
                          reinterpret_cast<FUN_009a6080_Class*>(CellHelper::GetExteriorbhkWorld())->FUN_009a6080())
                          ->GetVectorElement(2));
}

extern int DAT_011a55b0[2];

// @fnv 0x009aa140
int FUN_009aa140(int index)
{
    return *(int*)((char*)DAT_011a55b0 + index * 8);
}

// If a equals the value stored at this, forwards b to FUN_009aa280 and returns its result; otherwise returns false.
// @fnv 0x009aa250
bool FUN_009aa250_Class::FUN_009aa250(unsigned int a, unsigned int uiValue)
{
    if (a == *(unsigned int*)this)
        return ((FUN_009aa280_Class*)this)->FUN_009aa280((int)uiValue);
    return false;
}

struct FUN_009ab970_Class
{
    char m0[0xd30];
    struct NiPoint3
    {
        float x, y, z;
    };
    NiPoint3& FUN_009ab970(NiPoint3& akDest);
};
// Copies the NiPoint3 stored at offset 0xd30 of this object into akDest and returns it.
// @fnv 0x009ab970
FUN_009ab970_Class::NiPoint3& FUN_009ab970_Class::FUN_009ab970(NiPoint3& akDest)
{
    akDest = *reinterpret_cast<NiPoint3*>(reinterpret_cast<unsigned char*>(this) + 0xd30);
    return akDest;
}

struct TESSaveLoadGame
{
    void* GetHitSound();
};
struct TESWorldSpace
{
    void* GetWorldTerrainManager();
};
struct KFModel
{
    void* GetControllerSequence();
};
extern int g_TES;

struct FUN_009acd00_Class
{
    void FUN_009acd00();
};

// Gets a pointer from the object's vtable slot 0x1d0, then resolves a model via g_TES and calls its vtable slot 0xdc with that pointer and 1.
// @fnv 0x009acd00
void FUN_009acd00_Class::FUN_009acd00()
{
    void* p = ((void*(__thiscall*)(void*))(*(void***)this)[0x1d0 / 4])(this);
    if (p != 0)
    {
        void* c = ((KFModel*)((TESWorldSpace*)((TESSaveLoadGame*)g_TES)->GetHitSound())->GetWorldTerrainManager())
                      ->GetControllerSequence();
        if (c != 0)
        {
            ((void(__thiscall*)(void*, void*, int))(*(void***)c)[0xdc / 4])(c, p, 1);
        }
    }
}

struct SL
{
    SL();
    ~SL();
};
struct FUN_009b0f40
{
    void* m0;
    bool m4;
    bool m5;
    bool m6;
    char pad_07;
    SL m8;
    FUN_009b0f40();
};
// Initializes the object: clears m0 and sets the m4, m5 and m6 flags to false.
// @fnv 0x009b0f40
FUN_009b0f40::FUN_009b0f40() : m8()
{
    m0 = 0;
    m4 = false;
    m5 = false;
    m6 = false;
}

struct FUN_0057c530Class
{
    void FUN_0057c530();
};

struct FUN_009b2db0_Class
{
    void FUN_009b2db0();
};

// @fnv 0x009b2db0
void FUN_009b2db0_Class::FUN_009b2db0()
{
    ((FUN_0057c530Class*)this)->FUN_0057c530();
}

struct CalleeObj
{
    void FUN_00622570(bool);
};
struct FUN_009b2dd0_Class
{
    CalleeObj* FUN_009b2dd0(CalleeObj* p);
};
// Calls p->FUN_00622570 with whether the object's field at offset 12 differs from the field at offset 0, then returns p.
// @fnv 0x009b2dd0
CalleeObj* FUN_009b2dd0_Class::FUN_009b2dd0(CalleeObj* apCallee)
{
    apCallee->FUN_00622570(reinterpret_cast<int*>(this)[3] != reinterpret_cast<int*>(this)[0]);
    return apCallee;
}

struct MemoryManager
{
    int x;
};
MemoryManager* __cdecl _D1A0E0GetMemoryRouter();
struct S006e7620_R2
{
    void FUN_005e0ad0();
};
struct FUN_009b2e60_List
{
    S006e7620_R2* GetItem(unsigned int a, unsigned int b);
};
// @fnv 0x009b2e60
void CallItemMethod(unsigned int a, unsigned int b)
{
    FUN_009b2e60_List* p = (FUN_009b2e60_List*)_D1A0E0GetMemoryRouter();
    p->GetItem((a * 0x70 + 0x7f) & 0xffffff80, b)->FUN_005e0ad0();
}

typedef unsigned char ByteTag;
void __cdecl FUN_009b2ed0(void*, int, int, ByteTag);

// If count is greater than 1, calls FUN_009b2ed0 with the range from 0 to count-1 and the given tag.
// @fnv 0x009b2e90
void __cdecl FUN_009b2e90(void* p, int count, ByteTag tag)
{
    if (count > 1)
    {
        int start = 0;
        int i = count - 1;
        FUN_009b2ed0(p, start, i, tag);
    }
}

namespace fnv_009b3100 {
struct bhkCharacterController
{
    float& GetVectorElement(int a);
};
struct FUN_009b3100_class
{
    float FUN_009b3100();
};
// @fnv 0x009b3100
float FUN_009b3100_class::FUN_009b3100()
{
    return (*(bhkCharacterController*)((char*)this + 0x10)).GetVectorElement(3);
}
}  // namespace fnv_009b3100

struct SFTX
{
    void* vptr;
    void SetFormType(int a);
};

struct FUN_009bbef0_DestructibleMember
{
    int value;
    FUN_009bbef0_DestructibleMember();
    ~FUN_009bbef0_DestructibleMember();
};

struct FUN_009bbef0 : public SFTX
{
    FUN_009bbef0_DestructibleMember member_04;
    unsigned char pad_08[0x10];
    FUN_009bbef0(void* a, void* b, void* c, NiPoint3 position, float d, float e);
};

extern void* DAT_0108f2e8;
extern void* DAT_0108f2f4;

struct FUN_009b31f0 : public FUN_009bbef0
{
    void* p_18;
    unsigned char pad_1c[0x134];
    float f_150;
    float f_154;

    FUN_009b31f0(void* a, void* b, void* c, NiPoint3 position, float d, float e);
};

// Initializes the base, sets the vtable and p_18 pointers, sets form type 0x40, and zeroes f_150 and f_154.
// @fnv 0x009b31f0
FUN_009b31f0::FUN_009b31f0(void* a, void* b, void* c, NiPoint3 position, float d, float e)
    : FUN_009bbef0(a, b, c, position, d, e)
{
    vptr = &DAT_0108f2f4;
    p_18 = &DAT_0108f2e8;
    SetFormType(0x40);
    f_150 = 0.0f;
    f_154 = 0.0f;
}

struct FUN_009b7c90_shell
{
    bool __thiscall FUN_009b7c90();
};

struct FUN_009d9f00_Class
{
    unsigned int __thiscall FUN_009d9f00();
};

struct FUN_008256d0_shell
{
    bool __thiscall FUN_008256d0();
};

struct FUN_009b8a20_class
{
    void __thiscall FUN_009b8a20();
};

// @fnv 0x009b8a20
void FUN_009b8a20_class::FUN_009b8a20()
{
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150) == 3)
    {
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150) = 4;
    }
    else
    {
        if (!reinterpret_cast<FUN_008256d0_shell*>(reinterpret_cast<char*>(this) + 0x88)->FUN_008256d0())
        {
            *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150) = 1;

            if (reinterpret_cast<FUN_009b7c90_shell*>(reinterpret_cast<XActor*>(this)->GetActorBase())->FUN_009b7c90())
            {
                *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150) = 3;
            }

            if (reinterpret_cast<S9b46c0*>(this)->FUN_00444d00(1))
            {
                if (!reinterpret_cast<S9b46c0*>(this)->FUN_00444d00(2))
                {
                    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150) = 0;
                }
            }

            if (!reinterpret_cast<S9b46c0*>(this)->FUN_00444d00(1))
            {
                if (reinterpret_cast<BGSProjectile*>(reinterpret_cast<XActor*>(this)->GetActorBase())->GetFlag(0x10) ||
                    reinterpret_cast<FUN_009d9f00_Class*>(this)->FUN_009d9f00())
                {
                    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150) = 2;
                }
            }
        }
    }
}

struct FUN_009a03d0_inner
{
    unsigned int unk00[0x68 / 4];
    unsigned int m_68;
    bool Check();
    int Make(int);
};

struct FUN_009a03d0_cls
{
    unsigned int unk00[0xe4 / 4];
    FUN_009a03d0_inner* m_e4;
    void Helper1(unsigned int);
    void Helper2(FUN_009a03d0_inner*);
    void FUN_009a03d0(unsigned char flag);
};

// If m_e4 is set, optionally calls Helper1 with its m_68, calls Helper2 when Check() passes, calls Make(1), then clears m_e4.
// @fnv 0x009a03d0
void __thiscall FUN_009a03d0_cls::FUN_009a03d0(unsigned char flag)
{
    if (m_e4 != 0)
    {
        if (flag)
        {
            Helper1(m_e4->m_68);
        }
        if (m_e4->Check())
        {
            Helper2(m_e4);
        }
        FUN_009a03d0_inner* a = m_e4;
        FUN_009a03d0_inner* b5 = a;
        (b5 != 0) ? b5->Make(1) : 0;
        m_e4 = 0;
    }
}

extern "C" int __fastcall FUN_004030b0(void* obj);
extern "C" float __cdecl FUN_0047eeb0(unsigned int v);
extern const double DAT_01012060;

class FUN_009a1380_cls
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    float m_08;
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
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned char unkC0;
    unsigned char unkC1;
    unsigned char unkC2;
    unsigned char unkC3;
    unsigned char unkC4;
    unsigned char unkC5;
    unsigned char unkC6;
    unsigned char unkC7;
    unsigned char unkC8;
    unsigned char m_c9;
    unsigned char unkCA;
    unsigned char unkCB;
    float m_cc;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    void* m_1c4;
    unsigned char FUN_009a1380();
};

// Returns 1 if m_08 is less than a value derived from m_c9 (reduced by m_cc when above DAT_01012060), or 0 if FUN_004030b0(m_1c4) is zero.
// @fnv 0x009a1380
unsigned char FUN_009a1380_cls::FUN_009a1380()
{
    float f;
    if (FUN_004030b0(m_1c4) == 0)
    {
        return 0;
    }
    f = FUN_0047eeb0(m_c9);
    if (f > DAT_01012060)
    {
        f -= m_cc;
    }
    return (m_08 < f) ? 1 : 0;
}

struct FUN_009a3910_cls
{
    int m_00;
    int m_04;
    int m_08;
    unsigned int m_0c;
    int FUN_009a3910();
};

// Returns m_0c plus 0x400 when m_0c exceeds 0x400, otherwise returns m_0c shifted left by one.
// @fnv 0x009a3910
int FUN_009a3910_cls::FUN_009a3910()
{
    return (this->m_0c > 0x400) ? (int)(this->m_0c + 0x400) : (int)(this->m_0c << 1);
}

void* __cdecl operator new(unsigned int count, void* place);
void __cdecl operator delete(void* ptr, void* place);
struct FUN_009a3d90
{
    int timestamp;
    int flags;
    FUN_009a3d90();
};
struct FUN_009a3950_Class
{
    void ConstructObjects(FUN_009a3d90* objects, unsigned int count);
};
// Default-constructs each of count FUN_009a3d90 objects in the array at objects via placement new.
// @fnv 0x009a3950
void FUN_009a3950_Class::ConstructObjects(FUN_009a3d90* objects, unsigned int count)
{
    for (unsigned int index = 0; index < count; ++index)
    {
        new (&objects[index]) FUN_009a3d90();
    }
}

struct FUN_009a3c50_cls
{
    virtual void vfn_00();
    virtual int v1(int a);
    virtual void vfn_08();
    virtual int v3(int a, int b);
    int m_04;
    int m_08;
    int m_0c;
    void UpdateThreat(int a1, int a2);
    void unkHelper();
};

// Maintains m_04: if empty, stores v1(a1) and m_0c=a1; if a2 matches m_0c, combines via v3, otherwise replaces m_04 with v1(a1) after CopyCombatThreatEntries and unkHelper.
// @fnv 0x009a3c50
void FUN_009a3c50_cls::UpdateThreat(int a1, int a2)
{
    if (m_04 != 0)
    {
        if (a2 == m_0c)
        {
            m_04 = v3(m_04, a1);
        }
        else
        {
            int r = v1(a1);
            ((FUN_009a3b20_Class*)this)
                ->CopyCombatThreatEntries((CombatThreatEntry*)r, (CombatThreatEntry*)m_04, (unsigned int)a2);
            unkHelper();
            m_04 = r;
        }
    }
    else
    {
        m_04 = v1(a1);
        m_0c = a1;
    }
}

class Obj;

class Iface
{
  public:
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
    virtual void v58(Obj* p);
};

class Obj
{
  public:
    Iface* Lookup();
};

class Member
{
  public:
    unsigned int unk00;
    Obj* Get();
    ~Member();
};

class Base
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ~Base();
};

bool __cdecl CalleeC();
void* __stdcall CalleeD(Obj* p);

class Sink
{
  public:
    void Take();
};

class FUN_009a3db0_cls : public Base
{
  public:
    Member m_10;
    ~FUN_009a3db0_cls();
};

// Destructor: if m_10.Get() and its Lookup() are non-null, calls v58 on the interface or Take on the result of CalleeD depending on CalleeC().
// @fnv 0x009a3db0
FUN_009a3db0_cls::~FUN_009a3db0_cls()
{
    if (m_10.Get() != 0 && m_10.Get()->Lookup() != 0)
    {
        if (!CalleeC())
        {
            m_10.Get()->Lookup()->v58(m_10.Get());
        }
        else
        {
            ((Sink*)CalleeD(m_10.Get()))->Take();
        }
    }
}

struct CombatEntry
{
    ~CombatEntry();
};

struct CombatEntryOwner
{
    bool __thiscall GetAt(int key, CombatEntry** result);
    void __thiscall RemoveKey(int key);
    void __thiscall RemoveEntry(int key);
};

// @fnv 0x009a41e0
void CombatEntryOwner::RemoveEntry(int key)
{
    CombatEntry* entry = 0;
    if (GetAt(key, &entry))
    {
        RemoveKey(key);
        delete entry;
    }
}

struct CombatOwner;
struct CombatOwnerManager
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4C();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual void unk5C();
    virtual void unk60();
    virtual void unk64();
    virtual void unk68();
    virtual void unk6C();
    virtual void unk70();
    virtual void unk74();
    virtual void unk78();
    virtual void unk7C();
    virtual void unk80();
    virtual void unk84();
    virtual void unk88();
    virtual void unk8C();
    virtual void unk90();
    virtual void unk94();
    virtual void unk98();
    virtual void unk9C();
    virtual void unkA0();
    virtual void unkA4();
    virtual void unkA8();
    virtual void unkAC();
    virtual void unkB0();
    virtual void unkB4();
    virtual void unkB8();
    virtual void unkBC();
    virtual void unkC0();
    virtual void unkC4();
    virtual void unkC8();
    virtual void unkCC();
    virtual void unkD0();
    virtual void unkD4();
    virtual void unkD8();
    virtual void unkDC();
    virtual void unkE0();
    virtual void unkE4();
    virtual void Remove(CombatOwner*);
};
struct CombatOwner
{
    CombatOwnerManager* FUN_009611e0();
};
struct CombatOwnerPtr
{
    CombatOwner* object;
    operator CombatOwner*() const;
    CombatOwner* operator->() const;
    ~CombatOwnerPtr();
};
struct FUN_009a45e0
{
    int unk00, unk04, unk08, unk0C, unk10;
    CombatOwnerPtr owner;
    ~FUN_009a45e0();
};
// Destructor that, if the held owner and its manager exist, removes the owner from that manager.
// @fnv 0x009a45e0
FUN_009a45e0::~FUN_009a45e0()
{
    if (owner && owner->FUN_009611e0())
        owner->FUN_009611e0()->Remove(owner);
}

extern float __cdecl FUN_00435dd0();

struct TimestampStruct
{
    int m_uiCommandId;
};

struct FUN_00435de0_ctor : public TimestampStruct
{
    void* FUN_00435de0(float afValue);
};

struct FUN_009a4690_shell
{
    int m0;
    float m4;
    TimestampStruct m8;
    TimestampStruct mc;
    float m10;

    void FUN_009a4690(int a1, float a2, float a3, float a4, float a5, bool a6);
};

// @fnv 0x009a4690
void FUN_009a4690_shell::FUN_009a4690(int a1, float a2, float afFirstOffset, float afSecondOffset, float a5,
                                      bool abSkipFirst)
{
    FUN_00435de0_ctor t2;
    FUN_00435de0_ctor t7;
    m0 = a1;
    m4 = a2;
    if (!abSkipFirst)
    {
        t7.FUN_00435de0(FUN_00435dd0() + afFirstOffset);
        m8 = t7;
    }
    t2.FUN_00435de0(FUN_00435dd0() + afSecondOffset);
    mc = t2;
    m10 = a5;
}

extern double DAT_01011590;

struct S_009a49b0_VTableObject
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual int vfn_08(int value);
};

struct S_009a49b0_Arg
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4c;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5c;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6c;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7c;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8c;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9c;
    void* unk_a0;
    S_009a49b0_VTableObject unk_a4;
};

struct S_009a49b0_Class
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    float unk10;

    float __thiscall ComputeScaledRatio(S_009a49b0_Arg* arg, float value);
};

// Divides unk10 times DAT_01011590 by the vtable result of arg (or value when arg is null) and returns the quotient.
// @fnv 0x009a49b0
float S_009a49b0_Class::ComputeScaledRatio(S_009a49b0_Arg* arg, float value)
{
    float divisor = arg ? arg->unk_a4.vfn_08(0x10) : value;

    return unk10 * DAT_01011590 / divisor;
}

struct Point9a
{
    float x, y, z;
    float FUN_00457910();
    Point9a operator*(float) const;
    Point9a operator+(const Point9a&) const;
    Point9a& operator+=(const Point9a&);
};
struct Source9a
{
    virtual void unk000();
    virtual void unk004();
    virtual void unk008();
    virtual void unk00c();
    virtual void unk010();
    virtual void unk014();
    virtual void unk018();
    virtual void unk01c();
    virtual void unk020();
    virtual void unk024();
    virtual void unk028();
    virtual void unk02c();
    virtual void unk030();
    virtual void unk034();
    virtual void unk038();
    virtual void unk03c();
    virtual void unk040();
    virtual void unk044();
    virtual void unk048();
    virtual void unk04c();
    virtual void unk050();
    virtual void unk054();
    virtual void unk058();
    virtual void unk05c();
    virtual void unk060();
    virtual void unk064();
    virtual void unk068();
    virtual void unk06c();
    virtual void unk070();
    virtual void unk074();
    virtual void unk078();
    virtual void unk07c();
    virtual void unk080();
    virtual void unk084();
    virtual void unk088();
    virtual void unk08c();
    virtual void unk090();
    virtual void unk094();
    virtual void unk098();
    virtual void unk09c();
    virtual void unk0a0();
    virtual void unk0a4();
    virtual void unk0a8();
    virtual void unk0ac();
    virtual void unk0b0();
    virtual void unk0b4();
    virtual void unk0b8();
    virtual void unk0bc();
    virtual void unk0c0();
    virtual void unk0c4();
    virtual void unk0c8();
    virtual void unk0cc();
    virtual void unk0d0();
    virtual void unk0d4();
    virtual void unk0d8();
    virtual void unk0dc();
    virtual void unk0e0();
    virtual void unk0e4();
    virtual void unk0e8();
    virtual void unk0ec();
    virtual void unk0f0();
    virtual void unk0f4();
    virtual void unk0f8();
    virtual void unk0fc();
    virtual void unk100();
    virtual void unk104();
    virtual void unk108();
    virtual void unk10c();
    virtual void unk110();
    virtual void unk114();
    virtual void unk118();
    virtual void unk11c();
    virtual void unk120();
    virtual void unk124();
    virtual void unk128();
    virtual void unk12c();
    virtual void unk130();
    virtual void unk134();
    virtual void unk138();
    virtual void unk13c();
    virtual void unk140();
    virtual void unk144();
    virtual void unk148();
    virtual void unk14c();
    virtual void unk150();
    virtual void unk154();
    virtual void unk158();
    virtual void unk15c();
    virtual void unk160();
    virtual void unk164();
    virtual void unk168();
    virtual void unk16c();
    virtual void unk170();
    virtual void unk174();
    virtual void unk178();
    virtual void unk17c();
    virtual void unk180();
    virtual void unk184();
    virtual void unk188();
    virtual void unk18c();
    virtual void unk190();
    virtual void unk194();
    virtual void unk198();
    virtual void unk19c();
    virtual void unk1a0();
    virtual void unk1a4();
    virtual void unk1a8();
    virtual void unk1ac();
    virtual void unk1b0();
    virtual void unk1b4();
    virtual void unk1b8();
    virtual void unk1bc();
    virtual void unk1c0();
    virtual void unk1c4();
    virtual void unk1c8();
    virtual void unk1cc();
    virtual void unk1d0();
    virtual void unk1d4();
    virtual void unk1d8();
    virtual void unk1dc();
    virtual void unk1e0();
    virtual void unk1e4();
    virtual void unk1e8();
    virtual void unk1ec();
    virtual void unk1f0();
    virtual const Point9a& Position();
};
struct Setting9a
{
    float* Float();
};
extern Setting9a DAT_011cf48c, DAT_011cef98, DAT_011ce990;
float FUN_00404010(float, float);
struct Context9a;
struct Result9a
{
    Result9a(const Point9a&, float, float);
    Result9a(const Point9a&, const Point9a&, float, float);
};
struct Target9a
{
    Source9a* source;
    float radius;
    void FUN_009a4a10(Point9a&);
    float ComputeScaledRatio(Context9a*, float);
    Result9a FUN_009a4c70(Context9a*);
};
// Computes a point from FUN_009a4a10 and the source position, then returns a Result9a built from the radius, ComputeScaledRatio and the setting floats.
// @fnv 0x009a4c70
Result9a Target9a::FUN_009a4c70(Context9a* context)
{
    Point9a h;
    FUN_009a4a10(h);
    float s = radius * *DAT_011cf48c.Float();
    float i = ComputeScaledRatio(context, 0.0f);
    float p = h.FUN_00457910();
    Point9a a = source->Position() + h * p * 0.5f;
    if (p < s)
    {
        return Result9a(a, radius, i * *DAT_011cef98.Float());
    }
    else
    {
        float f = h.FUN_00457910();
        float eb = 0.0f;
        eb = FUN_00404010(eb, 0.0f);
        a += h * (f * eb - radius);
        Point9a cf = a + h * (2.0 * radius + (*DAT_011ce990.Float() - eb) * f);
        return Result9a(a, cf, radius, i * *DAT_011cef98.Float());
    }
}

struct FUN_009a4e30_vec3
{
    int m_00;
    int m_04;
    int m_08;
};

class FUN_009a4e30_cls
{
  public:
    FUN_009a4e30_vec3 m_00;
    FUN_009a4e30_vec3 m_0c;
    float m_18;
    float m_1c;
    int m_20;

    FUN_009a4e30_cls* FUN_009a4e30(FUN_009a4e30_vec3* a1, FUN_009a4e30_vec3* a2, float a3, float a4);
};

// Copies two vec3 values and two floats into the object, sets m_20 to 1, and returns this.
// @fnv 0x009a4e30
FUN_009a4e30_cls* FUN_009a4e30_cls::FUN_009a4e30(FUN_009a4e30_vec3* pVecA, FUN_009a4e30_vec3* pVecB, float fValueA,
                                                 float fValueB)
{
    m_00 = *pVecA;
    m_0c = *pVecB;
    m_18 = fValueA;
    m_1c = fValueB;
    m_20 = 1;
    return this;
}

class ThisBase_b4986
{
  public:
    virtual ~ThisBase_b4986();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    ThisBase_b4986(int aValue);
};

class ThisMember_b4986
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    ThisMember_b4986();
    ~ThisMember_b4986();
};

class FUN_009a4fb0 : public ThisBase_b4986
{
  public:
    virtual ~FUN_009a4fb0();
    ThisMember_b4986 m_10;

    FUN_009a4fb0();
};

// Constructs the object, initializing the base with 0x25 and default-constructing the m_10 member.
// @fnv 0x009a4fb0
FUN_009a4fb0::FUN_009a4fb0() : ThisBase_b4986(0x25), m_10()
{}

struct S_9a54a0_Setting
{
    int unk00;
    float unk04;
    float* FUN_00403e20();
};
extern S_9a54a0_Setting DAT_011cf3f0;
struct S_9a54a0_Actor
{
    float FUN_006a78f0();
    float FUN_00477900();
};
float __cdecl ComputeExplosionDamageFalloff(float a, float b, float c);
struct S_9a54a0_Class
{
    void AddOrUpdateItem(int a, float b, float c, float d, float e);
    void FUN_009a54a0(int a1, S_9a54a0_Actor* a2, float a3);
};
// @fnv 0x009a54a0
void S_9a54a0_Class::FUN_009a54a0(int a1, S_9a54a0_Actor* pActor, float a3)
{
    float cur = pActor->FUN_006a78f0();
    if (cur >= *DAT_011cf3f0.FUN_00403e20())
    {
        float f = pActor->FUN_00477900();
        f = ComputeExplosionDamageFalloff(f, cur, *DAT_011cf3f0.FUN_00403e20());
        AddOrUpdateItem(a1, f, 0.0f, a3, cur);
    }
}

// FUN_009a5780 : thiscall getter that copies the int member at +0x08
// through an out-pointer argument and returns that out-pointer.
struct FUN_009a5780_val
{
    int v;
};

struct FUN_009a5780_cls
{
    void* vfn_00;
    int pad_04;
    FUN_009a5780_val m_08;
    FUN_009a5780_val* __thiscall FUN_009a5780(FUN_009a5780_val* out);
};

// @fnv 0x009a5780
FUN_009a5780_val* FUN_009a5780_cls::FUN_009a5780(FUN_009a5780_val* out)
{
    *out = m_08;
    return out;
}

struct DtorBaseP
{
    virtual ~DtorBaseP();
};
struct DtorBaseE
{
    void Release();
};
struct FUN_009a5df0_cls : DtorBaseP
{
    virtual ~FUN_009a5df0_cls();
};
// @fnv 0x009a5df0
FUN_009a5df0_cls::~FUN_009a5df0_cls()
{
    ((DtorBaseE*)this)->Release();
}

extern char DAT_0104e1dc;
struct FUN_0062a220
{
    void* vtable;
    FUN_0062a220();
    ~FUN_0062a220();
    void SetFilter(unsigned int first, unsigned int second);
};
struct FUN_008c71b0_Class
{
    void FUN_008c71b0(int value);
};
struct FUN_009a7bc0 : FUN_0062a220
{
    FUN_009a7bc0(unsigned int first, unsigned int second);
};
// Sets the vtable, initialises the object at offset 0x70 with 0, then calls SetFilter with first and second.
// @fnv 0x009a7bc0
FUN_009a7bc0::FUN_009a7bc0(unsigned int first, unsigned int second)
{
    vtable = &DAT_0104e1dc;
    reinterpret_cast<FUN_008c71b0_Class*>(reinterpret_cast<char*>(this) + 0x70)->FUN_008c71b0(0);
    SetFilter(first, second);
}

struct Vec3Arg
{
    float x;
    float y;
    float z;
    float FUN_00457990();
};

struct SceneRef
{
    float FUN_009669c0();
    void* FUN_004181e0();
};

struct SceneOwner
{
    float FUN_00966980();
};

void ComputeLaunchAngle(float a, float b, float c, float d, unsigned char e);

extern float DAT_011f1c00;

// Zeroes the vector's z, measures its length, defaults p18 to a1's value, scales a1's owner value by DAT_011f1c00, and passes all to ComputeLaunchAngle.
// @fnv 0x009a7d50
void FUN_009a7d50(SceneRef* pSceneRef, Vec3Arg vecArg, float fParam, unsigned char p1c)
{
    float len;
    float fSavedZ = vecArg.z;
    vecArg.z = 0.0f;
    len = vecArg.FUN_00457990();
    if (fParam == 0.0)
    {
        fParam = pSceneRef->FUN_009669c0();
    }
    float scaled = reinterpret_cast<SceneOwner*>(pSceneRef->FUN_004181e0())->FUN_00966980() * DAT_011f1c00;
    ComputeLaunchAngle(len, fSavedZ, fParam, scaled, p1c);
}

struct Triple12
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
};

struct ObjCallees
{
    void* Lookup();
    void Apply(void* pOut);
};

typedef unsigned char(__thiscall* VCheckFn)(void*);

extern unsigned int DAT_011f426c;
extern unsigned int DAT_011f4270;
extern unsigned int DAT_011f4274;

// Builds a Triple12 from three globals, optionally lets a1's lookup result apply changes to it, and stores it in pOut.
// @fnv 0x009a8660
Triple12* GetTriple12(Triple12* pResult, void* pObject)
{
    Triple12 result;
    result.m_00 = DAT_011f426c;
    result.m_04 = DAT_011f4270;
    result.m_08 = DAT_011f4274;

    if (((VCheckFn)(*(void***)pObject)[64])(pObject) != 0)
    {
        ObjCallees* obj = (ObjCallees*)pObject;
        ObjCallees* p = (ObjCallees*)obj->Lookup();
        if (p != 0)
        {
            p->Apply(&result);
        }
    }

    *pResult = result;
    return pResult;
}

// GetKeywordName (0x009aa120, 23 bytes, /MT /Od /Oy- /GS /EHsc /Gy)
//
// The original is a tiny thiscall accessor on a keyword/flag holder object:
//
//   mov eax, [ebp-4]          ; the spilled 'this'
//   mov ecx, [eax]            ; this->m_uiEdgeIndex  (first dword of the object)
//   mov eax, [ecx*8 + table]  ; table[m_uiEdgeIndex].m_name  (8-byte entries)
//
// records (the script keyword names), and the accessor hands back the name
// pointer of the record selected by the index stored in the object.

struct ScriptKeywordEntry
{
    const char* m_name;
    int m_uiFilterValue;
};

// The keyword table lives in the game's data segment.
extern ScriptKeywordEntry g_scriptKeywords[];

struct FUN_009aa120_cls
{
    int m_uiEdgeIndex;
    const char* GetKeywordName();
};

// @fnv 0x009aa120
const char* FUN_009aa120_cls::GetKeywordName()
{
    return g_scriptKeywords[m_uiEdgeIndex].m_name;
}

struct UnsignedIdHandle
{
    int FUN_00559450();
    unsigned int FUN_00726070();
};
struct WorldStateNode
{
    UnsignedIdHandle*& FUN_006815c0();
    WorldStateNode* FUN_0062d990();
    bool FindStateByType(int type, unsigned int* output);
};
// Walks the node chain, and for the first state whose FUN_00559450 equals type, stores its FUN_00726070 result in output and returns true; otherwise false.
// @fnv 0x009aa410
bool WorldStateNode::FindStateByType(int type, unsigned int* puiOutput)
{
    WorldStateNode* current = this;
    while (current != 0)
    {
        UnsignedIdHandle* state = current->FUN_006815c0();
        if (state != 0 && state->FUN_00559450() == type)
        {
            *puiOutput = state->FUN_00726070();
            return true;
        }
        current = current->FUN_0062d990();
    }
    return false;
}

struct FUN_009aadc0_cls
{
    unsigned char FUN_009aadc0(int a, unsigned int b);
};

// Checks DAT_011a55b4 for entry a: if set, tests bit b of FUN_005bd5c0(a); otherwise compares FUN_005bd5c0(a) to b.
// @fnv 0x009aadc0
unsigned char FUN_009aadc0_cls::FUN_009aadc0(int aiIndex, unsigned int auiBit)
{
    if (DAT_011a55b4[aiIndex * 8] != 0)
    {
        return (reinterpret_cast<DummyFontManager*>(this)->FUN_005bd5c0(aiIndex) & (1u << auiBit)) != 0;
    }
    return (reinterpret_cast<DummyFontManager*>(this)->FUN_005bd5c0(aiIndex) == (int)auiBit) ? 1 : 0;
}

class NiPoint39AB
{
  public:
    float x;
    float y;
    float z;
};

class TESObjectREFR9AB;

class PathingSolution9AB;

template <class T> class PathingRef9AB
{
  public:
    PathingRef9AB(T* pObject = 0);
    ~PathingRef9AB();
    void Reset(T* pObject);

    T* m_pObject;
};

class TESForm9AB
{
  public:
    virtual ~TESForm9AB();
    void SetFormType(int eType);

    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
};

class BaseExtra9AB
{
  public:
    virtual ~BaseExtra9AB();
};

class Base9AB : public TESForm9AB, public BaseExtra9AB
{
  public:
    Base9AB(int iA, int iB, int iC, NiPoint39AB kPos, float fA, float fB);
    virtual ~Base9AB();

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
};

class FUN_009ab090 : public Base9AB
{
  public:
    FUN_009ab090(int iA, int iB, int iC, NiPoint39AB kPos, float fA, float fB);
    virtual ~FUN_009ab090();

    PathingRef9AB<PathingSolution9AB> m_spSolution;
};

// Constructs the object via Base9AB, sets its form type to 0x69, and resets m_spSolution to null.
// @fnv 0x009ab090
FUN_009ab090::FUN_009ab090(int iA, int iB, int iC, NiPoint39AB kPos, float fA, float fB)
    : Base9AB(iA, iB, iC, kPos, fA, fB)
{
    SetFormType(0x69);
    m_spSolution.Reset(0);
}

// FUN_009ac9a0: /MT /Od thiscall member (this in ecx, no stack args).
// The body only forwards to a virtual of the same object: the vtable slot at
// offset 0xc4 (index 49) is called with the constant 1 as its single argument.
//   push 1
//   mov eax, [ebp-4]      ; this (spilled by the /Od prologue)
//   mov edx, [eax]        ; vtable
//   mov ecx, [ebp-4]      ; this for the virtual call
//   mov eax, [edx+0xc4]   ; slot 49
//   call eax
class FUN_009ac9a0_cls
{
  public:
    virtual void vf000();
    virtual void vf001();
    virtual void vf002();
    virtual void vf003();
    virtual void vf004();
    virtual void vf005();
    virtual void vf006();
    virtual void vf007();
    virtual void vf008();
    virtual void vf009();
    virtual void vf010();
    virtual void vf011();
    virtual void vf012();
    virtual void vf013();
    virtual void vf014();
    virtual void vf015();
    virtual void vf016();
    virtual void vf017();
    virtual void vf018();
    virtual void vf019();
    virtual void vf020();
    virtual void vf021();
    virtual void vf022();
    virtual void vf023();
    virtual void vf024();
    virtual void vf025();
    virtual void vf026();
    virtual void vf027();
    virtual void vf028();
    virtual void vf029();
    virtual void vf030();
    virtual void vf031();
    virtual void vf032();
    virtual void vf033();
    virtual void vf034();
    virtual void vf035();
    virtual void vf036();
    virtual void vf037();
    virtual void vf038();
    virtual void vf039();
    virtual void vf040();
    virtual void vf041();
    virtual void vf042();
    virtual void vf043();
    virtual void vf044();
    virtual void vf045();
    virtual void vf046();
    virtual void vf047();
    virtual void vf048();
    virtual void vf049(int a);
    void FUN_009ac9a0();
};

// @fnv 0x009ac9a0
void FUN_009ac9a0_cls::FUN_009ac9a0()
{
    vf049(1);
}

class TESForm
{
  public:
    virtual ~TESForm();
};
class TESImageSpaceModifier : public TESForm
{
  public:
    virtual ~TESImageSpaceModifier();
};
extern TESImageSpaceModifier* DAT_011c9708;
TESForm* __cdecl LookupFormByID(unsigned int);
// Returns the cached TESImageSpaceModifier, looking it up by form ID 0x166 via LookupFormByID if not yet set.
// @fnv 0x009ad630
TESImageSpaceModifier* __cdecl FUN_009ad630()
{
    if (DAT_011c9708 == 0)
    {
        DAT_011c9708 = dynamic_cast<TESImageSpaceModifier*>(LookupFormByID(0x166));
    }
    return DAT_011c9708;
}

template <> class SettingT<GameSettingCollection>
{
  public:
    float& Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting505;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting506;
extern double _gModifierZero;

float __cdecl FUN_006479e0(void* base);

struct FUN_009b0f80_ValueOwner
{
    virtual void vf_00();
    virtual void vf_04();
    virtual void vf_08();
    virtual float GetValue(int key);
};

struct FUN_009b0f80_Item
{
    virtual void vf_000();
    virtual void vf_004();
    virtual void vf_008();
    virtual void vf_00c();
    virtual void vf_010();
    virtual void vf_014();
    virtual void vf_018();
    virtual void vf_01c();
    virtual void vf_020();
    virtual void vf_024();
    virtual void vf_028();
    virtual void vf_02c();
    virtual void vf_030();
    virtual void vf_034();
    virtual void vf_038();
    virtual void vf_03c();
    virtual void vf_040();
    virtual void vf_044();
    virtual void vf_048();
    virtual void vf_04c();
    virtual void vf_050();
    virtual void vf_054();
    virtual void vf_058();
    virtual void vf_05c();
    virtual void vf_060();
    virtual void vf_064();
    virtual void vf_068();
    virtual void vf_06c();
    virtual void vf_070();
    virtual void vf_074();
    virtual void vf_078();
    virtual void vf_07c();
    virtual void vf_080();
    virtual void vf_084();
    virtual void vf_088();
    virtual void vf_08c();
    virtual void vf_090();
    virtual void vf_094();
    virtual void vf_098();
    virtual void vf_09c();
    virtual void vf_0a0();
    virtual void vf_0a4();
    virtual void vf_0a8();
    virtual void vf_0ac();
    virtual void vf_0b0();
    virtual void vf_0b4();
    virtual void vf_0b8();
    virtual void vf_0bc();
    virtual void vf_0c0();
    virtual void vf_0c4();
    virtual void vf_0c8();
    virtual void vf_0cc();
    virtual void vf_0d0();
    virtual void vf_0d4();
    virtual void vf_0d8();
    virtual void vf_0dc();
    virtual void vf_0e0();
    virtual void vf_0e4();
    virtual void vf_0e8();
    virtual void vf_0ec();
    virtual void vf_0f0();
    virtual void vf_0f4();
    virtual void vf_0f8();
    virtual void vf_0fc();
    virtual bool vf_100();
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
    FUN_009b0f80_ValueOwner owner;
};

struct FUN_009b0f80_Skill
{
    int GetUnk15C();
};
struct FUN_009b0f80_Skill_Holder
{
};

struct FUN_009b0f80_Actor
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c,
        unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc,
        unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    float value100;
    void* GetActorBase();
    FUN_009b0f80_Item* GetFieldC8();
    FUN_009b0f80_Skill* GetFieldE0();
    float GetCachedValue();
};

// Returns value100 if non-negative; otherwise recomputes it from the actor base and scales it by two runtime float settings when an item and skill are present.
// @fnv 0x009b0f80
float FUN_009b0f80_Actor::GetCachedValue()
{
    if (value100 >= _gModifierZero)
    {
        return value100;
    }
    value100 = FUN_006479e0(GetActorBase());
    if (GetFieldC8() && GetFieldC8()->vf_100() && GetFieldE0())
    {
        FUN_009b0f80_Item* item = GetFieldC8();
        float skill = item->owner.GetValue(GetFieldE0()->GetUnk15C());
        float mult9 = originalRuntimeFloatSetting505.Float() + originalRuntimeFloatSetting506.Float() * (skill * 0.01f);
        value100 = value100 * mult9;
    }
    return value100;
}

struct SoundForm
{
    unsigned int GetFormID();
};
struct ActorBaseX
{
    SoundForm* GetBoltSound();
    SoundForm* FUN_009185e0();
};
struct SoundHandleX
{
    int unk00;
    int unk04;
    int unk08;
    ~SoundHandleX();
    SoundHandleX& operator=(const SoundHandleX& other);
};
struct ActorX
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
    SoundHandleX soundAC;
    SoundHandleX soundB8;
    void FUN_009b11c0();
    ActorBaseX* GetActorBase();
    SoundHandleX PlaySoundByFormID(unsigned int formID, int a, unsigned int flags, int b);
    void FUN_009b1090();
};

// Calls FUN_009b11c0, then assigns sound handles from the actor base's bolt sound and FUN_009185e0 sound form IDs via PlaySoundByFormID.
// @fnv 0x009b1090
void ActorX::FUN_009b1090()
{
    FUN_009b11c0();
    if (GetActorBase()->GetBoltSound())
    {
        unsigned int boltSoundFormID = GetActorBase()->GetBoltSound()->GetFormID();
        soundAC = PlaySoundByFormID(boltSoundFormID, 0, 0x40000182, 1);
    }
    if (GetActorBase()->FUN_009185e0())
    {
        unsigned int secondSoundFormID = GetActorBase()->FUN_009185e0()->GetFormID();
        soundB8 = PlaySoundByFormID(secondSoundFormID, 0, 0x40000182, 1);
    }
}

struct S_009b13a0_A
{
    float FUN_008d01e0();
    float GetFloatAtOffset9C();
};
struct S_009b13a0_B
{
    void SetRadiation(float f);
};
extern float DAT_01013ea4;
struct S_009b13a0_Cls
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48(int f);
    S_009b13a0_A* FUN_004181e0();
    float FUN_0051b8e0();
    S_009b13a0_B* FUN_005d43c0();
    void FUN_009b13a0();
};
// @fnv 0x009b13a0
void S_009b13a0_Cls::FUN_009b13a0()
{
    float a = FUN_004181e0()->FUN_008d01e0();
    float b5 = FUN_004181e0()->GetFloatAtOffset9C();
    if (a > 0.0 && b5 > 0.0)
    {
        a = (1.0f - FUN_0051b8e0() / b5) * a;
        if (a <= 0.0)
            a = DAT_01013ea4;
        FUN_005d43c0()->SetRadiation(a);
        vfn_48(0x40000000);
    }
}

struct FUN_005609f0_shell
{
    FUN_005609f0_shell();
    bool FUN_005609f0();
    char m_cValue;
};

void __fastcall FUN_00626870(void* p);
void __cdecl FUN_005e0b60(void* p);

class B2D30Base
{
  public:
    ~B2D30Base();
    int unk00;
    int unk04;
    int unk08;
};

class FUN_009b2d30 : public B2D30Base
{
  public:
    ~FUN_009b2d30();
    FUN_005609f0_shell GetState();
    void* m_pData;
};

// @fnv 0x009b2d30
FUN_009b2d30::~FUN_009b2d30()
{
    if (!GetState().FUN_005609f0())
        FUN_00626870(this);
    FUN_005e0b60(m_pData);
}

class FUN_009b2e30_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void Callee0062e230(void* p, int a, int b);
    FUN_009b2e30_cls* FUN_009b2e30(int a);
};

// Calls Callee0062e230 on the member at offset 0x0c with a and 0x80, then returns this.
// @fnv 0x009b2e30
FUN_009b2e30_cls* FUN_009b2e30_cls::FUN_009b2e30(int a)
{
    Callee0062e230(&unk0c, a, 0x80);
    return this;
}

struct S_9b3080_Bool
{
    char c;
    bool FUN_005609f0();
};
struct S_9b3080_A
{
    S_9b3080_Bool* SetFlagFromComparison(S_9b3080_Bool* out, S_9b3080_A* other);
};
struct S_9b3080_Class
{
    int CompareBool(S_9b3080_A* a, S_9b3080_A* b);
};
// Calls SetFlagFromComparison on a with b into a local S_9b3080_Bool and returns the result of FUN_005609f0 on it.
// @fnv 0x009b3080
int S_9b3080_Class::CompareBool(S_9b3080_A* apLeft, S_9b3080_A* apRight)
{
    S_9b3080_Bool r;
    return apLeft->SetFlagFromComparison(&r, apRight)->FUN_005609f0();
}

class FUN_009b30b0_cls
{
  public:
    int unk00;

    double GetValue();
    void SetFlag(bool flag);

    FUN_009b30b0_cls* SetFlagFromComparison(FUN_009b30b0_cls* sink, FUN_009b30b0_cls* other);
};

// Sets sink's flag to whether this object's value is less than other's value, then returns sink.
// @fnv 0x009b30b0
FUN_009b30b0_cls* FUN_009b30b0_cls::SetFlagFromComparison(FUN_009b30b0_cls* sink, FUN_009b30b0_cls* other)
{
    sink->SetFlag((GetValue() < other->GetValue()) ? true : false);
    return sink;
}

struct WeapStub;
struct ProcStub
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F();
    virtual void v50();
    virtual void v51();
    virtual void* GetThing();
};
struct FactorStub
{
    float GetFactor(bool b);
};
struct ItemStub
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
    virtual bool IsOk();
    WeapStub* GetWeap();
    ProcStub* GetProc();
};
struct ActorStub
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F();
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
    virtual void v5A();
    virtual void v5B();
    virtual void v5C();
    virtual void v5D();
    virtual void v5E();
    virtual void v5F();
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
    virtual void v6A();
    virtual void v6B();
    virtual void v6C();
    virtual void v6D();
    virtual void v6E();
    virtual void v6F();
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
    virtual void v7A();
    virtual void v7B();
    virtual void v7C();
    virtual void v7D();
    virtual void v7E();
    virtual void v7F();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual bool IsActorX();
    unsigned int GetWeapRef();
    ItemStub* GetItem();
};
struct CombatThing
{
    void SetFlagX(unsigned int flag, bool on);
    void Update1(int a);
    void Update2();
    void Update3();
    int unk00;
    int unk04;
    ActorStub* unk08;
    int unk0C;
    int unk10;
    float unk14;
    float unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    unsigned int unk30;
    float unk34;
};

// Initializes a CombatThing with two ints, an actor and a float, sets flag 0x2000, derives unk30/unk34 from the actor's weapon, then runs Update1/2/3.
// @fnv 0x009b5770
void InitCombatThing(CombatThing* thing, int iValueA, int iValueB, ActorStub* actor, float fValue)
{
    if (thing == 0)
        return;
    thing->unk00 = iValueA;
    thing->unk04 = iValueB;
    thing->SetFlagX(0x2000, true);
    if (actor && actor->IsActorX())
    {
        ActorStub* pActor = actor;
        thing->unk30 = pActor->GetWeapRef();
        thing->unk34 = 1.0f;
        if (pActor->GetItem() && pActor->GetItem()->IsOk())
        {
            ItemStub* item = pActor->GetItem();
            if ((unsigned int)item->GetWeap() == thing->unk30)
            {
                FactorStub* pFactor = item->GetProc() ? (FactorStub*)item->GetProc()->GetThing() : 0;
                thing->unk34 = pFactor ? pFactor->GetFactor(true) : 1.0f;
            }
        }
    }
    thing->unk08 = actor;
    thing->unk14 = fValue;
    thing->unk18 = thing->unk14;
    thing->Update1(1);
    thing->Update2();
    thing->Update3();
}

struct FUN_009b79d0_stand_in
{
    void FUN_009962f0(void* p);
    void FUN_009b79d0(int value);
};

// @fnv 0x009b79d0
void FUN_009b79d0_stand_in::FUN_009b79d0(int value)
{
    FUN_009962f0(&value);
}

struct PUpdateData
{
    float fTime;
    bool bFlag1;
    bool bFlag2;
    int iUnk08;
    PUpdateData(float t, bool a, bool b);
};
struct PPoint3
{
    float x, y, z;
    PPoint3();
    PPoint3& operator*=(float f);
};
struct PTransformHolder
{
    void GetTranslate(unsigned int idx, PPoint3& out);
};
struct PNode
{
    virtual void vf_00();
    virtual void vn_4();
    virtual void vn_8();
    virtual void vn_c();
    virtual void vn_10();
    virtual void vn_14();
    virtual void vn_18();
    virtual void vn_1c();
    virtual void vn_20();
    virtual void vn_24();
    virtual void vn_28();
    virtual void vn_2c();
    virtual void vn_30();
    virtual void vn_34();
    virtual void vn_38();
    virtual void vn_3c();
    virtual void vn_40();
    virtual void vn_44();
    virtual void vn_48();
    virtual void vn_4c();
    virtual void vn_50();
    virtual void vn_54();
    virtual void vn_58();
    virtual void vn_5c();
    virtual void vn_60();
    virtual void vn_64();
    virtual void vn_68();
    virtual void vn_6c();
    virtual void vn_70();
    virtual void vn_74();
    virtual void vn_78();
    virtual void vn_7c();
    virtual void vn_80();
    virtual void vn_84();
    virtual void vn_88();
    virtual void vn_8c();
    virtual void vn_90();
    virtual void vn_94();
    virtual void vn_98();
    virtual void vn_9c();
    virtual void vn_a0();
    virtual void vn_a4();
    virtual void vn_a8();
    virtual void vn_ac();
    virtual void vn_b0();
    virtual void vn_b4();
    virtual void Update(PUpdateData& data);
    PTransformHolder* GetHolder();
};
struct PDataHandler
{
    bool CheckForm(unsigned int id);
};
extern PDataHandler* g_dataHandler;
void __cdecl SetNodeFlags(PNode* node, int a, int b, int c);
void __cdecl PlaceNode(PNode* node, PPoint3* pt, int c);
struct PRef
{
    virtual void vf_0();
    virtual void vf_4();
    virtual void vf_8();
    virtual void vf_c();
    virtual void vf_10();
    virtual void vf_14();
    virtual void vf_18();
    virtual void vf_1c();
    virtual void vf_20();
    virtual void vf_24();
    virtual void vf_28();
    virtual void vf_2c();
    virtual void vf_30();
    virtual void vf_34();
    virtual void vf_38();
    virtual void vf_3c();
    virtual void vf_40();
    virtual void vf_44();
    virtual void SetFlagV(int a);
    virtual void vf_4c();
    virtual void vf_50();
    virtual void vf_54();
    virtual void vf_58();
    virtual void vf_5c();
    virtual void vf_60();
    virtual void vf_64();
    virtual void vf_68();
    virtual void vf_6c();
    virtual void vf_70();
    virtual void vf_74();
    virtual void vf_78();
    virtual void vf_7c();
    virtual void vf_80();
    virtual void vf_84();
    virtual void vf_88();
    virtual void vf_8c();
    virtual void vf_90();
    virtual void vf_94();
    virtual void vf_98();
    virtual void vf_9c();
    virtual void vf_a0();
    virtual void vf_a4();
    virtual void vf_a8();
    virtual void vf_ac();
    virtual void vf_b0();
    virtual void vf_b4();
    virtual void vf_b8();
    virtual void vf_bc();
    virtual void vf_c0();
    virtual void vf_c4();
    virtual void vf_c8();
    virtual void vf_cc();
    virtual void vf_d0();
    virtual void vf_d4();
    virtual void vf_d8();
    virtual void vf_dc();
    virtual void vf_e0();
    virtual void vf_e4();
    virtual void vf_e8();
    virtual void vf_ec();
    virtual void vf_f0();
    virtual void vf_f4();
    virtual void vf_f8();
    virtual void vf_fc();
    virtual void vf_100();
    virtual void vf_104();
    virtual void vf_108();
    virtual void vf_10c();
    virtual void vf_110();
    virtual void vf_114();
    virtual void vf_118();
    virtual void vf_11c();
    virtual void vf_120();
    virtual void vf_124();
    virtual void vf_128();
    virtual void vf_12c();
    virtual void vf_130();
    virtual void vf_134();
    virtual void vf_138();
    virtual void vf_13c();
    virtual void vf_140();
    virtual void vf_144();
    virtual void vf_148();
    virtual void vf_14c();
    virtual void vf_150();
    virtual void vf_154();
    virtual void vf_158();
    virtual void vf_15c();
    virtual void vf_160();
    virtual void vf_164();
    virtual void vf_168();
    virtual void vf_16c();
    virtual void vf_170();
    virtual void vf_174();
    virtual void vf_178();
    virtual void vf_17c();
    virtual void vf_180();
    virtual void vf_184();
    virtual void vf_188();
    virtual void vf_18c();
    virtual void vf_190();
    virtual void vf_194();
    virtual void vf_198();
    virtual void vf_19c();
    virtual void vf_1a0();
    virtual void vf_1a4();
    virtual void vf_1a8();
    virtual void vf_1ac();
    virtual void vf_1b0();
    virtual void vf_1b4();
    virtual void vf_1b8();
    virtual void vf_1bc();
    virtual void vf_1c0();
    virtual void vf_1c4();
    virtual void vf_1c8();
    virtual void vf_1cc();
    virtual PNode* GetNode3D();
    bool IsFlagSet(int flag);
    unsigned int GetFormID();
    float GetScale();
    void UpdateNodePlacement();
};

// If flag 8 is clear, flag 4 set and the form valid, updates the 3D node, scales its translation and places it, then sets flag 4.
// @fnv 0x009beb00
void PRef::UpdateNodePlacement()
{
    if (!IsFlagSet(8) && IsFlagSet(4) && g_dataHandler->CheckForm(GetFormID()))
    {
        PNode* node7 = GetNode3D();
        if (node7)
        {
            SetNodeFlags(node7, 0, 1, 1);
            PUpdateData updateData3(0.0f, false, false);
            node7->Update(updateData3);
            SetNodeFlags(node7, 1, 1, 1);
            PPoint3 pt;
            node7->GetHolder()->GetTranslate(1, pt);
            pt *= GetScale();
            PlaceNode(node7, &pt, 1);
            SetFlagV(4);
        }
    }
}

class GameObject
{
  public:
    void** vtable;
    bool __thiscall FUN_00444d00(unsigned int flags);
    void __thiscall FUN_009bec10(float value);
};

typedef void(__thiscall* VirtualCall)(GameObject*, float);

// @fnv 0x009bec10
void __thiscall GameObject::FUN_009bec10(float value)
{
    if (!FUN_00444d00(0x80))
    {
        ((VirtualCall)(vtable[190]))(this, value);
    }
}

struct FUN_009bec50_v00
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
};

struct FUN_009bec50_v01 : public FUN_009bec50_v00
{
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
};

struct FUN_009bec50_v02 : public FUN_009bec50_v01
{
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
};

struct FUN_009bec50_v03 : public FUN_009bec50_v02
{
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
};

struct FUN_009bec50_v04 : public FUN_009bec50_v03
{
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
};

struct FUN_009bec50_v05 : public FUN_009bec50_v04
{
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
};

struct FUN_009bec50_v06 : public FUN_009bec50_v05
{
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
};

struct FUN_009bec50_v07 : public FUN_009bec50_v06
{
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
};

struct FUN_009bec50_v08 : public FUN_009bec50_v07
{
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
};

struct FUN_009bec50_v09 : public FUN_009bec50_v08
{
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
};

struct FUN_009bec50_v10 : public FUN_009bec50_v09
{
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
};

struct FUN_009bec50_v11 : public FUN_009bec50_v10
{
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
};

struct FUN_009bec50_v12 : public FUN_009bec50_v11
{
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
};

struct FUN_009bec50_v13 : public FUN_009bec50_v12
{
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
};

struct FUN_009bec50_v14 : public FUN_009bec50_v13
{
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
};

struct FUN_009bec50_v15 : public FUN_009bec50_v14
{
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
};

struct FUN_009bec50_v16 : public FUN_009bec50_v15
{
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
};

struct FUN_009bec50_v17 : public FUN_009bec50_v16
{
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
};

struct FUN_009bec50_v18 : public FUN_009bec50_v17
{
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
};

struct FUN_00444d00_Class : public FUN_009bec50_v18
{
    bool __thiscall FUN_00444d00(int value);
};

struct FUN_009bec50_Class : public FUN_00444d00_Class
{
    virtual int vfn_2f8(float value);
    bool __thiscall FUN_009bec50(float value);
};

// @fnv 0x009bec50
bool __thiscall FUN_009bec50_Class::FUN_009bec50(float value)
{
    if (this->FUN_00444d00(0x80))
    {
        this->vfn_2f8(value);
    }
    return false;
}

void* __cdecl operator new(unsigned int uiSize, void* pvMem);
void __cdecl operator delete(void* pvObject, void* pvMem);

struct E9A3A80Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;

    E9A3A80Entry();
};

class E9A3A80Allocator
{
  public:
    void ConstructEntries(E9A3A80Entry* pkArray, unsigned int ItemUpdateArray);
};

// Constructs each of the given number of E9A3A80Entry objects in place in the array.
// @fnv 0x009a3a80
void E9A3A80Allocator::ConstructEntries(E9A3A80Entry* pkArray, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        new (&pkArray[i]) E9A3A80Entry;
}

extern int DAT_0108e258;

class CleanupBase
{
  public:
    virtual ~CleanupBase();
};

class FUN_009a4420_cls : public CleanupBase
{
  public:
    int unk04;

    void BaseCleanup();

    virtual ~FUN_009a4420_cls();
};

// @fnv 0x009a4420
FUN_009a4420_cls::~FUN_009a4420_cls()
{
    BaseCleanup();
}

struct Pt_009a4710
{
    float x, y, z;
    float FUN_00457910();
    float FUN_004a7290() const;
    float DotProduct(const Pt_009a4710& other) const;
    Pt_009a4710 operator*(float scale) const;
    Pt_009a4710 operator+(const Pt_009a4710& other) const;
    Pt_009a4710 operator-(const Pt_009a4710& other) const;
};
void __cdecl FUN_004a3760(Pt_009a4710* out, float scale, const Pt_009a4710& p);
struct Src_009a4710
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
    virtual const Pt_009a4710& Position();
};
struct Ctx_009a4710;
extern float DAT_0108e2b0;
struct Target_009a4710
{
    Src_009a4710* source;
    float radius;
    bool Contains(float time);
    float ComputeScaledRatio(Ctx_009a4710* ctx, float value);
    void FUN_009a4a10(Pt_009a4710& out);
    float ComputeFalloff(const Pt_009a4710& point, Ctx_009a4710* ctx, float time, float extra, float value);
};
// @fnv 0x009a4710
float Target_009a4710::ComputeFalloff(const Pt_009a4710& point, Ctx_009a4710* ctx, float time, float extra, float value)
{
    float result2 = 0.0f;
    if (time < 0.0 || Contains(time))
    {
        float range5 = radius + extra;
        float distSq_2 = 0.0f;
        float limit6 = range5 * *DAT_011cf48c.Float();
        Pt_009a4710 dir2;
        FUN_009a4a10(dir2);
        float len = dir2.FUN_00457910();
        Pt_009a4710 center8 = source->Position() + dir2 * len * 0.5f;
        if (len < limit6)
        {
            Pt_009a4710 _offset = center8 - point;
            distSq_2 = _offset.FUN_004a7290();
        }
        else
        {
            float t = 0.0f;
            t = FUN_00404010(t, 0.0f);
            Pt_009a4710 start7 = center8 + dir2 * (len * t - range5);
            float span = range5 * DAT_01011590 + (*DAT_011ce990.Float() - t) * len;
            float spanSq6 = span * span;
            Pt_009a4710 axis_2;
            FUN_004a3760(&axis_2, span, dir2);
            Pt_009a4710 diff = point - start7;
            float proj4 = diff.DotProduct(axis_2);
            if (proj4 < 0.0 || proj4 > spanSq6)
            {
                distSq_2 = DAT_0108e2b0;
            }
            else
            {
                distSq_2 = diff.FUN_004a7290() - proj4 * proj4 / spanSq6;
            }
        }
        if (distSq_2 < range5 * range5)
        {
            result2 = ComputeScaledRatio(ctx, value) * (1.0f - distSq_2 / (range5 * range5));
        }
    }
    return result2;
}

extern const double DAT_01026998;

struct FUN_00435e00_t : public TimestampStruct
{
    float FUN_00435e00();
};

struct FUN_0066ca00_holder
{
    void FUN_0066ca00(NiPoint3* apVelocity);
};

struct FUN_009a4a10_actor
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
    virtual void* v116();
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
    virtual bool v137();
    FUN_0066ca00_holder* FUN_009306d0();
    bool FUN_00444d00(int aiFlag);
};

struct FUN_00560d50_body
{
    void FUN_00560d50(const NiPoint3& arVelocity);
};

struct FUN_006fa820_coll
{
    void* FUN_006fa820();
};
FUN_006fa820_coll* __cdecl FUN_004b5260(void* apNode);

struct FUN_00653270_rtti;
extern FUN_00653270_rtti DAT_012681c0;
FUN_00560d50_body* __cdecl FUN_00653270(const FUN_00653270_rtti* apRTTI, void* apObject);

struct FUN_009a4a10_shell
{
    FUN_009a4a10_actor* pActor;
    char pad[0x18 - 4];
    void* pNode;
    FUN_00560d50_body* pCollisionEntry;
    NiPoint3 kMotionVelocity;
    FUN_00435e00_t kStamp;
    NiPoint3 FUN_009a4a10();
};

// Returns the cached velocity, refreshing it from the actor's controller or collision body when the timestamp is stale.
// @fnv 0x009a4a10
NiPoint3 FUN_009a4a10_shell::FUN_009a4a10()
{
    if (kStamp.FUN_00435e00() < DAT_01026998)
        return kMotionVelocity;

    void* pCurrentNode;
    FUN_0066ca00_holder* pController2;
    FUN_009a4a10_actor* pCharActor4;
    FUN_006fa820_coll* pCollision;
    void* pTmpWorldObject;
    FUN_00435de0_ctor kNowAX;
    FUN_00435de0_ctor kNowB7;
    FUN_00435de0_ctor kNowC4;
    FUN_00435de0_ctor kNowD;
    pCurrentNode = pActor->v116();
    if (pCurrentNode)
    {
        if (pActor->v137())
        {
            pCharActor4 = pActor;
            pController2 = pCharActor4->FUN_009306d0();
            if (pController2)
            {
                pController2->FUN_0066ca00(&kMotionVelocity);
                kNowAX.FUN_00435de0(FUN_00435dd0());
                kStamp.m_uiCommandId = kNowAX.m_uiCommandId;
                return kMotionVelocity;
            }
            if (pCharActor4->FUN_00444d00(8))
            {
                kMotionVelocity = *(NiPoint3*)&DAT_011f426c;
                kNowB7.FUN_00435de0(FUN_00435dd0());
                kStamp.m_uiCommandId = kNowB7.m_uiCommandId;
                return kMotionVelocity;
            }
        }
        if (pNode != pCurrentNode)
        {
            pNode = pCurrentNode;
            pCollision = FUN_004b5260(pNode);
            if (pCollision)
            {
                pTmpWorldObject = pCollision->FUN_006fa820();
                if (pTmpWorldObject)
                    pCollisionEntry = FUN_00653270(&DAT_012681c0, pTmpWorldObject);
            }
        }
        if (pCollisionEntry)
            pCollisionEntry->FUN_00560d50(kMotionVelocity);
        else
            kMotionVelocity = *(NiPoint3*)&DAT_011f426c;
        kNowC4.FUN_00435de0(FUN_00435dd0());
        kStamp.m_uiCommandId = kNowC4.m_uiCommandId;
        return kMotionVelocity;
    }
    {
        kNowD.FUN_00435de0(FUN_00435dd0());
        kStamp.m_uiCommandId = kNowD.m_uiCommandId;
    }
    return *(NiPoint3*)&DAT_011f426c;
}

class Entry9A5
{
  public:
    ~Entry9A5();

    int unk00;
    int unk04;
};

class Lock9A5
{
  public:
    void Lock();
    void Unlock();

    int unk00;
};

class Ref9A5
{
  public:
    unsigned int GetFormID();
};

class EntryMap9A5
{
  public:
    bool GetAt(unsigned int uiKey, Entry9A5*& pkValue) const;
    bool RemoveAt(unsigned int uiKey);

    void* m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
    Lock9A5 m_kLock;

    void RemoveEntryForRef(Ref9A5* pkRef);
};

// Locks the map, deletes the entry stored under the reference's form ID and removes that key, then unlocks.
// @fnv 0x009a51e0
void EntryMap9A5::RemoveEntryForRef(Ref9A5* pkRef)
{
    m_kLock.Lock();
    Entry9A5* pkEntry = 0;
    if (GetAt(pkRef->GetFormID(), pkEntry))
    {
        delete pkEntry;
        RemoveAt(pkRef->GetFormID());
    }
    m_kLock.Unlock();
}

struct Lock_009a5530
{
    void Lock();
    void Unlock();
};

struct Map_009a5530 : public NiTPointerMap<unsigned int, unsigned int>
{
    Lock_009a5530 m_lock;
};

struct Form_009a5530
{
    void NotifySaveLoadGameOfFormChange(bool);
    unsigned int GetFormID();
};

struct Item_009a5530 : public FUN_009a4690_shell
{
    char pad[0x30 - sizeof(FUN_009a4690_shell)];
    Item_009a5530(int a1, float a2, float a3, float a4, float a5);
    void FUN_004534f0(unsigned int);
};

struct Setting_009a5530
{
    bool* Bool();
};

extern Setting_009a5530 g_011f1ba0;

// @fnv 0x009a5530
void S_9a54a0_Class::AddOrUpdateItem(int pForm, float b, float c, float d, float e)
{
    ((Map_009a5530*)this)->m_lock.Lock();
    ((Form_009a5530*)pForm)->NotifySaveLoadGameOfFormChange(true);
    Item_009a5530* pItem = 0;
    if (((Map_009a5530*)this)->GetAt(((Form_009a5530*)pForm)->GetFormID(), (unsigned int&)pItem))
    {
        pItem->FUN_009a4690(pForm, b, c, d, e, true);
    }
    else
    {
        pItem = new Item_009a5530(pForm, b, c, d, e);
        ((Map_009a5530*)this)->SetAt(((Form_009a5530*)pForm)->GetFormID(), (unsigned int)pItem);
    }
    if (*g_011f1ba0.Bool())
    {
        pItem->FUN_004534f0(0);
    }
    ((Map_009a5530*)this)->m_lock.Unlock();
}

struct AvoidanceEntry
{
    Point9a position;
    Point9a direction;
    float radius;
    float distance;
    int type;
};
class PathingAvoidNodeArray
{
  public:
    void* vtable;
    AvoidanceEntry* entries;
    unsigned int count;
    unsigned int capacity;
    void* allocatorVtable;
    unsigned int allocatorState;
    static void* operator new(unsigned int);
    PathingAvoidNodeArray();
    unsigned int AppendNode(const AvoidanceEntry&);
};
struct AvoidanceActor
{
    bool FUN_009989d0();
};
struct AvoidanceContext
{
    AvoidanceActor* FUN_008a7f80();
};
struct AvoidanceSource
{
    float ComputeFalloff(void*, AvoidanceContext*, float, float, float);
    AvoidanceEntry FUN_009a4c70(AvoidanceContext*);
};
struct AvoidanceLock
{
    void FUN_00aa5ff0();
    void FUN_00aa62c0();
};
extern S_9a54a0_Setting DAT_011cfbcc;
struct AvoidanceMap
{
    unsigned int state;
    unsigned int buckets;
    unsigned int size;
    unsigned int capacity;
    AvoidanceLock lock;
    void* FUN_004b9ba0();
    void FUN_006b7f20(void*&, unsigned int&, AvoidanceSource*&);
    PathingAvoidNodeArray* BuildAvoidanceNodes(void*, AvoidanceContext*, float);
};
// Collects avoidance entries scored above a threshold into a new PathingAvoidNodeArray, falling back to the best-scoring entry if none qualify.
// @fnv 0x009a57a0
PathingAvoidNodeArray* AvoidanceMap::BuildAvoidanceNodes(void* argument, AvoidanceContext* context, float time)
{
    {
        AvoidanceActor* actor = context->FUN_008a7f80();
        if (actor->FUN_009989d0())
            return 0;
    }
    float evaluationTime = 0.0f;
    if (time < 0.0)
        evaluationTime = time;
    else
        evaluationTime = FUN_00435dd0() + time;
    PathingAvoidNodeArray* nodes = 0;
    AvoidanceSource* pBestEntry = 0;
    float result = 0.0f;
    lock.FUN_00aa5ff0();
    void* position = FUN_004b9ba0();
    while (position)
    {
        unsigned int sourceKey = 0;
        AvoidanceSource* entry = 0;
        FUN_006b7f20(position, sourceKey, entry);
        float score = entry->ComputeFalloff(argument, context, evaluationTime, 1024.0f, 0.0f);
        if (score > result)
        {
            result = score;
            pBestEntry = entry;
        }
        if (score > *DAT_011cfbcc.FUN_00403e20())
        {
            if (!nodes)
                nodes = new PathingAvoidNodeArray;
            nodes->AppendNode(entry->FUN_009a4c70(context));
        }
    }
    lock.FUN_00aa62c0();
    if (!nodes && pBestEntry)
    {
        nodes = new PathingAvoidNodeArray;
        nodes->AppendNode(pBestEntry->FUN_009a4c70(context));
    }
    return nodes;
}

struct FUN_00435de0
{
    float value;
    FUN_00435de0(float input);
};
struct FUN_00633c90
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00633c90(int value);
    ~FUN_00633c90();
};
struct FUN_006815c0
{
    int unk00;
    int unk04;
    int unk08;
    FUN_006815c0();
};
struct FUN_009a5b90
{
    int unk00;
    float unk04;
    FUN_00435de0 unk08;
    FUN_00435de0 unk0c;
    float unk10;
    FUN_00633c90 unk14;
    FUN_006815c0 unk20;
    CombatTargetTimestamp unk2c;
    FUN_009a5b90();
};
// @fnv 0x009a5b90
FUN_009a5b90::FUN_009a5b90() : unk00(0), unk04(0.0f), unk08(0.0f), unk0c(0.0f), unk10(0.0f), unk14(0), unk20()
{
    FUN_004300a0(&unk2c);
}

// Return the current response's voice file path (or the default path), toggling the dialogue lock around it.

class A6080Path;

class A6080Response
{
  public:
    A6080Path* GetVoiceFilePath();
};

A6080Path* __stdcall A6080GetDefaultPath();

class A6080Speaker
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
    virtual void Unk48();
    virtual void Unk4C();
    virtual void Unk50();
    virtual void Unk54();
    virtual void Unk58();
    virtual void Unk5C();
    virtual void Unk60();
    virtual void Unk64();
    virtual void Unk68();
    virtual void Unk6C();
    virtual void Unk70();
    virtual void Unk74();
    virtual void Unk78();
    virtual void Unk7C();
    virtual void Unk80();
    virtual void Unk84();
    virtual void Unk88();
    virtual void Unk8C();
    virtual void Unk90();
    virtual A6080Response* GetActiveResponse();

    void ToggleLock();
    A6080Path* FUN_009a6080();
};

// Toggles the speaker lock, gets the voice file path from the response (or the default path if none), then toggles the lock again and returns it.
// @fnv 0x009a6080
A6080Path* A6080Speaker::FUN_009a6080()
{
    A6080Response* pkResponse = GetActiveResponse();
    ToggleLock();
    A6080Path* pkFound = pkResponse ? pkResponse->GetVoiceFilePath() : A6080GetDefaultPath();
    A6080Path* pkPath = pkFound;
    ToggleLock();
    return pkPath;
}

struct Vec3
{
    float x;
    float y;
    float z;
};

extern Vec3 g_defaultVec3;

void GetTriple12(Vec3* out, const void* p);
void GetTargetLocationWithOffset(Vec3* out, const void* p, int a);
void FUN_009a8f00(Vec3* out, Vec3 a, Vec3 b, Vec3 c, float first, float second, int flags);
void GetPitchYaw(Vec3* out, Vec3 a, Vec3 b);

// @fnv 0x009a87f0
Vec3* FUN_009a87f0(Vec3* out, Vec3 vecInput, const void* pData, float f1, float f2, int a5)
{
    if (pData == 0)
    {
        *out = g_defaultVec3;
        return out;
    }
    Vec3 A;
    Vec3 B;
    Vec3 C;
    GetTriple12(&A, pData);
    GetTargetLocationWithOffset(&B, pData, a5);
    FUN_009a8f00(&C, vecInput, B, A, f1, f2, 0);
    GetPitchYaw(out, vecInput, C);
    return out;
}

struct TargetVector
{
    float x, y, z;
    TargetVector ApplyScaled(float scale) const;
    TargetVector FUN_004b3800(const TargetVector& other) const;
    TargetVector FUN_00439e90(const TargetVector& other) const;
    TargetVector FUN_00439ef0(const TargetVector& other) const;
};
struct TargetActor
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    TargetVector position, alternate, direction;
    bool FUN_006e4820();
    bool FUN_00982be0();
};
struct TargetSettings
{
    unsigned char unk00, unk01, unk02, unk03;
    bool enabled, reverse;
    float FUN_009a95f0();
};
extern const TargetVector DAT_011a9484;
// @fnv 0x009a93e0
void __cdecl FUN_009a93e0(float distance, TargetActor* actor, TargetSettings* settings, TargetVector* first,
                          TargetVector* second)
{
    if (!first && !second)
        return;
    float offset = distance + 16.0;
    float radiusX = 64.0f;
    float radiusA = 128.0f;
    TargetVector delta5 = actor->direction.ApplyScaled(-offset);
    TargetVector cross3 = actor->direction.FUN_004b3800(DAT_011a9484);
    float scale3 = settings->FUN_009a95f0();
    TargetVector origin = actor->position.FUN_00439e90(cross3.ApplyScaled(scale3)).FUN_00439e90(delta5);
    if (!actor->FUN_006e4820())
    {
        if (first)
            *first = origin;
        if (second)
        {
            if (actor->FUN_00982be0() || settings->enabled)
            {
                if (settings->reverse)
                    *second = actor->position.FUN_00439ef0(cross3.ApplyScaled(radiusX)).FUN_00439e90(delta5);
                else
                    *second = actor->alternate.FUN_00439e90(cross3.ApplyScaled(radiusX)).FUN_00439e90(delta5);
            }
            else
            {
                *second = origin;
            }
        }
    }
    else
    {
        if (second)
            *second = origin;
        if (first)
            *first = origin.FUN_00439e90(actor->direction.ApplyScaled(-radiusA));
    }
}

struct TargetRef;
struct TargetExtra;
struct TargetMatrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
};
struct TargetRef
{
    virtual void vf000();
    virtual void vf001();
    virtual void vf002();
    virtual void vf003();
    virtual void vf004();
    virtual void vf005();
    virtual void vf006();
    virtual void vf007();
    virtual void vf008();
    virtual void vf009();
    virtual void vf010();
    virtual void vf011();
    virtual void vf012();
    virtual void vf013();
    virtual void vf014();
    virtual void vf015();
    virtual void vf016();
    virtual void vf017();
    virtual void Mark(int);
    virtual void vf019();
    virtual void vf020();
    virtual void vf021();
    virtual void vf022();
    virtual void vf023();
    virtual void vf024();
    virtual void vf025();
    virtual void vf026();
    virtual void vf027();
    virtual void vf028();
    virtual void vf029();
    virtual void vf030();
    virtual void vf031();
    virtual void vf032();
    virtual void vf033();
    virtual void vf034();
    virtual void vf035();
    virtual void vf036();
    virtual void vf037();
    virtual void vf038();
    virtual void vf039();
    virtual void vf040();
    virtual void vf041();
    virtual void vf042();
    virtual void vf043();
    virtual void vf044();
    virtual void vf045();
    virtual void vf046();
    virtual void vf047();
    virtual void vf048();
    virtual void vf049();
    virtual void vf050();
    virtual void vf051();
    virtual void vf052();
    virtual void vf053();
    virtual void vf054();
    virtual void vf055();
    virtual void vf056();
    virtual void vf057();
    virtual void vf058();
    virtual void vf059();
    virtual void vf060();
    virtual void vf061();
    virtual void vf062();
    virtual void vf063();
    virtual bool NeedsExtra();
    virtual void vf065();
    virtual void vf066();
    virtual void vf067();
    virtual void vf068();
    virtual void vf069();
    virtual void vf070();
    virtual void vf071();
    virtual void vf072();
    virtual void vf073();
    virtual void vf074();
    virtual void vf075();
    virtual void vf076();
    virtual void vf077();
    virtual void vf078();
    virtual void vf079();
    virtual void vf080();
    virtual void vf081();
    virtual TargetRef* GetLoadedForm();
    virtual void vf083();
    virtual void vf084();
    virtual void vf085();
    virtual void vf086();
    virtual void vf087();
    virtual void vf088();
    virtual void SetExtra(TargetExtra*);
    virtual TargetExtra* GetExtra();
    virtual void vf091();
    virtual void vf092();
    virtual void vf093();
    virtual void vf094();
    virtual void vf095();
    virtual void vf096();
    virtual void vf097();
    virtual void vf098();
    virtual void vf099();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual void vf125();
    virtual void vf126();
    virtual void vf127();
    virtual void vf128();
    virtual void vf129();
    virtual void vf130();
    virtual void vf131();
    virtual void vf132();
    virtual void vf133();
    virtual void vf134();
    virtual void vf135();
    virtual void vf136();
    virtual bool IsProjectile();
    virtual void vf138();
    virtual void vf139();
    virtual void vf140();
    virtual void vf141();
    virtual void vf142();
    virtual void vf143();
    virtual void vf144();
    virtual void vf145();
    virtual void vf146();
    virtual void vf147();
    virtual void vf148();
    virtual void vf149();
    virtual void vf150();
    virtual void vf151();
    virtual void vf152();
    virtual void vf153();
    virtual void vf154();
    virtual void vf155();
    virtual void vf156();
    virtual void vf157();
    virtual void vf158();
    virtual void vf159();
    virtual void vf160();
    virtual void vf161();
    virtual void vf162();
    virtual void vf163();
    virtual void vf164();
    virtual void vf165();
    virtual void vf166();
    virtual void vf167();
    virtual void vf168();
    virtual void vf169();
    virtual void vf170();
    virtual void vf171();
    virtual void vf172();
    virtual void vf173();
    virtual void vf174();
    virtual void vf175();
    virtual void vf176();
    virtual void vf177();
    virtual void vf178();
    virtual void vf179();
    virtual void vf180();
    virtual void vf181();
    virtual void vf182();
    virtual void vf183();
    virtual void vf184();
    virtual void vf185();
    virtual void vf186();
    virtual void vf187();
    virtual void vf188();
    virtual void vf189();
    virtual void vf190();
    virtual void vf191();
    virtual void vf192();
    virtual void Update();
    TargetRef* FUN_00874480();
    unsigned int FUN_00476c90();
    TargetRef* FUN_008d8520();
    unsigned int FUN_0044ddc0();
    float FUN_00644930();
    void FUN_00407880(float);
    TargetRef* GetFieldC8();
    void FUN_0056c7d0(TargetRef*);
    bool FUN_00572c80();
};
struct FUN_009ac200 : TargetRef
{
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
    FUN_009ac200(void*, TargetRef*, int, NiPoint3, TargetMatrix);
};
struct TargetExtra
{
};
struct FUN_0066e010 : TargetExtra
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    FUN_0066e010(TargetRef*);
};
struct TargetQueue
{
    void QueueCheckTask();
};
TargetQueue* __stdcall FUN_004537b0(TargetRef*);
bool __cdecl FUN_008c7aa0();
extern TargetRef* DAT_011dea3c;
void __cdecl FUN_005e58f0(int, TargetRef*, ...);
void* __cdecl operator new(unsigned int);

// Creates a new projectile reference from a form, source and parent, scales it, attaches extra data, links it to the parent and updates or queues it.
// @fnv 0x009ac9c0
TargetRef* __cdecl CreateProjectileRef(void* form, TargetRef* source, TargetRef* parent, int flags, NiPoint3 position,
                                       TargetMatrix rotation)
{
    TargetRef* result = 0;
    float scale = 1.0f;
    if (form)
    {
        TargetRef* owner = source;
        if (source && source->IsProjectile())
        {
            TargetRef* projectile = source;
            owner = projectile->FUN_00874480();
            if (owner == DAT_011dea3c)
            {
                TargetRef* actor = source;
                unsigned int actorFlags = actor ? actor->FUN_00476c90() : 0;
                FUN_005e58f0(0x48, DAT_011dea3c, actorFlags, &scale);
            }
        }
        else if (source && source == DAT_011dea3c)
        {
            TargetRef* weaponFlags = DAT_011dea3c->FUN_008d8520() ? DAT_011dea3c->FUN_008d8520()->GetLoadedForm() : 0;
            unsigned int weapon = weaponFlags ? weaponFlags->FUN_0044ddc0() : 0;
            FUN_005e58f0(0x48, DAT_011dea3c, weapon, &scale);
        }
        result = new FUN_009ac200(form, owner, flags, position, rotation);
        result->FUN_00407880(result->FUN_00644930() * scale);
    }
    if (result)
    {
        if (result->GetFieldC8())
        {
            TargetExtra* extra = 0;
            if (result->GetFieldC8()->NeedsExtra())
            {
                extra = new FUN_0066e010(result->GetFieldC8());
            }
            else
            {
                extra = result->GetFieldC8()->GetExtra();
            }
            result->SetExtra(extra);
        }
        result->FUN_0056c7d0(parent);
        if (parent && parent->FUN_00572c80())
        {
            parent->Mark(4);
        }
        if (!FUN_008c7aa0())
        {
            result->Update();
        }
        else
        {
            FUN_004537b0(result)->QueueCheckTask();
        }
    }
    return result;
}

struct MatchPoint
{
    float x, y, z;
    MatchPoint operator-(const MatchPoint&) const;
    float Length() const;
};
struct MatchRef
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
    virtual bool IsActor();
    bool GetGhost();
    MatchPoint& Position();
};
struct MatchArray
{
    int Count();
    unsigned int& At(int);
};
struct MatchList
{
    MatchArray* Items();
};
struct MatchPointer
{
    MatchList* Get();
};
struct MatchBase
{
    int Rank();
};
extern MatchRef* _g_thePlayer;
MatchRef* Resolve(unsigned int);
MatchRef* CastActor(MatchRef*);
MatchBase* FindBase(unsigned int);
struct MatchContext
{
    virtual void c000();
    virtual void c004();
    virtual void c008();
    virtual void c00c();
    virtual void c010();
    virtual void c014();
    virtual void c018();
    virtual void c01c();
    virtual void c020();
    virtual void c024();
    virtual void c028();
    virtual void c02c();
    virtual void c030();
    virtual void c034();
    virtual void c038();
    virtual void c03c();
    virtual void c040();
    virtual void c044();
    virtual void c048();
    virtual void c04c();
    virtual void c050();
    virtual void c054();
    virtual void c058();
    virtual void c05c();
    virtual void c060();
    virtual void c064();
    virtual void c068();
    virtual void c06c();
    virtual void c070();
    virtual void c074();
    virtual void c078();
    virtual void c07c();
    virtual void c080();
    virtual void c084();
    virtual void c088();
    virtual void c08c();
    virtual void c090();
    virtual void c094();
    virtual void c098();
    virtual void c09c();
    virtual void c0a0();
    virtual void c0a4();
    virtual void c0a8();
    virtual void c0ac();
    virtual void c0b0();
    virtual void c0b4();
    virtual void c0b8();
    virtual void c0bc();
    virtual void c0c0();
    virtual void c0c4();
    virtual void c0c8();
    virtual void c0cc();
    virtual void c0d0();
    virtual void c0d4();
    virtual void c0d8();
    virtual void c0dc();
    virtual void c0e0();
    virtual void c0e4();
    virtual void c0e8();
    virtual void c0ec();
    virtual void c0f0();
    virtual void c0f4();
    virtual void c0f8();
    virtual void c0fc();
    virtual void c100();
    virtual void c104();
    virtual void c108();
    virtual void c10c();
    virtual void c110();
    virtual void c114();
    virtual void c118();
    virtual void c11c();
    virtual void c120();
    virtual void c124();
    virtual void c128();
    virtual void c12c();
    virtual void c130();
    virtual void c134();
    virtual void c138();
    virtual void c13c();
    virtual void c140();
    virtual void c144();
    virtual void c148();
    virtual void c14c();
    virtual void c150();
    virtual void c154();
    virtual void c158();
    virtual void c15c();
    virtual void c160();
    virtual void c164();
    virtual void c168();
    virtual void c16c();
    virtual void c170();
    virtual void c174();
    virtual void c178();
    virtual void c17c();
    virtual void c180();
    virtual void c184();
    virtual void c188();
    virtual void c18c();
    virtual void c190();
    virtual void c194();
    virtual void c198();
    virtual void c19c();
    virtual void c1a0();
    virtual void c1a4();
    virtual void c1a8();
    virtual void c1ac();
    virtual void c1b0();
    virtual void c1b4();
    virtual void c1b8();
    virtual void c1bc();
    virtual void c1c0();
    virtual void c1c4();
    virtual void c1c8();
    virtual void c1cc();
    virtual void c1d0();
    virtual void c1d4();
    virtual void c1d8();
    virtual void c1dc();
    virtual void c1e0();
    virtual void c1e4();
    virtual void c1e8();
    virtual void c1ec();
    virtual void c1f0();
    virtual MatchPoint& Position();
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
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    MatchPointer entries;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    MatchRef* excluded;
    int unkcc;
    int unkd0;
    char unkd4;
    bool done;
    void* Evaluate(MatchRef*, int, bool);
    float Factor();
    void Update(void*, MatchRef*, float);
    void UpdateMatchingActors();
};
// @fnv 0x009afcc0
void MatchContext::UpdateMatchingActors()
{
    void* playerResult = Evaluate(_g_thePlayer, 0, true);
    if (entries.Get())
    {
        for (int index3 = 0; index3 < entries.Get()->Items()->Count(); ++index3)
        {
            MatchRef* reference = Resolve(entries.Get()->Items()->At(index3));
            MatchRef* actor = CastActor(reference);
            if (actor)
            {
                if (actor->IsActor())
                {
                    MatchRef* ghostActor4 = actor;
                    if (ghostActor4->GetGhost())
                        continue;
                }
                MatchBase* base2 = FindBase(entries.Get()->Items()->At(index3));
                bool lowRank = base2 ? base2->Rank() < 4 : false;
                void* result = 0;
                if (actor != _g_thePlayer && actor != excluded)
                    result = Evaluate(actor, 0, lowRank);
                else if (actor == _g_thePlayer)
                    result = playerResult;
                if (result && actor->IsActor() && Factor() > 0.0)
                {
                    Update(result, reference, (reference->Position() - Position()).Length());
                }
            }
        }
    }
    done = true;
}

class List9AF
{
  public:
    void* GetFirst();
};

class Owner9AF
{
  public:
    List9AF* GetList();
    void* GetFirstListItem();
};

// Retrieves the list via GetList and returns its first element from GetFirst.
// @fnv 0x009afed0
void* Owner9AF::GetFirstListItem()
{
    List9AF* pkList = GetList();
    return pkList->GetFirst();
}

struct BaseFlags9af
{
    bool HasFlag(unsigned int flag);
};
struct List9af
{
    int GetSize();
    void*& GetAt(unsigned int idx);
};
struct Owner9af
{
    List9af* GetList();
};
struct PathPtr
{
    operator Owner9af*() const;
};
struct Filter9af
{
    unsigned int uiFilterInfo;
    int GetLayer();
};
struct Body9af
{
    Filter9af GetFilter();
    int GetMotionKind();
};
struct Ref9af
{
    unsigned int GetFlags();
};
struct Shader9af
{
    int GetAddonModels();
};
struct Form9af
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual bool IsShader();
};
void* FUN_004b59f0(const void* p);
Body9af* FUN_004b5a80(const void* p);
Ref9af* FUN_004b5a20(const void* p);
Form9af* FUN_0056f930(unsigned int id);

struct Actor9af
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
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    PathPtr unka0;
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
    void* unkcc;
    int unkd0;
    char unkd4;
    char unkd5;
    char unkd6;
    char unkd7;
    BaseFlags9af* GetActorBase();
    void AddBody(Body9af* body);
    void FUN_009afef0();
};

// @fnv 0x009afef0
void Actor9af::FUN_009afef0()
{
    if (unka0)
    {
        bool bFlag = GetActorBase()->HasFlag(0x20);
        for (int i = 0; i < ((Owner9af*)unka0)->GetList()->GetSize(); i++)
        {
            void* pObj2 = FUN_004b59f0(((Owner9af*)unka0)->GetList()->GetAt(i));
            Body9af* pBody6 = FUN_004b5a80(pObj2);
            int iLayerB = pBody6 ? pBody6->GetFilter().GetLayer() : 0;
            if (bFlag || iLayerB == 0x1d)
            {
                Ref9af* pRef = FUN_004b5a20(pObj2);
                unsigned int uiIDA = pRef ? pRef->GetFlags() : 0;
                Form9af* pForm5 = FUN_0056f930(uiIDA);
                if (bFlag && pForm5 != unkcc)
                    continue;
                if (pForm5)
                {
                    Shader9af* pShader = pForm5->IsShader() ? (Shader9af*)pForm5 : 0;
                    if (pShader && pShader->GetAddonModels() == 1)
                        continue;
                }
            }
            if (pBody6 && (pBody6->GetMotionKind() < 4 || iLayerB == 0x14))
                AddBody(pBody6);
        }
    }
    unkd7 = 1;
}

namespace fnv_009b00a0 {
struct Obj082;
struct List082;
struct Entry082
{
    Obj082* object;
    unsigned char unk04;
    unsigned char update;
    unsigned char skip;
};
struct List082
{
    bool FUN_008256d0();
    Entry082** FUN_006815c0();
    List082* FUN_00726070();
};
struct Vector082
{
    float x, y, z;
    Vector082 FUN_00439ef0(const Vector082*);
    float FUN_00457990();
    void FUN_0043d410(float, int, int);
};
struct Pair082
{
    float x, y;
    Pair082(float, float);
};
struct Curve082
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void Apply(void*, int, void*, float, int);
};
struct Effect082
{
    int unk00, unk04, unk08;
    Curve082 curve;
};
struct Hit082
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    float unk40;
    float unk44;
    float unk48;
    float unk4c;
    float unk50;
    float unk54;
    float unk58;
    float unk5c;
    float unk60;
    void FUN_009b4d90();
};
struct Obj082
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
    virtual bool IsActor();
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
    virtual void Damage(float, int);
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void Update(Obj082*);
    virtual Obj082* GetSource();
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
    virtual Obj082* GetNode();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual Vector082* Position();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool State(int);
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
    List082 hits;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    Obj082* impactSource;
    int unkcc;
    int unkd0;
    unsigned short unkD4;
    unsigned char processing;
    unsigned char unkD7;
    int unkd8;
    Effect082* effect;
    bool FUN_00477ba0();
    bool FUN_00440da0();
    float FUN_00644930();
    float FUN_008d01e0();
    Obj082* FUN_004181e0();
    Obj082* GetFieldC8();
    Obj082* GetFieldE0();
    float GetCachedValue();
    int FUN_00559450();
    int FUN_005d43c0();
    void CallProcessAt778();
    void SetEffectValue(int, float, int);
    bool FUN_009b1810(Vector082, Obj082*);
    void FUN_0089a760(Hit082*, int);
    void InitFromPoints(const Pair082&, const Pair082&, const Pair082&);
    bool HasAnyFlags(int);
    void FUN_009b0d70(Obj082*, float);
    Obj082* FUN_00950bb0(int);
    void FUN_00a59c60(Vector082*);
    void ProcessHits();
};
struct Setting082
{
    float* FUN_00403e20();
};
extern Obj082* DAT_011dea3c;
extern float DAT_0102918c;
extern Setting082 DAT_011d0030, DAT_011d0490, DAT_011cfea0, DAT_011d0edc, DAT_011d0d38, DAT_011d00d8, DAT_011d05e0;
float ComputeSquaredRatioComplement(float, float);
void FUN_005299a0(void*, float, int);
void FUN_005ac750(void*, int, int);
void InitCombatThing(Hit082*, Obj082*, Obj082*, Obj082*, float);
Pair082 FUN_00532fd0(float, Pair082*);
Obj082* FUN_00705950();
bool FUN_00646400(void*, int);
void FUN_00c6a350(Obj082*, int, int, int, int);
// @fnv 0x009b00a0
void Obj082::ProcessHits()
{
    processing = true;
    List082* iter = &hits;
    while (iter && !iter->FUN_008256d0())
    {
        Entry082* entry = *iter->FUN_006815c0();
        iter = iter->FUN_00726070();
        if (entry && entry->object && !entry->skip && !entry->object->FUN_00477ba0() && !entry->object->FUN_00440da0())
        {
            float radius = entry->object->Position()->FUN_00439ef0(Position()).FUN_00457990();
            float distance = ComputeSquaredRatioComplement(FUN_00644930(), radius);
            float factor = FUN_008d01e0();
            float damage = factor > 0.0 ? ComputeSquaredRatioComplement(factor, radius) : 1.0f;
            if (damage > 0.0 && entry->object->IsActor())
            {
                Obj082* target = entry->object;
                if (target == DAT_011dea3c)
                {
                    Obj082* base = FUN_004181e0();
                    List082* data = ((List082*)&base->unk68)->FUN_00726070();
                    data = data;
                    if (data)
                        FUN_005299a0(data, damage, 0);
                }
            }
            if (distance > 0.0)
            {
                if (entry->update)
                    entry->object->Update(GetSource());
                float actor;
                Obj082* amount = entry->object->IsActor() ? entry->object : 0;
                if (amount)
                    amount->CallProcessAt778();
                FUN_005ac750(GetSource() ? (void*)GetSource()->FUN_00559450() : 0, entry->object->FUN_005d43c0(), 0x80);
                if (GetFieldE0())
                    FUN_005ac750(GetFieldE0(), entry->object->FUN_005d43c0(), 0x100);
                else
                    FUN_005ac750(FUN_004181e0(), entry->object->FUN_005d43c0(), 0x100);
                actor = GetCachedValue() * distance;
                if (entry->object->FUN_00477ba0() && GetFieldC8() == DAT_011dea3c)
                    DAT_011dea3c->SetEffectValue(10, DAT_0102918c, 0);
                if (amount)
                {
                    if (FUN_009b1810(*Position(), amount))
                    {
                        Hit082 hit;
                        hit.FUN_009b4d90();
                        InitCombatThing(&hit, impactSource && impactSource->IsActor() ? impactSource : 0, amount, this,
                                        actor);
                        amount->FUN_0089a760(&hit, 0);
                        if (amount == DAT_011dea3c && distance > *DAT_011d0030.FUN_00403e20())
                        {
                            Pair082 c(*DAT_011cfea0.FUN_00403e20(), *DAT_011d0490.FUN_00403e20());
                            Pair082 b(*DAT_011d0d38.FUN_00403e20(), *DAT_011d0edc.FUN_00403e20());
                            Pair082 a(*DAT_011d05e0.FUN_00403e20(), *DAT_011d00d8.FUN_00403e20());
                            FUN_00705950()->InitFromPoints(FUN_00532fd0(distance, &c), FUN_00532fd0(distance, &b), a);
                        }
                        List082* data = ((List082*)&FUN_004181e0()->unk54)->FUN_00726070();
                        if (data && ((GetFieldC8() && GetFieldC8()->IsActor()) || effect))
                        {
                            if (effect)
                                effect->curve.Apply(data ? &((Obj082*)data)->unk18 : 0, 0, amount ? &amount->unk94 : 0,
                                                    1.0f, 0);
                            else
                                ((Curve082*)&GetFieldC8()->unk88)
                                    ->Apply(data ? &((Obj082*)data)->unk18 : 0, 0, amount ? &amount->unk94 : 0, 1.0f,
                                            0);
                        }
                        if (!amount->State(0) && (FUN_004181e0()->HasAnyFlags(4) ||
                                                  (FUN_004181e0()->HasAnyFlags(8) &&
                                                   FUN_00646400(amount ? &amount->hits : 0, (int)hit.unk14))))
                            FUN_009b0d70(amount, distance);
                        if (amount->State(0))
                        {
                            Obj082* zero;
                            if (amount == DAT_011dea3c)
                                zero = DAT_011dea3c->FUN_00950bb0(0);
                            else
                                zero = amount->GetNode();
                            FUN_00c6a350(zero, 1, 1, 0, 1);
                            Vector082 node;
                            node.FUN_0043d410(0.0f, 0, 0);
                            zero->FUN_00a59c60(&node);
                        }
                    }
                }
                else
                    entry->object->Damage(actor, 0);
            }
        }
    }
}
}  // namespace fnv_009b00a0

class B9B1320Light
{
  public:
    void SetFade(float fFadeAmount);
};

class B9B1320LightPtr
{
  public:
    B9B1320Light* Get();

    B9B1320Light* m_pkLight;
};

float __cdecl B9B1320Min(float fA, float fB);
float __cdecl B9B1320Max(float fA, float fB);

class B9B1320Request
{
  public:
    float GetGoalZDelta();
    float GetMaxZDelta();
    void UpdateLightFade();

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
    B9B1320LightPtr m_kLight;
};

// Computes a fade from the goal and max Z deltas, clamps it to 0..1, and applies it to the light if one is set.
// @fnv 0x009b1320
void B9B1320Request::UpdateLightFade()
{
    if (m_kLight.Get())
    {
        float fFadeAmount = 1.0 - 2.0 * GetGoalZDelta() / GetMaxZDelta();
        m_kLight.Get()->SetFade(B9B1320Max(0.0f, B9B1320Min(1.0f, fFadeAmount)));
    }
}

namespace fnv_009b2cb0 {
struct FUN_006299a0
{
    int value;

    FUN_006299a0();
    ~FUN_006299a0();
};

struct FUN_009b2cb0
{
    FUN_006299a0 unk00;
    int unk04;
    unsigned int unk08;
    int unk0c;

    FUN_009b2cb0(unsigned int a);
};

int __cdecl CallItemMethod(unsigned int a, unsigned int b);

FUN_006299a0::FUN_006299a0()
{}

FUN_006299a0::~FUN_006299a0()
{}

// @fnv 0x009b2cb0
FUN_009b2cb0::FUN_009b2cb0(unsigned int a)
{
    unk00.value = CallItemMethod(a, 0);
    unk08 = a | 0x80000000u;
    unk0c = unk00.value;
}
}  // namespace fnv_009b2cb0

struct WeaponHit
{
    int FormType();
    bool IsSpecial();
    int WeaponKind();
    unsigned char AmmoPerShot();
    bool Automatic();
    float DamageMult();
    bool IsMelee();
};
struct RefHit
{
    WeaponHit* Base();
    float Condition(int);
    float Damage(void*, float, int);
};
struct ValuesHit
{
    int Value(int);
    float FloatValue(int);
};
struct AnimHit
{
    unsigned short Group(int);
};
struct ActorHit
{
    virtual void virtual000();
    virtual void virtual004();
    virtual void virtual008();
    virtual void virtual00c();
    virtual void virtual010();
    virtual void virtual014();
    virtual void virtual018();
    virtual void virtual01c();
    virtual void virtual020();
    virtual void virtual024();
    virtual void virtual028();
    virtual void virtual02c();
    virtual void virtual030();
    virtual void virtual034();
    virtual void virtual038();
    virtual void virtual03c();
    virtual void virtual040();
    virtual void virtual044();
    virtual void virtual048();
    virtual void virtual04c();
    virtual void virtual050();
    virtual void virtual054();
    virtual void virtual058();
    virtual void virtual05c();
    virtual void virtual060();
    virtual void virtual064();
    virtual void virtual068();
    virtual void virtual06c();
    virtual void virtual070();
    virtual void virtual074();
    virtual void virtual078();
    virtual void virtual07c();
    virtual void virtual080();
    virtual void virtual084();
    virtual void virtual088();
    virtual void virtual08c();
    virtual void virtual090();
    virtual void virtual094();
    virtual void virtual098();
    virtual void virtual09c();
    virtual void virtual0a0();
    virtual void virtual0a4();
    virtual void virtual0a8();
    virtual void virtual0ac();
    virtual void virtual0b0();
    virtual void virtual0b4();
    virtual void virtual0b8();
    virtual void virtual0bc();
    virtual void virtual0c0();
    virtual void virtual0c4();
    virtual void virtual0c8();
    virtual void virtual0cc();
    virtual void virtual0d0();
    virtual void virtual0d4();
    virtual void virtual0d8();
    virtual void virtual0dc();
    virtual void virtual0e0();
    virtual void virtual0e4();
    virtual void virtual0e8();
    virtual void virtual0ec();
    virtual void virtual0f0();
    virtual void virtual0f4();
    virtual void virtual0f8();
    virtual void virtual0fc();
    virtual void virtual100();
    virtual void virtual104();
    virtual void virtual108();
    virtual void virtual10c();
    virtual void virtual110();
    virtual void virtual114();
    virtual void virtual118();
    virtual void virtual11c();
    virtual void virtual120();
    virtual void virtual124();
    virtual void virtual128();
    virtual void virtual12c();
    virtual void virtual130();
    virtual void virtual134();
    virtual void virtual138();
    virtual void virtual13c();
    virtual void virtual140();
    virtual void virtual144();
    virtual void virtual148();
    virtual void virtual14c();
    virtual void virtual150();
    virtual void virtual154();
    virtual void virtual158();
    virtual void virtual15c();
    virtual void virtual160();
    virtual void virtual164();
    virtual void virtual168();
    virtual void virtual16c();
    virtual void virtual170();
    virtual void virtual174();
    virtual void virtual178();
    virtual void virtual17c();
    virtual void virtual180();
    virtual void virtual184();
    virtual void virtual188();
    virtual void virtual18c();
    virtual void virtual190();
    virtual void virtual194();
    virtual void virtual198();
    virtual void virtual19c();
    virtual void virtual1a0();
    virtual void virtual1a4();
    virtual void virtual1a8();
    virtual void virtual1ac();
    virtual void virtual1b0();
    virtual void virtual1b4();
    virtual void virtual1b8();
    virtual void virtual1bc();
    virtual void virtual1c0();
    virtual void virtual1c4();
    virtual void virtual1c8();
    virtual void virtual1cc();
    virtual void virtual1d0();
    virtual void virtual1d4();
    virtual void virtual1d8();
    virtual void virtual1dc();
    virtual void virtual1e0();
    virtual AnimHit* Anim();
    virtual void virtual1e8();
    virtual void virtual1ec();
    virtual void virtual1f0();
    virtual void virtual1f4();
    virtual void virtual1f8();
    virtual void virtual1fc();
    virtual void virtual200();
    virtual void virtual204();
    virtual void virtual208();
    virtual void virtual20c();
    virtual void virtual210();
    virtual void virtual214();
    virtual void virtual218();
    virtual bool Creature();
    virtual void virtual220();
    virtual void virtual224();
    virtual void virtual228();
    virtual void virtual22c();
    virtual bool TargetFlag();
    virtual void virtual234();
    virtual void virtual238();
    virtual void virtual23c();
    virtual void virtual240();
    virtual void virtual244();
    virtual void virtual248();
    virtual void virtual24c();
    virtual void virtual250();
    virtual void virtual254();
    virtual void virtual258();
    virtual void virtual25c();
    virtual void virtual260();
    virtual void virtual264();
    virtual void virtual268();
    virtual void virtual26c();
    virtual void virtual270();
    virtual void virtual274();
    virtual void virtual278();
    virtual void virtual27c();
    virtual void virtual280();
    virtual void virtual284();
    virtual void virtual288();
    virtual void virtual28c();
    virtual void virtual290();
    virtual void virtual294();
    virtual void virtual298();
    virtual void virtual29c();
    virtual void virtual2a0();
    virtual void virtual2a4();
    virtual void virtual2a8();
    virtual void virtual2ac();
    virtual void virtual2b0();
    virtual void virtual2b4();
    virtual void virtual2b8();
    virtual void virtual2bc();
    virtual void virtual2c0();
    virtual void virtual2c4();
    virtual void virtual2c8();
    virtual void virtual2cc();
    virtual void virtual2d0();
    virtual void virtual2d4();
    virtual void virtual2d8();
    virtual void virtual2dc();
    virtual void virtual2e0();
    virtual void virtual2e4();
    virtual void virtual2e8();
    virtual void virtual2ec();
    virtual void virtual2f0();
    virtual void virtual2f4();
    virtual void virtual2f8();
    virtual void virtual2fc();
    virtual void virtual300();
    virtual void virtual304();
    virtual void virtual308();
    virtual void virtual30c();
    virtual void virtual310();
    virtual void virtual314();
    virtual void virtual318();
    virtual void virtual31c();
    virtual void virtual320();
    virtual void virtual324();
    virtual void virtual328();
    virtual void virtual32c();
    virtual void virtual330();
    virtual void virtual334();
    virtual void virtual338();
    virtual void virtual33c();
    virtual void virtual340();
    virtual void virtual344();
    virtual void virtual348();
    virtual void virtual34c();
    virtual void virtual350();
    virtual void virtual354();
    virtual void virtual358();
    virtual void virtual35c();
    virtual bool SpecialActor();
    virtual void virtual364();
    virtual void virtual368();
    virtual void virtual36c();
    virtual void virtual370();
    virtual void virtual374();
    virtual void virtual378();
    virtual void virtual37c();
    virtual void virtual380();
    virtual void virtual384();
    virtual void virtual388();
    virtual void virtual38c();
    virtual void virtual390();
    virtual void virtual394();
    virtual void virtual398();
    virtual void virtual39c();
    virtual void virtual3a0();
    virtual void virtual3a4();
    virtual void virtual3a8();
    virtual void virtual3ac();
    virtual void virtual3b0();
    virtual void virtual3b4();
    virtual void virtual3b8();
    virtual void virtual3bc();
    virtual void virtual3c0();
    virtual void virtual3c4();
    virtual void virtual3c8();
    virtual void virtual3cc();
    virtual void virtual3d0();
    virtual void virtual3d4();
    virtual void virtual3d8();
    virtual void virtual3dc();
    virtual void virtual3e0();
    virtual void virtual3e4();
    virtual void virtual3e8();
    virtual void virtual3ec();
    virtual void virtual3f0();
    virtual void virtual3f4();
    virtual void virtual3f8();
    virtual void virtual3fc();
    virtual void virtual400();
    virtual void virtual404();
    virtual void virtual408();
    virtual void virtual40c();
    virtual void virtual410();
    virtual void virtual414();
    virtual void virtual418();
    virtual void virtual41c();
    virtual void virtual420();
    virtual void virtual424();
    virtual void virtual428();
    virtual void virtual42c();
    virtual void virtual430();
    virtual void virtual434();
    virtual void virtual438();
    virtual void virtual43c();
    virtual void virtual440();
    virtual int CreatureDamage();
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
    ValuesHit values;
    bool Sneaking();
    float Scale();
    bool Teammate();
};
struct ExtraHit
{
    int type;
    bool active;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char count;
};
struct BooleanFloatQuery
{
    ActorHit* actor;
    ActorHit* target;
    int unk08;
    int kind;
    int unk10;
    float damage;
    int unk18;
    float secondary;
    int unk20;
    int unk24;
    int unk28;
    float special;
    WeaponHit* weapon;
    float condition;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    ExtraHit* extra;
    bool Flag(unsigned int);
    void Multiply(float);
    void Finish();
    void Update(int);
    void Finalize(int);
    void Complete();
};
struct SettingHit
{
    float* Float();
};
extern SettingHit DAT_011cf5d0, DAT_011d0424, DAT_011d12d8, DAT_011d07b4;
extern ActorHit* playerHit;
int HitGroup(unsigned short);
float HitMultiplier(int, int);
void UnarmedDamage(ValuesHit*, bool, float*, float*);
float SpecialDamage(ActorHit*);
// Fills the hit record from actor, target and weapon, computes damage and kind, then finalizes and completes it.
// @fnv 0x009b5170
void __cdecl InitHitData(BooleanFloatQuery* data, ActorHit* actor, ActorHit* target, RefHit* pWeaponRef,
                         unsigned char apply)
{
    if (!data)
        return;
    data->actor = actor;
    data->target = target;
    data->weapon = pWeaponRef && pWeaponRef->Base()->FormType() == 40 ? pWeaponRef->Base() : 0;
    data->condition = pWeaponRef ? pWeaponRef->Condition(1) : 1.0f;
    bool scale = data->extra ? data->extra->active : true;
    if (data->extra && !data->extra->active && (!data->weapon || data->weapon->IsSpecial()))
        scale = true;
    unsigned short group = actor->Anim()->Group(4);
    int kind = HitGroup(group);
    if (scale)
    {
        if (data->weapon)
        {
            float mult = 1.0f;
            data->kind = data->weapon->WeaponKind();
            if (!actor->Creature() && !actor->Sneaking())
                mult = apply ? HitMultiplier(actor->values.Value(data->kind), kind) : 1.0f;
            data->damage = pWeaponRef->Damage(actor ? &actor->values : 0, mult, 0);
            if (data->extra && data->extra->count > 1 && data->Flag(4096))
                data->damage *= data->extra->count / data->weapon->AmmoPerShot();
            if (data->extra && data->weapon->IsSpecial() && data->weapon->Automatic())
                data->damage *= *DAT_011cf5d0.Float();
            if (data->extra)
            {
                if (data->extra->type == 16)
                    data->damage *= data->weapon->DamageMult();
                else if (data->extra->type == 17)
                    data->damage *= *DAT_011d0424.Float();
                else if (data->extra->type == 20)
                    data->damage *= *DAT_011d12d8.Float();
                else if (data->extra->type == 21)
                    data->damage *= *DAT_011d07b4.Float();
            }
        }
        else if (actor->Creature())
            data->damage = (float)actor->CreatureDamage();
        else
        {
            UnarmedDamage(actor ? &actor->values : 0, target ? target->TargetFlag() : false, &data->damage,
                          &data->secondary);
            data->kind = 45;
            float fUnarmedMult = apply ? HitMultiplier(actor->values.Value(data->kind), kind) : 1.0f;
            if (!actor->Sneaking())
                data->Multiply(fUnarmedMult);
        }
        if (actor)
            data->damage *= actor->Scale();
        if (actor && actor->SpecialActor() && data->weapon && !data->weapon->IsMelee())
            data->special = SpecialDamage(data->actor);
        if (actor->Teammate())
        {
            float bonus = playerHit->values.FloatValue(8);
            float value = 1.0 + bonus * (double)0.05f;
            data->damage *= value;
        }
        data->Finish();
        data->Update(0);
    }
    data->Finalize(0);
    if (scale)
        data->Complete();
}

struct Pt9b : public NiPoint3
{
    Pt9b operator-(const NiPoint3& rhs) const;
    Pt9b& operator+=(const NiPoint3& rhs);
};

Pt9b __cdecl operator*(float f, const Pt9b& pt);

struct Actor9b58d0
{
    virtual void vf000();
    virtual void vf001();
    virtual void vf002();
    virtual void vf003();
    virtual void vf004();
    virtual void vf005();
    virtual void vf006();
    virtual void vf007();
    virtual void vf008();
    virtual void vf009();
    virtual void vf010();
    virtual void vf011();
    virtual void vf012();
    virtual void vf013();
    virtual void vf014();
    virtual void vf015();
    virtual void vf016();
    virtual void vf017();
    virtual void vf018();
    virtual void vf019();
    virtual void vf020();
    virtual void vf021();
    virtual void vf022();
    virtual void vf023();
    virtual void vf024();
    virtual void vf025();
    virtual void vf026();
    virtual void vf027();
    virtual void vf028();
    virtual void vf029();
    virtual void vf030();
    virtual void vf031();
    virtual void vf032();
    virtual void vf033();
    virtual void vf034();
    virtual void vf035();
    virtual void vf036();
    virtual void vf037();
    virtual void vf038();
    virtual void vf039();
    virtual void vf040();
    virtual void vf041();
    virtual void vf042();
    virtual void vf043();
    virtual void vf044();
    virtual void vf045();
    virtual void vf046();
    virtual void vf047();
    virtual void vf048();
    virtual void vf049();
    virtual void vf050();
    virtual void vf051();
    virtual void vf052();
    virtual void vf053();
    virtual void vf054();
    virtual void vf055();
    virtual void vf056();
    virtual void vf057();
    virtual void vf058();
    virtual void vf059();
    virtual void vf060();
    virtual void vf061();
    virtual void vf062();
    virtual void vf063();
    virtual void vf064();
    virtual void vf065();
    virtual void vf066();
    virtual void vf067();
    virtual void vf068();
    virtual void vf069();
    virtual void vf070();
    virtual void vf071();
    virtual void vf072();
    virtual void vf073();
    virtual void vf074();
    virtual void vf075();
    virtual void vf076();
    virtual void vf077();
    virtual void vf078();
    virtual void vf079();
    virtual void vf080();
    virtual void vf081();
    virtual void vf082();
    virtual void vf083();
    virtual void vf084();
    virtual void vf085();
    virtual void vf086();
    virtual void vf087();
    virtual void vf088();
    virtual void vf089();
    virtual void vf090();
    virtual void vf091();
    virtual void vf092();
    virtual void vf093();
    virtual void vf094();
    virtual void vf095();
    virtual void vf096();
    virtual void vf097();
    virtual void vf098();
    virtual void vf099();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual Pt9b* GetPos();
    int __thiscall FUN_008b3d70(Pt9b a, Pt9b b);
    int __thiscall FUN_008b3ef0(int a);
};

struct Struct9b58d0
{
    int unk00;
    Pt9b pt1;
    Pt9b pt2;
};

struct Thing9b58d0 : public FUN_009b5a30_Class
{
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    Pt9b pt38;
    Pt9b pt44;
};

// @fnv 0x009b58d0
void __cdecl FUN_009b58d0(Thing9b58d0* pThing, int iUnused, Actor9b58d0* pActor, float a4, Struct9b58d0* a5)
{
    if (!pThing)
        return;

    pThing->vfn_00 = 0;
    pThing->vfn_04 = pActor;
    pThing->f14 = a4;
    pThing->f18 = a4;

    Pt9b pt = *pActor->GetPos();
    pt += 0.25f * (a5->pt1 - *pActor->GetPos());
    pt.z = a5->pt1.z;

    pThing->pt38 = pt;
    pThing->pt44 = a5->pt2;

    if (pActor)
    {
        int iResult = pActor->FUN_008b3d70(a5->pt1 - a5->pt2, a5->pt1);
        pThing->vfn_10 = (void*)pActor->FUN_008b3ef0(iResult);
    }

    pThing->FUN_009b5a30(1);
    pThing->ApplyDamageEffects();
}

struct DecompTagByte
{
    bool value;
};

// Builds a zero-initialized DecompTagByte and passes its value to FUN_009b2e90 along with a and b.
// @fnv 0x009b2e00
void __cdecl FUN_009b2e00(void* a, int aiValue)
{
    DecompTagByte tag = {};
    FUN_009b2e90(a, aiValue, tag.value);
}

struct BoundReader
{
    unsigned int rawValue;
    float __thiscall FUN_006a7f50();
};
struct CombatRange
{
    int m_uiContentCount;
    int m_pOwnerObject;
    BoundReader m_lower;
    BoundReader m_upper;
    bool __thiscall Contains(float value);
};
// Returns true when value lies between the lower and upper bounds obtained from m_lower and m_upper.
// @fnv 0x009a4960
bool CombatRange::Contains(float value)
{
    return m_lower.FUN_006a7f50() <= value && value <= m_upper.FUN_006a7f50();
}

struct FUN_009a95f0_cls
{
    unsigned char m_b0;
    unsigned char unk;
    unsigned char m_b2;
    unsigned char m_b3;
    float FUN_009a95f0();
};
// Returns (m_b2 / DAT_01011590 + m_b3) * m_b0 as a float.
// @fnv 0x009a95f0
float FUN_009a95f0_cls::FUN_009a95f0()
{
    return ((float)m_b2 / DAT_01011590 + (float)m_b3) * (float)m_b0;
}

extern const char* DAT_011a5700[];
extern const char* DAT_0118a8a8[];
extern const char* DAT_011a5768[];
// @fnv 0x009aa1b0
int __cdecl FUN_009aa1b0(int a, int iIndex)
{
    switch (a)
    {
    case 1:
    case 2:
    case 13:
        return (int)DAT_011a5700[iIndex];
    case 10:
    case 11:
    case 12:
        return (int)DAT_0118a8a8[iIndex];
    case 18:
        return (int)DAT_011a5768[iIndex];
    default:
        return (int)(iIndex ? "True" : "False");
    }
}

struct ExtendedTargetRef : TargetRef
{
    virtual void vfunc_308();
    virtual void vfunc_30c();
    virtual void vfunc_310();
    virtual void vfunc_314();
    virtual void vfunc_318();
    virtual void vfunc_31c();
    virtual void vfunc_320();
    virtual void vfunc_324();
    virtual void vfunc_328();
    virtual void vfunc_32c();
    virtual void vfunc_330();
    virtual void vfunc_334();
    virtual void vfunc_338();
    virtual void vfunc_33c();
    virtual void vfunc_340();
    virtual void vfunc_344();
    virtual void vfunc_348();
    virtual void vfunc_34c();
    virtual void vfunc_350();
    virtual void vfunc_354();
    virtual void vfunc_358();
    virtual void vfunc_35c();
    virtual void vfunc_360();
    virtual void vfunc_364();
    virtual void vfunc_368();
    virtual void vfunc_36c();
    virtual void vfunc_370();
    virtual void vfunc_374();
    virtual void vfunc_378();
    virtual void vfunc_37c();
    virtual void vfunc_380();
    virtual void vfunc_384();
    virtual void vfunc_388();
    virtual void vfunc_38c();
    virtual void vfunc_390();
    virtual void vfunc_394();
    virtual void vfunc_398();
    virtual void vfunc_39c();
    virtual void vfunc_3a0();
    virtual void vfunc_3a4();
    virtual void vfunc_3a8();
    virtual void vfunc_3ac();
    virtual void vfunc_3b0();
    virtual void vfunc_3b4();
    virtual void vfunc_3b8();
    virtual void vfunc_3bc();
    virtual void vfunc_3c0();
    virtual void vfunc_3c4();
    virtual void vfunc_3c8();
    virtual void vfunc_3cc();
    virtual void vfunc_3d0();
    virtual void vfunc_3d4();
    virtual void vfunc_3d8();
    virtual void vfunc_3dc();
    virtual void vfunc_3e0();
    virtual void vfunc_3e4();
    virtual void vfunc_3e8();
    virtual void vfunc_3ec();
    virtual void vfunc_3f0();
    virtual void vfunc_3f4();
    virtual void vfunc_3f8();
    virtual void vfunc_3fc();
    virtual void vfunc_400();
    virtual void vfunc_404();
    virtual void vfunc_408();
    virtual void vfunc_40c();
    virtual void vfunc_410();
    virtual void vfunc_414();
    virtual void ApplyPosition(TargetRef* owner, MatchPoint position, float time);
};
extern S_9a54a0_Setting DAT_011d1188;
struct SceneObject : MatchContext
{
    void FUN_009b0d70(TargetRef* object, float timestamp);
};
// If object and its FUN_008d8520() result are non-null and timestamp exceeds the setting value, applies Position() at time 0.0f to the extended target ref.
// @fnv 0x009b0d70
void SceneObject::FUN_009b0d70(TargetRef* object, float timestamp)
{
    if (object && object->FUN_008d8520() && timestamp > *DAT_011d1188.FUN_00403e20())
    {
        static_cast<ExtendedTargetRef*>(object->FUN_008d8520())->ApplyPosition(object, Position(), 0.0f);
    }
}

struct Tgt_9bd5c0
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
    virtual bool IsValid();
    int FUN_004fd4f0();
};
struct Base_9bd5c0
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
    virtual void SetExtra(FUN_0066e010* extra);
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
    virtual void Refresh();
    void FUN_005de0a0(int flag, int on);
    void FUN_00420ba0(int value);
    void FUN_009bd760(float value);
};
struct FUN_009b4020 : Base_9bd5c0
{
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
    FUN_009b4020(Tgt_9bd5c0* a, Tgt_9bd5c0* b, int c, NiPoint3 pos, float f1, float f2);
};
extern S_9a54a0_Setting DAT_011ce6cc;

// @fnv 0x009bd5c0
Base_9bd5c0* __cdecl FUN_009bd5c0(Tgt_9bd5c0* a1, Tgt_9bd5c0* a2, int a3, int a4)
{
    Base_9bd5c0* obj = 0;
    if (a1)
    {
        switch (a1->FUN_004fd4f0())
        {
        case 0x20000:
            obj = new FUN_009b4020(a1, a2, a4, *(NiPoint3*)&DAT_011f426c, 0.0f, 0.0f);
            break;
        }
    }
    if (obj)
    {
        if (a2 && a2->IsValid())
        {
            obj->SetExtra(new FUN_0066e010((TargetRef*)a2));
        }
        obj->FUN_005de0a0(0x400, 1);
        obj->FUN_00420ba0(a3);
        obj->Refresh();
        obj->FUN_009bd760(*DAT_011ce6cc.FUN_00403e20());
    }
    return obj;
}

struct CTStamp
{
    int m_uiCommandId;
    CTStamp();
    CTStamp(float afValue);
};
struct CTList
{
    int unk00;
    int unk04;
    int unk08;
    CTList(int value);
    ~CTList();
};
struct CTPoint
{
    float x, y, z;
    CTPoint();
};

extern float DAT_0108e2b0;
struct TimeoutTimer
{
    int unk00;
    float unk04;
    CTStamp unk08;
    CTStamp unk0c;
    float unk10;
    CTList unk14;
    CTPoint unk20;
    CTStamp unk2c;
    TimeoutTimer(int a1, float a2, float a3, float a4, float a5);
    void FUN_009a4690(int a1, float a2, float a3, float a4, float a5, bool a6);
};
// @fnv 0x009a44e0
TimeoutTimer::TimeoutTimer(int a1, float a2, float a3, float a4, float a5) : unk14(0)
{
    FUN_009a4690(a1, a2, a3, a4, a5, false);
    unk14.unk04 = 0;
    unk14.unk08 = 0;
    unk20 = *(CTPoint*)&DAT_011f426c;
    CTStamp kStamp(-DAT_0108e2b0);
    unk2c = kStamp;
}

class AnimIdle
{
  public:
    void IncRefCount();
    void DecRefCount();
};

namespace FUN_004f15a0 {
class TESForm
{
  public:
    virtual ~TESForm();
    void SetFormType(ENUM_FORM_ID eType);
    int unk04, unk08, unk0C, unk10, unk14;
};
}

namespace hk9AAF {
class TESChildCell
{
  public:
    virtual void vfn_00();
};
}

namespace FUN_009bbc70 {
class Projectile : public FUN_004f15a0::TESForm, public hk9AAF::TESChildCell
{
  public:
    Projectile(bool bTempRef);
    virtual ~Projectile();
    int unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48;
    int unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78;
    int unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8;
    int unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8;
    int unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC, unk100, unk104, unk108;
    int unk10C, unk110, unk114, unk118, unk11C, unk120, unk124, unk128, unk12C, unk130, unk134, unk138;
    int unk13C, unk140, unk144, unk148, unk14C;
};
}

namespace FUN_009aaff0 {
class ContinuousBeamProjectile : public FUN_009bbc70::Projectile
{
  public:
    ContinuousBeamProjectile(bool bTempRef);
    virtual ~ContinuousBeamProjectile();

    NiPointer<AnimIdle> m_spUnk150;
};

// Constructs a ContinuousBeamProjectile, sets its form type to 0x69, and initializes m_spUnk150 to null.
// @fnv 0x009aaff0
ContinuousBeamProjectile::ContinuousBeamProjectile(bool bTempRef) : FUN_009bbc70::Projectile(bTempRef)
{
    SetFormType((ENUM_FORM_ID)0x69);
    m_spUnk150 = 0;
}
}

struct FUN_009ae540
{
    float m0;
    float m4;
    float m8;
    float mc;
    FUN_009ae540(float*);
};
// @fnv 0x009ae540
FUN_009ae540::FUN_009ae540(float* a)
{
    m0 = a[0];
    m4 = a[1];
    m8 = a[2];
    mc = 0.0f;
}

namespace fnv_009b5a30 {
struct HitActor;
struct HitWeapon;
struct HitSetting
{
    const float* FUN_00403e20();
};
extern HitSetting DAT_011ced4c, DAT_011d1020, DAT_011d0be4, DAT_011cf0fc, DAT_011ce9f0;
struct HitMode
{
    bool FUN_00525430();
};
extern HitMode DAT_011f2250;
struct HitAmmo
{
    int FUN_00923000();
};
struct HitEntry
{
    HitWeapon* FUN_0044ddc0();
    bool HasEffect(int);
};
struct HitProcess
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
    virtual HitEntry* Weapon();
};
struct HitValues
{
    virtual void v0();
    virtual void v1();
    virtual int Base(int);
    virtual float Current(int);
    float FUN_0066ef50(int);
};
struct HitMagic
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool Invulnerable();
    int unk04, unk08, unk0c;
};
struct HitActor
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
    virtual bool IsActor();
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
    virtual bool Dead(int);
    virtual void v140();
    virtual bool Creature();
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
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    HitMagic magic;
    HitValues values;
    bool FUN_00566950();
    bool FUN_00894d60();
    HitProcess* FUN_008d8520();
    void SetFieldE28(float);
    bool FUN_008a16d0();
};
struct HitClip
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned short Count();
};
struct HitWeapon
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
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    HitClip clip;
    HitAmmo* FUN_00525980(HitActor*);
    bool FUN_006450c0();
    int FUN_00446390();
    unsigned char FUN_00525b20(int, int, HitActor*);
    bool FUN_00524b40();
    int FUN_009b6600();
};
extern HitActor* DAT_011dea3c;
extern HitWeapon* DAT_011ca278;
extern const float DAT_01016410;
extern const double DAT_01017a40, DAT_0103c7c8, DAT_01012060, DAT_01012070;
double FUN_0040ebd0(float, float);
double FUN_00404010(float, float);
float ComputeAmmoEffectValue(int, int, float);
float FUN_006462e0(float, float);
bool IsTargetInCone(HitActor*, HitActor*, int);
float FUN_006463a0(int);
HitWeapon* LookupFormByID(int);
void FUN_005e58f0(int, HitActor*, HitWeapon*, HitActor*, float*);
void FUN_005e58f0(int, HitActor*, HitActor*, HitWeapon*, float*);
int FUN_009b65d0(unsigned short, int);
void FUN_00709c60(bool);
void FUN_00709c80(bool);
void AddTimedEntry(HitActor*, int);
struct HitDamage
{
    HitActor* attacker;
    HitActor* target;
    HitActor* projectile;
    int unk0c, unk10;
    float damage, original, critical, unk20, blocking, resisted, unk2c;
    HitWeapon* weapon;
    void FUN_00407e00(int, bool);
    void FUN_009b5a30(bool);
};
// @fnv 0x009b5a30
void HitDamage::FUN_009b5a30(bool skipBlock)
{
    if (!target || !target->IsActor())
        return;
    if (target->magic.Invulnerable())
    {
        original = 0.0f;
        damage = 0.0f;
        critical = 0.0f;
        return;
    }
    original = damage;
    float minimumDamage8 = damage * *DAT_011ced4c.FUN_00403e20();
    if (weapon)
        critical = ComputeAmmoEffectValue(5, weapon->FUN_00525980(attacker) ? weapon->FUN_00525980(attacker)->FUN_00923000() : 0,
                                critical);
    float resistanceVal = FUN_0040ebd0(target->values.Current(18), DAT_01016410) / DAT_01017a40;
    if (target->FUN_00566950())
    {
        float endurance = DAT_011dea3c->values.FUN_0066ef50(8);
        float multiplier9 = 1.0f + endurance * DAT_0103c7c8;
        resistanceVal *= multiplier9;
    }
    if (weapon)
        resistanceVal = ComputeAmmoEffectValue(
            1, weapon->FUN_00525980(attacker) ? weapon->FUN_00525980(attacker)->FUN_00923000() : 0, resistanceVal);
    float maxResistance8 = *DAT_011d1020.FUN_00403e20() / DAT_01017a40;
    if (resistanceVal > maxResistance8)
        resistanceVal = maxResistance8;
    resisted = critical > DAT_01012060 ? 0.0f : FUN_006462e0(damage, resistanceVal);
    damage = (1.0f - resistanceVal) * damage;
    float threshold = FUN_00404010(target->values.Current(76), 0.0f);
    if (target->FUN_00566950())
    {
        float endurance4 = DAT_011dea3c->values.FUN_0066ef50(8);
        float multiplier2 = 1.0f + endurance4 * DAT_0103c7c8;
        threshold *= multiplier2;
    }
    float originalThreshold = threshold;
    if (weapon)
        threshold = ComputeAmmoEffectValue(2, weapon->FUN_00525980(attacker) ? weapon->FUN_00525980(attacker)->FUN_00923000() : 0,
                                 threshold);
    if (!skipBlock)
    {
        bool canBlock2 = target->Creature() ? false : target->FUN_00894d60();
        bool unarmed = !target->FUN_008d8520()->Weapon() && canBlock2;
        if (canBlock2 && IsTargetInCone(target, projectile ? projectile : attacker, 0))
        {
            HitWeapon* blockWeapon2 =
                target->FUN_008d8520()->Weapon() ? target->FUN_008d8520()->Weapon()->FUN_0044ddc0() : 0;
            FUN_00407e00(1, true);
            if (DAT_011dea3c == target)
                DAT_011dea3c->SetFieldE28(*DAT_011d0be4.FUN_00403e20());
            bool power = false;
            if (blockWeapon2 && target->FUN_008a16d0())
                power = true;
            int skill = 0;
            if (weapon && blockWeapon2 && (blockWeapon2->FUN_00446390() == 2 || blockWeapon2->FUN_00446390() == 1))
                skill = target->values.Base(38);
            else if (!weapon || (blockWeapon2 && blockWeapon2->FUN_00446390() == 0))
                skill = target->values.Base(45);
            if (unarmed && ((weapon && !weapon->FUN_006450c0()) || projectile))
                blocking = 0.0f;
            else
                blocking = FUN_006463a0(skill);
            if (blocking > DAT_01012060)
                threshold = threshold + blocking;
            FUN_00407e00(2, power);
        }
    }
    float penetration = 0.0f;
    if (attacker)
    {
        if (!weapon)
            weapon = LookupFormByID(500);
        FUN_005e58f0(58, attacker, weapon, target, &penetration);
    }
    float bonus9 = 0.0f;
    if (target)
        FUN_005e58f0(56, target, attacker, weapon ? weapon : DAT_011ca278, &bonus9);
    threshold = threshold - penetration + bonus9;
    bool negatedTmp = false;
    if (originalThreshold > DAT_01012060 && threshold <= DAT_01012060)
        negatedTmp = true;
    threshold = FUN_00404010(0.0f, threshold);
    if (attacker && attacker->FUN_008d8520() && attacker->FUN_008d8520()->Weapon() &&
        attacker->FUN_008d8520()->Weapon()->HasEffect(12) && threshold > DAT_01012060)
        threshold /= weapon->FUN_00525b20(1, 0, attacker);
    if (weapon && weapon->FUN_00524b40() && weapon->FUN_006450c0())
    {
        float rounds = (float)FUN_009b65d0(weapon->clip.Count(), 1);
        float fraction = 1.0f - threshold / rounds;
        fraction = FUN_00404010(fraction, 0.0f);
        damage = damage * fraction;
    }
    else
        damage = damage - threshold;
    if (weapon)
        damage = ComputeAmmoEffectValue(0, weapon->FUN_00525980(attacker) ? weapon->FUN_00525980(attacker)->FUN_00923000() : 0,
                              damage);
    if (weapon)
        FUN_005e58f0(0, attacker, weapon, target, &damage);
    if (critical <= DAT_01012060)
    {
        float absorbed = FUN_0040ebd0(threshold, damage - minimumDamage8) * *DAT_011cf0fc.FUN_00403e20();
        resisted = resisted + absorbed;
    }
    if (damage < minimumDamage8)
    {
        damage = minimumDamage8;
        if (target == DAT_011dea3c)
            FUN_00709c60(negatedTmp);
        else if (attacker == DAT_011dea3c && !target->Dead(0))
            FUN_00709c80(negatedTmp);
        if (attacker && attacker->FUN_00566950())
            AddTimedEntry(attacker, 9);
    }
    else if (negatedTmp)
    {
        if (target == DAT_011dea3c)
            FUN_00709c60(negatedTmp);
        else if (attacker == DAT_011dea3c && !target->Dead(0))
            FUN_00709c80(negatedTmp);
    }
    if (weapon && weapon->FUN_009b6600() != -1)
    {
        float specific = FUN_0040ebd0(target->values.Current(weapon->FUN_009b6600()), DAT_01016410) / DAT_01017a40;
        if (specific > DAT_01012060 && specific <= DAT_01012070)
            damage = (1.0f - specific) * damage;
    }
    if (critical > DAT_01012060 && original > DAT_01012060)
    {
        float proportion = damage / original;
        critical = critical * proportion;
    }
    if (target == DAT_011dea3c && DAT_011f2250.FUN_00525430())
    {
        damage = damage * *DAT_011ce9f0.FUN_00403e20();
        original = original * *DAT_011ce9f0.FUN_00403e20();
        critical = critical * *DAT_011ce9f0.FUN_00403e20();
        unk20 = unk20 * *DAT_011ce9f0.FUN_00403e20();
        resisted = resisted * *DAT_011ce9f0.FUN_00403e20();
        unk2c = unk2c * *DAT_011ce9f0.FUN_00403e20();
    }
}
}  // namespace fnv_009b5a30

struct CombatWorldStateArrayValues : FUN_009aa470_Class
{
    int values[20];
    int specifiedVariables[3];
};

// Zeroes the 0x50 byte object and the specifiedVariables array of the CombatWorldStateArrayValues view.
// @fnv 0x009aa4b0
void FUN_009aa470_Class::FUN_009aa4b0()
{
    memset(this, 0, 0x50);
    memset(static_cast<CombatWorldStateArrayValues*>(this)->specifiedVariables, 0, 0xc);
}
