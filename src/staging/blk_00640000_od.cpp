
// src/staging/blk_00640000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_006427a0_Class
{
    void SetValue(float value);
};

// @fnv 0x006427a0
void FUN_006427a0_Class::SetValue(float value)
{
    *(float*)((char*)this + 0x98) = value;
}

struct FUN_00642890_Class
{
    void FUN_00642890();
};

// @fnv 0x00642890
void FUN_00642890_Class::FUN_00642890()
{
    ((char*)this)[0x24] = 0;
}

struct GlobalObject_0040e0b0
{
    float* Float();
};

GlobalObject_0040e0b0 g_011ce00c;

// @fnv 0x00643f70
float ScaleByGlobalFloat(float value)
{
    return value * *reinterpret_cast<float*>(g_011ce00c.Float());
}

struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting289;
extern double DAT_01011588;

// Returns a plus the product of the float setting from originalRuntimeFloatSetting289 and DAT_01011588.
// @fnv 0x00643fa0
float AddScaledSetting(float afValue)
{
    float result = *originalRuntimeFloatSetting289.Float() * DAT_01011588 + afValue;
    return result;
}

namespace fnv_00643fd0 {
struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting289;

// @fnv 0x00643fd0
float __cdecl AddRuntimeFloatSetting(float afValue)
{
    return afValue + *originalRuntimeFloatSetting289.Float();
}
}  // namespace fnv_00643fd0

struct Helper_00644400
{
    void FUN_00644400(int, int);
};

extern int DAT_0104f3e8;

struct FUN_006442b0_class
{
    void* vftable;
    void* FUN_006442b0(int a);
};

// Sets the vftable to DAT_0104f3e8, calls FUN_00644400 with the argument twice, and returns this.
// @fnv 0x006442b0
void* FUN_006442b0_class::FUN_006442b0(int aiValue)
{
    vftable = &DAT_0104f3e8;
    ((Helper_00644400*)this)->FUN_00644400(aiValue, aiValue);
    return this;
}

extern int DAT_0104f3e8;

struct GlobalObject_00869f00
{
    int* p;
    void Clear(bool);
    void ResetPointer();
};

void GlobalObject_00869f00::Clear(bool b)
{
    delete[] p;
    if (b)
        p = 0;
}

// @fnv 0x006442e0
void GlobalObject_00869f00::ResetPointer()
{
    p = &DAT_0104f3e8;
    Clear(true);
}

namespace fnv_00644520 {
struct Setting_S
{
    float* Float();
};

struct GameSettingCollection
{
    float* Float();
};

template <class T> struct SettingT
{
    float* Float();
};

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting509;

// @fnv 0x00644520
float FUN_00644520()
{
    float f = ((Setting_S*)&originalRuntimeFloatSetting509)->Float()[0];
    return f;
}
}  // namespace fnv_00644520

struct FUN_00644790_class
{
    float FUN_00644790();
};

// @fnv 0x00644790
float FUN_00644790_class::FUN_00644790()
{
    return *(float*)((char*)this + 0x80);
}

struct FUN_00645c20_Class
{
    unsigned short GetShortAtOffset1C0();
};

// @fnv 0x00645c20
unsigned short FUN_00645c20_Class::GetShortAtOffset1C0()
{
    return *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0x1c0);
}

struct FUN_00645c80_Class
{
    bool __thiscall IsFlagSet() const;
};

// @fnv 0x00645c80
bool __thiscall FUN_00645c80_Class::IsFlagSet() const
{
    return (*(reinterpret_cast<const unsigned int*>(this) + 75) & 0x200) ? true : false;
}

struct FUN_00645ca0_Class
{
    float GetField14C();
};

// @fnv 0x00645ca0
float FUN_00645ca0_Class::GetField14C()
{
    return *(float*)((char*)this + 0x14c);
}

struct FUN_00645cc0_class
{
    float GetField150Float();
};

// @fnv 0x00645cc0
float FUN_00645cc0_class::GetField150Float()
{
    return *(float*)((char*)this + 0x150);
}

struct FUN_00645ce0_class
{
    float GetField154();
};

// @fnv 0x00645ce0
float FUN_00645ce0_class::GetField154()
{
    return *(float*)((char*)this + 0x154);
}

struct FUN_00647ac0_Class
{
    unsigned char GetByteAt0x62();
};

// @fnv 0x00647ac0
unsigned char FUN_00647ac0_Class::GetByteAt0x62()
{
    return ((unsigned char*)this)[0x62];
}

struct FUN_0064db00_class
{
    int FUN_0064dc30();
    bool FUN_0064db00();
};

// @fnv 0x0064db00
bool FUN_0064db00_class::FUN_0064db00()
{
    return !FUN_0064dc30();
}

struct FUN_0064db50_class
{
    void __thiscall ApplyToCopy(int a, int b);
    void __thiscall FUN_0064db50(int a, int b);
};

// @fnv 0x0064db50
void __thiscall FUN_0064db50_class::FUN_0064db50(int aiArg1, int aiArg2)
{
    ApplyToCopy(aiArg1, aiArg2);
}

struct FUN_0064dbd0_Class
{
    void FUN_0064dda0();
    void FUN_0064dbd0();
};
// @fnv 0x0064dbd0
void FUN_0064dbd0_Class::FUN_0064dbd0()
{
    FUN_0064dda0();
}

struct FUN_0064dc30_class
{
    int __thiscall FUN_0064dc30();
};

// @fnv 0x0064dc30
int __thiscall FUN_0064dc30_class::FUN_0064dc30()
{
    return (*(int*)((char*)this + 0x10) - *(int*)((char*)this + 0x0C)) >> 4;
}

struct FUN_0064de50_class
{
    void InitAndReturn();
    void* FUN_0064de50();
};

// @fnv 0x0064de50
void* FUN_0064de50_class::FUN_0064de50()
{
    InitAndReturn();
    return this;
}

struct CF_0081c630
{
    void Init();
};
void CF_0081c630::Init()
{}

// @fnv 0x0064de70
CF_0081c630* __fastcall InitAndReturn(CF_0081c630* pObject)
{
    pObject->Init();
    return pObject;
}

extern "C" void __cdecl FUN_0064e2d0();

struct FUN_0064de90_class
{
    void __thiscall FUN_0064de90();
};

// @fnv 0x0064de90
void __thiscall FUN_0064de90_class::FUN_0064de90()
{
    ((void(__thiscall*)(void*))FUN_0064e2d0)(this + 8);
}

struct FUN_0064deb0_Class
{
    void Insert(int, int, int, int);
    void ForwardToFUN0064df50(int a, int b, int c, int d);
};
// Calls Insert with the four integer arguments a, b, c and d.
// @fnv 0x0064deb0
void FUN_0064deb0_Class::ForwardToFUN0064df50(int a, int b, int c, int d)
{
    Insert(a, b, c, d);
}

extern "C" void __cdecl FUN_0064e3f0(int, int, int);

struct FUN_0064dee0_Class
{
    void __thiscall ForwardToHelper(int, int);
};

// Calls FUN_0064e3f0 with the two arguments and a pointer to this object's offset 8.
// @fnv 0x0064dee0
void __thiscall FUN_0064dee0_Class::ForwardToHelper(int aiArg1, int aiArg2)
{
    FUN_0064e3f0(aiArg1, aiArg2, (int)this + 8);
}

extern "C" void __cdecl FUN_0064e430(int, int);

struct FUN_0064df30_class
{
    void __thiscall FUN_0064df30(int a);
};

// @fnv 0x0064df30
void __thiscall FUN_0064df30_class::FUN_0064df30(int a)
{
    FUN_0064e430(a, 0);
}

extern "C" void __cdecl FUN_0064e630(void* a, void* b, void* c, void* d);

struct FUN_0064e480_Class
{
    void __thiscall FUN_0064e480(void* a, void* b, void* c);
};

// Calls FUN_0064e630 with the three arguments and a pointer to this object's offset 8.
// @fnv 0x0064e480
void __thiscall FUN_0064e480_Class::FUN_0064e480(void* a, void* b, void* c)
{
    FUN_0064e630(a, b, c, (char*)this + 8);
}

struct FUN_0065e9a0_holder
{
    void FUN_0065e9a0(int* p);
};

// Iterates over the range from a to b in steps of 4 and calls FUN_0065e9a0 on each element through c.
// @fnv 0x0064e600
void FUN_0064e600(int* pBegin, int* pEnd, FUN_0065e9a0_holder* c)
{
    for (; pBegin != pEnd; pBegin += 4)
    {
        c->FUN_0065e9a0(pBegin);
    }
}

extern "C" void __cdecl CopyConstructBlock(void*, void*);

struct FUN_0064e7d0_class
{
    void __thiscall FUN_0064e7d0(void* a, void* b);
};

// @fnv 0x0064e7d0
void __thiscall FUN_0064e7d0_class::FUN_0064e7d0(void* apFirst, void* apSecond)
{
    CopyConstructBlock(apFirst, apSecond);
}

extern "C" void __cdecl FUN_0064e920(int, int, int, int);

// @fnv 0x0064e840
void __cdecl ForwardToHandler(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    FUN_0064e920(aiArg1, aiArg2, aiArg3, aiArg4);
}

struct DecalStub
{
    void FUN_004bc480(int);
    float m_f;
    void FUN_00654700(float f);
};

// Stores f at offset 0x38 of this and calls FUN_004bc480(1).
// @fnv 0x00654700
void DecalStub::FUN_00654700(float afValue)
{
    *(float*)((char*)this + 0x38) = afValue;
    FUN_004bc480(1);
}

struct FUN_00657880_class
{
    bool FUN_00658160(int);
    bool operator==(int other);
};

// @fnv 0x00657880
bool FUN_00657880_class::operator==(int other)
{
    return !FUN_00658160(other);
}

struct FUN_00657be0_class
{
    int a;
    int b;
    void AddToA();
};

// @fnv 0x00657be0
void FUN_00657be0_class::AddToA()
{
    a += b;
}

struct FUN_00658100
{
    void __thiscall Method_00658100();
};
struct FUN_00657fd0
{
    void __thiscall Method_00657fd0();
};
// @fnv 0x00657fd0
void __thiscall FUN_00657fd0::Method_00657fd0()
{
    ((FUN_00658100*)((char*)this + 8))->Method_00658100();
}

extern "C" void __cdecl FUN_00658bd0(int a1, int a2, int a3);

struct FUN_00657ff0_Class
{
    void FUN_00657ff0(int a1, int a2);
};

// Calls FUN_00658bd0 with the two arguments and a pointer to this object's offset 8.
// @fnv 0x00657ff0
void FUN_00657ff0_Class::FUN_00657ff0(int a1, int a2)
{
    FUN_00658bd0(a1, a2, (int)this + 8);
}

extern "C" void __cdecl FUN_00658c10(int a, int b);

struct FUN_00658020_Class
{
    void __thiscall FUN_00658020(int a);
};

// @fnv 0x00658020
void __thiscall FUN_00658020_Class::FUN_00658020(int a)
{
    FUN_00658c10(a, 0);
}

struct FUN_00658130
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void __thiscall Call_00658130();
};

struct FUN_00658040
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_C;
    void __thiscall Call_00658040();
};

// @fnv 0x00658040
void __thiscall FUN_00658040::Call_00658040()
{
    ((FUN_00658130*)((char*)this + 8))->Call_00658130();
}

extern "C" void __cdecl FUN_00658c60(int, int, int);

struct FUN_00658060_Class
{
    void __thiscall FUN_00658060(int a, int b);
};

// Calls FUN_00658c60 with the two arguments and a pointer to this object's offset 8.
// @fnv 0x00658060
void __thiscall FUN_00658060_Class::FUN_00658060(int a, int b)
{
    FUN_00658c60(a, b, (int)this + 8);
}

void __cdecl FUN_00658ca0(int a, int b);

struct FUN_00658090_Class
{
    void __thiscall FUN_00658090(int a);
};

// @fnv 0x00658090
void __thiscall FUN_00658090_Class::FUN_00658090(int a)
{
    FUN_00658ca0(a, 0);
}

struct FUN_00658930_class
{
    unsigned int GetShortAtOffsetA() const;
};

// @fnv 0x00658930
unsigned int FUN_00658930_class::GetShortAtOffsetA() const
{
    return *(const unsigned short*)((const char*)this + 0xa);
}

extern "C" void __cdecl FUN_00659230(int, int);
extern int DAT_01065870;

struct FUN_00658aa0_class
{
    void* vtbl;
    void FUN_00659230(int a, int b);
    FUN_00658aa0_class* __thiscall Initialize(int a, unsigned char b);
};

// Calls FUN_00659230 with the two arguments, sets vtbl to &DAT_01065870, and returns this.
// @fnv 0x00658aa0
FUN_00658aa0_class* __thiscall FUN_00658aa0_class::Initialize(int a, unsigned char b)
{
    FUN_00659230(a, b);
    vtbl = &DAT_01065870;
    return this;
}

extern "C" void* __cdecl NiFreeAlias(void*);

struct NiTStringTemplateMap
{
    int m_auiShapeKeys[1];
    int m_pObject;
};

struct BSFaceGenModelMap
{
    void FUN_00658b80(NiTStringTemplateMap* pStringMap);
};

// If the byte at offset 0x10 of this map is set, frees the object pointer held by the given string map via NiFreeAlias.
// @fnv 0x00658b80
void BSFaceGenModelMap::FUN_00658b80(NiTStringTemplateMap* pStringMap)
{
    if (*(unsigned char*)((char*)this + 0x10))
        NiFreeAlias((void*)pStringMap->m_pObject);
}

struct FUN_00658d30_class
{
    void __thiscall FUN_00658d50();
    void __thiscall FUN_00658d30();
};

// @fnv 0x00658d30
void __thiscall FUN_00658d30_class::FUN_00658d30()
{
    FUN_00658d50();
}

struct FUN_00659170
{
    void FUN_00659190();
    FUN_00659170();
};

// @fnv 0x00659170
FUN_00659170::FUN_00659170()
{
    FUN_00659190();
}

struct FUN_00659210_Class
{
    int __thiscall FUN_00659210(char a, int b);
};

// @fnv 0x00659210
int __thiscall FUN_00659210_Class::FUN_00659210(char a, int b)
{
    return (b << 5) + b + a;
}

struct FUN_006592f0
{
    void __thiscall operator()(void*);
};

// Iterates from a to b in 0x3c-byte steps, invoking the callable c on each element.
// @fnv 0x00659260
void FUN_00659260(void* pBegin, void* pEnd, FUN_006592f0* pCallback)
{
    for (; pBegin != pEnd; pBegin = (char*)pBegin + 0x3c)
        pCallback->operator()(pBegin);
}

struct FUN_00659310_
{
    void __thiscall FUN_00659310(void*);
};

// Iterates from obj to end in 0x88-byte steps, calling FUN_00659310 on each element.
// @fnv 0x00659290
void __cdecl ForEachItem(void* apBegin, void* end, FUN_00659310_* apVisitor)
{
    for (; apBegin != end; apBegin = (char*)apBegin + 0x88)
        apVisitor->FUN_00659310(apBegin);
}

extern int DAT_010658b0;

struct FUN_00659490_cls
{
    void InitArray(int);
};

struct FUN_00659460_cls
{
    int* m;
    FUN_00659460_cls* Construct(int a);
};

// Calls InitArray with a, sets m to point at DAT_010658b0, and returns this.
// @fnv 0x00659460
FUN_00659460_cls* FUN_00659460_cls::Construct(int a)
{
    ((FUN_00659490_cls*)this)->InitArray(a);
    m = &DAT_010658b0;
    return this;
}

extern "C" void* DAT_00fdf07c;

struct FUN_00659540_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void FUN_00659540();
};

// @fnv 0x00659540
void FUN_00659540_class::FUN_00659540()
{
    ((void(__stdcall*)(void*))DAT_00fdf07c)(m_8);
}

struct FUN_0065cc30_class
{
    int __thiscall FUN_0065cc30();
};

// @fnv 0x0065cc30
int __thiscall FUN_0065cc30_class::FUN_0065cc30()
{
    return (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x10) -
            *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xc)) /
           0x38;
}

struct FUN_0065cc50_Class
{
    int FUN_0065cc50();
};

// @fnv 0x0065cc50
int FUN_0065cc50_Class::FUN_0065cc50()
{
    return *(int*)((char*)this + 0x10) - *(int*)((char*)this + 0xc);
}

struct FUN_0065cea0_class
{
    int __thiscall FUN_0065cea0();
};

// @fnv 0x0065cea0
int __thiscall FUN_0065cea0_class::FUN_0065cea0()
{
    return (*(int*)((char*)this + 0x10) - *(int*)((char*)this + 0xc)) / 0x58;
}

struct FUN_0065cf90_class
{
    void FUN_0065db40();
    void* FUN_0065cf90();
};

// @fnv 0x0065cf90
void* FUN_0065cf90_class::FUN_0065cf90()
{
    FUN_0065db40();
    return this;
}

struct FUN_0065cfb0_Class
{
    void __thiscall FUN_0065d6e0();
    void __thiscall FUN_0065cfb0();
};

// @fnv 0x0065cfb0
void __thiscall FUN_0065cfb0_Class::FUN_0065cfb0()
{
    FUN_0065d6e0();
}

struct FUN_0065db40_class
{
    void FUN_0064de50();
    void* FUN_0065db40();
};

// Calls FUN_0064de50, sets the field at offset 4 to 0, and returns this.
// @fnv 0x0065db40
void* FUN_0065db40_class::FUN_0065db40()
{
    FUN_0064de50();
    *(int*)((char*)this + 4) = 0;
    return this;
}

void __cdecl FUN_0065e2d0(int, int, int);

struct FUN_0065db60_class
{
    void __thiscall FUN_0065db60(int a, int b);
};

// Calls FUN_0065e2d0 with the two arguments and a pointer to this object's offset 8.
// @fnv 0x0065db60
void __thiscall FUN_0065db60_class::FUN_0065db60(int aiArg1, int aiArg2)
{
    FUN_0065e2d0(aiArg1, aiArg2, (int)this + 8);
}

struct FUN_0065e020_class
{
    void __thiscall FUN_0065e020();
};

struct FUN_0065db90_class
{
    void __thiscall FUN_0065db90();
};

// @fnv 0x0065db90
void __thiscall FUN_0065db90_class::FUN_0065db90()
{
    ((FUN_0065e020_class*)((char*)this + 8))->FUN_0065e020();
}

extern "C" void __cdecl FUN_0065e310(int, int);

struct FUN_0065dbb0_class
{
    void __thiscall FUN_0065dbb0(int arg);
};

// @fnv 0x0065dbb0
void __thiscall FUN_0065dbb0_class::FUN_0065dbb0(int arg)
{
    FUN_0065e310(arg, 0);
}

extern "C" void __cdecl FUN_0065e360(int, int, int);

struct FUN_0065dbf0_class
{
    void CallWithThisOffset(int a, int b);
};

// @fnv 0x0065dbf0
void FUN_0065dbf0_class::CallWithThisOffset(int aiFirst, int aiSecond)
{
    FUN_0065e360(aiFirst, aiSecond, (int)this + 8);
}

extern "C" void __cdecl FUN_0065e3a0(int, int);

struct FUN_0065dc20_class
{
    void __thiscall FUN_0065dc20(int a);
};

// @fnv 0x0065dc20
void __thiscall FUN_0065dc20_class::FUN_0065dc20(int a)
{
    FUN_0065e3a0(a, 0);
}

extern "C" void __cdecl FUN_0065e3f0(int a, int b, int c);

struct FUN_0065dc60Class
{
    void FUN_0065dc60(int a, int b);
};

// Calls FUN_0065e3f0 with the two arguments and a pointer to this object's offset 8.
// @fnv 0x0065dc60
void FUN_0065dc60Class::FUN_0065dc60(int aiArg1, int aiArg2)
{
    FUN_0065e3f0(aiArg1, aiArg2, (int)this + 8);
}

extern "C" void __cdecl FUN_0065e430(int, int);

struct FUN_0065dd50_Class
{
    void __thiscall FUN_0065dd50(int a);
};

// @fnv 0x0065dd50
void __thiscall FUN_0065dd50_Class::FUN_0065dd50(int a)
{
    FUN_0065e430(a, 0);
}

struct FUN_0065dd70_Class
{
    void __thiscall FUN_0065dd70();
};

extern "C" void __cdecl FUN_0065e0b0(void*);

// @fnv 0x0065dd70
void __thiscall FUN_0065dd70_Class::FUN_0065dd70()
{
    ((void(__thiscall*)(void*))FUN_0065e0b0)((char*)this + 8);
}

extern "C" void __cdecl FUN_0065e4c0(int, int);

struct FUN_0065ddc0_class
{
    void __thiscall FUN_0065ddc0(int a);
};

// @fnv 0x0065ddc0
void __thiscall FUN_0065ddc0_class::FUN_0065ddc0(int a)
{
    FUN_0065e4c0(a, 0);
}

struct FUN_0065dde0_Class
{
    void FUN_0065e0e0();
    void FUN_0065dde0();
};

// @fnv 0x0065dde0
void FUN_0065dde0_Class::FUN_0065dde0()
{
    ((FUN_0065dde0_Class*)((char*)this + 8))->FUN_0065e0e0();
}

extern "C" void __cdecl FUN_0065e510(int, int, int);

struct FUN_0065de00_Class
{
    void FUN_0065de00(int a, int b);
};

// Calls FUN_0065e510 with the two arguments and a pointer to this object's offset 8.
// @fnv 0x0065de00
void FUN_0065de00_Class::FUN_0065de00(int aiArg1, int aiArg2)
{
    FUN_0065e510(aiArg1, aiArg2, (int)this + 8);
}

extern "C" void __cdecl FUN_0065e5a0(int, int, int);

struct FUN_0065de80_Class
{
    void FUN_0065de80(int a, int b);
};

// Calls FUN_0065e5a0 with the two arguments and a pointer to this object's offset 8.
// @fnv 0x0065de80
void FUN_0065de80_Class::FUN_0065de80(int aiArg1, int aiArg2)
{
    FUN_0065e5a0(aiArg1, aiArg2, (int)this + 8);
}

extern "C" void __cdecl FUN_0065e5e0(int, int);

struct FUN_0065deb0_Class
{
    void __thiscall FUN_0065deb0(int arg);
};

// @fnv 0x0065deb0
void __thiscall FUN_0065deb0_Class::FUN_0065deb0(int arg)
{
    FUN_0065e5e0(arg, 0);
}

extern "C" void __cdecl FUN_0065e630(void*, void*, void*);

struct FUN_0065df10_class
{
    void __thiscall FUN_0065df10(void* b, void* c);
};

// @fnv 0x0065df10
void __thiscall FUN_0065df10_class::FUN_0065df10(void* apFirst, void* apSecond)
{
    FUN_0065e630(apFirst, apSecond, (char*)this + 8);
}

void __cdecl FUN_0065e670(int a, int b);

struct FUN_0065df40_class
{
    void __thiscall FUN_0065df40(int a);
};

// @fnv 0x0065df40
void __thiscall FUN_0065df40_class::FUN_0065df40(int a)
{
    FUN_0065e670(a, 0);
}

struct FUN_0065df60_class
{
    void FUN_0065e170();
    void FUN_0065df60();
};

// @fnv 0x0065df60
void FUN_0065df60_class::FUN_0065df60()
{
    ((FUN_0065df60_class*)((char*)this + 8))->FUN_0065e170();
}

extern "C" void __cdecl CallWithByteResult(int, int, int);

struct FUN_0065df80_class
{
    void __thiscall FUN_0065df80(int a, int b);
};

// Calls CallWithByteResult with the two arguments and a pointer to this object's offset 8.
// @fnv 0x0065df80
void __thiscall FUN_0065df80_class::FUN_0065df80(int aiArg1, int aiArg2)
{
    CallWithByteResult(aiArg1, aiArg2, (int)this + 8);
}

struct FUN_0065dfb0_Class
{
    void __thiscall FUN_0065dfb0(int a);
};

extern "C" void __cdecl FUN_0065e700(int a, int b);

// @fnv 0x0065dfb0
void __thiscall FUN_0065dfb0_Class::FUN_0065dfb0(int a)
{
    FUN_0065e700(a, 0);
}

struct FUN_0065dfd0_class
{
    bool __thiscall FUN_0065e1a0(int);
    bool __thiscall FUN_0065dfd0(int);
};
// Returns the logical negation of FUN_0065e1a0(b).
// @fnv 0x0065dfd0
bool __thiscall FUN_0065dfd0_class::FUN_0065dfd0(int b)
{
    return !FUN_0065e1a0(b);
}

struct FUN_0065e000_class
{
    int __thiscall FUN_0065da80(int a, int b);
    int __thiscall FUN_0065e000(int a, int b);
};

// Calls FUN_0065da80 with the two arguments, then returns this.
// @fnv 0x0065e000
int __thiscall FUN_0065e000_class::FUN_0065e000(int a, int b)
{
    FUN_0065da80(a, b);
    return (int)this;
}

struct FUN_0065e9a0
{
    void __thiscall Destroy(void* p);
};

// Iterates from a to b in 0xc-byte steps and calls Destroy on each element through c.
// @fnv 0x0065e820
void FUN_0065e820(void* pBegin, void* pEnd, FUN_0065e9a0* pDestroyer)
{
    for (; pBegin != pEnd; pBegin = (char*)pBegin + 0xc)
        pDestroyer->Destroy(pBegin);
}

struct FUN_0065e9a0_t
{
    void __thiscall FUN_0065e9a0(void*);
};
// Iterates from a to b in 8-byte steps, calling FUN_0065e9a0 on c for each element.
// @fnv 0x0065e850
void __cdecl FUN_0065e850(void* pBegin, void* pEnd, void* pCallback)
{
    for (; pBegin != pEnd; pBegin = (char*)pBegin + 8)
        ((FUN_0065e9a0_t*)pCallback)->FUN_0065e9a0(pBegin);
}

struct FUN_0065ea00_class
{
    void __thiscall FUN_0065ea00(void*);
};

// Iterates over the range from first to last in 0x34-byte steps, calling FUN_0065ea00 on each element via obj.
// @fnv 0x0065e8e0
void __cdecl FUN_0065e8e0(void* first, void* last, FUN_0065ea00_class* obj)
{
    for (; first != last; first = (char*)first + 0x34)
        obj->FUN_0065ea00(first);
}

struct FUN_0065ea60_class
{
    void __thiscall FUN_0065ea60(void*);
};

// Iterates from p to e in 0x58-byte steps, calling FUN_0065ea60 on obj for each element.
// @fnv 0x0065e970
void FUN_0065e970(void* apBegin, void* apEnd, void* apTarget)
{
    for (; apBegin != apEnd; apBegin = (char*)apBegin + 0x58)
        ((FUN_0065ea60_class*)apTarget)->FUN_0065ea60(apBegin);
}

extern "C" void __cdecl FUN_0065eb00(int);

struct FUN_0065e9c0_class
{
    void __thiscall FUN_0065e9c0(int arg);
};

// @fnv 0x0065e9c0
void __thiscall FUN_0065e9c0_class::FUN_0065e9c0(int aiValue)
{
    FUN_0065eb00(aiValue);
}

extern "C" void __cdecl FUN_0065eb10(void*);

struct FUN_0065e9e0_Class
{
    void __thiscall FUN_0065e9e0(void* a);
};

// @fnv 0x0065e9e0
void __thiscall FUN_0065e9e0_Class::FUN_0065e9e0(void* a)
{
    FUN_0065eb10(a);
}

extern "C" void __cdecl FUN_0065eb30(int);

struct FUN_0065ea20_Class
{
    void __thiscall FUN_0065ea20(int a);
};

