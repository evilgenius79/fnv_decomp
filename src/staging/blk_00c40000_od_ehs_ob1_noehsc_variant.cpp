
// src/staging/blk_00c40000_od_ehs_ob1_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHs /Gy /Ob1 (unit src/staging/blk_00c40000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00c40000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
extern int DAT_010c1670;
struct FUN_00c40990_Class {
    void __thiscall FUN_00c40990();
};
struct FUN_00c42b60_class {
    int __thiscall FUN_00c42b80();
    int a;
    int b;
    void FUN_00c42b60();
};
void __cdecl EnsureArenaAllocated(void*);
struct FUN_00c42da0_Class {
    virtual void vfn_0000();
    virtual void vfn_0004();
};
int __stdcall FUN_00c42da0(FUN_00c42da0_Class* p);
struct FUN_00c430a0_class
{
    int __thiscall FUN_00c430a0(int);
};
struct FUN_00c430b0_class {
    void __thiscall FUN_00a99c40(int a1, int a2);
    void __thiscall FUN_00c430b0(int a1, int a2);
};
struct NiStream;
struct NiIntegerExtraData { void LoadBinary(NiStream&); };
struct FUN_00c430d0 : public NiIntegerExtraData { void LoadBinary(NiStream&); };
struct NiAVObject;
struct NiBinaryExtraData {
    void FUN_00a9af00(NiAVObject* a);
    void FUN_00c430f0(NiAVObject* a);
};
struct FUN_00c43140_StandIn {
    void FUN_00a9a4e0(int a);
    void FUN_00c43140(int a);
};
struct NiStringExtraData {
    char* m_p;
    char IsEqual(const char*);
    char FUN_00c43160(const char* other);
};
char NiStringExtraData::IsEqual(const char* other)
{
    return 0;
}
struct NiFixedString;
extern NiFixedString* DAT_01202ddc;
struct NiAVObject { void SetName(const NiFixedString&); void FUN_00c43470(); };
extern "C" void* g_01202de0;
struct FUN_00c43650_Class {
    void* __thiscall FUN_00c43650();
};
struct NiNode {
    void __thiscall ReadChildListFromStream(void*);
};
struct FUN_00c43900_class {
    void __thiscall FUN_00c43900(void* apParam);
};
extern "C" void* g_01202de8;
struct FUN_00c43cf0_Class {
    void* __thiscall FUN_00c43cf0();
};
struct FUN_00c43d60_cls {
    char pad[0x108];
    int m_pSelf;
    char InitSelfPointer(int a);
};
extern "C" void __cdecl FUN_00c80240(void*);
struct FUN_00c44940_Class {
    void __thiscall FUN_00c44940();
};
struct FUN_00c44960_class {
    void __thiscall CallStoredCallback();
    void __thiscall FUN_00c44960();
};
struct FUN_00c44cb0_class {
    void* m0;
    void* m1;
    void* m2;
    void CallStoredCallback();
};
extern int DAT_010178bc;
void __cdecl FUN_00a5e930(void*);
struct FUN_00c44e20 {
    void FUN_00a5e930();
    ~FUN_00c44e20();
};
struct FUN_00c452a0_Class {
    void __thiscall ReadChildListFromStream(int a);
    void __thiscall FUN_00c452a0(int a);
};
struct NiStream;
struct FUN_00a5e5b0_helper {
    unsigned char RegisterChildStreamables(NiStream*);
};
struct FUN_00c452c0_class {
    unsigned char FUN_00c452c0(NiStream*);
};
extern char const* const g_01202e7c_arg1;
struct FUN_00c457d0_Class
{
    char const* const* __thiscall FUN_00c457d0();
};
extern unsigned short DAT_01202e2c;
bool FUN_00c45ab0();
struct NiStream;
struct NiPSysModifier {
    void LinkObject(NiStream&);
    void FUN_00c467f0(NiStream& stream);
};
struct FUN_00c46810_Class {
    void __thiscall FUN_00c31670(int);
    void __thiscall FUN_00c46810(int);
};
extern "C" void* g_01202e74;
struct FUN_00c47650_Class {
    void* __thiscall FUN_00c47650();
};
struct P03MM { void* Allocate(unsigned int); void* AllocateScaled(unsigned int count); };
extern P03MM g_memoryManager;
struct FUN_00c4aae0_class {
    void __thiscall CopyStateTo(int a, int b);
    void __thiscall FUN_00c4aae0(int a, int b);
};
struct FUN_00c4ab40_class {
    void __thiscall FUN_00c45220(int);
    void __thiscall FUN_00c4ab40(int);
};
struct FUN_00c452a0_class {
    void FUN_00c452a0(int a);
};
void FUN_00c452a0_class::FUN_00c452a0(int a)
{
}
struct FUN_00c4ab60_class {
    void FUN_00c4ab60(int a);
};
struct FUN_00c4abb0_class {
    void FUN_00c452f0(int);
    void FUN_00c4abb0(int a);
};
struct FUN_00c4abd0_class {
    char FUN_00c45380(int);
    char FUN_00c4abd0(int a1);
};
extern "C" void* g_01202e7c;
struct FUN_00c4ac90_Class {
    void* __thiscall FUN_00c4ac90();
};
struct FUN_00c4ad40_class {
    void __thiscall CopyStateTo(int, int);
    void __thiscall FUN_00c4ad40(int a, int b);
};
extern "C" void __cdecl FUN_00c45220(int);
struct FUN_00c4ada0_Class {
    void __thiscall FUN_00c4ada0(int a);
};
struct FUN_00c4ade0_class {
    unsigned char FUN_00c452c0(int);
    unsigned char FUN_00c4ade0(int);
};
struct FUN_00c4ae10_Class {
    void FUN_00c452f0(int);
    void FUN_00c4ae10(int a);
};
struct FUN_00c4ae30_class {
    unsigned char FUN_00c45380(unsigned int a);
    unsigned char FUN_00c4ae30(unsigned int a);
};
extern int g_01202e84;
struct FUN_00c4aef0_Class {
    int* __thiscall FUN_00c4aef0();
};
struct FUN_00c4afa0_class {
    void __thiscall CopyStateTo(int a, int b);
    void __thiscall FUN_00c4afa0(int a, int b);
};
struct FUN_00c4b000_class {
    void __thiscall FUN_00c45220(int);
    void __thiscall FUN_00c4b000(int a);
};
struct FUN_00c4b020_Class {
    void __thiscall FUN_00c452a0(int);
    void __thiscall FUN_00c4b020(int a);
};
struct FUN_00c452f0_cls {
    void __thiscall FUN_00c452f0(int a1);
};
void __thiscall FUN_00c452f0_cls::FUN_00c452f0(int a1)
{
}
struct FUN_00c4b070_cls {
    void __thiscall FUN_00c4b070(int a1);
};
struct GlobalObject_00a7b610;
extern GlobalObject_00a7b610 g_01202e8c;
struct FUN_00c4b210_Class {
    GlobalObject_00a7b610* FUN_00c4b210();
};
struct NiNode;
struct NiNode_Helper { void CopyMemberData(NiNode* a, void* b); };
struct FUN_00c51550 : NiNode_Helper { void __thiscall Copy(NiNode* a, void* b); };
struct FUN_00c51570_Class {
    void* __thiscall FUN_00a5ea70(void* arg);
    void* __thiscall FUN_00c51570(void* arg);
};
struct BaseT {
    ~BaseT();
};
struct FUN_00c516d0 : BaseT {
    void DoIt();
};
extern void* g_01203110;
struct FUN_00c516f0_Class {
    void* __thiscall FUN_00c516f0();
};
extern const char* const g_011df0c0_arg1;
struct FUN_00c52870_class
{
    const char* const* FUN_00c52870();
};
struct FUN_00c54dc0_class {
    int __thiscall FUN_00c54dc0(int);
};
struct NiStream;
struct NiExtraData {
    void LinkObject(NiStream&);
};
struct BSBound : NiExtraData {
    void FUN_00c54e70(NiStream& stream);
};
struct FUN_00a7b290_shell {
    bool FUN_00a7b290(int);
    int FUN_00c54e90(int arg);
};
extern "C" void* g_012031e8;
struct FUN_00c55320_Class {
    void* __thiscall FUN_00c55320();
};
struct FUN_00c5b5d0_class {
    unsigned int FUN_00c5b5d0();
};
struct NiStream;
struct NiPSysEmitterCtlr {
    void LinkObject(NiStream&);
};
struct BSPSysMultiTargetEmitterCtlr : NiPSysEmitterCtlr {
    void FUN_00c5cc90(NiStream& stream);
};
struct NiStream;
struct FUN_00c1be10_shell {
    bool RegisterEmitterInterpolatorStreamables(NiStream&);
    char FUN_00c5ccb0(NiStream&);
};
extern int g_01203340;
struct FUN_00c5cea0_Class {
    int* __thiscall FUN_00c5cea0();
};
extern int DAT_010c2e7c;
struct FUN_00a744a0 {
    void* vtbl;
    FUN_00a744a0();
};
FUN_00a744a0::FUN_00a744a0()
{
}
struct FUN_00c5ceb0 : public FUN_00a744a0 {
    FUN_00c5ceb0();
};
extern "C" void __fastcall FUN_00a89760(void*);
extern int DAT_010c2e7c;
struct FUN_00c5cfb0 {
    virtual void vfn();
    void FUN_00a89760();
    ~FUN_00c5cfb0();
};
struct StrArr;
struct Caller74690 {
    void FUN_00a74690(StrArr*);
    void ForwardTo74690(StrArr* p);
};
extern "C" void* g_01203348;
struct FUN_00c5d2a0_Class {
    void* __thiscall FUN_00c5d2a0();
};
struct FUN_00c5dcb0_class {
    void SetShortAtOffsetBA(short param);
};
extern "C" void* g_0120436c;
struct FUN_00c5ec90_class
{
    void* __thiscall GetGlobalPtr();
};
struct GlobalObject_00a7b610 {
    GlobalObject_00a7b610* __thiscall GetGlobalInstance();
};
extern GlobalObject_00a7b610 g_01204378;
extern int DAT_010c31a4;
struct Unk_00a5e930 {
    void __thiscall FUN_00a5e930();
};
struct FUN_00c5faa0 {
    void FUN_00a5e930();
};
extern const char* const g_01201f84_arg1;
struct FUN_00c5fc60_class {
    const char* const* FUN_00c5fc60();
};
extern void* DAT_010c32c4;
struct NiPSysPositionModifier { NiPSysPositionModifier(); };
struct FUN_00c5fd30 : NiPSysPositionModifier {
    FUN_00c5fd30();
};
NiPSysPositionModifier::NiPSysPositionModifier() {}
struct FUN_00c5ffb0_Class {
    void __thiscall FUN_00c31670(int param);
    void __thiscall FUN_00c5ffb0(int param);
};
extern int DAT_010c30b8;
void NiFreeAlias(void*);
struct FUN_00c5eb60_Class {
    int m0;
    int m1;
    void ResetAndFreeAlias();
};
void __cdecl FUN_00c3f8c0();
struct MemoryManager { void Deallocate(void*); };
struct FUN_00c40930_Class {
    void __thiscall FUN_00c3f8c0();
    void* __thiscall FUN_00c40930(unsigned int flags);
};
void __cdecl FUN_00c43070(void*);
struct FUN_00c43620_Class {
    void __thiscall FUN_00c43070();
    void* __thiscall FUN_00c43620(unsigned int flags);
    static void __cdecl operator delete(void* p, unsigned int size);
};
struct FUN_00c43850_Class {
    void __thiscall ForwardToBase(void* dst, unsigned int size);
    void __thiscall FUN_00c43850(void* dst, unsigned int size);
};
extern "C" char* __cdecl _strchr(const char*, int);
extern "C" int __cdecl _strcpy_s(char*, unsigned int, const char*);
void __cdecl CopyMainNameFromPath(int param_1, char* param_2);
void __cdecl EnsureArenaAllocated(void*);
struct FUN_00c448f0_Class {
    char pad[0x50];
    int m50;
    int m54;
    int m58;
    void __thiscall FUN_00c448f0();
};
struct FUN_00c44cd0_class {
    void __thiscall FUN_00c44cd0();
    void __thiscall WaitForWorkers();
};
struct FUN_00c44c40_class {
    void __thiscall FUN_00c44c40(int a1, int a2);
};
struct FUN_00c455a0_Class {
    void __thiscall FUN_00c455a0(unsigned char);
};
struct FUN_00c5fb60_Class {
    void __thiscall ForwardToBase(int a, int b);
};
struct FUN_00c451b0_class {
    void __thiscall CopyStateTo(int a, int b);
};
extern int DAT_011af758;
void FUN_00c45820(int value);
int FUN_00c45ad0();
extern unsigned short DAT_01202e2e;
void __cdecl FUN_00c45b10(unsigned short value);
struct NiPSysModifier;
struct CloningProcess;
struct NiPSysModifier_StandIn : public NiPSysModifier {
    void __thiscall CopyMemberData(NiPSysModifier*, CloningProcess&);
    char pad[0x18];
    float m_f;
    void __thiscall CopyModifier(NiPSysModifier_StandIn* dst, CloningProcess& proc);
};
struct SStream;
struct SObj;
void __cdecl CallAnimCallback(SStream*, SObj*);
struct FUN_00c46830_class {
    void __thiscall FUN_00c31950(NiStream* stream);
    void __thiscall Load(NiStream* stream);
};
void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int size);
struct FUN_00c4a640_class {
    void __thiscall FUN_00c4a640(char* dst, char* src, unsigned int count);
};
extern "C" void* g_01202e7c;
extern "C" void* __cdecl FUN_00a7d330(void*);
struct NiTPrimitiveArray_unsigned_int_ {
    void AddFirstEmpty(unsigned int&);
};
struct FUN_00c4ab00_Class {
    void __thiscall FUN_00c454c0(int);
    void __thiscall FUN_00c4ab00(int a);
};
struct FUN_00c4f2d0_class {
    void __thiscall FUN_00c4f2d0();
};
struct FUN_00c5dcd0_Class {
    void __thiscall FUN_00c5dcd0(void* a);
};
struct FUN_00c50f30_Class {
    FUN_00c5dcd0_Class* __thiscall GetEntryValue(int a);
};
struct FUN_00c505c0_Class {
    void __thiscall FUN_00c505c0(int a, void* b);
};
void __cdecl FNV_Warning(const char* fmt, ...);
struct FUN_00c50f30_class {
    int __thiscall GetEntryValue(int a);
};
extern int DAT_0106c814;
extern int DAT_010c256c;
struct FUN_00c51640_Class {
    const char* s;
    int i;
    unsigned char b;
    int d;
    unsigned char c;
    int p;
    void* __thiscall FUN_00c51640();
};
struct FUN_00878690_shell {
    void __thiscall FUN_00c51df0();
};
void __cdecl operator delete(void* ptr, unsigned int size);
struct FUN_00c52830_class {
    void* __thiscall FUN_00c52830(unsigned int flags);
};
struct NiStream;
struct NiColor {
    void SaveBinary(NiStream&);
};
struct NiExtraDataSaveHelper {
    void SaveBinary(NiStream&);
};
struct FUN_00c54ec0_class {
    void __thiscall FUN_00c54ec0(NiStream& stream);
};
struct FUN_00a7b300_shell { void __thiscall FUN_00a7b300(); };
struct FUN_00c55330_class {
    void* __thiscall FUN_00c55330(unsigned int flags);
    void operator delete(void* p, unsigned int size);
};
extern int DAT_010c2d54;
struct FUN_00c1c280_class {
    void __thiscall FUN_00c1c280(int a);
};
struct FUN_00c5c3c0_class : FUN_00c1c280_class {
    int __thiscall InitWithParams(int a, int b, unsigned short c);
};
extern int DAT_010c2d54;
struct FUN_00c1c390_Class {
    void __thiscall FUN_00c1c390();
};
struct FUN_00c5c400_Class : FUN_00c1c390_Class {
    void* vtbl;
    char pad[0x5c - 4];
    int m_0x5c;
    unsigned short m_0x60;
    FUN_00c5c400_Class* __thiscall FUN_00c5c400();
};
struct NiStream;
void __cdecl FUN_00a303a0(NiStream&, unsigned short*);
struct S_00c1be40 {
    void FUN_00c1be40(NiStream& stream);
};
struct FUN_00c5cce0_Class {
    char pad[0x5c];
    int m_0x5c;
    void __thiscall FUN_00c5cce0(NiStream& stream);
};
struct FUN_00c1be60_StandIn {
    unsigned char __thiscall FUN_00c1be60(void*);
    char FUN_00c5cd20(void* other);
};
struct FUN_00c5ced0 : FUN_00a744a0 {
    FUN_00c5ced0(int a, int b, int c, int d);
};
struct FUN_00c5cfd0_class {
    void __thiscall FUN_00c5cfd0(int a, int b, int c, int d);
};
extern "C" void __cdecl FUN_00c65530();
extern "C" void __cdecl FUN_00c55200();
extern "C" void __cdecl FUN_00c546c0();
extern "C" void __cdecl FUN_00c618f0();
extern "C" void __cdecl FUN_00c5f240();
extern "C" void __cdecl FUN_00c616c0();
extern "C" void __cdecl FUN_00c43500();
extern "C" unsigned char DAT_01204364;
void __cdecl FUN_00c5d4e0();
extern unsigned char DAT_01204364;
void __cdecl FUN_00c655d0();
void __cdecl FUN_00c552a0();
void __cdecl FUN_00c54760();
void __cdecl FUN_00c61990();
void __cdecl FUN_00c5f2e0();
void __cdecl FUN_00c61760();
void __cdecl FUN_00c435a0();
void __cdecl FUN_00c5d520();
struct FUN_00c5dea0_Entry {
    unsigned char mFlag;
};
struct FUN_00c5dea0_Class {
    int* pData;
    unsigned short mCount;
    void __thiscall FUN_00c5dea0();
};
struct FUN_00c5e560_class : public NiNode_Helper {
    void __thiscall FUN_00c5e560(NiNode* a, void* b);
};
struct FUN_00c5db90_Class {
    void __thiscall FUN_00c5db90();
};
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00c5eb20_Class {
    void* __thiscall FUN_00c5eb20(unsigned int flags);
};
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00c5ed60_Class {
    void __thiscall FUN_00c5ed60();
};
struct FUN_00c5f360_Class {
    void* __thiscall FUN_00c5f360(unsigned int flags);
};
struct FUN_00c5f390_class {
    void __thiscall FUN_00c5f390(int a, int b);
};
struct FUN_00c5f500_class {
    void __thiscall FUN_00c5f500(FUN_00c5f500_class* other);
    int pad;
    int* data;
    unsigned int count;
};
struct FUN_00c5fc20_class {
    void* __thiscall FUN_00c5fc20(unsigned int flags);
    void __cdecl operator delete(void* p, unsigned int size);
    void __thiscall FUN_00c5faa0();
};
struct BaseForCall { bool FUN_00a5e600(NiObject*); };
struct NiObject {
    char pad[0xb0];
    int p;
    unsigned char flag;
};
struct FUN_00c439b0_class : BaseForCall {
    char FUN_00c439b0(NiObject* apParam);
};
struct RefCountedObject {
    virtual ~RefCountedObject();
    virtual void vfn_0004();
    volatile long m_lObjectReferenceCount;
};
struct FUN_00c46270_Class {
    RefCountedObject* m_pObject;
    FUN_00c46270_Class& __thiscall AssignRefCounted(const FUN_00c46270_Class& other);
};
extern GlobalObject_00a7b610 g_01202e60;
struct FUN_00c46960_Class {
    GlobalObject_00a7b610* FUN_00c46960();
};
struct Elem_00c48a10 { int p; int a; int b; };
struct Arr_00c48a10 {
    int _0;
    Elem_00c48a10* m_pData;
    int _8;
    int m_iCapacity;
    void FUN_00c4a1e0(int, bool);
};
struct FUN_00c48a10_t {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    Arr_00c48a10 m_kArray;
    int _24;
    int m_iArrayLength;
    void ShiftElements(int iDelta, bool bClear);
};
struct FUN_00c4a9c0_class {
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08(void*);
    void* m_p;
    unsigned int m_uiItemCount;
    int m_auiShapeKeys;
    void __thiscall ReleaseBuffer(unsigned char a);
};
void* __cdecl NiMalloc(unsigned int);
struct FUN_00c5ec10_Class {
    int* vtbl;
    void* m0;
    unsigned short m1;
    unsigned short m2;
    unsigned short m3;
    unsigned short m4;
    FUN_00c5ec10_Class(unsigned short a, unsigned short b);
};
extern int DAT_010c1b2c;
struct FUN_00c5f570_Class {
    void __thiscall FUN_00c5f570();
};
struct FUN_00c450d0 : FUN_00c5f570_Class {
    int vtbl;
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned char b8;
    unsigned char b9;
    unsigned char ba;
    unsigned char bb;
    unsigned char bc;
    unsigned char bd;
    unsigned char be;
    unsigned char bf;
    unsigned char c0;
    unsigned char c1;
    unsigned char c2;
    unsigned char c3;
    unsigned char c4;
    unsigned char c5;
    unsigned char c6;
    unsigned char c7;
    unsigned char c8;
    unsigned char c9;
    unsigned char ca;
    unsigned char cb;
    unsigned char cc;
    unsigned char cd;
    unsigned char ce;
    unsigned char cf;
    unsigned char d0;
    unsigned char d1;
    unsigned char d2;
    unsigned char d3;
    unsigned char d4;
    unsigned char d5;
    unsigned char d6;
    unsigned char d7;
    unsigned char d8;
    unsigned char d9;
    unsigned char da;
    unsigned char db;
    unsigned char dc;
    unsigned char dd;
    unsigned char de;
    unsigned char df;
    unsigned char e0;
    unsigned char e1;
    unsigned char e2;
    unsigned char e3;
    unsigned char e4;
    unsigned char e5;
    unsigned char e6;
    unsigned char e7;
    unsigned char e8;
    unsigned char e9;
    unsigned char ea;
    unsigned char eb;
    unsigned char ec;
    unsigned char ed;
    unsigned char ee;
    unsigned char ef;
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    unsigned char f4;
    unsigned char f5;
    unsigned char f6;
    unsigned char f7;
    unsigned char f8;
    unsigned char f9;
    unsigned char fa;
    unsigned char fb;
    unsigned char fc;
    unsigned char fd;
    unsigned char fe;
    unsigned char ff;
    unsigned char a0;
    unsigned char a1;
    unsigned char a2;
    unsigned char a3;
    unsigned char a4;
    unsigned char a5;
    unsigned char a6;
    unsigned char a7;
    unsigned char a8;
    unsigned char a9;
    unsigned char aa;
    unsigned char ab;
    unsigned char ac;
    unsigned char ad;
    unsigned char ae;
    unsigned char af;
    FUN_00c450d0();
};
struct FUN_00c465a0_class {
    void* operator new(unsigned int);
    FUN_00c465a0_class();
    char pad[0x1c];
};
struct FUN_00c46670_class {
    void* __thiscall FUN_00c46670(CloningProcess& process);
};
struct FUN_00c465a0 {
    char* p;
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    FUN_00c465a0();
    ~FUN_00c465a0();
    static void* operator new(unsigned int);
};
FUN_00c465a0* __cdecl FUN_00c46740();
struct FUN_00c48fe0_Class {
    int m_0000;
    int m_0004;
    int m_0008;
    int m_000c;
    int m_0010;
    int m_0014;
    int m_0018;
    int m_001c;
    int m_0020;
    int m_0024;
    int m_0028;
    int FUN_00c48fe0();
};
struct FUN_00c4a5a0_class {
    virtual void vfn_0000();
    virtual void* vfn_0004(unsigned int);
    void* m1;
    unsigned int m2;
    unsigned int m3;
    void __thiscall FUN_00c4a5a0(unsigned int a, unsigned int b);
};
struct CloningProcess;
struct NiBinaryExtraData;
struct NiFloatsExtraData;
struct NiExtraData_Shell {
    void FUN_00a7b330(NiBinaryExtraData*, CloningProcess*);
};
struct FUN_00c54dd0 : NiExtraData_Shell {
    void FUN_00a7b330(NiBinaryExtraData*, CloningProcess*);
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
};
struct FUN_00c54dd0_3i {
    int x;
    int y;
    int z;
};
struct Elem4 { void FUN_008228f0(int); };
struct FUN_0042fb60_shell { void FUN_0042fb60(char*, char*, unsigned int); };
struct FUN_00c5bef0_class {
    char* m0;
    char* m1;
    unsigned int m2;
    void RemoveRange(unsigned int a, unsigned int b);
};
struct NiObject;
struct NiStream {
    NiObject* DeserializeObject();
};
void __cdecl FUN_00a30370(NiStream*, void const*);
struct FUN_00c5cc30_class {
    void LoadBinary(NiStream&);
    void FUN_00c5cc30(NiStream&);
};
char* __cdecl FUN_00a7d330(char const*);
char* __cdecl FUN_00a7d510(char const*, unsigned int);
struct FUN_00c5d610_StandIn {
    unsigned int FUN_0044f890(NiTPrimitiveArray_unsigned_int_&);
};
struct FUN_00c5d610_Class {
    unsigned int __thiscall AddRegSettingsStrings(NiTPrimitiveArray_unsigned_int_& arr);
};
int __cdecl FUN_00c33090(int);
int __cdecl GetStateResult(int* apParams);
struct FUN_00c5e620_Class {
    void __thiscall FUN_00c5e620(NiStream* stream);
};
struct NiNode_LoadBinary_StandIn {
    void __thiscall LoadBinary(NiStream* stream);
};
struct NiStream_ReadMultipleLinkIDs_Helper {
    unsigned int __thiscall ReadUnsignedInteger();
};
struct ObjA { void __thiscall FUN_0044dd60(); };
struct FUN_00c40910_Class {
    ObjA* m_p;
    void __thiscall CallObjA();
};
struct FUN_00c42060_Class {
    virtual void vfn_0000();
    virtual void vfn_0004();
    int m4;            // +0x4
    int m8;            // +0x8
    char pad[0xc];
    unsigned char m18; // +0x18
    void __thiscall SetArg(int arg);
};
extern int DAT_010c1844;
extern "C" __declspec(dllimport) void __stdcall FreeLibrary(void*);
extern "C" __declspec(dllimport) void __stdcall DeleteObject(void*);
void __fastcall DestroyResources(void* thisPtr);
extern int DAT_010a0d24;
extern int DAT_010c1854;
struct FUN_00c43070_shell {
    void FUN_00a7b300();
    void FUN_00c43070();
};
struct NiExtraDataX {
    virtual void vfn_0000();
    virtual void* vfn_0004();
    virtual void* vfn_0008();
};
struct NiAVObjectX {
    NiExtraDataX* GetExtraData(NiFixedString* name);
};
extern void* _g_01202de0;
void* GetExtraDataChecked(NiAVObjectX* obj);
extern int DAT_010c195c;
struct FUN_00c43660 : FUN_00c5f570_Class {
    char pad[0xb0];
    int f1;
    int f2;
    FUN_00c43660();
};
struct NiNode_StandIn {
    void FUN_00c438a0(NiStream& stream);
};
void __cdecl ReadBinaryValue(NiStream& stream, unsigned int& value);
void __cdecl FUN_00a643b0(NiStream& stream, unsigned int& value);
struct BSValueNode_StandIn : NiNode_StandIn {
    char pad[0xac];
    unsigned int m_field_ac;
    unsigned int m_field_b0;
    void FUN_00c438a0(NiStream& stream);
};
struct FUN_00c43920_class {
    char FUN_00c43920(NiStream* stream);
};
struct MyBase {
    void __thiscall FUN_00a5e880(NiStream& stream);
};
void __cdecl FUN_00a29550(NiStream& stream, unsigned char* p);
struct FUN_00c43950_Class : MyBase {
    void __thiscall FUN_00c43950(NiStream& stream);
};
struct FUN_00c43cb0_class {
    void __thiscall FUN_00c5faa0();
    void* __thiscall FUN_00c43cb0(unsigned int flags);
};
struct FUN_00c457e0_class {
    char pad[0xb0];
    void __thiscall FUN_00c5faa0();
    void* __thiscall FUN_00c457e0(unsigned int flags);
};
struct FUN_00c46230_Class {
    void* m0;
    void __thiscall FUN_00c46230();
};
void __cdecl FUN_00c31750();
struct FUN_00c46930_class {
    void __thiscall FUN_00c31750();
    void* __thiscall FUN_00c46930(unsigned int flags);
};
struct A51BF0Base {
    char pad[0xb4];

