// staging/blk_005e0000_od_ctx_variant.cpp: Derived, Holder (4 functions)

#include <string.h>
// blk_005e0000_od_ctx_variant.cpp: context variant of src/staging/blk_005e0000_od.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
// src/staging/blk_005e0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
struct FUN_00851d70_shell
{
    void SetFlagByte();
};
extern GlobalObject_0045cf30 g_011de29c;
extern void* DAT_011de134;
bool FUN_005e0160();
extern "C" void __cdecl FUN_004b0220(int);
extern int DAT_0103d3e8;
struct FUN_005e02e0
{
    int m0;
    int m4;
    void Init();
};
extern "C" void* DAT_0103d3f0;
struct FUN_005e0310_class
{
    void* vtbl;
    void __thiscall FUN_005e08e0(void* a, void* b);
    FUN_005e0310_class* __thiscall FUN_005e0310(void* a, void* b);
};
struct ActorCombatGroup;
struct NiTMallocInterface_
{
    static void __cdecl Deallocate(ActorCombatGroup**);
};
struct FUN_005e0340Class
{
    int m_vtbl;
    ActorCombatGroup** m_ptr;
    void FUN_005e0340();
};
extern int DAT_0103d3f8;
extern int DAT_0103d400;
struct FUN_005e0370_Class
{
    void* vtbl;
    void FUN_005e0950(int a, int b);
    void* FUN_005e0370(int a, int b);
};
struct NavMeshPtr
{
    void* FUN_00458b50();
    void* FUN_005e05b0(int index);
};
struct QuantityData
{
    void SetQuantity(unsigned int);
    void FUN_005e0b80(unsigned int quantity);
};
struct FUN_005e1140_Class
{
    void FUN_005e1140(float value);
};
struct FUN_005e2850_class
{
    bool FUN_005e2850();
};
struct Stub
{
    void FUN_005e9590();
    void FUN_005e9860();
};
struct TESFaction_RankDataView
{
    unsigned char* GetRankDataList();
    bool HasFlag20();
};
struct FUN_005ec8f0_class
{
    bool __thiscall FUN_005ec760(int a);
    bool __thiscall FUN_005ec8f0(int a);
};
struct FUN_005ecd10_cls
{
    unsigned char IsEqual(int);
    bool FUN_005ece20(int a);
};
struct FUN_005ed1b0_Class
{
    bool Equals(int);
    bool FUN_005ed1b0(int arg);
};
extern int DAT_010472e4;
struct GlobalObject_00869f00
{
    int* p;
    void Clear(bool);
    void ResetToGlobal();
};
extern int DAT_010472f8;
struct FUN_005ef910_class
{
    int __thiscall FUN_005ef910(int, int);
};
struct FUN_005eefc0_class
{
    FUN_005eefc0_class* __thiscall FUN_005eefc0();
};
void* __cdecl operator new(unsigned int);
struct FUN_005ef150_class
{
    void* __thiscall FUN_005ef150(int a);
};
extern "C" void* __cdecl _Reallocate(void* p, size_t size);
struct FUN_005ef180_Class
{
    void* __thiscall FUN_005ef180(int n, int m);
};
extern int DAT_0104730c;
void FUN_005efb30(int, int);
struct FUN_005ef1a0_Class
{
    void FUN_005efb30(int, int);
    FUN_005ef1a0_Class* FUN_005ef1a0();
};
struct FUN_005ef330_Class
{
    void* __thiscall FUN_005ef330(int param_2);
};
void* __cdecl Reallocate(void* p, unsigned int n);
struct FUN_005ef360_class
{
    void* __thiscall FUN_005ef360(unsigned int n, unsigned int m);
};
extern int DAT_01047320;
struct FUN_005efd40_class
{
    void* vtbl;
    void FUN_005efd40(int a, int b);
    FUN_005efd40_class* FUN_005ef380();
};
struct FUN_005ef510_Class
{
    void* __thiscall AllocateSixTimesSize(int n);
};
extern "C" void* __cdecl _Reallocate(void* p, size_t n);
struct FUN_005ef540_class
{
    void* __thiscall FUN_005ef540(int a, int b);
};
struct TESAttributes
{
    unsigned char GetAttributeValue(int);
};
struct FUN_005f1210_shell : TESAttributes
{
    unsigned char FUN_005f1210();
};
struct FUN_005f3710_Class
{
    int __thiscall GetEntryAt(int index);
};
struct FUN_005f4b70_Class
{
    void FUN_005f4b70(unsigned char aucLevel);
};
struct FUN_005f4b90_Class
{
    void SetByteAtOffset2B(unsigned char v);
};
struct FUN_005f5f60_class
{
    int FUN_005f5f60();
};
struct FUN_005f5fa0_cls
{
    unsigned int GetShortAtOffset64();
};
struct FUN_005f5fc0_class
{
    unsigned int GetShortAtOffset66();
};
struct FUN_005f5fe0_class
{
    unsigned int __thiscall GetShortAtOffset68();
};
struct FUN_005f60c0_Class
{
    int HasFlag8();
};
struct TESChallenge
{
    void MarkForSave();
    void FUN_005f60e0(int amount);
};
struct TESActorBaseData
{
    void UpdateFlagBit(int, bool, bool);
    void FUN_005f9010(bool set);
};
void __cdecl FUN_00600b90();
struct FUN_005ffbd0_cls
{
    void __thiscall FUN_005ffbd0();
    void __thiscall FUN_00600b90();
};
struct FUN_005e0830
{
    void __thiscall FUN_004f8ac0(const char*);
    void __thiscall Open(const char* apFileName, bool abWrite);
};
struct FUN_005efc60_class
{
    void* __thiscall InitToMinusOne();
};
struct FUN_005f4bd0_class
{
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    int m14;
    void SetEntryByte(unsigned int index, unsigned char value);
};
extern int DAT_0103d408;
void __cdecl FUN_004ede70(void*);
struct Standin005e03a0
{
    void* vtbl;
    void* m4;
    void __thiscall FUN_005e03a0();
};
struct NiBound
{
    NiBound();
};
int __cdecl FUN_005e0aa0(void* a, int b);
struct FUN_005e05d0 : NiBound
{
    FUN_005e05d0(void* a, int b);
};
void __cdecl _Deallocate(void*);
struct Holder005e0620
{
    void* __thiscall InitAndMaybeFree(unsigned int);
};
struct FUN_005dd810_Class
{
    void FUN_005dd810();
    void* __thiscall FUN_005e0650(unsigned int flags);
};
void __cdecl Deallocate(void* p);
void __cdecl Deallocate(void* p);
struct FUN_005e0680_Class : FUN_005e0340Class
{
    void* __thiscall FUN_005e0680(unsigned int flags);
};
void __cdecl Deallocate(void*);
struct FUN_005dd7b0_class
{
    void __thiscall FUN_005dd7b0();
    void* __thiscall FUN_005e06b0(unsigned int flags);
};
struct FUN_005e03a0_Class
{
    void __thiscall FUN_005e03a0();
};
void __cdecl operator delete(void*);
struct FUN_005e06e0_Class
{
    void* __thiscall FUN_005e06e0(unsigned int flags);
};
struct FUN_005dd7d0_Class
{
    void FUN_005dd7d0();
};
void __cdecl Deallocate(void* p);
struct FUN_005e0710_Class
{
    void* __thiscall FUN_005e0710(unsigned int flags);
};
struct FUN_005e0460_class
{
    void FUN_005e0460();
};
struct FUN_005e0740_class : FUN_005e0460_class
{
    void* __thiscall FUN_005e0740(unsigned int flags);
};
void __cdecl operator delete(void*);
struct FUN_005dd7f0_class
{
    void FUN_005dd7f0();
};
struct FUN_005e0770_class
{
    FUN_005e0770_class* FUN_005e0770(unsigned int flags);
};
struct _Mem_20a4
{
    ~_Mem_20a4();
    _Mem_20a4* __thiscall FUN_005e07a0(unsigned int flags);
};
void __cdecl operator delete(void*);
struct FUN_005e0590_shell
{
    void FUN_005e0590();
};
struct FUN_005e0800_class
{
    void* __thiscall FUN_005e0800(unsigned int flags);
};
void* __cdecl FUN_00c85750();
struct ref_006815c0_class
{
    ref_006815c0_class* ref_006815c0(void* a, void* b);
    void FUN_005e0ad0();
};
void FUN_005e0aa0(int a, int b);
struct FUN_005e0b10_holder
{
    void __thiscall FUN_005e0b10();
};
unsigned int __cdecl FUN_005e0b50(void*, int);
struct S_005e0ad0
{
    void* __thiscall FUN_005e0ad0(int a, int b);
};
void __cdecl FUN_005e0b40(void*, void*);
struct FUN_005e0b10_Cls
{
    NavMeshPtr m0;
    char _pad[7];
    NavMeshPtr m8;
    void __thiscall FUN_005e0b10();
};
template <int N> struct EndianSizeTag
{
    unsigned char v;
};
void __cdecl BSEndian(unsigned char*, EndianSizeTag<0>);
void __cdecl FUN_004717f0(void*, EndianSizeTag<0>);
struct T2870
{
    void __thiscall FUN_005e2870();
};
struct FUN_005ec700_shell : TESFaction_RankDataView
{
    void SetFlag20(bool b);
};
struct FUN_005ed160_Class
{
    bool Equals(int arg);
};
struct FUN_00692290_class
{
    void __thiscall FUN_00692290(unsigned int, unsigned int);
};
struct FUN_005eee30_class
{
    void* vtbl;
    FUN_005eee30_class* __thiscall FUN_005eee30();
};
struct GlobalObject_00869f00_Deleting : GlobalObject_00869f00
{
    GlobalObject_00869f00* __thiscall FUN_005ef590(unsigned int flags);
};
void __cdecl operator delete(void*);
struct FUN_005eeff0_shell
{
    void __thiscall FUN_005eeff0();
};
struct FUN_005ef5c0_class
{
    void* __thiscall FUN_005ef5c0(unsigned int flags);
};
struct FUN_005ef1d0_class
{
    void __thiscall FUN_005ef1d0();
};
void __cdecl operator delete(void*);
struct FUN_005ef5f0_class
{
    void* __thiscall FUN_005ef5f0(unsigned int flags);
};
void __cdecl operator delete(void*);
struct FUN_005ef3b0
{
    void __thiscall FUN_005ef3b0_dtor();
    FUN_005ef3b0* __thiscall FUN_005ef620(unsigned int flags);
};
struct NavMeshSearchLOSArray
{
    void FUN_006a8500();
    void FUN_005efe70(void*, void*, int);
};
struct FUN_005ef860_class
{
    virtual void v0();
    virtual void* v4(int a);
    virtual void v8();
    virtual void* vC(int a, int b);
    void* m4;
    int m8;
    int mC;
    void FUN_005ef860(int a, int b);
};
struct FUN_005efa40_class
{
    short m0;
    short m2;
    char pad4[24];
    float m1C;
    float m20;
    float m24;
    FUN_005efa40_class* __thiscall FUN_005efa40();
};
struct FUN_005f29f0_Class
{
    void __thiscall SetValueAtIndex(unsigned int index, float value);
};
struct FUN_005f2a30_Class
{
    char _pad0[0x34];
    unsigned int m34;
    void* m38;
    void __thiscall SetEntryValue(unsigned int index, unsigned int value);
};
struct FUN_005f2b20_Class
{
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    unsigned int m34;
    int m38;
    void __thiscall SetEntryFloat(unsigned int a, float b);
};
struct FUN_005f6000_Class : TESChallenge
{
    int m_flags;
    void SetFlagAndMarkForSave(bool bFlag);
};
struct FUN_005f6060_class
{
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
    int m54;
    int m58;
    int m5c;
    int m60;
    int m64;
    int m68;
    int m6c;
    int m70;
    void MarkForSave();
    void FUN_005f6060(bool show);
};
struct FUN_005f6570 : public TESChallenge
{
    void SetFlag(bool set);
};
struct FUN_005f74b0_cls
{
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
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
    virtual void Target(int, int);
    void __thiscall TargetWithFloatArg(int a, float b);
};
struct Inner74e0
{
    virtual void i0();
    virtual void i1();
    virtual int __thiscall i2(int);
};
struct Outer74e0
{
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void u4();
    virtual void u5();
    virtual void u6();
    virtual void u7();
    virtual void u8();
    virtual void u9();
    virtual void u10();
    virtual void u11();
    virtual void u12();
    virtual void u13();
    virtual void u14();
    virtual void u15();
    virtual void u16();
    virtual void u17();
    virtual void u18();
    virtual void u19();
    virtual void u20();
    virtual void u21();
    virtual void u22();
    virtual void u23();
    virtual void u24();
    virtual void u25();
    virtual void u26();
    virtual void u27();
    virtual void u28();
    virtual void u29();
    virtual void u30();
    virtual void u31();
    virtual void u32();
    virtual void u33();
    virtual void u34();
    virtual void u35();
    virtual void u36();
    virtual void u37();
    virtual void u38();
    virtual void u39();
    virtual void u40();
    virtual void u41();
    virtual void u42();
    virtual void u43();
    virtual void u44();
    virtual void u45();
    virtual void u46();
    virtual void u47();
    virtual void u48();
    virtual void u49();
    virtual void u50();
    virtual void u51();
    virtual void u52();
    virtual void u53();
    virtual void u54();
    virtual void u55();
    virtual void u56();
    virtual void u57();
    virtual void u58();
    virtual void u59();
    virtual void u60();
    virtual void u61();
    virtual void u62();
    virtual void u63();
    virtual void u64();
    virtual void u65();
    virtual void u66();
    virtual void u67();
    virtual void u68();
    virtual void u69();
    virtual void u70();
    virtual void u71();
    virtual void u72();
    virtual void u73();
    virtual void u74();
    virtual void u75();
    virtual void u76();
    virtual void u77();
    virtual void u78();
    virtual void u79();
    virtual void u80();
    virtual void u81();
    virtual void u82();
    virtual void u83();
    virtual void u84();
    virtual void u85();
    virtual void u86();
    virtual void u87();
    virtual void u88();
    virtual void u89();
    virtual void u90();
    virtual void u91();
    virtual void u92();
    virtual void u93();
    virtual void u94();
    virtual void u95();
    virtual void u96();
    virtual void u97();
    virtual void u98();
    virtual void u99();
    virtual void u100();
    virtual void __thiscall targ(int, int);
    char _pad[252];
    Inner74e0 fld100;
    void __thiscall ForwardToTarget(int, int);
};
struct GlobalObject_0045cfe0
{
    int** Int();
};
extern GlobalObject_0045cfe0 g_011cd3b4;
extern GlobalObject_0045cfe0 g_011cd538;
extern GlobalObject_0045cfe0 g_011cdde0;
struct FUN_005fbeb0_shell
{
    int* FUN_005fbeb0();
};
struct FUN_005ff520_shell
{
    unsigned int FUN_005ff520(unsigned int);
};
struct FUN_005ff560_shell
{
    void RemoveChildAndRelinkNeighbors(unsigned int);
};
struct FUN_005ff5d0_class
{
    void FUN_005ff5d0(unsigned int a);
};
char** __cdecl FUN_005e0ba0(unsigned int);
struct FUN_005e08e0_class
{
    int* vtbl;
    char** data;
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short d;
    unsigned short e;
    FUN_005e08e0_class* __thiscall FUN_005e08e0(unsigned short x, unsigned short y);
};
struct FUN_005ef9a0_shell
{
    virtual void v0();
    virtual int v1(unsigned int);
    void ConstructEntries(int, unsigned int);
};
struct FUN_005efb30_class
{
    void* vtbl;
    unsigned int m4;
    unsigned int m8;
    unsigned int mc;
    void FUN_005efb30(unsigned int requested, unsigned int savedSize);
};
void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int size);
struct FUN_005efdd0_class
{
    void __thiscall FUN_005efdd0(char* a, char* b, unsigned int count);
};
void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int size);
struct FUN_005efe70_shell
{
    void __thiscall FUN_005efe70(char* a, char* b, unsigned int c);
};
void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int count);
struct FUN_005eff10_class
{
    void __thiscall FUN_005eff10(char* dst, const char* src, unsigned int count);
};
struct FNStub
{
    char* __thiscall GetFullName();
};
struct TESSaveLoadGame
{
    void FUN_008579b0(void*, int);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
int BSStringLength(const char*);
struct FUN_005f6f70_Class
{
    void FUN_005f6f70();
};
struct NiTMallocInterface_0096afc0
{
    static ActorCombatGroup** __cdecl Allocate(unsigned short);
};
struct FUN_005e0950
{
    int m0;
    int m4;
    unsigned short m8;
    unsigned short ma;
    unsigned short mc;
    unsigned short me;
    FUN_005e0950(unsigned short, unsigned short);
};
struct FUN_006c8a30_Class
{
    void FUN_006a8500();
};
struct FUN_005ef6a0Class
{
    virtual void v0();
    virtual void* v4(int);
    virtual void v8();
    virtual void* v12(void*, int);
    void* p;
    int pad;
    int idx;
    void SetOrReplace(int a, int b);
};
struct FUN_005ef7f0_Data
{
    short x0;
    short x2;
    short x4;
    char x6;
    float x8;
    float xc;
    float x10;
    float x14;
    float x18;
    float x1c;
    void* __thiscall FUN_005ef7f0();
};
struct FUN_005ef910_vt
{
    virtual void v0();
    virtual int Write(int);
};
struct FUN_005ef910 : FUN_005ef910_vt
{
    int iSize;
    int iPosition;
    int iDataLength;
    void ConstructSpawnItems(int, int);
    void __thiscall RecordRequestedSize(unsigned int requested, unsigned int savedSize);
};
void __cdecl FUN_005e0b60(void*);
struct GO
{
    operator unsigned int();
};
struct FUN_005e0600_Class
{
    void FUN_005e0600();
};
void* __cdecl FUN_00885750();
struct BSSimpleList_005e0b60
{
    BSSimpleList_005e0b60* GetItem();
};
void FUN_005e0b60(void* p);
struct FUN_005e3fe0_class
{
    void __thiscall SwapEndianFields();
};
struct FUN_005eee10
{
    ~FUN_005eee10();
};
struct FUN_005ef560_Class : public FUN_005eee10
{
    void* FUN_005ef560(unsigned int flags);
};
FUN_005eee10::~FUN_005eee10()
{}
struct FUN_005f11f0_shell : TESAttributes
{
    unsigned char GetAttributeValue5();
};
struct FUN_005f1290_shell : TESAttributes
{
    unsigned char GetAttributeValue10();
};
// FindByKey: list search over a cursor list at this+0x10c.
class FNVCursor
{
  public:
    bool IsEnd();
    void** Value();
    FNVCursor* Next();
};
class FNVObject
{
  public:
    void* Key();
};
int __cdecl FNVCompare(void* key, void* a1);
class FUN_005e0860_cls
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
    FNVCursor m_kNode;
    bool FindByKey(void* a1, FNVObject** a2);
};
int __cdecl FUN_005e0b40(unsigned int arg0, unsigned int arg1);
unsigned int __cdecl FUN_005e0b50(void* base, int offset);
struct ObjectHeader
{
    unsigned int flags;
};
struct Component
{
    unsigned int state;
};
struct CompleteObject : ObjectHeader, Component
{
};
struct VirtualReader
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
    virtual Component* readEntry(bool* success);
    CompleteObject* ReadCompleteObject();
};
struct LightingDataCmp
{
    short s00;
    short s02;
    short s04;
    unsigned char b06;
    unsigned char unk07;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    float f34;

