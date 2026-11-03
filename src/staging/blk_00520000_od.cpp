
// src/staging/blk_00520000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_005224c0_Class
{
    unsigned int __thiscall GetField22C();
};

// @fnv 0x005224c0
unsigned int __thiscall FUN_005224c0_Class::GetField22C()
{
    return *(unsigned int*)((char*)this + 0x22c);
}

struct FUN_005224e0_class
{
    unsigned int GetField230();
};

// @fnv 0x005224e0
unsigned int FUN_005224e0_class::GetField230()
{
    return *(unsigned int*)((char*)this + 0x230);
}

struct FUN_00524b40_class
{
    bool FUN_00524b40();
};

// @fnv 0x00524b40
bool FUN_00524b40_class::FUN_00524b40()
{
    return reinterpret_cast<unsigned char*>(this)[0x100] & 2;
}

struct FUN_00526ae0_class
{
    float FUN_00526ae0() const;
};

// @fnv 0x00526ae0
float FUN_00526ae0_class::FUN_00526ae0() const
{
    return *(const float*)((const char*)this + 0x28);
}

struct FUN_00527740_class
{
    void __thiscall FUN_00527740();
};

// Clears the int fields at offsets 0x0c and 0x10 and the byte at 0x14 of this object to zero.
// @fnv 0x00527740
void __thiscall FUN_00527740_class::FUN_00527740()
{
    *(int*)((char*)this + 0x0c) = 0;
    *(int*)((char*)this + 0x10) = 0;
    *(char*)((char*)this + 0x14) = 0;
}

struct BSTreeNode;
struct TESObjectREFR;

template <class Key, class Node> struct LockFreeMap
{
    LockFreeMap(unsigned int a, unsigned int b, unsigned int c);
};

struct FUN_00527e30
{
    LockFreeMap<TESObjectREFR*, BSTreeNode*> m;
    FUN_00527e30();
};

// @fnv 0x00527e30
FUN_00527e30::FUN_00527e30() : m(2, 0x25, 0xc)
{}

struct TESQueuedCellManager
{
    void SubmitQueuedItems();
    void FUN_00528540();
};

// @fnv 0x00528540
void TESQueuedCellManager::FUN_00528540()
{
    SubmitQueuedItems();
}

extern "C" int __cdecl sprintf_s(char*, int, const char*, ...);

struct FUN_0052a980_Class
{
    int __thiscall FUN_0052a980(char* dst);
};

// @fnv 0x0052a980
int __thiscall FUN_0052a980_Class::FUN_0052a980(char* pcBuffer)
{
    return sprintf_s(pcBuffer, 0x800, "  Temp");
}

struct FUN_0052d180_cls
{
    void __thiscall FUN_0052d180();
};

void __thiscall FUN_0052d180_cls::FUN_0052d180()
{}

struct FUN_0052d160_cls
{
    void* __thiscall FUN_0052d160();
};

// @fnv 0x0052d160
void* __thiscall FUN_0052d160_cls::FUN_0052d160()
{
    ((FUN_0052d180_cls*)this)->FUN_0052d180();
    return this;
}

struct NiBound
{
    NiBound();
};

NiBound::NiBound()
{}

struct FUN_0052d200
{
    NiBound b;
    FUN_0052d200();
};

// @fnv 0x0052d200
FUN_0052d200::FUN_0052d200()
{}

struct FUN_0052d240_obj
{
    ~FUN_0052d240_obj();
};

struct FUN_0052d220_obj : public FUN_0052d240_obj
{
    void DestroyBase();
};

// @fnv 0x0052d220
void FUN_0052d220_obj::DestroyBase()
{
    FUN_0052d240_obj::~FUN_0052d240_obj();
}

struct NiObjectNET
{
    void FUN_00439360(unsigned short a, unsigned int b, unsigned int c);
    void FUN_00533fb0(unsigned short a);
};

// @fnv 0x00533fb0
void NiObjectNET::FUN_00533fb0(unsigned short a)
{
    FUN_00439360(a, 0xe, 1);
}

struct FUN_008256d0_shell_base
{
    bool FUN_008256d0();
};
struct FUN_00537b50_shell
{
    bool FUN_00537b50();
};
// Returns the negation of the result of calling FUN_008256d0 on the object at this+0xac.
// @fnv 0x00537b50
bool FUN_00537b50_shell::FUN_00537b50()
{
    return !reinterpret_cast<FUN_008256d0_shell_base*>(reinterpret_cast<char*>(this) + 0xac)->FUN_008256d0();
}

struct Base537
{
    void FUN_00537bb0();
    Base537* FUN_00537b80();
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    float m_iThirdValue;
};

// @fnv 0x00537b80
Base537* Base537::FUN_00537b80()
{
    FUN_00537bb0();
    m_8 = 0;
    m_iThirdValue = 1.0f;
    return this;
}

struct GO
{
    GO& operator=(void*);
};

struct FUN_00539f20_Class
{
    GO m;
    void FUN_00539f20(void*);
};

// @fnv 0x00539f20
void FUN_00539f20_Class::FUN_00539f20(void* p)
{
    ((GO*)((char*)this + 0xd0))->operator=(p);
}

extern "C" void* __cdecl NiFreeAlias(void*);
extern void* DAT_0102cfa0;

struct FUN_005278a0
{
    void* vtbl;
    void* a;
    void* b;
    void DoIt();
};

// Sets the vtable to DAT_0102cfa0, clears the map via RemoveAll, then frees b with NiFreeAlias.
// @fnv 0x005278a0
void FUN_005278a0::DoIt()
{
    vtbl = &DAT_0102cfa0;
    ((NiTPointerMap<int, int>*)this)->RemoveAll();
    NiFreeAlias(b);
}

void __cdecl FUN_0040fca0(unsigned long);

struct FUN_005289b0_Class
{
    int m_field00;
    int m_field04;
    int m_field08;
    int m_field0c;
    void __thiscall FUN_005289b0(void* p);
};

