// fallout_shared/tessaveloadgame.cpp: TESSaveLoadGame, NiTPointerMap_Standin, Holder, ChangesMap and more (142 functions)

#include "tessaveloadgame_decls.h"
// @fnv 0x008551f0
bool ChangesMap::HasFormChanges(TESForm* form, bool clear)
{
    return FUN_00855220(form->GetFormID(), clear);
}
// Looks up the TESObjectREFR stored in this pointer map under the given id and returns it, or null if absent.
// @fnv 0x00855100
TESObjectREFR* TESSaveLoadGame::QueueRemoveReferenceChange(unsigned int id)
{
    TESObjectREFR* result = 0;
    ((NiTPointerMap<unsigned int, TESObjectREFR*>*)this)->GetAt(id, result);
    return result;
}
// @fnv 0x00856c70
void TESSaveLoadGame::HasFormChanges(TESForm* form, bool clear)
{
    if (!form->IsTemporary())
        changes->HasFormChanges(form, clear);
}
// Removes the given TESForm from the deferred list if it is present.
// @fnv 0x0085a410
void TESSaveLoadGame::FinalizeForm(TESForm* form)
{
    if (deferred.IsInList((BGSNote*&)form))
        ((BSSimpleList<BGSCameraShot*>*)&deferred)->Remove((BGSCameraShot* const&)form);
}
// Initializes the task manager thread: calls FUN_00c42dd0 with arg and DAT_010c1748, then stores DAT_010c1740 in table and owner in manager.
// @fnv 0x00c3ee70
BSTaskManagerThread::BSTaskManagerThread(void* owner, unsigned int arg)
{
    FUN_00c42dd0(arg, DAT_010c1748);
    table = DAT_010c1740;
    manager = owner;
}

struct S006b81d0
{
    bool IsKeyEqual(unsigned int key1, unsigned int key2);
};
// @fnv 0x006b81d0
bool S006b81d0::IsKeyEqual(unsigned int key1, unsigned int key2)
{
    return key1 == key2;
}

struct S006c6a60
{
    unsigned int pad;
    unsigned int size;
    unsigned int GetIndexForKey(unsigned int key);
};
// @fnv 0x006c6a60
unsigned int S006c6a60::GetIndexForKey(unsigned int key)
{
    return key % size;
}

struct ChangeData
{
    void NotifyFormIDChanged(unsigned int);
    void ClearFormChangeFlags(unsigned int);
    void SetBuffer(void*);
    void* GetBuffer();
    unsigned int GetFlags();
    void SetFlags(unsigned int);
    void SetChange(unsigned int);
    void* __vecDelDtor(unsigned int);
    unsigned int iFlags;
    void* pBuffer;
};
typedef char _sizecheck_ChangeData[sizeof(ChangeData) == 8 ? 1 : -1];
struct FUN_00855220_shell : public ChangesMap
{
    bool FUN_00855220(unsigned int, bool);
};

struct LoadingHelper00855220
{
    bool GetLoading();
};
extern LoadingHelper00855220* g_TESSaveLoadGame;
struct RemoveAtHelper00855220
{
    bool RemoveAt(unsigned int);
};
struct Chg00855220
{
    int a;
    int b;
    void* FUN_00854fe0(unsigned int);
};
// @fnv 0x00855220
bool FUN_00855220_shell::FUN_00855220(unsigned int aiFormID, bool abForceRemove)
{
    Chg00855220* pchange;
    if (g_TESSaveLoadGame->GetLoading())
        return false;
    pchange = (Chg00855220*)((TESSaveLoadGame*)this)->QueueRemoveReferenceChange(aiFormID);
    if (pchange)
    {
        if (pchange->b == 0 || abForceRemove)
        {
            ((RemoveAtHelper00855220*)this)->RemoveAt(aiFormID);
            Chg00855220* t1 = pchange;
            Chg00855220* t2 = t1;
            t2 ? t2->FUN_00854fe0(1) : 0;
        }
        return true;
    }
    return false;
}

extern int DAT_01080514;
struct Dummy_00863390
{
    void FUN_00863390(int);
};

// @fnv 0x008552b0
int* __fastcall FUN_008552b0(Dummy_00863390* apObject)
{
    apObject->FUN_00863390(0x25);
    *(int*)apObject = (int)&DAT_01080514;
    return (int*)apObject;
}

namespace fnv_008553e0 {
extern int DAT_01080514;
struct Dummy_00863390
{
    void FUN_00863390(int);
};

// Calls FUN_00863390 with 0x25, stores the address of DAT_01080514 into the object, and returns the object pointer.
// @fnv 0x008553e0
int* __fastcall FUN_008553e0(Dummy_00863390* apObject)
{
    apObject->FUN_00863390(0x25);
    *(int*)apObject = (int)&DAT_01080514;
    return (int*)apObject;
}
}  // namespace fnv_008553e0

namespace fnv_00855550 {
extern int DAT_01080514;
struct Dummy_00863390
{
    void FUN_00863390(int);
};

// Calls FUN_00863390 with 0x25, stores the address of DAT_01080514 into the object, and returns the object pointer.
// @fnv 0x00855550
int* __fastcall FUN_00855550(Dummy_00863390* apObject)
{
    apObject->FUN_00863390(0x25);
    *(int*)apObject = (int)&DAT_01080514;
    return (int*)apObject;
}
}  // namespace fnv_00855550

// @fnv 0x00856850
void __fastcall CopyByteToOffset80(char* pBuffer)
{
    pBuffer[0x80] = pBuffer[0x75];
}

struct NiTMapItem_00863840
{
    NiTMapItem_00863840* m_pkNext;
    unsigned int m_key;
    void* m_val;
};

struct ArgItem_00863840
{
    NiTMapItem_00863840* pkItem;
};
struct ArgKey_00863840
{
    unsigned int key;
};
struct ArgVal_00863840
{
    void* val;
};

// @fnv 0x00863840
void __fastcall SetMapItemKeyValue(void* pThis, ArgItem_00863840 pkItem, ArgKey_00863840 key, ArgVal_00863840 val)
{
    pkItem.pkItem->m_key = key.key;
    pkItem.pkItem->m_val = val.val;
}

struct NiTLargeArray
{
    unsigned int SetAtGrow(unsigned int, const unsigned int&);
};
struct S00863d90
{
    unsigned int a, b, c;
    unsigned int cnt;
    void FUN_00863d90(const unsigned int& e);
};
// Appends the given element to the array at index cnt via SetAtGrow.
// @fnv 0x00863d90
void S00863d90::FUN_00863d90(const unsigned int& auiElement)
{
    ((NiTLargeArray*)this)->SetAtGrow(cnt, auiElement);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long);
struct Elem00c3e7d0
{
    void FUN_00446ff0();
};
struct S00c3e7d0
{
    char pad[0x44];
    volatile long a44;
    volatile long a48;
    unsigned int a4c;
    Elem00c3e7d0** a50;
    bool ReleaseAndCleanup();
};
// If a48 is nonzero, decrements it; when it reaches zero, waits for a44 to equal a4c, then calls FUN_00446ff0 on each of a4c elements and decrements a44.
// @fnv 0x00c3e7d0
bool S00c3e7d0::ReleaseAndCleanup()
{
    if (a48 == 0)
        return false;
    if (InterlockedDecrement(&a48) == 0)
    {
        while (a44 != a4c)
            Sleep(1);
        for (unsigned int i = 0; i < a4c; i++)
        {
            a50[i]->FUN_00446ff0();
            InterlockedDecrement(&a44);
        }
        {
            int u1, u2, u3;
        }
        return true;
    }
    return false;
}

namespace fnv_007065c0 {
struct FUN_008df040_shell
{
    unsigned char FUN_008df040(void);
};

extern TESSaveLoadGame* g_TESSaveLoadGame;

// @fnv 0x007065c0
unsigned short __cdecl FUN_007065c0(void)
{
    unsigned short v = 0;
    v += 4;
    v += 4;
    if (((FUN_008df040_shell*)g_TESSaveLoadGame)->FUN_008df040() >= 0x5d)
        v += 1;
    return v;
}
}  // namespace fnv_007065c0

struct InteriorCellNewReferencesMap
{
    void* FUN_00855310();
    void* __thiscall FUN_008552e0(unsigned int flags);
};

void _Deallocate(void* p);

// Calls FUN_00855310, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x008552e0
void* InteriorCellNewReferencesMap::FUN_008552e0(unsigned int flags)
{
    FUN_00855310();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// Compares the values at index 5 of two unsigned short arrays, returning -1, 1, or 0.
// @fnv 0x00855b60
int CompareByIndex5(unsigned short* ausLeft, unsigned short* ausRight)
{
    int result;
    if (ausLeft[5] > ausRight[5])
        result = -1;
    else
        result = (ausLeft[5] < ausRight[5]) ? 1 : 0;
    return result;
}

namespace fnv_00858700 {
extern "C" void __cdecl _Deallocate(void*);

struct FUN_00858700
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    void* m_ptr;
    void DoIt(void* arg);
};

// Deallocates arg via _Deallocate and sets m_ptr to null.
// @fnv 0x00858700
void FUN_00858700::DoIt(void* arg)
{
    _Deallocate(arg);
    m_ptr = 0;
}
}  // namespace fnv_00858700

extern "C" void __cdecl FUN_00ecbf20(void*, void*);

// @fnv 0x00860e00
void FUN_00860e00(void* apFirst, void* apSecond)
{
    FUN_00ecbf20(apFirst, apSecond);
}

struct FUN_00861610_Class
{
    char m_auiShapeKeys[0x5c];
    int* m_field5C;
    int __thiscall GetRangeBetweenEntries(int arg, int arg2);
};

// Returns the difference between the element at index arg+1 and the element at index arg in the array pointed to by m_field5C.
// @fnv 0x00861610
int __thiscall FUN_00861610_Class::GetRangeBetweenEntries(int aiIndex, int aiUnused)
{
    return m_field5C[aiIndex + 1] - m_field5C[aiIndex];
}

struct FUN_008620f0
{
    unsigned char m_0x74;
    unsigned char m_0x75;
    void Init();
};

// @fnv 0x008620f0
void FUN_008620f0::Init()
{
    ((unsigned char*)this)[0x74] = 0;
    ((unsigned char*)this)[0x75] = 0x7d;
}

struct FUN_008634e0
{
    void* FUN_00863860();
    void* DeleteThis(unsigned int flags);
};
void _Deallocate(void* p);

// Calls FUN_00863860, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x008634e0
void* FUN_008634e0::DeleteThis(unsigned int flags)
{
    FUN_00863860();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00863540 {
extern "C" void __cdecl _Deallocate(void*);

struct FUN_00863540_class
{
    void FUN_00863cd0();
    void* FUN_00863540(unsigned int flags);
};

// Calls FUN_00863cd0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00863540
void* FUN_00863540_class::FUN_00863540(unsigned int flags)
{
    FUN_00863cd0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00863540

struct FUN_00863c90_Class
{
    bool __thiscall IsEqual(unsigned char a, unsigned char b);
};

// @fnv 0x00863c90
bool __thiscall FUN_00863c90_Class::IsEqual(unsigned char aucLeft, unsigned char aucRight)
{
    return aucLeft == aucRight;
}

struct ActorCombatGroup;

struct NiTMallocInterface
{
    static void __cdecl Deallocate(ActorCombatGroup**);
};

extern int DAT_01081f98;

struct FUN_00863d60_obj
{
    int field0;
    ActorCombatGroup** field4;
    void __thiscall FUN_00863d60();
};

// Sets field0 to the address of DAT_01081f98, then deallocates field4 via NiTMallocInterface::Deallocate.
// @fnv 0x00863d60
void __thiscall FUN_00863d60_obj::FUN_00863d60()
{
    field0 = reinterpret_cast<int>(&DAT_01081f98);
    NiTMallocInterface::Deallocate(field4);
}

struct FUN_00855130_This
{
    TESObjectREFR* FUN_00855130(TESForm* arg);
};

// @fnv 0x00855130
TESObjectREFR* FUN_00855130_This::FUN_00855130(TESForm* pForm)
{
    return ((TESSaveLoadGame*)this)->QueueRemoveReferenceChange(pForm->GetFormID());
}

struct FUN_00863480Class
{
    void __thiscall FUN_00863640();
    void* __thiscall FUN_00863480(unsigned int flags);
};

void __cdecl _Deallocate(void*);

// Calls FUN_00863640, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00863480
void* __thiscall FUN_00863480Class::FUN_00863480(unsigned int flags)
{
    FUN_00863640();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00863c70_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int ModuloByDivisor(unsigned char a);
};

// @fnv 0x00863c70
int FUN_00863c70_Class::ModuloByDivisor(unsigned char a)
{
    return a % (unsigned int)m_iWordAt04;
}

extern "C" void __cdecl _NiFreeAlias(void*);

extern int DAT_01081f78;

struct NiTPointerMap_Standin
{
    void* m_ppVirtualMethodTable;
    void* m_unknown;
    void* m_ptr;
    void RemoveAll();
    void ClearAndFree();
};

void __thiscall NiTPointerMap_Standin::RemoveAll()
{}

// @fnv 0x00863d30
void __thiscall NiTPointerMap_Standin::ClearAndFree()
{
    m_ppVirtualMethodTable = &DAT_01081f78;
    RemoveAll();
    _NiFreeAlias(m_ptr);
}

namespace fnv_00484ce0 {
struct TESSaveLoadGameHelper
{
    void FUN_008579b0(void*, int);
    void FUN_00484ce0(void* form, int flag);
};

extern TESSaveLoadGame* g_TESSaveLoadGame;

// Forwards the form and flag to the save/load game's FUN_008579b0 handler.
// @fnv 0x00484ce0
void TESSaveLoadGameHelper::FUN_00484ce0(void* form, int flag)
{
    ((TESSaveLoadGameHelper*)g_TESSaveLoadGame)->FUN_008579b0(form, flag);
}
}  // namespace fnv_00484ce0

namespace fnv_00484d00 {
struct FUN_008579e0_shell
{
    void __thiscall FUN_008579e0(void* buffer, unsigned int size);
};

extern TESSaveLoadGame* g_TESSaveLoadGame;

struct FUN_00484d00_shell
{
    void __thiscall FUN_00484d00(void* buffer, unsigned int size);
};

// @fnv 0x00484d00
void __thiscall FUN_00484d00_shell::FUN_00484d00(void* buffer, unsigned int size)
{
    reinterpret_cast<FUN_008579e0_shell*>(g_TESSaveLoadGame)->FUN_008579e0(buffer, size);
}
}  // namespace fnv_00484d00

struct FUN_008586a0_class
{
    void FUN_00857b50(int, int, int);
    void ForwardToFUN_00857b50(int a, int b, int c);
};

// Calls FUN_00857b50 with the three integer arguments a, b and c.
// @fnv 0x008586a0
void FUN_008586a0_class::ForwardToFUN_00857b50(int a, int b, int c)
{
    FUN_00857b50(a, b, c);
}

struct FUN_00862370_class
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
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* m_38;
    void* m_3c;
    void* m_40;
    void* m_44;
    void* m_48;
    void* m_4c;
    void* m_50;
    void* m_54;
    void* m_58;
    void* m_5c;
    void* m_60;
    void* m_64;
    void* m_68;
    void* m_6c;
    void* m_70;
    void* m_74;
    void* m_78;
    void* m_7c;
    void* m_80;
    void* m_84;
    void* m_88;
    int* m_8c;
    void InitMaxValue();
    int* __thiscall GetOrCreatePointer();
};

// Returns m_8c, calling InitMaxValue first to initialize it if it is null.
// @fnv 0x00862370
int* __thiscall FUN_00862370_class::GetOrCreatePointer()
{
    if (m_8c == 0)
        InitMaxValue();
    return m_8c;
}

extern int DAT_01081e30;
struct FUN_00863360
{
    void __thiscall FUN_008635d0(int);
    void* __thiscall FUN_00863361(int);
};
// Calls FUN_008635d0 with a, stores the address of DAT_01081e30 at this, and returns this.
// @fnv 0x00863360
void* __thiscall FUN_00863360::FUN_00863361(int a)
{
    FUN_008635d0(a);
    *reinterpret_cast<void**>(this) = &DAT_01081e30;
    return this;
}

extern int DAT_01081e50;
struct FUN_00863390_class
{
    int m;
    void __thiscall FUN_008636d0(int);
    int __thiscall FUN_00863390(int a);
};
// Calls FUN_008636d0 with a, stores the address of DAT_01081e50 in m, and returns this.
// @fnv 0x00863390
int __thiscall FUN_00863390_class::FUN_00863390(int a)
{
    FUN_008636d0(a);
    m = (int)&DAT_01081e50;
    return (int)this;
}

struct FUN_008633f0_class
{
    void* p;
    void* FUN_008633f0(void* a);
    void FUN_008638f0(void* a);
};

extern void* DAT_01081e90;

// Calls FUN_008638f0 on a, sets p to the address of DAT_01081e90, and returns this.
// @fnv 0x008633f0
void* FUN_008633f0_class::FUN_008633f0(void* apArg)
{
    FUN_008638f0(apArg);
    p = &DAT_01081e90;
    return this;
}

extern int DAT_01081eb0;

struct FUN_00863420_class
{
    void* vfn_0;
    void FUN_008639f0(int a);
    FUN_00863420_class* FUN_00863420(int a);
};

// Calls FUN_008639f0 with a, sets vfn_0 to &DAT_01081eb0, and returns this.
// @fnv 0x00863420
FUN_00863420_class* FUN_00863420_class::FUN_00863420(int a)
{
    FUN_008639f0(a);
    vfn_0 = &DAT_01081eb0;
    return this;
}

extern "C" void __cdecl FUN_00863e30(int);
extern int DAT_01081ed0;

struct FUN_00863450_Class
{
    int __thiscall FUN_00863e30(int);
    int __thiscall InitWithGlobal(int a);
};

// Calls FUN_00863e30 with a, stores the address of DAT_01081ed0 into this, and returns this.
// @fnv 0x00863450
int __thiscall FUN_00863450_Class::InitWithGlobal(int a)
{
    FUN_00863e30(a);
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_01081ed0);
    return reinterpret_cast<int>(this);
}

extern int DAT_01081ef8;
struct MyMap
{
    void RemoveAll();
};
void __cdecl _NiFreeAlias(void*);
struct FUN_008636a0 : MyMap
{
    int* vtbl;
    void* data;
    void* alias;
    void Init();
};
// @fnv 0x008636a0
void FUN_008636a0::Init()
{
    vtbl = (int*)&DAT_01081ef8;
    RemoveAll();
    _NiFreeAlias(alias);
}

struct FUN_00863cb0_Class
{
    void __thiscall FUN_00863cb0(int a, char b, int c);
};

// @fnv 0x00863cb0
void __thiscall FUN_00863cb0_Class::FUN_00863cb0(int a, char b, int aiValue)
{
    ((char*)a)[4] = b;
    ((int*)a)[2] = aiValue;
}

struct FUN_00c3ea10_stub
{
    void FUN_00c3ea10();
};
void FUN_00c3fce0(void*);
struct IOManager
{
    void FUN_00c3fce0();
    void FUN_00c3e380();
};
// @fnv 0x00c3e380
void IOManager::FUN_00c3e380()
{
    FUN_00c3fce0();
    ((FUN_00c3ea10_stub**)((char*)this + 0x64))[0]->FUN_00c3ea10();
}

namespace fnv_00858730 {
struct ChangeData
{
    void NotifyFormIDChanged(unsigned int);
    void ClearFormChangeFlags(unsigned int);
    void SetBuffer(void*);
    void* GetBuffer();
    unsigned int GetFlags();
    void SetFlags(unsigned int);
    void SetChange(unsigned int);
    void* __vecDelDtor(unsigned int);
    unsigned int iFlags;
    void* pBuffer;
};
typedef char _sizecheck_ChangeData[sizeof(ChangeData) == 8 ? 1 : -1];
struct FUN_00858730_shell : public TESSaveLoadGame
{
    bool FUN_00858730(TESForm*);
};

struct FUN_00485d50_slg
{
    bool GetLoading();
};
struct FUN_00855130_This
{
    TESObjectREFR* FUN_00855130(TESForm*);
};
struct FUN_00855150_s
{
    void FUN_00855150(TESForm*, unsigned int);
};
struct FUN_008579e0_shell
{
    void FUN_008579e0(void*, unsigned int);
};
struct ATM
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering();
};
struct GlobalObject_0044fae0;
extern ATM g_011de494;
extern TESSaveLoadGame* g_TESSaveLoadGame;
int __fastcall FNV_GetFormType(TESForm*);
struct Fake440e30
{
    const char* FUN_00440e30();
};
struct FormTypeInfo_s
{
    const char* pName;
    int a;
    int b;
};
extern FormTypeInfo_s DAT_01187004[];
int sprintf(char*, const char*, ...);
struct Flt
{
    operator unsigned int();
};
struct GridArray_s
{
    void* FUN_00726070();
};
struct SLGStub
{
    unsigned int ClearRefrFlag(TESForm*, unsigned int);
    void FUN_00861ee0(unsigned char);
    void LoadChange(TESForm*, unsigned int);
    void FUN_00858700(void*);
};
struct BufferHeader_s
{
    void FUN_00858aa0(void*, unsigned int, unsigned int);
    int a;
    int b;
    int c;
};
class TESSound;
struct EffectSetting
{
    void SetBoltSound(TESSound*);
};
struct FUN_004534f0_shell
{
    void FUN_004534f0(unsigned int);
};
struct FUN_0046a010_shell
{
    void FUN_0046a010(bool);
};
struct FormV
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
    virtual void LoadGame(unsigned int, int);
};
void __fastcall CopyByteToOffset80(char*);
struct FUN_00863e00
{
    FUN_00863e00(int, int);
    char pad[0x18];
};
struct FUN_00857280
{
    FUN_00857280(TESForm*, unsigned int, int, unsigned char);
    char pad[0x10];
};
class TESTopicInfo;
template <class T> class NiTMallocInterface;
template <class T, class A> class NiTLargeArray
{
  public:
    unsigned int Add(const T&);
};
struct TESRaceForm
{
    void Initialize(unsigned int);
};
struct LoadFormHeader_s
{
    unsigned short size;
    unsigned char type;
    unsigned char version;
};

// @fnv 0x00858730
bool FUN_00858730_shell::FUN_00858730(TESForm* apForm)
{
    if (!((FUN_00485d50_slg*)this)->GetLoading())
        return false;
    ChangeData* pchange2 = (ChangeData*)((FUN_00855130_This*)changes)->FUN_00855130(apForm);
    if (pchange2)
    {
        void* ptempbuffer = ((GridArray_s*)pchange2)->FUN_00726070();
        if (ptempbuffer)
        {
            int _ibufferOverrun;
            unsigned int iflags;
            unsigned int isize;
            BufferHeader_s bufferHeader4;
            bool brestore;
            LoadFormHeader_s formHeader;

            g_011de494.QueryPerformanceCounter((int)"TESSaveLoadGame::LoadForm");
            *(void**)((char*)this + 0x14) = ptempbuffer;
            ((FUN_008579e0_shell*)g_TESSaveLoadGame)->FUN_008579e0(&formHeader, 4);
            if (FNV_GetFormType(apForm) != formHeader.type)
            {
                char pmessageA[260];
                sprintf(
                    pmessageA,
                    "Load Error: Form with ID %08X was saved with form type %s, but currently has form type %s.  Its loading will be skipped.",
                    apForm->GetFormID(), DAT_01187004[formHeader.type].pName, ((Fake440e30*)apForm)->FUN_00440e30());
                changes->HasFormChanges(apForm, true);
                *(void**)((char*)this + 0x14) = 0;
                g_011de494.WaitForTasksDuringRendering();
                return false;
            }
            isize = formHeader.size;
            iflags = *(Flt*)pchange2;
            iflags = ((SLGStub*)this)->ClearRefrFlag(apForm, iflags);
            ((SLGStub*)this)->FUN_00861ee0(formHeader.version);
            bufferHeader4.FUN_00858aa0(&formHeader, apForm->GetFormID(), iflags);
            ((EffectSetting*)this)->SetBoltSound((TESSound*)&bufferHeader4);
            brestore = ((FUN_00485d50_slg*)this)->GetLoading();
            ((FUN_004534f0_shell*)this)->FUN_004534f0(1);
            ((FUN_0046a010_shell*)apForm)->FUN_0046a010(true);
            ((SLGStub*)this)->LoadChange(apForm, iflags);
            ((FormV*)apForm)->LoadGame(iflags, 0);
            ((FUN_004534f0_shell*)this)->FUN_004534f0(brestore);
            ((EffectSetting*)this)->SetBoltSound(0);
            CopyByteToOffset80((char*)this);
            if (*(void**)((char*)this + 0x20) == 0)
                *(FUN_00863e00**)((char*)this + 0x20) = new FUN_00863e00(0x32, 0x32);
            (*(NiTLargeArray<TESTopicInfo*, NiTMallocInterface<TESTopicInfo*> >**)((char*)this + 0x20))
                ->Add((TESTopicInfo*)new FUN_00857280(apForm, iflags, 0, formHeader.version));
            _ibufferOverrun = *(char**)((char*)this + 0x14) - ((char*)ptempbuffer + isize + 4);
            ((SLGStub*)this)->FUN_00858700(ptempbuffer);
            ((TESRaceForm*)pchange2)->Initialize(0);
            if (*(unsigned int*)((char*)this + 0x54))
            {
                ((FUN_00855150_s*)changes)->FUN_00855150(apForm, *(unsigned int*)((char*)this + 0x54));
                *(unsigned int*)((char*)this + 0x54) = 0;
            }
            g_011de494.WaitForTasksDuringRendering();
            return true;
        }
    }
    return false;
}
}  // namespace fnv_00858730

extern int DAT_01081e70;
struct S8633
{
    void FUN_008637d0(int);
    S8633* FUN_008633c0(int);
};
// Calls FUN_008637d0 with a, sets the object's vtable pointer to DAT_01081e70, and returns this.
// @fnv 0x008633c0
S8633* S8633::FUN_008633c0(int a)
{
    FUN_008637d0(a);
    *(void**)this = (void*)&DAT_01081e70;
    return this;
}

extern int DAT_01081ef0;
struct BaseStub
{
    void __thiscall FUN_00864160(unsigned int, unsigned int);
};
struct FUN_008635a0 : BaseStub
{
    FUN_008635a0(unsigned int, unsigned int);
};
// @fnv 0x008635a0
FUN_008635a0::FUN_008635a0(unsigned int a, unsigned int b)
{
    FUN_00864160(a, b);
    *(void**)this = (void*)&DAT_01081ef0;
}

namespace fnv_008637a0 {
struct MyMap
{
    void RemoveAll();
    void FUN_008637a0();
};
void __cdecl _NiFree(void*);
extern int DAT_01081f18;
// @fnv 0x008637a0
void MyMap::FUN_008637a0()
{
    *(void**)this = (void*)&DAT_01081f18;
    RemoveAll();
    _NiFree(*(void**)((char*)this + 8));
}
}  // namespace fnv_008637a0

namespace fnv_008638c0 {
struct MyMap
{
    int m0;
    int m4;
    void RemoveAll();
};
void _NiFree(void*);
extern int DAT_01081f38;
struct Holder : MyMap
{
    void* m8;
    void FUN_008638c0();
};
// @fnv 0x008638c0
void Holder::FUN_008638c0()
{
    *(int*)this = (int)&DAT_01081f38;
    RemoveAll();
    _NiFree(m8);
}
}  // namespace fnv_008638c0