    bool FUN_005ec760(const LightingDataCmp* other);
};
struct Entry38
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
};
struct StrArray
{
    void* vtbl;
    char** data;
    int unk08;
    int unk0C;
    unsigned int GetSize();
    char*& GetAt(unsigned int index);
    void Clear(bool);
    void SetSize(unsigned int, bool);
};
struct EntryArray
{
    void* vtbl;
    Entry38* data;
    int unk08;
    int unk0C;
    unsigned int GetSize();
    Entry38* GetEntry(unsigned int index);
    void Clear(bool);
    void SetEntryCount(unsigned int, bool);
};
int BSStringLength(const char*);
int strcpy_s(char* dst, unsigned int size, const char* src);
struct Data005ecb30
{
    unsigned char flag;
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    StrArray strings;
    EntryArray entries;
    void FUN_005ecb30(Data005ecb30* other);
};
// FUN_005eedc0 : returns &m_pEntries[index] (element size 0x38)
struct FUN_005eedc0_item
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
};
struct FUN_005eedc0_cls
{
    int m_unk00;
    FUN_005eedc0_item* m_pEntries;
    FUN_005eedc0_item* FUN_005eedc0(int index);
};
struct FUN_005efa80_cls
{
    virtual void v0();
    virtual void* v4(void* a);
    virtual void v8();
    virtual void* vC(void* a, void* b);
    void* m_04;
    unsigned int m_08;
    void* m_0c;
    void Helper(void* a, void* b, unsigned int c);
    void Finish();
    void FUN_005efa80(void* a1, unsigned int a2);
};
void* operator new(unsigned int uiSize, void* pvMem);
void operator delete(void* pvMem, void* pvPlace);
struct EFBC0Item
{
    EFBC0Item();