    static void* __cdecl operator new(unsigned int size);
    A51BF0Base();

    void __thiscall FUN_00c46c30(A51BF0Base* copy, int a);
    A51BF0Base* __thiscall FUN_00c46ba0(int a);
};
struct GO {
    void operator=(void*);
};
struct NiStreamHelper {
    void* __thiscall GetLoadedObject();
};
struct FUN_00c46cd0_Class {
    char pad[0xac];
    GO m_go;

    void __thiscall LoadFromStream(void* stream);
};
struct FUN_00c46af0 {
    void __thiscall Destruct();
    void* __thiscall FUN_00c47610(unsigned int flags);
};
struct FUN_00c47a00_Class {
    char pad0[0x18];
    char* m18;             // +0x18
    char pad1[0x4];
    int m20;               // +0x20
    char pad2[0x4];
    int m28;               // +0x28
    void FUN_00c47a00();
};
struct FUN_00c47a70_Class {
    void FUN_00c47a70();
};
struct FUN_006dc6e0_Class
{
    virtual void* v0();
    virtual char* v4(unsigned int);
    virtual void v8(char*);
    virtual char* vc(char*, unsigned int);

    char* m_p;
    unsigned int m_ucUnknownByte;
    unsigned int m_uiFilterValue;

    void __thiscall FUN_006dc6e0(char*, char*, unsigned int);
    void __thiscall FUN_00c4a4e0(unsigned int, unsigned int);
};
struct FUN_00c4a960_Class {
    void FUN_00c4a840();
    void* FUN_00c4a960(unsigned int flags);
};
struct FUN_00c4ab80_class {
    unsigned char FUN_00c452c0(int);
    char FUN_00c4ab80(int a);
};
unsigned int __cdecl _FUN_00a7d330(int a);
struct FUN_00c4ad60_class : public FUN_00c4ab00_Class {
    void __thiscall AddFirstEmptyFromGlobal(int a);
};
template <class T>
class NiTPrimitiveArray {
public:
    unsigned int AddFirstEmpty(const T& value);
};
unsigned int __cdecl _FUN_00a7d330(void*);
struct FUN_00c4afc0_class {
    void __thiscall AddValueToArray(NiTPrimitiveArray<unsigned int>* array);
};
struct FUN_00c4b090_class {
    char FUN_00c4b090(int a1);
};
struct FUN_00c4c920_class {
    unsigned int reserved;
    unsigned int* data;
    unsigned short capacity;
    unsigned short used;
    unsigned short nonNullCount;

