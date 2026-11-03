// src/staging/blk_006e0000_od_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_006e0000_od.cpp that match byte for byte only
// with VC9 SP1 and /MT /Od /Oy- /GS /EHsc /Gy (unit lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


// src/staging/blk_006e0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
struct Interface
{
    static void __cdecl PrintDebugMessage(void);
};
int __cdecl FUN_0043b460(long volatile* a1, long a2, long a3);
struct FUN_006ec0d0_Class
{
    bool __thiscall FUN_006ec0d0(int a1);
};
struct FUN_006e1020_shell
{
    FUN_006e1020_shell* __thiscall FUN_006e1020();
    FUN_006e1020_shell* __thiscall FUN_006e0e80();
};
FUN_006e1020_shell* __thiscall FUN_006e1020_shell::FUN_006e1020()
{
    return this;
}
extern int DAT_0106ceb8;
struct FUN_006e0ea0_Class
{
    int* __thiscall FUN_006e0ea0(int a1);
    void __thiscall ConstructHashTable(int a1);
};
extern int DAT_0106cef8;
struct GlobalObject_00869f00
{
    void __thiscall Clear(bool);
    void __thiscall FUN_006e1050();
};
extern int DAT_0106cf0c;
struct S006d0420
{
    void __thiscall FUN_0069b940(int a1, int a2);
};
struct FUN_006e1070_Class
{
    FUN_006e1070_Class* __thiscall FUN_006e1070();
};
extern int DAT_0106cf68;
struct FUN_006e2080_Class
{
    void __thiscall FUN_006e20e0(int a1);
    int m;
    int __thiscall FUN_006e2080(int a1);
};
struct Copy9
{
    Copy9* __thiscall FUN_00502630(const Copy9* a1);
};
struct FUN_006e29b0_Class
{
    void __thiscall FUN_006e29b0(const Copy9* a1);
};
struct PathingAvoidanceNode;
struct FUN_006e3a80
{
    void __thiscall _InitialSetup(unsigned int, unsigned int);
    const char* m_p;
    FUN_006e3a80();
};
struct FUN_006e5ee0_Class
{
    void __thiscall FUN_006e5ee0(float value);
};
void __cdecl FUN_005e0b60(void*);
struct FUN_006e6bd0_Class
{
    void __thiscall FUN_006e6bd0();
};
struct Dummy_006e8f80
{
    void* FUN_006e8f80(unsigned int);
};
struct FUN_006e8fc0_Class
{
    void* __thiscall FUN_006e8fc0();
};
void __cdecl InitSizeState(int a1, int a2);
extern void* DAT_0106d4d4;
struct FUN_006e9050_Class
{
    void __thiscall InitSizeState(int a1, int a2);
    void* __thiscall FUN_006e9050();
};
extern int DAT_0106d6b8;
struct FUN_006ec1e0_Class
{
    void __thiscall FUN_006ec1e0();
};
extern int DAT_0106d6d0;
struct FUN_006ec3f0_Class
{
    void __thiscall FUN_006ec3f0();
    void __thiscall FUN_006ec410();
};
extern const void* DAT_0106d6f0;
struct FUN_006ec410_Class
{
    virtual ~FUN_006ec410_Class();
    void __thiscall FUN_006ec430();
};
extern int DAT_0106d710;
struct FUN_006ec430_Class
{
    void __thiscall FUN_006ec430();
};
extern "C" void __cdecl FUN_006ecc00();
extern int DAT_0106d698;
struct FUN_006ecb40_Class
{
    void __thiscall FUN_006ecc00();
    FUN_006ecb40_Class* __thiscall FUN_006ecb40();
};
extern int DAT_0106d7a0;
struct FUN_006ecf20_Class
{
    void __thiscall FUN_006ecf20();
};
struct FUN_006ed0e0_Class
{
    int __thiscall FUN_006ed0e0();
};
extern NiPoint3 _NiPoint3_ZERO;
struct PathingLocation;
struct PathingSolution
{
    void ReserveIndex(const PathingLocation&, const NiPoint3&);
};
struct FUN_006ed7a0_Class
{
    void __thiscall FUN_006ed7a0(const PathingLocation&);
};
void* __cdecl Reallocate(void* ptr, size_t size);
struct FUN_006f2e20_Class
{
    void* __thiscall FUN_006f2e20(void* ptr, int count);
};
struct AX
{
    void FUN_006b3eb0(unsigned int a, unsigned int b);
};
struct FUN_006f30e0_Class
{
    AX* __thiscall FUN_006f30e0();
};
extern int DAT_0106d88c;
struct FUN_006f3320_Class
{
    void __thiscall InitBuffer(int a1, int a2);
    FUN_006f3320_Class* __thiscall FUN_006f31c0();
};
struct ScrapHeapBuffer
{
    int m;
};
struct FUN_00aa5410_Helper
{
    ScrapHeapBuffer* __thiscall InitWithAlignedSize(unsigned int);
};
struct FUN_006f4320_Class : public ScrapHeapBuffer
{
    ScrapHeapBuffer* __thiscall FUN_006f4320();
};
extern int DAT_0106d974;
struct Dummy_0061bf20
{
    void __thiscall FUN_006b3f40(int a1, int a2);
    Dummy_0061bf20* __thiscall FUN_006f4b10();
};
extern void* DAT_0106d988;
struct FUN_006f4b60_Class
{
    void __thiscall ResetAndWrite(void* a1, void* a2);
    void* __thiscall FUN_006f4b60();
};
void* __cdecl operator new(unsigned int);
struct FUN_006f4bb0_Class
{
    void* __thiscall FUN_006f4bb0(int a1);
};
extern int DAT_0106df38;
struct FUN_006f98c0_Class
{
    void __thiscall FUN_006f98c0(int a1);
};
struct FUN_006f9680_Class
{
    int m_iWordAt00;
    int __thiscall FUN_006f9680(int a1);
};
extern int DAT_0106df58;
struct FUN_006f9a00_Class
{
    void __thiscall FUN_006f9a00(int a2);
};
struct FUN_006f96b0_Class
{
    int* __thiscall FUN_006f96b0(int a1);
};
extern int DAT_0106df78;
struct FUN_006f9740_Class
{
    void __thiscall ResizeAndFill(int a1, int a2);
    FUN_006f9740_Class* __thiscall FUN_006f9740();
};
void* __cdecl Reallocate(void* p, unsigned int size);
struct FUN_006f9850_Class
{
    void* __thiscall FUN_006f9850(void* p, unsigned int count);
};
extern int DAT_0106dfe0;
struct FUN_006fa180_Class
{
    void __thiscall FUN_006fa180(int, int);
};
struct FUN_006fa100_Class
{
    FUN_006fa100_Class* __thiscall FUN_006fa100();
};
extern int DAT_0106dfe0;
struct FUN_006f9c70_shell
{
    void FUN_006f9c70(bool a1);
};
struct FUN_006fa160_Class
{
    void __thiscall FUN_006fa160();
};
struct NiBinaryStream
{
    unsigned int Read(void*, unsigned int);
};
struct FUN_006fc920_Class
{
    int __thiscall ReadFromStream(NiBinaryStream* a1);
};
void __cdecl FUN_006fda10();
struct FUN_006fca70_Class
{
    void __thiscall FUN_006fca70();
    void* m_p;
};
struct FUN_006ff880_Class
{
    void __thiscall FUN_006ff880(unsigned char a1);
};
extern int DAT_0106e7b4;
struct FUN_006ff970_Class
{
    int* m_p;
    char m_kPointB;
    int m_i;
    FUN_006ff970_Class();
};
extern int DAT_0106e7a4;
struct FUN_006ffc00_Class
{
    void __thiscall UnregisterSteamCallback();
    void __thiscall FUN_006ff9a0();
};
extern int DAT_0106e7c4;
struct FUN_006ffa40_Class
{
    int m_vtbl;
    bool m_flag;
    void __thiscall UnregisterSteamCallback();
    void __thiscall FUN_006ffa40();
};
extern "C" void* DAT_0106e7d4;
struct FUN_006ffac0_Class
{
    void __thiscall UnregisterSteamCallback();
    void __thiscall FUN_006ffac0();
};
struct FUN_006ffb10_Class
{
    int __thiscall FUN_006ffb10();
};
extern void* __cdecl NiFreeAlias(void*);
extern void* DAT_0106ced8;
struct FUN_006e0ff0_Class : NiTPointerMap<int, int>
{
    void __thiscall FUN_006e0ff0();
};
extern int DAT_0106d63c;
struct FUN_006ecc40_Class
{
    int m0;
    int m4;
    int m8;
    FUN_006ecc40_Class();
};
extern int DAT_0106d7a0;
struct FUN_006ed010_Class
{
    int* p;
    int a;
    int b;
    int* __thiscall FUN_006ed010();
};
struct FUN_006e0f90_Class
{
    void __thiscall FUN_006e0f90();
    void* __thiscall FUN_006e0ef0(unsigned int flags);
};
void __cdecl Deallocate(void*);
void __cdecl _Deallocate(void*);
struct FUN_006e11f0_Class
{
    void* __thiscall FUN_006e11f0(unsigned int);
};
void __cdecl _Deallocate(void*);
struct S006e1220 : GlobalObject_00869f00
{
    void* __thiscall FUN_006e1220(unsigned int);
};
struct FUN_006e10a0_shell
{
    void __thiscall FUN_006e10a0();
};
void __cdecl Deallocate(void*);
struct FUN_006e1250_Class
{
    void* __thiscall FUN_006e1250(unsigned int a1);
};
void* __cdecl operator new(unsigned int, void*);
struct FUN_006e1280_Class
{
    void __thiscall FUN_006e1280(char* a1, unsigned int a2);
};
void* __cdecl _NiMalloc(unsigned int);
void* memset(void* p, int v, unsigned int n);
extern int DAT_0106cf88;
struct FUN_006e20e0_Class
{
    int* m_vtbl;
    int m_iElementCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_006e20e0_Class(int a1);
};
void __cdecl Deallocate(void* p);
struct FUN_006e21e0_Class
{
    void __thiscall ClearAndFreeStorage();
    FUN_006e21e0_Class* __thiscall FUN_006e21e0(unsigned int flags);
};
struct PathingRequestClosePoint
{
    PathingRequestClosePoint();
    char _pad[0xB8];
};
extern int DAT_0106d414;
struct FUN_006e5fa0 : public PathingRequestClosePoint
{
    int m_B8;
    FUN_006e5fa0();
};
struct _Mem_2064
{
    ~_Mem_2064();
};
struct FUN_006e62b0_Class
{
    virtual ~FUN_006e62b0_Class();
    _Mem_2064 m1;
    char pad[0x27];
    _Mem_2064 m2;
};
struct S006e7620_R2
{
    void __thiscall FUN_005e0ad0();
};
struct S006e7620_R1
{
    S006e7620_R2* __thiscall _ref_006815c0(int a1, const char* a2);
};
S006e7620_R1* __cdecl _FUN_00c85750();
void __cdecl FUN_006e7620(int aiSize, const char* what);
struct FUN_006e9000_Class
{
    float m_iWordAt00;
    float m_cByteAtOffset1;
    float m_cByteAtOffset2;
    float m_cByteAtOffset3;
    float m_iWordAt04;
    float __thiscall ComputeWeightedSum(float* a1, float* a2, float* a3, float* a4);
};
struct FUN_006e9260
{
    ~FUN_006e9260();
};
void __cdecl Deallocate(void*);
struct FUN_006e9500_Class : public FUN_006e9260
{
    void* __thiscall FUN_006e9500(unsigned int flags);
};
struct HostA
{
    bool __thiscall DispatchToInner(int, bool);
};
struct FUN_006ebbd0_Cls
{
    HostA* h;
    bool __thiscall ForwardToHost(int, bool);
};
struct FUN_006ebbf0_Class
{
    void __thiscall CallVirtualObjectMethod(void* a1, void* a2, void* a3, void* a4, bool a5);
    void __thiscall FUN_006ebbf0(void* a1, void* a2, void* a3, void* a4, bool a5);
};
struct FUN_006eb2b0_Callee
{
    void __thiscall ProcessKeyedItem(int a1, int a2, int a3, int a4);
};
struct Host_006ebc20
{
    FUN_006eb2b0_Callee* m;
    void __thiscall FUN_006ebc20(int a1, int a2, int a3, int a4);
};
struct SeqObj
{
    void FUN_00401970();
};
struct G00559a40
{
    void FUN_0040f6e0();
};
struct FUN_006ebfb0_Class
{
    int* m_p;
    int* __thiscall AssignPointer(int** other);
};
extern int DAT_0106d678;
struct FUN_006ec090_Class
{
    int f0;
    int f4;
    int f8;
    int fC;
    void* f10;
    FUN_006ec090_Class* __thiscall FUN_006ec090(int a1);
};
void __cdecl Deallocate(void*);
struct FUN_006ec200_Class
{
    void __thiscall FUN_006ec1c0();
    void* __thiscall FUN_006ec200(unsigned int flags);
};
struct Call_6ecb70
{
    void __thiscall FUN_006ecb70();
};
struct Holder_6ec340
{
    Holder_6ec340* __thiscall FUN_006ec340();
};
struct FUN_006ec390_Class
{
    bool __thiscall FUN_006ec390(int a1);
};
void __cdecl operator delete(void*);
struct FUN_006ec410_Helper
{
    void __thiscall FUN_006ec430();
};
struct FUN_006ec450_Class
{
    void* __thiscall FUN_006ec450(unsigned int a1);
};
void __cdecl Deallocate(void*);
struct FUN_006ec480_Class : public FUN_006ec410_Class
{
    void* __thiscall FUN_006ec480(unsigned int flags);
};
struct FUN_0044df00Class
{
    int* FUN_0044df00();
};
struct FUN_0044df20
{
    bool Call();
};
struct FUN_00529000_Class
{
    void FUN_00529000();
};
struct FUN_006ec9b0_Class
{
    bool ProcessNodeChain(int a1, int a2);
    bool FUN_006ec9b0(int a1, int a2, int* a3);
};
void __cdecl Deallocate(void*);
struct FUN_006ec130_Class
{
    void __thiscall FUN_006ec130();
    void* __thiscall FUN_006eca80(unsigned int flags);
};
void __cdecl _Deallocate(void*);
struct FUN_006ecab0_Class
{
    void* __thiscall FUN_006ecab0(unsigned int);
};
void __cdecl Deallocate(void* p);
struct FUN_006ec870_Class
{
    void __thiscall FUN_006ec870();
    void* __thiscall FUN_006ecae0(unsigned int flags);
};
class QueuedMessage;
template <class T> struct BSTFreeListElement
{
    void __thiscall FUN_006ecce0();
};
template <class T> struct BSTFreeList
{
    void __thiscall PushFront(BSTFreeListElement<T>*&);
    void __thiscall FUN_006ecb10(BSTFreeListElement<T>*&);
};
struct CF_0081c630
{
    void Init();
    CF_0081c630();
};
struct FUN_006ecbd0_Class
{
    int m0;
    int m4;
    CF_0081c630 m8;
    FUN_006ecbd0_Class* __thiscall InitFromValues(int a, int* b);
};
struct FUN_006ecd60_stub
{
    bool __thiscall FUN_006ecd60(void**);
    bool __thiscall FUN_006ecd00(void** a1, int a2);
};
struct FUN_006ece00_Obj
{
    void __thiscall AssignFrom(int);
};
void __cdecl _Deallocate(void*);
struct FUN_006ecf40_Class
{
    void* __thiscall FUN_006ecf40(unsigned int);
};
struct NiBound
{
    NiBound();
};
struct ref_006815c0
{
    ref_006815c0();
};
struct FUN_006ee100_Class
{
    int a;
    int b;
    ref_006815c0 m_08;
    int c;
    int d;
    int e;
    int f;
    ref_006815c0 m_14;
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
    ref_006815c0 m_20;
    int q;
    int r;
    int s;
    int t;
    int u;
    int v;
    ref_006815c0 m_2c;
    int w;
    int x;
    int y;
    int z;
    int aa;
    int ab;
    int ac;
    int ad;
    int ae;
    int af;
    int ag;
    int ah;
    int ai;
    NiBound m_3c;
    FUN_006ee100_Class* __thiscall FUN_006ee100();
};
struct B006815c0
{
    char d[12];
    B006815c0();
};
struct FUN_006efd50
{
    char _p[12];
    B006815c0 m[2];
    FUN_006efd50();
};
struct S006F1E90
{
    bool __thiscall FUN_006f1fc0(int);
    bool __thiscall IsSegmentClear(int, int);
    bool __thiscall FUN_006f1e90(int, int);
};
extern int DAT_0106d814;
struct FUN_006f26d0_Class
{
    virtual ~FUN_006f26d0_Class();
};
struct FUN_006f26f0_Class : public FUN_006f26d0_Class
{
    void __thiscall Clear(bool a1);
    ~FUN_006f26f0_Class();
};
extern unsigned int DAT_010a2720;
struct ScrapHeapHelper
{
    void* __thiscall Allocate(unsigned int a1, unsigned int a2);
};
struct BSScrapArray
{
    char _pad[16];
    void* m_pPoolBase;
    void* __thiscall AllocateElements(unsigned int a1);
};
extern unsigned int DAT_010a2720;
struct ScrapHeap_Allocate_Helper
{
    void* __thiscall Allocate(unsigned int, unsigned int);
};
struct FUN_006f2c10_Holder
{
    int _00;
    int _04;
    int _08;
    int _0c;
    ScrapHeapBuffer* _10;
    void* __thiscall FUN_006f2c10(int);
};
extern unsigned int DAT_010a2720;
struct ArrSI
{
    unsigned int GetFlags();
};
struct FUN_00aa54a0_s
{
    void* Allocate(unsigned int, unsigned int);
    void Deallocate(void*);
};
struct FUN_006f2c40_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    FUN_00aa54a0_s* m_pStreamAllocator;
    void* __thiscall ReallocateArray(int a1, int a2);
};
void* __cdecl __memcpy(void* dst, const void* src, unsigned int n);
extern unsigned int DAT_010a2720;
struct AllocHelper_006f2ea0
{
    void* __thiscall Allocate(unsigned int, unsigned int);
};
struct Host_006f2ea0
{
    unsigned char _pad[16];
    AllocHelper_006f2ea0* _heap;
    void* __thiscall FUN_006f2ea0(int);
};
struct FUN_006f25b0
{
    virtual ~FUN_006f25b0();
    void* __thiscall FUN_006f2f30(unsigned int);
};
void _Deallocate(void*);
struct FUN_006f25d0
{
    ~FUN_006f25d0();
};
void __cdecl _Deallocate(void*);
struct FUN_006f2f60_shell : public FUN_006f25d0
{
    void* __thiscall FUN_006f2f60(unsigned int);
};
void __cdecl Deallocate(void* p);
struct FUN_006f2810_Class
{
    void __thiscall FUN_006f2810();
    void* __thiscall FUN_006f3020(unsigned int flags);
};
struct FUN_006f3050_Class
{
    void __thiscall FUN_006f2bb0();
    void* __thiscall FUN_006f3050(unsigned int flags);
};
struct FUN_006f2e40_Class
{
    void __thiscall FUN_006f2e40();
    void* __thiscall FUN_006f30b0(unsigned int flags);
};
void __cdecl Deallocate(void*);
struct FUN_006f3170_Class
{
    bool FUN_006f3170();
};
struct _Base_006f3c80
{
    ~_Base_006f3c80();
};
struct FUN_006f3f80_Class : public _Base_006f3c80
{
    void* __thiscall FUN_006f3f80(unsigned int flags);
};
struct FUN_006f4690_Class
{
    void __thiscall FUN_006f4690();
};
void __cdecl Deallocate(void*);
struct FUN_006f4850_Class
{
    void* __thiscall FUN_006f4850(unsigned int flags);
};
struct FUN_006f4b40
{
    ~FUN_006f4b40();
    void* __thiscall FUN_006f4be0(unsigned int);
};
struct FUN_006f4b90
{
    ~FUN_006f4b90();
    void* __thiscall FUN_006f4c10(unsigned int);
};
void __cdecl _Deallocate(void*);
struct FindTriangleForLocationFilter;
struct PathingLocationProxy
{
    bool FindContainingTriangle(FindTriangleForLocationFilter*);
};
struct FUN_006f5020_Class
{
    int m_flags;
    PathingLocationProxy m_proxy;
    void __thiscall UpdateProxyFlag();
};
struct FUN_006f9710_Class
{
    void __thiscall FUN_006f9b80();
    void* __thiscall FUN_006f9710(unsigned int a1);
};
extern int DAT_0106dfa0;
void __cdecl Deallocate(void*);
struct FUN_006f99a0_Class
{
    int m_vtbl;
    int m_auiShapeKeys;
    int m_i;
    void __thiscall FUN_006f99a0();
};
struct FUN_006f9b80_shell
{
    void __thiscall RemoveAll();
    virtual ~FUN_006f9b80_shell();
};
struct FUN_006f9b80 : public FUN_006f9b80_shell
{
    virtual ~FUN_006f9b80();
};
extern int DAT_0106dfc0;
void __cdecl Deallocate(void* p);
struct FUN_006f9be0_Class
{
    void __thiscall FUN_006f9be0();
};
void __cdecl Deallocate(void*);
struct FUN_006f9770_Class
{
    void __thiscall FUN_006f9770();
    FUN_006f9770_Class* __thiscall FUN_006f9cd0(unsigned int flags);
};
void __cdecl Deallocate(void*);
struct FUN_006f9d60_Class
{
    void __thiscall FUN_006f9be0();
    void* __thiscall FUN_006f9d60(unsigned int flags);
};
void __cdecl Deallocate(void*);
struct GlobalObject_006fa100
{
    void __thiscall FUN_006fa160();
    ~GlobalObject_006fa100();
    GlobalObject_006fa100* __thiscall FUN_006fa130(unsigned int flags);
};
struct FUN_006fa670_Target;
struct SoundListView
{
    void __thiscall AddTail(FUN_006fa670_Target*&);
};
extern SoundListView g_011d8624;
struct FUN_006fa670_Target
{
    void __thiscall AddSelfToList();
};
struct Flt
{
    operator unsigned int();
};
struct Tile
{
    int _0;
    Flt _4;
    NiNode* FUN_0056c7f0();
    void SetNodeFloat(float);
};
struct FUN_006fd750
{
    void __thiscall Unload();
};
void __cdecl Deallocate(void*);
struct FUN_006fca40_Class
{
    void* __thiscall FUN_006fca40(unsigned int a1);
};
struct FUN_00759d80_Class
{
    unsigned char FUN_00759d80();
};
struct FORenderedMenu
{
    bool GetInitialized();
};
struct FUN_006fea10_Class
{
    void* m_10;
    unsigned char __thiscall FUN_006fea10(bool a1);
    unsigned char __thiscall FUN_006fe920(bool a1);
};
extern int DAT_011d8794;
struct FUN_006ff660_Class
{
    int __thiscall FUN_006ff660(int a1);
};
void __cdecl FUN_006ff620();
struct FUN_006ffb20_Class
{
    void __thiscall SetSourceAndTarget(int a1, int a2);
};
struct FUN_006ff920 : public FUN_006ff970_Class
{
    FUN_006ff920(int a1, int a2);
};
void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int size);
struct FUN_006e3e70_Class
{
    void __thiscall FUN_006e3e70(char* a, char* b, unsigned int c);
};
struct SaveGameSizeState
{
    int iSize;
    int iPosition;
    int iDataLength;
    virtual int Write(unsigned int);
    virtual int Write2(unsigned int);
    void __thiscall FUN_006e95d0(unsigned int, unsigned int);
    void __thiscall InitSizeState(unsigned int requested, unsigned int savedSize);
};
struct FUN_006e9700_Class
{
    virtual void* __thiscall v0();
    virtual int __thiscall v1(unsigned int a1);
    void __thiscall ConstructArray(int a1, unsigned int a2);
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void __thiscall FUN_006e97a0(unsigned int a1, unsigned int a2);
};
struct FUN_006ec260_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int* m_10;
    bool __thiscall FUN_006ec260(int a1);
};
struct FUN_006ecc70_Class
{
    void __thiscall PushFront(int* p);
};
bool __cdecl FUN_00696540(const NiPoint3*, const NiPoint3*, const NiPoint3*, const NiPoint3*);
struct NavMeshTriangleReference;
struct NavMeshTriangleEdgeReference;
struct AStarNode
{
    NavMeshTriangleReference* m_pReferencedNode;
    NavMeshTriangleEdgeReference* m_pLink;
    int m_i;
    int m_iUnknownValue;
    float m_f;
    float m_g;
    float m_h;
    float m_k;
    int m_l;
    int m_iUnknownValue2;
    int m_uiValueCount;
    int m_o;
};
struct Arr
{
    AStarNode* __thiscall GetAt(int);
};
struct FUN_006ed7d0_Class
{
    bool FUN_006ed7d0(unsigned int a1, unsigned int a2, const NiPoint3& a3, const NiPoint3& a4);
};
struct S5460
{
    bool __thiscall FUN_00438b90();
    unsigned int __thiscall FUN_009a3910();
    void __thiscall FUN_009f6540(unsigned int a1, unsigned int a2);
    virtual void* v0();
    virtual void* v1(unsigned int a);
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
    virtual void* v6();
    virtual void* v7();
    virtual void* v8();
    virtual void* v9();
    virtual void* v10();
    virtual void* v11();
    virtual void* v12();
    virtual void* v13();
    virtual void* v14();
    virtual void* v15();
    void* p;
    unsigned int i;
    unsigned int n;
};
unsigned int __fastcall FUN_006f31f0(S5460* self);
void* __cdecl _fnv_zlib_memset(void* p, int c, unsigned int n);
struct FUN_006f98c0_Class2
{
    void* m_vtbl;
    int m_uiItemCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_006f98c0_Class2(int count);
};
struct AnimIdle;
struct Helper62d0
{
    AnimIdle* m_p;
    Helper62d0& operator=(const Helper62d0&);
};
struct FUN_006f9d90_S
{
    int m_iWordAt00;
    float m_iWordAt04;
    float m_8;
    float m_iThirdValue;
    float m_10;
    float m_14;
    float m_18;
    Helper62d0 m_1c;
    FUN_006f9d90_S& operator=(const FUN_006f9d90_S&);
};
struct FakeArray
{
    virtual void* v0();
    virtual void* Write(unsigned int);
    void ConstructElements(void* a1, int a2);
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void __thiscall ResizeAndFill(unsigned int a1, unsigned int a2);
};
extern SoundListView g_011d8624;
extern unsigned char DAT_0119f154;
struct FUN_006fb170_Class
{
    void __thiscall UpdateWaterReferences(int a1);
};
struct FUN_006fb3d0_Class
{
    void __thiscall FUN_006fb3d0(int a1);
};
struct ListNode_680910
{
    int* _ref_006815c0();
    ListNode_680910* GetNext();
};
void SetSoundListFlag(unsigned char a1);
struct FUN_006f2510_Class
{
    void* FUN_006f2510(int, int, int);
};
struct FUN_006edce0_Class
{
    BSSimpleList<BGSPerk*> l0;
    int p0;
    BSSimpleList<BGSPerk*> l1;
    int p1;
    BSSimpleList<BGSPerk*> l2;
    int p2;
    BSSimpleList<BGSPerk*> l3;
    FUN_006f2510_Class f;
    FUN_006edce0_Class* FUN_006edce0(int a1);
};
struct NavMeshSearchLOSArray
{
    void __thiscall Clear(bool);
    virtual ~NavMeshSearchLOSArray();
};
struct FUN_006f2bb0_Class : public NavMeshSearchLOSArray
{
    virtual ~FUN_006f2bb0_Class();
};
struct FUN_006f46f0_Node
{
    FUN_006f46f0_Node* m_00;
    FUN_006f46f0_Node* m_04;
    FUN_006f46f0_Node* m_08;
    FUN_006f46f0_Node* m_0c;
    FUN_006f46f0_Node* m_10;
    FUN_006f46f0_Node* m_14;
    FUN_006f46f0_Node* m_18;
    FUN_006f46f0_Node* m_1c;
    FUN_006f46f0_Node* m_20;
    FUN_006f46f0_Node* m_24;
    FUN_006f46f0_Node** m_28;
    FUN_006f46f0_Node* m_2c;
};
FUN_006f46f0_Node* __fastcall PopFirstNode(FUN_006f46f0_Node* a1);
struct Arr16
{
    void FUN_006dbcf0(int*, int);
};
struct SizeState
{
    virtual void v0();
    virtual int Write(unsigned int requested);
    void FUN_006dbcf0(int*, int);
    int iSize;
    int iPosition;
    int iDataLength;
    void __thiscall ResetAndWrite(unsigned int requested, unsigned int savedSize);
};
struct FUN_006f9a00
{
    void* m_pVtbl;
    int m_uiLogicalSize;
    void* m_pData;
    int m_iPad;
    FUN_006f9a00(int iSize);
};
struct FUN_006c8a30_Class
{
    void FUN_006a8500();
};
struct FUN_006dc640_Class
{
    void FUN_006dc640(char*, char*, unsigned int);
};
struct FUN_006f9eb0_Class
{
    virtual void v0();
    virtual char* v1(unsigned int);
    virtual void v2();
    virtual char* v3(char*, unsigned int);
    char* m;
    unsigned int pad;
    unsigned int key;
    void FUN_006f9eb0(unsigned int a, unsigned int b);
};
struct FUN_006fa180_StandIn
{
    virtual int v00();
    int m_iElementCount;
    int m_pos;
    int m_len;
    virtual int v04(unsigned int);
    void __thiscall FUN_006f9ff0(int, unsigned int);
    void __thiscall FUN_006fa180(unsigned int requested, unsigned int savedSize);
};
struct Unk006fec90
{
    int GetActiveMenu(int a1);
};
struct Unk006fec00
{
    bool FUN_006fec00(int a1);
};
struct Unk006fec90_Class
{
    int GetActiveMenu(int a1);
    bool FUN_006fec00(int a1);
    int m_iWordAt00;
    int m_cByteAtOffset1;
    int m_cByteAtOffset2;
    int m_cByteAtOffset3;
    FORenderedMenu* m_pMenu;
    int m_iWordAt04;
    int m_5;
    int m_6;
    Unk006fec90* m_pItems[4];
};
// Steam SDK import (called through the IAT in the original)
extern "C" __declspec(dllimport) void __cdecl SteamAPI_RunCallbacks();
struct FUN_006ff860_Class
{
    void FUN_006ff860();
};
struct FUN_006ffb90_Class
{
    void __thiscall SetParams(int a1, int a2);
};
struct FUN_006ff9f0 : FUN_006ff970_Class
{
    int m_kPointA;
    int m_kPointB;
    FUN_006ff9f0(int a1, int a2);
};
struct FUN_006ffa70 : FUN_006ff970_Class
{
    int __thiscall FUN_006ffc20(int a1, int a2);
    int m_i;
    int m_iUnknownValue;
    FUN_006ffa70(int a1, int a2);
};
struct FUN_006e22d0_Class
{
    int m0;
    _Mem_2064 m1;
    void __thiscall FUN_006e22d0();
};
struct Elem4
{
    int m_uiFilterValue;
    void __thiscall FUN_008228f0(int a1);
};
struct FUN_006ec5b0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    Elem4 m_queue[256];
    unsigned int m_uiItemCount;
    unsigned int m_40c;
    unsigned int m_uiEdgeIndex;

    bool __thiscall FUN_006ec5b0(Helper62d0* a1);
};
struct FUN_006ee050_Class
{
    int m0;
    int m4;
    NiBound mBound;
    FUN_006ee050_Class();
};
struct FUN_006f02e0_Point
{
    int x;
    int y;
    int z;
};
struct FUN_006f02e0_Node
{
    unsigned int* p0;
    unsigned int* p1;
};
struct FUN_006f02e0_Class
{
    void CopyNodePositions();
};
struct BSSimpleArrayActor
{
    unsigned int __thiscall Add(void*& item);
};
struct FUN_0042fb60_shell
{
    void __thiscall FUN_0042fb60(char* destination, char* source, unsigned int count);
};
struct CtorHelper
{
    void __thiscall InitializeItems(NavMeshInfo** items, unsigned int count);
};
struct FUN_006f23d0_Class
{
    virtual void FUN_006f23d0_v0() = 0;
    virtual void* FUN_006f23d0_v4(unsigned int count) = 0;