    short m_sValue0;
    short m_sValue1;
    short m_sValue2;
};
class EFBC0Array
{
  public:
    void ConstructItems(EFBC0Item* pkItems, unsigned int ItemUpdateArray);
};
struct Vec3Sub
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
    Vec3Sub();
};
extern Vec3Sub DAT_011f426c;
struct RootCls_b9637
{
    virtual void unk00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;

    RootCls_b9637();
    ~RootCls_b9637();
};
class FUN_005f21c0_cls : public RootCls_b9637
{
  public:
    virtual void unk00();
    int unk18;
    Vec3Sub m_1c;
    unsigned char unk28;
    unsigned char unk29;
    unsigned char unk2a;
    unsigned char unk2b;
    unsigned char unk2c;
    int unk30;
    int unk34;
    int unk38;

    FUN_005f21c0_cls(unsigned short a);
    void SetAnimGroupType(unsigned short a);
};
struct PairRecord16
{
    unsigned int unk00;
    unsigned char m_flag;
    unsigned char unk05;
    unsigned short unk06;
    unsigned int m_uiFilterValue;
    unsigned int unk0C;
};
class FUN_005f2a70_cls
{
  public:
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
    unsigned int m_uiItemCount;
    PairRecord16* m_pRecords;

    void SetRecordFlagAndValue(unsigned int index, unsigned char flag, unsigned int value);
};
extern double DAT_010484f0;
struct FUN_005f2ac0_rec
{
    unsigned char m_00[4];
    unsigned char m_04;
    unsigned char m_05[11];
};
struct FUN_005f2ac0_cls
{
    char m_000[0x34];
    unsigned int m_34;
    FUN_005f2ac0_rec* m_38;
    void __thiscall SetRecordValue(unsigned int idx, float f);
};
struct Pt3
{
    float x;
    float y;
    float z;
};
struct Ext
{
    float GetMult();
};
struct Ref;
struct SndInfo
{
    int m00;
    int m04;
    int m08;
    int m0C;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
};
struct SndForm
{
    SndInfo GetInfo();
    int GetSoundId(int flags);
    int GetId2(int flags);
};
struct AudioPlaybackHandle
{
    int m0;
    int m4;
    int m8;
    AudioPlaybackHandle();
    ~AudioPlaybackHandle();
    AudioPlaybackHandle& operator=(const AudioPlaybackHandle& o);
    void SetPos(float x, float y, float z);
    void SetVolume(float v);
    void SetNode(void* node);
    void SetFreq(float f);
    void Play(bool b);
};
struct AudioMgr
{
    static AudioMgr* Get();
    AudioPlaybackHandle Make(int id, SndForm* form);
    AudioPlaybackHandle Make2(int id);
    bool PlayAt(void* node, float f, int flags);
};
struct SndList
{
    SndForm* GetSoundByEditorID(int idx);
};
struct SndTable
{
    SndForm* GetSoundByEditorID(int idx);
};
struct Holder
{
    ~Holder();
    SndTable* GetTable();
};
struct StrHolder
{
    char* GetStr();
};
struct StrElem
{
    int m0;
    int m4;
    StrHolder* Get();
};
struct ArrHolder
{
    StrElem* GetArr();
};
struct Script
{
    ArrHolder* GetData(int* found);
};
struct Proc
{
    SndForm* GetSoundByEditorID();
};
struct Ref
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
    virtual bool IsActor();
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
    virtual void* GetNode();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual Ext* GetExt();
    virtual void v7A();
    virtual void v7B();
    virtual void v7C();
    virtual Pt3* GetPos();
    virtual void v7E();
    virtual void v7F();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual bool IsAlive();
    bool IsSomething();
    void HandleRef(Ref* r);
    SndList* GetSndList();
    Holder* GetHolder(int n);
    Proc* GetProc();
};
union EntryData
{
    float f;
    unsigned int u;
};
struct Entry
{
    float fTime_2;
    unsigned char ucType;
    EntryData data;
    SndForm* pForm;
};
extern Ref* g_pPlayer;
extern double g_dPercent;
extern float g_fVolume;
extern double g_dZero;
int __cdecl GetFlagBits(int v);
bool __cdecl CheckDist(SndForm* form, Pt3 pos3, float f);
void __cdecl DoTypeA(Ref* r, int type);
void __cdecl DoTypeB(Ref* r, int n);
void __cdecl DoShake(float f, Pt3* pos3);
double __cdecl StrToD(const char* s);
struct FUN_005f2b60_cls
{
    unsigned int GetCount();
    Entry* GetAt(unsigned int i);
    int GetKind();
    void ProcessSoundEntries(Ref* ref, float fFrom, float fTo, Script* script);
};
// GetEntryByte0d: lookup of a per-entry byte value by index.
// The class holds a count of entries at +0x0c and a pointer to a table of
// 16-byte entries at +0x14; the byte read from each entry sits at +0x0d.
struct F4c00Entry
{
    int m_i00;
    int m_i04;
    int m_i08;
    unsigned char m_uc0c;
    unsigned char m_uc0d;
    unsigned char m_uc0e;
    unsigned char m_uc0f;
};
struct FUN_005f4c00_cls
{
    int m_i00;
    int m_i04;
    int m_i08;
    unsigned int m_uCount;
    int m_i10;
    F4c00Entry* m_pEntries;
    unsigned char GetEntryByte0d(unsigned int index);
};
struct FUN_005f4db0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short m10;
    bool FUN_005f4db0();
};
extern "C" int __cdecl FUN_005f2440(unsigned short value);
class B5FA120Form
{
  public:
    int GetFormType();
    bool FUN_0046e8c0();
};
class B5FA120Checker
{
  public:
    bool FUN_005fa120(B5FA120Form* pkForm);
};
struct FUN_005fbdd0_cls
{
    void FUN_005fbdd0(int a1);
    void* FUN_00717e50();
    void* FUN_006815c0();
    int FUN_00401170();
    unsigned char FUN_0046e8c0();
    int FUN_00522c00();
    void FUN_00481790(void* item);
    void* FUN_00726070();
};
int __cdecl FUN_004aae30(int a, int b);
class B5FC120Form
{
  public:
    virtual ~B5FC120Form();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
class B5FC120FullName
{
  public:
    virtual ~B5FC120FullName();
    int unk04;
    int unk08;
};
class B5FC120Texture
{
  public:
    virtual ~B5FC120Texture();
    int unk04;
    int unk08;
};
// TESEyes destructor
class FUN_005fc120 : public B5FC120Form, public B5FC120FullName, public B5FC120Texture
{
  public:
    virtual ~FUN_005fc120();
};
class C5FDB90Form
{
  public:
    virtual ~C5FDB90Form();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
class C5FDB90FullName
{
  public:
    virtual ~C5FDB90FullName();

