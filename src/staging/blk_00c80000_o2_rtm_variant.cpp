// src/staging/blk_00c80000_o2_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00c80000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/staging/blk_00c80000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
extern int DAT_010c53dc;
extern int DAT_01267e60;
struct FUN_00c6c290_holder
{
    void FUN_00c6c290();
};
struct FUN_00c81550_holder
{
    void FUN_00c81550();
};
void* __cdecl FUN_00c81c50(void*);
float FUN_00c82580(void* arg);
extern int DAT_011b09d8[];
void __cdecl FUN_00c84cd0(int aiIndex, void* apOut);
struct bhkRefObject
{
    void UpdateReference(bool);
};
struct bhkBoxShape
{
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    void* m_next;
    void FUN_00c84e50(bool b);
};
struct NiStream;
struct NiObject
{
    virtual void LinkObject(NiStream&);
};
struct FUN_00c87670_Class : NiObject
{
    void FUN_00c87670(NiStream& stream);
    void* m_pad_0x4;
    void* m_pad_0x8;
    void* m_field_0xc;
};
extern "C" void __cdecl operator delete(void*, unsigned int);
struct FUN_00c88a20_cls
{
    void __thiscall FUN_00c88930();
    void* __thiscall FUN_00c88a20(unsigned int flags);
};
struct FUN_00cf4ce0_cls
{
    void FUN_00cf4ce0(int* arg);
};
struct FUN_00c8aa40_cls
{
    int* m_p0;
    int* m_p4;
    int* m_p8;
    void FUN_00c8aa40(int* arg);
};
char FUN_00c8cce0(int* piValue);
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
void FUN_00c8cd00(void* apBlock);
struct FUN_00c9a6e0_struct
{
    void FUN_00c9a6e0();
};
struct FUN_00c9a820_class
{
    void Reset();
};
void __cdecl FUN_00c9ad60();
void __cdecl _delete(void* ptr, unsigned int size);
struct FUN_00c9af20_class
{
    void FUN_00c9ad60();
    void* FUN_00c9af20(int flag);
};
extern int DAT_010c53b4;
extern void(__stdcall* DAT_010c53bc)(int*);
struct FUN_00c80630_holder
{
    int* m_vtbl;
    int* m_p4;
    int* m_p8;
    int* m_pc;
    void ResetHolder();
};
struct FUN_00c81640_cls
{
    void* __thiscall FUN_00c81640(bool flag);
};
struct NiPoint3
{
    float x, y, z;
};
extern NiPoint3 DAT_011a9490;
int __stdcall FUN_00c84ec0(void* apObject);
extern "C" void __stdcall EnterCriticalSection(void*);
extern int DAT_0126813c;
extern void* g_pEnterCriticalSection;
void FUN_00c876f0();
extern int DAT_010c69f4;
struct FUN_00c6aca0_holder
{
    void* __thiscall FUN_00c6aca0();
};
struct FUN_00c9a040_cls
{
    void* __thiscall FUN_00c9a040(bool b);
};
__forceinline int Sign_00c9a070(float f)
{
    return f < 0.0f ? -1 : 1;
}
struct Range_00c9a070
{
    float fHi;
    float fLo;
    Range_00c9a070(float h, float l) : fHi(h), fLo(l)
    {}
};
__forceinline void Adjust_00c9a070(float& out, float v, float fHi, float fLo)
{
    Range_00c9a070 r(fHi, fLo);
    float s = (float)Sign_00c9a070(v);
    float t = v + (r.fHi - r.fLo) * s;
    if (t * s > 0.0f)
        out -= t;
}
struct FUN_00c9a070_shell
{
    char _pad0[0xa0];
    float fLo[3];
    char _padac[0x14];
    float fHi[3];
    void AdjustVector(float* p);
};
extern int DAT_010c6b04;
extern "C" void __cdecl NiFree(void*);
struct FUN_00c9ae80_class
{
    void* m_p0;
    void* m_p4;
    void* __thiscall FUN_00c9ae80(unsigned char b);
};
struct FUN_00c80660_t
{
    int* m_p0;
    int* m_p4;
    int* m_p8;
    int* m_pc;
    void* __thiscall FUN_00c80660(bool b);
};
struct FUN_00c9aeb0_t
{
    char m_data[0x5c];
    FUN_00c9aeb0_t();
    ~FUN_00c9aeb0_t();
    static void* operator new(unsigned int);
};
FUN_00c9aeb0_t* FUN_00c9b020();
struct FUN_00c9eba0_IFace
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
    virtual void FUN_00c9eba0_call(int a, int b, int c, int d);
};
struct ScriptX
{
    void GetLocalData();
    void InvokeInterfaceCall(int a, int b, int c, int d);
};
extern int DAT_0126820c;
extern void(__stdcall* DAT_0126820c_enter)(int*);
extern void(__stdcall* DAT_0126820c_leave)(int*);
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};
struct FUN_00c6b910 : A51BF0Base
{
    FUN_00c6b910();
};
struct bhkBlendCollisionObject : FUN_00c6b910
{
    void* m_vtbl;
    unsigned char m_pad_04[8];
    unsigned short m_flags;
    unsigned char m_pad_0e[6];
    unsigned char m_flag14;
    unsigned char m_pad_15[3];
    float m_f18;
    float m_f1c;
    int m_i20;
    int m_i24;
    int m_i28;

    void __thiscall FUN_00c657f0(void* p, int value);

    bhkBlendCollisionObject()
    {
        m_vtbl = &DAT_010c53dc;
        ++DAT_01267e60;
        m_f18 = 0.0f;
        m_flags &= 0xfeff;
        m_f1c = 1.0f;
        m_i20 = 8;
        m_i24 = 0;
        m_i28 = 0;
        m_flag14 = 0;
    }

    bhkBlendCollisionObject* FUN_00c81670(int value);
};
struct NiGlobalStringTable
{
    static char* __cdecl AddString(char const* str);
};
extern int _data_011c16bc;
extern char* _EmptyFS;
extern char const* const g_0126817c_arg1;
struct DynCastHelper
{
    NiObject* __thiscall DynamicCast(unsigned int const* rtti);
};
int* __cdecl FUN_00c4b470(int, int, int);
struct StringHolder
{
    char* p;

    StringHolder(char const* str) : p(NiGlobalStringTable::AddString(str))
    {}

    ~StringHolder()
    {
        if (p != _EmptyFS)
        {
            InterlockedDecrement(reinterpret_cast<long*>(p - 8));
        }
    }
};
float GetFloatProperty(int aiObject, char const* apName);
struct FUN_00c85ec0_t
{
    int* m_p0;
    int* m_p4;
    int* m_p8;
    int* m_pc;
    void CallVirtualOnNestedPointer();
};
struct NiObjLB
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual void LoadBinary(NiStream& stream);
};
struct FUN_00c87650_t : NiObjLB
{
    virtual void LoadBinary(NiStream& stream);
};
extern "C" void __stdcall LeaveCriticalSection(void*);
void(__stdcall* DAT_0126813c_leave)(void*);
void FUN_00c87700();
struct FUN_00c88410_t
{
    void FUN_00caa140();
    void* __thiscall FUN_00c88410(unsigned int flags);
};
int __fastcall FUN_00c899c0(char* p, int edx);
struct FUN_00c8a7e0_t
{
    void FUN_00c8a720();
    void* FUN_00c8a7e0(bool b);
};
struct FUN_00cf4d30_holder
{
    void SetRefObject(void*);
};
struct FUN_00c8aa60_holder
{
    int* m_auiShapeKeys;
    int* m_pAuxiliaryObject;
    int* m_target;
    void FUN_00c8aa60(void* arg);
};
struct H_00c8c810
{
    void FUN_00c84e50(bool);
    void InvokeCallbacksOnEntries();
    void ReleaseReferencedObjects();
    void FUN_00c8b410(bool b);
};
extern int DAT_010c6fb0;
struct FUN_00c9d890_t
{
    int* m_p0;
    FUN_00c9d890_t(char b);
    ~FUN_00c9d890_t();
};
extern __declspec(thread) unsigned int memoryCategory;
struct ScopedMemoryCategory
{
    unsigned int previous;
    ScopedMemoryCategory() : previous(memoryCategory)
    {
        memoryCategory = 16;
    }
    ~ScopedMemoryCategory()
    {
        memoryCategory = previous;
    }
};
struct ArenaAllocator
{
    virtual void Reserved();
    virtual char* Allocate(unsigned int bytes);
};
struct ArenaMemoryManager : MemoryManager
{
    void* Allocate(unsigned int bytes);
};
struct TemporaryArena
{
    char* start;
    char* cursor;
    char* end;
    ArenaAllocator* current;
    ArenaAllocator* allocator;
    unsigned int unk14;
    ArenaAllocator* saved;
    unsigned int unk1C;
    unsigned int unk20;
    TemporaryArena();
    static void* operator new(unsigned int bytes)
    {
        return static_cast<ArenaMemoryManager*>(&g_memoryManager)->Allocate(bytes);
    }
};
struct ArenaRegistrationFlag
{
    unsigned int value;
    ArenaRegistrationFlag() : value(1)
    {}
    ArenaRegistrationFlag(const ArenaRegistrationFlag& other) : value(other.value)
    {}
};
struct ArenaRegistry
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Register(TemporaryArena*, const char*, ArenaRegistrationFlag);
};
ArenaRegistry* FUN_00cbbfc0();
void FUN_00cbb930(TemporaryArena*);
extern const char DAT_010c53c4[];
extern unsigned int DAT_01267e48;
extern "C" __declspec(dllimport) void __stdcall ArenaEnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall ArenaLeaveCriticalSection(void*);
struct ArenaOwner
{
    TemporaryArena* arena;
    char* buffer;
};
void EnsureArenaAllocated(ArenaOwner* owner);
struct FlaggedObj_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned short m_0c;
};
struct WalkNode_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual WalkNode_cls* v03();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    FlaggedObj_cls* m_1c;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    WalkNode_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};
void SetFlagRecursive(bool abSet, WalkNode_cls* node);
class AnimIdle
{
  public:
    virtual void FUN_00c80570_slot0();
    virtual void FUN_00c80570_slot1();
    long refs;
    void IncRefCount();
    void DecRefCount();
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
struct MM
{
    void Deallocate(void* mem);
};
extern MM _g_memoryManager;
struct GlobalObject_004ee810
{
    ~GlobalObject_004ee810();
};
struct FUN_00c80570_Node
{
    NiPointer<AnimIdle> key;
    FUN_00c80570_Node* next;
    void RemoveNode(const NiPointer<AnimIdle>* keyp);
};
struct SpawnedAllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};
struct SpawnedPtrArray
{
    void** m_pData;
    unsigned int m_uiCount;
    unsigned int m_uiCapacity;
};
extern "C" void _ReadWriteBarrier(void);
void* FUN_00c7fb50(void* a1);
SpawnedAllocHolder* FUN_00c85750();
void ResizeAudioStream(void* allocator, SpawnedPtrArray* arr, unsigned int growBy);
void AppendSpawnedPtr(void* a1, SpawnedPtrArray* arr);
inline void* __cdecl operator new(unsigned int, void* placement)
{
    return placement;
}
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* addend);
struct NiAllocator
{
    void* __thiscall FUN_00aa3e40(unsigned int size);
};
extern NiAllocator DAT_011f6238;
struct RefObject
{
    int unk00;
    volatile long referenceCount;
};
struct RefNode
{
    RefObject* item;
    RefNode* next;
    __forceinline RefNode(RefObject* p)
    {
        item = p;
        if (p)
            InterlockedIncrement(&p->referenceCount);
        next = 0;
    }
};
struct RefOwner
{
    RefObject* item;
    RefNode* head;
    void __thiscall FUN_006e5cc0(int* param);
    void __thiscall FUN_00c80a30(int* param);
};
struct FUN_00c80b20_item8
{
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
};
struct FUN_00c80b20_cls
{
    virtual void Slot0();
    virtual void* AllocBuffer(unsigned int count);
    virtual void FreeBuffer(void* buffer);
    FUN_00c80b20_item8* m_pBuffer;
    unsigned int m_uiLogicalSize;
    unsigned int m_iReservedSize;
    unsigned int AppendSlot();
    void CopyItems(void* dst, void* src, unsigned int count);
    void InsertItemAt(unsigned int index, FUN_00c80b20_item8& item);
};
// FUN_00c81570 : a one-line function - getter
extern int g_target_00c81570;
void* FUN_00c81570();
struct FUN_00c81580_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float m_f18;
    float m_f1C;
    int unk20;
    int m_i24;
    void FUN_00c657f0(FUN_00c81580_cls* dest, void* other);
    void FUN_00c81580(FUN_00c81580_cls* dest, void* other);
};
class C815B0Base
{
  public:
    bool IsEqual(C815B0Base* pkOther);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
class C815B0Constraint : public C815B0Base
{
  public:
    float m_fMinAngle;
    float m_fMaxAngle;

    bool FUN_00c815b0(C815B0Constraint* pkOther);
};
extern int DAT_010c53dc;
extern int DAT_01267e60;
struct FUN_00c6b910_holder
{
    void FUN_00c6b910();
};
struct FUN_00c81600_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned short m_0c;
    unsigned short unk0e;
    unsigned int unk10;
    unsigned char m_14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    float m_18;
    float m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;

    FUN_00c81600_cls* Initialize();
};
struct C819A0Range
{
    float m_fMinimum;
    float m_fMaximum;
};
extern C819A0Range g_akC819A0Ranges[];
class C819A0Primary
{
  public:
    virtual ~C819A0Primary();

    int unk04;
    int unk08;
    int unk0C;
};
class C819A0Secondary
{
  public:
    virtual ~C819A0Secondary();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_uiValue1;
};
class C819A0Object : public C819A0Primary, public C819A0Secondary
{
};
class C819A0Holder
{
  public:
    int unk00;
    int unk04;
    C819A0Object* m_pPointer;
};
class C819A0Base
{
  public:
    void Init(void* pvParam);

    int unk00;
    int unk04;
    int unk08;
    unsigned short m_usFlags;
    short unk0E;
    C819A0Holder* m_pkHolder;
    int unk14;
};
class C819A0Derived : public C819A0Base
{
  public:
    void InitFromFlags(void* pvParam);

    float m_fMinimum;
    float m_fMaximum;
};
class FUN_00c81aa0_poly
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
    virtual void v39(int a);
    int unk04;
    unsigned int m_08;
};
class FUN_00c81aa0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    FUN_00c81aa0_poly* m_10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    int m_24;
    void FUN_00c81aa0();
};
struct FUN_00c81ae0_target
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
    virtual void v39(void* arg);
};
struct FUN_00c81ae0_cls
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    FUN_00c81ae0_target* m_10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* m_24;
    unsigned int m_28;

    void FUN_00c81890();
    void InitOnce();
};
struct TreeResult_cls
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual TreeResult_cls* v0f();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int m_24;
};
struct TreeHost_cls
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
    TreeResult_cls* __thiscall FindResult(unsigned int* rtti);
};
struct TreeNode_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual TreeNode_cls* v03();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    TreeHost_cls* m_1c;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    TreeNode_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};
extern unsigned int DAT_012043f8;
void SetTreeValue(TreeNode_cls* node, unsigned int value);
extern unsigned __int64 selected_target_masks[];
void SetSelectionMask(unsigned int uiIndexA, unsigned int uiIndexB, bool bSelected);
struct NiColor
{
    float r, g, b;
    NiColor()
    {}
    NiColor(float fR, float fG, float fB) : r(fR), g(fG), b(fB)
    {}
};
extern NiColor DAT_011a9b7c;
void __cdecl GetLayerColor(unsigned int layer, NiColor& rColor);
struct ObjA
{
    unsigned char m_flag;
    unsigned char unk01[0x1b];
    void* m_p1c;
};
extern "C" unsigned char __cdecl FUN_00c84740(void* pA, void* pB);
ObjA* __stdcall FUN_00c84880(ObjA* p1, ObjA* p2, ObjA* p3);
struct ChainNode
{
    int m_00;
    int m_04;
    int m_08;
    ChainNode* m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
};
unsigned char __cdecl FUN_00c84740(int a1, int a2);
unsigned char* __stdcall FUN_00c848b0(unsigned char* pResult, int a2, ChainNode* pChainA, ChainNode* pChainB, int a5,
                                      int a6);
// FUN_00c84930: stdcall 3-arg wrapper.
//   a2->m_24 and a3->m_1c are passed to the cdecl helper FUN_00c84740,
//   the resulting byte is written through the first (out) parameter, which is returned.
unsigned char __cdecl FUN_00c84740(int a1, int a2);
struct NodeA
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
};
struct NodeB
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
};
unsigned char* __stdcall FUN_00c84930(unsigned char* pResult, NodeA* pNodeA, NodeB* pNodeB);
struct FUN_00c84dc0_param
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};
struct FUN_00c84dc0_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    bool FUN_00ba87d0(FUN_00c84dc0_param* p);
    bool FUN_00c84dc0(FUN_00c84dc0_param* p);
};
class FUN_00c84df0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int m_10;

    void FUN_00c87600(FUN_00c84df0_cls* first, FUN_00c84df0_cls* second);
    void FUN_00c84df0(FUN_00c84df0_cls* first, FUN_00c84df0_cls* second);
};
struct FUN_00c84e80_holder
{
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    void* m_next;
    int __thiscall ApplyToNext(int* arg_2);
};
extern void __cdecl FUN_00cf0690(void* object, float value, int* data);
// Target class of the first virtual call
class TargetCls
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
    virtual int v56(int a);
};
class FUN_00c84f10_cls
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
    virtual TargetCls* v51();
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int FUN_00c84f10(int a);
};
class FUN_00c84f50_cls
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual FUN_00c84f50_cls* GetNext();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_flags10;
    bool FUN_00c84f50(int a1, unsigned int a2);
};
struct NiStream;
struct BaseThunk
{
    bool FUN_00a81fe0(NiStream& stream);
};
struct C_t
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(NiStream* a);
};
struct B_t
{
    int unk00;
    int unk04;
    C_t* unk08;
};
struct A_t
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    B_t* unk10;
};
struct FUN_00c85ac0_cls : BaseThunk
{
    int unk00;
    int unk04;
    A_t* unk08;

    void FUN_00c85ac0(NiStream* a);
};
struct TlsBlock_t
{
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
    int m_2b4;
};
__declspec(thread) TlsBlock_t g_tlsBlock;
struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};
class RefLeaf_t
{
  public:
    virtual void unk00();
    virtual void unk04();
    unsigned int m_04;
};
struct Inner_t;
struct Mid_t
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Inner_t* m_10;
};
struct Inner_t
{
    int unk00;
    int unk04;
    RefLeaf_t* m_08;
};
struct FUN_00c85b00_cls
{
    int unk00;
    int unk04;
    Mid_t* m_08;

    void FUN_00c85b00();
};
class BC85BA0Target
{
  public:
    int unk00;
    long m_lRefCount;
};
class BC85BA0Link
{
  public:
    int unk00;
    int unk04;
    BC85BA0Target* m_pkTarget;
};
class BC85BA0Holder
{
  public:
    BC85BA0Link* m_pkLink;
};
class BC85BA0HkObject
{
  public:
    int unk00;
    int unk04;
    int unk08;
    void* m_pvUserData;
    BC85BA0Holder m_kHolder;
};
class BC85BA0RefObject
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual void VFunc5C();
    virtual void VFunc60();
    virtual void VFunc64();
    virtual void VFunc68();
    virtual void VFunc6C();
    virtual void VFunc70();
    virtual void VFunc74();
    virtual void VFunc78();
    virtual void VFunc7C();
    virtual void VFunc80();
    virtual void VFunc84();
    virtual void VFunc88();
    virtual void VFunc8C();
    virtual void VFunc90();
    virtual void VFunc94();
    virtual void VFunc98();
    virtual void VFunc9C();
    virtual void RegisterWithWorld();
    void UpdateReference(bool bAdd);
};
class BC85BA0WorldObject : public BC85BA0RefObject
{
  public:
    void FUN_00c85b00();
    void SetHkObjectUserData(bool bAdd);

    int unk04;
    BC85BA0HkObject* m_pkHkObject;
};
struct S_00c85ce0_First
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S_00c85ce0_Inner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct S_00c85ce0_Obj : S_00c85ce0_First, S_00c85ce0_Inner
{
};
struct S_00c85ce0
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vf2f();
    virtual void vf30();
    virtual void vfc4();
    int unk04;
    S_00c85ce0_Obj* unk08;
    void FUN_00c85ce0(unsigned int a1);
};
struct FUN_00c87600_Base
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
};
struct FUN_00c87600_Arg : FUN_00c87600_Base
{
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void* vfB0(void* value);
};
struct FUN_00c87600_Obj : FUN_00c87600_Base
{
    virtual void vfA4(int value);
    virtual void vfA8();
    virtual void vfAC();
    virtual void* vfB0(void* value);
    virtual void* vfB4(void* value);

    void __thiscall FUN_00c87600(void* arg1, void* arg2);
};
struct FUN_00a5d450_helper
{
    void __thiscall CreateVertexBufferSet(void* arg1, void* arg2);
};
// TailOne: thiscall, 18 bytes. Self virtual call at slot 0xa4 (index 41) tail-jumped with constant 1 in the stack arg.
struct FUN_00c876d0_cls
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
    virtual void Tail(int a);
    void TailOne(int a);
};
class C87710BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(C87710BinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                              unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};
class C87710Stream
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
    C87710BinaryStream* m_pUnderlyingStream;
};
class C87710HavokObject
{
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
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
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
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
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
    virtual unsigned int GetDataSize();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void* GetData(bool& bIsValid);