// Loops calling FUN_0040fca0(0) while the object's m_field0c is 3 or 5.
// @fnv 0x005289b0
void __thiscall FUN_005289b0_Class::FUN_005289b0(void* pObject)
{
    while (((FUN_005289b0_Class*)pObject)->m_field0c == 3 || ((FUN_005289b0_Class*)pObject)->m_field0c == 5)
        FUN_0040fca0(0);
}

void __cdecl Deallocate(void* p);
struct FUN_00526ef0_Class
{
    void __thiscall FUN_00526d50();
    void* __thiscall Destroy(unsigned int flags);
};
// Calls FUN_00526d50, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00526ef0
void* FUN_00526ef0_Class::Destroy(unsigned int flags)
{
    FUN_00526d50();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_005277a0_Class
{
    void __thiscall FUN_00527840();
    void* FUN_005277a0(unsigned int flags);
};

// Calls FUN_00527840, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x005277a0
void* FUN_005277a0_Class::FUN_005277a0(unsigned int flags)
{
    FUN_00527840();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl operator delete(void*);
struct FUN_00528be0_Class
{
    void __thiscall FUN_00528be0();
};
struct FUN_00528e10_Class
{
    void* __thiscall FUN_00528e10(unsigned int flags);
};
// @fnv 0x00528e10
void* __thiscall FUN_00528e10_Class::FUN_00528e10(unsigned int flags)
{
    ((FUN_00528be0_Class*)this)->FUN_00528be0();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_00529330_Class
{
    void __thiscall FUN_00529330();
};
struct FUN_00529300_Class
{
    void* __thiscall FUN_00529300(unsigned int flags);
};
// Calls FUN_00529330 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00529300
void* __thiscall FUN_00529300_Class::FUN_00529300(unsigned int flags)
{
    ((FUN_00529330_Class*)this)->FUN_00529330();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_005293c0_Class
{
    void __thiscall FUN_0044f420();
    void* __thiscall FUN_005293c0(unsigned int flags);
};
// @fnv 0x005293c0
void* __thiscall FUN_005293c0_Class::FUN_005293c0(unsigned int flags)
{
    FUN_0044f420();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct GameTimerRecord
{
    int GetSection();
};
extern GameTimerRecord g_timeGlobal;
struct TESSound
{
    unsigned int Deallocate();
};
struct MapH
{
    bool RemoveAt(unsigned int);
};
struct FUN_00526c40_Class
{
    bool RemoveSound(TESSound*);
};
// @fnv 0x00526c40
bool FUN_00526c40_Class::RemoveSound(TESSound* apSound)
{
    if (((MapH*)this)->RemoveAt(apSound->Deallocate()))
    {
        --(*(unsigned int*)((char*)this + 0x10));
        *(int*)((char*)this + 0x14) = g_timeGlobal.GetSection();
        return true;
    }
    return false;
}

struct BGSLoadedReferenceCollection;
extern BGSLoadedReferenceCollection* DAT_011c95c8;
// @fnv 0x00526eb0
void FUN_00526eb0()
{
    FUN_00526ef0_Class* b;
    FUN_00526ef0_Class* a;
    void* c;
    b = (FUN_00526ef0_Class*)DAT_011c95c8;
    a = b;
    if (a)
        c = a->Destroy(1);
    else
        c = 0;
    DAT_011c95c8 = 0;
}

struct FUN_005271b0_Class
{
    char m_auiShapeKeys[0x48];
    char m_field48;
    char m_field70;
    char* __thiscall GetFieldByType(unsigned int type);
};

// Returns a pointer to the member at offset 0x48 for type 0x29 or at offset 0x30 for type 0x28, otherwise null.
// @fnv 0x005271b0
char* __thiscall FUN_005271b0_Class::GetFieldByType(unsigned int type)
{
    switch (type)
    {
    case 0x29:
        return (char*)this + 0x48;
    case 0x28:
        return (char*)this + 0x30;
    default:
        return 0;
    }
}

struct InventoryStackRecord
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    InventoryStackRecord();
};
struct FUN_00527270 : public InventoryStackRecord
{
    int m_iThirdValue;
    int m_10;
    unsigned char m_14;
    FUN_00527270();
};
// @fnv 0x00527270
FUN_00527270::FUN_00527270()
{
    m_iThirdValue = 0;
    m_10 = 0;
    m_14 = 0;
}

namespace fnv_00527350 {
struct BGSLoadedReferenceCollection;
struct MapX
{
    void* GetFirstPos();
};
struct ScriptS
{
    void* GetHeader();
};
extern BGSLoadedReferenceCollection* DAT_011c95c8;
struct FUN_005271b0_Class
{
    void* __thiscall GetFieldByType(void*);
};
struct FUN_00527350
{
    void* vtbl;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    char f34;
    void FUN_00527350_Init();
};
// Clears f10, f14 and f34, resolves fc from DAT_011c95c8 (falling back to GetHeader), then stores GetFirstPos() into f18.
// @fnv 0x00527350
void FUN_00527350::FUN_00527350_Init()
{
    f10 = 0;
    f14 = 0;
    f34 = 0;
    fc = (int)((FUN_005271b0_Class*)DAT_011c95c8)->GetFieldByType(vtbl);
    if (!fc)
        fc = (int)((ScriptS*)DAT_011c95c8)->GetHeader();
    f18 = (int)((MapX*)fc)->GetFirstPos();
}
}  // namespace fnv_00527350

struct FUN_005277d0_Class
{
    void* vtbl;
    unsigned int size;
    void* data;
    void* next;
    FUN_005277d0_Class* __thiscall InitBuffer(unsigned int size);
};
void* __cdecl NiMalloc(unsigned int size);
void* __cdecl memset(void* dst, int value, unsigned int count);
// Sets the vtable, stores size, clears next, allocates size*4 bytes with NiMalloc, zeroes them, and returns this.
// @fnv 0x005277d0
FUN_005277d0_Class* __thiscall FUN_005277d0_Class::InitBuffer(unsigned int size)
{
    vtbl = &DAT_0102cfa0;
    this->size = size;
    next = 0;
    unsigned int uiByteCount = this->size * 4;
    data = NiMalloc(uiByteCount);
    memset(data, 0, this->size * 4);
    return this;
}

void __cdecl _Deallocate(void*);
struct FUN_005278d0_Class
{
    void* __thiscall FUN_005278d0(unsigned int flags);
};
// Calls DoIt on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x005278d0
void* __thiscall FUN_005278d0_Class::FUN_005278d0(unsigned int flags)
{
    ((FUN_005278a0*)this)->DoIt();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct IOTask
{
    virtual void __thiscall Dummy();
    IOTask(int a);
    char _pad[20];
};
struct FUN_00527c00 : public IOTask
{
    int m_18;
    int m_1c;
    FUN_00527c00(int a, int b);
};
// Initializes the IOTask base with 0 and stores the two constructor arguments into m_18 and m_1c.
// @fnv 0x00527c00
FUN_00527c00::FUN_00527c00(int aiValue18, int aiValue1c) : IOTask(0)
{
    m_18 = aiValue18;
    m_1c = aiValue1c;
}

struct Caller27f90
{
    void* __thiscall FUN_00527f90(unsigned int flags);
};
extern TESQueuedCellManager* DAT_011c9618;
// If the global TESQueuedCellManager exists, calls its FUN_00527f90 with flags 1 and clears the global pointer.
// @fnv 0x00527f40
void __cdecl FUN_00527f40()
{
    TESQueuedCellManager* pManager;
    TESQueuedCellManager* pManagerCopy;
    if (DAT_011c9618)
    {
        void* r;
        pManager = DAT_011c9618;
        pManagerCopy = pManager;
        if (pManagerCopy)
            r = ((Caller27f90*)pManagerCopy)->FUN_00527f90(1);
        else
            r = 0;
        DAT_011c9618 = 0;
    }
}

struct FUN_00527f90_Holder
{
    void __thiscall FUN_00527e50();
    void* __thiscall FUN_00527f90(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_00527e50, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00527f90
void* __thiscall FUN_00527f90_Holder::FUN_00527f90(unsigned int flags)
{
    FUN_00527e50();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct RecursiveSpinLock
{
    void __thiscall Lock(const char*);
    void __thiscall Unlock();
};
struct FUN_00449f80_Class
{
    void* __thiscall FUN_00449f80(void* a, void* b, unsigned char c);
};
struct FUN_0044c000_Class
{
    unsigned char __thiscall FUN_0044c000();
};
struct FUN_00528b60_Class
{
    unsigned char __thiscall LockedCall(void* a, void* b, unsigned char c);
};
// Locks the object at offset 0x20, calls FUN_00449f80 then FUN_0044c000 on its result, unlocks, and returns that result.
// @fnv 0x00528b60
unsigned char __thiscall FUN_00528b60_Class::LockedCall(void* a, void* b, unsigned char c)
{
    unsigned char r;
    ((RecursiveSpinLock*)((char*)this + 0x20))->Lock(0);
    r = ((FUN_0044c000_Class*)((FUN_00449f80_Class*)this)->FUN_00449f80(a, b, c))->FUN_0044c000();
    ((RecursiveSpinLock*)((char*)this + 0x20))->Unlock();
    return r;
}

extern int DAT_0102d078;
struct FUN_00528c70_Class
{
    void* vtbl;
    int m_kPointA;
    int m_kPointB;
    char m_iThirdValue;
    FUN_00528c70_Class();
};
// Initializes the object's vtable pointer and zeroes its three data members.
// @fnv 0x00528c70
FUN_00528c70_Class::FUN_00528c70_Class()
{
    vtbl = &DAT_0102d078;
    m_kPointA = 0;
    m_kPointB = 0;
    m_iThirdValue = 0;
}

struct FUN_0052cfc0_Rect
{
    int v0;
    int v1;
    int v2;
    int v3;
};
struct FUN_0052cfc0_Class
{
    int pad;
    FUN_0052cfc0_Rect rect;
    void __thiscall FUN_0052cfc0(FUN_0052cfc0_Rect* p);
};
// Copies the four ints of the passed rect into this object's rect field.
// @fnv 0x0052cfc0
void __thiscall FUN_0052cfc0_Class::FUN_0052cfc0(FUN_0052cfc0_Rect* apRect)
{
    rect = *apRect;
}

template <int N> struct EndianSizeTag
{
};

void __cdecl BSEndian(unsigned char*, EndianSizeTag<0>);
void __cdecl BSEndian(unsigned short*, EndianSizeTag<1>);

struct FUN_00535aa0_Class
{
    void __thiscall FUN_00535aa0();
};

// @fnv 0x00535aa0
void __thiscall FUN_00535aa0_Class::FUN_00535aa0()
{
    BSEndian((unsigned char*)this, EndianSizeTag<0>());
    BSEndian((unsigned short*)((char*)this + 4), EndianSizeTag<1>());
}

struct CallCls537
{
    void __thiscall FUN_004b5020();
};
struct Cl537
{
    int m_iWordAt00;
    int m_iWordAt04;
    Cl537* __thiscall FUN_00537bb0();
};
// @fnv 0x00537bb0
Cl537* __thiscall Cl537::FUN_00537bb0()
{
    ((CallCls537*)this)->FUN_004b5020();
    m_iWordAt04 = 0;
    return this;
}

struct FUN_00527e30_Alloc
{
    char m[0x40];
    FUN_00527e30_Alloc();
};
// @fnv 0x00527eb0
void __cdecl InitQueuedCellManager()
{
    if (!DAT_011c9618)
        DAT_011c9618 = (TESQueuedCellManager*)new FUN_00527e30_Alloc;
}

struct FUN_005285c0_Class
{
    void* __thiscall FUN_005285c0(void* a, void* b, void* c);
};
// Allocates a 0x14-byte object storing a, b and c in its first three fields, zeroing the byte at 0x10 and the int at 0xC, and returns it or null if a is null.
// @fnv 0x005285c0
void* FUN_005285c0_Class::FUN_005285c0(void* a, void* b, void* c)
{
    void* p = 0;
    if (a)
    {
        void* t = operator new(0x14);
        p = t;
        ((void**)p)[2] = a;
        ((void**)p)[0] = b;
        ((void**)p)[1] = c;
        ((char*)p)[0x10] = 0;
        ((int*)p)[3] = 0;
    }
    return p;
}

extern unsigned int _data_011c16bc;

struct AutoMemHelper
{
    int m_auiShapeKeys;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};

struct FUN_00526c90
{
    unsigned char m_auiShapeKeys[0xc0];
    FUN_00526c90();
};

void* __cdecl operator new(unsigned int);

// @fnv 0x00526e10
void FUN_00526e10()
{
    AutoMemHelper context(
        0x2c, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\BGSLoadedReferenceCollection.cpp", 0x58);

    DAT_011c95c8 = reinterpret_cast<BGSLoadedReferenceCollection*>(new FUN_00526c90);
}

struct FUN_005272b0_ItemChange
{
    void __thiscall dtor();
};

struct FUN_005272b0_Class
{
    void __thiscall ClearAndDestroy();
};

// @fnv 0x005272b0
void FUN_005272b0_Class::ClearAndDestroy()
{
    *(void**)this = 0;
    reinterpret_cast<FUN_005272b0_ItemChange*>(this)->dtor();
}

struct FUN_005285a0_Class
{
    virtual void __thiscall v0();
    virtual void __thiscall v1();
    virtual void __thiscall v2();
    virtual void __thiscall v3();
    virtual void __thiscall v4();
    virtual void __thiscall v5();
    virtual void __thiscall v6();
    virtual void __thiscall v7();
    virtual void __thiscall v8();
    virtual void __thiscall v9();
    virtual void __thiscall v10();
    virtual void __thiscall v11();
    virtual void __thiscall v12();
    virtual void __thiscall v13();
    virtual void __thiscall v14();
    virtual void __thiscall v15();
    virtual void __thiscall CallVirtual17();
};
// @fnv 0x005285a0
void __thiscall FUN_005285a0_Class::CallVirtual17()
{
    ((void(__thiscall*)(void*))(*(void***)this)[17])(this);
}

class Sub24_b5481
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    ~Sub24_b5481();
};

class FUN_00526d50_cls
{
  public:
    Sub24_b5481 m_00;
    Sub24_b5481 m_18;
    Sub24_b5481 m_30;
    Sub24_b5481 m_48;
    Sub24_b5481 m_60;
    Sub24_b5481 m_78;
    Sub24_b5481 m_90;
    Sub24_b5481 m_a8;
    ~FUN_00526d50_cls();
};

// Destructor for the class; destroys its eight Sub24_b5481 members in reverse order.
// @fnv 0x00526d50
FUN_00526d50_cls::~FUN_00526d50_cls()
{}

struct C5271F0Change
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned char unk14;

    C5271F0Change();
    ~C5271F0Change();
};

struct FUN_005271f0
{
    int m_iOwner;
    int m_iArrayLength;
    int m_iType;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    C5271F0Change m_kChange;

    FUN_005271f0(int owner, int type);
    void Reset();
};

// @fnv 0x005271f0
FUN_005271f0::FUN_005271f0(int owner, int type) : m_iOwner(owner), m_iArrayLength(0), m_iType(type)
{
    Reset();
}

// The game object whose byte at +4 is read by FUN_00401170 (a plain __thiscall
// member of the game's own shell class, so a stand-in with the same shape is
// enough: the call is ECX-based and its result is a plain int).
struct FNV_FormType
{
    unsigned char unk04;
    int GetFormType();
};

// The sub-object that lives at +0x1c of the complete object.  It owns a
// non-trivial destructor, which is what gives the constructor its exception
// frame and the single state transition (0 -> -1) around the body.
struct FNV_Sub5272d0
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    unsigned char m_14;
    FNV_Sub5272d0();
    ~FNV_Sub5272d0();
};

struct FUN_005272d0_Class
{
    int m_00;
    FNV_FormType* m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    FNV_Sub5272d0 m_1c;
    unsigned char m_34;
    ~FUN_005272d0_Class();
    FUN_005272d0_Class(FNV_FormType* p, int q);
    void FUN_00527350();
};

// Constructor initializes m_00 from p->GetFormType(), stores p and q, then calls FUN_00527350.
// @fnv 0x005272d0
FUN_005272d0_Class::FUN_005272d0_Class(FNV_FormType* apForm, int q) : m_00(apForm->GetFormType()), m_04(apForm), m_08(q)
{
    FUN_00527350();
}

class Base_b9015
{
  public:
    virtual ~Base_b9015();
    unsigned int unk04;
    unsigned int unk08;
};

class Cleanup_b9015
{
  public:
    void Cleanup();
};

class FUN_00527840 : public Base_b9015
{
  public:
    virtual ~FUN_00527840();
    void DoCleanup();
};

// Destructor for FUN_00527840 that calls DoCleanup().
// @fnv 0x00527840
FUN_00527840::~FUN_00527840()
{
    DoCleanup();
}

struct FUN_00528be0
{
    ~FUN_00528be0();
};

struct FUN_00527e50 : FUN_00528be0
{
    void SubmitQueuedItems();
    ~FUN_00527e50();
};

// @fnv 0x00527e50
FUN_00527e50::~FUN_00527e50()
{
    SubmitQueuedItems();
}

struct FUN_005287e0_Class
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    unsigned char FUN_005287e0();
};
struct Query
{
    void* vtbl;
    int m_kPointA;
    int m_kPointB;
    char m_iThirdValue;
    Query();
    ~Query();
    unsigned char FUN_006ebde0();
};
struct Handle
{
    FUN_005287e0_Class* value;
    Handle(int);
    ~Handle();
    FUN_005287e0_Class* FUN_00559450();
};
struct Controller
{
    unsigned char AdvanceRequest(Query*, unsigned int*, Handle*, unsigned int);
    void ProcessQueries();
};
// Loops over queries until one finishes, and for each successful query whose handle value passes a check, calls its v5 method.
// @fnv 0x00528110
void Controller::ProcessQueries()
{
    Query query;
    while (!query.FUN_006ebde0())
    {
        unsigned int x = 0;
        Handle y(0);
        if (AdvanceRequest(&query, &x, &y, 1))
        {
            if (y.FUN_00559450()->FUN_005287e0())
            {
                y.FUN_00559450()->v5();
            }
        }
    }
}

struct Holder_cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    bool FUN_005287e0();
};

struct Local_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    Local_cls();
    ~Local_cls();
    bool FUN_006ebde0();
};

struct Obj20_cls
{
    int m_00;
    Obj20_cls(int a);
    ~Obj20_cls();
    Holder_cls* FUN_00559450();
};

extern FUN_005289b0_Class* DAT_01202d98;

struct FUN_005282d0_cls
{
    void FUN_005282d0();
    bool AdvanceRequest(Local_cls* a, int* b, Obj20_cls* o, int f);
};

// @fnv 0x005282d0
void FUN_005282d0_cls::FUN_005282d0()
{
    Local_cls a;
    while (!a.FUN_006ebde0())
    {
        int b = 0;
        Obj20_cls o4(0);
        if (AdvanceRequest(&a, &b, &o4, 1))
        {
            DAT_01202d98->FUN_005289b0(o4.FUN_00559450());
            if (o4.FUN_00559450()->FUN_005287e0())
            {
                o4.FUN_00559450()->v5();
            }
        }
    }
}

namespace fnv_005283c0 {
struct TESObjectCELL;

struct QWorldSpace
{
    TESObjectCELL* GetCellAt(int x, int y);
};

class TES
{
  public:
    bool IsCellLoadedQ(TESObjectCELL* cell);
    void HandleLoadedCellQ(TESObjectCELL* cell);
};
extern TES* g_TES;

struct QIOTask
{
    virtual void v0();
    QIOTask(int a);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct QCellTask : public QIOTask
{
    int m_18;
    int m_1c;
    QCellTask(int a, int b);
};

struct QTaskPtr
{
    QIOTask* p;
    QTaskPtr(QIOTask* t);
    ~QTaskPtr();
    operator QIOTask*() const;
};

class IOManager
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
    virtual void AddTask(QIOTask* task);
};
extern IOManager* DAT_01202d98;

int __cdecl TESWorldSpace_GetKeyForCellCoord(short x, short y);

struct QCellQueue
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool Insert(int key, QTaskPtr* ptr, int flag);
    bool IsQueuedQ(int x, int y);
    void* MakeEntryQ(QWorldSpace* ws, int x, int y);
    void FUN_005283c0(QWorldSpace* ws, int x, int y);
};

// @fnv 0x005283c0
void QCellQueue::FUN_005283c0(QWorldSpace* ws, int x, int y)
{
    if (!ws)
        return;
    TESObjectCELL* cellVal = ws->GetCellAt(x, y);
    if (cellVal && g_TES->IsCellLoadedQ(cellVal))
    {
        g_TES->HandleLoadedCellQ(cellVal);
        return;
    }
    if (IsQueuedQ(x, y))
        return;
    void* entry7 = MakeEntryQ(ws, x, y);
    if (entry7)
    {
        QTaskPtr ptr(new QCellTask((int)this, (int)entry7));
        int key = TESWorldSpace_GetKeyForCellCoord((unsigned short)x, (unsigned short)y);
        bool ok6 = Insert(key, &ptr, 1);
        DAT_01202d98->AddTask(ptr);
    }
}
}  // namespace fnv_005283c0

extern const char kThreadSafeStructuresSourceFile[];

class AutoMemContext
{
  public:
    int unk00;
    AutoMemContext(MEM_CONTEXT aeMemoryContext, bool bPush, const char* pFile, int iLine);
    ~AutoMemContext();
};

struct QueuedRefPtr
{
    void* p;
    QueuedRefPtr& operator=(void* rhs);
};

struct NodeLink
{
    void* p;
    int Get();
    void Clear();
};

struct QueuedNode
{
    int unk00;
    QueuedRefPtr ref;
    NodeLink next;
};

struct QueuedOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    QueuedOwner(int data);
    ~QueuedOwner();
    int GetData();
};

struct QueuedMap
{
    int unk00;
    int unk04;
    unsigned int bucketCount;
    NodeLink* buckets;
    int unk10;
    QueuedOwner* owner;
    int count;
    int unk1C;
    RecursiveSpinLock lock;

    void FreeNode(QueuedNode* node);
    void FUN_00528e40(bool abFreeNodes);
};

// Under a task-overhead memory context, locks the map, deletes the owner, frees all bucket nodes, and optionally recreates the owner with the saved data.
// @fnv 0x00528e40
void QueuedMap::FUN_00528e40(bool abFreeNodes)
{
    AutoMemContext kMemContext(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true, kThreadSafeStructuresSourceFile, 0x42c);
    if (owner == 0)
        return;
    lock.Lock(0);
    int data = owner->GetData();
    delete owner;
    owner = 0;
    count = 0;
    for (unsigned int i = 0; i < bucketCount; i++)
    {
        QueuedNode* node = (QueuedNode*)buckets[i].Get();
        buckets[i].Clear();
        while (node)
        {
            QueuedNode* nextNode = (QueuedNode*)node->next.Get();
            node->next.Clear();
            node->ref = 0;
            FreeNode(node);
            node = nextNode;
        }
    }
    if (!abFreeNodes)
        owner = new QueuedOwner(data);
    lock.Unlock();
}

struct FloatSettings
{
    unsigned int field_00;
    unsigned int field_04;
    unsigned int field_08;
    unsigned int field_0c;
    unsigned int field_10;
    unsigned int field_14;
    float field_18;
    float field_1c;
    float field_20;
    float field_24;
    float field_28;
    float field_2c;
    float field_30;
    float field_34;
    float field_38;
    float field_3c;
    float field_40;
    float field_44;
    float field_48;
    float field_4c;
    float field_50;
    float field_54;
    float field_58;
    float field_5c;
    float field_60;
    float field_64;
    float field_68;
    float field_6c;
    float field_70;
    float field_74;
    float field_78;
    float field_7c;
    float field_80;
    float field_84;
    float field_88;
    float field_8c;
    float field_90;
    float field_94;
    float field_98;
    void InitDefaults();
};
// Assigns a fixed set of float constants to the fields from field_18 through field_98.
// @fnv 0x0052b780
void FloatSettings::InitDefaults()
{
    field_18 = 0.5f;
    field_1c = 7.0f;
    field_24 = 1.0f;
    field_28 = 1.0f;
    field_2c = 1.0f;
    field_30 = 2.25f;
    field_34 = 0.22499999404f;
    field_38 = 1.0f;
    field_3c = 0.0f;
    field_40 = 0.0f;
    field_44 = 1.5f;
    field_48 = 1.5f;
    field_4c = 1.0f;
    field_20 = 1.0f;
    field_54 = 0.0299999993294f;
    field_5c = 0.20000000298f;
    field_58 = 0.699999988079f;
    field_60 = 0.5f;
    field_64 = 0.5f;
    field_68 = 0.019999999553f;
    field_78 = 2.5f;
    field_6c = 0.209999993443f;
    field_70 = 0.5f;
    field_74 = 0.77999997139f;
    field_88 = 1.0f;
    field_80 = 0.5f;
    field_84 = 1.0f;
    field_7c = 1.0f;
    field_98 = 0.0f;
    field_8c = 1.0f;
    field_90 = 1.0f;
    field_94 = 1.0f;
}

class FUN_00537bf0_base
{
  public:
    virtual ~FUN_00537bf0_base();
    FUN_00537bf0_base();
};

class FUN_00537bf0_sub
{
  public:
    FUN_00537bf0_sub(int a, int b);
    ~FUN_00537bf0_sub();
    void Init();
    unsigned int m_unk00;
    unsigned int m_unk04;
};

class FUN_00537bf0 : public FUN_00537bf0_base
{
  public:
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned short m_iOwnerObjectOffset;
    unsigned int m_unk10;
    unsigned int m_unk14;
    unsigned int m_unk18;
    FUN_00537bf0_sub m_sub;
    FUN_00537bf0(unsigned short id);
    virtual ~FUN_00537bf0();
};

// @fnv 0x00537bf0
FUN_00537bf0::FUN_00537bf0(unsigned short id) : m_sub(0, 1)
{
    m_unk08 = 0;
    m_iOwnerObjectOffset = id;
    m_unk10 = 0;
    m_unk14 = 0;
    m_sub.Init();
    m_unk18 = 0;
}

// FUN_00539f40 : returns the VALUE of a global (mov eax,[0x11f94bc]).
// The module is unoptimised, so the frame is kept even with no locals.
extern int g_00539f40;

// @fnv 0x00539f40
int __cdecl FUN_00539f40()
{
    return g_00539f40;
}

namespace fnv_00526c90 {
struct C90List
{
    C90List();
    ~C90List();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct FUN_00526c90
{
    FUN_00526c90();

    C90List m_kList0;
    C90List m_kList1;
    C90List m_kList2;
    C90List m_kList3;
    C90List m_kList4;
    C90List m_kList5;
    C90List m_kList6;
    C90List m_kList7;
};

// Default constructor; the eight C90List members are constructed implicitly.
// @fnv 0x00526c90
FUN_00526c90::FUN_00526c90()
{}
}  // namespace fnv_00526c90

struct Ref;
struct Form;
struct Changes;
struct Form
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
    virtual bool IsSpecial();
    int FNV_GetFormType();
    bool Accept(Ref*, int, int);
};
struct Ref
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
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
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
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual bool IsExcluded();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool IsActor(int);
    Form* CallGetFlags();
    bool GetDisabled();
    bool GetDeleted();
    bool HasFlag();
    Form* GetAcousticSpace();
    void* FUN_00726070();
    Changes* FUN_005d43c0();
};
struct Changes
{
    struct Entries* GetEntries();
};
struct EntryState
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    void FUN_00527740();
};
struct Entries
{
    bool Next(EntryState*, Ref**, int);
};
struct Map
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    void* GetFirstPos();
    void GetNext(void*&, unsigned int&, Ref*&);
};
struct State
{
    int type;
    Form* filter;
    int context;
    Map* map;
    Ref* current;
    Entries* entries;
    void* pos;
    EntryState state;
    unsigned char stage;
};
struct Collection
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    Map first;
    Map second;
    Map third;
    Map fourth;
    Map fifth;
    bool FindNextRef(State*, Ref**, Ref**, unsigned int);
};
// Walks the collection's maps by stage and flags, skipping disabled, deleted, excluded or filtered refs, and returns the next matching ref and its item.
// @fnv 0x005273c0
bool Collection::FindNextRef(State* state, Ref** result, Ref** item, unsigned int flags)
{
    while (state->map)
    {
        if (state->current)
        {
            Ref* entry7 = 0;
            while (state->entries->Next(&state->state, &entry7, 1))
            {
                if (state->filter)
                {
                    if (entry7->CallGetFlags() != state->filter)
                        continue;
                }
                else
                {
                    if (entry7->CallGetFlags()->FNV_GetFormType() != state->type)
                        continue;
                }
                if (!entry7->FUN_00726070())
                    continue;
                *result = state->current;
                *item = entry7;
                return true;
            }
            state->state.FUN_00527740();
            state->entries = 0;
            state->current = 0;
        }
        while (!state->pos)
        {
            switch (state->stage)
            {
            case 0:
                if (flags & 1)
                    state->map = &fourth;
                break;
            case 1:
                if (flags & 6)
                    state->map = &fifth;
                break;
            case 2:
                state->map = 0;
                return false;
            }
            state->stage++;
            if (state->map)
                state->pos = state->map->GetFirstPos();
        }
        bool tempSwap6 = state->stage > 0;
        bool container7 = true;
        if (state->map == &first)
            container7 = false;
        while (state->pos)
        {
            unsigned int key = 0;
            Ref* ref = 0;
            state->map->GetNext(state->pos, key, ref);
            if (ref->GetDisabled() || ref->GetDeleted())
                continue;
            if (ref->IsExcluded() || ref->GetAcousticSpace()->IsSpecial())
                continue;
            if (ref->HasFlag() && !(flags & 8))
                continue;
            if (!tempSwap6)
            {
                if (state->filter)
                {
                    if (state->filter != ref->GetAcousticSpace())
                        continue;
                }
                else if (!container7)
                {
                    if (state->type != ref->GetAcousticSpace()->FNV_GetFormType())
                        continue;
                }
                *result = ref;
                *item = 0;
                return true;
            }
            else
            {
                if (state->map == &fifth)
                {
                    bool actors = (flags & 2) ? true : false;
                    bool others = (flags & 4) ? true : false;
                    if (actors != others)
                    {
                        if (ref->IsActor(0) == !actors)
                            continue;
                    }
                }
                else if (ref->GetAcousticSpace()->FNV_GetFormType() == 0x1b)
                {
                    Form* baseTmp = ref->GetAcousticSpace();
                    if (!baseTmp->Accept(ref, state->context, 0))
                        continue;
                }
                state->entries = ref->FUN_005d43c0()->GetEntries();
                if (state->entries)
                    state->current = ref;
                break;
            }
        }
    }
    return false;
}