    int unk04;
    int unk08;
};
class C5FDB90Model
{
  public:
    virtual ~C5FDB90Model();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
class C5FDB90Texture
{
  public:
    virtual ~C5FDB90Texture();

    int unk04;
    int unk08;
};
// TESHair
class FUN_005fdb90 : public C5FDB90Form, public C5FDB90FullName, public C5FDB90Model, public C5FDB90Texture
{
  public:
    virtual ~FUN_005fdb90();
};
class FUN_005fe040_baseA
{
  public:
    virtual void unk00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    FUN_005fe040_baseA();
    ~FUN_005fe040_baseA();
};
class FUN_005fe040_baseB
{
  public:
    virtual void unk00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    FUN_005fe040_baseB();
    ~FUN_005fe040_baseB();
};
class FUN_005fe040_memberC
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FUN_005fe040_memberC();
    ~FUN_005fe040_memberC();
};
class FUN_005fe040_memberD
{
  public:
    unsigned int unk00;
    FUN_005fe040_memberD();
    ~FUN_005fe040_memberD();
};
class FUN_005fe040 : public FUN_005fe040_baseA, public FUN_005fe040_baseB
{
  public:
    FUN_005fe040_memberC m_30;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    FUN_005fe040_memberD m_4c;

    FUN_005fe040();
    virtual void unk_Vfn();
    void unk_Init(unsigned int aSize);
    void unk_Finish();
};
class ThisBase_b3969
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    ThisBase_b3969(int aValue, bool aFlag);
    ~ThisBase_b3969();
};
class ThisMember_b3969
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    ThisMember_b3969(unsigned int aValue, bool aFlag);
    ~ThisMember_b3969();
};
class FUN_005ffaf0 : public ThisBase_b3969
{
  public:
    unsigned char m_14;
    ThisMember_b3969 m_18;

