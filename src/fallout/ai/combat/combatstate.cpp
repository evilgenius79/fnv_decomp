// fallout/ai/combat/combatstate.cpp: CombatState, Host, Holder, NavMeshSearchLOSArray and more (141 functions)

#include "combatstate_decls.h"
// Gets or adds the InventoryChanges for this reference and returns the count of the given object in it, or 0 if none.
// @fnv 0x00575610
int CombatState::GetInventoryItemCount(TESForm* object)
{
    struct
    {
        int result;
        InventoryChanges* inventory;
    } locals;
    locals.result = 0;
    locals.inventory = InventoryChanges::GetOrAddInventoryChanges((TESObjectREFR*)this);
    if (locals.inventory)
        locals.result = locals.inventory->GetObjectCount(object);
    return locals.result;
}
// If los is set and its check passes, calls los->FUN_008be220(this); otherwise calls Clear().
// @fnv 0x008be1b0
void CombatState::ProcessCoverLOSResult()
{
    if (los && los->FUN_00884920())
        los->FUN_008be220(this);
    else
        Clear();
}

// @fnv 0x0064bf90
void CombatState::UpdateCombatStateData(int state, float* pfX, float* pfY, float delta)
{
    timer -= delta;
    if (timer <= 0.0)
    {
        switch (state)
        {
        case -1:
        case 0:
        case 8:
        case 11:
            if (RandomBoolean(DAT_01017870))
            {
                timer = RandomFloat(DAT_010162c0, DAT_01017718);
                offsetX = 0.0f;
                offsetY = 0.0f;
            }
            else
            {
                timer = RandomFloat(DAT_01016248, DAT_01016088);
                offsetY = RandomFloat(DAT_011d5944.FUN_00450410(), DAT_011d57d0.FUN_00450410());
                offsetX = RandomFloat(DAT_011d5968.FUN_00450410(), DAT_011d5750.FUN_00450410());
            }
            break;
        case 2:
        case 4:
            if (RandomBoolean(DAT_01017870))
            {
                timer = RandomFloat(DAT_01017718, DAT_0101e570);
                offsetX = 0.0f;
                offsetY = 0.0f;
            }
            else
            {
                timer = RandomFloat(DAT_01016248, DAT_01016088);
                offsetY = RandomFloat(DAT_011d58e8.FUN_00450410(), DAT_011d5874.FUN_00450410());
                offsetX = RandomFloat(DAT_011d5794.FUN_00450410(), DAT_011d5988.FUN_00450410());
            }
            break;
        case 3:
        case 9:
        case 12:
            timer = RandomFloat(DAT_010162c0, DAT_01017718);
            if (RandomBoolean(DAT_01017870))
            {
                offsetX = 0.0f;
                offsetY = 0.0f;
            }
            else
            {
                offsetY = RandomFloat(DAT_011d581c.FUN_00450410(), DAT_011d57b8.FUN_00450410());
                offsetX = RandomFloat(DAT_011d5930.FUN_00450410(), DAT_011d5894.FUN_00450410());
            }
            break;
        case 1:
        case 6:
            timer = RandomFloat(DAT_01016248, DAT_01016088);
            offsetY = 0.0f;
            if (RandomBoolean(DAT_01016248))
                offsetX = 0.0f;
            else
                offsetX = RandomFloat(DAT_011d5868.FUN_00450410(), DAT_011d58d8.FUN_00450410());
            break;
        case 5:
            if (RandomBoolean(DAT_01017870))
            {
                timer = RandomFloat(DAT_01017718, DAT_0101e570);
                offsetX = 0.0f;
                offsetY = 0.0f;
            }
            else
            {
                timer = RandomFloat(DAT_01016248, DAT_01016088);
                offsetY = RandomFloat(DAT_011d58c4.FUN_00450410(), DAT_011d5834.FUN_00450410());
                offsetX = RandomFloat(DAT_011d585c.FUN_00450410(), DAT_011d5908.FUN_00450410());
            }
            break;
        }
    }
    *pfX += offsetX;
    *pfY += offsetY;
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CombatCoverPointData
{
    void Copy(void*);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    bool IsHideCover();
    bool IsCrouchCover();
    bool IsStandCover();
    bool IsLedgeCover();
    bool IsValidCover();
    unsigned char GetCoverHeight();
    bool IsReserved();
    void SetReserved(bool);
    bool IsDirty();
    void SetDirty(bool);
    void* __vecDelDtor(unsigned int);
    bool m_bDataDirty;
    bool bReserved;
    unsigned char m_ucCoverHeight;
    char _pad_3[1];
    int iLocation;
    char m_cCoverData[12];
    char CombatCoverPoint[84];
    unsigned int m_uiCoverFlags;
    unsigned int m_uiLocationFlags;
    char m_cTrailingData[6];
    char _pad_76[2];
};
typedef char _sizecheck_CombatCoverLocation[sizeof(CombatCoverPointData) == 120 ? 1 : -1];
struct FUN_005dc960_shell : public CombatCoverPointData
{
    bool FUN_005dc960();
};

// @fnv 0x005dc960
bool FUN_005dc960_shell::FUN_005dc960()
{
    return bReserved;
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CoordinateTriple;
struct TESForm;
struct TESObjectREFR;
struct CombatAvoidanceSphere
{
    void Copy(void*);
    void SetLocation(int);
    void SetPoint(void*, TESForm*);
    void SetTargetForm(TESForm*);
    void AssignReference(TESObjectREFR*);
    void SetRadius(float);
    void SetFlag(unsigned int, bool);
    void SetWorldLocation(void*);
    void* GetPoint();
    TESObjectREFR* GetRef();
    TESForm* GetReferenceSpace();
    CoordinateTriple* GetWorldForwardVector();
    int GetLocation();
    float GetRadius();
    bool GetFlag(unsigned int);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    void InitLoadGame(BGSLoadFormBuffer*);
    void IsWithinSphere();
    char m_cBuffer[16];
    TESObjectREFR* pRef;
    int iLocation;
    float fRadius;
    unsigned int iFlags;
};
typedef char _sizecheck_CombatLocation[sizeof(CombatAvoidanceSphere) == 32 ? 1 : -1];
struct FUN_00819a50_shell : public CombatAvoidanceSphere
{
    void FUN_00819a50(float);
};

// @fnv 0x00819a50
void FUN_00819a50_shell::FUN_00819a50(float afRadius)
{
    fRadius = afRadius;
}

struct FUN_00997c10_shell
{
    void __thiscall FUN_009975c0();
    void __thiscall FUN_00997c10();
};

// @fnv 0x00997c10
void __thiscall FUN_00997c10_shell::FUN_00997c10()
{
    ((FUN_00997c10_shell*)((char*)this + 0x128))->FUN_009975c0();
}

struct FUN_009989f0_shell
{
    unsigned char __thiscall GetByteAtOffsetC7();
};

// @fnv 0x009989f0
unsigned char __thiscall FUN_009989f0_shell::GetByteAtOffsetC7()
{
    return ((unsigned char*)this)[0xc7];
}

struct FUN_00998a10_shell
{
    unsigned char field_c5;
    unsigned char GetFieldC5();
};

// @fnv 0x00998a10
unsigned char FUN_00998a10_shell::GetFieldC5()
{
    return *(unsigned char*)((char*)this + 0xc5);
}

struct CombatTargetMapLock
{
    void AcquireLock();
};

struct FUN_0099c210_shell
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    CombatTargetMapLock m_lock;
    void LockCombatTargetMap();
};

// @fnv 0x0099c210
void __thiscall FUN_0099c210_shell::LockCombatTargetMap()
{
    m_lock.AcquireLock();
}

struct FUN_009a0680_shell
{
    void __thiscall ClearAndDeletePointer();
};

// Deletes the pointer stored at offset 0x18c and sets that field to null.
// @fnv 0x009a0680
void __thiscall FUN_009a0680_shell::ClearAndDeletePointer()
{
    void* ptr = *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x18c);
    operator delete(ptr);
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x18c) = 0;
}

void __cdecl operator delete(void*);

struct FUN_009a0a40_shell
{
    char pad[0xc4];
    void* field_c4;
};

// Deletes the pointer stored at field_c4 and sets it to null.
// @fnv 0x009a0a40
void __fastcall FreeAndClearFieldC4(FUN_009a0a40_shell* thisp)
{
    void* p = thisp->field_c4;
    operator delete(p);
    thisp->field_c4 = 0;
}

struct CoordinateTriple
{
    void FUN_00527b70(void*);
};

struct CombatTargetTimestamp
{
    void SaveTimeStamp(void*);
};

struct FUN_009a2d80_shell
{
    void FUN_009a2d80(void* buffer);
};

// Calls FUN_00527b70 on this and SaveTimeStamp on the object at offset 0x10, passing buffer to both.
// @fnv 0x009a2d80
void FUN_009a2d80_shell::FUN_009a2d80(void* buffer)
{
    reinterpret_cast<CoordinateTriple*>(this)->FUN_00527b70(buffer);
    reinterpret_cast<CombatTargetTimestamp*>(reinterpret_cast<char*>(this) + 0x10)->SaveTimeStamp(buffer);
}

struct GlobalObject_00869f00
{
    int* m_ptr;
    void Clear(bool);
};

extern int DAT_0108e068;

// @fnv 0x009a3410
void __fastcall FUN_009a3410(GlobalObject_00869f00* this_)
{
    this_->m_ptr = &DAT_0108e068;
    this_->Clear(true);
}

namespace fnv_009a35f0 {
struct GlobalObject_00869f00
{
    int m_Data;
    void __thiscall Clear(bool);
};

extern int DAT_0108e090;

struct FUN_009a35f0_shell : GlobalObject_00869f00
{
    void FUN_009a35f0();
};

// @fnv 0x009a35f0
void FUN_009a35f0_shell::FUN_009a35f0()
{
    m_Data = reinterpret_cast<int>(&DAT_0108e090);
    this->Clear(true);
}
}  // namespace fnv_009a35f0

struct FUN_006d3280_s
{
    bool a, b, c, d, e, f;
    FUN_006d3280_s* ClearFlags();
};
// Sets all six boolean flags of this object to false and returns this.
// @fnv 0x006d3280
FUN_006d3280_s* FUN_006d3280_s::ClearFlags()
{
    a = false;
    b = false;
    c = false;
    d = false;
    e = false;
    f = false;
    return this;
}

void _Deallocate(void*);
struct FUN_006d3370_s
{
    void FUN_006d33a0();
    FUN_006d3370_s* FUN_006d3370(unsigned int flags);
};
// Calls FUN_006d33a0, then frees this with _Deallocate if flags has bit 1 set, and returns this.
// @fnv 0x006d3370
FUN_006d3370_s* FUN_006d3370_s::FUN_006d3370(unsigned int flags)
{
    FUN_006d33a0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct NavMeshSearchLOSArray
{
    void* vfn_0;
    void* data;
    int size;
    int capacity;
    void FUN_006a8500();
    void FUN_006dbee0(void* data, int size);
    void FUN_006dbde0(bool freeStorage);
};

// @fnv 0x006dbde0
void NavMeshSearchLOSArray::FUN_006dbde0(bool freeStorage)
{
    if (data)
    {
        FUN_006dbee0(data, size);
        if (freeStorage)
        {
            FUN_006a8500();
            data = 0;
            capacity = 0;
        }
        size = 0;
    }
}

struct Elem
{
    int v[21];
    void FUN_006dc4d0(int);
};
struct FUN_006dbee0_s
{
    void FUN_006dbee0(Elem* arr, unsigned int count);
};
// Calls FUN_006dc4d0(0) on each of the count elements in arr.
// @fnv 0x006dbee0
void FUN_006dbee0_s::FUN_006dbee0(Elem* apElements, unsigned int count)
{
    for (unsigned int i = 0; i < count; i++)
        apElements[i].FUN_006dc4d0(0);
}

struct FUN_009052c0_shell
{
    void* FUN_009052c0(int index);
};
// @fnv 0x009052c0
void* FUN_009052c0_shell::FUN_009052c0(int index)
{
    return *(char**)((char*)this + 4) + index * 0x54;
}

struct Tile;
struct IMH
{
    Tile* FUN_00586150();
};
struct CombatLoc
{
    void FUN_0099ac20(int);
};
// @fnv 0x0097beb0
void FUN_0097beb0(IMH* pIMH, int iUnused, int iValue)
{
    CombatLoc* t = (CombatLoc*)pIMH->FUN_00586150();
    t->FUN_0099ac20(iValue);
}

struct V4
{
    int a, b, c, d;
};
struct FUN_0097ee60_shell
{
    V4 v;
    void AssignV4(V4* o);
};
// Copies the four-int V4 pointed to by o into the shell's v member.
// @fnv 0x0097ee60
void FUN_0097ee60_shell::AssignV4(V4* apValue)
{
    v = *apValue;
}

struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting413;
struct CombatTimeStampHelper
{
    float GetElapsedTime();
};
struct UnknownClass
{
    char _pad[0x94];
    CombatTimeStampHelper ts;
    bool IsElapsedTimeAtLeastSetting();
};
// Returns true if ts.GetElapsedTime() is greater than or equal to the value from originalRuntimeFloatSetting413.Float().
// @fnv 0x0097eee0
bool UnknownClass::IsElapsedTimeAtLeastSetting()
{
    return (ts.GetElapsedTime() >= *originalRuntimeFloatSetting413.Float() ? 1 : 0);
}

struct FUN_0097ef30_shell
{
    bool FUN_0097ef30();
};
// @fnv 0x0097ef30
bool FUN_0097ef30_shell::FUN_0097ef30()
{
    return 0 < *(unsigned int*)((char*)this + 0xd0);
}

namespace fnv_00997400 {
struct CoordinateTriple
{
    int a;
    int b;
    int c;
    int d;
};

struct TESObjectREFR_STUB
{
    CoordinateTriple FUN_00575650();
};

struct CombatAvoidanceSphere
{
    CoordinateTriple m_cBuffer;
    TESObjectREFR* pRef;
    void FUN_00997400(TESObjectREFR* apRef);
};

// @fnv 0x00997400
void CombatAvoidanceSphere::FUN_00997400(TESObjectREFR* apRef)
{
    pRef = apRef;
    m_cBuffer = reinterpret_cast<TESObjectREFR_STUB*>(pRef)->FUN_00575650();
}
}  // namespace fnv_00997400

struct WL16_997440
{
    int v0;
    int v4;
    int v8;
    int vC;
};
struct Ref_997440
{
    WL16_997440 FUN_00575650();
};
struct Outer_997440
{
    WL16_997440 loc;
    Ref_997440* pRef;
    void CopyRefValue();
};
// If pRef is set, copies the value returned by pRef->FUN_00575650() into loc.
// @fnv 0x00997440
void Outer_997440::CopyRefValue()
{
    if (pRef)
        loc = pRef->FUN_00575650();
}

extern float DAT_0108df70;
struct CH
{
    int v;
    void __thiscall CombatTargetTimestamp(float);
};
struct SH
{
    void __thiscall FUN_006dbde0(int);
};
struct Unk975C0
{
    char _0[24];
    float f18;
    int i1c;
    SH s20;
    void FUN_009975c0();
};
// @fnv 0x009975c0
void Unk975C0::FUN_009975c0()
{
    CH data;
    f18 = 0.0f;
    data.CombatTargetTimestamp(-DAT_0108df70);
    i1c = data.v;
    s20.FUN_006dbde0(1);
}

namespace fnv_00997ba0 {
struct FUN_00997c10_shell
{
    void FUN_00997c10();
};
struct FUN_009a0680_shell
{
    void ClearAndDeletePointer();
};
struct FUN_00997ba0_shell
{
    void FUN_009a03d0(int);
    void FUN_00997bf0();
    void ReleaseStageHolder(int);
    void FUN_00997ba0(int, int);
};
// When a is zero and b is non-zero, calls FUN_009a03d0(0), FUN_00997bf0, ReleaseStageHolder(0), FUN_00997c10 and ClearAndDeletePointer.
// @fnv 0x00997ba0
void FUN_00997ba0_shell::FUN_00997ba0(int aiFirst, int aiSecond)
{
    if (aiFirst == 0 && aiSecond != 0)
    {
        FUN_009a03d0(0);
        FUN_00997bf0();
        ReleaseStageHolder(0);
        ((FUN_00997c10_shell*)this)->FUN_00997c10();
        ((FUN_009a0680_shell*)this)->ClearAndDeletePointer();
    }
}
}  // namespace fnv_00997ba0

namespace fnv_00997bf0 {
struct FUN_00997c10_shell
{
    void FUN_009975c0();
};
struct FUN_00997bf0_shell
{
    void FUN_00997bf0();
};
// @fnv 0x00997bf0
void FUN_00997bf0_shell::FUN_00997bf0()
{
    ((FUN_00997c10_shell*)((char*)this + 0xec))->FUN_009975c0();
}
}  // namespace fnv_00997bf0

struct MobileObject
{
    unsigned int GetCurrentProcessLevel();
};

struct TESAmmoInitCalls
{
    MobileObject* GetFieldBC();
};

struct FUN_00997cb0_Class
{
    void FUN_00997cb0();
    void FUN_00997cf0();
    void FUN_00998a50();
    void FUN_00999160();
};

// @fnv 0x00997cb0
void FUN_00997cb0_Class::FUN_00997cb0()
{
    if ((*reinterpret_cast<TESAmmoInitCalls**>(reinterpret_cast<char*>(this) + 0x1c4))
            ->GetFieldBC()
            ->GetCurrentProcessLevel() == 0)
    {
        FUN_00997cf0();
        FUN_00998a50();
    }
    else
    {
        FUN_00999160();
    }
}

namespace fnv_00998980 {
struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting411;
struct CombatTimeStampHelper
{
    float GetElapsedTime();
};
struct FUN_00998980_shell
{
    char _pad[0x98];
    CombatTimeStampHelper _ts;
    bool FUN_00998980();
};
// Returns whether the elapsed time from _ts is less than the float value of originalRuntimeFloatSetting411.
// @fnv 0x00998980
bool FUN_00998980_shell::FUN_00998980()
{
    return (double)_ts.GetElapsedTime() < *originalRuntimeFloatSetting411.Float();
}
}  // namespace fnv_00998980

struct FUN_009989d0_shell
{
    bool HasCombatFlag(int);
    bool FUN_009989d0();
};
// @fnv 0x009989d0
bool FUN_009989d0_shell::FUN_009989d0()
{
    return HasCombatFlag(0x10);
}

struct FUN_00998a30_shell
{
    bool FUN_00998a30();
};
// @fnv 0x00998a30
bool FUN_00998a30_shell::FUN_00998a30()
{
    return *(bool*)((char*)this + 0xd4);
}

extern double _gModifierZero;
struct FUN_009990c0_s
{
    int a;
    float value;
    bool IsNegative();
};
// Returns true when value is less than _gModifierZero.
// @fnv 0x009990c0
bool FUN_009990c0_s::IsNegative()
{
    return value < _gModifierZero;
}

struct FUN_00999100_shell
{
    bool FUN_006296b0(int);
    bool FUN_00999100();
};
// @fnv 0x00999100
bool FUN_00999100_shell::FUN_00999100()
{
    return FUN_006296b0(3);
}

struct Modifier
{
    float GetValue();
};
extern double _gModifierZero;
struct Holder
{
    unsigned char _pad[0xB4];
    Modifier mod;
    bool IsModifierZero();
};
// Returns whether the holder's modifier value equals _gModifierZero.
// @fnv 0x00999120
bool Holder::IsModifierZero()
{
    return mod.GetValue() == _gModifierZero;
}

struct FUN_0099a3e0_s
{
    char a[0x10];
    int state;
    bool FUN_0099a3e0();
};
// Returns true when state is neither 3 nor 4.
// @fnv 0x0099a3e0
bool FUN_0099a3e0_s::FUN_0099a3e0()
{
    return state != 3 && state != 4;
}

struct Actor
{
    static float __cdecl GetActorScale(void);
};

struct RegionPoint
{
    float __thiscall GetX(void);
};

struct CombatTimeStampCtor
{
    void __thiscall CombatTargetTimestamp(float);
};

struct CombatTimeStamp4
{
    float v;
};

extern float DAT_0108df70;

struct FUN_0099a5e0_shell
{
    void __thiscall UpdateCombatTimestamps(int);
};

// Stores a new combat timestamp at this+0x9c and, if the timestamp at this+0xa4 equals -DAT_0108df70, replaces it with a new one.
// @fnv 0x0099a5e0
void FUN_0099a5e0_shell::UpdateCombatTimestamps(int)
{
    CombatTimeStamp4 a;
    CombatTimeStamp4 b;
    reinterpret_cast<CombatTimeStampCtor*>(&a)->CombatTargetTimestamp(Actor::GetActorScale());
    *(CombatTimeStamp4*)((char*)this + 0x9c) = a;
    if (((RegionPoint*)((char*)this + 0xa4))->GetX() == -DAT_0108df70)
    {
        reinterpret_cast<CombatTimeStampCtor*>(&b)->CombatTargetTimestamp(Actor::GetActorScale());
        *(CombatTimeStamp4*)((char*)this + 0xa4) = b;
    }
}

struct FUN_0097f220_t
{
    void FUN_0097f220();
};
struct FUN_0099a650_shell : CombatState
{
    void FUN_0099a650(int a, bool b);
};
// If the flag is false, calls FUN_0097f220 on the object at offset 0x214 of this CombatState.
// @fnv 0x0099a650
void FUN_0099a650_shell::FUN_0099a650(int aiUnused, bool b)
{
    if (!b)
        ((FUN_0097f220_t*)((char*)this + 0x214))->FUN_0097f220();
}

namespace fnv_0099a6b0 {
struct Actor
{
    static float __cdecl GetActorScale();
};

struct CombatTargetTimestamp
{
    float val;
    CombatTargetTimestamp(float v);
    float GetElapsedTime();
};

struct S9a0c50
{
    void UpdateModifierState(int);
};

struct S9a1280
{
    void FUN_009a1280(int);
};

struct FUN_0099a6b0_Class
{
    void FUN_0099a6b0(int, int);
};

// @fnv 0x0099a6b0
void FUN_0099a6b0_Class::FUN_0099a6b0(int p1, int p2)
{
    if (((CombatTargetTimestamp*)((char*)this + 0xa0))->GetElapsedTime() > 1.0)
    {
        ((S9a0c50*)this)->UpdateModifierState(1);
    }
    CombatTargetTimestamp ts(Actor::GetActorScale());
    *(CombatTargetTimestamp*)((char*)this + 0xa0) = ts;
    if (*(unsigned char*)((char*)this + 0xd8) == 2)
    {
        ((S9a1280*)this)->FUN_009a1280(1);
    }
}
}  // namespace fnv_0099a6b0

namespace fnv_0099a720 {
struct Setting_S
{
    float* Float();
};

Setting_S g_011ce058;

struct FUN_008d7f40_cls
{
    void FUN_008d7f40(float);
};

struct FUN_0099a720_cls
{
    void EvaluateWeaponScores();
    void FUN_0099a720();
};

// @fnv 0x0099a720
void FUN_0099a720_cls::FUN_0099a720()
{
    if (*reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x64) <
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x58))
    {
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x64) =
            *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x58);
        reinterpret_cast<FUN_008d7f40_cls*>(reinterpret_cast<char*>(this) + 0x1d4)->FUN_008d7f40(*g_011ce058.Float());
    }
    EvaluateWeaponScores();
}
}  // namespace fnv_0099a720

struct StageHolder
{
    bool GetDone();
};
struct FUN_0099a9a0_shell
{
    void UpdateStageHolders();
    void FUN_009a03d0(int);
    void ReleaseStageHolder(int);
};
// Checks the StageHolder pointers at offsets 0xE4 and 0xE8 and calls FUN_009a03d0(0) or ReleaseStageHolder(0) for each one that is not done.
// @fnv 0x0099a9a0
void FUN_0099a9a0_shell::UpdateStageHolders()
{
    if (*(StageHolder**)((char*)this + 0xE4) && !(*(StageHolder**)((char*)this + 0xE4))->GetDone())
        this->FUN_009a03d0(0);
    if (*(StageHolder**)((char*)this + 0xE8) && !(*(StageHolder**)((char*)this + 0xE8))->GetDone())
        this->ReleaseStageHolder(0);
}

struct AlchemyItem
{
    void* FUN_004030b0();
};
struct CTSHelper
{
    float GetElapsedTime();
};
struct D3
{
    int a, b, c;
};
extern double DAT_010718b8;

struct FUN_0099ab50_Class
{
    bool FUN_0099ab50(D3* dest);
};

// Checks the item pointer at 0x1c4 and elapsed time against DAT_010718b8; if valid, copies the D3 at 0x84 into dest and returns true, else false.
// @fnv 0x0099ab50
bool FUN_0099ab50_Class::FUN_0099ab50(D3* dest)
{
    void* p = (*(AlchemyItem**)((char*)this + 0x1c4))->FUN_004030b0();
    if (p == 0 || ((CTSHelper*)((char*)this + 0x98))->GetElapsedTime() > DAT_010718b8)
        return false;
    *dest = *(D3*)((char*)this + 0x84);
    return true;
}

namespace fnv_0099abc0 {
struct NiPoint3
{
    float x;
    float y;
    float z;
};
struct Actor
{
};
struct AlchemyItem
{
    Actor* FUN_004030b0();
};
float __cdecl FUN_009a8460(Actor*, int, int);
struct FUN_0099abc0_This
{
    bool FUN_0099ab50(NiPoint3&);
    bool UpdateLastSeenFiringLocation(NiPoint3&);
};
// Checks the point via FUN_0099ab50, then adds FUN_009a8460's result for the target actor to the point's z and returns true.
// @fnv 0x0099abc0
bool FUN_0099abc0_This::UpdateLastSeenFiringLocation(NiPoint3& arLastSeenFiringLocation)
{
    Actor* ptarget;
    if (!FUN_0099ab50(arLastSeenFiringLocation))
        return false;
    ptarget = (*(AlchemyItem**)((char*)this + 0x1c4))->FUN_004030b0();
    arLastSeenFiringLocation.z += FUN_009a8460(ptarget, 2, 1);
    return true;
}
}  // namespace fnv_0099abc0

struct MagicItem;
struct MagicCaster
{
    void SetSelectedMagicItem(MagicItem*);
};
struct FUN_0099b520_shell : MagicCaster
{
    void FUN_0099b520(MagicItem* spell);
};
// @fnv 0x0099b520
void FUN_0099b520_shell::FUN_0099b520(MagicItem* spell)
{
    SetSelectedMagicItem(spell);
}

struct FUN_0099b580_shell
{
    void _ref_0084e3a0();
    void CallReferencedFunction();
};
// @fnv 0x0099b580
void FUN_0099b580_shell::CallReferencedFunction()
{
    _ref_0084e3a0();
}

struct FUN_00989010_t
{
    void SetTripleAndValue(int, int);
};
struct FUN_0099b8b0_shell : FUN_00989010_t
{
    void FUN_0099b8b0(int a, int b);
};
// Calls SetTripleAndValue with the two arguments, then writes 0 to the field at offset 0x10 of this object.
// @fnv 0x0099b8b0
void FUN_0099b8b0_shell::FUN_0099b8b0(int a, int b)
{
    SetTripleAndValue(a, b);
    *(int*)((char*)this + 0x10) = 0;
}

struct FUN_0099c1f0_shell
{
    bool FUN_0099c1f0();
};
// @fnv 0x0099c1f0
bool FUN_0099c1f0_shell::FUN_0099c1f0()
{
    return *(bool*)((char*)this + 0x4c);
}

struct ParentSpaceNode
{
    int a;
    int b;
    int c;
};
template <class T, int N> struct BSSimpleArray
{
    T& GetAt(int);
};
struct ArrSI : public BSSimpleArray<ParentSpaceNode, 1024>
{
    unsigned int GetFlags();
};
bool __cdecl FUN_0099cc60(void*, ParentSpaceNode*, int);
// @fnv 0x0099cb00
bool __cdecl FUN_0099cb00(void* p1, ArrSI* pNodes)
{
    unsigned int i;
    ParentSpaceNode node;
    for (i = 0; i < pNodes->GetFlags(); ++i)
    {
        node = pNodes->GetAt(i);
        if (FUN_0099cc60(p1, &node, 0))
            return true;
    }
    return false;
}

namespace fnv_009a0260 {
struct CoordinateTriple
{
    int v[4];
    CoordinateTriple* FUN_0043a3c0(int, int, bool, bool);
};
struct FUN_009a0260_s
{
    void FUN_009a02a0(CoordinateTriple*);
    void FUN_009a0260(int a, int b, bool c, bool d);
};
// @fnv 0x009a0260
void FUN_009a0260_s::FUN_009a0260(int a, int b, bool c, bool d)
{
    CoordinateTriple loc;
    FUN_009a02a0(loc.FUN_0043a3c0(a, b, c, d));
}
}  // namespace fnv_009a0260

namespace fnv_009a0650 {
struct FUN_009a0680_shell
{
    void ClearAndDeletePointer();
};
struct FUN_009a0650_shell : FUN_009a0680_shell
{
    void SetField18C(int v);
};
// Calls ClearAndDeletePointer, then stores v at offset 0x18c of this object.
// @fnv 0x009a0650
void FUN_009a0650_shell::SetField18C(int aiValue)
{
    ClearAndDeletePointer();
    *(int*)((char*)this + 0x18c) = aiValue;
}
}  // namespace fnv_009a0650

struct Inner097
{
    char data[16];
    void FUN_0097ede0();
};
struct FUN_009a08d0_Cls
{
    unsigned char b0;
    unsigned char b1;
    int i4;
    Inner097 u8;
    float f18;
    float f1c;
    FUN_009a08d0_Cls* FUN_009a08d0();
};
// @fnv 0x009a08d0
FUN_009a08d0_Cls* FUN_009a08d0_Cls::FUN_009a08d0()
{
    b0 = 0;
    b1 = 0;
    i4 = 0;
    u8.FUN_0097ede0();
    f18 = 0.0f;
    f1c = 0.0f;
    return this;
}