namespace fnv_008639c0 {
struct MyMap
{
    void RemoveAll();
    int _0;
};
extern int DAT_01081f58;
void __cdecl _NiFree(void*);
struct Holder : public MyMap
{
    void* _4;
    void* _8;
    void FUN_008639c0();
};
// @fnv 0x008639c0
void Holder::FUN_008639c0()
{
    *(void**)this = (void*)&DAT_01081f58;
    RemoveAll();
    _NiFree(_8);
}
}  // namespace fnv_008639c0

namespace fnv_00855660 {
struct FUN_00863420_class
{
    void* m_pVirtualFunctionTable;
    char m[0xc];
    FUN_00863420_class(int);
};
struct SL
{
    void* m_pObject;
    char m[4];
    SL();
};
struct FUN_00855660
{
    FUN_00863420_class* m_pVirtualFunctionTable;
    SL* m_pObject;
    FUN_00855660();
};

// Allocates a FUN_00863420_class with argument 0x25 and an SL, storing both in the object's fields.
// @fnv 0x00855660
FUN_00855660::FUN_00855660()
{
    m_pVirtualFunctionTable = new FUN_00863420_class(0x25);
    m_pObject = new SL;
}
}  // namespace fnv_00855660

struct AutoMemHelper
{
    int m_uiLogicalSize;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct ContainerItemExtra
{
    int m_iExtraID;
    char* m_pString;
};
struct TaskQueueInterface
{
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
struct G2
{
    void AddHead(int*);
};
unsigned int BSStringLength(const char*);
struct FUN_008558a0
{
    void SetExtraDataString(int iExtraID, const char* pString);
};
// @fnv 0x008558a0
void FUN_008558a0::SetExtraDataString(int iExtraID, const char* pString)
{
    AutoMemHelper kHelper4(17, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESSaveLoadGame.cpp",
                           615);
    ContainerItemExtra* pExtra;
    unsigned int uiSize;
    pExtra = new ContainerItemExtra;
    pExtra->m_iExtraID = iExtraID;
    uiSize = BSStringLength(pString) + 1;
    pExtra->m_pString = static_cast<char*>(operator new(uiSize));
    TaskQueueInterface::CopyStringToBuffer(pExtra->m_pString, uiSize, pString);
    ((G2*)*(int**)((char*)this + 4))->AddHead((int*)&pExtra);
}

struct MobileObject
{
    bool IsTalkingActivator() const;
};
struct FUN_00857bd0
{
    void Init(unsigned int);
};
struct FUN_00857aa0 : FUN_00857bd0
{
    unsigned int FUN_00861c00(unsigned int);
    bool ValidateFormIDArray(unsigned int* apFormID, unsigned int aiSize);
};
void* __cdecl __memcpy(void* pDest, const void* pSrc, unsigned int uiSize);
// Copies aiSize bytes from the object's buffer into apFormID, remaps each form ID when talking, calls Init, and returns whether any nonzero ID became zero.
// @fnv 0x00857aa0
bool FUN_00857aa0::ValidateFormIDArray(unsigned int* apFormID, unsigned int aiSize)
{
    bool bforcedToZero = false;
    __memcpy(apFormID, *(void**)((char*)this + 0x14), aiSize);
    if (reinterpret_cast<MobileObject*>(this)->IsTalkingActivator())
    {
        unsigned int icount = aiSize / 4;
        for (unsigned int i = 0; i < icount; ++i)
        {
            unsigned int iformID = FUN_00861c00(apFormID[i]);
            if (apFormID[i] != 0 && iformID == 0)
                bforcedToZero = true;
            apFormID[i] = iformID;
        }
    }
    Init(aiSize);
    return bforcedToZero;
}

namespace fnv_00858570 {
struct FUN_008558a0_class
{
    void FUN_008558a0(void*, const char*);
};
struct FUN_008586a0_class
{
    void FUN_00857b50(int, void**, int);
    void ForwardToFUN_00857b50(int, void*, int);
};
struct FUN_00858600_class
{
    void* FUN_00858600(void*);
};
struct FUN_00858700_class
{
    void FUN_00858700(void*);
};
struct FUN_009755b0_class
{
    void* FUN_009755b0();
};
struct FUN_009756c0_class
{
    void SaveTempEffects();
};
extern int DAT_011e0e80;
struct FUN_00858570_class
{
    void LoadTempEffectsList(int apFile);
};
// @fnv 0x00858570
void FUN_00858570_class::LoadTempEffectsList(int apFile)
{
    void* ptempBuffer = ((FUN_009755b0_class*)&DAT_011e0e80)->FUN_009755b0();
    ((FUN_008586a0_class*)this)->FUN_00857b50(apFile, &ptempBuffer, 4);
    if (ptempBuffer)
    {
        if (*(void**)((char*)this + 0x44))
            ((FUN_008558a0_class*)*(void**)((char*)this + 0x44))->FUN_008558a0(ptempBuffer, "Temp Effects List");
        void* ptempBuffer2 = ((FUN_00858600_class*)this)->FUN_00858600(ptempBuffer);
        ((FUN_009756c0_class*)&DAT_011e0e80)->SaveTempEffects();
        ((FUN_008586a0_class*)this)->ForwardToFUN_00857b50(apFile, ptempBuffer2, (int)ptempBuffer);
        ((FUN_00858700_class*)this)->FUN_00858700(ptempBuffer2);
    }
}
}  // namespace fnv_00858570

struct PlayerCharacter
{
    int __fastcall FUN_004f8960();
    bool GetUnderAIControl();
    static bool UpdatePlayerStatus();
};
extern PlayerCharacter* _g_thePlayer;
int __cdecl FUN_007023c0();
int __cdecl FUN_00702640();
struct FUN_008616f0_shell
{
    bool __thiscall FUN_008616f0();
};
// @fnv 0x008616f0
bool __thiscall FUN_008616f0_shell::FUN_008616f0()
{
    if (_g_thePlayer->FUN_004f8960() == 2 || _g_thePlayer->FUN_004f8960() == 1)
        return false;
    if (_g_thePlayer->GetUnderAIControl())
        return false;
    if (PlayerCharacter::UpdatePlayerStatus())
        return true;
    int emenuEnum = FUN_007023c0();
    if (emenuEnum != 0 && emenuEnum != 3)
        return false;
    emenuEnum = FUN_00702640();
    if (emenuEnum != 0 && emenuEnum != 3)
        return false;
    return true;
}

namespace fnv_00861780 {
struct DataHandler
{
    bool FormIDExists(unsigned int);
};
extern DataHandler* g_dataHandler;
struct LH
{
    bool IsInList(int&);
};
struct G2
{
    void AddHead(int*);
};
void _FNV_Warning(const char*, ...);

struct FUN_00861780_StandIn
{
    void Add(TESForm* form);
};

// Warns if form is null or not created, otherwise adds its form ID to the list at offset 0x2c if not already present.
// @fnv 0x00861780
void FUN_00861780_StandIn::Add(TESForm* form)
{
    if (form == 0)
    {
        _FNV_Warning("SAVELOAD: Attempting to add null object to created base objects list.");
    }
    else if (!g_dataHandler->FormIDExists(form->GetFormID()))
    {
        _FNV_Warning("SAVELOAD: Attempting to add non-created form %08X to created base objects list.",
                     form->GetFormID());
    }
    else
    {
        int id = form->GetFormID();
        if (!((LH*)((char*)this + 0x2c))->IsInList(id))
        {
            int iFormIDToAdd = form->GetFormID();
            ((G2*)((char*)this + 0x2c))->AddHead(&iFormIDToAdd);
        }
    }
}
}  // namespace fnv_00861780

int __cdecl _FNV_Finite(double);
int __cdecl _FNV_IsNaN(double);
struct FUN_00862430_vec
{
    float x, y, z;
};
struct FUN_00862430_cls
{
    bool __thiscall HasInvalidComponents(FUN_00862430_vec* v);
};
// Returns true if any component of v is non-finite or NaN, otherwise false.
// @fnv 0x00862430
bool __thiscall FUN_00862430_cls::HasInvalidComponents(FUN_00862430_vec* pVec)
{
    if (!_FNV_Finite(pVec->x) || !_FNV_Finite(pVec->y) || !_FNV_Finite(pVec->z) || _FNV_IsNaN(pVec->x) ||
        _FNV_IsNaN(pVec->y) || _FNV_IsNaN(pVec->z))
        return true;
    return false;
}

namespace fnv_008632a0 {
void* __cdecl operator new(unsigned int);

struct TESTopicInfo;

template <class T> struct NiTMallocInterface;

template <class T, class A> class NiTLargeArray
{
  public:
    unsigned int Add(T&);
};

struct NiTLargePrimitiveArray
{
    char data[0x18];
    NiTLargePrimitiveArray(unsigned int, unsigned int);
    ~NiTLargePrimitiveArray();
};

struct FUN_008632a0_slg : TESSaveLoadGame
{
    bool GetLoading();
    void AddLoadingTopic(TESTopicInfo*);
};

// When loading, lazily creates the topic array at this+0xb0 and adds pTopic to it.
// @fnv 0x008632a0
void FUN_008632a0_slg::AddLoadingTopic(TESTopicInfo* pTopic)
{
    if (!GetLoading())
        return;
    if (!*((NiTLargePrimitiveArray**)((char*)this + 0xb0)))
        *((NiTLargePrimitiveArray**)((char*)this + 0xb0)) = new NiTLargePrimitiveArray(0x4e20, 0x7d0);
    ((NiTLargeArray<TESTopicInfo*, NiTMallocInterface<TESTopicInfo*> >*)*(
         (NiTLargePrimitiveArray**)((char*)this + 0xb0)))
        ->Add(pTopic);
}
}  // namespace fnv_008632a0

struct BSFile
{
    int FUN_00473180(const char*, unsigned int);
};
struct FUN_00857b50_slg : TESSaveLoadGame
{
    bool GetLoading();
    int FUN_00857b50(BSFile*, const char*, unsigned int);
};

// @fnv 0x00857b50
int FUN_00857b50_slg::FUN_00857b50(BSFile* file, const char* name, unsigned int size)
{
    if (GetLoading())
    {
        *(unsigned int*)((char*)this + 0x94) += size;
        return size;
    }
    int result = file->FUN_00473180(name, size);
    return result;
}

struct DataHandler
{
    bool FormIDExists(unsigned int);
};
extern DataHandler* g_dataHandler;
struct Arr
{
    unsigned int* GetAt(int);
};
struct FUN_00861c00
{
    unsigned int GetID(unsigned int id);
};
// @fnv 0x00861c00
unsigned int FUN_00861c00::GetID(unsigned int id)
{
    if (g_dataHandler->FormIDExists(id))
        return id;
    if (id > ((TESForm*)(*(void**)((char*)this + 0x78)))->GetFormID())
        return 0;
    unsigned int result = *((Arr*)(*(void**)((char*)this + 0x78)))->GetAt(id);
    return result;
}

namespace fnv_00861cd0 {
struct Arr
{
    unsigned int* GetAt(int);
};
struct FUN_00861cd0Class
{
    unsigned int FUN_00861cd0(unsigned short index);
};

// Returns 0 if index exceeds the form ID at this+0x7c, otherwise returns the element at index from the array at this+0x7c.
// @fnv 0x00861cd0
unsigned int FUN_00861cd0Class::FUN_00861cd0(unsigned short index)
{
    if (index > ((TESForm*)(*(unsigned int*)((char*)this + 0x7c)))->GetFormID())
        return 0;
    unsigned int result = *((Arr*)(*(unsigned int*)((char*)this + 0x7c)))->GetAt(index);
    return result;
}
}  // namespace fnv_00861cd0

void __cdecl memset(void*, int, unsigned int);
void* __cdecl _NiMalloc(unsigned int);
extern int DAT_01081ef8;

struct FUN_008635d0_t
{
    void* m_pVTable;
    int m_iArrayLength;
    void* m_pData;
    int m_iDummy;
    FUN_008635d0_t(int iCount);
};

// Sets the vtable, stores iCount, allocates iCount*4 bytes and zeroes them into m_pData.
// @fnv 0x008635d0
FUN_008635d0_t::FUN_008635d0_t(int iCount)
{
    m_pVTable = &DAT_01081ef8;
    m_iArrayLength = iCount;
    m_iDummy = 0;
    unsigned int uiSize = m_iArrayLength * 4;
    m_pData = _NiMalloc(uiSize);
    memset(m_pData, 0, m_iArrayLength * 4);
}

namespace fnv_00863640 {
struct MyMap
{
    virtual ~MyMap();
    void RemoveAll();
};
struct FUN_008636a0
{
    ~FUN_008636a0();
};
struct FUN_00863640 : public MyMap
{
    virtual ~FUN_00863640();
};
// Destructor that calls RemoveAll to clear the map's contents.
// @fnv 0x00863640
FUN_00863640::~FUN_00863640()
{
    RemoveAll();
}
}  // namespace fnv_00863640

namespace fnv_008636d0 {
extern int DAT_01081f18;
void* __cdecl _NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);

struct FUN_008636d0
{
    int* vtbl;
    int count;
    void* data;
    int pad;
    FUN_008636d0(int n);
};

// Sets the vtable, stores the element count, allocates count*4 bytes and zero-fills them.
// @fnv 0x008636d0
FUN_008636d0::FUN_008636d0(int aiCount)
{
    vtbl = &DAT_01081f18;
    count = aiCount;
    pad = 0;
    unsigned int size = count << 2;
    data = _NiMalloc(size);
    memset(data, 0, count << 2);
}
}  // namespace fnv_008636d0

namespace fnv_008637d0 {
void* __cdecl _NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
extern int DAT_01081f38;
struct FUN_008637d0
{
    void** vtbl;
    unsigned int count;
    void* buf;
    unsigned int m;
    FUN_008637d0(unsigned int n);
};
// Sets the vtable, stores the count, allocates count*4 bytes, and zeroes the buffer.
// @fnv 0x008637d0
FUN_008637d0::FUN_008637d0(unsigned int auiCount)
{
    vtbl = (void**)&DAT_01081f38;
    count = auiCount;
    m = 0;
    unsigned int uiSize = count << 2;
    buf = _NiMalloc(uiSize);
    memset(buf, 0, count << 2);
}
}  // namespace fnv_008637d0

namespace fnv_00863860 {
extern int DAT_01081e70;
struct MyMap
{
    void RemoveAll();
};
struct FUN_008638c0_Class
{
    virtual ~FUN_008638c0_Class();
};
struct FUN_00863860 : FUN_008638c0_Class
{
    virtual ~FUN_00863860();
};
// Destructor that calls RemoveAll on the map stored at the start of the object.
// @fnv 0x00863860
FUN_00863860::~FUN_00863860()
{
    ((MyMap*)this)->RemoveAll();
}
}  // namespace fnv_00863860

void* __cdecl _NiMalloc(unsigned int);
void __cdecl memset(void*, int, unsigned int);
extern int DAT_01081f58;

struct FUN_008638f0
{
    void* m_pVTable;
    unsigned int m_uiSize;
    void* m_pData;
    unsigned int m_uiCount;
    FUN_008638f0(unsigned int uiSize);
};

// Sets the vtable, stores uiSize, allocates uiSize*4 bytes for m_pData, zeroes them, and sets m_uiCount to 0.
// @fnv 0x008638f0
FUN_008638f0::FUN_008638f0(unsigned int uiSize)
{
    m_pVTable = &DAT_01081f58;
    m_uiSize = uiSize;
    m_uiCount = 0;
    unsigned int uiBytes = m_uiSize * 4;
    m_pData = _NiMalloc(uiBytes);
    memset(m_pData, 0, m_uiSize * 4);
}

namespace fnv_008639f0 {
void* __cdecl _NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
extern int DAT_01081f78;
struct FUN_008639f0
{
    void* pVTable;
    unsigned int ItemUpdateArray;
    void* pBuffer;
    void* pElement0;
    FUN_008639f0(unsigned int);
};
// Sets the vtable, stores count, allocates count*4 bytes, and zeroes the buffer.
// @fnv 0x008639f0
FUN_008639f0::FUN_008639f0(unsigned int count)
{
    unsigned int uiSize;
    pVTable = &DAT_01081f78;
    ItemUpdateArray = count;
    pElement0 = 0;
    uiSize = ItemUpdateArray * 4;
    pBuffer = _NiMalloc(uiSize);
    memset(pBuffer, 0, ItemUpdateArray * 4);
}
}  // namespace fnv_008639f0

struct FUN_00c3e860_t
{
    int SumArrayUpToCount(unsigned int);
};
// Sums the int array at this+0x54 from index 0 through count inclusive and returns the total.
// @fnv 0x00c3e860
int FUN_00c3e860_t::SumArrayUpToCount(unsigned int count)
{
    int total = 0;
    for (unsigned int i = 0; i <= count; ++i)
        total = (*(int**)((char*)this + 0x54))[i] + total;
    return total;
}

struct FUN_00854ed0_standin
{
    void* FUN_00854ed0(unsigned int flags);
    void FUN_00854f00();
};

void __cdecl _Deallocate(void* ptr);

// @fnv 0x00854ed0
void* FUN_00854ed0_standin::FUN_00854ed0(unsigned int flags)
{
    FUN_00854f00();

    if (flags & 1)
        _Deallocate(this);

    return this;
}

struct FUN_00854e10
{
    void FUN_00854e10_();
    void* FUN_00854fe0(unsigned int flags);
};

void _Deallocate(void*);

// @fnv 0x00854fe0
void* FUN_00854e10::FUN_00854fe0(unsigned int flags)
{
    FUN_00854e10_();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct ExteriorCellNewReferencesMap
{
    void FUN_00855440();
    void* FUN_00855410(unsigned int flags);
};

void _Deallocate(void*);

// @fnv 0x00855410
void* ExteriorCellNewReferencesMap::FUN_00855410(unsigned int flags)
{
    FUN_00855440();

    if (flags & 1)
        _Deallocate(this);

    return this;
}

struct NumericIDBufferMap
{
    void FUN_008555b0();
    void* FUN_00855580(unsigned int flags);
};

void __cdecl _Deallocate(void*);

// Calls FUN_008555b0, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x00855580
void* NumericIDBufferMap::FUN_00855580(unsigned int flags)
{
    FUN_008555b0();

    if (flags & 1)
        _Deallocate(this);

    return this;
}

struct BaseS
{
    BaseS();
    char m_ucUnknownByte[12];
};

struct FUN_008572f0
{
    FUN_008572f0();
};

struct FUN_00857320
{
    int m_uiFilterValue;
    BaseS m_base;
    FUN_008572f0 m_kMemberDescriptor;

    FUN_00857320();
};

// @fnv 0x00857320
FUN_00857320::FUN_00857320() : m_uiFilterValue(0), m_base(), m_kMemberDescriptor()
{}

namespace fnv_008578b0 {
struct RefList
{
    void FUN_00905330(int& value);
};

struct BSFile
{
    virtual ~BSFile();
    void Close();
};

struct FUN_008578b0_Class
{
    char padding[0x70];
    RefList* pRefList;

    void ReleaseFile(BSFile* file, int type);
};

// @fnv 0x008578b0
void FUN_008578b0_Class::ReleaseFile(BSFile* file, int type)
{
    if (!file)
        return;

    switch (type)
    {
    case 0:
    case 1:
    case 3:
        if (pRefList)
        {
            int value = reinterpret_cast<int>(file);
            pRefList->FUN_00905330(value);
        }
        delete file;
        break;

    case 2:
        file->Close();
        break;
    }
}
}  // namespace fnv_008578b0

namespace fnv_anon_00858480 {}
using namespace fnv_anon_00858480;
namespace fnv_anon_00858480 {
class BSFile
{
};

class TESGlobal : public TESForm
{
  public:
    float GetValue();
};

class BSSimpleListTESRaceSize
{
  public:
    int GetSize();
};

class GlobalListNode : public BSSimpleListTESRaceSize
{
  public:
    TESGlobal** _ref_006815c0();
    GlobalListNode* _ref_00726070();
};

class TESDataHandler
{
  public:
    GlobalListNode* GetTESGlobalList();
};

class EmptyClass
{
};

class FUN_008558a0
{
  public:
    void SetExtraDataString(int, char const*);
};

class FUN_008586a0_class
{
  public:
    void ForwardToFUN_00857b50(int, int, int);
};

class TESSaveLoadGame
{
  public:
    void* FUN_00858600(unsigned int);
    void FUN_00858700(void*);
    void FUN_008579b0(void*, int);
    void FUN_00857a10(int, int);
    void FUN_00858480(BSFile*);
};

extern TESDataHandler* g_dataHandler;

// @fnv 0x00858480
void TESSaveLoadGame::FUN_00858480(BSFile* apFile)
{
    GlobalListNode* pglobals4;
    unsigned short icount3;
    unsigned short isize9;
    void* ptempBuffer2;

    pglobals4 = g_dataHandler->GetTESGlobalList();
    icount3 = static_cast<unsigned short>(pglobals4->GetSize());
    isize9 = static_cast<unsigned short>(icount3 * 8 + 2);

    ptempBuffer2 = this->FUN_00858600(isize9);
    this->FUN_008579b0(&icount3, 2);

    while (pglobals4)
    {
        {
            TESGlobal* pglobal;
            unsigned int iglobalID2;
            float fvalue6;

            pglobal = *pglobals4->_ref_006815c0();
            if (pglobal)
            {
                iglobalID2 = pglobal->GetFormID();
                fvalue6 = pglobal->GetValue();
                this->FUN_00857a10(reinterpret_cast<int>(&iglobalID2), 4);
                this->FUN_008579b0(&fvalue6, 4);
            }
        }
        pglobals4 = pglobals4->_ref_00726070();
    }

    reinterpret_cast<FUN_008586a0_class*>(this)->ForwardToFUN_00857b50(reinterpret_cast<int>(apFile),
                                                                       reinterpret_cast<int>(ptempBuffer2), isize9);

    this->FUN_00858700(ptempBuffer2);

    if (*reinterpret_cast<EmptyClass**>(reinterpret_cast<unsigned char*>(this) + 0x44))
    {
        reinterpret_cast<FUN_008558a0*>(*reinterpret_cast<EmptyClass**>(reinterpret_cast<unsigned char*>(this) + 0x44))
            ->SetExtraDataString(isize9, "Global Variables");
    }
}
}

namespace fnv_0085a3d0 {
class G2
{
  public:
    void AddHead(int*);
};

class LH
{
  public:
    bool IsInList(int&);
};

class TESSaveLoadGameStandIn
{
  public:
    void AddFormToList(TESForm* apForm);
};

// If apForm is not already in the list at offset 0x34, adds it to the head of that list.
// @fnv 0x0085a3d0
void TESSaveLoadGameStandIn::AddFormToList(TESForm* apForm)
{
    if (!reinterpret_cast<LH*>(reinterpret_cast<char*>(this) + 0x34)->IsInList(reinterpret_cast<int&>(apForm)))
    {
        reinterpret_cast<G2*>(reinterpret_cast<char*>(this) + 0x34)->AddHead(reinterpret_cast<int*>(&apForm));
    }
}
}  // namespace fnv_0085a3d0

namespace fnv_00861d10 {
class BSFile
{
};

class Arr : public TESForm
{
  public:
    unsigned int* GetAt(int);
};

class FUN_008558a0
{
  public:
    void SetExtraDataString(int, char const*);
};

class FUN_008586a0_class
{
  public:
    void FUN_00857b50(int, int, int);
};

int(_sprintf_s)(char*, int, char const*, ...);

class TESSaveLoadGame_standin : public FUN_008586a0_class
{
  public:
    char padding_00[0x44];
    FUN_008558a0* m_pSaveGameEntry;
    char padding_48[0x30];
    Arr* m_pLoadingFormRecordHeader;
    Arr* m_pSavingFormIDEntry;

    void WriteFormIDArrays(BSFile*);
};

// @fnv 0x00861d10
void TESSaveLoadGame_standin::WriteFormIDArrays(BSFile* apFile)
{
    unsigned int isize;
    unsigned int uiCount2;

    isize = m_pLoadingFormRecordHeader->GetFormID();
    FUN_008586a0_class::FUN_00857b50(reinterpret_cast<int>(apFile), reinterpret_cast<int>(&isize), 4);

    {
        unsigned int i;

        for (i = 0; i < isize; ++i)
        {
            unsigned int iformID;

            iformID = *m_pLoadingFormRecordHeader->GetAt(i);
            FUN_008586a0_class::FUN_00857b50(reinterpret_cast<int>(apFile), reinterpret_cast<int>(&iformID), 4);
        }
    }

    uiCount2 = m_pSavingFormIDEntry->GetFormID();
    FUN_008586a0_class::FUN_00857b50(reinterpret_cast<int>(apFile), reinterpret_cast<int>(&uiCount2), 4);

    {
        unsigned int i;

        for (i = 0; i < uiCount2; ++i)
        {
            unsigned int iformID;

            iformID = *m_pSavingFormIDEntry->GetAt(i);
            FUN_008586a0_class::FUN_00857b50(reinterpret_cast<int>(apFile), reinterpret_cast<int>(&iformID), 4);
        }
    }

    {
        char acBuffer[260];

        if (m_pSaveGameEntry)
        {
            (_sprintf_s)(acBuffer, 0x104, "Numeric ID Array(%i)", isize);
            m_pSaveGameEntry->SetExtraDataString(isize * 4 + 4, acBuffer);

            (_sprintf_s)(acBuffer, 0x104, "WorldSpace ID Array(%i)", uiCount2);
            m_pSaveGameEntry->SetExtraDataString(uiCount2 * 4 + 4, acBuffer);
        }
    }
}
}  // namespace fnv_00861d10

struct TES
{
    void RefreshWorldState(int, int, int);
};

struct Interface
{
    static bool __cdecl IsGamePaused();
};

struct LLD_TESHelper
{
    void FUN_00861ea0();
};

extern unsigned int DAT_011de464;
extern int g_TES;

__declspec(dllimport) unsigned long __stdcall GetTickCount();

// @fnv 0x00861ea0
void LLD_TESHelper::FUN_00861ea0()
{
    if (GetTickCount() > DAT_011de464 + 0xbb8)
    {
        if (!Interface::IsGamePaused())
        {
            reinterpret_cast<TES*>(g_TES)->RefreshWorldState(1, 0, 0);
        }
    }
}

namespace fnv_00862150 {
struct FUN_00862150File
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual const char* GetPath() = 0;
};

struct FUN_00862150StandIn
{
    char padding[0x1C4];
    char* queuedWeaponPath;

    void FUN_00862150(FUN_00862150File* file);
};

void __cdecl _Deallocate(void* pointer);
int __cdecl BSStringLength(char const* string);
char* __cdecl FUN_004812f0(char const* string, char const* characters);
bool __fastcall FUN_008905f0(bool* object);

class TaskQueueInterface
{
  public:
    static void __cdecl CopyStringToBuffer(char* output, unsigned int capacity, char const* input);
};

// @fnv 0x00862150
void FUN_00862150StandIn::FUN_00862150(FUN_00862150File* file)
{
    if (queuedWeaponPath)
    {
        _Deallocate(queuedWeaponPath);
        queuedWeaponPath = 0;
    }

    if (file != 0)
    {
        if (FUN_008905f0(reinterpret_cast<bool*>(file)) != 0)
        {
            const char* currentPath = file->GetPath();
            char* found = FUN_004812f0(currentPath, "\\");

            while (found)
            {
                currentPath = found + 1;
                found = FUN_004812f0(currentPath, "\\");
            }

            char queuedName[260];
            TaskQueueInterface::CopyStringToBuffer(queuedName, 260, currentPath);

            int queuedNameLength = BSStringLength(queuedName);
            queuedName[queuedNameLength - 4] = 0;

            int allocationSize = BSStringLength(queuedName) + 1;
            queuedWeaponPath = static_cast<char*>(::operator new(allocationSize));

            TaskQueueInterface::CopyStringToBuffer(queuedWeaponPath, allocationSize, queuedName);
        }
    }
}
}  // namespace fnv_00862150

struct FUN_00863510Class
{
    void FUN_00863960();
    void* FUN_00863510(unsigned int flags);
};

void _Deallocate(void* ptr);

// Calls FUN_00863960, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00863510
void* FUN_00863510Class::FUN_00863510(unsigned int flags)
{
    FUN_00863960();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00863ea0_StandIn
{
    void FUN_00863ea0();
};

struct FUN_00863570_StandIn : public FUN_00863ea0_StandIn
{
    void* FUN_00863570(unsigned int flags);
};

void __cdecl _Deallocate(void*);

// @fnv 0x00863570
void* FUN_00863570_StandIn::FUN_00863570(unsigned int flags)
{
    this->FUN_00863ea0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00c41330_holder
{
    void FUN_00c41330(int);
};

struct FUN_00c3ea10_holder
{
    void FUN_00c3ea10();
};

// Sets the count at offset 0xc to 0, then calls FUN_00c41330(0) on each of the first count elements of the array at offset 4.
// @fnv 0x00c3ea10
void FUN_00c3ea10_holder::FUN_00c3ea10()
{
    unsigned int i;
    *(int*)((char*)this + 0xc) = 0;
    for (i = 0; i < *(unsigned int*)((char*)this + 8); ++i)
    {
        ((FUN_00c41330_holder**)*(void**)((char*)this + 4))[i]->FUN_00c41330(0);
    }
}

class FUN_00854f00_base
{
  public:
    virtual ~FUN_00854f00_base();
};

class FUN_00854f00_cls : public FUN_00854f00_base
{
  public:
    virtual ~FUN_00854f00_cls();
    void DeleteAllEntries();
};

// Destructor that calls DeleteAllEntries before the object is destroyed.
// @fnv 0x00854f00
FUN_00854f00_cls::~FUN_00854f00_cls()
{
    DeleteAllEntries();
}

struct Form_00855010
{
    void* FUN_0084e3a0();
};
struct Guard_00855010
{
    int unk00;
    Guard_00855010(int a, int b, const char* file, int line);
    ~Guard_00855010();
};
struct Node_00855010
{
    unsigned int unk00;
    unsigned int unk04;
    Node_00855010();
    void FUN_00854e40(unsigned int a);
};
struct FUN_00855010_cls
{
    bool GetAt(void* r1, Node_00855010** out);
    void FUN_00844700(void* r1, Node_00855010* out);
    void* GetOrCreateNode(void* a1, unsigned int a2);
};

Guard_00855010::Guard_00855010(int a, int b, const char* file, int line)
{}
Guard_00855010::~Guard_00855010()
{}
Node_00855010::Node_00855010()
{}

// Looks up a node for the form via GetAt, creates and registers one if missing, then calls FUN_00854e40 with a2 and returns it.
// @fnv 0x00855010
void* FUN_00855010_cls::GetOrCreateNode(void* pForm, unsigned int uiValue)
{
    void* out = reinterpret_cast<Form_00855010*>(pForm)->FUN_0084e3a0();
    Node_00855010* r1;
    {
        bool found = GetAt(out, &r1);
        if (!found)
        {
            Guard_00855010 g(0x11, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESSaveLoadGame.cpp",
                             0x104);
            r1 = new Node_00855010;
            FUN_00844700(out, r1);
        }
    }
    r1->FUN_00854e40(uiValue);
    return r1;
}

struct Cell00855310
{
    void FUN_00470470();
    unsigned int FUN_004702f0(int flags);
};

struct Base00855310
{
    virtual ~Base00855310();
};

struct FUN_00855310_cls : Base00855310
{
    void* FUN_004b9ba0();
    void FUN_006b7f20(void** node, unsigned int* b, Cell00855310** c);
    void FUN_00438af0();
    virtual ~FUN_00855310_cls();
};

// @fnv 0x00855310
FUN_00855310_cls::~FUN_00855310_cls()
{
    void* node7;
    unsigned int b8;
    Cell00855310* c3;

    node7 = FUN_004b9ba0();
    while (node7 != 0)
    {
        c3 = 0;
        b8 = 0;
        FUN_006b7f20(&node7, &b8, &c3);
        if (c3 != 0)
        {
            c3->FUN_00470470();
            Cell00855310* t = c3;
            Cell00855310* u = t;
            (u != 0) ? u->FUN_004702f0(1) : 0;
        }
    }
    FUN_00438af0();
}

struct ScopeLock_855970
{
    unsigned int m_unk00;
    ScopeLock_855970(int a, int b, const char* file, int line);
    ~ScopeLock_855970();
};

struct Key_855970
{
    Key_855970();
    unsigned int unk00;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned short unk0a;
};

struct Owner_855970
{
    void Apply(Key_855970* key);
};

struct FUN_00855970_cls
{
    Owner_855970 owner;
    void ApplyKeyWithFlags(Key_855970* src, unsigned short flags);
};

// Copies the key fields from src into a local key, stores flags into its unk0a, and applies it to owner under a scope lock.
// @fnv 0x00855970
void FUN_00855970_cls::ApplyKeyWithFlags(Key_855970* pSrcKey, unsigned short flags)
{
    ScopeLock_855970 lock(0x11, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESSaveLoadGame.cpp",
                          0x276);
    Key_855970 key;
    *(unsigned int*)&key.unk05 = *(unsigned int*)&pSrcKey->unk05;
    key.unk00 = pSrcKey->unk00;
    key.unk04 = pSrcKey->unk04;
    key.unk09 = pSrcKey->unk09;
    key.unk0a = flags;
    owner.Apply(&key);
}

struct SubObj572
{
    void FUN_008572f0();
};

struct FUN_008572c0_cls
{
    unsigned int m_00;
    unsigned int m_04;
    SubObj572 m_08;
    FUN_008572c0_cls* FUN_008572c0();
};

// Clears m_00 and m_04 to zero, calls FUN_008572f0 on m_08, and returns this.
// @fnv 0x008572c0
FUN_008572c0_cls* FUN_008572c0_cls::FUN_008572c0()
{
    m_00 = 0;
    m_04 = 0;
    m_08.FUN_008572f0();
    return this;
}

class B8572F0Member
{
  public:
    B8572F0Member();

    int unk00;
    int unk04;
    int unk08;
};

class FUN_008572f0_cls
{
  public:
    FUN_008572f0_cls();

    int m_iArrayLength;
    B8572F0Member m_kFirst;
    B8572F0Member m_kSecond;
};

// @fnv 0x008572f0
FUN_008572f0_cls::FUN_008572f0_cls() : m_iArrayLength(0)
{}

class C857370
{
  public:
    int* __thiscall OpenSaveFile(int*, int, int);
};
class C8578b0
{
  public:
    void __thiscall ReleaseFile(int*, int);
};
class C857950
{
  public:
    void __thiscall FUN_00857950(int* a, int b);
};

void __cdecl FUN_00aff0b0(int);

// @fnv 0x00857950
void __thiscall C857950::FUN_00857950(int* pObject, int b)
{
    int* p;
    if (pObject == 0)
        return;
    p = ((C857370*)this)->OpenSaveFile(pObject, b, 3);
    if (p == 0)
        p = pObject;
    FUN_00aff0b0((*(int(__thiscall**)(int*))(*(int**)p + 6))(p));
    ((C8578b0*)this)->ReleaseFile(p, 3);
}

extern int DAT_01183028;
extern int DAT_011841cc;
extern int DAT_01183fb4;
extern "C" int __cdecl FUN_00ec43fb(unsigned int a, unsigned int b, void* c, void* d, unsigned int e);

struct FUN_0085a450_cls
{
    int FUN_0085a450(unsigned int a1, unsigned int a2);
};

// Calls FUN_00ec43fb twice with DAT_01183028 and DAT_011841cc/DAT_01183fb4, then returns a code derived from a2 and the results.
// @fnv 0x0085a450
int FUN_0085a450_cls::FUN_0085a450(unsigned int a1, unsigned int auiFlags)
{
    int r1 = FUN_00ec43fb(a1, 0, &DAT_01183028, &DAT_011841cc, 0);
    if (r1 == 0)
    {
        int r2 = FUN_00ec43fb(a1, 0, &DAT_01183028, &DAT_01183fb4, 0);
        if (r2 != 0)
        {
            if ((auiFlags & 0) != 0)
                return 4;
            else
            {
                if ((auiFlags & 0) != 0)
                    return 6;
                else
                    return 0;
            }
        }
    }
    if (r1 != 0)
    {
        if ((auiFlags & 0) != 0)
            return 0x24;
        if ((auiFlags & 6) != 0)
        {
            if ((auiFlags & 0) != 0)
                return 0x2c;
            else
                return 0x1c;
        }
        if ((auiFlags & 0) != 0)
            return 4;
    }
    return 0;
}

struct FUN_0085b240_ref
{
    int FUN_004720a0();
};
struct FUN_0085b240_node
{
    void* FUN_00891170();
};
struct FUN_0085b240_att
{
    void SetExtraDataString(int iExtraID, const char* pString);
};
struct FUN_0085b240_mgr
{
    unsigned char FUN_0051f550();
    FUN_0085b240_node* FUN_00465010(unsigned int i);
};
extern FUN_0085b240_mgr* DAT_011c3f2c;
unsigned char __cdecl FUN_0044a670(void* p);

struct FUN_0085b240_cls
{
    unsigned int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c, m_40;
    int m_44;
    void FUN_00857b50(void* a, void* b, int c);
    void WritePluginList(FUN_0085b240_ref* a1);
};

// @fnv 0x0085b240
void FUN_0085b240_cls::WritePluginList(FUN_0085b240_ref* a1)
{
    unsigned char i;
    unsigned char flag9 = DAT_011c3f2c->FUN_0051f550();
    int iStartPos = 0;
    unsigned char flagA;
    if (this->m_44 != 0)
    {
        iStartPos = a1->FUN_004720a0();
    }
    FUN_00857b50(a1, &flag9, 1);
    for (i = 0; i < flag9; i++)
    {
        FUN_0085b240_node* pNode = DAT_011c3f2c->FUN_00465010(i);
        {
            void* pData = pNode->FUN_00891170();
            flagA = FUN_0044a670(pData);
            FUN_00857b50(a1, &flagA, 1);
            FUN_00857b50(a1, pData, flagA);
        }
    }
    if (this->m_44 != 0)
    {
        reinterpret_cast<FUN_0085b240_att*>(this->m_44)
            ->SetExtraDataString(a1->FUN_004720a0() - iStartPos, "Plugin List");
    }
}

struct Collection_00861c60
{
    unsigned int FUN_0084e3a0();
    unsigned int* FUN_00877a30(unsigned int index);
    unsigned short FUN_00863d90(const unsigned int& value);
};
struct FUN_00861c60_shell
{
    unsigned int unknown_0;
    unsigned int unknown_4;
    unsigned int unknown_8;
    unsigned int unknown_c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    Collection_00861c60* collection;
    unsigned short FUN_00861c60(unsigned int value);
};
// @fnv 0x00861c60
unsigned short FUN_00861c60_shell::FUN_00861c60(unsigned int value)
{
    unsigned int count = collection->FUN_0084e3a0();
    for (unsigned int index = 0; index < count; ++index)
    {
        unsigned int currentValue = *collection->FUN_00877a30(index);
        if (currentValue == value)
            return static_cast<unsigned short>(index);
    }
    return collection->FUN_00863d90(value);
}

extern "C" char DAT_01081cf0[];
extern "C" void __cdecl FUN_005b5e40(char*, unsigned char, unsigned int);

struct FUN_00861ee0_Class
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
    unsigned char unk80;

    void __thiscall FUN_00861ee0(unsigned char value);
};

// If value is below 0x13, calls FUN_005b5e40 with DAT_01081cf0, value and 0x13, then stores value in unk80.
// @fnv 0x00861ee0
void __thiscall FUN_00861ee0_Class::FUN_00861ee0(unsigned char value)
{
    if (value < 0x13)
        FUN_005b5e40(DAT_01081cf0, value, 0x13);

    unk80 = value;
}

struct NiPoint3
{
    float x, y, z;
};

class TESObjectCELL
{
  public:
    void FUN_0054b5b0();
};

struct TES_861f20
{
    unsigned int GetGlobalInt();
    TESObjectCELL* CurCell_861f20();
    TESObjectCELL* FUN_00459470(unsigned int);
};

struct TESBoundObject;
struct TESWorldSpace;

struct TESObjectREFR_861f20
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
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
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual NiPoint3* GetPos();
    TESWorldSpace* GetParentWorldSpace();
    void* GetContainingCell(TESWorldSpace*);
    const NiPoint3& GetAngle();
    void SetLocationOnReference(const NiPoint3&);
};

struct DataHandler_861f20
{
    TESObjectREFR_861f20* CreateRef(TESBoundObject*, NiPoint3*, const NiPoint3&, void*, int, int, int);
};

extern int g_TES;
extern TESBoundObject* g_pLockpickItem;
extern TESObjectREFR_861f20* g_player_861f20;
extern DataHandler_861f20* g_dh_861f20;
extern int DAT_011de500;

int sprintf_s(char*, unsigned int, const char*, ...);

struct TESSaveLoadGame_861f20
{
    void SaveGame(int, const char*, int);
    void FUN_00861f20(int aiType);
};

// @fnv 0x00861f20
void TESSaveLoadGame_861f20::FUN_00861f20(int aiType)
{
    if (aiType == 4 || aiType == 5)
    {
        if (aiType == 5)
        {
            TESBoundObject* pObj8;
            unsigned int kUiCount;
            unsigned int iA;
            TESObjectCELL* pCell9;
            unsigned int j3;
            TESObjectREFR_861f20* pRef3;
            NiPoint3 kPos;
            kUiCount = ((TES_861f20*)g_TES)->GetGlobalInt();
            if (((TES_861f20*)g_TES)->CurCell_861f20())
                kUiCount = 1;
            for (iA = 0; iA < kUiCount; iA++)
            {
                pCell9 = ((TES_861f20*)g_TES)->CurCell_861f20();
                if (!pCell9)
                    pCell9 = ((TES_861f20*)g_TES)->FUN_00459470(iA);
                if (pCell9)
                    pCell9->FUN_0054b5b0();
            }
            pObj8 = g_pLockpickItem;
            for (j3 = 0; j3 < 5; j3++)
            {
                pRef3 = g_dh_861f20->CreateRef(pObj8, g_player_861f20->GetPos(), g_player_861f20->GetAngle(),
                                               g_player_861f20->GetContainingCell(g_player_861f20->GetParentWorldSpace()), 0,
                                               0, 0);
                kPos = *pRef3->GetPos();
                kPos.z += 1000.0;
                pRef3->SetLocationOnReference(kPos);
            }
        }
        if (DAT_011de500 % 50 == 0)
        {
            char acName[260];
            sprintf_s(acName, 260, "Test All Cells %i.ess", DAT_011de500);
            SaveGame(0, acName, 1);
        }
        DAT_011de500++;
    }
}

struct FUN_008df040_cls
{
    unsigned char FUN_008df040();
};

extern FUN_008df040_cls* DAT_011de45c;

struct FUN_00862110_cls
{
    int unk00;
    bool FUN_00862110();
};

// @fnv 0x00862110
bool FUN_00862110_cls::FUN_00862110()
{
    if (DAT_011de45c->FUN_008df040() >= 0x1f)
    {
        if (DAT_011de45c->FUN_008df040() < 0x5a)
        {
            return true;
        }
    }
    return false;
}

struct Rec8623
{
    void* form;
};

struct Map8623
{
    unsigned int Count();
    Rec8623** At(unsigned int index);
    void RemoveAt(unsigned int index);
};

void __cdecl DeleteRec8623(Rec8623* rec);

struct TESSL8623
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    Map8623* m_changes;
    void FUN_008623a0(void* form);
};

