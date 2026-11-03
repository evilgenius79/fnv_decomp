
// src/staging/blk_00660000_od_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x0066e100: the skeleton of src/staging/blk_00660000_od.cpp
// with declarations corrected to what the original code does (unit: struct G2 : public List_009e03e0 { void AddHead(Detectio -> struct G2 : public List_009e03e0 { void AddHead(Detectio). Move the function to its real unit once
// that unit declares it this way.

// src/staging/blk_00660000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
void __cdecl CopyConstructEntry(int a, int b);
struct FUN_006601f0_Class
{
    void __thiscall FUN_006601f0(int a, int b);
};
extern "C" void __cdecl FUN_00660340(void*, void*, void*, void*);
void __cdecl FUN_00660210(void* a1, void* a2, void* a3, void* a4);
extern "C" void __cdecl FUN_006603a0(void* a, void* b, void* c, void* d);
void __cdecl FUN_00660230(void* a, void* b, void* c, void* d);
extern "C" int __cdecl ConstructInPlace(int, int);
struct FUN_00660300_Class
{
    int __thiscall FUN_00660300(int a, int b);
};
extern "C" void __cdecl CopyConstructElement(int, int);
struct FUN_00660320_Class
{
    void __thiscall FUN_00660320(int a, int b);
};
extern const char* const g_011d5ba8_arg1;
struct FUN_00661d30_cls
{
    const char* const* GetArg1Ptr();
};
extern "C" void* __cdecl FUN_00665f50(void*);
extern int DAT_01066434;
struct FUN_00665c50
{
    void* __thiscall FUN_00665f50(int a);
    void* __thiscall Set(int a);
};
struct FUN_00665f10_class
{
    int __thiscall Identity(int a);
};
struct BGSSaveLoadChangesMap
{
    void Deallocate(void* p);
    void FUN_00666050(void* p);
};
struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting1297;
float FUN_0066b0b0();
extern "C" void* __cdecl FUN_00664840(int);
struct Flt
{
    operator unsigned int();
};
unsigned int __cdecl GetFltValueAtOffset16();
struct FUN_0066dd80_Class
{
    bool IsFlag8Set() const;
};
bool FUN_0066de80(int type);
extern int DAT_01068884;
struct FUN_0067ad20_Class
{
    int* vtbl;
    FUN_0067ad20_Class();
};
extern int DAT_01068884;
struct FUN_0067ad70_Class
{
    void FUN_0067ad70();
};
extern int DAT_01068aa4;
struct ActorPackageData
{
    ActorPackageData();
    ActorPackageData* FUN_0067d920();
};
ActorPackageData::ActorPackageData()
{}
extern "C" int DAT_01068aa4;
struct FUN_0067d970_Class
{
    int m;
    void __thiscall FUN_0067d970();
};
struct FUN_0067f4b0_class
{
    unsigned char b;
    int a;
    int c;
    void FUN_0067f4b0(int d);
};
struct FUN_00666020
{
    void* vtbl;
    int a;
    void* b;
    void RemoveAll();
    void Init();
};
extern "C" void _NiFreeAlias(void*);
struct S6
{
    short a;
    short b;
    short c;
};
S6* __cdecl CopyTripleShorts(S6* a1, S6* a2, S6* a3);
struct FUN_00661d40_shell
{
    void __thiscall SetVTableAndDestroy();
    void* __thiscall FUN_00661d60(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
extern const char* DAT_0119b49c[];
const char* FUN_00661da0(int i);
struct StatisticalArray
{
    int _pad[3];
    int m_base;
    unsigned int __thiscall FUN_0065cc30();
    int __thiscall FUN_00662890(unsigned int);
};
unsigned int __cdecl FUN_00ec7c56();
void __cdecl Deallocate(void* p);
struct FUN_00665c80_Class
{
    void __thiscall FUN_00665fc0();
    void* __thiscall FUN_00665c80(unsigned int flags);
};
struct Inner0080
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual int Func(int a, int b);
};
struct FUN_00665f20_Holder
{
    Inner0080* p;
    void __thiscall AdvanceState(int a);
    void __thiscall CallInnerFuncAndForward(int a);
};
void* __cdecl _NiMalloc(unsigned int);
void* __cdecl memset(void* dest, int value, unsigned int count);
extern int $SG6086;
struct FUN_00665f50_Class
{
    int* vtbl;
    int count;
    int* data;
    int zero;
    void* __thiscall FUN_00665f50(int a);
};
struct FUN_006661b0_Class
{
    void __thiscall FUN_006661e0();
    void* __thiscall FUN_006661b0(unsigned int flags);
};
void __cdecl _Deallocate(void*);
struct FUN_00666270_Holder
{
    void* __thiscall InitAndMaybeDeallocate(unsigned int);
};
void __cdecl FUN_006665c0();
void __cdecl Deallocate(void*);
struct FUN_00666570_Class
{
    void __thiscall FUN_006665c0();
    void* __thiscall FUN_00666570(unsigned int flags);
};
struct T_
{
    void FUN_004a3f10(void*);
};
struct bhkCharacterController
{
    float& GetVectorElement(int);
};
struct FUN_0066c9c0_Class
{
    T_ a;
    T_ b;
    void FUN_0066c9c0(T_& x, T_& y, float f);
};
struct Date
{
    ~Date();
};
struct FUN_0066da50 : Date
{
    ~FUN_0066da50();
    void FUN_0066dab0();
};
struct H_A100
{
    void* GetSizeMasked();
};
struct H_6db70
{
    void FUN_0066db70(void* a, void* b);
};
struct FUN_0066dae0_Class
{
    void* p;
    unsigned int pad;
    unsigned int state;
    void __thiscall DestroyRange();
    void __thiscall FUN_0066dae0(void* a);
};
struct FUN_0066db70_Class
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2()
    {}
    virtual void v3()
    {}
    virtual void v4(int, int)
    {}
    void __thiscall FUN_0066db70(int a, int b);
};
void __cdecl Deallocate(void* p);
struct FUN_0066df40_Class
{
    void __thiscall FUN_0066df40();
    void* __thiscall FUN_0066e300(unsigned int flags);
};
struct FUN_00671a70_Class
{
    unsigned short flags;
    void FUN_00671a70(bool set);
};
struct FUN_00671ad0_Class
{
    void __thiscall FUN_00671ad0(bool a);
};
struct FUN_00671b30_Class
{
    unsigned short m_0024;
    void FUN_00671b30(bool a);
};
struct FUN_00671b90_Class
{
    void __thiscall FUN_00671b90(bool b);
};
struct FUN_00671bf0_Class
{
    void __thiscall FUN_00671bf0(bool a);
};
struct FUN_00671c50_Class
{
    void __thiscall FUN_00671c50(bool bSet);
};
struct FUN_00671cb0_Class
{
    void __thiscall SetFlag20(bool b);
};
struct FUN_0067ac70_Class
{
    unsigned short wFlags;  // +0x22
    void __thiscall SetFlag100(bool bSet);
};
struct FUN_0067ad70_cls
{
    virtual ~FUN_0067ad70_cls();
    void* __thiscall DestroyAndFree(unsigned int);
};
void __cdecl _Deallocate(void*);
struct BGSSaveFormBuffer
{
    void __thiscall SaveData(void*, unsigned int, int);
};
struct FUNObj
{
    void __thiscall FUN_0067fb60(void*);
};
struct Holder
{
    int _0;
    FUNObj* q;
    void __thiscall SaveToBuffer(void*);
};
extern int DAT_010689e4;
struct FUN_0067c3f0_Class : public FUN_0067ad20_Class
{
    unsigned char b;
    unsigned char c;
    FUN_0067c3f0_Class();
};
template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned char* p, EndianSizeTag<1>);
void __cdecl BSEndian(unsigned char* p, EndianSizeTag<2>);
struct FUN_0067eff0_Class
{
    void __thiscall FUN_0067eff0();
};
struct FUN_0067b170
{
    int pad[4];
    unsigned char flag;
    int pad2[3];
    FUN_0067b170();
};
struct TESPackage
{
    int GetPackType();
    void* p;
    void* q;
    void* r;
    void* s;
    void* t;
    void* u;
    void* v;
    void* w;
    void* x;
    void* y;
    FUN_0067b170* e;
    void SetPackageFlag(bool b);
};
void __cdecl BSEndian(unsigned char* p, EndianSizeTag<1>);
struct FUN_0067b100_Class
{
    unsigned char b0;
    unsigned char b4;
    unsigned char b0c;
    unsigned char b14;
    void __thiscall FUN_0067b100();
};
struct bhkConvexShape
{
    bhkConvexShape();
    ~bhkConvexShape();
    void FUN_00cab820(int a);
};
extern int DAT_01066e2c;
extern int DAT_01268324;
struct FUN_0066d6a0 : bhkConvexShape
{
    int* vtbl;
    FUN_0066d6a0(int a);
};
struct GlobalObject_0045cfe0
{
    int* Int();
};
struct Pair8
{
    GlobalObject_0045cfe0* a;
    GlobalObject_0045cfe0* b;
};
int FindPairValue(int a, Pair8* b, int c);
struct FUN_00672c40_Class
{
    int GetPackType();
    void SetExtraValue(float value);
};
struct ListX
{
    ~ListX();
};
struct PackageList : ListX
{
    void ClearPackageList();
    ~PackageList();
};
struct FUN_0067e3a0_Class : PackageList
{
    ~FUN_0067e3a0_Class();
};
// @fnv 0x00660400
template <class T> struct BSSimpleList;
BSSimpleList<int>* FUN_00660400(BSSimpleList<int>* a)
{
    return a->GetNext();
}
void* __cdecl operator new(unsigned int);
struct AutoMemHelper
{
    int pad;
    AutoMemHelper(int context, bool flag, const char* file, int line);
    ~AutoMemHelper();
};
struct FUN_0044d000
{
    int pad[9];
    FUN_0044d000(int a, int b, int c, int d);
};
struct FUN_00665e30_Class
{
    int pad;
    int* data;
    FUN_0044d000* __thiscall FUN_00665e30(int index);
};
void* __cdecl operator new(unsigned int);
struct DetectionViewData;
struct List_009e03e0
{
    void* padding[2];