// @fnv 0x0065ea20
void __thiscall FUN_0065ea20_Class::FUN_0065ea20(int aiValue)
{
    FUN_0065eb30(aiValue);
}

void FUN_0065eb40(int a);

struct FUN_0065ea40_class
{
    void FUN_0065ea40(int a);
};

// @fnv 0x0065ea40
void FUN_0065ea40_class::FUN_0065ea40(int aiValue)
{
    FUN_0065eb40(aiValue);
}

void __cdecl FUN_0065eb50(void* a);

struct FUN_0065ea60_cls
{
    void __thiscall FUN_0065ea60(void* a);
};

// @fnv 0x0065ea60
void __thiscall FUN_0065ea60_cls::FUN_0065ea60(void* a)
{
    FUN_0065eb50(a);
}

struct FUN_0065ee70_class
{
    void __thiscall FUN_0065ee70();
};

struct FUN_0065ee30_class
{
    void __thiscall FUN_0065ee30();
};

// @fnv 0x0065ee30
void __thiscall FUN_0065ee30_class::FUN_0065ee30()
{
    ((FUN_0065ee70_class*)((char*)this + 4))->FUN_0065ee70();
}

extern "C" void __cdecl CallInterfaceWithResult(int, int, int);

struct FUN_0065f2b0_class
{
    void __thiscall FUN_0065f2b0(int a, int b);
};

// Calls CallInterfaceWithResult with the two arguments and a pointer to this object's offset 8.
// @fnv 0x0065f2b0
void __thiscall FUN_0065f2b0_class::FUN_0065f2b0(int aiArg1, int aiArg2)
{
    CallInterfaceWithResult(aiArg1, aiArg2, (int)this + 8);
}

extern "C" void __cdecl FUN_0065f9a0(int, int, int);

struct FUN_0065f400_class
{
    void __thiscall FUN_0065f400(int a, int b);
};

// @fnv 0x0065f400
void __thiscall FUN_0065f400_class::FUN_0065f400(int aiArg1, int aiArg2)
{
    FUN_0065f9a0(aiArg1, aiArg2, (int)this + 8);
}

struct FUN_0065f7c0_Class
{
    void FUN_0065f7c0();
};

struct FUN_0065f580_Class
{
    void FUN_0065f580();
};

// @fnv 0x0065f580
void FUN_0065f580_Class::FUN_0065f580()
{
    ((FUN_0065f7c0_Class*)((char*)this + 8))->FUN_0065f7c0();
}

extern "C" void __cdecl FUN_0065f9e0(int a, int b);

struct FUN_0065f6c0_class
{
    void __thiscall FUN_0065f6c0(int a);
};

// @fnv 0x0065f6c0
void __thiscall FUN_0065f6c0_class::FUN_0065f6c0(int aiValue)
{
    FUN_0065f9e0(aiValue, 0);
}

extern "C" void* __cdecl AllocateChecked(void*, void*);

struct FUN_0065f7a0_Class
{
    void* __thiscall FUN_0065f7a0(void* arg);
};

// @fnv 0x0065f7a0
void* __thiscall FUN_0065f7a0_Class::FUN_0065f7a0(void* arg)
{
    return AllocateChecked(arg, 0);
}

extern "C" void __cdecl FUN_0065fde0(int, int, int, int);

struct FUN_0065f890_class
{
    void __thiscall FUN_0065f890(int a1, int a2, int a3);
};

// @fnv 0x0065f890
void __thiscall FUN_0065f890_class::FUN_0065f890(int aiArg1, int aiArg2, int aiArg3)
{
    FUN_0065fde0(aiArg1, aiArg2, aiArg3, (int)(this + 8));
}

extern "C" void __cdecl FUN_0065fea0(int, int, int, int);

struct FUN_0065f930_Class
{
    void __thiscall FUN_0065f930(int a, int b, int c);
};

// Calls FUN_0065fea0 with the three arguments and a pointer to this object's offset 8.
// @fnv 0x0065f930
void __thiscall FUN_0065f930_Class::FUN_0065f930(int aiArg1, int aiArg2, int aiArg3)
{
    FUN_0065fea0(aiArg1, aiArg2, aiArg3, (int)this + 8);
}

extern "C" void _NiFreeAlias(void*);
extern void* DAT_010658d0;

struct FUN_00658e70_cls : public NiTPointerMap<int, int>
{
    void FUN_00658e70();
};

// @fnv 0x00658e70
void FUN_00658e70_cls::FUN_00658e70()
{
    *reinterpret_cast<void**>(this) = &DAT_010658d0;
    RemoveAll();
    _NiFreeAlias(reinterpret_cast<void*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 8)));
}

struct Flt
{
    operator unsigned int();
};

struct FUN_00b64d60_Class
{
    void __thiscall UpdateQueries();
};

struct FUN_00642860_Class
{
    void FUN_00642860();
};

// Sets the byte at offset 0x24 to 1, then reads a pointer at 0x28 and, if non-null, calls its UpdateQueries method.
// @fnv 0x00642860
void FUN_00642860_Class::FUN_00642860()
{
    *reinterpret_cast<unsigned char*>(this + 0x24) = 1;
    unsigned int p = reinterpret_cast<Flt*>(this + 0x28)->operator unsigned int();
    if (p)
        reinterpret_cast<FUN_00b64d60_Class*>(reinterpret_cast<void*>(p))->UpdateQueries();
}

struct GameSettingCollection
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetFloat(unsigned int index);
};
extern Setting_S originalRuntimeFloatSetting332;
extern Setting_S originalRuntimeFloatSetting333;

// Returns a float setting scaled by collection->GetFloat(0x2d) plus an offset when index is 0x38, otherwise 0.0f.
// @fnv 0x00643ed0
float FUN_00643ed0(GameSettingCollection* collection, int index)
{
    float result = 0.0f;
    if (index == 0x38)
        result = *originalRuntimeFloatSetting332.Float() * collection->GetFloat(0x2d) +
                 *originalRuntimeFloatSetting333.Float();
    return result;
}

namespace fnv_00643f20 {
struct GameSettingCollection
{
    float f;
    float* Float();
};
template <typename T> struct SettingT
{
    float* Float();
};
template <> struct SettingT<GameSettingCollection> : public GameSettingCollection
{
    float* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting287;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting288;
float FUN_00404010(float a, float b);
// Returns FUN_00404010 called with value times the float setting and value minus another float setting.
// @fnv 0x00643f20
float FUN_00643f20(float value)
{
    return FUN_00404010(value * ((GameSettingCollection*)originalRuntimeFloatSetting288.Float())->f,
                        value - ((GameSettingCollection*)originalRuntimeFloatSetting287.Float())->f);
}
}  // namespace fnv_00643f20

struct FUN_00644350_Class
{
    bool IsGreaterThan(int a);
};
// Compares two objects by calling IsGreaterThan on each against the other, returning 1, -1, or 0.
// @fnv 0x00644300
int CompareObjects(int aiLeft, int aiRight)
{
    int x = aiLeft;
    int y = aiRight;
    if (((FUN_00644350_Class*)x)->IsGreaterThan(y))
        return 1;
    else if (((FUN_00644350_Class*)y)->IsGreaterThan(x))
        return -1;
    else
        return 0;
}

void* __cdecl operator new(unsigned int size, void* placement);
struct FUN_00644490_Class
{
    void __thiscall FUN_00644490(char* items, unsigned int count);
};
// @fnv 0x00644490
void __thiscall FUN_00644490_Class::FUN_00644490(char* acBuffer, unsigned int count)
{
    for (unsigned int i = 0; i < count; ++i)
    {
        void* p = operator new(0x10, acBuffer + i * 0x10);
    }
}

struct FUN_006444e0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_C;
    void* __thiscall FUN_006444e0(int a, int b, int c, int d);
};

// Stores the four arguments into the object's fields and returns this.
// @fnv 0x006444e0
void* __thiscall FUN_006444e0_Class::FUN_006444e0(int aiFirst, int aiSecond, int aiThird, int aiFourth)
{
    m_iWordAt00 = aiFirst;
    m_iWordAt04 = aiSecond;
    m_8 = aiThird;
    m_C = aiFourth;
    return this;
}

namespace fnv_00644540 {
struct GameSettingCollection
{
};
template <class T> struct SettingT
{
    float* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting334;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting335;

// Multiplies value by one of two runtime float game settings, choosing the second when flag is set.
// @fnv 0x00644540
float ScaleByGameSetting(float value, float, bool abUseSecondSetting)
{
    float multiplier;
    float result2;
    if (abUseSecondSetting)
        multiplier = *originalRuntimeFloatSetting335.Float();
    else
        multiplier = *originalRuntimeFloatSetting334.Float();
    result2 = value * multiplier;
    return result2;
}
}  // namespace fnv_00644540

GlobalObject_0040e0b0 g_011ce840;
GlobalObject_0040e0b0 g_011cfd8c;

// Converts value to float and returns the sum of g_011ce840's float setting plus g_011cfd8c's float setting multiplied by that value.
// @fnv 0x006463a0
float FUN_006463a0(int value)
{
    float f = (float)value;
    float result =
        *reinterpret_cast<Setting_S*>(&g_011ce840)->Float() + *reinterpret_cast<Setting_S*>(&g_011cfd8c)->Float() * f;
    return result;
}

// Clamps the unsigned int pointed to by p so that it lies between low and high.
// @fnv 0x00647bd0
void __cdecl ClampUInt(unsigned int* puiValue, unsigned int low, unsigned int high)
{
    if (*puiValue > high)
        *puiValue = high;
    else if (*puiValue < low)
        *puiValue = low;
}

struct ActorValueOwner
{
    float GetActorValueFloatByIndex(ActorValue::Index);
};
extern double g_d100;
extern Setting_S g_011d17d0;
extern Setting_S originalRuntimeFloatSetting1216;
// Computes carry weight from actor value 37 divided by g_d100, scaled by a setting and offset by another setting.
// @fnv 0x00649530
float __cdecl FUN_00649530(ActorValueOwner* apOwner)
{
    float a;
    {
        float b;
        a = (float)(apOwner->GetActorValueFloatByIndex((ActorValue::Index)37) / g_d100);
        b = *g_011d17d0.Float() + a * *originalRuntimeFloatSetting1216.Float();
        return b;
    }
}

namespace fnv_00649580 {
struct ActorValueOwner
{
    float GetActorValueFloatByIndex(int);
};
extern double g_d100;
extern Setting_S g_011d1854;
extern Setting_S originalRuntimeFloatSetting1217;
// Reads actor value 44, divides it by g_d100, scales it by a runtime setting and adds another setting's float value, returning the sum.
// @fnv 0x00649580
float __cdecl GetActorValueScaledSetting(ActorValueOwner* apActorValueOwner)
{
    float v;
    float r;
    v = apActorValueOwner->GetActorValueFloatByIndex(44) / g_d100;
    r = *g_011d1854.Float() + v * *originalRuntimeFloatSetting1217.Float();
    return r;
}
}  // namespace fnv_00649580

struct S_0064dac0
{
    int __thiscall FUN_0064dac0(int, int);
};
// Returns the value at this+0x50 plus b times the element at index this+0x60 of the array at this+0x5C, plus the element at index a of that array.
// @fnv 0x0064dac0
int __thiscall S_0064dac0::FUN_0064dac0(int a, int b)
{
    return *(int*)((char*)this + 0x50) + b * *(int*)(*(int*)((char*)this + 0x5C) + *(int*)((char*)this + 0x60) * 4) +
           *(int*)(*(int*)((char*)this + 0x5C) + a * 4);
}

unsigned int __cdecl FUN_00ec7c56(void);
struct FUN_0064db20_Class
{
    void* __thiscall GetEntryAt(unsigned int a);
};
// Bounds-checks index a against the container's count, then returns the pointer to the entry at offset a*16 in the buffer at this+12.
// @fnv 0x0064db20
void* __thiscall FUN_0064db20_Class::GetEntryAt(unsigned int auiIndex)
{
    if (auiIndex >= ((FUN_0064db00_class*)this)->FUN_0064dc30())
        FUN_00ec7c56();
    do
    {
    } while (0);
    return (void*)((auiIndex << 4) + *(unsigned int*)((char*)this + 12));
}

struct Caller
{
    void __thiscall Increment();
};
struct Pair
{
    int a;
    int b;
};
struct Tgt
{
    Pair m;
    int* __thiscall CopyPairAfterCallback(int* p1, int p2);
};
// Saves m into tmp, calls Increment on this, then writes tmp into p1 and returns p1.
// @fnv 0x0064dbf0
int* __thiscall Tgt::CopyPairAfterCallback(int* pOutPair, int aiUnused)
{
    Pair tmp = m;
    ((Caller*)this)->Increment();
    *(Pair*)pOutPair = tmp;
    return pOutPair;
}

struct FUN_0064e2d0_Holder
{
    unsigned int __thiscall FUN_0064e2d0() const;
};
// @fnv 0x0064e2d0
unsigned int __thiscall FUN_0064e2d0_Holder::FUN_0064e2d0() const
{
    unsigned int _Count = 0xfffffff;
    return _Count > 0 ? _Count : 1;
}

struct FUN_0064e300_Class
{
    int __thiscall FUN_0064e300();
};
// Returns 0 when the pointer at offset 0xc is null, otherwise the difference between the values at offsets 0x14 and 0xc shifted right by 4.
// @fnv 0x0064e300
int __thiscall FUN_0064e300_Class::FUN_0064e300()
{
    return !*(int*)((char*)this + 0xc) ? 0 : (*(int*)((char*)this + 0x14) - *(int*)((char*)this + 0xc)) >> 4;
}

extern "C" void __cdecl FUN_0064e550(int a, int b, int c, void* d);

struct FUN_0064e340_class
{
    void* __thiscall FUN_0064e340(int a, int b, int c);
};

// Calls FUN_0064e550 with a, b, c and this+8, then returns a + (b << 4).
// @fnv 0x0064e340
void* __thiscall FUN_0064e340_class::FUN_0064e340(int pBase, int b, int c)
{
    FUN_0064e550(pBase, b, c, (char*)this + 8);
    return (char*)pBase + (b << 4);
}

char __cdecl FUN_0065e750(int*, int*);
void __cdecl FUN_0064e600(int, int, int, char);
extern "C" void __cdecl FUN_0064e3f0(int, int, int);
// @fnv 0x0064e3f0
extern "C" void __cdecl FUN_0064e3f0(int a, int b, int c)
{
    char v = FUN_0065e750(&a, &b);
    FUN_0064e600(a, b, c, v);
}

int __cdecl CallWithFlag(int* p);
void __cdecl FUN_0064e680(int a, int b, int c);
// @fnv 0x0064e4b0
void __cdecl FUN_0064e4b0(int a, int b, int c)
{
    FUN_0064e680(CallWithFlag(&a), CallWithFlag(&b), c);
}

struct FUN_0064e680_S
{
    int m0;
    int m1;
    int m2;
    int m3;
};
// Copies the four-int struct pointed to by c into each struct from a up to b.
// @fnv 0x0064e680
void FUN_0064e680(FUN_0064e680_S* apBegin, FUN_0064e680_S* apEnd, FUN_0064e680_S* apSource)
{
    for (; apBegin != apEnd; apBegin++)
        *apBegin = *apSource;
}

struct FUN_0064e7f0_S
{
    int f0;
    int f4;
    int f8;
    int fC;
};
// Copies the structs in the range [a, b) into the destination starting at c and returns the advanced destination pointer.
// @fnv 0x0064e7f0
FUN_0064e7f0_S* __cdecl CopyStructRange(FUN_0064e7f0_S* apBegin, FUN_0064e7f0_S* apEnd, FUN_0064e7f0_S* apDest)
{
    for (; apBegin != apEnd; ++apDest, ++apBegin)
        *apDest = *apBegin;
    return apDest;
}

struct FUN_0064e980_Block
{
    int m0;
    int m4;
    int m8;
    int mC;
};
// Copies blocks from b down to a into c, stepping backwards, and returns the resulting destination pointer.
// @fnv 0x0064e980
void* __cdecl CopyBlocksBackward(void* apStart, FUN_0064e980_Block* apEnd, FUN_0064e980_Block* apDestEnd)
{
    while (apStart != apEnd)
    {
        apEnd--;
        apDestEnd--;
        *apDestEnd = *apEnd;
    }
    return apDestEnd;
}

namespace fnv_006505d0 {
struct Flt
{
    operator unsigned int();
};
struct FUN_006505d0_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    Flt* m_8;
    unsigned int __thiscall GetFloatValue();
};
// Returns the value of the Flt object pointed to by m_8, or 0 if m_8 is null.
// @fnv 0x006505d0
unsigned int __thiscall FUN_006505d0_class::GetFloatValue()
{
    return m_8 ? (unsigned int)*m_8 : 0;
}
}  // namespace fnv_006505d0

struct BSFaceGenManager
{
    static void* __stdcall GetFaceGenManager(float a1, int a2, int a3);
};
struct Holder00aad6b0
{
    void __thiscall FUN_00aad6b0();
};
// @fnv 0x00652fc0
void __cdecl FUN_00652fc0(float a1, int a2, int a3)
{
    if (a3 != 0 && a2 != 0)
    {
        ((Holder00aad6b0*)((char*)BSFaceGenManager::GetFaceGenManager(a1, a2, a3) + 0x118))->FUN_00aad6b0();
    }
}

struct Class_00658100
{
    unsigned int __thiscall FUN_00658100();
};
// @fnv 0x00658100
unsigned int __thiscall Class_00658100::FUN_00658100()
{
    unsigned int v = 0x4444444;
    return v > 0 ? v : 1;
}

struct Dummy658130
{
    unsigned __thiscall FUN_00658130();
};
// @fnv 0x00658130
unsigned __thiscall Dummy658130::FUN_00658130()
{
    unsigned x = 0x1E1E1E1;
    return x > 0 ? x : 1;
}

unsigned char __cdecl FUN_0065e750(void*, void*);
void __cdecl FUN_00659260(int, int, int, unsigned char);
// Computes a byte from a1 and a2 via FUN_0065e750, then passes a1, a2, a3 and that byte to FUN_00659260.
// @fnv 0x00658bd0
void FUN_00658bd0(int a1, int a2, int a3)
{
    unsigned char tmp = FUN_0065e750(&a1, &a2);
    FUN_00659260(a1, a2, a3, tmp);
}

namespace fnv_00658c60 {
unsigned char __cdecl FUN_0065e750(int*, int*);
void __cdecl ForEachItem(int, int, int, unsigned char);
// Calls FUN_0065e750 on a and b to get a byte, then passes a, b, c and that byte to ForEachItem.
// @fnv 0x00658c60
void FUN_00658c60(int a, int b, int c)
{
    unsigned char d = FUN_0065e750(&a, &b);
    ForEachItem(a, b, c, d);
}
}  // namespace fnv_00658c60

void __cdecl operator delete(void* p);
struct FUN_00658bb0_Class
{
    void __thiscall FUN_00658bb0();
};
struct FUN_00658d00_Class
{
    void* __thiscall FUN_00658d00(unsigned int flags);
};
// Calls FUN_00658bb0 on this, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x00658d00
void* __thiscall FUN_00658d00_Class::FUN_00658d00(unsigned int flags)
{
    reinterpret_cast<FUN_00658bb0_Class*>(this)->FUN_00658bb0();
    if (flags & 1)
        operator delete(this);
    return this;
}

void _Deallocate(void*);
struct FUN_00658ea0_cls
{
    void* __thiscall FUN_00658ea0(unsigned int);
};
// @fnv 0x00658ea0
void* __thiscall FUN_00658ea0_cls::FUN_00658ea0(unsigned int flags)
{
    ((FUN_00658e70_cls*)this)->FUN_00658e70();
    if (flags & 1)
        _Deallocate((void*)this);
    return (void*)this;
}

