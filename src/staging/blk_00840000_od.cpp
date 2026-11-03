
// src/staging/blk_00840000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

extern int DAT_0107ea60;

struct FUN_00843190_class
{
    void* vtbl;
    void FUN_00844f00(int, int, int);
    void* FUN_00843190();
};

// Calls FUN_00844f00 with (0x20, 0, 0), sets vtbl to &DAT_0107ea60, and returns this.
// @fnv 0x00843190
void* FUN_00843190_class::FUN_00843190()
{
    FUN_00844f00(0x20, 0, 0);
    vtbl = &DAT_0107ea60;
    return this;
}

struct FUN_00843220_Class
{
    void __thiscall FUN_00844ff0();
    void __thiscall FUN_00843220();
};

// @fnv 0x00843220
void __thiscall FUN_00843220_Class::FUN_00843220()
{
    FUN_00844ff0();
}

struct FUN_00844560_class
{
    int a;
    int b;
    FUN_00844560_class* FUN_00844560(int x);
};

// Sets the first field to 0 and stores x in the second field, then returns this.
// @fnv 0x00844560
FUN_00844560_class* FUN_00844560_class::FUN_00844560(int x)
{
    a = 0;
    b = x;
    return this;
}

struct FUN_008452e0_Class
{
    void FUN_007f6900();
    void* FUN_008452e0();
};

// @fnv 0x008452e0
void* FUN_008452e0_Class::FUN_008452e0()
{
    FUN_007f6900();
    return this;
}

struct FUN_00702220_Class
{
    void __thiscall FUN_00702220();
};

// @fnv 0x008456c0
void __fastcall FUN_008456c0(void* self)
{
    ((FUN_00702220_Class*)((char*)self + 4))->FUN_00702220();
}

void ScanRefsInRange(int, int, int);

// @fnv 0x00847d70
void FUN_00847d70(int a)
{
    ScanRefsInRange(a, 0, 12);
}

namespace fnv_00847d90 {
extern "C" void __cdecl ScanRefsInRange(int, int, int);

// @fnv 0x00847d90
void __cdecl FUN_00847d90(int a)
{
    ScanRefsInRange(a, 0x3e8, 0x3e9);
}
}  // namespace fnv_00847d90

struct FUN_00848cf0_Class
{
    bool IsFlag80Set() const;
};

// @fnv 0x00848cf0
bool FUN_00848cf0_Class::IsFlag80Set() const
{
    return (*(const int*)((const char*)this + 0x244) & 0x80) ? true : false;
}

void __cdecl FUN_0084bfb0(unsigned int, unsigned int);

// @fnv 0x00848d10
void __cdecl FUN_00848d10()
{
    FUN_0084bfb0(0, 0xc);
}

extern "C" void __cdecl FUN_0084c110(int, int);

// @fnv 0x00848d30
void __cdecl FUN_00848d30()
{
    FUN_0084c110(0, 0xc);
}

struct SM7d6
{
    void FUN_0075f6f0(int, int);
};
extern SM7d6* DAT_011daac0;

// @fnv 0x00848e40
void FUN_00848e40(unsigned char arg)
{
    if (DAT_011daac0)
        DAT_011daac0->FUN_0075f6f0(0x20000000, arg);
}

struct FUN_0084b450_Class
{
    unsigned char FUN_0084b450();
};

// @fnv 0x0084b450
unsigned char FUN_0084b450_Class::FUN_0084b450()
{
    return *(unsigned char*)((char*)*(void**)this + 1);
}

struct MapH
{
    bool RemoveAt(unsigned int);
    bool FUN_0084b470(unsigned int index);
};

// @fnv 0x0084b470
bool MapH::FUN_0084b470(unsigned int index)
{
    return RemoveAt(index);
}

struct FUN_00852a10_shell
{
    void RemoveReference(unsigned int, unsigned int);
};

struct FUN_0084b490_class
{
    void FUN_0084b490(unsigned int a, unsigned int b);
};

// Forwards the two arguments to RemoveReference on the object at offset 0x10 of this instance.
// @fnv 0x0084b490
void __thiscall FUN_0084b490_class::FUN_0084b490(unsigned int a, unsigned int b)
{
    ((FUN_00852a10_shell*)((char*)this + 0x10))->RemoveReference(a, b);
}

extern int DAT_0107f474;
struct FUN_0084b4b0_class
{
    void FUN_0084b650(int);
    int vtbl;
    int* InitializeVtbl(int a);
};
// Calls FUN_0084b650 with a, sets vtbl to the address of DAT_0107f474, and returns &vtbl.
// @fnv 0x0084b4b0
int* FUN_0084b4b0_class::InitializeVtbl(int a)
{
    FUN_0084b650(a);
    vtbl = (int)&DAT_0107f474;
    return &vtbl;
}

extern "C" void* DAT_0107f4b4;

struct AX
{
    void* vfn;
    void FUN_006b3eb0(unsigned int, unsigned int);
    AX* FUN_0084b570();
};

// @fnv 0x0084b570
AX* AX::FUN_0084b570()
{
    this->vfn = &DAT_0107f4b4;
    this->FUN_006b3eb0(0, 0);
    return this;
}

namespace fnv_0084b5a0 {
extern int DAT_0107f4b4;

struct GlobalObject_00869f00
{
    int* m_p;
    void Clear(bool b);
    void FUN_0084b5a0();
};

// @fnv 0x0084b5a0
void GlobalObject_00869f00::FUN_0084b5a0()
{
    m_p = &DAT_0107f4b4;
    Clear(true);
}
}  // namespace fnv_0084b5a0

extern "C" void* __cdecl Reallocate(void* p, unsigned int size);

struct FUN_0084b630
{
    void* __thiscall Reallocate(void* p, int n);
};

// @fnv 0x0084b630
void* __thiscall FUN_0084b630::Reallocate(void* p, int aiCount)
{
    return ::Reallocate(p, aiCount << 2);
}

struct FUN_0084ba50_Class
{
    void __thiscall FUN_0084ba50();
    void __thiscall AllocateObject();
};
// @fnv 0x0084ba50
void __thiscall FUN_0084ba50_Class::FUN_0084ba50()
{
    ((FUN_0084ba50_Class*)((char*)this + 0xc))->AllocateObject();
}

struct Unk6b
{
    void FreeMemory(void*);
};

struct FUN_0084ba70_Cls
{
    void FUN_0084ba70(void* arg);
};

// Sets the int at offset 0x10 of arg to 0, then calls FreeMemory on the object at this+0xc with arg.
// @fnv 0x0084ba70
void FUN_0084ba70_Cls::FUN_0084ba70(void* arg)
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(arg) + 0x10) = 0;
    reinterpret_cast<Unk6b*>(reinterpret_cast<char*>(this) + 0xc)->FreeMemory(arg);
}

void* __cdecl operator new(unsigned int size);

struct FUN_0084bb30_class
{
    void* __thiscall AllocateObject();
};

// @fnv 0x0084bb30
void* __thiscall FUN_0084bb30_class::AllocateObject()
{
    void* result = operator new(0x18);
    return result;
}

extern int DAT_0107f714;
struct FUN_0084d240_class
{
    void* m_p;
    void __thiscall InitBuffer(int);
    void* __thiscall FUN_0084d240(int);
};
// Calls InitBuffer with a, sets m_p to &DAT_0107f714, and returns this.
// @fnv 0x0084d240
void* __thiscall FUN_0084d240_class::FUN_0084d240(int a)
{
    InitBuffer(a);
    m_p = &DAT_0107f714;
    return this;
}

// @fnv 0x0084da90
int __fastcall GetCombinedValue(int this_)
{
    return *(int*)(this_ + 4) + *(int*)(this_ + 0xc);
}

struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};

struct WeaponQueue
{
    void __thiscall QueueWeapon(unsigned int);
};

// @fnv 0x0084dd70
void __thiscall WeaponQueue::QueueWeapon(unsigned int param_2)
{
    TaskQueueInterface::CopyStringToBuffer((char*)this + 0x3c, 0x40, (const char*)param_2);
}

struct FUN_0084e320_Class
{
    BSSimpleArray<unsigned int, 2> m_Array;
    unsigned int GetArrayElement(int index);
};

// @fnv 0x0084e320
unsigned int FUN_0084e320_Class::GetArrayElement(int index)
{
    return m_Array.GetAt(index);
}

struct FUN_0084e3a0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int FUN_0084e3a0();
};

// @fnv 0x0084e3a0
int FUN_0084e3a0_Class::FUN_0084e3a0()
{
    return m_iThirdValue;
}

struct BGSSaveLoadFileEntry
{
    void ReadTypedData();
    void* FUN_00851ef0();
};

// @fnv 0x00851ef0
void* BGSSaveLoadFileEntry::FUN_00851ef0()
{
    ReadTypedData();
    return *(void**)((char*)this + 0x20);
}

namespace fnv_00851f10 {
struct BGSSaveLoadFileEntry
{
    void ReadTypedData();
    void* FUN_00851f10();
};

// @fnv 0x00851f10
void* BGSSaveLoadFileEntry::FUN_00851f10()
{
    ReadTypedData();
    return *(void**)((char*)this + 0x24);
}
}  // namespace fnv_00851f10

namespace fnv_00851f30 {
struct BGSSaveLoadFileEntry
{
    void ReadTypedData();
    void* FUN_00851f30();
};

// @fnv 0x00851f30
void* BGSSaveLoadFileEntry::FUN_00851f30()
{
    ReadTypedData();
    return *(void**)((char*)this + 0x28);
}
}  // namespace fnv_00851f30

extern "C" void* __cdecl FUN_00af2e50(void);

struct FUN_00851f50_class
{
    void* __thiscall FUN_00851f50();
};

// @fnv 0x00851f50
void* __thiscall FUN_00851f50_class::FUN_00851f50()
{
    return FUN_00af2e50();
}

namespace fnv_00851f60 {
struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char* dst, unsigned int size, const char* src);
};

struct FUN_00851f60_Class
{
    void __thiscall FUN_00851f60(unsigned int a);
};

// @fnv 0x00851f60
void __thiscall FUN_00851f60_Class::FUN_00851f60(unsigned int apSource)
{
    TaskQueueInterface::CopyStringToBuffer((char*)this + 0x164, 0x100, (const char*)apSource);
}
}  // namespace fnv_00851f60

namespace fnv_00851f90 {
struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};

struct FUN_00851f90_class
{
    void __thiscall FUN_00851f90(unsigned int a);
};

// @fnv 0x00851f90
void __thiscall FUN_00851f90_class::FUN_00851f90(unsigned int apSource)
{
    TaskQueueInterface::CopyStringToBuffer((char*)this + 0x265, 0x80, (const char*)apSource);
}
}  // namespace fnv_00851f90

namespace fnv_00852030 {
struct TaskQueueInterface
{
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};

struct FUN_00852030_Class
{
    void FUN_00852030(int a);
};

// @fnv 0x00852030
void FUN_00852030_Class::FUN_00852030(int apSource)
{
    TaskQueueInterface::CopyStringToBuffer((char*)this + 0x8f4, 0x100, (const char*)apSource);
}
}  // namespace fnv_00852030

struct FUN_00852060_Class
{
    void SetValue(int value);
};

// @fnv 0x00852060
void FUN_00852060_Class::SetValue(int value)
{
    *(int*)((char*)this + 0x9f4) = value;
}

extern "C" void __cdecl FUN_00af3020();

// @fnv 0x008526c0
void __fastcall FUN_008526c0(void* thisPtr)
{
    FUN_00af3020();
}

extern int DAT_01080028;

struct FUN_00852fa0_class
{
    int __thiscall FUN_008530c0(int arg);
    int __thiscall FUN_00852fa0(int arg);
};

// Calls FUN_008530c0 with arg, stores the address of DAT_01080028 into this, and returns this.
// @fnv 0x00852fa0
int __thiscall FUN_00852fa0_class::FUN_00852fa0(int arg)
{
    FUN_008530c0(arg);
    *(int*)this = (int)&DAT_01080028;
    return (int)this;
}

extern int DAT_01080048;

struct FUN_00852fd0_cls
{
    void* m_p;
    void* __thiscall InitializeBuffer(void* arg);
    void* __thiscall FUN_00852fd0(void* arg);
};

// Calls InitializeBuffer with arg, stores the address of DAT_01080048 in m_p, and returns this.
// @fnv 0x00852fd0
void* __thiscall FUN_00852fd0_cls::FUN_00852fd0(void* arg)
{
    this->InitializeBuffer(arg);
    m_p = &DAT_01080048;
    return this;
}

extern int DAT_01080068;
struct FUN_00853370_class
{
    void __thiscall FUN_00853370(int arg);
};

struct FUN_00853000_class
{
    int* p;
    FUN_00853000_class* __thiscall FUN_00853000(int arg);
};

// Calls FUN_00853370 with arg, sets p to point at DAT_01080068, and returns this.
// @fnv 0x00853000
FUN_00853000_class* __thiscall FUN_00853000_class::FUN_00853000(int arg)
{
    ((FUN_00853370_class*)this)->FUN_00853370(arg);
    p = &DAT_01080068;
    return this;
}

namespace fnv_00853240 {
struct Unk6b
{
    void FreeMemory(void*);
};
struct FUN_00853240_Class
{
    int a;
    int b;
    Unk6b c;
    void FUN_00853240(void* p);
};
// Clears the third int of p, then calls FreeMemory on this+0xc with p.
// @fnv 0x00853240
void FUN_00853240_Class::FUN_00853240(void* pTarget)
{
    ((int*)pTarget)[2] = 0;
    ((Unk6b*)((char*)this + 0xc))->FreeMemory(pTarget);
}
}  // namespace fnv_00853240

struct CF_0081c630
{
    CF_0081c630();
};
struct FUN_00854af0
{
    void* pad;
    CF_0081c630 m;
    FUN_00854af0();
};
// @fnv 0x00854af0
FUN_00854af0::FUN_00854af0()
{}

extern int DAT_01080434;
struct FUN_00854c80_class
{
    int m_vf_00;
    void __thiscall FUN_00854ce0(int a);
    int* __thiscall FUN_00854c80(int a);
};
// Calls FUN_00854ce0 with a, sets m_vf_00 to the address of DAT_01080434, and returns this.
// @fnv 0x00854c80
int* FUN_00854c80_class::FUN_00854c80(int a)
{
    FUN_00854ce0(a);
    m_vf_00 = (int)&DAT_01080434;
    return (int*)this;
}

extern "C" void __cdecl Deallocate(void*);

struct FUN_00854e10
{
    int a;
    void* b;
    void FUN_00854e10_();
};

// @fnv 0x00854e10
void FUN_00854e10::FUN_00854e10_()
{
    if (b)
        Deallocate(b);
}

struct FUN_00854e40_Class
{
    int m_00;
    int m_04;
    void FUN_00854e40(int a1);
};

// If m_04 is zero, ORs a1 into m_00; otherwise does nothing.
// @fnv 0x00854e40
void FUN_00854e40_Class::FUN_00854e40(int a1)
{
    if (m_04 == 0)
        m_00 |= a1;
}

struct FUN_00854e70_class
{
    unsigned int a;
    unsigned int b;
    void FUN_00854e70(unsigned int auMode);
};

// If b is zero, clears the bits of auMode in a.
// @fnv 0x00854e70
void FUN_00854e70_class::FUN_00854e70(unsigned int auMode)
{
    if (b == 0)
        a &= ~auMode;
}

extern void* DAT_010804a8;

struct FUN_00854ea0_class
{
    void* m;
    void __thiscall FUN_00863360(int);
    void* FUN_00854ea0();
};

// Calls FUN_00863360 with 0x13af, sets m to point at DAT_010804a8, and returns this.
// @fnv 0x00854ea0
void* FUN_00854ea0_class::FUN_00854ea0()
{
    FUN_00863360(0x13af);
    m = &DAT_010804a8;
    return this;
}

struct FUN_00863d60_obj
{
    void FUN_00863d60();
};

struct FUN_00857350_obj : FUN_00863d60_obj
{
    void FUN_00857350();
};

// @fnv 0x00857350
void FUN_00857350_obj::FUN_00857350()
{
    FUN_00863d60();
}

struct NiBinaryStream
{
    unsigned int Read(void* buffer, unsigned int size);
};

struct FUN_00857ba0_shell
{
    unsigned int ReadFromStream(NiBinaryStream* stream, void* buffer, unsigned int size);
};

// @fnv 0x00857ba0
unsigned int __thiscall FUN_00857ba0_shell::ReadFromStream(NiBinaryStream* stream, void* buffer, unsigned int size)
{
    unsigned int result = stream->Read(buffer, size);
    return result;
}

struct TESSound
{
    unsigned int Deallocate();
};
struct DummyPointerMap;
struct Holder
{
    void FUN_0085efc0(DummyPointerMap*, unsigned int, unsigned short);
    void FUN_0085f2b0(TESSound* sound, unsigned short flag);
};
// Calls FUN_0085efc0 with the map at this+0x5c, the result of sound->Deallocate(), and flag.
// @fnv 0x0085f2b0
void Holder::FUN_0085f2b0(TESSound* sound, unsigned short flag)
{
    FUN_0085efc0((DummyPointerMap*)*(int*)((char*)this + 0x5c), sound->Deallocate(), flag);
}

namespace fnv_0085f420 {
struct TESSound
{
    unsigned int Deallocate();
};
struct DummyPointerMap
{
};
struct Holder
{
    void FUN_0085efc0(DummyPointerMap*, unsigned int, unsigned short);
    DummyPointerMap* m_pMapObject;
};
struct FUN_0085f420Class : Holder
{
    void FUN_0085f420(TESSound* SoundAssetTmp, unsigned short wParam);
};
// Calls FUN_0085efc0 with the pointer at this+0x60, the result of TESSound::Deallocate, and wParam.
// @fnv 0x0085f420
void FUN_0085f420Class::FUN_0085f420(TESSound* SoundAssetTmp, unsigned short wParam)
{
    FUN_0085efc0(*(DummyPointerMap**)((char*)this + 0x60), SoundAssetTmp->Deallocate(), wParam);
}
}  // namespace fnv_0085f420

struct FUN_0085feb0_class
{
    char GetByteAt158();
};

// @fnv 0x0085feb0
char FUN_0085feb0_class::GetByteAt158()
{
    return *(char*)((char*)this + 0x158);
}

extern "C" void* __cdecl _NiFreeAlias(void*);

struct FUN_00844660_Class
{
    int m_vtbl;
    int m_auiShapeKeys;
    int m_data;
    void NiTPointerMap_RemoveAll();
    void FUN_00844660();
};

// Sets the vtable pointer, clears the pointer map, and frees m_data.
// @fnv 0x00844660
void FUN_00844660_Class::FUN_00844660()
{
    m_vtbl = (int)0x0107ec88;
    NiTPointerMap_RemoveAll();
    _NiFreeAlias((void*)m_data);
}

namespace fnv_00844840 {
extern "C" void __cdecl _NiFreeAlias(void*);
extern int DAT_0107eca8;

struct FUN_00844840_
{
    void* vtbl;
    void* p;
    void* q;
    void RemoveAll();
    void FUN_00844840();
};

// Sets the vtable to DAT_0107eca8, calls RemoveAll, then frees q via _NiFreeAlias.
// @fnv 0x00844840
void FUN_00844840_::FUN_00844840()
{
    vtbl = &DAT_0107eca8;
    RemoveAll();
    _NiFreeAlias(q);
}
}  // namespace fnv_00844840

