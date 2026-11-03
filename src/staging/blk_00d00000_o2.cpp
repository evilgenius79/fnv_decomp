
// src/staging/blk_00d00000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @fnv 0x00d1a300
void __cdecl InitArrayEntries(int** apEntries, int count)
{
    int i = 0;
    if (count > 0)
    {
        do
        {
            int* p = apEntries[i] + 12;
            ++i;
            *(int*)p = 1;
            *(int*)((char*)p + 0x10) = 0;
        } while (i < count);
    }
}

// @fnv 0x00d081f0
int __cdecl CompareByNestedValue(int** ppLeft, int** ppRight)
{
    return *(int**)(*(ppLeft + 1) + 5) < *(int**)(*(ppRight + 1) + 5);
}

struct FUN_00d97710_class
{
    void ClearEntryByKey(int);
};
struct FUN_00d0a270_class
{
    void* p0;
    void* p4;
    void* p8;
    void* pc;
    FUN_00d97710_class* pv;
    void FUN_00d0a270(int ai);
};
// @fnv 0x00d0a270
void FUN_00d0a270_class::FUN_00d0a270(int ai)
{
    pv->ClearEntryByKey(ai + 0x10);
}

struct D107A0RTTI;
extern D107A0RTTI g_D107A0RTTI;

// @fnv 0x00d10790
D107A0RTTI* __cdecl FUN_00d10790()
{
    return &g_D107A0RTTI;
}

extern int DAT_010cd54c;

struct FUN_00d107b0
{
    void** vft;
    unsigned short a;
    unsigned short b;
    int c;
    FUN_00d107b0();
};

// @fnv 0x00d107b0
FUN_00d107b0::FUN_00d107b0()
{
    b = 1;
    c = 0;
    vft = (void**)&DAT_010cd54c;
}

struct FUN_00c9ce00_cls
{
    void FUN_00c9ce00(int);
};

// @fnv 0x00d1f180
void __cdecl FUN_00d1f180(FUN_00c9ce00_cls* obj, int v)
{
    if (obj)
        obj->FUN_00c9ce00(v);
}

struct FUN_00d1fa20_t
{
    int m_uiCount;
    void ResetEntries();
};
// @fnv 0x00d1fa20
void FUN_00d1fa20_t::ResetEntries()
{
    for (int i = 0; i < *(int*)((char*)this + 0x1c); ++i)
        *(unsigned int*)((char*)*(unsigned char**)((char*)this + 0x18) + i * 4) = 1;
    *(unsigned char*)((char*)this + 0x24) = 0;
}

struct SpawnedAllocator
{
    virtual void v0();
    virtual void* Alloc(unsigned int size);
    virtual void Free(void* p, unsigned int size);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    SpawnedAllocator* m_pAllocator;
};

AllocHolder* FUN_00c85750();
extern "C" void __cdecl FUN_00ec44d0(void* dst, const void* src, unsigned int size);

struct FUN_00d06c30_cls
{
    char* m_pData;
    unsigned short m_usElementCount;
    unsigned short m_usCap;
};

// @fnv 0x00d06c30
extern "C" void __cdecl FUN_00d06c30(FUN_00d06c30_cls* self, unsigned int newCap, unsigned int elemSize)
{
    AllocHolder* holder = FUN_00c85750();
    SpawnedAllocator* alloc = holder->m_pAllocator;
    char* newBuf = (char*)alloc->Alloc(newCap * elemSize);
    FUN_00ec44d0(newBuf, self->m_pData, self->m_usElementCount * elemSize);
    if ((self->m_usCap & 0x8000) == 0)
    {
        unsigned int size = (self->m_usCap & 0x3fff) * elemSize;
        char* oldBuf = self->m_pData;
        holder = FUN_00c85750();
        alloc = holder->m_pAllocator;
        alloc->Free(oldBuf, size);
    }
    self->m_pData = newBuf;
    self->m_usCap = (unsigned short)((self->m_usCap & 0x4000) | (unsigned short)newCap);
}

class FUN_00d07910_cls;

class FUN_00d07910_elem
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10(FUN_00d07910_cls* owner);
};

class FUN_00d07910_cls
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
    FUN_00d07910_elem** m_98;
    int m_9C;
    void NotifyElements();
};

// Iterates the m_98 element array backwards and calls v10(this) on each non-null element.
// @fnv 0x00d07910
void FUN_00d07910_cls::NotifyElements()
{
    for (int i = m_9C - 1; i >= 0; --i)
    {
        FUN_00d07910_elem** ppSlot = &m_98[i];
        if (m_98[i] != 0)
        {
            FUN_00d07910_elem* e = *ppSlot;
            e->v10(this);
        }
    }
}

// File-static helper with a compiler-chosen register convention.
// @fnv 0x00d10ab0
static __declspec(noinline) unsigned int FUN_00d10ab0(unsigned int uiValue)
{
    if (uiValue != 0xffff)
        uiValue++;
    return uiValue | 1;
}

unsigned int D10AB0NextOdd(const unsigned int* puiValue)
{
    return FUN_00d10ab0(*puiValue);
}

extern int DAT_01268838;

// @fnv 0x00d1f110
int* __cdecl FUN_00d1f110()
{
    return &DAT_01268838;
}

extern int g_unk01268868;

// @fnv 0x00d1f130
void* __cdecl FUN_00d1f130()
{
    return &g_unk01268868;
}

// FUN_00d1f140 : a one-line function - getter
extern int g_target_00d1f140;
// @fnv 0x00d1f140
void* FUN_00d1f140()
{
    return &g_target_00d1f140;
}

class D1F150Object
{
  public:
    virtual ~D1F150Object();
};

// @fnv 0x00d1f150
void FUN_00d1f150(D1F150Object* pkObject)
{
    pkObject->~D1F150Object();
}

extern int DAT_012688c8;
// @fnv 0x00d1f160
int* __cdecl FUN_00d1f160()
{
    return &DAT_012688c8;
}

struct FUN_00d1f1c0_target
{
    void Run();
};

// @fnv 0x00d1f1c0
void __cdecl FUN_00d1f1c0(FUN_00d1f1c0_target* pTarget)
{
    pTarget->Run();
}

struct S_00d1f730_Base
{
    S_00d1f730_Base(int a, int b);
    virtual void vfn00();
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
};

struct S_00d1f730_Arr
{
    int* m_data;
    int m_iElementCount;
    unsigned m_cap;
    S_00d1f730_Arr()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_cap = 0x80000000;
    }
};