void __cdecl operator delete(void* p);
struct FUN_00658ed0_Class
{
    void __thiscall FUN_00658e10();
    void* __thiscall FUN_00658ed0(unsigned int flags);
};
// Calls FUN_00658e10, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00658ed0
void* __thiscall FUN_00658ed0_Class::FUN_00658ed0(unsigned int flags)
{
    FUN_00658e10();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_00658f00_Class : public FUN_00658d30_class
{
    FUN_00658f00_Class* __thiscall FUN_00658f00(unsigned int flags);
};

// @fnv 0x00658f00
FUN_00658f00_Class* __thiscall FUN_00658f00_Class::FUN_00658f00(unsigned int flags)
{
    this->FUN_00658d50();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct Pair590
{
    int a;
    int b;
};
struct S_006590c0
{
    void* __thiscall CopyPairTo(void* p, int q);
};
// Copies the two-int pair at this into p, runs FUN_00659170 on this, and returns p.
// @fnv 0x006590c0
void* __thiscall S_006590c0::CopyPairTo(void* apDest, int q)
{
    Pair590 tmp = *(Pair590*)this;
    ((FUN_00659170*)this)->FUN_00659170::FUN_00659170();
    *(Pair590*)apDest = tmp;
    return apDest;
}

struct FUN_006a68b0_Class
{
    void FUN_006a68b0();
};
void __cdecl operator delete(void*);
struct FUN_00659140_Class
{
    void* __thiscall FUN_00659140(unsigned int flags);
};
// Calls FUN_006a68b0 on this, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x00659140
void* __thiscall FUN_00659140_Class::FUN_00659140(unsigned int flags)
{
    ((FUN_006a68b0_Class*)this)->FUN_006a68b0();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern int DAT_010658f0;
struct FUN_00659230
{
    void* vptr;
    void __thiscall InitializeWithGlobal(int a, unsigned char b);
    FUN_00659230(int a, unsigned char b);
};
// Calls InitializeWithGlobal with the two arguments, then sets the vtable pointer to DAT_010658f0.
// @fnv 0x00659230
FUN_00659230::FUN_00659230(int a, unsigned char b)
{
    InitializeWithGlobal(a, b);
    vptr = (void*)&DAT_010658f0;
}

void _Deallocate(void*);
struct S_006592c0
{
    void* FUN_006592c0(unsigned int flags);
};
// @fnv 0x006592c0
void* S_006592c0::FUN_006592c0(unsigned int flags)
{
    ((FUN_00658d30_class*)this)->FUN_00658d30();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int DAT_01065890;
struct FUN_00659330_class
{
    void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_C;
    unsigned char m_10;
    void* __thiscall InitializeWithGlobal(int a, unsigned char b);
};
// Calls Construct on this, then stores a pointer to DAT_01065890 and the byte b into the object's fields.
// @fnv 0x00659330
void* __thiscall FUN_00659330_class::InitializeWithGlobal(int a, unsigned char b)
{
    ((FUN_00659460_cls*)this)->Construct(a);
    m_iWordAt00 = &DAT_01065890;
    m_10 = b;
    return this;
}

struct FUN_00659380_cls
{
    void __thiscall FUN_00659380(int a);
};

// @fnv 0x00659360
void __cdecl FUN_00659360(int a)
{
    ((FUN_00659380_cls*)a)->FUN_00659380(0);
}

struct FUN_006593b0_class
{
    void __thiscall FUN_006593b0(int a);
};
// @fnv 0x00659370
void __cdecl FUN_00659370(int a)
{
    ((FUN_006593b0_class*)a)->FUN_006593b0(0);
}

void __cdecl operator delete(void*);
struct FUN_00659380_class
{
    void __thiscall FUN_006593e0();
    void* __thiscall FUN_00659380(unsigned int flags);
};
// Calls FUN_006593e0, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x00659380
void* __thiscall FUN_00659380_class::FUN_00659380(unsigned int flags)
{
    FUN_006593e0();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_00659440_Class
{
    void __thiscall FUN_00659440();
};
struct FUN_006593b0_Class
{
    void* __thiscall FUN_006593b0(unsigned int flags);
};
// Calls FUN_00659440 on this, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006593b0
void* __thiscall FUN_006593b0_Class::FUN_006593b0(unsigned int flags)
{
    ((FUN_00659440_Class*)this)->FUN_00659440();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct NarrowString
{
    char* p;
    ~NarrowString();
};
struct FaceGenMatrix
{
    ~FaceGenMatrix();
};
struct FUN_006593e0_Class
{
    FaceGenMatrix m_iWordAt00;
    char m_20[28];
    NarrowString m_40;
    ~FUN_006593e0_Class();
};
// @fnv 0x006593e0
FUN_006593e0_Class::~FUN_006593e0_Class()
{}

namespace fnv_00659440 {
template <typename T> struct FaceGenMatrix
{
    ~FaceGenMatrix();
    char data[32];
};
struct FUN_00659440
{
    char pad[8];
    FaceGenMatrix<float> arr[4];
    ~FUN_00659440();
};
// @fnv 0x00659440
FUN_00659440::~FUN_00659440()
{}
}  // namespace fnv_00659440

extern "C" __declspec(dllimport) void* __stdcall CreateSemaphoreA(void*, long, long, const char*);
struct FUN_00659500_Holder
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    FUN_00659500_Holder* __thiscall InitSemaphore(int a, int b);
};
// Stores the two integer arguments and creates a semaphore with them as initial and maximum counts, returning this.
// @fnv 0x00659500
FUN_00659500_Holder* __thiscall FUN_00659500_Holder::InitSemaphore(int aiInitialCount, int aiMaxCount)
{
    m_iWordAt00 = (void*)aiInitialCount;
    m_iWordAt04 = (void*)aiMaxCount;
    m_8 = CreateSemaphoreA(0, (long)m_iWordAt00, (long)m_iWordAt04, 0);
    return this;
}

struct FUN_0065b3e0_Holder
{
    char _pad[16];
    void* m_10;
    void* m_14;
    void* __thiscall GetPointerByFlag(bool);
};
// Returns m_14 when flag is true, otherwise m_10.
// @fnv 0x0065b3e0
void* __thiscall FUN_0065b3e0_Holder::GetPointerByFlag(bool abUseSecond)
{
    return abUseSecond ? m_14 : m_10;
}

unsigned int __cdecl FUN_00ec7c56(void);
struct FUN_0065cc70_Holder
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_C;
    int __thiscall FUN_0065cc70(unsigned int param);
};
// Bounds-checks param against the holder's count, then returns the int stored at offset 0xc plus param.
// @fnv 0x0065cc70
int __thiscall FUN_0065cc70_Holder::FUN_0065cc70(unsigned int uiIndex)
{
    if (uiIndex >= ((FUN_0065cc50_Class*)this)->FUN_0065cc50())
        FUN_00ec7c56();
    do
    {
    } while (0);
    return *(int*)((char*)this + 0xc) + (int)uiIndex;
}

struct TextureBasis
{
    unsigned int FUN_0065cea0();
};
unsigned int __cdecl FUN_00ec7c56();
struct Holder : TextureBasis
{
    int FUN_0065cec0(unsigned int);
};
// @fnv 0x0065cec0
int Holder::FUN_0065cec0(unsigned int auiIndex)
{
    if (auiIndex >= TextureBasis::FUN_0065cea0())
        FUN_00ec7c56();
    do
    {
    } while (0);
    return auiIndex * 0x58 + *(int*)((char*)this + 0xC);
}

struct Pair65cf50
{
    int a;
    int b;
};
struct Holder65cf50
{
    Pair65cf50 data;
    void __thiscall FUN_0065dae0();
    void* __thiscall CopyDataAfterCallback(void* p, int q);
};
// Saves data, calls FUN_0065dae0, then writes the saved pair to p and returns p.
// @fnv 0x0065cf50
void* __thiscall Holder65cf50::CopyDataAfterCallback(void* pDest, int iUnused)
{
    Pair65cf50 tmp = data;
    FUN_0065dae0();
    *(Pair65cf50*)pDest = tmp;
    return pDest;
}

struct FUN_0064df10_helper
{
    void deallocate(void* p, unsigned int n);
};
struct FUN_0065d150_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void __thiscall ClearStorage();
};
// @fnv 0x0065d150
void __thiscall FUN_0065d150_class::ClearStorage()
{
    if (m_iThirdValue)
    {
        ((FUN_0064dee0_Class*)this)->ForwardToHelper((int)m_iThirdValue, (int)m_10);
        ((FUN_0064df10_helper*)((char*)this + 8))->deallocate(m_iThirdValue, (unsigned int)((char*)m_14 - (char*)m_iThirdValue >> 4));
    }
    m_iThirdValue = 0;
    m_10 = 0;
    m_14 = 0;
}

namespace fnv_0065d330 {
struct FUN_0064df10_helper
{
    void __thiscall deallocate(void*, unsigned int);
};
struct FUN_0065d330Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    void __thiscall ClearAndFreeArray();
};
// @fnv 0x0065d330
void __thiscall FUN_0065d330Class::ClearAndFreeArray()
{
    if (m_iThirdValue)
    {
        ((FUN_0065dc60Class*)this)->FUN_0065dc60(m_iThirdValue, m_10);
        ((FUN_0064df10_helper*)((char*)this + 8))->deallocate((void*)m_iThirdValue, (unsigned int)((m_14 - m_iThirdValue) >> 5));
    }
    m_iThirdValue = 0;
    m_10 = 0;
    m_14 = 0;
}
}  // namespace fnv_0065d330

void __cdecl FUN_0065e480(int a1, int a2, void* a3);
struct FUN_0065dd90_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void __thiscall FUN_0065dd90(int a1, int a2);
};
// Forwards the two arguments and the address of m_8 to FUN_0065e480.
// @fnv 0x0065dd90
void __thiscall FUN_0065dd90_Class::FUN_0065dd90(int aiArg1, int aiArg2)
{
    FUN_0065e480(aiArg1, aiArg2, &m_8);
}

struct _Out_0044a170
{
    void __thiscall FUN_0065e000(int, void*);
};
struct FUN_0065ded0_Class
{
    _Out_0044a170* __thiscall FUN_0065ded0(_Out_0044a170* a1, int a2, int a3);
};
// Calls FUN_0065e000 on a1 with a3 and this, then returns a1.
// @fnv 0x0065ded0
_Out_0044a170* __thiscall FUN_0065ded0_Class::FUN_0065ded0(_Out_0044a170* a1, int aiUnused, int aiArg)
{
    a1->FUN_0065e000(aiArg, this);
    return a1;
}

struct FUN_0065e020_Cls
{
    int __thiscall FUN_0065e020();
};
// @fnv 0x0065e020
int __thiscall FUN_0065e020_Cls::FUN_0065e020()
{
    unsigned int val = 0x15555555;
    return val > 0 ? val : 1;
}

struct FUN_0065e050_Holder
{
    int __thiscall FUN_0065e050();
};
// @fnv 0x0065e050
int __thiscall FUN_0065e050_Holder::FUN_0065e050()
{
    unsigned int x = 0x1fffffff;
    return x > 0 ? x : 1;
}

struct FUN_0065e080_S
{
    int __thiscall FUN_0065e080();
};
// @fnv 0x0065e080
int __thiscall FUN_0065e080_S::FUN_0065e080()
{
    unsigned int x = 0x7FFFFFF;
    return x > 0 ? x : 1;
}

struct FUN_0065e0b0_Class
{
    unsigned int FUN_0065e0b0();
};
// @fnv 0x0065e0b0
unsigned int FUN_0065e0b0_Class::FUN_0065e0b0()
{
    unsigned int value = 0x5D1745D;
    return value > 0 ? value : 1;
}

struct FUN_0065e110_Holder
{
    int GetPositiveValue();
};
// @fnv 0x0065e110
int FUN_0065e110_Holder::GetPositiveValue()
{
    unsigned int a = 0x4924924;
    return a > 0 ? a : 1;
}

struct S_0065e140
{
    unsigned int FUN_0065e140();
};
// @fnv 0x0065e140
unsigned int S_0065e140::FUN_0065e140()
{
    unsigned int v = 0x9249249;
    return v > 0 ? v : 1;
}

struct FUN_0065e170_Cls
{
    unsigned __thiscall FUN_0065e170();
};
// @fnv 0x0065e170
unsigned __thiscall FUN_0065e170_Cls::FUN_0065e170()
{
    unsigned int value = 0x2e8ba2e;
    return value > 0 ? value : 1;
}

namespace fnv_0065e2d0 {
unsigned char __cdecl FUN_0065e750(int*, int*);
void __cdecl FUN_0065e820(int, int, int, unsigned char);
// @fnv 0x0065e2d0
void __cdecl FUN_0065e2d0(int aiFirst, int aiSecond, int aiThird)
{
    unsigned char v = FUN_0065e750(&aiFirst, &aiSecond);
    FUN_0065e820(aiFirst, aiSecond, aiThird, v);
}
}  // namespace fnv_0065e2d0

namespace fnv_0065e360 {
bool __cdecl FUN_0065e750(void*, void*);
void __cdecl FUN_0065e850(int, int, int, bool);
// Calls FUN_0065e750 on a and b to get a bool, then passes a, b, c and that bool to FUN_0065e850.
// @fnv 0x0065e360
void __cdecl FUN_0065e360(int aiFirst, int aiSecond, int aiThird)
{
    bool d = FUN_0065e750(&aiFirst, &aiSecond);
    FUN_0065e850(aiFirst, aiSecond, aiThird, d);
}
}  // namespace fnv_0065e360

namespace fnv_0065e3f0 {
bool __cdecl FUN_0065e750(int*, int*);
void __cdecl FUN_0065e880(int, int, int, bool);
// Calls FUN_0065e750 on a and b, then passes a, b, c and the returned bool to FUN_0065e880.
// @fnv 0x0065e3f0
void __cdecl FUN_0065e3f0(int aiValueA, int aiValueB, int aiValueC)
{
    bool tmp = FUN_0065e750(&aiValueA, &aiValueB);
    FUN_0065e880(aiValueA, aiValueB, aiValueC, tmp);
}
}  // namespace fnv_0065e3f0

namespace fnv_0065e480 {
unsigned char __cdecl FUN_0065e750(int* a, int* b);
void __cdecl FUN_0065e8b0(int a, int b, int c, int d);
// @fnv 0x0065e480
void __cdecl FUN_0065e480(int aiFirst, int aiSecond, int aiThird)
{
    unsigned char v;
    v = FUN_0065e750(&aiFirst, &aiSecond);
    FUN_0065e8b0(aiFirst, aiSecond, aiThird, v);
}
}  // namespace fnv_0065e480

unsigned char __cdecl FUN_0065e750(void*, void*);
void __cdecl FUN_0065e8e0(int, int, int, unsigned char);
// Calls FUN_0065e750 on a and b to get a byte, then passes a, b, c and that byte to FUN_0065e8e0.
// @fnv 0x0065e510
void FUN_0065e510(int aiFirst, int aiSecond, int aiThird)
{
    unsigned char v = FUN_0065e750(&aiFirst, &aiSecond);
    FUN_0065e8e0(aiFirst, aiSecond, aiThird, v);
}

unsigned char __cdecl FUN_0065e750(void*, void*);
void __cdecl FUN_0065e910(int, int, int, int);
// Calls FUN_0065e750 on a and b to get a byte, then passes a, b, c and that byte to FUN_0065e910.
// @fnv 0x0065e5a0
void __cdecl FUN_0065e5a0(int aiFirst, int aiSecond, int aiThird)
{
    unsigned char v = FUN_0065e750(&aiFirst, &aiSecond);
    FUN_0065e910(aiFirst, aiSecond, aiThird, v);
}

namespace fnv_0065e630 {
struct DummyTag
{
    char dummy;
};
DummyTag __cdecl FUN_0065e750(void* a, void* b);
void __cdecl FUN_0065e940(void* a, void* b, void* c, int d);
// Calls FUN_0065e750 on the addresses of a and b, then passes its dummy byte as the fourth argument to FUN_0065e940 along with a, b and c.
// @fnv 0x0065e630
void __cdecl FUN_0065e630(void* pFirst, void* pSecond, void* pThird)
{
    FUN_0065e940(pFirst, pSecond, pThird, (unsigned char)FUN_0065e750(&pFirst, &pSecond).dummy);
}
}  // namespace fnv_0065e630

namespace fnv_0065e6c0 {
int __cdecl FUN_0065e750(void*, void*);
void __cdecl FUN_0065e970(int, int, int, int);
// @fnv 0x0065e6c0
void __cdecl CallWithByteResult(int aiValue1, int aiValue2, int aiValue3)
{
    unsigned char c;
    c = FUN_0065e750(&aiValue1, &aiValue2);
    FUN_0065e970(aiValue1, aiValue2, aiValue3, c);
}
}  // namespace fnv_0065e6c0

// Iterates over 0x20-byte entries from a1 up to a2, calling a3->FUN_0065e9c0 on each entry.
// @fnv 0x0065e880
void __cdecl FUN_0065e880(int a1, int a2, FUN_0065e9c0_class* a3)
{
    for (; a1 != a2; a1 += 0x20)
        a3->FUN_0065e9c0(a1);
}

// Iterates over the range from a to b in 0x2c-byte steps, calling c->FUN_0065e9e0 on each element.
// @fnv 0x0065e8b0
void __cdecl FUN_0065e8b0(char* pBegin, char* pEnd, FUN_0065e9e0_Class* c)
{
    for (; pBegin != pEnd; pBegin += 0x2c)
        c->FUN_0065e9e0(pBegin);
}

// Iterates over the range from _First to _Last in steps of 0x38, calling _Dest->FUN_0065ea20 on each element.
// @fnv 0x0065e910
void FUN_0065e910(int _First, int _Last, FUN_0065ea20_Class* _Dest)
{
    for (; _First != _Last; _First += 0x38)
    {
        _Dest->FUN_0065ea20(_First);
    }
}

// @fnv 0x0065e940
void FUN_0065e940(int a, int b, FUN_0065ea40_class* c)
{
    for (; a != b; a += 0x1c)
    {
        c->FUN_0065ea40(a);
    }
}

struct S_0065eb60
{
    void __thiscall FUN_0065eb60(void* p);
};
// @fnv 0x0065ea80
char* __cdecl FUN_0065ea80(char* apSourceBegin, char* apSourceEnd, char* apDest)
{
    for (; apSourceBegin != apSourceEnd; apDest += 0x1c, apSourceBegin += 0x1c)
    {
        ((S_0065eb60*)apDest)->FUN_0065eb60(apSourceBegin);
    }
    return apDest;
}

struct S_0065eb90
{
    void __thiscall FUN_0065eb90(int);
};
// @fnv 0x0065eac0
int FUN_0065eac0(int pBegin, int pEnd, int pDest)
{
    for (; pBegin != pEnd; pDest += 0x58, pBegin += 0x58)
        ((S_0065eb90*)pDest)->FUN_0065eb90(pBegin);
    return pDest;
}

struct FUN_0065ec10_class
{
    void __thiscall FUN_0065ec10(int b);
};

// @fnv 0x0065eb00
void __cdecl FUN_0065eb00(int a)
{
    ((FUN_0065ec10_class*)(void*)a)->FUN_0065ec10(0);
}

struct FUN_0065ec40_class
{
    void FUN_0065ec40(int a);
};
// @fnv 0x0065eb10
void FUN_0065eb10(FUN_0065ec40_class* self, int a)
{
    self->FUN_0065ec40(0);
}

struct FUN_0065ec70_class
{
    void FUN_0065ec70(int a);
};

// @fnv 0x0065eb20
void __cdecl FUN_0065eb20(FUN_0065ec70_class* self)
{
    self->FUN_0065ec70(0);
}

struct FUN_0065ecd0_Class
{
    void FUN_0065ecd0(int a);
};
// @fnv 0x0065eb40
void FUN_0065eb40(int a)
{
    ((FUN_0065ecd0_Class*)a)->FUN_0065ecd0(0);
}

struct FUN_0065ed00_Class
{
    void __thiscall FUN_0065ed00(int a);
};
// @fnv 0x0065eb50
void __cdecl FUN_0065eb50(int a)
{
    ((FUN_0065ed00_Class*)a)->FUN_0065ed00(0);
}

struct Sub_0065eed0
{
    void __thiscall FUN_0065eed0(const Sub_0065eed0*);
};
struct Owner_0065eb60
{
    float m_iWordAt00;
    Sub_0065eed0 m_iWordAt04;
    Owner_0065eb60& __thiscall FUN_0065eb60(const Owner_0065eb60&);
};
// Copies the float member and the nested object from src into this object, then returns *this.
// @fnv 0x0065eb60
Owner_0065eb60& __thiscall Owner_0065eb60::FUN_0065eb60(const Owner_0065eb60& src)
{
    m_iWordAt00 = src.m_iWordAt00;
    m_iWordAt04.FUN_0065eed0(&src.m_iWordAt04);
    return *this;
}

namespace fnv_0065ec10 {
struct FUN_0065ec10_class
{
    void* FUN_0065ed30();
    void* FUN_0065ec10(unsigned int flags);
};
// Calls FUN_0065ed30, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x0065ec10
void* FUN_0065ec10_class::FUN_0065ec10(unsigned int flags)
{
    FUN_0065ed30();
    if (flags & 1)
        operator delete(this);
    return this;
}
}  // namespace fnv_0065ec10

void __cdecl operator delete(void*);
struct FUN_0065eca0_class
{
    void __thiscall FUN_0065edd0();
    void* __thiscall FUN_0065eca0(unsigned int flags);
};
// Calls FUN_0065edd0, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x0065eca0
void* __thiscall FUN_0065eca0_class::FUN_0065eca0(unsigned int flags)
{
    FUN_0065edd0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_0065ecd0_class
{
    void* __thiscall FUN_0065ecd0(unsigned int flags);
};
// Calls FUN_0065ee30 on this, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x0065ecd0
void* __thiscall FUN_0065ecd0_class::FUN_0065ecd0(unsigned int flags)
{
    reinterpret_cast<FUN_0065ee30_class*>(this)->FUN_0065ee30();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl operator delete(void* p);
struct FUN_0065ed00_class
{
    void __thiscall FUN_0065ee50();
    void* __thiscall FUN_0065ed00(unsigned int flags);
};
// Calls FUN_0065ee50, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x0065ed00
void* FUN_0065ed00_class::FUN_0065ed00(unsigned int flags)
{
    FUN_0065ee50();
    if (flags & 1)
        operator delete(this);
    return this;
}

namespace fnv_0065ed70 {
struct S_0065c6a0
{
    ~S_0065c6a0();
};
struct NarrowString
{
    ~NarrowString();
};
struct FUN_0065ed70
{
    ~FUN_0065ed70();
    NarrowString m_pcFileName;
    char m_auiShapeKeys[27];
    S_0065c6a0 m_data;
};
// @fnv 0x0065ed70
FUN_0065ed70::~FUN_0065ed70()
{}
}  // namespace fnv_0065ed70

namespace fnv_0065edd0 {
struct NarrowString
{
    ~NarrowString();
};
struct FUN_0065edd0_t
{
    void FUN_0044a040();
};
struct FUN_0065edd0_class
{
    NarrowString m_idv;
    FUN_0065edd0_t m_obj;
    ~FUN_0065edd0_class();
};
// Destructor that calls FUN_0044a040 on the sub-object at offset 0x20 of this instance.
// @fnv 0x0065edd0
FUN_0065edd0_class::~FUN_0065edd0_class()
{
    ((FUN_0065edd0_t*)((char*)this + 0x20))->FUN_0044a040();
}
}  // namespace fnv_0065edd0

void FUN_0065f060();
void __stdcall FUN_0065ee50_Helper(void*, unsigned int, int, void (*)());
struct FUN_0065ee50_S
{
    char m_auiShapeKeys[16];
    char m_aiIndexedValues[72];
    void FUN_0065ee50();
};
// Calls FUN_0065ee50_Helper on the sub-object at this+16 with 24, 3 and FUN_0065f060.
// @fnv 0x0065ee50
void FUN_0065ee50_S::FUN_0065ee50()
{
    FUN_0065ee50_Helper((void*)((char*)this + 16), 24, 3, FUN_0065f060);
}

struct S_0065f2e0
{
    int _0;
    int _4;
    int _8;
    int m_iThirdValue;
    int _10;
    int m_14;
    int FUN_0065f2e0();
};
// @fnv 0x0065f2e0
int S_0065f2e0::FUN_0065f2e0()
{
    return m_iThirdValue == 0 ? 0 : (m_14 - m_iThirdValue) / 6;
}

struct FUN_0065f4b0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_C;
    int m_10;
    int m_14;
    int FUN_0065f4b0();
};
// Returns 0 when m_C is zero, otherwise returns m_14 minus m_C.
// @fnv 0x0065f4b0
int FUN_0065f4b0_Class::FUN_0065f4b0()
{
    return m_C == 0 ? 0 : m_14 - m_C;
}

namespace fnv_0065f550 {
struct _Out_0044a170
{
    void FUN_0065e000(int, void*);
};
struct FUN_0065f550_Class
{
    char _0[0x10];
    int m_10;
    _Out_0044a170* __thiscall CallWithSelf(_Out_0044a170* p);
};
// Calls p->FUN_0065e000 with m_10 and this, then returns p.
// @fnv 0x0065f550
_Out_0044a170* __thiscall FUN_0065f550_Class::CallWithSelf(_Out_0044a170* pOut)
{
    pOut->FUN_0065e000(m_10, this);
    return pOut;
}
}  // namespace fnv_0065f550

struct S_0065f7c0
{
    unsigned int FUN_0065f7c0();
};
// @fnv 0x0065f7c0
unsigned int S_0065f7c0::FUN_0065f7c0()
{
    unsigned int v = 0x2AAAAAAA;
    return v > 0 ? v : 1;
}

struct FUN_0065f7f0_Class
{
    unsigned int __thiscall FUN_0065f7f0() const;
};
// @fnv 0x0065f7f0
unsigned int __thiscall FUN_0065f7f0_Class::FUN_0065f7f0() const
{
    unsigned int _Count = (unsigned int)-1 / sizeof(char);
    return (0 < _Count ? _Count : 1);
}

namespace fnv_0065f960 {
struct Interface
{
    static void __cdecl PrintDebugMessage(int a, int b, int c, int d);
};
unsigned char __cdecl FUN_0065e750(int* a, int* b);
// @fnv 0x0065f960
void CallInterfaceWithResult(int aiValue1, int aiValue2, int aiValue3, int aiValue4)
{
    unsigned char r = FUN_0065e750(&aiValue1, &aiValue2);
    Interface::PrintDebugMessage(aiValue1, aiValue2, aiValue3, (int)r);
}
}  // namespace fnv_0065f960

unsigned char __cdecl FUN_0065e750(void* a, void* b);
void __cdecl FUN_0065ff00(void* a, void* b, void* c, unsigned char d);
// @fnv 0x0065f9a0
void __cdecl FUN_0065f9a0(void* pFirst, void* pSecond, void* pThird)
{
    unsigned char r = FUN_0065e750(&pFirst, &pSecond);
    FUN_0065ff00(pFirst, pSecond, pThird, r);
}

struct FUN_0065fb10_Class
{
    void __thiscall FUN_0065fb10(const FUN_0065fb10_Class& other);
};
struct FUN_0065fa80_Holder
{
    float m_iWordAt00;
    FUN_0065fb10_Class m_iWordAt04;
    FUN_0065fa80_Holder& __thiscall FUN_0065fa80(const FUN_0065fa80_Holder& other);
};
// @fnv 0x0065fa80
FUN_0065fa80_Holder& __thiscall FUN_0065fa80_Holder::FUN_0065fa80(const FUN_0065fa80_Holder& other)
{
    m_iWordAt00 = other.m_iWordAt00;
    m_iWordAt04.FUN_0065fb10(other.m_iWordAt04);
    return *this;
}

int __cdecl FUN_00ec7ce3(void* a1, unsigned int a2, void* a3, unsigned int a4);
// @fnv 0x0065fe60
char* FUN_0065fe60(char* pBegin, char* pEnd, char* pDest)
{
    char* end;
    {
        int size = pEnd - pBegin;
        end = pDest + size;
        if (size > 0)
            FUN_00ec7ce3(pDest, size, pBegin, size);
    }
    return end;
}

// @fnv 0x0065ff00
void __cdecl FUN_0065ff00(char* _First, char* _Last, FUN_0065e9a0_holder* _Dest)
{
    for (; _First != _Last; _First += 6)
        _Dest->FUN_0065e9a0((int*)_First);
}

extern "C" void __cdecl FUN_00660130(int a, int b, int c, int d, int e, int f);

struct FUN_0065ff30_Class
{
    void __thiscall FUN_0065ff30(int a, int b, int c, int d, int e);
};

// @fnv 0x0065ff30
void __thiscall FUN_0065ff30_Class::FUN_0065ff30(int aiArg1, int aiArg2, int aiArg3, int aiArg4, int aiArg5)
{
    FUN_00660130(aiArg1, aiArg2, aiArg3, aiArg4, aiArg5, (int)(this + 8));
}

struct FUN_0065ff60_class
{
    void __thiscall FUN_0065ff60(int a, int b, int c, int d, int e);
};
extern "C" void __cdecl FUN_00660190(int a, int b, int c, int d, int e, int f);
// Passes the five arguments plus a pointer to this object's offset 8 to FUN_00660190.
// @fnv 0x0065ff60
void __thiscall FUN_0065ff60_class::FUN_0065ff60(int aiArg1, int aiArg2, int aiArg3, int aiArg4, int aiArg5)
{
    FUN_00660190(aiArg1, aiArg2, aiArg3, aiArg4, aiArg5, (int)(this + 8));
}

struct NiRTTI;
struct NiProperty;
struct NiTexture;

struct PropHelper
{
    void* GetProperty(unsigned int);
};
struct SkyShaderProperty
{
    void SetTexture(NiTexture*);
    void FUN_00634900(int*);
};
void* DynamicCastByRTTI(const NiRTTI*, NiProperty*);
extern int DAT_011f49e0;
extern const char* const DAT_012005b8;
struct FUN_00642940_class
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int o;
    int p;
    void FUN_00642940();
};
// @fnv 0x00642940
void FUN_00642940_class::FUN_00642940()
{
    void* pProperty;
    SkyShaderProperty* obj;
    pProperty = ((PropHelper*)((Flt*)((char*)this + 0x10))->operator unsigned int())->GetProperty(3);
    obj = (SkyShaderProperty*)DynamicCastByRTTI((const NiRTTI*)&DAT_012005b8, (NiProperty*)pProperty);
    if (obj)
    {
        obj->SetTexture(0);
        obj->FUN_00634900(&DAT_011f49e0);
    }
    pProperty = ((PropHelper*)((Flt*)((char*)this + 0x14))->operator unsigned int())->GetProperty(3);
    obj = (SkyShaderProperty*)DynamicCastByRTTI((const NiRTTI*)&DAT_012005b8, (NiProperty*)pProperty);
    if (obj)
    {
        obj->SetTexture(0);
        obj->FUN_00634900(&DAT_011f49e0);
    }
}

struct Arr16
{
    void FUN_00644490(int a, int b);
};
struct FUN_00644400_Class
{
    virtual void v0();
    virtual int v1(int a);
    void FUN_00644400(unsigned int a, unsigned int b);
};
// @fnv 0x00644400
void FUN_00644400_Class::FUN_00644400(unsigned int a, unsigned int b)
{
    *(int*)((char*)this + 4) = 0;
    *(int*)((char*)this + 8) = 0;
    *(int*)((char*)this + 12) = 0;
    if (b > a)
    {
        a = b;
    }
    if (a > 0)
    {
        *(int*)((char*)this + 4) = v1(a);
        *(int*)((char*)this + 12) = a;
    }
    if (b > 0)
    {
        ((Arr16*)this)->FUN_00644490(*(int*)((char*)this + 4), b);
        *(int*)((char*)this + 8) = b;
    }
}

struct FUN_00657e60_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    void __thiscall FUN_00657e60();
};
// @fnv 0x00657e60
void __thiscall FUN_00657e60_Class::FUN_00657e60()
{
    if (m_iThirdValue)
    {
        ((FUN_00658060_Class*)this)->FUN_00658060(m_iThirdValue, m_10);
        ((FUN_0064df10_helper*)((char*)this + 8))->deallocate((void*)m_iThirdValue, (unsigned int)((m_14 - m_iThirdValue) / 0x88));
    }
    m_iThirdValue = 0;
    m_10 = 0;
    m_14 = 0;
}

struct H_0060b3b0
{
    float* FUN_006578b0(unsigned int a) const;
};
int __cdecl _memcmp(const void* a, const void* b, unsigned int n);
// @fnv 0x00658160
bool FUN_00657880_class::FUN_00658160(int other)
{
    if (*(unsigned int*)((char*)other + 0x18) != *(unsigned int*)((char*)this + 0x18) ||
        *(unsigned int*)((char*)other + 0x1c) != *(unsigned int*)((char*)this + 0x1c))
        return false;
    if (*(unsigned int*)((char*)this + 0x18) == 0 || *(unsigned int*)((char*)this + 0x1c) == 0)
        return true;
    return _memcmp(((H_0060b3b0*)this)->FUN_006578b0(0), ((H_0060b3b0*)other)->FUN_006578b0(0),
                   (*(unsigned int*)((char*)this + 0x18) << 2) * *(unsigned int*)((char*)this + 0x1c)) == 0;
}

struct FUN_0065d460_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void __thiscall FUN_0065d460();
};
// @fnv 0x0065d460
void __thiscall FUN_0065d460_Class::FUN_0065d460()
{
    if (m_iThirdValue)
    {
        ((FUN_0065dd90_Class*)this)->FUN_0065dd90((int)m_iThirdValue, (int)m_10);
        ((FUN_0064df10_helper*)((char*)this + 8))->deallocate(m_iThirdValue, (unsigned int)(((int)m_14 - (int)m_iThirdValue) / 44));
    }
    m_iThirdValue = 0;
    m_10 = 0;
    m_14 = 0;
}

struct FUN_0065d660_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    void __thiscall FUN_0065d660();
};
// @fnv 0x0065d660
void __thiscall FUN_0065d660_Class::FUN_0065d660()
{
    if (m_iThirdValue)
    {
        ((FUN_0065de80_Class*)this)->FUN_0065de80(m_iThirdValue, m_10);
        ((FUN_0064df10_helper*)((char*)this + 8))->deallocate((void*)m_iThirdValue, (unsigned int)((m_14 - m_iThirdValue) / 0x38));
    }
    m_iThirdValue = 0;
    m_10 = 0;
    m_14 = 0;
}

struct FUN_0065d860_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void __thiscall FUN_0065d860();
};
// @fnv 0x0065d860
void __thiscall FUN_0065d860_class::FUN_0065d860()
{
    if (m_iThirdValue)
    {
        ((FUN_0065df10_class*)this)->FUN_0065df10(m_iThirdValue, m_10);
        ((FUN_0064df10_helper*)((char*)this + 8))->deallocate(m_iThirdValue, (int)((int)m_14 - (int)m_iThirdValue) / 0x1c);
    }
    m_iThirdValue = 0;
    m_10 = 0;
    m_14 = 0;
}

struct EGMDeltaList;
int __fastcall FUN_00657bc0(EGMDeltaList*);
struct Elem_65eed0
{
    short a, b, c;
};
Elem_65eed0* __cdecl FUN_0065f820(Elem_65eed0*, Elem_65eed0*, Elem_65eed0*);