extern "C" void __cdecl FormHeap_Free(void*);
extern "C" void FUN_0044e360(unsigned long);

struct ArrayItem
{
    int m_iWordAt00;
    void* m_iWordAt04;
};

struct ElemCls
{
    void* __thiscall FUN_005293c0(unsigned int flags);
};

struct Cls
{
    void* m_iWordAt00;
    unsigned long m_iWordAt04;
    ArrayItem* m_8;
    unsigned int __thiscall FUN_00559450();
    void __thiscall FUN_00529330();
};

// @fnv 0x00529330
void __thiscall Cls::FUN_00529330()
{
    unsigned int i = 0;
    for (; i < this->FUN_00559450(); ++i)
    {
        void* t = this->m_8[i].m_iWordAt04;
        void* t2 = t;
        t2 ? ((ElemCls*)t2)->FUN_005293c0(1) : 0;
    }
    {
        void* p = this->m_8;
        FormHeap_Free(p);
    }
    FUN_0044e360(this->m_iWordAt04);
}

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3(float, float, float);
    NiPoint3 operator+(const NiPoint3&) const;
    NiPoint3 operator*(float) const;
    bool FUN_004390c0(const NiPoint3&);
    NiPoint3& Subtract(const NiPoint3&);
    void FUN_004a0c10();
    NiPoint3 FUN_0053d1a0(const NiPoint3&);
};
NiPoint3 operator*(float, const NiPoint3&);
extern const NiPoint3 DAT_011a9484;
float FUN_004b1520(float, float);
struct TerrainInput
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned int region;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    unsigned int position, edgeA, u, c;
    bool flipA, flipB;
};
struct TerrainOwner
{
    NiPoint3 FUN_0053b450(unsigned char, unsigned short, int*, int*);
    void FUN_00534240(unsigned int, unsigned int, NiPoint3&);
    void FUN_00534390(unsigned int, unsigned int, NiPoint3&);
    float FUN_00534080();
    float FUN_00534050();
    bool ComputeTerrainNormalAndTangent(TerrainInput*, NiPoint3*, NiPoint3*);
};
// Computes a terrain normal and tangent at input->position, blending edge/u/c samples by flip flags, and returns true.
// @fnv 0x0053caf0
bool TerrainOwner::ComputeTerrainNormalAndTangent(TerrainInput* input, NiPoint3* normal, NiPoint3* tangent)
{
    NiPoint3 origin;
    NiPoint3 position = FUN_0053b450((unsigned char)input->region, (unsigned short)input->position, 0, 0);
    FUN_00534240(input->region, input->position, origin);
    NiPoint3 location;
    location = NiPoint3(FUN_00534050() + 2048.0, FUN_00534080() + 2048.0, 0.0f);
    NiPoint3 center = origin + location;
    center.z = 0.0f;
    if (center.FUN_004390c0(position))
    {
        FUN_00534390(input->region, input->position, *normal);
        *tangent = *normal;
    }
    else
    {
        float blended = FUN_004b1520(position.x, 128.0f) / 128.0;
        float pointB = FUN_004b1520(position.y, 128.0f) / 128.0;
        NiPoint3 edgeA;
        NiPoint3 u;
        NiPoint3 c;
        NiPoint3 v = DAT_011a9484;
        FUN_00534390(input->region, input->edgeA, edgeA);
        FUN_00534390(input->region, input->u, u);
        FUN_00534390(input->region, input->c, c);
        if (!input->flipA && !input->flipB)
            v = ((1.0f - blended) * u + blended * edgeA) * (1.0f - pointB) + pointB * c;
        if (!input->flipA && input->flipB)
            v = ((1.0f - blended) * edgeA + blended * c) * pointB + (1.0f - pointB) * u;
        if (input->flipA && !input->flipB)
            v = ((1.0f - blended) * edgeA + blended * u) * (1.0f - pointB) + pointB * c;
        if (input->flipA && input->flipB)
            v = ((1.0f - blended) * c + blended * edgeA) * pointB + (1.0f - pointB) * u;
        *normal = v;
        normal->FUN_004a0c10();
        NiPoint3 a;
        NiPoint3 pointC;
        NiPoint3 edgeB;
        NiPoint3 b;
        FUN_00534240(input->region, input->edgeA, a);
        FUN_00534240(input->region, input->u, pointC);
        a.Subtract(pointC);
        FUN_00534240(input->region, input->edgeA, edgeB);
        FUN_00534240(input->region, input->c, b);
        edgeB.Subtract(b);
        if ((input->flipA && !input->flipB) || (!input->flipA && input->flipB))
            *tangent = a.FUN_0053d1a0(edgeB);
        else
            *tangent = edgeB.FUN_0053d1a0(a);
    }
    return true;
}