    void __thiscall FUN_00c4c920(unsigned int count);
};
void* _NiMalloc(unsigned int size);
void NiFree(void* ptr);
struct FUN_00c4f270_Class {
    char pad[0x90];
    int m_type;
    char pad2[0x28];
    int m_uiItemCount;
    int m_aiEntries[1];
    void __thiscall FUN_00c4f270(int aeType);
};
struct NiPSysEmitterCtlr_StandIn {
    void CopyMemberData(NiPSysEmitterCtlr_StandIn*, void*);
    void FUN_00c5cb20(NiPSysEmitterCtlr_StandIn* a, void* b);
};
struct FUN_00c5ce40_Class {
    int PopFrontNode();
};
struct FUN_00c5d260_view {
    void __thiscall Destruct();
    static void __cdecl operator delete(void* p, unsigned int sz);
};
struct FUN_00c5d260 : FUN_00c5d260_view {
    void* __thiscall FUN_00c5d260_method(unsigned int flags);
};
extern double runtimeInitializationDouble5;
extern double DAT_01034208;
float __cdecl EvaluateQuinticPolynomial(float x);
float FUN_00c5d300(float a, float b, float c);
struct NiObjectNET_stub {
    void FUN_00a5c6a0(int);
};
struct FUN_00c5de70_stub {
    void FUN_00c5de70();
};
struct FUN_00c5e6f0_class {
    void FUN_00c5e6f0(int a);
};
struct FUN_00c5e720_Class {
    unsigned char FUN_00c5e720(NiStream* stream);
};
struct FUN_00c5ede0_Class {
    int __thiscall GetEntryAt(int a);
};
struct S_00a953b0_Node {
    void __thiscall CopyMemberData(S_00a953b0_Node*, void*);
};
struct FUN_00c5fb60_class : public S_00a953b0_Node {
    void __thiscall ForwardToBase(S_00a953b0_Node*, void*);
};
struct FUN_00c25d40_Class {
    void __thiscall ResetEntry(unsigned short);
};
struct FUN_00c5fd70_Class {
    void __thiscall FUN_00c5fd70(void* a, unsigned short b);
};
struct NiPSysModifier_00c31950 {
    void FUN_00c31950(NiStream*);
};
struct FUN_00c5ffd0 : NiPSysModifier_00c31950 {
    void Method(NiStream* stream);
};
struct C40B20Timer {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned __int64 m_uiElapsedTime;

    void FUN_00c40b20();
};
struct S_0044dd60 {
    void __thiscall FUN_0044dd60();
};
extern "C" void (__stdcall *FUN_00fdf1c0)(void*);
struct FUN_00c41050_Class {
    S_0044dd60* m_pIntegerData;

    FUN_00c41050_Class* __thiscall AssignRef(S_0044dd60** other);
};
struct FUN_00c42b60_class;
struct SpawnHeap_cls { void __thiscall FUN_00aa4060(void* pObject); };
extern "C" char DAT_011f6238;
typedef void (__stdcall *S_00c422d0_IAT_Fn)(void*);
extern "C" S_00c422d0_IAT_Fn DAT_0fdf050;
struct S_00c422d0_Entry { unsigned int unk00; FUN_00c42b60_class* m_pObject; };
struct S_00c422d0_Foo {
    unsigned int m_uiItemCount;
    unsigned int m_unk04;
    S_00c422d0_Entry* m_pEntries;
    void __thiscall DestroyEntries();
};
class FUN_00c42b40_cls
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
    int m_20;
    void Step();
    void FUN_00c42b40();
};
void* __cdecl FUN_00aa13e0(unsigned int size);
extern int DAT_011f49e0;
struct SpawnedObject_b9874 {
    char m00[0x10];
    SpawnedObject_b9874();
    void Init(int* arg);
    static void* operator new(unsigned int size) { return FUN_00aa13e0(size); }
};
SpawnedObject_b9874* FUN_00c43190();
struct S_00c437c0_Obj {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4;
    static void* operator new(unsigned int);
    S_00c437c0_Obj();
};
struct S_00c437c0 : FUN_00c43850_Class {
    S_00c437c0_Obj* CreateObject(unsigned int stream);
};
void* __cdecl FUN_00aa13e0(unsigned int size);
struct SpawnedObject_b9504 : FUN_00c43660 {
    static void* operator new(unsigned int size) throw() { return FUN_00aa13e0(size); }
};
FUN_00c43660* __cdecl FUN_00c43a30();
class FUN_00c43be0_cls {
public:
    int unk00;
    int unk04;
    char* m_08;
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
    int m_b0;
    bool HasTrailingSuffix();
};
extern "C" int __cdecl FUN_00ec6130(const char* s);
extern "C" int __cdecl FUN_00eca6d3(const char* s);
// CopyStringBeforeColon
// Copies the leading part of a path (up to the first ':') into a caller buffer.
struct FUN_00c43e00_Obj {
    int unk00;
    int unk04;
    char* m_pStr;
};
extern "C" char* __cdecl FNV_StrChr(const char* s, int c);
extern "C" unsigned int __cdecl FNV_StrLen(const char* s);
extern "C" void __cdecl FNV_CopyPath(char* dest, unsigned int destSize, const char* src, unsigned int count);
void __cdecl CopyStringBeforeColon(FUN_00c43e00_Obj* pObj, char* pDest);
struct S_00c44d90_Item;
struct S_00c44d90_Cls {
    void (__cdecl *m_pfnWork)(int, int);
    int* m_pArg;
    unsigned int m_uiCount;
    volatile long m_lIndex;
};
void __cdecl RunWorkItems(S_00c44d90_Cls* pParam);
class NiStream;
void FUN_00a643b0(NiStream& kStream, bool& m_bHeaderParsed);
class NiNodeC45 {
public:
    virtual ~NiNodeC45();
    void LoadBinary(NiStream& kStream);

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
    short unkAC;
    bool m_bFlagAE;
    bool m_bFlagAF;
};
class BSNodeC45 : public NiNodeC45 {
public:
    void SetFlag(bool m_bHeaderParsed);
    void FUN_00c45220(NiStream& kStream);
};
struct S_00c45380_Base { bool FUN_00a5e600(S_00c45380_Base*); };
struct S_00c45380_Obj : S_00c45380_Base {
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
    unsigned char unkAC;
    unsigned char unkAD;
    unsigned char unkAE;
    unsigned char unkAF;
    char FUN_00c45380(S_00c45380_Obj* other);
};
extern "C" __declspec(dllimport) int __stdcall fnv_Import_TryEnterCriticalSection(void* cs);
extern "C" __declspec(dllimport) void __stdcall fnv_Import_LeaveCriticalSection(void* cs);
class GameLockA {
public:
    bool FUN_0078d200();
    void Lock(int a);
};
class GameLockB {
public:
    void FUN_00c46080();
};
extern GameLockA DAT_01202e40;
extern GameLockB DAT_01202e20;
extern unsigned int DAT_01202e44;
extern unsigned int DAT_011f4380;
void __cdecl TruncateStringToMaxLength();
struct FUN_00c459d0_frame {
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
void __cdecl FUN_00c459d0(unsigned char a1);
// AppendElement @ 0x00c45e00 (75 bytes) - __thiscall member, 1 stack parameter (ret 4).
// Add(element) of an NiTArray-style growable array:
//   +0x00 vtable, +0x04 m_pBase, +0x08 m_usMaxSize (u16),
//   +0x0A m_usSize (u16), +0x0C m_usESize (u16), +0x0E m_usGrowBy (u16).
// index = m_usSize; if (index >= m_usMaxSize) grow via FUN_00c45b20
// (m_usGrowBy + index); store element at index via SetSlot; return index.
struct FUN_00c45e00_class
{
    int unk00;                  // +0x00 vtable pointer (not accessed here)
    int unk04;                  // +0x04 element base pointer (not accessed here)
    unsigned short m_usMaxSize; // +0x08 allocated capacity
    unsigned short m_usSize;    // +0x0A live element count
    unsigned short m_usESize;   // +0x0C (not accessed here)
    unsigned short m_usGrowBy;  // +0x0E grow increment

