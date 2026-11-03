
// src/staging/blk_00a60000_o2_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/staging/blk_00a60000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00a60000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
void* __cdecl _fnv_zlib_memset(void* p, int c, unsigned int n);
struct FUN_00a61590_class
{
    void* __thiscall ClearAndReset();
};
struct NiShader;
template <class K, class V> class NiTPointerMap;
template <class K, class V> class NiTStringTemplateMap
{
  public:
    virtual void Test(int);
};
struct NiUnionBV
{
    virtual void Test(int);
};
extern NiTStringTemplateMap<NiTPointerMap<char const*, NiShader*>, NiShader*>* DAT_011f4784;
extern NiUnionBV* DAT_011f4788;
void FUN_00a632b0();
extern "C" void NiFreeAlias(void*);
extern void* DAT_011f4aa8;
void FreeGlobalAlias();
extern int DAT_0109df2c;
extern int DAT_011f4ab4;
struct FUN_00a7f820_Class
{
    void __thiscall FUN_00a7f820();
};
void __fastcall FUN_00a69690(float* p);
struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct FUN_00a615c0_Class
{
    void __thiscall ClearAllBuckets();
};
struct RecursiveSpinLock
{
    void __thiscall Lock(const char*);
};
extern RecursiveSpinLock g_011c5f80;
extern unsigned int DAT_011c5f84;
extern void* DAT_011c5f58;
void __stdcall FUN_00a638c0(void* p);
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct NiTriBasedGeomData;
NiTriBasedGeomData* __fastcall InitializeTriBasedGeomData(NiTriBasedGeomData*);
extern int DAT_0109dac4;
void* __cdecl FUN_00a7b790();
void __fastcall FUN_00a71f60(void*);
extern int DAT_0109dd0c;
struct FUN_00a7d670_Class
{
    void* __thiscall FUN_00a7d670();
};
struct CloningProcess;
struct NiDirectionalLight
{
    void CopyMemberData(NiDirectionalLight* dst, CloningProcess& proc);
    void FUN_00a7d6a0(NiDirectionalLight* dst, CloningProcess& proc);
};
extern "C" int __cdecl tolower(int);
unsigned int FUN_00a61530(const char* str);
struct NiCullingProperty
{
    void FUN_00a5d7a0(void*, CloningProcess&);
};
struct FUN_00a755f0_Class : NiCullingProperty
{
    void __thiscall CopyCullingData(void* dst, CloningProcess& proc);
};
struct FUN_00a72590_Class
{
    int FUN_00a72590(unsigned int index, int* out);
};
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
};
struct FUN_00a7d6e0_Class
{
    void __thiscall FUN_00a71f60();
};
void* FUN_00a7d6e0();
struct NiTMapBaseStub
{
    void RemoveAll();
};
extern void _NiFree(void*);
extern int DAT_0109bc84;
extern int DAT_0109bca4;
extern int DAT_0109bcc4;
struct FUN_00a63850_Class
{
    void DestroyMap();
};
struct NiPoint3
{
    float x;
    float y;
    float z;

    NiPoint3 __thiscall CrossProduct(NiPoint3 const& other) const;
};
struct FUN_00a699d0_Class
{
    NiPoint3 normal;
    float distance;

    FUN_00a699d0_Class* __thiscall FUN_00a699d0(NiPoint3 const* point0, NiPoint3 const* point1, NiPoint3 const* point2);
};
struct NiTFixedStringMap_NiAVObject___
{
    void* m_baseData0;
    void* m_baseData1;
    void __thiscall RemoveAll();
};
struct FUN_00a6ea00_Class : NiTFixedStringMap_NiAVObject___
{
    void* m_pData;
    void* __thiscall FUN_00a6ea00(unsigned char flag);
};
extern int DAT_0109ca08;
extern MemoryManager _g_memoryManager;
void _NiFree(void* p);
struct NiTriStrips
{
    NiTriStrips();
};
extern int DAT_0109cd44;
void* CreateNiTriStrips();
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void SetSize(unsigned int);
};
struct FUN_00a72ca0_Class
{
    void FUN_00a72ca0(unsigned int size);
};
struct FUN_00a7f810
{
    int m_p;
    FUN_00a7f810();
};
struct HashValue_00a61670
{
    unsigned int unk00;
    unsigned int key;
};
struct HashNode_00a61670
{
    HashValue_00a61670* value;
    HashNode_00a61670* next;
};
struct FUN_00a61670_Map
{
    HashNode_00a61670* buckets[1001];
    unsigned int count;
    HashValue_00a61670* RemoveByKey(unsigned int key);
};
extern struct MemoryManager g_memoryManager;
struct A616E0Entry
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short unk0C;
};
struct A616E0Iter
{
    A616E0Entry* m_entry;
    unsigned int m_uiEdgeIndex;
    unsigned int m_uiFilterValue;
};
struct A616E0Bucket
{
    A616E0Entry* m_entries[0x2c9];
    int m_uiItemCount;

