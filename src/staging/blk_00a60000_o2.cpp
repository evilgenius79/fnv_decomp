// staging/blk_00a60000_o2.cpp: NiShader, PivotGeometry, NiDirectionalLight, NiTMapBaseStub and more (116 functions)

#include <windows.h>
// src/staging/blk_00a60000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

void* __cdecl _fnv_zlib_memset(void* p, int c, unsigned int n);

struct FUN_00a61590_class
{
    void* __thiscall ClearAndReset();
};

// Zeroes the first 0xb24 bytes of this object, sets the int at offset 0xb24 to 0, and returns this.
// @fnv 0x00a61590
void* __thiscall FUN_00a61590_class::ClearAndReset()
{
    _fnv_zlib_memset(this, 0, 0xb24);
    *(int*)((char*)this + 0xb24) = 0;
    return this;
}

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

// Calls Test(1) on the shader pointer map and the union BV object if each is non-null.
// @fnv 0x00a632b0
void FUN_00a632b0()
{
    if (DAT_011f4784)
        DAT_011f4784->Test(1);
    if (DAT_011f4788)
        DAT_011f4788->Test(1);
}

extern "C" void NiFreeAlias(void*);
extern void* DAT_011f4aa8;

// @fnv 0x00a7e940
void FreeGlobalAlias()
{
    NiFreeAlias(DAT_011f4aa8);
    DAT_011f4aa8 = 0;
}

extern int DAT_0109df2c;
extern int DAT_011f4ab4;

struct FUN_00a7f820_Class
{
    void __thiscall FUN_00a7f820();
};

// @fnv 0x00a7f820
void __thiscall FUN_00a7f820_Class::FUN_00a7f820()
{
    *reinterpret_cast<int*>(this) = (int)&DAT_0109df2c;
    DAT_011f4ab4 = 0;
}

// Clamps each of the first three floats in the array to a maximum of 1.0.
// @fnv 0x00a69690
void __fastcall FUN_00a69690(float* afValues)
{
    if (afValues[0] > 1.0f)
        afValues[0] = 1.0f;
    if (afValues[1] > 1.0f)
        afValues[1] = 1.0f;
    if (afValues[2] > 1.0f)
        afValues[2] = 1.0f;
}

struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
extern MemoryManager g_memoryManager;

struct FUN_00a615c0_Class
{
    void __thiscall ClearAllBuckets();
};

// Walks each of 0x3e9 bucket lists, freeing every node via g_memoryManager.Deallocate, then clears the buckets and the pointer at offset 0xfa4.
// @fnv 0x00a615c0
void __thiscall FUN_00a615c0_Class::ClearAllBuckets()
{
    void** p = (void**)(this + 0);
    for (unsigned int i = 0; i < 0x3e9; ++i)
    {
        void* current = p[i];
        while (current != 0)
        {
            void* node = current;
            current = ((void**)node)[1];
            ((void**)((void**)node)[0])[1] = 0;
            g_memoryManager.Deallocate(node);
        }
        p[i] = 0;
    }
    *(void**)((char*)this + 0xfa4) = 0;
}

struct RecursiveSpinLock
{
    void __thiscall Lock(const char*);
};
extern RecursiveSpinLock g_011c5f80;
extern unsigned int DAT_011c5f84;
extern void* DAT_011c5f58;
// @fnv 0x00a638c0
void __stdcall FUN_00a638c0(void* pNode)
{
    ((unsigned short*)((char*)pNode + 8))[0] = 0;
    g_011c5f80.Lock(0);
    *(unsigned int*)((char*)pNode + 4) = 0;
    *(unsigned int*)pNode = (unsigned int)DAT_011c5f58;
    --DAT_011c5f84;
    DAT_011c5f58 = pNode;
    if (!DAT_011c5f84)
        *(unsigned int*)&g_011c5f80 = 0;
}

namespace fnv_00a63b30 {
extern "C" void NiFree(void*);
extern int DAT_0109bc3c;
extern void* g_memoryManager;

struct MemoryManager
{
    void Deallocate(void*);
};

struct FUN_00a63b30_Class
{
    void* __thiscall FUN_00a63b30(bool);
};

// @fnv 0x00a63b30
void* __thiscall FUN_00a63b30_Class::FUN_00a63b30(bool abFree)
{
    void* p = *(void**)((char*)this + 4);
    *(int**)((char*)this) = &DAT_0109bc3c;
    NiFree(p);
    if (abFree & 1)
        ((MemoryManager*)&g_memoryManager)->Deallocate(this);
    return this;
}
}  // namespace fnv_00a63b30

namespace fnv_00a652d0 {
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager _g_memoryManager;
extern int DAT_0109bd98;
void __cdecl ReleaseObjectArray(void*);
struct FUN_00a652d0_class
{
    int m0;
    void* m4;
    void* __thiscall FUN_00a652d0(bool);
};
// Sets m0 to &DAT_0109bd98, calls ReleaseObjectArray on m4, and if b is set deallocates this via _g_memoryManager, returning this.
// @fnv 0x00a652d0
void* __thiscall FUN_00a652d0_class::FUN_00a652d0(bool abFree)
{
    m0 = (int)&DAT_0109bd98;
    ReleaseObjectArray(m4);
    if (abFree & 1)
        _g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00a652d0

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct NiTriBasedGeomData;
NiTriBasedGeomData* __fastcall InitializeTriBasedGeomData(NiTriBasedGeomData*);
extern int DAT_0109dac4;
// @fnv 0x00a7b790
void* __cdecl FUN_00a7b790()
{
    char* p = (char*)BSFadeNode::operator new(0x58);
    if (p)
    {
        InitializeTriBasedGeomData((NiTriBasedGeomData*)p);
        *(int*)(p + 0x44) = 0;
        *(int*)(p + 0x48) = 0;
        *(int*)(p + 0x4c) = 0;
        *(int*)(p + 0x54) = 0;
        *(short*)(p + 0x50) = 0;
        *(int*)p = (int)&DAT_0109dac4;
        return p;
    }
    return 0;
}

void __fastcall FUN_00a71f60(void*);
extern int DAT_0109dd0c;
struct FUN_00a7d670_Class
{
    void* __thiscall FUN_00a7d670();
};
// @fnv 0x00a7d670
void* __thiscall FUN_00a7d670_Class::FUN_00a7d670()
{
    FUN_00a71f60(this);
    *(float*)((char*)this + 0xf0) = 0.0f;
    *(int*)this = (int)&DAT_0109dd0c;
    *(float*)((char*)this + 0xf4) = 1.0f;
    *(unsigned char*)((char*)this + 0x9d) = 2;
    *(float*)((char*)this + 0xf8) = 0.0f;
    return this;
}

struct CloningProcess;
struct NiDirectionalLight
{
    void CopyMemberData(NiDirectionalLight* dst, CloningProcess& proc);
    void FUN_00a7d6a0(NiDirectionalLight* dst, CloningProcess& proc);
};
// @fnv 0x00a7d6a0
void NiDirectionalLight::FUN_00a7d6a0(NiDirectionalLight* dst, CloningProcess& proc)
{
    CopyMemberData(dst, proc);
    *reinterpret_cast<float*>(reinterpret_cast<char*>(dst) + 0xf0) =
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xf0);
    *reinterpret_cast<float*>(reinterpret_cast<char*>(dst) + 0xf4) =
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xf4);
    *reinterpret_cast<float*>(reinterpret_cast<char*>(dst) + 0xf8) =
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xf8);
}

extern "C" int __cdecl tolower(int);

// Hashes the lowercased characters of str (stopping before a trailing 3-character extension after a dot) and returns the hash modulo 713.
// @fnv 0x00a61530
unsigned int FUN_00a61530(const char* str)
{
    unsigned int hash = 0;
    while (*str)
    {
        int c = tolower(*str);
        ++str;
        if (c == '.' && !str[3])
            break;
        hash = hash * 33u + c;
    }
    return hash % 713u;
}

struct NiCullingProperty
{
    void FUN_00a5d7a0(void*, CloningProcess&);
};
struct FUN_00a755f0_Class : NiCullingProperty
{
    void __thiscall CopyCullingData(void* dst, CloningProcess& proc);
};
// @fnv 0x00a755f0
void __thiscall FUN_00a755f0_Class::CopyCullingData(void* dst, CloningProcess& proc)
{
    FUN_00a5d7a0(dst, proc);
    char* a = (char*)this;
    char* b = (char*)dst;
    *(int*)(b + 0x1c) = *(int*)(a + 0x1c);
    *(int*)(b + 0x20) = *(int*)(a + 0x20);
    *(int*)(b + 0x24) = *(int*)(a + 0x24);
    *(int*)(b + 0x28) = *(int*)(a + 0x28);
    *(int*)(b + 0x2c) = *(int*)(a + 0x2c);
    *(int*)(b + 0x30) = *(int*)(a + 0x30);
    *(int*)(b + 0x34) = *(int*)(a + 0x34);
    *(float*)(b + 0x38) = *(float*)(a + 0x38);
    *(float*)(b + 0x3c) = *(float*)(a + 0x3c);
    *(float*)(b + 0x40) = *(float*)(a + 0x40);
}

struct FUN_00a72590_Class
{
    int FUN_00a72590(unsigned int index, int* out);
};

// @fnv 0x00a72590
int FUN_00a72590_Class::FUN_00a72590(unsigned int index, int* out)
{
    *out = 0;
    unsigned short count = *(unsigned short*)((char*)this + 0x26);
    if (index >= count)
        return 0;
    int* array = *(int**)((char*)this + 0x20);
    int obj = array[index];
    if (!obj)
        return 0;
    *out = *(int*)(obj + 4);
    int* vtable = *(int**)obj;
    void(__thiscall * fn)(void*, int, int) = *(void(__thiscall**)(void*, int, int))(vtable + 2);
    fn((void*)obj, 0, 0);
    return *(int*)(obj + 8);
}

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
};

struct FUN_00a7d6e0_Class
{
    void __thiscall FUN_00a71f60();
};

// @fnv 0x00a7d6e0
void* FUN_00a7d6e0()
{
    FUN_00a7d6e0_Class* obj = (FUN_00a7d6e0_Class*)A51BF0Base::operator new(0xfc);
    if (obj)
    {
        obj->FUN_00a71f60();
        *(float*)((char*)obj + 0xf0) = 0.0f;
        *(void**)obj = (void*)&DAT_0109dd0c;
        *(float*)((char*)obj + 0xf4) = 1.0f;
        *(unsigned char*)((char*)obj + 0x9d) = 2;
        *(float*)((char*)obj + 0xf8) = 0.0f;
        return obj;
    }
    return 0;
}

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

// @fnv 0x00a63850
void FUN_00a63850_Class::DestroyMap()
{
    char* self = reinterpret_cast<char*>(this);
    *reinterpret_cast<int*>(self) = (int)&DAT_0109bcc4;
    if (self[0x10])
    {
        unsigned int i = 0;
        if (*reinterpret_cast<unsigned int*>(self + 4) > 0)
        {
            do
            {
                char* node = *reinterpret_cast<char**>(*reinterpret_cast<char**>(self + 8) + i * 4);
                while (node)
                {
                    char* cur = node;
                    node = *reinterpret_cast<char**>(cur);
                    _NiFree(*reinterpret_cast<void**>(cur + 4));
                }
                ++i;
            } while (i < *reinterpret_cast<unsigned int*>(self + 4));
        }
    }
    *reinterpret_cast<int*>(self) = (int)&DAT_0109bca4;
    reinterpret_cast<NiTMapBaseStub*>(this)->RemoveAll();
    *reinterpret_cast<int*>(self) = (int)&DAT_0109bc84;
    reinterpret_cast<NiTMapBaseStub*>(this)->RemoveAll();
    _NiFree(*reinterpret_cast<void**>(self + 8));
}