    void __thiscall FUN_00c45b20(unsigned int uiNewSize);                        // ensure capacity
    void __thiscall SetSlot(unsigned int uiIndex, unsigned int uiElement);  // store element
    unsigned int __thiscall AppendElement(unsigned int uiElement);
};
extern int DAT_010c1c5c;
extern void* __cdecl FUN_00c46170(unsigned int count);
struct S_00c46530_Class {
    void* m_vtbl;
    void* m_result;
    unsigned short m_uiItemCount;
    unsigned short m_field_0a;
    unsigned short m_field_0c;
    unsigned short m_field_0e;

    S_00c46530_Class* __thiscall FUN_00c46530(unsigned short param1,
                                               unsigned short param2);
};
// @fnv 0x00c46530
S_00c46530_Class* __thiscall
S_00c46530_Class::FUN_00c46530(unsigned short param1, unsigned short param2)
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;

    this->m_vtbl = &DAT_010c1c5c;
    this->m_uiItemCount = param1;
    this->m_field_0e = param2;
    this->m_field_0a = 0;
    this->m_field_0c = 0;

    if (this->m_uiItemCount > 0) {
        this->m_result = FUN_00c46170(this->m_uiItemCount);
    } else {
        this->m_result = 0;
    }

    return this;
}
class FUN_00c46860_cls {
public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    float m_18;

    bool unkCheck(FUN_00c46860_cls* other);
    bool FUN_00c46860(FUN_00c46860_cls* other);
};
extern double DAT_01017a40;
struct FNVPad18
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
struct FNVPad1C
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
struct FNVVec3B
{
    float x;
    float y;
    float z;
    void Init(float s);
};
extern FNVVec3B DAT_01202e68;
FNVVec3B* __cdecl CombineVec3B(FNVVec3B* dst, FNVVec3B* a, FNVVec3B* b);
void __cdecl FUN_00c468c0(float a1, float a2);
class C46D60Stream {
public:
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
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void SaveLinkID(void* pvObject);
};
class C46D60Base {
public:
    void FUN_00a5e880(C46D60Stream& kStream);
};
class C46D60Node : public C46D60Base {
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
    int unkA4;
    int unkA8;
    void* m_pkChild;

    void FUN_00c46d60(C46D60Stream& kStream);
};
struct FUN_00c46da0_class : BaseForCall {
    bool __thiscall FUN_00c46da0(NiObject* other);
};
void* __cdecl FUN_00aa13e0(unsigned int size);
struct NewObject_b9649 {
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
    NewObject_b9649();
    static void* operator new(unsigned int size) { return FUN_00aa13e0(size); }
};
NewObject_b9649* CreateNewObject();
struct UpdateContext {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
 int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
 int unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;
 int unk80,unk84,unk88,unk8c;
 int state;
};
struct BoundBase {
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
 virtual bool Test(void*);
};
struct BoundTester : BoundBase {
 int unk04;
 int state;
};
struct BoundReference { int unk00,unk04,unk08; BoundTester* object; };
struct UpdateChild { void FUN_00a59e00(UpdateContext*); };
struct UpdateOwner {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
 int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
 int unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;
 int unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c;
 UpdateChild** children;
 unsigned short capacity,count,enabled,unkAA;
 BoundReference* reference;
 int replacement;
 void FUN_00c46f60(UpdateContext*);
};
// Stand-in model of CheckProcStateAndPlane (0x00c47150, 252 bytes) - an /Od member function.
//
// The original is:
//   bool CheckProcStateAndPlane(Vec3 pt, Proc* proc, Plane* plane)
//   {
//       if (proc->unk90 == 3 || proc->unk90 == 1) return true;
//       if (plane) {
//           obj.FUN_0045c620();                  // 0x0045c620
//           plane->FUN_00c33870(pt, &obj);      // 0x00c33870
//           Target* t = this->unkAC->unk0c;
//           if (t->v40(&obj)) {                 // vtable slot 0xA0
//               Target* u = this->unkAC->unk0c;
//               u->unk08 = 2;
//               return false;
//           }
//       }
//       return true;
//   }
//
// The local NAMES below are not arbitrary: under /Od the frame slot of every local is
// decided by the 16-bucket hash of its name, so the names are chosen to put each local on
// the frame slot the original uses (see attempts.txt).  The three dead int locals exist
// only to reserve the four unused 4-byte slots that the original's frame shows.
struct FNV_Vec3 {
    float x;
    float y;
    float z;
};
struct FNV_Proc {
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
};
struct FNV_Local {
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
    void FUN_0045c620();
};
struct FNV_Target {
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
    virtual bool v40(FNV_Local* pObj);
    int unk04;
    int unk08;
};
struct FNV_Holder {
    int unk00;
    int unk04;
    int unk08;
    FNV_Target* unk0c;
};
struct FNV_Plane {
    void FUN_00c33870(FNV_Vec3 pt, FNV_Local* pObj);
};
struct FNV_Owner {
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
    FNV_Holder* unkAC;
    bool CheckProcStateAndPlane(FNV_Vec3 pt, FNV_Proc* proc, FNV_Plane* plane);
};
struct TargetCls {
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
    virtual void v35(int a);
};
struct OwnerCls {
    int unk00;
    int unk01;
    int unk02;
    int unk03;
    int unk04;
    int unk05;
    int unk06;
    int unk07;
    int unk08;
    int unk09;
    int unk10;
    int unk11;
    int unk12;
    int unk13;
    int unk14;
    int unk15;
    int unk16;
    int unk17;
    int unk18;
    int unk19;
    int unk20;
    int unk21;
    int unk22;
    int unk23;
    int unk24;
    int unk25;
    int unk26;
    int unk27;
    int unk28;
    int unk29;
    int unk30;
    int unk31;
    int unk32;
    int unk33;
    int unk34;
    int unk35;
    int unk36;
    int unk37;
    int unk38;
    int unk39;
    int unk40;
    int unk41;
    int unk42;
    TargetCls* m_pFlagTarget;
    void CallVirtual35(int a);
};
struct Rec64 {
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
};
struct Vec12 { int x; int y; int z; };
struct Elem0C { int a; int b; int c; };
struct ArrRec64 {
    void* vtbl;
    Rec64* m_pData;
    int unk08;
    unsigned int m_uiSize;
    void SetSizeRec(unsigned int n, bool b);
};
struct ArrElem0C {
    void* vtbl;
    Elem0C* m_pData;
    int unk08;
    unsigned int m_uiSize;
    void Resize(unsigned int n, bool b);
};
struct Obj_c477f0 {
    unsigned char b00;
    ArrRec64 m_kArr04;
    ArrElem0C m_kArr14;
    int unk24;
    int unk28;
    int unk2C;
    Rec64 m_kRec30;
    Vec12 m_kVec94;
    void CopyTo(Obj_c477f0* dst);
};
class FUN_00c47980_sub
{
public:
    void SetFromFrustum(void* a, void* b);
};
class FUN_00c47980_arg
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
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
};
class FUN_00c47980_vec3
{
public:
    int x;
    int y;
    int z;
};
class FUN_00c47980_cls
{
public:
    void InitFromArg(FUN_00c47980_arg* a1);

    unsigned char m_00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int m_24;
    int m_28;
    int m_2c;
    FUN_00c47980_sub m_30;
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
    FUN_00c47980_vec3 m_94;
    unsigned char m_A0;
};
struct Sub_c47ae0
{
    int unk00;
    void FUN_00c4a1e0(int, bool);
};
struct FUN_00c47ae0_cls
{
    unsigned char m_00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    Sub_c47ae0 m_14;
    char* m_18;
    int unk1C;
    int m_20;
    int unk24;
    int m_28;
    void FUN_00c47ae0();
};
struct NavEntryItem {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int m_60;
};
class NavAllocator {
public:
    int* Alloc(unsigned int size, unsigned int tag);
};
class NavHolder {
public:
    NavAllocator* GetAllocator();
};
extern NavHolder g_navHolder;
extern unsigned int g_navTag;
class NavEntryOwner {
public:
    int unk00;
    int unk04;
    NavEntryItem* m_08;
    int unk0C;
    int m_10;
    int unk14, unk18, unk1C, unk20;
    int m_24;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    int unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84;
    int unk88, unk8C;
    int m_90;

    int* BuildEntryValueArray();
};
class NiPoint3 { public: float x,y,z; };
extern NiPoint3 DAT_011f426c;
struct SSNode {
 bool __thiscall FUN_00c344c0(void*, void*);
 bool __thiscall FUN_00c33cf0(void*, int, NiPoint3);
 bool __thiscall FUN_00c347d0(void*);
};
struct DecisionNode { int type; int trueIndex; int falseIndex; };
struct VolumeRecord {
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
};
struct DecisionTree {
 int unk00;
 int unk04;
 VolumeRecord* volumes;
 int unk0c;
 int unk10;
 int unk14;
 DecisionNode* nodes;
 int unk1c;
 int unk20;
 int unk24;
 int nodeCount;
 int rootIndex;
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
 bool skipBounds;
 bool __thiscall EvaluateQuery(SSNode* query);
};
extern int DAT_010c1e9c;
struct FUN_00c4a1b0_cls
{
    int m_vptr;

    FUN_00c4a1b0_cls* FUN_00c4a1b0();
};
class CachedRef_b5611 {
public:
    virtual void v00();
    virtual void* v01(unsigned int a);
    virtual void v02(void* a);
    virtual void* v03(void* b, unsigned int a);
    void CopyRange_b5611(void* c, void* b, unsigned int a);
    void UpdateCachedRef(unsigned int a1, unsigned int a2);