namespace fnv_00844940 {
extern "C" void _NiFreeAlias(void*);
extern int DAT_0107ecc8;

struct NiTPointerMap_00844940
{
    void* vtbl;
    int a;
    void* b;
    void RemoveAll();
    void FUN_00844940();
};

// @fnv 0x00844940
void NiTPointerMap_00844940::FUN_00844940()
{
    *reinterpret_cast<void**>(this) = (void*)&DAT_0107ecc8;
    RemoveAll();
    _NiFreeAlias(b);
}
}  // namespace fnv_00844940

extern "C" void* __cdecl NiFreeAlias(void*);
extern int DAT_0107ece8;

struct FUN_00844a40
{
    void* vtbl;
    int a;
    int b;
    void RemoveAll();
};

// @fnv 0x00844a40
void FUN_00844a40::RemoveAll()
{
    *reinterpret_cast<int**>(this) = &DAT_0107ece8;
    reinterpret_cast<NiTPointerMap<int, int>*>(this)->RemoveAll();
    NiFreeAlias(reinterpret_cast<void**>(this)[2]);
}

namespace fnv_0084b720 {
extern int DAT_0107f4c8;
void __cdecl _NiFreeAlias(void*);
struct FUN_0084b720
{
    void* vtbl;
    int a;
    void* b;
    void __thiscall Init();
};
// Sets the vtable pointer, clears the pointer map, and frees the b pointer via _NiFreeAlias.
// @fnv 0x0084b720
void __thiscall FUN_0084b720::Init()
{
    *(void**)(void*)this = (void*)&DAT_0107f4c8;
    ((NiTPointerMap<int, int>*)this)->RemoveAll();
    _NiFreeAlias(b);
}
}  // namespace fnv_0084b720

namespace fnv_0084ba20 {
extern "C" void __cdecl _NiFreeAlias(void*);

struct FUN_0084ba20
{
    void* m_vft;
    void* m_auiShapeKeys;
    void* m_data;
    void NiTPointerMapRemoveAll();
    void Init();
};

// Sets the vtable pointer, clears the pointer map, and frees m_data.
// @fnv 0x0084ba20
void FUN_0084ba20::Init()
{
    m_vft = (void*)0x0107f4e8;
    NiTPointerMapRemoveAll();
    _NiFreeAlias(m_data);
}
}  // namespace fnv_0084ba20

extern "C" void __cdecl NiFree(void*);
extern int DAT_01080088;

struct FUN_00853210_cls : NiTPointerMap<int, int>
{
    void FUN_00853210();
};

// Sets the vtable pointer, removes all entries from the map, and frees the pointer stored at offset 8.
// @fnv 0x00853210
void __thiscall FUN_00853210_cls::FUN_00853210()
{
    *(void**)(void*)this = (void*)&DAT_01080088;
    ((NiTPointerMap<int, int>*)this)->RemoveAll();
    NiFree(*(void**)((char*)this + 8));
}

namespace fnv_00853340 {
extern "C" void __cdecl _NiFreeAlias(void*);
extern int DAT_010800a8;

struct FUN_00853340 : NiTPointerMap<int, int>
{
    void Init();
};

// Sets the vtable pointer, clears all entries with RemoveAll, then frees the pointer stored at offset 8 via _NiFreeAlias.
// @fnv 0x00853340
void FUN_00853340::Init()
{
    *(void**)this = (void*)&DAT_010800a8;
    RemoveAll();
    _NiFreeAlias(*(void**)((char*)this + 8));
}
}  // namespace fnv_00853340

extern "C" void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void* dst, int c, unsigned int n);
extern int DAT_0107ec88;

struct FUN_00844590
{
    int* m_pVTable;
    unsigned int m_uiCount;
    void* m_pData;
    unsigned int m_uiSize;
    FUN_00844590(unsigned int ItemUpdateArray);
    ~FUN_00844590();
};

// Sets the vtable, stores the element count, allocates count*4 bytes with NiMalloc and zero-fills them.
// @fnv 0x00844590
FUN_00844590::FUN_00844590(unsigned int ItemUpdateArray)
{
    m_pVTable = &DAT_0107ec88;
    m_uiCount = ItemUpdateArray;
    m_uiSize = 0;
    unsigned int size = m_uiCount * 4;
    m_pData = NiMalloc(size);
    memset(m_pData, 0, m_uiCount * 4);
}

extern int DAT_0107eca8;
void* __cdecl NiMalloc(unsigned int size);
void* __cdecl memset(void* dest, int value, unsigned int count);
struct FUN_00844690_class
{
    void* vtbl;
    int count;
    void* data;
    int pad;
    FUN_00844690_class* __thiscall FUN_00844690(int c);
};
// Sets the vtable, stores the element count, allocates count*4 bytes, zeroes them, and returns this.
// @fnv 0x00844690
FUN_00844690_class* __thiscall FUN_00844690_class::FUN_00844690(int aiCount)
{
    vtbl = &DAT_0107eca8;
    count = aiCount;
    pad = 0;
    unsigned int uiSize = count * 4;
    data = NiMalloc(uiSize);
    memset(data, 0, count * 4);
    return this;
}

namespace fnv_00844870 {
extern "C" void* __cdecl NiMalloc(unsigned int);
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern int DAT_0107ecc8;

struct FUN_00844870_Cls
{
    int* vtbl;
    int count;
    void* data;
    int pad;
    FUN_00844870_Cls* __thiscall FUN_00844870(int count);
};

// Sets the vtable, stores count, allocates count*4 bytes zeroed into data, and returns this.
// @fnv 0x00844870
FUN_00844870_Cls* __thiscall FUN_00844870_Cls::FUN_00844870(int count)
{
    vtbl = &DAT_0107ecc8;
    this->count = count;
    pad = 0;
    unsigned int size = this->count * 4;
    data = NiMalloc(size);
    memset(data, 0, this->count * 4);
    return this;
}
}  // namespace fnv_00844870

void* __cdecl _NiMalloc(unsigned int size);
void* __cdecl memset(void* dest, int c, unsigned int count);

struct FUN_00844970_class
{
    int* vtbl;
    int a;
    int* p;
    int b;
    FUN_00844970_class(int size);
};

// Constructor: sets the vtable, stores size, allocates a zeroed array of size ints and stores it in p.
// @fnv 0x00844970
FUN_00844970_class::FUN_00844970_class(int size)
{
    vtbl = &DAT_0107ece8;
    a = size;
    b = 0;
    int n = a * 4;
    p = (int*)_NiMalloc(n);
    memset(p, 0, a * 4);
}