namespace fnv_00a63a20 {
struct NiTMapBaseStub
{
    void* vtable;
    void* data;
    void __thiscall RemoveAll();
};

extern int DAT_0109bc84;
extern int DAT_0109bca4;
extern MemoryManager _g_memoryManager;
void _NiFree(void*);

struct FUN_00a63a20_Class : NiTMapBaseStub
{
    void* ptr;

    void* __thiscall FUN_00a63a20(int flags);
};

// @fnv 0x00a63a20
void* __thiscall FUN_00a63a20_Class::FUN_00a63a20(int flags)
{
    vtable = &DAT_0109bca4;
    RemoveAll();

    vtable = &DAT_0109bc84;
    RemoveAll();

    _NiFree(ptr);

    if (flags & 1)
        _g_memoryManager.Deallocate(this);

    return this;
}
}  // namespace fnv_00a63a20

namespace fnv_00a63a60 {
struct NiTMapBaseStub
{
    void __thiscall RemoveAll();
    void* __thiscall FUN_00a63a60(unsigned char);
};

extern int DAT_0109bcec;
extern MemoryManager _g_memoryManager;
void __cdecl _NiFree(void*);

// @fnv 0x00a63a60
void* __thiscall NiTMapBaseStub::FUN_00a63a60(unsigned char flag)
{
    *reinterpret_cast<void**>(this) = reinterpret_cast<void*>(&DAT_0109bcec);
    RemoveAll();
    _NiFree(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 8));
    if (flag & 1)
        _g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00a63a60

namespace fnv_00a63aa0 {
struct NiTMapBaseStub
{
    void* vptr;
    int padding;
    void* data;
    void __thiscall RemoveAll();
};

extern int DAT_0109bcec;
extern int DAT_0109bd0c;
void _NiFree(void*);

struct FUN_00a63aa0_Class : NiTMapBaseStub
{
    void* __thiscall FUN_00a63aa0(int flags);
};

// @fnv 0x00a63aa0
void* __thiscall FUN_00a63aa0_Class::FUN_00a63aa0(int flags)
{
    this->vptr = &DAT_0109bd0c;
    this->RemoveAll();
    this->vptr = &DAT_0109bcec;
    this->RemoveAll();

    _NiFree(this->data);

    if (flags & 1)
    {
        g_memoryManager.Deallocate(this);
    }

    return this;
}
}  // namespace fnv_00a63aa0

namespace fnv_00a63b60 {
struct NiTMapBaseStub
{
    void* vftable;
    void* reserved;
    void __thiscall RemoveAll();
};

struct FUN_00a63b60_Class : NiTMapBaseStub
{
    void* pData;

    void* __thiscall FUN_00a63b60(unsigned char flags);
};

void __cdecl NiFree(void* p);
extern int DAT_0109bc64;

// Resets the vftable, removes all entries, frees pData, and deallocates this when flags has bit 0 set.
// @fnv 0x00a63b60
void* __thiscall FUN_00a63b60_Class::FUN_00a63b60(unsigned char flags)
{
    vftable = &DAT_0109bc64;
    NiTMapBaseStub::RemoveAll();

    NiFree(pData);

    if (flags & 1)
        g_memoryManager.Deallocate(this);

    return this;
}
}  // namespace fnv_00a63b60

namespace fnv_00a63ba0 {
struct NiTMapBaseStub
{
    void __thiscall RemoveAll();
};

struct FUN_00a63ba0_Class : public NiTMapBaseStub
{
    void* vtable;
    unsigned int padding;
    void* buffer;

    void* __thiscall FUN_00a63ba0(unsigned char flags);
};

extern char DAT_0109bd54;
extern char DAT_0109bc64;
void __cdecl _NiFree(void*);

// @fnv 0x00a63ba0
void* __thiscall FUN_00a63ba0_Class::FUN_00a63ba0(unsigned char flags)
{
    vtable = &DAT_0109bd54;
    RemoveAll();

    vtable = &DAT_0109bc64;
    RemoveAll();

    _NiFree(buffer);

    if (flags & 1)
        g_memoryManager.Deallocate(this);

    return this;
}
}  // namespace fnv_00a63ba0

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

// Computes the normal as the cross product of the two edge vectors and sets distance to the dot product of the normal with point0.
// @fnv 0x00a699d0
FUN_00a699d0_Class* __thiscall FUN_00a699d0_Class::FUN_00a699d0(NiPoint3 const* point0, NiPoint3 const* point1,
                                                                NiPoint3 const* point2)
{
    NiPoint3 edge1;
    edge1.x = point1->x - point0->x;
    edge1.y = point1->y - point0->y;
    edge1.z = point1->z - point0->z;

    NiPoint3 edge2;
    edge2.x = point2->x - point1->x;
    edge2.y = point2->y - point1->y;
    edge2.z = point2->z - point1->z;

    normal = edge1.CrossProduct(edge2);

    distance = normal.x * point0->x + normal.y * point0->y + normal.z * point0->z;

    return this;
}

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

// Sets the vtable, clears the map, frees m_pData, and optionally deallocates this object.
// @fnv 0x00a6ea00
void* FUN_00a6ea00_Class::FUN_00a6ea00(unsigned char flag)
{
    *reinterpret_cast<int**>(this) = &DAT_0109ca08;
    RemoveAll();
    _NiFree(m_pData);
    if (flag & 1)
        _g_memoryManager.Deallocate(this);
    return this;
}

struct NiTriStrips
{
    NiTriStrips();
};

extern int DAT_0109cd44;

// Allocates 0xc4 bytes, constructs a NiTriStrips in place, sets its vtable to DAT_0109cd44, and returns the pointer or 0 on failure.
// @fnv 0x00a71ce0
void* CreateNiTriStrips()
{
    NiTriStrips* p = (NiTriStrips*)A51BF0Base::operator new(0xc4);
    if (p)
    {
        p->NiTriStrips::NiTriStrips();
        *(int*)p = (int)&DAT_0109cd44;
        return p;
    }
    return 0;
}

struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void SetSize(unsigned int);
};
struct FUN_00a72ca0_Class
{
    void FUN_00a72ca0(unsigned int size);
};
// @fnv 0x00a72ca0
void FUN_00a72ca0_Class::FUN_00a72ca0(unsigned int size)
{
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x1c))->SetSize(size);
}

struct FUN_00a7f810
{
    int m_p;
    FUN_00a7f810();
};

// @fnv 0x00a7f810
FUN_00a7f810::FUN_00a7f810()
{
    m_p = (int)&DAT_0109df2c;
    DAT_011f4ab4 = (int)this;
}

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
// Looks up a key in the hash map, unlinks and deallocates its node, clears the value's key, and returns the removed value or null.
// @fnv 0x00a61670
HashValue_00a61670* FUN_00a61670_Map::RemoveByKey(unsigned int key)
{
    unsigned int index = (key >> 4) % 1001;
    HashValue_00a61670* result = 0;
    HashNode_00a61670* current = buckets[index];
    HashNode_00a61670* previous = 0;
    if (current != 0)
    {
        do
        {
            if (current->value->key == key)
            {
                if (previous != 0)
                    previous->next = current->next;
                else
                    buckets[index] = current->next;
                HashValue_00a61670* value = current->value;
                --count;
                g_memoryManager.Deallocate(current);
                value->key = 0;
                result = value;
                break;
            }
            previous = current;
            current = current->next;
        } while (current != 0);
    }
    return result;
}

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

// Scans the seven buckets of DAT_011f4464 from the last to the first and returns whether GetFirst found an entry, filling it.
// @fnv 0x00a616e0
bool __cdecl FUN_00a616e0(A616E0Iter* it)
{
    int i = 7;
    bool found;
    do
    {
        --i;
        found = DAT_011f4464->m_buckets[i].GetFirst(it);
    } while (!found && i);
    return found;
}

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

// Returns a level 0-4 based on the larger of the texture's width and height, using thresholds 0x80, 0x100, 0x200 and 0x400.
// @fnv 0x00a61750
unsigned int GetTextureSizeLevel(A61750Texture* pkTexture)
{
    unsigned int uiTreeBlockIndex = 0;
    unsigned int uiWidth = pkTexture->GetWidth();
    unsigned int uiHeight = pkTexture->GetHeight();
    unsigned int uiSize = uiHeight > uiWidth ? uiHeight : uiWidth;
    if (uiSize >= 0x400)
        uiTreeBlockIndex = 4;
    else if (uiSize >= 0x200)
        uiTreeBlockIndex = 3;
    else if (uiSize >= 0x100)
        uiTreeBlockIndex = 2;
    else if (uiSize >= 0x80)
        uiTreeBlockIndex = 1;
    return uiTreeBlockIndex;
}

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

// @fnv 0x00a61920
bool __thiscall FUN_00a61920_Class::FindShaderByHash(int iBucketIndex, int iHashKey, NiShader** ppOutShader)
{
    FUN_00a61920_Node* node = m_pBuckets[iBucketIndex];
    bool found = false;

    if (node != 0)
    {
        do
        {
            int* hash = node->m_pObject->GetHash();
            int value = static_cast<int>(node->unk0e) + *hash;

            if (FUN_00a614d0(iHashKey, value))
            {
                NiShader* pOldShader = *ppOutShader;

                if (pOldShader != node->m_pObject)
                {
                    if (pOldShader != 0)
                    {
                        if (InterlockedDecrement(&pOldShader->m_iObjectReferenceCount) == 0)
                        {
                            pOldShader->Release();
                        }
                    }

                    *ppOutShader = node->m_pObject;

                    if (*ppOutShader != 0)
                    {
                        InterlockedIncrement(&(*ppOutShader)->m_iObjectReferenceCount);
                    }
                }

                found = true;
                break;
            }

            node = node->m_pkNext;
        } while (node != 0);
    }

    return found;
}

namespace fnv_00a61ad0 {
// FUN_00a61ad0 candidate (b9725)
struct TLSCtx_b9725
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

struct TLSHeap_b9725
{
    void* __thiscall Alloc(unsigned int size);
};

extern __declspec(thread) TLSCtx_b9725 g_tlsCtx_b9725;
extern TLSHeap_b9725 DAT_011f6238;
extern void* DAT_011f4468;
extern void* DAT_011f4464;
extern unsigned char DAT_011f4461;
void* __cdecl ClearAndReset();
void* __cdecl _fnv_zlib_memset(void* p, int c, unsigned int n);
void __stdcall Init_b9725(void* p, unsigned int size, int count, void* cb);

// Allocates two blocks via the TLS heap, zeroes the first and initializes the second with Init_b9725, storing both in globals and restoring the TLS field.
// @fnv 0x00a61ad0
void FUN_00a61ad0()
{
    int iSavedTlsValue = g_tlsCtx_b9725.m_2b4;
    g_tlsCtx_b9725.m_2b4 = 0xf;
    char* obj = (char*)DAT_011f6238.Alloc(0xfa8);
    if (obj != 0)
    {
        _fnv_zlib_memset(obj, 0, 0xfa4);
        *(int*)(obj + 0xfa4) = 0;
        DAT_011f4468 = obj;
    }
    else
    {
        DAT_011f4468 = 0;
    }
    char* p = (char*)DAT_011f6238.Alloc(0x4e1c);
    if (p != 0)
    {
        *(int*)p = 7;
        Init_b9725(p + 4, 0xb28, 7, (void*)ClearAndReset);
        DAT_011f4464 = p + 4;
        g_tlsCtx_b9725.m_2b4 = iSavedTlsValue;
        DAT_011f4461 = 0;
        return;
    }
    g_tlsCtx_b9725.m_2b4 = iSavedTlsValue;
    DAT_011f4464 = 0;
    DAT_011f4461 = 0;
}
}  // namespace fnv_00a61ad0

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