struct Vec_65eed0
{
    void* unk00;
    void* _Myfirstiter;
    FUN_0064df10_helper _Alval;
    Elem_65eed0* _Myfirst;
    Elem_65eed0* _Mylast;
    Elem_65eed0* _Myend;
    void FUN_0065f320();
    bool FUN_0065f380(unsigned int);
    Elem_65eed0* FUN_0065f890(Elem_65eed0*, Elem_65eed0*, Elem_65eed0*);
    Vec_65eed0* FUN_0065eed0(Vec_65eed0* _Right);
};

// Assigns the contents of _Right into this vector, reusing, growing or reallocating storage depending on the two sizes.
// @fnv 0x0065eed0
Vec_65eed0* Vec_65eed0::FUN_0065eed0(Vec_65eed0* _Right)
{
    if (this != _Right)
    {
        if (FUN_00657bc0((EGMDeltaList*)_Right) == 0)
        {
            FUN_0065f320();
        }
        else if ((unsigned int)FUN_00657bc0((EGMDeltaList*)_Right) <= (unsigned int)FUN_00657bc0((EGMDeltaList*)this))
        {
            Elem_65eed0* _Ptr = FUN_0065f820(_Right->_Myfirst, _Right->_Mylast, _Myfirst);
            ((FUN_0065f400_class*)this)->FUN_0065f400((int)_Ptr, (int)_Mylast);
            _Mylast = _Myfirst + FUN_00657bc0((EGMDeltaList*)_Right);
        }
        else if ((unsigned int)FUN_00657bc0((EGMDeltaList*)_Right) <= (unsigned int)((S_0065f2e0*)this)->FUN_0065f2e0())
        {
            Elem_65eed0* _Ptr = _Right->_Myfirst + FUN_00657bc0((EGMDeltaList*)this);
            FUN_0065f820(_Right->_Myfirst, _Ptr, _Myfirst);
            _Mylast = FUN_0065f890(_Ptr, _Right->_Mylast, _Mylast);
        }
        else
        {
            if (_Myfirst != 0)
            {
                ((FUN_0065f400_class*)this)->FUN_0065f400((int)_Myfirst, (int)_Mylast);
                _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
            }
            if (FUN_0065f380(FUN_00657bc0((EGMDeltaList*)_Right)))
                _Mylast = FUN_0065f890(_Right->_Myfirst, _Right->_Mylast, _Myfirst);
        }
    }
    return this;
}

struct FUN_0065f430_class
{
    void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void* m_iThirdValue;
    int m_10;
    int m_14;
    void FUN_0065f430();
};
// @fnv 0x0065f430
void FUN_0065f430_class::FUN_0065f430()
{
    if (m_iThirdValue)
    {
        ((FUN_0065f400_class*)this)->FUN_0065f400((int)m_iThirdValue, m_10);
        ((FUN_0064df10_helper*)((char*)this + 8))->deallocate(m_iThirdValue, (unsigned int)((m_14 - (int)m_iThirdValue) / 6));
    }
    m_iThirdValue = 0;
    m_10 = 0;
    m_14 = 0;
}

struct FUN_0064cc90_Class
{
    void __thiscall FUN_0064cc90(unsigned char bFlag);
};

// If bFlag differs from the byte at this+0x18f, calls vtable slot 47 when bFlag is set, then stores bFlag at this+0x18f.
// @fnv 0x0064cc90
void FUN_0064cc90_Class::FUN_0064cc90(unsigned char bFlag)
{
    if (bFlag == *(unsigned char*)((char*)this + 0x18f))
        return;
    if (bFlag)
        ((void(__thiscall*)(void*, float, int, int, int, int))(*((void***)this))[47])(this, 0.0f, 1, 1, 1, 1);
    *(unsigned char*)((char*)this + 0x18f) = bFlag;
}

void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void* dst, int value, unsigned int size);
struct FUN_00659490_cls2
{
    void* m_vtbl;
    int m_uiItemCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_00659490_cls2* InitArray(int count);
};
// Sets the vtable, stores count, allocates count*4 zeroed bytes into m_data and returns this.
// @fnv 0x00659490
FUN_00659490_cls2* FUN_00659490_cls2::InitArray(int count)
{
    unsigned int size;
    m_vtbl = &DAT_010658d0;
    m_uiItemCount = count;
    m_auiShapeKeys = 0;
    size = m_uiItemCount << 2;
    m_data = NiMalloc(size);
    memset(m_data, 0, m_uiItemCount << 2);
    return this;
}

struct FUN_0065d050
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    void __thiscall Clear_0065d050();
};

// @fnv 0x0065d050
void FUN_0065d050::Clear_0065d050()
{
    if (m_iThirdValue)
    {
        ((FUN_0065db60_class*)this)->FUN_0065db60(m_iThirdValue, m_10);
        ((FUN_0064df10_helper*)((char*)this + 8))->deallocate((void*)m_iThirdValue, (m_14 - m_iThirdValue) / 0xc);
    }
    m_iThirdValue = 0;
    m_10 = 0;
    m_14 = 0;
}

struct FUN_0065f240
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_auiShapeKeys;
    int m_buf;
    int m_iElementCount;
    int m_cap;
    void Clear();
};

// Frees the buffer if set, then resets the buffer, its end pointer and capacity to zero.
// @fnv 0x0065f240
void FUN_0065f240::Clear()
{
    if (m_buf)
    {
        ((FUN_0065f2b0_class*)this)->FUN_0065f2b0(m_buf, m_iElementCount);
        ((FUN_0064df10_helper*)((char*)this + 8))
            ->deallocate((void*)m_buf, (unsigned int)(((int)m_cap - (int)m_buf) >> 2));
    }
    m_buf = 0;
    m_iElementCount = 0;
    m_cap = 0;
}

struct StartMenu
{
    char const* GetMenuTitle();
};

struct GlobalObject_0040c150 : public StartMenu
{
};

extern GlobalObject_0040c150 g_011d30b4;
extern GlobalObject_0040c150 g_011d41a4;

int __cdecl _sprintf_s(char* buffer, unsigned int sizeOfBuffer, char const* format, ...);

// @fnv 0x006495d0
void __cdecl FormatMenuText(int menuType, char const* text, char* buffer, unsigned int bufferSize)
{
    if (!buffer)
        return;

    buffer[0] = 0;

    switch (menuType)
    {
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
        if (text)
        {
            _sprintf_s(buffer, bufferSize, "%s %s", text, g_011d30b4.StartMenu::GetMenuTitle());
        }
        else
        {
            _sprintf_s(buffer, bufferSize, "%s", g_011d30b4.StartMenu::GetMenuTitle());
        }
        break;

    case 31:
        _sprintf_s(buffer, bufferSize, "%s", g_011d41a4.StartMenu::GetMenuTitle());
        break;
    }
}

struct FUN_0064da80_Class
{
    int __thiscall FUN_0064da80(int a, int b);
};

// @fnv 0x0064da80
int __thiscall FUN_0064da80_Class::FUN_0064da80(int aiIndex, int aiUnused)
{
    return reinterpret_cast<int*>(*reinterpret_cast<int**>(reinterpret_cast<unsigned char*>(this) + 0x54))[aiIndex];
}

struct FUN_0064daa0_Class
{
    int __thiscall FUN_0064daa0(int a, int b);
};
// @fnv 0x0064daa0
int __thiscall FUN_0064daa0_Class::FUN_0064daa0(int aiIndex, int b)
{
    return (*(int**)((char*)this + 0x58))[aiIndex];
}

struct BGSTerrainManager
{
    unsigned int GetMinLevel();
};

struct Calendar : public BGSTerrainManager
{
    int GetDaysPassed();
    void __thiscall ScaleAll(float value);
};

// @fnv 0x00653000
void FUN_00653000(float value, Calendar* calendars, bool flag)
{
    if (calendars == 0 || value < 0.0f || value > 1.0f)
        return;

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            if (reinterpret_cast<Calendar*>(reinterpret_cast<char*>(calendars) + (i << 6) + (j << 5))
                        ->GetDaysPassed() != 0 &&
                reinterpret_cast<Calendar*>(reinterpret_cast<char*>(calendars) + (i << 6) + (j << 5))->GetMinLevel() !=
                    0 &&
                (i == 0 || (i == 1 && flag) || !flag))
            {
                reinterpret_cast<Calendar*>(reinterpret_cast<char*>(calendars) + (i << 6) + (j << 5))->ScaleAll(value);
            }
        }
    }
}

struct GO
{
    ~GO();
};

struct Helper62d0
{
    void* operator=(const void*);
};

struct FUN_00658ad0_arg
{
    int m_iWordAt00;
    char* m_iWordAt04;
    Helper62d0 m_8;
};

struct FUN_00658ad0_class
{
    void __thiscall AssignString(FUN_00658ad0_arg* arg, char* source, GO value);
};

int __cdecl strcpy_s(char*, unsigned int, char*);
int __cdecl strlen(char*);
void* __cdecl _NiMalloc(unsigned int);
extern unsigned int _data_011c16bc;

// @fnv 0x00658ad0
void __thiscall FUN_00658ad0_class::AssignString(FUN_00658ad0_arg* arg, char* source, GO goValue)
{
    if (*((unsigned char*)this + 0x10) != 0)
    {
        int length = strlen(source) + 1;
        arg->m_iWordAt04 = (char*)_NiMalloc((unsigned int)length);
        strcpy_s(arg->m_iWordAt04, (unsigned int)length, source);
    }
    else
    {
        arg->m_iWordAt04 = source;
    }

    arg->m_8 = &goValue;
}

struct FUN_00658bb0 : FUN_00658d30_class
{
    ~FUN_00658bb0();
};

// @fnv 0x00658bb0
FUN_00658bb0::~FUN_00658bb0()
{
    *(void**)this = &DAT_01065870;
    FUN_00658d30_class::FUN_00658d30();
}

struct FUN_0065d240_class
{
    void __thiscall ClearAndFree();
};

// If the buffer at offset 0xc is non-null, calls CallWithThisOffset on it and deallocates it, then zeroes the pointers at 0xc, 0x10 and 0x14.
// @fnv 0x0065d240
void __thiscall FUN_0065d240_class::ClearAndFree()
{
    if (*(int*)((char*)this + 0xc) != 0)
    {
        ((FUN_0065dbf0_class*)this)->CallWithThisOffset(*(int*)((char*)this + 0xc), *(int*)((char*)this + 0x10));
        ((FUN_0064df10_helper*)((char*)this + 8))
            ->deallocate(*(void**)((char*)this + 0xc),
                         (unsigned int)((*(int*)((char*)this + 0x14) - *(int*)((char*)this + 0xc)) >> 3));
    }
    *(int*)((char*)this + 0xc) = 0;
    *(int*)((char*)this + 0x10) = 0;
    *(int*)((char*)this + 0x14) = 0;
}

struct FUN_0065d560_Class
{
    void __thiscall ClearAndFreeBuffer();
};

// @fnv 0x0065d560
void FUN_0065d560_Class::ClearAndFreeBuffer()
{
    if (*(int*)((char*)this + 0xc) != 0)
    {
        ((FUN_0065de00_Class*)this)->FUN_0065de00(*(int*)((char*)this + 0xc), *(int*)((char*)this + 0x10));
        ((FUN_0064df10_helper*)((char*)this + 8))
            ->deallocate(*(void**)((char*)this + 0xc),
                         (*(int*)((char*)this + 0x14) - *(int*)((char*)this + 0xc)) / 0x34);
    }
    *(int*)((char*)this + 0xc) = 0;
    *(int*)((char*)this + 0x10) = 0;
    *(int*)((char*)this + 0x14) = 0;
}

struct FUN_0065da00_class
{
    void FUN_0065da00();
};
// @fnv 0x0065da00
void FUN_0065da00_class::FUN_0065da00()
{
    if (*(int*)((char*)this + 0xc) != 0)
    {
        ((FUN_0065df80_class*)this)->FUN_0065df80(*(int*)((char*)this + 0xc), *(int*)((char*)this + 0x10));
        ((FUN_0064df10_helper*)((char*)this + 8))
            ->deallocate(*(void**)((char*)this + 0xc),
                         (*(int*)((char*)this + 0x14) - *(int*)((char*)this + 0xc)) / 0x58);
    }
    *(int*)((char*)this + 0xc) = 0;
    *(int*)((char*)this + 0x10) = 0;
    *(int*)((char*)this + 0x14) = 0;
}

struct FUN_0065dbd0_Class
{
    int a0;
    int a4;
    int FUN_0065dbd0();
};
// @fnv 0x0065dbd0
int FUN_0065dbd0_Class::FUN_0065dbd0()
{
    return ((FUN_0065e050_Holder*)((char*)this + 8))->FUN_0065e050();
}

struct FUN_0065dc40_Class
{
    int CallNestedMethod();
};
// @fnv 0x0065dc40
int FUN_0065dc40_Class::CallNestedMethod()
{
    return ((FUN_0065e080_S*)((char*)this + 8))->FUN_0065e080();
}

struct FUN_0065de60_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int FUN_0065de60();
};

// @fnv 0x0065de60
int FUN_0065de60_Class::FUN_0065de60()
{
    return ((FUN_0065e110_Holder*)((char*)this + 8))->GetPositiveValue();
}

struct FUN_0065def0_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    unsigned int FUN_0065def0();
};
// @fnv 0x0065def0
unsigned int FUN_0065def0_class::FUN_0065def0()
{
    return ((S_0065e140*)((char*)this + 8))->FUN_0065e140();
}

// @fnv 0x0065eb30
void* __cdecl FUN_0065eb30(unsigned int a)
{
    return ((FUN_0065eca0_class*)a)->FUN_0065eca0(0);
}

struct CIdvFilenameDestructorHelper
{
    void __thiscall NarrowString();
};

struct FUN_0065ed30_class
{
    void __thiscall FUN_0065ed30();
};

// @fnv 0x0065ed30
void __thiscall FUN_0065ed30_class::FUN_0065ed30()
{
    reinterpret_cast<CIdvFilenameDestructorHelper*>(reinterpret_cast<unsigned char*>(this) + 4)->NarrowString();
}

struct CIdvFilenameDtorHelper
{
    void Dtor();
};

struct FUN_0065ed50_Class
{
    void FUN_0065ed50();
};

// @fnv 0x0065ed50
void FUN_0065ed50_Class::FUN_0065ed50()
{
    ((CIdvFilenameDtorHelper*)((char*)this + 0x10))->Dtor();
}

struct FUN_0044a9d0_Class
{
    unsigned int FUN_0065f7f0();
};
struct FUN_0065f6e0_Class
{
    int m0;
    int m4;
    FUN_0044a9d0_Class m8;
    unsigned int GetNestedValue();
};
// @fnv 0x0065f6e0
unsigned int FUN_0065f6e0_Class::GetNestedValue()
{
    return m8.FUN_0065f7f0();
}

extern const char DAT_0104f2ac;
struct FUN_00404eb0
{
    int state;
    FUN_00404eb0(int category, int enabled, const char* source, int line);
    ~FUN_00404eb0();
};
struct FUN_00508050
{
    float FUN_00508050_value();
};
struct FUN_00559450
{
    FUN_00508050* FUN_00559450_value();
};
struct FUN_006427c0_Class
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    FUN_00559450 unk28;
    float FUN_006427c0();
};
// Returns the value from the object obtained via unk28, or 0.0f if that object is null.
// @fnv 0x006427c0
float FUN_006427c0_Class::FUN_006427c0()
{
    FUN_00404eb0 scope(0x21, 1, &DAT_0104f2ac, 0x235);
    FUN_00508050* value = unk28.FUN_00559450_value();
    if (value)
        return value->FUN_00508050_value();
    return 0.0f;
}

struct Value_006428b0
{
    int FUN_00441110();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
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
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    float unk6c;
};
struct Link_006428b0
{
    Value_006428b0* FUN_00a59d30();
};
struct Container_006428b0
{
    Link_006428b0* FUN_00559450(int index);
};
struct Object_006428b0
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    Container_006428b0 unk14;
    float GetLinkedValueFloat();
};
// Looks up the value at container index 3, and if its FUN_00441110 result is 13, returns that value's unk6c float; otherwise returns 0.0f.
// @fnv 0x006428b0
float Object_006428b0::GetLinkedValueFloat()
{
    Value_006428b0* value =
        (unk14.FUN_00559450(3)->FUN_00a59d30() == 0 ? false
                                                    : unk14.FUN_00559450(3)->FUN_00a59d30()->FUN_00441110() == 13)
            ? unk14.FUN_00559450(3)->FUN_00a59d30()
            : 0;
    if (value)
        return value->unk6c;
    return 0.0f;
}

extern double DAT_010356d8;
extern double DAT_01012060;
float __cdecl FUN_00476b70(float a, float b);

// @fnv 0x006429e0
float __cdecl FUN_006429e0(float afValue, float afLimit)
{
    float lo2 = (afValue > afLimit) ? afLimit + DAT_010356d8 : afLimit;
    float r = FUN_00476b70(afValue, lo2);
    float s = r - DAT_010356d8;
    r = s >= DAT_01012060 ? s : r;
    return r;
}

extern GlobalObject_0040e0b0 g_011cddec;
extern Setting_S originalRuntimeFloatSetting112;
extern Setting_S originalRuntimeFloatSetting117;
extern Setting_S originalRuntimeFloatSetting113;
extern Setting_S originalRuntimeFloatSetting114;
extern GlobalObject_0040e0b0 g_011cdc28;
extern GlobalObject_0040e0b0 g_011cdfa8;
extern GlobalObject_0040e0b0 g_011cddc4;
extern GlobalObject_0040e0b0 g_011cd890;
extern Setting_S originalRuntimeFloatSetting116;
extern GlobalObject_0040e0b0 g_011cd438;

// Sums base, a level-scaled term, and several setting-weighted terms (some skipped when flag is set) plus extra, returning the total.
// @fnv 0x00642a60
int FUN_00642a60(int base, int level, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int extra,
                 bool abSkipTerms)
{
    int total = 0;
    int levelPart6 = (int)(*g_011cddec.Float() +
                           *originalRuntimeFloatSetting112.Float() * (level - *originalRuntimeFloatSetting117.Float()));
    int part2 = 0;
    if (!abSkipTerms)
    {
        part2 = (int)(*originalRuntimeFloatSetting113.Float() * a3 *
                      (*originalRuntimeFloatSetting114.Float() + *g_011cdc28.Float() * a2));
    }
    int part3 = (int)*g_011cdfa8.Float() * a4;
    int part4 = (int)(a5 * *g_011cddc4.Float() * (*g_011cd890.Float() + a6 * *g_011cddc4.Float()));
    int part5 = 0;
    if (!abSkipTerms)
    {
        part5 = (int)*originalRuntimeFloatSetting116.Float() * a7;
    }
    int part9 = (int)*g_011cd438.Float() * a8;
    total = base + levelPart6 + part2 + part3 + part4 + part5 + part9 + extra;
    return total;
}

extern Setting_S DAT_011cdf78;
extern Setting_S DAT_011cdf44;
extern Setting_S DAT_011cde50;
extern Setting_S DAT_011cdce8;

struct FUN_0066ef50_Class
{
    double FUN_0066ef50(int a);
};

// Returns a scaled value from the actor's FUN_0066ef50(7) plus a setting, multiplied by another setting, depending on the action (0x13 or 0x14); otherwise 0.
// @fnv 0x00643e40
float __cdecl FUN_00643e40(FUN_0066ef50_Class* actor, int action)
{
    float result = 0.0f;
    switch (action)
    {
    case 0x13:
        result = (float)((actor->FUN_0066ef50(7) + *DAT_011cdf78.Float()) * *DAT_011cdf44.Float());
        break;
    case 0x14:
        result = (float)((actor->FUN_0066ef50(7) + *DAT_011cde50.Float()) * *DAT_011cdce8.Float());
        break;
    }
    return result;
}

class FUN_00644350_cls
{
  public:
    int m_iWordAt00;
    float m_iWordAt04;
    float m_8;
    unsigned char IsGreaterThan(FUN_00644350_cls* other);
};

// @fnv 0x00644350
unsigned char FUN_00644350_cls::IsGreaterThan(FUN_00644350_cls* other)
{
    return (m_8 == other->m_8) ? ((m_iWordAt04 > other->m_iWordAt04) ? 1 : 0) : ((m_8 > other->m_8) ? 1 : 0);
}

struct AVOwnerStub_646400
{
    virtual float GetAV0(int index);
    virtual float GetBaseAV(int index);
    virtual float GetAV2(int index);
    virtual float GetCurAV(int index);
    float GetScaledAV(int index);
};

struct FloatSetting_646400
{
    float* Float();
};

extern FloatSetting_646400 originalRuntimeFloatSetting762;
extern FloatSetting_646400 originalRuntimeFloatSetting763;
extern FloatSetting_646400 g_011ce78c;
extern FloatSetting_646400 g_011ce064;
extern FloatSetting_646400 g_011ceecc;
extern FloatSetting_646400 gs_011cecd0;
extern FloatSetting_646400 gs_011ce808;
unsigned int DialogueRandom();

// @fnv 0x00646400
bool FUN_00646400(AVOwnerStub_646400* owner, int value)
{
    bool result2 = false;
    float current4 = owner->GetCurAV(16);
    if (current4 > 0.0)
    {
        float remainingB = current4 - value;
        if (remainingB > 0.0)
        {
            float basePct3 = value / owner->GetBaseAV(16);
            basePct3 = basePct3 * 100.0;
            if (basePct3 > *originalRuntimeFloatSetting762.Float())
            {
                result2 = true;
            }
            else
            {
                float curPct = value / current4;
                curPct = curPct * 100.0;
                if (curPct > *originalRuntimeFloatSetting763.Float())
                {
                    float skill5 = owner->GetScaledAV(10) * 10.0;
                    float denom4 = *g_011ce78c.Float() + *g_011ce064.Float() * skill5;
                    float numer2 = *g_011ceecc.Float() + *gs_011cecd0.Float() * value;
                    float chance7 = numer2 / denom4;
                    if (chance7 >= *gs_011ce808.Float())
                    {
                        chance7 = *gs_011ce808.Float();
                    }
                    chance7 = chance7 * 1000.0;
                    int roll = DialogueRandom() % 1000;
                    if (roll < (int)chance7)
                    {
                        result2 = true;
                    }
                }
            }
        }
    }
    return result2;
}

extern double DAT_01012060;
extern double DAT_01016408;
extern double DAT_01017a40;

struct FUN_00647a30_Obj
{
    virtual void unk00();
    virtual float unk04(int arg);
};

struct FUN_00647a30_Flag
{
    unsigned char Check();
};

// @fnv 0x00647a30
float __cdecl FUN_00647a30(FUN_00647a30_Obj* pObj, FUN_00647a30_Flag* pFlag, float fValue)
{
    float result2 = 0.0f;
    if (pObj != 0 && pFlag != 0)
    {
        int flag = pFlag->Check();
        float f = (float)flag * DAT_01016408;
        float t2 = pObj->unk04(0x10);
        if (t2 <= DAT_01012060)
        {
            result2 = fValue;
        }
        else if (f > DAT_01012060)
        {
            result2 = (float)((fValue / (f * t2)) * DAT_01017a40);
        }
    }
    return result2;
}

class SettingValue
{
  public:
    float* GetValue();
};

extern SettingValue g_011cee24;
extern SettingValue g_011cf314;
extern SettingValue g_011ced28;
extern SettingValue g_011ceb38;

float __cdecl FUN_00476b70(float a, float b);
int __cdecl FUN_00647b70(int a, int b);

// @fnv 0x00647ae0
int __cdecl ComputeScaledSettingSum(float scale)
{
    float v5 = *g_011cee24.GetValue();
    float v2 = *g_011cf314.GetValue() + scale * *g_011ced28.GetValue();
    float v4 = FUN_00476b70(-(*g_011ceb38.GetValue()), *g_011ceb38.GetValue());
    int r = FUN_00647b70(0, (int)(v5 + v2 + v4));
    return r;
}

// Scale a value by the remaining fraction (max - current) / max, clamped to [0, 1].

float __cdecl E50Max(float fA, float fB);
float __cdecl E50Min(float fA, float fB);

// @fnv 0x00648e50
float __cdecl ScaleByInverseRatio(float fValue, float fScaledValue, float afSubtractor)
{
    float fFactor = E50Min(1.0f, E50Max(0.0f, (fScaledValue - afSubtractor) / fScaledValue));
    return fValue * fFactor;
}

struct S_00648ea0_Setting
{
    float* __thiscall FUN_00403e20();
};

extern S_00648ea0_Setting DAT_011d0c90;
extern S_00648ea0_Setting DAT_011d07c0;
extern S_00648ea0_Setting DAT_011d1110;
extern S_00648ea0_Setting DAT_011d0a24;
extern S_00648ea0_Setting DAT_011d00f0;

extern double DAT_01017a40;
extern double DAT_01011588;

// Computes a weighted product of two normalized values and returns it scaled by DAT_01017a40, clamped to 100 when it exceeds the DAT_011d00f0 threshold.
// @fnv 0x00648ea0
int __cdecl ComputeWeightedValue(float value1, float value2, int weight)
{
    float normalized9;
    float normalized8;
    int weightInt2;
    float weightFactor;
    float product3;
    int result;

    normalized9 = 1.0 + *DAT_011d0c90.FUN_00403e20() * (value1 - *DAT_011d07c0.FUN_00403e20()) / DAT_01017a40;
    normalized8 = 1.0 + *DAT_011d1110.FUN_00403e20() * (value2 - *DAT_011d0a24.FUN_00403e20()) / DAT_01017a40;

    weightInt2 = 100 - weight;
    weightFactor = weightInt2 / DAT_01017a40;

    product3 = normalized9 * normalized8 * weightFactor;

    if (product3 > *DAT_011d00f0.FUN_00403e20())
    {
        result = 100;
    }
    else
    {
        result = (int)(product3 * DAT_01017a40 + DAT_01011588);
    }

    return result;
}

extern int DAT_011d5744;

// @fnv 0x006499d0
int __cdecl FUN_006499d0()
{
    return DAT_011d5744;
}

extern double DAT_01012060;
extern double DAT_01012070;

struct FUN_0064bda0_Class
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual float vf94(int index);

    int __thiscall FUN_0064bda0();
};

// @fnv 0x0064bda0
inline void FUN_0064bda0_Class::vf00()
{}
inline void FUN_0064bda0_Class::vf04()
{}
inline void FUN_0064bda0_Class::vf08()
{}
inline void FUN_0064bda0_Class::vf0c()
{}
inline void FUN_0064bda0_Class::vf10()
{}
inline void FUN_0064bda0_Class::vf14()
{}
inline void FUN_0064bda0_Class::vf18()
{}
inline void FUN_0064bda0_Class::vf1c()
{}
inline void FUN_0064bda0_Class::vf20()
{}
inline void FUN_0064bda0_Class::vf24()
{}
inline void FUN_0064bda0_Class::vf28()
{}
inline void FUN_0064bda0_Class::vf2c()
{}
inline void FUN_0064bda0_Class::vf30()
{}
inline void FUN_0064bda0_Class::vf34()
{}
inline void FUN_0064bda0_Class::vf38()
{}
inline void FUN_0064bda0_Class::vf3c()
{}
inline void FUN_0064bda0_Class::vf40()
{}
inline void FUN_0064bda0_Class::vf44()
{}
inline void FUN_0064bda0_Class::vf48()
{}
inline void FUN_0064bda0_Class::vf4c()
{}
inline void FUN_0064bda0_Class::vf50()
{}
inline void FUN_0064bda0_Class::vf54()
{}
inline void FUN_0064bda0_Class::vf58()
{}
inline void FUN_0064bda0_Class::vf5c()
{}
inline void FUN_0064bda0_Class::vf60()
{}
inline void FUN_0064bda0_Class::vf64()
{}
inline void FUN_0064bda0_Class::vf68()
{}
inline void FUN_0064bda0_Class::vf6c()
{}
inline void FUN_0064bda0_Class::vf70()
{}
inline void FUN_0064bda0_Class::vf74()
{}
inline void FUN_0064bda0_Class::vf78()
{}
inline void FUN_0064bda0_Class::vf7c()
{}
inline void FUN_0064bda0_Class::vf80()
{}
inline void FUN_0064bda0_Class::vf84()
{}
inline void FUN_0064bda0_Class::vf88()
{}
inline void FUN_0064bda0_Class::vf8c()
{}
inline void FUN_0064bda0_Class::vf90()
{}
inline float FUN_0064bda0_Class::vf94(int)
{
    return 0.0f;
}