    void* m_p;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;

    void __thiscall FUN_006f23d0(unsigned int index, void*& value);
};
struct S006949d0
{
    void* __thiscall GetAt(int);
};
struct FUN_006f4480_Class : public S006949d0
{
    void __thiscall FUN_006f4480(int, int);
};
struct FUN_006f4230_EdgeData
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
};
struct FUN_006f4230_ExtraData
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_C;
};
struct FUN_006f4230_Node
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    FUN_006f4230_Node* m_next;
};
struct EdgeArr
{
    FUN_006f4230_EdgeData* __thiscall FUN_006a1440(unsigned int);
};
struct H2 : public EdgeArr
{
    void __thiscall FUN_006a8890(int, int);
};
struct FUN_006f4230_Class
{
    bool __thiscall CopyNodeListToArrays(FUN_006f4230_Node*, H2*, FUN_006f4480_Class*);
};
struct ScrapHeapBuffer;
void* __cdecl FUN_006a1f90(unsigned int, ScrapHeapBuffer*);
struct FUN_006f47f0_Class
{
    void* __thiscall Constructor();
};
struct FUN_006f4340_Class : public ScrapHeapBuffer
{
    void* __thiscall FUN_006f4340();
};
struct FUN_006f4430_Class
{
    void __thiscall UnlinkFromList(int* a1);
};
struct GO
{
    unsigned int m_uiFilterValue;
    operator unsigned int() const;
};
struct QIdlePtr : public GO
{
    QIdlePtr& operator=(void* a1);
};
struct MiddleHighProcess
{
    void __thiscall FUN_00929260(unsigned char a1);
};
struct FUN_006faa50_Class
{
    void __thiscall CopyHelperFromOffset(void* a1);
};
struct FUN_006faa70_Class
{
    void __thiscall FUN_006faa70(void* a1);
};
struct FUN_006fa990_Entry
{
    int m_uiFilterValue;
};
struct TargetObject
{
    GO* m_go;
    FUN_006fa990_Entry m_entry4;
    FUN_006fa990_Entry m_entry8;
    FUN_006fa990_Entry m_entryC;
    FUN_006fa990_Entry m_entry10;
    char m_ucUnknownByte[0x10];
    QIdlePtr m_idle;
    bool m_flag;

    void __thiscall FUN_006f6250(void* a1);
    void __thiscall AssignValue(void* a1);
    void __thiscall FUN_006fa990();
};
struct BGSTerrainManager
{
    unsigned int __thiscall GetMinLevel();
};
struct TESActorBaseData
{
    short __thiscall GetFatigue() const;
};
struct BSShaderPPLightingProperty
{
    short __thiscall GetDiffuseTextureIndex();
};
struct FUN_006fe920_Class
{
    BGSTerrainManager* m_terrainManager;
    int m_iValueAtOffset04;
    unsigned char m_ucUnknownByte[0x18];
    FUN_006fea10_Class* m_object20;
    FUN_006fea10_Class* m_object24;
    FUN_006fea10_Class* m_object28;
    FUN_006fea10_Class* m_object2c;

    bool __thiscall FUN_006fe920(bool value);
};
struct FUN_006fed30_Callee
{
    int __thiscall FUN_006fed30(int a1);
};
struct FUN_006fed30_Class
{
    int __thiscall FUN_006fed30(int a1);
};
struct LocalUnk006fec90_Class
{
    bool __thiscall FUN_006fec00(int a1);
};
struct LocalBSSimpleList
{
    void* __thiscall GetNext();
};
void* __cdecl FUN_006fe510();
extern void* DAT_0106ced8;
void* __cdecl _NiMalloc(unsigned int size);
void* __cdecl memset(void* destination, int value, unsigned int size);
struct FUN_006e0f20_Class
{
    void** m_ppVirtualMethodTable;
    unsigned int m_hashSize;
    void* m_table;
    unsigned int m_entryCount;

    FUN_006e0f20_Class* __thiscall ConstructHashTable(unsigned int hashSize);
};
struct FUN_006e12c0_Class
{
    virtual void v0();
    virtual int v1(int requested);
    virtual void v2();
    virtual int v3(int oldData, int requested);
    int currentData;
    int reserved08;
    int cachedKey;
    void __thiscall FUN_006d07d0(int replacement, int previous, int previousKey);
    void __thiscall FUN_006a8500();
    void __thiscall SetData(int newData, int searchKey);
};
struct FUN_004968b0
{
    virtual ~FUN_004968b0();
    int referenceCount;
    FUN_004968b0();
};
struct FUN_006e2080
{
    int data;
    int count;
    int capacity;
    int allocation;
    int flags;
    FUN_006e2080(unsigned int size);
    ~FUN_006e2080();
};
struct FUN_0042f800
{
    int x;
    int y;
    int z;
    int w;
    FUN_0042f800();
};
struct Position3
{
    int x;
    int y;
    int z;
};
struct FUN_006e1370 : FUN_004968b0
{
    FUN_006e2080 items;
    FUN_0042f800 range;
    int value2c;
    int value30;
    int value34;
    bool option38;
    bool option39;
    Position3 position;
    float size;
    FUN_006e1370(Position3 coordinates, float dimension);
    virtual ~FUN_006e1370();
};
struct FUN_006dcbb0
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
    FUN_006dcbb0();
    ~FUN_006dcbb0();
};
struct FUN_006e2210
{
    int m_00;
    FUN_006dcbb0 m_04;
    ref_006815c0 m_2c;
    int unk30;
    int unk34;
    int m_38;
    FUN_006e2210();
};
struct FUN_006e3d30_cls
{
    virtual void v0();
    virtual int v1(int a);
    virtual void v2();
    virtual int v3(int a, int b);
    int m_04;
    int m_08;
    int m_0c;
    void FUN_006e3d30(int a1, int a2);
    void FUN_006e3e70(int a, int b, int c);
    void FUN_006a8500();
};
struct TESObjectCELL_s
{
    void* GetWorld();
};
struct Loc_s
{
    TESObjectCELL_s* GetContainingCell();
};
struct Holder_s
{
    Loc_s* GetLocationPointer();
};
struct Flags_s
{
    int m_flags;
    Flags_s(int a1);
    void SetBit(int a1);
    void SetLevel(unsigned int a1);
};
struct Child84_s
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
    Child84_s();
};
struct Child80_s
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
    Child80_s();
    void SetFlags(Flags_s a1);
    void SetParent(void* a1);
    void SetChild(Child84_s* a1);
};
void* __cdecl HeapAlloc_s(unsigned int align, unsigned int size);
void* __cdecl operator new(unsigned int, void*);
void __cdecl operator delete(void*, void*);
struct PathObj_s
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
    Holder_s* m_holder;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    void* m_parent;
    void* m_pOwningWorld;
    Child80_s* m_child80;
    Child84_s* m_child84;
    void Setup();
    bool SetupFromCellWorld();
};
class FUN_006e6db0_cls;
class FUN_006e6db0_ObjectBase
{
  public:
    virtual void Destroy();
    virtual void Release(int flags);
};
void FreeObjectMemory(void* p);
class FUN_006e6db0_cls
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
    FUN_006e6db0_ObjectBase* m_80;
    FUN_006e6db0_ObjectBase* m_84;

    void FlushChildren();
    void FUN_006e6db0();
};
struct FUN_006e7190_Helper30
{
    void Tick();
};
struct FUN_006e7190_Target
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
    FUN_006e7190_Helper30 m_30;
    void Foo(int a);
    void Bar(int a);
};
struct FUN_006e7190_Helper84
{
    void Tick2();
};
struct FUN_006e7190_Dispatch
{
    virtual void v000() = 0;
    virtual void v001() = 0;
    virtual void v002() = 0;
    virtual void v003() = 0;
    virtual void v004() = 0;
    virtual void v005() = 0;
    virtual void v006() = 0;
    virtual void v007() = 0;
    virtual void v008() = 0;
    virtual void v009() = 0;
    virtual void v010() = 0;
    virtual void v011() = 0;
    virtual void v012() = 0;
    virtual void v013() = 0;
    virtual void v014() = 0;
    virtual void v015() = 0;
    virtual void v016() = 0;
    virtual void v017() = 0;
    virtual void v018() = 0;
    virtual void v019() = 0;
    virtual void v020() = 0;
    virtual void v021() = 0;
    virtual void v022() = 0;
    virtual void v023() = 0;
    virtual void v024() = 0;
    virtual void v025() = 0;
    virtual void v026() = 0;
    virtual void v027() = 0;
    virtual void v028() = 0;
    virtual void v029() = 0;
    virtual void v030() = 0;
    virtual void v031() = 0;
    virtual void v032() = 0;
    virtual void v033() = 0;
    virtual void v034() = 0;
    virtual void v035() = 0;
    virtual void v036() = 0;
    virtual void v037() = 0;
    virtual void v038() = 0;
    virtual void v039() = 0;
    virtual void v040() = 0;
    virtual void v041() = 0;
    virtual void v042() = 0;
    virtual void v043() = 0;
    virtual void v044() = 0;
    virtual void v045() = 0;
    virtual void v046() = 0;
    virtual void v047() = 0;
    virtual void v048() = 0;
    virtual void v049() = 0;
    virtual unsigned char Check(FUN_006e7190_Target* p) = 0;
};
struct FUN_006e7190_cls
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
    FUN_006e7190_Dispatch* m_7c;
    FUN_006e7190_Target* m_80;
    FUN_006e7190_Helper84* m_84;
    int m_88;
    bool UpdateAndCheck(void* a1, void* a2);
};
class B6E9570PathingLocation
{
  public:
    B6E9570PathingLocation& operator=(const B6E9570PathingLocation& kOther);

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
};
struct B6E9570Point3
{
    float x;
    float y;
    float z;
};
class FUN_006e9570_cls
{
  public:
    FUN_006e9570_cls& operator=(const FUN_006e9570_cls& kOther);

    int m_iType;
    B6E9570PathingLocation m_kLocation;
    B6E9570Point3 m_kPathOffset;
    int m_iFlags;
};
void* __cdecl operator new(unsigned int, void*);
void __cdecl operator delete(void*, void*);
struct FUN_006f4cd0
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
    FUN_006f4cd0();
};
struct FUN_006e95d0_Class
{
    void __thiscall FUN_006e95d0(FUN_006f4cd0* destination, unsigned int count);
};
class FUN_006ecc40
{
  public:
    virtual ~FUN_006ecc40();
    int value04;
    int value08;
    FUN_006ecc40();
};
class FUN_006ed0e0
{
  public:
    int value00;
    int value04;
    int value08;
    FUN_006ed0e0();
    ~FUN_006ed0e0();
};
class FUN_006ec000 : public FUN_006ecc40
{
  public:
    FUN_006ed0e0 nodes[256];

    FUN_006ec000();
    virtual ~FUN_006ec000();
    void InitElementList(unsigned int count, FUN_006ed0e0* entries);
};
extern int DAT_0106d698;
struct FUN_006ec2e0_Elem
{
    int unk00;
    int unk04;
    FUN_006ec2e0_Elem* next;
    int __thiscall FUN_006815c0();
};
struct FUN_006ec2e0_Free
{
    void __thiscall FUN_006ecb10(FUN_006ec2e0_Elem*& e);
};
struct FUN_006ec2e0_Out
{
    void __thiscall FUN_006eaa00(int value);
};
struct FUN_006ec2e0_Class
{
    int unk00;
    int unk04;
    FUN_006ec2e0_Free* freeList;
    FUN_006ec2e0_Elem* head;
    bool __thiscall PopHead(FUN_006ec2e0_Out* a1);
};
void* operator new(unsigned int size, void* where);
void operator delete(void* p, void* where);
class FUN_006ec4b0_item
{
  public:
    unsigned int m_unk00;
    FUN_006ec4b0_item(void* arg);
};
class FUN_006ec4b0_cls
{
  public:
    unsigned int m_unk00;
    unsigned int m_unk04;
    void* m_slots[0x100];
    unsigned int m_uiItemCount;
    unsigned int m_pFirstNode;

    unsigned char PushItem(void* arg);
};
class RecursiveSpinLock
{
  public:
    void Lock(char* name);
    void Unlock();
};
struct FUN_006ec900_Class
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual bool Visit(unsigned int index, int arg);
    int unk04;
    unsigned int count;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    RecursiveSpinLock lock;
    bool VisitUntilFound(int a1);
};
struct FUN_006ecce0_Class
{
    void __thiscall FUN_007b3fa0(unsigned int);
    void __thiscall FUN_006ecce0();
};
struct SpawnedBase
{
    unsigned int unk04;
    unsigned int unk08;
    SpawnedBase();
    virtual ~SpawnedBase();
};
struct SpawnedElem
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    SpawnedElem();
    ~SpawnedElem();
};
class FUN_006ece90 : public SpawnedBase
{
  public:
    SpawnedElem m_0c[0x100];

    FUN_006ece90();
    virtual ~FUN_006ece90();
    void InitElementList(unsigned int count, SpawnedElem* arr);
};
struct FUN_006ed040_Elem
{
    unsigned int unk00;
    unsigned int unk04;
    FUN_006ed040_Elem* m_next;
};
struct FUN_006ed040_cls
{
    unsigned int unk00;
    long volatile m_lock;
    FUN_006ed040_Elem* m_pFirstNode;
    void __thiscall InitElementList(unsigned int count, FUN_006ed040_Elem* elems);
};
void FUN_0040fbe0();
struct Position_006edd30
{
    float x;
    float y;
    float z;
    float DotProduct(const Position_006edd30*);
};
struct PositionArray_006edd30
{
    void FUN_006971e0(Position_006edd30*, unsigned short);
};
struct PositionIndex_006edd30
{
    PositionArray_006edd30* source;
    unsigned short itemIndex;
};
struct PositionCollection_006edd30
{
    PositionIndex_006edd30* FUN_006dad90(unsigned int);
};
struct Stamp_006edd30
{
    unsigned int FUN_0068efb0();
};
struct LocationContext_006edd30
{
    Stamp_006edd30* stampSource;
    unsigned short index;
    unsigned short flags;
    unsigned int formID;
};
struct ContextProvider_006edd30
{
    LocationContext_006edd30* FUN_006ced70();
};
struct PointerList_006edd30
{
    void* entries;
    unsigned int capacity;
    unsigned int size;
    unsigned int flags;
    unsigned int revision;
    unsigned int* FUN_006f2270();
    void FUN_007cb2e0(void**);
};
struct Location_006edd30
{
    Position_006edd30 position;
    unsigned int unknown0C;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1C;
    unsigned int unknown20;
    unsigned int stamp;
    unsigned short index;
    unsigned short flags;
    PointerList_006edd30 relatedPaths;
};
struct PathEdge_006edd30
{
    unsigned int nodeKey;
    Location_006edd30* location;
    unsigned int stamp;
    unsigned short index;
    unsigned short flags;
    unsigned int nextIndex;
    unsigned char active;
    unsigned char color;
    unsigned short padding16;
    unsigned int state;
};
struct Path_006edd30
{
    Location_006edd30* start;
    Location_006edd30* finish;
    unsigned int unknown08;
    unsigned int unknown0C;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1C;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2C;
    unsigned int unknown30;
    unsigned int unknown34;
    float distance;
    unsigned int stamp;
    unsigned short index;
    unsigned short flag42;
    unsigned int formID;
    unsigned int state;
    PathEdge_006edd30* startEdge;
    PathEdge_006edd30* finishEdge;
};
struct FUN_006edd30_shell
{
    unsigned int unknown00;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0C;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1C;
    PositionCollection_006edd30* positions;
    ContextProvider_006edd30* contexts;
    unsigned int unknown28;
    unsigned int unknown2C;
    unsigned int unknown30;
    unsigned int unknown34;
    unsigned int unknown38;
    unsigned int unknown3C;
    PointerList_006edd30 starts;
    PointerList_006edd30 ends;
    PointerList_006edd30 startEdges;
    PointerList_006edd30 endEdges;
    PointerList_006edd30 paths;
    Location_006edd30* FUN_006edc40();
    PathEdge_006edd30* CreateSize28();
    Path_006edd30* CreateObject();
    void FUN_006edd30(const Position_006edd30* start, const Position_006edd30* finish);
};
extern unsigned int DAT_010a2720;
void* __cdecl operator new(unsigned int size, void* place);
void __cdecl operator delete(void* ptr, void* place);
struct FUN_006ee050_Size28 : public FUN_006ee050_Class
{
    int extra0c;
    int extra10;
    int extra14;
    int extra18;
    __forceinline FUN_006ee050_Size28() : FUN_006ee050_Class()
    {}
};
struct FUN_006edfc0_Host
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
    FUN_00aa54a0_s allocator;
    void* __thiscall CreateSize28();
};
struct Heap_006ee070
{
    void* __thiscall Allocate(unsigned int size, unsigned int flags);
};
void* __cdecl operator new(unsigned int size, void* where);
void __cdecl operator delete(void* p, void* where);
struct FUN_006ee070_obj
{
    char unk00[0x58];
    FUN_006ee070_obj();
};
struct FUN_006ee070_cls
{
    char unk00[0x30];
    Heap_006ee070 m_pStreamAllocator;
    void* __thiscall CreateObject();
};
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
};
struct S0069a690
{
    int unk0, unk4;
    S0069a690* FUN_0069a690(const S0069a690*);
};
struct EH
{
    int unk0, unk4, unk8;
    EH& operator=(const EH&);
};
struct Node;
struct Edge;
template <class T> struct LocalArray
{
    int unk0, unk4, unk8, unkC, unk10;
    T& FUN_00877a30(unsigned);
    unsigned FUN_0044ddc0();
    unsigned FUN_007cb2e0(T&);
    T& GetFirstForm();
    T& FUN_006f2270();
    void FUN_006f2290(unsigned, bool);
    void FUN_006f23d0(unsigned, T&);
};
struct Node
{
    NiPoint3 origin, position, direction;
    S0069a690 info;
    LocalArray<Edge*> edges;
};
struct Edge
{
    Node* first;
    Node* second;
    EH info;
    unsigned char flag;
    int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;
    float weight;
    EH bound;
    unsigned index;
    Edge* left;
    Edge* right;
};
bool __cdecl FUN_00696540(const NiPoint3*, const NiPoint3*, const NiPoint3*, const NiPoint3*);
struct FUN_006ee740_Class
{
    int unk0, unk4, unk8, unkC, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    LocalArray<Node*> nodesA, nodesB;
    LocalArray<Edge*> edgesA, edgesB, edgesC;
    Node* FUN_006edc40();
    Edge* CreateSize28();
    Edge* CreateObject();
    void SetEntry(unsigned, Edge*, bool);
    void AssignRecordIndices(unsigned, Edge*);
    Node* SplitNode(unsigned index, bool side, const NiPoint3& start, const NiPoint3& end);
};
struct FUN_006eec00_Entry
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int index;
};
struct FUN_006eec00_Array
{
    void FUN_006f23d0(unsigned int index, void*& value);
    unsigned int FUN_0044ddc0();
    FUN_006eec00_Entry** FUN_00877a30(unsigned int index);
};
struct FUN_006eec00_Class
{
    void SetEntry(unsigned int index, void* value, unsigned char usePrimary);
};
struct IndexedRecord
{
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
};
struct IndexCollection
{
    void __thiscall FUN_006f23d0(unsigned int first, unsigned int* last);
    unsigned int __thiscall FUN_0044ddc0();
    IndexedRecord** __thiscall FUN_00877a30(unsigned int index);
};
struct FUN_006eecc0_Owner
{
    void __thiscall AssignRecordIndices(unsigned int first, unsigned int last);
};
struct V08
{
    int x, y, z;
};
struct N08
{
    V08 original, copy;
};
struct A08
{
    int unk00, unk04, unk08, unk0c, unk10;
    N08*& GetFirstForm();
    N08*& FUN_006f2270();
    unsigned int FUN_0044ddc0();
};
struct F08
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    float unk2c;
    int unk30, unk34, unk38, unk3c;
    A08 unk40, unk54;
    unsigned int UpdateNodeDirection(unsigned int, float, bool);
    void FUN_006eef80();
};
extern const float DAT_01016248;
struct Pt_6f03a0
{
    float x, y, z;
    Pt_6f03a0 operator+(const Pt_6f03a0& rhs) const;
    Pt_6f03a0 operator*(float s) const;
};
struct Elem_6f03a0
{
    int unk00;
    int unk04;
    Pt_6f03a0 pos08;
    int unk14;
    int unk18;
    int unk1c;
    Pt_6f03a0 pos20;
    Pt_6f03a0 pos2c;
};
struct Arr_6f03a0
{
    unsigned int GetSize();
    Elem_6f03a0*& GetAt(unsigned int i);
};
struct Host_6f03a0
{
    int unk[36];
    Arr_6f03a0 arr90;
    void FUN_006f03a0();
};
struct S_00aa42e0_Mgr
{
    void* __thiscall FUN_00aa42e0();
};
S_00aa42e0_Mgr* __cdecl FUN_00401020();
struct S_006f2510_Base
{
    int unk04;
    int unk08;
    int unk0c;
    S_006f2510_Base();
    virtual ~S_006f2510_Base();
    void __thiscall FUN_006b3eb0(unsigned int a, unsigned int b);
};
struct FUN_006f2510 : S_006f2510_Base
{
    void* unk10;
    FUN_006f2510(unsigned int a, unsigned int b, void* heap);
    virtual ~FUN_006f2510();
};
struct LOSElem
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
};
struct LOSArray6f29e0
{
    virtual void v0();
    virtual LOSElem* Allocate(unsigned int count);
    LOSElem* m_data;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;