// Scans m_changes for the record whose form matches form, removes it from the map and deletes it.
// @fnv 0x008623a0
void TESSL8623::FUN_008623a0(void* form)
{
    if (m_changes != 0)
    {
        unsigned int count = m_changes->Count();
        for (unsigned int i = 0; i < count; i++)
        {
            Rec8623* rec = *m_changes->At(i);
            if (rec != 0 && rec->form == form)
            {
                m_changes->RemoveAt(i);
                Rec8623* del = rec;
                DeleteRec8623(del);
                return;
            }
        }
    }
}

struct FUN_008634b0_Class
{
    void __thiscall FUN_00863740();
    void* __thiscall FUN_008634b0(unsigned int flags);
};
// Calls FUN_00863740, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x008634b0
void* FUN_008634b0_Class::FUN_008634b0(unsigned int flags)
{
    FUN_00863740();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_00863a60_Node
{
    FUN_00863a60_Node* next;
    unsigned char key;
    int value;
};

struct FUN_00863a60_Class
{
    virtual void vf00();
    virtual int vf04(int index);
    virtual bool vf08(int key, unsigned char nodeKey);
    virtual void vf0c(void* node, unsigned char key, int value);
    virtual void vf10();
    virtual void* vf14();

    int unk04;
    FUN_00863a60_Node** nodes;
    int count;

    void __thiscall FUN_00863a60(unsigned char key, int value);
};

// Empty inline virtual stub; the class's first vtable slot, defined with no body.
// @fnv 0x00863a60
inline void FUN_00863a60_Class::vf00()
{}
inline int FUN_00863a60_Class::vf04(int)
{
    return 0;
}
inline bool FUN_00863a60_Class::vf08(int, unsigned char)
{
    return false;
}
inline void FUN_00863a60_Class::vf0c(void*, unsigned char, int)
{}
inline void FUN_00863a60_Class::vf10()
{}
inline void* FUN_00863a60_Class::vf14()
{
    return 0;
}

void __thiscall FUN_00863a60_Class::FUN_00863a60(unsigned char key, int value)
{
    int counter = this->vf04(key);
    FUN_00863a60_Node* node = this->nodes[counter];
    int index = 0;

    while (node != 0)
    {
        ++index;

        if (this->vf08(key, node->key))
        {
            node->value = value;
            return;
        }

        node = node->next;
    }

    node = static_cast<FUN_00863a60_Node*>(this->vf14());
    this->vf0c(node, key, value);
    node->next = this->nodes[counter];
    this->nodes[counter] = node;
    ++this->count;
}

struct FUN_00863b40_Node
{
    FUN_00863b40_Node* next;
    unsigned char key;
    int value;
};

struct FUN_00863b40_Class
{
    virtual void vf00();
    virtual int vf04(unsigned char key);
    virtual bool vf08(unsigned char key, unsigned char nodeKey);

    int unk04;
    FUN_00863b40_Node** nodes;

    bool __thiscall FUN_00863b40(unsigned char key, int* result);
};

// @fnv 0x00863b40
inline void FUN_00863b40_Class::vf00()
{}
inline int FUN_00863b40_Class::vf04(unsigned char)
{
    return 0;
}
inline bool FUN_00863b40_Class::vf08(unsigned char, unsigned char)
{
    return false;
}

bool __thiscall FUN_00863b40_Class::FUN_00863b40(unsigned char key, int* result)
{
    int counter = this->vf04(key);
    FUN_00863b40_Node* node = this->nodes[counter];

    while (node != 0)
    {
        if (this->vf08(key, node->key))
        {
            *result = node->value;
            return true;
        }

        node = node->next;
    }

    return false;
}

struct Item_00863bc0
{
    Item_00863bc0* m_pkNext;
    unsigned char m_key;
    unsigned int m_val;
};

struct Map_00863bc0
{
    virtual void Vfn0() = 0;
    virtual unsigned int Hash(unsigned char key) = 0;
    unsigned int m_uiCount;
    Item_00863bc0** m_ppBuckets;
    void GetNextItem(Item_00863bc0*& item, unsigned char& key, unsigned int& val);
};

// Outputs the item's key and value, then advances item to the next chained item or the next non-empty bucket, or null.
// @fnv 0x00863bc0
void Map_00863bc0::GetNextItem(Item_00863bc0*& item, unsigned char& key, unsigned int& val)
{
    Item_00863bc0* pkItem = item;
    unsigned int uiIndex;
    key = pkItem->m_key;
    val = pkItem->m_val;
    if (pkItem->m_pkNext != 0)
    {
        item = pkItem->m_pkNext;
        return;
    }
    uiIndex = Hash(pkItem->m_key);
    uiIndex++;
    for (; uiIndex < m_uiCount; uiIndex++)
    {
        pkItem = m_ppBuckets[uiIndex];
        if (pkItem != 0)
        {
            item = pkItem;
            return;
        }
    }
    item = 0;
}

class B63CD0MapBase
{
  public:
    virtual ~B63CD0MapBase();

    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_00863cd0 : public B63CD0MapBase
{
  public:
    virtual ~FUN_00863cd0();
};

// Destructor that calls RemoveAll to clear the hash table entries.
// @fnv 0x00863cd0
FUN_00863cd0::~FUN_00863cd0()
{
    RemoveAll();
}

// FUN_00c3e340
struct FUN_00c3e340_cls
{
    char pad_00[0x80];
    void(__thiscall* m_pFn)();
    bool ReleaseAndCleanup();
    void FUN_00c3e340();
};

// Calls m_pFn if ReleaseAndCleanup returns true and m_pFn is non-null.
// @fnv 0x00c3e340
void FUN_00c3e340_cls::FUN_00c3e340()
{
    if (this->ReleaseAndCleanup() && this->m_pFn != 0)
    {
        this->m_pFn();
    }
}

class C3E3A0Table
{
  public:
    int FUN_00c3e3a0(__int64 iKey);
};

// @fnv 0x00c3e3a0
int C3E3A0Table::FUN_00c3e3a0(__int64 iKey)
{
    unsigned char m_ucClipIdentifier = (unsigned char)(iKey >> 16);
    return m_ucClipIdentifier * (((unsigned char)(iKey >> 56) + 4) % 20);
}

// FUN_00c3e3f0 : thiscall member (1 stack parameter), /Od.
// Calls a member helper on this, then when the flag parameter has bit 0 set it
// hands this to the spawn heap manager, and finally returns this.

struct FUN_00c3e3f0_cls
{
    void FUN_00c3db60();
    FUN_00c3e3f0_cls* FUN_00c3e3f0(int iFlags);
};

struct SpawnHeap_cls
{
    void __thiscall FUN_00aa4060(void* pObject);
};

extern "C" char DAT_011f6238;

// @fnv 0x00c3e3f0
FUN_00c3e3f0_cls* FUN_00c3e3f0_cls::FUN_00c3e3f0(int iFlags)
{
    this->FUN_00c3db60();
    if (iFlags & 1)
        reinterpret_cast<SpawnHeap_cls*>(&DAT_011f6238)->FUN_00aa4060(this);
    return this;
}

struct Elem00c3e420
{
    bool FUN_00c3e490(int arg);
};

struct Container00c3e420
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    Elem00c3e420** items;
    unsigned int count;
    bool FUN_00c3e420(int arg);
};

// Iterates the container's items and returns true as soon as an item's FUN_00c3e490(arg) check succeeds, otherwise false.
// @fnv 0x00c3e420
bool Container00c3e420::FUN_00c3e420(int arg)
{
    for (unsigned int i = 0; i < count; i++)
    {
        int depth;
        int max;
        int node;
        int pos;
        int state;
        int str;
        int addr;
        int item;
        int src;
        int delta;
        int result;
        bool b = items[i]->FUN_00c3e490(arg);
        if (b)
        {
            v2();
            return true;
        }
    }
    return false;
}

class ChangeEntry854f60
{
  public:
    ~ChangeEntry854f60();

    int unk00;
    int unk04;
};

class ChangesMap854f60
{
  public:
    void* GetFirstPos();
    void GetNext(void*& rkPos, unsigned int& ruiFormID, ChangeEntry854f60*& rpkVal);
    void RemoveAll();
};

class ChangesMapOwner854f60 : public ChangesMap854f60
{
  public:
    void DeleteAllEntries();
};

// Iterates the map's entries, deletes each ChangeEntry, then calls RemoveAll to clear the map.
// @fnv 0x00854f60
void ChangesMapOwner854f60::DeleteAllEntries()
{
    void* pkPos = GetFirstPos();
    while (pkPos)
    {
        ChangeEntry854f60* pkChange = 0;
        unsigned int auiFormId = 0;
        GetNext(pkPos, auiFormId, pkChange);
        delete pkChange;
    }
    RemoveAll();
}

struct RefItem
{
    unsigned int unk00;
};

struct RefListNode
{
    RefItem*& Item();
    RefListNode* Next();
    void RemoveAll();
    ~RefListNode();
};

struct CellRefMapBase
{
    virtual ~CellRefMapBase();
    void* GetFirstPos();
    void GetNext(void*& pos, unsigned int& key, RefListNode*& val);
    void RemoveAll();
};

struct FUN_00855440 : CellRefMapBase
{
    virtual ~FUN_00855440();
};

// Destructor: walks every entry of the map, deletes each RefItem and its RefListNode list, then clears the map.
// @fnv 0x00855440
FUN_00855440::~FUN_00855440()
{
    void* pos = GetFirstPos();
    while (pos)
    {
        RefListNode* list = 0;
        unsigned int key = 0;
        GetNext(pos, key, list);
        RefListNode* node = list;
        if (list)
        {
            while (node)
            {
                RefItem* item = node->Item();
                if (item)
                    delete item;
                node = node->Next();
            }
            list->RemoveAll();
            delete list;
        }
    }
    RemoveAll();
}

struct Base008555b0
{
    virtual ~Base008555b0();
};

struct FUN_008555b0_cls : Base008555b0
{
    void* FUN_004b9ba0();
    void FUN_006b7f20(void** node, unsigned int* b, void** c);
    void FUN_00438af0();
    virtual ~FUN_008555b0_cls();
};

// @fnv 0x008555b0
FUN_008555b0_cls::~FUN_008555b0_cls()
{
    void* node7;
    unsigned int b8;
    void* c3;

    node7 = FUN_004b9ba0();
    while (node7 != 0)
    {
        c3 = 0;
        b8 = 0;
        FUN_006b7f20(&node7, &b8, &c3);
        if (c3 != 0)
        {
            _Deallocate(c3);
        }
    }
    FUN_00438af0();
}

struct CellItem;
struct OwnedBuffer
{
    void* m_pData;
    void* m_pBuffer;
};
struct List_009e03e0
{
    void* m_item;
    List_009e03e0* m_pkNext;
    ~List_009e03e0();
    void*& FUN_006815c0();
    List_009e03e0* FUN_00726070();
    void RemoveAll();
};
class NiTMap
{
  public:
    virtual ~NiTMap();
    void* GetFirstPos();
    void GetNextItem(void*& pos, unsigned char& key, List_009e03e0*& val);
};
struct FUN_00855730_shell
{
    NiTMap* m_pMapObject;
    List_009e03e0* m_pEntries;
    void DestroyMapAndLists();
};
// Iterates the map's entries, deleting each list's items and the list, then deletes the map and frees the buffers in the second list.
// @fnv 0x00855730
void FUN_00855730_shell::DestroyMapAndLists()
{
    void* posCur = m_pMapObject->GetFirstPos();
    while (posCur)
    {
        unsigned char key;
        List_009e03e0* pList;
        m_pMapObject->GetNextItem(posCur, key, pList);
        List_009e03e0* pIter_ = pList;
        if (pList)
        {
            while (pIter_)
            {
                CellItem* pItem = (CellItem*)pIter_->FUN_006815c0();
                pIter_ = pIter_->FUN_00726070();
                if (pItem)
                    delete pItem;
            }
            pList->RemoveAll();
            delete pList;
        }
    }
    delete m_pMapObject;
    List_009e03e0* pIter = m_pEntries;
    if (m_pEntries)
    {
        while (pIter)
        {
            OwnedBuffer* pBuf = (OwnedBuffer*)pIter->FUN_006815c0();
            if (pBuf)
            {
                operator delete(pBuf->m_pBuffer);
                delete pBuf;
            }
            pIter = pIter->FUN_00726070();
        }
        m_pEntries->RemoveAll();
        delete m_pEntries;
    }
}

extern const char DAT_010804c8[];

struct FUN_006815c0
{
    unsigned int itemId;
    unsigned int flags;
    unsigned int next;
    FUN_006815c0();
};

struct FUN_0096a2d0
{
    unsigned int first;
    unsigned int second;
    FUN_0096a2d0();
    void FUN_007a7eb0(FUN_006815c0*, int (*callback)(unsigned short*, unsigned short*));
};

struct ReferenceMap
{
    bool FUN_00863b40(unsigned char id, FUN_0096a2d0** out);
    void FUN_00863a60(unsigned char id, FUN_0096a2d0* entry);
};

struct FUN_00855a20_This
{
    ReferenceMap* references;
    void AddReferenceRecord(const FUN_006815c0* input);
};

// @fnv 0x00855a20
void FUN_00855a20_This::AddReferenceRecord(const FUN_006815c0* apRecord)
{
    AutoMemHelper frame9(0x11, true, DAT_010804c8, 0x286);
    FUN_006815c0* record = new FUN_006815c0;
    *record = *apRecord;
    unsigned char id8 = (unsigned char)record->flags;
    FUN_0096a2d0* bucket6;
    bool found4 = references->FUN_00863b40(id8, &bucket6);
    if (!found4)
    {
        bucket6 = new FUN_0096a2d0;
        references->FUN_00863a60(id8, bucket6);
    }
    bucket6->FUN_007a7eb0(record, CompareByIndex5);
}

namespace SaveManager {
struct String
{
    unsigned int unk0, unk4;
    String();
    ~String();
};
struct Changes
{
    unsigned int unk0, unk4, unk8, unkc;
    Changes();
};
struct References
{
    unsigned int unk0, unk4, unk8, unkc;
    References();
};
struct Forms
{
    unsigned int unk0, unk4, unk8, unkc;
    Forms();
};
struct Entries
{
    unsigned int unk0, unk4, unk8, unkc;
    Entries();
};
struct Array
{
    unsigned int unk0, unk4, unk8, unkc, unk10, unk14;
    Array(unsigned int, unsigned int);
    void FUN_00864240(unsigned int, const unsigned int&);
};
struct Scope
{
    unsigned int unk0;
    Scope(int, int, const char*, int);
    ~Scope();
};
extern char DAT_010804c8;
struct FUN_00856380;
extern FUN_00856380* DAT_011de45c;
void FUN_00403d30(void*, int, unsigned int);
struct FUN_00856380
{
    Changes* changes;
    unsigned int unk4;
    References* refs;
    Forms* forms;
    Forms* otherForms;
    unsigned int unk14;
    unsigned int unk18;
    bool b1c;
    char unk1d, unk1e, unk1f;
    unsigned int unk20;
    String s24;
    String s2c;
    String s34;
    String s3c;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    Entries* e58;
    Entries* e5c;
    Entries* e60;
    Entries* e64;
    String s68;
    unsigned int unk70;
    bool b74, b75;
    char unk76, unk77;
    Array* a78;
    Array* a7c;
    char unk80;
    bool b81;
    char unk82, unk83;
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
    bool bac, bad, bae, baf;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    FUN_00856380();
    void FUN_008620f0();
    void CopyByteToOffset80();
};
// Initialises the save manager singleton: allocates changes, references, forms, entries and arrays, zeroes fields, and calls FUN_008620f0 and CopyByteToOffset80.
// @fnv 0x00856380
FUN_00856380::FUN_00856380()
    : unk4(0), refs(0), forms(0), unk14(0), unk18(0), b1c(false), unk20(0), unk44(0), unk50(0), unk54(0), unk70(0),
      b74(false), b75(false), b81(true), unk84(0), unk88(0), unk8c(0), unk90(0), unk94(0), unka8(0), bac(false),
      bad(false), bae(false), baf(false), unkb0(0), unk1c4(0)
{
    Scope scope(0x11, 1, &DAT_010804c8, 0x35f);
    DAT_011de45c = this;
    changes = new Changes;
    refs = new References;
    forms = new Forms;
    otherForms = new Forms;
    e58 = new Entries;
    e5c = new Entries;
    e60 = new Entries;
    e64 = new Entries;
    a78 = new Array(100, 50);
    a78->FUN_00864240(0, 0);
    a7c = new Array(5, 1);
    a7c->FUN_00864240(0, 0);
    FUN_00403d30(&unk98, 0, 16);
    FUN_008620f0();
    CopyByteToOffset80();
}
}

namespace fnv_00856870 {
struct OwnedObject856870
{
    virtual ~OwnedObject856870();
    void ClearItems();
};
struct IntList
{
    unsigned int value;
    IntList* next;
    ~IntList();
    void FUN_00470470();
};
struct List_009e03e0
{
    ~List_009e03e0();
    bool FUN_008256d0();
    OwnedObject856870** FUN_006815c0();
    void FUN_00905330(OwnedObject856870**);
};
struct FUN_00856870
{
    ~FUN_00856870();
    OwnedObject856870* field00;
    unsigned int field04;
    OwnedObject856870* field08;
    OwnedObject856870* field0c;
    OwnedObject856870* field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    IntList field24;
    IntList field2c;
    IntList field34;
    IntList field3c;
    unsigned int field44;
    unsigned int field48;
    unsigned int field4c;
    char* field50;
    unsigned int field54;
    OwnedObject856870* field58;
    OwnedObject856870* field5c;
    OwnedObject856870* field60;
    OwnedObject856870* field64;
    IntList field68;
    List_009e03e0* field70;
    unsigned int field74;
    OwnedObject856870* field78;
    OwnedObject856870* field7c;
    unsigned int field80;
    unsigned int field84;
    unsigned int field88;
    unsigned int field8c;
    unsigned int field90;
    unsigned int field94;
    unsigned int field98;
    unsigned int field9c;
    unsigned int fielda0;
    unsigned int fielda4;
    unsigned int fielda8;
    unsigned int fieldac;
    unsigned int fieldb0;
    unsigned int fieldb4;
    unsigned int fieldb8;
    unsigned int fieldbc;
    unsigned int fieldc0;
    unsigned int fieldc4;
    unsigned int fieldc8;
    unsigned int fieldcc;
    unsigned int fieldd0;
    unsigned int fieldd4;
    unsigned int fieldd8;
    unsigned int fielddc;
    unsigned int fielde0;
    unsigned int fielde4;
    unsigned int fielde8;
    unsigned int fieldec;
    unsigned int fieldf0;
    unsigned int fieldf4;
    unsigned int fieldf8;
    unsigned int fieldfc;
    unsigned int field100;
    unsigned int field104;
    unsigned int field108;
    unsigned int field10c;
    unsigned int field110;
    unsigned int field114;
    unsigned int field118;
    unsigned int field11c;
    unsigned int field120;
    unsigned int field124;
    unsigned int field128;
    unsigned int field12c;
    unsigned int field130;
    unsigned int field134;
    unsigned int field138;
    unsigned int field13c;
    unsigned int field140;
    unsigned int field144;
    unsigned int field148;
    unsigned int field14c;
    unsigned int field150;
    unsigned int field154;
    unsigned int field158;
    unsigned int field15c;
    unsigned int field160;
    unsigned int field164;
    unsigned int field168;
    unsigned int field16c;
    unsigned int field170;
    unsigned int field174;
    unsigned int field178;
    unsigned int field17c;
    unsigned int field180;
    unsigned int field184;
    unsigned int field188;
    unsigned int field18c;
    unsigned int field190;
    unsigned int field194;
    unsigned int field198;
    unsigned int field19c;
    unsigned int field1a0;
    unsigned int field1a4;
    unsigned int field1a8;
    unsigned int field1ac;
    unsigned int field1b0;
    unsigned int field1b4;
    unsigned int field1b8;
    unsigned int field1bc;
    unsigned int field1c0;
    void* field1c4;
};
// Destructor that deletes owned objects in fields, drains and deletes field70's list, frees field1c4, and cleans up the field24 and field2c lists.
// @fnv 0x00856870
FUN_00856870::~FUN_00856870()
{
    if (field00)
        delete field00;
    if (field08)
        delete field08;
    if (field0c)
        delete field0c;
    if (field10)
        delete field10;
    if (field50)
        delete field50;
    if (field58)
        delete field58;
    if (field5c)
        delete field5c;
    if (field60)
        delete field60;
    if (field64)
        delete field64;
    if (field78)
    {
        field78->ClearItems();
        delete field78;
    }
    if (field7c)
    {
        field7c->ClearItems();
        delete field7c;
    }
    if (field1c4)
        _Deallocate(field1c4);
    if (field70)
    {
        while (!field70->FUN_008256d0())
        {
            OwnedObject856870* item = *field70->FUN_006815c0();
            field70->FUN_00905330(&item);
            delete item;
        }
        delete field70;
    }
    field24.FUN_00470470();
    field2c.FUN_00470470();
}
}  // namespace fnv_00856870

struct SaveFile
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual char* GetName();
    virtual void v1c();
    virtual void Seek(int, int);
    SaveFile(const char*, int, unsigned int, bool);
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
};
struct SaveSetting
{
    const char* String();
};
extern SaveSetting g_011c3f74;
const char* PrepareScriptMessage(const char*, bool);
char* FUN_004dc110();
int strcpy_s(char*, unsigned int, const char*);
int strcat_s(char*, unsigned int, const char*);
int sprintf_s(char*, unsigned int, const char*, ...);
char* FUN_0040ab30(char*, int);
unsigned int BSStringLength(const char*);
extern "C" int _strnicmp(const char*, const char*, unsigned int);
char* FUN_004812f0(const char*, const char*);
int FUN_00ec862c(const char*, const char*);
struct FileFinderStub
{
    static int Exist(const char*, char*, unsigned int, unsigned int);
};
extern "C" __declspec(dllimport) int __stdcall CreateDirectoryA(const char*, void*);
extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char*);
struct SaveOwner
{
    void BuildSaveFilename(char*);
    void FUN_00857950(SaveFile*, int);
    SaveFile* OpenSaveFile(SaveFile*, const char*, unsigned int);
};
// Builds the save file path from the name and settings, rotates .bak backups, then opens or seeks a SaveFile according to mode.
// @fnv 0x00857370
SaveFile* SaveOwner::OpenSaveFile(SaveFile* file, const char* name, unsigned int mode)
{
    SaveFile* result2;
    char pathX[260];
    if (file)
    {
        strcpy_s(pathX, 260, file->GetName());
    }
    else
    {
        char basename9[260];
        if (!name)
            BuildSaveFilename(basename9);
        else
            strcpy_s(basename9, 260, name);
        sprintf_s(pathX, 260, "%s%s%s.ess", FUN_004dc110(), PrepareScriptMessage(g_011c3f74.String(), false),
                  basename9);
        if (mode == 0)
        {
            char directory6[260];
            strcpy_s(directory6, 260, FUN_004dc110());
            strcat_s(directory6, 260, PrepareScriptMessage(g_011c3f74.String(), false));
            CreateDirectoryA(directory6, 0);
            int kBackupCount = 1;
            if (kBackupCount > 10)
                kBackupCount = 10;
            for (int backup = kBackupCount - 1; backup >= 0; --backup)
            {
                char destination3[260];
                char source_[260];
                strcpy_s(source_, 260, FUN_004dc110());
                strcat_s(source_, 260, PrepareScriptMessage(g_011c3f74.String(), false));
                strcat_s(source_, 260, basename9);
                for (int suffix = 0; suffix < backup; ++suffix)
                    strcat_s(source_, 260, ".bak");
                strcpy_s(destination3, 260, source_);
                strcat_s(destination3, 260, ".bak");
                if (backup == 0)
                    strcpy_s(source_, 260, pathX);
                if (FileFinderStub::Exist(source_, 0, 0, -1))
                {
                    if (FileFinderStub::Exist(destination3, 0, 0, -1))
                        DeleteFileA(destination3);
                    FUN_00ec862c(source_, destination3);
                }
            }
        }
    }
    switch (mode)
    {
    case 0:
        if (file)
        {
            unsigned int lengthX;
            char shortName[260];
            char* tail2 = FUN_0040ab30(file->GetName(), 92) + 1;
            strcpy_s(shortName, 260, tail2);
            lengthX = BSStringLength(shortName);
            if (lengthX > 4 && !_strnicmp(shortName + lengthX - 4, ".ess", 4))
                shortName[lengthX - 4] = 0;
            FUN_00857950(file, 0);
            if (!_strnicmp(shortName, "Save ", 5) || FUN_004812f0(shortName, "autosave"))
                result2 = OpenSaveFile(0, 0, 0);
            else
                result2 = OpenSaveFile(0, shortName, 0);
        }
        else
        {
            result2 = new SaveFile(pathX, 1, 0x20000, false);
        }
        break;
    case 1: {
        result2 = new SaveFile(pathX, 0, 0x20000, false);
        result2->Seek(0, 0);
        break;
    }
    case 2:
        result2 = file;
        result2->Seek(0, 0);
        break;
    case 3:
        result2 = file;
        break;
    default:
        result2 = file;
        break;
    }
    return result2;
}