int __thiscall FUN_0064bda0_Class::FUN_0064bda0()
{
    int result = -1;

    {
        float bestValue = 0.0f;

        {
            int index = -1;

            for (; index < 15; ++index)
            {
                float value = this->vf94(index);

                if (value > DAT_01012060 && value >= DAT_01012060 && value <= DAT_01012070 && value > bestValue)
                {
                    bestValue = value;
                    result = index;
                }
            }
        }
    }

    return result;
}

struct FUN_0040fbf0_lock
{
    void Lock(int);
    void Unlock();
};
struct FUN_0064be40_shell
{
    bool FUN_0064be40(float elapsed, int unused);
    int FUN_0064bda0();
    void FUN_0064bf90(int deltaY, float* deltaX, float* limit, float elapsed);
    void SetEyeHeadingAndPitch(float x, float y);
};
struct FUN_00403e20_setting
{
    float* FUN_00403e20();
};
extern FUN_00403e20_setting DAT_011d5924;
void __cdecl FUN_005330e0(float* value, float minimum, float maximum);

// @fnv 0x0064be40
bool FUN_0064be40_shell::FUN_0064be40(float elapsed, int unused)
{
    ((FUN_0040fbf0_lock*)((char*)this + 0x1a0))->Lock(0);
    bool updateNeeded = !*(bool*)((char*)this + 0x18e);
    if (updateNeeded)
    {
        updateNeeded = true;
        int deltaY = FUN_0064bda0();
        float deltaX = *(float*)((char*)this + 0x150);
        float limit = *(float*)((char*)this + 0x154);
        if (deltaY < 15)
            FUN_0064bf90(deltaY, &deltaX, &limit, elapsed);
        float desiredX = deltaX - *(float*)((char*)this + 0x140);
        float stage = limit - *(float*)((char*)this + 0x144);
        float desiredY = *DAT_011d5924.FUN_00403e20() * elapsed;
        FUN_005330e0(&desiredX, -desiredY, desiredY);
        FUN_005330e0(&stage, -desiredY, desiredY);
        *(float*)((char*)this + 0x140) += desiredX;
        *(float*)((char*)this + 0x144) += stage;
        SetEyeHeadingAndPitch(*(float*)((char*)this + 0x140), *(float*)((char*)this + 0x144));
    }
    ((FUN_0040fbf0_lock*)((char*)this + 0x1a0))->Unlock();
    return updateNeeded;
}

struct S_0064ccf0_Obj
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
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
    virtual int vfn_94();
    virtual int vfn_98();
};
struct S_0064ccf0_Base
{
    int unk04;
    S_0064ccf0_Base();
    virtual ~S_0064ccf0_Base();
};
struct S_0064ccf0_Ptr
{
    S_0064ccf0_Obj* unk00;
    S_0064ccf0_Ptr(S_0064ccf0_Obj* p);
    ~S_0064ccf0_Ptr();
    S_0064ccf0_Ptr& operator=(S_0064ccf0_Obj* p);
    operator S_0064ccf0_Obj*() const;
};
struct S_0064ccf0_Member
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S_0064ccf0_Member();
    ~S_0064ccf0_Member();
};
struct FUN_0064ccf0 : S_0064ccf0_Base
{
    S_0064ccf0_Ptr unk08;
    S_0064ccf0_Member unk0c;
    int unk24;
    int unk28;
    FUN_0064ccf0(S_0064ccf0_Obj* a);
    virtual ~FUN_0064ccf0();
};
// Stores the given object pointer and, if non-null, caches its vfn_94 and vfn_98 results in unk24 and unk28; otherwise zeroes both.
// @fnv 0x0064ccf0
FUN_0064ccf0::FUN_0064ccf0(S_0064ccf0_Obj* pObj) : unk08(0)
{
    unk08 = pObj;
    if (unk08)
    {
        unk24 = ((S_0064ccf0_Obj*)unk08)->vfn_94();
        unk28 = ((S_0064ccf0_Obj*)unk08)->vfn_98();
    }
    else
    {
        unk28 = 0;
        unk24 = 0;
    }
}

extern unsigned char DAT_011f94b0;

// @fnv 0x0064d870
unsigned char __cdecl FUN_0064d870()
{
    return DAT_011f94b0;
}

class ConstIter64D
{
  public:
    ConstIter64D();

    int* m_pMyCont;
    int* m_pPtr;
};

class Iter64D : public ConstIter64D
{
  public:
    Iter64D();
};

class Vector64D
{
  public:
    Iter64D begin();
    Iter64D end();
    Iter64D erase(ConstIter64D kFirst, ConstIter64D kLast);
    void FUN_0064db70();
};

// Erases all elements of the vector by calling erase with begin() and end().
// @fnv 0x0064db70
void Vector64D::FUN_0064db70()
{
    erase(begin(), end());
}

struct PairDword
{
    int a;
    int b;
    bool FUN_0065dfd0(PairDword* other);
};

extern "C" int __cdecl FUN_0064e380(int, int, int);

class FUN_0064dc50_cls
{
  public:
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    PairDword* FUN_0065ded0(PairDword* out, int a, int b);
    void ForwardToHelper(int a, int b);
    PairDword FUN_0064dc50(int p1, int p2, int p3, int p4);
};

// @fnv 0x0064dc50
PairDword FUN_0064dc50_cls::FUN_0064dc50(int p1, int p2, int p3, int p4)
{
    PairDword B;
    PairDword A;
    FUN_0065ded0(&B, p1, p2);
    FUN_0065ded0(&A, p3, p4);
    if (B.FUN_0065dfd0(&A))
    {
        int r = FUN_0064e380(A.b, m_10, B.b);
        ForwardToHelper(r, m_10);
        m_10 = r;
    }
    return B;
}

struct Vec2i
{
    int x;
    int y;
};

struct Vector4f
{
    int a;
    int b;
    int c;
    int d;
};

struct Ret8
{
    int x;
    int y;
    Ret8()
    {}
    Ret8(const Ret8& other)
    {
        x = other.x;
        y = other.y;
    }
};

class FUN_0064dcf0_cls
{
  public:
    Vec2i* GetFirst(Vec2i* out);
    Vec2i* GetSecond(Vec2i* out);
    Ret8 Combine(Vec2i b, Vec2i a);
    void Apply(Vec2i c, int a1, Vector4f* q);
    void ApplyToCopy(int a1, const Vector4f* a2);
};

// @fnv 0x0064dcf0
void FUN_0064dcf0_cls::ApplyToCopy(int a1, const Vector4f* pSource)
{
    Vector4f local2 = *pSource;
    Vec2i t7;
    Vec2i a = *GetFirst(&t7);
    Vec2i t1;
    Vec2i b = *GetSecond(&t1);
    Vec2i t4;
    Ret8 r = Combine(b, a);
    Vec2i c6 = *GetSecond(&t4);
    Apply(c6, a1, &local2);
}

struct FUN_0064dda0_target
{
    char pad_00[0x10];
    unsigned int m_10;
};
unsigned int __cdecl FUN_00ec7c56(void);
struct FUN_0064dda0_cls
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    unsigned char __thiscall CheckValid();
    FUN_0064dda0_target* __thiscall GetTarget();
    unsigned int __thiscall FUN_0064dda0();
};
// @fnv 0x0064dda0
unsigned int __thiscall FUN_0064dda0_cls::FUN_0064dda0()
{
    if (!CheckValid())
        FUN_00ec7c56();
    do
    {
    } while (0);
    if (m_iWordAt04 >= GetTarget()->m_10)
        FUN_00ec7c56();
    do
    {
    } while (0);
    return m_iWordAt04;
}

unsigned int __cdecl FUN_00ec7c56(void);
struct S_0064ddf0_Container
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned int end;
};
struct S_0064ddf0_Elem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S_0064ddf0_Iter
{
    int unk00;
    S_0064ddf0_Elem* ptr;
    bool FUN_005ca4f0();
    S_0064ddf0_Container* FUN_0060b980();
    S_0064ddf0_Iter* Increment();
};
// @fnv 0x0064ddf0
S_0064ddf0_Iter* S_0064ddf0_Iter::Increment()
{
    if (!FUN_005ca4f0())
    {
        FUN_00ec7c56();
    }
    do
    {
    } while (0);
    if (!((unsigned int)ptr < FUN_0060b980()->end))
    {
        FUN_00ec7c56();
    }
    do
    {
    } while (0);
    ++ptr;
    return this;
}

namespace std {
struct exception
{
    virtual ~exception() throw();
    const char* message;
    bool ownsMessage;
};
struct bad_alloc : public exception
{
    bad_alloc(const char* = 0) throw();
};
}
// @fnv 0x0064e430
extern "C" void __cdecl FUN_0064e430(int count, int unused)
{
    if ((unsigned int)count <= 0u)
        count = 0;
    else if (0xffffffffu / (unsigned int)count < 16u)
        throw std::bad_alloc();
    ::operator new((unsigned int)count * 16u);
}

struct C64E550CheckedTag
{
};

struct C64E550PtrCategory
{
};

struct C64E550Element;
struct C64E550Allocator;

C64E550PtrCategory C64E550PtrCat(void* first, void* dest);

void C64E550UninitCopy(C64E550Element* first, C64E550Element* last, C64E550Element* dest, C64E550Allocator* alloc,
                       C64E550PtrCategory category, C64E550CheckedTag tag);

// Copies the elements in [first, last) to dest by calling C64E550UninitCopy with the pointer category of first and a checked tag.
// @fnv 0x0064e550
void FUN_0064e550(C64E550Element* first, C64E550Element* last, C64E550Element* dest, C64E550Allocator* alloc)
{
    C64E550UninitCopy(first, last, dest, alloc, C64E550PtrCat(&first, &first), C64E550CheckedTag());
}

void __cdecl ForwardToHandler(int a, int b, void* c, void* d, unsigned char r, unsigned char flag);
unsigned char __cdecl FUN_0065e750(void* p);
int __cdecl CallWithFlag(int* p);

struct FUN_0064e630_flag
{
    bool m_flag;
};

// @fnv 0x0064e630
extern "C" void __cdecl FUN_0064e630(void* apFirst, void* apSecond, void* c, void* d)
{
    FUN_0064e630_flag zeroFlag = {};
    unsigned char zz = FUN_0065e750(&c);
    ForwardToHandler(CallWithFlag((int*)&apFirst), CallWithFlag((int*)&apSecond), c, d, zz, zeroFlag.m_flag);
}

extern "C" void __cdecl FUN_0064e860(void* a1, void* a2, void* a3, unsigned char a4, unsigned char a5,
                                     unsigned char a6);
struct SpawnedFlagBox
{
    unsigned char v;
};

// @fnv 0x0064e6c0
extern "C" void __cdecl FUN_0064e6c0(void* a1, void* a2, void* a3, unsigned char a4)
{
    SpawnedFlagBox flagA3 = {};
    unsigned char flagB;
    flagB = FUN_0065e750(&a1, &a3);
    FUN_0064e860(a1, a2, a3, a4, flagB, flagA3.v);
}

struct S_0064e860_Block
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
};
struct S_0064e860_TagBase
{
};
struct S_0064e860_TagA : S_0064e860_TagBase
{
};
struct S_0064e860_TagB
{
};
struct S_0064e860_TagC
{
};
void* __cdecl CopyBlocksBackward(S_0064e860_Block* a, S_0064e860_Block* b, int c, S_0064e860_TagA t1,
                                 S_0064e860_TagB t2, S_0064e860_TagC t3);
// @fnv 0x0064e860
S_0064e860_Block* __cdecl FUN_0064e860(S_0064e860_Block* first, S_0064e860_Block* last, S_0064e860_Block* dest)
{
    S_0064e860_Block* result = dest - (last - first);
    CopyBlocksBackward(first, last, CallWithFlag((int*)&dest), S_0064e860_TagA(), S_0064e860_TagB(), S_0064e860_TagC());
    return result;
}

struct S_0064e8c0_Blk
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
// Copy-constructs a block from src into the memory at where.
// @fnv 0x0064e8c0
void __cdecl CopyConstructBlock(void* apDest, S_0064e8c0_Blk* src)
{
    void* mem = apDest;
    new (mem) S_0064e8c0_Blk(*src);
}

extern "C" void __cdecl FUN_0064e9c0(int a, int b, int c, int d, int e, int f);

struct FlagBox5317
{
    unsigned char v;
};

// @fnv 0x0064e920
extern "C" void __cdecl FUN_0064e920(int a, int b, int c, int iFourth)
{
    FlagBox5317 flag1 = {};
    unsigned char flag2 = FUN_0065e750((void*)&a, (void*)&c);
    FUN_0064e9c0(CallWithFlag((int*)&a), CallWithFlag((int*)&b), c, iFourth, flag2, flag1.v);
}

struct FUN_0064fcd0_Other
{
    virtual int v00();
    virtual int v01();
    virtual int v02();
    virtual float v03();
    unsigned int __thiscall FUN_0044edb0(int flag);
    float __thiscall FUN_005dd4e0(unsigned int index);
};

struct FUN_0064fcd0_Self
{
    virtual int v00();
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual void v04(float value);
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual void v20(unsigned int value);
    int unk04;
    int unk08;
    int unk0c;
    unsigned int m_uiItemCount;
    void __thiscall FUN_0064a4d0(unsigned int index, float value);
    FUN_0064fcd0_Self* __thiscall CopyFrom(FUN_0064fcd0_Other* other);
};

// If the other object's v01 matches, copies its v03, its FUN_0044edb0(1) result and each FUN_005dd4e0 value into this object, then returns this.
// @fnv 0x0064fcd0
FUN_0064fcd0_Self* FUN_0064fcd0_Self::CopyFrom(FUN_0064fcd0_Other* other)
{
    if (this->v01() != other->v01())
    {
        return this;
    }
    this->v04(other->v03());
    this->v20(other->FUN_0044edb0(1));
    for (unsigned int i = 0; i < this->m_uiItemCount; i++)
    {
        this->FUN_0064a4d0(i, other->FUN_005dd4e0(i));
    }
    return this;
}

struct FUN_00438af0_cls
{
    void FUN_00438af0();
};

struct FUN_0064fe10_cls
{
    virtual void unk00();
    FUN_00658bb0 m_04;

    virtual ~FUN_0064fe10_cls();
};

// Destructor that calls FUN_00438af0 on the member at m_04.
// @fnv 0x0064fe10
FUN_0064fe10_cls::~FUN_0064fe10_cls()
{
    reinterpret_cast<FUN_00438af0_cls*>(&m_04)->FUN_00438af0();
}

struct PathingSolution
{
    void IncRefCount();
    void DecRefCount();
};

struct PathingSolutionBase
{
    int unk04;
    PathingSolutionBase();
    ~PathingSolutionBase();
    virtual void Release()
    {}
};

struct FUN_00650100 : PathingSolutionBase
{
    NiPointer<PathingSolution> m_pPathingSolution;
    FUN_00650100();
};

// Constructs a PathingSolutionHolder, initialising its PathingSolution pointer to null.
// @fnv 0x00650100
FUN_00650100::FUN_00650100() : m_pPathingSolution(0)
{}

struct S_006503b0_Elem;
struct S_006503b0_Slot
{
    int unk00;
    S_006503b0_Slot(int);
    ~S_006503b0_Slot();
    void FUN_0066b0d0(int);
    S_006503b0_Elem* FUN_00559450();
};
struct S_006503b0_Elem
{
    int unk00;
    int unk04;
    S_006503b0_Slot slot08;
    int FUN_00726070();
};
struct S_006503b0_List
{
    int FUN_004b9ba0();
    void FUN_00559120(int* pos, int* out, S_006503b0_Slot* slot);
    void RemoveKey(int item);
};
void __cdecl FUN_00652140();
void __cdecl FUN_00652190();
struct S_006503b0_Owner
{
    int unk00;
    S_006503b0_List list04;
    void FUN_006503b0();
};
// Iterates list04, removing each item whose nested slot reports 1, then calls FUN_00652140 and FUN_00652190 around the loop.
// @fnv 0x006503b0
void S_006503b0_Owner::FUN_006503b0()
{
    FUN_00652140();
    int pos2 = list04.FUN_004b9ba0();
    int item3;
    S_006503b0_Slot slot(0);
    while (pos2 != 0)
    {
        list04.FUN_00559120(&pos2, &item3, &slot);
        if (slot.FUN_00559450()->slot08.FUN_00559450()->FUN_00726070() == 1)
        {
            list04.RemoveKey(item3);
        }
        slot.FUN_0066b0d0(0);
    }
    FUN_00652190();
}

struct ModelHelper
{
    void EnsureMorphData();
};
struct InnerPointer
{
    ModelHelper* FUN_00559450();
};
struct ModelRecord
{
    int unk00, unk04;
    InnerPointer model;
    unsigned time;
};
struct NPX
{
    ModelRecord* ptr;
    NPX(int);
    ~NPX();
    ModelRecord* FUN_00559450();
};
struct FileNames
{
    const char* GetFloatValue();
    const char* FUN_00650600();
};
unsigned FUN_0044a670(const char*);
void FUN_00652140();
void FUN_00652190();
unsigned gm_GetTickCount();
struct CacheMap
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    bool FUN_006c62d0(const char*, NPX&);
};
struct Target
{
    int unk00;
    CacheMap map;
    bool dirty;
    void FUN_00650ba0(ModelRecord*);
    bool FUN_00650480(FileNames*);
};
// @fnv 0x00650480
bool Target::FUN_00650480(FileNames* pFileNames)
{
    NPX a(0);
    if (!pFileNames || !pFileNames->GetFloatValue() || !FUN_0044a670(pFileNames->GetFloatValue()))
        return false;
    bool p = false;
    FUN_00652140();
    if (map.FUN_006c62d0(pFileNames->GetFloatValue(), a) ||
        (pFileNames->FUN_00650600() && map.FUN_006c62d0(pFileNames->FUN_00650600(), a)))
    {
        a.FUN_00559450()->time = gm_GetTickCount();
        FUN_00650ba0(a.FUN_00559450());
        a.FUN_00559450()->model.FUN_00559450()->EnsureMorphData();
        dirty = true;
        p = true;
    }
    FUN_00652190();
    return p;
}

struct Holder_657c50
{
    void __thiscall Fin();
};

struct Pair_657c50
{
    int m_iWordAt00;
    void* __thiscall Method(void* p);
};

struct Blk_657c50
{
    int m_iWordAt00;
    int m_iWordAt04;
};

struct FUN_00657c50_cls
{
    int __thiscall Check();
    void* __thiscall Get1(void* out);
    Holder_657c50* __thiscall Get3(void* out, void* a, void* x);
    void __thiscall Apply(int a, int b, int c, int d);
    void* __thiscall FUN_00657c50(void* a, Pair_657c50 b, int c, int d);
};

// @fnv 0x00657c50
void* FUN_00657c50_cls::FUN_00657c50(void* a, Pair_657c50 pair, int c, int d)
{
    Blk_657c50 t14;
    int t12;
    int dummy;
    void* x = !Check() ? 0 : pair.Method(Get1(&t12));
    Apply(pair.m_iWordAt00, c, 1, d);
    Get3(&t14, a, x)->Fin();
    return a;
}

struct Sub_657cd0_08
{
    int Alloc(unsigned int count);
};

extern "C" void __cdecl Grow_65f640(void);

class FUN_00657cd0_cls
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;

    unsigned int Count();
    bool ReserveEntries(unsigned int idx);
};

// Resets the three pointers, then grows the container or allocates idx entries of 0x3c bytes and sets the begin/current/end pointers.
// @fnv 0x00657cd0
bool FUN_00657cd0_cls::ReserveEntries(unsigned int idx)
{
    m_0c = 0;
    m_10 = 0;
    m_14 = 0;
    if (idx == 0)
    {
        return false;
    }
    else
    {
        if (Count() < idx)
        {
            Grow_65f640();
        }
        else
        {
            m_0c = ((Sub_657cd0_08*)&m_08)->Alloc(idx);
            m_10 = m_0c;
            m_14 = m_0c + idx * 0x3c;
        }
    }
    return true;
}

struct FUN_00657d50_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    void __thiscall FUN_00657d50();
};

struct FUN_00657d50_callee_a
{
    void __thiscall FUN_00657ff0(int a1, int a2);
};

struct FUN_00657d50_callee_b
{
    void __thiscall FUN_0064df10(int a1, int a2);
};

// @fnv 0x00657d50
void FUN_00657d50_cls::FUN_00657d50()
{
    if (m_0c != 0)
    {
        reinterpret_cast<FUN_00657d50_callee_a*>(this)->FUN_00657ff0(m_0c, m_10);
        reinterpret_cast<FUN_00657d50_callee_b*>(&m_08)->FUN_0064df10(m_0c, (m_14 - m_0c) / 60);
    }
    m_0c = 0;
    m_10 = 0;
    m_14 = 0;
}

void __cdecl OverflowAbort_0065f640();

struct SubPool_08
{
    int m_00;
    char* Grow(unsigned int index);
};

struct FUN_00657dd0_cls
{
    int m_00;
    int m_04;
    SubPool_08 m_08;
    char* m_0c;
    char* m_10;
    char* m_14;
    unsigned int GetCount();
    bool FUN_00657dd0(unsigned int index);
};

// @fnv 0x00657dd0
bool FUN_00657dd0_cls::FUN_00657dd0(unsigned int index)
{
    m_0c = 0;
    m_10 = 0;
    m_14 = 0;
    if (index == 0)
    {
        return false;
    }
    else
    {
        if (GetCount() < index)
        {
            OverflowAbort_0065f640();
        }
        else
        {
            m_0c = m_08.Grow(index);
            m_10 = m_0c;
            m_14 = m_0c + index * 0x88;
        }
    }
    return true;
}

struct FUN_00657ee0_sub
{
    int unk00;
    unsigned int __thiscall Alloc(unsigned int n);
};

struct FUN_00657ee0_cls
{
    int unk00;
    int unk04;
    FUN_00657ee0_sub m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;

    unsigned int __thiscall Count();
    static void __cdecl Grow();
    bool __thiscall FUN_00657ee0(unsigned int a);
};

// @fnv 0x00657ee0
bool FUN_00657ee0_cls::FUN_00657ee0(unsigned int a)
{
    m_0c = 0;
    m_10 = 0;
    m_14 = 0;
    if (a == 0)
    {
        return false;
    }
    else
    {
        if (this->Count() < a)
        {
            Grow();
        }
        else
        {
            m_0c = m_08.Alloc(a);
            m_10 = m_0c;
            m_14 = m_0c + a;
        }
    }
    return true;
}

class SpanEntry;

class FUN_006580b0_cls
{
  public:
    int unk00;
    SpanEntry* m_pEntries;

    bool CheckState();
    bool CheckEntry(FUN_006580b0_cls* other);
    int GetEntryOffset(FUN_006580b0_cls* other);
};

// If CheckState or CheckEntry fails it calls FUN_00ec7c56, then returns the byte distance between m_pEntries pointers divided by 4.
// @fnv 0x006580b0
int FUN_006580b0_cls::GetEntryOffset(FUN_006580b0_cls* other)
{
    if (CheckState() == 0 || CheckEntry(other) == 0)
    {
        FUN_00ec7c56();
    }
    do
    {
    } while (0);
    return (int)((char*)m_pEntries - (char*)other->m_pEntries) >> 2;
}

struct FNV_MapKey
{
    int value;
    FNV_MapKey(const FNV_MapKey&);
    ~FNV_MapKey();
    void FUN_006e5cc0(FNV_MapKey*);
};
struct FNV_MapNode
{
    FNV_MapNode* next;
    int id;
    FNV_MapKey key;
};
struct FNV_HashMap
{
    virtual void Reserved();
    virtual int Hash(int id);
    virtual bool Equals(int id, int existing);
    virtual void Init(FNV_MapNode* node, int id, FNV_MapKey key);
    unsigned int unk04;
    FNV_MapNode** buckets;
    int count;
    bool keepExisting;
    FNV_MapNode* FUN_006c63e0();
    void InsertOrUpdate(int id, FNV_MapKey key);
};
// Looks up the bucket for id, updates the matching node's key (and id unless keepExisting), or allocates and inserts a new node and increments count.
// @fnv 0x00658950
void FNV_HashMap::InsertOrUpdate(int id, FNV_MapKey key)
{
    int bucketIndex = Hash(id);
    FNV_MapNode* node = buckets[bucketIndex];
    int probeCount = 0;
    while (node)
    {
        ++probeCount;
        if (Equals(id, node->id))
        {
            if (!keepExisting)
                node->id = id;
            node->key.FUN_006e5cc0(&key);
            return;
        }
        node = node->next;
    }
    node = FUN_006c63e0();
    Init(node, id, key);
    node->next = buckets[bucketIndex];
    buckets[bucketIndex] = node;
    ++count;
}

struct Hldr0044
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void FUN_0044d6c0(int a);
};

extern "C" void __stdcall FUN_00ec7894(Hldr0044* p, void* dat);
extern "C" void __cdecl FormHeap_Allocate(int scaled);
extern "C" int DAT_01140ef8;

// @fnv 0x00658c10
extern "C" void __cdecl FUN_00658c10(int aiValue, int aiUnused)
{
    Hldr0044 h;

    if ((unsigned)aiValue <= 0)
    {
        aiValue = 0;
    }
    else
    {
        if (0xFFFFFFFFu / (unsigned)aiValue < 60)
        {
            h.FUN_0044d6c0(0);
            FUN_00ec7894(&h, &DAT_01140ef8);
        }
    }

    FormHeap_Allocate(aiValue * 60);
}

class Base_b9895
{
  public:
    Base_b9895();
    ~Base_b9895();

    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};

class FUN_00659000 : public Base_b9895
{
  public:
    void unk_Alloc(int size);

    int m_18;
    int m_1c;

    FUN_00659000(int a, int b);
};

// Initializes the base, stores the two arguments in m_18 and m_1c, then allocates m_1c * m_18 bytes via unk_Alloc.
// @fnv 0x00659000
FUN_00659000::FUN_00659000(int aiFirst, int aiSecond) : Base_b9895()
{
    m_18 = aiFirst;
    m_1c = aiSecond;
    unk_Alloc(m_1c * m_18);
}

struct FUN_0065cd70_Elem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;

    void FUN_0065cd70();
    ~FUN_0065cd70_Elem();
};

struct FUN_00659600
{
    int unk00;
    FUN_0065cd70_Elem m_aiIndexedValues[2];

    ~FUN_00659600();
};

// @fnv 0x00659600
FUN_00659600::~FUN_00659600()
{
    m_aiIndexedValues[0].FUN_0065cd70();
    m_aiIndexedValues[1].FUN_0065cd70();
}