    void Clear(bool shrink);
    bool ShouldShrink();
    unsigned int GetShrinkCapacity();
    void Move(LOSElem* dst, LOSElem* src, unsigned int count);
    void Destruct(LOSElem* p, unsigned int count);
    void FreeData();
    void RemoveRange(unsigned int index, unsigned int count, bool shrink);
};
class Base_6f33b0
{
  public:
    virtual void v00();
    int unk04;
    int unk08;
    int unk0C;
    Base_6f33b0();
    ~Base_6f33b0();
};
class Member_6f33b0_2064
{
  public:
    int m_00;
    Member_6f33b0_2064();
    ~Member_6f33b0_2064();
};
class Member_6f33b0_20a4
{
  public:
    int m_00;
    Member_6f33b0_20a4();
    ~Member_6f33b0_20a4();
};
class FUN_006f33b0_cls : public Base_6f33b0
{
  public:
    virtual void v00();
    int unk0010, unk0014, unk0018, unk001C, unk0020, unk0024, unk0028, unk002C, unk0030, unk0034, unk0038, unk003C,
        unk0040, unk0044, unk0048, unk004C;
    int unk0050, unk0054, unk0058, unk005C, unk0060, unk0064, unk0068, unk006C, unk0070, unk0074, unk0078, unk007C,
        unk0080, unk0084, unk0088, unk008C;
    int unk0090, unk0094, unk0098, unk009C, unk00A0, unk00A4, unk00A8, unk00AC, unk00B0, unk00B4, unk00B8, unk00BC,
        unk00C0, unk00C4, unk00C8, unk00CC;
    int unk00D0, unk00D4, unk00D8, unk00DC, unk00E0, unk00E4, unk00E8, unk00EC, unk00F0, unk00F4, unk00F8, unk00FC,
        unk0100, unk0104, unk0108, unk010C;
    int unk0110, unk0114, unk0118, unk011C, unk0120, unk0124, unk0128, unk012C, unk0130, unk0134, unk0138, unk013C,
        unk0140, unk0144, unk0148, unk014C;
    int unk0150, unk0154, unk0158, unk015C, unk0160, unk0164, unk0168, unk016C, unk0170, unk0174, unk0178, unk017C,
        unk0180, unk0184, unk0188, unk018C;
    int unk0190, unk0194, unk0198, unk019C, unk01A0, unk01A4, unk01A8, unk01AC, unk01B0, unk01B4, unk01B8, unk01BC,
        unk01C0, unk01C4, unk01C8, unk01CC;
    int unk01D0, unk01D4, unk01D8, unk01DC, unk01E0, unk01E4, unk01E8, unk01EC, unk01F0, unk01F4, unk01F8, unk01FC,
        unk0200, unk0204, unk0208, unk020C;
    int unk0210, unk0214, unk0218, unk021C, unk0220, unk0224, unk0228, unk022C, unk0230, unk0234, unk0238, unk023C,
        unk0240, unk0244, unk0248, unk024C;
    int unk0250, unk0254, unk0258, unk025C, unk0260, unk0264, unk0268, unk026C, unk0270, unk0274, unk0278, unk027C,
        unk0280, unk0284, unk0288, unk028C;
    int unk0290, unk0294, unk0298, unk029C, unk02A0, unk02A4, unk02A8, unk02AC, unk02B0, unk02B4, unk02B8, unk02BC,
        unk02C0, unk02C4, unk02C8, unk02CC;
    int unk02D0, unk02D4, unk02D8, unk02DC, unk02E0, unk02E4, unk02E8, unk02EC, unk02F0, unk02F4, unk02F8, unk02FC,
        unk0300, unk0304, unk0308, unk030C;
    int unk0310, unk0314, unk0318, unk031C, unk0320, unk0324, unk0328, unk032C, unk0330, unk0334, unk0338, unk033C,
        unk0340, unk0344, unk0348, unk034C;
    int unk0350, unk0354, unk0358, unk035C, unk0360, unk0364, unk0368, unk036C, unk0370, unk0374, unk0378, unk037C,
        unk0380, unk0384, unk0388, unk038C;
    int unk0390, unk0394, unk0398, unk039C, unk03A0, unk03A4, unk03A8, unk03AC, unk03B0, unk03B4, unk03B8, unk03BC,
        unk03C0, unk03C4, unk03C8, unk03CC;
    int unk03D0, unk03D4, unk03D8, unk03DC, unk03E0, unk03E4, unk03E8, unk03EC, unk03F0, unk03F4, unk03F8, unk03FC,
        unk0400, unk0404, unk0408, unk040C;
    int unk0410, unk0414, unk0418, unk041C, unk0420, unk0424, unk0428, unk042C, unk0430, unk0434, unk0438, unk043C,
        unk0440, unk0444, unk0448, unk044C;
    int unk0450, unk0454, unk0458, unk045C, unk0460, unk0464, unk0468, unk046C, unk0470, unk0474, unk0478, unk047C,
        unk0480, unk0484, unk0488, unk048C;
    int unk0490, unk0494, unk0498, unk049C, unk04A0, unk04A4, unk04A8, unk04AC, unk04B0, unk04B4, unk04B8, unk04BC,
        unk04C0, unk04C4, unk04C8, unk04CC;
    int unk04D0, unk04D4, unk04D8, unk04DC, unk04E0, unk04E4, unk04E8, unk04EC, unk04F0, unk04F4, unk04F8, unk04FC,
        unk0500, unk0504, unk0508, unk050C;
    int unk0510, unk0514, unk0518, unk051C, unk0520, unk0524, unk0528, unk052C, unk0530, unk0534, unk0538, unk053C,
        unk0540, unk0544, unk0548, unk054C;
    int unk0550, unk0554, unk0558, unk055C, unk0560, unk0564, unk0568, unk056C, unk0570, unk0574, unk0578, unk057C,
        unk0580, unk0584, unk0588, unk058C;
    int unk0590, unk0594, unk0598, unk059C, unk05A0, unk05A4, unk05A8, unk05AC, unk05B0, unk05B4, unk05B8, unk05BC,
        unk05C0, unk05C4, unk05C8, unk05CC;
    int unk05D0, unk05D4, unk05D8, unk05DC, unk05E0, unk05E4, unk05E8, unk05EC, unk05F0, unk05F4, unk05F8, unk05FC,
        unk0600, unk0604, unk0608, unk060C;
    int unk0610, unk0614, unk0618, unk061C, unk0620, unk0624, unk0628, unk062C, unk0630, unk0634, unk0638, unk063C,
        unk0640, unk0644, unk0648, unk064C;
    int unk0650, unk0654, unk0658, unk065C, unk0660, unk0664, unk0668, unk066C, unk0670, unk0674, unk0678, unk067C,
        unk0680, unk0684, unk0688, unk068C;
    int unk0690, unk0694, unk0698, unk069C, unk06A0, unk06A4, unk06A8, unk06AC, unk06B0, unk06B4, unk06B8, unk06BC,
        unk06C0, unk06C4, unk06C8, unk06CC;
    int unk06D0, unk06D4, unk06D8, unk06DC, unk06E0, unk06E4, unk06E8, unk06EC, unk06F0, unk06F4, unk06F8, unk06FC,
        unk0700, unk0704, unk0708, unk070C;
    int unk0710, unk0714, unk0718, unk071C, unk0720, unk0724, unk0728, unk072C, unk0730, unk0734, unk0738, unk073C,
        unk0740, unk0744, unk0748, unk074C;
    int unk0750, unk0754, unk0758, unk075C, unk0760, unk0764, unk0768, unk076C, unk0770, unk0774, unk0778, unk077C,
        unk0780, unk0784, unk0788, unk078C;
    int unk0790, unk0794, unk0798, unk079C, unk07A0, unk07A4, unk07A8, unk07AC, unk07B0, unk07B4, unk07B8, unk07BC,
        unk07C0, unk07C4, unk07C8, unk07CC;
    int unk07D0, unk07D4, unk07D8, unk07DC, unk07E0, unk07E4, unk07E8, unk07EC, unk07F0, unk07F4, unk07F8, unk07FC,
        unk0800, unk0804, unk0808, unk080C;
    int unk0810, unk0814, unk0818, unk081C, unk0820, unk0824, unk0828, unk082C, unk0830, unk0834, unk0838, unk083C,
        unk0840, unk0844, unk0848, unk084C;
    int unk0850, unk0854, unk0858, unk085C, unk0860, unk0864, unk0868, unk086C, unk0870, unk0874, unk0878, unk087C,
        unk0880, unk0884, unk0888, unk088C;
    int unk0890, unk0894, unk0898, unk089C, unk08A0, unk08A4, unk08A8, unk08AC, unk08B0, unk08B4, unk08B8, unk08BC,
        unk08C0, unk08C4, unk08C8, unk08CC;
    int unk08D0, unk08D4, unk08D8, unk08DC, unk08E0, unk08E4, unk08E8, unk08EC, unk08F0, unk08F4, unk08F8, unk08FC,
        unk0900, unk0904, unk0908, unk090C;
    int unk0910, unk0914, unk0918, unk091C, unk0920, unk0924, unk0928, unk092C, unk0930, unk0934, unk0938, unk093C,
        unk0940, unk0944, unk0948, unk094C;
    int unk0950, unk0954, unk0958, unk095C, unk0960, unk0964, unk0968, unk096C, unk0970, unk0974, unk0978, unk097C,
        unk0980, unk0984, unk0988, unk098C;
    int unk0990, unk0994, unk0998, unk099C, unk09A0, unk09A4, unk09A8, unk09AC, unk09B0, unk09B4, unk09B8, unk09BC,
        unk09C0, unk09C4, unk09C8, unk09CC;
    int unk09D0, unk09D4, unk09D8, unk09DC, unk09E0, unk09E4, unk09E8, unk09EC, unk09F0, unk09F4, unk09F8, unk09FC,
        unk0A00, unk0A04, unk0A08, unk0A0C;
    int unk0A10, unk0A14, unk0A18, unk0A1C, unk0A20, unk0A24, unk0A28, unk0A2C, unk0A30, unk0A34, unk0A38, unk0A3C,
        unk0A40, unk0A44, unk0A48, unk0A4C;
    int unk0A50, unk0A54, unk0A58, unk0A5C, unk0A60, unk0A64, unk0A68, unk0A6C, unk0A70, unk0A74, unk0A78, unk0A7C,
        unk0A80, unk0A84, unk0A88, unk0A8C;
    int unk0A90, unk0A94, unk0A98, unk0A9C, unk0AA0, unk0AA4, unk0AA8, unk0AAC, unk0AB0, unk0AB4, unk0AB8, unk0ABC,
        unk0AC0, unk0AC4, unk0AC8, unk0ACC;
    int unk0AD0, unk0AD4, unk0AD8, unk0ADC, unk0AE0, unk0AE4, unk0AE8, unk0AEC, unk0AF0, unk0AF4, unk0AF8, unk0AFC,
        unk0B00, unk0B04, unk0B08, unk0B0C;
    int unk0B10, unk0B14, unk0B18, unk0B1C, unk0B20, unk0B24, unk0B28, unk0B2C, unk0B30, unk0B34, unk0B38, unk0B3C,
        unk0B40, unk0B44, unk0B48, unk0B4C;
    int unk0B50, unk0B54, unk0B58, unk0B5C, unk0B60, unk0B64, unk0B68, unk0B6C, unk0B70, unk0B74, unk0B78, unk0B7C,
        unk0B80, unk0B84, unk0B88, unk0B8C;
    int unk0B90, unk0B94, unk0B98, unk0B9C, unk0BA0, unk0BA4, unk0BA8, unk0BAC, unk0BB0, unk0BB4, unk0BB8, unk0BBC,
        unk0BC0, unk0BC4, unk0BC8, unk0BCC;
    int unk0BD0, unk0BD4, unk0BD8, unk0BDC, unk0BE0, unk0BE4, unk0BE8, unk0BEC, unk0BF0, unk0BF4, unk0BF8, unk0BFC,
        unk0C00, unk0C04, unk0C08, unk0C0C;
    int unk0C10, unk0C14, unk0C18, unk0C1C, unk0C20, unk0C24, unk0C28, unk0C2C, unk0C30, unk0C34, unk0C38, unk0C3C,
        unk0C40, unk0C44, unk0C48, unk0C4C;
    int unk0C50, unk0C54, unk0C58, unk0C5C, unk0C60, unk0C64, unk0C68, unk0C6C, unk0C70, unk0C74, unk0C78, unk0C7C,
        unk0C80, unk0C84, unk0C88, unk0C8C;
    int unk0C90, unk0C94, unk0C98, unk0C9C, unk0CA0, unk0CA4, unk0CA8, unk0CAC, unk0CB0, unk0CB4, unk0CB8, unk0CBC,
        unk0CC0, unk0CC4, unk0CC8, unk0CCC;
    int unk0CD0, unk0CD4, unk0CD8, unk0CDC, unk0CE0, unk0CE4, unk0CE8, unk0CEC, unk0CF0, unk0CF4, unk0CF8, unk0CFC,
        unk0D00, unk0D04, unk0D08, unk0D0C;
    int unk0D10, unk0D14, unk0D18, unk0D1C, unk0D20, unk0D24, unk0D28, unk0D2C, unk0D30, unk0D34, unk0D38, unk0D3C,
        unk0D40, unk0D44, unk0D48, unk0D4C;
    int unk0D50, unk0D54, unk0D58, unk0D5C, unk0D60, unk0D64, unk0D68, unk0D6C, unk0D70, unk0D74, unk0D78, unk0D7C,
        unk0D80, unk0D84, unk0D88, unk0D8C;
    int unk0D90, unk0D94, unk0D98, unk0D9C, unk0DA0, unk0DA4, unk0DA8, unk0DAC, unk0DB0, unk0DB4, unk0DB8, unk0DBC,
        unk0DC0, unk0DC4, unk0DC8, unk0DCC;
    int unk0DD0, unk0DD4, unk0DD8, unk0DDC, unk0DE0, unk0DE4, unk0DE8, unk0DEC, unk0DF0, unk0DF4, unk0DF8, unk0DFC,
        unk0E00, unk0E04, unk0E08, unk0E0C;
    int unk0E10, unk0E14, unk0E18, unk0E1C, unk0E20, unk0E24, unk0E28, unk0E2C, unk0E30, unk0E34, unk0E38, unk0E3C,
        unk0E40, unk0E44, unk0E48, unk0E4C;
    int unk0E50, unk0E54, unk0E58, unk0E5C, unk0E60, unk0E64, unk0E68, unk0E6C, unk0E70, unk0E74, unk0E78, unk0E7C,
        unk0E80, unk0E84, unk0E88, unk0E8C;
    int unk0E90, unk0E94, unk0E98, unk0E9C, unk0EA0, unk0EA4, unk0EA8, unk0EAC, unk0EB0, unk0EB4, unk0EB8, unk0EBC,
        unk0EC0, unk0EC4, unk0EC8, unk0ECC;
    int unk0ED0, unk0ED4, unk0ED8, unk0EDC, unk0EE0, unk0EE4, unk0EE8, unk0EEC, unk0EF0, unk0EF4, unk0EF8, unk0EFC,
        unk0F00, unk0F04, unk0F08, unk0F0C;
    int unk0F10, unk0F14, unk0F18, unk0F1C, unk0F20, unk0F24, unk0F28, unk0F2C, unk0F30, unk0F34, unk0F38, unk0F3C,
        unk0F40, unk0F44, unk0F48, unk0F4C;
    int unk0F50, unk0F54, unk0F58, unk0F5C, unk0F60, unk0F64, unk0F68, unk0F6C, unk0F70, unk0F74, unk0F78, unk0F7C,
        unk0F80, unk0F84, unk0F88, unk0F8C;
    int unk0F90, unk0F94, unk0F98, unk0F9C, unk0FA0, unk0FA4, unk0FA8, unk0FAC, unk0FB0, unk0FB4, unk0FB8, unk0FBC,
        unk0FC0, unk0FC4, unk0FC8, unk0FCC;
    int unk0FD0, unk0FD4, unk0FD8, unk0FDC, unk0FE0, unk0FE4, unk0FE8, unk0FEC, unk0FF0, unk0FF4, unk0FF8, unk0FFC,
        unk1000, unk1004, unk1008, unk100C;
    int unk1010, unk1014, unk1018, unk101C, unk1020, unk1024, unk1028, unk102C, unk1030, unk1034, unk1038, unk103C,
        unk1040, unk1044, unk1048, unk104C;
    int unk1050, unk1054, unk1058, unk105C, unk1060, unk1064, unk1068, unk106C, unk1070, unk1074, unk1078, unk107C,
        unk1080, unk1084, unk1088, unk108C;
    int unk1090, unk1094, unk1098, unk109C, unk10A0, unk10A4, unk10A8, unk10AC, unk10B0, unk10B4, unk10B8, unk10BC,
        unk10C0, unk10C4, unk10C8, unk10CC;
    int unk10D0, unk10D4, unk10D8, unk10DC, unk10E0, unk10E4, unk10E8, unk10EC, unk10F0, unk10F4, unk10F8, unk10FC,
        unk1100, unk1104, unk1108, unk110C;
    int unk1110, unk1114, unk1118, unk111C, unk1120, unk1124, unk1128, unk112C, unk1130, unk1134, unk1138, unk113C,
        unk1140, unk1144, unk1148, unk114C;
    int unk1150, unk1154, unk1158, unk115C, unk1160, unk1164, unk1168, unk116C, unk1170, unk1174, unk1178, unk117C,
        unk1180, unk1184, unk1188, unk118C;
    int unk1190, unk1194, unk1198, unk119C, unk11A0, unk11A4, unk11A8, unk11AC, unk11B0, unk11B4, unk11B8, unk11BC,
        unk11C0, unk11C4, unk11C8, unk11CC;
    int unk11D0, unk11D4, unk11D8, unk11DC, unk11E0, unk11E4, unk11E8, unk11EC, unk11F0, unk11F4, unk11F8, unk11FC,
        unk1200, unk1204, unk1208, unk120C;
    int unk1210, unk1214, unk1218, unk121C, unk1220, unk1224, unk1228, unk122C, unk1230, unk1234, unk1238, unk123C,
        unk1240, unk1244, unk1248, unk124C;
    int unk1250, unk1254, unk1258, unk125C, unk1260, unk1264, unk1268, unk126C, unk1270, unk1274, unk1278, unk127C,
        unk1280, unk1284, unk1288, unk128C;
    int unk1290, unk1294, unk1298, unk129C, unk12A0, unk12A4, unk12A8, unk12AC, unk12B0, unk12B4, unk12B8, unk12BC,
        unk12C0, unk12C4, unk12C8, unk12CC;
    int unk12D0, unk12D4, unk12D8, unk12DC, unk12E0, unk12E4, unk12E8, unk12EC, unk12F0, unk12F4, unk12F8, unk12FC,
        unk1300, unk1304, unk1308, unk130C;
    int unk1310, unk1314, unk1318, unk131C, unk1320, unk1324, unk1328, unk132C, unk1330, unk1334, unk1338, unk133C,
        unk1340, unk1344, unk1348, unk134C;
    int unk1350, unk1354, unk1358, unk135C, unk1360, unk1364, unk1368, unk136C, unk1370, unk1374, unk1378, unk137C,
        unk1380, unk1384, unk1388, unk138C;
    int unk1390, unk1394, unk1398, unk139C, unk13A0, unk13A4, unk13A8, unk13AC, unk13B0, unk13B4, unk13B8, unk13BC,
        unk13C0, unk13C4, unk13C8, unk13CC;
    int unk13D0, unk13D4, unk13D8, unk13DC, unk13E0, unk13E4, unk13E8, unk13EC, unk13F0, unk13F4, unk13F8, unk13FC,
        unk1400, unk1404, unk1408, unk140C;
    int unk1410, unk1414, unk1418, unk141C, unk1420, unk1424, unk1428, unk142C, unk1430, unk1434, unk1438, unk143C,
        unk1440, unk1444, unk1448, unk144C;
    int unk1450, unk1454, unk1458, unk145C, unk1460, unk1464, unk1468, unk146C, unk1470, unk1474, unk1478, unk147C,
        unk1480, unk1484, unk1488, unk148C;
    int unk1490, unk1494, unk1498, unk149C, unk14A0, unk14A4, unk14A8, unk14AC, unk14B0, unk14B4, unk14B8, unk14BC,
        unk14C0, unk14C4, unk14C8, unk14CC;
    int unk14D0, unk14D4, unk14D8, unk14DC, unk14E0, unk14E4, unk14E8, unk14EC, unk14F0, unk14F4, unk14F8, unk14FC,
        unk1500, unk1504, unk1508, unk150C;
    int unk1510, unk1514, unk1518, unk151C, unk1520, unk1524, unk1528, unk152C, unk1530, unk1534, unk1538, unk153C,
        unk1540, unk1544, unk1548, unk154C;
    int unk1550, unk1554, unk1558, unk155C, unk1560, unk1564, unk1568, unk156C, unk1570, unk1574, unk1578, unk157C,
        unk1580, unk1584, unk1588, unk158C;
    int unk1590, unk1594, unk1598, unk159C, unk15A0, unk15A4, unk15A8, unk15AC, unk15B0, unk15B4, unk15B8, unk15BC,
        unk15C0, unk15C4, unk15C8, unk15CC;
    int unk15D0, unk15D4, unk15D8, unk15DC, unk15E0, unk15E4, unk15E8, unk15EC, unk15F0, unk15F4, unk15F8, unk15FC,
        unk1600, unk1604, unk1608, unk160C;
    int unk1610, unk1614, unk1618, unk161C, unk1620, unk1624, unk1628, unk162C, unk1630, unk1634, unk1638, unk163C,
        unk1640, unk1644, unk1648, unk164C;
    int unk1650, unk1654, unk1658, unk165C, unk1660, unk1664, unk1668, unk166C, unk1670, unk1674, unk1678, unk167C,
        unk1680, unk1684, unk1688, unk168C;
    int unk1690, unk1694, unk1698, unk169C, unk16A0, unk16A4, unk16A8, unk16AC, unk16B0, unk16B4, unk16B8, unk16BC,
        unk16C0, unk16C4, unk16C8, unk16CC;
    int unk16D0, unk16D4, unk16D8, unk16DC, unk16E0, unk16E4, unk16E8, unk16EC, unk16F0, unk16F4, unk16F8, unk16FC,
        unk1700, unk1704, unk1708, unk170C;
    int unk1710, unk1714, unk1718, unk171C, unk1720, unk1724, unk1728, unk172C, unk1730, unk1734, unk1738, unk173C,
        unk1740, unk1744, unk1748, unk174C;
    int unk1750, unk1754, unk1758, unk175C, unk1760, unk1764, unk1768, unk176C, unk1770, unk1774, unk1778, unk177C,
        unk1780, unk1784, unk1788, unk178C;
    int unk1790, unk1794, unk1798, unk179C, unk17A0, unk17A4, unk17A8, unk17AC, unk17B0, unk17B4, unk17B8, unk17BC,
        unk17C0, unk17C4, unk17C8, unk17CC;
    int unk17D0, unk17D4, unk17D8, unk17DC, unk17E0, unk17E4, unk17E8, unk17EC, unk17F0, unk17F4, unk17F8, unk17FC,
        unk1800, unk1804, unk1808, unk180C;
    int unk1810, unk1814, unk1818, unk181C, unk1820, unk1824, unk1828, unk182C, unk1830, unk1834, unk1838, unk183C,
        unk1840, unk1844, unk1848, unk184C;
    int unk1850, unk1854, unk1858, unk185C, unk1860, unk1864, unk1868, unk186C, unk1870, unk1874, unk1878, unk187C,
        unk1880, unk1884, unk1888, unk188C;
    int unk1890, unk1894, unk1898, unk189C, unk18A0, unk18A4, unk18A8, unk18AC, unk18B0, unk18B4, unk18B8, unk18BC,
        unk18C0, unk18C4, unk18C8, unk18CC;
    int unk18D0, unk18D4, unk18D8, unk18DC, unk18E0, unk18E4, unk18E8, unk18EC, unk18F0, unk18F4, unk18F8, unk18FC,
        unk1900, unk1904, unk1908, unk190C;
    int unk1910, unk1914, unk1918, unk191C, unk1920, unk1924, unk1928, unk192C, unk1930, unk1934, unk1938, unk193C,
        unk1940, unk1944, unk1948, unk194C;
    int unk1950, unk1954, unk1958, unk195C, unk1960, unk1964, unk1968, unk196C, unk1970, unk1974, unk1978, unk197C,
        unk1980, unk1984, unk1988, unk198C;
    int unk1990, unk1994, unk1998, unk199C, unk19A0, unk19A4, unk19A8, unk19AC, unk19B0, unk19B4, unk19B8, unk19BC,
        unk19C0, unk19C4, unk19C8, unk19CC;
    int unk19D0, unk19D4, unk19D8, unk19DC, unk19E0, unk19E4, unk19E8, unk19EC, unk19F0, unk19F4, unk19F8, unk19FC,
        unk1A00, unk1A04, unk1A08, unk1A0C;
    int unk1A10, unk1A14, unk1A18, unk1A1C, unk1A20, unk1A24, unk1A28, unk1A2C, unk1A30, unk1A34, unk1A38, unk1A3C,
        unk1A40, unk1A44, unk1A48, unk1A4C;
    int unk1A50, unk1A54, unk1A58, unk1A5C, unk1A60, unk1A64, unk1A68, unk1A6C, unk1A70, unk1A74, unk1A78, unk1A7C,
        unk1A80, unk1A84, unk1A88, unk1A8C;
    int unk1A90, unk1A94, unk1A98, unk1A9C, unk1AA0, unk1AA4, unk1AA8, unk1AAC, unk1AB0, unk1AB4, unk1AB8, unk1ABC,
        unk1AC0, unk1AC4, unk1AC8, unk1ACC;
    int unk1AD0, unk1AD4, unk1AD8, unk1ADC, unk1AE0, unk1AE4, unk1AE8, unk1AEC, unk1AF0, unk1AF4, unk1AF8, unk1AFC,
        unk1B00, unk1B04, unk1B08, unk1B0C;
    int unk1B10, unk1B14, unk1B18, unk1B1C, unk1B20, unk1B24, unk1B28, unk1B2C, unk1B30, unk1B34, unk1B38, unk1B3C,
        unk1B40, unk1B44, unk1B48, unk1B4C;
    int unk1B50, unk1B54, unk1B58, unk1B5C, unk1B60, unk1B64, unk1B68, unk1B6C, unk1B70, unk1B74, unk1B78, unk1B7C,
        unk1B80, unk1B84, unk1B88, unk1B8C;
    int unk1B90, unk1B94, unk1B98, unk1B9C, unk1BA0, unk1BA4, unk1BA8, unk1BAC, unk1BB0, unk1BB4, unk1BB8, unk1BBC,
        unk1BC0, unk1BC4, unk1BC8, unk1BCC;
    int unk1BD0, unk1BD4, unk1BD8, unk1BDC, unk1BE0, unk1BE4, unk1BE8, unk1BEC, unk1BF0, unk1BF4, unk1BF8, unk1BFC,
        unk1C00, unk1C04, unk1C08, unk1C0C;
    int unk1C10, unk1C14, unk1C18, unk1C1C, unk1C20, unk1C24, unk1C28, unk1C2C, unk1C30, unk1C34, unk1C38, unk1C3C,
        unk1C40, unk1C44, unk1C48, unk1C4C;
    int unk1C50, unk1C54, unk1C58, unk1C5C, unk1C60, unk1C64, unk1C68, unk1C6C, unk1C70, unk1C74, unk1C78, unk1C7C,
        unk1C80, unk1C84, unk1C88, unk1C8C;
    int unk1C90, unk1C94, unk1C98, unk1C9C, unk1CA0, unk1CA4, unk1CA8, unk1CAC, unk1CB0, unk1CB4, unk1CB8, unk1CBC,
        unk1CC0, unk1CC4, unk1CC8, unk1CCC;
    int unk1CD0, unk1CD4, unk1CD8, unk1CDC, unk1CE0, unk1CE4, unk1CE8, unk1CEC, unk1CF0, unk1CF4, unk1CF8, unk1CFC,
        unk1D00, unk1D04, unk1D08, unk1D0C;
    int unk1D10, unk1D14, unk1D18, unk1D1C, unk1D20, unk1D24, unk1D28, unk1D2C, unk1D30, unk1D34, unk1D38, unk1D3C,
        unk1D40, unk1D44, unk1D48, unk1D4C;
    int unk1D50, unk1D54, unk1D58, unk1D5C, unk1D60, unk1D64, unk1D68, unk1D6C, unk1D70, unk1D74, unk1D78, unk1D7C,
        unk1D80, unk1D84, unk1D88, unk1D8C;
    int unk1D90, unk1D94, unk1D98, unk1D9C, unk1DA0, unk1DA4, unk1DA8, unk1DAC, unk1DB0, unk1DB4, unk1DB8, unk1DBC,
        unk1DC0, unk1DC4, unk1DC8, unk1DCC;
    int unk1DD0, unk1DD4, unk1DD8, unk1DDC, unk1DE0, unk1DE4, unk1DE8, unk1DEC, unk1DF0, unk1DF4, unk1DF8, unk1DFC,
        unk1E00, unk1E04, unk1E08, unk1E0C;
    int unk1E10, unk1E14, unk1E18, unk1E1C, unk1E20, unk1E24, unk1E28, unk1E2C, unk1E30, unk1E34, unk1E38, unk1E3C,
        unk1E40, unk1E44, unk1E48, unk1E4C;
    int unk1E50, unk1E54, unk1E58, unk1E5C, unk1E60, unk1E64, unk1E68, unk1E6C, unk1E70, unk1E74, unk1E78, unk1E7C,
        unk1E80, unk1E84, unk1E88, unk1E8C;
    int unk1E90, unk1E94, unk1E98, unk1E9C, unk1EA0, unk1EA4, unk1EA8, unk1EAC, unk1EB0, unk1EB4, unk1EB8, unk1EBC,
        unk1EC0, unk1EC4, unk1EC8, unk1ECC;
    int unk1ED0, unk1ED4, unk1ED8, unk1EDC, unk1EE0, unk1EE4, unk1EE8, unk1EEC, unk1EF0, unk1EF4, unk1EF8, unk1EFC,
        unk1F00, unk1F04, unk1F08, unk1F0C;
    int unk1F10, unk1F14, unk1F18, unk1F1C, unk1F20, unk1F24, unk1F28, unk1F2C, unk1F30, unk1F34, unk1F38, unk1F3C,
        unk1F40, unk1F44, unk1F48, unk1F4C;
    int unk1F50, unk1F54, unk1F58, unk1F5C, unk1F60, unk1F64, unk1F68, unk1F6C, unk1F70, unk1F74, unk1F78, unk1F7C,
        unk1F80, unk1F84, unk1F88, unk1F8C;
    int unk1F90, unk1F94, unk1F98, unk1F9C, unk1FA0, unk1FA4, unk1FA8, unk1FAC, unk1FB0, unk1FB4, unk1FB8, unk1FBC,
        unk1FC0, unk1FC4, unk1FC8, unk1FCC;
    int unk1FD0, unk1FD4, unk1FD8, unk1FDC, unk1FE0, unk1FE4, unk1FE8, unk1FEC, unk1FF0, unk1FF4, unk1FF8, unk1FFC,
        unk2000, unk2004, unk2008, unk200C;
    int unk2010, unk2014, unk2018, unk201C, unk2020, unk2024, unk2028, unk202C, unk2030, unk2034, unk2038, unk203C,
        unk2040, unk2044, unk2048, unk204C;
    int unk2050, unk2054, unk2058, unk205C, unk2060;
    Member_6f33b0_2064 m_2064;
    int unk2068, unk206C, unk2070, unk2074, unk2078, unk207C, unk2080, unk2084, unk2088, unk208C, unk2090, unk2094,
        unk2098, unk209C, unk20A0;
    Member_6f33b0_20a4 m_20a4;