struct S_00d1f730_Flag
{
    char v;
    S_00d1f730_Flag()
    {
        v = 0;
    }
};

struct FUN_00d1f730 : S_00d1f730_Base
{
    FUN_00d1f730(int a, int b, int c);
    virtual void vfn00();
    S_00d1f730_Arr unk160;
    S_00d1f730_Flag unk16c;
};

// Constructs the object from the base constructor and stores the third argument into unk2c.
// @fnv 0x00d1f730
FUN_00d1f730::FUN_00d1f730(int aiArg1, int aiArg2, int aiValue) : S_00d1f730_Base(aiArg1, aiArg2)
{
    unk2c = aiValue;
}

struct D01E50Node
{
    unsigned char kind;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int payload;
};
int __cdecl FUN_00d95cf0(int, void*, D01E50Node*);
int __cdecl FUN_00d94df0(int, void*, D01E50Node*);
int __cdecl ExecuteConstraintCallbacks(int, void*, D01E50Node*);
int __cdecl FUN_00d94a80(int, void*, D01E50Node*);
int __cdecl FUN_00d947e0(int, void*, D01E50Node*);
int __cdecl FUN_00d944d0(int, void*, D01E50Node*);
int __cdecl FUN_00d94570(int, void*, D01E50Node*);
int __cdecl LogIntegrateVelocity(int, void*, D01E50Node*);
int __cdecl FUN_00d94730(int, void*, D01E50Node*);
int __cdecl FUN_00d943d0(int, void*, D01E50Node*);
int __cdecl FUN_00d93ba0(int, void*, D01E50Node*);
int __cdecl FUN_00d93380(int, void*, D01E50Node*);
int __cdecl AccumulateShapes(int, void*, D01E50Node*);
int __cdecl FUN_00d94340(int, void*, D01E50Node*);

// Dispatches on node->kind to one of several handlers, passing node->payload, ctx and node; returns 1 for unknown kinds.
// @fnv 0x00d01e50
int __cdecl DispatchNodeByKind(void* pContext, D01E50Node* node)
{
    switch (node->kind)
    {
    case 0:
        return FUN_00d95cf0(node->payload, pContext, node);
    case 1:
        return FUN_00d94df0(node->payload, pContext, node);
    case 3:
        return ExecuteConstraintCallbacks(node->payload, pContext, node);
    case 4:
        return FUN_00d94a80(node->payload, pContext, node);
    case 6:
        return FUN_00d947e0(node->payload, pContext, node);
    case 7:
        return FUN_00d944d0(node->payload, pContext, node);
    case 8:
        return FUN_00d94570(node->payload, pContext, node);
    case 9:
        return LogIntegrateVelocity(node->payload, pContext, node);
    case 10:
        return FUN_00d94730(node->payload, pContext, node);
    case 11:
        return FUN_00d943d0(node->payload, pContext, node);
    case 5:
        return FUN_00d94340(node->payload, pContext, node);
    case 12:
        return FUN_00d93ba0(node->payload, pContext, node);
    case 15:
    case 13:
        return FUN_00d93380(node->payload, pContext, node);
    case 14:
        return AccumulateShapes(node->payload, pContext, node);
    default:
        return 1;
    }
}

int __fastcall FUN_00d04380(void*);
// @fnv 0x00d043b0
int __cdecl FUN_00d043b0(void* ap)
{
    return FUN_00d04380(ap);
}

// @fnv 0x00d043d0
int __cdecl FUN_00d043d0()
{
    return 0;
}

struct FnvCpu_FUN_00d04430_CpuScalar
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    int value;
};
struct FnvCpu_FUN_00d04430_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    FnvCpu_FUN_00d04430_CpuScalar* value;
    int FUN_00d04430();
};
// @fnv 0x00d04430
int FnvCpu_FUN_00d04430_CpuObject::FUN_00d04430()
{
    return value->value;
}

struct FnvCpu_FUN_00d04440_CpuScalar
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    int value;
};
struct FnvCpu_FUN_00d04440_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    FnvCpu_FUN_00d04440_CpuScalar* value;
    int FUN_00d04440();
};
// @fnv 0x00d04440
int FnvCpu_FUN_00d04440_CpuObject::FUN_00d04440()
{
    return value->value;
}

// 0x00d05de0  bare ret
// @fnv 0x00d05de0
void FUN_00d05de0()
{}

struct FUN_00d06f70_s
{
    void FUN_00d06f70();
};

struct FUN_00d07070_s : FUN_00d06f70_s
{
    int unk00;
    unsigned short unk04;

    int __thiscall FUN_00d07070(unsigned char flag);
};

// @fnv 0x00d07070
int __thiscall FUN_00d07070_s::FUN_00d07070(unsigned char flag)
{
    this->FUN_00d06f70();

    if (flag & 1)
    {
        AllocHolder* holder = FUN_00c85750();
        unsigned short value = unk04;
        holder->m_pAllocator->Free(reinterpret_cast<void*>(this), value);
    }

    return reinterpret_cast<int>(this);
}

// 0x00d070b0  bare ret
// @fnv 0x00d070b0
void FUN_00d070b0()
{}

struct FnvCpu_FUN_00d081d0_CpuObject
{
    char* FUN_00d081d0();
};
// @fnv 0x00d081d0
char* FnvCpu_FUN_00d081d0_CpuObject::FUN_00d081d0()
{
    return reinterpret_cast<char*>(this) + 80;
}

struct FUN_00d081e0_ret
{
    int base;
};

class FUN_00d081e0_cls
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
    FUN_00d081e0_ret unk50;
    FUN_00d081e0_ret* FUN_00d081e0();
};

// @fnv 0x00d081e0
FUN_00d081e0_ret* FUN_00d081e0_cls::FUN_00d081e0()
{
    return &unk50;
}

// @fnv 0x00d08370
void __stdcall FUN_00d08370(int)
{}

// @fnv 0x00d0a2a0
void __stdcall FUN_00d0a2a0(int)
{}

// @fnv 0x00d10760
void __cdecl FUN_00d10760()
{}

// @fnv 0x00d10770
void FUN_00d10770()
{}

// @fnv 0x00d10780
void __cdecl FUN_00d10780()
{}