    bool GetFirst(A616E0Iter* it)
    {
        it->m_uiEdgeIndex = 0;
        it->m_entry = 0;
        if (m_uiItemCount)
        {
            for (unsigned int i = 0; i < 0x2c9; ++i)
            {
                if (m_entries[i])
                {
                    it->m_uiEdgeIndex = i;
                    it->m_entry = m_entries[i];
                    it->m_uiFilterValue = it->m_entry->unk0C;
                    break;
                }
            }
        }
        return it->m_entry != 0;
    }
};
struct A616E0Pool
{
    A616E0Bucket m_buckets[7];
};
extern A616E0Pool* DAT_011f4464;
bool __cdecl FUN_00a616e0(A616E0Iter* it);
class A61750Texture
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
    virtual unsigned int GetHeight();
    virtual unsigned int GetWidth();
};
unsigned int GetTextureSizeLevel(A61750Texture* pkTexture);
extern bool __cdecl FUN_00a614d0(int, int);
struct NiShaderBase
{
    virtual void M00()
    {}
    virtual void Release() = 0;
    virtual void M01()
    {}
    virtual void M02()
    {}
    virtual void M03()
    {}
    virtual void M04()
    {}
    virtual void M05()
    {}
    virtual void M06()
    {}
    virtual void M07()
    {}
    virtual void M08()
    {}
    virtual void M09()
    {}
    virtual void M10()
    {}
    virtual void M11()
    {}
    virtual void M12()
    {}
    virtual void M13()
    {}
    virtual void M14()
    {}
    virtual void M15()
    {}
    virtual void M16()
    {}
    virtual void M17()
    {}
    virtual void M18()
    {}
    virtual void M19()
    {}
    virtual void M20()
    {}
    virtual void M21()
    {}
    virtual void M22()
    {}
    virtual void M23()
    {}
    virtual void M24()
    {}
    virtual void M25()
    {}
    virtual void M26()
    {}
    virtual void M27()
    {}
    virtual void M28()
    {}
    virtual void M29()
    {}
    virtual void M30()
    {}
    virtual void M31()
    {}
    virtual void M32()
    {}
    virtual void M33()
    {}
    virtual void M34()
    {}
    virtual void M35()
    {}
    virtual void M36()
    {}
    virtual void M37()
    {}
};
class NiShader : public NiShaderBase
{
  public:
    long m_iObjectReferenceCount;
    int m_iShaderValue;

    virtual void Release();
    virtual int* GetHash();
};
struct FUN_00a61920_Node
{
    NiShader* m_pObject;
    int unk04;
    FUN_00a61920_Node* m_pkNext;
    short unk0c;
    short unk0e;
};
class FUN_00a61920_Class
{
  public:
    FUN_00a61920_Node* m_pBuckets[1];

    bool __thiscall FindShaderByHash(int, int, NiShader**);
};
void NiShader::Release()
{}
int* NiShader::GetHash()
{
    return &m_iShaderValue;
}
class FUN_00a61ec0_cls;
class RefCountedNodeObject
{
  public:
    virtual void vSlot0();
    virtual void vSlot1();
    long m_iObjectReferenceCount;
};
struct PoolNode
{
    RefCountedNodeObject* m_obj;
    unsigned int m_unk04;
    PoolNode* m_next;
};
class NodePool
{
  public:
    void Free(PoolNode* node);
};
extern NodePool DAT_011f6238;
class FUN_00a61ec0_cls
{
  public:
    PoolNode* m_slots[0x2c9];
    unsigned int m_unkB24;

    void ClearAllSlots();
};
struct Vector4f
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
};
void __cdecl SwapByteQuadWords(Vector4f* q, unsigned int count);
struct A62190Component
{
    int m_eComponent;
    int m_eRepresentation;
    unsigned char m_ucBPC;
    bool m_bSigned;
};
// NiPixelFormat::GetMask
class A62190PixelFormat
{
  public:
    unsigned char m_ucFlags;
    unsigned char m_ucBitsPerPixel;
    unsigned char unk02;
    unsigned char unk03;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    A62190Component m_akComponents[4];

    unsigned int GetComponentMask(int eComponent) const;
};
// ReleasePendingTable - release the pending objects held in the engine slot table.
//
// The table lives at DAT_011f4514 and holds ten four byte slots.  Every slot
// points at a reference counted object:
//
//   +0x00  vtable pointer
//   +0x04  reference count
//
// A slot is released by dropping the reference count of the object it holds;
// when that count reaches zero the release hook of the object (vtable slot 1)
// runs, and afterwards the slot itself is cleared.
struct SlotObject
{
    virtual void SlotVirtual0();  // vtable slot 0
    virtual void SlotVirtual1();  // vtable slot 1 - the release hook
    int m_iObjectReferenceCount;  // +0x04
};
extern SlotObject* g_pendingTable[10];
typedef long(__stdcall* FNV_INTERLOCKED_DECREMENT)(volatile long*);
void ReleasePendingTable();
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
struct RefObj_a62
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
template <class T> struct NiPtr_a62
{
    T* m_pObject;
    NiPtr_a62& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
struct Settings_a62
{
    int m_ai[17];
};
extern Settings_a62 g_kSettings_11f4600;
extern NiPtr_a62<RefObj_a62> g_aspObjects_11f4514[10];
void __cdecl ApplySettings(const Settings_a62& kSettings);
extern MemoryManager _g_memoryManager;
extern int DAT_0109bc84;
extern "C" void NiFreeAlias(void*);
struct FUN_00a639e0_Class
{
    void* m_baseData0;
    void* m_baseData1;
    void* m_baseData2;
    FUN_00a639e0_Class* __thiscall FUN_00a639e0(char param_2);
};
struct FUN_00a66960_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int FUN_00a66960(int a1);
};
static int CompareFloatArrays(const float* pfA, const float* pfB, unsigned int ItemUpdateArray);
struct A66970Keys
{
    unsigned int m_uiCount;
    const float* m_pfA;
    const float* m_pfB;
};
int A66970Compare(const A66970Keys* pkKeys);
struct OutRec674
{
    int a;
    int b;
    unsigned char c;
};
struct Obj_a674
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
    virtual bool v35();
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
    unsigned char m_2c;
    void __thiscall FUN_00a72720(int flag, int* a, int* f, int* c, int* e, int* d, int* b);
};
struct FUN_00a674b0_cls
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
    Obj_a674* m_30;
    unsigned int unk34;
    unsigned char unk38;
    unsigned char unk39;
    unsigned char m_3a;
    void __thiscall GetOutRec(OutRec674* out);
};
extern int DAT_0109c28c;
struct FUN_00a693e0_cls
{
    int m_vptr00;