    void* m_pCachedReference;
    unsigned int unk08;
    unsigned int m_key;
};
struct FUN_00c4a6e0_cls
{
    int unk00;
    bool ProcessEntries(struct CallerObj_b3918* a1, struct EntrySet_b3918* a2);
};
struct CallerObj_b3918
{
    int ClassifySphereAgainstPlane(void* p);
};
struct EntrySet_b3918
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
    unsigned int m_60;
};
struct FUN_00c4a8e0
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual ~FUN_00c4a8e0();
};
struct FUN_00c4b150_cls {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C;
    int m_30;
    void FUN_00a5dd70(int a1, int a2);
    void CallIfNotFlagged(int a1, int a2);
};
struct S_c4b190_Base { void FUN_00a5ded0(int a, int b); };
struct S_c4b190 : S_c4b190_Base {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30;
    void CallBaseIfFlagClear(int a, int b);
};
struct S_00c4b1d0_Cls {
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
    unsigned int flags;
    void FUN_00a5e1f0(int a, int b);
    void FUN_00c4b1d0(int a, int b);
};
class FUN_00c4b470_owner {
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
    virtual int v35(void** a2);
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual int v39(void** a2);
    unsigned int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    unsigned int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    unsigned int unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60;
    unsigned int unk64, unk68, unk6C, unk70, unk74;
    FUN_00c4b470_owner* unk78;
    FUN_00c4b470_owner* FUN_00a5c570(void* p);
};
extern char DAT_011f36ac;
int __cdecl FUN_00c4b470(FUN_00c4b470_owner* a1, void** a2, unsigned char a3);
extern double DAT_01012060;
struct FUN_00c4cdc0_child
{
    void ReverseElements();
};
struct FUN_00c4cdc0_cls
{
    FUN_00c4cdc0_child* m_pChildObject;
    double FUN_00c4d9d0();
    void FUN_00c4db20();
    void FUN_00c4cdc0();
};
struct FUN_00c4cf00_Entry {
    int m_iA;
    int m_iB;
    float m_fC;
};
struct FUN_00c4cf00_Data {
    int unk00;
    FUN_00c4cf00_Entry* m_pItems;
};
struct FUN_00c4cf00_cls {
    FUN_00c4cf00_Data* m_pData;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int m_iArrayLength;

    void FUN_00c4cf00();
};
struct S_00c4dcf0 {
    int GetPointSide(float a, float b, float c, float d, float e, float f, float g, float h, float i);
};
struct S_00c4e0a0_Data {
    int unk00;
    unsigned short* m_pValues;
};
struct S_00c4e0a0_Class {
    int unk00;
    int unk04;
    S_00c4e0a0_Data* m_pData;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int m_iArrayLength;

    bool __thiscall FUN_00c4de80(int arg1, int arg2, int arg3,
                               int arg4, int arg5);
    bool __thiscall ContainsMatchingTriple(int arg1, int arg2);
};
struct S_00c4e900_Elem {
    int a;
    int b;
    int c;
};
struct S_00c4e900_Arr {
    int unk00;
    S_00c4e900_Elem* data;
    int count;
    void ReverseElements();
};
extern unsigned char DAT_012030a4;
struct S_00c4ed70_Object {
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void __stdcall vfn_0018(int);
};
struct S_00c4ed70_Class {
    S_00c4ed70_Object* m_pObject;
    bool __thiscall FUN_00c4ed70();
};
void S_00c4ed70_Object::vfn_0000() {}
void S_00c4ed70_Object::vfn_0004() {}
void S_00c4ed70_Object::vfn_0008() {}
void S_00c4ed70_Object::vfn_000c() {}
void S_00c4ed70_Object::vfn_0010() {}
void S_00c4ed70_Object::vfn_0014() {}
void __stdcall S_00c4ed70_Object::vfn_0018(int) {}
// Candidate v2 for FUN_00c4edb0 (zai_04).
// Same guard logic; callee hypothesis: virtual __stdcall member taking one int,
// called as m_p->vfn(1). MSVC passes this as the first __stdcall stack argument
// (push 1 then push m_p), vtable slot 6 (+0x18), no ecx requirement at call.
extern unsigned char DAT_012030a4;
struct FUN_00c4edb0_Virt {
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void __stdcall vfn_0018(int one);
};
struct FUN_00c4edb0_Class {
    FUN_00c4edb0_Virt* m_p;
    void FUN_00c4edb0();
};
struct S_00c4edf0_Obj {
    virtual void vfn00(); virtual void vfn04(); virtual void vfn08(); virtual void vfn0c();
    virtual void vfn10(); virtual void vfn14(); virtual void vfn18();
    virtual int __stdcall vfn1c(int, int, int);
};
struct S_00c4edf0_cls {
    S_00c4edf0_Obj* unk00;
    bool FUN_00c4edf0(int a1, bool a2);
};
struct DispatchObject {
    virtual void __stdcall reserved0();
    virtual void __stdcall reserved1();
    virtual void __stdcall reserved2();
    virtual void __stdcall reserved3();
    virtual void __stdcall FunctionAtSlot4();
    virtual void __stdcall FunctionAtSlot5();
    virtual void __stdcall FunctionAtSlot6();
    virtual int __stdcall Execute(int code, int mode, int flag);
};
struct DispatchOwner {
    DispatchObject* object;
    bool __thiscall FUN_00c4ee40(int code, unsigned char enabled);
};
struct FUN_00c509a0_Class {
    void* __thiscall GetEntryValue(int);
    void __thiscall FUN_00c51700(void*);
    void __thiscall FUN_00c509a0(int);
};
extern "C" char DAT_010c2580;
extern "C" void __cdecl FUN_005b5e40(void*, int);
// FUN_00c50dd0: clears (releases) the pointer held by the second argument's
// smart-pointer holder. The two dword locals reproduce the original /Od frame
// layout (named locals above the hidden 'this' spill at [ebp-0xc]).
struct FUN_00c50dd0_Holder {
    void* __thiscall FUN_0066b0d0(void* value);
};
struct FUN_00c50dd0_cls {
    int unk00;
    void FUN_00c50dd0(int* p1, FUN_00c50dd0_Holder* p2);
};
struct S_00c50ea0_T {
    void FUN_0066b0d0(int a);
};
struct S_00c50ea0 {
    void FUN_00c50ea0(int a1, int a2, S_00c50ea0_T* a3);
};
// Layout up to the item array (+0xa0) and the 16-bit item count (+0xa8).
struct FUN_00c50ec0_cls {
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
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
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
    int* m_pItems;
    unsigned int unkA4;
    unsigned short m_usElementCount;

    int FindItemIndex(int key);
};
struct NiRTTI { const char* m_pcName; const NiRTTI* m_pBaseRTTI; };
extern const NiRTTI DAT_012024e0;
extern const NiRTTI DAT_01203340;
void __cdecl FNV_Warning(const char* fmt, ...);
struct NiNodeStub;
struct NiAVObjectStub {
    virtual void v00();
    virtual void v04();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiNodeStub* IsSceneNode();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual int IsParticleSystem();
    int unk04;
    const char* m_pcName;
};
struct EmitterModifier : NiAVObjectStub {
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    EmitterModifier* m_pkNext;
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
    int m_iTarget;
};
struct MasterPSys : NiAVObjectStub {
    EmitterModifier* m_pkModifiers;
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
    bool m_bFlag;
};
struct NiNodeStub : NiAVObjectStub {
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
    NiAVObjectStub** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
};
bool __cdecl SetParticleSystemTarget(NiAVObjectStub* pkObject, int iTarget);
void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);
struct FUN_00c51590_cls {
    int unk00;

    void BaseCleanup();

    FUN_00c51590_cls* FUN_00c51590(unsigned int acFlags);
};
struct FUN_00c516a0_Virtual {
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
    virtual void v41(void*, int);
};
struct FUN_00c516a0_Class {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_00c516a0_Virtual* unk18;
    void* unk1C;

    void __thiscall FUN_00c516a0();
};
struct Node_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int v0c();
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
    Node_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};
struct ItemCtx_cls
{
    bool FUN_00a53c30(Node_cls* a1, unsigned int* out);
    void InsertOrUpdate(Node_cls* a1, unsigned int v);
};
struct FUN_00c53280_cls
{
    void UpdateMaxValue(Node_cls* a1, ItemCtx_cls* a2, unsigned int* out);
};
// Stand-in model of the destructor at 0x00c53fa0 (an /Od member function of a
// polymorphic class with a non-trivial base).
//
// The original is:
//   push ebp / mov ebp,esp / push -1 / push <eh handler> / mov eax,fs:[0] / push eax
//   sub esp,0x10 / <security cookie> / lea eax,[ebp-0xc] / mov fs:[0],eax
//   mov dword ptr [ebp-0x1c], ecx      ; the 'this' home
//   mov eax,dword ptr [ebp-0x1c]
//   mov dword ptr [eax], 0x10c2a94     ; the class' own vftable
//   mov dword ptr [ebp - 4], 0         ; EH state 0
//   mov ecx,dword ptr [ebp-0x1c] / add ecx,0xc / mov dword ptr [ebp-0x18],ecx
//   mov edx,dword ptr [ebp-0x18] / mov dword ptr [edx], 0x10c2b2c
//   mov eax,dword ptr [ebp-0x18] / mov ecx,dword ptr [eax+4]
//   mov dword ptr [ebp-0x14], ecx
//   mov edx,dword ptr [ebp-0x14] / mov dword ptr [ebp-0x10], edx
//   mov eax,dword ptr [ebp-0x10] / push eax
//   mov ecx, 0x11f6238 / call 0xaa4060   ; g_memoryManager.Deallocate(...)
//   mov dword ptr [ebp - 4], -1        ; EH state -1
//   mov ecx,dword ptr [ebp-0x1c] / call 0xa7b300   ; the base destructor
extern int FNV_vtbl_NiTArrayBase;
struct FNV_Item;
struct FNV_MemoryManager {
    void Deallocate(void* p);
};
extern FNV_MemoryManager FNV_g_memoryManager;
struct FNV_SubObject {
    int* m_vtbl;         // +0x00
    FNV_Item* m_pBase;   // +0x04
};
struct FNV_Base {
    int unk00;           // +0x04
    int unk04;           // +0x08
    virtual void vfn();
    ~FNV_Base();
};
struct FUN_00c53fa0_Class : public FNV_Base {
    FNV_SubObject m_sub;    // +0x0c
    ~FUN_00c53fa0_Class();
};
struct SpawnedSubObject
{
    int unk00;
    int unk04;
    int unk08;
    void Attach(int a1);
};
struct FUN_00c54e30_cls
{
    int unk00;
    int unk04;
    int unk08;
    SpawnedSubObject m_0c;
    SpawnedSubObject m_18;
    void BindOwner(int a1);
    void BindAndAttachSubObjects(int a1);
};
struct Point3_c54f00 {
    float x;
    float y;
    float z;
};
struct C00c541e0 {
    int unk00;
    int unk04;
    int unk08;
    bool FUN_00a7b3d0(int other);
};
struct C00c54f00 : C00c541e0 {
    Point3_c54f00 m_vec0C;
    Point3_c54f00 m_vec18;
    bool FUN_00c54f00(int other);
};
struct C55CD0Point3 {
    float x;
    float y;
    float z;
};
void C55CD0DrawBox(const C55CD0Point3& kMinBoundsCur, const C55CD0Point3& kMaxPoint, float fA, float fB, float fC, float fD,
                   unsigned int uiColor, unsigned int uiOutline);
void FUN_00c55cd0(const C55CD0Point3& kTargetCenter, float fSize, unsigned int uiColor);
struct S_00c5ae70_Result {
    int unk00;
    int unk04;
    int unk08;
};
struct S_00c5ae70_Inner2 {
    int unk00;
    int unk04;
    int unk08;

    S_00c5ae70_Result* __thiscall FUN_0043a010();
};
struct S_00c5ae70_Inner1 {
    int unk00;
    int unk04;
    S_00c5ae70_Inner2 m_inner2;

    void __thiscall FUN_00559a70(S_00c5ae70_Result* result);
};
struct S_00c5ae70_Class {
    int unk00;
    int unk04;
    S_00c5ae70_Inner1 m_inner1;