extern int DAT_010cd664;
void __cdecl FormHeap_Free(void*);
struct FUN_00d1bab0_t
{
    int m_vft;
    FUN_00d1bab0_t(bool fInit);
};
// @fnv 0x00d1bab0
FUN_00d1bab0_t::FUN_00d1bab0_t(bool fInit)
{
    m_vft = (int)&DAT_010cd664;
    if (fInit & 1)
        FormHeap_Free(this);
}

// @fnv 0x00d1f100
void __cdecl FUN_00d1f100()
{}

// @fnv 0x00d1f120
void __cdecl FUN_00d1f120()
{}

// @fnv 0x00d1f170
void FUN_00d1f170()
{}

// @fnv 0x00d1fa10
void __cdecl FUN_00d1fa10()
{}

// @fnv 0x00d043f0
void __stdcall FUN_00d043f0(int)
{}

inline void* operator new(unsigned int, void* address)
{
    return address;
}

struct ArrayAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* Allocate(int& bytes);
    virtual void Free(void* data, int bytes);
};
struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ArrayAllocator* allocator;
};
Holder* __cdecl _FUN_00c85750();
void __cdecl FUN_00c908c0(ArrayAllocator* allocator, void* array, int capacity, int elementSize);

struct IntArray
{
    int* data;
    int size;
    int capacity;

    __forceinline ~IntArray()
    {
        Holder* h = _FUN_00c85750();
        ArrayAllocator* allocator = h->allocator;
        int cap = capacity;
        size = 0;
        if ((cap & 0x80000000) == 0)
            allocator->Free(data, (cap & 0x3fffffff) * 4);
        data = 0;
        capacity = 0x80000000;
    }

    static __forceinline int* allocate(ArrayAllocator* allocator, int& count)
    {
        if (count)
        {
            int bytes = count * 4;
            int* p = static_cast<int*>(allocator->Allocate(bytes));
            count = bytes / 4;
            return p;
        }
        return 0;
    }

    __forceinline IntArray(const IntArray& source) : data(0), size(0), capacity(0x80000000)
    {
        int count = source.size;
        Holder* h = _FUN_00c85750();
        ArrayAllocator* allocator = h->allocator;
        int* buffer = allocate(allocator, count);
        int cap = count ? count : 0x80000000;
        data = buffer;
        size = count;
        capacity = cap;
        const int* input = source.data;
        for (int i = 0; i < count; ++i)
            buffer[i] = input[i];
    }

    __forceinline IntArray& operator=(const IntArray& source)
    {
        ArrayAllocator* allocator = _FUN_00c85750()->allocator;
        if ((capacity & 0x3fffffff) < source.size)
        {
            if ((capacity & 0x80000000) == 0)
                allocator->Free(data, (capacity & 0x3fffffff) * 4);
            int bytes = source.size * 4;
            data = static_cast<int*>(allocator->Allocate(bytes));
            capacity = bytes / 4;
        }
        int n = source.size;
        size = n;
        int* dst = data;
        const int* src = source.data;
        for (int i = 0; i < n; ++i)
            dst[i] = src[i];
        return *this;
    }
};

struct ArrayOfArrays
{
    IntArray* data;
    int size;
    int capacity;
    __forceinline ArrayOfArrays& operator=(const ArrayOfArrays& source)
    {
        Holder* h = _FUN_00c85750();
        ArrayAllocator* allocator = h->allocator;
        int oldSize = size;
        int newSize = source.size;
        int common = (newSize > oldSize) ? oldSize : newSize;
        int reserved = capacity & 0x3fffffff;
        if (reserved < newSize)
        {
            int grown = reserved * 2;
            if (newSize >= grown)
                grown = newSize;
            FUN_00c908c0(allocator, this, grown, sizeof(IntArray));
        }
        IntArray* end = data + newSize;
        for (int i = 0; i < oldSize - newSize; ++i)
            end[i].~IntArray();
        const IntArray* input = source.data;
        IntArray* output = data;
        for (int i = 0; i < common; ++i)
            output[i] = input[i];
        input = source.data + common;
        output = data + common;
        for (int i = 0; i < newSize - common; ++i)
            new (output + i) IntArray(input[i]);
        size = newSize;
        return *this;
    }
};

struct ArrayRecord
{
    int type;
    char flag;
    int value;
    ArrayOfArrays arrays;
    ArrayRecord& FUN_00d05b50(const ArrayRecord& source);
};

// Copies type, flag, value and arrays from source into this ArrayRecord and returns a reference to this.
// @fnv 0x00d05b50
ArrayRecord& ArrayRecord::FUN_00d05b50(const ArrayRecord& source)
{
    type = source.type;
    flag = source.flag;
    value = source.value;
    arrays = source.arrays;
    return *this;
}

// @fnv 0x00d05dd0
void FUN_00d05dd0()
{}

extern "C" int __cdecl FUN_00d61d00(void* dst, const char* format, ...);

// Writes a human-readable size string (Bytes, Kb, or Mb) into dst using FUN_00d61d00 based on the value of size.
// @fnv 0x00d06eb0
void __cdecl FUN_00d06eb0(int size, void* dst)
{
    if (size < 0x400)
    {
        FUN_00d61d00(dst, "%i Bytes", size);
    }
    else if (size < 0x2800)
    {
        FUN_00d61d00(dst, "%.1f Kb", (double)size * (1.0 / 1024.0));
    }
    else if (size < 0x100000)
    {
        FUN_00d61d00(dst, "%i Kb", size / 1024);
    }
    else
    {
        float mb = (float)((double)size * (1.0 / 1048576.0));
        FUN_00d61d00(dst, "%.2f Mb", mb);
    }
}

struct FUN_00d0bc20_Outer;

struct FUN_00d0bc20_Vtable
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
    virtual void Method(FUN_00d0bc20_Outer* owner, unsigned int value);
};

struct FUN_00d0bc20_Outer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00d0bc20_Vtable* unk14;
    int unk18;
    int unk1C;
    int unk20;
    unsigned char unk24;
    unsigned char unk25;
    unsigned char unk26;
    unsigned char unk27;
};

// Sets bit 0 of object->unk27, calls the virtual Method on object->unk14, and stores the negation of bit 3 of unk27 into result.
// @fnv 0x00d0bc20
unsigned char* __stdcall FUN_00d0bc20(unsigned char* result, FUN_00d0bc20_Outer* object, unsigned int value)
{
    object->unk27 |= 1;
    object->unk14->Method(object, value);
    *result = (unsigned char)(~(object->unk27 >> 3) & 1);
    return result;
}

extern int DAT_010c63bc;
extern int DAT_010cd588;
extern int DAT_010cd598;