    void FUN_00a693e0();
};
extern unsigned int DAT_011f4980;
extern unsigned int DAT_011f4984;
struct FUN_00a69b00
{
    unsigned int originXBits, originYBits;
    float originZ, extentX, extentY, scaleX, scaleY;
    volatile unsigned char enabled;
    unsigned char unk1D, unk1E, unk1F;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    volatile int mode;
    FUN_00a69b00();
};
struct FUN_00a69b40_Class
{
    void __thiscall FUN_00a69b40(int param_2);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
class NiGlobalStringTable
{
  public:
    static char* __cdecl AddString(const char* str);
};
extern char* DAT_0109b220;
struct NiRefObjectStub
{
    virtual ~NiRefObjectStub();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct FixedStringStub
{
    char* m_kHandle;
};
static inline void ReleaseString(FixedStringStub& s)
{
    char* old = s.m_kHandle;
    if (old)
    {
        s.m_kHandle = NiGlobalStringTable::AddString(0);
        if (old != DAT_0109b220)
            InterlockedDecrement((volatile long*)(old - 8));
    }
}
extern NiRefObjectStub* DAT_011f49ac;
extern FixedStringStub DAT_011f49b0;
extern FixedStringStub DAT_011f49b4;
extern FixedStringStub DAT_011f49b8;
extern FixedStringStub DAT_011f49bc;
extern FixedStringStub DAT_011f49c0;
extern FixedStringStub DAT_011f49c4;
extern FixedStringStub DAT_011f49c8;
extern FixedStringStub DAT_011f49cc;
extern FixedStringStub DAT_011f49d0;
extern FixedStringStub DAT_011f49d4;
void ReleaseGlobalStrings();
struct FUN_00a6db50_V
{
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    FUN_00a6db50_V* __thiscall Set(float a, float b, float c, float d);
};
class A6DB70ColorA
{
  public:
    A6DB70ColorA()
    {}
    A6DB70ColorA(float fR, float fG, float fB, float fA) : r(fR), g(fG), b(fB), a(fA)
    {}

    A6DB70ColorA FUN_00a6db70(const A6DB70ColorA& kColor) const;

    float r;
    float g;
    float b;
    float a;
};
struct FUN_00a6dbd0_cls
{
    float m_f0;
    float m_f1;
    float m_f2;
    float m_f3;

    void Negate(float* __restrict out);
};
class FUN_00a71b80_cls
{
  public:
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    float m_10;
    float m_14;
    unsigned char m_18;

    FUN_00a71b80_cls* Init(float a1, float a2, float a3, float a4, float a5, float a6, unsigned char flag);
};
struct FUN_00a75dc0_cls
{
    void* FUN_00a75dc0(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5,
                       unsigned int a6, unsigned int a7, unsigned int a8, unsigned int a9, unsigned int a10,
                       unsigned int a11);
};
void* __cdecl FUN_00aa13e0(unsigned int size);
struct FUN_00a71c40_cls
{
    int* m_vt;
    void FUN_00a89720(void* p);
    FUN_00a71c40_cls* ConstructWithAlloc(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4,
                                         unsigned int a5, unsigned int a6, unsigned int a7, unsigned int a8,
                                         unsigned int a9, unsigned int a10, unsigned int a11);
};
// FUN_00a71cc0 : constructor-like helper that calls a base routine with the
// argument and then installs the class vtable pointer, returning itself.
extern int DAT_0109cd44;
struct FUN_00a71cc0_cls
{
    void* m_pVTable;
    void FUN_00a89720(int arg);
    FUN_00a71cc0_cls* FUN_00a71cc0(int arg);
};
struct FUN_00a72550_Class
{
    struct Item
    {
        int unk00;
        int unk04;
        int unk08;
    };
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Item** unk20;
    unsigned short unk24;
    unsigned short unk26;

    int GetItemData(unsigned int index, int* out);
};
struct SceneEntry
{
    virtual void Detach(unsigned int reason);
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0C();
    virtual void Prepare(unsigned int reason);
};
struct IndexedObjects
{
    void* vtable;
    SceneEntry** entries;
    unsigned short capacity;
    unsigned short count;
    unsigned short elementSize;
    unsigned short growth;
    void __thiscall FUN_00ba3aa0(unsigned int index, unsigned int* removed);
};
struct LinkedRecord
{
    void* owner;
    void* object;
    void* metadata;
    void* parent;
    void* child;
    unsigned int objectIndex;
    void* cachedValue;
};
struct ObjectRegistry
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    unsigned int recordCount;
    LinkedRecord* records;
    void* unk18;
    IndexedObjects indexedObjects;

    bool __thiscall RemoveObject(unsigned int index, bool clearReferences);
};
struct BA726A0Entry
{
    unsigned int m_uiValue1;
    void* m_pResource;
    unsigned int m_uiStride;
    unsigned int m_uiSize;
    unsigned int m_uiValueBeforeCount;
    unsigned int m_uiCount;
    unsigned int m_uiElapsedTime;
};
class FUN_00a726a0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    unsigned short m_usFormat;
    unsigned int m_uiStreamIndex;
    BA726A0Entry* m_pkEntryArray;
    int unk18;
    int unk1C;
    int unk20;
    unsigned short unk24;
    unsigned short m_usMaxCount;

