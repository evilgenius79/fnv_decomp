
// src/staging/blk_009e0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @fnv 0x009faba0
int __stdcall FUN_009faba0(int, int, int)
{
    return 0x80004001;
}

// @fnv 0x009f9d90
int __stdcall GetValueFromOffset8(int a, int aiUnused, int* piOut)
{
    if (!piOut)
        return 0x80004003;
    *piOut = *(int*)((char*)a + 8);
    return 0;
}

void* __cdecl _fnv_zlib_memset(void* dst, int value, int size);

struct FUN_009f9a30_class
{
    void FUN_009f9a30();
};

// @fnv 0x009f9a30
void FUN_009f9a30_class::FUN_009f9a30()
{
    _fnv_zlib_memset(this, 0, 0x48);
    *(int*)((char*)this + 0x28) = 1;
    *(int*)((char*)this + 0x20) = 1;
}

struct SpectatorPackage
{
    int IsComplete(const SpectatorPackage&);
    SpectatorPackage* FUN_009f9d10(const SpectatorPackage&);
};

// @fnv 0x009f9d10
SpectatorPackage* SpectatorPackage::FUN_009f9d10(const SpectatorPackage& aPackage)
{
    IsComplete(aPackage);
    return this;
}

struct FUN_009f9d10_cls
{
    void __thiscall FUN_009f9d10(int);
    int __thiscall CallAndReturnThis(int a);
};
// @fnv 0x009f9d30
int __thiscall FUN_009f9d10_cls::CallAndReturnThis(int a)
{
    FUN_009f9d10(a);
    return (int)this;
}

extern void** DAT_00fdf1c0;

// @fnv 0x009fa040
void __cdecl FUN_009fa040(int* a)
{
    a = a + 5;
    ((void(__cdecl*)(void*))DAT_00fdf1c0)(a);
}

namespace fnv_009fa180 {
extern "C" void* __cdecl DAT_00fdf1c0;

// @fnv 0x009fa180
void __stdcall FUN_009fa180(int a)
{
    ((void(__stdcall*)(int))DAT_00fdf1c0)(a + 0x10);
}
}  // namespace fnv_009fa180

// @fnv 0x009fa480
int __stdcall FUN_009fa480(int aSource, int apOut)
{
    if (!apOut)
        return 0x80004003;
    *(int*)apOut = *(int*)(aSource + 0x10);
    return 0;
}

extern void(__stdcall* DAT_00fdf05c)(int*);
extern void(__stdcall* DAT_00fdf100)(int*);

struct FUN_009fa4e0_class
{
    int FUN_009fa4e0(int a, int b);
};
// @fnv 0x009fa4e0
int FUN_009fa4e0_class::FUN_009fa4e0(int a, int aiValue)
{
    int* p = *(int**)((char*)a + 0x10);
    DAT_00fdf05c(p);
    *(int*)((char*)a + 0x1c) = aiValue;
    DAT_00fdf100(p);
    return 0;
}

// @fnv 0x009fa650
int __stdcall GetFieldAt0C(int a, int* piOut)
{
    *piOut = *(int*)(a + 0xc);
    return 0;
}

// @fnv 0x009fa840
int __stdcall FUN_009fa840(int* pFlags, int bSet)
{
    if (bSet)
        pFlags[1] |= 4;
    else
        pFlags[1] &= ~4;
    return 0;
}

// @fnv 0x009fa8b0
int __stdcall FUN_009fa8b0(void* obj, int value)
{
    if (value > *(int*)((char*)obj + 0x14))
        return 0x8004020d;
    *(int*)((char*)obj + 0x10) = value;
    return 0;
}

struct FUN_009fb020_class
{
    int FUN_009fb020();
};

// @fnv 0x009fb020
int FUN_009fb020_class::FUN_009fb020()
{
    if (*(int*)((char*)this + 0x38) > 0 && *(int*)((char*)this + 0x40) > 0 && *(int*)((char*)this + 0x44) > 0)
    {
        return *(int*)((char*)this + 0x4C) == 0;
    }
    return 0x80040212;
}

struct FUN_009f9f70_class
{
    void __thiscall FUN_009f9f70();
};
struct FUN_009fbb30_class
{
    void* __thiscall FUN_009fbb30(int flag);
};
// @fnv 0x009fbb30
void* __thiscall FUN_009fbb30_class::FUN_009fbb30(int aiFlags)
{
    ((FUN_009f9f70_class*)this)->FUN_009f9f70();
    if (aiFlags & 1)
        operator delete(this);
    return this;
}

void __cdecl operator delete(void*);
void InitVTableAndInvokeCallback();
struct FUN_009fbca0
{
    FUN_009fbca0* __thiscall Method(bool);
};
// @fnv 0x009fbca0
FUN_009fbca0* __thiscall FUN_009fbca0::Method(bool abDelete)
{
    InitVTableAndInvokeCallback();
    if (abDelete & 1)
        operator delete(this);
    return this;
}

int __stdcall FUN_009fd0a0(int);

// @fnv 0x009fc450
int __stdcall FUN_009fc450(int a)
{
    int b = *(int*)((int)a + 8);
    return FUN_009fd0a0(b);
}

struct FUN_009fc460_Class
{
    int __thiscall FUN_009fa560();
    void* __thiscall FUN_009fc460(int);
};
// @fnv 0x009fc460
void* __thiscall FUN_009fc460_Class::FUN_009fc460(int flag)
{
    FUN_009fa560();
    if (flag & 1)
        operator delete(this);
    return this;
}

struct FUN_009fd100_node
{
    void* p;
    FUN_009fd100_node* next;
};

struct FUN_009fd100_t
{
    void* a;
    void* b;
    FUN_009fd100_node* list;
    void DeleteList();
};

// @fnv 0x009fd100
void FUN_009fd100_t::DeleteList()
{
    FUN_009fd100_node* node = list;
    while (node)
    {
        void* current = node;
        node = node->next;
        operator delete(current);
    }
}

// @fnv 0x009fd180
int __stdcall PopAndGetValue(int* pListHead)
{
    if (!*pListHead)
        return 0;
    int v = *pListHead;
    *pListHead = *(int*)(v + 4);
    return *(int*)(v + 8);
}

// @fnv 0x009fd1a0
int __stdcall GetValueAtOffset8(int a)
{
    if (!a)
        return 0;
    return *(int*)(a + 8);
}

struct FUN_009fe2a0_class
{
    int __thiscall FUN_009fe2a0();
};

// @fnv 0x009fdbd0
int __stdcall FUN_009fdbd0(int a)
{
    return ((FUN_009fe2a0_class*)(*(int*)(a + 0xa4)))->FUN_009fe2a0();
}

struct FUN_009fddd0_class
{
    void __thiscall FUN_009fd3c0();
    FUN_009fddd0_class* __thiscall FUN_009fddd0(int);
};
// @fnv 0x009fddd0
FUN_009fddd0_class* __thiscall FUN_009fddd0_class::FUN_009fddd0(int a)
{
    FUN_009fd3c0();
    if (a & 1)
        delete this;
    return this;
}

void __fastcall FUN_009fdc10(void*);
void __cdecl _Deallocate(void*);

struct FUN_009fdeb0_class
{
    int __thiscall FUN_009fdeb0(int);
};

// @fnv 0x009fdeb0
int __thiscall FUN_009fdeb0_class::FUN_009fdeb0(int flag)
{
    FUN_009fdc10(this);
    if (flag & 1)
        _Deallocate(this);
    return (int)this;
}

// @fnv 0x009f9d60
int __stdcall FUN_009f9d60(int apSource, int apDest)
{
    if (!apDest)
        return 0x80004003;
    *(int*)(apDest + 0x0) = *(int*)(apSource + 0x1c);
    *(int*)(apDest + 0x4) = *(int*)(apSource + 0x20);
    *(int*)(apDest + 0x8) = *(int*)(apSource + 0x24);
    *(int*)(apDest + 0xc) = *(int*)(apSource + 0x28);
    return 0;
}

// @fnv 0x009fa060
long __stdcall FUN_009fa060(long* pObject)
{
    long r = InterlockedDecrement(pObject + 5);
    if (r == 0 && pObject)
        ((void(__thiscall*)(long*, int)) * (*(long**)pObject + 7))(pObject, 1);
    return r;
}

// @fnv 0x009fa1a0
int __stdcall FUN_009fa1a0(int* pObject)
{
    int r = InterlockedDecrement((volatile long*)(pObject + 4));
    if (r == 0 && pObject)
        ((void(__thiscall*)(void*, int))(*((void***)pObject))[7])(pObject, 1);
    return r;
}

extern int DAT_01093bcc;
extern int DAT_01093bdc;
extern int DAT_01093f14;
int __stdcall FUN_009f9980(int, int);
int __stdcall GetObjectPointer(int, int);
// @fnv 0x009fa580
int __stdcall FUN_009fa580(int a, int b, int c)
{
    if (FUN_009f9980(b, (int)&DAT_01093bdc) || FUN_009f9980(b, (int)&DAT_01093bcc) ||
        FUN_009f9980(b, (int)&DAT_01093f14))
        return GetObjectPointer(a, c);
    return 0x80004002;
}

int __stdcall FUN_009f9cd0(int a);

// @fnv 0x009fa8d0
int __stdcall FUN_009fa8d0(int p1, int* p2)
{
    if (!(*(unsigned char*)(p1 + 4) & 8))
    {
        *p2 = 0;
        return 1;
    }
    *p2 = FUN_009f9cd0(*(int*)(p1 + 0x3c));
    return *p2 ? 0 : 0x8007000e;
}

// @fnv 0x009faca0
int __stdcall FUN_009faca0(int pSource, int* pOutput)
{
    if (!pOutput)
        return 0x80004003;
    int* d = 0;
    if (pSource - 12)
        d = (int*)(pSource - 12) + 4;
    else
        d = 0;
    DAT_00fdf05c(d);
    pOutput[1] = *(int*)((char*)pSource + 0x34);
    pOutput[0] = *(int*)((char*)pSource + 0x2c);
    pOutput[2] = *(int*)((char*)pSource + 0x38);
    pOutput[3] = *(int*)((char*)pSource + 0x3c);
    DAT_00fdf100(d);
    return 0;
}

struct FUN_009fce60_class
{
    void __thiscall FUN_009fce60(int a);
};
struct FUN_009fcee0_class
{
    int* __thiscall FUN_009fcee0(int a, int b);
};
// Calls FUN_009fce60 on the object at offset 4 with a, then stores b (or this if b is null) at offset 4 and zero at offset 8, returning this.
// @fnv 0x009fcee0
int* __thiscall FUN_009fcee0_class::FUN_009fcee0(int aiValue, int apParent)
{
    ((FUN_009fce60_class*)((char*)this + 4))->FUN_009fce60(aiValue);
    *(int*)((char*)this + 4) = apParent ? apParent : (int)this;
    *(int*)((char*)this + 8) = 0;
    return (int*)this;
}

namespace fnv_009fcf10 {
int __stdcall FUN_009f9980(int a, int b);
void __stdcall GetObjectPointer(int a, int b);
extern int DAT_01093f14;

// @fnv 0x009fcf10
int __stdcall FUN_009fcf10(int aObject, int b, int* apOutInterface)
{
    if (!apOutInterface)
        return 0x80004003;
    if (FUN_009f9980(b, (int)&DAT_01093f14))
    {
        GetObjectPointer(aObject, (int)apOutInterface);
        return 0;
    }
    *apOutInterface = 0;
    return 0x80004002;
}
}  // namespace fnv_009fcf10

extern void(__stdcall* DAT_00fdf07c)(void*);
// @fnv 0x009fcfe0
void __fastcall FUN_009fcfe0(void** p)
{
    if (*p)
        DAT_00fdf07c(*p);
}

extern "C" void __cdecl FUN_00e7cd40();
// @fnv 0x009fd480
void __fastcall FUN_009fd480(void* self)
{
    *(int*)((char*)self + 0xa0) = 0;
    FUN_00e7cd40();
}

extern int DAT_01093b4c;
int __stdcall FUN_009f9980(int a, int* b);
int __stdcall GetObjectPointer(int a, int b);
int __stdcall FUN_009fa260(int a, int b, int c);
// @fnv 0x009fd490
int __stdcall FUN_009fd490(int pThis, int b, int c)
{
    if (!c)
        return 0x80004003;
    if (FUN_009f9980(b, &DAT_01093b4c))
    {
        *(int*)(pThis + 0xa0) = 1;
        return GetObjectPointer(pThis - 8, c);
    }
    return FUN_009fa260(pThis, b, c);
}

extern int __stdcall FUN_009f9980(int a, int b);
extern int DAT_01093f04;
struct FUN_009fd530_class
{
    int __thiscall FUN_009fd530(int b);
};
// @fnv 0x009fd530
int __thiscall FUN_009fd530_class::FUN_009fd530(int b)
{
    int* lock = *(int**)((char*)this + 0x20);
    DAT_00fdf05c(lock);
    char* base = (char*)*(int**)((char*)this + 0x98);
    if (FUN_009f9980((int)(base + 0x1a0), b))
    {
        char* p = base + 0x1b0;
        if (FUN_009f9980((int)p, (int)&DAT_01093f04) || FUN_009f9980((int)p, b + 0x10))
        {
            DAT_00fdf100(lock);
            return 0;
        }
    }
    DAT_00fdf100(lock);
    return 1;
}

namespace fnv_009fe0c0 {
extern void(__stdcall* DAT_00fdf0d0)(int*);
extern void(__stdcall* DAT_00fdf1c8)(int, int);
extern void(__stdcall* DAT_00fdf07c)(int*);

struct FUN_009fe0c0_class
{
    int __thiscall FUN_009fe0c0();
};

// Calls DAT_00fdf0d0 on the pointer at this+0x7c, then if the handle at this+0x80 is set, calls DAT_00fdf1c8 and DAT_00fdf07c on it and clears it; returns 0.
// @fnv 0x009fe0c0
int __thiscall FUN_009fe0c0_class::FUN_009fe0c0()
{
    DAT_00fdf0d0((int*)*(int**)((char*)this + 0x7c));
    int handle = *(int*)((char*)this + 0x80);
    if (handle)
    {
        DAT_00fdf1c8(handle, -1);
        DAT_00fdf07c((int*)*(int**)((char*)this + 0x80));
        *(int*)((char*)this + 0x80) = 0;
    }
    return 0;
}
}  // namespace fnv_009fe0c0

int __stdcall FUN_009fcf10(int a, int b, int c);
extern int DAT_01093c3c;
extern int DAT_01093b7c;
// Checks b against two type descriptors and forwards a (offset by 0xc or 0x10) with c to the matching handler, otherwise calls FUN_009fcf10.
// @fnv 0x009fa260
int __stdcall FUN_009fa260(int a, int b, int c)
{
    if (FUN_009f9980(b, &DAT_01093c3c))
        return GetObjectPointer(a ? a + 0xc : 0, c);
    if (FUN_009f9980(b, &DAT_01093b7c))
        return GetObjectPointer(a ? a + 0x10 : 0, c);
    return FUN_009fcf10(a, b, c);
}

typedef int(__stdcall* FUN_009fa5d0_fp)(int);

// @fnv 0x009fa5d0
int __stdcall FUN_009fa5d0(int a)
{
    a += 0x44;
    return (*(FUN_009fa5d0_fp*)&DAT_00fdf1c0)(a);
}

int __stdcall FUN_009fcf10(int a, int b, int c);
extern int DAT_01093bec;
extern int DAT_01093bfc;
extern int DAT_01093f24;
extern int DAT_01093b9c;
// @fnv 0x009fb480
int __stdcall FUN_009fb480(int a, int b, int c)
{
    if (FUN_009f9980(b, &DAT_01093bec))
        return GetObjectPointer(a ? a + 0xc : 0, c);
    if (FUN_009f9980(b, &DAT_01093bfc))
        return GetObjectPointer(a ? a + 0xc : 0, c);
    if (FUN_009f9980(b, &DAT_01093f24))
        return GetObjectPointer(a ? a + 0xc : 0, c);
    if (FUN_009f9980(b, &DAT_01093b9c))
        return GetObjectPointer(a ? a + 0x10 : 0, c);
    return FUN_009fcf10(a, b, c);
}

extern int DAT_01093d84;
extern int DAT_01093d9c;
extern int DAT_01093de8;
extern int DAT_01093e24;
extern int DAT_01093ed4;
struct FUN_009fc890_class
{
    void __thiscall FUN_009fc890(int a, int b, int c, int d, const wchar_t* e, int f);
};
struct FUN_009fdd70_class
{
    int m_vft;
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
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    FUN_009fdd70_class(int a, int b, int c, int d);
};
// Initialises the object: constructs the embedded FUN_009fc890 sub-object with "Output", sets vtable and member pointers, and stores b and c.
// @fnv 0x009fdd70
FUN_009fdd70_class::FUN_009fdd70_class(int a, int b, int c, int d)
{
    ((FUN_009fc890_class*)((char*)this + 8))->FUN_009fc890(0, b, d, a, L"Output", 1);
    m_08 = (int)&DAT_01093de8;
    m_a0 = b;
    m_vft = (int)&DAT_01093e24;
    m_14 = (int)&DAT_01093d9c;
    m_18 = (int)&DAT_01093d84;
    m_a4 = c;
}

int __stdcall FUN_009f9980(int a, int b);
struct FUN_009f9a50_class
{
    int __thiscall FUN_009f9a50();
};
// @fnv 0x009f9a50
int FUN_009f9a50_class::FUN_009f9a50()
{
    if (FUN_009f9980((int)this, (int)&DAT_01093f04) || FUN_009f9980((int)((char*)this + 0x2c), (int)&DAT_01093f04))
        return 1;
    return 0;
}

void __stdcall FUN_009f9c20(SpectatorPackage*);
extern void(__stdcall* DAT_00fdf45c)(SpectatorPackage*);

// @fnv 0x009f9cb0
void __stdcall FUN_009f9cb0(SpectatorPackage* apPackage)
{
    if (apPackage)
    {
        FUN_009f9c20(apPackage);
        DAT_00fdf45c(apPackage);
    }
}

int __fastcall FUN_009fce80(int);
// @fnv 0x009f9f50
int __fastcall FUN_009f9f50(int p)
{
    return FUN_009fce80(p ? p + 4 : 0);
}

struct FUN_009fa1d0_vtbl
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
};
struct FUN_009fa1d0_s
{
    int a;
    int b;
    FUN_009fa1d0_vtbl* vt;
    int c;
    int __stdcall ResetAndQueryVtbl();
};
// @fnv 0x009fa1d0
int __stdcall FUN_009fa1d0_s::ResetAndQueryVtbl()
{
    b = 0;
    c = vt->v4();
    return 0;
}

extern int DAT_01093c9c;
int __stdcall FUN_009f9cb0(int);
struct FUN_009fa560_class
{
    int m_vft;
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
    void __thiscall FUN_009fa560();
};
// @fnv 0x009fa560
void FUN_009fa560_class::FUN_009fa560()
{
    *(int*)this = (int)&DAT_01093c9c;
    if (m_3c)
        FUN_009f9cb0(m_3c);
}

extern void*(__stdcall* DAT_00fdf1c4)(int*);

// @fnv 0x009fa5f0
int __stdcall FUN_009fa5f0(int* pObject)
{
    int* p = (int*)((char*)pObject + 0x44);
    int result;
    if (*p == 1)
    {
        result = 0;
        *p = result;
    }
    else
    {
        result = (int)DAT_00fdf1c4(p);
        if (result != 0)
            return result;
    }

    if ((*(unsigned char*)((char*)pObject + 4) & 8) != 0)
    {
        void** vt = (void**)*pObject;
        ((void(__stdcall*)(int*, int))vt[0x38 / 4])(pObject, 0);
    }

    int* obj = (int*)(*(int*)((char*)pObject + 0x18) + 0xc);
    *(int*)((char*)pObject + 4) = 0;
    *(int*)((char*)pObject + 8) = 0;
    *(int*)((char*)pObject + 0x40) = 0;
    void** vt2 = (void**)*obj;
    ((void(__stdcall*)(int*, int*))vt2[0x20 / 4])(obj, pObject);

    return result;
}

// @fnv 0x009fa800
int __stdcall FUN_009fa800(int* pFlags, int bSet)
{
    if (bSet)
        pFlags[1] |= 1;
    else
        pFlags[1] &= ~1;
    return 0;
}

// @fnv 0x009fa880
int __stdcall FUN_009fa880(int* pFlags, int bSet)
{
    if (bSet)
        *(unsigned int*)(pFlags + 1) |= 2;
    else
        *(unsigned int*)(pFlags + 1) &= 0xfffffffd;
    return 0;
}

extern void(__stdcall* DAT_00fdf1b4)(int, int, int);

struct FUN_009fae70_class
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
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    void __thiscall FUN_009fae70();
};
// If m_34 is set, calls DAT_00fdf1b4 with m_30 and m_34, then clears m_34.
// @fnv 0x009fae70
void __thiscall FUN_009fae70_class::FUN_009fae70()
{
    if (m_34)
    {
        DAT_00fdf1b4(m_30, m_34, 0);
        m_34 = 0;
    }
}

struct FUN_009fc580_class
{
    void FUN_009fb1c0();
    FUN_009fc580_class* Destroy(bool);
};
// @fnv 0x009fc580
FUN_009fc580_class* FUN_009fc580_class::Destroy(bool abFree)
{
    FUN_009fb1c0();
    if (abFree & 1)
        _Deallocate(this);
    return this;
}

extern int DAT_01093cf8;
extern int DAT_01093d28;
struct FUN_009fcc20_class
{
    int __thiscall FUN_009fcb90(int a, int b, int c, int d, int e);
    int __thiscall Initialize(int a, int b, int c);
};
// @fnv 0x009fcc20
int __thiscall FUN_009fcc20_class::Initialize(int a, int b, int c)
{
    FUN_009fcb90(a, b, c, 1, 1);
    *(int*)this = (int)&DAT_01093d28;
    *(int*)((char*)this + 0xc) = (int)&DAT_01093cf8;
    *(int*)((char*)this + 0x60) = 0;
    return (int)this;
}

namespace fnv_009fce80 {
extern int DAT_011f3294;
extern int DAT_011f3298;
extern int(__stdcall* DAT_00fdf1c4)(int*);
extern void(__stdcall* DAT_00fdf0a8)(int);
// @fnv 0x009fce80
void FUN_009fce80()
{
    if (DAT_00fdf1c4(&DAT_011f3298) == 0 && DAT_011f3294)
    {
        DAT_00fdf0a8(DAT_011f3294);
        DAT_011f3294 = 0;
    }
}
}  // namespace fnv_009fce80

struct FUN_009fd120_class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    FUN_009fd120_class(int);
};

// @fnv 0x009fd120
FUN_009fd120_class::FUN_009fd120_class(int)
{
    m_00 = 0;
    m_04 = 0;
    m_08 = 0;
    m_0c = 10;
    m_10 = 0;
    m_14 = 0;
}

struct FUN_009fd140_class
{
    FUN_009fd100_node* m_pFirstNode;
    int m_uiItemCount;
    int m_flag;

