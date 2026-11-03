
// src/staging/blk_00aa0000_od_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/staging/blk_00aa0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00aa0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
extern "C" void* __cdecl _malloc(unsigned int);
struct FUN_00aa4290_Class
{
    void* __thiscall AllocateBuffer(unsigned int size, unsigned int pad);
};
extern "C" void __cdecl free(void*);
struct FUN_00aa42c0_class
{
    void __thiscall FreePointer(void* p, int dummy);
};
struct FUN_00aa4790_Class
{
    void __thiscall FUN_00aa4710(int, unsigned char, int);
    void __thiscall FUN_00aa4790(int a, int b, int c);
};
void SetByteAtOffset(char* p, char c);
struct FUN_00aa4c10_class
{
    void __thiscall FUN_00aa4c10(int arg);
};
extern "C" void __cdecl FUN_00aa4be0(int);
extern "C" void __cdecl SetByteAtOffset(int, int);
struct FUN_00aa4c40_class
{
    void __thiscall FUN_00aa4c40(int a);
};
extern "C" void* DAT_010a2708;
struct FUN_00aa4c60_class
{
    void* m_p;
    void* FUN_00aa4c60();
};
struct AbstractHeapLogger
{
    void FUN_00aa4ce0();
};
extern AbstractHeapLogger* DAT_011f6388;
extern MemoryPool* DAT_011f67b8[];
struct FUN_00aa6950_Class
{
    void __thiscall ClearPoolSlot(unsigned int a);
};
struct FUN_00aa7e50_Class
{
    int m0;
    int m4;
    int GetM4();
};
extern int DAT_010a29c0;
struct BSThread
{
    BSThread();
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
struct FUN_00aa8410 : BSThread
{
    FUN_00aa8410();
};
extern int DAT_010a29b0;
struct FUN_00aa8a00_cls
{
    int* m;
    void FUN_00aa8a00();
};
extern int DAT_010a2980;
struct FUN_00aa8a20_class
{
    void FUN_00aa8a20();
};
struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;
struct FUN_00aa8b00_Class
{
    void* __thiscall FUN_00aa8b00();
};
void __cdecl FNV_Warning(const char* fmt, ...);
void __cdecl ReportFr2Error(const char* a, int b, const char* c);
struct FUN_00aa41e0_Class
{
    void* __thiscall FUN_00aa41e0(unsigned int a, unsigned int b);
};
struct FUN_00aa41f0_Class
{
    void __thiscall FUN_00aa41f0(int a, int b, int c);
};
struct FUN_00aa45a0_vt
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool v4(int);
};
struct FUN_00aa45a0_Class
{
    unsigned short m_auiShapeKeys;
    unsigned short m_uiItemCount;
    unsigned int m_unknown;
    FUN_00aa45a0_vt** m_items;
    FUN_00aa45a0_vt* __thiscall FindItemByArg(int arg);
};
struct FUN_00aa46a0_holder
{
    void* __thiscall GetEntryAt(unsigned int a);
};
struct FUN_00aa4710_Class
{
    char __thiscall FUN_00aa4710(int a, unsigned char b, int c);
};
struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
struct FUN_00aa4b20_Class
{
    void __thiscall ClearAndDeallocate(void* p);
};
struct FUN_00aa50f0_Class
{
    void __thiscall FUN_00aa50f0(unsigned int a);
};
struct FUN_00aa8b80_class
{
    void* m0;
    void* m4;
    void* m8;
    int mC;
    void __thiscall AppendBlock(void* block);
};
struct FUN_00aa8c40_N
{
    FUN_00aa8c40_N* next;
    FUN_00aa8c40_N* prev;
};
struct FUN_00aa8c40_H
{
    int pad0;
    FUN_00aa8c40_N* head;
    FUN_00aa8c40_N* tail;
    unsigned int count;
    void PushFront(FUN_00aa8c40_N* n);
};
struct FUN_00aa9d20_Class
{
    void __thiscall FUN_00aa9d20(int arg);
};
struct FUN_00aaa6d0_Class
{
    void* __thiscall FUN_00aaa6d0();
};
struct FUN_00aaa6e0_Class
{
    int m0;
    int m4;
    void __thiscall SetFlags(unsigned int flags, int unused);
};
extern int DAT_010a2618;
void* __cdecl _fnv_zlib_memset(void* dst, int val, unsigned int len);
struct FUN_00aa47e0_Class
{
    int m0;
    int m4;
    void* m8;
    int mC;
    FUN_00aa47e0_Class* __thiscall FUN_00aa47e0(unsigned int count);
};
struct FUN_00aba370_s
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    void __thiscall EraseRange(unsigned int a, unsigned int b);
    void __thiscall AppendChars(unsigned int a, unsigned char b);
    void __thiscall FUN_00aba370(unsigned int pos, unsigned char b);
};
extern unsigned int DAT_010173f0;
void __cdecl FUN_00ec7c56();
struct FUN_00abbeb0_Class
{
    int m0;
    int m4;
    int m8;
    unsigned int mC;
    unsigned int m10;
    FUN_00abbeb0_Class* FUN_00abbeb0(unsigned int size, FUN_00abbeb0_Class* p);
};
void FUN_00ec7c56();
struct FUN_00abbf00_Class
{
    int m0;
    int m4;
    char Matches(FUN_00abbf00_Class* other);
};
struct FUN_00aa4760_Class : public FUN_00aa4710_Class
{
    char CallBaseWithOffset(int a, unsigned char b, int c);
};
unsigned char __cdecl FUN_00aa4be0(char* p);
struct FUN_00aa4ca0_class
{
    void __thiscall FUN_00aa4ca0(unsigned int a, unsigned int b, float c, unsigned int d, unsigned int e);
};
struct FUN_00aa5fc0_Class
{
    int __thiscall ClearFields();
};
struct FUN_00aa6920_Class
{
    void __thiscall RegisterInPool(unsigned int index);
};
struct FUN_00aa8a40_vt
{
    virtual void v0();
    virtual void* v1();
};
struct FUN_00aa8a40_Node
{
    int pad0;
    int pad4;
    int pad8;
};
struct FUN_00aa8a40_Class
{
    FUN_00aa8c40_H m_kNode;
    void __thiscall FUN_00aa8a40(FUN_00aa8a40_Node* node);
};
struct HeapFreeBlock
{
};
struct HeapFreeList
{
    void* m0;
    HeapFreeBlock* m4;
};
struct AbstractHeap
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
    virtual void v13(void* value);

    unsigned char m_pad00[0x10];
    int m14;
    unsigned char m_pad18[0x18];
    void* m30;
    unsigned char m_pad34[0x10];
    HeapFreeList m_lists[0x400];
    unsigned char m_pad2044[4];
    HeapFreeBlock* m2048;
    HeapFreeBlock* m204c;

    void __thiscall FUN_00aa9e50(HeapFreeList* list, HeapFreeBlock* block);
    void __thiscall Clear();
};
struct FUN_00aaaa80_Class
{
    void* __thiscall FUN_00aaaa80();
    void* __thiscall DestroyWithFlags(unsigned int flags);
};
struct FUN_00ab2e70
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    FUN_00ab2e70();
    ~FUN_00ab2e70();
};
struct FUN_00ab2e40
{
    int m0;
    int m4;
    int m8;
    int mC;
    FUN_00ab2e70 m10[3];
    FUN_00ab2e40();
};
class AA4610Pool
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual bool Contains(void* pvMem);
};
class AA4610Allocator
{
  public:
    int unk00;
    unsigned short m_usPoolCount;
    unsigned short unk06;
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
    AA4610Pool** m_ppkPools;

    AA4610Pool* FindPoolContaining(void* pvMem);
};
extern unsigned int DAT_011f69f8;
void* FUN_00aa4960(unsigned int size);
struct FUN_00aa4ae0_Class
{
    int* unk00;
    int unk04;
    void* unk08;
    void ResetAndFree();
};
extern int DAT_010a2618;
extern MemoryManager DAT_011f6238;
extern MemoryManager DAT_011f6238;
struct FUN_00aa4bb0_Class
{
    void FUN_00aa4a60();
    int __thiscall FUN_00aa4bb0(int arg);
};
struct FUN_00aa4bb0_Local
{
    int unk00;
    int unk04;
    int unk08;
};
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(__int64* frequency);
extern double DAT_01017b70;
extern float DAT_011ac39c;
void __cdecl InitPerformanceFrequency(void);
struct ScrapHeapEntry
{
    void* m_pBuffer;
    unsigned int m_iElementCount;
};
struct ScrapHeapManager
{
    ScrapHeapEntry m_entries[64];
    unsigned int m_uiItemCount;
    unsigned int m_totalSize;
    void RemoveEntry(unsigned int index);
};
struct FUN_00aa5ff0_Class
{
    unsigned int m_uiItemCount;
    unsigned int m_uiThreadId;

    void __thiscall FUN_00aa5ff0();
};
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long);
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long* destination, long exchange,
                                                                           long comparand);
struct FUN_00aa6330_Class
{
    int unk0;
    unsigned int unk4;
    bool IsCurrentThread();
};
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void*, unsigned int, unsigned int);
struct FUN_00aa6680_class
{
    unsigned int unk00;
    void* allocation;
    void __thiscall FreeAllocation();
};
struct LinkedNode
{
    LinkedNode* previous;
    LinkedNode* next;
};
struct NodeSorter
{
    LinkedNode* SortList(LinkedNode* head);
};
struct MemoryPool
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
    void Lock(char*);
    void FUN_00aa7260();
};
extern MemoryPool* DAT_011f67b8[];
extern char DAT_010a2850;
void FUN_00aa7290(int idx);
extern int DAT_011f6bec;
extern int DAT_011f6bd4;
typedef void(__stdcall* FUN_00fdf054_t)(void*);
typedef void(__stdcall* FUN_00fdf05c_t)(void*);
typedef void(__stdcall* FUN_00fdf100_t)(void*);
extern FUN_00fdf054_t DAT_00fdf054;
extern FUN_00fdf05c_t DAT_00fdf05c;
extern FUN_00fdf100_t DAT_00fdf100;
int __cdecl FUN_00ec658f(void(__cdecl*)(void));
void __cdecl FUN_00fdb2b0(void);
struct FUN_00aa7300_Obj
{
    void FUN_00aa7300();
};
void FUN_00aa7370(void);
extern "C" void(__stdcall* DAT_00fdf05c)(void*);
extern "C" void(__stdcall* DAT_00fdf100)(void*);
extern "C" void(__stdcall* DAT_00fdf1b4)(void*, int, int);
extern "C" void(__stdcall* DAT_00fdf1c0)(void*);
extern "C" void* DAT_011f6bfc;
extern "C" void* DAT_011f6bf4;
struct BlockSource
{
    virtual void v0();
    virtual void* v1();
};
extern "C" BlockSource* DAT_011f6c00;
struct BlockHolder
{
    void* m0;
    void* m4;
};
struct AllocBlock
{
    void* m0;
    void* m4;
    int m8;
    int mC;
};
struct FUN_00aa8b80_class;
void __cdecl SetBlockValue(int arg);
struct FUN_00aa8be0_cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2(void* item);
    void* m_04;
    void* m_08;
    void* m_0c;
    void __thiscall ClearList();
};
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* cs);
extern "C" char DAT_010a28c8;
extern "C" char DAT_010a2bbc;
struct FUN_00aa8ca0_cls
{
    void* m_vtbl;
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

    FUN_00aa8ca0_cls* FUN_00aa8ca0(int a1, int a2, int a3, int a4);
};
extern "C" void __cdecl FUN_00ec61c0(void* p, int value, unsigned int size);
extern "C" void __stdcall FUN_00eccec5(int code);
struct FUN_00aa8dd0_slot
{
    int m_flag;
    char* m_ptr;
};
struct FUN_00aa8dd0_cls
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
    virtual int v12(void* a, int b);

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* m_14;
    int unk18;
    int m_1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int m_30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    unsigned char m_buf44[0x2000];
    char* m_2044;
    unsigned char m_buf2048[8];
    int unk2050;
    int unk2054;
    FUN_00aa8dd0_slot m_slots[16];

    void InitializeSlots();
};
struct FUN_00aa9d00_cls
{
    int unk00;
    void FUN_00aa9d00();
};
struct FUN_00aaa720_cls
{
    int unk00;
    void FUN_00aaa720();
};
struct FrameBlock40
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
};
struct FUN_00aaab30_base
{
    virtual ~FUN_00aaab30_base();
};
struct FUN_00aaab30_cls : FUN_00aaab30_base
{
    void unk04();
    virtual ~FUN_00aaab30_cls();
};
struct S_00aadd20_Vector
{
    float x;
    float y;
    float z;
    float w;
};
S_00aadd20_Vector* __cdecl FUN_00aadd20(S_00aadd20_Vector* out, S_00aadd20_Vector* in);
struct FUN_00aadda0_Class
{
    void __thiscall BuildScaledValues(int a, float b);
    int __thiscall FUN_00aadda0(int a, float b);
};
// Candidate: FUN_00aafa30
struct FlagBox
{
    unsigned char v;
};
void __cdecl FUN_00aafa80(int a0, int a1, int a2, int a3, unsigned char f4, unsigned char f5);
void __cdecl FUN_00aafa30(int a0, int a1, int a2, int a3);
struct FUN_00aafbd0_cls
{
    int unk00;
    void __thiscall FUN_00aafbd0();
};
struct FUN_00ab2630_cls
{
    int unk00;
    void FUN_00ab2630();
};
struct FUN_00ab46e0_cls
{
    int unk00;
    void FUN_00ab46e0();
};
// ---------------------------------------------------------------------------
// FUN_00abaf60 - pick one of two range handles out of a container.
//
// The container keeps a base pointer (m_pBase) and the byte offsets of the
// first and of the one-past-the-last element of an array of eight byte
// elements (m_i0c / m_i10).  A range handle is a pair of that base pointer
// and the byte offset of an element inside the array.
//
// The function gets two such handles (a and b) and copies the first one out
// through pOut.  Both handles are checked against the range of the container
// and are compared with each other; only when the two offsets are equal the
// new end of the container is computed and stored back.
//
// The build is unoptimised (/Od), so every value lives in its own frame slot.
// The names of the locals below are chosen so that the frame slots land on
// the offsets of the original (the compiler sorts the locals of an /Od frame
// by a hash of their name).
// ---------------------------------------------------------------------------
// A range handle: the base of the array and the byte offset of an element.
struct FnvAbaf60Iter
{
    void* m_pBase;
    unsigned int m_uiPosition;
    bool __thiscall FUN_00ac0460(FnvAbaf60Iter* pOther);
};
// A scratch block of 48 bytes.  Only its first two bytes are touched.
struct FnvAbaf60Block
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
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
// The container the range handles belong to.
struct FnvAbaf60Owner
{
    void* m_pBase;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    FnvAbaf60Iter* __thiscall FUN_00abaf60(FnvAbaf60Iter* pOut, FnvAbaf60Iter a, FnvAbaf60Iter b);
};
// The helper that turns two offsets into the offset of the element behind the
// last one of the range.
int __cdecl FUN_00ac12d0(int nFirst, int nLast, int nExtra);
unsigned int __cdecl FUN_00ac13c0(unsigned int b, unsigned int end, unsigned int a);
struct FUN_00abc180_Pair
{
    void* p;
    unsigned int i;
    bool Compare(FUN_00abc180_Pair* other);
};
struct FUN_00abc180_Tmp
{
    unsigned int f0;
    unsigned int f4;
    unsigned int f8;
    unsigned char fC;
    unsigned char fD;
};
struct FUN_00abc180_Pad
{
    unsigned int g00, g04, g08, g0C, g10, g14, g18, g1C;
};
struct FUN_00abc180_cls
{
    void* m0;
    unsigned int m4;
    unsigned int m8;
    unsigned int mC;
    unsigned int m10;
    FUN_00abc180_Pair FUN_00abc180(unsigned int x, unsigned int a, unsigned int y, unsigned int b);
};
extern "C" void __cdecl FUN_00ac0b00(void);
extern "C" unsigned int* __cdecl FUN_00ac1720(unsigned int count, unsigned int zero);
struct FUN_00abc260_frame
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
};
struct FUN_00abc260_cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int* m_0c;
    unsigned int* m_10;
    unsigned int* m_14;
    bool FUN_00abc260(unsigned int count);
};
struct FUN_00aa6650_Class
{
    bool __thiscall FreeMemory(unsigned int size, void* p);
};
struct FUN_00aa7300_node
{
    int m_00;
    FUN_00aa7300_node* m_04;
};
struct FUN_00aa7300_pool
{
    int m_00;
    int m_04;
    void Lock(const char* name);
};
class FUN_00aa7300_cls
{
  public:
    int m_00;
    int m_04;
    FUN_00aa7300_node* m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    FUN_00aa7300_pool m_20;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    unsigned int m_40;

    void FUN_00aa7300();
};
struct CounterA
{
    long count;
    void* event;
};
struct NodeA
{
    NodeA* next;
    NodeA* prev;
    void* value;
};
struct JobA
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    CounterA* completion;
};
struct QueueA
{
    virtual void v0();
    virtual NodeA* Allocate();
    void AppendBlock(NodeA* node);
};
struct PoolA
{
    virtual void v0();
    virtual NodeA* Allocate();
    virtual void FreeNode(NodeA* node);
    CounterA* FUN_00aa8a80();
    void PushFront(NodeA* node);
};
extern "C" void(__stdcall* DAT_00fdf1c4)(void*);
extern "C" void(__stdcall* DAT_00fdf1c8)(void*, int);
extern PoolA* DAT_011f6c04;
void __cdecl CompleteJob(JobA* job);
struct S_0044a730_Class
{
    void FUN_0044a730(int a, int b);
};
struct S_00aba220_Class
{
    int unk00;
    float unk04;
    float unk08;
    float unk0c;
    S_0044a730_Class unk10;

    S_00aba220_Class* FUN_00aba220();
};
struct FUN_00aa6800_class
{
    void __thiscall FUN_00aa6800();
};
void __cdecl DestroyMemoryPools();
extern unsigned int DAT_010173f0;
extern "C" void __cdecl _Xlen(void);
class S_00aadeb0_Class
{
  public:
    unsigned int m_00;
    char* m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;

    S_00aadeb0_Class* AppendChars(unsigned int count, unsigned char ch);
};
struct S_00aae180_Class
{
    void __thiscall FUN_00aae180(unsigned int pos, unsigned int count, unsigned char ch);
};
struct S_0044a8d0_Class
{
    bool __thiscall FUN_0044a8d0(unsigned int newSize, int reserve);
};
struct S_00aadeb0_pad
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};

struct HeapBlockBase
{
    HeapBlockBase()
    {}
    ~HeapBlockBase();
    virtual void v00();
};

struct HeapBlockLink
{
    int m_00;
    int m_04;
    HeapBlockLink() : m_00(0), m_04(0)
    {}
};

struct FUN_00aa7400 : HeapBlockBase
{
    unsigned int m_04;
    unsigned int m_08;
    void* m_0c;
    void* m_10;
    int m_14;
    int m_18;
    int m_1c;
    HeapBlockLink m_20;
    FUN_00aa7400(unsigned int a, unsigned int b);
    virtual void v00();
};

// @fnv 0x00aa7400
FUN_00aa7400::FUN_00aa7400(unsigned int a, unsigned int b) : m_04(a), m_08(b), m_14(0)
{
    m_0c = ((FUN_00aa4290_Class*)&DAT_011f6238)->AllocateBuffer(a, 1);
    m_10 = m_0c;
}

struct AA74C0Base
{
    virtual ~AA74C0Base()
    {}
};

struct FUN_00aa74c0 : AA74C0Base
{
    int m_04;
    int m_08;
    void* m_0c;
    virtual ~FUN_00aa74c0();
};

// @fnv 0x00aa74c0
FUN_00aa74c0::~FUN_00aa74c0()
{
    ((FUN_00aa42c0_class*)&DAT_011f6238)->FreePointer(m_0c, 1);
}

// The supplied unit has incompatible Win32 prototypes, so retain its pointer-erased ABI.
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void*);
struct ShutdownMessage
{
    unsigned int flags;
    unsigned int type;
    void* data;
    unsigned int length;
    void* auxiliary;
    unsigned int references;
    void* owner;
    ShutdownMessage() : flags(0), type(0), length(0), references(0)
    {}
};
void __cdecl SetBlockValue(ShutdownMessage*);
struct ShutdownWorker
{
    virtual ~ShutdownWorker();
    void StopAndCloseHandle();
};
struct ShutdownObject
{
    virtual ~ShutdownObject();
};
struct ShutdownHandle
{
    volatile long count;
    void* handle;
    unsigned int state;
    void Wait()
    {
        WaitForSingleObject(handle, 0xffffffffUL);
        InterlockedDecrement(&count);
    }
    ~ShutdownHandle()
    {
        CloseHandle(handle);
    }
    static void operator delete(void* p)
    {
        DAT_011f6238.Deallocate(p);
    }
    static void operator delete[](void* p)
    {
        DAT_011f6238.Deallocate(p);
    }
};
struct ShutdownCriticalSection
{
    ~ShutdownCriticalSection()
    {
        DeleteCriticalSection(this);
    }
    static void operator delete(void* p)
    {
        DAT_011f6238.Deallocate(p);
    }
};
extern ShutdownWorker* DAT_011f6bf0;
extern ShutdownHandle* DAT_011f6bf8;
extern ShutdownHandle* DAT_011f6c08;
// @fnv 0x00aa81d0
void __cdecl FUN_00aa81d0()
{
    ShutdownMessage message;
    message.type = 4;
    SetBlockValue(&message);
    DAT_011f6bf8->Wait();
    DAT_011f6bf0->StopAndCloseHandle();
    delete DAT_011f6bf0;
    DAT_011f6bf0 = 0;
    delete[] DAT_011f6c08;
    DAT_011f6c08 = 0;
    delete reinterpret_cast<ShutdownObject*>(DAT_011f6c04);
    DAT_011f6c04 = 0;
    delete reinterpret_cast<ShutdownObject*>(DAT_011f6c00);
    DAT_011f6c00 = 0;
    delete reinterpret_cast<ShutdownCriticalSection*>(DAT_011f6bfc);
    DAT_011f6bfc = 0;
    delete DAT_011f6bf8;
    DAT_011f6bf8 = 0;
    delete reinterpret_cast<ShutdownHandle*>(DAT_011f6bf4);
    DAT_011f6bf4 = 0;
}

extern MemoryManager DAT_011f6238;
extern int DAT_010a29a0;

struct Guard
{
    int m0;
    int m1;
    Guard()
    {}
    ~Guard()
    {}
};

struct Derived
{
    void* m_vtbl;
    void __thiscall ClearList();
    void* FUN_00aa88d0(unsigned int flags);
};

// @fnv 0x00aa88d0
void* Derived::FUN_00aa88d0(unsigned int flags)
{
    m_vtbl = &DAT_010a29a0;
    {
        Guard guard;
        this->ClearList();
    }
    m_vtbl = &DAT_010a29b0;
    if (flags & 1)
        DAT_011f6238.Deallocate(this);
    return this;
}

void __cdecl ReportAssertionViolation(const char*, int);
inline MemoryManager* GetMemoryManager()
{
    return &DAT_011f6238;
}
inline void ReleaseAllocation(void* p)
{
    GetMemoryManager()->Deallocate(p);
}
struct AllocatorStub
{
    int unk00;
    void deallocate(void* p, unsigned int n)
    {
        ReleaseAllocation(p);
    }
};
struct DestroyTag
{
};
inline DestroyTag FUN_0065e750(float**, float**)
{
    return DestroyTag();
}
inline void DestroyRange(float*, float*, AllocatorStub*, DestroyTag)
{}
inline void CallInterfaceWithResult(float* first, float* last, AllocatorStub* allocator)
{
    DestroyTag tag = FUN_0065e750(&first, &last);
    DestroyRange(first, last, allocator, tag);
}
struct MarkerType
{
    ~MarkerType()
    {}
};
struct StorageCore : MarkerType
{
    void* m_data;
    AllocatorStub allocator;
    AllocatorStub allocator8;
    float* begin;
    float* end;
    float* capacity;
    int unk18, unk1c;
    ~StorageCore()
    {
        allocator.deallocate(m_data, 1);
    }
};
struct StorageWrapper : StorageCore
{
    ~StorageWrapper()
    {}
};
struct ClearStorage : StorageWrapper
{
    void FUN_0065f2b0(float* first, float* last)
    {
        CallInterfaceWithResult(first, last, &allocator8);
    }
    void FUN_0065f240()
    {
        if (begin)
        {
            FUN_0065f2b0(begin, end);
            allocator8.deallocate(begin, capacity - begin);
        }
        begin = 0;
        end = 0;
        capacity = 0;
    }
    ~ClearStorage()
    {
        FUN_0065f240();
    }
};
struct TmpArr : ClearStorage
{
    TmpArr operator*(float f);
    ~TmpArr()
    {}
};
struct Curve20
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    TmpArr Transpose();
};
struct Out40
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
    void operator=(const TmpArr&);
};
struct Entry48
{
    Curve20 curves[2];
    float scale;
    int unk44;
};
struct Row168
{
    Entry48 entries[5];
};
struct Mixer
{
    bool m_enabled;
    char unk01, unk02, unk03;
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
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    Row168 rows[5];
    float FUN_00aacdb0(int a, int b, Out40* out);
    void FUN_00aacf40(int a, int b, float t, Out40* out);
};
// @fnv 0x00aacf40
void Mixer::FUN_00aacf40(int a, int b, float t, Out40* out)
{
    a < 5 ? (void)0
          : ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\FanControls.cpp", 0x1d4);
    b < 5 ? (void)0
          : ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\FanControls.cpp", 0x1d5);
    a != b ? (void)0
           : ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\FanControls.cpp", 0x1d6);
    if (!m_enabled)
        return;
    {
        float f = (t - FUN_00aacdb0(a, b, out)) * rows[a].entries[b].scale;
        for (unsigned int i = 0; i < 2; i++)
            out[i] = rows[a].entries[b].curves[i].Transpose() * f;
    }
}

void ReportAssertionViolation(const char*, int);
struct CleanupBase
{
    __forceinline ~CleanupBase()
    {}
};
struct ImageAllocation
{
    void* data;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
};
struct MemoryBlockHeader : CleanupBase
{
    void* data;
    int unk04;
    __forceinline ~MemoryBlockHeader()
    {
        ImageAllocation block;
        block.data = data;
        DAT_011f6238.Deallocate(block.data);
    }
};
struct Storage : MemoryBlockHeader
{
    __forceinline ~Storage()
    {}
};
struct ImageData : Storage
{
    int unk08, unk0c, unk10, unk14, unk18, unk1c;
    void FUN_0065f240();
    __forceinline ~ImageData()
    {
        FUN_0065f240();
    }
};
struct Image : ImageData
{
    __forceinline ~Image()
    {}
    Image BuildScaledValues(float);
    Image operator+(const Image&);
    Image& operator=(const Image&);
};
struct ImagePair
{
    Image images[2];
};
struct ControlSet
{
    Image images[5];
};
struct FanControls
{
    bool enabled;
    ControlSet controls[5];
    void FUN_00aad890(int index, ImagePair* input);
};
// @fnv 0x00aad890
void FanControls::FUN_00aad890(int index, ImagePair* input)
{
    if (index < 5)
    {
    }
    else
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\FanControls.cpp", 629);
    if (!enabled)
        return;
    for (unsigned int channel = 0; channel < 2; ++channel)
    {
        input[channel].images[1] = input[channel].images[1].BuildScaledValues(-1.0f);
        input[channel].images[0] = controls[index].images[channel].BuildScaledValues(2.0f) + input[channel].images[0];
    }
}

struct ShortPoint
{
    short x, y, z;
};
struct CopyTag
{
};
struct RangeTag
{
};
struct PointAlloc
{
    int state;
    void construct(ShortPoint*, const ShortPoint&);
    void destroy(ShortPoint* _Ptr)
    {
        _Ptr->~ShortPoint();
    }
    void deallocate(ShortPoint* _Ptr, unsigned int _Count)
    {
        DAT_011f6238.Deallocate(_Ptr);
    }
};
struct VectorMessage
{
    int iteratorHead;
    union
    {
        char buffer[16];
        char* data;
    } storage;
    unsigned int length;
    unsigned int reserved;
    VectorMessage(const char*);
    ~VectorMessage();
};
struct VectorLengthError
{
    virtual ~VectorLengthError() throw();
    const char* whatText;
    bool ownsText;
    VectorMessage message;
    VectorLengthError(const VectorMessage&);
};
inline void ThrowVectorTooLong()
{
    throw VectorLengthError(VectorMessage("vector<T> too long"));
}
struct VectorBadAlloc
{
    virtual ~VectorBadAlloc() throw();
    const char* message;
    bool ownsMessage;
    VectorBadAlloc(const char*);
};
void* __cdecl operator new(unsigned int);
extern "C" inline ShortPoint* __cdecl FUN_0065f9e0(unsigned int _Count, int)
{
    if (_Count <= 0)
        _Count = 0;
    else if ((unsigned int)(-1) / _Count < sizeof(ShortPoint))
        throw VectorBadAlloc(0);
    return static_cast<ShortPoint*>(operator new(_Count * sizeof(ShortPoint)));
}
ShortPoint* __cdecl FUN_0065fde0(ShortPoint*, ShortPoint*, ShortPoint*, PointAlloc&);
void __cdecl FUN_00ab23c0(ShortPoint*, unsigned int, const ShortPoint&, PointAlloc&, CopyTag, RangeTag);

struct BaseTag
{
};
template <class T> inline T CheckedBase(T& _It, BaseTag)
{
    return _It;
}
template <class T> inline T CheckedBase(T& _It)
{
    BaseTag _Base_tag;
    return CheckedBase(_It, _Base_tag);
}
template <class T> inline CopyTag PtrCat(T&, T&)
{
    CopyTag _Cat;
    return _Cat;
}
template <class T> inline T UninitCopy(T _First, T _Last, T _Dest, PointAlloc& _Al, CopyTag, RangeTag)
{
    return FUN_0065fde0(_First, _Last, _Dest, _Al);
}
template <class T> inline T UncheckedCopy(T _First, T _Last, T _Dest, PointAlloc& _Al)
{
    return UninitCopy(CheckedBase(_First), CheckedBase(_Last), _Dest, _Al, PtrCat(_First, _Dest), RangeTag());
}
inline void UncheckedFill(ShortPoint* _First, unsigned int _Count, const ShortPoint& _Val, PointAlloc& _Al)
{
    FUN_00ab23c0(_First, _Count, _Val, _Al, PtrCat(_First, _First), RangeTag());
}
inline void DestroyRange(ShortPoint* _First, ShortPoint* _Last, PointAlloc& _Al, CopyTag)
{
    for (; _First != _Last; ++_First)
        _First->~ShortPoint();
}
inline void DestroyRange(ShortPoint* _First, ShortPoint* _Last, PointAlloc& _Al)
{
    DestroyRange(_First, _Last, _Al, PtrCat(_First, _Last));
}
inline void FillLoop(ShortPoint* _First, ShortPoint* _Last, const ShortPoint& _Val)
{
    for (; _First != _Last; ++_First)
        *_First = _Val;
}
inline void Fill(ShortPoint* _First, ShortPoint* _Last, const ShortPoint& _Val)
{
    FillLoop(CheckedBase(_First), CheckedBase(_Last), _Val);
}

inline ShortPoint* __cdecl CopyRange(ShortPoint* _First, ShortPoint* _Last, ShortPoint* _Dest, PointAlloc& _Al, CopyTag,
                                     RangeTag)
{
    ShortPoint* _Next = _Dest;
    try
    {
        for (; _First != _Last; ++_Dest, ++_First)
            _Al.construct(_Dest, *_First);
    }
    catch (...)
    {
        for (; _Next != _Dest; ++_Next)
            _Al.destroy(_Next);
        throw;
    }
    return _Dest;
}
inline ShortPoint* ByteCopy(ShortPoint* _First, ShortPoint* _Last, ShortPoint* _Dest, PointAlloc& _Al)
{
    return CopyRange(CheckedBase(_First), CheckedBase(_Last), _Dest, _Al, PtrCat(_First, _Dest), RangeTag());
}
inline ShortPoint* CopyDispatch(ShortPoint* _First, ShortPoint* _Last, ShortPoint* _Dest, PointAlloc& _Al, CopyTag,
                                RangeTag)
{
    return ByteCopy(_First, _Last, _Dest, _Al);
}
inline ShortPoint* __cdecl FUN_00ab2260(ShortPoint* _First, ShortPoint* _Last, ShortPoint* _Dest, PointAlloc& _Al)
{
    return CopyDispatch(CheckedBase(_First), CheckedBase(_Last), _Dest, _Al, PtrCat(_First, _Dest), RangeTag());
}
struct RandomTag
{
};
template <class T> inline RandomTag IterRandom(T&, T&)
{
    RandomTag _Cat;
    return _Cat;
}
struct ForwardTag
{
};
inline ShortPoint* BackwardLoop(ShortPoint* _First, ShortPoint* _Last, ShortPoint* _Dest, ForwardTag, CopyTag, RangeTag)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return _Dest;
}
inline ShortPoint* BackwardOpt(ShortPoint* _First, ShortPoint* _Last, ShortPoint* _Dest, CopyTag _Cat, RangeTag)
{
    ShortPoint* _Result = _Dest - (_Last - _First);
    BackwardLoop(_First, _Last, CheckedBase(_Dest), ForwardTag(), _Cat, RangeTag());
    return _Result;
}
inline ShortPoint* __cdecl FUN_00ab22e0(ShortPoint* _First, ShortPoint* _Last, ShortPoint* _Dest, RandomTag, CopyTag,
                                        RangeTag)
{
    return BackwardOpt(_First, _Last, _Dest, PtrCat(_First, _Dest), RangeTag());
}
inline ShortPoint* __cdecl FUN_00ab2210(ShortPoint* _First, ShortPoint* _Last, ShortPoint* _Dest)
{
    return FUN_00ab22e0(CheckedBase(_First), CheckedBase(_Last), _Dest, IterRandom(_First, _Dest),
                        PtrCat(_First, _Dest), RangeTag());
}

struct PointIter
{
    void* container;
    ShortPoint* point;
};
struct PointVector
{
    int iteratorHead;
    int iteratorState;
    PointAlloc _Alval;
    ShortPoint* _Myfirst;
    ShortPoint* _Mylast;
    ShortPoint* _Myend;
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int max_size() const
    {
        unsigned int _Count = 0x2aaaaaaa;
        return 0 < _Count ? _Count : 1;
    }
    template <class T> ShortPoint* _Ucopy(T _First, T _Last, ShortPoint* _Ptr)
    {
        return UncheckedCopy(_First, _Last, _Ptr, _Alval);
    }
    ShortPoint* _UcopyTail(ShortPoint* _First, ShortPoint* _Last, ShortPoint* _Ptr)
    {
        return FUN_00ab2260(_First, _Last, _Ptr, _Alval);
    }
    void _Destroy(ShortPoint* _First, ShortPoint* _Last)
    {
        DestroyRange(_First, _Last, _Alval);
    }
    ShortPoint* _Ufill(ShortPoint* _Ptr, unsigned int _Count, const ShortPoint& _Val)
    {
        UncheckedFill(_Ptr, _Count, _Val, _Alval);
        return _Ptr + _Count;
    }
    void FUN_00ab0fd0(PointIter _Where, unsigned int _Count, const ShortPoint& _Val);
};
// @fnv 0x00ab0fd0
void PointVector::FUN_00ab0fd0(PointIter _Where, unsigned int _Count, const ShortPoint& _Val)
{
    unsigned int _Capacity = capacity();
    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        ThrowVectorTooLong();
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        ShortPoint* _Newvec = FUN_0065f9e0(_Capacity, 0);
        ShortPoint* _Newlast = _Newvec;
        try
        {
            _Newlast = _Ucopy(_Myfirst, _Where.point, _Newvec);
            _Ufill(_Newlast, _Count, _Val);
            _Newlast += _Count;
            _Ucopy(_Where.point, _Mylast, _Newlast);
        }
        catch (...)
        {
            _Destroy(_Newvec, _Newlast);
            DAT_011f6238.Deallocate(_Newvec);
            throw;
        }
        _Count += size();
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myend = _Newvec + _Capacity;
        _Mylast = _Newvec + _Count;
        _Myfirst = _Newvec;
    }
    else if ((unsigned int)(_Mylast - _Where.point) < _Count)
    {
        ShortPoint _Tmp = _Val;
        _Ucopy(_Where.point, _Mylast, _Where.point + _Count);
        try
        {
            _Ufill(_Mylast, _Count - (_Mylast - _Where.point), _Tmp);
        }
        catch (...)
        {
            _Destroy(_Where.point + _Count, _Mylast + _Count);
            throw;
        }
        _Mylast += _Count;
        Fill(_Where.point, _Mylast - _Count, _Tmp);
    }
    else
    {
        ShortPoint _Tmp = _Val;
        ShortPoint* _Oldend = _Mylast;
        _Mylast = _UcopyTail(_Oldend - _Count, _Oldend, _Mylast);
        FUN_00ab2210(_Where.point, _Oldend - _Count, _Oldend);
        Fill(_Where.point, _Where.point + _Count, _Tmp);
    }
}

struct FnvElem
{
    FnvElem(const FnvElem& other);
    int m00;
    int m04;
    int m08;
    int m0c;
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
};

__forceinline void* operator new(unsigned int, void* p) throw()
{
    return p;
}
void operator delete(void*, void*) throw();

extern "C" void __cdecl FUN_0065eb50(void* p);

// @fnv 0x00ab45f0
void __cdecl FUN_00ab45f0(char* first, unsigned int count, void* value)
{
    char* next = first;

    try
    {
        for (; 0 < count; --count, first += 0x58)
        {
            void* vptr = first;
            ::new (vptr) FnvElem(*(const FnvElem*)value);
        }
    }
    catch (...)
    {
        for (; next != first; next += 0x58)
            FUN_0065eb50(next);
        throw;
    }
}

void __cdecl FUN_00ec7c56();
struct ContainerBaseAuxB9F1
{
};
class AuxContB9F1
{
  public:
    const ContainerBaseAuxB9F1* _Getcont() const
    {
        return _Mycontainer;
    }
    const ContainerBaseAuxB9F1* _Mycontainer;
};
class IteratorBaseAuxB9F1
{
  public:
    const ContainerBaseAuxB9F1* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    AuxContB9F1* _Myaux;
};
struct ElemB9F1
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct VectorB9F1 : public ContainerBaseAuxB9F1
{
    AuxContB9F1* _Myownedaux;
    int _Alaux;
    int _Alval;
    ElemB9F1* _Myfirst;
    ElemB9F1* _Mylast;
    ElemB9F1* _Myend;
};
class FUN_00ab9f10_It : public IteratorBaseAuxB9F1
{
  public:
    FUN_00ab9f10_It& FUN_00ab9f10();
    ElemB9F1* _Myptr;
};

// @fnv 0x00ab9f10
FUN_00ab9f10_It& FUN_00ab9f10_It::FUN_00ab9f10()
{
    if (!(this->_Has_container()))
        FUN_00ec7c56();
    if (!(_Myptr < ((VectorB9F1*)this->_Getmycont())->_Mylast))
        FUN_00ec7c56();
    ++_Myptr;
    return *this;
}

void FUN_00ec7c56();
struct Element12
{
    unsigned int x, y, z;
};
struct ElementAllocator
{
    inline void destroy(Element12* pointer)
    {
        pointer->~Element12();
    }
};
struct Container0;
struct ForwardCopyTag
{
};
struct RandomCopyTag : ForwardCopyTag
{
};
struct ObjectCopyTag
{
};
struct RangeCheckedTag
{
};
inline RandomCopyTag iteratorCategory(Element12* const&, Element12* const&)
{
    RandomCopyTag category;
    return category;
}
inline ObjectCopyTag pointerCategory(Element12*&, Element12*&)
{
    ObjectCopyTag category;
    return category;
}
struct UnchangedBaseTag
{
};
inline Element12* checkedBase(Element12*& pointer, UnchangedBaseTag)
{
    return pointer;
}
inline Element12* checkedBase(Element12*& pointer)
{
    UnchangedBaseTag tag;
    return checkedBase(pointer, tag);
}
inline Element12* copyDispatch(Element12* first, Element12* last, Element12* destination, ForwardCopyTag, ObjectCopyTag,
                               RangeCheckedTag)
{
    for (; first != last; ++destination, ++first)
        *destination = *first;
    return destination;
}
inline Element12* copyDispatch(Element12* first, Element12* last, Element12* destination, RandomCopyTag, ObjectCopyTag,
                               RangeCheckedTag)
{
    Element12* result = destination + (last - first);
    copyDispatch(first, last, checkedBase(destination), ForwardCopyTag(), ObjectCopyTag(), RangeCheckedTag());
    return result;
}
inline Element12* copyElements(Element12* first, Element12* last, Element12* destination)
{
    return copyDispatch(checkedBase(first), checkedBase(last), destination, iteratorCategory(first, destination),
                        pointerCategory(first, destination), RangeCheckedTag());
}
struct IteratorAuxiliary
{
    const Container0* container;
    inline const Container0* get() const
    {
        return container;
    }
};
struct IteratorOwner
{
    const IteratorAuxiliary* owner;
    inline IteratorOwner() : owner(0)
    {}
    inline void set(const Container0* container);
    inline bool hasContainer() const
    {
        return owner != 0;
    }
    inline bool sameContainer(const IteratorOwner& other) const
    {
        return owner == other.owner;
    }
    inline const Container0* GetShapeContainer() const
    {
        return owner ? owner->get() : 0;
    }
};
struct ConstIterator : IteratorOwner
{
    Element12* current;
    inline ConstIterator(Element12* ptr, const Container0* container);
    ConstIterator& FUN_00ac0dc0(int n);
    inline Element12* base() const
    {
        return current;
    }
    inline bool operator==(const ConstIterator& other) const
    {
        if (!(hasContainer() && sameContainer(other)))
            FUN_00ec7c56();
        return current == other.current;
    }
    inline bool operator!=(const ConstIterator& other) const
    {
        return !(*this == other);
    }
};
struct CheckedIterator : ConstIterator
{
    inline CheckedIterator(Element12* ptr, const Container0* container) : ConstIterator(ptr, container)
    {}
    inline CheckedIterator& operator+=(int n)
    {
        static_cast<ConstIterator*>(this)->FUN_00ac0dc0(n);
        return *this;
    }
    inline CheckedIterator operator+(int n) const
    {
        CheckedIterator result = *this;
        return result += n;
    }
};
struct Container0
{
    const IteratorAuxiliary* owner00;
    int unk04;
    ElementAllocator allocator08;
    Element12* first0c;
    Element12* last10;
    Element12* end14;
    inline unsigned int size() const
    {
        return last10 - first0c;
    }
    inline CheckedIterator begin()
    {
        return CheckedIterator(first0c, this);
    }
    inline CheckedIterator end()
    {
        return CheckedIterator(last10, this);
    }
    void FUN_00abca90(ConstIterator where, unsigned int count, const Element12& value);
    inline CheckedIterator makeIterator(ConstIterator where) const
    {
        return CheckedIterator(where.current, this);
    }
    inline void destroy(Element12* first, Element12* last)
    {
        for (Element12* cursor = first; cursor != last; ++cursor)
            allocator08.destroy(cursor);
    }
    CheckedIterator FUN_00aba9a0(ConstIterator firstArgument, ConstIterator lastArgument)
    {
        CheckedIterator first = makeIterator(firstArgument);
        CheckedIterator last = makeIterator(lastArgument);
        if (first != last)
        {
            Element12* position = copyElements(last.base(), last10, first.base());
            destroy(position, last10);
            last10 = position;
        }
        return first;
    }
    void FUN_00aba7b0(unsigned int count, Element12 value);
};
inline void IteratorOwner::set(const Container0* container)
{
    owner = container->owner00;
}
inline ConstIterator::ConstIterator(Element12* ptr, const Container0* container)
{
    if (container == 0 || container->first0c > ptr || ptr > container->last10)
        FUN_00ec7c56();
    set(container);
    current = ptr;
}
// @fnv 0x00aba7b0
void Container0::FUN_00aba7b0(unsigned int count, Element12 value)
{
    if (size() < count)
        FUN_00abca90(end(), count - size(), value);
    else if (count < size())
        FUN_00aba9a0(begin() + count, end());
}

inline ConstIterator& ConstIterator::FUN_00ac0dc0(int n)
{
    if (!hasContainer())
        FUN_00ec7c56();
    if (!(current + n <= GetShapeContainer()->last10 && current + n >= GetShapeContainer()->first0c))
        FUN_00ec7c56();
    current += n;
    return *this;
}

struct MemoryStatusAA3880
{
    unsigned long dwLength;
    unsigned long dwMemoryLoad;
    unsigned __int64 ullTotalPhys;
    unsigned __int64 ullAvailPhys;
    unsigned __int64 ullTotalPageFile;
    unsigned __int64 ullAvailPageFile;
    unsigned __int64 ullTotalVirtual;
    unsigned __int64 ullAvailVirtual;
    unsigned __int64 ullAvailExtendedVirtual;
};
extern "C" __declspec(dllimport) int __stdcall GlobalMemoryStatusEx(MemoryStatusAA3880* pkStatus);
extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* pcText, const char* pcCaption,
                                                           unsigned int uiType);
extern "C" __declspec(noreturn) void __cdecl exit(int iCode);
extern "C" void __cdecl FUN_00ec61c0(void* pvDst, int iValue, unsigned int uiSize);
struct MemoryManagerAA3880
{
    void* Allocate(unsigned int uiSize);
};
extern MemoryManagerAA3880 g_kMemoryAA3880;
inline void* AllocateAA3880(unsigned int uiSize)
{
    void* pvMem = g_kMemoryAA3880.Allocate(uiSize);
    return pvMem;
}
struct TableBaseAA3880
{
    TableBaseAA3880(unsigned int ItemUpdateArray)
    {
        m_uiCount = ItemUpdateArray;
        m_uiAllocatedCapacity = 0;
        if (ItemUpdateArray)
        {
            m_ppvData = (void**)AllocateAA3880(m_uiCount * sizeof(void*));
            FUN_00ec61c0(m_ppvData, 0, m_uiCount * sizeof(void*));
        }
    }
    virtual ~TableBaseAA3880();
    unsigned int m_uiCount;
    void** m_ppvData;
    unsigned int m_uiAllocatedCapacity;
};
struct TableAA3880 : public TableBaseAA3880
{
    TableAA3880() : TableBaseAA3880(37)
    {}
    virtual ~TableAA3880();
};
struct FUN_00aa3880
{
    FUN_00aa3880();
    void FUN_00aa39c0();
    void InitializeGlobal();
    static void FUN_00aa58d0();
    bool m_bShaderEnabled;
    char unk01;
    short m_sCount;
    short m_sIndex;
    short unk06;
    int m_iFlags;
    void* m_apSlots[66];
    TableAA3880 m_kTable;
    int m_iActive;
    bool m_bEnableState;
    bool m_bVisible;
    char unk12A;
    char unk12B;
    int m_iFirst;
    int m_iSecond;
    int m_iThird;
};

// @fnv 0x00aa3880
FUN_00aa3880::FUN_00aa3880()
    : m_bShaderEnabled(false), m_sCount(0), m_sIndex(0), m_iFlags(0), m_iActive(0), m_bEnableState(true),
      m_bVisible(true), m_iFirst(0), m_iSecond(0), m_iThird(0)
{
    FUN_00ec61c0(m_apSlots, 0, sizeof(m_apSlots));
    MemoryStatusAA3880 kStatus;
    kStatus.dwLength = sizeof(kStatus);
    if (GlobalMemoryStatusEx(&kStatus) && kStatus.ullAvailPageFile < 0x20000000)
    {
        MessageBoxA(0, "Not enough memory to run application.", "Memory Error", 0x10);
        exit(0);
    }
    FUN_00aa39c0();
    InitializeGlobal();
    FUN_00aa58d0();
}

struct HeapStandIn
{
    virtual void v0();
    virtual void v1();
    virtual void* Allocate(unsigned int size, unsigned int flags);
};

class PoolStandIn
{
  public:
    void* AllocatePoolBlock(unsigned int size);
};

inline PoolStandIn* __cdecl GetPoolForSize(unsigned int size)
{
    PoolStandIn* pool = 0;
    if (size < 0x12c)
    {
        pool = size <= 0x3fc ? reinterpret_cast<PoolStandIn*>(DAT_011f67b8[((size + 15) & ~15) >> 2]) : 0;
    }
    else if (size < 0x200)
    {
        pool = size <= 0x3fc ? reinterpret_cast<PoolStandIn*>(DAT_011f67b8[((size + 15) & ~15) >> 2]) : 0;
        if (!pool)
        {
            pool = size <= 0x3fc ? reinterpret_cast<PoolStandIn*>(DAT_011f67b8[((size + 31) & ~31) >> 2]) : 0;
        }
    }
    else if (size < 0x240)
    {
        pool = size <= 0x3fc ? reinterpret_cast<PoolStandIn*>(DAT_011f67b8[0x240 >> 2]) : 0;
    }
    if (pool && true)
    {
        return pool;
    }
    else
    {
        return 0;
    }
}

extern __declspec(thread) int tlsHeapIndex;

struct MemoryManagerStandIn
{
    bool initialized;
    char unk01;
    char unk02;
    char unk03;
    int unk04;
    int unk08;
    HeapStandIn* heaps[0x41];
    HeapStandIn* defaultHeap;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    char unk128;
    bool usePools;

    void* FallbackAllocate(unsigned int size, unsigned int flags);
    int HandleOutOfMemory(HeapStandIn* heap, int attempt, bool* retry);
    void* FUN_00aa3e40(unsigned int size);
};

// @fnv 0x00aa3e40
void* MemoryManagerStandIn::FUN_00aa3e40(unsigned int size)
{
    if (!initialized)
    {
        return FallbackAllocate(size, 0);
    }
    HeapStandIn* mainHeap = defaultHeap;
    if (!mainHeap)
    {
        return FallbackAllocate(size, 0);
    }
    unsigned int requested3 = size;
    void* result2 = 0;
    if (size <= 8)
    {
        size = 8;
    }
    else
    {
        size = (size + 3) & ~3;
    }
    int heapIndex6 = tlsHeapIndex;
    if (usePools)
    {
        PoolStandIn* pool = size <= 0x3fc ? reinterpret_cast<PoolStandIn*>(DAT_011f67b8[size >> 2]) : 0;
        if (!pool)
        {
            pool = GetPoolForSize(size);
        }
        if (pool)
        {
            result2 = pool->AllocatePoolBlock(requested3);
            if (result2)
            {
                return result2;
            }
        }
    }
    bool retry2 = false;
    bool recovered7 = false;
    int attempt2 = 0;
    HeapStandIn* heap = 0;
    HeapStandIn* threadHeapB = 0;
    threadHeapB = heaps[heapIndex6];
    do
    {
        heap = threadHeapB ? threadHeapB : mainHeap;
        result2 = heap->Allocate(size, 0);
        if (!result2 && heap != mainHeap)
        {
            heap = mainHeap;
            result2 = heap->Allocate(size, 0);
        }
        if (!result2)
        {
            attempt2 = HandleOutOfMemory(threadHeapB ? threadHeapB : mainHeap, attempt2, &retry2);
            if (retry2)
            {
                result2 = FallbackAllocate(size, 0);
                recovered7 = result2 != 0;
            }
        }
    } while (!result2);
    return result2;
}

void __cdecl NiFree4A60(void* pvMem);

struct MemoryManager4A60
{
    void Deallocate(void* pvMem);
};
extern MemoryManager4A60 g_kMemoryManager4A60;
inline void __cdecl operator delete[](void* pvMem)
{
    g_kMemoryManager4A60.Deallocate(pvMem);
}

struct MapItem4A60
{
    MapItem4A60* m_pkNext;
    const char* m_key;
    void* m_val;
};

class MapBase4A60
{
  public:
    static void operator delete(void* pvMem)
    {
        g_kMemoryManager4A60.Deallocate(pvMem);
    }
    virtual ~MapBase4A60()
    {
        if (m_ppkHashTable)
            delete[] m_ppkHashTable;
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(MapItem4A60* pkItem, const char* key, void* val);
    virtual void ClearValue(MapItem4A60* pkItem);
    virtual MapItem4A60* NewItem();
    virtual void DeleteItem(MapItem4A60* pkItem);
    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                MapItem4A60* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }
    unsigned int m_uiHashSize;
    MapItem4A60** m_ppkHashTable;
    unsigned int m_uiCount;
};
class FUN_00aa4a60 : public MapBase4A60
{
  public:
    virtual ~FUN_00aa4a60();
};

// @fnv 0x00aa4a60
FUN_00aa4a60::~FUN_00aa4a60()
{
    RemoveAll();
}

struct S_00aa8950_MM
{
    void __thiscall FUN_00aa4060(void*);
};

struct S00aa8950_ReleaseGuard
{
    unsigned int m_uiFirstValue;
    unsigned int m_pSecondNode;
    __forceinline ~S00aa8950_ReleaseGuard()
    {}
};

struct S00aa8950_Obj : FUN_00aa8be0_cls
{
    void* __thiscall FUN_00aa8950(unsigned int flags);
};

// @fnv 0x00aa8950
void* __thiscall S00aa8950_Obj::FUN_00aa8950(unsigned int flags)
{
    ((int*)this)[0] = 0x010a2970;
    {
        S00aa8950_ReleaseGuard guard;
        ClearList();
    }
    ((int*)this)[0] = (int)&DAT_010a2980;
    if (flags & 1)
    {
        reinterpret_cast<S_00aa8950_MM*>(&DAT_011f6238)->FUN_00aa4060(this);
    }
    return this;
}

extern "C" unsigned int __cdecl strlen(const char*);
void* __cdecl FUN_0044d670(unsigned int, int);

namespace std {
template <class E> struct char_traits;
template <> struct char_traits<char>
{
    typedef char char_type;
    static void assign(char& left, const char& right)
    {
        left = right;
    }
    static unsigned int length(const char* first)
    {
        return ::strlen(first);
    }
};
template <class T> class allocator
{
  public:
    typedef T value_type;
    typedef T* pointer;
    typedef unsigned int size_type;
    template <class U> struct rebind
    {
        typedef allocator<U> other;
    };
    allocator()
    {}
    allocator(const allocator&)
    {}
    template <class U> allocator(const allocator<U>&)
    {}
    void deallocate(pointer ptr, size_type)
    {
        DAT_011f6238.Deallocate(ptr);
    }
    pointer allocate(size_type count)
    {
        return (pointer)FUN_0044d670(count, 0);
    }
};
template <class E, class Tr, class A> class basic_string
{
  public:
    typedef basic_string<E, Tr, A> Myt;
    typedef unsigned int size_type;
    enum
    {
        BUF_SIZE = 16
    };
    static const size_type npos = (size_type)-1;
    basic_string(const E* ptr);
    ~basic_string()
    {
        Tidy(true);
    }
    Myt& assign(const E* ptr)
    {
        return assign(ptr, Tr::length(ptr));
    }
    Myt& assign(const E* ptr, size_type count);
    void Tidy(bool built = false, size_type newsize = 0);
    E* Myptr()
    {
        return BUF_SIZE <= myres ? bx.ptr : bx.buf;
    }
    A alval;
    union
    {
        E buf[BUF_SIZE];
        E* ptr;
    } bx;
    size_type mysize;
    size_type myres;
};

template <class E, class Tr, class A> inline basic_string<E, Tr, A>::basic_string(const E* ptr)
{
    unsigned n0, n1, n2, n3, n4, n5, n6, n7;
    n0 = 0;
    n1 = n0;
    n2 = n1;
    n3 = n2;
    n4 = n3;
    n5 = n4;
    n6 = n5;
    n7 = n6;
    if (n7 == 1)
    {
        basic_string<E, Tr, A> again(ptr);
        (void)again;
    }
    Tidy();
    assign(ptr);
}

template <class E, class Tr, class A> inline void basic_string<E, Tr, A>::Tidy(bool built, size_type newsize)
{
    if (!built)
    {
    }
    else if (BUF_SIZE <= myres)
    {
        E* p = bx.ptr;
        alval.deallocate(p, myres + 1);
    }
    myres = BUF_SIZE - 1;
    Tr::assign(Myptr()[mysize = newsize], E());
}

template <class E, class Tr, class A>
inline basic_string<E, Tr, A>& basic_string<E, Tr, A>::assign(const E* ptr, size_type count)
{
    if (count && myres < count)
    {
        E* p = alval.allocate(count + 1);
        bx.ptr = p;
        myres = count;
    }
    mysize = count;
    return *this;
}
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > Str;

struct Obj00aaa730
{
    virtual ~Obj00aaa730();
    Str a;
    Str b;
    int unk3c;
    Obj00aaa730(Str key);
    bool FUN_00ac3fe0(const char* name);
};

inline Obj00aaa730::~Obj00aaa730()
{}

// @fnv 0x00aaa730
bool FUN_00aaa730(const char* name)
{
    Obj00aaa730 obj(Str("FRCTL001"));
    return obj.FUN_00ac3fe0(name);
}

struct S00aaaa80_Str
{
    int alloc;
    int b04;
    int b08;
    int b0c;
    int b10;
    unsigned int len;
    unsigned int cap;
    ~S00aaaa80_Str()
    {
        Tidy(true);
    }
    void Tidy(bool built = false, unsigned int count = 0);
};

struct S00aaaa80_Body
{
    virtual void Anchor();
    void FUN_00ac5430()
    {
        unsigned n0, n1, n2, n3, n4, n5, n6, n7, n8, n9;
        if (n0)
            FUN_00ac5430();
        n0 = n1 = n2 = n3 = n4 = n5 = n6 = n7 = n8 = n9 = 0;
    }
};

struct FUN_00aaaa80 : S00aaaa80_Body
{
    S00aaaa80_Str filename;
    S00aaaa80_Str signature;
    unsigned int unk3c;
    virtual ~FUN_00aaaa80();
};

// @fnv 0x00aaaa80
FUN_00aaaa80::~FUN_00aaaa80()
{
    FUN_00ac5430();
}

namespace fnv_00aaab90 {
extern MemoryManager DAT_011f6238;
extern "C" int __cdecl fclose(void*);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" const char DAT_01011584[];
char* __cdecl FUN_0044ccd0(char*, unsigned int, const char*, unsigned int);
void* __cdecl FUN_0044d670(unsigned int, int);

struct ReaderAllocator
{
    int standin;
    void FUN_0064df10(void* p, unsigned int)
    {
        DAT_011f6238.Deallocate(p);
    }
};

struct ReaderTraits
{
    static char* CopyS(char* destination, unsigned int size, const char* source, unsigned int count)
    {
        return FUN_0044ccd0(destination, size, source, count);
    }
    static void Assign(char& left, const char& right)
    {
        left = right;
    }
};

struct ReaderString
{
    ReaderAllocator allocator;
    union
    {
        char small[16];
        char* heap;
    } storage;
    unsigned int length;
    unsigned int capacity;
    void FUN_0044a730(bool built = false, unsigned int count = 0)
    {
        if (built && 16 <= capacity)
        {
            char* ptr = storage.heap;
            if (0 < count)
                ReaderTraits::CopyS(storage.small, 16, ptr, count);
            allocator.FUN_0064df10(ptr, capacity + 1);
        }
        capacity = 15;
        Eos(count);
    }
    ReaderString& AssignSubstring(const ReaderString&, unsigned int, unsigned int);
    ReaderString& assign(const char* text)
    {
        return FUN_0044a7f0(text, strlen(text));
    }
    bool Inside(const char* text);
    unsigned int max_size();
    void Xlen();
    void Copy(unsigned int count, unsigned int oldLength)
    {
        unsigned int newres = count | 15;
        if (max_size() < newres)
            newres = count;
        char* ptr = (char*)FUN_0044d670(newres + 1, 0);
        if (0 < oldLength)
            FUN_0044ccd0(ptr, newres + 1, Myptr(), oldLength);
        FUN_0044a730(true);
        storage.heap = ptr;
        capacity = newres;
        Eos(oldLength);
    }
    bool Grow(unsigned int count, bool trim = false)
    {
        if (max_size() < count)
            Xlen();
        if (capacity < count)
            Copy(count, length);
        else if (trim && count < 16)
            FUN_0044a730(true, count < length ? count : length);
        else if (count == 0)
            Eos(0);
        return 0 < count;
    }
    char* Myptr()
    {
        return 16 <= capacity ? storage.heap : storage.small;
    }
    void Eos(unsigned int count)
    {
        ReaderTraits::Assign(Myptr()[length = count], char());
    }
    ReaderString& FUN_0044a7f0(const char* text, unsigned int count)
    {
        if (Inside(text))
            return AssignSubstring(*this, text - Myptr(), count);
        if (Grow(count))
        {
            FUN_0044ccd0(Myptr(), capacity + 1, text, count);
            Eos(count);
        }
        return *this;
    }
    ~ReaderString()
    {
        FUN_0044a730(true);
    }
};

struct FUN_00aaaa80
{
    ReaderString filename;
    ReaderString signature;
    void* unk3c;
    void FUN_00ac5430()
    {
        if (unk3c != 0)
            fclose(unk3c);
        unsigned int length = strlen(DAT_01011584);
        filename.FUN_0044a7f0(DAT_01011584, length);
        unk3c = 0;
    }
    virtual ~FUN_00aaaa80()
    {
        FUN_00ac5430();
    }
};

struct ReaderObject
{
    virtual ~ReaderObject();
};

struct LoadedFile
{
    void FUN_0044b180();
};

struct DerivedReader : FUN_00aaaa80
{
    ReaderObject* unk40;
    LoadedFile* unk44;
    void ClearHolders()
    {
        if (unk44 != 0)
        {
            unk40 = 0;
            unk44->FUN_0044b180();
            unk44 = 0;
        }
        else
        {
            ReaderObject* object = unk40;
            if (object != 0)
                delete object;
            unk40 = 0;
        }
    }
    virtual ~DerivedReader()
    {
        ClearHolders();
    }
    DerivedReader* FUN_00aaab90(unsigned int flags);
};

// @fnv 0x00aaab90
DerivedReader* DerivedReader::FUN_00aaab90(unsigned int flags)
{
    this->DerivedReader::~DerivedReader();
    if (flags & 1)
        DAT_011f6238.Deallocate(this);
    return this;
}
}  // namespace fnv_00aaab90

inline void DA()
{
    int a[2];
}
inline void DB()
{
    int a[2];
}
inline void DC()
{
    int a[5];
}
extern void __cdecl FUN_00ec7c56();
extern unsigned int DAT_010173f0;
struct AAStr
{
    int unk00;
    char* ptr;
    int unk08, unk0c, unk10;
    unsigned int size, res;
    void EraseRange(unsigned int, unsigned int);
    void AppendChars(unsigned int, unsigned char);
    void resize(unsigned int count)
    {
        DC();
        if (count <= size)
            EraseRange(count, DAT_010173f0);
        else
            AppendChars(count - size, 0);
    }
    char* data()
    {
        return res >= 16 ? ptr : (char*)&ptr;
    }
    char& at(unsigned int index)
    {
        if (size < index)
            FUN_00ec7c56();
        return (res >= 16 ? ptr : (char*)&ptr)[index];
    }
};
struct AARet
{
    float* data;
    int unk04;
    float& operator[](unsigned int index)
    {
        DB();
        return data[index];
    }
};
struct AAItem
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, rows;
    unsigned int columns;
    AAStr name;
    AARet FUN_0060b370(int);
    void FUN_0060b410(unsigned int, float);
    void resize(unsigned int height, unsigned int count)
    {
        rows = height;
        columns = count;
        FUN_0060b410(height * count, 0.0f);
    }
};
struct AAElem
{
    int unk00, unk04, unk08;
    AAItem* first;
    AAItem* last;
    AAItem* endp;
    void FUN_00aadde0(unsigned int);
    unsigned int size() const
    {
        return last - first;
    }
    AAItem& at(unsigned int index)
    {
        if (index >= size())
            FUN_00ec7c56();
        return first[index];
    }
};
struct AAStream
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool Read(void*, unsigned int, unsigned int);
};
struct AAOwner
{
    AAElem elems[2][2];
    bool FUN_00aaac10(AAStream*, unsigned int (*)[2]);
};
// @fnv 0x00aaac10
bool AAOwner::FUN_00aaac10(AAStream* stream, unsigned int (*lengths)[2])
{
    unsigned int count, length;
    DA();
    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 2; j++)
        {
            if (!stream->Read(&length, 4, 1))
                return false;
            elems[i][j].FUN_00aadde0(length);
            for (unsigned int k = 0; k < length; k++)
            {
                elems[i][j].at(k).resize(1, lengths[i][j]);
                if (!stream->Read(&elems[i][j].at(k).FUN_0060b370(0)[0], 4, lengths[i][j]))
                    return false;
                if (!stream->Read(&count, 4, 1))
                    return false;
                elems[i][j].at(k).name.resize(count);
                if (!stream->Read(&elems[i][j].at(k).name.at(0), 1, count))
                    return false;
            }
        }
    }
    return true;
}

struct EmptyBF
{
    __forceinline ~EmptyBF()
    {}
};
struct PairBF
{
    float m_00, m_04;
};
struct StorageBF
{
    void* m_00;
    int m_04, m_08, m_0c, m_10, m_14, m_18, m_1c;
    __forceinline ~StorageBF()
    {
        DAT_011f6238.Deallocate(m_00);
    }
};
struct OwnerBF : EmptyBF
{
    void* m_00;
    int m_04, m_08, m_0c, m_10, m_14, m_18, m_1c;
    __forceinline ~OwnerBF()
    {
        StorageBF release;
        release.m_00 = m_00;
    }
};
struct OwnerWrapBF : OwnerBF
{
    __forceinline ~OwnerWrapBF()
    {}
};
struct CleanupBF : OwnerWrapBF
{
    void FUN_0065f240();
    __forceinline ~CleanupBF()
    {
        FUN_0065f240();
    }
};
struct VectorBF : CleanupBF
{
    __forceinline ~VectorBF()
    {}
    VectorBF BuildScaledValues(float);
};
struct SourceBF
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24;
    VectorBF Transpose();
};
struct DestBF
{
    int m_00[16];
    void AddMatrix(const VectorBF&);
};
extern float DAT_0101e580, DAT_01077848, DAT_0102243c, DAT_0101e570;
extern const char DAT_010a2c5c[];
void ReportAssertionViolation(const char*, unsigned int);
void FUN_00aaf2b0(PairBF*, const PairBF*, const PairBF*);
struct SubBF
{
    unsigned char m_00;
    unsigned char unk001, unk002, unk003;
    int unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020;
    int unk024, unk028, unk02c, unk030, unk034, unk038, unk03c, unk040;
    int unk044, unk048, unk04c, unk050, unk054, unk058, unk05c, unk060;
    int unk064, unk068, unk06c, unk070, unk074, unk078, unk07c, unk080;
    int unk084, unk088, unk08c, unk090, unk094, unk098, unk09c, unk0a0;
    int unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc, unk0c0;
    int unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc, unk0e0;
    int unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc, unk100;
    int unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120;
    int unk124, unk128, unk12c, unk130, unk134, unk138, unk13c, unk140;
    int unk144, unk148, unk14c, unk150, unk154, unk158, unk15c, unk160;
    int unk164, unk168, unk16c, unk170, unk174, unk178, unk17c, unk180;
    int unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0;
    int unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc, unk1c0;
    int unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc, unk1e0;
    int unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc, unk200;
    int unk204, unk208, unk20c, unk210, unk214, unk218, unk21c, unk220;
    int unk224, unk228, unk22c, unk230, unk234, unk238, unk23c, unk240;
    int unk244, unk248, unk24c, unk250, unk254, unk258, unk25c, unk260;
    int unk264, unk268, unk26c, unk270, unk274, unk278, unk27c, unk280;
    int unk284, unk288, unk28c, unk290, unk294, unk298, unk29c, unk2a0;
    int unk2a4, unk2a8, unk2ac, unk2b0, unk2b4, unk2b8, unk2bc, unk2c0;
    int unk2c4, unk2c8, unk2cc, unk2d0, unk2d4, unk2d8, unk2dc, unk2e0;
    int unk2e4, unk2e8, unk2ec, unk2f0, unk2f4, unk2f8, unk2fc, unk300;
    int unk304, unk308, unk30c, unk310, unk314, unk318, unk31c, unk320;
    SourceBF m_324[5][2][2];
    int unk644, unk648, unk64c, unk650, unk654, unk658, unk65c, unk660;
    int unk664, unk668, unk66c, unk670, unk674, unk678, unk67c, unk680;
    int unk684, unk688, unk68c, unk690, unk694, unk698, unk69c, unk6a0;
    int unk6a4, unk6a8, unk6ac, unk6b0, unk6b4, unk6b8, unk6bc, unk6c0;
    int unk6c4, unk6c8, unk6cc, unk6d0, unk6d4, unk6d8, unk6dc, unk6e0;
    int unk6e4, unk6e8, unk6ec, unk6f0, unk6f4, unk6f8, unk6fc, unk700;
    int unk704, unk708, unk70c, unk710, unk714, unk718, unk71c, unk720;
    int unk724, unk728, unk72c, unk730, unk734, unk738, unk73c, unk740;
    int unk744, unk748, unk74c, unk750, unk754, unk758, unk75c, unk760;
    int unk764, unk768, unk76c, unk770, unk774, unk778, unk77c, unk780;
    int unk784, unk788, unk78c, unk790, unk794, unk798, unk79c, unk7a0;
    int unk7a4, unk7a8, unk7ac, unk7b0, unk7b4, unk7b8, unk7bc, unk7c0;
    int unk7c4, unk7c8, unk7cc, unk7d0, unk7d4, unk7d8, unk7dc, unk7e0;
    int unk7e4, unk7e8, unk7ec, unk7f0, unk7f4, unk7f8, unk7fc, unk800;
    int unk804, unk808, unk80c, unk810, unk814, unk818, unk81c, unk820;
    int unk824, unk828, unk82c, unk830, unk834, unk838, unk83c, unk840;
    int unk844, unk848, unk84c, unk850, unk854, unk858, unk85c, unk860;
    int unk864, unk868, unk86c, unk870, unk874, unk878, unk87c, unk880;
    int unk884, unk888, unk88c, unk890, unk894, unk898, unk89c, unk8a0;
    int unk8a4, unk8a8, unk8ac, unk8b0, unk8b4, unk8b8, unk8bc, unk8c0;
    int unk8c4, unk8c8, unk8cc, unk8d0, unk8d4, unk8d8, unk8dc, unk8e0;
    int unk8e4, unk8e8, unk8ec, unk8f0, unk8f4, unk8f8, unk8fc, unk900;
    int unk904, unk908, unk90c, unk910, unk914, unk918, unk91c, unk920;
    int unk924, unk928, unk92c, unk930, unk934, unk938, unk93c, unk940;
    int unk944, unk948, unk94c, unk950, unk954, unk958, unk95c, unk960;
    int unk964, unk968, unk96c, unk970, unk974, unk978, unk97c, unk980;
    int unk984, unk988, unk98c, unk990, unk994, unk998, unk99c, unk9a0;
    int unk9a4, unk9a8, unk9ac, unk9b0, unk9b4, unk9b8, unk9bc, unk9c0;
    int unk9c4, unk9c8, unk9cc, unk9d0, unk9d4, unk9d8, unk9dc, unk9e0;
    int unk9e4, unk9e8, unk9ec, unk9f0, unk9f4, unk9f8, unk9fc, unka00;
    int unka04, unka08, unka0c, unka10, unka14, unka18, unka1c, unka20;
    int unka24, unka28, unka2c, unka30, unka34, unka38, unka3c, unka40;
    int unka44, unka48, unka4c, unka50, unka54, unka58, unka5c, unka60;
    int unka64, unka68, unka6c, unka70, unka74, unka78, unka7c, unka80;
    int unka84, unka88, unka8c, unka90, unka94, unka98, unka9c, unkaa0;
    int unkaa4, unkaa8, unkaac, unkab0, unkab4, unkab8, unkabc, unkac0;
    int unkac4, unkac8, unkacc, unkad0, unkad4, unkad8, unkadc, unkae0;
    int unkae4, unkae8, unkaec, unkaf0, unkaf4, unkaf8, unkafc, unkb00;
    int unkb04, unkb08, unkb0c, unkb10, unkb14, unkb18, unkb1c, unkb20;
    int unkb24, unkb28, unkb2c, unkb30, unkb34, unkb38, unkb3c, unkb40;
    int unkb44, unkb48, unkb4c, unkb50, unkb54, unkb58, unkb5c, unkb60;
    int unkb64, unkb68, unkb6c, unkb70, unkb74, unkb78, unkb7c, unkb80;
    int unkb84, unkb88, unkb8c, unkb90, unkb94, unkb98, unkb9c, unkba0;
    int unkba4, unkba8, unkbac, unkbb0, unkbb4, unkbb8, unkbbc, unkbc0;
    int unkbc4, unkbc8, unkbcc, unkbd0, unkbd4, unkbd8, unkbdc, unkbe0;
    int unkbe4, unkbe8, unkbec, unkbf0, unkbf4, unkbf8, unkbfc, unkc00;
    int unkc04, unkc08, unkc0c, unkc10, unkc14, unkc18, unkc1c, unkc20;
    int unkc24, unkc28, unkc2c, unkc30, unkc34, unkc38, unkc3c, unkc40;
    int unkc44, unkc48, unkc4c, unkc50, unkc54, unkc58, unkc5c, unkc60;
    int unkc64, unkc68, unkc6c, unkc70, unkc74, unkc78, unkc7c, unkc80;
    int unkc84, unkc88, unkc8c, unkc90, unkc94, unkc98, unkc9c, unkca0;
    int unkca4, unkca8, unkcac, unkcb0, unkcb4, unkcb8, unkcbc, unkcc0;
    int unkcc4, unkcc8, unkccc, unkcd0, unkcd4, unkcd8, unkcdc, unkce0;
    int unkce4, unkce8, unkcec, unkcf0, unkcf4, unkcf8, unkcfc, unkd00;
    int unkd04, unkd08, unkd0c, unkd10, unkd14, unkd18, unkd1c, unkd20;
    int unkd24, unkd28, unkd2c, unkd30, unkd34, unkd38, unkd3c, unkd40;
    int unkd44, unkd48, unkd4c, unkd50, unkd54, unkd58, unkd5c, unkd60;
    int unkd64, unkd68, unkd6c, unkd70, unkd74, unkd78, unkd7c, unkd80;
    int unkd84, unkd88, unkd8c, unkd90, unkd94, unkd98, unkd9c, unkda0;
    int unkda4, unkda8, unkdac, unkdb0, unkdb4, unkdb8, unkdbc, unkdc0;
    int unkdc4, unkdc8, unkdcc, unkdd0, unkdd4, unkdd8, unkddc, unkde0;
    int unkde4, unkde8, unkdec, unkdf0, unkdf4, unkdf8, unkdfc, unke00;
    int unke04, unke08, unke0c, unke10, unke14, unke18, unke1c, unke20;
    int unke24, unke28, unke2c, unke30, unke34, unke38, unke3c, unke40;
    int unke44, unke48, unke4c, unke50, unke54, unke58, unke5c, unke60;
    int unke64, unke68, unke6c, unke70, unke74, unke78, unke7c, unke80;
    int unke84, unke88, unke8c, unke90, unke94, unke98, unke9c, unkea0;
    int unkea4, unkea8, unkeac, unkeb0, unkeb4, unkeb8, unkebc, unkec0;
    int unkec4, unkec8, unkecc, unked0, unked4, unked8, unkedc, unkee0;
    int unkee4, unkee8, unkeec, unkef0, unkef4, unkef8, unkefc, unkf00;
    int unkf04, unkf08, unkf0c, unkf10, unkf14, unkf18, unkf1c, unkf20;
    int unkf24, unkf28, unkf2c, unkf30, unkf34, unkf38, unkf3c, unkf40;
    int unkf44, unkf48, unkf4c, unkf50, unkf54, unkf58, unkf5c, unkf60;
    int unkf64, unkf68, unkf6c, unkf70, unkf74, unkf78, unkf7c, unkf80;
    int unkf84, unkf88, unkf8c, unkf90, unkf94, unkf98, unkf9c, unkfa0;
    int unkfa4, unkfa8, unkfac, unkfb0, unkfb4, unkfb8, unkfbc, unkfc0;
    int unkfc4, unkfc8;
    PairBF m_fcc[5][2][2];
    float FUN_00aabdb0(int, int, int, DestBF*);
    void FUN_00aabf30(int, int, int, float, DestBF*);
};
// @fnv 0x00aabf30
void SubBF::FUN_00aabf30(int ia, int ib, int ic, float value, DestBF* dest)
{
    if (ia < 5)
    {
    }
    else
        ReportAssertionViolation(DAT_010a2c5c, 222);
    if (!m_00)
        return;
    float h[2] = {DAT_0101e580, DAT_01077848};
    float f[2] = {DAT_0102243c, DAT_0101e570};
    float a = value;
    if (a < h[ib])
        a = h[ib];
    if (a > f[ib])
        a = f[ib];
    float p = a - FUN_00aabdb0(ia, ib, ic, dest);
    PairBF i = {0.0f, 0.0f};
    ((float*)&i)[ib] = p;
    PairBF s;
    FUN_00aaf2b0(&s, &m_fcc[ia][ic][0], &i);
    dest[ic].AddMatrix(m_324[ia][ib][ic].Transpose().BuildScaledValues(((float*)&s)[ib]));
}

namespace fnv_00aac170 {
extern const char DAT_010a27f4[];
struct MatrixPoolLock
{
    unsigned int owner, count, unk08, unk0c, unk10, unk14, unk18, unk1c;
    void Lock(const char*);
};
struct MatrixPool
{
    unsigned int unk00, begin;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    MatrixPoolLock lock;
    unsigned int unk40;
    unsigned int unk44;
    unsigned short* pageCounts;
    unsigned int unk4c;
    unsigned int size;
    void FUN_00aa6e00(void*);
    __forceinline void FUN_00aa6c70(void* pointer)
    {
        if (!pointer)
            return;
        lock.Lock(DAT_010a27f4);
        FUN_00aa6e00(pointer);
        unsigned int page = ((unsigned int)pointer - begin) >> 12;
        --pageCounts[page];
        MatrixPoolLock* heldLock = &lock;
        --heldLock->count;
        if (!heldLock->count)
            heldLock->owner = 0;
    }
    bool Contains(const void* pointer)
    {
        return (unsigned int)pointer >= begin && (unsigned int)pointer < begin + size;
    }
};
struct MatrixHeap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Free(void*, int);
    virtual bool Contains(const void*);
};
extern MatrixPool* DAT_011f63b8[256];
struct MM
{
    unsigned char active;
    unsigned char unk01;
    unsigned short heapCount;
    unsigned int unk004;
    MatrixHeap** heaps;
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
    void* current;
    void FreePointer(void*, int);
    __forceinline MatrixHeap* FindItemByArg(const void* pointer)
    {
        for (unsigned short i = 0; i < heapCount; ++i)
        {
            MatrixHeap* heap = heaps[i];
            if (heap->Contains(pointer))
                return heap;
        }
        return 0;
    }
    void Deallocate(void* pointer)
    {
        if (!pointer)
            return;
        if (!active)
        {
            FreePointer(pointer, 0);
            return;
        }
        void* currentPool = current;
        if (!currentPool)
        {
            FreePointer(pointer, 0);
            return;
        }
        MatrixPool* pool = DAT_011f63b8[(unsigned int)pointer >> 24];
        if (pool && pool->Contains(pointer))
        {
            pool->FUN_00aa6c70(pointer);
            return;
        }
        MatrixHeap* heap = FindItemByArg(pointer);
        if (heap)
            heap->Free(pointer, 0);
        else
            FreePointer(pointer, 0);
    }
};
extern MM _g_memoryManager;
__forceinline void ReleaseMatrixMemory(void* pointer)
{
    _g_memoryManager.Deallocate(pointer);
}
struct AllocationTag
{
    __forceinline ~AllocationTag()
    {}
};
struct AllocationStorage : AllocationTag
{
    void* data;
    unsigned int unk04, unk08, unk0c, unk10, unk14, rows, cols;
    __forceinline ~AllocationStorage()
    {
        ReleaseMatrixMemory(data);
    }
};
struct MatrixStorage : AllocationStorage
{
    __forceinline ~MatrixStorage()
    {}
};
struct MatrixCore : MatrixStorage
{
    void FUN_0065f2b0(unsigned int, unsigned int);
    void deallocateVector(void*, unsigned int);
    void FUN_0065f240()
    {
        if (unk0c)
        {
            FUN_0065f2b0(unk0c, unk10);
            deallocateVector((void*)unk0c, (unk14 - unk0c) / 4);
        }
        unk0c = 0;
        unk10 = 0;
        unk14 = 0;
    }
    __forceinline ~MatrixCore()
    {
        FUN_0065f240();
    }
};
struct LocalMatrix : MatrixCore
{
    LocalMatrix BuildScaledValues(float scale);
    __forceinline ~LocalMatrix()
    {}
};
struct SourceMatrix : LocalMatrix
{
    unsigned int unk20, unk24;
    LocalMatrix Transpose();
};
struct OutputMatrix
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    void AddMatrix(const LocalMatrix& rhs);
};
struct TransformMatrix
{
    float x0, y0, x1, y1;
};
struct PairVector
{
    float x, y;
    PairVector()
    {}
};
extern const float g_011c75e0_arg1;
extern const float g_011dae08_arg1;
extern const float g_011c72f0_arg1;
extern const float DAT_0101e570;
PairVector __cdecl FUN_00aaf2b0(const TransformMatrix&, const PairVector&);
void __cdecl ReportAssertionViolation(const char*, int);
extern const char DAT_010a2c5c[];
struct Sub_00aabdb0
{
    unsigned char active;
    unsigned char unk01;
    unsigned short unk02;
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
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
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
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    SourceMatrix components[5][2][2];
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66c;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67c;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68c;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69c;
    unsigned int unk6a0;
    unsigned int unk6a4;
    unsigned int unk6a8;
    unsigned int unk6ac;
    unsigned int unk6b0;
    unsigned int unk6b4;
    unsigned int unk6b8;
    unsigned int unk6bc;
    unsigned int unk6c0;
    unsigned int unk6c4;
    unsigned int unk6c8;
    unsigned int unk6cc;
    unsigned int unk6d0;
    unsigned int unk6d4;
    unsigned int unk6d8;
    unsigned int unk6dc;
    unsigned int unk6e0;
    unsigned int unk6e4;
    unsigned int unk6e8;
    unsigned int unk6ec;
    unsigned int unk6f0;
    unsigned int unk6f4;
    unsigned int unk6f8;
    unsigned int unk6fc;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70c;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71c;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72c;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73c;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74c;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75c;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76c;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77c;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78c;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79c;
    unsigned int unk7a0;
    unsigned int unk7a4;
    unsigned int unk7a8;
    unsigned int unk7ac;
    unsigned int unk7b0;
    unsigned int unk7b4;
    unsigned int unk7b8;
    unsigned int unk7bc;
    unsigned int unk7c0;
    unsigned int unk7c4;
    unsigned int unk7c8;
    unsigned int unk7cc;
    unsigned int unk7d0;
    unsigned int unk7d4;
    unsigned int unk7d8;
    unsigned int unk7dc;
    unsigned int unk7e0;
    unsigned int unk7e4;
    unsigned int unk7e8;
    unsigned int unk7ec;
    unsigned int unk7f0;
    unsigned int unk7f4;
    unsigned int unk7f8;
    unsigned int unk7fc;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80c;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81c;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82c;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83c;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84c;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85c;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86c;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87c;
    unsigned int unk880;
    unsigned int unk884;
    unsigned int unk888;
    unsigned int unk88c;
    unsigned int unk890;
    unsigned int unk894;
    unsigned int unk898;
    unsigned int unk89c;
    unsigned int unk8a0;
    unsigned int unk8a4;
    unsigned int unk8a8;
    unsigned int unk8ac;
    unsigned int unk8b0;
    unsigned int unk8b4;
    unsigned int unk8b8;
    unsigned int unk8bc;
    unsigned int unk8c0;
    unsigned int unk8c4;
    unsigned int unk8c8;
    unsigned int unk8cc;
    unsigned int unk8d0;
    unsigned int unk8d4;
    unsigned int unk8d8;
    unsigned int unk8dc;
    unsigned int unk8e0;
    unsigned int unk8e4;
    unsigned int unk8e8;
    unsigned int unk8ec;
    unsigned int unk8f0;
    unsigned int unk8f4;
    unsigned int unk8f8;
    unsigned int unk8fc;
    unsigned int unk900;
    unsigned int unk904;
    unsigned int unk908;
    unsigned int unk90c;
    unsigned int unk910;
    unsigned int unk914;
    unsigned int unk918;
    unsigned int unk91c;
    unsigned int unk920;
    unsigned int unk924;
    unsigned int unk928;
    unsigned int unk92c;
    unsigned int unk930;
    unsigned int unk934;
    unsigned int unk938;
    unsigned int unk93c;
    unsigned int unk940;
    unsigned int unk944;
    unsigned int unk948;
    unsigned int unk94c;
    unsigned int unk950;
    unsigned int unk954;
    unsigned int unk958;
    unsigned int unk95c;
    unsigned int unk960;
    unsigned int unk964;
    unsigned int unk968;
    unsigned int unk96c;
    unsigned int unk970;
    unsigned int unk974;
    unsigned int unk978;
    unsigned int unk97c;
    unsigned int unk980;
    unsigned int unk984;
    unsigned int unk988;
    unsigned int unk98c;
    unsigned int unk990;
    unsigned int unk994;
    unsigned int unk998;
    unsigned int unk99c;
    unsigned int unk9a0;
    unsigned int unk9a4;
    unsigned int unk9a8;
    unsigned int unk9ac;
    unsigned int unk9b0;
    unsigned int unk9b4;
    unsigned int unk9b8;
    unsigned int unk9bc;
    unsigned int unk9c0;
    unsigned int unk9c4;
    unsigned int unk9c8;
    unsigned int unk9cc;
    unsigned int unk9d0;
    unsigned int unk9d4;
    unsigned int unk9d8;
    unsigned int unk9dc;
    unsigned int unk9e0;
    unsigned int unk9e4;
    unsigned int unk9e8;
    unsigned int unk9ec;
    unsigned int unk9f0;
    unsigned int unk9f4;
    unsigned int unk9f8;
    unsigned int unk9fc;
    unsigned int unka00;
    unsigned int unka04;
    unsigned int unka08;
    unsigned int unka0c;
    unsigned int unka10;
    unsigned int unka14;
    unsigned int unka18;
    unsigned int unka1c;
    unsigned int unka20;
    unsigned int unka24;
    unsigned int unka28;
    unsigned int unka2c;
    unsigned int unka30;
    unsigned int unka34;
    unsigned int unka38;
    unsigned int unka3c;
    unsigned int unka40;
    unsigned int unka44;
    unsigned int unka48;
    unsigned int unka4c;
    unsigned int unka50;
    unsigned int unka54;
    unsigned int unka58;
    unsigned int unka5c;
    unsigned int unka60;
    unsigned int unka64;
    unsigned int unka68;
    unsigned int unka6c;
    unsigned int unka70;
    unsigned int unka74;
    unsigned int unka78;
    unsigned int unka7c;
    unsigned int unka80;
    unsigned int unka84;
    unsigned int unka88;
    unsigned int unka8c;
    unsigned int unka90;
    unsigned int unka94;
    unsigned int unka98;
    unsigned int unka9c;
    unsigned int unkaa0;
    unsigned int unkaa4;
    unsigned int unkaa8;
    unsigned int unkaac;
    unsigned int unkab0;
    unsigned int unkab4;
    unsigned int unkab8;
    unsigned int unkabc;
    unsigned int unkac0;
    unsigned int unkac4;
    unsigned int unkac8;
    unsigned int unkacc;
    unsigned int unkad0;
    unsigned int unkad4;
    unsigned int unkad8;
    unsigned int unkadc;
    unsigned int unkae0;
    unsigned int unkae4;
    unsigned int unkae8;
    unsigned int unkaec;
    unsigned int unkaf0;
    unsigned int unkaf4;
    unsigned int unkaf8;
    unsigned int unkafc;
    unsigned int unkb00;
    unsigned int unkb04;
    unsigned int unkb08;
    unsigned int unkb0c;
    unsigned int unkb10;
    unsigned int unkb14;
    unsigned int unkb18;
    unsigned int unkb1c;
    unsigned int unkb20;
    unsigned int unkb24;
    unsigned int unkb28;
    unsigned int unkb2c;
    unsigned int unkb30;
    unsigned int unkb34;
    unsigned int unkb38;
    unsigned int unkb3c;
    unsigned int unkb40;
    unsigned int unkb44;
    unsigned int unkb48;
    unsigned int unkb4c;
    unsigned int unkb50;
    unsigned int unkb54;
    unsigned int unkb58;
    unsigned int unkb5c;
    unsigned int unkb60;
    unsigned int unkb64;
    unsigned int unkb68;
    unsigned int unkb6c;
    unsigned int unkb70;
    unsigned int unkb74;
    unsigned int unkb78;
    unsigned int unkb7c;
    unsigned int unkb80;
    unsigned int unkb84;
    unsigned int unkb88;
    unsigned int unkb8c;
    unsigned int unkb90;
    unsigned int unkb94;
    unsigned int unkb98;
    unsigned int unkb9c;
    unsigned int unkba0;
    unsigned int unkba4;
    unsigned int unkba8;
    unsigned int unkbac;
    unsigned int unkbb0;
    unsigned int unkbb4;
    unsigned int unkbb8;
    unsigned int unkbbc;
    unsigned int unkbc0;
    unsigned int unkbc4;
    unsigned int unkbc8;
    unsigned int unkbcc;
    unsigned int unkbd0;
    unsigned int unkbd4;
    unsigned int unkbd8;
    unsigned int unkbdc;
    unsigned int unkbe0;
    unsigned int unkbe4;
    unsigned int unkbe8;
    unsigned int unkbec;
    unsigned int unkbf0;
    unsigned int unkbf4;
    unsigned int unkbf8;
    unsigned int unkbfc;
    unsigned int unkc00;
    unsigned int unkc04;
    unsigned int unkc08;
    unsigned int unkc0c;
    unsigned int unkc10;
    unsigned int unkc14;
    unsigned int unkc18;
    unsigned int unkc1c;
    unsigned int unkc20;
    unsigned int unkc24;
    unsigned int unkc28;
    unsigned int unkc2c;
    unsigned int unkc30;
    unsigned int unkc34;
    unsigned int unkc38;
    unsigned int unkc3c;
    unsigned int unkc40;
    unsigned int unkc44;
    unsigned int unkc48;
    unsigned int unkc4c;
    unsigned int unkc50;
    unsigned int unkc54;
    unsigned int unkc58;
    unsigned int unkc5c;
    unsigned int unkc60;
    unsigned int unkc64;
    unsigned int unkc68;
    unsigned int unkc6c;
    unsigned int unkc70;
    unsigned int unkc74;
    unsigned int unkc78;
    unsigned int unkc7c;
    unsigned int unkc80;
    unsigned int unkc84;
    unsigned int unkc88;
    unsigned int unkc8c;
    unsigned int unkc90;
    unsigned int unkc94;
    unsigned int unkc98;
    unsigned int unkc9c;
    unsigned int unkca0;
    unsigned int unkca4;
    unsigned int unkca8;
    unsigned int unkcac;
    unsigned int unkcb0;
    unsigned int unkcb4;
    unsigned int unkcb8;
    unsigned int unkcbc;
    unsigned int unkcc0;
    unsigned int unkcc4;
    unsigned int unkcc8;
    unsigned int unkccc;
    unsigned int unkcd0;
    unsigned int unkcd4;
    unsigned int unkcd8;
    unsigned int unkcdc;
    unsigned int unkce0;
    unsigned int unkce4;
    unsigned int unkce8;
    unsigned int unkcec;
    unsigned int unkcf0;
    unsigned int unkcf4;
    unsigned int unkcf8;
    unsigned int unkcfc;
    unsigned int unkd00;
    unsigned int unkd04;
    unsigned int unkd08;
    unsigned int unkd0c;
    unsigned int unkd10;
    unsigned int unkd14;
    unsigned int unkd18;
    unsigned int unkd1c;
    unsigned int unkd20;
    unsigned int unkd24;
    unsigned int unkd28;
    unsigned int unkd2c;
    unsigned int unkd30;
    unsigned int unkd34;
    unsigned int unkd38;
    unsigned int unkd3c;
    unsigned int unkd40;
    unsigned int unkd44;
    unsigned int unkd48;
    unsigned int unkd4c;
    unsigned int unkd50;
    unsigned int unkd54;
    unsigned int unkd58;
    unsigned int unkd5c;
    unsigned int unkd60;
    unsigned int unkd64;
    unsigned int unkd68;
    unsigned int unkd6c;
    unsigned int unkd70;
    unsigned int unkd74;
    unsigned int unkd78;
    unsigned int unkd7c;
    unsigned int unkd80;
    unsigned int unkd84;
    unsigned int unkd88;
    unsigned int unkd8c;
    unsigned int unkd90;
    unsigned int unkd94;
    unsigned int unkd98;
    unsigned int unkd9c;
    unsigned int unkda0;
    unsigned int unkda4;
    unsigned int unkda8;
    unsigned int unkdac;
    unsigned int unkdb0;
    unsigned int unkdb4;
    unsigned int unkdb8;
    unsigned int unkdbc;
    unsigned int unkdc0;
    unsigned int unkdc4;
    unsigned int unkdc8;
    unsigned int unkdcc;
    unsigned int unkdd0;
    unsigned int unkdd4;
    unsigned int unkdd8;
    unsigned int unkddc;
    unsigned int unkde0;
    unsigned int unkde4;
    unsigned int unkde8;
    unsigned int unkdec;
    unsigned int unkdf0;
    unsigned int unkdf4;
    unsigned int unkdf8;
    unsigned int unkdfc;
    unsigned int unke00;
    unsigned int unke04;
    unsigned int unke08;
    unsigned int unke0c;
    unsigned int unke10;
    unsigned int unke14;
    unsigned int unke18;
    unsigned int unke1c;
    unsigned int unke20;
    unsigned int unke24;
    unsigned int unke28;
    unsigned int unke2c;
    unsigned int unke30;
    unsigned int unke34;
    unsigned int unke38;
    unsigned int unke3c;
    unsigned int unke40;
    unsigned int unke44;
    unsigned int unke48;
    unsigned int unke4c;
    unsigned int unke50;
    unsigned int unke54;
    unsigned int unke58;
    unsigned int unke5c;
    unsigned int unke60;
    unsigned int unke64;
    unsigned int unke68;
    unsigned int unke6c;
    unsigned int unke70;
    unsigned int unke74;
    unsigned int unke78;
    unsigned int unke7c;
    unsigned int unke80;
    unsigned int unke84;
    unsigned int unke88;
    unsigned int unke8c;
    unsigned int unke90;
    unsigned int unke94;
    unsigned int unke98;
    unsigned int unke9c;
    unsigned int unkea0;
    unsigned int unkea4;
    unsigned int unkea8;
    unsigned int unkeac;
    unsigned int unkeb0;
    unsigned int unkeb4;
    unsigned int unkeb8;
    unsigned int unkebc;
    unsigned int unkec0;
    unsigned int unkec4;
    unsigned int unkec8;
    unsigned int unkecc;
    unsigned int unked0;
    unsigned int unked4;
    unsigned int unked8;
    unsigned int unkedc;
    unsigned int unkee0;
    unsigned int unkee4;
    unsigned int unkee8;
    unsigned int unkeec;
    unsigned int unkef0;
    unsigned int unkef4;
    unsigned int unkef8;
    unsigned int unkefc;
    unsigned int unkf00;
    unsigned int unkf04;
    unsigned int unkf08;
    unsigned int unkf0c;
    unsigned int unkf10;
    unsigned int unkf14;
    unsigned int unkf18;
    unsigned int unkf1c;
    unsigned int unkf20;
    unsigned int unkf24;
    unsigned int unkf28;
    unsigned int unkf2c;
    unsigned int unkf30;
    unsigned int unkf34;
    unsigned int unkf38;
    unsigned int unkf3c;
    unsigned int unkf40;
    unsigned int unkf44;
    unsigned int unkf48;
    unsigned int unkf4c;
    unsigned int unkf50;
    unsigned int unkf54;
    unsigned int unkf58;
    unsigned int unkf5c;
    unsigned int unkf60;
    unsigned int unkf64;
    unsigned int unkf68;
    unsigned int unkf6c;
    unsigned int unkf70;
    unsigned int unkf74;
    unsigned int unkf78;
    unsigned int unkf7c;
    unsigned int unkf80;
    unsigned int unkf84;
    unsigned int unkf88;
    unsigned int unkf8c;
    unsigned int unkf90;
    unsigned int unkf94;
    unsigned int unkf98;
    unsigned int unkf9c;
    unsigned int unkfa0;
    unsigned int unkfa4;
    unsigned int unkfa8;
    unsigned int unkfac;
    unsigned int unkfb0;
    unsigned int unkfb4;
    unsigned int unkfb8;
    unsigned int unkfbc;
    unsigned int unkfc0;
    unsigned int unkfc4;
    unsigned int unkfc8;
    TransformMatrix transforms[5][2];
    float FUN_00aabdb0(int, int, int, int);
    void FUN_00aac170(int group, int kind, const float* input, OutputMatrix* output);
};
// @fnv 0x00aac170
void Sub_00aabdb0::FUN_00aac170(int group, int kind, const float* input, OutputMatrix* output)
{
    if (group < 5)
    {
    }
    else
        ReportAssertionViolation(DAT_010a2c5c, 266);
    if (!active)
        return;
    float transformed[2] = {g_011c75e0_arg1, g_011dae08_arg1};
    float lower[2] = {g_011c72f0_arg1, DAT_0101e570};
    PairVector upper;
    upper.x = 0.0f;
    upper.y = 0.0f;
    unsigned int i;
    for (i = 0; i < 2; i++)
    {
        float value = input[i];
        if (value < transformed[i])
            value = transformed[i];
        if (value > lower[i])
            value = lower[i];
        (&upper.x)[i] = value - FUN_00aabdb0(group, i, kind, (int)output);
    }
    PairVector delta = FUN_00aaf2b0(transforms[group][kind], upper);
    for (i = 0; i < 2; i++)
    {
        output[kind].AddMatrix(components[group][i][kind].Transpose().BuildScaledValues((&delta.x)[i]));
    }
}
}  // namespace fnv_00aac170

static __forceinline void DeadQ2()
{
    int dq[2];
}
extern double DAT_01016ff0;
double __cdecl GenerateGaussianRandom();

struct NoiseRow
{
    float* values;
    unsigned int count;
    __forceinline float& operator[](unsigned int column)
    {
        DeadQ2();
        return values[column];
    }
};

struct NoiseGrid
{
    float* data;
    unsigned int count;
    unsigned int capacity;
    unsigned int allocation;
    unsigned int rowStride;
    unsigned int flags;
    unsigned int rows;
    unsigned int columns;

    void __thiscall FUN_0060b410(unsigned int count, float initialValue);
    NoiseRow __thiscall FUN_0060b370(unsigned int row);
    __forceinline unsigned int getRows()
    {
        return rows;
    }
    __forceinline unsigned int getColumns()
    {
        return columns;
    }
    __forceinline void resize(unsigned int height, unsigned int width)
    {
        rows = height;
        columns = width;
        FUN_0060b410(height * width, 0.0f);
    }
};

struct NoiseGridBuilder
{
    void __thiscall FUN_00aad6b0(float magnitude, NoiseGrid input[2][2], NoiseGrid output[2][2]);
};

// @fnv 0x00aad6b0
void NoiseGridBuilder::FUN_00aad6b0(float magnitude, NoiseGrid input[2][2], NoiseGrid output[2][2])
{
    for (int group = 0; group < 2; group = group + 1)
    {
        for (int slot = 0; slot < 2; slot = slot + 1)
        {
            output[group][slot].resize(input[group][slot].getRows(), input[group][slot].getColumns());
            for (unsigned int row = 0; row < input[group][slot].getRows(); row = row + 1)
            {
                for (unsigned int column = 0; column < input[group][slot].getColumns(); column = column + 1)
                {
                    if (slot == 0)
                    {
                        double delta = GenerateGaussianRandom() * magnitude * DAT_01016ff0;
                        output[group][slot].FUN_0060b370(row)[column] =
                            input[group][slot].FUN_0060b370(row)[column] + delta;
                    }
                    else
                    {
                        output[group][slot].FUN_0060b370(row)[column] = 0.0f;
                    }
                }
            }
        }
    }
}

struct BlendAllocator
{
    void FUN_00aa4060(void*);
};
struct BlendEmpty
{
    ~BlendEmpty()
    {}
};
struct BlendStorage : BlendEmpty
{
    void* m_00;
    int m_04, m_08, m_0c, m_10, m_14, m_18, m_1c;
    ~BlendStorage()
    {
        struct PointerCopy
        {
            void* m_00;
            int m_04, m_08, m_0c, m_10, m_14, m_18, m_1c;
        } p;
        p.m_00 = m_00;
        ((BlendAllocator*)&DAT_011f6238)->FUN_00aa4060(p.m_00);
    }
};
struct BlendStorageWrapper : BlendStorage
{
    ~BlendStorageWrapper()
    {}
};
struct BlendRelease : BlendStorageWrapper
{
    void FUN_0065f240();
    ~BlendRelease()
    {
        FUN_0065f240();
    }
};
struct BlendValue : BlendRelease
{
    ~BlendValue()
    {}
    BlendValue BuildScaledValues(float);
    BlendValue FUN_00658500(const BlendValue&);
    void FUN_006581e0(const BlendValue&);
};
struct BlendOwner
{
    float FUN_00aac3f0(int, int, int, BlendValue (*)[2]);
    void FUN_00aac820(int, int, int, float, BlendValue (*)[2]);
    void FUN_00aadac0(int, int, float, BlendValue (*)[2], BlendValue (*)[2], BlendValue (*)[2]);
};
// @fnv 0x00aadac0
void BlendOwner::FUN_00aadac0(int row, int col, float t, BlendValue (*a)[2], BlendValue (*b)[2], BlendValue (*out)[2])
{
    float second = FUN_00aac3f0(0, row, col, a);
    float first = FUN_00aac3f0(0, row, col, b);
    float result;
    if (t < 0.0)
        result = first;
    else if (t > 1.0)
        result = second;
    else
        result = second * t + (1.0f - t) * first;
    out[row][col].FUN_006581e0(a[row][col].BuildScaledValues(t).FUN_00658500(b[row][col].BuildScaledValues(1.0f - t)));
    FUN_00aac820(0, row, col, result, out);
}

// FUN_00aadde0: thiscall member (1 stack arg).
// The original default-constructs a 0x3c-byte class object (external ctor) and
// then forwards the argument to this->FUN_00aadf50(arg).
struct FUN_00aade20
{
    FUN_00aade20()
    {
        int v[68];
        for (int i = 0; i < 68; i++)
            v[i] = i;
        for (int i = 1; i < 68; i++)
            v[i] += v[i - 1];
        unk00 = v[68 - 1];
    }

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
    int unk0a;
    int unk0b;
    int unk0c;
    int unk0d;
    int unk0e;
    FUN_00aade20(const FUN_00aade20&);
    ~FUN_00aade20() throw();
};

struct Pad
{
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
    int unk0a;
    int unk0b;
    int unk0c;
    int unk0d;
    int unk0e;
    int unk0f;
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
    int unk1a;
    int unk1b;
    int unk1c;
    int unk1d;
    int unk1e;
    int unk1f;
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
    int unk2a;
    int unk2b;
    int unk2c;
    int unk2d;
    int unk2e;
    int unk2f;
    int unk30;
    int unk31;
    int unk32;
    int unk33;
    int unk34;
    int unk35;
    int unk36;
    int unk37;
};

struct Big
{
    int u[69];
};
struct FUN_00aadde0_cls
{
    void __thiscall FUN_00aadf50(int a, FUN_00aade20 o);
    void __thiscall FUN_00aadde0(int a);
};

// @fnv 0x00aadde0
void FUN_00aadde0_cls::FUN_00aadde0(int a)
{

    this->FUN_00aadf50(a, FUN_00aade20());
}

inline void Dead31()
{
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
    int d8;
    int d9;
    int d10;
    int d11;
    int d12;
    int d13;
    int d14;
    int d15;
    int d16;
    int d17;
    int d18;
    int d19;
    int d20;
    int d21;
    int d22;
    int d23;
    int d24;
    int d25;
    int d26;
    int d27;
    int d28;
    int d29;
    int d30;
    int d31;
    int d32;
}
struct FUN_006593e0
{
    int m[15];
    FUN_006593e0(const FUN_006593e0&);
    ~FUN_006593e0();
};
struct VecQ_aadf50;
struct CItQ_aadf50_aadf50
{
    void* _Myaux;
    FUN_006593e0* _Myptr;
    CItQ_aadf50_aadf50()
    {}
    CItQ_aadf50_aadf50(FUN_006593e0* _Ptr, const VecQ_aadf50* _Pvector);
    CItQ_aadf50_aadf50& FUN_00aaecb0(int _Off);
};
struct ItQ_aadf50 : CItQ_aadf50_aadf50
{
    ItQ_aadf50()
    {}
    ItQ_aadf50(FUN_006593e0* _Ptr, const VecQ_aadf50* _Pvector) : CItQ_aadf50_aadf50(_Ptr, _Pvector)
    {}
    ItQ_aadf50& operator+=(int _Off)
    {
        (*(CItQ_aadf50_aadf50*)this).FUN_00aaecb0(_Off);
        return (*this);
    }
    ItQ_aadf50 operator+(int _Off) const
    {
        ItQ_aadf50 _Tmp = *this;
        return (_Tmp += _Off);
    }
};
struct VecQ_aadf50
{
    void* _Myownedaux;
    int m04;
    int m08;
    FUN_006593e0* _Myfirst;
    FUN_006593e0* _Mylast;
    FUN_006593e0* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    ItQ_aadf50 begin()
    {
        return ItQ_aadf50(_Myfirst, this);
    }
    ItQ_aadf50 end()
    {
        return ItQ_aadf50(_Mylast, this);
    }
    void FUN_00aae3a0(CItQ_aadf50_aadf50 _Where, unsigned int _Count, const FUN_006593e0& _Val);
    ItQ_aadf50 FUN_00aae200(CItQ_aadf50_aadf50 _First, CItQ_aadf50_aadf50 _Last);
    void FUN_00aadf50(unsigned int _Newsize, FUN_006593e0 _Val);
};
inline CItQ_aadf50_aadf50::CItQ_aadf50_aadf50(FUN_006593e0* _Ptr, const VecQ_aadf50* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        FUN_00ec7c56();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00aadf50
void VecQ_aadf50::FUN_00aadf50(unsigned int _Newsize, FUN_006593e0 _Val)
{
    int _Unused;
    if (size() < _Newsize)
        FUN_00aae3a0(end(), _Newsize - size(), _Val);
    else if (_Newsize < size())
    {
        FUN_00aae200(begin() + _Newsize, end());
        Dead31();
    }
}

inline void DeadA()
{
    int a[5];
}
inline void DeadB()
{
    int a[12];
}
struct ElQ
{
    int m[15];
    void FUN_006593e0();
    void DelQ(unsigned int f)
    {
        FUN_006593e0();
        if (f & 1)
            DAT_011f6238.Deallocate(this);
    }
};
struct CatQ
{
};
struct TagQ
{
};
struct IterQ
{
    IterQ()
    {}
};
inline CatQ PtrCat(ElQ*&, ElQ*&)
{
    CatQ c;
    return c;
}
struct HelpQ
{
    ElQ* Base(ElQ* const& p)
    {
        return p;
    }
};
inline ElQ* Chk(ElQ* const& p)
{
    HelpQ _Helper;
    return _Helper.Base(p);
}
ElQ* __cdecl FUN_00aaf750(ElQ* _First, ElQ* _Last, ElQ* _Dest, IterQ, CatQ, TagQ);
inline ElQ* UCopy(ElQ* _First, ElQ* _Last, ElQ* _Dest)
{
    return FUN_00aaf750(Chk(_First), Chk(_Last), _Dest, IterQ(), PtrCat(_First, _Dest), TagQ());
    DeadA();
}
inline void DestroyR(ElQ* _First, ElQ* _Last, CatQ)
{
    for (; _First != _Last; ++_First)
        _First->DelQ(0);
    DeadB();
}
inline void DestroyR(ElQ* _First, ElQ* _Last)
{
    DestroyR(_First, _Last, PtrCat(_First, _Last));
}
struct VecQ;
struct CItQ
{
    void* _Myaux;
    ElQ* _Myptr;
    CItQ()
    {}
    CItQ(ElQ* _Ptr, const VecQ* _Pvector);
    bool FUN_00ac0460(const CItQ& _Right) const;
};
struct ItQ : CItQ
{
    ItQ()
    {}
    ItQ(ElQ* _Ptr, const VecQ* _Pvector) : CItQ(_Ptr, _Pvector)
    {}
};
struct VecQ
{
    void* _Myownedaux;
    int m04;
    char _Alval;
    char p09[3];
    ElQ* _Myfirst;
    ElQ* _Mylast;
    ElQ* _Myend;
    void Destroy(ElQ* _First, ElQ* _Last)
    {
        DestroyR(_First, _Last);
    }
    ItQ FUN_00aae200(CItQ _First_arg, CItQ _Last_arg);
};
inline CItQ::CItQ(ElQ* _Ptr, const VecQ* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        FUN_00ec7c56();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00aae200
ItQ VecQ::FUN_00aae200(CItQ _First_arg, CItQ _Last_arg)
{
    ItQ _First(_First_arg._Myptr, this);
    ItQ _Last(_Last_arg._Myptr, this);
    if (_First.FUN_00ac0460(_Last))
    {
        ElQ* _Ptr = UCopy(_Last._Myptr, _Mylast, _First._Myptr);
        Destroy(_Ptr, _Mylast);
        _Mylast = _Ptr;
    }
    return _First;
}

void __cdecl InvalidParameterNoInfoXAECB0();
struct ContainerBaseAuxXAECB0
{
};
class AuxContXAECB0
{
  public:
    const ContainerBaseAuxXAECB0* _Getcont() const
    {
        return _Mycontainer;
    }
    const ContainerBaseAuxXAECB0* _Mycontainer;
};
class IteratorBaseAuxXAECB0
{
  public:
    const ContainerBaseAuxXAECB0* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    AuxContXAECB0* _Myaux;
};
struct ElemXAECB0
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
};
struct VectorXAECB0 : public ContainerBaseAuxXAECB0
{
    AuxContXAECB0* _Myownedaux;
    int _Alaux;
    int _Alval;
    ElemXAECB0* _Myfirst;
    ElemXAECB0* _Mylast;
    ElemXAECB0* _Myend;
};
class FUN_00aaecb0_It : public IteratorBaseAuxXAECB0
{
  public:
    FUN_00aaecb0_It& FUN_00aaecb0(int _Off);
    ElemXAECB0* _Myptr;
};

// @fnv 0x00aaecb0
FUN_00aaecb0_It& FUN_00aaecb0_It::FUN_00aaecb0(int _Off)
{
    if (!(this->_Has_container()))
        InvalidParameterNoInfoXAECB0();
    if (!(_Myptr + _Off <= ((VectorXAECB0*)this->_Getmycont())->_Mylast &&
          _Myptr + _Off >= ((VectorXAECB0*)this->_Getmycont())->_Myfirst))
        InvalidParameterNoInfoXAECB0();
    _Myptr += _Off;
    return *this;
}

inline float S00aaf2b0_Dot(const float* m, unsigned int row, const float* v)
{
    return v[1] * *(const float*)((const char*)m + (row << 3) + 4) +
           v[0] * *(const float*)((const char*)m + (row << 3));
}

// @fnv 0x00aaf2b0
float* FUN_00aaf2b0(float* out, float* m, float* v)
{
    float r0 = 0.0f;
    float r1 = 0.0f;
    r0 = S00aaf2b0_Dot(m, 0, v);
    r1 = S00aaf2b0_Dot(m, 1, v);
    out[0] = r0;
    out[1] = r1;
    return out;
}

namespace fnv_00aaf330 {
static __forceinline void DeadQ1()
{
    int dq[1];
}
static __forceinline void DeadQ2()
{
    int dq[2];
}
static __forceinline void DeadQ3()
{
    int dq[3];
}
static __forceinline void DeadQ4()
{
    int dq[4];
}
static __forceinline void DeadQ5()
{
    int dq[5];
}
static __forceinline void DeadQ6()
{
    int dq[6];
}
static __forceinline void DeadQ7()
{
    int dq[7];
}
static __forceinline void DeadQ8()
{
    int dq[8];
}
static __forceinline void DeadQ9()
{
    int dq[9];
}
static __forceinline void DeadQ10()
{
    int dq[10];
}
static __forceinline void DeadQ11()
{
    int dq[11];
}
static __forceinline void DeadQ12()
{
    int dq[12];
}
static __forceinline void DeadQ13()
{
    int dq[13];
}
static __forceinline void DeadQ14()
{
    int dq[14];
}
static __forceinline void DeadQ15()
{
    int dq[15];
}
inline void Dead2()
{
    int a[2];
}
inline void Dead8()
{
    int a[8];
}
inline void Dead14()
{
    int a[14];
}
inline void Dead13()
{
    int a[13];
}
void __cdecl ReportAssertionViolation(const char* file, int line);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
struct FGValueQ
{
    float* data;
    void* owner;
    float* at(unsigned i)
    {
        return &data[i];
        DeadQ2();
    }
};
struct FaceGenRow
{
    float* m_p;
    unsigned m_uiValueCount;
    FaceGenRow(float* p, unsigned n) : m_p(p), m_uiValueCount(n)
    {}
    float* at(unsigned i)
    {
        float* p = &m_p[i];
        return p;
    }
    float& operator[](unsigned i)
    {
        return m_p[i];
    }
};
struct FGBaseQ
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    FGBaseQ();
    ~FGBaseQ();
};
struct FGMatQ : FGBaseQ
{
    unsigned int m_uiRowCount;
    unsigned int m_uiColumnCount;
    FGMatQ(unsigned rows, unsigned cols)
    {
        m_uiRowCount = rows;
        m_uiColumnCount = cols;
        unsigned n = m_uiColumnCount * m_uiRowCount;
        FUN_0060b410(n, 0.0f);
    }
    FGMatQ(const FGMatQ&);
    unsigned rows() const
    {
        return m_uiRowCount;
    }
    unsigned cols() const
    {
        return m_uiColumnCount;
    }
    bool empty() const
    {
        return rows() == 0 || cols() == 0;
    }
    float* FUN_006578b0(unsigned i) const;
    FaceGenRow row(unsigned i) const
    {
        return FaceGenRow(FUN_006578b0(0) + i * m_uiColumnCount, m_uiColumnCount);
    }
    FGValueQ FUN_0060b370(unsigned i);
    void FUN_0060b410(unsigned int count, float value);
};
// @fnv 0x00aaf330
FGMatQ FUN_00aaf330(const FGMatQ& a, FGMatQ& b)
{
    bool aEmpty = a.empty();
    bool bEmpty4 = b.empty();
    if (aEmpty && bEmpty4)
        return FGMatQ(0, 0);
    else if (aEmpty)
        return b;
    else if (bEmpty4)
        return a;
    Dead8();
    (a.cols() == b.cols())
        ? (void)0
        : ReportAssertionViolation("d:\\_fallout3\\platforms\\common\\code\\sdk\\facegen\\matrixVT.hpp", 0x4fe);
    FGMatQ r(a.rows() + b.rows(), a.cols());
    memcpy(r.row(0).at(0), a.row(0).at(0), a.rows() * a.cols() * sizeof(float));
    memcpy(r.FUN_0060b370(a.rows()).at(0), b.FUN_0060b370(0).at(0), b.rows() * b.cols() * sizeof(float));
    Dead14();
    return r;
}
}  // namespace fnv_00aaf330

struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
extern "C" int __cdecl memmove_s(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _MaxCount);
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
struct _Undefined_move_tagS
{
};
template <class _Ty> struct _Move_operation_categoryS
{
    typedef _Undefined_move_tagS _Move_cat;
};
template <class _Iter>
inline typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Move_catS(const _Iter&)
{
    typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Cat;
    return (_Cat);
}
template <class _InIt, class _FwdIt, class _Alloc, class _MoveCatTy>
inline _FwdIt _Uninit_moveS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _MoveCatTy,
                            _Range_checked_iterator_tagS)
{
    return (unchecked_uninitialized_copyS(_First, _Last, _Dest, _Al));
}
struct ElemMOVE
{
    int unk00;
    int unk04;
};
// @fnv 0x00aaf7e0
ElemMOVE* __cdecl FUN_00aaf7e0(ElemMOVE* _First, ElemMOVE* _Last, ElemMOVE* _Dest, allocatorS<ElemMOVE>& _Al)
{
    return (_Uninit_moveS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Move_catS(_Dest),
                          _Range_checked_iterator_tagS()));
}

struct PoolX
{
    void FUN_00aa4060(void* p);
};
extern "C" PoolX g_pool_011f6238;
inline void operator delete(void*, void*)
{}
struct FUN_00aaec10
{
    char b[0x3c];
    void FUN_006593e0();
    FUN_00aaec10(const FUN_00aaec10& o);
};
inline void Del(FUN_00aaec10* p, unsigned int f)
{
    p->FUN_006593e0();
    if (f & 1)
        g_pool_011f6238.FUN_00aa4060(p);
}
inline void DeadX()
{
    int x0;
    int x1;
    int x2;
    int x3;
    int x4;
    int x5;
    int x6;
    int x7;
    int x8;
    int x9;
    int x10;
    int x11;
    int x12;
    int x13;
    int x14;
    int x15;
    int x16;
    int x17;
    int x18;
    int x19;
    int x20;
    int x21;
    int x22;
}
inline void Construct(FUN_00aaec10* p, const FUN_00aaec10& v)
{
    void* vp = p;
    ::new (vp) FUN_00aaec10(v);
    DeadX();
}
// @fnv 0x00aaf8a0
void FUN_00aaf8a0(FUN_00aaec10* first, unsigned int count, const FUN_00aaec10& val)
{
    FUN_00aaec10* next = first;
    try
    {
        for (; 0 < count; --count, ++first)
            Construct(first, val);
    }
    catch (...)
    {
        for (; next != first; ++next)
            Del(next, 0);
        throw;
    }
}

namespace fnv_00aafa80 {
struct PoolX
{
    void FUN_00aa4060(void* p);
};
extern "C" PoolX g_pool_011f6238;
inline void operator delete(void*, void*)
{}
struct FUN_00aaec10
{
    char b[0x3c];
    void FUN_006593e0();
    FUN_00aaec10(const FUN_00aaec10& o);
};
inline void Del(FUN_00aaec10* p, unsigned int f)
{
    p->FUN_006593e0();
    if (f & 1)
        g_pool_011f6238.FUN_00aa4060(p);
}
inline void DeadX()
{
    int x0;
    int x1;
    int x2;
    int x3;
    int x4;
    int x5;
    int x6;
    int x7;
    int x8;
    int x9;
    int x10;
    int x11;
    int x12;
    int x13;
    int x14;
    int x15;
    int x16;
    int x17;
    int x18;
    int x19;
    int x20;
    int x21;
    int x22;
}
inline void Construct(FUN_00aaec10* p, const FUN_00aaec10& v)
{
    void* vp = p;
    ::new (vp) FUN_00aaec10(v);
    DeadX();
}
// @fnv 0x00aafa80
FUN_00aaec10* FUN_00aafa80(FUN_00aaec10* first, FUN_00aaec10* last, FUN_00aaec10* dest)
{
    FUN_00aaec10* next = dest;
    try
    {
        for (; first != last; ++dest, ++first)
            Construct(dest, *first);
    }
    catch (...)
    {
        for (; next != dest; ++next)
            Del(next, 0);
        throw;
    }
    return dest;
}
}  // namespace fnv_00aafa80

namespace fnv_00aafbe0 {
namespace std {
template <class T> struct char_traits
{
};
template <class T> class allocator
{
};
template <class E, class Tr, class A> class basic_string
{
  public:
    allocator<E> al;
    union
    {
        char buf[16];
        char* ptr;
    } bx;
    unsigned int mysize;
    unsigned int myres;
    basic_string(const E* p)
    {
        unsigned a0;
        a0 = 0;
        unsigned a1;
        a1 = 1;
        unsigned a2;
        a2 = 2;
        unsigned a3;
        a3 = 3;
        unsigned a4;
        a4 = 4;
        unsigned a5;
        a5 = 5;
        unsigned a6;
        a6 = 6;
        unsigned a7;
        a7 = 7;
        unsigned a8;
        a8 = 8;
        unsigned a9;
        a9 = 9;
        unsigned a10;
        a10 = 10;
        unsigned a11;
        a11 = 11;
        unsigned a12;
        a12 = 12;
        unsigned a13;
        a13 = 13;
        unsigned a14;
        a14 = 14;
        unsigned a15;
        a15 = 15;
        unsigned a16;
        a16 = 16;
        unsigned a17;
        a17 = 17;
        unsigned a18;
        a18 = 18;
        unsigned a19;
        a19 = 19;
        unsigned a20;
        a20 = 20;
        unsigned a21;
        a21 = 21;
        if (p == (const E*)0)
            return;
        basic_string again(p + 1);
        mysize = again.mysize + a0;
    }
    basic_string(const basic_string& other)
    {
        mysize = other.mysize;
    }
    ~basic_string()
    {}
};
typedef basic_string<char, char_traits<char>, allocator<char> > string;
}
struct FutBinaryFileC
{
    virtual ~FutBinaryFileC();
    std::string signature;
    std::string path;
    unsigned int unk3c;
    FutBinaryFileC(std::string);
    char FUN_00ac3fe0(const std::string&);
};
// @fnv 0x00aafbe0
char __cdecl FUN_00aafbe0(const std::string& name)
{
    FutBinaryFileC obj(std::string("FREGM002"));
    return obj.FUN_00ac3fe0(name);
}
}  // namespace fnv_00aafbe0

namespace fnv_00aafc80 {
extern unsigned int DAT_010173f0;
void __cdecl RuntimeFree(void*);
void __cdecl FUN_00ec7c56();
void __cdecl FUN_0044ccd0(char*, unsigned int, const char*, unsigned int);
void __cdecl FUN_00ec30e8();
namespace std {
template <class T> struct char_traits;
struct _Container_base
{
};
struct _String_base : _Container_base
{
};
template <class T> struct _Allocator_base
{
    typedef T value_type;
};
template <class T> class allocator : public _Allocator_base<T>
{
  public:
    allocator() throw();
    allocator(const allocator&) throw()
    {}
    void deallocate(char*, unsigned int);
};
template <class C, class Al> struct _String_val : _String_base
{
    Al _Alval;
    _String_val(const Al& a = Al()) : _Alval(a)
    {}
};
template <class C, class Tr, class Al> class basic_string : public _String_val<C, Al>
{
  public:
    union Storage
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    basic_string(const char* p)
    {
        _Tidy(false, 0);
        assign(p);
    }
    basic_string& assign(const char* p)
    {
        return assign(p, length(p));
    }
    static unsigned int length(const char* p);
    basic_string& assign(const char* p, unsigned int n);
    unsigned int size() const
    {
        return _Mysize;
    }
    char* _Myptr()
    {
        return _Myres < 16 ? _Bx._Buf : _Bx._Ptr;
    }
    const char* _Myptr() const
    {
        return _Myres < 16 ? _Bx._Buf : _Bx._Ptr;
    }
    char& operator[](unsigned int n)
    {
        if (_Mysize < n)
            FUN_00ec7c56();
        return _Myptr()[n];
    }
    int compare(unsigned int, unsigned int, const char*, unsigned int) const;
    basic_string& erase(unsigned int, unsigned int);
    unsigned int max_size() const;
    void _Copy(unsigned int, unsigned int);
    void _Xlen();
    bool _Grow(unsigned int n, bool trim)
    {
        if (max_size() < n)
            _Xlen();
        if (_Myres < n)
            _Copy(n, _Mysize);
        else if (trim && n < 16)
            _Tidy(true, n < _Mysize ? n : _Mysize);
        else if (n == 0)
            _Eos(0);
        return n > 0;
    }
    void _Eos(unsigned int);
    basic_string& assign(const basic_string& o, unsigned int pos, unsigned int count)
    {
        if (o.size() < pos)
            FUN_00ec30e8();
        unsigned int n = o.size() - pos;
        if (count < n)
            n = count;
        if (this == &o)
        {
            erase(pos + n, DAT_010173f0);
            erase(0, pos);
        }
        else if (_Grow(n, false))
        {
            FUN_0044ccd0(_Myptr(), _Myres, o._Myptr() + pos, n);
            _Eos(n);
        }
        return *this;
    }
    void _Tidy(bool built, unsigned int size)
    {
        if (built && _Myres >= 16)
        {
            char* p = _Bx._Ptr;
            if (size > 0)
                FUN_0044ccd0(_Bx._Buf, 16, p, size);
            this->_Alval.deallocate(p, _Myres + 1);
        }
        _Myres = 15;
        _Eos(size);
    }
    basic_string(const basic_string& o) : _String_val<C, Al>(o)
    {
        _Tidy(false, 0);
        assign(o, 0, DAT_010173f0);
    }
    ~basic_string()
    {
        _Tidy(true, 0);
    }
};
typedef basic_string<char, char_traits<char>, allocator<char> > Str;
}
struct Short3
{
    unsigned short a;
    unsigned short b;
    unsigned short c;
    Short3() : a(0), b(0), c(0)
    {}
};
struct Arr6
{
    int u0;
    int u4;
    int u8;
    Short3* begin;
    Short3* end;
    int u14;
    void FUN_00ab0b60(unsigned int cnt, Short3 t);
    void resize(unsigned int n)
    {
        FUN_00ab0b60(n, Short3());
    }
    unsigned int size() const
    {
        return end - begin;
    }
    Short3& operator[](unsigned int i)
    {
        if (i >= size())
            FUN_00ec7c56();
        return begin[i];
    }
};
struct Elem28
{
    float f;
    Arr6 arr;
};
struct VecIterator
{
    void* owner;
    Elem28* ptr;
};
struct Arr28
{
    int u0;
    int u4;
    int u8;
    Elem28* begin;
    Elem28* end;
    int u14;
    VecIterator CallWithSelf();
    VecIterator FUN_0044a170();
    VecIterator FUN_0065d740(VecIterator first, VecIterator last);
    __declspec(noinline) void FUN_0065cd70()
    {
        FUN_0065d740(FUN_0044a170(), CallWithSelf());
    }
    void FUN_00ab0a30(unsigned int n);
    unsigned int size() const
    {
        return end - begin;
    }
    Elem28& operator[](unsigned int i)
    {
        if (i >= size())
            FUN_00ec7c56();
        return begin[i];
    }
};
struct Hdr38
{
    unsigned int f0;
    unsigned int f4;
    unsigned int f8;
    unsigned int fC;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    void FUN_00aafbd0();
};
struct DeallocHeap
{
    virtual void v0();
    virtual void v1();
    virtual void* Alloc(unsigned int, int);
    virtual void Free(void*, int);
    virtual bool Contains(void*);
};
extern const char poolLockName[];
struct PoolLock
{
    unsigned int owner;
    unsigned int depth;
    void Lock(const char*);
    void Unlock()
    {
        if (--depth == 0)
            owner = 0;
    }
};
struct FreeBlock
{
    FreeBlock* prev;
    FreeBlock* next;
};
struct DeallocPool
{
    int unk00;
    char* begin;
    FreeBlock* freeList;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    PoolLock lock;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    unsigned short* pageCounts;
    int unk4c;
    unsigned int size;
    unsigned int freeCount;
    void PushFreeBlock(void* p)
    {
        FreeBlock* block = (FreeBlock*)p;
        block->prev = 0;
        block->next = freeList;
        if (freeList)
            freeList->prev = block;
        freeList = block;
        ++freeCount;
    }
    void FUN_00aa6c70(void* p)
    {
        if (!p)
            return;
        lock.Lock(poolLockName);
        PushFreeBlock(p);
        unsigned int page = ((unsigned int)p - (unsigned int)begin) >> 12;
        --pageCounts[page];
        lock.Unlock();
    }
    void* Alloc(unsigned int);
    bool contains(void* p)
    {
        return (char*)p >= begin && (char*)p < begin + size;
    }
};
extern DeallocPool* DAT_011f63b8[256];
struct MMDealloc
{
    unsigned char active;
    unsigned char unk001;
    unsigned short heapCount;
    int unk004;
    DeallocHeap** heaps;
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
    DeallocHeap* defaultHeap;
    void FreePointer(void* p, int)
    {
        RuntimeFree(p);
    }
    DeallocHeap* FindItemByArg(void* p)
    {
        for (unsigned short i = 0; i < heapCount; ++i)
        {
            DeallocHeap* h = heaps[i];
            if (h->Contains(p))
                return h;
        }
        return 0;
    }
    void FUN_00aa4060(void* p)
    {
        if (!p)
            return;
        if (!active)
        {
            FreePointer(p, 0);
            return;
        }
        DeallocHeap* fallback = defaultHeap;
        DeallocHeap* defaultAllocator = fallback;
        if (!defaultAllocator)
        {
            FreePointer(p, 0);
            return;
        }
        DeallocPool* pool = DAT_011f63b8[(unsigned int)p >> 24];
        if (pool && pool->contains(p))
        {
            pool->FUN_00aa6c70(p);
            return;
        }
        DeallocHeap* heap = FindItemByArg(p);
        if (heap)
            heap->Free(p, 0);
        else
            FreePointer(p, 0);
    }
};
extern P03MM g_memoryManager;
extern DeallocPool* smallPools[256];
DeallocPool* GetSmallPool(unsigned int);
unsigned int GetHeapIndex();
struct MMAlloc : MMDealloc
{
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    unsigned char unk128;
    unsigned char poolsActive;
    void* AllocateFallback(unsigned int, int);
    unsigned int HandleFailure(DeallocHeap*, unsigned int, bool*);
    void* Allocate(unsigned int n)
    {
        if (!active)
            return AllocateFallback(n, 0);
        DeallocHeap* fallback = defaultHeap;
        if (!fallback)
            return AllocateFallback(n, 0);
        unsigned int requested = n;
        void* result = 0;
        if (n <= 8)
            n = 8;
        else
            n = (n + 3) & ~3u;
        unsigned int index = GetHeapIndex();
        if (poolsActive)
        {
            DeallocPool* pool = n <= 0x3fc ? smallPools[n >> 2] : 0;
            if (!pool)
                pool = GetSmallPool(n);
            if (pool)
            {
                result = pool->Alloc(requested);
                if (result)
                    return result;
            }
        }
        bool retry = false;
        bool succeeded = false;
        unsigned int failures = 0;
        DeallocHeap* heap = 0;
        DeallocHeap* perThread = 0;
        perThread = ((DeallocHeap**)&unk00c)[index];
        do
        {
            heap = perThread ? perThread : fallback;
            result = heap->Alloc(n, 0);
            if (!result && heap != fallback)
            {
                heap = fallback;
                result = heap->Alloc(n, 0);
            }
            if (!result)
            {
                failures = HandleFailure(perThread ? perThread : fallback, failures, &retry);
                if (retry)
                {
                    result = AllocateFallback(n, 0);
                    succeeded = result != 0;
                }
            }
        } while (!result);
        return result;
    }
};
inline void* AllocateBytes(unsigned int n)
{
    return ((MMAlloc*)&g_memoryManager)->Allocate(n);
}
extern void* DAT_010a2c38;
struct FUN_00aaaa80
{
    std::Str name;
    std::Str path;
    int unk3c;
    FUN_00aaaa80(std::Str s);
    virtual ~FUN_00aaaa80();
    void FUN_00ac5430();
};
struct ReaderStream
{
    virtual ~ReaderStream();
};
struct ReaderReference
{
    int unk00;
    int unk04;
    ReaderStream* stream;
    unsigned char unk0c;
    unsigned char used;
    void AddRef();
    void Release();
};
struct ReaderDirectory
{
    ReaderReference* Find(const char*);
};
extern ReaderDirectory* readerDirectory;
ReaderStream* OpenReaderStream(const char*, int, int, int);
void ReportReaderError(unsigned int, std::Str);
extern unsigned int ReaderStringLength(const char*);
struct ReaderRef
{
    ReaderReference* p;
    ReaderRef(ReaderReference* q) : p(q)
    {
        if (p)
            p->AddRef();
    }
    ~ReaderRef()
    {
        if (p)
            p->Release();
    }
};
struct ReaderChars
{
    int unk00;
    int unk04;
    int unk08;
    char* first;
    char* last;
    char* capacity;
    ReaderChars(unsigned int);
    ReaderChars(const ReaderChars&);
    void Destroy();
    ~ReaderChars()
    {
        Destroy();
        ((MMDealloc*)&g_memoryManager)->FUN_00aa4060(first);
    }
    char& operator[](unsigned int i)
    {
        if (i >= (unsigned int)(last - first))
            FUN_00ec7c56();
        return first[i];
    }
    char* begin()
    {
        if (last == first)
            FUN_00ec7c56();
        return first;
    }
};
struct FUN_00ac5490 : FUN_00aaaa80
{
    int m40;
    int m44;
    FUN_00ac5490(std::Str s) : FUN_00aaaa80(s), m40(0), m44(0)
    {}
    virtual ~FUN_00ac5490()
    {
        ClearHolders();
    }
    void ClearHolders()
    {
        if (m44)
        {
            m40 = 0;
            ((ReaderReference*)m44)->Release();
            m44 = 0;
        }
        else
        {
            delete (ReaderStream*)m40;
            m40 = 0;
        }
    }
    unsigned char FUN_00ac5540(std::Str s, int z)
    {
        int mode = z ? 0x100 : 1;
        ReaderRef reference(readerDirectory ? readerDirectory->Find(s._Myptr()) : 0);
        if (reference.p)
        {
            m44 = (int)reference.p;
            reference.p->AddRef();
            reference.p->used = true;
            m40 = (int)reference.p->stream;
        }
        else
            m40 = (int)OpenReaderStream(s._Myptr(), 0, 0x2800, mode);
        if (!m40)
        {
            ReportReaderError(4, s);
            return 0;
        }
        ReaderChars raw(path.size() + 1);
        if (!FUN_00ac5e00(raw.begin(), path.size(), 1))
            return 0;
        ReaderChars signature(raw);
        signature[5] = path[5];
        if (path.compare(0, path.size(), signature.begin(), ReaderStringLength(signature.begin())) != 0)
        {
            ReportReaderError(2, s);
            ClearHolders();
            return 0;
        }
        if (raw[5] > '0' && path[5] != raw[5])
        {
            ReportReaderError(4, s);
            ClearHolders();
            return 0;
        }
        path[5] = raw[5];
        name.assign(s, 0, DAT_010173f0);
        return m40 != 0;
    }
    unsigned char FUN_00ac5e00(void* buf, int a, int b);
    unsigned char FUN_00ac5cf0(void* buf, int a, int b);
    unsigned char FUN_00ac5c70(void* buf, int n);
};
static const char signatureText[] = "FREGM002";
// @fnv 0x00aafc80
unsigned char __cdecl FUN_00aafc80(const std::Str& pStr, int* pOut, Arr28* pA, Arr28* pB)
{
    float val;
    long p2;
    unsigned short* _res;
    {
        FUN_00ac5490 obj4((std::Str(signatureText)));
        if (!obj4.FUN_00ac5540(pStr, 0))
        {
            return 0;
        }
        Hdr38 hdr;
        if (!obj4.FUN_00ac5e00(&hdr, 1, 0x38))
        {
            return 0;
        }
        hdr.FUN_00aafbd0();
        *pOut = hdr.fC;
        pA->FUN_0065cd70();
        pB->FUN_0065cd70();
        pA->FUN_00ab0a30(hdr.f4);
        pB->FUN_00ab0a30(hdr.f8);
        {
            _res = (unsigned short*)AllocateBytes(hdr.f0 * 6);
            for (p2 = 0; p2 < hdr.f4; ++p2)
            {
                Elem28* e = &(*pA)[p2];
                (*pA)[p2].arr.resize(hdr.f0);
                if (!obj4.FUN_00ac5cf0(&val, 4, 1))
                    return 0;
                (*pA)[p2].f = val;
                if (!obj4.FUN_00ac5c70(_res, hdr.f0 * 3))
                    return 0;
                unsigned int index;
                for (index = 0; index + 3 < hdr.f0; index += 4)
                {
                    Short3* p0 = &e->arr[index];
                    Short3* item = &e->arr[index + 1];
                    Short3* first = &e->arr[index + 2];
                    Short3* entry = &e->arr[index + 3];
                    p0->a = _res[index * 3];
                    p0->b = _res[index * 3 + 1];
                    p0->c = _res[index * 3 + 2];
                    item->a = _res[(index + 1) * 3 + 0];
                    item->b = _res[(index + 1) * 3 + 1];
                    item->c = _res[(index + 1) * 3 + 2];
                    first->a = _res[(index + 2) * 3 + 0];
                    first->b = _res[(index + 2) * 3 + 1];
                    first->c = _res[(index + 2) * 3 + 2];
                    entry->a = _res[(index + 3) * 3 + 0];
                    entry->b = _res[(index + 3) * 3 + 1];
                    entry->c = _res[(index + 3) * 3 + 2];
                }
                for (; index < hdr.f0; ++index)
                {
                    e->arr[index].a = _res[index * 3];
                    e->arr[index].b = _res[index * 3 + 1];
                    e->arr[index].c = _res[index * 3 + 2];
                }
            }
            for (p2 = 0; p2 < hdr.f8; ++p2)
            {
                Elem28* e = &(*pB)[p2];
                e->arr.resize(hdr.f0);
                if (!obj4.FUN_00ac5cf0(&val, 4, 1))
                    return 0;
                e->f = val;
                if (!obj4.FUN_00ac5c70(_res, hdr.f0 * 3))
                    return 0;
                unsigned int index;
                for (index = 0; index + 3 < hdr.f0; index += 4)
                {
                    Short3* p0 = &e->arr[index];
                    Short3* item = &e->arr[index + 1];
                    Short3* first = &e->arr[index + 2];
                    Short3* entry = &e->arr[index + 3];
                    p0->a = _res[index * 3];
                    p0->b = _res[index * 3 + 1];
                    p0->c = _res[index * 3 + 2];
                    item->a = _res[(index + 1) * 3 + 0];
                    item->b = _res[(index + 1) * 3 + 1];
                    item->c = _res[(index + 1) * 3 + 2];
                    first->a = _res[(index + 2) * 3 + 0];
                    first->b = _res[(index + 2) * 3 + 1];
                    first->c = _res[(index + 2) * 3 + 2];
                    entry->a = _res[(index + 3) * 3 + 0];
                    entry->b = _res[(index + 3) * 3 + 1];
                    entry->c = _res[(index + 3) * 3 + 2];
                }
                for (; index < hdr.f0; ++index)
                {
                    e->arr[index].a = _res[index * 3];
                    e->arr[index].b = _res[index * 3 + 1];
                    e->arr[index].c = _res[index * 3 + 2];
                }
            }
            if (_res)
                ((MMDealloc*)&g_memoryManager)->FUN_00aa4060(_res);
        }
        return 1;
    }
}
}  // namespace fnv_00aafc80

int g_sink;

struct Ab0a30Chunk
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    Ab0a30Chunk();
    Ab0a30Chunk(const Ab0a30Chunk&);
    ~Ab0a30Chunk();
};
struct Ab0a30Msg
{
    int unk00;
    Ab0a30Chunk chunk;
};
struct Ab0a30Owner
{
    int unk00;
    void FUN_00ab0d50(int arg, Ab0a30Msg msg);
    void FUN_00ab0a30(int a0);
};
inline Ab0a30Chunk::Ab0a30Chunk()
{
    unsigned int d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16, d17, d18, d19, d20, d21,
        d22, d23, d24, d25;
    d0 = g_sink;
    d1 = d0;
    d2 = d1;
    d3 = d2;
    d4 = d3;
    d5 = d4;
    d6 = d5;
    d7 = d6;
    d8 = d7;
    d9 = d8;
    d10 = d9;
    d11 = d10;
    d12 = d11;
    d13 = d12;
    d14 = d13;
    d15 = d14;
    d16 = d15;
    d17 = d16;
    d18 = d17;
    d19 = d18;
    d20 = d19;
    d21 = d20;
    d22 = d21;
    d23 = d22;
    d24 = d23;
    d25 = d24;
    d0 = d25 + 1;
    d1 = d0 + 1;
    d2 = d1 + 1;
    d3 = d2 + 1;
    d4 = d3 + 1;
    d5 = d4 + 1;
    d6 = d5 + 1;
    d7 = d6 + 1;
    d8 = d7 + 1;
    d9 = d8 + 1;
    d10 = d9 + 1;
    d11 = d10 + 1;
    d12 = d11 + 1;
    d13 = d12 + 1;
    d14 = d13 + 1;
    d15 = d14 + 1;
    d16 = d15 + 1;
    d17 = d16 + 1;
    d18 = d17 + 1;
    d19 = d18 + 1;
    d20 = d19 + 1;
    d21 = d20 + 1;
    d22 = d21 + 1;
    d23 = d22 + 1;
    d24 = d23 + 1;
    d25 = d24 + 1;
    d0 = d1 | 1;
    d1 = d2 | 1;
    d2 = d3 | 1;
    d3 = d4 | 1;
    d4 = d5 | 1;
    d5 = d6 | 1;
    d6 = d7 | 1;
    d7 = d8 | 1;
    d8 = d9 | 1;
    d9 = d10 | 1;
    d10 = d11 | 1;
    d11 = d12 | 1;
    d12 = d13 | 1;
    d13 = d14 | 1;
    d14 = d15 | 1;
    d15 = d16 | 1;
    d16 = d17 | 1;
    d17 = d18 | 1;
    d18 = d19 | 1;
    d19 = d20 | 1;
    d20 = d21 | 1;
    d21 = d22 | 1;
    d22 = d23 | 1;
    d23 = d24 | 1;
    d24 = d25 | 1;
    d25 = d0 | 1;
    g_sink = d0;
}
inline void Ab0a30Owner::FUN_00ab0d50(int arg, Ab0a30Msg msg)
{
    unsigned int e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21,
        e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43,
        e44;
    e0 = g_sink + arg;
    e1 = e0;
    e2 = e1;
    e3 = e2;
    e4 = e3;
    e5 = e4;
    e6 = e5;
    e7 = e6;
    e8 = e7;
    e9 = e8;
    e10 = e9;
    e11 = e10;
    e12 = e11;
    e13 = e12;
    e14 = e13;
    e15 = e14;
    e16 = e15;
    e17 = e16;
    e18 = e17;
    e19 = e18;
    e20 = e19;
    e21 = e20;
    e22 = e21;
    e23 = e22;
    e24 = e23;
    e25 = e24;
    e26 = e25;
    e27 = e26;
    e28 = e27;
    e29 = e28;
    e30 = e29;
    e31 = e30;
    e32 = e31;
    e33 = e32;
    e34 = e33;
    e35 = e34;
    e36 = e35;
    e37 = e36;
    e38 = e37;
    e39 = e38;
    e40 = e39;
    e41 = e40;
    e42 = e41;
    e43 = e42;
    e44 = e43;
    e0 = e44 + 1;
    e1 = e0 + 1;
    e2 = e1 + 1;
    e3 = e2 + 1;
    e4 = e3 + 1;
    e5 = e4 + 1;
    e6 = e5 + 1;
    e7 = e6 + 1;
    e8 = e7 + 1;
    e9 = e8 + 1;
    e10 = e9 + 1;
    e11 = e10 + 1;
    e12 = e11 + 1;
    e13 = e12 + 1;
    e14 = e13 + 1;
    e15 = e14 + 1;
    e16 = e15 + 1;
    e17 = e16 + 1;
    e18 = e17 + 1;
    e19 = e18 + 1;
    e20 = e19 + 1;
    e21 = e20 + 1;
    e22 = e21 + 1;
    e23 = e22 + 1;
    e24 = e23 + 1;
    e25 = e24 + 1;
    e26 = e25 + 1;
    e27 = e26 + 1;
    e28 = e27 + 1;
    e29 = e28 + 1;
    e30 = e29 + 1;
    e31 = e30 + 1;
    e32 = e31 + 1;
    e33 = e32 + 1;
    e34 = e33 + 1;
    e35 = e34 + 1;
    e36 = e35 + 1;
    e37 = e36 + 1;
    e38 = e37 + 1;
    e39 = e38 + 1;
    e40 = e39 + 1;
    e41 = e40 + 1;
    e42 = e41 + 1;
    e43 = e42 + 1;
    e44 = e43 + 1;
    g_sink = e0;
}
// @fnv 0x00ab0a30
void Ab0a30Owner::FUN_00ab0a30(int a0)
{
    this->FUN_00ab0d50(a0, Ab0a30Msg());
}

namespace fnv_00ab0a80 {
void* __cdecl FUN_0044d670(unsigned int, int);
void __cdecl FUN_0064df10(void*, unsigned int);
inline void __cdecl operator delete(void*, void*)
{}
struct AuxCont;
struct ContainerBase
{
    AuxCont* owned;
    ContainerBase()
    {}
    ContainerBase(const ContainerBase&)
    {}
    ~ContainerBase()
    {}
};
struct AuxCont
{
    explicit AuxCont(const ContainerBase* const cont) : container(cont)
    {}
    const ContainerBase* container;
};
template <class T> struct GameAlloc
{
    typedef T value_type;
    typedef T* pointer;
    typedef unsigned int size_type;
    template <class U> struct rebind
    {
        typedef GameAlloc<U> other;
    };
    GameAlloc()
    {}
    GameAlloc(const GameAlloc&)
    {}
    template <class U> GameAlloc(const GameAlloc<U>&)
    {}
    pointer allocate(size_type count)
    {
        return (pointer)FUN_0044d670(count, 0);
    }
    void deallocate(pointer ptr, size_type)
    {
        FUN_0064df10(ptr, 1);
    }
    size_type max_size() const
    {
        size_type count = (size_type)(-1) / sizeof(T);
        return 0 < count ? count : 1;
    }
};
template <class Alloc> struct BaseAlloc : ContainerBase
{
    typename Alloc::template rebind<AuxCont>::other alaux;
    explicit BaseAlloc(Alloc al) : alaux(al)
    {
        owned = new (alaux.allocate(1)) AuxCont(this);
    }
    ~BaseAlloc()
    {
        alaux.deallocate(owned, 1);
    }
};
struct Short3
{
    short x, y, z;
};
template <class T, class Alloc> struct VectorVal : BaseAlloc<Alloc>
{
    typedef unsigned int size_type;
    typename Alloc::template rebind<T>::other alval;
    T* first;
    T* last;
    T* endp;
    VectorVal(Alloc al = Alloc()) : BaseAlloc<Alloc>(al), alval(al)
    {}
    size_type max_size() const
    {
        return this->alval.max_size();
    }
    bool FUN_0065f380(size_type capacity)
    {
        first = 0, last = 0, endp = 0;
        if (capacity == 0)
            return false;
        else if (max_size() < capacity)
            Xlen();
        else
        {
            first = this->alval.allocate(capacity);
            last = first;
            endp = first + capacity;
        }
        return true;
    }
    static void Xlen()
    {
        int v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22,
            v23, v24, v25, v26, v27, v28, v29;
        v0 = 1;
        v1 = v0 + 1;
        v2 = v1 + 2;
        v3 = v2 + 3;
        v4 = v3 + 4;
        v5 = v4 + 5;
        v6 = v5 + 6;
        v7 = v6 + 7;
        v8 = v7 + 8;
        v9 = v8 + 9;
        v10 = v9 + 10;
        v11 = v10 + 11;
        v12 = v11 + 12;
        v13 = v12 + 13;
        v14 = v13 + 14;
        v15 = v14 + 15;
        v16 = v15 + 16;
        v17 = v16 + 17;
        v18 = v17 + 18;
        v19 = v18 + 19;
        v20 = v19 + 20;
        v21 = v20 + 21;
        v22 = v21 + 22;
        v23 = v22 + 23;
        v24 = v23 + 24;
        v25 = v24 + 25;
        v26 = v25 + 26;
        v27 = v26 + 27;
        v28 = v27 + 28;
        v29 = v28 + 29;
        if (v29 == 0)
            return;
    }
};
struct FUN_00ab0a80 : VectorVal<Short3, GameAlloc<Short3> >
{
    FUN_00ab0a80();
};
// @fnv 0x00ab0a80
FUN_00ab0a80::FUN_00ab0a80() : VectorVal<Short3, GameAlloc<Short3> >()
{
    FUN_0065f380(0);
}
}  // namespace fnv_00ab0a80

namespace fnv_00ab0b60 {
inline void Dead31()
{
    int d[23];
}
struct ElQ_ab0b60
{
    short m0, m1, m2;
};
struct VecQ_ab0b60;
struct CItQ_ab0b60_ab0b60
{
    void* _Myaux;
    ElQ_ab0b60* _Myptr;
    CItQ_ab0b60_ab0b60()
    {}
    CItQ_ab0b60_ab0b60(ElQ_ab0b60* _Ptr, const VecQ_ab0b60* _Pvector);
    CItQ_ab0b60_ab0b60& FUN_00ab2150(int _Off);
};
struct ItQ_ab0b60 : CItQ_ab0b60_ab0b60
{
    ItQ_ab0b60()
    {}
    ItQ_ab0b60(ElQ_ab0b60* _Ptr, const VecQ_ab0b60* _Pvector) : CItQ_ab0b60_ab0b60(_Ptr, _Pvector)
    {}
    ItQ_ab0b60& operator+=(int _Off)
    {
        (*(CItQ_ab0b60_ab0b60*)this).FUN_00ab2150(_Off);
        return (*this);
    }
    ItQ_ab0b60 operator+(int _Off) const
    {
        ItQ_ab0b60 _Tmp = *this;
        return (_Tmp += _Off);
    }
};
struct VecQ_ab0b60
{
    void* _Myownedaux;
    int m04;
    int m08;
    ElQ_ab0b60* _Myfirst;
    ElQ_ab0b60* _Mylast;
    ElQ_ab0b60* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    ItQ_ab0b60 begin()
    {
        return ItQ_ab0b60(_Myfirst, this);
    }
    ItQ_ab0b60 end()
    {
        return ItQ_ab0b60(_Mylast, this);
    }
    void FUN_00ab0fd0(CItQ_ab0b60_ab0b60 _Where, unsigned int _Count, const ElQ_ab0b60& _Val);
    ItQ_ab0b60 FUN_0065f5a0(CItQ_ab0b60_ab0b60 _First, CItQ_ab0b60_ab0b60 _Last);
    void FUN_00ab0b60(unsigned int _Newsize, ElQ_ab0b60 _Val);
};
inline CItQ_ab0b60_ab0b60::CItQ_ab0b60_ab0b60(ElQ_ab0b60* _Ptr, const VecQ_ab0b60* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        FUN_00ec7c56();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00ab0b60
void VecQ_ab0b60::FUN_00ab0b60(unsigned int _Newsize, ElQ_ab0b60 _Val)
{

    if (size() < _Newsize)
        FUN_00ab0fd0(end(), _Newsize - size(), _Val);
    else if (_Newsize < size())
    {
        FUN_0065f5a0(begin() + _Newsize, end());
        Dead31();
    }
}
}  // namespace fnv_00ab0b60

void __cdecl InvalidParameterNoInfoXB2150();
struct ContainerBaseAuxXB2150
{
};
class AuxContXB2150
{
  public:
    const ContainerBaseAuxXB2150* _Getcont() const
    {
        return _Mycontainer;
    }
    const ContainerBaseAuxXB2150* _Mycontainer;
};
class IteratorBaseAuxXB2150
{
  public:
    const ContainerBaseAuxXB2150* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    AuxContXB2150* _Myaux;
};
struct ElemXB2150
{
    short unk00;
    short unk02;
    short unk04;
};
struct VectorXB2150 : public ContainerBaseAuxXB2150
{
    AuxContXB2150* _Myownedaux;
    int _Alaux;
    int _Alval;
    ElemXB2150* _Myfirst;
    ElemXB2150* _Mylast;
    ElemXB2150* _Myend;
};
class FUN_00ab2150_It : public IteratorBaseAuxXB2150
{
  public:
    FUN_00ab2150_It& FUN_00ab2150(int _Off);
    ElemXB2150* _Myptr;
};

// @fnv 0x00ab2150
FUN_00ab2150_It& FUN_00ab2150_It::FUN_00ab2150(int _Off)
{
    if (!(this->_Has_container()))
        InvalidParameterNoInfoXB2150();
    if (!(_Myptr + _Off <= ((VectorXB2150*)this->_Getmycont())->_Mylast &&
          _Myptr + _Off >= ((VectorXB2150*)this->_Getmycont())->_Myfirst))
        InvalidParameterNoInfoXB2150();
    _Myptr += _Off;
    return *this;
}

namespace fnv_00ab2490 {
struct FUN_0065fb10_Class
{
    int a0, a1, a2, a3, a4, a5;
    inline void FUN_0065fb10(const FUN_0065fb10_Class& src)
    {
        unsigned n0, n1, n2, n3, n4, n5, n6, n7, n8, n9;
        FUN_0065fb10(src);
    }
};
struct FUN_0065ecd0_class
{
    float f;
    FUN_0065fb10_Class sub;
    void* FUN_0065ecd0(unsigned int);
    FUN_0065ecd0_class(const FUN_0065ecd0_class& o)
    {
        f = o.f;
        sub.FUN_0065fb10(o.sub);
    }
};
inline void operator delete(void*, void*)
{}
// @fnv 0x00ab2490
void FUN_00ab2490(FUN_0065ecd0_class* first, unsigned int count, const FUN_0065ecd0_class& val)
{
    FUN_0065ecd0_class* next = first;
    try
    {
        for (; 0 < count; --count, ++first)
        {
            void* vptr = first;
            new (vptr) FUN_0065ecd0_class(val);
        }
    }
    catch (...)
    {
        for (; next != first; ++next)
            next->FUN_0065ecd0(0);
        throw;
    }
}
}  // namespace fnv_00ab2490

namespace fnv_00ab2f50 {
inline void Dead31()
{
    int d[19];
}
struct ElQ_ab2f50
{
    char c;
};
struct VecQ_ab2f50;
struct CItQ_ab2f50_ab2f50
{
    void* _Myaux;
    ElQ_ab2f50* _Myptr;
    CItQ_ab2f50_ab2f50()
    {}
    CItQ_ab2f50_ab2f50(ElQ_ab2f50* _Ptr, const VecQ_ab2f50* _Pvector);
    CItQ_ab2f50_ab2f50& FUN_00ab43d0(int _Off);
};
struct ItQ_ab2f50 : CItQ_ab2f50_ab2f50
{
    ItQ_ab2f50()
    {}
    ItQ_ab2f50(ElQ_ab2f50* _Ptr, const VecQ_ab2f50* _Pvector) : CItQ_ab2f50_ab2f50(_Ptr, _Pvector)
    {}
    ItQ_ab2f50& operator+=(int _Off)
    {
        (*(CItQ_ab2f50_ab2f50*)this).FUN_00ab43d0(_Off);
        return (*this);
    }
    ItQ_ab2f50 operator+(int _Off) const
    {
        ItQ_ab2f50 _Tmp = *this;
        return (_Tmp += _Off);
    }
};
struct VecQ_ab2f50
{
    void* _Myownedaux;
    int m04;
    int m08;
    ElQ_ab2f50* _Myfirst;
    ElQ_ab2f50* _Mylast;
    ElQ_ab2f50* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    ItQ_ab2f50 begin()
    {
        return ItQ_ab2f50(_Myfirst, this);
    }
    ItQ_ab2f50 end()
    {
        return ItQ_ab2f50(_Mylast, this);
    }
    void FUN_00ab3370(CItQ_ab2f50_ab2f50 _Where, unsigned int _Count, const ElQ_ab2f50& _Val);
    ItQ_ab2f50 FUN_0065f700(CItQ_ab2f50_ab2f50 _First, CItQ_ab2f50_ab2f50 _Last);
    void FUN_00ab2f50(unsigned int _Newsize, ElQ_ab2f50 _Val);
};
inline CItQ_ab2f50_ab2f50::CItQ_ab2f50_ab2f50(ElQ_ab2f50* _Ptr, const VecQ_ab2f50* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        FUN_00ec7c56();
    do
    {
    } while (0);
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00ab2f50
void VecQ_ab2f50::FUN_00ab2f50(unsigned int _Newsize, ElQ_ab2f50 _Val)
{

    if (size() < _Newsize)
        FUN_00ab3370(end(), _Newsize - size(), _Val);
    else if (_Newsize < size())
    {
        FUN_0065f700(begin() + _Newsize, end());
        Dead31();
    }
}
}  // namespace fnv_00ab2f50

namespace fnv_00ab3130 {
inline void DeadN()
{
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
    int d8;
    int d9;
    int d10;
    int d11;
    int d12;
    int d13;
    int d14;
    int d15;
    int d16;
    int d17;
    int d18;
    int d19;
    int d20;
}
struct ElX
{
    int m[6];
    ElX(const ElX&);
    ~ElX();
};
struct ElQ
{
    int h[4];
    ElX a[3];
};
struct VecQ_ab3130;
struct CItQ_ab3130_ab3130
{
    void* _Myaux;
    ElQ* _Myptr;
    CItQ_ab3130_ab3130()
    {}
    CItQ_ab3130_ab3130(ElQ* _Ptr, const VecQ_ab3130* _Pvector);
    CItQ_ab3130_ab3130& FUN_00ab4310(int _Off);
};
struct ItQ_ab3130 : CItQ_ab3130_ab3130
{
    ItQ_ab3130()
    {}
    ItQ_ab3130(ElQ* _Ptr, const VecQ_ab3130* _Pvector) : CItQ_ab3130_ab3130(_Ptr, _Pvector)
    {}
    ItQ_ab3130& operator+=(int _Off)
    {
        (*(CItQ_ab3130_ab3130*)this).FUN_00ab4310(_Off);
        return (*this);
    }
    ItQ_ab3130 operator+(int _Off) const
    {
        ItQ_ab3130 _Tmp = *this;
        return (_Tmp += _Off);
    }
};
struct VecQ_ab3130
{
    void* _Myownedaux;
    int m04;
    int m08;
    ElQ* _Myfirst;
    ElQ* _Mylast;
    ElQ* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    ItQ_ab3130 begin()
    {
        return ItQ_ab3130(_Myfirst, this);
    }
    ItQ_ab3130 end()
    {
        return ItQ_ab3130(_Mylast, this);
    }
    void FUN_00ab3a40(CItQ_ab3130_ab3130 _Where, unsigned int _Count, const ElQ& _Val);
    ItQ_ab3130 BuildAndComparePair(CItQ_ab3130_ab3130 _First, CItQ_ab3130_ab3130 _Last);
    void FUN_00ab3130(unsigned int _Newsize, ElQ _Val);
};
inline CItQ_ab3130_ab3130::CItQ_ab3130_ab3130(ElQ* _Ptr, const VecQ_ab3130* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        FUN_00ec7c56();
    do
    {
    } while (0);
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00ab3130
void VecQ_ab3130::FUN_00ab3130(unsigned int _Newsize, ElQ _Val)
{
    if (size() < _Newsize)
        FUN_00ab3a40(end(), _Newsize - size(), _Val);
    else if (_Newsize < size())
    {
        BuildAndComparePair(begin() + _Newsize, end());
        DeadN();
    }
}
}  // namespace fnv_00ab3130

struct VectorAllocator
{
};
struct ScalarIteratorTag
{
};
struct CheckedIteratorTag
{
};
struct AllocationExceptionBase
{
    virtual ~AllocationExceptionBase() throw();
    const char* message;
    bool ownsMessage;
    AllocationExceptionBase(const char*);
};
struct AllocationFailure : AllocationExceptionBase
{
    AllocationFailure(const char* _Message) throw() : AllocationExceptionBase(_Message)
    {}
};
void* __cdecl operator new(unsigned int);
extern "C" inline char* __cdecl AllocateChecked(unsigned int _Count, int)
{
    if (_Count <= 0)
        _Count = 0;
    else if ((unsigned int)-1 / _Count < 1)
        throw AllocationFailure(0);
    return (char*)operator new(_Count);
}
char* __cdecl FUN_0065fea0(char*, char*, char*, VectorAllocator*);
struct ExceptionString
{
    unsigned int allocatorState;
    union
    {
        char localBuffer[16];
        char* heapBuffer;
    } storage;
    unsigned int size;
    unsigned int capacity;
    ExceptionString(const char*);
    ~ExceptionString();
};
struct LengthFailure
{
    virtual ~LengthFailure() throw();
    const char* message;
    bool ownsMessage;
    ExceptionString text;
    LengthFailure(const ExceptionString&);
};
inline void __cdecl FUN_00ac3300(char*, unsigned int, const char&);
inline ScalarIteratorTag pointer_category(char*&, char*&)
{
    ScalarIteratorTag _Cat;
    return _Cat;
}
struct UnchangedIteratorTag
{
};
inline char* checked_base_impl(char*& _It, UnchangedIteratorTag)
{
    return _It;
}
inline char* checked_base(char*& _It)
{
    UnchangedIteratorTag _Base_tag;
    return checked_base_impl(_It, _Base_tag);
}
struct RandomAccessIteratorTag
{
};
inline RandomAccessIteratorTag iterator_category(char*&)
{
    RandomAccessIteratorTag _Cat;
    return _Cat;
}
inline void fill_n_loop(char* _First, unsigned int _Count, const char& _Val, CheckedIteratorTag)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
inline void fill_n_dispatch(char* _First, unsigned int _Count, const char& _Val, RandomAccessIteratorTag,
                            CheckedIteratorTag)
{
    char* _Last = _First + _Count;
    (void)_Last;
    fill_n_loop(checked_base(_First), _Count, _Val, CheckedIteratorTag());
}
inline void __cdecl FUN_00ac3300(char* _First, unsigned int _Count, const char& _Val)
{
    fill_n_dispatch(_First, _Count, _Val, iterator_category(_First), CheckedIteratorTag());
}
inline char* copy_dispatch(char* _First, char* _Last, char* _Dest, VectorAllocator& _Al, ScalarIteratorTag,
                           CheckedIteratorTag)
{
    return FUN_0065fea0(_First, _Last, _Dest, &_Al);
}
inline char* unchecked_copy(char* _First, char* _Last, char* _Dest, VectorAllocator& _Al)
{
    return copy_dispatch(checked_base(_First), checked_base(_Last), _Dest, _Al, pointer_category(_First, _Dest),
                         CheckedIteratorTag());
}
inline void fill_dispatch(char* _First, unsigned int _Count, const char& _Val, VectorAllocator& _Al, ScalarIteratorTag,
                          CheckedIteratorTag)
{
    FUN_00ac3300(checked_base(_First), _Count, _Val);
}
inline void unchecked_fill(char* _First, unsigned int _Count, const char& _Val, VectorAllocator& _Al)
{
    fill_dispatch(_First, _Count, _Val, _Al, pointer_category(_First, _First), CheckedIteratorTag());
}
inline void destroy_dispatch(char* _First, char* _Last, VectorAllocator& _Al, ScalarIteratorTag)
{}
inline void destroy_range(char* _First, char* _Last, VectorAllocator& _Al)
{
    destroy_dispatch(_First, _Last, _Al, pointer_category(_First, _Last));
}
inline void fill_loop(char* _First, char* _Last, const char& _Val)
{
    for (; _First != _Last; ++_First)
        *_First = _Val;
}
inline void fill_range(char* _First, char* _Last, const char& _Val)
{
    fill_loop(checked_base(_First), checked_base(_Last), _Val);
}
extern int __cdecl FUN_00ec7ce3(void*, unsigned int, const void*, unsigned int);
inline char* scalar_copy(char* _First, char* _Last, char* _Dest, VectorAllocator&, ScalarIteratorTag,
                         CheckedIteratorTag)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    char* _Result = _Dest + _Count;
    if (_Count > 0)
        FUN_00ec7ce3(_Dest, _Count, _First, _Count);
    return _Result;
}
inline char* copy_mutable(char* _First, char* _Last, char* _Dest, VectorAllocator& _Al)
{
    return scalar_copy(checked_base(_First), checked_base(_Last), _Dest, _Al, pointer_category(_First, _Dest),
                       CheckedIteratorTag());
}
inline char* move_mutable(char* _First, char* _Last, char* _Dest, VectorAllocator& _Al, ScalarIteratorTag,
                          CheckedIteratorTag)
{
    return copy_mutable(_First, _Last, _Dest, _Al);
}
inline char* __cdecl FUN_00ad5e20(char* _First, char* _Last, char* _Dest, VectorAllocator* _Al)
{
    return move_mutable(checked_base(_First), checked_base(_Last), _Dest, *_Al, pointer_category(_Dest, _Dest),
                        CheckedIteratorTag());
}
inline RandomAccessIteratorTag iter_random(char*&, char*&)
{
    RandomAccessIteratorTag _Cat;
    return _Cat;
}
inline char* backward_scalar(char* _First, char* _Last, char* _Dest, RandomAccessIteratorTag, ScalarIteratorTag,
                             CheckedIteratorTag)
{
    int _Off = _Last - _First;
    char* _Result = _Dest - _Off;
    if (_Off > 0)
        FUN_00ec7ce3(_Result, _Off, _First, _Off);
    return _Result;
}
inline char* backward_copy(char* _First, char* _Last, char* _Dest)
{
    return backward_scalar(checked_base(_First), checked_base(_Last), _Dest, iter_random(_First, _Dest),
                           pointer_category(_First, _Dest), CheckedIteratorTag());
}
inline char* backward_move(char* _First, char* _Last, char* _Dest, RandomAccessIteratorTag _First_dest_cat,
                           ScalarIteratorTag, CheckedIteratorTag)
{
    return backward_scalar(_First, _Last, _Dest, _First_dest_cat, pointer_category(_First, _Dest),
                           CheckedIteratorTag());
}
inline char* __cdecl FUN_00ab4490(char* _First, char* _Last, char* _Dest)
{
    return backward_move(checked_base(_First), checked_base(_Last), _Dest, iter_random(_First, _Dest),
                         pointer_category(_First, _Dest), CheckedIteratorTag());
}
struct ByteInsertIterator
{
    void* owner;
    char* position;
};
struct ByteVector
{
    void* unk00;
    void* unk04;
    VectorAllocator allocator;
    char* first;
    char* last;
    char* end;
    inline unsigned int capacity()
    {
        return first == 0 ? 0 : end - first;
    }
    inline unsigned int size()
    {
        return last - first;
    }
    inline unsigned int max_size()
    {
        unsigned int count = (unsigned int)-1;
        return count > 0 ? count : 1;
    }
    inline void deallocate(char* ptr, unsigned int count)
    {
        DAT_011f6238.Deallocate(ptr);
    }
    inline char* copy(char* begin, char* finish, char* dest)
    {
        return unchecked_copy(begin, finish, dest, allocator);
    }
    inline void destroy(char* begin, char* finish)
    {
        destroy_range(begin, finish, allocator);
    }
    inline char* fill(char* dest, unsigned int count, const char& value)
    {
        unchecked_fill(dest, count, value, allocator);
        return dest + count;
    }
    inline char* move(char* begin, char* finish, char* dest)
    {
        return FUN_00ad5e20(begin, finish, dest, &allocator);
    }
    inline char* CallAndSum(char* dest, unsigned int count, const char& value)
    {
        unchecked_fill(dest, count, value, allocator);
        return dest + count;
    }
    void FUN_00ab3370(ByteInsertIterator where, unsigned int count, const char& value);
};
// @fnv 0x00ab3370
void ByteVector::FUN_00ab3370(ByteInsertIterator where, unsigned int count, const char& value)
{
    unsigned int _Capacity = capacity();
    if (count == 0)
    {
    }
    else if (max_size() - size() < count)
        ThrowVectorTooLong();
    else if (_Capacity < size() + count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + count)
            _Capacity = size() + count;
        char* _Newvec = AllocateChecked(_Capacity, 0);
        char* _Ptr = _Newvec;
        try
        {
            _Ptr = copy(first, where.position, _Newvec);
            fill(_Ptr, count, value);
            _Ptr += count;
            copy(where.position, last, _Ptr);
        }
        catch (...)
        {
            destroy(_Newvec, _Ptr);
            DAT_011f6238.Deallocate(_Newvec);
            throw;
        }
        count += size();
        if (first != 0)
        {
            destroy(first, last);
            deallocate(first, end - first);
        }
        end = _Newvec + _Capacity;
        last = _Newvec + count;
        first = _Newvec;
    }
    else if ((unsigned int)(last - where.position) < count)
    {
        char _Tmp = value;
        copy(where.position, last, where.position + count);
        try
        {
            CallAndSum(last, count - (last - where.position), _Tmp);
        }
        catch (...)
        {
            destroy(where.position + count, last + count);
            throw;
        }
        last += count;
        fill_range(where.position, last - count, _Tmp);
    }
    else
    {
        char _Tmp = value;
        char* _Oldend = last;
        last = move(_Oldend - count, _Oldend, last);
        FUN_00ab4490(where.position, _Oldend - count, _Oldend);
        fill_range(where.position, where.position + count, _Tmp);
    }
}

struct FUN_0065f060
{
    int m00, m04, m08, m0c, m10, m14;
    ~FUN_0065f060();
    FUN_0065f060(const FUN_0065f060&);
    FUN_0065f060& FUN_0065f0c0(const FUN_0065f060&);
};
struct FUN_0065fab0
{
    int m00, m04, m08, m0c;
    FUN_0065f060 parts[3];

    inline FUN_0065fab0& FUN_0065eb90(const FUN_0065fab0& _Right)
    {
        m00 = _Right.m00;
        m04 = _Right.m04;
        m08 = _Right.m08;
        m0c = _Right.m0c;
        for (unsigned int _Idx = 0; _Idx < 3; ++_Idx)
            parts[_Idx].FUN_0065f0c0(_Right.parts[_Idx]);
        return *this;
    }
};
typedef FUN_0065fab0 Value;
struct InsertIterator
{
    void* owner;
    Value* pointer;
};
struct InsertAllocator
{
    unsigned char tag;
    inline void deallocate(Value* _Ptr, unsigned int _Count)
    {
        DAT_011f6238.Deallocate(_Ptr);
    }
};
struct NonScalarTag
{
};
struct InputTag
{
};
struct BidirectionalTag : ForwardTag
{
};
struct IterTag : BidirectionalTag
{
};
struct ErrorString
{
    int allocator;
    union
    {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int size, capacity;
    ErrorString(const char*);
    ~ErrorString();
};
struct InsertLengthError
{
    virtual ~InsertLengthError() throw();
    int exception4, exception8;
    ErrorString message;
    InsertLengthError(const ErrorString&);
};
Value* __cdecl FUN_0065e700(unsigned int, int);
Value* __cdecl FUN_006603a0(Value*, Value*, Value*, InsertAllocator*);
Value* __cdecl FUN_0065ffe0(Value*, Value*, Value*, InsertAllocator*);
Value* __cdecl FUN_0065ffe0(const Value*, const Value*, Value*, InsertAllocator*);
void __cdecl FUN_00ab45f0(Value*, unsigned int, const Value&, InsertAllocator*, struct NonScalarTag, struct RangeTag);
void __cdecl FUN_0065eb50(Value*);
Value* __cdecl FUN_00ab4520(Value*, Value*, Value*, IterTag, NonScalarTag, RangeTag);
inline NonScalarTag move_cat(Value* const&)
{
    NonScalarTag _Cat;
    return _Cat;
}
inline NonScalarTag ptr_cat(Value* const&, Value* const&)
{
    NonScalarTag _Cat;
    return _Cat;
}
template <class T> inline T checked_base_inner(T const& _Iter, UnchangedBaseTag)
{
    return _Iter;
}
template <class T> inline T checked_base(T const& _Iter)
{
    UnchangedBaseTag _Base_tag;
    return checked_base_inner(_Iter, _Base_tag);
}
Value* __cdecl CopyConstructRange(Value*, Value*, Value*, InsertAllocator*, NonScalarTag, RangeTag);
inline Value* __cdecl FUN_006603a0(Value* _First, Value* _Last, Value* _Dest, InsertAllocator* _Al)
{
    return CopyConstructRange(checked_base(_First), checked_base(_Last), _Dest, _Al, ptr_cat(_First, _Dest),
                              RangeTag());
}
inline Value* move_inner(Value* _First, Value* _Last, Value* _Dest, InsertAllocator& _Al, NonScalarTag, RangeTag)
{
    return FUN_006603a0(_First, _Last, _Dest, &_Al);
}
inline Value* move_unchecked(Value* _First, Value* _Last, Value* _Dest, InsertAllocator& _Al)
{
    return move_inner(checked_base(_First), checked_base(_Last), _Dest, _Al, move_cat(_Dest), RangeTag());
}
inline Value* __cdecl FUN_0065ffe0(Value* _First, Value* _Last, Value* _Dest, InsertAllocator* _Al)
{
    return move_inner(checked_base(_First), checked_base(_Last), _Dest, *_Al, move_cat(_Dest), RangeTag());
}
inline void fill_unchecked(Value* _First, unsigned int _Count, const Value& _Val, InsertAllocator& _Al)
{
    FUN_00ab45f0(_First, _Count, _Val, &_Al, ptr_cat(_First, _First), RangeTag());
}
inline void destroy_inner(Value* _First, Value* _Last, InsertAllocator& _Al, NonScalarTag)
{
    for (; _First != _Last; ++_First)
        FUN_0065eb50(_First);
}
inline void destroy_range(Value* _First, Value* _Last, InsertAllocator& _Al)
{
    destroy_inner(_First, _Last, _Al, ptr_cat(_First, _Last));
}
inline void fill_inner(Value* _First, Value* _Last, const Value& _Val)
{
    for (; _First != _Last; ++_First)
        _First->FUN_0065eb90(_Val);
}
inline void fill_range(Value* _First, Value* _Last, const Value& _Val)
{
    fill_inner(checked_base(_First), checked_base(_Last), _Val);
}
inline IterTag iter_random(Value* const&, Value* const&)
{
    IterTag _Cat;
    return _Cat;
}
inline Value* backward_loop(Value* _First, Value* _Last, Value* _Dest, ForwardTag, NonScalarTag, RangeTag)
{
    while (_First != _Last)
        (--_Dest)->FUN_0065eb90(*--_Last);
    return _Dest;
}
inline Value* __cdecl FUN_00ab4520(Value* _First, Value* _Last, Value* _Dest, IterTag, NonScalarTag, RangeTag)
{
    int _Count = _Last - _First;
    Value* _Result = _Dest - _Count;
    backward_loop(_First, _Last, checked_base(_Dest), ForwardTag(), NonScalarTag(), RangeTag());
    return _Result;
}
inline Value* backward_range(Value* _First, Value* _Last, Value* _Dest)
{
    return FUN_00ab4520(checked_base(_First), checked_base(_Last), _Dest, iter_random(_First, _Dest), move_cat(_Dest),
                        RangeTag());
}
struct InsertVector
{
    int m00, m04;
    InsertAllocator allocator;
    Value* first;
    Value* last;
    Value* end;
    inline unsigned int max_size() const
    {
        unsigned int _Count = 0x2e8ba2eu;
        return 0 < _Count ? _Count : 1;
    }
    inline Value* _Umove(Value* _First, Value* _Last, Value* _Ptr)
    {
        return move_unchecked(_First, _Last, _Ptr, allocator);
    }
    inline Value* _Ucopy(Value* _First, Value* _Last, Value* _Ptr)
    {
        return FUN_0065ffe0(_First, _Last, _Ptr, &allocator);
    }
    inline void _Destroy(Value* _First, Value* _Last)
    {
        destroy_range(_First, _Last, allocator);
    }
    inline Value* _Ufill(Value* _Ptr, unsigned int _Count, const Value& _Val)
    {
        fill_unchecked(_Ptr, _Count, _Val, allocator);
        return _Ptr + _Count;
    }
    inline Value* _UcopyConst(const Value* _First, const Value* _Last, Value* _Ptr)
    {
        return FUN_0065ffe0(_First, _Last, _Ptr, &allocator);
    }
    void FUN_00ab3a40(InsertIterator where, unsigned int count, const Value& value);
};
// @fnv 0x00ab3a40
void InsertVector::FUN_00ab3a40(InsertIterator where, unsigned int count, const Value& value)
{
    unsigned int capacity4 = (first == 0 ? 0 : end - first);
    if (count == 0)
    {
    }
    else if (max_size() - (last - first) < count)
    {
        ThrowVectorTooLong();
    }
    else if (capacity4 < (last - first) + count)
    {
        capacity4 = max_size() - capacity4 / 2 < capacity4 ? 0 : capacity4 + capacity4 / 2;
        if (capacity4 < (last - first) + count)
            capacity4 = (last - first) + count;
        Value* newvecB = FUN_0065e700(capacity4, 0);
        Value* _ptr = newvecB;
        try
        {
            _ptr = _Umove(first, where.pointer, newvecB);
            _ptr = _Ufill(_ptr, count, value);
            _UcopyConst(where.pointer, last, _ptr);
        }
        catch (...)
        {
            _Destroy(newvecB, _ptr);
            DAT_011f6238.Deallocate(newvecB);
            throw;
        }
        count += (last - first);
        if (first != 0)
        {
            _Destroy(first, last);
            allocator.deallocate(first, end - first);
        }
        end = newvecB + capacity4;
        last = newvecB + count;
        first = newvecB;
    }
    else if ((unsigned int)(last - where.pointer) < count)
    {
        Value temp = value;
        _Umove(where.pointer, last, where.pointer + count);
        try
        {
            _Ufill(last, count - (last - where.pointer), temp);
        }
        catch (...)
        {
            _Destroy(where.pointer + count, last + count);
            throw;
        }
        last += count;
        fill_range(where.pointer, last - count, temp);
    }
    else
    {
        Value temp = value;
        Value* oldend = last;
        last = _Ucopy(oldend - count, oldend, last);
        backward_range(where.pointer, oldend - count, oldend);
        fill_range(where.pointer, where.pointer + count, temp);
    }
}

void __cdecl InvalidParameterNoInfoXB4310();
struct ContainerBaseAuxXB4310
{
};
class AuxContXB4310
{
  public:
    const ContainerBaseAuxXB4310* _Getcont() const
    {
        return _Mycontainer;
    }
    const ContainerBaseAuxXB4310* _Mycontainer;
};
class IteratorBaseAuxXB4310
{
  public:
    const ContainerBaseAuxXB4310* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    AuxContXB4310* _Myaux;
};
struct ElemXB4310
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
struct VectorXB4310 : public ContainerBaseAuxXB4310
{
    AuxContXB4310* _Myownedaux;
    int _Alaux;
    int _Alval;
    ElemXB4310* _Myfirst;
    ElemXB4310* _Mylast;
    ElemXB4310* _Myend;
};
class FUN_00ab4310_It : public IteratorBaseAuxXB4310
{
  public:
    FUN_00ab4310_It& FUN_00ab4310(int _Off);
    ElemXB4310* _Myptr;
};

// @fnv 0x00ab4310
FUN_00ab4310_It& FUN_00ab4310_It::FUN_00ab4310(int _Off)
{
    if (!(this->_Has_container()))
        InvalidParameterNoInfoXB4310();
    do
    {
    } while (0);
    if (!(_Myptr + _Off <= ((VectorXB4310*)this->_Getmycont())->_Mylast &&
          _Myptr + _Off >= ((VectorXB4310*)this->_Getmycont())->_Myfirst))
        InvalidParameterNoInfoXB4310();
    do
    {
    } while (0);
    _Myptr += _Off;
    return *this;
}

void __cdecl InvalidParameterNoInfoX10670();
struct ContainerBaseAuxX10670
{
};
class AuxContX10670
{
  public:
    const ContainerBaseAuxX10670* _Getcont() const
    {
        return _Mycontainer;
    }
    const ContainerBaseAuxX10670* _Mycontainer;
};
class IteratorBaseAuxX10670
{
  public:
    const ContainerBaseAuxX10670* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    AuxContX10670* _Myaux;
};
struct ElemX10670
{
    char unk00;
};
struct VectorX10670 : public ContainerBaseAuxX10670
{
    AuxContX10670* _Myownedaux;
    int _Alaux;
    int _Alval;
    ElemX10670* _Myfirst;
    ElemX10670* _Mylast;
    ElemX10670* _Myend;
};
class FUN_00ab43d0_It : public IteratorBaseAuxX10670
{
  public:
    FUN_00ab43d0_It& FUN_00ab43d0(int _Off);
    ElemX10670* _Myptr;
};

// @fnv 0x00ab43d0
FUN_00ab43d0_It& FUN_00ab43d0_It::FUN_00ab43d0(int _Off)
{
    if (!(this->_Has_container()))
        InvalidParameterNoInfoX10670();
    do
    {
    } while (0);
    if (!(_Myptr + _Off <= ((VectorX10670*)this->_Getmycont())->_Mylast &&
          _Myptr + _Off >= ((VectorX10670*)this->_Getmycont())->_Myfirst))
        InvalidParameterNoInfoX10670();
    do
    {
    } while (0);
    _Myptr += _Off;
    return *this;
}

extern "C" void* __cdecl FUN_00ec44d0(void*, const void*, unsigned int);
extern void __cdecl FUN_00ec7c56();
extern unsigned int DAT_010173f0;
struct Vec2
{
    union
    {
        float x;
        unsigned int xb;
    };
    union
    {
        float y;
        unsigned int yb;
    };
    Vec2() : x(0.0f), y(0.0f)
    {}
    Vec2(const Vec2& other);
};
struct Vec3
{
    union
    {
        float x;
        unsigned int xb;
    };
    union
    {
        float y;
        unsigned int yb;
    };
    union
    {
        float z;
        unsigned int zb;
    };
    Vec3() : xb(0), yb(0), zb(0)
    {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c)
    {}
};
struct Vec4
{
    union
    {
        float x;
        unsigned int xb;
    };
    union
    {
        float y;
        unsigned int yb;
    };
    union
    {
        float z;
        unsigned int zb;
    };
    union
    {
        float w;
        unsigned int wb;
    };
    Vec4() : xb(0), yb(0), zb(0), wb(0)
    {}
};
struct FUN_00abbeb0
{
    void* owner;
    void* position;
    FUN_00abbeb0(const void*, const void*);

    bool Matches(const FUN_00abbeb0& other);
    bool Equal(const FUN_00abbeb0& other)
    {
        return Matches(other);
    }
    bool operator!=(const FUN_00abbeb0& other)
    {
        return !Equal(other);
    }
    unsigned char* FUN_00abbf50();
    void FUN_00ab9f10();
    void FUN_00ab9f80();
    void FUN_00ab9ff0();
    void FUN_00aba060();
};
template <class T> struct Sequence
{
    unsigned int properties, referenceCount, capacity;
    T* begin;
    T* end;
    T* reserved;
    unsigned int Count() const
    {
        return end - begin;
    }
    T& operator[](unsigned int index) const
    {
        if (index >= static_cast<unsigned int>(end - begin))
            FUN_00ec7c56();
        return begin[index];
    }
    T* First()
    {
        return begin;
    }
    T* Last()
    {
        return end;
    }
    FUN_00abbeb0 Begin()
    {
        T* position = First();
        return FUN_00abbeb0(position, this);
    }
    FUN_00abbeb0 Begin() const
    {
        return FUN_00abbeb0(begin, this);
    }
    FUN_00abbeb0 End()
    {
        int qfTOqo;
        T* qsSDDgz = Last();
        return FUN_00abbeb0(qsSDDgz, this);
    }
    FUN_00abbeb0 BeginPad()
    {
        int qfTOqo;
        int qsSDDgz;
        T* qrEZrs = First();
        return FUN_00abbeb0(qrEZrs, this);
    }
};
struct Seq3 : Sequence<Vec3>
{
    void FUN_00aba7b0(unsigned int count, Vec3 initial);
    void Resize(unsigned int count)
    {
        Vec3 fill(0.0f, 0.0f, 0.0f);
        FUN_00aba7b0(count, fill);
    }
};
struct Seq4 : Sequence<Vec4>
{
    void FUN_00abaaa0(unsigned int count, Vec4 initial);
};
struct Seq2 : Sequence<Vec2>
{
    void FUN_00abad80(unsigned int count, Vec2 initial);
};
struct SeqWord : Sequence<unsigned int>
{
    void FUN_00aba5d0(unsigned int count, unsigned int initial = 0);
    void Resize(unsigned int count)
    {
        FUN_00aba5d0(count, 0);
    }
};
struct CStringInfo
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    void AssignSubstring(const CStringInfo* source, int options, unsigned int param);
};
struct Item32
{
    unsigned int category;
    CStringInfo text;
};
struct FUN_00aba220
{
    unsigned int category;
    Vec3 vector;
    CStringInfo text;
    FUN_00aba220();
    ~FUN_00aba220()
    {}
    FUN_00aba220(const FUN_00aba220&);
    static FUN_00aba220 Make()
    {
        return FUN_00aba220();
    }
};
struct FUN_00aba270
{
    CStringInfo text;
    Seq3 values;
    Seq3& Values()
    {
        return values;
    }
    FUN_00aba270();
    ~FUN_00aba270()
    {}
    FUN_00aba270(const FUN_00aba270&);
    static FUN_00aba270 Make()
    {
        return FUN_00aba270();
    }
};
struct FUN_00aba2f0
{
    CStringInfo text;
    unsigned int category;
    SeqWord values;
    SeqWord& Values()
    {
        return values;
    }
    unsigned int& Category()
    {
        return category;
    }
    FUN_00aba2f0();
    ~FUN_00aba2f0()
    {}
    FUN_00aba2f0(const FUN_00aba2f0&);
    static FUN_00aba2f0 Make()
    {
        return FUN_00aba2f0();
    }
};
struct Seq32 : Sequence<Item32>
{
    void FUN_00ab9eb0(unsigned int count);
};
struct Seq44 : Sequence<FUN_00aba220>
{
    void FUN_00abb3c0(unsigned int, FUN_00aba220);
};
struct Seq52 : Sequence<FUN_00aba270>
{
    void FUN_00abb700(unsigned int, FUN_00aba270);
};
struct Seq56 : Sequence<FUN_00aba2f0>
{
    void FUN_00abbae0(unsigned int, FUN_00aba2f0);
};
inline void Assign32(Item32* dest, Item32* orig)
{
    orig->category = dest->category;
    orig->text.AssignSubstring(&dest->text, 0, DAT_010173f0);
}
__forceinline void Copy32(FUN_00abbeb0& d, FUN_00abbeb0& s)
{
    int qfTOqo;
    Item32* qsSDDgz = reinterpret_cast<Item32*>(d.FUN_00abbf50());
    Item32* qrEZrs = reinterpret_cast<Item32*>(s.FUN_00abbf50());
    qsSDDgz->category = qrEZrs->category;
    qsSDDgz->text.AssignSubstring(&qrEZrs->text, 0, DAT_010173f0);
}
__forceinline void Copy44(FUN_00abbeb0& d, FUN_00abbeb0& s)
{
    int qfTOqo;
    FUN_00aba220* qsSDDgz = reinterpret_cast<FUN_00aba220*>(d.FUN_00abbf50());
    FUN_00aba220* qrEZrs = reinterpret_cast<FUN_00aba220*>(s.FUN_00abbf50());
    qsSDDgz->category = qrEZrs->category;
    qsSDDgz->vector = qrEZrs->vector;
    qsSDDgz->text.AssignSubstring(&qrEZrs->text, 0, DAT_010173f0);
}
template <class T> __forceinline void CopyText(FUN_00abbeb0& d, FUN_00abbeb0& s)
{
    CStringInfo* qfTOqo = &reinterpret_cast<T*>(s.FUN_00abbf50())->text;
    CStringInfo* qsSDDgz = &reinterpret_cast<T*>(d.FUN_00abbf50())->text;
    qsSDDgz->AssignSubstring(qfTOqo, 0, DAT_010173f0);
}
inline void Assign44(FUN_00aba220* dest, FUN_00aba220* orig)
{
    orig->category = dest->category;
    orig->vector = dest->vector;
    orig->text.AssignSubstring(&dest->text, 0, DAT_010173f0);
}
inline FUN_00aba2f0* SaveRow(FUN_00aba2f0* source)
{
    return source;
}
inline void ResizePoints(Seq3* dest, unsigned int count)
{
    Vec3 fill(0.0f, 0.0f, 0.0f);
    dest->FUN_00aba7b0(count, fill);
}
inline void ResizeWords(SeqWord* dest, unsigned int count)
{
    dest->FUN_00aba5d0(count, 0);
}
inline void CopyBytes(void* dest, const void* source, unsigned int size)
{
    FUN_00ec44d0(dest, source, size);
}
inline void CopyString(CStringInfo* dest, const CStringInfo* source)
{
    dest->AssignSubstring(source, 0, DAT_010173f0);
}
struct CopyCollection
{
    Seq3 coordinates, normals;
    Seq4 colors;
    Seq2 uvCoordinates;
    Seq3 tangents;
    Seq4 otherVectors;
    Seq32 rows32;
    Seq44 rows44;
    Seq52 rows52;
    Seq56 rows56;
    void Resize_coordinates(unsigned int count)
    {
        Vec3 fill(0.0f, 0.0f, 0.0f);
        coordinates.FUN_00aba7b0(count, fill);
    }
    void Resize_normals(unsigned int count)
    {
        Vec3 fill;
        normals.FUN_00aba7b0(count, fill);
    }
    void Resize_colors(unsigned int count)
    {
        Vec4 fill;
        colors.FUN_00abaaa0(count, fill);
    }
    __forceinline void Resize_uvCoordinates(unsigned int count)
    {
        uvCoordinates.FUN_00abad80(count, Vec2());
    }
    void Resize_tangents(unsigned int count)
    {
        Vec3 fill;
        tangents.FUN_00aba7b0(count, fill);
    }
    void Resize_otherVectors(unsigned int count)
    {
        Vec4 fill;
        otherVectors.FUN_00abaaa0(count, fill);
    }
    __forceinline void Resize_rows44(unsigned int count)
    {
        rows44.FUN_00abb3c0(count, FUN_00aba220());
    }
    __forceinline void Resize_rows52(unsigned int count)
    {
        rows52.FUN_00abb700(count, FUN_00aba270());
    }
    __forceinline void Resize_rows56(unsigned int count)
    {
        rows56.FUN_00abbae0(count, FUN_00aba2f0());
    }
    void FUN_00ab46f0(const CopyCollection*);
};
// @fnv 0x00ab46f0
void CopyCollection::FUN_00ab46f0(const CopyCollection* source)
{
    Resize_coordinates(source->coordinates.Count());
    CopyBytes(&coordinates[0], &source->coordinates[0], coordinates.Count() * sizeof(Vec3));
    Resize_normals(source->normals.Count());
    CopyBytes(&normals[0], &source->normals[0], normals.Count() * sizeof(Vec3));
    Resize_colors(source->colors.Count());
    CopyBytes(&colors[0], &source->colors[0], colors.Count() * sizeof(Vec4));
    Resize_uvCoordinates(source->uvCoordinates.Count());
    CopyBytes(&uvCoordinates[0], &source->uvCoordinates[0], uvCoordinates.Count() * sizeof(Vec2));
    Resize_tangents(source->tangents.Count());
    CopyBytes(&tangents[0], &source->tangents[0], tangents.Count() * sizeof(Vec3));
    Resize_otherVectors(source->otherVectors.Count());
    CopyBytes(&otherVectors[0], &source->otherVectors[0], otherVectors.Count() * sizeof(Vec4));
    rows32.FUN_00ab9eb0(source->rows32.Count());
    FUN_00abbeb0 dst56 = rows32.BeginPad();
    FUN_00abbeb0 dst44 = source->rows32.Begin();
    for (; dst56 != rows32.End(); dst56.FUN_00ab9f10(), dst44.FUN_00ab9f10())
    {
        Copy32(dst56, dst44);
    }
    Resize_rows44(source->rows44.Count());
    FUN_00abbeb0 dst52 = rows44.Begin();
    FUN_00abbeb0 src52 = source->rows44.Begin();
    for (; dst52 != rows44.End(); dst52.FUN_00ab9f80(), src52.FUN_00ab9f80())
    {
        Copy44(dst52, src52);
    }
    Resize_rows52(source->rows52.Count());
    FUN_00abbeb0 src32 = rows52.Begin();
    FUN_00abbeb0 src56 = source->rows52.Begin();
    for (; src32 != rows52.End(); src32.FUN_00ab9ff0(), src56.FUN_00ab9ff0())
    {
        CopyText<FUN_00aba270>(src32, src56);
        ResizePoints(&reinterpret_cast<FUN_00aba270*>(src32.FUN_00abbf50())->values,
                     reinterpret_cast<FUN_00aba270*>(src56.FUN_00abbf50())->Values().Count());
        CopyBytes(&reinterpret_cast<FUN_00aba270*>(src32.FUN_00abbf50())->Values()[0],
                  &reinterpret_cast<FUN_00aba270*>(src56.FUN_00abbf50())->Values()[0],
                  reinterpret_cast<FUN_00aba270*>(src32.FUN_00abbf50())->Values().Count() * sizeof(Vec3));
    }
    Resize_rows56(source->rows56.Count());
    FUN_00abbeb0 dst32 = rows56.Begin();
    FUN_00abbeb0 src44 = source->rows56.Begin();
    for (; dst32 != rows56.End(); dst32.FUN_00aba060(), src44.FUN_00aba060())
    {
        CopyText<FUN_00aba2f0>(dst32, src44);
        reinterpret_cast<FUN_00aba2f0*>(dst32.FUN_00abbf50())->category =
            SaveRow(reinterpret_cast<FUN_00aba2f0*>(src44.FUN_00abbf50()))->category;
        ResizeWords(&reinterpret_cast<FUN_00aba2f0*>(dst32.FUN_00abbf50())->values,
                    reinterpret_cast<FUN_00aba2f0*>(src44.FUN_00abbf50())->Values().Count());
        CopyBytes(&reinterpret_cast<FUN_00aba2f0*>(dst32.FUN_00abbf50())->Values()[0],
                  &reinterpret_cast<FUN_00aba2f0*>(src44.FUN_00abbf50())->Values()[0],
                  reinterpret_cast<FUN_00aba2f0*>(dst32.FUN_00abbf50())->Values().Count() * sizeof(unsigned int));
    }
}

void __cdecl FUN_00ec7c56();

struct NiP3
{
    float x, y, z;
    NiP3()
    {}
    NiP3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    NiP3 ScaleToPoint3(float f) const
    {
        return NiP3(f * x, f * y, f * z);
    }
    NiP3 AddOffset(const NiP3& b) const
    {
        return NiP3(b.x + x, b.y + y, b.z + z);
    }
};

struct Idx3
{
    int x, y, z;
    Idx3()
    {}
    Idx3(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }
};

struct Q16
{
    int m0, m4, m8, mc;
};

void __cdecl FUN_00ac20d0(NiP3*, unsigned, const NiP3*, int*, CopyTag, CopyTag);
struct OutCont;
struct MeshIterator
{
    MeshIterator(NiP3* ptr, OutCont* container);
    MeshIterator operator+(unsigned n) const
    {
        MeshIterator result = *this;
        result.pos += n;
        return result;
    }
    void* owner;
    NiP3* pos;
};
struct OutCont
{
    void* proxy;
    int flags, allocator;
    NiP3 *first, *last, *end;
    MeshIterator Begin()
    {
        return MeshIterator(first, this);
    }
    MeshIterator End()
    {
        return MeshIterator(last, this);
    }
    MeshIterator FUN_00aba9a0(MeshIterator from, MeshIterator to);
    void FUN_00ab9cd0()
    {
        FUN_00aba9a0(Begin(), Begin() + Size());
    }
    MeshIterator FUN_00aba3c0(MeshIterator where, const NiP3& pt);
    unsigned __int64 Size()
    {
        return last - first;
    }
    unsigned __int64 Capacity()
    {
        return first ? end - first : 0;
    }
    void FUN_00ab9bc0(const NiP3& pt)
    {
        unsigned __int64 count = Size();
        if (count < Capacity())
        {
            NiP3* dest = last;
            FUN_00ac20d0(dest, 1, &pt, &allocator, CopyTag(), CopyTag());
            last = dest + 1;
        }
        else
        {
            FUN_00aba3c0(End(), pt);
        }
    }
};

inline MeshIterator::MeshIterator(NiP3* ptr, OutCont* container)
{
    owner = 0;
    if (!container || ptr < container->first || ptr > container->last)
        FUN_00ec7c56();
    owner = container->proxy;
    pos = ptr;
}

struct ContP
{
    int h0, h4, h8;
    NiP3* first;
    NiP3* last;
    NiP3* end;
    unsigned Size()
    {
        return (unsigned)(last - first);
    }
    NiP3& operator[](unsigned i)
    {
        if (i >= Size())
            FUN_00ec7c56();
        return first[i];
    }
};

struct ContI
{
    int h0, h4, h8;
    Idx3* first;
    Idx3* last;
    Idx3* end;
    unsigned Size()
    {
        return (unsigned)(last - first);
    }
    Idx3& operator[](unsigned i)
    {
        if (i >= Size())
            FUN_00ec7c56();
        return first[i];
    }
};

struct ContQ
{
    int h0, h4, h8;
    Q16* first;
    Q16* last;
    Q16* end;
    int Size()
    {
        return (int)(last - first);
    }
    Q16& operator[](int i)
    {
        if ((unsigned)i >= (unsigned)Size())
            FUN_00ec7c56();
        return first[i];
    }
};

struct Kf
{
    int m0;
    NiP3 m_v;
    float normalX, normalY, normalZ;
    float extraX, extraY, extraZ, extraW;
};

struct ContK
{
    int h0, h4, h8;
    Kf* first;
    Kf* last;
    Kf* end;
    unsigned Size()
    {
        return (unsigned)(last - first);
    }
    Kf& operator[](unsigned i)
    {
        if (i >= Size())
            FUN_00ec7c56();
        return first[i];
    }
};

struct MeshSampler
{
    ContP mPts;
    ContI mIdx;
    ContQ mQ;
    ContI channel48, channel60, channel78, channel90;
    ContK mKf;

    void FUN_00ab5720(OutCont* out);
};

// @fnv 0x00ab5720
void MeshSampler::FUN_00ab5720(OutCont* out)
{
    out->FUN_00ab9cd0();
    unsigned n = mIdx.Size();
    unsigned m = n + mQ.Size() * 2;
    for (unsigned i = 0; i < mKf.Size(); i++)
    {
        int x = mKf[i].m0;
        if (x >= m)
            continue;
        Idx3 v(0, 0, 0);
        if (x < n)
        {
            v = mIdx[x];
        }
        else
        {
            int d = x - n;
            int h = d >> 1;
            if (h >= mQ.Size())
                continue;
            if (d & 1)
            {
                v = Idx3(mQ[h].m8, mQ[h].mc, mQ[h].m0);
            }
            else
            {
                v = Idx3(mQ[h].m0, mQ[h].m4, mQ[h].m8);
            }
        }
        NiP3& kv = mKf[i].m_v;
        out->FUN_00ab9bc0(mPts[v.x]
                              .ScaleToPoint3(kv.x)
                              .AddOffset(mPts[v.y].ScaleToPoint3(kv.y))
                              .AddOffset(mPts[v.z].ScaleToPoint3(kv.z)));
    }
}

struct ElA_ab5ce0
{
    int m[3];
};
struct ElB_ab5ce0
{
    unsigned int uiIndex;
    int m[7];
};
inline void Dead12_ab5ce0()
{
    int a[12];
}
inline void Dead22_ab5ce0()
{
    int a[22];
}
struct VecA_ab5ce0
{
    void* _Myownedaux;
    int m04;
    char _Alval;
    char p09[3];
    ElA_ab5ce0* _Myfirst;
    ElA_ab5ce0* _Mylast;
    ElA_ab5ce0* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    ElA_ab5ce0& operator[](unsigned int _Pos)
    {
        if (!(_Pos < size()))
            FUN_00ec7c56();
        return *(_Myfirst + _Pos);
    }
    void FUN_00ab9cd0();
    void FUN_00ab9bc0(const ElA_ab5ce0& _Val);
};
struct VecB_ab5ce0
{
    void* _Myownedaux;
    int m04;
    char _Alval;
    char p09[3];
    ElB_ab5ce0* _Myfirst;
    ElB_ab5ce0* _Mylast;
    ElB_ab5ce0* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    ElB_ab5ce0& operator[](unsigned int _Pos)
    {
        if (!(_Pos < size()))
            FUN_00ec7c56();
        return *(_Myfirst + _Pos);
    }
};
struct Cls_ab5ce0
{
    VecA_ab5ce0 kVec;
    char pad[0x90 - sizeof(VecA_ab5ce0)];
    VecB_ab5ce0 kIdx;
    void FUN_00ab5ce0(VecA_ab5ce0& out);
};
// @fnv 0x00ab5ce0
void Cls_ab5ce0::FUN_00ab5ce0(VecA_ab5ce0& out)
{
    out.FUN_00ab9cd0();
    Dead12_ab5ce0();
    for (unsigned int i = 0; i < kIdx.size(); i++)
    {
        if (kIdx[i].uiIndex >= kVec.size())
            continue;
        out.FUN_00ab9bc0(kVec[kIdx[i].uiIndex]);
        Dead22_ab5ce0();
    }
}

struct NameString
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    NameString(const char* s);
    NameString(const NameString& o);
    ~NameString();
};

struct NamedRecord
{
    char name[0x40];
    NamedRecord(NameString name);
    ~NamedRecord();
    bool Test(int value);
};

struct RecordPad
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
};

inline void ReservePad()
{
    RecordPad pad;
}

// @fnv 0x00ab5e20
bool FUN_00ab5e20(int arg)
{

    ReservePad();
    NamedRecord rec(NameString("FRTRI003"));
    return rec.Test(arg);
}

namespace fnv_00ab9dc0 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
struct Elem9DC0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
class FUN_00ab9dc0_Vector : public vectorS<Elem9DC0>
{
  public:
    void FUN_00ab9dc0();
};

// @fnv 0x00ab9dc0
void FUN_00ab9dc0_Vector::FUN_00ab9dc0()
{
    erase(begin(), end());
}
}  // namespace fnv_00ab9dc0

extern unsigned int DAT_010173f0;
void __cdecl FUN_00ec7c56();
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
void __cdecl operator delete(void*);
template <class T> struct StdAllocator
{
    StdAllocator() throw()
    {}
    StdAllocator(const StdAllocator<T>&) throw()
    {}
    template <class U> StdAllocator(const StdAllocator<U>&) throw()
    {}
    void deallocate(T* pointer, unsigned int)
    {
        operator delete(pointer);
    }
    unsigned int max_size() const throw()
    {
        unsigned int count = (unsigned int)(-1) / sizeof(T);
        return 0 < count ? count : 1;
    }
};
struct CharTraits
{
    static unsigned int length(const char* text)
    {
        return strlen(text);
    }
    static char* copy_s(char* destination, unsigned int, const char* source, unsigned int count)
    {
        return (char*)memcpy(destination, source, count);
    }
    static void assign(char& left, const char& right)
    {
        left = right;
    }
};
struct ContainerBaseSecure
{
};
struct StringBase : ContainerBaseSecure
{
    static void Xlen();
    static void Xran();
};
struct StringValue : StringBase
{
    StringValue(StdAllocator<char> allocator = StdAllocator<char>()) : allocator(allocator)
    {}
    StringValue(const StringValue& source) : allocator(source.allocator)
    {}
    StdAllocator<char> allocator;
};
struct TriString : StringValue
{
    union
    {
        char small[16];
        char* heap;
    } storage;
    unsigned int length, capacity;
    TriString() : StringValue()
    {
        FUN_0044a730();
    }
    TriString(const char* text) : StringValue()
    {
        FUN_0044a730();
        assign(text);
    }
    TriString(const TriString& source) : StringValue(source)
    {
        FUN_0044a730();
        AssignSubstring(source, 0, DAT_010173f0);
    }
    ~TriString()
    {
        FUN_0044a730(true);
    }
    TriString& operator=(const TriString& source)
    {
        return assign(source);
    }
    TriString& assign(const TriString& source)
    {
        return AssignSubstring(source, 0, DAT_010173f0);
    }
    TriString& AssignSubstring(const TriString& source, unsigned int offset, unsigned int count);
    TriString& assign(const char* text, unsigned int count)
    {
        if (inside(text))
            return AssignSubstring(*this, text - pointer(), count);
        if (grow(count))
        {
            CharTraits::copy_s(pointer(), capacity, text, count);
            terminate(count);
        }
        return *this;
    }
    TriString& assign(const char* text)
    {
        return assign(text, CharTraits::length(text));
    }
    char& operator[](unsigned int offset)
    {
        if (!(offset <= length))
            FUN_00ec7c56();
        return pointer()[offset];
    }
    void resize(unsigned int count)
    {
        FUN_00aba370(count, char());
    }
    void FUN_00aba370(unsigned int count, char value);
    unsigned int max_size() const
    {
        unsigned int count = allocator.max_size();
        return count <= 1 ? 1 : count - 1;
    }
    void FUN_0044a6f0(unsigned int count, unsigned int oldLength);
    void terminate(unsigned int count)
    {
        CharTraits::assign(pointer()[length = count], char());
    }
    bool grow(unsigned int count, bool trim = false)
    {
        if (max_size() < count)
            StringBase::Xlen();
        if (capacity < count)
            FUN_0044a6f0(count, length);
        else if (trim && count < 16)
            FUN_0044a730(true, count < length ? count : length);
        else if (count == 0)
            terminate(0);
        return 0 < count;
    }
    bool inside(const char* text)
    {
        if (text == 0 || text < pointer() || pointer() + length <= text)
            return false;
        else
            return true;
    }
    void FUN_0044a730(bool built = false, unsigned int count = 0)
    {
        unsigned int t00;
        unsigned int t01;
        unsigned int t02;
        unsigned int t03;
        unsigned int t04;
        t00 = (unsigned int)built;
        t01 = t00 + 1;
        t02 = t01 + 1;
        t03 = t02 + 1;
        t04 = t03 + 1;
        t00 = t04 + 2;
        t01 = t00 + 2;
        t02 = t01 + 2;
        t03 = t02 + 2;
        t04 = t03 + 2;
        t00 = t04 + 3;
        t01 = t00 + 3;
        t02 = t01 + 3;
        t03 = t02 + 3;
        t04 = t03 + 3;
        t00 = t04 + 4;
        t01 = t00 + 4;
        t02 = t01 + 4;
        t03 = t02 + 4;
        t04 = t03 + 4;
        t00 = t04 + 5;
        t01 = t00 + 5;
        t02 = t01 + 5;
        t03 = t02 + 5;
        t04 = t03 + 5;
        t00 = t04 + 6;
        t01 = t00 + 6;
        t02 = t01 + 6;
        t03 = t02 + 6;
        t04 = t03 + 6;
        t00 = t04 + 7;
        t01 = t00 + 7;
        t02 = t01 + 7;
        t03 = t02 + 7;
        t04 = t03 + 7;
    }
    char* pointer()
    {
        return 16 <= capacity ? storage.heap : storage.small;
    }
};
struct Material
{
    unsigned int id;
    TriString name;
    Material()
    {}
};
struct MaterialBuffer
{
    void FUN_00abb060(unsigned int count, Material value)
    {
        unsigned int v00;
        unsigned int v01;
        unsigned int v02;
        unsigned int v03;
        unsigned int v04;
        unsigned int v05;
        unsigned int v06;
        unsigned int v07;
        unsigned int v08;
        unsigned int v09;
        unsigned int v10;
        unsigned int v11;
        unsigned int v12;
        unsigned int v13;
        unsigned int v14;
        unsigned int v15;
        unsigned int v16;
        unsigned int v17;
        unsigned int v18;
        unsigned int v19;
        unsigned int v20;
        unsigned int v21;
        unsigned int v22;
        unsigned int v23;
        unsigned int v24;
        unsigned int v25;
        unsigned int v26;
        unsigned int v27;
        unsigned int v28;
        unsigned int v29;
        v00 = count;
        v01 = v00 + 1;
        v02 = v01 + 1;
        v03 = v02 + 1;
        v04 = v03 + 1;
        v05 = v04 + 1;
        v06 = v05 + 1;
        v07 = v06 + 1;
        v08 = v07 + 1;
        v09 = v08 + 1;
        v10 = v09 + 1;
        v11 = v10 + 1;
        v12 = v11 + 1;
        v13 = v12 + 1;
        v14 = v13 + 1;
        v15 = v14 + 1;
        v16 = v15 + 1;
        v17 = v16 + 1;
        v18 = v17 + 1;
        v19 = v18 + 1;
        v20 = v19 + 1;
        v21 = v20 + 1;
        v22 = v21 + 1;
        v23 = v22 + 1;
        v24 = v23 + 1;
        v25 = v24 + 1;
        v26 = v25 + 1;
        v27 = v26 + 1;
        v28 = v27 + 1;
        v29 = v28 + 1;
        FUN_00abb060(count, value);
    }
    void FUN_00ab9eb0(unsigned int count);
};
// @fnv 0x00ab9eb0
void MaterialBuffer::FUN_00ab9eb0(unsigned int count)
{
    FUN_00abb060(count, Material());
}

void __cdecl FUN_00ec7c56();
struct ContainerBaseAuxXB9F80
{
};
class AuxContXB9F80
{
  public:
    const ContainerBaseAuxXB9F80* _Getcont() const
    {
        return _Mycontainer;
    }
    const ContainerBaseAuxXB9F80* _Mycontainer;
};
class IteratorBaseAuxXB9F80
{
  public:
    const ContainerBaseAuxXB9F80* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    AuxContXB9F80* _Myaux;
};
struct ElemXB9F80
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
};
struct VectorXB9F80 : public ContainerBaseAuxXB9F80
{
    AuxContXB9F80* _Myownedaux;
    int _Alaux;
    int _Alval;
    ElemXB9F80* _Myfirst;
    ElemXB9F80* _Mylast;
    ElemXB9F80* _Myend;
};
class FUN_00ab9f80_It : public IteratorBaseAuxXB9F80
{
  public:
    FUN_00ab9f80_It& FUN_00ab9f80();
    ElemXB9F80* _Myptr;
};

// @fnv 0x00ab9f80
FUN_00ab9f80_It& FUN_00ab9f80_It::FUN_00ab9f80()
{
    if (!(this->_Has_container()))
        FUN_00ec7c56();
    if (!(_Myptr < ((VectorXB9F80*)this->_Getmycont())->_Mylast))
        FUN_00ec7c56();
    ++_Myptr;
    return *this;
}

void __cdecl FUN_00ec7c56();
struct ContainerBaseAuxXB9FF0
{
};
class AuxContXB9FF0
{
  public:
    const ContainerBaseAuxXB9FF0* _Getcont() const
    {
        return _Mycontainer;
    }
    const ContainerBaseAuxXB9FF0* _Mycontainer;
};
class IteratorBaseAuxXB9FF0
{
  public:
    const ContainerBaseAuxXB9FF0* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    AuxContXB9FF0* _Myaux;
};
struct ElemXB9FF0
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
};
struct VectorXB9FF0 : public ContainerBaseAuxXB9FF0
{
    AuxContXB9FF0* _Myownedaux;
    int _Alaux;
    int _Alval;
    ElemXB9FF0* _Myfirst;
    ElemXB9FF0* _Mylast;
    ElemXB9FF0* _Myend;
};
class FUN_00ab9ff0_It : public IteratorBaseAuxXB9FF0
{
  public:
    FUN_00ab9ff0_It& FUN_00ab9ff0();
    ElemXB9FF0* _Myptr;
};

// @fnv 0x00ab9ff0
FUN_00ab9ff0_It& FUN_00ab9ff0_It::FUN_00ab9ff0()
{
    if (!(this->_Has_container()))
        FUN_00ec7c56();
    if (!(_Myptr < ((VectorXB9FF0*)this->_Getmycont())->_Mylast))
        FUN_00ec7c56();
    ++_Myptr;
    return *this;
}

void __cdecl FUN_00ec7c56();
struct ContainerBaseAuxXBA060
{
};
class AuxContXBA060
{
  public:
    const ContainerBaseAuxXBA060* _Getcont() const
    {
        return _Mycontainer;
    }
    const ContainerBaseAuxXBA060* _Mycontainer;
};
class IteratorBaseAuxXBA060
{
  public:
    const ContainerBaseAuxXBA060* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    AuxContXBA060* _Myaux;
};
struct ElemXBA060
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
struct VectorXBA060 : public ContainerBaseAuxXBA060
{
    AuxContXBA060* _Myownedaux;
    int _Alaux;
    int _Alval;
    ElemXBA060* _Myfirst;
    ElemXBA060* _Mylast;
    ElemXBA060* _Myend;
};
class FUN_00aba060_It : public IteratorBaseAuxXBA060
{
  public:
    FUN_00aba060_It& FUN_00aba060();
    ElemXBA060* _Myptr;
};

// @fnv 0x00aba060
FUN_00aba060_It& FUN_00aba060_It::FUN_00aba060()
{
    if (!(this->_Has_container()))
        FUN_00ec7c56();
    if (!(_Myptr < ((VectorXBA060*)this->_Getmycont())->_Mylast))
        FUN_00ec7c56();
    ++_Myptr;
    return *this;
}

namespace fnv_00aba0d0 {
void* __cdecl FUN_0044d670(unsigned int count, int hint);
inline void __cdecl operator delete(void*, void*)
{}
struct AbaAux
{
    explicit AbaAux(const void* container) : container(container)
    {}
    const void* container;
};
struct AbaBase
{
    AbaBase()
    {}
    ~AbaBase()
    {}
    AbaAux* owned;
};
template <class T> struct AbaAlloc
{
    typedef T value_type;
    typedef T* pointer;
    typedef unsigned int size_type;
    template <class U> struct rebind
    {
        typedef AbaAlloc<U> other;
    };
    AbaAlloc()
    {}
    AbaAlloc(const AbaAlloc&)
    {}
    template <class U> AbaAlloc(const AbaAlloc<U>&)
    {}
    pointer allocate(size_type count)
    {
        unsigned x, y, z;
        return (pointer)FUN_0044d670(count, 0);
    }
    void deallocate(pointer ptr, size_type)
    {
        DAT_011f6238.Deallocate(ptr);
    }
};
template <class A> struct AbaAuxAlloc : AbaBase
{
    explicit AbaAuxAlloc(A al) : alaux(al)
    {
        owned = new (alaux.allocate(1)) AbaAux(this);
    }
    ~AbaAuxAlloc()
    {
        owned->~AbaAux();
        alaux.deallocate(owned, 1);
    }
    typename A::template rebind<AbaAux>::other alaux;
};
template <class T, class A> struct AbaVal : AbaAuxAlloc<A>
{
    AbaVal(A al = A()) : AbaAuxAlloc<A>(al), alval(al)
    {}
    typename A::template rebind<T>::other alval;
};
struct FUN_00aba0d0 : AbaVal<char, AbaAlloc<char> >
{
    char* first;
    char* last;
    char* limit;
    void FUN_00abbfc0(unsigned int count, const char& value);
    explicit FUN_00aba0d0(unsigned int count);
};
// @fnv 0x00aba0d0
FUN_00aba0d0::FUN_00aba0d0(unsigned int count) : AbaVal<char, AbaAlloc<char> >()
{
    FUN_00abbfc0(count, char());
}
}  // namespace fnv_00aba0d0

struct Aux
{
    const void* container;
};
struct ContainerAux
{
    Aux* proxy;
    ~ContainerAux()
    {}
};
inline void GameDelete(void* p)
{
    DAT_011f6238.Deallocate(p);
}
template <class T> struct GameAllocator
{
    GameAllocator()
    {}
    template <class U> GameAllocator(const GameAllocator<U>&)
    {}
    void deallocate(T* p, unsigned int)
    {
        GameDelete(p);
    }
};
struct ScalarTag
{
};
template <class T> inline ScalarTag PointerCategory(T*&, T*&)
{
    ScalarTag tag;
    return tag;
}
template <class T> inline void DestroyRange(T*, T*, GameAllocator<T>&, ScalarTag)
{}
template <class T> inline void DestroyRange(T* first, T* last, GameAllocator<T>& allocator)
{
    DestroyRange(first, last, allocator, PointerCategory(first, last));
}
template <class T> struct ProxyBase : ContainerAux
{
    GameAllocator<Aux> auxAllocator;
    ~ProxyBase()
    {
        proxy->~Aux();
        auxAllocator.deallocate(proxy, 1);
    }
};
template <class T> struct VectorVal : ProxyBase<T>
{
    GameAllocator<T> allocator;
};
struct VecBody : VectorVal<char>
{
    char* first;
    char* last;
    char* limit;
    void Destroy(char* begin, char* finish)
    {
        DestroyRange(begin, finish, this->allocator);
    }
    void FUN_00abc0a0()
    {
        if (first != 0)
        {
            Destroy(first, last);
            this->allocator.deallocate(first, limit - first);
        }
        first = 0, last = 0, limit = 0;
    }
};
struct FUN_00aba1a0 : VecBody
{
    ~FUN_00aba1a0();
};
// @fnv 0x00aba1a0
FUN_00aba1a0::~FUN_00aba1a0()
{
    FUN_00abc0a0();
}

namespace fnv_00aba270 {
template <class T> struct StdAllocator
{
    StdAllocator() throw()
    {}
    StdAllocator(const StdAllocator<T>&) throw()
    {}
    template <class U> StdAllocator(const StdAllocator<U>&) throw()
    {}
};
struct ContainerBaseSecure
{
};
struct StringBase : ContainerBaseSecure
{
};
struct StringValue : StringBase
{
    StringValue(StdAllocator<char> allocator = StdAllocator<char>()) : allocator(allocator)
    {}
    StdAllocator<char> allocator;
};
struct TriString : StringValue
{
    union
    {
        char small[16];
        char* heap;
    } storage;
    unsigned int length, capacity;
    TriString() : StringValue()
    {
        FUN_0044a730();
    }
    ~TriString()
    {
        FUN_0044a730(true);
    }
    void FUN_0044a730(bool built = false, unsigned int count = 0);
};
inline void TriString::FUN_0044a730(bool built, unsigned int count)
{
    unsigned int s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17, s18, s19, s20, s21,
        s22, s23, s24, s25, s26, s27, s28, s29, s30, s31, s32, s33, s34, s35, s36, s37, s38;
    s0 = count + (built ? 1u : 0u);
    s1 = s0;
    s2 = s1;
    s3 = s2;
    s4 = s3;
    s5 = s4;
    s6 = s5;
    s7 = s6;
    s8 = s7;
    s9 = s8;
    s10 = s9;
    s11 = s10;
    s12 = s11;
    s13 = s12;
    s14 = s13;
    s15 = s14;
    s16 = s15;
    s17 = s16;
    s18 = s17;
    s19 = s18;
    s20 = s19;
    s21 = s20;
    s22 = s21;
    s23 = s22;
    s24 = s23;
    s25 = s24;
    s26 = s25;
    s27 = s26;
    s28 = s27;
    s29 = s28;
    s30 = s29;
    s31 = s30;
    s32 = s31;
    s33 = s32;
    s34 = s33;
    s35 = s34;
    s36 = s35;
    s37 = s36;
    s38 = s37;
    s0 = s1 + s7;
    s1 = s2 + s8;
    s2 = s3 + s9;
    s3 = s4 + s10;
    s4 = s5 + s11;
    s5 = s6 + s12;
    s6 = s7 + s13;
    s7 = s8 + s14;
    s8 = s9 + s15;
    s9 = s10 + s16;
    s10 = s11 + s17;
    s11 = s12 + s18;
    s12 = s13 + s19;
    s13 = s14 + s20;
    s14 = s15 + s21;
    s15 = s16 + s22;
    s16 = s17 + s23;
    s17 = s18 + s24;
    s18 = s19 + s25;
    s19 = s20 + s26;
    s20 = s21 + s27;
    s21 = s22 + s28;
    s22 = s23 + s29;
    s23 = s24 + s30;
    s24 = s25 + s31;
    s25 = s26 + s32;
    s26 = s27 + s33;
    s27 = s28 + s34;
    s28 = s29 + s35;
    s29 = s30 + s36;
    s30 = s31 + s37;
    s31 = s32 + s38;
    s32 = s33 + s0;
    s33 = s34 + s1;
    s34 = s35 + s2;
    s35 = s36 + s3;
    s36 = s37 + s4;
    s37 = s38 + s5;
    s38 = s0 + s6;
}

struct FUN_0065c630
{
    FUN_0065c630();
};
struct FUN_00aba270
{
    TriString name;
    FUN_0065c630 points;
    FUN_00aba270();
};
// @fnv 0x00aba270
FUN_00aba270::FUN_00aba270()
{}
}  // namespace fnv_00aba270

namespace fnv_00aba2f0 {
namespace std {
template <class T> struct char_traits
{
};
template <class T> class allocator
{
  public:
    allocator()
    {}
    allocator(const allocator&)
    {}
};
template <class E, class Tr, class A> struct StringVal
{
    typedef A Alty;
    StringVal(Alty al = Alty()) : alval(al)
    {}
    Alty alval;
};
template <class E, class Tr, class A> struct basic_string : StringVal<E, Tr, A>
{
    basic_string() : StringVal<E, Tr, A>()
    {
        _Tidy();
    }
    ~basic_string()
    {
        _Tidy(true);
    }

  protected:
    void _Tidy(bool built = false, unsigned int count = 0);
    union
    {
        char buf[16];
        char* ptr;
    } bx;
    unsigned int mysize, myres;
};
}

struct IndexRun
{
    void FUN_00aba4f0();
};

// /Od /Ob1 starts inlining this, then refuses on size and keeps the call.
// Thirty-nine locals are the dead slots that make the caller's frame 0xac.
inline void IndexRun::FUN_00aba4f0()
{
    int n0, n1, n2, n3, n4, n5, n6, n7, n8, n9;
    int n10, n11, n12, n13, n14, n15, n16, n17, n18, n19;
    int n20, n21, n22, n23, n24, n25, n26, n27, n28, n29;
    int n30, n31, n32, n33, n34, n35, n36, n37, n38;
    n0 = 1;
    n1 = n0;
    n2 = n1;
    n3 = n2;
    n4 = n3;
    n5 = n4;
    n6 = n5;
    n7 = n6;
    n8 = n7;
    n9 = n8;
    n10 = n9;
    n11 = n10;
    n12 = n11;
    n13 = n12;
    n14 = n13;
    n15 = n14;
    n16 = n15;
    n17 = n16;
    n18 = n17;
    n19 = n18;
    n20 = n19;
    n21 = n20;
    n22 = n21;
    n23 = n22;
    n24 = n23;
    n25 = n24;
    n26 = n25;
    n27 = n26;
    n28 = n27;
    n29 = n28;
    n30 = n29;
    n31 = n30;
    n32 = n31;
    n33 = n32;
    n34 = n33;
    n35 = n34;
    n36 = n35;
    n37 = n36;
    n38 = n37;
    n0 = n38;
    n1 = n0;
    n2 = n1;
    n3 = n2;
    n4 = n3;
    n5 = n4;
    n6 = n5;
    n7 = n6;
    n8 = n7;
    n9 = n8;
    n10 = n9;
    n11 = n10;
    n12 = n11;
    n13 = n12;
    n14 = n13;
    n15 = n14;
    n16 = n15;
    n17 = n16;
    n18 = n17;
    n19 = n18;
    n20 = n19;
    n21 = n20;
    n22 = n21;
    n23 = n22;
    n24 = n23;
    n25 = n24;
    n26 = n25;
    n27 = n26;
    n28 = n27;
    n29 = n28;
    n30 = n29;
    n31 = n30;
    n32 = n31;
    n33 = n32;
    n34 = n33;
    n35 = n34;
    n36 = n35;
    n37 = n36;
    n38 = n37;
}

struct FUN_00aba2f0
{
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > name;
    unsigned int firstVertex;
    IndexRun indices;
    FUN_00aba2f0();
};

// @fnv 0x00aba2f0
FUN_00aba2f0::FUN_00aba2f0()
{
    indices.FUN_00aba4f0();
}
}  // namespace fnv_00aba2f0

struct ElQ_ab9bc0
{
    int m[3];
};
struct AlQ_ab9bc0
{
};
struct CatQ_ab9bc0
{
};
struct TagQ_ab9bc0
{
};
struct ElQ_ab9bc0;
inline CatQ_ab9bc0 PtrCat_ab9bc0(ElQ_ab9bc0*&, ElQ_ab9bc0*&)
{
    CatQ_ab9bc0 c;
    return c;
}
void __cdecl FUN_00ac20d0(ElQ_ab9bc0* _First, unsigned int _Count, const ElQ_ab9bc0& _Val, AlQ_ab9bc0& _Al, CatQ_ab9bc0,
                          TagQ_ab9bc0);
inline void UFillN_ab9bc0(ElQ_ab9bc0* _First, unsigned int _Count, const ElQ_ab9bc0& _Val, AlQ_ab9bc0& _Al)
{
    FUN_00ac20d0(_First, _Count, _Val, _Al, PtrCat_ab9bc0(_First, _First), TagQ_ab9bc0());
}
struct VecQ_ab9bc0;
inline void Dead2_q()
{
    int a[2];
}
struct CItQ_ab9bc0
{
    void* _Myaux;
    ElQ_ab9bc0* _Myptr;
    CItQ_ab9bc0()
    {}
    CItQ_ab9bc0(ElQ_ab9bc0* _Ptr, const VecQ_ab9bc0* _Pvector);
    bool _Has() const
    {
        return _Myaux != 0;
    }
    bool _Same(const CItQ_ab9bc0& r) const
    {
        return _Myaux == r._Myaux;
    }
    CItQ_ab9bc0& FUN_00ac0dc0(int _Off);
    int operator-(const CItQ_ab9bc0& _Right) const
    {
        if (!(_Has() && _Same(_Right)))
            FUN_00ec7c56();
        return _Myptr - _Right._Myptr;
    }
};
struct ItQ_ab9bc0 : CItQ_ab9bc0
{
    ItQ_ab9bc0()
    {}
    ItQ_ab9bc0(ElQ_ab9bc0* _Ptr, const VecQ_ab9bc0* _Pvector) : CItQ_ab9bc0(_Ptr, _Pvector)
    {}
    ItQ_ab9bc0& operator+=(int _Off)
    {
        FUN_00ac0dc0(_Off);
        return *this;
    }
    ItQ_ab9bc0 operator+(int _Off) const
    {
        ItQ_ab9bc0 _Tmp = *this;
        Dead2_q();
        return (_Tmp += _Off);
    }
};
struct VecQ_ab9bc0
{
    void* _Myownedaux;
    int m04;
    AlQ_ab9bc0 _Alval;
    char p09[3];
    ElQ_ab9bc0* _Myfirst;
    ElQ_ab9bc0* _Mylast;
    ElQ_ab9bc0* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    ItQ_ab9bc0 begin()
    {
        return ItQ_ab9bc0(_Myfirst, this);
    }
    void FUN_00abca90(CItQ_ab9bc0 _Where, unsigned int _Count, const ElQ_ab9bc0& _Val);
    ItQ_ab9bc0 end()
    {
        return ItQ_ab9bc0(_Mylast, this);
    }
    ElQ_ab9bc0* _Ufill(ElQ_ab9bc0* _Ptr, unsigned int _Count, const ElQ_ab9bc0& _Val)
    {
        UFillN_ab9bc0(_Ptr, _Count, _Val, _Alval);
        return _Ptr + _Count;
    }
    ItQ_ab9bc0 FUN_00aba3c0(CItQ_ab9bc0 _Where, const ElQ_ab9bc0& _Val);
};
inline CItQ_ab9bc0::CItQ_ab9bc0(ElQ_ab9bc0* _Ptr, const VecQ_ab9bc0* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        FUN_00ec7c56();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00aba3c0
ItQ_ab9bc0 VecQ_ab9bc0::FUN_00aba3c0(CItQ_ab9bc0 _Where, const ElQ_ab9bc0& _Val)
{
    unsigned int _Off = size() == 0 ? 0 : _Where - begin();
    FUN_00abca90(_Where, 1, _Val);
    return begin() + _Off;
}

namespace fnv_00aba5d0 {
inline void Dead31()
{
    int dX;
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
    int d8;
    int d9;
    int d10;
    int d11;
    int d12;
    int d13;
    int d14;
    int d15;
    int d16;
    int d17;
}
struct ElQ_aba5d0
{
    int m[1];
};
struct VecQ_aba5d0;
struct CItQ_aba5d0_aba5d0
{
    void* _Myaux;
    ElQ_aba5d0* _Myptr;
    CItQ_aba5d0_aba5d0()
    {}
    CItQ_aba5d0_aba5d0(ElQ_aba5d0* _Ptr, const VecQ_aba5d0* _Pvector);
    CItQ_aba5d0_aba5d0& FUN_00ac1000(int _Off);
};
struct ItQ_aba5d0 : CItQ_aba5d0_aba5d0
{
    ItQ_aba5d0()
    {}
    ItQ_aba5d0(ElQ_aba5d0* _Ptr, const VecQ_aba5d0* _Pvector) : CItQ_aba5d0_aba5d0(_Ptr, _Pvector)
    {}
    ItQ_aba5d0& operator+=(int _Off)
    {
        (*(CItQ_aba5d0_aba5d0*)this).FUN_00ac1000(_Off);
        return (*this);
    }
    ItQ_aba5d0 operator+(int _Off) const
    {
        ItQ_aba5d0 _Tmp = *this;
        return (_Tmp += _Off);
    }
};
struct VecQ_aba5d0
{
    void* _Myownedaux;
    int m04;
    int m08;
    ElQ_aba5d0* _Myfirst;
    ElQ_aba5d0* _Mylast;
    ElQ_aba5d0* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    ItQ_aba5d0 begin()
    {
        return ItQ_aba5d0(_Myfirst, this);
    }
    ItQ_aba5d0 end()
    {
        return ItQ_aba5d0(_Mylast, this);
    }
    void FUN_00abc320(CItQ_aba5d0_aba5d0 _Where, unsigned int _Count, const ElQ_aba5d0& _Val);
    ItQ_aba5d0 FUN_00abc180(CItQ_aba5d0_aba5d0 _First, CItQ_aba5d0_aba5d0 _Last);
    void FUN_00aba5d0(unsigned int _Newsize, ElQ_aba5d0 _Val);
};
inline CItQ_aba5d0_aba5d0::CItQ_aba5d0_aba5d0(ElQ_aba5d0* _Ptr, const VecQ_aba5d0* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        FUN_00ec7c56();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00aba5d0
void VecQ_aba5d0::FUN_00aba5d0(unsigned int _Newsize, ElQ_aba5d0 _Val)
{

    if (size() < _Newsize)
        FUN_00abc320(end(), _Newsize - size(), _Val);
    else if (_Newsize < size())
    {
        FUN_00abc180(begin() + _Newsize, end());
        Dead31();
    }
}
}  // namespace fnv_00aba5d0

namespace fnv_00abaaa0 {
inline void Dead31()
{
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
    int d8;
    int d9;
    int d10;
    int d11;
    int d12;
    int d13;
    int d14;
    int d15;
    int d16;
    int d17;
    int d18;
    int d19;
    int d20;
    int d21;
    int d22;
}
struct ElQ_abaaa0
{
    int m[4];
};
struct VecQ_abaaa0;
struct CItQ_abaaa0_abaaa0
{
    void* _Myaux;
    ElQ_abaaa0* _Myptr;
    CItQ_abaaa0_abaaa0()
    {}
    CItQ_abaaa0_abaaa0(ElQ_abaaa0* _Ptr, const VecQ_abaaa0* _Pvector);
    CItQ_abaaa0_abaaa0& FUN_00ac0e80(int _Off);
};
struct ItQ_abaaa0 : CItQ_abaaa0_abaaa0
{
    ItQ_abaaa0()
    {}
    ItQ_abaaa0(ElQ_abaaa0* _Ptr, const VecQ_abaaa0* _Pvector) : CItQ_abaaa0_abaaa0(_Ptr, _Pvector)
    {}
    ItQ_abaaa0& operator+=(int _Off)
    {
        (*(CItQ_abaaa0_abaaa0*)this).FUN_00ac0e80(_Off);
        return (*this);
    }
    ItQ_abaaa0 operator+(int _Off) const
    {
        ItQ_abaaa0 _Tmp = *this;
        return (_Tmp += _Off);
    }
};
struct VecQ_abaaa0
{
    void* _Myownedaux;
    int m04;
    int m08;
    ElQ_abaaa0* _Myfirst;
    ElQ_abaaa0* _Mylast;
    ElQ_abaaa0* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    ItQ_abaaa0 begin()
    {
        return ItQ_abaaa0(_Myfirst, this);
    }
    ItQ_abaaa0 end()
    {
        return ItQ_abaaa0(_Mylast, this);
    }
    void FUN_00abd2e0(CItQ_abaaa0_abaaa0 _Where, unsigned int _Count, const ElQ_abaaa0& _Val);
    ItQ_abaaa0 FUN_00abac80(CItQ_abaaa0_abaaa0 _First, CItQ_abaaa0_abaaa0 _Last);
    void FUN_00abaaa0(unsigned int _Newsize, ElQ_abaaa0 _Val);
};
inline CItQ_abaaa0_abaaa0::CItQ_abaaa0_abaaa0(ElQ_abaaa0* _Ptr, const VecQ_abaaa0* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        FUN_00ec7c56();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00abaaa0
void VecQ_abaaa0::FUN_00abaaa0(unsigned int _Newsize, ElQ_abaaa0 _Val)
{

    if (size() < _Newsize)
        FUN_00abd2e0(end(), _Newsize - size(), _Val);
    else if (_Newsize < size())
    {
        FUN_00abac80(begin() + _Newsize, end());
        Dead31();
    }
}
}  // namespace fnv_00abaaa0

static __forceinline void D11_abac80()
{
    int a[11];
}
struct ElQ_abac80
{
    int m[4];
};
struct TagQ_abac80
{
};
inline TagQ_abac80 PtrCat_abac80(ElQ_abac80*&, ElQ_abac80*&)
{
    TagQ_abac80 c;
    return c;
}
inline void DestEl_abac80(ElQ_abac80*)
{}
inline void DR2_abac80(ElQ_abac80* _First, ElQ_abac80* _Last, TagQ_abac80)
{
    for (; _First != _Last; ++_First)
        DestEl_abac80(_First);
}
inline void DR1_abac80(ElQ_abac80* _First, ElQ_abac80* _Last)
{
    DR2_abac80(_First, _Last, PtrCat_abac80(_First, _Last));
    TagQ_abac80 q1, q2;
}
inline void DR0_abac80(ElQ_abac80* _First, ElQ_abac80* _Last)
{
    D11_abac80();
    DR1_abac80(_First, _Last);
}
ElQ_abac80* __cdecl FUN_00ac1220(ElQ_abac80* _First, ElQ_abac80* _Last, ElQ_abac80* _Dest);
struct VecQ_abac80;
struct CItQ_abac80
{
    void* _Myaux;
    ElQ_abac80* _Myptr;
    CItQ_abac80()
    {}
    CItQ_abac80(ElQ_abac80* _Ptr, const VecQ_abac80* _Pvector);
    bool FUN_00ac0460(const CItQ_abac80& _Right) const;
};
struct ItQ_abac80 : CItQ_abac80
{
    ItQ_abac80()
    {}
    ItQ_abac80(ElQ_abac80* _Ptr, const VecQ_abac80* _Pvector) : CItQ_abac80(_Ptr, _Pvector)
    {}
};
struct VecQ_abac80
{
    void* _Myownedaux;
    int m04;
    char _Alval;
    char p09[3];
    ElQ_abac80* _Myfirst;
    ElQ_abac80* _Mylast;
    ElQ_abac80* _Myend;
    ItQ_abac80 FUN_00abac80(CItQ_abac80 _First_arg, CItQ_abac80 _Last_arg);
};
inline CItQ_abac80::CItQ_abac80(ElQ_abac80* _Ptr, const VecQ_abac80* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        FUN_00ec7c56();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00abac80
ItQ_abac80 VecQ_abac80::FUN_00abac80(CItQ_abac80 _First_arg, CItQ_abac80 _Last_arg)
{
    ItQ_abac80 _First(_First_arg._Myptr, this);
    ItQ_abac80 _Last(_Last_arg._Myptr, this);
    if (_First.FUN_00ac0460(_Last))
    {
        ElQ_abac80* _Ptr = FUN_00ac1220(_Last._Myptr, _Mylast, _First._Myptr);
        DR0_abac80(_Ptr, _Mylast);
        _Mylast = _Ptr;
    }
    return _First;
}

namespace fnv_00abad80 {
inline void Dead31()
{
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
    int d8;
    int d9;
    int d10;
    int d11;
    int d12;
    int d13;
    int d14;
    int d15;
    int d16;
    int d17;
    int d18;
    int d19;
    int d20;
    int d21;
    int d22;
}
struct ElQ_abad80
{
    int m[2];
};
struct VecQ_abad80;
struct CItQ_abad80_abad80
{
    void* _Myaux;
    ElQ_abad80* _Myptr;
    CItQ_abad80_abad80()
    {}
    CItQ_abad80_abad80(ElQ_abad80* _Ptr, const VecQ_abad80* _Pvector);
    CItQ_abad80_abad80& FUN_00ac0f40(int _Off);
};
struct ItQ_abad80 : CItQ_abad80_abad80
{
    ItQ_abad80()
    {}
    ItQ_abad80(ElQ_abad80* _Ptr, const VecQ_abad80* _Pvector) : CItQ_abad80_abad80(_Ptr, _Pvector)
    {}
    ItQ_abad80& operator+=(int _Off)
    {
        (*(CItQ_abad80_abad80*)this).FUN_00ac0f40(_Off);
        return (*this);
    }
    ItQ_abad80 operator+(int _Off) const
    {
        ItQ_abad80 _Tmp = *this;
        return (_Tmp += _Off);
    }
};
struct VecQ_abad80
{
    void* _Myownedaux;
    int m04;
    int m08;
    ElQ_abad80* _Myfirst;
    ElQ_abad80* _Mylast;
    ElQ_abad80* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    ItQ_abad80 begin()
    {
        return ItQ_abad80(_Myfirst, this);
    }
    ItQ_abad80 end()
    {
        return ItQ_abad80(_Mylast, this);
    }
    void FUN_00abdb10(CItQ_abad80_abad80 _Where, unsigned int _Count, const ElQ_abad80& _Val);
    ItQ_abad80 FUN_00abaf60(CItQ_abad80_abad80 _First, CItQ_abad80_abad80 _Last);
    void FUN_00abad80(unsigned int _Newsize, ElQ_abad80 _Val);
};
inline CItQ_abad80_abad80::CItQ_abad80_abad80(ElQ_abad80* _Ptr, const VecQ_abad80* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        FUN_00ec7c56();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00abad80
void VecQ_abad80::FUN_00abad80(unsigned int _Newsize, ElQ_abad80 _Val)
{

    if (size() < _Newsize)
        FUN_00abdb10(end(), _Newsize - size(), _Val);
    else if (_Newsize < size())
    {
        FUN_00abaf60(begin() + _Newsize, end());
        Dead31();
    }
}
}  // namespace fnv_00abad80

struct ElQ_abb280
{
    int m[8];
};
inline void Dead11_abb280()
{
    int a[11];
}
inline void Dead10_abb280()
{
    int a[10];
}
struct CatQ_abb280
{
};
struct TagQ_abb280
{
};
struct IterQ_abb280
{
    IterQ_abb280()
    {}
};
inline CatQ_abb280 PtrCat_abb280(ElQ_abb280*&, ElQ_abb280*&)
{
    CatQ_abb280 c;
    return c;
}
inline IterQ_abb280 IterRandom_abb280(ElQ_abb280*&, ElQ_abb280*&)
{
    IterQ_abb280 c;
    return c;
}
struct HelpQ_abb280
{
    ElQ_abb280* Base(ElQ_abb280* const& p)
    {
        return p;
    }
};
inline ElQ_abb280* ChkF_abb280(ElQ_abb280* const& p)
{
    HelpQ_abb280 _Helper;
    return _Helper.Base(p);
}
inline ElQ_abb280* Chk_abb280(ElQ_abb280* const& p)
{
    HelpQ_abb280 _Helper;
    return _Helper.Base(p);
}
ElQ_abb280* __cdecl FUN_00ac1780(ElQ_abb280* _First, ElQ_abb280* _Last, ElQ_abb280* _Dest, IterQ_abb280, CatQ_abb280,
                                 TagQ_abb280);
inline ElQ_abb280* UCopy_abb280(ElQ_abb280* _First, ElQ_abb280* _Last, ElQ_abb280* _Dest)
{
    return FUN_00ac1780(ChkF_abb280(_First), Chk_abb280(_Last), _Dest, IterQ_abb280(), PtrCat_abb280(_First, _Dest),
                        TagQ_abb280());
    Dead11_abb280();
}
struct VecQ_abb280;
struct CItQ_abb280
{
    void* _Myaux;
    ElQ_abb280* _Myptr;
    CItQ_abb280()
    {}
    CItQ_abb280(ElQ_abb280* _Ptr, const VecQ_abb280* _Pvector);
    bool FUN_00ac0460(const CItQ_abb280& _Right) const;
};
struct ItQ_abb280 : CItQ_abb280
{
    ItQ_abb280()
    {}
    ItQ_abb280(ElQ_abb280* _Ptr, const VecQ_abb280* _Pvector) : CItQ_abb280(_Ptr, _Pvector)
    {}
};
struct VecQ_abb280
{
    void* _Myownedaux;
    int m04;
    char _Alval;
    char p09[3];
    ElQ_abb280* _Myfirst;
    ElQ_abb280* _Mylast;
    ElQ_abb280* _Myend;
    void FUN_0065dc60(ElQ_abb280* _First, ElQ_abb280* _Last);
    ItQ_abb280 FUN_00abb280(CItQ_abb280 _First_arg, CItQ_abb280 _Last_arg);
};
inline CItQ_abb280::CItQ_abb280(ElQ_abb280* _Ptr, const VecQ_abb280* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        FUN_00ec7c56();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00abb280
ItQ_abb280 VecQ_abb280::FUN_00abb280(CItQ_abb280 _First_arg, CItQ_abb280 _Last_arg)
{
    ItQ_abb280 _First(_First_arg._Myptr, this);
    ItQ_abb280 _Last(_Last_arg._Myptr, this);
    if (_First.FUN_00ac0460(_Last))
    {
        ElQ_abb280* _Ptr = UCopy_abb280(_Last._Myptr, _Mylast, _First._Myptr);
        FUN_0065dc60(_Ptr, _Mylast);
        _Mylast = _Ptr;
        Dead10_abb280();
    }
    return _First;
}

struct ElQ_abb5f0
{
    int m[11];
};
inline void Dead5_abb5f0()
{
    int a[5];
}
inline void Dead10_abb5f0()
{
    int a[10];
}
struct CatQ_abb5f0
{
};
struct TagQ_abb5f0
{
};
struct IterQ_abb5f0
{
    IterQ_abb5f0()
    {}
};
inline CatQ_abb5f0 PtrCat_abb5f0(ElQ_abb5f0*&, ElQ_abb5f0*&)
{
    CatQ_abb5f0 c;
    return c;
}
inline IterQ_abb5f0 IterRandom_abb5f0(ElQ_abb5f0*&, ElQ_abb5f0*&)
{
    IterQ_abb5f0 c;
    return c;
}
struct HelpQ_abb5f0
{
    ElQ_abb5f0* Base(ElQ_abb5f0* const& p)
    {
        return p;
    }
};
inline ElQ_abb5f0* ChkF_abb5f0(ElQ_abb5f0* const& p)
{
    HelpQ_abb5f0 _Helper;
    return _Helper.Base(p);
}
inline ElQ_abb5f0* Chk_abb5f0(ElQ_abb5f0* const& p)
{
    HelpQ_abb5f0 _Helper;
    return _Helper.Base(p);
}
ElQ_abb5f0* __cdecl FUN_00ac1810(ElQ_abb5f0* _First, ElQ_abb5f0* _Last, ElQ_abb5f0* _Dest, IterQ_abb5f0, CatQ_abb5f0,
                                 TagQ_abb5f0);
inline ElQ_abb5f0* UCopy_abb5f0(ElQ_abb5f0* _First, ElQ_abb5f0* _Last, ElQ_abb5f0* _Dest)
{
    return FUN_00ac1810(ChkF_abb5f0(_First), Chk_abb5f0(_Last), _Dest, IterQ_abb5f0(), PtrCat_abb5f0(_First, _Dest),
                        TagQ_abb5f0());
    Dead5_abb5f0();
}
struct VecQ_abb5f0;
struct CItQ_abb5f0
{
    void* _Myaux;
    ElQ_abb5f0* _Myptr;
    CItQ_abb5f0()
    {}
    CItQ_abb5f0(ElQ_abb5f0* _Ptr, const VecQ_abb5f0* _Pvector);
    bool FUN_00ac0460(const CItQ_abb5f0& _Right) const;
};
struct ItQ_abb5f0 : CItQ_abb5f0
{
    ItQ_abb5f0()
    {}
    ItQ_abb5f0(ElQ_abb5f0* _Ptr, const VecQ_abb5f0* _Pvector) : CItQ_abb5f0(_Ptr, _Pvector)
    {}
};
struct VecQ_abb5f0
{
    void* _Myownedaux;
    int m04;
    char _Alval;
    char p09[3];
    ElQ_abb5f0* _Myfirst;
    ElQ_abb5f0* _Mylast;
    ElQ_abb5f0* _Myend;
    void FUN_0065dd90(ElQ_abb5f0* _First, ElQ_abb5f0* _Last);
    ItQ_abb5f0 FUN_00abb5f0(CItQ_abb5f0 _First_arg, CItQ_abb5f0 _Last_arg);
};
inline CItQ_abb5f0::CItQ_abb5f0(ElQ_abb5f0* _Ptr, const VecQ_abb5f0* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        FUN_00ec7c56();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00abb5f0
ItQ_abb5f0 VecQ_abb5f0::FUN_00abb5f0(CItQ_abb5f0 _First_arg, CItQ_abb5f0 _Last_arg)
{
    ItQ_abb5f0 _First(_First_arg._Myptr, this);
    ItQ_abb5f0 _Last(_Last_arg._Myptr, this);
    if (_First.FUN_00ac0460(_Last))
    {
        ElQ_abb5f0* _Ptr = UCopy_abb5f0(_Last._Myptr, _Mylast, _First._Myptr);
        FUN_0065dd90(_Ptr, _Mylast);
        _Mylast = _Ptr;
        Dead10_abb5f0();
    }
    return _First;
}

namespace fnv_00abb700 {
inline void Dead31()
{
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
    int d8;
    int d9;
    int d10;
    int d11;
    int d12;
    int d13;
    int d14;
    int d15;
    int d16;
    int d17;
    int d18;
    int d19;
    int d20;
    int d21;
    int d22;
    int d23;
    int d24;
    int d25;
    int d26;
    int d27;
    int d28;
    int d29;
    int d30;
    int d31;
    int d32;
    int d33;
    int d34;
    int d35;
    int d36;
}
struct FUN_0065ed70
{
    int m[13];
    FUN_0065ed70(const FUN_0065ed70&);
    ~FUN_0065ed70();
};
struct VecQ_abb700;
struct CItQ_abb700_abb700
{
    void* _Myaux;
    FUN_0065ed70* _Myptr;
    CItQ_abb700_abb700()
    {}
    CItQ_abb700_abb700(FUN_0065ed70* _Ptr, const VecQ_abb700* _Pvector);
    CItQ_abb700_abb700& FUN_00ac0d00(int _Off);
};
struct ItQ_abb700 : CItQ_abb700_abb700
{
    ItQ_abb700()
    {}
    ItQ_abb700(FUN_0065ed70* _Ptr, const VecQ_abb700* _Pvector) : CItQ_abb700_abb700(_Ptr, _Pvector)
    {}
    ItQ_abb700& operator+=(int _Off)
    {
        (*(CItQ_abb700_abb700*)this).FUN_00ac0d00(_Off);
        return (*this);
    }
    ItQ_abb700 operator+(int _Off) const
    {
        ItQ_abb700 _Tmp = *this;
        return (_Tmp += _Off);
    }
};
struct VecQ_abb700
{
    void* _Myownedaux;
    int m04;
    int m08;
    FUN_0065ed70* _Myfirst;
    FUN_0065ed70* _Mylast;
    FUN_0065ed70* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    ItQ_abb700 begin()
    {
        return ItQ_abb700(_Myfirst, this);
    }
    ItQ_abb700 end()
    {
        return ItQ_abb700(_Mylast, this);
    }
    void FUN_00abf210(CItQ_abb700_abb700 _Where, unsigned int _Count, const FUN_0065ed70& _Val);
    ItQ_abb700 FUN_00abb930(CItQ_abb700_abb700 _First, CItQ_abb700_abb700 _Last);
    void FUN_00abb700(unsigned int _Newsize, FUN_0065ed70 _Val);
};
inline CItQ_abb700_abb700::CItQ_abb700_abb700(FUN_0065ed70* _Ptr, const VecQ_abb700* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        FUN_00ec7c56();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00abb700
void VecQ_abb700::FUN_00abb700(unsigned int _Newsize, FUN_0065ed70 _Val)
{
    int _Unused;
    if (size() < _Newsize)
        FUN_00abf210(end(), _Newsize - size(), _Val);
    else if (_Newsize < size())
    {
        FUN_00abb930(begin() + _Newsize, end());
        Dead31();
    }
}
}  // namespace fnv_00abb700

// FUN_00abb930 : vector<Elem>::erase(first, last), VC9 STL with /Ob1 inlining
class MemoryManager;
extern MemoryManager DAT_011f6238;

struct S00abb930_Pool
{
    void FUN_00aa4060(void* p);
};

struct S00abb930_Elem
{
    int f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24, f28, f2c, f30;
    void FUN_0065ed70();
    ~S00abb930_Elem()
    {
        FUN_0065ed70();
    }
    void operator delete(void* p)
    {
        reinterpret_cast<S00abb930_Pool*>(&DAT_011f6238)->FUN_00aa4060(p);
    }
};

struct S00abb930_RangeTag
{
};
struct S00abb930_PtrTag
{
};
struct S00abb930_RandTag
{
    S00abb930_RandTag()
    {}
};

S00abb930_Elem* __cdecl FUN_00ac18c0(S00abb930_Elem* first, S00abb930_Elem* last, S00abb930_Elem* dest,
                                     S00abb930_RandTag, S00abb930_PtrTag, S00abb930_RangeTag);
void __cdecl FUN_00ec7c56();

struct S00abb930_Iter
{
    void* m_proxy;
    S00abb930_Elem* m_ptr;
    bool FUN_00ac0460(const S00abb930_Iter& other) const;
};

inline S00abb930_PtrTag S00abb930_PtrCat(S00abb930_Elem* const&, S00abb930_Elem* const&)
{
    S00abb930_PtrTag cat;
    return cat;
}

inline S00abb930_Elem* S00abb930_CheckedBase(S00abb930_Elem* const& p)
{
    int b0;
    return p;
}

inline void S00abb930_Pad()
{
    int c0;
    int c1;
    int c2;
    int c3;
    int c4;
}

inline S00abb930_Elem* S00abb930_CheckedBase2(S00abb930_Elem* const& p)
{
    int b0;
    S00abb930_Elem* r = p;
    S00abb930_Pad();
    return r;
}

inline S00abb930_Elem* S00abb930_UncheckedCopy(S00abb930_Elem* first, S00abb930_Elem* last, S00abb930_Elem* dest)
{
    return FUN_00ac18c0(S00abb930_CheckedBase2(first), S00abb930_CheckedBase(last), dest, S00abb930_RandTag(),
                        S00abb930_PtrCat(first, dest), S00abb930_RangeTag());
}

template <class T> inline void S00abb930_DestroyPtr(T* p)
{
    p->~T();
}

struct S00abb930_Alloc
{
    void destroy(S00abb930_Elem* p)
    {
        S00abb930_DestroyPtr(p);
    }
};

inline void S00abb930_DestroyRange2(S00abb930_Elem* first, S00abb930_Elem* last, S00abb930_Alloc& al, S00abb930_PtrTag)
{
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
    int d8;
    int d9;
    int d10;
    int d11;
    int d12;
    for (; first != last; ++first)
        al.destroy(first);
}

inline void S00abb930_DestroyRange(S00abb930_Elem* first, S00abb930_Elem* last, S00abb930_Alloc& al)
{
    S00abb930_DestroyRange2(first, last, al, S00abb930_PtrCat(first, last));
}

struct S00abb930_Vec
{
    void* m_00;
    int m_04;
    S00abb930_Alloc m_08;
    S00abb930_Elem* m_0c;
    S00abb930_Elem* m_10;
    void Destroy(S00abb930_Elem* first, S00abb930_Elem* last)
    {
        S00abb930_DestroyRange(first, last, m_08);
    }
    S00abb930_Iter FUN_00abb930(S00abb930_Iter pFirst, S00abb930_Iter pLast);
};

// @fnv 0x00abb930
S00abb930_Iter S00abb930_Vec::FUN_00abb930(S00abb930_Iter pFirst, S00abb930_Iter pLast)
{
    S00abb930_Iter it;
    it.m_proxy = 0;
    if (this == 0 || m_0c > pFirst.m_ptr || pFirst.m_ptr > m_10)
        FUN_00ec7c56();
    it.m_proxy = m_00;
    it.m_ptr = pFirst.m_ptr;

    S00abb930_Iter last;
    last.m_proxy = 0;
    if (this == 0 || m_0c > pLast.m_ptr || pLast.m_ptr > m_10)
        FUN_00ec7c56();
    last.m_proxy = m_00;
    last.m_ptr = pLast.m_ptr;

    if (it.FUN_00ac0460(last))
    {
        S00abb930_Elem* ptr = S00abb930_UncheckedCopy(last.m_ptr, m_10, it.m_ptr);
        Destroy(ptr, m_10);
        m_10 = ptr;
    }
    return it;
}

namespace fnv_00abbae0 {
inline void Dead31()
{
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
    int d8;
    int d9;
    int d10;
    int d11;
    int d12;
    int d13;
    int d14;
    int d15;
    int d16;
    int d17;
    int d18;
    int d19;
    int d20;
    int d21;
    int d22;
    int d23;
    int d24;
    int d25;
    int d26;
    int d27;
    int d28;
    int d29;
    int d30;
    int d31;
    int d32;
    int d33;
    int d34;
    int d35;
}
struct FUN_0065edd0
{
    int m[14];
    FUN_0065edd0(const FUN_0065edd0&);
    ~FUN_0065edd0();
};
struct VecQ_abbae0;
struct CItQ_abbae0_abbae0
{
    void* _Myaux;
    FUN_0065edd0* _Myptr;
    CItQ_abbae0_abbae0()
    {}
    CItQ_abbae0_abbae0(FUN_0065edd0* _Ptr, const VecQ_abbae0* _Pvector);
    CItQ_abbae0_abbae0& FUN_00ad3750(int _Off);
};
struct ItQ_abbae0 : CItQ_abbae0_abbae0
{
    ItQ_abbae0()
    {}
    ItQ_abbae0(FUN_0065edd0* _Ptr, const VecQ_abbae0* _Pvector) : CItQ_abbae0_abbae0(_Ptr, _Pvector)
    {}
    ItQ_abbae0& operator+=(int _Off)
    {
        (*(CItQ_abbae0_abbae0*)this).FUN_00ad3750(_Off);
        return (*this);
    }
    ItQ_abbae0 operator+(int _Off) const
    {
        ItQ_abbae0 _Tmp = *this;
        return (_Tmp += _Off);
    }
};
struct VecQ_abbae0
{
    void* _Myownedaux;
    int m04;
    int m08;
    FUN_0065edd0* _Myfirst;
    FUN_0065edd0* _Mylast;
    FUN_0065edd0* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    ItQ_abbae0 begin()
    {
        return ItQ_abbae0(_Myfirst, this);
    }
    ItQ_abbae0 end()
    {
        return ItQ_abbae0(_Mylast, this);
    }
    void FUN_00abfa90(CItQ_abbae0_abbae0 _Where, unsigned int _Count, const FUN_0065edd0& _Val);
    ItQ_abbae0 FUN_00abbd10(CItQ_abbae0_abbae0 _First, CItQ_abbae0_abbae0 _Last);
    void FUN_00abbae0(unsigned int _Newsize, FUN_0065edd0 _Val);
};
inline CItQ_abbae0_abbae0::CItQ_abbae0_abbae0(FUN_0065edd0* _Ptr, const VecQ_abbae0* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        FUN_00ec7c56();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00abbae0
void VecQ_abbae0::FUN_00abbae0(unsigned int _Newsize, FUN_0065edd0 _Val)
{
    int _Unused;
    if (size() < _Newsize)
        FUN_00abfa90(end(), _Newsize - size(), _Val);
    else if (_Newsize < size())
    {
        FUN_00abbd10(begin() + _Newsize, end());
        Dead31();
    }
}
}  // namespace fnv_00abbae0

namespace fnv_00abbd10 {
inline void DeadA()
{
    int a[5];
}
inline void DeadB()
{
    int a[12];
}
struct ElQ
{
    int m[14];
    void FUN_0065edd0();
    void DelQ(unsigned int f)
    {
        FUN_0065edd0();
        if (f & 1)
            DAT_011f6238.Deallocate(this);
    }
};
struct CatQ
{
};
struct TagQ
{
};
struct IterQ
{
    IterQ()
    {}
};
inline CatQ PtrCat(ElQ*&, ElQ*&)
{
    CatQ c;
    return c;
}
struct HelpQ
{
    ElQ* Base(ElQ* const& p)
    {
        return p;
    }
};
inline ElQ* Chk(ElQ* const& p)
{
    HelpQ _Helper;
    return _Helper.Base(p);
}
ElQ* __cdecl FUN_00ac1980(ElQ* _First, ElQ* _Last, ElQ* _Dest, IterQ, CatQ, TagQ);
inline ElQ* UCopy(ElQ* _First, ElQ* _Last, ElQ* _Dest)
{
    return FUN_00ac1980(Chk(_First), Chk(_Last), _Dest, IterQ(), PtrCat(_First, _Dest), TagQ());
    DeadA();
}
inline void DestroyR(ElQ* _First, ElQ* _Last, CatQ)
{
    for (; _First != _Last; ++_First)
        _First->DelQ(0);
    DeadB();
}
inline void DestroyR(ElQ* _First, ElQ* _Last)
{
    DestroyR(_First, _Last, PtrCat(_First, _Last));
}
struct VecQ;
struct CItQ
{
    void* _Myaux;
    ElQ* _Myptr;
    CItQ()
    {}
    CItQ(ElQ* _Ptr, const VecQ* _Pvector);
    bool FUN_00ac0460(const CItQ& _Right) const;
};
struct ItQ : CItQ
{
    ItQ()
    {}
    ItQ(ElQ* _Ptr, const VecQ* _Pvector) : CItQ(_Ptr, _Pvector)
    {}
};
struct VecQ
{
    void* _Myownedaux;
    int m04;
    char _Alval;
    char p09[3];
    ElQ* _Myfirst;
    ElQ* _Mylast;
    ElQ* _Myend;
    void Destroy(ElQ* _First, ElQ* _Last)
    {
        DestroyR(_First, _Last);
    }
    ItQ FUN_00abbd10(CItQ _First_arg, CItQ _Last_arg);
};
inline CItQ::CItQ(ElQ* _Ptr, const VecQ* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        FUN_00ec7c56();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00abbd10
ItQ VecQ::FUN_00abbd10(CItQ _First_arg, CItQ _Last_arg)
{
    ItQ _First(_First_arg._Myptr, this);
    ItQ _Last(_Last_arg._Myptr, this);
    if (_First.FUN_00ac0460(_Last))
    {
        ElQ* _Ptr = UCopy(_Last._Myptr, _Mylast, _First._Myptr);
        Destroy(_Ptr, _Mylast);
        _Mylast = _Ptr;
    }
    return _First;
}
}  // namespace fnv_00abbd10

namespace fnv_00abbf50 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        do
        {
        } while (0);
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
struct ElemBF50
{
    int unk00;
};
class FUN_00abbf50_Iterator : public _Vector_const_iteratorS<ElemBF50>
{
  public:
    ElemBF50& FUN_00abbf50() const;
};

// @fnv 0x00abbf50
ElemBF50& FUN_00abbf50_Iterator::FUN_00abbf50() const
{
    if (!(this->_Has_container()))
        InvalidParameterNoInfoS();
    if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
        InvalidParameterNoInfoS();
    return (*_Myptr);
}
}  // namespace fnv_00abbf50

struct S00abc120_shell
{
    void __thiscall FUN_00aa4060(void* p);
};

struct S00abc120_ptr
{
    void* m_v;
    __forceinline ~S00abc120_ptr()
    {}
};

struct S00abc120_cls
{
    void* m_00;

    void __thiscall FUN_00abc120();
};

// @fnv 0x00abc120
void __thiscall S00abc120_cls::FUN_00abc120()
{
    S00abc120_ptr p;
    p.m_v = m_00;
    ((S00abc120_shell*)&DAT_011f6238)->FUN_00aa4060(p.m_v);
}

namespace fnv_00abca90 {
struct Vec3Item
{
    unsigned int x, y, z;
};
struct CopyTag
{
};
struct RangeTag
{
};

struct ExceptionString
{
    unsigned int allocator;
    union
    {
        char buffer[16];
        char* data;
    } storage;
    unsigned int length, capacity;
    ExceptionString(const char*);
    ~ExceptionString();
};
struct LengthError
{
    virtual ~LengthError();
    const char* message;
    int ownsMessage;
    ExceptionString text;
    LengthError(const ExceptionString&);
};
extern const char DAT_010173c4[];
inline void __cdecl ThrowVectorTooLong()
{
    throw LengthError(ExceptionString(DAT_010173c4));
}

struct AllocationError
{
    virtual ~AllocationError();
    const char* message;
    int ownsMessage;
    AllocationError(const char* = 0);
};
void* __cdecl operator new(unsigned int);
inline Vec3Item* __cdecl FUN_0065e310(unsigned int _Count, int)
{
    if (_Count <= 0)
        _Count = 0;
    else if ((unsigned int)(-1) / _Count < sizeof(Vec3Item))
        throw AllocationError();
    return (Vec3Item*)operator new(_Count * sizeof(Vec3Item));
}

Vec3Item* __cdecl FUN_00ac3580(Vec3Item*, Vec3Item*, Vec3Item*, unsigned int*);
void __cdecl FUN_00ac20d0(Vec3Item*, unsigned int, const Vec3Item*, unsigned int*, CopyTag, RangeTag);

struct Vector3Heap
{
    void __thiscall FUN_00aa4060(void*);
};

struct UnchangedBaseTag
{
};
inline Vec3Item* checked_base_impl(Vec3Item*& _It, UnchangedBaseTag)
{
    return _It;
}
inline Vec3Item* checked_base(Vec3Item*& _It)
{
    UnchangedBaseTag _Base_tag;
    return checked_base_impl(_It, _Base_tag);
}
inline CopyTag ptr_cat(Vec3Item*&, Vec3Item*&)
{
    CopyTag _Cat;
    return _Cat;
}

inline Vec3Item* copy_impl(Vec3Item* _First, Vec3Item* _Last, Vec3Item* _Dest, unsigned int& _Al, CopyTag,
                           RangeTag _Checked)
{
    return FUN_00ac3580(_First, _Last, _Dest, &_Al);
}
inline Vec3Item* unchecked_copy(Vec3Item* _First, Vec3Item* _Last, Vec3Item* _Dest, unsigned int& _Al)
{
    return copy_impl(checked_base(_First), checked_base(_Last), _Dest, _Al, ptr_cat(_First, _Dest), RangeTag());
}
inline void unchecked_fill(Vec3Item* _First, unsigned int _Count, const Vec3Item& _Val, unsigned int& _Al)
{
    FUN_00ac20d0(_First, _Count, &_Val, &_Al, ptr_cat(_First, _First), RangeTag());
}
inline void destroy_impl(Vec3Item* _First, Vec3Item* _Last, unsigned int& _Al, CopyTag)
{
    for (; _First != _Last; ++_First)
        _First->~Vec3Item();
}
inline void destroy_range(Vec3Item* _First, Vec3Item* _Last, unsigned int& _Al)
{
    destroy_impl(_First, _Last, _Al, ptr_cat(_First, _Last));
}
inline void fill_impl(Vec3Item* _First, Vec3Item* _Last, const Vec3Item& _Val)
{
    for (; _First != _Last; ++_First)
        *_First = _Val;
}
inline void fill(Vec3Item* _First, Vec3Item* _Last, const Vec3Item& _Val)
{
    fill_impl(checked_base(_First), checked_base(_Last), _Val);
}

Vec3Item* __cdecl FUN_00ac3370(Vec3Item*, Vec3Item*, Vec3Item*, unsigned int*, CopyTag, RangeTag);
inline Vec3Item* raw_unchecked_copy(Vec3Item* _First, Vec3Item* _Last, Vec3Item* _Dest, unsigned int& _Al)
{
    return FUN_00ac3370(checked_base(_First), checked_base(_Last), _Dest, &_Al, ptr_cat(_First, _Dest), RangeTag());
}
inline Vec3Item* move_impl(Vec3Item* _First, Vec3Item* _Last, Vec3Item* _Dest, unsigned int& _Al, CopyTag, RangeTag)
{
    return raw_unchecked_copy(_First, _Last, _Dest, _Al);
}
inline Vec3Item* __cdecl FUN_00ac1af0(Vec3Item* _First, Vec3Item* _Last, Vec3Item* _Dest, unsigned int* _Al)
{
    return move_impl(checked_base(_First), checked_base(_Last), _Dest, *_Al, ptr_cat(_First, _Dest), RangeTag());
}
struct InputTag
{
};
struct ForwardTag : InputTag
{
};
struct BidirectionalTag : ForwardTag
{
};
struct RandomTag : BidirectionalTag
{
};
inline RandomTag iter_random(Vec3Item*&, Vec3Item*&)
{
    RandomTag _Cat;
    return _Cat;
}
inline Vec3Item* backward_loop(Vec3Item* _First, Vec3Item* _Last, Vec3Item* _Dest, ForwardTag, CopyTag, RangeTag)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return _Dest;
}
inline Vec3Item* backward_opt(Vec3Item* _First, Vec3Item* _Last, Vec3Item* _Dest, RandomTag, CopyTag, RangeTag)
{
    Vec3Item* _Result = _Dest - (_Last - _First);
    backward_loop(_First, _Last, checked_base(_Dest), ForwardTag(), CopyTag(), RangeTag());
    return _Result;
}

inline Vec3Item* backward_dispatch(Vec3Item* _First, Vec3Item* _Last, Vec3Item* _Dest, RandomTag, CopyTag, RangeTag)
{
    return backward_opt(_First, _Last, _Dest, RandomTag(), ptr_cat(_First, _Dest), RangeTag());
}
inline Vec3Item* __cdecl FUN_00ac1370(Vec3Item* _First, Vec3Item* _Last, Vec3Item* _Dest)
{
    return backward_dispatch(checked_base(_First), checked_base(_Last), _Dest, iter_random(_First, _Dest),
                             ptr_cat(_First, _Dest), RangeTag());
}
struct Vector3Storage
{
    unsigned int unk00, unk04, allocator;
    Vec3Item *first, *last, *end;
    inline unsigned int max_size() const
    {
        unsigned int _Count = 0x15555555u;
        return 0 < _Count ? _Count : 1;
    }
    inline void _Destroy(Vec3Item* _First, Vec3Item* _Last)
    {
        destroy_range(_First, _Last, allocator);
    }
    inline Vec3Item* _Ucopy(Vec3Item* _First, Vec3Item* _Last, Vec3Item* _Ptr)
    {
        return unchecked_copy(_First, _Last, _Ptr, allocator);
    }
    inline Vec3Item* _Ufill(Vec3Item* _Ptr, unsigned int _Count, const Vec3Item& _Val)
    {
        unchecked_fill(_Ptr, _Count, _Val, allocator);
        return _Ptr + _Count;
    }
    inline void deallocate(Vec3Item* _Ptr, unsigned int _Count)
    {
        ((Vector3Heap*)&DAT_011f6238)->FUN_00aa4060(_Ptr);
    }
    inline Vec3Item* _UcopyRaw(Vec3Item* _First, Vec3Item* _Last, Vec3Item* _Ptr)
    {
        return FUN_00ac1af0(_First, _Last, _Ptr, &allocator);
    }
    void FUN_00abca90(int unused, Vec3Item* position, unsigned int count, const Vec3Item* value);
};
// @fnv 0x00abca90
void Vector3Storage::FUN_00abca90(int unused, Vec3Item* position, unsigned int count, const Vec3Item* value)
{
    unsigned int _Capacity = first == 0 ? 0 : end - first;
    if (count == 0)
        ;
    else if (max_size() - (unsigned int)(last - first) < count)
        ThrowVectorTooLong();
    else if (_Capacity < (unsigned int)(last - first) + count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < (unsigned int)(last - first) + count)
            _Capacity = (unsigned int)(last - first) + count;
        Vec3Item* _Newvec = FUN_0065e310(_Capacity, 0);
        Vec3Item* _Newlast = _Newvec;
        try
        {
            _Newlast = _Ucopy(first, position, _Newvec);
            _Ufill(_Newlast, count, *value);
            _Newlast += count;
            _Ucopy(position, last, _Newlast);
        }
        catch (...)
        {
            destroy_range(_Newvec, _Newlast, allocator);
            ((Vector3Heap*)&DAT_011f6238)->FUN_00aa4060(_Newvec);
            throw;
        }
        count += (unsigned int)(last - first);
        if (first != 0)
        {
            _Destroy(first, last);
            deallocate(first, end - first);
        }
        end = _Newvec + _Capacity;
        last = _Newvec + count;
        first = _Newvec;
    }
    else if ((unsigned int)(last - position) < count)
    {
        Vec3Item _Tmp = *value;
        _Ucopy(position, last, position + count);
        try
        {
            _Ufill(last, count - (last - position), _Tmp);
        }
        catch (...)
        {
            _Destroy(position + count, last + count);
            throw;
        }
        last += count;
        fill(position, last - count, _Tmp);
    }
    else
    {
        Vec3Item _Tmp = *value;
        Vec3Item* _Oldend = last;
        last = _UcopyRaw(_Oldend - count, _Oldend, last);
        FUN_00ac1370(position, _Oldend - count, _Oldend);
        fill(position, position + count, _Tmp);
    }
}
}  // namespace fnv_00abca90

namespace fnv_00abdb10 {
// VC9 vector repeated insertion for a two-float value.
struct InsertPoint
{
    float x, y;
    InsertPoint(const InsertPoint& p) : x(p.x), y(p.y)
    {}
};
struct InsertPosition
{
    void* owner;
    InsertPoint* pointer;
};
struct MoveCategory
{
};
struct CheckedCategory
{
};
struct PointerCategory
{
};
struct PointAllocator
{
    typedef InsertPoint* pointer;
    typedef InsertPoint value_type;
    static InsertPoint* FUN_0065e3a0(unsigned int, const void* = 0);
    unsigned int max_size() const
    {
        unsigned int _Count = 0xffffffffu / sizeof(InsertPoint);
        return 0 < _Count ? _Count : 1;
    }
    void deallocate(InsertPoint* p, unsigned int)
    {
        DAT_011f6238.Deallocate(p);
    }
    void destroy(InsertPoint* p)
    {
        p->~InsertPoint();
    }
};
extern const char DAT_010173c4[];
struct ErrorString
{
    int allocator;
    union
    {
        char small[16];
        char* heap;
    } storage;
    unsigned int length, capacity;
    ErrorString(const char* text)
    {
        initialize();
        assign(text);
    }
    ~ErrorString()
    {
        initialize(true);
    }
    void initialize(bool = false, unsigned int = 0);
    unsigned int max_size() const
    {
        unsigned int count = 0xffffffffu;
        return count <= 1 ? 1 : count - 1;
    }
    void grow_storage(unsigned int, unsigned int);
    void too_long();
    char* pointer()
    {
        return capacity >= 16 ? storage.heap : storage.small;
    }
    unsigned int CalculateStringLength(const char*);
    void copy(char*, unsigned int, const char*, unsigned int);
    bool inside(const char* t)
    {
        return t && pointer() <= t && t < pointer() + length;
    }
    void copy_self(unsigned int, unsigned int);
    bool grow(unsigned int count)
    {
        if (max_size() < count)
            too_long();
        if (capacity < count)
            grow_storage(count, length);
        else if (count == 0)
        {
            length = 0;
            pointer()[0] = 0;
        }
        return 0 < count;
    }
    void assign(const char* t)
    {
        unsigned int count = CalculateStringLength(t);
        if (inside(t))
            copy_self(t - pointer(), count);
        else if (grow(count))
        {
            copy(pointer(), capacity, t, count);
            length = count;
            pointer()[count] = 0;
        }
    }
};
struct LengthError
{
    int vtable;
    const char* message;
    ErrorString text;
    LengthError(const ErrorString&);
    LengthError(const LengthError&);
    ~LengthError();
};
InsertPoint* FUN_00ac3690(InsertPoint*, InsertPoint*, InsertPoint*, PointAllocator&);
void FUN_00ac2290(InsertPoint*, unsigned int, const InsertPoint&, PointAllocator&, PointerCategory, CheckedCategory);
template <class Iter> inline Iter checked_base(Iter& _It, UnchangedBaseTag)
{
    return _It;
}
template <class Iter> inline Iter checked_base(Iter& _It)
{
    UnchangedBaseTag _Base_tag;
    return checked_base(_It, _Base_tag);
}
template <class Iter> inline MoveCategory move_category(const Iter&)
{
    MoveCategory _Cat;
    return _Cat;
}
template <class T1, class T2> inline PointerCategory pointer_category(T1&, T2&)
{
    PointerCategory _Cat;
    return _Cat;
}
inline InsertPoint* move_dispatch(InsertPoint* _First, InsertPoint* _Last, InsertPoint* _Dest, PointAllocator& _Al,
                                  MoveCategory, CheckedCategory)
{
    return FUN_00ac3690(_First, _Last, _Dest, _Al);
}
inline InsertPoint* move_inline(InsertPoint* _First, InsertPoint* _Last, InsertPoint* _Dest, PointAllocator& _Al)
{
    return move_dispatch(checked_base(_First), checked_base(_Last), _Dest, _Al, move_category(_Dest),
                         CheckedCategory());
}
InsertPoint* FUN_00ac3900(InsertPoint*, InsertPoint*, InsertPoint*, PointAllocator&, PointerCategory, CheckedCategory);
inline InsertPoint* copy_worker(InsertPoint* _First, InsertPoint* _Last, InsertPoint* _Dest, PointAllocator& _Al,
                                CheckedCategory)
{
    InsertPoint* _Result = _Dest;
    return FUN_00ac3900(checked_base(_First), checked_base(_Last), _Result, _Al, pointer_category(_Result, _Result),
                        CheckedCategory());
}
inline InsertPoint* FUN_00ac1c90(InsertPoint* _First, InsertPoint* _Last, InsertPoint* _Dest, PointAllocator& _Al)
{
    InsertPoint* output = _Dest;
    return copy_worker(checked_base(_First), checked_base(_Last), output, _Al, CheckedCategory());
}
inline InsertPoint* copy_backward_body(InsertPoint* first, InsertPoint* last, InsertPoint* dest, PointerCategory,
                                       CheckedCategory)
{
    while (first != last)
        *--dest = *--last;
    return dest;
}
inline InsertPoint* FUN_00ac1d10(InsertPoint* first, InsertPoint* last, InsertPoint* dest, MoveCategory,
                                 PointerCategory, CheckedCategory)
{
    InsertPoint* begin = first;
    InsertPoint* finish = dest;
    InsertPoint* result = finish - (last - begin);
    copy_backward_body(begin, last, finish, PointerCategory(), CheckedCategory());
    return result;
}
inline InsertPoint* move_backward_opt(InsertPoint* _First, InsertPoint* _Last, InsertPoint* _Dest,
                                      MoveCategory _Category, MoveCategory, CheckedCategory)
{
    return FUN_00ac1d10(_First, _Last, _Dest, _Category, pointer_category(_First, _Dest), CheckedCategory());
}
inline void FUN_00ac1530(InsertPoint* _First, InsertPoint* _Last, InsertPoint* _Dest)
{
    move_backward_opt(checked_base(_First), checked_base(_Last), _Dest, move_category(_First), move_category(_Dest),
                      CheckedCategory());
}
inline void fill_unchecked(InsertPoint* _First, unsigned int _Count, const InsertPoint& _Val, PointAllocator& _Al)
{
    FUN_00ac2290(_First, _Count, _Val, _Al, pointer_category(_First, _First), CheckedCategory());
}
inline void destroy_range(InsertPoint* _First, InsertPoint* _Last, PointAllocator& _Al, PointerCategory)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
inline void destroy_range(InsertPoint* _First, InsertPoint* _Last, PointAllocator& _Al)
{
    destroy_range(_First, _Last, _Al, pointer_category(_First, _Last));
}
inline void fill_range_inner(InsertPoint* _First, InsertPoint* _Last, const InsertPoint& _Val)
{
    for (; _First != _Last; ++_First)
        *_First = _Val;
}
inline void fill_range(InsertPoint* _First, InsertPoint* _Last, const InsertPoint& _Val)
{
    fill_range_inner(checked_base(_First), checked_base(_Last), _Val);
}
struct PairInsertionVector
{
    int unk00, unk04;
    PointAllocator _Alval;
    InsertPoint* _Myfirst;
    InsertPoint* _Mylast;
    InsertPoint* _Myend;
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int max_size() const
    {
        return _Alval.max_size();
    }
    void _Destroy(InsertPoint* _First, InsertPoint* _Last)
    {
        destroy_range(_First, _Last, _Alval);
    }
    InsertPoint* _Umove(InsertPoint* _First, InsertPoint* _Last, InsertPoint* _Ptr)
    {
        return move_inline(_First, _Last, _Ptr, _Alval);
    }
    InsertPoint* _Ucopy(InsertPoint* _First, InsertPoint* _Last, InsertPoint* _Ptr)
    {
        return FUN_00ac1c90(_First, _Last, _Ptr, _Alval);
    }
    void _Ufill(InsertPoint* _Ptr, unsigned int _Count, const InsertPoint& _Val)
    {
        fill_unchecked(_Ptr, _Count, _Val, _Alval);
    }
    void FUN_00abdb10(InsertPosition _Where, unsigned int _Count, const InsertPoint& _Val);
};
// @fnv 0x00abdb10
void PairInsertionVector::FUN_00abdb10(InsertPosition _Where, unsigned int _Count, const InsertPoint& _Val)
{
    unsigned int _Capacity = capacity();
    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        ThrowVectorTooLong();
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        InsertPoint* _Newvec = PointAllocator::FUN_0065e3a0(_Capacity);
        InsertPoint* _Ptr = _Newvec;
        try
        {
            _Ptr = _Umove(_Myfirst, _Where.pointer, _Newvec);
            _Ufill(_Ptr, _Count, _Val);
            _Ptr += _Count;
            _Umove(_Where.pointer, _Mylast, _Ptr);
        }
        catch (...)
        {
            _Destroy(_Newvec, _Ptr);
            _Alval.deallocate(_Newvec, _Capacity);
            throw;
        }
        _Count += size();
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myend = _Newvec + _Capacity;
        _Mylast = _Newvec + _Count;
        _Myfirst = _Newvec;
    }
    else if ((unsigned int)(_Mylast - _Where.pointer) < _Count)
    {
        InsertPoint _Tmp = _Val;
        _Umove(_Where.pointer, _Mylast, _Where.pointer + _Count);
        try
        {
            _Ufill(_Mylast, _Count - (_Mylast - _Where.pointer), _Tmp);
        }
        catch (...)
        {
            _Destroy(_Where.pointer + _Count, _Mylast + _Count);
            throw;
        }
        _Mylast += _Count;
        fill_range(_Where.pointer, _Mylast - _Count, _Tmp);
    }
    else
    {
        InsertPoint _Tmp = _Val;
        InsertPoint* _Oldend = _Mylast;
        _Mylast = _Ucopy(_Oldend - _Count, _Oldend, _Mylast);
        FUN_00ac1530(_Where.pointer, _Oldend - _Count, _Oldend);
        fill_range(_Where.pointer, _Where.pointer + _Count, _Tmp);
    }
}
}  // namespace fnv_00abdb10

namespace fnv_00ab0d50 {
inline void DeadN()
{
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
    int d8;
    int d9;
    int d10;
    int d11;
    int d12;
    int d13;
    int d14;
    int d15;
    int d16;
    int d17;
    int d18;
    int d19;
    int d20;
    int d21;
    int d22;
    int d23;
    int d24;
    int d25;
    int d26;
    int d27;
    int d28;
    int d29;
}
inline void FreeI(void* p)
{
    DAT_011f6238.Deallocate(p);
}
struct B0Q
{
    ~B0Q()
    {}
};
struct MBQ : B0Q
{
    void* m_p;
    ~MBQ()
    {
        FreeI(m_p);
    }
};
struct MidQ : MBQ
{
    ~MidQ() throw()
    {}
};
struct MQ : MidQ
{
    void FUN_0065f430();
    ~MQ()
    {
        FUN_0065f430();
    }
};
struct ElQ
{
    int a;
    MQ m;
    int r[5];
};
struct VecQ_ab0d50;
struct CItQ_ab0d50_ab0d50
{
    void* _Myaux;
    ElQ* _Myptr;
    CItQ_ab0d50_ab0d50()
    {}
    CItQ_ab0d50_ab0d50(ElQ* _Ptr, const VecQ_ab0d50* _Pvector);
    CItQ_ab0d50_ab0d50& FUN_00ad35e0(int _Off);
};
struct ItQ_ab0d50 : CItQ_ab0d50_ab0d50
{
    ItQ_ab0d50()
    {}
    ItQ_ab0d50(ElQ* _Ptr, const VecQ_ab0d50* _Pvector) : CItQ_ab0d50_ab0d50(_Ptr, _Pvector)
    {}
    ItQ_ab0d50& operator+=(int _Off)
    {
        (*(CItQ_ab0d50_ab0d50*)this).FUN_00ad35e0(_Off);
        return (*this);
    }
    ItQ_ab0d50 operator+(int _Off) const
    {
        ItQ_ab0d50 _Tmp = *this;
        return (_Tmp += _Off);
    }
};
struct VecQ_ab0d50
{
    void* _Myownedaux;
    int m04;
    int m08;
    ElQ* _Myfirst;
    ElQ* _Mylast;
    ElQ* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    ItQ_ab0d50 begin()
    {
        return ItQ_ab0d50(_Myfirst, this);
    }
    ItQ_ab0d50 end()
    {
        return ItQ_ab0d50(_Mylast, this);
    }
    void FUN_00ab1800(CItQ_ab0d50_ab0d50 _Where, unsigned int _Count, const ElQ& _Val);
    ItQ_ab0d50 FUN_0065d740(CItQ_ab0d50_ab0d50 _First, CItQ_ab0d50_ab0d50 _Last);
    void FUN_00ab0d50(unsigned int _Newsize, ElQ _Val);
};
inline CItQ_ab0d50_ab0d50::CItQ_ab0d50_ab0d50(ElQ* _Ptr, const VecQ_ab0d50* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        FUN_00ec7c56();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00ab0d50
void VecQ_ab0d50::FUN_00ab0d50(unsigned int _Newsize, ElQ _Val)
{
    if (size() < _Newsize)
        FUN_00ab1800(end(), _Newsize - size(), _Val);
    else if (_Newsize < size())
    {
        FUN_0065d740(begin() + _Newsize, end());
        DeadN();
    }
}
}  // namespace fnv_00ab0d50

namespace fnv_00ab2210 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
extern "C" int __cdecl memmove_s(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _MaxCount);
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
struct _Undefined_move_tagS
{
};
template <class _Ty> struct _Move_operation_categoryS
{
    typedef _Undefined_move_tagS _Move_cat;
};
template <class _Iter>
inline typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Move_catS(const _Iter&)
{
    typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Cat;
    return (_Cat);
}
template <class _InIt, class _FwdIt, class _Alloc, class _MoveCatTy>
inline _FwdIt _Uninit_moveS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _MoveCatTy,
                            _Range_checked_iterator_tagS)
{
    return (unchecked_uninitialized_copyS(_First, _Last, _Dest, _Al));
}
template <class _Ty1, class _Ty2>
_Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS);
template <class _Ty1, class _Ty2>
inline _Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Scalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _Ty2 _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _FwdIt _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unchecked_fill_nS(_First, _Count, _Val);
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void unchecked_uninitialized_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al)
{
    _Uninit_fill_nS(_First, _Count, _Val, _Al, _Ptr_catS(_First, _First), _Range_checked_iterator_tagS());
}
template <class _BidIt1, class _BidIt2, class _InOutItCat, class _MoveCatTy>
inline _BidIt2 _Move_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat _First_dest_cat,
                                   _MoveCatTy, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
struct EUMB
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
// @fnv 0x00ab2210
EUMB* __cdecl FUN_00ab2210(EUMB* _First, EUMB* _Last, EUMB* _Dest)
{
    return (_Move_backward_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                                _Move_catS(_Dest), _Range_checked_iterator_tagS()));
}
}  // namespace fnv_00ab2210

namespace fnv_00ab2260 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
extern "C" int __cdecl memmove_s(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _MaxCount);
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
struct _Undefined_move_tagS
{
};
template <class _Ty> struct _Move_operation_categoryS
{
    typedef _Undefined_move_tagS _Move_cat;
};
template <class _Iter>
inline typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Move_catS(const _Iter&)
{
    typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Cat;
    return (_Cat);
}
template <class _InIt, class _FwdIt, class _Alloc, class _MoveCatTy>
inline _FwdIt _Uninit_moveS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _MoveCatTy,
                            _Range_checked_iterator_tagS)
{
    return (unchecked_uninitialized_copyS(_First, _Last, _Dest, _Al));
}
struct ElemMOVE
{
    int unk00;
    int unk04;
};
// @fnv 0x00ab2260
ElemMOVE* __cdecl FUN_00ab2260(ElemMOVE* _First, ElemMOVE* _Last, ElemMOVE* _Dest, allocatorS<ElemMOVE>& _Al)
{
    return (_Uninit_moveS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Move_catS(_Dest),
                          _Range_checked_iterator_tagS()));
}
}  // namespace fnv_00ab2260

namespace fnv_00ab4490 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
extern "C" int __cdecl memmove_s(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _MaxCount);
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
struct _Undefined_move_tagS
{
};
template <class _Ty> struct _Move_operation_categoryS
{
    typedef _Undefined_move_tagS _Move_cat;
};
template <class _Iter>
inline typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Move_catS(const _Iter&)
{
    typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Cat;
    return (_Cat);
}
template <class _InIt, class _FwdIt, class _Alloc, class _MoveCatTy>
inline _FwdIt _Uninit_moveS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _MoveCatTy,
                            _Range_checked_iterator_tagS)
{
    return (unchecked_uninitialized_copyS(_First, _Last, _Dest, _Al));
}
template <class _Ty1, class _Ty2>
_Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS);
template <class _Ty1, class _Ty2>
inline _Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Scalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _Ty2 _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _FwdIt _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unchecked_fill_nS(_First, _Count, _Val);
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void unchecked_uninitialized_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al)
{
    _Uninit_fill_nS(_First, _Count, _Val, _Al, _Ptr_catS(_First, _First), _Range_checked_iterator_tagS());
}
template <class _BidIt1, class _BidIt2, class _InOutItCat, class _MoveCatTy>
inline _BidIt2 _Move_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat _First_dest_cat,
                                   _MoveCatTy, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
// @fnv 0x00ab4490
unsigned char* __cdecl FUN_00ab4490(unsigned char* _First, unsigned char* _Last, unsigned char* _Dest)
{
    return (_Move_backward_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                                _Move_catS(_Dest), _Range_checked_iterator_tagS()));
}
}  // namespace fnv_00ab4490

namespace fnv_00ab9bc0 {
struct ElQ_ab9bc0
{
    int m[3];
};
struct AlQ_ab9bc0
{
};
struct CatQ_ab9bc0
{
};
struct TagQ_ab9bc0
{
};
struct ElQ_ab9bc0;
inline CatQ_ab9bc0 PtrCat_ab9bc0(ElQ_ab9bc0*&, ElQ_ab9bc0*&)
{
    CatQ_ab9bc0 c;
    return c;
}
void __cdecl FUN_00ac20d0(ElQ_ab9bc0* _First, unsigned int _Count, const ElQ_ab9bc0& _Val, AlQ_ab9bc0& _Al, CatQ_ab9bc0,
                          TagQ_ab9bc0);
inline void UFillN_ab9bc0(ElQ_ab9bc0* _First, unsigned int _Count, const ElQ_ab9bc0& _Val, AlQ_ab9bc0& _Al)
{
    FUN_00ac20d0(_First, _Count, _Val, _Al, PtrCat_ab9bc0(_First, _First), TagQ_ab9bc0());
}
struct VecQ_ab9bc0;
struct CItQ_ab9bc0
{
    void* _Myaux;
    ElQ_ab9bc0* _Myptr;
    CItQ_ab9bc0()
    {}
    CItQ_ab9bc0(ElQ_ab9bc0* _Ptr, const VecQ_ab9bc0* _Pvector);
};
struct ItQ_ab9bc0 : CItQ_ab9bc0
{
    ItQ_ab9bc0()
    {}
    ItQ_ab9bc0(ElQ_ab9bc0* _Ptr, const VecQ_ab9bc0* _Pvector) : CItQ_ab9bc0(_Ptr, _Pvector)
    {}
};
struct VecQ_ab9bc0
{
    void* _Myownedaux;
    int m04;
    AlQ_ab9bc0 _Alval;
    char p09[3];
    ElQ_ab9bc0* _Myfirst;
    ElQ_ab9bc0* _Mylast;
    ElQ_ab9bc0* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    ItQ_ab9bc0 end()
    {
        return ItQ_ab9bc0(_Mylast, this);
    }
    ElQ_ab9bc0* _Ufill(ElQ_ab9bc0* _Ptr, unsigned int _Count, const ElQ_ab9bc0& _Val)
    {
        UFillN_ab9bc0(_Ptr, _Count, _Val, _Alval);
        return _Ptr + _Count;
    }
    ItQ_ab9bc0 FUN_00aba3c0(CItQ_ab9bc0 _Where, const ElQ_ab9bc0& _Val);
    void FUN_00ab9bc0(const ElQ_ab9bc0& _Val);
};
inline CItQ_ab9bc0::CItQ_ab9bc0(ElQ_ab9bc0* _Ptr, const VecQ_ab9bc0* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        FUN_00ec7c56();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
inline void Dead12_ab9bc0()
{
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
    int d8;
    int d9;
    int d10;
}
// @fnv 0x00ab9bc0
void VecQ_ab9bc0::FUN_00ab9bc0(const ElQ_ab9bc0& _Val)
{
    if (size() < capacity())
        _Mylast = _Ufill(_Mylast, 1, _Val);
    else
    {
        FUN_00aba3c0(end(), _Val);
        Dead12_ab9bc0();
    }
}
}  // namespace fnv_00ab9bc0

namespace fnv_00ab9cd0 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
struct Elem9CD0
{
    int unk00;
    int unk04;
    int unk08;
};
class FUN_00ab9cd0_Vector : public vectorS<Elem9CD0>
{
  public:
    void FUN_00ab9cd0();
};

// @fnv 0x00ab9cd0
void FUN_00ab9cd0_Vector::FUN_00ab9cd0()
{
    erase(begin(), end());
}
}  // namespace fnv_00ab9cd0

#include <math.h>
void ReportAssertionViolation(const char*, unsigned int);

double FUN_00ec6054(double);

inline float FGSqrt(float x)
{
    return sqrt(x);
}

void* _fnv_zlib_memset(void*, int, unsigned int);

struct FGView
{

    float* data;

    void* owner;
    FGView(float*, unsigned int);

    inline float* pointer(unsigned int i)
    {
        return data + i;
    }

    inline float& operator[](unsigned int i)
    {
        return *pointer(i);
    }
};

inline void FGFree(void* ptr)
{
    DAT_011f6238.Deallocate(ptr);
}
template <class T> struct FGAlloc
{
    typedef T* pointer;
    FGAlloc()
    {}
    template <class U> FGAlloc(const FGAlloc<U>&)
    {}
    void deallocate(T* ptr, unsigned int)
    {
        FGFree(ptr);
    }
};
struct FGContainer;
struct FGAux
{
    const FGContainer* owner;
};
struct FGContainer
{
    FGAux* proxy;
    ~FGContainer()
    {}
};
template <class T> struct FGProxy : FGContainer
{
    FGAlloc<FGAux> proxyAllocator;
    ~FGProxy()
    {
        proxy->~FGAux();
        proxyAllocator.deallocate(proxy, 1);
    }
};
template <class T> struct FGVal : FGProxy<T>
{
    FGAlloc<T> allocator;
};
struct FGScalarTag
{
};
template <class T> inline FGScalarTag FGCategory(T* const&, T* const&)
{
    FGScalarTag category;
    return category;
}
template <class A> inline void FGDestroyRange(typename A::pointer, typename A::pointer, A&, FGScalarTag)
{}
template <class A> inline void FGDestroyRange(typename A::pointer begin, typename A::pointer end, A& allocator)
{
    FGDestroyRange(begin, end, allocator, FGCategory(begin, end));
}
void FUN_00ec7c56();
struct FGVector : FGVal<float>
{
    float* first;
    float* last;
    float* limit;
    float& operator[](unsigned int index)
    {
        {
            if (!(index < (unsigned int)(last - first)))
            {
                {
                    FUN_00ec7c56();
                }
            }
        }
        return first[index];
    }
    void destroy(float* begin, float* end)
    {
        FGDestroyRange(begin, end, allocator);
    }
    void FUN_0065f240()
    {
        if (first != 0)
        {
            destroy(first, last);
            allocator.deallocate(first, limit - first);
        }
        first = 0, last = 0, limit = 0;
    }
    ~FGVector()
    {
        FUN_0065f240();
    }
};
struct FGMatrix : FGVector
{
    unsigned int rows, cols;
    void FUN_0060b410(unsigned int n, float value);
    float* FUN_006578b0(unsigned int i)
    {
        return &(*this)[i];
    }
    FGView FUN_0060b370(int index)
    {
        FGView out(FUN_006578b0(0) + index * cols, cols);
        return out;
    }
    float FUN_006588a0();
    FGMatrix BuildScaledValues(float scale);
    FGMatrix FUN_00aadda0(float scale);
    FGMatrix Transpose();
    FGMatrix FUN_00658360(const FGMatrix&);
    FGMatrix FUN_00aaed70(const FGMatrix&);
    FGMatrix& FUN_006581e0(const FGMatrix&);
    FGMatrix& ScaleAll(float);
    FGMatrix& operator*=(float value)
    {
        return ScaleAll(value);
    }
    inline void resize(unsigned int r, unsigned int c, float value = 0.0f)
    {
        rows = r;
        cols = c;
        FUN_0060b410(r * c, value);
    }
    inline ~FGMatrix()
    {}
};
struct FUN_0065d6e0 : FGContainer
{
    FGAlloc<FGAux> proxyAllocator;
    ~FUN_0065d6e0();
};
struct FGScaledVal : FUN_0065d6e0
{
    FGAlloc<float> allocator;
};
struct FGScaledVector : FGScaledVal
{
    float* first;
    float* last;
    float* limit;
    void destroy(float* begin, float* end)
    {
        FGDestroyRange(begin, end, allocator);
    }
    void FUN_0065f240()
    {
        if (first != 0)
        {
            destroy(first, last);
            allocator.deallocate(first, limit - first);
        }
        first = 0, last = 0, limit = 0;
    }
    ~FGScaledVector()
    {
        FUN_0065f240();
    }
};
struct FGScaledMatrix : FGScaledVector
{
    unsigned int rows, cols;
    ~FGScaledMatrix()
    {}
};
struct FGBasis : FGMatrix
{

    float inverse, weight;

    FGScaledMatrix FUN_00aadda0(float scale);
};

struct FGCross
{
    FGMatrix vectors[2];
    float inverse, weight;
};

struct FGSourceMatrices
{
    FGMatrix first[2];
    FGMatrix square;
    FGMatrix second[2];
};

struct FGNormalized
{
    FGMatrix first, second;
};

struct FGSmall
{
    void zero()
    {
        _fnv_zlib_memset(this, 0, 16);
    }

    union
    {
        float value[2][2];
        S_00aadd20_Vector raw;
    };

    FGSmall()
    {}

    inline FGSmall(const S_00aadd20_Vector& r) : raw(r)
    {}

    inline float& at(unsigned int r, unsigned int c)
    {
        return value[r][c];
    }

    inline S_00aadd20_Vector inverse()
    {
        S_00aadd20_Vector out;
        S_00aadd20_Vector result;
        result = *FUN_00aadd20(&out, &raw);
        return result;
    }
};

struct FGReader
{

    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();

    virtual bool read(void*, unsigned int, unsigned int);
};

struct FGSize
{
    unsigned int count, other;
};

struct FGModel
{

    bool loaded;

    FGSourceMatrices matrices[5];

    FGBasis bases[5][2][2];

    FGCross cross[5][5];

    FGNormalized normalized[5][2];

    FGSmall small[5][2];

    bool FUN_00aaaf10(FGReader* file, FGSize* sizes);
};

// @fnv 0x00aaaf10
bool FGModel::FUN_00aaaf10(FGReader* file, FGSize* sizes)
{

    unsigned int total2;

    unsigned int i;

    for (i = 0; i < 5; ++i)
    {

        for (unsigned int j = 0; j < 2; ++j)
        {

            for (unsigned int k = 0; k < 2; ++k)
            {

                bases[i][j][k].resize(1, sizes[k].count);

                if (!file->read(&bases[i][j][k].FUN_0060b370(0)[0], 4, sizes[k].count))
                    return false;

                if (!file->read(&bases[i][j][k].weight, 4, 1))
                    return false;

                bases[i][j][k].inverse = 1.0f / bases[i][j][k].FUN_006588a0();
            }
        }
    }

    for (i = 0; i < 5; ++i)
    {

        for (unsigned int j = 0; j < 5; ++j)
        {

            if (j != i)
            {

                float sum4 = 0.0f;

                for (unsigned int k = 0; k < 2; ++k)
                {

                    cross[i][j].vectors[k].resize(1, sizes[k].count);

                    if (!file->read(&cross[i][j].vectors[k].FUN_0060b370(0)[0], 4, sizes[k].count))
                        return false;

                    sum4 += cross[i][j].vectors[k].FUN_006588a0();
                }

                if (!file->read(&cross[i][j].weight, 4, 1))
                    return false;

                cross[i][j].inverse = 1.0f / sum4;
            }
        }
    }

    total2 = sizes[0].count + sizes[1].count;

    for (i = 0; i < 5; ++i)
    {

        unsigned int j;

        for (j = 0; j < 2; ++j)
        {

            unsigned int n = sizes[j].count;

            matrices[i].first[j].resize(n, 1);

            if (!file->read(&matrices[i].first[j].FUN_0060b370(0)[0], 4, n))
                return false;
        }

        matrices[i].square.resize(total2, total2);

        if (!file->read(&matrices[i].square.FUN_0060b370(0)[0], 4, total2 * total2))
            return false;

        for (j = 0; j < 2; ++j)
        {

            unsigned int n = sizes[j].count;

            matrices[i].second[j].resize(n, n);

            if (!file->read(&matrices[i].second[j].FUN_0060b370(0)[0], 4, n * n))
                return false;
        }
    }

    for (i = 0; i < 5; ++i)
    {

        for (unsigned int j = 0; j < 2; ++j)
        {

            float dot4;

            float norm5 = FGSqrt(bases[i][0][j].FUN_006588a0());

            if (norm5 > 0.001)
            {
            }
            else
                ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\FanControls.cpp", 0x90);

            normalized[i][j].first.FUN_006581e0((const FGMatrix&)bases[i][0][j].FUN_00aadda0(norm5));

            dot4 = bases[i][1][j].FUN_00658360(normalized[i][j].first.Transpose()).FUN_0060b370(0)[0];

            normalized[i][j].second.FUN_006581e0(
                bases[i][1][j].FUN_00aaed70(normalized[i][j].first.BuildScaledValues(dot4)));

            norm5 = FGSqrt(normalized[i][j].second.FUN_006588a0());

            if (norm5 > 0.001)
            {
            }
            else
                ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\FanControls.cpp", 0x98);

            normalized[i][j].second *= 1.0f / norm5;
        }
    }

    if (true)
    {
    }
    else
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\FanControls.cpp", 0xa1);

    for (i = 0; i < 5; ++i)
    {

        for (unsigned int j = 0; j < 2; ++j)
        {

            small[i][j].zero();

            for (unsigned int k = 0; k < 2; ++k)
            {

                for (unsigned int l = 0; l < 2; ++l)
                {

                    small[i][j].at(k, l) +=
                        bases[i][k][j].FUN_00658360(bases[i][l][j].Transpose()).FUN_0060b370(0)[0];
                }
            }

            small[i][j] = FGSmall(small[i][j].inverse());
        }
    }

    loaded = true;

    return true;
}

namespace fnv_00aac3f0 {
static const char DAT_010a2c5c[] = "D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\FanControls.cpp";
// Stand-in for the locals of FaceGen inline helpers that /Ob1 expanded here but whose
// source is not identified; each one only reserves N ints of frame space.
template <int N> __forceinline void UnusedInlineLocals()
{
    int locals[N];
}

double FUN_00ec6054(double x);
void __cdecl ReportAssertionViolation(const char* file, int line);

inline double FgSqrtf(float value)
{
    return (float)FUN_00ec6054(value);
}
inline float FgSqrt(float value)
{
    return FgSqrtf(value);
}
inline float FgSqrt(unsigned int value)
{
    return (float)FUN_00ec6054((double)value);
}
inline float SquareFloat(float x)
{
    return x * x;
}
void FUN_00ec7c56();

struct FgCoord
{
    float* m_data;
    unsigned int m_cols;
    FgCoord(float* data, unsigned int cols) : m_data(data), m_cols(cols)
    {}
    inline float& operator[](int i)
    {
        UnusedInlineLocals<2>();
        return m_data[i];
    }
};

struct FgVecBase
{
    ~FgVecBase();
};

struct FgVecT : FgVecBase
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void FUN_0065f240();
    ~FgVecT()
    {
        FUN_0065f240();
    }
};

struct FgMatT
{
    FgVecT m_vec;
    unsigned int m_rows;
    unsigned int m_cols;
    FgCoord FUN_0060b370(int idx);
    FgMatT BuildScaledValues(float val);
};

struct FgMat
{
    int unk00;
    int unk04;
    int unk08;
    float* m_pRayStart;
    float* m_kRayEnd;
    float* m_cap;
    unsigned int m_rows;
    unsigned int m_cols;
    ~FgMat();
    unsigned int FUN_00662820() const
    {
        return m_kRayEnd - m_pRayStart;
    }
    float* FUN_006578b0(unsigned int idx)
    {
        if (idx >= FUN_00662820())
            FUN_00ec7c56();
        return m_pRayStart + idx;
    }
    FgCoord FUN_0060b370(unsigned int row)
    {
        return FgCoord(FUN_006578b0(0) + row * m_cols, m_cols);
    }
    float FUN_006588a0();
    FgMat FUN_00aaed70(const FgMat& rhs);
    FgMat FUN_00658360(const FgMat& rhs);
    void FUN_00aaef90(const FgMatT& rhs);
};

inline unsigned int FgRowCount(FgMat& matrix)
{
    unsigned int rows = matrix.m_rows;
    return rows;
}

struct FgMatD
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned int m_rows;
    unsigned int m_cols;
    FgMatT FUN_00658360(const FgMat& rhs);
    FgMatT Transpose();
};

struct FanControls
{
    unsigned char m_enabled;
    char unk01;
    char unk02;
    char unk03;
    FgMat m_matrices_04[5][5];
    int unk_0324;
    int unk_0328;
    int unk_032c;
    int unk_0330;
    int unk_0334;
    int unk_0338;
    int unk_033c;
    int unk_0340;
    int unk_0344;
    int unk_0348;
    int unk_034c;
    int unk_0350;
    int unk_0354;
    int unk_0358;
    int unk_035c;
    int unk_0360;
    int unk_0364;
    int unk_0368;
    int unk_036c;
    int unk_0370;
    int unk_0374;
    int unk_0378;
    int unk_037c;
    int unk_0380;
    int unk_0384;
    int unk_0388;
    int unk_038c;
    int unk_0390;
    int unk_0394;
    int unk_0398;
    int unk_039c;
    int unk_03a0;
    int unk_03a4;
    int unk_03a8;
    int unk_03ac;
    int unk_03b0;
    int unk_03b4;
    int unk_03b8;
    int unk_03bc;
    int unk_03c0;
    int unk_03c4;
    int unk_03c8;
    int unk_03cc;
    int unk_03d0;
    int unk_03d4;
    int unk_03d8;
    int unk_03dc;
    int unk_03e0;
    int unk_03e4;
    int unk_03e8;
    int unk_03ec;
    int unk_03f0;
    int unk_03f4;
    int unk_03f8;
    int unk_03fc;
    int unk_0400;
    int unk_0404;
    int unk_0408;
    int unk_040c;
    int unk_0410;
    int unk_0414;
    int unk_0418;
    int unk_041c;
    int unk_0420;
    int unk_0424;
    int unk_0428;
    int unk_042c;
    int unk_0430;
    int unk_0434;
    int unk_0438;
    int unk_043c;
    int unk_0440;
    int unk_0444;
    int unk_0448;
    int unk_044c;
    int unk_0450;
    int unk_0454;
    int unk_0458;
    int unk_045c;
    int unk_0460;
    int unk_0464;
    int unk_0468;
    int unk_046c;
    int unk_0470;
    int unk_0474;
    int unk_0478;
    int unk_047c;
    int unk_0480;
    int unk_0484;
    int unk_0488;
    int unk_048c;
    int unk_0490;
    int unk_0494;
    int unk_0498;
    int unk_049c;
    int unk_04a0;
    int unk_04a4;
    int unk_04a8;
    int unk_04ac;
    int unk_04b0;
    int unk_04b4;
    int unk_04b8;
    int unk_04bc;
    int unk_04c0;
    int unk_04c4;
    int unk_04c8;
    int unk_04cc;
    int unk_04d0;
    int unk_04d4;
    int unk_04d8;
    int unk_04dc;
    int unk_04e0;
    int unk_04e4;
    int unk_04e8;
    int unk_04ec;
    int unk_04f0;
    int unk_04f4;
    int unk_04f8;
    int unk_04fc;
    int unk_0500;
    int unk_0504;
    int unk_0508;
    int unk_050c;
    int unk_0510;
    int unk_0514;
    int unk_0518;
    int unk_051c;
    int unk_0520;
    int unk_0524;
    int unk_0528;
    int unk_052c;
    int unk_0530;
    int unk_0534;
    int unk_0538;
    int unk_053c;
    int unk_0540;
    int unk_0544;
    int unk_0548;
    int unk_054c;
    int unk_0550;
    int unk_0554;
    int unk_0558;
    int unk_055c;
    int unk_0560;
    int unk_0564;
    int unk_0568;
    int unk_056c;
    int unk_0570;
    int unk_0574;
    int unk_0578;
    int unk_057c;
    int unk_0580;
    int unk_0584;
    int unk_0588;
    int unk_058c;
    int unk_0590;
    int unk_0594;
    int unk_0598;
    int unk_059c;
    int unk_05a0;
    int unk_05a4;
    int unk_05a8;
    int unk_05ac;
    int unk_05b0;
    int unk_05b4;
    int unk_05b8;
    int unk_05bc;
    int unk_05c0;
    int unk_05c4;
    int unk_05c8;
    int unk_05cc;
    int unk_05d0;
    int unk_05d4;
    int unk_05d8;
    int unk_05dc;
    int unk_05e0;
    int unk_05e4;
    int unk_05e8;
    int unk_05ec;
    int unk_05f0;
    int unk_05f4;
    int unk_05f8;
    int unk_05fc;
    int unk_0600;
    int unk_0604;
    int unk_0608;
    int unk_060c;
    int unk_0610;
    int unk_0614;
    int unk_0618;
    int unk_061c;
    int unk_0620;
    int unk_0624;
    int unk_0628;
    int unk_062c;
    int unk_0630;
    int unk_0634;
    int unk_0638;
    int unk_063c;
    int unk_0640;
    int unk_0644;
    int unk_0648;
    int unk_064c;
    int unk_0650;
    int unk_0654;
    int unk_0658;
    int unk_065c;
    int unk_0660;
    int unk_0664;
    int unk_0668;
    int unk_066c;
    int unk_0670;
    int unk_0674;
    int unk_0678;
    int unk_067c;
    int unk_0680;
    int unk_0684;
    int unk_0688;
    int unk_068c;
    int unk_0690;
    int unk_0694;
    int unk_0698;
    int unk_069c;
    int unk_06a0;
    int unk_06a4;
    int unk_06a8;
    int unk_06ac;
    int unk_06b0;
    int unk_06b4;
    int unk_06b8;
    int unk_06bc;
    int unk_06c0;
    int unk_06c4;
    int unk_06c8;
    int unk_06cc;
    int unk_06d0;
    int unk_06d4;
    int unk_06d8;
    int unk_06dc;
    int unk_06e0;
    int unk_06e4;
    int unk_06e8;
    int unk_06ec;
    int unk_06f0;
    int unk_06f4;
    int unk_06f8;
    int unk_06fc;
    int unk_0700;
    int unk_0704;
    int unk_0708;
    int unk_070c;
    int unk_0710;
    int unk_0714;
    int unk_0718;
    int unk_071c;
    int unk_0720;
    int unk_0724;
    int unk_0728;
    int unk_072c;
    int unk_0730;
    int unk_0734;
    int unk_0738;
    int unk_073c;
    int unk_0740;
    int unk_0744;
    int unk_0748;
    int unk_074c;
    int unk_0750;
    int unk_0754;
    int unk_0758;
    int unk_075c;
    int unk_0760;
    int unk_0764;
    int unk_0768;
    int unk_076c;
    int unk_0770;
    int unk_0774;
    int unk_0778;
    int unk_077c;
    int unk_0780;
    int unk_0784;
    int unk_0788;
    int unk_078c;
    int unk_0790;
    int unk_0794;
    int unk_0798;
    int unk_079c;
    int unk_07a0;
    int unk_07a4;
    int unk_07a8;
    int unk_07ac;
    int unk_07b0;
    int unk_07b4;
    int unk_07b8;
    int unk_07bc;
    int unk_07c0;
    int unk_07c4;
    int unk_07c8;
    int unk_07cc;
    int unk_07d0;
    int unk_07d4;
    int unk_07d8;
    int unk_07dc;
    int unk_07e0;
    int unk_07e4;
    int unk_07e8;
    int unk_07ec;
    int unk_07f0;
    int unk_07f4;
    int unk_07f8;
    int unk_07fc;
    int unk_0800;
    int unk_0804;
    int unk_0808;
    int unk_080c;
    int unk_0810;
    int unk_0814;
    int unk_0818;
    int unk_081c;
    int unk_0820;
    int unk_0824;
    int unk_0828;
    int unk_082c;
    int unk_0830;
    int unk_0834;
    int unk_0838;
    int unk_083c;
    int unk_0840;
    int unk_0844;
    int unk_0848;
    int unk_084c;
    int unk_0850;
    int unk_0854;
    int unk_0858;
    int unk_085c;
    int unk_0860;
    int unk_0864;
    int unk_0868;
    int unk_086c;
    int unk_0870;
    int unk_0874;
    int unk_0878;
    int unk_087c;
    int unk_0880;
    int unk_0884;
    int unk_0888;
    int unk_088c;
    int unk_0890;
    int unk_0894;
    int unk_0898;
    int unk_089c;
    int unk_08a0;
    int unk_08a4;
    int unk_08a8;
    int unk_08ac;
    int unk_08b0;
    int unk_08b4;
    int unk_08b8;
    int unk_08bc;
    int unk_08c0;
    int unk_08c4;
    int unk_08c8;
    int unk_08cc;
    int unk_08d0;
    int unk_08d4;
    int unk_08d8;
    int unk_08dc;
    int unk_08e0;
    int unk_08e4;
    int unk_08e8;
    int unk_08ec;
    int unk_08f0;
    int unk_08f4;
    int unk_08f8;
    int unk_08fc;
    int unk_0900;
    int unk_0904;
    int unk_0908;
    int unk_090c;
    int unk_0910;
    int unk_0914;
    int unk_0918;
    int unk_091c;
    int unk_0920;
    int unk_0924;
    int unk_0928;
    int unk_092c;
    int unk_0930;
    int unk_0934;
    int unk_0938;
    int unk_093c;
    int unk_0940;
    int unk_0944;
    int unk_0948;
    int unk_094c;
    int unk_0950;
    int unk_0954;
    int unk_0958;
    int unk_095c;
    int unk_0960;
    int unk_0964;
    int unk_0968;
    int unk_096c;
    int unk_0970;
    int unk_0974;
    int unk_0978;
    int unk_097c;
    int unk_0980;
    int unk_0984;
    int unk_0988;
    int unk_098c;
    int unk_0990;
    int unk_0994;
    int unk_0998;
    int unk_099c;
    int unk_09a0;
    int unk_09a4;
    int unk_09a8;
    int unk_09ac;
    int unk_09b0;
    int unk_09b4;
    int unk_09b8;
    int unk_09bc;
    int unk_09c0;
    int unk_09c4;
    int unk_09c8;
    int unk_09cc;
    int unk_09d0;
    int unk_09d4;
    int unk_09d8;
    int unk_09dc;
    int unk_09e0;
    int unk_09e4;
    int unk_09e8;
    int unk_09ec;
    int unk_09f0;
    int unk_09f4;
    int unk_09f8;
    int unk_09fc;
    int unk_0a00;
    int unk_0a04;
    int unk_0a08;
    int unk_0a0c;
    int unk_0a10;
    int unk_0a14;
    int unk_0a18;
    int unk_0a1c;
    int unk_0a20;
    int unk_0a24;
    int unk_0a28;
    int unk_0a2c;
    int unk_0a30;
    int unk_0a34;
    int unk_0a38;
    int unk_0a3c;
    int unk_0a40;
    int unk_0a44;
    int unk_0a48;
    int unk_0a4c;
    int unk_0a50;
    int unk_0a54;
    int unk_0a58;
    int unk_0a5c;
    int unk_0a60;
    int unk_0a64;
    int unk_0a68;
    int unk_0a6c;
    int unk_0a70;
    int unk_0a74;
    int unk_0a78;
    int unk_0a7c;
    int unk_0a80;
    int unk_0a84;
    int unk_0a88;
    int unk_0a8c;
    int unk_0a90;
    int unk_0a94;
    int unk_0a98;
    int unk_0a9c;
    int unk_0aa0;
    int unk_0aa4;
    int unk_0aa8;
    int unk_0aac;
    int unk_0ab0;
    int unk_0ab4;
    int unk_0ab8;
    int unk_0abc;
    int unk_0ac0;
    int unk_0ac4;
    int unk_0ac8;
    int unk_0acc;
    int unk_0ad0;
    int unk_0ad4;
    int unk_0ad8;
    int unk_0adc;
    int unk_0ae0;
    int unk_0ae4;
    int unk_0ae8;
    int unk_0aec;
    int unk_0af0;
    int unk_0af4;
    int unk_0af8;
    int unk_0afc;
    int unk_0b00;
    int unk_0b04;
    int unk_0b08;
    int unk_0b0c;
    int unk_0b10;
    int unk_0b14;
    int unk_0b18;
    int unk_0b1c;
    int unk_0b20;
    int unk_0b24;
    int unk_0b28;
    int unk_0b2c;
    int unk_0b30;
    int unk_0b34;
    int unk_0b38;
    int unk_0b3c;
    int unk_0b40;
    int unk_0b44;
    int unk_0b48;
    int unk_0b4c;
    int unk_0b50;
    int unk_0b54;
    int unk_0b58;
    int unk_0b5c;
    int unk_0b60;
    int unk_0b64;
    int unk_0b68;
    int unk_0b6c;
    int unk_0b70;
    int unk_0b74;
    int unk_0b78;
    int unk_0b7c;
    int unk_0b80;
    int unk_0b84;
    int unk_0b88;
    int unk_0b8c;
    int unk_0b90;
    int unk_0b94;
    int unk_0b98;
    int unk_0b9c;
    int unk_0ba0;
    int unk_0ba4;
    int unk_0ba8;
    int unk_0bac;
    int unk_0bb0;
    int unk_0bb4;
    int unk_0bb8;
    int unk_0bbc;
    int unk_0bc0;
    int unk_0bc4;
    int unk_0bc8;
    int unk_0bcc;
    int unk_0bd0;
    int unk_0bd4;
    int unk_0bd8;
    int unk_0bdc;
    int unk_0be0;
    int unk_0be4;
    int unk_0be8;
    int unk_0bec;
    int unk_0bf0;
    int unk_0bf4;
    int unk_0bf8;
    int unk_0bfc;
    int unk_0c00;
    int unk_0c04;
    int unk_0c08;
    int unk_0c0c;
    int unk_0c10;
    int unk_0c14;
    int unk_0c18;
    int unk_0c1c;
    int unk_0c20;
    int unk_0c24;
    int unk_0c28;
    int unk_0c2c;
    int unk_0c30;
    int unk_0c34;
    int unk_0c38;
    int unk_0c3c;
    int unk_0c40;
    int unk_0c44;
    int unk_0c48;
    int unk_0c4c;
    int unk_0c50;
    int unk_0c54;
    int unk_0c58;
    int unk_0c5c;
    int unk_0c60;
    int unk_0c64;
    int unk_0c68;
    int unk_0c6c;
    int unk_0c70;
    int unk_0c74;
    int unk_0c78;
    int unk_0c7c;
    int unk_0c80;
    int unk_0c84;
    int unk_0c88;
    int unk_0c8c;
    int unk_0c90;
    int unk_0c94;
    int unk_0c98;
    int unk_0c9c;
    int unk_0ca0;
    int unk_0ca4;
    int unk_0ca8;
    int unk_0cac;
    int unk_0cb0;
    int unk_0cb4;
    int unk_0cb8;
    int unk_0cbc;
    int unk_0cc0;
    int unk_0cc4;
    int unk_0cc8;
    int unk_0ccc;
    int unk_0cd0;
    int unk_0cd4;
    int unk_0cd8;
    int unk_0cdc;
    int unk_0ce0;
    int unk_0ce4;
    int unk_0ce8;
    int unk_0cec;
    int unk_0cf0;
    int unk_0cf4;
    int unk_0cf8;
    int unk_0cfc;
    int unk_0d00;
    int unk_0d04;
    int unk_0d08;
    int unk_0d0c;
    int unk_0d10;
    int unk_0d14;
    int unk_0d18;
    int unk_0d1c;
    int unk_0d20;
    int unk_0d24;
    int unk_0d28;
    int unk_0d2c;
    int unk_0d30;
    int unk_0d34;
    int unk_0d38;
    int unk_0d3c;
    int unk_0d40;
    int unk_0d44;
    int unk_0d48;
    FgMatD m_matrices_d4c[5][2][2];

    float FUN_00aac3f0(int arg1, int arg2, int arg3, FgMat (*arg4)[2]);
};

// @fnv 0x00aac3f0
float FanControls::FUN_00aac3f0(int arg1, int arg2, int arg3, FgMat (*arg4)[2])
{

    if (arg1 < 5)
    {
    }
    else
    {
        ReportAssertionViolation(DAT_010a2c5c, 308);
    }
    if (arg2 < 2)
    {
    }
    else
    {
        ReportAssertionViolation(DAT_010a2c5c, 309);
    }
    if (arg3 < 2)
    {
    }
    else
    {
        ReportAssertionViolation(DAT_010a2c5c, 310);
    }

    if (!m_enabled)
        return 0.0f;

    if (arg3 == 1)
    {

        return FgSqrt(arg4[arg2][arg3].FUN_006588a0()) / FgSqrt(arg4[arg2][arg3].m_rows);
    }
    else if (arg3 == 0)
    {

        FgMat mat5 = arg4[arg2][arg3].FUN_00aaed70(m_matrices_04[arg1][arg2]);
        for (unsigned int i = 0; i < 2; ++i)
        {

            float coord2 = m_matrices_d4c[arg1][arg2][i].FUN_00658360(mat5).FUN_0060b370(0)[0];
            mat5.FUN_00aaef90(m_matrices_d4c[arg1][arg2][i].Transpose().BuildScaledValues(coord2));
        }

        UnusedInlineLocals<21>();
        FgMat aRes = (m_matrices_04[arg1] + arg2)[3].FUN_00658360(mat5);
        return FgSqrt(aRes.FUN_006588a0()) / FgSqrtf((float)(FgRowCount(aRes) - 2.0));
    }
    else
    {
        if (false)
        {
        }
        else
        {
            ReportAssertionViolation(DAT_010a2c5c, 344);
        }
        UnusedInlineLocals<16>();
    }
    return 0.0f;
}
}  // namespace fnv_00aac3f0

#include <math.h>
namespace fnv_00aac820 {
#include <math.h>

void ReportAssertionViolation(const char*, int);

static inline float FgSqrtf(float x)
{
    return (float)sqrt((double)x);
}
static inline float FgSqrt(float x)
{
    return FgSqrtf(x);
}
static inline float FgSqrtN(unsigned int n)
{
    return (float)sqrt((double)n);
}

static __forceinline void fgDead2()
{
    int aiDead[2];
}
static __forceinline void fgDead4()
{
    int aiDead[4];
}
static __forceinline void fgDead64()
{
    int aiDead[64];
}

struct FgRow
{
    float* data;
    int len;
    ~FgRow()
    {}
    float& operator[](int i)
    {
        fgDead4();
        return data[i];
    }
};

struct FgStore
{
    int unk00;
    int unk04;
    float* first;
    float* last;
    float* end;
    int unk14;
    FgStore();
    ~FgStore();
    void FUN_0065f240();
};

struct FgCore : FgStore
{
    unsigned int rows;
    unsigned int cols;
    ~FgCore()
    {
        FUN_0065f240();
    }
};

struct FgMat : FgCore
{
    FgMat(unsigned int r, unsigned int c)
    {
        fgDead2();
        rows = r;
        cols = c;
        Resize(cols * rows);
    }
    void Resize(unsigned int n)
    {
        FUN_0060b410(n, 0.0f);
    }
    void e0()
    {}
    void e1()
    {}
    void e2()
    {}
    void e3()
    {}
    void e4()
    {}
    ~FgMat()
    {
        e0();
        e1();
        e2();
        e3();
        e4();
    }
    void FUN_0060b410(unsigned int n, float v);
    void FUN_0060b3b0();
    float FUN_006588a0();
    unsigned int NumRows()
    {
        return rows;
    }
    unsigned int NumCols()
    {
        return cols;
    }
    void ScaleAll(float s);
    FgMat FUN_00aaed70(const FgMat& m);
    FgMat FUN_00658360(const FgMat& m);
    FgRow FUN_0060b370(int r);
    FgMat Transpose();
    FgMat BuildScaledValues(float s);
    void AddMatrix(const FgMat& m);
    void FUN_00aaef90(const FgMat& m);
    FgMat FUN_00658500(const FgMat& m);
    void FUN_006581e0(const FgMat& m);
};

struct FgParams
{
    FgMat values[2][2];
};

struct FanControls
{
    bool enabled;
    FgMat means[5][5];
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
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    int unk9a8;
    int unk9ac;
    int unk9b0;
    int unk9b4;
    int unk9b8;
    int unk9bc;
    int unk9c0;
    int unk9c4;
    int unk9c8;
    int unk9cc;
    int unk9d0;
    int unk9d4;
    int unk9d8;
    int unk9dc;
    int unk9e0;
    int unk9e4;
    int unk9e8;
    int unk9ec;
    int unk9f0;
    int unk9f4;
    int unk9f8;
    int unk9fc;
    int unka00;
    int unka04;
    int unka08;
    int unka0c;
    int unka10;
    int unka14;
    int unka18;
    int unka1c;
    int unka20;
    int unka24;
    int unka28;
    int unka2c;
    int unka30;
    int unka34;
    int unka38;
    int unka3c;
    int unka40;
    int unka44;
    int unka48;
    int unka4c;
    int unka50;
    int unka54;
    int unka58;
    int unka5c;
    int unka60;
    int unka64;
    int unka68;
    int unka6c;
    int unka70;
    int unka74;
    int unka78;
    int unka7c;
    int unka80;
    int unka84;
    int unka88;
    int unka8c;
    int unka90;
    int unka94;
    int unka98;
    int unka9c;
    int unkaa0;
    int unkaa4;
    int unkaa8;
    int unkaac;
    int unkab0;
    int unkab4;
    int unkab8;
    int unkabc;
    int unkac0;
    int unkac4;
    int unkac8;
    int unkacc;
    int unkad0;
    int unkad4;
    int unkad8;
    int unkadc;
    int unkae0;
    int unkae4;
    int unkae8;
    int unkaec;
    int unkaf0;
    int unkaf4;
    int unkaf8;
    int unkafc;
    int unkb00;
    int unkb04;
    int unkb08;
    int unkb0c;
    int unkb10;
    int unkb14;
    int unkb18;
    int unkb1c;
    int unkb20;
    int unkb24;
    int unkb28;
    int unkb2c;
    int unkb30;
    int unkb34;
    int unkb38;
    int unkb3c;
    int unkb40;
    int unkb44;
    int unkb48;
    int unkb4c;
    int unkb50;
    int unkb54;
    int unkb58;
    int unkb5c;
    int unkb60;
    int unkb64;
    int unkb68;
    int unkb6c;
    int unkb70;
    int unkb74;
    int unkb78;
    int unkb7c;
    int unkb80;
    int unkb84;
    int unkb88;
    int unkb8c;
    int unkb90;
    int unkb94;
    int unkb98;
    int unkb9c;
    int unkba0;
    int unkba4;
    int unkba8;
    int unkbac;
    int unkbb0;
    int unkbb4;
    int unkbb8;
    int unkbbc;
    int unkbc0;
    int unkbc4;
    int unkbc8;
    int unkbcc;
    int unkbd0;
    int unkbd4;
    int unkbd8;
    int unkbdc;
    int unkbe0;
    int unkbe4;
    int unkbe8;
    int unkbec;
    int unkbf0;
    int unkbf4;
    int unkbf8;
    int unkbfc;
    int unkc00;
    int unkc04;
    int unkc08;
    int unkc0c;
    int unkc10;
    int unkc14;
    int unkc18;
    int unkc1c;
    int unkc20;
    int unkc24;
    int unkc28;
    int unkc2c;
    int unkc30;
    int unkc34;
    int unkc38;
    int unkc3c;
    int unkc40;
    int unkc44;
    int unkc48;
    int unkc4c;
    int unkc50;
    int unkc54;
    int unkc58;
    int unkc5c;
    int unkc60;
    int unkc64;
    int unkc68;
    int unkc6c;
    int unkc70;
    int unkc74;
    int unkc78;
    int unkc7c;
    int unkc80;
    int unkc84;
    int unkc88;
    int unkc8c;
    int unkc90;
    int unkc94;
    int unkc98;
    int unkc9c;
    int unkca0;
    int unkca4;
    int unkca8;
    int unkcac;
    int unkcb0;
    int unkcb4;
    int unkcb8;
    int unkcbc;
    int unkcc0;
    int unkcc4;
    int unkcc8;
    int unkccc;
    int unkcd0;
    int unkcd4;
    int unkcd8;
    int unkcdc;
    int unkce0;
    int unkce4;
    int unkce8;
    int unkcec;
    int unkcf0;
    int unkcf4;
    int unkcf8;
    int unkcfc;
    int unkd00;
    int unkd04;
    int unkd08;
    int unkd0c;
    int unkd10;
    int unkd14;
    int unkd18;
    int unkd1c;
    int unkd20;
    int unkd24;
    int unkd28;
    int unkd2c;
    int unkd30;
    int unkd34;
    int unkd38;
    int unkd3c;
    int unkd40;
    int unkd44;
    int unkd48;

    FgMat bases[5][2][2];
    float FUN_00aac3f0(int model, int category, int channel, FgParams* params);
    void FUN_00aac820(int model, int category, int channel, float amount, FgParams* params);
};

// @fnv 0x00aac820
void FanControls::FUN_00aac820(int model, int category, int channel, float amount, FgParams* params)
{
    if (model < 5)
    {
    }
    else
    {
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\FanControls.cpp", 0x172);
    }
    if (category < 2)
    {
    }
    else
    {
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\FanControls.cpp", 0x173);
    }
    if (channel < 2)
    {
    }
    else
    {
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\FanControls.cpp", 0x174);
    }
    if (!enabled)
        return;
    if (amount < 0.0099999997764825821)
        amount = 0.01f;
    if (channel == 1)
    {
        float scale = sqrt(params->values[category][channel].FUN_006588a0()) /
                      FgSqrtN(params->values[category][channel].NumRows());
        if (scale > 0.0)
        {
            params->values[category][channel].ScaleAll(amount / scale);
        }
        else
        {
            return;
        }
    }
    else if (channel == 0)
    {
        FgMat centered = params->values[category][channel].FUN_00aaed70(means[model][category]);
        FgMat projection(params->values[category][channel].NumRows(), params->values[category][channel].NumCols());
        projection.FUN_0060b3b0();
        for (unsigned int axis = 0; axis < 2; ++axis)
        {
            float weight = bases[model][category][axis].FUN_00658360(centered).FUN_0060b370(0)[0];
            fgDead64();
            projection.AddMatrix(bases[model][category][axis].Transpose().BuildScaledValues(weight));
        }
        centered.FUN_00aaef90(projection);
        float scale3 = FUN_00aac3f0(model, category, channel, params);
        if (scale3 > 0.0)
        {
            centered.ScaleAll(amount / scale3);
        }
        else
        {
            return;
        }
        params->values[category][channel].FUN_006581e0(
            centered.FUN_00658500(projection).FUN_00658500(means[model][category]));
    }
}
}  // namespace fnv_00aac820

namespace fnv_00aacdb0 {
void __cdecl ReportAssertionViolation(const char* pcFile, int iLine);
struct MemoryManagerAACDB0
{
    void Deallocate(void* pvMem);
};
extern MemoryManagerAACDB0 g_kMemoryAACDB0;
struct ProxyAACDB0
{
    void* m_pkContainer;
};
template <class T> struct AllocatorAACDB0
{
    AllocatorAACDB0()
    {}
    ~AllocatorAACDB0()
    {}
    void deallocate(T* pkPtr, unsigned int)
    {
        g_kMemoryAACDB0.Deallocate(pkPtr);
    }
    void destroy(T* pkPtr)
    {
        pkPtr->~T();
    }
};
struct AuxBaseAACDB0
{
    ~AuxBaseAACDB0()
    {
        m_kAlAux.destroy(m_pkAux);
        m_kAlAux.deallocate(m_pkAux, 1);
    }
    ProxyAACDB0* m_pkAux;
    AllocatorAACDB0<ProxyAACDB0> m_kAlAux;
};
struct ScalarTagAACDB0
{
};
inline ScalarTagAACDB0 PtrCatAACDB0(float*&, float*&)
{
    ScalarTagAACDB0 kCat;
    return kCat;
}
template <class T, class A> inline void DestroyRangeAACDB0(T*, T*, A&, ScalarTagAACDB0)
{}
template <class T, class A> inline void DestroyRangeAACDB0(T* pFirst, T* pLast, A& kAl)
{
    DestroyRangeAACDB0(pFirst, pLast, kAl, PtrCatAACDB0(pFirst, pLast));
}
struct FloatVectorVal : public AuxBaseAACDB0
{
    AllocatorAACDB0<float> m_kAlval;
    float* m_pfFirst;
    float* m_pfLast;
    float* m_pfEnd;
};
void __cdecl FUN_00ec7c56();
struct FloatVector : public FloatVectorVal
{
    ~FloatVector()
    {
        _Tidy();
    }
    unsigned int size() const
    {
        return m_pfFirst == 0 ? 0 : m_pfLast - m_pfFirst;
    }
    float& operator[](unsigned int uiPos)
    {
        if (!(uiPos < size()))
            FUN_00ec7c56();
        do
        {
        } while (0);
        return *(m_pfFirst + uiPos);
    }
    void _Destroy(float* pfFirst, float* pfLast)
    {
        DestroyRangeAACDB0(pfFirst, pfLast, m_kAlval);
    }
    void _Tidy()
    {
        if (m_pfFirst != 0)
        {
            _Destroy(m_pfFirst, m_pfLast);
            m_kAlval.deallocate(m_pfFirst, m_pfEnd - m_pfFirst);
        }
        m_pfFirst = 0;
        m_pfLast = 0;
        m_pfEnd = 0;
    }
};
struct FgRow
{
    FgRow(float* pVector4, unsigned int uiStride) : m_pfData(pVector4), m_uiStride(uiStride)
    {}
    float& operator[](unsigned int uiCol)
    {
        return m_pfData[uiCol];
    }
    float* m_pfData;
    unsigned int m_uiStride;
};
struct FgMatrix
{
    FgRow Row(unsigned int uiRow)
    {
        return FgRow(&m_kData[0] + uiRow * m_uiCols, m_uiCols);
    }
    FloatVector m_kData;
    unsigned int m_uiRows;
    unsigned int m_uiCols;
};
struct FgCoordinates
{
    float m_afValues[16];
};
struct FgCoordinateBasis
{
    FgMatrix Transform(const FgCoordinates& kCoords) const;
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct FgControlPair
{
    FgCoordinateBasis m_akBasis[2];
    int unk40;
    float m_fSequenceOffset;
};
struct FanControls
{
    bool m_bEnableState;
    char unk01;
    char unk02;
    char unk03;
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
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    FgControlPair m_aakPairs[5][5];
    float FUN_00aacdb0(int iFrom, int iTo, const FgCoordinates* pkCoords);
};

// @fnv 0x00aacdb0
float FanControls::FUN_00aacdb0(int iFrom, int iTo, const FgCoordinates* pkCoords)
{
    if (iFrom < 5)
        ;
    else
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\FanControls.cpp", 436);
    if (iTo < 5)
        ;
    else
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\FanControls.cpp", 437);
    if (iFrom != iTo)
        ;
    else
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\FanControls.cpp", 438);
    if (!m_bEnableState)
        return 0.0f;
    float fValue = 0.0f;
    for (unsigned int i = 0; i < 2; ++i)
        fValue += m_aakPairs[iFrom][iTo].m_akBasis[i].Transform(pkCoords[i]).Row(0)[0];
    fValue += m_aakPairs[iFrom][iTo].m_fSequenceOffset;
    return fValue;
}
}  // namespace fnv_00aacdb0

namespace fnv_00aaf750 {
struct Image
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned int rows;
    unsigned int cols;
    Image& operator=(const Image&);
};

namespace std {
template <class E> struct char_traits
{
};
template <class T> class allocator
{
};

struct StringBase
{
};
template <class E, class Tr, class A> class basic_string : public StringBase
{
  public:
    typedef basic_string<E, Tr, A> Myt;
    static const unsigned int npos;
    Myt& operator=(const Myt& right)
    {
        return assign(right);
    }
    Myt& assign(const Myt& right)
    {
        return assign(right, 0, npos);
    }
    Myt& assign(const Myt& right, unsigned int roff, unsigned int count)
    {
        unsigned a00, a01, a02, a03, a04, a05, a06, a07, a08, a09, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19,
            a20;
        if (roff == count)
        {
            a00 = roff;
            a01 = a00;
            a02 = a01;
            a03 = a02;
            a04 = a03;
            a05 = a04;
            a06 = a05;
            a07 = a06;
            a08 = a07;
            a09 = a08;
            a10 = a09;
            a11 = a10;
            a12 = a11;
            a13 = a12;
            a14 = a13;
            a15 = a14;
            a16 = a15;
            a17 = a16;
            a18 = a17;
            a19 = a18;
            a20 = a19;
            return *this;
        }
        return assign(right, roff + 1, count);
    }
    A alval;
    union Bx
    {
        char buf[16];
        char* ptr;
    } bx;
    unsigned int mysize;
    unsigned int myres;
};
}

struct Elem
{
    Image image;
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > name;
};

struct InputTag
{
};
struct ForwardTag : InputTag
{
};
struct NonscalarTag
{
};
struct RangeTag
{
};
struct UnchangedTag
{
};

template <class T> inline T CheckedBase(T it, UnchangedTag)
{
    return it;
}
template <class T> inline T CheckedBase(T it)
{
    UnchangedTag tag;
    return CheckedBase(it, tag);
}

template <class InIt, class OutIt>
inline OutIt CopyForward(InIt first, InIt last, OutIt dest, ForwardTag, NonscalarTag, RangeTag)
{
    for (; first != last; ++dest, ++first)
        *dest = *first;
    return dest;
}

// @fnv 0x00aaf750
Elem* __cdecl FUN_00aaf750(Elem* _First, Elem* _Last, Elem* _Dest)
{
    Elem* _Result = _Dest + (_Last - _First);
    CopyForward(_First, _Last, CheckedBase(_Dest), ForwardTag(), NonscalarTag(), RangeTag());
    return _Result;
}
}  // namespace fnv_00aaf750

namespace fnv_00aaf9a0 {
extern unsigned int DAT_010173f0;

struct TagIn
{
};
struct TagFwd : TagIn
{
};
struct TagRand : TagFwd
{
};
struct TagNon
{
};
struct TagRange
{
};
struct TagUnchanged
{
};

template <class T> inline T CheckedBase(T& it, TagUnchanged)
{
    return it;
}
template <class T> inline T CheckedBase(T& it)
{
    TagUnchanged tag;
    return CheckedBase(it, tag);
}

namespace std {
template <class E> struct char_traits
{
};
template <class E> class allocator
{
};
template <class E, class Tr, class Ax> class basic_string
{
  public:
    char al;
    union
    {
        char buf[16];
        char* ptr;
    } bx;
    unsigned int mysize;
    unsigned int myres;
    basic_string& assign(const basic_string& right, unsigned int off, unsigned int count)
    {
        int slot0 = 0;
        int slot1 = 1;
        int slot2 = 2;
        int slot3 = 3;
        int slot4 = 4;
        int slot5 = 5;
        int slot6 = 6;
        int slot7 = 7;
        int slot8 = 8;
        int slot9 = 9;
        int slot10 = 10;
        int slot11 = 11;
        int slot12 = 12;
        int slot13 = 13;
        int slot14 = 14;
        int slot15 = 15;
        int slot16 = 16;
        int slot17 = 17;
        int slot18 = 18;
        int slot19 = 19;
        int slot20 = 20;
        slot0 = slot0 + 1;
        slot1 = slot1 + 1;
        slot2 = slot2 + 1;
        slot3 = slot3 + 1;
        slot4 = slot4 + 1;
        slot5 = slot5 + 1;
        slot6 = slot6 + 1;
        slot7 = slot7 + 1;
        slot8 = slot8 + 1;
        slot9 = slot9 + 1;
        slot10 = slot10 + 1;
        slot11 = slot11 + 1;
        slot12 = slot12 + 1;
        slot13 = slot13 + 1;
        slot14 = slot14 + 1;
        slot15 = slot15 + 1;
        slot16 = slot16 + 1;
        slot17 = slot17 + 1;
        slot18 = slot18 + 1;
        slot19 = slot19 + 1;
        slot20 = slot20 + 1;
        return *this;
    }
    basic_string& operator=(const basic_string& right)
    {
        return assign(right, 0, DAT_010173f0);
    }
};
}

struct Matrix
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    Matrix& FUN_006581e0(const Matrix&);
    Matrix& operator=(const Matrix& other)
    {
        return FUN_006581e0(other);
    }
};

struct Elem
{
    Matrix m;
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > s;
};

template <class It> inline It Loop(It first, It last, It dest, TagFwd, TagNon, TagRange)
{
    while (first != last)
        *--dest = *--last;
    return dest;
}

// @fnv 0x00aaf9a0
Elem* __cdecl FUN_00aaf9a0(Elem* first, Elem* last, Elem* dest, TagRand, TagNon, TagRange)
{
    Elem* result = dest - (last - first);
    Loop(first, last, CheckedBase(dest), TagFwd(), TagNon(), TagRange());
    return result;
}
}  // namespace fnv_00aaf9a0

namespace fnv_00ab1800 {
// Attribution: base code reused from "another contributor, 2026-10-24" (ndiff 526 WIP).
// Adapted by zai_worker_01 (GLM (Z.ai)) 2026-10-24: added MemoryManager/DAT_011f6238 declaration.
extern MemoryManager DAT_011f6238;
struct EmptyContainerBase
{
    ~EmptyContainerBase()
    {}
};
struct ProxyAllocator
{
    void deallocate(void* _Ptr, unsigned int _Count)
    {
        DAT_011f6238.Deallocate(_Ptr);
    }
};
struct FUN_0065d6e0_class : EmptyContainerBase
{
    void* storage;
    ProxyAllocator proxy;
    ~FUN_0065d6e0_class()
    {
        proxy.deallocate(storage, 1);
    }
};
struct MiniValue
{
    unsigned short x;
    unsigned short y;
    unsigned short z;
};
struct MiniTag
{
};
inline MiniTag mini_category(MiniValue*&, MiniValue*&)
{
    MiniTag _Cat;
    return _Cat;
}
inline void destroy_mini_one(MiniValue* _Ptr)
{
    _Ptr->~MiniValue();
}
inline void destroy_mini_dispatch(MiniValue* _First, MiniValue* _Last, ProxyAllocator&, MiniTag)
{
    for (; _First != _Last; ++_First)
        destroy_mini_one(_First);
}
inline void FUN_0065f9a0(MiniValue* _First, MiniValue* _Last, ProxyAllocator& _Al)
{
    destroy_mini_dispatch(_First, _Last, _Al, mini_category(_First, _Last));
}
struct ValueBase : FUN_0065d6e0_class
{
    ProxyAllocator allocator;
};
struct SubValue : ValueBase
{
    MiniValue* first;
    MiniValue* last;
    MiniValue* limit;
    void FUN_0065fb10(const SubValue&);
    void FUN_0065eed0(const SubValue*);
    void _Destroy(MiniValue* _First, MiniValue* _Last)
    {
        FUN_0065f9a0(_First, _Last, allocator);
    }
    void FUN_0065f430()
    {
        if (first != 0)
        {
            _Destroy(first, last);
            allocator.deallocate(first, (unsigned int)(limit - first));
        }
        first = 0;
        last = 0;
        limit = 0;
    }
    SubValue(const SubValue&);
    ~SubValue()
    {
        FUN_0065f430();
    }
};
struct SnapshotBase : EmptyContainerBase
{
    void* storage;
    ProxyAllocator proxy;
    ~SnapshotBase();
};

struct SnapshotAllocator : SnapshotBase
{
    ProxyAllocator allocator;
};
struct SnapshotValue : SnapshotAllocator
{
    MiniValue* first;
    MiniValue* last;
    MiniValue* limit;
    void FUN_0065fb10(const SnapshotValue&);
    void FUN_0065eed0(const SnapshotValue*);
    void _Destroy(MiniValue* _First, MiniValue* _Last)
    {
        FUN_0065f9a0(_First, _Last, allocator);
    }
    void FUN_0065f430()
    {
        if (first != 0)
        {
            _Destroy(first, last);
            allocator.deallocate(first, (unsigned int)(limit - first));
        }
        first = 0;
        last = 0;
        limit = 0;
    }
    SnapshotValue(const SubValue&);
    ~SnapshotValue()
    {
        FUN_0065f430();
    }
};

struct SnapshotElement
{
    float scalar;
    SnapshotValue detail;
};

struct VectorElement
{
    float scalar;
    SubValue detail;
    VectorElement& operator=(const VectorElement& _Right)
    {
        scalar = _Right.scalar;
        detail.FUN_0065eed0(&_Right.detail);
        return *this;
    }
};
extern VectorElement* __cdecl FUN_0065e670(unsigned int, unsigned int);
extern VectorElement* __cdecl FUN_00660340(VectorElement*, VectorElement*, VectorElement*, void*);
extern VectorElement* __cdecl DeclaredMoveTail(VectorElement*, VectorElement*, VectorElement*, void*);

inline void __cdecl FUN_0065eb40(VectorElement* _Ptr)
{
    while (_Ptr->detail.last != _Ptr->detail.first)
        destroy_mini_one(--_Ptr->detail.last);
    reinterpret_cast<SnapshotElement*>(_Ptr)->~SnapshotElement();
}
struct ErrorString
{
    unsigned int allocator;
    union
    {
        char small[16];
        char* heap;
    } data;
    unsigned int length;
    unsigned int _Capacity;
    ErrorString(const char*);
    ~ErrorString();
};
struct LengthError
{
    virtual ~LengthError();
    const char* exception_name;
    int owns_name;
    ErrorString message;
    LengthError(const ErrorString&);
};
inline void __cdecl ThrowVectorTooLong()
{
    throw LengthError("vector<T> too long");
}
struct ElementAllocator
{
    unsigned int state;
    void construct(VectorElement*, const VectorElement&);
    void destroy(VectorElement* _Ptr)
    {
        FUN_0065eb40(_Ptr);
    }
};
// Empty category tags model VC9's algorithm dispatch.
struct BaseTag
{
};
inline VectorElement* checked_base_inner(VectorElement*& _It, BaseTag)
{
    return _It;
}
inline VectorElement* checked_base(VectorElement*& _It)
{
    BaseTag _Base_tag;
    return checked_base_inner(_It, _Base_tag);
}
struct RangeTag
{
};
struct PointerTag;
extern void __cdecl FUN_00ab2490(VectorElement*, unsigned int, const VectorElement*, void*, PointerTag, RangeTag);
struct PointerTag
{
};
struct InputTag
{
};
struct ForwardTag : InputTag
{
};
struct BidirectionalTag : ForwardTag
{
};
struct RandomTag : BidirectionalTag
{
};
inline PointerTag ptr_category(VectorElement* const&, VectorElement* const&)
{
    PointerTag _Cat;
    return _Cat;
}
inline RandomTag iter_category(VectorElement* const&, VectorElement* const&)
{
    RandomTag _Cat;
    return _Cat;
}
inline VectorElement* backward_loop(VectorElement* _First, VectorElement* _Last, VectorElement* _Dest, ForwardTag,
                                    PointerTag, RangeTag)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return _Dest;
}
inline VectorElement* __cdecl FUN_00ab2380(VectorElement* _First, VectorElement* _Last, VectorElement* _Dest, RandomTag,
                                           PointerTag, RangeTag)
{
    int _Count = _Last - _First;
    VectorElement* _Result = _Dest - _Count;
    backward_loop(_First, _Last, checked_base(_Dest), ForwardTag(), PointerTag(), RangeTag());
    return _Result;
}

inline VectorElement* move_backward(VectorElement* _First, VectorElement* _Last, VectorElement* _Dest)
{
    return FUN_00ab2380(checked_base(_First), checked_base(_Last), _Dest, iter_category(_First, _Dest),
                        ptr_category(_Dest, _Dest), RangeTag());
}
inline RangeTag checked_category()
{
    return RangeTag();
}
inline VectorElement* copy_dispatch(VectorElement* _First, VectorElement* _Last, VectorElement* _Dest,
                                    ElementAllocator& _Al, PointerTag, RangeTag)
{
    return FUN_00660340(_First, _Last, _Dest, &_Al);
}
inline VectorElement* unchecked_copy(VectorElement* _First, VectorElement* _Last, VectorElement* _Dest,
                                     ElementAllocator& _Al)
{
    return copy_dispatch(checked_base(_First), checked_base(_Last), _Dest, _Al, ptr_category(_First, _Dest),
                         RangeTag());
}
inline void unchecked_fill(VectorElement* _First, unsigned int _Count, const VectorElement& _Val, ElementAllocator& _Al)
{
    FUN_00ab2490(_First, _Count, &_Val, &_Al, ptr_category(_First, _First), RangeTag());
}
inline void destroy_one(VectorElement* _Ptr)
{
    FUN_0065eb40(_Ptr);
}
inline void destroy_dispatch(VectorElement* _First, VectorElement* _Last, ElementAllocator& _Al, PointerTag)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
inline void destroy_range(VectorElement* _First, VectorElement* _Last, ElementAllocator& _Al)
{
    destroy_dispatch(_First, _Last, _Al, ptr_category(_First, _Last));
}
inline void fill_loop(VectorElement* _First, VectorElement* _Last, const VectorElement& _Val)
{
    for (; _First != _Last; ++_First)
        *_First = _Val;
}
inline void fill_range(VectorElement* _First, VectorElement* _Last, const VectorElement& _Val)
{
    fill_loop(checked_base(_First), checked_base(_Last), _Val);
}
struct UndefinedMoveTag
{
};
inline UndefinedMoveTag move_category(VectorElement* const&)
{
    UndefinedMoveTag _Cat;
    return _Cat;
}
inline VectorElement* uninit_copy_leaf(VectorElement* _First, VectorElement* _Last, VectorElement* _Dest,
                                       ElementAllocator& _Al, PointerTag, RangeTag)
{
    VectorElement* _Next = _Dest;
    try
    {
        for (; _First != _Last; ++_Dest, ++_First)
            _Al.construct(_Dest, *_First);
    }
    catch (...)
    {
        for (; _Next != _Dest; ++_Next)
            _Al.destroy(_Next);
        throw;
    }
    return _Dest;
}
inline VectorElement* full_uninit_copy(VectorElement* _First, VectorElement* _Last, VectorElement* _Dest,
                                       ElementAllocator& _Al)
{
    return uninit_copy_leaf(checked_base(_First), checked_base(_Last), _Dest, _Al, ptr_category(_First, _Dest),
                            RangeTag());
}
inline VectorElement* full_move_dispatch(VectorElement* _First, VectorElement* _Last, VectorElement* _Dest,
                                         ElementAllocator& _Al, UndefinedMoveTag, RangeTag)
{
    return full_uninit_copy(_First, _Last, _Dest, _Al);
}
inline VectorElement* __cdecl FUN_0065ff90(VectorElement* _First, VectorElement* _Last, VectorElement* _Dest,
                                           ElementAllocator& _Al)
{

    return full_move_dispatch(checked_base(_First), checked_base(_Last), _Dest, _Al, move_category(_Dest), RangeTag());
}

struct VectorContainer
{
    unsigned int vtable;
    unsigned int status;
    ElementAllocator allocator;
    VectorElement* first;
    VectorElement* last;
    VectorElement* limit;
    unsigned int max_size() const
    {
        unsigned int _Count = 0x9249249;
        return 0 < _Count ? _Count : 1;
    }
    VectorElement* _Ucopy(VectorElement* _First, VectorElement* _Last, VectorElement* _Ptr)
    {
        return unchecked_copy(_First, _Last, _Ptr, allocator);
    }
    void _Destroy(VectorElement* _First, VectorElement* _Last)
    {
        destroy_range(_First, _Last, allocator);
    }
    void deallocate(VectorElement* _Ptr, unsigned int _Count)
    {
        DAT_011f6238.Deallocate(_Ptr);
    }
    VectorElement* _Umove(VectorElement* _First, VectorElement* _Last, VectorElement* _Ptr)
    {
        return FUN_0065ff90(_First, _Last, _Ptr, allocator);
    }
    VectorElement* _Ufill(VectorElement* _Ptr, unsigned int _Count, const VectorElement& _Val)
    {
        unchecked_fill(_Ptr, _Count, _Val, allocator);
        return _Ptr + _Count;
    }
    VectorElement* _UmoveDeclared(VectorElement* _First, VectorElement* _Last, VectorElement* _Ptr)
    {
        return DeclaredMoveTail(_First, _Last, _Ptr, &allocator);
    }
    void FUN_00ab1800(unsigned int, VectorElement*, unsigned int, const VectorElement*);
};
// @fnv 0x00ab1800
void VectorContainer::FUN_00ab1800(unsigned int reserved, VectorElement* where, unsigned int count,
                                   const VectorElement* value)
{
    unsigned int _Capacity = first == 0 ? 0 : (unsigned int)(limit - first);
    if (count == 0)
        ;
    else
    {
        if (max_size() - (unsigned int)(last - first) < count)
            ThrowVectorTooLong();
        else if (_Capacity < (unsigned int)(last - first) + count)
        {
            _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
            if (_Capacity < (unsigned int)(last - first) + count)
                _Capacity = (unsigned int)(last - first) + count;
            VectorElement* _Newvec = FUN_0065e670(_Capacity, 0);
            VectorElement* _Ptr = _Newvec;
            try
            {
                _Ptr = _Ucopy(first, where, _Newvec);
                _Ufill(_Ptr, count, *value);
                _Ptr += count;
                _UmoveDeclared(where, last, _Ptr);
            }
            catch (...)
            {
                destroy_range(_Newvec, _Ptr, allocator);
                DAT_011f6238.Deallocate(_Newvec);
                throw;
            }
            count += (unsigned int)(last - first);
            if (first != 0)
            {
                _Destroy(first, last);
                deallocate(first, (unsigned int)(limit - first));
            }
            limit = _Newvec + _Capacity;
            last = _Newvec + count;
            first = _Newvec;
        }
        else if ((unsigned int)(last - where) < count)
        {
            SnapshotElement _Tmp = {value->scalar, value->detail};
            _Ucopy(where, last, where + count);
            try
            {
                _Ufill(last, count - (unsigned int)(last - where), reinterpret_cast<const VectorElement&>(_Tmp));
            }
            catch (...)
            {
                _Destroy(where + count, last + count);
                throw;
            }
            last += count;
            fill_range(where, last - count, reinterpret_cast<const VectorElement&>(_Tmp));
        }
        else
        {
            VectorElement _Tmp = {value->scalar, value->detail};
            VectorElement* _Oldend = last;
            last = _Umove(_Oldend - count, _Oldend, last);
            move_backward(where, _Oldend - count, _Oldend);
            fill_range(where, where + count, _Tmp);
        }
    }
}
}  // namespace fnv_00ab1800

namespace fnv_00ab2580 {
struct Sub_0065eed0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void FUN_0065eed0(const Sub_0065eed0* other)
    {
        int l0, l1, l2, l3, l4, l5, l6, l7, l8, l9;
        int l10, l11, l12, l13, l14, l15, l16, l17, l18, l19;
        int l20, l21, l22, l23, l24, l25, l26, l27, l28, l29;
        int l30, l31, l32, l33, l34, l35, l36, l37, l38, l39;
        int l40, l41, l42, l43, l44, l45, l46, l47, l48, l49;
        int l50, l51, l52, l53, l54, l55, l56, l57, l58, l59;
        int l60, l61, l62, l63, l64, l65, l66, l67, l68, l69;
        int l70, l71, l72, l73, l74, l75, l76, l77, l78, l79;
        int l80, l81, l82, l83, l84, l85;
        l0 = l1;
        l1 = l2;
        l2 = l3;
        l3 = l4;
        l4 = l5;
        l5 = l6;
        l6 = l7;
        l7 = l8;
        l8 = l9;
        l9 = l10;
        l10 = l11;
        l11 = l12;
        l12 = l13;
        l13 = l14;
        l14 = l15;
        l15 = l16;
        l16 = l17;
        l17 = l18;
        l18 = l19;
        l19 = l20;
        l20 = l21;
        l21 = l22;
        l22 = l23;
        l23 = l24;
        l24 = l25;
        l25 = l26;
        l26 = l27;
        l27 = l28;
        l28 = l29;
        l29 = l30;
        l30 = l31;
        l31 = l32;
        l32 = l33;
        l33 = l34;
        l34 = l35;
        l35 = l36;
        l36 = l37;
        l37 = l38;
        l38 = l39;
        l39 = l40;
        l40 = l41;
        l41 = l42;
        l42 = l43;
        l43 = l44;
        l44 = l45;
        l45 = l46;
        l46 = l47;
        l47 = l48;
        l48 = l49;
        l49 = l50;
        l50 = l51;
        l51 = l52;
        l52 = l53;
        l53 = l54;
        l54 = l55;
        l55 = l56;
        l56 = l57;
        l57 = l58;
        l58 = l59;
        l59 = l60;
        l60 = l61;
        l61 = l62;
        l62 = l63;
        l63 = l64;
        l64 = l65;
        l65 = l66;
        l66 = l67;
        l67 = l68;
        l68 = l69;
        l69 = l70;
        l70 = l71;
        l71 = l72;
        l72 = l73;
        l73 = l74;
        l74 = l75;
        l75 = l76;
        l76 = l77;
        l77 = l78;
        l78 = l79;
        l79 = l80;
        l80 = l81;
        l81 = l82;
        l82 = l83;
        l83 = l84;
        l84 = l85;
        l85 = unk00;
        if (this != other)
            unk00 = other->unk00;
    }
};

struct EgmElem
{
    float unk00;
    Sub_0065eed0 unk04;
    EgmElem& operator=(const EgmElem& other)
    {
        unk00 = other.unk00;
        unk04.FUN_0065eed0(&other.unk04);
        return *this;
    }
};

struct FnvInputTag
{
};
struct FnvForwardTag : FnvInputTag
{
};
struct FnvNonscalarTag
{
};
struct FnvRangeTag
{
};
struct FnvUnchangedTag
{
};

template <class T> inline T CheckedBase(T& it, FnvUnchangedTag)
{
    return it;
}

template <class T> inline T CheckedBase(T& it)
{
    FnvUnchangedTag tag;
    return CheckedBase(it, tag);
}

template <class A, class B, class Cat, class Scalar, class Range>
inline B CopyBackward(A first, A last, B dest, Cat, Scalar, Range)
{
    while (first != last)
        *--dest = *--last;
    return dest;
}

// @fnv 0x00ab2580
EgmElem* __cdecl FUN_00ab2580(EgmElem* first, EgmElem* last, EgmElem* dest)
{
    EgmElem* result = dest - (last - first);
    CopyBackward(first, last, CheckedBase(dest), FnvForwardTag(), FnvNonscalarTag(), FnvRangeTag());
    return result;
}
}  // namespace fnv_00ab2580

namespace fnv_00ab4520 {
struct CopyTag
{
};
struct RangeTag
{
};
struct RandomTag
{
};
struct ForwardTag
{
};
template <class T> __forceinline T CheckedBase(T _It)
{
    return _It;
}
template <class T> __forceinline CopyTag PtrCat(T&, T&)
{
    CopyTag _Cat;
    return _Cat;
}
template <class T> __forceinline RandomTag IterRandom(T&, T&)
{
    RandomTag _Cat;
    return _Cat;
}
struct S_0065eb90
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54;
    void FUN_0065eb90(int);
};
inline void S_0065eb90::FUN_0065eb90(int src)
{
    int u00, u01, u02, u03, u04, u05, u06, u07, u08, u09, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21,
        u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34, u35, u36, u37, u38, u39, u40, u41, u42, u43,
        u44, u45, u46, u47, u48, u49, u50, u51, u52, u53, u54, u55, u56, u57, u58, u59, u60, u61, u62, u63, u64, u65,
        u66, u67, u68, u69, u70, u71, u72, u73, u74;
    int i;
    u00 = u00;
    u01 = u01;
    u02 = u02;
    u03 = u03;
    u04 = u04;
    u05 = u05;
    u06 = u06;
    u07 = u07;
    u08 = u08;
    u09 = u09;
    u10 = u10;
    u11 = u11;
    u12 = u12;
    u13 = u13;
    u14 = u14;
    u15 = u15;
    u16 = u16;
    u17 = u17;
    u18 = u18;
    u19 = u19;
    u20 = u20;
    u21 = u21;
    u22 = u22;
    u23 = u23;
    u24 = u24;
    u25 = u25;
    u26 = u26;
    u27 = u27;
    u28 = u28;
    u29 = u29;
    u30 = u30;
    u31 = u31;
    u32 = u32;
    u33 = u33;
    u34 = u34;
    u35 = u35;
    u36 = u36;
    u37 = u37;
    u38 = u38;
    u39 = u39;
    for (i = 0; i < 3; ++i)
        unk00 = src + i;
    unk04 = u00;
    unk08 = u01;
    unk0c = u02;
}
__forceinline S_0065eb90* BackwardLoop(S_0065eb90* _First, S_0065eb90* _Last, S_0065eb90* _Dest, ForwardTag, CopyTag,
                                       RangeTag)
{
    while (_First != _Last)
    {
        --_Last;
        --_Dest;
        _Dest->FUN_0065eb90((int)_Last);
    }
    return _Dest;
}
__forceinline S_0065eb90* BackwardOpt(S_0065eb90* _First, S_0065eb90* _Last, S_0065eb90* _Dest, CopyTag _Cat, RangeTag)
{
    S_0065eb90* _Result = _Dest - (_Last - _First);
    BackwardLoop(_First, _Last, CheckedBase(_Dest), ForwardTag(), _Cat, RangeTag());
    return _Result;
}
// @fnv 0x00ab4520
S_0065eb90* __cdecl FUN_00ab4520(S_0065eb90* _First, S_0065eb90* _Last, S_0065eb90* _Dest, RandomTag, CopyTag, RangeTag)
{
    return BackwardOpt(_First, _Last, _Dest, PtrCat(_First, _Dest), RangeTag());
}
}  // namespace fnv_00ab4520

namespace fnv_00ab5ec0 {
extern unsigned int DAT_010173f0;
void __cdecl FUN_00ec7c56();
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
void __cdecl operator delete(void*);
template <class T> struct StdAllocator
{
    StdAllocator() throw()
    {}
    StdAllocator(const StdAllocator<T>&) throw()
    {}
    template <class U> StdAllocator(const StdAllocator<U>&) throw()
    {}
    void deallocate(T* pointer, unsigned int)
    {
        operator delete(pointer);
    }
    unsigned int max_size() const throw()
    {
        unsigned int count = (unsigned int)(-1) / sizeof(T);
        return 0 < count ? count : 1;
    }
};
struct CharTraits
{
    static unsigned int length(const char* text)
    {
        return strlen(text);
    }
    static char* copy_s(char* destination, unsigned int, const char* source, unsigned int count)
    {
        return (char*)memcpy(destination, source, count);
    }
    static void assign(char& left, const char& right)
    {
        left = right;
    }
};
struct ContainerBaseSecure
{
};
struct StringBase : ContainerBaseSecure
{
    static void Xlen();
    static void Xran();
};
struct StringValue : StringBase
{
    StringValue(StdAllocator<char> allocator = StdAllocator<char>()) : allocator(allocator)
    {}
    StringValue(const StringValue& source) : allocator(source.allocator)
    {}
    StdAllocator<char> allocator;
};
struct TriString : StringValue
{
    union
    {
        char small[16];
        char* heap;
    } storage;
    unsigned int length, capacity;
    TriString() : StringValue()
    {
        FUN_0044a730();
    }
    TriString(const char* text) : StringValue()
    {
        FUN_0044a730();
        assign(text);
    }
    TriString(const TriString& source) : StringValue(source)
    {
        FUN_0044a730();
        AssignSubstring(source, 0, DAT_010173f0);
    }
    ~TriString()
    {
        FUN_0044a730(true);
    }
    TriString& operator=(const TriString& source)
    {
        return assign(source);
    }
    TriString& assign(const TriString& source)
    {
        return AssignSubstring(source, 0, DAT_010173f0);
    }
    TriString& AssignSubstring(const TriString& source, unsigned int offset, unsigned int count);
    TriString& assign(const char* text, unsigned int count)
    {
        if (inside(text))
            return AssignSubstring(*this, text - pointer(), count);
        if (grow(count))
        {
            CharTraits::copy_s(pointer(), capacity, text, count);
            terminate(count);
        }
        return *this;
    }
    TriString& assign(const char* text)
    {
        return assign(text, CharTraits::length(text));
    }
    char& operator[](unsigned int offset)
    {
        if (!(offset <= length))
            FUN_00ec7c56();
        return pointer()[offset];
    }
    void resize(unsigned int count)
    {
        FUN_00aba370(count, char());
    }
    void FUN_00aba370(unsigned int count, char value);
    unsigned int max_size() const
    {
        unsigned int count = allocator.max_size();
        return count <= 1 ? 1 : count - 1;
    }
    void FUN_0044a6f0(unsigned int count, unsigned int oldLength);
    void terminate(unsigned int count)
    {
        CharTraits::assign(pointer()[length = count], char());
    }
    bool grow(unsigned int count, bool trim = false)
    {
        if (max_size() < count)
            StringBase::Xlen();
        if (capacity < count)
            FUN_0044a6f0(count, length);
        else if (trim && count < 16)
            FUN_0044a730(true, count < length ? count : length);
        else if (count == 0)
            terminate(0);
        return 0 < count;
    }
    bool inside(const char* text)
    {
        if (text == 0 || text < pointer() || pointer() + length <= text)
            return false;
        else
            return true;
    }
    void FUN_0044a730(bool built = false, unsigned int count = 0);
    char* pointer()
    {
        return 16 <= capacity ? storage.heap : storage.small;
    }
};
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
struct TriHeader
{
    unsigned int vertices, triangles, quads, materials, shapes, texcoords;
    unsigned int flags, morphs, partitions, extraVertices;
    unsigned char reserved[16];
    void FUN_00ab46e0();
};
struct Point3
{
    float x, y, z;
    Point3() : x(0), y(0), z(0)
    {}
    Point3(float a, float b, float c) : x(a), y(b), z(c)
    {}
};
struct ShortPoint
{
    short x, y, z;
};
struct TriIndex
{
    unsigned int x, y, z;
    TriIndex() : x(0), y(0), z(0)
    {}
};
struct QuadIndex
{
    unsigned int x, y, z, w;
    QuadIndex() : x(0), y(0), z(0), w(0)
    {}
};
struct TexCoord
{
    float x, y;
    TexCoord() : x(0), y(0)
    {}
    TexCoord(const TexCoord& other) : x(other.x), y(other.y)
    {}
};
struct FUN_00aaaa80
{
    virtual ~FUN_00aaaa80();
    TriString filename;
    TriString signature;
    unsigned int unk3c;
};
struct FUN_00ac5490 : FUN_00aaaa80
{
    unsigned int unk40, unk44;
    FUN_00ac5490(TriString);
    virtual ~FUN_00ac5490()
    {
        ClearHolders();
    }
    void ClearHolders();
    bool FUN_00ac5540(TriString, int);
    bool FUN_00ac5e00(void*, unsigned int, unsigned int);
    bool FUN_00ac5cf0(void*, unsigned int, unsigned int);
    template <class T> bool read(T& value)
    {
        return FUN_00ac5cf0(&value, sizeof(T), 1);
    }
};
struct IteratorAuxiliary;
template <class T> struct CheckedBuffer;
struct IteratorOwner
{
    const IteratorAuxiliary* owner;
    IteratorOwner() : owner(0)
    {}
};
template <class T> struct ConstIterator : IteratorOwner
{
    T* current;
    ConstIterator(T* pointer, const CheckedBuffer<T>* container)
    {
        if (container == 0 || container->first > pointer || pointer > container->last)
            FUN_00ec7c56();
        owner = container->auxiliary;
        current = pointer;
    }
};
template <class T> struct CheckedIterator : ConstIterator<T>
{
    CheckedIterator(T* pointer, const CheckedBuffer<T>* container) : ConstIterator<T>(pointer, container)
    {}
};
template <class T> struct CheckedBuffer
{
    const IteratorAuxiliary* auxiliary;
    unsigned int auxAllocator, allocator;
    T* first;
    T* last;
    T* limit;
    CheckedIterator<T> begin()
    {
        return CheckedIterator<T>(first, this);
    }
    CheckedIterator<T> end()
    {
        return CheckedIterator<T>(last, this);
    }
    unsigned int size() const
    {
        return last - first;
    }
    T& operator[](unsigned int index)
    {
        if (index >= (unsigned int)(last - first))
            FUN_00ec7c56();
        return first[index];
    }
};
struct PointBuffer : CheckedBuffer<Point3>
{
    void FUN_00aba7b0(unsigned int, Point3);
    void resize(unsigned int count)
    {
        FUN_00aba7b0(count, Point3());
    }
};
struct IndexBuffer : CheckedBuffer<TriIndex>
{
    void FUN_00aba7b0(unsigned int, TriIndex);
    void resize(unsigned int count)
    {
        FUN_00aba7b0(count, TriIndex());
    }
    CheckedIterator<TriIndex> FUN_00aba9a0(ConstIterator<TriIndex>, ConstIterator<TriIndex>);
    void FUN_00ab9cd0()
    {
        FUN_00aba9a0(begin(), end());
    }
};
struct QuadBuffer : CheckedBuffer<QuadIndex>
{
    void FUN_00abaaa0(unsigned int, QuadIndex);
    void resize(unsigned int count)
    {
        FUN_00abaaa0(count, QuadIndex());
    }
    CheckedIterator<QuadIndex> FUN_00abac80(ConstIterator<QuadIndex>, ConstIterator<QuadIndex>);
    void FUN_00ab9dc0()
    {
        FUN_00abac80(begin(), end());
    }
};
struct TexBuffer : CheckedBuffer<TexCoord>
{
    void FUN_00abad80(unsigned int, TexCoord);
    void resize(unsigned int count)
    {
        FUN_00abad80(count, TexCoord());
    }
};
struct Material
{
    unsigned int id;
    TriString name;
};
struct MaterialBuffer : CheckedBuffer<Material>
{
    void FUN_00ab9eb0(unsigned int count)
    {
        FUN_00abb060(count, Material());
    }
    void FUN_00abb060(unsigned int count, Material value);
};
struct FUN_00aba220
{
    unsigned int id;
    Point3 position;
    TriString name;
    FUN_00aba220();
};
typedef FUN_00aba220 Shape;
struct ShapeBuffer : CheckedBuffer<Shape>
{
    void FUN_00abb3c0(unsigned int, Shape);
    void resize(unsigned int count)
    {
        FUN_00abb3c0(count, Shape());
    }
};
struct FUN_00aba270
{
    TriString name;
    PointBuffer points;
    FUN_00aba270();
};
typedef FUN_00aba270 Morph;
struct MorphBuffer : CheckedBuffer<Morph>
{
    void FUN_00abb700(unsigned int, Morph);
    void resize(unsigned int count)
    {
        FUN_00abb700(count, Morph());
    }
};
struct UIntBuffer : CheckedBuffer<unsigned int>
{
    void FUN_00aba5d0(unsigned int, unsigned char);
    void resize(unsigned int count)
    {
        FUN_00aba5d0(count, 0);
    }
};
struct FUN_00aba2f0
{
    TriString name;
    unsigned int firstVertex;
    UIntBuffer indices;
    FUN_00aba2f0();
};
typedef FUN_00aba2f0 Partition;
struct PartitionBuffer : CheckedBuffer<Partition>
{
    void FUN_00abbae0(unsigned int, Partition);
    void resize(unsigned int count)
    {
        FUN_00abbae0(count, Partition());
    }
};
struct Geometry
{
    PointBuffer vertices;
    IndexBuffer triangles;
    QuadBuffer quads;
    TexBuffer texcoords;
    IndexBuffer textureTriangles;
    QuadBuffer textureQuads;
    MaterialBuffer materials;
    ShapeBuffer shapes;
    MorphBuffer morphs;
    PartitionBuffer partitions;
};
struct ContainerAux;
void* __cdecl FUN_0044d670(int, int);
struct Aux
{
    const ContainerAux* container;
};
struct ContainerAux
{
    Aux* proxy;
    ~ContainerAux()
    {}
};
inline void GameDelete(void* p)
{
    DAT_011f6238.Deallocate(p);
}
template <class T> struct GameAllocator
{
    GameAllocator()
    {}
    template <class U> GameAllocator(const GameAllocator<U>&)
    {}
    void deallocate(T* p, unsigned int)
    {
        GameDelete(p);
    }
};
template <class T> struct ProxyBase : ContainerAux
{
    GameAllocator<Aux> auxAllocator;
    ~ProxyBase()
    {
        proxy->~Aux();
        auxAllocator.deallocate(proxy, 1);
    }
};
template <class T> struct VectorVal : ProxyBase<T>
{
    GameAllocator<T> allocator;
};
struct ScalarTag
{
};
template <class T> inline ScalarTag PointerCategory(T*&, T*&)
{
    ScalarTag tag;
    return tag;
}
template <class T> inline void DestroyRange(T*, T*, GameAllocator<T>&, ScalarTag)
{}
template <class T> inline void DestroyRange(T* first, T* last, GameAllocator<T>& allocator)
{
    DestroyRange(first, last, allocator, PointerCategory(first, last));
}
struct FUN_00aba0d0 : VectorVal<char>
{
    char* first;
    char* last;
    char* limit;
    void FUN_00abbfc0(unsigned int, const char&);
    FUN_00aba0d0(unsigned int count)
    {
        void* space = FUN_0044d670(1, 0);
        Aux* node = (Aux*)space;
        if (node != 0)
            node->container = this;
        proxy = node;
        FUN_00abbfc0(count, char());
    }
    void Destroy(char* begin, char* finish)
    {
        DestroyRange(begin, finish, allocator);
    }
    void FUN_00abc0a0()
    {
        if (first != 0)
        {
            Destroy(first, last);
            allocator.deallocate(first, limit - first);
        }
        first = 0, last = 0, limit = 0;
    }
    ~FUN_00aba0d0()
    {
        FUN_00abc0a0();
    }
    char& operator[](unsigned int index)
    {
        if (index >= (unsigned int)(last - first))
            FUN_00ec7c56();
        return first[index];
    }
};
void __cdecl FUN_00ac6430(int, TriString);
// @fnv 0x00ab5ec0
bool __cdecl FUN_00ab5ec0(const TriString& filename, Geometry* geometry)
{
    TriHeader triHeader;
    fnv_zlib_memset(&triHeader, 0, 56);
    FUN_00ac5490 reader("FRTRI003");
    if (!reader.FUN_00ac5540(filename, 0))
        return false;
    if (!reader.FUN_00ac5e00(&triHeader, 1, 56))
        return false;
    triHeader.FUN_00ab46e0();
    geometry->vertices.resize(triHeader.vertices + triHeader.extraVertices);
    geometry->triangles.resize(triHeader.triangles);
    geometry->quads.resize(triHeader.quads);
    geometry->materials.FUN_00ab9eb0(triHeader.materials);
    geometry->shapes.resize(triHeader.shapes);
    geometry->morphs.resize(triHeader.morphs);
    geometry->partitions.resize(triHeader.partitions);
    if (triHeader.vertices + triHeader.extraVertices &&
        !reader.FUN_00ac5cf0(&geometry->vertices[0], 12, triHeader.vertices + triHeader.extraVertices))
        return false;
    if (triHeader.triangles && !reader.FUN_00ac5cf0(&geometry->triangles[0], 12, triHeader.triangles))
        return false;
    if (triHeader.quads && !reader.FUN_00ac5cf0(&geometry->quads[0], 16, triHeader.quads))
        return false;
    unsigned int item;
    unsigned int accumulated;
    for (item = 0; item < triHeader.materials; item++)
    {
        if (!reader.read(geometry->materials[item].id))
            return false;
        unsigned int materialLength;
        if (!reader.read(materialLength))
            return false;
        if (materialLength)
        {
            FUN_00aba0d0 materialBytes(materialLength);
            if (!reader.FUN_00ac5cf0(&materialBytes[0], 1, materialLength))
                return false;
            if (materialLength > 1)
            {
                geometry->materials[item].name.resize(materialLength - 1);
                unsigned int materialChar;
                for (materialChar = 0; materialChar < materialLength - 1; materialChar++)
                    ;
                geometry->materials[item].name[materialChar] = materialBytes[materialChar];
            }
            else
                geometry->materials[item].name = TriString("");
        }
    }
    for (item = 0; item < triHeader.shapes; item++)
    {
        if (!reader.read(geometry->shapes[item].id))
            return false;
        if (!reader.read(geometry->shapes[item].position))
            return false;
        unsigned int shapeLength;
        if (!reader.read(shapeLength))
            return false;
        if (shapeLength)
        {
            FUN_00aba0d0 shapeBytes(shapeLength);
            if (!reader.FUN_00ac5cf0(&shapeBytes[0], 1, shapeLength))
                return false;
            if (shapeLength > 1)
            {
                geometry->shapes[item].name.resize(shapeLength - 1);
                unsigned int shapeChar;
                for (shapeChar = 0; shapeChar < shapeLength - 1; shapeChar++)
                    ;
                geometry->shapes[item].name[shapeChar] = shapeBytes[shapeChar];
            }
            else
                geometry->shapes[item].name = TriString("");
        }
    }
    if (triHeader.flags & 1)
    {
        if (!triHeader.texcoords)
        {
            geometry->texcoords.resize(triHeader.vertices);
            if (triHeader.vertices && !reader.FUN_00ac5cf0(&geometry->texcoords[0], 8, triHeader.vertices))
                return false;
            geometry->textureTriangles.FUN_00ab9cd0();
            geometry->textureQuads.FUN_00ab9dc0();
        }
        else
        {
            geometry->texcoords.resize(triHeader.texcoords);
            if (triHeader.texcoords && !reader.FUN_00ac5cf0(&geometry->texcoords[0], 8, triHeader.texcoords))
                return false;
            geometry->textureTriangles.resize(triHeader.triangles);
            if (triHeader.triangles && !reader.FUN_00ac5cf0(&geometry->textureTriangles[0], 12, triHeader.triangles))
                return false;
            geometry->textureQuads.resize(triHeader.quads);
            if (triHeader.quads && !reader.FUN_00ac5cf0(&geometry->textureQuads[0], 16, triHeader.quads))
                return false;
        }
    }
    for (item = 0; item < triHeader.morphs; item++)
    {
        unsigned int morphLength;
        if (!reader.read(morphLength))
            return false;
        if (morphLength)
        {
            FUN_00aba0d0 morphBytes(morphLength);
            if (!reader.FUN_00ac5cf0(&morphBytes[0], 1, morphLength))
                return false;
            if (morphLength > 1)
            {
                geometry->morphs[item].name.resize(morphLength - 1);
                for (unsigned int morphChar = 0; morphChar < morphLength - 1; morphChar++)
                    geometry->morphs[item].name[morphChar] = morphBytes[morphChar];
            }
            else
                geometry->morphs[item].name = TriString("");
        }
        float morphScale;
        if (!reader.read(morphScale))
            return false;
        geometry->morphs[item].points.resize(triHeader.vertices);
        for (unsigned int vertex = 0; vertex < triHeader.vertices; vertex++)
        {
            ShortPoint displacement;
            if (!reader.FUN_00ac5cf0(&displacement, 2, 3))
                return false;
            geometry->morphs[item].points[vertex] =
                Point3(displacement.x * morphScale, displacement.y * morphScale, displacement.z * morphScale);
        }
    }
    accumulated = triHeader.vertices;
    for (item = 0; item < triHeader.partitions; item++)
    {
        unsigned int partitionCount;
        if (!reader.read(partitionCount))
            return false;
        if (partitionCount)
        {
            FUN_00aba0d0 partitionBytes(partitionCount);
            if (!reader.FUN_00ac5cf0(&partitionBytes[0], 1, partitionCount))
                return false;
            if (partitionCount > 1)
            {
                geometry->partitions[item].name.resize(partitionCount - 1);
                for (unsigned int partitionChar = 0; partitionChar < partitionCount - 1; partitionChar++)
                    geometry->partitions[item].name[partitionChar] = partitionBytes[partitionChar];
            }
            else
                geometry->partitions[item].name = TriString("");
        }
        geometry->partitions[item].firstVertex = accumulated;
        if (!reader.read(partitionCount))
            return false;
        geometry->partitions[item].indices.resize(partitionCount);
        if (partitionCount && !reader.FUN_00ac5cf0(&geometry->partitions[item].indices[0], 4, partitionCount))
            return false;
        accumulated += partitionCount;
    }
    if (accumulated != triHeader.vertices + triHeader.extraVertices)
    {
        FUN_00ac6430(1, filename);
        return false;
    }
    return true;
}
}  // namespace fnv_00ab5ec0

// @fnv 0x00ab22e0
ShortPoint* __cdecl FUN_00ab22e0(ShortPoint* _First, ShortPoint* _Last, ShortPoint* _Dest)
{
    return BackwardOpt(_First, _Last, _Dest, PtrCat(_First, _Dest), RangeTag());
}

void ReportAssertionViolation(const char*, int);
struct CleanupBaseV7
{
    __forceinline ~CleanupBaseV7()
    {}
};
struct ImageAllocationV7
{
    void* data;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
};
struct HeapBlockV7 : CleanupBaseV7
{
    void* data;
    int unk04;
    __forceinline ~HeapBlockV7()
    {
        ImageAllocationV7 block;
        block.data = data;
        DAT_011f6238.Deallocate(block.data);
    }
};
struct StorageV7 : HeapBlockV7
{
    __forceinline ~StorageV7()
    {}
};
void FUN_00ec7c56();
struct ImageDataV7 : StorageV7
{
    int unk08;
    float* first;
    float* last;
    float* limit;
    unsigned int rows, cols;
    unsigned int size() const
    {
        return last - first;
    }
    float& FUN_006578b0(unsigned int pos) const
    {
        {
            if (!(pos < size()))
            {
                {
                    FUN_00ec7c56();
                }
            }
        }
        return first[pos];
    }
    void FUN_0065f240();
    __forceinline ~ImageDataV7()
    {
        FUN_0065f240();
    }
};
struct RowView
{
    float* pData;
    unsigned int len;
    RowView(float* p, unsigned int n) : pData(p), len(n)
    {}
    float& operator[](unsigned int index)
    {
        return pData[index];
    }
};
struct ImageV7 : ImageDataV7
{
    __forceinline ~ImageV7()
    {}
    RowView FUN_0060b370(int index)
    {
        return RowView(&FUN_006578b0(0) + index * cols, cols);
    }
};
struct ImagePairV7
{
    ImageV7 images[2];
};
struct ControlSetV7
{
    ImageV7 images[5];
};
struct MatrixEntry
{
    ImageV7 image;
    int unk20;
    float bias;
    ImageV7 FUN_00658360(const ImagePairV7*);
};
struct FanControlsV7
{
    bool enabled;
    ControlSetV7 controls[5];
    MatrixEntry entries[5][2][2];
    float FUN_00aabdb0(int a1, int a2, int a3, const ImagePairV7* a4);
};
// @fnv 0x00aabdb0
float FanControlsV7::FUN_00aabdb0(int a1, int a2, int a3, const ImagePairV7* a4)
{
    if (a1 < 5)
    {
    }
    else
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\FanControls.cpp", 0xc6);
    if (a2 < 2)
    {
    }
    else
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\FanControls.cpp", 0xc7);
    if (a3 < 2)
    {
    }
    else
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\FanControls.cpp", 0xc8);
    if (!enabled)
        return 0.0f;
    float val = 0.0f;
    val = entries[a1][a2][a3].FUN_00658360(&a4[a3]).FUN_0060b370(0)[0];
    val += entries[a1][a2][a3].bias;
    return val;
}

template <class T> inline T* Allocate(unsigned int count, T*)
{
    return (T*)FUN_0044d670(count, 0);
}

template <class T> struct Allocator
{
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef unsigned int size_type;
    typedef int difference_type;
    template <class U> struct rebind
    {
        typedef Allocator<U> other;
    };
    Allocator()
    {}
    Allocator(const Allocator&)
    {}
    template <class U> Allocator(const Allocator<U>&)
    {}
    pointer allocate(size_type count)
    {
        return Allocate(count, (pointer)0);
    }
    void deallocate(pointer ptr, size_type)
    {
        DAT_011f6238.Deallocate(ptr);
    }
};

struct ContainerBaseAux;
struct AuxCont
{
    explicit AuxCont(const ContainerBaseAux* const cont) : mycontainer(cont)
    {}
    const ContainerBaseAux* mycontainer;
};
struct ContainerBaseAux
{
    ContainerBaseAux()
    {}
    ~ContainerBaseAux()
    {}
    AuxCont* myownedaux;
};

template <class A> struct ContainerBaseAuxAlloc : ContainerBaseAux
{
    explicit ContainerBaseAuxAlloc(A al) : alaux(al)
    {
        myownedaux = new (alaux.allocate(1)) AuxCont(this);
    }
    ~ContainerBaseAuxAlloc()
    {
        myownedaux->~AuxCont();
        alaux.deallocate(myownedaux, 1);
    }
    typename A::template rebind<AuxCont>::other alaux;
};

template <class T, class A> struct VectorVal_aba4f0 : ContainerBaseAuxAlloc<A>
{
    VectorVal_aba4f0(A al = A()) : ContainerBaseAuxAlloc<A>(al), alval(al)
    {}
    typename A::template rebind<T>::other alval;
};

struct WordSecureCharTag
{
};
inline WordSecureCharTag wordCharCategory()
{
    WordSecureCharTag category;
    return category;
}
inline char* wordCopy(char* destination, unsigned int size, const char* source, unsigned int count, WordSecureCharTag)
{
    FUN_00ec7ce3(destination, size, source, count);
    return destination;
}
inline char* wordCopy(char* destination, unsigned int size, const char* source, unsigned int count)
{
    return wordCopy(destination, size, source, count, wordCharCategory());
}
struct WordStringBase
{
};
struct WordStringValue : WordStringBase
{
    WordStringValue(StdAllocator<char> value = StdAllocator<char>()) : allocator(value)
    {}
    StdAllocator<char> allocator;
};
struct WordErrorText : WordStringValue
{
    union
    {
        char small[16];
        char* heap;
    } storage;
    unsigned int length;
    unsigned int capacity;
    WordErrorText(const char* text) : WordStringValue()
    {
        tidy();
        assign(text);
    }
    ~WordErrorText()
    {
        tidy(true);
    }
    char* pointer()
    {
        return 16 <= capacity ? storage.heap : storage.small;
    }
    void terminate(unsigned int count)
    {
        CharTraits::assign(pointer()[length = count], char());
    }
    unsigned int max_size() const
    {
        unsigned int count = allocator.max_size();
        return count <= 1 ? 1 : count - 1;
    }
    void copy(unsigned int count, unsigned int oldLength);
    static void tooLong();
    WordErrorText& assign(const WordErrorText&, unsigned int, unsigned int);
    bool inside(const char* text)
    {
        if (text == 0 || text < pointer() || pointer() + length <= text)
            return false;
        else
            return true;
    }
    bool grow(unsigned int count, bool trim = false)
    {
        if (max_size() < count)
            tooLong();
        if (capacity < count)
            copy(count, length);
        else if (trim && count < 16)
            tidy(true, count < length ? count : length);
        else if (count == 0)
            terminate(0);
        return 0 < count;
    }
    void tidy(bool built = false, unsigned int count = 0)
    {
        if (!built)
        {
        }
        else if (16 <= capacity)
        {
            char* old = storage.heap;
            if (0 < count)
                wordCopy(storage.small, 16, old, count);
            allocator.deallocate(old, capacity + 1);
        }
        capacity = 15;
        terminate(count);
    }
    WordErrorText& assign(const char* text, unsigned int count)
    {
        if (inside(text))
            return assign(*this, text - pointer(), count);
        if (grow(count))
        {
            wordCopy(pointer(), capacity, text, count);
            terminate(count);
        }
        return *this;
    }
    WordErrorText& assign(const char* text)
    {
        return assign(text, CharTraits::length(text));
    }
};
struct WordLogicException
{
    virtual ~WordLogicException() throw();
    const char* message;
    bool ownsMessage;
    WordErrorText text;
    WordLogicException(const WordErrorText&);
};
struct WordLengthException : WordLogicException
{
    explicit WordLengthException(const WordErrorText& value) : WordLogicException(value)
    {}
    virtual ~WordLengthException() throw()
    {}
};
inline void wordThrowLength()
{
    throw WordLengthException(WordErrorText("vector<T> too long"));
}

struct WordAllocationFailure : AllocationExceptionBase
{
    WordAllocationFailure(const char* message) throw() : AllocationExceptionBase(message)
    {}
};
inline unsigned int* __cdecl FUN_00ac1720(unsigned int count, unsigned int)
{
    if (count <= 0)
        count = 0;
    else if ((unsigned int)-1 / count < sizeof(unsigned int))
        throw WordAllocationFailure(0);
    return (unsigned int*)operator new(count * sizeof(unsigned int));
}
inline unsigned int wordMaximum()
{
    unsigned int count = (unsigned int)-1 / sizeof(unsigned int);
    return 0 < count ? count : 1;
}
inline bool FUN_00abc260_cls::FUN_00abc260(unsigned int count)
{
    m_0c = 0, m_10 = 0, m_14 = 0;
    if (count == 0)
        return false;
    else if (wordMaximum() < count)
        wordThrowLength();
    else
    {
        m_0c = FUN_00ac1720(count, 0);
        m_10 = m_0c;
        m_14 = m_0c + count;
    }
    return true;
}

struct FUN_00aba4f0 : VectorVal_aba4f0<unsigned int, Allocator<unsigned int> >
{
    FUN_00aba4f0();
    unsigned int* myfirst;
    unsigned int* mylast;
    unsigned int* myend;
};

// @fnv 0x00aba4f0
FUN_00aba4f0::FUN_00aba4f0() : VectorVal_aba4f0<unsigned int, Allocator<unsigned int> >()
{
    ((FUN_00abc260_cls*)this)->FUN_00abc260(0);
}

namespace fnv_00abd2e0 {
namespace FnvStd {
struct _Range_checked_iterator_tag
{
};
struct _Nonscalar_ptr_iterator_tag
{
};
struct _Undefined_move_tag
{
};
struct _Unchanged_checked_iterator_base_type_tag
{
};
template <class _Iter> inline _Iter _Checked_base(_Iter& _It, _Unchanged_checked_iterator_base_type_tag)
{
    return _It;
}
template <class _Iter> inline _Iter _Checked_base(_Iter& _It)
{
    _Unchanged_checked_iterator_base_type_tag _Base_tag;
    return _Checked_base(_It, _Base_tag);
}
template <class _Iter> inline _Undefined_move_tag _Move_cat(const _Iter&)
{
    _Undefined_move_tag _Cat;
    return _Cat;
}
template <class _T1, class _T2> inline _Nonscalar_ptr_iterator_tag _Ptr_cat(_T1&, _T2&)
{
    _Nonscalar_ptr_iterator_tag _Cat;
    return _Cat;
}
template <class _Ty> inline void _Destroy(_Ty* _Ptr)
{
    _Ptr->~_Ty();
}
template <class T, class U> inline void construct_value(T* ptr, const U& value)
{
    void* storage = ptr;
    ::new (storage) T(value);
}
template <class _Alloc>
inline void _Destroy_range(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                           _Nonscalar_ptr_iterator_tag)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_range(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_range(_First, _Last, _Al, _Ptr_cat(_First, _Last));
}
template <class _FwdIt, class _Ty> inline void _Fill(_FwdIt _First, _FwdIt _Last, const _Ty& _Val)
{
    for (; _First != _Last; ++_First)
        *_First = _Val;
}
template <class _FwdIt, class _Ty> inline void fill(_FwdIt _First, _FwdIt _Last, const _Ty& _Val)
{
    _Fill(_Checked_base(_First), _Checked_base(_Last), _Val);
}
}

struct FnvBlock16
{
    unsigned int a, b, c, d;
};
template <class T> inline T* __cdecl FUN_0064e430(unsigned int, T*);
extern MemoryManager DAT_011f6238;
template <class T> struct PrivateAllocator;
template <> struct PrivateAllocator<FnvBlock16>
{
    typedef FnvBlock16 value_type;
    typedef FnvBlock16* pointer;
    typedef unsigned int size_type;
    unsigned int state;
    void deallocate(pointer _Ptr, size_type)
    {
        DAT_011f6238.Deallocate(_Ptr);
    }
    pointer allocate(size_type _Count, const void* = 0)
    {
        return FUN_0064e430(_Count, (pointer)0);
    }
    void destroy(pointer _Ptr)
    {
        FnvStd::_Destroy(_Ptr);
    }
    void construct(pointer ptr, const FnvBlock16& value)
    {
        FnvStd::construct_value(ptr, value);
    }
    size_type max_size() const throw()
    {
        size_type _Count = (size_type)(-1) / sizeof(FnvBlock16);
        return 0 < _Count ? _Count : 1;
    }
};

typedef PrivateAllocator<FnvBlock16> FnvBlockAllocator;

struct FnvErrorString
{
    unsigned int allocator;
    union Storage
    {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int size, capacity;
    FnvErrorString(const char*);
    ~FnvErrorString();
};
struct FnvException
{
    char* whatMessage;
    int ownsMessage;
    FnvException();
    FnvException(const char* const&);
    FnvException(const FnvException&);
    virtual ~FnvException() throw();
};
struct FnvLengthError : FnvException
{
    FnvErrorString message;
    FnvLengthError(const FnvErrorString&);
    virtual ~FnvLengthError();
};
extern const char DAT_010173c4[];
inline void __cdecl ThrowVectorTooLong()
{
    throw FnvLengthError(FnvErrorString(DAT_010173c4));
}

struct FnvBadAlloc : FnvException
{
    FnvBadAlloc(const char* message) throw() : FnvException(message)
    {}
    FnvBadAlloc(const FnvBadAlloc& other) throw() : FnvException(other)
    {}
    virtual ~FnvBadAlloc() throw()
    {}
};
extern void* __cdecl operator new(unsigned int);

template <class T> inline T* __cdecl FUN_0064e430(unsigned int count, T*)
{
    if (count && (count * sizeof(T)) / sizeof(T) != count)
        throw FnvBadAlloc(0);
    return (T*)operator new(count * sizeof(T));
}

template <class I, class O, class A>
inline O __cdecl FUN_00ac3820(I first, I last, O dest, A& al, FnvStd::_Nonscalar_ptr_iterator_tag,
                              FnvStd::_Range_checked_iterator_tag)
{
    O next = dest;
    try
    {
        for (; first != last; ++dest, ++first)
            al.construct(dest, *first);
    }
    catch (...)
    {
        for (; next != dest; ++next)
            al.destroy(next);
        throw;
    }
    return dest;
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt __cdecl CopyIteratorRange(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return FUN_00ac3820(FnvStd::_Checked_base(_First), FnvStd::_Checked_base(_Last), _Dest, _Al,
                        FnvStd::_Ptr_cat(_First, _Dest), FnvStd::_Range_checked_iterator_tag());
}

void __cdecl FUN_00ac21b0(FnvBlock16*, unsigned int, const FnvBlock16&, FnvBlockAllocator&,
                          FnvStd::_Nonscalar_ptr_iterator_tag, FnvStd::_Range_checked_iterator_tag);
namespace FnvMove {
template <class _InIt, class _FwdIt, class _Alloc, class _MoveCatTy>
inline _FwdIt _Uninit_move(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _MoveCatTy,
                           FnvStd::_Range_checked_iterator_tag)
{
    return CopyIteratorRange(_First, _Last, _Dest, _Al);
}
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt __cdecl FUN_00ac1b70(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return FnvMove::_Uninit_move(FnvStd::_Checked_base(_First), FnvStd::_Checked_base(_Last), _Dest, _Al,
                                 FnvStd::_Move_cat(_Dest), FnvStd::_Range_checked_iterator_tag());
}

FnvBlock16* CopyIteratorRange(FnvBlock16*, FnvBlock16*, FnvBlock16*, const FnvBlockAllocator&);
namespace FnvMove {
template <class _InIt, class _FwdIt, class _Alloc, class _MoveCatTy>
__forceinline _FwdIt _Uninit_moveSpill(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _MoveCatTy,
                                       FnvStd::_Range_checked_iterator_tag)
{
    return CopyIteratorRange(_First, _Last, _Dest, (const FnvBlockAllocator&)_Al);
}
}
template <class _InIt, class _FwdIt, class _Alloc>
__forceinline _FwdIt __cdecl MoveForSpill(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return FnvMove::_Uninit_moveSpill(FnvStd::_Checked_base(_First), FnvStd::_Checked_base(_Last), _Dest, _Al,
                                      FnvStd::_Move_cat(_Dest), FnvStd::_Range_checked_iterator_tag());
}

namespace FnvStd {
struct forward_iterator_tag
{
};
struct random_access_iterator_tag : forward_iterator_tag
{
};
template <class _I1, class _I2> inline random_access_iterator_tag _Iter_random(const _I1&, const _I2&)
{
    random_access_iterator_tag _Cat;
    return _Cat;
}
template <class _I1, class _I2, class _Cat>
inline _I2 _Copy_backward_opt(_I1 _First, _I1 _Last, _I2 _Dest, _Cat, _Nonscalar_ptr_iterator_tag,
                              _Range_checked_iterator_tag)
{
    while (_First != _Last)
    {
        _I1 _Source = --_Last;
        _I1 _Input = _Source;
        _I2 _Target = --_Dest;
        _Target->a = _Input->a;
        _Target->b = _Input->b;
        _Target->c = _Input->c;
        _Target->d = _Input->d;
    }
    return _Dest;
}
template <class _I1, class _I2>
inline _I2 _Copy_backward_opt(_I1 _First, _I1 _Last, _I2 _Dest, random_access_iterator_tag, _Nonscalar_ptr_iterator_tag,
                              _Range_checked_iterator_tag)
{
    _I2 _Result = _Dest - (_Last - _First);
    _Copy_backward_opt(_First, _Last, _Checked_base(_Dest), forward_iterator_tag(), _Nonscalar_ptr_iterator_tag(),
                       _Range_checked_iterator_tag());
    return _Result;
}
}
inline FnvBlock16* __cdecl FUN_00ac1bf0(FnvBlock16* _First, FnvBlock16* _Last, FnvBlock16* _Dest,
                                        FnvStd::random_access_iterator_tag _First_dest_cat, FnvStd::_Undefined_move_tag,
                                        FnvStd::_Range_checked_iterator_tag)
{
    return FnvStd::_Copy_backward_opt(_First, _Last, _Dest, _First_dest_cat, FnvStd::_Ptr_cat(_First, _Dest),
                                      FnvStd::_Range_checked_iterator_tag());
}
template <class _InIt, class _OutIt> inline _OutIt __cdecl FUN_00ac14e0(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return FUN_00ac1bf0(FnvStd::_Checked_base(_First), FnvStd::_Checked_base(_Last), _Dest,
                        FnvStd::_Iter_random(_First, _Dest), FnvStd::_Move_cat(_Dest),
                        FnvStd::_Range_checked_iterator_tag());
}

namespace FnvFill {
inline void unchecked_uninitialized_fill_n(FnvBlock16* _First, unsigned int _Count, const FnvBlock16& _Val,
                                           FnvBlockAllocator& _Al)
{
    FUN_00ac21b0(_First, _Count, _Val, _Al, FnvStd::_Ptr_cat(_First, _First), FnvStd::_Range_checked_iterator_tag());
}
}
struct FnvBlockIterator
{
    void* collection;
    FnvBlock16* position;
};
struct FnvBlockVector
{
    unsigned int unknown00, unknown04;
    FnvBlockAllocator _Alval;
    FnvBlock16* _Myfirst;
    FnvBlock16* _Mylast;
    FnvBlock16* _Myend;
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int max_size() const
    {
        return _Alval.max_size();
    }
    void _Destroy(FnvBlock16* _First, FnvBlock16* _Last)
    {
        FnvStd::_Destroy_range(_First, _Last, _Alval);
    }
    template <class _Iter> FnvBlock16* _Umove(_Iter _First, _Iter _Last, FnvBlock16* _Ptr)
    {
        return FUN_00ac1b70(_First, _Last, _Ptr, _Alval);
    }
    template <class _Iter> __forceinline FnvBlock16* _UmoveForSpill(_Iter _First, _Iter _Last, FnvBlock16* _Ptr)
    {
        return MoveForSpill(_First, _Last, _Ptr, _Alval);
    }
    FnvBlock16* _Ufill(FnvBlock16* _Ptr, unsigned int _Count, const FnvBlock16& _Val)
    {
        FnvFill::unchecked_uninitialized_fill_n(_Ptr, _Count, _Val, _Alval);
        return _Ptr + _Count;
    }
    void __thiscall FUN_00abd2e0(FnvBlockIterator _Where, unsigned int _Count, const FnvBlock16& _Val);
};
// @fnv 0x00abd2e0
void FnvBlockVector::FUN_00abd2e0(FnvBlockIterator _Where, unsigned int _Count, const FnvBlock16& _Val)
{
    unsigned int _Capacity = capacity();
    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        ThrowVectorTooLong();
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        FnvBlock16* _Newvec = _Alval.allocate(_Capacity);
        FnvBlock16* _Mid = _Newvec;
        try
        {
            _Mid = _Umove(_Myfirst, _Where.position, _Newvec);
            _Ufill(_Mid, _Count, _Val);
            _Mid += _Count;
            _Umove(_Where.position, _Mylast, _Mid);
        }
        catch (...)
        {
            _Destroy(_Newvec, _Mid);
            _Alval.deallocate(_Newvec, _Capacity);
            throw;
        }
        _Count += size();
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myend = _Newvec + _Capacity;
        _Mylast = _Newvec + _Count;
        _Myfirst = _Newvec;
    }
    else if ((unsigned int)(_Mylast - _Where.position) < _Count)
    {
        FnvBlock16 _Tmp = _Val;
        _UmoveForSpill(_Where.position, _Mylast, _Where.position + _Count);
        try
        {
            _Ufill(_Mylast, _Count - (_Mylast - _Where.position), _Tmp);
        }
        catch (...)
        {
            _Destroy(_Where.position + _Count, _Mylast + _Count);
            throw;
        }
        _Mylast += _Count;
        FnvStd::fill(_Where.position, _Mylast - _Count, _Tmp);
    }
    else
    {
        FnvBlock16 _Tmp = _Val;
        FnvBlock16* _Oldend = _Mylast;
        _Mylast = _Umove(_Oldend - _Count, _Oldend, _Mylast);
        FUN_00ac14e0(_Where.position, _Oldend - _Count, _Oldend);
        FnvStd::fill(_Where.position, _Where.position + _Count, _Tmp);
    }
}
}  // namespace fnv_00abd2e0

__forceinline void* operator new(unsigned int size)
{
    return g_memoryManager.Allocate(size);
}
__forceinline void* operator new[](unsigned int size)
{
    return g_memoryManager.Allocate(size);
}
void operator delete(void*);
void operator delete[](void*);
extern "C" __declspec(dllimport) void* __stdcall CreateSemaphoreA(void*, long, long, const char*);
struct IOSemaphore
{
    long initialCount;
    void* handle;
    long maximumCount;
    IOSemaphore* Initialize(long initial, long maximum)
    {
        IOSemaphore* self = this;
        self->initialCount = initial;
        self->maximumCount = maximum;
        self->handle = CreateSemaphoreA(0, self->initialCount, self->maximumCount, 0);
        return self;
    }
};
struct IOCriticalSection
{
    unsigned long debugInfo;
    long lockCount;
    long recursionCount;
    void* owningThread;
    void* lockSemaphore;
    unsigned long spinCount;
    IOCriticalSection()
    {
        InitializeCriticalSection(this);
    }
};
struct GlobalObject_0078d3b0
{
    long initialCount;
    void* handle;
    long maximumCount;
    GlobalObject_0078d3b0();
    ~GlobalObject_0078d3b0();
};
extern int DAT_010a29a0, DAT_010a2990, DAT_010a2970, DAT_010a2960;
struct IOQueue
{
    int* vtable;
    void* head;
    void* tail;
    unsigned int count;
    IOQueue()
    {
        vtable = &DAT_010a29b0;
        count = 0;
        head = 0;
        tail = 0;
        vtable = &DAT_010a29a0;
        vtable = &DAT_010a2990;
    }
    void FUN_00aa8a40(GlobalObject_0078d3b0* const&);
};
struct IOFreeQueue
{
    int* vtable;
    void* head;
    void* tail;
    unsigned int count;
    IOFreeQueue()
    {
        vtable = &DAT_010a2980;
        count = 0;
        head = 0;
        tail = 0;
        vtable = &DAT_010a2970;
        vtable = &DAT_010a2960;
    }
};

extern "C" __declspec(dllimport) void* __stdcall GetCurrentThread();
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void*, unsigned int, unsigned long(__stdcall*)(void*),
                                                              void*, unsigned long, unsigned long*);
extern "C" __declspec(dllimport) unsigned long __stdcall ResumeThread(void*);
unsigned long __stdcall RunThreadProc(void*);
struct IOThread
{
    int* vtable;
    IOCriticalSection critical;
    void* worker;
    void* creator;
    unsigned long workerId;
    unsigned long creatorId;
    bool running;
    void FUN_00aa6560(int);
    void FUN_00aa6430(int stackSize, const char* name, bool suspended)
    {
        IOThread* self = this;
        if (self->worker)
            return;
        self->creator = GetCurrentThread();
        self->creatorId = GetCurrentThreadId();
        self->worker = CreateThread(0, stackSize, RunThreadProc, self, suspended ? 4 : 0, &self->workerId);
        DAT_00fdf05c(&self->critical);
        self->FUN_00aa6560(-1);
        self->running = true;
        ResumeThread(self->worker);
        DAT_00fdf100(&self->critical);
    }
};
struct GlobalObject_00aa8410
{
    int unk00;
    GlobalObject_00aa8410();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
};
namespace IoTaskGlobals {
extern "C" IOSemaphore* DAT_011f6bf8;
extern "C" IOThread* DAT_011f6bf0;
}
namespace IoTaskGlobals {
extern "C" GlobalObject_0078d3b0* DAT_011f6c08;
}
// @fnv 0x00aa7eb0
void FUN_00aa7eb0()
{
    unsigned int i;
    {
        IOSemaphore* sem1Result;
        IOSemaphore* sem1Memory;
        IOSemaphore* sem2Result;
        IOSemaphore* sem2Memory2;
        sem1Memory = (IOSemaphore*)g_memoryManager.Allocate(12);
        sem1Result = sem1Memory ? sem1Memory->Initialize(0, 65535) : 0;
        DAT_011f6bf4 = sem1Result;
        sem2Memory2 = (IOSemaphore*)g_memoryManager.Allocate(12);
        sem2Result = sem2Memory2 ? sem2Memory2->Initialize(0, 1) : 0;
        IoTaskGlobals::DAT_011f6bf8 = sem2Result;
        DAT_011f6bfc = new IOCriticalSection;
        DAT_011f6c00 = (BlockSource*)new IOQueue;
        DAT_011f6c04 = (PoolA*)new IOFreeQueue;
        IoTaskGlobals::DAT_011f6c08 = new GlobalObject_0078d3b0[32];
        for (i = 0; i < 32; ++i)
        {
            ((IOQueue*)DAT_011f6c04)->FUN_00aa8a40(&IoTaskGlobals::DAT_011f6c08[i]);
        }
        IoTaskGlobals::DAT_011f6bf0 = (IOThread*)new GlobalObject_00aa8410;
        IoTaskGlobals::DAT_011f6bf0->FUN_00aa6430(0x4000, "Serialized IO Thread", false);
    }
}

double GenerateGaussianRandom();
void __cdecl ReportAssertionViolation(const char*, int);
struct ReworkInput
{
    void* proxy;
    int proxyAllocator, allocator;
    float* first;
    float* last;
    float* limit;
    unsigned rows, cols;
    FGScaledMatrix FUN_00658360(const ReworkInput&);
};
struct ReworkGrid : FGMatrix
{
    unsigned getRows()
    {
        return rows;
    }
};
struct ReworkMatrix : ReworkInput
{
    FGMatrix FUN_00658500(const FGMatrix&);
    FGMatrix FUN_00aaf110(int, int, int, int);
    void FUN_006581e0(const FGScaledMatrix&);
    void FUN_00449680()
    {
        ((FGMatrix*)this)->FGMatrix::~FGMatrix();
    }
    __forceinline ~ReworkMatrix()
    {
        FUN_00449680();
    }
};
struct ReworkPair
{
    ReworkGrid grid[2];
    void FUN_006581e0(const FGMatrix&);
};
ReworkMatrix __cdecl FUN_00aaf330(ReworkPair&, ReworkPair&);
struct ReworkModel : FGModel
{
    void FUN_00aad140(int idx, ReworkPair* bases);
};
// @fnv 0x00aad140
void ReworkModel::FUN_00aad140(int idx, ReworkPair* bases)
{
    if (idx < 5)
    {
    }
    else
        ReportAssertionViolation(DAT_010a2c5c, 498);
    if (!loaded)
    {
    }
    else
    {
        unsigned aVal;
        unsigned b8;
        for (unsigned i = 0; i < 2; i++)
            for (unsigned j = 0; j < 2; j++)
                for (unsigned k = 0; k < bases[i].grid[j].getRows(); k++)
                    bases[i].grid[j].FUN_0060b370(k)[0] = (float)GenerateGaussianRandom();
        ReworkMatrix oB = FUN_00aaf330(bases[0], bases[1]);
        oB.FUN_006581e0(((ReworkInput&)matrices[idx].square).FUN_00658360(oB));
        aVal = bases[0].grid[0].rows;
        b8 = bases[1].grid[0].rows;
        bases[0].FUN_006581e0(((ReworkMatrix&)oB.FUN_00aaf110(0, 0, aVal, 1)).FUN_00658500(matrices[idx].first[0]));
        bases[1].FUN_006581e0(((ReworkMatrix&)oB.FUN_00aaf110(aVal, 0, b8, 1)).FUN_00658500(matrices[idx].first[1]));
    }
}

void __cdecl operator delete(void*);
extern "C" int __cdecl memcpy_s(void*, unsigned int, const void*, unsigned int);
extern "C" int __cdecl memmove_s(void*, unsigned int, const void*, unsigned int);
struct SecureTraitsTag
{
};
inline SecureTraitsTag charTraitsTag()
{
    SecureTraitsTag tag;
    return tag;
}
inline char* secureCopy(char* d, unsigned int cap, const char* s, unsigned int n)
{
    memcpy_s(d, cap, s, n);
    return d;
}
inline char* secureMove(char* d, unsigned int cap, const char* s, unsigned int n)
{
    memmove_s(d, cap, s, n);
    return d;
}
inline char* taggedCopy(char* d, unsigned int cap, const char* s, unsigned int n, SecureTraitsTag)
{
    return secureCopy(d, cap, s, n);
}
inline char* taggedMove(char* d, unsigned int cap, const char* s, unsigned int n, SecureTraitsTag)
{
    return secureMove(d, cap, s, n);
}
extern unsigned int entryNpos;
struct EntryPart
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    EntryPart(const EntryPart&);
    ~EntryPart();
    EntryPart& operator=(const EntryPart&);
};
struct EntryString
{
    int unk00;
    char buffer[16];
    unsigned int length, reserved;
    EntryString(const EntryString&);
    EntryString(const char*);
    ~EntryString()
    {
        Tidy(true, 0);
    }
    void DeallocateBuffer(char* p)
    {
        ::operator delete(p);
    }
    __declspec(noinline) void Tidy(bool built, unsigned int n)
    {
        if (!built)
            ;
        else if (16 <= reserved)
        {
            char* old = heapPointer();
            if (0 < n)
                CopyChars(buffer, 16, old, n);
            DeallocateBuffer(old);
        }
        reserved = 15;
        Eos(n);
    }
    unsigned int size() const
    {
        return length;
    }
    static void RangeError();
    static char* MoveChars(char* d, unsigned int cap, const char* s, unsigned int n)
    {
        return taggedMove(d, cap, s, n, charTraitsTag());
    }
    __forceinline EntryString& erase(unsigned int off, unsigned int n = entryNpos)
    {
        if (length < off)
            RangeError();
        if (length - off < n)
            n = length - off;
        if (0 < n)
        {
            MoveChars(ptr() + off, reserved - off, ptr() + off + n, length - off - n);
            Eos(length - n);
        }
        return *this;
    }
    static void InsertLengthError();
    void RenderCopyData(unsigned int, unsigned int);
    unsigned int max_size() const
    {
        unsigned int n = 0xffffffff;
        return n <= 1 ? 1 : n - 1;
    }
    __declspec(noinline) bool Grow(unsigned int n, bool trim = false)
    {
        unsigned int maximum = max_size();
        if (maximum < n)
            InsertLengthError();
        if (reserved < n)
            RenderCopyData(n, length);
        else if (trim && n < 16)
            Tidy(true, n < length ? n : length);
        else if (n == 0)
            Eos(0);
        return 0 < n;
    }
    static char* CopyChars(char* d, unsigned int cap, const char* s, unsigned int n)
    {
        return taggedCopy(d, cap, s, n, charTraitsTag());
    }
    char* heapPointer();
    const char* heapPointer() const;
    __declspec(noinline) char* ptr()
    {
        return 16 <= reserved ? heapPointer() : buffer;
    }
    const __declspec(noinline) char* ptr() const
    {
        return 16 <= reserved ? heapPointer() : buffer;
    }
    static void AssignChar(char& out, const char& v)
    {
        out = v;
    }
    __declspec(noinline) void Eos(unsigned int n)
    {
        AssignChar(ptr()[length = n], char());
    }
    __forceinline EntryString& assign(const EntryString& rhs, unsigned int off, unsigned int n)
    {
        struct Slice
        {
            const EntryString* owner;
            unsigned int begin, extent;
        };
        Slice input = {&rhs, off, n};
        unsigned int available = input.owner->size();
        if (available < input.begin)
            RangeError();
        available -= input.begin;
        unsigned int count = input.extent < available ? input.extent : available;
        const char* source = input.owner->ptr() + input.begin;
        char* destination = ptr();
        if (this == input.owner)
        {
            erase(input.begin + count);
            erase(0, input.begin);
            return *this;
        }
        if (Grow(count))
        {
            destination = ptr();
            CopyChars(destination, reserved, source, count);
            Eos(count);
        }
        return *this;
    }
    EntryString& operator=(const EntryString& rhs)
    {
        return assign(rhs, 0, entryNpos);
    }
};
struct Entry
{
    EntryPart part;
    EntryString text;
    Entry(const Entry& rhs) : part(rhs.part), text(rhs.text)
    {}
    ~Entry()
    {}
    Entry& operator=(const Entry& rhs)
    {
        part = rhs.part;
        text = rhs.text;
        return *this;
    }
    void Destroy(unsigned int);
};
struct FirstString
{
    int unk00;
    char buffer[16];
    unsigned int length, reserved;
    FirstString(const FirstString& rhs)
    {
        Tidy(false, 0);
        assign(rhs, 0, entryNpos);
    }
    FirstString(const char*);
    ~FirstString()
    {
        Tidy(true, 0);
    }
    void DeallocateBuffer(char* p)
    {
        ::operator delete(p);
    }
    void Tidy(bool built, unsigned int n)
    {
        if (!built)
            ;
        else if (16 <= reserved)
        {
            char* old = heapPointer();
            if (0 < n)
                CopyChars(buffer, 16, old, n);
            DeallocateBuffer(old);
        }
        reserved = 15;
        Eos(n);
    }
    unsigned int size() const
    {
        return length;
    }
    static void RangeError();
    static char* MoveChars(char* d, unsigned int cap, const char* s, unsigned int n)
    {
        return taggedMove(d, cap, s, n, charTraitsTag());
    }
    FirstString& erase(unsigned int off, unsigned int n = entryNpos)
    {
        if (length < off)
            RangeError();
        if (length - off < n)
            n = length - off;
        if (0 < n)
        {
            MoveChars(ptr() + off, reserved - off, ptr() + off + n, length - off - n);
            unsigned int newsize = length - n;
            Eos(newsize);
        }
        return *this;
    }
    static void InsertLengthError();
    void RenderCopyData(unsigned int, unsigned int);
    unsigned int max_size() const
    {
        unsigned int n = 0xffffffff;
        return n <= 1 ? 1 : n - 1;
    }
    bool Grow(unsigned int n, bool trim = false)
    {
        if (max_size() < n)
            InsertLengthError();
        if (reserved < n)
            RenderCopyData(n, length);
        else if (trim && n < 16)
            Tidy(true, n < length ? n : length);
        else if (n == 0)
            Eos(0);
        return 0 < n;
    }
    static char* CopyChars(char* d, unsigned int cap, const char* s, unsigned int n)
    {
        return taggedCopy(d, cap, s, n, charTraitsTag());
    }
    char* heapPointer();
    const char* heapPointer() const;
    char* ptr()
    {
        return 16 <= reserved ? heapPointer() : buffer;
    }
    const char* ptr() const
    {
        return 16 <= reserved ? heapPointer() : buffer;
    }
    static void AssignChar(char& out, const char& v)
    {
        out = v;
    }
    void Eos(unsigned int n)
    {
        AssignChar(ptr()[length = n], char());
    }
    FirstString& assign(const FirstString& rhs, unsigned int off, unsigned int n)
    {
        if (rhs.size() < off)
            RangeError();
        unsigned int num = rhs.size() - off;
        if (n < num)
            num = n;
        if (this == &rhs)
            erase(off + num), erase(0, off);
        else if (Grow(num))
        {
            CopyChars(ptr(), reserved, rhs.ptr() + off, num);
            Eos(num);
        }
        return *this;
    }
    FirstString& operator=(const FirstString& rhs)
    {
        return assign(rhs, 0, entryNpos);
    }
};
struct OutlinedEntry
{
    EntryPart part;
    FirstString text;
    OutlinedEntry(const Entry& rhs) : part(rhs.part), text(reinterpret_cast<const FirstString&>(rhs.text))
    {}
    ~OutlinedEntry();
};
struct InsertCopyTag
{
};
struct InsertRangeTag
{
};
struct InsertInputTag
{
};
struct InsertForwardTag : InsertInputTag
{
};
struct InsertBidirectionalTag : InsertForwardTag
{
};
struct InsertRandomTag : InsertBidirectionalTag
{
};
inline InsertRangeTag rangeTag()
{
    return InsertRangeTag();
}
inline InsertCopyTag copyTag(Entry* const& p)
{
    InsertCopyTag cat;
    return cat;
}
inline InsertCopyTag ptrTag(Entry*& a, Entry*& b)
{
    InsertCopyTag cat;
    return cat;
}
inline InsertRandomTag iterTag(Entry* const& a, Entry* const& b)
{
    InsertRandomTag cat;
    return cat;
}
struct InsertBaseTag
{
};
inline Entry* checkedBase(Entry*& p, InsertBaseTag)
{
    return p;
}
inline Entry* unchecked(Entry*& p)
{
    InsertBaseTag tag;
    return checkedBase(p, tag);
}
struct EntryMemoryAllocator
{
    unsigned char value_bayk;
    unsigned int max_size() const
    {
        unsigned int count_mi = 0x4444444;
        return 0 < count_mi ? count_mi : 1;
    }
    void deallocate(Entry* p, unsigned int n);
};
Entry* __cdecl AllocateEntries(unsigned int, int);
struct LengthException
{
    virtual ~LengthException();
    int unk04, unk08;
    EntryString message;
    LengthException(const EntryString&);
};
inline void __cdecl InsertLengthError()
{
    throw LengthException(EntryString("vector<T> too long"));
}
Entry* __cdecl CopyPrefix(Entry*, Entry*, Entry*, EntryMemoryAllocator*);
Entry* __cdecl MoveEntries(Entry*, Entry*, Entry*, EntryMemoryAllocator*);
void __cdecl FillUninitialized(Entry*, unsigned int, const Entry&, EntryMemoryAllocator*, InsertCopyTag, InsertRangeTag);
inline void fillLoop(Entry* a, Entry* b, const Entry& v)
{
    for (; a != b; ++a)
        *a = v;
}
inline void __cdecl FillEntries(Entry* a, Entry* b, const Entry& v)
{
    fillLoop(unchecked(a), unchecked(b), v);
}
Entry* __cdecl MoveBackward(Entry*, Entry*, Entry*, InsertRandomTag, InsertCopyTag, InsertRangeTag);
struct EntryMemory
{
    void Deallocate(void*);
};
extern EntryMemory entryMemory;
inline Entry* moveTagged(Entry* a, Entry* b, Entry* d, EntryMemoryAllocator& al, InsertCopyTag, InsertRangeTag)
{
    return CopyPrefix(a, b, d, &al);
}
inline Entry* uncheckedMove(Entry* a, Entry* b, Entry* d, EntryMemoryAllocator& al)
{
    return moveTagged(unchecked(a), unchecked(b), d, al, copyTag(d), InsertRangeTag());
}
inline void uncheckedFill(Entry* p, unsigned int n, const Entry& v, EntryMemoryAllocator& al)
{
    FillUninitialized(p, n, v, &al, ptrTag(p, p), InsertRangeTag());
}
inline void destroyTagged(Entry* a, Entry* b, EntryMemoryAllocator& al, InsertCopyTag)
{
    for (; a != b; ++a)
        a->Destroy(0);
}
inline void destroyRange(Entry* a, Entry* b, EntryMemoryAllocator& al)
{
    destroyTagged(a, b, al, ptrTag(a, b));
}
inline void EntryMemoryAllocator::deallocate(Entry* p, unsigned int n)
{
    entryMemory.Deallocate(p);
}
struct InsertMoveTag
{
};
inline InsertMoveTag moveCategory(Entry* const&)
{
    InsertMoveTag category;
    return category;
}
inline Entry* backwardLoop(Entry* a, Entry* b, Entry* d, InsertForwardTag, InsertCopyTag, InsertRangeTag)
{
    while (a != b)
        *--d = *--b;
    return d;
}
inline Entry* backwardCopy(Entry* a, Entry* b, Entry* d, InsertRandomTag, InsertCopyTag, InsertRangeTag)
{
    Entry* result = d - (b - a);
    backwardLoop(a, b, unchecked(d), InsertForwardTag(), InsertCopyTag(), InsertRangeTag());
    return result;
}
inline Entry* moveBackwardDispatch(Entry* a, Entry* b, Entry* d, InsertRandomTag category, InsertMoveTag,
                                   InsertRangeTag)
{
    return backwardCopy(a, b, d, category, ptrTag(a, d), InsertRangeTag());
}
inline Entry* uncheckedBackward(Entry* a, Entry* b, Entry* d)
{
    return moveBackwardDispatch(unchecked(a), unchecked(b), d, iterTag(a, d), moveCategory(d), InsertRangeTag());
}
inline Entry* backward(Entry* a, Entry* b, Entry* d)
{
    return uncheckedBackward(a, b, d);
}
struct FinalString
{
    int unk00;
    char buffer[16];
    unsigned int length, reserved;
    FinalString(const FinalString&);
    FinalString(const char*);
    ~FinalString()
    {
        Tidy(true, 0);
    }
    void DeallocateBuffer(char* p)
    {
        ::operator delete(p);
    }
    __declspec(noinline) void Tidy(bool built, unsigned int n)
    {
        if (!built)
            ;
        else if (16 <= reserved)
        {
            char* old = heapPointer();
            if (0 < n)
                CopyChars(buffer, 16, old, n);
            DeallocateBuffer(old);
        }
        reserved = 15;
        Eos(n);
    }
    unsigned int size() const
    {
        return length;
    }
    static void RangeError();
    static char* MoveChars(char* d, unsigned int cap, const char* s, unsigned int n)
    {
        return taggedMove(d, cap, s, n, charTraitsTag());
    }
    __forceinline FinalString& erase(unsigned int off, unsigned int n = entryNpos)
    {
        if (length < off)
            RangeError();
        if (length - off < n)
            n = length - off;
        if (0 < n)
        {
            MoveChars(ptr() + off, reserved - off, ptr() + off + n, length - off - n);
            Eos(length - n);
        }
        return *this;
    }
    static void InsertLengthError();
    void RenderCopyData(unsigned int, unsigned int);
    unsigned int max_size() const
    {
        unsigned int n = 0xffffffff;
        return n <= 1 ? 1 : n - 1;
    }
    __declspec(noinline) bool Grow(unsigned int n, bool trim = false)
    {
        unsigned int maximum = max_size();
        if (maximum < n)
            InsertLengthError();
        if (reserved < n)
            RenderCopyData(n, length);
        else if (trim && n < 16)
            Tidy(true, n < length ? n : length);
        else if (n == 0)
            Eos(0);
        return 0 < n;
    }
    static char* CopyChars(char* d, unsigned int cap, const char* s, unsigned int n)
    {
        return taggedCopy(d, cap, s, n, charTraitsTag());
    }
    char* heapPointer();
    const char* heapPointer() const;
    char* ptr()
    {
        return 16 <= reserved ? heapPointer() : buffer;
    }
    const char* ptr() const
    {
        return 16 <= reserved ? heapPointer() : buffer;
    }
    static void AssignChar(char& out, const char& v)
    {
        out = v;
    }
    __declspec(noinline) void Eos(unsigned int n)
    {
        AssignChar(ptr()[length = n], char());
    }
    __forceinline FinalString& assign(const FinalString& rhs, unsigned int off, unsigned int n)
    {
        if (rhs.size() < off)
            RangeError();
        unsigned int count = rhs.size() - off;
        if (n < count)
            count = n;
        if (this == &rhs)
            erase(off + count), erase(0, off);
        else if (Grow(count))
        {
            CopyChars(ptr(), reserved, rhs.ptr() + off, count);
            Eos(count);
        }
        return *this;
    }
    FinalString& operator=(const FinalString& rhs)
    {
        return assign(rhs, 0, entryNpos);
    }
};
struct FinalEntry
{
    EntryPart part;
    FinalString text;
    FinalEntry& operator=(const FinalEntry& rhs)
    {
        part = rhs.part;
        text = rhs.text;
        return *this;
    }
};
struct FinalBaseTag
{
};
inline FinalEntry* FinalChecked(FinalEntry*& p, FinalBaseTag)
{
    return p;
}
inline FinalEntry* FinalUnchecked(FinalEntry*& p)
{
    FinalBaseTag tag;
    return FinalChecked(p, tag);
}
inline void FinalLoop(FinalEntry* a, FinalEntry* b, const FinalEntry& v)
{
    for (; a != b; ++a)
        *a = v;
}
inline void LastFill(FinalEntry* a, FinalEntry* b, const FinalEntry& v)
{
    FinalLoop(FinalUnchecked(a), FinalUnchecked(b), v);
}

struct EntryVector
{
    int unk00, unk04;
    EntryMemoryAllocator allocator_ygxh;
    Entry* first_yoqmo;
    Entry* last_zuz;
    Entry* end_b;
    unsigned int capacity() const
    {
        return first_yoqmo == 0 ? 0 : end_b - first_yoqmo;
    }
    unsigned int size() const
    {
        return last_zuz - first_yoqmo;
    }
    unsigned int max_size() const
    {
        return allocator_ygxh.max_size();
    }
    void destroy(Entry* begin, Entry* finish)
    {
        destroyRange(begin, finish, allocator_ygxh);
    }
    Entry* copy(Entry* a, Entry* b, Entry* d)
    {
        return uncheckedMove(a, b, d, allocator_ygxh);
    }
    Entry* move(Entry* a, Entry* b, Entry* d)
    {
        return MoveEntries(a, b, d, &allocator_ygxh);
    }
    Entry* moveTail(Entry* a, Entry* b, Entry* d)
    {
        return MoveEntries(a, b, d, &allocator_ygxh);
    }
    void fill(Entry* p, unsigned int n, const Entry& v)
    {
        uncheckedFill(p, n, v, allocator_ygxh);
    }
    void FUN_00aae3a0(int owner_ai, Entry* where_tmoy, unsigned int count_mi, const Entry& value_bayk);
};
// @fnv 0x00aae3a0
void EntryVector::FUN_00aae3a0(int owner_ai, Entry* where_tmoy, unsigned int count_mi, const Entry& value_bayk)
{
    unsigned int capacityValue_ea = capacity();
    if (count_mi == 0)
        ;
    else if (max_size() - size() < count_mi)
        InsertLengthError();
    else if (capacityValue_ea < size() + count_mi)
    {
        capacityValue_ea =
            max_size() - capacityValue_ea / 2 < capacityValue_ea ? 0 : capacityValue_ea + capacityValue_ea / 2;
        if (capacityValue_ea < size() + count_mi)
            capacityValue_ea = size() + count_mi;
        Entry* _Newvec = AllocateEntries(capacityValue_ea, 0);
        Entry* _Newlast = _Newvec;
        try
        {
            _Newlast = copy(first_yoqmo, where_tmoy, _Newvec);
            fill(_Newlast, count_mi, value_bayk);
            _Newlast += count_mi;
            move(where_tmoy, last_zuz, _Newlast);
        }
        catch (...)
        {
            destroy(_Newvec, _Newlast);
            allocator_ygxh.deallocate(_Newvec, capacityValue_ea);
            throw;
        }
        count_mi += last_zuz - first_yoqmo;
        if (first_yoqmo != 0)
        {
            destroy(first_yoqmo, last_zuz);
            allocator_ygxh.deallocate(first_yoqmo, end_b - first_yoqmo);
        }
        end_b = _Newvec + capacityValue_ea;
        last_zuz = _Newvec + count_mi;
        first_yoqmo = _Newvec;
    }
    else if ((unsigned int)(last_zuz - where_tmoy) < count_mi)
    {
        OutlinedEntry _jfnz(value_bayk);
        copy(where_tmoy, last_zuz, where_tmoy + count_mi);
        try
        {
            fill(last_zuz, count_mi - (last_zuz - where_tmoy), reinterpret_cast<const Entry&>(_jfnz));
        }
        catch (...)
        {
            destroy(where_tmoy + count_mi, last_zuz + count_mi);
            throw;
        }
        last_zuz += count_mi;
        FillEntries(where_tmoy, last_zuz - count_mi, reinterpret_cast<const Entry&>(_jfnz));
    }
    else
    {
        Entry _jfnz(value_bayk);
        Entry* _ivbnx = last_zuz;
        last_zuz = moveTail(_ivbnx - count_mi, _ivbnx, last_zuz);
        backward(where_tmoy, _ivbnx - count_mi, _ivbnx);
        LastFill(reinterpret_cast<FinalEntry*>(where_tmoy), reinterpret_cast<FinalEntry*>(where_tmoy + count_mi),
                 reinterpret_cast<const FinalEntry&>(_jfnz));
    }
}

void __cdecl operator delete(void*);
namespace Ab2e70Detail {
struct SecureTag
{
};
inline SecureTag secure_category()
{
    SecureTag category;
    return category;
}
extern "C" int __cdecl memcpy_s(void*, unsigned int, const void*, unsigned int);
inline char* secure_copy(char* dest, unsigned int size, const char* source, unsigned int count, SecureTag)
{
    memcpy_s(dest, size, source, count);
    return dest;
}
inline char* secure_copy(char* dest, unsigned int size, const char* source, unsigned int count)
{
    return secure_copy(dest, size, source, count, secure_category());
}
class AllocationBase
{
  public:
    AllocationBase(const char* const&);
    virtual ~AllocationBase() throw();
    const char* message;
    int ownsMessage;
};
class AllocationError : public AllocationBase
{
  public:
    AllocationError(const char* message) throw() : AllocationBase(message)
    {}
    virtual ~AllocationError() throw()
    {}
};
template <class T> inline T* checked_allocate(unsigned int count, T*)
{
    if (count <= 0)
        count = 0;
    else if ((unsigned int)-1 / count < sizeof(T))
        throw AllocationError(0);
    return (T*)operator new(count * sizeof(T));
}
template <class T> class Alloc
{
  public:
    Alloc() throw()
    {}
    Alloc(const Alloc&) throw()
    {}
    template <class U> Alloc(const Alloc<U>&) throw()
    {}
    T* allocate(unsigned int count)
    {
        return checked_allocate(count, (T*)0);
    }
    void deallocate(T* p, unsigned int)
    {
        operator delete(p);
    }
    unsigned int max_size() const throw()
    {
        unsigned int count = (unsigned int)-1 / sizeof(T);
        return count > 0 ? count : 1;
    }
};
class Base;
class Aux
{
  public:
    Aux(const Base* owner) : owner(owner)
    {}
    const Base* owner;
};
class Base
{
  public:
    Base()
    {}
    ~Base()
    {}
    Aux* proxy;
};
template <class A> class Proxy : public Base
{
  public:
    Proxy(A al) : allocator(al)
    {
        proxy = new (allocator.allocate(1)) Aux(this);
    }
    ~Proxy()
    {
        proxy->~Aux();
        allocator.deallocate(proxy, 1);
    }
    Alloc<Aux> allocator;
};
template <class T, class A> class Value : public Proxy<A>
{
  public:
    Value(A al = A()) : Proxy<A>(al), allocator(al)
    {}
    Alloc<T> allocator;
};
struct StringValue
{
    StringValue(Alloc<char> al = Alloc<char>()) : allocator(al)
    {}
    Alloc<char> allocator;
};
struct ErrorString : StringValue
{
    union
    {
        char local[16];
        char* heap;
    } storage;
    unsigned int size, capacity;
    ErrorString(const char* text) : StringValue()
    {
        tidy();
        assign(text);
    }
    ~ErrorString()
    {
        tidy(true);
    }
    char* pointer()
    {
        return 16 <= capacity ? storage.heap : storage.local;
    }
    void tidy(bool built = false, unsigned int count = 0)
    {
        if (!built)
        {
        }
        else if (16 <= capacity)
        {
            char* old = storage.heap;
            if (0 < count)
                secure_copy(storage.local, 16, old, count);
            allocator.deallocate(old, capacity + 1);
        }
        capacity = 15;
        terminate(count);
    }
    ErrorString& assign(const ErrorString&, unsigned int, unsigned int);
    ErrorString& assign(const char* text)
    {
        return assign(text, strlen(text));
    }
    ErrorString& assign(const char* text, unsigned int count)
    {
        if (inside(text))
            return assign(*this, text - pointer(), count);
        if (grow(count))
        {
            secure_copy(pointer(), capacity, text, count);
            terminate(count);
        }
        return *this;
    }
    bool inside(const char* text)
    {
        if (text == 0 || text < pointer() || pointer() + size <= text)
            return false;
        else
            return true;
    }
    unsigned int max_size() const
    {
        unsigned int count = allocator.max_size();
        return count <= 1 ? 1 : count - 1;
    }
    void copy(unsigned int, unsigned int);
    bool grow(unsigned int count, bool trim = false)
    {
        if (max_size() < count)
            StringBase::Xlen();
        if (capacity < count)
            copy(count, size);
        else if (trim && count < 16)
            tidy(true, count < size ? count : size);
        else if (count == 0)
            terminate(0);
        return 0 < count;
    }
    void terminate(unsigned int count)
    {
        CharTraits::assign(pointer()[size = count], char());
    }
};
struct LengthError
{
    virtual ~LengthError() throw();
    const char* message;
    bool ownsMessage;
    ErrorString text;
    LengthError(const ErrorString&);
};
}
namespace std {
template <class T, class A = Ab2e70Detail::Alloc<T> > class vector : public Ab2e70Detail::Value<T, A>
{
  public:
    __forceinline vector() : Ab2e70Detail::Value<T, A>()
    {
        FUN_00657ee0(0);
    }
    unsigned int max_size() const
    {
        return this->allocator.max_size();
    }
    static void length_error()
    {
        throw Ab2e70Detail::LengthError(Ab2e70Detail::ErrorString("vector<T> too long"));
    }
    bool FUN_00657ee0(unsigned int count)
    {
        first = 0, last = 0, limit = 0;
        if (count == 0)
            return false;
        else if (max_size() < count)
            length_error();
        else
        {
            first = this->allocator.allocate(count);
            last = first;
            limit = first + count;
        }
        return true;
    }
    T* first;
    T* last;
    T* limit;
};
}
// @fnv 0x00ab2e70
FUN_00ab2e70::FUN_00ab2e70()
{
    ((std::vector<char>*)this)->std::vector<char>::vector();
}

namespace WordInsert {
typedef unsigned int Word;
extern "C" int __cdecl FUN_00ec7ce3(void*, unsigned int, const Word*, unsigned int);
struct ScalarTag
{
};
struct RangeTag
{
};
struct BaseTag
{
};
struct InputTag
{
};
struct ForwardTag : InputTag
{
};
struct BidirectionalTag : ForwardTag
{
};
struct RandomTag : BidirectionalTag
{
};
struct MoveTag
{
};
template <class I> inline I base_inner(const I& _Val, BaseTag)
{
    return _Val;
}
template <class I> inline I checked_base(const I& _Val)
{
    BaseTag _Cat;
    return base_inner(_Val, _Cat);
}
template <class I> inline I base_inner(I& _Val, BaseTag)
{
    return _Val;
}
template <class I> inline I checked_base(I& _Val)
{
    BaseTag _Cat;
    return base_inner(_Val, _Cat);
}
template <class I, class O> inline ScalarTag ptr_category(const I&, const O&)
{
    ScalarTag _Cat;
    return _Cat;
}
template <class I> inline MoveTag move_category(const I&)
{
    MoveTag _Cat;
    return _Cat;
}
template <class I, class O> inline RandomTag iter_random(const I&, const O&)
{
    RandomTag _Cat;
    return _Cat;
}
template <class I> inline RandomTag iter_category(const I&)
{
    return RandomTag();
}
struct AllocationException
{
    virtual ~AllocationException() throw();
    const char* message;
    int ownsMessage;
    AllocationException(const char* const&);
};
struct AllocationError : AllocationException
{
    AllocationError(const char* text) throw() : AllocationException(text)
    {}
    virtual ~AllocationError() throw()
    {}
};
template <class T> inline T* allocate(unsigned int _Count, T*)
{
    if (_Count <= 0)
        _Count = 0;
    else if ((unsigned int)(-1) / _Count < sizeof(T))
        throw AllocationError(0);
    return (T*)operator new(_Count * sizeof(T));
}
template <class T> struct Allocator
{
    typedef T* pointer;
    typedef T value_type;
    Allocator() throw()
    {}
    Allocator(const Allocator&) throw()
    {}
    template <class U> Allocator(const Allocator<U>&) throw()
    {}
    T* allocate(unsigned int _Count, const void* = 0)
    {
        return WordInsert::allocate(_Count, (T*)0);
    }
    void deallocate(T* pointer, unsigned int)
    {
        DAT_011f6238.Deallocate(pointer);
    }
    unsigned int max_size() const throw()
    {
        unsigned int _Count = (unsigned int)-1 / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
template <class I, class O, class A> inline O copy_scalar(I _First, I _Last, O _Dest, A&, ScalarTag, RangeTag)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    O _Result = _Dest + _Count;
    if (_Count > 0)
        FUN_00ec7ce3(_Dest, _Count * sizeof(*_First), _First, _Count * sizeof(*_First));
    return _Result;
}
template <class I, class O, class A> inline O copy_unchecked(I _First, I _Last, O _Dest, A& _Al)
{
    return copy_scalar(checked_base(_First), checked_base(_Last), _Dest, _Al, ptr_category(_First, _Dest), RangeTag());
}
template <class I, class O, class A, class M> inline O move_dispatch(I _First, I _Last, O _Dest, A& _Al, M, RangeTag)
{
    return copy_unchecked(_First, _Last, _Dest, _Al);
}
template <class I, class O, class A> inline O move_unchecked(I _First, I _Last, O _Dest, A& _Al)
{
    return move_dispatch(checked_base(_First), checked_base(_Last), _Dest, _Al, move_category(_Dest), RangeTag());
}
template <class I, class N, class T> inline void fill_n_loop(I _First, N _Count, const T& _Val, RangeTag)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class I, class N, class T> inline void fill_n_dispatch(I _First, N _Count, const T& _Val, RandomTag, RangeTag)
{
    I _Result = _First + _Count;
    fill_n_loop(checked_base(_First), _Count, _Val, RangeTag());
}
template <class I, class N, class T> inline void fill_n_unchecked(I _First, N _Count, const T& _Val)
{
    fill_n_dispatch(_First, _Count, _Val, iter_category(_First), RangeTag());
}
template <class I, class N, class T, class A>
inline void uninit_fill_dispatch(I _First, N _Count, const T& _Val, A&, ScalarTag, RangeTag)
{
    fill_n_unchecked(_First, _Count, _Val);
}
template <class I, class N, class T, class A> inline void uninit_fill(I _First, N _Count, const T& _Val, A& _Al)
{
    uninit_fill_dispatch(_First, _Count, _Val, _Al, ptr_category(_First, _First), RangeTag());
}
template <class A> inline void destroy_dispatch(typename A::pointer, typename A::pointer, A&, ScalarTag)
{}
template <class A> inline void destroy_range(typename A::pointer _First, typename A::pointer _Last, A& _Al)
{
    destroy_dispatch(_First, _Last, _Al, ptr_category(_First, _Last));
}
template <class I, class T> inline void fill_loop(I _First, I _Last, const T& _Val)
{
    for (; _First != _Last; ++_First)
        *_First = _Val;
}
template <class I, class T> inline void fill(I _First, I _Last, const T& _Val)
{
    fill_loop(checked_base(_First), checked_base(_Last), _Val);
}
template <class I, class O> inline O backward_scalar(I _First, I _Last, O _Dest, RandomTag, ScalarTag, RangeTag)
{
    int _Count = _Last - _First;
    O _Result = _Dest - _Count;
    if (_Count > 0)
        FUN_00ec7ce3(_Result, _Count * sizeof(*_First), _First, _Count * sizeof(*_First));
    return _Result;
}
template <class I, class O, class C, class M> inline O backward_dispatch(I _First, I _Last, O _Dest, C cat, M, RangeTag)
{
    return backward_scalar(_First, _Last, _Dest, cat, ptr_category(_First, _Dest), RangeTag());
}
template <class I, class O> inline O backward(I _First, I _Last, O _Dest)
{
    return backward_dispatch(checked_base(_First), checked_base(_Last), _Dest, iter_random(_First, _Dest),
                             move_category(_Dest), RangeTag());
}
struct Iterator
{
    void* owner;
    Word* pointer;
};
struct ProxyBase
{
    void* proxy;
    Allocator<void*> proxyAllocator;
};
struct VectorBase : ProxyBase
{
    Allocator<Word> _Al;
};
struct Vector : VectorBase
{
    Word* _First;
    Word* _Last;
    Word* end;
    unsigned int capacity() const
    {
        return _First == 0 ? 0 : (unsigned int)(end - _First);
    }
    unsigned int size() const
    {
        return (unsigned int)(_Last - _First);
    }
    unsigned int max_size() const
    {
        return _Al.max_size();
    }
    template <class I> Word* move(I _First, I _Last, Word* _Dest)
    {
        return move_unchecked(_First, _Last, _Dest, _Al);
    }
    Word* fill_new(Word* _Dest, unsigned int _Count, const Word& _Val)
    {
        uninit_fill(_Dest, _Count, _Val, _Al);
        return _Dest + _Count;
    }
    void destroy(Word* _First, Word* _Last)
    {
        destroy_range(_First, _Last, _Al);
    }
    static void length_error()
    {
        throw VectorLengthError(VectorMessage("vector<T> too long"));
    }
    void FUN_00abc320(Iterator _Where, unsigned int _Count, const Word& _Val);
};
}

// @fnv 0x00abc320
void WordInsert::Vector::FUN_00abc320(Iterator _Where, unsigned int _Count, const Word& _Val)
{
    unsigned int _Capacity = capacity();
    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        length_error();
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        Word* _Newvec = _Al.allocate(_Capacity);
        Word* _Ptr = _Newvec;
        try
        {
            _Ptr = move(this->_First, _Where.pointer, _Newvec);
            _Ptr = fill_new(_Ptr, _Count, _Val);
            move(_Where.pointer, this->_Last, _Ptr);
        }
        catch (...)
        {
            destroy(_Newvec, _Ptr);
            _Al.deallocate(_Newvec, _Capacity);
            throw;
        }
        _Count += size();
        if (_First != 0)
        {
            destroy(_First, _Last);
            _Al.deallocate(_First, end - _First);
        }
        end = _Newvec + _Capacity;
        _Last = _Newvec + _Count;
        _First = _Newvec;
    }
    else if ((unsigned int)(_Last - _Where.pointer) < _Count)
    {
        Word _Tmp = _Val;
        move(_Where.pointer, _Last, _Where.pointer + _Count);
        try
        {
            fill_new(_Last, _Count - (_Last - _Where.pointer), _Tmp);
        }
        catch (...)
        {
            destroy(_Where.pointer + _Count, _Last + _Count);
            throw;
        }
        _Last += _Count;
        WordInsert::fill(_Where.pointer, _Last - _Count, _Tmp);
    }
    else
    {
        Word _Tmp = _Val;
        Word* _Oldend = _Last;
        _Last = move(_Oldend - _Count, _Oldend, _Last);
        backward(_Where.pointer, _Oldend - _Count, _Oldend);
        WordInsert::fill(_Where.pointer, _Where.pointer + _Count, _Tmp);
    }
}

extern "C" int __cdecl memcpy_s(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _MaxCount);
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
void __cdecl FUN_00ec7c56();
double __cdecl FUN_00ec6940(double);

void* __cdecl FUN_0044d670(unsigned int count, int hint);
namespace TriWriterRework {
inline void __cdecl GameFree(void* p)
{
    DAT_011f6238.Deallocate(p);
}

template <class T> inline T* Allocate(unsigned int count, T*)
{
    return (T*)FUN_0044d670(count, 0);
}

template <class T> struct Allocator
{
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef unsigned int size_type;
    typedef int difference_type;
    template <class U> struct rebind
    {
        typedef Allocator<U> other;
    };
    Allocator()
    {}
    Allocator(const Allocator&)
    {}
    template <class U> Allocator(const Allocator<U>&)
    {}
    template <class U> Allocator& operator=(const Allocator<U>&)
    {
        return *this;
    }
    void deallocate(pointer ptr, size_type)
    {
        GameFree(ptr);
    }
    pointer allocate(size_type count)
    {
        return Allocate(count, (pointer)0);
    }
    void construct(pointer ptr, const T& val);
    void destroy(pointer ptr)
    {
        ptr->~T();
    }
    size_type max_size() const
    {
        size_type count = (size_type)(-1) / sizeof(T);
        return 0 < count ? count : 1;
    }
};

struct ContainerBaseAux;
struct AuxCont
{
    explicit AuxCont(const ContainerBaseAux* const cont) : mycontainer(cont)
    {}
    const ContainerBaseAux* mycontainer;
};
struct ContainerBaseAux
{
    ContainerBaseAux()
    {}
    ~ContainerBaseAux()
    {}
    AuxCont* myownedaux;
};
template <class A> struct ContainerBaseAuxAlloc : ContainerBaseAux
{
    explicit ContainerBaseAuxAlloc(A al) : alaux(al)
    {
        myownedaux = new (alaux.allocate(1)) AuxCont(this);
    }
    ~ContainerBaseAuxAlloc()
    {
        myownedaux->~AuxCont();
        alaux.deallocate(myownedaux, 1);
    }
    typename A::template rebind<AuxCont>::other alaux;
};

struct ScalarPtrTag
{
};
template <class T> inline ScalarPtrTag PtrCat(T*&, T*&)
{
    ScalarPtrTag cat;
    return cat;
}
template <class T, class A> inline void DestroyRange(T*, T*, A&, ScalarPtrTag)
{}
template <class T, class A> inline void DestroyRange(T* first, T* last, A& al)
{
    DestroyRange(first, last, al, PtrCat(first, last));
}
void __cdecl XLength();

template <class T, class A> struct WriterVectorVal : ContainerBaseAuxAlloc<A>
{
    WriterVectorVal(A al = A()) : ContainerBaseAuxAlloc<A>(al), alval(al)
    {}
    typename A::template rebind<T>::other alval;
};

template <class T, class A = Allocator<T> > struct Vector : WriterVectorVal<T, A>
{
    typedef unsigned int size_type;
    explicit Vector(size_type count) : WriterVectorVal<T, A>()
    {
        ConstructN(count, T());
    }
    ~Vector()
    {
        Tidy();
    }
    void ConstructN(size_type count, const T& val)
    {
        if (Buy(count))
        {
            try
            {
                mylast = Ufill(myfirst, count, val);
            }
            catch (...)
            {
                Tidy();
                throw;
            }
        }
    }
    size_type size() const
    {
        return mylast - myfirst;
    }
    size_type max_size() const
    {
        return this->alval.max_size();
    }
    const T& operator[](size_type pos) const
    {
        {
            if (!(pos < size()))
            {
                {
                    FUN_00ec7c56();
                }
            }
        }
        return *(myfirst + pos);
    }
    T& operator[](size_type pos)
    {
        {
            if (!(pos < size()))
            {
                {
                    FUN_00ec7c56();
                }
            }
        }
        return *(myfirst + pos);
    }
    bool Buy(size_type capacity)
    {
        myfirst = 0, mylast = 0, myend = 0;
        if (capacity == 0)
            return false;
        else if (max_size() < capacity)
            XLength();
        else
        {
            myfirst = this->alval.allocate(capacity);
            mylast = myfirst;
            myend = myfirst + capacity;
        }
        return true;
    }
    void Destroy(T* first, T* last)
    {
        DestroyRange(first, last, this->alval);
    }
    void Tidy()
    {
        if (myfirst != 0)
        {
            Destroy(myfirst, mylast);
            this->alval.deallocate(myfirst, myend - myfirst);
        }
        myfirst = 0, mylast = 0, myend = 0;
    }
    T* Ufill(T* ptr, size_type count, const T& val);
    T* myfirst;
    T* mylast;
    T* myend;
};

namespace TriWriterTypes {
struct SecureCharTraitsTag
{
};
template <class E> struct char_traits;
template <> struct char_traits<char>
{
    typedef char char_type;
    typedef SecureCharTraitsTag SecureCharTraits;
    static void assign(char& left, const char& right)
    {
        left = right;
    }
    static unsigned int length(const char* first)
    {
        return ::strlen(first);
    }
    static char* CopyS(char* first1, unsigned int sizeInBytes, const char* first2, unsigned int count)
    {
        ::memcpy_s(first1, sizeInBytes, first2, count);
        return first1;
    }
    static char* MoveS(char* first1, unsigned int sizeInBytes, const char* first2, unsigned int count)
    {
        ::memmove_s(first1, sizeInBytes, first2, count);
        return first1;
    }
};
template <class Tr> inline typename Tr::SecureCharTraits CharTraitsCat()
{
    typename Tr::SecureCharTraits secure;
    return secure;
}
template <class Tr>
inline typename Tr::char_type* TraitsCopyS(typename Tr::char_type* first1, unsigned int size,
                                           const typename Tr::char_type* first2, unsigned int count,
                                           SecureCharTraitsTag)
{
    return Tr::CopyS(first1, size, first2, count);
}
template <class Tr>
inline typename Tr::char_type* TraitsCopyS(typename Tr::char_type* first1, unsigned int size,
                                           const typename Tr::char_type* first2, unsigned int count)
{
    return TraitsCopyS<Tr>(first1, size, first2, count, CharTraitsCat<Tr>());
}
template <class Tr>
inline typename Tr::char_type* TraitsMoveS(typename Tr::char_type* first1, unsigned int size,
                                           const typename Tr::char_type* first2, unsigned int count,
                                           SecureCharTraitsTag)
{
    return Tr::MoveS(first1, size, first2, count);
}
template <class Tr>
inline typename Tr::char_type* TraitsMoveS(typename Tr::char_type* first1, unsigned int size,
                                           const typename Tr::char_type* first2, unsigned int count)
{
    return TraitsMoveS<Tr>(first1, size, first2, count, CharTraitsCat<Tr>());
}

template <class T> class allocator
{
  public:
    typedef T value_type;
    typedef T* pointer;
    typedef unsigned int size_type;
    template <class U> struct rebind
    {
        typedef allocator<U> other;
    };
    allocator()
    {}
    allocator(const allocator&)
    {}
    template <class U> allocator(const allocator<U>&)
    {}
    void deallocate(pointer ptr, size_type)
    {
        GameFree(ptr);
    }
    pointer allocate(size_type count)
    {
        return Allocate(count, (pointer)0);
    }
    size_type max_size() const
    {
        size_type count = (size_type)(-1) / sizeof(T);
        return 0 < count ? count : 1;
    }
};

struct ContainerBaseSecure
{
};
struct StringBase : ContainerBaseSecure
{
    static void Xlen();
    static void Xran();
};
template <class T, class A> struct StringVal : StringBase
{
    typedef typename A::template rebind<T>::other Alty;
    StringVal(Alty al = Alty()) : alval(al)
    {}
    Alty alval;
};

class FUN_0044a4c0 : public StringVal<char, allocator<char> >
{
  public:
    typedef char E;
    typedef char_traits<char> Tr;
    typedef allocator<char> A;
    typedef FUN_0044a4c0 Myt;
    typedef StringVal<E, A> Mybase;
    typedef unsigned int size_type;
    enum
    {
        BUF_SIZE = 16,
        ALLOC_MASK = 15
    };
    static const size_type npos = (size_type)(-1);

    FUN_0044a4c0(const E* ptr) : Mybase()
    {
        Tidy();
        assign(ptr);
    }
    ~FUN_0044a4c0()
    {
        Tidy(true);
    }

    Myt& assign(const Myt& right, size_type roff, size_type count)
    {
        if (right.size() < roff)
            StringBase::Xran();
        size_type num = right.size() - roff;
        if (count < num)
            num = count;
        if (this == &right)
            erase((size_type)(roff + num)), erase(0, roff);
        else if (Grow(num))
        {
            TraitsCopyS<Tr>(Myptr(), myres, right.Myptr() + roff, num);
            Eos(num);
        }
        return *this;
    }
    Myt& assign(const E* ptr, size_type count)
    {
        if (Inside(ptr))
            return assign(*this, ptr - Myptr(), count);
        if (Grow(count))
        {
            TraitsCopyS<Tr>(Myptr(), myres, ptr, count);
            Eos(count);
        }
        return *this;
    }
    Myt& assign(const E* ptr)
    {
        return assign(ptr, Tr::length(ptr));
    }
    Myt& erase(size_type off = 0, size_type count = npos)
    {
        if (mysize < off)
            StringBase::Xran();
        if (mysize - off < count)
            count = mysize - off;
        if (0 < count)
        {
            TraitsMoveS<Tr>(Myptr() + off, myres - off, Myptr() + off + count, mysize - off - count);
            size_type newsize = mysize - count;
            Eos(newsize);
        }
        return *this;
    }
    const E& operator[](size_type off) const
    {
        {
            if (!(off <= mysize))
            {
                {
                    FUN_00ec7c56();
                }
            }
        }
        return Myptr()[off];
    }
    size_type size() const
    {
        return mysize;
    }
    size_type max_size() const
    {
        size_type num = this->alval.max_size();
        return num <= 1 ? 1 : num - 1;
    }
    void Copy(size_type newsize, size_type oldlen)
    {
        size_type newres = newsize | ALLOC_MASK;
        if (max_size() < newres)
            newres = newsize;
        else if (newres / 3 < myres / 2 && myres <= max_size() - myres / 2)
            newres = myres + myres / 2;
        E* ptr = 0;
        try
        {
            ptr = this->alval.allocate(newres + 1);
        }
        catch (...)
        {
            newres = newsize;
            try
            {
                ptr = this->alval.allocate(newres + 1);
            }
            catch (...)
            {
                Tidy(true);
                throw;
            }
        }
        if (0 < oldlen)
            TraitsCopyS<Tr>(ptr, newres + 1, Myptr(), oldlen);
        Tidy(true);
        bx.ptr = ptr;
        myres = newres;
        Eos(oldlen);
    }
    void Eos(size_type newsize)
    {
        Tr::assign(Myptr()[mysize = newsize], E());
    }
    bool Grow(size_type newsize, bool trim = false)
    {
        if (max_size() < newsize)
            StringBase::Xlen();
        if (myres < newsize)
            Copy(newsize, mysize);
        else if (trim && newsize < BUF_SIZE)
            Tidy(true, newsize < mysize ? newsize : mysize);
        else if (newsize == 0)
            Eos(0);
        return 0 < newsize;
    }
    bool Inside(const E* ptr)
    {
        if (ptr == 0 || ptr < Myptr() || Myptr() + mysize <= ptr)
            return false;
        else
            return true;
    }
    void Tidy(bool built = false, size_type newsize = 0)
    {
        if (!built)
            ;
        else if (BUF_SIZE <= myres)
        {
            E* ptr = bx.ptr;
            if (0 < newsize)
                TraitsCopyS<Tr>(bx.buf, BUF_SIZE, ptr, newsize);
            this->alval.deallocate(ptr, myres + 1);
        }
        myres = BUF_SIZE - 1;
        Eos(newsize);
    }
    E* Myptr()
    {
        return BUF_SIZE <= myres ? bx.ptr : bx.buf;
    }
    const E* Myptr() const
    {
        return BUF_SIZE <= myres ? bx.ptr : bx.buf;
    }

    union Bxty
    {
        E buf[BUF_SIZE];
        E* ptr;
    } bx;
    size_type mysize;
    size_type myres;
};
}
typedef TriWriterTypes::FUN_0044a4c0 WriterString;

void __cdecl ReportError(int code, WriterString msg);

struct V3
{
    float x, y, z;
};
struct E0
{
    int a, b, c;
};
struct E30
{
    int a, b, c, d;
};
struct E48
{
    int a, b;
};
struct E90
{
    int id;
    WriterString name;
};
struct EA8
{
    int id;
    V3 pos;
    WriterString name;
};
struct EC0
{
    WriterString name;
    Vector<V3> verts;
};
struct ED8
{
    WriterString name;
    int unk1C;
    Vector<int> idx;
};

struct Tri : Vector<E0>
{
    Vector<E0> v18;
    Vector<E30> v30;
    Vector<E48> v48;
    Vector<E0> v60;
    Vector<E30> v78;
    Vector<E90> v90;
    Vector<EA8> va8;
    Vector<EC0> vc0;
    Vector<ED8> vd8;
    unsigned int FUN_0065a5a0() const;
    unsigned int FUN_0065a5a0()
    {
        unsigned int n = size();
        for (unsigned int i = 0; i < vd8.size(); i++)
            if (vd8[i].unk1C < n)
                n = vd8[i].unk1C;
        return n;
    }
};
typedef Vector<char> Buf;

struct Writer
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual bool Write(const void* p, unsigned int size, unsigned int count);
    bool FUN_00ac5220(const void* p, unsigned int size, unsigned int count);
};

}
// @fnv 0x00ab7f40
bool __cdecl FUN_00ab7f40(TriWriterRework::Writer* w, TriWriterRework::Tri* t)
{
    using namespace TriWriterRework;
    union
    {
        unsigned int counts[14];
        unsigned char bytes[56];
    } hdr;
    unsigned int total;
    unsigned int el;
    fnv_zlib_memset(hdr.bytes, 0, 0x38);
    hdr.counts[0] = t->FUN_0065a5a0();
    hdr.counts[1] = t->v18.size();
    hdr.counts[2] = t->v30.size();
    hdr.counts[3] = t->v90.size();
    hdr.counts[4] = t->va8.size();
    hdr.counts[7] = t->vc0.size();
    hdr.counts[8] = t->vd8.size();
    hdr.counts[9] = t->size() - ((const Tri*)t)->FUN_0065a5a0();
    if (t->v48.size() == hdr.counts[0] && t->v60.size() == 0 && t->v78.size() == 0)
    {
        hdr.counts[6] |= 1;
        hdr.counts[5] = 0;
    }
    else if (t->v48.size() != 0 && t->v60.size() == hdr.counts[1] && t->v78.size() == hdr.counts[2])
    {
        hdr.counts[6] |= 1;
        hdr.counts[5] = t->v48.size();
    }
    else
    {
        hdr.counts[6] &= ~1;
        hdr.counts[5] = 0;
    }
    if (!w->FUN_00ac5220(hdr.bytes, 0x38, 1))
        return false;
    if (hdr.counts[0] + hdr.counts[9] != 0 && !w->Write(&(*t)[0], 12, hdr.counts[0] + hdr.counts[9]))
        return false;
    if (hdr.counts[1] != 0 && !w->Write(&t->v18[0], 12, hdr.counts[1]))
        return false;
    if (hdr.counts[2] != 0 && !w->Write(&t->v30[0], 16, hdr.counts[2]))
        return false;
    for (el = 0; el < hdr.counts[3]; el++)
    {
        if (!w->Write(&t->v90[el].id, 4, 1))
            return false;
        unsigned int n11 = t->v90[el].name.size() + 1;
        if (!w->Write(&n11, 4, 1))
            return false;
        Buf bufferA(n11);
        for (unsigned int j = 0; j < n11 - 1; j++)
            bufferA[j] = t->v90[el].name[j];
        bufferA[n11 - 1] = 0;
        if (!w->Write(&bufferA[0], 1, n11))
        {
            return false;
        }
    }
    for (el = 0; el < hdr.counts[4]; el++)
    {
        if (!w->Write(&t->va8[el].id, 4, 1))
            return false;
        if (!w->Write(&t->va8[el].pos, 12, 1))
            return false;
        unsigned int n11 = t->va8[el].name.size() + 1;
        if (!w->Write(&n11, 4, 1))
            return false;
        Buf bufferA(n11);
        for (unsigned int j = 0; j < n11 - 1; j++)
            bufferA[j] = t->va8[el].name[j];
        bufferA[n11 - 1] = 0;
        if (!w->Write(&bufferA[0], 1, n11))
        {
            return false;
        }
    }
    if (hdr.counts[6] & 1)
    {
        if (hdr.counts[5] == 0)
        {
            if (!w->Write(&t->v48[0], 8, hdr.counts[0]))
                return false;
        }
        else
        {
            if (!w->Write(&t->v48[0], 8, hdr.counts[5]))
                return false;
            if (!w->Write(&t->v60[0], 12, hdr.counts[1]))
                return false;
            if (!w->Write(&t->v78[0], 16, hdr.counts[2]))
                return false;
        }
    }
    for (el = 0; el < hdr.counts[7]; el++)
    {
        unsigned int n11 = t->vc0[el].name.size() + 1;
        if (!w->Write(&n11, 4, 1))
            return false;
        Buf bufferA(n11);
        for (unsigned int j = 0; j < n11 - 1; j++)
            bufferA[j] = t->vc0[el].name[j];
        bufferA[n11 - 1] = 0;
        {
            if (!w->Write(&bufferA[0], 1, n11))
            {
                return false;
            }
        }
        float scale = 0.0f;
        unsigned int k;
        for (k = 0; k < hdr.counts[0]; k++)
        {
            if (scale < fabs(t->vc0[el].verts[k].x))
                scale = fabs(t->vc0[el].verts[k].x);
            if (scale < fabs(t->vc0[el].verts[k].y))
                scale = fabs(t->vc0[el].verts[k].y);
            if (scale < fabs(t->vc0[el].verts[k].z))
                scale = fabs(t->vc0[el].verts[k].z);
        }
        scale = scale / 32767.0;
        if (!w->Write(&scale, 4, 1))
            return false;
        scale = 1.0f / scale;
        for (k = 0; k < hdr.counts[0]; k++)
        {
            short s[3];
            s[0] = (short)FUN_00ec6940(t->vc0[el].verts[k].x * scale + 0.5);
            s[1] = (short)FUN_00ec6940(t->vc0[el].verts[k].y * scale + 0.5);
            s[2] = (short)FUN_00ec6940(t->vc0[el].verts[k].z * scale + 0.5);
            if (!w->Write(s, 2, 3))
                return false;
        }
    }
    total = 0;
    for (el = 0; el < hdr.counts[8]; el++)
    {
        unsigned int n11 = t->vd8[el].name.size() + 1;
        if (!w->Write(&n11, 4, 1))
            return false;
        Buf bufferA(n11);
        for (unsigned int j = 0; j < n11 - 1; j++)
            bufferA[j] = t->vd8[el].name[j];
        bufferA[n11 - 1] = 0;
        {
            if (!w->Write(&bufferA[0], 1, n11))
            {
                return false;
            }
        }
        n11 = t->vd8[el].idx.size();
        if (!w->Write(&n11, 4, 1))
            return false;
        if (n11 != 0 && !w->Write(&t->vd8[el].idx[0], 4, n11))
            return false;
        total += n11;
    }
    if (total != hdr.counts[9])
    {
        ReportError(0xb, WriterString("Invalid morph data during TRI file save."));
        return false;
    }
    return true;
}

extern unsigned int DAT_010173f0;
extern char DAT_010a2d3c;
extern void* DAT_010a2c38;
void FUN_00ec7c56();
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" int __cdecl memcpy_s(void*, unsigned int, const void*, unsigned int);
extern "C" int __cdecl memmove_s(void*, unsigned int, const void*, unsigned int);
extern MemoryManager DAT_011f6238;
void* __cdecl FUN_0044d670(unsigned int, int);
inline void __cdecl GameFree(void* p)
{
    DAT_011f6238.Deallocate(p);
}
namespace ImageReaderTypes {
struct SecureCharTraitsTag
{
};
template <class E> struct char_traits;
template <> struct char_traits<char>
{
    typedef char char_type;
    typedef SecureCharTraitsTag SecureCharTraits;
    static void assign(char& left, const char& right)
    {
        left = right;
    }
    static unsigned int length(const char* first)
    {
        return ::strlen(first);
    }
    static char* CopyS(char* first1, unsigned int sizeInBytes, const char* first2, unsigned int count)
    {
        ::memcpy_s(first1, sizeInBytes, first2, count);
        return first1;
    }
    static char* MoveS(char* first1, unsigned int sizeInBytes, const char* first2, unsigned int count)
    {
        ::memmove_s(first1, sizeInBytes, first2, count);
        return first1;
    }
};
template <class Tr> inline typename Tr::SecureCharTraits CharTraitsCat()
{
    typename Tr::SecureCharTraits secure;
    return secure;
}
template <class Tr>
inline typename Tr::char_type* TraitsCopyS(typename Tr::char_type* first1, unsigned int size,
                                           const typename Tr::char_type* first2, unsigned int count,
                                           SecureCharTraitsTag)
{
    return Tr::CopyS(first1, size, first2, count);
}
template <class Tr>
inline typename Tr::char_type* TraitsCopyS(typename Tr::char_type* first1, unsigned int size,
                                           const typename Tr::char_type* first2, unsigned int count)
{
    return TraitsCopyS<Tr>(first1, size, first2, count, CharTraitsCat<Tr>());
}
template <class Tr>
inline typename Tr::char_type* TraitsMoveS(typename Tr::char_type* first1, unsigned int size,
                                           const typename Tr::char_type* first2, unsigned int count,
                                           SecureCharTraitsTag)
{
    return Tr::MoveS(first1, size, first2, count);
}
template <class Tr>
inline typename Tr::char_type* TraitsMoveS(typename Tr::char_type* first1, unsigned int size,
                                           const typename Tr::char_type* first2, unsigned int count)
{
    return TraitsMoveS<Tr>(first1, size, first2, count, CharTraitsCat<Tr>());
}

template <class T> class allocator
{
  public:
    typedef T value_type;
    typedef T* pointer;
    typedef unsigned int size_type;
    template <class U> struct rebind
    {
        typedef allocator<U> other;
    };
    allocator()
    {}
    allocator(const allocator&)
    {}
    template <class U> allocator(const allocator<U>&)
    {}
    void deallocate(pointer ptr, size_type)
    {
        GameFree(ptr);
    }
    pointer allocate(size_type count)
    {
        return Allocate(count, (pointer)0);
    }
    size_type max_size() const
    {
        size_type count = (size_type)(-1) / sizeof(T);
        return 0 < count ? count : 1;
    }
};

struct ContainerBaseSecure
{
};
struct StringBase : ContainerBaseSecure
{
    static void Xlen();
    static void Xran();
};
template <class T, class A> struct StringVal : StringBase
{
    typedef typename A::template rebind<T>::other Alty;
    StringVal(Alty al = Alty()) : alval(al)
    {}
    StringVal(const StringVal& other) : alval(other.alval)
    {}
    Alty alval;
};

template <class E, class Tr, class A> class basic_string : public StringVal<E, A>
{
  public:
    typedef basic_string<E, Tr, A> Myt;
    typedef StringVal<E, A> Mybase;
    typedef unsigned int size_type;
    enum
    {
        BUF_SIZE = 16,
        ALLOC_MASK = 15
    };
    static const size_type npos = (size_type)(-1);

    basic_string(const Myt& other) : Mybase(other)
    {
        _Tidy();
        assign(other, 0, DAT_010173f0);
    }
    basic_string(const E* ptr) : Mybase()
    {
        _Tidy();
        assign(ptr);
    }
    ~basic_string()
    {
        _Tidy(true);
    }

    Myt& assign(const Myt& right, size_type roff, size_type count)
    {
        if (right.size() < roff)
            StringBase::Xran();
        size_type num = right.size() - roff;
        if (count < num)
            num = count;
        if (this == &right)
            erase((size_type)(roff + num)), erase(0, roff);
        else if (Grow(num))
        {
            TraitsCopyS<Tr>(Myptr(), myres, right.Myptr() + roff, num);
            Eos(num);
        }
        return *this;
    }
    Myt& assign(const E* ptr, size_type count)
    {
        if (Inside(ptr))
            return assign(*this, ptr - Myptr(), count);
        if (Grow(count))
        {
            TraitsCopyS<Tr>(Myptr(), myres, ptr, count);
            Eos(count);
        }
        return *this;
    }
    Myt& assign(const E* ptr)
    {
        return assign(ptr, Tr::length(ptr));
    }
    Myt& erase(size_type off = 0, size_type count = npos)
    {
        if (mysize < off)
            StringBase::Xran();
        if (mysize - off < count)
            count = mysize - off;
        if (0 < count)
        {
            TraitsMoveS<Tr>(Myptr() + off, myres - off, Myptr() + off + count, mysize - off - count);
            size_type newsize = mysize - count;
            Eos(newsize);
        }
        return *this;
    }
    const E& operator[](size_type off) const
    {
        {
            if (!(off <= mysize))
            {
                {
                    FUN_00ec7c56();
                }
            }
        }
        return Myptr()[off];
    }
    size_type size() const
    {
        return mysize;
    }
    size_type max_size() const
    {
        size_type num = this->alval.max_size();
        return num <= 1 ? 1 : num - 1;
    }
    void Copy(size_type newsize, size_type oldlen)
    {
        size_type newres = newsize | ALLOC_MASK;
        if (max_size() < newres)
            newres = newsize;
        else if (newres / 3 < myres / 2 && myres <= max_size() - myres / 2)
            newres = myres + myres / 2;
        E* ptr = 0;
        try
        {
            ptr = this->alval.allocate(newres + 1);
        }
        catch (...)
        {
            newres = newsize;
            try
            {
                ptr = this->alval.allocate(newres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < oldlen)
            TraitsCopyS<Tr>(ptr, newres + 1, Myptr(), oldlen);
        _Tidy(true);
        bx.ptr = ptr;
        myres = newres;
        Eos(oldlen);
    }
    void Eos(size_type newsize)
    {
        Tr::assign(Myptr()[mysize = newsize], E());
    }
    bool Grow(size_type newsize, bool trim = false)
    {
        if (max_size() < newsize)
            StringBase::Xlen();
        if (myres < newsize)
            Copy(newsize, mysize);
        else if (trim && newsize < BUF_SIZE)
            _Tidy(true, newsize < mysize ? newsize : mysize);
        else if (newsize == 0)
            Eos(0);
        return 0 < newsize;
    }
    bool Inside(const E* ptr)
    {
        if (ptr == 0 || ptr < Myptr() || Myptr() + mysize <= ptr)
            return false;
        else
            return true;
    }
    void _Tidy(bool built = false, size_type newsize = 0);
    E* Myptr()
    {
        return BUF_SIZE <= myres ? bx.ptr : bx.buf;
    }
    const E* Myptr() const
    {
        return BUF_SIZE <= myres ? bx.ptr : bx.buf;
    }

    union Bxty
    {
        E buf[BUF_SIZE];
        E* ptr;
    } bx;
    size_type mysize;
    size_type myres;
};
}
typedef ImageReaderTypes::basic_string<char, ImageReaderTypes::char_traits<char>, ImageReaderTypes::allocator<char> >
    ReaderString;

namespace ImageReaderTypes {
struct FUN_00aaaa80
{
    virtual ~FUN_00aaaa80();
    ReaderString name;
    ReaderString path;
    unsigned int unk3c;
};
}
struct VirtualFile
{
    virtual ~VirtualFile();
};
struct LoadedFile
{
    void FUN_0044b180();
};
struct FUN_00ac5490 : ImageReaderTypes::FUN_00aaaa80
{
    FUN_00ac5490(ReaderString);
    VirtualFile* unk40;
    LoadedFile* unk44;

    bool FUN_00ac5540(ReaderString, int);
    bool FUN_00ac5e00(void*, unsigned int, unsigned int);
    bool FUN_00ac5cf0(void*, unsigned int, unsigned int);
    inline void ClearHolders()
    {
        if (unk44)
        {
            unk40 = 0;
            unk44->FUN_0044b180();
            unk44 = 0;
        }
        else
        {
            delete unk40;
            unk40 = 0;
        }
    }
    virtual inline ~FUN_00ac5490()
    {
        ClearHolders();
    }
};

struct TextureChannel
{
    unsigned int unk00, unk04, unk08;
    unsigned char* first;
    unsigned char* last;
    unsigned char* end;
    ~TextureChannel();
    void FUN_00ab2f50(unsigned int, unsigned char);
    inline void resize(unsigned int n)
    {
        FUN_00ab2f50(n, 0);
    }
    unsigned char* FUN_0065cc70(unsigned int);
    inline unsigned int count() const
    {
        return (unsigned int)(last - first);
    }
    inline unsigned char& operator[](unsigned int i)
    {
        {
            if (!(i < count()))
            {
                {
                    FUN_00ec7c56();
                }
            }
        }
        do
        {
        } while (0);
        return first[i];
    }
};
namespace Match {
struct FUN_00ab2e40
{
    unsigned int id, m4, m8, mC;
    TextureChannel m10[3];
    FUN_00ab2e40();
    FUN_00ab2e40(const FUN_00ab2e40&);
};
}
typedef Match::FUN_00ab2e40 ImageRecord;
struct Images
{
    unsigned int unk00, unk04, unk08;
    ImageRecord* first;
    ImageRecord* last;
    ImageRecord* end;
    struct Iterator
    {
        Images* owner;
        ImageRecord* ptr;
        inline Iterator(ImageRecord* p, Images* o) : owner(o), ptr(p)
        {}
        inline Iterator(const Iterator& other) : owner(other.owner), ptr(other.ptr)
        {}
    };
    inline Iterator CallWithSelf()
    {
        return Iterator(last, this);
    }
    inline Iterator FUN_0044a170()
    {
        return Iterator(first, this);
    }
    struct ConstIterator
    {
        Images* owner;
        const ImageRecord* ptr;
        inline ConstIterator(const Iterator& other) : owner(other.owner), ptr(other.ptr)
        {}
    };
    Iterator BuildAndComparePair(ConstIterator, ConstIterator);
    inline void FUN_0065cef0()
    {
        BuildAndComparePair(FUN_0044a170(), CallWithSelf());
    }
    void FUN_00ab3130(unsigned int, ImageRecord);
    inline void resize(unsigned int n)
    {
        FUN_00ab3130(n, ImageRecord());
    }
    inline unsigned int count() const
    {
        return (unsigned int)(last - first);
    }
    inline ImageRecord& operator[](unsigned int i)
    {
        {
            if (!(i < count()))
            {
                {
                    FUN_00ec7c56();
                }
            }
        }
        do
        {
        } while (0);
        return first[i];
    }
};
struct ImageHeader
{
    unsigned int height, width, count1, count2, format;
    unsigned int unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    void FUN_00ab2630();
};
// @fnv 0x00ab2640
bool __cdecl FUN_00ab2640(const ReaderString& filename, unsigned int* format, Images* first, Images* second)
{
    FUN_00ac5490 stream3((ReaderString(&DAT_010a2d3c)));
    if (!stream3.FUN_00ac5540(filename, 0))
        return false;
    ImageHeader kHeader;
    if (!stream3.FUN_00ac5e00(&kHeader, 1, 56))
        return false;
    kHeader.FUN_00ab2630();
    *format = kHeader.format;
    first->FUN_0065cef0();
    second->FUN_0065cef0();
    unsigned int stride6 = 1;
    unsigned int padding3 = ((kHeader.width * stride6 + 7) & ~7u) / stride6 - kHeader.width;
    unsigned int rowSize = kHeader.width + padding3;
    unsigned int size7 = rowSize * kHeader.height;
    first->resize(kHeader.count1);
    unsigned int i3, j2, k;
    for (i3 = 0; i3 < kHeader.count1; i3++)
    {
        if (!stream3.FUN_00ac5cf0(&(*first)[i3], 4, 1))
            return false;
        (*first)[i3].m4 = kHeader.width;
        (*first)[i3].m8 = kHeader.height;
        (*first)[i3].mC = padding3;
        for (j2 = 0; j2 < 3; j2++)
        {
            ((TextureChannel&)(*first)[i3].m10[j2]).resize(size7);
            unsigned char* row = &((TextureChannel&)(*first)[i3].m10[j2])[size7 - rowSize];
            for (k = 0; k < kHeader.height; k++)
            {
                if (!stream3.FUN_00ac5cf0(row, stride6, kHeader.width))
                    return false;
                row -= kHeader.width + padding3;
            }
        }
    }
    second->resize(kHeader.count2);
    for (i3 = 0; i3 < kHeader.count2; i3++)
    {
        if (!stream3.FUN_00ac5cf0(&(*second)[i3], 4, 1))
            return false;
        (*second)[i3].m4 = kHeader.width;
        (*second)[i3].m8 = kHeader.height;
        (*second)[i3].mC = padding3;
        for (j2 = 0; j2 < 3; j2++)
        {
            ((TextureChannel&)(*second)[i3].m10[j2]).resize(size7);
            unsigned char* row = ((TextureChannel&)(*second)[i3].m10[j2]).FUN_0065cc70(size7 - rowSize);
            for (k = 0; k < kHeader.height; k++)
            {
                if (!stream3.FUN_00ac5cf0(row, stride6, kHeader.width))
                    return false;
                row -= kHeader.width + padding3;
            }
        }
    }
    return true;
}