    void RemoveAll();
};
struct G2 : public List_009e03e0
{
    void AddHead(DetectionViewData** value);
    bool IsEmpty();
    struct DetectionGroup*& FUN_006815c0();
    G2* FUN_00726070();
};
struct SL : public G2
{
    SL();
};
struct BGSLoadFormBuffer
{
    void ReadTypedData(void* data, unsigned int size);
    bool ReadFormIdentifier(void* formId);
    int ReadElementCount();
};
struct BGSLoadGameBuffer : public BGSLoadFormBuffer
{
};
struct DetectionViewData
{
    void* formId;
    SL* list;
    unsigned char data[12];
    unsigned int value;
    int padding[3];

    DetectionViewData();
    void LoadGame(BGSLoadGameBuffer* buffer);
    void FUN_0066e440(BGSLoadGameBuffer* buffer);
};
void* __cdecl operator new(unsigned int);
void __cdecl ReportAssertionViolation(char const*, int);
struct FUN_0067caa0
{
    int m_auiShapeKeys[9];

    FUN_0067caa0();
};
struct FUN_00672d10_Class
{
    unsigned char m_auiShapeKeys[0x28];
    FUN_0067caa0* m_pObject;

    FUN_0067caa0* __thiscall FUN_00672d10();
};
struct C0130Iterator
{
    void* m_pkContainer;
    char* m_pPtr;
};
struct C0130ScalarPtrTag
{
};
struct C0130RangeCheckedTag
{
};
C0130ScalarPtrTag __cdecl C0130PtrCat(C0130Iterator& first, C0130Iterator& dest);
char* __cdecl C0130CheckedBase(C0130Iterator& iter);
char* __cdecl C0130CopyOpt(char* first, char* last, C0130Iterator dest, C0130ScalarPtrTag ptrCat,
                           C0130RangeCheckedTag checked);
