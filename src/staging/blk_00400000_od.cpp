
// src/staging/blk_00400000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

extern int $SG3295;

struct FUN_00401280_Class
{
    int* __thiscall FUN_00401280();
};

// @fnv 0x00401280
int* __thiscall FUN_00401280_Class::FUN_00401280()
{
    return &$SG3295;
}

struct FUN_00401660_Class
{
    unsigned int __thiscall GetField25C();
};

// @fnv 0x00401660
unsigned int __thiscall FUN_00401660_Class::GetField25C()
{
    return *(unsigned int*)((char*)this + 0x25c);
}

struct FUN_004036b0_Class
{
    unsigned int __thiscall FUN_004036b0();
};

// @fnv 0x004036b0
unsigned int __thiscall FUN_004036b0_Class::FUN_004036b0()
{
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0xb8);
}

struct Dummy
{
    void FUN_00404c00();
};

struct FUN_00404b70 : Dummy
{
    void FUN_00404b71();
};

// @fnv 0x00404b70
void FUN_00404b70::FUN_00404b71()
{
    FUN_00404c00();
}

extern "C" void* DAT_01012188;

struct Twin_008d0360
{
    bool GetBooleanValue();
    void FUN_00404c80();
};

// @fnv 0x00404c80
void Twin_008d0360::FUN_00404c80()
{
    *reinterpret_cast<void**>(this) = &DAT_01012188;
    GetBooleanValue();
}

extern "C" void* __cdecl DAT_010121b4;

struct FUN_00405570_struct
{
    void* __thiscall InitFromGlobal(int, char);
};

struct FUN_00404d50_class
{
    void* __thiscall ConstructWithVTable(int a, char b);
};

// @fnv 0x00404d50
void* __thiscall FUN_00404d50_class::ConstructWithVTable(int aiArg, char acArg)
{
    ((FUN_00405570_struct*)this)->InitFromGlobal(aiArg, acArg);
    *(void**)this = &DAT_010121b4;
    return this;
}

struct FUN_00405230_Class
{
    void __thiscall FUN_00405250();
    void __thiscall FUN_00405230();
};

// @fnv 0x00405230
void __thiscall FUN_00405230_Class::FUN_00405230()
{
    FUN_00405250();
}

extern int DAT_01012298;
void __cdecl FUN_004055d0(int, char);

struct FUN_00405570_cls
{
    void __thiscall FUN_004055d0(int, char);
    FUN_00405570_cls* __thiscall InitFromGlobal(int, char);
};

// Calls FUN_004055d0 with the arguments, stores the address of DAT_01012298 into this, and returns this.
// @fnv 0x00405570
FUN_00405570_cls* __thiscall FUN_00405570_cls::InitFromGlobal(int a, char b)
{
    FUN_004055d0(a, b);
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_01012298);
    return this;
}

extern "C" void __cdecl Init(int);
extern int DAT_01012258;

struct FUN_00405600_class
{
    void __thiscall Init(int);
    void* __thiscall FUN_00405600(int param_2);
};

// Calls Init with param_2, stores the address of DAT_01012258 into this, and returns this.
// @fnv 0x00405600
void* __thiscall FUN_00405600_class::FUN_00405600(int param_2)
{
    Init(param_2);
    *(int*)this = (int)&DAT_01012258;
    return this;
}

struct EffectSetting
{
    bool IsFlagSet(unsigned int);
    void FUN_00405e60();
};

// @fnv 0x00405e60
void EffectSetting::FUN_00405e60()
{
    IsFlagSet(0x400000);
}

struct FUN_00407860_class
{
    void FUN_00407860(float value);
};

// @fnv 0x00407860
void FUN_00407860_class::FUN_00407860(float value)
{
    *(float*)((char*)this + 0x90) = value;
}

struct FUN_00407880_Class
{
    void FUN_00407880(float value);
};

// @fnv 0x00407880
void FUN_00407880_Class::FUN_00407880(float value)
{
    *(float*)((char*)this + 0x94) = value;
}

extern "C" void* DAT_01183320;

// @fnv 0x00408a60
void* __cdecl GetEntryByIndex(int index)
{
    return *(void**)((char*)&DAT_01183320 + (index << 4));
}

struct FUN_00409130_Class
{
    int __thiscall FUN_00409130();
};

// @fnv 0x00409130
int __thiscall FUN_00409130_Class::FUN_00409130()
{
    return 0x54494e45;
}

struct FUN_00409700_Class
{
    bool FUN_00409700();
};