    void __thiscall FUN_00c5ae70(int param);
};
struct FUN_00c3a250_Obj {
    void __thiscall FUN_00c3a250(int* a1);
};
void __thiscall FUN_00c3a250_Obj::FUN_00c3a250(int* a1) {
}
struct FUN_00c5aec0_Class {
    int unk00;
    int unk04;
    void __thiscall FUN_00c5aec0(int a1);
};
struct FUN_00c5b190_Sub {
    void Process(int* p);
};
struct FUN_00c5b190_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    FUN_00c5b190_Sub m_14;
    void FUN_00c5b190(int a1);
};
// Constructor: member routine that installs the class vtable pointer into
// the object, clears the flag member at +0x5c and then hands the object to
// the shared cleanup routine (FUN_00c1c300).
extern int DAT_010c2d54;
struct FUN_00c5c440_cls
{
    void* m_pVTable;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    void FUN_00c1c300();
    void Constructor();
};
struct FUN_00c5c400 {
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
    unsigned int m_0x5c;
    unsigned int m_0x60;
    static void* __cdecl operator new(unsigned int size);
    FUN_00c5c400();
};
struct NiPSysEmitterCtlr_CloneShell {
    void FUN_00c5cb20(FUN_00c5c400* clone, void* process);
    FUN_00c5c400* FUN_00c5ca90(void* process);
};
struct FUN_00a53c30_cls {
    bool FUN_00a53c30(unsigned int key, void** out);
};
struct FUN_00c5cb50_pad {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
struct FUN_00c5cb50_cls {
    void FUN_00c1bdc0(int a1);
    void FUN_00c5cb50(int a1);
};
class BC5CBB0Object {
public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
};
class BC5CBB0Controller : public BC5CBB0Object {
public:
    BC5CBB0Controller();

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
};
BC5CBB0Object* __cdecl FUN_00c5cbb0();
struct EmitterObjectStub {
    void* m_ppVirtualMethodTable;
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
    EmitterObjectStub();
    static void* operator new(unsigned int size);
    static void operator delete(void* p);
};
struct EmitterOwnerStub {
    void Attach(EmitterObjectStub* pkObject, int iParam);
    EmitterObjectStub* CreateAndAttachEmitterObject(int iParam);
};
struct FUN_00c5d0a0_cls;
struct FUN_00c5d0a0_Vec4 { int x; int y; int z; int w; };
struct FUN_00c5d0a0_cls {
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
    FUN_00c5d0a0_Vec4 m_c4;
    void Helper(FUN_00c5d0a0_cls* other, int b);
    void CopyVec4AndHelper(FUN_00c5d0a0_cls* a1, int a2);
};
typedef void* HKEY_t;
extern "C" __declspec(dllimport) long __stdcall RegSetValueExA(HKEY_t hKey, const char* lpValueName, unsigned long Reserved,
                                         unsigned long dwType, const unsigned char* lpData, unsigned long cbData);
int __cdecl FUN_00c33090(int);
extern "C" int __cdecl strcpy_s(char* dst, unsigned int size, const char* src);
struct RegSetting {
    int unk00;
    int value;
    char* pName;
    unsigned int GetSize();
};
struct RegStore {
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void Open(bool bWrite);
    virtual void Close();
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
    HKEY_t m_hKey;

    bool WriteSetting(RegSetting* pSetting);
};
typedef struct HKEY__* HKEY;
typedef unsigned long DWORD;
typedef unsigned char BYTE;
extern "C" __declspec(dllimport) long __stdcall RegQueryValueExA(HKEY hKey, const char* lpValueName, DWORD* lpReserved, DWORD* lpType, BYTE* lpData, DWORD* lpcbData);
extern "C" int __cdecl strcpy_s(char* dst, unsigned int size, const char* src);
struct Setting {
    int unk00;
    int value;
    const char* name;
    unsigned int GetFormatSize();
    Setting& FUN_00c33170(const char* str);
};
int __cdecl GetStateResult(int* apParams);
struct RegSettingCollection {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void Open(int a);
    virtual void Close();
    int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c;
    int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c;
    int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c;
    int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c;
    int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc;
    int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc;
    int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc;
    int unk100; int unk104;
    HKEY hKey;
    bool ReadFromRegistry(Setting* pSetting);
};
// FUN_00c5de30: thiscall, zero two fields, reset sub-object at +0xac
struct ResetHelper {
    unsigned int unk00, unk04, unk08;
    void __thiscall Reset();
};
class FUN_00c5de30_cls {
public:
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8;
    ResetHelper m_ac;
    unsigned short m_b8;
    unsigned short unkBA;
    unsigned int unkBC;
    unsigned int m_c0;
    void __thiscall FUN_00c5de30();
};
struct FUN_00c5de70_sub {
    void FUN_005e03d0();
};
struct FUN_00c5de70_cls
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
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    FUN_00c5de70_sub m_cc;
    void WalkTree(FUN_00c5de70_cls* a, FUN_00c5de70_sub* b);
    void FUN_00c5de70();
};
extern int g_01203340;
struct FUN_00c5e010_Node {
    virtual void vf00();
    virtual void vf04();
    virtual int vf08();

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
    FUN_00c5e010_Node* next;
};
inline void FUN_00c5e010_Node::vf04() {}
inline int FUN_00c5e010_Node::vf08() { return 0; }
bool __cdecl FUN_00c5e010(int object) {
    FUN_00c5e010_Node* initial =
        *reinterpret_cast<FUN_00c5e010_Node**>(
            reinterpret_cast<char*>(object) + 0x0C);
    FUN_00c5e010_Node* current = initial;

    while (current != 0) {
        bool found;
        if (current == 0)
            found = false;
        else
            found = current->vf08() ==
                reinterpret_cast<int>(&g_01203340);

        if (found)
            return true;

        FUN_00c5e010_Node* next = current->next;
        current = next;
    }

    return false;
}
struct Walk_TreeNode_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual Walk_TreeNode_cls* v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual int v12();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    Walk_TreeNode_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};
struct Walk_Helper_cls
{
    void FUN_00c4c8d0(Walk_TreeNode_cls** p);
};
struct Walk_Walker_cls
{
    void WalkTree(Walk_TreeNode_cls* node, int a2);
};
struct S_00c5e3d0 {
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
    unsigned short unkb8;
    unsigned short unkba;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    float unkdc;
    void FUN_00c5e080();
    bool FUN_00c5eb90();
    void FUN_00a5ded0(float* p, int b);
    void FUN_00c5e3d0(float* p, int b);
};
struct S_00c5e3d0_pad { int a, b, c, d; float saved; };
struct FUN_00c5e450_cls {
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
    unsigned short m_b8;
    unsigned short unkBA;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    float m_dc;

    void FUN_00c5e080();
    unsigned char FUN_00c5eb90();
    void FUN_00a5e1f0(float* f, int b);
    void FUN_00c5e450(float* f, int b);
};
class C5E7A0Object;
class C5E7A0Stream {
public:
    virtual void vfunc00(); virtual void vfunc01(); virtual void vfunc02(); virtual void vfunc03();
    virtual void vfunc04(); virtual void vfunc05(); virtual void vfunc06(); virtual void vfunc07();
    virtual void vfunc08(); virtual void vfunc09(); virtual void vfunc0A(); virtual void vfunc0B();
    virtual void SaveLinkID(C5E7A0Object* pkObject);
};
void C5E7A0SaveShort(C5E7A0Stream& kStream, unsigned short* pusValue);
void C5E7A0SaveUInt(C5E7A0Stream& kStream, unsigned int* puiValue);
class C5E7A0Node {
public:
    void SaveBinary(C5E7A0Stream& kStream);
};
class C5E7A0Switch : public C5E7A0Node {
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
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    unsigned short unkB8;
    unsigned short m_usFlags;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    C5E7A0Object** m_ppkChildren;
    unsigned short unkD4;
    unsigned short m_usChildCount;

    void FUN_00c5e7a0(C5E7A0Stream& kStream);
};
struct SwitchChild {
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58();
    virtual bool IsEqual(SwitchChild* pOther);
};
struct ListNode {
    ListNode* m_pkNext;
    ListNode* m_pkPrev;
    int m_element;
};
struct ListOwner_c5e830 : BaseForCall {
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
    ListNode* m_pkHead;
    int unkB0;
    int unkB4;
    unsigned short m_usB8;
    unsigned short m_usBA;
    unsigned short m_usBC;
    unsigned short unkBE;
    int unkC0;
    int m_iC4;
    int unkC8;
    int unkCC;
    SwitchChild** m_ppChildren;
    unsigned short unkD4;
    unsigned short m_usChildCount;

    bool FUN_00c5e830(NiObject* pObject);
};
struct FUN_007530a0 {
    virtual ~FUN_007530a0() {}
};
struct FUN_00a7b300 {
    virtual ~FUN_00a7b300() {}
};
struct FUN_00c5ed60 : FUN_00a7b300 {
    int unk04;
    int unk08;
    FUN_007530a0 m_00c;
    virtual ~FUN_00c5ed60();
};
struct BSShaderAccumulator {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    static void* __cdecl operator new(unsigned int size);
    BSShaderAccumulator();
};
NiObject* __cdecl CreateShaderAccumulator(void);
struct FUN_00a7b4a0_cls {
    void __thiscall FUN_00a7b4a0(int a);
};
struct FUN_00a645b0_cls {
    void __thiscall FUN_00a645b0();
};
void __cdecl FUN_00a26df0(int a, int* out);
class FUN_00c5ef50_cls {
public:
    void __thiscall FUN_00c5ef50(int a1);
};
class FUN_00c5f100_cls {
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    void** m_ppItems;
    unsigned int m_uiCount;

    bool Equals(FUN_00c5f100_cls* other);
};
class NiMemObject {
public:
    static void* __cdecl operator new(unsigned int size);
};
struct NiTransformView {
    float rotation[9];
    float translation[3];
    float scale;
};
struct NiBoundView {
    float center[3];
    float radius;
};
struct CloneNode : NiMemObject {
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void vfn_0018();
    virtual void vfn_001c();
    virtual void vfn_0020();
    virtual void vfn_0024();
    virtual void vfn_0028();
    virtual void vfn_002c();
    virtual void vfn_0030();
    virtual void vfn_0034();
    virtual void vfn_0038();
    virtual void vfn_003c();
    virtual void vfn_0040();
    virtual void vfn_0044();
    virtual void vfn_0048();
    virtual void vfn_004c();
    virtual void vfn_0050();
    virtual void vfn_0054();
    virtual void vfn_0058();
    virtual void vfn_005c();
    virtual void vfn_0060();
    virtual void vfn_0064();
    virtual void vfn_0068();
    virtual void vfn_006c();
    virtual void vfn_0070();
    virtual void vfn_0074();
    virtual void vfn_0078();
    virtual void vfn_007c();
    virtual void vfn_0080();
    virtual void vfn_0084();
    virtual void vfn_0088();
    virtual void vfn_008c();
    virtual void vfn_0090();
    virtual void vfn_0094();
    virtual void vfn_0098();
    virtual void vfn_009c();
    virtual void vfn_00a0();
    virtual void vfn_00a4();
    virtual void vfn_00a8();
    virtual void vfn_00ac();
    virtual void vfn_00b0();
    virtual void vfn_00b4();
    virtual void vfn_00b8();
    virtual void vfn_00bc();
    CloneNode();
    unsigned int referenceCount;
    const char* name;
    void* extraData;
    unsigned short extraDataCount;
    unsigned short extraDataCapacity;
    void* controller;
    CloneNode* parent;
    void* collisionObject;
    unsigned int flags;
    NiTransformView localTransform;
    NiTransformView worldTransform;
    NiBoundView worldBound;
    CloneNode** children;
    unsigned int childCapacity;
    unsigned int childCount;
    void* runtimeState;
};
struct CloneOwnerObj : FUN_00c5fb60_Class {
    CloneNode* __thiscall FUN_00c5fac0(void* context);
};
struct FUN_00c5fb80_str
{
    char* m_p;
};
struct FUN_00c5fb80_rec
{
    int unk00;
    int unk04;
    FUN_00c5fb80_str m_08;
};
struct FUN_00c5fb80_pool
{
    char* __thiscall Alloc(unsigned int size);
};
extern "C" char DAT_011f6238;
unsigned int __cdecl FUN_00c5fb80_strlen(const char* s);
void __cdecl FUN_00c5fb80_copyPrefix(char* dst, unsigned int len, const char* src);
char* __cdecl FUN_00c5fb80_appendTail(char* dst, unsigned int len, const char* src);
char* __cdecl ConcatPrefixAndSuffix(FUN_00c5fb80_rec* rec, const char* suffix);
extern void* DAT_010c32c4;
struct FUN_00c5fd50_cls
{
    void* m_vtbl;
    void FUN_00c31750();
    void FUN_00c5fd50();
};
void* __cdecl FUN_00aa13e0(unsigned int);
struct PositionModifierInstance {
    FUN_00c5fd30 modifier;
    void* name;
    unsigned int order;
    void* target;
    bool active;
    float lastTime;
    void* next;
    static __forceinline void* operator new(unsigned int amount) {
        return FUN_00aa13e0(amount);
    }
};
FUN_00c5fd30* __cdecl CreatePositionModifierInstance();
struct MyStream;
void FUN_00a26df0(MyStream* stream, void* value);
struct ParticlePositionModifier {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    void FUN_00c318b0(MyStream* stream);
    void FUN_00c5ff60(MyStream* stream);
};
char* __cdecl FUN_00a7d370(const char* name, bool value);
struct ArrC43220 {
    int f00;
    int f04;
    unsigned short f08;
    unsigned short m_usSize;
    void FUN_00470000(unsigned int index, unsigned int& elem);
    void FUN_0096a610(unsigned int& elem);
};
struct KwHi {
    int n0;
    char c4;
    char c5;
    char c6;
    bool bDynamic;
    int n8;
    char c12;
    char c13;
    char c14;
    bool bEditorMarker;
    int n16;
    char c20;
    char c21;
    char c22;
    bool bAddon;
    int n24;
    char c28;
    char c29;
    char c30;
    bool bComplex;
    int n32;
    char c36;
    char c37;
    char c38;
    bool bRagDoll;
    int n40;
    short s44;
    bool bHavok;
    bool bAnimated;
};
struct KwLo {
    int n0;
    int n4;
    int n8;
    int n12;
    char c16;
    char c17;
    char c18;
    bool bIKTarget;
    int n20;
    int n24;
    int n28;
    int n32;
    char c36;
    char c37;
    char c38;
    bool bArticulated;
};
struct ThisC43220 {
    int f00;
    int f04;
    int f08;
    unsigned int m_flags;
    void FUN_00a99d70(ArrC43220* arr);
    void AppendKeywordFlags(ArrC43220* arr);
};
class BC45120CloningProcess;
class BC45120Object {
public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    BC45120Object();
    virtual ~BC45120Object();