    FUN_005ffaf0();
};
// Thiscall dtor, 98 bytes /MT /Od /GS /EHsc: body call on this (state 1),
// member sub-object at +0x18 released (state 0), then base sub-object dtor on this (state -1).
class FUN_005ffb60_base
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    ~FUN_005ffb60_base();
};
class FUN_005ffb60_child
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    ~FUN_005ffb60_child();
};
class FUN_005ffb60_cls : public FUN_005ffb60_base
{
  public:
    FUN_005ffb60_child m_18;
    void Tidy();
    ~FUN_005ffb60_cls();
};
struct C5E0200AutoMemHelper
{
    C5E0200AutoMemHelper(int iType, bool bFlag, const char* pcFile, int iLine);
    ~C5E0200AutoMemHelper();

    int m_uiLogicalSize;
};
extern const char g_ac5E0200SourceFile[];
class C5E0200File
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void Process();
    virtual void VFunc20();
    virtual void Prepare();

    bool Open(const char* pcFileName, bool bWrite);
    bool FUN_005e0200(const char* pcFileName);
};
struct NiRTTI_S;
struct SkinInst_S;
struct TriGeom_S;
struct Node_S;
struct AVObj_S
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual Node_S* IsSceneNode();
    virtual void v10();
    virtual void v14();
    virtual TriGeom_S* IsTriBasedGeom();
};
struct Node_S : AVObj_S
{
    unsigned int GetChildCount();
    AVObj_S* GetAt(unsigned int);
};
struct TriGeom_S : AVObj_S
{
    SkinInst_S* GetSkinInstance();
};
struct SkinPartObj_S
{
    void SetPartitionVisible(unsigned int partId, bool show);
};
SkinPartObj_S* NiDynamicCast(const NiRTTI_S* rtti, SkinInst_S* obj);
extern const NiRTTI_S g_011f49d8;
void SetPartitionVisibility(int partition, AVObj_S* root);
struct CompareEntry
{
    bool Differs(CompareEntry*);
};
struct CompareArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int Size();
    CompareEntry* At(unsigned int);
};
struct CompareStrings
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int Size();
    const char*& At(unsigned int);
};
int CompareText(const char*, const char*);
struct CompareData
{
    unsigned char flag;
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    CompareStrings strings;
    CompareArray entries;
    bool FUN_005ec920(CompareData* other);
};
struct Entry005ed1e0
{
    bool FUN_005ed1b0(Entry005ed1e0* other);
};
struct Array005ed1e0
{
    void* unknown_00;
    void* unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int FUN_0044ddc0();
};
struct EntryArray005ed1e0 : Array005ed1e0
{
    Entry005ed1e0* FUN_0069ccf0(unsigned int index);
};
struct StringArray005ed1e0 : Array005ed1e0
{
    const char*& FUN_00877a30(unsigned int index);
};
int __cdecl FUN_00408b20(const char*, const char*);
struct Target005ed1e0
{
    unsigned char unknown_00;
    unsigned char unknown_01;
    unsigned short unknown_02;
    StringArray005ed1e0 strings_04;
    EntryArray005ed1e0 entries_14;
    bool FUN_005ed1e0(Target005ed1e0* other);
};
void* __cdecl operator new(unsigned int, void*);
struct SpawnItem : FUN_005ef7f0_Data
{
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    SpawnItem();
};
void* __cdecl operator new(unsigned int uiSize, void* pvMem);
void __cdecl operator delete(void* pvObject, void* pvMem);
struct E5EF9A0Entry
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

    E5EF9A0Entry();
};
class E5EF9A0Allocator
{
  public:
    void ConstructEntries(E5EF9A0Entry* pkArray, unsigned int ItemUpdateArray);
};
struct ChallengeView;
struct ChallengeNode
{
    ChallengeView** FUN_006815c0();
    ChallengeNode* FUN_00726070();
};
struct ChallengeName
{
    const char* FUN_00408da0();
    int unk00;
    int unk04;
    int unk08;
};
struct ChallengeDescription
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vC();
    virtual const char* GetText(int, unsigned int);
    int unk04;
};
struct ChallengeView : TESChallenge
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ChallengeName name;
    ChallengeDescription description;
    ChallengeNode rewards;
    int FUN_005a6150();
    int FUN_005f5f60();
    int FUN_005f5930();
    int FUN_005a60d0();
    unsigned int FUN_0084e3a0();
    int FUN_005e3fa0();
    int FUN_006286d0();
    int GetField54();
    unsigned int GetShortAtOffset64();
    int HasFlag8();
    void ClearField6C();
    void FUN_005f6060(bool);
    void SetFlagAndMarkForSave(bool);
    int FUN_005f5f80();
};
struct ChallengeReward
{
    void RunScriptOnTarget(void*, int);
};
extern ChallengeNode DAT_011cb448;
extern GlobalObject_0045cf30 g_011cb4d4;
extern void* DAT_011dea3c;
void __cdecl FUN_004d5c60(int);
int __cdecl FUN_00406d00(char*, int, const char*, ...);
const char* __cdecl FUN_0048e730(ChallengeView*, int);
bool __cdecl QueueUIMessage(const char*, int, const char*, const char*, float, bool);
void __cdecl FUN_00706f30(int);
void __cdecl FUN_005f5880();
bool __cdecl FUN_005f6110(ChallengeView* source, int amount);
int __cdecl FUN_00408b20(const char*, const char*);
struct NavMeshStaticAvoidNode : FUN_005ecd10_cls
{
};
struct NodeArray : BSSimpleArray<NavMeshStaticAvoidNode*, 1024>
{
    NavMeshStaticAvoidNode* FUN_00691750(int index);
};
struct FUN_005ece50_class
{
    unsigned char m0;
    BSSimpleArray<const char*, 1024> m4;
    NodeArray m14;
    unsigned char FUN_005ece50(FUN_005ece50_class* other);
};
struct PlayerCharacter
{
    bool IsSneaking();
    bool MovingCheck();
};
struct TESSound;
struct SoundDataHandler
{
    TESSound* GetSoundByEditorID(const char*);
};
extern PlayerCharacter* g_thePlayer;
extern SoundDataHandler* DAT_011c3f2c;
const char* __cdecl GetStringByIndex(const char*);
int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
TESSound* GetBrushSound(const char* apPrefix);
extern const char* DAT_01196d40[10];
const char* __cdecl GetStringByIndex(int index);
struct BSStr
{
    bool Set(const char* a, unsigned int b);
};
struct FUN_005e2c10_shell
{
    BSStr m3c;
    bool SetString(const char* a);
};
extern const char $SG3295[];
struct FUN_005e2c30_class
{
    char m0[0x3c];
    GO m3c;
    const char* __thiscall FUN_005e2c30();
};
struct FUN_005e2ca0_s
{
    void FUN_005e2ca0();
};
struct FUN_005e2c70_s : FUN_005e2ca0_s
{
    void* FUN_005e2c70(unsigned int flags);
};
struct SoundData
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
};
class TESForm
{
  public:
    virtual ~TESForm();
};
class TESSound : public TESForm
{
  public:
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
    SoundData soundData;
    unsigned char unk68;