    FUN_006f33b0_cls();
};
extern unsigned int DAT_0106d90c;
struct FUN_006f4320
{
    unsigned int m_pTreeNode;
    unsigned int m_pRayCursor;
    unsigned int m_uiItemCount;
    unsigned int m_uiFirstValue;
    FUN_006f4320();
    ~FUN_006f4320();
};
struct FUN_006b3de0
{
    unsigned int m_entries[2040];
    FUN_006b3de0();
    ~FUN_006b3de0();
};
struct FUN_006b9470
{
    unsigned int m_auiBitFieldWords[21];
    FUN_006b9470();
};
struct FUN_006f3bd0
{
    unsigned int* m_ppVirtualMethodTable;
    FUN_006f4320 m_pStreamAllocator;
    FUN_006b3de0 m_entries;
    FUN_006b9470 m_lookup;
    unsigned int m_uiItemCount;
    unsigned int m_pRayCursor;
    unsigned int m_uiEdgeIndex;
    unsigned char m_sState;
    FUN_006f3bd0();
};
struct S_006f3d00_Vec3
{
    float x, y, z;
};
struct S_006f3d00_Node
{
    int unk0;
    float unk4;
    S_006f3d00_Vec3 unk8;
};
struct S_006f3d00_List
{
    int unk0;
    void InsertNode(S_006f3d00_Node* node);
};
struct S_006f3d00_Obj
{
    int unk0, unk4, unk8, unkc, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134,
        unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170, unk174,
        unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4,
        unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc, unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4,
        unk1f8, unk1fc;
    int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c, unk220, unk224, unk228, unk22c, unk230, unk234,
        unk238, unk23c;
    int unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c, unk260, unk264, unk268, unk26c, unk270, unk274,
        unk278, unk27c;
    int unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c, unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, unk2b4,
        unk2b8, unk2bc;
    int unk2c0, unk2c4, unk2c8, unk2cc, unk2d0, unk2d4, unk2d8, unk2dc, unk2e0, unk2e4, unk2e8, unk2ec, unk2f0, unk2f4,
        unk2f8, unk2fc;
    int unk300, unk304, unk308, unk30c, unk310, unk314, unk318, unk31c, unk320, unk324, unk328, unk32c, unk330, unk334,
        unk338, unk33c;
    int unk340, unk344, unk348, unk34c, unk350, unk354, unk358, unk35c, unk360, unk364, unk368, unk36c, unk370, unk374,
        unk378, unk37c;
    int unk380, unk384, unk388, unk38c, unk390, unk394, unk398, unk39c, unk3a0, unk3a4, unk3a8, unk3ac, unk3b0, unk3b4,
        unk3b8, unk3bc;
    int unk3c0, unk3c4, unk3c8, unk3cc, unk3d0, unk3d4, unk3d8, unk3dc, unk3e0, unk3e4, unk3e8, unk3ec, unk3f0, unk3f4,
        unk3f8, unk3fc;
    int unk400, unk404, unk408, unk40c, unk410, unk414, unk418, unk41c, unk420, unk424, unk428, unk42c, unk430, unk434,
        unk438, unk43c;
    int unk440, unk444, unk448, unk44c, unk450, unk454, unk458, unk45c, unk460, unk464, unk468, unk46c, unk470, unk474,
        unk478, unk47c;
    int unk480, unk484, unk488, unk48c, unk490, unk494, unk498, unk49c, unk4a0, unk4a4, unk4a8, unk4ac, unk4b0, unk4b4,
        unk4b8, unk4bc;
    int unk4c0, unk4c4, unk4c8, unk4cc, unk4d0, unk4d4, unk4d8, unk4dc, unk4e0, unk4e4, unk4e8, unk4ec, unk4f0, unk4f4,
        unk4f8, unk4fc;
    int unk500, unk504, unk508, unk50c, unk510, unk514, unk518, unk51c, unk520, unk524, unk528, unk52c, unk530, unk534,
        unk538, unk53c;
    int unk540, unk544, unk548, unk54c, unk550, unk554, unk558, unk55c, unk560, unk564, unk568, unk56c, unk570, unk574,
        unk578, unk57c;
    int unk580, unk584, unk588, unk58c, unk590, unk594, unk598, unk59c, unk5a0, unk5a4, unk5a8, unk5ac, unk5b0, unk5b4,
        unk5b8, unk5bc;
    int unk5c0, unk5c4, unk5c8, unk5cc, unk5d0, unk5d4, unk5d8, unk5dc, unk5e0, unk5e4, unk5e8, unk5ec, unk5f0, unk5f4,
        unk5f8, unk5fc;
    int unk600, unk604, unk608, unk60c, unk610, unk614, unk618, unk61c, unk620, unk624, unk628, unk62c, unk630, unk634,
        unk638, unk63c;
    int unk640, unk644, unk648, unk64c, unk650, unk654, unk658, unk65c, unk660, unk664, unk668, unk66c, unk670, unk674,
        unk678, unk67c;
    int unk680, unk684, unk688, unk68c, unk690, unk694, unk698, unk69c, unk6a0, unk6a4, unk6a8, unk6ac, unk6b0, unk6b4,
        unk6b8, unk6bc;
    int unk6c0, unk6c4, unk6c8, unk6cc, unk6d0, unk6d4, unk6d8, unk6dc, unk6e0, unk6e4, unk6e8, unk6ec, unk6f0, unk6f4,
        unk6f8, unk6fc;
    int unk700, unk704, unk708, unk70c, unk710, unk714, unk718, unk71c, unk720, unk724, unk728, unk72c, unk730, unk734,
        unk738, unk73c;
    int unk740, unk744, unk748, unk74c, unk750, unk754, unk758, unk75c, unk760, unk764, unk768, unk76c, unk770, unk774,
        unk778, unk77c;
    int unk780, unk784, unk788, unk78c, unk790, unk794, unk798, unk79c, unk7a0, unk7a4, unk7a8, unk7ac, unk7b0, unk7b4,
        unk7b8, unk7bc;
    int unk7c0, unk7c4, unk7c8, unk7cc, unk7d0, unk7d4, unk7d8, unk7dc, unk7e0, unk7e4, unk7e8, unk7ec, unk7f0, unk7f4,
        unk7f8, unk7fc;
    int unk800, unk804, unk808, unk80c, unk810, unk814, unk818, unk81c, unk820, unk824, unk828, unk82c, unk830, unk834,
        unk838, unk83c;
    int unk840, unk844, unk848, unk84c, unk850, unk854, unk858, unk85c, unk860, unk864, unk868, unk86c, unk870, unk874,
        unk878, unk87c;
    int unk880, unk884, unk888, unk88c, unk890, unk894, unk898, unk89c, unk8a0, unk8a4, unk8a8, unk8ac, unk8b0, unk8b4,
        unk8b8, unk8bc;
    int unk8c0, unk8c4, unk8c8, unk8cc, unk8d0, unk8d4, unk8d8, unk8dc, unk8e0, unk8e4, unk8e8, unk8ec, unk8f0, unk8f4,
        unk8f8, unk8fc;
    int unk900, unk904, unk908, unk90c, unk910, unk914, unk918, unk91c, unk920, unk924, unk928, unk92c, unk930, unk934,
        unk938, unk93c;
    int unk940, unk944, unk948, unk94c, unk950, unk954, unk958, unk95c, unk960, unk964, unk968, unk96c, unk970, unk974,
        unk978, unk97c;
    int unk980, unk984, unk988, unk98c, unk990, unk994, unk998, unk99c, unk9a0, unk9a4, unk9a8, unk9ac, unk9b0, unk9b4,
        unk9b8, unk9bc;
    int unk9c0, unk9c4, unk9c8, unk9cc, unk9d0, unk9d4, unk9d8, unk9dc, unk9e0, unk9e4, unk9e8, unk9ec, unk9f0, unk9f4,
        unk9f8, unk9fc;
    int unka00, unka04, unka08, unka0c, unka10, unka14, unka18, unka1c, unka20, unka24, unka28, unka2c, unka30, unka34,
        unka38, unka3c;
    int unka40, unka44, unka48, unka4c, unka50, unka54, unka58, unka5c, unka60, unka64, unka68, unka6c, unka70, unka74,
        unka78, unka7c;
    int unka80, unka84, unka88, unka8c, unka90, unka94, unka98, unka9c, unkaa0, unkaa4, unkaa8, unkaac, unkab0, unkab4,
        unkab8, unkabc;
    int unkac0, unkac4, unkac8, unkacc, unkad0, unkad4, unkad8, unkadc, unkae0, unkae4, unkae8, unkaec, unkaf0, unkaf4,
        unkaf8, unkafc;
    int unkb00, unkb04, unkb08, unkb0c, unkb10, unkb14, unkb18, unkb1c, unkb20, unkb24, unkb28, unkb2c, unkb30, unkb34,
        unkb38, unkb3c;
    int unkb40, unkb44, unkb48, unkb4c, unkb50, unkb54, unkb58, unkb5c, unkb60, unkb64, unkb68, unkb6c, unkb70, unkb74,
        unkb78, unkb7c;
    int unkb80, unkb84, unkb88, unkb8c, unkb90, unkb94, unkb98, unkb9c, unkba0, unkba4, unkba8, unkbac, unkbb0, unkbb4,
        unkbb8, unkbbc;
    int unkbc0, unkbc4, unkbc8, unkbcc, unkbd0, unkbd4, unkbd8, unkbdc, unkbe0, unkbe4, unkbe8, unkbec, unkbf0, unkbf4,
        unkbf8, unkbfc;
    int unkc00, unkc04, unkc08, unkc0c, unkc10, unkc14, unkc18, unkc1c, unkc20, unkc24, unkc28, unkc2c, unkc30, unkc34,
        unkc38, unkc3c;
    int unkc40, unkc44, unkc48, unkc4c, unkc50, unkc54, unkc58, unkc5c, unkc60, unkc64, unkc68, unkc6c, unkc70, unkc74,
        unkc78, unkc7c;
    int unkc80, unkc84, unkc88, unkc8c, unkc90, unkc94, unkc98, unkc9c, unkca0, unkca4, unkca8, unkcac, unkcb0, unkcb4,
        unkcb8, unkcbc;
    int unkcc0, unkcc4, unkcc8, unkccc, unkcd0, unkcd4, unkcd8, unkcdc, unkce0, unkce4, unkce8, unkcec, unkcf0, unkcf4,
        unkcf8, unkcfc;
    int unkd00, unkd04, unkd08, unkd0c, unkd10, unkd14, unkd18, unkd1c, unkd20, unkd24, unkd28, unkd2c, unkd30, unkd34,
        unkd38, unkd3c;
    int unkd40, unkd44, unkd48, unkd4c, unkd50, unkd54, unkd58, unkd5c, unkd60, unkd64, unkd68, unkd6c, unkd70, unkd74,
        unkd78, unkd7c;
    int unkd80, unkd84, unkd88, unkd8c, unkd90, unkd94, unkd98, unkd9c, unkda0, unkda4, unkda8, unkdac, unkdb0, unkdb4,
        unkdb8, unkdbc;
    int unkdc0, unkdc4, unkdc8, unkdcc, unkdd0, unkdd4, unkdd8, unkddc, unkde0, unkde4, unkde8, unkdec, unkdf0, unkdf4,
        unkdf8, unkdfc;
    int unke00, unke04, unke08, unke0c, unke10, unke14, unke18, unke1c, unke20, unke24, unke28, unke2c, unke30, unke34,
        unke38, unke3c;
    int unke40, unke44, unke48, unke4c, unke50, unke54, unke58, unke5c, unke60, unke64, unke68, unke6c, unke70, unke74,
        unke78, unke7c;
    int unke80, unke84, unke88, unke8c, unke90, unke94, unke98, unke9c, unkea0, unkea4, unkea8, unkeac, unkeb0, unkeb4,
        unkeb8, unkebc;
    int unkec0, unkec4, unkec8, unkecc, unked0, unked4, unked8, unkedc, unkee0, unkee4, unkee8, unkeec, unkef0, unkef4,
        unkef8, unkefc;
    int unkf00, unkf04, unkf08, unkf0c, unkf10, unkf14, unkf18, unkf1c, unkf20, unkf24, unkf28, unkf2c, unkf30, unkf34,
        unkf38, unkf3c;
    int unkf40, unkf44, unkf48, unkf4c, unkf50, unkf54, unkf58, unkf5c, unkf60, unkf64, unkf68, unkf6c, unkf70, unkf74,
        unkf78, unkf7c;
    int unkf80, unkf84, unkf88, unkf8c, unkf90, unkf94, unkf98, unkf9c, unkfa0, unkfa4, unkfa8, unkfac, unkfb0, unkfb4,
        unkfb8, unkfbc;
    int unkfc0, unkfc4, unkfc8, unkfcc, unkfd0, unkfd4, unkfd8, unkfdc, unkfe0, unkfe4, unkfe8, unkfec, unkff0, unkff4,
        unkff8, unkffc;
    int unk1000, unk1004, unk1008, unk100c, unk1010, unk1014, unk1018, unk101c, unk1020, unk1024, unk1028, unk102c,
        unk1030, unk1034, unk1038, unk103c;
    int unk1040, unk1044, unk1048, unk104c, unk1050, unk1054, unk1058, unk105c, unk1060, unk1064, unk1068, unk106c,
        unk1070, unk1074, unk1078, unk107c;
    int unk1080, unk1084, unk1088, unk108c, unk1090, unk1094, unk1098, unk109c, unk10a0, unk10a4, unk10a8, unk10ac,
        unk10b0, unk10b4, unk10b8, unk10bc;
    int unk10c0, unk10c4, unk10c8, unk10cc, unk10d0, unk10d4, unk10d8, unk10dc, unk10e0, unk10e4, unk10e8, unk10ec,
        unk10f0, unk10f4, unk10f8, unk10fc;
    int unk1100, unk1104, unk1108, unk110c, unk1110, unk1114, unk1118, unk111c, unk1120, unk1124, unk1128, unk112c,
        unk1130, unk1134, unk1138, unk113c;
    int unk1140, unk1144, unk1148, unk114c, unk1150, unk1154, unk1158, unk115c, unk1160, unk1164, unk1168, unk116c,
        unk1170, unk1174, unk1178, unk117c;
    int unk1180, unk1184, unk1188, unk118c, unk1190, unk1194, unk1198, unk119c, unk11a0, unk11a4, unk11a8, unk11ac,
        unk11b0, unk11b4, unk11b8, unk11bc;
    int unk11c0, unk11c4, unk11c8, unk11cc, unk11d0, unk11d4, unk11d8, unk11dc, unk11e0, unk11e4, unk11e8, unk11ec,
        unk11f0, unk11f4, unk11f8, unk11fc;
    int unk1200, unk1204, unk1208, unk120c, unk1210, unk1214, unk1218, unk121c, unk1220, unk1224, unk1228, unk122c,
        unk1230, unk1234, unk1238, unk123c;
    int unk1240, unk1244, unk1248, unk124c, unk1250, unk1254, unk1258, unk125c, unk1260, unk1264, unk1268, unk126c,
        unk1270, unk1274, unk1278, unk127c;
    int unk1280, unk1284, unk1288, unk128c, unk1290, unk1294, unk1298, unk129c, unk12a0, unk12a4, unk12a8, unk12ac,
        unk12b0, unk12b4, unk12b8, unk12bc;
    int unk12c0, unk12c4, unk12c8, unk12cc, unk12d0, unk12d4, unk12d8, unk12dc, unk12e0, unk12e4, unk12e8, unk12ec,
        unk12f0, unk12f4, unk12f8, unk12fc;
    int unk1300, unk1304, unk1308, unk130c, unk1310, unk1314, unk1318, unk131c, unk1320, unk1324, unk1328, unk132c,
        unk1330, unk1334, unk1338, unk133c;
    int unk1340, unk1344, unk1348, unk134c, unk1350, unk1354, unk1358, unk135c, unk1360, unk1364, unk1368, unk136c,
        unk1370, unk1374, unk1378, unk137c;
    int unk1380, unk1384, unk1388, unk138c, unk1390, unk1394, unk1398, unk139c, unk13a0, unk13a4, unk13a8, unk13ac,
        unk13b0, unk13b4, unk13b8, unk13bc;
    int unk13c0, unk13c4, unk13c8, unk13cc, unk13d0, unk13d4, unk13d8, unk13dc, unk13e0, unk13e4, unk13e8, unk13ec,
        unk13f0, unk13f4, unk13f8, unk13fc;
    int unk1400, unk1404, unk1408, unk140c, unk1410, unk1414, unk1418, unk141c, unk1420, unk1424, unk1428, unk142c,
        unk1430, unk1434, unk1438, unk143c;
    int unk1440, unk1444, unk1448, unk144c, unk1450, unk1454, unk1458, unk145c, unk1460, unk1464, unk1468, unk146c,
        unk1470, unk1474, unk1478, unk147c;
    int unk1480, unk1484, unk1488, unk148c, unk1490, unk1494, unk1498, unk149c, unk14a0, unk14a4, unk14a8, unk14ac,
        unk14b0, unk14b4, unk14b8, unk14bc;
    int unk14c0, unk14c4, unk14c8, unk14cc, unk14d0, unk14d4, unk14d8, unk14dc, unk14e0, unk14e4, unk14e8, unk14ec,
        unk14f0, unk14f4, unk14f8, unk14fc;
    int unk1500, unk1504, unk1508, unk150c, unk1510, unk1514, unk1518, unk151c, unk1520, unk1524, unk1528, unk152c,
        unk1530, unk1534, unk1538, unk153c;
    int unk1540, unk1544, unk1548, unk154c, unk1550, unk1554, unk1558, unk155c, unk1560, unk1564, unk1568, unk156c,
        unk1570, unk1574, unk1578, unk157c;
    int unk1580, unk1584, unk1588, unk158c, unk1590, unk1594, unk1598, unk159c, unk15a0, unk15a4, unk15a8, unk15ac,
        unk15b0, unk15b4, unk15b8, unk15bc;
    int unk15c0, unk15c4, unk15c8, unk15cc, unk15d0, unk15d4, unk15d8, unk15dc, unk15e0, unk15e4, unk15e8, unk15ec,
        unk15f0, unk15f4, unk15f8, unk15fc;
    int unk1600, unk1604, unk1608, unk160c, unk1610, unk1614, unk1618, unk161c, unk1620, unk1624, unk1628, unk162c,
        unk1630, unk1634, unk1638, unk163c;
    int unk1640, unk1644, unk1648, unk164c, unk1650, unk1654, unk1658, unk165c, unk1660, unk1664, unk1668, unk166c,
        unk1670, unk1674, unk1678, unk167c;
    int unk1680, unk1684, unk1688, unk168c, unk1690, unk1694, unk1698, unk169c, unk16a0, unk16a4, unk16a8, unk16ac,
        unk16b0, unk16b4, unk16b8, unk16bc;
    int unk16c0, unk16c4, unk16c8, unk16cc, unk16d0, unk16d4, unk16d8, unk16dc, unk16e0, unk16e4, unk16e8, unk16ec,
        unk16f0, unk16f4, unk16f8, unk16fc;
    int unk1700, unk1704, unk1708, unk170c, unk1710, unk1714, unk1718, unk171c, unk1720, unk1724, unk1728, unk172c,
        unk1730, unk1734, unk1738, unk173c;
    int unk1740, unk1744, unk1748, unk174c, unk1750, unk1754, unk1758, unk175c, unk1760, unk1764, unk1768, unk176c,
        unk1770, unk1774, unk1778, unk177c;
    int unk1780, unk1784, unk1788, unk178c, unk1790, unk1794, unk1798, unk179c, unk17a0, unk17a4, unk17a8, unk17ac,
        unk17b0, unk17b4, unk17b8, unk17bc;
    int unk17c0, unk17c4, unk17c8, unk17cc, unk17d0, unk17d4, unk17d8, unk17dc, unk17e0, unk17e4, unk17e8, unk17ec,
        unk17f0, unk17f4, unk17f8, unk17fc;
    int unk1800, unk1804, unk1808, unk180c, unk1810, unk1814, unk1818, unk181c, unk1820, unk1824, unk1828, unk182c,
        unk1830, unk1834, unk1838, unk183c;
    int unk1840, unk1844, unk1848, unk184c, unk1850, unk1854, unk1858, unk185c, unk1860, unk1864, unk1868, unk186c,
        unk1870, unk1874, unk1878, unk187c;
    int unk1880, unk1884, unk1888, unk188c, unk1890, unk1894, unk1898, unk189c, unk18a0, unk18a4, unk18a8, unk18ac,
        unk18b0, unk18b4, unk18b8, unk18bc;
    int unk18c0, unk18c4, unk18c8, unk18cc, unk18d0, unk18d4, unk18d8, unk18dc, unk18e0, unk18e4, unk18e8, unk18ec,
        unk18f0, unk18f4, unk18f8, unk18fc;
    int unk1900, unk1904, unk1908, unk190c, unk1910, unk1914, unk1918, unk191c, unk1920, unk1924, unk1928, unk192c,
        unk1930, unk1934, unk1938, unk193c;
    int unk1940, unk1944, unk1948, unk194c, unk1950, unk1954, unk1958, unk195c, unk1960, unk1964, unk1968, unk196c,
        unk1970, unk1974, unk1978, unk197c;
    int unk1980, unk1984, unk1988, unk198c, unk1990, unk1994, unk1998, unk199c, unk19a0, unk19a4, unk19a8, unk19ac,
        unk19b0, unk19b4, unk19b8, unk19bc;
    int unk19c0, unk19c4, unk19c8, unk19cc, unk19d0, unk19d4, unk19d8, unk19dc, unk19e0, unk19e4, unk19e8, unk19ec,
        unk19f0, unk19f4, unk19f8, unk19fc;
    int unk1a00, unk1a04, unk1a08, unk1a0c, unk1a10, unk1a14, unk1a18, unk1a1c, unk1a20, unk1a24, unk1a28, unk1a2c,
        unk1a30, unk1a34, unk1a38, unk1a3c;
    int unk1a40, unk1a44, unk1a48, unk1a4c, unk1a50, unk1a54, unk1a58, unk1a5c, unk1a60, unk1a64, unk1a68, unk1a6c,
        unk1a70, unk1a74, unk1a78, unk1a7c;
    int unk1a80, unk1a84, unk1a88, unk1a8c, unk1a90, unk1a94, unk1a98, unk1a9c, unk1aa0, unk1aa4, unk1aa8, unk1aac,
        unk1ab0, unk1ab4, unk1ab8, unk1abc;
    int unk1ac0, unk1ac4, unk1ac8, unk1acc, unk1ad0, unk1ad4, unk1ad8, unk1adc, unk1ae0, unk1ae4, unk1ae8, unk1aec,
        unk1af0, unk1af4, unk1af8, unk1afc;
    int unk1b00, unk1b04, unk1b08, unk1b0c, unk1b10, unk1b14, unk1b18, unk1b1c, unk1b20, unk1b24, unk1b28, unk1b2c,
        unk1b30, unk1b34, unk1b38, unk1b3c;
    int unk1b40, unk1b44, unk1b48, unk1b4c, unk1b50, unk1b54, unk1b58, unk1b5c, unk1b60, unk1b64, unk1b68, unk1b6c,
        unk1b70, unk1b74, unk1b78, unk1b7c;
    int unk1b80, unk1b84, unk1b88, unk1b8c, unk1b90, unk1b94, unk1b98, unk1b9c, unk1ba0, unk1ba4, unk1ba8, unk1bac,
        unk1bb0, unk1bb4, unk1bb8, unk1bbc;
    int unk1bc0, unk1bc4, unk1bc8, unk1bcc, unk1bd0, unk1bd4, unk1bd8, unk1bdc, unk1be0, unk1be4, unk1be8, unk1bec,
        unk1bf0, unk1bf4, unk1bf8, unk1bfc;
    int unk1c00, unk1c04, unk1c08, unk1c0c, unk1c10, unk1c14, unk1c18, unk1c1c, unk1c20, unk1c24, unk1c28, unk1c2c,
        unk1c30, unk1c34, unk1c38, unk1c3c;
    int unk1c40, unk1c44, unk1c48, unk1c4c, unk1c50, unk1c54, unk1c58, unk1c5c, unk1c60, unk1c64, unk1c68, unk1c6c,
        unk1c70, unk1c74, unk1c78, unk1c7c;
    int unk1c80, unk1c84, unk1c88, unk1c8c, unk1c90, unk1c94, unk1c98, unk1c9c, unk1ca0, unk1ca4, unk1ca8, unk1cac,
        unk1cb0, unk1cb4, unk1cb8, unk1cbc;
    int unk1cc0, unk1cc4, unk1cc8, unk1ccc, unk1cd0, unk1cd4, unk1cd8, unk1cdc, unk1ce0, unk1ce4, unk1ce8, unk1cec,
        unk1cf0, unk1cf4, unk1cf8, unk1cfc;
    int unk1d00, unk1d04, unk1d08, unk1d0c, unk1d10, unk1d14, unk1d18, unk1d1c, unk1d20, unk1d24, unk1d28, unk1d2c,
        unk1d30, unk1d34, unk1d38, unk1d3c;
    int unk1d40, unk1d44, unk1d48, unk1d4c, unk1d50, unk1d54, unk1d58, unk1d5c, unk1d60, unk1d64, unk1d68, unk1d6c,
        unk1d70, unk1d74, unk1d78, unk1d7c;
    int unk1d80, unk1d84, unk1d88, unk1d8c, unk1d90, unk1d94, unk1d98, unk1d9c, unk1da0, unk1da4, unk1da8, unk1dac,
        unk1db0, unk1db4, unk1db8, unk1dbc;
    int unk1dc0, unk1dc4, unk1dc8, unk1dcc, unk1dd0, unk1dd4, unk1dd8, unk1ddc, unk1de0, unk1de4, unk1de8, unk1dec,
        unk1df0, unk1df4, unk1df8, unk1dfc;
    int unk1e00, unk1e04, unk1e08, unk1e0c, unk1e10, unk1e14, unk1e18, unk1e1c, unk1e20, unk1e24, unk1e28, unk1e2c,
        unk1e30, unk1e34, unk1e38, unk1e3c;
    int unk1e40, unk1e44, unk1e48, unk1e4c, unk1e50, unk1e54, unk1e58, unk1e5c, unk1e60, unk1e64, unk1e68, unk1e6c,
        unk1e70, unk1e74, unk1e78, unk1e7c;
    int unk1e80, unk1e84, unk1e88, unk1e8c, unk1e90, unk1e94, unk1e98, unk1e9c, unk1ea0, unk1ea4, unk1ea8, unk1eac,
        unk1eb0, unk1eb4, unk1eb8, unk1ebc;
    int unk1ec0, unk1ec4, unk1ec8, unk1ecc, unk1ed0, unk1ed4, unk1ed8, unk1edc, unk1ee0, unk1ee4, unk1ee8, unk1eec,
        unk1ef0, unk1ef4, unk1ef8, unk1efc;
    int unk1f00, unk1f04, unk1f08, unk1f0c, unk1f10, unk1f14, unk1f18, unk1f1c, unk1f20, unk1f24, unk1f28, unk1f2c,
        unk1f30, unk1f34, unk1f38, unk1f3c;
    int unk1f40, unk1f44, unk1f48, unk1f4c, unk1f50, unk1f54, unk1f58, unk1f5c, unk1f60, unk1f64, unk1f68, unk1f6c,
        unk1f70, unk1f74, unk1f78, unk1f7c;
    int unk1f80, unk1f84, unk1f88, unk1f8c, unk1f90, unk1f94, unk1f98, unk1f9c, unk1fa0, unk1fa4, unk1fa8, unk1fac,
        unk1fb0, unk1fb4, unk1fb8, unk1fbc;
    int unk1fc0, unk1fc4, unk1fc8, unk1fcc, unk1fd0, unk1fd4, unk1fd8, unk1fdc, unk1fe0, unk1fe4, unk1fe8, unk1fec,
        unk1ff0;
    S_006f3d00_List unk1ff4;
    int unk1ff8, unk1ffc, unk2000, unk2004, unk2008, unk200c, unk2010, unk2014, unk2018, unk201c, unk2020, unk2024,
        unk2028, unk202c, unk2030, unk2034;
    int unk2038, unk203c, unk2040, unk2044, unk2048, unk204c;
    S_006f3d00_Node* unk2050;
    int InsertOrUpdateNode(int key, float f, S_006f3d00_Node** out);
    S_006f3d00_Node* FUN_006f3d00(int key, S_006f3d00_Vec3* pos, float f);
};
class SpawnedArg
{
  public:
    float m_00;
    float GetValue();
};
extern const double DAT_010356e8;
class FUN_006f4790_cls
{
  public:
    float m_00;
    unsigned int GetScaledValue(SpawnedArg* p);
};
struct DTB_Ref
{
    DTB_Ref* Get();
};
struct DTB_Task
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void Start();
};
struct DTB_TaskPtr
{
    DTB_Task* m_pObject;
    DTB_TaskPtr(DTB_Task* p);
    ~DTB_TaskPtr();
    DTB_TaskPtr& operator=(DTB_Task* p);
    operator DTB_Task*() const;
};
struct DTB_List
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DTB_List();
    ~DTB_List();
};
struct DTB_MapA
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DTB_MapA(int size);
    ~DTB_MapA();
};
struct DTB_MapB
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DTB_MapB(int size);
    ~DTB_MapB();
};
struct DTB_Array
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DTB_Array();
    ~DTB_Array();
};
struct DTB_MemContext
{
    int unk00;
    DTB_MemContext(MEM_CONTEXT ctx, bool b, const char* file, int line);
    ~DTB_MemContext();
};
extern int DAT_011d859c;
extern int DAT_011d8598;
struct FUN_006f7540;
struct DTB_LoadTask : DTB_Task
{
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
    DTB_LoadTask(FUN_006f7540* block, DTB_Ref* ref, int x, int y, int lod, int flags);
};
struct FUN_006f7540
{
    DTB_TaskPtr m_spTask;
    DTB_List m_kNode;
    DTB_MapA m_mapA;
    DTB_MapB m_mapB;
    DTB_Array m_ppData;
    DTB_Ref* m_pReference;
    bool m_bLoadComplete;
    bool m_bAttached;
    FUN_006f7540(DTB_Ref* ref, int lod, short x, short y);
};
extern int DAT_011d8598;
struct Sub_b9266A
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    ~Sub_b9266A();
};
struct Sub_b9266B
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    ~Sub_b9266B();
};
struct Sub_b9266C
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    ~Sub_b9266C();
};
struct Sub_b9266D
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    ~Sub_b9266D();
};
struct Helper_b9266
{
    int unk00;
    void Fn(unsigned int aArg1, int aArg2);
};
extern Helper_b9266* DAT_01202d98;
class Base_b9266
{
  public:
    unsigned int m_00;
    ~Base_b9266();
};
class FUN_006f76b0_cls : public Base_b9266
{
  public:
    Sub_b9266A m_04;
    Sub_b9266B m_14;
    Sub_b9266C m_24;
    Sub_b9266D m_34;
    void ClearEntries();
    void FUN_006f7780();
    unsigned int FUN_00559450();
    void FUN_006f74f0(int aFlag);
    ~FUN_006f76b0_cls();
};
struct S_006f9c20_Elem
{
    int unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    void FUN_006f9d90(const S_006f9c20_Elem* a1);
};
struct S_006f9c20
{
    int unk00;
    S_006f9c20_Elem* unk04;
    int GetNextIndex();
    void FUN_006f9ff0(S_006f9c20_Elem* p, int n);
    int AddElement(const S_006f9c20_Elem* a1);
};
void* __cdecl operator new(unsigned int size, void* place);
void __cdecl operator delete(void* p, void* place);
class FNVElem_cls
{
  public:
    FNVElem_cls();
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
};
class FNVOwner_cls
{
  public:
    void ConstructElements(char* base, unsigned int count);
};
extern int DAT_011d8624;
struct Pair3Pool
{
    void Done();
};
struct Mid
{
    Pair3Pool* Pair();
};
struct Sub
{
    Mid* Inner();
};
struct Holder
{
    Sub* Get();
};
struct Item
{
    Sub* Find();
};
struct Cursor
{
    Item** Slot();
    Cursor* Next();
};
void __cdecl FUN_006fa860();
struct MenuValueTarget
{
    void Assign(const void* value);
};
struct MenuValueSource : TargetObject
{
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int value48;