struct PacketEntry
{
    unsigned int identifier;
    unsigned int state;
    unsigned int offset;
    unsigned int length;
    unsigned int mode;
    unsigned int flags;
    PacketEntry();
    ~PacketEntry();
};
struct PacketScope
{
    unsigned int key;
    unsigned int state;
    unsigned int start;
    unsigned int end;
    unsigned int flags;
    unsigned int context;
    unsigned int owner;
    PacketScope(unsigned int selector);
    ~PacketScope();
};
void __cdecl FUN_00ab2640(PacketScope* scope, void* owner, PacketEntry* begin, PacketEntry* next);
struct FUN_00659670
{
    unsigned int mode;
    PacketEntry entries[2];
    FUN_00659670(unsigned int selector);
};
// Constructs a PacketScope from selector and calls FUN_00ab2640 with it, this, and the two entries.
// @fnv 0x00659670
FUN_00659670::FUN_00659670(unsigned int selector)
{
    PacketScope scope(selector);
    FUN_00ab2640(&scope, this, &entries[0], &entries[1]);
}

struct FUN_00659710_elem
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    void Init();
    ~FUN_00659710_elem();
};

class FUN_00659710_cls
{
  public:
    int m_00;
    FUN_00659710_elem m_04[2];
    ~FUN_00659710_cls();
};

// Destructor that calls Init on both elements of the m_04 array.
// @fnv 0x00659710
FUN_00659710_cls::~FUN_00659710_cls()
{
    m_04[0].Init();
    m_04[1].Init();
}

void* FUN_00607340();

class OwnerBase
{
  public:
    virtual ~OwnerBase();
    int m_iWordAt04;
    int m_8;

    OwnerBase(void* p);
};

class SubMember
{
  public:
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;

    SubMember(bool flag);
    ~SubMember();
    void Apply(int value);
};

class SubMember_d0045cec0 : public SubMember
{
  public:
    SubMember_d0045cec0(bool f) : SubMember(f)
    {}
    ~SubMember_d0045cec0();
};
class FUN_0065be60 : public OwnerBase
{
  public:
    SubMember_d0045cec0 m_iThirdValue;

    FUN_0065be60(int a);
    virtual ~FUN_0065be60();
};

// Constructs the object with a base from FUN_00607340 and a SubMember initialized to false, then applies a to the SubMember.
// @fnv 0x0065be60
FUN_0065be60::FUN_0065be60(int aiValue) : OwnerBase(FUN_00607340()), m_iThirdValue(false)
{
    m_iThirdValue.Apply(aiValue);
}

struct FUN_0065cfb0
{
    ~FUN_0065cfb0();
};
struct FUN_0065c7c0 : FUN_0065cfb0
{
    ~FUN_0065c7c0();
    void ClearStorage();
};
// @fnv 0x0065c7c0
FUN_0065c7c0::~FUN_0065c7c0()
{
    ClearStorage();
}

// Container default constructor: base storage takes a default allocator, then reserve nothing.

class C5C820Allocator
{
  public:
    C5C820Allocator();
    C5C820Allocator(const C5C820Allocator& kOther);
};

class C5C820Storage
{
  public:
    C5C820Storage(C5C820Allocator kAlloc);
    ~C5C820Storage();
    void* m_pFirst;
    void* m_pLast;
    void* m_pRecordEnd;
};

class FUN_0065c820 : public C5C820Storage
{
  public:
    FUN_0065c820();
    void Buy(unsigned int uiCapacity);
};

// @fnv 0x0065c820
FUN_0065c820::FUN_0065c820() : C5C820Storage(C5C820Allocator())
{
    Buy(0);
}

struct FUN_0065cfb0_base
{
    int unk00;
    ~FUN_0065cfb0_base();
};

struct FUN_0065c890_cls : FUN_0065cfb0_base
{
    void ClearAndFree();
    ~FUN_0065c890_cls();
};

// @fnv 0x0065c890
FUN_0065c890_cls::~FUN_0065c890_cls()
{
    ClearAndFree();
}

class ScopeBase_c960
{
  public:
    ~ScopeBase_c960();
    int unk04;
};

class FUN_0065c960_cls : public ScopeBase_c960
{
  public:
    ~FUN_0065c960_cls();
    void unk08();
};

// Destructor that calls unk08 on the object before base destruction.
// @fnv 0x0065c960
FUN_0065c960_cls::~FUN_0065c960_cls()
{
    this->unk08();
}

struct Mem_65ca30
{
    ~Mem_65ca30();
};
struct FUN_0065ca30
{
    Mem_65ca30 m_mem;
    void FUN_0065d460();
    ~FUN_0065ca30();
};
// @fnv 0x0065ca30
FUN_0065ca30::~FUN_0065ca30()
{
    FUN_0065d460();
}

struct FUN_006815c0
{
    int unk00;
    FUN_006815c0();
    FUN_006815c0(const FUN_006815c0&);
};
struct FUN_0065d3a0
{
    FUN_0065d3a0(FUN_006815c0 value);
    ~FUN_0065d3a0();
};
struct FUN_0065ca90 : FUN_0065d3a0
{
    FUN_0065ca90();
    void __thiscall FUN_0065d4e0(int value);
};
// Constructs the base with a default value and initializes the object by calling FUN_0065d4e0 with 0.
// @fnv 0x0065ca90
FUN_0065ca90::FUN_0065ca90() : FUN_0065d3a0(FUN_006815c0())
{
    FUN_0065d4e0(0);
}

namespace fnv_0065cb00 {
struct FUN_0065cfb0
{
    ~FUN_0065cfb0();
};
struct FUN_0065cb00 : FUN_0065cfb0
{
    void ClearAndFreeBuffer();
    ~FUN_0065cb00();
};
// @fnv 0x0065cb00
FUN_0065cb00::~FUN_0065cb00()
{
    ClearAndFreeBuffer();
}
}  // namespace fnv_0065cb00

// Container default constructor: base storage takes a default allocator, then reserve nothing.

class C5CB60Allocator
{
  public:
    C5CB60Allocator();
    C5CB60Allocator(const C5CB60Allocator& kOther);
};

class C5CB60Storage
{
  public:
    C5CB60Storage(C5CB60Allocator kAlloc);
    ~C5CB60Storage();
    void* m_pFirst;
    void* m_pLast;
    void* m_pRecordEnd;
};

class FUN_0065cb60 : public C5CB60Storage
{
  public:
    FUN_0065cb60();
    void Buy(unsigned int uiCapacity);
};

// Constructs the storage with a default allocator and calls Buy(0) to initialise it.
// @fnv 0x0065cb60
FUN_0065cb60::FUN_0065cb60() : C5CB60Storage(C5CB60Allocator())
{
    Buy(0);
}

namespace fnv_0065cbd0 {
struct FUN_0065cfb0
{
    ~FUN_0065cfb0();
};
struct FUN_0065cbd0 : FUN_0065cfb0
{
    ~FUN_0065cbd0();
};
// Destructor that calls FUN_0065d660 on this object.
// @fnv 0x0065cbd0
FUN_0065cbd0::~FUN_0065cbd0()
{
    ((FUN_0065d660_Class*)this)->FUN_0065d660();
}
}  // namespace fnv_0065cbd0

struct FUN_0065cfb0_Base
{
    ~FUN_0065cfb0_Base();
};

struct FUN_0065cd10 : FUN_0065cfb0_Base
{
    void FUN_0065d860();
    ~FUN_0065cd10();
};

// @fnv 0x0065cd10
FUN_0065cd10::~FUN_0065cd10()
{
    FUN_0065d860();
}

struct B65CD70ConstIterator
{
    float* m_pfData;
    int m_iArrayCapacity;
};

struct B65CD70Iterator : public B65CD70ConstIterator
{
};

// clear(): erase(begin(), end())
class B65CD70Vector
{
  public:
    B65CD70Iterator begin();
    B65CD70Iterator end();
    B65CD70Iterator erase(B65CD70ConstIterator kFirst, B65CD70ConstIterator kLast);

    void FUN_0065cd70();
};

// Erases all elements of the vector by calling erase(begin(), end()).
// @fnv 0x0065cd70
void B65CD70Vector::FUN_0065cd70()
{
    erase(begin(), end());
}

namespace fnv_0065cdd0 {
struct FUN_006815c0
{
    int value;
    FUN_006815c0();
    FUN_006815c0(const FUN_006815c0&);
};
struct FUN_0065d3a0
{
    FUN_0065d3a0(FUN_006815c0 value);
    ~FUN_0065d3a0();
    void __thiscall FUN_0065d980(int value);
};
struct FUN_0065cdd0 : FUN_0065d3a0
{
    FUN_0065cdd0();
};
// Constructs the base with a default value and then calls FUN_0065d980 with 0.
// @fnv 0x0065cdd0
FUN_0065cdd0::FUN_0065cdd0() : FUN_0065d3a0(FUN_006815c0())
{
    FUN_0065d980(0);
}
}  // namespace fnv_0065cdd0

class C65CE40List
{
  public:
    ~C65CE40List();

    int unk00;
    int unk04;
};

class FUN_0065ce40 : public C65CE40List
{
  public:
    ~FUN_0065ce40();

    void RemoveAll();
};

// Destructor that calls RemoveAll to clear the list's contents.
// @fnv 0x0065ce40
FUN_0065ce40::~FUN_0065ce40()
{
    RemoveAll();
}

struct FNVPair8
{
    unsigned int lo;
    unsigned int hi;
};

class FUN_0065cef0_cls
{
  public:
    FNVPair8* CallWithSelf(FNVPair8* out);
    FNVPair8* FUN_0044a170(FNVPair8* out);
    void BuildAndComparePair(FNVPair8* out, FNVPair8 y, FNVPair8 x);
    void FUN_0065cef0();
};

// Reads two FNVPair8 values via CallWithSelf and FUN_0044a170, then passes them to BuildAndComparePair to produce an output pair.
// @fnv 0x0065cef0
void FUN_0065cef0_cls::FUN_0065cef0()
{
    FNVPair8 tmpA3;
    FNVPair8 x;
    FNVPair8 tmpB;
    FNVPair8 y3;
    FNVPair8 out;

    x = *CallWithSelf(&tmpA3);
    y3 = *FUN_0044a170(&tmpB);
    BuildAndComparePair(&out, y3, x);
}

struct FUN_0065cfd0_sub
{
    int m_iWordAt00;
    void* __thiscall Alloc(unsigned int n);
};

extern "C" void __cdecl ThrowVectorTooLong();

struct FUN_0065cfd0_cls
{
    int m_00;
    int m_04;
    FUN_0065cfd0_sub m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    unsigned int CountItems();
    bool ReserveItems(unsigned int n);
};

// @fnv 0x0065cfd0
bool FUN_0065cfd0_cls::ReserveItems(unsigned int n)
{
    m_0c = 0;
    m_10 = 0;
    m_14 = 0;
    if (n == 0)
    {
        return false;
    }
    else
    {
        if (CountItems() < n)
        {
            ThrowVectorTooLong();
        }
        else
        {
            m_0c = m_08.Alloc(n);
            m_10 = m_0c;
            m_14 = (char*)m_0c + n * 12;
        }
    }
    return true;
}

void __cdecl ClearSharedBuffers();

struct FUN_0065d0d0_sub
{
    int unk00;
    void* Reserve(unsigned int count);
};

struct FUN_0065d0d0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    FUN_0065d0d0_sub m_08;
    char* m_0c;
    char* m_10;
    char* m_14;

    unsigned int GetCount();
    bool ReserveBuffers(unsigned int count);
};

// @fnv 0x0065d0d0
bool FUN_0065d0d0_cls::ReserveBuffers(unsigned int count)
{
    m_0c = 0;
    m_10 = 0;
    m_14 = 0;
    if (count == 0)
    {
        return false;
    }
    else
    {
        if (GetCount() < count)
        {
            ClearSharedBuffers();
        }
        else
        {
            m_0c = (char*)m_08.Reserve(count);
            m_10 = m_0c;
            m_14 = m_0c + count * 16;
        }
    }
    return true;
}

struct S_0065d1c0_Element
{
    int __thiscall FUN_0065dc20(unsigned int a);
};

struct S_0065d1c0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    S_0065d1c0_Element m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;

    unsigned int __thiscall FUN_0065dbd0();
    bool __thiscall AllocateElements(unsigned int a);
};

extern void __cdecl ThrowVectorTooLong();

// Resets the element pointers, then allocates a elements via m_8 and stores the base, current and end pointers; returns false when a is zero.
// @fnv 0x0065d1c0
bool __thiscall S_0065d1c0_Class::AllocateElements(unsigned int a)
{
    m_iThirdValue = 0;
    m_10 = 0;
    m_14 = 0;

    if (a == 0)
    {
        return false;
    }
    else if (FUN_0065dbd0() < a)
    {
        ThrowVectorTooLong();
    }
    else
    {
        m_iThirdValue = m_8.FUN_0065dc20(a);
        m_10 = m_iThirdValue;
        m_14 = m_iThirdValue + a * 8;
    }

    return true;
}

struct FUN_0065d2b0_sub
{
    int unk00;
    int Alloc(int n);
};

extern "C" void __cdecl ThrowVectorTooLong();

struct FUN_0065d2b0_cls
{
    int unk00;
    int unk04;
    FUN_0065d2b0_sub m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    unsigned int GetCount();
    bool FUN_0065d2b0(int n);
};

// Resets the three fields, then either calls ThrowVectorTooLong when the count is below n or allocates n and sets the range from the result.
// @fnv 0x0065d2b0
bool FUN_0065d2b0_cls::FUN_0065d2b0(int aiCount)
{
    m_iThirdValue = 0;
    m_10 = 0;
    m_14 = 0;
    if (aiCount == 0)
    {
        return false;
    }
    else
    {
        if ((unsigned int)GetCount() < (unsigned int)aiCount)
        {
            ThrowVectorTooLong();
        }
        else
        {
            m_iThirdValue = m_8.Alloc(aiCount);
            m_10 = m_iThirdValue;
            m_14 = (aiCount << 5) + m_iThirdValue;
        }
    }
    return true;
}

struct S_0065d3e0_Pool
{
    int unk00;
    char* FUN_0065ddc0(unsigned n);
};
void __cdecl ThrowVectorTooLong();
struct S_0065d3e0_Class
{
    int unk00;
    int unk04;
    S_0065d3e0_Pool unk08;
    char* unk0c;
    char* unk10;
    char* unk14;
    unsigned FUN_0065dd70();
    bool AllocateBuffer(unsigned n);
};

// @fnv 0x0065d3e0
bool S_0065d3e0_Class::AllocateBuffer(unsigned n)
{
    unk0c = 0;
    unk10 = 0;
    unk14 = 0;
    if (n == 0)
    {
        return false;
    }
    else
    {
        if (FUN_0065dd70() < n)
        {
            ThrowVectorTooLong();
        }
        else
        {
            unk0c = unk08.FUN_0065ddc0(n);
            unk10 = unk0c;
            unk14 = unk0c + n * 0x2c;
        }
    }
    return true;
}

class FUN_0065d4e0_Pool
{
  public:
    unsigned int unk00;
    unsigned int Alloc(unsigned int count);
};

class FUN_0065d4e0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    FUN_0065d4e0_Pool m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;

    unsigned int GetCount();
    bool FUN_0065d4e0(unsigned int n);
};

void FUN_0065d4e0_GrowFail();

// @fnv 0x0065d4e0
bool FUN_0065d4e0_cls::FUN_0065d4e0(unsigned int n)
{
    m_0c = 0;
    m_10 = 0;
    m_14 = 0;
    if (n == 0)
    {
        return false;
    }
    else
    {
        if (GetCount() < n)
        {
            FUN_0065d4e0_GrowFail();
        }
        else
        {
            m_0c = m_08.Alloc(n);
            m_10 = m_0c;
            m_14 = m_0c + n * 0x34;
        }
    }
    return true;
}

struct FUN_0065d5e0_sub
{
    int m_iWordAt00;
    unsigned char* Alloc(unsigned int index);
};

void FUN_0065f640_reserve();

struct FUN_0065d5e0_cls
{
    int m_iWordAt00;
    int m_iWordAt04;
    FUN_0065d5e0_sub m_8;
    unsigned char* m_iThirdValue;
    unsigned char* m_10;
    unsigned char* m_14;
    unsigned int Count();
    bool AllocateEntries(unsigned int index);
};

// Clears the three pointers, then either reserves capacity when index exceeds Count() or allocates index entries of 0x38 bytes and sets the begin/end pointers.
// @fnv 0x0065d5e0
bool FUN_0065d5e0_cls::AllocateEntries(unsigned int index)
{
    m_iThirdValue = 0;
    m_10 = 0;
    m_14 = 0;
    if (index == 0)
    {
        return false;
    }
    else
    {
        if (Count() < index)
        {
            FUN_0065f640_reserve();
        }
        else
        {
            m_iThirdValue = m_8.Alloc(index);
            m_10 = m_iThirdValue;
            m_14 = m_iThirdValue + index * 0x38;
        }
    }
    return true;
}

namespace fnv_0065d740 {
struct FNVPair8
{
    unsigned int lo;
    unsigned int hi;
    bool Compare(FNVPair8* other);
};

extern "C" unsigned int __cdecl FUN_0065e1f0(unsigned int a, unsigned int b, unsigned int c);

class FUN_0065d740_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_10;
    void FUN_0065ded0(FNVPair8* out, unsigned int a, unsigned int b);
    void FUN_0065df10(unsigned int a, unsigned int b);
    FNVPair8* FUN_0065d740(FNVPair8* out, unsigned int a, unsigned int b, unsigned int c, unsigned int d);
};

// @fnv 0x0065d740
FNVPair8* FUN_0065d740_cls::FUN_0065d740(FNVPair8* out, unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    FNVPair8 local1;
    FNVPair8 local7;

    FUN_0065ded0(&local1, a, b);
    FUN_0065ded0(&local7, c, d);
    if (local1.Compare(&local7))
    {
        unsigned int t = FUN_0065e1f0(local7.hi, m_10, local1.hi);
        FUN_0065df10(t, m_10);
        m_10 = t;
    }
    *out = local1;
    return out;
}
}  // namespace fnv_0065d740

struct Lay_d8e0_Pair
{
    int m_00;
    int m_04;
    bool IsLess(Lay_d8e0_Pair* other);
};

extern "C" int __cdecl Lay_d8e0_Combine(int a, int b, int c);

struct FUN_0065d8e0_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    void Build(Lay_d8e0_Pair* out, int a, int b);
    void Store(int a, int b);
    Lay_d8e0_Pair* BuildAndComparePair(Lay_d8e0_Pair* out, int a1, int a2, int a3, int a4);
};

// Builds two pairs from the given values, and if the first is less than the second, combines and stores values before returning the first pair.
// @fnv 0x0065d8e0
Lay_d8e0_Pair* FUN_0065d8e0_cls::BuildAndComparePair(Lay_d8e0_Pair* out, int aiFirstA, int aiFirstB, int aiSecondA,
                                                     int aiSecondB)
{
    Lay_d8e0_Pair first;
    Lay_d8e0_Pair second;
    Build(&first, aiFirstA, aiFirstB);
    Build(&second, aiSecondA, aiSecondB);
    if (first.IsLess(&second))
    {
        int temp = Lay_d8e0_Combine(second.m_04, m_10, first.m_04);
        Store(temp, m_10);
        m_10 = temp;
    }
    *out = first;
    return out;
}

struct D980Elem
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
};

struct D980Alloc
{
    D980Elem* allocate(unsigned int n);
};

void __cdecl ThrowVectorTooLong();

struct D980Vector
{
    int unk00;
    int unk04;
    D980Alloc _Alval;
    D980Elem* _Myfirst;
    D980Elem* _Mylast;
    D980Elem* _Myend;

    unsigned int max_size();
    bool FUN_0065d980(unsigned int _Capacity);
};

// Resets the vector's pointers, then allocates _Capacity elements via _Alval, setting _Myfirst, _Mylast and _Myend; returns false for zero capacity.
// @fnv 0x0065d980
bool D980Vector::FUN_0065d980(unsigned int _Capacity)
{
    _Myfirst = 0;
    _Mylast = 0;
    _Myend = 0;
    if (_Capacity == 0)
        return false;
    else if (max_size() < _Capacity)
        ThrowVectorTooLong();
    else
    {
        _Myfirst = _Alval.allocate(_Capacity);
        _Mylast = _Myfirst;
        _Myend = _Myfirst + _Capacity;
    }
    return true;
}

struct FUN_0065dae0_target
{
    char pad_00[0x10];
    unsigned int m_10;
};
unsigned int __cdecl FUN_00ec7c56(void);
struct FUN_0065dae0_cls
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    unsigned char __thiscall CheckValid();
    FUN_0065dae0_target* __thiscall GetTarget();
    FUN_0065dae0_cls* __thiscall FUN_0065dae0();
};
// @fnv 0x0065dae0
FUN_0065dae0_cls* __thiscall FUN_0065dae0_cls::FUN_0065dae0()
{
    if (!CheckValid())
        FUN_00ec7c56();
    do
    {
    } while (0);
    if (m_iWordAt04 >= GetTarget()->m_10)
        FUN_00ec7c56();
    do
    {
    } while (0);
    m_iWordAt04 += 6;
    return this;
}

struct FUN_0065e0e0_cls
{
    unsigned int FUN_0065e0e0();
};

// @fnv 0x0065e0e0
unsigned int FUN_0065e0e0_cls::FUN_0065e0e0()
{
    unsigned int count = 0x4ec4ec4;
    return count > 0 ? count : 1;
}

struct S_0065e1a0
{
    int unk00;
    int unk04;
    bool FUN_005ca4f0();
    bool FUN_004b0460(S_0065e1a0* other);
    bool FUN_0065e1a0(S_0065e1a0* other);
};
// @fnv 0x0065e1a0
bool S_0065e1a0::FUN_0065e1a0(S_0065e1a0* other)
{
    if (!FUN_005ca4f0() || !FUN_004b0460(other))
        FUN_00ec7c56();
    do
    {
    } while (0);
    return unk04 == other->unk04;
}

namespace fnv_0065e310 {
struct FUN_0065e310_cls
{
    int unk00;
    int unk04;
    int unk08;
    void __thiscall FUN_0044d6c0(int arg);
};

extern "C" void __stdcall FUN_00ec7894(void* obj, void* dtor);
extern "C" void* __cdecl FormHeap_Allocate(unsigned int size);
extern int DAT_01140ef8;

// @fnv 0x0065e310
extern "C" void __cdecl FUN_0065e310(int count, int)
{
    FUN_0065e310_cls tmp;
    if ((unsigned int)count <= 0)
    {
        count = 0;
    }
    else
    {
        if (0xffffffffu / (unsigned int)count < 12)
        {
            tmp.FUN_0044d6c0(0);
            FUN_00ec7894(&tmp, &DAT_01140ef8);
        }
    }
    FormHeap_Allocate((unsigned int)count * 12);
}
}  // namespace fnv_0065e310

namespace fnv_0065e430 {
namespace std {
class bad_alloc
{
  public:
    virtual ~bad_alloc();
    bad_alloc(const char* message = 0);
    const char* message;
    bool ownsMessage;
};
}

// @fnv 0x0065e430
void* __cdecl FUN_0065e430(unsigned int count)
{
    if (count <= 0u)
        count = 0;
    else if (0xffffffffu / count < 32u)
        throw std::bad_alloc();

    return ::operator new(count * 32u);
}
}  // namespace fnv_0065e430

struct LengthErrorB9431
{
    virtual void v0();
    int m_iWordAt04;
    int m_8;
    LengthErrorB9431(int msg);
    ~LengthErrorB9431() throw();
};

// Validates that count * 0x2c does not overflow, throwing LengthErrorB9431 on overflow, then allocates count * 0x2c bytes via operator new.
// @fnv 0x0065e4c0
void* __cdecl FUN_0065e4c0(unsigned int count)
{
    if (count <= 0)
    {
        count = 0;
    }
    else
    {
        if (0xFFFFFFFFu / count < 0x2c)
        {
            throw LengthErrorB9431(0);
        }
    }
    return operator new(count * 0x2c);
}

struct S_0065e550_Err
{
    virtual void vf00();
    int unk04;
    int unk08;
    S_0065e550_Err(int code);
    ~S_0065e550_Err();
};

void* __cdecl operator new(unsigned int size);

// Clamps n to 0, throws S_0065e550_Err(0) if n * 0x34 would overflow, and returns operator new(n * 0x34).
// @fnv 0x0065e550
void* __cdecl FUN_0065e550(unsigned int auiCount)
{
    if (auiCount <= 0)
    {
        auiCount = 0;
    }
    else if (0xffffffffu / auiCount < 0x34)
    {
        throw S_0065e550_Err(0);
    }
    return operator new(auiCount * 0x34);
}

namespace fnv_0065e5e0 {
struct FUN_0065e5e0_Hldr
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    void Init(int code);
};

extern "C" void __stdcall FUN_00ec7894(FUN_0065e5e0_Hldr* p, void* dat);
extern "C" void* __cdecl FormHeap_Allocate(unsigned int size);
extern "C" int DAT_01140ef8;

// @fnv 0x0065e5e0
void* __cdecl FUN_0065e5e0(unsigned int n)
{
    FUN_0065e5e0_Hldr h;

    if (n <= 0)
    {
        n = 0;
    }
    else
    {
        if (0xFFFFFFFFu / n < 56)
        {
            h.Init(0);
            FUN_00ec7894(&h, &DAT_01140ef8);
        }
    }

    return FormHeap_Allocate(n * 56);
}
}  // namespace fnv_0065e5e0

namespace fnv_0065e670 {
class FUN_0065e670_cls
{
  public:
    FUN_0065e670_cls(int unk00);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};

extern "C" char DAT_01140ef8;
int __cdecl FormHeap_Allocate(unsigned int size);
void __stdcall FUN_00ec7894(FUN_0065e670_cls* obj, char* msg);

// @fnv 0x0065e670
void __cdecl FUN_0065e670(unsigned int count, int unused)
{
    if (count <= 0)
    {
        count = 0;
    }
    else
    {
        if (0xffffffffu / count < 0x1c)
        {
            FUN_0065e670_cls local(0);
            FUN_00ec7894(&local, &DAT_01140ef8);
        }
    }
    FormHeap_Allocate(count * 0x1c);
}
}  // namespace fnv_0065e670

struct LengthErrB9739
{
    virtual void v0();
    int m_iWordAt04;
    int m_8;
    LengthErrB9739(int msg);
    ~LengthErrB9739() throw();
};

// @fnv 0x0065e700
void* __cdecl FUN_0065e700(unsigned int count)
{
    if (count <= 0)
    {
        count = 0;
    }
    else
    {
        if (0xFFFFFFFFu / count < 0x58)
        {
            throw LengthErrB9739(0);
        }
    }
    return operator new(count * 0x58);
}

// @fnv 0x0065e750
unsigned char __cdecl FUN_0065e750(void* a, void* b)
{
    char c;
    return c;
}

struct EmptyTag
{
};
int __cdecl CallWithFlag(int*);
int __cdecl FUN_0065eac0(int, int, int, EmptyTag, EmptyTag, EmptyTag);
// @fnv 0x0065e7c0
int __cdecl FUN_0065e7c0(int first, int last, int destination)
{
    int result = ((last - first) / 88) * 88 + destination;
    {
        EmptyTag firstZero = {};
        EmptyTag secondZero = {};
        EmptyTag option;
        FUN_0065eac0(first, last, CallWithFlag(&destination), option, secondZero, firstZero);
    }
    return result;
}

class FUN_0065f060_base
{
  public:
    ~FUN_0065f060_base();
    int unk04;
};

class FUN_0065f060 : public FUN_0065f060_base
{
  public:
    ~FUN_0065f060();
    void unk08();
};

// Destructor that calls unk08() on this object.
// @fnv 0x0065f060
FUN_0065f060::~FUN_0065f060()
{
    this->unk08();
}