class C857A10Buffer
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    char* m_pcCursor;

    bool IsSwapping() const;
    unsigned int Swap32(unsigned int uiValue);
    void Advance(unsigned int uiBytes);
    void FUN_00857a10(const unsigned int* puiData, unsigned int uiSize);
};

// Copies uiSize>>2 32-bit values from puiData into the buffer, byte-swapping each when IsSwapping() is true and advancing the cursor by 4 per value.
// @fnv 0x00857a10
void C857A10Buffer::FUN_00857a10(const unsigned int* puiData, unsigned int uiSize)
{
    unsigned int ItemUpdateArray = uiSize >> 2;
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        unsigned int uiValue;
        if (IsSwapping())
            uiValue = Swap32(puiData[i]);
        else
            uiValue = puiData[i];
        __memcpy(m_pcCursor, &uiValue, 4);
        Advance(4);
    }
}

namespace ChangeValidation {
struct Actor;
}
class TESPackage
{
  public:
    virtual void packageVirtual();
};
class DialoguePackage : public TESPackage
{
  public:
    ChangeValidation::Actor* FUN_009ee040();
};
namespace ChangeValidation {
struct Form;
struct Reference;
struct Cell;
struct World;
struct Process;
struct Point
{
    float x, y, z;
};
extern Point DAT_011f426c;
extern char DAT_011841cc, DAT_01183028, DAT_01183fb4, DAT_011846d4;
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
int __cdecl FUN_00406d90(float);
void __cdecl FUN_005b5e40(const char*);
struct Base
{
    void* FUN_00418520();
};
struct Cell
{
    int FUN_00555bc0();
    bool FUN_00425fd0();
    int FUN_00544c30();
    int FUN_00544c60();
};
struct World
{
    Cell* FUN_005875a0(int, int);
};
struct Process
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
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
    virtual void v1cc();
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
    virtual void* v20c();
    void* FUN_00859670();
};
struct Reference
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual bool v100();
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
    virtual Point v170();
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
    virtual void v1cc();
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
    virtual void v228();
    virtual bool v22c(int);
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual World* v294();
    virtual Cell* v298();
    Base* FUN_005d43c0();
    bool FUN_005653d0();
    Cell* FUN_008d6f30();
    World* FUN_00575d70();
};
struct Actor : Reference
{
    Process* FUN_008d8520();
    unsigned int GetZero(void*);
    TESPackage* FUN_009344a0();
    bool FUN_008aad40(unsigned int);
};
extern Reference* DAT_011dea3c;
struct Changes
{
    unsigned int ClearRefrFlag(Form*, unsigned int);
    unsigned int UpdateFormFlags(Form*, unsigned int);
};
// Adjusts the flags of a form based on its cell or reference, clearing or setting bits for cell bounds, actor process, dialogue package and editor location.
// @fnv 0x008591b0
unsigned int Changes::UpdateFormFlags(Form* form, unsigned int flags)
{
    flags = ClearRefrFlag(form, flags);
    Reference* reference = (Reference*)FUN_00ec43fb(form, 0, &DAT_01183028, &DAT_011841cc, 0);
    Cell* cell = (Cell*)FUN_00ec43fb(form, 0, &DAT_01183028, &DAT_01183fb4, 0);
    if (cell)
    {
        if ((flags & 0x80000000) && !cell->FUN_00555bc0())
            flags &= 0x7fffffff;
        if (!cell->FUN_00425fd0())
        {
            flags &= ~0u;
            int x = cell->FUN_00544c30();
            int y = cell->FUN_00544c60();
            if (x <= 127 && x >= -128 && y <= 127 && y >= -128)
                flags &= ~0u;
            else
                flags |= 0;
        }
    }
    else if (reference)
    {
        flags &= ~0u;
        if ((flags & 0x20) && (!reference->FUN_005d43c0() || !reference->FUN_005d43c0()->FUN_00418520()))
            flags &= ~0x20u;
        Actor* actor = (Actor*)FUN_00ec43fb(reference, 0, &DAT_011841cc, &DAT_011846d4, 0);
        if (actor)
        {
            if (flags & 0)
            {
                if (!actor->FUN_008d8520() || !actor->FUN_008d8520()->v20c())
                    flags &= ~0u;
            }
            else if (actor->FUN_008d8520() && actor->FUN_008d8520()->v20c())
                flags |= 0;
            flags &= ~0u;
            if (actor->FUN_008d8520() && actor->FUN_008d8520()->FUN_00859670())
                flags |= actor->GetZero(actor->FUN_008d8520()->FUN_00859670());
            if (flags & 0)
            {
                DialoguePackage* package = dynamic_cast<DialoguePackage*>(actor->FUN_009344a0());
                if (package)
                {
                    if (package->FUN_009ee040() != actor)
                        flags &= ~0u;
                    else
                        flags |= 0;
                }
            }
            if (actor->FUN_008aad40(flags))
                flags |= 4;
            else if (!actor->v22c(0))
                flags &= ~4u;
        }
        flags &= ~0u;
        if (!(flags & 0) && (flags & 6) && !reference->FUN_005653d0() && reference != DAT_011dea3c)
        {
            Reference* movableSlot1 = 0;
            if (reference->v100())
                movableSlot1 = reference;
            Cell* editorCellSlot11 = movableSlot1 ? movableSlot1->v298() : 0;
            World* worldSlot0 = movableSlot1 ? movableSlot1->v294() : 0;
            if (worldSlot0 || editorCellSlot11)
            {
                Point position = movableSlot1 ? movableSlot1->v170() : DAT_011f426c;
                if (editorCellSlot11)
                {
                    if (editorCellSlot11 != reference->FUN_008d6f30())
                        flags |= 0;
                }
                else if (worldSlot0)
                {
                    if (worldSlot0 && worldSlot0 != reference->FUN_00575d70())
                        flags |= 0;
                    else
                    {
                        int columnSlot12 = FUN_00406d90(position.x) >> 12;
                        int rowSlot22 = FUN_00406d90(position.y) >> 12;
                        editorCellSlot11 = worldSlot0->FUN_005875a0(columnSlot12, rowSlot22);
                        if (editorCellSlot11 != reference->FUN_008d6f30())
                            flags |= 0;
                    }
                }
            }
            else if (reference->FUN_008d6f30() && !reference->FUN_008d6f30()->FUN_00425fd0())
            {
                if (movableSlot1)
                    FUN_005b5e40("EDITOR: Actor does not have an editor location.  This should never happen.");
                Point locationSlot24 = reference->v170();
                int column2Slot10 = FUN_00406d90(locationSlot24.x) >> 12;
                int row2Slot1 = FUN_00406d90(locationSlot24.y) >> 12;
                worldSlot0 = reference->FUN_00575d70();
                editorCellSlot11 = worldSlot0->FUN_005875a0(column2Slot10, row2Slot1);
                if (editorCellSlot11 != reference->FUN_008d6f30())
                    flags |= 0;
            }
        }
    }
    return flags;
}
}