    void AssignValue(MenuValueTarget* target);
};
extern unsigned char g_fnvFlag006fe540;
unsigned char FUN_006fe540();
// Whether a position still falls inside this area's influence: full areas never accept,
// forced areas always do, otherwise compare the falloff value at the point to the threshold.
class FE550Point2
{
  public:
    float x;
    float y;
    FE550Point2(float fX, float fY);
};
struct FE550Point3
{
    float x;
    float y;
    float z;
};
class FE550List
{
  public:
    unsigned int GetCount();
};
class FE550Area
{
  public:
    FE550List* m_pkList;
    unsigned int m_uiCount;
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
    float m_fCenterX;
    float m_fCenterY;
    int unk3C;
    int unk40;
    float m_fThreshold;

    bool IsForced();
    float GetFalloff(FE550Point2 kTargetCenter, float fRadius, FE550Point2 kTestPoint);
    bool FUN_006fe550(const FE550Point3* pkPos);
};
struct Vec2
{
    float x;
    float y;
    Vec2(float px, float py);
    void Dummy();
};
struct GameSettingRef
{
    float* GetFloat();
};
extern "C" double DAT_01017a10;
extern GameSettingRef DAT_011d877c;
struct FUN_006fe620_cls
{
    int unk00;
    unsigned int m_04;
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
    float m_34;
    float m_38;

    float Blend(Vec2 b, float f, Vec2 a);
    bool FUN_006fe620(Vec2* p);
};
struct S_006fe6d0_Vec2
{
    float x;
    float y;
    S_006fe6d0_Vec2(float ax, float ay);
};
struct S_006fe6d0_Gl
{
    float* FUN_00403e20();
};
extern S_006fe6d0_Gl DAT_011d8724;
extern double DAT_01017a10;
struct S_006fe6d0
{
    int unk0;
    unsigned int unk4;
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
    float unk34;
    float unk38;
    float ComputeDistanceSquaredToRect(S_006fe6d0_Vec2 a, float b, S_006fe6d0_Vec2 c);
    bool FUN_006fe6d0(const S_006fe6d0_Vec2* p);
};
struct FUN_00452dc0
{
    float x, y;
    FUN_00452dc0(float a, float b);
};
struct S_006fe780_Global
{
    float* __thiscall FUN_00403e20();
};
extern S_006fe780_Global DAT_011d8788;
extern double DAT_01017a10;
struct S_006fe780_Foo
{
    int unk00;
    unsigned int unk04;
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
    float unk34;
    float unk38;
    float __thiscall ComputeDistanceSquaredToRect(FUN_00452dc0 a, float t, FUN_00452dc0 b);
    bool __thiscall FUN_006fe780(const FUN_00452dc0* p);
};
struct FnvVec2
{
    float x;
    float y;
};
struct FnvPt2
{
    float x;
    float y;
    FnvPt2(float, float);
    void* __thiscall Subtract(FnvVec2* out, FnvPt2& v);
};
float __cdecl ConvertDoubleResult(float);
struct FnvOwner
{
    void* m_10;
    float __thiscall ComputeDistanceSquaredToRect(FnvPt2 s, float a, float b, float c);
};
struct FUN_00974d90_Class
{
    bool __thiscall IsUnk28Set();
    void __thiscall SetNodeFloat(float value);
};
struct FUN_006fea70_Class
{
    void* m_00;
    int m_04;
    int m_08;
    int m_0c;
    FUN_00974d90_Class* m_10;
    int m_14;
    int m_18;
    int m_1c;

    FUN_006fea70_Class* m_20[4];

    unsigned char m_30;
    unsigned char m_31;
    unsigned char m_32;
    unsigned char m_33;
    unsigned char m_34;
    unsigned char m_35;
    unsigned char m_36;
    unsigned char m_37;
    unsigned char m_38;
    unsigned char m_39;
    unsigned char m_3a;
    unsigned char m_3b;
    unsigned char m_3c;
    unsigned char m_3d;
    unsigned char m_3e;
    unsigned char m_3f;
    unsigned char m_40;
    unsigned char m_41;
    unsigned char m_42;
    unsigned char m_43;
    unsigned char m_44;
    unsigned char m_45;
    unsigned char m_46;
    unsigned char m_47;
    unsigned char m_48;
    unsigned char m_49;
    unsigned char m_4a;
    unsigned char m_4b;
    unsigned char m_4c;
    unsigned char m_4d;
    unsigned char m_4e;
    unsigned char m_4f;
    unsigned char m_50;
    unsigned char m_51;
    unsigned char m_52;
    unsigned char m_53;
    unsigned char m_54;

    unsigned char m_55;
    unsigned char m_56;
    unsigned char m_57;
    unsigned char m_58;
    unsigned char m_59;
    unsigned char m_5a;
    unsigned char m_5b;
    unsigned char m_5c;
    unsigned char m_5d;

    float __thiscall GetScaleAtPoint(int value);
    void __thiscall FUN_006ff3f0();
    bool __thiscall GetByteAtOffset5C();

    void __thiscall SetValue(int value);
};
// Stand-in for the game's NiPoint2 (float x, float y).  The real constructor
// lives at 0x452dc0 in the image; it is only declared here so that the call
// keeps the original relocation.
struct NiPoint2
{
    float x;
    float y;
    NiPoint2(float a, float b);
};
// Stand-in for the class that owns GetScaleAtPoint.  Only the members the
// function actually touches are modelled, at their original offsets.
struct FnvScaleNode
{
    int unk00;
    unsigned int m04;
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
    float m34;
    float m38;
    int unk3c;
    int unk40;
    int unk44;
    float m48;
    float m4c;
    float ComputeDistanceSquaredToRect(NiPoint2 a, float b, NiPoint2 c);
    float GetScaleAtPoint(NiPoint2* arg);
};
extern double DAT_01016968;
float C6FEC00Abs(float fValue);
struct C6FEC00Point2
{
    float x;
    float y;
};
class C6FEC00Cell
{
  public:
    int unk00;
    unsigned int m_uiSize;
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
    float m_fCenterX;
    float m_fCenterY;

