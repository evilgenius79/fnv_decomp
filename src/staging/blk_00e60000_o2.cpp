
// src/staging/blk_00e60000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_00a77980_shell
{
    unsigned char FUN_00a77980(int);
};
struct FUN_00e7cdf0_shell
{
    unsigned char FUN_00e7cdf0();
    int _p1;
    int _p2;
    int _p3;
    int _p4;
    int _p5;
    int _p6;
};
// @fnv 0x00e7cdf0
unsigned char FUN_00e7cdf0_shell::FUN_00e7cdf0()
{
    if (_p4 && _p6)
        return ((FUN_00a77980_shell*)_p4)->FUN_00a77980(0x11) > 0;
    return 0;
}

void __cdecl FUN_00e7d1b0();

void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00e7d230_cls
{
    FUN_00e7d230_cls* __thiscall DestroyIfFlagged(int);
};

// Calls FUN_00e7d1b0, then deletes this (size 0x24) when bit 0 of a is set, and returns this.
// @fnv 0x00e7d230
FUN_00e7d230_cls* __thiscall FUN_00e7d230_cls::DestroyIfFlagged(int aiFlags)
{
    FUN_00e7d1b0();
    if (aiFlags & 1)
        operator delete(this, 0x24);
    return this;
}

struct MM
{
    void Deallocate(void*);
};
extern MM g_memoryManager;

void __cdecl DestroyArrayElements(void*);

struct FUN_00e7f790_Class
{
    void __thiscall DestroyList();
};

// @fnv 0x00e7f790
void __thiscall FUN_00e7f790_Class::DestroyList()
{
    DestroyArrayElements(*(void**)this);
    void* next = *(void**)((char*)this + 8);
    if (next)
    {
        ((FUN_00e7f790_Class*)next)->DestroyList();
        g_memoryManager.Deallocate(next);
    }
}

// @fnv 0x00e60c70
int __cdecl FUN_00e60c70(int a)
{
    switch (a)
    {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
    case 4:
        return 3;
    default:
        return 0;
    }
}

struct FUN_00e67fd0_cls
{
    void __thiscall ClearEntries();
};

// Zeroes the first int of each of two arrays of entries, using the counts at offsets 0x10 and 8 and strides 0x50 and 0x40.
// @fnv 0x00e67fd0
void __thiscall FUN_00e67fd0_cls::ClearEntries()
{
    int count = 0;
    if (count < *(int*)((char*)this + 0x10))
    {
        do
        {
            *(int*)((char*)this + 0xfb4 + count * 0x50) = 0;
            ++count;
        } while (count < *(int*)((char*)this + 0x10));
    }
    count = 0;
    if (count < *(int*)((char*)this + 8))
    {
        do
        {
            *(int*)((char*)this + 0x50 + count * 0x40) = 0;
            ++count;
        } while (count < *(int*)((char*)this + 8));
    }
}

typedef void*(__stdcall* DepthDevice)(unsigned int);
typedef int(__stdcall* CreateExFn)(unsigned int, DepthDevice**);
extern void* DAT_0126f0d4;
extern DepthDevice DAT_0126f0dc;
extern CreateExFn DAT_0126f0e0;
extern void*(__stdcall* DAT_00fdf0ac)(void*, const char*);
extern void*(__stdcall* DAT_00fdf0b0)(const char*);

// Loads D3D9.DLL and resolves Direct3DCreate9Ex and Direct3DCreate9, returning 1 if the Direct3DCreate9 pointer is available.
// @fnv 0x00e69410
unsigned char __cdecl InitD3D9CreateFunctions()
{
    if (DAT_0126f0dc)
        return 1;
    DAT_0126f0d4 = DAT_00fdf0b0("D3D9.DLL");
    if (DAT_0126f0d4)
    {
        void*(__stdcall * pfnGetProcAddress)(void*, const char*) = DAT_00fdf0ac;
        DAT_0126f0e0 = (CreateExFn)pfnGetProcAddress(DAT_0126f0d4, "Direct3DCreate9Ex");
        DAT_0126f0dc = (DepthDevice)pfnGetProcAddress(DAT_0126f0d4, "Direct3DCreate9");
        if (DAT_0126f0dc)
            return 1;
    }
    return 0;
}

extern void __cdecl NiFree(void*);
struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
extern int DAT_010eec74;
struct FUN_00e7b200_Class
{
    int vtbl;
    int m_p;
    FUN_00e7b200_Class* __thiscall FUN_00e7b200(int);
};
// Sets the vtable, frees m_p with NiFree, and if bit 0 of a is set deallocates this via the memory manager; returns this.
// @fnv 0x00e7b200
FUN_00e7b200_Class* __thiscall FUN_00e7b200_Class::FUN_00e7b200(int aiFlags)
{
    vtbl = (int)&DAT_010eec74;
    NiFree((void*)m_p);
    if (aiFlags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

struct FUN_00e7d490_Class
{
    void* _00;
    void* _04;
    void* _08;
    void* _0c;
    void* _10;
    void* _14;
    void* _18;
    void* _1c;
    void* _20;
    void __thiscall FUN_00e7d490();
};
// @fnv 0x00e7d490
void __thiscall FUN_00e7d490_Class::FUN_00e7d490()
{
    if (_14)
    {
        ((void(__stdcall*)(void*))(*(void***)_14)[2])(_14);
        _14 = 0;
    }
    g_memoryManager.Deallocate(_0c);
    void* tmp = _20;
    _0c = 0;
    if (tmp)
    {
        ((void(__stdcall*)(void*))(*(void***)tmp)[2])(tmp);
        _20 = 0;
    }
}

struct P03MM
{
    void* __thiscall Allocate(unsigned int);
};
struct StagePool
{
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;
    int v6;
};
extern StagePool* DAT_0126f6cc;

// Allocates a 0x18-byte StagePool via the memory manager, zeroes its first four fields, sets the last two to 8, and stores it in DAT_0126f6cc.
// @fnv 0x00e7ec90
void __cdecl CreateStagePool()
{
    StagePool* p = (StagePool*)reinterpret_cast<P03MM*>(&g_memoryManager)->Allocate(0x18);
    if (p)
    {
        p->v1 = 0;
        p->v2 = 0;
        p->v3 = 0;
        p->v4 = 0;
        p->v5 = 8;
        p->v6 = 8;
        DAT_0126f6cc = p;
    }
    else
        DAT_0126f6cc = 0;
}

struct FUN_00e7efc0_Node
{
    int _a;
    int _b;
    FUN_00e7efc0_Node* next;
    FUN_00e7efc0_Node* prev;
};
struct FUN_00e7efc0_List
{
    int _x;
    int _y;
    int _z;
    int count;
    FUN_00e7efc0_Node* head;
    FUN_00e7efc0_Node* __thiscall FUN_00e7efc0(FUN_00e7efc0_Node* node);
};
// Unlinks node from the doubly linked list, fixes neighbours and head, decrements count, clears node's links and returns it.
// @fnv 0x00e7efc0
FUN_00e7efc0_Node* __thiscall FUN_00e7efc0_List::FUN_00e7efc0(FUN_00e7efc0_Node* node)
{
    FUN_00e7efc0_Node* prev = node->prev;
    FUN_00e7efc0_Node* next = node->next;
    if (next)
        next->prev = prev;
    if (prev)
        prev->next = next;
    if (node == head)
        head = next;
    --count;
    node->next = 0;
    node->prev = 0;
    return node;
}

namespace fnv_00e7f2b0 {
struct P03MM
{
    void* __thiscall Allocate(unsigned int);
};
struct D3DRenderStateGroup
{
    void* p[4];
    unsigned int a;
    unsigned int b;
};
struct NiD3DRenderStateEntry
{
    void* p[4];
    unsigned int a;
    unsigned int b;
};
D3DRenderStateGroup* DAT_0126f718;
NiD3DRenderStateEntry* DAT_0126f71c;
// Allocates two 0x18-byte structures, zeroes their four pointers, sets their a/b fields to 8 and 0x10, and stores them in DAT_0126f718 and DAT_0126f71c.
// @fnv 0x00e7f2b0
void __cdecl FUN_00e7f2b0()
{
    D3DRenderStateGroup* p =
        static_cast<D3DRenderStateGroup*>(reinterpret_cast<P03MM*>(&g_memoryManager)->Allocate(0x18));
    if (p)
    {
        p->p[0] = 0;
        p->p[1] = 0;
        p->p[2] = 0;
        p->p[3] = 0;
        p->a = 8;
        p->b = 8;
        DAT_0126f718 = p;
    }
    else
    {
        DAT_0126f718 = 0;
    }
    NiD3DRenderStateEntry* q =
        static_cast<NiD3DRenderStateEntry*>(reinterpret_cast<P03MM*>(&g_memoryManager)->Allocate(0x18));
    if (q)
    {
        q->p[0] = 0;
        q->p[1] = 0;
        q->p[2] = 0;
        q->p[3] = 0;
        q->a = 0x10;
        q->b = 0x10;
        DAT_0126f71c = q;
    }
    else
    {
        DAT_0126f71c = 0;
    }
}
}  // namespace fnv_00e7f2b0

enum DX9Format_00e68530
{
    DX9FMT_A8P8 = 40,
    DX9FMT_P8 = 41
};

enum DX9ResourceType_00e68530
{
    DX9RTYPE_TEXTURE = 3,
    DX9RTYPE_VOLUMETEXTURE = 4,
    DX9RTYPE_CUBETEXTURE = 5
};

struct DX9SurfaceDesc_00e68530
{
    DX9Format_00e68530 Format;
    DX9ResourceType_00e68530 Type;
    unsigned long Usage;
    int Pool;
    int MultiSampleType;
    unsigned long MultiSampleQuality;
    unsigned int Width;
    unsigned int Height;
};

struct DX9VolumeDesc_00e68530
{
    DX9Format_00e68530 Format;
    DX9ResourceType_00e68530 Type;
    unsigned long Usage;
    int Pool;
    unsigned int Width;
    unsigned int Height;
    unsigned int Depth;
};

struct DX9BaseTexture_00e68530
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObj) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetDevice(void** ppDevice) = 0;
    virtual long __stdcall SetPrivateData(const void* refguid, const void* pData, unsigned long SizeOfData,
                                          unsigned long Flags) = 0;
    virtual long __stdcall GetPrivateData(const void* refguid, void* pData, unsigned long* pSizeOfData) = 0;
    virtual long __stdcall FreePrivateData(const void* refguid) = 0;
    virtual unsigned long __stdcall SetPriority(unsigned long PriorityNew) = 0;
    virtual unsigned long __stdcall GetPriority() = 0;
    virtual void __stdcall PreLoad() = 0;
    virtual DX9ResourceType_00e68530 __stdcall GetType() = 0;
    virtual unsigned long __stdcall SetLOD(unsigned long LODNew) = 0;
    virtual unsigned long __stdcall GetLOD() = 0;
    virtual unsigned long __stdcall GetLevelCount() = 0;
    virtual long __stdcall SetAutoGenFilterType(int FilterType) = 0;
    virtual int __stdcall GetAutoGenFilterType() = 0;
    virtual void __stdcall GenerateMipSubLevels() = 0;
};

struct DX9Texture_00e68530 : DX9BaseTexture_00e68530
{
    virtual long __stdcall GetLevelDesc(unsigned int Level, DX9SurfaceDesc_00e68530* pDesc) = 0;
};

struct DX9CubeTexture_00e68530 : DX9BaseTexture_00e68530
{
    virtual long __stdcall GetLevelDesc(unsigned int Level, DX9SurfaceDesc_00e68530* pDesc) = 0;
};

struct DX9VolumeTexture_00e68530 : DX9BaseTexture_00e68530
{
    virtual long __stdcall GetLevelDesc(unsigned int Level, DX9VolumeDesc_00e68530* pDesc) = 0;
};

struct NiComponentSpec
{
    int m_eComponent;
    int m_eRepresentation;
    unsigned char m_ucBPC;
    bool m_bSigned;
};

struct NiPixelFormat
{
    unsigned char m_ucFlags;
    unsigned char m_ucBitsPerPixel;
    int m_eFormat;
    int m_eTiling;
    unsigned int m_uiRendererHint;
    unsigned int m_uiExtraData;
    NiComponentSpec m_akComponents[4];
    NiPixelFormat();
};

bool __cdecl GetPixelTemplateForFormat(DX9Format_00e68530 eFormat, NiPixelFormat& kFormat);

struct NiDX9SourceCubeMapData_S
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_uiImageWidth;
    unsigned int m_uiImageHeight;
    NiPixelFormat m_kPixelFormat;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    DX9BaseTexture_00e68530* m_pkCubeMapTexture;
    unsigned int m_uiTextureFormat;
    bool m_b6c;
    bool m_bHasTexture;
    unsigned int m_uiSize;
    bool FUN_00e68530(DX9BaseTexture_00e68530* pkD3DTexture);
};

// Reads each mip level of the given D3D texture, cube or volume texture, records dimensions and pixel format, and accumulates m_uiSize.
// @fnv 0x00e68530
bool NiDX9SourceCubeMapData_S::FUN_00e68530(DX9BaseTexture_00e68530* pkD3DTexture)
{
    m_uiTextureFormat = pkD3DTexture->GetLevelCount();
    m_bHasTexture = (m_uiTextureFormat != 1);
    m_uiSize = 0;

    DX9ResourceType_00e68530 eType = pkD3DTexture->GetType();
    if (eType == DX9RTYPE_TEXTURE)
    {
        for (unsigned int i = 0; i < m_uiTextureFormat; i++)
        {
            DX9SurfaceDesc_00e68530 kDesc;
            if (((DX9Texture_00e68530*)pkD3DTexture)->GetLevelDesc(i, &kDesc) < 0)
                return false;
            if (i == 0)
            {
                m_uiImageWidth = kDesc.Width;
                m_uiImageHeight = kDesc.Height;
                if (kDesc.Format == DX9FMT_A8P8 || kDesc.Format == DX9FMT_P8)
                    return false;
                m_kPixelFormat = NiPixelFormat();
                GetPixelTemplateForFormat(kDesc.Format, m_kPixelFormat);
            }
            m_uiSize += (kDesc.Width * kDesc.Height * m_kPixelFormat.m_ucBitsPerPixel) >> 3;
        }
    }
    else if (eType == DX9RTYPE_CUBETEXTURE)
    {
        for (unsigned int i = 0; i < m_uiTextureFormat; i++)
        {
            DX9SurfaceDesc_00e68530 kDesc;
            if (((DX9CubeTexture_00e68530*)pkD3DTexture)->GetLevelDesc(i, &kDesc) < 0)
                return false;
            if (i == 0)
            {
                m_uiImageWidth = kDesc.Width;
                m_uiImageHeight = kDesc.Height;
                if (kDesc.Format == DX9FMT_A8P8 || kDesc.Format == DX9FMT_P8)
                    return false;
                m_kPixelFormat = NiPixelFormat();
                GetPixelTemplateForFormat(kDesc.Format, m_kPixelFormat);
            }
            m_uiSize += (kDesc.Width * kDesc.Height * m_kPixelFormat.m_ucBitsPerPixel) >> 3;
        }
        m_pkCubeMapTexture = pkD3DTexture;
        m_uiSize *= 6;
        return true;
    }
    else if (eType == DX9RTYPE_VOLUMETEXTURE)
    {
        for (unsigned int i = 0; i < m_uiTextureFormat; i++)
        {
            DX9VolumeDesc_00e68530 kDesc;
            if (((DX9VolumeTexture_00e68530*)pkD3DTexture)->GetLevelDesc(i, &kDesc) < 0)
                return false;
            if (i == 0)
            {
                m_uiImageWidth = kDesc.Width;
                m_uiImageHeight = kDesc.Height;
                if (kDesc.Format == DX9FMT_A8P8 || kDesc.Format == DX9FMT_P8)
                    return false;
                m_kPixelFormat = NiPixelFormat();
                GetPixelTemplateForFormat(kDesc.Format, m_kPixelFormat);
            }
            m_uiSize += (kDesc.Width * kDesc.Height * kDesc.Depth * m_kPixelFormat.m_ucBitsPerPixel) >> 3;
        }
    }

    m_pkCubeMapTexture = pkD3DTexture;
    return true;
}

struct FUN_00e7d560_Class
{
    void* _00;
    void* _04;
    void* _08;
    void* _0c;
    void* _10;
    void* _14;
    void* _18;
    void* _1c;
    void* _20;
    void* _24;
    void* _28;
    void* _2c;
    void* _30;
    void* _34;
    void* _38;
    void* _3c;
    void* _40;
    void* _44;
    void* _48;
    void* _4c;
    void* _50;
    void* _54;
    void* _58;
    void __thiscall FUN_00e7d560();
};

// Releases the DX9BaseTexture objects at _14 and _58, deallocates the pointer at _0c, and nulls all three.
// @fnv 0x00e7d560
void __thiscall FUN_00e7d560_Class::FUN_00e7d560()
{
    if (_14)
    {
        ((DX9BaseTexture_00e68530*)_14)->Release();
        _14 = 0;
    }
    g_memoryManager.Deallocate(_0c);
    _0c = 0;
    if (_58)
    {
        ((DX9BaseTexture_00e68530*)_58)->Release();
        _58 = 0;
    }
}

struct FUN_00e673f0_shell
{
    int __thiscall GetPrimitiveCount();
};
struct FUN_00e613f0
{
    int _00;
    int _04;
    int _08;
    FUN_00e673f0_shell** _0c;
    int _10;
    int __thiscall Sum();
};
// Sums the results of calling GetPrimitiveCount on each of the _10 entries in the _0c array and returns the total.
// @fnv 0x00e613f0
int __thiscall FUN_00e613f0::Sum()
{
    int total = 0;
    for (int i = 0; i < _10; ++i)
    {
        int add = _0c[i]->GetPrimitiveCount();
        total += add;
    }
    return total;
}

int __cdecl CompareStringsCaseInsensitive(int, int);

struct FUN_00e63ec0_Class
{
    int _00;
    int _04;
    int* _08;
    int _0c;
    int __thiscall FUN_00e63ec0(int a, int* out);
};

// @fnv 0x00e63ec0
int FUN_00e63ec0_Class::FUN_00e63ec0(int a, int* out)
{
    int i = 0;
    if (_0c > 0)
    {
        do
        {
            int v = _08[i * 2 + 1] & 0xfffffffe;
            if (CompareStringsCaseInsensitive(a, v))
            {
                ++i;
            }
            else
            {
                int* p = _08;
                int val = p[i * 2];
                *out = val;
                return 0;
            }
        } while (i < _0c);
    }
    return 1;
}

struct NiTMapBaseStub
{
    void RemoveAll();
};
extern MM g_memoryManager;
extern int DAT_010eec54;
struct FUN_00e7afc0_Class : NiTMapBaseStub
{
    int vtbl;
    int _04;
    int _08;
    FUN_00e7afc0_Class* __thiscall FUN_00e7afc0(int);
};
// Sets the vtable, removes all entries, frees the buffer at _08, and deallocates this object when ai has bit 0 set.
// @fnv 0x00e7afc0
FUN_00e7afc0_Class* FUN_00e7afc0_Class::FUN_00e7afc0(int aiFlags)
{
    vtbl = (int)&DAT_010eec54;
    RemoveAll();
    NiFree((void*)_08);
    if ((unsigned char)aiFlags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

namespace fnv_00e7b000 {
struct NiTMapBaseStub
{
    void* vtbl;
    void __thiscall RemoveAll();
};

struct FUN_00e7b000_Class : NiTMapBaseStub
{
    int _04;
    void* _08;
    FUN_00e7b000_Class* __thiscall FUN_00e7b000(int deleting);
};

extern char DAT_010eec54[];
extern char DAT_010eec7c[];

// Restores two vtables, calls RemoveAll on each, frees _08, and deallocates this when deleting has bit 0 set.
// @fnv 0x00e7b000
FUN_00e7b000_Class* __thiscall FUN_00e7b000_Class::FUN_00e7b000(int deleting)
{
    vtbl = DAT_010eec7c;
    RemoveAll();

    vtbl = DAT_010eec54;
    RemoveAll();

    NiFree(_08);

    if (deleting & 1)
    {
        g_memoryManager.Deallocate(this);
    }

    return this;
}
}  // namespace fnv_00e7b000

void* __cdecl _NiFree(void*);
extern int DAT_010eec4c;
extern MemoryManager _g_memoryManager;

struct FUN_00e7b230_Class
{
    void* vtbl;
    void* m_p;
    void* __thiscall FUN_00e7b230(unsigned char flags);
};

// @fnv 0x00e7b230
void* FUN_00e7b230_Class::FUN_00e7b230(unsigned char flags)
{
    this->vtbl = &DAT_010eec4c;
    _NiFree(this->m_p);
    if (flags & 1)
        _g_memoryManager.Deallocate(this);
    return this;
}

namespace fnv_00e7bb50 {
void __cdecl _NiFree(void* p);
void __cdecl _delete(void* p, unsigned int size);

struct M788
{
    void __thiscall FUN_004ed900();
};

struct FUN_00e7b550_Class
{
    void __thiscall DeleteAllItems();
};

struct FUN_00e7bb50_Class
{
    void __thiscall FUN_00e7bb50();
};

// @fnv 0x00e7bb50
void __thiscall FUN_00e7bb50_Class::FUN_00e7bb50()
{
    unsigned char* self = reinterpret_cast<unsigned char*>(this);

    for (unsigned int i = 0; i < *reinterpret_cast<unsigned short*>(self + 0x45a); ++i)
    {
        void* item = reinterpret_cast<void**>(*reinterpret_cast<void***>(self + 0x454))[i];

        if (item)
        {
            reinterpret_cast<M788*>(reinterpret_cast<unsigned char*>(item) + 0x10)->FUN_004ed900();
            _delete(item, 0x1c);
        }
    }

    void* pObject460 = *reinterpret_cast<void**>(self + 0x460);
    if (pObject460)
    {
        reinterpret_cast<FUN_00e7b550_Class*>(pObject460)->DeleteAllItems();
        _delete(pObject460, 0x144);
    }

    void* pObject464 = *reinterpret_cast<void**>(self + 0x464);
    if (pObject464)
    {
        reinterpret_cast<FUN_00e7b550_Class*>(pObject464)->DeleteAllItems();
        _delete(pObject464, 0x144);
    }

    void** items = *reinterpret_cast<void***>(self + 0x454);
    *reinterpret_cast<void**>(self + 0x450) = reinterpret_cast<void*>(&DAT_010eec74);
    _NiFree(items);
}
}  // namespace fnv_00e7bb50

extern void* const DAT_010eecac[];
void NiFree(void*);

struct NiD3DShader
{
    void* const* vtbl;
    unsigned char _padding[0x4c];
    void* m_p;
    void __thiscall FUN_00e806c0();
    void __thiscall FUN_00e7c540();
};

// @fnv 0x00e7c540
void __thiscall NiD3DShader::FUN_00e7c540()
{
    vtbl = DAT_010eecac;
    NiFree(m_p);
    FUN_00e806c0();
}

extern int DAT_0126f590;

// If DAT_0126f590 is set, calls the virtual function at offset 0x9c on p with 0 and clears DAT_0126f590 on success; returns 1 or 0.
// @fnv 0x00e7cca0
unsigned char __cdecl FUN_00e7cca0(int* pObject)
{
    if (DAT_0126f590)
    {
        if (((long(__stdcall*)(void*, int))(*((void***)(*(void***)pObject + 0x9c / 4))))(pObject, 0) < 0)
            return 0;
        DAT_0126f590 = 0;
    }
    return 1;
}

struct NiRefObject
{
    void* vtbl;
};
extern NiRefObject vftable_NiRefObject;

extern int DAT_010eeed4;
extern int DAT_010eefbc;
extern long volatile DAT_011f4400;
extern MemoryManager _g_memoryManager;
extern void*(__stdcall* DAT_00fdf1c4)(void*);

struct FUN_00e7d1b0_Class
{
    void* _00;
    void* _04;
    void* _08;
    void* _0c;
    void* _10;
    void* _14;
    void* _18;
    void* _1c;
    void* _20;
    void __thiscall FUN_00e7d1b0();
};

// @fnv 0x00e7d1b0
void FUN_00e7d1b0_Class::FUN_00e7d1b0()
{
    void* p = *(void**)((char*)this + 0x20);
    *(void**)this = &DAT_010eefbc;
    if (p)
    {
        void** vt = *(void***)p;
        typedef void(__stdcall * RelFn)(void*);
        RelFn rel = (RelFn)vt[2];
        rel(p);
        *(void**)((char*)this + 0x20) = 0;
    }
    p = *(void**)((char*)this + 0x14);
    *(void**)this = &DAT_010eeed4;
    if (p)
    {
        void** vt = *(void***)p;
        typedef void(__stdcall * RelFn)(void*);
        RelFn rel = (RelFn)vt[2];
        rel(p);
        *(void**)((char*)this + 0x14) = 0;
    }
    void* q = *(void**)((char*)this + 0x0c);
    _g_memoryManager.Deallocate(q);
    *(void**)((char*)this + 0x0c) = 0;
    *(void**)this = &vftable_NiRefObject;
    DAT_00fdf1c4((void*)&DAT_011f4400);
}

struct FUN_00e7d690_Class
{
    void __thiscall FUN_00e7d4e0();
    FUN_00e7d690_Class* __thiscall FUN_00e7d690(int flags);
};

// Calls FUN_00e7d4e0, frees this with operator delete when flags has bit 1 set, and returns this.
// @fnv 0x00e7d690
FUN_00e7d690_Class* FUN_00e7d690_Class::FUN_00e7d690(int flags)
{
    FUN_00e7d4e0();
    if (flags & 1)
        operator delete(this, 92);
    return this;
}

namespace fnv_00e7dbc0 {
extern int DAT_010eeed4;
extern int DAT_010ef184;
extern long volatile DAT_011f4400;
extern int DAT_0126f5cc;
extern int DAT_0126f600;
extern void* _g_memoryManager;

struct BSBatchRenderer__AlphaList
{
    void* Remove(void**);
};

struct NiRefObject
{
    static const int vftable;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct FUN_00e7dbc0_Class
{
    void FUN_00e7dbc0();
};

// @fnv 0x00e7dbc0
void FUN_00e7dbc0_Class::FUN_00e7dbc0()
{
    *(int*)this = (int)&DAT_010ef184;
    EnterCriticalSection(&DAT_0126f600);
    void* p = this;
    ((BSBatchRenderer__AlphaList*)&DAT_0126f5cc)->Remove(&p);
    LeaveCriticalSection(&DAT_0126f600);
    void* q = *(void**)((char*)this + 0x14);
    *(int*)this = (int)&DAT_010eeed4;
    if (q)
    {
        (*(void(__stdcall**)(void*))(*(int*)q + 8))(q);
        *(int*)((char*)this + 0x14) = 0;
    }
    void* r = *(void**)((char*)this + 0xc);
    ((MemoryManager*)&_g_memoryManager)->Deallocate(r);
    *(int*)((char*)this + 0xc) = 0;
    *(int*)this = (int)&NiRefObject::vftable;
    InterlockedDecrement(&DAT_011f4400);
}
}  // namespace fnv_00e7dbc0

struct FUN_00e7ef80_Node
{
    int _a;
    int _b;
    FUN_00e7ef80_Node* next;
    FUN_00e7ef80_Node* prev;
};
struct FUN_00e7ef80_List
{
    int _x;
    int count;
    FUN_00e7ef80_Node* head;
    FUN_00e7ef80_Node* __thiscall FUN_00e7ef80(FUN_00e7ef80_Node* node);
};
// Unlinks node from the doubly linked list, fixing neighbours and head, decrements count, clears the node's links and returns it.
// @fnv 0x00e7ef80
FUN_00e7ef80_Node* FUN_00e7ef80_List::FUN_00e7ef80(FUN_00e7ef80_Node* node)
{
    FUN_00e7ef80_Node* prev = node->next;
    FUN_00e7ef80_Node* next = node->prev;
    if (prev)
        prev->prev = next;
    if (next)
        next->next = prev;
    if (node == head)
        head = prev;
    --count;
    node->next = 0;
    node->prev = 0;
    return node;
}

class D3DRenderStateGroup
{
  public:
    ~D3DRenderStateGroup();
};

void __cdecl _FUN_00aa1490(void* p, int size);

// @fnv 0x00e7f750
void __cdecl DestroyArrayElements(void* p)
{
    if (p)
    {
        unsigned char* base = static_cast<unsigned char*>(p);
        int count = *reinterpret_cast<int*>(base - 4);
        unsigned char* current = base + (count + count * 4) * sizeof(int);

        --count;
        if (count >= 0)
        {
            do
            {
                current -= 0x14;
                reinterpret_cast<D3DRenderStateGroup*>(current)->~D3DRenderStateGroup();
                --count;
            } while (count >= 0);
        }

        _FUN_00aa1490(base - 4, 0x14);
    }
}

struct FUN_00e611d0_Object
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    int unk08;
    int unk0C;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    unsigned char unk14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    int unk18;
};

struct FUN_00c85750_Result
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

FUN_00c85750_Result* __cdecl FUN_00c85750();
void __cdecl AppendIndexSequence(int, int, int, int, int);
void __cdecl AppendIndices(int, int, int, int, int);

// Switches on object->unk14: case 0 calls AppendIndexSequence with object fields and value; case 1 calls AppendIndices when unk00 is 3 or 4.
// @fnv 0x00e611d0
void __cdecl FUN_00e611d0(FUN_00e611d0_Object* object, int value)
{
    switch (object->unk14)
    {
    case 0: {
        FUN_00c85750_Result* result = FUN_00c85750();
        AppendIndexSequence(object->unk00, object->unk08, object->unk0C, value, result->unk10);
        break;
    }

    case 1: {
        if ((static_cast<unsigned int>(object->unk00) - 3U) <= 1U)
        {
            AppendIndices(object->unk00, object->unk18, object->unk08, 0, value);
        }
        break;
    }
    }
}

struct FUN_00e61230_Buffer
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
};
struct FUN_00e61230_Receiver
{
    virtual void unknown0() = 0;
    virtual void unknown1() = 0;
    virtual void unknown2() = 0;
    virtual void unknown3() = 0;
    virtual void begin(void* value, unsigned int mode, FUN_00e61230_Buffer* buffer) = 0;
    virtual void end(FUN_00e61230_Buffer* buffer) = 0;
};
extern "C" void __cdecl FUN_00e611d0(FUN_00e61230_Buffer* buffer, unsigned int stage);
// Calls receiver->begin with value and mode 1, runs FUN_00e611d0 on the buffer with stage, then calls receiver->end.
// @fnv 0x00e61230
void __cdecl RunReceiverStage(FUN_00e61230_Receiver* receiver, void* value, unsigned int stage)
{
    FUN_00e61230_Buffer buffer;
    receiver->begin(value, 1, &buffer);
    FUN_00e611d0(&buffer, stage);
    receiver->end(&buffer);
}

struct E65000Entry
{
    float m_fValue;
    int m_iData;
};

// File-static helper with a compiler-chosen register convention.
// @fnv 0x00e65000
static __declspec(noinline) float FUN_00e65000(E65000Entry* pkEntries, int iIndex, float fValue)
{
    float fOld = pkEntries[iIndex].m_fValue;
    pkEntries[iIndex].m_fValue = fValue;
    return fOld;
}

float E65000Swap(E65000Entry* pkEntries, int iIndex, float fValue)
{
    return FUN_00e65000(pkEntries, iIndex, fValue);
}

class E673F0Geometry
{
  public:
    int unk00;
    int unk04;
    char m_cPrimitiveType;
    char unk09;
    char unk0A;
    char unk0B;
    int unk0C;
    int m_iIndexCount;
    int unk14;
    int unk18;
    int m_iVertexCount;

    int GetPrimitiveCount();
};

// @fnv 0x00e673f0
int E673F0Geometry::GetPrimitiveCount()
{
    int iCount = m_iIndexCount ? m_iIndexCount : m_iVertexCount;
    switch (m_cPrimitiveType)
    {
    case 1:
        return iCount / 3;
    default:
        return 0;
    }
}

struct IndexSource_e67420
{
    int unk00;
    int unk04;
    char m_cType;
    char unk09;
    char unk0a;
    char unk0b;
    unsigned short* m_pusIndices;
    int m_iShortCount;
    int unk14;
    unsigned int* m_puiIndices;
    int m_iIntCount;

    bool FUN_00e67420(unsigned int iIndex, unsigned int* p0, unsigned int* p1, unsigned int* p2);
};

// @fnv 0x00e67420
bool IndexSource_e67420::FUN_00e67420(unsigned int iIndex, unsigned int* puiIndex0, unsigned int* puiIndex1,
                                      unsigned int* puiIndex2)
{
    if (m_iShortCount)
    {
        switch (m_cType)
        {
        case 1:
            *puiIndex0 = m_pusIndices[iIndex * 3];
            *puiIndex1 = m_pusIndices[iIndex * 3 + 1];
            *puiIndex2 = m_pusIndices[iIndex * 3 + 2];
            return true;
        case 2:
            *puiIndex0 = m_pusIndices[iIndex];
            *puiIndex1 = m_pusIndices[iIndex + 1];
            *puiIndex2 = m_pusIndices[iIndex + 2];
            return true;
        }
    }
    else if (m_iIntCount)
    {
        switch (m_cType)
        {
        case 1:
            *puiIndex0 = m_puiIndices[iIndex * 3];
            *puiIndex1 = m_puiIndices[iIndex * 3 + 1];
            *puiIndex2 = m_puiIndices[iIndex * 3 + 2];
            return true;
        case 2:
            *puiIndex0 = m_puiIndices[iIndex];
            *puiIndex1 = m_puiIndices[iIndex + 1];
            *puiIndex2 = m_puiIndices[iIndex + 2];
            return true;
        }
    }
    *puiIndex0 = 0xffffffff;
    *puiIndex1 = 0xffffffff;
    *puiIndex2 = 0xffffffff;
    return false;
}

class FUN_00e67660_cls;
class FnvEnt67;
class FnvNode67;
class FnvOwner67;

class FnvOwner67
{
  public:
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
    FnvEnt67* m_30;
};

class FnvEnt67
{
  public:
    FnvOwner67* m_00;
    int unk04;
    int unk08;
    FnvNode67* m_0c;
};

class FnvNode67
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FnvEnt67* m_18;
    int unk1c;
    int unk20;
    int unk24;
    FnvEnt67* m_28;
    int unk2c;
    int unk30;
    int unk34;
    FnvEnt67* m_38;
    int unk3c;
    float m_40;
    int m_44;
    int Callee00e63af0(int a2, FUN_00e67660_cls* t, int* out);
};

