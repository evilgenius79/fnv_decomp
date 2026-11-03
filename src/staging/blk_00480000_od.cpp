
// src/staging/blk_00480000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct TESSaveLoadGame
{
    void __thiscall FUN_00857a10(int a, int b);
};

extern TESSaveLoadGame* g_TESSaveLoadGame;

struct FUN_00484d20_Class
{
    void __thiscall ForwardToSaveLoadGame(int a, int b);
};

// Calls FUN_00857a10 on g_TESSaveLoadGame, passing both arguments through.
// @fnv 0x00484d20
void __thiscall FUN_00484d20_Class::ForwardToSaveLoadGame(int a, int b)
{
    g_TESSaveLoadGame->FUN_00857a10(a, b);
}

extern int DAT_00ffffff;

struct FUN_00485bc0_class
{
    int __thiscall FUN_00485bc0();
};

// @fnv 0x00485bc0
int __thiscall FUN_00485bc0_class::FUN_00485bc0()
{
    return ((int*)this)[3] & (int)&DAT_00ffffff;
}

int __cdecl _stricmp(const char*, const char*);

struct FUN_00486b50_Class
{
    int __thiscall IsStringEqualIgnoreCase(const char* a, const char* b);
};

// Compares two strings case-insensitively and returns whether they are equal.
// @fnv 0x00486b50
int __thiscall FUN_00486b50_Class::IsStringEqualIgnoreCase(const char* pcStringA, const char* pcStringB)
{
    return _stricmp(pcStringA, pcStringB) == 0;
}

extern int $SG4908;
struct FUN_00486c60_t
{
    int* vtbl;
    void FUN_00486c80();
    ~FUN_00486c60_t();
};
// @fnv 0x00486c60
FUN_00486c60_t::~FUN_00486c60_t()
{
    vtbl = (int*)&$SG4908;
    FUN_00486c80();
}

struct FUN_00486c80_class
{
    void FUN_00486ca0();
    void FUN_00486c80();
};

// @fnv 0x00486c80
void FUN_00486c80_class::FUN_00486c80()
{
    FUN_00486ca0();
}

struct FUN_00486e80_Class
{
    void FUN_00486d60();
    void* DestroyIfFlagged(unsigned int flags);
};

// Calls FUN_00486d60, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x00486e80
void* FUN_00486e80_Class::DestroyIfFlagged(unsigned int flags)
{
    FUN_00486d60();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern "C" void* __cdecl DAT_0101cb38;

struct FUN_00486f40
{
    void __thiscall Call(void* a, bool b);
};

struct FUN_00486ee0
{
    void* a;
    void* __thiscall Init(void* a, bool b);
};

// Calls Call with the given arguments, then stores the address of DAT_0101cb38 in this object and returns this.
// @fnv 0x00486ee0
void* __thiscall FUN_00486ee0::Init(void* apArg, bool abFlag)
{
    ((FUN_00486f40*)this)->Call(apArg, abFlag);
    *(void**)this = &DAT_0101cb38;
    return this;
}

extern "C" void __cdecl FUN_00486fa0(int);
extern int DAT_0101caf8;

struct FUN_00486f70_class
{
    void __thiscall FUN_00486fa0(int);
    void* m_p;
    void* __thiscall InitializeWithGlobal(int a);
};

// Calls FUN_00486fa0 with a, stores the address of DAT_0101caf8 in m_p, and returns this.
// @fnv 0x00486f70
void* __thiscall FUN_00486f70_class::InitializeWithGlobal(int a)
{
    FUN_00486fa0(a);
    m_p = &DAT_0101caf8;
    return this;
}

void __cdecl Deallocate(void*);

struct FUN_00487620
{
    void* m0;
    void* m1;
    void* m2;
    ~FUN_00487620();
};

// Destructor that passes m2 to Deallocate.
// @fnv 0x00487620
FUN_00487620::~FUN_00487620()
{
    void* p = m2;
    Deallocate(p);
}

struct FUN_004893c0_class
{
    void FUN_004893c0(unsigned char acFlags);
};
// @fnv 0x004893c0
void FUN_004893c0_class::FUN_004893c0(unsigned char acFlags)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x14) = acFlags;
}

struct BFC_s
{
    BFC_s();
};
struct FUN_008c6060_shell
{
    void FUN_008c6060();
};
extern int DAT_0101d398;
struct FUN_0048b800 : BFC_s
{
    FUN_0048b800();
};
// Sets the object's vtable pointer to DAT_0101d398 and then calls FUN_008c6060 on this object.
// @fnv 0x0048b800
FUN_0048b800::FUN_0048b800()
{
    *(int*)this = (int)&DAT_0101d398;
    ((FUN_008c6060_shell*)this)->FUN_008c6060();
}

namespace fnv_0048e7a0 {
extern int DAT_0101d81c;
struct FUN_008c6060_shell
{
    void FUN_008c6060();
};
struct BFC_s
{
    BFC_s();
};
struct FUN_0048e7a0 : BFC_s
{
    void FUN_008c6060();
    FUN_0048e7a0();
};
// Sets the object's first field to point at DAT_0101d81c, then calls FUN_008c6060.
// @fnv 0x0048e7a0
FUN_0048e7a0::FUN_0048e7a0()
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_0101d81c);
    FUN_008c6060();
}
}  // namespace fnv_0048e7a0

struct FUN_0048ee50_Class
{
    float GetFieldB8Float();
};

// @fnv 0x0048ee50
float FUN_0048ee50_Class::GetFieldB8Float()
{
    return *(float*)((char*)this + 0xb8);
}

struct FUN_004938c0_class
{
    unsigned char GetByteAt384();
};

// @fnv 0x004938c0
unsigned char FUN_004938c0_class::GetByteAt384()
{
    return ((unsigned char*)this)[0x384];
}

struct FUN_0049c4e0_Class
{
    void* m0;
    short m4;
    void* m8;
    void __thiscall SetFields(void* a, short b, void* c);
};

// Stores the short value b and the pointer c into the object's m4 and m8 fields.
// @fnv 0x0049c4e0
void __thiscall FUN_0049c4e0_Class::SetFields(void* pObject, short sValue, void* pValue)
{
    ((FUN_0049c4e0_Class*)pObject)->m4 = sValue;
    ((FUN_0049c4e0_Class*)pObject)->m8 = pValue;
}

struct Flt
{
    operator unsigned int();
};
struct TESObject
{
    unsigned int GetNext();
};
struct FUN_0049ec60
{
    unsigned int GetNext();
};
// Returns the next value from the TESObject obtained by converting the float at offset 0xb8 to an unsigned int.
// @fnv 0x0049ec60
unsigned int FUN_0049ec60::GetNext()
{
    return ((TESObject*)((Flt*)((char*)this + 0xb8))->operator unsigned int())->GetNext();
}

extern int DAT_010159d4;

struct GlobalObject_00869f00
{
    int* p;
    void Clear(bool);
    void FUN_0049f1f0();
};

// @fnv 0x0049f1f0
void GlobalObject_00869f00::FUN_0049f1f0()
{
    p = &DAT_010159d4;
    Clear(true);
}

extern void* DAT_0101e128;
struct FUN_0049f640_class
{
    void* vtable;
    void FUN_0049fbf0(int, int);
    FUN_0049f640_class* FUN_0049f640();
};
// Sets the vtable to DAT_0101e128, calls FUN_0049fbf0(0, 0), and returns this.
// @fnv 0x0049f640
FUN_0049f640_class* FUN_0049f640_class::FUN_0049f640()
{
    vtable = &DAT_0101e128;
    FUN_0049fbf0(0, 0);
    return this;
}

namespace fnv_0049f670 {
extern "C" void __cdecl FUN_0049faf0(int);
extern int DAT_0101e128;

struct FUN_0049f670_Class
{
    int* p;
    void FUN_0049f670();
};

// @fnv 0x0049f670
void FUN_0049f670_Class::FUN_0049f670()
{
    p = &DAT_0101e128;
    ((void(__thiscall*)(void*, int))FUN_0049faf0)(this, 1);
}
}  // namespace fnv_0049f670

struct NiPlane
{
    bool FUN_004390c0(const NiPlane&);
};

// @fnv 0x0049f830
bool FUN_0049f830(NiPlane* self, const NiPlane& other)
{
    return self->FUN_004390c0(other);
}

struct NodePoolView
{
    void* AddHead();
};

struct ScriptPool
{
    int pad0;
    int pad1;
    NodePoolView pool;
    void* FUN_0049fa80();
};

// @fnv 0x0049fa80
void* ScriptPool::FUN_0049fa80()
{
    return pool.AddHead();
}

struct FUN_0049fe00_class
{
    void FUN_004a44a0();
    void FUN_0049fe00();
};

// @fnv 0x0049fe00
void FUN_0049fe00_class::FUN_0049fe00()
{
    FUN_004a44a0();
}

extern "C" void* __cdecl NiFreeAlias(void*);

struct FUN_00486dc0_Class
{
    const char* m_p;
    void* m_auiShapeKeys;
    void* m_data;
    void FUN_00486dc0();
};

// Sets m_p to "PnH", clears the pointer map contents, and frees m_data.
// @fnv 0x00486dc0
void FUN_00486dc0_Class::FUN_00486dc0()
{
    m_p = "PnH";
    ((NiTPointerMap<int, int>*)this)->RemoveAll();
    NiFreeAlias(m_data);
}

namespace fnv_0048b500 {
extern "C" void __cdecl Deallocate(void*);

struct FUN_0048b500_Class
{
    void __thiscall ResetAndDeallocate(int param_2);
};

// Clears the int at offset 8 of the given object, then passes that object to Deallocate.
// @fnv 0x0048b500
void __thiscall FUN_0048b500_Class::ResetAndDeallocate(int pObject)
{
    *(int*)(pObject + 8) = 0;
    int local = pObject;
    Deallocate((void*)local);
}
}  // namespace fnv_0048b500

namespace fnv_0049c570 {
extern int DAT_0101def0;
void __cdecl NiFreeAlias(void*);
struct FUN_0049c570 : NiTPointerMap<int, int>
{
    void Reset();
};
// @fnv 0x0049c570
void __thiscall FUN_0049c570::Reset()
{
    *reinterpret_cast<void**>(this) = &DAT_0101def0;
    NiTPointerMap::RemoveAll();
    NiFreeAlias(reinterpret_cast<void*>(reinterpret_cast<unsigned int*>(this)[2]));
}
}  // namespace fnv_0049c570