extern "C" void __cdecl Deallocate(void*);
struct Unk008444d0
{
    void __thiscall FUN_008444d0();
};
struct FUN_008450b0_class
{
    void* __thiscall FUN_008450b0(unsigned int flags);
};
// @fnv 0x008450b0
void* __thiscall FUN_008450b0_class::FUN_008450b0(unsigned int flags)
{
    ((Unk008444d0*)this)->FUN_008444d0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_00845110_class
{
    void* __thiscall FUN_00844840();
    void* __thiscall FUN_00845110(unsigned int flags);
};
// @fnv 0x00845110
void* __thiscall FUN_00845110_class::FUN_00845110(unsigned int flags)
{
    FUN_00844840();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void Deallocate(void*);
struct FUN_00845140_class
{
    void __thiscall FUN_00844940();
    void* __thiscall FUN_00845140(unsigned int flags);
};
// Calls FUN_00844940, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x00845140
void* __thiscall FUN_00845140_class::FUN_00845140(unsigned int flags)
{
    FUN_00844940();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_00845170_class
{
    void* __thiscall FUN_00845170(unsigned int flags);
};
// Removes all entries from this object, optionally deallocates it when flags has bit 0 set, and returns this.
// @fnv 0x00845170
void* __thiscall FUN_00845170_class::FUN_00845170(unsigned int flags)
{
    reinterpret_cast<FUN_00844a40*>(this)->RemoveAll();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);

struct S_00844e80
{
    void FUN_00844e80();
    void* FUN_008451d0(unsigned int flags);
};

// Calls FUN_00844e80, then frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x008451d0
void* S_00844e80::FUN_008451d0(unsigned int flags)
{
    FUN_00844e80();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);

struct FUN_00844fa0_class
{
    void __thiscall InitGlobalObject();
};

struct FUN_00845200_class
{
    void* __thiscall FUN_00845200(unsigned int flags);
};

// Calls InitGlobalObject on this, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00845200
void* __thiscall FUN_00845200_class::FUN_00845200(unsigned int flags)
{
    ((FUN_00844fa0_class*)this)->InitGlobalObject();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);

struct FUN_00845230_Class
{
    void* FUN_00845230(unsigned int flags);
};

// Calls FUN_00844ff0 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00845230
void* FUN_00845230_Class::FUN_00845230(unsigned int flags)
{
    ((FUN_00843220_Class*)this)->FUN_00844ff0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct BGSSaveLoadReferencesMap
{
    BGSSaveLoadReferencesMap();
    void* FUN_00852ae0();
    void* FUN_008473f0(unsigned int flags);
};

// Calls FUN_00852ae0, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x008473f0
void* BGSSaveLoadReferencesMap::FUN_008473f0(unsigned int flags)
{
    FUN_00852ae0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_00865220_class
{
    void __thiscall FUN_00865220();
    void* __thiscall FUN_00847420(unsigned int flags);
};
// @fnv 0x00847420
void* FUN_00865220_class::FUN_00847420(unsigned int flags)
{
    FUN_00865220();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00849240_class
{
    void SetFlag4(bool b);
};

// @fnv 0x00849240
void FUN_00849240_class::SetFlag4(bool abSet)
{
    if (abSet)
        *(unsigned int*)((char*)this + 0x28) |= 4;
    else
        *(unsigned int*)((char*)this + 0x28) &= ~4;
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_0084b510_class
{
    void __thiscall FUN_0084b6c0();
    void* __thiscall FUN_0084b510(unsigned int flags);
};
// @fnv 0x0084b510
void* __thiscall FUN_0084b510_class::FUN_0084b510(unsigned int flags)
{
    FUN_0084b6c0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void* dest, int c, unsigned int count);
extern int DAT_0107f4c8;
struct FUN_0084b650_t
{
    int* vtbl;
    int count;
    void* data;
    int unused;
    void* __thiscall FUN_0084b650(int n);
};
// Sets the vtable, stores the element count, allocates count*4 bytes, zeroes them, and returns this.
// @fnv 0x0084b650
void* __thiscall FUN_0084b650_t::FUN_0084b650(int aiCount)
{
    unsigned int size;
    vtbl = (int*)&DAT_0107f4c8;
    count = aiCount;
    unused = 0;
    size = count << 2;
    data = NiMalloc(size);
    memset(data, 0, count << 2);
    return this;
}

void* __cdecl NiMalloc(unsigned int size);
void* __cdecl memset(void* dst, int value, unsigned int count);
extern int DAT_0107f4e8;
struct FUN_0084b750
{
    void* vtbl;
    int count;
    void* data;
    int size;
    FUN_0084b750(int count);
};
// Sets the vtable, stores count, allocates count*4 bytes with NiMalloc and zeroes them with memset.
// @fnv 0x0084b750
FUN_0084b750::FUN_0084b750(int count)
{
    vtbl = (void*)&DAT_0107f4e8;
    this->count = count;
    size = 0;
    unsigned int n = this->count * 4;
    data = NiMalloc(n);
    memset(data, 0, this->count * 4);
}

struct FUN_0084baa0_Class
{
    void* __thiscall FUN_0084baa0(unsigned int flags);
    void __thiscall FUN_0084b5a0();
};
void __cdecl Deallocate(void*);
// @fnv 0x0084baa0
void* __thiscall FUN_0084baa0_Class::FUN_0084baa0(unsigned int flags)
{
    FUN_0084b5a0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void Deallocate(void*);

struct FUN_0084bad0_class
{
    void __thiscall FUN_0084b720();
    void* __thiscall FUN_0084bad0(unsigned int flags);
};

// @fnv 0x0084bad0
void* FUN_0084bad0_class::FUN_0084bad0(unsigned int flags)
{
    FUN_0084b720();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);

struct FUN_0084d270_class
{
    void __thiscall FUN_0084d3f0();
    void* __thiscall FUN_0084d270(unsigned int flags);
};

// Calls FUN_0084d3f0, frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0084d270
void* __thiscall FUN_0084d270_class::FUN_0084d270(unsigned int flags)
{
    FUN_0084d3f0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

namespace fnv_0084d2a0 {
extern "C" void* __cdecl NiMalloc(unsigned int);
extern "C" void* __cdecl memset(void* dst, int c, unsigned int n);
extern int DAT_0107f734;
struct FUN_0084d2a0_t
{
    int* vtbl;
    unsigned int count;
    void* data;
    unsigned int used;
    FUN_0084d2a0_t* __thiscall InitBuffer(unsigned int n);
};
// Sets the vtable, stores the element count, allocates count*4 bytes, zeroes them, and returns this.
// @fnv 0x0084d2a0
FUN_0084d2a0_t* __thiscall FUN_0084d2a0_t::InitBuffer(unsigned int n)
{
    unsigned int size;
    vtbl = &DAT_0107f734;
    count = n;
    used = 0;
    size = count * 4;
    data = NiMalloc(size);
    memset(data, 0, count * 4);
    return this;
}
}  // namespace fnv_0084d2a0

extern "C" void __cdecl Deallocate(void*);
struct FUN_0084d480_Class
{
    void __thiscall FUN_0084d450();
    void* __thiscall FUN_0084d480(unsigned int flags);
};
// Calls FUN_0084d450, frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0084d480
void* __thiscall FUN_0084d480_Class::FUN_0084d480(unsigned int flags)
{
    FUN_0084d450();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00846d20_shell
{
    unsigned int FUN_00846d20(unsigned int a);
};
struct BGSSaveLoadGame
{
    unsigned int FUN_0084e3a0();
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;

struct FUN_0084e340_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void FUN_0084e340(const char* p);
};

// @fnv 0x0084e340
void FUN_0084e340_Class::FUN_0084e340(const char* p)
{
    m_iWordAt04 = (short)p[2];
    m_8 = (short)p[3];
    m_iThirdValue = *(int*)(p + 4);
    m_iWordAt00 = ((FUN_00846d20_shell*)g_BGSSaveLoadGame->FUN_0084e3a0())->FUN_00846d20(*(unsigned short*)p);
}

struct FUN_0084e420_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void __thiscall ResetFromValue(int* arg);
};
// @fnv 0x0084e420
void __thiscall FUN_0084e420_class::ResetFromValue(int* piValue)
{
    m_iWordAt04 = 0;
    m_8 = 0;
    m_iThirdValue = *piValue;
    m_iWordAt00 = 0;
}

void __fastcall FUN_008462c0(char*);
extern void __cdecl Deallocate(void*);
struct FUN_00850330_class
{
    char* __thiscall FUN_00850330(unsigned int flags);
};
// Calls FUN_008462c0 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00850330
char* __thiscall FUN_00850330_class::FUN_00850330(unsigned int flags)
{
    FUN_008462c0(reinterpret_cast<char*>(this));
    if (flags & 1)
        Deallocate(this);
    return reinterpret_cast<char*>(this);
}

extern "C" void __cdecl Deallocate(void*);
void __fastcall FUN_00846690(void** self);
struct FUN_008515f0_class
{
    void* FUN_008515f0(unsigned int flags);
};
// Calls FUN_00846690 on this, frees this when bit 0 of flags is set, and returns this.
// @fnv 0x008515f0
void* FUN_008515f0_class::FUN_008515f0(unsigned int flags)
{
    FUN_00846690((void**)this);
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00851ff0_class
{
    void __thiscall FUN_00851ff0(int a, int b, int c);
};

// Stores the three int arguments at offsets 0x7e8, 0x7ec and 0x7f0 of this object.
// @fnv 0x00851ff0
void __thiscall FUN_00851ff0_class::FUN_00851ff0(int a, int b, int c)
{
    *(int*)((char*)this + 0x7e8) = a;
    *(int*)((char*)this + 0x7ec) = b;
    *(int*)((char*)this + 0x7f0) = c;
}

struct FUN_00852700_Class
{
    int vtbl;
    int flags;
    bool IsFlagged();
};
// Returns true if the flags field has bit 0x20 or bit 0x80 set.
// @fnv 0x00852700
bool FUN_00852700_Class::IsFlagged()
{
    return (flags & 0x20) || (flags & 0x80);
}

struct FUN_008531b0_class
{
    void __thiscall FUN_008531b0();
    void* __thiscall FUN_00853030(unsigned int flags);
};

// Calls FUN_008531b0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00853030
void* __thiscall FUN_008531b0_class::FUN_00853030(unsigned int flags)
{
    FUN_008531b0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_008532e0_class
{
    void __thiscall FUN_008532e0();
    void* __thiscall FUN_00853060(unsigned int flags);
};
// @fnv 0x00853060
void* __thiscall FUN_008532e0_class::FUN_00853060(unsigned int flags)
{
    FUN_008532e0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);
void FUN_008533e0();
struct FUN_00853090_class
{
    void __thiscall FUN_008533e0();
    void* __thiscall FUN_00853090(unsigned int flags);
};
// Calls FUN_008533e0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00853090
void* FUN_00853090_class::FUN_00853090(unsigned int flags)
{
    FUN_008533e0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void* __cdecl _NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
struct FUN_008530c0_obj
{
    int* vtbl;
    unsigned int size;
    void* data;
    unsigned int count;
    FUN_008530c0_obj* __thiscall FUN_008530c0(unsigned int n);
};
// @fnv 0x008530c0
FUN_008530c0_obj* __thiscall FUN_008530c0_obj::FUN_008530c0(unsigned int auiSize)
{
    unsigned int tmp;
    vtbl = &DAT_01080088;
    size = auiSize;
    count = 0;
    tmp = size * 4;
    data = _NiMalloc(tmp);
    memset(data, 0, size * 4);
    return this;
}

struct FUN_00853440
{
    int* vtbl;
    virtual ~FUN_00853440();
};
struct FUN_008533e0 : FUN_00853440
{
    ~FUN_008533e0();
};
// Destructor that clears all entries from the underlying NiTPointerMap by calling RemoveAll.
// @fnv 0x008533e0
FUN_008533e0::~FUN_008533e0()
{
    ((NiTPointerMap<int, int>*)this)->RemoveAll();
}

void __cdecl Deallocate(void*);
struct FUN_00853340_shell
{
    void __thiscall FUN_00853340();
};
struct FUN_008534a0_shell
{
    void* __thiscall FUN_008534a0(unsigned int flags);
};
// Calls FUN_00853340 on this, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x008534a0
void* __thiscall FUN_008534a0_shell::FUN_008534a0(unsigned int flags)
{
    ((FUN_00853340_shell*)this)->FUN_00853340();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_00853440_class
{
    void __thiscall FUN_00853440();
    void* __thiscall FUN_008534d0(unsigned int flags);
};
// Calls FUN_00853440, frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x008534d0
void* FUN_00853440_class::FUN_008534d0(unsigned int flags)
{
    FUN_00853440();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct BSFile
{
    void __thiscall FUN_00473180(const char* p, unsigned int n);
};
int __cdecl BSStringLength(const char* p);
struct FUN_00854b80_class
{
    void __thiscall FUN_00854b80(const char* p);
};
// @fnv 0x00854b80
void __thiscall FUN_00854b80_class::FUN_00854b80(const char* pcString)
{
    if (*(int*)((char*)this + 0x18))
        ((BSFile*)*(int*)((char*)this + 0x18))->FUN_00473180(pcString, BSStringLength(pcString));
}

extern "C" void __cdecl Deallocate(void*);
void __fastcall FUN_00854d50(void* self);
struct FUN_00854cb0_class
{
    void* __thiscall FUN_00854cb0(unsigned int flags);
};
// Calls FUN_00854d50 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x00854cb0
void* __thiscall FUN_00854cb0_class::FUN_00854cb0(unsigned int flags)
{
    FUN_00854d50(this);
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void* __cdecl NiMalloc(unsigned int size);
void* __cdecl memset(void* dest, int value, unsigned int size);
extern int DAT_01080454;
struct FUN_00854ce0_class
{
    void* vtbl;
    int count;
    void* data;
    void* pad;
    void* __thiscall FUN_00854ce0(int a);
};
// Sets the vtable, stores the element count, allocates count*4 bytes, zeroes them, and returns this.
// @fnv 0x00854ce0
void* __thiscall FUN_00854ce0_class::FUN_00854ce0(int aiCount)
{
    unsigned int size;
    vtbl = &DAT_01080454;
    count = aiCount;
    pad = 0;
    size = count * 4;
    data = NiMalloc(size);
    memset(data, 0, count * 4);
    return this;
}

struct FUN_00854de0_class
{
    void* __thiscall ClearAndFree();
    void* __thiscall FUN_00854de0(unsigned int flags);
};
// Calls ClearAndFree, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00854de0
void* __thiscall FUN_00854de0_class::FUN_00854de0(unsigned int flags)
{
    ClearAndFree();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_00855730_Class
{
    void __thiscall DestroyMapAndLists();
    void* __thiscall FUN_00857250(unsigned int flags);
};
// @fnv 0x00857250
void* __thiscall FUN_00855730_Class::FUN_00857250(unsigned int flags)
{
    DestroyMapAndLists();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct TESSaveLoadGame
{
    void ReadTypedData(void*, unsigned int);
};
struct SetAtHelper
{
    void SetAt(unsigned int, unsigned int);
};
struct FUN_0085ef80_shell
{
    TESSaveLoadGame* AllocateWithPrefix(unsigned short);
};
struct FUN_0085efc0_Class
{
    void FUN_0085efc0(DummyPointerMap* a, unsigned int b, unsigned short c);
};
// @fnv 0x0085efc0
void __thiscall FUN_0085efc0_Class::FUN_0085efc0(DummyPointerMap* pMap, unsigned int uiKey, unsigned short usIndex)
{
    TESSaveLoadGame* q = ((FUN_0085ef80_shell*)this)->AllocateWithPrefix(usIndex);
    TESSaveLoadGame* p = q + 2;
    ((TESSaveLoadGame*)this)->ReadTypedData((void*)p, usIndex);
    ((SetAtHelper*)pMap)->SetAt(uiKey, (unsigned int)q);
}

struct LH
{
    bool IsInList(int*&);
};
struct G2
{
    void AddHead(int**);
};
struct FUN_0085f710_class
{
    void* pad[0x68 / 4];
    LH list;
    void __thiscall AddActorToList(int* actor);
};
// If actor is not already in list, adds it to the head of the list.
// @fnv 0x0085f710
void __thiscall FUN_0085f710_class::AddActorToList(int* actor)
{
    if (!list.IsInList(actor))
        ((G2*)&list)->AddHead(&actor);
}

unsigned int __fastcall FUN_00853500(void*);
struct Vec3
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
};
struct FUN_0084e460_t
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    Vec3 f;
    Vec3 g;
    unsigned char flag;
    void FUN_0084e460(unsigned int arg);
};
// Reads a value from arg via FUN_00853500, zeroes b-e, copies two Vec3s from arg+3 and arg+15, and clears flag.
// @fnv 0x0084e460
void FUN_0084e460_t::FUN_0084e460(unsigned int auiData)
{
    a = FUN_00853500((void*)auiData);
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = *(Vec3*)(auiData + 3);
    g = *(Vec3*)(auiData + 15);
    flag = 0;
}

unsigned int __fastcall FUN_00853500(void* p);

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct FUN_0084e580_t
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    int d;
    int e;
    NiPoint3 f;
    NiPoint3 g;
    unsigned char h;
};

struct FUN_0084e580_class
{
    void __thiscall FUN_0084e580(void* p);
};

// Reads fields from p into this: two values via FUN_00853500, two shorts, two NiPoint3s, and zeroes b and h.
// @fnv 0x0084e580
void __thiscall FUN_0084e580_class::FUN_0084e580(void* p)
{
    ((FUN_0084e580_t*)this)->a = FUN_00853500(p);
    ((FUN_0084e580_t*)this)->b = 0;
    ((FUN_0084e580_t*)this)->c = FUN_00853500((char*)p + 0x1b);
    ((FUN_0084e580_t*)this)->d = *(short*)((char*)p + 0x1e);
    ((FUN_0084e580_t*)this)->e = *(short*)((char*)p + 0x20);
    ((FUN_0084e580_t*)this)->f = *(NiPoint3*)((char*)p + 3);
    ((FUN_0084e580_t*)this)->g = *(NiPoint3*)((char*)p + 0xf);
    ((FUN_0084e580_t*)this)->h = 0;
}

struct BSS
{
    ~BSS();
};
struct FUN_0084fe50_class
{
    void FUN_00851540();
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
    BSS m_30;
    ~FUN_0084fe50_class();
};
void __cdecl Deallocate(void*);
// @fnv 0x0084fe50
FUN_0084fe50_class::~FUN_0084fe50_class()
{
    FUN_00851540();
    void* oldData = (void*)m_14;
    Deallocate(oldData);
}

struct FUN_0084fec0_shell
{
    void EnsureFosExtension(char* a, char* b);
};
struct FUN_0084ff30_shell
{
    void CreateScriptMessageDirectory(char* a);
};
int __cdecl strcat_s(char* dst, unsigned int size, const char* src);

struct FUN_0084ff90_shell : FUN_0084fec0_shell
{
    void BuildWeaponPath(char* weapon, char* name, bool tmp);
};

// Builds a path from the weapon and this object, copies it into name, appends the buffer, and adds ".tmp" when tmp is set.
// @fnv 0x0084ff90
void FUN_0084ff90_shell::BuildWeaponPath(char* weapon, char* name, bool tmp)
{
    char buffer[260];
    char path[260];
    EnsureFosExtension(weapon, buffer);
    ((FUN_0084ff30_shell*)this)->CreateScriptMessageDirectory(path);
    TaskQueueInterface::CopyStringToBuffer(name, 260, path);
    strcat_s(name, 260, buffer);
    if (tmp)
        strcat_s(name, 260, ".tmp");
}

extern int DAT_010800a8;
// Sets the vtable, stores arg as the element count, allocates a zeroed count*4 byte buffer via NiMalloc, and returns this.
// @fnv 0x00853270
void* FUN_00852fd0_cls::InitializeBuffer(void* aiCount)
{
    *(void**)this = &DAT_010800a8;
    ((int*)this)[1] = (int)aiCount;
    ((int*)this)[3] = 0;
    int size = ((int*)this)[1] << 2;
    ((int*)this)[2] = (int)NiMalloc(size);
    memset((void*)((int*)this)[2], 0, ((int*)this)[1] << 2);
    return this;
}

int __cdecl DAT_00ffffff;

struct FUN_00857bf0_Class
{
    unsigned char m_4c;
    void* m_50;
    int FUN_00857bf0(int a);
};

// @fnv 0x00857bf0
int FUN_00857bf0_Class::FUN_00857bf0(int auiPacked)
{
    unsigned char b = (auiPacked & 0xff000000) >> 24;
    if (!*(void**)((char*)this + 0x50) || b == 0xff)
        return auiPacked;
    unsigned char c = 0;
    if (b < *(unsigned char*)((char*)this + 0x4c))
    {
        c = ((unsigned char*)*(void**)((char*)this + 0x50))[b];
        if (c != 0xff)
            return (auiPacked & (int)&DAT_00ffffff) + (c << 24);
    }
    return 0;
}

struct P09H
{
    int GetReferenceType();
};
struct MapX
{
    void* GetFirstPos();
};
struct NiTMap
{
    void GetNext(void*&, unsigned int&, void*&);
};
struct TESForm
{
    virtual ~TESForm();
};
struct TESObjectREFR : TESForm
{
    virtual ~TESObjectREFR();
};
extern "C" TESForm* __cdecl LookupFormByID(unsigned int);
struct FUN_0085f070_shell
{
    void SaveReferenceState(TESObjectREFR*, unsigned int, void*);
    void FUN_0085f070();
};
void __cdecl Deallocate(void*);
extern TESObjectREFR* g_thePlayer;
// @fnv 0x0085f070
void FUN_0085f070_shell::FUN_0085f070()
{
    void* pos2 = reinterpret_cast<MapX*>(*(void**)((char*)this + 0x58))->GetFirstPos();
    while (pos2)
    {
        TESObjectREFR* ref;
        unsigned int key;
        void* value2;
        reinterpret_cast<NiTMap*>(*(void**)((char*)this + 0x58))->GetNext(pos2, key, value2);
        if (key)
            ref = dynamic_cast<TESObjectREFR*>(LookupFormByID(key));
        else
            ref = g_thePlayer;
        if (ref)
        {
            if (!reinterpret_cast<P09H*>(ref)->GetReferenceType())
            {
                Deallocate(value2);
                reinterpret_cast<MapH*>(*(void**)((char*)this + 0x58))->RemoveAt(key);
                continue;
            }
            SaveReferenceState(ref, key, value2);
        }
        Deallocate(value2);
        reinterpret_cast<MapH*>(*(void**)((char*)this + 0x58))->RemoveAt(key);
    }
}

namespace fnv_0085f3d0 {
struct TESForm
{
    void Revert(unsigned int);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct FUN_0085f3d0
{
    void* p0;
    void* p4;
    void* p8;
    void* pc;
    void* p10;
    void* p14;
    void Method(TESForm* form, unsigned int value);
};
// @fnv 0x0085f3d0
void FUN_0085f3d0::Method(TESForm* form, unsigned int value)
{
    void* old = p14;
    p14 = (void*)value;
    unsigned int ui;
    g_TESSaveLoadGame->ReadTypedData(&ui, 2);
    form->Revert(0);
    p14 = old;
}
}  // namespace fnv_0085f3d0

struct Struct_004b0680
{
    void* p;
    int pad;
    Struct_004b0680(void* a, void* b);
};
struct FUN_008431c0_Class
{
    void __thiscall FUN_00844eb0(Struct_004b0680*);
    void __thiscall ConstructAndForward(void* a, void* b);
};
// Builds a temporary Struct_004b0680 from the two arguments and passes its address to FUN_00844eb0.
// @fnv 0x008431c0
void __thiscall FUN_008431c0_Class::ConstructAndForward(void* pFirst, void* pSecond)
{
    Struct_004b0680 tmp(pFirst, pSecond);
    FUN_00844eb0(&tmp);
}

struct FUN_008431f0_Class : FUN_00843220_Class
{
    void* __thiscall FUN_008431f0(unsigned int flags);
};
// Calls the base constructor, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x008431f0
void* __thiscall FUN_008431f0_Class::FUN_008431f0(unsigned int flags)
{
    FUN_00843220_Class::FUN_00843220();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_008450e0_Class : FUN_00844660_Class
{
    void* FUN_008450e0(unsigned int flags);
};

// Calls the base cleanup, deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x008450e0
void* FUN_008450e0_Class::FUN_008450e0(unsigned int flags)
{
    FUN_00844660();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern int DAT_0107ed50;
struct SaveGameSizeState
{
    void RecordRequestedSize(unsigned int, unsigned int);
};
struct FUN_00845430 : SaveGameSizeState
{
    void* vtbl;
    FUN_00845430();
};
// @fnv 0x00845430
FUN_00845430::FUN_00845430()
{
    vtbl = &DAT_0107ed50;
    RecordRequestedSize(0, 0);
}

extern int DAT_0107eda8;
extern "C" void __cdecl NiFree(void*);
struct FUN_00845c60
{
    int* vtbl;
    unsigned int count;
    void* data;
    void __thiscall NiTPointerMap_RemoveAll();
    void FUN_00845c60_();
};
// Sets the vtable pointer, removes all entries from the map, and frees the data buffer.
// @fnv 0x00845c60
void FUN_00845c60::FUN_00845c60_()
{
    vtbl = (int*)&DAT_0107eda8;
    NiTPointerMap_RemoveAll();
    NiFree(data);
}

struct FUN_009a5df0
{
    ~FUN_009a5df0();
};
struct FUN_00845c90 : FUN_009a5df0
{
    void* __thiscall DeleteThis(unsigned int flags);
};
// Runs the base destructor, frees this when flags has bit 0 set, and returns this.
// @fnv 0x00845c90
void* FUN_00845c90::DeleteThis(unsigned int flags)
{
    FUN_009a5df0::~FUN_009a5df0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);
struct FormIDConverter
{
    ~FormIDConverter();
    void* FUN_008473c0(unsigned int flags);
};
// Destructs the object, frees it with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x008473c0
void* FormIDConverter::FUN_008473c0(unsigned int flags)
{
    this->FormIDConverter::~FormIDConverter();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_0084b9c0
{
    virtual ~FUN_0084b9c0();
    FUN_0084b9c0* FUN_0084b540(unsigned int flags);
};

// Runs the destructor and, when bit 0 of flags is set, deallocates this object; returns this.
// @fnv 0x0084b540
FUN_0084b9c0* FUN_0084b9c0::FUN_0084b540(unsigned int flags)
{
    this->FUN_0084b9c0::~FUN_0084b9c0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_0084b950_shell
{
    char AreEqual(int a, int b, int c, int d);
};
// Returns 1 if the first pair of ints equals the second pair, otherwise 0.
// @fnv 0x0084b950
char FUN_0084b950_shell::AreEqual(int a, int b, int c, int d)
{
    return (a == c && b == d) ? 1 : 0;
}

struct FUN_0084ba20
{
    virtual ~FUN_0084ba20();
    void* DestroySelf(unsigned int flags);
};
// Calls the destructor, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x0084bb00
void* FUN_0084ba20::DestroySelf(unsigned int flags)
{
    this->FUN_0084ba20::~FUN_0084ba20();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern int DAT_0107f734;
struct FUN_0084d450_class : NiTPointerMap<int, int>
{
    void __thiscall FUN_0084d450();
};
// Sets the vtable pointer, removes all entries from the map, and frees the pointer stored at offset 8.
// @fnv 0x0084d450
void __thiscall FUN_0084d450_class::FUN_0084d450()
{
    *(int**)this = (int*)&DAT_0107f734;
    NiTPointerMap::RemoveAll();
    NiFree(*(void**)((char*)this + 8));
}

extern unsigned int _data_011c16bc;
extern void* DAT_011de134;

struct FUN_0084fda0
{
    unsigned char m_Padding00[0x1C];
    bool m_Flag;
    unsigned char m_Padding1D[0x1B];

    FUN_0084fda0();
};

FUN_0084fda0::FUN_0084fda0()
{}

struct BGSAcousticSpace
{
    virtual void m_Virtual00();
    virtual void m_Virtual04();
    virtual void m_Virtual08();
    virtual unsigned int Check(const char* string, int value1, int value2);

    void __thiscall SetWallaSound(TESSound* sound);
};

void BGSAcousticSpace::m_Virtual00()
{}

void BGSAcousticSpace::m_Virtual04()
{}

void BGSAcousticSpace::m_Virtual08()
{}

unsigned int BGSAcousticSpace::Check(const char* string, int value1, int value2)
{
    return 0;
}

void BGSAcousticSpace::SetWallaSound(TESSound* sound)
{}

BGSAcousticSpace* __cdecl _FUN_00af2e50();

void __cdecl UpdateHasSaves()
{}

// Allocates a FUN_0084fda0, sets its byte at offset 0x1C from Check("-SAVE-",0,0) > 0, and sets the walla sound to UpdateHasSaves.
// @fnv 0x0084fc70
void InitAcousticSpace()
{
    DAT_011de134 = new FUN_0084fda0;

    reinterpret_cast<unsigned char*>(DAT_011de134)[0x1C] = _FUN_00af2e50()->Check("-SAVE-", 0, 0) > 0;

    _FUN_00af2e50()->SetWallaSound(reinterpret_cast<TESSound*>(&UpdateHasSaves));
}

struct FUN_0084fd70_class : FUN_0084fe50_class
{
    void* DestroyAndFree(unsigned int flags);
};
// Runs the base destructor and, when bit 0 of flags is set, deallocates this object; returns this.
// @fnv 0x0084fd70
void* FUN_0084fd70_class::DestroyAndFree(unsigned int flags)
{
    this->FUN_0084fe50_class::~FUN_0084fe50_class();
    if (flags & 1)
        Deallocate(this);
    return this;
}

namespace fnv_00850720 {
char __cdecl ConsumeByteAtE4();
struct BGSSaveLoadManager
{
    bool LoadGame(char*, int, bool, bool);
};
extern BGSSaveLoadManager* DAT_011de134;
extern char DAT_011de138[];
extern int DAT_011a224c;
extern bool DAT_011de23c;
// Calls ConsumeByteAtE4 and, if it returns 1, invokes DAT_011de134->LoadGame with DAT_011de138, DAT_011a224c, DAT_011de23c and true.
// @fnv 0x00850720
void __cdecl FUN_00850720()
{
    signed char c;
    c = ConsumeByteAtE4();
    if (c == 1)
        DAT_011de134->LoadGame(DAT_011de138, DAT_011a224c, DAT_011de23c, true);
}
}  // namespace fnv_00850720

struct FUN_00851fc0_shell
{
    void FUN_00851fc0(unsigned int a);
};
// @fnv 0x00851fc0
void FUN_00851fc0_shell::FUN_00851fc0(unsigned int pData)
{
    TaskQueueInterface::CopyStringToBuffer((char*)((char*)this + 0x2e5), 0x400, (const char*)pData);
}

struct FUN_00853470 : FUN_00853210_cls
{
    void* __thiscall DeleteThis(unsigned int flags);
};

// @fnv 0x00853470
void* FUN_00853470::DeleteThis(unsigned int flags)
{
    FUN_00853210();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct AEList
{
    void Insert(void*, int(__cdecl*)(void*, void*));
};

void CompareByPriority();

struct FUN_00854c10_Class
{
    char pad[0x10];
    AEList list;
    void FUN_00854c10(int a1, int a2, int a3);
};

// @fnv 0x00854c10
void FUN_00854c10_Class::FUN_00854c10(int a1, int a2, int a3)
{
    char* buf;
    {
        char* tmp = (char*)operator new(0x10c);
        buf = tmp;
    }
    TaskQueueInterface::CopyStringToBuffer(buf, 0x104, (const char*)a1);
    *(int*)(buf + 0x104) = a2;
    *(int*)(buf + 0x108) = a3;
    list.Insert(buf, (int(__cdecl*)(void*, void*))CompareByPriority);
}

void NiFree(void*);

struct FUN_00854db0_class : NiTPointerMap<int, int>
{
    void __thiscall ClearAndFree();
};

// Sets the vtable pointer, removes all entries from the map, and frees the pointer stored at offset 8.
// @fnv 0x00854db0
void __thiscall FUN_00854db0_class::ClearAndFree()
{
    *(int**)this = &DAT_01080454;
    this->RemoveAll();
    NiFree(*(void**)((char*)this + 8));
}

struct FUN_00857210_shell
{
    bool Flush();
    void FUN_00857210();
};
// @fnv 0x00857210
void FUN_00857210_shell::FUN_00857210()
{
    Flush();
}

struct FUN_00857280
{
    int a;
    int b;
    int c;
    char d;
    FUN_00857280(int, int, int, char);
};
// Stores the four constructor arguments into the object's fields a, b, c and d.
// @fnv 0x00857280
FUN_00857280::FUN_00857280(int x, int y, int z, char f)
{
    a = x;
    b = y;
    c = z;
    d = f;
}

void* __cdecl operator new(unsigned int size);
void* __cdecl __memcpy(void* dst, const void* src, unsigned int count);
struct FUN_0085ef80_class
{
    void* AllocateWithPrefix(unsigned short value);
};
// Allocates value + 2 bytes, copies the 2-byte value to the start of the block, and returns the block.
// @fnv 0x0085ef80
void* FUN_0085ef80_class::AllocateWithPrefix(unsigned short value)
{
    unsigned short local;
    local = value;
    void* result2 = operator new(value + 2);
    __memcpy(result2, &local, 2);
    return result2;
}

struct FUN_0085f5a0_Class : public Holder
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
    void FUN_0085f5a0(TESSound* sound, unsigned short flag);
};

// Forwards the sound's Deallocate() result and flag to FUN_0085efc0 with the map stored at this+0x64.
// @fnv 0x0085f5a0
void FUN_0085f5a0_Class::FUN_0085f5a0(TESSound* sound, unsigned short flag)
{
    FUN_0085efc0(reinterpret_cast<DummyPointerMap*>(*(void**)((char*)this + 0x64)), sound->Deallocate(), flag);
}

extern void* DAT_011de45c;

struct FUN_00560530_Class
{
    void FUN_00560530(unsigned short arg);
};

struct FUN_0085f6c0_Class
{
    char pad[0x14];
    int m_14;
    void FUN_0085f6c0(int arg1, int arg2);
};

// @fnv 0x0085f6c0
void FUN_0085f6c0_Class::FUN_0085f6c0(int apTarget, int aiValue)
{
    int saved = m_14;
    m_14 = aiValue;
    unsigned short buf;
    ((TESSaveLoadGame*)DAT_011de45c)->ReadTypedData(&buf, 2);
    ((FUN_00560530_Class*)apTarget)->FUN_00560530(buf);
    m_14 = saved;
}

struct FUN_0085f810_shell
{
    void* __thiscall FUN_0085f810();
};
// Returns the pointer at offset 0x28 of the object stored at offset 0x88, or null if that object is absent.
// @fnv 0x0085f810
void* FUN_0085f810_shell::FUN_0085f810()
{
    return *(void**)((char*)this + 0x88) ? *(void**)((char*)*(void**)((char*)this + 0x88) + 0x28) : 0;
}

struct FUN_0085f2e0_class
{
    void FUN_0085f2e0();
};

struct FUN_0085f450_class
{
    void FUN_0085f450();
};

struct FUN_0085f5d0_class
{
    void ProcessMapEntries();
};

struct FUN_0085f750_class
{
    void DetachProjectiles();
};

struct FUN_00978420_class
{
    void FUN_00978420(float, int);
};

struct Zt5TES
{
    void FUN_00453550(float);
};

struct BSOcclusionPlane
{
    int GetCullResult() const;
};

struct ExtraDataList
{
    unsigned int GetRoomId();
};

struct FUN_00c6a870_class
{
    void FUN_00c6a870();
};

struct TESSaveLoadGame_GetLoading_class
{
    bool GetLoading();
};

extern Zt5TES* g_TES;
extern BSOcclusionPlane* _g_thePlayer;
extern FUN_00978420_class DAT_011e0e80;

struct FUN_0085f850_class
{
    void FUN_0085f850(bool);
};

// @fnv 0x0085f850
void FUN_0085f850_class::FUN_0085f850(bool arg)
{
    if (!reinterpret_cast<TESSaveLoadGame_GetLoading_class*>(this)->GetLoading())
        return;

    reinterpret_cast<FUN_0085f070_shell*>(this)->FUN_0085f070();
    reinterpret_cast<FUN_0085f2e0_class*>(this)->FUN_0085f2e0();
    reinterpret_cast<FUN_0085f450_class*>(this)->FUN_0085f450();

    if (arg)
    {
        DAT_011e0e80.FUN_00978420(0.0f, 0);
        g_TES->FUN_00453550(0.0f);

        int cullResult = _g_thePlayer->GetCullResult();
        if (cullResult)
        {
            unsigned int room = reinterpret_cast<ExtraDataList*>(cullResult)->GetRoomId();
            if (room)
                reinterpret_cast<FUN_00c6a870_class*>(room)->FUN_00c6a870();
        }
    }

    reinterpret_cast<FUN_0085f5d0_class*>(this)->ProcessMapEntries();
    reinterpret_cast<FUN_0085f750_class*>(this)->DetachProjectiles();
}

struct B844520Stamp
{
    int m_iLow;
    int m_iHigh;

    B844520Stamp(int iValue);
};

struct B844520Item
{
    int unk00;
    int unk04;
    B844520Stamp m_kStamp;
};

struct B844520List
{
    void FreeMemory(void* pvItem);
};

class B844520Queue
{
  public:
    int unk00;
    int unk04;
    int unk08;
    B844520List m_kUnsortedGeometryList;

    void FUN_00844520(B844520Item* pkItem);
};

// @fnv 0x00844520
void B844520Queue::FUN_00844520(B844520Item* pkItem)
{
    B844520Stamp kStamp(0);
    pkItem->m_kStamp = kStamp;
    m_kUnsortedGeometryList.FreeMemory(pkItem);
}

struct SaveLoadCleanup
{
    void Cleanup();
    void* FUN_008451a0(unsigned int flags);
};

// Calls Cleanup, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x008451a0
void* SaveLoadCleanup::FUN_008451a0(unsigned int flags)
{
    Cleanup();
    if (flags & 1)
    {
        Deallocate(this);
    }
    return this;
}

void* __cdecl FormHeap_Allocate(unsigned int size);

struct Obj_b9971
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    Obj_b9971();
    static void* operator new(unsigned int size) throw()
    {
        return FormHeap_Allocate(size);
    }
};

struct FUN_0069b8a0_cls
{
    Obj_b9971* CreateObj();
};

// Allocates and constructs a new Obj_b9971 and returns its pointer.
// @fnv 0x00845260
Obj_b9971* FUN_0069b8a0_cls::CreateObj()
{
    return new Obj_b9971();
}

class B4B6C0MapBase
{
  public:
    virtual ~B4B6C0MapBase();
    int m_uiHashSize;
    void** m_ppkHashTable;
    int m_uiCount;
};

class FUN_0084b6c0_Map : public B4B6C0MapBase
{
  public:
    virtual ~FUN_0084b6c0_Map();
    void RemoveAll();
};

// @fnv 0x0084b6c0
FUN_0084b6c0_Map::~FUN_0084b6c0_Map()
{
    RemoveAll();
}

struct KeyPair
{
    unsigned int first;
    unsigned int second;
};
struct MapEntry
{
    MapEntry* next;
    int flags;
    KeyPair key;
    unsigned int value;
};

struct HashMap
{
    virtual void Unknown0();
    virtual unsigned int GetBucket(unsigned int key1, unsigned int key2);
    virtual bool Equal(unsigned int key1, unsigned int key2, KeyPair other);
    virtual void InitEntry(MapEntry* entry, unsigned int key1, unsigned int key2, unsigned int value);
    virtual void Unknown4();
    virtual MapEntry* NewEntry();

    unsigned int unknown04;
    MapEntry** buckets;
    unsigned int count;

    void InsertOrUpdate(unsigned int key1, unsigned int key2, unsigned int value);
};

// Looks up the bucket for a key pair, updates the value if the entry exists, otherwise creates, initializes and prepends a new entry and increments count.
// @fnv 0x0084b7c0
void HashMap::InsertOrUpdate(unsigned int key1, unsigned int key2, unsigned int value)
{
    unsigned int index = GetBucket(key1, key2);
    MapEntry* entry = buckets[index];
    unsigned int num = 0;
    while (entry != 0)
    {
        ++num;
        if (Equal(key1, key2, entry->key))
        {
            entry->value = value;
            return;
        }
        entry = entry->next;
    }
    entry = NewEntry();
    InitEntry(entry, key1, key2, value);
    entry->next = buckets[index];
    buckets[index] = entry;
    ++count;
}

struct FUN_0084b930_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int ModuloByField(volatile unsigned int a, unsigned int b);
};
// @fnv 0x0084b930
unsigned int FUN_0084b930_cls::ModuloByField(volatile unsigned int auiValue, unsigned int auiUnused)
{
    return auiValue % this->unk04;
}

// SetPairAndExtra : thiscall setter. Copies a small 8-byte by-value struct into
// the destination object at offset 8, then stores one more int at offset 0x10.
struct FUN_0084b990_pair
{
    int m_i00;
    int m_i04;
};

struct FUN_0084b990_data
{
    int m_i00;
    int m_i04;
    FUN_0084b990_pair m_pair;
    int m_i10;
};

class FUN_0084b990_cls
{
  public:
    void SetPairAndExtra(FUN_0084b990_data* data, FUN_0084b990_pair values, int extra);
};

// Stores the pair into data->m_pair and extra into data->m_i10.
// @fnv 0x0084b990
void FUN_0084b990_cls::SetPairAndExtra(FUN_0084b990_data* data, FUN_0084b990_pair pairValues, int extra)
{
    data->m_pair = pairValues;
    data->m_i10 = extra;
}

class RefScanBuffer
{
  public:
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0C;
    unsigned int m_unk10;
    RefScanBuffer();
    ~RefScanBuffer();
    void Append(void* owner);
    void Reset();
};

bool __cdecl ProbeRefAt(unsigned int index, RefScanBuffer* buf);
void __cdecl CopyRefAt(void* owner, unsigned int* index, unsigned int size);

// @fnv 0x0084bb50
int ScanRefsInRange(void* owner, unsigned int begin, unsigned int end)
{
    int iHits = 0;
    RefScanBuffer _buf;
    for (unsigned int i = begin; i < end; i++)
    {
        if (ProbeRefAt(i, &_buf))
        {
            CopyRefAt(owner, &i, 4);
            _buf.Append(owner);
            _buf.Reset();
            iHits++;
        }
    }
    return iHits;
}

struct FUN_0084d310_entry;

struct FUN_0084d310_class
{
    virtual void FUN_0084d310_slot0() = 0;
    virtual int FUN_0084d310_lookup(int key) = 0;
    virtual bool FUN_0084d310_match(int key, int value) = 0;
    virtual void FUN_0084d310_create(void* node, int key, unsigned char value) = 0;
    virtual void FUN_0084d310_unused() = 0;
    virtual void* FUN_0084d310_allocate() = 0;

    void* unk04;
    FUN_0084d310_entry** m_buckets;
    unsigned int m_uiItemCount;

    void FUN_0084d310(int key, unsigned char value);
};

struct FUN_0084d310_entry
{
    FUN_0084d310_entry* m_next;
    int m_key;
    unsigned char m_uiFilterValue;
};

// @fnv 0x0084d310
void FUN_0084d310_class::FUN_0084d310(int key, unsigned char value)
{
    int index = FUN_0084d310_lookup(key);
    FUN_0084d310_entry* entry = m_buckets[index];
    int count = 0;

    while (entry != 0)
    {
        ++count;
        if (FUN_0084d310_match(key, entry->m_key))
        {
            entry->m_uiFilterValue = value;
            return;
        }
        entry = entry->m_next;
    }

    entry = static_cast<FUN_0084d310_entry*>(FUN_0084d310_allocate());

    FUN_0084d310_create(entry, key, value);
    entry->m_next = m_buckets[index];
    m_buckets[index] = entry;
    ++m_uiItemCount;
}

struct FUN_0084d450
{
    virtual ~FUN_0084d450();
};

struct FUN_0084d3f0 : FUN_0084d450
{
    virtual ~FUN_0084d3f0();
    void FUN_00438af0();
};

// @fnv 0x0084d3f0
FUN_0084d3f0::~FUN_0084d3f0()
{
    FUN_00438af0();
}

struct SaveEntryData
{
    unsigned short resourceId;
    short row;
    short column;
    unsigned short flagsLow;
    unsigned short flagsHigh;
};
struct ItemRef
{
    unsigned int FUN_00846d20();
};
struct ItemManager
{
    ItemRef* FUN_0084e3a0(unsigned int resourceId);
};
struct FUN_0084e3c0_Class
{
    unsigned int handle;
    int row;
    int column;
    unsigned int flags;
    void LoadFromSaveEntry(const SaveEntryData* data);
};
// Copies row, column and flags from the save entry, then resolves the resource id to a handle via the item manager.
// @fnv 0x0084e3c0
void FUN_0084e3c0_Class::LoadFromSaveEntry(const SaveEntryData* pEntry)
{
    row = pEntry->row;
    column = pEntry->column;
    flags = *reinterpret_cast<const unsigned int*>(&pEntry->flagsLow);
    handle = reinterpret_cast<ItemManager*>(g_BGSSaveLoadGame)->FUN_0084e3a0(pEntry->resourceId)->FUN_00846d20();
}

struct FUN_0084e4f0_triple
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

class FUN_0084e4f0_cls
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    FUN_0084e4f0_triple m_14;
    FUN_0084e4f0_triple m_20;
    unsigned char m_2c;
    void FUN_0084e4f0(void* src);
};

// Reads two values via FUN_00853500 from src and src+0x1c, zeroes m_08/m_0c/m_10, copies two triples from src+3 and src+0xf, and stores the byte at src+0x1b.
// @fnv 0x0084e4f0
void FUN_0084e4f0_cls::FUN_0084e4f0(void* pSource)
{
    m_00 = FUN_00853500(pSource);
    m_04 = FUN_00853500((char*)pSource + 0x1c);
    m_08 = 0;
    m_0c = 0;
    m_10 = 0;
    m_14 = *(FUN_0084e4f0_triple*)((char*)pSource + 3);
    m_20 = *(FUN_0084e4f0_triple*)((char*)pSource + 0xf);
    m_2c = *((unsigned char*)pSource + 0x1b);
}

struct FNVU64Pair
{
    unsigned int lo;
    unsigned int hi;
};

class FNVU64Source
{
  public:
    void GetValue(FNVU64Pair* out);
};

// Reads a 64-bit value from each source and returns -1, 1 or 0 by comparing high words first, then low words.
// @fnv 0x0084fbe0
int __cdecl CompareU64Values(FNVU64Source* pFirstSource, FNVU64Source* pSecondSource)
{
    FNVU64Pair first;
    FNVU64Pair second;
    int result;

    pFirstSource->GetValue(&first);
    pSecondSource->GetValue(&second);
    if (first.hi > second.hi)
    {
        return -1;
    }
    else if (first.hi < second.hi)
    {
        return 1;
    }
    if (first.lo > second.lo)
    {
        result = -1;
    }
    else
    {
        result = (first.lo < second.lo) ? 1 : 0;
    }
    return result;
}

struct FUN_0084fc50_pair
{
    int m_uiX;
    int m_uiY;
};

struct FUN_0084fc50_cls
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
    FUN_0084fc50_pair m_pair;
    void FUN_0084fc50(FUN_0084fc50_pair* out);
};

// @fnv 0x0084fc50
void FUN_0084fc50_cls::FUN_0084fc50(FUN_0084fc50_pair* out)
{
    *out = m_pair;
}

struct FUN_00850360_class : public FUN_0084ff90_shell
{
    void DeleteWeaponFile(char* weapon, int flags);
};

extern "C" __declspec(dllimport) int __stdcall DeleteFileA(char* lpFileName);

// Builds a file path from weapon via BuildWeaponPath and deletes that file with DeleteFileA.
// @fnv 0x00850360
void FUN_00850360_class::DeleteWeaponFile(char* weapon, int flags)
{
    char path[260];

    BuildWeaponPath(weapon, path, false);
    DeleteFileA(path);
}

struct BC0Item
{
    unsigned int GetPriority();
};

// Compares two BC0Item objects by their GetPriority() values, returning -1 if the first has higher priority, otherwise 0 or 1.
// @fnv 0x00854bc0
int __cdecl CompareByPriority(BC0Item* pkA, BC0Item* pkB)
{
    unsigned int uiA = pkA->GetPriority();
    unsigned int uiB = pkB->GetPriority();
    return uiA > uiB ? -1 : uiA < uiB;
}

class FUN_008562c0_cls
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned short m_08;
    unsigned short m_0a;
    FUN_008562c0_cls* FUN_008562c0();
};

// Clears m_00, m_04 and m_0a to zero, sets m_08 to 0xffff, and returns this.
// @fnv 0x008562c0
FUN_008562c0_cls* FUN_008562c0_cls::FUN_008562c0()
{
    m_0a = 0;
    m_04 = 0;
    m_00 = 0;
    m_08 = 0xffff;
    return this;
}

extern int DAT_00ffffff;

struct FUN_00857c70_StandIn
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
    unsigned char unk4C;
    unsigned char* unk50;

    unsigned int __thiscall FUN_00857c70(unsigned int value);
};

// @fnv 0x00857c70
unsigned int __thiscall FUN_00857c70_StandIn::FUN_00857c70(unsigned int value)
{
    unsigned char code = static_cast<unsigned char>((value & 0xFF000000u) >> 24);

    if (this->unk50 == 0 || code == 0xFF)
        return value;

    {
        unsigned char foundIndex;
        int index;

        foundIndex = 0xFF;
        index = 0;

        for (; index < this->unk4C; ++index)
        {
            if (this->unk50[index] == code)
                foundIndex = static_cast<unsigned char>(index);
        }

        if (foundIndex != 0xFF)
            return (value & static_cast<unsigned int>(reinterpret_cast<unsigned int>(&DAT_00ffffff))) +
                   (static_cast<unsigned int>(foundIndex) << 24);

        return 0;
    }
}

class StaticFlagMgr
{
  public:
    unsigned char FUN_00469860(int value);
};

extern StaticFlagMgr* DAT_011c3f2c;

struct FUN_00859120_probe
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int FUN_0084e3a0();
};

class FUN_00859120_cls
{
  public:
    unsigned int __thiscall ClearRefrFlag(TESForm* arg1, unsigned int flags);
};

// Clears bit 1 of flags when the form is a TESObjectREFR and the static flag manager reports nonzero for its probe value.
// @fnv 0x00859120
unsigned int __thiscall FUN_00859120_cls::ClearRefrFlag(TESForm* pForm, unsigned int flags)
{
    TESObjectREFR* a;
    TESObjectCELL* b;
    if (DAT_011c3f2c->FUN_00469860(reinterpret_cast<FUN_00859120_probe*>(pForm)->FUN_0084e3a0()) != 0)
    {
        a = dynamic_cast<TESObjectREFR*>(pForm);
        if (a != 0)
        {
            flags = flags;
            flags &= 0xfffffffd;
        }
        b = dynamic_cast<TESObjectCELL*>(pForm);
        if (b != 0)
        {
            flags = flags;
        }
    }
    return flags;
}

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern char DAT_01080864;
void __cdecl FUN_005b5e40(void*);

struct BinaryRecord36
{
    void* value00;
    void* value04;
    void* value08;
    unsigned int value0c, value10, value14, value18, value1c, value20;
    void FUN_008572c0();
};
struct BinaryRecord44
{
    void* value00;
    unsigned int value04, value08, value0c;
    void* value10;
    unsigned int value14, value18, value1c, value20, value24, value28;
    void FUN_00857320();
};
class TESForm;
class MagicProjectile
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual ~MagicProjectile();
};
struct SourceItem
{
    unsigned int FUN_00559450();
    unsigned char* FUN_00726070();
};
struct SourceItemMap
{
    SourceItem* FUN_00855100(unsigned int key);
};
struct SourceTracker
{
    void FUN_00905330(unsigned int* key);
};
struct FUN_008598d0_shell
{
    SourceItemMap* source;
    unsigned int field04, field08, field0c, field10, field14;
    unsigned int field18, field1c, field20;
    SourceTracker tracker;
    void* FUN_00861c00(void*);
    TESForm* FUN_00859a90(unsigned int key, BinaryRecord36* data);
    TESForm* FUN_00859f20(unsigned int key, BinaryRecord44* data);
    void FUN_00858730(TESForm*);
    void ProcessSourceItem(unsigned int key);
};
// @fnv 0x008598d0
void FUN_008598d0_shell::ProcessSourceItem(unsigned int key)
{
    SourceItem* item = source->FUN_00855100(key);
    if (item != 0)
    {
        unsigned int flags = item->FUN_00559450();
        if (flags & 0)
        {
            unsigned char* bytes = item->FUN_00726070();
            if (bytes != 0)
            {
                TESForm* pCreated;
                BinaryRecord36 record;
                record.FUN_008572c0();
                bytes += 4;
                memcpy(&record, bytes, sizeof(record));
                record.value04 = FUN_00861c00(record.value04);
                record.value08 = FUN_00861c00(record.value08);
                pCreated = FUN_00859a90(key, &record);
                if (pCreated != 0)
                {
                    MagicProjectile* asSpecial = dynamic_cast<MagicProjectile*>(pCreated);
                    if (asSpecial != 0)
                    {
                        delete asSpecial;
                        return;
                    }
                    FUN_00858730(pCreated);
                }
            }
        }
        else if (flags & 0)
        {
            unsigned char* bytes2 = item->FUN_00726070();
            if (bytes2 != 0)
            {
                BinaryRecord44 record2;
                record2.FUN_00857320();
                bytes2 += 4;
                memcpy(&record2, bytes2, sizeof(record2));
                record2.value00 = FUN_00861c00(record2.value00);
                record2.value10 = FUN_00861c00(record2.value10);
                TESForm* newObject2 = FUN_00859f20(key, &record2);
                if (newObject2 != 0)
                    FUN_00858730(newObject2);
                tracker.FUN_00905330(&key);
            }
        }
        else
        {
            FUN_005b5e40(&DAT_01080864);
        }
    }
}

struct SavedReferenceData
{
    void LoadFromSave(TESObjectREFR*);
    char* FUN_00491040(char*);
};
struct ReferenceDataAccess
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
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual SavedReferenceData* GetData();
};
struct PlayerSaveAccess : TESObjectREFR
{
    SavedReferenceData* FUN_00950a60(bool);
};
extern PlayerSaveAccess* DAT_011dea3c;
class BaseProcess
{
  public:
    virtual void slot0();
};
class HighProcess : public BaseProcess
{
  public:
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
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void slot186();
    virtual void slot187();
    virtual void slot188();
    virtual void slot189();
    virtual void slot190();
    virtual void slot191();
    virtual void slot192();
    virtual void slot193();
    virtual void slot194();
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual void slot198();
    virtual void slot199();
    virtual void slot200();
    virtual void slot201();
    virtual void slot202();
    virtual void slot203();
    virtual void slot204();
    virtual void slot205();
    virtual void slot206();
    virtual void slot207();
    virtual void slot208();
    virtual void slot209();
    virtual void slot210();
    virtual void slot211();
    virtual void slot212();
    virtual void slot213();
    virtual void slot214();
    virtual void slot215();
    virtual void slot216();
    virtual void slot217();
    virtual void slot218();
    virtual void slot219();
    virtual void slot220();
    virtual void slot221();
    virtual void slot222();
    virtual void slot223();
    virtual void slot224();
    virtual void slot225();
    virtual void slot226();
    virtual void slot227();
    virtual void slot228();
    virtual void slot229();
    virtual void slot230();
    virtual void slot231();
    virtual void slot232();
    virtual void slot233();
    virtual void slot234();
    virtual void slot235();
    virtual void slot236();
    virtual void slot237();
    virtual void slot238();
    virtual void slot239();
    virtual void slot240();
    virtual void slot241();
    virtual void slot242();
    virtual void slot243();
    virtual void slot244();
    virtual void slot245();
    virtual void slot246();
    virtual void slot247();
    virtual void slot248();
    virtual int GetSavedState();
    virtual char* GetSavedToken();
    virtual void RestoreSavedState(int, char*);
};
class MobileObject : public TESObjectREFR
{
  public:
    BaseProcess* FUN_008d8520();
};
struct SaveManagerAccess
{
    void FUN_008579e0(int*, int);
};
struct ReferenceSaveContext
{
    unsigned int unk00, unk04, unk08, unk0C, unk10;
    int mode;
    void SaveReferenceState(TESObjectREFR*, int, int);
};
// Saves the reference's data, temporarily sets mode, and restores the high process saved state and token for first-person references.
// @fnv 0x0085f150
void ReferenceSaveContext::SaveReferenceState(TESObjectREFR* reference, int firstPerson, int newMode)
{
    SavedReferenceData* dataB;
    if (reference == DAT_011dea3c)
    {
        if (firstPerson)
            dataB = DAT_011dea3c->FUN_00950a60(false);
        else
            dataB = DAT_011dea3c->FUN_00950a60(true);
    }
    else
    {
        dataB = reinterpret_cast<ReferenceDataAccess*>(reference)->GetData();
    }
    MobileObject* _mobile = dynamic_cast<MobileObject*>(reference);
    HighProcess* process = 0;
    int savedState4 = -1;
    char* token = 0;
    if (_mobile && firstPerson)
    {
        process = dynamic_cast<HighProcess*>(_mobile->FUN_008d8520());
        if (process)
        {
            savedState4 = process->GetSavedState();
            token = process->GetSavedToken();
        }
    }
    int oldMode = mode;
    mode = newMode;
    int index;
    static_cast<SaveManagerAccess*>(DAT_011de45c)->FUN_008579e0(&index, 2);
    if (dataB)
        dataB->LoadFromSave(reference);
    mode = oldMode;
    if (process)
    {
        if (token)
        {
            char* start = token - 8;
            token = dataB->FUN_00491040(start);
        }
        process->RestoreSavedState(savedState4, token);
    }
}

extern "C" void __cdecl FormHeap_Free(void* data);
struct FnvMap
{
    void* FUN_004b9ba0();
    void FUN_006b7f20(void*& cursor, unsigned int& id, void*& data);
    void RemoveKey(unsigned int id);
};
struct FnvQueue
{
    void GetOrCreateNode(TESObjectREFR* ref, unsigned int flag);
};
struct FnvRefMethod
{
    int FUN_0043fcd0();
};
struct FnvState
{
    FnvQueue* unk00;
    FnvQueue* unk04;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    int unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    FnvMap* unk64;
};
// @fnv 0x0085f5d0
void FUN_0085f5d0_class::ProcessMapEntries()
{
    void* cursor = reinterpret_cast<FnvState*>(this)->unk64->FUN_004b9ba0();
    while (cursor)
    {
        unsigned int key;
        void* data;
        reinterpret_cast<FnvState*>(this)->unk64->FUN_006b7f20(cursor, key, data);
        TESObjectREFR* refObject = dynamic_cast<TESObjectREFR*>(LookupFormByID(key));
        if (refObject)
        {
            if (!reinterpret_cast<FnvRefMethod*>(refObject)->FUN_0043fcd0())
            {
                if (reinterpret_cast<FnvState*>(this)->unk04)
                    reinterpret_cast<FnvState*>(this)->unk04->GetOrCreateNode(refObject, 0);
                else
                    reinterpret_cast<FnvState*>(this)->unk00->GetOrCreateNode(refObject, 0);
                reinterpret_cast<FnvState*>(this)->unk64->RemoveKey(key);
                continue;
            }
            reinterpret_cast<FUN_0085f6c0_Class*>(this)->FUN_0085f6c0((int)refObject, (int)data);
        }
        FormHeap_Free(data);
        reinterpret_cast<FnvState*>(this)->unk64->RemoveKey(key);
    }
}

class B5F750Node
{
  public:
    void Update(const void* pvData);
};

class B5F750UpdateData
{
  public:
    B5F750UpdateData(float fTime, bool m_bUpdateEnabled, bool bIsMultiThreaded);

    float m_fTime;
    bool m_bUpdate;
    bool m_bIsMultiThreaded;
    int unk08;
};

class B5F750Ref
{
  public:
    B5F750Node* Get3DSimple();
};

class ArrowProjectile : public TESForm
{
  public:
    B5F750Ref* GetAttachedRef();
    void Detach();
};

class B5F750List
{
  public:
    TESForm** GetItem();
    B5F750List* GetNext();
    void RemoveAll();

    TESForm* m_pkItem;
    B5F750List* m_pkNext;
};

class B5F750Owner
{
  public:
    void DetachProjectiles();

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
    B5F750List m_kProjectiles;
};

// @fnv 0x0085f750
void B5F750Owner::DetachProjectiles()
{
    B5F750List* pkNode = &m_kProjectiles;
    while (pkNode)
    {
        TESForm* pkForm = *pkNode->GetItem();
        if (pkForm)
        {
            ArrowProjectile* pkArrow = dynamic_cast<ArrowProjectile*>(pkForm);
            if (pkArrow)
            {
                B5F750Ref* pkRef = pkArrow->GetAttachedRef();
                if (pkRef)
                {
                    B5F750Node* pkNode3D = pkRef->Get3DSimple();
                    if (pkNode3D)
                    {
                        B5F750UpdateData kData(0.0f, false, false);
                        pkNode3D->Update(&kData);
                    }
                }
                pkArrow->Detach();
            }
        }
        pkNode = pkNode->GetNext();
    }
    m_kProjectiles.RemoveAll();
}

// FUN_0085fe50 - 0x0085fe50, 39 bytes.  The unit 0x0085xxxx is an
// unoptimised (/Od) build: the prologue homes `this` in a frame slot
// ("push ecx / mov dword ptr [ebp-4],ecx") and every argument is re-read
// from its stack slot.
//
// The function copies the object's 8-byte member at +0x15c into the
// caller's 8-byte structure and hands that structure back to the caller:
//
//   mov  eax, [ebp-4]        ; this
//   mov  ecx, [eax+0x15c]    ; m_15c.m_00      <- both source words are
//   mov  edx, [eax+0x160]    ; m_15c.m_04         loaded BEFORE the
//   mov  eax, [ebp+8]        ; out                 destination address
//   mov  [eax], ecx
//   mov  [eax+4], edx
//   mov  eax, [ebp+8]        ; the returned pointer
//   mov  esp, ebp / pop ebp / ret 4
//
// The caller at 0x0085fd63 confirms the return value:
//   lea ecx,[ebp-0x16c] / push ecx / mov ecx,[ebp+0xc] / call 0x85fe50
//   mov edx,[eax] / mov eax,[eax+4]
// i.e. it reads the two words through the POINTER the function returned.
//
// Sibling members of the same object:
//   SetPair(int,int)  writes +0x15c/+0x160 and sets the byte at +0x158
//   GetByteAt158()         returns the byte at +0x158
struct FNV_0085fe50_Pair
{
    int m_00;  // +0x00
    int m_04;  // +0x04
};

struct FNV_0085fe50_Obj
{
    char pad[0x158];          // +0x00 .. +0x157
    unsigned char m_158;      // +0x158
    char pad159[3];           // +0x159 .. +0x15b
    FNV_0085fe50_Pair m_15c;  // +0x15c
    FNV_0085fe50_Pair* FUN_0085fe50(FNV_0085fe50_Pair* out);
    void SetPair(int a, int b);
    unsigned char GetByteAt158();
};

// Copies the m_15c pair into out and returns out.
// @fnv 0x0085fe50
FNV_0085fe50_Pair* FNV_0085fe50_Obj::FUN_0085fe50(FNV_0085fe50_Pair* out)
{
    *out = m_15c;
    return out;
}

struct FUN_0085fe80_pair
{
    int m_00;
    int m_04;
};

struct FUN_0085fe80_cls
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
    unsigned char m_158;
    unsigned char unk159;
    unsigned char unk15A;
    unsigned char unk15B;
    FUN_0085fe80_pair m_15c;
    void SetPair(FUN_0085fe80_pair a1);
};

// Stores the given pair into m_15c and sets m_158 to 1.
// @fnv 0x0085fe80
void FUN_0085fe80_cls::SetPair(FUN_0085fe80_pair aPair)
{
    m_15c = aPair;
    m_158 = 1;
}

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
void* __cdecl memset(void*, int, unsigned int);
struct SaveMemberA
{
    int a, b, c, d;
    SaveMemberA();
    ~SaveMemberA();
};
struct SaveMemberB
{
    int a, b, c, d;
    SaveMemberB(int);
    ~SaveMemberB();
};
struct ChangesMap
{
    int field00;
    int field04;
    int field08;
    int field0c;
    ChangesMap();
};
struct SaveMap
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    SaveMap(int);
};
struct SaveTable
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    SaveTable();
};
struct LoadTable
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    LoadTable();
};
struct PointerMap
{
    int field00;
    int field04;
    int field08;
    int field0c;
    PointerMap(int);
};
struct FileMap
{
    int field00;
    int field04;
    int field08;
    int field0c;
    FileMap();
};
struct ReconstructMap
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    int field30;
    ReconstructMap();
};
struct FUN_00846f30
{
    ChangesMap* changes;
    int flag;
    SaveMap* forms;
    SaveMap* refs;
    SaveTable* saves;
    LoadTable* loads;
    PointerMap* pointers;
    FileMap* files;
    ReconstructMap* reconstruct;
    SaveMemberA memberA;
    SaveMemberB memberB;
    unsigned char field044;
    unsigned char field045;
    unsigned char field046;
    unsigned char field047;
    unsigned char field048;
    unsigned char field049;
    unsigned char field04a;
    unsigned char field04b;
    unsigned char field04c;
    unsigned char field04d;
    unsigned char field04e;
    unsigned char field04f;
    unsigned char field050;
    unsigned char field051;
    unsigned char field052;
    unsigned char field053;
    unsigned char field054;
    unsigned char field055;
    unsigned char field056;
    unsigned char field057;
    unsigned char field058;
    unsigned char field059;
    unsigned char field05a;
    unsigned char field05b;
    unsigned char field05c;
    unsigned char field05d;
    unsigned char field05e;
    unsigned char field05f;
    unsigned char field060;
    unsigned char field061;
    unsigned char field062;
    unsigned char field063;
    unsigned char field064;
    unsigned char field065;
    unsigned char field066;
    unsigned char field067;
    unsigned char field068;
    unsigned char field069;
    unsigned char field06a;
    unsigned char field06b;
    unsigned char field06c;
    unsigned char field06d;
    unsigned char field06e;
    unsigned char field06f;
    unsigned char field070;
    unsigned char field071;
    unsigned char field072;
    unsigned char field073;
    unsigned char field074;
    unsigned char field075;
    unsigned char field076;
    unsigned char field077;
    unsigned char field078;
    unsigned char field079;
    unsigned char field07a;
    unsigned char field07b;
    unsigned char field07c;
    unsigned char field07d;
    unsigned char field07e;
    unsigned char field07f;
    unsigned char field080;
    unsigned char field081;
    unsigned char field082;
    unsigned char field083;
    unsigned char field084;
    unsigned char field085;
    unsigned char field086;
    unsigned char field087;
    unsigned char field088;
    unsigned char field089;
    unsigned char field08a;
    unsigned char field08b;
    unsigned char field08c;
    unsigned char field08d;
    unsigned char field08e;
    unsigned char field08f;
    unsigned char field090;
    unsigned char field091;
    unsigned char field092;
    unsigned char field093;
    unsigned char field094;
    unsigned char field095;
    unsigned char field096;
    unsigned char field097;
    unsigned char field098;
    unsigned char field099;
    unsigned char field09a;
    unsigned char field09b;
    unsigned char field09c;
    unsigned char field09d;
    unsigned char field09e;
    unsigned char field09f;
    unsigned char field0a0;
    unsigned char field0a1;
    unsigned char field0a2;
    unsigned char field0a3;
    unsigned char field0a4;
    unsigned char field0a5;
    unsigned char field0a6;
    unsigned char field0a7;
    unsigned char field0a8;
    unsigned char field0a9;
    unsigned char field0aa;
    unsigned char field0ab;
    unsigned char field0ac;
    unsigned char field0ad;
    unsigned char field0ae;
    unsigned char field0af;
    unsigned char field0b0;
    unsigned char field0b1;
    unsigned char field0b2;
    unsigned char field0b3;
    unsigned char field0b4;
    unsigned char field0b5;
    unsigned char field0b6;
    unsigned char field0b7;
    unsigned char field0b8;
    unsigned char field0b9;
    unsigned char field0ba;
    unsigned char field0bb;
    unsigned char field0bc;
    unsigned char field0bd;
    unsigned char field0be;
    unsigned char field0bf;
    unsigned char field0c0;
    unsigned char field0c1;
    unsigned char field0c2;
    unsigned char field0c3;
    unsigned char field0c4;
    unsigned char field0c5;
    unsigned char field0c6;
    unsigned char field0c7;
    unsigned char field0c8;
    unsigned char field0c9;
    unsigned char field0ca;
    unsigned char field0cb;
    unsigned char field0cc;
    unsigned char field0cd;
    unsigned char field0ce;
    unsigned char field0cf;
    unsigned char field0d0;
    unsigned char field0d1;
    unsigned char field0d2;
    unsigned char field0d3;
    unsigned char field0d4;
    unsigned char field0d5;
    unsigned char field0d6;
    unsigned char field0d7;
    unsigned char field0d8;
    unsigned char field0d9;
    unsigned char field0da;
    unsigned char field0db;
    unsigned char field0dc;
    unsigned char field0dd;
    unsigned char field0de;
    unsigned char field0df;
    unsigned char field0e0;
    unsigned char field0e1;
    unsigned char field0e2;
    unsigned char field0e3;
    unsigned char field0e4;
    unsigned char field0e5;
    unsigned char field0e6;
    unsigned char field0e7;
    unsigned char field0e8;
    unsigned char field0e9;
    unsigned char field0ea;
    unsigned char field0eb;
    unsigned char field0ec;
    unsigned char field0ed;
    unsigned char field0ee;
    unsigned char field0ef;
    unsigned char field0f0;
    unsigned char field0f1;
    unsigned char field0f2;
    unsigned char field0f3;
    unsigned char field0f4;
    unsigned char field0f5;
    unsigned char field0f6;
    unsigned char field0f7;
    unsigned char field0f8;
    unsigned char field0f9;
    unsigned char field0fa;
    unsigned char field0fb;
    unsigned char field0fc;
    unsigned char field0fd;
    unsigned char field0fe;
    unsigned char field0ff;
    unsigned char field100;
    unsigned char field101;
    unsigned char field102;
    unsigned char field103;
    unsigned char field104;
    unsigned char field105;
    unsigned char field106;
    unsigned char field107;
    unsigned char field108;
    unsigned char field109;
    unsigned char field10a;
    unsigned char field10b;
    unsigned char field10c;
    unsigned char field10d;
    unsigned char field10e;
    unsigned char field10f;
    unsigned char field110;
    unsigned char field111;
    unsigned char field112;
    unsigned char field113;
    unsigned char field114;
    unsigned char field115;
    unsigned char field116;
    unsigned char field117;
    unsigned char field118;
    unsigned char field119;
    unsigned char field11a;
    unsigned char field11b;
    unsigned char field11c;
    unsigned char field11d;
    unsigned char field11e;
    unsigned char field11f;
    unsigned char field120;
    unsigned char field121;
    unsigned char field122;
    unsigned char field123;
    unsigned char field124;
    unsigned char field125;
    unsigned char field126;
    unsigned char field127;
    unsigned char field128;
    unsigned char field129;
    unsigned char field12a;
    unsigned char field12b;
    unsigned char field12c;
    unsigned char field12d;
    unsigned char field12e;
    unsigned char field12f;
    unsigned char field130;
    unsigned char field131;
    unsigned char field132;
    unsigned char field133;
    unsigned char field134;
    unsigned char field135;
    unsigned char field136;
    unsigned char field137;
    unsigned char field138;
    unsigned char field139;
    unsigned char field13a;
    unsigned char field13b;
    unsigned char field13c;
    unsigned char field13d;
    unsigned char field13e;
    unsigned char field13f;
    unsigned char field140;
    unsigned char field141;
    unsigned char field142;
    unsigned char field143;
    unsigned char field144;
    unsigned char field145;
    unsigned char field146;
    unsigned char field147;
    unsigned char field148;
    unsigned char field149;
    unsigned char field14a;
    unsigned char field14b;
    unsigned char field14c;
    unsigned char field14d;
    unsigned char field14e;
    unsigned char field14f;
    unsigned char field150;
    unsigned char field151;
    unsigned char field152;
    unsigned char field153;
    unsigned char field154;
    unsigned char field155;
    unsigned char field156;
    unsigned char field157;
    unsigned char field158;
    unsigned char field159;
    unsigned char field15a;
    unsigned char field15b;
    unsigned char field15c;
    unsigned char field15d;
    unsigned char field15e;
    unsigned char field15f;
    unsigned char field160;
    unsigned char field161;
    unsigned char field162;
    unsigned char field163;
    unsigned char field164;
    unsigned char field165;
    unsigned char field166;
    unsigned char field167;
    unsigned char field168;
    unsigned char field169;
    unsigned char field16a;
    unsigned char field16b;
    unsigned char field16c;
    unsigned char field16d;
    unsigned char field16e;
    unsigned char field16f;
    unsigned char field170;
    unsigned char field171;
    unsigned char field172;
    unsigned char field173;
    unsigned char field174;
    unsigned char field175;
    unsigned char field176;
    unsigned char field177;
    unsigned char field178;
    unsigned char field179;
    unsigned char field17a;
    unsigned char field17b;
    unsigned char field17c;
    unsigned char field17d;
    unsigned char field17e;
    unsigned char field17f;
    unsigned char field180;
    unsigned char field181;
    unsigned char field182;
    unsigned char field183;
    unsigned char field184;
    unsigned char field185;
    unsigned char field186;
    unsigned char field187;
    unsigned char field188;
    unsigned char field189;
    unsigned char field18a;
    unsigned char field18b;
    unsigned char field18c;
    unsigned char field18d;
    unsigned char field18e;
    unsigned char field18f;
    unsigned char field190;
    unsigned char field191;
    unsigned char field192;
    unsigned char field193;
    unsigned char field194;
    unsigned char field195;
    unsigned char field196;
    unsigned char field197;
    unsigned char field198;
    unsigned char field199;
    unsigned char field19a;
    unsigned char field19b;
    unsigned char field19c;
    unsigned char field19d;
    unsigned char field19e;
    unsigned char field19f;
    unsigned char field1a0;
    unsigned char field1a1;
    unsigned char field1a2;
    unsigned char field1a3;
    unsigned char field1a4;
    unsigned char field1a5;
    unsigned char field1a6;
    unsigned char field1a7;
    unsigned char field1a8;
    unsigned char field1a9;
    unsigned char field1aa;
    unsigned char field1ab;
    unsigned char field1ac;
    unsigned char field1ad;
    unsigned char field1ae;
    unsigned char field1af;
    unsigned char field1b0;
    unsigned char field1b1;
    unsigned char field1b2;
    unsigned char field1b3;
    unsigned char field1b4;
    unsigned char field1b5;
    unsigned char field1b6;
    unsigned char field1b7;
    unsigned char field1b8;
    unsigned char field1b9;
    unsigned char field1ba;
    unsigned char field1bb;
    unsigned char field1bc;
    unsigned char field1bd;
    unsigned char field1be;
    unsigned char field1bf;
    unsigned char field1c0;
    unsigned char field1c1;
    unsigned char field1c2;
    unsigned char field1c3;
    unsigned char field1c4;
    unsigned char field1c5;
    unsigned char field1c6;
    unsigned char field1c7;
    unsigned char field1c8;
    unsigned char field1c9;
    unsigned char field1ca;
    unsigned char field1cb;
    unsigned char field1cc;
    unsigned char field1cd;
    unsigned char field1ce;
    unsigned char field1cf;
    unsigned char field1d0;
    unsigned char field1d1;
    unsigned char field1d2;
    unsigned char field1d3;
    unsigned char field1d4;
    unsigned char field1d5;
    unsigned char field1d6;
    unsigned char field1d7;
    unsigned char field1d8;
    unsigned char field1d9;
    unsigned char field1da;
    unsigned char field1db;
    unsigned char field1dc;
    unsigned char field1dd;
    unsigned char field1de;
    unsigned char field1df;
    unsigned char field1e0;
    unsigned char field1e1;
    unsigned char field1e2;
    unsigned char field1e3;
    unsigned char field1e4;
    unsigned char field1e5;
    unsigned char field1e6;
    unsigned char field1e7;
    unsigned char field1e8;
    unsigned char field1e9;
    unsigned char field1ea;
    unsigned char field1eb;
    unsigned char field1ec;
    unsigned char field1ed;
    unsigned char field1ee;
    unsigned char field1ef;
    unsigned char field1f0;
    unsigned char field1f1;
    unsigned char field1f2;
    unsigned char field1f3;
    unsigned char field1f4;
    unsigned char field1f5;
    unsigned char field1f6;
    unsigned char field1f7;
    unsigned char field1f8;
    unsigned char field1f9;
    unsigned char field1fa;
    unsigned char field1fb;
    unsigned char field1fc;
    unsigned char field1fd;
    unsigned char field1fe;
    unsigned char field1ff;
    unsigned char field200;
    unsigned char field201;
    unsigned char field202;
    unsigned char field203;
    unsigned char field204;
    unsigned char field205;
    unsigned char field206;
    unsigned char field207;
    unsigned char field208;
    unsigned char field209;
    unsigned char field20a;
    unsigned char field20b;
    unsigned char field20c;
    unsigned char field20d;
    unsigned char field20e;
    unsigned char field20f;
    unsigned char field210;
    unsigned char field211;
    unsigned char field212;
    unsigned char field213;
    unsigned char field214;
    unsigned char field215;
    unsigned char field216;
    unsigned char field217;
    unsigned char field218;
    unsigned char field219;
    unsigned char field21a;
    unsigned char field21b;
    unsigned char field21c;
    unsigned char field21d;
    unsigned char field21e;
    unsigned char field21f;
    unsigned char field220;
    unsigned char field221;
    unsigned char field222;
    unsigned char field223;
    unsigned char field224;
    unsigned char field225;
    unsigned char field226;
    unsigned char field227;
    unsigned char field228;
    unsigned char field229;
    unsigned char field22a;
    unsigned char field22b;
    unsigned char field22c;
    unsigned char field22d;
    unsigned char field22e;
    unsigned char field22f;
    unsigned char field230;
    unsigned char field231;
    unsigned char field232;
    unsigned char field233;
    unsigned char field234;
    unsigned char field235;
    unsigned char field236;
    unsigned char field237;
    unsigned char field238;
    unsigned char field239;
    unsigned char field23a;
    unsigned char field23b;
    unsigned char field23c;
    unsigned char field23d;
    unsigned char field23e;
    unsigned char field23f;
    unsigned char field240;
    unsigned char field241;
    unsigned char field242;
    unsigned char field243;
    int field244;
    unsigned char field248;
    bool SetMode(bool);
    FUN_00846f30();
};
// @fnv 0x00846f30
FUN_00846f30::FUN_00846f30() : flag(0), memberB(0x25), field244(0), field248(0xff)
{
    SetMode(false);
    changes = new ChangesMap;
    forms = new SaveMap(0x13af);
    refs = new SaveMap(0x25);
    saves = new SaveTable;
    loads = new LoadTable;
    pointers = new PointerMap(0x25);
    files = new FileMap;
    reconstruct = new ReconstructMap;
    memset(&field044, 0xff, 0xff);
    memset(&field143, 0xff, 0xff);
}

struct Owned008471f0_V
{
    virtual ~Owned008471f0_V();
};
struct Owned008471f0_A
{
    ~Owned008471f0_A();
};
struct Owned008471f0_B
{
    ~Owned008471f0_B();
};
struct Owned008471f0_C
{
    ~Owned008471f0_C();
};
struct Owned008471f0_D
{
    ~Owned008471f0_D();
};
struct Member008471f0_24
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ~Member008471f0_24();
};
struct Member008471f0_34
{
    ~Member008471f0_34();
};

struct FUN_008471f0
{
    Owned008471f0_V* pObj00;
    int unk04;
    Owned008471f0_A* pObj08;
    Owned008471f0_A* pObj0C;
    Owned008471f0_B* pObj10;
    Owned008471f0_C* pObj14;
    Owned008471f0_V* pObj18;
    Owned008471f0_D* pObj1C;
    Owned008471f0_V* pObj20;
    Member008471f0_24 kMember24;
    Member008471f0_34 kMember34;

    ~FUN_008471f0();
};

// Destructor that deletes the eight owned objects held by the struct's pointer members.
// @fnv 0x008471f0
FUN_008471f0::~FUN_008471f0()
{
    delete pObj00;
    delete pObj08;
    delete pObj0C;
    delete pObj10;
    delete pObj14;
    delete pObj18;
    delete pObj1C;
    delete pObj20;
}

namespace fnv_00852740 {
struct FUN_00852740_mgr
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    FUN_00850330_class* m_20;
    unsigned char m_24;
    void(__cdecl* m_28)(int, int);
};

extern FUN_00852740_mgr* DAT_011de134;

// @fnv 0x00852740
void __cdecl FUN_00852740(int a1, int a2)
{
    if (DAT_011de134 != 0)
    {
        DAT_011de134->m_24 = 1;
    }
    if (DAT_011de134->m_20 != 0)
    {
        FUN_00850330_class* src = DAT_011de134->m_20;
        FUN_00850330_class* p = src;
        p != 0 ? p->FUN_00850330(1) : 0;
        DAT_011de134->m_20 = 0;
    }
    if (DAT_011de134 != 0 && DAT_011de134->m_28 != 0)
    {
        DAT_011de134->m_28(a1, a2);
    }
}
}  // namespace fnv_00852740

// Hash map constructor: allocate and clear the bucket table.

void* NiMalloc(unsigned int uiSize);

class FUN_00853370
{
  public:
    FUN_00853370(unsigned int uiHashSize);
    virtual ~FUN_00853370();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

// Initializes a hash table: stores the hash size, zeroes the count, allocates the bucket array with NiMalloc and clears it.
// @fnv 0x00853370
FUN_00853370::FUN_00853370(unsigned int uiHashSize)
{
    m_uiHashSize = uiHashSize;
    m_uiCount = 0;
    unsigned int uiSize = sizeof(void*) * m_uiHashSize;
    m_ppkHashTable = (void**)NiMalloc(uiSize);
    memset(m_ppkHashTable, 0, sizeof(void*) * m_uiHashSize);
}

struct ProbeTarget
{
    int unk00;
    int unk04;

    int Probe(int a, unsigned __int64 key, int* out);
};

unsigned int __cdecl FUN_0044a670(int value);

struct FUN_00856300_cls
{
    int unk00;

    bool FUN_00856300(ProbeTarget* target, int value);
};

// Computes a key from value, calls target->Probe with it, and returns true when Probe returns zero.
// @fnv 0x00856300
bool FUN_00856300_cls::FUN_00856300(ProbeTarget* target, int value)
{
    bool result = false;
    unsigned __int64 key = FUN_0044a670(value);
    int out[3];
    result = !target->Probe(value, key, out);
    return result;
}

class ThreeByThreeMatrix
{
  public:
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
};
class TESWorldSpace : public TESForm
{
};
class Controller
{
  public:
    bool FUN_005c0860();
    void FUN_005620e0(NiPoint3*);
};
class NiUpdateData
{
  public:
    NiUpdateData(float, bool, bool);
    float time;
    bool controllers, multi;
    int flags;
};
class Node
{
  public:
    void FUN_00440460(const NiPoint3&);
    void FUN_0043fa80(const ThreeByThreeMatrix&);
    void FUN_00a59c60(NiUpdateData&);
};
class Extra
{
  public:
    void* GetExtraData(unsigned char);
    TESForm* FUN_0041b320();
};
class RefAccess : public TESObjectREFR
{
  public:
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
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual bool IsMobile();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual NiPoint3 GetRotation();
    virtual NiPoint3 GetPosition();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual NiPoint3* GetWorldPosition();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual bool HasSavedLocation();
    virtual TESWorldSpace* GetSavedWorld();
    virtual TESObjectCELL* GetSavedCell();
    Extra* FUN_005d43c0();
    void SetLocationOnReference(const NiPoint3&);
    void FUN_005757d0(float);
    void FUN_00575700(NiPoint3);
    Node* Get3DSimple();
    ThreeByThreeMatrix FUN_0056fa00();
};
class MobileAccess : public MobileObject
{
  public:
    Controller* FUN_009306d0();
};
void FUN_00573800(RefAccess*, TESObjectCELL*, TESWorldSpace*);
void FUN_00c6bd00(Node*, bool);
class RestoreBuffer
{
  public:
    unsigned char GetVersion();
    void FUN_008a8150(unsigned char);
    void FUN_004534f0(unsigned int);
    bool FUN_00857d10(RefAccess*, bool);
};
// Restores the reference's saved location or extra-data position, updates its 3D and controller, and returns whether anything changed.
// @fnv 0x00857d10
bool RestoreBuffer::FUN_00857d10(RefAccess* ref, bool process)
{
    unsigned char version3 = GetVersion();
    FUN_008a8150(0);
    bool changed = false;
    RefAccess* mobileX = 0;
    if (ref->IsMobile())
        mobileX = ref;
    if (mobileX && mobileX->HasSavedLocation())
    {
        TESObjectCELL* cell6 = mobileX->GetSavedCell();
        TESWorldSpace* world = mobileX->GetSavedWorld();
        if (cell6 || world)
        {
            ref->SetLocationOnReference(mobileX->GetPosition());
            ref->FUN_005757d0(mobileX->GetRotation().z);
            if (process)
                FUN_004534f0(1);
            FUN_00573800(ref, cell6, world);
            if (process)
                FUN_004534f0(0);
            changed = true;
        }
    }
    else if (ref->FUN_005d43c0())
    {
        if (ref->FUN_005d43c0()->GetExtraData(15))
        {
            NiPoint3 position3 = ref->GetPosition();
            NiPoint3 rotation = ref->GetRotation();
            ref->SetLocationOnReference(position3);
            ref->FUN_00575700(rotation);
            changed = true;
        }
        TESForm* form7 = ref->FUN_005d43c0()->FUN_0041b320();
        if (form7)
        {
            TESObjectCELL* savedCell7 = dynamic_cast<TESObjectCELL*>(form7);
            TESWorldSpace* savedWorld6 = dynamic_cast<TESWorldSpace*>(form7);
            if (savedCell7 || savedWorld6)
            {
                FUN_00573800(ref, savedCell7, savedWorld6);
                changed = true;
            }
        }
    }
    if (changed)
    {
        Node* node6 = ref->Get3DSimple();
        if (node6)
        {
            NiPoint3 location9 = *ref->GetWorldPosition();
            MobileObject* objectA = dynamic_cast<MobileObject*>((TESObjectREFR*)ref);
            if (objectA)
            {
                Controller* controller = ((MobileAccess*)objectA)->FUN_009306d0();
                if (controller && !controller->FUN_005c0860())
                    controller->FUN_005620e0(&location9);
            }
            node6->FUN_00440460(location9);
            node6->FUN_0043fa80(ref->FUN_0056fa00());
            FUN_00c6bd00(node6, true);
            NiUpdateData update6(0.0f, false, false);
            node6->FUN_00a59c60(update6);
        }
    }
    FUN_008a8150(version3);
    return changed;
}

struct Entry859
{
    unsigned key;
    int x;
    int y;
};
struct List859
{
    Entry859** FUN_006815c0();
    List859* FUN_00726070();
    void FUN_00470470();
    void FUN_00905330(Entry859* const&);
    void FUN_0063f7b0();
    bool FUN_008256d0();
    ~List859();
};
struct Map859
{
    bool GetAt(unsigned, List859*&);
    bool RemoveKey(unsigned);
};
struct Cell859
{
    bool FUN_00425fd0();
    unsigned FUN_0084e3a0();
    Cell859* FUN_0054ddd0();
    int FUN_00544c30();
    int FUN_00544c60();
};
struct Manager859
{
    unsigned field00, field04;
    Map859* interiors;
    Map859* worlds;
    bool FUN_0047c850();
    bool FUN_00858730(Cell859*);
    void ProcessSourceItem(unsigned);
    bool FUN_00859690(Cell859* cell);
};
// @fnv 0x00859690
bool Manager859::FUN_00859690(Cell859* cell)
{
    bool result5 = false;
    if (!FUN_0047c850())
        return result5;
    result5 = FUN_00858730(cell);
    if (cell->FUN_00425fd0())
    {
        List859* list8;
        bool found8 = interiors->GetAt(cell->FUN_0084e3a0(), list8);
        if (!found8)
            return result5;
        List859* node2 = list8;
        while (node2)
        {
            Entry859* entry7 = *node2->FUN_006815c0();
            if (entry7)
            {
                ProcessSourceItem((unsigned)entry7);
                result5 = true;
            }
            node2 = node2->FUN_00726070();
        }
        interiors->RemoveKey(cell->FUN_0084e3a0());
        list8->FUN_00470470();
        delete list8;
    }
    else
    {
        List859* listExterior;
        bool foundExterior = worlds->GetAt(cell->FUN_0054ddd0()->FUN_0084e3a0(), listExterior);
        if (!foundExterior)
            return result5;
        List859* nodeExterior8 = listExterior;
        List859* _previous = 0;
        int x7 = cell->FUN_00544c30();
        int y7 = cell->FUN_00544c60();
        while (nodeExterior8)
        {
            Entry859* entryExterior2 = *nodeExterior8->FUN_006815c0();
            if (entryExterior2 && x7 == entryExterior2->x && y7 == entryExterior2->y)
            {
                ProcessSourceItem(entryExterior2->key);
                result5 = true;
                if (_previous)
                {
                    _previous->FUN_00905330(entryExterior2);
                    nodeExterior8 = _previous->FUN_00726070();
                }
                else
                    nodeExterior8->FUN_0063f7b0();
                delete entryExterior2;
            }
            else
            {
                _previous = nodeExterior8;
                nodeExterior8 = nodeExterior8->FUN_00726070();
            }
        }
        if (listExterior->FUN_008256d0())
        {
            worlds->RemoveKey(cell->FUN_0054ddd0()->FUN_0084e3a0());
            delete listExterior;
        }
    }
    return result5;
}

struct RestoreVector
{
    float x, y, z;
};
struct RestoredObject;
struct RestoreAction
{
    unsigned int x, y, z;
    void SetPositionExtraData();
    void SetStartingPosition();
};
struct RestoredObject
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
    virtual void Reset();
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
    virtual void slot3a();
    virtual void slot3b();
    virtual void slot3c();
    virtual void slot3d();
    virtual void slot3e();
    virtual void slot3f();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot4a();
    virtual void slot4b();
    virtual void slot4c();
    virtual void slot4d();
    virtual void slot4e();
    virtual void slot4f();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot5a();
    virtual void slot5b();
    virtual void slot5c();
    virtual void slot5d();
    virtual void slot5e();
    virtual void slot5f();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot6a();
    virtual void slot6b();
    virtual void slot6c();
    virtual void slot6d();
    virtual void slot6e();
    virtual void slot6f();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot7a();
    virtual void slot7b();
    virtual void slot7c();
    virtual RestoreVector* Position();
    RestoreVector* FUN_00430830();
    RestoreAction FUN_005d43c0(RestoredObject*, RestoreVector);
};
struct RestoreForm;
struct RestoreRef
{
    bool FUN_004734d0(RestoreForm*);
    unsigned int FUN_00472660();
};
struct RestoreLink
{
    RestoreRef* FUN_004739b0();
};
struct RestoreForm
{
    int GetSourceFileCount();
    RestoreLink* FUN_00484e60(int);
    bool SeekToCellInWorld(RestoreRef*, int, int);
};
struct RestoredActor
{
    void SetPlacement(RestoreForm*, RestoreForm*, RestoreVector*, float);
};
struct RestoreLocation
{
    unsigned int id;
    float x, y;
    unsigned int unk0c, alternate;
};
extern char DAT_01183028, DAT_01183fb4, DAT_01183fd0, DAT_011841cc, DAT_011846d4;
extern const char DAT_01080958[], DAT_01080900[];
extern void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);

extern bool __cdecl HasFormInGroup(RestoreRef*, unsigned int);
extern RestoredObject* __cdecl FUN_00564480(unsigned char, int);
extern void __cdecl FUN_004601d0(RestoredObject*, RestoreRef*);
extern int __cdecl FUN_00406d90(float);
extern void __cdecl FUN_005b5e40(const char*, ...);
struct ObjectRestorer
{
    RestoredObject* FUN_00859f20(unsigned int, RestoreLocation*);
};
// @fnv 0x00859f20
RestoredObject* ObjectRestorer::FUN_00859f20(unsigned int id, RestoreLocation* location)
{
    RestoredObject* object5 = 0;
    unsigned int parent = location->id;
    if (!parent)
        parent = location->alternate;
    void* form2 = LookupFormByID(parent);
    RestoreForm* cellTmp = (RestoreForm*)FUN_00ec43fb(form2, 0, &DAT_01183028, &DAT_01183fb4, 0);
    RestoreForm* world = (RestoreForm*)FUN_00ec43fb(form2, 0, &DAT_01183028, &DAT_01183fd0, 0);
    int x6 = 0, y4 = 0;
    int count9;
    int i;
    if (cellTmp)
    {
        count9 = cellTmp->GetSourceFileCount();
        for (i = 0; i < count9; ++i)
        {
            RestoreRef* reference = cellTmp->FUN_00484e60(i)->FUN_004739b0();
            if (reference->FUN_004734d0(cellTmp) && HasFormInGroup(reference, id))
            {
                unsigned int type = reference->FUN_00472660();
                object5 = FUN_00564480((unsigned char)type, 1);
                FUN_004601d0(object5, reference);
            }
        }
    }
    else if (world)
    {
        count9 = world->GetSourceFileCount();
        x6 = FUN_00406d90(location->x) >> 12;
        y4 = FUN_00406d90(location->y) >> 12;
        for (i = 0; i < count9; ++i)
        {
            RestoreRef* reference = world->FUN_00484e60(i)->FUN_004739b0();
            if (world->SeekToCellInWorld(reference, x6, y4) && HasFormInGroup(reference, id))
            {
                unsigned int type = reference->FUN_00472660();
                object5 = FUN_00564480((unsigned char)type, 1);
                FUN_004601d0(object5, reference);
            }
        }
    }
    else
    {
        FUN_005b5e40(DAT_01080958);
    }
    if (!object5)
    {
        FUN_005b5e40(DAT_01080900, id, parent, x6, y4);
        return 0;
    }
    object5->Reset();
    RestoredActor* actor = (RestoredActor*)FUN_00ec43fb(object5, 0, &DAT_011841cc, &DAT_011846d4, 0);
    if (actor)
        actor->SetPlacement(world, cellTmp, object5->Position(), object5->FUN_00430830()->z);
    else
    {
        object5->FUN_005d43c0(object5, *object5->Position()).SetPositionExtraData();
        object5->FUN_005d43c0(object5, *object5->FUN_00430830()).SetStartingPosition();
    }
    return object5;
}

void* memset(void* dst, int val, unsigned int size);

struct FileTimeStamp
{
    unsigned int low;
    unsigned int high;
};

// Win32 WIN32_FIND_DATAA layout
struct FileFindData
{
    unsigned int dwFileAttributes;
    FileTimeStamp ftCreationTime;
    FileTimeStamp ftLastAccessTime;
    FileTimeStamp ftLastWriteTime;
    unsigned int nFileSizeHigh;
    unsigned int nFileSizeLow;
    unsigned int dwReserved0;
    unsigned int dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
};

extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char* fileName, FileFindData* findData);
extern "C" __declspec(dllimport) int __stdcall FindClose(void* findFile);

struct TimedFile
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual const char* GetPath();
    FileTimeStamp* GetCachedTime(FileTimeStamp* out);
    void SetCachedTime(FileTimeStamp time);
    unsigned char HasCachedTime();
};

// Compares the cached last-write timestamps of two files, querying the filesystem when uncached, and returns -1, 1 or 0.
// @fnv 0x0085fc90
int CompareFileWriteTimes(TimedFile* apFirstFile, TimedFile* apSecondFile)
{
    FileTimeStamp firstTime9;
    memset(&firstTime9, 0, sizeof(firstTime9));
    FileTimeStamp secondTime;
    memset(&secondTime, 0, sizeof(secondTime));
    FileFindData kFindData;
    void* findHandle;

    if (apFirstFile->HasCachedTime())
    {
        FileTimeStamp tmp1;
        firstTime9 = *apFirstFile->GetCachedTime(&tmp1);
    }
    else
    {
        findHandle = FindFirstFileA(apFirstFile->GetPath(), &kFindData);
        if (findHandle != (void*)-1)
            firstTime9 = kFindData.ftLastWriteTime;
        FindClose(findHandle);
        apFirstFile->SetCachedTime(firstTime9);
    }

    if (apSecondFile->HasCachedTime())
    {
        FileTimeStamp tmp4;
        secondTime = *apSecondFile->GetCachedTime(&tmp4);
    }
    else
    {
        findHandle = FindFirstFileA(apSecondFile->GetPath(), &kFindData);
        if (findHandle != (void*)-1)
            secondTime = kFindData.ftLastWriteTime;
        FindClose(findHandle);
        apSecondFile->SetCachedTime(secondTime);
    }

    if (firstTime9.high > secondTime.high)
        return -1;
    else if (firstTime9.high < secondTime.high)
        return 1;
    return firstTime9.low > secondTime.low ? -1 : firstTime9.low < secondTime.low;
}

struct FUN_00846a20_base
{
    void UpdateFileWriteTime();
};

struct FUN_008465b0_stub : FUN_00846a20_base
{
    FUN_008465b0_stub(const char* name, int flag);
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
};

struct FUN_00851680_class
{
    BSSimpleList<FUN_00846a20_base*>* unk00;
    int unk04;
    void AddFileToList(const char* path, int flag, int unused);
};

int __cdecl strcpy_s(char* dst, unsigned int size, const char* src);
int __cdecl _stricmp(const char* a, const char* b);

// @fnv 0x00851680
void FUN_00851680_class::AddFileToList(const char* path, int flag, int unused)
{
    char buf[260];
    strcpy_s(buf, 260, path);
    unsigned int n = (unsigned int)BSStringLength(buf);
    if (n > 4)
    {
        if (_stricmp(buf + n - 4, ".fos") == 0)
        {
            buf[n - 4] = 0;
        }
    }
    FUN_00846a20_base* item5 = new FUN_008465b0_stub(buf, flag);
    item5->UpdateFileWriteTime();
    unk00->AddHead(item5);
    unk04++;
}

struct FUN_00854d50_Base
{
    virtual ~FUN_00854d50_Base();
};

struct FUN_00854d50 : FUN_00854d50_Base
{
    virtual ~FUN_00854d50();
};

// Destructor that clears all entries from the underlying NiTPointerMap before destruction.
// @fnv 0x00854d50
FUN_00854d50::~FUN_00854d50()
{
    ((NiTPointerMap<int, int>*)this)->RemoveAll();
}

struct FUN_00858aa0_shell
{
    void* FUN_00858aa0(unsigned short*, unsigned int, unsigned int);
};
// Stores b and c into the object and copies bytes from a into offsets 4, 9 and 10, returning this.
// @fnv 0x00858aa0
void* FUN_00858aa0_shell::FUN_00858aa0(unsigned short* a, unsigned int b, unsigned int c)
{
    *(unsigned int*)this = b;
    *(unsigned int*)((char*)this + 5) = c;
    *(unsigned char*)((char*)this + 4) = ((unsigned char*)a)[2];
    *(unsigned char*)((char*)this + 9) = ((unsigned char*)a)[3];
    *(unsigned short*)((char*)this + 10) = *(unsigned short*)a;
    return this;
}

struct StQ
{
    FnvQueue* pQ0;
    FnvQueue* pQ4;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44,
        unk48, unk4c, unk50, unk54, unk58;
    FnvMap* pMap;
    void FUN_0085f3d0(TESObjectREFR* pRef_zaxvzc, void* pData_zbax);
    void FUN_0085f2e0();
};
// @fnv 0x0085f2e0
void StQ::FUN_0085f2e0()
{
    void* pIterator = pMap->FUN_004b9ba0();
    while (pIterator)
    {
        unsigned int uiID;
        void* pData_zbax;
        pMap->FUN_006b7f20(pIterator, uiID, pData_zbax);
        TESObjectREFR* pRef_zaxvzc = dynamic_cast<TESObjectREFR*>(LookupFormByID(uiID));
        if (pRef_zaxvzc)
        {
            if (!((FnvRefMethod*)pRef_zaxvzc)->FUN_0043fcd0())
            {
                if (pQ4)
                    pQ4->GetOrCreateNode(pRef_zaxvzc, 0);
                else
                    pQ0->GetOrCreateNode(pRef_zaxvzc, 0);
                pMap->RemoveKey(uiID);
                continue;
            }
            FUN_0085f3d0(pRef_zaxvzc, pData_zbax);
        }
        FormHeap_Free(pData_zbax);
        pMap->RemoveKey(uiID);
    }
}

struct Key64
{
    int lo;
    int hi;
};

struct MapItem
{
    MapItem* m_pNext;
    int m_04;
    Key64 m_key;
    int m_val;
};

class Map64
{
  public:
    virtual void Slot0();
    virtual unsigned int KeyToHashIndex(Key64 key);
    virtual bool IsKeysEqual(Key64 a, Key64 b);
    int m_04;
    MapItem** m_ppHashTable;
    bool FUN_0084b8b0(Key64 key, int* val);
};

// Looks up key in the hash table and writes the matching item's m_val into *val, returning true when found.
// @fnv 0x0084b8b0
bool Map64::FUN_0084b8b0(Key64 key, int* val)
{
    unsigned int idx = KeyToHashIndex(key);
    MapItem* item = m_ppHashTable[idx];
    while (item)
    {
        if (IsKeysEqual(key, item->m_key))
        {
            *val = item->m_val;
            return true;
        }
        item = item->m_pNext;
    }
    return false;
}

class TESBoundObject : public TESForm
{
};

namespace s85ac30 {

enum
{
    kChange_Move = 0,
    kChange_Position = 6,
    kChange_Cell = 0,
    kChange_Persistent = 0
};

struct CellView
{
    bool FUN_00425fd0();
    void FUN_0054ca90(TESObjectREFR* pkRef);
};

struct WorldView
{
    TESObjectCELL* FUN_005875a0(int iX, int iY);
};

class RefView
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
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void Update3D(int iArg0, int iArg1);
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void SetParentCell(TESObjectCELL* pkCell);

    void FUN_00575700(NiPoint3 kAngle);
    void FUN_00575830(const NiPoint3& kPos);
    TESObjectCELL* FUN_008d6f30();
    bool FUN_005653d0();
};

struct MoveRecord
{
    int m_iType;
    unsigned int m_uiBaseID;
    unsigned int m_uiCellID;
    NiPoint3 m_kPos;
    NiPoint3 m_kAngle;

    MoveRecord();
};

struct PositionRecord
{
    unsigned int m_uiCellID;
    NiPoint3 m_kPos;
    NiPoint3 m_kAngle;

    PositionRecord();
};

struct FullPositionRecord
{
    unsigned int m_uiID;
    int unk04;
    int unk08;
    int unk0c;
    PositionRecord m_kPathOffset;

    FullPositionRecord();
};

struct SaveGame
{
    unsigned char FUN_008df040();
    void FUN_008579e0(void* pvBuffer, unsigned int uiSize);
};

struct DataHandler
{
    void PlaceObjectReference(TESBoundObject* pkBase, NiPoint3* pkPos, NiPoint3* pkAngle, TESObjectCELL* pkCell,
                              TESWorldSpace* pkWorld, TESObjectREFR* pkRef, int iArg0, int iArg1);
};

struct ProcessLists
{
    void FUN_00445570(TESObjectREFR* pkRef);
};

extern SaveGame* DAT_011de45c;
extern DataHandler* DAT_011c3f2c;
extern ProcessLists* DAT_011c3b3c;
extern TESObjectREFR* DAT_011dea3c;

int FUN_00406d90(float fValue);
void FUN_00573800(TESObjectREFR* pkRef, TESObjectCELL* pkCell, TESWorldSpace* pkWorld);
void FUN_005b5e40(const char* pcFormat, ...);

struct RefLoader
{
    void FUN_00857bd0(unsigned int uiState);
    unsigned int FUN_00861c00(unsigned int uiID);
    void FUN_008624e0(TESObjectREFR* pkRef);
    void LoadChange(TESForm* pkForm, unsigned int uiChangeFlags);
};

// Applies a saved change record to a form, handling move, position, and cell updates via the save game stream and data handler.
// @fnv 0x0085ac30
void RefLoader::LoadChange(TESForm* pkForm, unsigned int uiChangeFlags)
{
    TESObjectREFR* pkRef = dynamic_cast<TESObjectREFR*>(pkForm);
    if (!pkRef)
    {
        TESObjectCELL* pkCellForm = dynamic_cast<TESObjectCELL*>(pkForm);
        if (pkCellForm)
        {
            if (DAT_011de45c->FUN_008df040() >= 0x5b)
            {
                if (uiChangeFlags & kChange_Move)
                    FUN_00857bd0(4);
                else if (uiChangeFlags & kChange_Cell)
                    FUN_00857bd0(6);
            }
            if (DAT_011de45c->FUN_008df040() < 0x5b)
            {
                if ((uiChangeFlags & kChange_Move) && (uiChangeFlags & kChange_Cell))
                    FUN_00857bd0(0xc);
                else
                    FUN_00857bd0(2);
            }
        }
    }
    else if (uiChangeFlags & kChange_Move)
    {
        MoveRecord kMoveData;
        DAT_011de45c->FUN_008579e0(&kMoveData, 0x24);
        kMoveData.m_uiBaseID = FUN_00861c00(kMoveData.m_uiBaseID);
        kMoveData.m_uiCellID = FUN_00861c00(kMoveData.m_uiCellID);
        TESForm* pkLocation = LookupFormByID(kMoveData.m_uiCellID);
        TESObjectCELL* pkCell = dynamic_cast<TESObjectCELL*>(pkLocation);
        TESWorldSpace* pkWorld = dynamic_cast<TESWorldSpace*>(pkLocation);
        if (kMoveData.m_iType != 2)
        {
            TESBoundObject* pkBase = dynamic_cast<TESBoundObject*>(LookupFormByID(kMoveData.m_uiBaseID));
            DAT_011c3f2c->PlaceObjectReference(pkBase, &kMoveData.m_kPos, &kMoveData.m_kAngle, pkCell, pkWorld, pkRef,
                                               0, 0);
            FUN_008624e0(pkRef);
        }
        else
        {
            if (pkWorld)
            {
                int iX = FUN_00406d90(kMoveData.m_kPos.x) >> 12;
                int iY = FUN_00406d90(kMoveData.m_kPos.y) >> 12;
                pkCell = ((WorldView*)pkWorld)->FUN_005875a0(iX, iY);
            }
            if (pkCell)
                ((RefView*)pkRef)->SetParentCell(pkCell);
            ((RefView*)pkRef)->FUN_00575830(kMoveData.m_kPos);
            ((RefView*)pkRef)->FUN_00575700(kMoveData.m_kAngle);
            FUN_008624e0(pkRef);
        }
    }
    else if (uiChangeFlags & kChange_Position)
    {
        PositionRecord kPosition;
        if (uiChangeFlags & kChange_Persistent)
        {
            FullPositionRecord kFull;
            DAT_011de45c->FUN_008579e0(&kFull, 0x2c);
            kFull.m_uiID = FUN_00861c00(kFull.m_uiID);
            kFull.m_kPathOffset.m_uiCellID = FUN_00861c00(kFull.m_kPathOffset.m_uiCellID);
            kPosition = kFull.m_kPathOffset;
        }
        else
        {
            DAT_011de45c->FUN_008579e0(&kPosition, 0x1c);
            kPosition.m_uiCellID = FUN_00861c00(kPosition.m_uiCellID);
        }
        ((RefView*)pkRef)->FUN_00575700(kPosition.m_kAngle);
        if (pkRef != DAT_011dea3c)
        {
            ((RefView*)pkRef)->FUN_00575830(kPosition.m_kPos);
            FUN_008624e0(pkRef);
            TESForm* pkLocation = LookupFormByID(kPosition.m_uiCellID);
            TESObjectCELL* pkCell2 = dynamic_cast<TESObjectCELL*>(pkLocation);
            TESWorldSpace* pkWorld2 = dynamic_cast<TESWorldSpace*>(pkLocation);
            if (pkCell2)
            {
                if (pkCell2 != ((RefView*)pkRef)->FUN_008d6f30())
                    FUN_00573800(pkRef, pkCell2, 0);
            }
            else if (pkWorld2)
            {
                int iCellX2 = FUN_00406d90(kPosition.m_kPos.x) >> 12;
                int iCellY2 = FUN_00406d90(kPosition.m_kPos.y) >> 12;
                pkCell2 = ((WorldView*)pkWorld2)->FUN_005875a0(iCellX2, iCellY2);
                if ((((RefView*)pkRef)->FUN_008d6f30() &&
                     ((CellView*)((RefView*)pkRef)->FUN_008d6f30())->FUN_00425fd0()) ||
                    ((RefView*)pkRef)->FUN_008d6f30() != pkCell2)
                    FUN_00573800(pkRef, 0, pkWorld2);
                else if (!pkCell2 && !((RefView*)pkRef)->FUN_005653d0())
                    FUN_005b5e40("SAVELOAD: Trying to load non-persistent ref into non-existent cell.");
            }
            else
            {
                if (!((RefView*)pkRef)->FUN_005653d0())
                {
                    FUN_005b5e40("SAVELOAD: Trying to put non-persistent reference in non-existent cell.");
                }
                else
                {
                    if (((RefView*)pkRef)->FUN_008d6f30())
                        ((CellView*)((RefView*)pkRef)->FUN_008d6f30())->FUN_0054ca90(pkRef);
                    ((RefView*)pkRef)->SetParentCell(0);
                    DAT_011c3b3c->FUN_00445570(pkRef);
                    ((RefView*)pkRef)->Update3D(0, 1);
                }
            }
        }
    }
    else if (uiChangeFlags & kChange_Move)
    {
        FUN_00857bd0(4);
    }
}

}