    void __thiscall ClearList();
};

// @fnv 0x009fd140
void __thiscall FUN_009fd140_class::ClearList()
{
    FUN_009fd100_node* node = m_pFirstNode;
    while (node != 0)
    {
        FUN_009fd100_node* current = node;
        node = node->next;
        _Deallocate(current);
    }

    m_flag = 0;
    m_uiItemCount = 0;
    m_pFirstNode = 0;
}

struct FUN_009fa350_class
{
    void DispatchCall();
};
struct FUN_009fd450_class
{
    void FUN_009fd450();
};
// @fnv 0x009fd450
void FUN_009fd450_class::FUN_009fd450()
{
    *(int*)((char*)this + 0xa0) = 0;
    ((FUN_009fa350_class*)this)->DispatchCall();
}

struct FUN_009fe690_class
{
    int __thiscall FUN_009fe690();
};
// @fnv 0x009fdbb0
int __stdcall FUN_009fdbb0(int a)
{
    return ((FUN_009fe690_class*)*(int**)(a + 0xa4))->FUN_009fe690();
}

struct FUN_009fdcb0_class
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual int v18();
    int* __thiscall FUN_009fdcb0(int a);
};
// Returns a pointer to the slot at offset 0xf8 when v18() is positive and a is zero, otherwise returns null.
// @fnv 0x009fdcb0
int* FUN_009fdcb0_class::FUN_009fdcb0(int a)
{
    if (v18() > 0 && a == 0 && (char*)this + 0xf0 != 0)
        return (int*)((char*)this + 0xf8);
    return 0;
}

extern "C" __declspec(dllimport) unsigned int __stdcall D3DPERF_SetOptions(unsigned int dwOptions);

// @fnv 0x009f9968
unsigned int __stdcall FUN_009f9968(unsigned int dwOptions)
{
    return D3DPERF_SetOptions(dwOptions);
}

extern "C" __declspec(dllimport) void __stdcall CoTaskMemFree(void* pv);

struct FUN_009f9c20_cls
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
    void* m_3c;
    void* m_40;
    void* m_44;
};

// @fnv 0x009f9c20
void __stdcall FUN_009f9c20(FUN_009f9c20_cls* p)
{
    if (p->m_40 != 0)
    {
        CoTaskMemFree(p->m_44);
        p->m_40 = 0;
        p->m_44 = 0;
    }
    if (p->m_3c != 0)
    {
        void** vt = *(void***)p->m_3c;
        ((void(__stdcall*)(void*))vt[2])(p->m_3c);
        p->m_3c = 0;
    }
}

// FUN_009f9c60 - a __thiscall member that hands `this` to the __stdcall
// free helper FUN_009f9c20 (which pops the argument itself), so the member
// ends in a bare `ret`.
//
//   009f9c60  51              push ecx
//   009f9c61  e8baffffff      call 0x009f9c20
//   009f9c66  c3              ret

void __stdcall FUN_009f9c20(SpectatorPackage* pkg);

struct SpectatorPackageImpl : SpectatorPackage
{
    void FUN_009f9c60();
};

// @fnv 0x009f9c60
void SpectatorPackageImpl::FUN_009f9c60()
{
    FUN_009f9c20(this);
}

struct SeekableStream
{
    virtual int __stdcall vfn_00() = 0;
    virtual int __stdcall vfn_04() = 0;
    virtual int __stdcall vfn_08() = 0;
    virtual int __stdcall GetPosition(__int64* position) = 0;
};

struct OffsetStream
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    SeekableStream* underlying;
    unsigned int unk1C;
    __int64 baseOffset;
    int FUN_009f9db0(__int64* position);
};

// @fnv 0x009f9db0
int OffsetStream::FUN_009f9db0(__int64* position)
{
    if (underlying == 0)
    {
        return (int)0x80040213;
    }

    int result = underlying->GetPosition(position);
    if (result >= 0)
    {
        *position -= baseOffset;
        return 0;
    }
    return result;
}

// @fnv 0x009f9f40
int __stdcall FUN_009f9f40(int a, int b)
{
    return (int)0x80004001;
}

typedef void(__thiscall* FUN_009f9f70_fn)(void* self, void* pRef);

struct FUN_009f9f70_leaf
{
    int unk00;
    int unk04;
    FUN_009f9f70_fn m_08;
};

struct FUN_009f9f70_holder
{
    int unk00;
    int unk04;
    int unk08;
    FUN_009f9f70_leaf* m_0c;
};

class FUN_009f9f70_member
{
  public:
    ~FUN_009f9f70_member();
    int unk00;
};

class FUN_009f9f70_cls
{
  public:
    virtual ~FUN_009f9f70_cls();
    int unk04;
    int unk08;
    FUN_009f9f70_holder* m_0c;
    int unk10;
    int unk14;
    FUN_009f9f70_member m_18;
};

// Destructor that fetches the leaf callback from m_0c and invokes it with the leaf and the holder's m_0c address.
// @fnv 0x009f9f70
FUN_009f9f70_cls::~FUN_009f9f70_cls()
{
    FUN_009f9f70_holder* pLeafHolder = m_0c;
    FUN_009f9f70_leaf* pLeaf = pLeafHolder->m_0c;
    FUN_009f9f70_fn fn = pLeaf->m_08;
    fn(pLeaf, &pLeafHolder->m_0c);
}

extern int DAT_01093c2c;
extern int DAT_01093f14;

// Returns E_POINTER if out is null; checks p2 against two globals and returns E_NOINTERFACE with *out=0 if neither matches, otherwise delegates to GetObjectPointer.
// @fnv 0x009f9fe0
int __stdcall GetInterfaceForObject(int pUnk, int pIid, int* ppvOut)
{
    if (ppvOut == 0)
    {
        return 0x80004003;
    }
    if (FUN_009f9980(pIid, (int*)&DAT_01093c2c) == 0)
    {
        if (FUN_009f9980(pIid, (int*)&DAT_01093f14) == 0)
        {
            *ppvOut = 0;
            return 0x80004002;
        }
    }
    return GetObjectPointer(pUnk, (int)ppvOut);
}

class DepObj
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual int v14();
    virtual int v18();
};

class HolderSub
{
  public:
    void Reset();
};

class CallerHolder
{
  public:
    int m_00;
    int m_04;
    int m_08;
    DepObj* m_0c;
    int m_10;
    int m_14;
    HolderSub m_18;
};

// @fnv 0x009fa090
int __stdcall FUN_009fa090(CallerHolder* apHolder)
{
    CallerHolder* esi = apHolder;
    esi->m_10 = esi->m_0c->v14();
    esi->m_08 = esi->m_0c->v18();
    esi->m_04 = 0;
    esi->m_18.Reset();
    return 0;
}

struct Intf
{
    virtual int unk0();
    virtual int unk1();
    virtual int unk2();
    virtual int unk3();
    virtual int unk4();
    virtual int m0();
    virtual int m1();
};

int Intf::unk0()
{
    return 0;
}
int Intf::unk1()
{
    return 0;
}
int Intf::unk2()
{
    return 0;
}
int Intf::unk3()
{
    return 0;
}
int Intf::unk4()
{
    return 0;
}
int Intf::m0()
{
    return 0;
}
int Intf::m1()
{
    return 0;
}

// Reads an interface pointer from a+0xC, stores m0() at a+0x10 and m1() at a+0x08, clears a+0x04, and returns 0.
// @fnv 0x009fa0d0
int __stdcall InitFromInterface(int a)
{
    Intf* p = *(Intf**)(a + 0xC);
    int r = p->m0();
    p = *(Intf**)(a + 0xC);
    *(int*)(a + 0x10) = r;
    *(int*)(a + 0x08) = p->m1();
    *(int*)(a + 0x04) = 0;
    return 0;
}

// Vtable of the class this function belongs to; supplied by the game data.
extern int DAT_01093c74[];

struct VkCallback
{
    void* m_pUnknown00;
    void* m_pUnknown04;
    void(__stdcall* m_pInvoke)(void*);
};

struct VkInner
{
    void* m_pUnknown00;
    void* m_pUnknown04;
    void* m_pUnknown08;
    VkCallback* m_pCallback;
};

struct FUN_009fa100_cls
{
    void* m_pVTable;
    int m_iUnknown04;
    VkInner* m_pInner;
    void InitVTableAndInvokeCallback();
};

// @fnv 0x009fa100
void FUN_009fa100_cls::InitVTableAndInvokeCallback()
{
    m_pVTable = DAT_01093c74;

    VkInner* inner = m_pInner;
    VkCallback* callback = inner->m_pCallback;
    callback->m_pInvoke(&inner->m_pCallback);
}

extern int DAT_01093c1c;

// @fnv 0x009fa120
int __stdcall FUN_009fa120(int a, int b, int* apOut)
{
    if (apOut == 0)
    {
        return 0x80004003;
    }

    if (FUN_009f9980(b, &DAT_01093c1c) || FUN_009f9980(b, &DAT_01093f14))
    {
        return GetObjectPointer(a, (int)apOut);
    }

    *apOut = 0;
    return 0x80004002;
}

int __cdecl FormHeap_Free(int);

class SubA4
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ~SubA4();
};

class SubB34
{
  public:
    unsigned int unk00;
    ~SubB34();
};

class FUN_009fa1f0_cls
{
  public:
    unsigned int unk00;
    SubA4 m_04;
    int m_14;
    unsigned char unk18[0x1c];
    SubB34 m_34;
    ~FUN_009fa1f0_cls();
};

// @fnv 0x009fa1f0
FUN_009fa1f0_cls::~FUN_009fa1f0_cls()
{
    FormHeap_Free(m_14);
}

struct S_009fa2f0_table
{
    int(__cdecl* m_fn0)(void*);
    int(__cdecl* m_fn1)(void*);
};

struct S_009fa2f0_sub
{
    int unk00;
    int unk04;
    int unk08;
    S_009fa2f0_table* unk0c;
};

struct S_009fa2f0_owner
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
    S_009fa2f0_sub* unk28;
};

// @fnv 0x009fa2f0
int __cdecl FUN_009fa2f0(S_009fa2f0_owner* pOwner)
{
    S_009fa2f0_sub* s = pOwner->unk28;
    return s->unk0c->m_fn1(&s->unk0c);
}

struct FUN_009fa380_child
{
    virtual void v00();
    virtual void v04();
    virtual void __stdcall Release();
};

struct FUN_009fa380_cls
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
    virtual int v2c();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_009fa380_child* m_pChildObject;
};

// @fnv 0x009fa380
int __stdcall FUN_009fa380(FUN_009fa380_cls* apObj)
{
    int result;
    if (apObj->m_pChildObject != 0)
    {
        result = apObj->v2c();
        if (result < 0)
        {
            goto done;
        }
        apObj->m_pChildObject->Release();
        apObj->m_pChildObject = 0;
        return 0;
    }
    result = 1;
done:
    return result;
}

class FUN_009fa4a0_cls
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
    virtual int v08(void* a);
};

// Returns E_POINTER for a null value, otherwise calls the virtual v08 on the object at p-0xc and maps a negative result to 1.
// @fnv 0x009fa4a0
int __stdcall FUN_009fa4a0(FUN_009fa4a0_cls* apObject, void* value)
{
    if (value == 0)
    {
        return 0x80004003;
    }
    FUN_009fa4a0_cls* self = (FUN_009fa4a0_cls*)((char*)apObject - 0xc);
    int r = self->v08(value);
    return r < 0 ? 1 : r;
}

struct FUN_009fa4d0_cls
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
    unsigned char m_24;
    int FUN_009fa4d0();
};

// @fnv 0x009fa4d0
int FUN_009fa4d0_cls::FUN_009fa4d0()
{
    m_24 = 0;
    return 0;
}

// FUN_009fa510: stdcall stub returning E_NOTIMPL (0x80004001) with 8 unused stack parameters.
// @fnv 0x009fa510
long __stdcall FUN_009fa510(int unk00, int unk04, int unk08, int unk0C, int unk10, int unk14, int unk18, int unk1C)
{
    return (long)0x80004001;
}

class FUN_009fa670_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_14;
};

// @fnv 0x009fa670
int __stdcall FUN_009fa670(FUN_009fa670_cls* obj)
{
    return obj->m_14;
}

struct ObjQueryRecord
{
    unsigned int unk00;
    unsigned int m_flags04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned __int64 m_value20;
    unsigned __int64 m_value28;
};

// Checks rec->m_flags04 bits 0x100/0x10 and writes rec->m_value20/m_value28 (or m_value20 and m_value20+1) to outA/outB, returning a status code.
// @fnv 0x009fa680
unsigned int __stdcall GetRecordValues(ObjQueryRecord* pRecord, unsigned __int64* outA, unsigned __int64* outB)
{
    if ((pRecord->m_flags04 & 0x100) == 0)
    {
        if ((pRecord->m_flags04 & 0x10) == 0)
        {
            return 0x80040249;
        }
        goto copyOne;
    }
    *outA = pRecord->m_value20;
    *outB = pRecord->m_value28;
    return 0;

copyOne:
    *outA = pRecord->m_value20;
    *outB = pRecord->m_value20 + 1;
    return 0x40270;
}

// @fnv 0x009fa760
int __stdcall FUN_009fa760(void* pObject, int* pStart, int* pEnd)
{
    if (!(((unsigned char*)pObject)[4] & 0x20))
        return 0x80040251;

    int* p = (int*)pObject;
    *(__int64*)pStart = *(__int64*)(p + 12);
    *(__int64*)pEnd = (__int64)p[14] + *(__int64*)(p + 12);
    return 0;
}

// Returns 1 when the low bit of the flag byte at offset 4 is clear, 0 otherwise.
// @fnv 0x009fa7e0
int __stdcall IsFlagBit0Clear(int* pFlags)
{
    unsigned char flag = ((unsigned char*)pFlags)[4];
    if ((flag & 1) == 0)
        return 1;
    return 0;
}

// Reads the byte field at offset 4 of the argument and returns bit 1 of its
// complement (i.e. 1 when that bit of the raw byte is 0).
// @fnv 0x009fa860
int __stdcall GetTwoBits(unsigned char* pucData)
{
    unsigned int u = (unsigned char)(~pucData[4]);
    unsigned int w = u >> 1;
    return (int)((w & 1u) | ((u & 2u) >> 1));
}

struct FUN_009fa8a0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_10;
};

// @fnv 0x009fa8a0
int __stdcall FUN_009fa8a0(FUN_009fa8a0_cls* a1)
{
    return a1->m_10;
}

extern "C" int DAT_01093d28;
extern "C" int DAT_01093cf8;
struct EntryObject
{
    void* volatile vtable;
    int unk04;
    int unk08;
    void* volatile secondaryVtable;
    void FUN_009faf50(void* subobject);
    void FUN_009fb170();
    void FUN_009fabb0();
    void FUN_009fb1c0();
};
struct CleanupGuard
{
    EntryObject* const owner;
    CleanupGuard(EntryObject* obj) : owner(obj)
    {
        obj->vtable = &DAT_01093d28;
        obj->secondaryVtable = &DAT_01093cf8;
    }
    ~CleanupGuard()
    {
        owner->FUN_009fabb0();
    }
};
// @fnv 0x009fb1c0
void EntryObject::FUN_009fb1c0()
{
    CleanupGuard cleanup(this);
    FUN_009faf50((void*)&secondaryVtable);
    FUN_009fb170();
}

struct C9FB250GUID;

class C9FB250Unknown
{
  public:
    virtual long __stdcall QueryInterface(const C9FB250GUID& riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

class C9FB250BaseObject
{
  public:
    virtual ~C9FB250BaseObject();

    C9FB250Unknown* m_pUnknown;
    const char* m_pName;
};

class FUN_009fb250 : public C9FB250BaseObject, public C9FB250Unknown
{
  public:
    virtual long __stdcall QueryInterface(const C9FB250GUID& riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

// DECLARE_IUNKNOWN
// @fnv 0x009fb250
unsigned long __stdcall FUN_009fb250::AddRef()
{
    return m_pUnknown->AddRef();
}

struct FBC50Filter
{
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0C();
    virtual void vfunc10();
    virtual int GetPinVersion();
};

struct FBC50EnumPins
{
    virtual long __stdcall FUN_009fbc50(unsigned long cPins);

    unsigned int m_uiReferenceCount;
    unsigned int m_PinCount;
    FBC50Filter* m_pOwnerFilter;
    int m_iCurrentPinIndex;
};

// Checks the filter's pin version against the stored version, then advances the pin index by cPins if it fits within the pin count, returning an HRESULT.
// @fnv 0x009fbc50
long __stdcall FBC50EnumPins::FUN_009fbc50(unsigned long cPins)
{
    if (m_pOwnerFilter->GetPinVersion() != m_iCurrentPinIndex)
        return 0x80040203;
    if (cPins > m_PinCount - m_uiReferenceCount)
        return 1;
    m_uiReferenceCount += cPins;
    return 0;
}

struct SubPart
{
    int unk00;
    SubPart(int value);
    ~SubPart();
    void Assign(const SubPart* other);
};

struct ResultRec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    SubPart m_18;
};

struct TargetObj
{
    int unk00;
    void* (TargetObj::*m_04)(TargetObj** owner);
};

struct SourceObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual int v14();
    virtual int v18();
    int unk04;
    int unk08;
    TargetObj* m_0c;
};

extern char g_layoutVtable[];

struct LayoutBase
{
    void* m_00;
    int m_04;
    int m_08;
    SourceObj* m_0c;
    int m_10;
    int m_14;
    LayoutBase(SourceObj* src);
};

struct FUN_009fc600 : LayoutBase
{
    SubPart m_18;

    FUN_009fc600(SourceObj* src, ResultRec* rec);
};

LayoutBase::LayoutBase(SourceObj* src)
{
    m_00 = g_layoutVtable;
    m_04 = 0;
    m_08 = 0;
    m_0c = src;
    m_14 = 1;
}

// Initializes the base from src, invokes a callback on src->m_0c, then copies fields from rec if non-null, otherwise reads v14/v18 from m_0c.
// @fnv 0x009fc600
FUN_009fc600::FUN_009fc600(SourceObj* apSource, ResultRec* apRecord) : LayoutBase(apSource), m_18(0)
{
    SourceObj* s = m_0c;
    (s->m_0c->*(s->m_0c->m_04))(&s->m_0c);
    if (apRecord == 0)
    {
        m_10 = m_0c->v14();
        m_08 = m_0c->v18();
    }
    else
    {
        m_04 = apRecord->unk04;
        m_08 = apRecord->unk08;
        m_10 = apRecord->unk10;
        m_18.Assign(&apRecord->m_18);
    }
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct PinCritSecLock
{
    int* m_pLock;
    PinCritSecLock(int* lock) : m_pLock(lock)
    {
        EnterCriticalSection(lock);
    }
    ~PinCritSecLock()
    {
        LeaveCriticalSection(m_pLock);
    }
};

struct PinFilterStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_iValueAt14;
};

struct PinUnknownBase
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
    virtual void Cleanup();
    int unk04;
    int unk08;
};

struct PinIface
{
    virtual long __stdcall QueryInterface(void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall ReceiveConnection(void* pReceivePin, void* pmt);
};

struct PinQualityIface
{
    virtual long __stdcall QueryInterface(void*, void**);
};

struct BasePinStub : PinUnknownBase, PinIface, PinQualityIface
{
    int unk14;
    void* m_Connected;
    int unk1c;
    int* m_pLock;
    char unk24;
    char m_bCanReconnectWhenActive;
    char unk26;
    char unk27;
    PinFilterStub* m_pOwnerFilter;

    long AgreeMediaType(void* pReceivePin, void* pmt);
    bool IsStopped()
    {
        return m_pOwnerFilter->m_iValueAt14 == 0;
    }
    virtual long __stdcall ReceiveConnection(void* pReceivePin, void* pmt);
};

// Validates the receive pin and media type, checks connection state and lock, calls AgreeMediaType and Cleanup on failure, and returns an HRESULT.
// @fnv 0x009fc990
long __stdcall BasePinStub::ReceiveConnection(void* pReceivePin, void* pMediaType)
{
    if (pReceivePin == 0)
    {
        return 0x80004003;
    }
    PinCritSecLock lock(m_pLock);
    if (m_Connected)
    {
        return 0x80040204;
    }
    if (!IsStopped() && !m_bCanReconnectWhenActive)
    {
        return 0x80040224;
    }
    long hr = AgreeMediaType(pReceivePin, pMediaType);
    if (hr < 0)
    {
        Cleanup();
        return hr;
    }
    return 0;
}

struct FUN_009fceb0_object
{
    virtual void __stdcall first_virtual()
    {}
    virtual void __stdcall second_virtual()
    {}
};

// @fnv 0x009fceb0
int __stdcall GetObjectPointer(FUN_009fceb0_object* object, int* target)
{
    if (target == 0)
        return 0x80004003;

    *target = reinterpret_cast<int>(object);
    object->second_virtual();
    return 0;
}

class CNode9FD
{
  public:
    CNode9FD* m_pListObject;
    CNode9FD* m_pNext;
    void* m_pObject;
};

typedef CNode9FD* POSITION9FD;

static __declspec(noinline) void* __stdcall GetNodeObject9FD(POSITION9FD pos)
{
    if (pos == 0)
        return 0;
    return pos->m_pObject;
}

void*(__stdcall* g_pfnGetNodeObject9FD)(POSITION9FD) = GetNodeObject9FD;

class CBaseList9FD
{
  public:
    POSITION9FD GetHeadPositionI() const;
    POSITION9FD Next(POSITION9FD pos) const
    {
        if (pos == 0)
            return m_pFirst;
        return pos->m_pNext;
    }
    POSITION9FD Find(void* pObj) const;

    CNode9FD* m_pFirst;
};

__declspec(noinline) POSITION9FD CBaseList9FD::GetHeadPositionI() const
{
    return m_pFirst;
}

// Scans the list from the head and returns the position whose node object equals pObj, or 0 if none matches.
// @fnv 0x009fd1c0
POSITION9FD CBaseList9FD::Find(void* pObject) const
{
    POSITION9FD pn;
    for (pn = GetHeadPositionI(); pn; pn = Next(pn))
    {
        if (GetNodeObject9FD(pn) == pObject)
            return pn;
    }
    return 0;
}

struct S_009fd390_Base
{
    int m_00;
    int __thiscall RemoveNode(int a);
};

struct FUN_009fd390_cls : S_009fd390_Base
{
    int __thiscall FUN_009fd390();
};

// @fnv 0x009fd390
int __thiscall FUN_009fd390_cls::FUN_009fd390()
{
    return RemoveNode(m_00);
}

struct S_009fd3f0_Impl
{
    void** m_vptr;
};
typedef void(__cdecl* S_009fd3f0_fn)(void*);
// @fnv 0x009fd3f0
void __cdecl InvokeVirtualMethod(void* arg)
{
    S_009fd3f0_Impl* impl = *(S_009fd3f0_Impl**)((char*)arg + 0x0c);
    void** pVtable = impl->m_vptr;
    *(S_009fd3f0_Impl* volatile*)&arg = impl;
    S_009fd3f0_fn fn = (S_009fd3f0_fn)pVtable[0];
    fn(arg);
}

struct CallbackInterface
{
    virtual void __cdecl NotifyFirst();
    virtual int __cdecl NotifySecond();
};
struct CallbackOwner
{
    void* userData;
    void* context;
    void* next;
    CallbackInterface* handler;
};
// @fnv 0x009fd410
int __cdecl InvokeHandlerSecond(CallbackOwner* owner)
{
    return owner->handler->NotifySecond();
}

class Pin9FD460
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
    void* m_pConnected;