// @fnv 0x00409700
bool FUN_00409700_Class::FUN_00409700()
{
    return (((const unsigned char*)this)[0xc0] & 1) ? true : false;
}

struct ContainerItemExtraFileData
{
    void Endian();
};

struct FUN_004098d0_class
{
    void FUN_004098d0();
};

// @fnv 0x004098d0
void FUN_004098d0_class::FUN_004098d0()
{
    ((ContainerItemExtraFileData*)((char*)this + 0x34))->Endian();
}

int __cdecl FinishScriptRunLock(void*);

struct FUN_0040c130_Class
{
    int FUN_0040c130();
};

// @fnv 0x0040c130
int FUN_0040c130_Class::FUN_0040c130()
{
    return FinishScriptRunLock((char*)this + 4);
}

// @fnv 0x0040ca10
int __cdecl GetMinusOne()
{
    int result = -1;
    return result;
}

// @fnv 0x0040ca30
int __cdecl GetSix()
{
    int v = 6;
    return v;
}

// @fnv 0x0040ebd0
float FUN_0040ebd0(float a, float b)
{
    float result;
    if (a < b)
        result = a;
    else
        result = b;
    return result;
}

extern int DAT_010142ac;

struct BE
{
    int* pv;
    int pad;
    int mExtra;
    BE(unsigned char);
};

struct FUN_0040f6b0 : BE
{
    int* pBound;
    FUN_0040f6b0();
};

// Initializes the base with 0x0b, points pv at DAT_010142ac and clears pBound.
// @fnv 0x0040f6b0
FUN_0040f6b0::FUN_0040f6b0() : BE(0x0b)
{
    pv = &DAT_010142ac;
    pBound = 0;
}

int __cdecl InitScriptRunLock(void*);

struct FUN_0040f6e0_class
{
    int __thiscall FUN_0040f6e0();
};

// @fnv 0x0040f6e0
int __thiscall FUN_0040f6e0_class::FUN_0040f6e0()
{
    return InitScriptRunLock((char*)this + 4);
}

struct FUN_00413ff0_class
{
    float f;
    FUN_00413ff0_class* SetFromFloat(const float* p);
};

// @fnv 0x00413ff0
FUN_00413ff0_class* FUN_00413ff0_class::SetFromFloat(const float* apValue)
{
    f = *apValue;
    return this;
}

struct FUN_004181c0_class
{
    void __thiscall SetIndexedValue(int index, int value);
};

// @fnv 0x004181c0
void __thiscall FUN_004181c0_class::SetIndexedValue(int index, int value)
{
    *(int*)((char*)this + 0xec + index * 4) = value;
}

struct BSExtraData;
struct BaseExtraList
{
    BSExtraData* GetExtraData(unsigned char);
    BSExtraData* FUN_00418200();
};
// @fnv 0x00418200
BSExtraData* BaseExtraList::FUN_00418200()
{
    BSExtraData* result = GetExtraData(0x2d);
    return result;
}

namespace fnv_0041af30 {
struct BaseExtraList
{
    void RemoveExtra(unsigned char);
};

struct FUN_0041af30_shell : BaseExtraList
{
    void FUN_0041af30();
};

// @fnv 0x0041af30
void FUN_0041af30_shell::FUN_0041af30()
{
    RemoveExtra(0x3f);
}
}  // namespace fnv_0041af30