struct S_486a60
{
    void FUN_00486a60();
    void* __thiscall FUN_00486c00(unsigned int flags);
};
void __cdecl Deallocate(void*);
// @fnv 0x00486c00
void* __thiscall S_486a60::FUN_00486c00(unsigned int flags)
{
    FUN_00486a60();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00486e50_Class : FUN_00486dc0_Class
{
    void* FUN_00486e50(unsigned int flags);
};
// Calls the base cleanup, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00486e50
void* FUN_00486e50_Class::FUN_00486e50(unsigned int flags)
{
    FUN_00486dc0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00486f10_Class
{
    void* __thiscall FUN_00486f10(unsigned int flags);
};
// Calls FUN_00486c80 on this and, when flags has bit 0 set, deallocates this; returns this.
// @fnv 0x00486f10
void* __thiscall FUN_00486f10_Class::FUN_00486f10(unsigned int flags)
{
    ((FUN_00486c60_t*)this)->FUN_00486c80();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FileEntryList
{
    void __thiscall FUN_00488ff0();
    void* __thiscall FUN_0048a0a0(unsigned int flags);
};
// @fnv 0x0048a0a0
void* FileEntryList::FUN_0048a0a0(unsigned int flags)
{
    FUN_00488ff0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_0048fb20_Class
{
    unsigned char flags;
    void __thiscall UpdateFlags(unsigned char a, unsigned char b, unsigned char c);
};
// Clears the bits of flags selected by b, then sets the bits of a shifted left by c.
// @fnv 0x0048fb20
void __thiscall FUN_0048fb20_Class::UpdateFlags(unsigned char a, unsigned char b, unsigned char c)
{
    flags = (flags & ~b) | (a << c);
}

struct FUN_0049c570_Class
{
    void* __thiscall FUN_0049c5a0(unsigned int flags);
    void __thiscall FUN_0049c570();
};
// Calls FUN_0049c570, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x0049c5a0
void* __thiscall FUN_0049c570_Class::FUN_0049c5a0(unsigned int flags)
{
    FUN_0049c570();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_0049e3e0_Class
{
    void __thiscall FUN_00c4ccd0();
    void* __thiscall FUN_0049e3e0(unsigned int flags);
};

// @fnv 0x0049e3e0
void* __thiscall FUN_0049e3e0_Class::FUN_0049e3e0(unsigned int flags)
{
    FUN_00c4ccd0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_0049f670_Class
{
    void __thiscall FUN_0049f670();
    void* __thiscall FUN_0049f880(unsigned int flags);
};

// @fnv 0x0049f880
void* FUN_0049f670_Class::FUN_0049f880(unsigned int flags)
{
    FUN_0049f670();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_0049fe20_class
{
    void __thiscall FUN_0049fe20();
    void* __thiscall FUN_0049ffc0(unsigned int flags);
};

// @fnv 0x0049ffc0
void* FUN_0049fe20_class::FUN_0049ffc0(unsigned int flags)
{
    FUN_0049fe20();
    if (flags & 1)
        Deallocate(this);
    return this;
}

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned short*, EndianSizeTag<2>);
bool __cdecl FUN_00401500();
void __cdecl AppendChunk(void*, void*, unsigned int);
// @fnv 0x00485950
void __cdecl FUN_00485950(void* apDest, unsigned short ausValue)
{
    if (FUN_00401500())
        BSEndian((unsigned short*)&ausValue, EndianSizeTag<2>());
    AppendChunk(apDest, &ausValue, 2);
}

void __cdecl _Deallocate(void*);
struct S_486eb0
{
    void* __thiscall FUN_00486eb0(unsigned int flags);
};
// Calls FUN_00486ca0 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00486eb0
void* __thiscall S_486eb0::FUN_00486eb0(unsigned int flags)
{
    ((FUN_00486c80_class*)this)->FUN_00486ca0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int DAT_0101cad8;
struct S486f40 : FUN_00486f70_class
{
    void* __thiscall FUN_00486f40(int a, bool b);
};
// Calls the base constructor, installs DAT_0101cad8 as the vtable pointer, stores b at offset 0x10, and returns this.
// @fnv 0x00486f40
void* __thiscall S486f40::FUN_00486f40(int aiArg, bool abFlag)
{
    InitializeWithGlobal(aiArg);
    *(void**)this = (void*)&DAT_0101cad8;
    *(bool*)((char*)this + 0x10) = abFlag;
    return this;
}

struct IdleAnimationManager
{
    bool __thiscall FUN_00843150();
};
void __cdecl FUN_004858f0(unsigned int, unsigned char);
struct FUN_00489240_Class
{
    void __thiscall FUN_00489240(unsigned a);
};
// Calls FUN_00843150 on this; if it returns a nonzero signed char, passes a and that value to FUN_004858f0.
// @fnv 0x00489240
void __thiscall FUN_00489240_Class::FUN_00489240(unsigned a)
{
    signed char b = reinterpret_cast<IdleAnimationManager*>(this)->FUN_00843150();
    if (b)
        FUN_004858f0(a, b);
}

// Returns true if the chunk ID is one of the four MOD-related chunk tags, otherwise false.
// @fnv 0x00489280
bool FUN_00489280(int chunk)
{
    switch (chunk)
    {
    case 0x4c444f4d:
    case 0x44444f4d:
    case 0x44534f4d:
    case 0x54444f4d:
        return true;
    default:
        return false;
    }
}

extern int DAT_0101d274;
void __cdecl Deallocate(void*);
struct FUN_0048b4c0_Class
{
    int* m_vtbl;
    int m_auiShapeKeys;
    void* m_data;
    ~FUN_0048b4c0_Class();
};
// Sets the vtable pointer and, if m_data is non-null, frees it via Deallocate.
// @fnv 0x0048b4c0
FUN_0048b4c0_Class::~FUN_0048b4c0_Class()
{
    m_vtbl = &DAT_0101d274;
    if (m_data)
    {
        void* tmp = m_data;
        Deallocate(tmp);
    }
}

struct FUN_0048b590_shell
{
    void __thiscall ClearFields();
};
extern int DAT_0101d2a4;
struct FUN_0048b560 : BFC_s
{
    FUN_0048b560();
};
// Sets the object's vtable pointer to DAT_0101d2a4 and then calls ClearFields on this.
// @fnv 0x0048b560
FUN_0048b560::FUN_0048b560() : BFC_s()
{
    *(int*)this = (int)&DAT_0101d2a4;
    ((FUN_0048b590_shell*)this)->ClearFields();
}

struct TESSound
{
    void* m_auiShapeKeys;
    void* m_sound;
    unsigned int Deallocate();
};
extern "C" void __cdecl FUN_00485910(int a, int b);
struct FUN_0048b830_Class
{
    void* m_p;
    void* m_auiShapeKeys;
    void __thiscall ReleaseSound();
};
// @fnv 0x0048b830
void __thiscall FUN_0048b830_Class::ReleaseSound()
{
    if (((TESSound*)this)->m_sound)
    {
        unsigned int result = ((TESSound*)((TESSound*)this)->m_sound)->Deallocate();
        FUN_00485910(0x4d414e52, result);
    }
}

struct TESModel
{
    unsigned int GetModelLength() const;
};
struct FNStub
{
    void* GetFullName();
};
void __cdecl FUN_004856f0(unsigned int, void*, unsigned int);
struct FUN_0048cea0_shell : TESModel
{
    void __thiscall FUN_0048cea0();
};
// @fnv 0x0048cea0
void __thiscall FUN_0048cea0_shell::FUN_0048cea0()
{
    if (GetModelLength())
        FUN_004856f0(0x4d414e46, reinterpret_cast<FNStub*>(this)->GetFullName(), GetModelLength() + 1);
}

struct FUN_00508100_shell
{
    float FUN_00508100();
};
struct FUN_00759450_shell
{
    float FUN_00759450();
};
// Returns 0 if the sequence is null, otherwise the difference between the two values returned by the sequence's FUN_00508100 and FUN_00759450 calls.
// @fnv 0x00491090
float __cdecl FUN_00491090(NiControllerSequence* apSequence)
{
    if (!apSequence)
        return 0.0f;
    float f = ((FUN_00759450_shell*)apSequence)->FUN_00759450();
    float g = ((FUN_00508100_shell*)apSequence)->FUN_00508100();
    return g - f;
}

struct S00496440
{
    int m0;
    int m1;
    int m2;
    void __thiscall FUN_004963b0(const S00496440&);
    void __thiscall FUN_00496440(bool);
};
// Copies p into this object and then calls FUN_00496440 with true.
// @fnv 0x004963b0
void __thiscall S00496440::FUN_004963b0(const S00496440& aSource)
{
    *this = aSource;
    FUN_00496440(true);
}

struct FUN_00496470_shell
{
    void __thiscall FUN_00496470(bool);
};
struct FourInts
{
    int a;
    int b;
    int c;
    int d;
};
struct S_004963e0
{
    char pad[12];
    FourInts m;
    void __thiscall SetFromFourInts(FourInts* p);
};
// Copies the four ints pointed to by p into m, then calls FUN_00496470 with true.
// @fnv 0x004963e0
void __thiscall S_004963e0::SetFromFourInts(FourInts* apValues)
{
    m = *apValues;
    ((FUN_00496470_shell*)this)->FUN_00496470(true);
}

struct BGSSaveFormBuffer
{
    void SaveData(void* p, int a, int b);
};
struct FUN_00497bc0_Class
{
    void FUN_00497bc0(BGSSaveFormBuffer* buffer, int a);
};
// Saves three 4-byte fields at offsets 8, 0xc and 0x14 of this object into the given BGSSaveFormBuffer.
// @fnv 0x00497bc0
void FUN_00497bc0_Class::FUN_00497bc0(BGSSaveFormBuffer* buffer, int aiUnused)
{
    buffer->SaveData(this + 8, 4, 0);
    buffer->SaveData(this + 0xc, 4, 0);
    buffer->SaveData(this + 0x14, 4, 0);
}

struct NiTListItem_0049c6d0
{
    NiTListItem_0049c6d0* a;
    int b;
    int c;
};
struct NiTPointerListBase_0049c6d0
{
    NiTListItem_0049c6d0* m0;
    NiTListItem_0049c6d0* m4;
    unsigned int m8;
    void FUN_00559c90(NiTListItem_0049c6d0* a);
    NiTListItem_0049c6d0* RemoveHead();
};
// @fnv 0x0049c6d0
NiTListItem_0049c6d0* NiTPointerListBase_0049c6d0::RemoveHead()
{
    NiTListItem_0049c6d0* item = m0;
    m0 = m0->a;
    if (m0)
        m0->b = 0;
    else
        m4 = 0;
    NiTListItem_0049c6d0* result = (NiTListItem_0049c6d0*)item->c;
    FUN_00559c90(item);
    m8--;
    return result;
}

struct FUN_0049db00_Class
{
    void* m0;
    void* m4;
    void* m8;
    void* mc;
    void* m10;
    void* m14;
    void* m18;
    void* m1c;
    void* m20;
    void* m24;
    void* m28;
    float FUN_0049db00();
};
// @fnv 0x0049db00
float FUN_0049db00_Class::FUN_0049db00()
{
    return m28 ? ((float*)m28)[0x28] : 0.0f;
}

struct FUN_0049db30_Class
{
    void* m0;
    void* m4;
    void* m8;
    void* mc;
    void* m10;
    void* m14;
    void* m18;
    void* m1c;
    void* m20;
    void* m24;
    void* m28;
    void* __thiscall GetSecondPointer();
};
// Returns the second pointer stored in the object at m28, or null if m28 is null.
// @fnv 0x0049db30
void* FUN_0049db30_Class::GetSecondPointer()
{
    return m28 ? ((void**)m28)[1] : 0;
}

struct FUN_0049f190_Class
{
    int __thiscall FindIndexIf(const NiPlane&, int, bool(__cdecl*)(NiPlane*, const NiPlane&));
    bool __thiscall ContainsPlane(const NiPlane&);
};
// Returns whether the plane is found by searching with FindIndexIf using FUN_0049f830, i.e. the result is not -1.
// @fnv 0x0049f190
bool __thiscall FUN_0049f190_Class::ContainsPlane(const NiPlane& aPlane)
{
    return FindIndexIf(aPlane, 0, FUN_0049f830) != -1;
}

struct S_0049f850
{
    void* __thiscall FUN_0049f850(unsigned int flags);
};
// Calls FUN_0049f1f0 on this and, if flags has bit 1 set, deletes this; returns this.
// @fnv 0x0049f850
void* __thiscall S_0049f850::FUN_0049f850(unsigned int flags)
{
    ((GlobalObject_00869f00*)this)->FUN_0049f1f0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct NiPlane_0049f8b0
{
    int m_kPointA[4];
    NiPlane_0049f8b0& FUN_0049f8b0(const NiPlane_0049f8b0& other);
};
// Copies the last three ints of other into this object's array and returns *this.
// @fnv 0x0049f8b0
NiPlane_0049f8b0& NiPlane_0049f8b0::FUN_0049f8b0(const NiPlane_0049f8b0& other)
{
    m_kPointA[1] = other.m_kPointA[1];
    m_kPointA[2] = other.m_kPointA[2];
    m_kPointA[3] = other.m_kPointA[3];
    return *this;
}

struct NavMeshSearchLOSArray
{
    int pad0;
    void* data;
    int size;
    int capacity;
    void CallVirtualOnEach(void*, int);
    void FUN_006a8500();
    void FUN_0049faf0(bool freeStorage);
};

// @fnv 0x0049faf0
void NavMeshSearchLOSArray::FUN_0049faf0(bool freeStorage)
{
    if (data)
    {
        CallVirtualOnEach(data, size);
        if (freeStorage)
        {
            FUN_006a8500();
            data = 0;
            capacity = 0;
        }
        size = 0;
    }
}

struct FUN_0049fc80_Elem
{
    virtual void __thiscall Foo(int);
    char _pad[12];
};
struct FUN_0049fc80_Holder
{
    void __thiscall CallVirtualOnEach(FUN_0049fc80_Elem* a, unsigned int b);
};
// Calls Foo(0) on each of b consecutive elements starting at a.
// @fnv 0x0049fc80
void __thiscall FUN_0049fc80_Holder::CallVirtualOnEach(FUN_0049fc80_Elem* apElem, unsigned int b)
{
    unsigned int i;
    for (i = 0; i < b; i++)
        apElem[i].Foo(0);
}

struct bsrandom_singleton
{
    static FUN_0049fe20_class* DAT_011c57f8;
};
// Calls FUN_0049ffc0(1) on the singleton at DAT_011c57f8 if it exists, then clears DAT_011c57f8.
// @fnv 0x0049ff80
void FUN_0049ff80()
{
    FUN_0049fe20_class* _b;
    FUN_0049fe20_class* _c;
    void* _a;
    _b = bsrandom_singleton::DAT_011c57f8;
    _c = _b;
    if (_c)
        _a = _c->FUN_0049ffc0(1);
    else
        _a = 0;
    bsrandom_singleton::DAT_011c57f8 = 0;
}

struct TESModelTextureSwap;
struct TESForm
{
    virtual ~TESForm();
    unsigned int FNV_GetFormType();
};
struct TESObjectREFR
{
    TESForm* GetOwner();
};
struct TESActorBase
{
    int GetSex();
};
struct TESBipedModelForm : TESForm
{
    TESModelTextureSwap* GetBipedModel(int);
};
// @fnv 0x00481090
TESModelTextureSwap* GetBipedModelTextureSwap(TESForm* form, TESObjectREFR* refr)
{
    TESBipedModelForm* model2 = dynamic_cast<TESBipedModelForm*>(form);
    if (!model2)
        return 0;
    if (!refr)
        return (TESModelTextureSwap*)((char*)model2 + 0xc);
    TESForm* owner = refr->GetOwner();
    int aSex = 0;
    if (owner && owner->FNV_GetFormType() == 0x2a)
        aSex = reinterpret_cast<TESActorBase*>(owner)->GetSex();
    return model2->GetBipedModel(aSex);
}

extern int DAT_0101d274;
void* __cdecl operator new(unsigned int);
void* _fnv_zlib_memset(void* p, int c, unsigned int n);
struct FUN_0048b3e0_t
{
    int* vtbl;
    int count;
    void* data;
    int pad;
    FUN_0048b3e0_t(int n);
};
// Sets the vtable, stores n in count, and if n is nonzero allocates count*4 bytes into data and zero-fills them.
// @fnv 0x0048b3e0
FUN_0048b3e0_t::FUN_0048b3e0_t(int aiCount)
{
    int size;
    void* p3;
    vtbl = &DAT_0101d274;
    count = aiCount;
    pad = 0;
    if (aiCount)
    {
        size = count << 2;
        p3 = operator new(size);
        data = p3;
        _fnv_zlib_memset(data, 0, count << 2);
    }
}

struct GO
{
    void operator=(void*);
};
struct AnimIdle
{
};
struct Animation
{
    void AssignControllerManager(GO&);
    void SpecialIdleFree(bool, bool);
    void __thiscall FUN_0048ff50();
};
// @fnv 0x0048ff50
void __thiscall Animation::FUN_0048ff50()
{
    ((char*)this)[0xcd] = 1;
    SpecialIdleFree(true, true);
    for (unsigned int i = 0; i < 2; i++)
    {
        if (reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x12c + i * 4)->operator unsigned int())
        {
            AssignControllerManager(*reinterpret_cast<GO*>(reinterpret_cast<char*>(this) + 0x12c + i * 4));
            *reinterpret_cast<GO*>(reinterpret_cast<char*>(this) + 0x12c + i * 4) = 0;
        }
    }
}

namespace fnv_0049a920 {
struct GO
{
    void operator=(void*);
};
struct NiControllerManager
{
    void DeactivateAllSequences(float);
};
struct KFModel
{
    void* GetControllerSequence();
};
struct FUN_00496280_shell
{
    void FUN_00496280();
};
struct Animation
{
    void AssignControllerManager(Flt*);
};
struct H00499240
{
    void FUN_00499240(bool);
};
struct H00499080
{
    void FUN_00499080();
};
void __cdecl FUN_00499160(void*);
struct FUN_0049a920_s
{
    void FUN_00496080(unsigned int, float);
    void __thiscall FUN_0049a920(unsigned int a);
};
// @fnv 0x0049a920
void __thiscall FUN_0049a920_s::FUN_0049a920(unsigned int a)
{
    FUN_00496080(0x14, 0.0f);
    ((FUN_00496280_shell*)this)->FUN_00496280();
    if (*(Flt*)((char*)this + 0x124))
        ((Animation*)this)->AssignControllerManager((Flt*)((char*)this + 0x124));
    *(GO*)((char*)this + 0x124) = 0;
    if (*(Flt*)((char*)this + 0x128))
        ((Animation*)this)->AssignControllerManager((Flt*)((char*)this + 0x128));
    *(GO*)((char*)this + 0x128) = 0;
    *(int*)((char*)this + 0xfc) = 0;
    FUN_00496080(7, 0.0f);
    if (*(Flt*)((char*)this + 0xd8))
        ((NiControllerManager*)(unsigned int)*(Flt*)((char*)this + 0xd8))->DeactivateAllSequences(0.0f);
    FUN_00499160(((KFModel*)this)->GetControllerSequence());
    ((H00499080*)this)->FUN_00499080();
    ((H00499240*)this)->FUN_00499240(true);
}
}  // namespace fnv_0049a920

struct FUN_0049f8f0_class
{
    virtual void v0();
    virtual int Write(unsigned int);
    void ConstructEntries(int, unsigned int);
};
struct FUN_0049f990_class : FUN_0049f8f0_class
{
    int m4;
    int m8;
    int mc;
    void __thiscall FUN_0049f990(unsigned int requested, unsigned int saved);
};
// @fnv 0x0049f990
void __thiscall FUN_0049f990_class::FUN_0049f990(unsigned int requested, unsigned int saved)
{
    m4 = 0;
    m8 = 0;
    mc = 0;
    if (saved > requested)
        requested = saved;
    if (requested > 0)
    {
        m4 = Write(requested);
        mc = requested;
    }
    if (saved > 0)
    {
        ConstructEntries(m4, saved);
        m8 = saved;
    }
}

extern "C" void* __cdecl NiMalloc(unsigned int);
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern int $SG6245;
struct FUN_00486fa0_Class
{
    int* vtbl;
    int m_uiItemCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_00486fa0_Class(int count);
};
// Sets the vtable, stores count, allocates count*4 bytes with NiMalloc and zero-fills them.
// @fnv 0x00486fa0
FUN_00486fa0_Class::FUN_00486fa0_Class(int count)
{
    vtbl = &$SG6245;
    m_uiItemCount = count;
    m_auiShapeKeys = 0;
    unsigned int size = m_uiItemCount << 2;
    m_data = NiMalloc(size);
    memset(m_data, 0, m_uiItemCount << 2);
}

// Compares the first float of two pointers, returning 1 if the first is greater, -1 if the second is greater, otherwise 0.
// @fnv 0x0049c7b0
int __cdecl FUN_0049c7b0(const float* a, const float* b)
{
    const float* pValueA = a;
    const float* pValueB = b;
    if (*pValueA > *pValueB)
        return 1;
    else if (*pValueB > *pValueA)
        return -1;
    else
        return 0;
}

struct ActorAvoidanceEntry
{
    int a;
    int b;
    int c;
};
struct FUN_0072ba80_shell
{
    void FUN_0072ba80(ActorAvoidanceEntry* a, unsigned int b);
};
struct FUN_0049f510
{
    int m0;
    ActorAvoidanceEntry* m1;
    unsigned int m2;
    void FUN_0049f510_m();
};
// If m2 is nonzero, calls FUN_0072ba80 on the last element of the m1 array and decrements m2.
// @fnv 0x0049f510
void FUN_0049f510::FUN_0049f510_m()
{
    if (!m2)
        return;
    ((FUN_0072ba80_shell*)this)->FUN_0072ba80(m1 + m2 - 1, 1);
    --m2;
}

struct FUN_0049fa20_Node
{
    FUN_0049fa20_Node* m_pNext;
    FUN_0049fa20_Node* m_pListObject;
};
struct FUN_0049fa20_List
{
    FUN_0049fa20_Node* m_pHead;
    FUN_0049fa20_Node* m_pTail;
    unsigned int m_uiCount;
    void FUN_0049fa20(FUN_0049fa20_Node* p);
};
// Inserts a node at the head of the list, linking it to the previous head and updating the tail and count.
// @fnv 0x0049fa20
void FUN_0049fa20_List::FUN_0049fa20(FUN_0049fa20_Node* pNode)
{
    pNode->m_pListObject = 0;
    pNode->m_pNext = m_pHead;
    if (m_pHead)
        m_pHead->m_pListObject = pNode;
    else
        m_pTail = pNode;
    m_pHead = pNode;
    ++m_uiCount;
}

struct Arr16
{
    unsigned int FUN_006f31f0();
};
struct FUN_0049faa0_Class
{
    int m0;
    char* m4;
    char* ConstructElements(char*, int);
    unsigned int AppendPlane(const NiPlane_0049f8b0&);
};
// @fnv 0x0049faa0
unsigned int FUN_0049faa0_Class::AppendPlane(const NiPlane_0049f8b0& aPlane)
{
    unsigned int i = ((Arr16*)this)->FUN_006f31f0();
    ConstructElements(m4 + (i << 4), 1);
    ((NiPlane_0049f8b0*)(m4 + (i << 4)))->FUN_0049f8b0(aPlane);
    return i;
}

struct FUN_0049fbf0_vt
{
    virtual ~FUN_0049fbf0_vt();
    virtual void* v0(unsigned int);
};
struct FUN_0049fbf0_class : FUN_0049fbf0_vt
{
    int m4;
    int m8;
    int mc;
    void ConstructElements(void*, unsigned int);
    void FUN_0049fbf0(unsigned int a, unsigned int b);
};
// @fnv 0x0049fbf0
void FUN_0049fbf0_class::FUN_0049fbf0(unsigned int a, unsigned int b)
{
    m4 = 0;
    m8 = 0;
    mc = 0;
    if (b > a)
        a = b;
    if (a > 0)
    {
        m4 = (int)v0(a);
        mc = a;
    }
    if (b > 0)
    {
        ConstructElements((void*)m4, b);
        m8 = b;
    }
}

void* __cdecl __memcpy(void* destination, const void* source, unsigned int size);
bool __cdecl _FUN_00401500();
void __cdecl _FUN_00485990(void* destination, void* source, unsigned int size);
void __cdecl BSEndian(unsigned char* data, EndianSizeTag<8> type);

// @fnv 0x00485820
void __cdecl FUN_00485820(void* destination, void* source, unsigned int count)
{
    unsigned int size = count << 1;

    if (_FUN_00401500())
    {
        unsigned short* data = new unsigned short[count];
        __memcpy(data, source, size);

        for (unsigned int i = 0; i < count; ++i)
        {
            BSEndian(reinterpret_cast<unsigned char*>(data) + i * 2, EndianSizeTag<8>());
        }

        _FUN_00485990(destination, data, size);
        delete[] data;
    }
    else
    {
        _FUN_00485990(destination, source, size);
    }
}

// @fnv 0x004858f0
void __cdecl FUN_004858f0(unsigned int a, unsigned char ucValue)
{
    AppendChunk((void*)a, &ucValue, 1);
}

int __cdecl strcpy_s(char*, unsigned int, char*);
void* __cdecl _NiMalloc(unsigned int);
unsigned int __cdecl _strlen(const char*);

struct FUN_00486ae0_Class
{
    void __thiscall SetString(int* a, char* b, int c);
};

// Stores b into a[1] (copying it when the flag at this+0x10 is set) and stores c into a[2].
// @fnv 0x00486ae0
void FUN_00486ae0_Class::SetString(int* a, char* pcString, int iValue)
{
    unsigned int size;
    if (*(unsigned char*)((char*)this + 0x10) != 0)
    {
        size = _strlen(pcString) + 1;
        a[1] = (int)_NiMalloc(size);
        strcpy_s((char*)a[1], size, pcString);
    }
    else
    {
        a[1] = (int)pcString;
    }
    a[2] = iValue;
}

struct Date
{
    virtual ~Date();
};
struct FUN_0048e7d0 : Date
{
    ~FUN_0048e7d0();
};
// @fnv 0x0048e7d0
FUN_0048e7d0::~FUN_0048e7d0()
{}

struct FUN_0049c4c0_Class
{
    int pad;
    unsigned int m4;
    unsigned int __thiscall Modulo(unsigned short a);
};

// @fnv 0x0049c4c0
unsigned int FUN_0049c4c0_Class::Modulo(unsigned short ausValue)
{
    return ausValue % m4;
}

struct BSSimpleArrayActor
{
    void Clear(bool);
};

struct FUN_006c8a30_Class
{
    void FUN_006a8500();
};

struct FUN_006dc6e0_Class
{
    void FUN_006dc6e0(char*, char*, unsigned int);
};

struct FUN_006f3170_Class
{
    bool FUN_006f3170();
};

struct FUN_00869600_Class
{
    unsigned int FUN_00869600();
};

struct FUN_0049f3c0_Class
{
    virtual void FUN_0049f3c0_virtual1();
    virtual ActorAvoidanceEntry* FUN_0049f3c0_virtual2(unsigned int);

    ActorAvoidanceEntry* m4;
    unsigned int m8;
    unsigned int mc;

    void FUN_0049f3c0(unsigned int, unsigned int, bool);
};

// Removes arg2 elements starting at index arg1 from the array, optionally reallocating via virtual2 when arg3 is set and FUN_006f3170 succeeds, then shrinks m8.
// @fnv 0x0049f3c0
void FUN_0049f3c0_Class::FUN_0049f3c0(unsigned int uiStart, unsigned int arg2, bool abReallocate)
{
    if (arg2 >= this->m8)
    {
        reinterpret_cast<BSSimpleArrayActor*>(this)->Clear(abReallocate);
    }
    else
    {
        if (abReallocate && reinterpret_cast<FUN_006f3170_Class*>(this)->FUN_006f3170())
        {
            unsigned int value = reinterpret_cast<FUN_00869600_Class*>(this)->FUN_00869600();

            ActorAvoidanceEntry* p = this->FUN_0049f3c0_virtual2(value);

            reinterpret_cast<FUN_006dc6e0_Class*>(this)->FUN_006dc6e0(reinterpret_cast<char*>(p),
                                                                      reinterpret_cast<char*>(this->m4), uiStart);

            reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(this->m4 + uiStart, arg2);

            reinterpret_cast<FUN_006dc6e0_Class*>(this)->FUN_006dc6e0(
                reinterpret_cast<char*>(p) + uiStart * 12, reinterpret_cast<char*>(this->m4 + uiStart + arg2),
                this->m8 - arg2);

            reinterpret_cast<FUN_006c8a30_Class*>(this)->FUN_006a8500();

            this->m4 = p;
            this->mc = value;
        }
        else
        {
            reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(this->m4 + uiStart, arg2);

            reinterpret_cast<FUN_006dc6e0_Class*>(this)->FUN_006dc6e0(
                reinterpret_cast<char*>(this->m4 + uiStart), reinterpret_cast<char*>(this->m4 + uiStart + arg2),
                this->m8 - uiStart - arg2);
        }

        this->m8 -= arg2;
    }
}

struct ModelData
{
    virtual void Function0();
    virtual void Function1();
    virtual void Function2();
    virtual void Function3();
    virtual void Function4();
    virtual unsigned int GetValue();
};
struct FormEntry
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
    ModelData model;
    unsigned int FUN_00481190(unsigned int);
};
struct ExtraData
{
    unsigned int FUN_00401170();
    unsigned int FUN_005f0cc0();
};
struct Reference
{
    ExtraData* FUN_00567790();
};
extern "C" unsigned char DAT_01183028;
extern "C" unsigned char DAT_01183978;
extern "C" FormEntry* __cdecl func_0x00ec43fb(void*, unsigned int, void*, void*, unsigned int);
// Looks up a FormEntry from source, then returns its model value or a value computed from reference's extra data via FUN_00481190.
// @fnv 0x00480e60
unsigned int __cdecl FUN_00480e60(void* source, Reference* reference)
{
    FormEntry* form4 = func_0x00ec43fb(source, 0, &DAT_01183028, &DAT_01183978, 0);
    if (form4 == 0)
        return 0;
    if (reference == 0)
        return form4->model.GetValue();
    ExtraData* extra = reference->FUN_00567790();
    unsigned int value = 0;
    if (extra != 0 && extra->FUN_00401170() == 42)
    {
        value = extra->FUN_005f0cc0();
    }
    return form4->FUN_00481190(value);
}

class FUN_00486d60_base
{
  public:
    virtual void unk00();
    ~FUN_00486d60_base();
    int unk04;
};

class FUN_00486d60 : public FUN_00486d60_base
{
  public:
    virtual ~FUN_00486d60();
    void unk08();
};

// Destructor that calls unk08() on this object.
// @fnv 0x00486d60
FUN_00486d60::~FUN_00486d60()
{
    this->unk08();
}

struct GameMember
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ~GameMember();
};
struct FUN_004876d0
{
    virtual ~FUN_004876d0();
    GameMember firstMember;
    GameMember secondMember;
    void FUN_00487770();
};
// @fnv 0x004876d0
FUN_004876d0::~FUN_004876d0()
{
    FUN_00487770();
}

struct FUN_004899f0_cls
{
    unsigned char m_uiItemCount;
    unsigned int* m_pData;

    void Reset();
    void FUN_004899f0(const FUN_004899f0_cls* src);
};

void* __cdecl CopyMemory_Thunk(void* dst, const void* src, unsigned int size);

// @fnv 0x004899f0
void FUN_004899f0_cls::FUN_004899f0(const FUN_004899f0_cls* apSource)
{
    Reset();
    m_uiItemCount = apSource->m_uiItemCount;
    m_pData = new unsigned int[m_uiItemCount];
    CopyMemory_Thunk(m_pData, apSource->m_pData, m_uiItemCount * 4);
}

struct Elem_48a2c0
{
    int unk00;
    int unk04;
    Elem_48a2c0();
    void CopyFrom(Elem_48a2c0* other);
};

struct List_48a2c0
{
    unsigned int count;
    Elem_48a2c0** items;
    void Clear();
    void FUN_0048a2c0(List_48a2c0* other);
};

// Clears this list, then deep-copies other's count and items, allocating a new array and copying each element.
// @fnv 0x0048a2c0
void List_48a2c0::FUN_0048a2c0(List_48a2c0* other)
{
    Clear();
    if (other->count)
    {
        count = other->count;
        items = new Elem_48a2c0*[count];
        for (unsigned int i = 0; i < count; i++)
        {
            items[i] = new Elem_48a2c0;
            items[i]->CopyFrom(other->items[i]);
        }
    }
}

class TESForm;

class ChangeFlags0048
{
  public:
    unsigned int flags;
    ChangeFlags0048();
    operator bool() const;
};

class SaveFormBuf0048
{
  public:
    ChangeFlags0048 GetChangeFlags(unsigned int mask);
    unsigned int FUN_00865f20();
    void FUN_00865df0(void* form, int arg);
    void FUN_00865ff0(int count, unsigned int pos);
};

template <class T> class FormNode0048
{
  public:
    T item;
    FormNode0048<T>* next;
    T& GetItem();
    FormNode0048<T>* FUN_00726070();
};

class FormListPair
{
  public:
    void* vtable;
    FormNode0048<TESForm*> listA;
    FormNode0048<TESForm*> listB;

    void FUN_0048e040(SaveFormBuf0048* buffer);
};

// If the buffer's change flags include 0x10, writes each non-null form of listA and listB to the buffer and records the counts at their saved positions.
// @fnv 0x0048e040
void FormListPair::FUN_0048e040(SaveFormBuf0048* buffer)
{
    if (buffer->GetChangeFlags(0x10))
    {
        {
            int i = 0;
            unsigned int off = buffer->FUN_00865f20();
            FormNode0048<TESForm*>* pCurrent = &listA;
            while (pCurrent)
            {
                TESForm* item = pCurrent->GetItem();
                if (item)
                {
                    buffer->FUN_00865df0(item, 0);
                    i++;
                }
                pCurrent = pCurrent->FUN_00726070();
            }
            buffer->FUN_00865ff0(i, off);
        }
        {
            int cnt = 0;
            unsigned int iPos = buffer->FUN_00865f20();
            FormNode0048<TESForm*>* list = &listB;
            while (list)
            {
                TESForm* obj = list->GetItem();
                if (obj)
                {
                    buffer->FUN_00865df0(obj, 0);
                    cnt++;
                }
                list = list->FUN_00726070();
            }
            buffer->FUN_00865ff0(cnt, iPos);
        }
    }
}

class Base_b4768
{
  public:
    virtual ~Base_b4768();
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
    Base_b4768();
};

class Member_b4768
{
  public:
    unsigned int unk00;
    Member_b4768(unsigned int aValue);
};

class FUN_0049baa0 : public Base_b4768
{
  public:
    virtual ~FUN_0049baa0();
    Member_b4768 m_74;

    FUN_0049baa0();
};

// Constructs the object: initializes the base and sets member m_74 to 0.
// @fnv 0x0049baa0
FUN_0049baa0::FUN_0049baa0() : Base_b4768(), m_74(0)
{}

struct FUN_0049c410_item
{
    FUN_0049c410_item* m_pNext;
    unsigned short m_usKey;
    unsigned int m_uiCurrentValue;
};

struct FUN_0049c410_cls
{
    virtual void vSlot0();
    virtual unsigned int vSlot1(unsigned short key);
    unsigned int m_uiCount;
    FUN_0049c410_item** m_ppItems;
    void GetNextEntry(FUN_0049c410_item** pp, unsigned short* outKey, unsigned int* outValue);
};

// Reads the key and value of the item at *pp, advances *pp to the next item or the next non-null bucket entry, or sets it to null when exhausted.
// @fnv 0x0049c410
void FUN_0049c410_cls::GetNextEntry(FUN_0049c410_item** apItem, unsigned short* ausKey, unsigned int* auiValue)
{
    FUN_0049c410_item* item = *apItem;
    *ausKey = item->m_usKey;
    *auiValue = item->m_uiCurrentValue;
    if (item->m_pNext != 0)
    {
        *apItem = item->m_pNext;
        return;
    }
    unsigned int n = vSlot1(item->m_usKey);
    n++;
    for (; n < m_uiCount; n++)
    {
        item = m_ppItems[n];
        if (item != 0)
        {
            *apItem = item;
            return;
        }
    }
    *apItem = 0;
}

struct ListLink_b5187
{
    ListLink_b5187* m_00;
    ListLink_b5187* m_04;
    unsigned int m_08;
};

struct FUN_0049c5d0_cls
{
    ListLink_b5187* m_00;
    ListLink_b5187* m_04;
    unsigned int m_08;

    unsigned int RemoveTail();
    unsigned int RemoveNode(ListLink_b5187** pNode);
};

// @fnv 0x0049c5d0
unsigned int FUN_0049c5d0_cls::RemoveNode(ListLink_b5187** pNode)
{
    ListLink_b5187* node = *pNode;
    if (node == m_00)
    {
        *pNode = node->m_00;
        return (unsigned int)reinterpret_cast<NiTPointerListBase_0049c6d0*>(this)->RemoveHead();
    }
    if (node == m_04)
    {
        *pNode = 0;
        return RemoveTail();
    }
    ListLink_b5187* prev3 = node->m_04;
    ListLink_b5187* next = node->m_00;
    *pNode = next;
    if (prev3 != 0)
    {
        prev3->m_00 = next;
    }
    if (next != 0)
    {
        next->m_04 = prev3;
    }
    unsigned int data = node->m_08;
    reinterpret_cast<NiTPointerListBase_0049c6d0*>(this)->FUN_00559c90(reinterpret_cast<NiTListItem_0049c6d0*>(node));
    m_08 = m_08 - 1;
    return data;
}

// Stand-in for the game's NiTPointerListBase (list head / list tail / element count).
// Layout taken from the disassembly of RemoveTail:
//   +0x00  list head        +0x04  list tail        +0x08  element count
// The list item is { next, prev, element }.
struct FNVListItem
{
    FNVListItem* m_pkNext;
    FNVListItem* m_pkPrev;
    void* m_element;
};

struct FNVPointerList
{
    FNVListItem* m_pkHead;
    FNVListItem* m_pkTail;
    unsigned int m_uiCount;
    void FNV_DeleteItem(FNVListItem* item);
    void* RemoveTail();
};

// @fnv 0x0049c740
void* FNVPointerList::RemoveTail()
{
    FNVListItem* pRemovedItem = m_pkTail;
    m_pkTail = m_pkTail->m_pkPrev;
    if (m_pkTail)
    {
        m_pkTail->m_pkNext = 0;
    }
    else
    {
        m_pkHead = 0;
    }
    void* element = pRemovedItem->m_element;
    FNV_DeleteItem(pRemovedItem);
    m_uiCount = m_uiCount - 1;
    return element;
}

struct FloatKeyedRecord
{
    int m_unk00;
    float m_key04;
};

// Compares two FloatKeyedRecord objects by their m_key04 values, returning 1, -1 or 0.
// @fnv 0x0049c800
int __cdecl FUN_0049c800(FloatKeyedRecord* apLeft, FloatKeyedRecord* apRight)
{
    FloatKeyedRecord* pa = apLeft;
    FloatKeyedRecord* pb = apRight;
    if (pa->m_key04 > pb->m_key04)
    {
        return 1;
    }
    else if (pb->m_key04 > pa->m_key04)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

extern bool __cdecl IsApproximatelyEqual(float a, float b, float tolerance);

// @fnv 0x0049e2f0
bool __cdecl AreVectorsEqual(const float* lhs, const float* rhs, float tolerance)
{
    return IsApproximatelyEqual(lhs[0], rhs[0], tolerance) && IsApproximatelyEqual(lhs[1], rhs[1], tolerance) &&
           IsApproximatelyEqual(lhs[2], rhs[2], tolerance);
}

struct PlaneElem
{
    int a;
    int b;
    int c;
    int d;
    PlaneElem& FUN_0049f8b0(const PlaneElem& other);
};

struct PlaneArray
{
    virtual void v0();
    virtual PlaneElem* Allocate(unsigned int count);

    PlaneElem* data;
    unsigned int size;
    unsigned int capacity;

    bool FUN_00438b90();
    unsigned int FUN_009a3910();
    void FUN_006c8bd0(PlaneElem* dst, PlaneElem* src, unsigned int count);
    void ConstructElements(PlaneElem* p, unsigned int count);
    void FUN_006a8500();
    unsigned int AppendPlane(const PlaneElem& elem);
    void FUN_0049f690(unsigned int index, const PlaneElem& elem);
};

// Inserts elem at index, growing the buffer if needed, shifting existing elements right and incrementing size.
// @fnv 0x0049f690
void PlaneArray::FUN_0049f690(unsigned int index, const PlaneElem& elem)
{
    if (index == size)
    {
        AppendPlane(elem);
        return;
    }
    if (FUN_00438b90())
    {
        PlaneElem* pNewBuffer2;
        unsigned int uiNewSize;
        uiNewSize = FUN_009a3910();
        pNewBuffer2 = Allocate(uiNewSize);
        FUN_006c8bd0(pNewBuffer2, data, index);
        ConstructElements(pNewBuffer2 + index, 1);
        FUN_006c8bd0(pNewBuffer2 + index + 1, data + index, size - index);
        FUN_006a8500();
        data = pNewBuffer2;
        capacity = uiNewSize;
    }
    else
    {
        FUN_006c8bd0(data + index + 1, data + index, size - index);
        ConstructElements(data + index, 1);
    }
    size++;
    data[index].FUN_0049f8b0(elem);
}

struct FUN_0049f7d0_elem
{
    int unk00;
    int unk04;
    int unk08;
};

class FUN_0049f7d0_cls
{
  public:
    int unk00;
    FUN_0049f7d0_elem* m_04;
    unsigned int m_08;

    int FindIndexIf(int a1, unsigned int start, bool(__cdecl* pred)(FUN_0049f7d0_elem*, int));
};

// Scans the element array from start, returning the first index whose element satisfies pred, or -1 if none match.
// @fnv 0x0049f7d0
int FUN_0049f7d0_cls::FindIndexIf(int a1, unsigned int start, bool(__cdecl* pred)(FUN_0049f7d0_elem*, int))
{
    unsigned int i;
    for (i = start; i < m_08; i++)
    {
        if (m_04 != 0)
        {
            if (pred(&m_04[i], a1))
            {
                return i;
            }
        }
    }
    return -1;
}

void* __cdecl operator new(unsigned int uiSize, void* pvMem);
void __cdecl operator delete(void* pvObject, void* pvMem);

struct B49F8F0Entry
{
    int unk00;
    int unk04;
    int unk08;

    B49F8F0Entry();
};

class B49F8F0Allocator
{
  public:
    void ConstructEntries(B49F8F0Entry* pkArray, unsigned int ItemUpdateArray);
};

// Constructs each of the given number of B49F8F0Entry elements in place in the array.
// @fnv 0x0049f8f0
void B49F8F0Allocator::ConstructEntries(B49F8F0Entry* pkArray, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        new (&pkArray[i]) B49F8F0Entry;
}

void* __cdecl operator new(unsigned int size, void* where);
void __cdecl operator delete(void*, void*);
struct FUN_0049f1c0
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    FUN_0049f1c0();
    ~FUN_0049f1c0();
};
// Default-constructs count FUN_0049f1c0 objects in place at elements, each 16 bytes apart.
// @fnv 0x0049fb50
void FUN_0049fbf0_class::ConstructElements(void* elements, unsigned int count)
{
    for (unsigned int index = 0; index < count; ++index)
    {
        new (static_cast<char*>(elements) + index * 16) FUN_0049f1c0;
    }
}

class StrList487
{
  public:
    StrList487();
    ~StrList487();

    void* m_pkHead;
    void* m_pkTail;
    int m_iArrayLength;
    int unk0C;
};

class Base487
{
  public:
    Base487();

    virtual void Update();
};

class FUN_00487650 : public Base487
{
  public:
    FUN_00487650();

    void Init();

    StrList487 m_kFirst;
    StrList487 m_kSecond;
};

// Initializes the object by calling Init().
// @fnv 0x00487650
FUN_00487650::FUN_00487650()
{
    Init();
}

struct Entry487a60
{
    int value;
    unsigned short type;
    unsigned short priority;
    int data;
    Entry487a60();
};

struct Node487a60
{
    Entry487a60*& GetItem();
    Node487a60* GetNext();
    void InsertBefore(Entry487a60*& item);
    void InsertAfter(Entry487a60*& item);
};

struct Owner487a60
{
    Node487a60* GetList();
    Entry487a60* InsertEntryByPriority(unsigned short priority, unsigned short type, int value, int data);
};

// @fnv 0x00487a60
Entry487a60* Owner487a60::InsertEntryByPriority(unsigned short priority, unsigned short type, int value, int data)
{
    Entry487a60* entry = 0;
    Node487a60* node = GetList();
    Node487a60* prev = 0;
    while (node)
    {
        Entry487a60* item = node->GetItem();
        if (item)
        {
            if (item->priority > priority)
                break;
            prev = node;
        }
        node = node->GetNext();
    }
    entry = new Entry487a60;
    entry->value = value;
    entry->priority = priority;
    entry->type = type;
    entry->data = data;
    if (node)
        node->InsertBefore(entry);
    else if (prev)
        prev->InsertAfter(entry);
    else
        GetList()->InsertAfter(entry);
    return entry;
}

struct VObj
{
    virtual int Call0(int);
    virtual void Mid1();
    virtual void Mid2();
    virtual int Call3();
    void FUN_00a5c480(void*);
};
struct AVObj
{
    void* FUN_00a5c570(void*);
    void FUN_00a5c480(void*);
    void FUN_0048fef0(float);
    void ClearEntries();
    VObj* FUN_0055b980();
};
struct NP
{
    void* p;
    ~NP();
    AVObj* FUN_00559450();
    NP& FUN_0066b0d0(void*);
};
struct ListX
{
    int head;
    ~ListX();
    bool FUN_008256d0();
    void** FUN_006815c0();
    ListX* FUN_00726070();
    void FUN_00470470();
};
struct MapObj
{
    virtual int Call0(int);
    void* FUN_004b9ba0();
    void GetNextEntry(void**, void**, VObj**);
    void FUN_00438af0();
};
struct Loader
{
    void FUN_00445430(void*);
};
struct ItemObj
{
    void FinishScriptRunLockIfActive();
};
extern Loader* DAT_011c3b3c;
extern int DAT_011f36bc;
extern int DAT_011f36e4;
void __cdecl FormHeap_Free(void*);
struct FUN_0048fb50
{
    void* f00;
    int f04;
    NP m8;
    void* f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
    int f70;
    int f74;
    int f78;
    int f7c;
    int f80;
    int f84;
    int f88;
    int f8c;
    int f90;
    int f94;
    int f98;
    int f9c;
    int fa0;
    int fa4;
    int fa8;
    int fac;
    int fb0;
    int fb4;
    int fb8;
    int fbc;
    int fc0;
    int fc4;
    int fc8;
    int fcc;
    int fd0;
    int fd4;
    NP mD8;
    MapObj* mapPtr;
    int fe0;
    int fe4;
    int fe8;
    int fec;
    int ff0;
    int ff4;
    int ff8;
    int ffc;
    int f100;
    ListX m104;
    int f108;
    int f10c;
    int f110;
    int f114;
    int f118;
    int f11c;
    int f120;
    NP m124;
    NP m128;
    NP m12c[2];
    ListX m134;
    void FUN_0048ff50();
    ~FUN_0048fb50();
};
// @fnv 0x0048fb50
FUN_0048fb50::~FUN_0048fb50()
{
    void* itemCopy2;
    MapObj* copyMapA0;
    MapObj* copyMapB9;
    VObj* copyA;
    VObj* copyB4;
    void* itemValB2;
    ListX* nodeBq;
    void* item3;
    void* outKey3;
    VObj* outVal;
    VObj* acopyP;
    void* ctlB0;
    VObj* objP_c;
    void* ctrlA_b;
    ListX* nodeA5;
    void* pos5;
    FUN_0048ff50();
    DAT_011c3b3c->FUN_00445430(this);
    if (mD8.FUN_00559450())
    {
        ctrlA_b = m8.FUN_00559450() ? m8.FUN_00559450()->FUN_00a5c570((void*)&DAT_011f36bc) : 0;
        ctlB0 = m8.FUN_00559450() ? m8.FUN_00559450()->FUN_00a5c570((void*)&DAT_011f36e4) : 0;
        if (ctrlA_b)
            m8.FUN_00559450()->FUN_00a5c480(ctrlA_b);
        if (ctlB0)
            m8.FUN_00559450()->FUN_00a5c480(ctlB0);
        mD8.FUN_00559450()->FUN_0048fef0(0.0f);
        mD8.FUN_00559450()->ClearEntries();
        objP_c = mD8.FUN_00559450()->FUN_0055b980();
        if (objP_c)
        {
            if (objP_c->Call3())
            {
                acopyP = objP_c;
                acopyP->FUN_00a5c480(mD8.FUN_00559450());
            }
        }
        mD8.FUN_0066b0d0(0);
    }
    pos5 = mapPtr->FUN_004b9ba0();
    while (pos5 != 0)
    {
        outVal = 0;
        mapPtr->GetNextEntry(&pos5, &outKey3, &outVal);
        if (outVal != 0)
        {
            copyA = outVal;
            copyB4 = copyA;
            copyB4 ? copyB4->Call0(1) : 0;
        }
    }
    nodeA5 = &m104;
    while (nodeA5 != 0 && nodeA5->FUN_008256d0() == false)
    {
        item3 = *nodeA5->FUN_006815c0();
        ((ItemObj*)item3)->FinishScriptRunLockIfActive();
        nodeA5 = nodeA5->FUN_00726070();
    }
    m104.FUN_00470470();
    mapPtr->FUN_00438af0();
    copyMapA0 = mapPtr;
    copyMapB9 = copyMapA0;
    copyMapB9 ? copyMapB9->Call0(1) : 0;
    mapPtr = 0;
    f0c = 0;
    if (!m134.FUN_008256d0())
    {
        nodeBq = &m134;
        while (nodeBq != 0)
        {
            itemValB2 = *nodeBq->FUN_006815c0();
            itemCopy2 = itemValB2;
            FormHeap_Free(itemCopy2);
            nodeBq = nodeBq->FUN_00726070();
        }
        m134.FUN_00470470();
    }
}

// Load v4 worker5: Animation load-from-buffer transcription.
struct TESIdleForm : TESForm
{
};
struct BGSLoadFormBuffer;
struct Actor;
struct BaseProcess;
struct Animation;
struct KFModel;
struct Biped;
struct ExtraDataList;
struct MyNode;

struct NiMemObject
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct AnimIdleStub : NiMemObject
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
    AnimIdleStub(TESIdleForm* a, int b, int c, Actor* d, int e, Animation* f);
};
struct PtrBox
{
    void* p;
    void* FUN_00559450();
};
struct FUN_004f0040_shell
{
    void UpdateControls(float a);
};
struct F48fef0
{
    void FUN_0048fef0(float value);
};
struct FUN_004970e0_shell
{
    void AssignGO(void* a);
};
struct F497c10
{
    void LoadAnimationData(BGSLoadFormBuffer* buffer, void* a);
};
struct hkpTypedBroadPhaseHandle
{
    unsigned int FUN_0044ddc0();
};
struct FUN_0047b470_This
{
    bool FUN_0047b470();
};
struct ThisStub
{
    void FUN_00493bd0();
};
struct FUN_00639aa0_shell
{
    float FUN_00639aa0();
};
struct FUN_0098adb0_shell
{
    void FUN_0098adb0(float a);
};
struct HX
{
    void FUN_004efd10(BGSLoadFormBuffer* a, float b);
};
struct FUN_004eeb00
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
    int f70;
    int f74;
    FUN_004eeb00();
    ~FUN_004eeb00();
};
struct BSSimpleList_standin
{
    void* m_pFirstNode;
    int m_uiItemCount;
    bool IsEmpty();
    void** FUN_006815c0();
    void FUN_0063f7b0();
};
struct FUN_005ae3d0_S
{
    void FUN_005ae3d0(ExtraDataList** a);
};
struct PlayerCharacter;
extern PlayerCharacter* g_thePlayer;
TESForm* __cdecl LookupFormByID(unsigned int a);
MyNode* __cdecl FUN_00c802d0(MyNode* a);
void __cdecl SetFlagRecursive(int a, void* b);
void __fastcall FinishScriptRunLockIfActive(void* a);
void __fastcall FUN_00498290(Animation* a);
void* __cdecl operator new(unsigned int);
struct BaseProcess
{
    virtual void vp0();
    virtual void vp1();
    virtual void vp2();
    virtual void vp3();
    virtual void vp4();
    virtual void vp5();
    virtual void vp6();
    virtual void vp7();
    virtual void vp8();
    virtual void vp9();
    virtual void vp10();
    virtual void vp11();
    virtual void vp12();
    virtual void vp13();
    virtual void vp14();
    virtual void vp15();
    virtual void vp16();
    virtual void vp17();
    virtual void vp18();
    virtual void vp19();
    virtual void vp20();
    virtual void vp21();
    virtual void vp22();
    virtual void vp23();
    virtual void vp24();
    virtual void vp25();
    virtual void vp26();
    virtual void vp27();
    virtual void vp28();
    virtual void vp29();
    virtual void vp30();
    virtual void vp31();
    virtual void vp32();
    virtual void vp33();
    virtual void vp34();
    virtual void vp35();
    virtual void vp36();
    virtual void vp37();
    virtual void vp38();
    virtual void vp39();
    virtual void vp40();
    virtual void vp41();
    virtual void vp42();
    virtual void vp43();
    virtual void vp44();
    virtual void vp45();
    virtual void vp46();
    virtual void vp47();
    virtual void vp48();
    virtual void vp49();
    virtual void vp50();
    virtual void vp51();
    virtual void vp52();
    virtual void vp53();
    virtual void vp54();
    virtual void vp55();
    virtual void vp56();
    virtual void vp57();
    virtual void vp58();
    virtual void vp59();
    virtual void vp60();
    virtual void vp61();
    virtual void vp62();
    virtual void vp63();
    virtual void vp64();
    virtual void vp65();
    virtual void vp66();
    virtual void vp67();
    virtual void vp68();
    virtual void vp69();
    virtual void vp70();
    virtual void vp71();
    virtual void vp72();
    virtual void vp73();
    virtual void vp74();
    virtual void vp75();
    virtual void vp76();
    virtual void vp77();
    virtual void vp78();
    virtual void vp79();
    virtual void vp80();
    virtual void vp81();
    virtual void vp82();
    virtual void vp83();
    virtual void vp84();
    virtual void vp85();
    virtual void vp86();
    virtual void vp87();
    virtual void vp88();
    virtual void vp89();
    virtual void vp90();
    virtual void vp91();
    virtual void vp92();
    virtual void vp93();
    virtual void vp94();
    virtual void vp95();
    virtual void vp96();
    virtual void vp97();
    virtual void vp98();
    virtual void vp99();
    virtual void vp100();
    virtual void vp101();
    virtual void vp102();
    virtual void vp103();
    virtual void vp104();
    virtual void vp105();
    virtual void vp106();
    virtual void vp107();
    virtual void vp108();
    virtual void vp109();
    virtual void vp110();
    virtual void vp111();
    virtual void vp112();
    virtual void vp113();
    virtual void vp114();
    virtual void V1cc(unsigned char a, void* b, void* c, void* d);
    virtual void vp116();
    virtual void vp117();
    virtual void V1d8(void* a);
    virtual void vp119();
    virtual void vp120();
    virtual void vp121();
    virtual void vp122();
    virtual void vp123();
    virtual void vp124();
    virtual void vp125();
    virtual void vp126();
    virtual void vp127();
    virtual void vp128();
    virtual void vp129();
    virtual void vp130();
    virtual void vp131();
    virtual void vp132();
    virtual void vp133();
    virtual void vp134();
    virtual void vp135();
    virtual void vp136();
    virtual void vp137();
    virtual void vp138();
    virtual void vp139();
    virtual void vp140();
    virtual void vp141();
    virtual void vp142();
    virtual void vp143();
    virtual void vp144();
    virtual void vp145();
    virtual void vp146();
    virtual void vp147();
    virtual void vp148();
    virtual void vp149();
    virtual void vp150();
    virtual void vp151();
    virtual void vp152();
    virtual void vp153();
    virtual void vp154();
    virtual void vp155();
    virtual void vp156();
    virtual void vp157();
    virtual void vp158();
    virtual void vp159();
    virtual void vp160();
    virtual void vp161();
    virtual void vp162();
    virtual void vp163();
    virtual void vp164();
    virtual void vp165();
    virtual void vp166();
    virtual void vp167();
    virtual void vp168();
    virtual void vp169();
    virtual void vp170();
    virtual void vp171();
    virtual void vp172();
    virtual void vp173();
    virtual void vp174();
    virtual void vp175();
    virtual void vp176();
    virtual void vp177();
    virtual void vp178();
    virtual void vp179();
    virtual void vp180();
    virtual void vp181();
    virtual void vp182();
    virtual void vp183();
    virtual void vp184();
    virtual void vp185();
    virtual void vp186();
    virtual void vp187();
    virtual void vp188();
    virtual void vp189();
    virtual void vp190();
    virtual void vp191();
    virtual void vp192();
    virtual void vp193();
    virtual void vp194();
    virtual void vp195();
    virtual void vp196();
    virtual void vp197();
    virtual void vp198();
    virtual void vp199();
    virtual void vp200();
    virtual void vp201();
    virtual void vp202();
    virtual void vp203();
    virtual void vp204();
    virtual void vp205();
    virtual void vp206();
    virtual void vp207();
    virtual void vp208();
    virtual void vp209();
    virtual void vp210();
    virtual void vp211();
    virtual void vp212();
    virtual void vp213();
    virtual void vp214();
    virtual void vp215();
    virtual void vp216();
    virtual void vp217();
    virtual void vp218();
    virtual void vp219();
    virtual void vp220();
    virtual void vp221();
    virtual void vp222();
    virtual void vp223();
    virtual void vp224();
    virtual void vp225();
    virtual void vp226();
    virtual void vp227();
    virtual void vp228();
    virtual void vp229();
    virtual void vp230();
    virtual void vp231();
    virtual void vp232();
    virtual void vp233();
    virtual void vp234();
    virtual void vp235();
    virtual void vp236();
    virtual void vp237();
    virtual void vp238();
    virtual void vp239();
    virtual void vp240();
    virtual void vp241();
    virtual void vp242();
    virtual void vp243();
    virtual void vp244();
    virtual void vp245();
    virtual void vp246();
    virtual void vp247();
    virtual void vp248();
    virtual void vp249();
    virtual void vp250();
    virtual void V3ec(int a, void* b);
    virtual void vp252();
    virtual void vp253();
    virtual void vp254();
    virtual void vp255();
    virtual void vp256();
    virtual void vp257();
    virtual void vp258();
    virtual void vp259();
    virtual void vp260();
    virtual void vp261();
    virtual void vp262();
    virtual void vp263();
    virtual void vp264();
    virtual void vp265();
    virtual void vp266();
    virtual void vp267();
    virtual void vp268();
    virtual void vp269();
    virtual void vp270();
    virtual void vp271();
    virtual void vp272();
    virtual void vp273();
    virtual void vp274();
    virtual void vp275();
    virtual void vp276();
    virtual unsigned char V454();
    virtual void vp278();
    virtual void vp279();
    virtual void vp280();
    virtual void vp281();
    virtual void vp282();
    virtual void vp283();
    virtual void vp284();
    virtual void vp285();
    virtual void vp286();
    virtual void vp287();
    virtual void vp288();
    virtual void vp289();
    virtual void vp290();
    virtual void vp291();
    virtual void vp292();
    virtual void vp293();
    virtual void vp294();
    virtual void vp295();
    virtual void vp296();
    virtual void vp297();
    virtual void vp298();
    virtual void vp299();
    virtual void vp300();
    virtual void vp301();
    virtual void vp302();
    virtual void vp303();
    virtual void vp304();
    virtual void vp305();
    virtual void vp306();
    virtual void vp307();
    virtual void vp308();
    virtual void vp309();
    virtual void vp310();
    virtual void V4dc(void* a, void* b);
    virtual void vp312();
    virtual void vp313();
    virtual void vp314();
    virtual void vp315();
    virtual void vp316();
    virtual void vp317();
    virtual void vp318();
    virtual void vp319();
    virtual void vp320();
    virtual void vp321();
    virtual void vp322();
    virtual void vp323();
    virtual void vp324();
    virtual void vp325();
    virtual void vp326();
    virtual void vp327();
    virtual void vp328();
    virtual void vp329();
    virtual void vp330();
    virtual void vp331();
    virtual void vp332();
    virtual void vp333();
    virtual void vp334();
    virtual void vp335();
    virtual void vp336();
    virtual void vp337();
    virtual void vp338();
    virtual void vp339();
    virtual void vp340();
    virtual void vp341();
    virtual void vp342();
    virtual void vp343();
    virtual void vp344();
    virtual void vp345();
    virtual void vp346();
    virtual void vp347();
    virtual void vp348();
    virtual void vp349();
    virtual void vp350();
    virtual void vp351();
    virtual void vp352();
    virtual void vp353();
    virtual void vp354();
    virtual void vp355();
    virtual void vp356();
    virtual void vp357();
    virtual void vp358();
    virtual void vp359();
    virtual void vp360();
    virtual void vp361();
    virtual void vp362();
    virtual void vp363();
    virtual void vp364();
    virtual void vp365();
    virtual void vp366();
    virtual void vp367();
    virtual void vp368();
    virtual void vp369();
    virtual void vp370();
    virtual void vp371();
    virtual void vp372();
    virtual void vp373();
    virtual void vp374();
    virtual void vp375();
    virtual void vp376();
    virtual void vp377();
    virtual void vp378();
    virtual void vp379();
    virtual void vp380();
    virtual void vp381();
    virtual void vp382();
    virtual void vp383();
    virtual void vp384();
    virtual void vp385();
    virtual void vp386();
    virtual void vp387();
    virtual void vp388();
    virtual void vp389();
    virtual void vp390();
    virtual void V61c();
};
struct Actor
{
    virtual void vp0();
    virtual void vp1();
    virtual void vp2();
    virtual void vp3();
    virtual void vp4();
    virtual void vp5();
    virtual void vp6();
    virtual void vp7();
    virtual void vp8();
    virtual void vp9();
    virtual void vp10();
    virtual void vp11();
    virtual void vp12();
    virtual void vp13();
    virtual void vp14();
    virtual void vp15();
    virtual void vp16();
    virtual void vp17();
    virtual void vp18();
    virtual void vp19();
    virtual void vp20();
    virtual void vp21();
    virtual void vp22();
    virtual void vp23();
    virtual void vp24();
    virtual void vp25();
    virtual void vp26();
    virtual void vp27();
    virtual void vp28();
    virtual void vp29();
    virtual void vp30();
    virtual void vp31();
    virtual void vp32();
    virtual void vp33();
    virtual void vp34();
    virtual void vp35();
    virtual void vp36();
    virtual void vp37();
    virtual void vp38();
    virtual void vp39();
    virtual void vp40();
    virtual void vp41();
    virtual void vp42();
    virtual void vp43();
    virtual void vp44();
    virtual void vp45();
    virtual void vp46();
    virtual void vp47();
    virtual void vp48();
    virtual void vp49();
    virtual void vp50();
    virtual void vp51();
    virtual void vp52();
    virtual void vp53();
    virtual void vp54();
    virtual void vp55();
    virtual void vp56();
    virtual void vp57();
    virtual void vp58();
    virtual void vp59();
    virtual void vp60();
    virtual void vp61();
    virtual void vp62();
    virtual void vp63();
    virtual void vp64();
    virtual void vp65();
    virtual void vp66();
    virtual void vp67();
    virtual void vp68();
    virtual void vp69();
    virtual void vp70();
    virtual void vp71();
    virtual void vp72();
    virtual void vp73();
    virtual void vp74();
    virtual void vp75();
    virtual void vp76();
    virtual void vp77();
    virtual void vp78();
    virtual void vp79();
    virtual void vp80();
    virtual void vp81();
    virtual void vp82();
    virtual void vp83();
    virtual void vp84();
    virtual void vp85();
    virtual void vp86();
    virtual void vp87();
    virtual void vp88();
    virtual void vp89();
    virtual void vp90();
    virtual void vp91();
    virtual void vp92();
    virtual void vp93();
    virtual void vp94();
    virtual void vp95();
    virtual void vp96();
    virtual void vp97();
    virtual void vp98();
    virtual void vp99();
    virtual void vp100();
    virtual void vp101();
    virtual void vp102();
    virtual void vp103();
    virtual void vp104();
    virtual void vp105();
    virtual void vp106();
    virtual void vp107();
    virtual void vp108();
    virtual void vp109();
    virtual void vp110();
    virtual void vp111();
    virtual void vp112();
    virtual void vp113();
    virtual void vp114();
    virtual void vp115();
    virtual void vp116();
    virtual void vp117();
    virtual void vp118();
    virtual void vp119();
    virtual void vp120();
    virtual void vp121();
    virtual void* V1e8();
    virtual void vp123();
    virtual void vp124();
    virtual void vp125();
    virtual void vp126();
    virtual void vp127();
    virtual void vp128();
    virtual void vp129();
    virtual void vp130();
    virtual void vp131();
    virtual void vp132();
    virtual void vp133();
    virtual void vp134();
    virtual void vp135();
    virtual void vp136();
    virtual void vp137();
    virtual void vp138();
    virtual unsigned char V22c(int a);
    virtual void vp140();
    virtual void vp141();
    virtual void vp142();
    virtual void vp143();
    virtual void vp144();
    virtual void vp145();
    virtual void vp146();
    virtual void vp147();
    virtual void vp148();
    virtual void vp149();
    virtual void vp150();
    virtual void vp151();
    virtual void vp152();
    virtual void vp153();
    virtual void vp154();
    virtual void vp155();
    virtual void vp156();
    virtual void vp157();
    virtual void vp158();
    virtual void vp159();
    virtual void vp160();
    virtual void vp161();
    virtual void vp162();
    virtual void vp163();
    virtual void vp164();
    virtual void vp165();
    virtual void vp166();
    virtual void vp167();
    virtual void vp168();
    virtual void vp169();
    virtual void vp170();
    virtual void vp171();
    virtual void vp172();
    virtual void vp173();
    virtual void vp174();
    virtual void vp175();
    virtual void vp176();
    virtual void vp177();
    virtual void vp178();
    virtual void vp179();
    virtual void vp180();
    virtual void vp181();
    virtual void vp182();
    virtual void vp183();
    virtual void vp184();
    virtual void vp185();
    virtual unsigned char V2e8();
    BaseProcess* GetProcess();
};
struct BGSLoadFormBuffer
{
    virtual void vp0();
    virtual void vp1();
    virtual void vp2();
    virtual Actor* V3();
    void FUN_00864980(void* a, int b);
    int FUN_00864a60();
    unsigned int FUN_008648a0();
    bool FUN_008648e0(int* a);
    void AddToOffset(int a);
};
struct PlayerCharacter : Actor
{
    Animation* GetAnimation(bool a);
    Biped* FUN_00950b00(bool a);
};
struct AnimPosition
{
    float x;
    float y;
    float z;
};
struct LoadedIdle
{
    TESIdleForm* idle;
    int value;
};
struct AnimSelf
{
    int m_00;
    int m_04;
    PtrBox m_08;
    int m_0c;
    AnimPosition m_10;
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
    unsigned short m_4c[8];
    int m_5c[8];
    int m_7c[8];
    unsigned short m_9c[8];
    int m_ac[8];
    unsigned char m_cc;
    unsigned char m_cd;
    unsigned char m_ce;
    unsigned char m_cf;
    float m_d0;
    int m_d4;
    PtrBox m_d8;
    int m_dc;
    HX* m_e0[8];
    int m_100;
    BSSimpleList_standin m_104;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    unsigned char m_120;
    unsigned char m_121;
    unsigned short m_122;
    GO m_124;
    int m_128;
    int m_12c;
    int m_130;
    FUN_005ae3d0_S m_134;
    bool AddAnimation(KFModel* a, bool b);
    void FUN_004955c0(int a, int b, int c, float d, int e);
    void FUN_004974a0();
    void FUN_00496080(int a, float b);
    void FUN_00496280();
    void FUN_0049bca0(float a, void* b, int c);
    void __thiscall Load(BGSLoadFormBuffer* buf);
};

// Loads animation state from a BGSLoadFormBuffer: clears the animation list, restores process, idle, slot and mask data, and applies transforms.
// @fnv 0x0049b050
void __thiscall AnimSelf::Load(BGSLoadFormBuffer* apBuffer)
{
    if (m_08.FUN_00559450() == 0)
        return;
    unsigned char actor2;
    short groupA5;
    char slotX;
    char slot7;
    Actor* owner6 = apBuffer->V3();
    while (!m_104.IsEmpty())
    {
        void* item = *m_104.FUN_006815c0();
        AddAnimation((KFModel*)item, false);
        FinishScriptRunLockIfActive(item);
        m_104.FUN_0063f7b0();
    }
    owner6->GetProcess()->V4dc(owner6, this);
    if (owner6->V22c(0) || owner6->V2e8())
        FUN_004955c0(0x14, 0xe0, -1, 0.0f, -1);
    {
        actor2 = owner6->GetProcess()->V454();
        FUN_004974a0();
        if (owner6 == (Actor*)g_thePlayer)
        {
            if ((Animation*)this == g_thePlayer->GetAnimation(1))
                owner6->GetProcess()->V1cc(actor2, g_thePlayer->FUN_00950b00(1), this, g_thePlayer);
            else
                g_thePlayer->GetProcess()->V1cc(actor2, g_thePlayer->FUN_00950b00(0), this, g_thePlayer);
        }
        else
        {
            owner6->GetProcess()->V1cc(actor2, owner6->V1e8(), this, owner6);
        }
    }
    owner6->GetProcess()->V1d8(owner6);
    owner6->GetProcess()->V61c();
    owner6->GetProcess()->V3ec(-1, 0);
    {
        unsigned int bProc;
        for (bProc = 0; bProc < 8; bProc++)
        {
            if (m_e0[bProc] != 0)
            {
                float ftmp = ((FUN_00639aa0_shell*)m_e0[bProc])->FUN_00639aa0();
                ((FUN_0098adb0_shell*)m_e0[bProc])
                    ->FUN_0098adb0(((FUN_00508100_shell*)m_e0[bProc])->FUN_00508100() + ftmp);
            }
        }
    }
    FUN_0049bca0(m_d0, &m_1c, 1);
    ((FUN_004f0040_shell*)m_08.FUN_00559450())->UpdateControls(m_d0);
    MyNode* node9 = FUN_00c802d0((MyNode*)m_08.FUN_00559450());
    unsigned char valid6 = node9 != 0 ? ((FUN_0047b470_This*)node9)->FUN_0047b470() : false;
    if (valid6)
        SetFlagRecursive(0, m_08.FUN_00559450());
    ((ThisStub*)this)->FUN_00493bd0();
    if (valid6)
        SetFlagRecursive(valid6, m_08.FUN_00559450());
    FUN_00496080(0x14, 0.0f);
    FUN_00496280();
    if (m_d8.FUN_00559450() != 0)
        ((F48fef0*)m_d8.FUN_00559450())->FUN_0048fef0(0.0f);
    apBuffer->FUN_00864980(&m_10c, 4);
    apBuffer->FUN_00864980(&m_110, 4);
    apBuffer->FUN_00864980(&m_10, 0xc);
    apBuffer->FUN_00864980(&m_48, 4);
    apBuffer->FUN_00864980(&m_cc, 1);
    apBuffer->FUN_00864980(&m_d4, 4);
    apBuffer->FUN_00864980(&m_122, 2);
    {
        int count = apBuffer->FUN_00864a60();
        unsigned int j;
        for (j = 0; j < (unsigned int)count; j++)
        {
            LoadedIdle* rawNew = new LoadedIdle;
            rawNew->idle = dynamic_cast<TESIdleForm*>(LookupFormByID(apBuffer->FUN_008648a0()));
            apBuffer->FUN_00864980(&rawNew->value, 4);
            m_134.FUN_005ae3d0((ExtraDataList**)&rawNew);
        }
    }
    int formA5;
    formA5 = 0;
    unsigned char flags6 = apBuffer->FUN_008648e0(&formA5);
    if (flags6)
    {
        apBuffer->AddToOffset(apBuffer->FUN_00864a60());
    }
    else if (formA5 != 0)
    {
        formA5 = formA5 != 0 ? (int)dynamic_cast<TESIdleForm*>(LookupFormByID((unsigned int)formA5)) : 0;
        if (formA5 == 0)
        {
            apBuffer->AddToOffset(apBuffer->FUN_00864a60());
        }
        else
        {
            apBuffer->FUN_00864a60();
            m_124 = new AnimIdleStub((TESIdleForm*)formA5, 7, 1, owner6, 1, (Animation*)0);
            ((F497c10*)((PtrBox*)&m_124)->FUN_00559450())->LoadAnimationData(apBuffer, this);
        }
    }
    char maskTmp;
    maskTmp = 0;
    apBuffer->FUN_00864980(&maskTmp, 1);
    {
        unsigned int k;
        for (k = 0; k < 8; k++)
        {
            if (maskTmp & (1 << k))
            {
                apBuffer->FUN_00864980(&m_4c[k], 2);
                apBuffer->FUN_00864980(&m_5c[k], 4);
                apBuffer->FUN_00864980(&m_9c[k], 2);
                apBuffer->FUN_00864980(&m_7c[k], 4);
                apBuffer->FUN_00864980(&m_ac[k], 4);
                m_e0[k] = 0;
                char b49;
                b49 = -1;
                apBuffer->FUN_00864980(&b49, 1);
                if (b49 != -2)
                {
                    FUN_004974a0();
                    FUN_004955c0(k, m_4c[k], m_5c[k], m_d0, (unsigned char)b49);
                    if (m_e0[k] != 0)
                    {
                        m_e0[k]->FUN_004efd10(apBuffer, m_d0);
                    }
                    else
                    {
                        FUN_004eeb00 obj;
                        ((HX*)&obj)->FUN_004efd10(apBuffer, m_d0);
                        FUN_00496080(k, 0.0f);
                    }
                }
            }
        }
    }
    apBuffer->FUN_00864980(&m_120, 1);
    {
        groupA5 = -1;
        slotX = -1;
        apBuffer->FUN_00864980(&groupA5, 2);
        apBuffer->FUN_00864980(&slotX, 1);
        if (slotX != -1 && m_e0[slotX] != 0)
            owner6->GetProcess()->V3ec(groupA5, m_e0[slotX]);
    }
    {
        slot7 = -1;
        apBuffer->FUN_00864980(&slot7, 1);
        if (((PtrBox*)&m_124)->FUN_00559450() != 0)
        {
            if (slot7 != -1)
                ((FUN_004970e0_shell*)((PtrBox*)&m_124)->FUN_00559450())->AssignGO(m_e0[slot7]);
            if (((hkpTypedBroadPhaseHandle*)((PtrBox*)&m_124)->FUN_00559450())->FUN_0044ddc0() == 1)
            {
                FUN_004974a0();
                FUN_00498290((Animation*)this);
            }
        }
    }
    FUN_0049bca0(m_d0, &m_1c, 1);
    ((FUN_004f0040_shell*)m_08.FUN_00559450())->UpdateControls(m_d0);
}

struct ArrElem12
{
    int a;
    int b;
    int c;
};

struct ArrElem12Array
{
    virtual void Unk00();
    virtual ArrElem12* Allocate(unsigned int count);

    ArrElem12* m_data;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;

    bool IsFull();
    unsigned int GetGrowSize();
    void MoveItems(ArrElem12* dest, ArrElem12* src, unsigned int count);
    void ConstructItems(ArrElem12* p, unsigned int count);
    void FreeData();
    void Append(const ArrElem12& item);

    void FUN_0049f270(unsigned int index, const ArrElem12& item);
};

// Inserts item at index, growing the array if full and shifting existing elements right; appends when index equals the count.
// @fnv 0x0049f270
void ArrElem12Array::FUN_0049f270(unsigned int index, const ArrElem12& item)
{
    if (index == m_iElementCount)
    {
        Append(item);
        return;
    }
    if (IsFull())
    {
        unsigned int newCapacity = GetGrowSize();
        ArrElem12* newData2 = Allocate(newCapacity);
        MoveItems(newData2, m_data, index);
        ConstructItems(newData2 + index, 1);
        MoveItems(newData2 + index + 1, m_data + index, m_iElementCount - index);
        FreeData();
        m_data = newData2;
        m_pRayCursor = newCapacity;
    }
    else
    {
        MoveItems(m_data + index + 1, m_data + index, m_iElementCount - index);
        ConstructItems(m_data + index, 1);
    }
    m_iElementCount++;
    m_data[index] = item;
}

struct FUN_00659210_Class
{
    int FUN_00659210(char c, int h);
};
struct FUN_00486df0_Map : FUN_00659210_Class
{
    int unk;
    unsigned int m_uiSize;
    unsigned int HashString(const char* s);
};
// Hashes the null-terminated string s with FUN_00659210 and returns the hash modulo m_uiSize.
// @fnv 0x00486df0
unsigned int FUN_00486df0_Map::HashString(const char* pcString)
{
    unsigned int h = 0;
    while (*pcString)
        h = FUN_00659210(*pcString++, h);
    return h % m_uiSize;
}

// Animation state SaveGame: header fields, the (form, value) list with a back-patched count,
// the active sequence block with a back-patched size, then the 8 animation group slots.
struct SaveBufN;
struct GroupSeqN
{
    void SaveGame(SaveBufN* pBuffer, float fTime);
};
struct ProcN
{
    virtual void p000(), p001(), p002(), p003(), p004(), p005(), p006(), p007(), p008(), p009();
    virtual void p010(), p011(), p012(), p013(), p014(), p015(), p016(), p017(), p018(), p019();
    virtual void p020(), p021(), p022(), p023(), p024(), p025(), p026(), p027(), p028(), p029();
    virtual void p030(), p031(), p032(), p033(), p034(), p035(), p036(), p037(), p038(), p039();
    virtual void p040(), p041(), p042(), p043(), p044(), p045(), p046(), p047(), p048(), p049();
    virtual void p050(), p051(), p052(), p053(), p054(), p055(), p056(), p057(), p058(), p059();
    virtual void p060(), p061(), p062(), p063(), p064(), p065(), p066(), p067(), p068(), p069();
    virtual void p070(), p071(), p072(), p073(), p074(), p075(), p076(), p077(), p078(), p079();
    virtual void p080(), p081(), p082(), p083(), p084(), p085(), p086(), p087(), p088(), p089();
    virtual void p090(), p091(), p092(), p093(), p094(), p095(), p096(), p097(), p098(), p099();
    virtual void p100(), p101(), p102(), p103(), p104(), p105(), p106(), p107(), p108(), p109();
    virtual void p110(), p111(), p112(), p113(), p114(), p115(), p116(), p117(), p118(), p119();
    virtual void p120(), p121(), p122(), p123(), p124(), p125(), p126(), p127(), p128(), p129();
    virtual void p130(), p131(), p132(), p133(), p134(), p135(), p136(), p137(), p138(), p139();
    virtual void p140(), p141(), p142(), p143(), p144(), p145(), p146(), p147(), p148(), p149();
    virtual void p150(), p151(), p152(), p153(), p154(), p155(), p156(), p157(), p158(), p159();
    virtual void p160(), p161(), p162(), p163(), p164(), p165(), p166(), p167(), p168(), p169();
    virtual void p170(), p171(), p172(), p173(), p174(), p175(), p176(), p177(), p178(), p179();
    virtual void p180(), p181(), p182(), p183(), p184(), p185(), p186(), p187(), p188(), p189();
    virtual void p190(), p191(), p192(), p193(), p194(), p195(), p196(), p197(), p198(), p199();
    virtual void p200(), p201(), p202(), p203(), p204(), p205(), p206(), p207(), p208(), p209();
    virtual void p210(), p211(), p212(), p213(), p214(), p215(), p216(), p217(), p218(), p219();
    virtual void p220(), p221(), p222(), p223(), p224(), p225(), p226(), p227(), p228(), p229();
    virtual void p230(), p231(), p232(), p233(), p234(), p235(), p236(), p237(), p238(), p239();
    virtual void p240(), p241(), p242(), p243(), p244(), p245(), p246(), p247(), p248();
    virtual unsigned short GetCurrentGroupID();
    virtual GroupSeqN* GetCurrentSequence();
};
struct RefN
{
    ProcN* GetProcess();
};
struct SaveBufN
{
    virtual void b0();
    virtual void b1();
    virtual RefN* GetRef();
    void SaveData(void* pData, unsigned int uiSize, int iFlags);
    void SerializeFormData(void* pForm, int iFlags);
    unsigned int GetPosition();
    void WriteAt(unsigned int uiValue, unsigned int uiPosition);
    unsigned int GetSize();
};
struct AnimDataN;
struct SeqN
{
    void* GetIdle();
    GroupSeqN* GetGroupSequence();
    void SaveSequence(SaveBufN* pBuffer, AnimDataN* pData);
};
struct SeqPtrN
{
    SeqN* m_pObject;
    operator SeqN*() const;
};
struct AnimN
{
    virtual void a0(), a1(), a2(), a3(), a4(), a5();
    virtual char GetState(GroupSeqN* pForwardSequence);
};
struct AnimMapN
{
    bool GetAt(unsigned short usKey, AnimN*& pValue) const;
};
struct ListItemN
{
    void* m_pForm;
    int m_iValue;
};
struct ListN
{
    ListItemN* m_pInventoryEntryData;
    ListN* m_pNext;
    ListItemN*& GetItem();
    ListN* GetNext();
};
struct Point3N
{
    float x, y, z;
};

struct AnimDataN
{
    int unk00, unk04, unk08, unk0c;
    Point3N m_kPos;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    int m_48;
    unsigned short m_ausGroup[8];
    int m_ai5c[8];
    int m_ai7c[8];
    unsigned short m_aus9c[8];
    int m_aiac[8];
    unsigned char m_ucc;
    unsigned char unkcd;
    unsigned short unkce;
    float m_fTime;
    int m_d4;
    int unkd8;
    AnimMapN* m_pMapObject;
    GroupSeqN* m_apSeq[8];
    int unk100, unk104, unk108;
    int m_10c;
    int m_110;
    int unk114, unk118, unk11c;
    unsigned char m_uc120;
    unsigned char unk121;
    unsigned short m_us122;
    SeqPtrN m_spSeq124;
    SeqPtrN m_spSeq128;
    int unk12c, unk130;
    ListN m_kList;

    void SaveAnimData(SaveBufN* pBuffer);
};

// Serializes animation data fields, the list of items, the current sequence and per-slot group state into the save buffer.
// @fnv 0x0049ab40
void AnimDataN::SaveAnimData(SaveBufN* pBuffer)
{
    RefN* pObject = pBuffer->GetRef();
    pBuffer->SaveData(&m_10c, 4, 0);
    pBuffer->SaveData(&m_110, 4, 0);
    pBuffer->SaveData(&m_kPos, 12, 0);
    pBuffer->SaveData(&m_48, 4, 0);
    pBuffer->SaveData(&m_ucc, 1, 0);
    pBuffer->SaveData(&m_d4, 4, 0);
    pBuffer->SaveData(&m_us122, 2, 0);

    int iCountTmp = 0;
    unsigned int uiCountPos_ = pBuffer->GetPosition();
    ListN* pIter = &m_kList;
    while (pIter)
    {
        ListItemN* pItem = pIter->GetItem();
        if (pItem)
        {
            pBuffer->SerializeFormData(pItem->m_pForm, 0);
            pBuffer->SaveData(&pItem->m_iValue, 4, 0);
            iCountTmp++;
        }
        pIter = pIter->GetNext();
    }
    pBuffer->WriteAt(iCountTmp, uiCountPos_);

    SeqN* pSequence = m_spSeq128 ? m_spSeq128 : m_spSeq124;
    pBuffer->SerializeFormData(pSequence ? pSequence->GetIdle() : 0, 0);
    if (pSequence && pSequence->GetIdle())
    {
        unsigned int uiPosition = pBuffer->GetPosition();
        unsigned int uiStartSize = pBuffer->GetSize();
        pSequence->SaveSequence(pBuffer, this);
        unsigned int uiEnd = pBuffer->GetSize();
        pBuffer->WriteAt(uiEnd - uiStartSize, uiPosition);
    }

    GroupSeqN* pBlend = 0;
    if (m_spSeq128 && m_spSeq124)
        pBlend = ((SeqN*)m_spSeq124)->GetGroupSequence();

    char cActiveMask = 0;
    for (unsigned int i = 0; i < 8; i++)
    {
        if (pBlend && m_apSeq[i] == pBlend)
            continue;
        if (m_ausGroup[i] != 0xff && m_ausGroup[i] != 0xffff)
            cActiveMask |= 1 << i;
    }
    pBuffer->SaveData(&cActiveMask, 1, 0);

    char cProcIdx = -1;
    unsigned short usGroupID = pObject->GetProcess()->GetCurrentGroupID();
    GroupSeqN* pCur2 = pObject->GetProcess()->GetCurrentSequence();
    char cSeqSlot = -1;
    GroupSeqN* pMainSeq = pSequence ? pSequence->GetGroupSequence() : 0;
    for (unsigned int j = 0; j < 8; j++)
    {
        if (pBlend && m_apSeq[j] == pBlend)
            continue;
        if (m_ausGroup[j] != 0xff && m_ausGroup[j] != 0xffff)
        {
            pBuffer->SaveData(&m_ausGroup[j], 2, 0);
            pBuffer->SaveData(&m_ai5c[j], 4, 0);
            pBuffer->SaveData(&m_aus9c[j], 2, 0);
            pBuffer->SaveData(&m_ai7c[j], 4, 0);
            pBuffer->SaveData(&m_aiac[j], 4, 0);
            AnimN* pAnim = 0;
            char cStatus = -1;
            if (m_pMapObject->GetAt(m_ausGroup[j], pAnim))
                cStatus = pAnim->GetState(m_apSeq[j]);
            if (m_apSeq[j] == 0)
                cStatus = -2;
            pBuffer->SaveData(&cStatus, 1, 0);
            if (m_apSeq[j])
                m_apSeq[j]->SaveGame(pBuffer, m_fTime);
            if (m_apSeq[j] == pCur2)
                cProcIdx = (char)j;
            if (m_apSeq[j] == pMainSeq)
                cSeqSlot = (char)j;
        }
    }
    pBuffer->SaveData(&m_uc120, 1, 0);
    pBuffer->SaveData(&usGroupID, 2, 0);
    pBuffer->SaveData(&cProcIdx, 1, 0);
    pBuffer->SaveData(&cSeqSlot, 1, 0);
}

struct SaveGameBufferAA8
{
    void FUN_008579b0(void* pvData, unsigned int uiSize);
};
extern SaveGameBufferAA8* DAT_011de45c;
struct ActorAnimDataAA8
{
    unsigned short GetSerializedSize(Actor* pkActor);
    void WriteToStream(Actor* pkActor);
};
// @fnv 0x0049aa80
void __cdecl FUN_0049aa80(Actor* pkActor, ActorAnimDataAA8* pkAnimData)
{
    unsigned short usAnimValue = 0;
    if (pkAnimData && !pkActor->V22c(0))
        usAnimValue = pkAnimData->GetSerializedSize(pkActor);
    DAT_011de45c->FUN_008579b0(&usAnimValue, 2);
    if (pkAnimData && !pkActor->V22c(0))
        pkAnimData->WriteToStream(pkActor);
}

struct MapBase49C
{
    virtual void v00();
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
    ~MapBase49C();
    void RemoveAll();
};
struct FUN_0049c510 : MapBase49C
{
    virtual void v00();
    ~FUN_0049c510();
};
// Destructor that calls RemoveAll to clear the hash table entries.
// @fnv 0x0049c510
FUN_0049c510::~FUN_0049c510()
{
    RemoveAll();
}

extern void* DAT_0101e07c;
class FUN_00439260
{
  public:
    FUN_00439260();
    ~FUN_00439260();
    unsigned int unk[6];
};
class FUN_0049ec80 : public FUN_00439260
{
  public:
    unsigned short m_usFlags;
    unsigned int m_uiCount;
    int m_iIndex;
    FUN_0049ec80();
    void FUN_0049ed90(int a);
    void FUN_0049edb0(int a);
    void FUN_00533fb0(int a);
    void FUN_0049ee10(int a);
    void FUN_0049ede0(int a);
    void FUN_0049ee30(int a);
};
// Constructor that sets the vtable, initialises m_usFlags, m_uiCount and m_iIndex, then calls the member initialisers.
// @fnv 0x0049ec80
FUN_0049ec80::FUN_0049ec80()
{
    *(void**)this = &DAT_0101e07c;
    m_usFlags = 0;
    m_uiCount = 0;
    m_iIndex = -1;
    FUN_0049ed90(0);
    FUN_0049edb0(4);
    FUN_00533fb0(0);
    FUN_0049ee10(0);
    FUN_0049ede0(3);
    FUN_0049ee30(0);
}

class AutoMemContext
{
    int previous;

  public:
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
};
extern const char DAT_0101e018[];
extern const float DAT_01013ea4;
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3(float, float, float);
};
struct PointChain
{
    virtual ~PointChain();
    NiPoint3* data;
    unsigned int size;
    unsigned int capacity;
    unsigned int FUN_0044ddc0();
    NiPoint3& FUN_006a7af0(int);
    NiPoint3& FUN_006ced70();
    NiPoint3& GetLastEdge();
    void AddItem(const NiPoint3&);
    void FUN_0049f270(unsigned int, const NiPoint3&);
    void FUN_0049f3c0(unsigned int, unsigned int, bool);
};
extern PointChain* DAT_011c57ac;
struct LandView
{
    NiPoint3 FUN_00535b30(int);
};
struct CellView
{
    float FUN_005471e0();
    LandView* FUN_00546fb0();
};
struct FUN_00c4cba0
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    FUN_00c4cba0(PointChain*);
    int FUN_0059bb30();
    void FUN_00c4cf00();
    void FUN_00c4cf80();
};
class FUN_0049e3e0
{
  public:
    ~FUN_0049e3e0();
};
struct FUN_0048f200
{
    void* head;
    void* tail;
    unsigned int count;
    FUN_0048f200();
    void FUN_0076b660(FUN_00c4cba0**);
    void* FUN_00559450();
    void* DereferenceIfNotNull(void*);
    FUN_00c4cba0*& AddEight(void*);
    FUN_00c4cba0* FUN_0049f590(void*&);
};
extern FUN_0048f200* DAT_011c57b0;
extern "C" bool __cdecl AreVectorsEqual(const NiPoint3&, const NiPoint3&, float);
bool __cdecl AnyPointInListMatches(FUN_00c4cba0*, FUN_00c4cba0*);

// Joins segment pairs from DAT_011c57ac into chains, adds closed chains as FUN_00c4cba0 to DAT_011c57b0, then removes entries that overlap another.
// @fnv 0x0049db60
void __cdecl BuildWaterSurfaces(CellView* cell)
{
    AutoMemContext context4(MEM_CONTEXT_MEM_CONTEXT_WATER, true, DAT_0101e018, 0x20a);
    while (DAT_011c57ac->FUN_0044ddc0() > 0)
    {
        PointChain* chainX = (PointChain*)new FUN_0049f1c0;
        chainX->AddItem(DAT_011c57ac->FUN_006a7af0(0));
        chainX->AddItem(DAT_011c57ac->FUN_006a7af0(1));
        DAT_011c57ac->FUN_0049f3c0(0, 2, true);
        bool changed3 = true;
        bool closed2 = false;
        while (changed3)
        {
            changed3 = false;
            int i3 = 0;
            while (i3 < (int)DAT_011c57ac->FUN_0044ddc0())
            {
                NiPoint3 b = DAT_011c57ac->FUN_006a7af0(i3);
                NiPoint3 a = DAT_011c57ac->FUN_006a7af0(i3 + 1);
                if (AreVectorsEqual(b, chainX->GetLastEdge(), DAT_01013ea4) &&
                    !AreVectorsEqual(a, chainX->FUN_006ced70(), DAT_01013ea4) &&
                    !AreVectorsEqual(a, chainX->FUN_006a7af0(chainX->FUN_0044ddc0() - 2), DAT_01013ea4))
                {
                    chainX->AddItem(a);
                    DAT_011c57ac->FUN_0049f3c0(i3, 2, true);
                    changed3 = true;
                    break;
                }
                else if (AreVectorsEqual(a, chainX->GetLastEdge(), DAT_01013ea4) &&
                         !AreVectorsEqual(b, chainX->FUN_006ced70(), DAT_01013ea4) &&
                         !AreVectorsEqual(b, chainX->FUN_006a7af0(chainX->FUN_0044ddc0() - 2), DAT_01013ea4))
                {
                    chainX->AddItem(b);
                    DAT_011c57ac->FUN_0049f3c0(i3, 2, true);
                    changed3 = true;
                    break;
                }
                else if (AreVectorsEqual(b, chainX->FUN_006ced70(), DAT_01013ea4) &&
                         !AreVectorsEqual(a, chainX->GetLastEdge(), DAT_01013ea4) &&
                         !AreVectorsEqual(a, chainX->FUN_006a7af0(1), DAT_01013ea4))
                {
                    chainX->FUN_0049f270(0, a);
                    DAT_011c57ac->FUN_0049f3c0(i3, 2, true);
                    changed3 = true;
                    break;
                }
                else if (AreVectorsEqual(a, chainX->FUN_006ced70(), DAT_01013ea4) &&
                         !AreVectorsEqual(b, chainX->GetLastEdge(), DAT_01013ea4) &&
                         !AreVectorsEqual(b, chainX->FUN_006a7af0(1), DAT_01013ea4))
                {
                    chainX->FUN_0049f270(0, b);
                    DAT_011c57ac->FUN_0049f3c0(i3, 2, true);
                    changed3 = true;
                    break;
                }
                else if ((AreVectorsEqual(b, chainX->GetLastEdge(), DAT_01013ea4) &&
                          AreVectorsEqual(a, chainX->FUN_006ced70(), DAT_01013ea4)) ||
                         (AreVectorsEqual(b, chainX->FUN_006ced70(), DAT_01013ea4) &&
                          AreVectorsEqual(a, chainX->GetLastEdge(), DAT_01013ea4)))
                {
                    closed2 = true;
                    i3 += 2;
                }
                else
                {
                    i3 += 2;
                }
            }
        }
        const int level3 = 0;
        NiPoint3 originX(cell->FUN_00546fb0()->FUN_00535b30(level3).x, cell->FUN_00546fb0()->FUN_00535b30(level3).y,
                         cell->FUN_005471e0());
        if (closed2)
        {
            FUN_00c4cba0* surface2 = new FUN_00c4cba0(chainX);
            if (surface2->FUN_0059bb30() > 2)
            {
                surface2->FUN_00c4cf00();
                surface2->FUN_00c4cf80();
                if (!DAT_011c57b0)
                    DAT_011c57b0 = new FUN_0048f200;
                DAT_011c57b0->FUN_0076b660(&surface2);
            }
            else
            {
                delete (FUN_0049e3e0*)surface2;
            }
        }
        else
        {
            delete chainX;
        }
    }
    if (DAT_011c57b0)
    {
        void* pos3 = DAT_011c57b0->FUN_00559450();
        void* next3 = 0;
        while (pos3)
        {
            next3 = DAT_011c57b0->DereferenceIfNotNull(pos3);
            if (pos3)
            {
                FUN_00c4cba0* other3 = DAT_011c57b0->AddEight(pos3);
                void* otherNextX = DAT_011c57b0->FUN_00559450();
                void* a = 0;
                while (otherNextX)
                {
                    a = DAT_011c57b0->DereferenceIfNotNull(otherNextX);
                    if (otherNextX)
                    {
                        FUN_00c4cba0* b = DAT_011c57b0->AddEight(otherNextX);
                        if (other3 != b && AnyPointInListMatches(other3, b))
                        {
                            DAT_011c57b0->FUN_0049f590(pos3);
                            break;
                        }
                    }
                    otherNextX = a;
                }
            }
            pos3 = next3;
        }
    }
}

extern "C" void* __cdecl _alloca(unsigned int);
void* __memcpy(void*, const void*, unsigned int);
void __cdecl BSEndian(unsigned char*, EndianSizeTag<1>);
struct TESFile
{
    unsigned int GetChunkSize();
    bool GetChunkData(void*, unsigned int);
    bool GetChunkData();
};
class TESModelList
{
  public:
    virtual ~TESModelList();
};

struct TgtOps
{
    void* GetPosition();
};
struct ListNodeStandIn
{
    void** FUN_006815c0();
    ListNodeStandIn* FUN_00726070();
};
struct FUN_00488fd0
{
    void* m0;
    void* m4;
    FUN_00488fd0();
};
struct S00489670
{
    void LoadTextureArchiveEntries(char*, unsigned char, TESForm*, void*);
};
struct FileEntryListCollection
{
    unsigned int m_uiCount;
    FileEntryList** m_ppArray;
    void ClearAndDeleteArray();
    void LoadFromTESFile(TESModelList* pOwner, TESFile* pFile);
};

// Reads a chunk from pFile, allocates m_ppArray, and loads texture archive entries for each FileEntryList from pOwner's model list.
// @fnv 0x0048a0d0
void FileEntryListCollection::LoadFromTESFile(TESModelList* pOwner, TESFile* pFile)
{
    unsigned int uiElapsedMilliseconds;
    {
        ListNodeStandIn* pNode;
        {
            char* pBuffer;
            {
                unsigned int uiSize;
                ClearAndDeleteArray();
                uiSize = pFile->GetChunkSize();
                pBuffer = (char*)_alloca(uiSize);
                pFile->GetChunkData(pBuffer, uiSize);
                __memcpy(this, pBuffer, 4);
                if (pFile->GetChunkData())
                    BSEndian((unsigned char*)this, EndianSizeTag<1>());
                uiElapsedMilliseconds = 4;
                m_ppArray = new FileEntryList*[m_uiCount];
                pNode = (ListNodeStandIn*)((TgtOps*)pOwner)->GetPosition();
                for (unsigned int i = 0; i < m_uiCount; i++)
                {
                    unsigned char ucEntryCount;
                    {
                        void* m_kModelObjectsItem = 0;
                        if (pNode)
                            m_kModelObjectsItem = *pNode->FUN_006815c0();
                        pNode = pNode->FUN_00726070();
                        m_ppArray[i] = (FileEntryList*)new FUN_00488fd0;
                        ucEntryCount = pBuffer[uiElapsedMilliseconds];
                        uiElapsedMilliseconds++;
                        ((S00489670*)m_ppArray[i])
                            ->LoadTextureArchiveEntries(pBuffer + uiElapsedMilliseconds, ucEntryCount,
                                                        dynamic_cast<TESForm*>(pOwner), m_kModelObjectsItem);
                        uiElapsedMilliseconds += ucEntryCount * 0x18;
                    }
                }
            }
        }
    }
}

class DistantTreeTextureInfo;
template <typename K, typename V> struct BSMapBase
{
    virtual ~BSMapBase();
};
struct FUN_0048b3b0 : BSMapBase<int, DistantTreeTextureInfo*>
{
    virtual ~FUN_0048b3b0();
};
// Destructor of a subclass of BSMapBase<int, DistantTreeTextureInfo*>; the body is empty.
// @fnv 0x0048b3b0
FUN_0048b3b0::~FUN_0048b3b0()
{}

struct FUN_0048b530 : NiTPointerMap<unsigned int, unsigned int>
{
    virtual ~FUN_0048b530();
};
// @fnv 0x0048b530
FUN_0048b530::~FUN_0048b530()
{}

// ---------------------------------------------------------------------------
// FUN_0049fe20 -- the destructor of the class whose constructor is at
// 0x0049fcd0 (both live in the same source unit).
//
// The original is 200 bytes of unoptimised (/Od) MSVC 2008 code:
//
//   * an EH frame (push -1 / push __ehhandler / fs:[0] / security cookie),
//     `this` homed at [ebp-0x10] and the EH state variable at [ebp-4];
//   * the state variable counts the four destructible MEMBERS:
//     4 -> 3 -> 2 -> 1 -> 0 -> -1, with the four member destructors called
//     in reverse declaration order (0x24, 0x20, 0x14, 0x08) and the base
//     sub-object's destructor emitted as the epilogue (offset 0x00);
//   * the destructor body makes six calls:
//        0x622bc0  (a free function)
//        g_011c58e0.operator=(0)
//        this+0x08  -> 0x4a4650
//        this+0x14  -> 0x4ed900
//        this+0x20  ->  operator=(0)
//        this+0x24  ->  operator=(0)
//
// Layout of the reconstructed object (the constructor at 0x0049fcd0 confirms
// it: the handle's constructor 0x633c90 only writes the first dword, and the
// first destructible member is built at +0x08):
//     +0x00  base sub-object - a one-pointer handle, dtor 0x45cec0
//     +0x04  a plain pointer that the constructor never touches
//     +0x08  member with dtor 0x49fe00 and method 0x4a4650
//     +0x14  member with dtor 0x4a1a30 and method 0x4ed900
//     +0x20  handle member (dtor 0x45cec0)
//     +0x24  handle member (dtor 0x45cec0)
// ---------------------------------------------------------------------------

struct FNV_Handle
{
    void* m_pEntryObject;
    FNV_Handle& __thiscall operator=(void* p);
    ~FNV_Handle();
};

struct FNV_Member08
{
    int unk00;
    int unk04;
    int unk08;
    void FUN_004a4650();
    ~FNV_Member08();
};

struct FNV_Member14
{
    int unk00;
    int unk04;
    int unk08;
    void FUN_004ed900();
    ~FNV_Member14();
};

struct FUN_0049fe20_Object : FNV_Handle
{
    void* m_04;
    FNV_Member08 m_08;
    FNV_Member14 m_14;
    FNV_Handle m_20;
    FNV_Handle m_24;
    ~FUN_0049fe20_Object();
};

extern FNV_Handle g_011c58e0;
void __cdecl FUN_00622bc0();

// Calls FUN_00622bc0, sets g_011c58e0 to 0, calls FUN_004a4650 on m_08 and FUN_004ed900 on m_14, then sets m_20 and m_24 to 0.
// @fnv 0x0049fe20
FUN_0049fe20_Object::~FUN_0049fe20_Object()
{
    FUN_00622bc0();
    g_011c58e0 = 0;
    m_08.FUN_004a4650();
    m_14.FUN_004ed900();
    m_20 = 0;
    m_24 = 0;
}

namespace fnv_00486ca0 {
void NiFree(void*);
struct FUN_00486d60
{
    virtual ~FUN_00486d60();
};
struct FUN_00486ca0_Node
{
    FUN_00486ca0_Node* m_pkNext;
    void* m_pResource;
};
struct FUN_00486ca0 : FUN_00486d60
{
    unsigned int m_uiCount;
    FUN_00486ca0_Node** m_ppkBuckets;
    int unk0C;
    bool m_bOwnsData;
    virtual ~FUN_00486ca0();
};
// If m_bOwnsData is set, calls NiFree on each node's m_pResource across all buckets.
// @fnv 0x00486ca0
FUN_00486ca0::~FUN_00486ca0()
{
    if (m_bOwnsData)
    {
        for (unsigned int i = 0; i < m_uiCount; i++)
        {
            FUN_00486ca0_Node* pkNode = m_ppkBuckets[i];
            while (pkNode)
            {
                FUN_00486ca0_Node* pkCurr = pkNode;
                pkNode = pkNode->m_pkNext;
                NiFree(pkCurr->m_pResource);
            }
        }
    }
}
}  // namespace fnv_00486ca0

struct Caller300
{
    const char* __thiscall FUN_0047a300();
};

struct FUN_00481280_class
{
    const char* __thiscall FUN_00481280(int);
};

struct BipedMessageIconView
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
    Caller300 messageIcon;
};