struct FUN_009a0b30_self
{
    float GetScaledValue();
};

// Returns 0.9 times the float at offset 0x18 of the pointer stored at offset 0xc4, or 0.0 if that pointer is null.
// @fnv 0x009a0b30
float FUN_009a0b30_self::GetScaledValue()
{
    return (
        float)(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0xc4)
                   ? *reinterpret_cast<float*>(*reinterpret_cast<char**>(reinterpret_cast<char*>(this) + 0xc4) + 0x18) *
                         (double)0.9f
                   : 0.0);
}

namespace fnv_009a0be0 {
struct AnimIdle
{
    int __thiscall GetSection();
};
struct Setting_S
{
    float* __thiscall Float();
};
struct Obj_1c4
{
    AnimIdle* __thiscall FUN_004f9bf0();
};
struct GameSettingCollection;
template <class T> struct SettingT;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting424;

struct FUN_009a0be0_Class
{
    float __thiscall GetIdleAdjustedValue();
};

// Returns the float at this+0xc4 offset 0x1c, adding the runtime float setting when the idle's section is not 0xf, 6 or 0.
// @fnv 0x009a0be0
float FUN_009a0be0_Class::GetIdleAdjustedValue()
{
    AnimIdle* idle = ((Obj_1c4*)*(void**)((char*)this + 0x1c4))->FUN_004f9bf0();
    if (idle)
    {
        int section = idle->GetSection();
        if (section != 0xf && section != 6 && section != 0)
        {
            return *(float*)(*(char**)((char*)this + 0xc4) + 0x1c) +
                   reinterpret_cast<Setting_S*>(&originalRuntimeFloatSetting424)->Float()[0];
        }
    }
    return *(float*)(*(char**)((char*)this + 0xc4) + 0x1c);
}
}  // namespace fnv_009a0be0

namespace fnv_009a0d00 {
struct E006950d0;

struct S5460
{
    unsigned int __thiscall FUN_00845460(void);
};

struct S006950d0
{
    E006950d0* __thiscall GetElement(unsigned int);
};

struct Actor
{
    static float __cdecl GetActorScale(void);
};

struct CombatTargetTimestamp
{
    float time;
    CombatTargetTimestamp(float);
};

struct Entry
{
    void* ptr;
    CombatTargetTimestamp ts;
};

struct FUN_009a0d00_shell
{
    void __thiscall StoreEntry(const void* apCopy);
};

// @fnv 0x009a0d00
void __thiscall FUN_009a0d00_shell::StoreEntry(const void* apCopy)
{
    if (!apCopy)
        return;
    unsigned int count = ((S5460*)((char*)this + 0x164))->FUN_00845460();
    ((Entry*)((S006950d0*)((char*)this + 0x164))->GetElement(count))->ptr = (void*)apCopy;
    CombatTargetTimestamp ts(Actor::GetActorScale());
    ((Entry*)((S006950d0*)((char*)this + 0x164))->GetElement(count))->ts = ts;
}
}  // namespace fnv_009a0d00

namespace fnv_009a0ec0 {
struct S20;
struct H4
{
    S20* __thiscall FUN_006b3160(unsigned int);
};
struct FUN_007881d0_shell
{
    unsigned int __thiscall FUN_007881d0(void);
};
struct CombatTimeStamp_ctor
{
    void __thiscall CombatTargetTimestamp(float);
};
struct Actor
{
    static float __cdecl GetActorScale(void);
};

struct FUN_009a0ec0_Block
{
    unsigned int v[4];
};
struct FUN_009a0ec0_Ts
{
    unsigned int v;
};
struct FUN_009a0ec0_Node
{
    FUN_009a0ec0_Block block;
    FUN_009a0ec0_Ts ts;
};

struct FUN_009a0ec0_shell
{
    void __thiscall SetNodeBlockAndTimestamp(const FUN_009a0ec0_Block* a1);
};

// @fnv 0x009a0ec0
void __thiscall FUN_009a0ec0_shell::SetNodeBlockAndTimestamp(const FUN_009a0ec0_Block* apBlock)
{
    FUN_009a0ec0_Ts timeStamp;
    unsigned int index = reinterpret_cast<FUN_007881d0_shell*>(reinterpret_cast<char*>(this) + 0x174)->FUN_007881d0();
    reinterpret_cast<FUN_009a0ec0_Node*>(
        reinterpret_cast<H4*>(reinterpret_cast<char*>(this) + 0x174)->FUN_006b3160(index))
        ->block = *apBlock;
    reinterpret_cast<CombatTimeStamp_ctor*>(&timeStamp)->CombatTargetTimestamp(Actor::GetActorScale());
    reinterpret_cast<FUN_009a0ec0_Node*>(
        reinterpret_cast<H4*>(reinterpret_cast<char*>(this) + 0x174)->FUN_006b3160(index))
        ->ts = timeStamp;
}
}  // namespace fnv_009a0ec0

namespace fnv_009a1010 {
struct Actor
{
    float __thiscall GetCombatRating(float);
    float __thiscall FUN_008be600();
};

struct TESAmmoInitCalls
{
    unsigned int __thiscall GetFieldBC();
};

struct FUN_009a1010_Class
{
    void FUN_009a1010();
};

// @fnv 0x009a1010
void FUN_009a1010_Class::FUN_009a1010()
{
    Actor* ptarget = (Actor*)(*(TESAmmoInitCalls**)((char*)this + 0x1c4))->GetFieldBC();
    *(float*)((char*)this + 0xd4) = ptarget->FUN_008be600();
    *(float*)((char*)this + 0xd0) = ptarget->GetCombatRating(*(float*)((char*)this + 0xd4));
}
}  // namespace fnv_009a1010

namespace fnv_009a2bf0 {
struct BGSSaveFormBuffer
{
    void SerializeFormData(void*, int);
    void SaveData(void*, int, int);
};

struct CoordinateTriple
{
    void FUN_00527b70(void*);
    void* field00;
    void* field04;
    void* field08;
    void* field0C;
};

struct FUN_009a2bf0_shell : CoordinateTriple
{
    void* field10;
    void* field14;
    void* field18;
    void* field1C;
    void FUN_009a2bf0(BGSSaveFormBuffer* a_buffer);
};

// @fnv 0x009a2bf0
void FUN_009a2bf0_shell::FUN_009a2bf0(BGSSaveFormBuffer* a_buffer)
{
    FUN_00527b70(a_buffer);
    a_buffer->SaveData(&field14, 4, 0);
    a_buffer->SaveData(&field18, 4, 0);
    a_buffer->SaveData(&field1C, 4, 0);
    a_buffer->SerializeFormData(field10, 0);
}
}  // namespace fnv_009a2bf0

struct BGSLoadFormBuffer
{
    bool __thiscall ReadFormIdentifier(void*);
    void __thiscall ReadTypedData(void*, unsigned int);
};

struct FUN_00527ba0_Class
{
    void __thiscall FUN_00527ba0(void*);
};

struct FUN_009a2c60_Class
{
    void __thiscall LoadFormData(void*);
};

// @fnv 0x009a2c60
void FUN_009a2c60_Class::LoadFormData(void* buffer)
{
    ((FUN_00527ba0_Class*)this)->FUN_00527ba0(buffer);
    ((BGSLoadFormBuffer*)buffer)->ReadTypedData((void*)((char*)this + 0x14), 4);
    ((BGSLoadFormBuffer*)buffer)->ReadTypedData((void*)((char*)this + 0x18), 4);
    ((BGSLoadFormBuffer*)buffer)->ReadTypedData((void*)((char*)this + 0x1c), 4);
    ((BGSLoadFormBuffer*)buffer)->ReadFormIdentifier((void*)((char*)this + 0x10));
}

namespace fnv_009a2d20 {
struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
};
struct CombatTargetTimestamp
{
    int v;
    void SaveTimeStamp(void*);
};
struct FUN_009a2d20_s
{
    int a;
    CombatTargetTimestamp ts;
    void FUN_009a2d20(BGSSaveFormBuffer* buf);
};
// @fnv 0x009a2d20
void FUN_009a2d20_s::FUN_009a2d20(BGSSaveFormBuffer* apBuffer)
{
    apBuffer->SaveData(this, 4, 0);
    ts.SaveTimeStamp(apBuffer);
}
}  // namespace fnv_009a2d20

namespace fnv_009a2d50 {
struct BGSLoadGameBuffer;
struct BGSLoadFormBuffer
{
    void ReadTypedData(void*, unsigned int);
};
struct CombatTargetTimestamp
{
    int v;
    void LoadGame(BGSLoadGameBuffer*);
};
struct FUN_009a2d50_s
{
    int a;
    CombatTargetTimestamp ts;
    void FUN_009a2d50(BGSLoadFormBuffer* buf);
};
// Reads 4 bytes of this object from buf, then loads the ts member from the same buffer.
// @fnv 0x009a2d50
void FUN_009a2d50_s::FUN_009a2d50(BGSLoadFormBuffer* buf)
{
    buf->ReadTypedData(this, 4);
    ts.LoadGame((BGSLoadGameBuffer*)buf);
}
}  // namespace fnv_009a2d50

namespace fnv_009a2db0 {
struct BGSLoadGameBuffer;
struct CombatTargetTimestamp
{
    void LoadGame(BGSLoadGameBuffer*);
};
struct FUN_00527ba0_t
{
    void FUN_00527ba0(BGSLoadGameBuffer*);
};
struct FUN_009a2db0_shell : FUN_00527ba0_t
{
    void FUN_009a2db0(BGSLoadGameBuffer* buf);
};
// @fnv 0x009a2db0
void FUN_009a2db0_shell::FUN_009a2db0(BGSLoadGameBuffer* buf)
{
    FUN_00527ba0(buf);
    ((CombatTargetTimestamp*)((char*)this + 0x10))->LoadGame(buf);
}
}  // namespace fnv_009a2db0

namespace fnv_009a3130 {
struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
    void SerializeFormData(void*, int);
};
struct CoordinateTriple
{
    void FUN_00527b70(void*);
};
struct CombatSaveData
{
    unsigned char unk0;
    unsigned char unk1;
    void* pRef;
    unsigned char unk08[16];
    int unk18;
    int unk1C;
    void FUN_009a3130(BGSSaveFormBuffer*);
};
// @fnv 0x009a3130
void CombatSaveData::FUN_009a3130(BGSSaveFormBuffer* apSaveGameBuffer)
{
    apSaveGameBuffer->SaveData(&unk0, 1, 0);
    apSaveGameBuffer->SaveData(&unk1, 1, 0);
    apSaveGameBuffer->SaveData(&unk18, 4, 0);
    apSaveGameBuffer->SaveData(&unk1C, 4, 0);
    apSaveGameBuffer->SerializeFormData(pRef, 0);
    ((CoordinateTriple*)((char*)this + 8))->FUN_00527b70(apSaveGameBuffer);
}
}  // namespace fnv_009a3130

namespace fnv_009a31b0 {
struct BGSLoadFormBuffer
{
    void ReadTypedData(void*, unsigned int);
    bool ReadFormIdentifier(void*);
};
struct Sub08
{
    void FUN_00527ba0(BGSLoadFormBuffer*);
};
struct Holder
{
    void FUN_009a31b0(BGSLoadFormBuffer*);
};
// Reads bytes at offsets 0, 1, 0x18 and 0x1C, a value at offset 4, and delegates offset 8 to FUN_00527ba0, all via the load buffer.
// @fnv 0x009a31b0
void Holder::FUN_009a31b0(BGSLoadFormBuffer* pBuffer)
{
    pBuffer->ReadTypedData(this, 1);
    pBuffer->ReadTypedData((void*)((char*)this + 1), 1);
    pBuffer->ReadTypedData((void*)((char*)this + 0x18), 4);
    pBuffer->ReadTypedData((void*)((char*)this + 0x1C), 4);
    pBuffer->ReadFormIdentifier((void*)((char*)this + 4));
    ((Sub08*)((char*)this + 8))->FUN_00527ba0(pBuffer);
}
}  // namespace fnv_009a31b0

struct FUN_009a3280_shell
{
    void* FUN_009052c0(int);
    void* FUN_009a3280(int index);
};
// @fnv 0x009a3280
void* FUN_009a3280_shell::FUN_009a3280(int index)
{
    return FUN_009052c0(index);
}

struct Elem54
{
    char data[0x54];
};
struct RetObj
{
    void FUN_006e4430();
};
struct Helper
{
    void FUN_009a32a0(unsigned int, int);
    RetObj* FUN_009052c0(unsigned int, void*);
};
struct Host
{
    int unk0;
    Elem54* arr;
    unsigned int cnt;
    void ProcessElements(Helper*);
};
// Calls FUN_009a32a0 with cnt and 1, then for each of cnt elements calls FUN_009052c0(i, &arr[i]) and FUN_006e4430 on the result.
// @fnv 0x009a3780
void Host::ProcessElements(Helper* apHelper)
{
    apHelper->FUN_009a32a0(cnt, 1);
    for (unsigned int i = 0; i < cnt; ++i)
    {
        apHelper->FUN_009052c0(i, &arr[i])->FUN_006e4430();
    }
}

struct FUN_009cc490_shell
{
    void FUN_009cc490(unsigned int flags);
};
// @fnv 0x009cc490
void FUN_009cc490_shell::FUN_009cc490(unsigned int flags)
{
    *(unsigned int*)((char*)this + 4) |= flags;
}

struct CCL
{
    int v;
};
struct FUN_009d6730_shell : CombatState
{
    CCL* FUN_009d6730(CCL* out);
};
// @fnv 0x009d6730
CCL* FUN_009d6730_shell::FUN_009d6730(CCL* out)
{
    *out = *(CCL*)((char*)this + 0xa0);
    return out;
}

struct CombatCoverPointData;
struct FUN_009d6c80_shell
{
    void FUN_009a05b0(CombatCoverPointData*);
    void FUN_009d6c80();
};
// @fnv 0x009d6c80
void FUN_009d6c80_shell::FUN_009d6c80()
{
    FUN_009a05b0(*(CombatCoverPointData**)((char*)this + 0xe8));
}

struct CombatCoverPointData;
struct FUN_009d7c20_shell : CombatState
{
    void FUN_009a0510(CombatCoverPointData*);
    void FUN_009d7c20();
};
// @fnv 0x009d7c20
void FUN_009d7c20_shell::FUN_009d7c20()
{
    FUN_009a0510(*(CombatCoverPointData**)((char*)this + 0xe8));
}

struct RefX
{
    bool FUN_00437b90();
};
struct FUN_00981340_shell
{
    void FreeSlot(int);
};
struct FUN_0097cfc0_shell
{
    void* GetActionAtIndex(int);
};
struct FUN_0099a530_shell
{
    void FUN_0099a530();
};
// @fnv 0x0099a530
void FUN_0099a530_shell::FUN_0099a530()
{
    void* a = *(void**)((char*)this + 0x19c);
    void* b = *(void**)((char*)this + 0x1a0);
    for (unsigned int i = 0; i < 5; ++i)
    {
        void* pSlotObj = ((FUN_0097cfc0_shell*)this)->GetActionAtIndex(i);
        if (pSlotObj && *(void**)pSlotObj && ((RefX*)*(void**)pSlotObj)->FUN_00437b90())
            ((FUN_00981340_shell*)this)->FreeSlot(i);
    }
    if (a != ((FUN_0097cfc0_shell*)this)->GetActionAtIndex(3) || b != ((FUN_0097cfc0_shell*)this)->GetActionAtIndex(4))
    {
        ((FUN_00981340_shell*)this)->FreeSlot(3);
        ((FUN_00981340_shell*)this)->FreeSlot(4);
    }
}

namespace fnv_009a2f50 {
struct BGSSaveGameBuffer
{
    void FUN_00865f60(unsigned int);
};
struct BGSSaveFormBuffer : BGSSaveGameBuffer
{
    void SaveData(void*, int, int);
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct CombatTargetTimestamp
{
    void SaveTimeStamp(BGSSaveFormBuffer*);
};
struct FUN_009a3280_shell
{
    void* FUN_009a3280(int);
};
struct FUN_009a2f50_shell
{
    void FUN_009a2f50(BGSSaveFormBuffer* buffer);
};
// @fnv 0x009a2f50
void FUN_009a2f50_shell::FUN_009a2f50(BGSSaveFormBuffer* buffer)
{
    buffer->SaveData(this, 12, 0);
    buffer->SaveData((char*)this + 12, 12, 0);
    buffer->SaveData((char*)this + 24, 4, 0);
    buffer->SaveData((char*)this + 56, 1, 0);
    buffer->SaveData((char*)this + 48, 4, 0);
    buffer->SaveData((char*)this + 52, 4, 0);
    ((CombatTargetTimestamp*)((char*)this + 28))->SaveTimeStamp(buffer);
    unsigned int flags = ((char*)this + 32) ? ((ArrSI*)((char*)this + 32))->GetFlags() : 0;
    buffer->FUN_00865f60(flags);
    for (unsigned int i = 0; i < flags; ++i)
    {
        void* cover = ((FUN_009a3280_shell*)((char*)this + 32))->FUN_009a3280(i);
        ((void(__thiscall*)(void*, BGSSaveFormBuffer*))(*((int**)cover))[0])(cover, buffer);
    }
}
}  // namespace fnv_009a2f50

namespace fnv_009a3050 {
struct BGSLoadFormBuffer
{
    void ReadTypedData(void*, unsigned int);
    int ReadElementCount();
};
struct CombatTargetTimestamp
{
    void LoadGame(BGSLoadFormBuffer*);
};
struct PathingCoverLocation
{
    virtual void v0();
    virtual void LoadGame(BGSLoadFormBuffer*);
};
struct Helper
{
    void FUN_009a32a0(unsigned int, int);
};
struct FUN_009a3280_shell
{
    PathingCoverLocation* FUN_009a3280(int);
};
struct CombatSaveGameData
{
    void FUN_009a3050(BGSLoadFormBuffer* buffer);
};
// Reads this object's fields from the buffer, then loads a count and each of that many PathingCoverLocation entries via LoadGame.
// @fnv 0x009a3050
void CombatSaveGameData::FUN_009a3050(BGSLoadFormBuffer* buffer)
{
    buffer->ReadTypedData(this, 0xc);
    buffer->ReadTypedData((char*)this + 0xc, 0xc);
    buffer->ReadTypedData((char*)this + 0x18, 4);
    buffer->ReadTypedData((char*)this + 0x38, 1);
    buffer->ReadTypedData((char*)this + 0x30, 4);
    buffer->ReadTypedData((char*)this + 0x34, 4);
    ((CombatTargetTimestamp*)((char*)this + 0x1c))->LoadGame(buffer);
    unsigned int count = buffer->ReadElementCount();
    ((Helper*)((char*)this + 0x20))->FUN_009a32a0(count, 1);
    unsigned int i = 0;
    for (; i < count; ++i)
    {
        PathingCoverLocation* cover = ((FUN_009a3280_shell*)((char*)this + 0x20))->FUN_009a3280(i);
        cover->LoadGame(buffer);
    }
}
}  // namespace fnv_009a3050

struct FUN_0097ee20_shell
{
    char _pad[0x10];
    int f10;
    int f14;
    float f18;
    int f1c;
    void FUN_0097ede0();
    FUN_0097ee20_shell* FUN_0097ee20();
};

// Calls FUN_0097ede0, then sets f10 to 0, f14 to -1, f18 to 0.0f and f1c to 0, returning this.
// @fnv 0x0097ee20
FUN_0097ee20_shell* FUN_0097ee20_shell::FUN_0097ee20()
{
    FUN_0097ede0();
    f10 = 0;
    f14 = -1;
    f18 = 0.0f;
    f1c = 0;
    return this;
}

struct TES;
struct TESWorldSpace;

struct TES
{
    TESWorldSpace* GetHitSound();
};

struct TESWorldSpace
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
    virtual int getFormType();
    bool FUN_0099a3e0();
};

struct Container
{
    bool FUN_0099a360(int, TESWorldSpace*);
};

// @fnv 0x0099a360
bool Container::FUN_0099a360(int, TESWorldSpace* param2)
{
    if (param2 != *(TESWorldSpace**)((char*)this + 0x1c0))
        return true;
    bool bResult = true;
    if (*(int*)((char*)this + 0x6c) > 0)
    {
        TESWorldSpace* SoundAssetTmp = ((TES*)(*(TES**)((char*)this + 0x1c4)))->GetHitSound();
        if (SoundAssetTmp)
        {
            if (SoundAssetTmp->getFormType() == 7)
            {
                TESWorldSpace* pHitSoundCopy = SoundAssetTmp;
                if (pHitSoundCopy->FUN_0099a3e0())
                    bResult = false;
            }
        }
    }
    return bResult;
}

namespace fnv_0099a680 {
struct CombatTargetTimestamp
{
    int v;
    CombatTargetTimestamp(float);
};
struct Actor
{
    static float __cdecl GetActorScale();
};
struct FUN_0099a680_s
{
    char pad[0x9c];
    CombatTargetTimestamp stamp;
    void SetStampFromActor(int);
};
// @fnv 0x0099a680
void FUN_0099a680_s::SetStampFromActor(int)
{
    CombatTargetTimestamp t(Actor::GetActorScale());
    stamp = t;
}
}  // namespace fnv_0099a680

struct S81
{
    void FUN_00981380();
};
struct C99
{
    char _pad[0x1C4];
    S81* f1C4;
    int* GetActionAtIndex(int);
    void FUN_0099a420(int, int);
    void FUN_0099a780(int);
};
// Looks up entry 2, calls f1C4->FUN_00981380() if its value equals a, then calls FUN_0099a420(a, 1).
// @fnv 0x0099a780
void C99::FUN_0099a780(int a)
{
    int* b = GetActionAtIndex(2);
    if (b && *b == a)
        f1C4->FUN_00981380();
    FUN_0099a420(a, 1);
}

namespace fnv_0099a7d0 {
bool __fastcall FUN_00981990(void*);
void* __fastcall _FNV_GetObjectReference(void*);
int __fastcall _FNV_GetFormType(void*);
int __fastcall _ref_0084e3a0(void*);
struct Actor
{
    static float __cdecl GetActorScale();
};
struct CTSHelper
{
    void CombatTargetTimestamp(float);
};
struct Host
{
    char _pad0[0xdc];
    unsigned int m_uiCoverPointFlags;
    unsigned int m_kCoverPointData;
    char _pad1[0x1c4 - 0xe4];
    void* ctrl;
    void FUN_0099a7d0(void* apRef, void* apObject, int aiCount, bool abActivatedScriptOnly);
};
// @fnv 0x0099a7d0
void Host::FUN_0099a7d0(void* apRef, void* apObject, int aiCount, bool abActivatedScriptOnly)
{
    if (FUN_00981990(ctrl))
    {
        if (_FNV_GetFormType(_FNV_GetObjectReference(apRef)) == 0x1c)
        {
            m_uiCoverPointFlags = _ref_0084e3a0(apRef);
            unsigned int ts;
            ((CTSHelper*)&ts)->CombatTargetTimestamp(Actor::GetActorScale());
            m_kCoverPointData = ts;
        }
    }
}
}  // namespace fnv_0099a7d0

struct FUN_0099b540_s
{
    char pad[0x1c];
    unsigned int flags;
    void SetFlags(unsigned int mask, bool set);
};
// Sets or clears the bits of flags selected by mask, according to set.
// @fnv 0x0099b540
void FUN_0099b540_s::SetFlags(unsigned int mask, bool set)
{
    if (set)
        flags |= mask;
    else
        flags &= ~mask;
}

struct CombatCoverPointData;
struct FUN_009a0600_shell
{
    unsigned char _pad[0xE4];
    CombatCoverPointData* m_pCurrentCoverPoint;
    CombatCoverPointData* m_pAlternateCoverPoint;
    bool FUN_009a0600(CombatCoverPointData* apCoverLocation);
};
// @fnv 0x009a0600
bool FUN_009a0600_shell::FUN_009a0600(CombatCoverPointData* apCoverLocation)
{
    if (!apCoverLocation)
        return false;
    return apCoverLocation == m_pCurrentCoverPoint || apCoverLocation == m_pAlternateCoverPoint;
}

namespace fnv_009a0a80 {
struct AlchemyItem
{
    void* FUN_004030b0();
    bool FUN_00981420();
};
struct Host
{
    unsigned char pad0[0xC4];
    unsigned char* field_C4;
    unsigned char pad1[0x1C4 - 0xC4 - 4];
    AlchemyItem* field_1C4;
    bool FUN_0097ee90();
    bool FUN_009a0a80();
};
// @fnv 0x009a0a80
bool Host::FUN_009a0a80()
{
    void* tmp = field_1C4->FUN_004030b0();
    if (tmp != 0)
    {
        if (FUN_0097ee90() || field_1C4->FUN_00981420())
            return true;
    }
    if (tmp == 0 && field_C4 != 0 && *field_C4 == 2)
        return true;
    return false;
}
}  // namespace fnv_009a0a80

struct Target
{
    float f[8];
};
struct FUN_009a0b00_s
{
    char pad[0xc4];
    Target* t;
    bool FUN_009a0a80();
    float GetScaledValue();
    float FUN_009a0b00();
};
// Returns t->f[7] when FUN_009a0a80() succeeds, otherwise returns the result of GetScaledValue().
// @fnv 0x009a0b00
float FUN_009a0b00_s::FUN_009a0b00()
{
    if (FUN_009a0a80())
        return t->f[7];
    return GetScaledValue();
}

namespace fnv_009a0b70 {
struct Setting_S
{
    float* Float();
};
struct SettingT_GameSettingCollection : Setting_S
{
};
extern SettingT_GameSettingCollection originalRuntimeFloatSetting424;
extern double const DAT_0101de30;

struct InnerData
{
    char pad0;
    unsigned char flag;
    char pad[0x16];
    float val18;
    float val1c;
};

struct FUN_009a0b70_shell
{
    char pad_c4[0xc4];
    InnerData* ptr;
    float GetInterpolatedValue();
};

// Returns ptr->val1c plus the runtime float setting when ptr->flag is set, otherwise interpolates between ptr->val18 and ptr->val1c using DAT_0101de30.
// @fnv 0x009a0b70
float FUN_009a0b70_shell::GetInterpolatedValue()
{
    if (ptr->flag)
        return ptr->val1c + *originalRuntimeFloatSetting424.Float();
    return (ptr->val1c - ptr->val18) * DAT_0101de30 + ptr->val18;
}
}  // namespace fnv_009a0b70

extern int DAT_0108e068;
struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
};
struct FUN_009a33e0_shell : AX
{
    FUN_009a33e0_shell* FUN_009a33e0();
};
// Sets the object's vtable pointer to DAT_0108e068, calls FUN_006b3eb0(0, 0), and returns this.
// @fnv 0x009a33e0
FUN_009a33e0_shell* FUN_009a33e0_shell::FUN_009a33e0()
{
    *(int**)this = &DAT_0108e068;
    FUN_006b3eb0(0, 0);
    return this;
}

extern int DAT_0108e07c;
struct FUN_009a39f0_t
{
    void FUN_009a39f0(unsigned int, unsigned int);
};
struct FUN_009a3430_shell : FUN_009a39f0_t
{
    FUN_009a3430_shell* FUN_009a3430();
};
// Sets the object's vtable pointer to DAT_0108e07c, calls FUN_009a39f0(0, 0), and returns this.
// @fnv 0x009a3430
FUN_009a3430_shell* FUN_009a3430_shell::FUN_009a3430()
{
    *(int**)this = &DAT_0108e07c;
    FUN_009a39f0(0, 0);
    return this;
}

namespace fnv_009a3460 {
extern int DAT_0108e07c;
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_009a3460_shell : GlobalObject_00869f00
{
    void FUN_009a3460();
};
// @fnv 0x009a3460
void FUN_009a3460_shell::FUN_009a3460()
{
    *(int**)this = &DAT_0108e07c;
    Clear(true);
}
}  // namespace fnv_009a3460

extern int DAT_0108e090;
struct FUN_009a3bc0_t
{
    void Initialize(unsigned int, unsigned int);
};
struct FUN_009a35c0_shell : FUN_009a3bc0_t
{
    FUN_009a35c0_shell* FUN_009a35c0();
};
// Sets the object's vtable pointer to DAT_0108e090, calls Initialize with 0, 0, and returns this.
// @fnv 0x009a35c0
FUN_009a35c0_shell* FUN_009a35c0_shell::FUN_009a35c0()
{
    *(int**)this = &DAT_0108e090;
    Initialize(0, 0);
    return this;
}

namespace fnv_00997480 {
struct S12
{
    int a, b, c;
};
struct S6
{
    short a, b, c;
};

struct RetObj
{
    void FUN_006e4430(const RetObj*);
};

struct FUN_00997480_shell
{
    void FUN_00997480(const FUN_00997480_shell* apCopy);
};

// @fnv 0x00997480
void FUN_00997480_shell::FUN_00997480(const FUN_00997480_shell* apCopy)
{
    *(bool*)((char*)this + 0) = *(bool*)((char*)apCopy + 0);
    *(bool*)((char*)this + 1) = *(bool*)((char*)apCopy + 1);
    *(unsigned char*)((char*)this + 2) = *(unsigned char*)((char*)apCopy + 2);
    *(int*)((char*)this + 4) = *(int*)((char*)apCopy + 4);
    *(S12*)((char*)this + 8) = *(S12*)((char*)apCopy + 8);
    ((RetObj*)((char*)this + 0x14))->FUN_006e4430((RetObj*)((char*)apCopy + 0x14));
    *(unsigned int*)((char*)this + 0x68) = *(unsigned int*)((char*)apCopy + 0x68);
    *(unsigned int*)((char*)this + 0x6c) = *(unsigned int*)((char*)apCopy + 0x6c);
    *(S6*)((char*)this + 0x70) = *(S6*)((char*)apCopy + 0x70);
}
}  // namespace fnv_00997480