class FUN_00e67660_cls
{
  public:
    int unk00;
    int m_04;
    int unk08;
    int m_0c;
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
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    int unk9a8;
    int unk9ac;
    int unk9b0;
    int unk9b4;
    int unk9b8;
    int unk9bc;
    int unk9c0;
    int unk9c4;
    int unk9c8;
    int unk9cc;
    int unk9d0;
    int unk9d4;
    int unk9d8;
    int unk9dc;
    int unk9e0;
    int unk9e4;
    int unk9e8;
    int unk9ec;
    int unk9f0;
    int unk9f4;
    int unk9f8;
    int unk9fc;
    int unka00;
    int unka04;
    int unka08;
    int unka0c;
    int unka10;
    int unka14;
    int unka18;
    int unka1c;
    int unka20;
    int unka24;
    int unka28;
    int unka2c;
    int unka30;
    int unka34;
    int unka38;
    int unka3c;
    int unka40;
    int unka44;
    int unka48;
    int unka4c;
    int unka50;
    int unka54;
    int unka58;
    int unka5c;
    int unka60;
    int unka64;
    int unka68;
    int unka6c;
    int unka70;
    int unka74;
    int unka78;
    int unka7c;
    int unka80;
    int unka84;
    int unka88;
    int unka8c;
    int unka90;
    int unka94;
    int unka98;
    int unka9c;
    int unkaa0;
    int unkaa4;
    int unkaa8;
    int unkaac;
    int unkab0;
    int unkab4;
    int unkab8;
    int unkabc;
    int unkac0;
    int unkac4;
    int unkac8;
    int unkacc;
    int unkad0;
    int unkad4;
    int unkad8;
    int unkadc;
    int unkae0;
    int unkae4;
    int unkae8;
    int unkaec;
    int unkaf0;
    int unkaf4;
    int unkaf8;
    int unkafc;
    int unkb00;
    int unkb04;
    int unkb08;
    int unkb0c;
    int unkb10;
    int unkb14;
    int unkb18;
    int unkb1c;
    int unkb20;
    int unkb24;
    int unkb28;
    int unkb2c;
    int unkb30;
    int unkb34;
    int unkb38;
    int unkb3c;
    int unkb40;
    int unkb44;
    int unkb48;
    int unkb4c;
    int unkb50;
    int unkb54;
    int unkb58;
    int unkb5c;
    int unkb60;
    int unkb64;
    int unkb68;
    int unkb6c;
    int unkb70;
    int unkb74;
    int unkb78;
    int unkb7c;
    int unkb80;
    int unkb84;
    int unkb88;
    int unkb8c;
    int unkb90;
    int unkb94;
    int unkb98;
    int unkb9c;
    int unkba0;
    int unkba4;
    int unkba8;
    int unkbac;
    int unkbb0;
    int unkbb4;
    int unkbb8;
    int unkbbc;
    int unkbc0;
    int unkbc4;
    int unkbc8;
    int unkbcc;
    int unkbd0;
    int unkbd4;
    int unkbd8;
    int unkbdc;
    int unkbe0;
    int unkbe4;
    int unkbe8;
    int unkbec;
    int unkbf0;
    int unkbf4;
    int unkbf8;
    int unkbfc;
    int unkc00;
    int unkc04;
    int unkc08;
    int unkc0c;
    int unkc10;
    int unkc14;
    int unkc18;
    int unkc1c;
    int unkc20;
    int unkc24;
    int unkc28;
    int unkc2c;
    int unkc30;
    int unkc34;
    int unkc38;
    int unkc3c;
    int unkc40;
    int unkc44;
    int unkc48;
    int unkc4c;
    int unkc50;
    int unkc54;
    int unkc58;
    int unkc5c;
    int unkc60;
    int unkc64;
    int unkc68;
    int unkc6c;
    int unkc70;
    int unkc74;
    int unkc78;
    int unkc7c;
    int unkc80;
    int unkc84;
    int unkc88;
    int unkc8c;
    int unkc90;
    int unkc94;
    int unkc98;
    int unkc9c;
    int unkca0;
    int unkca4;
    int unkca8;
    int unkcac;
    int unkcb0;
    int unkcb4;
    int unkcb8;
    int unkcbc;
    int unkcc0;
    int unkcc4;
    int unkcc8;
    int unkccc;
    int unkcd0;
    int unkcd4;
    int unkcd8;
    int unkcdc;
    int unkce0;
    int unkce4;
    int unkce8;
    int unkcec;
    int unkcf0;
    int unkcf4;
    int unkcf8;
    int unkcfc;
    int unkd00;
    int unkd04;
    int unkd08;
    int unkd0c;
    int unkd10;
    int unkd14;
    int unkd18;
    int unkd1c;
    int unkd20;
    int unkd24;
    int unkd28;
    int unkd2c;
    int unkd30;
    int unkd34;
    int unkd38;
    int unkd3c;
    int unkd40;
    int unkd44;
    int unkd48;
    int unkd4c;
    int unkd50;
    int unkd54;
    int unkd58;
    int unkd5c;
    int unkd60;
    int unkd64;
    int unkd68;
    int unkd6c;
    int unkd70;
    int unkd74;
    int unkd78;
    int unkd7c;
    int unkd80;
    int unkd84;
    int unkd88;
    int unkd8c;
    int unkd90;
    int unkd94;
    int unkd98;
    int unkd9c;
    int unkda0;
    int unkda4;
    int unkda8;
    int unkdac;
    int unkdb0;
    int unkdb4;
    int unkdb8;
    int unkdbc;
    int unkdc0;
    int unkdc4;
    int unkdc8;
    int unkdcc;
    int unkdd0;
    int unkdd4;
    int unkdd8;
    int unkddc;
    FnvNode67* m_de0[100];
    int FUN_00e67660(FnvNode67* a1, int a2, int* a3, FnvEnt67** a4);
};

extern float DAT_0104da48;

// @fnv 0x00e67660
int FUN_00e67660_cls::FUN_00e67660(FnvNode67* apNode, int aiArg, int* apiCount, FnvEnt67** apOutEntry)
{
    int iResult = 0;
    int i = 0;
    FnvEnt67** p = &apNode->m_18;
    for (; i < 3; i++, p += 4)
    {
        FnvEnt67* e = *p;
        FnvNode67* n = e->m_0c;
        int st = n->m_44;
        if (st == 0)
        {
            st = n->Callee00e63af0(aiArg, this, &m_04);
            n->m_44 = st;
            if (st == 1)
            {
                iResult = FUN_00e67660(n, aiArg, apiCount, apOutEntry);
                if (iResult == 2)
                {
                    break;
                }
                continue;
            }
            if (st == 4)
            {
                iResult = 2;
                break;
            }
        }
        if (st == 2)
        {
            e->m_00->m_30 = e;
            (*apiCount)++;
            *apOutEntry = e;
        }
    }
    apNode->m_40 = DAT_0104da48;
    if (m_0c >= 100)
    {
        return 2;
    }
    m_de0[m_0c] = apNode;
    m_0c++;
    return iResult;
}

void* __cdecl _memmove(void*, const void*, unsigned);
struct CopyDesc
{
    int format, type;
    unsigned usage;
    int pool, multisample;
    unsigned quality, width, height;
};
struct CopyLock
{
    unsigned pitch;
    void* bits;
};
struct CopySurface
{
    virtual void __stdcall vf0() = 0;
    virtual void __stdcall vf1() = 0;
    virtual void __stdcall vf2() = 0;
    virtual void __stdcall vf3() = 0;
    virtual void __stdcall vf4() = 0;
    virtual void __stdcall vf5() = 0;
    virtual void __stdcall vf6() = 0;
    virtual void __stdcall vf7() = 0;
    virtual void __stdcall vf8() = 0;
    virtual void __stdcall vf9() = 0;
    virtual void __stdcall vf10() = 0;
    virtual void __stdcall vf11() = 0;
    virtual long __stdcall GetDesc(CopyDesc*) = 0;
    virtual long __stdcall LockRect(CopyLock*, void*, unsigned) = 0;
    virtual long __stdcall UnlockRect() = 0;
};
struct CopyPixels
{
    int unk00;
    int unk04;
    int unk08;
    int format;
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
    unsigned char* pixels;
    unsigned* widths;
    unsigned* heights;
    unsigned* offsets;
    unsigned levels;
    unsigned bytesPerPixel;
};
const char* __cdecl GetHResultName(long);
void __cdecl FUN_00a29680(const char*, ...);
// Locks a surface level, copies pixel rows from the source buffer (clamped to the surface height and pitch), then unlocks the surface.
// @fnv 0x00e68150
void __cdecl FUN_00e68150(CopyPixels* pSourcePixels, unsigned level, CopySurface* surface, unsigned face)
{
    CopyDesc desc;
    long hr = surface->GetDesc(&desc);
    if (hr < 0)
    {
        FUN_00a29680("NiDX9SourceTextureData::CopyDataToSurfaceLevel> Failed GetDesc - %s", GetHResultName(hr));
        return;
    }
    CopyLock locked;
    hr = surface->LockRect(&locked, 0, 0);
    if (hr < 0)
    {
        FUN_00a29680("NiDX9SourceTextureData::CopyDataToSurfaceLevel> Failed GetSurfaceLevel - %s", GetHResultName(hr));
        return;
    }
    unsigned width = pSourcePixels->widths[level];
    unsigned pitch = locked.pitch;
    unsigned rowSize = pSourcePixels->bytesPerPixel * width;
    unsigned height = pSourcePixels->heights[level];
    if (height > desc.height)
        height = desc.height;
    if (pSourcePixels->format >= 4 && pSourcePixels->format <= 6)
    {
        pitch >>= 2;
        if (desc.format == 0x31545844)
            rowSize = ((width + 3) & 0x0ffffffcu) >> 1;
        else
            rowSize = (width + 3) & 0x0ffffffcu;
        height = (height + 3) & 0x0ffffffcu;
    }
    if (rowSize != pitch)
    {
        unsigned copySize = pitch;
        if (rowSize <= pitch)
            copySize = rowSize;
        unsigned char* src = pSourcePixels->pixels + pSourcePixels->offsets[level] +
                             pSourcePixels->offsets[pSourcePixels->levels] * face;
        unsigned char* dst = (unsigned char*)locked.bits;
        for (unsigned i = 0; i < height; ++i)
        {
            _memmove(dst, src, copySize);
            dst += locked.pitch;
            src += rowSize;
        }
    }
    else
    {
        _memmove(locked.bits,
                 pSourcePixels->pixels + pSourcePixels->offsets[level] +
                     pSourcePixels->offsets[pSourcePixels->levels] * face,
                 rowSize * height);
    }
    surface->UnlockRect();
}

struct TexDevice
{
    virtual void __stdcall vf0() = 0;
    virtual void __stdcall vf1() = 0;
    virtual void __stdcall vf2() = 0;
    virtual void __stdcall vf3() = 0;
    virtual void __stdcall vf4() = 0;
    virtual void __stdcall vf5() = 0;
    virtual void __stdcall vf6() = 0;
    virtual void __stdcall vf7() = 0;
    virtual void __stdcall vf8() = 0;
    virtual void __stdcall vf9() = 0;
    virtual void __stdcall vf10() = 0;
    virtual void __stdcall vf11() = 0;
    virtual void __stdcall vf12() = 0;
    virtual void __stdcall vf13() = 0;
    virtual void __stdcall vf14() = 0;
    virtual void __stdcall vf15() = 0;
    virtual void __stdcall vf16() = 0;
    virtual void __stdcall vf17() = 0;
    virtual void __stdcall vf18() = 0;
    virtual void __stdcall vf19() = 0;
    virtual void __stdcall vf20() = 0;
    virtual void __stdcall vf21() = 0;
    virtual void __stdcall vf22() = 0;
    virtual long __stdcall CreateTexture(unsigned, unsigned, unsigned, unsigned, int, int, void**, void*) = 0;
};
struct TexRenderer
{
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5() = 0;
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12() = 0;
    virtual void vf13() = 0;
    virtual void vf14() = 0;
    virtual void vf15() = 0;
    virtual void vf16() = 0;
    virtual void vf17() = 0;
    virtual void vf18() = 0;
    virtual void vf19() = 0;
    virtual void vf20() = 0;
    virtual void vf21() = 0;
    virtual void vf22() = 0;
    virtual void vf23() = 0;
    virtual void vf24() = 0;
    virtual void vf25() = 0;
    virtual void vf26() = 0;
    virtual void vf27() = 0;
    virtual void vf28() = 0;
    virtual void vf29() = 0;
    virtual void vf30() = 0;
    virtual void vf31() = 0;
    virtual void vf32() = 0;
    virtual void vf33() = 0;
    virtual void vf34() = 0;
    virtual void vf35() = 0;
    virtual void vf36() = 0;
    virtual void vf37() = 0;
    virtual void vf38() = 0;
    virtual void vf39() = 0;
    virtual unsigned Flags() = 0;
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
    TexDevice* device;
};
struct TextureInput
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
    unsigned levels;
};
struct TextureOwner
{
    int unk00;
    int unk04;
    int unk08;
    unsigned width, height;
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
    TexRenderer* renderer;
    void* texture;
    unsigned levels;
    bool unk6c, mipmap;
    unsigned unk70, unk74, skip;
    bool CreateTextureFromInput(TextureInput*, int);
};
extern int DAT_0126efc0;
extern bool DAT_0126f0d0;
const char* __cdecl GetHResultName(long);
void __cdecl FUN_00a29680(const char*, ...);
inline bool IsPowerOfTwo(unsigned n)
{
    if (!n)
        return false;
    return (n & (n - 1)) == 0;
}
// Clamps mip levels by power-of-two size and renderer flags, halves width/height per dropped level, then creates a texture via the device and stores it.
// @fnv 0x00e682b0
bool TextureOwner::CreateTextureFromInput(TextureInput* input, int format)
{
    if ((!IsPowerOfTwo(width) || !IsPowerOfTwo(height)) && !(renderer->Flags() & 8))
        levels = 1;
    else
        levels = input->levels;
    mipmap = levels != 1;
    unsigned dropped = DAT_0126efc0;
    if (dropped > levels - 1)
        dropped = levels - 1;
    for (unsigned i = 0; i < dropped; ++i)
    {
        if (width & 1)
            ++width;
        width >>= 1;
        if (height & 1)
            ++height;
        height >>= 1;
    }
    skip = dropped;
    TexDevice* device = renderer->device;
    void* created = 0;
    long hr = device->CreateTexture(width, height, levels - dropped, DAT_0126f0d0 ? 512 : 0, format,
                                    DAT_0126f0d0 ? 0 : 1, &created, 0);
    if (hr >= 0 && created)
    {
        texture = created;
        return true;
    }
    FUN_00a29680(
        "NiDX9SourceTextureData::CreateSurfFromRendererData> FAILED to create texture of format: 0x%x, D3D error: %s",
        format, GetHResultName(hr));
    texture = 0;
    return false;
}

struct E68760Program
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int m_uiID;
};

template <class T> class E68760Pointer
{
  public:
    T* m_pObject;

    bool operator!=(const T* pObject) const
    {
        return m_pObject != pObject;
    }
    E68760Pointer& operator=(T* pObject);
};

class E68760Pass
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
    E68760Pointer<E68760Program> m_spShaderProgram;
    int unk78;
    int unk7C;
    unsigned int m_uiProgramID;

    bool SetProgram(E68760Program* pkProgram);
};

// Stores the program's ID and pointer, returning true if either the ID or the pointer changed.
// @fnv 0x00e68760
bool E68760Pass::SetProgram(E68760Program* pkProgram)
{
    bool bChanged = false;
    if (pkProgram)
    {
        if (m_uiProgramID != pkProgram->m_uiID)
            bChanged = true;
        m_uiProgramID = pkProgram->m_uiID;
        if (m_spShaderProgram != pkProgram)
        {
            m_spShaderProgram = pkProgram;
            bChanged = true;
        }
    }
    return bChanged;
}

// SetValue: thiscall setter, one stack dword stored to this+0x64.
struct FUN_00e687e0_cls
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
    unsigned int m_i64;
    void __thiscall SetValue(unsigned int value);
};

// @fnv 0x00e687e0
void FUN_00e687e0_cls::SetValue(unsigned int value)
{
    m_i64 = value;
}

class E68830RefObject
{
  public:
    virtual ~E68830RefObject();
    virtual void DeleteThis();

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};

class E68830Base
{
  public:
    virtual ~E68830Base();
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
};

class FUN_00e68830 : public E68830Base
{
  public:
    NiPointer<E68830RefObject> m_spTransformData;

    virtual ~FUN_00e68830() throw();
};

// Destructor for FUN_00e68830; the body is empty and the compiler-generated member cleanup handles the NiPointer member.
// @fnv 0x00e68830
FUN_00e68830::~FUN_00e68830() throw()
{}

struct CubeMapSource
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
    virtual int __stdcall v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual int __stdcall GetSurfaceLevel(unsigned int i, int* out);
};
struct CubeMapSurface
{
    virtual void v00();
    virtual void v01();
    virtual void __stdcall Release();
};
extern "C" void __cdecl FUN_00e68150(int a, unsigned int b, int c, int d);
extern "C" void* __cdecl GetHResultName(int r);
extern "C" void __cdecl FUN_00a29680(const char* fmt, unsigned int i, void* s);
struct FUN_00e68870_arg
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
    unsigned int m_60;
};
struct FUN_00e68870_cls
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
    CubeMapSource* m_64;
    unsigned int m_68;
    int unk6C;
    int unk70;
    int unk74;
    unsigned int m_78;
    void __thiscall FUN_00e68870(FUN_00e68870_arg* a1);
};
// @fnv 0x00e68870
void FUN_00e68870_cls::FUN_00e68870(FUN_00e68870_arg* apSourceData)
{
    int out;
    if (m_64 == 0)
    {
        return;
    }
    if (m_64->v0A() == 5)
    {
        return;
    }
    if (m_64->v0A() == 4)
    {
        return;
    }
    CubeMapSource* src = m_64;
    m_68 = apSourceData->m_60;
    unsigned int i = 0;
    if (m_68 - m_78 != 0)
    {
        do
        {
            int r = src->GetSurfaceLevel(i, &out);
            if (r < 0)
            {
                FUN_00a29680("NiDX9SourceTextureData::CopyDataToSurface> Failed GetSurfaceLevel (%d)- %s", i,
                             GetHResultName(r));
                return;
            }
            FUN_00e68150(reinterpret_cast<int>(apSourceData), m_78 + i, out, 0);
            reinterpret_cast<CubeMapSurface*>(out)->Release();
        } while (++i < m_68 - m_78);
    }
}