    unsigned int FUN_00c87710(C87710Stream& kStream);
};
class BC87850BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BC87850BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(BC87850BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
class BC87850Stream
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
    unsigned int m_uiFileVersion;
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
    BC87850BinaryStream* m_pUnderlyingStream;
    BC87850BinaryStream* m_pBackingStream;
};
template <class T>
inline void BC87850BinaryStreamSave(BC87850BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void BC87850SaveBinary(BC87850Stream& kStream, const T& value)
{
    BC87850BinaryStreamSave(*kStream.m_pBackingStream, &value);
}
class BC87850RefObject
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual void VFunc5C();
    virtual void VFunc60();
    virtual void VFunc64();
    virtual void VFunc68();
    virtual void VFunc6C();
    virtual void VFunc70();
    virtual void VFunc74();
    virtual void VFunc78();
    virtual void VFunc7C();
    virtual void VFunc80();
    virtual void VFunc84();
    virtual void VFunc88();
    virtual void VFunc8C();
    virtual void VFunc90();
    virtual void VFunc94();
    virtual void VFunc98();
    virtual void VFunc9C();
    virtual void VFuncA0();
    virtual void FreeSerializeData(int iHandle);
    virtual unsigned int GetSerializeSize();
    virtual void VFuncAC();
    virtual void VFuncB0();
    virtual char* GetSerializeData(int* piHandle);

    void BaseSaveBinary(BC87850Stream& kStream);
    void SaveSerializeData(BC87850Stream& kStream);
};
struct NiObjectData
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    void* m_pc;
    unsigned int m_uiFilterValue;
};
struct FUN_00c879e0_Class
{
    void* m_p0;
    void* m_p4;
    NiObjectData* m_p8;

    void __thiscall FUN_00c879e0(unsigned int* result);
};
struct C87A10HavokObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_ulUserData;
};
class C87A10RefObject
{
  public:
    int unk00;
    int unk04;
    C87A10HavokObject* m_pPointer;

    void UpdateReference(bool bAdd);
};
class C87A10WorldObject : public C87A10RefObject
{
  public:
    void FUN_00c87a10(bool bAdd);
};
extern int DAT_0126817c;
void* __cdecl FUN_00c88370();
// Constructor of a two-level Havok wrapper: attach the given Havok object (through its referenced-object base).
extern int g_iC88380RefObjectCount;
extern int g_iC88380WrapperCount;
class C88380ReferencedObject
{
  public:
    int m_iMemSizeAndFlags;
};
class C88380HavokBase
{
  public:
    virtual ~C88380HavokBase();
};
class C88380HavokObject : public C88380HavokBase, public C88380ReferencedObject
{
};
class C88380Root
{
  public:
    C88380Root();
    virtual ~C88380Root();
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
};
class C88380Holder : public C88380Root
{
  public:
    C88380Holder() : m_pkHavokObject(0)
    {}
    virtual ~C88380Holder();
    void* m_pkHavokObject;
};
class C88380RefObject : public C88380Holder
{
  public:
    C88380RefObject()
    {
        ++g_iC88380RefObjectCount;
    }
    virtual ~C88380RefObject();
    void SetReferencedObject(C88380ReferencedObject* pkObject);
};
class FUN_00c88380 : public C88380RefObject
{
  public:
    FUN_00c88380(C88380HavokObject* pkObject);
    virtual ~FUN_00c88380();
};
extern int DAT_0126831c;
int* __cdecl FUN_00c88400();
struct FNVTransformState
{
    int component00, component04, component08, component0c;
    int component10, component14, component18, component1c;
    int component20, component24, component28, component2c;
    int component30;
};
struct FNVTraversalNode
{
    int unknown00, unknown04, unknown08, unknown0c;
    int unknown10, unknown14;
    FNVTraversalNode* parent;
    int unknown1c, unknown20, unknown24;
    int unknown28, unknown2c, unknown30;
    FNVTransformState state;
};
struct FNVTraversalOutput : FNVTransformState
{
    void FUN_00a86bf0();
    FNVTransformState FUN_0062c250(FNVTransformState* state);
};
void __cdecl AccumulateParentTransforms(FNVTraversalNode* node, FNVTraversalNode* stop, FNVTraversalOutput* output);
struct ThreadTlsBlock
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};
extern __declspec(thread) ThreadTlsBlock g_tls;
struct TlsFlagGuard
{
    unsigned int m_saved;
    TlsFlagGuard()
    {
        m_saved = g_tls.m_2b4;
        g_tls.m_2b4 = 0x10;
    }
    ~TlsFlagGuard()
    {
        g_tls.m_2b4 = m_saved;
    }
};
extern int DAT_012681f0;
class TlsCallTarget
{
  public:
    unsigned int Lookup(int* p);
    void Apply(unsigned int v);
};
void __cdecl CallWithArgs(TlsCallTarget* t, int a, int b);
class FUN_00c886c0_cls
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    TlsCallTarget* m_08;
    void CallTargetWithArgs();
};
class C88930Base
{
  public:
    virtual ~C88930Base();
};
class FUN_00c88930 : public C88930Base
{
  public:
    void Release();

    virtual ~FUN_00c88930();
};
class SpawnedBase_b7559
{
  public:
    virtual void unk00();
    int m_04;

    SpawnedBase_b7559();
    ~SpawnedBase_b7559();
};
class FUN_00c894d0 : public SpawnedBase_b7559
{
  public:
    FUN_00c894d0(int a, int b, int c, int d, int e);
    virtual void unk00();
    void Init_b7559(int a, int b, int c, int d, int e);
};
extern int DAT_01268188;
class PolyBase
{
  public:
    virtual ~PolyBase();
};
class FUN_00c89640_cls : public PolyBase
{
  public:
    virtual ~FUN_00c89640_cls();
    void FUN_00c876a0();
};
class C896C0Object
{
  public:
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual int GetA();
    virtual int GetB();

    bool IsEqualBase(C896C0Object* pkObject);
    bool IsEqualWithValues(C896C0Object* pkObject);
};
struct S_00c89810_ResultInner
{
    void* unk0;
    void* unk4;
    int unk8;
};
struct S_00c89810_Result
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2(int value)
    {}

    S_00c89810_ResultInner* m_p4;
};
struct S_00c89810_Owner
{
    virtual void d00()
    {}
    virtual void d01()
    {}
    virtual void d02()
    {}
    virtual void d03()
    {}
    virtual void d04()
    {}
    virtual void d05()
    {}
    virtual void d06()
    {}
    virtual void d07()
    {}
    virtual void d08()
    {}
    virtual void d09()
    {}
    virtual void d0a()
    {}
    virtual void d0b()
    {}
    virtual void d0c()
    {}
    virtual void d0d()
    {}
    virtual void d0e()
    {}
    virtual void d0f()
    {}
    virtual void d10()
    {}
    virtual void d11()
    {}
    virtual void d12()
    {}
    virtual void d13()
    {}
    virtual void d14()
    {}
    virtual void d15()
    {}
    virtual void d16()
    {}
    virtual void d17()
    {}
    virtual void d18()
    {}
    virtual void d19()
    {}
    virtual void d1a()
    {}
    virtual void d1b()
    {}
    virtual void d1c()
    {}
    virtual void d1d()
    {}
    virtual void d1e()
    {}
    virtual void d1f()
    {}
    virtual void d20()
    {}
    virtual void d21()
    {}
    virtual void d22()
    {}
    virtual void d23()
    {}
    virtual void d24()
    {}
    virtual void d25()
    {}
    virtual void d26()
    {}
    virtual void d27()
    {}
    virtual void d28()
    {}
    virtual void d29()
    {}

    virtual void mA8()
    {}
    virtual void mA9()
    {}
    virtual void mAA()
    {}
    virtual void* mB4(char* value)
    {
        return 0;
    }

    void SetValueAndReset(int value);
};
struct FUN_00c898e0_Inner
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
    virtual void Slot21(int a);
};
struct FUN_00c898e0_Sub
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00c898e0_Inner* m_0c;
};
struct FUN_00c898e0_Holder
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
    virtual FUN_00c898e0_Sub* GetSub();
    void DispatchToInnerSlot(int arg);
    void FUN_00a81fe0(int a);
};
struct RefTarget
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03(int a)
    {}
};
struct FUN_00c89920_cls
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
    virtual unsigned char* GetRef(unsigned char* flag);
    void InvokeRefTarget(int a);
};
struct FUN_00c89960_inner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(unsigned int a);
};
struct FUN_00c89960_cls
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
    virtual void v41(int flag);
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void* v45(unsigned int* p);
    void __thiscall FUN_00c878c0(unsigned int a);
    void FUN_00c89960(unsigned int a1);
};
class FUN_00c899b0_target
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int m_14;
};
class FUN_00c899b0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    FUN_00c899b0_target* m_08;

    int FUN_00c899b0();
};
struct FUN_00c899d0_Target
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
    void* unk2c;
};
struct FUN_00c899d0_Class
{
    int unk00;
    int unk04;
    FUN_00c899d0_Target* unk08;

    void ReleaseReference(bool b);
    void FUN_00c899d0(bool b);
};
struct S_00c89a30_Obj;
struct S_00c89a30_Owner;
struct S_00c89a30_Obj
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
    virtual int v37();
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
    virtual void v53(S_00c89a30_Obj* o, int f);
    int unk04;
    S_00c89a30_Owner* unk08;
    void FUN_00c6b320(S_00c89a30_Owner* owner);
    bool FUN_00c89a30(S_00c89a30_Obj* other);
};
extern __declspec(thread) int DAT_tls_field;
struct hkReferencedObject
{
    void removeReference();
};
struct FUN_009ba5f0_shell
{
    void SetChildObject(int);
    void ReleaseObject(hkReferencedObject*, int);
};
struct TlsGuard
{
    int old;
    TlsGuard() : old(DAT_tls_field)
    {
        DAT_tls_field = 16;
    }
    ~TlsGuard()
    {
        DAT_tls_field = old;
    }
};
struct S_00c8a280_Child
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};
struct S_00c8a280_Bin
{
    void* __vf;
    unsigned int m_uiPos;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(S_00c8a280_Bin*, const void*, unsigned int, unsigned int*, unsigned int);
};
inline void S_00c8a280_Save(S_00c8a280_Bin* b, const void* buf, unsigned int bytes)
{
    unsigned int comp = bytes;
    unsigned int n = b->m_pfnWrite(b, buf, bytes, &comp, 1);
    b->m_uiPos += n;
}
struct S_00c8a280_Stream
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
    virtual void v12(int a);
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
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
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    S_00c8a280_Bin* m_pBackingStream;
};
struct S_00c8a280_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    int m_04;
    unsigned int m_08;
    S_00c8a280_Child* m_0c;
    S_00c8a280_Child* m_10;
    void FUN_00c8a280(S_00c8a280_Stream& kStream);
};
class C8A4B0BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(C8A4B0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(C8A4B0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};
class C8A4B0Object;
class C8A4B0Stream
{
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
    virtual void SaveLinkID(C8A4B0Object* pkObject);

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
    C8A4B0BinaryStream* m_pBackingStream;
};
template <class T>
inline void C8A4B0BinaryStreamSave(C8A4B0BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void C8A4B0SaveBinary(C8A4B0Stream& kStream, const T& value)
{
    C8A4B0BinaryStreamSave(*kStream.m_pBackingStream, &value);
}
class C8A4B0Shape
{
  public:
    void SaveSphere(C8A4B0Stream& kStream);
    void SaveBox(C8A4B0Stream& kStream);
    void SaveCapsule(C8A4B0Stream& kStream);

    int unk00;
    int unk04;
    char m_cType;
};
void __stdcall SaveShape(C8A4B0Shape* pkShape, C8A4B0Stream& kStream);
struct GlobalObject
{
    int unk00;
};
extern GlobalObject g_global;
GlobalObject* __cdecl FUN_00c8a790();
struct FUN_00c8a7a0_cls;
struct Callee_a645
{
    void Run();
};
struct FUN_00c8a7a0_cls
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
    virtual void* v2D(unsigned int* out);
    void Init(unsigned int a);
    void FUN_00c8a7a0(unsigned int a1);
};
// Result block filled in by WriteScriptTargetInfo.
struct ScriptOutBlock
{
    int unk00;
    int unk04;
    void* unk08;
};
// Object reached through the member pointer of the owner.
struct ScriptTarget
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int m_18;
    void* m_1c;
};
class ScriptOwnerBase
{
  public:
    void FUN_00c879e0(ScriptOutBlock* pOut);
};
class FUN_00c8a800_cls : public ScriptOwnerBase
{
  public:
    int unk00;
    int unk04;
    ScriptTarget* m_pFlagTarget;
    void WriteScriptTargetInfo(ScriptOutBlock* pOut);
};
struct Ca980Block
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int m_18;
    unsigned int m_1C;
};
class FUN_00c8a980_cls
{
  public:
    int unk00;
    int unk04;
    Ca980Block* m_08;
    bool FUN_00ba87d0(FUN_00c8a980_cls* p);
    bool FUN_00c8a980(FUN_00c8a980_cls* p);
};
extern int DAT_012681a0;
class FUN_00c8adf0_base
{
  public:
    virtual ~FUN_00c8adf0_base();
};
class FUN_00c8adf0_cls : public FUN_00c8adf0_base
{
  public:
    virtual ~FUN_00c8adf0_cls();
    void FUN_00c876a0();
};
struct FUN_00c8b000_Node
{
    int m_00;
    void* m_04;
    void* m_08;
};
struct FUN_00c8b000_Item;
struct FUN_00c8b000_Obj
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
    virtual FUN_00c8b000_Node* v18(int a);
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
    virtual bool v52(int a);
};
struct FUN_00c8b000_Item
{
    int m_00;
    int m_04;
    FUN_00c8b000_Obj* m_08;
};
struct FUN_00c8b000_List
{
    int m_00;
    FUN_00c8b000_Item** m_04;
    int m_08;
};
struct FUN_00c8b000_cls
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
    virtual FUN_00c8b000_List* v45(bool* out);
    void FUN_00c84df0(int a, int b);
    void UpdateListEntries(int a1, int a2);
};
struct FileContext
{
    void FUN_00a64670();
};
struct H_00c8b1d0
{
    virtual void reservedVirtual0();
    virtual void reservedVirtual1();
    virtual void reservedVirtual2();
    virtual void reservedVirtual3();
    virtual void reservedVirtual4();
    virtual void reservedVirtual5();
    virtual void reservedVirtual6();
    virtual void reservedVirtual7();
    virtual void reservedVirtual8();
    virtual void reservedVirtual9();
    virtual void reservedVirtual10();
    virtual void reservedVirtual11();
    virtual void reservedVirtual12();
    virtual void reservedVirtual13();
    virtual void reservedVirtual14();
    virtual void reservedVirtual15();
    virtual void reservedVirtual16();
    virtual void reservedVirtual17();
    virtual void reservedVirtual18();
    virtual void reservedVirtual19();
    virtual void reservedVirtual20();
    virtual void reservedVirtual21();
    virtual void reservedVirtual22();
    virtual void reservedVirtual23();
    virtual void reservedVirtual24();
    virtual void reservedVirtual25();
    virtual void reservedVirtual26();
    virtual void reservedVirtual27();
    virtual void reservedVirtual28();
    virtual void reservedVirtual29();
    virtual void reservedVirtual30();
    virtual void reservedVirtual31();
    virtual void reservedVirtual32();
    virtual void reservedVirtual33();
    virtual void reservedVirtual34();
    virtual void reservedVirtual35();
    virtual void reservedVirtual36();
    virtual void reservedVirtual37();
    virtual void reservedVirtual38();
    virtual void reservedVirtual39();
    virtual void reservedVirtual40();
    virtual void reservedVirtual41();
    virtual void* GetSharedData();
    virtual void reservedVirtual43();
    virtual void reservedVirtual44();
    virtual char* GetDataPosition(FileContext* volatile* object);
    void FUN_00c84d00(FileContext* object);
    void ProcessFileContext(FileContext* object);
};
void __cdecl FUN_00cf0930(char* data, void* shared, char* component);
void __cdecl LoadIntArray(FileContext* object, char* component);
// HandleAllEntries — walks the entry array of the list object held at this+0x08
// and forwards the parameter to each entry's handler-object virtual
// (vtable slot 21), then calls the member routine FUN_00aa0ad0 on this.
//
// Count source: vtable slot 1 of the sub-object embedded at list+0x10, with
// the owner chain (this, list) null-checked; the entry walk re-checks the
// chain on every iteration and skips null slots / null handler objects.
//
// Target: __thiscall (this in ecx), callee pops 4 bytes (1 stack parameter),
// size 109, /MT /O2 /GS /EHsc /Gy.
// Sub-object embedded at list+0x10; its vtable slot 1 returns the entry
// count as an unsigned value.
struct SubObj00
{
    virtual void v0();
    virtual unsigned int GetCount();  // vtable +0x04
};
// Handler object; vtable slot 21 (+0x54) is invoked with the parameter.
struct Handler00;
// Entry object referenced by a slot; field +0x08 points at the handler
// object that receives the per-entry virtual call.
struct Entry00;
// One 16-byte slot of the entry array at list+0x18; only the first dword
// (a pointer to the entry object) is read here.
struct Slot00
{
    Entry00* p0;  // +0x00
    int unk04;
    int unk08;
    int unk0C;
};
struct Entry00
{
    int unk00;
    int unk04;
    Handler00* unk08;  // +0x08
};
struct Handler00
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
    virtual void Handle(void* param);  // vtable +0x54
};
// The list object held at this+0x08: embedded polymorphic sub-object at
// +0x10, spare dword at +0x14, entry array base at +0x18.
struct List00
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    SubObj00 sub;  // +0x10
    int unk14;
    Slot00* arr;  // +0x18
};
// Owning class of the target member.
struct Owner00
{
    int unk00;
    int unk04;
    List00* unk08;  // +0x08

    void __thiscall FUN_00aa0ad0(void* param);  // defined elsewhere
    void HandleAllEntries(void* param);
};
struct DecCountProvider
{
    virtual void Slot00();
    virtual int GetCount();
};
struct DecTarget
{
    int unk00;
    int unk04;
};
struct DecItem
{
    int unk00;
    int unk04;
    DecTarget* m_08;
};
struct DecEntry
{
    DecItem* m_00;
    int unk04;
    int unk08;
    int unk0C;
};
struct DecOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DecCountProvider m_10;
    int unk14;
    DecEntry* m_18;
};
typedef void(__stdcall* DecCallback)(void* arg);
extern "C" DecCallback DAT_00fdf1c0;
struct FUN_00c8b2b0_cls
{
    int unk00;
    int unk04;
    DecOwner* m_08;
    void InvokeCallbacksOnEntries();
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(thread) int g_memoryContext;
struct MemoryContextScope
{
    int previousContext;
    MemoryContextScope()
    {
        previousContext = g_memoryContext;
        g_memoryContext = 16;
    }
    ~MemoryContextScope()
    {
        g_memoryContext = previousContext;
    }
};
struct RefCountedEntry
{
    virtual void UnusedVirtual();
    virtual void Release();
    volatile long referenceCount;
};
struct Record
{
    int firstField;
    int secondField;
    RefCountedEntry* referencedObject;
};
struct CollectionSlot
{
    Record* record;
    int key;
    int status;
    int extra;
};
struct IndexedRecords
{
    virtual void FirstVirtual();
    virtual unsigned int GetSize();
    int capacity;
    CollectionSlot* entries;
};
struct RecordCollection
{
    int header0;
    int header4;
    int header8;
    int headerC;
    IndexedRecords items;
};
struct CollectionHolderLayout
{
    int state;
    int reserved;
    RecordCollection* collection;
};
extern __declspec(thread) int tls_iMemContext;
struct MemContextScope
{
    int iOld;
    MemContextScope(int iNew)
    {
        iOld = tls_iMemContext;
        tls_iMemContext = iNew;
    }
    ~MemContextScope()
    {
        tls_iMemContext = iOld;
    }
};
int __cdecl sprintf_s(char* buf, unsigned int size, const char* fmt, ...);
char* __cdecl CreateDebugString(const char* pcName);
char* __cdecl CreateDebugString(const char* pcName, int iValue);
struct ViewerStrings
{
    void* vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& element);
    unsigned int Add(char* element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
};
struct NiRTTIStub
{
    const char* m_pcName;
    const NiRTTIStub* m_pBaseRTTI;
};
extern NiRTTIStub bhkListShape_ms_RTTI;
struct hkpShapeContainerStub
{
    virtual ~hkpShapeContainerStub();
    virtual int GetNumChildShapes();
};
struct hkpListShapeStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkpShapeContainerStub kContainer;
};
struct bhkShapeCollectionBase
{
    void GetViewerStrings_base(ViewerStrings* pkStrings);
};
struct bhkListShapeStub : bhkShapeCollectionBase
{
    int unk00;
    int unk04;
    hkpListShapeStub* m_pHavokObject;

    void FUN_00c8bcd0(ViewerStrings* pkStrings);
};
static inline hkpListShapeStub* GetHkListShape(bhkListShapeStub* p)
{
    return p ? p->m_pHavokObject : 0;
}
class C8CCC0Base
{
  public:
    bool IsEqual(const C8CCC0Base& kOther) const;

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
class C8CCC0Derived : public C8CCC0Base
{
  public:
    bool FUN_00c8ccc0(const C8CCC0Derived& kOther) const;