struct QueryState175
{
    void* vtable;
    unsigned current;
    unsigned cursor;
    unsigned char complete;
    QueryState175();
    ~QueryState175();
    bool FUN_006ebde0();
};
struct Head175
{
    void* value;
    Head175(int);
    ~Head175();
    void* FUN_00559450();
};
struct Manager175
{
    bool RunQueuedTask(void*, int);
};
struct FUN_005281f0_Class
{
    bool AdvanceRequest(QueryState175*, int*, Head175*, int);
    int FUN_005281f0();
};
// @fnv 0x005281f0
int FUN_005281f0_Class::FUN_005281f0()
{
    int count = 0;
    QueryState175 query;
    while (!query.FUN_006ebde0())
    {
        int currentValue = 0;
        Head175 itemHead(0);
        if (AdvanceRequest(&query, &currentValue, &itemHead, 1))
        {
            if (!reinterpret_cast<Manager175*>(DAT_01202d98)->RunQueuedTask(itemHead.FUN_00559450(), 0))
                ++count;
        }
    }
    return count;
}

class NiObject
{
  public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual NiObject* slot9(int a, int b);
    void FUN_00528ce0(NiObject* other);
};

struct FUN_00528bb0_class
{
    NiObject* m_obj;
    void FUN_00528bb0(int arg);
};