namespace fnv_00e68920 {
struct FUN_00e68920_Surface
{
    virtual void unk00();
    virtual void unk04();
    virtual unsigned long __stdcall Release();
};
struct FUN_00e68920_Tex
{
    virtual long __stdcall unk00();
    virtual long __stdcall unk04();
    virtual long __stdcall unk08();
    virtual long __stdcall unk0C();
    virtual long __stdcall unk10();
    virtual long __stdcall unk14();
    virtual long __stdcall unk18();
    virtual long __stdcall unk1C();
    virtual long __stdcall unk20();
    virtual long __stdcall unk24();
    virtual int __stdcall GetType();
    virtual long __stdcall unk2C();
    virtual long __stdcall unk30();
    virtual long __stdcall unk34();
    virtual long __stdcall unk38();
    virtual long __stdcall unk3C();
    virtual long __stdcall unk40();
    virtual long __stdcall unk44();
    virtual long __stdcall GetSurfaceLevel(unsigned int level, FUN_00e68920_Surface** ppSurf);
};
int __cdecl FUN_00e683d0(int a, int b, FUN_00e68920_Surface* c, int d);
int __cdecl GetHResultName(int hr);
int __cdecl FUN_00a29680(const char* fmt, unsigned int level, int code);
struct FUN_00e68920_cls
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
    FUN_00e68920_Tex* m_pTex;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int m_78;
    void __thiscall FUN_00e68920(int a1);
};
// Copies renderer data into each surface level of m_pTex from m_78 up to unk68, skipping null or type 4/5 textures and logging failed GetSurfaceLevel calls.
// @fnv 0x00e68920
void __thiscall FUN_00e68920_cls::FUN_00e68920(int a1)
{
    if (m_pTex == 0)
        return;
    if (m_pTex->GetType() == 5)
        return;
    if (m_pTex->GetType() == 4)
        return;
    FUN_00e68920_Tex* tex = m_pTex;
    unsigned int i = 0;
    if (unk68 - m_78 == 0)
        return;
    FUN_00e68920_Surface* pSurface;
    do
    {
        long hr = tex->GetSurfaceLevel(i, &pSurface);
        if (hr < 0)
        {
            FUN_00a29680("NiDX9SourceTextureData::CopyRendererDataToSurface> Failed GetSurfaceLevel (%d)- %s", i,
                         GetHResultName(hr));
            return;
        }
        FUN_00e683d0(a1, m_78 + i, pSurface, 0);
        pSurface->Release();
        ++i;
    } while (i < (unsigned int)(unk68 - m_78));
}
}  // namespace fnv_00e68920

namespace fnv_00e689d0 {
struct TextureResource
{
    unsigned int m_header00;
    unsigned int m_header04;
    unsigned int m_header08;
    unsigned int m_header0c;
    unsigned int m_uiContentCount;
};
struct SourcePixels
{
    unsigned int m_unknown00;
    unsigned int m_unknown04;
    unsigned int m_unknown08;
    unsigned int m_unknown0c;
    unsigned int m_unknown10;
    unsigned int m_unknown14;
    unsigned int m_unknown18;
    unsigned int m_unknown1c;
    unsigned int m_unknown20;
    unsigned int m_unknown24;
    unsigned int m_unknown28;
    unsigned int m_unknown2c;
    unsigned int m_unknown30;
    unsigned int m_unknown34;
    unsigned int m_unknown38;
    unsigned int m_unknown3c;
    unsigned int m_unknown40;
    unsigned int m_unknown44;
    unsigned int m_unknown48;
    TextureResource* m_resource;
    unsigned int m_unknown50;
    unsigned int m_unknown54;
    unsigned int m_unknown58;
    unsigned int m_unknown5c;
    unsigned int m_unknown60;
    unsigned int m_unknown64;
    unsigned int m_revision;
};
struct TextureOwner
{
    unsigned int m_unknown00;
    unsigned int m_unknown04;
    unsigned int m_unknown08;
    unsigned int m_unknown0c;
    unsigned int m_unknown10;
    unsigned int m_unknown14;
    unsigned int m_unknown18;
    unsigned int m_unknown1c;
    unsigned int m_unknown20;
    unsigned int m_unknown24;
    unsigned int m_unknown28;
    unsigned int m_unknown2c;
    unsigned int m_unknown30;
    unsigned int m_unknown34;
    unsigned int m_unknown38;
    SourcePixels* m_pixels;
};
struct CreatedTexture
{
    virtual void v0();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
};
struct TextureBuilder
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual CreatedTexture* Create(SourcePixels*, NiPixelFormat&, SourcePixels*, bool);
};
extern TextureBuilder* __cdecl FUN_00a76640();
struct TrackedResource
{
    TextureResource* current;
    void FUN_00a5f860(TextureResource* resource);
};
struct TextureUpdate_00e689d0 : public NiDX9SourceCubeMapData_S
{
    TrackedResource m_resource;
    unsigned int m_meta78;
    unsigned int m_revision7c;
    unsigned int m_state80;
    void FUN_00e68870(CreatedTexture* result);
    void UpdateTexture();
};
// @fnv 0x00e689d0
void TextureUpdate_00e689d0::UpdateTexture()
{
    if (m_b6c)
        return;
    TextureOwner* owner = reinterpret_cast<TextureOwner*>(unk08);
    SourcePixels* pixels = owner->m_pixels;
    if (!pixels)
        return;
    TextureResource* resource = pixels->m_resource;
    bool changed = false;
    if (resource)
    {
        if (m_state80 != resource->m_uiContentCount)
            changed = true;
        bool resourceChanged = m_resource.current != resource;
        m_state80 = resource->m_uiContentCount;
        if (resourceChanged)
        {
            m_resource.FUN_00a5f860(resource);
            changed = true;
        }
    }
    if (pixels->m_revision == m_revision7c && !changed)
        return;
    CreatedTexture* result = FUN_00a76640()->Create(pixels, m_kPixelFormat, pixels, m_bHasTexture);
    m_revision7c = pixels->m_revision;
    if (unk08)
        FUN_00e68870(result);
    if (result)
    {
        InterlockedIncrement(&result->m_uiRefCount);
        if (InterlockedDecrement(&result->m_uiRefCount) == 0)
            result->DeleteThis();
    }
}
}  // namespace fnv_00e689d0

extern "C" char DAT_010ed37c[];

void __cdecl FUN_00aa1460(void* pObject, unsigned int value);

struct FUN_00e68ea0_held
{
    virtual void v00();
    virtual void v04();
    long m_iRefCount;
};

struct FUN_00e68ea0_cls
{
    void* m_vptr;
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
    FUN_00e68ea0_held* m_74;
    int unk78;
    int unk7c;
    int unk80;

    void BaseCleanup();

    FUN_00e68ea0_cls* FUN_00e68ea0(unsigned char acFlags);
};

// @fnv 0x00e68ea0
FUN_00e68ea0_cls* FUN_00e68ea0_cls::FUN_00e68ea0(unsigned char acFlags)
{
    *(void* volatile*)&m_vptr = DAT_010ed37c;
    FUN_00e68ea0_held* pRefCounted = *(FUN_00e68ea0_held* volatile*)&m_74;
    if (pRefCounted != 0)
    {
        if (InterlockedDecrement(&pRefCounted->m_iRefCount) == 0)
        {
            pRefCounted->v04();
        }
    }
    BaseCleanup();
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0x84);
    }
    return this;
}

void __cdecl NiFree(void* pvMem);
void __cdecl BE7B040SizedFree(void* pvMem, unsigned int uiSize);

struct BE7B040Value
{
    static void operator delete(void* pvMem, unsigned int uiSize)
    {
        BE7B040SizedFree(pvMem, uiSize);
    }

    int m_aiData00;
    int m_aiData04;
    int m_aiData08;
    int m_aiData0C;
    int m_aiData10;
    int m_aiData14;
    int m_aiData18;
    int m_aiData1C;
    int m_aiData20;
    int m_aiData24;
    int m_aiData28;
    int m_aiData2C;
    int m_aiData30;
    int m_aiData34;
    int m_aiData38;
    int m_aiData3C;
    int m_aiData40;
    int m_aiData44;
};

template <class TKEY, class TVAL> struct BE7B040MapItem
{
    BE7B040MapItem* m_pkNext;
    TKEY m_key;
    TVAL m_val;
};

template <class TKEY, class TVAL> class BE7B040MapBase
{
  public:
    typedef BE7B040MapItem<TKEY, TVAL> Item;

    __forceinline virtual ~BE7B040MapBase()
    {
        RemoveAll();
        NiFree(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(TKEY key) const;

    void RemoveAll();

    Item* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }
    void GetNext(Item*& pkPos, TKEY& key, TVAL& val) const
    {
        Item* pkItem = pkPos;
        key = pkItem->m_key;
        val = pkItem->m_val;
        if (pkItem->m_pkNext)
        {
            pkPos = pkItem->m_pkNext;
            return;
        }
        unsigned int i = KeyToHashIndex(pkItem->m_key);
        for (++i; i < m_uiHashSize; i++)
        {
            pkPos = m_ppkHashTable[i];
            if (pkPos)
                return;
        }
        pkPos = 0;
    }

    unsigned int m_uiHashSize;
    Item** m_ppkHashTable;
    unsigned int m_uiCount;
};

template <class TKEY, class TVAL> class BE7B040Map : public BE7B040MapBase<TKEY, TVAL>
{
  public:
    __forceinline virtual ~BE7B040Map()
    {
        this->RemoveAll();
    }
};

class FUN_00e7b040_cls
{
  public:
    ~FUN_00e7b040_cls() throw();

    int unk00;
    int unk04;
    BE7B040Map<unsigned int, BE7B040Value*> m_kValues;
};

// Destructor that iterates the m_kValues map and deletes each stored BE7B040Value pointer.
// @fnv 0x00e7b040
FUN_00e7b040_cls::~FUN_00e7b040_cls() throw()
{
    BE7B040MapItem<unsigned int, BE7B040Value*>* pkPos = m_kValues.GetFirstPos();
    while (pkPos)
    {
        unsigned int uiKey;
        BE7B040Value* pkValue;
        m_kValues.GetNext(pkPos, uiKey, pkValue);
        delete pkValue;
    }
}

struct Entry
{
    unsigned int identifier;
    unsigned int subIdentifier;
    unsigned int properties;
    unsigned int group;
    unsigned int FUN_00e7af60(unsigned int accumulated);
};
struct EntryArray
{
    void* vtable;
    Entry** items;
    unsigned short capacity;
    unsigned short count;
    unsigned short elementSize;
    unsigned short growBy;
};
struct Owner
{
    EntryArray& entries()
    {
        return *reinterpret_cast<EntryArray*>(reinterpret_cast<char*>(this) + 0x450);
    }
    Entry* FUN_00e7b190(unsigned int group, unsigned int identifier, unsigned int subIdentifier,
                        unsigned int* accumulated);
};
// Scans the entry array for an item matching group, identifier and subIdentifier, accumulates its value and returns the last match.
// @fnv 0x00e7b190
Entry* Owner::FUN_00e7b190(unsigned int group, unsigned int identifier, unsigned int subIdentifier,
                           unsigned int* puiAccumulated)
{
    Entry* match = 0;
    for (unsigned int index = 0; index < entries().count; ++index)
    {
        Entry* item = entries().items[index];
        if (item && item->group == group && item->identifier == identifier && item->subIdentifier == subIdentifier)
        {
            match = item;
            *puiAccumulated = item->FUN_00e7af60(*puiAccumulated);
        }
    }
    return match;
}

struct FUN_00e7b550_cls
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
    void FUN_00e7b040();
    void FUN_00b71300();
    void DeleteAllItems();
};

struct ListNode_b9541
{
    ListNode_b9541* next;
    int unk04;
    FUN_00e7b550_cls* item;
};

// @fnv 0x00e7b550
void __thiscall FUN_00e7b550_cls::DeleteAllItems()
{
    ListNode_b9541* node = *(ListNode_b9541**)((char*)this + 0x134);
    if (node != 0)
    {
        do
        {
            FUN_00e7b550_cls* item = node->item;
            FUN_00e7b550_cls** pp = &node->item;
            node = node->next;
            if (*pp != 0)
            {
                item->FUN_00e7b040();
                operator delete(item, 0x18);
            }
        } while (node != 0);
    }
    ((FUN_00e7b550_cls*)((char*)this + 0x134))->FUN_00b71300();
}

class BE7BBF0Source
{
  public:
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObject);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall GetDesc(void* pDesc);
    virtual unsigned int __stdcall GetCount();
};

class BE7BBF0Item
{
  public:
    static void* operator new(unsigned int uiSize);

    BE7BBF0Item(BE7BBF0Source* pkSource, unsigned int uiIndex, void* pvContext) throw();

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
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
};

template <class T> class BE7BBF0Array
{
  public:
    virtual ~BE7BBF0Array();
    void SetSize(unsigned int uiMaxSize);

    void SetAt(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != T(0))
                m_usESize++;
        }
        else
        {
            if (element != T(0))
            {
                if (m_pBase[uiIndex] == T(0))
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != T(0))
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }

    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

class FUN_00e7bbf0_cls
{
  public:
    void BuildItemsFromSource(BE7BBF0Source* pkSource, void* pvContext);

    unsigned int m_uiCount;
    BE7BBF0Array<BE7BBF0Item*> m_kUnsortedGeometryList;
};

// Stores the source's count and fills the array with a new item for each index, passing the source and context.
// @fnv 0x00e7bbf0
void FUN_00e7bbf0_cls::BuildItemsFromSource(BE7BBF0Source* pkSource, void* pvContext)
{
    m_uiCount = pkSource->GetCount();
    m_kUnsortedGeometryList.SetSize(m_uiCount);
    for (unsigned int i = 0; i < m_uiCount; i++)
    {
        BE7BBF0Item* pkItem = new BE7BBF0Item(pkSource, i, pvContext);
        m_kUnsortedGeometryList.SetAt(i, pkItem);
    }
}

extern int DAT_010eeca4;

struct NiArr_e7bc90
{
    void* m_ppVirtualMethodTable;
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    NiArr_e7bc90(unsigned int uiMaxSize, unsigned int uiGrowBy) throw()
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        m_pBase = 0;
        m_ppVirtualMethodTable = (void*)&DAT_010eeca4;
    }
};

struct Base_e7bc90
{
    unsigned int m_uiCount;
    void BuildItemsFromSource(int a, int b) throw();
};

struct FUN_00e7bc90 : Base_e7bc90
{
    NiArr_e7bc90 m_aiIndexedValues;
    FUN_00e7bc90(int a, int b) throw();
};

// Initializes the count to zero, constructs the array with max size 0 and grow-by 1, then calls BuildItemsFromSource with the two arguments.
// @fnv 0x00e7bc90
FUN_00e7bc90::FUN_00e7bc90(int a, int b) throw() : m_aiIndexedValues(0, 1)
{
    m_uiCount = 0;
    BuildItemsFromSource(a, b);
}

struct FUN_00e7bcd0_Item
{
    void FUN_00e7bb50();
};

void __cdecl FUN_00aa1460(void* p, int size);
void __cdecl FUN_00aa10f0(void* p);

struct FUN_00e7bcd0_cls
{
    int unk00;
    int unk04;
    FUN_00e7bcd0_Item** m_items;
    unsigned short unk0C;
    unsigned short m_uiItemCount;
    void DestroyItems();
};

// @fnv 0x00e7bcd0
void FUN_00e7bcd0_cls::DestroyItems()
{
    for (unsigned int i = 0; i < m_uiItemCount; i++)
    {
        FUN_00e7bcd0_Item* item = m_items[i];
        if (item != 0)
        {
            item->FUN_00e7bb50();
            FUN_00aa1460(item, 0x468);
        }
    }
    unk04 = (int)&DAT_010eec4c;
    FUN_00aa10f0(m_items);
}

struct S_00e88fc0_Callee
{
    void __thiscall SetStageValue(int, int, int);
};

struct S_00e7c610_Object
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    S_00e88fc0_Callee* unk10;
    void* unk14;
    void* unk18;
    float unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
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
    unsigned char unk5c;
    unsigned char unk5d;
    unsigned char unk5e;
    unsigned char unk5f;
};

// @fnv 0x00e7c610
void __stdcall FUN_00e7c610(float* afMatrix, S_00e7c610_Object* pObject)
{
    pObject->unk5e = 1;

    pObject->unk10->SetStageValue(0x18, 2, 0);

    pObject->unk1c = afMatrix[0];
    pObject->unk2c = afMatrix[1];
    pObject->unk3c = afMatrix[2];
    pObject->unk4c = 0.0f;

    pObject->unk20 = afMatrix[3];
    pObject->unk30 = afMatrix[4];
    pObject->unk40 = afMatrix[5];

    pObject->unk50 = 0.0f;
    pObject->unk54 = 0.0f;
    pObject->unk44 = 0.0f;
    pObject->unk34 = 0.0f;
    pObject->unk24 = 0.0f;
    pObject->unk58 = 0.0f;
    pObject->unk48 = 0.0f;
    pObject->unk38 = 0.0f;
    pObject->unk28 = 0.0f;
}

class FUN_00e7cc90_cls
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
    bool FUN_00e7cc90();
};

// @fnv 0x00e7cc90
bool FUN_00e7cc90_cls::FUN_00e7cc90()
{
    v26();
    return true;
}

struct E7CCD0Device
{
    virtual long __stdcall vfunc00();
    virtual long __stdcall vfunc01();
    virtual long __stdcall vfunc02();
    virtual long __stdcall vfunc03();
    virtual long __stdcall vfunc04();
    virtual long __stdcall vfunc05();
    virtual long __stdcall vfunc06();
    virtual long __stdcall vfunc07();
    virtual long __stdcall vfunc08();
    virtual long __stdcall vfunc09();
    virtual long __stdcall vfunc0A();
    virtual long __stdcall vfunc0B();
    virtual long __stdcall vfunc0C();
    virtual long __stdcall vfunc0D();
    virtual long __stdcall vfunc0E();
    virtual long __stdcall vfunc0F();
    virtual long __stdcall vfunc10();
    virtual long __stdcall Present(const void* pSourceRect, const void* pDestRect, void* hDestWindowOverride,
                                   const void* pDirtyRegion);
};

class E7CCD0Renderer
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
    E7CCD0Device* m_pD3DDevice;

    bool PresentFrame();
};

// @fnv 0x00e7ccd0
bool E7CCD0Renderer::PresentFrame()
{
    return m_pD3DDevice->Present(0, 0, 0, 0) >= 0;
}

// Candidate reconstruction of FUN_00e7cdb0 (0x00e7cdb0, 59 bytes).
//
// The original is a __thiscall member of a NiDX9*BufferData-like object:
//   * a 32-bit id member lives at offset +0x14 of the object,
//   * a global int caches the last id that was accepted,
//   * the id is validated through a renderer interface object passed as the
//     single stack argument; the interface's vtable slot 0x9c is entered with
//     the interface pointer as an explicit argument plus the id.
//
// The interface stand-in below is a plain polymorphic class with 39 filler
// virtuals so that the interesting one lands on vtable offset 0x9c.

struct FnvRendererData
{
    virtual int Fnv_v00();
    virtual int Fnv_v01();
    virtual int Fnv_v02();
    virtual int Fnv_v03();
    virtual int Fnv_v04();
    virtual int Fnv_v05();
    virtual int Fnv_v06();
    virtual int Fnv_v07();
    virtual int Fnv_v08();
    virtual int Fnv_v09();
    virtual int Fnv_v10();
    virtual int Fnv_v11();
    virtual int Fnv_v12();
    virtual int Fnv_v13();
    virtual int Fnv_v14();
    virtual int Fnv_v15();
    virtual int Fnv_v16();
    virtual int Fnv_v17();
    virtual int Fnv_v18();
    virtual int Fnv_v19();
    virtual int Fnv_v20();
    virtual int Fnv_v21();
    virtual int Fnv_v22();
    virtual int Fnv_v23();
    virtual int Fnv_v24();
    virtual int Fnv_v25();
    virtual int Fnv_v26();
    virtual int Fnv_v27();
    virtual int Fnv_v28();
    virtual int Fnv_v29();
    virtual int Fnv_v30();
    virtual int Fnv_v31();
    virtual int Fnv_v32();
    virtual int Fnv_v33();
    virtual int Fnv_v34();
    virtual int Fnv_v35();
    virtual int Fnv_v36();
    virtual int Fnv_v37();
    virtual int Fnv_v38();
    virtual int Fnv_v39(FnvRendererData* pSelf, int nId);
};

struct FnvBufferData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_nId;
    unsigned char FUN_00e7cdb0(FnvRendererData* pRenderer);
};

extern int g_nLastId;

// @fnv 0x00e7cdb0
unsigned char FnvBufferData::FUN_00e7cdb0(FnvRendererData* pRenderer)
{
    if (m_nId == 0)
        return 0;
    if (m_nId != g_nLastId)
    {
        if (pRenderer->Fnv_v39(pRenderer, m_nId) < 0)
            return 0;
        g_nLastId = m_nId;
    }
    return 1;
}

typedef int(__stdcall* FNV_PFN_2)(void* obj, void* arg);
typedef void(__stdcall* FNV_PFN_1)(void* obj);
int __cdecl CreatePixelFormat(void* p);
struct FUN_00a8f080_shell
{
    void __thiscall SetValues(int a, int b);
};

class FUN_00e7ce30_cls
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
    void* m_04;
    void* m_08;
    void* m_0c;
    int m_10;
    void* m_14;
    unsigned char FUN_00e7ce30(void* a1);
};

struct FNV_Frame
{
    void* out;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

// @fnv 0x00e7ce30
unsigned char FUN_00e7ce30_cls::FUN_00e7ce30(void* a1)
{
    FNV_Frame frame;
    void** slot = &m_14;
    if (*slot != 0)
        v21();
    if (((FNV_PFN_2)(*(void**)((char*)*(void**)a1 + 0xa0)))(a1, slot) < 0)
        return 0;
    if (((FNV_PFN_2)(*(void**)((char*)*(void**)*slot + 0x30)))(*slot, &frame.out) < 0)
    {
        ((FNV_PFN_1)(*(void**)((char*)*(void**)*slot + 8)))(*slot);
        *slot = 0;
        return 0;
    }
    m_0c = (void*)CreatePixelFormat(frame.out);
    ((FUN_00a8f080_shell*)m_08)->SetValues(frame.unk18, frame.unk1c);
    return 1;
}

// FUN_00e7d180 : releases the callback object held at +0x14 and the
// memory block held at +0x0c.
class Handler
{
  public:
    virtual void __stdcall v00();
    virtual void __stdcall v01();
    virtual void __stdcall v02();
};

extern MemoryManager DAT_011f6238;

class FUN_00e7d180_cls
{
  public:
    void* unk00;
    void* unk04;
    void* unk08;
    void* m_0c;
    int unk10;
    Handler* m_14;

    void FUN_00e7d180();
};

// Calls v02 on m_14 and clears it, then deallocates m_0c via DAT_011f6238 and clears it.
// @fnv 0x00e7d180
void FUN_00e7d180_cls::FUN_00e7d180()
{
    if (m_14 != 0)
    {
        m_14->v02();
        m_14 = 0;
    }
    DAT_011f6238.Deallocate(m_0c);
    m_0c = 0;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126f5a4;
// @fnv 0x00e7d220
CpuOpaque* __cdecl FUN_00e7d220()
{
    return &DAT_0126f5a4;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);

struct D3DSurfaceDesc_e7d250
{
    int Format;
    int Type;
    unsigned long Usage;
    int Pool;
    int MultiSampleType;
    unsigned long MultiSampleQuality;
    unsigned int Width;
    unsigned int Height;
};

struct D3DSurface_e7d250
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObj) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetDevice(void** ppDevice) = 0;
    virtual long __stdcall SetPrivateData(const void* refguid, const void* pData, unsigned long SizeOfData,
                                          unsigned long Flags) = 0;
    virtual long __stdcall GetPrivateData(const void* refguid, void* pData, unsigned long* pSizeOfData) = 0;
    virtual long __stdcall FreePrivateData(const void* refguid) = 0;
    virtual unsigned long __stdcall SetPriority(unsigned long PriorityNew) = 0;
    virtual unsigned long __stdcall GetPriority() = 0;
    virtual void __stdcall PreLoad() = 0;
    virtual int __stdcall GetType() = 0;
    virtual long __stdcall GetContainer(const void* riid, void** ppContainer) = 0;
    virtual long __stdcall GetDesc(D3DSurfaceDesc_e7d250* pDesc) = 0;
};

struct D3DTexture_e7d250
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObj) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetDevice(void** ppDevice) = 0;
    virtual long __stdcall SetPrivateData(const void* refguid, const void* pData, unsigned long SizeOfData,
                                          unsigned long Flags) = 0;
    virtual long __stdcall GetPrivateData(const void* refguid, void* pData, unsigned long* pSizeOfData) = 0;
    virtual long __stdcall FreePrivateData(const void* refguid) = 0;
    virtual unsigned long __stdcall SetPriority(unsigned long PriorityNew) = 0;
    virtual unsigned long __stdcall GetPriority() = 0;
    virtual void __stdcall PreLoad() = 0;
    virtual int __stdcall GetType() = 0;
    virtual unsigned long __stdcall SetLOD(unsigned long LODNew) = 0;
    virtual unsigned long __stdcall GetLOD() = 0;
    virtual unsigned long __stdcall GetLevelCount() = 0;
    virtual long __stdcall SetAutoGenFilterType(int FilterType) = 0;
    virtual int __stdcall GetAutoGenFilterType() = 0;
    virtual void __stdcall GenerateMipSubLevels() = 0;
    virtual long __stdcall GetLevelDesc(unsigned int Level, D3DSurfaceDesc_e7d250* pDesc) = 0;
    virtual long __stdcall GetSurfaceLevel(unsigned int Level, D3DSurface_e7d250** ppSurfaceLevel) = 0;
};

struct NiPixelFormat;
NiPixelFormat* __cdecl CreatePixelFormat(unsigned int eD3DFormat);
const char* __cdecl NiDX9ErrorString(long hr);
void __cdecl NiDX9Warning(const char* pcFormat, ...);

class Ni2DBufferStub;

class NiRefObjectStub
{
  public:
    static void* operator new(unsigned int uiSize);
    NiRefObjectStub() throw()
    {
        m_uiRefCount = 0;
        InterlockedIncrement(&ms_lObjectCount);
    }
    virtual ~NiRefObjectStub();
    unsigned int m_uiRefCount;
    static volatile long ms_lObjectCount;
};