namespace fnv_00997520 {
struct S12
{
    int a, b, c;
};
struct S4
{
    int a;
};
struct Helper;
struct Host
{
    void ProcessElements(Helper*);
};
struct Unk975C0
{
    void FUN_009975c0();
};
struct FUN_00997520_shell : Unk975C0
{
    void FUN_00997520(const void* apParam);
};

// @fnv 0x00997520
void FUN_00997520_shell::FUN_00997520(const void* apParam)
{
    if (!apParam)
    {
        FUN_009975c0();
        return;
    }
    *(S12*)((char*)this + 0) = *(S12*)((char*)apParam + 0);
    *(S12*)((char*)this + 0xc) = *(S12*)((char*)apParam + 0xc);
    *(float*)((char*)this + 0x18) = *(float*)((char*)apParam + 0x18);
    *(S4*)((char*)this + 0x1c) = *(S4*)((char*)apParam + 0x1c);
    ((Host*)((char*)apParam + 0x20))->ProcessElements((Helper*)((char*)this + 0x20));
    *(int*)((char*)this + 0x30) = *(int*)((char*)apParam + 0x30);
    *(int*)((char*)this + 0x34) = *(int*)((char*)apParam + 0x34);
    *(char*)((char*)this + 0x38) = *(char*)((char*)apParam + 0x38);
}
}  // namespace fnv_00997520

namespace fnv_00997aa0 {
struct FUN_00981340_shell
{
    void FreeSlot(int);
};

struct FUN_009a0680_shell : FUN_00981340_shell
{
    void ClearAndDeletePointer();
};

struct FUN_0099a9a0_shell : FUN_009a0680_shell
{
    void FUN_009a03d0(int);
    void ReleaseStageHolder(int);
};

struct FUN_009a0a40_shell : FUN_0099a9a0_shell
{
};

void __fastcall FreeAndClearFieldC4(FUN_009a0a40_shell*);

struct PrimaryBase : FUN_009a0a40_shell
{
    int pad[9];
    void FUN_0099a2a0();
};

struct GlobalObject_00869f00;
void __fastcall FUN_009a3410(GlobalObject_00869f00*);

struct Base_009a3410
{
    int pad;
    ~Base_009a3410()
    {
        FUN_009a3410((GlobalObject_00869f00*)this);
    }
};

struct FUN_006e4d00_shell
{
    int pad;
    void CallMemberFunction();
    ~FUN_006e4d00_shell()
    {
        CallMemberFunction();
    }
};

struct FUN_009a3460_shell
{
    int pad;
    void FUN_009a3460();
    ~FUN_009a3460_shell()
    {
        FUN_009a3460();
    }
};

struct FUN_009a35f0_class
{
    int pad;
    void FUN_009a35f0();
    ~FUN_009a35f0_class()
    {
        FUN_009a35f0();
    }
};

struct Ptr2_006e9e20
{
    int pad;
    ~Ptr2_006e9e20();
};

struct FUN_00997aa0 : PrimaryBase, Base_009a3410
{
    char pad_28[0xec - 0x28];
    FUN_006e4d00_shell m_ec;
    char pad_f0[0x128 - 0xf0];
    FUN_006e4d00_shell m_128;
    char pad_12c[0x164 - 0x12c];
    FUN_009a3460_shell m_164;
    char pad_168[0x174 - 0x168];
    FUN_009a35f0_class m_174;
    char pad_178[0x224 - 0x178];
    Ptr2_006e9e20 m_224;

    ~FUN_00997aa0();
};

// @fnv 0x00997aa0
FUN_00997aa0::~FUN_00997aa0()
{
    FUN_0099a2a0();
    FUN_009a03d0(0);
    ReleaseStageHolder(0);
    ClearAndDeletePointer();
    FreeAndClearFieldC4(this);
    for (unsigned int i = 0; i < 5; ++i)
    {
        FreeSlot(i);
    }
}
}  // namespace fnv_00997aa0

namespace fnv_00997c30 {
struct TESAmmoInitCalls
{
    void* GetFieldBC();
};

bool __cdecl FUN_0097f310(void*, int);

struct FUN_00997cb0_Class
{
    void FUN_00997cb0();
};

struct SubObj
{
    virtual void vf0();
    virtual void vf1();
    virtual bool vf2(bool);
};

struct FUN_00997c30_shell : FUN_00997cb0_Class
{
    void EvaluateWeaponScores();
    void InitAmmoState();
};

// @fnv 0x00997c30
void FUN_00997c30_shell::InitAmmoState()
{
    void* local4 = (void*)((TESAmmoInitCalls*)*(void**)((char*)this + 0x1c4))->GetFieldBC();
    *(char*)((char*)this + 0x75) = FUN_0097f310(local4, 0);
    EvaluateWeaponScores();
    FUN_00997cb0();
    *(char*)((char*)this + 0xc8) = ((SubObj*)((char*)local4 + 0xa4))->vf2(true);
    *(char*)((char*)this + 0xc9) = *(char*)((char*)this + 0xc8);
    *(char*)((char*)this + 0x1c8) = 0;
}
}  // namespace fnv_00997c30

namespace fnv_00999160 {
struct CombatTargetTimestamp;

struct TESAmmoInitCalls
{
    unsigned int GetFieldBC();
};

struct AlchemyItem : TESAmmoInitCalls
{
    int FUN_004030b0();
};

struct MyClass
{
    void UpdateTargetPerception(int, int, int*, CombatTargetTimestamp*, bool*, bool*);
};

struct EffectSetting : AlchemyItem
{
    MyClass* GetCastSound();
};

struct Setting_S
{
    float* Float();
};

extern Setting_S g_011cf198;
extern Setting_S originalRuntimeFloatSetting492;

struct FUN_008d7f40_shell
{
    void FUN_008d7f40(float);
};

struct TimeoutTimer : FUN_008d7f40_shell
{
    bool CheckTimer();
};

struct FUN_00999160_struct
{
    char pad_00[0x1c4];
    EffectSetting* field_1C4;

    void EvaluateWeaponScores();
    void FUN_009a1010();
    void UpdateRangeValue();

    void FUN_00999160();
};

// Reads count and target from field_1C4, calls UpdateTargetPerception with this's offsets when target is set, then runs timer-gated updates at 0x204 and 0x20c.
// @fnv 0x00999160
void FUN_00999160_struct::FUN_00999160()
{
    unsigned int count = field_1C4->GetFieldBC();
    int target = field_1C4->FUN_004030b0();
    if (target)
    {
        field_1C4->GetCastSound()->UpdateTargetPerception(count, target, (int*)((char*)this + 0x6c),
                                                          (CombatTargetTimestamp*)((char*)this + 0x94),
                                                          (bool*)((char*)this + 0x70), (bool*)((char*)this + 0x71));
    }
    if (*(bool*)((char*)this + 0x77))
    {
        EvaluateWeaponScores();
    }
    if (((TimeoutTimer*)((char*)this + 0x204))->CheckTimer())
    {
        FUN_009a1010();
        ((TimeoutTimer*)((char*)this + 0x204))->FUN_008d7f40(*g_011cf198.Float());
    }
    if (((TimeoutTimer*)((char*)this + 0x20c))->CheckTimer())
    {
        UpdateRangeValue();
        ((TimeoutTimer*)((char*)this + 0x20c))->FUN_008d7f40(*originalRuntimeFloatSetting492.Float());
    }
}
}  // namespace fnv_00999160

struct WEAPStub;

struct FUN_0097ac90_shell
{
    float FUN_0097ac90(int);
};

struct CombatStateStub
{
    WEAPStub* FUN_0097c150(int);
};

struct FUN_0099a2d0_shell
{
    WEAPStub* GetBestWeapon();
};

// Scores weapon types 0-6 via FUN_0097ac90 and returns the weapon from FUN_0097c150 with the highest score, or null for type 6.
// @fnv 0x0099a2d0
WEAPStub* FUN_0099a2d0_shell::GetBestWeapon()
{
    float bestScoreA = 0.0f;
    WEAPStub* kBestWeapon = 0;
    for (unsigned int i = 0; i < 7; ++i)
    {
        float fScore2;
        int weaponType = i;
        fScore2 = ((FUN_0097ac90_shell*)this)->FUN_0097ac90(weaponType);
        if (fScore2 > bestScoreA)
        {
            bestScoreA = fScore2;
            kBestWeapon = (weaponType != 6) ? (kBestWeapon = ((CombatStateStub*)this)->FUN_0097c150(weaponType)) : 0;
        }
    }
    return kBestWeapon;
}

namespace fnv_0099a840 {
struct FUN_008d7f40_shell
{
    void FUN_008d7f40(float);
};

struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting425;
extern Setting_S originalRuntimeFloatSetting426;

struct FUN_0099a840_shell
{
    void FUN_0099a840(void* apItem);
};

// @fnv 0x0099a840
void FUN_0099a840_shell::FUN_0099a840(void* apItem)
{
    for (unsigned int i = 0; i < 2; ++i)
    {
        if (*(void**)((char*)this + 0x1a4 + i * 4) == apItem)
        {
            float val = 0.0f;
            switch (i + 17)
            {
            case 17:
                val = *originalRuntimeFloatSetting425.Float();
            case 18:
                val = *originalRuntimeFloatSetting426.Float();
                break;
            }
            ((FUN_008d7f40_shell*)((char*)this + 0x1ac + i * 8))->FUN_008d7f40(val);
            break;
        }
    }
}
}  // namespace fnv_0099a840

namespace fnv_0099a8d0 {
struct NiPoint3
{
    float x, y, z;
};

struct AlchemyItem
{
    void* FUN_004030b0();
};

struct LocS
{
    void* GetLocation();
};

struct FUN_005407b0_Class
{
    char pad0[0x14];
    LocS loc;
    void FUN_005407b0(char);
};

struct Field18C
{
    char pad0[0x14];
    int state;
};

struct FUN_0099a8d0_struct;
bool __fastcall FUN_0097fb20(FUN_0099a8d0_struct*);

struct FUN_009a0680_shell
{
    void ClearAndDeletePointer();
};

struct FUN_00999100_shell : FUN_009a0680_shell
{
    bool FUN_00999100();
};

struct FUN_0099a8d0_struct : FUN_00999100_shell
{
    char pad0[0xe4];
    FUN_005407b0_Class* field_E4;
    char padE8[0x18c - 0xe8];
    Field18C* field_18C;
    char pad190[0x1c4 - 0x190];
    AlchemyItem* field_1C4;

    bool FUN_0099ccd0(void*, void*, NiPoint3*, void*, int);
    void EvaluateWeaponScores();

    void FUN_0099a8d0();
};

// @fnv 0x0099a8d0
void FUN_0099a8d0_struct::FUN_0099a8d0()
{
    void* ptr4 = field_1C4->FUN_004030b0();
    if (field_E4 && ptr4)
    {
        NiPoint3 local_14;
        bool bSafe = FUN_0099ccd0(&field_E4->loc, field_E4->loc.GetLocation(), &local_14, ptr4, 0);
        if (!bSafe || !FUN_0097fb20(this))
        {
            field_E4->FUN_005407b0(1);
        }
    }
    if (field_18C)
    {
        if (field_18C->state == 0 || field_18C->state == 1)
        {
            ClearAndDeletePointer();
        }
    }
    FUN_00999100();
    EvaluateWeaponScores();
}
}  // namespace fnv_0099a8d0

struct NiPoint3
{
    float x, y, z;
};

extern int DAT_0106cbc0;

struct StandInShell
{
    StandInShell* FUN_006dcc40(void*);
};

struct FUN_0099aa80_struct : StandInShell
{
    void* vtable;
    char pad4[0x28 - 4];
    NiPoint3 pt28;
    NiPoint3 pt34;
    NiPoint3 pt40;
    char b4c;
    char b4d;
    char b4e;
    char b4f;
    char b50;
    char b51;
    char b52;

    FUN_0099aa80_struct* FUN_0099aa80(FUN_0099aa80_struct* other);
};

// @fnv 0x0099aa80
FUN_0099aa80_struct* FUN_0099aa80_struct::FUN_0099aa80(FUN_0099aa80_struct* other)
{
    FUN_006dcc40(other);
    vtable = &DAT_0106cbc0;
    pt28 = other->pt28;
    pt34 = other->pt34;
    pt40 = other->pt40;
    b4c = other->b4c;
    b4d = other->b4d;
    b4e = other->b4e;
    b4f = other->b4f;
    b50 = other->b50;
    b51 = other->b51;
    b52 = other->b52;
    return this;
}

namespace fnv_0099ca00 {
extern const float DAT_01017718;

struct ParentSpaceNode
{
};

struct _ref_006815c0 : ParentSpaceNode
{
    int a, b, c;
    _ref_006815c0();
};

struct Inner097
{
    int pad[4];
    void FUN_0097ede0();
    _ref_006815c0* _ref_006815c0();
};

struct Member
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual void d74();
    virtual void d75();
    virtual void d76();
    virtual void d77();
    virtual void d78();
    virtual void d79();
    virtual void d80();
    virtual void d81();
    virtual void d82();
    virtual void d83();
    virtual void d84();
    virtual void d85();
    virtual void d86();
    virtual void d87();
    virtual void d88();
    virtual void d89();
    virtual void d90();
    virtual void d91();
    virtual void d92();
    virtual void d93();
    virtual void d94();
    virtual void d95();
    virtual void d96();
    virtual void d97();
    virtual void d98();
    virtual void d99();
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
    virtual void d116();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual _ref_006815c0* GetPos();
};

struct EffectSetting
{
    struct ActorCombatGroup* GetCastSound();
};

struct ActorCombatGroup
{
    unsigned int GetVirtualNodeCount();
    Member* FUN_00968630(int);
    bool TryGetQuadForState(int, Inner097*, float);
};

bool __cdecl FUN_0099cc60(void*, ParentSpaceNode*, int);

struct FUN_0099ca00_struct
{
    char pad0[0x1c4];
    EffectSetting* field_1C4;

    bool FUN_0099ca00(void* arg1, Member* ignore);
};

// @fnv 0x0099ca00
bool FUN_0099ca00_struct::FUN_0099ca00(void* arg1, Member* pIgnoreMember)
{
    ActorCombatGroup* group = field_1C4->GetCastSound();
    unsigned int count = group->GetVirtualNodeCount();
    for (unsigned int i = 0; i < count; ++i)
    {
        Member* member = group->FUN_00968630(i);
        if (member == pIgnoreMember)
        {
            continue;
        }
        Inner097 loc;
        loc.FUN_0097ede0();
        _ref_006815c0 pos;
        if (group->TryGetQuadForState(i, &loc, DAT_01017718))
        {
            pos = *loc._ref_006815c0();
        }
        else
        {
            pos = *member->GetPos();
        }
        if (FUN_0099cc60(arg1, &pos, 0))
        {
            return true;
        }
    }
    return false;
}
}  // namespace fnv_0099ca00

namespace fnv_0099cb70 {
extern const float DAT_01017718;

struct _ref_006815c0
{
    int a, b, c;
    _ref_006815c0();
};

struct Inner097
{
    int pad[4];
    void FUN_0097ede0();
    _ref_006815c0* _ref_006815c0();
};

struct Member
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual void d74();
    virtual void d75();
    virtual void d76();
    virtual void d77();
    virtual void d78();
    virtual void d79();
    virtual void d80();
    virtual void d81();
    virtual void d82();
    virtual void d83();
    virtual void d84();
    virtual void d85();
    virtual void d86();
    virtual void d87();
    virtual void d88();
    virtual void d89();
    virtual void d90();
    virtual void d91();
    virtual void d92();
    virtual void d93();
    virtual void d94();
    virtual void d95();
    virtual void d96();
    virtual void d97();
    virtual void d98();
    virtual void d99();
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
    virtual void d116();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual _ref_006815c0* GetPos();
};

struct EffectSetting
{
    struct ActorCombatGroup* GetCastSound();
};

struct ActorCombatGroup
{
    unsigned int GetVirtualNodeCount();
    Member* FUN_00968630(int);
    bool TryGetQuadForState(int, Inner097*, float);
};

struct Arr_006cee30
{
    void FUN_006cee30(int);
    void AddItem(_ref_006815c0*);
};

struct FUN_0099cb70_struct
{
    char pad0[0x1c4];
    EffectSetting* field_1C4;

    void CollectCastSoundPositions(Arr_006cee30* array);
};

// @fnv 0x0099cb70
void FUN_0099cb70_struct::CollectCastSoundPositions(Arr_006cee30* array)
{
    ActorCombatGroup* group = field_1C4->GetCastSound();
    unsigned int count = group->GetVirtualNodeCount();
    array->FUN_006cee30(count);
    for (unsigned int i = 0; i < count; ++i)
    {
        Member* member = group->FUN_00968630(i);
        Inner097 loc;
        loc.FUN_0097ede0();
        _ref_006815c0 pos;
        if (group->TryGetQuadForState(i, &loc, DAT_01017718))
        {
            pos = *loc._ref_006815c0();
        }
        else
        {
            pos = *member->GetPos();
        }
        array->AddItem(&pos);
    }
}
}  // namespace fnv_0099cb70

namespace fnv_009a02a0 {
struct CoordinateTriple
{
    double FUN_00527a40(CoordinateTriple*);
};

struct LocationTarget
{
    unsigned char type;
    char pad[7];
    CoordinateTriple location;
};

struct ABD_005f92d0
{
    bool GetFlag(unsigned int) const;
};

struct FUN_009a02a0_struct : ABD_005f92d0
{
    char pad0[0xc4];
    LocationTarget* pAssociatedObject;

    float GetIdleAdjustedValue();
    bool HasItemWithinRadius(const CoordinateTriple& loc, float f);

    bool FUN_009a02a0(const CoordinateTriple& arWorldLocation, bool abCheckLocationReachable,
                      bool abIgnoreCombatAreaCheck);
};

// @fnv 0x009a02a0
bool FUN_009a02a0_struct::FUN_009a02a0(const CoordinateTriple& arWorldLocation, bool abCheckLocationReachable,
                                       bool abIgnoreCombatAreaCheck)
{
    if (pAssociatedObject)
    {
        if ((pAssociatedObject->type == 1 && !GetFlag(0x100)) || pAssociatedObject->type == 2 ||
            (pAssociatedObject->type == 3 && !abIgnoreCombatAreaCheck))
        {
            float fmaxDistance = GetIdleAdjustedValue();
            if (((CoordinateTriple&)arWorldLocation).FUN_00527a40(&pAssociatedObject->location) >
                fmaxDistance * fmaxDistance)
            {
                return false;
            }
        }
    }
    if (abCheckLocationReachable && HasItemWithinRadius(arWorldLocation, -1.0f))
    {
        return false;
    }
    return true;
}
}  // namespace fnv_009a02a0

namespace fnv_009a0470 {
struct StageHolder
{
    bool GetDone();
};

struct CombatCoverPointData;

struct FUN_009d6c80_shell
{
    void FUN_009a05b0(CombatCoverPointData*);
};

struct FUN_006d3370_s
{
    ~FUN_006d3370_s();
};

struct FUN_009a0470_shell : FUN_009d6c80_shell
{
    void StoreEntry(int);
    void ReleaseStageHolder(bool);
};

// @fnv 0x009a0470
void FUN_009a0470_shell::ReleaseStageHolder(bool bParam)
{
    if (*(void**)((char*)this + 0xe8))
    {
        if (bParam)
        {
            StoreEntry(*(int*)(*(char**)((char*)this + 0xe8) + 0x68));
        }
        if (((StageHolder*)*(void**)((char*)this + 0xe8))->GetDone())
        {
            FUN_009a05b0((CombatCoverPointData*)*(void**)((char*)this + 0xe8));
        }
        delete (FUN_006d3370_s*)*(void**)((char*)this + 0xe8);
        *(void**)((char*)this + 0xe8) = 0;
    }
}
}  // namespace fnv_009a0470

namespace fnv_009a06c0 {
void* __cdecl operator new(unsigned int);

struct TESObjectREFRHelper
{
    void SetTargetingState(bool);
};

struct SL
{
    TESObjectREFRHelper* field_0;
    int field_4;
    SL();
};

struct FUN_00981340_shell
{
    void FreeSlot(int);
};

struct FUN_009a06c0_struct : FUN_00981340_shell
{
    char pad0[0x190];
    SL* array_190[1];

    void SetArrayEntry(int arg1, TESObjectREFRHelper* arg2, int arg3);
};

// @fnv 0x009a06c0
void FUN_009a06c0_struct::SetArrayEntry(int aiIndex, TESObjectREFRHelper* apRefr, int aiValue)
{
    FreeSlot(aiIndex);
    if (apRefr)
    {
        array_190[aiIndex] = new SL();
        array_190[aiIndex]->field_0 = apRefr;
        array_190[aiIndex]->field_4 = aiValue;
        if (apRefr)
        {
            apRefr->SetTargetingState(true);
        }
    }
}
}  // namespace fnv_009a06c0

namespace fnv_009a0c50 {
extern double _gModifierZero;

struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting429;

struct CameraShotHelper
{
    float GetField4C();
};

struct TESAmmoInitCalls
{
    void* GetFieldBC();
};

struct FUN_00980070_shell : TESAmmoInitCalls
{
    CameraShotHelper* FUN_00980070();
};

struct FieldC4
{
    unsigned char byte0;
};

struct Ref_997440
{
    int FUN_00575650(void*, int, float, float);
};

struct Local18
{
    int data[4];
};

struct FUN_009a0c50_class
{
    char pad0[0xc4];
    FieldC4* field_C4;
    char padC8[0x1c4 - 0xc8];
    FUN_00980070_shell* field_1C4;

    void FUN_009a0910(int);
    void UpdateModifierState(bool arg_8);
};

// If field_C4 is null or its byte0 is 3 and arg_8 is set, computes a modifier value and applies it via FUN_009a0910 when it exceeds _gModifierZero.
// @fnv 0x009a0c50
void FUN_009a0c50_class::UpdateModifierState(bool arg_8)
{
    if (field_C4)
    {
        if (field_C4->byte0 != 3 || !arg_8)
        {
            return;
        }
    }
    float f = field_1C4->FUN_00980070()->GetField4C();
    if (f > _gModifierZero)
    {
        Ref_997440* pRef = (Ref_997440*)field_1C4->GetFieldBC();
        {
            Local18 localData;
            FUN_009a0910(pRef->FUN_00575650(&localData, 3, f * *originalRuntimeFloatSetting429.Float(), f));
        }
    }
}
}  // namespace fnv_009a0c50

namespace fnv_009a0d70 {
struct CTSHelper
{
    float GetElapsedTime();
};

struct ArrSI
{
    unsigned int GetFlags();
};

struct FUN_00844160_shell
{
    unsigned int FUN_00844160(unsigned int);
};

struct ActorAvoidanceDataArray
{
    void FUN_00983720(unsigned int, unsigned int);
};

struct FUN_009a0d70_shell
{
    bool ContainsItem(void* apItem);
};

// Scans the array at offset 0x164, removing entries whose elapsed time exceeds 10.0, and returns true if any remaining entry's pointer equals apItem.
// @fnv 0x009a0d70
bool FUN_009a0d70_shell::ContainsItem(void* apItem)
{
    for (unsigned int i = 0; i < ((ArrSI*)((char*)this + 0x164))->GetFlags(); ++i)
    {
        void* entry = (void*)((FUN_00844160_shell*)((char*)this + 0x164))->FUN_00844160(i);
        if (((CTSHelper*)((char*)entry + 4))->GetElapsedTime() > 10.0)
        {
            ((ActorAvoidanceDataArray*)((char*)this + 0x164))->FUN_00983720(i, 1);
            --i;
            continue;
        }
        if (*(void**)entry == apItem)
        {
            return true;
        }
    }
    return false;
}
}  // namespace fnv_009a0d70

namespace fnv_009a0e10 {
struct CTSHelper
{
    float GetElapsedTime();
};

struct ArrSI
{
    unsigned int GetFlags();
};

struct FUN_00844160_entry
{
    void* item;
    CTSHelper timer;
};

struct FUN_00844160_shell : ArrSI
{
    FUN_00844160_entry* FUN_00844160(unsigned int);
};

struct ActorAvoidanceDataArray : FUN_00844160_shell
{
    void FUN_00983720(unsigned int, unsigned int);
};

struct HArr
{
    void GrowCapacity(unsigned int);
};

template <typename T, int N> struct BSSimpleArray;

template <> struct BSSimpleArray<void*, 1024> : HArr
{
    unsigned int Add(void*&);
};

struct FUN_009a0e10_shell
{
    char pad[0x164];
    ActorAvoidanceDataArray avoidanceData;

    void CollectAvoidanceItems(BSSimpleArray<void*, 1024>* apArray);
};

// Removes avoidance entries whose timer exceeds 10 seconds and adds the remaining entries' items to the array.
// @fnv 0x009a0e10
void FUN_009a0e10_shell::CollectAvoidanceItems(BSSimpleArray<void*, 1024>* apArray)
{
    apArray->GrowCapacity(avoidanceData.GetFlags());
    for (unsigned int i = 0; i < avoidanceData.GetFlags(); ++i)
    {
        FUN_00844160_entry* entry = avoidanceData.FUN_00844160(i);
        if (entry->timer.GetElapsedTime() > 10.0)
        {
            avoidanceData.FUN_00983720(i, 1);
            --i;
            continue;
        }
        apArray->Add(entry->item);
    }
}
}  // namespace fnv_009a0e10

namespace fnv_009a0f40 {
extern const float runtimeFloatSettingDefault1296;

struct CoordinateTriple
{
    double FUN_00527a40(const CoordinateTriple*);
};

struct CTSHelper
{
    float GetElapsedTime();
};

struct Item : CoordinateTriple
{
    char pad[0x10];
    CTSHelper time;
};

struct ArrSI
{
    unsigned int GetFlags();
};

struct MyArr : ArrSI
{
    Item* FUN_006dad90(unsigned int) const;
    void RemoveEntries(unsigned int, int);
};

struct FUN_009a0f40_struct
{
    char pad0[0x174];
    MyArr array_174;

    bool HasItemWithinRadius(const CoordinateTriple* arWorldLocation, float afRadius);
};

// @fnv 0x009a0f40
bool FUN_009a0f40_struct::HasItemWithinRadius(const CoordinateTriple* arWorldLocation, float afRadius)
{
    float maxDistSq = 0.0f;
    if (afRadius == -1.0)
    {
        maxDistSq = runtimeFloatSettingDefault1296;
    }
    else
    {
        maxDistSq = afRadius * afRadius;
    }

    for (unsigned int i = 0; i < array_174.GetFlags(); ++i)
    {
        Item* item = array_174.FUN_006dad90(i);
        if (item->time.GetElapsedTime() > 10.0)
        {
            array_174.RemoveEntries(i, 1);
            --i;
            continue;
        }
        if (item->FUN_00527a40(arWorldLocation) < maxDistSq)
        {
            return true;
        }
    }
    return false;
}
}  // namespace fnv_009a0f40

struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
};

struct Member14
{
    virtual void SaveGame(BGSSaveFormBuffer*);
};

struct FUN_00982c20
{
    void Save(BGSSaveFormBuffer*);
};

struct FUN_009a2de0_struct
{
    char byte0;
    char byte1;
    char byte2;
    char pad3;
    int dword4;
    char data8[12];
    Member14 member14;
    char pad18[0x68 - 0x14 - sizeof(Member14)];
    int dword68;
    int dword6c;
    FUN_00982c20 member70;

    void FUN_009a2de0(BGSSaveFormBuffer* buffer);
};

// Serializes byte1, byte0, byte2, dword4, data8, member14, dword68, dword6c and member70 into the save buffer.
// @fnv 0x009a2de0
void FUN_009a2de0_struct::FUN_009a2de0(BGSSaveFormBuffer* buffer)
{
    buffer->SaveData(&byte1, 1, 0);
    buffer->SaveData(&byte0, 1, 0);
    buffer->SaveData(&byte2, 1, 0);
    buffer->SaveData(&dword4, 4, 0);
    buffer->SaveData(data8, 12, 0);
    member14.SaveGame(buffer);
    buffer->SaveData(&dword68, 4, 0);
    buffer->SaveData(&dword6c, 4, 0);
    member70.Save(buffer);
}

namespace fnv_009a2ea0 {
struct BGSLoadFormBuffer
{
    void ReadTypedData(void*, unsigned int);
};

struct Member14
{
    virtual void unk0();
    virtual void LoadGame(BGSLoadFormBuffer*);
};

struct Member70
{
    void FUN_00982ca0(BGSLoadFormBuffer*);
};

struct FUN_009a2ea0_struct
{
    char byte0;
    char byte1;
    char byte2;
    char pad3;
    int dword4;
    char data8[12];
    Member14 member14;
    char pad18[0x68 - 0x14 - sizeof(Member14)];
    int dword68;
    int dword6c;
    Member70 member70;

    void FUN_009a2ea0(BGSLoadFormBuffer* buffer);
};

// Reads byte1, byte0, byte2, dword4, data8, dword68 and dword6c from the buffer and calls member14.LoadGame and member70.FUN_00982ca0.
// @fnv 0x009a2ea0
void FUN_009a2ea0_struct::FUN_009a2ea0(BGSLoadFormBuffer* buffer)
{
    buffer->ReadTypedData(&byte1, 1);
    buffer->ReadTypedData(&byte0, 1);
    buffer->ReadTypedData(&byte2, 1);
    buffer->ReadTypedData(&dword4, 4);
    buffer->ReadTypedData(data8, 12);
    member14.LoadGame(buffer);
    buffer->ReadTypedData(&dword68, 4);
    buffer->ReadTypedData(&dword6c, 4);
    member70.FUN_00982ca0(buffer);
}
}  // namespace fnv_009a2ea0