    bool FUN_00a726a0(unsigned int uiIndex, unsigned int ItemUpdateArray, unsigned int uiStart, void* pvData,
                      unsigned short usFormat, unsigned int uiStride, unsigned int uiElapsedMilliseconds);
};
struct ObjectWriter
{
    void* vtable;
    unsigned int bytesWritten;
    unsigned int(__cdecl* write)(ObjectWriter*, const void*, unsigned int, const unsigned int*, int);
};
struct BinaryStream
{
    ObjectWriter* Writer()
    {
        return *reinterpret_cast<ObjectWriter**>(reinterpret_cast<char*>(this) + 0x24c);
    }
};
struct ColorState
{
    unsigned char format;
    unsigned char flags;
    unsigned short reserved;
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int alpha;
    unsigned int threshold;
    unsigned int blendMode;

    void FUN_00a72cb0(BinaryStream* stream);
};
class BA72DB0BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BA72DB0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(BA72DB0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

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
class BA72DB0Stream
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
    BA72DB0BinaryStream* m_pUnderlyingStream;
    BA72DB0BinaryStream* m_pBackingStream;
};
template <class T>
inline void BA72DB0BinaryStreamSave(BA72DB0BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void BA72DB0SaveBinary(BA72DB0Stream& kStream, const T& value)
{
    BA72DB0BinaryStreamSave(*kStream.m_pBackingStream, &value);
}
class BA72DB0Data
{
  public:
    void FUN_00a72db0(BA72DB0Stream& kStream);

    bool m_bFlag;
    int m_iValue0;
    int m_iValue1;
    int m_iValue2;
    int m_iValue3;
    int m_iValue4;
    int m_iValue5;
};
extern int DAT_0109d55c;
struct SceneFactoryObject
{
    void* m_vtbl;
    void Initialize();
};
SceneFactoryObject* CreateSceneFactoryObject();
extern int DAT_011aa04c;
void __cdecl FUN_00a74d80(int param_1);
// FUN_00a74d90 - installs a callback pointer into the global slot at 0x011aa050.
//
// Original bytes:
//   8b 44 24 04          mov eax, dword ptr [esp+4]
//   a3 50 a0 1a 01       mov dword ptr [0x011aa050], eax
//   c3                   ret
//
// The global is referenced by a plain DIR32 relocation with addend 0 and is
// declared (never defined) here, so the checker binds it to the original's
// own address.  The name is spelled with a void* type so that it does not
// collide with the canonical "?DAT_011aa050@@3HA" entry in the symbol DB.
extern void* DAT_011aa050;
void __cdecl FUN_00a74d90(void* callback);
struct CallTarget_00a74e10
{
    int SetFromFrustum(int, int);
};
struct SearchObject
{
    int FUN_00a755d0(unsigned int arg0);
};
extern int DAT_00ff0000;
struct FUN_00a77110_info
{
    unsigned int m_eVertexFormat;
    unsigned int m_flags;
};
void __cdecl FUN_00a77110(unsigned int width, unsigned int rows, unsigned int unk0c, unsigned char* dst,
                          unsigned int unk14, FUN_00a77110_info* info, const unsigned char* src);
struct BitPackLayout
{
    unsigned int mask0;
    unsigned int mask1;
    unsigned int mask2;
    unsigned int unk0C;
    unsigned char rshift0;
    unsigned char rshift1;
    unsigned char rshift2;
    unsigned char unk13;
    unsigned char lshift0;
    unsigned char lshift1;
    unsigned char lshift2;
};
void UnpackPixels(unsigned int countA, unsigned int countB, unsigned int unk0C, unsigned char* dst, unsigned int unk14,
                  unsigned int unk18, unsigned int srcAddr, const BitPackLayout* layout);
// Convert a 16-bit-per-pixel surface into 32-bit RGBA.
//
// The pixel layout is described by FnvPixelFormat: four channel masks
// (dwords) followed by the per-channel right and left shift amounts
// (bytes).  Each source pixel is a 16-bit word; every channel is
// extracted, scaled and written as one byte of the destination pixel.
//
// arg0 = pixels per pass, arg1 = number of passes,
// arg3 = destination bytes, arg6 = source words, arg7 = pixel layout.
struct FnvPixelFormat
{
    unsigned int mask[4];
    unsigned char shiftRight[4];
    unsigned char shiftLeft[4];
};
void ConvertPixelsToBytes(unsigned int count, unsigned int rows, unsigned int a2, char* dest, unsigned int a4, void* a5,
                          unsigned short* src, FnvPixelFormat* fmt);
struct A77740Format
{
    unsigned int m_uiMask0;
    unsigned int m_uiMask1;
    unsigned int m_uiMask2;
    unsigned int m_uiMask3;
    unsigned char m_ucLeftShift0;
    unsigned char m_ucLeftShift1;
    unsigned char m_ucLeftShift2;
    unsigned char m_ucLeftShift3;
    unsigned char m_ucRightShift0;
    unsigned char m_ucRightShift1;
    unsigned char m_ucRightShift2;
    unsigned char m_ucRightShift3;
};
void ConvertRgbToPacked16(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiUnused, unsigned char* pucDest,
                          unsigned int uiUnused2, const A77740Format* pkFmt, const unsigned char* pucSrc);
struct S_00a77800_Layout
{
    unsigned int mask0;
    unsigned int mask1;
    unsigned int unk08;
    unsigned int mask2;
    unsigned char shl0;
    unsigned char shl1;
    unsigned char unk12;
    unsigned char shl2;
    unsigned char shr0;
    unsigned char shr1;
    unsigned char unk16;
    unsigned char shr2;
};
void __cdecl FUN_00a77800(unsigned int count, unsigned int rows, unsigned int unkArg3, unsigned int* dst,
                          unsigned int unkArg5, const S_00a77800_Layout* layout, const unsigned char* src);
bool FUN_00a77920(int a);
struct NiBinaryStream;
typedef unsigned int (*NiBinaryStreamWriteFn)(NiBinaryStream* pThis, const void* pvBuffer, unsigned int uiBytes,
                                              unsigned int* puiComponentSizes, unsigned int uiNumComponents);
struct NiBinaryStream
{
    void* vtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    NiBinaryStreamWriteFn m_pfnWrite;

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytes = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytes;
        return uiBytes;
    }
};
struct NiStream
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
    NiBinaryStream* m_pBackingStream;
};
template <class T> inline void SerializeValue(NiBinaryStream& binstream, const T& value)
{
    unsigned int uiSize = sizeof(T);
    binstream.BinaryWrite(&value, uiSize, &uiSize, 1);
}
template <class T> inline void SerializeValue(NiStream& stream, const T& value)
{
    SerializeValue(*stream.m_pBackingStream, value);
}
struct Entry
{
    int a;
    int b;
    char c;
    char d;
};
struct FUN_00a7d1a0_Class
{
    char m_c0;
    char m_c1;
    int m_i4;
    int m_i8;
    int m_iC;
    int m_i10;
    Entry m_entries[4];