    long Forward(void* p);
    long ForwardIfConnected(void* p);
};

// @fnv 0x009fd460
long Pin9FD460::ForwardIfConnected(void* p)
{
    if (m_pConnected != 0)
        return Forward(p);
    return 0x80040266;
}

struct Interface
{
    virtual void __stdcall method0();
    virtual void __stdcall method1();
    virtual void __stdcall method2();
    virtual void __stdcall method3();
    virtual void __stdcall method4();
    virtual void __stdcall method5();
    virtual void __stdcall method6();
    virtual void __stdcall method7();
    virtual void __stdcall method8();
    virtual void __stdcall method9();
    virtual void __stdcall method10();
    virtual void __stdcall method11();
    virtual void __stdcall OnReady(int flags);
};
struct Worker
{
    int __thiscall WaitForCompletion(int resource, Interface** result, int flags, int* originalFlags);
};
struct Device
{
    int m_vft;
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
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    Worker* m_a4;
};
// @fnv 0x009fdaf0
int __stdcall FUN_009fdaf0(Device* device, int resource, Interface** output, int flags)
{
    if (output == 0)
        return 0x80004003;
    Interface* result = 0;
    int status = device->m_a4->WaitForCompletion(resource, &result, flags, &flags);
    if (status >= 0)
        result->OnReady(flags);
    *output = result;
    return status;
}

struct FUN_009fe100_class
{
    void __thiscall FUN_009fe100(int a, int b, int c, int d);
};

// Forwards the four integer arguments to the FUN_009fe100 method of the object stored at owner->m_a4.
// @fnv 0x009fdb60
void __stdcall FUN_009fdb60(FUN_009fdd70_class* owner, int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    ((FUN_009fe100_class*)owner->m_a4)->FUN_009fe100(aiArg1, aiArg2, aiArg3, aiArg4);
}

struct FUN_009fe090_class
{
    int __thiscall GetHelperValue(int a, int b);
};

struct FUN_009fdb90_class
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
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    FUN_009fe090_class* m_a4;
};

// @fnv 0x009fdb90
void __stdcall FUN_009fdb90(FUN_009fdb90_class* p, int aiArg1, int aiArg2)
{
    p->m_a4->GetHelperValue(aiArg1, aiArg2);
}

// @fnv 0x009fdbf0
void __stdcall CallVirtualMethod9(int aiObject, int aiArg1, int aiArg2)
{
    void* p = *(void**)(aiObject + 0x8c);
    typedef void(__thiscall * Method)(void*, int, int);
    Method m = (Method)(*(void***)p)[9];
    m(p, aiArg1, aiArg2);
}

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* pkSection);

struct FDC10CriticalSection
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;

    ~FDC10CriticalSection()
    {
        DeleteCriticalSection(this);
    }
};

struct FDC10ListA
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

    ~FDC10ListA();
};

struct FDC10ListB
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

    ~FDC10ListB();
};

struct FDC10ListC
{
    int unk00;

    ~FDC10ListC();
};

class FDC10BaseFilter
{
  public:
    int unk04;
    int unk08;

    virtual ~FDC10BaseFilter();
};

class FDC10InterfaceA
{
  public:
    virtual long __stdcall QueryInterface(const void* riid, void** ppv);
};

class FDC10InterfaceB
{
  public:
    virtual long __stdcall QueryInterface(const void* riid, void** ppv);
};

class FUN_009fdc10 : public FDC10BaseFilter, public FDC10InterfaceA, public FDC10InterfaceB
{
  public:
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
    FDC10CriticalSection m_kLock;
    FDC10ListA m_kListA;
    FDC10ListB m_kListB;
    FDC10ListC m_kListC;

    virtual ~FUN_009fdc10();
};

// Destructor for the filter object; the body is empty, member destructors run automatically.
// @fnv 0x009fdc10
FUN_009fdc10::~FUN_009fdc10()
{}

struct FUN_009fded0_cls
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
    int __thiscall FUN_009fded0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
};

// @fnv 0x009fded0
int __thiscall FUN_009fded0_cls::FUN_009fded0(int aiField00, int aiField04, int aiField08, int aiField0c, int aiField14,
                                              int aiField10, int aiField18, int aiField1c, int aiField20)
{
    m_00 = aiField00;
    m_04 = aiField04;
    m_08 = aiField08;
    m_0c = aiField0c;
    m_14 = aiField14;
    m_10 = aiField10;
    m_18 = aiField18;
    m_1c = aiField1c;
    m_20 = aiField20;
    m_24 = 0x8004022e;
    return 0;
}

class FUN_009fe090_helper
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual unsigned __int64 v0C(unsigned int arg);
};

class FUN_009fe090_cls
{
  public:
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0C;
    unsigned int m_unk10;
    unsigned int m_unk14;
    FUN_009fe090_helper* m_pHelper;
    int GetHelperValue(unsigned __int64* out, unsigned int arg);
};

// @fnv 0x009fe090
int FUN_009fe090_cls::GetHelperValue(unsigned __int64* out, unsigned int arg)
{
    if (out == 0)
    {
        return 0x80004003;
    }
    unsigned __int64 value = m_pHelper->v0C(arg);
    *out = value;
    return 0;
}

struct S_9fe1a0_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
};
struct S_9fe1a0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S_9fe1a0_Obj* unk18;
    long GetValue(int* out);
};
// @fnv 0x009fe1a0
long S_9fe1a0_Class::GetValue(int* piOut)
{
    if (!piOut)
        return 0x80004003;
    *piOut = unk18->v4();
    return 0;
}

__declspec(dllimport) void __stdcall InitializeCriticalSection(void*);

struct S_Lock
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S_Lock()
    {
        InitializeCriticalSection(this);
    }
    ~S_Lock();
};
struct S_Blk
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void Init(int a);
    S_Blk()
    {
        Init(0);
    }
    ~S_Blk();
};
struct S_Evt
{
    int unk00;
    S_Evt(int a);
    ~S_Evt();
};
struct FUN_009fe1d0 : S_Lock
{
    int unk18;
    S_Lock m_1c;
    int unk34;
    S_Blk m_38;
    S_Blk m_50;
    S_Evt m_68;
    S_Evt m_6c;
    int unk70;
    int unk74;
    S_Evt m_78;
    S_Evt m_7c;
    int unk80;
    FUN_009fe1d0(int a);
};
// Constructs the object, initialising unk18 from a and default-initialising the lock, block and event members.
// @fnv 0x009fe1d0
FUN_009fe1d0::FUN_009fe1d0(int aiValue)
    : unk18(aiValue), unk34(0), m_38(), m_50(), m_68(1), m_6c(1), unk70(0), unk74(0), m_78(0), m_7c(1), unk80(0)
{}

struct FUN_009fd270_class
{
    int __thiscall AddNode(int);
};

struct FUN_009fe3f0_class
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
    FUN_009fd270_class m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;

    int __thiscall FUN_009fe3f0(int);
};

extern void(__stdcall* DAT_00fdf0d0)(void*);

// @fnv 0x009fe3f0
int __thiscall FUN_009fe3f0_class::FUN_009fe3f0(int value)
{
    if (m_50.AddNode(value))
    {
        DAT_00fdf0d0(reinterpret_cast<void*>(m_6c));
        return 0;
    }

    return static_cast<int>(0x8007000e);
}

class ForwardTarget
{
  public:
    void Tail();
};

// @fnv 0x009fe560
void __stdcall FUN_009fe560(ForwardTarget* p)
{
    p->Tail();
}

extern int DAT_011a6224;

// @fnv 0x009fea24
int __cdecl FUN_009fea24()
{
    return DAT_011a6224;
}

extern void(__cdecl* DAT_011a6238)(void);

// @fnv 0x009fead0
void __cdecl FUN_009fead0()
{
    DAT_011a6238();
}

extern void(__cdecl* DAT_011a6250)(void);

// @fnv 0x009feae2
void __cdecl FUN_009feae2()
{
    DAT_011a6250();
}

namespace fnv_009f9cd0 {
extern void*(__stdcall* DAT_00fdf460)(unsigned long);
extern void(__stdcall* DAT_00fdf45c)(void*);

int __stdcall FUN_009f9bb0(void* obj, int a);

// @fnv 0x009f9cd0
int __stdcall FUN_009f9cd0(int a)
{
    void* obj = DAT_00fdf460(0x48);
    if (obj == 0)
        return 0;

    if (FUN_009f9bb0(obj, a) < 0)
    {
        DAT_00fdf45c(obj);
        return 0;
    }

    return (int)obj;
}
}  // namespace fnv_009f9cd0

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" void* __cdecl memset(void*, int, unsigned int);

struct AllocSysInfo
{
    unsigned long dwOemId;
    unsigned long dwPageSize;
    void* lpMinimumApplicationAddress;
    void* lpMaximumApplicationAddress;
    unsigned long dwActiveProcessorMask;
    unsigned long dwNumberOfProcessors;
    unsigned long dwProcessorType;
    unsigned long dwAllocationGranularity;
    unsigned long dwProcessorLevelRevision;
};
extern "C" __declspec(dllimport) void __stdcall GetSystemInfo(AllocSysInfo*);

struct AllocProps
{
    long cBuffers;
    long cbBuffer;
    long cbAlign;
    long cbPrefix;
};

struct AllocCritSec
{
    int m_cs00;
    int m_cs04;
    int m_cs08;
    int m_cs0c;
    int m_cs10;
    int m_cs14;
};

struct AllocLock
{
    AllocCritSec* m_pLock;
    AllocLock(AllocCritSec* lock) : m_pLock(lock)
    {
        EnterCriticalSection(lock);
    }
    ~AllocLock()
    {
        LeaveCriticalSection(m_pLock);
    }
};

struct AllocUnknown
{
    virtual long __stdcall NonDelegatingQueryInterface(const void* riid, void** ppv);
    void* m_pName;
    void* m_pUnknown;
};

struct AllocIface
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall SetAllocProperties(AllocProps* pRequest, AllocProps* pActual) = 0;
};

struct AllocSampleList
{
    void* m_kEntryList;
    int m_nOnList;
    int GetCount() const
    {
        return m_nOnList;
    }
};

struct MemAllocStub : AllocUnknown, AllocIface, AllocCritSec
{
    AllocSampleList m_lFree;
    void* m_hSem;
    long m_lWaiting;
    long m_lCount;
    long m_lAllocated;
    long m_lSize;
    long m_lAlignment;
    long m_lPrefix;
    int m_bChanged;
    int m_bCommitted;

    long __stdcall SetAllocProperties(AllocProps* pRequest, AllocProps* pActual);
};

// @fnv 0x009fb050
long __stdcall MemAllocStub::SetAllocProperties(AllocProps* pRequestedProps, AllocProps* pActualProps)
{
    if (pActualProps == 0)
    {
        return 0x80004003;
    }
    AllocLock cObjectLock(this);

    memset(pActualProps, 0, sizeof(AllocProps));

    AllocSysInfo SysInfo;
    GetSystemInfo(&SysInfo);

    if (pRequestedProps->cbAlign == 0 || (SysInfo.dwAllocationGranularity & (pRequestedProps->cbAlign - 1)) != 0)
    {
        return 0x8004020e;
    }

    if (m_bCommitted == 1)
    {
        return 0x8004020f;
    }

    if (m_lFree.GetCount() < m_lAllocated)
    {
        return 0x80040210;
    }

    long lAlignedSize = pRequestedProps->cbBuffer + pRequestedProps->cbPrefix;
    long lRemainder = lAlignedSize % pRequestedProps->cbAlign;
    if (lRemainder != 0)
    {
        lAlignedSize = lAlignedSize - lRemainder + pRequestedProps->cbAlign;
    }
    pActualProps->cbBuffer = m_lSize = (lAlignedSize - pRequestedProps->cbPrefix);

    pActualProps->cBuffers = m_lCount = pRequestedProps->cBuffers;
    pActualProps->cbAlign = m_lAlignment = pRequestedProps->cbAlign;
    pActualProps->cbPrefix = m_lPrefix = pRequestedProps->cbPrefix;

    m_bChanged = 1;
    return 0;
}

// Forwards through a function table: the object stored 8 bytes before p
// begins with a pointer to a table of plain functions; entry 0 is called
// with that object and the forwarded second argument.
typedef void(__cdecl* ForwardFn)(void* obj, int arg);

// @fnv 0x009fb230
void __cdecl FUN_009fb230(void** p, int arg)
{
    p = (void**)p[-2];
    (*(ForwardFn*)*p)(p, arg);
}

struct FnvCpu_FUN_009fd0f0_CpuObject
{
    int value;
    int FUN_009fd0f0();
};
// @fnv 0x009fd0f0
int FnvCpu_FUN_009fd0f0_CpuObject::FUN_009fd0f0()
{
    return value;
}

extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);

struct Vector4f
{
    int x;
    int y;
    int z;
    int w;
};

extern int DAT_01093f04;
int __stdcall FUN_009f9980(int, int);

static inline int operator==(const Vector4f& a, const Vector4f& b)
{
    return FUN_009f9980((int)&a, (int)&b);
}

static inline int operator!=(const Vector4f& a, const Vector4f& b)
{
    return !(a == b);
}

struct MediaType
{
    Vector4f majortype;
    Vector4f subtype;
    int bFixedSizeSamples;
    int bTemporalCompression;
    int lSampleSize;
    Vector4f formattype;
    void* pUnk;
    unsigned int cbFormat;
    unsigned char* pbFormat;

    int FUN_009f9a80(const MediaType* ppartial) const;
};

// CMediaType::MatchesPartial(const CMediaType *ppartial) const
// Returns 1 if the partial MediaType matches this one, treating a null GUID in the partial as a wildcard for that field.
// @fnv 0x009f9a80
int MediaType::FUN_009f9a80(const MediaType* ppartial) const
{
    const Vector4f& guidNull = *(const Vector4f*)&DAT_01093f04;

    if ((ppartial->majortype != guidNull) && (majortype != ppartial->majortype))
    {
        return 0;
    }
    if ((ppartial->subtype != guidNull) && (subtype != ppartial->subtype))
    {
        return 0;
    }

    if (ppartial->formattype != guidNull)
    {
        if (formattype != ppartial->formattype)
        {
            return 0;
        }
        if (cbFormat != ppartial->cbFormat)
        {
            return 0;
        }
        if ((cbFormat != 0) && (memcmp(pbFormat, ppartial->pbFormat, cbFormat) != 0))
        {
            return 0;
        }
    }

    return 1;
}

class S009f9d50_Value
{
  public:
    S009f9d50_Value& FUN_009f9c80(const S009f9d50_Value& kOther);  // operator=
    S009f9d50_Value& FUN_009f9d50(const S009f9d50_Value& kOther);
};

// @fnv 0x009f9d50
S009f9d50_Value& S009f9d50_Value::FUN_009f9d50(const S009f9d50_Value& kOther)
{
    return FUN_009f9c80(kOther);
}

void __stdcall CopyN(unsigned short* dst, const char* src, unsigned int count);

class FNVRefCountedIface
{
  public:
    virtual void __stdcall SlotQueryInterface();
    virtual void __stdcall SlotAddRef();
};

class FNVNameSource
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
    const char* m_pName;
    FNVRefCountedIface* m_pIface;
};

struct FNVNameDest
{
    unsigned short m_pText[0x80];
    unsigned int m_flags;
};

// Copies the name string and interface pointer from pSrc into pDst, adding a reference to the interface when present.
// @fnv 0x009f9df0
long __stdcall FUN_009f9df0(FNVNameSource* pSrc, FNVNameDest* pDst)
{
    if (pDst == 0)
    {
        return 0x80004003;
    }
    if (pSrc->m_pName != 0)
    {
        CopyN(pDst->m_pText, pSrc->m_pName, 0x80);
    }
    else
    {
        pDst->m_pText[0] = 0;
    }
    pDst->m_flags = (unsigned int)pSrc->m_pIface;
    if (pSrc->m_pIface != 0)
    {
        pSrc->m_pIface->SlotAddRef();
    }
    return 0;
}

struct IFilter
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct UnknownBase
{
    virtual ~UnknownBase();
    int unk04;
    int unk08;
};

struct BaseFilter : UnknownBase, IFilter
{
};

struct BasePin
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
    BaseFilter* m_pOwnerFilter;
};

// @fnv 0x009fa310
unsigned long __stdcall ReleaseOwnerFilter(BasePin* pin)
{
    return pin->m_pOwnerFilter->Release();
}

// Sub-object living at +0x34 of the owner; its method is called with `this` in ecx.
struct SubObj
{
    int m_00;
    int FUN_009f9d50(int a);
};

struct FUN_009fa330_cls
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
    SubObj m_34;
    int FUN_009fa330(int a);
};

// Forwards the argument to the member at +0x34 and keeps only a negative result.
// @fnv 0x009fa330
int FUN_009fa330_cls::FUN_009fa330(int a)
{
    int r = m_34.FUN_009f9d50(a);
    return r & ((r >= 0) ? 0 : -1);
}

struct S_009fa400_vtable
{
    void* unk00;
    void(__stdcall* unk04)(int);
};

struct S_009fa400_source
{
    void* unk00;
    int unk04;
    void* unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

struct S_009fa400_output
{
    void* unk00;
    int unk04;
    unsigned short unk08;
};

void __stdcall CopyN(void* dst, void* src, int size);

// Returns an error if output is null; else sets output->unk00 (calling its vtable unk04), unk08 (via CopyN) and unk04 from the source fields.
// @fnv 0x009fa400
int __stdcall FUN_009fa400(S_009fa400_source* source, S_009fa400_output* output)
{
    if (output == 0)
        return 0x80004003;

    output->unk00 = source->unk1c != 0 ? (void*)(source->unk1c + 0x0c) : 0;

    if (source->unk1c != 0)
    {
        S_009fa400_vtable* vtable = *(S_009fa400_vtable**)((char*)source->unk1c + 0x0c);
        vtable->unk04(source->unk1c + 0x0c);
    }

    if (source->unk08 != 0)
    {
        CopyN(&output->unk08, source->unk08, 0x80);
    }
    else
    {
        output->unk08 = 0;
    }

    output->unk04 = source->unk10;
    return 0;
}

struct S_009fa6f0_Foo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    __int64 unk20;
    __int64 unk28;
};

// Stores *pTime, and *pDuration if given, in obj and sets or clears the matching flag bits in unk04; a null pTime only clears them.
// @fnv 0x009fa6f0
int __stdcall FUN_009fa6f0(S_009fa6f0_Foo* obj, __int64* pTime, __int64* pDuration)
{
    if (pTime == 0)
    {
        obj->unk04 &= 0xfffffeef;
        return 0;
    }

    if (pDuration == 0)
    {
        obj->unk20 = *pTime;
        obj->unk04 &= 0xfffffeff;
        obj->unk04 |= 0x10;
        return 0;
    }

    obj->unk20 = *pTime;
    obj->unk28 = *pDuration;
    obj->unk04 |= 0x110;
    return 0;
}

struct FUN_009fa7a0_rec
{
    int unk00;
    unsigned int m_flags04;
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
    int m_30;
    int m_34;
    int m_38;
};
struct SrcRec
{
    int m_00;
    int m_04;
};
// Stores src fields into m_30/m_34, computes m_38 as pValue minus src->m_00, sets flag 0x20, or clears flag 0x20 if src is null.
// @fnv 0x009fa7a0
int __stdcall FUN_009fa7a0(FUN_009fa7a0_rec* self, SrcRec* src, int* pValue)
{
    if (src == 0)
    {
        self->m_flags04 &= 0xffffffdfu;
        return 0;
    }
    self->m_30 = src->m_00;
    self->m_34 = src->m_04;
    self->m_38 = *pValue - src->m_00;
    self->m_flags04 |= 0x20;
    return 0;
}

struct S_009fa910_Foo
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
};

int __stdcall FUN_009f9cb0(int a);

// @fnv 0x009fa910
int __stdcall FUN_009fa910(S_009fa910_Foo* obj, int value)
{
    if (obj->unk3c != 0)
    {
        FUN_009f9cb0(obj->unk3c);
        obj->unk3c = 0;
    }

    if (value == 0)
    {
        obj->unk04 &= 0xfffffff7;
        return 0;
    }

    obj->unk3c = FUN_009f9cd0(value);
    if (obj->unk3c == 0)
    {
        obj->unk04 &= 0xfffffff7;
        return 0x8007000e;
    }

    obj->unk04 |= 8;
    return 0;
}

struct MediaSample
{
    int unk00;
    unsigned int dwSampleFlags;
    unsigned int dwTypeSpecificFlags;
    void* pbBuffer;
    int lActual;
    int cbBuffer;
    unsigned int unk18;
    unsigned int unk1C;
    __int64 tStart;
    __int64 tStop;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    void* pMediaType;
    unsigned int dwStreamId;
};

struct SampleProperties
{
    unsigned int cbData;
    unsigned int dwTypeSpecificFlags;
    unsigned int dwSampleFlags;
    int lActual;
    __int64 tStart;
    __int64 tStop;
    unsigned int dwStreamId;
    void* pMediaType;
    void* pbBuffer;
    int cbBuffer;
};

extern "C" void* __cdecl memmove(void* dst, const void* src, unsigned int n);

// Copies a subset of MediaSample fields into a SampleProperties struct at pDest, clearing the 0x20 sample flag and zeroing pMediaType when the 0x8 flag is unset.
// @fnv 0x009fa960
long __stdcall CopySampleProperties(MediaSample* pSample, unsigned int cb, void* pDest)
{
    void* dest = pDest;
    SampleProperties props;
    unsigned int n;

    if (cb != 0)
    {
        if (dest == 0)
            return (long)0x80004003;

        props.cbData = cb < sizeof(SampleProperties) ? cb : sizeof(SampleProperties);
        n = props.cbData;

        unsigned int flags = pSample->dwSampleFlags;

        props.dwSampleFlags = flags & ~0x20u;
        props.dwTypeSpecificFlags = pSample->dwTypeSpecificFlags;
        props.pbBuffer = pSample->pbBuffer;
        props.cbBuffer = pSample->cbBuffer;
        props.lActual = pSample->lActual;
        props.tStart = pSample->tStart;
        props.tStop = pSample->tStop;
        props.dwStreamId = pSample->dwStreamId;
        props.cbData = n;

        if (flags & 8u)
            props.pMediaType = pSample->pMediaType;
        else
            props.pMediaType = 0;

        memmove(dest, &props, n);
    }
    return 0;
}

struct MediaTypeSI;
MediaTypeSI* __stdcall FUN_009f9cd0(MediaTypeSI* a);
void __stdcall FUN_009f9cb0(MediaTypeSI*);