    void FUN_004851b0(TESForm* form);
    SoundData CopyBig();

    void CopyFromSound(TESForm* form);
};
void __cdecl FUN_004858f0(unsigned int chunkId, unsigned char value);
void __cdecl AppendChunk(unsigned int chunkId, void* data, unsigned int size);
unsigned char __cdecl FUN_00401500();
struct FUN_005e2fa0_SoundFile
{
    void __thiscall FUN_0048cea0();
};
struct FUN_005e2fa0_SoundData
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
    void __thiscall SwapEndian();
};
struct FUN_005e2fa0_standin
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
    FUN_005e2fa0_SoundFile unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    FUN_005e2fa0_SoundData unk44;
    unsigned char unk68;

    void __thiscall FUN_004855a0();
    void __thiscall FUN_00485680();
    void __thiscall WriteToStream();
};
class TESSound;
struct ContNode;
int __cdecl FUN_00404dc0(char const* a, char const* b);
bool __fastcall FUN_008256d0(ContNode* node);
ContNode* __fastcall FUN_00726070(ContNode* node);
struct FUN_00408da0_Class
{
    int* FUN_00408da0();
};
struct ListNodeHelper
{
    void** FUN_006815c0();
};
class DataHandler
{
  public:
    BSSimpleList<TESSound*>* FUN_0045c650();
};
extern DataHandler* g_dataHandler;
TESSound* __cdecl FUN_005e3570(char const* filename);
int strcpy_s(char* dst, unsigned int size, const char* src);
int strcat_s(char* dst, unsigned int size, const char* src);
bool __cdecl FUN_005e39a0();
bool __cdecl ResolveArchivePath(const char*, char*, int);
BSSimpleList<char*>* __cdecl FUN_00afe420(const char*, char*, int, int);
unsigned int __cdecl DialogueRandom();
unsigned int __cdecl FUN_00ae9d80(const char*);
unsigned int __cdecl FUN_005a00a0(unsigned int);
extern unsigned int DAT_011caf04[10];
extern char DAT_011caf2c[10];
extern char DAT_011caf36;
template <class T> struct BSSimpleListEx : public BSSimpleList<T>
{
    int GetSize();
};
bool FindDialogueFile(char* a1);
extern bool DAT_011acdf9;
bool FUN_005e39a0();
int __cdecl GetFlagMask(unsigned int flags);
struct FUN_005e50f0_Obj
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
    int unk34[16];
    int GetValueByIndex(int index);
};
struct FUN_005e5190_Class
{
    unsigned char GetByte63();
};
struct Obj5e5300
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned char unk60;
    unsigned char unk61;

    unsigned int GetByte61();
};
struct FUN_005e5380_shell
{
    bool __thiscall IsFlag2Set();
};
struct FUN_0066e010_entry
{
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
};
struct G2
{
    void AddHead(int*);
};
struct FUN_005e5320_class
{
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    FUN_0066e010_entry m34;
    FUN_0066e010_entry m54;
    FUN_0066e010_entry m74;
    FUN_0066e010_entry m94;
    FUN_0066e010_entry mb4;
    FUN_0066e010_entry md4;
    FUN_0066e010_entry mf4;
    FUN_0066e010_entry m114;
    FUN_0066e010_entry m134;
    FUN_0066e010_entry m154;
    FUN_0066e010_entry m174;
    FUN_0066e010_entry m194;
    FUN_0066e010_entry m1b4;
    FUN_0066e010_entry m1d4;
    FUN_0066e010_entry m1f4;
    void __thiscall FUN_005e5320(G2* list);
};
struct FUN_005e5380_Class
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
    unsigned char unk60;

    bool __thiscall IsFlag2Set();
};
// 0x005e0d20 - ScriptRunner::Run-like: nested-run guard, climate-list loop,
// per-run expression object (ctor 0x593490 / dtor 0x483710), optional timing.
extern "C" __int64 DAT_011caec8;
extern "C" char g_nestedScriptRunFormat[];
extern "C" void* __fastcall FNV_GetObjectReference(void*);
__declspec(dllimport) long __stdcall QueryPerformanceCounter(__int64*);
__declspec(dllimport) long __stdcall QueryPerformanceFrequency(__int64*);
bool FUN_00702fc0();
void FUN_005b5e40(const char* fmt, int a, int b);
struct Clist
{
    char m0[8];
    unsigned int m8;
    char mC[5];
    unsigned char m11;
};
struct CL8
{
    unsigned char b0;
    unsigned char b1;
    float f4;
};
struct SLoc
{
    ~SLoc();
    char p0[0x10];
    CL8* m10;
    void FUN_005a8ea0();
};
struct Vt130
{
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
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
    virtual int v130();
};
struct A8 : Vt130
{
    bool FUN_004013e0();
    SLoc* CreateEventList();
    Clist* FUN_00500940();
    void FUN_005e1140(float value);
};
struct Big79
{
    Big79();
    ~Big79();
    char m[0x710];
};
struct Runner
{
    int m0;
    void* m4;
    SLoc* m8;
    int mC;
    int m10;
    A8* m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    char pad28[0xa1 - 0x28];
    bool m_a1;