// Walks each of the 0x2c9 slot lists, releases each node's refcounted object and frees the node, then clears the slots and m_unkB24.
// @fnv 0x00a61ec0
void FUN_00a61ec0_cls::ClearAllSlots()
{
    for (unsigned int i = 0; i < 0x2c9; ++i)
    {
        PoolNode* node = m_slots[i];
        while (node != 0)
        {
            PoolNode* cur = node;
            node = cur->m_next;
            RefCountedNodeObject* obj = cur->m_obj;
            if (obj != 0)
            {
                if (InterlockedDecrement(&obj->m_iObjectReferenceCount) == 0)
                {
                    obj->vSlot1();
                }
            }
            DAT_011f6238.Free(cur);
        }
        m_slots[i] = 0;
    }
    m_unkB24 = 0;
}

namespace fnv_00a62090 {
extern MemoryManager g_memoryManager;

struct ShaderState
{
    void __thiscall ClearAllBuckets();
    ~ShaderState()
    {
        ClearAllBuckets();
    }
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
struct ShaderEntry
{
    void __thiscall ClearAllSlots();
};
extern ShaderState* DAT_011f4468;
extern unsigned char* DAT_011f4464;
void __cdecl FUN_00a62030();

// Calls FUN_00a62030, deletes DAT_011f4468, destroys each ShaderEntry in the DAT_011f4464 array, frees it, and nulls both globals.
// @fnv 0x00a62090
void __cdecl FUN_00a62090()
{
    FUN_00a62030();

    delete DAT_011f4468;

    unsigned char* entries = DAT_011f4464;
    DAT_011f4468 = 0;
    if (entries != 0)
    {
        int count = *reinterpret_cast<int*>(entries - 4);
        unsigned char* current = entries + count * 2856;
        int* allocation = reinterpret_cast<int*>(entries - 4);
        if (--count >= 0)
        {
            do
            {
                current -= 2856;
                reinterpret_cast<ShaderEntry*>(current)->ClearAllSlots();
            } while (--count >= 0);
        }
        g_memoryManager.Deallocate(allocation);
    }
    DAT_011f4464 = 0;
}
}  // namespace fnv_00a62090

struct Vector4f
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
};
// For each of count 4-byte elements, swaps the first and last bytes and swaps the two middle bytes in place.
// @fnv 0x00a62150
void __cdecl SwapByteQuadWords(Vector4f* pQuads, unsigned int count)
{
    unsigned char* p = (unsigned char*)pQuads;
    if (count <= 0)
        return;
    do
    {
        unsigned int t = pQuads->b3;
        unsigned char c = pQuads->b0;
        pQuads->b0 = (unsigned char)t;
        p[3] = c;
        t = pQuads->b2;
        c = pQuads->b1;
        pQuads->b1 = (unsigned char)t;
        pQuads->b2 = c;
        pQuads++;
        p += 4;
    } while (--count);
}

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

// @fnv 0x00a62190
unsigned int A62190PixelFormat::GetComponentMask(int eComponent) const
{
    unsigned int uiShift = 0;
    for (unsigned int i = 0; i < 4; i++)
    {
        if (m_akComponents[i].m_eComponent == eComponent)
        {
            unsigned char ucBPC = m_akComponents[i].m_ucBPC;
            unsigned int uiMask = 0;
            unsigned char ucBit = ucBPC - 1;
            if (!ucBPC)
                return 0;
            while (ucBit)
            {
                uiMask += 1 << ucBit;
                ucBit--;
            }
            uiMask = (uiMask + 1) << uiShift;
            if (m_ucFlags & 1)
                return uiMask;
            unsigned char* pucBytes = (unsigned char*)&uiMask;
            for (int iByte = 0; iByte < 2; iByte++)
            {
                unsigned char ucTemp = pucBytes[iByte];
                pucBytes[iByte] = pucBytes[3 - iByte];
                pucBytes[3 - iByte] = ucTemp;
            }
            return uiMask >> (32 - m_ucBitsPerPixel);
        }
        uiShift += m_akComponents[i].m_ucBPC;
    }
    return 0;
}

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

// Iterates g_pendingTable, decrements each object's reference count and calls its virtual slot 1 when the count reaches zero, then clears the entry.
// @fnv 0x00a62280
void ReleasePendingTable()
{
    FNV_INTERLOCKED_DECREMENT pDecrement = &InterlockedDecrement;
    for (unsigned int offset = 0; offset < 40; offset += 4)
    {
        SlotObject* pObject = *(SlotObject**)((char*)g_pendingTable + offset);
        if (pObject)
        {
            if (pDecrement((volatile long*)&pObject->m_iObjectReferenceCount) == 0)
                pObject->SlotVirtual1();
            *(SlotObject**)((char*)g_pendingTable + offset) = 0;
        }
    }
}

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

// Copies kSettings into g_kSettings_11f4600 and clears all 10 entries of g_aspObjects_11f4514.
// @fnv 0x00a622d0
void __cdecl ApplySettings(const Settings_a62& kSettings)
{
    g_kSettings_11f4600 = kSettings;
    for (unsigned int i = 0; i < 10; i++)
        g_aspObjects_11f4514[i] = 0;
}

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

// Resets m_baseData0, clears the map, frees m_baseData2, and optionally deallocates this object.
// @fnv 0x00a639e0
FUN_00a639e0_Class* __thiscall FUN_00a639e0_Class::FUN_00a639e0(char abFreeMemory)
{
    m_baseData0 = &DAT_0109bc84;
    ((NiTMapBaseStub*)this)->RemoveAll();
    NiFreeAlias(m_baseData2);
    if (abFreeMemory & 1)
        _g_memoryManager.Deallocate(this);
    return this;
}

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

// @fnv 0x00a66960
int FUN_00a66960_cls::FUN_00a66960(int a1)
{
    return m_2C;
}

// File-static comparison with a compiler-chosen register convention.
// @fnv 0x00a66970
static __declspec(noinline) int CompareFloatArrays(const float* pfA, const float* pfB, unsigned int auiCount)
{
    for (unsigned int i = 0; i < auiCount; i++)
    {
        if (pfA[i] < pfB[i])
            return -1;
        if (pfA[i] > pfB[i])
            return 1;
    }
    return 0;
}

struct A66970Keys
{
    unsigned int m_uiCount;
    const float* m_pfA;
    const float* m_pfB;
};

int A66970Compare(const A66970Keys* pkKeys)
{
    return CompareFloatArrays(pkKeys->m_pfA, pkKeys->m_pfB, pkKeys->m_uiCount);
}

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

// If m_3a is set, optionally queries m_30 via FUN_00a72720 and writes the resulting a, b and 0 into out.
// @fnv 0x00a674b0
void FUN_00a674b0_cls::GetOutRec(OutRec674* out)
{
    if (m_3a != 0)
    {
        int b = 0;
        int c = 0;
        int a = 0;
        int e;
        int f;
        Obj_a674* obj = m_30;
        if (obj != 0 && obj->v35() && (obj->m_2c & 1) != 0)
        {
            int d = 0;
            obj->FUN_00a72720(1, &a, &f, &c, &e, &d, &b);
        }
        out->a = a;
        out->b = b;
        out->c = 0;
    }
}

extern int DAT_0109c28c;

struct FUN_00a693e0_cls
{
    int m_vptr00;

    void FUN_00a693e0();
};

// @fnv 0x00a693e0
void FUN_00a693e0_cls::FUN_00a693e0()
{
    m_vptr00 = (int)&DAT_0109c28c;
}

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
// Constructor initializing origin bits from globals, unit extents, 0.5 scales, enabled=1 and mode=2.
// @fnv 0x00a69b00
FUN_00a69b00::FUN_00a69b00()
    : originXBits(DAT_011f4980), originYBits(DAT_011f4984), originZ(0.f), extentX(1.f), extentY(1.f), scaleX(0.5f),
      scaleY(0.5f), enabled(1), mode(2)
{}

struct FUN_00a69b40_Class
{
    void __thiscall FUN_00a69b40(int param_2);
};

// Sets or clears bit 0 of the flags at offset 0x18 depending on whether param_2 is nonzero or any entry after the first in the array at 0x20 is nonzero.
// @fnv 0x00a69b40
void FUN_00a69b40_Class::FUN_00a69b40(int param_2)
{
    bool found = param_2 != 0;
    if (!found)
    {
        unsigned int count = *(unsigned short*)((char*)this + 0x26);
        unsigned int index = 1;
        if (index < count)
        {
            int* value = *(int**)((char*)this + 0x20) + 1;
            do
            {
                if (*value != 0)
                {
                    found = true;
                    break;
                }
                ++value;
                ++index;
            } while (index < count);
        }
    }

    if (found)
    {
        *(unsigned short*)((char*)this + 0x18) |= 1;
    }
    else
    {
        *(unsigned short*)((char*)this + 0x18) &= 0xfffe;
    }
}

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

// Releases the global ref-counted object and clears ten global fixed strings via ReleaseString.
// @fnv 0x00a6a6f0
void ReleaseGlobalStrings()
{
    if (DAT_011f49ac)
    {
        DAT_011f49ac->DecRefCount();
        DAT_011f49ac = 0;
    }
    ReleaseString(DAT_011f49b0);
    ReleaseString(DAT_011f49b4);
    ReleaseString(DAT_011f49b8);
    ReleaseString(DAT_011f49bc);
    ReleaseString(DAT_011f49c0);
    ReleaseString(DAT_011f49c4);
    ReleaseString(DAT_011f49c8);
    ReleaseString(DAT_011f49cc);
    ReleaseString(DAT_011f49d0);
    ReleaseString(DAT_011f49d4);
}

struct FUN_00a6db50_V
{
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    FUN_00a6db50_V* __thiscall Set(float a, float b, float c, float d);
};

// Stores the four float arguments into m_00, m_04, m_08 and m_0c and returns this.
// @fnv 0x00a6db50
FUN_00a6db50_V* __thiscall FUN_00a6db50_V::Set(float a, float b, float c, float d)
{
    m_00 = a;
    m_04 = b;
    m_08 = c;
    m_0c = d;
    return this;
}

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

// operator+
// Returns a new color whose components are this color's components plus the corresponding components of the given color.
// @fnv 0x00a6db70
A6DB70ColorA A6DB70ColorA::FUN_00a6db70(const A6DB70ColorA& kColor) const
{
    return A6DB70ColorA(r + kColor.r, g + kColor.g, b + kColor.b, a + kColor.a);
}

struct FUN_00a6dbd0_cls
{
    float m_f0;
    float m_f1;
    float m_f2;
    float m_f3;

    void Negate(float* __restrict out);
};
// Writes the negation of each of the four float members into the output array.
// @fnv 0x00a6dbd0
void FUN_00a6dbd0_cls::Negate(float* __restrict out)
{
    out[0] = -m_f0;
    out[1] = -m_f1;
    out[2] = -m_f2;
    out[3] = -m_f3;
}

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

// Stores six float arguments and a flag byte into the object's fields and returns the object.
// @fnv 0x00a71b80
FUN_00a71b80_cls* FUN_00a71b80_cls::Init(float a1, float a2, float a3, float a4, float a5, float a6, unsigned char flag)
{
    FUN_00a71b80_cls* p = this;
    p->m_00 = a1;
    p->m_18 = flag;
    p->m_04 = a2;
    p->m_08 = a3;
    p->m_0c = a4;
    p->m_10 = a5;
    p->m_14 = a6;
    return p;
}

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