struct FUN_00d107d0_t
{
    void* p0;
    unsigned short a;
    unsigned short b;
    union
    {
        void* volatile p8a;
        void* p8b;
    };
    int c;
    FUN_00d107d0_t* FUN_00d107d0(int v);
};

// Sets b to 1, points p8a/p0/p8b at DAT_010c63bc/DAT_010cd598/DAT_010cd588, stores v in c, and returns this.
// @fnv 0x00d107d0
FUN_00d107d0_t* FUN_00d107d0_t::FUN_00d107d0(int v)
{
    b = 1;
    p8a = &DAT_010c63bc;
    p0 = &DAT_010cd598;
    p8b = &DAT_010cd588;
    c = v;
    return this;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_load_ps(const float* p);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);

struct S00d1b7f0_Input
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
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    int m44;
    int m48;
    int m4C;
};

struct S00d1b7f0_Frame
{
    int v0;
    int v1;
    int v2;
    int v3;
    __m128 diff;
};

extern "C" void __cdecl QueryKdTree(int a, int b, int c, const __m128* d, const int* e, int f, int g);

// Subtracts the vector at p+0x30 from the one at p+0x40 and calls QueryKdTree with p->m00 twice, p->m1C, the difference and the p+0x30 values.
// @fnv 0x00d1b7f0
void __cdecl FUN_00d1b7f0(S00d1b7f0_Input* p, int argB, int argC)
{
    S00d1b7f0_Frame frame;

    int first = p->m00;
    frame.v0 = p->m30;
    frame.v1 = p->m34;
    frame.v2 = p->m38;
    frame.v3 = p->m3C;

    int m1c = p->m1C;

    frame.diff = _mm_sub_ps(*reinterpret_cast<const __m128*>(&p->m40), *reinterpret_cast<const __m128*>(&p->m30));

    QueryKdTree(first, first, m1c, &frame.diff, &frame.v0, argB, argC);
}

// @fnv 0x00d043e0
int FUN_00d043e0()
{
    return 1;
}

struct DispatchContext;
struct DispatchNode
{
    unsigned char kind;
    unsigned char subtype;
};
typedef int(__cdecl* DispatchHandler)(DispatchContext*, int, DispatchNode*);
struct DispatchEntry
{
    void* first;
    void* second;
    void* third;
    DispatchHandler handler;
};
struct DispatchContext
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
    DispatchEntry handlers[256];
};
extern "C" void _ReadWriteBarrier(void);
// Computes a byte offset from the node subtype and invokes the handler pointer stored at that offset in the context's handler table.
// @fnv 0x00d04570
int __cdecl FUN_00d04570(DispatchContext* apContext, int b, DispatchNode* apNode)
{
    unsigned off = apNode->subtype << 4;

    return reinterpret_cast<DispatchEntry*>(reinterpret_cast<char*>(apContext->handlers) + off)
        ->handler(apContext, b, apNode);
}

// @fnv 0x00d05dc0
void FUN_00d05dc0()
{}

// @fnv 0x00d083d0
void __cdecl FUN_00d083d0()
{}

struct D10E90Obj
{
    unsigned short unk00;
};

// @fnv 0x00d10e90
static __declspec(noinline) unsigned short FUN_00d10e90(D10E90Obj* obj)
{
    return obj->unk00;
}

extern "C" D10E90Obj* d10e90_stub(void);
extern unsigned short d10e90_sink;

void d10e90_caller(void)
{
    d10e90_sink = FUN_00d10e90(d10e90_stub());
}

class MyClass
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

  public:
    int* GetField20();
};

// @fnv 0x00d10fe0
int* MyClass::GetField20()
{
    return &unk20;
}

extern __m128 DAT_011b3810;

// @fnv 0x00d1b280
__m128 __cdecl FUN_00d1b280()
{
    return DAT_011b3810;
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

extern unsigned int DAT_0126835c;
extern char DAT_010cd648[];
extern char DAT_010c41f8[];

struct __declspec(align(16)) Vec4
{
    float q[4];
};

struct HkTimer
{
    int unk00;
    char* head;
    int unk08;
    char* end;
};

struct QueryObj
{
    void* unk00;
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
    __m128 min;
    __m128 max;
};

void __cdecl FUN_00d1b4d0(const void* a, int b, const Vec4* c, const Vec4* d, int e, int f, int g, int h, int i, int j);

// Records two HkTimer profiling markers around a call to FUN_00d1b4d0 with the QueryObj vertex data and bounds.
// @fnv 0x00d1b850
void __cdecl FUN_00d1b850(QueryObj* obj, int arg1, int arg2)
{
    HkTimer* prof = (HkTimer*)TlsGetValue(DAT_0126835c);
    char* cur = prof->head;
    if (cur < prof->end)
    {
        *(const char**)cur = DAT_010cd648;
        _ReadWriteBarrier();
        volatile unsigned int stamp = (unsigned int)__rdtsc();
        *(unsigned int*)(cur + 4) = stamp;
        prof->head = cur + 12;
    }

    void* verts = obj->unk00;
    int vcount = obj->unk1c;
    Vec4 mn = *(const Vec4*)&obj->min;
    __m128 dv = _mm_sub_ps(obj->max, obj->min);
    const Vec4* delta = (const Vec4*)&dv;
    int count = obj->unk0c > 0 ? obj->unk0c : 128;
    FUN_00d1b4d0(verts, vcount, delta, &mn, arg1, count, arg2, 0, 0, 0);

    prof = (HkTimer*)TlsGetValue(DAT_0126835c);
    cur = prof->head;
    if (cur < prof->end)
    {
        *(const char**)cur = DAT_010c41f8;
        _ReadWriteBarrier();
        volatile unsigned int stamp2 = (unsigned int)__rdtsc();
        *(unsigned int*)(cur + 4) = stamp2;
        prof->head = cur + 12;
    }
}

extern "C" void __cdecl FUN_00d1b4d0(int, int, const __m128*, const int*, int, int, int, int, int, int);

// Builds a frame from the vectors at p->m30 and p->m40 (start and difference) and calls FUN_00d1b4d0 with count m0C, or 128 if that is not positive.
// @fnv 0x00d1b930
void __cdecl FUN_00d1b930(S00d1b7f0_Input* p, int argB, int argC, int argD)
{
    S00d1b7f0_Frame frame;
    __m128 end = _mm_load_ps(reinterpret_cast<const float*>(&p->m40));
    __m128 start = _mm_load_ps(reinterpret_cast<const float*>(&p->m30));
    __m128 difference = _mm_sub_ps(end, start);
    int first = p->m00;
    int second = p->m1C;
    frame.v0 = p->m30;
    frame.v1 = p->m34;
    frame.v2 = p->m38;
    frame.v3 = p->m3C;
    frame.diff = difference;
    int count = p->m0C;
    if (count <= 0)
        count = 128;
    FUN_00d1b4d0(first, second, &frame.diff, &frame.v0, argB, count, 0, 0, argC, argD);
}

struct FUN_00d1ba90
{
    virtual ~FUN_00d1ba90();
};
// @fnv 0x00d1ba90
FUN_00d1ba90::~FUN_00d1ba90()
{}

extern "C" void _ReadWriteBarrier();
struct D01B40_Sub
{
    virtual void v00();
    virtual int GetValueV();
    int GetValue()
    {
        _ReadWriteBarrier();
        return GetValueV();
    }
};
struct D01B40_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D01B40_Sub kSub;
};
struct D01B40_cls
{
    D01B40_Obj* pObj;
    bool* FUN_00d01b40(bool* pbResult);
};
// Writes false to pbResult if pObj is null, if unk0C is 0xF, or if unk0C is 7, 9 or 0x17 and GetValue() exceeds 100; otherwise true.
// @fnv 0x00d01b40
bool* D01B40_cls::FUN_00d01b40(bool* pbResult)
{
    if (!pObj)
    {
        *pbResult = false;
        return pbResult;
    }
    bool bOk = true;
    if (pObj->unk0C == 9 && pObj->kSub.GetValue() > 100)
        bOk = false;
    if (pObj->unk0C == 0x17 && pObj->kSub.GetValue() > 100)
        bOk = false;
    if (pObj->unk0C == 7 && pObj->kSub.GetValue() > 100)
        bOk = false;
    if (pObj->unk0C == 0xF)
        bOk = false;
    *pbResult = bOk;
    return pbResult;
}