    bool FUN_005e13a0(A8* a1, int* pv24, unsigned int* pi, int* pv14, int* pv20, bool b);
    bool FUN_005e1550(A8* a1, int v24, void* v20, int* pv14, unsigned int i, int* pv10, int count, int zero1,
                      int zero2);
    bool RunScript(A8* a1, void* a2, SLoc* a3, int a4, bool a5, char a6, char a7, float a8);
};
// Stand-in for the native TESBoundAnimObject base subobject (size 0x30).
class SoundBoundAnimBase
{
  public:
    virtual ~SoundBoundAnimBase();
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
};
class TESSoundFile
{
  public:
    virtual ~TESSoundFile();
    BSStringT<char> soundFile;
};
// Native TESSound destructor; both bases and the string member own their lifetimes.
class FUN_005e2ca0 : public SoundBoundAnimBase, public TESSoundFile
{
  public:
    BSStringT<char> editorID;
    virtual ~FUN_005e2ca0();
};
void BSEndian(unsigned int*, EndianSizeTag<0>);
void BSEndian(unsigned short*, EndianSizeTag<0>);
struct TESSound__SOUND_DATA
{
    unsigned char minAttenuation;
    unsigned char maxAttenuation;
    signed char frequencyAdjustment;
    unsigned char unk03;
    unsigned int soundFlags;
    unsigned short staticAttenuation;
    unsigned short stopTime;
    unsigned short attenuationCurve[5];
    unsigned short reverbAttenuation;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    signed char frequencyVariance;
    void SwapEndian();
};
struct InitTag5E35
{
};
void __cdecl FUN_00401080(int* p, InitTag5E35 tag);
void __cdecl FUN_00407a90(short* p, InitTag5E35 tag);
struct Data5E35
{
    int unk00;
    int m_04;
    short m_08;
    short m_0A;