    bool FUN_006fec00(const C6FEC00Point2* pkPoint);
};
struct SteamCallbackA
{
    int unk00, unk04, unk08, unk0C, unk10;
    SteamCallbackA(void*, void (*)());
    ~SteamCallbackA();
};
struct SteamCallbackB
{
    int unk00, unk04, unk08, unk0C, unk10;
    SteamCallbackB(void*, void (*)());
    ~SteamCallbackB();
};
struct SteamCallbackC
{
    int unk00, unk04, unk08, unk0C, unk10;
    SteamCallbackC(void*, void (*)());
    ~SteamCallbackC();
};
void OnEvent();
void FUN_006ff8f0();
struct SteamUserInterface
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
    virtual int GetId();
};
struct SteamStatsInterface
{
    virtual void Init();
};
extern "C" __declspec(dllimport) bool __cdecl SteamAPI_Init();
extern "C" __declspec(dllimport) SteamUserInterface* __cdecl SteamUser();
extern "C" __declspec(dllimport) SteamStatsInterface* __cdecl SteamUserStats();
struct FUN_006ff690
{
    SteamCallbackA callbackA;
    SteamCallbackB callbackB;
    SteamCallbackC callbackC;
    bool initialized, unk3D, enabled;
    int userId;
    bool FUN_006ff820();
    FUN_006ff690();
};
// FUN_006ff7b0 - destructor of the game's Steam callback holder.
//
// The object is a plain (NON-polymorphic) hub that owns three VSteam::CCallback<>
// sub-objects, each 0x14 bytes wide:
//
//     +0x00  CCallback<UserStatsReceived_t>       (dtor 0x6ff9a0)
//     +0x14  CCallback<UserStatsStored_t>         (dtor 0x6ffa40)
//     +0x28  CCallback<UserAchievementStored_t>   (dtor 0x6ffac0)
//
// The destructor shuts the Steam API down and then lets the compiler tear the
// three members down in reverse declaration order.  Because the holder itself is
// not polymorphic it has no vptr of its own, so no vtable store appears here -
// only the sub-objects' own destructors install theirs.
//
// The three sub-object destructors are only DECLARED here: they live in the game
// image and the checker binds the three call relocations from the original's own
// bytes.  They need three DIFFERENT class names - if two sub-objects shared a
// class they would share one relocation symbol and only one binding would
// survive.
extern "C" __declspec(dllimport) void __cdecl SteamAPI_Shutdown();
// Stand-in for VSteam::CCallback<UserStatsReceived_t>: 0x14 bytes.
struct SteamCallbackReceived
{
    int* m_pCallback;     // +0x00
    char m_bEnableState;  // +0x04
    int m_nCallbackSize;  // +0x08
    int m_nCallbackId;    // +0x0c
    int m_nB;             // +0x10
    ~SteamCallbackReceived();
};
// Stand-in for VSteam::CCallback<UserStatsStored_t>: 0x14 bytes.
struct SteamCallbackStored
{
    int* m_pCallback;     // +0x00
    char m_bEnableState;  // +0x04
    int m_nCallbackSize;  // +0x08
    int m_nCallbackId;    // +0x0c
    int m_nB;             // +0x10
    ~SteamCallbackStored();
};
// Stand-in for VSteam::CCallback<UserAchievementStored_t>: 0x14 bytes.
struct SteamCallbackAchieved
{
    int* m_pCallback;     // +0x00
    char m_bEnableState;  // +0x04
    int m_nCallbackSize;  // +0x08
    int m_nCallbackId;    // +0x0c
    int m_nB;             // +0x10
    ~SteamCallbackAchieved();
};
struct FUN_006ff7b0_Class
{
    SteamCallbackReceived m_received;  // +0x00
    SteamCallbackStored m_stored;      // +0x14
    SteamCallbackAchieved m_achieved;  // +0x28
    ~FUN_006ff7b0_Class();
};
// InvokeHandler: thiscall wrapper that forwards to a handler stored in the object.
//   ecx = this
//   [ebp+8] = int argument, pushed for the handler
//   handler is called as handler(this->m_pFlagTarget, a1): the target object goes in
//   ecx, the int argument on the stack, and the handler pops it (ret 4).
typedef void(__thiscall* FUN_006ff9d0_Handler)(void* self, int a1);
struct FUN_006ff9d0_cls : public FUN_006ff970_Class
{
    void* m_pFlagTarget;
    FUN_006ff9d0_Handler m_pHandler;
    void InvokeHandler(int a1);
};
struct FUN_006ffaf0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void* m_0c;
    void(__thiscall* m_10)(void*, int);

    void __thiscall ForwardToCallback(int a1, int a2, int a3, int a4);
};
extern "C" __declspec(dllimport) void __cdecl B6FFB20Notify(void* pvObject, int iMessage);
class B6FFB20Request
{
  public:
    int unk00;
    unsigned char m_ucFlags;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    int unk08;
    void* m_pvSource;
    void* m_pvTarget;

    void UnregisterSteamCallback();
    void SetSourceAndTarget(void* pvSource, void* pvTarget);
};
struct FFB90Request;
extern void(__cdecl* g_pfnFFB90Notify)(FFB90Request* request, int message);
struct FFB90Request
{
    int unk00;
    unsigned char m_ucFlags;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    int unk08;
    int m_iParam1;
    int m_iParam2;

    void UnregisterSteamCallback();
    void SetParams(int param1, int param2);
};
extern "C" __declspec(dllimport) void __cdecl SteamAPI_RegisterCallback(void* callback, int callbackId);
struct FUN_006ffc20_shell : FUN_006ff970_Class
{
    int callbackObject;
    int callbackTarget;
    enum
    {
        kGameServerCallback = 0
    };
    void FUN_006ffc20(int object, int target);
};
struct FUN_006ffda0_cls
{
    int m_i0;
    int m_i4;
    int m_i8;
    int m_ic;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    unsigned char m_ca28;
    unsigned char m_cb29;

    void FUN_006ffda0();
    int __thiscall FUN_00559450();
    int __thiscall FUN_004048e0();
};
int __cdecl FormHeap_Free(int a);
int __cdecl AllocateZeroed(int a, int b);
class NiTMapBase6E2
{
  public:
    virtual ~NiTMapBase6E2();

    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};
class FUN_006e2150 : public NiTMapBase6E2
{
  public:
    virtual ~FUN_006e2150();
};
class TESForm
{
  public:
    virtual ~TESForm();
};
class TESObjectREFR : public TESForm
{
};
class BGSLoadFormBuffer
{
  public:
    void FUN_00864980(void* apDest, unsigned int auiSize);
    unsigned int FUN_008648a0();
};
TESForm* LookupFormByID(unsigned int auiFormID);
struct LoadedRefPosition
{
    float x;
    float y;
    float z;
};
class LoadedRefMember
{
  public:
    virtual void v00();
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
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
class LoadedRefHolder
{
  public:
    unsigned int m_uiValue1;
    LoadedRefMember m_kMember;
    LoadedRefPosition m_kPathOffset;
    TESObjectREFR* m_pReference;

    void FUN_006e23b0(BGSLoadFormBuffer* apBuffer);
};
struct Point3 : public NiPoint3
{
    Point3();
    float __thiscall FUN_00457910();
    Point3 __thiscall operator*(float distance) const;
    Point3 __thiscall operator+(const Point3& other) const;
};
extern double DAT_010240c0;
float __cdecl FUN_00408840(float value);
class PathCheck
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
    float m_spacing;

    bool __thiscall TraceWithLiftAndExtension(const NiPoint3* from, const NiPoint3* to, NiPoint3* result);
    bool __thiscall CheckPathClear(NiPoint3* start, NiPoint3* end);
};
struct TraceVector
{
    float x;
    float y;
    float z;
    TraceVector ApplyScaled(float) const;
    TraceVector FUN_00439e90(const TraceVector&) const;
    TraceVector FUN_00439ef0(const TraceVector&) const;
};
extern TraceVector DAT_011a9484;
struct TraceReset
{
    void FUN_0062a2b0();
};
struct TraceRequest
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
    TraceReset state;
    void FUN_004a3da0(const TraceVector&);
    void FUN_004a3eb0(const TraceVector&);
};
struct TraceFraction
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float fraction;
};
struct TraceResult
{
    void FUN_0062a290();
    TraceFraction* FUN_00460140();
};
struct TraceWorld
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual bool Trace(TraceRequest*);
};
struct TraceOwner
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
    TraceWorld* world;
    TraceRequest* request;
    TraceResult* result;
    unsigned int count;
    float distance;
    float height;
    bool TraceWithLiftAndExtension(const TraceVector&, const TraceVector&, TraceVector&);
};
struct SAElement
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
struct SAArray
{
    virtual void v00();
    virtual SAElement* Allocate(unsigned int auiCount);

    SAElement* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;

    bool ShouldShrink();
    unsigned int GetShrinkSize();
    void Move(SAElement* apDest, const SAElement* apSrc, unsigned int auiCount);
    void Destroy(SAElement* apItems, unsigned int auiCount);
    void Free();
    void FUN_006e7500(unsigned int auiIndex, bool abShrink);
};
struct S_006eaa00
{
    int unk00;
    int unk04;
    S_006eaa00(S_006eaa00* other);
};
struct FUN_006ece00_Empty
{
    void __thiscall Clear();
};
struct Elem_00483710
{
    int unk00;
    int unk04;
    int unk08;
    ~Elem_00483710();
};
struct Base_006ecf20
{
    virtual ~Base_006ecf20();
};
struct FUN_006ecfa0 : Base_006ecf20
{
    int unk04;
    int unk08;
    Elem_00483710 elements[256];
    ~FUN_006ecfa0();
};
// Create a path entry at this position for the current navmesh triangle and register it in both lists.
struct EDBC0Point3
{
    float x;
    float y;
    float z;
};
class EDBC0NavMesh
{
  public:
    void* GetNavMeshInfo();
};
struct EDBC0Location
{
    EDBC0NavMesh* m_pkNavMesh;
    unsigned short m_usTriangle;
};
class EDBC0Source
{
  public:
    EDBC0Location* GetLocation();
};
struct EDBC0Entry
{
    EDBC0Point3 m_kPathOffset;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    void* m_pkNavMeshInfo;
    unsigned short m_usTriangle;
};
class EDBC0EntryArray
{
  public:
    unsigned int Add(EDBC0Entry*& rpkEntry);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
class EDBC0Builder
{
  public:
    int unk00;
    int unk04;
    EDBC0Point3 m_kPathOffset;
    int unk14;
    int unk18;
    int unk1C;
    EDBC0Source* m_pkSource;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    EDBC0EntryArray m_kAll;
    EDBC0EntryArray m_kOpen;

    EDBC0Entry* CreateEntry();
    void FUN_006edbc0();
};
struct PBTriangle
{
    unsigned char GetEdgeFlags(unsigned int auiEdge);
};
struct PBNavMesh
{
    unsigned int GetStamp();
    PBTriangle* GetTriangle(unsigned short ausIndex);
};
struct PBContext
{
    PBNavMesh* m_pLocationNavMesh;
    unsigned short usIndex;
    unsigned short usFlags;
    int m_iEdgeNumber;
};
struct PBContextArray
{
    PBContext* GetAt(int aiIndex);
};
struct PBList
{
    void* pEntries;
    unsigned int uiCapacity;
    unsigned int uiSize;
    unsigned int uiFlags;
    unsigned int uiRevision;

    unsigned int* GetLast();
    unsigned int GetSize();
    void Add(void** appItem);
};
struct PBBuilder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    PositionCollection_006edd30* pPositions;
    PBContextArray* m_pContextArray;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    PBList kStarts;
    PBList kEnds;
    PBList kStartEdges;
    PBList kEndEdges;
    PBList kPaths;

    Location_006edd30* NewLocation();
    PathEdge_006edd30* NewEdge();
    Path_006edd30* NewPath();
    void AddPathFromContext(const Position_006edd30* apPosition, int aiIndex);
};
struct Vec390
{
    float x, y, z;
    float Dot(const Vec390&) const;
};
struct Info390;
struct Tri390
{
    unsigned char EdgeFlag(int);
};
struct Mesh390
{
    Info390* Info();
    Tri390* Triangle(unsigned short);
    Vec390 Position(unsigned short);
};
struct Parent390
{
    Mesh390* mesh;
    unsigned short triangle;
    int edge;
};
struct Parents390
{
    Parent390& GetAt(int);
};
struct Search390
{
    Parent390* Get(unsigned) const;
};
template <class T> struct List390
{
    int unk00, unk04, unk08, unk0c, unk10;
    T& GetLast();
    unsigned Add(T&);
    unsigned Size();
};
struct Path390;
struct PathList390
{
    int unk00, unk04, unk08;
    unsigned Add(Path390*&);
};
struct Location390
{
    Vec390 position;
    int unk0c, unk10, unk14, unk18, unk1c, unk20;
    Info390* info;
    unsigned short triangle;
    PathList390 paths;
};
struct Link390
{
    Location390* previous;
    Location390* location;
    Info390* info;
    unsigned short triangle;
    int edge;
    unsigned char flag;
    unsigned index;
};
struct Path390
{
    Path390* previous;
    Location390* location;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    PathList390 paths;
    float dot;
    Info390* info;
    unsigned short triangle;
    int edge;
    unsigned index;
    Path390* prior;
    Link390* link;
};
struct Builder390
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Search390* search;
    Parents390* parents;
    int unk28, unk2c, unk30, unk34, unk38, unk3c;
    List390<Path390*> paths;
    List390<Location390*> locations;
    List390<Path390*> other;
    List390<Link390*> links;
    List390<Path390*> allPaths;
    Location390* NewLocation();
    Link390* NewLink();
    Path390* NewPath();
    void AddPathFromEdge(const Vec390* position, int index);
};
struct NodeS;
struct EdgeS;
struct ArrE
{
    int unk0, unk4, unk8, unkC, unk10;
    EdgeS*& FUN_006a7ad0(unsigned int);
    EdgeS*& GetFirstForm();
    EdgeS*& FUN_006f2270();
    bool FUN_0076b610();
};
struct ArrN
{
    int unk0, unk4, unk8, unkC, unk10;
    void FUN_006f23d0(unsigned int, NodeS*&);
};
struct NodeS
{
    NiPoint3 origin, position, direction;
    S0069a690 info;
    ArrE edges;
};
struct EdgeS
{
    NodeS* first;
    NodeS* second;
    EH info;
    unsigned char flag;
    int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;
    float weight;
    EH bound;
    unsigned int index;
    EdgeS* left;
    EdgeS* right;
};
struct HostS
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    ArrN nodesA, nodesB;
    ArrE edgesA, edgesB, edgesC;
    NodeS* FUN_006edc40();
    EdgeS* CreateSize28();
    EdgeS* CreateObject();
    void SetEntry(unsigned int, EdgeS*, bool);
    void AssignRecordIndices(unsigned int, EdgeS*);
    NodeS* SplitEdge(unsigned int index, bool side);
};
struct FNV_006ef920_Vertex
{
    unsigned int unk00, unk04, unk08;
    NiPoint3 position;
};
struct FNV_006ef920_Nodes
{
    FNV_006ef920_Vertex* first;
    FNV_006ef920_Vertex* second;
};
struct FNV_006ef920_Temporary
{
    unsigned int handle;
    FNV_006ef920_Temporary()
    {
        FUN_0042fb00();
    }
    ~FNV_006ef920_Temporary()
    {
        FUN_0042fa40();
    }
    void FUN_0042fb00();
    void FUN_0042fa40();
    void* FUN_00559450();
};
struct FNV_006ef920_Serializer
{
    bool FUN_0069ad00(FNV_006ef920_Temporary*);
};
struct FNV_006ef920_Entry
{
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
    FNV_006ef920_Serializer* serializer;
    unsigned short identifier;
    unsigned short unk42;
    void* extra;
    unsigned int unk48;
    FNV_006ef920_Nodes* sideA;
    FNV_006ef920_Nodes* sideB;
};
struct FNV_006ef920_Record
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    void FUN_006efd50();
};
struct FNV_006ef920_RecordFields
{
    void* handle;
    unsigned short identifier;
    unsigned short unk06;
    void* extra;
};
struct FNV_006ef920_Receiver
{
    void FUN_006cf4c0(FNV_006ef920_Record*);
};
struct FNV_006ef920
{
    FNV_006ef920_Receiver* receiver;
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
    IndexCollection edges;
    bool CheckLinkCrossing(FNV_006ef920_Nodes*, FNV_006ef920_Nodes*, bool);
    bool CheckEdges();
};
struct Point
{
    float x, y, z;
    Point operator-(const Point&) const;
    Point operator+(const Point&) const;
    Point operator*(float) const;
};
struct Mesh;
struct Location
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    Location(const Point&, const Mesh*);
    ~Location();
};
struct Segment
{
    Point start, end;
};
struct Vertex
{
    Point origin, position, direction;
    const Mesh* mesh;
};
struct Link
{
    Vertex* first;
    Vertex* second;
    int unk08, unk0c, unk10, unk14;
    unsigned index;
};
bool __cdecl Cross(const Point*, const Point*, const Point*, const Point*);
bool __cdecl Reach(Location*, const Point&, int, int);
extern const float scale;
struct Owner
{
    Segment* Allocate(unsigned, bool);
    bool CheckLinkCrossing(Link* source, Link* target, bool side);
};
class NiPoint3Ex : public NiPoint3
{
  public:
    NiPoint3Ex operator+(const NiPoint3Ex&) const;
    NiPoint3Ex operator-(const NiPoint3Ex&) const;
    NiPoint3Ex operator*(float) const;
};
class PathingLocation
{
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    PathingLocation();
    PathingLocation(const NiPoint3&, TESObjectCELL*, TESWorldSpace*);
    ~PathingLocation();
    NiPoint3Ex FUN_005c3420() const;
};
struct TargetNavInfo
{
    TESWorldSpace* FUN_00690800();
    TESObjectCELL* FUN_006b7770();
};
extern NiPoint3Ex DAT_011a946c;
bool __cdecl FUN_006d7350(PathingLocation&, PathingLocation&, PathingLocation*, void*);
bool __cdecl FUN_006d7490(PathingLocation&, PathingLocation&, void*, void*);
struct TargetHost
{
    bool FUN_006f0050(const NiPoint3Ex&, NiPoint3Ex&, TargetNavInfo*, int, const NiPoint3Ex&, PathingLocation&,
                      PathingLocation&);
};
struct HeightVec
{
    float x, y, z;
    HeightVec operator-(const HeightVec&) const;
    float FUN_00589850() const;
};
struct HeightTriangle
{
    bool FUN_006a5ec0();
};
struct HeightMesh
{
    HeightTriangle* FUN_005582f0(unsigned short);
};
struct HeightPtr
{
    HeightMesh* ptr;
    HeightPtr();
    ~HeightPtr();
    operator HeightMesh*() const;
};
struct HeightInfo
{
    bool Resolve(HeightPtr&);
};
struct HeightEntry
{
    int unk00, unk04, unk08, unk0c, unk10;
    HeightVec position;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    HeightInfo* info;
    unsigned short triangle;
    unsigned short unk42;
    int unk44, unk48, unk4c, unk50;
    int boundary;
};
struct HeightArray
{
    unsigned GetSize();
    HeightEntry*& GetAt(unsigned);
};
struct HeightFlags
{
    int unk00, unk04, unk08, unk0c, unk10;
    HeightFlags(unsigned);
    ~HeightFlags();
    unsigned GetSize();
    bool& GetAt(unsigned);
    unsigned Find(const bool&, unsigned, bool(__cdecl*)(const unsigned char*, const unsigned char*));
};
bool __cdecl AreBytesEqual(const unsigned char*, const unsigned char*);
struct HeightPath
{
    int unk00, unk04;
    HeightVec start, end;
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
    HeightArray points;
    void FlattenPathPoints();
};
struct PSPoint3
{
    float x;
    float y;
    float z;
};
struct PSNavMeshInfo;
struct PSNavMesh
{
    PSNavMeshInfo* GetNavMeshInfo();
};
struct PSRequest
{
    PSNavMesh*& GetStartNavMesh();
    PSNavMesh*& GetEndNavMesh();
};
struct PSLocation
{
    int unk00[10];

    PSLocation(const PSPoint3& arPoint, const PSNavMeshInfo* apInfo);
    ~PSLocation();
};
struct PSLocationArray
{
    unsigned int Add(const PSLocation& arLocation);
};
struct PSNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    PSPoint3 kPosition;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    float m_fPathingCostCur;
    PSNavMeshInfo* m_pNavigationMesh;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    void* pPathNodeDoor;
};
struct PSNodeArray
{
    int GetSize();
    PSNode*& GetAt(unsigned int auiIndex);
};
struct PSSolution
{
    int unk00;
    int unk04;
    PSPoint3 kStart;
    PSPoint3 kEnd;
    PSRequest* pRequest;
    int unk24[27];
    PSNodeArray kNodes;
    int unk94[4];
    PSLocationArray kLocations;

    bool IsStraightPath(int aiFirst, int aiLast, PSPoint3& arFrom, PSPoint3& arTo);
    void BuildLocations();
};
struct FUN_006815c0
{
    float x, y, z;
    FUN_006815c0();
    FUN_006815c0 FUN_00439ef0(const FUN_006815c0&) const;
    float FUN_004a7290() const;
};
struct AvoidObject
{
    float x, y, z, radius;
    void* object;
    int unk14, unk18, unk1c, unk20;
    const FUN_006815c0* FUN_006815c0();
    float FUN_004a7bd0();
};
struct AvoidObjects
{
    unsigned int FUN_0044ddc0();
    const AvoidObject& FUN_006a1400(unsigned int);
};
struct AvoidOwner
{
    AvoidObjects* GetString();
};
struct FUN_006240d0
{
    FUN_006815c0 center;
    float radius;
    FUN_006240d0();
    bool FUN_006f1bc0(const FUN_006815c0&);
};
struct FUN_006f2d80
{
    void* table;
    FUN_006240d0* data;
    unsigned int size, capacity;
    void* allocator;
    FUN_006f2d80();
    ~FUN_006f2d80();
    unsigned int FUN_0044ddc0();
    FUN_006240d0* FUN_00558dd0(unsigned int);
    void AppendElement(const FUN_006240d0&);
};
struct FUN_006dd0d0
{
    void* table;
    float x, y, z;
    void* mesh;
    void* meshes;
    void* cell;
    void* world;
    unsigned int cellKey;
    unsigned short triangle, flags;
    FUN_006dd0d0(const FUN_006815c0&, const FUN_006dd0d0&);
    ~FUN_006dd0d0();
    FUN_006815c0 FUN_005c3420();
};
struct AvoidPoints
{
    unsigned int FUN_0044ddc0();
    FUN_006dd0d0* FUN_00691750(unsigned int);
    void RemoveRange(unsigned int, unsigned int, int);
    void FUN_006f28a0(unsigned int, const FUN_006dd0d0&);
};
struct AvoidPath
{
    void* table;
    AvoidOwner* owner;
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
    AvoidPoints points;
    bool FUN_006f1e90(const FUN_006815c0&, const FUN_006815c0&);
    void ClipPathAgainstObstacles();
};
bool FUN_006ba9e0(const FUN_006815c0&, const FUN_006815c0&, const FUN_006815c0&, float);
bool ComputeCircleTangents(const FUN_006815c0&, float, const FUN_006815c0&, FUN_006815c0*, FUN_006815c0*);
// Whether a point lies strictly inside the sphere.
class C6F1BC0Vector : public NiPoint3
{
  public:
    float SqrLength() const;
};
class C6F1BC0Sphere
{
  public:
    NiPoint3 m_kCenter;
    float m_fBoundRadius;

    bool FUN_006f1bc0(const NiPoint3& kPoint);
};
struct PathPoint3
{
    float x;
    float y;
    float z;
};
struct PathSegment
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
    PathSegment(const PathPoint3& kPoint, int iCellID);
    ~PathSegment();
};
struct PathCell
{
    int FUN_0068efb0();
};
struct PathCellSource
{
    PathCell*& GetFirstElement();
    PathCell*& GetLastElement();
};
struct PathSegmentArray
{
    unsigned int FUN_0044ddc0();
    PathSegment& FUN_00691750(unsigned int uiIndex);
};
struct FUN_006f1c10_Path
{
    int unk00;
    int unk04;
    PathPoint3 kStart;
    PathPoint3 kEnd;
    PathCellSource* pCells;
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
    PathSegmentArray kSegments;

    void FUN_006ed7a0(const PathSegment& kSegment);
    void AppendSegments(bool abIncludeStart, bool abIncludeEnd);
};
// Whether the segment a-b crosses none of the area's border edges (both edge lists).
struct F1ED0Point3
{
    float x;
    float y;
    float z;
};
struct F1ED0Vertex
{
    int unk00;
    int unk04;
    int unk08;
    F1ED0Point3 m_kPos;
};
struct F1ED0Edge
{
    F1ED0Vertex* m_pkStart;
    F1ED0Vertex* m_pkEnd;
};
class F1ED0EdgeArray
{
  public:
    unsigned int GetSize();
    F1ED0Edge*& GetAt(unsigned int uiIndex) const;
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
bool __cdecl F1ED0SegmentsIntersect(const F1ED0Point3& kA0, const F1ED0Point3& kA1, const F1ED0Point3& kB0,
                                    const F1ED0Point3& kB1);
class F1ED0Area
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
    F1ED0EdgeArray m_kOuterEdges;
    F1ED0EdgeArray m_kInnerEdges;

    bool IsSegmentClear(const F1ED0Point3& kStart, const F1ED0Point3& kEnd);
};
extern float DAT_0106b158;
struct PtObj1fc0
{
    int u0;
    int u4;
    int u8;
    NiPoint3 pt;
};
struct Elem1fc0
{
    PtObj1fc0* first;
    PtObj1fc0* second;
};
struct Arr1fc0
{
    int u0;
    int u4;
    int u8;
    int uc;
    int u10;
    bool FUN_0076b610();
    Elem1fc0** FUN_00877a30(unsigned int);
    unsigned int FUN_0044ddc0();
    Elem1fc0** FUN_006f2270();
};
bool __cdecl FUN_006b9cf0(const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&, float&, float, float);
struct Host1fc0
{
    int m00;
    int m04;
    NiPoint3 pt08;
    NiPoint3 pt14;
    int m20, m24, m28, m2c, m30, m34, m38, m3c;
    int m40, m44, m48, m4c, m50, m54, m58, m5c;
    int m60, m64, m68, m6c, m70, m74, m78, m7c;
    int m80, m84, m88, m8c;
    Arr1fc0 arr90;
    bool __thiscall FUN_006f1fc0(int);
};
class Heap6F2;
class MemoryManager6F2
{
  public:
    Heap6F2* GetDefaultHeap();
};
MemoryManager6F2* GetMemoryManager6F2();
class Base6F2
{
  public:
    Base6F2();
    virtual ~Base6F2();