class RendererDataStub : public NiRefObjectStub
{
  public:
    RendererDataStub() throw() : m_pCacheEntry(0), m_pkRenderPixelFormat(0)
    {}
    virtual ~RendererDataStub();
    Ni2DBufferStub* m_pCacheEntry;
    NiPixelFormat* m_pkRenderPixelFormat;
};

class NiDX92DBufferDataStub : public RendererDataStub
{
  public:
    NiDX92DBufferDataStub() throw() : m_pkSurface(0)
    {}
    virtual ~NiDX92DBufferDataStub();
    int m_iDepthFormat;
    D3DSurface_e7d250* m_pkSurface;
    int m_iUnk18;
    int m_iSamples;
};

class NiDX9TextureBufferData : public NiDX92DBufferDataStub
{
  public:
    NiDX9TextureBufferData() throw()
    {
        m_pkCubeMapTexture = 0;
    }
    virtual ~NiDX9TextureBufferData();
    D3DTexture_e7d250* m_pkCubeMapTexture;

    static NiDX9TextureBufferData* __cdecl FUN_00e7d250(D3DTexture_e7d250* pkD3DTexture, Ni2DBufferStub*& pkBuffer,
                                                        int eMSAAPref, int iUnk18);
};

class Ni2DBufferStub
{
  public:
    static Ni2DBufferStub* __cdecl Create(unsigned int uiWidth, unsigned int uiHeight, RendererDataStub* pkData);
    void AttachRendererData(RendererDataStub* pkData);
};

// Creates a NiDX9TextureBufferData wrapping the texture's level-0 surface, sets sample count from eMSAAPref, and attaches it to pkBuffer.
// @fnv 0x00e7d250
NiDX9TextureBufferData* __cdecl NiDX9TextureBufferData::FUN_00e7d250(D3DTexture_e7d250* pkD3DTexture,
                                                                     Ni2DBufferStub*& pkBuffer, int eMSAAPref,
                                                                     int iUnk18)
{
    NiDX9TextureBufferData* pkThis = new NiDX9TextureBufferData;

    pkThis->m_pkCubeMapTexture = pkD3DTexture;
    if (pkD3DTexture)
        pkD3DTexture->AddRef();

    pkThis->m_iDepthFormat = eMSAAPref;
    int iSamples;
    switch (eMSAAPref)
    {
    case 0:
        iSamples = 0;
        break;
    case 1:
        iSamples = 2;
        break;
    case 2:
        iSamples = 4;
        break;
    case 3:
        iSamples = 8;
        break;
    default:
        iSamples = 0;
        break;
    }
    pkThis->m_iSamples = iSamples;

    long hr = pkD3DTexture->GetSurfaceLevel(0, &pkThis->m_pkSurface);
    pkThis->m_iUnk18 = iUnk18;
    if (hr < 0)
    {
        NiDX9Warning("NiDX9TextureBufferData::Create> FAILED- GetSurfaceLevel - %s", NiDX9ErrorString(hr));
        delete pkThis;
        return 0;
    }

    D3DSurfaceDesc_e7d250 kDesc;
    hr = pkThis->m_pkSurface->GetDesc(&kDesc);
    if (hr < 0)
    {
        delete pkThis;
        return 0;
    }

    pkThis->m_pkRenderPixelFormat = CreatePixelFormat(kDesc.Format);

    if (pkBuffer == 0)
        pkBuffer = Ni2DBufferStub::Create(kDesc.Width, kDesc.Height, pkThis);
    else
        pkBuffer->AttachRendererData(pkThis);

    pkThis->m_pCacheEntry = pkBuffer;
    return pkThis;
}

namespace fnv_00e7d4e0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);

extern int DAT_010ef06c;
extern int DAT_010eeed4;
extern int DAT_0101dce4;
extern volatile long DAT_011f4400;

struct FUN_00e7d4e0_child
{
    virtual void v00();
    virtual void v04();
    virtual void __stdcall Release();
};

struct FUN_00e7d4e0_pool
{
    void FUN_00aa4060(void* apItem);
};
extern FUN_00e7d4e0_pool DAT_011f6238;

struct FUN_00e7d4e0_cls
{
    int m_vptr;
    int unk04;
    int unk08;
    void* m_0c;
    int unk10;
    FUN_00e7d4e0_child* m_14;
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
    FUN_00e7d4e0_child* m_58;

    void FUN_00e7d4e0();
};

// Resets the vtable, releases m_58 and m_14, frees m_0c via the pool, and decrements DAT_011f4400.
// @fnv 0x00e7d4e0
void FUN_00e7d4e0_cls::FUN_00e7d4e0()
{
    m_vptr = (int)&DAT_010ef06c;
    if (m_58 != 0)
    {
        m_58->Release();
        m_58 = 0;
    }
    m_vptr = (int)&DAT_010eeed4;
    if (m_14 != 0)
    {
        m_14->Release();
        m_14 = 0;
    }
    DAT_011f6238.FUN_00aa4060(m_0c);
    m_0c = 0;
    m_vptr = (int)&DAT_0101dce4;
    InterlockedDecrement(&DAT_011f4400);
}
}  // namespace fnv_00e7d4e0

extern int DAT_0126f5e0;

// @fnv 0x00e7d550
int* __cdecl FUN_00e7d550()
{
    return &DAT_0126f5e0;
}

namespace fnv_00e7d620 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);

extern int DAT_010eeed4;
extern int DAT_0101dce4;
extern volatile long DAT_011f4400;

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct FUN_00e7d620_child
{
    virtual void v00();
    virtual void v04();
    virtual void __stdcall Release();
};

struct FUN_00e7d620_pool
{
    void FUN_00aa4060(void* apItem);
};
extern FUN_00e7d620_pool DAT_011f6238;

struct FUN_00e7d620_cls
{
    int m_vptr;
    int unk04;
    int unk08;
    void* m_0c;
    int unk10;
    FUN_00e7d620_child* m_14;

    FUN_00e7d620_cls* FUN_00e7d620(unsigned char acFlags);
};

// Resets the vtable, releases m_14, frees m_0c via the pool, decrements DAT_011f4400 and optionally frees this with size 0x20.
// @fnv 0x00e7d620
FUN_00e7d620_cls* FUN_00e7d620_cls::FUN_00e7d620(unsigned char acFlags)
{
    m_vptr = (int)&DAT_010eeed4;
    if (m_14 != 0)
    {
        m_14->Release();
        m_14 = 0;
    }
    DAT_011f6238.FUN_00aa4060(m_0c);
    m_0c = 0;
    m_vptr = (int)&DAT_0101dce4;
    InterlockedDecrement(&DAT_011f4400);
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0x20);
    }
    return this;
}
}  // namespace fnv_00e7d620

extern int DAT_0126f5b4;

// @fnv 0x00e7d680
void* __cdecl FUN_00e7d680(void)
{
    return &DAT_0126f5b4;
}

namespace fnv_00e7eb50 {
extern "C" void* __cdecl FUN_00e7e880(unsigned int count);
struct Block
{
    char* data;
    unsigned int count;
    Block* next;
    void Initialize(unsigned int n)
    {
        count = n;
        next = 0;
        if (n > 0)
            data = (char*)FUN_00e7e880(n);
        else
            data = 0;
    }
    char* At(unsigned int index) const
    {
        char* value;
        if (index >= count)
        {
            value = 0;
        }
        else
        {
            value = data + index * 104;
        }
        return value;
    }
};
struct ArrayAllocator
{
    void* __thiscall FUN_00aa3e40(unsigned int bytes);
};
extern ArrayAllocator DAT_011f6238;
struct BlockAllocatedStringArray
{
    char** data;
    unsigned int capacity;
    unsigned int size;
    Block* blocks;
    void __thiscall FUN_00a311e0(unsigned int count);
    void __thiscall AppendBlock(unsigned int count);
};
// Allocates a Block of count elements, appends each element pointer to the array (growing it as needed), and links the block into the blocks list.
// @fnv 0x00e7eb50
void BlockAllocatedStringArray::AppendBlock(unsigned int count)
{
    Block* pBlock = (Block*)DAT_011f6238.FUN_00aa3e40(sizeof(Block));
    Block* block;
    if (pBlock)
    {
        pBlock->Initialize(count);
        block = pBlock;
    }
    else
    {
        block = 0;
    }
    for (unsigned int i = 0; i < count; ++i)
    {
        char* value = block->At(i);
        if (size == capacity)
        {
            unsigned int newCapacity = capacity > 0 ? capacity * 2 : 1;
            FUN_00a311e0(newCapacity);
        }
        data[size++] = value;
    }
    block->next = blocks;
    blocks = block;
}
}  // namespace fnv_00e7eb50

namespace fnv_00e7ec60 {
struct FUN_00e7ec60_Helper
{
    void __thiscall Release(int mode);
};

struct FUN_00e7ec60_Allocator
{
    void __thiscall Deallocate(void* p);
};

extern FUN_00e7ec60_Allocator DAT_011f6238;

struct FUN_00e7ec60_cls
{
    FUN_00e7ec60_Helper* m_00;
    int m_04;
    FUN_00e7ec60_cls* m_08;
    void __thiscall FUN_00e7ec60();
};

// Releases m_00 with mode 3, then recursively destroys and deallocates the m_08 child via DAT_011f6238.
// @fnv 0x00e7ec60
void __thiscall FUN_00e7ec60_cls::FUN_00e7ec60()
{
    if (m_00 != 0)
    {
        m_00->Release(3);
    }
    FUN_00e7ec60_cls* child = m_08;
    if (child != 0)
    {
        child->FUN_00e7ec60();
        DAT_011f6238.Deallocate(child);
    }
}
}  // namespace fnv_00e7ec60

namespace fnv_00e7ed80 {
struct SpawnedObject
{
    void __thiscall FUN_00e7e7c0(int n);
    void __thiscall FUN_00e7e7a0(int n);
};

struct StageInner
{
    SpawnedObject* m_00;
    int m_04;
    SpawnedObject* m_08;
};

struct GlobalHolder
{
    void __thiscall FUN_00aa4060(void* p);
};

extern GlobalHolder DAT_011f6238;

void __cdecl FUN_00aa10f0(int p);

// Clears the global stage pool: releases its inner objects, frees the inner and pool memory, and nulls the global pointer.
// @fnv 0x00e7ed80
void __cdecl DestroyStagePool()
{
    StagePool* p = DAT_0126f6cc;
    if (DAT_0126f6cc != 0)
    {
        StageInner* inner = (StageInner*)p->v4;
        DAT_0126f6cc->v3 = 0;
        if (inner != 0)
        {
            if (inner->m_00 != 0)
            {
                inner->m_00->FUN_00e7e7c0(3);
            }
            if (inner->m_08 != 0)
            {
                inner->m_08->FUN_00e7e7a0(1);
            }
            DAT_011f6238.FUN_00aa4060(inner);
        }
        FUN_00aa10f0(p->v1);
        DAT_011f6238.FUN_00aa4060(p);
    }
    DAT_0126f6cc = 0;
}
}  // namespace fnv_00e7ed80

namespace fnv_00e7f210 {
struct FUN_00e7f210_Pool
{
    void* __thiscall Alloc(unsigned int size);
};
extern FUN_00e7f210_Pool DAT_011f6238;

struct FUN_00e7f210_Item
{
    unsigned char* m_pData;
    unsigned int m_uiCount;
    FUN_00e7f210_Item* m_pNext;
    FUN_00e7f210_Item* Init(unsigned int n);
};

struct FUN_00e7f210_cls
{
    void** m_pItems;
    unsigned int m_uiCapacity;
    unsigned int m_uiCount;
    FUN_00e7f210_Item* m_pHead;
    void Grow(unsigned int newCapacity);
    void AppendItems(unsigned int n);
};

// Allocates a node holding n items, appends each item pointer to m_pItems (growing as needed), then pushes the node onto m_pHead.
// @fnv 0x00e7f210
void FUN_00e7f210_cls::AppendItems(unsigned int n)
{
    void* mem = DAT_011f6238.Alloc(0xc);
    FUN_00e7f210_Item* node = mem ? ((FUN_00e7f210_Item*)mem)->Init(n) : 0;

    for (unsigned int i = 0; i < n; ++i)
    {
        void* elem = (i >= node->m_uiCount) ? 0 : (void*)(node->m_pData + i * 16);
        if (m_uiCount == m_uiCapacity)
        {
            Grow(m_uiCapacity > 0 ? m_uiCapacity * 2 : 1);
        }
        m_pItems[m_uiCount] = elem;
        ++m_uiCount;
    }

    node->m_pNext = m_pHead;
    m_pHead = node;
}
}  // namespace fnv_00e7f210

namespace fnv_00e7f320 {
struct Item
{
    unsigned int unk00, unk04;
    Item* next;
};
struct NiStreamLinkIDSet
{
    Item** data;
    unsigned int capacity, size;
    void Realloc(unsigned int);
    unsigned int Find(Item* item)
    {
        for (unsigned int i = 0; i < size; ++i)
            if (data[i] == item)
                return i;
        return (unsigned int)-1;
    }
    void Add(Item* item)
    {
        if (size == capacity)
            Realloc(capacity > 0 ? capacity * 2 : 1);
        data[size++] = item;
    }
    void AddUnique(Item* item)
    {
        if (Find(item) == (unsigned int)-1)
            Add(item);
    }
};
extern NiStreamLinkIDSet* DAT_0126f71c;
struct Owner
{
    unsigned int unk00, unk04;
    Item* first;
    unsigned int unk0c;
    Item* second;
    void MoveItemsToGlobalSet();
};
// Adds each item from the first and second linked lists to DAT_0126f71c uniquely, then clears both list heads.
// @fnv 0x00e7f320
void Owner::MoveItemsToGlobalSet()
{
    Item* pNextItem;
    Item* item = first;
    while (item)
    {
        pNextItem = item->next;
        DAT_0126f71c->AddUnique(item);
        item = pNextItem;
    }
    item = second;
    while (item)
    {
        pNextItem = item->next;
        DAT_0126f71c->AddUnique(item);
        item = pNextItem;
    }
    first = 0;
    second = 0;
}
}  // namespace fnv_00e7f320

class BE7F610Heap
{
  public:
    void Deallocate(void* pvMem);
};

extern BE7F610Heap g_kE7F610Heap;

void __cdecl FUN_00aa10f0(void* pvMem);
void __cdecl FUN_00aa1490(void* pvMem, unsigned int uiAlignment);

class BE7F610Object
{
  public:
    static void operator delete(void* pvMem)
    {
        g_kE7F610Heap.Deallocate(pvMem);
    }
};

class BE7F610Worker : public BE7F610Object
{
  public:
    ~BE7F610Worker();
};

class BE7F610Leaf : public BE7F610Object
{
  public:
    void* FUN_00e7f050(unsigned int uiFlags);
};

class BE7F610Buffer : public BE7F610Object
{
  public:
    __forceinline ~BE7F610Buffer()
    {
        FUN_00aa1490(m_pResource, 0x10);
        if (m_pkLeaf)
            m_pkLeaf->FUN_00e7f050(1);
    }

    void* m_pResource;
    int unk04;
    BE7F610Leaf* m_pkLeaf;
};

template <class T> class BE7F610Queue : public BE7F610Object
{
  public:
    __forceinline ~BE7F610Queue()
    {
        m_iArrayLength = 0;
        delete m_pkOwned;
        FUN_00aa10f0(m_pvItems);
    }

    void* m_pvItems;
    int unk04;
    int m_iArrayLength;
    T* m_pkOwned;
};

extern BE7F610Queue<BE7F610Worker>* g_pkE7F610WorkerQueue;
extern BE7F610Queue<BE7F610Buffer>* g_pkE7F610BufferQueue;

// Deletes the global worker queue and buffer queue objects.
// @fnv 0x00e7f610
void __cdecl DestroyGlobalQueues()
{
    delete g_pkE7F610WorkerQueue;
    delete g_pkE7F610BufferQueue;
}

extern int DAT_0126f728;

// @fnv 0x00e7f7c0
int __cdecl FUN_00e7f7c0()
{
    return DAT_0126f728;
}

struct Q74
{
    unsigned int a, b, c, d;
    Q74() : a(0), b(0), c(0), d(0)
    {}
};
struct FUN_00e8a260
{
    virtual void V0();
    void* unk04[0x1a];
    FUN_00e8a260(int, int);
};
struct Mid_00e687a0 : FUN_00e8a260
{
    unsigned char unk6c;
    unsigned char unk6d;
    unsigned int unk70;
    Mid_00e687a0(int p1, int p2) : FUN_00e8a260(p1, p2)
    {
        unk6c = 0;
        unk6d = 0;
        unk70 = 0;
    }
};
struct FUN_00e687a0 : Mid_00e687a0
{
    Q74 q74;
    virtual void V1();
    FUN_00e687a0(int p1, int p2);
};
// Constructs the object by forwarding p1 and p2 to the base constructor and leaving the Q74 member default-initialized.
// @fnv 0x00e687a0
FUN_00e687a0::FUN_00e687a0(int p1, int p2) : Mid_00e687a0(p1, p2)
{}

extern long(__stdcall* DAT_00fdf1c0)(void*);
struct E74RefShader
{
    virtual void v00();
    virtual void DeleteThis();
    long m_lRefCount;
    void IncRefCount()
    {
        DAT_00fdf1c0(&m_lRefCount);
    }
    void DecRefCount()
    {
        if (!DAT_00fdf1c4(&m_lRefCount))
            DeleteThis();
    }
};
struct E74GeomData
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
    virtual unsigned short GetActiveCount();
    char pad04[0x30];
    unsigned int m_uiTriangles;
};
struct E74Partition
{
    char pad00[0x28];
    unsigned int m_uiTriangles;
};
struct E74SkinPartition
{
    char pad00[8];
    unsigned int m_uiPartitionCount;
    E74Partition* m_pPartitions;
};
struct E74SkinInstance
{
    char pad00[0xc];
    E74SkinPartition* m_pkSkinMeshPartition;
};
struct E74Geometry
{
    char pad00[8];
    const char* m_pcName;
    char pad0c[0xac];
    E74GeomData* m_spGeometryData;
    E74SkinInstance* m_spSkinningInstance;
    E74RefShader* m_pGeometryShader;
};
class BSFaceGenMorphData
{
  public:
    static void* operator new(unsigned int uiSize);
};
struct E74ShaderPtr
{
    E74RefShader* m_pObject;
    operator E74RefShader*() const
    {
        return m_pObject;
    }
    E74RefShader* operator->() const
    {
        return m_pObject;
    }
    E74ShaderPtr& operator=(E74RefShader* pObject)
    {
        E74RefShader* pOld = m_pObject;
        if (pOld != pObject)
        {
            if (pOld)
                pOld->DecRefCount();
            m_pObject = pObject;
            if (pObject)
                pObject->IncRefCount();
        }
        return *this;
    }
};
struct E74Node
{
    E74Geometry* m_pkGeom;
    E74Partition* m_pkGeometryPartition;
    unsigned int m_uiTriangles;
    E74Node* m_pkNext;
};
struct E74GroupMgr
{
    bool ProcessCollector(void* pkGroup, E74GeomData* pkData, E74SkinInstance* pkSkin, bool bHasAnimation,
                          unsigned int a, unsigned int b);
};
extern int DAT_0126f0ec;
inline E74Node* E74NewNode()
{
    E74Node* pkNode = (E74Node*)DAT_0126f0ec;
    if (!pkNode)
        return (E74Node*)BSFaceGenMorphData::operator new(sizeof(E74Node));
    DAT_0126f0ec = (int)pkNode->m_pkNext;
    pkNode->m_pkNext = 0;
    return pkNode;
}
struct E74Accumulator
{
    char pad000[0x620];
    E74Node* m_pkHead;
    E74Node* m_pkTail;
    char pad628[8];
    E74ShaderPtr m_pGeometryShader;
    char pad634[0x278];
    E74GroupMgr* m_pkGroupMgr;
    void* m_pkActorGroup;
    bool FUN_00e72c20(E74Geometry* pkGeom, E74RefShader* pkShader);
    void AddTail(E74Node* pkNode)
    {
        if (m_pkTail)
            m_pkTail->m_pkNext = pkNode;
        else
            m_pkHead = pkNode;
        m_pkTail = pkNode;
    }
};
struct FUN_00e74a40_shell : E74Accumulator
{
    void AddGeometryToBatch(E74Geometry* pkGeom);
};
// @fnv 0x00e74a40
void FUN_00e74a40_shell::AddGeometryToBatch(E74Geometry* pkGeom)
{
    E74GeomData* pkData = pkGeom->m_spGeometryData;
    E74SkinInstance* pkSkin = pkGeom->m_spSkinningInstance;
    if (!m_pGeometryShader)
    {
        m_pGeometryShader = pkGeom->m_pGeometryShader;
        if (!m_pGeometryShader)
        {
            FUN_00a29680("AddToBatch> No shader found for object %s!\n", pkGeom->m_pcName);
            return;
        }
    }
    if (!pkData->GetActiveCount())
        return;
    bool bHasAnimation = FUN_00e72c20(pkGeom, m_pGeometryShader);
    m_pkGroupMgr->ProcessCollector(m_pkActorGroup, pkData, pkSkin, bHasAnimation, 0, 0);
    if (bHasAnimation)
    {
        E74SkinPartition* pkPartition = pkSkin->m_pkSkinMeshPartition;
        E74Partition* pkPartitions = pkPartition->m_pPartitions;
        unsigned int uiPartitionCount = pkPartition->m_uiPartitionCount;
        for (unsigned int i = 0; i < uiPartitionCount; i++)
        {
            E74Node* pkNode = E74NewNode();
            pkNode->m_pkGeom = pkGeom;
            pkNode->m_pkGeometryPartition = &pkPartitions[i];
            pkNode->m_uiTriangles = pkPartitions[i].m_uiTriangles;
            pkNode->m_pkNext = 0;
            AddTail(pkNode);
        }
    }
    else
    {
        E74Node* pkNode = E74NewNode();
        pkNode->m_pkGeom = pkGeom;
        pkNode->m_pkGeometryPartition = 0;
        pkNode->m_uiTriangles = pkData->m_uiTriangles;
        pkNode->m_pkNext = 0;
        AddTail(pkNode);
    }
}

struct FUN_00e74c00_cls
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
    void* m_p288;
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
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    unsigned char m_bRestoreBusy;
    unsigned char unk6FD;
    unsigned char unk6FE;
    unsigned char unk6FF;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    int unk884;
    int unk888;
    int unk88C;
    int unk890;
    int unk894;
    int unk898;
    int unk89C;
    int unk8A0;
    int unk8A4;
    int unk8A8;
    int unk8AC;
    int unk8B0;
    int unk8B4;
    int unk8B8;
    int unk8BC;
    int unk8C0;
    int unk8C4;
    int unk8C8;
    int unk8CC;
    int unk8D0;
    int unk8D4;
    int unk8D8;
    int unk8DC;
    int unk8E0;
    int unk8E4;
    int unk8E8;
    int unk8EC;
    int unk8F0;
    int unk8F4;
    int unk8F8;
    int unk8FC;
    int unk900;
    int unk904;
    int unk908;
    int unk90C;
    int unk910;
    int unk914;
    int unk918;
    int unk91C;
    int unk920;
    int unk924;
    int unk928;
    int unk92C;
    int unk930;
    int unk934;
    int unk938;
    int unk93C;
    int unk940;
    int unk944;
    int unk948;
    int unk94C;
    int unk950;
    int unk954;
    int unk958;
    int unk95C;
    int unk960;
    int unk964;
    int unk968;
    int unk96C;
    int unk970;
    int unk974;
    int unk978;
    int unk97C;
    int unk980;
    int unk984;
    int unk988;
    int unk98C;
    int unk990;
    int unk994;
    int unk998;
    int unk99C;
    int unk9A0;
    int unk9A4;
    int unk9A8;
    int unk9AC;
    int unk9B0;
    int unk9B4;
    int unk9B8;
    int unk9BC;
    int unk9C0;
    int unk9C4;
    int unk9C8;
    int unk9CC;
    int unk9D0;
    int unk9D4;
    int unk9D8;
    int unk9DC;
    int unk9E0;
    int unk9E4;
    int unk9E8;
    int unk9EC;
    int unk9F0;
    int unk9F4;
    int unk9F8;
    int unk9FC;
    int unkA00;
    int unkA04;
    int unkA08;
    int unkA0C;
    int unkA10;
    int unkA14;
    int unkA18;
    int unkA1C;
    int unkA20;
    int unkA24;
    int unkA28;
    int unkA2C;
    int unkA30;
    int unkA34;
    int unkA38;
    int unkA3C;
    int unkA40;
    int unkA44;
    int unkA48;
    int unkA4C;
    int unkA50;
    int unkA54;
    int unkA58;
    int unkA5C;
    int unkA60;
    int unkA64;
    int unkA68;
    int unkA6C;
    int unkA70;
    int unkA74;
    int unkA78;
    int unkA7C;
    int unkA80;
    int unkA84;
    int unkA88;
    int unkA8C;
    int unkA90;
    int unkA94;
    int unkA98;
    int unkA9C;
    int unkAA0;
    int unkAA4;
    int unkAA8;
    int unkAAC;
    int unkAB0;
    int unkAB4;
    int unkAB8;
    int unkABC;
    int unkAC0;
    int unkAC4;
    int unkAC8;
    int unkACC;
    int unkAD0;
    int unkAD4;
    int unkAD8;
    int unkADC;
    int unkAE0;
    int unkAE4;
    int unkAE8;
    int unkAEC;
    int unkAF0;
    int unkAF4;
    void** m_ppCallbacks;
    unsigned char unkAFC;
    unsigned char unkAFD;
    unsigned short m_usCallbackCount;
    int unkB00;
    int unkB04;
    void** m_ppCallbackData;

    bool FUN_00e736b0();
    bool HandleDeviceLost();
};

typedef int(__stdcall* FNVSlot3Fn)(void*);
typedef int(__stdcall* FNVSlot80Fn)(void*, int);
typedef bool(__cdecl* FNVCallbackFn)(void*);

// Calls slot 3 on m_p288, optionally slot 128, and on device-lost codes runs the restore callbacks or FUN_00e736b0.
// @fnv 0x00e74c00
bool FUN_00e74c00_cls::HandleDeviceLost()
{
    void* obj = m_p288;
    int code = ((FNVSlot3Fn)(*(void***)obj)[3])(obj);
    if (DAT_0126f0d0 != 0)
    {
        obj = m_p288;
        ((FNVSlot80Fn)(*(void***)obj)[128])(obj, 0);
    }
    if (code == (int)0x88760869)
    {
        return FUN_00e736b0();
    }
    if (code == (int)0x88760868)
    {
        if (m_bRestoreBusy == 0)
        {
            m_bRestoreBusy = 1;
            unsigned int count = m_usCallbackCount;
            unsigned int i = 0;
            while (i < count)
            {
                FNVCallbackFn fn = (FNVCallbackFn)m_ppCallbacks[i];
                void* data = m_ppCallbackData[i];
                if (fn != 0 && !fn(data))
                {
                    FUN_00a29680("NiDX9Renderer::LostDeviceRestore> Lost device notification function failed\n");
                    return false;
                }
                ++i;
            }
        }
        return false;
    }
    return true;
}