// @fnv 0x00a71c40
FUN_00a71c40_cls* FUN_00a71c40_cls::ConstructWithAlloc(unsigned int a1, unsigned int a2, unsigned int a3,
                                                       unsigned int a4, unsigned int a5, unsigned int a6,
                                                       unsigned int a7, unsigned int a8, unsigned int a9,
                                                       unsigned int a10, unsigned int a11)
{
    void* obj;
    void* mem = FUN_00aa13e0(0x50);
    if (mem != 0)
    {
        obj = ((FUN_00a75dc0_cls*)mem)->FUN_00a75dc0(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    }
    else
    {
        obj = 0;
    }
    this->FUN_00a89720(obj);
    this->m_vt = &DAT_0109cd44;
    return this;
}

// FUN_00a71cc0 : constructor-like helper that calls a base routine with the
// argument and then installs the class vtable pointer, returning itself.

extern int DAT_0109cd44;

struct FUN_00a71cc0_cls
{
    void* m_pVTable;
    void FUN_00a89720(int arg);
    FUN_00a71cc0_cls* FUN_00a71cc0(int arg);
};

// @fnv 0x00a71cc0
FUN_00a71cc0_cls* FUN_00a71cc0_cls::FUN_00a71cc0(int arg)
{
    FUN_00a89720(arg);
    m_pVTable = (void*)&DAT_0109cd44;
    return this;
}

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

// Clears out, bounds-checks index against unk26, and if unk20[index] exists writes its unk04 to out and returns its unk08.
// @fnv 0x00a72550
int FUN_00a72550_Class::GetItemData(unsigned int index, int* out)
{
    *out = 0;
    if (index >= unk26)
        return 0;

    Item* item = unk20[index];
    if (!item)
        return 0;

    *out = item->unk04;
    return item->unk08;
}

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

// @fnv 0x00a72600
bool __thiscall ObjectRegistry::RemoveObject(unsigned int index, bool clearReferences)
{
    SceneEntry* object = index < indexedObjects.count ? indexedObjects.entries[index] : 0;
    if (!object)
        return false;

    object->Prepare(0);
    object->Detach(1);

    unsigned int removed = 0;
    indexedObjects.FUN_00ba3aa0(index, &removed);

    if (clearReferences)
    {
        for (unsigned int i = 0; i < recordCount; ++i)
        {
            LinkedRecord* record = &records[i];
            if (index == record->objectIndex && i < recordCount && records)
            {
                record->object = 0;
                record->parent = 0;
                record->metadata = 0;
                record->child = 0;
                record->objectIndex = 0;
                record->cachedValue = 0;
            }
        }
    }
    return true;
}

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

// Validates format, index, count and entry pointer, then fills the entry at uiIndex with the data pointer, count, start, stride and size.
// @fnv 0x00a726a0
bool FUN_00a726a0_cls::FUN_00a726a0(unsigned int uiIndex, unsigned int ItemUpdateArray, unsigned int uiStart, void* pvData,
                                    unsigned short usFormat, unsigned int uiStride, unsigned int uiElapsedMilliseconds)
{
    if (usFormat != m_usFormat)
        return false;
    if (uiIndex >= m_uiStreamIndex || !m_pkEntryArray)
        return false;
    if (ItemUpdateArray > m_usMaxCount)
        return false;

    BA726A0Entry& kEntry = m_pkEntryArray[uiIndex];
    kEntry.m_pResource = pvData;
    kEntry.m_uiCount = ItemUpdateArray;
    kEntry.m_uiValueBeforeCount = uiElapsedMilliseconds;
    kEntry.m_uiElapsedTime = uiStart;
    kEntry.m_uiStride = uiStride;
    kEntry.m_uiSize = usFormat * uiStride;
    return true;
}

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

// Writes red, green, blue, alpha, threshold and blendMode as 4-byte values, then format as 1 byte, to the stream's writer.
// @fnv 0x00a72cb0
void ColorState::FUN_00a72cb0(BinaryStream* stream)
{
    ObjectWriter* __restrict writer = stream->Writer();
    {
        unsigned int elementWidth = 4;
        writer->bytesWritten += writer->write(writer, &red, 4, &elementWidth, 1);

        writer = stream->Writer();
        elementWidth = 4;
        writer->bytesWritten += writer->write(writer, &green, 4, &elementWidth, 1);

        writer = stream->Writer();
        elementWidth = 4;
        writer->bytesWritten += writer->write(writer, &blue, 4, &elementWidth, 1);

        writer = stream->Writer();
        elementWidth = 4;
        writer->bytesWritten += writer->write(writer, &alpha, 4, &elementWidth, 1);

        writer = stream->Writer();
        elementWidth = 4;
        writer->bytesWritten += writer->write(writer, &threshold, 4, &elementWidth, 1);

        writer = stream->Writer();
        elementWidth = 4;
        writer->bytesWritten += writer->write(writer, &blendMode, 4, &elementWidth, 1);

        writer = stream->Writer();
        elementWidth = 1;
        writer->bytesWritten += writer->write(writer, this, 1, &elementWidth, 1);
    }
}

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

// Writes m_iValue0 through m_iValue5 and m_bFlag to kStream via BA72DB0SaveBinary.
// @fnv 0x00a72db0
void BA72DB0Data::FUN_00a72db0(BA72DB0Stream& kStream)
{
    BA72DB0SaveBinary(kStream, m_iValue0);
    BA72DB0SaveBinary(kStream, m_iValue1);
    BA72DB0SaveBinary(kStream, m_iValue2);
    BA72DB0SaveBinary(kStream, m_iValue3);
    BA72DB0SaveBinary(kStream, m_iValue4);
    BA72DB0SaveBinary(kStream, m_iValue5);
    BA72DB0SaveBinary(kStream, m_bFlag);
}

extern int DAT_0109d55c;

struct SceneFactoryObject
{
    void* m_vtbl;
    void Initialize();
};

// Allocates a 196-byte SceneFactoryObject, initializes it, sets its vtable to DAT_0109d55c, and returns it (or null on allocation failure).
// @fnv 0x00a74750
SceneFactoryObject* CreateSceneFactoryObject()
{
    SceneFactoryObject* object = static_cast<SceneFactoryObject*>(BSFadeNode::operator new(196));
    if (object)
    {
        object->Initialize();
        object->m_vtbl = &DAT_0109d55c;
        return object;
    }
    return 0;
}

extern int DAT_011aa04c;

// @fnv 0x00a74d80
void __cdecl FUN_00a74d80(int param_1)
{
    DAT_011aa04c = param_1;
}

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

// @fnv 0x00a74d90
void __cdecl FUN_00a74d90(void* callback)
{
    DAT_011aa050 = callback;
}

struct CallTarget_00a74e10
{
    int SetFromFrustum(int, int);
};
struct SearchObject
{
    int FUN_00a755d0(unsigned int arg0);
};
// @fnv 0x00a755d0
int SearchObject::FUN_00a755d0(unsigned int arg0)
{
    unsigned int callResult0 =
        (unsigned int)((CallTarget_00a74e10*)this)->SetFromFrustum((int)(arg0 + 220u), (int)(104u + arg0));
    return (int)callResult0;
}

extern int DAT_00ff0000;

struct FUN_00a77110_info
{
    unsigned int m_eVertexFormat;
    unsigned int m_flags;
};

// @fnv 0x00a77110
void __cdecl FUN_00a77110(unsigned int width, unsigned int rows, unsigned int unk0c, unsigned char* dst,
                          unsigned int unk14, FUN_00a77110_info* info, const unsigned char* src)
{
    if (info->m_flags != 0xff00)
        return;
    unsigned int key = info->m_eVertexFormat;
    if (key == (unsigned int)&DAT_00ff0000)
    {
        if (rows <= 0)
            return;
        unsigned int r = rows;
        do
        {
            if (width > 0)
            {
                unsigned int w = width;
                do
                {
                    dst[0] = src[2];
                    dst++;
                    dst[0] = src[1];
                    dst++;
                    dst[0] = src[0];
                    dst++;
                    src += 4;
                    w--;
                } while (w != 0);
            }
            r--;
        } while (r != 0);
    }
    else if (key == 0xff)
    {
        if (rows <= 0)
            return;
        unsigned int r = rows;
        do
        {
            if (width > 0)
            {
                unsigned int w = width;
                do
                {
                    *dst = src[0];
                    dst++;
                    src++;
                    *dst = src[0];
                    dst++;
                    src++;
                    *dst = src[0];
                    dst++;
                    src += 2;
                    w--;
                } while (w != 0);
            }
            r--;
        } while (r != 0);
    }
}

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

// For each of countB rows and countA pixels, reads a 16-bit source value and writes three bytes extracted with the layout's masks and shifts.
// @fnv 0x00a772b0
void UnpackPixels(unsigned int countA, unsigned int uiRowCount, unsigned int uiUnused0C, unsigned char* dst,
                  unsigned int uiUnused14, unsigned int uiUnused18, unsigned int srcAddr, const BitPackLayout* layout)
{
    const unsigned short* src = (const unsigned short*)srcAddr;
    for (srcAddr = 0; srcAddr < uiRowCount; srcAddr++)
    {
        for (unsigned int x = 0; x < countA; x++)
        {
            *dst++ = (unsigned char)(((*src & layout->mask0) >> layout->rshift0) << layout->lshift0);
            *dst++ = (unsigned char)(((*src & layout->mask1) >> layout->rshift1) << layout->lshift1);
            *dst++ = (unsigned char)(((*src++ & layout->mask2) >> layout->rshift2) << layout->lshift2);
        }
    }
}

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

// Converts count pixels per row from src into 4 bytes each in dest using fmt masks and shifts, for rows rows.
// @fnv 0x00a77330
void ConvertPixelsToBytes(unsigned int count, unsigned int rows, unsigned int auiUnused, char* dest,
                          unsigned int auiUnused2, void* apUnused, unsigned short* src, FnvPixelFormat* fmt)
{
    unsigned short* s = src;
    if (rows <= 0)
        return;
    for (unsigned char* p = (unsigned char*)rows; p != 0; --p)
    {
        if (count > 0)
        {
            for (unsigned int col = count; col > 0; --col)
            {
                *dest++ = (unsigned char)((*s & fmt->mask[0]) >> fmt->shiftRight[0]) << fmt->shiftLeft[0];
                *dest++ = (unsigned char)((*s & fmt->mask[1]) >> fmt->shiftRight[1]) << fmt->shiftLeft[1];
                *dest++ = (unsigned char)((*s & fmt->mask[2]) >> fmt->shiftRight[2]) << fmt->shiftLeft[2];
                *dest++ = (unsigned char)((*s & fmt->mask[3]) >> fmt->shiftRight[3]) << fmt->shiftLeft[3];
                s++;
            }
        }
    }
}

namespace fnv_00a77460 {
extern "C" unsigned char DAT_00ff0000;
// Converts a width-by-height RGB source image to RGBA in dst, writing 0xFF alpha and swapping channels when mask[0] matches DAT_00ff0000.
// @fnv 0x00a77460
void __cdecl ConvertRgbToRgba(unsigned int width, unsigned int height, int, unsigned char* dst, int, int,
                              const unsigned char* src, const unsigned int* mask)
{
    if (mask[1] == 0xFF00)
    {
        if (mask[0] == (unsigned int)&DAT_00ff0000)
        {
            if (height > 0)
            {
                unsigned int rows = height;
                do
                {
                    if (width > 0)
                    {
                        unsigned int cols = width;
                        do
                        {
                            *dst++ = src[2];
                            *dst++ = src[1];
                            *dst++ = src[0];
                            *dst++ = 0xFF;
                            src += 3;
                        } while (--cols != 0);
                    }
                } while (--rows != 0);
            }
        }
        else
        {
            if (height > 0)
            {
                unsigned int rows = height;
                do
                {
                    if (width > 0)
                    {
                        unsigned int cols = width;
                        do
                        {
                            *dst++ = *src++;
                            *dst++ = *src++;
                            *dst++ = *src++;
                            *dst++ = 0xFF;
                        } while (--cols != 0);
                    }
                } while (--rows != 0);
            }
        }
    }
}
}  // namespace fnv_00a77460

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

// @fnv 0x00a77740
void ConvertRgbToPacked16(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiUnused, unsigned char* pucDest,
                          unsigned int uiUnused2, const A77740Format* pkFmt, const unsigned char* pucSrc)
{
    unsigned short* pusDest = (unsigned short*)pucDest;
    for (unsigned int y = 0; y < uiHeight; y++)
    {
        for (unsigned int x = 0; x < uiWidth; x++)
        {
            unsigned char r = *pucSrc;
            unsigned char g = *++pucSrc;
            unsigned char b = *++pucSrc;
            pucSrc += 2;
            *pusDest++ = ((unsigned short)(r >> pkFmt->m_ucRightShift0) << pkFmt->m_ucLeftShift0 & pkFmt->m_uiMask0) |
                         ((unsigned short)(g >> pkFmt->m_ucRightShift1) << pkFmt->m_ucLeftShift1 & pkFmt->m_uiMask1) |
                         ((unsigned short)(b >> pkFmt->m_ucRightShift3) << pkFmt->m_ucLeftShift3 & pkFmt->m_uiMask3);
        }
    }
}

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

// For each pixel, reads two bytes from src and combines shifted/masked channel bits from layout into one packed value written to dst.
// @fnv 0x00a77800
void __cdecl FUN_00a77800(unsigned int count, unsigned int rows, unsigned int auiUnused3, unsigned int* dst,
                          unsigned int auiUnused5, const S_00a77800_Layout* layout, const unsigned char* src)
{
    unsigned int* d = dst;
    for (unsigned int y = 0; y < rows; y++)
    {
        for (unsigned int x = 0; x < count; x++)
        {
            unsigned char b0 = *src++;
            unsigned char b1 = *src++;
            unsigned int r = ((b0 >> layout->shr0) << layout->shl0) & layout->mask0;
            r |= ((b1 >> layout->shr1) << layout->shl1) & layout->mask1;
            r |= ((0xffffffffu >> layout->shr2) << layout->shl2) & layout->mask2;
            *d++ = r;
        }
    }
}

// Returns true when the argument is a power of two (zero is not).
// @fnv 0x00a77920
bool FUN_00a77920(int aiValue)
{
    if (aiValue == 0)
        return false;
    return (aiValue & (aiValue - 1)) == 0;
}

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

// Writes the object's fields and its four Entry records to the given NiStream in a fixed order.
// @fnv 0x00a7d1a0
void FUN_00a7d1a0_Class::FUN_00a7d1a0(NiStream& stream)
{
    SerializeValue(stream, m_i4);
    SerializeValue(stream, m_c1);
    SerializeValue(stream, m_iC);
    SerializeValue(stream, m_i10);
    SerializeValue(stream, m_c0);
    SerializeValue(stream, m_i8);
    for (unsigned int i = 0; i < 4; i++)
    {
        SerializeValue(stream, m_entries[i].a);
        SerializeValue(stream, m_entries[i].b);
        SerializeValue(stream, m_entries[i].c);
        char d = m_entries[i].d;
        SerializeValue(stream, d);
    }
}

void* __cdecl BuildSqrtLut();

// @fnv 0x00a7e930
void FUN_00a7e930()
{
    DAT_011f4aa8 = BuildSqrtLut();
}

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

// Applies the transform's rotation, scale and translation to p, and multiplies scale by the transform's scale.
// @fnv 0x00a7fea0
void S_00a7fea0_Class::TransformPoint(const S_00a7fea0_Xf& aXf)
{
    p = aXf.scale * (aXf.rot * p) + aXf.t;
    scale = aXf.scale * scale;
}

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

// @fnv 0x00a61890
void NameTableA61::RemoveNode(NodeA61* pkNode)
{
    const char* pcName = *pkNode->m_pReferencedObject->GetName();
    unsigned int uiBucket = HashNameA61(pcName + GetPrefixLengthA61(pcName, 1));
    NodeA61* pkCurrent = m_apkBuckets[uiBucket];
    if (!pkCurrent)
        return;

    NodeA61* pkPrev = 0;
    do
    {
        if (pkCurrent == pkNode)
        {
            if (pkPrev)
                pkPrev->m_pkNext = pkCurrent->m_pkNext;
            else
                m_apkBuckets[uiBucket] = pkCurrent->m_pkNext;
            delete pkCurrent;
            m_uiCount--;
            return;
        }
        pkPrev = pkCurrent;
        pkCurrent = pkCurrent->m_pkNext;
    } while (pkCurrent);
}

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

// Advances the iterator to the next item, skipping empty buckets, and copies the current item's value into rspValue; returns whether an item remains.
// @fnv 0x00a619b0
bool A619B0Map::GetNext(A619B0Iterator& kIter, A619B0Pointer<A619B0Object>& rspValue)
{
    if (kIter.m_pkItem)
    {
        rspValue = kIter.m_pkItem->m_spValue;
        kIter.m_pkItem = kIter.m_pkItem->m_pkNext;
        if (!kIter.m_pkItem)
        {
            while (++kIter.m_uiBucket < 713)
            {
                if (m_apkBuckets[kIter.m_uiBucket])
                {
                    kIter.m_pkItem = m_apkBuckets[kIter.m_uiBucket];
                    break;
                }
            }
        }
    }
    return kIter.m_pkItem != 0;
}

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

// @fnv 0x00a62030
void __cdecl FUN_00a62030()
{
    if (DAT_011f4468 != 0)
    {
        DAT_011f4480.Lock(0);
        DAT_011f4468->ClearAllBuckets();
        for (unsigned int i = 0; i < 7; i++)
            ((MyPool*)DAT_011f4464)->m_buckets[i].ClearAllSlots();
        if (--DAT_011f4484 == 0)
            *(int*)&DAT_011f4480 = 0;
    }
}

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

// Reads one char from the stream's binary stream into pcValue via BA643B0BinaryStreamLoad.
// @fnv 0x00a643b0
void __cdecl FUN_00a643b0(BA643B0Stream& kStream, char* pcValue)
{
    BA643B0BinaryStreamLoad(*kStream.m_pUnderlyingStream, pcValue);
}

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

// @fnv 0x00a67530
void Q67530Cls::FillOutRec674(OutRec674* out)
{
    if (m_3a)
    {
        Obj_a674* p = m_30;
        Q67530Data q;
        q.b = 0;
        q.c = 0;
        q.a = 0;
        if (p && p->v35() && (p->m_2c & 1))
        {
            q.d = 0;
            ((BSFaceGenModel*)p)->FUN_00a72720(2, &q.a, &q.f, &q.c, &q.e, &q.d, &q.b);
        }
        out->a = q.a;
        out->b = q.b;
        out->c = 0;
    }
}

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

// Allocates and constructs a new NiExtraDataMapA6F and returns it as a NiObjectA6F pointer.
// @fnv 0x00a6f000
NiObjectA6F* NiExtraDataMapA6F::FUN_00a6f000()
{
    return new NiExtraDataMapA6F;
}

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

// Converts a 16-bit source image to 32-bit RGBA output, extracting each channel via the supplied masks and shifts and writing an opaque alpha byte.
// @fnv 0x00a773d0
void __cdecl FUN_00a773d0(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiDestStride,
                          unsigned char* pucDest, unsigned int uiDestSize, unsigned int uiSrcStride,
                          const unsigned short* pusSrc, const NiPixelChannelsA773* pkChannels)
{
    const unsigned short* pusPixel = pusSrc;
    for (unsigned int y = 0; y < uiHeight; y++)
    {
        for (unsigned int x = 0; x < uiWidth; x++)
        {
            *pucDest++ = (unsigned char)((*pusPixel & pkChannels->m_uiRedMask) >> pkChannels->m_ucRedShift)
                         << pkChannels->m_ucRedBits;
            *pucDest++ = (unsigned char)((*pusPixel & pkChannels->m_uiGreenMask) >> pkChannels->m_ucGreenShift)
                         << pkChannels->m_ucGreenBits;
            *pucDest++ = (unsigned char)((*pusPixel & pkChannels->m_uiBlueMask) >> pkChannels->m_ucBlueShift)
                         << pkChannels->m_ucBlueBits;
            *pucDest++ = 0xff;
            pusPixel++;
        }
    }
}

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

// Converts each source pixel to three destination bytes by masking and shifting the red, green and blue channels using the given channel masks and shifts.
// @fnv 0x00a77510
void __cdecl ConvertPixelsToRgb(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiDestStride,
                                unsigned char* pucDest, unsigned int uiDestSize, unsigned int uiSrcStride,
                                const unsigned int* puiSrc, const NiPixelChannelsA77* pkChannels)
{
    const unsigned int* puiPixel = puiSrc;
    for (unsigned int y = 0; y < uiHeight; y++)
    {
        for (unsigned int x = 0; x < uiWidth; x++)
        {
            *pucDest++ = (unsigned char)((*puiPixel & pkChannels->m_uiRedMask) >> pkChannels->m_ucRedShift)
                         << pkChannels->m_ucRedBits;
            *pucDest++ = (unsigned char)((*puiPixel & pkChannels->m_uiGreenMask) >> pkChannels->m_ucGreenShift)
                         << pkChannels->m_ucGreenBits;
            *pucDest++ = (unsigned char)((*puiPixel++ & pkChannels->m_uiBlueMask) >> pkChannels->m_ucBlueShift)
                         << pkChannels->m_ucBlueBits;
        }
    }
}

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

// @fnv 0x00a776b0
void __cdecl FUN_00a776b0(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiDestStride, unsigned int* puiDest,
                          unsigned int uiDestSize, const NiPixelChannelsA776* pkDestChannels,
                          const unsigned char* pucSrc, const NiPixelChannelsA776* pkSrcChannels)
{
    unsigned int* puiPixel = puiDest;
    for (unsigned int y = 0; y < uiHeight; y++)
    {
        for (unsigned int x = 0; x < uiWidth; x++)
        {
            unsigned char ucRed = *pucSrc++;
            unsigned char ucGreen = *pucSrc++;
            unsigned char ucAlpha = *pucSrc;
            pucSrc += 2;
            *puiPixel++ = (((ucRed >> pkDestChannels->m_ucRedBits) << pkDestChannels->m_ucRedShift) &
                           pkDestChannels->m_uiRedMask) |
                          (((ucAlpha >> pkDestChannels->m_ucAlphaBits) << pkDestChannels->m_ucAlphaShift) &
                           pkDestChannels->m_uiAlphaMask) |
                          (((ucGreen >> pkDestChannels->m_ucGreenBits) << pkDestChannels->m_ucGreenShift) &
                           pkDestChannels->m_uiGreenMask);
        }
    }
}

extern "C" int __cdecl tolower(int);

// @fnv 0x00a614d0
bool __cdecl FUN_00a614d0(const char* a, const char* b)
{
    while (*a != 0)
    {
        int c1 = tolower(*a++);
        int c2 = tolower(*b++);
        if (c1 == '.')
        {
            if (c2 != c1)
            {
                return false;
            }
            if (a[3] == 0)
            {
                break;
            }
        }
        else if (c1 != c2)
        {
            return false;
        }
    }
    return true;
}

struct A5FC10Stub
{
    A5FC10Stub* __thiscall FUN_00a5fc10();
};

void* __cdecl FUN_00aa13e0(unsigned int size);

// @fnv 0x00a60070
A5FC10Stub* __cdecl CreateA5FC10Stub()
{
    A5FC10Stub* object = (A5FC10Stub*)FUN_00aa13e0(0x48);

    if (object)
    {
        return object->FUN_00a5fc10();
    }

    return 0;
}

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

// @fnv 0x00a60100
void This::DispatchIfStateFour()
{
    T* p = m24;
    if (p)
    {
        unsigned int iState = p ? p->m5b : 0;
        if (iState == 4)
            p->v36(this);
    }
}

struct FUN_00a5fca0_cls
{
    void FUN_00a5fca0();
};
struct FUN_00a60160_cls : FUN_00a5fca0_cls
{
    void* DestroyIfFlagged(unsigned int flags);
};
extern "C" void __cdecl _delete(void* p, unsigned int size);
// Calls FUN_00a5fca0, then if bit 0 of flags is set frees this with size 0x48, and returns this.
// @fnv 0x00a60160
void* FUN_00a60160_cls::DestroyIfFlagged(unsigned int flags)
{
    FUN_00a5fca0();
    if (flags & 1)
        _delete(this, 0x48);
    return this;
}

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

// @fnv 0x00a60600
void ControllerA606::FUN_00a60600(NiStream& kStream)
{
    FUN_00a5d7b0(kStream);
    bool bNoTargets = !m_pkTarget1 && !m_pkTarget2;
    SerializeValue(kStream, bNoTargets);
    ((NiStreamA606*)&kStream)->WriteObjectLink(&m_kName);
    if (m_bUseFirst)
        ((NiStreamA606*)&kStream)->SaveLinkID(m_pkTarget1);
    else
        ((NiStreamA606*)&kStream)->SaveLinkID(m_pkTarget2);
    SerializeValue(kStream, m_uiUnk18);
    SerializeValue(kStream, m_uiUnk20);
    SerializeValue(kStream, m_uiUnk1c);
    bool bUnk40 = m_bUnk40;
    SerializeValue(kStream, bUnk40);
    bool bUnk41 = m_bUnk41;
    SerializeValue(kStream, bUnk41);
    bool bUseFirst = m_bUseFirst;
    SerializeValue(kStream, bUseFirst);
}

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

// @fnv 0x00a61610
void HashA616::FUN_00a61610(unsigned int key, EntryA616* entry)
{
    unsigned int uiBucket = (key >> 4) % 1001;
    entry->m_key = key;
    m_buckets[uiBucket] = new NodeA616(entry, m_buckets[uiBucket]);
    m_uiItemCount++;
}

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
// @fnv 0x00a61e60
void* __cdecl FindNodeByObject(A61E60Obj* obj)
{
    const char* pcName = *obj->GetNameRef();
    unsigned int idx = FUN_00a61530(pcName + FUN_00af4170(pcName, 1));
    A61E60Node* n;
    for (unsigned int i = 0; i < 7; ++i)
    {
        n = ((NodeList*)&DAT_011f4464->m_buckets[i].m_entries[idx])->Find(obj);
        if (n)
            break;
    }
    return n;
}

bool __fastcall FUN_00a5c180(void*, int, NiStream*);
// @fnv 0x00a62130
bool __fastcall FUN_00a62130(void* a, int b, NiStream* s)
{
    return FUN_00a5c180(a, b, s);
}

class EqBase
{
  public:
    bool __thiscall FUN_00a5c820(void* other);
    bool __thiscall FUN_00a62140(void* other);
};

// @fnv 0x00a62140
bool __thiscall EqBase::FUN_00a62140(void* other)
{
    return FUN_00a5c820(other);
}

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

// Returns a ColorAStandIn whose components are this color's r, g, b and a minus the corresponding components of c.
// @fnv 0x00a6dba0
ColorAStandIn ColorAStandIn::Subtract(const ColorAStandIn& c) const
{
    return ColorAStandIn(r - c.r, g - c.g, b - c.b, a - c.a);
}

struct FUN_00a727b0_Class
{
    unsigned int FUN_00a727b0();
};

// @fnv 0x00a727b0
unsigned int FUN_00a727b0_Class::FUN_00a727b0()
{
    return *(unsigned short*)((char*)this + 0x26);
}

extern void __cdecl FUN_00a8a9b0();

// @fnv 0x00a75f00
void __cdecl FUN_00a75f00()
{
    FUN_00a8a9b0();
}

// @fnv 0x00a75f20
unsigned short __fastcall FUN_00a75f20(char* p, int)
{
    return *reinterpret_cast<unsigned short*>(p + 0x40);
}

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

// If the owner manager's request type is 2 or 3, opens the named file read-only, calls Load on the owner, then deletes the file handle.
// @fnv 0x00a60090
void ObjA609::LoadFile()
{
    if (m_pkOwnerManager)
    {
        int eType = m_pkOwnerManager->m_eRequestType;
        if (eType == 2 || eType == 3)
        {
            const char* pcName = GetNamed()->m_pcName;
            m_pFile = FUN_00aa1a20(pcName, NiFile::READ_ONLY, 0x8000);
            if (m_pFile)
            {
                m_pkOwnerManager->Load(this);
                delete m_pFile;
                m_pFile = 0;
            }
        }
    }
}

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

// Reads texture metadata and file references from a TextureLoadStream, resolving the texture name and registering the texture object.
// @fnv 0x00a60180
void NiSourceTexture::FUN_00a60180(TextureLoadStream& stream)
{
    FUN_00a47350(stream);
    InterlockedIncrement((volatile long*)&m_uiRefCount);
    unsigned char bOldVersion = 0;
    unsigned char ucExternal;
    if (stream.Version() < 0x0a000104)
    {
        stream.Read(ucExternal);
        if (ucExternal)
        {
            stream.FUN_00a64ea0(&fileName);
            if (rendererData)
            {
                rendererData->DecRefCount();
                rendererData = 0;
            }
            bOldVersion = true;
            stream.FUN_00a64700(0);
        }
        else
        {
            fileName.Clear();
            unsigned char ucHasPixels;
            stream.Read(ucHasPixels);
            if (ucHasPixels)
            {
                stream.FUN_00a64700(1);
                stream.FUN_00a645b0();
            }
            else
            {
                stream.FUN_00a64700(0);
            }
        }
        if (pixelData)
        {
            pixelData->DecRefCount();
            pixelData = 0;
        }
    }
    else
    {
        stream.Read(bOldVersion);
        if (stream.Version() < 0x14010001)
            stream.FUN_00a64ea0(&fileName);
        else
            stream.FUN_00a64df0(&fileName);
        stream.FUN_00a64700(1);
        stream.FUN_00a645b0();
    }
    if (fileName.m_handle)
        FUN_00a76960(&fileName, &resolvedName);
    if (bOldVersion)
    {
        stream.FUN_00a636f0(resolvedName.m_handle);
        DAT_011f4780 = true;
        NiObjectA61* pkTexture = 0;
        char acFileName[260];
        do
        {
            if (!stream.FUN_00a636b0(acFileName, 260))
                break;
            stream.FUN_00a633d0(acFileName, &pkTexture);
        } while (!pkTexture);
        if (pkTexture)
        {
            resolvedName.Assign(acFileName);
            reinterpret_cast<TextureStreamVirtual*>(&stream)->Register(pkTexture);
        }
        else
        {
            DAT_011f4780 = true;
            while (stream.FUN_00a636b0(acFileName, 260))
            {
                if (FUN_00aa1a30(acFileName, 0))
                {
                    resolvedName = acFileName;
                    stream.FUN_00a633b0(this);
                    break;
                }
            }
        }
        if (pkTexture)
            pkTexture->DecRefCount();
    }
    else if (resolvedName.m_handle != DAT_0109b220)
    {
        NiObjectA61* pkTexture = 0;
        stream.FUN_00a633d0(resolvedName.m_handle, &pkTexture);
        if (!pkTexture)
            stream.FUN_00a633b0(this);
        else
            reinterpret_cast<TextureStreamVirtual*>(&stream)->Register(pkTexture);
        if (pkTexture)
            pkTexture->DecRefCount();
    }
    {
        SourcePixelLayout value;
        stream.Read(value);
        pixelLayout = value;
    }
    {
        SourceMipmapFormat value;
        stream.Read(value);
        mipmapFormat = value;
    }
    {
        SourceAlphaFormat value;
        stream.Read(value);
        alphaFormat = value;
    }
    if (stream.Version() < 0x0303000c)
    {
        if (pixelLayout == 4)
            pixelLayout = 6;
    }
    else if (stream.Version() < 0x05000001)
    {
        if (pixelLayout == 5)
            pixelLayout = 6;
    }
    unsigned char ucStatic;
    stream.Read(ucStatic);
    isStatic = ucStatic != 0;
    if (stream.Version() >= 0x0a010067)
    {
        stream.Read(loadDirect);
    }
    if (stream.Version() >= 0x14020004)
    {
        stream.Read(persistent);
    }
    DecRefCount();
}

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
// Calls FUN_00a62a40(pkStrings), then adds FUN_00a7d330 of the string at g_011f444c and a 'File:' string built from m_pcFileName to pkStrings.
// @fnv 0x00a60770
void FUN_00a60770_shell::GetFileStrings(StrArr* pkStrings)
{
    FUN_00a62a40(pkStrings);
    char* pcString = FUN_00a7d330(*(char**)&g_011f444c);
    pkStrings->Add(pcString);
    const char* pcFile = m_pcFileName;
    pcString = FUN_00a7d5e0("File:", pcFile);
    pkStrings->Add(pcString);
}

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

// If DAT_011f4468 is set, locks DAT_011f4480, looks up pcName via fnv_NiStreamGetTexture, and returns FUN_00a61f30 of the result if found, else false.
// @fnv 0x00a61fb0
bool __cdecl FUN_00a61fb0(const char* pcName)
{
    bool bResult = false;
    if (DAT_011f4468)
    {
        A61F::NiPointer spTexture;
        reinterpret_cast<GlobalObject_0096a2d0*>(&DAT_011f4480)->Lock(0);
        bool bFound = fnv_NiStreamGetTexture(pcName, &spTexture);
        A61F::NiRefObject* pkTexture = spTexture.m_pObject;
        if (bFound)
            bResult = FUN_00a61f30(pkTexture);
        reinterpret_cast<A61F::LockState*>(&DAT_011f4480)->Unlock();
        if (pkTexture)
            pkTexture->DecRefCount();
    }
    return bResult;
}

struct FUN_00a63840_Class
{
    unsigned int m0;
    unsigned int m4;
    unsigned int FUN_00a63840(unsigned int a);
};

// @fnv 0x00a63840
unsigned int FUN_00a63840_Class::FUN_00a63840(unsigned int a)
{
    return a % m4;
}

struct NiPixelFormatA775
{
    unsigned int m_auiMask[4];
    unsigned char m_aucShift[4];
    unsigned char m_aucBitsLoss[4];
};

// Converts each pixel from a packed source format to four 8-bit channels using the source NiPixelFormatA775 masks, shifts and bits-loss values.
// @fnv 0x00a77590
void __cdecl ConvertPixelFormat(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiDestStride,
                                unsigned char* pucDest, unsigned int uiSrcStride, unsigned int uiSrcSize,
                                const unsigned char* pucSrc, const NiPixelFormatA775* pkSrcFmt)
{
    const unsigned int* puiSrc = (const unsigned int*)pucSrc;
    for (unsigned int y = 0; y < uiHeight; y++)
    {
        for (unsigned int x = 0; x < uiWidth; x++)
        {
            *pucDest++ = (unsigned char)((*puiSrc & pkSrcFmt->m_auiMask[0]) >> pkSrcFmt->m_aucShift[0])
                         << pkSrcFmt->m_aucBitsLoss[0];
            *pucDest++ = (unsigned char)((*puiSrc & pkSrcFmt->m_auiMask[1]) >> pkSrcFmt->m_aucShift[1])
                         << pkSrcFmt->m_aucBitsLoss[1];
            *pucDest++ = (unsigned char)((*puiSrc & pkSrcFmt->m_auiMask[2]) >> pkSrcFmt->m_aucShift[2])
                         << pkSrcFmt->m_aucBitsLoss[2];
            *pucDest++ = (unsigned char)((*puiSrc & pkSrcFmt->m_auiMask[3]) >> pkSrcFmt->m_aucShift[3])
                         << pkSrcFmt->m_aucBitsLoss[3];
            puiSrc++;
        }
    }
}

void __cdecl FUN_00a8a9a0();
// @fnv 0x00a7b7d0
void __cdecl FUN_00a7b7d0()
{
    FUN_00a8a9a0();
}

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
// Adds src[i] * scale to dest[i] for each of the count NiPoint3 elements.
// @fnv 0x00a7ec90
void __cdecl AddScaledPoints(NiPoint3* dest, float scale, const NiPoint3* src, unsigned int count)
{
    Vec3* d = reinterpret_cast<Vec3*>(dest);
    const Vec3* s = reinterpret_cast<const Vec3*>(src);
    for (unsigned int i = 0; i < count; ++i)
    {
        d[i] += s[i] * scale;
    }
}

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
// @fnv 0x00a7fb80
void* FUN_00a7fb80_Class::FUN_00a7fb80()
{
    FUN_00a5c200();
    m_ppVirtualMethodTable = &DAT_0109b944;
    m_18 = 6;
    m_1C = 3;
    m_20 = 2;
    m_24 = 0;
    ((Z2Setup*)this)->FUN_00a5f7b0();
    m_ppVirtualMethodTable = &DAT_0109df8c;
    m_30 = 0;
    return this;
}

struct Writer
{
    void* unk0;
    int m_offset;
    void* unk8;
    int(__cdecl* m_pfnWrite)(Writer* self, void* buf, int size, int* written, int flag);
    void WriteInt(int value)
    {
        int written = 4;
        m_offset += m_pfnWrite(this, &value, 4, &written, 1);
    }
};

struct Thing
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
    int** m_ppData;
    short m_gap;
    unsigned short m_uiItemCount;
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
    Writer* m_pStreamWriter;
    void WriteData();
};