    int unk04;
    int unk08;
    int unk0C;
    Heap6F2* m_pkHeap;

    void Initialize(unsigned int uiA, unsigned int uiB);
};
class FUN_006f2630 : public Base6F2
{
  public:
    FUN_006f2630(unsigned int uiA, unsigned int uiB, Heap6F2* pkHeap);
    virtual ~FUN_006f2630();
};
inline void* __cdecl operator new(unsigned int, void* pvWhere)
{
    return pvWhere;
}
inline void __cdecl operator delete(void*, void*)
{}
class C6F3280Bound
{
  public:
    C6F3280Bound();

    float m_fCenterX;
    float m_fCenterY;
    float m_fCenterZ;
    float m_fBoundRadius;
};
class C6F3280Allocator
{
  public:
    void ConstructBounds(C6F3280Bound* pkElements, unsigned int ItemUpdateArray);
};
struct SearchNode
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    SearchNode* parent;
    float Heuristic();
};
struct Neighbours
{
    int unk00, unk04, unk08, unk0c, unk10;
    Neighbours();
    ~Neighbours();
    void Clear(bool);
    unsigned int Count();
    SearchNode*& At(unsigned int);
};
struct OpenNodes
{
    SearchNode* Pop();
    void Remove(SearchNode*);
    void Add(SearchNode*);
};
void __cdecl Yield(unsigned long);
struct Search
{
    virtual void Unused();
    virtual void Expand(SearchNode*, Neighbours*);
    virtual bool IsGoal(SearchNode*);
    int unk0004, unk0008, unk000c, unk0010, unk0014, unk0018, unk001c, unk0020, unk0024, unk0028, unk002c, unk0030,
        unk0034, unk0038, unk003c, unk0040, unk0044, unk0048, unk004c, unk0050, unk0054, unk0058, unk005c, unk0060,
        unk0064, unk0068, unk006c, unk0070, unk0074, unk0078, unk007c, unk0080, unk0084, unk0088, unk008c, unk0090,
        unk0094, unk0098, unk009c, unk00a0, unk00a4, unk00a8, unk00ac, unk00b0, unk00b4, unk00b8, unk00bc, unk00c0,
        unk00c4, unk00c8, unk00cc, unk00d0, unk00d4, unk00d8, unk00dc, unk00e0, unk00e4, unk00e8, unk00ec, unk00f0,
        unk00f4, unk00f8, unk00fc, unk0100, unk0104, unk0108, unk010c, unk0110, unk0114, unk0118, unk011c, unk0120,
        unk0124, unk0128, unk012c, unk0130, unk0134, unk0138, unk013c, unk0140, unk0144, unk0148, unk014c, unk0150,
        unk0154, unk0158, unk015c, unk0160, unk0164, unk0168, unk016c, unk0170, unk0174, unk0178, unk017c, unk0180,
        unk0184, unk0188, unk018c, unk0190, unk0194, unk0198, unk019c, unk01a0, unk01a4, unk01a8, unk01ac, unk01b0,
        unk01b4, unk01b8, unk01bc, unk01c0, unk01c4, unk01c8, unk01cc, unk01d0, unk01d4, unk01d8, unk01dc, unk01e0,
        unk01e4, unk01e8, unk01ec, unk01f0, unk01f4, unk01f8, unk01fc, unk0200, unk0204, unk0208, unk020c, unk0210,
        unk0214, unk0218, unk021c, unk0220, unk0224, unk0228, unk022c, unk0230, unk0234, unk0238, unk023c, unk0240,
        unk0244, unk0248, unk024c, unk0250, unk0254, unk0258, unk025c, unk0260, unk0264, unk0268, unk026c, unk0270,
        unk0274, unk0278, unk027c, unk0280, unk0284, unk0288, unk028c, unk0290, unk0294, unk0298, unk029c, unk02a0,
        unk02a4, unk02a8, unk02ac, unk02b0, unk02b4, unk02b8, unk02bc, unk02c0, unk02c4, unk02c8, unk02cc, unk02d0,
        unk02d4, unk02d8, unk02dc, unk02e0, unk02e4, unk02e8, unk02ec, unk02f0, unk02f4, unk02f8, unk02fc, unk0300,
        unk0304, unk0308, unk030c, unk0310, unk0314, unk0318, unk031c, unk0320, unk0324, unk0328, unk032c, unk0330,
        unk0334, unk0338, unk033c, unk0340, unk0344, unk0348, unk034c, unk0350, unk0354, unk0358, unk035c, unk0360,
        unk0364, unk0368, unk036c, unk0370, unk0374, unk0378, unk037c, unk0380, unk0384, unk0388, unk038c, unk0390,
        unk0394, unk0398, unk039c, unk03a0, unk03a4, unk03a8, unk03ac, unk03b0, unk03b4, unk03b8, unk03bc, unk03c0,
        unk03c4, unk03c8, unk03cc, unk03d0, unk03d4, unk03d8, unk03dc, unk03e0, unk03e4, unk03e8, unk03ec, unk03f0,
        unk03f4, unk03f8, unk03fc, unk0400, unk0404, unk0408, unk040c, unk0410, unk0414, unk0418, unk041c, unk0420,
        unk0424, unk0428, unk042c, unk0430, unk0434, unk0438, unk043c, unk0440, unk0444, unk0448, unk044c, unk0450,
        unk0454, unk0458, unk045c, unk0460, unk0464, unk0468, unk046c, unk0470, unk0474, unk0478, unk047c, unk0480,
        unk0484, unk0488, unk048c, unk0490, unk0494, unk0498, unk049c, unk04a0, unk04a4, unk04a8, unk04ac, unk04b0,
        unk04b4, unk04b8, unk04bc, unk04c0, unk04c4, unk04c8, unk04cc, unk04d0, unk04d4, unk04d8, unk04dc, unk04e0,
        unk04e4, unk04e8, unk04ec, unk04f0, unk04f4, unk04f8, unk04fc, unk0500, unk0504, unk0508, unk050c, unk0510,
        unk0514, unk0518, unk051c, unk0520, unk0524, unk0528, unk052c, unk0530, unk0534, unk0538, unk053c, unk0540,
        unk0544, unk0548, unk054c, unk0550, unk0554, unk0558, unk055c, unk0560, unk0564, unk0568, unk056c, unk0570,
        unk0574, unk0578, unk057c, unk0580, unk0584, unk0588, unk058c, unk0590, unk0594, unk0598, unk059c, unk05a0,
        unk05a4, unk05a8, unk05ac, unk05b0, unk05b4, unk05b8, unk05bc, unk05c0, unk05c4, unk05c8, unk05cc, unk05d0,
        unk05d4, unk05d8, unk05dc, unk05e0, unk05e4, unk05e8, unk05ec, unk05f0, unk05f4, unk05f8, unk05fc, unk0600,
        unk0604, unk0608, unk060c, unk0610, unk0614, unk0618, unk061c, unk0620, unk0624, unk0628, unk062c, unk0630,
        unk0634, unk0638, unk063c, unk0640, unk0644, unk0648, unk064c, unk0650, unk0654, unk0658, unk065c, unk0660,
        unk0664, unk0668, unk066c, unk0670, unk0674, unk0678, unk067c, unk0680, unk0684, unk0688, unk068c, unk0690,
        unk0694, unk0698, unk069c, unk06a0, unk06a4, unk06a8, unk06ac, unk06b0, unk06b4, unk06b8, unk06bc, unk06c0,
        unk06c4, unk06c8, unk06cc, unk06d0, unk06d4, unk06d8, unk06dc, unk06e0, unk06e4, unk06e8, unk06ec, unk06f0,
        unk06f4, unk06f8, unk06fc, unk0700, unk0704, unk0708, unk070c, unk0710, unk0714, unk0718, unk071c, unk0720,
        unk0724, unk0728, unk072c, unk0730, unk0734, unk0738, unk073c, unk0740, unk0744, unk0748, unk074c, unk0750,
        unk0754, unk0758, unk075c, unk0760, unk0764, unk0768, unk076c, unk0770, unk0774, unk0778, unk077c, unk0780,
        unk0784, unk0788, unk078c, unk0790, unk0794, unk0798, unk079c, unk07a0, unk07a4, unk07a8, unk07ac, unk07b0,
        unk07b4, unk07b8, unk07bc, unk07c0, unk07c4, unk07c8, unk07cc, unk07d0, unk07d4, unk07d8, unk07dc, unk07e0,
        unk07e4, unk07e8, unk07ec, unk07f0, unk07f4, unk07f8, unk07fc, unk0800, unk0804, unk0808, unk080c, unk0810,
        unk0814, unk0818, unk081c, unk0820, unk0824, unk0828, unk082c, unk0830, unk0834, unk0838, unk083c, unk0840,
        unk0844, unk0848, unk084c, unk0850, unk0854, unk0858, unk085c, unk0860, unk0864, unk0868, unk086c, unk0870,
        unk0874, unk0878, unk087c, unk0880, unk0884, unk0888, unk088c, unk0890, unk0894, unk0898, unk089c, unk08a0,
        unk08a4, unk08a8, unk08ac, unk08b0, unk08b4, unk08b8, unk08bc, unk08c0, unk08c4, unk08c8, unk08cc, unk08d0,
        unk08d4, unk08d8, unk08dc, unk08e0, unk08e4, unk08e8, unk08ec, unk08f0, unk08f4, unk08f8, unk08fc, unk0900,
        unk0904, unk0908, unk090c, unk0910, unk0914, unk0918, unk091c, unk0920, unk0924, unk0928, unk092c, unk0930,
        unk0934, unk0938, unk093c, unk0940, unk0944, unk0948, unk094c, unk0950, unk0954, unk0958, unk095c, unk0960,
        unk0964, unk0968, unk096c, unk0970, unk0974, unk0978, unk097c, unk0980, unk0984, unk0988, unk098c, unk0990,
        unk0994, unk0998, unk099c, unk09a0, unk09a4, unk09a8, unk09ac, unk09b0, unk09b4, unk09b8, unk09bc, unk09c0,
        unk09c4, unk09c8, unk09cc, unk09d0, unk09d4, unk09d8, unk09dc, unk09e0, unk09e4, unk09e8, unk09ec, unk09f0,
        unk09f4, unk09f8, unk09fc, unk0a00, unk0a04, unk0a08, unk0a0c, unk0a10, unk0a14, unk0a18, unk0a1c, unk0a20,
        unk0a24, unk0a28, unk0a2c, unk0a30, unk0a34, unk0a38, unk0a3c, unk0a40, unk0a44, unk0a48, unk0a4c, unk0a50,
        unk0a54, unk0a58, unk0a5c, unk0a60, unk0a64, unk0a68, unk0a6c, unk0a70, unk0a74, unk0a78, unk0a7c, unk0a80,
        unk0a84, unk0a88, unk0a8c, unk0a90, unk0a94, unk0a98, unk0a9c, unk0aa0, unk0aa4, unk0aa8, unk0aac, unk0ab0,
        unk0ab4, unk0ab8, unk0abc, unk0ac0, unk0ac4, unk0ac8, unk0acc, unk0ad0, unk0ad4, unk0ad8, unk0adc, unk0ae0,
        unk0ae4, unk0ae8, unk0aec, unk0af0, unk0af4, unk0af8, unk0afc, unk0b00, unk0b04, unk0b08, unk0b0c, unk0b10,
        unk0b14, unk0b18, unk0b1c, unk0b20, unk0b24, unk0b28, unk0b2c, unk0b30, unk0b34, unk0b38, unk0b3c, unk0b40,
        unk0b44, unk0b48, unk0b4c, unk0b50, unk0b54, unk0b58, unk0b5c, unk0b60, unk0b64, unk0b68, unk0b6c, unk0b70,
        unk0b74, unk0b78, unk0b7c, unk0b80, unk0b84, unk0b88, unk0b8c, unk0b90, unk0b94, unk0b98, unk0b9c, unk0ba0,
        unk0ba4, unk0ba8, unk0bac, unk0bb0, unk0bb4, unk0bb8, unk0bbc, unk0bc0, unk0bc4, unk0bc8, unk0bcc, unk0bd0,
        unk0bd4, unk0bd8, unk0bdc, unk0be0, unk0be4, unk0be8, unk0bec, unk0bf0, unk0bf4, unk0bf8, unk0bfc, unk0c00,
        unk0c04, unk0c08, unk0c0c, unk0c10, unk0c14, unk0c18, unk0c1c, unk0c20, unk0c24, unk0c28, unk0c2c, unk0c30,
        unk0c34, unk0c38, unk0c3c, unk0c40, unk0c44, unk0c48, unk0c4c, unk0c50, unk0c54, unk0c58, unk0c5c, unk0c60,
        unk0c64, unk0c68, unk0c6c, unk0c70, unk0c74, unk0c78, unk0c7c, unk0c80, unk0c84, unk0c88, unk0c8c, unk0c90,
        unk0c94, unk0c98, unk0c9c, unk0ca0, unk0ca4, unk0ca8, unk0cac, unk0cb0, unk0cb4, unk0cb8, unk0cbc, unk0cc0,
        unk0cc4, unk0cc8, unk0ccc, unk0cd0, unk0cd4, unk0cd8, unk0cdc, unk0ce0, unk0ce4, unk0ce8, unk0cec, unk0cf0,
        unk0cf4, unk0cf8, unk0cfc, unk0d00, unk0d04, unk0d08, unk0d0c, unk0d10, unk0d14, unk0d18, unk0d1c, unk0d20,
        unk0d24, unk0d28, unk0d2c, unk0d30, unk0d34, unk0d38, unk0d3c, unk0d40, unk0d44, unk0d48, unk0d4c, unk0d50,
        unk0d54, unk0d58, unk0d5c, unk0d60, unk0d64, unk0d68, unk0d6c, unk0d70, unk0d74, unk0d78, unk0d7c, unk0d80,
        unk0d84, unk0d88, unk0d8c, unk0d90, unk0d94, unk0d98, unk0d9c, unk0da0, unk0da4, unk0da8, unk0dac, unk0db0,
        unk0db4, unk0db8, unk0dbc, unk0dc0, unk0dc4, unk0dc8, unk0dcc, unk0dd0, unk0dd4, unk0dd8, unk0ddc, unk0de0,
        unk0de4, unk0de8, unk0dec, unk0df0, unk0df4, unk0df8, unk0dfc, unk0e00, unk0e04, unk0e08, unk0e0c, unk0e10,
        unk0e14, unk0e18, unk0e1c, unk0e20, unk0e24, unk0e28, unk0e2c, unk0e30, unk0e34, unk0e38, unk0e3c, unk0e40,
        unk0e44, unk0e48, unk0e4c, unk0e50, unk0e54, unk0e58, unk0e5c, unk0e60, unk0e64, unk0e68, unk0e6c, unk0e70,
        unk0e74, unk0e78, unk0e7c, unk0e80, unk0e84, unk0e88, unk0e8c, unk0e90, unk0e94, unk0e98, unk0e9c, unk0ea0,
        unk0ea4, unk0ea8, unk0eac, unk0eb0, unk0eb4, unk0eb8, unk0ebc, unk0ec0, unk0ec4, unk0ec8, unk0ecc, unk0ed0,
        unk0ed4, unk0ed8, unk0edc, unk0ee0, unk0ee4, unk0ee8, unk0eec, unk0ef0, unk0ef4, unk0ef8, unk0efc, unk0f00,
        unk0f04, unk0f08, unk0f0c, unk0f10, unk0f14, unk0f18, unk0f1c, unk0f20, unk0f24, unk0f28, unk0f2c, unk0f30,
        unk0f34, unk0f38, unk0f3c, unk0f40, unk0f44, unk0f48, unk0f4c, unk0f50, unk0f54, unk0f58, unk0f5c, unk0f60,
        unk0f64, unk0f68, unk0f6c, unk0f70, unk0f74, unk0f78, unk0f7c, unk0f80, unk0f84, unk0f88, unk0f8c, unk0f90,
        unk0f94, unk0f98, unk0f9c, unk0fa0, unk0fa4, unk0fa8, unk0fac, unk0fb0, unk0fb4, unk0fb8, unk0fbc, unk0fc0,
        unk0fc4, unk0fc8, unk0fcc, unk0fd0, unk0fd4, unk0fd8, unk0fdc, unk0fe0, unk0fe4, unk0fe8, unk0fec, unk0ff0,
        unk0ff4, unk0ff8, unk0ffc, unk1000, unk1004, unk1008, unk100c, unk1010, unk1014, unk1018, unk101c, unk1020,
        unk1024, unk1028, unk102c, unk1030, unk1034, unk1038, unk103c, unk1040, unk1044, unk1048, unk104c, unk1050,
        unk1054, unk1058, unk105c, unk1060, unk1064, unk1068, unk106c, unk1070, unk1074, unk1078, unk107c, unk1080,
        unk1084, unk1088, unk108c, unk1090, unk1094, unk1098, unk109c, unk10a0, unk10a4, unk10a8, unk10ac, unk10b0,
        unk10b4, unk10b8, unk10bc, unk10c0, unk10c4, unk10c8, unk10cc, unk10d0, unk10d4, unk10d8, unk10dc, unk10e0,
        unk10e4, unk10e8, unk10ec, unk10f0, unk10f4, unk10f8, unk10fc, unk1100, unk1104, unk1108, unk110c, unk1110,
        unk1114, unk1118, unk111c, unk1120, unk1124, unk1128, unk112c, unk1130, unk1134, unk1138, unk113c, unk1140,
        unk1144, unk1148, unk114c, unk1150, unk1154, unk1158, unk115c, unk1160, unk1164, unk1168, unk116c, unk1170,
        unk1174, unk1178, unk117c, unk1180, unk1184, unk1188, unk118c, unk1190, unk1194, unk1198, unk119c, unk11a0,
        unk11a4, unk11a8, unk11ac, unk11b0, unk11b4, unk11b8, unk11bc, unk11c0, unk11c4, unk11c8, unk11cc, unk11d0,
        unk11d4, unk11d8, unk11dc, unk11e0, unk11e4, unk11e8, unk11ec, unk11f0, unk11f4, unk11f8, unk11fc, unk1200,
        unk1204, unk1208, unk120c, unk1210, unk1214, unk1218, unk121c, unk1220, unk1224, unk1228, unk122c, unk1230,
        unk1234, unk1238, unk123c, unk1240, unk1244, unk1248, unk124c, unk1250, unk1254, unk1258, unk125c, unk1260,
        unk1264, unk1268, unk126c, unk1270, unk1274, unk1278, unk127c, unk1280, unk1284, unk1288, unk128c, unk1290,
        unk1294, unk1298, unk129c, unk12a0, unk12a4, unk12a8, unk12ac, unk12b0, unk12b4, unk12b8, unk12bc, unk12c0,
        unk12c4, unk12c8, unk12cc, unk12d0, unk12d4, unk12d8, unk12dc, unk12e0, unk12e4, unk12e8, unk12ec, unk12f0,
        unk12f4, unk12f8, unk12fc, unk1300, unk1304, unk1308, unk130c, unk1310, unk1314, unk1318, unk131c, unk1320,
        unk1324, unk1328, unk132c, unk1330, unk1334, unk1338, unk133c, unk1340, unk1344, unk1348, unk134c, unk1350,
        unk1354, unk1358, unk135c, unk1360, unk1364, unk1368, unk136c, unk1370, unk1374, unk1378, unk137c, unk1380,
        unk1384, unk1388, unk138c, unk1390, unk1394, unk1398, unk139c, unk13a0, unk13a4, unk13a8, unk13ac, unk13b0,
        unk13b4, unk13b8, unk13bc, unk13c0, unk13c4, unk13c8, unk13cc, unk13d0, unk13d4, unk13d8, unk13dc, unk13e0,
        unk13e4, unk13e8, unk13ec, unk13f0, unk13f4, unk13f8, unk13fc, unk1400, unk1404, unk1408, unk140c, unk1410,
        unk1414, unk1418, unk141c, unk1420, unk1424, unk1428, unk142c, unk1430, unk1434, unk1438, unk143c, unk1440,
        unk1444, unk1448, unk144c, unk1450, unk1454, unk1458, unk145c, unk1460, unk1464, unk1468, unk146c, unk1470,
        unk1474, unk1478, unk147c, unk1480, unk1484, unk1488, unk148c, unk1490, unk1494, unk1498, unk149c, unk14a0,
        unk14a4, unk14a8, unk14ac, unk14b0, unk14b4, unk14b8, unk14bc, unk14c0, unk14c4, unk14c8, unk14cc, unk14d0,
        unk14d4, unk14d8, unk14dc, unk14e0, unk14e4, unk14e8, unk14ec, unk14f0, unk14f4, unk14f8, unk14fc, unk1500,
        unk1504, unk1508, unk150c, unk1510, unk1514, unk1518, unk151c, unk1520, unk1524, unk1528, unk152c, unk1530,
        unk1534, unk1538, unk153c, unk1540, unk1544, unk1548, unk154c, unk1550, unk1554, unk1558, unk155c, unk1560,
        unk1564, unk1568, unk156c, unk1570, unk1574, unk1578, unk157c, unk1580, unk1584, unk1588, unk158c, unk1590,
        unk1594, unk1598, unk159c, unk15a0, unk15a4, unk15a8, unk15ac, unk15b0, unk15b4, unk15b8, unk15bc, unk15c0,
        unk15c4, unk15c8, unk15cc, unk15d0, unk15d4, unk15d8, unk15dc, unk15e0, unk15e4, unk15e8, unk15ec, unk15f0,
        unk15f4, unk15f8, unk15fc, unk1600, unk1604, unk1608, unk160c, unk1610, unk1614, unk1618, unk161c, unk1620,
        unk1624, unk1628, unk162c, unk1630, unk1634, unk1638, unk163c, unk1640, unk1644, unk1648, unk164c, unk1650,
        unk1654, unk1658, unk165c, unk1660, unk1664, unk1668, unk166c, unk1670, unk1674, unk1678, unk167c, unk1680,
        unk1684, unk1688, unk168c, unk1690, unk1694, unk1698, unk169c, unk16a0, unk16a4, unk16a8, unk16ac, unk16b0,
        unk16b4, unk16b8, unk16bc, unk16c0, unk16c4, unk16c8, unk16cc, unk16d0, unk16d4, unk16d8, unk16dc, unk16e0,
        unk16e4, unk16e8, unk16ec, unk16f0, unk16f4, unk16f8, unk16fc, unk1700, unk1704, unk1708, unk170c, unk1710,
        unk1714, unk1718, unk171c, unk1720, unk1724, unk1728, unk172c, unk1730, unk1734, unk1738, unk173c, unk1740,
        unk1744, unk1748, unk174c, unk1750, unk1754, unk1758, unk175c, unk1760, unk1764, unk1768, unk176c, unk1770,
        unk1774, unk1778, unk177c, unk1780, unk1784, unk1788, unk178c, unk1790, unk1794, unk1798, unk179c, unk17a0,
        unk17a4, unk17a8, unk17ac, unk17b0, unk17b4, unk17b8, unk17bc, unk17c0, unk17c4, unk17c8, unk17cc, unk17d0,
        unk17d4, unk17d8, unk17dc, unk17e0, unk17e4, unk17e8, unk17ec, unk17f0, unk17f4, unk17f8, unk17fc, unk1800,
        unk1804, unk1808, unk180c, unk1810, unk1814, unk1818, unk181c, unk1820, unk1824, unk1828, unk182c, unk1830,
        unk1834, unk1838, unk183c, unk1840, unk1844, unk1848, unk184c, unk1850, unk1854, unk1858, unk185c, unk1860,
        unk1864, unk1868, unk186c, unk1870, unk1874, unk1878, unk187c, unk1880, unk1884, unk1888, unk188c, unk1890,
        unk1894, unk1898, unk189c, unk18a0, unk18a4, unk18a8, unk18ac, unk18b0, unk18b4, unk18b8, unk18bc, unk18c0,
        unk18c4, unk18c8, unk18cc, unk18d0, unk18d4, unk18d8, unk18dc, unk18e0, unk18e4, unk18e8, unk18ec, unk18f0,
        unk18f4, unk18f8, unk18fc, unk1900, unk1904, unk1908, unk190c, unk1910, unk1914, unk1918, unk191c, unk1920,
        unk1924, unk1928, unk192c, unk1930, unk1934, unk1938, unk193c, unk1940, unk1944, unk1948, unk194c, unk1950,
        unk1954, unk1958, unk195c, unk1960, unk1964, unk1968, unk196c, unk1970, unk1974, unk1978, unk197c, unk1980,
        unk1984, unk1988, unk198c, unk1990, unk1994, unk1998, unk199c, unk19a0, unk19a4, unk19a8, unk19ac, unk19b0,
        unk19b4, unk19b8, unk19bc, unk19c0, unk19c4, unk19c8, unk19cc, unk19d0, unk19d4, unk19d8, unk19dc, unk19e0,
        unk19e4, unk19e8, unk19ec, unk19f0, unk19f4, unk19f8, unk19fc, unk1a00, unk1a04, unk1a08, unk1a0c, unk1a10,
        unk1a14, unk1a18, unk1a1c, unk1a20, unk1a24, unk1a28, unk1a2c, unk1a30, unk1a34, unk1a38, unk1a3c, unk1a40,
        unk1a44, unk1a48, unk1a4c, unk1a50, unk1a54, unk1a58, unk1a5c, unk1a60, unk1a64, unk1a68, unk1a6c, unk1a70,
        unk1a74, unk1a78, unk1a7c, unk1a80, unk1a84, unk1a88, unk1a8c, unk1a90, unk1a94, unk1a98, unk1a9c, unk1aa0,
        unk1aa4, unk1aa8, unk1aac, unk1ab0, unk1ab4, unk1ab8, unk1abc, unk1ac0, unk1ac4, unk1ac8, unk1acc, unk1ad0,
        unk1ad4, unk1ad8, unk1adc, unk1ae0, unk1ae4, unk1ae8, unk1aec, unk1af0, unk1af4, unk1af8, unk1afc, unk1b00,
        unk1b04, unk1b08, unk1b0c, unk1b10, unk1b14, unk1b18, unk1b1c, unk1b20, unk1b24, unk1b28, unk1b2c, unk1b30,
        unk1b34, unk1b38, unk1b3c, unk1b40, unk1b44, unk1b48, unk1b4c, unk1b50, unk1b54, unk1b58, unk1b5c, unk1b60,
        unk1b64, unk1b68, unk1b6c, unk1b70, unk1b74, unk1b78, unk1b7c, unk1b80, unk1b84, unk1b88, unk1b8c, unk1b90,
        unk1b94, unk1b98, unk1b9c, unk1ba0, unk1ba4, unk1ba8, unk1bac, unk1bb0, unk1bb4, unk1bb8, unk1bbc, unk1bc0,
        unk1bc4, unk1bc8, unk1bcc, unk1bd0, unk1bd4, unk1bd8, unk1bdc, unk1be0, unk1be4, unk1be8, unk1bec, unk1bf0,
        unk1bf4, unk1bf8, unk1bfc, unk1c00, unk1c04, unk1c08, unk1c0c, unk1c10, unk1c14, unk1c18, unk1c1c, unk1c20,
        unk1c24, unk1c28, unk1c2c, unk1c30, unk1c34, unk1c38, unk1c3c, unk1c40, unk1c44, unk1c48, unk1c4c, unk1c50,
        unk1c54, unk1c58, unk1c5c, unk1c60, unk1c64, unk1c68, unk1c6c, unk1c70, unk1c74, unk1c78, unk1c7c, unk1c80,
        unk1c84, unk1c88, unk1c8c, unk1c90, unk1c94, unk1c98, unk1c9c, unk1ca0, unk1ca4, unk1ca8, unk1cac, unk1cb0,
        unk1cb4, unk1cb8, unk1cbc, unk1cc0, unk1cc4, unk1cc8, unk1ccc, unk1cd0, unk1cd4, unk1cd8, unk1cdc, unk1ce0,
        unk1ce4, unk1ce8, unk1cec, unk1cf0, unk1cf4, unk1cf8, unk1cfc, unk1d00, unk1d04, unk1d08, unk1d0c, unk1d10,
        unk1d14, unk1d18, unk1d1c, unk1d20, unk1d24, unk1d28, unk1d2c, unk1d30, unk1d34, unk1d38, unk1d3c, unk1d40,
        unk1d44, unk1d48, unk1d4c, unk1d50, unk1d54, unk1d58, unk1d5c, unk1d60, unk1d64, unk1d68, unk1d6c, unk1d70,
        unk1d74, unk1d78, unk1d7c, unk1d80, unk1d84, unk1d88, unk1d8c, unk1d90, unk1d94, unk1d98, unk1d9c, unk1da0,
        unk1da4, unk1da8, unk1dac, unk1db0, unk1db4, unk1db8, unk1dbc, unk1dc0, unk1dc4, unk1dc8, unk1dcc, unk1dd0,
        unk1dd4, unk1dd8, unk1ddc, unk1de0, unk1de4, unk1de8, unk1dec, unk1df0, unk1df4, unk1df8, unk1dfc, unk1e00,
        unk1e04, unk1e08, unk1e0c, unk1e10, unk1e14, unk1e18, unk1e1c, unk1e20, unk1e24, unk1e28, unk1e2c, unk1e30,
        unk1e34, unk1e38, unk1e3c, unk1e40, unk1e44, unk1e48, unk1e4c, unk1e50, unk1e54, unk1e58, unk1e5c, unk1e60,
        unk1e64, unk1e68, unk1e6c, unk1e70, unk1e74, unk1e78, unk1e7c, unk1e80, unk1e84, unk1e88, unk1e8c, unk1e90,
        unk1e94, unk1e98, unk1e9c, unk1ea0, unk1ea4, unk1ea8, unk1eac, unk1eb0, unk1eb4, unk1eb8, unk1ebc, unk1ec0,
        unk1ec4, unk1ec8, unk1ecc, unk1ed0, unk1ed4, unk1ed8, unk1edc, unk1ee0, unk1ee4, unk1ee8, unk1eec, unk1ef0,
        unk1ef4, unk1ef8, unk1efc, unk1f00, unk1f04, unk1f08, unk1f0c, unk1f10, unk1f14, unk1f18, unk1f1c, unk1f20,
        unk1f24, unk1f28, unk1f2c, unk1f30, unk1f34, unk1f38, unk1f3c, unk1f40, unk1f44, unk1f48, unk1f4c, unk1f50,
        unk1f54, unk1f58, unk1f5c, unk1f60, unk1f64, unk1f68, unk1f6c, unk1f70, unk1f74, unk1f78, unk1f7c, unk1f80,
        unk1f84, unk1f88, unk1f8c, unk1f90, unk1f94, unk1f98, unk1f9c, unk1fa0, unk1fa4, unk1fa8, unk1fac, unk1fb0,
        unk1fb4, unk1fb8, unk1fbc, unk1fc0, unk1fc4, unk1fc8, unk1fcc, unk1fd0, unk1fd4, unk1fd8, unk1fdc, unk1fe0,
        unk1fe4, unk1fe8, unk1fec, unk1ff0;
    OpenNodes open;
    int unk1ff8, unk1ffc, unk2000, unk2004, unk2008, unk200c, unk2010, unk2014, unk2018, unk201c, unk2020, unk2024,
        unk2028, unk202c, unk2030, unk2034, unk2038, unk203c, unk2040, unk2044;
    SearchNode* best;
    SearchNode* current;
    int unk2050;
    bool yielding;
    SearchNode* StepSearch();
};
struct FUN_006f4640
{
    virtual ~FUN_006f4640();
    void FUN_008454f0(bool);
};
struct FUN_006f4690 : FUN_006f4640
{
    virtual ~FUN_006f4690();
};
FUN_006f4640::~FUN_006f4640()
{
    FUN_008454f0(true);
}
struct ObjRef
{
    ObjRef* Get() const;
};
struct NodePtr
{
    void* value;
    NodePtr(void* p = 0);
    ~NodePtr();
    NodePtr& operator=(void* p);
};
struct LoadTask;
struct TaskPtr
{
    LoadTask* value;
    TaskPtr(LoadTask* p = 0);
    ~TaskPtr();
    TaskPtr& operator=(LoadTask* p);
    operator LoadTask*() const;
};
struct MemScope
{
    int context;
    MemScope(int, bool, const char*, int);
    ~MemScope();
};
struct FUN_006f5160;
struct LoadTask
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void Start();
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
    LoadTask(FUN_006f5160*, ObjRef*, int, int, int, int, bool, int);
};
struct NodePtr_d0045cec0 : NodePtr
{
    NodePtr_d0045cec0(void* p = 0) : NodePtr(p)
    {}
    ~NodePtr_d0045cec0();
    using NodePtr::operator=;
};
struct FUN_006f5160
{
    ObjRef* owner;
    NodePtr_d0045cec0 node04, node08, node0c, node10, node14;
    TaskPtr task18, task1c;
    bool flag20, flag21, flag22, flag23, flag24;
    int value28;
    FUN_006f5160(ObjRef*, int, short, short, bool);
};
struct SceneRelease
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
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
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
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
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
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void slot2e();
    virtual void slot2f();
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
    virtual void Detach(void*);
};
struct OwnerRef
{
    SceneRelease* GetScene();
};
struct OwnerHandle
{
    OwnerRef* Get() const;
};
struct SceneHandle
{
    void* value;
    operator void*() const;
    SceneHandle& operator=(void*);
    ~SceneHandle();
};
struct QueueHandle
{
    void* value;
    operator void*() const;
    QueueHandle& operator=(void*);
    ~QueueHandle();
};
struct ReleaseGlobals
{
    bool FUN_005bb4d0();
};
extern ReleaseGlobals* g_osGlobals;
extern int DAT_011d8514;
void FUN_00c45830(void*);
void ReleasePending();
struct FUN_006f5370
{
    OwnerHandle* owner;
    SceneHandle scene04, scene08, scene0c, scene10, scene14;
    QueueHandle queue18, queue1c;
    void RunLoop();
    ~FUN_006f5370();
};
struct FUN_006f9060
{
    int unk;
    int unkCur;
    int unkValue;
    int unk0c;
    int uNewnk;
    int uTmpnk;
    int unk18;
    int unk1c;
    FUN_006f9060();
};
struct GlobalObject_00633c90
{
    void* object;
    GlobalObject_00633c90(int value);
    ~GlobalObject_00633c90();
    GlobalObject_00633c90& operator=(void* value);
    GlobalObject_00633c90& FUN_006e5cc0(const GlobalObject_00633c90& other);
};
struct WorldData
{
};
struct WorldPointer
{
    WorldData* FUN_00559450();
};
struct OwnerPointer
{
    WorldPointer* FUN_00559450();
};
struct FUN_006fa210;
struct FUN_006fb980
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void Start();
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
    bool active30;
    int x34;
    int y38;
    int lod3c;
    FUN_006fa210* owner40;
    WorldData* world44;
    void* node48;
    void* node4c;
    void* node50;
    void* node54;
    bool flag58;
    int unk5c;
    FUN_006fb980(FUN_006fa210*, WorldData*, int, int, int);
};
struct GlobalObject_00528cb0
{
    FUN_006fb980* object;
    GlobalObject_00528cb0(int value);
    ~GlobalObject_00528cb0();
    void FUN_006f74f0(FUN_006fb980* value);
    FUN_006fb980* FUN_00559450();
};
class AutoMemContext
{
    int previous;