struct Item
{
    int m_key;
    unsigned char m_flag4;
    unsigned char m_flag5;
    unsigned char m_unk06;
    unsigned char m_unk07;
};

struct Node
{
    Node* m_next;
    int m_unk04;
    Item* m_item;
};

__declspec(noinline) int __cdecl FUN_00e7acb0(int key)
{
    switch (key)
    {
    case 0x3154454d:
        return 0x10;
    case 0x34545844:
        return 0x18;
    case 0x31545844:
        return 0x20;
    case 0x32545844:
        return 0x40;
    case 0x33545844:
        return 0x80;
    case 0x35545844:
        return 0x8;
    case 0x32595559:
        return 0x10;
    case 0x59565955:
        return 0x10;
    case 0x47424752:
        return 0x10;
    case 0x42475247:
        return 0x10;
    case 0x75:
        return 0x8;
    case 0x76:
        return 0x10;
    default:
        return 0;
    }
}

int __cdecl MapCodeToIndex(int key);

class TexFormatList
{
  public:
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
    Node* m_pFirstNode;
    int __thiscall FindFormatValue(unsigned char flag, int key);
};

// @fnv 0x00e7aed0
int __thiscall TexFormatList::FindFormatValue(unsigned char abUseFlag4, int key)
{
    Node* node = m_pFirstNode;
    int result = 0;
    if (abUseFlag4)
    {
        while (node)
        {
            Item*& pItemRef = node->m_item;
            node = node->m_next;
            Item* item = pItemRef;
            if (item && item->m_flag4 && FUN_00e7acb0(item->m_key) == key)
            {
                result = MapCodeToIndex(item->m_key);
                break;
            }
        }
    }
    else
    {
        while (node)
        {
            Item*& pItemRef = node->m_item;
            node = node->m_next;
            Item* item = pItemRef;
            if (item && item->m_flag5 && FUN_00e7acb0(item->m_key) == key)
            {
                result = MapCodeToIndex(item->m_key);
                break;
            }
        }
    }
    return result;
}

struct PixelTemplate
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    unsigned int field30;
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
};
extern const PixelTemplate DAT_011aa210;
extern const PixelTemplate DAT_011aa2a0;
extern const PixelTemplate DAT_011aa408;
extern const PixelTemplate DAT_011aa498;
extern const PixelTemplate DAT_011aa4e0;
extern const PixelTemplate DAT_011aa528;
extern const PixelTemplate DAT_011aa570;
extern const PixelTemplate DAT_011aa5b8;
extern const PixelTemplate DAT_011aa600;
extern const PixelTemplate DAT_011aa648;
extern const PixelTemplate DAT_011aa690;
extern const PixelTemplate DAT_011aa6d8;
extern const PixelTemplate DAT_011aa768;
extern const PixelTemplate DAT_011aa7b0;
extern const PixelTemplate DAT_011aa7f8;
extern const PixelTemplate DAT_011aa8d0;
extern const PixelTemplate DAT_011aa960;
extern const PixelTemplate DAT_011aa9a8;
extern const PixelTemplate DAT_011aa9f0;
extern const PixelTemplate DAT_011aaa38;
extern const PixelTemplate DAT_011aaa80;
extern const PixelTemplate DAT_011aaac8;
extern const PixelTemplate DAT_011aab58;
extern const PixelTemplate DAT_011aaba0;
extern const PixelTemplate DAT_011aabe8;
extern const PixelTemplate DAT_011aac30;
extern const PixelTemplate DAT_011aacc0;
extern const PixelTemplate DAT_011aad08;
extern const PixelTemplate DAT_011aad50;
extern const PixelTemplate DAT_011aad98;
extern const PixelTemplate DAT_011aade0;
extern const PixelTemplate DAT_011aae28;
extern const PixelTemplate DAT_011aae70;
extern const PixelTemplate DAT_011aaeb8;
extern const PixelTemplate DAT_011aaf00;
extern const PixelTemplate DAT_011aaf48;
extern const PixelTemplate DAT_011aaf90;
extern const PixelTemplate DAT_011ab020;
extern const PixelTemplate DAT_011ab068;
extern const PixelTemplate DAT_011ab0b0;
extern const PixelTemplate DAT_011ab0f8;
extern const PixelTemplate DAT_011ab140;
extern const PixelTemplate DAT_011ab188;
extern const PixelTemplate DAT_011ab1d0;
extern const PixelTemplate DAT_011ab218;
extern const PixelTemplate DAT_011ab2a8;
extern const PixelTemplate DAT_011ab2f0;
// Selects a PixelTemplate by format code, copies it into output, sets field0c to format and field10 to 0, and returns output.
// @fnv 0x00e7c1e0
PixelTemplate& __cdecl GetPixelTemplateForFormat(int format, PixelTemplate& output)
{
    const PixelTemplate* pTemplate;
    switch (format)
    {
    case 0x14:
        pTemplate = &DAT_011aaa80;
        break;
    case 0x15:
        pTemplate = &DAT_011aaac8;
        break;
    case 0x16:
        pTemplate = &DAT_011aab58;
        break;
    case 0x17:
        pTemplate = &DAT_011aa8d0;
        break;
    case 0x18:
        pTemplate = &DAT_011aa9a8;
        break;
    case 0x19:
        pTemplate = &DAT_011aa960;
        break;
    case 0x1a:
        pTemplate = &DAT_011aa9f0;
        break;
    case 0x1b:
        pTemplate = &DAT_011aa7b0;
        break;
    case 0x1c:
        pTemplate = &DAT_011aa768;
        break;
    case 0x1d:
        pTemplate = &DAT_011aa7f8;
        break;
    case 0x1e:
        pTemplate = &DAT_011aaa38;
        break;
    case 0x1f:
        pTemplate = &DAT_011aabe8;
        break;
    case 0x20:
        pTemplate = &DAT_011aa2a0;
        break;
    case 0x21:
        pTemplate = &DAT_011aaba0;
        break;
    case 0x22:
        pTemplate = &DAT_011aacc0;
        break;
    case 0x23:
        pTemplate = &DAT_011aac30;
        break;
    case 0x24:
        pTemplate = &DAT_011aa5b8;
        break;
    case 0x71:
        pTemplate = &DAT_011aa5b8;
        break;
    case 0x28:
        pTemplate = &DAT_011aad50;
        break;
    case 0x29:
        pTemplate = &DAT_011aa210;
        break;
    case 0x32:
        pTemplate = &DAT_011aad98;
        break;
    case 0x51:
        pTemplate = &DAT_011aade0;
        break;
    case 0x33:
        pTemplate = &DAT_011aae28;
        break;
    case 0x34:
        pTemplate = &DAT_011aae70;
        break;
    case 0x3c:
        pTemplate = &DAT_011aa408;
        break;
    case 0x3f:
        pTemplate = &DAT_011aaeb8;
        break;
    case 0x40:
        pTemplate = &DAT_011aaf00;
        break;
    case 0x6e:
        pTemplate = &DAT_011ab0f8;
        break;
    case 0x75:
        pTemplate = &DAT_011ab068;
        break;
    case 0x3d:
        pTemplate = &DAT_011aad08;
        break;
    case 0x3e:
        pTemplate = &DAT_011aaf90;
        break;
    case 0x43:
        pTemplate = &DAT_011aaf48;
        break;
    case 0x46:
        pTemplate = &DAT_011ab140;
        break;
    case 0x50:
        pTemplate = &DAT_011ab140;
        break;
    case 0x47:
        pTemplate = &DAT_011ab188;
        break;
    case 0x49:
        pTemplate = &DAT_011ab1d0;
        break;
    case 0x4b:
        pTemplate = &DAT_011ab218;
        break;
    case 0x4d:
        pTemplate = &DAT_011ab2a8;
        break;
    case 0x4f:
        pTemplate = &DAT_011ab2f0;
        break;
    case 0x52:
        pTemplate = &DAT_011ab0b0;
        break;
    case 0x53:
        pTemplate = &DAT_011ab0b0;
        break;
    case 0x6f:
        pTemplate = &DAT_011aa6d8;
        break;
    case 0x70:
        pTemplate = &DAT_011aa648;
        break;
    case 0x72:
        pTemplate = &DAT_011aa600;
        break;
    case 0x73:
        pTemplate = &DAT_011aa690;
        break;
    case 0x74:
        pTemplate = &DAT_011aa570;
        break;
    case 0x31545844:
        pTemplate = &DAT_011aa498;
        break;
    case 0x35545844:
        pTemplate = &DAT_011aa528;
        break;
    case 0x33545844:
        pTemplate = &DAT_011aa4e0;
        break;
    default:
        pTemplate = &DAT_011ab020;
        break;
    }
    output = *pTemplate;
    output.field0c = format;
    output.field10 = 0;
    return output;
}

class CE7C500Heap
{
  public:
    void* Allocate(unsigned int uiSize);
};

extern CE7C500Heap g_kE7C500Heap;

class CE7C500PixelFormat
{
  public:
    static void* operator new(unsigned int uiSize)
    {
        return g_kE7C500Heap.Allocate(uiSize);
    }
    static void operator delete(void* pvMem);

    CE7C500PixelFormat() throw();

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
};

void __cdecl CE7C500ConvertFormat(int eFormat, CE7C500PixelFormat* pkFormat);

// Allocates a CE7C500PixelFormat, converts the given format into it, and returns the new object.
// @fnv 0x00e7c500
CE7C500PixelFormat* __cdecl CreatePixelFormat(int eFormat)
{
    CE7C500PixelFormat* pkFormat = new CE7C500PixelFormat;
    CE7C500ConvertFormat(eFormat, pkFormat);
    return pkFormat;
}

struct DepthSurfaceDescription
{
    unsigned int format;
    unsigned int type;
    unsigned int usage;
    unsigned int pool;
    unsigned int multisampleType;
    unsigned int multisampleQuality;
    unsigned int width;
    unsigned int height;
};
struct AdditionalDepthDevice
{
    void** vtable;
};
typedef unsigned long(__stdcall* DepthAddRef)(void*);
typedef long(__stdcall* DepthAcquireSurface)(void*, void*, int, D3DSurface_e7d250**);
typedef long(__stdcall* DepthGetDescription)(void*, DepthSurfaceDescription*);
class AdditionalDepthData : public NiDX92DBufferDataStub
{
  public:
    AdditionalDepthDevice* device;
    AdditionalDepthData() throw() : device(0)
    {}
    virtual ~AdditionalDepthData()
    {}
};
extern char DAT_010ef028;
// Creates AdditionalDepthData, acquires a depth surface from the device, queries its description, and creates or reuses the Ni2DBufferStub.
// @fnv 0x00e7d390
AdditionalDepthData* __cdecl CreateDepthBufferData(AdditionalDepthDevice* device, void* surfaceSource, int, int,
                                                   Ni2DBufferStub** buffer)
{
    AdditionalDepthData* result = new AdditionalDepthData;
    result->device = device;
    DepthAddRef addRef = reinterpret_cast<DepthAddRef>(result->device->vtable[1]);
    addRef(result->device);
    long status = reinterpret_cast<DepthAcquireSurface>(result->device->vtable[18])(result->device, surfaceSource, 0,
                                                                                    &result->m_pkSurface);
    if (status < 0)
    {
        FUN_00a29680(&DAT_010ef028, NiDX9ErrorString(status));
        result->m_pkSurface = 0;
    }
    else
    {
        DepthSurfaceDescription description;
        status = reinterpret_cast<DepthGetDescription>(
            reinterpret_cast<AdditionalDepthDevice*>(result->m_pkSurface)->vtable[12])(result->m_pkSurface,
                                                                                       &description);
        if (status >= 0)
        {
            result->m_pkRenderPixelFormat = CreatePixelFormat(description.format);
            if (*buffer == 0)
                *buffer = Ni2DBufferStub::Create(description.width, description.height, result);
            else
                (*buffer)->AttachRendererData(result);
            result->m_pCacheEntry = *buffer;
            return result;
        }
    }
    delete result;
    return 0;
}

struct IndexAllocator
{
    int unk00;
};
struct IndexArray;
void __cdecl FUN_00c908c0(IndexAllocator* alloc, IndexArray* arr, int newCap, int elemSize);
void* __cdecl FUN_00cb1260(void* dst, const void* src, unsigned int n);

struct IndexArray
{
    unsigned short* data;
    int size;
    unsigned int capacity;
};

// @fnv 0x00e61090
void __cdecl AppendIndices(int primType, const unsigned short* src, int count, int offset, IndexArray* out)
{
    switch (primType)
    {
    case 3: {
        FUN_00c85750_Result* pResult = FUN_00c85750();
        IndexAllocator* alloc = (IndexAllocator*)pResult->unk10;
        int oldSize = out->size;
        int newSize = oldSize + count;
        int cap = out->capacity & 0x3fffffff;
        if (cap < newSize)
        {
            if (newSize < cap * 2)
                newSize = cap * 2;
            FUN_00c908c0(alloc, out, newSize, 2);
        }
        out->size += count;
        unsigned short* dst = out->data + oldSize;
        if (offset == 0)
        {
            FUN_00cb1260(dst, src, count * 2);
            return;
        }
        if (count > 0)
        {
            int delta = (int)src - (int)dst;
            do
            {
                *dst = (unsigned short)(*(unsigned short*)((char*)dst + delta) + offset);
                dst++;
            } while (--count != 0);
        }
        break;
    }
    case 4: {
        int n = count * 3 - 6;
        FUN_00c85750_Result* pResult = FUN_00c85750();
        IndexAllocator* alloc = (IndexAllocator*)pResult->unk10;
        int oldSize = out->size;
        int newSize = oldSize + n;
        int cap = out->capacity & 0x3fffffff;
        if (cap < newSize)
        {
            if (newSize < cap * 2)
                newSize = cap * 2;
            FUN_00c908c0(alloc, out, newSize, 2);
        }
        out->size += n;
        unsigned short* dst = out->data + oldSize;
        for (int i = 2; i < count; i++)
        {
            *dst++ = (unsigned short)(src[i - 2] + offset);
            if ((i & 1) == 0)
            {
                *dst++ = (unsigned short)(src[i - 1] + offset);
                *dst++ = (unsigned short)(src[i] + offset);
            }
            else
            {
                *dst++ = (unsigned short)(src[i] + offset);
                *dst++ = (unsigned short)(src[i - 1] + offset);
            }
        }
        break;
    }
    }
}

struct HeapAlloc
{
    virtual void* v00();
    virtual void v04();
    virtual void* v08(int* size);
    virtual void v0c(void* p, int size);
    virtual void ReturnMemory(void* p, int size);
};

struct MemRouter
{
    char* stackCur;
    int unk04;
    int unk08;
    int unk0c;
    HeapAlloc* heap;
};

inline MemRouter* getRouter() throw()
{
    return (MemRouter*)FUN_00c85750();
}

void __cdecl ResizeAudioStream(HeapAlloc* alloc, void* arr, int elemSize);

template <class T> inline void construct(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

struct IntArray
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void AddBack(const int& e)
    {
        MemRouter* rr = getRouter();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(rr->heap, this, 4);
        construct(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};

struct U16Array
{
    unsigned short* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    char* m_pStackAllocation;

    __forceinline void ClearAndRelease(HeapAlloc* alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc->ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * 2);
    }
};

struct IndexSource
{
    unsigned char type;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    int unk04;
    int count;
    int unk0c;
    int unk10;
    unsigned char mode;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    int unk18;
};

inline void* __cdecl operator new(unsigned int, void* p) throw()
{
    return p;
}
inline bool isTri(int t)
{
    switch (t)
    {
    case 3:
    case 4:
        return true;
    }
    return false;
}
void __cdecl FUN_00e60e40(int type, int count, int data, IntArray* out);
void __cdecl FUN_00e60f50(int type, int data, int count, int base, IntArray* out);
void __cdecl AppendIndices(int type, int data, int count, int base, U16Array* out);

// @fnv 0x00e61280
void __cdecl BuildIndexArray(IndexSource* src, IntArray* out)
{
    switch (src->mode)
    {
    case 0:
        FUN_00e60e40(src->type, src->count, src->unk0c, out);
        break;
    case 1:
        if (isTri(src->type))
        {
            int n = src->count;
            U16Array tmp;
            tmp.m_data = 0;
            tmp.m_iElementCount = 0;
            tmp.m_iCapacityState = 0x80000000;
            MemRouter* r = getRouter();
            char* p = r->stackCur;
            r->stackCur = p + ((n * 2 + 0x7f) & ~0x7f);
            tmp.m_data = (unsigned short*)p;
            tmp.m_iCapacityState = n | 0x80000000;
            tmp.m_pStackAllocation = p;
            AppendIndices(src->type, src->unk18, src->count, 0, &tmp);
            for (int i = 0; i < src->count; i++)
            {
                int v = tmp.m_data[i];
                out->AddBack(v);
            }
            char* pStackMark = tmp.m_pStackAllocation;
            if (pStackMark == (char*)tmp.m_data)
                tmp.m_iElementCount = 0;
            getRouter()->stackCur = pStackMark;
            tmp.ClearAndRelease(getRouter()->heap);
        }
        break;
    case 2:
        if (isTri(src->type))
            FUN_00e60f50(src->type, src->unk18, src->count, 0, out);
        break;
    }
}

enum hkResultE63E
{
    HK_SUCCESS_E63E = 0,
    HK_FAILURE_E63E = 1
};

struct hkPairE63E
{
    void* m_key;
    unsigned int m_uiFilterValue;
};

class hkMapE63E
{
  public:
    int unk00;
    int unk04;
    hkPairE63E* m_pairs;
    int m_numPairs;

    hkResultE63E FindValue(void* key, unsigned int* out) const;
};

// @fnv 0x00e63e80
hkResultE63E hkMapE63E::FindValue(void* key, unsigned int* out) const
{
    for (int i = 0; i < m_numPairs; i++)
    {
        if (m_pairs[i].m_key == key)
        {
            *out = m_pairs[i].m_uiFilterValue & ~1u;
            return HK_SUCCESS_E63E;
        }
    }
    return HK_FAILURE_E63E;
}

struct FnvCpu_FUN_00e687f0_CpuObject
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
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    int value;
    int FUN_00e687f0();
};
// @fnv 0x00e687f0
int FnvCpu_FUN_00e687f0_CpuObject::FUN_00e687f0()
{
    return value;
}

struct FnvCpu_FUN_00e68800_CpuObject
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
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    int value;
    int FUN_00e68800();
};
// @fnv 0x00e68800
int FnvCpu_FUN_00e68800_CpuObject::FUN_00e68800()
{
    return value;
}

struct FUN_00e76620_cls
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
    unsigned char unk34;
    unsigned char __thiscall FUN_00e76620();
};

// @fnv 0x00e76620
unsigned char FUN_00e76620_cls::FUN_00e76620()
{
    return unk34;
}

void __cdecl FUN_00c908c0(void*, IndexArray*, int, int);
// Appends a sequence of unsigned short indices to an IndexArray, growing its capacity via FUN_00c908c0 when needed.
// @fnv 0x00e60d40
void __cdecl AppendIndexSequence(int aiSequenceType, int count, int start, IndexArray* output, void* allocator)
{
    switch (aiSequenceType)
    {
    case 4: {
        int added = 3 * count - 6;
        int oldCount = output->size;
        int required = oldCount + added;
        int capacity = output->capacity & 0x3fffffff;
        if (capacity < required)
        {
            int grown = 2 * capacity;
            FUN_00c908c0(allocator, output, required >= grown ? required : grown, 2);
        }
        output->size += added;
        unsigned short* destination = output->data + oldCount;
        for (int i = 2; i < count; ++i)
        {
            *destination++ = start + i - 2;
            if ((i & 1) == 0)
            {
                *destination++ = start + i - 1;
                *destination++ = start + i;
            }
            else
            {
                *destination++ = start + i;
                *destination++ = start + i - 1;
            }
        }
        break;
    }
    case 3: {
        int size = output->size;
        int required = size + count;
        int capacity = output->capacity & 0x3fffffff;
        if (capacity < required)
        {
            int grown = 2 * capacity;
            FUN_00c908c0(allocator, output, required >= grown ? required : grown, 2);
        }
        output->size += count;
        unsigned short* destination = output->data + size;
        for (int i = 0; i < count; ++i)
            destination[i] = start + i;
        break;
    }
    }
}

class AllocatorE60F;

struct RouterE60F
{
    int unk00, unk04, unk08, unk0C;
    AllocatorE60F* m_pStreamAllocator;

    AllocatorE60F& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterE60F {
extern "C" RouterE60F& __cdecl FUN_00c85750() throw();
}

void __cdecl FUN_00c908c0(AllocatorE60F& kAlloc, void* pArray, int iNumElements, int iSizeElem);
void* __cdecl FUN_00cb1260(void* pDst, const void* pSrc, int iNumBytes);

template <class T> class hkArrayE60F
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline T* expandBy(int n)
    {
        AllocatorE60F& kAlloc = hkRouterE60F::FUN_00c85750().heap();
        int iOldSize = m_iElementCount;
        int iNewSize = iOldSize + n;
        if (getCapacity() < iNewSize)
        {
            int iCap2 = 2 * getCapacity();
            int iNewCap = (iNewSize < iCap2) ? iCap2 : iNewSize;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
        m_iElementCount += n;
        return m_data + iOldSize;
    }
};

// Appends indices to kOut: type 3 copies them (adding iOffset if nonzero), type 4 expands a strip into 3 indices per triangle with iOffset added.
// @fnv 0x00e60f50
void __cdecl FUN_00e60f50(int iType, const int* piIndices, int iNumIndices, int iOffset, hkArrayE60F<int>& kOut)
{
    switch (iType)
    {
    case 3: {
        int* piDst = kOut.expandBy(iNumIndices);
        if (iOffset == 0)
        {
            FUN_00cb1260(piDst, piIndices, iNumIndices * sizeof(int));
        }
        else
        {
            for (int i = 0; i < iNumIndices; i++)
                piDst[i] = piIndices[i] + iOffset;
        }
        break;
    }
    case 4: {
        int* piDst = kOut.expandBy((iNumIndices - 2) * 3);
        for (int i = 2; i < iNumIndices; i++)
        {
            *piDst++ = piIndices[i - 2] + iOffset;
            if ((i & 1) == 0)
            {
                *piDst++ = piIndices[i - 1] + iOffset;
                *piDst++ = piIndices[i] + iOffset;
            }
            else
            {
                *piDst++ = piIndices[i] + iOffset;
                *piDst++ = piIndices[i - 1] + iOffset;
            }
        }
        break;
    }
    }
}

extern "C" double DAT_010229b8;

// @fnv 0x00e62ac0
static __declspec(noinline) float FUN_00e62ac0(unsigned seed)
{
    int result = 0x3039 - (int)(seed * 0x3e39b193u);
    result &= 0x7fffffff;

    return (float)result * DAT_010229b8;
}

volatile unsigned g_e62ac0_seed = 12345u;
volatile float g_e62ac0_sink;

void e62ac0_probe_caller(void)
{
    g_e62ac0_sink = FUN_00e62ac0(g_e62ac0_seed);
}

// SetVec3FromHelper - 36 bytes at 0x00e62af0 (/MT /O2 /GS /EHsc /Gy)
// void body: out receives the same float three times, and out arrives in
// EDX: this function only exists under a compiler-chosen custom calling
// convention (static callee, caller built the stack args and cleans them,
// hence the plain `ret`).  The convention register is steered by the exact
// clobber set of the in-TU callee: helper() visibly clobbers EAX and ECX
// (imul / shl with a variable count), so `out`, which must live across the
// call, gets the only remaining volatile register: EDX.
//   call 0xe62ac0            ; helper, result in st(0)
//   fld  [esp+4] / fld st(0) / faddp st(2) / fsubr [esp+8] / fmulp st(1)
//   fstp [esp+4] / fld [esp+4]
//   fst [edx] / fst [edx+4] / fstp [edx+8]
//   ret
struct Vec3
{
    float x;
    float y;
    float z;
};

int g_cn = 5;
int g_c2 = 7;

// External linkage + noinline: stays a call, and because its body is in
// this TU the caller knows it clobbers EAX/ECX but preserves EDX.
extern float __declspec(noinline) helper()
{
    g_cn = (g_cn * 3) << (g_c2 & 31);
    return 1.0f;
}

// Calls helper(), computes v = (b - a) * (r + a), and writes v into out->x, out->y, and out->z.
// @fnv 0x00e62af0
static __declspec(noinline) void SetVec3FromHelper(Vec3* out, float a, float b)
{
    float r = helper();
    float v = (b - a) * (r + a);
    out->x = v;
    out->y = v;
    out->z = v;
}

// Same-TU call site: gives the static callee its private calling
// convention (out in EDX, a/b on the stack, caller pops).
void FUN_dummycaller()
{
    Vec3 o;
    SetVec3FromHelper(&o, 1.0f, 2.0f);
}

// @fnv 0x00e64fe0
static __declspec(noinline) void SwapFloatPair(float* apFloats, int aiIndex, float* apOutSecond, float afFirst,
                                               float afSecond, unsigned __int64 outA)
{
    *(float*)(unsigned __int64)outA = apFloats[aiIndex * 2];
    *apOutSecond = apFloats[aiIndex * 2 + 1];
    apFloats[aiIndex * 2] = afFirst;
    apFloats[aiIndex * 2 + 1] = afSecond;
}

float* volatile g_e64_base;
int volatile g_e64_i;
float* volatile g_e64_outB;
float volatile g_e64_a;
float volatile g_e64_b;
float* volatile g_e64_outA;

void dummy_call_e64fe0(void)
{
    SwapFloatPair((float*)g_e64_base, g_e64_i, (float*)g_e64_outB, g_e64_a, g_e64_b,
                  (unsigned __int64)(unsigned)g_e64_outA);
}

struct E65020Entry
{
    int unk00;
    float m_fValue;
};

// @fnv 0x00e65020
__declspec(noinline) static float FUN_00e65020(E65020Entry* pkEntries, int iIndex, float fValue)
{
    float f = pkEntries[iIndex].m_fValue;
    pkEntries[iIndex].m_fValue = fValue;
    return f;
}

float E65020Swap(E65020Entry* pkEntries, int iIndex, float fValue)
{
    return FUN_00e65020(pkEntries, iIndex, fValue);
}

// @fnv 0x00e67560
void __cdecl FUN_00e67560()
{}

struct FUN_00e68820_cls
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
    int FUN_00e68820();
};