namespace fnv_009a3610 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_0072ba80_shell
{
    void FUN_0072ba80(void*, unsigned int);
};
struct UCL_009a3610
{
    unsigned int m_uiData;
    char pad[0x10];
};
struct FUN_009a3610_arr
{
    virtual void v0();
    virtual UCL_009a3610* Allocate(unsigned int);
    UCL_009a3610* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    void UpdateThreat(unsigned int, unsigned int);
    void ConstructEntries(UCL_009a3610*, unsigned int);
    void FUN_009a3610(unsigned int aiNewSize, bool abFreeMemory);
};
// @fnv 0x009a3610
void FUN_009a3610_arr::FUN_009a3610(unsigned int aiNewSize, bool abFreeMemory)
{
    if (aiNewSize == 0)
    {
        ((GlobalObject_00869f00*)this)->Clear(abFreeMemory);
    }
    else if (aiNewSize > SimpleArrayStorage)
    {
        if (SimpleArrayStorage == 0)
        {
            pBuffer = Allocate(aiNewSize);
            SimpleArrayStorage = aiNewSize;
        }
        else
        {
            UpdateThreat(aiNewSize, iSize);
            SimpleArrayStorage = aiNewSize;
        }
        ConstructEntries(&pBuffer[iSize], aiNewSize - iSize);
        iSize = aiNewSize;
    }
    else if (aiNewSize < iSize)
    {
        ((FUN_0072ba80_shell*)this)->FUN_0072ba80(&pBuffer[aiNewSize], iSize - aiNewSize);
        iSize = aiNewSize;
        if (abFreeMemory && aiNewSize <= SimpleArrayStorage >> 2)
        {
            UpdateThreat(aiNewSize, aiNewSize);
            SimpleArrayStorage = aiNewSize;
        }
    }
    else
    {
        ConstructEntries(&pBuffer[iSize], aiNewSize - iSize);
        iSize = aiNewSize;
    }
}
}  // namespace fnv_009a3610

struct TESObjectWEAP;

bool __fastcall FUN_006450c0(TESObjectWEAP*);
int __fastcall FUN_007031c0(int);

struct ActH2
{
    void* GetActiveWeapon();
};

struct S981990
{
    bool FUN_00981940(int);
};

// @fnv 0x009a9630
bool FUN_009a9630(void* apActor)
{
    TESObjectWEAP* weapon = 0;
    void* pcombatController = (*(void*(__thiscall**)(void*))(*(char**)apActor + 0x428))(apActor);
    if (pcombatController)
    {
        weapon = (TESObjectWEAP*)FUN_007031c0((int)pcombatController);
    }
    else
    {
        weapon = (TESObjectWEAP*)((ActH2*)apActor)->GetActiveWeapon();
    }

    if (!weapon || FUN_006450c0(weapon))
    {
        return true;
    }

    if (pcombatController &&
        (((S981990*)pcombatController)->FUN_00981940(7) || ((S981990*)pcombatController)->FUN_00981940(8)))
    {
        return true;
    }

    return false;
}

namespace fnv_009a0910 {
struct FUN_009a0a40_shell;
struct FUN_009a08d0_Cls;

struct FUN_009a0910_Vector
{
    float x;
    float y;
    float z;
    float w;
};

void __fastcall FreeAndClearFieldC4(FUN_009a0a40_shell*);
float __cdecl _FUN_00404010(float, float);

unsigned int _data_011c16bc;

struct Setting_S
{
    float* Float();
};

struct GameSettingCollection
{
};

template <class T> struct SettingT : public Setting_S
{
};

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting423;

struct FUN_009a08d0_Cls
{
    unsigned char flag;
    int field4;
    FUN_009a0910_Vector value;
    float value18;
    float value1c;

    FUN_009a08d0_Cls();
};

struct FUN_009a0910_shell
{
    unsigned char padding[0xc4];
    FUN_009a08d0_Cls* fieldC4;

    void FUN_009a0910(FUN_009a0910_Vector* value, unsigned char flag, float value10, float value14);
};

// Calls FreeAndClearFieldC4, allocates a FUN_009a08d0_Cls into fieldC4 and stores the flag, vector, and two clamped float values.
// @fnv 0x009a0910
void FUN_009a0910_shell::FUN_009a0910(FUN_009a0910_Vector* apVector, unsigned char flag, float value10, float value14)
{
    FreeAndClearFieldC4(reinterpret_cast<FUN_009a0a40_shell*>(this));

    fieldC4 = new FUN_009a08d0_Cls;

    fieldC4->flag = flag;
    fieldC4->field4 = 0;
    fieldC4->value = *apVector;

    fieldC4->value18 = _FUN_00404010(value10, *originalRuntimeFloatSetting423.Float());
    fieldC4->value1c = _FUN_00404010(value14, *originalRuntimeFloatSetting423.Float());
}
}  // namespace fnv_009a0910

namespace fnv_009a3480 {
struct Actor
{
    unsigned int field_0;
    unsigned int field_4;
};

struct BSSimpleArrayActor
{
    virtual void FUN_00000000() = 0;
    virtual Actor* Allocate(unsigned int count) = 0;

    void Clear(bool clear);
    Actor* m_buffer;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;
};

struct FUN_0072ba80_shell : public BSSimpleArrayActor
{
    void FUN_0072ba80(char* data, unsigned int count);
};

struct S5460 : public FUN_0072ba80_shell
{
    void FUN_006a2770(unsigned int first, unsigned int second);
    void ConstructObjects(Actor* data, unsigned int count);
    void FUN_009a3480(unsigned int count, bool clear);
};

// @fnv 0x009a3480
void S5460::FUN_009a3480(unsigned int count, bool clear)
{
    if (count == 0)
    {
        Clear(clear);
    }
    else if (count > m_pRayCursor)
    {
        if (m_pRayCursor == 0)
        {
            m_buffer = Allocate(count);
            m_pRayCursor = count;
        }
        else
        {
            FUN_006a2770(count, m_iElementCount);
            m_pRayCursor = count;
        }

        ConstructObjects(m_buffer + m_iElementCount, count - m_iElementCount);
        m_iElementCount = count;
    }
    else if (count < m_iElementCount)
    {
        FUN_0072ba80_shell::FUN_0072ba80((char*)(m_buffer + count), m_iElementCount - count);
        m_iElementCount = count;

        if (clear && count <= (m_pRayCursor >> 2))
        {
            FUN_006a2770(count, count);
            m_pRayCursor = count;
        }
    }
    else
    {
        ConstructObjects(m_buffer + m_iElementCount, count - m_iElementCount);
        m_iElementCount = count;
    }
}
}  // namespace fnv_009a3480

struct CombatTimer999260
{
    bool IsExpired();
    void Reset(float afTime);
};
struct ValueSource999260
{
    float GetValue();
};
struct CombatController999260
{
    int GetActor();
    ValueSource999260* GetValueSource();
};
struct FloatSetting999260
{
    float* Float();
};
extern FloatSetting999260 originalRuntimeFloatSetting357;
bool RandomBoolean(float);
extern const float fCombatTimerReset999260a;
extern const float fCombatTimerReset999260b;
extern double _gModifierZero;

struct FUN_00999260_shell
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
    unsigned int iFlags;
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
    CombatController999260* pController;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    CombatTimer999260 timer1e4;
    int unk1e8;
    CombatTimer999260 timer1ec;
    void UpdateCombatFlags();
};

// Refreshes the two combat timers when expired and sets iFlags bits from the runtime float setting and the controller's value source.
// @fnv 0x00999260
void FUN_00999260_shell::UpdateCombatFlags()
{
    int iActor = pController->GetActor();
    if (timer1e4.IsExpired())
    {
        iFlags &= 0xffff00ff;
        if (RandomBoolean(*originalRuntimeFloatSetting357.Float()))
        {
            iFlags |= 0x100;
        }
        timer1e4.Reset(fCombatTimerReset999260a);
    }
    if (timer1ec.IsExpired())
    {
        iFlags &= 0xffffff00;
        float fValue = pController->GetValueSource()->GetValue();
        if (RandomBoolean(fValue / 100.0))
        {
            iFlags |= 1;
        }
        if (fValue > _gModifierZero)
        {
            iFlags |= 2;
        }
        timer1ec.Reset(fCombatTimerReset999260b);
    }
}

// Menu event hook: on event 15 forward the argument to the active list, and refresh when the
// tracked item's id matches the event id.

class AA10List
{
  public:
    void HandleEvent(int iArg);
};

class AA10Source
{
  public:
    AA10List* GetList();
};

class AA10Item
{
  public:
    unsigned int GetID();
};

class AA10Menu
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
    AA10Item* m_pkTrackedItem;
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
    AA10Source* m_pkSource;

    void Refresh();
    void HandleMenuEvent(int iArg, unsigned int uiEvent);
};

// Handles event 15 by forwarding iArg to the source list, and refreshes when the tracked item's ID equals uiEvent.
// @fnv 0x0099aa10
void AA10Menu::HandleMenuEvent(int iArg, unsigned int uiEvent)
{
    switch (uiEvent)
    {
    case 15:
        m_pkSource->GetList()->HandleEvent(iArg);
        break;
    }

    if (m_pkTrackedItem)
    {
        unsigned int uiItemID = m_pkTrackedItem->GetID();
        if (uiItemID == uiEvent)
            Refresh();
    }
}

struct Pt3
{
    float x, y, z;
    Pt3();
    Pt3 operator-(const Pt3& o) const;
    float FUN_00589850();
};

struct Seg99
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
    Pt3 start;
    Pt3 end;
};

struct Timer99
{
    bool FUN_00998a30();
    float FUN_00453700();
    float GetFieldCC();
};

float FUN_0040ebd0(float, float);
float GetScaleOrHeightDelta(TESObjectREFR*, int);
bool FUN_006ba6e0(Pt3*, Pt3*, Pt3*, Pt3*, Pt3*);

struct Combat99
{
    char unk000;
    char unk001;
    char unk002;
    char unk003;
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
    Timer99* pTimer;
    bool FUN_0099cec0(Seg99* apSeg, Pt3* apFrom, Pt3* apTarget, TESObjectREFR* apRef);
};

// @fnv 0x0099cec0
bool Combat99::FUN_0099cec0(Seg99* apSeg, Pt3* apFrom, Pt3* apTarget, TESObjectREFR* apRef)
{
    float fTop3 = FUN_0040ebd0(apSeg->start.z, apSeg->end.z);
    if (apTarget->z >= fTop3)
    {
        return false;
    }
    else
    {
        Pt3 kTarget4 = *apTarget;
        kTarget4.z += GetScaleOrHeightDelta(apRef, 1);
        if (kTarget4.z >= fTop3)
        {
            return false;
        }
        else
        {
            Pt3 kHit3;
            bool bHitB = FUN_006ba6e0(&apSeg->start, &apSeg->end, &kTarget4, apFrom, &kHit3);
            if (!bHitB)
                return false;
            float m_fGlyphExtent = kHit3.z - kTarget4.z;
            Pt3 kDiff9 = kHit3 - kTarget4;
            float fDist6 = kDiff9.FUN_00589850();
            Pt3 kDiffVal = kHit3 - *apFrom;
            float fLen2 = kDiffVal.FUN_00589850();
            float fScaledTmp = m_fGlyphExtent * fLen2 / fDist6;
            float fLimit3 = pTimer->FUN_00998a30() ? pTimer->FUN_00453700() : pTimer->GetFieldCC();
            if (fLimit3 > fScaledTmp)
                return false;
        }
    }
    return true;
}

struct PosHolder;
struct Vec3
{
    float x, y, z;
    Vec3();
    Vec3* Self();
    Vec3 operator-(const Vec3& o) const;
    Vec3 operator+(const Vec3& o) const;
    Vec3 operator*(float s) const;
    Vec3 Neg() const;
    void Normalize();
    Vec3 Cross(const Vec3& o) const;
    float Length() const;
};

struct MyTimer
{
    float t;
    MyTimer(float v);
    MyTimer(const MyTimer& o);
    float Get();
};

struct Picker
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
    Picker(void* p);
    Picker();
    ~Picker();
    Vec3 GetPoint();
};

struct MyMover
{
    void FUN_0099b8b0(Vec3* p, int a);
};

struct MyActor
{
    virtual void v0();
    float FUN_008be1b0();
    void FUN_00575650(PosHolder* out);
};

struct MyRef
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
    virtual Vec3* GetPos();
};

struct MyProc
{
    MyActor* GetFieldBC();
    MyRef* FUN_004030b0();
};

struct PosHolder
{
    float unk00, unk04, unk08;
    int unk0C;
    Vec3* Self();
    int FUN_0084e3a0(int a, int b);
};

struct Result
{
    float EvaluateThreats();
};

struct Mgr
{
    Result* FUN_00825c00(Vec3 v, MyActor* a, float f1, float f2, MyTimer t, float f3);
};

extern Mgr* DAT_011f1958;
extern Vec3 DAT_011a9484;
float FUN_00435dd0();
bool FUN_006d7490(Picker* a, Vec3* b, Picker* c, int d);
bool FUN_009a7940(MyActor* a, MyRef* r, Vec3* v, Vec3* w, int x, int y);
int FUN_005a00a0(int n);

struct FUN_0099e190_cls
{
    char unk000[0x184];
    MyTimer timer;
    signed char last;
    char pad189[0x1c4 - 0x189];
    MyProc* proc;
    bool FUN_009a0260(Vec3* v, int x);
    bool SelectAndMoveToPoint(MyMover* mover, unsigned int mask1, unsigned int mask2, float dist, float minDist);
};

// Tests up to four candidate points around the actor against masks and distance limits, then moves the mover to a chosen valid point.
// @fnv 0x0099e190
bool FUN_0099e190_cls::SelectAndMoveToPoint(MyMover* mover, unsigned int mask1, unsigned int mask2, float dist,
                                            float minDist)
{
    MyActor* A9 = proc->GetFieldBC();
    MyRef* ref = proc->FUN_004030b0();
    float radius = A9->FUN_008be1b0() + 8.0;
    PosHolder h7;
    A9->FUN_00575650(&h7);
    Vec3 pp = *h7.Self();
    Vec3 T = *ref->GetPos();
    Picker p4(A9);
    Vec3 D_ = pp - T;
    D_.Normalize();
    Vec3 s = D_.Cross(DAT_011a9484);
    Vec3 A5[4];
    signed char slot[4];
    signed char dirOf[4];
    int n = 0;
    for (unsigned int i = 0; i < 4; i++)
    {
        slot[i] = -1;
        unsigned int bit = 1 << i;
        if (mask1 & bit)
        {
            Vec3 off;
            switch (bit)
            {
            case 1:
                off = s;
                break;
            case 2:
                off = s.Neg();
                break;
            case 4:
                off = D_.Neg();
                break;
            case 8:
                off = D_;
                break;
            }
            Vec3 target = pp + off * dist;
            Vec3 end = target + off * radius;
            if (DAT_011f1958->FUN_00825c00(target, A9, 0.0f, 0.0f, MyTimer(0.0f), 0.0f)->EvaluateThreats() > 0.0)
                continue;
            Picker hit;
            if (!FUN_006d7490(&p4, &end, &hit, 0))
            {
                if (minDist < dist)
                {
                    Vec3 diff3 = pp - hit.GetPoint();
                    float len = diff3.Length();
                    if (minDist > len - radius)
                        continue;
                    target = pp + off * (len - radius);
                }
                else
                {
                    continue;
                }
            }
            if (mask2 & bit)
            {
                if (!FUN_009a7940(A9, ref, &target, &T, 0, -1))
                    continue;
            }
            if (!FUN_009a0260(&target, h7.FUN_0084e3a0(1, 0)))
                continue;
            A5[n] = target;
            slot[i] = n;
            dirOf[n] = i;
            n++;
        }
    }
    if (n == 0)
        return false;
    if (last != -1 && timer.Get() < 10.0 && slot[last] != -1)
    {
        mover->FUN_0099b8b0(&A5[slot[last]], 0);
        return true;
    }
    int aK = FUN_005a00a0(n);
    last = dirOf[aK];
    timer = FUN_00435dd0();
    mover->FUN_0099b8b0(&A5[slot[last]], 0);
    return true;
}

struct TargetPosition
{
    float x, y, z;
    unsigned space;
};
struct TargetRef
{
    TargetPosition FUN_00575650();
};
struct TargetParameters
{
    unsigned char flag;
    TargetRef* reference;
    TargetPosition position;
    float nearRange, farRange;
    TargetParameters();
};
struct TargetSetting
{
    float* FUN_00403e20();
};
extern TargetSetting DAT_011cf0d8;
float FUN_00404010(float, float);
struct TargetWork
{
    unsigned unk0;
    unsigned unk4;
    unsigned unk8;
    unsigned unkc;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    unsigned unkac;
    unsigned unkb0;
    unsigned unkb4;
    unsigned unkb8;
    unsigned unkbc;
    unsigned unkc0;
    TargetParameters* parameters;
    void FreeAndClearFieldC4();
    void FUN_009a0790(TargetRef*, unsigned char, float, float);
};
// @fnv 0x009a0790
void TargetWork::FUN_009a0790(TargetRef* reference, unsigned char flag, float nearRange, float farRange)
{
    FreeAndClearFieldC4();
    if (!reference)
        return;
    parameters = new TargetParameters;
    parameters->flag = flag;
    parameters->reference = reference;
    parameters->position = reference->FUN_00575650();
    parameters->nearRange = FUN_00404010(nearRange, *DAT_011cf0d8.FUN_00403e20());
    parameters->farRange = FUN_00404010(farRange, *DAT_011cf0d8.FUN_00403e20());
}

class TESForm
{
  public:
    virtual void v0();
};

class TESObjectREFR : public TESForm
{
  public:
    virtual void v1();
};

TESForm* __cdecl LookupFormByID(TESObjectREFR* p);

class FUN_009a3220_cls
{
  public:
    char unk00[4];
    TESObjectREFR* m_04;
    void FUN_009a3220(int unkArg);
};

// Re-resolves m_04 through LookupFormByID and dynamic_cast to TESObjectREFR, or clears it to null when m_04 is null.
// @fnv 0x009a3220
void FUN_009a3220_cls::FUN_009a3220(int unkArg)
{
    m_04 = m_04 != 0 ? dynamic_cast<TESObjectREFR*>(LookupFormByID(m_04)) : 0;
}

struct ElementProxy
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
};
struct ArrayProxy
{
    virtual void unused();
    virtual ElementProxy* Allocate(unsigned int);
    ElementProxy* data;
    unsigned int size, capacity;
    void FUN_006dbde0(bool);
    void FUN_006dbfc0(unsigned int, unsigned int);
    void ConstructInPlace(ElementProxy*, unsigned int);
    void FUN_006dbee0(ElementProxy*, unsigned int);
    void FUN_009a32a0(unsigned int, bool);
};
// Grows, shrinks or clears the array to count elements, reallocating storage when needed and optionally shrinking capacity.
// @fnv 0x009a32a0
void ArrayProxy::FUN_009a32a0(unsigned int count, bool shrink)
{
    if (count == 0)
    {
        FUN_006dbde0(shrink);
    }
    else if (count > capacity)
    {
        if (capacity == 0)
        {
            data = Allocate(count);
            capacity = count;
        }
        else
        {
            FUN_006dbfc0(count, size);
            capacity = count;
        }
        ConstructInPlace(data + size, count - size);
        size = count;
    }
    else if (count < size)
    {
        FUN_006dbee0(data + count, size - count);
        size = count;
        if (shrink && count <= (capacity >> 2))
        {
            FUN_006dbfc0(count, count);
            capacity = count;
        }
    }
    else
    {
        ConstructInPlace(data + size, count - size);
        size = count;
    }
}

struct LocS
{
    int v0;
    int v4;
    int v8;
    int vC;
    float DistTo(LocS* other);
};
struct Loc2S
{
    int v0;
    int v4;
    int v8;
    int vC;
};
struct CellS
{
    Loc2S GetLoc2();
};
struct RefS
{
    LocS GetLocationPointer();
    CellS* GetContainingCell();
};
struct TileS
{
    bool TestLoc(LocS*, int, int);
};
struct IfaceS
{
    TileS* GetTile();
};
struct Sub30S
{
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual bool IsFlagV();
};
struct ActorBaseS
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
    Sub30S data30;
};
struct ActorS
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
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual bool IsDeadV();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
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
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual IfaceS* GetIfaceV();
    ActorBaseS* GetActorBase();
    LocS GetLocationPointer();
};
struct NodeS
{
    RefS* ref;
    void* other;
    unsigned char level;
    unsigned char flag9;
    unsigned char flagA;
};
struct NodeArrS
{
    NodeS& GetAt(int);
    unsigned int GetSize();
};
struct GlobalIntS
{
    unsigned int* Int();
};
extern GlobalIntS g_011cfc98;
bool __cdecl FUN_009a96f0(ActorS*, Loc2S*);
struct CombatNodeFinder
{
    int unk000;
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
    NodeArrS nodes;
    RefS* FindNearestCombatNode(ActorS* actor, float maxDist, bool checkCell);
};

// Scans nodes for a valid, in-range reference (optionally cell-checked and tile-tested) and returns the closest one to the actor, or null.
// @fnv 0x0098c3d0
RefS* CombatNodeFinder::FindNearestCombatNode(ActorS* actor, float maxDist, bool checkCell)
{
    if (actor->IsDeadV() && actor->GetActorBase()->data30.IsFlagV())
        return 0;
    IfaceS* iface3 = actor->GetIfaceV();
    LocS actorLoc2 = actor->GetLocationPointer();
    RefS* bestX = 0;
    float bestDist5 = maxDist * maxDist;
    for (unsigned int i = 0; i < nodes.GetSize(); i++)
    {
        NodeS& node5 = nodes.GetAt(i);
        if (!node5.ref || !node5.other)
            continue;
        if (node5.level > *g_011cfc98.Int() || node5.flagA || node5.flag9)
            continue;
        CellS* cell2 = node5.ref->GetContainingCell();
        if (!cell2)
            continue;
        if (checkCell)
        {
            Loc2S cellLoc = cell2->GetLoc2();
            if (!FUN_009a96f0(actor, &cellLoc))
                continue;
        }
        LocS nodeLoc2 = node5.ref->GetLocationPointer();
        if (iface3 && !iface3->GetTile()->TestLoc(&nodeLoc2, 1, 0))
            continue;
        float dist4 = actorLoc2.DistTo(&nodeLoc2);
        if (dist4 < bestDist5)
        {
            bestX = node5.ref;
            bestDist5 = dist4;
        }
    }
    return bestX;
}

namespace fnv_00997cf0 {
struct NiPoint3Ex
{
    float x, y, z;
    void FUN_00416870(float, float, float);
};
struct CombatStamp
{
    int value;
    void FUN_00435de0(float);
    float FUN_006a7f50();
    double FUN_00435e00();
};
struct CombatWorld
{
    int a, b, c, d;
    void* FUN_0084e3a0();
    float ComputeWeightedDistance(const CombatWorld&, const NiPoint3Ex&);
    float FUN_00527a40(const CombatWorld&);
};
struct CombatActor
{
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
    virtual bool IsActor();
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
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual NiPoint3Ex* GetPosition();
    void* FUN_00575ca0();
    CombatWorld* FUN_00575650(CombatWorld*);
    unsigned char FUN_004997b0();
    bool FUN_00894900();
};
struct CombatTimers
{
    int a, b;
    bool FUN_0097fa50();
    bool FUN_008d7f80();
    void FUN_00910b10();
    void FUN_008d7f40(float);
    void FUN_0097f220();
};
struct CombatMode
{
    unsigned char type;
    bool active;
    short unk02;
    CombatActor* actor;
    CombatWorld world;
    float nearDistance, farDistance;
};
struct CombatPackage
{
    int FUN_00825c00();
};
struct CombatMap
{
    void UpdateTargetPerception(CombatActor*, CombatActor*, int*, CombatStamp*, bool*, bool*);
    CombatActor* FindNearestActor(CombatActor*, CombatActor*, float);
    CombatActor* GetFieldAtOffset16(CombatActor*);
};
struct CombatOptions
{
    bool FUN_009989d0();
};
struct CombatController
{
    CombatActor* GetFieldBC();
    CombatActor* FUN_004030b0();
    void FUN_0097f200();
    bool GetFieldC5();
    CombatMap* FUN_004fb070();
    void SetByteAtOffsetC5(bool);
    CombatPackage* FUN_004f9bf0();
    bool FUN_00981940(int);
    bool FUN_00981300();
    bool FUN_0067a700();
    void FUN_00981380();
    bool FUN_00998a30();
    void SetFieldC7(unsigned char);
    bool GetByteAtOffsetC7();
    CombatOptions* FUN_00980070();
};
struct CombatPath
{
    bool FUN_006e4650(int);
};
struct CombatPathOwner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    CombatPath path;
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
    int index;
};
struct CombatHazard
{
    float EvaluateThreats(NiPoint3Ex, CombatActor*, float, float, void*, float);
};
struct CombatHazardHolder
{
    CombatHazard* FUN_00825c00();
};
struct CombatSetting
{
    float* FUN_00403e20();
};
extern CombatSetting DAT_011cf45c, DAT_011cfbcc, DAT_011ceed8;
extern CombatHazardHolder* DAT_011f1958;
extern CombatActor* DAT_011dea3c;
extern bool DAT_011f1ae4, DAT_011a4d34;
extern float DAT_011a5310, DAT_011a530c, DAT_011a5308, DAT_0108df70;
float FUN_00435dd0();
float FUN_00476b70(float, float);
bool FUN_009a9630(CombatActor*);
struct CombatUpdate
{
    int unk000;
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
    float chaseDistance;
    int targetState;
    bool visible, detected, known;
    signed char status;
    bool differentSpace;
    unsigned char unk075;
    bool changed, updateNow;
    int unk078;
    int unk07c;
    float danger;
    NiPoint3Ex targetPosition;
    unsigned int flags;
    CombatStamp targetTime;
    CombatStamp seenTime;
    int unk09c;
    int unk0a0;
    CombatStamp idleTime;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    void* hazardData;
    CombatMode* mode;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    void* temporary;
    CombatStamp temporaryTime;
    CombatPathOwner* path;
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
    CombatActor* previousTarget;
    CombatController* controller;
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
    CombatTimers stanceTimer;
    CombatTimers pathTimer;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    CombatTimers chaseTimer;

    void FUN_00997cf0();
    bool FUN_00998980();
    void FUN_0099a530();
    void FUN_009a03d0(bool);
    void FUN_009a0790(CombatActor*, int, float, float);
    void FUN_009a0910(CombatActor*, int, float, float);
    void FreeAndClearFieldC4();
    void UpdateModifierState(bool);
    bool FUN_009a0a80();
    float GetInterpolatedValue();
    void EvaluateWeaponScores();
};
// Updates the combat target, detection state, path and stance timers, mode activation, danger level and chase timer for the controller's owner.
// @fnv 0x00997cf0
void CombatUpdate::FUN_00997cf0()
{
    CombatStamp timeD3;
    CombatWorld worldB;
    CombatWorld worldAB;
    CombatStamp timeC3;
    CombatStamp timeB_1;
    CombatStamp timeA;
    CombatWorld ownLocation3;
    CombatWorld targetLocation;
    unsigned char stance;
    CombatActor* follow;
    float range_;
    NiPoint3Ex weights_26;
    float distance_1;
    bool fleeing_3;
    CombatActor* aFoundOther;
    CombatActor* found;
    CombatActor* current;
    float nearRange;
    float searchRange5;
    float farRange_5;
    CombatPackage* package2;
    int state_7;
    CombatActor* target4;
    float oldDangerX;
    void* space_41;
    CombatActor* owner_21;
    owner_21 = controller->GetFieldBC();
    {
        target4 = controller->FUN_004030b0();
        space_41 = owner_21->FUN_00575ca0();
        if (target4 && space_41 != target4->FUN_00575ca0())
        {
            if (!differentSpace)
            {
                if (visible)
                    controller->FUN_0097f200();
                differentSpace = true;
            }
        }
        else
            differentSpace = false;
        if (target4)
        {
            if (controller->GetFieldC5() || previousTarget != target4)
            {
                state_7 = -100;
                controller->FUN_004fb070()->UpdateTargetPerception(owner_21, target4, &state_7, &targetTime, &visible,
                                                                   &detected);
                targetState = state_7;
                controller->SetByteAtOffsetC5(false);
            }
            if (detected)
            {
                timeA.FUN_00435de0(FUN_00435dd0());
                seenTime = timeA;
                targetPosition = *target4->GetPosition();
                package2 = controller->FUN_004f9bf0();
                if (!package2 || package2->FUN_00825c00() != 13)
                {
                    status = -1;
                    changed = false;
                }
            }
            if (detected && !known && controller->FUN_00981940(24))
                controller->FUN_0097f200();
            if (!FUN_00998980() && status == -1)
                status = 0;
        }
        else
        {
            targetState = -1;
            detected = false;
            timeB_1.FUN_00435de0(-DAT_0108df70);
            targetTime = timeB_1;
            timeC3.FUN_00435de0(-DAT_0108df70);
            seenTime = timeC3;
            status = -1;
        }
        FUN_0099a530();
        if (pathTimer.FUN_0097fa50())
        {
            if (pathTimer.FUN_008d7f80())
            {
                FUN_009a03d0(false);
                pathTimer.FUN_00910b10();
            }
        }
        else if (path && path->index != -1 && !path->path.FUN_006e4650(path->index))
            pathTimer.FUN_008d7f40(2.0f);
        if (DAT_011f1ae4)
        {
            if (!mode || mode->type == 2)
            {
                nearRange = DAT_011a5310;
                farRange_5 = DAT_011a530c;
                searchRange5 = DAT_011a5308;
                if (FUN_009a9630(owner_21))
                {
                    nearRange *= 2;
                    farRange_5 *= 2;
                }
                if (farRange_5 + 256.0 > searchRange5)
                    searchRange5 = farRange_5 + 256.0;
                if (DAT_011a4d34)
                {
                    current = 0;
                    if (mode && mode->actor && mode->actor->IsActor())
                        current = mode->actor;
                    found = controller->FUN_004fb070()->FindNearestActor(owner_21, current, searchRange5);
                    if (found)
                        FUN_009a0790(found, 2, nearRange, farRange_5);
                    else
                        FreeAndClearFieldC4();
                }
                else
                {
                    aFoundOther = controller->FUN_004fb070()->GetFieldAtOffset16(owner_21);
                    if (aFoundOther)
                        FUN_009a0910(aFoundOther, 2, nearRange, farRange_5);
                    else
                        FreeAndClearFieldC4();
                }
            }
        }
        else if (!DAT_011f1ae4 && mode && mode->type == 2)
            FreeAndClearFieldC4();
        if (mode)
        {
            if (mode->type == 3 && mode->world.FUN_0084e3a0() != space_41)
                UpdateModifierState(true);
            if (mode->actor)
                mode->world = *mode->actor->FUN_00575650(&worldAB);
            weights_26.FUN_00416870(1.0f, 1.0f, 0.25f);
            distance_1 = mode->world.ComputeWeightedDistance(*owner_21->FUN_00575650(&worldB), weights_26);
            fleeing_3 = false;
            if ((mode->type == 0 || mode->type == 1) && target4 && controller->FUN_00981300() &&
                !controller->FUN_0067a700())
                fleeing_3 = true;
            if (fleeing_3)
                mode->active = true;
            else
            {
                if (mode->farDistance > mode->nearDistance && FUN_009a0a80())
                {
                    range_ = GetInterpolatedValue();
                    if (mode->active)
                    {
                        if (distance_1 > range_ * range_)
                            mode->active = false;
                    }
                    else
                    {
                        if (distance_1 < range_ * range_)
                            mode->active = true;
                    }
                }
                else
                {
                    mode->active = false;
                    if (distance_1 < mode->nearDistance * mode->nearDistance)
                        mode->active = true;
                }
            }
            switch (mode->type)
            {
            case 0:
                if (mode->active && !fleeing_3)
                {
                    FreeAndClearFieldC4();
                    controller->FUN_00981380();
                }
                break;
            case 1:
                if (controller->FUN_00998a30() && mode->actor && mode->actor->IsActor())
                {
                    if (distance_1 < *DAT_011cf45c.FUN_00403e20() * *DAT_011cf45c.FUN_00403e20())
                    {
                        follow = mode->actor;
                        stance = follow->FUN_004997b0();
                        if (stance != owner_21->FUN_004997b0())
                        {
                            if (!stanceTimer.FUN_0097fa50())
                            {
                                if (follow == DAT_011dea3c)
                                    stanceTimer.FUN_008d7f40(FUN_00476b70(0.5f, 1.0f));
                                else
                                    stanceTimer.FUN_008d7f40(FUN_00476b70(0.1f, 0.5f));
                            }
                            else if (stanceTimer.FUN_008d7f80())
                            {
                                controller->SetFieldC7(stance);
                                stanceTimer.FUN_00910b10();
                            }
                        }
                        else
                            stanceTimer.FUN_00910b10();
                    }
                    else if (controller->GetByteAtOffsetC7())
                        controller->SetFieldC7(0);
                }
                break;
            }
        }
        oldDangerX = danger;
        if (!controller->FUN_00980070()->FUN_009989d0())
        {
            if (danger > *DAT_011cfbcc.FUN_00403e20() || (flags & 0x100))
            {
                danger = DAT_011f1958->FUN_00825c00()->EvaluateThreats(*owner_21->GetPosition(), owner_21, 0, 0,
                                                                       hazardData, 0);
                if (danger >= *DAT_011cfbcc.FUN_00403e20() && oldDangerX < *DAT_011cfbcc.FUN_00403e20())
                    controller->FUN_0097f200();
            }
            else
                danger = 0;
        }
        if (idleTime.FUN_006a7f50() != -DAT_0108df70 && !owner_21->FUN_00894900())
        {
            timeD3.FUN_00435de0(-DAT_0108df70);
            idleTime = timeD3;
        }
        if (target4 && chaseDistance > 0.0)
        {
            owner_21->FUN_00575650(&ownLocation3);
            target4->FUN_00575650(&targetLocation);
            if (ownLocation3.FUN_00527a40(targetLocation) < chaseDistance * chaseDistance)
                chaseTimer.FUN_0097f220();
        }
        if (updateNow || (chaseTimer.FUN_0097fa50() && chaseTimer.FUN_008d7f80()))
            EvaluateWeaponScores();
        UpdateModifierState(false);
        if (temporary && temporaryTime.FUN_00435e00() > *DAT_011ceed8.FUN_00403e20())
            temporary = 0;
        previousTarget = target4;
    }
}
}  // namespace fnv_00997cf0