    int m_iValue;
};
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
extern "C" unsigned short __cdecl _byteswap_ushort(unsigned short);
struct SwapMatrix_c8ce70
{
    unsigned long m00;
    unsigned long m04;
    unsigned long m08;
    unsigned long m0c;
    unsigned long m10;
    unsigned long m14;
    unsigned long m18;
    unsigned long m1c;
    unsigned long m20;
    unsigned long m24;
    unsigned long m28;
    unsigned long m2c;
};
inline void Swap32_c8ce70(void* p)
{
    unsigned long* q = (unsigned long*)p;
    *q = _byteswap_ulong(*q);
}
inline void Swap16_c8ce70(void* p)
{
    unsigned short* q = (unsigned short*)p;
    *q = _byteswap_ushort(*q);
}
void __cdecl SwapEndianBlocks(SwapMatrix_c8ce70* m);
struct SwapBlock_c8ce70
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
    unsigned short unk2c;
    short unk2e;
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
    float unk64;
    float unk68;
    float unk6c;
    SwapMatrix_c8ce70 unk70;
    float unka0;
    float unka4;
    float unka8;
    float unkac;
    float unkb0;
    float unkb4;
    float unkb8;
    float unkbc;
    float unkc0;
    float unkc4;
    float unkc8;
    float unkcc;
    float unkd0;

    void SwapEndian();
};
class FUN_00c8d090_item
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
    virtual void v15(int a);
};
struct FUN_00c8d090_node
{
    FUN_00c8d090_item* m_pInventoryEntryData;
    FUN_00c8d090_node* m_pNext;
};
struct FUN_00c8d090_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    FUN_00c8d090_node m_14;

    bool Check(int a);
    bool CheckAndNotify(int a);
};
struct FUN_00c8d0d0_Object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;

    int GetNodeCount();
};
extern int DAT_012681d4;
int __cdecl FUN_00c90820(void);
class C90830ReferencedObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    C90830ReferencedObject()
    {
        m_sReferenceCount = 1;
    }
    virtual ~C90830ReferencedObject()
    {}
};
struct C90830Stream
{
    int m_iHandle;
    unsigned short m_usFlags;

    C90830Stream() : m_iHandle(-15), m_usFlags(0x8000)
    {}
    void ResetThreadCheck() throw();
};
struct C90830CriticalSection
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;

    C90830CriticalSection(int iSpinCount) throw();
};
class FUN_00c90830 : public C90830ReferencedObject
{
  public:
    int m_iFadeIndex;
    int m_iArrayLength;
    C90830Stream m_kVertexStream;
    C90830CriticalSection m_kLock;

    FUN_00c90830();
    virtual ~FUN_00c90830();
};
extern const double DAT_01012060;
struct FUN_00c90e00
{
    virtual void unk00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    float m_24;

    FUN_00c90e00(int flag);
};
extern int DAT_012681e8;
void* __cdecl FUN_00c99fe0();
struct FUN_00653290_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00653290_cls* __thiscall FUN_00653290(int* arg);
};
struct FUN_00c9a430_arg
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00653290_cls* unk0C;
};
struct FUN_00c9a430_cls
{
    int unk00;
    int unk04;
    FUN_00653290_cls* __thiscall GetMatchingObject(FUN_00c9a430_arg* arg);
};
extern int DAT_012681c0;
struct FUN_00c9a660_cls
{
    float m_00;
    float m_04;
    float m_08;

    bool NotEqual(const FUN_00c9a660_cls* other) const;
};
struct FUN_00c9a840_cls
{
    struct Vec3
    {
        float x;
        float y;
        float z;
    };
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
    Vec3* m_pVerts;
    int unk40;
    int unk44;
    unsigned int m_uiItemCount;

    bool FUN_00a6cc80(FUN_00c9a840_cls* other);
    bool FUN_00c9a840(FUN_00c9a840_cls* other);
};
extern double DAT_010231b0;
extern double DAT_010241b0;
struct FUN_00c9ab10_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    float unk14;
    float unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    float* unk3c;
    int unk40;
    int unk44;
    int unk48;

    void FUN_00c9ab10();
};
void* NiMalloc(unsigned int size);
void NiFree(void* p);
struct Elem_c9ac00
{
    float a;
    float b;
    float c;
    Elem_c9ac00()
    {}
    Elem_c9ac00(int i)
    {
        float f = (float)(i / 100.0);
        a = -1.0f;
        b = f;
        c = f;
    }
    Elem_c9ac00& operator=(const Elem_c9ac00& o)
    {
        a = o.a;
        b = o.b;
        c = o.c;
        return *this;
    }
    bool operator!=(const Elem_c9ac00& o) const
    {
        return a != o.a || b != o.b || c != o.c;
    }
};
struct LargeArray_c9ac00
{
    void** m_ppVirtualMethodTable;
    Elem_c9ac00* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void Resize(unsigned int uiMaxSize);
};
void FUN_00aa10f0(int value);
struct SubObject_c9ad60
{
    int m_00;

    virtual ~SubObject_c9ad60();
};
struct Base_c9ad60
{
    virtual void unk00();
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

    ~Base_c9ad60();
};
class FUN_00c9ad60_cls : public Base_c9ad60
{
  public:
    SubObject_c9ad60 m_38;

    virtual ~FUN_00c9ad60_cls();
};
SubObject_c9ad60::~SubObject_c9ad60()
{
    FUN_00aa10f0(m_00);
}
// FUN_00c9add0 : a one-line function - getter
extern int g_target_00c9add0;
void* FUN_00c9add0();
struct S_00c9af40_BinStream
{
    int unk00;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(S_00c9af40_BinStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(S_00c9af40_BinStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSize, unsigned int uiNumComponents)
    {
        m_uiStreamFlags += m_pfnWrite(this, pvBuffer, uiBytes, puiComponentSize, uiNumComponents);
    }
};
struct S_00c9af40_Stream
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
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    char unk1e4;
    char unk1e5, unk1e6, unk1e7;
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
    S_00c9af40_BinStream* unk250;
};
struct S_00c9af40_Point
{
    float x, y, z;
    S_00c9af40_Point()
    {}
    S_00c9af40_Point(const S_00c9af40_Point& o) : x(o.x), y(o.y), z(o.z)
    {}
};
template <class T> inline void WriteBinaryArray(S_00c9af40_BinStream& kStream, const T* pkValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    kStream.Write(pkValue, uiNumEls * sizeof(T), &uiSize, 1);
}
inline void SwapFloat(float& f)
{
    unsigned int u = *(unsigned int*)&f;
    *(unsigned int*)&f = _byteswap_ulong(u);
}
inline void SwapPoint(S_00c9af40_Point& p)
{
    SwapFloat(p.y);
    SwapFloat(p.x);
    SwapFloat(p.z);
}
struct S_00c9af40_Base
{
    void __thiscall FUN_00a6d730(S_00c9af40_Stream& kStream);
};
struct S_00c9af40_Obj : S_00c9af40_Base
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
    S_00c9af40_Point* unk3c;
    int unk40;
    int unk44;
    unsigned int unk48;
    void WriteToStream(S_00c9af40_Stream& kStream);
};
extern __declspec(thread) int g_iC9B970MemContext;
class C9B970MemContext
{
  public:
    C9B970MemContext(int aiMemoryContext)
    {
        m_iPrevious = g_iC9B970MemContext;
        g_iC9B970MemContext = aiMemoryContext;
    }
    ~C9B970MemContext()
    {
        g_iC9B970MemContext = m_iPrevious;
    }

    int m_iPrevious;
};
struct C9B970Entry
{
    int unk00;
    int unk04;
    int unk08;
};
class C9B970Array
{
  public:
    void SetSize(unsigned int uiSize);

    int unk00;
    C9B970Entry* m_pkEntryArray;
    int unk08;
    int unk0C;
    unsigned int m_uiSize;
};
class C9B970Base
{
  public:
    void CopyMemberData(C9B970Base* pkDest, void* pvCloning);

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
class C9B970Object : public C9B970Base
{
  public:
    void AddEntry(C9B970Entry* pkEntry);
    void CloneTo(C9B970Object* pkDest, void* pvCloning);

    int m_iValue;
    C9B970Array m_kEntries;
};
struct FUN_00c9ea90_Base
{
    virtual void b0();
    FUN_00c9ea90_Base(int a, int b);
};
struct FUN_00c9ea90 : FUN_00c9ea90_Base
{
    virtual void v0();

    FUN_00c9ea90(int a1);
};
struct TreeResultData
{
    int unk00;
    int unk04;
    void* m_pIntegerData;
};
void __cdecl CollectTreeResultValues(TreeNode_cls* node, SpawnedPtrArray* arr);
// Give the object an emissive material of the given color, notify listeners, then update it through the owner.
struct C11F0Color
{
    float r;
    float g;
    float b;
};
class C11F0Object;
extern bool g_bC11F0Debug;
extern void(__cdecl* g_pfnC11F0EmissiveChanged)(C11F0Object* pkObject, C11F0Color* pkColor);
void __cdecl C11F0DebugColor(int m_uiSoundID, C11F0Color* pkColor);
class C11F0Material
{
  public:
    C11F0Material();
    virtual ~C11F0Material();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    void SetEmittance(const C11F0Color& kColor)
    {
        m_kEmissive = kColor;
        m_uiRevisionID++;
    }

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    C11F0Color m_kEmissive;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    unsigned int m_uiRevisionID;
    int unk48;
};
class C11F0Object
{
  public:
    void AttachProperty(C11F0Material* pkProperty);
};
class C11F0Owner
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
    virtual void Unk94();
    virtual void Unk98();
    virtual void Unk9C();
    virtual void UnkA0();
    virtual void UnkA4();
    virtual void UnkA8();
    virtual void UnkAC();
    virtual void UnkB0();
    virtual void UnkB4();
    virtual void UnkB8();
    virtual void UnkBC();
    virtual void UnkC0();
    virtual void UnkC4();
    virtual void UnkC8();
    virtual void UnkCC();
    virtual void UnkD0();
    virtual void UnkD4();
    virtual void UnkD8();
    virtual void UpdateObject(C11F0Object* pkObject, bool bForce);
};
void AttachEmissiveMaterial(C11F0Object* pkObject, C11F0Owner* pkOwner, int m_uiSoundID, C11F0Color* pkColor);
typedef int(__cdecl* NiBinaryStream_fn)(void* s, void* buf, unsigned int n, int* out, int flag);
struct NiBinaryStream
{
    void* m_00;
    unsigned int m_04;
    NiBinaryStream_fn m_08;

    unsigned int BinaryRead(void* p, unsigned int n, int* sizes, unsigned int count)
    {
        unsigned int read = m_08(this, p, n, sizes, count);
        m_04 += read;
        return read;
    }
};
struct NiStream
{
    int m_00;
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
    NiBinaryStream* m_24c;
};
template <class T> inline void NiBinaryStreamLoad(NiBinaryStream* kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    int uiSize = sizeof(T);
    kIstr->BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void ReadBinaryValue(NiStream* kStream, T& value)
{
    NiBinaryStreamLoad(kStream->m_24c, &value);
}
struct C818F0_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void FUN_00c65800(NiStream* p);
    void FUN_00c818f0(NiStream* p);
};
struct S_00c81b40_Callee
{
    virtual void m_v01();
    virtual void m_v02();
    virtual void m_v03();
    virtual void m_v04();
    virtual void m_v05();
    virtual void m_v06();
    virtual void m_v07();
    virtual void m_v08();
    virtual void m_v09();
    virtual void m_v10();
    virtual void m_v11();
    virtual void m_v12();
    virtual void m_v13();
    virtual void m_v14();
    virtual void m_v15();
    virtual void m_v16();
    virtual void m_v17();
    virtual void m_v18();
    virtual void m_v19();
    virtual void m_v20();
    virtual void m_v21();
    virtual void m_v22();
    virtual void m_v23();
    virtual void m_v24();
    virtual void m_v25();
    virtual void m_v26();
    virtual void m_v27();
    virtual void m_v28();
    virtual void m_v29();
    virtual void m_v30();
    virtual void m_v31();
    virtual void m_v32();
    virtual void m_v33();
    virtual void m_v34();
    virtual void m_v35();
    virtual void m_v36();
    virtual void m_v37();
    virtual void m_v38();
    virtual void m_v39();
    virtual void m_v40(int* argument);

    int unk04;
    unsigned char* m_data8;
};
struct S_00c81b40_Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00c81b40_Callee* unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int* unk24;
    int unk28;

    void UpdateCountdown();
};
char* __cdecl CreateDebugString(const char* pcName, float fValue);
char* __cdecl CreateDebugString(const char* pcName, bool bValue);
char* __cdecl CreateDebugString(const char* pcName, const char* pcValue);
extern char* g_01267e64_str;
__forceinline bool GetFlagBit8(unsigned short f)
{
    return (f >> 8) & 1;
}
__forceinline bool GetFlagBit9(unsigned short f)
{
    return (f >> 9) & 1;
}
struct FUN_00c825b0_cls
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short m_usFlags;
    unsigned short unk0e;
    int unk10;
    int unk14;
    float m_f18;
    float m_f1c;
    int unk20;
    int m_i24;

    void FUN_00c66060(ViewerStrings* pkStrings);
    void AddToViewerStrings(ViewerStrings* pkStrings);
};
struct FUN_00c84900_vtbl
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned int FUN_00c84900_call(unsigned int value);
};
struct FUN_00c84900_object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* field20;
};
extern unsigned char __cdecl FUN_00c84740(void* object, unsigned int value);
unsigned char* __stdcall CallAndStoreResult(unsigned char* output, FUN_00c84900_object* object, int unused,
                                            FUN_00c84900_vtbl* caller, unsigned int value);
char* __cdecl FUN_00a7d5e0(const char* prefix, const char* str);
char* __cdecl FUN_00a7d510(const char* prefix, unsigned int val);
char* __cdecl FUN_00a7d370(const char* prefix, bool val);
extern const char* kFilterLayers[];
extern const char* kFilterParts[];
struct HavokFilterInfo
{
    unsigned int m_uFilterInfo;

    unsigned short GetGroup() const
    {
        return (unsigned short)(m_uFilterInfo >> 16);
    }
    unsigned int GetLayer() const
    {
        return m_uFilterInfo & 0x7F;
    }
    bool GetLink() const
    {
        return (m_uFilterInfo >> 15) & 1;
    }
    unsigned int GetPart() const
    {
        return (m_uFilterInfo >> 8) & 0x1F;
    }
    bool GetNoCol() const
    {
        return (m_uFilterInfo >> 14) & 1;
    }
    bool GetScaled() const
    {
        return (m_uFilterInfo >> 13) & 1;
    }

    void AppendToViewerStrings(ViewerStrings* pkStrings);
};
static __forceinline void AddString(ViewerStrings* pkStrings, char* pcString)
{
    unsigned int uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiIndex + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiIndex, pcString);
}
struct FUN_00c84d50_arg
{
    int m_unk000;
    int m_unk004;
    int m_unk008;
    int m_unk00c;
    int m_unk010;
    int m_unk014;
    int m_unk018;
    int m_unk01c;
    int m_unk020;
    int m_unk024;
    int m_unk028;
    int m_unk02c;
    int m_unk030;
    int m_unk034;
    int m_unk038;
    int m_unk03c;
    int m_unk040;
    int m_unk044;
    int m_unk048;
    int m_unk04c;
    int m_unk050;
    int m_unk054;
    int m_unk058;
    int m_unk05c;
    int m_unk060;
    int m_unk064;
    int m_unk068;
    int m_unk06c;
    int m_unk070;
    int m_unk074;
    int m_unk078;
    int m_unk07c;
    int m_unk080;
    int m_unk084;
    int m_unk088;
    int m_unk08c;
    int m_unk090;
    int m_unk094;
    int m_unk098;
    int m_unk09c;
    int m_unk0a0;
    int m_unk0a4;
    int m_unk0a8;
    int m_unk0ac;
    int m_unk0b0;
    int m_unk0b4;
    int m_unk0b8;
    int m_unk0bc;
    int m_unk0c0;
    int m_unk0c4;
    int m_unk0c8;
    int m_unk0cc;
    int m_unk0d0;
    int m_unk0d4;
    int m_unk0d8;
    int m_unk0dc;
    int m_unk0e0;
    int m_unk0e4;
    int m_unk0e8;
    int m_unk0ec;
    int m_unk0f0;
    int m_unk0f4;
    int m_unk0f8;
    int m_unk0fc;
    int m_unk100;
    int m_unk104;
    int m_unk108;
    int m_unk10c;
    int m_unk110;
    int m_unk114;
    int m_unk118;
    int m_unk11c;
    int m_unk120;
    int m_unk124;
    int m_unk128;
    int m_unk12c;
    int m_unk130;
    int m_unk134;
    int m_unk138;
    int m_unk13c;
    int m_unk140;
    int m_unk144;
    int m_unk148;
    int m_unk14c;
    int m_unk150;
    int m_unk154;
    int m_unk158;
    int m_unk15c;
    int m_unk160;
    int m_unk164;
    int m_unk168;
    int m_unk16c;
    int m_unk170;
    int m_unk174;
    int m_unk178;
    int m_unk17c;
    int m_unk180;
    int m_unk184;
    int m_unk188;
    int m_unk18c;
    int m_unk190;
    int m_unk194;
    int m_unk198;
    int m_unk19c;
    int m_unk1a0;
    int m_unk1a4;
    int m_unk1a8;
    int m_unk1ac;
    int m_unk1b0;
    int m_unk1b4;
    int m_unk1b8;
    int m_unk1bc;
    int m_unk1c0;
    int m_unk1c4;
    int m_unk1c8;
    int m_unk1cc;
    int m_unk1d0;
    int m_unk1d4;
    int m_unk1d8;
    int m_unk1dc;
    int m_unk1e0;
    unsigned char m_unk1e4;
};
struct FUN_00c84d50_cls
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
    virtual void v41(void* object);
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual int* v45(void*& object);

    int m_unk04;
    int m_unk08;
    int m_unk0c;
    unsigned int m_flags;

    void SaveSerializeData(void* arg);
    void FUN_00c84d50(void* arg);
};
struct Out_00c85880
{
    int m_00;
    int m_04;
    unsigned char m_08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    int unk0C;
    int m_10;
};
struct Sub_00c85880
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned char m_18;
    int m_1C;
};
struct State_00c85880
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Sub_00c85880 m_10;
};
struct Owner_00c85880
{
    int unk00;
    int unk04;
    State_00c85880* m_08;

    void FillOutputFromState(Out_00c85880* o);
};
struct NiFixedStrX
{
    char* m_str;
    NiFixedStrX(const char* str)
    {
        m_str = NiGlobalStringTable::AddString(str);
    }
    __forceinline ~NiFixedStrX()
    {
        if (m_str != _EmptyFS)
            InterlockedDecrement((long*)(m_str - 8));
    }
};
struct NiNodeX
{
    int unk00;
    int unk04;
    char* m_name;
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
    NiNodeX(unsigned short count);
    void SetName(const NiFixedStrX& name);
    static void* operator new(unsigned int size);
};
struct bhkWorldX
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void AddDebugNode(NiNodeX* node, NiPoint3* offset);
};
struct WorldHolder
{
    int unk00;
    int unk04;
    bhkWorldX* m_pOwningWorld;
};
struct PhantomData
{
    WorldHolder* m_holder;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int m_pCollisionShape;
};
struct WorldObjectX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    PhantomData m_data;
};
void __cdecl GetLayerColor(int shape, NiPoint3* out);
struct bhkWorldObjectX
{
    int unk00;
    int unk04;
    WorldObjectX* m_obj;
    NiNodeX* AddDebugNodeToWorld(NiNodeX* node);
};
extern __declspec(thread) int g_iC88760AllocTag;
struct BC88760AllocTagScope
{
    int m_iSaved;

    BC88760AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iC88760AllocTag;
        g_iC88760AllocTag = aiAllocationTag;
    }
    ~BC88760AllocTagScope()
    {
        g_iC88760AllocTag = m_iSaved;
    }
};
class BC88760CloningProcess;
class BC88760Base
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    BC88760Base();
    virtual ~BC88760Base();

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
class BC88760Derived : public BC88760Base
{
  public:
    BC88760Derived()
    {}
    virtual ~BC88760Derived();