    void FUN_00a7d1a0(NiStream& stream);
};
void* __cdecl BuildSqrtLut();
void FUN_00a7e930();
struct S_00a7fea0_P3
{
    float x, y, z;
    S_00a7fea0_P3()
    {}
    S_00a7fea0_P3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    S_00a7fea0_P3 operator+(const S_00a7fea0_P3& o) const
    {
        return S_00a7fea0_P3(x + o.x, y + o.y, z + o.z);
    }
    S_00a7fea0_P3 operator*(float s) const
    {
        return S_00a7fea0_P3(x * s, y * s, z * s);
    }
};
inline S_00a7fea0_P3 operator*(float s, const S_00a7fea0_P3& v)
{
    return S_00a7fea0_P3(s * v.x, s * v.y, s * v.z);
}
struct S_00a7fea0_M3
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    S_00a7fea0_P3 operator*(const S_00a7fea0_P3& v) const
    {
        return S_00a7fea0_P3(m00 * v.x + m01 * v.y + m02 * v.z, m10 * v.x + m11 * v.y + m12 * v.z,
                             m20 * v.x + m21 * v.y + m22 * v.z);
    }
};
struct S_00a7fea0_Xf
{
    S_00a7fea0_M3 rot;
    S_00a7fea0_P3 t;
    float scale;
};
struct S_00a7fea0_Class
{
    S_00a7fea0_P3 p;
    float scale;
    void TransformPoint(const S_00a7fea0_Xf& a);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
class MemoryManagerA61
{
  public:
    void Deallocate(void* pvMem);
};
extern MemoryManagerA61 g_kMemoryManagerA61;
class NiObjectA61
{
  public:
    virtual ~NiObjectA61();
    virtual void DeleteThis();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3C();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4C();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual void vfn5C();
    virtual void vfn60();
    virtual void vfn64();
    virtual void vfn68();
    virtual void vfn6C();
    virtual void vfn70();
    virtual void vfn74();
    virtual void vfn78();
    virtual void vfn7C();
    virtual void vfn80();
    virtual void vfn84();
    virtual void vfn88();
    virtual void vfn8C();
    virtual void vfn90();
    virtual void vfn94();
    virtual void vfn98();
    virtual const char** GetName();

    void DecRefCount()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};
template <class T> class NiPointerA61
{
  public:
    ~NiPointerA61()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    T* operator->() const
    {
        return m_pObject;
    }

    T* m_pObject;
};
struct NodeA61
{
    static void operator delete(void* pvMem)
    {
        g_kMemoryManagerA61.Deallocate(pvMem);
    }

    NiPointerA61<NiObjectA61> m_pReferencedObject;
    int m_iData;
    NodeA61* m_pkNext;
};
unsigned int __cdecl GetPrefixLengthA61(const char* pcName, int iFlags);
unsigned int __cdecl HashNameA61(const char* pcName);
class NameTableA61
{
  public:
    void RemoveNode(NodeA61* pkNode);

    NodeA61* m_apkBuckets[713];
    unsigned int m_uiCount;
};
// Fixed-size (713 bucket) pointer map: return the current entry's object and advance the iterator.
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* plValue);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* plValue);
class A619B0Object
{
  public:
    virtual ~A619B0Object() throw();
    virtual void DeleteThis() throw();
    unsigned int m_uiRefCount;

    void IncRefCount() throw()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    void DecRefCount() throw()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};