// @fnv 0x00a64010
void Thing::WriteData()
{
    m_pStreamWriter->WriteInt(m_uiItemCount - 1);
    for (unsigned int i = 1; i < m_uiItemCount; ++i)
    {
        m_pStreamWriter->WriteInt(*m_ppData[i]);
    }
}

#include <math.h>
namespace FrustumPlanes {

struct Vector
{

    float x, y, z;

    Vector()
    {}

    Vector(float a, float b, float c) : x(a), y(b), z(c)
    {}

    Vector operator*(float value) const
    {
        Vector result;
        result.x = x * value;
        result.y = y * value;
        result.z = z * value;
        return result;
    }

    Vector operator+(const Vector& value) const
    {
        Vector result;
        result.x = x + value.x;
        result.y = y + value.y;
        result.z = z + value.z;
        return result;
    }

    Vector operator-() const
    {
        Vector result;
        result.x = -x;
        result.y = -y;
        result.z = -z;
        return result;
    }
};

inline Vector multiplyVector(const Vector& v, float scalar)
{
    return v * scalar;
}
struct Transform
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Vector position;
    float scale;
};

struct Frustum
{
    float left, right, top, bottom, nearDistance, farDistance;
    bool orthographic;
};

struct Plane
{
    float x, y, z, d;
    Plane(const Vector&, const Vector&);
};