    void CopyMemberData(BC88760Derived* pkDest, BC88760CloningProcess& kCloning);
    BC88760Derived* FUN_00c88760(BC88760CloningProcess& kCloning);
};
class NiNode;
class NiAVObject;
class NiFixedString
{
  public:
    char* m_kHandle;
    NiFixedString(const char* pcString) : m_kHandle(NiGlobalStringTable::AddString(pcString))
    {}
    ~NiFixedString()
    {
        if (m_kHandle != _EmptyFS)
            InterlockedDecrement(reinterpret_cast<long*>(m_kHandle - 8));
    }
};
class NiUpdateData
{
  public:
    float m_fTime;
    bool m_bUpdate;
    bool m_bIsMultiThreaded;
    bool m_bUpdateGeomorphs;
    bool m_bUpdateShadowSceneNode;
    bool m_bUnk8;
    NiUpdateData()
        : m_fTime(0.0f), m_bUpdate(false), m_bIsMultiThreaded(false), m_bUpdateGeomorphs(false),
          m_bUpdateShadowSceneNode(false), m_bUnk8(false)
    {}
};
struct FUN_00c88810_Collision
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
};
class NiAVObject
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual NiNode* IsSceneNode();
    char pad04[0x14];
    NiNode* m_pParentNode;
    FUN_00c88810_Collision* m_spCollisionObject;
    void Update(const NiUpdateData& kUpdateData);
};
class NiNode : public NiAVObject
{
  public:
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
    virtual NiAVObject* GetObjectByName(const NiFixedString& kName);
    char pad20[0x9c - 0x20];
    NiTObjectArray<NiAVObject*> m_kChildList;
};
void FUN_00c6a350(NiNode* apNode, int aiArg, bool abA, bool abB, bool abC);
void UpdateChainCollision(NiAVObject* apObject);
// LinkObject: resolve the two linked bodies and store their Havok entities in the constraint data.
class C8A910Stream
{
  public:
    void* GetLoadedObject();
};
class C8A910Body
{
  public:
    int unk00;
    int unk04;
    void* m_pkEntity;
};
struct C8A910ConstraintData
{
    int unk00;
    void* m_pkEntityA;
    void* m_pkEntityB;
};
class C8A910Constraint
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
    virtual void Unk94();
    virtual void Unk98();
    virtual void Unk9C();
    virtual void UnkA0();
    virtual void UnkA4();
    virtual void UnkA8();
    virtual void UnkAC();
    virtual void UnkB0();
    virtual C8A910ConstraintData* GetConstraintData(unsigned int& ruiType);

    void LinkObjectBase(C8A910Stream& kStream);
    void FUN_00c8a910(C8A910Stream& kStream);
};
class Dispatcher
{
  public:
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
    virtual void Dispatch(void* p);
};
class Node1
{
  public:
    int unk00;
    int unk04;
    int unk08;
    void* m_0c;
};
class Mid
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Node1* m_18;
    Node1* m_1c;
};
class RefChainOwner
{
  public:
    int unk00;
    int unk04;
    Mid* m_08;
    void SaveSerializeData(Dispatcher* p);
    void DispatchChainNodes(Dispatcher* arg);
};
extern void* __cdecl FUN_00aa13e0(unsigned int size);
extern int DAT_01030bf4;
extern int DAT_010c44e4;
extern int DAT_010c485c;
extern int DAT_012680f8;
extern int DAT_012686d0;
extern int DAT_012681a0;
struct Base_00c8ae60
{
    int* vtable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void FUN_00c87c30();
    Base_00c8ae60()
    {
        FUN_00c87c30();
    }
};
struct Object_00c8ae60 : Base_00c8ae60
{
    static void* operator new(unsigned int bytes)
    {
        return FUN_00aa13e0(bytes);
    }
    Object_00c8ae60()
    {
        vtable = &DAT_01030bf4;
        unk0c = 0;
        unk10 = 0;
        ++DAT_012680f8;
        vtable = &DAT_010c44e4;
        ++DAT_012686d0;
        vtable = &DAT_010c485c;
        ++DAT_012681a0;
    }
};
Object_00c8ae60* __cdecl FUN_00c8ae60();
// Forward a call to every child wrapper of this group's Havok object.
class C8B4D0Wrapper
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
    virtual void Apply(int iArg1, int iArg2);
};
struct C8B4D0Child
{
    int unk00;
    int unk04;
    C8B4D0Wrapper* m_pkWrapper;
};
struct C8B4D0Slot
{
    C8B4D0Child* m_pkChild;
    int unk04;
    int unk08;
    int unk0C;
};
class C8B4D0Counter
{
  public:
    virtual void Unk_00();
    virtual int GetCount();
};
struct C8B4D0HavokGroup
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C8B4D0Counter m_kCounter;
    int unk14;
    C8B4D0Slot* m_pkSlots;
};
class C8B4D0Group
{
  public:
    int unk00;
    int unk04;
    C8B4D0HavokGroup* m_pkHavok;

    C8B4D0HavokGroup* GetHavok()
    {
        return this ? m_pkHavok : 0;
    }
    int GetChildCount()
    {
        C8B4D0HavokGroup* pkHavok = GetHavok();
        return pkHavok ? pkHavok->m_kCounter.GetCount() : 0;
    }
    C8B4D0Child* GetChild(int i)
    {
        C8B4D0HavokGroup* pkHavok = GetHavok();
        return pkHavok ? pkHavok->m_pkSlots[i].m_pkChild : 0;
    }

    void ApplyToChildren(int iArg1, int iArg2);
};
SpawnedAllocHolder* FUN_00c85750();
struct C8B8A0Alloc;
struct C8B8A0Array;
void FUN_00c908c0(C8B8A0Alloc* allocator, C8B8A0Array* arr, int capacity, int elemSize);
struct C8B8A0Array
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void GrowArrayCapacity(C8B8A0Alloc& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(int));
        }
    }
    void _setSize(C8B8A0Alloc& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }
    void SetSizeAndGrow(int n)
    {
        SpawnedAllocHolder* router = FUN_00c85750();
        C8B8A0Alloc* allocator = (C8B8A0Alloc*)router->m_pAllocator;
        _setSize(*allocator, n);
    }
    void clear()
    {
        m_iElementCount = 0;
    }
};
struct C8B8A0Out
{
    int unk00;
    C8B8A0Array m_keys;
    C8B8A0Array m_iSlotIds;
};
struct C8B8A0Iface
{
    virtual void v00();
    virtual int GetCount();
    virtual void* GetFirst();
    virtual void* GetNext(void* it);
    virtual int GetValue(void* it);
};
struct C8B8A0Entry
{
    int m_key;
    int unk04;
    int unk08;
    int unk0C;
};
struct C8B8A0Map
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C8B8A0Iface m_iface;
    int unk14;
    C8B8A0Entry* m_entries;
};
struct MyObj
{
    int unk00;
    int unk04;
    C8B8A0Map* m_map;
    void FUN_00c84e20(void* out);
    void FillKeyValueArrays(C8B8A0Out* out);
};
extern __declspec(thread) int g_C8B9E0AllocTag;
struct C8B9E0AllocTagScope
{
    int m_iSaved;

    C8B9E0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_C8B9E0AllocTag;
        g_C8B9E0AllocTag = aiAllocationTag;
    }
    ~C8B9E0AllocTagScope()
    {
        g_C8B9E0AllocTag = m_iSaved;
    }
};
class C8B9E0Heap
{
  public:
    void* Allocate(unsigned int uiSize);
};
extern C8B9E0Heap g_kC8B9E0Heap;
template <class T> class C8B9E0Array
{
  public:
    C8B9E0Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
class C8B9E0Listener
{
  public:
    static void* operator new(unsigned int uiSize)
    {
        return g_kC8B9E0Heap.Allocate(uiSize);
    }
    static void operator delete(void* pvMem);

    C8B9E0Listener() : m_pkOwnerManager(0)
    {}

    void* m_pkOwnerManager;
    C8B9E0Array<void*> m_kAdded;
    C8B9E0Array<void*> m_kRemoved;
};
class C8B9E0Owner
{
  public:
    int unk00;
    int unk04;
    void* m_pkWorld;
    C8B9E0Listener* m_pkListener;

    void AttachListener(C8B9E0Listener* pkListener);
    C8B9E0Listener* GetOrCreateListener(bool* pbCreated);
};
struct ListAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* data, int bytes);
};
struct ShapeArray
{
    FUN_00c8b000_Item** data;
    int size;
    int capacity;
    ShapeArray() : data(0), size(0), capacity(0x80000000)
    {}
    ~ShapeArray()
    {
        SpawnedAllocHolder* holder = FUN_00c85750();
        ListAllocator* alloc = (ListAllocator*)holder->m_pAllocator;
        size = 0;
        if (!(capacity & 0x80000000))
        {
            alloc->Free(data, (capacity & 0x3fffffff) * 4);
        }
        data = 0;
        capacity = 0x80000000;
    }
    void swap(ShapeArray& other)
    {
        FUN_00c8b000_Item** oldData = data;
        data = other.data;
        other.data = oldData;
        int oldSize = size;
        size = other.size;
        other.size = oldSize;
        int oldCapacity = capacity;
        capacity = other.capacity;
        other.capacity = oldCapacity;
    }
};
struct ListShapeData
{
    unsigned int header;
    ShapeArray shapes;
    ShapeArray keys;
};
struct ListShapeSave
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
    virtual void* GetSharedData();
    virtual void v43();
    virtual void v44();
    virtual ListShapeData* GetDataPosition(bool* owned);
    void FUN_00c84d50(C8A4B0Stream* stream);
    void SaveListShape(C8A4B0Stream* stream);
};
void __cdecl SaveUIntArray(C8A4B0Stream* stream, ShapeArray* array);
unsigned int* __cdecl SwapEndianBlocks(unsigned int* auiData);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
extern __declspec(thread) int g_iAllocTagC9A;
struct AllocTagScopeC9A
{
    int m_iSaved;

    AllocTagScopeC9A(int aiAllocationTag)
    {
        m_iSaved = g_iAllocTagC9A;
        g_iAllocTagC9A = aiAllocationTag;
    }
    ~AllocTagScopeC9A()
    {
        g_iAllocTagC9A = m_iSaved;
    }
};
class ObstacleDataC9A
{
  public:
    virtual ~ObstacleDataC9A();
    virtual void DeleteThis();

    void IncRefCount()
    {
        InterlockedIncrement((long volatile*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};
template <class T> class NiPointerC9A
{
  public:
    NiPointerC9A(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointerC9A()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    T* m_pObject;
};
void __cdecl FreeNodeC9A(void* pvNode);
template <class T> class BSSimpleListC9A
{
  public:
    __declspec(noinline) void Remove(const T& kItem)
    {
        for (BSSimpleListC9A* pkNode = this; pkNode->m_pkNext; pkNode = pkNode->m_pkNext)
        {
            BSSimpleListC9A* pkNext = pkNode->m_pkNext;
            if (pkNext->m_item.m_pObject == kItem.m_pObject)
            {
                pkNode->m_pkNext = pkNext->m_pkNext;
                FreeNodeC9A(pkNext);
                return;
            }
        }
    }

    T m_item;
    BSSimpleListC9A* m_pkNext;
};
class ObstacleManagerC9A
{
  public:
    int unk00;
    int unk04;
    int unk08;
    BSSimpleListC9A<NiPointerC9A<ObstacleDataC9A> > m_kObstacles;

    void FUN_00c9a520(ObstacleDataC9A* pkData);
};
struct FUN_00c9abc0_cls
{
    int unk00;
    int unk04;
    unsigned char unk08;
    unsigned char unk09;
    short unk0a;
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
    float unk50;
    float unk54;
    void __thiscall FUN_00c9abc0(int param2);
};
struct FUN_00c9a6c0
{
    float time, value1, value2;
    FUN_00c9a6c0();
};
struct TargetFlags
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int flags;
};
struct TargetBody
{
    int unk00, unk04, unk08, unk0c;
    TargetFlags flags;
};
struct TargetLink
{
    int unk00, unk04;
    TargetBody* body;
    unsigned int GetFlags() const
    {
        TargetFlags* info = body ? &body->flags : 0;
        return info ? info->flags : 0;
    }
};
struct TargetExtra
{
    int unk00, unk04, unk08, unk0c;
    TargetLink* link;
    int unk14;
    float start, end;
    float GetStart() const
    {
        return start;
    }
    float GetEnd() const
    {
        return end;
    }
};
struct ExtraList
{
    TargetExtra* FUN_00653290(int* type);
};
struct TargetController
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
    virtual void v35(float time);
    int unk04;
    unsigned short flags;
    unsigned short unk0a;
    float frequency, phase, start, end;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    LargeArray_c9ac00 keys;
    int unk50, unk54;
    unsigned int mode;
    void Reset();
    void FUN_00c9b1a0(FUN_00c9a6c0* key);
};
struct SceneNode;
struct SceneObject
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual SceneNode* AsNode();
    int unk04, unk08, unk0c, unk10, unk14, unk18;
    ExtraList* extras;
    TargetController* FUN_00a5c570(int* type);
};
struct SceneNode : SceneObject
{
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
    SceneObject** children;
    unsigned short capacity, childCount;
};
struct TimeRange
{
    float start, end;
};
extern TimeRange DAT_011b1090[];
extern TimeRange DAT_011b0f90[];
extern int DAT_01267e64;
extern const float DAT_01015f5c;
void FUN_00c9b250(SceneObject* object, float middle, bool alternate);
struct Node253;
struct HavokObject253
{
    int unk00, unk04, unk08;
    Node253* owner;
};
struct PhysicsData253
{
    int unk00;
    HavokObject253* first;
    HavokObject253* second;
};
struct Map253
{
    bool FUN_00a53c30(Node253* key, void*& value);
};
struct CloneProcess253
{
    Map253* map;
};
struct Node253
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
    virtual Node253* Clone(void* process);
    int references;
    HavokObject253* object;
};
struct Owner253
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
    virtual PhysicsData253* GetData(bool* temporary);
    void FUN_00c87600(void* destination, void* process);
    void ClonePhysicsData(void* destination, void* process);
};
class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_012043f8;
extern GlobalObjectO2_00a7b610 g_0126818c;
struct Param5380d0;
struct This5380d0
{
    bool FUN_005380d0(Param5380d0*);
};
void EnableConstraintsAndZeroArrays(void*, void*);
struct ControllerRTTI
{
    const char* name;
    const ControllerRTTI* base;
};
struct ControllerOwner
{
    unsigned int unkCur;
    unsigned int unkValue;
    unsigned int uNewnk;
    unsigned int unk00C;
    unsigned int uTmpnk;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
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
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    This5380d0* manager;
};
struct ControllerObject
{
    virtual void slot();
    virtual void slotCur();
    virtual void slotValue();
    virtual void sNewlot();
    virtual void sTmplot();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual unsigned int GetType();
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
    virtual ControllerOwner* GetOwner();
};
struct ControllerLink
{
    unsigned int unk, unk04;
    void* active;
    ControllerObject* object;
    void Process()
    {
        EnableConstraintsAndZeroArrays(this, active);
    }
    bool IsActive() const
    {
        return active != 0;
    }
    void Update()
    {
        if (IsActive())
            Process();
    }
    void ProcessIfActive()
    {
        if (active)
            EnableConstraintsAndZeroArrays(this, active);
    }
};
struct ControllerFallback
{
    ControllerObject* object;
};
struct IdleController
{
    virtual void slot();
    virtual void DeleteThis();
    virtual const ControllerRTTI* GetRTTI();
    virtual void sNewlot();
    virtual void sTmplot();
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
    virtual void HandleControllerData(This5380d0*);
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
    virtual ControllerLink* GetLink();
    long refs;
    ControllerLink* link;
    ControllerFallback* fallback;
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    __forceinline void DecRefCount()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
    bool IsKindOfType(const ControllerRTTI* wanted)
    {
        const ControllerRTTI* type = GetRTTI();
        while (type)
        {
            if (type == wanted)
                return true;
            type = type->base;
        }
        return false;
    }
    void ProcessActive()
    {
        if (link->active)
            link->Process();
    }
    ControllerObject* GetObject()
    {
        return link ? link->object : (fallback ? fallback->object : 0);
    }
};
struct ControllerPtr
{
    IdleController* m_pObject;
    __forceinline ControllerPtr(IdleController* p) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline ~ControllerPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    ControllerPtr& operator=(const ControllerPtr& other);
};
struct ControllerList
{
    ControllerPtr item;
    ControllerList* next;
    ~ControllerList();
    void RemoveNode(const ControllerPtr& key);
};
void ControllerList::RemoveNode(const ControllerPtr& key)
{
    if (!key.m_pObject)
        return;
    if (!next && !item.m_pObject)
        return;
    ControllerList* prev = this;
    ControllerList* cur = this;
    while (cur->item.m_pObject != key.m_pObject)
    {
        prev = cur;
        cur = cur->next;
        if (!cur)
            return;
    }
    if (cur == this)
    {
        ControllerList* pNext = next;
        if (pNext)
        {
            next = pNext->next;
            item = pNext->item;
            pNext->next = 0;
            pNext->~ControllerList();
            _g_memoryManager.Deallocate(pNext);
        }
        else if (item.m_pObject)
        {
            item.m_pObject->DecRefCount();
            item.m_pObject = 0;
        }
    }
    else
    {
        prev->next = cur->next;
        cur->next = 0;
        cur->~ControllerList();
        _g_memoryManager.Deallocate(cur);
    }
}
struct ControllerCollection
{
    unsigned int unk, unk04, unk08, unk0C, unk10;
    ControllerList head;
};
struct ControllerExtra
{
    unsigned int unk, unk04, unk08, unk0C;
    ControllerCollection* collection;
};
void ProcessControllerList(WalkNode_cls* node);
struct C817D0Node
{
    void UpdateWorldLoc();
};
struct C817D0RefNode
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_flags;
};
struct C817D0TlsBlock
{
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
    int m_2c0;
};
__declspec(thread) C817D0TlsBlock g_c817d0Tls;
struct C817D0Cls
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
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfA0();
    virtual void vfA4();

    unsigned int unk04;
    C817D0Node* m_08;
    unsigned short m_0c;
    unsigned short unk0e;
    C817D0RefNode* m_10;
    unsigned char m_14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    float m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;

    void UpdateNodeState(int);
    void FUN_00c65b00();
};
void __cdecl FUN_00c87670(int* param_1, unsigned int param_2);
void __cdecl FUN_00c84cc0(int* param_1, unsigned int param_2);
// Fallout: New Vegas — FUN_00c85620
// __cdecl aligned-allocation helper: requests an over-sized block from the
// heap object's virtual allocator, aligns the returned pointer up to the
// requested alignment, and stores a small header immediately below the
// aligned pointer: {owner, end, offset-to-raw}.
struct FUN_00c85620_heap
{
    virtual void v0();
    virtual void* Allocate(unsigned int uiSize);
};
void* __cdecl FUN_00c85620(FUN_00c85620_heap* pkHeap, unsigned int uiSize, unsigned int uiAlignment);
struct FUN_00ba87d0_holder
{
    bool FUN_00ba87d0();
};
void __cdecl FUN_00c85800();
struct FUN_00c87a40_ref
{
    void* unk00;
    void* unk04;
    void* unk08;
};
struct FUN_00c87a40_obj
{
    void* unk00;
    void* unk04;
    FUN_00c87a40_ref* unk08;

    void* __thiscall FUN_00c87a40();
};
extern void __cdecl FUN_00a5d3a0();
extern int DAT_010c5b54;
struct FUN_00c87c30_t
{
    int* pVTable;
    int unk04;
    int unk08;
    FUN_00c87c30_t* FUN_00c87c30();
};
struct FUN_00c87c50_cls
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
    virtual void slot36(bool b);
    int unk04;
    NiObject* unk08;
    void FUN_00c87c50(NiObject* arg);
};
extern int DAT_01268160;
int* __cdecl FUN_00c87c80();
extern __declspec(thread) int DAT_tls_field;
struct MemoryContextGuard
{
    int previous;
    MemoryContextGuard() : previous(DAT_tls_field)
    {
        DAT_tls_field = 16;
    }
    ~MemoryContextGuard()
    {
        DAT_tls_field = previous;
    }
};
struct FUN_00c905b0_Class
{
    void FUN_00c905b0();
};
struct FUN_00a5d3d0
{
    virtual ~FUN_00a5d3d0();
};
struct FUN_00c87d20 : FUN_00a5d3d0
{
    int m_field04;
    FUN_00c905b0_Class* m_ref;
    virtual ~FUN_00c87d20();
};
struct FUN_00c87dc0_class
{
    void __thiscall FUN_00c87d20();
    unsigned int __thiscall FUN_00c87dc0(unsigned char param_2);
};
extern "C" void __cdecl operator delete(void*, unsigned int);
void __cdecl DispatchToTarget();
void __cdecl FUN_00c87fa0();
void FUN_00c6b760();
void FUN_00c87fb0();
extern int DAT_010c5dc0;
struct FUN_00c88430_t
{
    int* m_p0;
    int m_i4;
    int m_i8;
    int m_ic;
    int m_i10;
    FUN_00c88430_t();
};
extern int DAT_01267b70;
struct Flagged_c891
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
    int flag30;
};
struct Facade_c891
{
    int unk00;
    int unk04;
    Flagged_c891* value08;
};
struct Result_c891
{
    Facade_c891* facade00;
    int unk04;
};
struct Elem_c891
{
    int unk00;
    int unk04;
    Elem_c891* unk08;
    Elem_c891* getE() const
    {
        return unk08;
    }
};
struct Holder_c891
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Elem_c891* elem10;
};
struct Heap_c891
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int bytes);
};
Holder_c891* __cdecl FUN_00c802d0(int);
struct Arr_c891
{
    Elem_c891** m_data;
    int m_iElementCount;
    int m_cap;
    Arr_c891() : m_data(0), m_iElementCount(0), m_cap(0x80000000)
    {}
    Elem_c891*& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    ~Arr_c891()
    {
        SpawnedAllocHolder* r = FUN_00c85750();
        Heap_c891* heap = (Heap_c891*)r->m_pAllocator;
        m_iElementCount = 0;
        if ((m_cap & 0x80000000) == 0)
            heap->ReturnMemory(m_data, (m_cap & 0x3fffffff) * 4);
    }
};
void __cdecl CollectTreeResultValues(int, Arr_c891*);
Result_c891* __cdecl FUN_00c85ef0(Result_c891*, Elem_c891*, int*);
struct Cls_c891
{
    int unk00;
    int unk04;
    int m_08;
    void FUN_00c891c0();
};
extern void FUN_00c87650();
void FUN_00c896b0();
struct FnvCpu_FUN_00c89720_CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
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
    virtual void Invoke();
    void FUN_00c89720();
};
struct AttachObject;
struct AttachData;
struct AttachObject
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
    virtual AttachData* GetData();
    virtual void v38();
    virtual void Add(AttachObject*);
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
    virtual void Set(AttachObject*);
    virtual AttachObject* GetTarget();
    virtual AttachData* GetConstraint();
    int unk04;
    AttachData* owner;
    int unk0c;
    unsigned int flags;
    int unk14;
    unsigned int count;
    int unk1c;
    int unk20;
    AttachData* data24;
    int unk28;
    unsigned int id;
    void FUN_00a29680();
    bool AddOrRemoveConstraint(AttachObject* body, bool add);
};
struct AttachData
{
    unsigned char HasObjectOfType()
    {
        return object08 != 0;
    }
    int unk00;
    int unk04;
    AttachObject* object08;
    AttachObject* object0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    AttachObject* object24;
    int unk28;
    unsigned int id;
};
struct DiagFlag
{
    bool enabled;
    DiagFlag(bool value) : enabled(value)
    {}
    DiagFlag(const DiagFlag& other) : enabled(other.enabled)
    {}
};
struct DiagString
{
    int a, b, c;
    DiagString(char*, unsigned int, DiagFlag);
    void Append(const char*);
    ~DiagString();
};
struct DiagSink
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Report(int, unsigned int, char*, const char*, int);
};
extern DiagSink* diagnosticSink;
struct Alloc8b_c8b090
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int size);
    virtual void ReleaseBlock(void* p, int size);
};
struct hkThreadLocals_c8b090
{
    int value;
};
extern __declspec(thread) int g_hkTlsScopeValue;
struct TlsScope_c8b090
{
    int m_old;
    TlsScope_c8b090(int v)
    {
        m_old = g_hkTlsScopeValue;
        g_hkTlsScopeValue = v;
    }
    ~TlsScope_c8b090()
    {
        g_hkTlsScopeValue = m_old;
    }
};
struct hkRefObj_c8b090
{
    virtual void vf0();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;