char* __cdecl FUN_00660130(C0130Iterator first, C0130Iterator last, C0130Iterator dest);
struct C0190Iterator
{
    void* m_pkContainer;
    char* m_pPtr;
};
struct C0190ScalarPtrTag
{
};
struct C0190RangeCheckedTag
{
};
C0190ScalarPtrTag __cdecl C0190PtrCat(C0190Iterator& first, C0190Iterator& dest);
char* __cdecl C0190CheckedBase(C0190Iterator& iter);
char* __cdecl C0190CopyOpt(char* first, char* last, C0190Iterator dest, C0190ScalarPtrTag ptrCat,
                           C0190RangeCheckedTag checked);
char* __cdecl FUN_00660190(C0190Iterator first, C0190Iterator last, C0190Iterator dest);
void __cdecl FUN_00660400(void* a1, unsigned char flag);
void __cdecl CallWithUninitializedFlag(void* a1);
void* operator new(unsigned int uiSize, void* pvWhere);
struct C6602B0Entry
{
    short m_sA;
    short m_sB;
    short m_sC;
};
void CopyConstructEntry(C6602B0Entry* pkDest, const C6602B0Entry& kValue);
extern "C" bool __cdecl FUN_0065e750(void* a, void* b);
extern "C" void* __cdecl CallWithFlag(void* a);
extern "C" void __cdecl CopyConstructRange(void* a1, void* a2, void* a3, void* a4, bool a5, bool a6);
struct SpawnedFlagBox
{
    bool v;
};
// @fnv 0x006603a0
extern "C" void __cdecl FUN_006603a0(void* a, void* b, void* c, void* d)
{
    SpawnedFlagBox flagA3 = {};
    bool flagB;
    flagB = FUN_0065e750(&a, &c);
    CopyConstructRange(CallWithFlag(&a), CallWithFlag(&b), c, d, flagB, flagA3.v);
}