    void CopyMemberData(BC45120Object* pkDest, BC45120CloningProcess& kCloning);
    BC45120Object* Clone(BC45120CloningProcess& kCloning);

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
};
struct Ref462f0 { void* vtable; volatile long references; };
struct Slot462f0 { Ref462f0* p; Slot462f0& AssignRefCounted(const Slot462f0&); };
extern Ref462f0* DAT_01202e14;
extern unsigned int DAT_01202e18;
void __cdecl FUN_00fdd690();
int __cdecl FUN_00ec658f(void (__cdecl*)());
struct Target462f0 {
 void* vtable;
 Slot462f0* data;
 unsigned short capacity;
 unsigned short size;
 unsigned short count;
 unsigned short grow;
 void __thiscall SetSlot(unsigned int index, const Slot462f0& value);
};
struct Entry { int type; int a; int b; };
struct Target {
 int unk00, unk04, unk08, unk0c, unk10, unk14;
 Entry* data;
 int unk1c, unk20, unk24;
 int count;
 void CompactEntries();
};
struct MeshStatsData {
    unsigned int unk00,unk04;
    unsigned short vertices,unk0a;
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
    unsigned short triangles;
};
struct MeshStatsEntry {
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
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
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
    MeshStatsData* data;
    unsigned int unkbc,unkc0,unkc4,unkc8,unkcc;
    unsigned int bytes;
};
struct Statistics { unsigned int meshes,triangles,vertices,materials,other,bytes; };
struct MeshCollection {
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
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
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
    unsigned int other;
    unsigned short materials,unkba;
    unsigned int unkbc,unkc0,unkc4,unkc8,unkcc;
    MeshStatsEntry** meshes;
    unsigned short capacity,used;
    void AccumulateStatistics(Statistics*);
};
// Refresh every key whose time lags the given time by more than the controller's threshold.
struct FDA0Key {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
class FDA0Data {
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
    unsigned short m_usKeyCount;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    FDA0Key* m_pKeyArray;

    float GetKeyTime(unsigned short usIndex);
    void SetKeyTime(unsigned short usIndex, float fTime);
};
class FDA0Controller {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float m_fThreshold;

    void UpdateKeyTimes(float fTime, FDA0Data* pkArg);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* dest, long exchange, long comparand);
struct Inner5b
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
    virtual void Fire();
};
struct Tag5b
{
    unsigned int bits;
    void Init(int flag);
};
struct Scratch5b
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
};
struct Pad16_5b { unsigned int unk00; unsigned int unk04; unsigned int unk08; unsigned int unk0C; };
struct Lock5b
{
    Inner5b* m00;
    unsigned int* m04;
    unsigned int* m08;
    unsigned int* m0c;
    unsigned int* m10;
    unsigned int m14;
    unsigned int m18;

    bool Check(unsigned int a, unsigned int b, unsigned int c);
    void Step(unsigned int p);
    bool TryAcquireAndFire(unsigned int a, unsigned int b, unsigned int c);
};
struct RefObj {
    int unk00;
    int unk04;
    volatile long m_iObjectReferenceCount;
};
struct RefPtr {
    RefObj* m_pObject;
};
struct NodeKey {
    int a;
    int b;
};
struct NodeFlags {
    unsigned int m_uiValue1;
};
struct Node {
    NodeKey m_key;
    RefPtr m_pReferencedObject;
    NodeFlags m_flags;
};
struct TaggedNodePtr {
    unsigned int m_uiBits;
};
struct Handler {
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
    virtual void Process(NodeKey key, NodeKey* pKey);
};
struct NodeQueue {
    Handler* m_pHandler;
    int* m_p04;
    int* m_p08;
    int* m_p0C;
    int unk10;
    TaggedNodePtr m_kSecond;
    TaggedNodePtr m_kFirst;

    bool __thiscall FUN_00c416a0(int arg, NodeKey key);
    bool FUN_00c42560(int arg, NodeKey* pKey, RefPtr* pOut);
};
struct FUN_00c42560_pad {
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
};
struct C45440_Obj : FUN_00c450d0 {
    int u64;
    int u68;
    int u6C;
    int u70;
    int u74;
    int u78;
    int u7C;
    int u80;
    int u84;
    int u88;
    int u8C;
    int u90;
    int u94;
    int u98;
    int u9C;
    int uA0;
    int uA4;
    int uA8;
    int uAC;
    static void* __cdecl operator new(unsigned int size);
};
C45440_Obj* __cdecl CreateC45440Obj(void);
struct Animation;
struct C5EDC0_AnimArray {
    unsigned int __thiscall Add(Animation*& apAnim);
};
struct C5EDC0_AnimExtra {
    int unk00;
    int unk04;
    int unk08;
    C5EDC0_AnimArray m_kAnimations;
    unsigned int __thiscall AddAnimation(Animation* apAnim);
};
struct BSFaceGenMorphData { static void* operator new(unsigned int); static void operator delete(void*); };
namespace c30 {
struct FUN_00c5fd30 : BSFaceGenMorphData { FUN_00c5fd30(); int m[7]; };
struct Owner30 {
    void FUN_00c5fec0(FUN_00c5fd30* mod, int arg);
    FUN_00c5fd30* CreateMorphData(int arg);
};
// @fnv 0x00c5fe30
FUN_00c5fd30* Owner30::CreateMorphData(int arg)
{
    FUN_00c5fd30* mod = new FUN_00c5fd30;
    FUN_00c5fec0(mod, arg);
    return mod;
}
}

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds);
struct SemaphoreC44 {
    volatile long m_lCount;
    void* m_pSemaphore;
};
struct WorkerC44 {
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
    SemaphoreC44 m_kCompletionSemaphore;
};
struct FUN_00c44d30_cls {
    WorkerC44** m_ppkWorkers;
    void WaitForWorkers();
};
struct FUN_00c467c0_cls : ParticlePositionModifier {
    void FUN_00c467c0(MyStream* stream);
};
struct FUN_00c47b50Vec3;
struct FUN_00c47b50Transform { float v0; float v1; float v2; float v3; float v4; float v5; };
struct FUN_00c47b50Record {

    int m00; int m04; int m08; int m0c; int m10; int m14; int m18; int m1c;

    int m20; int m24; int m28; int m2c; int m30; int m34; int m38; int m3c;

    int m40; int m44; int m48; int m4c; int m50; int m54; int m58; int m5c;

    int m60;

};
struct FUN_00c47b50Vec3 {

    float x; float y; float z;

    void FUN_00a699d0(FUN_00c47b50Vec3*, FUN_00c47b50Vec3*, FUN_00c47b50Transform*);

    float DotProduct(FUN_00c47b50Vec3*);

};
struct FUN_00c47b50Arg {

    void FUN_00c35c10(FUN_00c47b50Vec3*);

    void FUN_00c33870(FUN_00c47b50Vec3, FUN_00c47b50Record*);

};
struct FUN_00c47b50Array {

    int unk00;

    FUN_00c47b50Record* m_pData;

    int unk08;

    int m_iCapacity;

    void FUN_00c4a070(int, bool);

};
struct FUN_00c47b50Elem { int value; int index; int unused; };
struct FUN_00c47b50SmallArray {

    int unk00;

    FUN_00c47b50Elem* m_pData;

    int unk08;

    int m_iCapacity;

    void FUN_00c4a1e0(int, bool);

};
struct FUN_00c47b50Class {

    int unk00;

    FUN_00c47b50Array first;

    FUN_00c47b50SmallArray second;

    int index;

    int count;

    int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48;

    int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68;

    int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88;

    int unk8c; int unk90;

    FUN_00c47b50Vec3 position;

    void UpdateRecords(FUN_00c47b50Arg*, int);

};
extern "C" double __cdecl FUN_00ec6cde(double);
struct S_00c4dd60_Key {
    unsigned short unk00;
    unsigned short w16;
};
struct S_00c4dd60_Vec2 {
    float x;
    float y;
};
struct S_00c4dd60_Elem {
    S_00c4dd60_Vec2 v;
    int unk08;
};
struct S_00c4dd60_Table {
    int unk00;
    S_00c4dd60_Elem* m_pElems;
};
struct S_00c4dd60_Words {
    int unk00;
    unsigned short* m_pWords;
    unsigned int m_uiItemCount;

    bool __thiscall Contains(unsigned short* key);
};
struct S_00c4dd60_Owner {
    S_00c4dd60_Table* m_pTable;
    S_00c4dd60_Words* m_pWords;