struct Planes
{
    Plane data[6];
    void SetFromFrustum(const Frustum*, const Transform*);
};

// Computes six frustum planes from a Frustum and Transform, using orthographic or perspective projection formulas.
// @fnv 0x00a74e10
void Planes::SetFromFrustum(const Frustum* apFrustum, const Transform* transform)
{

    Vector position = transform->position;

    Vector direction(transform->m00, transform->m10, transform->m20);

    Vector up(transform->m01, transform->m11, transform->m21);

    Vector right(transform->m02, transform->m12, transform->m22);

    Vector point = position + multiplyVector(direction, apFrustum->nearDistance);

    data[0] = Plane(direction, point);

    point = position + direction * apFrustum->farDistance;

    data[1] = Plane(-direction, point);

    if (apFrustum->orthographic)
    {

        float leftValue = apFrustum->left;
        point = position + right * leftValue;
        data[2] = Plane(right, point);

        point = position + right * apFrustum->right;
        data[3] = Plane(-right, point);

        point = position + up * apFrustum->top;
        data[4] = Plane(-up, point);

        float bottomValue = apFrustum->bottom;
        point = position + up * bottomValue;
        data[5] = Plane(up, point);
    }
    else
    {

        float inverse = 1.0f / (float)sqrt((float)(1.0 + (float)(apFrustum->left * apFrustum->left)));

        float coefficient = -apFrustum->left * inverse;
        Vector normal = direction * coefficient + right * inverse;
        data[2] = Plane(normal, position);

        inverse = 1.0f / (float)sqrt((float)(1.0 + (float)(apFrustum->right * apFrustum->right)));

        coefficient = apFrustum->right * inverse;
        float opposite = -inverse;
        normal = direction * coefficient + right * opposite;
        data[3] = Plane(normal, position);

        inverse = 1.0f / (float)sqrt((float)(1.0 + (float)(apFrustum->top * apFrustum->top)));

        coefficient = inverse * apFrustum->top;
        opposite = -inverse;
        normal = direction * coefficient + up * opposite;
        data[4] = Plane(normal, position);

        inverse = 1.0f / (float)sqrt((float)(1.0 + (float)(apFrustum->bottom * apFrustum->bottom)));

        coefficient = -apFrustum->bottom * inverse;
        normal = direction * coefficient + up * inverse;
        data[5] = Plane(normal, position);
    }
}

}