    void FUN_005e3510();
};
void __cdecl operator delete(void*);
struct DeletingObject
{
    void FUN_005e4bc0();
    void* FUN_005e4b90(unsigned int flags);
};
class FUN_00483630_holder
{
  public:
    virtual ~FUN_00483630_holder();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
class TESModel
{
  public:
    virtual ~TESModel();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
class BGSPreloadable
{
  public:
    virtual void Preload();
};
class BGSBodyPartData
{
  public:
    virtual void ClearData();
};
class FUN_005e4bc0 : public FUN_00483630_holder, public TESModel, public BGSPreloadable
{
  public:
    virtual ~FUN_005e4bc0();
};
struct Skin55;
struct Part55
{
    void SetEntryStateByKey(unsigned short partition, bool visible);
};
struct Node55;
struct BaseObject55
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual Node55* IsSceneNode();
};
struct Object55 : BaseObject55
{
    Object55* FUN_009611e0();
};
struct Skin55 : BaseObject55
{
};
struct Node55 : Object55
{
    Object55* FUN_0043b4a0(unsigned int index);
    unsigned int FUN_0043b480();
};
struct Geometry55 : Object55
{
    Skin55* FUN_0043fad0();
};
struct Name55
{
    const char* FUN_007fa950();
};
extern const NiRTTI_S DAT_011f4acc;
extern "C" void* __cdecl FUN_00653270(const NiRTTI_S*, BaseObject55*);
extern "C" Object55* __cdecl FUN_004aae30(Object55*, const char*);
struct Body55
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
    Name55* names[15];
    void HidePartitionsUnderAncestor(Object55* ancestor, Object55* root, int excluded, Object55* object);
};
namespace s5e5d20 {

struct Actor
{
    float FUN_006b9130();
};

bool FUN_005e5b80(int iArg0, int iArg1, void* pvArg2, void* pvArg3, unsigned char ucArg4, float** ppfValue,
                  Actor* pkActor);

// @fnv 0x005e5d20
void FUN_005e5d20(void* pvArg0, void* pvArg1, unsigned char ucArg2, float** ppfValue, Actor* pkActor)
{
    if (!FUN_005e5b80(0, 1, pvArg0, pvArg1, ucArg2, ppfValue, pkActor))
        return;
    float* pfValue = *ppfValue;
    Actor* pkTarget = pkActor;
    *pfValue = pkTarget->FUN_006b9130() * *pfValue;
}

}
namespace s5e63f0 {

extern "C" const char DAT_010462c0[];

struct Base
{
    const char* m_pVtbl;

    Base* FUN_005e6420();
};

struct Derived : Base
{
    float m_fValue;

    Derived* FUN_005e63f0();
};

// @fnv 0x005e63f0
Derived* Derived::FUN_005e63f0()
{
    FUN_005e6420();
    m_pVtbl = DAT_010462c0;
    m_fValue = 0.0f;
    return this;
}

}
namespace s5e6420 {

extern "C" const char DAT_010462e0[];

struct Holder
{
    const char* m_pTable;

    Holder* FUN_005e6420();
};

// @fnv 0x005e6420
Holder* Holder::FUN_005e6420()
{
    m_pTable = DAT_010462e0;
    return this;
}

}
extern void* DAT_01046320;
struct FUN_005e6510_cls
{
    void* vtbl;
    int m4;
    void FUN_005e6420();
    FUN_005e6510_cls* FUN_005e6510();
};
extern int DAT_01048bb4, DAT_01048ba0, DAT_01048b88, DAT_01048b68, DAT_01048b54;
struct FUN_00483370
{
    void* table_00;
    unsigned int unknown_04, unknown_08, unknown_0c, unknown_10, unknown_14;
    FUN_00483370();
    ~FUN_00483370();
};
struct FUN_00402d00
{
    void* table_18;
    unsigned int unknown_1c, unknown_20;
    FUN_00402d00();
    ~FUN_00402d00();
};
struct FUN_00482c50
{
    void* table_24;
    unsigned int unknown_28;
    FUN_00482c50();
};
struct FUN_0048e270
{
    void* table_2c;
    unsigned int unknown_30, unknown_34;
    FUN_0048e270();
    ~FUN_0048e270();
};
struct FUN_0047ff70
{
    void* table_38;
    FUN_0047ff70();
    ~FUN_0047ff70();
};
struct FUN_005f6610 : FUN_00483370, FUN_00402d00, FUN_00482c50, FUN_0048e270, FUN_0047ff70
{
    FUN_005f6610();
    void FUN_004f15a0(int);
    void FUN_005f67c0();
};
struct FUN_005e07d0
{
    virtual ~FUN_005e07d0();
};
struct FUN_005e9830 : Stub
{
    virtual ~FUN_005e9830();
};
struct EquivData_5ecd10
{
    short sValue00;
    short sValue02;
    float fValue04;
    float fValue08;
    float fValue0C;
    float fValue10;
    float fValue14;
    float fValue18;
    float fValue1C;
    float fValue20;
    float fValue24;

    bool IsEqual(const EquivData_5ecd10& other);
};
struct BSSimpleArrayActor
{
    void Clear(bool);
};
struct FUN_005ef3b0_class : BSSimpleArrayActor
{
    int* p;
    void FUN_005ef3b0();
};
struct FUN_005efbc0_s
{
    virtual void v0();
    virtual int v4(unsigned int);
    void ConstructItems(int, unsigned int);
};
struct FUN_005efd40_s : FUN_005efbc0_s
{
    int m4;
    int m8;
    int mc;
    void FUN_005efd40(unsigned int requested, unsigned int savedSize);
};

struct LocalFormArray
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    LocalFormArray();
    ~LocalFormArray();
    void SetSize(unsigned int);
    void SetGrowth(int);
};
struct LocalString
{
    char* data;
    unsigned short size, capacity;
    LocalString();
    ~LocalString();
    bool Set(const char*, unsigned int);
};
struct LocalState
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
};
struct FUN_005ff890
{
    LocalFormArray first;
    LocalFormArray second;
    LocalString name;
    LocalState state;
    FUN_005ff890(const char*);
};
// @fnv 0x005ff890
FUN_005ff890::FUN_005ff890(const char* text)
{
    name.Set(text, 0);
    first.SetSize(1);
    first.SetGrowth(1);
    second.SetSize(1);
    second.SetGrowth(1);
    memset(&state, 0, sizeof(state));
}