  public:
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
};
extern const char DAT_0106e068[];
struct FUN_006fa210
{
    OwnerPointer* owner;
    GlobalObject_00633c90 node04, node08, node0c, node10, node14, node18;
    int state1c, state20;
    GlobalObject_00528cb0 queued;
    bool flag28, flag29, flag2a;
    GlobalObject_00633c90 node2c;
    FUN_006fa210(OwnerPointer* input, int lod, short x, short y);
};
class NiNode
{
  public:
    void IncRefCount();
    void DecRefCount();
    NiNode* FUN_004ea9a0();
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
    virtual void slot0A();
    virtual void slot0B();
    virtual void slot0C();
    virtual void slot0D();
    virtual void slot0E();
    virtual void slot0F();
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
    virtual void slot1A();
    virtual void slot1B();
    virtual void slot1C();
    virtual void slot1D();
    virtual void slot1E();
    virtual void slot1F();
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
    virtual void slot2A();
    virtual void slot2B();
    virtual void slot2C();
    virtual void slot2D();
    virtual void slot2E();
    virtual void slot2F();
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
    virtual void InsertChild(NiNode* child);
};
class QueuedFile
{
  public:
    void IncRefCount();
    void DecRefCount();
};
class BSAudio
{
  public:
    bool FUN_005bb4d0();
};
extern BSAudio* DAT_011dea0c;
extern int DAT_011d85ec;
void __cdecl FUN_00a61cd0();
void __cdecl FUN_00c45830(NiNode* node);
struct FUN_006fa420
{
    NiPointer<NiNode>* owner;
    NiPointer<NiNode> root;
    NiPointer<NiNode> node08;
    NiPointer<NiNode> node0C;
    NiPointer<NiNode> node10;
    NiPointer<NiNode> node14;
    NiPointer<NiNode> node18;
    int unk1C;
    int unk20;
    NiPointer<QueuedFile> queued;
    int unk28;
    NiPointer<NiNode> node2C;
    void FUN_006fa6a0();
    void FUN_006fb3d0(int flag);
    ~FUN_006fa420();
};
struct FUN_006e5cc0_Class
{
    void __thiscall FUN_006e5cc0(void* a1);
};
struct S006f4390_Node
{
    float m_key0;
    float m_key4;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    S006f4390_Node** m_link;
    S006f4390_Node* m_next;

    double __thiscall GetSum();
};
struct S006f4390_Map
{
    int m_hashSize;
    S006f4390_Node* m_buckets[20];

    int __thiscall GetScaledValue(S006f4390_Node* node);
    void __thiscall InsertNode(S006f4390_Node* node);
};
struct PathingRequestHelper
{
    PathingRequestHelper();
    virtual ~PathingRequestHelper();
    char _pad04[0xAC];
};
struct FUN_00438660
{
    FUN_00438660();
    ~FUN_00438660();
    int unk00[4];
};
struct FUN_0049f1c0
{
    FUN_0049f1c0();
    int unk00[4];
};
extern FUN_006815c0 DAT_011f426c;
struct FUN_006e4a50 : public PathingRequestHelper
{
    float m_fB0;
    float m_fB4;
    float m_fB8;
    float m_fBC;
    float m_fC0;
    int m_iC4;
    FUN_006815c0 m_kPosC8;
    FUN_006815c0 m_kPosD4;
    bool m_bE0;
    bool m_bE1;
    FUN_00438660 m_kE4;
    FUN_0049f1c0 m_kF4;
    int m_i104;
    int m_i108;

    FUN_006e4a50();
    virtual ~FUN_006e4a50();
};
struct FUN_006ffcf0
{
    unsigned int w00 : 32;
    unsigned int lo : 20;
    unsigned int mid : 4;
    unsigned int hi : 8;
    void SetPackedFields(long a1, int a2, int a3, int a4);
};
struct LockEC7E
{
    int unk00[2];
    void Lock(const char* pcName);
    void Unlock();
};
struct EntryEC7E
{
    bool InsertOrReplaceNode();
};
class FUN_006ec7e0_C
{
  public:
    int unk00[8];
    LockEC7E m_kLock;

    EntryEC7E* FUN_00449f80(void* a1, void* a2, void* a3, bool a4);
    bool FUN_006ec7e0(void* a1, void* a2, void* a3, bool a4);
};
struct NavMesh;
struct P3
{
    float x;
    float y;
    float z;
    P3();
    P3 operator-(const P3& rhs) const;
    P3 Cross(const P3& rhs) const;
    bool Eq(const P3& rhs);
};
struct NavMesh
{
    void FUN_0068f0c0(unsigned short tri, int edge, P3& a, P3& b);
    void FindAdjacentEdge(unsigned short tri, int edge, NavMesh*& outMesh, unsigned short& outTri, int& outEdge);
};
struct PathNode
{
    NavMesh* mesh;
    unsigned short tri;
    int edge;
};
struct PathNodeArray
{
    unsigned int Size();
    PathNode& GetAt(int i);
};
struct SearchNodeArray
{
    PathNode* GetAt(unsigned int i) const;
};
struct PointList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    P3** GetLast();
};
struct PathSmoother
{
    int unk00;
    int unk04;
    P3 m08;
    int unk14;
    int unk18;
    int unk1C;
    SearchNodeArray* m20;
    PathNodeArray* m24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    PointList m40;
    PointList m54;

    void FUN_006edbc0();
    void FUN_006edd30(P3& a, P3& b);
    void AddPathFromEdge(P3& p, unsigned int i);
    void AddPathFromContext(P3& p, unsigned int i);
    void CreateNavMeshEdges();
    void FUN_006ed850();
};
extern unsigned int DAT_010a2720;
void* __cdecl operator new(unsigned int size, void* place);
void __cdecl operator delete(void* object, void* place);
struct Allocator_006edc40
{
    void* __thiscall Allocate(unsigned int size, unsigned int flags);
    int __thiscall FUN_006815c0();
};
struct Object_006edc40
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    Object_006edc40(int value);
};
struct Host_006edc40
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    int unk18, unk1C, unk20, unk24, unk28, unk2C;
    Allocator_006edc40 allocator;
    void* __thiscall FUN_006edc40();
};
class SMPPoint
{
  public:
    float x, y, z;
    SMPPoint(float fX, float fY, float fZ);
    SMPPoint& operator+=(const SMPPoint& kOther);
    SMPPoint& operator/=(float fScalar);
    SMPPoint operator-(const SMPPoint& kOther) const;
    SMPPoint operator+(const SMPPoint& kOther) const;
    SMPPoint operator*(float fScalar) const;
    bool operator==(const SMPPoint& kOther) const;
    void Unitize();
    float Dot(const SMPPoint& kOther) const;
    float Length() const;
};
SMPPoint operator*(float fScalar, const SMPPoint& kPoint);
SMPPoint FUN_006ba550(const SMPPoint* pkA, const SMPPoint* pkB, const SMPPoint* pkBefore, const SMPPoint* pkAfter);
float FUN_00408840(float fValue);
struct SMPNode
{
    int unk00;
    int unk04;
    SMPPoint m_kPos;       // +0x08
    SMPPoint m_kSmoothed;  // +0x14
    SMPPoint m_kLeft;      // +0x20
    SMPPoint m_kRight;     // +0x2c
};
struct SMPNodeArray
{
    int FUN_0044ddc0();
    SMPNode*& FUN_00877a30(int iIndex);
};
struct SMPSide
{
    float FUN_0051b8e0();
};
class SMPPath
{
  public:
    int unk00;
    SMPSide* m_pkSide;       // +0x04
    SMPPoint m_kStartPoint;  // +0x08
    SMPPoint m_kEnd;         // +0x14
    int unk20[28];
    SMPNodeArray m_kNodeArray;  // +0x90

    void SmoothNodes();
};
class FUN_006f3140
{
  public:
    FUN_006f3140();
    virtual ~FUN_006f3140();

    int unk04;
    int unk08;
    int unk0C;
    void* m_pkHeap;
};
class FUN_006f2750 : public FUN_006f3140
{
  public:
    FUN_006f2750(unsigned int uiA, unsigned int uiB, void* pkHeap);
    virtual ~FUN_006f2750();
};
class LoadMember6F51
{
  public:
    virtual void v00();
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    int unk04[9];
};
class LoadHolder6F51
{
  public:
    unsigned int m_uiValue1;
    LoadMember6F51 m_kMember;
    TESObjectREFR* m_pReference;

    void FUN_006f5100(BGSLoadFormBuffer* apBuffer);
};
class FUN_006fca40
{
  public:
    ~FUN_006fca40();
    int unk0;
};
class FUN_005e04f0
{
  public:
    ~FUN_005e04f0();
    int unk[4];
};
class FUN_006fc980
{
  public:
    int unk0;
    FUN_006fca40* m_pData;
    NiPointer<NiNode> m_spA;
    NiPointer<NiNode> m_spB;
    int unk10[7];
    FUN_005e04f0 m_kList;
    ~FUN_006fc980();
};
struct EventArg6FF
{
    unsigned __int64 m_uiKey;
    int m_iType;
};
class Owner6FF
{
  public:
    int unk00[15];
    char unk3C;
    bool m_bFlag;
    char unk3E[2];
    unsigned int m_uiKey;

    void OnEvent(EventArg6FF* pkArg);
};
struct SteamParam
{
    unsigned __int64 unk00;
};
struct C006ff8f0
{
    char unk00[0x40];
    unsigned int unk40;

    void FUN_006ff8f0(SteamParam* a1);
};
struct ThreadOwner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual bool IsOwnerThread(unsigned long id);
};
ThreadOwner* __cdecl FUN_00b00a00();
unsigned long __cdecl FUN_0040fc90();
struct PathSearch : public Search
{
    bool CopyNodeListToArrays(SearchNode* node, int a, int b);
    bool FindPath(int a, int b, bool useBest);
};
class FUN_006e0f90_base
{
  public:
    virtual ~FUN_006e0f90_base();
    int unk04;
};
class FUN_006e0f90_cls : public FUN_006e0f90_base
{
  public:
    virtual ~FUN_006e0f90_cls();
    void unk08();
};
// @fnv 0x006e20b0
struct FUN_006e20b0 : NiTPointerMap<unsigned int, unsigned int>
{
    virtual ~FUN_006e20b0();
};
FUN_006e20b0::~FUN_006e20b0()
{}
struct FUN_006e3ab0
{
    ~FUN_006e3ab0();
};
struct FUN_006e3c60 : public FUN_006e3ab0
{
    virtual ~FUN_006e3c60();
};
// FUN_006e3f10 (0x006e3f10, 8 bytes): `sub ecx,0x10 ; jmp FUN_006e3a50`
// This is a compiler-generated adjustor thunk: the second base of a multiply
// inherited class sits 0x10 bytes into the object, so the slot inherited from
// that base has to move `this` back to the start of the derived object before
// jumping to the implementation of the overridden virtual.
struct PrimaryBase
{
    virtual void FUN_006e3f10();
    int unk04;
    int unk08;
    int unk0C;
};
struct SecondaryBase
{
    virtual void FUN_006e3f10();
};
struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x006e3f10
    virtual void FUN_006e3f10();
};
Derived::Derived()
{}
void __cdecl operator delete(void*, void*);
struct FUN_006ec130_Local
{
    FUN_006ec130_Local();
    ~FUN_006ec130_Local();
    int m_iOwnerObjectOffset;
    int m_uiContentCount;
};
struct FUN_006ec130_Base
{
    int m_unk00;
    int m_unk04;
    virtual ~FUN_006ec130_Base();
};
struct FUN_006ec130 : FUN_006ec130_Base
{
    bool FUN_006ec390(void* item);
    virtual ~FUN_006ec130();
};
struct FUN_006eca20
{
    virtual ~FUN_006eca20();
};
struct Arr2_006e9e20
{
    ~Arr2_006e9e20();
};
struct FUN_006eca50 : Arr2_006e9e20
{
    virtual ~FUN_006eca50();
};
int __cdecl FUN_0043b460(long volatile* a1, long a2, long a3);
void FUN_0040fbe0();
struct NodeX
{
    int unk00;
    int unk04;
    NodeX* pNext;
};
struct QueueX
{
    int unk00;
    long volatile lLock;
    NodeX* pHead;
    bool FUN_006ecd60(NodeX** ppOut);
};
struct FUN_006ecf70
{
    virtual ~FUN_006ecf70();
};
struct FUN_006f27f0_Class
{
    virtual ~FUN_006f27f0_Class();
};
struct FUN_006f2810 : FUN_006f27f0_Class
{
    const char* m_p;
    ~FUN_006f2810();
};
struct Base006f2e00
{
    virtual ~Base006f2e00();
};
struct FUN_006f2e40 : Base006f2e00
{
    virtual ~FUN_006f2e40();
    void FUN_008454f0(int value);
};
struct FUN_006f3320_Arr16Helper
{
    void __thiscall ConstructBounds(void* a1, int a2);
};
struct FUN_006f3320_Fields
{
    void* m_pBuffer;
    int m_bufferPosition;
    int m_iBufferSize;
};
struct FUN_006f3320_VTable
{
    virtual void FUN_006f3320_Alloc0();
    virtual void* FUN_006f3320_Alloc(int a1);
};
// NiTMap destructor: remove all entries, then the base map destructor frees the hash table.
class F9940MapBase
{
  public:
    virtual ~F9940MapBase();
    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};
class FUN_006f9940 : public F9940MapBase
{
  public:
    virtual ~FUN_006f9940();
};
#include <stdio.h>
// Unregisters this object's Steam callback (GalaxyWrp.dll import).
extern "C" __declspec(dllimport) void __cdecl SteamAPI_UnregisterCallback(void* pCallback);
struct PathingRequest
{
    virtual ~PathingRequest();
    PathingRequest();
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
    float unk68;
    float unk6c;
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
};
struct PtB006815c0
{
    float x, y, z;
    PtB006815c0();
};
struct FUN_006e4080 : PathingRequest
{
    PtB006815c0 pointb0;
    float unkbc, unkc0, unkc4;
    int unkc8;
    bool unkcc, unkcd, unkce, unkcf, unkd0, unkd1;
    PtB006815c0 pointd4, pointe0;
    FUN_006e4080();
    virtual ~FUN_006e4080();
};
extern const float DAT_0104e0e8, DAT_0101e704, DAT_0101e6ec, DAT_010236e0;
struct QueueDeletingView : public FUN_006ec1e0_Class
{
    void* __thiscall FUN_006ec230(unsigned int flags);
};

struct SteamUserObj
{
    virtual void v0();
    virtual bool v1();
};

// @fnv 0x006ff820
bool FUN_006ff690::FUN_006ff820()
{
    if (initialized)
    {
        if (SteamUser())
        {
            return ((SteamUserObj*)SteamUser())->v1();
        }
    }
    return false;
}