struct GlobalObject_0040c150
{
    ~GlobalObject_0040c150();
    GlobalObject_0040c150* __thiscall FUN_004049d0(unsigned int flags);
};
// Runs the destructor and, when flags has bit 0 set, frees the object with operator delete; returns this.
// @fnv 0x004049d0
GlobalObject_0040c150* __thiscall GlobalObject_0040c150::FUN_004049d0(unsigned int flags)
{
    GlobalObject_0040c150::~GlobalObject_0040c150();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_00404da0_class
{
    void __thiscall FUN_00404da0();
    void* __thiscall FUN_00405200(unsigned int flags);
};

// @fnv 0x00405200
void* __thiscall FUN_00404da0_class::FUN_00405200(unsigned int flags)
{
    FUN_00404da0();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl Deallocate(void*);

struct FUN_00405370_Class
{
    void __thiscall FUN_00405370();
    void* __thiscall FUN_004053a0(unsigned int flags);
};

// Calls FUN_00405370, frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x004053a0
void* __thiscall FUN_00405370_Class::FUN_004053a0(unsigned int flags)
{
    FUN_00405370();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl operator delete(void*);
void FUN_00405310();
struct FUN_004053d0_class
{
    void FUN_00405310();
    void* FUN_004053d0(unsigned int flags);
};
// @fnv 0x004053d0
void* FUN_004053d0_class::FUN_004053d0(unsigned int flags)
{
    FUN_00405310();
    if (flags & 1)
        operator delete(this);
    return this;
}

namespace fnv_0040ecd0 {
struct BSExtraData
{
    virtual ~BSExtraData();
    void* __thiscall FUN_0040ecd0(unsigned int flags);
};
// Calls the BSExtraData destructor and, when flags has bit 0 set, frees this; returns this.
// @fnv 0x0040ecd0
void* BSExtraData::FUN_0040ecd0(unsigned int flags)
{
    BSExtraData::~BSExtraData();
    if (flags & 1)
        operator delete(this);
    return this;
}
}  // namespace fnv_0040ecd0

struct FUN_00401270_Class
{
    bool __thiscall FUN_00401270(int, int, int, int, int);
};
// @fnv 0x00401270
bool __thiscall FUN_00401270_Class::FUN_00401270(int a, int b, int c, int d, int e)
{
    return 0;
}

struct FUN_00401290_Class
{
    char __thiscall FUN_00401290(int);
};
// @fnv 0x00401290
char __thiscall FUN_00401290_Class::FUN_00401290(int)
{
    return 1;
}

struct Base5a
{
    virtual ~Base5a();
};
struct FUN_00401ac0 : Base5a
{
    void ClearData();
    ~FUN_00401ac0();
};
// @fnv 0x00401ac0
FUN_00401ac0::~FUN_00401ac0()
{
    ClearData();
}

extern int _gHungerStageCount;
extern int* _gHungerStages;
// Returns the hunger stage value at index if index is within _gHungerStageCount, otherwise 0.
// @fnv 0x004020b0
int GetHungerStage(unsigned int index)
{
    return index >= 0 && index < _gHungerStageCount ? _gHungerStages[index] : 0;
}

extern int _DAT_011c31b0;
extern void* _DAT_011c31b4;
// Returns the element at index from the array at _DAT_011c31b4 if index is within the count _DAT_011c31b0, otherwise returns null.
// @fnv 0x004027e0
void* __cdecl FUN_004027e0(unsigned int index)
{
    return index >= 0 && index < (unsigned int)_DAT_011c31b0 ? ((void**)_DAT_011c31b4)[index] : 0;
}

struct FUN_00402a20_class
{
    void __thiscall FUN_00402a20(unsigned int flags, bool set);
};

// Sets or clears the given flag bits in the byte at offset 0xbc of this object.
// @fnv 0x00402a20
void __thiscall FUN_00402a20_class::FUN_00402a20(unsigned int flags, bool set)
{
    set ? ((unsigned char*)(this))[0xbc] |= flags : ((unsigned char*)(this))[0xbc] &= ~flags;
}

// If the 16-byte slot at index param_1 has a zero second field, stores param_2 there and returns true; otherwise returns false.
// @fnv 0x00403a70
bool __cdecl SetSlotValueIfEmpty(int aiIndex, int aiValue)
{
    bool b = 0;
    if (*(int*)((char*)&DAT_01183320 + aiIndex * 16 + 4) == 0)
    {
        *(int*)((char*)&DAT_01183320 + aiIndex * 16 + 4) = aiValue;
        b = 1;
    }
    return b;
}

void __cdecl _Deallocate(void*);
struct FUN_004055a0_Class
{
    void* __thiscall FUN_004055a0(unsigned int flags);
};
// Calls FUN_00405230 on this, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x004055a0
void* __thiscall FUN_004055a0_Class::FUN_004055a0(unsigned int flags)
{
    ((FUN_00405230_Class*)this)->FUN_00405230();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int DAT_01012238;
struct FUN_004055d0 : public FUN_00405600_class
{
    FUN_004055d0(int, char);
};
// Calls the base constructor with a, installs the vtable from DAT_01012238, and stores b at offset 0x10.
// @fnv 0x004055d0
FUN_004055d0::FUN_004055d0(int a, char b)
{
    FUN_00405600(a);
    *(int**)this = &DAT_01012238;
    *(char*)((char*)this + 0x10) = b;
}

void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
extern "C" void* DAT_01012278;
struct FUN_00405630_s
{
    void* vtbl;
    int count;
    void* data;
    int pad;
    FUN_00405630_s* __thiscall Init(int count);
};
// Sets the vtable, stores count, allocates count*4 zeroed bytes into data and returns this.
// @fnv 0x00405630
FUN_00405630_s* __thiscall FUN_00405630_s::Init(int count)
{
    vtbl = &DAT_01012278;
    this->count = count;
    pad = 0;
    unsigned int size = this->count << 2;
    data = NiMalloc(size);
    memset(data, 0, this->count << 2);
    return this;
}

struct SL
{
    int m1;
    int m2;
    SL();
};
extern int DAT_01012508;
struct FUN_004056a0
{
    int vf;
    SL lst;
    int hostile;
    FUN_004056a0();
};
// Sets the object's vtable pointer to DAT_01012508 and initializes hostile to 0.
// @fnv 0x004056a0
FUN_004056a0::FUN_004056a0()
{
    *(int*)this = (int)&DAT_01012508;
    hostile = 0;
}

namespace fnv_00406db0 {
struct SL
{
    SL();
};
struct FUN_00406db0
{
    const char* f0;
    SL f4;
    FUN_00406db0();
};
// Initializes the object's f0 pointer to the string literal "@n@".
// @fnv 0x00406db0
FUN_00406db0::FUN_00406db0()
{
    f0 = "@n@";
}
}  // namespace fnv_00406db0

struct Flt
{
    operator unsigned int();
};
struct FUN_00408da0_Class
{
    int* __thiscall FUN_00408da0();
};
// Returns the unsigned int conversion of the Flt at offset 4, or a pointer to $SG3295 when that conversion is zero.
// @fnv 0x00408da0
int* __thiscall FUN_00408da0_Class::FUN_00408da0()
{
    return ((Flt*)((char*)this + 4))->operator unsigned int() ? (int*)((Flt*)((char*)this + 4))->operator unsigned int()
                                                              : (int*)&$SG3295;
}

struct Inner0040e230
{
    void __thiscall FUN_0040e230(int, bool);
};
struct Outer00409100
{
    void __thiscall FUN_00409100(bool);
};
// Calls FUN_0040e230 on the inner object at this-0x18 with 1 and the inverse of b.
// @fnv 0x00409100
void __thiscall Outer00409100::FUN_00409100(bool b)
{
    ((Inner0040e230*)((char*)this - 0x18))->FUN_0040e230(1, !b);
}

struct TESSound;
extern TESSound* DAT_011c3538;
extern TESSound* DAT_011c353c;
extern TESSound* DAT_011c3540;
extern TESSound* DAT_011c3544;
extern TESSound* DAT_011c3548;
extern TESSound* DAT_011c354c;
// Returns one of six global TESSound pointers selected by a, or null for any other value.
// @fnv 0x0040dee0
TESSound* __cdecl GetSoundByIndex(int aiIndex)
{
    switch (aiIndex)
    {
    case 0:
        return DAT_011c3538;
    case 1:
        return DAT_011c353c;
    case 2:
        return DAT_011c3540;
    case 3:
        return DAT_011c3544;
    case 4:
        return DAT_011c3548;
    case 5:
        return DAT_011c354c;
    default:
        return 0;
    }
}

struct SettingBase_01012120
{
    float _04;
    const char* _08;
    virtual ~SettingBase_01012120();
    SettingBase_01012120* __thiscall FUN_0040e130(const char* a, float b);
};
extern int vftable_SettingBase_01012120;
// Sets the vtable pointer, stores the string in _08 and the float in _04, then returns this.
// @fnv 0x0040e130
SettingBase_01012120* __thiscall SettingBase_01012120::FUN_0040e130(const char* a, float afValue)
{
    *(void**)this = (void*)&vftable_SettingBase_01012120;
    _08 = a;
    _04 = afValue;
    return this;
}

struct FUN_0040e230_Class
{
    unsigned char bFlags;
    void __thiscall FUN_0040e230(unsigned int flags, bool set);
};

// Sets or clears the given flag bits in the byte at offset 0x40 of this object.
// @fnv 0x0040e230
void __thiscall FUN_0040e230_Class::FUN_0040e230(unsigned int flags, bool set)
{
    set ? ((unsigned char*)this)[0x40] |= flags : ((unsigned char*)this)[0x40] &= ~flags;
}

int __fastcall _FNV_GetFormType(void*);
struct Holder0040e9f0
{
    void* form;
    void* val;
    void* __thiscall GetValueIfFormType42();
};
// Returns val when form is set and _FNV_GetFormType(form) equals 0x2a, otherwise returns 0.
// @fnv 0x0040e9f0
void* __thiscall Holder0040e9f0::GetValueIfFormType42()
{
    if (form)
    {
        if (_FNV_GetFormType(form) == 0x2a)
            return val;
    }
    return 0;
}

struct Interface
{
    static void __cdecl PrintDebugMessage();
};
struct RecursiveSpinLock
{
    unsigned int* pCount;
    unsigned int count;
    void __thiscall Unlock();
};
// @fnv 0x0040fba0
void __thiscall RecursiveSpinLock::Unlock()
{
    Interface::PrintDebugMessage();
    --count;
    if (count == 0)
        pCount = 0;
}

struct FUN_00413f60_Data
{
    int v[9];
};
struct FUN_00413f60_Holder
{
    char pad[0x1C];
    FUN_00413f60_Data data;
    FUN_00413f60_Data* __thiscall CopyData(FUN_00413f60_Data* dst);
};
// Copies the holder's data into dst and returns dst.
// @fnv 0x00413f60
FUN_00413f60_Data* __thiscall FUN_00413f60_Holder::CopyData(FUN_00413f60_Data* pDest)
{
    *pDest = data;
    return pDest;
}

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned char*, EndianSizeTag<0>);
void __cdecl BSEndian(unsigned char*, EndianSizeTag<10>);
struct FUN_004141e0_class
{
    void __thiscall FUN_004141e0();
};
// @fnv 0x004141e0
void __thiscall FUN_004141e0_class::FUN_004141e0()
{
    BSEndian((unsigned char*)this, EndianSizeTag<0>());
    BSEndian((unsigned char*)this + 4, EndianSizeTag<10>());
}

extern int DAT_010151c0;
struct FUN_0041fcd0 : BE
{
    FUN_0041fcd0();
};
// @fnv 0x0041fcd0
FUN_0041fcd0::FUN_0041fcd0() : BE(0x6f)
{
    *(int**)this = &DAT_010151c0;
}

struct ScriptS
{
    void* GetHeader();
};

struct BGSDehydrationStage : ScriptS
{
    static BGSDehydrationStage** __cdecl AllocateStageArray(unsigned int count);
};

extern int _DAT_011c3180;
extern BGSDehydrationStage** _DAT_011c3184;

// Inserts apNewStage into the global stage array ordered by header value, reallocating the array and updating the global count and pointer.
// @fnv 0x004016a0
void FUN_004016a0(BGSDehydrationStage* apNewStage)
{
    unsigned char newCount;
    BGSDehydrationStage** newStages5;
    unsigned int destinationVal;
    bool insertedB;
    unsigned int index;
    BGSDehydrationStage** oldStages;

    newCount = (unsigned char)(_DAT_011c3180 + 1);
    newStages5 = BGSDehydrationStage::AllocateStageArray(newCount);
    destinationVal = 0;
    insertedB = false;

    for (index = 0; index < (unsigned int)_DAT_011c3180; ++index)
    {
        if (*(unsigned int*)apNewStage->GetHeader() > *(unsigned int*)_DAT_011c3184[index]->GetHeader() && !insertedB)
        {
            newStages5[destinationVal] = apNewStage;
            ++destinationVal;
            insertedB = true;
        }

        newStages5[destinationVal] = _DAT_011c3184[index];
        ++destinationVal;
    }

    if (!insertedB)
    {
        newStages5[destinationVal] = apNewStage;
        ++destinationVal;
    }

    oldStages = _DAT_011c3184;
    _Deallocate(oldStages);
    _DAT_011c3180 = newCount;
    _DAT_011c3184 = newStages5;
}

struct ListX
{
    int m1;
    ~ListX();
};
struct FUN_0040a1c0_Class
{
    int m0;
    ListX m1;
    ~FUN_0040a1c0_Class();
};
// @fnv 0x0040a1c0
FUN_0040a1c0_Class::~FUN_0040a1c0_Class()
{}

namespace fnv_00411ea0 {
int DAT_01014458;
struct BSExtraData
{
    virtual ~BSExtraData();
};
struct FUN_00411ea0 : BSExtraData
{
    ~FUN_00411ea0();
};
// @fnv 0x00411ea0
FUN_00411ea0::~FUN_00411ea0()
{}
}  // namespace fnv_00411ea0

struct BaseExtraList_0041af50
{
    void __thiscall RemoveExtra(unsigned char);
    void __thiscall FUN_0041af50();
};

// @fnv 0x0041af50
void __thiscall BaseExtraList_0041af50::FUN_0041af50()
{
    RemoveExtra(0xd);
}

// FUN_00408b50 : a one-line function - globalvalue
extern int g_value_00408b50;
// @fnv 0x00408b50
int FUN_00408b50()
{
    return g_value_00408b50;
}

// @fnv 0x0040df90
int __cdecl FUN_0040df90()
{
    return 0;
}

extern int DAT_01012238;
void __cdecl FUN_00aa10f0(void* p);

struct C405250Node
{
    C405250Node* next;
    void* payload;
};
struct FUN_00405310
{
    virtual ~FUN_00405310();
};
struct FUN_00405250 : public FUN_00405310
{
    unsigned int count;
    C405250Node** buckets;
    int reserved;
    unsigned char ownsData;
    virtual ~FUN_00405250();
};
// @fnv 0x00405250
FUN_00405250::~FUN_00405250()
{
    if (ownsData)
    {
        for (unsigned int uiIndex = 0; uiIndex < count; ++uiIndex)
        {
            C405250Node* node = buckets[uiIndex];
            while (node != 0)
            {
                C405250Node* current = node;
                node = node->next;
                FUN_00aa10f0(current->payload);
            }
        }
    }
}

struct Setting405c
{
    int FUN_00810fd0();
    bool HasFlag2();
    int FUN_00586150();
    bool FUN_00403e60(unsigned int uiFlag);
};

struct Item405c
{
    Setting405c* FUN_00825c00();
    int FUN_0084e3a0();
    int FUN_004044d0();
    int FUN_00404390();
};

struct ListNode405c
{
    Item405c* m_pkItem;
    ListNode405c* m_pkNext;
    Item405c** FUN_006815c0();
    ListNode405c* FUN_00726070();
};

struct ListBase405c
{
    void* m_pvVtbl;
};

struct EffectList405c : public ListBase405c, public ListNode405c
{
    float FUN_00405c00(int iArchetype, int m_eRange, int m_eAssociatedActorValue);
};

// @fnv 0x00405c00
float EffectList405c::FUN_00405c00(int iArchetype, int m_eRange, int m_eAssociatedActorValue)
{
    float fTotal = 0.0f;
    EffectList405c* pkList = this;
    while (pkList)
    {
        Item405c* pkItem = *pkList->FUN_006815c0();
        if (pkItem)
        {
            Setting405c* pkSetting = pkItem->FUN_00825c00();
            if (pkSetting->FUN_00810fd0() == iArchetype &&
                (m_eAssociatedActorValue == 0x4D || !pkSetting->HasFlag2() || pkSetting->FUN_00586150() == m_eAssociatedActorValue) &&
                (m_eRange == 3 || pkItem->FUN_0084e3a0() == m_eRange))
            {
                float m_fElapsedTime =
                    pkItem->FUN_00404390() * (pkItem->FUN_004044d0() > 0 ? pkItem->FUN_004044d0() : 1);
                if (!pkSetting->FUN_00403e60(4))
                    fTotal += m_fElapsedTime;
                else
                    fTotal -= m_fElapsedTime;
            }
        }
        pkList = static_cast<EffectList405c*>(pkList->FUN_00726070());
    }
    return fTotal;
}

class TESForm
{
  public:
    virtual ~TESForm();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
    void SetFormType(ENUM_FORM_ID eType);
};

template <> class BSSimpleList<TESForm*>
{
  public:
    TESForm* m_item;
    BSSimpleList<TESForm*>* m_pkNext;

    void FUN_004019f0();
};

class FUN_00483370
{
  public:
    FUN_00483370();
    virtual ~FUN_00483370();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class FUN_004010b0 : public FUN_00483370
{
  public:
    FUN_004010b0();
    virtual ~FUN_004010b0();

    void FUN_00401b20();

    BSSimpleList<TESForm*> m_kList;
};

// Constructor that initializes m_kList, sets the form type to ENUM_FORM_ID_DEHY_ID, and calls FUN_00401b20.
// @fnv 0x004010b0
FUN_004010b0::FUN_004010b0()
{
    m_kList.FUN_004019f0();
    reinterpret_cast<TESForm*>(this)->SetFormType(ENUM_FORM_ID_DEHY_ID);
    FUN_00401b20();
}

template <class T> class SettingCollection
{
  public:
    virtual ~SettingCollection();
    char path[260];
    void* handle;
};
struct SettingMapNode;
// Representative of the native case-insensitive setting pointer map.
class SettingPointerMap
{
  public:
    virtual ~SettingPointerMap();
    unsigned int hashSize;
    SettingMapNode** hashTable;
    unsigned int count;
    void RemoveAll();
};
// Native SettingCollectionMap<Setting> destructor.
class FUN_00404c00 : public SettingCollection<Setting>
{
  public:
    SettingPointerMap settings;
    virtual ~FUN_00404c00();
};
// Destructor that calls RemoveAll on the settings map.
// @fnv 0x00404c00
FUN_00404c00::~FUN_00404c00()
{
    settings.RemoveAll();
}

namespace fnv_00405310 {
void __fastcall DeleteAllEntries(void* pkMap);

class FUN_00405370
{
  public:
    virtual ~FUN_00405370();
};

class FUN_00405310 : public FUN_00405370
{
  public:
    virtual ~FUN_00405310();
};

// Destructor that calls DeleteAllEntries with this.
// @fnv 0x00405310
FUN_00405310::~FUN_00405310()
{
    DeleteAllEntries(this);
}
}  // namespace fnv_00405310

struct EffectSetting4056
{
    unsigned int FUN_0084e3a0();
};

struct EffectItem4056
{
    EffectSetting4056* FUN_00825c00();
    void FUN_004040b0();
};

void __cdecl FUN_00485910(unsigned int uiType, unsigned int auiFormId);

struct EffectItemNode4056
{
    EffectItem4056* m_item;
    EffectItemNode4056* m_pkNext;

    EffectItem4056*& FUN_006815c0();
    EffectItemNode4056* FUN_00726070();
};

struct EffectItemListBase4056
{
    virtual ~EffectItemListBase4056();
};

struct EffectItemList4056 : public EffectItemListBase4056, public EffectItemNode4056
{
    void FUN_004056d0();
};

// @fnv 0x004056d0
void EffectItemList4056::FUN_004056d0()
{
    EffectItemList4056* pkList = this;
    while (pkList)
    {
        EffectItem4056* pkItem = pkList->FUN_006815c0();
        if (pkItem)
        {
            unsigned int auiFormId = pkItem->FUN_00825c00()->FUN_0084e3a0();
            FUN_00485910(0x44494645, auiFormId);
            pkItem->FUN_004040b0();
        }
        pkList = static_cast<EffectItemList4056*>(pkList->FUN_00726070());
    }
}

struct ItmQ
{
    int GetScriptFromEffectSetting();
    bool FUN_00405e40();
};
struct LstQ
{
    int unk00;
    bool FUN_008256d0();
    ItmQ** FUN_006815c0();
    LstQ* FUN_00726070();
};
struct BasQ
{
    int unk00;
};
struct NodQ : BasQ, LstQ
{
    bool FUN_00405e80(int iType);
};
// Returns true if some node's item has GetScriptFromEffectSetting equal to iType and FUN_00405e40 false; false at once if FUN_008256d0 is true.
// @fnv 0x00405e80
bool NodQ::FUN_00405e80(int iType)
{
    NodQ* pNode_aqd = this;
    if (pNode_aqd->FUN_008256d0())
        return false;
    bool bFound_jw = false;
    while (pNode_aqd && !bFound_jw)
    {
        ItmQ* pItem = *pNode_aqd->FUN_006815c0();
        if (pItem && pItem->GetScriptFromEffectSetting() == iType && !pItem->FUN_00405e40())
            bFound_jw = true;
        pNode_aqd = static_cast<NodQ*>(pNode_aqd->FUN_00726070());
    }
    return bFound_jw;
}

class PathingSolution;

template <class T> class PathingRef
{
  public:
    void Reset(void* p);
};

class FUN_00633c90
{
  public:
    int unk00;
    FUN_00633c90(int flag);
    ~FUN_00633c90();
};

class FUN_0040ec80
{
  public:
    int unk04;
    int unk08;
    FUN_0040ec80(unsigned char flag);
    virtual ~FUN_0040ec80();
};

class FUN_0040ec00 : public FUN_0040ec80
{
  public:
    FUN_00633c90 m_ref;

    FUN_0040ec00();
    virtual ~FUN_0040ec00();
};

// Constructs the base with 2 and m_ref with 0, then calls Reset(0) on m_ref viewed as PathingRef<PathingSolution>.
// @fnv 0x0040ec00
FUN_0040ec00::FUN_0040ec00() : FUN_0040ec80(2), m_ref(0)
{
    reinterpret_cast<PathingRef<PathingSolution>*>(&m_ref)->Reset(0);
}

class TESFormV
{
  public:
    virtual ~TESFormV();
};
class TESObject : public TESFormV
{
};
class TESBoundObject : public TESObject
{
  public:
    int GetFormType() const;
};
class BaseFormComponent
{
  public:
    virtual ~BaseFormComponent();
};
class TESEnchantableForm : public BaseFormComponent
{
};
class TESBipedModelForm : public BaseFormComponent
{
  public:
    virtual ~TESBipedModelForm();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
    bool FUN_0047c850();
};
struct ItemExtraList
{
    bool FUN_00418b10();
};
// Returns false if object or effect is null; otherwise checks object form type, effect flag bits and extra list; true for form type 43.
// @fnv 0x00409720
bool __cdecl FUN_00409720(TESBoundObject* object, ItemExtraList* extra, EffectSetting* effect)
{
    if (!object || !effect)
        return false;
    if (object->GetFormType() == 43)
        return true;
    if (!dynamic_cast<TESEnchantableForm*>(object))
        return false;
    switch (object->GetFormType())
    {
    case 40:
    case 41:
        if (!effect->IsFlagSet(0x20))
            return false;
        if (extra && extra->FUN_00418b10())
            return false;
        break;
    case 24:
    case 26:
        if (!effect->IsFlagSet(0x10))
            return false;
        if (effect->IsFlagSet(0x40000))
            return false;
        if (effect->IsFlagSet(0x80))
            return false;
        if (effect->IsFlagSet(0x100))
            return false;
        if (extra && extra->FUN_00418b10())
            return false;
        {
            TESBipedModelForm* biped = dynamic_cast<TESBipedModelForm*>(object);
            if (!biped)
                return false;
            if (!biped->FUN_0047c850() && effect->IsFlagSet(0x20000))
                return false;
        }
        break;
    }
    return true;
}

// Stores &DAT_01012278 in a field of the map, calls RemoveAll, then calls FUN_00aa10f0 on m_ppkHashTable.
// @fnv 0x00405370
void __thiscall FUN_00405370_Class::FUN_00405370()
{
    reinterpret_cast<NiTPointerMap<const char*, Setting*>*>(this)->m_ppVirtualMethodTable = &DAT_01012278;
    reinterpret_cast<NiTPointerMap<const char*, Setting*>*>(this)->RemoveAll();
    FUN_00aa10f0(reinterpret_cast<NiTPointerMap<const char*, Setting*>*>(this)->m_ppkHashTable);
}

struct StringMapDeletingEntry : FUN_00405230_Class
{
    void* __thiscall FUN_00405400(unsigned int flags);
};
// Calls FUN_00405250, frees this if bit 0 of flags is set, and returns this.
// @fnv 0x00405400
void* StringMapDeletingEntry::FUN_00405400(unsigned int flags)
{
    FUN_00405250();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct AssociatedForm40df
{
    TESForm* __thiscall FUN_005f5f80();
};

struct FUN_00480ad0_shell
{
    bool __thiscall HasFlag(unsigned int);
};

// @fnv 0x0040dfa0
bool __cdecl FUN_0040dfa0(Item405c* timer1, Item405c* timer2)
{
    if (timer1 == 0 || timer2 == 0)
        return false;

    if (timer1->FUN_00825c00()->FUN_00403e60(0x20000) && timer2->FUN_00825c00()->FUN_00403e60(0x20000))
    {
        TESForm* interval1 = reinterpret_cast<AssociatedForm40df*>(timer1->FUN_00825c00())->FUN_005f5f80();
        TESForm* interval2 = reinterpret_cast<AssociatedForm40df*>(timer2->FUN_00825c00())->FUN_005f5f80();

        TESBipedModelForm* result2 = dynamic_cast<TESBipedModelForm*>(interval1);
        TESBipedModelForm* result1 = dynamic_cast<TESBipedModelForm*>(interval2);

        if (result2 != 0 && result1 != 0)
        {
            return reinterpret_cast<FUN_00480ad0_shell*>(result2)->HasFlag(
                reinterpret_cast<unsigned int>(result1));
        }
    }

    if (timer1->FUN_00825c00()->FUN_00403e60(0x10000) && timer2->FUN_00825c00()->FUN_00403e60(0x10000))
        return true;

    return false;
}