    static void* operator new(unsigned int size)
    {
        SpawnedAllocHolder* holder = FUN_00c85750();
        Alloc8b_c8b090* alloc = (Alloc8b_c8b090*)holder->m_pAllocator;
        hkRefObj_c8b090* b = (hkRefObj_c8b090*)alloc->AllocateMemoryBlock(static_cast<int>(size));
        b->m_usMemSizeAndFlags = (unsigned short)size;
        return b;
    }
    static void operator delete(void* p, unsigned int size)
    {
        SpawnedAllocHolder* holder = FUN_00c85750();
        Alloc8b_c8b090* alloc = (Alloc8b_c8b090*)holder->m_pAllocator;
        alloc->ReleaseBlock(p, static_cast<int>(size));
    }
    void removeReference();
};
struct hkShapeContainer_c8b090
{
    virtual void v0();
    virtual int GetNumChildShapes();
    virtual int GetFirstKey();
    virtual int GetNextShapeKey(int key);
};
struct hkShape_c8b090
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct hkShapeBase_c8b090 : hkRefObj_c8b090
{
    int unk08;
    int unk0c;
};
struct hkListShape_c8b090 : hkShapeBase_c8b090, hkShapeContainer_c8b090
{
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
    hkListShape_c8b090(void* shapes, unsigned int count, int policy);
    void setChild(int key, int value);
};
struct ListInfo_c8b090
{
    int unk00;
    void* m_shapes;
    unsigned int m_numShapes;
    int unk0c;
    int* m_iSlotIds;
    unsigned int m_uiArrayCount;
};
struct bhkListOwner_c8b090
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void SetShape(hkListShape_c8b090* shape);
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void SetListInfo(ListInfo_c8b090* info);
    void SetListShape(ListInfo_c8b090* info);
};
struct C8B540Selected;
class C8B540Wrapper
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
    virtual C8B540Selected* Select();
};
class C8B540Selected
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
    virtual int GetResult(int iArg);
};
struct C8B540Group : C8B4D0Group
{
    int unk0C;
    int m_iFallback;

    int GetSelectedResult(int iArg);
};
extern int DAT_012681cc;
int __cdecl FUN_00c8ff70();
void __cdecl FUN_00c818f0(int, int);
void __cdecl FUN_00c8ff80(int param_1, int param_2);
struct FUN_00c819a0_holder
{
    static void InitFromFlags();
};
void __cdecl FUN_00c8ff90();
extern "C" void __cdecl FUN_00cb7610();
void __cdecl FUN_00c8ffa0();
extern void __cdecl FUN_00c819f0();
void __cdecl FUN_00c8ffb0();
bool __cdecl FUN_00c815b0(C815B0Constraint* pkOther);
bool __cdecl FUN_00c8ffc0(C815B0Constraint* pkOther);
struct C90160Matrix
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
};
extern const C90160Matrix DAT_011a9448;
class C90160Derived : public BC88760Base
{
  public:
    C90160Matrix matrix;
    C90160Derived() : matrix(DAT_011a9448)
    {}
    virtual ~C90160Derived();

    void FUN_00c81580(C90160Derived* destination, BC88760CloningProcess& cloning);
    C90160Derived* FUN_00c90160(BC88760CloningProcess& cloning);
};
void __cdecl FUN_00c90330();
void __cdecl FUN_00c90340();
int __cdecl FUN_00c90350();
extern "C" int DAT_01268748;
extern "C" const char* __cdecl FUN_00cf6170(void** value, void* object);
extern "C" void __cdecl FUN_00cf6920(void* owner, void* object, void* context);
struct FunctionContext
{
    void __thiscall FUN_00c90360(void* context, void* object);
};
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* lpCriticalSection);
extern int DAT_0102e388;
struct FUN_00c90880_Srv
{
    virtual void m_00();
    virtual void m_04();
    virtual void m_08(void* p, unsigned short w);
};
struct FUN_00c90880_Class
{
    void* m_00;
    unsigned short m_04;

    void* FUN_00c90880(unsigned int flags);
};
int __stdcall FUN_00c90e30(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8);
struct FUN_00c92b00_Entry
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44;
    int value48;
    int value4c;
};
struct FUN_00c92b00_Class
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24;
    FUN_00c92b00_Entry** entries28;
    int count2c;
    int unk30;
    FUN_00c92b00_Entry** entries34;
    int count38;

    void FUN_00c92a80(int first, int second);
    void ApplyEntries();
};
struct FUN_00c9a620_Obj
{
    float unk00;
    float unk04;
    float unk08;

    int __thiscall FUN_00c9a620(float* other);
};
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
void FUN_00cbb990();
struct ArenaReleaseAllocator : ArenaAllocator
{
    virtual void Deallocate(void* p, unsigned int bytes);
};
struct ArenaRegistryRelease
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void Release(TemporaryArena* arena, ArenaRegistrationFlag flag);
};
struct ArenaManagedOwner
{
    TemporaryArena* arena;
    void* buffer;
    unsigned long threadId;
};
void FUN_00c80240(ArenaManagedOwner* owner);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
class RefObject0AA0
{
  public:
    virtual ~RefObject0AA0();
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    long m_uiRefCount;
};
template <class T> class NiPointer0AA0
{
  public:
    NiPointer0AA0(const NiPointer0AA0& ptr)
    {
        m_pObject = ptr.m_pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    NiPointer0AA0& operator=(const NiPointer0AA0& ptr);
    operator T*() const
    {
        return m_pObject;
    }
    T* m_pObject;
};
struct MemoryManager0AA0
{
    void* Allocate(unsigned int uiSize);
};
extern MemoryManager0AA0 g_kMemoryManager0AA0;
class ListNode0AA0
{
  public:
    static void* operator new(unsigned int uiSize) throw()
    {
        return g_kMemoryManager0AA0.Allocate(uiSize);
    }
    ListNode0AA0(const NiPointer0AA0<RefObject0AA0>& spRetainedObject) : m_pReferencedObject(spRetainedObject)
    {
        m_pkNext = 0;
    }
    void FUN_00c80aa0(const NiPointer0AA0<RefObject0AA0>& spRetainedObject);

    NiPointer0AA0<RefObject0AA0> m_pReferencedObject;
    ListNode0AA0* m_pkNext;
};
struct FUN_00c819f0_stream
{
    void* vtable;
    unsigned int m_04;
    unsigned int unk08;
    unsigned int(__cdecl* m_0c)(FUN_00c819f0_stream* self, void* buffer, unsigned int size, unsigned int* sizes,
                                unsigned int count);
};
class FUN_00c819f0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int m_18;
    unsigned int m_1c;
    void Callee65820(int a1);
    void FUN_00c819f0(int a1);
};
struct MeshMemoryScope
{
    int saved;
    MeshMemoryScope()
    {
        saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 16;
    }
    ~MeshMemoryScope()
    {
        g_tlsBlock.m_2b4 = saved;
    }
};
inline void* __cdecl operator new[](unsigned int size)
{
    return DAT_011f6238.FUN_00aa3e40(size);
}
struct FourFloatComponents
{
    float unk00, unk04, unk08, unk0c;
};
struct SourceTriangle
{
    unsigned int unk00, unk04, unk08, unk0c;
};
struct SourceMesh
{
    FourFloatComponents* unk00;
    unsigned int unk04;
    unsigned int unk08;
    SourceTriangle* unk0c;
    unsigned int unk10;
};
void __cdecl FUN_00458620(NiPoint3*, const FourFloatComponents*);
struct GeometryData
{
    void EnsureNormals(bool);
};
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
class NiTriShape : public NiMemObject
{
  public:
    NiTriShape(unsigned short, NiPoint3*, NiPoint3*, void*, void*, unsigned short, unsigned int, unsigned short,
               unsigned short*);
    void SetName(const NiFixedString&);
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
    GeometryData* unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
};
void __cdecl AttachEmissiveMaterial(NiTriShape*, unsigned int, unsigned int, unsigned int);
struct MeshBuilder
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    void BuildTriShape(unsigned int unused, SourceMesh* mesh, unsigned int arg2, const char* name);
};
struct PropertyKey
{
    unsigned int first, second;
};
extern PropertyKey DAT_011f4280;
struct PropertyValue
{
    int value;
    unsigned int extra;
};
struct PropertyEntry
{
    void* key;
    unsigned int flags;
    PropertyValue data;
};
struct PropertyStore
{
    unsigned int unknown00;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    unsigned int unknown30;
    unsigned int unknown34;
    unsigned int unknown38;
    unsigned int unknown3c;
    unsigned int unknown40;
    unsigned int unknown44;
    unsigned int unknown48;
    unsigned int unknown4c;
    unsigned int unknown50;
    unsigned int unknown54;
    unsigned int unknown58;
    unsigned int unknown5c;
    unsigned int unknown60;
    unsigned int unknown64;
    unsigned int unknown68;
    unsigned int unknown6c;
    unsigned int unknown70;
    unsigned int unknown74;
    PropertyEntry* entries;
    int count;
    PropertyValue FindEntry(void* key, int flags);
};
struct PropertyOwner
{
    unsigned int unknown00, unknown04;
    PropertyStore* store;
    int ReadProperty(void* key);
    int FUN_00c85c80(void* key);
};
__forceinline int PropertyOwner::ReadProperty(void* key)
{
    PropertyStore* object = store;
    int result = 0;
    if (object)
        result = object->FindEntry(key, 0).value;
    return result;
}
struct ObjectController
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void* v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();

    void* unk04;
    void* m_pObject;
    void SetObject(void* replacement);
    void FUN_00c87c50(void* replacement);
};
struct FUN_00c87a50_t
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* FUN_00c87a50();
};
struct C87c90HkRef
{
    void FUN_00c90510();
};
struct NiPlane
{
    int unk00;
    int unk04;
    int unk08;

    bool operator==(const NiPlane& other) const;
};
struct Mat364
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

    bool _Call_4d9ae0(const Mat364& other) const;
};
extern unsigned char DAT_011f426c;
extern unsigned char DAT_011f4270;
extern unsigned char DAT_011f4274;
struct Target_00c88450
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
    Mat364 unk34;
    NiPlane unk58;
};
struct Cinfo_00c88450
{
    int unk00;
    int unk04;
    Target_00c88450* unk08;

    void __thiscall UpdateNodeState(void* arg);
    void __thiscall FUN_00c88450(void* arg);
};
struct Process89730
{
    Map253* map;
    int unk04;
    int unk08;
    int unk0C;
    float m_fScale;
};
struct Poly89730
{
    virtual void slot0();
    virtual void Scale(int iUnused, Process89730* pkProcess);
};
struct Data89730Base
{
    int unk00;
};
struct Data89730 : public Poly89730, public Data89730Base
{
    int unk08;
    HavokObject253* m_pkFirst;
    HavokObject253* m_pkSecond;
};
struct Owner89730
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
    virtual Data89730Base* GetData(bool* pbTemporary);
    void FUN_00c87600(void* pkDestination, Process89730* pkProcess);
    void FUN_00c89730(void* pkDestination, Process89730* pkProcess);
};
struct FUN_00d53200_class
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    int unk04;
    int unk08;
    void FUN_00c8a230(NiStream& kStream);
};
extern int DAT_01268194;
struct ActorBase
{
    virtual ~ActorBase();
};
struct FUN_00c8a720 : ActorBase
{
    virtual ~FUN_00c8a720();
    void FUN_00c876a0();
};
class C8AAResult
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;
};
class C8AASub
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    C8AAResult* m_18;
    C8AAResult* m_1c;
};
class C8AAHost
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    C8AASub* m_08;
    C8AAResult* GetA()
    {
        C8AAResult* r;
        if (this && m_08)
            r = m_08->m_18;
        else
            r = 0;
        return r;
    }
    C8AAResult* GetOther()
    {
        C8AAResult* r;
        if (this && m_08)
            r = m_08->m_1c;
        else
            r = 0;
        return r;
    }
    int GetResultValue(char c);
};
extern "C" void _ReadWriteBarrier(void);
struct FUN_00c8aa80_cls : BaseThunk
{
    int unk00;
    int unk04;
    Mid* m_08;
    void FUN_00c8aa80(NiStream* a);
};
extern unsigned int DAT_010c6234;
struct Ffd0base
{
    void Initialize();
};
struct Arr9
{
    int v[9];
};
struct FUN_00c8ffd0
{
    void* m_vtbl;
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
    Arr9 tab;
    FUN_00c8ffd0();
};
void FUN_00c910c0();
bool FUN_00c911c0();
struct OperationPacket
{
    unsigned char operation;
    void* target;
    unsigned int value;
};
struct CommandTarget
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Receive(unsigned int value);
};
struct CommandDispatcher
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
    void FUN_00c91160(OperationPacket* packet);
    CommandTarget* DispatchCommand(CommandTarget* target, unsigned int value);
};
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* lpCriticalSection);
SpawnedAllocHolder* FUN_00c85750() throw();
struct C99F10Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiBytes) throw();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, int aiBytes) throw();
};
struct C99F10Array
{
    void** m_ppData;
    int m_uiLogicalSize;
    int m_iCapacity;
    ~C99F10Array() throw()
    {
        SpawnedAllocHolder* pHolder = FUN_00c85750();
        C99F10Allocator* pAlloc = (C99F10Allocator*)pHolder->m_pAllocator;
        m_uiLogicalSize = 0;
        if (!(m_iCapacity & 0x80000000))
        {
            pAlloc->FreeArray(m_ppData, (m_iCapacity & 0x3fffffff) * 4);
        }
        m_ppData = 0;
        m_iCapacity = 0x80000000;
    }
};
struct C99F10Base
{
    virtual ~C99F10Base() throw()
    {}
    int unk04;
};
struct FUN_00c99f10 : C99F10Base
{
    C99F10Array m_kArray;
    void* m_pUserData;
    virtual ~FUN_00c99f10() throw();
};
struct FUN_00c9a520_shell
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
    virtual void* v9(void* pvArg);

    void FUN_00c9a520(void* pvData);
    void FUN_00c9a5e0(void* pvArg);
};
struct DispatchObject;
typedef int(__thiscall* DispatchAction)(DispatchObject*, void*);
struct DispatchObject
{
    void** vtable;
    void* unk04;
    DispatchObject* unk08;
    int type;
    int Dispatch(void* argument)
    {
        return reinterpret_cast<DispatchAction>(vtable[0x38])(this, argument);
    }
};
struct DispatchContainer
{
    void* unk00;
    void* argument;
    void* unk08;
    void* objectLink;
};
typedef void*(__thiscall* GetTarget)(DispatchObject*);
int __cdecl FUN_00c80020(DispatchContainer* container);
// FUN_00c80090: cdecl, one pointer arg; probes nested object chain.
class ProbeX;
class ProbeY;
class ProbeZ;
class ProbeE;
class ProbeD;
class ProbeC;
class ProbeObj;
extern int DAT_012681c0;
ProbeE* __cdecl GetExtraDataChecked(ProbeObj* o);
struct PackedPropertyByte
{
    unsigned char value;
    PackedPropertyByte()
    {}
    inline bool operator!=(int rhs) const
    {
        return value != rhs;
    }
};
class ProbeZ
{
  public:
    PackedPropertyByte FUN_00c9bff0() const;
};
class ProbeX
{
  public:
    ProbeY* FUN_00653290(const void* type);
};
class ProbeY
{
  public:
    int unk00;
    int unk04;
    ProbeZ* m_08;
};
struct SelectedBits
{
    unsigned int bits;
    inline operator bool() const
    {
        return bits != 0;
    }
};
class ProbeE
{
  public:
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_0c;
    inline SelectedBits SelectedFlag() const
    {
        SelectedBits result = {m_0c & 2};
        return result;
    }
};
class ProbeD
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ProbeX* m_10;
};
class ProbeC
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual ProbeD* GetD();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    ProbeC* m_1c;
};
class ProbeObj
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    ProbeC* m_1c;
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
    ProbeC** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
    inline unsigned int ChildCount() const
    {
        return m_a6;
    }
    inline ProbeC* FirstChild() const
    {
        return ChildCount() <= 0 ? 0 : *m_a0;
    }
};
static inline bool CheckBody(ProbeD* body, ProbeObj*& obj)
{
    ProbeX* object = body->m_10;
    if (object)
    {
        ProbeY* rigid = object->FUN_00653290(&DAT_012681c0);
        if (rigid && rigid->m_08)
            return rigid->m_08->FUN_00c9bff0() != 0;
    }
    return false;
}
bool FUN_00c80090(ProbeObj* obj);
struct WalkBits_c804
{
    union
    {
        unsigned int raw;
        struct
        {
            unsigned int lo : 7;
            unsigned int hi : 25;
        };
    };
    WalkBits_c804()
    {}
    WalkBits_c804(unsigned int r) : raw(r)
    {}
    void SetLo(unsigned int f)
    {
        lo = f;
    }
};
class WalkLookup_c804
{
  public:
    void* Find(const void* key);
};
class WalkMid_c804
{
  public:
    void Apply(unsigned int value);
    void Apply2(WalkBits_c804 value);
};
struct WalkHit_c804
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    WalkMid_c804* m_10;
};
struct WalkSub_c804
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    unsigned int m_1c;
};
struct WalkNode_c804
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual WalkNode_c804* v03();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    WalkLookup_c804* m_1c;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    WalkNode_c804** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};
void FUN_00c804d0(WalkNode_c804* node, unsigned int flag);
extern unsigned int DAT_012043f8;
struct WorkNode_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual int v03();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    DynCastHelper* unk1C;
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
    WorkNode_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};