struct FUN_0084fda0_SubObj
{
    void Init();
};

struct FUN_0084fda0_cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned char m_0c;
    unsigned char m_0d;
    unsigned char m_0e;
    unsigned char m_0f;
    unsigned char m_10;
    unsigned char m_11;
    unsigned int m_14;
    int m_18;
    unsigned char m_1c;
    unsigned int m_20;
    unsigned char m_24;
    unsigned char m_25;
    unsigned char m_26;
    unsigned int m_28;
    unsigned int m_2c;
    FUN_0084fda0_SubObj m_30;
    FUN_0084fda0_cls* __thiscall FUN_0084fda0();
};

// Zeroes all members of FUN_0084fda0_cls, sets m_18 to -1 and m_24 to 1, calls m_30.Init(), and returns this.
// @fnv 0x0084fda0
FUN_0084fda0_cls* FUN_0084fda0_cls::FUN_0084fda0()
{
    m_00 = 0;
    m_04 = 0;
    m_08 = 0;
    m_0c = 0;
    m_0d = 0;
    m_0e = 0;
    m_0f = 0;
    m_10 = 0;
    m_11 = 0;
    m_14 = 0;
    m_18 = -1;
    m_1c = 0;
    m_20 = 0;
    m_24 = 1;
    m_25 = 0;
    m_26 = 0;
    m_28 = 0;
    m_2c = 0;
    m_30.Init();
    return this;
}