// Converts a 32-bit RGBA pixel buffer to a packed format defined by layout, writing results to dest.
// @fnv 0x00a77040
void __cdecl ConvertRGBAToPacked(unsigned int width, unsigned int height, unsigned int unusedA, unsigned char* dest,
                                 const void* unusedB, const NiPixelFormatA775& layout, const unsigned char* src,
                                 const NiPixelFormatA775& unusedLayout)
{
    unsigned short* out = reinterpret_cast<unsigned short*>(dest);
    for (unsigned row = 0; row < height; ++row)
    {
        for (unsigned col = 0; col < width; ++col)
        {
            unsigned char red = *src++;
            unsigned char green = *src++;
            unsigned char blue = *src++;
            unsigned char alpha = *src++;
            *out = (unsigned short)((((unsigned long)red >> layout.m_aucBitsLoss[0]) << layout.m_aucShift[0] &
                                     layout.m_auiMask[0]) |
                                    (((unsigned long)green >> layout.m_aucBitsLoss[1]) << layout.m_aucShift[1] &
                                     layout.m_auiMask[1]) |
                                    (((unsigned long)blue >> layout.m_aucBitsLoss[2]) << layout.m_aucShift[2] &
                                     layout.m_auiMask[2]) |
                                    (((unsigned long)alpha >> layout.m_aucBitsLoss[3]) << layout.m_aucShift[3] &
                                     layout.m_auiMask[3]));
            ++out;
        }
    }
}

// Packs 4-byte RGBA source pixels into 32-bit values using format's bit loss, shift and mask per channel; sourceFormat is unused.
// @fnv 0x00a771d0
void __cdecl FUN_00a771d0(unsigned int width, unsigned int height, unsigned int destStride, unsigned int* dest,
                          unsigned int srcStride, const NiPixelFormatA775* format, const unsigned char* src,
                          const NiPixelFormatA775& sourceFormat)
{
    unsigned int* out = dest;
    for (unsigned int row = 0; row < height; ++row)
    {
        for (unsigned int col = 0; col < width; ++col)
        {
            unsigned char red = *src++;
            unsigned char green = *src++;
            unsigned char blue = *src++;
            unsigned char alpha = *src++;
            *out++ =
                (((unsigned long)red >> format->m_aucBitsLoss[0]) << format->m_aucShift[0] & format->m_auiMask[0]) |
                (((unsigned long)green >> format->m_aucBitsLoss[1]) << format->m_aucShift[1] & format->m_auiMask[1]) |
                (((unsigned long)blue >> format->m_aucBitsLoss[2]) << format->m_aucShift[2] & format->m_auiMask[2]) |
                (((unsigned long)alpha >> format->m_aucBitsLoss[3]) << format->m_aucShift[3] & format->m_auiMask[3]);
        }
    }
}

struct BitPackDesc
{
    unsigned short m_mask00;
    unsigned short unk02;
    unsigned short m_mask04;
    unsigned short unk06;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    unsigned short m_mask0C;
    unsigned short unk0E;
    unsigned char m_shift10;
    unsigned char m_shift11;
    unsigned char unk12;
    unsigned char m_shift13;
    unsigned char m_shift14;
    unsigned char m_shift15;
    unsigned char unk16;
    unsigned char m_shift17;
};

// Packs rows x count pixels of 2 source bytes into 16-bit values via desc's shifts and masks, adding a constant third component.
// @fnv 0x00a77880
void __cdecl FUN_00a77880(unsigned int count, unsigned int rows, void* unusedA, unsigned short* dst, void* unusedB,
                          BitPackDesc* desc, const unsigned char* src, void* unusedC)
{
    unsigned short* d = dst;
    for (unsigned int y = 0; y < rows; y++)
    {
        for (unsigned int x = 0; x < count; x++)
        {
            unsigned char b0 = *src++;
            unsigned char b1 = *src++;
            unsigned short comp1 =
                (unsigned short)(((unsigned char)(b0 >> desc->m_shift14) << desc->m_shift10) & desc->m_mask00);
            unsigned short comp2 =
                (unsigned short)(((unsigned char)(b1 >> desc->m_shift15) << desc->m_shift11) & desc->m_mask04);
            unsigned short comp3 =
                (unsigned short)(((0xffffffffu >> desc->m_shift17) << desc->m_shift13) & desc->m_mask0C);
            *d++ = (unsigned short)(comp1 | comp2 | comp3);
        }
    }
}

class NiRefObject
{
  public:
    virtual void unk00()
    {}
    virtual void Destroy()
    {}
    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement((LONG*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((LONG*)&m_uiRefCount) == 0)
            Destroy();
    }
};

struct MapEntry
{
    NiRefObject* m_pObject;
    unsigned int m_uiKey;
};

struct WeightedMapNode
{
    MapEntry* m_afEntries;
    WeightedMapNode* m_pNext;
};

class FUN_00a61a60_cls
{
  public:
    bool GetByKey(unsigned int index, unsigned int key, NiRefObject*& out);
};

// Walks the WeightedMapNode chain at the given index, finds the MapEntry whose m_uiKey matches, and swaps the out reference to it with refcount updates.
// @fnv 0x00a61a60
bool FUN_00a61a60_cls::GetByKey(unsigned int index, unsigned int key, NiRefObject*& out)
{
    WeightedMapNode* node = reinterpret_cast<WeightedMapNode**>(this)[index];
    bool result = false;
    if (node != 0)
    {
        do
        {
            if (key == node->m_afEntries->m_uiKey)
            {
                MapEntry* hit = node->m_afEntries;
                NiRefObject* old = out;
                if (old != hit->m_pObject)
                {
                    if (old != 0 && InterlockedDecrement((LONG*)&old->m_uiRefCount) == 0)
                        old->Destroy();
                    out = hit->m_pObject;
                    if (out != 0)
                        InterlockedIncrement((LONG*)&out->m_uiRefCount);
                }
                result = true;
                break;
            }
            node = node->m_pNext;
        } while (node != 0);
    }
    return result;
}