// @fnv 0x00e68820
int FUN_00e68820_cls::FUN_00e68820()
{
    return unk74;
}

struct FUN_00e69620_Target
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
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0(int a);
};
struct FUN_00e69620_cls
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
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    FUN_00e69620_Target* unk884;
    void FUN_00e69620();
};

// @fnv 0x00e69620
void FUN_00e69620_cls::FUN_00e69620()
{
    unk884->vfB0(0);
}

typedef int D3DFORMAT;
typedef int D3DDEVTYPE;
struct S00e7b590_Mode
{
    unsigned int Width;
    unsigned int Height;
    unsigned int RefreshRate;
    D3DFORMAT Format;
};
struct S00e7b590_Caps
{
    D3DDEVTYPE DeviceType;
    int c04;
    int c08;
    int c0c;
    int c10;
    int c14;
    int c18;
    int c1c;
    int c20;
    int c24;
    int c28;
    int c2c;
    int c30;
    int c34;
    int c38;
    int c3c;
    int c40;
    int c44;
    int c48;
    int c4c;
    int c50;
    int c54;
    int c58;
    int c5c;
    int c60;
    int c64;
    int c68;
    int c6c;
    int c70;
    int c74;
    int c78;
    int c7c;
    int c80;
    int c84;
    int c88;
    int c8c;
    int c90;
    int c94;
    int c98;
    int c9c;
    int ca0;
    int ca4;
    int ca8;
    int cac;
    int cb0;
    int cb4;
    int cb8;
    int cbc;
    int cc0;
    int cc4;
    int cc8;
    int ccc;
    int cd0;
    int cd4;
    int cd8;
    int cdc;
    int ce0;
    int ce4;
    int ce8;
    int cec;
    int cf0;
    int cf4;
    int cf8;
    int cfc;
    int c100;
    int c104;
    int c108;
    int c10c;
    int c110;
    int c114;
    int c118;
    int c11c;
    int c120;
    int c124;
    int c128;
    int c12c;
};
struct S00e7b590_D3D
{
    virtual int v_a();
    virtual int v_b();
    virtual int v_c();
    virtual int v_d();
    virtual int v_e();
    virtual int v_f();
    virtual unsigned int __stdcall GetAdapterModeCount(unsigned int a, D3DFORMAT f);
    virtual int __stdcall EnumAdapterModes(unsigned int a, D3DFORMAT f, unsigned int i, S00e7b590_Mode* m);
    virtual int v_g();
    virtual int __stdcall CheckDeviceType(unsigned int a, D3DDEVTYPE t, D3DFORMAT d, D3DFORMAT b, int w);
    virtual int v_h();
    virtual int v_i();
    virtual int v_j();
    virtual int v_k();
    virtual int __stdcall GetDeviceCaps(unsigned int a, D3DDEVTYPE t, S00e7b590_Caps* c);
};

struct OuterNode
{

    OuterNode* next;

    int unk04;

    D3DFORMAT format;
};

__forceinline D3DFORMAT const& GetOuterNext168(OuterNode*& position)
{

    D3DFORMAT const* value = &position->format;

    position = position->next;

    return *value;
}

typedef S00e7b590_Mode Desc;

struct ModeMap404
{
    virtual ~ModeMap404();
    unsigned int bucketCount;
    void* buckets;
    unsigned int count;
};
struct ModeItem404
{
    D3DFORMAT key;
    bool b4;
    bool fullscreenSupported;
    ModeMap404 modes;
};

struct ListNode
{

    ListNode* next;

    ListNode* prev;

    ModeItem404* item;
};

__forceinline ModeItem404* const& GetNext(ListNode*& pos)
{

    ModeItem404* const* p = &pos->item;

    pos = pos->next;

    return *p;
}

struct FUN_00e7b260 : ModeItem404
{

    static void* operator new(unsigned int size) throw();

    FUN_00e7b260(S00e7b590_D3D* dev, int ctx, D3DDEVTYPE id, D3DFORMAT key, bool fullscreen, bool windowed) throw();
};

void* __cdecl FUN_00aa13e0(unsigned int size);

class GlobalObject_0096a2d0
{

  public:
    unsigned int state;

    void Lock(const char*);
};

extern ListNode* DAT_011c5f58;

extern GlobalObject_0096a2d0 g_011c5f80;

extern unsigned int DAT_011c5f84;

void __cdecl FUN_0043a080();

struct ItemList168
{

    ListNode* head;
    ListNode* tail;
    unsigned int count;

    ItemList168()
    {
        count = 0;
        head = 0;
        tail = 0;
    }
};

struct FUN_00e7b590
{

    D3DDEVTYPE m_iOwnerObjectOffset;

    S00e7b590_Caps caps;

    ItemList168 items;

    unsigned char m_flag140;

    FUN_00e7b590(S00e7b590_D3D* dev, int ctx, D3DDEVTYPE id, D3DFORMAT a4, OuterNode** ppList);
};

// Queries device caps, builds items for formats from ppList, then sets m_flag140 from the b4 flag of the item whose key equals a4.
// @fnv 0x00e7b590
FUN_00e7b590::FUN_00e7b590(S00e7b590_D3D* dev, int aiAdapter, D3DDEVTYPE aiDeviceType, D3DFORMAT a4,
                           OuterNode** appFormats)

    : m_iOwnerObjectOffset(aiDeviceType)

{

    if (dev->GetDeviceCaps(aiAdapter, m_iOwnerObjectOffset, &caps) >= 0)
    {

        OuterNode* node = *appFormats;

        while (node)
        {

            D3DFORMAT val = GetOuterNext168(node);

            if (val)
            {

                unsigned int count = dev->GetAdapterModeCount(aiAdapter, val);

                for (unsigned int i = 0; i < count; i++)
                {

                    Desc desc;

                    bool windowed = false;
                    bool fullscreen = false;

                    if (dev->EnumAdapterModes(aiAdapter, val, i, &desc) >= 0)
                    {

                        dev->CheckDeviceType(aiAdapter, m_iOwnerObjectOffset, val, desc.Format, 0);

                        fullscreen = true;
                    }

                    if (dev->CheckDeviceType(aiAdapter, m_iOwnerObjectOffset, a4, desc.Format, 1) >= 0)

                        windowed = true;

                    if (!fullscreen && !windowed)

                        continue;

                    ListNode* pos = items.head;
                    ModeItem404* found = 0;
                    while (pos)
                    {
                        ModeItem404* item = GetNext(pos);
                        if (item->key == desc.Format)
                        {
                            found = item;
                            break;
                        }
                    }
                    if (found)
                        continue;
                    FUN_00e7b260* item =
                        new FUN_00e7b260(dev, aiAdapter, m_iOwnerObjectOffset, desc.Format, fullscreen, windowed);

                    g_011c5f80.Lock(0);

                    ListNode* poolNode = DAT_011c5f58;

                    if (!poolNode)
                    {

                        FUN_0043a080();

                        poolNode = DAT_011c5f58;
                    }

                    DAT_011c5f58 = poolNode->next;

                    poolNode->item = 0;

                    poolNode->next = 0;

                    poolNode->prev = 0;

                    if (--DAT_011c5f84 == 0)

                        g_011c5f80.state = 0;

                    poolNode->item = item;

                    poolNode->next = 0;

                    poolNode->prev = items.tail;

                    if (items.tail)

                        items.tail->next = poolNode;

                    else

                        items.head = poolNode;

                    items.count++;

                    items.tail = poolNode;
                }
            }
        }
    }
    else
    {

        caps.DeviceType = 0;
    }

    ListNode* pos = items.head;

    while (pos)
    {

        ModeItem404* item = GetNext(pos);

        if (item->key == a4)
        {

            if (item->b4)
            {

                m_flag140 = 1;

                return;
            }

            break;
        }
    }

    m_flag140 = 0;

    return;
}

struct FUN_00e7ce10_cls
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00a77980_shell* m_0c;
    int unk10;
    int m_14;

    unsigned char FUN_00e7ce10();
};

// @fnv 0x00e7ce10
unsigned char FUN_00e7ce10_cls::FUN_00e7ce10()
{
    if (!m_0c || !m_14)
    {
        return 0;
    }
    return m_0c->FUN_00a77980(0x12) > 0;
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

class ItemE7CF
{
  public:
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
    virtual void vf58(void* pArg);
};

template <class T> struct NiTListItemE7CF
{
    NiTListItemE7CF* m_pkNext;
    NiTListItemE7CF* m_pkPrev;
    T m_element;
};

typedef void* NiTListIterator;

template <class T> class NiTListE7CF
{
  public:
    void* m_vtbl;
    NiTListItemE7CF<T>* m_pkHead;
    NiTListItemE7CF<T>* m_pkTail;

    NiTListIterator GetHeadPos() const
    {
        return m_pkHead;
    }
    T GetNext(NiTListIterator& kPos) const
    {
        const T& element = ((NiTListItemE7CF<T>*)kPos)->m_element;
        kPos = ((NiTListItemE7CF<T>*)kPos)->m_pkNext;
        return element;
    }
};

struct CriticalSectionE7CF
{
    int unk00[6];
};

extern CriticalSectionE7CF DAT_0126f600;
extern NiTListE7CF<ItemE7CF*> DAT_0126f5c8;

// Locks DAT_0126f600, calls vf58(pArg) on every item in DAT_0126f5c8, then unlocks.
// @fnv 0x00e7cf00
void __cdecl FUN_00e7cf00(void* pArg)
{
    EnterCriticalSection(&DAT_0126f600);
    NiTListIterator kPos = DAT_0126f5c8.GetHeadPos();
    while (kPos)
        DAT_0126f5c8.GetNext(kPos)->vf58(pArg);
    LeaveCriticalSection(&DAT_0126f600);
}

struct SurfDesc
{
    int Format;
    int Type;
    unsigned Usage;
    int Pool;
    int MS;
    unsigned MSQ;
    unsigned Width;
    unsigned Height;
};
struct Surf
{
    virtual long QI();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual long __stdcall GetDesc(SurfDesc*);
};
struct Swap
{
    virtual long QI();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
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
    virtual long __stdcall GetSurf(unsigned, Surf**);
};
struct Tex
{
    void SetValues(unsigned, unsigned);
};

const char* FUN_00e7a9a0(int);
void FUN_00a29680(const char*, ...);
extern int DAT_0126f580;
extern int DAT_0126f590;
class RT
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
    virtual void ReleaseSurf();
    int m4;
    Tex* m_pkTex;
    CE7C500PixelFormat* m_iFmt;
    int m10;
    Surf* m_pkSurf;
    char pad[0x58 - 0x18];
    Swap* m_pkSwap;
    bool FUN_00e7d0a0(Swap* pkSwap);
};
// Releases the current swap chain and surface, adopts a new swap chain, fetches its backbuffer, and updates the texture size and pixel format.
// @fnv 0x00e7d0a0
bool RT::FUN_00e7d0a0(Swap* pkSwap)
{
    if (m_pkSurf)
        ReleaseSurf();
    DAT_0126f580 = 0;
    DAT_0126f590 = 0;
    if (m_pkSwap)
    {
        m_pkSwap->Release();
        m_pkSwap = 0;
    }
    m_pkSwap = pkSwap;
    pkSwap->AddRef();
    if (m_pkSwap->GetSurf(0, &m_pkSurf) < 0)
        return false;
    SurfDesc kDesc;
    if (m_pkSurf->GetDesc(&kDesc) < 0)
    {
        m_pkSurf->Release();
        m_pkSurf = 0;
        return false;
    }
    m_pkTex->SetValues(kDesc.Width, kDesc.Height);
    m_iFmt = CreatePixelFormat(kDesc.Format);
    FUN_00a29680("NiDX9Renderer::Recreate> Using %s backbuffer format\n", FUN_00e7a9a0(kDesc.Format));
    return true;
}

// Returns val, val/2, val/3, or val-2 depending on op (1-4), or 0 otherwise.
// @fnv 0x00e60cf0
int ApplyOperator(int op, int val)
{
    switch (op)
    {
    case 1:
        return val;
    case 2:
        return val / 2;
    case 3:
        return val / 3;
    case 4:
        return val - 2;
    }
    return 0;
}

struct RouterX
{
    char* stackCur;
    int unk04;
    int unk08;
    int unk0c;
    HeapAlloc* m_pStreamAllocator;
    __forceinline HeapAlloc& heap()
    {
        return *m_pStreamAllocator;
    }
};

struct IntArrayX
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void GrowArrayCapacity(HeapAlloc& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0((IndexAllocator*)&alloc, (IndexArray*)this, newSize, sizeof(int));
        }
    }
    __forceinline int* expandBy(int n)
    {
        HeapAlloc& alloc = ((RouterX*)FUN_00c85750())->heap();
        int oldSize = m_iElementCount;
        GrowArrayCapacity(alloc, oldSize + n);
        m_iElementCount += n;
        return m_data + oldSize;
    }
};

// Appends indices to out: type 3 adds count sequential values from data; type 4 adds count*3-6 values as triplets with alternating order.
// @fnv 0x00e60e40
void __cdecl FUN_00e60e40(int type, int count, int aiStart, IntArray* out)
{
    IntArrayX* arr = (IntArrayX*)out;
    switch (type)
    {
    case 3: {
        int* dst = arr->expandBy(count);
        for (int i = 0; i < count; i++)
            dst[i] = (unsigned short)(aiStart + i);
    }
    break;
    case 4: {
        int* dst = arr->expandBy(count * 3 - 6);
        for (int i = 2; i < count; i++)
        {
            int a = aiStart + i - 2;
            *dst++ = a;
            if ((i & 1) == 0)
            {
                *dst++ = a + 1;
                *dst++ = a + 2;
            }
            else
            {
                *dst++ = a + 2;
                *dst++ = a + 1;
            }
        }
    }
    break;
    }
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    struct
    {
        float x, y, z, w;
    } lanes;
};
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" void _mm_store_ss(float*, __m128);
__forceinline float dot3(__m128 p)
{
    float value;
    _mm_store_ss(&value, _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p)));
    return value;
}
__forceinline void dotOut(__m128 p, float& value)
{
    _mm_store_ss(&value, _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p)));
}
__forceinline void lengths(__m128 a, __m128 b, float& aa, float& cc, float& cross)
{
    aa = dot3(_mm_mul_ps(a, a));
    dotOut(_mm_mul_ps(b, b), cc);
    cross = dot3(_mm_mul_ps(b, a));
}
struct BarycentricResult
{
    float u, v, w;
};
// Computes barycentric weights of point relative to triangle a, b, c, using edge-based weights instead when the determinant is not positive.
// @fnv 0x00e61a10
void __cdecl FUN_00e61a10(const __m128* point, const __m128* apVertexA, const __m128* apVertexB,
                          const __m128* apVertexC, BarycentricResult* result)
{
    __m128 ab = _mm_sub_ps(*apVertexA, *apVertexB);
    __m128 cb = _mm_sub_ps(*apVertexC, *apVertexB);
    float abLen, fCBLenSq, ac;
    lengths(ab, cb, abLen, fCBLenSq, ac);
    float determinant = (float)(abLen * fCBLenSq) - (float)(ac * ac);
    if (determinant > 0.0f)
    {
        float reciprocal = 1.0f / determinant;
        __m128 bp = _mm_sub_ps(*apVertexB, *point);
        __m128 apProduct = _mm_mul_ps(bp, ab);
        float ap;
        ap = dot3(apProduct);
        __m128 cpProduct = _mm_mul_ps(bp, cb);
        float cp;
        cp = dot3(cpProduct);
        float s = ac * cp - fCBLenSq * ap;
        float t = ac * ap - abLen * cp;
        result->u = s * reciprocal;
        result->v = (determinant - s - t) * reciprocal;
        result->w = t * reciprocal;
    }
    else
    {
        __m128 ca = _mm_sub_ps(*apVertexA, *apVertexC);
        __m128 caLengthProduct = _mm_mul_ps(ca, ca);
        float fCALenSq;
        fCALenSq = dot3(caLengthProduct);
        if (abLen >= fCBLenSq)
        {
            if (fCALenSq >= abLen)
            {
                result->v = 0.0f;
                if (fCALenSq > 0.0f)
                {
                    __m128 sDotProduct = _mm_mul_ps(_mm_sub_ps(*point, *apVertexC), ca);
                    float s;
                    s = dot3(sDotProduct);
                    s /= fCALenSq;
                    result->u = s;
                    result->w = 1.0f - s;
                }
                else
                {
                    result->u = 0.0f;
                    result->w = 0.0f;
                }
            }
            else
            {
                __m128 sDotProduct = _mm_mul_ps(_mm_sub_ps(*point, *apVertexB), ab);
                float s;
                s = dot3(sDotProduct);
                s /= abLen;
                result->u = s;
                result->v = 1.0f - s;
                result->w = 0.0f;
            }
        }
        else
        {
            if (fCALenSq >= fCBLenSq)
            {
                __m128 sDotProduct = _mm_mul_ps(_mm_sub_ps(*point, *apVertexC), ca);
                float s;
                s = dot3(sDotProduct);
                s /= fCALenSq;
                result->u = s;
                result->v = 0.0f;
                result->w = 1.0f - s;
            }
            else
            {
                __m128 delta = _mm_sub_ps(*point, *apVertexB);
                __m128 tDotProduct = _mm_mul_ps(delta, cb);
                result->u = 0.0f;
                float t;
                t = dot3(tDotProduct);
                t /= fCBLenSq;
                result->w = t;
                result->v = 1.0f - t;
            }
        }
    }
}

namespace fnv_00e63af0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" void _mm_store_ss(float*, __m128);

extern double DAT_0109a3a0;

static __forceinline float fnv_dot(__m128 value)

{

    float scalar;
    _mm_store_ss(&scalar,
                 _mm_add_ss(_mm_shuffle_ps(value, value, 0xaa), _mm_add_ss(_mm_shuffle_ps(value, value, 0x55), value)));
    return scalar;
}

__declspec(align(16)) class ClipPlane
{

  public:
    __m128 m_vNormal;

    __m128* m_pvOrigin;

    int FUN_00e63af0(__m128* pB, float* pLo, float* pHi);
};

// Takes the distance of *pB from the plane origin along the normal, narrows *pLo or *pHi with it, and returns 4 if the range is empty, else 1 or 2.
// @fnv 0x00e63af0
int ClipPlane::FUN_00e63af0(__m128* apPoint, float* pLo, float* pHi)

{

    double t = fnv_dot(_mm_mul_ps(_mm_sub_ps(*apPoint, *m_pvOrigin), m_vNormal));

    int result = 1;
    if (*pLo < t)
    {

        if (t < *pHi)
        {

            *pHi = t;
        }
    }
    else
    {

        double t2 = t + DAT_0109a3a0;

        if (*pLo < t2)
        {

            *pLo = t2;
        }

        result = 2;
    }

    if (*pLo >= *pHi)
    {

        return 4;
    }

    return result;
}
}  // namespace fnv_00e63af0

// @fnv 0x00e67550
void __cdecl FUN_00e67550()
{}

// Clears bits 4-7 of *flags, then for modes 0-6 sets *outValue to 1 or 2 and ORs a bit pattern into *flags; returns false for other modes.
// @fnv 0x00e69510
bool __cdecl SetModeFlags(int mode, int* outValue, unsigned int* flags)
{
    *flags &= 0xffffff0fu;
    switch (mode)
    {
    case 0:
        *outValue = 1;
        *flags |= 0x50u;
        return true;
    case 1:
        *outValue = 1;
        *flags |= 0x40u;
        return true;
    case 2:
        *outValue = 1;
        *flags |= 0x80u;
        return true;
    case 3:
        *outValue = 1;
        *flags |= 0x20u;
        return true;
    case 5:
        *outValue = 2;
        *flags |= 0x40u;
        return true;
    case 6:
        *outValue = 2;
        *flags |= 0x80u;
        return true;
    case 4:
        *outValue = 2;
        *flags |= 0x20u;
        return true;
    default:
        return false;
    }
}

namespace se695c0 {

struct Block;
int SelectFormatTileValue(int iArg, Block* pkBlock);

struct Block
{
    int unk00;
};

struct Owner
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
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    Block m_kBlock;

    int FUN_00e695c0(int iArg);
};

// Returns the result of SelectFormatTileValue called with iArg and a pointer to m_kBlock.
// @fnv 0x00e695c0
int Owner::FUN_00e695c0(int iArg)
{
    return SelectFormatTileValue(iArg, &m_kBlock);
}

}

struct NiDX9DepthStencilEntry
{
    unsigned char m_bStreamFlag;
    unsigned char m_ucQuality;
    unsigned short m_usMultiSampleMask;
};
struct NiDX9RenderTargetInfo
{
    NiDX9DepthStencilEntry m_akWindowed[9];
    NiDX9DepthStencilEntry m_akFullscreen[9];
};
struct SearchIndex
{
    __declspec(noalias) bool Lookup(unsigned int key, NiDX9RenderTargetInfo** out);
};

extern "C" int __cdecl abs(int v);
extern unsigned int DAT_011bf140[];
int __cdecl FUN_00e7a8b0(unsigned int tbl, int* a, unsigned int* b);

class DepthStencilSearch
{
  public:
    int unk00;
    int unk04;
    SearchIndex m_08;
    int FindBestFullscreenFormat(unsigned int p1, int p2, int p3);
};
// Returns the DAT_011bf140 value of the enabled fullscreen entry whose two values from FUN_00e7a8b0 are closest to p2 and p3, or 0.
// @fnv 0x00e7ade0
int DepthStencilSearch::FindBestFullscreenFormat(unsigned int p1, int aiDepth, int aiStencil)
{
    NiDX9RenderTargetInfo* pRenderTargetInfo = 0;
    int result = 0;
    unsigned int uiIndex;
    if (m_08.Lookup(p1, &pRenderTargetInfo))
    {
        int chosen = 0;
        int iMinDepth = 0x7fffffff;
        int iMinStencil = 0x7fffffff;
        NiDX9DepthStencilEntry* pEntry = pRenderTargetInfo->m_akFullscreen;
        for (uiIndex = 0; uiIndex < 9; ++uiIndex, ++pEntry)
        {
            if (pEntry->m_bStreamFlag != 0)
            {
                unsigned int tbl = DAT_011bf140[uiIndex];
                int a = 0;
                unsigned int stencil = 0;
                FUN_00e7a8b0(tbl, &a, &stencil);
                if (abs(iMinDepth - aiDepth) < abs(a - aiDepth))
                    continue;
                if (abs(iMinStencil - aiStencil) < abs((int)stencil - aiStencil))
                    continue;
                iMinDepth = a;
                iMinStencil = (int)stencil;
                chosen = (int)tbl;
            }
        }
        result = chosen;
    }
    return result;
}

struct ClosestList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    NiTListItem<int>* m_pkHead;
    static int GetNext(NiTListItem<int>*& pos)
    {
        int* elem = &pos->m_element;
        pos = pos->m_pkNext;
        return *elem;
    }
    int FUN_00e7af60(int target);
};
// Returns the later list value closer to target than the first element, the closest such one, else 0; also returns 0 when target is 0.
// @fnv 0x00e7af60
int ClosestList::FUN_00e7af60(int target)
{
    if (!target)
        return 0;
    NiTListItem<int>* pos = m_pkHead;
    unsigned int best = abs(GetNext(pos) - target);
    int result = 0;
    while (pos)
    {
        int value = GetNext(pos);
        unsigned int dist = abs(value - target);
        if (dist < best)
        {
            best = dist;
            result = value;
        }
    }
    return result;
}

// Maps index 0, 1, 2 and 3 to 0, 2, 4 and 8; any other index returns 0.
// @fnv 0x00e7ccf0
int FUN_00e7ccf0(unsigned int index)
{
    switch (index)
    {
    case 0:
        return 0;
    case 1:
        return 2;
    case 2:
        return 4;
    case 3:
        return 8;
    default:
        return 0;
    }
}

class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_0126f59c;

// @fnv 0x00e7cd30
GlobalObjectO2_00a7b610* FUN_00e7cd30()
{
    return &g_0126f59c;
}

class FUN_00e7a5e0_Object
{
  public:
    virtual ~FUN_00e7a5e0_Object()
    {
        NiFree(m_pResource);
    }

    void* m_pResource;

    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }

    FUN_00e7a5e0_Object* FUN_00e7a5e0(unsigned int uiFlags);
};

// Frees m_pResource, then deletes the object itself when uiFlags has bit 0 set, and returns this.
// @fnv 0x00e7a5e0
FUN_00e7a5e0_Object* FUN_00e7a5e0_Object::FUN_00e7a5e0(unsigned int uiFlags)
{
    this->FUN_00e7a5e0_Object::~FUN_00e7a5e0_Object();
    if (uiFlags & 1)
        FUN_00e7a5e0_Object::operator delete(this);
    return this;
}

namespace fnv_00e7acb0 {
// The served context contains an unrelated noinline helper under this tag.
// Keep that helper inline-only, and isolate the reconstructed entry by namespace.
inline int __cdecl FUN_00e7acb0(int);
namespace texture_format_entry {
// Texture format size lookup: returns the number of bits per pixel for a
// format code, or -1 for an unknown format.
// Maps a format code to 0, 8, 16, 24, 32, 64 or 128, or to -1 when the code is not listed.
// @fnv 0x00e7acb0
int __cdecl FUN_00e7acb0(int aiFormat)
{
    switch (aiFormat)
    {
    case 0:
    case 100:
    case 0x3154454d:  // 'MET1'
    case 0x31545844:  // 'DXT1'
    case 0x32545844:  // 'DXT2'
    case 0x33545844:  // 'DXT3'
    case 0x34545844:  // 'DXT4'
    case 0x35545844:  // 'DXT5'
    case 0x47424752:  // 'RGBG'
    case 0x42475247:  // 'GRBG'
    case 0x32595559:  // 'YUY2'
    case 0x59565955:  // 'UVVY'
        return 0;
    case 27:
    case 28:
    case 41:
    case 50:
    case 52:
        return 8;
    case 23:
    case 24:
    case 25:
    case 26:
    case 29:
    case 30:
    case 34:
    case 40:
    case 51:
    case 60:
    case 61:
    case 70:
    case 73:
    case 80:
    case 81:
    case 101:
    case 111:
    case 117:
        return 16;
    case 20:
        return 24;
    case 21:
    case 22:
    case 31:
    case 32:
    case 33:
    case 35:
    case 62:
    case 63:
    case 64:
    case 67:
    case 71:
    case 75:
    case 77:
    case 79:
    case 82:
    case 83:
    case 102:
    case 112:
    case 114:
        return 32;
    case 36:
    case 110:
    case 113:
    case 115:
        return 64;
    case 116:
        return 128;
    }
    return -1;
}

}
}  // namespace fnv_00e7acb0