// AM_SAMPLE2_PROPERTIES
struct SampleProps
{
    unsigned int cbData;
    unsigned int dwTypeSpecificFlags;
    unsigned int dwSampleFlags;
    long lActual;
    __int64 tStart;
    __int64 tStop;
    unsigned int dwStreamId;
    MediaTypeSI* pMediaType;
    int pbBuffer;
    long cbBuffer;
};

// CMediaSample
struct MediaSampleSI
{
    void* vtbl;
    unsigned int m_dwSampleFlags;
    unsigned int m_dwTypeSpecificFlags;
    int m_pBuffer;
    long m_lActual;
    long m_lBufferSize;
    int unk18;
    int unk1c;
    __int64 m_Start;
    __int64 m_End;
    int unk30;
    int unk34;
    int unk38;
    MediaTypeSI* m_pMediaType;
    unsigned int m_dwStreamId;
    long __stdcall FUN_009faa20(unsigned int cbProperties, const unsigned char* pbProperties);
};

// Validates and copies sample properties from pbProperties into this MediaSampleSI, updating flags, times, stream id, and media type.
// @fnv 0x009faa20
long __stdcall MediaSampleSI::FUN_009faa20(unsigned int cbProperties, const unsigned char* pbProperties)
{
    MediaTypeSI* pMediaType = 0;

    if (cbProperties >= 4)
    {
        if (pbProperties == 0)
            return 0x80004003L;
        const SampleProps* pProps = (const SampleProps*)pbProperties;

        if (pProps->cbData < cbProperties)
            cbProperties = pProps->cbData;
        if (cbProperties > sizeof(*pProps) || pProps->cbData > sizeof(*pProps))
            return 0x80070057L;

        if (cbProperties >= 0xc)
        {
            if (pProps->dwSampleFlags & 0xfffffe20)
                return 0x80070057L;
            if ((pProps->dwSampleFlags & 0x10) && !(this->m_dwSampleFlags & 0x10) && !(cbProperties >= 0x20))
                return 0x80070057L;
        }
        if (cbProperties >= 0x2c)
        {
            if (pProps->pbBuffer != 0 && pProps->pbBuffer != this->m_pBuffer)
                return 0x80070057L;
        }
        if (cbProperties >= 0x30)
        {
            if (pProps->cbBuffer != 0 && pProps->cbBuffer != this->m_lBufferSize)
                return 0x80070057L;
        }
        if (cbProperties >= 0x30 && cbProperties >= 0x10)
        {
            if (pProps->cbBuffer < pProps->lActual)
                return 0x80070057L;
        }
        if (cbProperties >= 0x28)
        {
            if (pProps->dwSampleFlags & 8)
            {
                if (pProps->pMediaType == 0)
                    return 0x80004003L;
                pMediaType = FUN_009f9cd0(pProps->pMediaType);
                if (pMediaType == 0)
                    return 0x8007000eL;
            }
        }

        if (cbProperties >= 0x24)
            this->m_dwStreamId = pProps->dwStreamId;
        if (cbProperties >= 0xc)
        {
            this->m_dwSampleFlags = pProps->dwSampleFlags | (this->m_dwSampleFlags & 0x20);
            this->m_dwTypeSpecificFlags = pProps->dwTypeSpecificFlags;
        }
        else
        {
            if (cbProperties >= 8)
                this->m_dwTypeSpecificFlags = pProps->dwTypeSpecificFlags;
        }
        if (cbProperties >= 0x10)
            this->m_lActual = pProps->lActual;
        if (cbProperties >= 0x20)
        {
            this->m_End = pProps->tStop;
        }
        if (cbProperties >= 0x18)
        {
            this->m_Start = pProps->tStart;
        }
        if (cbProperties >= 0x28)
        {
            if (pProps->dwSampleFlags & 8)
            {
                if (this->m_pMediaType != 0)
                    FUN_009f9cb0(this->m_pMediaType);
                this->m_pMediaType = pMediaType;
            }
        }
        if (this->m_pMediaType)
            this->m_dwSampleFlags |= 8;
        else
            this->m_dwSampleFlags &= ~8u;
    }
    return 0;
}

struct FUN_009fae30_Rec
{
    int unk00;
    void* m_cs;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int m_20;
    int unk24;
    int unk28;
    int m_2c;
    int m_30;
};
// Under the critical section at r->m_cs, stores m_2c - m_30 + m_20 into *out and returns 0.
// @fnv 0x009fae30
int __stdcall FUN_009fae30(FUN_009fae30_Rec* r, int* out)
{
    void* pLock = ((char*)r - 0xc) ? (void*)&r->m_cs : 0;
    EnterCriticalSection(pLock);
    *out = r->m_2c - r->m_30 + r->m_20;
    LeaveCriticalSection(pLock);
    return 0;
}

struct Obj;
struct Tab
{
    void* query;
    void* addref;
    unsigned long(__stdcall* release)(Obj*);
};
struct Obj
{
    Tab* table;
};
// @fnv 0x009fb270
unsigned long __stdcall FUN_009fb270(Obj** p)
{
    Obj* q = p[-2];
    return q->table->release(q);
}

namespace fnv_009fb290 {
struct Vector4f
{
    int x;
    int y;
    int z;
    int w;
};
struct LinkPair
{
    const Vector4f* first;
    const Vector4f* second;
};
struct Record
{
    int type;
    int group;
    int property;
    int setting;
    int flags;
    const Vector4f* attachment;
    int attachmentKind;
    unsigned int linkCount;
    const LinkPair* links;
};
struct RecordSet
{
    const Vector4f* root;
    int category;
    int version;
    unsigned int recordCount;
    const Record* records;
};
struct RecordWriter
{
    virtual int __stdcall QueryInterface() = 0;
    virtual int __stdcall AddRef() = 0;
    virtual int __stdcall Release() = 0;
    virtual int __stdcall BeginSet(Vector4f header, int category, int version) = 0;
    virtual int __stdcall FinishSet() = 0;
    virtual int __stdcall WriteRecord(Vector4f header, int type, int group, int property, int setting, int flags,
                                      Vector4f attachment, int attachmentKind) = 0;
    virtual int __stdcall WriteLink(Vector4f header, int type, Vector4f first, Vector4f second) = 0;
    virtual int __stdcall WriteHeader(Vector4f header) = 0;
};
// @fnv 0x009fb290
int __stdcall WriteRecordSet(const RecordSet* source, RecordWriter* writer, int includeRecords)
{
    if (source == 0)
        return 1;
    int result = writer->WriteHeader(*source->root);
    if (includeRecords)
    {
        result = writer->BeginSet(*source->root, source->category, source->version);
        if (result >= 0)
        {
            for (unsigned int i = 0; i < source->recordCount; ++i)
            {

                result = writer->WriteRecord(*source->root, source->records[i].type, source->records[i].group,
                                             source->records[i].property, source->records[i].setting,
                                             source->records[i].flags, *source->records[i].attachment,
                                             source->records[i].attachmentKind);
                if (result < 0)
                    break;
                for (unsigned int j = 0; j < source->records[i].linkCount; ++j)
                {

                    result = writer->WriteLink(*source->root, source->records[i].type,
                                               *source->records[i].links[j].first, *source->records[i].links[j].second);
                    if (result < 0)
                        break;
                }
                if (result < 0)
                    break;
            }
        }
    }
    return result == (int)0x80070002 ? 0 : result;
}
}  // namespace fnv_009fb290

struct MediaEnumCount
{
    int unk00;
    ~MediaEnumCount()
    {
        FUN_009fce80((int)this);
    }
};

struct MediaEnumPin
{
    virtual long __stdcall QueryInterface(const void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

class FUN_009fb550
{
  public:
    int unk00;
    MediaEnumCount m_uiItemCount;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    MediaEnumPin* m_pin;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    void* m_mediaTypes;
    ~FUN_009fb550();
};

// Frees m_mediaTypes and releases m_pin if it is set.
// @fnv 0x009fb550
FUN_009fb550::~FUN_009fb550()
{
    operator delete(m_mediaTypes);
    if (m_pin)
    {
        m_pin->Release();
        m_pin = 0;
    }
}

struct FindCritSec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void Lock()
    {
        EnterCriticalSection(this);
    }
    void Unlock()
    {
        LeaveCriticalSection(this);
    }
};
struct FindGuard
{
    FindCritSec* m_pLock;
    FindGuard(FindCritSec* p) : m_pLock(p)
    {
        m_pLock->Lock();
    }
    ~FindGuard()
    {
        m_pLock->Unlock();
    }
};
struct FindPinIface
{
    virtual long __stdcall QueryInterface(void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall FindPin(const wchar_t* id, PinIface** result);
};
struct FindPinObject : AllocUnknown, PinIface
{
    int unk10;
    const wchar_t* m_Name;
    const wchar_t* Name()
    {
        return m_Name;
    }
};
struct FilterUnknown
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual int GetPinCount();
    virtual FindPinObject* GetPin(int index);
    int unk04;
    int unk08;
};
struct FindFilter : FilterUnknown, FindPinIface
{
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
    FindCritSec* m_pLock;
    long __stdcall FindPin(const wchar_t* id, PinIface** result);
};
int __stdcall CompareWideStrings(const wchar_t* a, const wchar_t* b);
// @fnv 0x009fb960
long __stdcall FindFilter::FindPin(const wchar_t* apPinName, PinIface** result)
{
    if (result == 0)
        return 0x80004003;
    FindGuard lock(m_pLock);
    int count = GetPinCount();
    for (int i = 0; i < count; i++)
    {
        FindPinObject* pin = GetPin(i);
        if (CompareWideStrings(pin->Name(), apPinName) == 0)
        {
            *result = (PinIface*)pin;
            (*result)->AddRef();
            return 0;
        }
    }
    *result = 0;
    return 0x80040216;
}

namespace fnv_009fbb50 {
int __stdcall InitFromInterface(int a);

struct IPin9FB
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

struct Pin9FB
{
    int unk00;
    int unk04;
    int unk08;
    IPin9FB m_iPin;
};

struct Filter9FB
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual int GetPinVersion();
    virtual void v18();
    virtual Pin9FB* GetPin(int n);
};

struct List9FB
{
    int m_pFirst;
    int Find(void* pObj) const;
    int AddNode(int pObj);
};

struct EnumPins9FB
{
    int unk00;
    int m_uiReferenceCount;
    int m_PinCount;
    Filter9FB* m_pOwnerFilter;
    int m_iCurrentPinIndex;
    int unk14;
    List9FB m_Pins;
};

// Enumerates up to cPins pins from the owner filter, storing their IPin9FB pointers in ppPins and the fetched count in pcFetched.
// @fnv 0x009fbb50
int __stdcall FUN_009fbb50(EnumPins9FB* self, unsigned long cPins, IPin9FB** ppPins, unsigned long* pcFetched)
{
    if (ppPins == 0)
    {
        return (int)0x80004003;
    }
    if (pcFetched != 0)
    {
        *pcFetched = 0;
    }
    else if (cPins > 1)
    {
        return (int)0x80070057;
    }
    unsigned long nFetched = 0;
    if (self->m_pOwnerFilter->GetPinVersion() != self->m_iCurrentPinIndex)
    {
        InitFromInterface((int)self);
    }
    int n = self->m_PinCount - self->m_uiReferenceCount;
    if (n >= (int)cPins)
    {
        n = (int)cPins;
    }
    if (n == 0)
    {
        return n + 1;
    }
    do
    {
        if (self->m_PinCount - self->m_uiReferenceCount == 0)
        {
            break;
        }
        Pin9FB* pin = self->m_pOwnerFilter->GetPin(self->m_uiReferenceCount++);
        if (pin == 0)
        {
            return (int)0x80040203;
        }
        if (self->m_Pins.Find(pin) == 0)
        {
            *ppPins = &pin->m_iPin;
            pin->m_iPin.AddRef();
            nFetched = nFetched + 1;
            ++ppPins;
            self->m_Pins.AddNode((int)pin);
            n = n - 1;
        }
    } while (n != 0);
    if (pcFetched != 0)
    {
        *pcFetched = nFetched;
    }
    return cPins != nFetched;
}
}  // namespace fnv_009fbb50

struct MediaGuid
{
    unsigned long data1;
    unsigned short data2, data3;
    unsigned char data4[8];
};
struct EnumMediaType
{
    MediaGuid majorType;
    MediaGuid subType;
    int fixedSizeSamples;
    int temporalCompression;
    unsigned long sampleSize;
    MediaGuid formatType;
    void* owner;
    unsigned int formatSize;
    void* format;
    void FUN_009f9c70();
    void FUN_009f9c60();
    EnumMediaType()
    {
        FUN_009f9c70();
    }
    ~EnumMediaType()
    {
        FUN_009f9c60();
    }
};
struct EnumMediaSource
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual int version();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual long getType(int index, EnumMediaType* type);
};
struct MediaEnumerator
{
    void* unk00;
    int position;
    EnumMediaSource* source;
    int version;
};
extern void*(__stdcall* DAT_00fdf460)(unsigned int);

// Retrieves up to count media types from the source at the current position, allocating each and reporting the number fetched.
// @fnv 0x009fbcc0
int __stdcall GetMediaTypes(MediaEnumerator* self, unsigned long count, EnumMediaType** types, unsigned long* fetched)
{
    if (!types)
        return 0x80004003;
    if (self->source->version() != self->version)
        return 0x80040203;
    if (fetched)
        *fetched = 0;
    else if (count > 1)
        return 0x80070057;
    unsigned long done = 0;
    while (count)
    {
        EnumMediaType type;
        long result = self->source->getType(self->position++, &type);
        if (result != 0)
            break;
        *types = (EnumMediaType*)DAT_00fdf460(sizeof(EnumMediaType));
        if (!*types)
            break;
        **types = type;
        type.format = 0;
        type.formatSize = 0;
        type.owner = 0;
        ++types;
        done += 1;
        count -= 1;
    }
    if (fetched)
        *fetched = done;
    return count != 0;
}

struct MediaTypeTry
{
    int FUN_009f9a80(MediaTypeTry* partial);
};
struct EnumMediaTry
{
    virtual long __stdcall QueryInterface(void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall Next(unsigned long count, MediaTypeTry** media, unsigned long* fetched);
    virtual long __stdcall Skip(unsigned long count);
    virtual long __stdcall Reset();
};
void __stdcall FUN_009f9cb0(MediaTypeTry* media);
struct PinTry
{
    long FUN_009fbf00(void* receiver, MediaTypeTry* media);
    long FUN_009fbfc0(void* receiver, MediaTypeTry* partial, EnumMediaTry* enumerator);
};
// @fnv 0x009fbfc0
long PinTry::FUN_009fbfc0(void* receiver, MediaTypeTry* partial, EnumMediaTry* enumerator)
{
    long hr = enumerator->Reset();
    if (hr < 0)
        return hr;
    MediaTypeTry* media = 0;
    unsigned long fetched = 0;
    long failure = 0;
    for (;;)
    {
        if (enumerator->Next(1, &media, &fetched) != 0)
            break;
        long hr;
        if (partial && !media->FUN_009f9a80(partial))
        {
            hr = 0x80040207;
        }
        else
        {
            hr = FUN_009fbf00(receiver, media);
            if (hr < 0 && failure >= 0 && hr != (long)0x80004005 && hr != (long)0x80070057 && hr != (long)0x8004022a)
                failure = hr;
        }
        FUN_009f9cb0(media);
        if (hr == 0)
            return hr;
    }
    if (failure == 0)
        failure = 0x80040207;
    return failure;
}

typedef int(__stdcall* FNV_HRESULT_Call2)(void* self, void** out);
typedef unsigned long(__stdcall* FNV_Release_Call)(void* self);

class FNV_Callee9f9a50
{
  public:
    int Call9f9a50();
};

class FNV_Callee9fbf00
{
  public:
    int Call9fbf00(void* arg1, void* arg2);
};

class FNV_Callee9fbfc0
{
  public:
    int Call9fbfc0(void* arg1, void* arg2, void* out);
};

class FUN_009fc0b0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    void* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    unsigned short unk24;
    unsigned char m_26;
    int FUN_009fc0b0(void* arg1, void* arg2);
};

// Returns Call9fbf00(arg1, arg2) if arg2's Call9f9a50() is 0; else tries twice (vtable slot 12 on arg1 or &m_0c, then Call9fbfc0), returning 0 or an HRESULT.
// @fnv 0x009fc0b0
int FUN_009fc0b0_cls::FUN_009fc0b0(void* arg1, void* arg2)
{
    void* out = 0;
    int hr;
    int i;
    void* cur = arg2;

    if (cur != 0)
    {
        if (((FNV_Callee9f9a50*)cur)->Call9f9a50() == 0)
        {
            return ((FNV_Callee9fbf00*)this)->Call9fbf00(arg1, arg2);
        }
    }

    i = 0;
    hr = 0x80040207;
    for (; i < 2; i = i + 1)
    {
        int r;
        cur = arg2;
        if (i == this->m_26)
        {
            r = ((FNV_HRESULT_Call2)(*(void***)arg1)[12])(arg1, &out);
        }
        else
        {
            r = ((FNV_HRESULT_Call2)(*(void***)&this->m_0c)[12])(&this->m_0c, &out);
        }
        if (r < 0)
        {
            goto next;
        }
        {
            int hrResult = ((FNV_Callee9fbfc0*)this)->Call9fbfc0(arg1, arg2, out);
            ((FNV_Release_Call)(*(void***)out)[2])(out);
            if (hrResult >= 0)
            {
                return 0;
            }
            if (hrResult != 0x80004005 && hrResult != 0x80070057 && hrResult != 0x8004022a)
            {
                hr = hrResult;
            }
        }
    next:;
    }
    return hr;
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);

struct DsCritSec
{
    int m_CritSec;
    void Lock()
    {
        EnterCriticalSection(&m_CritSec);
    }
    void Unlock()
    {
        LeaveCriticalSection(&m_CritSec);
    }
};

struct DsAutoLock
{
    DsCritSec* m_pLock;
    DsAutoLock(DsCritSec* plock)
    {
        m_pLock = plock;
        m_pLock->Lock();
    }
    ~DsAutoLock()
    {
        m_pLock->Unlock();
    }
};

struct DsUnknown
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct DsBaseFilter
{
    void* vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_iValueAt14;
};

struct DsPinBase0
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    int unk04;
    int unk08;
};

struct DsIPin : DsUnknown
{
    virtual long __stdcall Connect(DsUnknown* pReceivePin, const void* pmt) = 0;
    virtual long __stdcall FUN_009fc190(DsUnknown* pConnector, const void* pmt) = 0;
};

struct DsIQualityControl
{
    virtual void q00();
};

struct DsBasePin : DsPinBase0, DsIPin, DsIQualityControl
{
    wchar_t* m_pName;
    DsUnknown* m_Connected;
    int m_dir;
    DsCritSec* m_pLock;
    bool m_bRunTimeError;
    bool m_bCanReconnectWhenActive;
    bool m_bTryMyTypesFirst;
    DsBaseFilter* m_pOwnerFilter;

    virtual long CheckMediaType(const void* pmt);
    virtual long SetMediaType(const void* pmt);
    virtual long CheckConnect(DsUnknown* pPin);
    virtual long BreakConnect();
    virtual long CompleteConnect(DsUnknown* pReceivePin);

    bool IsStopped()
    {
        return m_pOwnerFilter->m_iValueAt14 == 0;
    }

    long __stdcall QueryInterface(const void* riid, void** ppv);
    unsigned long __stdcall AddRef();
    unsigned long __stdcall Release();
    long __stdcall Connect(DsUnknown* pReceivePin, const void* pmt);
    long __stdcall FUN_009fc190(DsUnknown* pConnector, const void* pmt);
};

// Connects this pin to pConnector with media type pmt, validating state, checking compatibility, and completing the connection.
// @fnv 0x009fc190
long __stdcall DsBasePin::FUN_009fc190(DsUnknown* pConnector, const void* pmt)
{
    if (pConnector == 0)
        return 0x80004003;
    if (pmt == 0)
        return 0x80004003;
    DsAutoLock cObjectLock(m_pLock);

    if (m_Connected)
    {
        return 0x80040204;
    }

    if (!IsStopped() && !m_bCanReconnectWhenActive)
    {
        return 0x80040224;
    }

    long hr = CheckConnect(pConnector);
    if (hr < 0)
    {
        BreakConnect();
        return hr;
    }

    hr = CheckMediaType(pmt);
    if (hr != 0)
    {
        BreakConnect();
        if (hr >= 0 || hr == (long)0x80004005 || hr == (long)0x80070057)
        {
            hr = 0x8004022a;
        }
        return hr;
    }

    m_Connected = pConnector;
    m_Connected->AddRef();
    hr = SetMediaType(pmt);
    if (hr >= 0)
    {
        hr = CompleteConnect(pConnector);
        if (hr >= 0)
        {
            return 0;
        }
    }

    m_Connected->Release();
    m_Connected = 0;
    BreakConnect();
    return hr;
}

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

inline void* __cdecl operator new(unsigned int, unsigned int size)
{
    return operator new(size);
}

inline void __cdecl operator delete(void* p, unsigned int)
{
    operator delete(p);
}

struct SourceVirtual
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5();
};

struct RecordView
{
    int unknown0;
    int unknown4;
    int unknown8;
    SourceObj* source;
    int value;
};

// @fnv 0x009fc6d0
int __stdcall FUN_009fc6d0(ResultRec* record, FUN_009fc600** result)
{
    if (!result)
        return (int)0x80004003;

    RecordView* data = (RecordView*)record;
    int status = 0;

    if (((SourceVirtual*)data->source)->v5() != data->value)
    {
        *result = 0;
        status = (int)0x80040203;
    }
    else
    {
        FUN_009fc600* object = new (0x30u) FUN_009fc600(data->source, record);
        *result = object;
        if (!object)
            status = (int)0x8007000e;
    }

    return status;
}

// FUN_009fc780: thiscall constructor (owner, source) for a polymorphic record.
// The base part stores the owner, the derived part installs the class vtable,
// then either copies two fields from the source or asks the owner through its
// slot 4 for the value. Returns this.

struct RecTarget
{
    virtual long __stdcall QueryInterface(void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

struct RecOwner
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void* unk10();
    int unk04_field;
    int unk08_field;
    RecTarget m_0c;
};

struct RecSource
{
    int unk00;
    int m_04;
    int unk08;
    void* m_0c;
};

struct RecBase
{
    void* m_ppVirtualMethodTable;
    int m_04;
    RecOwner* m_08;
    void* m_0c;
    int m_10;

    RecBase(RecOwner* owner)
    {
        m_08 = owner;
    }
};

struct FUN_009fc780 : RecBase
{
    FUN_009fc780(RecOwner* owner, RecSource* src);
};

// @fnv 0x009fc780
FUN_009fc780::FUN_009fc780(RecOwner* owner, RecSource* src) : RecBase(owner)
{
    m_ppVirtualMethodTable = DAT_01093c74;
    m_04 = 0;
    m_10 = 1;
    owner->m_0c.AddRef();
    if (src == 0)
    {
        m_0c = m_08->unk10();
    }
    else
    {
        m_04 = src->m_04;
        m_0c = src->m_0c;
    }
}

namespace fnv_009fc7e0 {
struct CBasePin_9fc7e0
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual long GetMediaTypeVersion();
};

struct FUN_009fc780
{
    virtual void v00();
    int m_uiReferenceCount;
    CBasePin_9fc7e0* m_pPin;
    long m_iCurrentPinIndex;
    long m_lRefCount;