template <class T> class A619B0Pointer
{
  public:
    T* m_pObject;

    A619B0Pointer& operator=(const A619B0Pointer& kOther) throw()
    {
        if (m_pObject != kOther.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = kOther.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
struct A619B0Item
{
    A619B0Pointer<A619B0Object> m_spValue;
    int m_iKey;
    A619B0Item* m_pkNext;
};
struct A619B0Iterator
{
    A619B0Item* m_pkItem;
    unsigned int m_uiBucket;
};
class A619B0Map
{
  public:
    A619B0Item* m_apkBuckets[713];

    bool GetNext(A619B0Iterator& kIter, A619B0Pointer<A619B0Object>& rspValue);
};
struct MyPool
{
    FUN_00a61ec0_cls m_buckets[7];
};
struct FUN_0040fbf0_Class
{
    void Lock(int);
};
extern FUN_00a615c0_Class* DAT_011f4468;
extern FUN_0040fbf0_Class DAT_011f4480;
extern int DAT_011f4484;
void __cdecl FUN_00a62030();
class BA643B0BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BA643B0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
class BA643B0Stream
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
    BA643B0BinaryStream* m_pUnderlyingStream;
};
template <class T> inline void BA643B0BinaryStreamLoad(BA643B0BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void BA643B0LoadBinary(BA643B0Stream& kStream, T& value)
{
    BA643B0BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}
void __cdecl FUN_00a643b0(BA643B0Stream& kStream, char* pcValue);
struct Q67530Data
{
    int a;
    int b;
    int d;
    int c;
    int e;
    int f;
};
struct BSFaceGenModel
{
    void FUN_00a72720(int flag, void* a, void* f, void* c, void* e, void* d, void* b);
};
struct Q67530Cls : FUN_00a674b0_cls
{
    void FillOutRec674(OutRec674* out);
};
void* __cdecl NiMallocA6F(unsigned int uiSize) throw();
extern "C" void* __cdecl MemSetA6F(void* pvDest, int iValue, unsigned int uiSize);
struct NiTMapItemA6F;
class NiTMapBaseA6F
{
  public:
    __forceinline NiTMapBaseA6F(unsigned int uiHashSize = 37) throw()
    {
        m_uiHashSize = uiHashSize;
        m_uiCount = 0;
        unsigned int uiSize = sizeof(NiTMapItemA6F*) * m_uiHashSize;
        m_ppkHashTable = (NiTMapItemA6F**)NiMallocA6F(uiSize);
        MemSetA6F(m_ppkHashTable, 0, m_uiHashSize * sizeof(NiTMapItemA6F*));
    }
    virtual ~NiTMapBaseA6F() throw();

    unsigned int m_uiHashSize;
    NiTMapItemA6F** m_ppkHashTable;
    unsigned int m_uiCount;
};
class NiTPointerMapA6F : public NiTMapBaseA6F
{
  public:
    __forceinline NiTPointerMapA6F(unsigned int uiHashSize = 37) throw() : NiTMapBaseA6F(uiHashSize)
    {}
    virtual ~NiTPointerMapA6F() throw();
};
class NiObjectA6F
{
  public:
    static void* operator new(unsigned int uiSize) throw();

    NiObjectA6F() throw();
    virtual ~NiObjectA6F() throw();

    unsigned int m_uiRefCount;
};
class NiExtraDataMapA6F : public NiObjectA6F
{
  public:
    __forceinline NiExtraDataMapA6F() throw() : m_pkLast(0)
    {}
    virtual ~NiExtraDataMapA6F() throw();

    static NiObjectA6F* FUN_00a6f000();

    NiTPointerMapA6F m_kFormatEntries;
    void* m_pkLast;
};
struct NiPixelChannelsA773
{
    unsigned int m_uiRedMask;
    unsigned int m_uiGreenMask;
    unsigned int m_uiBlueMask;
    unsigned int m_uiAlphaMask;
    unsigned char m_ucRedShift;
    unsigned char m_ucGreenShift;
    unsigned char m_ucBlueShift;
    unsigned char m_ucAlphaShift;
    unsigned char m_ucRedBits;
    unsigned char m_ucGreenBits;
    unsigned char m_ucBlueBits;
    unsigned char m_ucAlphaBits;
};
void __cdecl FUN_00a773d0(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiDestStride,
                          unsigned char* pucDest, unsigned int uiDestSize, unsigned int uiSrcStride,
                          const unsigned short* pusSrc, const NiPixelChannelsA773* pkChannels);
struct NiPixelChannelsA77
{
    unsigned int m_uiRedMask;
    unsigned int m_uiGreenMask;
    unsigned int m_uiBlueMask;
    unsigned int m_uiAlphaMask;
    unsigned char m_ucRedShift;
    unsigned char m_ucGreenShift;
    unsigned char m_ucBlueShift;
    unsigned char m_ucAlphaShift;
    unsigned char m_ucRedBits;
    unsigned char m_ucGreenBits;
    unsigned char m_ucBlueBits;
    unsigned char m_ucAlphaBits;
};
void __cdecl ConvertPixelsToRgb(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiDestStride,
                                unsigned char* pucDest, unsigned int uiDestSize, unsigned int uiSrcStride,
                                const unsigned int* puiSrc, const NiPixelChannelsA77* pkChannels);
struct NiPixelChannelsA776
{
    unsigned int m_uiRedMask;
    unsigned int m_uiGreenMask;
    unsigned int m_uiBlueMask;
    unsigned int m_uiAlphaMask;
    unsigned char m_ucRedShift;
    unsigned char m_ucGreenShift;
    unsigned char m_ucBlueShift;
    unsigned char m_ucAlphaShift;
    unsigned char m_ucRedBits;
    unsigned char m_ucGreenBits;
    unsigned char m_ucBlueBits;
    unsigned char m_ucAlphaBits;
};
void __cdecl FUN_00a776b0(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiDestStride, unsigned int* puiDest,
                          unsigned int uiDestSize, const NiPixelChannelsA776* pkDestChannels,
                          const unsigned char* pucSrc, const NiPixelChannelsA776* pkSrcChannels);
extern "C" int __cdecl tolower(int);
bool __cdecl FUN_00a614d0(const char* a, const char* b);
struct A5FC10Stub
{
    A5FC10Stub* __thiscall FUN_00a5fc10();
};
void* __cdecl FUN_00aa13e0(unsigned int size);
A5FC10Stub* __cdecl CreateA5FC10Stub();
struct This;
struct T
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
    char pad[0x5b - 4];
    unsigned char m5b;
    virtual void v36(This*);
};
struct This
{
    char pad[0x24];
    T* m24;
    void DispatchIfStateFour();
};
struct FUN_00a5fca0_cls
{
    void FUN_00a5fca0();
};
struct FUN_00a60160_cls : FUN_00a5fca0_cls
{
    void* DestroyIfFlagged(unsigned int flags);
};
extern "C" void __cdecl _delete(void* p, unsigned int size);
struct NiStreamA606
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void SaveLinkID(void* pkObject);
    void WriteObjectLink(void* pkString);
};
struct ControllerA606
{
    char m_acUnk00[0x18];
    unsigned int m_uiUnk18;
    unsigned int m_uiUnk1c;
    unsigned int m_uiUnk20;
    char m_acUnk24[0xc];
    void* m_kName;
    int m_iUnk34;
    void* m_pkTarget1;
    void* m_pkTarget2;
    bool m_bUnk40;
    bool m_bUnk41;
    bool m_bUseFirst;
    void FUN_00a5d7b0(NiStream& kStream);
    void FUN_00a60600(NiStream& kStream);
};
class FUN_00a5e3a0_Helper
{
  public:
    void* FUN_00aa3e40(unsigned int uiSize);
};
struct EntryA616
{
    int unk00;
    unsigned int m_key;
};
struct NodeA616
{
    EntryA616* m_entry;
    NodeA616* m_next;

    NodeA616(EntryA616* entry, NodeA616* next) : m_entry(entry), m_next(next)
    {}

    static void* operator new(unsigned int uiSize)
    {
        return ((FUN_00a5e3a0_Helper*)&_g_memoryManager)->FUN_00aa3e40(uiSize);
    }
    static void operator delete(void* p);
};
class HashA616
{
  public:
    NodeA616* m_buckets[1001];
    unsigned int m_uiItemCount;

    void FUN_00a61610(unsigned int key, EntryA616* entry);
};
class A61E60Obj
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

    virtual char** GetNameRef();
};
struct A61E60Node
{