struct Alloc_65f0c0
{
    void deallocate(void* p, unsigned int n);
};

char* __cdecl Copy_65f8c0(char* first, char* last, char* dest);

struct Vec_65f0c0
{
    void* unk00;
    void* _Myfirstiter;
    Alloc_65f0c0 _Alval;
    char* _Myfirst;
    char* _Mylast;
    char* _Myend;

    unsigned int size() const;
    unsigned int capacity() const;
    void clear();
    void _Destroy(char* first, char* last);
    char* _Ucopy(char* first, char* last, char* dest);
    bool _Buy(unsigned int n);
    Vec_65f0c0& FUN_0065f0c0(const Vec_65f0c0& _Right);
};

// Copy-assigns _Right into this vector, reusing existing storage when possible and reallocating when _Right is larger than capacity.
// @fnv 0x0065f0c0
Vec_65f0c0& Vec_65f0c0::FUN_0065f0c0(const Vec_65f0c0& _Right)
{
    if (this != &_Right)
    {
        if (_Right.size() == 0)
        {
            clear();
        }
        else if (_Right.size() <= size())
        {
            char* _Ptr = Copy_65f8c0(_Right._Myfirst, _Right._Mylast, _Myfirst);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Myfirst + _Right.size();
        }
        else if (_Right.size() <= capacity())
        {
            char* _Ptr = _Right._Myfirst + size();
            Copy_65f8c0(_Right._Myfirst, _Ptr, _Myfirst);
            _Mylast = _Ucopy(_Ptr, _Right._Mylast, _Mylast);
        }
        else
        {
            if (_Myfirst != 0)
            {
                _Destroy(_Myfirst, _Mylast);
                _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
            }
            if (_Buy(_Right.size()))
                _Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
        }
    }
    return *this;
}

struct Pair8_b6530
{
    int lo;
    int hi;
};

struct Vec_65eed0_callees_b6530
{
    Pair8_b6530* CallWithSelf(Pair8_b6530* out);
    Pair8_b6530* FUN_0044a170(Pair8_b6530* out);
    void FUN_0065f5a0(Pair8_b6530* out, Pair8_b6530 a, Pair8_b6530 b);
};

// Reads two pairs via CallWithSelf and FUN_0044a170, then passes them to FUN_0065f5a0 to produce a result.
// @fnv 0x0065f320
void Vec_65eed0::FUN_0065f320()
{
    Pair8_b6530 first;
    Pair8_b6530 firstTmp4;
    Pair8_b6530 second3;
    Pair8_b6530 secondTmp;
    Pair8_b6530 result;

    first = *((Vec_65eed0_callees_b6530*)this)->CallWithSelf(&firstTmp4);
    second3 = *((Vec_65eed0_callees_b6530*)this)->FUN_0044a170(&secondTmp);
    ((Vec_65eed0_callees_b6530*)this)->FUN_0065f5a0(&result, second3, first);
}

namespace fnv_0065f4f0 {
struct FNVPair8
{
    unsigned int lo;
    unsigned int hi;
};

class FUN_0065f4f0_cls
{
  public:
    FNVPair8* CallWithSelf(FNVPair8* out);
    FNVPair8* FUN_0044a170(FNVPair8* out);
    void FUN_0065f700(FNVPair8* out, FNVPair8 y, FNVPair8 x);
    void FUN_0065f4f0();
};

// Reads two FNVPair8 values via CallWithSelf and FUN_0044a170, then passes them to FUN_0065f700 to produce an output pair.
// @fnv 0x0065f4f0
void FUN_0065f4f0_cls::FUN_0065f4f0()
{
    FNVPair8 tmpA3;
    FNVPair8 x;
    FNVPair8 tmpB;
    FNVPair8 y3;
    FNVPair8 out;

    x = *CallWithSelf(&tmpA3);
    y3 = *FUN_0044a170(&tmpB);
    FUN_0065f700(&out, y3, x);
}
}  // namespace fnv_0065f4f0

namespace fnv_0065f5a0 {
struct FNVPair8
{
    unsigned int lo;
    unsigned int hi;
    bool FUN_0065dfd0(FNVPair8* other);
};

class FUN_0065f5a0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_10;
    FNVPair8* FUN_0065ded0(FNVPair8* out, int a, int b);
    void FUN_0065f400(int a, int b);
    FNVPair8* FUN_0065f5a0(FNVPair8* out, int a, int b, int c, int d);
};

// @fnv 0x0065f5a0
FNVPair8* FUN_0065f5a0_cls::FUN_0065f5a0(FNVPair8* out, int a, int b, int c, int d)
{
    FNVPair8 A5;
    FNVPair8 B;

    FUN_0065ded0(&A5, a, b);
    FUN_0065ded0(&B, c, d);
    if (A5.FUN_0065dfd0(&B))
    {
        int t = (int)FUN_0065f820((Elem_65eed0*)B.hi, (Elem_65eed0*)m_10, (Elem_65eed0*)A5.hi);
        FUN_0065f400(t, m_10);
        m_10 = t;
    }
    *out = A5;
    return out;
}
}  // namespace fnv_0065f5a0

namespace fnv_0065f640 {
// vector<T>::_Xlen: report a length error by throwing length_error("vector<T> too long").

class TooLongString
{
  public:
    int m_aiBuf0;
    int m_aiBuf1;
    int m_aiBuf2;
    int m_aiBuf3;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
    int m_iAlloc;

    TooLongString(const char* pText);
    ~TooLongString();
};

class LengthError
{
  public:
    const char* m_pWhat;
    int m_iDoFree;
    TooLongString m_kStr;

    LengthError(const TooLongString& kError);
    LengthError(const LengthError& kOther);
    virtual ~LengthError();
};

// Throws a LengthError constructed from the message "vector<T> too long".
// @fnv 0x0065f640
void __cdecl ThrowVectorTooLong()
{
    throw LengthError("vector<T> too long");
}
}  // namespace fnv_0065f640

struct C65F700Node;

struct C65F700Iterator
{
    void* m_pvContainer;
    C65F700Node* m_pkNode;

    bool operator==(const C65F700Iterator& kOther);
};

C65F700Node* C65F700Unlink(C65F700Node* pitLast, C65F700Node* pkHead, C65F700Node* pitFirst);

class C65F700List
{
  public:
    C65F700Iterator MakeIterator(void* pvContainer, C65F700Node* pkNode);
    void FreeRange(C65F700Node* pitFirst, C65F700Node* pkHead);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C65F700Node* m_pkHead;

    C65F700Iterator FUN_0065f700(void* pvFirstCont, C65F700Node* pitFirst, void* pvLastCont, C65F700Node* pitLast);
};

// Builds iterators for the first and last nodes; if they are equal, unlinks that node, frees the range and updates m_pkHead, then returns the first iterator.
// @fnv 0x0065f700
C65F700Iterator C65F700List::FUN_0065f700(void* pvFirstCont, C65F700Node* pitFirst, void* pvLastCont,
                                          C65F700Node* pitLast)
{
    C65F700Iterator itFirst = MakeIterator(pvFirstCont, pitFirst);
    C65F700Iterator itLast = MakeIterator(pvLastCont, pitLast);
    if (itFirst == itLast)
    {
        C65F700Node* pkNewHead = C65F700Unlink(itLast.m_pkNode, m_pkHead, itFirst.m_pkNode);
        FreeRange(pkNewHead, m_pkHead);
        m_pkHead = pkNewHead;
    }
    return itFirst;
}

struct S_0065f8c0_PtrTag
{
    char v;
};
struct S_0065f8c0_ChkTag
{
    char v;
};
struct S_0065f8c0_IterTag
{
    char v;
    S_0065f8c0_IterTag()
    {}
};
S_0065f8c0_PtrTag __cdecl FUN_0065e750(char** first, char** dest);
S_0065f8c0_IterTag __cdecl FUN_0065fd70(char** first, char** dest);
char* __cdecl CallWithFlag(char** p);
char* __cdecl FUN_0065fe60(char* first, char* last, char* dest, S_0065f8c0_IterTag a, S_0065f8c0_PtrTag b,
                           S_0065f8c0_ChkTag c);

// @fnv 0x0065f8c0
char* __cdecl FUN_0065f8c0(char* first, char* last, char* dest)
{
    return FUN_0065fe60(CallWithFlag(&first), CallWithFlag(&last), dest, FUN_0065fd70(&first, &dest),
                        FUN_0065e750(&first, &dest), S_0065f8c0_ChkTag());
}

namespace fnv_0065f9e0 {
namespace std {
class bad_alloc
{
  public:
    bad_alloc(const char* message);
    virtual ~bad_alloc();
    virtual const char* what() const;

  private:
    const char* message_;
    bool owns_message_;
};
}
// @fnv 0x0065f9e0
extern "C" void __cdecl FUN_0065f9e0(int count, int unused)
{
    if ((unsigned int)count <= 0u)
    {
        count = 0;
    }
    else if (0xffffffffu / (unsigned int)count < 6u)
    {
        throw std::bad_alloc(0);
    }
    ::operator new((unsigned int)count * 6u);
}
}  // namespace fnv_0065f9e0

namespace fnv_0065fa30 {
namespace std {
class bad_alloc
{
  public:
    virtual ~bad_alloc();
    bad_alloc(const char* message = 0);
    const char* description;
    int ownsMessage;
};
}
// @fnv 0x0065fa30
void* __cdecl AllocateChecked(unsigned int count)
{
    if (count <= 0)
    {
        count = 0;
    }
    else
    {
        if (0xffffffffu / count < 1u)
            throw std::bad_alloc();
    }
    return ::operator new(count);
}
}  // namespace fnv_0065fa30

extern void FUN_0065f060();
extern void FUN_0065fc10();
void __stdcall FUN_00ecaebb(void* dst, void* src, unsigned int size, unsigned int count, void (*copyCtor)(),
                            void (*dtor)());

struct FUN_0065fab0_cls
{
    float m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    FUN_0065fab0_cls* FUN_0065fab0(FUN_0065fab0_cls* src);
};

// Copies the four leading fields from src and copies three 0x18-byte elements at offset 0x10 using the given copy constructor and destructor.
// @fnv 0x0065fab0
FUN_0065fab0_cls* FUN_0065fab0_cls::FUN_0065fab0(FUN_0065fab0_cls* apSource)
{
    m_iWordAt00 = apSource->m_iWordAt00;
    m_iWordAt04 = apSource->m_iWordAt04;
    m_8 = apSource->m_8;
    m_iThirdValue = apSource->m_iThirdValue;
    FUN_00ecaebb((char*)this + 0x10, (char*)apSource + 0x10, 0x18, 3, FUN_0065fc10, FUN_0065f060);
    return this;
}

// @fnv 0x0065fd70
int __cdecl FUN_0065fd70(int a)
{
    int b;
    return a;
}

int __cdecl CopyTripleShorts(int a, int b, int r, bool z, bool y, bool x);
int __cdecl CallWithFlag(int* p);

struct FNVFlag7675
{
    bool v;
};

// Computes an index from a, b and c, calls CopyTripleShorts with a, b and the result of CallWithFlag(&c), then returns the index.
// @fnv 0x0065fd80
int __cdecl ComputeIndexAndCall(int a, int b, int c)
{
    int idx3 = ((b - a) / 6) * 6 + c;
    FNVFlag7675 y = {};
    FNVFlag7675 x5 = {};
    bool z;
    CopyTripleShorts(a, b, CallWithFlag(&c), z, x5.v, y.v);
    return idx3;
}

// Candidate: CallWithFlag
//   int CallWithFlag(int* p) { bool flag; return FUN_0043b1d0(p, flag); }
int __cdecl FUN_0043b1d0(int* p, bool flag);

// @fnv 0x0065fe40
int __cdecl CallWithFlag(int* p)
{
    bool flag;
    return FUN_0043b1d0(p, flag);
}

struct _DummyTag
{
};
struct S_0065ff90_Tag
{
};
struct S_0065ff90_Dest
{
    int* m_ptr;
    unsigned int m_iElementCount;
};
_DummyTag __cdecl FUN_0065e750(S_0065ff90_Dest* dest);
void __cdecl FUN_00660210(int first, int last, S_0065ff90_Dest dest, _DummyTag cat, S_0065ff90_Tag tag);
// @fnv 0x0065ff90
void __cdecl FUN_0065ff90(int first, int last, S_0065ff90_Dest dest)
{
    FUN_00660210(CallWithFlag(&first), CallWithFlag(&last), dest, FUN_0065e750(&dest), S_0065ff90_Tag());
}

namespace fnv_0065ffe0 {
struct SpawnedFlagBox
{
    unsigned char v;
};

int __cdecl FUN_00660230(int a, int b, int c, int d, unsigned char e, unsigned char f);
unsigned char __cdecl FUN_0065e750(void* p);

// @fnv 0x0065ffe0
int __cdecl FUN_0065ffe0(int a, int b, int c, int d)
{
    SpawnedFlagBox flagA3 = {};
    unsigned char flagB = FUN_0065e750(&c);
    return FUN_00660230(CallWithFlag(&a), CallWithFlag(&b), c, d, flagB, flagA3.v);
}
}  // namespace fnv_0065ffe0

class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct FUN_0064ec10_obj
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual bool IsCopyable();
    int value04, value08, value0c, value10;
    FUN_0064ec10_obj(const FUN_0064ec10_obj&);
};
struct CloneComponent
{
    int value00, value04, value08, value0c, value10;
    CloneComponent* CopyFrom(CloneComponent*);
};
struct LinkedList
{
    int head, tail, count;
    void* FUN_00559450();
    FUN_0064ec10_obj*& AddEight(void*);
    void* DereferenceIfNotNull(void*);
    void FUN_004ed8c0(void* const&);
};
struct CloneVector
{
    float x, y, z;
};
struct FUN_00649680 : NiMemObject
{
    int value00, value04, value08;
    FUN_0064ec10_obj* extra;
    CloneComponent member10, member24, member38, member4c, member60, member74;
    LinkedList list88;
    CloneComponent member94, membera8;
    LinkedList listbc;
    CloneComponent memberc8, memberdc;
    LinkedList listf0;
    CloneComponent memberfc, member110;
    CloneVector vector124;
    int value130;
    int value134;
    int value138;
    int value13c;
    int value140;
    int value144;
    int value148;
    int value14c;
    int value150;
    int value154;
    int value158;
    int value15c;
    int value160;
    int value164;
    int value168;
    int value16c;
    int value170;
    int value174;
    int value178;
    int value17c;
    int value180;
    int value184;
    unsigned char flag188;
    unsigned char flag189;
    unsigned char flag18a;
    unsigned char flag18b;
    unsigned char flag18c;
    unsigned char flag18d;
    unsigned char flag18e;
    unsigned char flag18f;
    unsigned char flag190;
    unsigned char flag191;
    unsigned char flag192;
    unsigned char flag193;
    int value194;
    int value198;
    int value19c;
    int value1a0;
    int value1a4;
    int value1a8;
    int value1ac;
    int value1b0;
    int value1b4;
    int value1b8;
    int value1bc;
    FUN_00649680();
    FUN_00649680* FUN_0064c5a0();
};
// @fnv 0x0064c5a0
FUN_00649680* FUN_00649680::FUN_0064c5a0()
{
    FUN_00649680* copy = new FUN_00649680;
    copy->member10.CopyFrom(&member10);
    copy->member24.CopyFrom(&member24);
    copy->member74.CopyFrom(&member74);
    copy->member94.CopyFrom(&member94);
    copy->member38.CopyFrom(&member38);
    copy->membera8.CopyFrom(&membera8);
    copy->memberc8.CopyFrom(&memberc8);
    copy->member4c.CopyFrom(&member4c);
    copy->memberdc.CopyFrom(&memberdc);
    copy->memberfc.CopyFrom(&memberfc);
    copy->member60.CopyFrom(&member60);
    copy->member110.CopyFrom(&member110);
    copy->vector124 = vector124;
    copy->flag18b = flag18b;
    copy->flag188 = flag188;
    copy->flag18c = flag18c;
    copy->flag18f = flag18f;
    copy->flag190 = flag190;
    if (extra)
        copy->extra = new FUN_0064ec10_obj(*extra);
    else
        copy->extra = 0;
    void* position;
    FUN_0064ec10_obj* cloned;
    position = list88.FUN_00559450();
    while (position)
    {
        FUN_0064ec10_obj* eligible0 = list88.AddEight(position);
        FUN_0064ec10_obj* item0;
        if (item0 = eligible0->IsCopyable() ? eligible0 : 0)
            cloned = new FUN_0064ec10_obj(*item0);
        else
            cloned = 0;
        copy->list88.FUN_004ed8c0(cloned);
        position = list88.DereferenceIfNotNull(position);
    }
    position = listbc.FUN_00559450();
    while (position)
    {
        FUN_0064ec10_obj* item1 = listbc.AddEight(position);
        FUN_0064ec10_obj* eligible1;
        if (eligible1 = item1->IsCopyable() ? item1 : 0)
            cloned = new FUN_0064ec10_obj(*eligible1);
        else
            cloned = 0;
        copy->listbc.FUN_004ed8c0(cloned);
        position = listbc.DereferenceIfNotNull(position);
    }
    position = listf0.FUN_00559450();
    while (position)
    {
        FUN_0064ec10_obj* eligible2 = listf0.AddEight(position);
        FUN_0064ec10_obj* item2;
        if (item2 = eligible2->IsCopyable() ? eligible2 : 0)
            cloned = new FUN_0064ec10_obj(*item2);
        else
            cloned = 0;
        copy->listf0.FUN_004ed8c0(cloned);
        position = listf0.DereferenceIfNotNull(position);
    }
    return copy;
}

template <class T> struct FGPointer
{
    T* m_pObject;

    FGPointer(T* apObject);
    ~FGPointer();
    operator T*() const;
};

struct FGPixelFormat
{
    int unk00;
};

struct FGRGBA
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

struct FGPixels
{
    FGRGBA* GetPixels(int aiMipmap, int aiFace);
    unsigned int GetWidth(int aiMipmap, int aiFace);
    unsigned int GetHeight(int aiMipmap, int aiFace);
};

struct FGPixelData
{
    FGPixels* GetData();
};

struct FGSourceTexture
{
    int unk00;
};

struct FGColor
{
    float r;
    float g;
    float b;
    float a;
};

struct FGImage
{
    int unk00;
    int unk04;
    int unk08;

    bool IsEmpty();
    void Resize(unsigned int auiCount, FGColor* apFill);
    FGColor* GetAt(unsigned int auiIndex);
};

extern const FGPixelFormat g_kFGPixelFormatRGBA32;
FGPixelData* __cdecl FGConvertPixelData(FGSourceTexture* apTexture, const FGPixelFormat* apFormat);

struct FGOwner
{
    int unk00;
    int unk04;
    FGPointer<FGSourceTexture> m_spTexture;
    FGImage m_kImage;

    FGImage* GetOrConvertImage();
};

// @fnv 0x0064d880
FGImage* FGOwner::GetOrConvertImage()
{
    if (m_kImage.IsEmpty() && m_spTexture)
    {
        FGPointer<FGPixelData> spPixelData = FGConvertPixelData(m_spTexture, &g_kFGPixelFormatRGBA32);
        if (!spPixelData)
            return &m_kImage;

        FGPixels* pPixels4 = ((FGPixelData*)spPixelData)->GetData();
        FGRGBA* pSrc2 = pPixels4->GetPixels(0, 0);
        unsigned int uiCount2 = pPixels4->GetWidth(0, 0) * pPixels4->GetHeight(0, 0);
        FGColor kBlack2;
        kBlack2.r = kBlack2.g = kBlack2.b = kBlack2.a = 0.0f;
        m_kImage.Resize(uiCount2, &kBlack2);
        for (unsigned int i2 = 0; i2 < uiCount2; i2++)
        {
            m_kImage.GetAt(i2)->r = pSrc2[i2].r;
            m_kImage.GetAt(i2)->g = pSrc2[i2].g;
            m_kImage.GetAt(i2)->b = pSrc2[i2].b;
            m_kImage.GetAt(i2)->a = pSrc2[i2].a;
        }
    }
    return &m_kImage;
}

class Obj653;

class Handle653
{
  public:
    Handle653(int iValue);
    ~Handle653();
    Obj653* Get() const;

    Obj653* m_pPointer;
};

class Owner653
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    Handle653 m_kHandle;
};

class Ref653
{
  public:
    int unk00;
    int unk04;
    Owner653* m_pkOwnerManager;

    Obj653* GetHandleObject();
};

// Returns the object held by the owner's handle, or the object of a temporary empty handle when the owner pointer is null.
// @fnv 0x00653180
Obj653* Ref653::GetHandleObject()
{
    return (m_pkOwnerManager ? m_pkOwnerManager->m_kHandle : Handle653(0)).Get();
}

struct FUN_00657a80 : FUN_0065d3a0
{
    FUN_00657a80();
};

// Constructs the object, initialising the base with FUN_006815c0() and then calling FUN_00657dd0(0) on this.
// @fnv 0x00657a80
FUN_00657a80::FUN_00657a80() : FUN_0065d3a0(FUN_006815c0())
{
    ((FUN_00657dd0_cls*)this)->FUN_00657dd0(0);
}

// Destructor: clear the contents, then the base container is destroyed.

class E7AF0Base
{
  public:
    ~E7AF0Base();

    void* m_pResource;
    unsigned int m_uiSize;
};

class FUN_00657af0 : public E7AF0Base
{
  public:
    ~FUN_00657af0();
    void Clear();
};

// @fnv 0x00657af0
FUN_00657af0::~FUN_00657af0()
{
    Clear();
}

void* __cdecl operator new(unsigned int uiSize);

class C658CA0BadAlloc
{
  public:
    C658CA0BadAlloc(const char* pcMessage = 0);
    virtual ~C658CA0BadAlloc();

    const char* m_pcWhat;
    int m_iDoFree;
};

struct C658CA0Element
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
};

// Clamps the element count to zero, throws C658CA0BadAlloc on overflow, and allocates count * sizeof(C658CA0Element) bytes.
// @fnv 0x00658ca0
C658CA0Element* __cdecl FUN_00658ca0(unsigned int ItemUpdateArray, C658CA0Element*)
{
    if (ItemUpdateArray <= 0)
        ItemUpdateArray = 0;
    else if (((unsigned int)(-1) / ItemUpdateArray) < sizeof(C658CA0Element))
        throw C658CA0BadAlloc(0);

    return (C658CA0Element*)::operator new(ItemUpdateArray * sizeof(C658CA0Element));
}

struct Node_658d50
{
    Node_658d50* next;
    void* data;
};

struct Base_658d50
{
    virtual ~Base_658d50();
};

struct FUN_00658d50 : Base_658d50
{
    unsigned int count;
    Node_658d50** buckets;
    int unk0c;
    unsigned char flag;
    ~FUN_00658d50();
};

void __cdecl NiFree(void* p);

// If flag is set, walks every bucket, frees each node's data with NiFree, and advances to the next node.
// @fnv 0x00658d50
FUN_00658d50::~FUN_00658d50()
{
    if (this->flag)
    {
        for (unsigned int i = 0; i < this->count; ++i)
        {
            Node_658d50* node = this->buckets[i];
            while (node)
            {
                Node_658d50* tmp = node;
                node = node->next;
                NiFree(tmp->data);
            }
        }
    }
}

struct ObjectCleanupBase658e10
{
    virtual ~ObjectCleanupBase658e10();
};
struct FUN_00658e10 : ObjectCleanupBase658e10
{
    void FUN_00438af0();
    virtual ~FUN_00658e10();
};
// @fnv 0x00658e10
FUN_00658e10::~FUN_00658e10()
{
    FUN_00438af0();
}

struct FUN_00659080_Class
{
    void __thiscall FUN_00659080(FUN_00659140_Class* obj);
};
// If obj is non-null, calls its FUN_00659140 method with argument 1.
// @fnv 0x00659080
void FUN_00659080_Class::FUN_00659080(FUN_00659140_Class* pObject)
{
    FUN_00659140_Class* a = pObject;
    FUN_00659140_Class* p = a;
    p ? p->FUN_00659140(1) : 0;
}

struct FUN_0065c9c0 : FUN_0065d3a0
{
    FUN_0065c9c0();
    void AllocateBuffer(unsigned int flag);
};
// @fnv 0x0065c9c0
FUN_0065c9c0::FUN_0065c9c0() : FUN_0065d3a0(FUN_006815c0())
{
    AllocateBuffer(0);
}

class B65CCA0List
{
  public:
    B65CCA0List();
    B65CCA0List(const B65CCA0List& kOther);

    void* m_pvHandle;
};

class B65CCA0Base
{
  public:
    B65CCA0Base(B65CCA0List kList);
    ~B65CCA0Base();

    int unk04;
};

class FUN_0065cca0_cls : public B65CCA0Base
{
  public:
    FUN_0065cca0_cls();

    void Reset(int iFlags);
};

// @fnv 0x0065cca0
FUN_0065cca0_cls::FUN_0065cca0_cls() : B65CCA0Base(B65CCA0List())
{
    Reset(0);
}

unsigned char* __cdecl FUN_0065fd70(unsigned char* out, int* a1, int* a2);
void __cdecl FUN_0065e760(int a, int b, int c, unsigned char d, unsigned char e, unsigned char f);

struct FlagA
{
    bool v;
};

// @fnv 0x0065e1f0
void __cdecl FUN_0065e1f0(int aiValueA, int aiValueB, int aiValueC)
{
    FlagA FLAGA = {};
    unsigned char flagB = FUN_0065e750(&aiValueA, &aiValueC);
    unsigned char out;
    FUN_0065e760(CallWithFlag(&aiValueA), CallWithFlag(&aiValueB), aiValueC, *FUN_0065fd70(&out, &aiValueA, &aiValueC),
                 flagB, FLAGA.v);
}

struct RangeCheckedTag65E
{
};

struct ScalarPtrTag65E
{
};

struct NonscalarPtrTag65E
{
    NonscalarPtrTag65E();
};

typedef int* Iter65E;

ScalarPtrTag65E __cdecl IterCat65E(Iter65E& kFirst, Iter65E& kDest);
NonscalarPtrTag65E __cdecl PtrCat65E(Iter65E& kFirst, Iter65E& kDest);
Iter65E __cdecl CheckedBase65E(Iter65E& kIter);
void __cdecl UninitCopy65E(Iter65E pFirst, Iter65E pLast, Iter65E pDest, NonscalarPtrTag65E kPtrCat,
                           ScalarPtrTag65E kIterCat, RangeCheckedTag65E kTag);

// @fnv 0x0065e260
void __cdecl UninitializedCopy(Iter65E kFirst, Iter65E kLast, Iter65E kDest)
{
    UninitCopy65E(CheckedBase65E(kFirst), CheckedBase65E(kLast), kDest, PtrCat65E(kFirst, kDest),
                  IterCat65E(kFirst, kDest), RangeCheckedTag65E());
}

struct FUN_0044d6c0_class
{
    int unk00;
    int unk04;
    int unk08;
    void* __thiscall FUN_0044d6c0(void** a);
};

// @fnv 0x0065e3a0
void __cdecl FUN_0065e3a0(int aiCount, int)
{
    if ((unsigned int)aiCount <= 0u)
    {
        aiCount = 0;
    }
    else if (0xFFFFFFFFu / (unsigned int)aiCount < 8u)
    {
        FUN_0044d6c0_class holder;
        holder.FUN_0044d6c0(0);
        FUN_00ec7894((Hldr0044*)&holder, (void*)&DAT_01140ef8);
    }
    FormHeap_Allocate(aiCount << 3);
}