typedef union __declspec(intrin_type) __declspec(align(16)) __m128i
{
    int m128i_i32[4];
} __m128i;

extern "C"
{
    __m128i _mm_setzero_si128(void);
    __m128i _mm_unpacklo_epi16(__m128i, __m128i);
    __m128i _mm_unpackhi_epi16(__m128i, __m128i);
    __m128i _mm_slli_epi32(__m128i, int);
    __m128i _mm_srli_epi32(__m128i, int);
    __m128 _mm_cvtepi32_ps(__m128i);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_cmple_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
    int _mm_movemask_ps(__m128);
    __m128i _mm_load_si128(__m128i const*);
}

extern double DAT_010217d0;
extern float DAT_010cd644;
extern __m128 DAT_011b3810;
extern "C" void _ReadWriteBarrier(void);

void __cdecl ResizeAudioStream(void* allocator, void* arr, int elemSize);

struct MemSource
{
    static void* FUN_00c85750();
};

struct KdNode
{
    int a;
    unsigned int b;
};

struct Aabb16
{
    union
    {
        struct
        {
            unsigned short minX;
            unsigned short minY;
            unsigned short minZ;
            unsigned short key0;
            unsigned short maxX;
            unsigned short maxY;
            unsigned short maxZ;
            unsigned short key1;
        };
        struct
        {
            int d0, d1, d2, d3;
        } words;
    };
};

struct QueryAabb
{
    float min[4];
    float max[4];
};

struct PrimIds
{
    int* data;
    int size;
    int capacity;
};

struct __declspec(align(16)) ScaleSplat
{
    float x, y, z, w;
};

struct __declspec(align(16)) RawWords
{
    int d0, d1, d2, d3;
};

static __forceinline __m128 u32_to_f(__m128i x, const ScaleSplat& magic)
{
    __m128i hi = _mm_srli_epi32(x, 16);
    __m128i lo = _mm_srli_epi32(_mm_slli_epi32(x, 16), 16);
    return _mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps(hi), *(__m128*)&magic), _mm_cvtepi32_ps(lo));
}

struct FloatPair
{
    __m128 lo;
    __m128 hi;
};
static __forceinline void convertPair(__m128i raw, __m128i zero, const ScaleSplat& c1, const ScaleSplat& c2,
                                      FloatPair& out)
{
    __m128i l = _mm_unpacklo_epi16(raw, zero);
    __m128i h = _mm_unpackhi_epi16(raw, zero);
    out.lo = u32_to_f(l, c1);
    out.hi = u32_to_f(h, c2);
}
struct ChildInfo
{
    int axis;
    KdNode* left;
    KdNode* right;
};
// @fnv 0x00d1b290
void __cdecl QueryKdTree(void* tree, KdNode* node, const Aabb16* prims, const float* scale, const float* offset,
                         const QueryAabb* __restrict query, PrimIds* hits)
{
    int a = node->a;
    unsigned int b = node->b;
    while (~(a >> 31) == 0)
    {
        KdNode* __restrict cur = node;
        ChildInfo info;
        info.left = (KdNode*)((char*)cur + (cur->a & 0x7ffffffc));
        info.axis = a & 3;
        info.right = (KdNode*)((char*)cur + (cur->a & 0x7ffffffc)) + 1;
        float maxv = query->max[info.axis];
        int lo16 = (int)(unsigned short)b;
        float lo = (float)((float)lo16 / DAT_010217d0 * scale[info.axis] + offset[info.axis]);
        if (maxv < lo)
        {
            node = info.left;
        }
        else
        {
            float minv = query->min[info.axis];
            int hi16 = (int)(b >> 16);
            float hi = (float)((float)hi16 / DAT_010217d0 * scale[info.axis] + offset[info.axis]);
            if (minv > hi)
            {
                node = info.right;
            }
            else
            {
                QueryKdTree(tree, info.left, prims, scale, offset, query, hits);
                node = info.right;
            }
        }
        a = node->a;
        b = node->b;
    }

    if ((a ^ 0x7fffffff) == 0)
        return;
    if ((int)b <= 0)
        return;

    ScaleSplat kHi;
    ScaleSplat kLo;
    kHi.x = DAT_010cd644;
    kHi.y = DAT_010cd644;
    kHi.z = DAT_010cd644;
    kHi.w = DAT_010cd644;
    kLo.x = DAT_010cd644;
    kLo.y = DAT_010cd644;
    kLo.z = DAT_010cd644;
    kLo.w = DAT_010cd644;

    __m128i zero = _mm_setzero_si128();
    const unsigned short* prim = &prims[a & 0x7fffffff].key1;
    int count = (int)b;
    do
    {
        union
        {
            struct
            {
                unsigned short lo;
                unsigned short hi;
            } s;
            int packed;
        } key;
        key.s.lo = prim[-4];
        key.s.hi = prim[0];

        __m128 sc = _mm_mul_ps(_mm_load_ps(scale), DAT_011b3810);
        RawWords bits;
        bits.d0 = ((const Aabb16*)(prim - 7))->words.d0;
        bits.d1 = ((const Aabb16*)(prim - 7))->words.d1;
        bits.d2 = ((const Aabb16*)(prim - 7))->words.d2;
        bits.d3 = ((const Aabb16*)(prim - 7))->words.d3;

        __m128 off = _mm_load_ps(offset);
        __m128i raw = _mm_load_si128((const __m128i*)&bits);
        FloatPair decoded;
        convertPair(raw, zero, kHi, kLo, decoded);
        __m128 lower, upper;
        upper = off;
        lower = off;
        upper = _mm_add_ps(_mm_mul_ps(decoded.hi, sc), lower);
        lower = _mm_add_ps(_mm_mul_ps(decoded.lo, sc), off);
        __m128 cmp =
            _mm_and_ps(_mm_cmple_ps(lower, _mm_load_ps(query->max)), _mm_cmple_ps(_mm_load_ps(query->min), upper));
        if ((_mm_movemask_ps(cmp) & 7) == 7)
        {
            AllocHolder* holder = (AllocHolder*)MemSource::FUN_00c85750();
            if (hits->size == (hits->capacity & 0x3fffffff))
                ResizeAudioStream((void*)holder->unk0C, hits, 4);
            int* dst = hits->data + hits->size;
            for (int once = 0; once < 1; ++once)
                dst[once] = key.packed;
            hits->size++;
        }
        prim += 8;
        --count;
    } while (count);
}

extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_cmpeq_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_and_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_andnot_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_or_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_rcp_ps(__m128 a);

extern __m128 DAT_01267e30;
extern __m128 DAT_010c7170;
extern __m128 DAT_010cd670;

static inline __m128 quadRecip(__m128 r)
{
    __m128 e = _mm_rcp_ps(r);
    return _mm_sub_ps(_mm_add_ps(e, e), _mm_mul_ps(_mm_mul_ps(e, r), e));
}
class HkVec4
{
  public:
    void operator=(const HkVec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const __m128& q)
    {
        m_vComponents = q;
    }
    operator __m128() const
    {
        return m_vComponents;
    }
    void setSub4(const HkVec4& a, const HkVec4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void select32(const HkVec4& a, const HkVec4& b, const __m128& mask)
    {
        m_vComponents = _mm_or_ps(_mm_and_ps(mask, b.m_vComponents), _mm_andnot_ps(mask, a.m_vComponents));
    }
    __m128 compareEqual4(const HkVec4& a) const
    {
        return _mm_cmpeq_ps(m_vComponents, a.m_vComponents);
    }
    void setReciprocal4(const HkVec4& v)
    {
        m_vComponents = quadRecip(v.m_vComponents);
    }

  private:
    __m128 m_vComponents;
};
struct HkBundle
{
    HkVec4 m_data[3];
};
struct HkRayBundle
{
    __forceinline HkRayBundle(const HkBundle& from, const HkBundle& to, int mask)
    {
        const HkVec4& kOne = (const HkVec4&)DAT_010c7170;
        const HkVec4& kMaxPoint = (const HkVec4&)DAT_010cd670;
        const HkVec4& kZero = (const HkVec4&)DAT_01267e30;
        m_uiMask = mask;
        m_vFrom = from;
        HkBundle delta;
        for (int i = 0; i < 3; i++)
        {
            delta.m_data[i].setSub4(to.m_data[i], m_vFrom.m_data[i]);
            __m128 isZero = delta.m_data[i].compareEqual4(kZero);
            HkVec4 maskedDelta;
            maskedDelta.select32(delta.m_data[i], kOne, isZero);
            HkVec4 invDelta;
            invDelta.setReciprocal4(maskedDelta);
            m_vInverseDirection.m_data[i].select32(invDelta, kMaxPoint, isZero);
        }
    }
    HkBundle m_vFrom;
    HkBundle m_vInverseDirection;
    int m_uiMask;
};
// Transposes four from vectors and four to vectors into bundles, then returns an HkRayBundle built from them with the given mask.
// @fnv 0x00d1bb50
HkRayBundle __cdecl FUN_00d1bb50(const HkVec4& from0, const HkVec4& to0, const HkVec4& from1, const HkVec4& to1,
                                 const HkVec4& from2, const HkVec4& to2, const HkVec4& from3, const HkVec4& to3,
                                 int mask)
{
    HkBundle bundleFrom;
    HkBundle bundleTo;
    HkVec4 tmpFrom;
    HkVec4 tmpTo;
    bundleFrom.m_data[0] = from0;
    bundleFrom.m_data[1] = from1;
    bundleFrom.m_data[2] = from2;
    tmpFrom = from3;
    bundleTo.m_data[0] = to0;
    bundleTo.m_data[1] = to1;
    bundleTo.m_data[2] = to2;
    tmpTo = to3;
    {
        __m128 tmp3, tmp2, tmp1, tmp0;

        tmp0 = _mm_shuffle_ps((bundleFrom.m_data[0]), (bundleFrom.m_data[1]), 0x44);
        tmp2 = _mm_shuffle_ps((bundleFrom.m_data[0]), (bundleFrom.m_data[1]), 0xEE);
        tmp1 = _mm_shuffle_ps((bundleFrom.m_data[2]), (tmpFrom), 0x44);
        tmp3 = _mm_shuffle_ps((bundleFrom.m_data[2]), (tmpFrom), 0xEE);

        (bundleFrom.m_data[0]) = _mm_shuffle_ps(tmp0, tmp1, 0x88);
        (bundleFrom.m_data[1]) = _mm_shuffle_ps(tmp0, tmp1, 0xDD);
        (bundleFrom.m_data[2]) = _mm_shuffle_ps(tmp2, tmp3, 0x88);
        (tmpFrom) = _mm_shuffle_ps(tmp2, tmp3, 0xDD);
    }
    {
        __m128 tmp3, tmp2, tmp1, tmp0;

        tmp0 = _mm_shuffle_ps((bundleTo.m_data[0]), (bundleTo.m_data[1]), 0x44);
        tmp2 = _mm_shuffle_ps((bundleTo.m_data[0]), (bundleTo.m_data[1]), 0xEE);
        tmp1 = _mm_shuffle_ps((bundleTo.m_data[2]), (tmpTo), 0x44);
        tmp3 = _mm_shuffle_ps((bundleTo.m_data[2]), (tmpTo), 0xEE);

        (bundleTo.m_data[0]) = _mm_shuffle_ps(tmp0, tmp1, 0x88);
        (bundleTo.m_data[1]) = _mm_shuffle_ps(tmp0, tmp1, 0xDD);
        (bundleTo.m_data[2]) = _mm_shuffle_ps(tmp2, tmp3, 0x88);
        (tmpTo) = _mm_shuffle_ps(tmp2, tmp3, 0xDD);
    }
    return HkRayBundle(bundleFrom, bundleTo, mask);
}

typedef void*(__stdcall* S00d1b9b0_TlsGet)(unsigned long dwTlsIndex);

// Records a TtqueryAabb timer, calls FUN_00d1b4d0 with the query AABB and count, then records an Et timer.
// @fnv 0x00d1b9b0
void __cdecl FUN_00d1b9b0(QueryObj* pQuery, int p1, int p2)
{
    volatile unsigned int tick;
    S00d1b9b0_TlsGet pfnTls = TlsGetValue;
    HkTimer* pBuf = (HkTimer*)pfnTls(DAT_0126835c);
    if (pBuf->head < pBuf->end)
    {
        char* pRec = pBuf->head;
        *(const char**)pRec = "TtqueryAabb";
        _ReadWriteBarrier();
        tick = (unsigned int)__rdtsc();
        *(unsigned int*)(pRec + 4) = tick;
        pBuf->head = pRec + 0xc;
    }

    const void* a = pQuery->unk00;
    int b = pQuery->unk1c;
    Vec4 vMin = *(const Vec4*)&pQuery->min;
    Vec4 vExtent;
    *(__m128*)&vExtent = _mm_sub_ps(pQuery->max, pQuery->min);
    int count = pQuery->unk0c;
    if (count <= 0)
        count = 0x80;
    FUN_00d1b4d0(a, b, &vExtent, &vMin, p1, count, 0, p2, 0, 0);

    pBuf = (HkTimer*)pfnTls(DAT_0126835c);
    if (pBuf->head < pBuf->end)
    {
        char* pRec = pBuf->head;
        *(const char**)pRec = "Et";
        _ReadWriteBarrier();
        tick = (unsigned int)__rdtsc();
        *(unsigned int*)(pRec + 4) = tick;
        pBuf->head = pRec + 0xc;
    }
}

// Today's unit (blk_00d00000_o2.cpp) declares __m128 and most SSE1 intrinsics as
// extern "C" functions instead of including <xmmintrin.h>; declare the four the
// matched code needs that the unit does not have.
extern "C" __m128 _mm_max_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_min_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" float _mm_cvtss_f32(__m128 a);

// Returns the squared distance from the point at b to the box with min at a and max at a+4 floats, or 0.0f when the point is inside.
// @fnv 0x00d1bad0
float __cdecl FUN_00d1bad0(float* a, float* b)
{
    __m128 va2 = *reinterpret_cast<__m128*>(a + 4);
    __m128 vb = *reinterpret_cast<__m128*>(b);
    __m128 va = *reinterpret_cast<__m128*>(a);
    __m128 overlap = _mm_and_ps(_mm_cmple_ps(va, vb), _mm_cmple_ps(vb, va2));
    int mask = _mm_movemask_ps(overlap);
    if ((mask & 7) == 7)
        return 0.0f;
    __m128 clamped = _mm_max_ps(_mm_min_ps(vb, va2), va);
    __m128 delta = _mm_sub_ps(clamped, vb);
    __m128 squared = _mm_mul_ps(delta, delta);
    __m128 y = _mm_shuffle_ps(squared, squared, 0x55);
    __m128 z = _mm_shuffle_ps(squared, squared, 0xaa);
    __m128 sum = _mm_add_ss(y, squared);
    sum = _mm_add_ss(z, sum);
    return _mm_cvtss_f32(sum);
}

extern "C" __m128 _mm_setzero_ps(void);

struct FUN_00d1f9f0
{
    short boneBegin;
    short boneEnd;
    __m128 penetrationPoint;
    __m128 penetrationNormal;