struct UpdateActor
{
    void Notify(int);
};
struct UpdateEffect
{
    int Type();
};
struct UpdateRef
{
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
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual int Query(float);
};
struct UpdateController
{
    UpdateActor* Actor();
    UpdateRef* Ref();
    unsigned char Flag();
    void Changed();
    bool Active();
    bool Ready();
    UpdateEffect* Effect();
};
struct DurationTracker
{
    int time;
    int state;
    bool Started();
    bool Expired();
    bool Randomize();
    void Reset(float);
    void Clear();
};
struct UpdateArray
{
    unsigned Count();
    int& At(unsigned);
};
struct UpdateSetting
{
    float* Float();
};
extern UpdateSetting originalRuntimeFloatSetting381, originalRuntimeFloatSetting380, originalRuntimeFloatSetting359,
    originalRuntimeFloatSetting360, originalRuntimeFloatSetting361, g_011cf198, originalRuntimeFloatSetting492;
extern const float DAT_010162c0, updateInterval;
unsigned GetRandomNumberInRange(int, int);
bool RandomBoolean(float);
struct UpdateWorld
{
    bool Test(UpdateActor*, int, int);
};
extern UpdateWorld* BGSSaveLoadGlobalDataWorldspacePtr;
struct UpdateManager
{
    void Notify(UpdateController*, int, int, int);
};
extern UpdateManager* DAT_011f1708;
struct UpdateResult
{
    int status;
    int detail;
    UpdateResult();
    ~UpdateResult();
};
struct UpdateRequest
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool Poll(UpdateResult*);
};
struct UpdatePointer
{
    UpdateRequest* Get();
    void Set(int);
};
struct UpdateState
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    UpdateArray targets;
    int unk028;
    int unk02c;
    int unk030;
    int target;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    float threshold;
    int unk05c;
    int unk060;
    float elapsed;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int pending;
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
    bool notified;
    char unk0d9;
    char unk0da;
    char unk0db;
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
    UpdateController* controller;
    bool force;
    char unk1c9;
    char unk1ca;
    char unk1cb;
    DurationTracker timer1cc;
    DurationTracker timer1d4;
    DurationTracker timer1dc;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    DurationTracker timer204;
    DurationTracker timer20c;
    DurationTracker timer214;
    int unk21c;
    int unk220;
    UpdatePointer request;
    int requestState;
    void Changed();
    void Tick();
    void RefreshA();
    void RefreshB();
    bool Cancel();
    bool Allowed();
    bool Request(bool);
    bool GetFlag(unsigned);
    void Update();
    bool Special();
    void FUN_00998a50();
};
// @fnv 0x00998a50
void UpdateState::FUN_00998a50()
{
    UpdateActor* count = controller->Actor();
    UpdateRef* ref = controller->Ref();
    {
        int actor = targets.Count();
        if (actor > 1)
        {
            unsigned char flag = controller->Flag();
            if (!timer214.Started() && !flag)
                timer214.Reset(*originalRuntimeFloatSetting381.Float());
            if ((timer214.Started() && timer214.Expired()) || force)
            {
                bool randomize = timer214.Randomize();
                if (RandomBoolean(*originalRuntimeFloatSetting380.Float()) || force || randomize)
                {
                    int selected = 0;
                    if (randomize && target)
                    {
                        int remaining = GetRandomNumberInRange(0, actor - 1);
                        for (unsigned index = 0; index < targets.Count(); ++index)
                        {
                            int entry = targets.At(index);
                            if (entry == target)
                                continue;
                            if (remaining == 0)
                            {
                                selected = entry;
                                break;
                            }
                            --remaining;
                        }
                    }
                    else
                    {
                        int choice = GetRandomNumberInRange(0, actor);
                        selected = targets.At(choice);
                    }
                    if (selected != target)
                    {
                        target = selected;
                        Changed();
                        controller->Changed();
                    }
                }
                timer214.Clear();
            }
        }
    }
    if (pending)
    {
        if (!timer1dc.Started())
            timer1dc.Reset(*originalRuntimeFloatSetting359.Float());
        if (timer1dc.Expired())
        {
            if (!ref || BGSSaveLoadGlobalDataWorldspacePtr->Test(count, pending, ref->Query(DAT_010162c0)))
                pending = 0;
            else
                timer1dc.Reset(*originalRuntimeFloatSetting359.Float());
        }
    }
    else
        timer1dc.Clear();
    if (timer1d4.Expired())
    {
        Tick();
        if (elapsed < threshold)
        {
            timer1d4.Reset(*originalRuntimeFloatSetting360.Float());
            elapsed = 0.0f;
        }
        else
            timer1d4.Reset(*originalRuntimeFloatSetting361.Float());
    }
    if (timer204.Expired())
    {
        RefreshA();
        timer204.Reset(*g_011cf198.Float());
    }
    if (timer20c.Expired())
    {
        RefreshB();
        timer20c.Reset(*originalRuntimeFloatSetting492.Float());
    }
    if (request.Get())
    {
        UpdateResult result;
        if (request.Get()->Poll(&result))
        {
            switch (result.status)
            {
            case 0:
                Cancel();
                requestState = -1;
                break;
            default:
                if (requestState == 1 && Allowed() && ref)
                {
                    if (!Request(false))
                        requestState = -1;
                }
                else
                    requestState = -1;
                break;
            }
            if (requestState == -1)
                request.Set(0);
        }
    }
    else if (Allowed() && ref)
    {
        if (!timer1cc.Started())
            timer1cc.Reset(updateInterval);
        if (timer1cc.Expired())
        {
            bool bRequested = false;
            if (GetFlag(2) && Request(true))
                bRequested = true;
            if (!bRequested)
                Request(false);
            timer1cc.Reset(updateInterval);
        }
    }
    else
        timer1cc.Clear();
    Update();
    if (controller->Active())
    {
        if (!controller->Ready() && !notified)
        {
            notified = true;
            count->Notify(0);
            DAT_011f1708->Notify(controller, 2, 3, 1);
        }
    }
    else
    {
        bool clear = true;
        if (controller->Effect() && controller->Effect()->Type() == 6 && Special())
            clear = false;
        if (clear)
            notified = false;
    }
}

namespace CombatWeapons {
struct Actor;
struct Weapon;
struct Ammo;
struct Entry;
struct Item;
struct Controller;
struct Process;
struct Profile
{
    int value;
    Profile(int, int, const char*, int);
    ~Profile();
};
struct Point
{
    float x, y, z;
};
struct Location
{
    Point point;
    void* cell;
    float FUN_00527a40(const Location&);
};
struct Effects
{
    float FUN_00405c00(int, int, int);
};
struct Item
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    Effects effects;
    int FUN_00401170();
};
struct Extra
{
    bool FUN_00418b10();
};
struct Extras
{
    Extra** FUN_006815c0();
};
struct Entry
{
    Weapon* FUN_0044ddc0();
    float FUN_004bcdb0(int);
    Extras* FUN_00559450();
};
struct AmmoState
{
    void FUN_006ecd40(int);
    int FUN_00726070();
};
struct Animation
{
    bool FUN_008846c0();
};
struct Equip
{
    unsigned int unk0, unk4, unk8;
    Equip(Ammo*, int);
};
struct Process
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual Entry* Equipped();
    virtual AmmoState* Ammunition();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void EquipAmmo(Equip*);
};
struct Projectile
{
    int FUN_004fd3c0();
};
struct Weapon : Item
{
    Ammo* FUN_00525980(Actor*);
    unsigned char GetByteAt102();
    int FUN_00522c80();
    bool FUN_0046e8c0();
    Projectile* GetOrFallback(Actor*);
};
struct InventoryIterator
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    InventoryIterator();
    ~InventoryIterator();
};
struct Inventory
{
    bool AdvanceInventoryIterator(InventoryIterator*, Entry**, int);
    Ammo* FindInventoryItem(Weapon*, bool*);
    int FUN_004c8f30(Ammo*);
};
Inventory* FUN_004bf220(Actor*);
struct Actor
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual Animation* AnimationData();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual const Point& Position();
    Location FUN_00575650();
    bool FUN_008bc9d0(Weapon*, int);
    Process* FUN_008d8520();
    bool FUN_008a8870();
    void FUN_008a8840();
};
struct CombatData
{
    bool HasCombatFlag(unsigned int);
};
struct Controller
{
    Actor* GetFieldBC();
    Actor* FUN_004030b0();
    CombatData* FUN_00980070();
    Weapon* FUN_007031c0();
};
struct WeaponScore
{
    Weapon* weapon;
    float health, damage, range;
    bool inRange;
};
struct Scores
{
    unsigned int unk0, unk4, unk8, unkc;
    Scores(int, int);
    ~Scores();
    unsigned int FUN_007881d0();
    WeaponScore& FUN_006b3160(unsigned int);
    WeaponScore& FUN_006dad90(unsigned int);
    unsigned int FUN_0044ddc0();
    void RemoveEntries(unsigned int, int);
};
struct Ammos
{
    unsigned int unk0, unk4, unk8, unkc;
    Ammos(int, int);
    ~Ammos();
    void FUN_007cb2e0(Ammo* const&);
    bool FUN_009962f0(Ammo* const&);
};
struct WeaponList
{
    unsigned int unk0, unk4, unk8, unkc;
    void FUN_007cb2e0(Weapon* const&);
};
struct Timer
{
    void FUN_008d7f40(float);
};
struct Setting
{
    float* FUN_00403e20();
};
extern Setting DAT_011ce4ac, DAT_011cf660;
extern const char DAT_0108dfb0[];
extern double DAT_01017a40, DAT_01012060, DAT_0106b798, DAT_0102f078;
extern float DAT_0108dfac, DAT_010162c0;
void* FUN_00403d30(void*, int, unsigned int);
float ComputeWeaponDamage(Actor*, Weapon*, float, CombatData*, int, int);
void FUN_009a9180(Controller*, Weapon*, float&, float&, float&);
float FUN_00404010(float, float);
struct System
{
    bool IsThreatWithinLimits(Actor*, int, const Point&, float);
};
extern System* DAT_011f1958;
struct Manager
{
    unsigned int unk0, unk4, unk8;
    Weapon* bestWeapons[6];
    WeaponList ranged;
    Weapon* current;
    unsigned int types;
    float categoryScore[7];
    float maxDamage, maxRanged, maxScore, unk64, maxRange;
    unsigned int unk6c, unk70;
    unsigned char unk74, unk75, unk76, flag;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    Item* aids[2];
    unsigned int unk1ac, unk1b0, unk1b4, unk1b8, aidTypes, unk1c0;
    Controller* controller;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    Timer timer;
    void FUN_0099a2a0();
    void FUN_00442a80(int);
    void EvaluateWeaponScores();
};
// Scans the actor's inventory for aids, weapons and ammo, scores each weapon by damage and range, fills bestWeapons/categoryScore, and updates the timer.
// @fnv 0x009993c0
void Manager::EvaluateWeaponScores()
{
    Profile profile(43, 1, DAT_0108dfb0, 838);
    Actor* actor = controller->GetFieldBC();
    Actor* target = controller->FUN_004030b0();
    CombatData* dataSlot17 = controller->FUN_00980070();
    float distance = 0.0f;
    if (target)
    {
        Location sourcePointSlot0 = actor->FUN_00575650();
        Location targetPointSlot14 = target->FUN_00575650();
        distance = sourcePointSlot0.FUN_00527a40(targetPointSlot14);
    }
    FUN_0099a2a0();
    flag = 0;
    maxDamage = 0.0f;
    maxRanged = 0.0f;
    maxScore = 0.0f;
    maxRange = 0.0f;
    types = 0;
    aidTypes = 0;
    FUN_00403d30(categoryScore, 0, 28);
    FUN_00403d30(aids, 0, 8);
    float aidScoresSlot19[2];
    FUN_00403d30(aidScoresSlot19, 0, 8);
    Scores scoresSlot20(32, 0);
    Ammos ammosSlot1(32, 0);
    Entry* entry = 0;
    InventoryIterator iteratorSlot1;
    Inventory* inventorySlot40 = FUN_004bf220(actor);
    while (inventorySlot40->AdvanceInventoryIterator(&iteratorSlot1, &entry, 0))
    {
        Item* item = entry->FUN_0044ddc0();
        switch (item->FUN_00401170())
        {
        case 47: {
            Item* aid = item;
            for (unsigned int n = 0; n < 2; n++)
            {
                float scoreSlot25 = 0.0f;
                unsigned int effect = n + 17;
                switch (effect)
                {
                case 17:
                    scoreSlot25 = aid->effects.FUN_00405c00(0, 0, 16);
                    scoreSlot25 += aid->effects.FUN_00405c00(34, 0, 16);
                    break;
                case 18:
                    if (!dataSlot17->HasCombatFlag(256))
                        scoreSlot25 = aid->effects.FUN_00405c00(12, 0, 77);
                    break;
                }
                if (scoreSlot25 > aidScoresSlot19[n])
                {
                    aids[n] = item;
                    aidScoresSlot19[n] = scoreSlot25;
                    aidTypes |= 1 << effect;
                    break;
                }
            }
            break;
        }
        case 40: {
            Weapon* weaponSlot32Slot15 = (Weapon*)item;
            if (actor->FUN_008bc9d0(weaponSlot32Slot15, 1))
            {
                unsigned int index = scoresSlot20.FUN_007881d0();
                FUN_00403d30(&scoresSlot20.FUN_006b3160(index), 0, 20);
                scoresSlot20.FUN_006b3160(index).weapon = weaponSlot32Slot15;
                scoresSlot20.FUN_006b3160(index).health = entry->FUN_004bcdb0(1) / 100.0f;
            }
            break;
        }
        case 41:
            ammosSlot1.FUN_007cb2e0((Ammo*)item);
            break;
        }
    }
    Weapon* forcedSlot30 = 0;
    Entry* equippedSlot10 = actor->FUN_008d8520()->Equipped();
    if (equippedSlot10 && equippedSlot10->FUN_00559450() && *equippedSlot10->FUN_00559450()->FUN_006815c0() &&
        (*equippedSlot10->FUN_00559450()->FUN_006815c0())->FUN_00418b10())
        forcedSlot30 = equippedSlot10->FUN_0044ddc0();
    if (!forcedSlot30)
    {
        float bestOutsideSlot13 = 0.0f;
        Weapon* outsideWeaponSlot0 = 0;
        float bestInsideSlot33 = 0.0f;
        for (unsigned int i = 0; i < scoresSlot20.FUN_0044ddc0(); i++)
        {
            WeaponScore* scoreSlot25 = &scoresSlot20.FUN_006dad90(i);
            Weapon* weaponSlot32Slot15 = scoreSlot25->weapon;
            Actor* ownerSlot16 = (equippedSlot10 && weaponSlot32Slot15 == equippedSlot10->FUN_0044ddc0()) ? actor : 0;
            Ammo* ammoSlot1 = weaponSlot32Slot15->FUN_00525980(ownerSlot16);
            if (ammoSlot1 && !ammosSlot1.FUN_009962f0(ammoSlot1))
            {
                bool special = false;
                Ammo* alternativeSlot0 = inventorySlot40->FindInventoryItem(weaponSlot32Slot15, &special);
                if (alternativeSlot0 && ammosSlot1.FUN_009962f0(alternativeSlot0))
                {
                    if (equippedSlot10 && weaponSlot32Slot15 == equippedSlot10->FUN_0044ddc0())
                    {
                        Animation* animation = actor->AnimationData();
                        bool busySlot0 = actor->FUN_008a8870() || (animation && animation->FUN_008846c0());
                        if (!busySlot0)
                        {
                            Process* process = actor->FUN_008d8520();
                            int countSlot11 = inventorySlot40->FUN_004c8f30(alternativeSlot0);
                            Equip* replacement = new Equip(alternativeSlot0, countSlot11);
                            process->EquipAmmo(replacement);
                            process->Ammunition()->FUN_006ecd40(0);
                            actor->FUN_008a8840();
                        }
                    }
                }
                else
                {
                    scoresSlot20.RemoveEntries(i, 1);
                    i--;
                    continue;
                }
            }
            else if (equippedSlot10 && weaponSlot32Slot15 == equippedSlot10->FUN_0044ddc0())
            {
                AmmoState* state = actor->FUN_008d8520()->Ammunition();
                if (state)
                {
                    Animation* animation2Slot1 = actor->AnimationData();
                    Weapon* active = equippedSlot10->FUN_0044ddc0();
                    if (animation2Slot1 && active)
                    {
                        bool emptySlot0 = state && state->FUN_00726070() <= 0 && active && active->GetByteAt102() > 0;
                        bool busy2Slot10 =
                            actor->FUN_008a8870() || (animation2Slot1 && animation2Slot1->FUN_008846c0());
                        if (emptySlot0 && !busy2Slot10)
                            actor->FUN_008a8840();
                    }
                }
            }
            scoreSlot25->damage = ComputeWeaponDamage(actor, weaponSlot32Slot15, scoreSlot25->health, dataSlot17, 0, 0);
            if (scoreSlot25->damage <= DAT_01012060)
            {
                scoresSlot20.RemoveEntries(i, 1);
                i--;
                continue;
            }
            scoreSlot25->inRange = 1;
            scoreSlot25->range = 0.0f;
            int categorySlot22 = scoreSlot25->weapon->FUN_00522c80();
            if (target && (categorySlot22 == 1 || categorySlot22 == 0))
            {
                float nearRange = 0.0f;
                float middleRangeSlot34 = 0.0f;
                float farRangeSlot1 = 0.0f;
                FUN_009a9180(controller, weaponSlot32Slot15, nearRange, middleRangeSlot34, farRangeSlot1);
                scoreSlot25->range = farRangeSlot1;
                if (controller->FUN_007031c0() == weaponSlot32Slot15)
                    farRangeSlot1 *= *DAT_011ce4ac.FUN_00403e20();
                if (distance > farRangeSlot1 * farRangeSlot1)
                {
                    scoreSlot25->inRange = 0;
                    if (scoreSlot25->damage > bestOutsideSlot13)
                    {
                        bestOutsideSlot13 = scoreSlot25->damage;
                        outsideWeaponSlot0 = weaponSlot32Slot15;
                    }
                }
                else if (scoreSlot25->damage > bestInsideSlot33)
                    bestInsideSlot33 = scoreSlot25->damage;
            }
        }
        if (bestInsideSlot33 > DAT_01012060)
            outsideWeaponSlot0 = 0;
        for (unsigned int j = 0; j < scoresSlot20.FUN_0044ddc0(); j++)
        {
            WeaponScore* candidateSlot0 = &scoresSlot20.FUN_006dad90(j);
            Weapon* weapon2Slot11 = candidateSlot0->weapon;
            int category2Slot19 = candidateSlot0->weapon->FUN_00522c80();
            float value = candidateSlot0->damage;
            if (weapon2Slot11 == current)
                value += DAT_0106b798;
            if (weapon2Slot11 == outsideWeaponSlot0)
                candidateSlot0->inRange = 1;
            if (!candidateSlot0->inRange)
            {
                value /= DAT_0102f078;
                if (candidateSlot0->range > maxRange && candidateSlot0->damage > bestInsideSlot33)
                    maxRange = candidateSlot0->range;
            }
            if (weapon2Slot11->FUN_0046e8c0() && candidateSlot0->inRange)
                ranged.FUN_007cb2e0(weapon2Slot11);
            maxDamage = FUN_00404010(maxDamage, candidateSlot0->damage);
            if (category2Slot19 == 1 || category2Slot19 == 0)
                maxRanged = FUN_00404010(maxRanged, candidateSlot0->damage);
            maxScore = FUN_00404010(maxScore, value);
            types |= 1 << category2Slot19;
            if (value > categoryScore[category2Slot19])
            {
                bestWeapons[category2Slot19] = weapon2Slot11;
                categoryScore[category2Slot19] = value;
            }
        }
        categoryScore[6] = ComputeWeaponDamage(actor, 0, 1.0f, dataSlot17, 0, 0);
        maxDamage = FUN_00404010(maxDamage, categoryScore[6]);
        maxScore = FUN_00404010(maxScore, categoryScore[6]);
        types |= 64;
    }
    else
    {
        int category3 = forcedSlot30->FUN_00522c80();
        bestWeapons[category3] = forcedSlot30;
        categoryScore[category3] = DAT_0108dfac;
        types |= 1 << category3;
        maxDamage = categoryScore[category3];
        maxScore = categoryScore[category3];
        if (category3 == 1 || category3 == 0)
            maxRanged = categoryScore[category3];
    }
    if (target && bestWeapons[0])
    {
        int projectile = bestWeapons[0]->GetOrFallback(actor)->FUN_004fd3c0();
        if (!DAT_011f1958->IsThreatWithinLimits(actor, projectile, target->Position(), DAT_010162c0))
            FUN_00442a80(projectile);
    }
    timer.FUN_008d7f40(*DAT_011cf660.FUN_00403e20());
}
}

struct Caster99a420
{
    int GetTarget();
};
struct Slot99a420
{
    int target;
};
struct Track99a420
{
    int unk00;
    int target;
};

struct Combat99a420
{
    int unk000;
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
    Track99a420* track;
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
    Caster99a420* caster;
    int unk190;
    int unk194;
    int unk198;
    Slot99a420* slot3;
    Slot99a420* slot4;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int target;

    Slot99a420* GetSlot(unsigned int idx);
    void ClearSlot(unsigned int idx);
    void ClearCaster();
    void FUN_0099a420(int aTarget, bool bKeep);
};

void __fastcall FreeAndClearFieldC4(Combat99a420* thisp);

// @fnv 0x0099a420
void Combat99a420::FUN_0099a420(int aTarget, bool bKeep)
{
    Slot99a420* pSavedSlot3 = slot3;
    Slot99a420* pSavedSlot4 = slot4;
    for (unsigned int i = 0; i < 5; i++)
    {
        Slot99a420* pSlot = GetSlot(i);
        if (pSlot && pSlot->target == aTarget)
            ClearSlot(i);
    }
    if (!bKeep)
    {
        if (pSavedSlot3 != GetSlot(3) || pSavedSlot4 != GetSlot(4))
        {
            ClearSlot(3);
            ClearSlot(4);
        }
    }
    if (track && track->target == aTarget)
        FreeAndClearFieldC4(this);
    if (caster && caster->GetTarget() == aTarget)
        ClearCaster();
    if (target == aTarget)
        target = 0;
}

struct PointC
{
    float x, y, z;
    PointC();
    PointC operator-(const PointC&) const;
    float Squared() const;
    float Length() const;
};
struct LocationC
{
    int a, b, c, d, e, f, g, h, i, j;
    LocationC(const PointC*, void*);
    ~LocationC();
    bool Validate(float);
};
struct SegmentC
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
    PointC start, kEnd4, third;
    unsigned char b4c, b4d, b4e, b4f, b50;
    bool IsSpecial();
    bool IsOther();
    bool Test(PointC*);
    PointC GetLocation();
};
struct ActorC
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
    virtual PointC* Position();
    float Radius();
    float Speed();
    void* Space();
};
struct InfoC
{
    int a, b, c, d;
    InfoC();
    void Set(PointC*, void*);
};
struct QueryC
{
    int Test(InfoC*, float, int);
};
struct OptionsC;
struct ControllerC
{
    ActorC* Actor();
    QueryC* Query();
    bool ValidateCandidate(void*, SegmentC*, ControllerC*, float, OptionsC*, bool, bool);
};
struct TimeC
{
    float value;
    TimeC(float);
    TimeC(const TimeC&);
};
struct HazardC
{
    float Evaluate(PointC, ActorC*, float, float, TimeC, float);
};
struct WorldC
{
    ControllerC* Controller();
    HazardC* Hazard();
};
extern WorldC* worldC;
extern const float defaultC;
extern const float negativeC;
bool GeometryC(const PointC*, const PointC*, const PointC*, const PointC*);
bool AllowedC(ControllerC*, SegmentC*, void*, PointC*, PointC*);
bool CollisionC(void*, void*, PointC*, PointC*, int, int);
bool ObstructedC(LocationC*, PointC*, int);
struct DestinationC
{
    void Set(PointC*, int);
};
struct OptionsC
{
    unsigned char a, b, c, d, e, f;
};
struct SearchC
{
    int unk000;
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
    ControllerC* controller;
    bool Reject(void*);
    bool Adjust(SegmentC*, PointC*, PointC*, ActorC*);
    bool CheckSpace(PointC*, void*, int, int);
    bool Blocked(LocationC*, ActorC*);
    bool FindPathCandidate(SegmentC*, DestinationC*, OptionsC*, PointC*, void*, void*, int, ActorC*, ActorC*, float,
                           float, int*, float*, bool);
};
// @fnv 0x0099c230
bool SearchC::FindPathCandidate(SegmentC* segment, DestinationC* destination, OptionsC* options, PointC* target,
                                void* first, void* second, int mode, ActorC* actor, ActorC* reference, float nearRange,
                                float farRange, int* piReason, float* pfDistance, bool force)
{
    ActorC* actor13 = controller->Actor();
    float range4 = defaultC;
    if (segment->IsSpecial() && !force && !segment->b4f && !segment->b50)
    {
        *piReason = 2;
        return false;
    }
    if (first == second && !GeometryC(&segment->GetLocation(), reference->Position(), &segment->start, &segment->kEnd4))
    {
        *piReason = 13;
        return false;
    }
    if (Reject(first))
    {
        *piReason = 3;
        return false;
    }
    int failure5 = 0;
    int prevA = 0;
    *pfDistance = 0.0f;
    float travelTime8 = negativeC;
    float radius = actor13->Radius();
    unsigned preferred3 = 1;
    if (options->b)
    {
        if (options->f)
            preferred3 = 0;
    }
    else if (segment->Test(actor->Position()))
        preferred3 = 0;
    bool _special = segment->IsSpecial() && !force;
    bool _aim = (segment->IsSpecial() || segment->IsOther()) && !force;
    unsigned cCount = (_special ? 1 : 0) + 1;
    for (unsigned iteration = 0; iteration < cCount; iteration++)
    {
        if (failure5)
            prevA = failure5;
        bool alternate4 = false;
        if (_special)
        {
            if (iteration == preferred3 && segment->b4f)
                alternate4 = true;
            else if (iteration != preferred3 && segment->b50)
                alternate4 = false;
            else
                continue;
        }
        if (!worldC->Controller()->ValidateCandidate(first, segment, controller, radius, options, force, alternate4))
        {
            failure5 = 9;
            continue;
        }
        PointC fStartB;
        PointC kEnd4;
        AllowedC(controller, segment, options, &fStartB, &kEnd4);
        if (segment->IsOther() && reference && !Adjust(segment, &fStartB, target, reference))
        {
            failure5 = 6;
            continue;
        }
        LocationC location(&fStartB, segment);
        if (!location.Validate(actor13->Radius()))
        {
            failure5 = 4;
            continue;
        }
        if (_aim)
        {
            LocationC other4(&kEnd4, segment);
            if (!other4.Validate(actor13->Radius()))
            {
                failure5 = 5;
                continue;
            }
        }
        if (!CheckSpace(&fStartB, actor->Space(), 1, 0))
        {
            failure5 = 16;
            continue;
        }
        *pfDistance = (*target - fStartB).Squared();
        if (*pfDistance > farRange * farRange)
        {
            failure5 = 7;
            continue;
        }
        if (*pfDistance < nearRange * nearRange)
        {
            failure5 = 8;
            continue;
        }
        InfoC pInfo5;
        pInfo5.Set(&fStartB, actor->Space());
        if (controller->Query()->Test(&pInfo5, range4, 0))
        {
            failure5 = 10;
            continue;
        }
        if (travelTime8 == -1.0)
        {
            PointC delta4 = *actor->Position() - fStartB;
            travelTime8 = delta4.Length() / actor->Speed();
        }
        if (worldC->Hazard()->Evaluate(fStartB, actor, travelTime8, 0.0f, TimeC(0.0f), 0.0f) > 0.0)
        {
            failure5 = 11;
            continue;
        }
        if (_aim)
        {
            if (worldC->Hazard()->Evaluate(kEnd4, actor, travelTime8, 0.0f, TimeC(0.0f), 0.0f) > 0.0)
            {
                failure5 = 12;
                continue;
            }
        }
        bool _d0x = ObstructedC(&location, target, 1);
        if (!_d0x)
            _d0x = Blocked(&location, reference);
        if (_d0x)
        {
            failure5 = 13;
            continue;
        }
        bool checkPackage = true;
        if (mode == 5)
            checkPackage = false;
        else if (force)
            checkPackage = false;
        else if (first == second)
            checkPackage = false;
        if (checkPackage)
        {
            bool clear5 = CollisionC(actor, reference, &kEnd4, target, 1, -1);
            if (!clear5)
            {
                failure5 = 14;
                continue;
            }
        }
        destination->Set(&fStartB, 0);
        return true;
    }
    if (prevA > failure5)
        *piReason = prevA;
    else
        *piReason = failure5;
    return false;
}