    FUN_009fc780(CBasePin_9fc7e0* pPin, FUN_009fc780* pEnumMediaTypes);
    long __stdcall FUN_009fc7e0(FUN_009fc780** ppEnum);
};

// Stores a new FUN_009fc780 built from m_pPin and this in *ppEnum if the pin's version equals m_iCurrentPinIndex; otherwise sets it null and returns an error.
// @fnv 0x009fc7e0
long __stdcall FUN_009fc780::FUN_009fc7e0(FUN_009fc780** ppEnumMediaTypes)
{
    if (ppEnumMediaTypes == 0)
        return 0x80004003;
    long hr = 0;
    if (m_pPin->GetMediaTypeVersion() != m_iCurrentPinIndex)
    {
        *ppEnumMediaTypes = 0;
        hr = 0x80040203;
    }
    else
    {
        *ppEnumMediaTypes = new FUN_009fc780(m_pPin, this);
        if (*ppEnumMediaTypes == 0)
            hr = 0x8007000e;
    }
    return hr;
}
}  // namespace fnv_009fc7e0

extern "C" void* __cdecl FUN_00ec44d0(void*, const void*, unsigned int);
void* __cdecl operator new(unsigned int);
int __stdcall FUN_009fd080(const wchar_t*);

struct FUN_009fcee0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    FUN_009fcee0(int name, int outer);
    ~FUN_009fcee0();
};
struct FUN_009f9c70
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
    FUN_009f9c70();
    ~FUN_009f9c70();
};
struct FUN_009fc890 : FUN_009fcee0
{
    wchar_t* m_pName;
    void* m_Connected;
    int m_dir;
    int* m_pLock;
    bool m_bRunTimeError;
    bool m_bCanReconnectWhenActive;
    bool m_bTryMyTypesFirst;
    char unk27;
    void* m_pOwnerFilter;
    void* m_pQSink;
    int m_TypeVersion;
    FUN_009f9c70 m_mt;
    __int64 m_tStart;
    __int64 m_tStop;
    volatile double m_dRate;
    FUN_009fc890(int objectName, void* filter, int* lock, int* phr, const wchar_t* name, int dir);
};
// Initializes members from the arguments, copies name into a new wchar_t array, and sets m_tStart to 0, m_tStop to the maximum and m_dRate to 1.0.
// @fnv 0x009fc890
FUN_009fc890::FUN_009fc890(int objectName, void* apOwnerFilter, int* lock, int* phr, const wchar_t* name, int dir)
    : FUN_009fcee0(objectName, 0), m_pName(0), m_Connected(0), m_dir(dir), m_pLock(lock), m_bRunTimeError(false),
      m_bCanReconnectWhenActive(false), m_bTryMyTypesFirst(false), m_pOwnerFilter(apOwnerFilter), m_pQSink(0),
      m_TypeVersion(1)
{
    m_tStart = 0;
    m_tStop = 0x7fffffffffffffffLL;
    m_dRate = 1.0;
    if (name)
    {
        int len = FUN_009fd080(name) + 1;
        m_pName = new wchar_t[len];
        if (m_pName)
        {
            FUN_00ec44d0(m_pName, name, len * sizeof(wchar_t));
        }
    }
}

class FUN_009fcab0_obj
{
  public:
    FUN_009fcab0_obj(char* p, int flag);
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
};

// @fnv 0x009fcab0
int __stdcall FUN_009fcab0(char* a, FUN_009fcab0_obj** out)
{
    if (out == 0)
    {
        return 0x80004003;
    }
    *out = new FUN_009fcab0_obj(a - 0xc, 0);
    return *out != 0 ? 0 : 0x8007000e;
}

struct S9fcc60_RawCS
{
    int DebugInfo;
    int LockCount;
    int RecursionCount;
    int OwningThread;
    int LockSemaphore;
    int SpinCount;
};

struct S9fcc60_CritSec
{
    S9fcc60_RawCS m_CritSec;
    void Lock()
    {
        EnterCriticalSection(&m_CritSec);
    }
    void Unlock()
    {
        LeaveCriticalSection(&m_CritSec);
    }
};

class S9fcc60_AutoLock
{
  protected:
    S9fcc60_CritSec* m_pLock;

  public:
    S9fcc60_AutoLock(S9fcc60_CritSec* plock)
    {
        m_pLock = plock;
        m_pLock->Lock();
    }
    ~S9fcc60_AutoLock()
    {
        m_pLock->Unlock();
    }
};

struct S9fcc60_Head
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct S9fcc60_Sample;

struct S9fcc60_Alloc : S9fcc60_Head, S9fcc60_CritSec
{
    S9fcc60_Sample* m_lFree;
    int m_lFreeCount;
    int unk30;
    int unk34;
    int m_lCount;
    int m_lAllocated;
    int m_lSize;
    int m_lAlignment;
    int m_lPrefix;
    int m_bChanged;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    unsigned char* m_pBuffer;
    int FUN_009fcc60();
};

struct S9fcc60_Sample
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    S9fcc60_Sample* m_pNext;
    __declspec(nothrow) S9fcc60_Sample* FUN_009fcb50(char* name, S9fcc60_Alloc* alloc, int* phr, unsigned char* buf,
                                                     int len);
};

struct S9fcc60_Base
{
    int FUN_009fb020();
    __declspec(nothrow) void FUN_009fb170();
};

__declspec(nothrow) void* __cdecl FormHeap_Allocate(unsigned int size);
extern "C" __declspec(dllimport) __declspec(nothrow) void* __stdcall VirtualAlloc(void* address, unsigned int size,
                                                                                  unsigned int allocationType,
                                                                                  unsigned int protect);

// Locks the allocator, computes aligned block size, allocates a buffer via VirtualAlloc, and builds the free list of sample blocks.
// @fnv 0x009fcc60
int S9fcc60_Alloc::FUN_009fcc60()
{
    S9fcc60_AutoLock lck(this);

    int res = ((S9fcc60_Base*)this)->FUN_009fb020();
    if (res < 0)
    {
        return res;
    }
    if (res == 1)
    {
        return 0;
    }
    if (m_pBuffer)
    {
        ((S9fcc60_Base*)this)->FUN_009fb170();
    }

    int lAlignedSize = m_lSize + m_lPrefix;
    if (m_lAlignment > 1)
    {
        int lRemainder = lAlignedSize % m_lAlignment;
        if (lRemainder != 0)
        {
            lAlignedSize += m_lAlignment - lRemainder;
        }
    }

    if ((m_pBuffer = (unsigned char*)VirtualAlloc(0, m_lCount * lAlignedSize, 0x1000, 4)) == 0)
    {
        return 0x8007000e;
    }

    unsigned char* pBlock = m_pBuffer;
    S9fcc60_Sample* pSample;
    for (; m_lAllocated < m_lCount; m_lAllocated++, pBlock += lAlignedSize)
    {
        int hr;
        S9fcc60_Sample* mem = (S9fcc60_Sample*)FormHeap_Allocate(0x48);
        pSample = mem ? mem->FUN_009fcb50(0, this, &hr, pBlock + m_lPrefix, m_lSize) : 0;
        if (pSample == 0)
        {
            return 0x8007000e;
        }
        pSample->m_pNext = m_lFree;
        m_lFree = pSample;
        m_lFreeCount++;
    }
    m_bChanged = 0;
    return 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plValue);

struct RefCounted
{
    int unk00[2];
    unsigned long m_uiRefCount;
};

// @fnv 0x009fcf60
unsigned long __stdcall FUN_009fcf60(RefCounted* pkObject)
{
    InterlockedIncrement((long volatile*)&pkObject->m_uiRefCount);
    return pkObject->m_uiRefCount > 1 ? pkObject->m_uiRefCount : 1;
}

class FUN_009fcf80_cls
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual ~FUN_009fcf80_cls();
    unsigned int unk04;
    volatile long m_lRefCount;
};
// Decrements m_lRefCount; deletes self when it reaches zero, otherwise returns the remaining reference count clamped to a minimum of 1.
// @fnv 0x009fcf80
unsigned int __stdcall FUN_009fcf80(FUN_009fcf80_cls* self)
{
    if (InterlockedDecrement(&self->m_lRefCount) == 0)
    {
        self->m_lRefCount = self->m_lRefCount + 1;
        delete self;
        return 0;
    }
    unsigned int c = self->m_lRefCount;
    unsigned int r = c > 1 ? c : 1;
    return r;
}

// Copies src to dest, stopping at the terminator or after count-1 characters and always null-terminating when count is nonzero; returns dest.
// @fnv 0x009fcff0
wchar_t* __stdcall CopyN(wchar_t* dest, const wchar_t* src, unsigned int count)
{
    wchar_t* ret = dest;
    if (count)
    {
        do
        {
            if (--count == 0)
            {
                *dest = 0;
                break;
            }
        } while ((*dest++ = *src++) != 0);
    }
    return ret;
}

namespace fnv_009fd030 {
// Performs a lexicographic comparison of two null-terminated wide strings, returning the difference of the first differing characters or zero if equal.
// @fnv 0x009fd030
int __stdcall CompareWideStrings(const wchar_t* p, const wchar_t* q)
{
    do
    {
        wchar_t c1 = *p, c2 = *q;
        if (c1 != c2)
            return c1 - c2;
    } while (*p++ && *q++);
    return 0;
}
}  // namespace fnv_009fd030

extern "C" __declspec(dllimport) void* __stdcall CoTaskMemAlloc(unsigned long cb);
extern "C" void* __cdecl memcpy(void* dst, const void* src, unsigned int size);
int __stdcall FUN_009fd080(const wchar_t* psz);

// Allocates a CoTaskMemAlloc'd copy of psz, writes the pointer to ppszReturn, and returns HRESULT.
// @fnv 0x009fd0a0
long __stdcall FUN_009fd0a0(const wchar_t* psz, wchar_t** ppszReturn)
{
    if (ppszReturn == 0)
        return 0x80004003L;
    unsigned long nameLen = sizeof(wchar_t) * (FUN_009fd080(psz) + 1);
    wchar_t* p = (wchar_t*)CoTaskMemAlloc(nameLen);
    int bAllocFailed;
    try
    {
        bAllocFailed = (p == 0);
    }
    catch (...)
    {
        throw;
    }
    *ppszReturn = p;
    if (bAllocFailed)
        return 0x8007000EL;
    memcpy(p, psz, nameLen);
    return 0;
}

struct FUN_009fd200_node
{
    FUN_009fd200_node* prev;
    FUN_009fd200_node* next;
    unsigned int unk08;
};
struct FUN_009fd200_list
{
    FUN_009fd200_node* head;
    FUN_009fd200_node* tail;
    int count;
    int limit;
    int freeCount;
    FUN_009fd200_node* freeHead;
};
void __cdecl FormHeap_Free(void* p);
class FUN_009fd200_cls
{
  public:
    unsigned int RemoveNode(FUN_009fd200_node* node);
};
// Unlinks node from the list, returns its unk08, and either pushes it onto the free list or frees it when freeCount is at limit.
// @fnv 0x009fd200
unsigned int FUN_009fd200_cls::RemoveNode(FUN_009fd200_node* node)
{
    if (node == 0)
    {
        return reinterpret_cast<unsigned int>(node);
    }
    FUN_009fd200_list* list = reinterpret_cast<FUN_009fd200_list*>(this);
    {
        if (node->prev == 0)
        {
            list->head = node->next;
        }
        else
        {
            node->prev->next = node->next;
        }
        if (node->next == 0)
        {
            list->tail = node->prev;
        }
        else
        {
            node->next->prev = node->prev;
        }
        unsigned int result = node->unk08;
        if (list->freeCount < list->limit)
        {
            node->next = list->freeHead;
            list->freeCount = list->freeCount + 1u;
            list->freeHead = node;
        }
        else
        {
            FormHeap_Free(node);
        }
        int* pCount = &list->count;
        *pCount -= 1;
        return result;
    }
}

struct Node9FD320
{
    int unk00;
    int unk04;
    FUN_009fd100_node* m_kNode;

    ~Node9FD320()
    {
        FUN_009fd100_node* node = m_kNode;
        while (node != 0)
        {
            FUN_009fd100_node* cur = node;
            node = node->next;
            operator delete(cur);
        }
    }
};

class FUN_009fd320
{
  public:
    FUN_009fd140_class m_uiBufferCapacity;
    Node9FD320 m_kNodePool;

    ~FUN_009fd320();
};

// Destructor: calls ClearList on m_uiBufferCapacity; m_kNodePool's destructor then deletes its node chain.
// @fnv 0x009fd320
FUN_009fd320::~FUN_009fd320()
{
    m_uiBufferCapacity.ClearList();
}

// Stand-in declarations for the objects used by FUN_009fd3a0.
struct CalleeObj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual int v04();
};

struct HolderObj
{
    virtual void v00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    CalleeObj* m_pEntryObject;  // +0x18
    int FUN_009fd3a0(int aMask);
};

// @fnv 0x009fd3a0
int HolderObj::FUN_009fd3a0(int aMask)
{
    return !((m_pEntryObject->v04() - 1) & aMask);
}

struct IUnknownFD4
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObject);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

struct AggregateFD4
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    IUnknownFD4* m_pOuter;
};

// @fnv 0x009fd430
unsigned long __stdcall FUN_009fd430(AggregateFD4* pThis)
{
    return pThis->m_pOuter->Release();
}

struct IID9FD5A0
{
    unsigned long d1;
    unsigned short d2;
    unsigned short d3;
    unsigned char d4[8];
};
extern const IID9FD5A0 DAT_01093bbc;

struct Base9FD5A0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual ~Base9FD5A0();
    int unk04;
    int unk08;
};
struct Iface9FD5A0
{
    virtual long __stdcall QueryInterface(const IID9FD5A0& riid, void** ppv);
};
struct Obj9FD5A0 : Base9FD5A0, Iface9FD5A0
{
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
    Obj9FD5A0(int a, int b, long* phr);
};

// Allocates an Obj9FD5A0, queries it for the DAT_01093bbc interface into ppv, and returns the HRESULT.
// @fnv 0x009fd5a0
long __stdcall FUN_009fd5a0(void** ppv)
{
    if (ppv == 0)
        return 0x80004003;
    long hr = 0;
    *ppv = 0;
    Obj9FD5A0* p = new Obj9FD5A0(0, 0, &hr);
    if (p == 0)
        return 0x8007000e;
    if (hr < 0)
    {
        delete p;
        return hr;
    }
    hr = static_cast<Iface9FD5A0*>(p)->QueryInterface(DAT_01093bbc, ppv);
    if (hr < 0)
    {
        delete p;
        return 0x80004002;
    }
    return 0;
}

struct ALLOCATOR_PROPERTIES
{
    long cBuffers;
    long cbBuffer;
    long cbAlign;
    long cbPrefix;
};
struct IMemAllocator
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall SetProperties(ALLOCATOR_PROPERTIES* pRequest, ALLOCATOR_PROPERTIES* pActual) = 0;
};
struct AlignmentDevice
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual long GetAlignment();
};
struct AllocatorStream
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    AlignmentDevice* pDevice;
    int __thiscall FUN_009fd3a0(long alAlign);
    void __thiscall GetValue(long* aplAlign);
    int IsAligned(long align)
    {
        return !(align & (pDevice->GetAlignment() - 1));
    }
};
struct AllocatorPin
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
    AllocatorStream* pStream;
    long __thiscall FUN_009fd5a0(IMemAllocator** appAllocator);
    long __stdcall FUN_009fd6d0(IMemAllocator* apAllocator, ALLOCATOR_PROPERTIES* apRequest,
                                IMemAllocator** appAllocator);
};
// Sets allocator properties on apAllocator or a fallback allocator, ensuring stream alignment, and stores the chosen allocator in appAllocator.
// @fnv 0x009fd6d0
long __stdcall AllocatorPin::FUN_009fd6d0(IMemAllocator* apAllocator, ALLOCATOR_PROPERTIES* apRequest,
                                          IMemAllocator** appAllocator)
{
    if (!apAllocator)
        return 0x80004003;
    if (!apRequest)
        return 0x80004003;
    if (!appAllocator)
        return 0x80004003;
    if (!apRequest->cbAlign || !pStream->IsAligned(apRequest->cbAlign))
        pStream->GetValue(&apRequest->cbAlign);
    ALLOCATOR_PROPERTIES kActual;
    if (apAllocator->SetProperties(apRequest, &kActual) >= 0 && pStream->FUN_009fd3a0(kActual.cbAlign))
    {
        apAllocator->AddRef();
        *appAllocator = apAllocator;
        return 0;
    }
    IMemAllocator* fallback;
    long hr = FUN_009fd5a0(&fallback);
    if (hr < 0)
        return hr;
    hr = fallback->SetProperties(apRequest, &kActual);
    if (hr >= 0 && pStream->FUN_009fd3a0(kActual.cbAlign))
    {
        *appAllocator = fallback;
        return 0;
    }
    fallback->Release();
    if (hr >= 0)
        hr = 0x8004020e;
    return hr;
}

// CAsyncOutputPin::Request (DirectShow async reader sample)
typedef __int64 LONGLONG;
typedef LONGLONG REFERENCE_TIME;

struct AsyncSample
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall GetPointer(unsigned char** ppBuffer);
    virtual long __stdcall GetSize();
    virtual long __stdcall GetTime(REFERENCE_TIME* pStart, REFERENCE_TIME* pEnd);
    virtual long __stdcall SetTime(REFERENCE_TIME* pStart, REFERENCE_TIME* pEnd);
};

struct AsyncIo
{
    long Length(LONGLONG* pllTotal, LONGLONG* pllAvailable);
    long Alignment(long* pAlignment);
    long Request(LONGLONG llPos, long lLength, int bAligned, unsigned char* pBuffer, void* pContext,
                 unsigned long dwUser);
};

struct AsyncOutputPin
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
    AsyncIo* m_pIo;
};

// Clamps the sample time range to the stream length and issues an aligned async read into the sample buffer.
// @fnv 0x009fd7f0
long __stdcall FUN_009fd7f0(AsyncOutputPin* apPin, AsyncSample* pSample, unsigned long dwUser)
{
    if (pSample == 0)
        return 0x80004003;

    REFERENCE_TIME tStart, tStop;
    long hr = pSample->GetTime(&tStart, &tStop);
    if (hr < 0)
        return hr;

    LONGLONG llPos = tStart / 10000000;
    long lLength = (long)((tStop - tStart) / 10000000);

    LONGLONG llTotal = 0, llAvailable = 0;
    hr = apPin->m_pIo->Length(&llTotal, &llAvailable);
    if (llPos + lLength > llTotal)
    {
        long lAlign;
        apPin->m_pIo->Alignment(&lAlign);
        llTotal = (llTotal + lAlign - 1) & ~(lAlign - 1);
        if (llPos + lLength > llTotal)
        {
            lLength = (long)(llTotal - llPos);
            tStop = llTotal * 10000000;
            pSample->SetTime(&tStart, &tStop);
        }
    }

    unsigned char* pBuffer;
    hr = pSample->GetPointer(&pBuffer);
    if (hr < 0)
        return hr;

    return apPin->m_pIo->Request(llPos, lLength, 1, pBuffer, pSample, dwUser);
}

typedef __int64 REFTIME64;

struct MediaSampleStub
{
    virtual long __stdcall QueryInterface(void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall GetPointer(unsigned char** ppBuffer);
    virtual long __stdcall GetSize();
    virtual long __stdcall GetTime(REFTIME64* pStart, REFTIME64* pEnd);
    virtual long __stdcall SetTime(REFTIME64* pStart, REFTIME64* pEnd);
    virtual long __stdcall IsSyncPoint();
    virtual long __stdcall SetSyncPoint(int b);
    virtual long __stdcall IsPreroll();
    virtual long __stdcall SetPreroll(int b);
    virtual long __stdcall GetActualDataLength();
    virtual long __stdcall SetActualDataLength(long len);
};

struct SampleSourceStub
{
    int GetRange(__int64* pEnd, __int64* pOut);
    int GetAlignment(int* pAlign);
    long FillSample(__int64 start, int count, unsigned char* pBuffer, long* pLen, MediaSampleStub* pSample);
};

struct SampleFilterStub
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
    SampleSourceStub* source;
    long __stdcall FUN_009fd970(MediaSampleStub* pSample);
};

// Clamps the sample time range to the source's range and alignment, then fills the sample buffer via source->FillSample and sets its actual data length.
// @fnv 0x009fd970
long __stdcall SampleFilterStub::FUN_009fd970(MediaSampleStub* pSample)
{
    if (!pSample)
        return 0x80004003;

    __int64 startSec;
    REFTIME64 tStart, tStop;
    long hr = pSample->GetTime(&tStart, &tStop);
    if (hr < 0)
        return hr;

    startSec = tStart / 10000000;
    int count = (int)((tStop - tStart) / 10000000);
    __int64 endSec;
    __int64 extra;
    source->GetRange(&endSec, &extra);
    if (startSec + count > endSec)
    {
        int align;
        source->GetAlignment(&align);
        endSec = (endSec + align - 1) & ~(align - 1);
        if (startSec + count > endSec)
        {
            count = (int)(endSec - startSec);
            tStop = endSec * 10000000;
            pSample->SetTime(&tStart, &tStop);
        }
    }

    unsigned char* pBuffer;
    hr = pSample->GetPointer(&pBuffer);
    if (hr < 0)
        return hr;
    long len;
    hr = source->FillSample(startSec, count, pBuffer, &len, pSample);
    pSample->SetActualDataLength(len);
    return hr;
}

struct Primary9FDTemplate
{
    virtual void __cdecl FUN_009fdce0();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};
struct Secondary9FDTemplate
{
    virtual void __cdecl FUN_009fdce0();
};
// @fnv 0x009fdce0
template <class T> struct Derived9FDTemplate : Primary9FDTemplate, Secondary9FDTemplate
{
    virtual void __cdecl FUN_009fdce0();
};
template <class T> void __cdecl Derived9FDTemplate<T>::FUN_009fdce0()
{
    InvokeVirtualMethod(this);
}
extern template void __cdecl Derived9FDTemplate<int>::FUN_009fdce0();
Derived9FDTemplate<int> parent_template_object;

class FUN_009fdf20_target
{
  public:
    virtual void unk00();
    virtual int unk01(int a, int b);
    virtual int unk02(int a, int b, int c, int* d);
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
};

class FUN_009fdf20_cls
{
  public:
    int m_00;
    FUN_009fdf20_target* m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    void* m_1c;
    int m_20;
    int m_24;
    int FUN_009fdf20();
};