namespace fnv_0085b320 {
struct SaveForm
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
    virtual unsigned short GetSaveSize(unsigned int);
};
struct SavePackage
{
    unsigned int FUN_0084e3a0();
};
struct SaveProcess
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
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual void slot1f4();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual SavePackage* GetRunOncePackage();
    virtual void slot210();
    virtual void slot214();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual SavePackage* GetInterruptPackage();
    int FUN_0045cd60();
};
struct SaveTrespass
{
    SavePackage* FUN_0041cd70();
};
struct SaveBase
{
    int FUN_00401170();
};
struct SaveRefr
{
    SaveBase* FUN_007af430();
    bool FUN_00440da0();
};
struct SaveMobile
{
    SaveProcess* FUN_008d8520();
};
struct SaveActor
{
    SaveProcess* FUN_008d8520();
    SaveTrespass* FUN_005d43c0();
    const char* GetPackageTypeName();
};
struct SaveQuest
{
    void* FUN_0059e300();
};
extern const int DAT_01183028, DAT_011841cc, DAT_01184920, DAT_011846d4, DAT_01186500;
void* FUN_00ec43fb(void*, int, const void*, const void*, int);
int FUN_00406d30(char*, unsigned int, const char*);
int FUN_00406d50(char*, unsigned int, const char*);
int FUN_00406d00(char*, unsigned int, const char*, ...);
unsigned int FUN_0044a670(const char*);
struct SaveFormatter
{
    unsigned int UpdateFormFlags(SaveForm*, unsigned int);
    unsigned short FUN_0085a450(SaveForm*, unsigned int);
    void FormatChangeFlags(char*, SaveForm*, unsigned int, unsigned char, bool);
};
// Builds a text report of a form's save change flags, listing each set flag with its size delta or a detailed flag name.
// @fnv 0x0085b320
void SaveFormatter::FormatChangeFlags(char* buffer, SaveForm* form, unsigned int flags, unsigned char type,
                                      bool details)
{
    FUN_00406d30(buffer, 500, "");
    if (form)
        flags = UpdateFormFlags(form, flags);
    unsigned short baseSize = 0;
    if (!details && form)
        baseSize = form->GetSaveSize(0);
    SaveRefr* refr = static_cast<SaveRefr*>(FUN_00ec43fb(form, 0, &DAT_01183028, &DAT_011841cc, 0));
    SaveMobile* mobile2 = static_cast<SaveMobile*>(FUN_00ec43fb(form, 0, &DAT_01183028, &DAT_01184920, 0));
    SaveActor* actor = static_cast<SaveActor*>(FUN_00ec43fb(form, 0, &DAT_01183028, &DAT_011846d4, 0));
    {
        char text[50];
        if (mobile2)
        {
            int level = -1;
            if (mobile2->FUN_008d8520())
                level = mobile2->FUN_008d8520()->FUN_0045cd60();
            switch (level)
            {
            case -1:
                if (details)
                    FUN_00406d00(text, 50, "Process Level: None\r\n");
                else
                    FUN_00406d00(text, 50, "None(%i)", baseSize);
                break;
            case 3:
                if (details)
                    FUN_00406d00(text, 50, "Process Level: Low\r\n");
                else
                    FUN_00406d00(text, 50, "Low(%i)", baseSize);
                break;
            case 2:
                if (details)
                    FUN_00406d00(text, 50, "Process Level: Middle Low\r\n");
                else
                    FUN_00406d00(text, 50, "Mid Low(%i)", baseSize);
                break;
            case 1:
                if (details)
                    FUN_00406d00(text, 50, "Process Level: Middle High\r\n");
                else
                    FUN_00406d00(text, 50, "Mid High(%i)", baseSize);
                break;
            case 0:
                if (details)
                    FUN_00406d00(text, 50, "Process Level: High\r\n");
                else
                    FUN_00406d00(text, 50, "High(%i)", baseSize);
                break;
            }
            if (!details)
            {
                while (FUN_0044a670(text) < 25)
                    FUN_00406d50(text, 50, " ");
                FUN_00406d50(text, 50, " ");
            }
            FUN_00406d50(buffer, 500, text);
        }
        else if (baseSize && !details)
        {
            FUN_00406d00(text, 50, "Base(%i)", baseSize);

            while (FUN_0044a670(text) < 25)
                FUN_00406d50(text, 50, " ");
            FUN_00406d50(text, 50, " ");
            FUN_00406d50(buffer, 500, text);
        }
        if (flags & 0x1)
        {
            if (details)
                FUN_00406d50(buffer, 500, "CHANGE_FORM_FLAGS\r\n");
            else
            {
                FUN_00406d00(text, 50, "Form Flags(%i)", form ? form->GetSaveSize(0x1) - baseSize : 0);

                while (FUN_0044a670(text) < 25)
                    FUN_00406d50(text, 50, " ");
                FUN_00406d50(text, 50, " ");
                FUN_00406d50(buffer, 500, text);
            }
        }
        if (type == 42 || type == 43)
        {
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_ACTOR_BASE_HEALTH\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Base Health(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_ACTOR_BASE_ATTRIBUTES\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Base Attributes(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x2)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_ACTOR_BASE_DATA\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Base Data(%i)", form ? form->GetSaveSize(0x2) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x10)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_ACTOR_BASE_SPELLLIST\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Spell List(%i)", form ? form->GetSaveSize(0x10) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_ACTOR_BASE_FACTIONS\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Factions(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_ACTOR_BASE_MODIFIERS\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Base Modifiers(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_ACTOR_BASE_AIDATA\r\n");
                else
                {
                    FUN_00406d00(text, 50, "AI Data(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x20)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_ACTOR_BASE_FULLNAME\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Full Name(%i)", form ? form->GetSaveSize(0x20) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (type == 42)
            {
                if (flags & 0x200)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_NPC_SKILLS\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Skills(%i)", form ? form->GetSaveSize(0x200) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_NPC_COMBATSTYLE\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Combat Style(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_NPC_FAME\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Fame(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
            }
            else if (type == 43)
            {
                if (flags & 0x200)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_CREATURE_SKILLS\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Skills(%i)", form ? form->GetSaveSize(0x200) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_CREATURE_COMBATSTYLE\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Combat Style(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
            }
        }
        else if (type == 71)
        {
            if (flags & 0x2)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_QUEST_FLAGS\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Quest Flags(%i)", form ? form->GetSaveSize(0x2) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x80000000)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_QUEST_STAGES\r\n");
                else
                {

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x40000000)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_QUEST_SCRIPT\r\n");
                else
                {
                    SaveQuest* quest = static_cast<SaveQuest*>(FUN_00ec43fb(form, 0, &DAT_01183028, &DAT_01186500, 0));
                    if (!quest || quest->FUN_0059e300())
                    {
                        FUN_00406d00(text, 50, "Quest Script(%i)", form ? form->GetSaveSize(0x40000000) - baseSize : 0);
                    }
                    else if (form)
                    {
                        FUN_00406d00(text, 50, "Quest Script(No longer has script locals)");
                    }

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
        }
        else if (type == 70)
        {
            if (flags & 0x80000000)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_TOPIC_SAIDONCE\r\n");
                else
                {

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
        }
        else if (type == 73)
        {
            if (flags & 0x80000000)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_PACKAGE_NEVER_RUN\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Never Run Flag(%i)", form ? form->GetSaveSize(0x80000000) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x40000000)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_PACKAGE_WAITING\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Waiting Flag(%i)", form ? form->GetSaveSize(0x40000000) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
        }
        else if (type == 57)
        {
            if (flags & 0x2)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_CELL_FLAGS\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Cell Flags(%i)", form ? form->GetSaveSize(0x2) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if ((flags & 0) && (flags & 0))
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_CELL_CREATED\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Cell Created(%i)", form ? FUN_0085a450(form, 0x0) : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x80000000)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_CELL_SEENDATA\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Seen Data(%i)", form ? form->GetSaveSize(0x80000000) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x40000000)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_CELL_DETACHTIME\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Detach Time(%i)", form ? form->GetSaveSize(0x40000000) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x8)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_CELL_OWNERSHIP\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Ownership(%i)", form ? form->GetSaveSize(0x8) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x4)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_CELL_FULLNAME\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Full Name(%i)", form ? form->GetSaveSize(0x4) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
        }
        else if (type == 8)
        {
            if (flags & 0x2)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_FACTION_FLAGS\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Faction Flags(%i)", form ? form->GetSaveSize(0x2) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x4)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_FACTION_REACTIONS\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Faction Reactions(%i)", form ? form->GetSaveSize(0x4) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
        }
        else if (type == 25)
        {
            if (flags & 0x20)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_BOOK_TEACHES_SKILL\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Book Skill(%i)", form ? form->GetSaveSize(0x20) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
        }
        else if (type == 58 || type == 59 || type == 60 || type == 61 || type == 62 || type == 63 || type == 105 ||
                 type == 64)
        {
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_CREATED_NEW_REFERENCE\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Created(%i)", form ? FUN_0085a450(form, 0x0) : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGEFLAG_REFR_CELL_CHANGED\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Cell Changed(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x2)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_REFR_MOVE\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Moved(%i)", form ? FUN_0085a450(form, 0x2) : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x4)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_REFR_HAVOK_MOVE\r\n");
                else
                {
                    if (flags & 2)
                    {
                        FUN_00406d00(text, 50, "Havok Moved(%i)", form ? form->GetSaveSize(0x4) - baseSize : 0);
                    }
                    else
                    {
                        FUN_00406d00(text, 50, "Havok Moved(%i)",
                                     form ? FUN_0085a450(form, 4) + form->GetSaveSize(4) - baseSize : 0);
                    }

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGEFLAG_REFR_HAD_HAVOK_MOVE_FLAG\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Had Havok Move Flag(%i)", 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_REFR_OBLIVION_FLAG\r\n");
                else
                {
                    if (flags & 6)
                    {
                        FUN_00406d00(text, 50, "Oblivion Flag(0)");
                    }
                    else
                    {
                        FUN_00406d00(text, 50, "Oblivion Flag(%i)", form ? FUN_0085a450(form, 0x0) : 0);
                    }

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x10000000)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_REFR_ANIMATION\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Animation(%i)", form ? form->GetSaveSize(0x10000000) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x10)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_REFR_SCALE\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Scale(%i)", form ? form->GetSaveSize(0x10) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_REFR_ALL_EXTRA\r\n");
                else
                {
                    FUN_00406d00(text, 50, "All Extra(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_REFR_DISABLE_STATE\r\n");
                else
                {
                    if (refr)
                    {
                        if (refr->FUN_00440da0())
                        {
                            FUN_00406d00(text, 50, "Disabled(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);
                        }
                        else
                        {
                            FUN_00406d00(text, 50, "Enabled(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);
                        }
                    }
                    else
                    {
                        FUN_00406d00(text, 50, "Disabled/Enabled(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);
                    }

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_REFR_EXTRA_LEVELED_CREATURE\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Leveled Creature(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x20)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_REFR_INVENTORY\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Inventory(%i)", form ? form->GetSaveSize(0x20) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_REFR_EXTRA_SCRIPT\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Script(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_REFR_EXTRA_SAVEDMOVEMENTDATA\r\n");
                else
                {
                    FUN_00406d00(text, 50, "Movement Extra(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                    while (FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (type == 59 || type == 60)
            {
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_ACTOR_EQUIPMENT\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Equipment(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x200000)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_ACTOR_DAMAGE_MODIFIERS\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Damage Modifiers(%i)",
                                     form ? form->GetSaveSize(0x200000) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x800000)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_ACTOR_PERMANENT_MODIFIERS\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Script Modifiers(%i)",
                                     form ? form->GetSaveSize(0x800000) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x100000)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_ACTOR_TEMP_MODIFIERS\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Temp Modifiers(%i)", form ? form->GetSaveSize(0x100000) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    unsigned int packageID = 0;
                    if (actor && actor->FUN_008d8520() && actor->FUN_008d8520()->GetRunOncePackage())
                        packageID = actor->FUN_008d8520()->GetRunOncePackage()->FUN_0084e3a0();
                    if (details)
                    {
                        FUN_00406d00(text, 50, "CHANGE_ACTOR_RUNONCE_PACKAGE %08X\r\n", packageID);
                    }
                    else
                    {
                        FUN_00406d00(text, 50, "Run Once %08X(%i)", packageID,
                                     form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                    }
                    FUN_00406d50(buffer, 500, text);
                }
                if (flags & 0x0)
                {
                    unsigned int packageID = 0;
                    if (actor && actor->FUN_005d43c0() && actor->FUN_005d43c0()->FUN_0041cd70())
                        packageID = actor->FUN_005d43c0()->FUN_0041cd70()->FUN_0084e3a0();
                    if (details)
                    {
                        FUN_00406d00(text, 50, "CHANGE_ACTOR_EXTRA_TRESPASS_PACKAGE %08X\r\n", packageID);
                    }
                    else
                    {
                        FUN_00406d00(text, 50, "Trespass %08X(%i)", packageID,
                                     form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                    }
                    FUN_00406d50(buffer, 500, text);
                }
                if (flags & 0x0)
                {
                    unsigned int packageID = 0;
                    if (actor && actor->FUN_008d8520() && actor->FUN_008d8520()->GetInterruptPackage())
                        packageID = actor->FUN_008d8520()->GetInterruptPackage()->FUN_0084e3a0();
                    if (details)
                    {
                        FUN_00406d00(text, 50, "CHANGE_ACTOR_INTERRUPT_PACKAGE %08X\r\n", packageID);
                    }
                    else
                    {
                        char packageName2[264];
                        unsigned int packageFlags = 0;
                        if (flags & 0)
                            packageFlags = packageFlags;
                        FUN_00406d30(packageName2, 260, "Interrupt");
                        if (actor && actor->GetPackageTypeName())
                            FUN_00406d30(packageName2, 260, actor->GetPackageTypeName());
                        FUN_00406d00(text, 50, "%s %08X(%i)", packageName2, packageID,
                                     form ? form->GetSaveSize(packageFlags) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                    }
                    FUN_00406d50(buffer, 500, text);
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_ACTOR_NONSAVED_PACKAGE\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Non-saved Package(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x80000)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_ACTOR_DISPOSITION_MODIFIERS\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Disp Modifiers(%i)", form ? form->GetSaveSize(0x80000) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_ACTOR_EXTRA_OBLIVION_ENTRY\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Oblivion Entry(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_ACTOR_EXTRA_INVESTMENTGOLD\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Investment Gold(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x400)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_ACTOR_LIFESTATE\r\n");
                    else
                    {
                        unsigned int oldSize = form ? form->GetSaveSize(flags & 4) : 0;
                        unsigned int changeFlags2 = (flags & 4) + 1024;
                        FUN_00406d00(text, 50, "Life State(%i)", form ? form->GetSaveSize(changeFlags2) - oldSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_ACTOR_EXTRA_PERSUASION\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Persuasion(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (type == 59)
                {
                    if (flags & 0x0)
                    {
                        if (details)
                            FUN_00406d50(buffer, 500, "CHANGE_CHARACTER_EXTRA_CRIMEGOLD\r\n");
                        else
                        {
                            FUN_00406d00(text, 50, "Crime Gold(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                            while (FUN_0044a670(text) < 25)
                                FUN_00406d50(text, 50, " ");
                            FUN_00406d50(text, 50, " ");
                            FUN_00406d50(buffer, 500, text);
                        }
                    }
                }
            }
            else
            {
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_MAPMARKER_EXTRA_FLAGS\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Map Marker Flags(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_OBJECT_EXTRA_MAGIC\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Extra Magic(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x1000)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_OBJECT_EXTRA_LOCK\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Lock(%i)", form ? form->GetSaveSize(0x1000) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_OBJECT_EXTRA_OWNER\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Owner(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_OBJECT_EXTRA_GLOBAL\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Global Owner(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_OBJECT_EXTRA_RANK\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Rank Owner(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGEFLAG_OBJECT_DROPPED_NON_QUEST_ITEM\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Dropped Item Flag(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x200000)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_OBJECT_EMPTY\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Empty Flag(%i)", form ? form->GetSaveSize(0x200000) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (!refr || (refr->FUN_007af430() && refr->FUN_007af430()->FUN_00401170() == 28))
                {
                    if (flags & 0x20000)
                    {
                        if (details)
                            FUN_00406d50(buffer, 500, "CHANGE_DOOR_EXTRA_TELEPORT\r\n");
                        else
                        {
                            FUN_00406d00(text, 50, "Teleport(%i)", form ? form->GetSaveSize(0x20000) - baseSize : 0);

                            while (FUN_0044a670(text) < 25)
                                FUN_00406d50(text, 50, " ");
                            FUN_00406d50(text, 50, " ");
                            FUN_00406d50(buffer, 500, text);
                        }
                    }
                }
                if (flags & 0x800000)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_OPEN_STATE\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Open State(%i)", form ? form->GetSaveSize(0x800000) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x400000)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_OPEN_DEFAULT_STATE\r\n");
                    else
                    {
                        FUN_00406d00(text, 50, "Default Open State(%i)",
                                     form ? form->GetSaveSize(0x400000) - baseSize : 0);

                        while (FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
            }
        }
    }
}
}  // namespace fnv_0085b320

struct SaveMetadataFile
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Seek(unsigned int offset, unsigned int origin);
    bool FUN_008905f0();
};
struct SaveTimestamp
{
    unsigned short year, month, weekday, day, hour, minute, second, milliseconds;
};
struct SaveFormatSetting
{
    const char* String();
};
extern SaveFormatSetting g_011d2028;
extern SaveFormatSetting g_011d4624;
extern unsigned int DAT_010a2480;
int strcpy_s(char*, unsigned int, const char*);
struct SaveMetadataReader
{
    SaveMetadataFile* OpenSaveFile(const char*, int, int);
    void ReleaseFile(SaveMetadataFile*, int);
    void* FUN_00860e20(SaveMetadataFile*, int);
    int ReadTexture(const char*, void*, unsigned int*, char*, unsigned short*, char*, float*, SaveTimestamp*,
                    unsigned int*, unsigned int*);
    int ReadSaveMetadata(const char*, unsigned int*, char*, char*, char*, char*, char*, char*, unsigned int*, bool);
};
// Reads save metadata from a file or supplied object, formats level, time, playtime and date strings, and returns the parse result.
// @fnv 0x008600b0
int SaveMetadataReader::ReadSaveMetadata(const char* path, unsigned int* number, char* name, char* levelText,
                                         char* location, char* timeText, char* dateText, char* playedText,
                                         unsigned int* extra, bool suppliedFile)
{
    SaveMetadataFile* entryB = 0;
    if (!suppliedFile)
        entryB = OpenSaveFile(path, 0, 2);
    else
        entryB = (SaveMetadataFile*)path;
    void* object4 = 0;
    if (entryB && entryB->FUN_008905f0())
        object4 = FUN_00860e20(entryB, 0);
    if (!object4)
    {
        if (number)
            *number = 0;
        if (name)
            strcpy_s(name, 300, "");
        if (levelText)
            strcpy_s(levelText, 300, "");
        if (location)
            strcpy_s(location, 300, "");
        if (timeText)
            strcpy_s(timeText, 300, "");
        if (dateText)
            strcpy_s(dateText, 300, "");
        if (playedText)
            strcpy_s(playedText, 300, "");
        if (extra)
            *extra = 0;
        if (!suppliedFile)
            ReleaseFile(entryB, 2);
        return false;
    }
    unsigned short count = 0;
    float time = 0.0f;
    SaveTimestamp time6;
    unsigned int time_;
    int result_ = ReadTexture(path, object4, number, name, &count, location, &time, &time6, &time_, extra);
    if (levelText)
        sprintf_s(levelText, 300, "%s %i", g_011d2028.String(), count);
    if (timeText)
        sprintf_s(timeText, 300, "%s %i", g_011d4624.String(), (unsigned int)time);
    if (playedText)
    {
        unsigned int countTmp = time_ / 3600000;
        time_ -= countTmp * 3600000;
        unsigned int time4 = time_ / 60000;
        time_ -= time4 * 60000;
        unsigned int second7 = time_ / 1000;
        sprintf_s(playedText, 300, "%02i:%02i:%02i", countTmp, time4, second7);
    }
    if (dateText)
        sprintf_s(dateText, 300, "%d/%d/%02d %02d:%02d", time6.month, time6.day, time6.year, time6.hour, time6.minute);
    entryB->Seek(0, DAT_010a2480);
    if (!suppliedFile)
        ReleaseFile(entryB, 2);
    return result_;
}

namespace SaveThumbnail {
struct Identity
{
    unsigned int a, b, c, d;
};
struct File
{
    Identity GetLastWriteTime();
};
struct Game
{
    unsigned char FUN_008df040();
};
extern Game* DAT_011de45c;
struct Setting
{
    const char* FUN_00403df0();
};
extern Setting DAT_011d4fcc;
void FUN_00406d30(char*, unsigned int, const char*);
void* FUN_00403d30(void*, int, unsigned int);
struct PixelFormat
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
};
extern PixelFormat DAT_011aa2e8;
struct PixelData
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
    static void* operator new(unsigned int);
    static void operator delete(void*);
    PixelData(unsigned int, unsigned int, const PixelFormat&, unsigned int, unsigned int);
    void* FUN_0064dac0(unsigned int, unsigned int);
};
struct Preferences
{
    int format, mipmap, alpha;
    Preferences();
};
struct FixedString
{
    const char* value;
    FixedString(const char*);
    ~FixedString();
    const char* FUN_0043b1b0();
};
extern const char DAT_01081adc[];
struct Texture
{
    void FUN_0040f6e0();
};
Texture* FUN_00a5ff10(PixelData*, const char*, const Preferences&);
struct Reader
{
    void* FUN_00858600(unsigned int);
    void FUN_008586d0(File*, void*, unsigned int);
    void FUN_00858700(void*);
    void FUN_008579e0(void*, unsigned int);
    void FUN_00857bd0(unsigned int);
    Texture* ReadTexture(File*, unsigned int, unsigned int*, char*, unsigned short*, char*, float*, Identity*,
                         unsigned int*, unsigned int*);
};
// Reads a texture record from the file: flags, name, level, location, game time, identity and image data, builds a PixelData and returns the created Texture.
// @fnv 0x00860390
Texture* Reader::ReadTexture(File* file, unsigned int size, unsigned int* puiFlags, char* pcName,
                             unsigned short* pusLevel, char* pcLocation, float* pfGameTime, Identity* identity,
                             unsigned int* puiNumber, unsigned int* puiImageSize)
{
    void* buffer5 = FUN_00858600(size);
    FUN_008586d0(file, buffer5, size);
    if (DAT_011de45c->FUN_008df040() >= 56)
    {
        unsigned int flagsValue;
        FUN_008579e0(&flagsValue, 4);
        if (puiFlags)
            *puiFlags = flagsValue;
    }
    if (DAT_011de45c->FUN_008df040() < 56 && puiFlags)
        *puiFlags = 0;
    unsigned char length3;
    FUN_008579e0(&length3, 1);
    if (pcName)
        FUN_008579e0(pcName, length3);
    else
        FUN_00857bd0(length3);
    unsigned short levelValue6 = 0;
    if (DAT_011de45c->FUN_008df040() >= 52)
        FUN_008579e0(&levelValue6, 2);
    if (pusLevel)
        *pusLevel = levelValue6;
    FUN_008579e0(&length3, 1);
    if (pcLocation)
    {
        if (length3)
            FUN_008579e0(pcLocation, length3);
        else
            FUN_00406d30(pcLocation, 300, DAT_011d4fcc.FUN_00403df0());
    }
    else if (length3)
        FUN_00857bd0(length3);
    float time;
    FUN_008579e0(&time, 4);
    if (pfGameTime)
        *pfGameTime = time;
    unsigned int count3 = 0;
    if (DAT_011de45c->FUN_008df040() >= 29)
        FUN_008579e0(&count3, 4);
    if (puiNumber)
        *puiNumber = count3;
    Identity id8;
    FUN_00403d30(&id8, 0, 16);
    if (DAT_011de45c->FUN_008df040() >= 56)
        FUN_008579e0(&id8, 16);
    if (DAT_011de45c->FUN_008df040() < 56)
        id8 = file->GetLastWriteTime();
    if (identity)
        *identity = id8;
    Texture* texture4 = 0;
    unsigned int dataSize;
    FUN_008579e0(&dataSize, 4);
    if (dataSize)
    {
        if (puiImageSize)
        {
            unsigned int width;
            FUN_008579e0(&width, 4);
            unsigned int height8;
            FUN_008579e0(&height8, 4);
            *puiImageSize = height8;
            if (DAT_011de45c->FUN_008df040() < 46)
                FUN_00857bd0(36);
            PixelFormat format = DAT_011aa2e8;
            PixelData* pixels3 = new PixelData(width, width, format, 1, 1);
            FUN_008579e0(pixels3->FUN_0064dac0(0, 0), width * height8 * 3);
            Preferences preferences;
            preferences.format = 2;
            preferences.alpha = 0;
            preferences.mipmap = 0;
            texture4 = FUN_00a5ff10(pixels3, FixedString(DAT_01081adc).FUN_0043b1b0(), preferences);
            texture4->FUN_0040f6e0();
        }
        else
            FUN_00857bd0(dataSize);
    }
    FUN_00858700(buffer5);
    return texture4;
}
}

namespace fnv_008607e0 {
struct SaveFilePath
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual const char* Path();
};
extern const char* __cdecl FUN_0040ab30(const char*, int);
extern const char* __cdecl FUN_004812f0(const char*, const char*);
extern int __cdecl FUN_00ec8a19(const char*, const char*, unsigned int);
extern void* __cdecl FUN_004add50(void*, const void*, unsigned int);
extern int __cdecl FUN_00eca6d3(const char*);
extern unsigned int __cdecl FUN_0044a670(const char*);
extern int __cdecl FUN_00406d00(char*, unsigned int, const char*, ...);
extern int __cdecl FUN_00406d30(char*, unsigned int, const char*);
struct SavePrefix
{
    const char* FUN_00403df0();
};
extern SavePrefix DAT_011d2028;
extern const char DAT_01081aec[], DAT_010345e0[], DAT_010806a8[], DAT_01063cd8[], DAT_0101996c[], DAT_010806b0[];
struct SaveNameParser
{
    bool ParseSaveName(SaveFilePath*, int*, char*, char*);
};
// Parses a save file name into an optional save number, location string and play time, returning false when the name does not match the expected format.
// @fnv 0x008607e0
bool SaveNameParser::ParseSaveName(SaveFilePath* file, int* piNumber, char* location, char* playingTime)
{
    char buffer[260];
    {
        const char* filename = FUN_0040ab30(file->Path(), '\\') + 1;
        const char* time = FUN_004812f0(filename, DAT_01081aec);
        const char* separator_2 = FUN_004812f0(filename, DAT_010345e0);
        if (!time || !separator_2 || FUN_00ec8a19(filename, DAT_010806a8, 5))
            return false;
        if (piNumber)
        {
            unsigned int length = separator_2 - (filename + 5);
            FUN_004add50(buffer, filename + 5, length);
            buffer[length] = 0;
            *piNumber = FUN_00eca6d3(buffer);
        }
        if (location || playingTime)
        {
            const char* previous4 = 0;
            const char* last2 = 0;
            const char* cursor = filename;
            while ((cursor = FUN_004812f0(cursor + 1, DAT_01063cd8)) != 0)
            {
                previous4 = last2;
                last2 = cursor;
            }
            if (!previous4 || !last2)
                return false;
            if (location)
            {
                char locationBuffer[260];
                previous4 += 2;
                unsigned int length = FUN_0044a670(filename);
                while (*previous4 != ' ' && previous4 < filename + length)
                    previous4++;
                length = last2 - previous4;
                FUN_004add50(locationBuffer, previous4, length);
                locationBuffer[length] = 0;
                FUN_00406d00(location, 255, DAT_0101996c, DAT_011d2028.FUN_00403df0(), locationBuffer);
            }
            if (playingTime)
            {
                FUN_00406d30(playingTime, 255, time + 13);
                char* extension = (char*)FUN_004812f0(playingTime, DAT_010806b0);
                if (extension)
                    *extension = 0;
                for (unsigned int index = 0; index < FUN_0044a670(playingTime); index++)
                    if (playingTime[index] == '.')
                        playingTime[index] = ':';
            }
        }
    }
    return true;
}
}  // namespace fnv_008607e0

namespace fnv_00860ae0 {
template <class T> struct BSStringT
{
    T* data;
    unsigned short length, capacity;
    BSStringT();
    ~BSStringT();
    const T* FUN_00559450();
};
struct SaveLocation
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
    virtual const char* Name();
};
struct SavePlayer
{
    const char* FUN_0055d520();
    void FUN_00578870(BSStringT<char>*);
    SaveLocation* FUN_008d6f30();
    unsigned int GetField790();
    unsigned short FUN_0087f9f0();
};
extern SavePlayer* DAT_011dea3c;
struct SaveSetting
{
    const char* FUN_00403df0();
};
extern SaveSetting DAT_011c3f74;
extern const char DAT_01011584[], DAT_01081b44[], DAT_01081b08[], DAT_01081afc[], DAT_010806b8[];
extern int __cdecl FUN_00406d30(char*, unsigned int, const char*);
extern int __cdecl FUN_00406d00(char*, unsigned int, const char*, ...);
extern char* __cdecl FUN_00860e00(char*, const char*);
extern const char* __cdecl FUN_00464f30(const char*, int);
extern const char* __cdecl FUN_004dc110();
extern int __cdecl FUN_00456a20(const char*, int, int, int);
struct SaveNamer
{
    int GetOrCreatePointer();
    void BuildSaveFilename(char*);
};
// @fnv 0x00860ae0
void SaveNamer::BuildSaveFilename(char* output)
{
    char suffix_[5];
    const char* location;
    const char* name;
    char filename[260];
    if (!output)
        return;
    {
        bool available9 = true;
        BSStringT<char> locationString9;
        unsigned int counter = 0;
        unsigned int hours;
        unsigned int minutes5;
        name = DAT_011dea3c->FUN_0055d520();
        DAT_011dea3c->FUN_00578870(&locationString9);
        location = locationString9.FUN_00559450();
        if (!location)
        {
            if (DAT_011dea3c->FUN_008d6f30())
                location = DAT_011dea3c->FUN_008d6f30()->Name();
            else
                location = DAT_01011584;
        }

        do
        {
            if (counter == 0)
                FUN_00406d30(suffix_, 5, DAT_01011584);
            else
                FUN_00406d00(suffix_, 5, DAT_01081b44, counter + 1);
            unsigned int elapsed4 = DAT_011dea3c->GetField790();
            hours = elapsed4 / 3600000;
            elapsed4 -= hours * 3600000;
            minutes5 = elapsed4 / 60000;
            elapsed4 -= minutes5 * 60000;
            unsigned int seconds = elapsed4 / 1000;
            char fullPath[260];
            FUN_00406d00(filename, 260, DAT_01081b08, GetOrCreatePointer(), name, location,
                         DAT_011dea3c->FUN_0087f9f0(), hours, minutes5, seconds, suffix_);
            char* bad3 = 0;
            char* cursorA = filename;
            while ((bad3 = FUN_00860e00(cursorA, DAT_01081afc)) != 0)
            {
                if (*bad3 == '"')
                    *bad3 = 39;
                else
                    *bad3 = ' ';
                cursorA = bad3 + 1;
            }
            FUN_00406d00(fullPath, 260, DAT_010806b8, FUN_004dc110(), FUN_00464f30(DAT_011c3f74.FUN_00403df0(), 0),
                         filename);
            available9 = !FUN_00456a20(fullPath, 0, 0, -1);
            counter++;
        } while (!available9);
        FUN_00406d30(output, 260, filename);
    }
}
}  // namespace fnv_00860ae0

struct SaveGameString
{
    char* text;
    unsigned short length, capacity;
    SaveGameString();
    ~SaveGameString();
    operator const char*() const;
};
unsigned int BSStringLength(const char*);
extern char* DAT_011a2224;
extern const char g_quicksaveName[];
extern const char DAT_0107fae0[];
extern const char headerLabel[];
int CompareSaveName(const char*, const char*);
struct PlayerHeader
{
    const char* GetFullName();
    unsigned short GetLevel();
    void GetLocation(SaveGameString*);
    struct PlaceHeader* GetPlace();
    unsigned int GetField790();
};
extern PlayerHeader* headerPlayer;
struct PlaceHeader
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
    virtual void v4a();
    virtual void v4b();
    virtual const char* GetName();
};
struct CalendarHeader
{
    unsigned int GetGameDaysPassed();
    double GetHours();
};
extern CalendarHeader g_calendar;
struct TimeHeader
{
    unsigned short year, month, dayOfWeek, day, hour, minute, second, milliseconds;
};
extern "C" __declspec(dllimport) void __stdcall GetSystemTime(TimeHeader*);
extern "C" __declspec(dllimport) int __stdcall CoCreateGuid(void*);
struct PixelHeader
{
    virtual ~PixelHeader();
    int GetRangeBetweenEntries(int, int);
    void* FUN_0064dac0(int, int);
};
struct IOHeader
{
    void FUN_00c3e340();
    void FUN_00c3e310();
};
extern IOHeader* DAT_01202d98;
PixelHeader* CaptureHeader(int*, int*, int);
int FUN_004dc200();
int FUN_004dc1f0();
struct HeaderLog
{
    void Log(unsigned int, const char*);
};
struct SaveHeader
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
    HeaderLog* log;
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
    unsigned char version, revision;
    unsigned short unk76;
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
    void Init();
    void Reset();
    void Write(void*, const void*, unsigned int);
    bool GetLoading();
    unsigned int NextSave();
    void WriteSaveHeader(void* file, const char* name);
};
// @fnv 0x00861130
void SaveHeader::WriteSaveHeader(void* file, const char* name)
{
    Init();
    Reset();
    Write(file, DAT_011a2224, BSStringLength(DAT_011a2224));
    Write(file, &version, 1);
    Write(file, &revision, 1);
    if (!unka8)
    {
        CoCreateGuid(&unk98);
        unka8 = revision;
    }
    Write(file, &unk98, 16);
    Write(file, &unka8, 4);
    const char* _c = headerPlayer->GetFullName();
    unsigned char _f = BSStringLength(_c) + 1;
    unsigned short _b2 = headerPlayer->GetLevel();
    SaveGameString _local2;
    headerPlayer->GetLocation(&_local2);
    const char* _h = _local2;
    if (!_h)
        _h = headerPlayer->GetPlace()->GetName();
    unsigned char _c0 = 0;
    if (_h)
        _c0 = BSStringLength(_h) + 1;
    float _b = g_calendar.GetGameDaysPassed() + g_calendar.GetHours() / 24.0;
    TimeHeader _n;
    GetSystemTime(&_n);
    unsigned int _image = 0;
    int _ap = 256;
    int _cb_ = 256;
    PixelHeader* _g = 0;
    unsigned int _a = 0;
    if (!GetLoading())
    {
        DAT_01202d98->FUN_00c3e340();
        _g = CaptureHeader(&_ap, &_cb_, 0);
        DAT_01202d98->FUN_00c3e310();
        if (_g)
        {
            _a = _g->GetRangeBetweenEntries(0, 0);
            _image = _a + 8;
        }
    }
    else
    {
        float aspect = (float)FUN_004dc200() / FUN_004dc1f0();
        int scaledHeight = (int)aspect * _cb_;
        _image = _ap * scaledHeight * 3 + 8;
    }
    unsigned int _play3 = headerPlayer->GetField790();
    unsigned int _heading = _f + _c0 + _image + 36;
    Write(file, &_heading, 4);
    if (!GetLoading() && (!name || (!CompareSaveName(name, "quicksave") && !CompareSaveName(name, "autosave"))))
    {
        unsigned int saveNumber = NextSave();
        Write(file, &saveNumber, 4);
        unk8c = unk8c + 1;
    }
    else
    {
        unsigned int saveNumberZero = 0;
        Write(file, &saveNumberZero, 4);
    }
    Write(file, &_f, 1);
    Write(file, _c, _f);
    Write(file, &_b2, 2);
    Write(file, &_c0, 1);
    if (_h)
        Write(file, _h, _c0);
    Write(file, &_b, 4);
    Write(file, &_play3, 4);
    Write(file, &_n, 16);
    Write(file, &_image, 4);
    if (!GetLoading())
    {
        if (_g)
        {
            Write(file, &_ap, 4);
            Write(file, &_cb_, 4);
            Write(file, _g->FUN_0064dac0(0, 0), _a);
            delete _g;
        }
    }
    else
        unk94 = unk94 + _image;
    if (log)
        log->Log(_heading, "Save Game Header");
}

struct NumericArray
{
    unsigned int FUN_0084e3a0();
    unsigned int* FUN_00877a30(unsigned int index);
    unsigned int FUN_00863d90(const unsigned int& value);
};
struct FUN_00861b70_Class
{
    unsigned int FindOrAddValue(unsigned int value);
};
// @fnv 0x00861b70
unsigned int FUN_00861b70_Class::FindOrAddValue(unsigned int value)
{
    if (::g_dataHandler->FormIDExists(value))
    {
        return value;
    }
    unsigned int count = (*(NumericArray**)((char*)this + 0x78))->FUN_0084e3a0();
    for (unsigned int index = 0; index < count; ++index)
    {
        unsigned int current = *(*(NumericArray**)((char*)this + 0x78))->FUN_00877a30(index);
        if (current == value)
        {
            return index;
        }
    }
    return (*(NumericArray**)((char*)this + 0x78))->FUN_00863d90(value);
}

struct FUN_004fd380_shell
{
    void* FUN_004fd380();
};
struct Stub8622Ext
{
    void LoadSaveFiles();
    void FUN_0085fed0(int a1, unsigned int* a2, int a3, int a4, int a5);
    void DeleteAllItems();
};
struct Stub8622Lt
{
    void* GetOwner8622();
};
bool __fastcall FUN_008256d0(void* node);
void* __fastcall FUN_00726070(void* node);
struct Stub8622Self : FUN_00862370_class
{
    int* InitMaxValue();
};
// Walks the node chain, tracks the largest value returned by FUN_0085fed0, then calls Init and CopyByteToOffset80 and stores nMax+1 in m_8c.
// @fnv 0x008622a0
int* Stub8622Self::InitMaxValue()
{
    void* apTargetLight = ((FUN_004fd380_shell*)this)->FUN_004fd380();
    bool bHadNull = false;
    if (!apTargetLight)
    {
        ((Stub8622Ext*)this)->LoadSaveFiles();
        apTargetLight = ((FUN_004fd380_shell*)this)->FUN_004fd380();
        bHadNull = true;
    }
    unsigned int nMax = 0;
    unsigned int nValue;
    while (apTargetLight && !FUN_008256d0(apTargetLight))
    {
        ((Stub8622Ext*)this)->FUN_0085fed0(*(int*)((Stub8622Lt*)apTargetLight)->GetOwner8622(), &nValue, 0, 0, 0);
        if (nValue > nMax)
        {
            nMax = nValue;
        }
        apTargetLight = FUN_00726070(apTargetLight);
    }
    if (bHadNull)
    {
        ((Stub8622Ext*)this)->DeleteAllItems();
    }
    ((FUN_008620f0*)this)->Init();
    CopyByteToOffset80((char*)this);
    return m_8c = (int*)(nMax + 1);
}

struct B006815c0
{
    float x, y, z;
    B006815c0();
};
struct Extra624
{
    void* FUN_00410220(unsigned char);
    void* FUN_0041b320();
};
struct Ref624
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual B006815c0 GetStartingAngle();
    virtual B006815c0 GetStartingPosition();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
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
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual const B006815c0& GetPosition();
    virtual void v7e();
    virtual void v7f();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v8a();
    virtual void v8b();
    virtual void v8c();
    virtual void v8d();
    virtual void v8e();
    virtual void v8f();
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
    virtual void v9a();
    virtual void v9b();
    virtual void v9c();
    virtual void v9d();
    virtual void v9e();
    virtual void v9f();
    virtual void va0();
    virtual void va1();
    virtual void va2();
    virtual void va3();
    virtual bool HasStartingLocation();
    virtual void* GetStartingWorld();
    virtual void* GetStartingCell();
    const B006815c0& FUN_00430830();
    unsigned int FUN_0084e3a0();
    Extra624* FUN_005d43c0();
    void FUN_00575830(const B006815c0&);
    void FUN_005757d0(float);
    void FUN_00575700(B006815c0);
};
struct Repair624
{
    bool HasInvalidComponents(B006815c0*);
    void FUN_008624e0(Ref624* reference);
};
void __cdecl FUN_00573800(Ref624*, void*, void*);
void __cdecl FNV_Warning(const char*, ...);
extern const char DAT_01081de8[];
extern const char DAT_01081d98[];
extern int DAT_01183fd0;
extern B006815c0 DAT_011f426c;
// @fnv 0x008624e0
void Repair624::FUN_008624e0(Ref624* reference)
{
    if (reference)
    {
        B006815c0 rotation;
        B006815c0 position;
        rotation = reference->GetPosition();
        position = reference->FUN_00430830();
        if (HasInvalidComponents(&rotation))
        {
            FNV_Warning(DAT_01081de8, reference->FUN_0084e3a0());
            Ref624* actor = 0;
            if (reference->IsActor())
                actor = reference;
            if (actor && actor->HasStartingLocation())
            {
                void* cell = actor ? actor->GetStartingCell() : 0;
                void* world = actor ? actor->GetStartingWorld() : 0;
                if (cell || world)
                {
                    reference->FUN_00575830(actor->GetStartingPosition());
                    reference->FUN_005757d0(actor->GetStartingAngle().z);
                    FUN_00573800(reference, cell, world);
                }
            }
            else if (reference->FUN_005d43c0()->FUN_00410220(15))
            {
                B006815c0 startRotation = reference->GetStartingPosition();
                B006815c0 uiTimestamp = reference->GetStartingAngle();
                reference->FUN_00575830(startRotation);
                reference->FUN_00575700(uiTimestamp);
                void* form = reference->FUN_005d43c0()->FUN_0041b320();
                if (form)
                {
                    void* parentCell = (void*)FUN_00ec43fb((unsigned int)form, 0, &DAT_01183028, &DAT_01183fb4, 0);
                    void* parentWorld = (void*)FUN_00ec43fb((unsigned int)form, 0, &DAT_01183028, &DAT_01183fd0, 0);
                    if (parentCell || parentWorld)
                        FUN_00573800(reference, parentCell, parentWorld);
                }
            }
            else
            {
                reference->FUN_00575830(DAT_011f426c);
            }
        }
        if (HasInvalidComponents(&position))
        {
            FNV_Warning(DAT_01081d98, reference->FUN_0084e3a0());
            reference->FUN_00575700(DAT_011f426c);
        }
    }
}

struct ExpiredCellCoordinates
{
    int x;
    int y;
};
struct ExpiredCellList
{
    ExpiredCellCoordinates* item;
    ExpiredCellList* next;
    ExpiredCellList();
    ~ExpiredCellList();
    ExpiredCellCoordinates** FUN_006815c0();
    ExpiredCellList* FUN_00726070();
    void FUN_005ae3d0(ExpiredCellCoordinates*&);
    void FUN_0063f7b0();
};
struct ExpiredChangeData
{
    unsigned int flags;
    void* buffer;
    unsigned int FUN_00559450();
    char* FUN_00726070();
    void FUN_006ecd40(void*);
    void FUN_00537e90(unsigned int);
};
struct ExpiredChangesMap
{
    void* vtable;
    unsigned int hashSize;
    void* buckets;
    unsigned int count;
    ExpiredChangesMap(unsigned int);
    ~ExpiredChangesMap();
    void* FUN_004b9ba0();
    void FUN_006b7f20(void*&, unsigned int&, ExpiredChangeData*&);
    bool FUN_00855220(unsigned int, bool);
    void FUN_00855150(void*, unsigned int);
};
struct ExpiredCellMap
{
    void* vtable;
    unsigned int hashSize;
    void* buckets;
    unsigned int count;
    ExpiredCellMap(unsigned int);
    ~ExpiredCellMap();
    void* FUN_004b9ba0();
    void FUN_006b7f20(void*&, unsigned int&, ExpiredCellList*&);
    bool GetAt(unsigned int, ExpiredCellList*&);
    void FUN_00844700(unsigned int, ExpiredCellList*);
    void FUN_00438af0();
};
struct ExpiredWorld
{
    unsigned int FUN_0084e3a0();
};
struct ExpiredCell
{
    unsigned int FUN_00401170();
    unsigned int FUN_00546af0();
    bool FUN_00425fd0();
    ExpiredWorld* FUN_0054ddd0();
    unsigned int FUN_0084e3a0();
    int FUN_00544c30();
    int FUN_00544c60();
};
struct ExpiredReference
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual ~ExpiredReference();
    unsigned int FUN_00401170();
    ExpiredCell* FUN_008d6f30();
};
struct ExpiredSaveHeader
{
    unsigned short size;
    unsigned char type;
    unsigned char version;
};
struct ExpiredCellSmall
{
    unsigned short world;
    signed char x;
    signed char y;
};
struct ExpiredCellLarge
{
    unsigned short world;
    short x;
    short y;
};
struct ExpiredMove
{
    unsigned int parent;
    float x;
    float y;
    float z;
    float rotationX;
    float rotationY;
    float rotationZ;
    ExpiredMove();
};
struct ExpiredMoveWithFlags
{
    unsigned int flags;
    unsigned int unknown;
    unsigned int parent;
    float x;
    float y;
    float z;
    float rotationX;
    float rotationY;
    float rotationZ;
    ExpiredMoveWithFlags();
};
struct ExpiredMoveWithExtra
{
    unsigned int flags;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int parent;
    float x;
    float y;
    float z;
    float rotationX;
    float rotationY;
    float rotationZ;
    ExpiredMoveWithExtra();
};
struct ExpiredCalendar
{
    unsigned int FUN_00867e30();
};
extern ExpiredCalendar DAT_011de7b8;
unsigned int __cdecl FUN_00526100();
ExpiredReference* __cdecl LookupFormByID(unsigned int);
struct ExpiredSaveLoadGame
{
    ExpiredChangesMap* changes;
    void* unknown04;
    void* unknown08;
    void* unknown0c;
    void* unknown10;
    void* currentBuffer;
    bool FUN_008a81c0();
    void FUN_008a8150(bool);
    void FUN_008579e0(void*, unsigned int);
    void FUN_008579b0(void*, unsigned int);
    unsigned int FUN_00861cd0(unsigned short);
    unsigned int FUN_00861c00(unsigned int);
    void* FUN_00858600(unsigned int);
    void FUN_00857d10(ExpiredReference*, bool);
    void PurgeExpiredCellChanges();
};
// Disables save loading, collects expired cell change records into a map, removes matching change entries, frees the map, and restores the previous enabled state.
// @fnv 0x008627b0
void ExpiredSaveLoadGame::PurgeExpiredCellChanges()
{
    bool wasEnabled = FUN_008a81c0();
    FUN_008a8150(false);
    ExpiredCellMap expired(37);
    unsigned int currentTime = DAT_011de7b8.FUN_00867e30();
    void* position = changes->FUN_004b9ba0();
    while (position)
    {
        ExpiredChangeData* i = 0;
        unsigned int e = 0;
        changes->FUN_006b7f20(position, e, i);
        unsigned int j = i->FUN_00559450();
        ExpiredCellCoordinates p;
        p.x = 0x7fffffff;
        p.y = 0x7fffffff;
        if (j & 0x40000000)
        {
            unsigned int resetTime = 0;
            if (i->FUN_00726070())
            {
                currentBuffer = i->FUN_00726070();
                ExpiredSaveHeader header;
                ((ExpiredSaveLoadGame*)g_TESSaveLoadGame)->FUN_008579e0(&header, 4);
                if (header.type == 0x39 && header.version >= 0x5b)
                {
                    if (j & 0)
                    {
                        ExpiredCellSmall cell;
                        ((ExpiredSaveLoadGame*)g_TESSaveLoadGame)->FUN_008579e0(&cell, 4);
                        e = FUN_00861cd0(cell.world);
                        p.x = cell.x;
                        p.y = cell.y;
                    }
                    else if (j & 0)
                    {
                        ExpiredCellLarge cell;
                        ((ExpiredSaveLoadGame*)g_TESSaveLoadGame)->FUN_008579e0(&cell, 6);
                        e = FUN_00861cd0(cell.world);
                        p.x = cell.x;
                        p.y = cell.y;
                    }
                    FUN_008579e0(&resetTime, 4);
                }
                currentBuffer = 0;
            }
            else
            {
                ExpiredReference* form = LookupFormByID(e);
                if (form && form->FUN_00401170() == 0x39)
                {
                    ExpiredCell* cell = (ExpiredCell*)form;
                    resetTime = cell->FUN_00546af0();
                    if (!cell->FUN_00425fd0())
                    {
                        e = cell->FUN_0054ddd0()->FUN_0084e3a0();
                        p.x = cell->FUN_00544c30();
                        p.y = cell->FUN_00544c60();
                    }
                }
            }
            if (resetTime && currentTime - resetTime > FUN_00526100())
            {
                ExpiredCellCoordinates* storedCoordinates = 0;
                if (p.x != 0x7fffffff)
                {
                    storedCoordinates = new ExpiredCellCoordinates;
                    __memcpy(storedCoordinates, &p, 8);
                    ExpiredCellList* cells = 0;
                    if (!expired.GetAt(e, cells))
                    {
                        cells = new ExpiredCellList;
                        expired.FUN_00844700(e, cells);
                    }
                    cells->FUN_005ae3d0(storedCoordinates);
                }
                else
                {
                    expired.FUN_00844700(e, 0);
                }
            }
        }
    }
    position = changes->FUN_004b9ba0();
    while (position)
    {
        ExpiredChangeData* s = 0;
        unsigned int f = 0;
        changes->FUN_006b7f20(position, f, s);
        unsigned int cf = s->FUN_00559450();
        unsigned int a = 0;
        int q = 0x7fffffff;
        int i = 0x7fffffff;
        ExpiredReference* h = 0;
        unsigned int eb = 0;
        ExpiredSaveHeader p;
        p.size = 0;
        if (s->FUN_00726070())
        {
            currentBuffer = s->FUN_00726070();
            ((ExpiredSaveLoadGame*)g_TESSaveLoadGame)->FUN_008579e0(&p, 4);
            eb = p.type;
            if (eb == 0x3a || eb == 0x3b || eb == 0x3c || eb == 0x3d || eb == 0x3e || eb == 0x3f || eb == 0x69 ||
                eb == 0x40)
            {
                if (cf & 0)
                {
                    ExpiredMoveWithFlags move;
                    ((ExpiredSaveLoadGame*)g_TESSaveLoadGame)->FUN_008579e0(&move, 0x24);
                    a = move.parent;
                    q = (int)move.x >> 12;
                    i = (int)move.y >> 12;
                }
                else if (cf & 6)
                {
                    if (cf & 0)
                    {
                        ExpiredMoveWithExtra move;
                        ((ExpiredSaveLoadGame*)g_TESSaveLoadGame)->FUN_008579e0(&move, 0x2c);
                        a = move.parent;
                        q = (int)move.x >> 12;
                        i = (int)move.y >> 12;
                    }
                    else
                    {
                        ExpiredMove move;
                        ((ExpiredSaveLoadGame*)g_TESSaveLoadGame)->FUN_008579e0(&move, 0x1c);
                        a = move.parent;
                        q = (int)move.x >> 12;
                        i = (int)move.y >> 12;
                    }
                }
                a = FUN_00861c00(a);
            }
            currentBuffer = 0;
        }
        else
        {
            ExpiredReference* form = LookupFormByID(f);
            if (form)
            {
                eb = form->FUN_00401170();
                if (eb == 0x3a || eb == 0x3b || eb == 0x3c || eb == 0x3d || eb == 0x3e || eb == 0x3f || eb == 0x69 ||
                    eb == 0x40)
                {
                    h = form;
                    ExpiredCell* cell = h->FUN_008d6f30();
                    if (cell)
                    {
                        if (cell->FUN_00425fd0())
                        {
                            a = cell->FUN_0084e3a0();
                            q = 0;
                            i = 0;
                        }
                        else
                        {
                            a = cell->FUN_0054ddd0()->FUN_0084e3a0();
                            q = cell->FUN_00544c30();
                            i = cell->FUN_00544c60();
                        }
                    }
                }
            }
        }
        if (a && q != 0x7fffffff && i != 0x7fffffff)
        {
            ExpiredCellList* cells = 0;
            if (expired.GetAt(a, cells))
            {
                bool reset = false;
                if (!cells)
                {
                    reset = true;
                }
                else
                {
                    while (cells && *cells->FUN_006815c0())
                    {
                        ExpiredCellCoordinates* coordinates = *cells->FUN_006815c0();
                        if (coordinates && coordinates->x == q && coordinates->y == i)
                        {
                            reset = true;
                            break;
                        }
                        cells = cells->FUN_00726070();
                    }
                }
                if (reset)
                {
                    if ((cf & 4) && !(cf & 0) && !(cf & 2))
                    {
                        if (cf == 4)
                        {
                            changes->FUN_00855220(f, true);
                        }
                        else
                        {
                            if (s->FUN_00726070())
                            {
                                char* b = s->FUN_00726070();
                                unsigned int l = 0;
                                cf &= ~4;
                                cf = cf;
                                if (cf & 0)
                                {
                                    cf = cf;
                                    l = 0x2c;
                                }
                                else
                                {
                                    l = 0x1c;
                                }
                                p.size -= l;
                                unsigned int ba = p.size;
                                if (cf & 0)
                                    p.size += 4;
                                void* k = FUN_00858600(p.size + 4);
                                ((ExpiredSaveLoadGame*)g_TESSaveLoadGame)->FUN_008579b0(&p, 4);
                                if (cf & 0)
                                {
                                    unsigned int storedWorld = a;
                                    ((ExpiredSaveLoadGame*)g_TESSaveLoadGame)->FUN_008579b0(&storedWorld, 4);
                                }
                                FUN_008579b0(b + l + 4, ba);
                                _Deallocate(b);
                                s->FUN_006ecd40(k);
                                s->FUN_00537e90(cf);
                                currentBuffer = 0;
                            }
                            else if (h)
                            {
                                changes->FUN_00855150(h, 4);
                            }
                        }
                        if (h)
                            FUN_00857d10(h, false);
                    }
                    if ((eb == 0x3b || eb == 0x3c) && ::g_dataHandler->FormIDExists(f))
                    {
                        changes->FUN_00855220(f, true);
                        if (h)
                        {
                            delete h;
                            h = 0;
                        }
                    }
                    if (eb == 0x3a || eb == 0x3d || eb == 0x3e || eb == 0x3f || eb == 0x69 || eb == 0x40)
                    {
                        if (cf & 0)
                        {
                            changes->FUN_00855220(f, true);
                            if (h)
                            {
                                delete h;
                                h = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    position = expired.FUN_004b9ba0();
    while (position)
    {
        ExpiredCellList* p = 0;
        unsigned int j = 0;
        expired.FUN_006b7f20(position, j, p);
        if (p)
        {
            ExpiredCellList* node = p;
            while (node && *node->FUN_006815c0())
            {
                delete *node->FUN_006815c0();
                node->FUN_0063f7b0();
            }
            delete p;
        }
    }
    expired.FUN_00438af0();
    FUN_008a8150(wasEnabled);
}

// NiTMap destructor: remove all entries, then the base map destructor frees the hash table.

class F3740MapBase
{
  public:
    virtual ~F3740MapBase();
    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_00863740 : public F3740MapBase
{
  public:
    virtual ~FUN_00863740();
};

// Destructor that calls RemoveAll to clear the hash table entries.
// @fnv 0x00863740
FUN_00863740::~FUN_00863740()
{
    RemoveAll();
}

struct RequestValue
{
    unsigned int first, second;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long* dest, long exch,
                                                                           long comparand);

struct FUN_00c3e690_Req
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    volatile long m_0c;
    RequestValue value;
};

class FUN_00c3e690_cls
{
  public:
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
// @fnv 0x00c3e690
    virtual void v18(FUN_00c3e690_Req* apRequest)
    {}
    void FUN_0044e050(FUN_00c3e690_Req* p);
    bool FUN_00c3e690(FUN_00c3e690_Req* p, RequestValue value);
};

bool FUN_00c3e690_cls::FUN_00c3e690(FUN_00c3e690_Req* p, RequestValue value)
{
    long v = p->m_0c;
    if (v == 0)
    {
        p->value = value;
        return true;
    }
    else if (v < 3)
    {
        bool ok = InterlockedCompareExchange(&p->m_0c, 2, v) == v;
        if (ok)
        {
            FUN_0044e050(p);
            p->value = value;
            bool ok2 = InterlockedCompareExchange(&p->m_0c, 0, 2) == 2;
            if (ok2)
            {
                v18(p);
            }
            return true;
        }
    }
    return false;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

extern unsigned char DAT_01202df0;

struct ArrSI
{
    void __thiscall FUN_00446f70();
};

struct FUN_00c3e750_Class
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
    volatile long a44;
    volatile long a48;
    unsigned int a4c;
    ArrSI** a50;

    bool __thiscall FUN_00c3e750();
};

// Sets DAT_01202df0 to 0; if the increment of a48 reaches 1, waits for a44 to clear, then calls FUN_00446f70 on each a50 element and increments a44.
// @fnv 0x00c3e750
bool __thiscall FUN_00c3e750_Class::FUN_00c3e750()
{
    unsigned int index;

    {
        unsigned int index;
    }

    {
        unsigned int index;
    }

    {
        unsigned int index;
    }

    DAT_01202df0 = 0;

    if (InterlockedIncrement(&this->a48) == 1)
    {
        while (this->a44 != 0)
        {
            Sleep(1);
        }

        for (index = 0; index < this->a4c; ++index)
        {
            this->a50[index]->FUN_00446f70();
            InterlockedIncrement(&this->a44);
        }

        return true;
    }

    return false;
}

struct Cmd61
{
    void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
};
struct Node61
{
    Cmd61** FUN_006815c0();
};
Node61* __fastcall FUN_00726070(Node61* p);
struct List61 : Node61
{
    void FUN_00905330(Cmd61* const& c);
};
struct Map61
{
    bool GetAt(const char* k, List61*& v) const;
};
class Own61
{
  public:
    int pad[4];
    Map61* m_10;
    void* RemoveCommand(const char* key, int a, int b);
};
// Looks up key in m_10, scans the list for a command matching a and b, removes and deletes it, and returns its stored pointer.
// @fnv 0x00861640
void* Own61::RemoveCommand(const char* key, int a, int b)
{
    List61* list;
    if (!m_10)
        return 0;
    {
        bool found;
        Node61* it;
        found = m_10->GetAt(key, list);
        if (!found)
            return 0;
        it = list;
        while (it)
        {
            Cmd61* cmd = *it->FUN_006815c0();
            if (cmd && a == cmd->m_iWordAt04 && b == cmd->m_8)
            {
                void* r = cmd->m_iWordAt00;
                list->FUN_00905330(cmd);
                delete cmd;
                return r;
            }
            it = FUN_00726070(it);
        }
    }
    return 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long*, long, long);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct ObjA
{
    int unk00, unk04;
    volatile long count;
    void FUN_0044dd60();
};
struct Ptr
{
    ObjA* p;
};
struct Node
{
    Node* next;
    Ptr value;
};
struct Queue
{
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void dec();
    Node* head;
    Node* tail;
};
struct Worker
{
    Queue* queue;
    volatile unsigned long* hazardHead;
    volatile unsigned long* hazardNext;
    void FUN_00c3f090(Node*);
    bool TryDequeue(Ptr* output);
};
// Pops the queue head with hazard-pointer protection, copies its value into output, retires the node and returns whether an item was dequeued.
// @fnv 0x00c3ea60
bool Worker::TryDequeue(Ptr* output)
{
    Node* volatile head = 0;
    while (true)
    {
        head = queue->head;
        *hazardHead = (unsigned long)head;
        if (head != queue->head)
            continue;
        int A2;
        int A5Kz9;
        int A;
        (void)&A2;
        (void)&A5Kz9;
        (void)&A;
        Node* tailNode = queue->tail;
        Node* volatile next = head->next;
        *hazardNext = (unsigned long)next;
        if (head != queue->head)
            continue;
        if (!next)
        {
            *hazardHead = 0;
            if (output->p != 0)
            {
                if (output->p)
                    output->p->FUN_0044dd60();
                output->p = 0;
                if (output->p)
                {
                    ObjA* object = output->p;
                    InterlockedIncrement(&object->count);
                }
            }
            return false;
        }
        if (head == tailNode)
        {
            Node* value2 = next;
            Node* volatile* location = &queue->tail;
            bool success3 =
                InterlockedCompareExchange((volatile long*)location, (long)value2, (long)tailNode) == (long)tailNode;
            continue;
        }
        {
            Ptr* source = &next->value;
            ObjA* object;
            int A5KzC;
            int A5KzF;
            int A9Qx9;
            (void)&A5KzC;
            (void)&A5KzF;
            (void)&A9Qx9;
            if (output->p != source->p)
            {
                if (output->p)
                    output->p->FUN_0044dd60();
                output->p = source->p;
                if (output->p)
                {
                    object = output->p;
                    InterlockedIncrement(&object->count);
                }
            }
        }
        {
            Node* expected = head;
            Node* value = next;
            Node* volatile* location4 = &queue->head;
            bool successTmp =
                InterlockedCompareExchange((volatile long*)location4, (long)value, (long)expected) == (long)expected;
            if (successTmp)
            {
                int A5KzC;
                int A5KzF;
                int A9Qx9;
                (void)&A5KzC;
                (void)&A5KzF;
                (void)&A9Qx9;
                queue->dec();
                {
                    Ptr* output = &next->value;
                    ObjA* obj2;
                    if (output->p != 0)
                    {
                        if (output->p)
                            output->p->FUN_0044dd60();
                        output->p = 0;
                        if (output->p)
                        {
                            obj2 = output->p;
                            InterlockedIncrement(&obj2->count);
                        }
                    }
                }
                break;
            }
        }
    }
    *hazardHead = 0;
    *hazardNext = 0;
    FUN_00c3f090(head);
    return true;
}

namespace fnv_00855150 {
struct FUN_00855130_This
{
    TESObjectREFR* FUN_00855130(TESForm*);
};
struct Chg00855220
{
    void* FUN_00854fe0(unsigned int);
};
struct FUN_00855150_cls
{
    void RemoveKey(unsigned int id);
    bool FUN_00855150(TESForm* form, unsigned int flags);
};

struct GlobalObj0047c850
{
    bool FUN_0047c850();
};
extern GlobalObj0047c850* DAT_011de45c;

struct RefCalls00855150
{
    void FUN_00854e70(unsigned int flags);
    int FUN_00559450();
};

struct FormCalls00855150
{
    unsigned int FUN_0084e3a0();
};

// @fnv 0x00855150
bool FUN_00855150_cls::FUN_00855150(TESForm* form, unsigned int flags)
{
    if (DAT_011de45c->FUN_0047c850())
    {
        return false;
    }
    TESObjectREFR* ref = ((FUN_00855130_This*)this)->FUN_00855130(form);
    if (ref != 0)
    {
        ((RefCalls00855150*)ref)->FUN_00854e70(flags);
        if (((RefCalls00855150*)ref)->FUN_00559450() == 0)
        {
            this->RemoveKey(((FormCalls00855150*)form)->FUN_0084e3a0());
            TESObjectREFR* a4 = ref;
            TESObjectREFR* b = a4;
            (void)(b ? ((Chg00855220*)b)->FUN_00854fe0(1) : (void*)0);
        }
        return true;
    }
    return false;
}
}  // namespace fnv_00855150

namespace fnv_00861820 {
class FormX
{
  public:
    virtual void v0(), v1(), v2(), v3(), v4(), v5(), v6(), v7(), v8(), v9(), v10();
    virtual void F2c();
    unsigned int GetGlobalValue();
    void* GetGlobalPointer();
    char FUN_00401170();
    unsigned int FUN_0084e3a0();
    void ResetGlobalPointer();
};
extern "C" void* __cdecl FUN_00ec43fb(void* p, long off, void* src, void* dst, int isRef);
extern char DAT_01183028, DAT_01183108, DAT_01183060, DAT_011839b4;
class EnchX
{
  public:
    FormX* FUN_00726070();
};
FormX* LookupFormByID(unsigned int id);
void FUN_005b5e40(const char* fmt, ...);
struct ListX
{
    bool FUN_00469860(unsigned int id);
};
extern ListX* g_pkList;

struct FUN_006815c0
{
    unsigned int uiID;
    char cType;
    char c5, c6, c7, c8, c9;
    unsigned short usSize;
    FUN_006815c0();
};

typedef FUN_006815c0 EntryX;
struct ChangesX
{
    void AddReferenceRecord(EntryX* p);
};
struct NodeX
{
    unsigned int* FUN_006815c0();
    NodeX* FUN_00726070();
};
struct BufX;
class SelfX
{
  public:
    char pad[0x2c];
    NodeX m2c;
    char pad2[0x44 - 0x2c - 1];
    ChangesX* m44;
    void FUN_00857b50(BufX* pBuf, void* p, unsigned int n);
    void FUN_00861820(BufX* pBuf);
};
// @fnv 0x00861820
void SelfX::FUN_00861820(BufX* pBuf)
{
    unsigned int uiCount_ggbd = 0;
    NodeX* pkNode_dhyats = &m2c;
    while (pkNode_dhyats)
    {
        unsigned int uiID = *pkNode_dhyats->FUN_006815c0();
        FormX* pkForm = LookupFormByID(uiID);
        if (pkForm)
        {
            FormX* pkBound = (FormX*)FUN_00ec43fb(pkForm, 0, &DAT_01183028, &DAT_01183108, 0);
            FormX* pkSpell = (FormX*)FUN_00ec43fb(pkForm, 0, &DAT_01183028, &DAT_01183060, 0);
            EnchX* pkEnch_db = (EnchX*)FUN_00ec43fb(pkForm, 0, &DAT_01183028, &DAT_011839b4, 0);
            if (pkEnch_db && !pkEnch_db->FUN_00726070())
            {
                pkNode_dhyats = pkNode_dhyats->FUN_00726070();
                continue;
            }
            if (pkEnch_db && pkEnch_db->FUN_00726070() &&
                g_pkList->FUN_00469860(pkEnch_db->FUN_00726070()->FUN_0084e3a0()))
                uiCount_ggbd++;
            if (pkBound || pkSpell)
                uiCount_ggbd++;
        }
        pkNode_dhyats = pkNode_dhyats->FUN_00726070();
    }
    FUN_00857b50(pBuf, &uiCount_ggbd, 4);
    if (!uiCount_ggbd)
        return;
    pkNode_dhyats = &m2c;
    while (pkNode_dhyats)
    {
        unsigned int uiFormID_wk = *pkNode_dhyats->FUN_006815c0();
        FormX* pkObj = LookupFormByID(uiFormID_wk);
        if (pkObj)
        {
            FormX* pkBoundObj_ai = (FormX*)FUN_00ec43fb(pkObj, 0, &DAT_01183028, &DAT_01183108, 0);
            FormX* pkSpellItem = (FormX*)FUN_00ec43fb(pkObj, 0, &DAT_01183028, &DAT_01183060, 0);
            if (pkBoundObj_ai || pkSpellItem)
            {
                EnchX* pkEnchForm_siup = (EnchX*)FUN_00ec43fb(pkObj, 0, &DAT_01183028, &DAT_011839b4, 0);
                if (pkEnchForm_siup)
                {
                    FormX* pkEnchItem = pkEnchForm_siup->FUN_00726070();
                    if (!pkEnchItem)
                    {
                        FUN_005b5e40(
                            "SAVELOAD: Enchantable item %08X with no enchantment exists in the created base objects list.",
                            uiFormID_wk);
                        pkNode_dhyats = pkNode_dhyats->FUN_00726070();
                        continue;
                    }
                    if (g_pkList->FUN_00469860(pkEnchItem->FUN_0084e3a0()))
                    {
                        pkEnchItem->F2c();
                        unsigned int uiEnchSize = pkEnchItem->GetGlobalValue();
                        FUN_00857b50(pBuf, pkEnchItem->GetGlobalPointer(), uiEnchSize);
                        if (m44)
                        {
                            EntryX kEnchEntry;
                            kEnchEntry.cType = pkEnchItem->FUN_00401170();
                            kEnchEntry.uiID = pkEnchItem->FUN_0084e3a0();
                            kEnchEntry.usSize = (unsigned short)uiEnchSize;
                            *(unsigned int*)&kEnchEntry.c5 = 0;
                            m44->AddReferenceRecord(&kEnchEntry);
                        }
                        pkEnchItem->ResetGlobalPointer();
                    }
                }
                pkObj->F2c();
                unsigned int uiSize = pkObj->GetGlobalValue();
                FUN_00857b50(pBuf, pkObj->GetGlobalPointer(), uiSize);
                if (m44)
                {
                    EntryX kEntry;
                    kEntry.cType = pkObj->FUN_00401170();
                    kEntry.uiID = uiFormID_wk;
                    kEntry.usSize = (unsigned short)uiSize;
                    *(unsigned int*)&kEntry.c5 = 0;
                    m44->AddReferenceRecord(&kEntry);
                }
                pkObj->ResetGlobalPointer();
            }
        }
        pkNode_dhyats = pkNode_dhyats->FUN_00726070();
    }
}
}  // namespace fnv_00861820

namespace fnv_00863960 {
struct NiTPointerMap_Standin
{
    void RemoveAll();
};
struct FUN_00863ff0_class
{
    void FUN_008639c0();
    virtual ~FUN_00863ff0_class()
    {
        FUN_008639c0();
    }
};
struct FUN_00863960 : FUN_00863ff0_class
{
    virtual ~FUN_00863960();
};
// Calls RemoveAll through a NiTPointerMap_Standin pointer.
// @fnv 0x00863960
FUN_00863960::~FUN_00863960()
{
    ((NiTPointerMap_Standin*)this)->RemoveAll();
}
}  // namespace fnv_00863960

class FUN_00863f00
{
  public:
    virtual ~FUN_00863f00();

    void FUN_00438af0();
};

class FUN_00863ea0 : public FUN_00863f00
{
  public:
    virtual ~FUN_00863ea0();
};

// Calls FUN_00438af0 before returning.
// @fnv 0x00863ea0
FUN_00863ea0::~FUN_00863ea0()
{
    FUN_00438af0();
}

namespace fnv_004f12b0 {
struct RegionListSize
{
    int FUN_005ae380();
};
struct RegionList
{
    int unk00;
    RegionListSize entries;
};
struct DataHandlerSize
{
    RegionList* FUN_004169d0();
};
extern DataHandlerSize* DAT_011c3f2c;
// Returns 2 plus eight times the value returned by the region-list entry-count method.
// @fnv 0x004f12b0
unsigned short FUN_004f12b0()
{
    unsigned short v = 0;
    v += 2;
    RegionList* q = DAT_011c3f2c->FUN_004169d0();
    v += q->entries.FUN_005ae380() * 8;
    return v;
}
}  // namespace fnv_004f12b0

namespace fnv_00858030 {
struct Vec58030
{
    int x;
    int y;
    int z;
};
struct Ref58030
{
    int __thiscall FUN_0084e3a0();
};
struct DH58030
{
    int __thiscall GetField208();
};
extern DH58030* DAT_011c3f2c;
struct TES58030
{
    Ref58030* __thiscall FUN_004fd3e0();
    int __thiscall FUN_0059bb30();
    int __thiscall FUN_0045cd60();
    unsigned short __thiscall FUN_00459100();
    void __thiscall WriteSaveBlock();
};
extern TES58030* DAT_011dea10;
struct Player58030
{
    Ref58030* __thiscall FUN_00575d70();
    Ref58030* __thiscall FUN_008d6f30();
    Vec58030* __thiscall FUN_00436aa0();
};
extern Player58030* DAT_011dea3c;
void __cdecl FUN_0040fbe0(const char* s);
struct Global58030
{
    unsigned short __thiscall GetTotalSize();
    void __thiscall FUN_009754f0();
};
extern Global58030 DAT_011e0e80;
struct Sky58030
{
    unsigned short __thiscall FUN_0063e940();
    void __thiscall FUN_0063e9f0();
};
Sky58030* __cdecl FUN_0046dd00();
unsigned short __cdecl FUN_007065c0();
void __cdecl SaveMenuTabStates();
unsigned short __cdecl FUN_004f12b0();
void __cdecl FUN_004f1300();
struct Field58030
{
    void __thiscall FUN_008558a0(int id, const char* name);
};
struct Host58030
{
    char unk00[0x44];
    Field58030* f44;
    void __thiscall FUN_00857b50(int a, void* p, int n);
    void __thiscall FUN_00858480(int a);
    int __thiscall FUN_00858600(int id);
    void __thiscall ForwardToFUN_00857b50(int a, int x, int id);
    void __thiscall FUN_00858700(int x);
    void __thiscall FUN_00861820(int a);
    void __thiscall FUN_00858030(int aParam);
};

// Writes save data for the player, world, process lists, sky, HUD, interface, and regions into the save stream.
// @fnv 0x00858030
void __thiscall Host58030::FUN_00858030(int aParam)
{
    int v48;

    int v444;
    int v405;
    int v3c4;
    int v38;
    int v34;
    Ref58030* pCell_;
    int v2c;
    int v282;
    unsigned short w4;
    int v20;
    int v1c;
    int v182;
    int v14;
    Vec58030 vec;
    Ref58030* pWorld;

    v20 = DAT_011c3f2c->GetField208();
    FUN_00857b50(aParam, &v20, 4);
    v282 = DAT_011dea10->FUN_004fd3e0()->FUN_0084e3a0();
    FUN_00857b50(aParam, &v282, 4);
    v1c = DAT_011dea10->FUN_0059bb30();
    v2c = DAT_011dea10->FUN_0045cd60();
    FUN_00857b50(aParam, &v1c, 4);
    FUN_00857b50(aParam, &v2c, 4);

    pWorld = DAT_011dea3c->FUN_00575d70();
    pCell_ = DAT_011dea3c->FUN_008d6f30();
    if (pWorld == 0 && pCell_ == 0)
        FUN_0040fbe0("Player has no worldspace or parent cell, cannot save.");
    v14 = 0;
    if (pWorld != 0)
        v14 = pWorld->FUN_0084e3a0();
    else if (pCell_ != 0)
        v14 = pCell_->FUN_0084e3a0();
    vec = *DAT_011dea3c->FUN_00436aa0();
    FUN_00857b50(aParam, &v14, 4);
    FUN_00857b50(aParam, &vec, 12);
    FUN_00858480(aParam);

    w4 = DAT_011dea10->FUN_00459100();
    FUN_00857b50(aParam, &w4, 2);
    if (w4 != 0)
    {
        if (f44 != 0)
            f44->FUN_008558a0(w4, "TES Class");
        v34 = FUN_00858600(w4);
        DAT_011dea10->WriteSaveBlock();
        ForwardToFUN_00857b50(aParam, v34, w4);
        FUN_00858700(v34);
    }

    w4 = DAT_011e0e80.GetTotalSize();
    FUN_00857b50(aParam, &w4, 2);
    if (w4 != 0)
    {
        if (f44 != 0)
            f44->FUN_008558a0(w4, "Process Lists Class");
        v38 = FUN_00858600(w4);
        DAT_011e0e80.FUN_009754f0();
        ForwardToFUN_00857b50(aParam, v38, w4);
        FUN_00858700(v38);
    }

    w4 = FUN_0046dd00()->FUN_0063e940();
    FUN_00857b50(aParam, &w4, 2);
    if (w4 != 0)
    {
        if (f44 != 0)
            f44->FUN_008558a0(w4, "Sky/Weather");
        v3c4 = FUN_00858600(w4);
        FUN_0046dd00()->FUN_0063e9f0();
        ForwardToFUN_00857b50(aParam, v3c4, w4);
        FUN_00858700(v3c4);
    }

    v182 = 0;
    FUN_00857b50(aParam, &v182, 4);
    FUN_00861820(aParam);
    w4 = 0;
    FUN_00857b50(aParam, &w4, 2);
    if (w4 != 0)
    {
        if (f44 != 0)
            f44->FUN_008558a0(w4, "HUD Reticle");
        v405 = FUN_00858600(w4);
        ForwardToFUN_00857b50(aParam, v405, w4);
        FUN_00858700(v405);
    }

    w4 = FUN_007065c0();
    FUN_00857b50(aParam, &w4, 2);
    if (w4 != 0)
    {
        if (f44 != 0)
            f44->FUN_008558a0(w4, "Interface");
        v444 = FUN_00858600(w4);
        SaveMenuTabStates();
        ForwardToFUN_00857b50(aParam, v444, w4);
        FUN_00858700(v444);
    }

    w4 = FUN_004f12b0();
    FUN_00857b50(aParam, &w4, 2);
    if (w4 != 0)
    {
        if (f44 != 0)
            f44->FUN_008558a0(w4, "Regions");
        v48 = FUN_00858600(w4);
        FUN_004f1300();
        ForwardToFUN_00857b50(aParam, v48, w4);
        FUN_00858700(v48);
    }
}
}  // namespace fnv_00858030

enum MEM_CONTEXT
{
    MC_11 = 0x11
};
struct AutoMemContext
{
    int unk00;
    AutoMemContext(MEM_CONTEXT, bool, const char*, unsigned int);
    ~AutoMemContext();
};
extern const char DAT_010804c8[];
extern const char DAT_01080750[];
void* __cdecl operator new(unsigned int);
extern "C" void __cdecl FUN_0040fbe0(const char*);

struct SaveMemory
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* buffer;
    void* FUN_00858600(unsigned int);
};

// Allocates size bytes with operator new and calls FUN_0040fbe0 if the returned pointer is null.
// @fnv 0x00858600
void* SaveMemory::FUN_00858600(unsigned int size)
{
    AutoMemContext context(MC_11, true, DAT_010804c8, 0x103a);
    buffer = operator new(size);
    if (!buffer)
        FUN_0040fbe0(DAT_01080750);
    return buffer;
}

struct FUN_0085a2e0_Class
{
    ChangesMap* changes;
    void* unknown_04;
    void* unknown_08;
    void* unknown_0C;
    void* unknown_10;
    void* unknown_14;
    void* unknown_18;
    void* unknown_1C;
    void* unknown_20;
    void* unknown_24;
    void* unknown_28;
    void* unknown_2C;
    void* unknown_30;
    BSSimpleList<BGSNote*> deferred;
    void FUN_0085a2e0(TESForm*);
};

extern void __cdecl FUN_005b5e40(const char*);
extern const char DAT_010809a0[];
extern int __cdecl FUN_00ec43fb(void*, int, const void*, const void*, int);
extern const char DAT_01011584[];
struct IDSource0085a2e0
{
    int FUN_00469800(unsigned int);
};
struct FormCall0085a2e0
{
    bool FUN_0047c850();
    void FUN_00483c70();
};
struct FormIdOne0085a2e0
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
    virtual void SetFormID(unsigned int);
};
struct FormIdTwo0085a2e0
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
    virtual void SetFormID(unsigned int, unsigned int);
};
struct FormSlot77_0085a2e0
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
    virtual void Call(unsigned int);
};
struct DeferredAdd0085a2e0
{
    void FUN_005ae3d0(BGSNote**);
};
// Checks form changes, assigns an ID, and for non-temporary non-cell forms calls methods and adds the form to deferred if absent.
// @fnv 0x0085a2e0
void FUN_0085a2e0_Class::FUN_0085a2e0(TESForm* form)
{
    if (!reinterpret_cast<FormCall0085a2e0*>(this)->FUN_0047c850())
        FUN_005b5e40(DAT_010809a0);
    changes->HasFormChanges(form, true);
    int bIsCell = FUN_00ec43fb(form, 0, &typeid(TESForm), &typeid(TESObjectCELL), 0);
    if (form->IsTemporary() || bIsCell)
    {
        reinterpret_cast<FormIdOne0085a2e0*>(form)->SetFormID(
            reinterpret_cast<IDSource0085a2e0*>(DAT_011c3f2c)->FUN_00469800(1));
    }
    else
    {
        reinterpret_cast<FormIdTwo0085a2e0*>(form)->SetFormID(0, 1);
        reinterpret_cast<FormCall0085a2e0*>(form)->FUN_00483c70();
        reinterpret_cast<FormSlot77_0085a2e0*>(form)->Call(reinterpret_cast<unsigned int>(DAT_01011584));
        if (!deferred.IsInList(reinterpret_cast<BGSNote*&>(form)))
            reinterpret_cast<DeferredAdd0085a2e0*>(&deferred)->FUN_005ae3d0(reinterpret_cast<BGSNote**>(&form));
    }
}

extern "C" int __cdecl sprintf(char*, const char*, ...);
struct NiBinaryStream
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Seek(int offset, int origin);
};
extern char* DAT_011a2224;
extern unsigned int DAT_010a2480;
extern int DAT_010a2484;
extern const char DAT_01081bbc[];
extern const char DAT_01081b50[];
extern "C" int __cdecl FUN_00ec8a19(const char*, const char*, unsigned int);
void __cdecl FUN_00403d30(void*, int, unsigned int);
unsigned int BSStringLength(const char*);
void __fastcall CopyByteToOffset80(char*);
struct SaveLoadManager
{
    unsigned char FUN_008df040();
    void FUN_004534f0(unsigned int);
};
struct InventoryMenuSetting
{
    const char* FUN_00403df0();
};
extern InventoryMenuSetting g_011d34f8;
extern InventoryMenuSetting g_011d3684;
char __cdecl FUN_00704010(const char*, int, int, const char*, const char*, int);
struct SaveHeaderReader
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
    unsigned char majorVersion;
    unsigned char minorVersion;
    unsigned short unknown76;
    unsigned int unknown78;
    unsigned int unknown7c;
    unsigned int unknown80;
    unsigned int unknown84;
    unsigned int unknown88;
    unsigned int unknown8c;
    unsigned int fileOffset;
    unsigned int unknown94;
    unsigned char identifier[16];
    unsigned int identifierTail;
    unsigned int ReadFromStream(NiBinaryStream*, void*, unsigned int);
    unsigned int FUN_00860e20(NiBinaryStream* stream, bool loadIdentifier);
};
// Reads header data from the stream, may seek to 0xd000, and checks the loaded version fields.
// @fnv 0x00860e20
unsigned int SaveHeaderReader::FUN_00860e20(NiBinaryStream* stream, bool loadIdentifier)
{
    char header[260];
    fileOffset = 0;
    if (!ReadFromStream(stream, header, BSStringLength(DAT_011a2224)))
        return 0;
    if (header[0])
    {
        if (FUN_00ec8a19(header, DAT_01081bbc, 4) == 0)
        {
            stream->Seek(0xd000, DAT_010a2480);
            fileOffset = 0xd000;
            ReadFromStream(stream, header, BSStringLength(DAT_011a2224));
        }
        if (FUN_00ec8a19(header, DAT_011a2224, BSStringLength(DAT_011a2224)) != 0)
            return 0;
    }
    else
    {
        stream->Seek(0, DAT_010a2480);
    }
    {
        unsigned int result;
        ReadFromStream(stream, &majorVersion, 1);
        ReadFromStream(stream, &minorVersion, 1);
        CopyByteToOffset80(reinterpret_cast<char*>(this));
        if (reinterpret_cast<SaveLoadManager*>(::g_TESSaveLoadGame)->FUN_008df040() >= 0x52)
        {
            if (loadIdentifier)
            {
                ReadFromStream(stream, identifier, 16);
                ReadFromStream(stream, &identifierTail, 4);
            }
            else
            {
                stream->Seek(20, DAT_010a2484);
            }
        }
        if (reinterpret_cast<SaveLoadManager*>(::g_TESSaveLoadGame)->FUN_008df040() < 0x52 && loadIdentifier)
        {
            FUN_00403d30(identifier, 255, 16);
            identifierTail = -1;
        }
        ReadFromStream(stream, &result, 4);
        if (majorVersion || (loadIdentifier && minorVersion != 125 && minorVersion < 19))
        {
            char messageBuffer[520];
            (sprintf)(messageBuffer, DAT_01081b50, majorVersion, minorVersion, 0, 125);
            reinterpret_cast<SaveLoadManager*>(::g_TESSaveLoadGame)->FUN_004534f0(1);
            char response = FUN_00704010(messageBuffer, 1, 5, g_011d34f8.FUN_00403df0(), g_011d3684.FUN_00403df0(), 0);
            reinterpret_cast<SaveLoadManager*>(::g_TESSaveLoadGame)->FUN_004534f0(0);
            if (response == 2)
                result = -1;
        }
        return result;
    }
}

struct SaveGameFile56
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void Vf(int, int);
    virtual int Vg();
    unsigned int FUN_004720a0();
};

struct SaveGameMap56
{
    void* FUN_004b9ba0();
    void FUN_006b7f20(void*&, unsigned int&, void*&);
};

struct SettingString
{
    const char* GetString();
};

class GlobalObject_0040c150;
extern GlobalObject_0040c150 g_011d2364;

bool __cdecl QueueUIMessage(const char*, int, const char*, const char*, float, bool);

struct FUN_008579e0_shell
{
    void FUN_008579e0(void*, unsigned int);
};

struct TESSound;
struct EffectSetting
{
    void SetHitSound(TESSound*);
};

struct FUN_00c3e310_shell
{
    void FUN_00c3e310();
};

struct IOManager;
extern const char DAT_0107fae0[];
extern const char g_011d2cd0_arg1[];
extern const char DAT_010804c8[];
extern unsigned int DAT_010a2480;

int __cdecl FUN_00408b20(const char*, const char*);
void __fastcall FUN_00c3e340(IOHeader*);
extern "C" void* _ref_004839c0(unsigned int);
void* __fastcall FUN_00726070_ref(void*);
int __fastcall FUN_00559450_ref(void*);

struct Rec56
{
    int a;
    char b;
    char c0;
    char c1;
    char c2;
    char c3;
    char d;
    char unk0A;
    char unk0B;
    Rec56();
};

union WordBuf
{
    unsigned int u;
    struct
    {
        char b0;
        char b1;
        char b2;
        char b3;
    };
};

struct Obj44
{
    int unk00;
    int unk04;
    Obj44();
    ~Obj44();
    void FUN_00855ba0(int);
};

struct FormObj : public SaveGameFile56
{
    void FUN_00857210();
};

struct FUN_00401170_s
{
    char FUN_00401170();
};

struct Obj56
{
    virtual void Va();
    virtual void Vb();
    virtual void Vc();
    virtual void Vd();
    virtual void Ve();
    virtual void Vf();
    virtual void Vg2();
    virtual void Vh();
    virtual void Vi();
    virtual void Vj();
    virtual void Vk();
    virtual void Vl();
    virtual void Vm();
    virtual void Vn();
    virtual void Vo();
    virtual void Vp();
    virtual void Vq();
    virtual void Vr();
    virtual void Vs();
    virtual void Vt();
    virtual unsigned short Vu(int);
    virtual void Vv();
    virtual void Vw(int);
};

struct FUN_00485d50_slg
{
    bool GetLoading();
};

struct FUN_008df040_shell
{
    char FUN_008df040();
};

struct Cls56
{
    SaveGameMap56* m_00;
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
    Obj44* m_44;
    bool FUN_008616f0();
    void FUN_00858030(FormObj*);
    void FUN_00862150(FormObj*);
    unsigned short FUN_0085a450(Obj56*, int);
    void FUN_0085a520(Obj56*, int);
    void* FUN_00858600(int);
    void FUN_00858700(void*);
    bool FUN_00856ca0(int, int, unsigned char);
};

// Checks the path when saving, writes the header and plugin list, processes map entries, and releases the file when saving.
// @fnv 0x00856ca0
bool Cls56::FUN_00856ca0(int aiFileHandle, int apSavePath, unsigned char p2)
{
    void* mapPos;
    FormObj* pForm;
    AutoMemContext helper(static_cast<MEM_CONTEXT>(0x11), true, DAT_010804c8, 0x466);
    int filePos2;
    int seekPos;
    int recs;
    int rTmp;

    if (!((FUN_00485d50_slg*)this)->GetLoading() && !FUN_008616f0())
    {
        if (apSavePath == 0 || FUN_00408b20((const char*)apSavePath, DAT_0107fae0) != 0)
        {
            QueueUIMessage(((SettingString*)&g_011d2364)->GetString(), 0, g_011d2cd0_arg1, 0, 2.0f, false);
            return false;
        }
    }
    ((FUN_00c3e310_shell*)DAT_01202d98)->FUN_00c3e310();
    ((::ExpiredSaveLoadGame*)this)->PurgeExpiredCellChanges();
    pForm = 0;
    if (!((FUN_00485d50_slg*)this)->GetLoading())
    {
        pForm = (FormObj*)((::SaveOwner*)this)->OpenSaveFile((::SaveFile*)aiFileHandle, (const char*)apSavePath, 0);
    }
    if (p2)
    {
        m_44 = new Obj44();
    }
    ((::FUN_008620f0*)this)->Init();
    ::CopyByteToOffset80((char*)this);
    ((::SaveHeader*)this)->WriteSaveHeader(pForm, (const char*)apSavePath);
    ((::FUN_0085b240_cls*)this)->WritePluginList((::FUN_0085b240_ref*)pForm);
    seekPos = 0;
    if (!((FUN_00485d50_slg*)this)->GetLoading())
    {
        seekPos = (int)pForm->FUN_004720a0();
    }
    rTmp = 0;
    ((::FUN_008586a0_class*)this)->FUN_00857b50((int)pForm, (int)&rTmp, 4);
    ((::FUN_008586a0_class*)this)->FUN_00857b50((int)pForm, (int)&rTmp, 4);
    FUN_00858030(pForm);
    recs = 0;
    mapPos = m_00->FUN_004b9ba0();
    while (mapPos)
    {
        void* value1 = 0;
        unsigned int mapKey = 0;
        m_00->FUN_006b7f20(mapPos, mapKey, value1);
        if (mapKey && value1)
        {
            m_14 = (int)FUN_00726070_ref(value1);
            int refVal = FUN_00559450_ref(value1);
            Rec56 recData;
            recData.a = (int)mapKey;
            *(int*)&recData.c0 = refVal;
            recData.d = ((FUN_008df040_shell*)this)->FUN_008df040();
            if (m_14)
            {
                WordBuf wordBuf;
                ((FUN_008579e0_shell*)g_TESSaveLoadGame)->FUN_008579e0(&wordBuf, 4);
                recData.b = wordBuf.b2;
                recData.d = wordBuf.b3;
                ((::FUN_008586a0_class*)g_TESSaveLoadGame)->FUN_00857b50((int)pForm, (int)&recData, 10);
                recs++;
                ((::FUN_008586a0_class*)this)->FUN_00857b50((int)pForm, (int)&wordBuf, 2);
                if ((unsigned short)wordBuf.u)
                {
                    ((::FUN_008586a0_class*)this)->FUN_00857b50((int)pForm, m_14, (unsigned short)wordBuf.u);
                }
                if (m_44)
                {
                    ((::FUN_00855970_cls*)m_44)->ApplyKeyWithFlags((::Key_855970*)&recData, (unsigned short)wordBuf.u);
                }
                m_14 = 0;
            }
            else
            {
                Obj56* obj = (Obj56*)_ref_004839c0(mapKey);
                if (obj)
                {
                    recData.b = ((FUN_00401170_s*)obj)->FUN_00401170();
                    *(int*)&recData.c0 = ((::ChangeValidation::Changes*)this)
                                             ->UpdateFormFlags((::ChangeValidation::Form*)obj, *(int*)&recData.c0);
                    ((::FUN_008586a0_class*)g_TESSaveLoadGame)->FUN_00857b50((int)pForm, (int)&recData, 10);
                    recs++;
                    ((EffectSetting*)this)->SetHitSound((TESSound*)&recData);
                    unsigned short soundVal = obj->Vu(*(int*)&recData.c0);
                    soundVal += FUN_0085a450(obj, *(int*)&recData.c0);
                    ((::FUN_008586a0_class*)this)->FUN_00857b50((int)pForm, (int)&soundVal, 2);
                    if (soundVal)
                    {
                        void* tempObj = FUN_00858600(soundVal);
                        FUN_0085a520(obj, *(int*)&recData.c0);
                        obj->Vw(*(int*)&recData.c0);
                        ((::FUN_008586a0_class*)this)->ForwardToFUN_00857b50((int)pForm, (int)tempObj, soundVal);
                        FUN_00858700(tempObj);
                    }
                    ((EffectSetting*)this)->SetHitSound(0);
                    if (m_44)
                    {
                        ((::FUN_00855970_cls*)m_44)->ApplyKeyWithFlags((::Key_855970*)&recData, soundVal);
                    }
                }
            }
        }
    }
    ((::fnv_00858570::FUN_00858570_class*)this)->LoadTempEffectsList((int)pForm);
    filePos2 = 0;
    if (!((FUN_00485d50_slg*)this)->GetLoading())
    {
        filePos2 = (int)pForm->FUN_004720a0();
    }
    ((::fnv_00861d10::TESSaveLoadGame_standin*)this)->WriteFormIDArrays((::fnv_00861d10::BSFile*)pForm);
    if (!((FUN_00485d50_slg*)this)->GetLoading())
    {
        pForm->Vf(seekPos, (int)DAT_010a2480);
        ((::FUN_008586a0_class*)this)->FUN_00857b50((int)pForm, (int)&filePos2, 4);
        ((::FUN_008586a0_class*)this)->FUN_00857b50((int)pForm, (int)&recs, 4);
    }
    if (m_44)
    {
        int vcallRes = pForm->Vg();
        m_44->FUN_00855ba0(vcallRes);
        delete m_44;
        m_44 = 0;
    }
    if (!((FUN_00485d50_slg*)this)->GetLoading())
    {
        pForm->FUN_00857210();
        FUN_00862150(pForm);
        ((::fnv_008578b0::FUN_008578b0_Class*)this)->ReleaseFile((::fnv_008578b0::BSFile*)pForm, 0);
    }
    FUN_00c3e340(DAT_01202d98);
    return true;
}

namespace SaveInitialData85A520 {
struct SavePoint85A520
{
    float x, y, z;
};
extern SavePoint85A520 DAT_011f426c;
class SaveForm85A520
{
  public:
    virtual void v00();
    unsigned int FUN_0084e3a0();
};
class SaveCell85A520 : public SaveForm85A520
{
  public:
    SaveForm85A520* FUN_0054ddd0();
    unsigned short FUN_00544c30();
    unsigned short FUN_00544c60();
    bool FUN_00425fd0();
};
struct SaveExtra85A520
{
    SaveCell85A520* FUN_0041d460();
};
struct SaveProcess85A520
{
    int FUN_0045cd60();
};
struct SaveEffect85A520
{
    unsigned int FUN_004086a0();
};
struct SaveMagic85A520
{
    SaveEffect85A520* FUN_00825c00();
};
class TESObjectREFR85A520 : public SaveForm85A520
{
  public:
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
    virtual void v4a();
    virtual void v4b();
    virtual const char* GetName();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual SavePoint85A520 GetEditorPosition();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
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
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual void v7d();
    virtual void v7e();
    virtual void v7f();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v8a();
    virtual void v8b();
    virtual void v8c();
    virtual void v8d();
    virtual void v8e();
    virtual void v8f();
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
    virtual void v9a();
    virtual void v9b();
    virtual void v9c();
    virtual void v9d();
    virtual void v9e();
    virtual void v9f();
    virtual void va0();
    virtual void va1();
    virtual void va2();
    virtual void va3();
    virtual void va4();
    virtual SaveForm85A520* va5();
    virtual SaveForm85A520* va6();
    SaveCell85A520* FUN_008d6f30();
    bool FUN_005653d0();
    SaveExtra85A520* FUN_005d43c0();
    SavePoint85A520& FUN_00436aa0();
    SavePoint85A520& FUN_00430830();
    SaveForm85A520* FUN_007af430();
    SaveForm85A520* FUN_00575d70();
};
class SaveMobile85A520 : public TESObjectREFR85A520
{
  public:
    SaveProcess85A520* FUN_008d8520();
};
class ArrowProjectile85A520 : public TESObjectREFR85A520
{
};
class MagicProjectile85A520 : public TESObjectREFR85A520
{
  public:
    SaveMagic85A520* FUN_00586150();
};
class Actor85A520 : public SaveMobile85A520
{
};
struct LocationRecord85A520
{
    unsigned int cell;
    SavePoint85A520 position;
    SavePoint85A520 rotation;
    void FUN_008572f0();
};
struct ReferenceRecord85A520
{
    int type;
    unsigned int base;
    LocationRecord85A520 savedLocation;
    void FUN_008572c0();
};
struct MoveRecord85A520
{
    unsigned int cell;
    SavePoint85A520 editorPosition;
    LocationRecord85A520 savedLocation;
    void FUN_00857320();
};
struct SmallCellRecord85A520
{
    unsigned short id;
    unsigned char x, y;
};
struct LargeCellRecord85A520
{
    unsigned short id, x, y;
};
struct SaveStream85A520
{
    void FUN_008579b0(void*, int);
};
extern "C" void* _FNV_DynamicCast(void*, int, void*, void*, int);
extern int DAT_01183028;
extern int DAT_011841cc;
extern int DAT_01183fb4;
extern int DAT_01184920;
extern int DAT_011a28e0;
extern int DAT_011a0e88;
extern int DAT_011846d4;
extern const char DAT_01080ba8[];
extern const char DAT_01080b38[];
extern const char DAT_01080ae8[];
extern const char DAT_01080a90[];
extern const char DAT_01080a40[];
extern const char DAT_010809e8[];
namespace SaveWarning85A520 {
void __cdecl FUN_005b5e40(const char*, ...);
}
struct SaveHandler85A520
{
    unsigned short FUN_00861c60(unsigned int);
    unsigned int FindOrAddValue(unsigned int);
    void FUN_0085a520(SaveForm85A520*, unsigned int);
};
// When flags & 6 is nonzero, writes the parent's position, rotation, and resolved cell ID as a 28-byte record.
// @fnv 0x0085a520
void SaveHandler85A520::FUN_0085a520(SaveForm85A520* form, unsigned int flags)
{
    TESObjectREFR85A520* parent = (TESObjectREFR85A520*)_FNV_DynamicCast(form, 0, &DAT_01183028, &DAT_011841cc, 0);
    if (!parent)
    {
        SaveCell85A520* cell = (SaveCell85A520*)_FNV_DynamicCast(form, 0, &DAT_01183028, &DAT_01183fb4, 0);
        if (cell)
        {
            if (flags & 0)
            {
                SmallCellRecord85A520 small;
                small.id = FUN_00861c60(cell->FUN_0054ddd0()->FUN_0084e3a0());
                small.x = (unsigned char)cell->FUN_00544c30();
                small.y = (unsigned char)cell->FUN_00544c60();
                ((SaveStream85A520*)::DAT_011de45c)->FUN_008579b0(&small, 4);
            }
            else if (flags & 0)
            {
                LargeCellRecord85A520 large;
                large.id = FUN_00861c60(cell->FUN_0054ddd0()->FUN_0084e3a0());
                large.x = cell->FUN_00544c30();
                large.y = cell->FUN_00544c60();
                ((SaveStream85A520*)::DAT_011de45c)->FUN_008579b0(&large, 6);
            }
        }
        return;
    }
    LocationRecord85A520 savedLocation;
    savedLocation.FUN_008572f0();
    SaveCell85A520* pRef = parent->FUN_008d6f30();
    SaveForm85A520* world = 0;
    if (pRef)
        world = pRef->FUN_0054ddd0();
    if (world)
        savedLocation.cell = FindOrAddValue(world->FUN_0084e3a0());
    else if (pRef)
        savedLocation.cell = FindOrAddValue(pRef->FUN_0084e3a0());
    else
    {
        if (!parent->FUN_005653d0())
            SaveWarning85A520::FUN_005b5e40(DAT_01080ba8, parent->FUN_0084e3a0());
        if (parent->FUN_005653d0() && !parent->FUN_005d43c0()->FUN_0041d460())
            SaveWarning85A520::FUN_005b5e40(DAT_01080b38, parent->FUN_0084e3a0());
        SaveMobile85A520* mobile = (SaveMobile85A520*)_FNV_DynamicCast(parent, 0, &DAT_011841cc, &DAT_01184920, 0);
        if (mobile && mobile->FUN_008d8520())
        {
            if (mobile->FUN_008d8520()->FUN_0045cd60() == 0)
                SaveWarning85A520::FUN_005b5e40(DAT_01080ae8, parent->FUN_0084e3a0());
            else if (mobile->FUN_008d8520()->FUN_0045cd60() == 1)
                SaveWarning85A520::FUN_005b5e40(DAT_01080a90, parent->FUN_0084e3a0());
        }
    }
    savedLocation.position = parent->FUN_00436aa0();
    savedLocation.rotation = parent->FUN_00430830();
    if (flags & 0)
    {
        ReferenceRecord85A520 world;
        world.FUN_008572c0();
        if (parent->FUN_007af430())
            world.base = FindOrAddValue(parent->FUN_007af430()->FUN_0084e3a0());
        world.savedLocation = savedLocation;
        ArrowProjectile85A520* savedLocation =
            (ArrowProjectile85A520*)_FNV_DynamicCast(parent, 0, &DAT_011841cc, &DAT_011a28e0, 0);
        MagicProjectile85A520* pRef =
            (MagicProjectile85A520*)_FNV_DynamicCast(parent, 0, &DAT_011841cc, &DAT_011a0e88, 0);
        if (parent->FUN_005653d0())
        {
            world.type = 3;
            if (world.savedLocation.cell == 0)
            {
                SaveCell85A520* persistent = parent->FUN_005d43c0()->FUN_0041d460();
                SaveForm85A520* pWorld = persistent->FUN_0054ddd0();
                world.savedLocation.cell = FindOrAddValue(pWorld->FUN_0084e3a0());
            }
        }
        else if (savedLocation)
            world.type = 1;
        else if (pRef)
        {
            world.type = 2;
            world.base = FindOrAddValue(pRef->FUN_00586150()->FUN_00825c00()->FUN_004086a0());
        }
        ((SaveStream85A520*)::DAT_011de45c)->FUN_008579b0(&world, 36);
    }
    else if (flags & 6)
    {
        if (flags & 0)
        {
            MoveRecord85A520 cellA;
            cellA.FUN_00857320();
            TESObjectREFR85A520* actor = 0;
            if (parent->IsActor())
                actor = parent;
            SaveForm85A520* move = actor ? actor->va6() : 0;
            SaveForm85A520* cellB = actor ? actor->va5() : 0;
            if (cellB || move)
            {
                cellA.editorPosition = actor ? actor->GetEditorPosition() : DAT_011f426c;
                if (cellB)
                    cellA.cell = FindOrAddValue(cellB->FUN_0084e3a0());
                else if (move)
                    cellA.cell = FindOrAddValue(move->FUN_0084e3a0());
            }
            else
            {
                Actor85A520* point = (Actor85A520*)_FNV_DynamicCast(parent, 0, &DAT_011841cc, &DAT_011846d4, 0);
                if (point)
                    SaveWarning85A520::FUN_005b5e40(DAT_01080a40);
                cellA.editorPosition = parent->GetEditorPosition();
                cellA.cell = 0;
                if (parent->FUN_008d6f30())
                {
                    if (parent->FUN_008d6f30()->FUN_00425fd0())
                        cellA.cell = FindOrAddValue(parent->FUN_008d6f30()->FUN_0084e3a0());
                    else if (parent->FUN_008d6f30()->FUN_0054ddd0())
                        cellA.cell = FindOrAddValue(parent->FUN_008d6f30()->FUN_0054ddd0()->FUN_0084e3a0());
                }
            }
            cellA.savedLocation = savedLocation;
            ((SaveStream85A520*)::DAT_011de45c)->FUN_008579b0(&cellA, 44);
        }
        else
            ((SaveStream85A520*)::DAT_011de45c)->FUN_008579b0(&savedLocation, 28);
    }
    else if (flags & 0)
    {
        SaveCell85A520* world = parent->FUN_008d6f30();
        unsigned int id;
        SaveForm85A520* p = parent->FUN_00575d70();
        if (p)
            id = FindOrAddValue(p->FUN_0084e3a0());
        else if (world)
            id = FindOrAddValue(world->FUN_0084e3a0());
        else
            SaveWarning85A520::FUN_005b5e40(DAT_010809e8, parent->GetName(), parent->FUN_0084e3a0());
        ((SaveStream85A520*)::DAT_011de45c)->FUN_008579b0(&id, 4);
    }
}

}

namespace ChangeReport {

struct Form
{

    virtual void slot0();

    virtual void slot4();

    virtual void slot8();

    virtual void slotc();

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

    virtual void slot94();

    virtual void slot98();

    virtual void slot9c();

    virtual void slota0();

    virtual void slota4();

    virtual void slota8();

    virtual void slotac();

    virtual void slotb0();

    virtual void slotb4();

    virtual void slotb8();

    virtual void slotbc();

    virtual void slotc0();

    virtual void slotc4();

    virtual void slotc8();

    virtual void slotcc();

    virtual void slotd0();

    virtual void slotd4();

    virtual void slotd8();

    virtual void slotdc();

    virtual void slote0();

    virtual void slote4();

    virtual void slote8();

    virtual void slotec();

    virtual void slotf0();

    virtual void slotf4();

    virtual void slotf8();

    virtual void slotfc();

    virtual void slot100();

    virtual void slot104();

    virtual void slot108();

    virtual void slot10c();

    virtual void slot110();

    virtual void slot114();

    virtual void slot118();

    virtual void slot11c();

    virtual void slot120();

    virtual void slot124();

    virtual void slot128();

    virtual void slot12c();

    virtual const char* Name();
};
struct FullName
{
    const char* FUN_00408da0();
};
struct NamedForm
{
    const char* FUN_0055d520();
};

struct Entry
{
    unsigned int id;
    unsigned char type, flags0, flags1, flags2, flags3, version;
    unsigned short size;
};

struct Node
{
    Entry** FUN_006815c0();
    Node* FUN_00726070();
};

struct Unknown
{
    unsigned int size, value;
};
struct UnknownNode
{
    Unknown** FUN_006815c0();
    UnknownNode* FUN_00726070();
};

struct Map
{
    void* FUN_004b9ba0();
    void GetNextItem(void**, unsigned char*, Node**);
};

struct File
{
    unsigned int unk0, unk4, unk8, unkc, unk10;
    File(const char*, int, int, int);
    ~File();
    int FUN_00559450();
};

struct Stats
{
    int count, total;
    unsigned short smallest, largest;
    Stats();
};

struct Type
{
    unsigned int unk0;
    const char* name;
    unsigned int unk8;
};
extern Type DAT_01187000[];

struct Manager
{
    void FormatChangeFlags(char*, Form*, unsigned int, unsigned char, int);
};
extern Manager* DAT_011de45c;

int FUN_00406d30(char*, unsigned int, const char*);
int FUN_00406d50(char*, unsigned int, const char*);
int FUN_00406d00(char*, unsigned int, const char*, ...);
int FUN_00456a20(const char*, int, int, int);
void FUN_00aff0b0(const char*);
unsigned int FUN_0044a670(const char*);
Form* LookupFormByID(unsigned int);
int FUN_00408b20(const char*, const char*);

extern char DAT_01039788;

extern char DAT_01080428;

extern char DAT_0105ac4c;

extern char DAT_01063d04;

extern char DAT_01044aec;

extern char DAT_0108041c;

extern char DAT_01080414;

extern char DAT_01080670;

extern char DAT_0104469c;

extern char DAT_01080668;

extern char DAT_01019f08;

extern char DAT_010803e4;

extern char DAT_01183158;

extern char DAT_01011584;

extern char DAT_01080648;

extern char DAT_0108063c;

extern char DAT_010805d8;

extern char DAT_010805c4;

extern char DAT_01080254;

extern char DAT_01080570;

struct Main
{
    Map* map;
    UnknownNode* others;
    void FUN_00856300(File*, const char*);
    void FUN_00855ba0(const char*);
};

// Writes per-type form counts and size statistics, unknown-entry sizes and values, and overall totals to a file.
// @fnv 0x00855ba0
void Main::FUN_00855ba0(const char* filename)
{

    char pathSlot0[260];
    FUN_00406d30(pathSlot0, 260, filename);
    FUN_00406d50(pathSlot0, 260, &DAT_01039788);
    if (FUN_00456a20(pathSlot0, 0, 0, -1))
        FUN_00aff0b0(pathSlot0);

    File fileSlot15(pathSlot0, 1, 2, 0);
    if (fileSlot15.FUN_00559450())
        return;

    Stats allSlot12;
    char buffer[520];
    FUN_00406d00(buffer, 520, &DAT_01080670, &DAT_01080414, &DAT_0108041c, &DAT_01044aec, &DAT_01063d04, &DAT_0105ac4c,
                 &DAT_01080428);
    FUN_00856300(&fileSlot15, buffer);

    void* position = map->FUN_004b9ba0();
    while (position)
    {
        Node* listSlot16;
        unsigned char type;
        map->GetNextItem(&position, &type, &listSlot16);
        Node* node = listSlot16;
        char typeNameSlot0[10];

        if (!type)
            FUN_00406d00(typeNameSlot0, 10, &DAT_0104469c);
        else if (type == 121)
            FUN_00406d00(typeNameSlot0, 10, &DAT_01080668);
        else
            FUN_00406d00(typeNameSlot0, 10, &DAT_01019f08, DAT_01187000[type].name);

        FUN_00406d00(buffer, 520, &DAT_010803e4, typeNameSlot0);
        unsigned __int64 lengthSlot33 = FUN_0044a670(buffer);
        FUN_00856300(&fileSlot15, buffer);
        Stats statsSlot13;

        while (node)
        {
            Entry* entry = *node->FUN_006815c0();
            if (entry)
            {
                Form* formSlot19 = LookupFormByID(entry->id);
                if (entry->size > statsSlot13.largest)
                    statsSlot13.largest = entry->size;
                if (entry->size < statsSlot13.smallest)
                    statsSlot13.smallest = entry->size;
                statsSlot13.total += entry->size;
                statsSlot13.count++;

                char descriptionSlot0[500];
                DAT_011de45c->FormatChangeFlags(descriptionSlot0, formSlot19, *(unsigned int*)&entry->flags0, entry->type,
                                           0);
                const char* name = 0;
                FullName* fullSlot10 = (FullName*)::SaveInitialData85A520::_FNV_DynamicCast(
                    formSlot19, 0, &::SaveInitialData85A520::DAT_01183028, &DAT_01183158, 0);
                NamedForm* namedSlot10 = (NamedForm*)::SaveInitialData85A520::_FNV_DynamicCast(
                    formSlot19, 0, &::SaveInitialData85A520::DAT_01183028, &::SaveInitialData85A520::DAT_011841cc, 0);

                if (formSlot19)
                {
                    if (namedSlot10)
                        name = namedSlot10->FUN_0055d520();
                    if (fullSlot10 && (!name || !FUN_00408b20(name, &DAT_01011584)))
                        name = fullSlot10->FUN_00408da0();
                    if (!name || !FUN_00408b20(name, &DAT_01011584))
                        name = formSlot19->Name();
                    FUN_00406d00(buffer, 520, &DAT_01080648, entry->id, entry->size, *(unsigned int*)&entry->flags0,
                                 entry->version, name, descriptionSlot0);
                }
                else
                    FUN_00406d00(buffer, 520, &DAT_01080648, entry->id, entry->size, *(unsigned int*)&entry->flags0,
                                 entry->version, &DAT_0108063c, descriptionSlot0);

                FUN_00856300(&fileSlot15, buffer);
            }

            node = node->FUN_00726070();
        }

        FUN_00406d00(buffer, 520, &DAT_010805d8, typeNameSlot0, statsSlot13.count, typeNameSlot0, statsSlot13.total,
                     typeNameSlot0, statsSlot13.smallest, typeNameSlot0, statsSlot13.largest, typeNameSlot0,
                     (float)statsSlot13.total / statsSlot13.count);
        FUN_00856300(&fileSlot15, buffer);

        if (statsSlot13.largest > allSlot12.largest)
            allSlot12.largest = statsSlot13.largest;
        if (statsSlot13.smallest < allSlot12.smallest)
            allSlot12.smallest = statsSlot13.smallest;
        allSlot12.total += statsSlot13.total;
        allSlot12.count += statsSlot13.count;
    }

    FUN_00856300(&fileSlot15, &DAT_010805c4);
    UnknownNode* unknownNodeSlot24 = others;
    while (unknownNodeSlot24)
    {
        Unknown* unknown = *unknownNodeSlot24->FUN_006815c0();
        if (unknown)
        {
            FUN_00406d00(buffer, 520, &DAT_01080254, unknown->size, unknown->value);
            FUN_00856300(&fileSlot15, buffer);
            allSlot12.total += unknown->size;
        }
        unknownNodeSlot24 = unknownNodeSlot24->FUN_00726070();
    }

    FUN_00406d00(buffer, 520, &DAT_01080570, allSlot12.count, allSlot12.total, allSlot12.smallest, allSlot12.largest,
                 (float)allSlot12.total / allSlot12.count);
    FUN_00856300(&fileSlot15, buffer);
}

}

class FormMethods77
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
    virtual void SetID(unsigned int, int);
    int unk04, unk08, unk0c, unk10, unk14;
    void FUN_0046a010(int);
};
struct CreatedForm77
{
    virtual void v00();
    int unk04, unk08, unk0c, unk10, unk14;
};
struct TESBoundObject : public TESForm
{
  public:
    int FUN_00401170();
};
class TESObjectREFR : public TESForm
{
  public:
    TESBoundObject* FUN_007af430();
    void FUN_00575690(TESBoundObject*);
};
struct NPC77 : CreatedForm77
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
    NPC77();
};
struct Creature77 : CreatedForm77
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
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    Creature77();
};
struct Reference77 : CreatedForm77
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
    Reference77();
};
struct Projectile77 : CreatedForm77
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
    Projectile77();
};
struct Missile77 : CreatedForm77
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
    Missile77();
};
struct Beam77 : CreatedForm77
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
    Beam77();
};
struct Flame77 : CreatedForm77
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
    Flame77();
};