    FUN_00d1f9f0();
};

// @fnv 0x00d1f9f0
FUN_00d1f9f0::FUN_00d1f9f0()
{
    boneBegin = 0;
    boneEnd = 1;
    penetrationPoint = _mm_setzero_ps();
    penetrationNormal = _mm_setzero_ps();
}

struct S00d1b4d0_Node
{
    unsigned code;
    unsigned packed;
    S00d1b4d0_Node* child()
    {
        return (S00d1b4d0_Node*)((char*)this + (code & 0x7ffffffc));
    }
};
struct __declspec(align(8)) S00d1b4d0_NodeCopy
{
    unsigned code;
    unsigned packed;
    void set(const S00d1b4d0_Node* p)
    {
        code = p->code;
        packed = p->packed;
    }
};
struct S00d1b4d0_Entry
{
    union
    {
        struct
        {
            unsigned short unk00, unk02, unk04, unk06, unk08, unk0a, unk0c, unk0e;
        };
        struct
        {
            unsigned word0, word1, word2, word3;
        };
    };
};
struct S00d1b4d0_List
{
    unsigned* data;
    int size;
    unsigned capacity;
};
struct S00d1b4d0_Id
{
    unsigned short lo, hi;
};
struct S00d1b4d0_Result
{
    char m_cBooleanValue;
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};
struct S00d1b4d0_Callback
{
    virtual void slot0();
    virtual S00d1b4d0_Result slot1(S00d1b4d0_Id id);
};
struct S00d1b4d0_Aabb
{
    __m128 m_kMinimumCorner;
    __m128 m_kMaximumCorner;
};
struct RealVec
{
    union
    {
        __m128 q;
        float f[4];
    };
    RealVec()
    {}
    const float& at(unsigned i) const
    {
        return f[i];
    }
};
struct S00d1b4d0_Bounds
{
    float min[4];
    float max[4];
};

void __cdecl ResizeAudioStream(void*, void*, int);

static __forceinline float S00d1b4d0_decode(int v, const RealVec& scale, const RealVec& offset, unsigned axis)
{
    return (float)(v / 65535.0 * scale.at(axis) + offset.at(axis));
}

struct IVector
{
    __m128i q;
    void unpackLo(const IVector& a, const IVector& b)
    {
        q = _mm_unpacklo_epi16(a.q, b.q);
    }
    void unpackHi(const IVector& a, const IVector& b)
    {
        q = _mm_unpackhi_epi16(a.q, b.q);
    }
};
struct FVector
{
    __m128 q;
    void convert(const IVector& a, __m128 bias)
    {
        __m128i hi = _mm_srli_epi32(a.q, 16);
        __m128i lo = _mm_srli_epi32(_mm_slli_epi32(a.q, 16), 16);
        q = _mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps(hi), bias), _mm_cvtepi32_ps(lo));
    }
    void mul(const FVector& a, __m128 b)
    {
        q = _mm_mul_ps(a.q, b);
    }
    void add(const FVector& a, __m128 b)
    {
        q = _mm_add_ps(a.q, b);
    }
};
static __forceinline void copyResult(unsigned* target, int count, const unsigned& value)
{
    for (int i = 0; i < count; ++i)
        target[i] = value;
}
// @fnv 0x00d1b4d0
int __cdecl FUN_00d1b4d0(S00d1b4d0_Node* node, S00d1b4d0_Entry* entries, const RealVec& scale, const RealVec& offset,
                         S00d1b4d0_Bounds* query, int capacity, S00d1b4d0_List* list, S00d1b4d0_Callback* callback,
                         unsigned** output, int limit)
{
    S00d1b4d0_Node* cur = node;
    S00d1b4d0_Id id;
    __declspec(align(16)) S00d1b4d0_NodeCopy n;
    n.set(cur);
    AllocHolder* alloc = FUN_00c85750();
    S00d1b4d0_Node** base = (S00d1b4d0_Node**)alloc->unk00;
    S00d1b4d0_Node** top = base;
    int bytes = (capacity * 4 + 127) & ~127;
    alloc->unk00 = (int)((char*)base + bytes);
    S00d1b4d0_Bounds bounds = *query;
    int found = 0;
    for (;;)
    {
        while (n.code & 0x80000000)
        {
            S00d1b4d0_Node* child = cur->child();
            n.code &= 3;
            unsigned axis = n.code;
            n.code = n.packed;
            S00d1b4d0_Node* other = cur->child() + 1;
            if (!(bounds.max[axis] < S00d1b4d0_decode((unsigned short)n.code, scale, offset, axis)))
            {
                if (bounds.min[axis] > S00d1b4d0_decode((int)(n.code >> 16), scale, offset, axis))
                    cur = other;
                else
                {
                    *top++ = other;
                    cur = child;
                }
            }
            else
                cur = child;
            n.set(*(S00d1b4d0_Node* volatile*)&cur);
        }
        if ((n.code ^ 0x7fffffffu) != 0)
        {
            int count = (int)n.packed;
            int i = 0;
            if (count > i)
            {
                __m128i packedData;
                __m128 biasLo;
                __m128 biasHi;
                __m128i zeroData;
                biasLo.m128_f32[0] = 1e16f;
                biasLo.m128_f32[1] = 1e16f;
                biasLo.m128_f32[2] = 1e16f;
                biasLo.m128_f32[3] = 1e16f;
                biasHi.m128_f32[0] = 1e16f;
                biasHi.m128_f32[1] = 1e16f;
                biasHi.m128_f32[2] = 1e16f;
                biasHi.m128_f32[3] = 1e16f;
                zeroData = _mm_setzero_si128();
                unsigned short* p = &entries[n.code & 0x7fffffff].unk0e;
                do
                {
                    id.lo = p[-4];
                    id.hi = p[0];
                    __m128 factor = _mm_mul_ps(DAT_011b3810, scale.q);
                    packedData.m128i_i32[0] =
                        ((const S00d1b4d0_Entry*)((const char*)p - offsetof(S00d1b4d0_Entry, unk0e)))->word0;
                    packedData.m128i_i32[1] =
                        ((const S00d1b4d0_Entry*)((const char*)p - offsetof(S00d1b4d0_Entry, unk0e)))->word1;
                    packedData.m128i_i32[2] =
                        ((const S00d1b4d0_Entry*)((const char*)p - offsetof(S00d1b4d0_Entry, unk0e)))->word2;
                    packedData.m128i_i32[3] =
                        ((const S00d1b4d0_Entry*)((const char*)p - offsetof(S00d1b4d0_Entry, unk0e)))->word3;
                    __m128 off = offset.q;
                    IVector data = {packedData}, zero = {zeroData};
                    IVector lo, hi;
                    lo.unpackLo(data, zero);
                    hi.unpackHi(data, zero);
                    FVector vmin, vmax;
                    vmin.convert(lo, biasLo);
                    vmax.convert(hi, biasHi);
                    vmax.mul(vmax, factor);
                    vmax.add(vmax, off);
                    vmin.mul(vmin, factor);
                    vmin.add(vmin, off);
                    S00d1b4d0_Aabb box;
                    box.m_kMinimumCorner = vmin.q;
                    box.m_kMaximumCorner = vmax.q;
                    __m128 mincomp = _mm_cmple_ps(box.m_kMinimumCorner, *(const __m128*)query->max);
                    __m128 maxcomp = _mm_cmple_ps(*(const __m128*)query->min, box.m_kMaximumCorner);
                    if ((_mm_movemask_ps(_mm_and_ps(mincomp, maxcomp)) & 7) == 7)
                    {
                        if (callback)
                        {
                            if (callback->slot1(id))
                                goto done;
                        }
                        else if (list)
                        {
                            AllocHolder* grow = FUN_00c85750();
                            if (list->size == (int)(list->capacity & 0x3fffffff))
                                ResizeAudioStream((void*)grow->unk0C, list, 4);
                            copyResult(list->data + list->size, 1, *(unsigned*)&id);
                            list->size++;
                        }
                        else if (output)
                        {
                            *(*output)++ = *(unsigned*)&id;
                            if (++found >= limit)
                                goto done;
                        }
                    }
                    p += 8;
                    ++i;
                } while (i < count);
            }
        }
        if (top == base)
            break;
        cur = *--top;
        n.set(cur);
    }
done:
    FUN_00c85750()->unk00 = (int)base;
    return found;
}