// std::_Construct for a 0x58-byte element: copy-construct in place.

void* __cdecl operator new(unsigned int uiSize, void* pvMem);
void __cdecl operator delete(void* pvObject, void* pvMem);
struct C60490Element
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

    C60490Element(const C60490Element& kOther);
};
void __cdecl CopyConstructElement(C60490Element* pkPtr, const C60490Element& kVal);
struct FUN_006665c0_Item
{
    int unk00;
    int unk04;
    int Dispose(int flags);
};
struct FUN_006665c0_Entry
{
    int unk00;
    FUN_006665c0_Item* m_item;
};
void __cdecl FormHeap_Free(void* p);
void __cdecl FUN_0044e360(void* p);
struct FUN_006665c0_cls
{
    int unk00;
    void* m_04;
    FUN_006665c0_Entry* m_08;

    unsigned int GetCount();
    void FUN_006665c0();
};
extern const double g_dblConst;
extern int g_timerA;
extern int g_timerB;
extern unsigned char g_counter;
float* __fastcall FUN_00403e20(void* obj);
int* __fastcall FUN_0043d4d0(void* obj);
struct FUN_0066ca50_cls
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
    int unk43;
    int unk44;
    int unk45;
    int unk46;
    int unk47;
    int unk48;
    int unk49;
    int unk50;
    int unk51;
    int unk52;
    int unk53;
    int unk54;
    int unk55;
    int unk56;
    int unk57;
    int unk58;
    int unk59;
    int unk60;
    float m_f4;

    bool FUN_0066ca50(float dt);
};
struct SpawnedObject
{
    int GetRefPtr();
    bool IsReady() const;
    float GetValue();
};
extern int DAT_011ca278;
extern int DAT_011dea3c;
int __cdecl FUN_0066dba0(int a);
float __cdecl FUN_0066dc70(int a);
void __cdecl FUN_005e58f0(int a, int b, int c, float* d);
float __cdecl GetObjectValue(SpawnedObject* obj);
extern "C" int __cdecl FUN_004019a0(void*);
struct S_0066e2b0_Class : public FUN_0066df40_Class
{
    void __thiscall FUN_0066e2b0();
};
struct G2;
extern G2 g_011d6124;
DetectionViewData* __cdecl FindStateByValue(int value);
struct SaveBufCls
{
    void __thiscall FUN_00865e50(void* data, unsigned int size, int z);
    void __thiscall FUN_00865df0(void* data, unsigned int size);
    unsigned int __thiscall FUN_00865f20();
    void __thiscall FUN_00865ff0(unsigned int count, unsigned int pos);
};
struct SaveItemCls
{
    void __thiscall SaveDetectionState(SaveBufCls* buffer);
};
struct SaveNodeCls
{
    SaveItemCls** __thiscall FUN_006815c0();
    SaveNodeCls* __thiscall FUN_00726070();
};
struct DetClassCls
{
    void* m_00;
    SaveNodeCls* m_04;
    unsigned char m_08[12];
    unsigned int m_14;
    void __thiscall WriteToSaveBuffer(SaveBufCls* buffer);
};
extern double DAT_01012060;
extern double DAT_01017a40;
class StatsGetterCls
{
  public:
    int* GetValuePtr();
};
extern StatsGetterCls DAT_011d6458;
bool __cdecl IsScaledValueAboveThreshold(float a, float b);
void __cdecl FUN_00407a90(void* p, bool flag);
void __cdecl FUN_00401080(void* p, bool flag);
struct SpawnedFlag
{
    bool m_bValue;
};
struct FUN_0067ca10_cls
{
    void FUN_0067ca10();
};
// NiTMap destructor: remove all entries, then the base map destructor frees the hash table.
class F5FC0MapBase
{
  public:
    virtual ~F5FC0MapBase();
    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};