struct B65E760Item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct B65E760IterCategory
{
};
struct B65E760ScalarTag
{
};
struct B65E760CheckedTag
{
};

B65E760Item* __cdecl B65E760Unchecked(B65E760Item** ppkIter);
B65E760Item* __cdecl FUN_0065ea80(B65E760Item* pkCurrentObject, B65E760Item* pkLast, B65E760Item* pkDest,
                                  B65E760IterCategory kCategory, B65E760ScalarTag kScalar, B65E760CheckedTag kChecked);

// @fnv 0x0065e760
B65E760Item* __cdecl FUN_0065e760(B65E760Item* pkCurrentObject, B65E760Item* pkLast, B65E760Item* pkDest)
{
    B65E760Item* pkResult = pkDest + (pkLast - pkCurrentObject);
    B65E760CheckedTag kChecked = {};
    B65E760ScalarTag kScalar = {};
    B65E760IterCategory kCategory4;
    FUN_0065ea80(pkCurrentObject, pkLast, B65E760Unchecked(&pkDest), kCategory4, kScalar, kChecked);
    return pkResult;
}

struct FUN_0065ee70 : FUN_0065cfb0
{
    ~FUN_0065ee70();
};
// Destructor that calls FUN_0065f430 on this object.
// @fnv 0x0065ee70
FUN_0065ee70::~FUN_0065ee70()
{
    ((FUN_0065f430_class*)this)->FUN_0065f430();
}

// Copy-style range helper: unwrap both iterators and forward them with the iterator-category and range tags.

struct EA0RangeTag
{
};
struct EA0CategoryTag
{
};

char* EA0Unwrap(char** ppcIter);
EA0CategoryTag EA0Category(char** ppcFirst, char** ppcDest);
char* EA0CopyImpl(char* pcFirst, char* pcLast, char* pcDest, int iCount, EA0CategoryTag kCategory, EA0RangeTag kRange);

// Copies iCount elements from the range [pcFirst, pcLast) to pcDest via EA0CopyImpl, unwrapping the iterators first.
// @fnv 0x0065fea0
char* FUN_0065fea0(char* pcFirst, char* pcLast, char* pcDest, int iCount)
{
    return EA0CopyImpl(EA0Unwrap(&pcFirst), EA0Unwrap(&pcLast), pcDest, iCount, EA0Category(&pcFirst, &pcDest),
                       EA0RangeTag());
}

struct FUN_00657b50 : FUN_0065d3a0
{
    FUN_00657b50();
};
// Constructs the object, passing FUN_006815c0() to the base constructor and then calling FUN_00657ee0(0) on this.
// @fnv 0x00657b50
FUN_00657b50::FUN_00657b50() : FUN_0065d3a0(FUN_006815c0())
{
    ((FUN_00657ee0_cls*)this)->FUN_00657ee0(0);
}

namespace c820 {
struct RCTag
{
};
struct InTag
{
};
struct FwdTag : InTag
{
};
struct BiTag : FwdTag
{
};
struct RaTag : BiTag
{
};
struct PtrCat
{
};
typedef Elem_65eed0* It;
PtrCat __cdecl FUN_0065e750(It& a, It& b);
RaTag __cdecl FUN_0065fd70(const It& a, const It& b);
It __cdecl ComputeIndexAndCall(int first, int last, It dest, RaTag cat, PtrCat pc, RCTag rc);
}
// Copies the elements in [first, last) to dest, choosing the copy strategy from the iterator category tags.
// @fnv 0x0065f820
Elem_65eed0* __cdecl FUN_0065f820(Elem_65eed0* first, Elem_65eed0* last, Elem_65eed0* dest)
{
    using namespace c820;
    return c820::ComputeIndexAndCall(CallWithFlag((int*)&first), CallWithFlag((int*)&last), dest,
                                     c820::FUN_0065fd70(first, dest), c820::FUN_0065e750(first, dest), RCTag());
}

namespace de {
struct RCTag
{
};
struct PtrCat
{
};
PtrCat __cdecl FUN_0065e750(int& a, int& b);
int __cdecl CopyRange(int first, int last, int dest, int al, PtrCat pc, RCTag rc);
}
// Calls CopyRange with CallWithFlag applied to first and last, dest, al, and FUN_0065e750(first, dest).
// @fnv 0x0065fde0
extern "C" void __cdecl FUN_0065fde0(int first, int last, int dest, int al)
{
    using namespace de;
    de::CopyRange(CallWithFlag(&first), CallWithFlag(&last), dest, al, de::FUN_0065e750(first, dest), RCTag());
}

struct TagA
{
    char v;
};

TagA* __cdecl FUN_0065fd70(TagA* flag, int* a, int* b);
int __cdecl FUN_0064e5a0(int a, int b, int c, TagA d, unsigned char e, TagA f);

// @fnv 0x0064e380
extern "C" int __cdecl FUN_0064e380(int arg1, int arg2, int arg3)
{
    TagA flag1 = {};
    char flag2 = FUN_0065e750(&arg1, &arg3);
    TagA flag3;

    return FUN_0064e5a0(CallWithFlag(&arg1), CallWithFlag(&arg2), arg3, *FUN_0065fd70(&flag3, &arg1, &arg3), flag2,
                        flag1);
}

int __cdecl CallWithFlag(int* p);

struct Tag
{
};

void __cdecl SpawnCallee6(int a1, int a2, int a3, Tag a4, Tag a5, Tag a6);

// @fnv 0x0064e5a0
int __cdecl FUN_0064e5a0(int a1, int a2, int a3)
{
    int value = (((a2 - a1) >> 4) << 4) + a3;
    Tag x1 = {};
    Tag xTmp = {};
    Tag x3;
    SpawnCallee6(a1, a2, CallWithFlag(&a3), x3, xTmp, x1);
    return value;
}

// Constructs count 16-byte elements at dst via obj->FUN_0064e7d0; on exception destroys already-built elements with FUN_0065e9a0 and rethrows.
// @fnv 0x0064e710
void __cdecl ConstructArrayWithRollback(char* apElements, unsigned int count, void* value, FUN_0064e7d0_class* obj)
{
    char* p = apElements;
    try
    {
        for (; count > 0; count--, apElements += 0x10)
        {
            obj->FUN_0064e7d0(apElements, value);
        }
    }
    catch (...)
    {
        for (; p != apElements; p += 0x10)
        {
            reinterpret_cast<FUN_0065e9a0_holder*>(obj)->FUN_0065e9a0((int*)p);
        }
        throw;
    }
}

struct Elem64e9
{
    char m_data[0x10];
};
struct Alloc64e9
{
    void FUN_0064e7d0(Elem64e9* pDest, const Elem64e9& kSrc);
    void FUN_0065e9a0(Elem64e9* pElem);
};
struct NonscalarTag64e9
{
};
struct CheckedTag64e9
{
};

// Copy-constructs each element of [_First, _Last) into _Dest via _Al, destroying already-built elements and rethrowing on exception.
// @fnv 0x0064e9c0
Elem64e9* __cdecl FUN_0064e9c0(Elem64e9* _First, Elem64e9* _Last, Elem64e9* _Dest, Alloc64e9& _Al, NonscalarTag64e9,
                               CheckedTag64e9)
{
    Elem64e9* _Next = _Dest;
    try
    {
        for (; _First != _Last; ++_Dest, ++_First)
            _Al.FUN_0064e7d0(_Dest, *_First);
    }
    catch (...)
    {
        for (; _Next != _Dest; ++_Next)
            _Al.FUN_0065e9a0(_Next);
        throw;
    }
    return _Dest;
}

class BSFaceGenModelExtraData : public NiMemObject
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    BSFaceGenModelExtraData(int);
};
class NiRefObject
{
  public:
    void IncRefCount();
    void DecRefCount();
};

class NiExtraData;

class NiObject : public NiRefObject
{
  public:
    virtual ~NiObject();
    NiObject* Clone();
    void ResolveObjectPointer(NiPointer<NiObject>& spCopy);
};

class NiObjectNET : public NiObject
{
  public:
    bool AddExtraData(NiExtraData* pExtraData);
};

class NiGeometryData : public NiObject
{
  public:
};

class NiGeometry : public NiObjectNET
{
  public:
    NiGeometryData* FUN_005495f0();
    virtual void vfn00();
    virtual void vfn01();
    virtual void vfn02();
    virtual void vfn03();
    virtual void vfn04();
    virtual void vfn05();
    virtual void vfn06();
    virtual void vfn07();
    virtual void vfn08();
    virtual void vfn09();
    virtual void vfn0a();
    virtual void vfn0b();
    virtual void vfn0c();
    virtual void vfn0d();
    virtual void vfn0e();
    virtual void vfn0f();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn1a();
    virtual void vfn1b();
    virtual void vfn1c();
    virtual void vfn1d();
    virtual void vfn1e();
    virtual void vfn1f();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn2a();
    virtual void vfn2b();
    virtual void vfn2c();
    virtual void vfn2d();
    virtual void vfn2e();
    virtual void vfn2f();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void ReplaceModelData(NiGeometryData* pData);
};

class NiSkinPartition : public NiObject
{
  public:
};

class NiSkinInstance
{
  public:
    NiSkinPartition* FUN_0043b230();
    void FUN_004addc0(NiSkinPartition* pPartition);
};

class NiTriBasedGeom : public NiGeometry
{
  public:
    NiSkinInstance* FUN_0043fad0();
};

class FUN_006624c0 : public NiMemObject
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_006624c0(NiTriBasedGeom* pGeom, int a2, int a3);
};

struct FaceGenModelData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    NiPointer<NiGeometry> spGeom;
    int unk14;
    int unk18;
};

class BSFaceGenModel
{
  public:
    int unk00;
    int unk04;
    FaceGenModelData* unk08;

    bool CloneTriBasedGeom(NiPointer<NiTriBasedGeom>& out);
};

// Clones the model's geometry, copies its geometry data and skin partition, attaches extra data, and returns true on success.
// @fnv 0x0065bbc0
bool BSFaceGenModel::CloneTriBasedGeom(NiPointer<NiTriBasedGeom>& out)
{
    NiPointer<NiGeometryData> spModelData;
    NiPointer<NiSkinPartition> spSkinPartition;

    out = 0;
    if (!unk08 || !unk08->spGeom || !unk08->spGeom->FUN_005495f0())
    {
        return false;
    }

    out = (NiTriBasedGeom*)unk08->spGeom->Clone();

    NiPointer<NiObject> spDataCopy3;
    unk08->spGeom->FUN_005495f0()->ResolveObjectPointer(spDataCopy3);
    spModelData = (NiGeometryData*)(NiObject*)spDataCopy3;
    out->ReplaceModelData(spModelData);

    NiSkinInstance* pObjectInstance = out->FUN_0043fad0();
    if (pObjectInstance && pObjectInstance->FUN_0043b230())
    {
        NiPointer<NiObject> spPartitionCopy;
        pObjectInstance->FUN_0043b230()->ResolveObjectPointer(spPartitionCopy);
        spSkinPartition = (NiSkinPartition*)(NiObject*)spPartitionCopy;
        pObjectInstance->FUN_004addc0(spSkinPartition);
    }

    FUN_006624c0* pExtra3 = new FUN_006624c0(out, unk08->unk14, unk08->unk18);
    if (pExtra3)
    {
        out->AddExtraData((NiExtraData*)pExtra3);
    }

    out->AddExtraData((NiExtraData*)(void*)new BSFaceGenModelExtraData((int)this));
    return true;
}

struct VecItem1C
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18;
};

struct VecItemAllocator
{
    unsigned int m_00;
    VecItem1C* allocate(unsigned int _Count);
};

struct VecItemVector
{
    unsigned int m_00;
    unsigned int m_04;
    VecItemAllocator _Alval;
    VecItem1C* _Myfirst;
    VecItem1C* _Mylast;
    VecItem1C* _Myend;

    unsigned int max_size() const;
    static void _Xlen();
    bool FUN_0065d7e0(unsigned int _Capacity);
};

// Resets the vector pointers and allocates storage for _Capacity items, returning false when _Capacity is zero.
// @fnv 0x0065d7e0
bool VecItemVector::FUN_0065d7e0(unsigned int _Capacity)
{
    _Myfirst = 0, _Mylast = 0, _Myend = 0;
    if (_Capacity == 0)
        return (false);
    else if (max_size() < _Capacity)
        _Xlen();
    else
    {
        _Myfirst = this->_Alval.allocate(_Capacity);
        _Mylast = _Myfirst;
        _Myend = _Myfirst + _Capacity;
    }
    return (true);
}

struct S_0065fb10_Elem
{
    short a;
    short b;
    short c;
};
struct S_0065fb10_Alloc
{
    S_0065fb10_Alloc(const S_0065fb10_Alloc&);
};
struct S_0065fb10_Iter
{
    S_0065fb10_Elem* ptr;
    void* cont;
};
struct S_0065fb10_Base
{
    int unk00;
    int unk04;
    S_0065fb10_Alloc _Alval;
    S_0065fb10_Elem* _Myfirst;
    S_0065fb10_Elem* _Mylast;
    S_0065fb10_Elem* _Myend;
    S_0065fb10_Base(S_0065fb10_Alloc al);
    ~S_0065fb10_Base();
    unsigned int FUN_00657bc0() const;
    bool FUN_0065f380(unsigned int n);
    S_0065fb10_Iter FUN_0065fd10() const;
    S_0065fb10_Iter FUN_0065fd40() const;
    S_0065fb10_Elem* FUN_0065ff30(S_0065fb10_Iter first, S_0065fb10_Iter last, S_0065fb10_Elem* dest);
    void FUN_0065f430();
};
struct FUN_0065fb10 : S_0065fb10_Base
{
    FUN_0065fb10(const FUN_0065fb10& other);
};
// @fnv 0x0065fb10
FUN_0065fb10::FUN_0065fb10(const FUN_0065fb10& other) : S_0065fb10_Base(other._Alval)
{
    if (FUN_0065f380(other.FUN_00657bc0()))
    {
        try
        {
            _Mylast = FUN_0065ff30(other.FUN_0065fd10(), other.FUN_0065fd40(), _Myfirst);
        }
        catch (...)
        {
            FUN_0065f430();
            throw;
        }
    }
}

struct Base64ce20
{
    virtual void Slot00();
    unsigned int unk04;
    ~Base64ce20();
};

struct ObjectPointer64ce20
{
    void* m_object;
    ObjectPointer64ce20& operator=(void* object);
    ~ObjectPointer64ce20();
};

struct Vector64ce20
{
    void* m_pHeadNode;
    void* m_last;
    void* m_kRayEnd;
    void FUN_0064db70();
    ~Vector64ce20();
};

struct FUN_0064ce20 : Base64ce20
{
    ObjectPointer64ce20 m_object;
    Vector64ce20 m_iSlotIds;
    ~FUN_0064ce20();
};

// Calls FUN_0064db70 on m_iSlotIds, then sets m_object to 0.
// @fnv 0x0064ce20
FUN_0064ce20::~FUN_0064ce20()
{
    m_iSlotIds.FUN_0064db70();
    m_object = 0;
}

struct ItE4E0
{
    int* m_ptr;
};

struct RangeTagE4E0
{
};

struct CatTagE4E0
{
};

struct PtrCatE4E0
{
    PtrCatE4E0()
    {}
};

CatTagE4E0 __cdecl FUN_0065e750(const ItE4E0& it);
PtrCatE4E0 __cdecl FUN_0065fd70(const ItE4E0& a, const ItE4E0& b);
int* __cdecl CallWithFlag(ItE4E0& it);
void __cdecl FUN_0064e6c0(int* pFirst, int* pLast, ItE4E0 kDest, PtrCatE4E0 kPtrCat, CatTagE4E0 kCat,
                          RangeTagE4E0 kRange);

// Calls FUN_0064e6c0 with the raw pointers from kFirst and kLast, kDest, and tags computed from kFirst, kDest and a range tag.
// @fnv 0x0064e4e0
void __cdecl FUN_0064e4e0(ItE4E0 kFirst, ItE4E0 kLast, ItE4E0 kDest)
{
    FUN_0064e6c0(CallWithFlag(kFirst), CallWithFlag(kLast), kDest, FUN_0065fd70(kFirst, kDest), FUN_0065e750(kDest),
                 RangeTagE4E0());
}

struct Allocator65C750
{
    Allocator65C750();
    Allocator65C750(const Allocator65C750& kOther);
    int unk00;
};
struct Base65C750
{
    Base65C750(Allocator65C750 kAllocator);
    ~Base65C750();
    int unk00;
};
struct FUN_0065c750 : public Base65C750
{
    FUN_0065c750();
    void Init(int iCount);
};

// @fnv 0x0065c750
FUN_0065c750::FUN_0065c750() : Base65C750(Allocator65C750())
{
    Init(0);
}

struct ItQ
{
    int* p;
    int c;
};
struct FUN_0065fc10 : FUN_0065d3a0
{
    int unk00;
    int unk04;
    int m_al;
    int* m_pHeadNode;
    int* m_last;
    int* m_kRayEnd;
    int FUN_0065cc50();
    bool FUN_00657ee0(unsigned int n);
    ItQ FUN_0065fd40();
    ItQ FUN_0065fd10();
    int* FUN_0065ff60(ItQ f, ItQ l, int* d);
    void FUN_00657f60();
    FUN_0065fc10(FUN_0065fc10& r);
};
// Constructs the base from r.m_al; if FUN_00657ee0(r.FUN_0065cc50()) is true, sets m_last via FUN_0065ff60, calling FUN_00657f60 on exception.
// @fnv 0x0065fc10
FUN_0065fc10::FUN_0065fc10(FUN_0065fc10& arSource) : FUN_0065d3a0(*(FUN_006815c0*)&arSource.m_al)
{
    if (FUN_00657ee0(arSource.FUN_0065cc50()))
    {
        try
        {
            m_last = FUN_0065ff60(arSource.FUN_0065fd10(), arSource.FUN_0065fd40(), m_pHeadNode);
        }
        catch (...)
        {
            FUN_00657f60();
            FUN_00ec7894(0, 0);
        }
    }
}

class FloatSource
{
  public:
    float FUN_006a78f0();
};
struct FloatGetterGlobal
{
    float* FUN_00403e20();
};
extern FloatGetterGlobal DAT_011cfb5c, DAT_011cf264;
// Returns the value from src scaled by the sum of two global float values, or 0.0f if src is null.
// @fnv 0x006479e0
float FUN_006479e0(FloatSource* src)
{
    float result;
    if (src != 0)
        result = src->FUN_006a78f0();
    else
        result = 0.0f;
    float factor = result;
    factor = (*DAT_011cf264.FUN_00403e20() + (+*DAT_011cfb5c.FUN_00403e20())) * factor;
    return factor;
}

namespace ctor_0065c8f0 {

struct FUN_006815c0
{
    FUN_006815c0();
    FUN_006815c0(const FUN_006815c0& other);
};

struct FUN_0065d3a0
{
    FUN_0065d3a0(FUN_006815c0 al) throw();
    ~FUN_0065d3a0();
    void FUN_0065d2b0(int value);
};

struct FUN_0065c8f0 : FUN_0065d3a0
{
    FUN_0065c8f0();
};

// Constructs a FUN_0065c8f0 object by delegating to the base FUN_0065d3a0 with a default FUN_006815c0 and calling FUN_0065d2b0 with 0.
// @fnv 0x0065c8f0
FUN_0065c8f0::FUN_0065c8f0() : FUN_0065d3a0(FUN_006815c0())
{
    FUN_0065d2b0(0);
}

}

namespace ctor_0065d3a0 {

struct FUN_0065de30
{
    FUN_0065de30(const FUN_0065de30& other);
};

struct RebindAllocator
{
    RebindAllocator(const FUN_0065de30& other);
    ~RebindAllocator();
};

struct FUN_0065dc90
{
    int unk00;
    int unk04;
    FUN_0065dc90(RebindAllocator al) throw();
};

struct FUN_0065d3a0 : FUN_0065dc90
{
    FUN_0065de30 alval;
    FUN_0065d3a0(FUN_0065de30 al) throw();
};

// Constructs a FUN_0065d3a0 object by delegating to the FUN_0065dc90 base and copying the FUN_0065de30 argument into alval.
// @fnv 0x0065d3a0
FUN_0065d3a0::FUN_0065d3a0(FUN_0065de30 al) throw() : FUN_0065dc90(al), alval(al)
{}

}

struct Elem6_f380
{
    short a, b, c;
};
struct Alloc_f380
{
    Elem6_f380* FUN_0065f6c0(unsigned int n);
};
void __cdecl ThrowVectorTooLong();
struct VecF380
{
    int unk00;
    int unk04;
    Alloc_f380 _Alval;
    Elem6_f380* _Myfirst;
    Elem6_f380* _Mylast;
    Elem6_f380* _Myend;
    unsigned int FUN_0065f580() const;
    bool FUN_0065f380(unsigned int _Capacity);
};
// Resets first/last/end pointers; returns false if _Capacity is 0, throws if it exceeds FUN_0065f580(), else allocates that many elements and returns true.
// @fnv 0x0065f380
bool VecF380::FUN_0065f380(unsigned int _Capacity)
{
    _Myfirst = 0;
    _Mylast = 0;
    _Myend = 0;
    if (_Capacity == 0)
        return false;
    else if (FUN_0065f580() < _Capacity)
        ThrowVectorTooLong();
    else
    {
        _Myfirst = _Alval.FUN_0065f6c0(_Capacity);
        _Mylast = _Myfirst;
        _Myend = _Myfirst + _Capacity;
    }
    return true;
}

#include <math.h>
template <class Collection> class SettingT
{
  public:
    float* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting86;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting87;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting90;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting92;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting93;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting97;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting98;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting99;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting100;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting101;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting102;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting150;
extern GlobalObject_0040e0b0 g_011cd080;
extern GlobalObject_0040e0b0 g_011cdb84;
float FUN_00404010(float, float);

// Sums a base setting with distance-falloff terms for quantity, value, level and resistance and returns it as int; a total between 0 and 1 becomes 1.
// @fnv 0x00642bc0
int __cdecl FUN_00642bc0(int skill, int count, float distance, int resistance, int level, bool flagA, bool flagB,
                         bool flagC, int quantity, int value, bool special)
{
    int d;      // Third boolean modifier.
    int n;      // Whether count is positive.
    int l = 0;  // Final integer result.
    // Total contribution, starting at the base setting.
    float c = *originalRuntimeFloatSetting86.Float();
    // Second boolean modifier.
    int e = 0;
    // First boolean modifier.
    int i = 0;
    d = 0;
    if (flagB)
        e = 1;
    if (flagA)
        i = 1;
    if (flagC)
        d = 1;
    // Skill contribution.
    float m = *originalRuntimeFloatSetting99.Float() +
              (*originalRuntimeFloatSetting100.Float() - *originalRuntimeFloatSetting99.Float()) * (skill / 10.0f);
    m *= 1.0f + e * *originalRuntimeFloatSetting98.Float() + i * *originalRuntimeFloatSetting97.Float() +
         d * *originalRuntimeFloatSetting150.Float();
    // Item value.
    int k = value;
    n = 0;
    if (count > 0)
        n = 1;
    // Effective range.
    float a = special ? *originalRuntimeFloatSetting101.Float() * *originalRuntimeFloatSetting87.Float()
                      : *originalRuntimeFloatSetting87.Float();
    // Range attenuation.
    float g = FUN_00404010((a - distance) / a, 0.0f);
    g = pow((double)g, (double)*originalRuntimeFloatSetting102.Float());
    // Attenuation adjusted for count.
    float j = g;
    if (!n)
        j = g * *originalRuntimeFloatSetting90.Float();
    // Scaled quantity.
    int o = (int)*g_011cd080.Float() * quantity;
    // Quantity contribution.
    float q = FUN_00404010(j * *originalRuntimeFloatSetting93.Float() * o, 0.0f);
    // Level contribution multiplier.
    float p = (*g_011cdb84.Float() + level) * *originalRuntimeFloatSetting92.Float();
    // Resistance multiplier, using integer division.
    float h = (100 - resistance) / 100;
    // Value contribution.
    float b = FUN_00404010(k * g * p * h, 0.0f);
    // Attenuated skill contribution.
    float f = m * g;
    c = c + q + b;
    if (c < 1.0 && c > 0.0)
        l = 1;
    else
        l = (int)c;
    return l;
}

struct FUN_006443d0 : GlobalObject_00869f00
{
    virtual ~FUN_006443d0();
};
// @fnv 0x006443d0
FUN_006443d0::~FUN_006443d0()
{}

namespace fnv_006592f0 {
extern "C" void __cdecl FUN_00659360(int);

struct FUN_006592f0_Class
{
    void __thiscall FUN_006592f0(int a);
};

// @fnv 0x006592f0
void __thiscall FUN_006592f0_Class::FUN_006592f0(int a)
{
    FUN_00659360(a);
}
}  // namespace fnv_006592f0

namespace fnv_00659310 {
extern "C" int __cdecl FUN_00659370(int);

struct FUN_00659310_Class
{
    int __thiscall FUN_00659310(int a);
};

// @fnv 0x00659310
int __thiscall FUN_00659310_Class::FUN_00659310(int a)
{
    return FUN_00659370(a);
}
}  // namespace fnv_00659310

struct BGSLoadGameBuffer;
struct Interface
{
    static void __cdecl PrintDebugMessage(BGSLoadGameBuffer*);
};
struct FUN_0065e9a0_Class
{
    void __thiscall FUN_0065e9a0(BGSLoadGameBuffer* p);
};
// @fnv 0x0065e9a0
void __thiscall FUN_0065e9a0_Class::FUN_0065e9a0(BGSLoadGameBuffer* apBuffer)
{
    Interface::PrintDebugMessage(apBuffer);
}

void __cdecl FUN_0065eb20(void*);

struct FUN_0065ea00_Class
{
    void __thiscall FUN_0065ea00(void* a);
};

// @fnv 0x0065ea00
void __thiscall FUN_0065ea00_Class::FUN_0065ea00(void* apObj)
{
    FUN_0065eb20(apObj);
}

namespace fnv_0065ec40 {
extern "C" void __cdecl Deallocate(void*);
struct FUN_0065ec40_Class
{
    void FUN_0065ed50();
    void* FUN_0065ec40(unsigned int flags);
};
// Calls FUN_0065ed50, then if the low bit of flags is set calls Deallocate on this and returns this.
// @fnv 0x0065ec40
void* FUN_0065ec40_Class::FUN_0065ec40(unsigned int flags)
{
    FUN_0065ed50();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}  // namespace fnv_0065ec40

namespace fnv_0065ec70 {
struct FUN_0065ec70_class
{
    void __thiscall FUN_0065ed70();
    void* __thiscall FUN_0065ec70(unsigned int flags);
};

// @fnv 0x0065ec70
void* __thiscall FUN_0065ec70_class::FUN_0065ec70(unsigned int flags)
{
    FUN_0065ed70();
    if (flags & 1)
        operator delete(this);
    return this;
}
}  // namespace fnv_0065ec70

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
struct GridStorage
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    GridStorage();
    ~GridStorage();
    void Allocate(unsigned int);
    unsigned int Size() const;
    void* At(unsigned int) const;
};
struct FUN_00658f30 : GridStorage
{
    unsigned int rows, columns;
    FUN_00658f30(const FUN_00658f30&);
};
// Copies rows and columns from other, allocates storage, and memcpys the grid data if both instances have allocated memory.
// @fnv 0x00658f30
FUN_00658f30::FUN_00658f30(const FUN_00658f30& other) : rows(other.rows), columns(other.columns)
{
    Allocate(rows * columns);
    if (Size() && other.Size())
        memcpy(At(0), other.At(0), rows * columns * sizeof(unsigned int));
}