class NiPixelFormat
{
  public:
    unsigned char m_ucFlags;
    unsigned char m_ucBitsPerPixel;
    unsigned char unk02, unk03;
    int unk04, unk08, unk0c, unk10;
    A62190Component m_akComponents[4];
    unsigned char FUN_00a62230(int component) const;
    unsigned int GetMask(int component) const;
};
class NiPixelData : public BSFadeNode
{
  public:
    void* m_vptr;
    unsigned int m_uiRefCount;
    NiPixelFormat m_kPixelFormat;
    void* m_pColorEntries;
    unsigned char* m_pucPixels;
    unsigned int* m_puiWidth;
    unsigned int* m_puiHeight;
    unsigned int* m_puiOffset;
    unsigned int m_uiMipmapLevels;
    unsigned int unk64, unk68, unk6c, unk70;
    NiPixelData(unsigned int, unsigned int, const NiPixelFormat&, unsigned int, unsigned int) throw();
};
struct CheckerColor
{
    float r, g, b, a;
};
// Creates a 32x32 NiPixelData and fills each face with a two-color checkerboard pattern using the given colors and pixel format.
// @fnv 0x00a62330
NiPixelData* __cdecl CreateCheckerboardTexture(const CheckerColor& color0, const CheckerColor& color1,
                                               const NiPixelFormat& format, unsigned int faces)
{
    NiPixelData* data = new NiPixelData(32, 32, format, 1, faces);
    unsigned int colors[2];
    colors[0] = ((unsigned int)(color0.r * 255.0) << format.FUN_00a62230(0)) & format.GetMask(0);
    colors[0] |= ((unsigned int)(color0.g * 255.0) << format.FUN_00a62230(1)) & format.GetMask(1);
    colors[0] |= ((unsigned int)(color0.b * 255.0) << format.FUN_00a62230(2)) & format.GetMask(2);
    colors[0] |= ((unsigned int)(color0.a * 255.0) << format.FUN_00a62230(3)) & format.GetMask(3);
    colors[1] = ((unsigned int)(color1.r * 255.0) << format.FUN_00a62230(0)) & format.GetMask(0);
    colors[1] |= ((unsigned int)(color1.g * 255.0) << format.FUN_00a62230(1)) & format.GetMask(1);
    colors[1] |= ((unsigned int)(color1.b * 255.0) << format.FUN_00a62230(2)) & format.GetMask(2);
    colors[1] |= ((unsigned int)(color1.a * 255.0) << format.FUN_00a62230(3)) & format.GetMask(3);
    for (unsigned int face = 0; face < faces; ++face)
    {
        unsigned char* dst =
            data->m_pucPixels + data->m_puiOffset[0] + data->m_puiOffset[data->m_uiMipmapLevels] * face;
        unsigned char bytes = format.m_ucBitsPerPixel >> 3;
        for (unsigned int y = 0; y < 32; ++y)
        {
            unsigned int rowHalf = y >> 4;
            for (unsigned int x = 0; x < 32; ++x)
            {
                memcpy(dst, &colors[rowHalf != (x >> 4)], bytes);
                dst += bytes;
            }
        }
    }
    return data;
}

void* __cdecl FUN_00aa1070(unsigned int size);
void __cdecl FUN_00ec65a6(char* dst, unsigned int count, const char* src);

struct FUN_00a63980_Out
{
    int unk00;
    char* unk04;
    unsigned short unk08;
};

struct FUN_00a63980_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    bool flag10;
    void FUN_00a63980(FUN_00a63980_Out* dst, const char* src, unsigned short value);
};

// If flag10 is set, stores an allocated copy of src in dst->unk04, otherwise stores src itself; also sets dst->unk08 to value.
// @fnv 0x00a63980
void FUN_00a63980_Class::FUN_00a63980(FUN_00a63980_Out* dst, const char* src, unsigned short value)
{
    if (flag10)
    {
        unsigned int size = strlen(src) + 1;
        dst->unk04 = (char*)FUN_00aa1070(size);
        FUN_00ec65a6(dst->unk04, size, src);
    }
    else
    {
        dst->unk04 = (char*)src;
    }
    dst->unk08 = value;
}

// Scalar deleting destructor: free the owned buffer, then release the object through the
// global memory manager when the delete flag is set (class-specific operator delete).
struct FUN_00a64470
{
    virtual ~FUN_00a64470();
    void* m_pData;
    static void operator delete(void* pvMem)
    {
        g_memoryManager.Deallocate(pvMem);
    }
};

// @fnv 0x00a64470
FUN_00a64470::~FUN_00a64470()
{
    _NiFree(m_pData);
}

extern "C" void _ReadWriteBarrier(void);
struct S_00a6d290_Obj
{
    virtual void v00() throw();
    virtual void v04() throw();
    long refs;
};

struct S_00a6d290_Base
{
    long refs;
    virtual ~S_00a6d290_Base() throw();
};

struct FUN_00a6d290 : S_00a6d290_Base
{
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
    S_00a6d290_Obj* unk30;
    virtual ~FUN_00a6d290() throw();
};

// Destructor that releases the referenced object in unk30 by decrementing its refs and calling v04 when it reaches zero.
// @fnv 0x00a6d290
FUN_00a6d290::~FUN_00a6d290() throw()
{
    _ReadWriteBarrier();
    S_00a6d290_Obj* o = unk30;
    if (o)
    {
        if (!InterlockedDecrement(&o->refs))
            o->v04();
    }
}

struct PixelConvertFormat
{
    unsigned short m_mask0;
    unsigned short unk02;
    unsigned short m_mask1;
    unsigned short unk06;
    unsigned short m_mask2;
    unsigned short unk0a;
    unsigned short m_mask3;
    unsigned short unk0e;
    unsigned char m_shift0;
    unsigned char m_shift1;
    unsigned char m_shift2;
    unsigned char m_shift3;
    unsigned char m_shift4;
    unsigned char m_shift5;
    unsigned char m_shift6;
    unsigned char m_shift7;
};

// Converts a pixel buffer from a source format to 16-bit using per-channel shift and mask values from fmt, writing results to dst.
// @fnv 0x00a76ea0
void __cdecl ConvertPixelsTo16Bit(unsigned int width, unsigned int height, unsigned int unused03, unsigned short* dst,
                                  unsigned int unused05, const PixelConvertFormat* apFormat, const unsigned char* src,
                                  const PixelConvertFormat* unused8)
{
    unsigned short* destination = dst;
    if (height <= 0)
        return;

    unsigned int one = 1;

    for (unsigned int outer = height; outer != 0; --outer)
    {
        if (width <= 0)
            continue;

        for (height = width; height != 0; --height)
        {
            unsigned char b0 = *src++;
            unsigned char b1 = *src++;
            unsigned char b2 = *src++;

            unsigned short px =
                (unsigned short)(((0xffu >> apFormat->m_shift7) << apFormat->m_shift3) & apFormat->m_mask3);
            px |= (unsigned short)((((unsigned short)(b0 >> apFormat->m_shift4)) << apFormat->m_shift0) &
                                   apFormat->m_mask0);
            px |= (unsigned short)((((unsigned short)(b2 >> apFormat->m_shift6)) << apFormat->m_shift2) &
                                   apFormat->m_mask2);
            px |= (unsigned short)((((unsigned short)(b1 >> apFormat->m_shift5)) << apFormat->m_shift1) &
                                   apFormat->m_mask1);

            *destination++ = px;
        }
    }
}

// Converts a packed RGB source buffer to a destination pixel format using per-channel shift, loss and mask values from pkSrcFmt.
// @fnv 0x00a76f80
void __cdecl ConvertRGBToFormat(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiDestStride,
                                unsigned int* puiDest, unsigned int uiSrcStride, const NiPixelFormatA775* pkSrcFmt,
                                const unsigned char* pucSrc, unsigned int uiUnused8)
{
    unsigned int* pDest = puiDest;
    if (uiHeight <= 0)
        return;

    unsigned int h = uiHeight;
    do
    {
        if (uiWidth > 0)
        {
            unsigned int w = uiWidth;
            do
            {
                unsigned char b0 = *pucSrc++;
                unsigned char b1 = *pucSrc++;
                unsigned char b2 = *pucSrc++;

                unsigned int c0 = ((unsigned int)b0 >> pkSrcFmt->m_aucBitsLoss[0]) << pkSrcFmt->m_aucShift[0];
                c0 &= pkSrcFmt->m_auiMask[0];

                unsigned int c1 = ((unsigned int)b1 >> pkSrcFmt->m_aucBitsLoss[1]) << pkSrcFmt->m_aucShift[1];
                c1 &= pkSrcFmt->m_auiMask[1];

                unsigned int c2 = ((unsigned int)b2 >> pkSrcFmt->m_aucBitsLoss[2]) << pkSrcFmt->m_aucShift[2];
                c2 &= pkSrcFmt->m_auiMask[2];

                unsigned int c3 = ((unsigned int)0xff >> pkSrcFmt->m_aucBitsLoss[3]) << pkSrcFmt->m_aucShift[3];
                c3 &= pkSrcFmt->m_auiMask[3];

                *pDest++ = c0 | c1 | c2 | c3;
                --w;
            } while (w != 0);
        }
        --h;
    } while (h != 0);
}

struct PixelChannels
{
    unsigned int redMask;
    unsigned int greenMask;
    unsigned int blueMask;
    unsigned int alphaMask;
    unsigned char redRightShift;
    unsigned char greenRightShift;
    unsigned char blueRightShift;
    unsigned char alphaRightShift;
    unsigned char redLeftShift;
    unsigned char greenLeftShift;
    unsigned char blueLeftShift;
    unsigned char alphaLeftShift;
};

// Converts a packed pixel buffer to RGBA bytes using the channel masks and shifts from channels, writing 0xFF for alpha.
// @fnv 0x00a77630
void __cdecl ConvertPackedPixelsToRGBA(unsigned int width, unsigned int height, unsigned int sourcePitch, char* output,
                                       unsigned int outputPitch, unsigned int unused, const unsigned int* source,
                                       const PixelChannels* channels)
{
    const unsigned int* pixel = source;
    if (height > 0)
    {
        unsigned int rowsRemaining = height;
        do
        {
            if (width > 0)
            {
                unsigned int pixelsRemaining = width;
                do
                {
                    *output++ = (char)((pixel[0] & channels->redMask) >> channels->redRightShift)
                                << channels->redLeftShift;
                    *output++ = (char)((pixel[0] & channels->greenMask) >> channels->greenRightShift)
                                << channels->greenLeftShift;
                    *output++ = (char)((pixel[0] & channels->blueMask) >> channels->blueRightShift)
                                << channels->blueLeftShift;
                    *output++ = -1;
                    ++pixel;
                } while (--pixelsRemaining != 0);
            }
        } while (--rowsRemaining != 0);
    }
}

static __declspec(noinline) int CompareValues(const float* a, const float* b, unsigned count)
{
    for (unsigned i = 0; i < count; ++i)
    {
        if (a[i] < b[i])
            return -1;
        if (a[i] > b[i])
            return 1;
    }
    return 0;
}
struct PivotGeometry
{
    struct LastIndex
    {
        int value;
    };
    int unk00, unk04;
    unsigned short vertexCount, unk0a, format, unk0e;
    int unk10, unk14, unk18, unk1c;
    float* positions;
    float* normals;
    float* colors;
    float* texcoords;
    __declspec(noinline) int CompareVertices(unsigned short a, unsigned short b, unsigned char ctx);
    int MedianOfThree(unsigned short* arr, unsigned char ctx, int lo, int hi);
};
__declspec(noinline) int PivotGeometry::CompareVertices(unsigned short a, unsigned short b, unsigned char ctx)
{
    int result;
    if (ctx & 1)
    {
        result = CompareValues(positions + 3 * a, positions + 3 * b, 3);
        if (result)
            return result;
    }
    if (normals && (ctx & 2))
    {
        result = CompareValues(normals + 3 * a, normals + 3 * b, 3);
        if (result)
            return result;
    }
    if (colors && (ctx & 4))
    {
        result = CompareValues(colors + 4 * a, colors + 4 * b, 4);
        if (result)
            return result;
    }
    if (texcoords && (ctx & 8))
    {
        for (unsigned short set = 0; set < (format & 1); ++set)
        {
            result = CompareValues(texcoords + 2 * (a + set * vertexCount), texcoords + 2 * (b + set * vertexCount), 2);
            if (result)
                return result;
        }
    }
    return 0;
}

// Returns the median vertex index of arr[lo], arr[mid], arr[hi] by comparing them with CompareVertices under the given ctx flags.
// @fnv 0x00a672b0
int PivotGeometry::MedianOfThree(unsigned short* apIndices, unsigned char ctx, int lo, int hi)
{
    int mid = (lo + hi) >> 1;
    if (CompareVertices(apIndices[lo], apIndices[mid], ctx) < 0)
    {
        if (CompareVertices(apIndices[mid], apIndices[hi], ctx) < 0)
            return apIndices[mid];
        if (CompareVertices(apIndices[lo], apIndices[hi], ctx) < 0)
            return apIndices[hi];
        return apIndices[lo];
    }
    if (CompareVertices(apIndices[lo], apIndices[hi], ctx) < 0)
        return apIndices[lo];
    if (CompareVertices(apIndices[mid], apIndices[hi], ctx) < 0)
        return apIndices[hi];
    return apIndices[mid];
}