namespace fnv_008527d0 {
class B8527D0FileSystem
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual unsigned int CountFiles(const char* pcPattern, int iA, int iB);
};

struct B8527D0Settings
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned char m_ucHasSaves;
};

extern B8527D0Settings* g_pkB8527D0Settings;

// Queries the file system for files matching "-SAVE-" and stores whether any exist in g_pkB8527D0Settings->m_ucHasSaves.
// @fnv 0x008527d0
void UpdateHasSaves()
{
    B8527D0FileSystem* pkFileSystem = static_cast<B8527D0FileSystem*>(FUN_00af2e50());
    g_pkB8527D0Settings->m_ucHasSaves = pkFileSystem->CountFiles("-SAVE-", 0, 0) > 0;
}
}  // namespace fnv_008527d0

struct FUN_008531b0_base
{
    virtual void v00();
    ~FUN_008531b0_base();
};

class FUN_008531b0_cls : public FUN_008531b0_base
{
  public:
    void Body();

    virtual ~FUN_008531b0_cls();
};

// Calls Body() and then invokes the base class destructor.
// @fnv 0x008531b0
FUN_008531b0_cls::~FUN_008531b0_cls()
{
    Body();
}

class C8532E0MapBase
{
  public:
    virtual ~C8532E0MapBase();

    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_008532e0 : public C8532E0MapBase
{
  public:
    virtual ~FUN_008532e0();
};

// Destructor: calls RemoveAll.
// @fnv 0x008532e0
FUN_008532e0::~FUN_008532e0()
{
    RemoveAll();
}

extern int DAT_010800c8;
struct FUN_00853440_shell : NiTPointerMap<int, int>
{
    void FUN_00853440();
};
// Sets the vtable pointer to DAT_010800c8, clears the map with RemoveAll, and frees the internal pointer at offset 8.
// @fnv 0x00853440
void FUN_00853440_shell::FUN_00853440()
{
    *(int*)this = (int)&DAT_010800c8;
    RemoveAll();
    NiFree(*(void**)((char*)this + 8));
}

struct FUN_0085fed0_Object
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual char* GetName();
};