class FUN_00665fc0 : public F5FC0MapBase
{
  public:
    virtual ~FUN_00665fc0();
};
// Forward the position for the given key (obtained through a stateless helper) to the erase routine.
class D9B0Container;
struct D9B0Locate
{
    void* Find(D9B0Container* pkContainer, int iKey);
};
class D9B0Container
{
  public:
    void EraseAt(void* pvPosition);
    void EraseByKey(int iKey);
};
// Save: write the header value, every queued item, then patch the item count in at the reserved position.
class E6D0SaveBuffer;
class E6D0Item
{
  public:
    void Save(E6D0SaveBuffer* pkBuffer);
};
class E6D0Node
{
  public:
    E6D0Item** GetItem();
    E6D0Node* GetNext();
};
class E6D0SaveBuffer
{
  public:
    void SaveData(void* pvData, int iSize, int iFlags);
    unsigned int GetPosition();
    void WriteCountAt(int aiCountValue, unsigned int uiPosition);
};
extern int g_iE6D0Header;
extern E6D0Node g_kE6D0Items;
void SaveE6D0Items(E6D0SaveBuffer* pkBuffer);
struct ComparisonEntry
{
    int FUN_00678ca0();
    int GetSecondByte();
    signed char FUN_00678ce0();
    signed char FUN_0086a460();
};
struct ComparisonOwner
{
    ComparisonEntry* FUN_0041d8a0();
    int CompareTo(ComparisonEntry* other);
};
class TESForm
{
  public:
    virtual ~TESForm();
};
class Actor : public TESForm
{
};
TESForm* __cdecl LookupFormByID(void* p);
struct E640Item
{
    void __thiscall ResolveActorFormId();
};
struct E640Cls : DetClassCls
{
    void __thiscall FUN_0066e640(SaveBufCls* buffer);
};
struct S_00660510_Context
{
    void __thiscall FUN_00660300(int dest, int src);
    void __thiscall FUN_0065ea40(int element);
};
int __cdecl FUN_00660510(int first, int last, int dest, S_00660510_Context* context);
struct Elem6605
{
    char m_data[0x58];
};
struct Alloc6605
{
    void FUN_00660320(Elem6605* pDest, const Elem6605& kSrc);
    void FUN_0065ea60(Elem6605* pElem);
};
struct NonscalarTag6605
{
};
struct CheckedTag6605
{
};
namespace std6605 {
// @fnv 0x006605d0
Elem6605* __cdecl CopyConstructRange(Elem6605* _First, Elem6605* _Last, Elem6605* _Dest, Alloc6605& _Al,
                                     NonscalarTag6605, CheckedTag6605)
{
    Elem6605* _Next = _Dest;
    try
    {
        for (; _First != _Last; ++_Dest, ++_First)
            _Al.FUN_00660320(_Dest, *_First);
    }
    catch (...)
    {
        for (; _Next != _Dest; ++_Next)
            _Al.FUN_0065ea60(_Next);
        throw;
    }
    return _Dest;
}
}

float __cdecl FUN_0066dc70(int value);
float* __fastcall FUN_00403e20(void* object);
extern unsigned char DAT_011d5f88;
float __cdecl FUN_0066dca0(int value, bool unscaled);
struct Vector3
{
    float x;
    float y;
    float z;
};
extern Vector3 DAT_011f426c;
struct SaveNodeExtended : SaveNodeCls
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
    ~SaveNodeExtended();
};
struct DetClassExtended : DetClassCls
{
    void ClearAndReset();
};

struct DetectionEntry
{
    unsigned int key;
};
struct DetectionEntryList
{
    DetectionEntry* item;
    DetectionEntryList* next;
    DetectionEntry*& FUN_006815c0();
    DetectionEntryList* FUN_00726070();
    void FUN_00905330(DetectionEntry* const& entry);
};
struct DetectionGroup
{
    unsigned int owner;
    DetectionEntryList* entries;
    bool FUN_005ca4f0();
    unsigned int FUN_00559450();
    DetectionEntryList* FUN_00726070();
    void ClearAndReset();
};
// @fnv 0x0066e100
void __cdecl FUN_0066e100(unsigned int key)
{
    G2* node = &g_011d6124;
    while (node && !node->IsEmpty())
    {
        DetectionGroup* group = node->FUN_006815c0();
        node = node->FUN_00726070();
        if (group && group->FUN_005ca4f0())
        {
            if (group->FUN_00559450() == key)
                group->ClearAndReset();
            DetectionEntryList* child = group->FUN_00726070();
            bool removed = false;
            while (!removed && child && child->FUN_006815c0())
            {
                DetectionEntry* entry = child->FUN_006815c0();
                child = child->FUN_00726070();
                if (entry->key == key)
                {
                    group->FUN_00726070()->FUN_00905330(entry);
                    delete entry;
                    removed = true;
                }
            }
        }
    }
}