struct FUN_005c3420_cls
{
    int __thiscall FUN_005c3420(ParentSpaceNode* out);
};
struct FUN_00439ef0_cls
{
    void __thiscall FUN_00439ef0(ParentSpaceNode* out, int v);
};
struct FUN_004a7290_cls
{
    double __thiscall FUN_004a7290();
};
bool __cdecl FUN_006d7490(void* a, ParentSpaceNode* b, int c, int d);
extern double DAT_0108d658;

// @fnv 0x0099cc60
bool __cdecl FUN_0099cc60(void* pNodeA, ParentSpaceNode* pNodeB, int c)
{
    ParentSpaceNode s1;
    ParentSpaceNode s2;
    if ((unsigned char)c == 0)
    {
        ((FUN_00439ef0_cls*)pNodeB)->FUN_00439ef0(&s2, ((FUN_005c3420_cls*)pNodeA)->FUN_005c3420(&s1));
        if (((FUN_004a7290_cls*)&s2)->FUN_004a7290() > DAT_0108d658)
        {
            return false;
        }
    }
    if (FUN_006d7490(pNodeA, pNodeB, 0, 0) == false)
    {
        return false;
    }
    return true;
}

struct NiPoint3Ex : NiPoint3
{
    NiPoint3Ex operator-(const NiPoint3& kPt) const;
    float FUN_004a7290() const;
};
float GetDirectionAngle(const NiPoint3Ex& kPt);
float FUN_004b15e0(float fA, float fB, float* pfOut);
namespace std {
float abs(float);
}
struct FUN_0099ccd0_Actor
{
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
    virtual void Unk_4C();
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
    virtual void Unk_7E();
    virtual void Unk_7F();
    virtual void Unk_80();
    virtual void Unk_81();
    virtual void Unk_82();
    virtual void Unk_83();
    virtual void Unk_84();
    virtual void Unk_85();
    virtual void Unk_86();
    virtual void Unk_87();
    virtual void Unk_88();
    virtual void Unk_89();
    virtual void Unk_8A();
    virtual void Unk_8B();
    virtual void Unk_8C();
    virtual void Unk_8D();
    virtual void Unk_8E();
    virtual void Unk_8F();
    virtual void Unk_90();
    virtual void Unk_91();
    virtual void Unk_92();
    virtual void Unk_93();
    virtual void Unk_94();
    virtual void Unk_95();
    virtual void Unk_96();
    virtual void Unk_97();
    virtual void Unk_98();
    virtual void Unk_99();
    virtual void Unk_9A();
    virtual void Unk_9B();
    virtual void Unk_9C();
    virtual void Unk_9D();
    virtual void Unk_9E();
    virtual void Unk_9F();
    virtual void Unk_A0();
    virtual void Unk_A1();
    virtual void Unk_A2();
    virtual void Unk_A3();
    virtual void Unk_A4();
    virtual void Unk_A5();
    virtual void Unk_A6();
    virtual void Unk_A7();
    virtual void Unk_A8();
    virtual void Unk_A9();
    virtual void Unk_AA();
    virtual void Unk_AB();
    virtual void Unk_AC();
    virtual void Unk_AD();
    virtual void Unk_AE();
    virtual float GetCurrentTargetDistance(int iUnk);
};
class PathingLocation
{
  public:
    int m_data[10];
    ~PathingLocation();
};
struct FUN_006dce10 : PathingLocation
{
    FUN_006dce10(const NiPoint3& kPt, TESObjectREFR* pRef);
};
struct FUN_006e4820_class
{
    bool FUN_006e4820();
};
struct FUN_008a1710_shell
{
    TESObjectWEAP* FUN_008a1710();
};
float GetActorReach(Actor* pActor, TESObjectWEAP* pWeap);
extern const double DAT_0106cd60;
extern const double DAT_01016ff0;

struct FUN_0099ccd0_shell : Combat99
{
    bool FUN_0099ccd0(Seg99* pSeg, NiPoint3Ex* pPos, FUN_0099ccd0_Actor* pActor, bool bCheckAngle);
};

// @fnv 0x0099ccd0
bool FUN_0099ccd0_shell::FUN_0099ccd0(Seg99* pSeg, NiPoint3Ex* pPos, FUN_0099ccd0_Actor* pActor, bool bCheckAngle)
{
    NiPoint3 kTargetPos = *pActor->GetPos();
    NiPoint3Ex kDiff = *pPos - kTargetPos;
    float fDistSqr9 = kDiff.FUN_004a7290();
    if (fDistSqr9 < DAT_0106cd60)
        return false;
    if (bCheckAngle)
    {
        float fDesiredHeadingAngle = GetDirectionAngle(kDiff);
        float fUnused;
        float fAngleDifference = FUN_004b15e0(pActor->GetCurrentTargetDistance(0), fDesiredHeadingAngle, &fUnused);
        if (std::abs(fAngleDifference) > 0.78539818525314331)
            return true;
    }
    if (FUN_009a9630(pActor))
    {
        float fImpulseRadiusSquared = GetActorReach((Actor*)pActor, ((FUN_008a1710_shell*)pActor)->FUN_008a1710()) * DAT_01016ff0;
        if (fDistSqr9 < fImpulseRadiusSquared * fImpulseRadiusSquared)
            return false;
    }
    else
    {
        FUN_006dce10 kLoc(*pPos, (TESObjectREFR*)pActor);
        if (FUN_006d7490((Picker*)&kLoc, (Vec3*)&kTargetPos, 0, 0))
            return false;
        if (((FUN_006e4820_class*)pSeg)->FUN_006e4820())
        {
            if (!FUN_0099cec0(pSeg, (Pt3*)pPos, (Pt3*)pActor->GetPos(), (TESObjectREFR*)pActor))
                return false;
        }
    }
    return true;
}

struct FUN_0099d310_actor_calls
{
    float FUN_008be1b0();
    float FUN_008a0b10();
};
struct FUN_0099d310_field_calls
{
    float GetFieldCC();
    bool FUN_00998a30();
    float FUN_00453700();
};
struct FUN_0099d310_window
{
    void FUN_007cb2e0();
};
struct FUN_0099d310_arg
{
    void FUN_00507610(float);
    void FUN_006e5ee0(float);
    void FUN_006e4ef0(float);
    void FUN_006e4320(float);
    void FUN_005076c0(float);
    void FUN_006e4f10(unsigned int);
    int GetOffsetF4();
    int FUN_006e4f90();
    FUN_0099d310_window* FUN_006e4f90(void*);
};
struct FUN_0099d310_shell : C99
{
    bool FUN_0097ee90();
    void CollectCastSoundPositions(int);
    void CollectAvoidanceItems(int);
    void FUN_0099d310(FUN_0099d310_arg*);
};
// @fnv 0x0099d310
void FUN_0099d310_shell::FUN_0099d310(FUN_0099d310_arg* param)
{
    MobileObject* actor = ((TESAmmoInitCalls*)f1C4)->GetFieldBC();
    void* item = ((AlchemyItem*)f1C4)->FUN_004030b0();
    param->FUN_00507610(((FUN_0099d310_actor_calls*)actor)->FUN_008be1b0());
    param->FUN_006e5ee0(((FUN_0099d310_actor_calls*)actor)->FUN_008a0b10());
    param->FUN_006e4ef0(((FUN_0099d310_field_calls*)f1C4)->GetFieldCC());
    if (((FUN_0099d310_field_calls*)f1C4)->FUN_00998a30())
    {
        param->FUN_006e4320(((FUN_0099d310_field_calls*)f1C4)->FUN_00453700());
    }
    param->FUN_005076c0((float)((int(__thiscall*)(void*, unsigned int))(*(unsigned int**)((char*)actor + 0xa4))[2])(
        (char*)actor + 0xa4, 0x10));
    if (item != 0)
    {
        if (FUN_0097ee90() && (unsigned char)_pad[0x74] == 0)
        {
            param->FUN_006e4f10(((int(__thiscall*)(void*))(*(unsigned int**)item)[0x1f4 / 4])(item));
        }
        CollectCastSoundPositions(param->GetOffsetF4());
    }
    CollectAvoidanceItems(param->FUN_006e4f90());
    if (*((void**)&_pad[0xe4]) != 0 && *((unsigned char*)*((void**)&_pad[0xe4]) + 1) != 0)
    {
        param->FUN_006e4f90((char*)*((void**)&_pad[0xe4]) + 0x68)->FUN_007cb2e0();
    }
}

struct Sub14
{
    int FUN_006e4570();
    int FUN_006e4740();
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
};

struct FUN_006d3150
{
    FUN_006d3150();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Sub14 sub14;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
};

struct RetObjParam
{
    void FUN_006e4430(void*);
};

struct LocalData2C
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    float unk18;
    int unk1c;
    LocalData2C* FUN_0097ee20();
};

struct CombatDecompClass : FUN_0099a9a0_shell
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
    FUN_006d3150* unkE8;
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

    bool FUN_0099d030(void* p1, FUN_006d3150* p2, LocalData2C* p3, int p4, int p5, float p6, int p7);
    bool InitSubObject(RetObjParam* a1, int a2, int a3, float a4, int a5);
};

// Resets the object, allocates a FUN_006d3150, initialises local data and calls FUN_0099d030; on success stores two sub14 values and passes sub14 to a1.
// @fnv 0x0099e060
bool CombatDecompClass::InitSubObject(RetObjParam* pRetObj, int a2, int a3, float a4, int a5)
{
    this->ReleaseStageHolder(0);
    this->unkE8 = new FUN_006d3150();
    LocalData2C local2c;
    local2c.FUN_0097ee20();
    if (!this->FUN_0099d030(&this->unk128, this->unkE8, &local2c, a3, a2, a4, a5))
    {
        this->ReleaseStageHolder(0);
        return false;
    }
    this->unkE8->unk68 = this->unkE8->sub14.FUN_006e4570();
    this->unkE8->unk6c = this->unkE8->sub14.FUN_006e4740();
    pRetObj->FUN_006e4430(&this->unkE8->sub14);
    return true;
}

struct PickWeapon;
struct PickActor;
struct PickRef;
struct PickVec
{
    float x, y, z;
};
struct PickLoc
{
    float x, y, z;
    unsigned space;
    float FUN_00527a40(PickLoc*);
};
struct PickBase
{
    PickWeapon* GetField158();
};
struct PickNode
{
    bool FUN_00418b10();
};
struct PickWrap
{
    PickNode* node;
    PickWrap* FUN_006815c0();
};
struct PickPtr
{
    PickWrap* FUN_00559450();
};
struct PickProc
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
    virtual PickPtr* GetActive();
};
struct PickExtra
{
    float FUN_004186f0();
    void* GetExtraAmmo();
};
struct PickLock
{
    bool FUN_005021a0();
};
struct PickForm
{
    unsigned FUN_00401170();
};
struct PickWeapon
{
    bool FUN_004c0c30();
    bool FUN_006450c0();
    void* FUN_00525980(PickActor*);
};
struct PickRef
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
    virtual PickVec* Pos();
    PickLoc FUN_00575650();
    PickExtra* FUN_005d43c0();
    bool FUN_00477ba0();
    PickWeapon* FUN_007af430();
    PickLock* FUN_00569160();
    void* FUN_00567790();
    bool FUN_005785e0(PickActor*, bool);
    unsigned FUN_00575610(void*);
};
struct PickActor : PickRef
{
    virtual void a126();
    virtual void a127();
    virtual void a128();
    virtual void a129();
    virtual void a130();
    virtual void a131();
    virtual void a132();
    virtual void a133();
    virtual void a134();
    virtual bool IsCreature();
    PickBase* FUN_004181e0();
    PickProc* FUN_008d8520();
    bool FUN_008bc9d0(PickWeapon*, int);
};
struct PickController
{
    PickActor* GetFieldBC();
    PickRef* FUN_004030b0();
    bool FUN_009a0240();
    PickWeapon* FUN_0044ddc0();
    unsigned FUN_00980070();
};
struct PickEntry
{
    float FUN_004bcdb0(int);
    PickWeapon* FUN_0044ddc0();
};
struct PickIter
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
    PickIter(int, PickActor*);
    PickIter(void*, PickActor*);
    ~PickIter();
};
struct PickCollection
{
    bool FindNextRef(PickIter*, PickRef**, PickEntry**, int);
};
extern PickCollection* DAT_011c95c8;
struct PickGlobal
{
    void FUN_00483710();
};
extern PickGlobal g_011f1a60;
struct PickSetting
{
    float* FUN_00403e20();
};
extern PickSetting DAT_011cfb6c;
extern PickSetting DAT_011cee9c;
extern PickSetting DAT_011cec4c;
extern PickSetting DAT_011cf320;
extern PickSetting DAT_011ce460;
extern PickSetting DAT_011cfb44;
extern PickSetting DAT_011cef08;
extern PickSetting DAT_011cfa10;
extern PickSetting DAT_011cf908;
extern PickSetting DAT_011ce260;
extern PickSetting DAT_011ce7fc;
extern PickSetting DAT_011cf0c8;
extern float DAT_0108df70;
unsigned FUN_004873d0(PickWeapon*);
float ComputeWeaponDamage(PickActor*, PickWeapon*, float, unsigned, int, int);
float FUN_0040ebd0(float, float);
float FUN_004579e0(float);
float FUN_00404010(float, float);
struct WeaponSearch
{
    int unk000;
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
    float unk058;
    float unk05c;
    int unk060;
    float unk064;
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
    PickController* controller;
    bool FUN_0097fd40();
    bool FUN_009a02a0(PickLoc*, int, int);
    void SetArrayEntry(int, PickRef*, void*);
    bool SelectBestWeaponTarget();
};
// Scans nearby refs for a weapon target, scores candidates by distance and damage, and records the best pick via SetArrayEntry.
// @fnv 0x0099f6d0
bool WeaponSearch::SelectBestWeaponTarget()
{
    PickActor* aC1 = controller->GetFieldBC();
    PickRef* aFB = controller->FUN_004030b0();
    if (!controller->FUN_009a0240())
        return false;
    if (unk034 || ((PickEntry*)&unk024)->FUN_0044ddc0())
        return false;
    if (aC1->IsCreature())
    {
        PickBase* aPC = aC1->FUN_004181e0();
        PickWeapon* aXi = aPC->GetField158();
        if (!aXi)
            return false;
    }
    PickPtr* aId = aC1->FUN_008d8520()->GetActive();
    if (aId && aId->FUN_00559450() && aId->FUN_00559450()->FUN_006815c0()->node &&
        aId->FUN_00559450()->FUN_006815c0()->node->FUN_00418b10())
        return false;
    g_011f1a60.FUN_00483710();
    PickLoc aI4 = aC1->FUN_00575650();
    PickRef* aCr = 0;
    PickWeapon* aB8 = 0;
    PickRef* aB4 = 0;
    void* aCb = 0;
    PickWeapon* aFg = controller->FUN_0044ddc0();
    bool aC2 = FUN_0097fd40();
    float aRt = aC2 ? unk05c : unk058;
    float aKB = aRt * (1.0f + *DAT_011cfb6c.FUN_00403e20());
    float aPE = 1.0f;
    if (unk064 > unk058)
    {
        aPE = *DAT_011cfa10.FUN_00403e20();
        aKB = FUN_0040ebd0(aKB, unk064);
    }
    if (aC2)
        aPE = *DAT_011cf908.FUN_00403e20();
    float aPa = 0.0f;
    float aIt = 0.0f;
    if (aC2 || (aFg && aFg->FUN_004c0c30()))
    {
        aPa = *DAT_011cfb44.FUN_00403e20();
        aIt = *DAT_011cef08.FUN_00403e20();
    }
    else
    {
        if (!aFg)
        {
            aPa = *DAT_011cee9c.FUN_00403e20();
            aIt = *DAT_011cec4c.FUN_00403e20();
        }
        else
        {
            aPa = *DAT_011cf320.FUN_00403e20();
            aIt = *DAT_011ce460.FUN_00403e20();
        }
        bool apX = false;
        if (aFB)
        {
            PickLoc bpA = aFB->FUN_00575650();
            if (aI4.FUN_00527a40(&bpA) < 589824.0)
                apX = true;
        }
        if (!apX && unk05c > 0.0 && unk058 > 0.0)
        {
            float cb2 = unk05c / unk058;
            if (cb2 > *DAT_011ce260.FUN_00403e20() && *DAT_011cef08.FUN_00403e20() > aIt)
                aIt = aIt + cb2 * (*DAT_011cef08.FUN_00403e20() - aIt);
        }
    }
    aPa *= aPE;
    aIt *= aPE;
    float aB1 = 0.0f;
    float aP2 = DAT_0108df70;
    PickIter ap8(40, aC1);
    PickRef* aFC = 0;
    PickEntry* aPb = 0;
    while (DAT_011c95c8->FindNextRef(&ap8, &aFC, &aPb, 3))
    {
        float cbX = aPb ? aPb->FUN_004bcdb0(0) : aFC->FUN_005d43c0()->FUN_004186f0();
        if (aFC->FUN_00477ba0() || cbX == 0.0)
            continue;
        PickWeapon* aRy = aPb ? aPb->FUN_0044ddc0() : aFC->FUN_007af430();
        float ap9 = 1.0f;
        if (cbX != -1.0)
            ap9 = cbX / FUN_004873d0(aRy);
        float ch3 = ComputeWeaponDamage(aC1, aRy, ap9, controller->FUN_00980070(), 0, 0);
        if (aRy->FUN_006450c0())
            ch3 *= *DAT_011cf0c8.FUN_00403e20();
        if (ch3 <= aKB)
            continue;
        if (aC2 && !aRy->FUN_004c0c30())
            continue;
        if (!aC1->FUN_008bc9d0(aRy, 0))
            continue;
        float cbA = 0.0f;
        if (aKB <= 0.0)
            cbA = aIt * aIt;
        else
        {
            float c_2 = ch3 / aKB;
            c_2 = FUN_0040ebd0(c_2, *DAT_011ce7fc.FUN_00403e20());
            float d_2 = (c_2 - 1.0) / (*DAT_011ce7fc.FUN_00403e20() - 1.0);
            float b10 = aPa + d_2 * (aIt - aPa);
            cbA = b10 * b10;
        }
        PickLoc aPH = aFC->FUN_00575650();
        float aM4 = aPH.FUN_00527a40(&aI4);
        if (aM4 >= cbA)
            continue;
        if (!FUN_009a02a0(&aPH, 1, 0))
            continue;
        if (aFC->FUN_007af430() && ((PickForm*)aFC->FUN_007af430())->FUN_00401170() == 27)
        {
            PickWeapon* base = aFC->FUN_007af430();
            if (base)
            {
                if (aFC->FUN_00569160() && aFC->FUN_00569160()->FUN_005021a0())
                    continue;
                if (aFC->FUN_00567790() && !aFC->FUN_005785e0(aC1, true))
                    continue;
            }
        }
        PickRef* ch8 = 0;
        bool ap3 = true;
        void* ap7 = aRy->FUN_00525980(aC1);
        if (ap7)
        {
            ap3 = false;
            if (!aPb && aFC->FUN_005d43c0()->GetExtraAmmo())
                ap3 = true;
            if (!ap3 && aC1->FUN_00575610(ap7))
                ap3 = true;
            if (!ap3 && aPb && aFC->FUN_00575610(ap7))
            {
                ap3 = true;
                ch8 = aFC;
            }
            if (!ap3)
            {
                float cb3 = DAT_0108df70;
                PickVec cb5 = *aFC->Pos();
                PickIter dy9(ap7, aC1);
                PickRef* cbB = 0;
                PickEntry* e2x = 0;
                while (DAT_011c95c8->FindNextRef(&dy9, &cbB, &e2x, 3))
                {
                    PickLoc fA8 = cbB->FUN_00575650();
                    float fEA = fA8.FUN_00527a40(&aI4) + fA8.FUN_00527a40(&aPH);
                    if (fEA > cbA || fEA > cb3)
                        continue;
                    if (!FUN_009a02a0(&fA8, 1, 0))
                        continue;
                    ch8 = cbB;
                    cb3 = fEA;
                    aM4 = fEA;
                    ap3 = true;
                }
            }
        }
        if (ap3)
        {
            float ch2 = FUN_00404010(FUN_004579e0(aM4), 64.0f);
            float fT7 = ch3 * 10000.0 / ch2;
            bool crA = false;
            if (fT7 > aB1)
            {
                crA = true;
            }
            else if (fT7 == aB1 && aM4 < aP2)
                crA = true;
            if (crA)
            {
                aB1 = fT7;
                aP2 = aM4;
                aCr = aFC;
                aB8 = aCr ? aRy : 0;
                aB4 = ch8;
                aCb = ch8 ? ap7 : 0;
            }
        }
    }
    g_011f1a60.FUN_00483710();
    if (aCr)
    {
        SetArrayEntry(3, aB4, aCb);
        SetArrayEntry(4, aCr, aB8);
        return true;
    }
    return false;
}

extern double DAT_010718b8;
extern double _gModifierZero;

struct CS_Loc16
{
    int v0;
    int v4;
    int v8;
    int vC;
};

struct CS_AVOwner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetActorValue(int);
};

struct CS_Actor
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
    CS_AVOwner avOwner;
    float GetScaledRange(float);
    CS_Loc16 GetLocation(float);
};

struct CS_Item
{
    float GetRangeA(CS_Actor*);
    float GetDivA();
    float GetRangeB(CS_Actor*);
    float GetDivB();
    int TestLocation(const CS_Loc16&, int);
};

struct CS_Flags
{
    bool IsSet();
};

struct CS_Owner
{
    CS_Actor* GetActor();
    CS_Item* GetItem();
    CS_Flags* GetFlags();
};

struct CS_Timer
{
    float GetElapsedTime();
};

struct CS_Setting
{
    float* Float();
};
extern CS_Setting originalRuntimeFloatSetting439;

struct CS_State
{
    int unk00;
    int unk04;
    float fImpulseRadiusSquared;
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
    CS_Timer timerA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    unsigned char unkC8;
    unsigned char ucC9;
    unsigned char unkCA;
    unsigned char unkCB;
    int unkCC;
    int unkD0;
    int unkD4;
    unsigned char ucD8;
    unsigned char unkD9;
    unsigned char unkDA;
    unsigned char unkDB;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    CS_Owner* pOwner;
    void MarkDone(int);
    void UpdateRangeValue();
};

// @fnv 0x009a1060
void CS_State::UpdateRangeValue()
{
    CS_Actor* pActor2 = pOwner->GetActor();
    if (ucD8 != 1)
    {
        fImpulseRadiusSquared = 100.0f;
        if (timerA0.GetElapsedTime() < DAT_010718b8)
        {
            if (pActor2->avOwner.GetActorValue(0) != 3.0)
            {
                CS_Item* pItem5 = pOwner->GetItem();
                float fA4 = pItem5->GetRangeA(pActor2);
                float fDivA4 = pItem5->GetDivA();
                if (fA4 >= _gModifierZero && fDivA4 > _gModifierZero)
                {
                    fImpulseRadiusSquared = fA4 / fDivA4;
                    if (fImpulseRadiusSquared > _gModifierZero && pOwner->GetFlags()->IsSet())
                    {
                        float _fB = pItem5->GetRangeB(pActor2);
                        float fDivB5 = pItem5->GetDivB();
                        if (_fB >= _gModifierZero && fDivB5 > _gModifierZero)
                        {
                            float fScaled5 = pActor2->GetScaledRange(_fB);
                            float fNew2 = fScaled5 / fDivB5;
                            if (fNew2 < fImpulseRadiusSquared)
                            {
                                fImpulseRadiusSquared = fNew2;
                            }
                        }
                    }
                }
                if (ucD8 == 2 && ucC9 < 4)
                {
                    if (pItem5->TestLocation(pActor2->GetLocation(*originalRuntimeFloatSetting439.Float()), 1))
                    {
                        MarkDone(1);
                    }
                }
            }
        }
    }
}