struct StartMenu
{
    char const* GetMenuTitle();
};

struct GlobalObject_0040c150 : public StartMenu
{
};

struct FUN_0085fed0_Class
{
    bool ParseSaveName(FUN_0085fed0_Object* object, int value, char const* suffix, unsigned int flag);
    void ReadSaveMetadata(FUN_0085fed0_Object* object, int value, int unused1, char const* suffix, int unused2,
                          int FlushUsageData, int unused4, unsigned int flag, int unused5, int unused6);
    void FUN_0085fed0(FUN_0085fed0_Object* object, int value, char* buffer, char const* suffix, unsigned int flag);
};

char* __cdecl FUN_0040ab30(char*, int);
char* __cdecl FUN_004812f0(char const*, char const*);
unsigned int __cdecl _BSStringLength(char const*);
int __cdecl __strnicmp(char const*, char const*, unsigned int);

extern char const $SG3295[];
extern char const _g_quicksaveName[];
extern char const DAT_0107fae0[];
extern char const str_010806a8[];
extern char const str_01081aa8[];
extern GlobalObject_0040c150 g_011d327c;
extern GlobalObject_0040c150 g_011d3ed4;

// After ParseSaveName and ReadSaveMetadata, fills buffer with a menu title plus suffix for two special save names, else the file name with its last 4 chars cut.
// @fnv 0x0085fed0
void FUN_0085fed0_Class::FUN_0085fed0(FUN_0085fed0_Object* object, int value, char* buffer, char const* suffix,
                                      unsigned int flag)
{
    if (buffer)
        TaskQueueInterface::CopyStringToBuffer(buffer, 0xff, $SG3295);

    if (ParseSaveName(object, value, suffix, flag))
        return;

    ReadSaveMetadata(object, value, 0, suffix, 0, 0, 0, flag, 0, 0);

    if (buffer)
    {
        if (FUN_004812f0(object->GetName(), _g_quicksaveName))
        {
            TaskQueueInterface::CopyStringToBuffer(buffer, 0xff, g_011d327c.GetMenuTitle());
            strcat_s(buffer, 0xff, str_01081aa8);
            strcat_s(buffer, 0xff, suffix);
        }
        else if (FUN_004812f0(object->GetName(), DAT_0107fae0))
        {
            TaskQueueInterface::CopyStringToBuffer(buffer, 0xff, g_011d3ed4.GetMenuTitle());
            strcat_s(buffer, 0xff, str_01081aa8);
            strcat_s(buffer, 0xff, suffix);
        }
        else
        {
            bool isSave = false;
            char* name = FUN_0040ab30(object->GetName(), 0x5c) + 1;

            if (__strnicmp(name, str_010806a8, 5))
                isSave = true;

            if (isSave)
            {
                TaskQueueInterface::CopyStringToBuffer(buffer, 0xff, name);
                unsigned int length = _BSStringLength(buffer);

                if (length > 4)
                    buffer[length - 4] = 0;

                if (length > 0x12)
                    buffer[0x12] = 0;
            }
        }
    }
}