    A61E60Obj* m_key;

    unsigned int m_unk04;

    A61E60Node* m_pNext;
};
unsigned int __cdecl FUN_00af4170(const char* s, int n);
unsigned int FUN_00a61530(const char* str);
struct NodeList
{
    A61E60Node* m_pHead;
    A61E60Node* Find(A61E60Obj* obj)
    {
        A61E60Node* n = m_pHead;
        while (n)
        {
            if (obj == n->m_key)
                break;
            n = n->m_pNext;
        }
        return n;
    }
};
void* __cdecl FindNodeByObject(A61E60Obj* obj);
bool __fastcall FUN_00a5c180(void*, int, NiStream*);
bool __fastcall FUN_00a62130(void* a, int b, NiStream* s);
class EqBase
{
  public:
    bool __thiscall FUN_00a5c820(void* other);
    bool __thiscall FUN_00a62140(void* other);
};
class ColorAStandIn
{
  public:
    float r, g, b, a;
    ColorAStandIn()
    {}
    ColorAStandIn(float fR, float fG, float fB, float fA)
    {
        r = fR;
        g = fG;
        b = fB;
        a = fA;
    }
    ColorAStandIn Subtract(const ColorAStandIn& c) const;
};
struct FUN_00a727b0_Class
{
    unsigned int FUN_00a727b0();
};
extern void __cdecl FUN_00a8a9b0();
void __cdecl FUN_00a75f00();
unsigned short __fastcall FUN_00a75f20(char* p, int);
class FileA609
{
  public:
    virtual ~FileA609();
};
FileA609* __cdecl FUN_00aa1a20(const char* pcName, NiFile::OpenMode eMode, unsigned int uiBufferSize);
class ObjA609;
struct NamedA609
{
    const char* m_pcName;
};
class OwnerA609
{
  public:
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00C();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01C();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02C();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03C();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04C();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05C();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06C();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07C();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void Load(ObjA609* pkObj);

    char unk004[0x57];
    unsigned char m_eRequestType;
};
class ObjA609
{
  public:
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00C();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01C();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02C();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03C();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04C();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05C();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06C();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07C();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08C();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual NamedA609* GetNamed();

    char unk004[0x20];
    OwnerA609* m_pkOwnerManager;
    char unk028[0x1c];
    FileA609* m_pFile;