struct NodeDepth
{
    WorkNode_cls* node;
    unsigned int depth;
};
struct WorkStack_cls
{
    unsigned int unk00;
    unsigned int* m_04;
    unsigned int m_08;
    void __thiscall InsertItemAt(int a1, NodeDepth* a2);
};
NiObject* __cdecl FUN_00c80c00(WorkNode_cls* a1, WorkStack_cls* a2, unsigned int a3, unsigned int a4);
// FUN_00c81890 (unit_a1df186ed60f.cpp) - 95B, /MT /O2 /GS /EHsc /Gy
// v4: extern __declspec(thread) int DAT_tls_0x2c0 (probe-exact a1+64 8b 0d+8b 14 81+8b 82 c0020000);
//     uchar bitfield f6/f0 (probe-exact mov cl/shr/test forms); m_bits word AND per v3 match
extern __declspec(thread) int DAT_tls_0x2c0;
// TLS slot +0x2C0 (module index 0x126fd98)
struct FUN_00c65b00_holder
{
    int __thiscall FUN_00c65b00();
};
struct FUN_00a68bf0_holder
{
    int __thiscall FUN_00a68bf0();
};
// ?UpdateWorldLoc@NiAVObject@@QAEXXZ
typedef int(__thiscall* FN_00c81890_VT)(void*);
union U_00c81890
{
    unsigned short m_bits;  // +0xC word member
    struct
    {
        unsigned char f0 : 1;
        unsigned char : 5;
        unsigned char f6 : 1;
        unsigned char : 1;
    } bf;
};
struct E_T
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
    virtual int va4();
    void* m_p4;
    void* m_p8;
    U_00c81890 u_c;

    bool GetBit(int n) const
    {
        return (u_c.m_bits >> n) & 1;
    }
    void ClearBit(int n)
    {
        u_c.m_bits &= ~(1 << n);
    }
    int __thiscall FUN_00c81890();
};
struct A50Inner
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
    unsigned char m_e8;
};
class A50Obj
{
  public:
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
    virtual void ve4(int t);
    int m_04;
    A50Inner* m_08;
};
struct A50Cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    A50Obj* m_10;
    int unk14;
    int unk18;
    int unk1c;
    int m_20;
    void __thiscall FUN_00c81a50();
};
struct FUN_00c84d00_obj
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
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
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
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char unk1E4;
    unsigned char m_1e5;
};
struct FUN_00c84d00_cls
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
    virtual int* vGet(FUN_00c84d00_obj** pp);
    void FUN_00c87650(FUN_00c84d00_obj* a);
    void FUN_00c84d00(FUN_00c84d00_obj* a1);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    int m_10;
};
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
class Obj
{
  public:
    virtual void* v00();
    virtual void* v01();
    virtual void* v02();
    virtual void* v03();
    virtual void* v04();
    virtual void* v05();
    virtual void* v06();
    virtual void* v07();
    virtual void* v08();
    virtual void* v09();
    virtual void* v0a();
    virtual void* v0b();
    virtual void* v0c();
    virtual void* v0d();
    virtual void* v0e();
    virtual void* v0f();
    virtual void* v10();
    virtual void* v11();
    virtual void* v12();
    virtual void* v13();
    virtual void* v14();
    virtual void* v15();
    virtual void* v16();
    virtual void* v17();
    virtual void* v18();
    virtual void* v19();
    virtual void* v1a();
    virtual void* v1b();
    virtual void* v1c();
    virtual void* v1d();
    virtual void* v1e();
    virtual void* v1f();
    virtual void* v20();
    virtual void* v21();
    virtual void* v22();
    virtual void* v23();
    virtual void* v24();
    virtual void* v25();
    virtual void* v26();
    virtual void* v27();
    virtual void* v28();
    unsigned int unk04;
    Obj* m_08;
    void FUN_00c6b0a0(Obj* p);
    bool FUN_00c85810(Obj* a);
};
extern int DAT_012682e8;
extern int DAT_012682dc;
struct FUN_00a63430_class
{
    void* FUN_00a63430();
};
struct FUN_00653290_class
{
    int FUN_00653290(int* arg);
};
struct FUN_00cca4e0
{
    void* m_00;
    void* m_04;
    void* m_08;
    int m_0c;
    int m_10;
    FUN_00cca4e0(void* value);
    static void* operator new(unsigned int bytes)
    {
        return FUN_00aa13e0(bytes);
    }
};
struct FUN_00c87670_class
{
    void FUN_00c87670(unsigned int value);
};
struct S00c859e0_holder
{
    void* m_00;
    void* m_04;
};
typedef S00c859e0_holder*(__thiscall* S00c859e0_slot45)(void*, unsigned int*);
struct S00c859e0_cls
{
    void FUN_00c859e0(unsigned int value);
};
extern __declspec(thread) unsigned int t_uiMemContextC877;
inline unsigned int GetMemContextC877()
{
    return t_uiMemContextC877;
}
inline void SetMemContextC877(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContextC877 = m_uiGeometryShaderFlags;
}
class AutoMemContextC877
{
  public:
    AutoMemContextC877(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContextC877();
        SetMemContextC877(m_uiGeometryShaderFlags);
    }
    ~AutoMemContextC877()
    {
        SetMemContextC877(m_uiPrevious);
    }
    unsigned int m_uiPrevious;
};
struct BlockPool_c877
{
    void FUN_00aa4060(void* pvBlock);
};
class PoolOwnerBase_c877
{
  public:
    virtual void v00();
    ~PoolOwnerBase_c877();
    int unk04;
    int unk08;
};
class FUN_00c877b0 : public PoolOwnerBase_c877
{
  public:
    virtual void v00();
    ~FUN_00c877b0();
    void* m_pvBlock;
};
struct C89AC0_Owner;
struct C89AC0_Child
{
    int unk00;
    int unk04;
    C89AC0_Owner* m_pSharedOwner;
    void FUN_00c905b0();
    void FUN_00c90510();
};
struct C89AC0_Owner
{
    int unk00;
    C89AC0_Child* m_pChildObject;
    void SetChildObject(C89AC0_Child* child);
};
struct ThreadData674
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
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
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int context;
};
extern __declspec(thread) ThreadData674 g_threadData;
struct Context674
{
    unsigned int previous;
    Context674()
    {
        previous = g_threadData.context;
        g_threadData.context = 16;
    }
    ~Context674()
    {
        g_threadData.context = previous;
    }
};
struct Input674
{
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(Input674*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* data, unsigned int bytes)
    {
        unsigned int size = bytes;
        position += read(this, data, bytes, &size, 1);
    }
};
struct Stream674
{
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
    Input674* input;
    Input674* Input()
    {
        return input;
    }
};
struct Heap674
{
    virtual void v0();
    virtual void* Allocate(unsigned int);
};
struct Router674
{
    int unk00, unk04, unk08, unk0C;
    Heap674* heap;
};
struct Base674
{
    virtual ~Base674();
    unsigned short size;
    unsigned short flags;
    static void* operator new(unsigned int size)
    {
        SpawnedAllocHolder* r = FUN_00c85750();
        Heap674* heap = (Heap674*)r->m_pAllocator;
        Base674* b = (Base674*)heap->Allocate(size);
        b->size = (unsigned short)size;
        return b;
    }
    static void operator delete(void* memory);
};
struct FUN_00cf4190_class : Base674
{
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    FUN_00cf4190_class();
    void FUN_00cf41c0(Stream674*);
};
struct FUN_00cf43b0_class : Base674
{
    int unk08, unk0C, unk10, unk14, unk18, unk1C;
    FUN_00cf43b0_class();
    void FUN_00cf4400(Stream674*);
};
struct FUN_00cf45d0_class : Base674
{
    int unk08, unk0C, unk10, unk14, unk18;
    FUN_00cf45d0_class();
    void SaveToArchive(Stream674*);
};
void* __stdcall FUN_00c8a330(Stream674* stream);
struct C8AC00_Info
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
    int id;
};
struct C8AC00_Target
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
    virtual C8AC00_Info* GetInfo();
};
struct C8AC00_Owner
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
    C8AC00_Target* target;
};
struct C8AC00_Sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int id;
    void SetRefObject(int);
};
struct C8AC00_Self
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
    virtual C8AC00_Owner* GetOwner();
    int unk04;
    C8AC00_Sub* sub;
    bool FUN_00c87b40();
    bool FUN_00c8ac00();
};
extern "C" void _ReadWriteBarrier(void);
extern "C" void _ReadBarrier(void);
extern "C" void _WriteBarrier(void);
struct AllocLocal;
inline void DeallocateLocal(AllocLocal* a, void* p, int const& n);
struct TypeInfoLocal
{
    const char* name;
    TypeInfoLocal* base;
};
extern TypeInfoLocal g_012682e8, g_012682dc, g_012686a0, g_01268264;
struct ShapeLocal
{
    virtual void v0();
    virtual void v1();
    virtual TypeInfoLocal* GetType();
    int reference;
    ShapeLocal* object;
    ShapeLocal* FUN_00653290(const TypeInfoLocal*);
    bool IsType(const TypeInfoLocal* type)
    {
        const TypeInfoLocal* current = GetType();
        while (current)
        {
            if (current == type)
                return true;
            current = current->base;
        }
        return false;
    }
};
struct WrapperLocal
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    static void* operator new(unsigned int);
    WrapperLocal(ShapeLocal*);
};
struct AllocLocal;
struct AllocTableLocal
{
    void(__thiscall* v0)(AllocLocal*);
    void(__thiscall* v1)(AllocLocal*);
    void(__thiscall* v2)(AllocLocal*);
    void(__thiscall* v3)(AllocLocal*);
    void(__thiscall* free)(AllocLocal*, void*, int);
};
struct AllocViewLocal
{
    AllocTableLocal* table;
};
struct AllocLocal
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void*, int);
    void Clear(SpawnedPtrArray& arr)
    {
        int cap = arr.m_uiCapacity;
        arr.m_uiCount = 0;
        if (!(cap & 0x80000000))
        {
            void* p = arr.m_pData;
            DeallocateLocal(this, p, cap & 0x3fffffff);
        }
        arr.m_pData = 0;
        arr.m_uiCapacity = 0x80000000;
    }
};
inline void DeallocateLocal(AllocLocal* a, void* p, int const& n)
{
    a->Free(p, n * 4);
}
void FUN_00c908c0(void*, SpawnedPtrArray*, int, int);
template <class T> inline void ConstructLocal(T* dest, int n, const T& value)
{
    for (int k = 0; k < n; ++k)
        dest[k] = value;
}
struct ArrayLocal : SpawnedPtrArray
{
    void Clear(AllocLocal& allocator)
    {
        m_uiCount = 0;
        if ((int)m_uiCapacity >= 0)
            allocator.Free(m_pData, (m_uiCapacity & 0x3fffffff) * 4);
        m_pData = 0;
        m_uiCapacity = 0x80000000;
    }
    void Reserve(void* allocator, int count)
    {
        int capacity = m_uiCapacity & 0x3fffffff;
        if (capacity < count)
        {
            int desired = capacity * 2;
            if (count >= desired)
                desired = count;
            FUN_00c908c0(allocator, this, desired, 4);
        }
    }
    void Append(SpawnedAllocHolder* holder, ShapeLocal* raw)
    {
        if (m_uiCount == (m_uiCapacity & 0x3fffffff))
            ResizeAudioStream(holder->m_pAllocator, this, 4);
        ConstructLocal(m_pData + m_uiCount, 1, (void*)raw);
        ++m_uiCount;
    }
};
struct LoadStreamLocal
{
    int unk00;
    unsigned int version;
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
    char filename;
    unsigned int FUN_00a63460();
    ShapeLocal* FUN_00a63430();
};
struct ListLocal
{
    int unk00;
    ArrayLocal items;
};
struct LoaderLocal
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
    virtual ListLocal* GetList(bool*);
    void FUN_00c84cc0(LoadStreamLocal*);
    void LoadShapes(LoadStreamLocal*);
};
class S00c8bf40_Flags
{
  public:
    bool FUN_00c84dc0(const S00c8bf40_Flags* pkOther) const;
    bool FUN_00c8bf40(const S00c8bf40_Flags* pkOther) const;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct FUN_00c6c290
{
    void FUN_00c6b980(int);
};
struct S00c90090_Obj
{
    virtual void S00c90090_v0();
    virtual void S00c90090_v1();
    int m_ref;
};
struct S00c90090_Ptr
{
    S00c90090_Obj* p;
    S00c90090_Ptr(S00c90090_Obj* q) : p(q)
    {
        if (p)
            InterlockedIncrement((long volatile*)&p->m_ref);
    }
    ~S00c90090_Ptr()
    {
        if (p)
        {
            if (!InterlockedDecrement((long volatile*)&p->m_ref))
                p->S00c90090_v1();
        }
    }
};
struct S00c90090_Self
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C(int i);
    int m_p4;
    int m_p8;
    int m_pc;
    S00c90090_Obj* m_p10;
    int m_p14;
    float m_f18;
    float m_f1c;
    int m_p20;
    int m_p24;
    float GetF1C() const
    {
        return m_f1c;
    }
    void SetF1C(float f)
    {
        m_f1c = f;
    }
    float GetF18() const
    {
        return m_f18;
    }
    void SetF18(float f)
    {
        m_f18 = f;
    }
    void FUN_00c90090(S00c90090_Self* src);
};
struct NiMatrix3Stub
{
    float m[9];
    char* FormatToBuffer(const char* pcName) const;
};
struct bhkTransformShapeStub : FUN_00c825b0_cls
{
    int unk28;
    NiMatrix3Stub m_kAdditionalRotation;

    void FUN_00c90240(ViewerStrings* pkStrings);
};
extern const float DAT_01017870;
extern const float DAT_010177e8;
extern const float DAT_01018180;
extern const float DAT_01056528;
struct MotionSettings
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
    float first;
    float second;
    int mode;
    void SetPreset(int preset);
};
struct SpawnedAllocHolder;
SpawnedAllocHolder* __cdecl FUN_00c85750();
extern "C" void __cdecl FUN_00c92950(void*);
extern "C" void __cdecl FUN_00c928c0(void*, void*);
extern "C" double clobber_c929e0(double);
struct FUN_00c929e0_Alloc
{
    virtual void vf00();
    virtual void* vf04(unsigned int size);
};
struct FUN_00d065e0_class
{
    void* FUN_00d065e0();
};
static __declspec(noinline) void FUN_00c927c0(void* p, void* q)
{
    volatile int sink = 0;
    char* s = (char*)FUN_00c85750();
    if (p)
        sink = 1;
    if (q)
        sink = 2;
    clobber_c929e0(1.0);
    sink += s[0];
    if (p)
        sink = 3;
    if (q)
        sink = 4;
    if (p)
        sink = 5;
}
static __declspec(noinline) void InvokeOnAllOwners(void* a, void* b)
{
    volatile int sink = 0;
    if (a)
        sink = 1;
    clobber_c929e0(2.0);
    if (a)
        sink = 2;
    if (b)
        sink = 3;
}
class FUN_00c929e0_ThisClass
{
  public:
    void* FUN_00c929e0();
};
struct RefObjectC9
{
    virtual void Unknown();
    virtual void Destroy();
    volatile long refs;
    void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&refs) == 0)
            Destroy();
    }
};
struct SmartC9
{
    RefObjectC9* pointer;
    SmartC9(RefObjectC9* p = 0) : pointer(p)
    {
        if (pointer)
            pointer->IncRefCount();
    }
    SmartC9(const SmartC9& other) : pointer(other.pointer)
    {
        if (pointer)
            pointer->IncRefCount();
    }
    ~SmartC9()
    {
        if (pointer)
            pointer->DecRefCount();
    }
    SmartC9& operator=(const SmartC9& other)
    {
        if (pointer != other.pointer)
        {
            if (pointer)
                pointer->DecRefCount();
            pointer = other.pointer;
            if (pointer)
                pointer->IncRefCount();
        }
        return *this;
    }
};
struct ListC9
{
    SmartC9 item;
    ListC9* next;
    ListC9(const SmartC9& p) : item(p), next(0)
    {}
    __declspec(noinline) void FUN_00631540(const SmartC9& p)
    {
        if (!p.pointer)
            return;
        if (item.pointer)
        {
            ListC9* node = new ListC9(item);
            node->next = next;
            next = node;
        }
        item = p;
    }
};
struct OwnerC9Body
{
    int unk00, unk04, unk08;
    ListC9 list;
    void AddObject(RefObjectC9* object);
};
extern const float DAT_01012054;
extern const double DAT_01017a40;
struct C9A6E0Entry
{
    float fA;
    float fB;
    float fC;
    void Set(float a, float b, float c)
    {
        fA = a;
        fB = b;
        fC = c;
    }
    void Set3(float a, float p)
    {
        float z = (float)(p / 100.0);
        fA = a;
        fB = z;
        fC = z;
    }
};
static inline float Pct(float f)
{
    return (float)(f / 100.0);
}
static inline float Pct2(int f)
{
    return (float)(f / 100.0);
}
struct C9A6E0Array
{
    int unk00;
    C9A6E0Entry* m_pkEntryArray;
    int unk08;
    unsigned int m_uiCount;
    unsigned int m_uiAllocatedCapacity;
    void FUN_00c9a6e0();
};
float __cdecl FUN_00a42050(float t, float a, float b);
struct KeyPair
{
    float time;
    float first;
    float second;
};
struct KeyPairInterpolator
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    int unk1C, unk20, unk24, unk28, unk2C, unk30;
    unsigned int lastIndex;
    int unk38;
    KeyPair* keys;
    int unk40, unk44;
    unsigned int count;
    bool Interpolate(float time, float& first, float& second);
};
extern __declspec(thread) int DAT_012722b4;
struct TlsGuardS00c9_t
{
    int m_saved;

    TlsGuardS00c9_t()
    {
        m_saved = DAT_012722b4;
        DAT_012722b4 = 0x10;
    }

    ~TlsGuardS00c9_t()
    {
        DAT_012722b4 = m_saved;
    }
};
struct HeldSub_t
{
    void* FUN_00a5c570(const void* key);
    void FUN_00a5c480(void* entry);
};
struct S00c9ade0_Obj
{
    int unk00;
    int unk04;
    unsigned char m_08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    HeldSub_t* m_2c;

    bool FUN_00c9ade0();
};
extern int DAT_012683f4;
void __cdecl FUN_00c9e3e0(void);
#include <stdlib.h>
struct C00624070
{
    unsigned int value;
    __declspec(noinline) bool FUN_00624070();
};
extern unsigned __int64 selected_target_masks[];
extern unsigned int DAT_01268078[];
__forceinline bool Mask135(unsigned int a, unsigned int b)
{
    return (DAT_01268078[(a >> 8) & 31] & (1 << ((b >> 8) & 31))) != 0;
}
bool FUN_00c84740(unsigned int a, unsigned int b);
__declspec(noinline) bool C00624070::FUN_00624070()
{
    unsigned int layer = value & 127;
    return layer == 8 || layer == 29;
}
// @fnv 0x00c85d20
struct B0
{
    int a, b, c, d;
};
struct F
{
    unsigned a, b, c, d, e, f, g, bits;
};
struct O : B0, F
{
};
unsigned Apply(unsigned bits, char on)
{
    if (on == 0)
        bits |= 0x4000u;
    else
        bits &= ~0x4000u;
    return bits;
}
struct C
{
    void** vt;
    int x;
    O* object;
    void FUN_00c85d20(char active);
};
void C::FUN_00c85d20(char active)
{
    O* item = object;
    F* part = item;
    unsigned bits = part ? part->bits : 0;
    bits = Apply(bits, active);
    part = item;
    if (part)
        part->bits = bits;
    typedef void(__thiscall * Fn)(C*);
    ((Fn*)vt)[49](this);
}
extern "C" unsigned long __readfsdword(unsigned long);
extern volatile unsigned long DAT_0126fd98;
struct MemoryCategoryScope_00c89dd0
{
    int previous;
    MemoryCategoryScope_00c89dd0(int* block) : previous(block[0x2b4 / 4])
    {
        block[0x2b4 / 4] = 16;
    }
    ~MemoryCategoryScope_00c89dd0()
    {
        previous = 0;
    }
};
struct PendingAllocation_00c89dd0
{
    void* pointer;
    PendingAllocation_00c89dd0(void* value) : pointer(value)
    {}
    ~PendingAllocation_00c89dd0()
    {
        pointer = 0;
    }
};
struct Allocator_00c89dd0
{
    virtual void reserved();
    virtual void* allocate(unsigned int bytes);
};
SpawnedAllocHolder* FUN_00c85750();
struct CloneData_00c89dd0
{
    int unknown00;
    void* first;
    void* second;
    void* third;
    void* fourth;
};
struct Instance_00c89dd0
{
    Instance_00c89dd0* FUN_00cf3ea0(void* first, void* second, void* third, void* fourth);
};
struct RefCounted_00c89dd0
{
    void FUN_00c905b0();
};
struct Dispatch_00c89dd0
{
    virtual void reserved00();
    virtual void reserved01();
    virtual void reserved02();
    virtual void reserved03();
    virtual void reserved04();
    virtual void reserved05();
    virtual void reserved06();
    virtual void reserved07();
    virtual void reserved08();
    virtual void reserved09();
    virtual void VirtualFunction10();
    virtual void ReplaceImpactData();
    virtual void reserved12();
    virtual void VirtualFunction13();
    virtual void reserved14();
    virtual void reserved15();
    virtual void reserved16();
    virtual void reserved17();
    virtual void reserved18();
    virtual void reserved19();
    virtual void reserved20();
    virtual void reserved21();
    virtual void VirtualFunction22();
    virtual void VirtualFunction23();
    virtual void VirtualFunction24();
    virtual void VirtualFunction25();
    virtual void VirtualFunction26();
    virtual void VirtualFunction27();
    virtual void VirtualFunction28();
    virtual void VirtualFunction29();
    virtual void reserved30();
    virtual void reserved31();
    virtual void reserved32();
    virtual void reserved33();
    virtual void reserved34();
    virtual void attach(Instance_00c89dd0*);
    virtual void reserved36();
    virtual void reserved37();
    virtual void reserved38();
    virtual void reserved39();
    virtual void reserved40();
    virtual void reserved41();
    virtual void reserved42();
    virtual void reserved43();
    virtual void reserved44();
    virtual void reserved45();
    virtual void reserved46();
    virtual void finish(int);
    void SpawnAndAttach(int data);
};
#include <string.h>
struct FUN_00c90030_Matrix
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
struct FUN_00c90030_Transform
{
    void* __thiscall FUN_0043f8d0(void* a, void* b, void* c, void* d);
};
struct FUN_00c90030_Result
{
    void* __thiscall FUN_0043f8d0();
};
struct FUN_00c90030_Outer
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
    FUN_00c90030_Transform unk68;
};
struct FUN_00c90030_Source
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

    void __thiscall FUN_00a68bf0();
};
struct FUN_00c90030_holder
{
    void* unk00;
    void* unk04;
    FUN_00c90030_Source* unk08;
    void* unk0C;
    int unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    FUN_00c90030_Matrix unk2C;

    void __thiscall UpdateNodeState(int value);
    void __thiscall FUN_00c90030(int value);
};
extern char DAT_010c6b0c[];
void* __cdecl NiMalloc(unsigned int size);
struct NiTLargeArrayStub
{
    void* m_vtbl;
    void** m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;

    NiTLargeArrayStub(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
    {
        m_vtbl = &DAT_010c6b04;
        m_uiMaxSize = uiMaxSize;
        m_uiGrowBy = uiGrowBy;
        m_uiSize = 0;
        m_uiESize = 0;
        if (m_uiMaxSize > 0)
            m_pBase = (void**)NiMalloc(sizeof(void*) * m_uiMaxSize);
        else
            m_pBase = 0;
    }
};
struct NiTLargePrimitiveArrayStub : NiTLargeArrayStub
{
    NiTLargePrimitiveArrayStub(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
        : NiTLargeArrayStub(uiMaxSize, uiGrowBy)
    {
        m_vtbl = DAT_010c6b0c;
    }
    ~NiTLargePrimitiveArrayStub();
};
struct BaseC9
{
    virtual void v00();
    int unk04[0xc];
    BaseC9();
    ~BaseC9();
};
struct FUN_00c9aeb0 : BaseC9
{
    int unk34;
    NiTLargePrimitiveArrayStub m_kArray;
    float unk50;
    float unk54;
    int unk58;

    virtual void v00();
    FUN_00c9aeb0();
};
extern int DAT_011f4428;
struct S00c81c50_Obj;
struct S00c81c50_Arr
{
    S00c81c50_Obj** data;
    unsigned short cap;
    unsigned short size;
    unsigned short esize;
    unsigned short grow;
    unsigned short GetSize() const
    {
        return size;
    }
    S00c81c50_Obj* GetAt(unsigned int i) const
    {
        return data[i];
    }
};
struct S00c81c50_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual S00c81c50_Obj* IsSceneNode();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    S00c81c50_Obj* collision;
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
    S00c81c50_Arr children;

