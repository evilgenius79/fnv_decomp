
// blk_00640000_od_ctx_variant.cpp: context variant of src/staging/blk_00640000_od.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
// src/staging/blk_00640000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
struct FUN_006427a0_Class
{
    void SetValue(float value);
};
struct FUN_00642890_Class
{
    void FUN_00642890();
};
struct GlobalObject_0040e0b0
{
    float* Float();
};
GlobalObject_0040e0b0 g_011ce00c;
float ScaleByGlobalFloat(float value);
struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting289;
extern double DAT_01011588;
float AddScaledSetting(float a);
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
struct FUN_00644790_class
{
    float FUN_00644790();
};
struct FUN_00645c20_Class
{
    unsigned short GetShortAtOffset1C0();
};
struct FUN_00645c80_Class
{
    bool __thiscall IsFlagSet() const;
};
struct FUN_00645ca0_Class
{
    float GetField14C();
};
struct FUN_00645cc0_class
{
    float GetField150Float();
};
struct FUN_00645ce0_class
{
    float GetField154();
};
struct FUN_00647ac0_Class
{
    unsigned char GetByteAt0x62();
};
struct FUN_0064db00_class
{
    int FUN_0064dc30();
    bool FUN_0064db00();
};
struct FUN_0064db50_class
{
    void __thiscall ApplyToCopy(int a, int b);
    void __thiscall FUN_0064db50(int a, int b);
};
struct FUN_0064dbd0_Class
{
    void FUN_0064dda0();
    void FUN_0064dbd0();
};
struct FUN_0064dc30_class
{
    int __thiscall FUN_0064dc30();
};
struct FUN_0064de50_class
{
    void InitAndReturn();
    void* FUN_0064de50();
};
struct CF_0081c630
{
    void Init();
};
void CF_0081c630::Init()
{}
CF_0081c630* __fastcall InitAndReturn(CF_0081c630* p);
extern "C" void __cdecl FUN_0064e2d0();
struct FUN_0064de90_class
{
    void __thiscall FUN_0064de90();
};
struct FUN_0064deb0_Class
{
    void Insert(int, int, int, int);
    void ForwardToFUN0064df50(int a, int b, int c, int d);
};
extern "C" void __cdecl FUN_0064e3f0(int, int, int);
struct FUN_0064dee0_Class
{
    void __thiscall ForwardToHelper(int, int);
};
extern "C" void __cdecl FUN_0064e430(int, int);
struct FUN_0064df30_class
{
    void __thiscall FUN_0064df30(int a);
};
extern "C" void __cdecl FUN_0064e630(void* a, void* b, void* c, void* d);
struct FUN_0064e480_Class
{
    void __thiscall FUN_0064e480(void* a, void* b, void* c);
};
struct FUN_0065e9a0_holder
{
    void FUN_0065e9a0(int* p);
};
void FUN_0064e600(int* a, int* b, FUN_0065e9a0_holder* c);
extern "C" void __cdecl CopyConstructBlock(void*, void*);
struct FUN_0064e7d0_class
{
    void __thiscall FUN_0064e7d0(void* a, void* b);
};
extern "C" void __cdecl FUN_0064e920(int, int, int, int);
void __cdecl ForwardToHandler(int a, int b, int c, int d);
struct DecalStub
{
    void FUN_004bc480(int);
    float m_f;
    void FUN_00654700(float f);
};
struct FUN_00657880_class
{
    bool FUN_00658160(int);
    bool operator==(int other);
};
struct FUN_00657be0_class
{
    int a;
    int b;
    void AddToA();
};
struct FUN_00658100
{
    void __thiscall Method_00658100();
};
struct FUN_00657fd0
{
    void __thiscall Method_00657fd0();
};
extern "C" void __cdecl FUN_00658bd0(int a1, int a2, int a3);
struct FUN_00657ff0_Class
{
    void FUN_00657ff0(int a1, int a2);
};
extern "C" void __cdecl FUN_00658c10(int a, int b);
struct FUN_00658020_Class
{
    void __thiscall FUN_00658020(int a);
};
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
extern "C" void __cdecl FUN_00658c60(int, int, int);
struct FUN_00658060_Class
{
    void __thiscall FUN_00658060(int a, int b);
};
void __cdecl FUN_00658ca0(int a, int b);
struct FUN_00658090_Class
{
    void __thiscall FUN_00658090(int a);
};
struct FUN_00658930_class
{
    unsigned int GetShortAtOffsetA() const;
};
extern "C" void __cdecl FUN_00659230(int, int);
extern int DAT_01065870;
struct FUN_00658aa0_class
{
    void* vtbl;
    void FUN_00659230(int a, int b);
    FUN_00658aa0_class* __thiscall Initialize(int a, unsigned char b);
};
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
struct FUN_00658d30_class
{
    void __thiscall FUN_00658d50();
    void __thiscall FUN_00658d30();
};
struct FUN_00659170
{
    void FUN_00659190();
    FUN_00659170();
};
struct FUN_00659210_Class
{
    int __thiscall FUN_00659210(char a, int b);
};
struct FUN_006592f0
{
    void __thiscall operator()(void*);
};
void FUN_00659260(void* a, void* b, FUN_006592f0* c);
struct FUN_00659310_
{
    void __thiscall FUN_00659310(void*);
};
void __cdecl ForEachItem(void* obj, void* end, FUN_00659310_* item);
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
extern "C" void* DAT_00fdf07c;
struct FUN_00659540_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void FUN_00659540();
};
struct FUN_0065cc30_class
{
    int __thiscall FUN_0065cc30();
};
struct FUN_0065cc50_Class
{
    int FUN_0065cc50();
};
struct FUN_0065cea0_class
{
    int __thiscall FUN_0065cea0();
};
struct FUN_0065cf90_class
{
    void FUN_0065db40();
    void* FUN_0065cf90();
};
struct FUN_0065cfb0_Class
{
    void __thiscall FUN_0065d6e0();
    void __thiscall FUN_0065cfb0();
};
struct FUN_0065db40_class
{
    void FUN_0064de50();
    void* FUN_0065db40();
};
void __cdecl FUN_0065e2d0(int, int, int);
struct FUN_0065db60_class
{
    void __thiscall FUN_0065db60(int a, int b);
};
struct FUN_0065e020_class
{
    void __thiscall FUN_0065e020();
};
struct FUN_0065db90_class
{
    void __thiscall FUN_0065db90();
};
extern "C" void __cdecl FUN_0065e310(int, int);
struct FUN_0065dbb0_class
{
    void __thiscall FUN_0065dbb0(int arg);
};
extern "C" void __cdecl FUN_0065e360(int, int, int);
struct FUN_0065dbf0_class
{
    void CallWithThisOffset(int a, int b);
};
extern "C" void __cdecl FUN_0065e3a0(int, int);
struct FUN_0065dc20_class
{
    void __thiscall FUN_0065dc20(int a);
};
extern "C" void __cdecl FUN_0065e3f0(int a, int b, int c);
struct FUN_0065dc60Class
{
    void FUN_0065dc60(int a, int b);
};
extern "C" void __cdecl FUN_0065e430(int, int);
struct FUN_0065dd50_Class
{
    void __thiscall FUN_0065dd50(int a);
};
struct FUN_0065dd70_Class
{
    void __thiscall FUN_0065dd70();
};
extern "C" void __cdecl FUN_0065e0b0(void*);
extern "C" void __cdecl FUN_0065e4c0(int, int);
struct FUN_0065ddc0_class
{
    void __thiscall FUN_0065ddc0(int a);
};
struct FUN_0065dde0_Class
{
    void FUN_0065e0e0();
    void FUN_0065dde0();
};
extern "C" void __cdecl FUN_0065e510(int, int, int);
struct FUN_0065de00_Class
{
    void FUN_0065de00(int a, int b);
};
extern "C" void __cdecl FUN_0065e5a0(int, int, int);
struct FUN_0065de80_Class
{
    void FUN_0065de80(int a, int b);
};
extern "C" void __cdecl FUN_0065e5e0(int, int);
struct FUN_0065deb0_Class
{
    void __thiscall FUN_0065deb0(int arg);
};
extern "C" void __cdecl FUN_0065e630(void*, void*, void*);
struct FUN_0065df10_class
{
    void __thiscall FUN_0065df10(void* b, void* c);
};
void __cdecl FUN_0065e670(int a, int b);
struct FUN_0065df40_class
{
    void __thiscall FUN_0065df40(int a);
};
struct FUN_0065df60_class
{
    void FUN_0065e170();
    void FUN_0065df60();
};
extern "C" void __cdecl CallWithByteResult(int, int, int);
struct FUN_0065df80_class
{
    void __thiscall FUN_0065df80(int a, int b);
};
struct FUN_0065dfb0_Class
{
    void __thiscall FUN_0065dfb0(int a);
};
extern "C" void __cdecl FUN_0065e700(int a, int b);
struct FUN_0065dfd0_class
{
    bool __thiscall FUN_0065e1a0(int);
    bool __thiscall FUN_0065dfd0(int);
};
struct FUN_0065e000_class
{
    int __thiscall FUN_0065da80(int a, int b);
    int __thiscall FUN_0065e000(int a, int b);
};
struct FUN_0065e9a0
{
    void __thiscall Destroy(void* p);
};
void FUN_0065e820(void* a, void* b, FUN_0065e9a0* c);
struct FUN_0065e9a0_t
{
    void __thiscall FUN_0065e9a0(void*);
};
void __cdecl FUN_0065e850(void* a, void* b, void* c);
struct FUN_0065ea00_class
{
    void __thiscall FUN_0065ea00(void*);
};
void __cdecl FUN_0065e8e0(void* first, void* last, FUN_0065ea00_class* obj);
struct FUN_0065ea60_class
{
    void __thiscall FUN_0065ea60(void*);
};
void FUN_0065e970(void* p, void* e, void* obj);
extern "C" void __cdecl FUN_0065eb00(int);
struct FUN_0065e9c0_class
{
    void __thiscall FUN_0065e9c0(int arg);
};
extern "C" void __cdecl FUN_0065eb10(void*);
struct FUN_0065e9e0_Class
{
    void __thiscall FUN_0065e9e0(void* a);
};
extern "C" void __cdecl FUN_0065eb30(int);
struct FUN_0065ea20_Class
{
    void __thiscall FUN_0065ea20(int a);
};
void FUN_0065eb40(int a);
struct FUN_0065ea40_class
{
    void FUN_0065ea40(int a);
};
void __cdecl FUN_0065eb50(void* a);
struct FUN_0065ea60_cls
{
    void __thiscall FUN_0065ea60(void* a);
};
struct FUN_0065ee70_class
{
    void __thiscall FUN_0065ee70();
};
struct FUN_0065ee30_class
{
    void __thiscall FUN_0065ee30();
};
extern "C" void __cdecl CallInterfaceWithResult(int, int, int);
struct FUN_0065f2b0_class
{
    void __thiscall FUN_0065f2b0(int a, int b);
};
extern "C" void __cdecl FUN_0065f9a0(int, int, int);
struct FUN_0065f400_class
{
    void __thiscall FUN_0065f400(int a, int b);
};
struct FUN_0065f7c0_Class
{
    void FUN_0065f7c0();
};
struct FUN_0065f580_Class
{
    void FUN_0065f580();
};
extern "C" void __cdecl FUN_0065f9e0(int a, int b);
struct FUN_0065f6c0_class
{
    void __thiscall FUN_0065f6c0(int a);
};
extern "C" void* __cdecl AllocateChecked(void*, void*);
struct FUN_0065f7a0_Class
{
    void* __thiscall FUN_0065f7a0(void* arg);
};
extern "C" void __cdecl FUN_0065fde0(int, int, int, int);
struct FUN_0065f890_class
{
    void __thiscall FUN_0065f890(int a1, int a2, int a3);
};
extern "C" void __cdecl FUN_0065fea0(int, int, int, int);
struct FUN_0065f930_Class
{
    void __thiscall FUN_0065f930(int a, int b, int c);
};
extern "C" void _NiFreeAlias(void*);
extern void* DAT_010658d0;
struct FUN_00658e70_cls : public NiTPointerMap<int, int>
{
    void FUN_00658e70();
};
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
struct GameSettingCollection
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetFloat(unsigned int index);
};
extern Setting_S originalRuntimeFloatSetting332;
extern Setting_S originalRuntimeFloatSetting333;
float FUN_00643ed0(GameSettingCollection* collection, int index);
struct FUN_00644350_Class
{
    bool IsGreaterThan(int a);
};
int CompareObjects(int a, int b);
void* __cdecl operator new(unsigned int size, void* placement);
struct FUN_00644490_Class
{
    void __thiscall FUN_00644490(char* items, unsigned int count);
};
struct FUN_006444e0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_C;
    void* __thiscall FUN_006444e0(int a, int b, int c, int d);
};
GlobalObject_0040e0b0 g_011ce840;
GlobalObject_0040e0b0 g_011cfd8c;
float FUN_006463a0(int value);
void __cdecl ClampUInt(unsigned int* p, unsigned int low, unsigned int high);
struct ActorValueOwner
{
    float GetActorValueFloatByIndex(ActorValue::Index);
};
extern double g_d100;
extern Setting_S g_011d17d0;
extern Setting_S originalRuntimeFloatSetting1216;
float __cdecl FUN_00649530(ActorValueOwner* p);
struct S_0064dac0
{
    int __thiscall FUN_0064dac0(int, int);
};
unsigned int __cdecl FUN_00ec7c56(void);
struct FUN_0064db20_Class
{
    void* __thiscall GetEntryAt(unsigned int a);
};
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
struct FUN_0064e2d0_Holder
{
    unsigned int __thiscall FUN_0064e2d0() const;
};
struct FUN_0064e300_Class
{
    int __thiscall FUN_0064e300();
};
extern "C" void __cdecl FUN_0064e550(int a, int b, int c, void* d);
struct FUN_0064e340_class
{
    void* __thiscall FUN_0064e340(int a, int b, int c);
};
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
void __cdecl FUN_0064e4b0(int a, int b, int c);
struct FUN_0064e680_S
{
    int m0;
    int m1;
    int m2;
    int m3;
};
void FUN_0064e680(FUN_0064e680_S* a, FUN_0064e680_S* b, FUN_0064e680_S* c);
struct FUN_0064e7f0_S
{
    int f0;
    int f4;
    int f8;
    int fC;
};
FUN_0064e7f0_S* __cdecl CopyStructRange(FUN_0064e7f0_S* a, FUN_0064e7f0_S* b, FUN_0064e7f0_S* c);
struct FUN_0064e980_Block
{
    int m0;
    int m4;
    int m8;
    int mC;
};
void* __cdecl CopyBlocksBackward(void* a, FUN_0064e980_Block* b, FUN_0064e980_Block* c);
struct BSFaceGenManager
{
    static void* __stdcall GetFaceGenManager(float a1, int a2, int a3);
};
struct Holder00aad6b0
{
    void __thiscall FUN_00aad6b0();
};
void __cdecl FUN_00652fc0(float a1, int a2, int a3);
struct Class_00658100
{
    unsigned int __thiscall FUN_00658100();
};
struct Dummy658130
{
    unsigned __thiscall FUN_00658130();
};
unsigned char __cdecl FUN_0065e750(void*, void*);
void __cdecl FUN_00659260(int, int, int, unsigned char);
void FUN_00658bd0(int a1, int a2, int a3);
void __cdecl operator delete(void* p);
struct FUN_00658bb0_Class
{
    void __thiscall FUN_00658bb0();
};
struct FUN_00658d00_Class
{
    void* __thiscall FUN_00658d00(unsigned int flags);
};
void _Deallocate(void*);
struct FUN_00658ea0_cls
{
    void* __thiscall FUN_00658ea0(unsigned int);
};
void __cdecl operator delete(void* p);
struct FUN_00658ed0_Class
{
    void __thiscall FUN_00658e10();
    void* __thiscall FUN_00658ed0(unsigned int flags);
};
struct FUN_00658f00_Class : public FUN_00658d30_class
{
    FUN_00658f00_Class* __thiscall FUN_00658f00(unsigned int flags);
};
struct Pair590
{
    int a;
    int b;
};
struct S_006590c0
{
    void* __thiscall CopyPairTo(void* p, int q);
};
struct FUN_006a68b0_Class
{
    void FUN_006a68b0();
};
void __cdecl operator delete(void*);
struct FUN_00659140_Class
{
    void* __thiscall FUN_00659140(unsigned int flags);
};
extern int DAT_010658f0;
struct FUN_00659230
{
    void* vptr;
    void __thiscall InitializeWithGlobal(int a, unsigned char b);
    FUN_00659230(int a, unsigned char b);
};
void _Deallocate(void*);
struct S_006592c0
{
    void* FUN_006592c0(unsigned int flags);
};
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
struct FUN_00659380_cls
{
    void __thiscall FUN_00659380(int a);
};
void __cdecl FUN_00659360(int a);
struct FUN_006593b0_class
{
    void __thiscall FUN_006593b0(int a);
};
void __cdecl FUN_00659370(int a);
void __cdecl operator delete(void*);
struct FUN_00659380_class
{
    void __thiscall FUN_006593e0();
    void* __thiscall FUN_00659380(unsigned int flags);
};
void __cdecl Deallocate(void*);
struct FUN_00659440_Class
{
    void __thiscall FUN_00659440();
};
struct FUN_006593b0_Class
{
    void* __thiscall FUN_006593b0(unsigned int flags);
};
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
extern "C" __declspec(dllimport) void* __stdcall CreateSemaphoreA(void*, long, long, const char*);
struct FUN_00659500_Holder
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    FUN_00659500_Holder* __thiscall InitSemaphore(int a, int b);
};
struct FUN_0065b3e0_Holder
{
    char _pad[16];
    void* m_10;
    void* m_14;
    void* __thiscall GetPointerByFlag(bool);
};
unsigned int __cdecl FUN_00ec7c56(void);
struct FUN_0065cc70_Holder
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_C;
    int __thiscall FUN_0065cc70(unsigned int param);
};
struct TextureBasis
{
    unsigned int FUN_0065cea0();
};
unsigned int __cdecl FUN_00ec7c56();
struct Holder : TextureBasis
{
    int FUN_0065cec0(unsigned int);
};
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
void __cdecl FUN_0065e480(int a1, int a2, void* a3);
struct FUN_0065dd90_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void __thiscall FUN_0065dd90(int a1, int a2);
};
struct _Out_0044a170
{
    void __thiscall FUN_0065e000(int, void*);
};
struct FUN_0065ded0_Class
{
    _Out_0044a170* __thiscall FUN_0065ded0(_Out_0044a170* a1, int a2, int a3);
};
struct FUN_0065e020_Cls
{
    int __thiscall FUN_0065e020();
};
struct FUN_0065e050_Holder
{
    int __thiscall FUN_0065e050();
};
struct FUN_0065e080_S
{
    int __thiscall FUN_0065e080();
};
struct FUN_0065e0b0_Class
{
    unsigned int FUN_0065e0b0();
};
struct FUN_0065e110_Holder
{
    int GetPositiveValue();
};
struct S_0065e140
{
    unsigned int FUN_0065e140();
};
struct FUN_0065e170_Cls
{
    unsigned __thiscall FUN_0065e170();
};
unsigned char __cdecl FUN_0065e750(void*, void*);
void __cdecl FUN_0065e8e0(int, int, int, unsigned char);
void FUN_0065e510(int a, int b, int c);
unsigned char __cdecl FUN_0065e750(void*, void*);
void __cdecl FUN_0065e910(int, int, int, int);
void __cdecl FUN_0065e5a0(int a, int b, int c);
void __cdecl FUN_0065e880(int a1, int a2, FUN_0065e9c0_class* a3);
void __cdecl FUN_0065e8b0(char* a, char* b, FUN_0065e9e0_Class* c);
void FUN_0065e910(int _First, int _Last, FUN_0065ea20_Class* _Dest);
void FUN_0065e940(int a, int b, FUN_0065ea40_class* c);
struct S_0065eb60
{
    void __thiscall FUN_0065eb60(void* p);
};
char* __cdecl FUN_0065ea80(char* a, char* b, char* c);
struct S_0065eb90
{
    void __thiscall FUN_0065eb90(int);
};
int FUN_0065eac0(int param_1, int param_2, int param_3);
struct FUN_0065ec10_class
{
    void __thiscall FUN_0065ec10(int b);
};
void __cdecl FUN_0065eb00(int a);
struct FUN_0065ec40_class
{
    void FUN_0065ec40(int a);
};
void FUN_0065eb10(FUN_0065ec40_class* self, int a);
struct FUN_0065ec70_class
{
    void FUN_0065ec70(int a);
};
void __cdecl FUN_0065eb20(FUN_0065ec70_class* self);
struct FUN_0065ecd0_Class
{
    void FUN_0065ecd0(int a);
};
void FUN_0065eb40(int a);
struct FUN_0065ed00_Class
{
    void __thiscall FUN_0065ed00(int a);
};
void __cdecl FUN_0065eb50(int a);
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
void __cdecl operator delete(void*);
struct FUN_0065eca0_class
{
    void __thiscall FUN_0065edd0();
    void* __thiscall FUN_0065eca0(unsigned int flags);
};
struct FUN_0065ecd0_class
{
    void* __thiscall FUN_0065ecd0(unsigned int flags);
};
void __cdecl operator delete(void* p);
struct FUN_0065ed00_class
{
    void __thiscall FUN_0065ee50();
    void* __thiscall FUN_0065ed00(unsigned int flags);
};
void FUN_0065f060();
void __stdcall FUN_0065ee50_Helper(void*, unsigned int, int, void (*)());
struct FUN_0065ee50_S
{
    char m_auiShapeKeys[16];
    char m_aiIndexedValues[72];
    void FUN_0065ee50();
};
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
struct S_0065f7c0
{
    unsigned int FUN_0065f7c0();
};
struct FUN_0065f7f0_Class
{
    unsigned int __thiscall FUN_0065f7f0() const;
};
unsigned char __cdecl FUN_0065e750(void* a, void* b);
void __cdecl FUN_0065ff00(void* a, void* b, void* c, unsigned char d);
void __cdecl FUN_0065f9a0(void* a, void* b, void* c);
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
int __cdecl FUN_00ec7ce3(void* a1, unsigned int a2, void* a3, unsigned int a4);
char* FUN_0065fe60(char* a1, char* a2, char* a3);
void __cdecl FUN_0065ff00(char* _First, char* _Last, FUN_0065e9a0_holder* _Dest);
extern "C" void __cdecl FUN_00660130(int a, int b, int c, int d, int e, int f);
struct FUN_0065ff30_Class
{
    void __thiscall FUN_0065ff30(int a, int b, int c, int d, int e);
};
struct FUN_0065ff60_class
{
    void __thiscall FUN_0065ff60(int a, int b, int c, int d, int e);
};
extern "C" void __cdecl FUN_00660190(int a, int b, int c, int d, int e, int f);
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
struct H_0060b3b0
{
    float* FUN_006578b0(unsigned int a) const;
};
int __cdecl _memcmp(const void* a, const void* b, unsigned int n);
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
struct FUN_0064cc90_Class
{
    void __thiscall FUN_0064cc90(unsigned char bFlag);
};
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
void __cdecl FormatMenuText(int menuType, char const* text, char* buffer, unsigned int bufferSize);
struct FUN_0064da80_Class
{
    int __thiscall FUN_0064da80(int a, int b);
};
struct FUN_0064daa0_Class
{
    int __thiscall FUN_0064daa0(int a, int b);
};
struct BGSTerrainManager
{
    unsigned int GetMinLevel();
};
struct Calendar : public BGSTerrainManager
{
    int GetDaysPassed();
    void __thiscall ScaleAll(float value);
};
void FUN_00653000(float value, Calendar* calendars, bool flag);
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
struct FUN_00658bb0 : FUN_00658d30_class
{
    ~FUN_00658bb0();
};
struct FUN_0065d240_class
{
    void __thiscall ClearAndFree();
};
struct FUN_0065d560_Class
{
    void __thiscall ClearAndFreeBuffer();
};
struct FUN_0065da00_class
{
    void FUN_0065da00();
};
struct FUN_0065dbd0_Class
{
    int a0;
    int a4;
    int FUN_0065dbd0();
};
struct FUN_0065dc40_Class
{
    int CallNestedMethod();
};
struct FUN_0065de60_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int FUN_0065de60();
};
struct FUN_0065def0_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    unsigned int FUN_0065def0();
};
void* __cdecl FUN_0065eb30(unsigned int a);
struct CIdvFilenameDestructorHelper
{
    void __thiscall NarrowString();
};
struct FUN_0065ed30_class
{
    void __thiscall FUN_0065ed30();
};
struct CIdvFilenameDtorHelper
{
    void Dtor();
};
struct FUN_0065ed50_Class
{
    void FUN_0065ed50();
};
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
extern double DAT_010356d8;
extern double DAT_01012060;
float __cdecl FUN_00476b70(float a, float b);
float __cdecl FUN_006429e0(float a, float b);
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
int FUN_00642a60(int base, int level, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int extra, bool flag);
extern Setting_S DAT_011cdf78;
extern Setting_S DAT_011cdf44;
extern Setting_S DAT_011cde50;
extern Setting_S DAT_011cdce8;
struct FUN_0066ef50_Class
{
    double FUN_0066ef50(int a);
};
float __cdecl FUN_00643e40(FUN_0066ef50_Class* actor, int action);
class FUN_00644350_cls
{
  public:
    int m_iWordAt00;
    float m_iWordAt04;
    float m_8;
    unsigned char IsGreaterThan(FUN_00644350_cls* other);
};
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
bool FUN_00646400(AVOwnerStub_646400* owner, int value);
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
float __cdecl FUN_00647a30(FUN_00647a30_Obj* a1, FUN_00647a30_Flag* a2, float a3);
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
int __cdecl ComputeScaledSettingSum(float scale);
// Scale a value by the remaining fraction (max - current) / max, clamped to [0, 1].
float __cdecl E50Max(float fA, float fB);
float __cdecl E50Min(float fA, float fB);
float __cdecl ScaleByInverseRatio(float fValue, float fScaledValue, float fCurrentAmountNext);
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
int __cdecl ComputeWeightedValue(float value1, float value2, int weight);
extern int DAT_011d5744;
int __cdecl FUN_006499d0();
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
extern unsigned char DAT_011f94b0;
unsigned char __cdecl FUN_0064d870();
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
void FUN_0064e550(C64E550Element* first, C64E550Element* last, C64E550Element* dest, C64E550Allocator* alloc);
void __cdecl ForwardToHandler(int a, int b, void* c, void* d, unsigned char r, unsigned char flag);
unsigned char __cdecl FUN_0065e750(void* p);
int __cdecl CallWithFlag(int* p);
struct FUN_0064e630_flag
{
    bool m_flag;
};
// @fnv 0x0064e630
extern "C" void __cdecl FUN_0064e630(void* a, void* b, void* c, void* d)
{
    FUN_0064e630_flag aa = {};
    unsigned char zz = FUN_0065e750(&c);
    ForwardToHandler(CallWithFlag((int*)&a), CallWithFlag((int*)&b), c, d, zz, aa.m_flag);
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
S_0064e860_Block* __cdecl FUN_0064e860(S_0064e860_Block* first, S_0064e860_Block* last, S_0064e860_Block* dest);
struct S_0064e8c0_Blk
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
void __cdecl CopyConstructBlock(void* where, S_0064e8c0_Blk* src);
extern "C" void __cdecl FUN_0064e9c0(int a, int b, int c, int d, int e, int f);
struct FlagBox5317
{
    unsigned char v;
};
// @fnv 0x0064e920
extern "C" void __cdecl FUN_0064e920(int a, int b, int c, int d)
{
    FlagBox5317 flag1 = {};
    unsigned char flag2 = FUN_0065e750((void*)&a, (void*)&c);
    FUN_0064e9c0(CallWithFlag((int*)&a), CallWithFlag((int*)&b), c, d, flag2, flag1.v);
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
extern "C" void __cdecl FUN_00658c10(int a, int b)
{
    Hldr0044 h;

    if ((unsigned)a <= 0)
    {
        a = 0;
    }
    else
    {
        if (0xFFFFFFFFu / (unsigned)a < 60)
        {
            h.FUN_0044d6c0(0);
            FUN_00ec7894(&h, &DAT_01140ef8);
        }
    }

    FormHeap_Allocate(a * 60);
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
class FUN_0065be60 : public OwnerBase
{
  public:
    SubMember m_iThirdValue;

    FUN_0065be60(int a);
    virtual ~FUN_0065be60();
};
struct FUN_0065cfb0
{
    ~FUN_0065cfb0();
};
struct FUN_0065c7c0 : FUN_0065cfb0
{
    ~FUN_0065c7c0();
    void ClearStorage();
};
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
struct FUN_006815c0
{
    void* object;
    FUN_006815c0();
    ~FUN_006815c0();
};
struct FUN_0065de30
{
    unsigned int value;
    FUN_0065de30(const FUN_0065de30&);
    unsigned int FUN_0044abd0(int flag);
};
struct FUN_008c71b0
{
    unsigned int value;
    FUN_008c71b0(void* owner);
    ~FUN_008c71b0();
    static void* operator new(unsigned int, unsigned int);
    static void operator delete(void*, unsigned int);
};
struct FUN_0065dc90 : FUN_006815c0
{
    FUN_0065de30 member;
    FUN_0065dc90(FUN_0065de30 argument);
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
struct FUN_0065cfb0_Base
{
    ~FUN_0065cfb0_Base();
};
struct FUN_0065cd10 : FUN_0065cfb0_Base
{
    void FUN_0065d860();
    ~FUN_0065cd10();
};
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
struct FUN_0065e0e0_cls
{
    unsigned int FUN_0065e0e0();
};
struct S_0065e1a0
{
    int unk00;
    int unk04;
    bool FUN_005ca4f0();
    bool FUN_004b0460(S_0065e1a0* other);
    bool FUN_0065e1a0(S_0065e1a0* other);
};
struct LengthErrorB9431
{
    virtual void v0();
    int m_iWordAt04;
    int m_8;
    LengthErrorB9431(int msg);
    ~LengthErrorB9431() throw();
};
void* __cdecl FUN_0065e4c0(unsigned int count);
struct S_0065e550_Err
{
    virtual void vf00();
    int unk04;
    int unk08;
    S_0065e550_Err(int code);
    ~S_0065e550_Err();
};
void* __cdecl operator new(unsigned int size);
void* __cdecl FUN_0065e550(unsigned int n);
struct LengthErrB9739
{
    virtual void v0();
    int m_iWordAt04;
    int m_8;
    LengthErrB9739(int msg);
    ~LengthErrB9739() throw();
};
void* __cdecl FUN_0065e700(unsigned int count);
unsigned char __cdecl FUN_0065e750(void* a, void* b);
struct EmptyTag
{
};
int __cdecl CallWithFlag(int*);
int __cdecl FUN_0065eac0(int, int, int, EmptyTag, EmptyTag, EmptyTag);
int __cdecl FUN_0065e7c0(int first, int last, int destination);
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
char* __cdecl FUN_0065f8c0(char* first, char* last, char* dest);
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
int __cdecl FUN_0065fd70(int a);
int __cdecl CopyTripleShorts(int a, int b, int r, bool z, bool y, bool x);
int __cdecl CallWithFlag(int* p);
struct FNVFlag7675
{
    bool v;
};
int __cdecl ComputeIndexAndCall(int a, int b, int c);
// Candidate: CallWithFlag
//   int CallWithFlag(int* p) { bool flag; return FUN_0043b1d0(p, flag); }
int __cdecl FUN_0043b1d0(int* p, bool flag);
int __cdecl CallWithFlag(int* p);
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
void __cdecl FUN_0065ff90(int first, int last, S_0065ff90_Dest dest);
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
struct FUN_00657a80 : FUN_0065d3a0
{
    FUN_00657a80();
};
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
C658CA0Element* __cdecl FUN_00658ca0(unsigned int ItemUpdateArray, C658CA0Element*);
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
struct ObjectCleanupBase658e10
{
    virtual ~ObjectCleanupBase658e10();
};
struct FUN_00658e10 : ObjectCleanupBase658e10
{
    void FUN_00438af0();
    virtual ~FUN_00658e10();
};
struct FUN_00659080_Class
{
    void __thiscall FUN_00659080(FUN_00659140_Class* obj);
};
struct FUN_0065c9c0 : FUN_0065d3a0
{
    FUN_0065c9c0();
    void AllocateBuffer(unsigned int flag);
};
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
unsigned char* __cdecl FUN_0065fd70(unsigned char* out, int* a1, int* a2);
void __cdecl FUN_0065e760(int a, int b, int c, unsigned char d, unsigned char e, unsigned char f);
struct FlagA
{
    bool v;
};
void __cdecl FUN_0065e1f0(int a, int b, int c);
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
void __cdecl UninitializedCopy(Iter65E kFirst, Iter65E kLast, Iter65E kDest);
struct FUN_0044d6c0_class
{
    int unk00;
    int unk04;
    int unk08;
    void* __thiscall FUN_0044d6c0(void** a);
};
void __cdecl FUN_0065e3a0(int param_1, int);
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
B65E760Item* __cdecl FUN_0065e760(B65E760Item* pkCurrentObject, B65E760Item* pkLast, B65E760Item* pkDest);
struct FUN_0065ee70 : FUN_0065cfb0
{
    ~FUN_0065ee70();
};
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
char* FUN_0065fea0(char* pcFirst, char* pcLast, char* pcDest, int iCount);
struct FUN_00657b50 : FUN_0065d3a0
{
    FUN_00657b50();
};
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
Elem_65eed0* __cdecl FUN_0065f820(Elem_65eed0* first, Elem_65eed0* last, Elem_65eed0* dest);
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
int __cdecl FUN_0064e5a0(int a1, int a2, int a3);
void __cdecl ConstructArrayWithRollback(char* dst, unsigned int count, void* value, FUN_0064e7d0_class* obj);
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
Elem64e9* __cdecl FUN_0064e9c0(Elem64e9* _First, Elem64e9* _Last, Elem64e9* _Dest, Alloc64e9& _Al, NonscalarTag64e9,
                               CheckedTag64e9);
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
void __cdecl FUN_0064e4e0(ItE4E0 kFirst, ItE4E0 kLast, ItE4E0 kDest);
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
float FUN_006479e0(FloatSource* src);
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
int __cdecl FUN_00642bc0(int skill, int count, float distance, int resistance, int level, bool flagA, bool flagB,
                         bool flagC, int quantity, int value, bool special);
struct FUN_006443d0 : GlobalObject_00869f00
{
    virtual ~FUN_006443d0();
};
struct BGSLoadGameBuffer;
struct Interface
{
    static void __cdecl PrintDebugMessage(BGSLoadGameBuffer*);
};
struct FUN_0065e9a0_Class
{
    void __thiscall FUN_0065e9a0(BGSLoadGameBuffer* p);
};
void __cdecl FUN_0065eb20(void*);
struct FUN_0065ea00_Class
{
    void __thiscall FUN_0065ea00(void* a);
};

void* __cdecl operator new(unsigned int size, unsigned int allocation);
void __cdecl operator delete(void* object, unsigned int allocation);

// @fnv 0x0065dc90
FUN_0065dc90::FUN_0065dc90(FUN_0065de30 argument) : FUN_006815c0(), member(argument)
{
    object = new (member.FUN_0044abd0(1)) FUN_008c71b0(this);
}