namespace fnv_0084fd30 {
struct FUN_0084fd70_cls
{
    int unk00;
    int DestroyAndFree(int flag);
};

struct FUN_0084fd30_cls
{
    int unk00;
    FUN_0084fd70_cls* m_04;
};

extern FUN_0084fd30_cls* DAT_011de134;

// Calls FUN_0084fd70(1) on the global DAT_011de134 object if it is not null, then nulls the global pointer.
// @fnv 0x0084fd30
void FUN_0084fd30()
{
    FUN_0084fd30_cls* tmp = DAT_011de134;
    FUN_0084fd30_cls* obj2 = tmp;
    int result;
    if (obj2 != 0)
    {
        result = reinterpret_cast<FUN_0084fd70_cls*>(obj2)->DestroyAndFree(1);
    }
    else
    {
        result = 0;
    }
    DAT_011de134 = 0;
}
}  // namespace fnv_0084fd30

// Members the file's BaseProcess/HighProcess do not declare yet: vtable slot 163 (int) and FUN_00926690.
class CharControllerProcess : public BaseProcess
{
  public:
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
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual int GetPhysicsCharacterController();
    void FUN_00926690(MobileObject*);
};
// Members the file's MobileObject does not declare yet: vtable slot 76 (name), FUN_00440d80, FUN_00440da0.
class CharControllerMob : public MobileObject
{
  public:
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
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual const char* GetName();
    bool FUN_00440d80();
    bool FUN_00440da0();
};
// Iterates the m_60 FnvMap, resolves each key to a MobileObject, and loads its physics character controller via the HighProcess.
// @fnv 0x0085f450
void FUN_0085f450_class::FUN_0085f450()
{
    void* pos = ((FnvMap*)((FUN_0085f5a0_Class*)this)->m_60)->FUN_004b9ba0();
    while (pos)
    {
        unsigned int data;
        void* object;
        ((FnvMap*)((FUN_0085f5a0_Class*)this)->m_60)->FUN_006b7f20(pos, data, object);
        MobileObject* id = dynamic_cast<MobileObject*>(LookupFormByID(data));
        if (id)
        {
            HighProcess* process = dynamic_cast<HighProcess*>(id->FUN_008d8520());
            if (process)
            {
                int saved = ((FUN_0085f5a0_Class*)this)->m_14;
                ((FUN_0085f5a0_Class*)this)->m_14 = (int)object;
                int mode;
                ((SaveManagerAccess*)DAT_011de45c)->FUN_008579e0(&mode, 2);
                if (((CharControllerProcess*)process)->GetPhysicsCharacterController())
                    ((CharControllerProcess*)process)->FUN_00926690(id);
                else if (!((CharControllerMob*)id)->FUN_00440d80() || !((CharControllerMob*)id)->FUN_00440da0())
                {
                    FUN_005b5e40(
                        "SAVELOAD: (LoadCharControllers()) Mob %s %08X does not have a character controller to load.",
                        ((CharControllerMob*)id)->GetName(), ((FUN_0084e3a0_Class*)id)->FUN_0084e3a0());
                }
                ((FUN_0085f5a0_Class*)this)->m_14 = saved;
            }
        }
        Deallocate(object);
        ((FnvMap*)((FUN_0085f5a0_Class*)this)->m_60)->RemoveKey(data);
    }
}