struct NiFilenameQ
{
    char m_acFolderPath[256];
    char m_acDriveLetter[3];
    char m_acExtension[256];
    char m_acBaseName[256];
    char m_acPlatformSubDir[256];
    void FUN_00aa27d0(const char* pcFullPath);
};

struct NiFileQ
{
    virtual void Release(int bDelete);
    virtual bool IsValid();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual unsigned int GetFileSize();
    unsigned int ReadBytes(void* pvBuffer, unsigned int uiBytes);
};

struct D3DXImageInfoQ
{
    unsigned int Width;
    unsigned int Height;
    unsigned int Depth;
    unsigned int MipLevels;
    int Format;
    int ResourceType;
    int m_iImageFileFormat;
};

struct D3DBaseTextureQ
{
    virtual long __stdcall QueryInterface(void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

struct DDSFileHeaderQ
{
    unsigned int dwMagic;
    unsigned int dwSize;
    unsigned int dwFlags;
    unsigned int dwHeight;
    unsigned int dwWidth;
    unsigned int m_uiPitchOrLinearSize;
    unsigned int dwDepth;
    unsigned int dwMipMapCount;
    unsigned int dwReserved0;
    unsigned int dwReserved1;
    unsigned int dwReserved2;
    unsigned int dwReserved3;
    unsigned int dwReserved4;
    unsigned int dwReserved5;
    unsigned int dwReserved6;
    unsigned int dwReserved7;
    unsigned int dwReserved8;
    unsigned int dwReserved9;
    unsigned int dwReserved10;
    unsigned int dwPFSize;
    unsigned int dwPFFlags;
    unsigned int dwFourCC;
};

struct NiDX9RendererQ
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
    void* m_pDirect3DDevice;
    void* GetD3DDevice() const
    {
        return m_pDirect3DDevice;
    }
};

struct FormatPrefsQ
{
    int m_ePreferredPixelLayout;
    int m_eAlphaFormat;
    int m_eMipFlag;
};

struct MemoryManagerQ : MemoryManager
{
    void* FUN_00aa3e40(unsigned int uiSize);
};

template <class T> __forceinline T NiMaxQ(T a, T b)
{
    return (a > b) ? a : b;
}
template <class T> __forceinline T NiMinQ(T a, T b)
{
    return (a < b) ? a : b;
}

__forceinline bool IsBumpFormatQ(int eFormat)
{
    return eFormat == 0x3c || eFormat == 0x3f || eFormat == 0x40 || eFormat == 0x6e || eFormat == 0x75 ||
           eFormat == 0x3d || eFormat == 0x3e || eFormat == 0x43;
}

int __cdecl FUN_00ec65a6(char* pcDest, unsigned int uiDestSize, const char* pcSrc);
void __cdecl FUN_00aa2a00(char* pcPath);
int __cdecl FUN_00aa1360(const char* s1, const char* s2);
NiFileQ* __cdecl FUN_00aa1a20(const char* pcName, int eMode, unsigned int uiBufferSize);
void* __cdecl FUN_00aa1070(unsigned int uiSize);
void __cdecl FUN_00aa10f0(void* pvMem);
void* __cdecl FUN_00ec44d0(void* pvDest, const void* pvSrc, unsigned int uiSize);
long __stdcall FUN_00ee6e22(const void* pvSrc, unsigned int uiSize, D3DXImageInfoQ* pkInfo);
__declspec(noalias) long __stdcall FUN_00ee6e1c(void* pkDevice, const void* pvSrc, unsigned int uiSize,
                                                D3DBaseTextureQ** ppkTexture);
long __stdcall FUN_00ee6e16(void* pkDevice, const void* pvSrc, unsigned int uiSize, D3DBaseTextureQ** ppkTexture);
long __stdcall FUN_00ee6e10(void* pkDevice, const void* pvSrc, unsigned int uiSize, D3DBaseTextureQ** ppkTexture);
extern unsigned int DAT_0126efc4;
extern unsigned int DAT_0126efc8;

struct LocalGroup2
{
    unsigned int mipCount;
    void* device;
};
struct LocalGroup3
{
    unsigned char* data;
    D3DBaseTextureQ* texture;
    unsigned int divisor;
};
struct NiDX9SourceTextureDataQ
{
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0C();
    virtual void V10();
    virtual void V14();
    virtual void V18();
    virtual void V1C();
    virtual void V20();
    virtual void V24();
    virtual void V28();
    virtual void V2C();
    virtual void V30();
    virtual void V34();
    virtual void V38();
    virtual void V3C();
    virtual void V40();
    virtual void V44();
    virtual void V48();
    virtual void V4C();
    virtual void V50();
    virtual void V54();
    virtual void V58();
    virtual void V5C();
    virtual void V60();
    virtual void V64();
    virtual void V68();
    virtual void V6C();
    virtual void V70();
    virtual void V74();
    virtual void V78();
    virtual void V7C();
    virtual void V80();
    virtual void V84();
    virtual void V88();
    virtual void V8C();
    virtual void V90();
    virtual void V94();
    virtual void V98();
    virtual void V9C();
    virtual void VA0();
    virtual void VA4();
    virtual void VA8();
    virtual void VAC();
    virtual bool SetD3DTexture(D3DBaseTextureQ* pkD3DTexture);

    int unk04;
    int unk08;
    unsigned int m_uiImageWidth;
    unsigned int m_uiImageHeight;

    bool LoadFromFilename(const char* pcFilename, NiDX9RendererQ* pkRenderer, const FormatPrefsQ& kPrefs,
                          NiFileQ* pkFile);
};

// @fnv 0x00e68a80
bool NiDX9SourceTextureDataQ::LoadFromFilename(const char* pcFilename, NiDX9RendererQ* pkRenderer,
                                               const FormatPrefsQ& kPrefs, NiFileQ* pkFile)
{
    LocalGroup2 group2;
    LocalGroup3 group3;
    if (!pkRenderer)
        return false;

    unsigned int uiMipsToRemove;
    union
    {
        unsigned int n;
        D3DBaseTextureQ* p;
    } kTextureOrSize;

    unsigned int height;
    D3DXImageInfoQ info;
    unsigned int width;
    group2.device = pkRenderer->GetD3DDevice();
    if (!group2.device)
        return false;

    if (!pkFile)
    {
        char acStandardFilename[260];
        FUN_00ec65a6(acStandardFilename, 260, pcFilename);
        FUN_00aa2a00(acStandardFilename);

        NiFilenameQ kFilename;
        kFilename.FUN_00aa27d0(acStandardFilename);
        if (FUN_00aa1360(kFilename.m_acExtension, ".bmp") != 0 && FUN_00aa1360(kFilename.m_acExtension, ".tga") != 0 &&
            FUN_00aa1360(kFilename.m_acExtension, ".dds") != 0)
        {
            return false;
        }

        pkFile = FUN_00aa1a20(acStandardFilename, 0, 0x8000);
        if (!pkFile)
            return false;
    }

    if (pkFile->IsValid())
    {
        unsigned int uiSize = pkFile->GetFileSize();
        kTextureOrSize.n = uiSize;
        if (uiSize == 0)
        {
            pkFile->Release(1);
            return false;
        }

        unsigned char* pucBuffer = (unsigned char*)FUN_00aa1070(uiSize);
        pkFile->ReadBytes(pucBuffer, uiSize);
        pkFile->Release(1);

        if (FUN_00ee6e22(pucBuffer, uiSize, &info) < 0)
        {
            FUN_00aa10f0(pucBuffer);
            return false;
        }

        if (kPrefs.m_ePreferredPixelLayout == 4)
        {
            int eFormat = info.Format;
            if (eFormat != 0x3c && eFormat != 0x3f && eFormat != 0x40 && eFormat != 0x6e && eFormat != 0x75 &&
                eFormat != 0x3d && eFormat != 0x3e && eFormat != 0x43)
            {
                FUN_00aa10f0(pucBuffer);
                return false;
            }
        }

        D3DBaseTextureQ* pkD3DTexture = 0;
        width = info.Width;
        height = info.Height;
        long hr;

        if (info.ResourceType == 3)
        {
            group3.texture = 0;
            if (info.m_iImageFileFormat == 4)
            {
                unsigned int uiSkip = DAT_0126efc4;
                unsigned int uiMinMips = DAT_0126efc8;
                DDSFileHeaderQ* pkHeader = (DDSFileHeaderQ*)pucBuffer;
                if (pkHeader->dwPFFlags & 4)
                {

                    if (pkHeader->dwFourCC == 0x31545844)
                        group3.divisor = 2;
                    else if (pkHeader->dwFourCC == 0x32545844 || pkHeader->dwFourCC == 0x33545844 ||
                             pkHeader->dwFourCC == 0x34545844 || pkHeader->dwFourCC == 0x35545844)
                        group3.divisor = 1;
                    else
                        goto Create;

                    group3.data = pucBuffer + 0x80;
                    unsigned int uiMips = pkHeader->dwMipMapCount;

                    unsigned int uiTargetMips = NiMaxQ(uiMips - uiSkip, uiMinMips);
                    if (uiMips <= uiSkip)
                        uiTargetMips = NiMinQ(uiMips, uiMinMips);

                    group2.mipCount = uiMips;
                    unsigned int uiFinalMips = uiMips;
                    if (uiTargetMips < group2.mipCount)
                    {
                        uiMipsToRemove = uiMips - uiTargetMips;
                        do
                        {
                            unsigned int uiBlocksW = (1u > (info.Width >> 2) ? 1u : (info.Width >> 2));
                            unsigned int uiBlocksH = (1u > (info.Height >> 2) ? 1u : (info.Height >> 2));
                            unsigned int uiLevelSize = (uiBlocksW * uiBlocksH * 16) / group3.divisor;
                            group3.data += uiLevelSize;
                            uiSize -= uiLevelSize;
                            info.Width = (1u > (info.Width >> 1) ? 1u : (info.Width >> 1));
                            info.Height = (1u > (info.Height >> 1) ? 1u : (info.Height >> 1));
                            group2.mipCount--;
                        } while (--uiMipsToRemove);
                        uiFinalMips = group2.mipCount;
                    }

                    if (uiFinalMips != pkHeader->dwMipMapCount)
                    {
                        unsigned char* pucNewBuffer =
                            (unsigned char*)static_cast<MemoryManagerQ&>(DAT_011f6238).FUN_00aa3e40(uiSize);
                        FUN_00ec44d0(pucNewBuffer, pucBuffer, 0x80);
                        DDSFileHeaderQ* pkNewHeader = (DDSFileHeaderQ*)pucNewBuffer;
                        pkNewHeader->dwWidth = info.Width;
                        pkNewHeader->dwHeight = info.Height;
                        pkNewHeader->dwMipMapCount = group2.mipCount;
                        pkNewHeader->m_uiPitchOrLinearSize = info.Width * info.Height;
                        FUN_00ec44d0(pucNewBuffer + 0x80, group3.data, uiSize - 0x80);
                        DAT_011f6238.Deallocate(pucBuffer);
                        pucBuffer = pucNewBuffer;
                    }
                    uiSize = kTextureOrSize.n;
                }
            }
        Create:
            hr = FUN_00ee6e1c(group2.device, pucBuffer, uiSize, &group3.texture);
            pkD3DTexture = group3.texture;
        }
        else if (info.ResourceType == 5)
        {
            kTextureOrSize.p = 0;
            hr = FUN_00ee6e16(group2.device, pucBuffer, uiSize, &kTextureOrSize.p);
            pkD3DTexture = kTextureOrSize.p;
        }
        else if (info.ResourceType == 4)
        {
            D3DBaseTextureQ* pkVolumeTexture = 0;
            hr = FUN_00ee6e10(group2.device, pucBuffer, uiSize, &pkVolumeTexture);
            pkD3DTexture = pkVolumeTexture;
        }
        else
        {
            hr = (long)0x8876086c;
        }

        FUN_00aa10f0(pucBuffer);

        if (hr < 0 || !pkD3DTexture)
            return false;

        bool bResult = SetD3DTexture(pkD3DTexture);
        m_uiImageWidth = width;
        m_uiImageHeight = height;
        if (!bResult)
            pkD3DTexture->Release();
        return bResult;
    }

    pkFile->Release(1);
    return false;
}

extern int DAT_010eec9c;
void* __cdecl NiMalloc(unsigned int size);

struct DisplayMode
{
    unsigned int width;
    unsigned int height;
    unsigned int refresh;
    int format;
};

struct CurrentMode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct AdapterApi
{
    virtual long __stdcall f00() throw() = 0;
    virtual long __stdcall f04() throw() = 0;
    virtual long __stdcall f08() throw() = 0;
    virtual long __stdcall f0C() throw() = 0;
    virtual long __stdcall f10() throw() = 0;
    virtual long __stdcall GetDesc(int handle, int flags, void* out) throw() = 0;
    virtual unsigned int __stdcall GetCount(int handle, int name) throw() = 0;
    virtual long __stdcall GetParam(int handle, int name, unsigned int index, DisplayMode* out) throw() = 0;
    virtual long __stdcall GetTech(int handle, CurrentMode* out) throw() = 0;
};

struct SpinLk
{
    int owner;
    unsigned int count;
    void Lock(const char* name = 0) throw();
    void Unlock() throw()
    {
        if (--count == 0)
            owner = 0;
    }
};
extern SpinLk DAT_011c5f80;

struct ListItem
{
    ListItem* next;
    ListItem* prev;
    unsigned int data;
};

struct NiTAbstractPoolAllocator_unsigned_int
{
    ListItem* head;
};
extern NiTAbstractPoolAllocator_unsigned_int NiTAbstractPoolAllocator_unsigned_int_instance;
struct PoolAlloc
{
    static ListItem* Allocate() throw()
    {
        DAT_011c5f80.Lock();
        if (!NiTAbstractPoolAllocator_unsigned_int_instance.head)
            FUN_0043a080();
        ListItem* p = NiTAbstractPoolAllocator_unsigned_int_instance.head;
        ListItem*& next = ((NiTAbstractPoolAllocator_unsigned_int_instance.head)->next);
        NiTAbstractPoolAllocator_unsigned_int_instance.head = next;
        p->data = 0;
        p->next = 0;
        p->prev = 0;
        DAT_011c5f80.Unlock();
        return p;
    }
};

struct PtrList
{
    ListItem* head;
    ListItem* tail;
    unsigned int count;
    PtrList() throw()
    {
        count = 0;
        head = 0;
        tail = 0;
    }
    void AddTail(const unsigned int& v) throw()
    {
        ListItem* n = PoolAlloc::Allocate();
        n->data = v;
        n->next = 0;
        n->prev = tail;
        if (tail)
            tail->next = n;
        else
            head = n;
        count++;
        tail = n;
    }
    void AddHead(const unsigned int& v) throw()
    {
        ListItem* n = PoolAlloc::Allocate();
        n->data = v;
        n->prev = 0;
        n->next = head;
        if (head)
            head->prev = n;
        else
            tail = n;
        count++;
        head = n;
    }
};

int __cdecl FUN_00e7acb0(int name) throw();

struct DisplayModeInfo
{
    unsigned int width;
    unsigned int height;
    int unk08;
    int format;
    PtrList list;
    DisplayModeInfo(const DisplayMode& d) throw() : width(d.width), height(d.height), format(d.format)
    {
        list.AddHead(d.refresh);
        unk08 = FUN_00e7acb0(d.format);
    }
    void* operator new(unsigned int size) throw()
    {
        return FUN_00aa13e0(size);
    }
};

struct FormatNode
{
    FormatNode* next;
    FormatNode* prev;
    unsigned int data;
};

struct FormatList
{
    FormatNode* head;
};

template <class T> class ModeStorage
{
  public:
    static T* Allocate(unsigned int n) throw()
    {
        return (T*)NiMalloc(sizeof(T) * n);
    }
};

template <class T, class TAlloc> class ModeArrayBase
{
  public:
    void* m_ppVirtualMethodTable;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    ModeArrayBase(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) throw()
    {
        m_ppVirtualMethodTable = &DAT_010eec74;
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
            m_pBase = TAlloc::Allocate(m_usMaxSize);
        else
            m_pBase = 0;
    }
    unsigned int GetSize() const
    {
        return m_usSize;
    }
    T& GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
    void FUN_00a90180(unsigned int size) throw();
    void SetAt(unsigned int uiIndex, const T& element) throw()
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != T(0))
                m_usESize++;
        }
        else
        {
            if (element != T(0))
            {
                if (m_pBase[uiIndex] == T(0))
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != T(0))
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int SetAtGrow(unsigned int uiIndex, const T& element) throw()
    {
        if (uiIndex >= m_usMaxSize)
            FUN_00a90180(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int Add(const T& element) throw()
    {
        return SetAtGrow(m_usSize, element);
    }
};

template <class T> class ModeArray : public ModeArrayBase<T, ModeStorage<T> >
{
  public:
    ModeArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) throw()
        : ModeArrayBase<T, ModeStorage<T> >(uiMaxSize, uiGrowBy)
    {
        this->m_ppVirtualMethodTable = &DAT_010eec9c;
    }
};

struct FUN_00e7b7d0
{
    int m_handle;
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
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    ModeArray<DisplayModeInfo*> m_entries;
    FUN_00e7b590* m_stage1;
    FUN_00e7b590* m_stage2;
    FUN_00e7b7d0(AdapterApi* fx, int handle, FormatList& names);
};

// Reads handle's description, collects unique display modes for each listed format into m_entries, and creates m_stage1 and m_stage2 for stages 1 and 2.
// @fnv 0x00e7b7d0
FUN_00e7b7d0::FUN_00e7b7d0(AdapterApi* apAdapter, int handle, FormatList& names) : m_handle(handle), m_entries(32, 16)
{
    apAdapter->GetDesc(m_handle, 0, &unk004);
    FormatNode* pos = names.head;
    while (pos)
    {
        unsigned int& uiFormat = pos->data;
        pos = pos->next;
        int name = uiFormat;
        if (!name)
            continue;
        unsigned int count = apAdapter->GetCount(m_handle, name);
        for (unsigned int i = 0; i < count; i++)
        {
            DisplayMode desc;
            if (apAdapter->GetParam(m_handle, name, i, &desc) < 0)
                continue;
            DisplayModeInfo* found = 0;
            for (unsigned int j = 0; j < m_entries.GetSize(); j++)
            {
                DisplayModeInfo* e = m_entries.GetAt(j);
                if (e && e->format == name && e->width == desc.width && e->height == desc.height)
                {
                    found = e;
                    e->list.AddTail(desc.refresh);
                }
            }
            if (!found)
            {
                found = new DisplayModeInfo(desc);
                m_entries.Add(found);
            }
        }
    }
    CurrentMode tech;
    apAdapter->GetTech(m_handle, &tech);
    m_stage1 = new (FUN_00aa13e0(sizeof(FUN_00e7b590)))
        FUN_00e7b590((S00e7b590_D3D*)apAdapter, handle, 1, tech.unk0C, (OuterNode**)&names);
    m_stage2 = new (FUN_00aa13e0(sizeof(FUN_00e7b590)))
        FUN_00e7b590((S00e7b590_D3D*)apAdapter, handle, 2, tech.unk0C, (OuterNode**)&names);
}

struct S00e60650
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int value;
    int FUN_00e60650();
};

// @fnv 0x00e60650
int S00e60650::FUN_00e60650()
{
    return value;
}

// FUN_00e60660: __thiscall accessor, returns this ? &this->field_14 : 0
struct FUN_00e60660_Cls;

struct FUN_00e60660_Cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int* __thiscall FUN_00e60660();
};

// @fnv 0x00e60660
int* FUN_00e60660_Cls::FUN_00e60660()
{
    return this ? &unk14 : 0;
}

namespace fnv_00e68010 {
#include <d3d9.h>

struct NiPixelFormatStub;
D3DFORMAT GetD3DFormat(const NiPixelFormatStub* kFormat);
const char* GetErrorString(HRESULT hr);
void DebugOut(const char* fmt, ...);

extern unsigned int DAT_0126efc0;
extern bool DAT_0126f0d0;

struct NiPixelFormatStub
{
    int unk00;
};

struct NiPixelDataStub
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
    unsigned int* m_puiWidth;
    unsigned int* m_puiHeight;
    int unk5c;
    unsigned int m_uiMipmapLevels;
};

static inline bool IsPowerOfTwo(unsigned int x)
{
    if (x == 0)
        return false;
    return (x & (x - 1)) == 0;
}

struct NiDX9SourceTextureData
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_uiImageWidth;
    unsigned int m_uiImageHeight;
    NiPixelFormatStub m_kPixelFormat;
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
    struct Renderer* m_pOwnerShader;
    IDirect3DTexture9* m_pkCubeMapTexture;
    unsigned int m_uiTextureFormat;
    int unk6c;
    int unk70;
    int unk74;
    unsigned int m_uiSkipLevels;
    bool FUN_00e68010(NiPixelDataStub* pkPixelData);
};

struct Renderer
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
    virtual unsigned int GetFlags();
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
    IDirect3DDevice9* m_pDirect3DDevice;
};

// Creates a D3D texture from pkPixelData, dropping top mip levels per DAT_0126efc0, stores it in m_pkCubeMapTexture and returns false on failure.
// @fnv 0x00e68010
bool NiDX9SourceTextureData::FUN_00e68010(NiPixelDataStub* pkPixelData)
{
    D3DFORMAT eFormat = GetD3DFormat(&m_kPixelFormat);
    m_uiImageWidth = *pkPixelData->m_puiWidth;
    m_uiImageHeight = *pkPixelData->m_puiHeight;

    if (!(IsPowerOfTwo(m_uiImageWidth) && IsPowerOfTwo(m_uiImageHeight)) && !(m_pOwnerShader->GetFlags() & 8))
        m_uiTextureFormat = 1;
    else
        m_uiTextureFormat = pkPixelData->m_uiMipmapLevels;

    unsigned int uiSkip = DAT_0126efc0;
    if (uiSkip > m_uiTextureFormat - 1)
        uiSkip = m_uiTextureFormat - 1;
    for (unsigned int i = 0; i < uiSkip; i++)
    {
        if (m_uiImageWidth & 1)
            m_uiImageWidth++;
        m_uiImageWidth >>= 1;
        if (m_uiImageHeight & 1)
            m_uiImageHeight++;
        m_uiImageHeight >>= 1;
    }
    m_uiSkipLevels = uiSkip;

    IDirect3DDevice9* pkDevice = m_pOwnerShader->m_pDirect3DDevice;
    IDirect3DTexture9* pkTexture = 0;
    HRESULT hr = pkDevice->CreateTexture(m_uiImageWidth, m_uiImageHeight, m_uiTextureFormat - uiSkip,
                                         DAT_0126f0d0 ? D3DUSAGE_DYNAMIC : 0, eFormat,
                                         DAT_0126f0d0 ? D3DPOOL_DEFAULT : D3DPOOL_MANAGED, &pkTexture, 0);
    if (SUCCEEDED(hr) && pkTexture)
    {
        m_pkCubeMapTexture = pkTexture;
        return true;
    }
    DebugOut("NiDX9SourceTextureData::CreateSurf> Failed CreateImageSurface - %s\n", GetErrorString(hr));
    m_pkCubeMapTexture = 0;
    return false;
}
}  // namespace fnv_00e68010

extern const char DAT_010ed328[];
extern const char DAT_010ed2d0[];
struct TextureAccessor
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    int format;
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
    unsigned char* data;
    unsigned int* widths;
    unsigned int* heights;
    unsigned int* offsets;
    unsigned int unk70;
    unsigned int mipCount;
    unsigned int pixelSize;
};
// Copies one mip level of the given face from source into a locked surface, row by row when the source row size differs from the surface pitch.
// @fnv 0x00e683d0
void __cdecl FUN_00e683d0(TextureAccessor* source, unsigned int level, CopySurface* surface, unsigned int face)
{
    CopyDesc desc;
    long result = surface->GetDesc(&desc);
    if (result < 0)
    {
        FUN_00a29680(DAT_010ed328, GetHResultName(result));
        return;
    }
    CopyLock locked;
    result = surface->LockRect(&locked, 0, 0);
    if (result < 0)
    {
        FUN_00a29680(DAT_010ed2d0, GetHResultName(result));
        return;
    }
    unsigned int pitch = locked.pitch;
    unsigned int width = source->widths[level];
    int rowSize = source->pixelSize * width;
    unsigned int rows = source->heights[level];
    if (rows > desc.height)
        rows = desc.height;
    if (source->format >= 4 && source->format <= 6)
    {
        pitch >>= 2;
        if (desc.format == 0x31545844)
            rowSize = ((width + 3) >> 1) & 0x07fffffeU;
        else
            rowSize = (width + 3) & 0x0ffffffcU;
        rows = (rows + 3) & 0x0ffffffcU;
    }
    if (rowSize != pitch)
    {
        unsigned int copySize = pitch;
        if (rowSize <= pitch)
            copySize = rowSize;
        unsigned char* read = source->data + source->offsets[level] + source->offsets[source->mipCount] * face;
        unsigned char* write = (unsigned char*)locked.bits;
        for (unsigned int i = 0; i < rows; ++i)
        {
            _memmove(write, read, copySize);
            write += locked.pitch;
            read += rowSize;
        }
    }
    else
    {
        _memmove(locked.bits, source->data + source->offsets[level] + source->offsets[source->mipCount] * face,
                 rows * rowSize);
    }
    surface->UnlockRect();
}

extern int DAT_010eec54;
extern int DAT_010eec7c;
void* __cdecl FUN_00ec61c0(void* p, int c, unsigned int n);
int __cdecl MapIndexToValue(unsigned int eFormat);

struct RTInfoZ : NiDX9RenderTargetInfo
{
    RTInfoZ()
    {
        unsigned int* puiData = reinterpret_cast<unsigned int*>(this);
        for (unsigned int n = 0; n < sizeof(*this) / sizeof(unsigned int); n++)
            puiData[n] = 0;
    }
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};

struct D3DProbe
{
    virtual int v00();
    virtual int v04();
    virtual int v08();
    virtual int v0c();
    virtual int v10();
    virtual int v14();
    virtual int v18();
    virtual int v1c();
    virtual int v20();
    virtual int v24();
    virtual int __stdcall CheckDeviceFormat(unsigned int a, int t, int af, unsigned int u, int rt, int cf);
    virtual int __stdcall CheckDeviceMultiSampleType(unsigned int a, int t, int sf, int w, int mt, unsigned int* q);
    virtual int __stdcall CheckDepthStencilMatch(unsigned int a, int t, int af, int rf, int df);
};