// Calls slot9(arg, arg) on m_obj and passes the result to FUN_00528ce0 on this.
// @fnv 0x00528bb0
void FUN_00528bb0_class::FUN_00528bb0(int arg)
{
    reinterpret_cast<NiObject*>(this)->FUN_00528ce0(m_obj->slot9(arg, arg));
}

namespace QueueReconstruction528be0 {
struct QueueBase528be0
{
    virtual void Slot00();
    ~QueueBase528be0();
};

struct FUN_00528be0 : QueueBase528be0
{
    void* unk04;
    unsigned int unk08;
    void* m_buckets;
    void FUN_00528e40(bool shutdown);
    ~FUN_00528be0();
};

// Calls FUN_00528e40(true), then passes m_buckets and unk04 to FormHeap_Free.
// @fnv 0x00528be0
FUN_00528be0::~FUN_00528be0()
{
    FUN_00528e40(true);
    void* buckets = m_buckets;
    FormHeap_Free(buckets);
    void* buffer = unk04;
    FormHeap_Free(buffer);
}

}

class TESAmmo;
class BGSAmmoForm
{
  public:
    TESAmmo* GetAmmoHelper();
};
struct AmmoProcess
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
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
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
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual Ref* GetLeft();
    virtual Ref* GetRight();
};
struct AmmoActor
{
    AmmoProcess* FUN_008d8520();
};
extern char DAT_01183108;
extern char DAT_011840c4;
extern "C" void* __cdecl _FNV_DynamicCast(void*, int, void*, void*, int);
struct AmmoOwner
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
    BGSAmmoForm ammo;
    Form* FUN_00525980(AmmoActor* actor);
};
// Returns the right-hand Form if it differs from the left one and passes the dynamic cast; otherwise returns the ammo helper's result.
// @fnv 0x00525980
Form* AmmoOwner::FUN_00525980(AmmoActor* actor)
{
    if (actor && actor->FUN_008d8520() && actor->FUN_008d8520()->GetRight())
    {
        Form* right3 = actor->FUN_008d8520()->GetRight()->CallGetFlags();
        Form* left5 = actor->FUN_008d8520()->GetLeft() ? actor->FUN_008d8520()->GetLeft()->CallGetFlags() : 0;
        if (right3 != left5)
        {
            void* casted = _FNV_DynamicCast(right3, 0, &DAT_01183108, &DAT_011840c4, 0);
            if (casted)
                return right3;
        }
    }
    return (Form*)ammo.GetAmmoHelper();
}

struct Obj
{
    int FUN_008d80e0();
};
struct Thing
{
    char pad[0x118];
    int m_uiFilterValue;
    Obj* FUN_00525980(int arg);
    int GetOrFallback(int arg);
};
// @fnv 0x00525a90
int Thing::GetOrFallback(int arg)
{
    Obj* result = FUN_00525980(arg);
    if (result != 0)
    {
        int value = result->FUN_008d80e0();
        if (value != 0)
            return value;
    }
    return m_uiFilterValue;
}

struct RgbaColor
{
    float r, g, b, a;
    RgbaColor(float r, float g, float b, float a);
};
struct _ref_006815c0
{
    _ref_006815c0();
    ~_ref_006815c0();
};
struct FUN_0052d180 : _ref_006815c0
{
    int pad;
    RgbaColor c;
    FUN_0052d180();
};
// @fnv 0x0052d180
FUN_0052d180::FUN_0052d180() : c(0.0f, 0.0f, 0.0f, 0.0f)
{}