// Calls m_04 methods unk05, unk01 and unk02, updates m_14 from the returned out value, and returns the status in m_24 (1 if m_14 changed).
// @fnv 0x009fdf20
int FUN_009fdf20_cls::FUN_009fdf20()
{
    int out;
    m_04->unk05();
    m_24 = m_04->unk01(m_08, m_0c);
    if (m_24 == 0)
    {
        m_24 = m_04->unk02(m_18, m_14, m_10, &out);
        if (m_24 == 0x40000)
        {
            if (m_1c != 0)
            {
                void** vt = *(void***)m_1c;
                ((void(__stdcall*)(void*, int))vt[16])(m_1c, 1);
                m_24 = 0;
            }
        }
        if (m_24 >= 0)
        {
            if (out != m_14)
            {
                m_14 = out;
                m_24 = 1;
                m_04->unk06();
                return m_24;
            }
            m_24 = 0;
        }
    }
    m_04->unk06();
    return m_24;
}

extern "C" void __cdecl FUN_009fd320();

// @fnv 0x009fdfd0
void __cdecl FUN_009fdfd0()
{
    FUN_009fd320();
}

int __stdcall FUN_009fdf20(void);

struct Ctx : FUN_009fded0_cls
{
};

class Fdfe0Cls : public S_9fe1a0_Class
{
  public:
    int __thiscall FUN_009fdfe0(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int* out,
                                unsigned int p5);
};

// Checks p0, p2, p3 against unk18 alignment, calls FUN_009fded0, stores ctx.m_14 to out, returns FUN_009fdf20 result.
// @fnv 0x009fdfe0
int __thiscall Fdfe0Cls::FUN_009fdfe0(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3,
                                      unsigned int* out, unsigned int p5)
{
    if (out == 0)
    {
        return 0x80004003;
    }
    unsigned int align = unk18->v4();
    if ((p0 & (align - 1)) == 0)
    {
        align = unk18->v4();
        if ((p2 & (align - 1)) == 0)
        {
            align = unk18->v4();
            if ((p3 & (align - 1)) == 0)
            {
                Ctx ctx;
                int hr = ctx.FUN_009fded0((int)this, (int)unk18, (int)p0, (int)p1, (int)p2, 1, (int)p3, (int)p5, 0);
                if (hr < 0)
                {
                    return hr;
                }
                int r = FUN_009fdf20();
                *out = (unsigned int)ctx.m_14;
                return r;
            }
        }
    }
    return 0x8004020e;
}

// CAsyncIo::WaitForNext from the DirectShow base classes' async reader sample (asyncio.cpp)
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle,
                                                                             unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* lpCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* lpCriticalSection);

class CCritSec
{
    int m_CritSec[6];

  public:
    void Lock()
    {
        EnterCriticalSection(m_CritSec);
    }
    void Unlock()
    {
        LeaveCriticalSection(m_CritSec);
    }
};
class CAutoLock
{
    CCritSec* m_pLock;

  public:
    CAutoLock(CCritSec* plock)
    {
        m_pLock = plock;
        m_pLock->Lock();
    }
    ~CAutoLock()
    {
        m_pLock->Unlock();
    }
};
class CAMEvent
{
    void* m_hEvent;

  public:
    int Wait(unsigned long dwTimeout)
    {
        return WaitForSingleObject(m_hEvent, dwTimeout) == 0;
    }
};
class CAsyncStream
{
  public:
    virtual long QueryInterface(void* riid, void** ppv) = 0;
    virtual long SetPointer(__int64 llPos) = 0;
    virtual long Read(unsigned char* pbBuffer, unsigned long dwBytesToRead, int bAlign,
                      unsigned long* pdwBytesRead) = 0;
    virtual __int64 Size(__int64* pSizeAvailable = 0) = 0;
};
class CAsyncRequest
{
    void* m_pIo;
    CAsyncStream* m_pBinaryStream;
    __int64 m_llPos;
    int m_bAligned;
    long m_lLength;
    unsigned char* m_pBuffer;
    void* m_pContext;
    unsigned long m_dwUser;
    long m_hr;

  public:
    long GetHResult()
    {
        return m_hr;
    }
    long GetActualLength()
    {
        return m_lLength;
    }
    void* GetContext()
    {
        return m_pContext;
    }
    unsigned long GetUser()
    {
        return m_dwUser;
    }
    __int64 GetStart()
    {
        return m_llPos;
    }
};
class CAsyncIo
{
    char pad00[0x18];
    CAsyncStream* m_pBinaryStream;
    CCritSec m_csLists;
    int m_bFlushing;
    char pad38[0x34];
    CAMEvent m_evDone;
    char pad70[4];
    int m_bWaiting;

  public:
    CAsyncRequest* LockAndProcess();  // GetDoneItem
    __int64 Size()
    {
        return m_pBinaryStream->Size();
    }
    long WaitForCompletion(unsigned long dwTimeout, void** ppContext, unsigned long* pUser, long* pcbActual);
};

// Waits for an async I/O completion event, retrieves the next request, and returns its result, context, user data, and actual bytes read.
// @fnv 0x009fe570
long CAsyncIo::WaitForCompletion(unsigned long dwTimeout, void** ppContext, unsigned long* pUser, long* pcbActual)
{
    if (!ppContext)
        return 0x80004003;  // E_POINTER
    if (!pUser)
        return 0x80004003;
    if (!pcbActual)
        return 0x80004003;

    *ppContext = 0;

    for (;;)
    {
        if (!m_evDone.Wait(dwTimeout))
        {
            return 0x8004022E;  // VFW_E_TIMEOUT
        }

        CAsyncRequest* pRequest = LockAndProcess();
        if (pRequest)
        {
            long hr = pRequest->GetHResult();
            if (hr == 1)
            {  // S_FALSE: short read, fine if it ends at the end of the stream
                if ((pRequest->GetActualLength() + pRequest->GetStart()) == Size())
                {
                    hr = 0;
                }
                else
                {
                    hr = 0x80004005;  // E_FAIL
                }
            }

            *pcbActual = pRequest->GetActualLength();
            *ppContext = pRequest->GetContext();
            *pUser = pRequest->GetUser();

            delete pRequest;
            return hr;
        }
        else
        {
            CAutoLock lck(&m_csLists);
            if (m_bFlushing && !m_bWaiting)
            {
                return 0x80040227;  // VFW_E_WRONG_STATE
            }
        }
    }
}

extern "C" __declspec(dllimport) int __stdcall ResetEvent(void* hEvent);
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* lpThreadAttributes, unsigned long dwStackSize,
                                                              unsigned long(__stdcall* lpStartAddress)(void*),
                                                              void* lpParameter, unsigned long dwCreationFlags,
                                                              unsigned long* lpThreadId);
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();
typedef unsigned long(__stdcall* ThreadStartFn)(void*);
struct AMEventStandIn
{
    void* m_hEvent;
    void Reset()
    {
        ResetEvent(m_hEvent);
    }
};
struct AsyncIoStandIn
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78;
    AMEventStandIn m_evStop;
    void* m_hThread;
    long StartThread();
};
static inline long HResultFromWin32(unsigned long x)
{
    return (long)x <= 0 ? (long)x : (long)((x & 0x0000FFFF) | (7 << 16) | 0x80000000);
}
// Creates a worker thread via CreateThread if m_hThread is null, resetting m_evStop first and returning an HRESULT on failure.
// @fnv 0x009fe780
long AsyncIoStandIn::StartThread()
{
    if (m_hThread)
        return 0;
    m_evStop.Reset();
    unsigned long dwThreadID;
    m_hThread = CreateThread(0, 0, (ThreadStartFn)FUN_009fe560, this, 0, &dwThreadID);
    if (!m_hThread)
    {
        unsigned long dwErr = GetLastError();
        return HResultFromWin32(dwErr);
    }
    return 0;
}

namespace fnv_009fe870 {
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* pkSection);
void __cdecl FormHeap_Free(void* pvMemory);  // free

class OwnedLock
{
  public:
    char m_acSection[0x18];  // CRITICAL_SECTION
    int m_iOwner;
    ~OwnedLock()
    {
        DeleteCriticalSection(m_acSection);
    }
};

class FUN_009fd320
{
  public:
    ~FUN_009fd320();
    void* PopAndGetValue(void*& rpvPos);  // GetNext
    void ClearList();                     // RemoveAll
    void* m_pvHead;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

class FUN_009fcfe0
{
  public:
    ~FUN_009fcfe0();
    void* m_pvObject;
};

class FUN_009fe870
{
  public:
    ~FUN_009fe870();
    void FUN_009fe690();
    void FUN_009fe0c0();

    OwnedLock m_kLockA;              // +0x00
    OwnedLock m_kLockB;              // +0x1c
    class FUN_009fd320 m_kListA;     // +0x38
    class FUN_009fd320 m_kListB;     // +0x50
    class FUN_009fcfe0 m_kHandle68;  // +0x68
    class FUN_009fcfe0 m_kHandle6c;  // +0x6c
    int unk70;
    int unk74;
    class FUN_009fcfe0 m_kHandle78;  // +0x78
    class FUN_009fcfe0 m_kHandle7c;  // +0x7c
};

// Destructor that calls FUN_009fe690 and FUN_009fe0c0, then frees every item in m_kListB via FormHeap_Free and clears the list.
// @fnv 0x009fe870
FUN_009fe870::~FUN_009fe870()
{
    FUN_009fe690();
    FUN_009fe0c0();
    void* pvPos = m_kListB.m_pvHead;
    while (pvPos)
        FormHeap_Free(m_kListB.PopAndGetValue(pvPos));
    m_kListB.ClearList();
}
}  // namespace fnv_009fe870

void* __cdecl operator new(unsigned int);

struct Stream_9fe960
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual __int64 GetAlign4();
};

struct Host_9fe960;

struct Req_9fe960
{
    int Init(Host_9fe960* pHost, Stream_9fe960* pStream, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
};

struct Host_9fe960
{
    int unk[6];
    Stream_9fe960* m_p18;
    int Queue(Req_9fe960* pReq);
    int FUN_009fe960(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
};

// Allocates a request, initializes it with the given parameters, and queues it on the host, returning the HRESULT.
// @fnv 0x009fe960
int Host_9fe960::FUN_009fe960(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    if (a4)
    {
        if ((a1 & (int)(m_p18->GetAlign4() - 1)) || (a3 & (int)(m_p18->GetAlign4() - 1)) ||
            (a5 & (int)(m_p18->GetAlign4() - 1)))
            return 0x8004020e;
    }
    Req_9fe960* pReq = (Req_9fe960*)operator new(0x28);
    if (!pReq)
        return 0x8007000e;
    int hr = pReq->Init(this, m_p18, a1, a2, a3, a4, a5, a6, a7);
    if (hr < 0 || (hr = Queue(pReq), hr < 0))
    {
        operator delete(pReq);
    }
    return hr;
}

struct S_009f9bb0_Unk;
struct S_009f9bb0_Vtbl
{
    int unk00;
    int(__stdcall* AddRef)(S_009f9bb0_Unk*);
};
struct S_009f9bb0_Unk
{
    S_009f9bb0_Vtbl* vtbl;
};
struct S_009f9bb0_Rec
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
    S_009f9bb0_Unk* unk3c;
    int unk40;
    void* unk44;
};
// Copies src into dst, allocates and copies the heap buffer when src->unk40 is set, and AddRefs the COM pointer in unk3c.
// @fnv 0x009f9bb0
int __stdcall FUN_009f9bb0(S_009f9bb0_Rec* dst, S_009f9bb0_Rec* src)
{
    *dst = *src;
    if (src->unk40)
    {
        dst->unk44 = DAT_00fdf460(src->unk40);
        if (!dst->unk44)
        {
            dst->unk40 = 0;
            return 0x8007000e;
        }
        memcpy(dst->unk44, src->unk44, dst->unk40);
    }
    if (dst->unk3c)
    {
        dst->unk3c->vtbl->AddRef(dst->unk3c);
    }
    return 0;
}

struct S_009fa520_obj
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
};

// Stores five values into the tail fields of S_009fa520_obj and returns 0.
// @fnv 0x009fa520
int __stdcall FUN_009fa520(S_009fa520_obj* obj, int a, int b, int c, int d, double e)
{
    obj->unk74 = a;
    obj->unk78 = b;
    obj->unk7c = c;
    obj->unk80 = d;
    *(volatile double*)((char*)obj + 0x84) = e;
    return 0;
}

// @fnv 0x009fcb50
struct FUN_009fcb50
{
    virtual void Update();
    int state04, state08, value0c, value10, value14, value18;
    int field1c, field20, field24, field28, field2c, field30, field34, field38;
    int state3c, state40, state44;
    FUN_009fcb50(int unused1, int second, int FlushUsageData, int fourth, int fifth);
};
FUN_009fcb50::FUN_009fcb50(int unused1, int second, int FlushUsageData, int fourth, int fifth) : state04(0), state08(0)
{
    value0c = fourth;
    value10 = fifth;
    value14 = fifth;
    value18 = second;
    state3c = 0;
    state40 = 0;
    state44 = 0;
}

// FUN_009fdcf0: __cdecl adjustor thunk (sub [esp+4],0x18; jmp target).
// Primary base is 0x18 bytes (vptr + five ints); the secondary base sits at +0x18 inside Derived.
struct PrimaryBase_009fdcf0
{
    virtual void __cdecl FUN_009fdcf0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct SecondaryBase_009fdcf0
{
    virtual void __cdecl FUN_009fdcf0();
};

struct Derived_009fdcf0 : PrimaryBase_009fdcf0, SecondaryBase_009fdcf0
{
    Derived_009fdcf0();
// @fnv 0x009fdcf0
    virtual void __cdecl FUN_009fdcf0();
};

Derived_009fdcf0::Derived_009fdcf0()
{}

// FUN_009fdd00: __cdecl adjustor thunk (sub [esp+4],0x14; jmp Derived override).
// Primary base is 0x14 bytes; the secondary base sits at +0x14 inside Derived.
struct PrimaryBase_009fdd00
{
    virtual void __cdecl FUN_009fdd00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase_009fdd00
{
    virtual void __cdecl FUN_009fdd00();
};

struct Derived_009fdd00 : PrimaryBase_009fdd00, SecondaryBase_009fdd00
{
    Derived_009fdd00();
// @fnv 0x009fdd00
    virtual void __cdecl FUN_009fdd00();
};

Derived_009fdd00::Derived_009fdd00()
{}

// ---------------------------------------------------------------------------
// FUN_009fdd10 (0x009fdd10, 10 bytes)
//
// The original is an ADJUSTOR THUNK.  Its bytes are
//     sub dword ptr [esp+4], 0x14
//     jmp     0x009fd430
// i.e. it takes the pointer that was passed on the stack, moves it back by
// 0x14 (the offset of the secondary base inside the complete object) and
// tail-jumps to the shared implementation.
//
// MSVC 2008 emits an adjustor thunk as "sub ecx, N / jmp target" - with the
// adjustment applied to ECX, because a normal virtual function receives "this"
// in ECX.  When the virtual is declared __cdecl, however, "this" travels on
// the stack as the first argument, and the very same thunk is emitted as
// "sub dword ptr [esp+4], N / jmp target" instead.
//
// So the model is: two bases declare the same __cdecl virtual, the derived
// class overrides it (declared only, never defined - that keeps the thunk's
// "jmp" an unresolved external that the checker binds from the original
// bytes), the first base is padded so that the second base lands at offset
// 0x14, and a defined key function in the derived class makes the compiler
// emit the vftable that references the thunk.
// ---------------------------------------------------------------------------

struct ThunkBaseA
{
    ThunkBaseA();
    virtual void __cdecl FUN_009fdd10();
    char pad_10[0x10];  // makes ThunkBaseA exactly 0x14 bytes
};

struct ThunkBaseB
{
    ThunkBaseB();
// @fnv 0x009fdd10
    virtual void __cdecl FUN_009fdd10();
};

struct ThunkOwner : ThunkBaseA, ThunkBaseB
{
    ThunkOwner();
    virtual void ThunkKey();      // key function -> the vftable is emitted
    void __cdecl FUN_009fdd10();  // the shared override: DECLARED ONLY
};

ThunkBaseA::ThunkBaseA()
{}
ThunkBaseB::ThunkBaseB()
{}
ThunkOwner::ThunkOwner()
{}
void ThunkOwner::ThunkKey()
{}

// FUN_009fdd20: __cdecl adjustor thunk (sub [esp+4],0x18; jmp target).
// Primary base is 0x18 bytes (vptr + five ints); the secondary base sits at +0x18 inside Derived.
struct PrimaryBase_009fdd20
{
    virtual void __cdecl FUN_009fdd20();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct SecondaryBase_009fdd20
{
    virtual void __cdecl FUN_009fdd20();
};

struct Derived_009fdd20 : PrimaryBase_009fdd20, SecondaryBase_009fdd20
{
    Derived_009fdd20();
// @fnv 0x009fdd20
    virtual void __cdecl FUN_009fdd20();
};

Derived_009fdd20::Derived_009fdd20()
{}

// FUN_009fdd30: __cdecl adjustor thunk (sub [esp+4],0x14; jmp target).
// Primary base is 0x14 bytes (vptr + four ints); secondary base sits at +0x14 in Derived.
struct PrimaryBase_009fdd30
{
    virtual void __cdecl FUN_009fdd30();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase_009fdd30
{
    virtual void __cdecl FUN_009fdd30();
};

struct Derived_009fdd30 : PrimaryBase_009fdd30, SecondaryBase_009fdd30
{
    Derived_009fdd30();
// @fnv 0x009fdd30
    virtual void __cdecl FUN_009fdd30();
};

Derived_009fdd30::Derived_009fdd30()
{}

// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct AdjPrimaryBase
{
    virtual void FUN_009fdd50();
    int unk04;
};

struct AdjSecondaryBase
{
    virtual void FUN_009fdd50();
};

struct AdjDerived : AdjPrimaryBase, AdjSecondaryBase
{
    AdjDerived();
// @fnv 0x009fdd50
    virtual void FUN_009fdd50();
};

AdjDerived::AdjDerived()
{}

// FUN_009fdd60: __cdecl adjustor thunk (sub dword ptr [esp+4],0x18; jmp target).
// A __cdecl virtual member passes "this" as the first stack argument, so the
// multiple-inheritance adjustor thunk subtracts the secondary-base offset from
// the stack slot instead of from ecx. Primary base is 0x18 bytes (vptr + five
// ints); the secondary base subobject sits at +0x18 inside Derived.
struct PrimaryBase_009fdd60
{
    virtual void __cdecl FUN_009fdd60();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct SecondaryBase_009fdd60
{
    virtual void __cdecl FUN_009fdd60();
};

struct Derived_009fdd60 : PrimaryBase_009fdd60, SecondaryBase_009fdd60
{
    Derived_009fdd60();
// @fnv 0x009fdd60
    virtual void __cdecl FUN_009fdd60();
};

Derived_009fdd60::Derived_009fdd60()
{}

namespace fnv_009fddf0 {
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* lpCriticalSection);
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* lpCriticalSection);

extern int DAT_01093d70;

struct Base_cls
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

    int m_04;
    int m_08;
    ~Base_cls();
    Base_cls(int a, int b, void* c, void* d, int e);
};

struct __declspec(novtable) Mem1_cls
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
};

struct __declspec(novtable) Mem2_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
};

struct CriticalSection_cls
{
    struct
    {
        int m_00;
        int m_04;
        int m_08;
        int m_0c;
        int m_10;
        int m_14;
    } m_cs;
    CriticalSection_cls()
    {
        InitializeCriticalSection(&m_cs);
    }
    ~CriticalSection_cls()
    {
        DeleteCriticalSection(&m_cs);
    }
};

struct Mem3_cls
{
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
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    ~Mem3_cls();
    Mem3_cls(int a);
};

struct Mem4_cls
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
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    ~Mem4_cls();
    Mem4_cls(int a, void* b, void* c, void* d);
};

struct Mem5_cls
{
    int m_00;
    int m_04;
    Mem5_cls();
};

struct FUN_009fddf0_cls : Base_cls, Mem1_cls, Mem2_cls
{
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
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
    CriticalSection_cls m_50;
    Mem3_cls m_68;
    Mem4_cls m_f0;
    int m_198;
    int m_19c;
    Mem5_cls m_1a0;
    FUN_009fddf0_cls(int a, int b, int c, int d);
};

// Initializes the object by calling Base_cls, m_50, m_68, m_f0, and m_1a0 constructors with the provided parameters.
// @fnv 0x009fddf0
FUN_009fddf0_cls::FUN_009fddf0_cls(int aBaseParam, int b, int c, int d)
    : Base_cls(aBaseParam, b, &m_50, &DAT_01093d70, 0), m_50(), m_68(c), m_f0(d, this, &m_68, &m_50), m_1a0()
{}
}  // namespace fnv_009fddf0

// Returns whether the first 16 bytes of b and a are identical using memcmp.
// @fnv 0x009f9980
int __stdcall FUN_009f9980(const void* apFirst, const void* apSecond)
{
    return memcmp(apFirst, apSecond, 16) == 0;
}

namespace fnv_009f9e50 {
extern int DAT_01093b6c[4];
struct GraphUnknown
{
    virtual long __stdcall QueryInterface(const void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};
struct GraphFilter
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
    void* m_lock;
    wchar_t* m_name;
    GraphUnknown* m_graph;
    GraphUnknown* m_sink;
};
struct GraphLock
{
    void* m_lock;
    GraphLock(void* lock) : m_lock(lock)
    {
        EnterCriticalSection(m_lock);
    }
    ~GraphLock()
    {
        LeaveCriticalSection(m_lock);
    }
};
unsigned int __stdcall FUN_009fd080(const wchar_t*);
void* __cdecl _memmove(void*, const void*, unsigned int);
// Locks the filter, updates m_graph and m_sink from graph, and replaces m_name with a copy of name.
// @fnv 0x009f9e50
int __stdcall SetGraphAndName(GraphFilter* self, GraphUnknown* graph, const wchar_t* name)
{
    GraphLock lock(self->m_lock);
    self->m_graph = graph;
    if (graph)
    {
        if (graph->QueryInterface(DAT_01093b6c, (void**)&self->m_sink) >= 0)
            self->m_sink->Release();
    }
    else
    {
        self->m_sink = 0;
    }
    if (self->m_name)
    {
        operator delete(self->m_name);
        self->m_name = 0;
    }
    if (name)
    {
        unsigned int n = FUN_009fd080(name) + 1;
        self->m_name = new wchar_t[n];
        if (self->m_name)
            _memmove(self->m_name, name, n * 2);
    }
    return 0;
}
}  // namespace fnv_009f9e50

typedef unsigned int(__thiscall* DispatchFn)(void* self, void* arg, void* out);
struct TargetCall
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    DispatchFn m_24;
};
struct TargetOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void* m_1c;
    unsigned int __thiscall DispatchCall(void** arg);
};
// @fnv 0x009fa350
unsigned int TargetOwner::DispatchCall(void** arg)
{
    TargetCall* p = (TargetCall*)*arg;
    p->m_24(p, arg, &arg);
    unsigned int result = (arg != (void**)m_1c) ? 1u : 0u;
    result = result - 1u;
    return result & 0x80040208u;
}