void* operator new(unsigned int);
void operator delete(void*);
enum MEM_CONTEXT;

extern const char DAT_010804c8[];
void __cdecl FUN_005b5e40(const char*, unsigned int, unsigned int);
void __cdecl FUN_005b5e40(const char*, int, unsigned int, unsigned int, unsigned int);
struct Record77
{
    int type;
    unsigned int object, location;
};
struct Save77
{
    void FUN_0085a2e0(TESForm*);
    TESForm* FUN_00859a90(unsigned int, Record77*);
};
// Looks up or creates a TESForm from the record and initializes it according to its type.
// @fnv 0x00859a90
TESForm* Save77::FUN_00859a90(unsigned int id, Record77* record)
{
    AutoMemContext scope6(static_cast<MEM_CONTEXT>(49), true, DAT_010804c8, 0x133b);
    TESForm* pForm = (TESForm*)::LookupFormByID(id);
    TESBoundObject* bound28 = 0;
    if (record->type != 2)
    {
        bound28 = dynamic_cast<TESBoundObject*>((TESForm*)::LookupFormByID(record->object));
        if (!bound28)
        {
            FUN_005b5e40("SAVELOAD: Bound object %08X no longer exists.  Reference %08X will not be created.",
                         record->object, id);
            return 0;
        }
    }
    if (pForm)
    {
        TESObjectREFR* reference = dynamic_cast<TESObjectREFR*>(pForm);
        if (!reference || (record->type != 0 && record->type != 3) || reference->FUN_007af430() != bound28)
        {
            FUN_0085a2e0(pForm);
            pForm = 0;
        }
    }
    if (!pForm)
    {
        if (record->type == 0 || record->type == 3)
        {
            switch (bound28->FUN_00401170())
            {
            case 42:
                pForm = (TESForm*)new NPC77;
                break;
            case 43:
                pForm = (TESForm*)new Creature77;
                break;
            default:
                pForm = (TESForm*)new Reference77;
                break;
            }
            TESObjectREFR* reference = dynamic_cast<TESObjectREFR*>(pForm);
            reference->FUN_00575690(bound28);
            ((FormMethods77*)pForm)->SetID(id, 1);
        }
        else if (record->type == 1)
        {
            pForm = (TESForm*)new Projectile77;
            TESObjectREFR* reference = dynamic_cast<TESObjectREFR*>(pForm);
            reference->FUN_00575690(bound28);
            ((FormMethods77*)pForm)->SetID(id, 1);
        }
        else if (record->type == 2)
        {
            TESForm* projectile = 0;
            switch (record->object)
            {
            case 0:
                projectile = (TESForm*)new Missile77;
                break;
            case 3:
                projectile = (TESForm*)new Beam77;
                break;
            case 1:
                projectile = (TESForm*)new Flame77;
                break;
            }
            pForm = projectile;
            ((FormMethods77*)pForm)->SetID(id, 1);
        }
        else
            FUN_005b5e40(
                "FORMS: Invalid created reference type %i for form %08X with bound object %08X in location %08X",
                record->type, id, record->object, record->location);
    }
    if (pForm)
        ((FormMethods77*)pForm)->FUN_0046a010(1);
    return pForm;
}