struct Save435
{
    void FUN_00865e50(void*, unsigned, int);
    void FUN_00865df0(void*, int);
    void FUN_00865db0(void*, int);
    void FUN_00865f60(unsigned);
};
struct Stamp435
{
    unsigned value;
    void SaveTimeStamp(Save435*);
};
struct Pair435
{
    unsigned first, second;
    void FUN_009a5eb0(Save435*);
};
struct Item435
{
    void FUN_009a2d20(Save435*);
};
struct ItemB435
{
    void FUN_009a2d80(Save435*);
};
struct List435
{
    unsigned first, second, third, fourth;
    unsigned FUN_0044ddc0();
    void** FUN_006a7ad0(unsigned);
    Item435* FUN_00844160(unsigned);
    ItemB435* FUN_006dad90(unsigned);
};
struct Optional435
{
    void FUN_009a2de0(Save435*);
};
struct OptionalB435
{
    void FUN_009a2bf0(Save435*);
};
struct OptionalC435
{
    void FUN_009a3130(Save435*);
};
struct Float435
{
    float value;
    float FUN_006a7f50();
};
struct Location435
{
    unsigned x00, x04, x08, x0c, x10, x14, x18;
    Float435 range;
    unsigned x20, x24, x28, x2c, x30, x34, x38;
    void FUN_009a2f50(Save435*);
};
struct RefPair435
{
    void* first;
    void* second;
};
extern float DAT_0108df70;
struct Vec435
{
    float x, y, z;
};
struct Owner435
{
    unsigned char flag;
    unsigned char unk1;
    unsigned char unk2;
    unsigned char unk3;
    unsigned f04;
    unsigned f08;
    void* references[6];
    List435 list24;
    void* reference34;
    unsigned f38;
    unsigned values[7];
    unsigned f58;
    unsigned f5c;
    unsigned unk60;
    unsigned f64;
    unsigned f68;
    unsigned f6c;
    unsigned char f70;
    unsigned char f71;
    unsigned char f72;
    unsigned char f73;
    unsigned char f74;
    unsigned char f75;
    unsigned char f76;
    unsigned char f77;
    void* reference78;
    unsigned f7c;
    unsigned f80;
    Vec435 position;
    unsigned f90;
    Stamp435 s94;
    Stamp435 s98;
    Stamp435 s9c;
    Stamp435 sa0;
    Stamp435 sa4;
    Pair435 pa8;
    Pair435 pb0;
    Pair435 pb8;
    Stamp435 sc0;
    OptionalC435* optionalC;
    unsigned char fc8;
    unsigned char fc9;
    unsigned char unkca;
    unsigned char unkcb;
    unsigned fcc;
    unsigned fd0;
    unsigned fd4;
    unsigned char fd8;
    unsigned char unkd9;
    unsigned char unkda;
    unsigned char unkdb;
    void* referencedc;
    Stamp435 se0;
    Optional435* optionalE4;
    Optional435* optionalE8;
    Location435 location1;
    Location435 location2;
    List435 list164;
    List435 list174;
    Stamp435 s184;
    unsigned char f188;
    unsigned char unk189;
    unsigned char unk18a;
    unsigned char unk18b;
    OptionalB435* optional18c;
    RefPair435* pairs[5];
    void* refs[2];
    Pair435 timers[2];
    unsigned f1bc;
    void* ref1c0;
    unsigned unk1c4;
    unsigned char f1c8;
    unsigned char unk1c9;
    unsigned char unk1ca;
    unsigned char unk1cb;
    Pair435 p1cc;
    Pair435 p1d4;
    Pair435 p1dc;
    Pair435 p1e4;
    Pair435 p1ec;
    Pair435 p1f4;
    Pair435 p1fc;
    Pair435 p204;
    Pair435 p20c;
    Pair435 p214;
    Pair435 p21c;
    unsigned unk224;
    unsigned f228;
    void SaveToStream(Save435*);
};
// Serializes the object's fields, references, lists, timers and optional sub-objects into the save buffer, writing presence flags before each optional block.
// @fnv 0x009a17a0
void Owner435::SaveToStream(Save435* pSaveBuffer)
{
    pSaveBuffer->FUN_00865e50(&flag, 1, 0);
    pSaveBuffer->FUN_00865e50(&f04, 4, 0);
    for (unsigned i = 0; i < 6; i++)
        pSaveBuffer->FUN_00865df0(references[i], 0);
    {
        unsigned count = &list24 ? list24.FUN_0044ddc0() : 0;
        pSaveBuffer->FUN_00865f60(count);
        for (unsigned j = 0; j < count; j++)
        {
            void** item = list24.FUN_006a7ad0(j);
            pSaveBuffer->FUN_00865df0(*item, 0);
        }
    }
    pSaveBuffer->FUN_00865df0(reference34, 0);
    pSaveBuffer->FUN_00865e50(&f38, 4, 0);
    for (unsigned uiValueIndex = 0; uiValueIndex < 7; uiValueIndex++)
        pSaveBuffer->FUN_00865e50(&values[uiValueIndex], 4, 0);
    pSaveBuffer->FUN_00865e50(&f58, 4, 0);
    pSaveBuffer->FUN_00865e50(&f5c, 4, 0);
    pSaveBuffer->FUN_00865e50(&f64, 4, 0);
    pSaveBuffer->FUN_00865e50(&f68, 4, 0);
    pSaveBuffer->FUN_00865e50(&f6c, 4, 0);
    pSaveBuffer->FUN_00865e50(&f70, 1, 0);
    pSaveBuffer->FUN_00865e50(&f71, 1, 0);
    pSaveBuffer->FUN_00865e50(&f72, 1, 0);
    pSaveBuffer->FUN_00865e50(&f73, 1, 0);
    pSaveBuffer->FUN_00865e50(&f74, 1, 0);
    pSaveBuffer->FUN_00865e50(&f75, 1, 0);
    pSaveBuffer->FUN_00865e50(&f76, 1, 0);
    pSaveBuffer->FUN_00865e50(&f77, 1, 0);
    pSaveBuffer->FUN_00865df0(reference78, 0);
    pSaveBuffer->FUN_00865e50(&f7c, 4, 0);
    pSaveBuffer->FUN_00865e50(&f80, 4, 0);
    pSaveBuffer->FUN_00865e50(&position, 12, 0);
    pSaveBuffer->FUN_00865e50(&f90, 4, 0);
    pSaveBuffer->FUN_00865e50(&fc8, 1, 0);
    pSaveBuffer->FUN_00865e50(&fc9, 1, 0);
    pSaveBuffer->FUN_00865e50(&fcc, 4, 0);
    pSaveBuffer->FUN_00865e50(&fd0, 4, 0);
    pSaveBuffer->FUN_00865e50(&fd4, 4, 0);
    pSaveBuffer->FUN_00865e50(&f08, 4, 0);
    pSaveBuffer->FUN_00865e50(&fd8, 1, 0);
    pSaveBuffer->FUN_00865db0(referencedc, 0);
    s94.SaveTimeStamp(pSaveBuffer);
    s98.SaveTimeStamp(pSaveBuffer);
    s9c.SaveTimeStamp(pSaveBuffer);
    sa0.SaveTimeStamp(pSaveBuffer);
    sa4.SaveTimeStamp(pSaveBuffer);
    pa8.FUN_009a5eb0(pSaveBuffer);
    pb0.FUN_009a5eb0(pSaveBuffer);
    sc0.SaveTimeStamp(pSaveBuffer);
    pb8.FUN_009a5eb0(pSaveBuffer);
    se0.SaveTimeStamp(pSaveBuffer);
    unsigned char flags = 0;
    if (optionalE4)
        flags |= 1;
    if (location1.range.FUN_006a7f50() != -DAT_0108df70)
        flags |= 2;
    if (optionalE8)
        flags |= 4;
    if (location2.range.FUN_006a7f50() != -DAT_0108df70)
        flags |= 8;
    if (optional18c)
        flags |= 16;
    if (optionalC)
        flags |= 32;
    pSaveBuffer->FUN_00865e50(&flags, 1, 0);
    if (optionalE4)
        optionalE4->FUN_009a2de0(pSaveBuffer);
    if (optionalE8)
        optionalE8->FUN_009a2de0(pSaveBuffer);
    if (optional18c)
        optional18c->FUN_009a2bf0(pSaveBuffer);
    if (optionalC)
        optionalC->FUN_009a3130(pSaveBuffer);
    if (location1.range.FUN_006a7f50() != -DAT_0108df70)
        location1.FUN_009a2f50(pSaveBuffer);
    if (location2.range.FUN_006a7f50() != -DAT_0108df70)
        location2.FUN_009a2f50(pSaveBuffer);
    {
        unsigned uiList164Count = &list164 ? list164.FUN_0044ddc0() : 0;
        pSaveBuffer->FUN_00865f60(uiList164Count);
        for (unsigned uiList164Index = 0; uiList164Index < uiList164Count; uiList164Index++)
        {
            Item435* item2 = list164.FUN_00844160(uiList164Index);
            item2->FUN_009a2d20(pSaveBuffer);
        }
    }
    {
        unsigned uiList174Count = &list174 ? list174.FUN_0044ddc0() : 0;
        pSaveBuffer->FUN_00865f60(uiList174Count);
        for (unsigned m = 0; m < uiList174Count; m++)
        {
            ItemB435* item3 = list174.FUN_006dad90(m);
            item3->FUN_009a2d80(pSaveBuffer);
        }
    }
    s184.SaveTimeStamp(pSaveBuffer);
    pSaveBuffer->FUN_00865e50(&f188, 1, 0);
    unsigned char ucPairFlags = 0;
    for (unsigned n = 0; n < 5; n++)
    {
        if (pairs[n])
            ucPairFlags |= 1 << n;
    }
    pSaveBuffer->FUN_00865e50(&ucPairFlags, 1, 0);
    for (unsigned o = 0; o < 5; o++)
    {
        if (pairs[o])
        {
            pSaveBuffer->FUN_00865df0(pairs[o]->first, 0);
            pSaveBuffer->FUN_00865df0(pairs[o]->second, 0);
        }
    }
    for (unsigned uiRefTimerIndex = 0; uiRefTimerIndex < 2; uiRefTimerIndex++)
    {
        pSaveBuffer->FUN_00865df0(refs[uiRefTimerIndex], 0);
        timers[uiRefTimerIndex].FUN_009a5eb0(pSaveBuffer);
    }
    pSaveBuffer->FUN_00865e50(&f1bc, 4, 0);
    pSaveBuffer->FUN_00865df0(ref1c0, 0);
    pSaveBuffer->FUN_00865e50(&f1c8, 1, 0);
    pSaveBuffer->FUN_00865e50(&f228, 4, 0);
    p1cc.FUN_009a5eb0(pSaveBuffer);
    p1d4.FUN_009a5eb0(pSaveBuffer);
    p1dc.FUN_009a5eb0(pSaveBuffer);
    p1e4.FUN_009a5eb0(pSaveBuffer);
    p1ec.FUN_009a5eb0(pSaveBuffer);
    p1f4.FUN_009a5eb0(pSaveBuffer);
    p1fc.FUN_009a5eb0(pSaveBuffer);
    p20c.FUN_009a5eb0(pSaveBuffer);
    p204.FUN_009a5eb0(pSaveBuffer);
    p214.FUN_009a5eb0(pSaveBuffer);
    p21c.FUN_009a5eb0(pSaveBuffer);
}

class TESFile9A2;

class Holder9A2
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    TESObjectREFR* m_pkRef;

    void ResolveRef(TESFile9A2* pkFile);
};

// Replaces m_pkRef with the result of LookupFormByID cast to TESObjectREFR, or null if m_pkRef is null.
// @fnv 0x009a2cc0
void Holder9A2::ResolveRef(TESFile9A2* pkFile)
{
    m_pkRef = m_pkRef ? dynamic_cast<TESObjectREFR*>(LookupFormByID(m_pkRef)) : 0;
}

namespace fnv_0099b5a0 {
// 0x0099b5a0  779 bytes  /MT /Od /Oy- /GS /EHsc /Gy
struct Vec3
{
    float x, y, z;
    float GetSquaredXYLength() const;
};
struct P3
{
    float x, y, z;
    P3();
    Vec3 FUN_00439ef0(const Vec3&) const;
};

struct Sound99
{
    bool GetDetectedTargetLocation();
};
struct Snd99
{
    Vec3 pos;
    int extra;
    void FUN_0097ede0();
    void* FUN_0084e3a0();
    P3* FUN_006815c0();
};
struct Mob99
{
    void* FUN_00575ca0();
};
struct Ammo99
{
    Sound99* FUN_004fd3c0();
};
struct Weap99
{
    void* GetOrFallback(void*);
};
struct Spell99
{
    void* GetFieldBC();
    void* FUN_004030b0();
    Sound99* FUN_004fb070(void*, Snd99*);
};
struct Clock99
{
    float FUN_00435e00();
};
struct SndMgr99
{
    bool IsThreatWithinLimits(void*, Sound99*, Vec3*, float);
};
struct A1_99
{
    void FUN_0099b8b0(Vec3*, int);
};

extern "C" Vec3 DAT_011f426c;
extern "C" SndMgr99* DAT_011f1958;

void __cdecl FUN_009a8050(Vec3*, void*);
float __cdecl FUN_009a7f00(Ammo99*, float);
float __cdecl FUN_009a8460(void*, int, int);
bool __cdecl FUN_009a7670(void*, void*, Ammo99*, Vec3, P3, Vec3, char*, P3*, float);
float __cdecl ComputeProjectileFlightTime(Ammo99*, Vec3, P3, char, float);

struct FUN_0099b5a0_holder
{
    char pad00[0x84];
    P3 pt84;
    char pad90[0x98 - 0x90];
    Clock99 clk;
    char pad99[0x1c4 - 0x99];
    Spell99* p1c4;

    bool FUN_0099b5a0(A1_99* a1, char* a2, Weap99* a3);
};

// @fnv 0x0099b5a0
bool FUN_0099b5a0_holder::FUN_0099b5a0(A1_99* a1, char* acArg, Weap99* apWeapon)
{
    if (!apWeapon || !apWeapon->GetOrFallback(p1c4->GetFieldBC()))
        return false;
    Mob99* mobj3 = (Mob99*)p1c4->GetFieldBC();
    Spell99* spellB = (Spell99*)p1c4->FUN_004030b0();
    if (!spellB)
        return false;
    Ammo99* ammoA = (Ammo99*)apWeapon->GetOrFallback(mobj3);
    float f6 = FUN_009a7f00(ammoA, 0.0f);
    Vec3 posVal;
    FUN_009a8050(&posVal, mobj3);

    for (unsigned i = 0; i < 2; i++)
    {
        P3 v9;
        if (i == 0)
        {
            Snd99 s2;
            s2.FUN_0097ede0();
            if (!p1c4->FUN_004fb070(spellB, &s2)->GetDetectedTargetLocation())
                continue;
            if (s2.FUN_0084e3a0() != mobj3->FUN_00575ca0())
                continue;
            v9 = *s2.FUN_006815c0();
        }
        else
        {
            if (clk.FUN_00435e00() > 10.0)
                continue;
            v9 = pt84;
        }
        v9.z += FUN_009a8460(spellB, 2, 0);
        Vec3 d_ = v9.FUN_00439ef0(posVal);
        float len = d_.GetSquaredXYLength();
        if (f6 * f6 < len)
            continue;
        if (len < 65536.0)
            continue;

        Sound99* snd2 = ammoA->FUN_004fd3c0();
        if (snd2)
        {
            if (!DAT_011f1958->IsThreatWithinLimits(mobj3, snd2, (Vec3*)&v9, 0.0f))
                continue;
        }
        P3 tB;
        if (FUN_009a7670(mobj3, spellB, ammoA, posVal, v9, DAT_011f426c, acArg, &tB, -1.0f))
        {
            if (snd2)
            {
                float r = ComputeProjectileFlightTime(ammoA, posVal, v9, *acArg, 0.0f);
                if (!DAT_011f1958->IsThreatWithinLimits(mobj3, snd2, (Vec3*)&v9, r))
                    continue;
            }
            a1->FUN_0099b8b0((Vec3*)&v9, 0);
            return true;
        }
    }
    return false;
}
}  // namespace fnv_0099b5a0

namespace fnv_0099b8e0 {
struct QPoint
{
    float x, y, z;
    QPoint();
    QPoint operator-(const QPoint& rhs) const;
};

struct QWorldLoc
{
    QPoint& GetPoint();
};

struct QTarget
{
    unsigned char type;
    char pad1[7];
    QWorldLoc loc;
};

struct QRef
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
    virtual QPoint* GetPos();
};

struct QWeapon
{
    float GetRange();
};
struct QCombatInfo
{
    float GetMinRange(QPoint* out);
    float GetMaxRange(QPoint* out);
};
struct QProcess
{
    QWeapon* GetLoadedForm();
    QCombatInfo* GetCombatInfo();
};

struct QCombatCtrl
{
    QRef* GetActor();
    QWeapon* GetLoadedForm();
    QCombatInfo* GetCombatInfo();
    QRef* GetTarget();
    float GetCoverOffset();
    float GetCoverHeight();
    bool IsFlanking();
};

struct QSetting
{
    float* Get();
};
struct QLock
{
    void Signal();
};
struct QClock
{
    unsigned int GetTime();
};
struct QLockable
{
    void Lock();
    void Unlock();
};
struct QMgr
{
    QLockable* GetLockable();
};
struct QTimer
{
    float GetValue();
};
struct QCoverMgr
{
    void Update();
};

struct QStamp
{
    int v;
    QStamp(float f);
    static float Now();
};

struct QSearchFlags
{
    bool a, b, c, d, e, f;
    QSearchFlags();
};

struct QLocElem
{
    char pad0[0x52];
    char state;
    int GetKey();
    unsigned int GetTimeStamp();
};

struct QLocSlot
{
    void Set(QLocElem* e);
    bool IsValid();
};

struct QLocArray
{
    void* vtbl;
    void* data;
    int size;
    int capacity;
    void Clear(bool freeStorage);
    unsigned int GetSize();
    QLocElem* GetAt(unsigned int index);
};

struct QOut
{
    QPoint pos;
    QPoint dest;
    float radius;
    QStamp stamp;
    QLocArray locs;
    int key;
    int result;
    bool useCover;
};

struct QState
{
    char b0;
    char b1;
    char valid;
    char b3;
    int type;
    QPoint pos;
    QLocSlot slot;
    char pad18[0x50];
    int key;
    unsigned int timeStamp;
    QSearchFlags flags;
    void SetDirty(int);
};

struct QBuilder
{
    int data[0x3c];
    QBuilder();
    ~QBuilder();
    void SetOrigin(void* src);
    void SetFirst(QPoint* p);
    void SetTarget(QPoint* p);
    void SetMinDist(float f);
    void SetMaxDist(float f);
    void SetMaxCount(int n);
    void SetFlagA(bool b);
    void SetFlagB(bool b);
    void SetFlagC(bool b);
    void SetHeight(float f);
    void SetOffset(float f);
    void SetFlank(bool b);
    void SetFlagD(bool b);
};

struct QOrigin
{
    int data[0xa];
    QOrigin(QPoint* pos, QRef* actor);
    ~QOrigin();
};

void FUN_009a9180(QCombatCtrl* ctrl, int a, float* minDist, float* maxDist, float* limit);
float FUN_0040ebd0(float a, float b);
int FindNearbyTriangles(QBuilder* b, QLocArray* arr);

extern QLock DAT_011f1a61;
extern QSetting DAT_011ce3f0;
extern QSetting DAT_011ced34;
extern QSetting DAT_011cf8d4;
extern QSetting DAT_011cf6cc;
extern QClock DAT_011f6394;
extern QMgr* DAT_011f1958;
extern const float DAT_010231a0;
extern const float DAT_01018bfc;
extern const float DAT_01022958;
extern const float DAT_01017a3c;
extern const double DAT_01011590;
extern const double DAT_01017b70;
extern const double DAT_01021928;

struct FUN_0099b8e0_cls
{
    char pad0[0x84];
    QPoint coverPos;
    char pad90[8];
    QTimer timer;
    char pad9c[0x28];
    QTarget* target;
    char padc8[0xfc];
    QCombatCtrl* ctrl;
    char pad1c8[0x34];
    QCoverMgr coverMgr;

    bool FindPathCandidate(void* slot, int a4, QSearchFlags* flags, QPoint* pos, int key, int key2, int type,
                           QRef* actor, QRef* target, float minDist, float maxDist, int* result, float* score,
                           bool flank);
    float GetTargetDist();
    bool FUN_0099b8e0(int a1, QOut* out, QState* st, int a4, int type);
};

// @fnv 0x0099b8e0
bool FUN_0099b8e0_cls::FUN_0099b8e0(int a1, QOut* out, QState* st, int a4, int aiSearchType)
{
    DAT_011f1a61.Signal();
    float kMinHeight = DAT_010231a0;
    float dist7 = DAT_01018bfc;
    const int fMax2 = 200;
    QRef* self2 = ctrl->GetActor();
    QRef* target = ctrl->GetTarget();
    if (!target)
    {
        return false;
    }
    float f = 0.0f;
    float fMin3 = DAT_010231a0;
    float range5 = DAT_01018bfc;
    float cap3 = DAT_01018bfc;
    FUN_009a9180(ctrl, a1, &f, &range5, &cap3);
    range5 *= *DAT_011ce3f0.Get();
    range5 = FUN_0040ebd0(range5, cap3);
    bool flag = false;
    bool flagB = false;
    bool flagC = false;
    bool flank = false;
    switch (aiSearchType)
    {
    case 12:
        fMin3 = *DAT_011ced34.Get();
        dist7 = *DAT_011cf8d4.Get();
        range5 = DAT_01022958;
        flagB = true;
        flagC = true;
        flank = true;
        break;
    case 10:
        range5 = DAT_01022958;
        flank = true;
        break;
    case 4:
        flank = true;
        flag = true;
        break;
    case 5:
        dist7 = DAT_01017a3c;
        range5 = DAT_01022958;
        flank = true;
        flagB = true;
        flagC = true;
        break;
    case 2:
        dist7 = ctrl->GetLoadedForm()->GetRange();
        break;
    }
    int aUres = 0;
    float score5 = 0.0f;
    if (st->key)
    {
        out->key = st->key;
        out->result = 0;
        if (aiSearchType == st->type)
        {
            float half = fMin3 / DAT_01011590;
            if (FindPathCandidate(&st->slot, a4, &st->flags, &st->pos, st->key, st->key, aiSearchType, self2, target,
                                  half, range5, &aUres, &score5, flank))
            {
                st->SetDirty(0);
                DAT_011f1a61.Signal();
                return true;
            }
            out->result = aUres;
        }
        else
        {
            out->result = 15;
        }
    }
    else
    {
        out->key = 0;
    }
    QPoint pos2;
    if (this->target && (this->target->type == 1 || this->target->type == 2))
    {
        pos2 = this->target->loc.GetPoint();
        dist7 = GetTargetDist();
    }
    else
    {
        pos2 = *self2->GetPos();
    }
    QBuilder builder2;
    QOrigin origin(&pos2, self2);
    builder2.SetOrigin(&origin);
    if (aiSearchType == 5)
    {
        QPoint lo3;
        QPoint maxPt;
        float _lo = ctrl->GetCombatInfo()->GetMinRange(&lo3);
        float hiA3 = ctrl->GetCombatInfo()->GetMaxRange(&maxPt);
        out->pos = lo3;
        QPoint dir = maxPt - lo3;
        builder2.SetTarget(&dir);
    }
    else
    {
        out->useCover = timer.GetValue() < *DAT_011cf6cc.Get();
        if (out->useCover)
        {
            out->pos = coverPos;
        }
        else
        {
            out->pos = *target->GetPos();
        }
    }
    builder2.SetFirst(&out->pos);
    builder2.SetMinDist(kMinHeight);
    builder2.SetMaxDist(dist7);
    builder2.SetMaxCount(fMax2);
    builder2.SetFlagA(flag);
    builder2.SetFlagB(flagB);
    builder2.SetFlagC(flagC);
    builder2.SetHeight(ctrl->GetCoverHeight());
    builder2.SetOffset(ctrl->GetCoverOffset());
    builder2.SetFlank(ctrl->IsFlanking());
    builder2.SetFlagD(flank);
    st->type = aiSearchType;
    st->pos = out->pos;
    out->stamp = QStamp::Now();
    out->dest = pos2;
    out->radius = dist7;
    out->locs.Clear(false);
    if (FindNearbyTriangles(&builder2, &out->locs))
    {
        DAT_011f1958->GetLockable()->Lock();
        for (unsigned int i = 0; i < out->locs.GetSize(); i++)
        {
            QLocElem* elem = out->locs.GetAt(i);
            int _resC = 0;
            float score8 = 0.0f;
            int id = elem->GetKey();
            if (id != st->key)
            {
                unsigned int ts = elem->GetTimeStamp();
                if (ts)
                {
                    if ((DAT_011f6394.GetTime() - ts) / DAT_01017b70 < DAT_01021928)
                    {
                        elem->state = 1;
                        continue;
                    }
                }
                QSearchFlags flags;
                if (FindPathCandidate(elem, a4, &flags, &st->pos, id, 0, aiSearchType, self2, target, fMin3, range5,
                                      &_resC, &score8, flank))
                {
                    elem->state = 19;
                    st->slot.Set(elem);
                    st->key = id;
                    st->timeStamp = ts;
                    st->flags = flags;
                    st->valid = st->slot.IsValid();
                    st->SetDirty(0);
                    coverMgr.Update();
                    DAT_011f1a61.Signal();
                    return true;
                }
                elem->state = _resC;
            }
            else
            {
                elem->state = aUres;
            }
        }
        DAT_011f1958->GetLockable()->Unlock();
    }
    DAT_011f1a61.Signal();
    return false;
}
}  // namespace fnv_0099b8e0

struct Pos9f48
{
    float x, y, z;
    float w;
    float FUN_00527a40(const Pos9f48& kOther);
};

struct Tile9f48
{
    bool FUN_00998980();
};

struct Process9f48
{
    Tile9f48* FUN_00586150();
};

struct Actor9f48
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual bool IsAlive();
    virtual void W065();
    virtual void W066();
    virtual void W067();
    virtual void W068();
    virtual void W069();
    virtual void W070();
    virtual void W071();
    virtual void W072();
    virtual void W073();
    virtual void W074();
    virtual void W075();
    virtual void W076();
    virtual void W077();
    virtual void W078();
    virtual void W079();
    virtual void W080();
    virtual void W081();
    virtual void W082();
    virtual void W083();
    virtual void W084();
    virtual void W085();
    virtual void W086();
    virtual void W087();
    virtual void W088();
    virtual void W089();
    virtual void W090();
    virtual void W091();
    virtual void W092();
    virtual void W093();
    virtual void W094();
    virtual void W095();
    virtual void W096();
    virtual void W097();
    virtual void W098();
    virtual void W099();
    virtual void W100();
    virtual void W101();
    virtual void W102();
    virtual void W103();
    virtual void W104();
    virtual void W105();
    virtual void W106();
    virtual void W107();
    virtual void W108();
    virtual void W109();
    virtual void W110();
    virtual void W111();
    virtual void W112();
    virtual void W113();
    virtual void W114();
    virtual void W115();
    virtual void W116();
    virtual void W117();
    virtual void W118();
    virtual void W119();
    virtual void W120();
    virtual void W121();
    virtual void W122();
    virtual void W123();
    virtual void W124();
    virtual void W125();
    virtual void W126();
    virtual void W127();
    virtual void W128();
    virtual void W129();
    virtual void W130();
    virtual void W131();
    virtual void W132();
    virtual void W133();
    virtual void W134();
    virtual void W135();
    virtual void W136();
    virtual void W137();
    virtual void W138();
    virtual void W139();
    virtual void W140();
    virtual void W141();
    virtual void W142();
    virtual void W143();
    virtual void W144();
    virtual void W145();
    virtual void W146();
    virtual void W147();
    virtual void W148();
    virtual void W149();
    virtual void W150();
    virtual void W151();
    virtual void W152();
    virtual void W153();
    virtual void W154();
    virtual void W155();
    virtual void W156();
    virtual void W157();
    virtual void W158();
    virtual void W159();
    virtual void W160();
    virtual void W161();
    virtual void W162();
    virtual void W163();
    virtual void W164();
    virtual void W165();
    virtual void W166();
    virtual void W167();
    virtual void W168();
    virtual void W169();
    virtual void W170();
    virtual void W171();
    virtual void W172();
    virtual void W173();
    virtual void W174();
    virtual void W175();
    virtual void W176();
    virtual void W177();
    virtual void W178();
    virtual void W179();
    virtual void W180();
    virtual void W181();
    virtual void W182();
    virtual void W183();
    virtual void W184();
    virtual void W185();
    virtual void W186();
    virtual void W187();
    virtual void W188();
    virtual void W189();
    virtual void W190();
    virtual void W191();
    virtual void W192();
    virtual void W193();
    virtual void W194();
    virtual void W195();
    virtual void W196();
    virtual void W197();
    virtual void W198();
    virtual void W199();
    virtual void W200();
    virtual void W201();
    virtual void W202();
    virtual void W203();
    virtual void W204();
    virtual void W205();
    virtual void W206();
    virtual void W207();
    virtual void W208();
    virtual void W209();
    virtual void W210();
    virtual void W211();
    virtual void W212();
    virtual void W213();
    virtual void W214();
    virtual void W215();
    virtual void W216();
    virtual void W217();
    virtual void W218();
    virtual void W219();
    virtual void W220();
    virtual void W221();
    virtual void W222();
    virtual void W223();
    virtual void W224();
    virtual void W225();
    virtual void W226();
    virtual void W227();
    virtual void W228();
    virtual void W229();
    virtual void W230();
    virtual void W231();
    virtual void W232();
    virtual void W233();
    virtual void W234();
    virtual void W235();
    virtual void W236();
    virtual void W237();
    virtual void W238();
    virtual void W239();
    virtual void W240();
    virtual void W241();
    virtual void W242();
    virtual void W243();
    virtual void W244();
    virtual void W245();
    virtual void W246();
    virtual void W247();
    virtual void W248();
    virtual void W249();
    virtual void W250();
    virtual void W251();
    virtual void W252();
    virtual void W253();
    virtual void W254();
    virtual void W255();
    virtual void W256();
    virtual void W257();
    virtual void W258();
    virtual void W259();
    virtual void W260();
    virtual void W261();
    virtual void W262();
    virtual void W263();
    virtual void W264();
    virtual void W265();
    virtual Process9f48* GetProcess();
    bool IsTargetIn360View(void* pkTarget);
    int FUN_00575650(Pos9f48* pkPosition);
    float FUN_008be1b0();
};

struct Group9f48
{
    bool FUN_00986a80(Actor9f48* pkMember);
    unsigned int FUN_00990890();
    Actor9f48* GetIntAt(unsigned int uiIndex);
};

struct Controller9f48
{
    Group9f48* FUN_004fb070();
    void* FUN_004030b0();
    Actor9f48* GetFieldBC();
};

struct Request9f48
{
    char m_acPad[0x10];
    Actor9f48* m_pkTarget;
    void FUN_00997400(Actor9f48* pkTarget);
    void FUN_00819a50(float fImpulseRadiusSquared);
};

class GameSettingCollection;
template <class T> class SettingT
{
  public:
    float* FUN_00403e20();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting430;

struct Planner9f48
{
    char m_acPad[0x1c4];
    Controller9f48* m_pkController;
    bool FUN_009a02a0(Pos9f48* pkPosition, int iA, int iB);
    bool TryAssignAllyTarget(Request9f48* pkRequest, int iUnused);
};

// @fnv 0x0099f480
bool Planner9f48::TryAssignAllyTarget(Request9f48* pkRequest, int iUnused)
{
    Group9f48* pkGroupList = m_pkController->FUN_004fb070();
    if (pkRequest->m_pkTarget && pkRequest->m_pkTarget->IsAlive())
    {
        Actor9f48* pkTarget = pkRequest->m_pkTarget;
        if (pkGroupList->FUN_00986a80(pkTarget))
        {
            Process9f48* pkProcess = pkTarget->GetProcess();
            if (pkProcess && pkProcess->FUN_00586150()->FUN_00998980())
                return true;
            else if (pkTarget->IsTargetIn360View(m_pkController->FUN_004030b0()))
                return true;
        }
    }
    Actor9f48* pkOwner = m_pkController->GetFieldBC();
    Pos9f48 kOwnerPos;
    pkOwner->FUN_00575650(&kOwnerPos);
    Actor9f48* pkAlly = 0;
    float fClosest = 67108864.0f;
    unsigned int ItemUpdateArray = pkGroupList->FUN_00990890();
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        Actor9f48* pkMember = pkGroupList->GetIntAt(i);
        if (pkMember == pkOwner)
            continue;
        bool bUsable = false;
        Process9f48* pkOtherProcess = pkMember->GetProcess();
        if (pkOtherProcess && pkOtherProcess->FUN_00586150()->FUN_00998980())
            bUsable = true;
        else if (pkMember->IsTargetIn360View(m_pkController->FUN_004030b0()))
            bUsable = true;
        if (!bUsable)
            continue;
        Pos9f48 kPos;
        pkMember->FUN_00575650(&kPos);
        float fDistance = kPos.FUN_00527a40(kOwnerPos);
        if (fDistance >= fClosest)
            continue;
        if (!FUN_009a02a0(&kPos, 1, 0))
            continue;
        pkAlly = pkMember;
        fClosest = fDistance;
    }
    if (pkAlly)
    {
        pkRequest->FUN_00997400(pkAlly);
        pkRequest->FUN_00819a50(pkAlly->FUN_008be1b0() + pkOwner->FUN_008be1b0() +
                                *originalRuntimeFloatSetting430.FUN_00403e20());
        return true;
    }
    return false;
}