    S00c81c50_Obj* FUN_00653290(int* rtti);

    __forceinline S00c81c50_Obj* GetCollision()
    {
        S00c81c50_Obj* c = collision;
        if (!c)
            return 0;
        return c->FUN_00653290(&DAT_01267e64);
    }
    __forceinline S00c81c50_Obj* FirstNode()
    {
        S00c81c50_Obj* c = children.size > 0 ? children.data[0] : 0;
        if (!c)
            return 0;
        return c->FUN_00653290(&DAT_011f4428);
    }
};
struct S00c81c50_Ptr
{
    S00c81c50_Obj* m_p;
    S00c81c50_Ptr(S00c81c50_Obj* p) : m_p(p)
    {}
    S00c81c50_Ptr& operator=(S00c81c50_Obj* p)
    {
        m_p = p;
        return *this;
    }
    operator S00c81c50_Obj*() const
    {
        return m_p;
    }
};
void* __cdecl FUN_00c81c50(S00c81c50_Obj* pkNode);
struct C8AB30_Sub
{
    virtual void v00(), v04(), v08(), v0c(), v10(), v14(), v18(), v1c();
    virtual void v20(), v24(), v28(), v2c(), v30(), v34(), v38(), v3c();
    virtual void v40(), v44(), v48(), v4c(), v50(), v54(), v58(), v5c();
    virtual void v60(), v64(), v68(), v6c(), v70(), v74(), v78(), v7c();
    virtual void v80(), v84(), v88(), v8c(), v90(), v94(), v98();
    virtual bool v9c(int a);
};
struct C8AB30_Mid
{
    int unk00;
    int unk04;
    int unk08;
    C8AB30_Sub* m_0c;
};
struct C8AB30_Ref
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    C8AB30_Mid* m_1c;
};
struct C8AB30_Cls
{
    virtual void v00(), v04(), v08(), v0c(), v10(), v14(), v18(), v1c();
    virtual void v20(), v24(), v28(), v2c(), v30(), v34(), v38(), v3c();
    virtual void v40(), v44(), v48(), v4c(), v50(), v54(), v58(), v5c();
    virtual void v60(), v64(), v68(), v6c(), v70(), v74(), v78(), v7c();
    virtual void v80(), v84(), v88(), v8c(), v90(), v94(), v98(), v9c();
    virtual void vA0();

    int unk04;
    C8AB30_Ref* m_08;

    bool FUN_00c87a70(int a);
    bool FUN_00c8ab30(int a);
};
extern float DAT_010c7948[];
struct Z577
{
    unsigned char index;
    void __thiscall FUN_00ca9360(float* value);
};
struct Y577
{
    unsigned char unk00[0xbd];
    Z577 z;
};
struct A577
{
    Y577* __thiscall FUN_00ca86c0();
    unsigned char unk00[0x19d];
    unsigned char unk19d;
};
struct S_00c8cd20_object
{
    unsigned int unk00;
    unsigned int unk04;
    A577* unk08;

    float __thiscall GetFloatValue();
};
extern __declspec(thread) int g_tlsMemContext;
struct S00c89ec0_Scope
{
    int saved;
    S00c89ec0_Scope()
    {
        saved = g_tlsMemContext;
        g_tlsMemContext = 0x10;
    }
    ~S00c89ec0_Scope()
    {
        g_tlsMemContext = saved;
    }
};
struct S00c89ec0_Res
{
    bool FUN_00c68d50(int key);
};
struct S00c89ec0_Owner
{
    int unk00;
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
    S00c89ec0_Res* unk350;
    S00c89ec0_Res* GetRes()
    {
        return unk350;
    }
};
struct S00c89ec0_cls
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
    virtual S00c89ec0_Owner* getOwner();
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
    virtual void process(S00c89ec0_Res* r, int flag);
    int unk04;
    int unk08;
    bool FUN_00c89ec0();
};
__declspec(noinline) int __stdcall FUN_00c84ec0(void* apObject);
struct ShareChildShape
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual void V48();
    virtual void V49();
    virtual void V50();
    virtual void V51();
    virtual bool V52(int a1);
};
struct ShareChildObject
{
    int unk0;
    int unk4;
    ShareChildShape* shape;
};
struct ShareChildEntry
{
    ShareChildObject* pObj;
    int unk4;
    int unk8;
    int unkC;
};
struct ShareListData : hkpListShapeStub
{
    int unk14;
    ShareChildEntry* arr;
};
class ListShapeSharingView : public bhkListShapeStub
{
  public:
    __forceinline ShareListData* GetNode()
    {
        return this != 0 ? (ShareListData*)m_pHavokObject : 0;
    }

    unsigned char FUN_00c8b440(int a1);
};

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned char m128_u8[16];
};
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" void _mm_store_ss(float*, __m128);

extern unsigned int DAT_0126818c;

extern float DAT_01017d00;

extern int DAT_010c5398, DAT_0108ffb4;

struct FnvMat4
{
    __m128 m_uiX, m_uiY, m_uiZ, m_w;
};

struct ChildGroup;
struct Attachment;
struct DirectNode;

struct RuntimeObject
{

    virtual void v00();

    virtual void v01();

    virtual void v02();

    virtual ChildGroup* GetChildren();

    virtual void v04();

    virtual void v05();

    virtual void v06();

    virtual void v07();

    virtual int GetKind();

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

    virtual Attachment* GetAttachment();

    virtual void v38();

    virtual void Attach(unsigned);

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

    virtual DirectNode* GetFirst();

    virtual DirectNode* GetSecond();

    virtual void v53();

    virtual void v54();

    virtual void v55();

    virtual void v56();

    virtual void v57();

    virtual void v58();

    virtual void v59();

    virtual void v60();

    virtual void GetMatrix(FnvMat4*);
};

struct Vec
{

    __m128 value;

    void FUN_00c7f640(const void*, const void*);
};

struct CastObject;

struct SceneObjectLocal : RuntimeObject
{

    int unk04, unk08, unk0c, unk10, unk14;

    SceneObjectLocal* unk18;

    CastObject* unk1c;

    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c,
        unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94;

    float unk98;
};

struct Endpoint;

struct DirectNode
{
    int unk00, unk04;
    void* unk08;
    Endpoint* body;
    __forceinline void* GetOwner()
    {
        return unk08;
    }
};

struct AlternativeNode;

struct GraphicsObject : RuntimeObject
{

    int unk04;

    DirectNode* direct;
    __forceinline DirectNode* Gethk()
    {
        return direct;
    }

    AlternativeNode** alternate;

    __forceinline AlternativeNode* GetBody()
    {
        if (direct)
            return reinterpret_cast<AlternativeNode*>(direct->body);
        if (alternate)
            return *alternate;
        return 0;
    }
};

struct AlternativeNode : RuntimeObject
{

    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40,
        unk44, unk48, unk4c;

    __m128 position, unk60, unk70, unk80, rotation;

    AlternativeNode* FUN_00cdf6c0();
};

struct Endpoint : RuntimeObject
{

    int unk04;

    unsigned id;
};

struct CastObject
{
    int unk00, unk04, unk08, unk0c;
    void* body;
    CastObject* FUN_00653290(const void*);
};

struct ResultData
{

    __m128 unk00, unk10, position, rotation;

    float unk40, distance;
};

struct Context
{

    void* vtable;

    ResultData* synthesized;

    unsigned type, firstId, secondId;

    void EnsureHelperAllocated();

    void SetChildObject(int);

    __forceinline Context() : synthesized(0), type(1), firstId(0), secondId(0)
    {
        vtable = &DAT_010c5398;
    }

    ~Context()
    {
        vtable = &DAT_0108ffb4;
        SetChildObject(0);
    }
};

void* __cdecl FUN_00aa13e0(unsigned);

struct FUN_00c7f9e0 : RuntimeObject
{

    long refs;

    void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }

    void DecRefCount();

    unsigned unk08, unk0c;

    static void* operator new(unsigned n)
    {
        return FUN_00aa13e0(n);
    }

    FUN_00c7f9e0(const Context&);
};

typedef FUN_00c7f9e0 Result;

struct ReleaseHandle
{
    void FUN_0045cec0();
};

struct Handle
{
    Result* m_pObject;
    __forceinline Handle(Result* p) : m_pObject(p)
    {
        if (p)
            InterlockedIncrement(&p->refs);
    }
    __forceinline ~Handle()
    {
        reinterpret_cast<ReleaseHandle*>(this)->FUN_0045cec0();
    }
};

struct ListNode
{

    CastObject* item;

    ListNode* next;

    void FUN_00c80a30(const Handle&);

    void FUN_00c80aa0(const Handle&);
};

struct Parent
{
    int unk00, unk04, unk08, unk0c, unk10;
    ListNode entries;
};

struct ChildGroup
{

    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c,
        unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;

    SceneObjectLocal** children;

    unsigned short capacity, count;
};

struct Attachment
{

    unsigned unk000;

    unsigned unk004;

    unsigned unk008;

    unsigned unk00c;

    unsigned unk010;

    unsigned unk014;

    unsigned unk018;

    unsigned unk01c;

    unsigned unk020;

    unsigned unk024;

    unsigned unk028;

    unsigned unk02c;

    unsigned unk030;

    unsigned unk034;

    unsigned unk038;

    unsigned unk03c;

    unsigned unk040;

    unsigned unk044;

    unsigned unk048;

    unsigned unk04c;

    unsigned unk050;

    unsigned unk054;

    unsigned unk058;

    unsigned unk05c;

    unsigned unk060;

    unsigned unk064;

    unsigned unk068;

    unsigned unk06c;

    unsigned unk070;

    unsigned unk074;

    unsigned unk078;

    unsigned unk07c;

    unsigned unk080;

    unsigned unk084;

    unsigned unk088;

    unsigned unk08c;

    unsigned unk090;

    unsigned unk094;

    unsigned unk098;

    unsigned unk09c;

    unsigned unk0a0;

    unsigned unk0a4;

    unsigned unk0a8;

    unsigned unk0ac;

    unsigned unk0b0;

    unsigned unk0b4;

    unsigned unk0b8;

    unsigned unk0bc;

    unsigned unk0c0;

    unsigned unk0c4;

    unsigned unk0c8;

    unsigned unk0cc;

    unsigned unk0d0;

    unsigned unk0d4;

    unsigned unk0d8;

    unsigned unk0dc;

    unsigned unk0e0;

    unsigned unk0e4;

    unsigned unk0e8;

    unsigned unk0ec;

    unsigned unk0f0;

    unsigned unk0f4;

    unsigned unk0f8;

    unsigned unk0fc;

    unsigned unk100;

    unsigned unk104;

    unsigned unk108;

    unsigned unk10c;

    unsigned unk110;

    unsigned unk114;

    unsigned unk118;

    unsigned unk11c;

    unsigned unk120;

    unsigned unk124;

    unsigned unk128;

    unsigned unk12c;

    unsigned unk130;

    unsigned unk134;

    unsigned unk138;

    unsigned unk13c;

    unsigned unk140;

    unsigned unk144;

    unsigned unk148;

    unsigned unk14c;

    unsigned unk150;

    unsigned unk154;

    unsigned unk158;

    unsigned unk15c;

    unsigned unk160;

    unsigned unk164;

    unsigned unk168;

    unsigned unk16c;

    unsigned unk170;

    unsigned unk174;

    unsigned unk178;

    unsigned unk17c;

    unsigned unk180;

    unsigned unk184;

    unsigned unk188;

    unsigned unk18c;

    unsigned unk190;

    unsigned unk194;

    unsigned unk198;

    unsigned unk19c;

    unsigned unk1a0;

    unsigned unk1a4;

    unsigned unk1a8;

    unsigned unk1ac;

    unsigned unk1b0;

    unsigned unk1b4;

    unsigned unk1b8;

    unsigned unk1bc;

    unsigned unk1c0;

    unsigned unk1c4;

    unsigned unk1c8;

    unsigned unk1cc;

    unsigned unk1d0;

    unsigned unk1d4;

    unsigned unk1d8;

    unsigned unk1dc;

    unsigned unk1e0;

    unsigned unk1e4;

    unsigned unk1e8;

    unsigned unk1ec;

    unsigned unk1f0;

    unsigned unk1f4;

    unsigned unk1f8;

    unsigned unk1fc;

    unsigned unk200;

    unsigned unk204;

    unsigned unk208;

    unsigned unk20c;

    unsigned unk210;

    unsigned unk214;

    unsigned unk218;

    unsigned unk21c;

    unsigned unk220;

    unsigned unk224;

    unsigned unk228;

    unsigned unk22c;

    unsigned unk230;

    unsigned unk234;

    unsigned unk238;

    unsigned unk23c;

    unsigned unk240;

    unsigned unk244;

    unsigned unk248;

    unsigned unk24c;

    unsigned unk250;

    unsigned unk254;

    unsigned unk258;

    unsigned unk25c;

    unsigned unk260;

    unsigned unk264;

    unsigned unk268;

    unsigned unk26c;

    unsigned unk270;

    unsigned unk274;

    unsigned unk278;

    unsigned unk27c;

    unsigned unk280;

    unsigned unk284;

    unsigned unk288;

    unsigned unk28c;

    unsigned unk290;

    unsigned unk294;

    unsigned unk298;

    unsigned unk29c;

    unsigned unk2a0;

    unsigned unk2a4;

    unsigned unk2a8;

    unsigned unk2ac;

    unsigned unk2b0;

    unsigned unk2b4;

    unsigned unk2b8;

    unsigned unk2bc;

    unsigned unk2c0;

    unsigned unk2c4;

    unsigned unk2c8;

    unsigned unk2cc;

    unsigned unk2d0;

    unsigned unk2d4;

    unsigned unk2d8;

    unsigned unk2dc;

    unsigned unk2e0;

    unsigned unk2e4;

    unsigned unk2e8;

    unsigned unk2ec;

    unsigned unk2f0;

    unsigned unk2f4;

    unsigned unk2f8;

    unsigned unk2fc;

    unsigned unk300;

    unsigned unk304;

    unsigned unk308;

    unsigned unk30c;

    unsigned unk310;

    unsigned unk314;

    unsigned unk318;

    unsigned unk31c;

    unsigned unk320;

    unsigned unk324;

    unsigned unk328;

    unsigned unk32c;

    unsigned unk330;

    unsigned unk334;

    unsigned unk338;

    unsigned unk33c;

    unsigned unk340;

    unsigned unk344;

    unsigned unk348;

    unsigned unk34c;

    unsigned value;
};

void __cdecl FUN_00cdff60(DirectNode*, void*);

static __forceinline int kind(AlternativeNode* p)
{
    return p->GetKind();
}

static __forceinline Endpoint* getFirst(GraphicsObject* p)
{
    DirectNode* d = p->GetFirst();
    return d ? d->body : 0;
}

static __forceinline Endpoint* getSecond(GraphicsObject* p)
{
    DirectNode* d = p->GetSecond();
    return d ? d->body : 0;
}

static __forceinline float length3(__m128 value)
{

    __m128 n = _mm_mul_ps(value, value);

    __m128 sq = _mm_shuffle_ps(n, n, 0x55);

    sq = _mm_add_ss(sq, n);

    n = _mm_shuffle_ps(n, n, 0xaa);

    n = _mm_add_ss(n, sq);

    float f;
    _mm_store_ss(&f, _mm_sqrt_ss(n));
    return f;
}

struct SceneModeGuard
{

    int m_saved;

    SceneModeGuard()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~SceneModeGuard()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

// @fnv 0x00c80ce0
void __cdecl FUN_00c80ce0(SceneObjectLocal* owner, int notification)
{

    SceneModeGuard mode;

    if (!owner || notification != 8)
        return;

    if (owner->unk1c)
    {

        CastObject* v = owner->unk1c->FUN_00653290(&DAT_012043f8);

        Parent* parent = v ? (Parent*)v->body : 0;

        if (parent)
        {

            ListNode* entries = &parent->entries;

            for (; entries && entries->item; entries = entries->next)
            {

                GraphicsObject* current = (GraphicsObject*)entries->item->FUN_00653290(&DAT_0126818c);

                if (current != 0)
                {

                    Endpoint* first = 0;

                    Endpoint* context = 0;

                    Vec pos, rot;

                    switch (kind(current->GetBody()))
                    {

                    case 7: {

                        AlternativeNode* node = current->GetBody();

                        pos.value = node->position;
                        rot.value = node->rotation;

                        first = getFirst(current);
                        context = getSecond(current);

                        break;
                    }

                    case 2: {

                        AlternativeNode* node = current->GetBody();

                        pos.value = node->position;
                        rot.value = node->rotation;

                        first = getFirst(current);
                        context = getSecond(current);

                        break;
                    }

                    case 13: {

                        AlternativeNode* node = current->GetBody()->FUN_00cdf6c0();

                        if (kind(node) == 7)
                        {

                            pos.value = node->position;
                            rot.value = node->rotation;

                            first = getFirst(current);
                            context = getSecond(current);
                        }

                        if (kind(node) == 2)
                        {

                            pos.value = node->position;
                            rot.value = node->rotation;

                            first = getFirst(current);
                            context = getSecond(current);
                        }

                        break;
                    }

                    default:
                        continue;
                    }

                    if (first && context)
                    {

                        Context second;

                        second.EnsureHelperAllocated();

                        second.firstId = first->id;
                        second.secondId = context->id;

                        if (second.synthesized)
                        {
                            second.synthesized->position = pos.value;
                            second.synthesized->rotation = rot.value;
                        }

                        FnvMat4 firstRecord, secondRecord;

                        Vec transformedFirst, transformedSecond;

                        first->GetMatrix(&firstRecord);

                        context->GetMatrix(&secondRecord);

                        transformedFirst.FUN_00c7f640(&firstRecord, &pos);

                        transformedSecond.FUN_00c7f640(&secondRecord, &rot);

                        transformedFirst.value = _mm_sub_ps(transformedFirst.value, transformedSecond.value);

                        float distance = length3(transformedFirst.value);

                        if (distance == 0.0f)
                            distance = DAT_01017d00;

                        if (second.synthesized)
                            second.synthesized->distance = distance;

                        Result* cast = new Result(second);

                        Attachment* attach = first->GetAttachment();

                        unsigned idx = attach ? attach->value : 0;
                        if (current->Gethk()->GetOwner())
                            FUN_00cdff60(current->Gethk(), current->Gethk()->GetOwner());

                        if (entries->next)
                            entries->next->FUN_00c80a30(cast);

                        else
                            entries->FUN_00c80aa0(cast);

                        if (cast)
                            cast->Attach(idx);
                    }
                }
            }
        }
    }

    ChildGroup* children = owner->GetChildren();

    if (children)
        for (unsigned i = 0; i < children->count; ++i)
            FUN_00c80ce0(children->children[i], 8);
}

namespace BlendTransformDetail {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned char m128_u8[16];
};
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
struct VecLocal
{
    __m128 v;
    VecLocal& operator=(const VecLocal& b)
    {
        v = b.v;
        return *this;
    }
};
struct QuatLocal : VecLocal
{
    void FUN_00cb26e0(const struct RotLocal&);
    void FUN_00cb2850(const QuatLocal&, const QuatLocal&, float);
    void FUN_005611c0();
};
struct RotLocal
{
    VecLocal columns[3];
    void FUN_00cb2d90(const QuatLocal&);
};
struct TransLocal
{
    RotLocal rotation;
    VecLocal position;
};
struct MatrixLocal
{
    float m[3][3];
};
struct SceneTransLocal
{
    MatrixLocal rotation;
    NiPoint3 position;
    float scale;
};
struct SceneLocal
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30;
    SceneTransLocal local, world;
    void FUN_00a68bf0();
};
struct BodyLocal
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
    virtual void GetPosition(VecLocal&);
    virtual void GetRotation(QuatLocal&);

    void FUN_00561690(const VecLocal&);
    void FUN_005617c0(const VecLocal&);
    void FUN_00c8de20(const VecLocal&, const QuatLocal&, float, float);
};
struct TargetLocal
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned int count;
};
struct LockLocal
{
    unsigned int owner, count;
    void Lock(char*);
    void Unlock()
    {
        if (--count == 0)
            owner = 0;
    }
};
extern LockLocal DAT_01267b80;
extern float DAT_011afe64;
extern float DAT_01267e6c;
extern VecLocal DAT_01267e30;
extern __m128 DAT_010ec7f0;
void VisitAndFetchThree(RotLocal*, const MatrixLocal*);
extern "C" void __cdecl FUN_00624b10(MatrixLocal*, RotLocal*);
void FUN_00458620(NiPoint3*, VecLocal*);
struct BlendLocal
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
    virtual void Reset();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void Publish(SceneTransLocal*);

    int unk04;
    SceneLocal* scene;
    unsigned short flags, unk0e;
    BodyLocal* body;
    unsigned int unk14;
    float heirGain, velGain;
    unsigned int motion;
    TargetLocal* target;
    unsigned int unk28;
    void FUN_00c65f40(unsigned int, BodyLocal*, bool);
    void FUN_00c65a80();
    void FUN_00c81aa0();
    void FUN_00c81e30();
};
extern "C" unsigned long __readfsdword(unsigned long);
struct TlsModeLocal
{
    int value;
};
struct TlsLocal : ThreadTlsBlock
{
    int unk2b8, unk2bc;
    TlsModeLocal mode;
};
inline TlsModeLocal& GetBlendMode()
{
    return ((TlsLocal*)&g_tls)->mode;
}
// @fnv 0x00c81e30
void BlendLocal::FUN_00c81e30()
{
    SceneLocal* node = scene;
    BodyLocal* rigid = body;
    bool forced = (flags & 0x100) != 0;
    float timestep = DAT_011afe64;
    unsigned int desiredMotion = 1;
    int mode;
    TlsModeLocal* tls;
    if (heirGain == 0.0f)
    {
        int state = GetBlendMode().value;
        tls = &GetBlendMode();
        if (state == 1)
        {
            node->FUN_00a68bf0();
            return;
        }
        mode = velGain == 0.0f || forced ? 1 : 0;
    }
    else if (heirGain == 1.0f)
    {
        tls = &GetBlendMode();
        mode = GetBlendMode().value == 2 ? 1 : 2;
        desiredMotion = 4;
    }
    else
    {
        tls = &GetBlendMode();
        mode = GetBlendMode().value == 2 ? 1 : 0;
    }
    bool changed = false;
    if (motion != desiredMotion)
    {
        if (motion == 4)
            Reset();
        else if (rigid)
        {
            rigid->FUN_00561690(DAT_01267e30);
            rigid->FUN_005617c0(DAT_01267e30);
        }
        DAT_01267b80.Lock(0);
        FUN_00c65f40(desiredMotion, rigid, false);
        DAT_01267b80.Unlock();
        motion = desiredMotion;
        changed = true;
    }
    switch (mode)
    {
    case 0: {
        node->FUN_00a68bf0();
        SceneTransLocal& world = node->world;
        NiPoint3& worldPosition = world.position;
        VecLocal position;
        position.v.m128_f32[0] = worldPosition.x * DAT_01267e6c;
        position.v.m128_f32[1] = worldPosition.y * DAT_01267e6c;
        position.v.m128_f32[2] = worldPosition.z * DAT_01267e6c;
        position.v.m128_f32[3] = 0.0f;
        RotLocal converted;
        VisitAndFetchThree(&converted, &world.rotation);
        QuatLocal desiredRotation;
        desiredRotation.FUN_00cb26e0(converted);
        VecLocal currentPosition;
        rigid->GetPosition(currentPosition);
        QuatLocal currentRotation;
        rigid->GetRotation(currentRotation);
        VecLocal blendedPosition;
        float blend = heirGain;
        __m128 t = _mm_load_ss(&blend);
        t = _mm_shuffle_ps(t, t, 0);
        blendedPosition.v =
            _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, t), currentPosition.v), _mm_mul_ps(position.v, t));
        QuatLocal blendedRotation;
        blendedRotation.FUN_00cb2850(currentRotation, desiredRotation, heirGain);
        blendedRotation.FUN_005611c0();
        TransLocal output;
        output.position = forced ? blendedPosition : position;
        output.rotation.FUN_00cb2d90(blendedRotation);
        FUN_00624b10(&world.rotation, &output.rotation);
        FUN_00458620(&worldPosition, &output.position);
        if (tls->value == 0)
            Publish(&world);
        float inverseTimestep = timestep != 0.0f ? 1.0f / timestep : 1.0f;
        float gain = forced ? 1.0f : velGain;
        rigid->FUN_00c8de20(blendedPosition, blendedRotation, inverseTimestep, gain);
        break;
    }
    case 1:
        FUN_00c65a80();
        break;
    case 2:
        Reset();
        break;
    }
    if (changed && target && target->count <= 0)
        FUN_00c81aa0();
}
}