struct ConnIface
{
    virtual long __stdcall QueryInterface(void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

struct ConnHolder
{
    virtual long __stdcall QueryInterface(void* riid, void** ppv);
    int unk04;
    int unk08;
    ConnIface* m_Connected;

    long __stdcall GetConnected(ConnIface** ppPin);
};

// @fnv 0x009fa3c0
long __stdcall ConnHolder::GetConnected(ConnIface** ppPin)
{
    if (ppPin == 0)
        return 0x80004003;
    ConnIface* pConnected = m_Connected;
    *ppPin = pConnected;
    if (pConnected != 0)
    {
        pConnected->AddRef();
        return 0;
    }
    return 0x80040209;
}

struct S_009fa820_Foo
{
    int unk00;
    unsigned char unk04;
};

// @fnv 0x009fa820
int __stdcall FUN_009fa820(S_009fa820_Foo* obj)
{
    unsigned int u = (unsigned char)(~obj->unk04);
    unsigned int w = u >> 2;
    return (int)((w & 1u) | ((u & 4u) >> 2));
}

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle,
                                                                             unsigned long dwMilliseconds);

class CCritSecW
{
  public:
    void Lock()
    {
        EnterCriticalSection(&m_CritSec);
    }
    void Unlock()
    {
        LeaveCriticalSection(&m_CritSec);
    }

    struct CriticalSection
    {
        int DebugInfo;
        int LockCount;
        int RecursionCount;
        int OwningThread;
        int LockSemaphore;
        int SpinCount;
    } m_CritSec;
};

class CAutoLockW
{
  public:
    CAutoLockW(CCritSecW* plock) : m_pLock(plock)
    {
        m_pLock->Lock();
    }
    ~CAutoLockW()
    {
        m_pLock->Unlock();
    }

    CCritSecW* m_pLock;
};

class CMediaSampleW
{
  public:
    CMediaSampleW* Next()
    {
        return m_pNext;
    }

    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    CMediaSampleW* m_pNext;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    long m_lRefCount;
};

class CSampleListW
{
  public:
    CMediaSampleW* RemoveHead()
    {
        CMediaSampleW* pSample = m_kEntryList;
        if (pSample != 0)
        {
            m_kEntryList = m_kEntryList->Next();
            m_nOnList--;
        }
        return pSample;
    }

    CMediaSampleW* m_kEntryList;
    int m_nOnList;
};

class CUnknownW
{
  public:
    virtual ~CUnknownW();

    const char* m_pName;
    void* m_pUnknown;
};

class IMemAllocatorW
{
  public:
    virtual long __stdcall QueryInterface(void* riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall SetProperties(void* pRequest, void* pActual) = 0;
    virtual long __stdcall GetProperties(void* pProps) = 0;
    virtual long __stdcall Commit() = 0;
    virtual long __stdcall Decommit() = 0;
    virtual long __stdcall FUN_009fad00(CMediaSampleW** ppBuffer, __int64* pStartTime, __int64* pEndTime,
                                        unsigned long dwFlags) = 0;
};

class CBaseAllocatorW : public CUnknownW, public IMemAllocatorW, public CCritSecW
{
  public:
    long __stdcall FUN_009fad00(CMediaSampleW** ppBuffer, __int64* pStartTime, __int64* pEndTime,
                                unsigned long dwFlags);

    void SetWaiting()
    {
        m_lWaiting++;
    }

    CSampleListW m_lFree;
    void* m_hSem;
    long m_lWaiting;
    long m_lCount;
    long m_lAllocated;
    long m_lSize;
    long m_lAlignment;
    long m_lPrefix;
    int m_bChanged;
    int m_bCommitted;
};

// Pops a sample from m_lFree with refcount 1, waiting on m_hSem when empty unless dwFlags & 4 is set; fails if not committed.
// @fnv 0x009fad00
long __stdcall CBaseAllocatorW::FUN_009fad00(CMediaSampleW** ppBuffer, __int64* pStartTime, __int64* pEndTime,
                                             unsigned long dwFlags)
{
    CMediaSampleW* pSample;

    *ppBuffer = 0;
    for (;;)
    {
        {
            CAutoLockW cObjectLock(this);

            if (!m_bCommitted)
                return 0x80040211;
            pSample = m_lFree.RemoveHead();
            if (pSample == 0)
                SetWaiting();
        }

        if (pSample)
            break;
        if (dwFlags & 4)
            return 0x8004022e;
        WaitForSingleObject(m_hSem, 0xffffffff);
    }

    pSample->m_lRefCount = 1;
    *ppBuffer = pSample;
    return 0;
}

struct SyncUnknown
{
    virtual long __stdcall QueryInterface(const void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};
struct SyncInterface
{
    virtual int __stdcall FUN_009fada0(SyncUnknown*) = 0;
};
struct SyncHead
{
    virtual void HeadMethod();
    int unk04;
    int unk08;
};
struct SyncOwner : SyncHead, SyncInterface, AllocCritSec
{
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
    SyncUnknown* clock;
    virtual int __stdcall FUN_009fada0(SyncUnknown* clock);
};
// Locks the owner, AddRefs the new clock, Releases the old clock, stores the new clock pointer, and returns 0.
// @fnv 0x009fada0
int __stdcall SyncOwner::FUN_009fada0(SyncUnknown* clock)
{
    AllocLock guard(this);
    if (clock)
        clock->AddRef();
    if (this->clock)
        this->clock->Release();
    this->clock = clock;
    return 0;
}

typedef void(__stdcall* LockedVirtStdFn)(void*);

struct LockedOwner_b5d0
{
    void* m_ppVirtualMethodTable;
    unsigned int unk04;
    unsigned int unk08;
    void* m_0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    int* m_2c;
};

struct LockGuard_b5d0
{
    int* m_pGuardedLock;
    LockGuard_b5d0(LockedOwner_b5d0* o)
    {
        m_pGuardedLock = o->m_2c;
        EnterCriticalSection(m_pGuardedLock);
    }
    ~LockGuard_b5d0()
    {
        LeaveCriticalSection(m_pGuardedLock);
    }
};

// Locks a->m_2c, calls vtable slot 1 on b and slot 2 on the old a->m_0c, stores b in a->m_0c, and returns 0.
// @fnv 0x009fb5d0
int __stdcall SetLockedPointer(LockedOwner_b5d0* apOwner, void* apNewPointer)
{
    LockGuard_b5d0 guard(apOwner);
    if (apNewPointer != 0)
    {
        ((LockedVirtStdFn)(*(void***)apNewPointer)[1])(apNewPointer);
    }
    void* pOldPointer = apOwner->m_0c;
    if (pOldPointer != 0)
    {
        ((LockedVirtStdFn)(*(void***)pOldPointer)[2])(pOldPointer);
    }
    apOwner->m_0c = apNewPointer;
    return 0;
}

extern void(__stdcall* DAT_00fdf05c)(int* pkCriticalSection);
extern void(__stdcall* DAT_00fdf100)(int* pkCriticalSection);

class CriticalSectionLock
{
  public:
    CriticalSectionLock(int* pkCriticalSection) : m_pkCriticalSection(pkCriticalSection)
    {
        EnterCriticalSection(m_pkCriticalSection);
    }
    ~CriticalSectionLock()
    {
        LeaveCriticalSection(m_pkCriticalSection);
    }

    int* m_pkCriticalSection;
};

class TaskW
{
  public:
    virtual void Vf00();
    virtual void Vf04();
    virtual void Vf08();
    virtual void Vf0c();
    virtual void Vf10();
    virtual void Vf14();
    virtual int Finish();

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int m_iActive;
};

class TaskGroupW
{
  public:
    virtual void Vf00();
    virtual void Vf04();
    virtual void Vf08();
    virtual void Vf0c();
    virtual void Vf10();
    virtual void Vf14();
    virtual int GetTaskCount();
    virtual TaskW* GetTask(int iIndex);
};

struct TaskGroupInnerW
{
    int m_iUnk00;
    int m_iUnk04;
    int m_bPending;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int* m_pkCriticalSection;
};

// Under the critical section, if m_bPending calls Finish on each active task, returns the first negative result (else 0), and clears m_bPending.
// @fnv 0x009fb6f0
int __stdcall FinishPendingTasks(TaskGroupInnerW* pkInner)
{
    CriticalSectionLock kLock(pkInner->m_pkCriticalSection);
    int iResult = 0;
    if (pkInner->m_bPending)
    {
        TaskGroupW* pkGroup = (TaskGroupW*)((char*)pkInner - 0xc);
        int iCount = pkGroup->GetTaskCount();
        for (int i = 0; i < iCount; i++)
        {
            TaskW* pkTask = pkGroup->GetTask(i);
            if (pkTask->m_iActive)
            {
                int iRet = pkTask->Finish();
                if (iRet < 0 && iResult >= 0)
                    iResult = iRet;
            }
        }
    }
    pkInner->m_bPending = 0;
    return iResult;
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct CBasePin
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int Active();

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int m_Connected;
};

struct CBaseFilter
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int GetPinCount();
    virtual CBasePin* GetPin(int n);
};

struct FilterInterface
{
    int unk00;
    int unk04;
    int m_iValueAt14;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int* m_pLock;

    int __stdcall Activate();
};

struct AutoLock
{
    int* m_pLock;
    AutoLock(int* lock) : m_pLock(lock)
    {
        EnterCriticalSection(m_pLock);
    }
    ~AutoLock()
    {
        LeaveCriticalSection(m_pLock);
    }
};

// @fnv 0x009fb7a0
int __stdcall FilterInterface::Activate()
{
    AutoLock lock(m_pLock);

    if (m_iValueAt14 == 0)
    {
        CBaseFilter* filter = reinterpret_cast<CBaseFilter*>(reinterpret_cast<char*>(this) - 0xc);
        int count = filter->GetPinCount();
        for (int c = 0; c < count; ++c)
        {
            CBasePin* pin = filter->GetPin(c);
            if (pin->m_Connected != 0)
            {
                int hr = pin->Active();
                if (hr < 0)
                {
                    return hr;
                }
            }
        }
    }

    m_iValueAt14 = 1;
    return 0;
}

struct FltCritSec
{
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
    void Lock()
    {
        EnterCriticalSection(this);
    }
    void Unlock()
    {
        LeaveCriticalSection(this);
    }
};

struct FltAutoLock
{
    FltCritSec* m_pLock;
    FltAutoLock(FltCritSec* plock)
    {
        m_pLock = plock;
        m_pLock->Lock();
    }
    ~FltAutoLock()
    {
        m_pLock->Unlock();
    }
};

struct FltPin
{
    virtual long __stdcall NonDelegatingQueryInterface(void* riid, void** ppv);
    virtual unsigned long __stdcall NonDelegatingAddRef();
    virtual unsigned long __stdcall NonDelegatingRelease();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual long Run(__int64 tStart);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* m_Connected;
    bool IsConnected()
    {
        return (m_Connected != 0);
    }
};

struct FltRefTime
{
    __int64 m_uiCommandId;
    FltRefTime& operator=(const __int64& ll)
    {
        m_uiCommandId = ll;
        return *this;
    }
};

struct FltUnknown
{
    virtual long __stdcall NonDelegatingQueryInterface(void* riid, void** ppv);
    virtual unsigned long __stdcall NonDelegatingAddRef();
    virtual unsigned long __stdcall NonDelegatingRelease();
    int unk04;
    int unk08;
};

struct FltMediaFilter
{
    virtual long __stdcall QueryInterface(void* riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetClassID(void* pClsID) = 0;
    virtual long __stdcall Stop() = 0;
    virtual long __stdcall Pause() = 0;
    virtual long __stdcall FUN_009fb860(__int64 tStart) = 0;
};

struct FltMovieSetup
{
    virtual long __stdcall QueryInterface(void* riid, void** ppv) = 0;
};

struct FltBaseFilter : FltUnknown, FltMediaFilter, FltMovieSetup
{
    int m_iValueAt14;
    void* m_pClock;
    FltRefTime m_tStart;
    unsigned long m_clsid0;
    unsigned long m_clsid1;
    unsigned long m_clsid2;
    unsigned long m_clsid3;
    FltCritSec* m_pLock;

    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual int GetPinCount();
    virtual FltPin* GetPin(int n);

    long __stdcall QueryInterface(void* riid, void** ppv);
    unsigned long __stdcall AddRef();
    unsigned long __stdcall Release();
    long __stdcall GetClassID(void* pClsID);
    long __stdcall Stop();
    long __stdcall Pause();
    long __stdcall FUN_009fb860(__int64 tStart);
};

// @fnv 0x009fb860
long __stdcall FltBaseFilter::FUN_009fb860(__int64 tStart)
{
    FltAutoLock cObjectLock(m_pLock);

    m_tStart = tStart;

    if (m_iValueAt14 == 0)
    {
        long hr = Pause();
        if (hr < 0)
        {
            return hr;
        }
    }

    if (m_iValueAt14 != 2)
    {
        int cPins = GetPinCount();
        for (int c = 0; c < cPins; c++)
        {
            FltPin* pPin = GetPin(c);
            if (pPin->IsConnected())
            {
                long hr = pPin->Run(tStart);
                if (hr < 0)
                {
                    return hr;
                }
            }
        }
    }
    m_iValueAt14 = 2;
    return 0;
}

class ConnectionPin
{
  public:
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual int v08(int a) = 0;
    virtual int v09(int a) = 0;
    virtual int v10(void* a) = 0;
    virtual void v11() = 0;
    virtual int v12(void* a) = 0;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    void* m_18;
    int FUN_009fbf00(void* a1, int a2);
};

// Calls v10(a1) and v08(a2), stores a1 in m_18, calls methods on a1 plus v09 and v12; on failure calls v11, releases m_18 and returns the error.
// @fnv 0x009fbf00
int ConnectionPin::FUN_009fbf00(void* a1, int a2)
{
    int hr = v10(a1);
    if (hr < 0)
    {
        v11();
        return hr;
    }
    hr = v08(a2);
    if (hr == 0)
    {
        m_18 = a1;
        ((void(__stdcall*)(void*))(*(void***)a1)[1])(a1);
        hr = v09(a2);
        if (hr >= 0)
        {
            hr = ((int(__stdcall*)(void*, int*, int))(*(void***)a1)[4])(a1, &m_0c, a2);
            if (hr >= 0)
            {
                hr = v12(a1);
                if (hr >= 0)
                {
                    return hr;
                }
                ((void(__stdcall*)(void*))(*(void***)a1)[5])(a1);
            }
        }
    }
    else if (hr >= 0 || hr == 0x80004005 || hr == 0x80070057)
    {
        hr = 0x8004022a;
    }
    v11();
    if (m_18 != 0)
    {
        void* obj = m_18;
        ((void(__stdcall*)(void*))(*(void***)obj)[2])(obj);
        m_18 = 0;
    }
    return hr;
}

// @fnv 0x009fd080
extern "C" int __stdcall FUN_009fd080(const unsigned short* apString)
{
    int i = -1;
    do
    {
        i = i + 1;
    } while (apString[i] != 0);
    return i;
}

struct CNode
{
    CNode* m_pListObject;
    CNode* m_pNext;
    void* m_pObject;
    CNode* Next() const
    {
        return m_pNext;
    }
    void SetPrev(CNode* p)
    {
        m_pListObject = p;
    }
    void SetNext(CNode* p)
    {
        m_pNext = p;
    }
    void SetData(void* p)
    {
        m_pObject = p;
    }
};

class CNodeCache
{
  public:
    int m_iCacheSize;
    int m_iUsed;
    CNode* m_pHead;
    CNode* RemoveFromCache()
    {
        CNode* pNode = m_pHead;
        if (pNode != 0)
        {
            m_pHead = pNode->Next();
            m_iUsed--;
        }
        return pNode;
    }
};

class CBaseList_9fd
{
  public:
    CNode* m_pFirst;
    CNode* m_pLast;
    int m_iNodeCount;
    CNodeCache m_Cache;
    CNode* AddNode(void* pObject);
};

// Allocates a CNode from the cache or heap, links it to the end of the list, and increments the node count.
// @fnv 0x009fd270
CNode* CBaseList_9fd::AddNode(void* pObject)
{
    CNode* pNode = m_Cache.RemoveFromCache();
    if (pNode == 0)
    {
        pNode = new CNode;
    }
    if (pNode == 0)
        return 0;
    pNode->SetData(pObject);
    pNode->SetNext(0);
    pNode->SetPrev(m_pLast);
    if (m_pLast == 0)
    {
        m_pFirst = pNode;
    }
    else
    {
        m_pLast->SetNext(pNode);
    }
    m_pLast = pNode;
    ++m_iNodeCount;
    return pNode;
}

struct S_009fd2d0_Pos;
struct S_009fd2d0_List
{
    S_009fd2d0_Pos* FUN_009fd0f0();
    void* PopAndGetValue(S_009fd2d0_Pos** pos);
    int AddNode(void* item);
    int FUN_009fd2d0(S_009fd2d0_List* src);
};
// Walks src with FUN_009fd0f0 and PopAndGetValue, adding each item via AddNode; returns 0 as soon as an add fails, otherwise 1.
// @fnv 0x009fd2d0
int S_009fd2d0_List::FUN_009fd2d0(S_009fd2d0_List* src)
{
    S_009fd2d0_Pos* pos = src->FUN_009fd0f0();
    while (pos)
    {
        void* item = src->PopAndGetValue(&pos);
        if (!AddNode(item))
            return 0;
    }
    return 1;
}

struct AlignSource
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual unsigned int GetAlignment();
};

struct SyncRequest
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
    int FUN_009fded0(void* owner, AlignSource* src, __int64 position, unsigned int length, int aligned,
                     unsigned char* buffer, void* context, unsigned int user);
};

struct SyncReader
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    AlignSource* m_18;
    int FUN_009fdfe0(__int64 position, unsigned int length, unsigned char* buffer, unsigned int* out, unsigned int p6);
    int FUN_009fe100(__int64 position, unsigned int length, unsigned char* buffer);
};

// @fnv 0x009fe100
int SyncReader::FUN_009fe100(__int64 position, unsigned int length, unsigned char* buffer)
{
    if (((unsigned int)position & (m_18->GetAlignment() - 1)) == 0 && (length & (m_18->GetAlignment() - 1)) == 0 &&
        ((unsigned int)buffer & (m_18->GetAlignment() - 1)) == 0)
    {
        unsigned int actual;
        return FUN_009fdfe0(position, length, buffer, &actual, 0);
    }
    else
    {
        SyncRequest ctx;
        int hr = ctx.FUN_009fded0(this, m_18, position, length, 0, buffer, 0, 0);
        if (hr >= 0)
            return FUN_009fdf20();
        return hr;
    }
}

struct S_009fd390_Class
{
    int __thiscall FUN_009fd390();

    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int* unk1c;
    int unk20;
    int unk24;
};

extern void(__stdcall* DAT_00fdf1cc)(int*);

struct S_009fe370_AutoLock
{
    int* pLock;

    S_009fe370_AutoLock(int* p) : pLock(p)
    {
        EnterCriticalSection(pLock);
    }

    ~S_009fe370_AutoLock() throw()
    {
        LeaveCriticalSection(pLock);
    }
};

struct S_009fe370_Class
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
    S_009fd390_Class unk50;

    int __thiscall LockAndProcess();
};

// @fnv 0x009fe370
int S_009fe370_Class::LockAndProcess()
{
    S_009fe370_AutoLock lock(&unk1c);

    int result = unk50.FUN_009fd390();

    if (unk50.unk08 == 0)
    {
        if (unk34 == 0 || unk50.unk24 != 0)
        {
            DAT_00fdf1cc(unk50.unk1c);
        }
    }

    return result;
}

struct S_009fe420_Item
{
    void __thiscall FUN_009fdf20();
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall SetEvent(void*);

struct CriticalSection9FE
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void Lock()
    {
        EnterCriticalSection(this);
    }
    void Unlock()
    {
        LeaveCriticalSection(this);
    }
};
struct S_009fe420_Lock
{
    CriticalSection9FE* m_cs;
    S_009fe420_Lock(CriticalSection9FE* cs)
    {
        m_cs = cs;
        m_cs->Lock();
    }
    ~S_009fe420_Lock()
    {
        m_cs->Unlock();
    }
};

struct S_009fe420_Cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    CriticalSection9FE unk1C;
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
    void* unk78;

    S_009fe420_Item* __thiscall FUN_009fe2f0();
    void __thiscall FUN_009fe3f0(S_009fe420_Item* item);
    void __thiscall ProcessItems();
};

// Repeatedly takes an item from FUN_009fe2f0, runs FUN_009fdf20 on it, calls FUN_009fe3f0, and sets event unk78 when unk70 reaches 0 and unk74 is set.
// @fnv 0x009fe420
void __thiscall S_009fe420_Cls::ProcessItems()
{
    for (;;)
    {
        S_009fe420_Item* item;
        {
            S_009fe420_Lock lock(&unk1C);
            item = FUN_009fe2f0();
            if (!item)
                break;
            unk70 += 1;
        }
        item->FUN_009fdf20();
        {
            S_009fe420_Lock lock(&unk1C);
            FUN_009fe3f0(item);
            if (--unk70 == 0 && unk74)
                SetEvent(unk78);
        }
    }
}

namespace fnv_009fabb0 {
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* pCS);

struct ComObj
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

class Inner
{
  public:
    ~Inner();
    int unk00;
    int unk04;
    int unk08;
};

class LockBase
{
  public:
    ~LockBase();
    int m_00;
    Inner m_04;
};

inline LockBase::~LockBase()
{}

class SixIntegerRecord
{
  public:
    ~SixIntegerRecord()
    {
        DeleteCriticalSection(&m_cs00);
    }
    int m_cs00;
    int m_cs04;
    int m_cs08;
    int m_cs0c;
    int m_cs10;
    int m_cs14;
};

class FUN_009fabb0 : public LockBase, public SixIntegerRecord
{
  public:
    ~FUN_009fabb0();
    int m_28;
    int m_2c;
    void* m_hHandle;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    ComObj* m_pkCom;
};

// Closes m_hHandle via CloseHandle and releases m_pkCom via Release if either is non-null.
// @fnv 0x009fabb0
FUN_009fabb0::~FUN_009fabb0()
{
    if (m_hHandle)
        CloseHandle(m_hHandle);
    if (m_pkCom)
        m_pkCom->Release();
}
}  // namespace fnv_009fabb0

namespace fnv_009fac30 {
extern int DAT_01093bbc;
extern int DAT_01093bac;

int __stdcall GetObjectPointer(int* a, int b);

struct InterfaceOwner
{
    int unk00;
    int unk04;
    int unk08;
    int interface0c;
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
    int interfaceEnabled5c;
};

// Tests b against DAT_01093bbc then DAT_01093bac with FUN_009f9980, then calls FUN_009fcf10 or FUN_009fceb0 depending on the results and interfaceEnabled5c.
// @fnv 0x009fac30
void __stdcall FUN_009fac30(int a, int b, int c)
{
    int result = FUN_009f9980(b, &DAT_01093bbc);
    InterfaceOwner* obj = (InterfaceOwner*)a;

    if (result == 0)
    {
        result = FUN_009f9980(b, &DAT_01093bac);

        if (result == 0 || obj->interfaceEnabled5c == 0)
        {
            FUN_009fcf10((int)obj, b, c);
            return;
        }
    }

    GetObjectPointer(obj ? &obj->interface0c : 0, c);
}
}  // namespace fnv_009fac30