namespace CombatFind {

struct CombatPoint3
{
    float x, y, z;
};

struct CombatSpot;

struct CombatCell
{
    bool FUN_00439090(void* apKey);
    bool FUN_004390c0(void* apKey);
};

struct CombatPos
{
    float x, y, z, w;
    CombatPos();
    CombatCell* FUN_006815c0();
};

struct CombatRef
{
    virtual void r000();
    virtual void r001();
    virtual void r002();
    virtual void r003();
    virtual void r004();
    virtual void r005();
    virtual void r006();
    virtual void r007();
    virtual void r008();
    virtual void r009();
    virtual void r00a();
    virtual void r00b();
    virtual void r00c();
    virtual void r00d();
    virtual void r00e();
    virtual void r00f();
    virtual void r010();
    virtual void r011();
    virtual void r012();
    virtual void r013();
    virtual void r014();
    virtual void r015();
    virtual void r016();
    virtual void r017();
    virtual void r018();
    virtual void r019();
    virtual void r01a();
    virtual void r01b();
    virtual void r01c();
    virtual void r01d();
    virtual void r01e();
    virtual void r01f();
    virtual void r020();
    virtual void r021();
    virtual void r022();
    virtual void r023();
    virtual void r024();
    virtual void r025();
    virtual void r026();
    virtual void r027();
    virtual void r028();
    virtual void r029();
    virtual void r02a();
    virtual void r02b();
    virtual void r02c();
    virtual void r02d();
    virtual void r02e();
    virtual void r02f();
    virtual void r030();
    virtual void r031();
    virtual void r032();
    virtual void r033();
    virtual void r034();
    virtual void r035();
    virtual void r036();
    virtual void r037();
    virtual void r038();
    virtual void r039();
    virtual void r03a();
    virtual void r03b();
    virtual void r03c();
    virtual void r03d();
    virtual void r03e();
    virtual void r03f();
    virtual bool IsActor();
    virtual void r041();
    virtual void r042();
    virtual void r043();
    virtual void r044();
    virtual void r045();
    virtual void r046();
    virtual void r047();
    virtual void r048();
    virtual void r049();
    virtual void r04a();
    virtual void r04b();
    virtual void r04c();
    virtual void r04d();
    virtual void r04e();
    virtual void r04f();
    virtual void r050();
    virtual void r051();
    virtual void r052();
    virtual void r053();
    virtual void r054();
    virtual void r055();
    virtual void r056();
    virtual void r057();
    virtual void r058();
    virtual void r059();
    virtual void r05a();
    virtual void r05b();
    virtual void r05c();
    virtual void r05d();
    virtual void r05e();
    virtual void r05f();
    virtual void r060();
    virtual void r061();
    virtual void r062();
    virtual void r063();
    virtual void r064();
    virtual void r065();
    virtual void r066();
    virtual void r067();
    virtual void r068();
    virtual void r069();
    virtual void r06a();
    virtual void r06b();
    virtual void r06c();
    virtual void r06d();
    virtual void r06e();
    virtual void r06f();
    virtual void r070();
    virtual void r071();
    virtual void r072();
    virtual void r073();
    virtual void r074();
    virtual void r075();
    virtual void r076();
    virtual void r077();
    virtual void r078();
    virtual void r079();
    virtual void r07a();
    virtual void r07b();
    virtual void r07c();
    virtual CombatPoint3* GetPos();
    float FUN_008be1b0();
    float FUN_008be420();
    float FUN_00571600();
    void* FUN_00575ca0();
    CombatPos FUN_00575650();
};

struct CombatSpot
{
    CombatSpot();
    void FUN_00600ab0(int aiType);
    void FUN_00819a50(float afRadius);
    void FUN_009973a0(void* apSource);
    void CopyRefValue();
    void FUN_00997400(CombatRef* apRef);
    void AssignV4(CombatPos* apPos);
    void SetFlags(int aiMode, int aiFlag);
    CombatPos* FUN_006815c0();
    CombatCell* FUN_0097b940();
    int CallReferencedFunction();
    void FUN_0099b520(void* apCell);
    int iData[8];
};

struct CombatSearch
{
    CombatSearch();
    ~CombatSearch();
    void FUN_00997480(void* apSource);
    char pad00[0x68];
    int iCount;
    int iData[3];
};

struct CombatTimed
{
    int FUN_00825c00();
};

struct CombatTyped
{
    int iValue;
    int iType;
};

struct CombatTargetInfo
{
    bool bInvalid;
    char pad01[3];
    CombatRef* pRef;
    CombatPos kPos;
    float fRadius;
};

struct CombatSlot
{
    CombatRef* pRef;
};

struct CombatPathing
{
    bool GetDetectedTargetLocation(CombatRef* apTarget, CombatPos* apOut);
    CombatPos* FindBestItem(CombatRef* apActor, int aiRadius, CombatPos* apFrom);
};

struct CombatLocations
{
    int FUN_00980700(int aiType);
    void FUN_00979f70(int aiType);
    float FUN_0097bd00(int aiType);
    void SetEntry(int aiType, CombatSpot* apSpot, float afDistance);
    void FUN_009959c0(int aiType, CombatSearch* apSearch);
};

struct CombatController
{
    CombatRef* GetFieldBC();
    CombatRef* FUN_004030b0();
    CombatPathing* FUN_004fb070();
    CombatLocations* FUN_005e3fc0();
    void* FUN_007031c0();
};

struct CombatTypeInfo
{
    bool bSkipSearch;
    bool bMeasure;
    char pad02[2];
    float fRadius;
};
extern CombatTypeInfo DAT_011a5650[];

struct CombatSetting
{
    float* FUN_00403e20();
};
extern CombatSetting DAT_011cf914;
extern char DAT_011f426c;
extern const float DAT_0108df70;

int __cdecl FUN_005b5e40(const char* apFormat, ...);
float __cdecl FUN_0097acb0(CombatController* apController, CombatPos* apFrom, CombatPos* apTo);

struct CombatStateQ
{
    char pad00[0x18];
    int iTargetCount;
    char pad1c[0x5a];
    char acFlags[0x4e];
    CombatTargetInfo* pTargetInfo;
    char padc8[0x1c];
    CombatTyped* pTyped;
    char pade8[4];
    char kEC[0xa0];
    CombatTimed* pTimed;
    char pad190[0x34];
    CombatController* pController;

    bool FUN_0097ee90();
    bool FUN_0097fd40();
    bool FUN_00461580(unsigned int auiMask);
    CombatSlot* GetActionAtIndex(int aiIndex);
    bool FUN_0099b8e0(void* apPackage, void* apData, CombatSearch* apSearch, CombatSpot* apSpot, int aiType);
    bool SelectAndMoveToPoint(CombatSpot* apSpot, int a2, int a3, float a4, float a5);
    bool FUN_0099d030(void* apData, CombatSearch* apSearch, CombatSpot* apSpot, int aiType, CombatPos* apPos,
                      float afRadius, int a7);
    bool FUN_0099b5a0(CombatSpot* apSpot, char* apFlags, int aiCount);
    bool FUN_0099ebe0(CombatSearch* apSearch, CombatSpot* apSpot, int aiType);
    bool TryAssignAllyTarget(CombatSpot* apSpot, int aiType);
    bool FUN_009a02a0(CombatPos* apPos, int a2, bool abFlag);
    bool FUN_0099ac20(int aiType);
};

// Finds a location for aiType using a CombatSpot and CombatSearch, then stores the result through pLocationsRes.
// @fnv 0x0099ac20
bool CombatStateQ::FUN_0099ac20(int aiType)
{
    CombatRef* pActorOld = pController->GetFieldBC();
    CombatRef* pTarget = pController->FUN_004030b0();
    CombatPathing* pPathingTmp = pController->FUN_004fb070();
    CombatLocations* pLocationsRes = pController->FUN_005e3fc0();
    if (pLocationsRes->FUN_00980700(aiType))
    {
        pLocationsRes->FUN_00979f70(aiType);
        return true;
    }
    else if (pLocationsRes->FUN_0097bd00(aiType) == DAT_0108df70)
    {
        return false;
    }
    bool bFound = false;
    CombatSpot* pFinalSpot = new CombatSpot();
    CombatSearch* pSearch = new CombatSearch();
    pFinalSpot->FUN_00600ab0(aiType);
    pFinalSpot->FUN_00819a50(DAT_011a5650[aiType].fRadius);
    if (pTimed && pTimed->FUN_00825c00() == aiType)
    {
        pFinalSpot->FUN_009973a0(pTimed);
        if (pTyped && pTyped->iType == aiType)
            pSearch->FUN_00997480(pTyped);
        if (!DAT_011a5650[aiType].bSkipSearch)
        {
            pFinalSpot->CopyRefValue();
            bFound = true;
        }
    }
    bool bFlag = false;
    switch (aiType)
    {
    case 10:
    case 12:
    case 15:
        bFlag = true;
    }
    if (!bFound)
    {
        switch (aiType)
        {
        case 0:
        case 1:
            if (pTarget)
            {
                if (FUN_0097ee90())
                {
                    if (!FUN_0097fd40())
                    {
                        pFinalSpot->FUN_00997400(pTarget);
                        bFound = true;
                    }
                }
                else
                {
                    CombatPos kPoint;
                    if (pPathingTmp->GetDetectedTargetLocation(pTarget, &kPoint))
                    {
                        pFinalSpot->AssignV4(&kPoint);
                        bFound = true;
                    }
                }
            }
            break;
        case 2:
        case 4:
        case 5:
            bFound = FUN_0099b8e0(pController->FUN_007031c0(), kEC, pSearch, pFinalSpot, aiType);
            break;
        case 3:
            bFound = SelectAndMoveToPoint(pFinalSpot, 3, 0xf, 128.0f, 128.0f);
            break;
        case 6:
            if (pTargetInfo && !pTargetInfo->bInvalid)
            {
                bFound = FUN_0099d030(kEC, pSearch, pFinalSpot, aiType, (CombatPos*)pTargetInfo->kPos.FUN_006815c0(),
                                      0.0f, 0);
            }
            else if (pController->FUN_004030b0())
            {
                CombatPoint3 kTargetPos = *pController->FUN_004030b0()->GetPos();
                bFound = FUN_0099d030(kEC, pSearch, pFinalSpot, aiType, (CombatPos*)&kTargetPos, 0.0f, 0);
            }
            break;
        case 7:
        case 8:
        case 9:
        case 16:
            if (pTargetInfo && (aiType != 8 || !FUN_00461580(1 << aiType)))
            {
                if (pTargetInfo->pRef)
                {
                    pFinalSpot->FUN_00997400(pTargetInfo->pRef);
                    if (pTargetInfo->pRef->IsActor())
                    {
                        CombatRef* pActor = pTargetInfo->pRef;
                        pFinalSpot->FUN_00819a50(pActor->FUN_008be1b0() + pActorOld->FUN_008be1b0());
                    }
                }
                else
                {
                    pFinalSpot->AssignV4(&pTargetInfo->kPos);
                }
                pFinalSpot->FUN_00819a50(pTargetInfo->fRadius);
                bFound = true;
            }
            break;
        case 11:
            bFound = FUN_0099b5a0(pFinalSpot, acFlags, iTargetCount);
            break;
        case 10:
        case 12:
            bFound = FUN_0099ebe0(pSearch, pFinalSpot, aiType);
            break;
        case 13:
            bFound = TryAssignAllyTarget(pFinalSpot, aiType);
            break;
        case 14:
            pFinalSpot->SetFlags(1, 1);
            bFound = true;
            break;
        case 15: {
            CombatPos* pCover = pController->FUN_004fb070()->FindBestItem(pActorOld, 0x32, pFinalSpot->FUN_006815c0());
            if (pCover)
            {
                pFinalSpot->AssignV4(pCover);
                bFound = true;
            }
            else if (pFinalSpot->FUN_0097b940()->FUN_00439090(&DAT_011f426c))
            {
                bFound = true;
            }
            if (bFound)
                pFinalSpot->SetFlags(2, 1);
            break;
        }
        case 17:
        case 18:
        case 19:
        case 20:
        case 21: {
            CombatSlot* pSlot = GetActionAtIndex(aiType - 0x11);
            if (pSlot && pSlot->pRef)
            {
                pFinalSpot->FUN_00997400(pSlot->pRef);
                pFinalSpot->FUN_00819a50(pSlot->pRef->FUN_00571600() + pActorOld->FUN_008be420() +
                                         *DAT_011cf914.FUN_00403e20());
                pFinalSpot->SetFlags(2, 1);
                bFound = true;
            }
            break;
        }
        default:
            FUN_005b5e40("COMBAT: Invalid combat location type %i passed to CombatState::FindCombatLocation()", aiType);
        }
    }
    if (bFound)
    {
        if (!pFinalSpot->CallReferencedFunction())
            pFinalSpot->FUN_0099b520(pActorOld->FUN_00575ca0());
        CombatPos kSpotPosTmp = *pFinalSpot->FUN_006815c0();
        if (kSpotPosTmp.FUN_006815c0()->FUN_004390c0(&DAT_011f426c) || FUN_009a02a0(&kSpotPosTmp, 1, bFlag))
        {
            float fDistance = 0.0f;
            if (DAT_011a5650[aiType].bMeasure)
            {
                CombatPos kActorPos = pActorOld->FUN_00575650();
                fDistance = FUN_0097acb0(pController, &kActorPos, &kSpotPosTmp);
            }
            pLocationsRes->SetEntry(aiType, pFinalSpot, fDistance);
            if (pSearch->iCount)
                pLocationsRes->FUN_009959c0(aiType, pSearch);
            else
                delete pSearch;
            return true;
        }
    }
    delete pFinalSpot;
    delete pSearch;
    pLocationsRes->SetEntry(aiType, 0, DAT_0108df70);
    return false;
}

}

namespace fnv_0097ee90 {
class GameSettingCollection;

template <class T> class SettingT
{
  public:
    float* Float();
};

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting412;

class CTSHelper
{
  public:
    float GetElapsedTime();
};

struct DummyInner
{
    char pad94[0x94];
    CTSHelper m_kTime;
    bool FUN_0097ee90();
};

// Returns true when m_kTime.GetElapsedTime() is less than the value of originalRuntimeFloatSetting412.
// @fnv 0x0097ee90
bool DummyInner::FUN_0097ee90()
{
    return (double)m_kTime.GetElapsedTime() < *originalRuntimeFloatSetting412.Float();
}
}  // namespace fnv_0097ee90

namespace fnv_0099d030 {
union SETTING_VALUE
{
    float f;
};

class GameSettingCollection;
template <typename T> class SettingT
{
  public:
    SETTING_VALUE* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting401;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting402;

class TESObjectREFR
{
  public:
    int unk00;
};

struct Actor : public TESObjectREFR
{
    float FUN_008be1b0();
};

class ActiveEffect
{
  public:
    float GetFloatAtOffset1C();
};

class FUN_00980070_shell
{
  public:
    unsigned int FUN_00980070();
};

class AlchemyItem : public FUN_00980070_shell
{
  public:
    int FUN_004030b0();
};

class TESAmmoInitCalls : public AlchemyItem
{
  public:
    Actor* GetFieldBC();
};

class CalendarDays
{
  public:
    bool TryUseCoverItem(void* unk68, void* unk14, TESAmmoInitCalls* m, float f, void* unk70, int one, bool unk75);
};

class FUN_009611e0_shell
{
  public:
    int FUN_009611e0();
};

class TESWorldSpace : public FUN_009611e0_shell
{
};
extern TESWorldSpace* BGSSaveLoadGlobalDataWorldspacePtr;

class GlobalObject_0045d260
{
  public:
    bool IsInCombat();
};
extern GlobalObject_0045d260 g_011f1a63;

class NiPoint3;

class Arg0Class
{
  public:
    int unk_00, unk_04, unk_08, unk_0c, unk_10, unk_14, unk_18, unk_1c, unk_20, unk_24, unk_28, unk_2c;
    int unk30;
};

class Arg1Class
{
  public:
    int unk00;
    int unk04;
    int unk08, unk0c, unk10;
    int unk14;
    int unk_18, unk_1c, unk_20, unk_24, unk_28, unk_2c, unk_30, unk_34, unk_38, unk_3c, unk_40, unk_44, unk_48, unk_4c,
        unk_50, unk_54, unk_58, unk_5c, unk_60, unk_64;
    void* unk68;
    int unk6c;
    int unk70;
    char unk74;
    bool unk75;
};

class FUN_0099b8b0_shell
{
  public:
    void FUN_0099b8b0(int, int);
};

class Arg2Class : public FUN_0099b8b0_shell
{
};

class PathingLocation
{
  public:
    PathingLocation(TESObjectREFR* actor);
    PathingLocation(const NiPoint3& pt, TESObjectREFR* actor);
    ~PathingLocation();
    int unk_00, unk_04, unk_08, unk_0c, unk_10, unk_14, unk_18, unk_1c, unk_20, unk_24;
};

class PathingRequest
{
  public:
    void FUN_006e4bf0();
    void SetOrigin(PathingLocation*);
    void SetDestination(PathingLocation*);
    void FUN_006d30e0(int);
    void FUN_006d3100(Arg1Class*);
    void FUN_006d61e0(void*);
    void FUN_00705b10(int);
    void FUN_006d3120();
    int FUN_006377e0();
    int unk_000, unk_004, unk_008, unk_00c, unk_010, unk_014, unk_018, unk_01c;
    int unk_020, unk_024, unk_028, unk_02c, unk_030, unk_034, unk_038, unk_03c;
    int unk_040, unk_044, unk_048, unk_04c, unk_050, unk_054, unk_058, unk_05c;
    int unk_060, unk_064, unk_068, unk_06c, unk_070, unk_074, unk_078, unk_07c;
    int unk_080, unk_084, unk_088, unk_08c, unk_090, unk_094, unk_098, unk_09c;
    int unk_0a0, unk_0a4, unk_0a8, unk_0ac, unk_0b0, unk_0b4, unk_0b8, unk_0bc;
    int unk_0c0, unk_0c4, unk_0c8, unk_0cc, unk_0d0, unk_0d4, unk_0d8, unk_0dc;
    int unk_0e0, unk_0e4, unk_0e8, unk_0ec, unk_0f0, unk_0f4, unk_0f8, unk_0fc;
    int unk_100, unk_104, unk_108;
};

class FUN_006e4a50 : public PathingRequest
{
  public:
    FUN_006e4a50();
    __forceinline ~FUN_006e4a50()
    {
        FUN_006e4bf0();
    }
};

bool FindCombatPosition(PathingRequest*, float, int);

class CombatController
{
  public:
    int unk_000, unk_004, unk_008, unk_00c, unk_010, unk_014, unk_018, unk_01c;
    int unk_020, unk_024, unk_028, unk_02c, unk_030, unk_034, unk_038, unk_03c;
    int unk_040, unk_044, unk_048, unk_04c, unk_050, unk_054, unk_058, unk_05c;
    int unk_060, unk_064, unk_068, unk_06c, unk_070, unk_074, unk_078, unk_07c;
    int unk_080, unk_084, unk_088, unk_08c, unk_090, unk_094, unk_098, unk_09c;
    int unk_0a0, unk_0a4, unk_0a8, unk_0ac, unk_0b0, unk_0b4, unk_0b8, unk_0bc;
    int unk_0c0, unk_0c4, unk_0c8, unk_0cc, unk_0d0, unk_0d4, unk_0d8, unk_0dc;
    int unk_0e0, unk_0e4, unk_0e8, unk_0ec, unk_0f0, unk_0f4, unk_0f8, unk_0fc;
    int unk_100, unk_104, unk_108, unk_10c, unk_110, unk_114, unk_118, unk_11c;
    int unk_120, unk_124, unk_128, unk_12c, unk_130, unk_134, unk_138, unk_13c;
    int unk_140, unk_144, unk_148, unk_14c, unk_150, unk_154, unk_158, unk_15c;
    int unk_160, unk_164, unk_168, unk_16c, unk_170, unk_174, unk_178, unk_17c;
    int unk_180, unk_184, unk_188, unk_18c, unk_190, unk_194, unk_198, unk_19c;
    int unk_1a0, unk_1a4, unk_1a8, unk_1ac, unk_1b0, unk_1b4, unk_1b8, unk_1bc;
    int unk_1c0;
    TESAmmoInitCalls* member_1c4;
    void FUN_0099d310(PathingRequest*);
    bool FUN_0099d030(Arg0Class* a0, Arg1Class* a1, Arg2Class* a2, int a3, const NiPoint3& a4, float a5, void* a6);
};

// Attempts to use a cover item, then builds a PathingRequest and calls FindCombatPosition to locate a combat position for the actor.
// @fnv 0x0099d030
bool CombatController::FUN_0099d030(Arg0Class* a0, Arg1Class* a1, Arg2Class* a2, int a3, const NiPoint3& a4, float a5,
                                    void* a6)
{
    float fTmp = 1024.0f;
    float f2 = 2048.0f;
    int i1_2 = 200;
    Actor* actor = this->member_1c4->GetFieldBC();
    int i4 = this->member_1c4->FUN_004030b0();
    float val4 = (a5 != 0.0) ? a5 : 256.0f;
    if (a3 == 6)
    {
        val4 = originalRuntimeFloatSetting401.Float()->f +
               ((1.0f - ((ActiveEffect*)this->member_1c4->FUN_00980070())->GetFloatAtOffset1C() / 100.0f) *
                (originalRuntimeFloatSetting402.Float()->f - originalRuntimeFloatSetting401.Float()->f));
    }
    a0->unk30 = 0;
    if (a1->unk68 != 0 && a3 == a1->unk04)
    {
        if (((CalendarDays*)BGSSaveLoadGlobalDataWorldspacePtr->FUN_009611e0())
                ->TryUseCoverItem(a1->unk68, &a1->unk14, this->member_1c4, actor->FUN_008be1b0(), &a1->unk70, 1,
                                  a1->unk75))
        {
            return true;
        }
    }
    g_011f1a63.IsInCombat();
    FUN_006e4a50 req2;
    this->FUN_0099d310(&req2);
    PathingLocation loc1(actor);
    req2.SetOrigin(&loc1);
    PathingLocation loc2(a4, actor);
    req2.SetDestination(&loc2);
    req2.FUN_006d30e0((int)a0);
    req2.FUN_006d3100(a1);
    req2.FUN_006d61e0(a6);
    req2.FUN_00705b10(a3);
    bool retVal7 = FindCombatPosition(&req2, val4, 0);
    if (retVal7)
    {
        a2->FUN_0099b8b0((int)req2.FUN_006377e0(), 0);
    }
    req2.FUN_006d3120();
    g_011f1a63.IsInCombat();
    return retVal7;
}
}  // namespace fnv_0099d030

namespace fnv_006d3150 {
struct NiPoint3
{
    float x, y, z;
};
extern NiPoint3 _NiPoint3_ZERO;

struct FUN_006d3200
{
    char pad[0x54];
    FUN_006d3200();
    ~FUN_006d3200();
};

struct FUN_006d3280_s
{
    FUN_006d3280_s* ClearFlags();
};

struct FUN_006d3150
{
    char byte0;
    char byte1;
    char byte2;
    char pad3;
    int dword4;
    NiPoint3 point8;
    FUN_006d3200 member14;
    int dword68;
    int dword6c;
    FUN_006d3280_s member70;

    FUN_006d3150();
};

// Initializes the listed fields, constructs member14, and calls ClearFlags on member70.
// @fnv 0x006d3150
FUN_006d3150::FUN_006d3150()
    : byte0(0), byte1(0), byte2(0), dword4(0), point8(_NiPoint3_ZERO), member14(), dword68(0), dword6c(-1)
{
    member70.ClearFlags();
}
}  // namespace fnv_006d3150

namespace fnv_00997600 {
extern "C" void* __cdecl memset(void*, int, size_t);

const float kFltMax = 3.402823466e+38F;
struct Pt3
{
    float x, y, z;
};
extern Pt3 g_zeroPt3;

struct Setting
{
    float* GetFloat();
};
extern Setting g_set804;
extern Setting g_set7ec;
extern Setting g_setdcc;

float ClampMin(float a, float b);

struct A24
{
    int unk0, unk4, unk8, unkC;
    A24();
    ~A24();
};
struct FloatW
{
    float f;
    FloatW(float v);
};
struct P2
{
    float x, y;
    P2();
    void Set(float v);
};
struct W4
{
    int v;
    W4();
};
struct B3C
{
    int unk[15];
    B3C();
    ~B3C();
};
struct C10
{
    int unk0, unk4, unk8, unkC;
    C10();
    ~C10();
};
struct D10
{
    int unk0, unk4, unk8, unkC;
    D10();
    ~D10();
};
struct E4
{
    int v;
    E4(int a);
    ~E4();
};

struct FUN_00997600
{
    char b00;
    int unk04;
    float f08;
    int unk0C, unk10, unk14, unk18, unk1C, unk20;
    A24 a24;
    int unk34;
    int unk38;
    int unk3C, unk40, unk44, unk48, unk4C, unk50, unk54;
    float f58, f5C, f60, f64, f68;
    int unk6C;
    char b70, b71, b72, b73, b74, b75, b76, b77;
    int unk78;
    int unk7C;
    float f80;
    Pt3 p84;
    int unk90;
    FloatW w94, w98, w9C, wA0, wA4;
    P2 pA8, pB0, pB8;
    W4 wC0;
    int unkC4;
    char bC8, bC9;
    float fCC;
    float fD0, fD4;
    char bD8;
    int unkDC;
    FloatW wE0;
    int unkE4;
    int unkE8;
    B3C bEC;
    B3C b128;
    C10 c164;
    D10 d174;
    W4 w184;
    char b188;
    int unk18C;
    int unk190, unk194, unk198, unk19C, unk1A0;
    int unk1A4, unk1A8;
    P2 arr1AC[2];
    int unk1BC;
    int unk1C0;
    int unk1C4;
    bool b1C8;
    P2 p1CC, p1D4, p1DC, p1E4, p1EC, p1F4, p1FC, p204, p20C, p214, p21C;
    E4 e224;
    int unk228;

    FUN_00997600(int a, int b);
};

// Initializes selected fields, stores a in unk1C4, sets p20C from g_set804, and computes fCC from g_setdcc and g_set7ec.
// @fnv 0x00997600
FUN_00997600::FUN_00997600(int aiUnk, int aiUnk2)
    : b00(0), unk04(0), f08(100.0f), unk34(0), unk38(0), f58(0.0f), f5C(0.0f), f60(0.0f), f64(0.0f), f68(0.0f),
      unk6C(-1), b70(0), b71(0), b72(0), b73(-1), b74(0), b75(0), b76(0), b77(0), unk78(0), unk7C(3), f80(0.0f),
      p84(g_zeroPt3), unk90(0), w94(-kFltMax), w98(-kFltMax), w9C(-kFltMax), wA0(-kFltMax), wA4(-kFltMax), unkC4(0),
      bC8(0), bC9(0), fD0(-1.0f), fD4(-1.0f), bD8(0), unkDC(0), wE0(-kFltMax), unkE4(0), unkE8(0), b188(-1), unk18C(0),
      unk1BC(0), unk1C0(0), unk1C4(aiUnk), b1C8(true), e224(0), unk228(-1)
{
    memset(&unk0C, 0, 0x18);
    memset(&unk3C, 0, 0x1c);
    memset(&unk190, 0, 0x14);
    memset(&unk1A4, 0, 8);
    p20C.Set(ClampMin(0.0f, *g_set804.GetFloat()));
    fCC = ClampMin(*g_setdcc.GetFloat(), *g_set7ec.GetFloat());
}
}  // namespace fnv_00997600

#include <string.h>

struct FUN_0099a2a0_s
{
    int a[3];
    char data[0x18];
    GlobalObject_00869f00 g;
    void FUN_0099a2a0();
};
// Zeroes the data buffer and clears the global object g.
// @fnv 0x0099a2a0
void FUN_0099a2a0_s::FUN_0099a2a0()
{
    memset(data, 0, 0x18);
    g.Clear(false);
}

struct RefCalls_9a2a30
{
    void FUN_00564db0(bool);
};
class BGSLoadFormBuffer;

TESForm* __cdecl LookupFormByID(unsigned int);
struct RefSlot
{
    TESObjectREFR* ref;
};
struct MemberC4
{
    void FUN_009a3220(BGSLoadFormBuffer*);
};
struct Member18C
{
    void ResolveRef(BGSLoadFormBuffer*);
};
float __cdecl FUN_00404010(float, float);
struct HostA
{
    int unk000;
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
    float values[7];
    int unk058;
    int unk05c;
    float maximum;
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
    MemberC4* memberC4;
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
    Member18C* member18C;
    RefSlot* slots[5];
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    Actor* actor;
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
    unsigned int index;
    void SetMode(unsigned int);
    void FUN_009a2a30(BGSLoadFormBuffer*);
};
// Calls buffer handlers, re-resolves stored references, optionally processes index, and updates maximum from values.
// @fnv 0x009a2a30
void HostA::FUN_009a2a30(BGSLoadFormBuffer* buffer)
{
    if (memberC4)
        memberC4->FUN_009a3220(buffer);
    for (unsigned int i = 0; i < 5; i++)
    {
        if (slots[i])
        {
            slots[i]->ref = slots[i]->ref ? dynamic_cast<TESObjectREFR*>(LookupFormByID((unsigned int)slots[i]->ref)) : 0;
            if (slots[i]->ref)
                ((RefCalls_9a2a30*)slots[i]->ref)->FUN_00564db0(true);
        }
    }
    if (member18C)
        member18C->ResolveRef(buffer);
    actor = actor ? dynamic_cast<Actor*>(LookupFormByID((unsigned int)actor)) : 0;
    if (index != -1)
        SetMode(index);
    for (unsigned int j = 0; j < 7; j++)
        maximum = FUN_00404010(maximum, values[j]);
}