struct LayerGain
{
    float fHeir;
    float fVel;
};
extern LayerGain DAT_011b06d8[];

struct HkObjBase
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
struct HkCollidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_uiFilterInfo;
};
struct HkWorldObj : HkObjBase, HkCollidable
{
    void FUN_00c9c1d0();
};

struct WorldObj
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
    virtual void SetBlendTarget(int target);
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
    virtual bool SetMotionType(int motion);

    int unk04;
    HkWorldObj* m_pkHkObj;
    int unk0C;
    unsigned int m_uiValue1;

    void FUN_00a29680();

    unsigned int GetFilterInfo()
    {
        HkCollidable* c = m_pkHkObj;
        return c ? c->m_uiFilterInfo : 0;
    }
    static bool IsBlendLayer(unsigned int uiInfo)
    {
        unsigned int uiLayer = uiInfo & 0x7f;
        return uiLayer == 8 || uiLayer == 0x1d;
    }
};

struct TimeCtrl
{
    int unk00;
    int unk04;
    unsigned short m_usFlags;
};

struct SceneObj
{
    TimeCtrl* GetController(const int* rtti);
};

extern int DAT_012681c0;
extern int DAT_012681f0;

struct BlendCollObj
{
    int unk00;
    int unk04;
    SceneObj* m_pkSceneObject;
    unsigned short m_usFlags;
    unsigned short unk0E;
    WorldObj* m_spWorldObject;
    int unk14;
    float m_fHeirGain;
    float m_fVelGain;
    int m_iMotion;
    int m_iBlendTarget;

    void FUN_00c81890();
    void FUN_00c81a50();
    void FUN_00c823b0(int iMotion, DynCastHelper* pkObj, bool bFlag);
};

// @fnv 0x00c823b0
void BlendCollObj::FUN_00c823b0(int iMotion, DynCastHelper* pkObj, bool bFlag)
{
    WorldObj* pkBody = pkObj == 0 ? 0 : (WorldObj*)pkObj->DynamicCast((unsigned int const*)&DAT_012681c0);
    float fHeir = FUN_00c8cce0(&iMotion) ? 0.0f : 1.0f;
    float fVel = fHeir;
    if (pkBody || (pkBody = m_spWorldObject) != 0)
    {
        unsigned int uiInfo = pkBody->GetFilterInfo();
        if (WorldObj::IsBlendLayer(uiInfo))
        {
            unsigned int uiIdx = (uiInfo >> 8) & 0x1f;
            float fScale = DAT_011b06d8[uiIdx].fHeir;
            if (fScale > 1.0f)
            {
                fHeir = 1.0f;
                fVel = 1.0f;
            }
            else
            {
                fVel = DAT_011b06d8[uiIdx].fVel * fHeir;
                fHeir = fHeir * fScale;
            }
            m_usFlags &= 0xfdff;
            if (FUN_00c8cce0(&iMotion))
            {
                if (bFlag)
                {
                    HkWorldObj* pkHk = pkBody->m_pkHkObj;
                    if (pkHk)
                    {
                        pkBody->FUN_00a29680();
                        pkHk->FUN_00c9c1d0();
                        pkBody->FUN_00a29680();
                    }
                }
                if (m_pkSceneObject)
                {
                    TimeCtrl* pkCtrl = m_pkSceneObject->GetController(&DAT_012681f0);
                    if (pkCtrl)
                        pkCtrl->m_usFlags &= 0xfff7;
                }
            }
        }
        else if (!pkBody->SetMotionType(iMotion) && FUN_00c8cce0(&iMotion))
        {
            fHeir = 1.0f;
            fVel = 1.0f;
        }
    }
    m_fVelGain = fVel;
    m_fHeirGain = fHeir;
    if (m_iMotion != iMotion && !(bool)(m_usFlags >> 6 & 1) && !(bool)(pkBody->m_uiValue1 >> 6 & 1))
        FUN_00c81890();
    FUN_00c81a50();
    WorldObj* pkWorld = m_spWorldObject;
    if (pkWorld)
    {
        if (WorldObj::IsBlendLayer(pkWorld->GetFilterInfo()) && m_iBlendTarget)
            pkWorld->SetBlendTarget(m_iBlendTarget);
    }
}

extern int DAT_01267e64;
struct PhysicsInfo
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
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    unsigned char motionType;
};
struct PhysicsLink
{
    int unk00, unk04;
    PhysicsInfo* info;
};
struct SharedBody
{
    virtual void slot00();
    virtual void release();
    volatile long references;
    PhysicsInfo* info;
};
struct BodyReference
{
    SharedBody* body;
    BodyReference(SharedBody* value) : body(value)
    {
        if (body)
            InterlockedIncrement(&body->references);
    }
    ~BodyReference()
    {
        if (body)
        {
            if (InterlockedDecrement(&body->references) == 0)
                body->release();
        }
    }
};
struct Controller892 : TargetController
{
    virtual void slot90();
    virtual void slot94();
    virtual void setTarget(void*);
};
struct Scene892 : SceneObject
{
    void AttachTarget(void*);
};
struct Shape892
{
    int unk00, unk04;
    Scene892* scene;
    unsigned short flags;
    unsigned short unk0E;
    SharedBody* body;
    int unk14;
    float scale18, scale1C;
    int mode;
    struct Pair
    {
        volatile int first, second;
        Pair& operator=(const Pair& other)
        {
            first = other.first;
            second = other.second;
            return *this;
        }
    } values;
    Shape892* FUN_00653290(int*);
    void FUN_00c6b980(SharedBody*);
    void FUN_00c89050(int, int, int, int);
    void FUN_00c892c0(int, int, int, Shape892*, int);
};
// @fnv 0x00c892c0
void Shape892::FUN_00c892c0(int arg0, int arg1, int arg2, Shape892* source, int arg4)
{
    TlsFlagGuard context;
    if (arg1 && arg2 && source)
    {
        flags |= 0x41;
        int value;
        const Shape892* settings = source->FUN_00653290(&DAT_01267e64);
        if (settings)
        {
            scale18 = settings->scale18;
            scale1C = settings->scale1C;
            value = settings->values.first;
            values.first = value;
            value = settings->values.second;
            values.second = value;
            value = settings->mode;
            mode = value;
        }
        else
        {
            scale1C = scale18 = 1.0f;
            mode = 4;
        }
        BodyReference saved(source->body);
        source->FUN_00c6b980(0);
        Scene892* scene = source->scene;
        scene->AttachTarget(this);
        FUN_00c6b980(saved.body);
        FUN_00c89050(1, arg0, arg1, arg4);
        if (body)
        {
            int motion = body->info ? body->info->motionType : 5;
            if (FUN_00c8cce0(&motion))
            {
                scale1C = scale18 = 0.0f;
                mode = 1;
            }
        }
        Controller892* controller = static_cast<Controller892*>(scene->FUN_00a5c570(&DAT_012681f0));
        if (!controller)
            controller = reinterpret_cast<Controller892*>(new FUN_00c9aeb0_t);
        controller->flags |= 8;
        controller->setTarget(scene);
    }
}

struct EventE610
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* m_pvSource;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    const void* m_pkPair;
    int unk4c;
    __m128 m_vContactPosition;
    __m128 m_vHitNormal;
};

class ListenerE610
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void OnEvent(EventE610& kEvent);
};

struct WorldE610
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
    ListenerE610* m_pkListener;
};

struct EntityE610
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
    WorldE610* m_pkWorld;
};

struct PairE610
{
    int unk00;
    int unk04;
    EntityE610* m_apkEntities[2];
    char m_cEntityOffset;
    EntityE610* GetEntity() const
    {
        return *(EntityE610* const*)((const char*)m_apkEntities + m_cEntityOffset);
    }
};

// @fnv 0x00c9e610
void __stdcall FUN_00c9e610(void* pvSource, const PairE610* pkPair, void* pvUnused)
{
    EventE610 kEvent;
    kEvent.m_pvSource = pvSource;
    kEvent.m_pkPair = pkPair;
    EntityE610* pkEntity = pkPair->GetEntity();
    WorldE610* pkWorld = pkEntity ? pkEntity->m_pkWorld : 0;
    pkWorld->m_pkListener->OnEvent(kEvent);
}

union __declspec(intrin_type) __declspec(align(16)) WaterLeaveVector
{
    struct
    {
        float x, y, z, w;
    };
    signed char bytes[16];
};

struct WaterLeaveListener
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void OnEvent(void* pkEvent);
};

struct WaterLeaveUserWorld
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
    WaterLeaveListener* m_pkListener;
};

struct WaterLeavePhysicsWorld
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
    WaterLeaveUserWorld* m_pkUserWorld;

    WaterLeaveUserWorld* WaterLeaveGetUserWorld() const
    {
        return m_pkUserWorld;
    }
};

struct WaterLeaveWorldObject
{
    void* vptr;
    int m_usMemSizeAndFlags;
    WaterLeavePhysicsWorld* m_pOwningWorld;
    struct UserObject
    {
        int unk00;
        int unk04;
        int unk08;
        int unk0c;
        unsigned int m_uiValue1;
    }* m_ulUserData;
};

struct WaterLeaveCollidable
{
    void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    void* m_pMotionState;
    void* m_parent;
    signed char m_iOwnerOffset;
    char m_uiForceCollideOntoPpu;
    short m_uiShapeSizeOnSpu;
    unsigned int m_broadPhaseId;
    signed char m_cBroadPhaseType;

    void* getOwner() const
    {
        return const_cast<char*>(reinterpret_cast<const char*>(this)) + m_iOwnerOffset;
    }
};

struct __declspec(align(16)) WaterLeaveContact
{
    WaterLeaveVector position;
    WaterLeaveVector separatingNormal;
    void* rootCollidableA;
    unsigned int shapeKeyA;
    unsigned int shapeKeysA[8];
    WaterLeaveCollidable* rootCollidableB;
    unsigned int shapeKeyB;
    unsigned int shapeKeysB[8];
};

inline WaterLeaveUserWorld* WaterLeaveGetUserWorld(WaterLeaveWorldObject* pkObject)
{
    WaterLeavePhysicsWorld* pkWorld = pkObject->m_pOwningWorld;
    return pkWorld ? pkWorld->WaterLeaveGetUserWorld() : 0;
}

// @fnv 0x00c9e670
void __stdcall FUN_00c9e670(void* pArg, WaterLeaveCollidable* pkCollidable)
{
    WaterLeaveContact kEvent;
    kEvent.rootCollidableA = pArg;
    kEvent.rootCollidableB = pkCollidable;
    WaterLeaveUserWorld* pkWorld =
        WaterLeaveGetUserWorld(static_cast<WaterLeaveWorldObject*>(pkCollidable->getOwner()));
    if (pkWorld)
        pkWorld->m_pkListener->OnEvent(&kEvent);

    if (pkCollidable->m_cBroadPhaseType == 1)
    {
        WaterLeaveWorldObject* pkOwner = static_cast<WaterLeaveWorldObject*>(pkCollidable->getOwner());
        if (pkOwner)
        {
            WaterLeaveWorldObject::UserObject* pkUser = pkOwner->m_ulUserData;
            if (pkUser)
                pkUser->m_uiValue1 &= ~8u;
        }
    }
}

union __declspec(align(16)) NormalE700
{
    float components[4];
    unsigned char bytes[16];
};

struct BoolE700
{
    char m_cBooleanValue;
    BoolE700()
    {}
    BoolE700(bool b)
    {
        m_cBooleanValue = b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct RayInputE700;

struct RayOutputE700
{
    NormalE700 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int m_unk18;
    int m_unk1c;
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    RayOutputE700() : m_fHitFraction(1.0f), m_iExtraInfo(-1)
    {
        m_uiShapeKeys[0] = 0xffffffff;
        m_uiShapeKeyIndex = 0;
    }
    BoolE700 HasHit() const;
};

class ShapeE700
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual BoolE700 CastRay(const RayInputE700& kInput, RayOutputE700& kOutput) const;
};

struct ContainerShapeE700
{
    void* vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    int m_type;
    const ShapeE700* m_pkChild;
};

struct CdBodyE700;

struct ParentE700
{
    const ContainerShapeE700* m_pkShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pvMotion;
};

struct CdBodyE700
{
    const void* m_pkShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pvMotion;
    const ParentE700* m_pParentNode;
};

class RayHitCollectorE700
{
  public:
    virtual void AddRayHit(const CdBodyE700& kBody, const RayOutputE700& kOutput);
};

// @fnv 0x00c9e700
void __stdcall FUN_00c9e700(const RayInputE700& kInput, const CdBodyE700& kBody, RayHitCollectorE700* pkCollector)
{
    ScopedMemoryCategory kScope;
    const ParentE700* pkParent = kBody.m_pParentNode;
    if (pkParent)
    {
        const ContainerShapeE700* pkShape = pkParent->m_pkShape;
        if (pkParent->m_pvMotion && pkShape && pkShape->m_type == 0x1b)
        {
            const ShapeE700* pkChild = pkShape->m_pkChild;
            if (pkChild)
            {
                RayOutputE700 kOutput;
                pkChild->CastRay(kInput, kOutput);
                if (kOutput.HasHit())
                    pkCollector->AddRayHit(kBody, kOutput);
            }
        }
    }
}

namespace RigidCinfoSimd {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    struct
    {
        float x, y, z, w;
    };
    unsigned char m128_u8[16];
};
extern "C" __m128 _mm_load_ps(float const*);
extern "C" void _mm_store_ps(float*, __m128);
}

struct __declspec(align(16)) Vector482
{
    RigidCinfoSimd::__m128 value;
};

struct Config482
{

    unsigned unk00;

    unsigned unk04;

    unsigned unk08;

    unsigned unk0c;

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

    Vector482 inertia;

    unsigned unk60;

    unsigned unk64;

    unsigned unk68;

    unsigned unk6c;

    unsigned unk70;

    unsigned unk74;

    unsigned unk78;

    unsigned unk7c;

    Vector482 centerOfMass;

    float mass, linearDamping, angularDamping;

    unsigned unk9c, unka0, unka4;

    float maxLinearVelocity, maxAngularVelocity;

    unsigned unkb0, unkb4, unkb8, unkbc;
};

struct Info482
{
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Config482 config;
};

struct MotionInterface482
{

    virtual void Method0();
    virtual void Method1();
    virtual void Method2();
    virtual void Method3();
    virtual void Method4();

    virtual void GetInertia(Vector482*);
};

struct Motion482 : MotionInterface482
{

    unsigned unk04;

    unsigned unk08;

    unsigned unk0c;

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

    Vector482 centerOfMass;

    unsigned unka0, unka4, unka8, unkac, unkb0;

    float linearDamping, angularDamping;

    float FUN_00c86430();
};

struct Collidable482
{
};

struct Body482
{

    unsigned unk00, unk04, unk08, unk0c;

    Collidable482 collidable;

    Collidable482* GetCollidable()
    {
        return &collidable;
    }

    void WriteToInfo(Config482*);

    Motion482* FUN_00ca86c0();
};

struct WrapperInterface482
{
    virtual void Method();
};

struct Wrapper482 : WrapperInterface482
{

    unsigned unk04;

    Body482* body;

    void FillOutputFromState(Info482*);

    float FUN_00577b50();

    float GetFloatValue();

    void FUN_00c8cfd0(Info482*);
};

// @fnv 0x00c8cfd0
void Wrapper482::FUN_00c8cfd0(Info482* info)
{

    FillOutputFromState(info);

    if (body)
    {

        body->WriteToInfo(&info->config);

        Motion482* motion = body ? body->FUN_00ca86c0() : 0;

        if (motion)
        {

            info->config.mass = motion->FUN_00c86430();

            RigidCinfoSimd::_mm_store_ps((float*)info->config.centerOfMass.value.m128_u8,
                                         RigidCinfoSimd::_mm_load_ps((float*)motion->centerOfMass.value.m128_u8));

            info->config.linearDamping = motion->linearDamping;

            info->config.angularDamping = motion->angularDamping;

            motion->GetInertia(&info->config.inertia);

            RigidCinfoSimd::_mm_store_ps((float*)info->config.centerOfMass.value.m128_u8,
                                         RigidCinfoSimd::_mm_load_ps((float*)motion->centerOfMass.value.m128_u8));
        }

        if (body && body->GetCollidable())
        {

            info->config.maxLinearVelocity = FUN_00577b50();

            info->config.maxAngularVelocity = GetFloatValue();
        }
    }
}

namespace WorldPositionDetail {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned char m128_u8[16];
};
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_and_ps(__m128, __m128);
extern "C" __m128 _mm_cmple_ps(__m128, __m128);
extern "C" __m128 _mm_set_ps1(float);
extern "C" int _mm_movemask_ps(__m128);

extern "C" double fabs(double);

extern __m128 DAT_01017d10;
extern float DAT_01016248;

struct WorldWrapAdjust : FUN_00c9a070_shell
{
    void AdjustVector(float*);
};

__declspec(noinline) void WorldWrapAdjust::AdjustVector(float* p)
{
    Adjust_00c9a070(p[0], p[0], fHi[0], fLo[0]);
    Adjust_00c9a070(p[1], p[1], fHi[1], fLo[1]);
    Adjust_00c9a070(p[2], p[2], fHi[2], fLo[2]);
}
struct PositionTarget
{
    void FUN_00c66c00(float* value);
};

struct MotionBounds
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
    __m128 m_60;
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
    float m_b0[3];

    bool FUN_00c9a1f0(__m128* value);
};

// @fnv 0x00c9a1f0
bool MotionBounds::FUN_00c9a1f0(__m128* value)
{
    bool hit = false;
    __m128 base = m_60;
    __m128 input = *value;
    __m128 d = _mm_sub_ps(input, base);
    for (unsigned int i = 0; i < 3; ++i)
    {
        if (hit)
            break;
        float t = (float)fabs(((float*)&d)[i]);
        hit = (t >= m_b0[i]);
    }
    if (hit)
    {
        d = input;
        ((WorldWrapAdjust*)this)->AdjustVector((float*)&d);
        __m128 diff = _mm_sub_ps(d, base);
        __m128 absdiff = _mm_and_ps(diff, DAT_01017d10);
        __m128 cmp = _mm_cmple_ps(absdiff, _mm_set_ps1(DAT_01016248));
        unsigned int mask = _mm_movemask_ps(cmp) & 7;
        bool result = mask != 7;
        if (result)
            ((PositionTarget*)this)->FUN_00c66c00((float*)&d);
        hit = result;
    }
    return hit;
}

}