    void LoadFile();
};
struct NiFixedString
{
    char* m_handle;
    NiFixedString& operator=(const char* value);
    void Assign(const char* value)
    {
        char* old = m_handle;
        if (old != value)
        {
            m_handle = NiGlobalStringTable::AddString(value);
            if (old != DAT_0109b220)
                InterlockedDecrement((volatile long*)(old - 8));
        }
    }
    void Clear()
    {
        char* old = m_handle;
        if (old)
        {
            m_handle = NiGlobalStringTable::AddString(0);
            if (old != DAT_0109b220)
                InterlockedDecrement((volatile long*)(old - 8));
        }
    }
};
struct TextureBinaryInput
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(TextureBinaryInput*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int BinaryRead(void* buffer, unsigned int totalBytes, unsigned int* componentSizes,
                            unsigned int numComponents)
    {
        unsigned int bytes = m_pfnRead(this, buffer, totalBytes, componentSizes, numComponents);
        m_uiStreamFlags += bytes;
        return bytes;
    }
};
template <class T> inline void TextureBinaryStreamLoad(TextureBinaryInput& input, T* value, unsigned int count = 1)
{
    unsigned int size = sizeof(T);
    input.BinaryRead(value, count * size, &size, 1);
}
struct TextureLoadStream : NiStream
{
    void FUN_00a64ea0(NiFixedString*);
    void FUN_00a64df0(NiFixedString*);
    void FUN_00a64700(unsigned int);
    void FUN_00a645b0();
    void FUN_00a636f0(const char*);
    bool FUN_00a636b0(char*, unsigned int);
    void FUN_00a633d0(const char*, NiObjectA61**);
    void FUN_00a633b0(void*);
    template <class T> void Read(T& value)
    {
        TextureBinaryStreamLoad(*reinterpret_cast<TextureBinaryInput*>(unk24c), &value);
    }
    void Read(bool& value)
    {
        unsigned char byte;
        Read(byte);
        value = byte != 0;
    }
    unsigned int Version() const
    {
        return static_cast<unsigned int>(unk0d8);
    }
};
struct TextureStreamVirtual
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
    virtual void Register(NiObjectA61*);
};
enum SourcePixelLayout
{
    PixelLayout4 = 4,
    PixelLayout5 = 5,
    PixelLayout6 = 6
};
enum SourceMipmapFormat
{
    MipmapDefault = 0,
    MipmapDisabled = 1,
    MipmapEnabled = 2
};
enum SourceAlphaFormat
{
    AlphaDefault = 0,
    AlphaNone = 1,
    AlphaBinary = 2,
    AlphaSmooth = 3
};
struct SourceTextureBase : NiObjectA61
{
    unsigned int unk08, unk0c, unk10, unk14;
    unsigned int pixelLayout, alphaFormat, mipmapFormat;
    unsigned int unk24, unk28, unk2c;
    void FUN_00a47350(TextureLoadStream&);
};
struct NiSourceTexture : SourceTextureBase
{
    NiFixedString fileName;
    NiFixedString resolvedName;
    NiObjectA61* pixelData;
    NiObjectA61* rendererData;
    bool isStatic;
    bool loadDirect;
    bool persistent;
    void FUN_00a60180(TextureLoadStream& stream);
};
extern bool DAT_011f4780;
void __cdecl FUN_00a76960(void*, void*);
bool __cdecl FUN_00aa1a30(const char*, int);
class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f444c;
char* __cdecl FUN_00a7d330(char* pcText);
char* __cdecl FUN_00a7d5e0(const char* pcPrefix, const char* pcText);
struct StrArr
{
    void* vtable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& element);
    void Add(char*& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
    }
};
struct FUN_00a62a40_this
{
    void FUN_00a62a40(StrArr* pkStrings);
};
struct FUN_00a60770_shell : FUN_00a62a40_this
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
    const char* m_pcFileName;
    void GetFileStrings(StrArr* pkStrings);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
namespace A61F {

class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis() throw();
    long m_uiRefCount;

    void DecRefCount() throw()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

class NiPointer
{
  public:
    NiRefObject* m_pObject;
    NiPointer() throw() : m_pObject(0)
    {}
};

struct LockState
{
    int m_pOwnerObject;
    int m_uiItemCount;
    void Unlock() throw()
    {
        if (--m_uiItemCount == 0)
            m_pOwnerObject = 0;
    }
};

}
class GlobalObject_0096a2d0
{
  public:
    void Lock(const char* pcName) throw();
};
extern "C" bool __cdecl fnv_NiStreamGetTexture(const char* pcName, A61F::NiPointer* apTextureOutput) throw();
bool __cdecl FUN_00a61f30(const void* pvTexture) throw();
bool __cdecl FUN_00a61fb0(const char* pcName);
struct FUN_00a63840_Class
{
    unsigned int m0;
    unsigned int m4;
    unsigned int FUN_00a63840(unsigned int a);
};
struct NiPixelFormatA775
{
    unsigned int m_auiMask[4];
    unsigned char m_aucShift[4];
    unsigned char m_aucBitsLoss[4];
};
void __cdecl ConvertPixelFormat(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiDestStride,
                                unsigned char* pucDest, unsigned int uiSrcStride, unsigned int uiSrcSize,
                                const unsigned char* pucSrc, const NiPixelFormatA775* pkSrcFmt);
void __cdecl FUN_00a8a9a0();
void __cdecl FUN_00a7b7d0();
struct Vec3
{
    float x;
    float y;
    float z;
    Vec3 operator*(float scale) const
    {
        Vec3 r;
        r.x = x * scale;
        r.y = y * scale;
        r.z = z * scale;
        return r;
    }
    Vec3& operator+=(const Vec3& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        return *this;
    }
};
void __cdecl AddScaledPoints(NiPoint3* dest, float scale, const NiPoint3* src, unsigned int count);
extern int DAT_0109b944;
extern int DAT_0109df8c;
struct FUN_00a7fb80_Class
{
    void* m_ppVirtualMethodTable;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    volatile int m_24;
    int m_28;
    int m_2C;
    int m_30;
    void* __thiscall FUN_00a5c200();
    void* __thiscall FUN_00a7fb80();
};
struct Z2Setup
{
    void* __thiscall FUN_00a5f7b0();
};

class FUN_007613f0
{
  public:
    int unk00;
    FUN_007613f0() throw();
    ~FUN_007613f0() throw()
    {}
    static void* operator new[](unsigned int uiSize)
    {
        return ((FUN_00a5e3a0_Helper*)&DAT_011f6238)->FUN_00aa3e40(uiSize);
    }
};

// @fnv 0x00a63ae0
void* FUN_00a63ae0(unsigned int ItemUpdateArray)
{
    return new FUN_007613f0[ItemUpdateArray];
}