    bool __thiscall IsKeyValid(int key, int a, int b);
    bool __thiscall Helper00c4de80(S_00c4dd60_Vec2 p, int a, int key, int b);
};
struct FUN_00c5ee90_cls : NiExtraData_Shell {
    int unk00;
    int unk04;
    int unk08;
    FUN_00c5f500_class unk0C;
    void FUN_00c5ee90(NiBinaryExtraData* dest, CloningProcess* cloning);
};
struct FUN_00a63430_Obj {
    unsigned int FUN_00a63430();
};
struct FUN_00c5efb0_Class : NiExtraData {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int* unk10;
    unsigned int unk14;
    void FUN_00c5efb0(NiStream& stream);
};
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
// FUN_00c43d00: builds the INISettings list snapshot ("INISettings" name + AddFirstEmpty,
// then count via FUN_0044f890 and "Total INISettings" message + AddFirstEmpty).
// SinkSave is a stand-in for the TU's local aggregate frame reservation.
struct SinkSave { unsigned int data[15]; };
struct FUN_00c43d00_Host {
    unsigned int FUN_0044f890(NiTPrimitiveArray_unsigned_int_& arr);
    unsigned int FUN_00c43d00(NiTPrimitiveArray_unsigned_int_& arr);
};
struct SetView {
    int unk00;
    union {
        int i;
        unsigned int u;
        float f;
        char* s;
    } data;
    char* name;
};
int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
extern "C" __declspec(dllimport) int __stdcall WritePrivateProfileStringA(const char*, const char*, const char*, const char*);
struct IniFile {
    virtual void z0();
    virtual void z1();
    virtual void z2();
    virtual void z3();
    virtual void z4();
    virtual void z5();
    virtual void Open(int);
    virtual void Close();
    char path[0x104];
    int fileHandle;
    bool FUN_00c43e90(SetView* setting);
};
struct S_00c454c0_Stream {
    void FUN_0096a610(char** p);
};
char* __cdecl FUN_00a7d410(const char* s, unsigned char v);
char* __cdecl FUN_00a7d370(const char* s, bool v);
extern const char str_010c1c40[];
extern const char str_010c1c3c[];
extern const char str_010c1c34[];
extern const char str_0109c7d8[];
struct S_00c454c0_Bool8 {
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    bool v;
};
struct S_00c454c0_Pad {
    int unkP00;
    int unkP04;
    int unkP08;
};
struct S_00c454c0_Low {
    int unkL00;
    int unkL04;
    int unkL08;
};
struct S_00c454c0_Byte8 {
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char v;
};
struct S_00c454c0 {
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
    unsigned char unkac;
    unsigned char unkad;
    unsigned char unkae;
    unsigned char unkaf;
    void FUN_00a5ea70(S_00c454c0_Stream* s);
    void FUN_00c454c0(S_00c454c0_Stream* s);
};
struct P465 {
    float x;
    float y;
    float z;
    void ApplyScaled(P465* result, float s);
    P465& FUN_0063c8a0(const P465& other);
};
struct R465 {
    P465 point;
    int unk0c;
    int unk10;
    float time;
    int unk18;
};
struct A465 {
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
    unsigned short unk50;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    R465* unk70;
};
struct H465 {
    unsigned short n;
    unsigned short scale;
};
struct C465 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float unk18;

    void FUN_00c465e0(float value, A465* arg);
};
struct StrArr;
struct E70Target
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
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24(StrArr* stream);
};
struct E70LinkRef
{
    int unk00;
    int unk04;
    int unk08;
    E70Target* object;
};
// link is the only live field. The two words above it are the frame holes at -0x14 and -0x10.
struct E70FirstSlot
{
    E70LinkRef* link;
    int unk04;
    int unk08;
};
extern char str_01090d1c[];
extern char str_010c1e3c[];
extern char str_010c1e34[];
extern char str_010c1e28[];
char* __cdecl FUN_00a7d330(char const* name);
unsigned int __cdecl FUN_00a7d5e0(const char* label, const char* value);
struct E70Owner : UpdateOwner
{
    void FUN_00a5ea70(StrArr* stream);
    void FUN_00c46e70(StrArr* stream);
};
struct Bound47250 {
    struct XYZ { unsigned int m_00, m_04, m_08; } m_00;
    float m_0c;
    void FUN_00a7f3f0(const Bound47250*);
};
extern Bound47250 DAT_011f4288;
struct Provider47250 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c();
    virtual void va0(); virtual void va4(Bound47250*);
};
struct Ref47250 { unsigned int m_00,m_04,m_08; Provider47250* m_0c; };
struct Node47250 {
    unsigned int m_00[8]; Bound47250* m_20;
    unsigned int m_24[3]; unsigned int m_30;
    unsigned int m_34[27]; Node47250** m_a0;
    unsigned short m_a4,m_a6,m_a8,m_aa; Ref47250* m_ac;
    void FUN_005467e0();
    void FUN_00c47250();
};
struct Pad47250 { unsigned int m_00,m_04,m_08; };
struct TargetClass {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
    virtual void v0c(); virtual void v0d(); virtual void v0e(); virtual void v0f();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1a(); virtual void v1b();
    virtual void v1c(); virtual void v1d(); virtual void v1e(); virtual void v1f();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26();
    virtual bool vfn_9c(void*);
    virtual bool vfn_a0(void*);
};
struct QueryParam {
    int unk00;
    int unk04;
    int unk08;
    TargetClass* target;
};
struct DecisionTreeExt : DecisionTree {
    bool FUN_00c493a0(QueryParam* query);
};
struct GraphRecord { int kind, yes, no; };
struct RecordArray {
    int unk00;
    GraphRecord* data;
    int unk08;
    int capacity;
    void FUN_00c4a1e0(int, bool);
};
struct GraphHeap {
    void* Allocate(unsigned int, unsigned int);
    void Deallocate(void*);
};
struct GraphMemory { GraphHeap* FUN_00aa42e0(); };
extern GraphMemory _g_memoryManager;
extern unsigned int DAT_010a2720;
extern char DAT_010c1e44[];
void __cdecl FUN_005b5e40(const char*);
void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
struct ControlGraph {
    bool ready;
    int unk04, unk08, unk0c, unk10;
    RecordArray records;
    int unk24;
    int count;
    int first;
    void FUN_00c49850();
};
extern int DAT_010c1e88;
struct S00c49fe0_Vt
{
    virtual void v0();
    virtual void* v1(unsigned int n);
};
struct FUN_00c49fe0_Cls
{
    void* vtbl;
    void* data;
    int unk08;
    int unk0C;

    void FUN_00c4a360(void* data, int flag);
    FUN_00c49fe0_Cls();
};
struct c4a790_Plane {
    unsigned int normalX;
    unsigned int normalY;
    unsigned int normalZ;
    unsigned int constant;
};
struct c4a790_Obj {
    c4a790_Plane planes[6];
    unsigned int mask;
};
struct c4a790_Side {
    int unusedSide;
    int value;
};
struct c4a790_Owner {
    bool FUN_00c4a790(CallerObj_b3918* target, c4a790_Obj* object);
};
extern int DAT_010c1e88;
struct VertexDE80 {
    float m_00, m_04, m_08;
};
struct DataDE80 {
    int m_00;
    VertexDE80* m_04;
};
struct ObjectDE80 {
    DataDE80* m_00;
    bool FUN_00c4de80(float x, float y, int A, int B, int C);
};
class FUN_00c511f0_cls {
public:
    virtual void v0();
    virtual void v1();
    virtual void* v2();
};
extern char g_sentinel_0120436c;
bool FUN_00c50f90(FUN_00c511f0_cls* a, FUN_00c511f0_cls* b);
bool __cdecl FUN_00c511f0(FUN_00c511f0_cls* obj);
// 0x00c52020  1072 bytes  /MT /Od /Oy- /GS /EHsc /Gy   -- byte-identical reconstruction
// thiscall (ret 0x10): (float fov, unsigned char flag, C52020Obj* obj, unsigned char arg4)
// called from 0xc51d67 as SetCameraFOV(*pSetting, 1, 0, 0).
//
// Frame 0xcc + push esi.  Named band -0x04..-0x88 (bucket-sorted: descending name-hash
// bucket, ties by reverse declaration order), expression temps -0x8c..-0xcc in code order.
// Slot roles are annotated on the declarations below; aFlag is the 0x18-byte hole at
// -0x6c that nothing ever reads, and the two setting divides use a two-member record
// read because only a "computed" right operand makes MSVC9 /Od emit
// `mov edx,[p] / fld [edx] / fdivr [ebp+8]` instead of the mirrored
// `fld [ebp+8] / mov edx,[p] / fdiv [edx]`.
extern "C" char DAT_01203144[];
extern "C" char DAT_01203150[];
extern "C" float DAT_01202800;
extern "C" double DAT_01023128;
extern "C" double DAT_01011588;
struct C52020Dev;
extern "C" C52020Dev* DAT_011f4748;
double tan(double);
struct NiFrustum {
    NiFrustum(bool);
    float m_fLeftBound;
    float m_fRightBound;
    float m_fTopBound;
    float m_fBottomBound;
    float m_fNearPlane;
    float m_fFarPlane;
    bool m_bOrthographic;
};
struct NiUpdateData {
    float m_fTime;
    bool m_b0;
    bool m_b1;
    bool m_b2;
    bool m_b3;
    bool m_b4;
};
struct C52020Res {
    char pad0[8];
    unsigned int m_08;
    unsigned int m_0c;
};
struct C52020Obj;
struct C52020Dev {
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
    virtual C52020Res* vfn_b0(int);
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual C52020Dev* vfn_c8();
    virtual C52020Dev* vfn_cc();
    unsigned int FUN_004dee70();
    unsigned int FUN_004dee10();
};
struct C52020Setting { float m_fReserved; float m_fValue; };
struct C52020Filler {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};
struct C52020Obj {
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
    virtual float vfn_100();
    char pad0[0xa8];
    C52020Obj* m_ac;
    char pad1[8];
    unsigned char m_b8;
    char pad2[3];
    float m_bc;
    char pad3[0x3c];
    float m_fc;
    float m_100;
    float m_104;
    float m_108;
    float m_10c;
    float m_110;
    void FUN_00a6faf0(NiFrustum* apFrustum);
    void Update(const NiUpdateData& kData);
    void SetCameraFOV(float m_fFirstFloat, unsigned char ucFlag, C52020Obj* pObj, unsigned char ucArg4);
};
extern "C" void* g_012031e8;
extern unsigned int DAT_010c1040;
extern unsigned int DAT_010c2bf8;
struct W5Sub {
    int pad;
    unsigned int __thiscall FUN_00a59af0(void* desc);
};
struct W5Big {
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    void* p;
};
struct W5Self {
    int f00;
    int f04;
    int f08;
    W5Sub subC;
    int f10;
    int f14;
    W5Sub sub18;
    void __thiscall FUN_00a7b580(ArrC43220* a1);
    void __thiscall FUN_00c550f0(ArrC43220* a1);
};
struct S_00c5b140_Node {
    int unk00;
    int unk04;
    void* unk08;
};
struct S_00c5b140_Allocator {
    S_00c5b140_Node* __thiscall FUN_0043a010();
};
struct S_00c5b140_List {
    int unk00;
    int unk04;
    S_00c5b140_Allocator unk08;
    void __thiscall FUN_00559a70(S_00c5b140_Node* node);
};
struct S_00c5b140 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    S_00c5b140_List unk14;
    void __thiscall FUN_00c5b140(void* value);
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern void* DAT_01203328;
typedef NiTListItem<NiPointer<NiProperty> > SpawnNode;
typedef NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiProperty> > SpawnList;
struct SpawnedObject {
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
    SpawnList m_50;
    SpawnList m_5c;
    void FUN_00c5b5f0(void* value);
    void FUN_00c5b740(void* value);
    void FUN_00c5b8d0();
};
struct LoopPadA { unsigned int a; unsigned int b; unsigned int c; unsigned int d; };
struct LoopPadB { unsigned int a; unsigned int b; unsigned int c; unsigned int d; unsigned int e; unsigned int f; unsigned int g; };
unsigned int __cdecl FUN_00a7d5a0(const char* name, int value);
unsigned int __cdecl FUN_00a7d490(const char* name, unsigned int value);
struct S00c5cd80_Scratch {
    int f00;
    int f04;
    int f08;
    int f0C;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
    int f2C;
};
struct S00c5cd80_Owner {
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
    int m_5c;
    unsigned short m_60;
    void FUN_00c1ce70(NiTPrimitiveArray_unsigned_int_* a);
    void FUN_00c5cd80(NiTPrimitiveArray_unsigned_int_* arg);
};
struct Node_00c5e080 {
    virtual void vfunc00();
    virtual void DeleteThis();
    volatile long m_uiRefCount; // offset 4
    char pad08[0x28];           // 0x08..0x2f
    unsigned int m_uiValue1;     // 0x30
};
struct MapHelper_00c5e080 {
    void FUN_00c5bfb0(Node_00c5e080** ppObj, int* ppCur);
};
struct Limits_00c5e080 {
    unsigned short maxCount; // offset 0 -> [ebp - 0x2c]
    unsigned short curCount; // offset 2 -> [ebp - 0x2a]
};

struct BBXHeap
{
    void *__thiscall FUN_00aa3e40(unsigned int size);
    void __thiscall FUN_00aa4060(void *p);
};
extern "C" int DAT_0109b220;
int __cdecl FUN_00a5b690(const char *s);

struct BBXRef
{
    int m_uiFilterValue;

    static void *operator new(unsigned int size) { return ((BBXHeap *)&DAT_011f6238)->FUN_00aa3e40(size); }
    static void operator delete(void *p) { ((BBXHeap *)&DAT_011f6238)->FUN_00aa4060(p); }

    BBXRef(const char *s)
    {
        if (!s)
            m_uiFilterValue = DAT_0109b220;
        else
            m_uiFilterValue = FUN_00a5b690(s);
    }
};

extern "C" BBXRef *DAT_012031e4;

// @fnv 0x00c55200
void __cdecl FUN_00c55200()
{
    DAT_012031e4 = new BBXRef("BBX");
}