struct VObj
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
    virtual void Enter(int a, int b);
    virtual void Leave(int a, int b);
    virtual void w1c();
    virtual void w1d();
    virtual void w1e();
    virtual void w1f();
    virtual void w20();
    virtual void w21();
    virtual void w22();
    virtual void w23();
    virtual void w24();
    virtual void w25();
    virtual void w26();
    virtual void w27();
    virtual void w28();
    virtual void w29();
    virtual void w2a();
    virtual void w2b();
    virtual void w2c();
    virtual void w2d();
    virtual void w2e();
    virtual void w2f();
    virtual void w30();
    virtual void w31();
    virtual void w32();
    virtual void w33();
    virtual void w34();
    virtual void w35();
    virtual void w36();
    virtual void w37();
    virtual void w38();
    virtual void w39();
    virtual void w3a();
    virtual void w3b();
    virtual void w3c();
    virtual void w3d();
    virtual void w3e();
    virtual void w3f();
    virtual void w40();
    virtual void w41();
    virtual void w42();
    virtual void w43();
    virtual void w44();
    virtual void w45();
    virtual void w46();
    virtual void w47();
    virtual void w48();
    virtual void w49();
    virtual void w4a();
    virtual void w4b();
    virtual void w4c();
    virtual void w4d();
    virtual void w4e();
    virtual void w4f();
    virtual void w50();
    virtual void w51();
    virtual void w52();
    virtual void w53();
    virtual void w54();
    virtual void w55();
    virtual void w56();
    virtual void w57();
    virtual void w58();
    virtual void w59();
    virtual void w5a();
    virtual void w5b();
    virtual void w5c();
    virtual void w5d();
    virtual void w5e();
    virtual void w5f();
    virtual void w60();
    virtual void w61();
    virtual void w62();
    virtual void w63();
    virtual void w64();
    virtual void w65();
    virtual void w66();
    virtual void w67();
    virtual void w68();
    virtual void w69();
    virtual void w6a();
    virtual void w6b();
    virtual void w6c();
    virtual void w6d();
    virtual void w6e();
    virtual void w6f();
    virtual void w70();
    virtual void w71();
    virtual void w72();
    virtual void w73();
    virtual void w74();
    virtual void w75();
    virtual void w76();
    virtual void w77();
    virtual void w78();
    virtual void w79();
    virtual void w7a();
    virtual void w7b();
    virtual void w7c();
    virtual NiPoint3* GetPos();
    int FUN_00950bb0(int);
};
class Actor : public TESForm
{
  public:
    int FUN_008d6f30();
    int FUN_00575d70();
    void FUN_00893340(int);
    void FUN_00575830(NiPoint3*);
    void FUN_00575700(NiPoint3);
    void FUN_00484af0(int);
    void FUN_00483710();
};
struct CellX
{
    void FUN_0054cfd0(NiPoint3*, NiPoint3*);
};
struct Entry
{
    TESForm* form;
    int a;
    int b;
    unsigned char flag;
};
struct EntryListNode
{
    virtual ~EntryListNode();
    unsigned int FUN_0084e3a0();
    Entry** FUN_00877a30(unsigned int);
    void ClearItems();
};
struct ActorList
{
    Actor* item;
    ActorList* next;
    void FUN_0096a2d0();
    void FUN_0046ffb0();
    void FUN_00470470();
    void FUN_005ae3d0(Actor**);
    bool FUN_008256d0();
    Actor** FUN_006815c0();
    ActorList* FUN_00726070();
};
struct Mgr98
{
    void FUN_008495b0();
    void FUN_00456520();
};
struct Node3d
{
    void FUN_00c66300();
    void FUN_00c6b540(int);
};
struct Sub10
{
    Node3d* FUN_004543c0();
};
struct Mgr10
{
    Sub10* FUN_005f36f0();
    void FUN_00459920();
};
struct Mgr3c
{
    void QueueReference(Actor*, int, int);
};
struct Owner
{
    void GetOrCreateNode(Actor*, int);
};
extern Mgr98* DAT_01202d98;
extern Mgr10* DAT_011dea10;
extern Mgr3c* DAT_011c3b3c;
extern NiPoint3 DAT_011f426c;
extern NiPoint3 DAT_011a9478;
void FUN_00573800(Actor*, TESObjectCELL*, int);
Node3d* FUN_00451010();
void FUN_00451590(int);
void FUN_0057d0a0(NiPoint3, NiPoint3, float);
void __cdecl operator delete(void*);

struct ActorList2
{
    ActorList list;
    ActorList2()
    {
        list.FUN_0096a2d0();
    }
    ~ActorList2()
    {
        list.FUN_0046ffb0();
    }
};

struct Cls
{
    Owner* owner;
    char pad[0x1c];
    EntryListNode* m_20;
    bool FUN_0047c850();
    void FUN_004534f0(int);
    void FUN_00861ee0(unsigned char);
    void CopyByteToOffset80();
    void FUN_00858af0(EntryListNode* list, Entry* ctx, bool reset);
};

// Calls Enter on ctx and each listed form, repositions the owned actors, optionally resets scene nodes and camera, then calls Leave and frees the list.
// @fnv 0x00858af0
void Cls::FUN_00858af0(EntryListNode* list, Entry* ctx, bool reset)
{
    if (!FUN_0047c850())
        return;
    FUN_004534f0(1);
    if (reset)
        DAT_01202d98->FUN_008495b0();
    bool own = true;
    if (!list)
    {
        list = m_20;
        own = false;
    }
    if (ctx)
        ((VObj*)DAT_011dea3c)->Enter(ctx->a, ctx->b);
    ActorList2 actors;
    if (list)
    {
        unsigned int n = list->FUN_0084e3a0();
        for (unsigned int i = 0; i < n; i++)
        {
            Entry* e = *list->FUN_00877a30(i);
            if (e && e->form != (TESForm*)DAT_011dea3c)
            {
                FUN_00861ee0(e->flag);
                ((VObj*)e->form)->Enter(e->a, e->b);
                if (own)
                {
                    Actor* a = dynamic_cast<Actor*>(e->form);
                    if (a && !a->FUN_008d6f30() && !a->FUN_00575d70())
                        actors.list.FUN_005ae3d0(&a);
                }
                CopyByteToOffset80();
            }
        }
    }
    if (own)
    {
        ActorList* it = &actors.list;
        while (it && !it->FUN_008256d0())
        {
            Actor* a = *it->FUN_006815c0();
            a->FUN_00893340(0);
            owner->GetOrCreateNode(a, 2);
            if (!a->FUN_008d6f30() && !a->FUN_00575d70())
            {
                unsigned int id = 0;
                TESObjectCELL* cell = dynamic_cast<TESObjectCELL*>(LookupFormByID(id));
                if (cell)
                {
                    NiPoint3 pos = DAT_011f426c;
                    NiPoint3 rot = DAT_011f426c;
                    ((CellX*)cell)->FUN_0054cfd0(&pos, &rot);
                    a->FUN_00575830(&pos);
                    a->FUN_00575700(rot);
                    FUN_00573800(a, cell, 0);
                }
                else
                {
                    a->FUN_00484af0(1);
                }
            }
            it = it->FUN_00726070();
        }
        actors.list.FUN_00470470();
    }
    if (reset)
    {
        NiPoint3 cam;
        Node3d* node1 = DAT_011dea10->FUN_005f36f0() ? DAT_011dea10->FUN_005f36f0()->FUN_004543c0() : 0;
        if (node1)
            node1->FUN_00c66300();
        if (FUN_00451010())
            FUN_00451010()->FUN_00c66300();
        DAT_011dea10->FUN_00459920();
        if (!((VObj*)DAT_011dea3c)->FUN_00950bb0(0))
            DAT_011c3b3c->QueueReference((Actor*)DAT_011dea3c, 0, 0);
        DAT_01202d98->FUN_00456520();
        DAT_01202d98->FUN_008495b0();
        if (node1)
            node1->FUN_00c6b540(0);
        if (FUN_00451010())
            FUN_00451010()->FUN_00c6b540(0);
        cam = *((VObj*)DAT_011dea3c)->GetPos();
        FUN_00451590(0);
        FUN_0057d0a0(cam, DAT_011a9478, 1.0f);
        FUN_00451590(1);
    }
    if (ctx && ((Actor*)DAT_011dea3c)->FUN_008d6f30())
        ((Actor*)DAT_011dea3c)->FUN_00483710();
    if (ctx)
        ((VObj*)DAT_011dea3c)->Leave(ctx->a, ctx->b);
    if (list)
    {
        unsigned int n = list->FUN_0084e3a0();
        for (unsigned int i = 0; i < n; i++)
        {
            Entry* e = *list->FUN_00877a30(i);
            if (e)
            {
                FUN_00861ee0(e->flag);
                ((VObj*)e->form)->Leave(e->a, e->b);
                CopyByteToOffset80();
                delete e;
            }
        }
    }
    if (m_20)
    {
        m_20->ClearItems();
        delete m_20;
        m_20 = 0;
    }
    if (reset)
    {
        Node3d* node1 = DAT_011dea10->FUN_005f36f0() ? DAT_011dea10->FUN_005f36f0()->FUN_004543c0() : 0;
        if (node1)
            node1->FUN_00c66300();
        if (FUN_00451010())
            FUN_00451010()->FUN_00c66300();
        DAT_01202d98->FUN_00456520();
        if (node1)
            node1->FUN_00c6b540(0);
        if (FUN_00451010())
            FUN_00451010()->FUN_00c6b540(0);
    }
    FUN_004534f0(0);
}