struct MapSetAt
{
    void InsertOrUpdate(unsigned int key, void* val);
};

struct ModeItemInit
{
    FUN_00e7b260* FUN_00e7b260(S00e7b590_D3D* dev, int ctx, D3DDEVTYPE eDeviceType, D3DFORMAT eAdapterFormat,
                               bool bFullscreen, bool bWindowed);
};

// Initializes the mode map and probes the D3D device for supported render formats, depth formats, and multisample quality for windowed and fullscreen modes.
// @fnv 0x00e7b260
FUN_00e7b260* ModeItemInit::FUN_00e7b260(S00e7b590_D3D* apD3D, int aiAdapter, D3DDEVTYPE eDeviceType,
                                         D3DFORMAT eAdapterFormat, bool bFullscreen, bool bWindowed)
{
    ::FUN_00e7b260* self = (::FUN_00e7b260*)this;
    ModeMap404& modes = self->modes;
    D3DProbe* pkD3D = (D3DProbe*)apD3D;
    unsigned int uiAdapter = aiAdapter;
    *(int**)&modes = &DAT_010eec54;
    modes.bucketCount = 37;
    modes.count = 0;
    modes.buckets = FUN_00aa1070(sizeof(void*) * modes.bucketCount);
    FUN_00ec61c0(modes.buckets, 0, sizeof(void*) * modes.bucketCount);
    *(int**)&modes = &DAT_010eec7c;
    self->key = eAdapterFormat;
    self->fullscreenSupported = bFullscreen;
    self->b4 = bWindowed;

    for (unsigned int i = 0; i < 19; i++)
    {
        if (i == 0)
            continue;

        int eFormat = MapIndexToValue(i);
        if (pkD3D->CheckDeviceFormat(uiAdapter, eDeviceType, eAdapterFormat, 1, 1, eFormat) < 0)
            continue;

        NiDX9RenderTargetInfo* pkInfo = new RTInfoZ;

        unsigned int uiWindowedMask = 0;
        unsigned int uiFullscreenMask = 0;
        unsigned int dwQuality;
        for (unsigned int ms = 0; ms < 16; ms++)
        {
            unsigned int uiBit = 1 << ms;
            if (bWindowed)
            {
                if (pkD3D->CheckDeviceMultiSampleType(uiAdapter, eDeviceType, eAdapterFormat, 1, (int)(ms + 1),
                                                      &dwQuality) >= 0)
                    uiWindowedMask |= uiBit;
            }
            if (bFullscreen)
            {
                if (pkD3D->CheckDeviceMultiSampleType(uiAdapter, eDeviceType, eAdapterFormat, 0, (int)(ms + 1),
                                                      &dwQuality) >= 0)
                    uiFullscreenMask |= uiBit;
            }
        }

        bool bFound = false;
        for (unsigned int j = 0; j < 9; j++)
        {
            int eDepth = DAT_011bf140[j];
            if (pkD3D->CheckDeviceFormat(uiAdapter, eDeviceType, eAdapterFormat, 2, 1, eDepth) < 0)
                continue;
            if (pkD3D->CheckDepthStencilMatch(uiAdapter, eDeviceType, eAdapterFormat, eFormat, eDepth) < 0)
                continue;

            pkInfo->m_akWindowed[j].m_bStreamFlag = bWindowed;
            bFound = true;
            pkInfo->m_akFullscreen[j].m_bStreamFlag = bFullscreen;

            unsigned int uiWindowedQuality;
            unsigned int uiFullscreenQuality;
            for (unsigned int k = 0; k < 16; k++)
            {
                unsigned int uiBit = 1 << k;
                int eType = (int)(k + 1);
                if (uiBit | uiWindowedMask)
                {
                    if (pkD3D->CheckDeviceMultiSampleType(uiAdapter, eDeviceType, eDepth, 1, eType,
                                                          &uiWindowedQuality) >= 0)
                    {
                        if (eType == 1)
                            pkInfo->m_akWindowed[j].m_ucQuality = (unsigned char)uiWindowedQuality;
                        pkInfo->m_akWindowed[j].m_usMultiSampleMask |= (unsigned short)uiBit;
                    }
                }
                if (uiBit | uiFullscreenMask)
                {
                    if (pkD3D->CheckDeviceMultiSampleType(uiAdapter, eDeviceType, eDepth, 0, eType,
                                                          &uiFullscreenQuality) >= 0)
                    {
                        if (eType == 1)
                            pkInfo->m_akFullscreen[j].m_ucQuality = (unsigned char)uiFullscreenQuality;
                        pkInfo->m_akFullscreen[j].m_usMultiSampleMask |= (unsigned short)uiBit;
                    }
                }
            }
        }

        if (bFound)
            ((MapSetAt*)&modes)->InsertOrUpdate(eFormat, pkInfo);
        else
            FUN_00aa1460(pkInfo, 0x48);
    }
    return self;
}

// Locks DAT_0126f600, iterates DAT_0126f5c8 calling vf54 on each ItemE7CF, then unlocks.
// @fnv 0x00e7cec0
void __cdecl FUN_00e7cec0()
{
    EnterCriticalSection(&DAT_0126f600);
    NiTListIterator position = DAT_0126f5c8.GetHeadPos();
    while (position)
    {
        ItemE7CF* item = DAT_0126f5c8.GetNext(position);
        item->vf54();
    }
    LeaveCriticalSection(&DAT_0126f600);
}

struct RendererE7D6B0
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
    virtual int GetA();
    virtual bool GetB();
};
extern RendererE7D6B0* g_rendererE7D6B0;
extern int g_dsAE7D6B0;
extern bool g_dsBE7D6B0;

struct PresentParamsE7D6B0
{
    unsigned int BackBufferWidth;
    unsigned int BackBufferHeight;
    int BackBufferFormat;
    unsigned int BackBufferCount;
    int MultiSampleType;
    unsigned long MultiSampleQuality;
    int SwapEffect;
    void* hDeviceWindow;
    int Windowed;
    int EnableAutoDepthStencil;
    int AutoDepthStencilFormat;
    unsigned long Flags;
    unsigned int FullScreen_RefreshRateInHz;
    unsigned int PresentationInterval;
};

struct DeviceE7D6B0
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObj) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual void __stdcall v03() = 0;
    virtual void __stdcall v04() = 0;
    virtual void __stdcall v05() = 0;
    virtual void __stdcall v06() = 0;
    virtual void __stdcall v07() = 0;
    virtual void __stdcall v08() = 0;
    virtual void __stdcall v09() = 0;
    virtual void __stdcall v10() = 0;
    virtual void __stdcall v11() = 0;
    virtual void __stdcall v12() = 0;
    virtual void __stdcall v13() = 0;
    virtual void __stdcall v14() = 0;
    virtual void __stdcall v15() = 0;
    virtual void __stdcall v16() = 0;
    virtual void __stdcall v17() = 0;
    virtual void __stdcall v18() = 0;
    virtual void __stdcall v19() = 0;
    virtual void __stdcall v20() = 0;
    virtual void __stdcall v21() = 0;
    virtual void __stdcall v22() = 0;
    virtual void __stdcall v23() = 0;
    virtual void __stdcall v24() = 0;
    virtual void __stdcall v25() = 0;
    virtual void __stdcall v26() = 0;
    virtual void __stdcall v27() = 0;
    virtual void __stdcall v28() = 0;
    virtual void __stdcall v29() = 0;
    virtual void __stdcall v30() = 0;
    virtual void __stdcall v31() = 0;
    virtual void __stdcall v32() = 0;
    virtual void __stdcall v33() = 0;
    virtual void __stdcall v34() = 0;
    virtual void __stdcall v35() = 0;
    virtual void __stdcall v36() = 0;
    virtual void __stdcall v37() = 0;
    virtual long __stdcall GetRenderTarget(unsigned long RenderTargetIndex, D3DSurface_e7d250** ppRenderTarget) = 0;
};

class SwapChainBufferData : public NiDX92DBufferDataStub
{
  public:
    SwapChainBufferData() throw()
    {
        m_pkDevice = 0;
    }
    virtual ~SwapChainBufferData();
    PresentParamsE7D6B0 m_kParams;
    DeviceE7D6B0* m_pkDevice;
};

// Creates a SwapChainBufferData from pkDevice and pkParams, queries the render target and pixel format, and attaches it to the Ni2DBufferStub in ppkBuffer.
// @fnv 0x00e7d6b0
SwapChainBufferData* __cdecl FUN_00e7d6b0(DeviceE7D6B0* pkDevice, PresentParamsE7D6B0* pkParams,
                                          Ni2DBufferStub** ppkBuffer)
{
    SwapChainBufferData* pkThis = new SwapChainBufferData;
    _memmove(&pkThis->m_kParams, pkParams, sizeof(PresentParamsE7D6B0));
    pkThis->m_pkDevice = pkDevice;
    pkDevice->AddRef();
    D3DSurfaceDesc_e7d250 kDesc;
    if (pkDevice->GetRenderTarget(0, &pkThis->m_pkSurface) < 0)
    {
        delete pkThis;
        return 0;
    }
    if (pkThis->m_pkSurface->GetDesc(&kDesc) < 0)
    {
        delete pkThis;
        return 0;
    }
    pkThis->m_pkRenderPixelFormat = CreatePixelFormat((unsigned int)kDesc.Format);
    FUN_00a29680("NiDX9Renderer::Create> Using %s backbuffer format\n", FUN_00e7a9a0(kDesc.Format));
    if (g_dsAE7D6B0 == 0)
    {
        RendererE7D6B0* r = g_rendererE7D6B0;
        g_dsAE7D6B0 = r->GetA();
        g_dsBE7D6B0 = r->GetB();
    }
    if (*ppkBuffer == 0)
    {
        *ppkBuffer = Ni2DBufferStub::Create(kDesc.Width, kDesc.Height, pkThis);
    }
    else
    {
        (*ppkBuffer)->AttachRendererData(pkThis);
    }
    pkThis->m_pCacheEntry = *ppkBuffer;
    return pkThis;
}

extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
extern "C" __m128 _mm_movelh_ps(__m128, __m128);
extern "C" __m128 _mm_movehl_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" void _mm_store_ps(float*, __m128);
extern "C" __m128 _mm_load_ps(const float*);
extern __m128 DAT_010c44d0;

class XfCallee
{
  public:
    virtual void v0();
    virtual void v1(void* a, void* b);
};

__declspec(align(16)) struct XfVecBuf
{
    unsigned int m_uiX;
    unsigned int m_uiY;
    unsigned int m_uiZ;
    unsigned int m_w;
};

class XfTransformBlock
{
  public:
    __m128 m_row0;
    __m128 m_row1;
    __m128 m_row2;
    __m128 m_row3;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    XfCallee* m_pCalleeA;
    XfCallee* m_pCalleeB;
    void FUN_00e62b20(__m128* in, __m128* out);
};

// Calls m_pCalleeA on in (output to out[1]) and m_pCalleeB on a row-transformed negated copy of in, then writes out[0] and out[2].
// @fnv 0x00e62b20
void XfTransformBlock::FUN_00e62b20(__m128* in, __m128* out)
{
    __m128 v = _mm_xor_ps(*in, DAT_010c44d0);
    __m128 x = m_row0;
    __m128 y = m_row1;
    __m128 z = m_row2;
    __m128 xy = _mm_unpacklo_ps(x, y);
    __m128 high = _mm_shuffle_ps(_mm_unpackhi_ps(x, y), z, 0xe4);
    x = _mm_movelh_ps(xy, z);
    y = _mm_shuffle_ps(_mm_movehl_ps(x, xy), z, 0xd4);
    z = high;
    __m128 px = _mm_mul_ps(x, _mm_shuffle_ps(v, v, 0x00));
    __m128 py = _mm_mul_ps(y, _mm_shuffle_ps(v, v, 0x55));
    __m128 pz = _mm_mul_ps(z, _mm_shuffle_ps(v, v, 0xaa));
    __m128 tmp = _mm_add_ps(_mm_add_ps(px, py), pz);
    XfVecBuf tmpA;
    XfVecBuf tmpB;
    _mm_store_ps((float*)&tmpA.m_uiX, tmp);
    m_pCalleeA->v1(in, out + 1);
    m_pCalleeB->v1(&tmpA, &tmpB);
    __m128 t2 = _mm_load_ps((float*)&tmpB.m_uiX);
    __m128 rx = _mm_mul_ps(m_row0, _mm_shuffle_ps(t2, t2, 0));
    __m128 ry = _mm_mul_ps(m_row1, _mm_shuffle_ps(t2, t2, 0x55));
    __m128 rz = _mm_mul_ps(m_row2, _mm_shuffle_ps(t2, t2, 0xaa));
    __m128 r = _mm_add_ps(_mm_add_ps(rx, ry), _mm_add_ps(rz, m_row3));
    out[0] = _mm_sub_ps(out[1], r);
    out[2] = t2;
}

extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_max_ps(__m128, __m128);
extern "C" int _mm_movemask_ps(__m128);

struct __declspec(align(16)) Vector
{
    __m128 value;
    __forceinline __m128 get() const
    {
        return value;
    }
    __forceinline void set(__m128 v)
    {
        value = v;
    }
};
struct Id
{
    unsigned int v;
};
union IdUnion
{
    unsigned int v;
};
struct IdCtor
{
    unsigned int v;
    IdCtor(unsigned int x) : v(x)
    {}
};
struct SupportResult
{
    Vector position;
    Vector field10;
    Vector field20;
    unsigned int field30;
    __forceinline void assign(const SupportResult& b, __m128 p)
    {
        __m128 a = b.field10.get();
        field10.set(a);
        __m128 c = b.field20.get();
        position.set(p);
        field20.set(c);
        field30 = b.field30;
    }
};
template <class T> struct Arg
{
    T* p;
    Arg(T* value) : p(value)
    {}
};
struct PodDir
{
    const Vector* p;
};
union UnionDir
{
    const Vector* p;
};
struct PodDst
{
    SupportResult* p;
};
struct SupportOwner
{
    void FUN_00e62b20(const Vector* direction, SupportResult* result);
    __m128* FUN_00e62c60(Arg<__m128> out, const Vector* direction, Arg<const __m128> point, Arg<SupportResult> result);
};
// @fnv 0x00e62c60
__m128* SupportOwner::FUN_00e62c60(Arg<__m128> out, const Vector* direction, Arg<const __m128> point,
                                   Arg<SupportResult> result)
{
    SupportResult positiveSupport;
    Vector negatedDirection;
    negatedDirection.set(_mm_xor_ps(direction->get(), DAT_010c44d0));
    FUN_00e62b20(direction, &positiveSupport);
    SupportResult* __restrict dst = result.p;
    FUN_00e62b20(&negatedDirection, dst);
    __m128 origin = *point.p;
    __m128 p = _mm_mul_ps(_mm_sub_ps(positiveSupport.position.get(), origin), direction->get());
    __m128 first = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
    __m128 q = _mm_mul_ps(_mm_sub_ps(dst->position.get(), origin), negatedDirection.get());
    __m128 second = _mm_add_ss(_mm_shuffle_ps(q, q, 0xaa), _mm_add_ss(_mm_shuffle_ps(q, q, 0x55), q));
    __m128 position = positiveSupport.position.get();
    __m128* output = out.p;
    *output = _mm_max_ps(first, second);
    if (_mm_movemask_ps(_mm_sub_ss(second, first)) & 1)
    {
        dst->assign(positiveSupport, position);
    }
    return output;
}

extern "C"
{
    __m128 _mm_load_ps(const float*);
    __m128 _mm_load_ss(const float*);
    void _mm_store_ps(float*, __m128);
    void _mm_store_ss(float*, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_set_ps1(float);
    void _ReadWriteBarrier();
    void _WriteBarrier();
}

extern const float DAT_01011d78;
extern const float DAT_01017718;
extern const float DAT_01016248;

struct PlaneVector
{
    __m128 m_vComponents;
    __forceinline void difference(const PlaneVector& a, const PlaneVector& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void cross(const PlaneVector& a, const PlaneVector& b)
    {
        __m128 first = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                                  _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        __m128 second = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(first, second);
    }
    __forceinline __m128 dot(const PlaneVector& a) const
    {
        __m128 products = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(products, products, 0x55), products);
        return _mm_add_ss(_mm_shuffle_ps(products, products, 0xaa), xy);
    }
    __forceinline __m128 inverseLength() const
    {
        __m128 half = _mm_set_ss(0.5f);
        __m128 three = _mm_set_ss(3.0f);
        __m128 zero = _mm_set_ss(0.0f);
        __m128 squareSum = dot(*this);
        __m128 mask = _mm_cmpeq_ss(squareSum, zero);
        __m128 estimate = _mm_rsqrt_ss(squareSum);
        __m128 correction = _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(squareSum, estimate), estimate));
        return _mm_andnot_ps(mask, _mm_mul_ss(_mm_mul_ss(half, estimate), correction));
    }
    __forceinline void normalize()
    {
        __m128 factor = inverseLength();
        factor = _mm_shuffle_ps(factor, factor, 0);
        m_vComponents = _mm_mul_ps(factor, m_vComponents);
    }
    __forceinline float dotFloat(const PlaneVector& a) const
    {
        float value;
        _mm_store_ss(&value, dot(a));
        return value;
    }
};
struct TrianglePlane
{
    PlaneVector m_00;
    PlaneVector* m_10;
    int m_14;
    int m_18;
    int m_1c;
    PlaneVector* m_20;
    int m_24;
    int m_28;
    int m_2c;
    PlaneVector* m_30;
    int m_34;
    int m_38;
    int m_3c;
    float m_40;

    void FUN_00e67570();
};

// Computes the normalized plane normal from three vertex positions and stores the dot product with the first vertex in m_40.
// @fnv 0x00e67570
void TrianglePlane::FUN_00e67570()
{
    const PlaneVector& first = *m_10;
    PlaneVector a, b;
    a.difference(first, *m_20);
    b.difference(*m_20, *m_30);
    m_00.cross(a, b);
    m_00.normalize();
    m_40 = m_00.dotFloat(first);
}

extern "C" __m128 _mm_sqrt_ss(__m128);

struct S00e61d30_TriVerts
{
    __m128 v0;
    __m128 v1;
    __m128 v2;
};

static inline __m128 Sum3(__m128 a, __m128 b)
{
    __m128 m = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m));
}
// @fnv 0x00e61d30
void FUN_00e61d30(const S00e61d30_TriVerts* tri, float* out)
{
    __m128 vEdge0 = _mm_sub_ps(tri->v0, tri->v1);
    __m128 vEdge1 = _mm_sub_ps(tri->v2, tri->v1);
    float a, b, c;
    (void)b;
    (void)a;
    (void)c;
    _mm_store_ss(&a, Sum3(vEdge0, vEdge0));
    _mm_store_ss(&b, Sum3(vEdge1, vEdge1));
    _mm_store_ss(&c, Sum3(vEdge1, vEdge0));
    __m128 vCross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(vEdge1, vEdge1, 0xd2), _mm_shuffle_ps(vEdge0, vEdge0, 0xc9)),
                               _mm_mul_ps(_mm_shuffle_ps(vEdge1, vEdge1, 0xc9), _mm_shuffle_ps(vEdge0, vEdge0, 0xd2)));
    float ab;
    ab = a * b;
    float inv = c * c;
    float det = ab - inv;
    float cc = 1.0f / det;
    out[0] = a * cc;
    out[1] = b * cc;
    out[2] = c * cc;
    __m128 sq;
    sq = _mm_mul_ps(vCross, vCross);
    __m128 vLen = _mm_sqrt_ss(_mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq)));
    float len;
    _mm_store_ss(&len, vLen);
    out[3] = 1.0f / len;
}

extern "C"
{
    double __cdecl fabs(double x);
}

struct S00e67ae0_HullFace;

struct S00e67ae0_HullEdge
{
    __m128* m_kRayStart;
    __m128** m_kRayEnd;
    S00e67ae0_HullEdge* m_twin;
    S00e67ae0_HullFace* m_face;
};

struct S00e67ae0_HullFace
{
    __m128 m_vHitNormal;
    S00e67ae0_HullEdge m_kEdges[3];
    float m_fClosestPointDistanceSquared;
    int m_uiContentCount;
};

struct S00e67ae0_HullWalker
{
    void ClearEntries();
    S00e67ae0_HullFace* FUN_00e67ae0(S00e67ae0_HullFace* start);
};

// Walks from start across hull face edges whose side test is negative, until no edge qualifies or a visited face is reached, and returns that face.
// @fnv 0x00e67ae0
S00e67ae0_HullFace* S00e67ae0_HullWalker::FUN_00e67ae0(S00e67ae0_HullFace* apStartFace)
{
    ClearEntries();
    S00e67ae0_HullFace* face = apStartFace;
    S00e67ae0_HullEdge* pFromEdge = 0;
    bool done = false;
    int i;
    do
    {
        if (done)
            break;
        face->m_uiContentCount = 3;
        for (i = 0; i < 3; i++)
        {
            S00e67ae0_HullEdge* edge = &face->m_kEdges[i];
            if (edge == pFromEdge)
                continue;
            __m128 n;
            (void)n;
            __m128 p = *edge->m_kRayStart;
            __m128 d = _mm_sub_ps(**edge->m_kRayEnd, p);
            __m128 sq = _mm_mul_ps(d, d);
            __m128 sq_y = _mm_shuffle_ps(sq, sq, 0x55);
            __m128 sq_xy = _mm_add_ss(sq_y, sq);
            __m128 sq_z = _mm_shuffle_ps(sq, sq, 0xaa);
            float fLengthSq;
            _mm_store_ss(&fLengthSq, _mm_add_ss(sq_z, sq_xy));
            n = face->m_vHitNormal;
            __m128 n_zxy = _mm_shuffle_ps(n, n, 0xd2);
            __m128 d_yzx = _mm_shuffle_ps(d, d, 0xc9);
            __m128 cross0 = _mm_mul_ps(d_yzx, n_zxy);
            __m128 d_zxy = _mm_shuffle_ps(d, d, 0xd2);
            n = _mm_shuffle_ps(n, n, 0xc9);
            __m128 cross = _mm_sub_ps(cross0, _mm_mul_ps(d_zxy, n));
            __m128 terms = _mm_mul_ps(cross, p);
            __m128 term_y = _mm_shuffle_ps(terms, terms, 0x55);
            __m128 sum_xy = _mm_add_ss(term_y, terms);
            __m128 term_z = _mm_shuffle_ps(terms, terms, 0xaa);
            float side;
            _mm_store_ss(&side, _mm_add_ss(term_z, sum_xy));
            if (side * (float)fabs(side) < (float)(fLengthSq * -9.99999949475751e-11))
            {
                S00e67ae0_HullFace* next = edge->m_twin->m_face;
                if (!(apStartFace->m_fClosestPointDistanceSquared > 0.0f) ||
                    !(next->m_fClosestPointDistanceSquared <
                      apStartFace->m_fClosestPointDistanceSquared * 0.8999999761581421))
                {
                    pFromEdge = face->m_kEdges[i].m_twin;
                    face = next;
                    done = next->m_uiContentCount == 3;
                    break;
                }
            }
        }
    } while (i != 3);
    return face;
}

extern "C" Ni2DBufferStub* __cdecl FUN_00a9ff60(unsigned int width, unsigned int height, RendererDataStub* data);
NiPixelFormat* __cdecl CreatePixelFormat(unsigned int eD3DFormat);
struct D3DDevice_e7d850
{
    virtual void vf00() = 0;
    virtual void vf01() = 0;
    virtual void vf02() = 0;
    virtual void vf03() = 0;
    virtual void vf04() = 0;
    virtual void vf05() = 0;
    virtual void vf06() = 0;
    virtual void vf07() = 0;
    virtual void vf08() = 0;
    virtual void vf09() = 0;
    virtual void vf0A() = 0;
    virtual void vf0B() = 0;
    virtual void vf0C() = 0;
    virtual void vf0D() = 0;
    virtual void vf0E() = 0;
    virtual void vf0F() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12() = 0;
    virtual void vf13() = 0;
    virtual void vf14() = 0;
    virtual void vf15() = 0;
    virtual void vf16() = 0;
    virtual void vf17() = 0;
    virtual void vf18() = 0;
    virtual void vf19() = 0;
    virtual void vf1A() = 0;
    virtual void vf1B() = 0;
    virtual void vf1C() = 0;
    virtual void vf1D() = 0;
    virtual void vf1E() = 0;
    virtual void vf1F() = 0;
    virtual void vf20() = 0;
    virtual void vf21() = 0;
    virtual void vf22() = 0;
    virtual void vf23() = 0;
    virtual void vf24() = 0;
    virtual void vf25() = 0;
    virtual void vf26() = 0;
    virtual void vf27() = 0;
    virtual long __stdcall GetDepthStencilSurface(D3DSurface_e7d250** ppZStencilSurface) = 0;
};

class NiDX9AdditionalDepthStencilBufferData : public NiDX92DBufferDataStub
{
  public:
    NiDX9AdditionalDepthStencilBufferData() throw()
    {}
    virtual ~NiDX9AdditionalDepthStencilBufferData();
};

// Creates NiDX9AdditionalDepthStencilBufferData, retrieves the device depth-stencil surface, and attaches it to the provided or newly created 2D buffer.
// @fnv 0x00e7d850
NiDX9AdditionalDepthStencilBufferData* __cdecl FUN_00e7d850(D3DDevice_e7d850* pkD3DDevice, Ni2DBufferStub*& pkBuffer)
{
    NiDX9AdditionalDepthStencilBufferData* pkData = new NiDX9AdditionalDepthStencilBufferData();
    if (pkD3DDevice->GetDepthStencilSurface(&pkData->m_pkSurface) < 0)
    {
        delete pkData;
        return 0;
    }

    D3DSurfaceDesc_e7d250 kDesc;
    if (pkData->m_pkSurface->GetDesc(&kDesc) < 0)
    {
        delete pkData;
        return 0;
    }

    pkData->m_pkRenderPixelFormat = (NiPixelFormat*)CreatePixelFormat(kDesc.Format);

    if (!pkBuffer)
    {
        pkBuffer = FUN_00a9ff60(kDesc.Width, kDesc.Height, pkData);
    }
    else
    {
        pkBuffer->AttachRendererData(pkData);
    }

    pkData->m_pCacheEntry = pkBuffer;
    DAT_0126f590 = (int)pkData->m_pkSurface;

    return pkData;
}