// Returns the message icon string for a biped model form, optionally selecting the variant matching the sex of the given reference's owner.
// @fnv 0x00480f80
const char* __cdecl FUN_00480f80(TESForm* form, TESObjectREFR* ref)
{
    TESBipedModelForm* pOwner = dynamic_cast<TESBipedModelForm*>(form);

    if (pOwner == 0)
        return 0;

    if (ref == 0)
    {
        return reinterpret_cast<BipedMessageIconView*>(pOwner)->messageIcon.FUN_0047a300();
    }

    TESForm* pBipedModelForm = ref->GetOwner();
    int nSex = 0;

    if (pBipedModelForm != 0 && pBipedModelForm->FNV_GetFormType() == 0x2a)
        nSex = reinterpret_cast<TESActorBase*>(pBipedModelForm)->GetSex();

    return reinterpret_cast<FUN_00481280_class*>(pOwner)->FUN_00481280(nSex);
}

void __cdecl operator delete(void*);

struct DeleteWrapper : FUN_00486c60_t
{
    void* FUN_00486c30(unsigned int flags);
};

// Calls the base class destructor and frees the object with operator delete when the low bit of flags is set, then returns this.
// @fnv 0x00486c30
void* DeleteWrapper::FUN_00486c30(unsigned int flags)
{
    FUN_00486c60_t::~FUN_00486c60_t();
    if (flags & 1)
        ::operator delete(this);
    return this;
}