namespace fnv_009fae90 {
#include <windows.h>

struct Packet;
struct PacketCallbacks
{
    void(__stdcall* onIdle)(Packet*);
    void(__stdcall* onStart)(Packet*);
};
struct Packet
{
    PacketCallbacks* callbacks;
    CRITICAL_SECTION criticalSection;
    int unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40;
    int active, delayed;
};
struct Parent
{
    virtual int Operation00();
    virtual int Operation04();
    virtual int Operation08();
    virtual int Operation0c();
    virtual int Operation10();
    virtual int Start();
};
class CriticalSectionGuard
{
    CRITICAL_SECTION* section;

  public:
    explicit CriticalSectionGuard(CRITICAL_SECTION* s) : section(s)
    {
        EnterCriticalSection(section);
    }
    ~CriticalSectionGuard()
    {
        LeaveCriticalSection(section);
    }
};
// Acquires the packet's critical section, marks it active, and either clears a delayed flag or starts the parent and invokes the onStart callback.
// @fnv 0x009fae90
int __stdcall FUN_009fae90(Packet* packet)
{
    CRITICAL_SECTION* section =
        reinterpret_cast<Parent*>(reinterpret_cast<char*>(packet) - 12) ? &packet->criticalSection : 0;
    CriticalSectionGuard guard(section);
    if (!packet->active)
    {
        packet->active = 1;
        if (packet->delayed)
        {
            packet->delayed = 0;
        }
        else
        {
            int result = reinterpret_cast<Parent*>(reinterpret_cast<char*>(packet) - 12)->Start();
            if (result < 0)
            {
                packet->active = 0;
                goto return_error;
            }
            packet->callbacks->onStart(packet);
            return 0;
        return_error:
            return result;
        }
    }
    return 0;
}
}  // namespace fnv_009fae90

namespace fnv_009fe690 {
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle,
                                                                             unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);

struct AsyncCritSec
{
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
    void Lock()
    {
        EnterCriticalSection(this);
    }
    void Unlock()
    {
        LeaveCriticalSection(this);
    }
};

struct AsyncAutoLock
{
    AsyncCritSec* m_pLock;
    AsyncAutoLock(AsyncCritSec* plock)
    {
        m_pLock = plock;
        m_pLock->Lock();
    }
    ~AsyncAutoLock()
    {
        m_pLock->Unlock();
    }
};

struct AsyncEvent
{
    void* m_hEvent;
    int Set()
    {
        return SetEvent(m_hEvent);
    }
    int Wait(unsigned long dwTimeout = 0xffffffff)
    {
        return WaitForSingleObject(m_hEvent, dwTimeout) == 0;
    }
};

struct AsyncRequest;

struct AsyncIo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    AsyncCritSec m_csLists;
    int m_bFlushing;
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
    AsyncEvent m_evDone;
    int m_cItemsOut;
    int m_bWaiting;
    AsyncEvent m_evAllDone;

    AsyncRequest* GetWorkItem();
    long PutDoneItem(AsyncRequest* pRequest);
    long FUN_009fe690();
};

// Drains all pending work items into done state, then waits on m_evAllDone until m_cItemsOut reaches zero before signalling m_evDone.
// @fnv 0x009fe690
long AsyncIo::FUN_009fe690()
{
    {
        AsyncAutoLock lock(&m_csLists);

        m_bFlushing = 1;

        AsyncRequest* preq;
        while ((preq = GetWorkItem()) != 0)
        {
            PutDoneItem(preq);
        }

        if (m_cItemsOut > 0)
        {
            m_bWaiting = 1;
        }
        else
        {
            m_evDone.Set();
            return 0;
        }
    }

    for (;;)
    {
        m_evAllDone.Wait();
        {
            AsyncAutoLock lock(&m_csLists);

            if (m_cItemsOut == 0)
            {
                m_bWaiting = 0;
                m_evDone.Set();
                return 0;
            }
        }
    }
}
}  // namespace fnv_009fe690

struct S009faf50_CritSec_009faf50
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

class S009faf50_FUN_009faf50_rec;

class S009faf50_FUN_009faf50_obj
{
  public:
    int unk00;
    int unk04;
    void(__thiscall* m_08)(S009faf50_FUN_009faf50_obj* self, S009faf50_FUN_009faf50_rec* arg);
};

class S009faf50_FUN_009faf50_base
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    int unk04;
    int unk08;
    void unk_fae70();
};

class S009faf50_FUN_009faf50_rec
{
  public:
    S009faf50_FUN_009faf50_obj* m_00;
    S009faf50_CritSec_009faf50 m_cs;
    int unk1c;
    int m_20;
    int unk24;
    int unk28;
    int unk2c;
    int m_30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int m_44;
    int m_48;
};

class S009faf50_FUN_009faf50_owner : public S009faf50_FUN_009faf50_base, public S009faf50_FUN_009faf50_rec
{
};

class S009faf50_CSGuard5
{
  public:
    S009faf50_CritSec_009faf50* m_cs;
    S009faf50_CSGuard5(S009faf50_CritSec_009faf50* cs)
    {
        m_cs = cs;
        EnterCriticalSection(m_cs);
    }
    ~S009faf50_CSGuard5()
    {
        LeaveCriticalSection(m_cs);
    }
};

// @fnv 0x009faf50
int __stdcall FUN_009faf50(S009faf50_FUN_009faf50_rec* self)
{
    int ok = 0;
    {
        S009faf50_CSGuard5 guard(((char*)self - 0xc) != 0 ? &self->m_cs : 0);
        if (self->m_44 == 0 && self->m_48 == 0)
        {
            return 0;
        }
        int m20 = self->m_20;
        self->m_44 = 0;
        if (m20 < self->m_30)
        {
            self->m_48 = 1;
        }
        else
        {
            self->m_48 = 0;
            ((S009faf50_FUN_009faf50_owner*)((char*)self - 0xc))->v4();
            ok = 1;
        }
        ((S009faf50_FUN_009faf50_owner*)self)->unk_fae70();
    }
    if (ok != 0)
    {
        self->m_00->m_08(self->m_00, self);
    }
    return 0;
}

extern "C" __declspec(dllimport) long __stdcall CoInitialize(void* pvReserved);
extern "C" __declspec(dllimport) void __stdcall CoUninitialize();
extern "C" __declspec(dllimport) void __stdcall CoFreeUnusedLibraries();
extern "C" __declspec(dllimport) long __stdcall CoCreateInstance(const MediaGuid& rclsid, void* pUnkOuter,
                                                                 unsigned long dwClsContext, const MediaGuid& riid,
                                                                 void** ppv);

extern const MediaGuid DAT_0107cb08;
extern const MediaGuid DAT_01093b8c;
int __stdcall WriteRecordSet(int a, void* b, int c);

struct S_009fba40_A
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int v20();
};

// Calls virtual v20 on the object at self-0x10 and returns 1 if it gives 0; otherwise creates a COM object, passes it to WriteRecordSet, releases it, returns 0.
// @fnv 0x009fba40
int __stdcall FUN_009fba40(void* self)
{
    S_009fba40_A* a = (S_009fba40_A*)((char*)self - 0x10);
    int r = a->v20();
    if (r == 0)
        return r + 1;
    CoInitialize(0);
    PinIface* p;
    if (CoCreateInstance(DAT_0107cb08, 0, 1, DAT_01093b8c, (void**)&p) >= 0)
    {
        WriteRecordSet(r, p, 1);
        p->Release();
    }
    CoFreeUnusedLibraries();
    CoUninitialize();
    return 0;
}

// @fnv 0x009fbe40
int __stdcall FUN_009fbe40(MediaEnumerator* self, int delta)
{
    if (delta == 0)
        return 0;
    if (self->source->version() != self->version)
        return 0x80040203;

    self->position += delta;
    EnumMediaType mediaType;
    int result = self->source->getType(self->position - 1, &mediaType) != 0;
    return result;
}

struct S009fe2f0_CS
{
    int m[6];
};

class S009fe2f0_BSAutoCSLock6153
{
  public:
    S009fe2f0_CS* m_pGuardedLock;
    S009fe2f0_BSAutoCSLock6153(S009fe2f0_CS* cs)
    {
        m_pGuardedLock = cs;
        EnterCriticalSection(cs);
    }
    ~S009fe2f0_BSAutoCSLock6153()
    {
        LeaveCriticalSection(m_pGuardedLock);
    }
};

class S009fe2f0_SubProbe38
{
  public:
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
    int Probe();
};

class S009fe2f0_FUN_009fe2f0_cls
{
  public:
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18;
    S009fe2f0_CS m_1c;
    int m_34;
    S009fe2f0_SubProbe38 m_38;
    void* m_68;

    int FUN_009fe2f0();
};

// Locks m_1c, calls m_38.Probe(), resets m_68 event if m_38.m_08 is zero, and returns the probe result.
// @fnv 0x009fe2f0
int S009fe2f0_FUN_009fe2f0_cls::FUN_009fe2f0()
{
    S009fe2f0_BSAutoCSLock6153 lock(&m_1c);
    int hr = m_38.Probe();
    if (m_38.m_08 == 0)
    {
        ResetEvent(m_68);
    }
    return hr;
}

struct AsyncRequestQueue
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* m_pBinaryStream;
    CriticalSection9FE m_csLists;
    int m_bFlushing;
    CBaseList_9fd m_listWork;
    CBaseList_9fd m_listDone;
    void* m_evWork;

    long FUN_009fe7e0(void* request);
};

// @fnv 0x009fe7e0
long AsyncRequestQueue::FUN_009fe7e0(void* request)
{
    S_009fe420_Lock lock(&m_csLists);
    long result;
    if (m_bFlushing != 0)
    {
        result = (long)0x80040227;
    }
    else if (m_listWork.AddNode(request) != 0)
    {
        SetEvent(m_evWork);
        result = ((AsyncIoStandIn*)this)->StartThread();
    }
    else
    {
        result = (long)0x8007000e;
    }
    return result;
}

struct AllocatorSampleDeleteView
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
    virtual ~AllocatorSampleDeleteView();
};
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void*, unsigned long, unsigned long);
inline S9fcc60_Sample* RemoveAllocatorSample(S9fcc60_Alloc* allocator)
{
    S9fcc60_Sample* node = allocator->m_lFree;
    if (node)
    {
        allocator->m_lFree = node->m_pNext;
        --allocator->m_lFreeCount;
    }
    return node;
}
// Deletes all free samples from the allocator's free list and releases the underlying buffer via VirtualFree.
// @fnv 0x009fb170
void EntryObject::FUN_009fb170()
{
    S9fcc60_Alloc* self = reinterpret_cast<S9fcc60_Alloc*>(this);
    S9fcc60_Sample* node;
    while ((node = RemoveAllocatorSample(self)) != 0)
    {
        delete reinterpret_cast<AllocatorSampleDeleteView*>(node);
    }
    void* mem = self->m_pBuffer;
    self->m_lAllocated = 0;
    if (mem != 0)
    {
        VirtualFree(mem, 0, 0x8000);
        self->m_pBuffer = 0;
    }
}

// @fnv 0x009fb650
int __stdcall FUN_009fb650(FltMediaFilter* self, void** pClock)
{
    if (pClock == 0)
    {
        return 0x80004003;
    }
    FltBaseFilter* filter = (FltBaseFilter*)((char*)self - 0xc);
    FltAutoLock lock(filter->m_pLock);
    if (filter->m_pClock != 0)
    {
        ((IUnknownFD4*)filter->m_pClock)->AddRef();
    }
    *pClock = filter->m_pClock;
    return 0;
}

struct FUN_009fc600_30
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    FUN_009fc600_30(SourceObj*, ResultRec*);
};
// @fnv 0x009fcdc0
int __stdcall FUN_009fcdc0(int a, FUN_009fc600** out)
{
    if (!out)
        return 0x80004003;
    FUN_009fc600* p = (FUN_009fc600*)new FUN_009fc600_30((SourceObj*)(a - 0xc), 0);
    *out = p;
    return p ? 0 : 0x8007000e;
}

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForMultipleObjects(unsigned long nCount,
                                                                                void* const* lpHandles, int bWaitAll,
                                                                                unsigned long dwMilliseconds);

class AsyncIoWait : public S_009fe420_Cls
{
  public:
    void* stopEvent;
    int FUN_009fe500();
};

// Waits on stopEvent and unk68 until stopEvent signals, calling ProcessItems on each wake-up, then returns 0.
// @fnv 0x009fe500
int AsyncIoWait::FUN_009fe500()
{
    void* handles[2];
    handles[0] = stopEvent;
    handles[1] = (void*)unk68;
    while (WaitForMultipleObjects(2, handles, 0, 0xFFFFFFFF) == 1)
    {
        ProcessItems();
    }
    return 0;
}

// @fnv 0x009fbab0
int __stdcall FUN_009fbab0(void* self)
{
    S_009fba40_A* a = (S_009fba40_A*)((char*)self - 0x10);
    int r = a->v20();
    if (r == 0)
        return r + 1;
    CoInitialize(0);
    long hr;
    C9FB250Unknown* p;
    hr = CoCreateInstance(DAT_0107cb08, 0, 1, DAT_01093b8c, (void**)&p);
    if (hr >= 0)
    {
        hr = WriteRecordSet(r, p, 0);
        p->Release();
    }
    CoFreeUnusedLibraries();
    CoUninitialize();
    return hr == 0x80070002 ? 0 : hr;
}

struct ResetMediaType_009fc390
{
    void FUN_009f9a30();
};
struct PinConnectionView_009fc390
{
    int refCount;
    int mode04;
    int mode08;
    int connected;
    int flags10;
    int* lock;
    int data18;
    int data1c;
    int data20;
    int data24;
    S_009f9bb0_Rec mediaType;
};

// @fnv 0x009fc390
int __stdcall FUN_009fc390(PinConnectionView_009fc390* owner, S_009f9bb0_Rec* target)
{
    if (!target)
        return 0x80004003;

    PinCritSecLock guard(owner->lock);
    if (owner->connected != 0)
    {
        FUN_009f9bb0(target, &owner->mediaType);
        return 0;
    }

    reinterpret_cast<ResetMediaType_009fc390*>(target)->FUN_009f9a30();
    return 0x80040209;
}

struct S009fd3c0_FUN_009fa1f0_class
{
    void FUN_009fa1f0();
};

// Stores four data pointers at offsets 0, 8, 0x14 and 0x18, then calls FUN_009fa1f0 on the subobject at offset 8.
// @fnv 0x009fd3c0
__declspec(noinline) void FUN_009fddd0_class::FUN_009fd3c0()
{
    char* base = reinterpret_cast<char*>(this);

    *reinterpret_cast<int*>(base) = reinterpret_cast<int>(&DAT_01093e24);
    *reinterpret_cast<int*>(base + 8) = reinterpret_cast<int>(&DAT_01093de8);
    *reinterpret_cast<int*>(base + 0x14) = reinterpret_cast<int>(&DAT_01093d9c);
    *reinterpret_cast<int*>(base + 0x18) = reinterpret_cast<int>(&DAT_01093d84);

    return reinterpret_cast<S009fd3c0_FUN_009fa1f0_class*>(base + 8)->FUN_009fa1f0();
}

struct ReleaseWakeCall
{
    void FUN_009fae70();
};

struct Lk_Outer
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
};
struct Lk_Item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    Lk_Item* next;
};
struct Lk_Owner
{
    void* vtbl;
    int cs00;
    int cs04;
    int cs08;
    int cs0c;
    int cs10;
    int cs14;
    Lk_Item* head;
    int count;
    int unk24;
    void* p28;
    int p2c;
    int p30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int flag48;
    void* p4c;
};

// Links b at the head of o's list under a critical section, increments count, and when flag48 is set and count equals p30 clears it and calls o's vtable slot 2.
// @fnv 0x009fc480
int __stdcall FUN_009fc480(int apOwner, Lk_Item* apItem)
{
    if (!apItem)
        return 0x80004003;
    Lk_Owner* o = (Lk_Owner*)apOwner;
    int notify = 0;
    int* pCritSec = ((char*)o - 0xc) ? (int*)((char*)o + 4) : 0;
    {
        PinCritSecLock g(pCritSec);
        apItem->next = o->head;
        o->head = apItem;
        o->count += 1;
        if (o->p28)
            ((ReleaseWakeCall*)((char*)o - 0xc))->FUN_009fae70();
        int cnt = o->count;
        if (o->flag48 && cnt == o->p30)
        {
            ((Lk_Outer*)((char*)o - 0xc))->v04();
            o->flag48 = 0;
            notify = 1;
        }
    }
    if (o->p4c)
    {
        void** vt = *(void***)o->p4c;
        ((void(__stdcall*)(void*))vt[3])(o->p4c);
    }
    if (notify)
    {
        void** vt = *(void***)o;
        ((void(__stdcall*)(void*))vt[2])(o);
    }
    return 0;
}

extern void(__stdcall* DAT_00fdf054)(void*);
extern void*(__stdcall* DAT_00fdf0b4)(void*, long, long, char const*);

struct AllocatorInitView
{
    int* __thiscall FUN_009fcee0(int a, int b);
};

struct AllocatorShell_9fcb90 : S9fcc60_Alloc
{
    int __thiscall FUN_009fcb90(int a, int b, int c, int d, int e);
};

// Initializes the allocator by calling FUN_009fcee0, zeroing fields, and optionally allocating a handle via DAT_00fdf0b4.
// @fnv 0x009fcb90
int __thiscall AllocatorShell_9fcb90::FUN_009fcb90(int a, int b, int apError, int d, int e)
{
    S9fcc60_Alloc* fields = this;

    reinterpret_cast<AllocatorInitView*>(this)->FUN_009fcee0(a, b);
    DAT_00fdf054(&fields->m_CritSec);

    int value = e;

    fields->m_lFree = 0;
    fields->m_lFreeCount = 0;
    fields->unk30 = 0;
    fields->unk34 = 0;
    fields->m_lCount = 0;
    fields->m_lAllocated = 0;
    fields->m_lSize = 0;
    fields->m_lAlignment = 0;
    fields->m_lPrefix = 0;
    fields->m_bChanged = 0;
    fields->unk50 = 0;
    fields->unk54 = 0;
    fields->unk58 = 0;
    fields->unk5c = value;

    if (d)
    {
        void* handle = DAT_00fdf0b4(0, 0, 0x7fffffff, 0);
        fields->unk30 = reinterpret_cast<int>(handle);
        if (!handle)
        {
            *reinterpret_cast<int*>(apError) = 0x8007000e;
        }
    }

    return reinterpret_cast<int>(this);
}

extern int DAT_011f3298;

struct ObjectLifetime : FUN_009fce60_class
{
    ObjectLifetime* __thiscall FUN_009fce60(int);
};

// @fnv 0x009fce60
ObjectLifetime* __thiscall ObjectLifetime::FUN_009fce60(int)
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&DAT_011f3298));
    return this;
}

extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void*, int, int, const char*);

struct FUN_009fcfc0_class
{
    void* m_p;
    void* __thiscall FUN_009fcfc0(int a);
};

// @fnv 0x009fcfc0
void* __thiscall FUN_009fcfc0_class::FUN_009fcfc0(int a)
{
    m_p = CreateEventA(0, a, 0, 0);
    return this;
}

struct AsyncReaderMediaStorage : DsBaseFilter
{
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
    MediaType mediaType;
};

struct AsyncPinMediaTypes : AsyncOutputPin
{
    int FUN_009fd4e0(int position, MediaType* output);
};

// For position 0, copies the stored media type into output and returns 0; otherwise returns an error or no-more-items code.
// @fnv 0x009fd4e0
int AsyncPinMediaTypes::FUN_009fd4e0(int position, MediaType* apMediaType)
{
    if (position < 0)
        return 0x80070057;
    if (position > 0)
        return 0x40103;
    if (apMediaType == 0)
        return 0x80004003;
    if (unk98 == 0)
        return 0x8000ffff;
    int (FUN_009f9d10_cls::*copyMediaType)(int) = &FUN_009f9d10_cls::CallAndReturnThis;
    (reinterpret_cast<FUN_009f9d10_cls*>(apMediaType)->*copyMediaType)(
        reinterpret_cast<int>(&reinterpret_cast<AsyncReaderMediaStorage*>(unk98)->mediaType));
    return 0;
}

struct AsyncFlush : S_009fe420_Cls
{
    int FUN_009fe2a0();
};

// Locks unk1C, zeroes unk34, calls DAT_00fdf0d0 or DAT_00fdf1cc on unk6C depending on unk58, then unlocks and returns 0.
// @fnv 0x009fe2a0
int AsyncFlush::FUN_009fe2a0()
{
    unk1C.Lock();
    unk34 = 0;
    if (unk58 > 0)
        DAT_00fdf0d0((void*)unk6C);
    else
        DAT_00fdf1cc((int*)unk6C);
    unk1C.Unlock();
    return 0;
}

namespace MediaTypeConstruction {
struct FUN_009f9c70 : ::MediaType
{
    FUN_009f9c70();
};

// @fnv 0x009f9c70
FUN_009f9c70::FUN_009f9c70()
{
    void (::FUN_009f9a30_class::*const initialize)() = &::FUN_009f9a30_class::FUN_009f9a30;
    (reinterpret_cast< ::FUN_009f9a30_class*>(this)->*initialize)();
}
}

static inline ::BasePinStub* PinOwnerFromInterface(::PinIface* pin)
{
    return reinterpret_cast< ::BasePinStub*>(reinterpret_cast<char*>(pin) - sizeof(::PinUnknownBase));
}

// @fnv 0x009fc300
int __stdcall FUN_009fc300(::PinIface* self)
{
    ::PinCritSecLock lock(PinOwnerFromInterface(self)->m_pLock);
    if (!PinOwnerFromInterface(self)->IsStopped())
    {
        return 0x80040224;
    }
    int(__stdcall* const disconnect)(::FUN_009fa380_cls*) = &::FUN_009fa380;
    return disconnect(reinterpret_cast< ::FUN_009fa380_cls*>(PinOwnerFromInterface(self)));
}

struct FUN_009fc5a0 : FUN_009fcee0
{
    int m14, m18, m1c, m20, m24, m28, m2c, m30, m34, m38, m3c, m40, m44, m48;
    FUN_009fc5a0(int b, int c, int d, int* e, int f);
};

// Initializes a FUN_009fc5a0 object by zeroing several fields, copying four values from e into m28-m34, and storing d in m38.
// @fnv 0x009fc5a0
FUN_009fc5a0::FUN_009fc5a0(int b, int c, int d, int* apIntArray, int f) : FUN_009fcee0(b, c)
{
    m14 = 0;
    m18 = 0;
    m20 = 0;
    m24 = 0;
    m28 = apIntArray[0];
    m2c = apIntArray[1];
    m30 = apIntArray[2];
    m34 = apIntArray[3];
    m38 = d;
    m3c = 0;
    m40 = 0;
    m44 = 0;
    m48 = 1;
}
