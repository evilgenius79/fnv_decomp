
// src/staging/blk_00e80000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_00e87a40_This {
    void ReleaseOwnedObject();
    void FUN_00e87a40();
};

// @fnv 0x00e87a40
void FUN_00e87a40_This::FUN_00e87a40()
{
    ((FUN_00e87a40_This*)((char*)this + 0xf8))->ReleaseOwnedObject();
}

struct FUN_00e87a70_Class {
    void __thiscall FUN_00e87a70();
};

// @fnv 0x00e87a70
void __thiscall FUN_00e87a70_Class::FUN_00e87a70()
{
    volatile char* p = (volatile char*)this;
    *(int*)(p + 0x10e4) = *(int*)(p + 0x10e0);
    *(int*)(p + 0x10ec) = *(int*)(p + 0x10e8);
}

struct FUN_00e888b0_Class
{
    int __thiscall FUN_00e888b0();
};

// @fnv 0x00e888b0
int __thiscall FUN_00e888b0_Class::FUN_00e888b0()
{
    return *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x10e8);
}

struct FUN_00e88a50_Class {
    int __thiscall FUN_00e88a50(int index);
};

// @fnv 0x00e88a50
int __thiscall FUN_00e88a50_Class::FUN_00e88a50(int index)
{
    return *(int*)((char*)this + 0x10a0 + index * 4);
}

struct FUN_00e87a50_Class {
    void __thiscall FUN_00e87a50();
};
// Sets four consecutive int fields at offsets 0x10e0-0x10ec to 0, 1, 0, 1.
// @fnv 0x00e87a50
void __thiscall FUN_00e87a50_Class::FUN_00e87a50()
{
    *(int*)((char*)this + 0x10e0) = 0;
    *(int*)((char*)this + 0x10e4) = 1;
    *(int*)((char*)this + 0x10e8) = 0;
    *(int*)((char*)this + 0x10ec) = 1;
}

struct FUN_00e87ea0_Class {
    int __thiscall CallVirtualWithFlags(void* p);
};
// Calls the virtual function at offset 0x68 of this with arguments 9, 2 or 1 depending on bit 0 of p[0x18], and 0, 0.
// @fnv 0x00e87ea0
int __thiscall FUN_00e87ea0_Class::CallVirtualWithFlags(void* pObject)
{
    return reinterpret_cast<int(__thiscall*)(void*, int, int, int, int)>(
        reinterpret_cast<int**>(reinterpret_cast<int**>(this)[0])[0x68 / 4])(
        this, 9, (reinterpret_cast<char*>(pObject)[0x18] & 1) ? 2 : 1, 0, 0);
}

struct FUN_00e88710_Class {
    void __thiscall FUN_00e88710(float* a, float* b);
};
// @fnv 0x00e88710
void __thiscall FUN_00e88710_Class::FUN_00e88710(float* a, float* b)
{
    *a = *(float*)((char*)this + 0x78);
    *b = *(float*)((char*)this + 0x7c);
}

struct FUN_00e88730_Class {
    void __thiscall SetRange(float a, float b);
};

// @fnv 0x00e88730
void __thiscall FUN_00e88730_Class::SetRange(float afMin, float afMax)
{
    *(float*)((char*)this + 0x78) = afMin;
    *(float*)((char*)this + 0x7c) = afMax;
    *(float*)((char*)this + 0x80) = afMax - afMin;
}

struct FUN_00e88760_Class {
    char m_auiShapeKeys[0xf4];
    int m_flag;
    int __thiscall SetFlag(bool b);
};
// @fnv 0x00e88760
int __thiscall FUN_00e88760_Class::SetFlag(bool b)
{
    m_flag = b != 0;
    return m_flag;
}

struct FUN_00e888c0_Class {
    int __thiscall CallVirtualWithMember();
};
// @fnv 0x00e888c0
int __thiscall FUN_00e888c0_Class::CallVirtualWithMember()
{
    void** vtbl = *reinterpret_cast<void***>(this);
    void* arg = *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x10ec);
    return reinterpret_cast<int(__thiscall*)(void*, void*, int)>(vtbl[31])(this, arg, 0);
}

struct FUN_00e891f0_Class {
    void __thiscall FUN_00e891f0();
};

// Zeroes two 8-byte arrays at offsets 0x2c and 0x5c, then clears the int fields at offsets 0x34 and 0x4.
// @fnv 0x00e891f0
void __thiscall FUN_00e891f0_Class::FUN_00e891f0()
{
    for (int i = 0; i < 8; ++i) {
        ((char*)this)[0x2c + i] = 0;
        ((char*)this)[0x5c + i] = 0;
    }
    *(int*)((char*)this + 0x34) = 0;
    *(int*)((char*)this + 4) = 0;
}

extern "C" void __cdecl operator delete(void* p, unsigned int size);
extern int DAT_010efc34;
void __cdecl FUN_00e68830();

struct FUN_00e8aa40_Class {
    int __thiscall FUN_00e8aa40(bool flag);
};

// @fnv 0x00e8aa40
int __thiscall FUN_00e8aa40_Class::FUN_00e8aa40(bool abFree)
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_010efc34);
    FUN_00e68830();
    if (abFree & 1)
        operator delete(this, 0x88);
    return (int)this;
}

// @fnv 0x00e8b490
void __stdcall FUN_00e8b490(int* paiValues, int iFirst, int iSecond)
{
    paiValues[1] = iFirst;
    paiValues[2] = iSecond;
}

struct NiTMapBaseStub { void RemoveAll(); };
extern NiTMapBaseStub* DAT_0126fa14;
// Calls RemoveAll on DAT_0126fa14, invokes its first virtual method with 1, then clears the pointer.
// @fnv 0x00e933d0
void FUN_00e933d0()
{
    DAT_0126fa14->RemoveAll();
    if (DAT_0126fa14)
        ((void (__thiscall*)(void*, int))(*reinterpret_cast<void***>(DAT_0126fa14))[0])(DAT_0126fa14, 1);
    DAT_0126fa14 = 0;
}

extern "C" void __cdecl FUN_00e93400();
struct MemoryManager { void __thiscall Deallocate(void*); };
extern MemoryManager g_memoryManager;
struct FUN_00e93650_Class {
    void* __thiscall FUN_00e93650(int unused);
};
// Calls FUN_00e93400, then deallocates this via g_memoryManager if the low bit of the argument is set, and returns this.
// @fnv 0x00e93650
void* __thiscall FUN_00e93650_Class::FUN_00e93650(int aiFlags)
{
    FUN_00e93400();
    if (aiFlags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

extern bool DAT_0126f0d0;
// Sets p[5] to 8 or 0x18 depending on the sign bit of p[2], and sets p[6] to 0 or 1 based on DAT_0126f0d0.
// @fnv 0x00e941a0
void __cdecl FUN_00e941a0(void* apData)
{
    int* p = (int*)apData;
    p[5] = 8;
    if (p[2] & 0x80000000)
        p[5] = 0x18;
    p[6] = DAT_0126f0d0 ? 0 : 1;
}

struct FUN_00e95b80_Class {
    void __thiscall FUN_00e95b80();
};
// @fnv 0x00e95b80
void __thiscall FUN_00e95b80_Class::FUN_00e95b80()
{
    void** p = *(void***)((char*)this + 0x10);
    if (p) {
        void** vtbl = *(void***)p;
        ((void (__stdcall*)(void**))vtbl[2])(p);
        *(void***)((char*)this + 0x10) = 0;
    }
}

struct FUN_00e97790_Class {
    int __thiscall InitFromSource(int a, int b);
};
struct BSFadeNode {
    static void* __cdecl operator new(unsigned int);
};
// @fnv 0x00e978a0
int __cdecl FUN_00e978a0(int a, int b)
{
    void* p = BSFadeNode::operator new(0x8c);
    if (p)
        return reinterpret_cast<FUN_00e97790_Class*>(p)->InitFromSource(a, b);
    return 0;
}

extern "C" void __cdecl NiFreeAlias(void*);
extern int DAT_010f0f7c;

struct FUN_00e98640_Class {
    void __thiscall FUN_00e98640();
};

// @fnv 0x00e98640
void __thiscall FUN_00e98640_Class::FUN_00e98640()
{
    void* p = *(void**)((char*)this + 0x30);
    *(int*)((char*)this + 0x2c) = (int)&DAT_010f0f7c;
    NiFreeAlias(p);
}

struct FUN_00e81d00_Class {
    char m_auiShapeKeys[0x38];
    void* m_pRenderState;
    void* m_pShaderObject;
    void* m_pD3DDevice;
    void __thiscall FUN_00e81d00(void* renderer);
};

// Stores the renderer, releases the previous object, AddRefs the renderer's field at 0x288, and caches the pointer at 0x8b8.
// @fnv 0x00e81d00
void __thiscall FUN_00e81d00_Class::FUN_00e81d00(void* renderer)
{
    m_pShaderObject = renderer;
    if (renderer)
    {
        void* state = *(void**)((char*)renderer + 0x288);
        if (m_pRenderState)
        {
            typedef void (__stdcall *ReleaseFunction)(void*);
            ReleaseFunction release = (ReleaseFunction)(*(void***)m_pRenderState)[2];
            release(m_pRenderState);
        }
        m_pRenderState = state;
        if (state)
        {
            typedef void (__stdcall *AddRefFunction)(void*);
            AddRefFunction addRef = (AddRefFunction)(*(void***)state)[1];
            addRef(state);
        }
        m_pD3DDevice = *(void**)((char*)m_pShaderObject + 0x8b8);
    }
    else
    {
        if (m_pRenderState)
        {
            typedef void (__stdcall *ReleaseFunction)(void*);
            ReleaseFunction release = (ReleaseFunction)(*(void***)m_pRenderState)[2];
            release(m_pRenderState);
        }
        m_pRenderState = 0;
        m_pD3DDevice = 0;
    }
}

struct NiD3DShaderFactory {
    void ShutdownPoint3();
    void FUN_00e87ab0();
};
// @fnv 0x00e87ab0
void NiD3DShaderFactory::FUN_00e87ab0()
{
    ((void (__thiscall*)(void*))(*(void***)this)[22])(this);
    ((void (__thiscall*)(void*))(*(void***)this)[28])(this);
    ((void (__thiscall*)(void*))(*(void***)this)[47])(this);
    ((void (__thiscall*)(void*))(*(void***)this)[54])(this);
    ((NiD3DShaderFactory*)((char*)this + 0xf8))->ShutdownPoint3();
}

struct FUN_00e87af0_This {
    void __thiscall FUN_00e87af0(void* renderer);
};
// @fnv 0x00e87af0
void __thiscall FUN_00e87af0_This::FUN_00e87af0(void* renderer)
{
    *(void**)((char*)this + 0x10fc) = renderer;
    if (renderer) {
        void* state = *(void**)((char*)renderer + 0x288);
        void* old = *(void**)((char*)this + 0x10f8);
        if (old) ((void (__stdcall*)(void*))(*(void***)old)[2])(old);
        *(void**)((char*)this + 0x10f8) = state;
        if (state) ((void (__stdcall*)(void*))(*(void***)state)[1])(state);
    } else {
        void* old = *(void**)((char*)this + 0x10f8);
        if (old) ((void (__stdcall*)(void*))(*(void***)old)[2])(old);
        *(void**)((char*)this + 0x10f8) = 0;
    }
}

struct FUN_00e886d0_Class {
    void __thiscall FUN_00e886d0(float a);
};
// Clamps a to a tiny minimum, stores it at offset 0x88, and stores 1/a - 1 at offset 0x84.
// @fnv 0x00e886d0
void __thiscall FUN_00e886d0_Class::FUN_00e886d0(float afValue)
{
    if (afValue <= 0.0f)
        afValue = 9.999999747378752e-06f;
    *(float*)((char*)this + 0x88) = afValue;
    *(float*)((char*)this + 0x84) = 1.0f / afValue - 1.0f;
}

struct FUN_00e88860_Class {
    int __thiscall FUN_00e88860(int idx);
};

// @fnv 0x00e88860
int __thiscall FUN_00e88860_Class::FUN_00e88860(int idx)
{
    return *(int*)((char*)this + 0x120 + idx * 8);
}

struct FUN_00e889b0_Class {
    void __thiscall ClearBlock();
};
// Zeroes sixteen consecutive ints starting at offset 0x10a0 of this object.
// @fnv 0x00e889b0
void __thiscall FUN_00e889b0_Class::ClearBlock()
{
    int* p = (int*)((char*)this + 0x10a0);
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    p[12] = 0;
    p[13] = 0;
    p[14] = 0;
    p[15] = 0;
}

struct FUN_00e88ab0_Class {
    void __thiscall FUN_00e88ab0(bool b);
};
// @fnv 0x00e88ab0
void __thiscall FUN_00e88ab0_Class::FUN_00e88ab0(bool b)
{
    ((char*)this)[0x10f4] = b;
}

struct FUN_00e88ad0_Class {
    void __thiscall FUN_00e88ad0(bool v);
};
// @fnv 0x00e88ad0
void __thiscall FUN_00e88ad0_Class::FUN_00e88ad0(bool v)
{
    *(char*)((char*)this + 0x10f5) = v;
}

struct FUN_00e88bb0_Class {
    void __thiscall ApplyFromArray(int* a);
};
// Calls four virtual methods on this, passing elements 3, 0, 4 and 2 of the given int array.
// @fnv 0x00e88bb0
void __thiscall FUN_00e88bb0_Class::ApplyFromArray(int* aiValues) {
    ((void (__thiscall *)(void*, int))(*reinterpret_cast<void***>(this))[7])(this, aiValues[3]);
    ((void (__thiscall *)(void*, int))(*reinterpret_cast<void***>(this))[3])(this, aiValues[0]);
    ((void (__thiscall *)(void*, int))(*reinterpret_cast<void***>(this))[9])(this, aiValues[4]);
    ((void (__thiscall *)(void*, int))(*reinterpret_cast<void***>(this))[6])(this, aiValues[2]);
}

// @fnv 0x00e89220
void __fastcall ClearFields(void* self)
{
    char* p = (char*)self + 0xa4;
    for (int i = 5; i; --i) {
        p[-0x24] = 0;
        *p = 0;
        p[0xc] = 0;
        ++p;
    }
    *(int*)((char*)self + 0x88) = 0;
    *(int*)((char*)self + 0x64) = 0;
    *(int*)((char*)self + 0xac) = 0;
}

extern "C" void __cdecl FUN_00aa1490(void*, unsigned int);
struct FUN_00e89560_Class {
    void* m_ptr;
    void* m_obj;
    void __thiscall FUN_00e89560();
};
// @fnv 0x00e89560
void __thiscall FUN_00e89560_Class::FUN_00e89560()
{
    if (m_ptr)
        FUN_00aa1490((char*)m_ptr - 4, 0xb8);
    void* obj = *(void**)((char*)this + 8);
    if (obj)
    {
        ((FUN_00e89560_Class*)obj)->FUN_00e89560();
        g_memoryManager.Deallocate(obj);
    }
}

extern int DAT_0126f9a0;

struct P03MM { void* __thiscall Allocate(unsigned int); };

// @fnv 0x00e895f0
void FUN_00e895f0()
{
    void* p = reinterpret_cast<P03MM*>(&g_memoryManager)->Allocate(0x18);
    if (p)
    {
        *(int*)p = 0;
        *(int*)((char*)p + 4) = 0;
        *(int*)((char*)p + 8) = 0;
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 8;
        *(int*)((char*)p + 0x14) = 8;
        DAT_0126f9a0 = (int)p;
    }
    else
        DAT_0126f9a0 = 0;
}

struct NiConsoleRendererStub {
    void* m_pCurrentRenderState;
    void* m_pD3DDevice;
};
struct NiConsoleRenderStateStub {
    void* m_ppVirtualMethodTable;
};
struct FUN_00e89760_Class {
    void __thiscall FUN_00e89760(NiConsoleRendererStub* renderer);
};
// @fnv 0x00e89760
void __thiscall FUN_00e89760_Class::FUN_00e89760(NiConsoleRendererStub* renderer)
{
    *(NiConsoleRendererStub**)((char*)this + 0x24) = renderer;
    if (renderer)
    {
        NiConsoleRenderStateStub* state = (NiConsoleRenderStateStub*)*(void**)((char*)renderer + 0x288);
        NiConsoleRenderStateStub* old = *(NiConsoleRenderStateStub**)((char*)this + 0x20);
        if (old)
        {
            void (__stdcall *Release)(NiConsoleRenderStateStub*) =
                (void (__stdcall *)(NiConsoleRenderStateStub*))*(void**)((void**)old->m_ppVirtualMethodTable + 2);
            Release(old);
        }
        *(NiConsoleRenderStateStub**)((char*)this + 0x20) = state;
        if (state)
        {
            void (__stdcall *AddRef)(NiConsoleRenderStateStub*) =
                (void (__stdcall *)(NiConsoleRenderStateStub*))*(void**)((void**)state->m_ppVirtualMethodTable + 1);
            AddRef(state);
        }
        *(void**)((char*)this + 0x28) = *(void**)((char*)*(NiConsoleRendererStub**)((char*)this + 0x24) + 0x8b8);
    }
    else
    {
        NiConsoleRenderStateStub* old = *(NiConsoleRenderStateStub**)((char*)this + 0x20);
        *(void**)((char*)this + 0x28) = 0;
        if (old)
        {
            void (__stdcall *Release)(NiConsoleRenderStateStub*) =
                (void (__stdcall *)(NiConsoleRenderStateStub*))*(void**)((void**)old->m_ppVirtualMethodTable + 2);
            Release(old);
        }
        *(NiConsoleRenderStateStub**)((char*)this + 0x20) = 0;
    }
}

extern int DAT_011f4500;

struct ShaderNode {
    virtual void Release(int);
};

// Walks the linked list at DAT_011f4500, releasing each node's shader at offset 0x24 and following the next pointer at 0x2c.
// @fnv 0x00e8a9b0
void __cdecl ReleaseShaderNodes()
{
    int node = DAT_011f4500;
    if (node)
    {
        do
        {
            int shader = *(int*)(node + 0x24);
            if (shader)
            {
                *(int*)(node + 0x24) = 0;
                reinterpret_cast<ShaderNode*>(shader)->Release(1);
            }
            node = *(int*)(node + 0x2c);
        } while (node);
    }
}

struct NiD3DShaderProgramCreator { virtual ~NiD3DShaderProgramCreator(); };
struct NiD3DShaderProgramFactory {
    static bool __cdecl RegisterCreator(const char*, NiD3DShaderProgramCreator*);
};
struct FUN_00e91b90_Class : NiD3DShaderProgramCreator {
    virtual ~FUN_00e91b90_Class();
    int m_auiShapeKeys[3];
};
extern FUN_00e91b90_Class* DAT_0126fa54;
extern const unsigned char DAT_010bc868[];
extern int DAT_010f0af4;
// @fnv 0x00e91b90
void __cdecl FUN_00e91b90()
{
    FUN_00e91b90_Class* p = (FUN_00e91b90_Class*)BSFadeNode::operator new(0x10);
    if (p) {
        p->m_auiShapeKeys[0] = 0;
        p->m_auiShapeKeys[1] = 0;
        p->m_auiShapeKeys[2] = 0;
        *(int*)p = (int)&DAT_010f0af4;
    } else {
        p = 0;
    }
    DAT_0126fa54 = p;
    NiD3DShaderProgramFactory::RegisterCreator((const char*)DAT_010bc868, p);
    NiD3DShaderProgramFactory::RegisterCreator("pso", DAT_0126fa54);
}

namespace fnv_00e91dc0 {
struct NiD3DShader { static void __cdecl InitializePoint3(void); };
struct NiD3DShaderFactory { static void __cdecl InitializePoint3(void); };
extern bool DAT_0126fa00;
void __cdecl AddKeyToList(int);
void __cdecl FUN_00e7f2b0();
void __cdecl FUN_00e895f0();
void __cdecl FUN_00e80620();
void __cdecl FUN_00e7a860();
void __cdecl FUN_00e93df0();
void __cdecl FUN_00e91b40();
void __cdecl FUN_00e91b90();
void __cdecl CreateHLSLShaderProgramCreator();

// @fnv 0x00e91dc0
void __cdecl FUN_00e91dc0()
{
    if (!DAT_0126fa00) {
        DAT_0126fa00 = true;
        AddKeyToList(21);
        AddKeyToList(22);
        AddKeyToList(25);
        AddKeyToList(24);
        AddKeyToList(23);
        FUN_00e7f2b0();
        FUN_00e895f0();
        FUN_00e80620();
        FUN_00e7a860();
        NiD3DShaderFactory::InitializePoint3();
        FUN_00e93df0();
        FUN_00e91b40();
        FUN_00e91b90();
        CreateHLSLShaderProgramCreator();
        NiD3DShader::InitializePoint3();
    }
}
}  // namespace fnv_00e91dc0

extern int DAT_010f0e50;
extern int DAT_010f0e70;
extern "C" void __cdecl NiFree(void*);

struct FUN_00e936b0_Class {
    int* m_kPointA;
    int* m_kPointB;
    void* m_iThirdValue;
    void* __thiscall DestroyMapBase(int unused);
};

// @fnv 0x00e936b0
void* __thiscall FUN_00e936b0_Class::DestroyMapBase(int aiFlags)
{
    *reinterpret_cast<int**>(this) = &DAT_010f0e70;
    reinterpret_cast<NiTMapBaseStub*>(this)->RemoveAll();
    *reinterpret_cast<int**>(this) = &DAT_010f0e50;
    reinterpret_cast<NiTMapBaseStub*>(this)->RemoveAll();
    NiFree(m_iThirdValue);
    if (aiFlags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

extern int DAT_010f0eb0;
extern int DAT_010f0ed0;
void __cdecl NiFree(void*);

struct FUN_00e93750_Class {
    void* __thiscall FUN_00e93750(int unused);
};

// Resets the two vtable pointers, clears both map bases, frees the pointer at offset 8, and optionally deallocates this.
// @fnv 0x00e93750
void* __thiscall FUN_00e93750_Class::FUN_00e93750(int unused)
{
    *(int**)this = &DAT_010f0ed0;
    ((NiTMapBaseStub*)this)->RemoveAll();
    *(int**)this = &DAT_010f0eb0;
    ((NiTMapBaseStub*)this)->RemoveAll();
    NiFree(*(void**)(this + 8));
    if (unused & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

struct FUN_00e941d0_Node { unsigned int pad[9]; unsigned int count; unsigned int pad2[5]; FUN_00e941d0_Node* next; FUN_00e941d0_Node* prev; };
struct FUN_00e941d0_This { int pad[11]; FUN_00e941d0_Node* head; };
// Walks the linked list from head to the first node whose count is at least value, unlinks it, and returns it (or null).
// @fnv 0x00e941d0
FUN_00e941d0_Node* __fastcall RemoveFirstNodeAtLeast(FUN_00e941d0_This* self, int, unsigned int value)
{
    FUN_00e941d0_Node* node = 0;
    FUN_00e941d0_Node* current = self->head;
    while (current && current->count < value)
        current = current->next;
    if (current) {
        node = current;
        if (node->next)
            node->next->prev = node->prev;
        if (node->prev)
            node->prev->next = node->next;
        if (node == self->head)
            self->head = node->next;
    }
    return node;
}

extern "C" void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00e98610_Node {
    void* m_next;
    void* m_auiShapeKeys;
    void* m_data;
    void* m_pAuxiliaryObject;
    void* m_pad3;
    void* m_pad4;
    void* m_pSecondNode;
};

extern int DAT_0126fa58;

// Walks the list at DAT_0126fa58, clears each node's field 2, frees the node, then sets DAT_0126fa58 to 0.
// @fnv 0x00e98610
void __cdecl FreeNodeList()
{
    int* node = (int*)DAT_0126fa58;
    while (node) {
        int* next = (int*)node[6];
        node[2] = 0;
        operator delete((void*)node, 0x20);
        node = next;
    }
    DAT_0126fa58 = 0;
}

struct FUN_00e89350_Class {
    unsigned char m_00;
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
    unsigned char m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    unsigned char m_a8;
    int m_ac;
    int m_b0;
    unsigned char m_b4;
    FUN_00e89350_Class();
};
// Zero-initializes all member fields of the object.
// @fnv 0x00e89350
FUN_00e89350_Class::FUN_00e89350_Class()
{
    m_00 = 0;
    m_04 = 0;
    m_08 = 0;
    m_34 = 0;
    m_38 = 0;
    m_64 = 0;
    m_68 = 0;
    m_88 = 0;
    m_8c = 0;
    m_ac = 0;
    m_0c = 0;
    m_10 = 0;
    m_14 = 0;
    m_18 = 0;
    m_1c = 0;
    m_20 = 0;
    m_24 = 0;
    m_28 = 0;
    m_2c = 0;
    m_30 = 0;
    m_3c = 0;
    m_40 = 0;
    m_44 = 0;
    m_48 = 0;
    m_4c = 0;
    m_50 = 0;
    m_54 = 0;
    m_58 = 0;
    m_5c = 0;
    m_60 = 0;
    m_6c = 0;
    m_70 = 0;
    m_74 = 0;
    m_78 = 0;
    m_7c = 0;
    m_80 = 0;
    m_84 = 0;
    m_90 = 0;
    m_94 = 0;
    m_98 = 0;
    m_9c = 0;
    m_a0 = 0;
    m_a4 = 0;
    m_a8 = 0;
    m_b0 = 0;
    m_b4 = 0;
}

struct NiColor { float m_r; float m_g; float m_kPointB; float m_kPointA; };
extern NiColor DAT_011f4998;
extern NiColor DAT_011f499c;
extern NiColor DAT_011f49a0;
struct FUN_00e93fb0_Class {
    char __thiscall CopyColorIfChanged(FUN_00e93fb0_Class* p);
};
// If the value at offset 0x44 differs from p's, copies p's color, alpha and related floats into this and returns 1; otherwise returns 0.
// @fnv 0x00e93fb0
char __thiscall FUN_00e93fb0_Class::CopyColorIfChanged(FUN_00e93fb0_Class* apSource)
{
    if (*(int*)((char*)this + 0x44) != *(int*)((char*)apSource + 0x44)) {
        *(int*)((char*)this + 0x44) = *(int*)((char*)apSource + 0x44);
        NiColor* c = (NiColor*)(*(NiColor**)((char*)apSource + 0x34) ? *(NiColor**)((char*)apSource + 0x34) : (NiColor*)((char*)apSource + 0x28));
        float a = *(float*)((char*)apSource + 0x3c);
        *(float*)((char*)this + 0x30) = c->m_r;
        *(float*)((char*)this + 0x34) = c->m_g;
        *(float*)((char*)this + 0x38) = c->m_kPointB;
        *(float*)((char*)this + 0x3c) = a;
        *(float*)((char*)this + 0x10) = DAT_011f4998.m_r;
        *(float*)((char*)this + 0x14) = DAT_011f499c.m_r;
        *(float*)((char*)this + 0x18) = DAT_011f49a0.m_r;
        *(float*)((char*)this + 0x1c) = a;
        *(float*)((char*)this + 0x00) = DAT_011f4998.m_r;
        *(float*)((char*)this + 0x04) = DAT_011f499c.m_r;
        *(float*)((char*)this + 0x08) = DAT_011f49a0.m_r;
        *(float*)((char*)this + 0x0c) = a;
        *(float*)((char*)this + 0x20) = *(float*)((char*)apSource + 0x1c);
        *(float*)((char*)this + 0x24) = *(float*)((char*)apSource + 0x20);
        *(float*)((char*)this + 0x28) = *(float*)((char*)apSource + 0x24);
        *(float*)((char*)this + 0x2c) = a;
        *(float*)((char*)this + 0x40) = *(float*)((char*)apSource + 0x38);
        return 1;
    }
    return 0;
}

struct FUN_00e8a1f0_Class {
    char __thiscall GetEntryData(int b, int* c, int* d, char* e, char* f);
};
// Reads the entry at index b (stride 12) and writes its two bytes, int field and int at offset 0x14 into f, e, d and c; returns whether that int is not 0x13.
// @fnv 0x00e8a1f0
char FUN_00e8a1f0_Class::GetEntryData(int aiIndex, int* piValue, int* piField, char* pcByte1, char* pcByte2)
{
    *pcByte2 = *(char*)((char*)this + aiIndex * 12 + 0x1d);
    *pcByte1 = *(char*)((char*)this + aiIndex * 12 + 0x1c);
    *piField = *(int*)((char*)this + aiIndex * 12 + 24);
    int v = *(int*)((char*)this + aiIndex * 12 + 0x14);
    *piValue = v;
    return v != 0x13;
}

extern int DAT_010f0ac0;
extern int DAT_0126fa50;
// @fnv 0x00e91b40
void __cdecl FUN_00e91b40()
{
    NiD3DShaderProgramCreator* p = (NiD3DShaderProgramCreator*)BSFadeNode::operator new(0x10);
    if (p) {
        *(int*)p = (int)&DAT_010f0ac0;
        *(int*)(p + 1) = 0;
        *(int*)(p + 2) = 0;
        *(int*)(p + 3) = 0;
    } else {
        p = 0;
    }
    DAT_0126fa50 = (int)p;
    NiD3DShaderProgramFactory::RegisterCreator("vsh", (NiD3DShaderProgramCreator*)DAT_0126fa50);
    NiD3DShaderProgramFactory::RegisterCreator("psh", (NiD3DShaderProgramCreator*)DAT_0126fa50);
}

struct NiD3DRenderStateStub {
    char m_auiShapeKeys[0x10e8];
    int m_10e8;
    int m_10ec;
    char m_pAuxiliaryObject[0x10f8 - 0x10f0];
    void* m_10f8;
    void ClearRenderState(int arg);
};

// If m_10e8 equals arg, resets m_10e8 to 0 and calls a virtual function on m_10f8 with 0; if m_10ec equals arg, resets m_10ec to 0.
// @fnv 0x00e888e0
void NiD3DRenderStateStub::ClearRenderState(int arg)
{
    if (m_10e8 == arg)
    {
        void* p = m_10f8;
        m_10e8 = 0;
        void** vt = *(void***)p;
        void (__stdcall *fn)(void*, int) = (void (__stdcall *)(void*, int))vt[0x1ac / 4];
        fn(p, 0);
    }
    if (m_10ec == arg)
        m_10ec = 0;
}

struct FUN_00e879e0_Class {
    void __thiscall FUN_00e879e0(float* p);
};

// Calls virtual slot 0x1a with 0x8f and 0 or 1 depending on whether p[0xc] is near 1 and two bytes at this+0x10f5/0x10f4 are clear.
// @fnv 0x00e879e0
void __thiscall FUN_00e879e0_Class::FUN_00e879e0(float* pfValue)
{
    if (pfValue[0xc] >= 0.99f && pfValue[0xc] <= 1.01f && !*(unsigned char*)((char*)this + 0x10f5) && !*(unsigned char*)((char*)this + 0x10f4))
    {
        void** vtbl = *(void***)this;
        ((void (__thiscall*)(void*, int, int, int, int))vtbl[0x1a])(this, 0x8f, 0, 0, 0);
    }
    else
    {
        void** vtbl = *(void***)this;
        ((void (__thiscall*)(void*, int, int, int, int))vtbl[0x1a])(this, 0x8f, 1, 0, 0);
    }
}

struct FUN_00e887d0_Class {
    char m_auiShapeKeys[0x1b8];
    int m_field1b8;
    char m_pAuxiliaryObject[0x4];
    int m_field1c0;
    char m_pad3[0xf34];
    void* m_field10f8;
    void __thiscall SetFieldValues(int a, int b, int c, int d);
};

// If the stored values differ from a and b, calls virtual slot 0x39 on m_field10f8 with 0x13/0x14, then stores a and b.
// @fnv 0x00e887d0
void FUN_00e887d0_Class::SetFieldValues(int aiValue1, int aiValue2, int aiUnused1, int aiUnused2)
{
    if (m_field1b8 != aiValue1)
    {
        void* p = m_field10f8;
        void** vt = *(void***)p;
        void (__stdcall *fn)(void*, int, int) = (void (__stdcall *)(void*, int, int))vt[0x39];
        fn(p, 0x13, aiValue1);
    }
    m_field1b8 = aiValue1;
    if (m_field1c0 != aiValue2)
    {
        void* p = m_field10f8;
        void** vt = *(void***)p;
        void (__stdcall *fn)(void*, int, int) = (void (__stdcall *)(void*, int, int))vt[0x39];
        fn(p, 0x14, aiValue2);
    }
    m_field1c0 = aiValue2;
}

struct FUN_00e88b00_Class {
    int m_auiShapeKeys[0x1100 / 4];
    virtual ~FUN_00e88b00_Class();
    int __thiscall FUN_00e88b00();
    int __thiscall DestroyIfFlagged(bool flag);
};
// Calls FUN_00e88b00, then deletes this with size 0x1100 if flag bit 0 is set, and returns this.
// @fnv 0x00e88bf0
int FUN_00e88b00_Class::DestroyIfFlagged(bool abDelete)
{
    FUN_00e88b00();
    if (abDelete & 1)
        operator delete(this, 0x1100);
    return (int)this;
}

// @fnv 0x00e8a240
unsigned int __fastcall FUN_00e8a240(char* self, int)
{
    unsigned int count = 0;
    char* p = self + 0x14;
    while (count < 4) {
        if (*reinterpret_cast<int*>(p) == 0x13)
            return count;
        ++count;
        p += 0xc;
    }
    return 4;
}

void __cdecl _NiFree(void* p);

struct FUN_00e8b4e0_Class : NiTMapBaseStub {
    void* m_auiShapeKeys;
    void* m_pAuxiliaryObject;
    void* m_ptr;
    void* __thiscall FUN_00e8b4e0(unsigned int flags);
};

extern int DAT_010efdd8;

// Sets the vtable, removes all entries, releases m_ptr, and frees this when flags has bit 0 set; returns this.
// @fnv 0x00e8b4e0
void* __thiscall FUN_00e8b4e0_Class::FUN_00e8b4e0(unsigned int flags)
{
    *(void**)this = (void*)&DAT_010efdd8;
    RemoveAll();
    _NiFree(m_ptr);
    if (flags & 1) {
        g_memoryManager.Deallocate(this);
    }
    return this;
}

struct FUN_00e8b520_Class : NiTMapBaseStub {
    void* __thiscall FUN_00e8b520(int deletingFlag);
};

extern int DAT_010efdf8;
extern int DAT_010efdd8;
void __cdecl _NiFree(void* p);

// Resets two vtable pointers, calls RemoveAll on both bases, releases the pointer at offset 8, and frees this when deletingFlag has bit 0 set.
// @fnv 0x00e8b520
void* __thiscall FUN_00e8b520_Class::FUN_00e8b520(int deletingFlag)
{
    *reinterpret_cast<void**>(this) = reinterpret_cast<void*>(&DAT_010efdf8);
    NiTMapBaseStub::RemoveAll();

    *reinterpret_cast<void**>(this) = reinterpret_cast<void*>(&DAT_010efdd8);
    NiTMapBaseStub::RemoveAll();

    _NiFree(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 8));

    if (deletingFlag & 1) {
        g_memoryManager.Deallocate(this);
    }

    return this;
}

void __cdecl _NiFree(void* p);
extern int DAT_010efe54;
extern MemoryManager _g_memoryManager;

struct FUN_00e8ce30_Class : NiTMapBaseStub {
    int m_auiShapeKeys[2];
    void* m_pUnk08;
    FUN_00e8ce30_Class(int flags);
};

// @fnv 0x00e8ce30
FUN_00e8ce30_Class::FUN_00e8ce30_Class(int flags)
{
    *(void**)this = (void*)&DAT_010efe54;
    RemoveAll();
    _NiFree(m_pUnk08);
    if (flags & 1)
        _g_memoryManager.Deallocate(this);
}

extern int DAT_010efe54;
extern int DAT_010efe74;
extern MemoryManager _g_memoryManager;
void __cdecl _NiFree(void*);

struct FUN_00e8ce70_Class : NiTMapBaseStub {
    void* m_ppVirtualMethodTable;
    unsigned int m_auiShapeKeys;
    void* m_data;

    void* __thiscall FUN_00e8ce70(int flag);
};

// Resets both map bases, frees m_data, and optionally deallocates the object when flag bit 0 is set.
// @fnv 0x00e8ce70
void* __thiscall FUN_00e8ce70_Class::FUN_00e8ce70(int flag)
{
    m_ppVirtualMethodTable = &DAT_010efe74;
    RemoveAll();

    m_ppVirtualMethodTable = &DAT_010efe54;
    RemoveAll();

    _NiFree(m_data);

    if (flag & 1) {
        _g_memoryManager.Deallocate(this);
    }

    return this;
}

extern "C" void __cdecl operator delete(void*, unsigned int);
struct FUN_00e8ceb0_Class {
    void __thiscall FUN_00e8ceb0();
    void* __thiscall FUN_00e8d200(bool flag);
};
// Calls FUN_00e8ceb0, then if flag bit 0 is set frees this with operator delete, and returns this.
// @fnv 0x00e8d200
void* FUN_00e8ceb0_Class::FUN_00e8d200(bool abFree)
{
    FUN_00e8ceb0();
    if (abFree & 1)
        operator delete(this, 0x100);
    return this;
}

struct FUN_00e8f800_Class {
    void* m_vptr;
    char m_auiShapeKeys[4];
    void* m_data;

    void* __thiscall FUN_00e8f800(bool deleting);
};

extern unsigned char DAT_010f02b0[];
extern unsigned char DAT_010f02d0[];
extern MemoryManager _g_memoryManager;
void __cdecl _NiFree(void* p);

// Restores two vtable pointers, clears the map twice, releases m_data, and frees this when deleting is set.
// @fnv 0x00e8f800
void* __thiscall FUN_00e8f800_Class::FUN_00e8f800(bool deleting)
{
    m_vptr = DAT_010f02d0;
    reinterpret_cast<NiTMapBaseStub*>(this)->RemoveAll();

    m_vptr = DAT_010f02b0;
    reinterpret_cast<NiTMapBaseStub*>(this)->RemoveAll();

    _NiFree(m_data);

    if (deleting & 1) {
        _g_memoryManager.Deallocate(this);
    }

    return this;
}

extern int DAT_0126fa04;
void __cdecl FUN_00aa2080(void*, void*);
void __cdecl FUN_00e91dc0();
void __cdecl FUN_00e91c80();
struct FUN_00e91e30_This {
    void* FUN_00e91e30();
};
// @fnv 0x00e91e30
void* FUN_00e91e30_This::FUN_00e91e30()
{
    int old = DAT_0126fa04;
    ++DAT_0126fa04;
    if (!old)
        FUN_00aa2080((void*)FUN_00e91dc0, (void*)FUN_00e91c80);
    return this;
}

extern void* DAT_0126fa0c;

struct FUN_00e92080_This {
    virtual void Release(int);
};

// @fnv 0x00e92080
void FUN_00e92080()
{
    FUN_00e92080_This* p = (FUN_00e92080_This*)DAT_0126fa0c;
    if (p) {
        p->Release(1);
        DAT_0126fa0c = 0;
    }
}

extern int DAT_010f0df0;
extern int DAT_010f0e10;
extern int DAT_010f0e30;

void __cdecl _NiFree(void* p);

struct FUN_00e93400_Class {
    void __thiscall FUN_00e93400();
};

// @fnv 0x00e93400
void __thiscall FUN_00e93400_Class::FUN_00e93400()
{
    char* self = reinterpret_cast<char*>(this);
    *(int*)self = (int)&DAT_010f0e30;
    if (self[0x10])
    {
        unsigned int i = 0;
        if (*(unsigned int*)(self + 4) > 0)
        {
            do
            {
                void* node = *(void**)(*(int*)(self + 8) + i * 4);
                if (node)
                {
                    do
                    {
                        void* cur = node;
                        node = *(void**)node;
                        _NiFree(*(void**)((char*)cur + 4));
                    } while (node);
                }
                i++;
            } while (i < *(unsigned int*)(self + 4));
        }
    }
    *(int*)self = (int)&DAT_010f0e10;
    ((NiTMapBaseStub*)self)->RemoveAll();
    *(int*)self = (int)&DAT_010f0df0;
    ((NiTMapBaseStub*)self)->RemoveAll();
    _NiFree(*(void**)(self + 8));
}

extern int DAT_010f0e90;
void _NiFree(void* p);

struct FUN_00e934d0_Class {
    void FUN_00e934d0();
};

// @fnv 0x00e934d0
void FUN_00e934d0_Class::FUN_00e934d0()
{
    *(int*)this = (int)&DAT_010f0e90;
    if (*(char*)((char*)this + 0x10)) {
        unsigned int i = 0;
        if (*(unsigned int*)((char*)this + 4) > 0) {
            do {
                int* node = *(int**)(*(char**)((char*)this + 8) + i * 4);
                if (node) {
                    do {
                        int* cur = node;
                        node = (int*)*node;
                        _NiFree((void*)cur[1]);
                    } while (node);
                }
                ++i;
            } while (i < *(unsigned int*)((char*)this + 4));
        }
    }
    *(int*)this = (int)&DAT_010f0e70;
    ((NiTMapBaseStub*)this)->RemoveAll();
    *(int*)this = (int)&DAT_010f0e50;
    ((NiTMapBaseStub*)this)->RemoveAll();
    _NiFree(*(void**)((char*)this + 8));
}

struct FUN_00e935b0_Class {
    char m_auiShapeKeys[0x10];
    bool m_flag;
    void FreeIfFlagged(int* a);
};

// @fnv 0x00e935b0
void FUN_00e935b0_Class::FreeIfFlagged(int* a)
{
    if (m_flag)
        NiFree(*(void**)(a + 1));
}

extern int DAT_010f0df0;
extern "C" void __cdecl NiFree(void*);

struct FUN_00e935d0 : NiTMapBaseStub {
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    void* m_data;
    FUN_00e935d0(int unused);
};

// Initialises the map base vtable, clears all entries, frees the data buffer, and deallocates the object when the low bit of unused is set.
// @fnv 0x00e935d0
FUN_00e935d0::FUN_00e935d0(int unused)
{
    *(int*)this = (int)&DAT_010f0df0;
    RemoveAll();
    NiFree(m_data);
    if (unused & 1)
        g_memoryManager.Deallocate(this);
}

extern int DAT_010f0df0;
extern int DAT_010f0e10;
extern MemoryManager _g_memoryManager;

struct FUN_00e93610_Class {
    void* m_vptr;
    char m_auiShapeKeys[3];
    void* m_data;

    FUN_00e93610_Class* __thiscall FUN_00e93610(int flags);
};

// Resets two vtable pointers, clears both map bases, frees m_data, and deallocates this when flags has bit 0 set.
// @fnv 0x00e93610
FUN_00e93610_Class* __thiscall FUN_00e93610_Class::FUN_00e93610(int flags)
{
    m_vptr = reinterpret_cast<void*>(&DAT_010f0e10);
    reinterpret_cast<NiTMapBaseStub*>(this)->RemoveAll();

    m_vptr = reinterpret_cast<void*>(&DAT_010f0df0);
    reinterpret_cast<NiTMapBaseStub*>(this)->RemoveAll();

    NiFree(m_data);

    if (flags & 1) {
        _g_memoryManager.Deallocate(this);
    }

    return this;
}

void __cdecl NiFree(void* p);
extern int DAT_010f0e50;
extern MemoryManager g_memoryManager;

struct FUN_00e93670_Class {
    void* m_ppVirtualMethodTable;
    void* m_auiShapeKeys;
    void* m_ptr;
    void* __thiscall FUN_00e93670(int unused);
};

// Resets the map, frees m_ptr, and optionally deallocates the object when the low bit of unused is set.
// @fnv 0x00e93670
void* FUN_00e93670_Class::FUN_00e93670(int aiFlags)
{
    m_ppVirtualMethodTable = &DAT_010f0e50;
    ((NiTMapBaseStub*)this)->RemoveAll();
    NiFree(m_ptr);
    if (aiFlags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

void __cdecl FUN_00e934d0();
struct FUN_00e936f0_Class {
    void __thiscall FUN_00e934d0();
    void* __thiscall FUN_00e936f0(bool b);
};
// @fnv 0x00e936f0
void* __thiscall FUN_00e936f0_Class::FUN_00e936f0(bool abFree)
{
    FUN_00e934d0();
    if (abFree & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

void __cdecl _NiFree(void* p);

struct FUN_00e93710_Class : NiTMapBaseStub {
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    void* m_ptr;
    void* __thiscall FUN_00e93710(int unused);
};

// Sets the vtable, clears all entries, releases m_ptr, and frees this when the low bit of unused is set.
// @fnv 0x00e93710
void* __thiscall FUN_00e93710_Class::FUN_00e93710(int aiFlags)
{
    *(int*)this = (int)&DAT_010f0eb0;
    RemoveAll();
    _NiFree(m_ptr);
    if (aiFlags & 1) {
        g_memoryManager.Deallocate(this);
    }
    return this;
}

struct NiTMapBase {
    bool __thiscall RemoveAt(const char* name);
};

struct Program {
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
    virtual const char* v50();

    void* m_auiShapeKeys[5];
    NiTMapBase* m_map;
};

Program* DAT_0126fa10;

// If both the global Program and the given program are non-null, gets the program's name and removes it from the global Program's map.
// @fnv 0x00e937c0
void __cdecl RemoveProgramFromMap(Program* program)
{
    if (DAT_0126fa10 && program)
    {
        const char* name = program->v50();
        if (name)
        {
            NiTMapBase* map = DAT_0126fa10->m_map;
            if (map)
                map->RemoveAt(name);
        }
    }
}

struct FUN_00e94070_Class {
    void* m_obj;
    char m_auiShapeKeys[0x48 - 4];
    void* m_ptr;
    void __thiscall ReleaseOwnedObject(FUN_00e94070_Class* p);
};
// If p and p->m_ptr are set, clears p->m_ptr, clears m_obj when it matched the old pointer, and deletes the old block.
// @fnv 0x00e94070
void __thiscall FUN_00e94070_Class::ReleaseOwnedObject(FUN_00e94070_Class* apOwner)
{
    if (apOwner && apOwner->m_ptr) {
        void* old = apOwner->m_ptr;
        apOwner->m_ptr = 0;
        if (old == m_obj)
            m_obj = 0;
        operator delete(old, 0x48);
    }
}

struct FUN_00e942d0_Class {
    void __thiscall FUN_00e942d0();
};
extern int DAT_0126fa30;

// @fnv 0x00e94330
void __stdcall FUN_00e94330(void* p)
{
    if (!p)
        return;

    void** obj = (void**)p;
    if (obj[2])
    {
        void* v = obj[2];
        void** vtbl = *(void***)v;
        void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vtbl[2];
        fn(v);
        obj[2] = 0;
    }

    ((FUN_00e942d0_Class*)p)->FUN_00e942d0();

    void* prev = obj[15];
    void* next = obj[16];
    if (prev)
        *(void**)((char*)prev + 0x40) = next;
    if (next)
        *(void**)((char*)next + 0x3c) = prev;

    void* head = (void*)DAT_0126fa30;
    if (head)
        *(void**)((char*)head + 0x40) = p;
    void* newhead = (void*)DAT_0126fa30;
    obj[15] = newhead;
    obj[16] = 0;
    DAT_0126fa30 = (int)p;
}

void __cdecl _NiFree(void* p);

struct FUN_00e94390_Class {
    void* m_vptr;
    void* m_ptr;

    void* __thiscall FUN_00e94390(int flags);
};

// @fnv 0x00e94390
void* __thiscall FUN_00e94390_Class::FUN_00e94390(int flags)
{
    void* p = m_ptr;
    m_vptr = reinterpret_cast<void*>(&DAT_010f0f7c);
    _NiFree(p);

    if (flags & 1) {
        g_memoryManager.Deallocate(this);
    }

    return this;
}

extern int DAT_010f0f94;
extern int DAT_010f0fb4;
extern MemoryManager _g_memoryManager;
void __cdecl _NiFree(void*);

struct FUN_00e94850_Class {
    int* m_ppVirtualMethodTable;
    int m_auiShapeKeys;
    void* m_data;

    int* __thiscall FUN_00e94850(int deleting);
};

// @fnv 0x00e94850
int* __thiscall FUN_00e94850_Class::FUN_00e94850(int deleting)
{
    m_ppVirtualMethodTable = &DAT_010f0fb4;
    reinterpret_cast<NiTMapBaseStub*>(this)->RemoveAll();

    m_ppVirtualMethodTable = &DAT_010f0f94;
    reinterpret_cast<NiTMapBaseStub*>(this)->RemoveAll();

    _NiFree(m_data);

    if (deleting & 1) {
        _g_memoryManager.Deallocate(this);
    }

    return reinterpret_cast<int*>(this);
}

extern int DAT_010f10f4;

struct FUN_00e89970_Object {
    virtual void FUN_00e89970_Object_0();
    virtual void FUN_00e89970_Object_1();
    virtual void __stdcall FUN_00e89970_Object_2();
};

struct FUN_00e96c90_Class {
    void* m_ppVirtualMethodTable;
    unsigned char m_auiShapeKeys[0x2c];
    void* m_30;
    void* m_34;
    FUN_00e89970_Object* m_38;

    void __thiscall FUN_00e89970();
    void __thiscall FUN_00e96c90();
};

// @fnv 0x00e96c90
void __thiscall FUN_00e96c90_Class::FUN_00e96c90()
{
    m_ppVirtualMethodTable = &DAT_010f10f4;
    NiFree(m_30);
    NiFree(m_34);

    if (m_38) {
        m_38->FUN_00e89970_Object_2();
        m_38 = 0;
    }

    FUN_00e89970();
}

extern "C" void __cdecl operator delete(void* p, unsigned int size);
void __cdecl FUN_00e989c0();
extern int DAT_010f1550;

struct FUN_00e97870_Class {
    void* m_ppVirtualMethodTable;
    FUN_00e97870_Class(unsigned char flag);
};

// @fnv 0x00e97870
FUN_00e97870_Class::FUN_00e97870_Class(unsigned char flag) {
    m_ppVirtualMethodTable = &DAT_010f1550;
    FUN_00e989c0();
    if (flag & 1)
        operator delete(this, 0x8c);
}

extern unsigned int DAT_011c1118;
extern int DAT_0126fa58;

struct A51BF0Base {
    static void* __cdecl operator new(unsigned int);
};

// Allocates DAT_011c1118 zero-initialised 0x20-byte nodes, links each to the previous head via offsets 0x1c and 0x18, and updates DAT_0126fa58 to the new head.
// @fnv 0x00e985a0
void AllocateNodeList()
{
    unsigned int i = 0;
    if (DAT_011c1118 > 0) {
        do {
            void* mem = A51BF0Base::operator new(0x20);
            int* node;
            if (mem != 0) {
                node = (int*)mem;
                node[0] = 0;
                node[1] = 0;
                node[2] = 0;
                node[3] = 0;
                node[5] = 0;
                node[4] = 0;
                node[6] = 0;
                node[7] = 0;
            } else {
                node = 0;
            }
            int prev = DAT_0126fa58;
            if (prev != 0) {
                *(int*)(prev + 0x1c) = (int)node;
                prev = DAT_0126fa58;
            }
            node[6] = prev;
            node[7] = 0;
            i++;
            DAT_0126fa58 = (int)node;
        } while (i < DAT_011c1118);
    }
}

struct FUN_00e98b10_Class {
    void*** m_ppVirtualMethodTable;
    void* m_data;
    FUN_00e98b10_Class* __thiscall FUN_00e98b10(unsigned char flag);
};

extern void** DAT_010f16dc;
extern MemoryManager _g_memoryManager;

// @fnv 0x00e98b10
FUN_00e98b10_Class* __thiscall FUN_00e98b10_Class::FUN_00e98b10(unsigned char flag)
{
    m_ppVirtualMethodTable = &DAT_010f16dc;
    NiFree(m_data);
    if (flag & 1)
        _g_memoryManager.Deallocate(this);
    return this;
}

struct SpawnedObject {
    void __thiscall ReleaseResources();
};

struct GlobalHolder {
    void __thiscall FUN_00aa4060(SpawnedObject* p);
};

extern SpawnedObject* DAT_0126f72c;
extern GlobalHolder DAT_011f6238;

// If DAT_0126f72c is non-null, calls ReleaseResources on it and FUN_00aa4060 on DAT_011f6238, then sets DAT_0126f72c to null.
// @fnv 0x00e803f0
void __cdecl ClearSpawnedObject()
{
    SpawnedObject* p = DAT_0126f72c;
    if (DAT_0126f72c != 0) {
        DAT_0126f72c->ReleaseResources();
        DAT_011f6238.FUN_00aa4060(p);
    }
    DAT_0126f72c = 0;
}

struct FUN_00e81b60_Entry {
    unsigned int m_key;
    int m_uiFilterValue;
};

struct FUN_00e81b60_Class {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int m_uiEdgeIndex[3];
    FUN_00e81b60_Entry* m_entries[3];

    int __thiscall LookupEntry(unsigned int a, unsigned int b, int c, int d);
};

extern int DAT_01101294;

// Builds a key from a and b, checks the entry at the current index in slot c, and if it matches advances the index and returns the entry's value.
// @fnv 0x00e81b60
int FUN_00e81b60_Class::LookupEntry(unsigned int auiLowKey, unsigned int auiHighKey, int aiSlot, int aiUnused)
{
    unsigned int key = (auiHighKey << DAT_01101294) | auiLowKey;
    unsigned int index = m_uiEdgeIndex[aiSlot];

    if (m_entries[aiSlot][index].m_key == key) {
        int result = m_entries[aiSlot][index].m_uiFilterValue;
        m_uiEdgeIndex[aiSlot] = index + 1;
        return result;
    }

    return 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

extern "C" void __cdecl _NiFreeE81(void* pvMem) throw();

extern const char* g_pcNullStringE81;

class NiFixedStringE81 {
public:
    ~NiFixedStringE81() throw()
    {
        if (m_kHandle != g_pcNullStringE81)
            InterlockedDecrement((long volatile*)(m_kHandle - 8));
    }

    const char* m_kHandle;
};

class NiRefObjectE81 {
public:
    virtual ~NiRefObjectE81() throw() { InterlockedDecrement(&ms_lObjectCount); }

    unsigned int m_uiRefCount;

    static long ms_lObjectCount;
};

class FUN_00e81c00 : public NiRefObjectE81 {
public:
    virtual ~FUN_00e81c00() throw();

    int m_iType;
    NiFixedStringE81 m_kControlPoint;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    NiFixedStringE81 m_kSecondaryString;
    int unk28;
    int unk2C;
    void* m_pConstantData;
    bool m_bOwnsData;
};

// Destructor that frees the owned data pointer when m_bOwnsData is set.
// @fnv 0x00e81c00
FUN_00e81c00::~FUN_00e81c00() throw()
{
    if (m_bOwnsData)
        _NiFreeE81(m_pConstantData);
}

struct Vec4 {
    float x;
    float y;
    float z;
    float w;
};


struct ConstantTarget {
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
    virtual bool SetConstant(int reg, const float* data, int count);
};

extern Vec4 DAT_0126f8a0;
extern Vec4 DAT_0126f8b0;
extern Vec4 DAT_0126f900;

// @fnv 0x00e830f0
int __stdcall SetConstantSum(ConstantTarget* target, int reg, int type1, int type2, int iUnused1, int iUnused2)
{
    switch (type1) {
    case 3:
    case 4:
        switch (type2) {
        case 3:
        case 4:
        {
            Vec4 t;
            t.x = DAT_0126f8a0.x + DAT_0126f8b0.x;
            t.y = DAT_0126f8a0.y + DAT_0126f8b0.y;
            t.z = DAT_0126f8a0.z + DAT_0126f8b0.z;
            t.w = DAT_0126f8a0.w + DAT_0126f8b0.w;
            DAT_0126f900 = t;
            return target->SetConstant(reg, &DAT_0126f900.x, 0) ? 0 : 0x50;
        }
        case 7:
        case 10:
            DAT_0126f900.x = DAT_0126f8a0.x + DAT_0126f8b0.x;
            DAT_0126f900.y = DAT_0126f8a0.y + DAT_0126f8b0.x;
            DAT_0126f900.z = DAT_0126f8a0.z + DAT_0126f8b0.x;
            DAT_0126f900.w = DAT_0126f8b0.x + DAT_0126f8a0.w;
            return target->SetConstant(reg, &DAT_0126f900.x, 0) ? 0 : 0x50;
        }
        break;
    case 7:
    case 10:
        switch (type2) {
        case 3:
        case 4:
            DAT_0126f900.x = DAT_0126f8a0.x + DAT_0126f8b0.x;
            DAT_0126f900.y = DAT_0126f8b0.y + DAT_0126f8a0.x;
            DAT_0126f900.z = DAT_0126f8b0.z + DAT_0126f8a0.x;
            DAT_0126f900.w = DAT_0126f8a0.x + DAT_0126f8b0.w;
            return target->SetConstant(reg, &DAT_0126f900.x, 0) ? 0 : 0x50;
        case 7:
        case 10:
            DAT_0126f900.x = DAT_0126f8a0.x + DAT_0126f8b0.x;
            DAT_0126f900.y = DAT_0126f8a0.y + DAT_0126f8b0.y;
            DAT_0126f900.z = DAT_0126f8a0.z + DAT_0126f8b0.z;
            DAT_0126f900.w = DAT_0126f8a0.w + DAT_0126f8b0.w;
            return target->SetConstant(reg, &DAT_0126f900.x, 0) ? 0 : 0x50;
        }
        break;
    }
    return 1;
}

class FUN_00e879b0_cls {
public:
    virtual void vtbl_unk00();
    virtual void vtbl_unk04();
    virtual void vtbl_unk08();
    virtual void vtbl_unk0C();
    virtual void vtbl_unk10();
    virtual void vtbl_unk14();
    virtual void vtbl_unk18();
    virtual void vtbl_unk1C();
    virtual void vtbl_unk20();
    virtual void vtbl_unk24();
    virtual void vtbl_unk28();
    virtual void vtbl_unk2C();
    virtual void vtbl_unk30();
    virtual void vtbl_unk34();
    virtual void vtbl_unk38();
    virtual void vtbl_unk3C();
    virtual void vtbl_unk40();
    virtual void vtbl_unk44();
    virtual void vtbl_unk48();
    virtual void vtbl_unk4C();
    virtual void vtbl_unk50();
    virtual void vtbl_unk54();
    virtual void vtbl_unk58();
    virtual void vtbl_unk5C();
    virtual void vtbl_unk60();
    virtual void vtbl_unk64();
    virtual int vtbl_slot68(int a, int b, int c, int d);
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
    int m_d4;
    int m_d8;
    int m_dc;
    int m_e0;
    int m_e4;
    int m_e8;
    int m_ec;
    int m_f0;
    int m_f4;
    int CallSlot68WithField(int a1, int a2);
};

// Calls vtbl_slot68 with selector 0x16, the value at (&m_d4)[m_f4 + a1 * 2], 0 and a2, returning its result.
// @fnv 0x00e879b0
int FUN_00e879b0_cls::CallSlot68WithField(int aiIndex, int aiArg) {
    return vtbl_slot68(0x16, (&m_d4)[m_f4 + aiIndex * 2], 0, aiArg);
}

struct FUN_00e87a90_Class {
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

    void __thiscall FUN_00e87a90();
};

// @fnv 0x00e87a90
void FUN_00e87a90_Class::FUN_00e87a90() {
    this->vf84();
    this->vf94();
}

struct E87B60AlphaProperty {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned short m_uiObjectFlags;
    unsigned char m_ucAlphaThreshold;

    bool GetAlphaBlending() const { return (m_uiObjectFlags & 1) != 0; }
    unsigned int GetSrcBlendMode() const { return (m_uiObjectFlags >> 1) & 0xf; }
    unsigned int GetDestBlendMode() const { return (m_uiObjectFlags >> 5) & 0xf; }
    bool GetAlphaTesting() const { return ((unsigned short)(m_uiObjectFlags >> 9) & 1) != 0; }
    unsigned int GetTestMode() const { return (m_uiObjectFlags >> 10) & 7; }
    unsigned char GetTestRef() const { return m_ucAlphaThreshold; }
};

class E87B60RenderState {
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
    virtual void SetRenderState(unsigned int eState, unsigned int uiValue, bool bSave, bool bForce);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int m_uiRenderStateValues[11];
    unsigned int m_uiTextureStageStateValues[8];

    void ApplyAlphaProperty(const E87B60AlphaProperty* pkNew);
};

// NiDX9RenderState::ApplyAlpha
// Applies alpha blending and alpha testing render states from pkNew via SetRenderState.
// @fnv 0x00e87b60
void E87B60RenderState::ApplyAlphaProperty(const E87B60AlphaProperty* pkNew) {
    if (pkNew->GetAlphaBlending()) {
        SetRenderState(0x1b, 1, false, false);
        SetRenderState(0x13, m_uiRenderStateValues[pkNew->GetSrcBlendMode()], false, false);
        SetRenderState(0x14, m_uiRenderStateValues[pkNew->GetDestBlendMode()], false, false);
    } else {
        SetRenderState(0x1b, 0, false, false);
    }
    if (pkNew->GetAlphaTesting()) {
        SetRenderState(0xf, 1, false, false);
        SetRenderState(0x19, m_uiTextureStageStateValues[pkNew->GetTestMode()], false, false);
        SetRenderState(0x18, pkNew->GetTestRef(), false, false);
    } else {
        SetRenderState(0xf, 0, false, false);
    }
}

class FUN_00e87c30_cls;

class FUN_00e87c30_arg
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned char unk18;
};

class FUN_00e87c30_cls
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
    virtual void v1a(int a, unsigned int b, int c, int d);

    void FUN_00e87c30(FUN_00e87c30_arg* a1);
};

// @fnv 0x00e87c30
void FUN_00e87c30_cls::FUN_00e87c30(FUN_00e87c30_arg* a1)
{
    this->v1a(0x1a, a1->unk18 & 1, 0, 0);
}

struct C00e87ed0 {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26(int, int, int, int) = 0;
    void __thiscall FUN_00e87ed0(void* p);
};

// @fnv 0x00e87ed0
void C00e87ed0::FUN_00e87ed0(void* apData) {
    int flag = ((unsigned char*)apData)[0x18] & 1;
    this->v26(0x1d, flag, 0, 0);
}

struct StencilPropStub {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned short m_flags;
    unsigned int m_ref;
    unsigned int m_uiMask;
};
struct RenderStateStub {
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
    virtual void SetRenderState(unsigned int state, unsigned int value, bool save, bool restore);
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
    unsigned int m_stencilTestFuncs[8];
    unsigned int m_stencilActions[6];
    unsigned int m_cullModes[4][2];
    int m_bStencilEnabled;
    void ApplyStencilState(StencilPropStub* prop);
};

// Applies the stencil test, ref, mask and ops from prop when its flag bit 0 is set, then sets the cull mode from the prop's bits 10-11.
// @fnv 0x00e87ef0
void RenderStateStub::ApplyStencilState(StencilPropStub* apStencilProp)
{
    if (apStencilProp->m_flags & 1) {
        SetRenderState(0x34, 1, false, false);
        SetRenderState(0x38, m_stencilTestFuncs[apStencilProp->m_flags >> 12], false, false);
        SetRenderState(0x39, apStencilProp->m_ref, false, false);
        SetRenderState(0x3a, apStencilProp->m_uiMask, false, false);
        SetRenderState(0x35, m_stencilActions[(apStencilProp->m_flags >> 1) & 7], false, false);
        SetRenderState(0x36, m_stencilActions[(apStencilProp->m_flags >> 4) & 7], false, false);
        SetRenderState(0x37, m_stencilActions[(apStencilProp->m_flags >> 7) & 7], false, false);
        SetRenderState(0x3b, 0xff, false, false);
    }
    SetRenderState(0x16, m_cullModes[(apStencilProp->m_flags >> 10) & 3][m_bStencilEnabled], false, false);
}

struct FUN_00e88000_pair {
    int key;
    int val;
};

extern FUN_00e88000_pair DAT_011bfce8;

class FUN_00e88000_cls {
public:
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010c;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011c;
    FUN_00e88000_pair m_120[(0x10f8 - 0x120) / 8];
    void* m_10f8;
    void __thiscall ApplyPairTable();
};

// Walks the DAT_011bfce8 pair list until key -1, storing each pair into m_120 and calling the object's vtable slot 57 with key and val.
// @fnv 0x00e88000
void FUN_00e88000_cls::ApplyPairTable()
{
    typedef void (__stdcall *Fn)(void*, int, int);
    FUN_00e88000_pair* cur = &DAT_011bfce8;
    int key = DAT_011bfce8.key;
    if (key == -1)
        return;
    FUN_00e88000_pair* nxt = cur;
    do {
        m_120[key].val = cur->val;
        m_120[cur->key].key = cur->val;
        void* obj = m_10f8;
        Fn fn = (Fn)(*(void***)obj)[57];
        fn(obj, cur->key, cur->val);
        key = nxt[1].key;
        nxt++;
        cur = nxt;
    } while (key != -1);
}

struct StateDefault {
    int type;
    unsigned int value;
};

struct RenderStateSetting {
    unsigned int unk00;
    unsigned int value;
};

struct D3DDeviceStub {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66();
    virtual long __stdcall SetTextureStageState(unsigned int stage, int type, unsigned int value);
    virtual void v68();
    virtual long __stdcall SetSamplerState(unsigned int sampler, int type, unsigned int value);
};

extern unsigned int DAT_011bf558;
extern unsigned int DAT_011bf560;
extern StateDefault DAT_011c04f0[];
extern StateDefault DAT_011c0538[];
extern unsigned short DAT_0126f958[];
extern unsigned short DAT_0126f92c[];

struct NiDX9RenderStateStub {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50();
    virtual void SetSamplerStateCached(unsigned int sampler, int type, unsigned int value, bool save);

    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20;
    int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40;
    int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60;
    int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80;
    int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0;
    int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0;
    int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc; int unke0;
    int unke4; int unke8; int unkec; int unkf0; int unkf4; int unkf8; int unkfc; int unk100;
    int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120;
    int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140;
    int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160;
    int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180;
    int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0;
    int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0;
    int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0;
    int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc; int unk200;
    int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c; int unk220;
    int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c; int unk240;
    int unk244; int unk248; int unk24c; int unk250; int unk254; int unk258; int unk25c; int unk260;
    int unk264; int unk268; int unk26c; int unk270; int unk274; int unk278; int unk27c; int unk280;
    int unk284; int unk288; int unk28c; int unk290; int unk294; int unk298; int unk29c; int unk2a0;
    int unk2a4; int unk2a8; int unk2ac; int unk2b0; int unk2b4; int unk2b8; int unk2bc; int unk2c0;
    int unk2c4; int unk2c8; int unk2cc; int unk2d0; int unk2d4; int unk2d8; int unk2dc; int unk2e0;
    int unk2e4; int unk2e8; int unk2ec; int unk2f0; int unk2f4; int unk2f8; int unk2fc; int unk300;
    int unk304; int unk308; int unk30c; int unk310; int unk314; int unk318; int unk31c; int unk320;
    int unk324; int unk328; int unk32c; int unk330; int unk334; int unk338; int unk33c; int unk340;
    int unk344; int unk348; int unk34c; int unk350; int unk354; int unk358; int unk35c; int unk360;
    int unk364; int unk368; int unk36c; int unk370; int unk374; int unk378; int unk37c; int unk380;
    int unk384; int unk388; int unk38c; int unk390; int unk394; int unk398; int unk39c; int unk3a0;
    int unk3a4; int unk3a8; int unk3ac; int unk3b0; int unk3b4; int unk3b8; int unk3bc; int unk3c0;
    int unk3c4; int unk3c8; int unk3cc; int unk3d0; int unk3d4; int unk3d8; int unk3dc; int unk3e0;
    int unk3e4; int unk3e8; int unk3ec; int unk3f0; int unk3f4; int unk3f8; int unk3fc; int unk400;
    int unk404; int unk408; int unk40c; int unk410; int unk414; int unk418; int unk41c; int unk420;
    int unk424; int unk428; int unk42c; int unk430; int unk434; int unk438; int unk43c; int unk440;
    int unk444; int unk448; int unk44c; int unk450; int unk454; int unk458; int unk45c; int unk460;
    int unk464; int unk468; int unk46c; int unk470; int unk474; int unk478; int unk47c; int unk480;
    int unk484; int unk488; int unk48c; int unk490; int unk494; int unk498; int unk49c; int unk4a0;
    int unk4a4; int unk4a8; int unk4ac; int unk4b0; int unk4b4; int unk4b8; int unk4bc; int unk4c0;
    int unk4c4; int unk4c8; int unk4cc; int unk4d0; int unk4d4; int unk4d8; int unk4dc; int unk4e0;
    int unk4e4; int unk4e8; int unk4ec; int unk4f0; int unk4f4; int unk4f8; int unk4fc; int unk500;
    int unk504; int unk508; int unk50c; int unk510; int unk514; int unk518; int unk51c; int unk520;
    int unk524; int unk528; int unk52c; int unk530; int unk534; int unk538; int unk53c; int unk540;
    int unk544; int unk548; int unk54c; int unk550; int unk554; int unk558; int unk55c; int unk560;
    int unk564; int unk568; int unk56c; int unk570; int unk574; int unk578; int unk57c; int unk580;
    int unk584; int unk588; int unk58c; int unk590; int unk594; int unk598; int unk59c; int unk5a0;
    int unk5a4; int unk5a8; int unk5ac; int unk5b0; int unk5b4; int unk5b8; int unk5bc; int unk5c0;
    int unk5c4; int unk5c8; int unk5cc; int unk5d0; int unk5d4; int unk5d8; int unk5dc; int unk5e0;
    int unk5e4; int unk5e8; int unk5ec; int unk5f0; int unk5f4; int unk5f8; int unk5fc; int unk600;
    int unk604; int unk608; int unk60c; int unk610; int unk614; int unk618; int unk61c; int unk620;
    int unk624; int unk628; int unk62c; int unk630; int unk634; int unk638; int unk63c; int unk640;
    int unk644; int unk648; int unk64c; int unk650; int unk654; int unk658; int unk65c; int unk660;
    int unk664; int unk668; int unk66c; int unk670; int unk674; int unk678; int unk67c; int unk680;
    int unk684; int unk688; int unk68c; int unk690; int unk694; int unk698; int unk69c; int unk6a0;
    int unk6a4; int unk6a8; int unk6ac; int unk6b0; int unk6b4; int unk6b8; int unk6bc; int unk6c0;
    int unk6c4; int unk6c8; int unk6cc; int unk6d0; int unk6d4; int unk6d8; int unk6dc; int unk6e0;
    int unk6e4; int unk6e8; int unk6ec; int unk6f0; int unk6f4; int unk6f8; int unk6fc; int unk700;
    int unk704; int unk708; int unk70c; int unk710; int unk714; int unk718; int unk71c; int unk720;
    int unk724; int unk728; int unk72c; int unk730; int unk734; int unk738; int unk73c; int unk740;
    int unk744; int unk748; int unk74c; int unk750; int unk754; int unk758; int unk75c; int unk760;
    int unk764; int unk768; int unk76c; int unk770; int unk774; int unk778; int unk77c; int unk780;
    int unk784; int unk788; int unk78c; int unk790; int unk794; int unk798; int unk79c; int unk7a0;
    int unk7a4; int unk7a8; int unk7ac; int unk7b0; int unk7b4; int unk7b8; int unk7bc; int unk7c0;
    int unk7c4; int unk7c8; int unk7cc; int unk7d0; int unk7d4; int unk7d8; int unk7dc; int unk7e0;
    int unk7e4; int unk7e8; int unk7ec; int unk7f0; int unk7f4; int unk7f8; int unk7fc; int unk800;
    int unk804; int unk808; int unk80c; int unk810; int unk814; int unk818; int unk81c; int unk820;
    int unk824; int unk828; int unk82c; int unk830; int unk834; int unk838; int unk83c; int unk840;
    int unk844; int unk848; int unk84c; int unk850; int unk854; int unk858; int unk85c; int unk860;
    int unk864; int unk868; int unk86c; int unk870; int unk874; int unk878; int unk87c; int unk880;
    int unk884; int unk888; int unk88c; int unk890; int unk894; int unk898; int unk89c; int unk8a0;
    int unk8a4; int unk8a8; int unk8ac; int unk8b0; int unk8b4; int unk8b8; int unk8bc; int unk8c0;
    int unk8c4; int unk8c8; int unk8cc; int unk8d0; int unk8d4; int unk8d8; int unk8dc; int unk8e0;
    int unk8e4; int unk8e8; int unk8ec; int unk8f0; int unk8f4; int unk8f8; int unk8fc; int unk900;
    int unk904; int unk908; int unk90c; int unk910; int unk914; int unk918; int unk91c; int unk920;
    int unk924; int unk928; int unk92c; int unk930; int unk934; int unk938; int unk93c; int unk940;
    int unk944; int unk948; int unk94c; int unk950; int unk954; int unk958; int unk95c; int unk960;
    int unk964; int unk968; int unk96c; int unk970; int unk974; int unk978; int unk97c; int unk980;
    int unk984; int unk988; int unk98c; int unk990; int unk994; int unk998; int unk99c; int unk9a0;
    int unk9a4; int unk9a8; int unk9ac; int unk9b0; int unk9b4; int unk9b8; int unk9bc; int unk9c0;
    int unk9c4; int unk9c8; int unk9cc; int unk9d0; int unk9d4; int unk9d8; int unk9dc; int unk9e0;
    int unk9e4; int unk9e8; int unk9ec; int unk9f0; int unk9f4; int unk9f8; int unk9fc; int unka00;
    int unka04; int unka08; int unka0c; int unka10; int unka14; int unka18; int unka1c;
    RenderStateSetting m_aakTextureStageStates[16][8];
    RenderStateSetting m_aakSamplerStates[16][5];
    int unk10a0; int unk10a4; int unk10a8; int unk10ac; int unk10b0; int unk10b4; int unk10b8; int unk10bc;
    int unk10c0; int unk10c4; int unk10c8; int unk10cc; int unk10d0; int unk10d4; int unk10d8; int unk10dc;
    int unk10e0; int unk10e4; int unk10e8; int unk10ec; int unk10f0; int unk10f4;
    D3DDeviceStub* m_pD3DDevice;

    void ApplyDefaultRenderStates();
};


// Iterates the default texture-stage and sampler state tables, writes each value into the cached state arrays and applies it to the D3D device.
// @fnv 0x00e88060
void NiDX9RenderStateStub::ApplyDefaultRenderStates()
{
    for (unsigned int i = 0; i < DAT_011bf558; i++) {
        StateDefault* d = DAT_011c04f0;
        int type = d->type;
        if (type != -1) {
          StateDefault* e = d;
          do {
            if (type == 11)
                d->value = i;
            else if ((type == 1 || type == 4) && i != 0)
                d->value = 1;
            m_aakTextureStageStates[i][DAT_0126f958[type]].value = d->value;
            m_pD3DDevice->SetTextureStageState(i, type, d->value);
            e++;
            type = e->type;
            d = e;
          } while (type != -1);
        }
    }
    for (unsigned int j = 0; j < DAT_011bf560; j++) {
        StateDefault* d = DAT_011c0538;
        int type = d->type;
        if (type != -1) {
          StateDefault* e = d;
          do {
            m_aakSamplerStates[j][DAT_0126f92c[type]].value = d->value;
            SetSamplerStateCached(j, type, d->value, false);
            m_pD3DDevice->SetSamplerState(j, type, d->value);
            e++;
            type = e->type;
            d = e;
          } while (type != -1);
        }
    }
}

class FUN_00e88670_cls {
public:
    virtual int vSlot00();
    virtual int vSlot01();
    virtual int vSlot02();
    virtual int vSlot03();
    virtual int vSlot04();
    virtual int vSlot05();
    virtual int vSlot06();
    virtual int vSlot07();
    virtual int vSlot08();
    virtual int vSlot09();
    virtual int vSlot10();
    virtual int vSlot11();
    virtual int vSlot12();
    virtual int vSlot13();
    virtual int vSlot14();
    virtual int vSlot15();
    virtual int vSlot16();
    virtual int vSlot17();
    virtual int vSlot18();
    virtual int vSlot19();
    virtual int vSlot20();
    virtual int vSlot21();
    virtual int vSlot22();
    virtual int vSlot23();
    virtual int vSlot24();
    virtual int vSlot25();
    virtual int vSlot26(int a, int b, int c, int d);
    int CallSlot26WithArgs(int a1, int a2);
};

// @fnv 0x00e88670
int FUN_00e88670_cls::CallSlot26WithArgs(int a1, int a2) {
    return vSlot26(0xc3, a1, 0, a2);
}

// Decompiled: dispatch a table value to a virtual slot on this.

struct FUN_00e88690_cls {
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
    virtual void v26(int a, int b, int c, int d);
    int m_04;
    int m_08;
    int m_aiIndexedValues[256];
    void SendIndexedValue(unsigned short index);
};

// @fnv 0x00e88690
void FUN_00e88690_cls::SendIndexedValue(unsigned short index)
{
    int value = m_aiIndexedValues[index];
    v26(0x97, value, 0, 0);
}

struct FUN_00e886b0_cls {
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
    int m_30;
    int m_34;
    int m_38;
    int m_3C;
    int m_40;
    int m_44;
    int m_48;
    int m_4C;
    int m_50;
    int m_54;
    int m_58;
    int m_5C;
    int m_60;
    int m_64;
    int m_68;
    int m_6C;
    int m_70;
    int m_74;
    int m_78;
    int m_7C;
    int m_80;
    int m_84;
    float m_88;
    float FUN_00e886b0();
};

// @fnv 0x00e886b0
float FUN_00e886b0_cls::FUN_00e886b0() {
    return m_88;
}

struct FUN_00e886c0_cls {
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
    float m_84;
    float FUN_00e886c0();
};

// @fnv 0x00e886c0
float FUN_00e886c0_cls::FUN_00e886c0() {
    return m_84;
}

class FUN_00e88750_cls {
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
    int m_F4;
    unsigned char FUN_00e88750();
};
// @fnv 0x00e88750
unsigned char FUN_00e88750_cls::FUN_00e88750() {
    return m_F4 != 0;
}

struct FUN_00e88780_D3DObject {
    void* m_ppVirtualMethodTable;
};

typedef void (__stdcall *FUN_00e88780_D3DCall)(
    FUN_00e88780_D3DObject* pObject,
    int index,
    int value
);

struct FUN_00e88780_Class {
    void __thiscall SetIndexedValue(
        int index,
        int value,
        int unused,
        unsigned char flag
    );
};

// @fnv 0x00e88780
void __thiscall FUN_00e88780_Class::SetIndexedValue(
    int index,
    int value,
    int unused,
    unsigned char flag
) {
    unsigned char* self = reinterpret_cast<unsigned char*>(this);

    if (self[0x920 + index] == 0) {
        self[0x920 + index] = flag;

        int* slot = reinterpret_cast<int*>(self + 0x120 + index * 8);
        if (*slot != value) {
            FUN_00e88780_D3DObject* pObject =
                *reinterpret_cast<FUN_00e88780_D3DObject**>(self + 0x10f8);

            void** vtable = reinterpret_cast<void**>(pObject->m_ppVirtualMethodTable);
            FUN_00e88780_D3DCall call =
                reinterpret_cast<FUN_00e88780_D3DCall>(vtable[0x39]);

            call(pObject, index, value);
            *slot = value;
        }
    }
}

struct FUN_00e88830_cls
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    int m_1f8;
    void FUN_00e88830(int a1, int unused1, int unused2);
};

typedef void (__stdcall *FUN_00e88830_Slot)(void* self, int code, int value);

// If m_1f8 differs from a1, calls the holder's slot at offset 0xe4 with code 0x1b and a1, then stores a1 in m_1f8.
// @fnv 0x00e88830
void FUN_00e88830_cls::FUN_00e88830(int aiValue, int unused1, int unused2)
{
    if (m_1f8 != aiValue)
    {
        void* holder = *(void**)((char*)this + 0x10f8);
        FUN_00e88830_Slot fn = (FUN_00e88830_Slot)(*(void***)holder)[0xe4 / 4];
        fn(holder, 0x1b, aiValue);
    }
    m_1f8 = aiValue;
}

struct RenderStateSink
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void Forward(RenderStateSink* self, int a);
};

struct FUN_00e88870_cls
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010c;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014c;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015c;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016c;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017c;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018c;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019c;
    int unk01a0;
    int unk01a4;
    int unk01a8;
    int unk01ac;
    int unk01b0;
    int unk01b4;
    int unk01b8;
    int unk01bc;
    int unk01c0;
    int unk01c4;
    int unk01c8;
    int unk01cc;
    int unk01d0;
    int unk01d4;
    int unk01d8;
    int unk01dc;
    int unk01e0;
    int unk01e4;
    int unk01e8;
    int unk01ec;
    int unk01f0;
    int unk01f4;
    int unk01f8;
    int unk01fc;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020c;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021c;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022c;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023c;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024c;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025c;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026c;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027c;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028c;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029c;
    int unk02a0;
    int unk02a4;
    int unk02a8;
    int unk02ac;
    int unk02b0;
    int unk02b4;
    int unk02b8;
    int unk02bc;
    int unk02c0;
    int unk02c4;
    int unk02c8;
    int unk02cc;
    int unk02d0;
    int unk02d4;
    int unk02d8;
    int unk02dc;
    int unk02e0;
    int unk02e4;
    int unk02e8;
    int unk02ec;
    int unk02f0;
    int unk02f4;
    int unk02f8;
    int unk02fc;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030c;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031c;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032c;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033c;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034c;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035c;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036c;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037c;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038c;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039c;
    int unk03a0;
    int unk03a4;
    int unk03a8;
    int unk03ac;
    int unk03b0;
    int unk03b4;
    int unk03b8;
    int unk03bc;
    int unk03c0;
    int unk03c4;
    int unk03c8;
    int unk03cc;
    int unk03d0;
    int unk03d4;
    int unk03d8;
    int unk03dc;
    int unk03e0;
    int unk03e4;
    int unk03e8;
    int unk03ec;
    int unk03f0;
    int unk03f4;
    int unk03f8;
    int unk03fc;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040c;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041c;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042c;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043c;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044c;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045c;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046c;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047c;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048c;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049c;
    int unk04a0;
    int unk04a4;
    int unk04a8;
    int unk04ac;
    int unk04b0;
    int unk04b4;
    int unk04b8;
    int unk04bc;
    int unk04c0;
    int unk04c4;
    int unk04c8;
    int unk04cc;
    int unk04d0;
    int unk04d4;
    int unk04d8;
    int unk04dc;
    int unk04e0;
    int unk04e4;
    int unk04e8;
    int unk04ec;
    int unk04f0;
    int unk04f4;
    int unk04f8;
    int unk04fc;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050c;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051c;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052c;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053c;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054c;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055c;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056c;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057c;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058c;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059c;
    int unk05a0;
    int unk05a4;
    int unk05a8;
    int unk05ac;
    int unk05b0;
    int unk05b4;
    int unk05b8;
    int unk05bc;
    int unk05c0;
    int unk05c4;
    int unk05c8;
    int unk05cc;
    int unk05d0;
    int unk05d4;
    int unk05d8;
    int unk05dc;
    int unk05e0;
    int unk05e4;
    int unk05e8;
    int unk05ec;
    int unk05f0;
    int unk05f4;
    int unk05f8;
    int unk05fc;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060c;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061c;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062c;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063c;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064c;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065c;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066c;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067c;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068c;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069c;
    int unk06a0;
    int unk06a4;
    int unk06a8;
    int unk06ac;
    int unk06b0;
    int unk06b4;
    int unk06b8;
    int unk06bc;
    int unk06c0;
    int unk06c4;
    int unk06c8;
    int unk06cc;
    int unk06d0;
    int unk06d4;
    int unk06d8;
    int unk06dc;
    int unk06e0;
    int unk06e4;
    int unk06e8;
    int unk06ec;
    int unk06f0;
    int unk06f4;
    int unk06f8;
    int unk06fc;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070c;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071c;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072c;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073c;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074c;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075c;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076c;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077c;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078c;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079c;
    int unk07a0;
    int unk07a4;
    int unk07a8;
    int unk07ac;
    int unk07b0;
    int unk07b4;
    int unk07b8;
    int unk07bc;
    int unk07c0;
    int unk07c4;
    int unk07c8;
    int unk07cc;
    int unk07d0;
    int unk07d4;
    int unk07d8;
    int unk07dc;
    int unk07e0;
    int unk07e4;
    int unk07e8;
    int unk07ec;
    int unk07f0;
    int unk07f4;
    int unk07f8;
    int unk07fc;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080c;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081c;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082c;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083c;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084c;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085c;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086c;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087c;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088c;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089c;
    int unk08a0;
    int unk08a4;
    int unk08a8;
    int unk08ac;
    int unk08b0;
    int unk08b4;
    int unk08b8;
    int unk08bc;
    int unk08c0;
    int unk08c4;
    int unk08c8;
    int unk08cc;
    int unk08d0;
    int unk08d4;
    int unk08d8;
    int unk08dc;
    int unk08e0;
    int unk08e4;
    int unk08e8;
    int unk08ec;
    int unk08f0;
    int unk08f4;
    int unk08f8;
    int unk08fc;
    int unk0900;
    int unk0904;
    int unk0908;
    int unk090c;
    int unk0910;
    int unk0914;
    int unk0918;
    int unk091c;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092c;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093c;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094c;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095c;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096c;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097c;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098c;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099c;
    int unk09a0;
    int unk09a4;
    int unk09a8;
    int unk09ac;
    int unk09b0;
    int unk09b4;
    int unk09b8;
    int unk09bc;
    int unk09c0;
    int unk09c4;
    int unk09c8;
    int unk09cc;
    int unk09d0;
    int unk09d4;
    int unk09d8;
    int unk09dc;
    int unk09e0;
    int unk09e4;
    int unk09e8;
    int unk09ec;
    int unk09f0;
    int unk09f4;
    int unk09f8;
    int unk09fc;
    int unk0a00;
    int unk0a04;
    int unk0a08;
    int unk0a0c;
    int unk0a10;
    int unk0a14;
    int unk0a18;
    int unk0a1c;
    int unk0a20;
    int unk0a24;
    int unk0a28;
    int unk0a2c;
    int unk0a30;
    int unk0a34;
    int unk0a38;
    int unk0a3c;
    int unk0a40;
    int unk0a44;
    int unk0a48;
    int unk0a4c;
    int unk0a50;
    int unk0a54;
    int unk0a58;
    int unk0a5c;
    int unk0a60;
    int unk0a64;
    int unk0a68;
    int unk0a6c;
    int unk0a70;
    int unk0a74;
    int unk0a78;
    int unk0a7c;
    int unk0a80;
    int unk0a84;
    int unk0a88;
    int unk0a8c;
    int unk0a90;
    int unk0a94;
    int unk0a98;
    int unk0a9c;
    int unk0aa0;
    int unk0aa4;
    int unk0aa8;
    int unk0aac;
    int unk0ab0;
    int unk0ab4;
    int unk0ab8;
    int unk0abc;
    int unk0ac0;
    int unk0ac4;
    int unk0ac8;
    int unk0acc;
    int unk0ad0;
    int unk0ad4;
    int unk0ad8;
    int unk0adc;
    int unk0ae0;
    int unk0ae4;
    int unk0ae8;
    int unk0aec;
    int unk0af0;
    int unk0af4;
    int unk0af8;
    int unk0afc;
    int unk0b00;
    int unk0b04;
    int unk0b08;
    int unk0b0c;
    int unk0b10;
    int unk0b14;
    int unk0b18;
    int unk0b1c;
    int unk0b20;
    int unk0b24;
    int unk0b28;
    int unk0b2c;
    int unk0b30;
    int unk0b34;
    int unk0b38;
    int unk0b3c;
    int unk0b40;
    int unk0b44;
    int unk0b48;
    int unk0b4c;
    int unk0b50;
    int unk0b54;
    int unk0b58;
    int unk0b5c;
    int unk0b60;
    int unk0b64;
    int unk0b68;
    int unk0b6c;
    int unk0b70;
    int unk0b74;
    int unk0b78;
    int unk0b7c;
    int unk0b80;
    int unk0b84;
    int unk0b88;
    int unk0b8c;
    int unk0b90;
    int unk0b94;
    int unk0b98;
    int unk0b9c;
    int unk0ba0;
    int unk0ba4;
    int unk0ba8;
    int unk0bac;
    int unk0bb0;
    int unk0bb4;
    int unk0bb8;
    int unk0bbc;
    int unk0bc0;
    int unk0bc4;
    int unk0bc8;
    int unk0bcc;
    int unk0bd0;
    int unk0bd4;
    int unk0bd8;
    int unk0bdc;
    int unk0be0;
    int unk0be4;
    int unk0be8;
    int unk0bec;
    int unk0bf0;
    int unk0bf4;
    int unk0bf8;
    int unk0bfc;
    int unk0c00;
    int unk0c04;
    int unk0c08;
    int unk0c0c;
    int unk0c10;
    int unk0c14;
    int unk0c18;
    int unk0c1c;
    int unk0c20;
    int unk0c24;
    int unk0c28;
    int unk0c2c;
    int unk0c30;
    int unk0c34;
    int unk0c38;
    int unk0c3c;
    int unk0c40;
    int unk0c44;
    int unk0c48;
    int unk0c4c;
    int unk0c50;
    int unk0c54;
    int unk0c58;
    int unk0c5c;
    int unk0c60;
    int unk0c64;
    int unk0c68;
    int unk0c6c;
    int unk0c70;
    int unk0c74;
    int unk0c78;
    int unk0c7c;
    int unk0c80;
    int unk0c84;
    int unk0c88;
    int unk0c8c;
    int unk0c90;
    int unk0c94;
    int unk0c98;
    int unk0c9c;
    int unk0ca0;
    int unk0ca4;
    int unk0ca8;
    int unk0cac;
    int unk0cb0;
    int unk0cb4;
    int unk0cb8;
    int unk0cbc;
    int unk0cc0;
    int unk0cc4;
    int unk0cc8;
    int unk0ccc;
    int unk0cd0;
    int unk0cd4;
    int unk0cd8;
    int unk0cdc;
    int unk0ce0;
    int unk0ce4;
    int unk0ce8;
    int unk0cec;
    int unk0cf0;
    int unk0cf4;
    int unk0cf8;
    int unk0cfc;
    int unk0d00;
    int unk0d04;
    int unk0d08;
    int unk0d0c;
    int unk0d10;
    int unk0d14;
    int unk0d18;
    int unk0d1c;
    int unk0d20;
    int unk0d24;
    int unk0d28;
    int unk0d2c;
    int unk0d30;
    int unk0d34;
    int unk0d38;
    int unk0d3c;
    int unk0d40;
    int unk0d44;
    int unk0d48;
    int unk0d4c;
    int unk0d50;
    int unk0d54;
    int unk0d58;
    int unk0d5c;
    int unk0d60;
    int unk0d64;
    int unk0d68;
    int unk0d6c;
    int unk0d70;
    int unk0d74;
    int unk0d78;
    int unk0d7c;
    int unk0d80;
    int unk0d84;
    int unk0d88;
    int unk0d8c;
    int unk0d90;
    int unk0d94;
    int unk0d98;
    int unk0d9c;
    int unk0da0;
    int unk0da4;
    int unk0da8;
    int unk0dac;
    int unk0db0;
    int unk0db4;
    int unk0db8;
    int unk0dbc;
    int unk0dc0;
    int unk0dc4;
    int unk0dc8;
    int unk0dcc;
    int unk0dd0;
    int unk0dd4;
    int unk0dd8;
    int unk0ddc;
    int unk0de0;
    int unk0de4;
    int unk0de8;
    int unk0dec;
    int unk0df0;
    int unk0df4;
    int unk0df8;
    int unk0dfc;
    int unk0e00;
    int unk0e04;
    int unk0e08;
    int unk0e0c;
    int unk0e10;
    int unk0e14;
    int unk0e18;
    int unk0e1c;
    int unk0e20;
    int unk0e24;
    int unk0e28;
    int unk0e2c;
    int unk0e30;
    int unk0e34;
    int unk0e38;
    int unk0e3c;
    int unk0e40;
    int unk0e44;
    int unk0e48;
    int unk0e4c;
    int unk0e50;
    int unk0e54;
    int unk0e58;
    int unk0e5c;
    int unk0e60;
    int unk0e64;
    int unk0e68;
    int unk0e6c;
    int unk0e70;
    int unk0e74;
    int unk0e78;
    int unk0e7c;
    int unk0e80;
    int unk0e84;
    int unk0e88;
    int unk0e8c;
    int unk0e90;
    int unk0e94;
    int unk0e98;
    int unk0e9c;
    int unk0ea0;
    int unk0ea4;
    int unk0ea8;
    int unk0eac;
    int unk0eb0;
    int unk0eb4;
    int unk0eb8;
    int unk0ebc;
    int unk0ec0;
    int unk0ec4;
    int unk0ec8;
    int unk0ecc;
    int unk0ed0;
    int unk0ed4;
    int unk0ed8;
    int unk0edc;
    int unk0ee0;
    int unk0ee4;
    int unk0ee8;
    int unk0eec;
    int unk0ef0;
    int unk0ef4;
    int unk0ef8;
    int unk0efc;
    int unk0f00;
    int unk0f04;
    int unk0f08;
    int unk0f0c;
    int unk0f10;
    int unk0f14;
    int unk0f18;
    int unk0f1c;
    int unk0f20;
    int unk0f24;
    int unk0f28;
    int unk0f2c;
    int unk0f30;
    int unk0f34;
    int unk0f38;
    int unk0f3c;
    int unk0f40;
    int unk0f44;
    int unk0f48;
    int unk0f4c;
    int unk0f50;
    int unk0f54;
    int unk0f58;
    int unk0f5c;
    int unk0f60;
    int unk0f64;
    int unk0f68;
    int unk0f6c;
    int unk0f70;
    int unk0f74;
    int unk0f78;
    int unk0f7c;
    int unk0f80;
    int unk0f84;
    int unk0f88;
    int unk0f8c;
    int unk0f90;
    int unk0f94;
    int unk0f98;
    int unk0f9c;
    int unk0fa0;
    int unk0fa4;
    int unk0fa8;
    int unk0fac;
    int unk0fb0;
    int unk0fb4;
    int unk0fb8;
    int unk0fbc;
    int unk0fc0;
    int unk0fc4;
    int unk0fc8;
    int unk0fcc;
    int unk0fd0;
    int unk0fd4;
    int unk0fd8;
    int unk0fdc;
    int unk0fe0;
    int unk0fe4;
    int unk0fe8;
    int unk0fec;
    int unk0ff0;
    int unk0ff4;
    int unk0ff8;
    int unk0ffc;
    int unk1000;
    int unk1004;
    int unk1008;
    int unk100c;
    int unk1010;
    int unk1014;
    int unk1018;
    int unk101c;
    int unk1020;
    int unk1024;
    int unk1028;
    int unk102c;
    int unk1030;
    int unk1034;
    int unk1038;
    int unk103c;
    int unk1040;
    int unk1044;
    int unk1048;
    int unk104c;
    int unk1050;
    int unk1054;
    int unk1058;
    int unk105c;
    int unk1060;
    int unk1064;
    int unk1068;
    int unk106c;
    int unk1070;
    int unk1074;
    int unk1078;
    int unk107c;
    int unk1080;
    int unk1084;
    int unk1088;
    int unk108c;
    int unk1090;
    int unk1094;
    int unk1098;
    int unk109c;
    int unk10a0;
    int unk10a4;
    int unk10a8;
    int unk10ac;
    int unk10b0;
    int unk10b4;
    int unk10b8;
    int unk10bc;
    int unk10c0;
    int unk10c4;
    int unk10c8;
    int unk10cc;
    int unk10d0;
    int unk10d4;
    int unk10d8;
    int unk10dc;
    int unk10e0;
    int unk10e4;
    int m_10e8;
    int m_10ec;
    int unk10f0;
    int unk10f4;
    RenderStateSink* m_10f8;
    void FUN_00e88870(int a, bool flag);
};

// If flag is set, copies m_10e8 into m_10ec; when m_10e8 differs from a, stores a and forwards it to m_10f8.
// @fnv 0x00e88870
void FUN_00e88870_cls::FUN_00e88870(int aiValue, bool abCopyCurrent)
{
    if (abCopyCurrent)
        m_10ec = m_10e8;
    if (m_10e8 != aiValue)
    {
        m_10e8 = aiValue;
        m_10f8->Forward(m_10f8, aiValue);
    }
}

extern unsigned short DAT_0126f958[];
struct S_00e88930_Item {
    int val;
    int unk04;
};
struct S_00e88930_Dev {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void __stdcall FUN_x10c(int a, int b, int c);
};
struct S_00e88930_Cls {
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
    S_00e88930_Item items[27][8];
    int unk10e0;
    int unk10e4;
    int unk10e8;
    int unk10ec;
    int unk10f0;
    int unk10f4;
    S_00e88930_Dev* dev;
    void SetItemValue(int a, int b, int c, int d);
};
// @fnv 0x00e88930
void S_00e88930_Cls::SetItemValue(int aiRow, int b, int aiValue, int aiUnused) {
    unsigned short slot = DAT_0126f958[b];
    if (slot < 8) {
        S_00e88930_Item* it = &items[aiRow][slot];
        if (it->val != aiValue) {
            dev->FUN_x10c(aiRow, b, aiValue);
        }
        it->val = aiValue;
    }
}

// 256-byte span of not-yet-identified fields.
struct E88980Block {
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
};

struct E88980SamplerState {
    unsigned int m_uiCurrentValue;
    unsigned int m_uiPrevValue;
};

extern unsigned short g_ausE88980SamplerMapping[];

// NiDX9RenderState::GetSamplerState
class E88980RenderState {
public:
    E88980Block m_kBlock00;
    E88980Block m_kBlock01;
    E88980Block m_kBlock02;
    E88980Block m_kBlock03;
    E88980Block m_kBlock04;
    E88980Block m_kBlock05;
    E88980Block m_kBlock06;
    E88980Block m_kBlock07;
    E88980Block m_kBlock08;
    E88980Block m_kBlock09;
    int unkA00;
    int unkA04;
    int unkA08;
    int unkA0C;
    int unkA10;
    int unkA14;
    int unkA18;
    int unkA1C;
    E88980SamplerState m_akSamplerStates[16][8];

    unsigned int GetSamplerStateId(unsigned int uiStage, unsigned int uiType);
};

// @fnv 0x00e88980
unsigned int E88980RenderState::GetSamplerStateId(unsigned int uiStage, unsigned int uiType) {
    unsigned short usIndex = g_ausE88980SamplerMapping[uiType];
    if (usIndex < 8)
        return m_akSamplerStates[uiStage][usIndex].m_uiCurrentValue;
    return 0;
}

struct FUN_00e88a20_cls
{
    void FUN_00e88a20(int a1, int a2);
};

typedef void (__stdcall *FUN_00e88a20_Slot)(void* self, int code, int value);

// If the value at table[a1] differs from a2, stores a2 there and calls the holder's slot callback with (a1, a2).
// @fnv 0x00e88a20
void FUN_00e88a20_cls::FUN_00e88a20(int aiIndex, int auiValue)
{
    unsigned int* table = (unsigned int*)((char*)this + 0x10a0);
    if (table[aiIndex] != (unsigned int)auiValue)
    {
        table[aiIndex] = auiValue;
        void* holder = *(void**)((char*)this + 0x10f8);
        FUN_00e88a20_Slot fn = (FUN_00e88a20_Slot)(*(void***)holder)[0x104 / 4];
        fn(holder, aiIndex, auiValue);
    }
}

struct FUN_00e88a60_Renderer {
    virtual void f00(int, int);
    virtual void f01(int, int);
    virtual void f02(int, int);
    virtual void f03(int, int);
    virtual void f04(int, int);
    virtual void f05(int, int);
    virtual void f06(int, int);
    virtual void f07(int, int);
    virtual void f08(int, int);
    virtual void f09(int, int);
    virtual void f10(int, int);
    virtual void f11(int, int);
    virtual void f12(int, int);
    virtual void f13(int, int);
    virtual void f14(int, int);
    virtual void f15(int, int);
    virtual void f16(int, int);
    virtual void f17(int, int);
    virtual void f18(int, int);
    virtual void f19(int, int);
    virtual void f20(int, int);
    virtual void f21(int, int);
    virtual void f22(int, int);
    virtual void f23(int, int);
    virtual void f24(int, int);
    virtual void f25(int, int);
    virtual void f26(int, int);
    virtual void f27(int, int);
    virtual void f28(int, int);
    virtual void f29(int, int);
    virtual void f30(int, int);
    virtual void f31(int, int);
    virtual void f32(int, int);
    virtual void f33(int, int);
    virtual void f34(int, int);
    virtual void f35(int, int);
    virtual void f36(int, int);
    virtual void f37(int, int);
    virtual void f38(int, int);
    virtual void f39(int, int);
    virtual void f40(int, int);
    virtual void f41(int, int);
    virtual void f42(int, int);
    virtual void f43(int, int);
    virtual void f44(int, int);
    virtual void f45(int, int);
    virtual void f46(int, int);
    virtual void f47(int, int);
    virtual void f48(int, int);
    virtual void f49(int, int);
    virtual void f50(int, int);
    virtual void f51(int, int);
    virtual void f52(int, int);
    virtual void f53(int, int);
    virtual void f54(int, int);
    virtual void f55(int, int);
    virtual void f56(int, int);
    virtual void f57(int, int);
    virtual void f58(int, int);
    virtual void f59(int, int);
    virtual void f60(int, int);
    virtual void f61(int, int);
    virtual void f62(int, int);
    virtual void f63(int, int);
    virtual void f64(int, int);
    virtual void __stdcall ClearSlotByValue(int, int);
};

struct FUN_00e88a60_Class {
    char m_auiShapeKeys[0x10a0];
    int m_10a0[16];
    char m_pAuxiliaryObject[0x18];
    FUN_00e88a60_Renderer* m_10f8;

    void __thiscall ClearSlotByValue(int value);
};

// @fnv 0x00e88a60
void __thiscall FUN_00e88a60_Class::ClearSlotByValue(int value)
{
    if (value != 0) {
        unsigned int index;
        for (index = 0; index < 16; ++index) {
            if (m_10a0[index] == value) {
                m_10a0[index] = 0;
                m_10f8->ClearSlotByValue(static_cast<int>(index), 0);
            }
        }
    }
}

// @fnv 0x00e88ac0
char __fastcall FUN_00e88ac0(void* self)
{
    return ((const char*)self)[0x10f4];
}

class FUN_00e88ae0_cls {
public:
    unsigned char FUN_00e88ae0();
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int unk02B0;
    int unk02B4;
    int unk02B8;
    int unk02BC;
    int unk02C0;
    int unk02C4;
    int unk02C8;
    int unk02CC;
    int unk02D0;
    int unk02D4;
    int unk02D8;
    int unk02DC;
    int unk02E0;
    int unk02E4;
    int unk02E8;
    int unk02EC;
    int unk02F0;
    int unk02F4;
    int unk02F8;
    int unk02FC;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030C;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031C;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032C;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033C;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034C;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035C;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036C;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037C;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038C;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039C;
    int unk03A0;
    int unk03A4;
    int unk03A8;
    int unk03AC;
    int unk03B0;
    int unk03B4;
    int unk03B8;
    int unk03BC;
    int unk03C0;
    int unk03C4;
    int unk03C8;
    int unk03CC;
    int unk03D0;
    int unk03D4;
    int unk03D8;
    int unk03DC;
    int unk03E0;
    int unk03E4;
    int unk03E8;
    int unk03EC;
    int unk03F0;
    int unk03F4;
    int unk03F8;
    int unk03FC;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040C;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041C;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042C;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043C;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044C;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045C;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046C;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047C;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048C;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049C;
    int unk04A0;
    int unk04A4;
    int unk04A8;
    int unk04AC;
    int unk04B0;
    int unk04B4;
    int unk04B8;
    int unk04BC;
    int unk04C0;
    int unk04C4;
    int unk04C8;
    int unk04CC;
    int unk04D0;
    int unk04D4;
    int unk04D8;
    int unk04DC;
    int unk04E0;
    int unk04E4;
    int unk04E8;
    int unk04EC;
    int unk04F0;
    int unk04F4;
    int unk04F8;
    int unk04FC;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050C;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051C;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052C;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053C;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054C;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055C;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056C;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057C;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058C;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059C;
    int unk05A0;
    int unk05A4;
    int unk05A8;
    int unk05AC;
    int unk05B0;
    int unk05B4;
    int unk05B8;
    int unk05BC;
    int unk05C0;
    int unk05C4;
    int unk05C8;
    int unk05CC;
    int unk05D0;
    int unk05D4;
    int unk05D8;
    int unk05DC;
    int unk05E0;
    int unk05E4;
    int unk05E8;
    int unk05EC;
    int unk05F0;
    int unk05F4;
    int unk05F8;
    int unk05FC;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060C;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061C;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062C;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063C;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064C;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065C;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066C;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067C;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068C;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069C;
    int unk06A0;
    int unk06A4;
    int unk06A8;
    int unk06AC;
    int unk06B0;
    int unk06B4;
    int unk06B8;
    int unk06BC;
    int unk06C0;
    int unk06C4;
    int unk06C8;
    int unk06CC;
    int unk06D0;
    int unk06D4;
    int unk06D8;
    int unk06DC;
    int unk06E0;
    int unk06E4;
    int unk06E8;
    int unk06EC;
    int unk06F0;
    int unk06F4;
    int unk06F8;
    int unk06FC;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070C;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071C;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072C;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073C;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074C;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075C;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076C;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077C;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078C;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079C;
    int unk07A0;
    int unk07A4;
    int unk07A8;
    int unk07AC;
    int unk07B0;
    int unk07B4;
    int unk07B8;
    int unk07BC;
    int unk07C0;
    int unk07C4;
    int unk07C8;
    int unk07CC;
    int unk07D0;
    int unk07D4;
    int unk07D8;
    int unk07DC;
    int unk07E0;
    int unk07E4;
    int unk07E8;
    int unk07EC;
    int unk07F0;
    int unk07F4;
    int unk07F8;
    int unk07FC;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080C;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081C;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082C;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083C;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084C;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085C;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086C;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087C;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088C;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089C;
    int unk08A0;
    int unk08A4;
    int unk08A8;
    int unk08AC;
    int unk08B0;
    int unk08B4;
    int unk08B8;
    int unk08BC;
    int unk08C0;
    int unk08C4;
    int unk08C8;
    int unk08CC;
    int unk08D0;
    int unk08D4;
    int unk08D8;
    int unk08DC;
    int unk08E0;
    int unk08E4;
    int unk08E8;
    int unk08EC;
    int unk08F0;
    int unk08F4;
    int unk08F8;
    int unk08FC;
    int unk0900;
    int unk0904;
    int unk0908;
    int unk090C;
    int unk0910;
    int unk0914;
    int unk0918;
    int unk091C;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092C;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093C;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094C;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095C;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096C;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097C;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098C;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099C;
    int unk09A0;
    int unk09A4;
    int unk09A8;
    int unk09AC;
    int unk09B0;
    int unk09B4;
    int unk09B8;
    int unk09BC;
    int unk09C0;
    int unk09C4;
    int unk09C8;
    int unk09CC;
    int unk09D0;
    int unk09D4;
    int unk09D8;
    int unk09DC;
    int unk09E0;
    int unk09E4;
    int unk09E8;
    int unk09EC;
    int unk09F0;
    int unk09F4;
    int unk09F8;
    int unk09FC;
    int unk0A00;
    int unk0A04;
    int unk0A08;
    int unk0A0C;
    int unk0A10;
    int unk0A14;
    int unk0A18;
    int unk0A1C;
    int unk0A20;
    int unk0A24;
    int unk0A28;
    int unk0A2C;
    int unk0A30;
    int unk0A34;
    int unk0A38;
    int unk0A3C;
    int unk0A40;
    int unk0A44;
    int unk0A48;
    int unk0A4C;
    int unk0A50;
    int unk0A54;
    int unk0A58;
    int unk0A5C;
    int unk0A60;
    int unk0A64;
    int unk0A68;
    int unk0A6C;
    int unk0A70;
    int unk0A74;
    int unk0A78;
    int unk0A7C;
    int unk0A80;
    int unk0A84;
    int unk0A88;
    int unk0A8C;
    int unk0A90;
    int unk0A94;
    int unk0A98;
    int unk0A9C;
    int unk0AA0;
    int unk0AA4;
    int unk0AA8;
    int unk0AAC;
    int unk0AB0;
    int unk0AB4;
    int unk0AB8;
    int unk0ABC;
    int unk0AC0;
    int unk0AC4;
    int unk0AC8;
    int unk0ACC;
    int unk0AD0;
    int unk0AD4;
    int unk0AD8;
    int unk0ADC;
    int unk0AE0;
    int unk0AE4;
    int unk0AE8;
    int unk0AEC;
    int unk0AF0;
    int unk0AF4;
    int unk0AF8;
    int unk0AFC;
    int unk0B00;
    int unk0B04;
    int unk0B08;
    int unk0B0C;
    int unk0B10;
    int unk0B14;
    int unk0B18;
    int unk0B1C;
    int unk0B20;
    int unk0B24;
    int unk0B28;
    int unk0B2C;
    int unk0B30;
    int unk0B34;
    int unk0B38;
    int unk0B3C;
    int unk0B40;
    int unk0B44;
    int unk0B48;
    int unk0B4C;
    int unk0B50;
    int unk0B54;
    int unk0B58;
    int unk0B5C;
    int unk0B60;
    int unk0B64;
    int unk0B68;
    int unk0B6C;
    int unk0B70;
    int unk0B74;
    int unk0B78;
    int unk0B7C;
    int unk0B80;
    int unk0B84;
    int unk0B88;
    int unk0B8C;
    int unk0B90;
    int unk0B94;
    int unk0B98;
    int unk0B9C;
    int unk0BA0;
    int unk0BA4;
    int unk0BA8;
    int unk0BAC;
    int unk0BB0;
    int unk0BB4;
    int unk0BB8;
    int unk0BBC;
    int unk0BC0;
    int unk0BC4;
    int unk0BC8;
    int unk0BCC;
    int unk0BD0;
    int unk0BD4;
    int unk0BD8;
    int unk0BDC;
    int unk0BE0;
    int unk0BE4;
    int unk0BE8;
    int unk0BEC;
    int unk0BF0;
    int unk0BF4;
    int unk0BF8;
    int unk0BFC;
    int unk0C00;
    int unk0C04;
    int unk0C08;
    int unk0C0C;
    int unk0C10;
    int unk0C14;
    int unk0C18;
    int unk0C1C;
    int unk0C20;
    int unk0C24;
    int unk0C28;
    int unk0C2C;
    int unk0C30;
    int unk0C34;
    int unk0C38;
    int unk0C3C;
    int unk0C40;
    int unk0C44;
    int unk0C48;
    int unk0C4C;
    int unk0C50;
    int unk0C54;
    int unk0C58;
    int unk0C5C;
    int unk0C60;
    int unk0C64;
    int unk0C68;
    int unk0C6C;
    int unk0C70;
    int unk0C74;
    int unk0C78;
    int unk0C7C;
    int unk0C80;
    int unk0C84;
    int unk0C88;
    int unk0C8C;
    int unk0C90;
    int unk0C94;
    int unk0C98;
    int unk0C9C;
    int unk0CA0;
    int unk0CA4;
    int unk0CA8;
    int unk0CAC;
    int unk0CB0;
    int unk0CB4;
    int unk0CB8;
    int unk0CBC;
    int unk0CC0;
    int unk0CC4;
    int unk0CC8;
    int unk0CCC;
    int unk0CD0;
    int unk0CD4;
    int unk0CD8;
    int unk0CDC;
    int unk0CE0;
    int unk0CE4;
    int unk0CE8;
    int unk0CEC;
    int unk0CF0;
    int unk0CF4;
    int unk0CF8;
    int unk0CFC;
    int unk0D00;
    int unk0D04;
    int unk0D08;
    int unk0D0C;
    int unk0D10;
    int unk0D14;
    int unk0D18;
    int unk0D1C;
    int unk0D20;
    int unk0D24;
    int unk0D28;
    int unk0D2C;
    int unk0D30;
    int unk0D34;
    int unk0D38;
    int unk0D3C;
    int unk0D40;
    int unk0D44;
    int unk0D48;
    int unk0D4C;
    int unk0D50;
    int unk0D54;
    int unk0D58;
    int unk0D5C;
    int unk0D60;
    int unk0D64;
    int unk0D68;
    int unk0D6C;
    int unk0D70;
    int unk0D74;
    int unk0D78;
    int unk0D7C;
    int unk0D80;
    int unk0D84;
    int unk0D88;
    int unk0D8C;
    int unk0D90;
    int unk0D94;
    int unk0D98;
    int unk0D9C;
    int unk0DA0;
    int unk0DA4;
    int unk0DA8;
    int unk0DAC;
    int unk0DB0;
    int unk0DB4;
    int unk0DB8;
    int unk0DBC;
    int unk0DC0;
    int unk0DC4;
    int unk0DC8;
    int unk0DCC;
    int unk0DD0;
    int unk0DD4;
    int unk0DD8;
    int unk0DDC;
    int unk0DE0;
    int unk0DE4;
    int unk0DE8;
    int unk0DEC;
    int unk0DF0;
    int unk0DF4;
    int unk0DF8;
    int unk0DFC;
    int unk0E00;
    int unk0E04;
    int unk0E08;
    int unk0E0C;
    int unk0E10;
    int unk0E14;
    int unk0E18;
    int unk0E1C;
    int unk0E20;
    int unk0E24;
    int unk0E28;
    int unk0E2C;
    int unk0E30;
    int unk0E34;
    int unk0E38;
    int unk0E3C;
    int unk0E40;
    int unk0E44;
    int unk0E48;
    int unk0E4C;
    int unk0E50;
    int unk0E54;
    int unk0E58;
    int unk0E5C;
    int unk0E60;
    int unk0E64;
    int unk0E68;
    int unk0E6C;
    int unk0E70;
    int unk0E74;
    int unk0E78;
    int unk0E7C;
    int unk0E80;
    int unk0E84;
    int unk0E88;
    int unk0E8C;
    int unk0E90;
    int unk0E94;
    int unk0E98;
    int unk0E9C;
    int unk0EA0;
    int unk0EA4;
    int unk0EA8;
    int unk0EAC;
    int unk0EB0;
    int unk0EB4;
    int unk0EB8;
    int unk0EBC;
    int unk0EC0;
    int unk0EC4;
    int unk0EC8;
    int unk0ECC;
    int unk0ED0;
    int unk0ED4;
    int unk0ED8;
    int unk0EDC;
    int unk0EE0;
    int unk0EE4;
    int unk0EE8;
    int unk0EEC;
    int unk0EF0;
    int unk0EF4;
    int unk0EF8;
    int unk0EFC;
    int unk0F00;
    int unk0F04;
    int unk0F08;
    int unk0F0C;
    int unk0F10;
    int unk0F14;
    int unk0F18;
    int unk0F1C;
    int unk0F20;
    int unk0F24;
    int unk0F28;
    int unk0F2C;
    int unk0F30;
    int unk0F34;
    int unk0F38;
    int unk0F3C;
    int unk0F40;
    int unk0F44;
    int unk0F48;
    int unk0F4C;
    int unk0F50;
    int unk0F54;
    int unk0F58;
    int unk0F5C;
    int unk0F60;
    int unk0F64;
    int unk0F68;
    int unk0F6C;
    int unk0F70;
    int unk0F74;
    int unk0F78;
    int unk0F7C;
    int unk0F80;
    int unk0F84;
    int unk0F88;
    int unk0F8C;
    int unk0F90;
    int unk0F94;
    int unk0F98;
    int unk0F9C;
    int unk0FA0;
    int unk0FA4;
    int unk0FA8;
    int unk0FAC;
    int unk0FB0;
    int unk0FB4;
    int unk0FB8;
    int unk0FBC;
    int unk0FC0;
    int unk0FC4;
    int unk0FC8;
    int unk0FCC;
    int unk0FD0;
    int unk0FD4;
    int unk0FD8;
    int unk0FDC;
    int unk0FE0;
    int unk0FE4;
    int unk0FE8;
    int unk0FEC;
    int unk0FF0;
    int unk0FF4;
    int unk0FF8;
    int unk0FFC;
    int unk1000;
    int unk1004;
    int unk1008;
    int unk100C;
    int unk1010;
    int unk1014;
    int unk1018;
    int unk101C;
    int unk1020;
    int unk1024;
    int unk1028;
    int unk102C;
    int unk1030;
    int unk1034;
    int unk1038;
    int unk103C;
    int unk1040;
    int unk1044;
    int unk1048;
    int unk104C;
    int unk1050;
    int unk1054;
    int unk1058;
    int unk105C;
    int unk1060;
    int unk1064;
    int unk1068;
    int unk106C;
    int unk1070;
    int unk1074;
    int unk1078;
    int unk107C;
    int unk1080;
    int unk1084;
    int unk1088;
    int unk108C;
    int unk1090;
    int unk1094;
    int unk1098;
    int unk109C;
    int unk10A0;
    int unk10A4;
    int unk10A8;
    int unk10AC;
    int unk10B0;
    int unk10B4;
    int unk10B8;
    int unk10BC;
    int unk10C0;
    int unk10C4;
    int unk10C8;
    int unk10CC;
    int unk10D0;
    int unk10D4;
    int unk10D8;
    int unk10DC;
    int unk10E0;
    int unk10E4;
    int unk10E8;
    int unk10EC;
    unsigned char unk10F0;
    unsigned char unk10F1;
    unsigned char unk10F2;
    unsigned char unk10F3;
    unsigned char unk10F4;
    unsigned char m_10f5;
};

// @fnv 0x00e88ae0
unsigned char FUN_00e88ae0_cls::FUN_00e88ae0() {
    return m_10f5;
}

struct FUN_00e88af0_Class {
    virtual void VF00();
    virtual void VF04();
    virtual void VF08();
    virtual void __thiscall VF0C(int value);

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

    void __thiscall FUN_00e88af0();
};

// @fnv 0x00e88af0
void __thiscall FUN_00e88af0_Class::FUN_00e88af0() {
    this->VF0C(this->unk74);
}

// NiD3DGeometryGroupManager
//   RTTI name  : .?AVNiD3DGeometryGroupManager@@   (vftable @ 0x010ef718)
//   Layout from the constructor at 0x00e88eb0 (the object is 0x1c bytes big):
//     +0x00  vftable pointer
//     +0x04  dword      +0x08  dword      +0x0c  dword
//     +0x10  dword      +0x14  dword      +0x18  byte flag
//   The single caller (0x00e73547) pushes a 0/1 byte and calls this setter.
struct NiD3DGeometryGroupManager {
    int m_vtbl;         // +0x00
    int m_04;           // +0x04
    int m_08;           // +0x08
    int m_0c;           // +0x0c
    int m_10;           // +0x10
    int m_14;           // +0x14
    bool m_18;          // +0x18
    void __thiscall FUN_00e88c20(bool flag);
};

// @fnv 0x00e88c20
void NiD3DGeometryGroupManager::FUN_00e88c20(bool flag) {
    m_18 = flag;
}

namespace fnv_00e88fc0 {
extern short DAT_0126f958[];

class E88FC0StageSet {
public:
    int unk00;
    int m_iVertexCount;
    int unk08;
    void* m_apvVertex[8];
    bool m_abVertex[8];
    int m_iPixelCount;
    int unk38;
    void* m_apvPixel[8];
    bool m_abPixel[8];

    void SetStageValue(unsigned int uiType, void* pvValue, bool bVertex);
};

// Maps uiType to a slot index and stores pvValue in the vertex or pixel array, moving the slot between the two and updating the counts.
// @fnv 0x00e88fc0
void E88FC0StageSet::SetStageValue(unsigned int uiType, void* pvValue, bool bVertex)
{
    unsigned short usIndex = DAT_0126f958[uiType];
    if (usIndex >= 8)
        return;

    if (bVertex) {
        if (m_abVertex[usIndex]) {
            m_apvVertex[usIndex] = pvValue;
            return;
        }
        if (m_abPixel[usIndex]) {
            m_abPixel[usIndex] = false;
            m_abVertex[usIndex] = true;
            m_apvVertex[usIndex] = pvValue;
            m_iPixelCount--;
            m_iVertexCount++;
        }
        m_abVertex[usIndex] = true;
        m_apvVertex[usIndex] = pvValue;
        m_iVertexCount++;
    } else {
        if (m_abPixel[usIndex]) {
            m_apvPixel[usIndex] = pvValue;
            return;
        }
        if (m_abVertex[usIndex]) {
            m_abVertex[usIndex] = false;
            m_abPixel[usIndex] = true;
            m_apvPixel[usIndex] = pvValue;
            m_iPixelCount++;
            m_iVertexCount--;
        }
        m_abPixel[usIndex] = true;
        m_apvPixel[usIndex] = pvValue;
        m_iPixelCount++;
    }
}
}  // namespace fnv_00e88fc0

extern unsigned short DAT_0126f92c[];

struct SlotGroup {
    int m_uiItemCount;
    int unk04;
    int m_iSlotIds[5];
    bool m_bSlotEnabled[5];
};

struct LightSlots {
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
    SlotGroup m_groupA;
    SlotGroup m_groupB;
    int m_countC;
    bool m_flagC[5];

    void FUN_00e890c0(int key, int value, bool typeA, bool flag);
};

// Maps key through DAT_0126f92c to a slot index and assigns value to group A or B, moving the slot between groups and updating the active and flagged counts.
// @fnv 0x00e890c0
void LightSlots::FUN_00e890c0(int key, int value, bool abGroupA, bool abFlagged)
{
    unsigned short s = DAT_0126f92c[key];
    if (s >= 5)
        return;
    int idx = s;
    if (abGroupA) {
        if (m_groupA.m_bSlotEnabled[idx]) {
            m_groupA.m_iSlotIds[idx] = value;
        } else {
            if (m_groupB.m_bSlotEnabled[idx]) {
                m_groupB.m_bSlotEnabled[idx] = false;
                m_groupB.m_uiItemCount--;
                if (m_flagC[idx])
                    m_countC--;
                m_flagC[idx] = false;
            }
            m_groupA.m_bSlotEnabled[idx] = true;
            m_groupA.m_iSlotIds[idx] = value;
            m_groupA.m_uiItemCount++;
            if (abFlagged)
                m_countC++;
            m_flagC[idx] = abFlagged;
            return;
        }
    } else {
        if (m_groupB.m_bSlotEnabled[idx]) {
            m_groupB.m_iSlotIds[idx] = value;
        } else {
            if (m_groupA.m_bSlotEnabled[idx]) {
                m_groupA.m_bSlotEnabled[idx] = false;
                m_groupA.m_uiItemCount--;
                if (m_flagC[idx])
                    m_countC--;
                m_flagC[idx] = false;
            }
            m_groupB.m_bSlotEnabled[idx] = true;
            m_groupB.m_iSlotIds[idx] = value;
            m_groupB.m_uiItemCount++;
            if (abFlagged)
                m_countC++;
            m_flagC[idx] = abFlagged;
            return;
        }
    }
    if (abFlagged) {
        if (!m_flagC[idx])
            m_countC++;
    } else {
        if (m_flagC[idx])
            m_countC--;
    }
    m_flagC[idx] = abFlagged;
}

extern unsigned short DAT_0126f948[8];

struct SlotDispatcher
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
    virtual int v30(int a, unsigned short b, int c, int d);
};

extern SlotDispatcher* DAT_0126f99c;

struct FUN_00e89250_cls
{
    int unk00[3];
    int m_0c[8];
    unsigned char m_2c[8];
    int unk34[2];
    int m_3c[8];
    unsigned char m_5c[8];
    int DispatchSlots(int param);
};

// For each of 8 slots, if m_5c[i] is set dispatches v30 with m_3c[i], else if m_2c[i] is set dispatches with m_0c[i], using DAT_0126f948[i].
// @fnv 0x00e89250
int FUN_00e89250_cls::DispatchSlots(int param)
{
    unsigned int i = 0;
    int* p = m_0c;
    for (; i < 8; i++, p++)
    {
        if (m_5c[i] != 0)
        {
            DAT_0126f99c->v30(param, DAT_0126f948[i], p[12], 0);
        }
        else if (m_2c[i] != 0)
        {
            DAT_0126f99c->v30(param, DAT_0126f948[i], p[0], 0);
        }
    }
    return 0;
}

namespace fnv_00e892d0 {
class GlobalMgr_0126f99c {
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
    virtual int v51(int a0, int a1, int a2, int a3);
};
extern GlobalMgr_0126f99c* DAT_0126f99c;
extern int DAT_0126f918[5];

class FUN_00e892d0_cls {
public:
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2C;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3C;
    int m_unk40;
    int m_unk44;
    int m_unk48;
    int m_unk4C;
    int m_unk50;
    int m_unk54;
    int m_unk58;
    int m_unk5C;
    int m_unk60;
    int m_unk64;
    int m_unk68;
    int m_6c[5];
    unsigned char m_80[5];
    unsigned char m_unk85;
    unsigned char m_unk86;
    unsigned char m_unk87;
    unsigned char m_unk88;
    unsigned char m_unk89;
    unsigned char m_unk8A;
    unsigned char m_unk8B;
    unsigned char m_unk8C;
    unsigned char m_unk8D;
    unsigned char m_unk8E;
    unsigned char m_unk8F;
    int m_90[5];
    unsigned char m_a4[5];

    int __thiscall FUN_00e892d0(int a1);
};

// For each of 5 slots, if m_a4[i] is set calls DAT_0126f99c->v51 with m_90[i], else if m_80[i] is set calls it with m_6c[i], then returns 0.
// @fnv 0x00e892d0
int FUN_00e892d0_cls::FUN_00e892d0(int a1) {
    for (unsigned int i = 0; i < 5; i++) {
        if (m_a4[i] != 0) {
            DAT_0126f99c->v51(a1, DAT_0126f918[i], m_90[i], 0);
        } else if (m_80[i] != 0) {
            DAT_0126f99c->v51(a1, DAT_0126f918[i], m_6c[i], 0);
        }
    }
    return 0;
}
}  // namespace fnv_00e892d0

struct FUN_00e89410_Class
{
    void* __thiscall DispatchSlots(unsigned int index);
    void* __thiscall FUN_00e892d0(unsigned int index);
    void* __thiscall GetItemByIndex(unsigned int index);
};

extern unsigned int DAT_011bf558;

// @fnv 0x00e89410
void* __thiscall FUN_00e89410_Class::GetItemByIndex(unsigned int index)
{
    void* item = 0;

    if (index < DAT_011bf558)
        item = DispatchSlots(index);

    void* result = FUN_00e892d0(index);

    if (item)
        result = item;

    return result;
}

struct ScalarDeletingObject {
    void FUN_00e89560();
    void* DestroyScalarObject(unsigned char flags);
};
// Calls FUN_00e89560, frees this via g_memoryManager when flags has bit 0 set, and returns this.
// @fnv 0x00e89440
void* ScalarDeletingObject::DestroyScalarObject(unsigned char flags) {
    FUN_00e89560();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

extern "C" void __cdecl FUN_00aa10f0(void*);
extern int DAT_010ef73c;
extern int DAT_0101dce4;
extern volatile long DAT_011f4400;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct ReleaseInterface {
    virtual void __stdcall GetType();
    virtual void __stdcall GetFlags();
    virtual void __stdcall Release();
};
struct FUN_00e89840_Class {
    void* m_ppVirtualMethodTable;
    int m_04;
    int m_08;
    void* m_0c;
    void* m_10;
    int m_14;
    void* m_18;
    int m_1c;
    ReleaseInterface* m_20;
    int m_24;
    int m_28;
    void FUN_00e89840();
};
// @fnv 0x00e89840
void FUN_00e89840_Class::FUN_00e89840()
{
    m_ppVirtualMethodTable = &DAT_010ef73c;
    FUN_00aa10f0(m_0c);
    FUN_00aa10f0(m_10);
    FUN_00aa10f0(m_18);
    m_24 = 0;
    m_28 = 0;
    if (m_20 != 0) m_20->Release();
    m_20 = 0;
    m_ppVirtualMethodTable = &DAT_0101dce4;
    InterlockedDecrement(&DAT_011f4400);
}

struct FUN_00e89ae0_obj;
typedef int (__stdcall *FUN_00e89ae0_vfn)(FUN_00e89ae0_obj*, int, int, int);
struct FUN_00e89ae0_obj { void** vtbl; };
struct FUN_00e89ae0_cls {
    int unk0000; int unk0004; int unk0008; int unk000C; int unk0010; int unk0014; int unk0018; int unk001C; int unk0020; int unk0024; int unk0028; int unk002C;
    int unk0030; int unk0034; int unk0038; int unk003C; int unk0040; int unk0044; int unk0048; int unk004C; int unk0050; int unk0054; int unk0058; int unk005C;
    int unk0060; int unk0064; int unk0068; int unk006C; int unk0070; int unk0074; int unk0078; int unk007C; int unk0080; int unk0084; int unk0088; int unk008C;
    int unk0090; int unk0094; int unk0098; int unk009C; int unk00A0; int unk00A4; int unk00A8; int unk00AC; int unk00B0; int unk00B4; int unk00B8; int unk00BC;
    int unk00C0; int unk00C4; int unk00C8; int unk00CC; int unk00D0; int unk00D4; int unk00D8; int unk00DC; int unk00E0; int unk00E4; int unk00E8; int unk00EC;
    int unk00F0; int unk00F4; int unk00F8; int unk00FC; int unk0100; int unk0104; int unk0108; int unk010C; int unk0110; int unk0114; int unk0118; int unk011C;
    int unk0120; int unk0124; int unk0128; int unk012C; int unk0130; int unk0134; int unk0138; int unk013C; int unk0140; int unk0144; int unk0148; int unk014C;
    int unk0150; int unk0154; int unk0158; int unk015C; int unk0160; int unk0164; int unk0168; int unk016C; int unk0170; int unk0174; int unk0178; int unk017C;
    int unk0180; int unk0184; int unk0188; int unk018C; int unk0190; int unk0194; int unk0198; int unk019C; int unk01A0; int unk01A4; int unk01A8; int unk01AC;
    int unk01B0; int unk01B4; int unk01B8; int unk01BC; int unk01C0; int unk01C4; int unk01C8; int unk01CC; int unk01D0; int unk01D4; int unk01D8; int unk01DC;
    int unk01E0; int unk01E4; int unk01E8; int unk01EC; int unk01F0; int unk01F4; int unk01F8; int unk01FC; int unk0200; int unk0204; int unk0208; int unk020C;
    int unk0210; int unk0214; int unk0218; int unk021C; int unk0220; int unk0224; int unk0228; int unk022C; int unk0230; int unk0234; int unk0238; int unk023C;
    int unk0240; int unk0244; int unk0248; int unk024C; int unk0250; int unk0254; int unk0258; int unk025C; int unk0260; int unk0264; int unk0268; int unk026C;
    int unk0270; int unk0274; int unk0278; int unk027C; int unk0280; int unk0284; int unk0288; int unk028C; int unk0290; int unk0294; int unk0298; int unk029C;
    int unk02A0; int unk02A4; int unk02A8; int unk02AC; int unk02B0; int unk02B4; int unk02B8; int unk02BC; int unk02C0; int unk02C4; int unk02C8; int unk02CC;
    int unk02D0; int unk02D4; int unk02D8; int unk02DC; int unk02E0; int unk02E4; int unk02E8; int unk02EC; int unk02F0; int unk02F4; int unk02F8; int unk02FC;
    int unk0300; int unk0304; int unk0308; int unk030C; int unk0310; int unk0314; int unk0318; int unk031C; int unk0320; int unk0324; int unk0328; int unk032C;
    int unk0330; int unk0334; int unk0338; int unk033C; int unk0340; int unk0344; int unk0348; int unk034C; int unk0350; int unk0354; int unk0358; int unk035C;
    int unk0360; int unk0364; int unk0368; int unk036C; int unk0370; int unk0374; int unk0378; int unk037C; int unk0380; int unk0384; int unk0388; int unk038C;
    int unk0390; int unk0394; int unk0398; int unk039C; int unk03A0; int unk03A4; int unk03A8; int unk03AC; int unk03B0; int unk03B4; int unk03B8; int unk03BC;
    int unk03C0; int unk03C4; int unk03C8; int unk03CC; int unk03D0; int unk03D4; int unk03D8; int unk03DC; int unk03E0; int unk03E4; int unk03E8; int unk03EC;
    int unk03F0; int unk03F4; int unk03F8; int unk03FC; int unk0400; int unk0404; int unk0408; int unk040C; int unk0410; int unk0414; int unk0418; int unk041C;
    int unk0420; int unk0424; int unk0428; int unk042C; int unk0430; int unk0434; int unk0438; int unk043C; int unk0440; int unk0444; int unk0448; int unk044C;
    int unk0450; int unk0454; int unk0458; int unk045C; int unk0460; int unk0464; int unk0468; int unk046C; int unk0470; int unk0474; int unk0478; int unk047C;
    int unk0480; int unk0484; int unk0488; int unk048C; int unk0490; int unk0494; int unk0498; int unk049C; int unk04A0; int unk04A4; int unk04A8; int unk04AC;
    int unk04B0; int unk04B4; int unk04B8; int unk04BC; int unk04C0; int unk04C4; int unk04C8; int unk04CC; int unk04D0; int unk04D4; int unk04D8; int unk04DC;
    int unk04E0; int unk04E4; int unk04E8; int unk04EC; int unk04F0; int unk04F4; int unk04F8; int unk04FC; int unk0500; int unk0504; int unk0508; int unk050C;
    int unk0510; int unk0514; int unk0518; int unk051C; int unk0520; int unk0524; int unk0528; int unk052C; int unk0530; int unk0534; int unk0538; int unk053C;
    int unk0540; int unk0544; int unk0548; int unk054C; int unk0550; int unk0554; int unk0558; int unk055C; int unk0560; int unk0564; int unk0568; int unk056C;
    int unk0570; int unk0574; int unk0578; int unk057C; int unk0580; int unk0584; int unk0588; int unk058C; int unk0590; int unk0594; int unk0598; int unk059C;
    int unk05A0; int unk05A4; int unk05A8; int unk05AC; int unk05B0; int unk05B4; int unk05B8; int unk05BC; int unk05C0; int unk05C4; int unk05C8; int unk05CC;
    int unk05D0; int unk05D4; int unk05D8; int unk05DC; int unk05E0; int unk05E4; int unk05E8; int unk05EC; int unk05F0; int unk05F4; int unk05F8; int unk05FC;
    int unk0600; int unk0604; int unk0608; int unk060C; int unk0610; int unk0614; int unk0618; int unk061C; int unk0620; int unk0624; int unk0628; int unk062C;
    int unk0630; int unk0634; int unk0638; int unk063C; int unk0640; int unk0644; int unk0648; int unk064C; int unk0650; int unk0654; int unk0658; int unk065C;
    int unk0660; int unk0664; int unk0668; int unk066C; int unk0670; int unk0674; int unk0678; int unk067C; int unk0680; int unk0684; int unk0688; int unk068C;
    int unk0690; int unk0694; int unk0698; int unk069C; int unk06A0; int unk06A4; int unk06A8; int unk06AC; int unk06B0; int unk06B4; int unk06B8; int unk06BC;
    int unk06C0; int unk06C4; int unk06C8; int unk06CC; int unk06D0; int unk06D4; int unk06D8; int unk06DC; int unk06E0; int unk06E4; int unk06E8; int unk06EC;
    int unk06F0; int unk06F4; int unk06F8; int unk06FC; int unk0700; int unk0704; int unk0708; int unk070C; int unk0710; int unk0714; int unk0718; int unk071C;
    int unk0720; int unk0724; int unk0728; int unk072C; int unk0730; int unk0734; int unk0738; int unk073C; int unk0740; int unk0744; int unk0748; int unk074C;
    int unk0750; int unk0754; int unk0758; int unk075C; int unk0760; int unk0764; int unk0768; int unk076C; int unk0770; int unk0774; int unk0778; int unk077C;
    int unk0780; int unk0784; int unk0788; int unk078C; int unk0790; int unk0794; int unk0798; int unk079C; int unk07A0; int unk07A4; int unk07A8; int unk07AC;
    int unk07B0; int unk07B4; int unk07B8; int unk07BC; int unk07C0; int unk07C4; int unk07C8; int unk07CC; int unk07D0; int unk07D4; int unk07D8; int unk07DC;
    int unk07E0; int unk07E4; int unk07E8; int unk07EC; int unk07F0; int unk07F4; int unk07F8; int unk07FC; int unk0800; int unk0804; int unk0808; int unk080C;
    int unk0810; int unk0814; int unk0818; int unk081C; int unk0820; int unk0824; int unk0828; int unk082C; int unk0830; int unk0834; int unk0838; int unk083C;
    int unk0840; int unk0844; int unk0848; int unk084C; int unk0850; int unk0854; int unk0858; int unk085C; int unk0860; int unk0864; int unk0868; int unk086C;
    int unk0870; int unk0874; int unk0878; int unk087C; int unk0880; int unk0884; int unk0888; int unk088C; int unk0890; int unk0894; int unk0898; int unk089C;
    int unk08A0; int unk08A4; int unk08A8; int unk08AC; int unk08B0; int unk08B4; int unk08B8; int unk08BC; int unk08C0; int unk08C4; int unk08C8; int unk08CC;
    int unk08D0; int unk08D4; int unk08D8; int unk08DC; int unk08E0; int unk08E4; int unk08E8; int unk08EC; int unk08F0; int unk08F4; int unk08F8; int unk08FC;
    int unk0900; int unk0904; int unk0908; int unk090C; int unk0910; int unk0914; int unk0918; int unk091C; int unk0920; int unk0924; int unk0928; int unk092C;
    int unk0930; int unk0934; int unk0938; int unk093C; int unk0940; int unk0944; int unk0948; int unk094C; int unk0950; int unk0954; int unk0958; int unk095C;
    int unk0960; int unk0964; int unk0968; int unk096C; int unk0970; int unk0974; int unk0978; int unk097C; int unk0980; int unk0984; int unk0988; int unk098C;
    int unk0990; int unk0994; int unk0998; int unk099C; int unk09A0; int unk09A4; int unk09A8; int unk09AC; int unk09B0; int unk09B4; int unk09B8; int unk09BC;
    int unk09C0; int unk09C4; int unk09C8; int unk09CC; int unk09D0; int unk09D4; int unk09D8; int unk09DC; int unk09E0; int unk09E4; int unk09E8; int unk09EC;
    int unk09F0; int unk09F4; int unk09F8; int unk09FC; int unk0A00; int unk0A04; int unk0A08; int unk0A0C; int unk0A10; int unk0A14; int unk0A18; int unk0A1C;
    int unk0A20; int unk0A24; int unk0A28; int unk0A2C; int unk0A30; int unk0A34; int unk0A38; int unk0A3C; int unk0A40; int unk0A44; int unk0A48; int unk0A4C;
    int unk0A50; int unk0A54; int unk0A58; int unk0A5C; int unk0A60; int unk0A64; int unk0A68; int unk0A6C; int unk0A70; int unk0A74; int unk0A78; int unk0A7C;
    int unk0A80; int unk0A84; int unk0A88; int unk0A8C; int unk0A90; int unk0A94; int unk0A98; int unk0A9C; int unk0AA0; int unk0AA4; int unk0AA8; int unk0AAC;
    int unk0AB0; int unk0AB4; int unk0AB8; int unk0ABC; int unk0AC0; int unk0AC4; int unk0AC8; int unk0ACC; int unk0AD0; int unk0AD4; int unk0AD8; int unk0ADC;
    int unk0AE0; int unk0AE4; int unk0AE8; int unk0AEC; int unk0AF0; int unk0AF4; int unk0AF8; int unk0AFC; int unk0B00; int unk0B04; int unk0B08; int unk0B0C;
    int unk0B10; int unk0B14; int unk0B18; int unk0B1C; int unk0B20; int unk0B24; int unk0B28; int unk0B2C; int unk0B30; int unk0B34; int unk0B38; int unk0B3C;
    int unk0B40; int unk0B44; int unk0B48; int unk0B4C; int unk0B50; int unk0B54; int unk0B58; int unk0B5C; int unk0B60; int unk0B64; int unk0B68; int unk0B6C;
    int unk0B70; int unk0B74; int unk0B78; int unk0B7C; int unk0B80; int unk0B84; int unk0B88; int unk0B8C; int unk0B90; int unk0B94; int unk0B98; int unk0B9C;
    int unk0BA0; int unk0BA4; int unk0BA8; int unk0BAC; int unk0BB0; int unk0BB4; int unk0BB8; int unk0BBC; int unk0BC0; int unk0BC4; int unk0BC8; int unk0BCC;
    int unk0BD0; int unk0BD4; int unk0BD8; int unk0BDC; int unk0BE0; int unk0BE4; int unk0BE8; int unk0BEC; int unk0BF0; int unk0BF4; int unk0BF8; int unk0BFC;
    int unk0C00; int unk0C04; int unk0C08; int unk0C0C; int unk0C10; int unk0C14; int unk0C18; int unk0C1C; int unk0C20; int unk0C24; int unk0C28; int unk0C2C;
    int unk0C30; int unk0C34; int unk0C38; int unk0C3C; int unk0C40; int unk0C44; int unk0C48; int unk0C4C; int unk0C50; int unk0C54; int unk0C58; int unk0C5C;
    int unk0C60; int unk0C64; int unk0C68; int unk0C6C; int unk0C70; int unk0C74; int unk0C78; int unk0C7C; int unk0C80; int unk0C84; int unk0C88; int unk0C8C;
    int unk0C90; int unk0C94; int unk0C98; int unk0C9C; int unk0CA0; int unk0CA4; int unk0CA8; int unk0CAC; int unk0CB0; int unk0CB4; int unk0CB8; int unk0CBC;
    int unk0CC0; int unk0CC4; int unk0CC8; int unk0CCC; int unk0CD0; int unk0CD4; int unk0CD8; int unk0CDC; int unk0CE0; int unk0CE4; int unk0CE8; int unk0CEC;
    int unk0CF0; int unk0CF4; int unk0CF8; int unk0CFC; int unk0D00; int unk0D04; int unk0D08; int unk0D0C; int unk0D10; int unk0D14; int unk0D18; int unk0D1C;
    int unk0D20; int unk0D24; int unk0D28; int unk0D2C; int unk0D30; int unk0D34; int unk0D38; int unk0D3C; int unk0D40; int unk0D44; int unk0D48; int unk0D4C;
    int unk0D50; int unk0D54; int unk0D58; int unk0D5C; int unk0D60; int unk0D64; int unk0D68; int unk0D6C; int unk0D70; int unk0D74; int unk0D78; int unk0D7C;
    int unk0D80; int unk0D84; int unk0D88; int unk0D8C; int unk0D90; int unk0D94; int unk0D98; int unk0D9C; int unk0DA0; int unk0DA4; int unk0DA8; int unk0DAC;
    int unk0DB0; int unk0DB4; int unk0DB8; int unk0DBC; int unk0DC0; int unk0DC4; int unk0DC8; int unk0DCC; int unk0DD0; int unk0DD4; int unk0DD8; int unk0DDC;
    int unk0DE0; int unk0DE4; int unk0DE8; int unk0DEC; int unk0DF0; int unk0DF4; int unk0DF8; int unk0DFC; int unk0E00; int unk0E04; int unk0E08; int unk0E0C;
    int unk0E10; int unk0E14; int unk0E18; int unk0E1C; int unk0E20; int unk0E24; int unk0E28; int unk0E2C; int unk0E30; int unk0E34; int unk0E38; int unk0E3C;
    int unk0E40; int unk0E44; int unk0E48; int unk0E4C; int unk0E50; int unk0E54; int unk0E58; int unk0E5C; int unk0E60; int unk0E64; int unk0E68; int unk0E6C;
    int unk0E70; int unk0E74; int unk0E78; int unk0E7C; int unk0E80; int unk0E84; int unk0E88; int unk0E8C; int unk0E90; int unk0E94; int unk0E98; int unk0E9C;
    int unk0EA0; int unk0EA4; int unk0EA8; int unk0EAC; int unk0EB0; int unk0EB4; int unk0EB8; int unk0EBC; int unk0EC0; int unk0EC4; int unk0EC8; int unk0ECC;
    int unk0ED0; int unk0ED4; int unk0ED8; int unk0EDC; int unk0EE0; int unk0EE4; int unk0EE8; int unk0EEC; int unk0EF0; int unk0EF4; int unk0EF8; int unk0EFC;
    int unk0F00; int unk0F04; int unk0F08; int unk0F0C; int unk0F10; int unk0F14; int unk0F18; int unk0F1C; int unk0F20; int unk0F24; int unk0F28; int unk0F2C;
    int unk0F30; int unk0F34; int unk0F38; int unk0F3C; int unk0F40; int unk0F44; int unk0F48; int unk0F4C; int unk0F50; int unk0F54; int unk0F58; int unk0F5C;
    int unk0F60; int unk0F64; int unk0F68; int unk0F6C; int unk0F70; int unk0F74; int unk0F78; int unk0F7C; int unk0F80; int unk0F84; int unk0F88; int unk0F8C;
    int unk0F90; int unk0F94; int unk0F98; int unk0F9C; int unk0FA0; int unk0FA4; int unk0FA8; int unk0FAC; int unk0FB0; int unk0FB4; int unk0FB8; int unk0FBC;
    int unk0FC0; int unk0FC4; int unk0FC8; int unk0FCC; int unk0FD0; int unk0FD4; int unk0FD8; int unk0FDC; int unk0FE0; int unk0FE4; int unk0FE8; int unk0FEC;
    int unk0FF0; int unk0FF4; int unk0FF8; int unk0FFC; int unk1000; int unk1004; int unk1008; int unk100C; int unk1010; int unk1014; int unk1018; int unk101C;
    int unk1020; int unk1024; int unk1028; int unk102C; int unk1030; int unk1034; int unk1038; int unk103C; int unk1040; int unk1044; int unk1048; int unk104C;
    int unk1050; int unk1054; int unk1058; int unk105C; int unk1060; int unk1064; int unk1068; int unk106C; int unk1070; int unk1074; int unk1078; int unk107C;
    int unk1080; int unk1084; int unk1088; int unk108C; int unk1090; int unk1094; int unk1098; int unk109C; int unk10A0; int unk10A4; int unk10A8; int unk10AC;
    int unk10B0; int unk10B4; int unk10B8; int unk10BC; int unk10C0; int unk10C4; int unk10C8; int unk10CC; int unk10D0; int unk10D4; int unk10D8; int unk10DC;
    int unk10E0; int unk10E4; int unk10E8; int unk10EC; int unk10F0; int unk10F4;
    FUN_00e89ae0_obj* m_10f8;
    bool IsVtblCallSucceeded(int a1, int a2, int a3, int a4);
};
// Calls virtual method slot 0x62 on m_10f8 with a1, a2, a3 and returns whether the result is non-negative.
// @fnv 0x00e89ae0
bool FUN_00e89ae0_cls::IsVtblCallSucceeded(int a1, int a2, int a3, int a4) {
    FUN_00e89ae0_obj* obj = m_10f8;
    return ((FUN_00e89ae0_vfn)obj->vtbl[0x62])(obj, a1, a2, a3) >= 0;
}

struct E89B40Device {
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
    virtual long __stdcall vfunc11();
    virtual long __stdcall vfunc12();
    virtual long __stdcall vfunc13();
    virtual long __stdcall vfunc14();
    virtual long __stdcall vfunc15();
    virtual long __stdcall vfunc16();
    virtual long __stdcall vfunc17();
    virtual long __stdcall vfunc18();
    virtual long __stdcall vfunc19();
    virtual long __stdcall vfunc1A();
    virtual long __stdcall vfunc1B();
    virtual long __stdcall vfunc1C();
    virtual long __stdcall vfunc1D();
    virtual long __stdcall vfunc1E();
    virtual long __stdcall vfunc1F();
    virtual long __stdcall vfunc20();
    virtual long __stdcall vfunc21();
    virtual long __stdcall vfunc22();
    virtual long __stdcall vfunc23();
    virtual long __stdcall vfunc24();
    virtual long __stdcall vfunc25();
    virtual long __stdcall vfunc26();
    virtual long __stdcall vfunc27();
    virtual long __stdcall vfunc28();
    virtual long __stdcall vfunc29();
    virtual long __stdcall vfunc2A();
    virtual long __stdcall vfunc2B();
    virtual long __stdcall vfunc2C();
    virtual long __stdcall vfunc2D();
    virtual long __stdcall vfunc2E();
    virtual long __stdcall vfunc2F();
    virtual long __stdcall vfunc30();
    virtual long __stdcall vfunc31();
    virtual long __stdcall vfunc32();
    virtual long __stdcall vfunc33();
    virtual long __stdcall vfunc34();
    virtual long __stdcall vfunc35();
    virtual long __stdcall vfunc36();
    virtual long __stdcall vfunc37();
    virtual long __stdcall vfunc38();
    virtual long __stdcall vfunc39();
    virtual long __stdcall vfunc3A();
    virtual long __stdcall vfunc3B();
    virtual long __stdcall vfunc3C();
    virtual long __stdcall vfunc3D();
    virtual long __stdcall vfunc3E();
    virtual long __stdcall vfunc3F();
    virtual long __stdcall vfunc40();
    virtual long __stdcall vfunc41();
    virtual long __stdcall vfunc42();
    virtual long __stdcall vfunc43();
    virtual long __stdcall vfunc44();
    virtual long __stdcall vfunc45();
    virtual long __stdcall vfunc46();
    virtual long __stdcall vfunc47();
    virtual long __stdcall vfunc48();
    virtual long __stdcall vfunc49();
    virtual long __stdcall vfunc4A();
    virtual long __stdcall vfunc4B();
    virtual long __stdcall vfunc4C();
    virtual long __stdcall vfunc4D();
    virtual long __stdcall vfunc4E();
    virtual long __stdcall vfunc4F();
    virtual long __stdcall vfunc50();
    virtual long __stdcall vfunc51();
    virtual long __stdcall vfunc52();
    virtual long __stdcall vfunc53();
    virtual long __stdcall vfunc54();
    virtual long __stdcall vfunc55();
    virtual long __stdcall vfunc56();
    virtual long __stdcall vfunc57();
    virtual long __stdcall vfunc58();
    virtual long __stdcall vfunc59();
    virtual long __stdcall vfunc5A();
    virtual long __stdcall vfunc5B();
    virtual long __stdcall vfunc5C();
    virtual long __stdcall vfunc5D();
    virtual long __stdcall vfunc5E();
    virtual long __stdcall vfunc5F();
    virtual long __stdcall SetState(unsigned int uiA, unsigned int uiB, unsigned int uiC);
};

class E89B40Renderer {
public:
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int unk02B0;
    int unk02B4;
    int unk02B8;
    int unk02BC;
    int unk02C0;
    int unk02C4;
    int unk02C8;
    int unk02CC;
    int unk02D0;
    int unk02D4;
    int unk02D8;
    int unk02DC;
    int unk02E0;
    int unk02E4;
    int unk02E8;
    int unk02EC;
    int unk02F0;
    int unk02F4;
    int unk02F8;
    int unk02FC;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030C;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031C;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032C;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033C;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034C;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035C;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036C;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037C;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038C;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039C;
    int unk03A0;
    int unk03A4;
    int unk03A8;
    int unk03AC;
    int unk03B0;
    int unk03B4;
    int unk03B8;
    int unk03BC;
    int unk03C0;
    int unk03C4;
    int unk03C8;
    int unk03CC;
    int unk03D0;
    int unk03D4;
    int unk03D8;
    int unk03DC;
    int unk03E0;
    int unk03E4;
    int unk03E8;
    int unk03EC;
    int unk03F0;
    int unk03F4;
    int unk03F8;
    int unk03FC;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040C;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041C;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042C;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043C;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044C;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045C;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046C;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047C;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048C;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049C;
    int unk04A0;
    int unk04A4;
    int unk04A8;
    int unk04AC;
    int unk04B0;
    int unk04B4;
    int unk04B8;
    int unk04BC;
    int unk04C0;
    int unk04C4;
    int unk04C8;
    int unk04CC;
    int unk04D0;
    int unk04D4;
    int unk04D8;
    int unk04DC;
    int unk04E0;
    int unk04E4;
    int unk04E8;
    int unk04EC;
    int unk04F0;
    int unk04F4;
    int unk04F8;
    int unk04FC;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050C;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051C;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052C;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053C;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054C;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055C;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056C;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057C;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058C;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059C;
    int unk05A0;
    int unk05A4;
    int unk05A8;
    int unk05AC;
    int unk05B0;
    int unk05B4;
    int unk05B8;
    int unk05BC;
    int unk05C0;
    int unk05C4;
    int unk05C8;
    int unk05CC;
    int unk05D0;
    int unk05D4;
    int unk05D8;
    int unk05DC;
    int unk05E0;
    int unk05E4;
    int unk05E8;
    int unk05EC;
    int unk05F0;
    int unk05F4;
    int unk05F8;
    int unk05FC;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060C;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061C;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062C;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063C;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064C;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065C;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066C;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067C;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068C;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069C;
    int unk06A0;
    int unk06A4;
    int unk06A8;
    int unk06AC;
    int unk06B0;
    int unk06B4;
    int unk06B8;
    int unk06BC;
    int unk06C0;
    int unk06C4;
    int unk06C8;
    int unk06CC;
    int unk06D0;
    int unk06D4;
    int unk06D8;
    int unk06DC;
    int unk06E0;
    int unk06E4;
    int unk06E8;
    int unk06EC;
    int unk06F0;
    int unk06F4;
    int unk06F8;
    int unk06FC;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070C;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071C;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072C;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073C;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074C;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075C;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076C;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077C;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078C;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079C;
    int unk07A0;
    int unk07A4;
    int unk07A8;
    int unk07AC;
    int unk07B0;
    int unk07B4;
    int unk07B8;
    int unk07BC;
    int unk07C0;
    int unk07C4;
    int unk07C8;
    int unk07CC;
    int unk07D0;
    int unk07D4;
    int unk07D8;
    int unk07DC;
    int unk07E0;
    int unk07E4;
    int unk07E8;
    int unk07EC;
    int unk07F0;
    int unk07F4;
    int unk07F8;
    int unk07FC;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080C;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081C;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082C;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083C;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084C;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085C;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086C;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087C;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088C;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089C;
    int unk08A0;
    int unk08A4;
    int unk08A8;
    int unk08AC;
    int unk08B0;
    int unk08B4;
    int unk08B8;
    int unk08BC;
    int unk08C0;
    int unk08C4;
    int unk08C8;
    int unk08CC;
    int unk08D0;
    int unk08D4;
    int unk08D8;
    int unk08DC;
    int unk08E0;
    int unk08E4;
    int unk08E8;
    int unk08EC;
    int unk08F0;
    int unk08F4;
    int unk08F8;
    int unk08FC;
    int unk0900;
    int unk0904;
    int unk0908;
    int unk090C;
    int unk0910;
    int unk0914;
    int unk0918;
    int unk091C;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092C;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093C;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094C;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095C;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096C;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097C;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098C;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099C;
    int unk09A0;
    int unk09A4;
    int unk09A8;
    int unk09AC;
    int unk09B0;
    int unk09B4;
    int unk09B8;
    int unk09BC;
    int unk09C0;
    int unk09C4;
    int unk09C8;
    int unk09CC;
    int unk09D0;
    int unk09D4;
    int unk09D8;
    int unk09DC;
    int unk09E0;
    int unk09E4;
    int unk09E8;
    int unk09EC;
    int unk09F0;
    int unk09F4;
    int unk09F8;
    int unk09FC;
    int unk0A00;
    int unk0A04;
    int unk0A08;
    int unk0A0C;
    int unk0A10;
    int unk0A14;
    int unk0A18;
    int unk0A1C;
    int unk0A20;
    int unk0A24;
    int unk0A28;
    int unk0A2C;
    int unk0A30;
    int unk0A34;
    int unk0A38;
    int unk0A3C;
    int unk0A40;
    int unk0A44;
    int unk0A48;
    int unk0A4C;
    int unk0A50;
    int unk0A54;
    int unk0A58;
    int unk0A5C;
    int unk0A60;
    int unk0A64;
    int unk0A68;
    int unk0A6C;
    int unk0A70;
    int unk0A74;
    int unk0A78;
    int unk0A7C;
    int unk0A80;
    int unk0A84;
    int unk0A88;
    int unk0A8C;
    int unk0A90;
    int unk0A94;
    int unk0A98;
    int unk0A9C;
    int unk0AA0;
    int unk0AA4;
    int unk0AA8;
    int unk0AAC;
    int unk0AB0;
    int unk0AB4;
    int unk0AB8;
    int unk0ABC;
    int unk0AC0;
    int unk0AC4;
    int unk0AC8;
    int unk0ACC;
    int unk0AD0;
    int unk0AD4;
    int unk0AD8;
    int unk0ADC;
    int unk0AE0;
    int unk0AE4;
    int unk0AE8;
    int unk0AEC;
    int unk0AF0;
    int unk0AF4;
    int unk0AF8;
    int unk0AFC;
    int unk0B00;
    int unk0B04;
    int unk0B08;
    int unk0B0C;
    int unk0B10;
    int unk0B14;
    int unk0B18;
    int unk0B1C;
    int unk0B20;
    int unk0B24;
    int unk0B28;
    int unk0B2C;
    int unk0B30;
    int unk0B34;
    int unk0B38;
    int unk0B3C;
    int unk0B40;
    int unk0B44;
    int unk0B48;
    int unk0B4C;
    int unk0B50;
    int unk0B54;
    int unk0B58;
    int unk0B5C;
    int unk0B60;
    int unk0B64;
    int unk0B68;
    int unk0B6C;
    int unk0B70;
    int unk0B74;
    int unk0B78;
    int unk0B7C;
    int unk0B80;
    int unk0B84;
    int unk0B88;
    int unk0B8C;
    int unk0B90;
    int unk0B94;
    int unk0B98;
    int unk0B9C;
    int unk0BA0;
    int unk0BA4;
    int unk0BA8;
    int unk0BAC;
    int unk0BB0;
    int unk0BB4;
    int unk0BB8;
    int unk0BBC;
    int unk0BC0;
    int unk0BC4;
    int unk0BC8;
    int unk0BCC;
    int unk0BD0;
    int unk0BD4;
    int unk0BD8;
    int unk0BDC;
    int unk0BE0;
    int unk0BE4;
    int unk0BE8;
    int unk0BEC;
    int unk0BF0;
    int unk0BF4;
    int unk0BF8;
    int unk0BFC;
    int unk0C00;
    int unk0C04;
    int unk0C08;
    int unk0C0C;
    int unk0C10;
    int unk0C14;
    int unk0C18;
    int unk0C1C;
    int unk0C20;
    int unk0C24;
    int unk0C28;
    int unk0C2C;
    int unk0C30;
    int unk0C34;
    int unk0C38;
    int unk0C3C;
    int unk0C40;
    int unk0C44;
    int unk0C48;
    int unk0C4C;
    int unk0C50;
    int unk0C54;
    int unk0C58;
    int unk0C5C;
    int unk0C60;
    int unk0C64;
    int unk0C68;
    int unk0C6C;
    int unk0C70;
    int unk0C74;
    int unk0C78;
    int unk0C7C;
    int unk0C80;
    int unk0C84;
    int unk0C88;
    int unk0C8C;
    int unk0C90;
    int unk0C94;
    int unk0C98;
    int unk0C9C;
    int unk0CA0;
    int unk0CA4;
    int unk0CA8;
    int unk0CAC;
    int unk0CB0;
    int unk0CB4;
    int unk0CB8;
    int unk0CBC;
    int unk0CC0;
    int unk0CC4;
    int unk0CC8;
    int unk0CCC;
    int unk0CD0;
    int unk0CD4;
    int unk0CD8;
    int unk0CDC;
    int unk0CE0;
    int unk0CE4;
    int unk0CE8;
    int unk0CEC;
    int unk0CF0;
    int unk0CF4;
    int unk0CF8;
    int unk0CFC;
    int unk0D00;
    int unk0D04;
    int unk0D08;
    int unk0D0C;
    int unk0D10;
    int unk0D14;
    int unk0D18;
    int unk0D1C;
    int unk0D20;
    int unk0D24;
    int unk0D28;
    int unk0D2C;
    int unk0D30;
    int unk0D34;
    int unk0D38;
    int unk0D3C;
    int unk0D40;
    int unk0D44;
    int unk0D48;
    int unk0D4C;
    int unk0D50;
    int unk0D54;
    int unk0D58;
    int unk0D5C;
    int unk0D60;
    int unk0D64;
    int unk0D68;
    int unk0D6C;
    int unk0D70;
    int unk0D74;
    int unk0D78;
    int unk0D7C;
    int unk0D80;
    int unk0D84;
    int unk0D88;
    int unk0D8C;
    int unk0D90;
    int unk0D94;
    int unk0D98;
    int unk0D9C;
    int unk0DA0;
    int unk0DA4;
    int unk0DA8;
    int unk0DAC;
    int unk0DB0;
    int unk0DB4;
    int unk0DB8;
    int unk0DBC;
    int unk0DC0;
    int unk0DC4;
    int unk0DC8;
    int unk0DCC;
    int unk0DD0;
    int unk0DD4;
    int unk0DD8;
    int unk0DDC;
    int unk0DE0;
    int unk0DE4;
    int unk0DE8;
    int unk0DEC;
    int unk0DF0;
    int unk0DF4;
    int unk0DF8;
    int unk0DFC;
    int unk0E00;
    int unk0E04;
    int unk0E08;
    int unk0E0C;
    int unk0E10;
    int unk0E14;
    int unk0E18;
    int unk0E1C;
    int unk0E20;
    int unk0E24;
    int unk0E28;
    int unk0E2C;
    int unk0E30;
    int unk0E34;
    int unk0E38;
    int unk0E3C;
    int unk0E40;
    int unk0E44;
    int unk0E48;
    int unk0E4C;
    int unk0E50;
    int unk0E54;
    int unk0E58;
    int unk0E5C;
    int unk0E60;
    int unk0E64;
    int unk0E68;
    int unk0E6C;
    int unk0E70;
    int unk0E74;
    int unk0E78;
    int unk0E7C;
    int unk0E80;
    int unk0E84;
    int unk0E88;
    int unk0E8C;
    int unk0E90;
    int unk0E94;
    int unk0E98;
    int unk0E9C;
    int unk0EA0;
    int unk0EA4;
    int unk0EA8;
    int unk0EAC;
    int unk0EB0;
    int unk0EB4;
    int unk0EB8;
    int unk0EBC;
    int unk0EC0;
    int unk0EC4;
    int unk0EC8;
    int unk0ECC;
    int unk0ED0;
    int unk0ED4;
    int unk0ED8;
    int unk0EDC;
    int unk0EE0;
    int unk0EE4;
    int unk0EE8;
    int unk0EEC;
    int unk0EF0;
    int unk0EF4;
    int unk0EF8;
    int unk0EFC;
    int unk0F00;
    int unk0F04;
    int unk0F08;
    int unk0F0C;
    int unk0F10;
    int unk0F14;
    int unk0F18;
    int unk0F1C;
    int unk0F20;
    int unk0F24;
    int unk0F28;
    int unk0F2C;
    int unk0F30;
    int unk0F34;
    int unk0F38;
    int unk0F3C;
    int unk0F40;
    int unk0F44;
    int unk0F48;
    int unk0F4C;
    int unk0F50;
    int unk0F54;
    int unk0F58;
    int unk0F5C;
    int unk0F60;
    int unk0F64;
    int unk0F68;
    int unk0F6C;
    int unk0F70;
    int unk0F74;
    int unk0F78;
    int unk0F7C;
    int unk0F80;
    int unk0F84;
    int unk0F88;
    int unk0F8C;
    int unk0F90;
    int unk0F94;
    int unk0F98;
    int unk0F9C;
    int unk0FA0;
    int unk0FA4;
    int unk0FA8;
    int unk0FAC;
    int unk0FB0;
    int unk0FB4;
    int unk0FB8;
    int unk0FBC;
    int unk0FC0;
    int unk0FC4;
    int unk0FC8;
    int unk0FCC;
    int unk0FD0;
    int unk0FD4;
    int unk0FD8;
    int unk0FDC;
    int unk0FE0;
    int unk0FE4;
    int unk0FE8;
    int unk0FEC;
    int unk0FF0;
    int unk0FF4;
    int unk0FF8;
    int unk0FFC;
    int unk1000;
    int unk1004;
    int unk1008;
    int unk100C;
    int unk1010;
    int unk1014;
    int unk1018;
    int unk101C;
    int unk1020;
    int unk1024;
    int unk1028;
    int unk102C;
    int unk1030;
    int unk1034;
    int unk1038;
    int unk103C;
    int unk1040;
    int unk1044;
    int unk1048;
    int unk104C;
    int unk1050;
    int unk1054;
    int unk1058;
    int unk105C;
    int unk1060;
    int unk1064;
    int unk1068;
    int unk106C;
    int unk1070;
    int unk1074;
    int unk1078;
    int unk107C;
    int unk1080;
    int unk1084;
    int unk1088;
    int unk108C;
    int unk1090;
    int unk1094;
    int unk1098;
    int unk109C;
    int unk10A0;
    int unk10A4;
    int unk10A8;
    int unk10AC;
    int unk10B0;
    int unk10B4;
    int unk10B8;
    int unk10BC;
    int unk10C0;
    int unk10C4;
    int unk10C8;
    int unk10CC;
    int unk10D0;
    int unk10D4;
    int unk10D8;
    int unk10DC;
    int unk10E0;
    int unk10E4;
    int unk10E8;
    int unk10EC;
    int unk10F0;
    int unk10F4;
    E89B40Device* m_pkDevice;

    bool SetDeviceState(unsigned int uiA, unsigned int uiB, unsigned int uiC, unsigned int uiUnused);
};

// Calls m_pkDevice->SetState with uiA, uiB and uiC and returns whether the result is non-negative.
// @fnv 0x00e89b40
bool E89B40Renderer::SetDeviceState(unsigned int uiA, unsigned int uiB, unsigned int uiC, unsigned int uiUnused) {
    return m_pkDevice->SetState(uiA, uiB, uiC) >= 0;
}

extern int DAT_010efb7c;
extern int DAT_010a080c;

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct FUN_00e8a9e0_mgr {
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
    virtual void Call57(void* apObj);
};

struct FUN_00e8a9e0_child {
    virtual void v00();
    virtual void v04();
    virtual void __stdcall Release();
};

struct FUN_00e8a9e0_owner {
    int unk00;
};

struct FUN_00e8a9e0_cls {
    int m_vptr;
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
    FUN_00e8a9e0_owner* m_pSharedOwner;
    FUN_00e8a9e0_child* m_pChildObject;

    void BaseCleanup();
    FUN_00e8a9e0_cls* FUN_00e8a9e0(unsigned char acFlags);
};

// Releases the child object through the manager, resets the vtable, runs BaseCleanup and frees this (0x6c bytes) when acFlags bit 0 is set.
// @fnv 0x00e8a9e0
FUN_00e8a9e0_cls* FUN_00e8a9e0_cls::FUN_00e8a9e0(unsigned char acFlags)
{
    FUN_00e8a9e0_child* pChild = m_pChildObject;
    m_vptr = (int)&DAT_010efb7c;
    if (pChild != 0) {
        FUN_00e8a9e0_mgr* pMgr = *(FUN_00e8a9e0_mgr**)((char*)m_pSharedOwner + 0x8b8);
        pMgr->Call57(pChild);
        m_pChildObject->Release();
        m_pChildObject = 0;
    }
    m_vptr = (int)&DAT_010a080c;
    BaseCleanup();
    if (acFlags & 1) {
        FUN_00aa1460(this, 0x6c);
    }
    return this;
}

struct CubeMapSource {
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual int __stdcall GetSurfaceLevel(int a, unsigned int b, int* c);
};
struct CubeMapSurface {
    virtual void v00();
    virtual void v01();
    virtual void __stdcall Release();
};
extern "C" void __cdecl FUN_00e68150(int a, unsigned int b, int c, int d);
extern "C" void* __cdecl GetHResultName(int r);
extern "C" void __cdecl FUN_00a29680(const char* fmt, unsigned int i, void* s);
struct FUN_00e8aaf0_cls {
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
    void __thiscall FUN_00e8aaf0(int a1, int a2);
};
// Copies data to each cube map surface: gets the surface level, copies data into it, and releases it, logging on failure.
// @fnv 0x00e8aaf0
void FUN_00e8aaf0_cls::FUN_00e8aaf0(int pData, int iFace) {
    CubeMapSource* src = m_64;
    unsigned int i = 0;
    if (i < m_68) {
        int orig = iFace;
        do {
            int r = src->GetSurfaceLevel(orig, i, &iFace);
            if (r < 0) {
                FUN_00a29680("NiDX9SourceCubeMapData::CopyDataToSurface> Failed GetSurfaceLevel (%d)- %s", i, GetHResultName(r));
                return;
            }
            FUN_00e68150(pData, i, iFace, orig);
            reinterpret_cast<CubeMapSurface*>(iFace)->Release();
        } while (++i < m_68);
    }
}

namespace fnv_00e8ab70 {
struct CubeMapSource {
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual int __stdcall GetSurfaceLevel(int a, unsigned int b, int* c);
};
struct CubeMapSurface {
    virtual void v00();
    virtual void v01();
    virtual void __stdcall Release();
};
extern "C" void __cdecl FUN_00e683d0(int a, unsigned int b, int c, int d);
extern "C" void* __cdecl GetHResultName(int r);
extern "C" void __cdecl FUN_00a29680(const char* fmt, unsigned int i, void* s);
struct FUN_00e8ab70_cls {
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
    void __thiscall FUN_00e8ab70(int a1, int a2);
};
// Copies data into each surface level of the cube map source, releasing each surface and logging a failure if GetSurfaceLevel fails.
// @fnv 0x00e8ab70
void FUN_00e8ab70_cls::FUN_00e8ab70(int aiData, int a2) {
    CubeMapSource* src = m_64;
    unsigned int i = 0;
    if (i < m_68) {
        int orig = a2;
        do {
            int r = src->GetSurfaceLevel(orig, i, &a2);
            if (r < 0) {
                FUN_00a29680("NiDX9SourceCubeMapData::CopyDataToSurface> Failed GetSurfaceLevel (%d)- %s", i, GetHResultName(r));
                return;
            }
            FUN_00e683d0(aiData, i, a2, orig);
            reinterpret_cast<CubeMapSurface*>(a2)->Release();
        } while (++i < m_68);
    }
}
}  // namespace fnv_00e8ab70

class MobileTargetObj {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64();
    virtual void v68(int a, int b, int c, int d);
};

class FUN_00e8b170_cls {
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    MobileTargetObj* m_pFlagTarget;
    unsigned int unk24;
    unsigned int unk28;
    unsigned char unk2C;
    unsigned char unk2D;
    unsigned short unk2E;
    unsigned int unk30;
    unsigned int unk34;

    void FUN_00e8b170();
};

// @fnv 0x00e8b170
void FUN_00e8b170_cls::FUN_00e8b170()
{
    m_pFlagTarget->v68(0x8b, 0, 0, 0);
    m_pFlagTarget->v68(0x89, 0, 0, 0);
    unk30 = 0;
    unk2D = 0;
    unk34 = 0;
    m_pFlagTarget->v68(0x94, 0, 0, 0);
    m_pFlagTarget->v68(0x93, 0, 0, 0);
    m_pFlagTarget->v68(0x91, 0, 0, 0);
    unk28 = unk24;
    unk2C = 0;
}

class FUN_00e8b1f0_cls {
public:
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0C;
    unsigned int m_unk10;
    unsigned int m_unk14;
    unsigned int m_unk18;
    unsigned int m_unk1C;
    unsigned int m_unk20;
    unsigned int m_unk24;
    unsigned int m_unk28;
    unsigned int m_unk2C;
    unsigned int m_unk30;
    unsigned int m_unk34;
    unsigned int m_nextIndex;
    unsigned int m_bits[128];
    int AllocateBitIndex();
};

// Scans the 4096-bit set from m_nextIndex for a clear bit, sets it, advances m_nextIndex, and returns the bit index or -1 if all bits are set.
// @fnv 0x00e8b1f0
int FUN_00e8b1f0_cls::AllocateBitIndex()
{
    unsigned int start = m_nextIndex;
    unsigned int i = start;
    do {
        unsigned int shift = i & 31;
        unsigned int word = i >> 5;
        if ((m_bits[word] & (1u << shift)) == 0) {
            m_bits[word] |= 1u << shift;
            m_nextIndex = (i + 1) & 0xfff;
            return (int)i;
        }
        i++;
        if (i == 0x1000) {
            i = 0;
        }
    } while (i != start);
    return -1;
}

struct S_00e8b4b0_Class {
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
    unsigned char m_70;
    unsigned char m_71;

    void __thiscall UpdateFromSource(int value);
    S_00e8b4b0_Class* __thiscall Init(int value1, int value2);
};

// Initializes fields m_68, m_6c, m_70 and m_71, calls UpdateFromSource with value1, and returns this.
// @fnv 0x00e8b4b0
S_00e8b4b0_Class* __thiscall S_00e8b4b0_Class::Init(int value1, int value2) {
    m_68 = 0;
    m_6c = value2;
    m_70 = 0;
    m_71 = 0;
    UpdateFromSource(value1);
    return this;
}

struct Key {
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
 unsigned int unk68;
 unsigned int unk6c;
 unsigned int unk70;
 unsigned int unk74;
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
 unsigned int unkac;
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
 unsigned int mark;
};
struct Value {
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
 unsigned int unk68;
 unsigned int index;
};
struct Item { Item* next; Key* key; Value* value; };
struct PoolNode { PoolNode* next; PoolNode* prev; void* data; };
struct LockObj { unsigned int value; void Lock(char*); };
extern LockObj DAT_011c5f80;
extern unsigned int DAT_011c5f84;
extern PoolNode* DAT_011c5f58;
struct Com { virtual void __stdcall f0(); virtual void __stdcall f1(); virtual void __stdcall Release(); };
struct ListCleanup { void FUN_004ed900(); };
void _delete(void*,unsigned int);
struct Target {
 virtual void f0();
 virtual unsigned int Hash(Key*);
 unsigned int bucketCount;
 Item** buckets;
 unsigned int count;
 PoolNode* head;
 PoolNode* tail;
 unsigned int listCount;
 Com* object;
 unsigned int unk20,unk24,unk28,unk2c,unk30,unk34,unk38;
 unsigned int bits[8];
 void ClearBit(unsigned int index) { unsigned int word=index>>5; unsigned int mask=1<<(index&31); bits[word]&=~mask; }
 Item* FUN_00ee8ac0();
 void FUN_00e8b630();
};
// Empties the map: removes and deletes all items, returns pooled nodes, releases object, clears both base maps and frees the bucket array.
// @fnv 0x00e8b630
void Target::FUN_00e8b630() {
 while(count) {
  Item* node=FUN_00ee8ac0();
  Key* key=node->key;
  Value* value=node->value;
  if(!node->next) {
   unsigned int i=Hash(key)+1;
   while(i<bucketCount && !buckets[i]) ++i;
  }
  ((NiTMapBase*)this)->RemoveAt((const char*)key);
  key->mark=0;
  ClearBit(value->index);
  _delete(value,0x74);
 }
 while(listCount) {
  PoolNode* node=head;
  head=node->next;
  if(head) head->prev=0;
  else tail=0;
  node->data=0;
  DAT_011c5f80.Lock(0);
  node->prev=0;
  node->next=DAT_011c5f58;
  --DAT_011c5f84;
  DAT_011c5f58=node;
  if(!DAT_011c5f84) DAT_011c5f80.value=0;
  --listCount;
 }
 if(object) { object->Release(); object=0; }
 ((ListCleanup*)&head)->FUN_004ed900();
 *(void**)this=&DAT_010efdf8;
 ((NiTMapBaseStub*)this)->RemoveAll();
 *(void**)this=&DAT_010efdd8;
 ((NiTMapBaseStub*)this)->RemoveAll();
 NiFreeAlias(buckets);
}

extern int DAT_010efdd8;
extern int DAT_010efdf8;
extern "C" void* __cdecl FUN_00aa1070(unsigned int);
extern "C" void* __cdecl FUN_00ec61c0(void*, int, unsigned int);
struct Observer {
    virtual void __stdcall Slot0();
    virtual void __stdcall Slot1();
};
struct MapProcessor {
    int* vtable;
    unsigned int bucketCount;
    void* buckets;
    unsigned int itemCount;
    int field10;
    int field14;
    int field18;
    Observer* observer1c;
    void* volatile context20;
    int index24;
    int field28;
    int field2c;
    int field30;
    int field34;
    int field38;
    unsigned char data3c[512];
    void FUN_00e8b170();
    MapProcessor* FUN_00e8bae0(void* context, Observer* observer);
};
// @fnv 0x00e8bae0
MapProcessor* MapProcessor::FUN_00e8bae0(void* context, Observer* observer) {
    vtable = &DAT_010efdd8;
    bucketCount = 37;
    itemCount = 0;
    buckets = FUN_00aa1070(148);
    FUN_00ec61c0(buckets, 0, bucketCount * sizeof(void*));
    vtable = &DAT_010efdf8;
    field18 = 0;
    field10 = 0;
    field14 = 0;
    context20 = context;
    index24 = -1;
    observer1c = observer;
    observer->Slot1();
    field38 = 0;
    FUN_00ec61c0(data3c, 0, sizeof(data3c));
    FUN_00e8b170();
    return this;
}

namespace fnv_00e8bd40 {
struct Record;
struct Item { unsigned int unk00;
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
unsigned int unk68; unsigned int index; unsigned char unk70; unsigned char enabled; unsigned char unk72; unsigned char unk73; };
struct Record { unsigned int unk00;
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
unsigned int unk74;
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
unsigned int unkac;
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
unsigned int unke8; Item* active; };
struct Container { unsigned int data10; unsigned int data14; unsigned int data18; void __thiscall FUN_0057c730(Record** record); };
struct CallbackVTable { unsigned int unused00;
unsigned int unused04;
unsigned int unused08;
unsigned int unused0c;
unsigned int unused10;
unsigned int unused14;
unsigned int unused18;
unsigned int unused1c;
unsigned int unused20;
unsigned int unused24;
unsigned int unused28;
unsigned int unused2c;
unsigned int unused30;
unsigned int unused34;
unsigned int unused38;
unsigned int unused3c;
unsigned int unused40;
unsigned int unused44;
unsigned int unused48;
unsigned int unused4c;
unsigned int unused50;
unsigned int unused54;
unsigned int unused58;
unsigned int unused5c;
unsigned int unused60;
unsigned int unused64;
unsigned int unused68;
unsigned int unused6c;
unsigned int unused70;
unsigned int unused74;
unsigned int unused78;
unsigned int unused7c;
unsigned int unused80;
unsigned int unused84;
unsigned int unused88;
unsigned int unused8c;
unsigned int unused90;
unsigned int unused94;
unsigned int unused98;
unsigned int unused9c;
unsigned int unuseda0;
unsigned int unuseda4;
unsigned int unuseda8;
unsigned int unusedac;
unsigned int unusedb0;
unsigned int unusedb4;
unsigned int unusedb8;
unsigned int unusedbc;
unsigned int unusedc0;
unsigned int unusedc4;
unsigned int unusedc8;
unsigned int unusedcc;
unsigned int unusedd0; void (__stdcall *Notify)(void*, unsigned int, int); };
struct Callback { CallbackVTable* vtbl; };
extern "C" char __stdcall FUN_00a53c30(Record*, Item**);
extern "C" void __cdecl FUN_00aa1460(Item*, unsigned int);
struct Owner {
 unsigned int unk00;
unsigned int unk04;
unsigned int unk08;
unsigned int unk0c; Container list;
 Callback* callback;
 unsigned int unk20;
unsigned int unk24;
unsigned int unk28;
unsigned int unk2c;
unsigned int unk30;
unsigned int unk34;
unsigned int unk38;
 unsigned int flags[64];
 void __thiscall FUN_00e91fd0(Record* record);
 void __thiscall DeactivateActiveItem(Record* record);
};
// Clears the record's active item: notifies the callback, disables the item, removes it from the list, clears its flag bit and frees it.
// @fnv 0x00e8bd40
void Owner::DeactivateActiveItem(Record* record) {
 Record* original = record;
 Item* item = original->active;
 Item* lookup = item;
 if (item) {
   FUN_00a53c30(original, &lookup);
   callback->vtbl->Notify(callback, item->index, 0);
   item->enabled = 0;
   FUN_00e91fd0(original);
   lookup = reinterpret_cast<Item*>(original);
   list.FUN_0057c730(reinterpret_cast<Record**>(&lookup));
   original->active = 0;
   unsigned int index = item->index;
   unsigned int word = index >> 5;
   unsigned int position = index & 31;
   unsigned int mask = 1u << position;
   flags[word] &= ~mask;
   FUN_00aa1460(item, 0x74);
 } else if (FUN_00a53c30(original, &lookup)) {
   FUN_00e91fd0(original);
   Record* key = original;
   list.FUN_0057c730(&key);
   original->active = 0;
   unsigned int index = lookup->index;
   unsigned int word = index >> 5;
   unsigned int position = index & 31;
   unsigned int mask = 1u << position;
   flags[word] &= ~mask;
 }
}
}  // namespace fnv_00e8bd40

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* p);
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* cs);
void* __cdecl NiMemset(void* dst, int val, unsigned int size);
void* __cdecl NiMalloc(unsigned int size);

extern volatile long DAT_011f4400;

struct ComStub {
    virtual long __stdcall QueryInterface(void* riid, void** out);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

struct RefObjStub {
    unsigned int m_uiRefCount;
    RefObjStub() { m_uiRefCount = 0; InterlockedIncrement(&DAT_011f4400); }
    virtual void DeleteThis();
};

struct MapBaseStub {
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
    MapBaseStub(unsigned int hashSize)
    {
        m_uiHashSize = hashSize;
        m_uiCount = 0;
        unsigned int size = sizeof(void*) * m_uiHashSize;
        m_ppkHashTable = (void**)NiMalloc(size);
        NiMemset(m_ppkHashTable, 0, sizeof(void*) * m_uiHashSize);
    }
    virtual void MapV0();
    void RemoveAll();
};

struct MapStub : MapBaseStub {
    MapStub(unsigned int hashSize = 37) : MapBaseStub(hashSize) {}
    virtual void MapV1();
};

struct CritSecStub {
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
};

struct FUN_00e8d0e0 : RefObjStub {
    ComStub* m_pkDevice;
    MapStub m_kMap1;
    MapStub m_kMap2;
    MapStub m_kMap3;
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
    CritSecStub m_kCritSec;

    FUN_00e8d0e0(ComStub* device);
    virtual void DerivedV();
};

// Initializes the critical section, stores and AddRefs the device, clears the three maps and resets unk3c.
// @fnv 0x00e8d0e0
FUN_00e8d0e0::FUN_00e8d0e0(ComStub* device)
    : unk40(0), unk44(0), unk48(0), unk4c(0)
{
    InitializeCriticalSection(&m_kCritSec);
    m_pkDevice = device;
    device->AddRef();
    m_kMap1.RemoveAll();
    m_kMap2.RemoveAll();
    m_kMap3.RemoveAll();
    unk3c = 0;
}

extern "C" char* DAT_0109b220;
extern "C" void (__stdcall* DAT_00fdf1c0)(void*);
extern "C" void (__stdcall* DAT_00fdf1c4)(void*);

class FUN_00e8e330_cls {
public:
    char** m_00;
    unsigned int m_04;
    unsigned int m_08;

    void FUN_00e8e290(unsigned int newCap);
    void PushBack(char* const* src);
};

// Appends the pointer from src to the array, growing capacity when full and releasing the previous element's reference-counted block.
// @fnv 0x00e8e330
void FUN_00e8e330_cls::PushBack(char* const* src)
{
    if (m_08 == m_04) {
        FUN_00e8e290(m_04 > 0 ? m_04 * 2 : 1);
    }
    unsigned int idx = m_08;
    char** slot = &m_00[idx];
    m_08 = idx + 1;
    char* v = *src;
    if (*slot != v) {
        if (v != DAT_0109b220) {
            DAT_00fdf1c0(v - 8);
        }
        if (*slot != DAT_0109b220) {
            DAT_00fdf1c4(*slot - 8);
        }
        *slot = v;
    }
}

namespace fnv_00e8ead0 {
// Class layout of the object built by FUN_00e8ead0:
//   +0x00  vftable pointer of the NiRefObject-style base
//   +0x04  reference count
//   +0x08  four counters, all zeroed by the constructor
// The constructor installs the base vftable, bumps the global live-object
// counter and then installs the vftable of the derived class.

extern char DAT_0101dce4[];   // vftable of the base class
extern char DAT_010f0134[];   // vftable of the derived class
extern long DAT_011f4400[];   // global live object counter

extern "C" void __cdecl _ReadWriteBarrier(void);

class FUN_00e8ead0
{
public:
    char* m_pVftable;
    int m_iRefCount;
    int m_iA;
    int m_iB;
    int m_iC;
    int m_iD;
    FUN_00e8ead0();
};

// Sets the vftable, zeroes the ref count and four int members, and increments a global counter.
// @fnv 0x00e8ead0
FUN_00e8ead0::FUN_00e8ead0()
{
    m_pVftable = DAT_0101dce4;
    m_iRefCount = 0;
    InterlockedIncrement(&DAT_011f4400[0]);
    m_pVftable = DAT_010f0134;
    _ReadWriteBarrier();
    m_iA = 0;
    m_iB = 0;
    m_iC = 0;
    m_iD = 0;
}
}  // namespace fnv_00e8ead0

namespace fnv_00e8f7c0 {
// Candidate: FUN_00e8f7c0 — release/destructor-like routine for a render-object class.
// Stores the class vtable, calls two module-level helpers, and optionally
// unregisters the object from the global registry object at DAT_011f6238.

extern unsigned char DAT_010f02b0[];

struct FUN_00aa4060_Class {
    void __thiscall FUN_00aa4060(void* object);
};

extern FUN_00aa4060_Class DAT_011f6238;

void __cdecl FUN_00b601a0();
void __cdecl FUN_00aa10f0(void* data);

struct FUN_00e8f7c0_Class {
    void* m_vptr;
    char m_auiShapeKeys[4];
    void* m_data;

    void* FUN_00e8f7c0(unsigned char deleting);
};

// @fnv 0x00e8f7c0
void* FUN_00e8f7c0_Class::FUN_00e8f7c0(unsigned char deleting)
{
    m_vptr = (void*)&DAT_010f02b0;
    FUN_00b601a0();
    FUN_00aa10f0(m_data);
    if (deleting & 1) {
        DAT_011f6238.FUN_00aa4060(this);
    }
    return this;
}
}  // namespace fnv_00e8f7c0

struct ListNode_b5254 {
    ListNode_b5254* m_00;
    ListNode_b5254* m_04;
    unsigned int m_08;
};

struct NodePool_b5254 {
    unsigned int m_00;
    ListNode_b5254* Alloc();
};

extern "C" ListNode_b5254* DAT_0126f0f8;
extern "C" ListNode_b5254* DAT_0126f0fc;
extern "C" NodePool_b5254 DAT_0126f100;

static inline unsigned int& NextKey_b5254(ListNode_b5254*& pos) {
    unsigned int& e = pos->m_08;
    pos = pos->m_00;
    return e;
}

// Searches the linked list for key; if absent, allocates a node, sets its key and links it at the tail (or as head when the list is empty).
// @fnv 0x00e91d50
void AddKeyToList(unsigned int key) {
    ListNode_b5254* cur = DAT_0126f0f8;
    ListNode_b5254* pFound = 0;
    if (cur != 0) {
        do {
            ListNode_b5254* node = cur;
            if (key == NextKey_b5254(cur)) {
                pFound = node;
                break;
            }
        } while (cur != 0);
    }
    if (pFound == 0) {
        ListNode_b5254* n = DAT_0126f100.Alloc();
        n->m_08 = key;
        n->m_00 = 0;
        n->m_04 = DAT_0126f0fc;
        if (DAT_0126f0fc != 0) {
            DAT_0126f0fc->m_00 = n;
            DAT_0126f100.m_00 += 1;
            DAT_0126f0fc = n;
        } else {
            DAT_0126f100.m_00 += 1;
            DAT_0126f0f8 = n;
            DAT_0126f0fc = n;
        }
    }
}

struct FUN_00e940a0_Global {
    int unk_00;
    int unk_04;
    int unk_08;
    int unk_0c;
    int unk_10;
    int unk_14;
    int unk_18;
    int unk_1c;
    int unk_20;
    int unk_24;
    int unk_28;
    int unk_2c;
    int unk_30;
    int unk_34;
    int unk_38;
    int unk_3c;
    int unk_40;
    int unk_44;
    void* unk_48;
};

extern FUN_00e940a0_Global* DAT_011f4a64;

struct FUN_00e940a0_Class {
    void* m_00;
    void __thiscall ReleaseGlobalSlot();
};

extern "C" void __cdecl operator delete(void* p, unsigned int size);

// If the global object exists and holds a pointer in unk_48, clears that slot, nulls m_00 when it matches, and deletes the pointer.
// @fnv 0x00e940a0
void __thiscall FUN_00e940a0_Class::ReleaseGlobalSlot() {
    if (DAT_011f4a64 != 0) {
        void* p = DAT_011f4a64->unk_48;
        if (p != 0) {
            DAT_011f4a64->unk_48 = 0;
            if (p == m_00) {
                m_00 = 0;
            }
            operator delete(p, 0x48);
        }
    }
}

struct FUN_00e94150_Node {
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
    FUN_00e94150_Node* m_3c;
    FUN_00e94150_Node* m_40;
};

struct FUN_00e94150_Class {
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
    FUN_00e94150_Node* m_2c;

    void __thiscall RemoveNode(FUN_00e94150_Node* node);
};

// Searches the linked list starting at m_2c for node, unlinks it by patching its neighbours' m_3c/m_40 links, and updates m_2c if it was the head.
// @fnv 0x00e94150
void __thiscall FUN_00e94150_Class::RemoveNode(FUN_00e94150_Node* node)
{
    FUN_00e94150_Node* current = m_2c;

    if (current) {
        while (current) {
            if (current == node) {
                break;
            }

            current = current->m_3c;
            if (!current) {
                return;
            }
        }

        if (current->m_3c) {
            current->m_3c->m_40 = current->m_40;
        }

        if (current->m_40) {
            current->m_40->m_3c = current->m_3c;
        }

        if (current == m_2c) {
            m_2c = current->m_3c;
        }
    }
}

namespace fnv_00e94810 {
extern int DAT_010c4cf8;
void __cdecl FUN_00aa10f0(int aValue);

struct FUN_00e94810_pool {
    void FUN_00aa4060(void* apMemory);
};
extern FUN_00e94810_pool DAT_011f6238;

struct FUN_00e94810_cls {
    int m_vptr;
    int m_04;
    int m_08;

    void BaseCleanup();

    FUN_00e94810_cls* FUN_00e94810(unsigned int acFlags);
};

// @fnv 0x00e94810
FUN_00e94810_cls* FUN_00e94810_cls::FUN_00e94810(unsigned int acFlags)
{
    m_vptr = (int)&DAT_010c4cf8;
    BaseCleanup();
    FUN_00aa10f0(m_08);
    if (acFlags & 1) {
        DAT_011f6238.FUN_00aa4060(this);
    }
    return this;
}
}  // namespace fnv_00e94810

class FUN_00e95b60_cls {
public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    FUN_00e95b60_cls* Reset();
};

// @fnv 0x00e95b60
FUN_00e95b60_cls* FUN_00e95b60_cls::Reset() {
    m_00 = -1;
    m_04 = 0xffff;
    m_08 = 0;
    m_10 = 0;
    return this;
}

struct S_00e97790_This {
    void __thiscall FUN_00e98910(void* p);
};


// @fnv 0x00e97790
int FUN_00e97790_Class::InitFromSource(int a, int apSource)
{
    S_00e97790_This* pThis =
        reinterpret_cast<S_00e97790_This*>(this);

    int* pObject =
        reinterpret_cast<int*>(this);
    unsigned char* pFieldBytes =
        reinterpret_cast<unsigned char*>(this);
    unsigned char* pFirst =
        reinterpret_cast<unsigned char*>(a);
    int* pSourceFields =
        reinterpret_cast<int*>(apSource);

    int zero = 0;
    int sixteen = zero + 0x10;

    pThis->FUN_00e98910(reinterpret_cast<void*>(a));

    *reinterpret_cast<int*>(this) =
        reinterpret_cast<int>(&DAT_010f1550);

    pObject[0x28 / 4] = pSourceFields[0xc8 / 4];

    int mode =
        *reinterpret_cast<unsigned char*>(apSource + 0xc5);

    if (mode == 1) {
        pObject[0x78 / 4] = zero;
        pObject[0x50 / 4] = zero;
    } else if (mode == 2) {
        int value = pSourceFields[0xfc / 4];
        value = value ? -1 : 0;
        value &= sixteen;
        pObject[0x7c / 4] = value;
        pObject[0x50 / 4] = sixteen;
    } else if (mode == 3) {
        pObject[0x78 / 4] = sixteen;
        pObject[0x50 / 4] = sixteen;
    }

    if (pObject[0x28 / 4] == zero &&
        *reinterpret_cast<unsigned char*>(a + 0x5d4) != 0) {
        pFieldBytes[0x88] = 1;
        pObject[0x28 / 4] = 0x2000;
    } else {
        pFieldBytes[0x88] = 0;
    }

    mode =
        *reinterpret_cast<unsigned char*>(apSource + 0xcd);

    if (mode == 1) {
        pObject[0x2c / 4] = 8;
        pObject[0x7c / 4] = zero;
        pObject[0x54 / 4] = zero;
        return reinterpret_cast<int>(this);
    }

    if (mode == 2) {
        pObject[0x2c / 4] = 0x20;

        pObject[0x7c / 4] =
            (pSourceFields[0x10c / 4] ? -1 : 0) & sixteen;

        pObject[0x54 / 4] = sixteen;
        return reinterpret_cast<int>(this);
    }

    if (mode == 3) {
        pObject[0x2c / 4] = 0xe0;
        pObject[0x7c / 4] = sixteen;
        pObject[0x54 / 4] = sixteen;
    }

    return reinterpret_cast<int>(this);
}

struct FUN_00e984d0_Struct {
    int unk00;
    int unk04;
    int unk08;
    int (__cdecl *unk0c)(FUN_00e984d0_Struct*, int, int, int*, int);
};

// @fnv 0x00e984d0
void __cdecl FUN_00e984d0(FUN_00e984d0_Struct* pStruct, int aiArg1, int aiArg2)
{
    int local = 1;
    pStruct->unk04 += pStruct->unk0c(pStruct, aiArg1, aiArg2, &local, 1);
}

struct FnvCpu_FUN_00e98e10_CpuTarget { void FUN_00e98cb0(); };
struct FnvCpu_FUN_00e98e10_CpuOwner {
    void FUN_00e98e10();
};
// @fnv 0x00e98e10
void FnvCpu_FUN_00e98e10_CpuOwner::FUN_00e98e10()
{
    reinterpret_cast<FnvCpu_FUN_00e98e10_CpuTarget*>(reinterpret_cast<char*>(this) + (24))->FUN_00e98cb0();
}

typedef bool (__cdecl *FNV_CondFn_e9c8c0)(float, void*, unsigned int, void*, unsigned int);

class FUN_00e9c8c0_obj {
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual unsigned int GetIndex();
};

extern FNV_CondFn_e9c8c0* DAT_0126fa94;

// Looks up a function pointer in DAT_0126fa94 indexed by the two objects' indices and calls it, swapping the argument pairs if the first lookup is null.
// @fnv 0x00e9c8c0
bool __cdecl CallConditionFunction(float afValue, FUN_00e9c8c0_obj* apFirst, unsigned int auiFirstArg, FUN_00e9c8c0_obj* apSecond, unsigned int auiSecondArg)
{
    unsigned int uiFirstIndex = apFirst->GetIndex() * 6;
    unsigned int uiSecondIndex = apSecond->GetIndex();
    FNV_CondFn_e9c8c0 fn = DAT_0126fa94[uiFirstIndex + uiSecondIndex];
    if (fn != 0) {
        return fn(afValue, apFirst, auiFirstArg, apSecond, auiSecondArg);
    }
    unsigned int uiSwappedIndex = apSecond->GetIndex() * 6;
    unsigned int uiSwappedSecondIndex = apFirst->GetIndex();
    fn = DAT_0126fa94[uiSwappedIndex + uiSwappedSecondIndex];
    return fn(afValue, apSecond, auiSecondArg, apFirst, auiFirstArg);
}

typedef int (__cdecl *FUN_00e9c950_handler)(float, void*, int, void*, int, int, int, int, int, int);

extern FUN_00e9c950_handler* DAT_0126fa98;

class FUN_00e9c950_cls_key
{
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual int Slot3();
};

// Looks up a handler in DAT_0126fa98 by the two objects' Slot3 values and calls it, swapping the object and argument order for the fallback lookup.
// @fnv 0x00e9c950
int DispatchPairHandler(float afValue, FUN_00e9c950_cls_key* pFirst, int aiFirstArg, FUN_00e9c950_cls_key* pSecond, int aiSecondArg, int aiArg6, int aiArg7, int aiArg8, int aiArg9, int aiArg10)
{
    int iFirstKey = pFirst->Slot3() * 3;
    iFirstKey = iFirstKey + iFirstKey;
    int idx = pSecond->Slot3() + iFirstKey;
    FUN_00e9c950_handler fn = DAT_0126fa98[idx];
    if (fn != 0) {
        return fn(afValue, pFirst, aiFirstArg, pSecond, aiSecondArg, aiArg6, aiArg7, aiArg8, aiArg9, aiArg10);
    }
    int s = pSecond->Slot3() * 3;
    s = s + s;
    int iSwappedHandlerIndex = pFirst->Slot3() + s;
    FUN_00e9c950_handler pSwappedHandler = DAT_0126fa98[iSwappedHandlerIndex];
    return pSwappedHandler(afValue, pSecond, aiSecondArg, pFirst, aiFirstArg, aiArg6, aiArg7, aiArg8, aiArg10, aiArg9);
}

struct DispatchObj_b4010 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

typedef void (__cdecl *DispatchFn_b4010)(float, DispatchObj_b4010*, int, int, int, int, int);

extern DispatchFn_b4010* DAT_0126fa9c;

// Looks up a dispatch function from DAT_0126fa9c using the object's virtual index and calls it with the forwarded arguments.
// @fnv 0x00e9ca10
void __cdecl DispatchByVirtualIndex(float afValue, DispatchObj_b4010* apObj, int aiArg2, int aiArg3, int aiArg4, int aiArg5, int aiArg6)
{
    DispatchFn_b4010 fn = DAT_0126fa9c[apObj->v3()];
    fn(afValue, apObj, aiArg2, aiArg3, aiArg4, aiArg5, aiArg6);
}

struct FUN_00e9e840_Class
{
    virtual int m_virtual00(int value);
    virtual int m_virtual01(int value);
    virtual int m_virtual02(int value);
    virtual int m_virtual03(int value);
    virtual int m_virtual04(int value);
    virtual int m_virtual05(int value);
    virtual int m_virtual06(int value);
    virtual int m_virtual07(int value);
    virtual bool m_virtual08(int value);
    virtual bool m_virtual09(int value);

    bool __thiscall FUN_00e9e840(int value);
};

// @fnv 0x00e9e840
inline int FUN_00e9e840_Class::m_virtual00(int value)
{
    return value;
}

inline int FUN_00e9e840_Class::m_virtual01(int value)
{
    return value;
}

inline int FUN_00e9e840_Class::m_virtual02(int value)
{
    return value;
}

inline int FUN_00e9e840_Class::m_virtual03(int value)
{
    return value;
}

inline int FUN_00e9e840_Class::m_virtual04(int value)
{
    return value;
}

inline int FUN_00e9e840_Class::m_virtual05(int value)
{
    return value;
}

inline int FUN_00e9e840_Class::m_virtual06(int value)
{
    return value;
}

inline int FUN_00e9e840_Class::m_virtual07(int value)
{
    return value;
}

inline bool FUN_00e9e840_Class::m_virtual08(int value)
{
    return value != 0;
}

inline bool FUN_00e9e840_Class::m_virtual09(int value)
{
    return value != 0;
}

bool FUN_00e9e840_Class::FUN_00e9e840(int value)
{
    return !m_virtual09(value);
}

struct ItemArrayOwner {
    unsigned int unk00;
    unsigned int unk04;
    void** pItems;
    unsigned short unk0C;
    unsigned short count;
    unsigned int unk10;
    unsigned int foundIndex;
};

bool __cdecl CallConditionFunction(float a1, void* a2, unsigned int a3, void* a4, unsigned int a5);

// Searches a2's items against a4's items with CallConditionFunction and, on a match, stores both indices in foundIndex and returns true.
// @fnv 0x00e9e9e0
bool __cdecl FindMatchingItemPair(float afValue, ItemArrayOwner* apOwnerA, unsigned int a3, ItemArrayOwner* apOwnerB, unsigned int a5)
{
    for (unsigned int i = 0; i < apOwnerA->count; i++) {
        void* item = apOwnerA->pItems[i];
        for (unsigned int j = 0; j < apOwnerB->count; j++) {
            void* other = apOwnerB->pItems[j];
            if (CallConditionFunction(afValue, item, a3, other, a5)) {
                apOwnerA->foundIndex = i;
                apOwnerB->foundIndex = j;
                return true;
            }
        }
    }
    return false;
}

struct FNVItemHolder {
    int m_00;
    int m_04;
    void** m_08;
    unsigned short m_0c;
    unsigned short m_0e;
    int m_10;
    int m_14;
};

bool __cdecl DispatchPairHandler(float f, void* item, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);

// Iterates holder->m_08 up to holder->m_0e, calls DispatchPairHandler on each item, stores the matching index in holder->m_14 and returns true, else false.
// @fnv 0x00e9eae0
bool __cdecl FindItemByPredicate(float f, FNVItemHolder* holder, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
    for (unsigned int i = 0; i < holder->m_0e; ++i) {
        void* item = holder->m_08[i];
        if (DispatchPairHandler(f, item, a2, a3, a4, a5, a6, a7, a8, a9)) {
            holder->m_14 = i;
            return true;
        }
    }
    return false;
}

// Candidate for FindMatchingPair (167 bytes)
//
// Searches two fixed-size index tables for a pair of entries that satisfy a
// comparison predicate.  On success the index of the outer table entry and of
// the inner table entry are stored back into the two table descriptors and the
// function reports true; otherwise it reports false.
struct E9EB60_Item
{
    int unk00;
    int unk04;
    void** m_ppData;
    unsigned short unk0c;
    unsigned short m_uiItemCount;
    int unk10;
    int m_result;
};

extern "C" bool __cdecl E9C950_probe(float a0, void* a1, int a2, void* a3,
                                     int a4, int a5, int a6, int a7, int a8, int a9);

// Scans every pair of entries from two item lists through E9C950_probe and, on the first match, stores both indices in m_result and returns true.
// @fnv 0x00e9eb60
bool __cdecl FindMatchingPair(float a0, E9EB60_Item* a1, int a2, E9EB60_Item* pListB,
                          int a4, int a5, int a6, int a7, int a8, int a9)
{
    for (unsigned int i = 0; i < a1->m_uiItemCount; i++) {
        void* a = a1->m_ppData[i];
        for (unsigned int j = 0; j < pListB->m_uiItemCount; j++) {
            void* b = pListB->m_ppData[j];
            if (E9C950_probe(a0, a, a2, b, a4, a5, a6, a7, a8, a9)) {
                a1->m_result = i;
                pListB->m_result = j;
                return true;
            }
        }
    }
    return false;
}

struct FogProperty {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned short flags;
    float depth;
    float red, green, blue;
};

static int to_int(float f) { float t = f; return *(int*)&t; }

struct Cls00e87c50 {
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
    virtual int v1a(int a, unsigned int b, int c, int d);

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
    unsigned int unk74;
    unsigned int unk78;
    float unk7c;
    float unk80;
    float unk84;
    unsigned int unk88;
    float unk8c;
    float unk90;
    float unk94;
    unsigned int unk98;
    void ApplyFogProperty(const FogProperty* arg);
};

// Applies a FogProperty to the fog settings: toggles fog, computes depth-based start/end/scale, sets fog mode and color, and pushes values via v1a.
// @fnv 0x00e87c50
void Cls00e87c50::ApplyFogProperty(const FogProperty* apFogProperty) {
    if (apFogProperty->flags & 1) {
        this->v1a(0x1c, 1, 0, 0);
    } else {
        this->v1a(0x1c, 0, 0, 0);
        return;
    }

    float fDepthScale = unk80 * apFogProperty->depth;
    float start = unk7c - fDepthScale;
    float s14 = unk84 * fDepthScale + unk7c;
    float s1c = 1.0f / fDepthScale;

    this->v1a(0x26, *(int*)&s1c, 0, 0);
    this->v1a(0x24, to_int(start), 0, 0);
    this->v1a(0x25, to_int(s14), 0, 0);

    if (((apFogProperty->flags >> 1) & 3) == 0) {
        if (unk08 & 1) {
            this->v1a(0x23, 3, 0, 0);
            this->v1a(0x8c, 0, 0, 0);
        }
        this->v1a(0x30, 0, 0, 0);
    } else if (((apFogProperty->flags >> 1) & 3) == 1) {
        if (unk08 & 1) {
            this->v1a(0x23, 0, 0, 0);
            this->v1a(0x8c, 3, 0, 0);
        }
        this->v1a(0x30, 1, 0, 0);
    } else {
        this->v1a(0x1c, 0, 0, 0);
    }

    if (apFogProperty->red != unk8c ||
        apFogProperty->green != unk90 ||
        apFogProperty->blue != unk94) {
        int iPackedColor = (unsigned char)(unsigned int)(apFogProperty->red * 255.0);
        iPackedColor = (iPackedColor & 0xFF) | 0xFFFFFF00;
        iPackedColor <<= 8;
        iPackedColor |= (unsigned char)((int)(unsigned int)(apFogProperty->green * 255.0));
        iPackedColor <<= 8;
        iPackedColor |= (unsigned char)((int)(unsigned int)(apFogProperty->blue * 255.0));
        unk98 = iPackedColor;
        *(int*)&unk8c = *(const int*)&apFogProperty->red;
        *(int*)&unk90 = *(const int*)&apFogProperty->green;
        *(int*)&unk94 = *(const int*)&apFogProperty->blue;
    }

    this->v1a(0x22, unk98, 0, 0);
}

// Grow the object pool: allocate a block of N entries and push every entry onto the free set.

class E94B0MemoryManager {
public:
    void* Allocate(unsigned int uiSize);
};
extern E94B0MemoryManager g_kE94B0MemoryManager;

struct E94B0Entry {
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
};

E94B0Entry* __cdecl E94B0AllocEntries(unsigned int ItemUpdateArray) throw();

struct E94B0Block {
    E94B0Block(unsigned int ItemUpdateArray) throw() : m_uiCount(ItemUpdateArray), m_pkNext(0)
    {
        if (ItemUpdateArray > 0)
            m_pkEntryArray = E94B0AllocEntries(ItemUpdateArray);
        else
            m_pkEntryArray = 0;
    }

    static void* operator new(unsigned int uiSize) { return g_kE94B0MemoryManager.Allocate(uiSize); }

    E94B0Entry* GetAt(unsigned int uiIndex)
    {
        if (uiIndex >= m_uiCount)
            return 0;
        return &m_pkEntryArray[uiIndex];
    }

    E94B0Entry* m_pkEntryArray;
    unsigned int m_uiCount;
    E94B0Block* m_pkNext;
};

class E94B0Pool {
public:
    E94B0Entry** m_ppkFree;
    unsigned int m_uiAllocated;
    unsigned int m_uiFree;
    E94B0Block* m_pkBlocks;

    void Realloc(unsigned int uiNewSize);

    void AddFree(E94B0Entry* pkEntry)
    {
        if (m_uiFree == m_uiAllocated)
            Realloc(m_uiAllocated > 0 ? 2 * m_uiAllocated : 1);
        m_ppkFree[m_uiFree] = pkEntry;
        m_uiFree++;
    }

    void AddBlock(unsigned int ItemUpdateArray);
};

// Allocates a new block of the given size, adds each entry to the free list, and links the block at the head of m_pkBlocks.
// @fnv 0x00e894b0
void E94B0Pool::AddBlock(unsigned int ItemUpdateArray)
{
    E94B0Block* pkBlock = new E94B0Block(ItemUpdateArray);
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        AddFree(pkBlock->GetAt(i));
    pkBlock->m_pkNext = m_pkBlocks;
    m_pkBlocks = pkBlock;
}

struct PoolItemStub {
    bool m_bIsCubeMap;
};

struct GlobalPoolStub {
    PoolItemStub** m_apFree;
    unsigned int m_unk04;
    int m_numFree;
    unsigned int m_unk0c;
    unsigned int m_growBy;
    unsigned int m_unk14;
    void __thiscall Grow(unsigned int growBy);
};

// Pops a free item from the global pool, growing it when empty, marks the item as used, and returns it.
// @fnv 0x00e89630
PoolItemStub* __cdecl AllocatePoolItem()
{
    GlobalPoolStub* pool = (GlobalPoolStub*)DAT_0126f9a0;
    int* numFree = &((GlobalPoolStub*)DAT_0126f9a0)->m_numFree;
    if (((GlobalPoolStub*)DAT_0126f9a0)->m_numFree == 0) {
        unsigned int* growBy = &((GlobalPoolStub*)DAT_0126f9a0)->m_growBy;
        ((GlobalPoolStub*)DAT_0126f9a0)->Grow(*growBy);
        *growBy = *growBy * 2;
    }
    PoolItemStub** list = pool->m_apFree;
    PoolItemStub* item = list[0];
    (*numFree)--;
    list[0] = list[*numFree];
    if (!item->m_bIsCubeMap) {
        item->m_bIsCubeMap = true;
    }
    return item;
}

extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
extern float DAT_0126f9c4;
struct Vec3 { float x,y,z; };
struct Matrix { Vec3 a,b,c; };
struct LightSource {
float f00;
float f04;
float f08;
float f0c;
float f10;
float f14;
float f18;
float f1c;
float f20;
float f24;
float f28;
float f2c;
float f30;
float f34;
float f38;
float f3c;
float f40;
float f44;
float f48;
float f4c;
float f50;
float f54;
float f58;
float f5c;
float f60;
float f64;
float f68;
float f6c;
float f70;
float f74;
float f78;
float f7c;
float f80;
float f84;
float f88;
float f8c;
float f90;
float f94;
float f98;
unsigned char unk9c; unsigned char kind; unsigned char unk9e; unsigned char unk9f;
float fa0;
float fa4;
int fa8;
float fac;
float fb0;
float fb4;
float fb8;
float fbc;
float fc0;
float fc4;
Matrix matrix;
float fec;
float ff0;
float ff4;
float ff8;
float ffc;
float f100;
float f104;
float f108;
float f10c;
float f110;
};
struct LightState {
int f00;
float f04;
float f08;
float f0c;
float f10;
float f14;
float f18;
float f1c;
float f20;
float f24;
float f28;
float f2c;
float f30;
float f34;
float f38;
float f3c;
float f40;
float f44;
float f48;
float f4c;
float f50;
float f54;
float f58;
float f5c;
float f60;
float f64;
int f68;
bool UpdateFromSource(LightSource* source);
};
// Rebuilds the light state from source when its fa8 value changes: clears the state, fills fields by source->kind, and stores the scaled source matrix.
// @fnv 0x00e8b250
bool LightState::UpdateFromSource(LightSource* source) {
if (f68 != source->fa8) {
f68 = source->fa8;
fnv_zlib_memset(this, 0, 0x68);
switch (source->kind) {
case 4:
f00=2; f34=source->f8c; f38=source->f90; f3c=source->f94;
f40=source->ffc; f44=source->f100; f48=source->f104;
f60=0; f64=(source->f108 * 3.1415927410125732421875) / 90.0;
f50=source->f110;
goto color;
case 3:
f00=3; f40=source->ff0; f44=source->ff4; f48=source->ff8;
break;
case 2:
f00=1; f34=source->f8c; f38=source->f90; f3c=source->f94;
color:
f54=source->ff0; f58=source->ff4; f5c=source->ff8; f4c=DAT_0126f9c4;
break;
}
float scale=source->fc4;
Matrix matScaled; matScaled.a=source->matrix.a; matScaled.b=source->matrix.b; matScaled.c=source->matrix.c;
matScaled.a.x *= scale;
matScaled.a.y *= scale;
matScaled.a.z *= scale;
matScaled.b.x *= scale;
matScaled.b.y *= scale;
matScaled.b.z *= scale;
matScaled.c.x *= scale;
matScaled.c.y *= scale;
matScaled.c.z *= scale;
f24=matScaled.a.x;
f28=matScaled.a.y;
f2c=matScaled.a.z; f30=1.0f;
f04=matScaled.b.x;
f08=matScaled.b.y;
f0c=matScaled.b.z; f10=1.0f;
f14=matScaled.c.x;
f18=matScaled.c.y;
f1c=matScaled.c.z;
f20=1.0f; return true;
} return false;
}

extern "C" void __cdecl FUN_00aa10f0(void* p);
extern int DAT_010f0ef0;

struct FUN_00e93540_Node {
    FUN_00e93540_Node* next;
    void* data;
};

struct FUN_00e93540_Map : public NiTMapBaseStub {
    unsigned int m_vptr;
    unsigned int m_uiItemCount;
    FUN_00e93540_Node** m_buckets;
    unsigned int unk0c;
    unsigned char m_ownsData;

    void __thiscall FUN_00e93540();
};

// Sets the vtable, frees each stored data pointer when m_ownsData is set, then clears the map and frees the bucket array.
// @fnv 0x00e93540
void FUN_00e93540_Map::FUN_00e93540() {
    m_vptr = (unsigned int)&DAT_010f0ef0;

    if (m_ownsData) {
        for (unsigned int index = 0; index < m_uiItemCount; ++index) {
            FUN_00e93540_Node* node = m_buckets[index];
            while (node) {
                FUN_00e93540_Node* current = node;
                node = node->next;
                FUN_00aa10f0(current->data);
            }
        }
    }

    m_vptr = (unsigned int)&DAT_010f0ed0;
    RemoveAll();

    m_vptr = (unsigned int)&DAT_010f0eb0;
    RemoveAll();

    FUN_00aa10f0(m_buckets);
}

struct FUN_00e89740_Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;

    void Cleanup();
};
// @fnv 0x00e89740
void FUN_00e89740()
{
    FUN_00e89740_Obj* p = (FUN_00e89740_Obj*)DAT_0126f9a0;
    if (DAT_0126f9a0) {
        ((FUN_00e89740_Obj*)DAT_0126f9a0)->Cleanup();
        _g_memoryManager.Deallocate(p);
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plValue);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plValue);

extern char* DAT_0109b220;

struct StringTable {
    static void IncRefCount(char* pcHandle)
    {
        if (pcHandle != DAT_0109b220)
            InterlockedIncrement((long volatile*)(pcHandle - 8));
    }
    static void DecRefCount(char* pcHandle)
    {
        if (pcHandle != DAT_0109b220)
            InterlockedDecrement((long volatile*)(pcHandle - 8));
    }
};

class FixedStr {
public:
    FixedStr& operator=(const FixedStr& kString)
    {
        if (m_kHandle != kString.m_kHandle) {
            char* pcHandle = kString.m_kHandle;
            StringTable::IncRefCount(pcHandle);
            StringTable::DecRefCount(m_kHandle);
            m_kHandle = pcHandle;
        }
        return *this;
    }
    char* m_kHandle;
};

FixedStr* FUN_00a63ae0(unsigned int ItemUpdateArray);   // array new
void FUN_00a644a0(FixedStr* pkArray);           // array delete

class FixedStrArray {
public:
    void FUN_00e8e290(unsigned int uiMaxSize);

    FixedStr* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
};

// Reallocates the string array to uiMaxSize, copies existing elements into the new buffer, frees the old buffer and updates m_pBase and m_uiMaxSize.
// @fnv 0x00e8e290
void FixedStrArray::FUN_00e8e290(unsigned int uiNewMaxSize)
{
    if (uiNewMaxSize == m_uiMaxSize)
        return;
    FixedStr* pkNew;
    if (uiNewMaxSize > 0) {
        pkNew = FUN_00a63ae0(uiNewMaxSize);
        for (unsigned int i = 0; i < m_uiSize; i++)
            pkNew[i] = m_pBase[i];
    } else {
        pkNew = 0;
    }
    FUN_00a644a0(m_pBase);
    m_pBase = pkNew;
    m_uiMaxSize = uiNewMaxSize;
}

struct Ref_e98cb0 {
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
};
struct Ptr_e98cb0 {
    Ref_e98cb0* m_p;
    void Release() { Ref_e98cb0* r = m_p; if (r && InterlockedDecrement(&r->m_uiRefCount) == 0) r->DeleteThis(); }
    void Clear() {
        Ref_e98cb0* r = m_p;
        if (r) {
            if (InterlockedDecrement(&r->m_uiRefCount) == 0) r->DeleteThis();
            m_p = 0;
        }
    }
};
struct Pair_e98cb0 {
    Ptr_e98cb0 first;
    Ptr_e98cb0 second;
};
struct E98CB0Arr {
    int vtbl;
    Pair_e98cb0** m_pBase;
    unsigned short m_usMax;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short pad;
    int unk10;
    void FUN_00e98cb0(bool bFree);
};
// Resets unk10 to 0 and, when bFree is set, releases both pointers of every pair, nulls the base entries and clears the size counters.
// @fnv 0x00e98cb0
void E98CB0Arr::FUN_00e98cb0(bool bFree)
{
    unk10 = 0;
    if (bFree) {
        for (int i = 0; i < m_usSize; i++) {
            Pair_e98cb0* p = m_pBase[i];
            p->first.Clear();
            p->second.Clear();
            p = m_pBase[i];
            if (p) {
                p->second.Release();
                p->first.Release();
                DAT_011f6238.FUN_00aa4060((SpawnedObject*)p);
            }
        }
        for (unsigned short j = 0; j < m_usSize; j++)
            m_pBase[j] = 0;
        m_usSize = 0;
        m_usESize = 0;
    }
}

struct NiColor3 {
    float m_r;
    float m_g;
    float m_kPointB;
    __forceinline NiColor3() : m_r(0.0f), m_g(0.0f), m_kPointB(0.0f) {}
};

class NiMemObject {
public:
    static void* operator new(unsigned int size) throw();
    static void* operator new(unsigned int, void* p) { return p; }
};

inline void* __cdecl operator new(unsigned int, void* p) { return p; }

extern volatile long DAT_011f4400;

class NiRefObject : public NiMemObject {
public:
    NiRefObject() throw() {
        m_uiRefCount = 0;
        InterlockedIncrement(&DAT_011f4400);
    }
    virtual void V0();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
};

class NiProperty : public NiRefObject {
public:
    NiProperty() throw();
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};

class NiAlphaProperty : public NiProperty {
public:
    NiAlphaProperty() throw() {
        m_usAlphaArg = 0xec;
        m_ucAlphaArg2 = 0;
    }
    unsigned short m_usAlphaArg;
    unsigned char m_ucAlphaArg2;
    unsigned char m_ucPad1b;
};

struct SubObjF8 {
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
    void __thiscall FUN_00e68810() throw();
    SubObjF8() {
        FUN_00e68810();
    }
};

struct PairEntry {
    int key;
    int val;
};

extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);

extern int DAT_0126f918;
extern int DAT_0126f91c;
extern int DAT_0126f920;
extern int DAT_0126f924;
extern int DAT_0126f928;
extern unsigned short DAT_0126f92c[];
extern unsigned short DAT_0126f948[8];
extern unsigned short DAT_0126f958[];

class FUN_00e881a0 : public NiRefObject {
public:
    FUN_00e881a0(void* renderer);
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
    NiAlphaProperty* m_74;
    float m_78;
    float m_7c;
    float m_80;
    float m_84;
    float m_88;
    NiColor3 m_8c;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    int m_e0;
    int m_e4;
    int m_e8;
    int m_ec;
    int m_f0;
    int m_f4;
    SubObjF8 m_f8;
    PairEntry m_120[256];
    int m_920[64];
    PairEntry m_a20[128];
    PairEntry m_e20[80];
    int m_10a0[20];
    int m_10f0;
    unsigned char m_10f4;
    unsigned char m_10f5;
    unsigned char m_10f6;
    unsigned char m_10f7;
    void* m_10f8;
    int m_10fc;
};

// Initializes the renderer object: fills lookup tables with sentinel keys, resets counters, creates an NiAlphaProperty, and sets default index and color values.
// @fnv 0x00e881a0
FUN_00e881a0::FUN_00e881a0(void* renderer)
    : NiRefObject(), m_74(0), m_8c(), m_f8()
{
    PairEntry* pEntry120 = m_120;
    int iCount120 = 255;
    do {
        pEntry120->key = 0x7fffffff;
        ++pEntry120;
        --iCount120;
    } while (iCount120 >= 0);
    PairEntry* p2 = m_a20;
    int iCountA20 = 127;
    do {
        p2->key = 0x7fffffff;
        ++p2;
        --iCountA20;
    } while (iCountA20 >= 0);
    PairEntry* p3 = m_e20;
    int iCountE20 = 79;
    do {
        p3->key = 0x7fffffff;
        ++p3;
        --iCountE20;
    } while (iCountE20 >= 0);

    void* r = renderer;
    int& firstSlot = m_10f0; firstSlot = 0;
    m_10f8 = 0;
    m_10fc = 0;
    ((FUN_00e87af0_This*)this)->FUN_00e87af0(r);

    m_0c = 0;
    m_10 = 1;
    m_14 = 1;
    m_18 = 2;
    m_1c = 3;
    m_6c = 0;
    m_70 = 0;
    NiAlphaProperty* pNew = new NiAlphaProperty();

    NiAlphaProperty* pOldAlpha = m_74;
    if (pOldAlpha != pNew) {
        if (pOldAlpha) {
            if (InterlockedDecrement((volatile long*)((char*)pOldAlpha + 4)) == 0)
                pOldAlpha->DeleteThis();
        }
        m_74 = pNew;
        if (pNew)
            InterlockedIncrement((volatile long*)((char*)pNew + 4));
    }

    int four = 4;
    int five = 5;
    int six = 6;

    m_20 = 2;
    m_24 = 1;
    m_28 = 3;
    m_2c = four;
    m_30 = 9;
    m_34 = 10;
    m_38 = five;
    m_3c = six;
    m_40 = 7;
    m_44 = 8;
    m_48 = 11;
    m_4c = 8;

    m_50 = 2;
    m_54 = 3;
    m_58 = four;
    m_5c = five;
    m_60 = six;
    m_64 = 7;
    m_68 = 1;

    m_78 = 0.0f;
    m_7c = 0.0f;
    m_80 = 0.0f;
    m_84 = 0.0f;
    m_88 = 1.0f;

    m_b8 = 8;
    m_a0 = 2;
    m_a4 = 3;
    m_a8 = four;
    m_ac = five;
    m_b0 = six;
    m_b4 = 7;
    m_9c = 1;

    m_bc = 1;
    m_c0 = 2;
    m_c4 = 3;
    m_c8 = four;
    m_cc = five;
    m_d0 = six;
    m_d4 = 2;
    m_dc = 2;
    m_e4 = 3;
    m_ec = 1;
    m_d8 = 3;
    m_e0 = 3;
    m_e8 = 2;
    m_f0 = 1;
    m_f4 = 0;

    m_8c = *(NiColor3*)&DAT_011f4998;
    int b0 = (unsigned char)(m_8c.m_r * 255.0);
    int b1 = (unsigned char)(m_8c.m_g * 255.0);
    int b2 = (unsigned char)(m_8c.m_kPointB * 255.0);
    int packed = (b0 | 0xffffff00);
    packed = (packed << 8) | (unsigned char)b1;
    packed = (packed << 8) | (unsigned char)b2;
    m_98 = packed;
    m_08 = 0;

    m_f8.m_08 = 8;
    m_f8.m_0c = 2;
    m_f8.m_10 = 3;
    m_f8.m_14 = 4;
    m_f8.m_18 = 5;
    m_f8.m_1c = 6;
    m_f8.m_20 = 7;
    m_f8.m_24 = 1;

    m_10f4 = 0;
    m_10f5 = 0;
    fnv_zlib_memset(DAT_0126f958, 0xffff, 0x42);

    DAT_0126f958[1] = 0;
    DAT_0126f958[2] = 1;
    DAT_0126f958[3] = 2;
    DAT_0126f958[4] = 3;
    DAT_0126f958[5] = 4;
    DAT_0126f958[6] = 5;
    DAT_0126f958[7] = 6;
    DAT_0126f958[24] = 7;
    DAT_0126f948[0] = 1;
    DAT_0126f948[1] = 2;
    DAT_0126f948[2] = 3;
    DAT_0126f948[3] = 4;
    DAT_0126f948[4] = 5;
    DAT_0126f948[5] = 6;
    DAT_0126f948[6] = 7;

    ((int*)DAT_0126f92c)[0] = -1;
    ((int*)DAT_0126f92c)[3] = -1;
    ((int*)DAT_0126f92c)[1] = -1;
    ((int*)DAT_0126f92c)[2] = -1;
    DAT_0126f948[7] = 0x18;
    ((int*)DAT_0126f92c)[4] = -1;
    ((int*)DAT_0126f92c)[5] = -1;
    ((int*)DAT_0126f92c)[6] = -1;
    DAT_0126f92c[1] = 0;
    DAT_0126f92c[2] = 1;
    DAT_0126f92c[5] = 2;
    DAT_0126f92c[6] = 3;
    DAT_0126f92c[7] = 4;

    DAT_0126f918 = 1;
    DAT_0126f91c = 2;
    DAT_0126f920 = 5;
    DAT_0126f924 = 6;
    DAT_0126f928 = 7;
}

struct FUN_00e8bf80_Object {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38;
    int m_uiItemCount;
    void __thiscall FUN_00e8bf80();
};
// @fnv 0x00e8bf80
void __thiscall FUN_00e8bf80_Object::FUN_00e8bf80() {
    ++m_uiItemCount;
}

struct FUN_00e8d350_Class {
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

    int* __thiscall FUN_00e8d350();
};

// @fnv 0x00e8d350
int* __thiscall FUN_00e8d350_Class::FUN_00e8d350() {
    return &unk3C;
}

struct Item9ea;

bool DispatchByVirtualIndex(float fTime, Item9ea* pkItem, void* p2, void* p3, void* p4, void* p5, void* p6);

struct Seq9ea
{
    int m_00;
    int m_04;
    Item9ea** m_ppGeometries;
    short m_0c;
    unsigned short m_usElementCount;
    int m_10;
    unsigned int m_uiLast;
};

// Iterates the sequence's items, calls DispatchByVirtualIndex on each, and on success stores the index in m_uiLast and returns true.
// @fnv 0x00e9ea70
bool FUN_00e9ea70(float fTime, Seq9ea* pkSeq, void* p2, void* p3, void* p4, void* p5, void* p6)
{
    for (unsigned int i = 0; i < pkSeq->m_usElementCount; i++)
    {
        Item9ea* pkItem = pkSeq->m_ppGeometries[i];
        if (DispatchByVirtualIndex(fTime, pkItem, p2, p3, p4, p5, p6))
        {
            pkSeq->m_uiLast = i;
            return true;
        }
    }
    return false;
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

struct ColorWithAlpha { float r,g,b,a; ColorWithAlpha(float red,float green,float blue):r(red),g(green),b(blue) {} void addScaled(const ColorWithAlpha& source,float factor) { r+=source.r*factor;g+=source.g*factor;b+=source.b*factor; } };
struct ActiveLight;
struct SceneLight {
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
 unsigned int field44;
 unsigned int field48;
 unsigned int field4c;
 unsigned int field50;
 unsigned int field54;
 unsigned int field58;
 unsigned int field5c;
 unsigned int field60;
 unsigned int field64;
 unsigned int field68;
 unsigned int field6c;
 unsigned int field70;
 unsigned int field74;
 unsigned int field78;
 unsigned int field7c;
 unsigned int field80;
 unsigned int field84;
 unsigned int field88;
 unsigned int field8c;
 unsigned int field90;
 unsigned int field94;
 unsigned int field98;
 unsigned char enabled; unsigned char direct; unsigned short field9e;
 unsigned int fielda0;
 unsigned int fielda4;
 unsigned int fielda8;
 unsigned int fieldac;
 unsigned int fieldb0;
 unsigned int fieldb4;
 unsigned int fieldb8;
 unsigned int fieldbc;
 unsigned int fieldc0;
 float intensity;
 float red;
 float green;
 float blue;
 unsigned int fieldd4;
 unsigned int fieldd8;
 unsigned int fielddc;
 unsigned int fielde0;
 unsigned int fielde4;
 unsigned int fielde8;
 ActiveLight* active;
};
struct ActiveLight {
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
 unsigned int field44;
 unsigned int field48;
 unsigned int field4c;
 unsigned int field50;
 unsigned int field54;
 unsigned int field58;
 unsigned int field5c;
 unsigned int field60;
 unsigned int field64;
 unsigned int field68;
 unsigned int field6c;
 bool stale; bool applied; unsigned short field72;
 bool UpdateFromSource(SceneLight*);
 ActiveLight* Init(SceneLight*, unsigned int);
};
struct LightDevice {
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
 virtual void __stdcall SetLight(unsigned int, ActiveLight*);
 virtual void slotd0();
 virtual void __stdcall EnableLight(unsigned int, int);
};
struct LightInputNode { LightInputNode* next; SceneLight* light; };
struct LightInput { unsigned int field00,field04,field08; LightInputNode* head; };
inline SceneLight*& nextLight(PoolNode*& node) { SceneLight*& item=(SceneLight*&)node->data; node=node->next; return item; }
struct ShadowSceneLightList { PoolNode* head; PoolNode* tail; unsigned int count; void* InsertHead(SceneLight* const*); SceneLight* FUN_004edf00();
 __forceinline void recycle(PoolNode* node) { node->data=0; DAT_011c5f80.Lock(0); node->prev=0; node->next=DAT_011c5f58; --DAT_011c5f84; DAT_011c5f58=node; if (!DAT_011c5f84) DAT_011c5f80.value=0; }
 __forceinline SceneLight* remove(PoolNode*& node) { if(node==head) { PoolNode* old=head; head=old->next; if(head) head->prev=0; else tail=0; SceneLight* element=(SceneLight*)old->data; recycle(old); --count; return element; } else if(node==tail) { return FUN_004edf00(); } else { PoolNode* prev=node->prev; PoolNode* next=node->next; if(prev)prev->next=next; if(next)next->prev=prev; SceneLight* element=(SceneLight*)node->data; recycle(node); --count; return element; } }
};
extern const float runtimeFloatSettingDefault9;
struct LightManager { unsigned int field00,field04,field08,field0c; ShadowSceneLightList active; LightDevice* device; MobileTargetObj* render; unsigned int field24,field28; unsigned char field2c; bool enabled; unsigned short field2e;
 unsigned int AllocateBitIndex(); void InsertOrUpdate(SceneLight*,ActiveLight*); void FUN_00e8b740(LightInput* input); };
// @fnv 0x00e8b740
void LightManager::FUN_00e8b740(LightInput* input) {
 ShadowSceneLightList* m_pAdditionalHudTile=&active;
 ColorWithAlpha ambient(0.0f,0.0f,0.0f);
 PoolNode* mark=m_pAdditionalHudTile->head; while(mark) nextLight(mark)->active->stale=true;
 if(enabled) {
 LightInputNode* pos=0; if(input)pos=input->head;
 unsigned int count=0;
 while(pos && count<8) {
 SceneLight* __restrict current;
 if(!pos) current=0; else { current=pos->light;pos=pos->next; }
 SceneLight* light=current;
 if(!current->enabled || current->intensity < 0.01f) continue;
 if(!current->direct) {
 float intensity=current->intensity;
 ambient.addScaled(*(ColorWithAlpha*)&current->red,intensity);
 } else {
 ActiveLight* data=current->active;
 bool update;
 if(data) update=data->UpdateFromSource(current);
 else {
 unsigned int index=AllocateBitIndex();
 if(index==-1)continue;
 ActiveLight* fresh=(ActiveLight*)BSFadeNode::operator new(sizeof(ActiveLight));
 if(fresh)data=fresh->Init(current,index); else data=0;
 InsertOrUpdate(current,data);
 current->active=data;
 update=true;
 }
 if(update)device->SetLight(data->field6c,data);
 if(!data->applied)m_pAdditionalHudTile->InsertHead(&light);
 data->stale=false;
 ++count;
 }
 }
 }
 PoolNode* pos=m_pAdditionalHudTile->head;
 while(pos) { PoolNode* node=pos; SceneLight** item=(SceneLight**)&node->data; ActiveLight* data=(*item)->active; pos=pos->next;
 if(data->stale) { device->EnableLight(data->field6c,0); data->applied=false;m_pAdditionalHudTile->remove(node); }
 }
 for(PoolNode* enable=m_pAdditionalHudTile->head;enable;) { ActiveLight* data=nextLight(enable)->active;
 if(!data->stale && !data->applied) { device->EnableLight(data->field6c,1);data->applied=true; }
 }
 unsigned int r=(unsigned int)(ambient.r*255.0); if(r>255)r=255;
 unsigned int g=(unsigned int)(ambient.g*255.0); if(g>255)g=255;
 unsigned int b=(unsigned int)(ambient.b*255.0); if(b>255)b=255;
 unsigned int color=((((0xffffff00|((unsigned char)r))<<8)|((unsigned char)g))<<8)|((unsigned char)b);
 render->v68(139,color,0,0);
}

struct S00e8f190_Iface { void** vtable; };
typedef int (__thiscall *S00e8f190_Query)(void* vt, S00e8f190_Iface* object, int a, int b, int c, int d, S00e8f190_Iface** result, int zero);
typedef void (__fastcall *S00e8f190_Release)(void* flag, void* vt, S00e8f190_Iface* object, void* flag2);
struct S00e8f190_Cls {
    int unk00;
    int unk04;
    S00e8f190_Iface* object;
    S00e8f190_Iface* __thiscall FUN_00e8f190(int a, int b, int c, int d, void* flag);
};
extern "C" const char str_010f0184[];
// Calls object's vtable slot 27 to get an interface pointer; if flag is set, calls slot 13 on it; on failure calls FUN_00a29680 with a string and returns 0.
// @fnv 0x00e8f190
S00e8f190_Iface* __thiscall S00e8f190_Cls::FUN_00e8f190(int a, int b, int c, int d, void* flag)
{
    S00e8f190_Iface* result = 0;
    int status = ((S00e8f190_Query)object->vtable[27])(object->vtable, object, a, b, c, d, &result, 0);
    if (status >= 0) {
        if (flag) {
            ((S00e8f190_Release)result->vtable[13])(flag, result->vtable, result, flag);
            return result;
        }
        return result;
    }
    ((void (__cdecl *)(const char*))FUN_00a29680)(str_010f0184);
    return 0;
}

extern unsigned int DAT_011bf560;
extern unsigned int DAT_011bf558;

struct Stage321 {
    int m_00;
    unsigned int m_04;
    int m_08;
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
    int m_60;

    void ReturnToPool() throw();
    void AcquireReference() { ++m_60; }
    void DecRef() { if (--m_60 == 0) ReturnToPool(); }
};

struct StagePtr {
    Stage321* m_p;
    StagePtr(Stage321* o) : m_p(o) { if (m_p) m_p->AcquireReference(); }
};

struct StageArray {
    void* m_vtbl;
    StagePtr* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void FUN_00e7fd20(unsigned int size) throw();
    void Set(unsigned int index, const StagePtr& obj) throw();
    void SetAtGrow(unsigned int index, const StagePtr& obj) {
        if (index >= m_usMaxSize)
            FUN_00e7fd20(index + m_usGrowBy);
        Set(index, obj);
    }
};

struct StageSet {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int m_14;
    int m_18;
    int m_1C;
    StageArray m_20;

    int FUN_00e802b0(unsigned int index, Stage321* obj);
};

// Stores obj at index in m_20, updating m_14, m_18, m_1C, and obj->m_04, or shrinks m_14 when obj is null.
// @fnv 0x00e802b0
int StageSet::FUN_00e802b0(unsigned int index, Stage321* obj)
{
    if (index >= DAT_011bf560)
        return 1;

    if (index >= DAT_011bf558)
        m_20.SetAtGrow(index, obj);
    else
        m_20.Set(index, obj);

    if (obj) {
        obj->DecRef();
        obj->m_04 = index;
        if (m_14 == index)
            ++m_14;
        ++m_18;
        if (obj->m_08 != 0)
            ++m_1C;
    } else {
        if (m_14 == index + 1) {
            while (m_14 != 0) {
                if (m_20.m_pBase[m_14 - 1].m_p == 0) {
                    --m_14;
                    break;
                }
            }
        }
    }
    return 0;
}

struct S00e81b00_Mat {
    float m00, m04, m08, m0c, m10, m14, m18, m1c, m20, m24, m28, m2c, m30, m34, m38, m3c;
};

// Copies all 16 float elements of a 4x4 matrix from src to dst.
// @fnv 0x00e81b00
static __declspec(noinline) void CopyMatrix(S00e81b00_Mat* dst, const S00e81b00_Mat* src) {
    dst->m00 = src->m00; dst->m04 = src->m04; dst->m08 = src->m08; dst->m0c = src->m0c;
    dst->m10 = src->m10; dst->m14 = src->m14; dst->m18 = src->m18; dst->m1c = src->m1c;
    dst->m20 = src->m20; dst->m24 = src->m24; dst->m28 = src->m28; dst->m2c = src->m2c;
    dst->m30 = src->m30; dst->m34 = src->m34; dst->m38 = src->m38; dst->m3c = src->m3c;
}

void S00e81b00_Caller(S00e81b00_Mat* dst, const S00e81b00_Mat* src) {
    CopyMatrix(dst, src);
}

typedef unsigned int UINT;
typedef unsigned long DWORD;
struct SurfDesc { UINT Format, Type, Usage, Pool, MultiSampleType, MultiSampleQuality, Width, Height; };
struct VolDesc { UINT Format, Type, Usage, Pool, Width, Height, Depth; };
struct BaseTex {
 virtual long __stdcall QueryInterface(const void*,void**);
 virtual unsigned __stdcall AddRef();
 virtual unsigned __stdcall Release();
 virtual long __stdcall GetDevice(void**);
 virtual long __stdcall SetPrivateData(const void*,const void*,unsigned,unsigned);
 virtual long __stdcall GetPrivateData(const void*,void*,unsigned*);
 virtual long __stdcall FreePrivateData(const void*);
 virtual unsigned __stdcall SetPriority(unsigned);
 virtual unsigned __stdcall GetPriority();
 virtual void __stdcall PreLoad();
 virtual int __stdcall GetType();
 virtual unsigned __stdcall SetLOD(unsigned);
 virtual unsigned __stdcall GetLOD();
 virtual unsigned __stdcall GetLevelCount();
 virtual long __stdcall SetAutoGenFilterType(unsigned);
 virtual unsigned __stdcall GetAutoGenFilterType();
 virtual void __stdcall GenerateMipSubLevels();
};
struct Tex2D : BaseTex { virtual long __stdcall GetLevelDesc(unsigned, SurfDesc*); };
struct TexCube : BaseTex { virtual long __stdcall GetLevelDesc(unsigned, SurfDesc*); };
struct TexVol : BaseTex { virtual long __stdcall GetLevelDesc(unsigned, VolDesc*); };

void __cdecl GetPixelTemplateForFormat(UINT format, void* out);

struct TextureInfo {
    int unk00;
    int unk04;
    int unk08;
    UINT m_fMaxFriction;
    UINT m_height;
    int m_format14;
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
    DWORD m_levelCount;

    bool InitFromTexture(BaseTex* pTexture);
};

// Stores level count, dimensions, and pixel template from a texture, rejecting formats 40 and 41.
// @fnv 0x00e8a120
bool TextureInfo::InitFromTexture(BaseTex* pTexture)
{
    m_levelCount = pTexture->GetLevelCount();
    int eType = pTexture->GetType();
    if (eType == 3) {
        SurfDesc kDesc;
        if (0 > ((Tex2D*)pTexture)->GetLevelDesc(0, &kDesc))
            return false;
        m_fMaxFriction = kDesc.Width;
        m_height = kDesc.Height;
        if (kDesc.Format == 40 || kDesc.Format == 41)
            return false;
        GetPixelTemplateForFormat(kDesc.Format, &m_format14);
    } else if (eType == 5) {
        SurfDesc kDesc;
        if (0 > ((TexCube*)pTexture)->GetLevelDesc(0, &kDesc))
            return false;
        m_fMaxFriction = kDesc.Width;
        m_height = kDesc.Height;
        if (kDesc.Format == 40 || kDesc.Format == 41)
            return false;
        GetPixelTemplateForFormat(kDesc.Format, &m_format14);
    } else if (eType == 4) {
        VolDesc kDesc;
        if (0 > ((TexVol*)pTexture)->GetLevelDesc(0, &kDesc))
            return false;
        m_fMaxFriction = kDesc.Width;
        m_height = kDesc.Height;
        if (kDesc.Format == 40 || kDesc.Format == 41)
            return false;
        GetPixelTemplateForFormat(kDesc.Format, &m_format14);
    }
    return true;
}

void __cdecl FUN_00aa1460(void* pvMem, unsigned int uiSize);

class BSSpinLockE8B {
public:
    void Lock(int iSpin);
    unsigned int m_uiOwningThread;
    unsigned int m_uiLockCount;

    void Unlock()
    {
        if (--m_uiLockCount == 0)
            m_uiOwningThread = 0;
    }
};

struct NiTListItemE8B {
    NiTListItemE8B* m_pkNext;
    NiTListItemE8B* m_pkPrev;
    void* m_element;
};

extern BSSpinLockE8B g_kListPoolLockE8B;
extern NiTListItemE8B* g_pkListFreeMemE8B;

class NiTPointerListE8B {
public:
    NiTListItemE8B* m_pkHead;
    NiTListItemE8B* m_pkTail;
    unsigned int m_uiCount;

    void* RemoveHead();
    void* RemoveTail();

    void* const& GetNext(NiTListItemE8B*& kPos) const
    {
        void* const& element = kPos->m_element;
        kPos = kPos->m_pkNext;
        return element;
    }

    NiTListItemE8B* FindPos(void* element) const
    {
        NiTListItemE8B* kPos = m_pkHead;
        while (kPos) {
            NiTListItemE8B* kPrevPos = kPos;
            if (element == GetNext(kPos))
                return kPrevPos;
        }
        return 0;
    }

    void DeleteItem(NiTListItemE8B* pkItem)
    {
        g_kListPoolLockE8B.Lock(0);
        pkItem->m_pkPrev = 0;
        pkItem->m_pkNext = g_pkListFreeMemE8B;
        g_pkListFreeMemE8B = pkItem;
        g_kListPoolLockE8B.Unlock();
    }

    void RemovePos(NiTListItemE8B* pkNode)
    {
        if (pkNode == m_pkHead) {
            RemoveHead();
            return;
        }
        if (pkNode == m_pkTail) {
            RemoveTail();
            return;
        }
        NiTListItemE8B* pkPrev = pkNode->m_pkPrev;
        NiTListItemE8B* pkNext = pkNode->m_pkNext;
        if (pkPrev)
            pkPrev->m_pkNext = pkNext;
        if (pkNext)
            pkNext->m_pkPrev = pkPrev;
        pkNode->m_element = 0;
        DeleteItem(pkNode);
        m_uiCount--;
    }

    void Remove(void* element)
    {
        NiTListItemE8B* pkPos = FindPos(element);
        if (pkPos)
            RemovePos(pkPos);
    }
};

class ControllerE8B {
public:
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
    unsigned int unk68;
    void* m_pvHandle;
    unsigned char unk70;
    bool m_bModifierActive;
    unsigned short unk72;
};

class KeyObjectE8B {
public:
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
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
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
    unsigned int unkac;
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
    void* m_pvMapEntry;
};

class OwnerE8B {
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2c();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3c();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4c();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual void unk5c();
    virtual void unk60();
    virtual void unk64();
    virtual void unk68();
    virtual void unk6c();
    virtual void unk70();
    virtual void unk74();
    virtual void unk78();
    virtual void unk7c();
    virtual void unk80();
    virtual void unk84();
    virtual void unk88();
    virtual void unk8c();
    virtual void unk90();
    virtual void unk94();
    virtual void unk98();
    virtual void unk9c();
    virtual void unka0();
    virtual void unka4();
    virtual void unka8();
    virtual void unkac();
    virtual void unkb0();
    virtual void unkb4();
    virtual void unkb8();
    virtual void unkbc();
    virtual void unkc0();
    virtual void unkc4();
    virtual void unkc8();
    virtual void unkcc();
    virtual void unkd0();
    virtual void __stdcall ReleaseHandle(void* pvHandle, int iFlags);
};

struct NiTMapItemE8B {
    NiTMapItemE8B* m_pkNext;
    KeyObjectE8B* m_key;
    ControllerE8B* m_val;
};

class ControllerMapE8B {
public:
    virtual ~ControllerMapE8B();
    virtual unsigned int KeyToHashIndex(KeyObjectE8B* key) const;

    unsigned int m_uiHashSize;
    NiTMapItemE8B** m_ppkHashTable;
    unsigned int m_uiCount;
    NiTPointerListE8B m_kKeys;
    OwnerE8B* m_pkOwnerManager;

    NiTMapItemE8B* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++) {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }

    void GetNext(NiTMapItemE8B*& pos, KeyObjectE8B*& key, ControllerE8B*& val) const
    {
        NiTMapItemE8B* pkItem = pos;
        key = pkItem->m_key;
        val = pkItem->m_val;
        if (pkItem->m_pkNext) {
            pos = pkItem->m_pkNext;
            return;
        }
        unsigned int i = KeyToHashIndex(pkItem->m_key);
        for (++i; i < m_uiHashSize; i++) {
            pkItem = m_ppkHashTable[i];
            if (pkItem) {
                pos = pkItem;
                return;
            }
        }
        pos = 0;
    }

    void FUN_00e91fd0(KeyObjectE8B* key);
    void FUN_00e8be20();
};

// Iterates all map entries, releasing each controller handle, removing its key, and freeing the controller object.
// @fnv 0x00e8be20
void ControllerMapE8B::FUN_00e8be20()
{
    NiTMapItemE8B* pos = GetFirstPos();
    while (pos) {
        KeyObjectE8B* key;
        ControllerE8B* val;
        GetNext(pos, key, val);
        if (val) {
            m_pkOwnerManager->ReleaseHandle(val->m_pvHandle, 0);
            val->m_bModifierActive = false;
            FUN_00e91fd0(key);
            m_kKeys.Remove(key);
            key->m_pvMapEntry = 0;
            FUN_00aa1460(val, sizeof(ControllerE8B));
        }
    }
}

struct VBDesc {
    int iFormat;
    int iType;
    int iUsage;
    int iPool;
    unsigned int uiSize;
    unsigned int uiFVF;
};
struct VertexBuffer;
struct VertexBufferVtbl {
    void* s00; void* s04; void* s08; void* s0c;
    void* s10; void* s14; void* s18; void* s1c;
    void* s20; void* s24; void* s28; void* s2c;
    long (__stdcall *Unlock)(VertexBuffer* self);
    long (__stdcall *GetDesc)(VertexBuffer* self, VBDesc* desc);
};
struct VertexBuffer {
    VertexBufferVtbl* vtbl;
};
struct VBEntry {
    int unk00;
    int unk04;
    VertexBuffer* pkVB;
    unsigned int uiElapsedMilliseconds;
    unsigned int uiFlags;
    unsigned int uiSize;
};
struct C_00e8f010 {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    unsigned int uiStreamCount;
    unsigned int* puiStrides;
    void FUN_00e8f010(int fvf);
};
struct FUN_00e69b40_shell {
    unsigned int GetEntry(unsigned int index);
};
struct Outer;
extern "C" void* memmove(void* dst, const void* src, unsigned int n);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);
struct SixIntegerRecord {
    int d00; int d04; int d08; int d0c; int d10; int d14;
};
struct TwoComponentVector { float x, y; };
struct Point4 { TwoComponentVector kXY; float z, w; };
struct ThisObj {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    void* pvSrc;
    int unk44;
    void* pvDst;
    unsigned int uiLen;
    int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c;
    int unk70; int unk74; int unk78; int unk7c;
    SixIntegerRecord kLock;
    bool FUN_00e8bfa0(Outer* outer, unsigned int arg);
    void* FUN_00e8bff0(VertexBuffer* vb, unsigned int offset, unsigned int size, unsigned int flags);
    VBEntry* FUN_00e8c570(C_00e8f010* owner, unsigned short count, const TwoComponentVector* pos, const float* col, const unsigned int* uv, unsigned int streamFlags, VBEntry* existing, void* data);
};
// @fnv 0x00e8c570
VBEntry* ThisObj::FUN_00e8c570(C_00e8f010* owner, unsigned short count, const TwoComponentVector* pos, const float* col, const unsigned int* uv, unsigned int streamFlags, VBEntry* existing, void* data) {
    if (count == 0 || pos == 0)
        return existing;
    int fvf = 4;
    int stride = 16;
    unsigned int colOffset;
    unsigned int uvOffset;
    if (col) {
        fvf = 0x44;
        colOffset = stride;
        stride = 20;
    }
    if (uv) {
        fvf |= 0x100;
        uvOffset = stride;
        stride += 8;
    }
    owner->FUN_00e8f010(fvf);
    if (owner->uiStreamCount > 0)
        *owner->puiStrides = stride;
    bool bUnlock = true;
    VBEntry* result;
    if (data) {
        result = existing;
        bUnlock = false;
    } else {
        bool bReuse = false;
        if (existing) {
            VertexBuffer* vb = existing->pkVB;
            if (vb) {
                VBDesc desc;
                vb->vtbl->GetDesc(vb, &desc);
                if (desc.iFormat == 100 && desc.uiFVF == fvf && desc.uiSize >= (unsigned int)(count * stride)) {
                    result = existing;
                    bReuse = true;
                }
            }
        }
        if (!bReuse) {
            if (!FUN_00e8bfa0((Outer*)owner, 0))
                return 0;
            result = (VBEntry*)((FUN_00e69b40_shell*)owner)->GetEntry(0);
        }
        unsigned int uiFlags = result->uiFlags;
        unsigned int uiSize = result->uiSize;
        unsigned int uiElapsedMilliseconds = result->uiElapsedMilliseconds;
        VertexBuffer* vb = result->pkVB;
        data = FUN_00e8bff0(vb, uiElapsedMilliseconds, uiSize, uiFlags);
    }
    if (streamFlags & 1) {
        Point4* j = (Point4*)data;
        for (unsigned short i = 0; i < count; ++i) {
            float* pz = &j->z;
            j->kXY = *pos;
            *pz = 0.0f;
            j->w = 1.0f;
            ++pos;
            j = (Point4*)((char*)j + stride);
        }
    }
    if (col && (streamFlags & 4)) {
        unsigned int* j = (unsigned int*)((char*)data + colOffset);
        for (unsigned short i = 0; i < count; ++i) {
            *j = (((fnv_FloatToInt((float)(col[3] * 255.0)) << 8 |
                    fnv_FloatToInt((float)(col[0] * 255.0))) << 8 |
                    fnv_FloatToInt((float)(col[1] * 255.0))) << 8 |
                    fnv_FloatToInt((float)(col[2] * 255.0)));
            j = (unsigned int*)((char*)j + stride);
            col += 4;
        }
    }
    if (uv && (streamFlags & 2)) {
        unsigned int* j = (unsigned int*)((char*)data + uvOffset);
        for (unsigned short i = 0; i < count; ++i) {
            j[0] = uv[0];
            j[1] = uv[1];
            j = (unsigned int*)((char*)j + stride);
            uv += 2;
        }
    }
    if (bUnlock) {
        VertexBuffer* vb = result->pkVB;
        memmove(pvDst, pvSrc, uiLen);
        pvDst = 0;
        uiLen = 0;
        LeaveCriticalSection(&kLock);
        if (vb->vtbl->Unlock(vb) < 0)
            return 0;
    }
    return result;
}

struct S00e8f360_Desc {
    unsigned int Format;
    unsigned int Type;
    unsigned int Usage;
    unsigned int Pool;
    unsigned int Size;
};
enum { S00e8f360_FMT16 = 101, S00e8f360_RTIB = 7 };
struct S00e8f360_IB {
    virtual long __stdcall QueryInterface(void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetDevice(void**) = 0;
    virtual long __stdcall SetPrivateData(const void*, const void*, unsigned long, unsigned long) = 0;
    virtual long __stdcall GetPrivateData(const void*, void*, unsigned long*) = 0;
    virtual long __stdcall FreePrivateData(const void*) = 0;
    virtual unsigned long __stdcall SetPriority(unsigned long) = 0;
    virtual unsigned long __stdcall GetPriority() = 0;
    virtual void __stdcall PreLoad() = 0;
    virtual unsigned int __stdcall GetType() = 0;
    virtual long __stdcall Lock(unsigned int, unsigned int, void**, unsigned int) = 0;
    virtual long __stdcall Unlock() = 0;
    virtual long __stdcall GetDesc(S00e8f360_Desc*) = 0;
};
struct S00e8f360_Dev {
    virtual long __stdcall v00() = 0;
    virtual long __stdcall v01() = 0;
    virtual long __stdcall v02() = 0;
    virtual long __stdcall v03() = 0;
    virtual long __stdcall v04() = 0;
    virtual long __stdcall v05() = 0;
    virtual long __stdcall v06() = 0;
    virtual long __stdcall v07() = 0;
    virtual long __stdcall v08() = 0;
    virtual long __stdcall v09() = 0;
    virtual long __stdcall v10() = 0;
    virtual long __stdcall v11() = 0;
    virtual long __stdcall v12() = 0;
    virtual long __stdcall v13() = 0;
    virtual long __stdcall v14() = 0;
    virtual long __stdcall v15() = 0;
    virtual long __stdcall v16() = 0;
    virtual long __stdcall v17() = 0;
    virtual long __stdcall v18() = 0;
    virtual long __stdcall v19() = 0;
    virtual long __stdcall v20() = 0;
    virtual long __stdcall v21() = 0;
    virtual long __stdcall v22() = 0;
    virtual long __stdcall v23() = 0;
    virtual long __stdcall v24() = 0;
    virtual long __stdcall v25() = 0;
    virtual long __stdcall v26() = 0;
    virtual long __stdcall CreateIndexBuffer(unsigned int, unsigned int, unsigned int, unsigned int, S00e8f360_IB**, void*) = 0;
};
extern const char str_010f0184[];
extern const char str_010f0200[];
extern const char str_010eddd0[];
typedef void (__cdecl *S00e8f360_LogFn)(const char*);
struct S00e8f360_Mgr {
    void* m_pOwnerObject;
    void* m_pThreadAllocator;
    S00e8f360_Dev* m_device;
    S00e8f360_IB* m_indexBuffer;
    unsigned int m_indexBufferSize;
    S00e8f360_IB* EnsureIndexBuffer(unsigned int minQuads, unsigned int quadCount, bool populate, unsigned int usage, unsigned int pool);
};
// Reuses or creates a 16-bit index buffer sized for quadCount quads, fills it with quad indices (on reuse only if populate), and caches it in m_indexBuffer.
// @fnv 0x00e8f360
S00e8f360_IB* S00e8f360_Mgr::EnsureIndexBuffer(unsigned int minQuads, unsigned int quadCount, bool populate, unsigned int usage, unsigned int pool)
{
    if (!m_device)
        return 0;
    if (!minQuads)
        return 0;
    unsigned int size = quadCount * 12;
    S00e8f360_IB* old = m_indexBuffer;
    S00e8f360_IB* buffer;
    if (old) {
        S00e8f360_Desc desc = {};
        if (old->GetDesc(&desc) >= 0) {
            if (desc.Format == S00e8f360_FMT16 && desc.Type == S00e8f360_RTIB && desc.Usage == usage
                && desc.Pool == pool && desc.Size >= minQuads * 12) {
                buffer = old;
                if (populate)
                    goto fill;
                return old;
            }
            old->Release();
        }
    }
    {
        S00e8f360_IB* fresh = 0;
        if (m_device->CreateIndexBuffer(size, usage, S00e8f360_FMT16, pool, &fresh, 0) < 0) {
            ((S00e8f360_LogFn)FUN_00a29680)(str_010f0184);
            fresh = 0;
        }
        buffer = fresh;
    }
    if (!buffer) {
        ((S00e8f360_LogFn)FUN_00a29680)(str_010f0200);
        return 0;
    }
fill:
    {
        unsigned int vertex = 0;
        void* data = 0;
        if (buffer->Lock(0, size, &data, 0) >= 0) {
            unsigned short* indices = (unsigned short*)data;
            for (unsigned int i = 0; i < quadCount; ++i) {
                unsigned short v = (unsigned short)vertex;
                *indices++ = v;
                *indices++ = v + 1;
                *indices++ = v + 2;
                *indices++ = v;
                *indices++ = v + 2;
                *indices++ = v + 3;
                vertex += 4;
            }
            buffer->Unlock();
        } else {
            ((S00e8f360_LogFn)FUN_00a29680)(str_010eddd0);
            buffer->Unlock();
            buffer->Release();
            buffer = 0;
        }
    }
    m_indexBuffer = buffer;
    m_indexBufferSize = size;
    return buffer;
}

extern "C" void* __cdecl memset(void*, int, unsigned int);

struct IDirect3DDevice9Like;

struct D3DINDEXBUFFER_DESC_L
{
    int Format;
    int Type;
    unsigned int Usage;
    int Pool;
    unsigned int Size;
};

struct IDirect3DIndexBuffer9Like
{
    virtual long __stdcall QueryInterface(void* riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall Slot03() = 0;
    virtual long __stdcall Slot04() = 0;
    virtual long __stdcall Slot05() = 0;
    virtual long __stdcall Slot06() = 0;
    virtual long __stdcall Slot07() = 0;
    virtual long __stdcall Slot08() = 0;
    virtual long __stdcall Slot09() = 0;
    virtual long __stdcall Slot10() = 0;
    virtual long __stdcall Lock(unsigned int OffsetToLock, unsigned int SizeToLock, void** ppbData, unsigned int Flags) = 0;
    virtual long __stdcall Unlock() = 0;
    virtual long __stdcall GetDesc(D3DINDEXBUFFER_DESC_L* pDesc) = 0;
};

class NiDX9IndexBufferManager
{
public:
    IDirect3DIndexBuffer9Like* FUN_00e8f190(unsigned int uiLength, unsigned int uiUsage,
        int eFormat, int ePool, void* pkDesc);
    IDirect3DIndexBuffer9Like* ResizeTempLineConnectivityIB(unsigned int uiVertexCount, const unsigned char* pucConnect,
        unsigned int* puiIndexCount, unsigned int uiUsage, int ePool);

    IDirect3DIndexBuffer9Like* ResizeTemp(unsigned int uiSize, unsigned int uiUsage, int ePool);
    static bool PackBuffer(IDirect3DIndexBuffer9Like* pkIB, unsigned int uiSize, unsigned int uiVertexCount,
        const unsigned char* pucConnect, unsigned int* puiIndexCount);

    int m_iRefCount;
    int m_unk04;
    IDirect3DDevice9Like* m_pDirect3DDevice;
    int m_unk0c;
    int m_unk10;
    IDirect3DIndexBuffer9Like* m_pkTempLineConnectivityIB;
    unsigned int m_uiTempLineConnectivityIBSize;
};

// Resizes or creates a temporary index buffer for line connectivity, packing vertex indices from pucConnect and storing it in m_pkTempLineConnectivityIB.
// @fnv 0x00e8f520
IDirect3DIndexBuffer9Like* NiDX9IndexBufferManager::ResizeTempLineConnectivityIB(unsigned int uiVertexCount,
    const unsigned char* pucConnect, unsigned int* puiIndexCount, unsigned int uiUsage, int ePool)
{
    if (m_pDirect3DDevice == 0)
        return 0;

    if (uiVertexCount == 0)
        return 0;
    if (pucConnect == 0)
        return 0;

    unsigned int uiSize = (uiVertexCount + 1) * sizeof(unsigned short) * 2;

    IDirect3DIndexBuffer9Like* pkIB = 0;
    IDirect3DIndexBuffer9Like* pkTempIB = m_pkTempLineConnectivityIB;
    if (pkTempIB)
    {
        D3DINDEXBUFFER_DESC_L kDesc;
        memset(&kDesc, 0, sizeof(kDesc));
        if (pkTempIB->GetDesc(&kDesc) >= 0)
        {
            if (kDesc.Format == 0x65 && kDesc.Type == 7 &&
                kDesc.Usage == uiUsage && kDesc.Pool == ePool && kDesc.Size >= uiSize)
            {
                pkIB = pkTempIB;
            }
            else
            {
                pkTempIB->Release();
            }
        }
    }

    if (pkIB == 0)
    {
        pkIB = FUN_00e8f190(uiSize, uiUsage, 0x65, ePool, 0);
        if (pkIB == 0)
        {
            reinterpret_cast<void (__cdecl*)(const char*)>(FUN_00a29680)("NiDX9IndexBufferManager::ResizeTempLineConnectivity> "
                "Failed to create index buffer\n");
            return 0;
        }
    }
    *puiIndexCount = 0;
    {
        void* pvData = 0;
        if (pkIB->Lock(0, uiSize, &pvData, 0) >= 0)
        {
            unsigned short* pusIndices = (unsigned short*)pvData;
            unsigned int uiLast = uiVertexCount - 1;
            for (unsigned int i = 0; i < uiLast; i++)
            {
                if (*pucConnect)
                {
                    pusIndices[0] = (unsigned short)i;
                    pusIndices[1] = (unsigned short)(i + 1);
                    pusIndices += 2;
                    *puiIndexCount += 2;
                }
                pucConnect++;
            }
            if (*pucConnect)
            {
                pusIndices[0] = (unsigned short)uiLast;
                pusIndices[1] = 0;
                *puiIndexCount += 2;
            }
            pkIB->Unlock();
        }
        else
        {
            reinterpret_cast<void (__cdecl*)(const char*)>(FUN_00a29680)("NiDX9IndexBufferManager::PackBuffer> "
                "Failed to lock index buffer\n");
            pkIB->Unlock();
            pkIB->Release();
            pkIB = 0;
        }
    }
    m_pkTempLineConnectivityIB = pkIB;
    m_uiTempLineConnectivityIBSize = uiSize;
    return pkIB;
}

struct Resource8F6D0 {
    virtual long __stdcall QueryInterface(void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};
struct Chip8F6D0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Resource8F6D0* m_pkResource;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    ~Chip8F6D0();
    static void operator delete(void* pvMem, unsigned int uiSize);
};
struct Entry8F6D0 {
    int unk00;
    int unk04;
    Chip8F6D0* m_apChips[5];
    static void operator delete(void* pvMem, unsigned int uiSize);
};
struct Item8F6D0 {
    Item8F6D0* m_pkNext;
    unsigned int m_key;
    Entry8F6D0* m_val;
};
struct Map8F6D0 {
    virtual ~Map8F6D0();
    unsigned int m_uiHashSize;
    Item8F6D0** m_ppkHashTable;
    unsigned int m_uiCount;

    Item8F6D0* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }
    __declspec(noalias) void GetNext(Item8F6D0*& pos, unsigned int& key, Entry8F6D0*& val) const;
    void RemoveAll();
};
struct Owner8F6D0 {
    int unk00;
    int unk04;
    int unk08;
    Resource8F6D0* m_pkResource0C;
    int unk10;
    Resource8F6D0* m_pkResource14;
    int unk18;
    Map8F6D0 m_kEntries;
    void FUN_00e8f6d0();
};

// Releases and deletes all chips and entries in m_kEntries, then releases m_pkResource0C and m_pkResource14.
// @fnv 0x00e8f6d0
void Owner8F6D0::FUN_00e8f6d0()
{
    Item8F6D0* pos = m_kEntries.GetFirstPos();
    while (pos)
    {
        unsigned int key;
        Entry8F6D0* pkEntry;
        m_kEntries.GetNext(pos, key, pkEntry);
        if (pkEntry)
        {
            Chip8F6D0** ppkChip = pkEntry->m_apChips;
            int n = 5;
            do
            {
                Chip8F6D0* pkChip = *ppkChip;
                if (pkChip)
                {
                    Resource8F6D0* pkResource = pkChip->m_pkResource;
                    if (pkResource)
                        pkResource->Release();
                    delete pkChip;
                }
                ++ppkChip;
            } while (--n);
            delete pkEntry;
        }
    }
    m_kEntries.RemoveAll();
    if (m_pkResource0C)
    {
        m_pkResource0C->Release();
        m_pkResource0C = 0;
    }
    if (m_pkResource14)
    {
        m_pkResource14->Release();
        m_pkResource14 = 0;
    }
}

#include <string.h>
struct FUN_00e93470_Output {
    unsigned int flags;
    const char* text;
    unsigned int data;
};
struct FUN_00e93470_Class {
    unsigned int m_field00;
    unsigned int m_field04;
    unsigned int m_field08;
    unsigned int m_field0c;
    unsigned char m_copyText;
    void __thiscall FUN_00e93470(FUN_00e93470_Output* out, const char* text, unsigned int data);
};
extern "C" void* __cdecl FUN_00aa1070(unsigned int length);
extern "C" void __cdecl FUN_00ec65a6(void* destination, unsigned int length, const char* source);

// @fnv 0x00e93470
void FUN_00e93470_Class::FUN_00e93470(FUN_00e93470_Output* out, const char* text, unsigned int data)
{
    if (m_copyText) {
        const unsigned int length = (unsigned int)strlen(text) + 1;
        void* copied = FUN_00aa1070(length);
        out->text = static_cast<const char*>(copied);
        FUN_00ec65a6(copied, length, text);
    } else {
        out->text = text;
    }
    out->data = data;
}

struct RefBaseE989 {
    unsigned int m_uiRefCount;
    RefBaseE989() : m_uiRefCount(0) {}
    virtual ~RefBaseE989() { InterlockedDecrement(&DAT_011f4400); }
};
struct ComReleaseE989 {
    virtual long __stdcall QueryInterface(void* riid, void** out);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};
struct ShaderDataE989 : RefBaseE989 {
    void* m_08; void* m_0c; void* m_10; void* m_14;
    int m_18; int m_1c; int m_20; int m_24; int m_28; int m_2c;
    void* m_30; void* m_34; void* m_38; void* m_3c;
    int m_40; int m_44; int m_48; int m_4c; int m_50; int m_54;
    void* m_58; void* m_5c; void* m_60; void* m_64;
    int m_68; int m_6c; int m_70; int m_74; int m_78; int m_7c;
    ComReleaseE989* m_80;
    virtual ~ShaderDataE989() throw();
};
// Calls FUN_00aa10f0 on 12 pointer members, then calls Release on m_80 and nulls it if set.
// @fnv 0x00e989c0
ShaderDataE989::~ShaderDataE989() throw()
{
    FUN_00aa10f0(m_08);
    FUN_00aa10f0(m_0c);
    FUN_00aa10f0(m_10);
    FUN_00aa10f0(m_14);
    FUN_00aa10f0(m_30);
    FUN_00aa10f0(m_34);
    FUN_00aa10f0(m_38);
    FUN_00aa10f0(m_3c);
    FUN_00aa10f0(m_58);
    FUN_00aa10f0(m_5c);
    FUN_00aa10f0(m_60);
    FUN_00aa10f0(m_64);
    if (m_80)
    {
        m_80->Release();
        m_80 = 0;
    }
}

struct FUN_00e9ca50_Object {
    virtual void FUN_00e9ca50_Virtual0();
    virtual void FUN_00e9ca50_Virtual1();
    virtual void FUN_00e9ca50_Virtual2();
    virtual int FUN_00e9ca50_GetIndex();
};

typedef void (__cdecl *FUN_00e9ca50_Entry)(
    float,
    FUN_00e9ca50_Object *,
    int,
    int,
    int,
    int,
    int,
    int,
    int,
    int,
    int,
    int);

extern void **DAT_0126faa0;

// Looks up a function pointer in DAT_0126faa0 using the object's index and calls it with the forwarded value and arguments.
// @fnv 0x00e9ca50
void __cdecl FUN_00e9ca50(
    float value,
    FUN_00e9ca50_Object *object,
    int arg1,
    int arg2,
    int arg3,
    int arg4,
    int arg5,
    int arg6,
    int arg7,
    int arg8,
    int arg9,
    int arg10)
{
    int index = object->FUN_00e9ca50_GetIndex();
    float forwardedValue = value;
    FUN_00e9ca50_Entry entry =
        ((volatile FUN_00e9ca50_Entry *)DAT_0126faa0)[index];

    entry(
        forwardedValue,
        object,
        arg1,
        arg2,
        arg3,
        arg4,
        arg5,
        arg6,
        arg7,
        arg8,
        arg9,
        arg10);
}

struct FUN_00e9ec90 {
    void* m_pData;
    virtual ~FUN_00e9ec90();
    static void operator delete(void* p) { g_memoryManager.Deallocate(p); }
};

// Destructor that frees m_pData with NiFree.
// @fnv 0x00e9ec90
FUN_00e9ec90::~FUN_00e9ec90() {
    NiFree(m_pData);
}

static const void* kNull = 0;
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" void _ReadWriteBarrier();
void* FUN_00aa13e0(unsigned int size);

struct S00e8fa80_Node {
    volatile unsigned int key;
    unsigned char flag;
    void* buffers[5];
    void Initialize() {
        key = 0; flag = 0;
        memset(buffers, 0, sizeof(buffers));
    }
};

struct S00e8fa80_Map {
    unsigned int unk00, unk04, unk08, unk0c;
    bool __thiscall FUN_00a53c30(unsigned int packed, S00e8fa80_Node*& out);
    void __thiscall InsertOrUpdate(unsigned int packed, S00e8fa80_Node* node);
};

struct S00e8fa80_Obj {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    S00e8fa80_Map map1c, map2c, map3c;
    S00e8fa80_Node* GetOrCreateNode(int a, unsigned int b, int c);
};

void* FUN_00aa13e0(unsigned int size);

// Packs a and b into a key, looks up the selected map by c, and creates a new node if the key is not found.
// @fnv 0x00e8fa80
S00e8fa80_Node* S00e8fa80_Obj::GetOrCreateNode(int aiHigh, unsigned int aiLow, int aiMapIndex)
{
    S00e8fa80_Map* map;
    unsigned int packed = aiLow | ((unsigned int)aiHigh << 0x10);
    S00e8fa80_Node* result; memset(&result, 0, sizeof(result));
    switch(aiMapIndex) {
    case 1:
        map = &map2c;
        if (!map->FUN_00a53c30(packed, result)) {
            S00e8fa80_Node* node = (S00e8fa80_Node*)FUN_00aa13e0(0x1c);
            node->Initialize();
            node->key = packed;
            map->InsertOrUpdate(packed, node);
            return node;
        }
        break;
    case 0:
        map = &map1c;
        if (!map->FUN_00a53c30(packed, result)) {
            S00e8fa80_Node* node = (S00e8fa80_Node*)FUN_00aa13e0(0x1c);
            node->Initialize();
            node->key = packed;
            map->InsertOrUpdate(packed, node);
            return node;
        }
        break;
    case 2:
        map = &map3c;
        if (!map->FUN_00a53c30(packed, result)) {
            S00e8fa80_Node* node = (S00e8fa80_Node*)FUN_00aa13e0(0x1c);
            node->Initialize();
            node->key = packed;
            map->InsertOrUpdate(packed, node);
            return node;
        }
        break;
    default: return result;
    }
    return result;
}

struct BlockLink {unsigned int next; unsigned int prev; BlockLink() : next(0), prev(0) {} };
struct AllocationBlock {
    void* unk00;
    void* unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    BlockLink link;
};

struct FUN_00a64330_Obj {
    unsigned int __thiscall FUN_00a64330(AllocationBlock** key);
};

struct BlockAllocator {
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
    FUN_00a64330_Obj unk2C;
    unsigned int __thiscall FUN_00e98660(unsigned int size);
};

extern int DAT_0126fa58;

void AllocateNodeList();

// @fnv 0x00e98660
unsigned int __thiscall BlockAllocator::FUN_00e98660(unsigned int size) {
    if (unk24 < size) {
        return 0;
    }

    if (!DAT_0126fa58) AllocateNodeList();
    AllocationBlock* block=(AllocationBlock*)DAT_0126fa58;
    DAT_0126fa58=(int)((AllocationBlock*)DAT_0126fa58)->link.next;
    if(DAT_0126fa58) ((AllocationBlock*)DAT_0126fa58)->link.prev=0;
    block->link.next=0;
    block->link.prev=0;
    block->unk04 = this;
    block->unk08 = unk08;
    block->unk0C = unk20;
    block->unk14 = size;
    unk20 += size;
    unk24 -= size;
    unk28 -= size;

    AllocationBlock* key = block;
    block->unk00 = (void*)unk2C.FUN_00a64330(&key);
    return (unsigned int)block;
}

namespace fnv_00e88b00 {
extern int DAT_00fdf1c4;
extern int DAT_010ef60c;
extern int DAT_0101dce4;
extern int DAT_011f4400;

typedef int (__stdcall *S_00e88b00_AllocFn)(void*);

struct S_00e88b00_Object {
    virtual void FUN_00e88b00_v0();
    virtual void FUN_00e88b00_v1();
};

struct S_00e88b00_FastObject {
    void* m_vptr;
};

struct S_00e88b00_FastVtable {
    void* unk00;
    void* unk04;
    void (__stdcall *m_fn)(void*);
};

struct S_00e88b00_F8 {
    void __thiscall ReleaseGlobalSlot();
};

struct S_00e88b00_Range {
    __int64 unk100;
    __int64 unk108;
    __int64 unk110;
    __int64 unk118;
    __int64 unk120;
    __int64 unk128;
    __int64 unk130;
    __int64 unk138;
    __int64 unk140;
    __int64 unk148;
    __int64 unk150;
    __int64 unk158;
    __int64 unk160;
    __int64 unk168;
    __int64 unk170;
    __int64 unk178;
    __int64 unk180;
    __int64 unk188;
    __int64 unk190;
    __int64 unk198;
    __int64 unk1a0;
    __int64 unk1a8;
    __int64 unk1b0;
    __int64 unk1b8;
    __int64 unk1c0;
    __int64 unk1c8;
    __int64 unk1d0;
    __int64 unk1d8;
    __int64 unk1e0;
    __int64 unk1e8;
    __int64 unk1f0;
    __int64 unk1f8;
    __int64 unk200;
    __int64 unk208;
    __int64 unk210;
    __int64 unk218;
    __int64 unk220;
    __int64 unk228;
    __int64 unk230;
    __int64 unk238;
    __int64 unk240;
    __int64 unk248;
    __int64 unk250;
    __int64 unk258;
    __int64 unk260;
    __int64 unk268;
    __int64 unk270;
    __int64 unk278;
    __int64 unk280;
    __int64 unk288;
    __int64 unk290;
    __int64 unk298;
    __int64 unk2a0;
    __int64 unk2a8;
    __int64 unk2b0;
    __int64 unk2b8;
    __int64 unk2c0;
    __int64 unk2c8;
    __int64 unk2d0;
    __int64 unk2d8;
    __int64 unk2e0;
    __int64 unk2e8;
    __int64 unk2f0;
    __int64 unk2f8;
    __int64 unk300;
    __int64 unk308;
    __int64 unk310;
    __int64 unk318;
    __int64 unk320;
    __int64 unk328;
    __int64 unk330;
    __int64 unk338;
    __int64 unk340;
    __int64 unk348;
    __int64 unk350;
    __int64 unk358;
    __int64 unk360;
    __int64 unk368;
    __int64 unk370;
    __int64 unk378;
    __int64 unk380;
    __int64 unk388;
    __int64 unk390;
    __int64 unk398;
    __int64 unk3a0;
    __int64 unk3a8;
    __int64 unk3b0;
    __int64 unk3b8;
    __int64 unk3c0;
    __int64 unk3c8;
    __int64 unk3d0;
    __int64 unk3d8;
    __int64 unk3e0;
    __int64 unk3e8;
    __int64 unk3f0;
    __int64 unk3f8;
    __int64 unk400;
    __int64 unk408;
    __int64 unk410;
    __int64 unk418;
    __int64 unk420;
    __int64 unk428;
    __int64 unk430;
    __int64 unk438;
    __int64 unk440;
    __int64 unk448;
    __int64 unk450;
    __int64 unk458;
    __int64 unk460;
    __int64 unk468;
    __int64 unk470;
    __int64 unk478;
    __int64 unk480;
    __int64 unk488;
    __int64 unk490;
    __int64 unk498;
    __int64 unk4a0;
    __int64 unk4a8;
    __int64 unk4b0;
    __int64 unk4b8;
    __int64 unk4c0;
    __int64 unk4c8;
    __int64 unk4d0;
    __int64 unk4d8;
    __int64 unk4e0;
    __int64 unk4e8;
    __int64 unk4f0;
    __int64 unk4f8;
    __int64 unk500;
    __int64 unk508;
    __int64 unk510;
    __int64 unk518;
    __int64 unk520;
    __int64 unk528;
    __int64 unk530;
    __int64 unk538;
    __int64 unk540;
    __int64 unk548;
    __int64 unk550;
    __int64 unk558;
    __int64 unk560;
    __int64 unk568;
    __int64 unk570;
    __int64 unk578;
    __int64 unk580;
    __int64 unk588;
    __int64 unk590;
    __int64 unk598;
    __int64 unk5a0;
    __int64 unk5a8;
    __int64 unk5b0;
    __int64 unk5b8;
    __int64 unk5c0;
    __int64 unk5c8;
    __int64 unk5d0;
    __int64 unk5d8;
    __int64 unk5e0;
    __int64 unk5e8;
    __int64 unk5f0;
    __int64 unk5f8;
    __int64 unk600;
    __int64 unk608;
    __int64 unk610;
    __int64 unk618;
    __int64 unk620;
    __int64 unk628;
    __int64 unk630;
    __int64 unk638;
    __int64 unk640;
    __int64 unk648;
    __int64 unk650;
    __int64 unk658;
    __int64 unk660;
    __int64 unk668;
    __int64 unk670;
    __int64 unk678;
    __int64 unk680;
    __int64 unk688;
    __int64 unk690;
    __int64 unk698;
    __int64 unk6a0;
    __int64 unk6a8;
    __int64 unk6b0;
    __int64 unk6b8;
    __int64 unk6c0;
    __int64 unk6c8;
    __int64 unk6d0;
    __int64 unk6d8;
    __int64 unk6e0;
    __int64 unk6e8;
    __int64 unk6f0;
    __int64 unk6f8;
    __int64 unk700;
    __int64 unk708;
    __int64 unk710;
    __int64 unk718;
    __int64 unk720;
    __int64 unk728;
    __int64 unk730;
    __int64 unk738;
    __int64 unk740;
    __int64 unk748;
    __int64 unk750;
    __int64 unk758;
    __int64 unk760;
    __int64 unk768;
    __int64 unk770;
    __int64 unk778;
    __int64 unk780;
    __int64 unk788;
    __int64 unk790;
    __int64 unk798;
    __int64 unk7a0;
    __int64 unk7a8;
    __int64 unk7b0;
    __int64 unk7b8;
    __int64 unk7c0;
    __int64 unk7c8;
    __int64 unk7d0;
    __int64 unk7d8;
    __int64 unk7e0;
    __int64 unk7e8;
    __int64 unk7f0;
    __int64 unk7f8;
    __int64 unk800;
    __int64 unk808;
    __int64 unk810;
    __int64 unk818;
    __int64 unk820;
    __int64 unk828;
    __int64 unk830;
    __int64 unk838;
    __int64 unk840;
    __int64 unk848;
    __int64 unk850;
    __int64 unk858;
    __int64 unk860;
    __int64 unk868;
    __int64 unk870;
    __int64 unk878;
    __int64 unk880;
    __int64 unk888;
    __int64 unk890;
    __int64 unk898;
    __int64 unk8a0;
    __int64 unk8a8;
    __int64 unk8b0;
    __int64 unk8b8;
    __int64 unk8c0;
    __int64 unk8c8;
    __int64 unk8d0;
    __int64 unk8d8;
    __int64 unk8e0;
    __int64 unk8e8;
    __int64 unk8f0;
    __int64 unk8f8;
    __int64 unk900;
    __int64 unk908;
    __int64 unk910;
    __int64 unk918;
    __int64 unk920;
    __int64 unk928;
    __int64 unk930;
    __int64 unk938;
    __int64 unk940;
    __int64 unk948;
    __int64 unk950;
    __int64 unk958;
    __int64 unk960;
    __int64 unk968;
    __int64 unk970;
    __int64 unk978;
    __int64 unk980;
    __int64 unk988;
    __int64 unk990;
    __int64 unk998;
    __int64 unk9a0;
    __int64 unk9a8;
    __int64 unk9b0;
    __int64 unk9b8;
    __int64 unk9c0;
    __int64 unk9c8;
    __int64 unk9d0;
    __int64 unk9d8;
    __int64 unk9e0;
    __int64 unk9e8;
    __int64 unk9f0;
    __int64 unk9f8;
    __int64 unka00;
    __int64 unka08;
    __int64 unka10;
    __int64 unka18;
    __int64 unka20;
    __int64 unka28;
    __int64 unka30;
    __int64 unka38;
    __int64 unka40;
    __int64 unka48;
    __int64 unka50;
    __int64 unka58;
    __int64 unka60;
    __int64 unka68;
    __int64 unka70;
    __int64 unka78;
    __int64 unka80;
    __int64 unka88;
    __int64 unka90;
    __int64 unka98;
    __int64 unkaa0;
    __int64 unkaa8;
    __int64 unkab0;
    __int64 unkab8;
    __int64 unkac0;
    __int64 unkac8;
    __int64 unkad0;
    __int64 unkad8;
    __int64 unkae0;
    __int64 unkae8;
    __int64 unkaf0;
    __int64 unkaf8;
    __int64 unkb00;
    __int64 unkb08;
    __int64 unkb10;
    __int64 unkb18;
    __int64 unkb20;
    __int64 unkb28;
    __int64 unkb30;
    __int64 unkb38;
    __int64 unkb40;
    __int64 unkb48;
    __int64 unkb50;
    __int64 unkb58;
    __int64 unkb60;
    __int64 unkb68;
    __int64 unkb70;
    __int64 unkb78;
    __int64 unkb80;
    __int64 unkb88;
    __int64 unkb90;
    __int64 unkb98;
    __int64 unkba0;
    __int64 unkba8;
    __int64 unkbb0;
    __int64 unkbb8;
    __int64 unkbc0;
    __int64 unkbc8;
    __int64 unkbd0;
    __int64 unkbd8;
    __int64 unkbe0;
    __int64 unkbe8;
    __int64 unkbf0;
    __int64 unkbf8;
    __int64 unkc00;
    __int64 unkc08;
    __int64 unkc10;
    __int64 unkc18;
    __int64 unkc20;
    __int64 unkc28;
    __int64 unkc30;
    __int64 unkc38;
    __int64 unkc40;
    __int64 unkc48;
    __int64 unkc50;
    __int64 unkc58;
    __int64 unkc60;
    __int64 unkc68;
    __int64 unkc70;
    __int64 unkc78;
    __int64 unkc80;
    __int64 unkc88;
    __int64 unkc90;
    __int64 unkc98;
    __int64 unkca0;
    __int64 unkca8;
    __int64 unkcb0;
    __int64 unkcb8;
    __int64 unkcc0;
    __int64 unkcc8;
    __int64 unkcd0;
    __int64 unkcd8;
    __int64 unkce0;
    __int64 unkce8;
    __int64 unkcf0;
    __int64 unkcf8;
    __int64 unkd00;
    __int64 unkd08;
    __int64 unkd10;
    __int64 unkd18;
    __int64 unkd20;
    __int64 unkd28;
    __int64 unkd30;
    __int64 unkd38;
    __int64 unkd40;
    __int64 unkd48;
    __int64 unkd50;
    __int64 unkd58;
    __int64 unkd60;
    __int64 unkd68;
    __int64 unkd70;
    __int64 unkd78;
    __int64 unkd80;
    __int64 unkd88;
    __int64 unkd90;
    __int64 unkd98;
    __int64 unkda0;
    __int64 unkda8;
    __int64 unkdb0;
    __int64 unkdb8;
    __int64 unkdc0;
    __int64 unkdc8;
    __int64 unkdd0;
    __int64 unkdd8;
    __int64 unkde0;
    __int64 unkde8;
    __int64 unkdf0;
    __int64 unkdf8;
    __int64 unke00;
    __int64 unke08;
    __int64 unke10;
    __int64 unke18;
    __int64 unke20;
    __int64 unke28;
    __int64 unke30;
    __int64 unke38;
    __int64 unke40;
    __int64 unke48;
    __int64 unke50;
    __int64 unke58;
    __int64 unke60;
    __int64 unke68;
    __int64 unke70;
    __int64 unke78;
    __int64 unke80;
    __int64 unke88;
    __int64 unke90;
    __int64 unke98;
    __int64 unkea0;
    __int64 unkea8;
    __int64 unkeb0;
    __int64 unkeb8;
    __int64 unkec0;
    __int64 unkec8;
    __int64 unked0;
    __int64 unked8;
    __int64 unkee0;
    __int64 unkee8;
    __int64 unkef0;
    __int64 unkef8;
    __int64 unkf00;
    __int64 unkf08;
    __int64 unkf10;
    __int64 unkf18;
    __int64 unkf20;
    __int64 unkf28;
    __int64 unkf30;
    __int64 unkf38;
    __int64 unkf40;
    __int64 unkf48;
    __int64 unkf50;
    __int64 unkf58;
    __int64 unkf60;
    __int64 unkf68;
    __int64 unkf70;
    __int64 unkf78;
    __int64 unkf80;
    __int64 unkf88;
    __int64 unkf90;
    __int64 unkf98;
    __int64 unkfa0;
    __int64 unkfa8;
    __int64 unkfb0;
    __int64 unkfb8;
    __int64 unkfc0;
    __int64 unkfc8;
    __int64 unkfd0;
    __int64 unkfd8;
    __int64 unkfe0;
    __int64 unkfe8;
    __int64 unkff0;
    __int64 unkff8;
    __int64 unk1000;
    __int64 unk1008;
    __int64 unk1010;
    __int64 unk1018;
    __int64 unk1020;
    __int64 unk1028;
    __int64 unk1030;
    __int64 unk1038;
    __int64 unk1040;
    __int64 unk1048;
    __int64 unk1050;
    __int64 unk1058;
    __int64 unk1060;
    __int64 unk1068;
    __int64 unk1070;
    __int64 unk1078;
    __int64 unk1080;
    __int64 unk1088;
    __int64 unk1090;
    __int64 unk1098;
    __int64 unk10a0;
    __int64 unk10a8;
    __int64 unk10b0;
    __int64 unk10b8;
    __int64 unk10c0;
    __int64 unk10c8;
    __int64 unk10d0;
    __int64 unk10d8;
    __int64 unk10e0;
    __int64 unk10e8;
    void* volatile unk10f0;
    int unk10f4;
};

struct FUN_00e88b00_Class {
    void* volatile m_vptr;

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

    S_00e88b00_Object* volatile unk74;

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
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;

    S_00e88b00_Object* unkf0;
    int unkf4;
    S_00e88b00_F8 unkf8;
    int unkfc;

    S_00e88b00_Range unk100;

    S_00e88b00_FastObject* unk10f8;
    int unk10fc;

    void __thiscall FUN_00e88b00();
};

// Releases unk74, unk10f8 and unk100's object, calls unkf8.FUN_00e940a0, then sets m_vptr to DAT_0101dce4 and calls DAT_00fdf1c4 on DAT_011f4400.
// @fnv 0x00e88b00
void __thiscall FUN_00e88b00_Class::FUN_00e88b00()
{
    S_00e88b00_AllocFn fn = (S_00e88b00_AllocFn)DAT_00fdf1c4;

    m_vptr = (void*)&DAT_010ef60c;

    S_00e88b00_Object* p = unk74;
    if (p) {
        if (fn((void*)((char*)p + 4)) == 0) {
            p->FUN_00e88b00_v1();
        }
        unk74 = 0;
    }

    unk10fc = 0;

    if (unk10f8) {
        S_00e88b00_FastVtable* vt =
            (S_00e88b00_FastVtable*)unk10f8->m_vptr;
        vt->m_fn(unk10f8);
    }

    *((S_00e88b00_FastObject* volatile*)&unk10f8) = 0;

    p = (S_00e88b00_Object*)unk100.unk10f0;
    if (p) {
        if (fn((void*)((char*)p + 4)) == 0) {
            p->FUN_00e88b00_v1();
        }
    }

    unkf8.ReleaseGlobalSlot();

    S_00e88b00_Object* q = unk74;
    if (q) {
        if (fn((void*)((char*)q + 4)) == 0) {
            q->FUN_00e88b00_v1();
        }
    }

    m_vptr = (void*)&DAT_0101dce4;
    fn((void*)&DAT_011f4400);
}
}  // namespace fnv_00e88b00

namespace fnv_00e8aa70 {
#include <d3d9.h>


extern char DAT_010efcf0[];
extern char* __cdecl GetHResultName(int);
extern void __cdecl FUN_00a29680(char*, char*);

struct CubeTextureResource
{
    bool __thiscall FUN_00e8aa70();
};

// Creates a cube texture on the device and stores it at offset 0x64, or calls FUN_00a29680 with an error string and returns false on failure.
// @fnv 0x00e8aa70
bool __thiscall CubeTextureResource::FUN_00e8aa70()
{
    const D3DFORMAT format =
        *reinterpret_cast<D3DFORMAT*>(reinterpret_cast<char*>(this) + 0x20);
    IDirect3DDevice9* const device =
        *reinterpret_cast<IDirect3DDevice9**>(
            *reinterpret_cast<char**>(reinterpret_cast<char*>(this) + 0x60) + 0x288);
    IDirect3DCubeTexture9* texture = 0;
    HRESULT result = device->CreateCubeTexture(
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x0c),
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x68),
        DAT_0126f0d0 ? 0x200 : 0,
        format,
        DAT_0126f0d0 ? D3DPOOL_DEFAULT : D3DPOOL_MANAGED,
        &texture, 0);

    if (result < 0)
    {
        FUN_00a29680(DAT_010efcf0, GetHResultName(result));
        return false;
    }
    *reinterpret_cast<IDirect3DCubeTexture9**>(reinterpret_cast<char*>(this) + 0x64) = texture;
    return true;
}
}  // namespace fnv_00e8aa70

// Creates and uploads a cube texture resource.

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct TextureSurface;
struct DeviceResource;
struct ResourceConfig;
struct TextureInput;
struct TextureDescription {
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
};
struct ResourceOwner {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    DeviceResource* resource;
};
struct ResourceConfig {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
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
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66c;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67c;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68c;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69c;
    unsigned int unk6a0;
    unsigned int unk6a4;
    unsigned int unk6a8;
    unsigned int unk6ac;
    unsigned int unk6b0;
    unsigned int unk6b4;
    unsigned int unk6b8;
    unsigned int unk6bc;
    unsigned int unk6c0;
    unsigned int unk6c4;
    unsigned int unk6c8;
    unsigned int unk6cc;
    unsigned int unk6d0;
    unsigned int unk6d4;
    unsigned int unk6d8;
    unsigned int unk6dc;
    unsigned int unk6e0;
    unsigned int unk6e4;
    unsigned int unk6e8;
    unsigned int unk6ec;
    unsigned int unk6f0;
    bool mipmaps; unsigned char unk6f5; unsigned short unk6f6;
    unsigned int unk6f8;
    unsigned int unk6fc;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70c;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71c;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72c;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73c;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74c;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75c;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76c;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77c;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78c;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79c;
    unsigned int unk7a0;
    unsigned int unk7a4;
    unsigned int unk7a8;
    unsigned int unk7ac;
    TextureDescription* renderTargets[22];
    unsigned int unk808;
    unsigned int unk80c;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81c;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82c;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83c;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84c;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85c;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86c;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87c;
    unsigned int defaultTarget;
};
struct DirectResource {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    TextureDescription description;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int* width;
    unsigned int* height;
    unsigned int* sizes;
    unsigned int unk070;
    unsigned int levels;
    unsigned int unk078;
    unsigned int faces;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    void* source;

    const TextureDescription& GetDescription() const { return description; }
    unsigned int GetWidth(unsigned int level = 0) const { return width[level]; }
    unsigned int GetHeight(unsigned int level = 0) const { return height[level]; }
    unsigned int GetLevels() const { return levels; }
    unsigned int GetFaces() const { return faces; }
    unsigned int GetSize() const { return sizes[GetLevels()] * GetFaces(); }
    void* GetPalette() const { return source; }
};
struct TextureSurface {
    virtual void v0();
    virtual unsigned long Release();
    volatile long references;
    void IncRefCount() { InterlockedIncrement(&references); }
    void DecRefCount() { if (!InterlockedDecrement(&references)) Release(); }
    TextureDescription description;
    void* source;
    unsigned int unk050;
    unsigned int* width;
    unsigned int* height;
    unsigned int* sizes;
    unsigned int levels;
    unsigned int unk064;
    unsigned int flags;
    unsigned int faces;

    const TextureDescription& GetDescription() const { return description; }
    unsigned int GetWidth(unsigned int level = 0) const { return width[level]; }
    unsigned int GetHeight(unsigned int level = 0) const { return height[level]; }
    unsigned int GetLevels() const { return levels; }
    unsigned int GetFaces() const { return faces; }
    unsigned int GetSize() const { return sizes[GetLevels()] * GetFaces(); }
    void* GetPalette() const { return source; }
    unsigned int GetFlags() const { return flags; }
};
struct TextureInput {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    struct InputDescription { unsigned int unk00, unk04, mode, unk0c, unk10, unk14, unk18; } description;
    void* resourceId;
    DirectResource* direct;
    TextureSurface* surface;
    const InputDescription& GetPreferences() const { return description; }
    DirectResource* GetDirect() const { return direct; }
    TextureSurface* GetSurface() const { return surface; }
    void* GetFilename() const { return resourceId; }
};
struct DeviceResource {
    virtual void Delete(unsigned int);
    unsigned int unk004;
    ResourceOwner* owner;
    unsigned int width;
    unsigned int height;
    TextureDescription description;
    unsigned int unk058;
    unsigned int unk05c;
    ResourceConfig* config;
    void* texture;
    unsigned int levels;
    bool fallback; bool mipmaps; unsigned short unk06e;
    unsigned int bytes;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int flags;

    void SetDescription(const TextureDescription& other) { description = other; }
    void SetDimensions(unsigned int x, unsigned int y) { width = x; height = y; }
    void FUN_00e687a0(TextureInput*, ResourceConfig*);
    bool SetProgram(void*);
    TextureDescription* FUN_00e8a300(TextureDescription*, void*, TextureDescription**);
    bool FUN_00e8aa70();
    void FUN_00e8ab70(DirectResource*, unsigned int);
    void FUN_00e8aaf0(TextureSurface*, unsigned int);
};
struct PlainResource58 {
    void* vtable;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int flags;

    void FUN_00e687a0(TextureInput*, ResourceConfig*);
    PlainResource58(TextureInput* input, ResourceConfig* config) {
        FUN_00e687a0(input, config);
        vtable = &DAT_010efc34;
        flags = 0;
    }
};
struct ResourceManager {
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual TextureSurface* GetTexture(void*, unsigned int, unsigned int);
    virtual void unused4();
    virtual TextureSurface* PrepareTexture(TextureSurface*, TextureDescription*, TextureSurface*, bool);
};
enum AdapterDeviceType { AdapterDeviceDefault = 0 };
enum AdapterFormat { AdapterFormatUnknown = 0 };
struct DepthDevice {
    virtual void __stdcall ReportDiagnostic();
    virtual void __stdcall unused1();
    virtual void __stdcall unused2();
    virtual void __stdcall FlushUsageData();
    virtual void __stdcall unused4();
    virtual void __stdcall unused5();
    virtual void __stdcall unused6();
    virtual void __stdcall unused7();
    virtual void __stdcall unused8();
    virtual void __stdcall unused9();
    virtual long __stdcall CreateResource(unsigned int, AdapterDeviceType, AdapterFormat, int, int, int);
};
struct CreationContext {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
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
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int width;
    AdapterDeviceType deviceType;
    unsigned int unk5cc;
    AdapterFormat adapterFormat;

    void GetCreationInfo(unsigned int& w, AdapterDeviceType& h, AdapterFormat& f) {
        w = width;
        h = deviceType;
        f = adapterFormat;
    }
};
extern void* __cdecl FUN_00aa13e0(unsigned int);
extern TextureSurface* __cdecl DispatchIfHighBitSet(TextureInput*, unsigned int, int);
extern ResourceManager* __cdecl FUN_00a76640();
extern void __cdecl FUN_00a29680(const void*, ...);
extern int __cdecl FUN_00e7bd20(TextureDescription*);
extern char DAT_010efd88, DAT_010ed4dc;
extern unsigned char DAT_011f4508;
extern CreationContext* DAT_011f4748;
extern DepthDevice* DAT_0126f0d8;
extern unsigned int DAT_0126f9bc, DAT_0126f9c0;
inline bool IsPowerOfTwo(unsigned int value) {
    if (value == 0) return false;
    return (value & (value - 1)) == 0;
}

// Creates a DeviceResource from a TextureInput, resolving a surface or direct resource and falling back to a default target when needed.
// @fnv 0x00e8abf0
DeviceResource* __cdecl FUN_00e8abf0(TextureInput* input, ResourceConfig* config)
{
    TextureDescription** renderTargets = config->renderTargets;
    unsigned int slot = 0;
    for (; slot < 22; slot += 2) {
        if (renderTargets[slot]) break;
        if (renderTargets[slot + 1]) { ++slot; break; }
    }
    if (slot == 22) {
        FUN_00a29680(&DAT_010efd88);
        return 0;
    }
    void* allocation = FUN_00aa13e0(0x88);
    DeviceResource* result = allocation ? reinterpret_cast<DeviceResource*>(new (allocation) PlainResource58(input, config)) : 0;
    DirectResource* directResource = input->GetDirect();
    const TextureInput::InputDescription& preferences = input->GetPreferences();
    void* textureDescription = const_cast<TextureInput::InputDescription*>(&preferences);
    TextureSurface* surface = 0;
    if (!directResource) {
        surface = input->GetSurface();
        if (!surface) {
            void* resourceId = input->GetFilename();
            if (resourceId) {
                ResourceManager* manager = FUN_00a76640();
                surface = manager->GetTexture(resourceId, (unsigned int)directResource, (unsigned int)directResource);
            } else {
                surface = DispatchIfHighBitSet(input, 0x80000008, 1);
                result->fallback = true;
            }
        }
    }
    TextureDescription* prepared = 0;
    if (!directResource && !surface) {
        surface = DispatchIfHighBitSet(input, 0x80000008, 1);
        result->fallback = true;
        FUN_00a29680(&DAT_010ed4dc, input->GetFilename());
    } else if (directResource) {
        TextureDescription* description = const_cast<TextureDescription*>(&directResource->GetDescription());
        unsigned int width = directResource->GetWidth();
        unsigned int height = directResource->GetHeight();
        if (width == height && IsPowerOfTwo(width)) {
            prepared = result->FUN_00e8a300(description, textureDescription, renderTargets);
            if (!prepared) {
                surface = DispatchIfHighBitSet(input, 0x80000007, 1);
                result->fallback = true;
            }
        } else {
            surface = DispatchIfHighBitSet(input, 0x80000009, 1);
            result->fallback = true;
        }
        if (!result->fallback) {
            int handle = FUN_00e7bd20(description);
            if (!handle) {
                surface = DispatchIfHighBitSet(input, 0x80000007, 1);
                result->fallback = true;
            } else {
                AdapterFormat format = DAT_011f4748->adapterFormat;
                DepthDevice* dev = DAT_0126f0d8;
                AdapterDeviceType type = DAT_011f4748->deviceType;
                unsigned int width = DAT_011f4748->width;
                long error = dev->CreateResource(width, type, format, 0, 3, handle);
                if (error < 0) {
                    surface = DispatchIfHighBitSet(input, 0x80000007, 1);
                    result->fallback = true;
                } else directResource->description.unk0c = handle;
            }
        }
    } else {
        TextureDescription* description = const_cast<TextureDescription*>(&surface->GetDescription());
        unsigned int width = surface->GetWidth();
        unsigned int height = surface->GetHeight();
        if (width == height && IsPowerOfTwo(width)) {
            prepared = result->FUN_00e8a300(description, textureDescription, renderTargets);
            if (!prepared || (description->unk04 == 2 || description->unk04 == 3)) {
                surface = DispatchIfHighBitSet(input, 0x80000007, 1);
                result->fallback = true;
            }
        } else {
            surface = DispatchIfHighBitSet(input, 0x80000009, 1);
            result->fallback = true;
        }
    }
    if (result->fallback) {
        prepared = renderTargets[config->defaultTarget];
        directResource = 0;
    }
    if (directResource) {
        result->description = directResource->GetDescription();
        result->width = directResource->GetWidth();
        result->height = directResource->GetHeight();
        unsigned int count = config->mipmaps ? directResource->GetLevels() : 1;
        result->levels = count;
        result->mipmaps = count != 1;
        result->config = config;
        result->fallback = false;
        result->SetProgram(directResource->GetPalette());
        result->bytes = directResource->GetSize();
        if (result->FUN_00e8aa70() && result->texture) {
            unsigned int bytes = result->bytes;
            DAT_0126f9bc += bytes;
            unsigned int pad = 0;
            if ((bytes & 0xfffff000) != bytes) pad = ((bytes & 0xfffff000) - bytes) + 0x1000;
            DAT_0126f9c0 += pad;
            for (slot = 0; slot < 6; ++slot) result->FUN_00e8ab70(directResource, slot);
            goto succeeded;
        }
        goto failed;
    } else {
        TextureSurface* preparedSurface;
        if (result->fallback) {
            preparedSurface = surface;
        } else {
            ResourceManager* manager = FUN_00a76640();
            preparedSurface = manager->PrepareTexture(surface, prepared, surface, result->mipmaps);
        }
        if (!preparedSurface) {
            preparedSurface = DispatchIfHighBitSet(input, 0x80000007, 1);
            prepared = renderTargets[config->defaultTarget];
        }
        result->flags = surface->GetFlags();
        result->description = *prepared;
        result->width = result->height = preparedSurface->GetWidth();
        if ((!result->fallback && preferences.mode == 1) ||
            (preferences.mode == 2 && DAT_011f4508 && config->mipmaps)) result->mipmaps = true;
        else result->mipmaps = false;
        result->levels = config->mipmaps ? preparedSurface->GetLevels() : 1;
        if (result->FUN_00e8aa70() && result->texture) {
            if (preparedSurface->GetFaces() != 6) {
                result->Delete(1);
                return 0;
            }
            for (slot = 0; slot < 6; ++slot) result->FUN_00e8aaf0(preparedSurface, slot);
            
            result->SetProgram(surface->GetPalette());
            unsigned int bytes = preparedSurface->GetSize();
            result->bytes = bytes;
            DAT_0126f9bc += bytes;
            unsigned int pad = 0;
            if ((bytes & 0xfffff000) != bytes) pad = ((bytes & 0xfffff000) - bytes) + 0x1000;
            DAT_0126f9c0 += pad;
            preparedSurface->IncRefCount();
            preparedSurface->DecRefCount();
            goto succeeded;
        }
    }
failed:
    result->Delete(1);
    return 0;
succeeded:
    result->owner->resource = result;
    return result;
}

struct ShaderComponent093 {
    int type;
    int format;
    char width;
    char flag;
    short unk0a;
};
struct ShaderRequest093 {
    unsigned int FUN_00e8a240();
    int unknown00;
    unsigned int kind;
    int disabled;
    int unk0c;
    int unk10;
    ShaderComponent093 components[4];
};
struct ShaderTraits093 { int kind; int ordering; };
struct ShaderChoices093 {
    void* choice00;
    void* choice04;
    void* choice08;
    void* choice0c;
    void* choice10;
    void* choice14;
    void* choice18;
    void* choice1c;
    void* choice20;
    void* choice24;
    void* choice28;
    void* choice2c;
    void* choice30;
    void* choice34;
    void* choice38;
    void* choice3c;
    void* choice40;
    void* choice44;
    void* choice48;
    void* choice4c;
    void* choice50;
    void* choice54;
};
struct ShaderValidator093 {
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual bool Accept(ShaderRequest093*, void*);
};
struct PixelComponentReader093 {
    char GetEntryData(int, int*, int*, char*, char*);
};

__declspec(noinline) char PixelComponentReader093::GetEntryData(int index, int* type, int* format, char* width, char* flag) {
    ShaderRequest093* request = (ShaderRequest093*)this;
    *flag = request->components[index].flag;
    *width = request->components[index].width;
    *format = request->components[index].format;
    *type = request->components[index].type;
    return *type != 19;
}
// Returns the first choice that validator->Accept accepts for the request, trying choices in an order set by request kind and traits; returns 0 if none.
// @fnv 0x00e8a300
void* __stdcall FUN_00e8a300(ShaderRequest093* request, ShaderTraits093* traits, ShaderChoices093* choices)
{
    int type;
    int format;
    char flag;
    char width;
    unsigned int kind = request->kind;
    ShaderValidator093* validator = (ShaderValidator093*)FUN_00a76640();
    if (request->disabled) return 0;
    void* candidate;
    if (traits->kind == 4) {
        if (kind != 9 && kind != 1) {
            candidate = choices->choice2c;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice34;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice30;
            if (candidate && validator->Accept(request, candidate)) return candidate;
        } else {
            candidate = choices->choice34;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice30;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice2c;
            if (candidate && validator->Accept(request, candidate)) return candidate;
        }
        return 0;
    }
    switch (kind) {
    case 0:
    case 2:
        if (traits->kind == 3) {
            candidate = choices->choice20;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice24;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice28;
            if (candidate && validator->Accept(request, candidate)) return candidate;
        }
        if (traits->kind == 1) {
            candidate = choices->choice04;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice00;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice08;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice14;
            if (candidate && validator->Accept(request, candidate)) return candidate;
        } else {
            candidate = choices->choice08;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice14;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice04;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice00;
            if (candidate && validator->Accept(request, candidate)) return candidate;
        }
        candidate = choices->choice0c;
        if (candidate && validator->Accept(request, candidate)) return candidate;
        candidate = choices->choice10;
        if (candidate && validator->Accept(request, candidate)) return candidate;
        return 0;
    case 4:
        if (traits->kind != 1 && traits->kind != 2) {
            candidate = choices->choice20;
            if (candidate && validator->Accept(request, candidate)) return candidate;
        }
        break;
    case 5:
        if (traits->kind != 1 && traits->kind != 2) {
            candidate = choices->choice24;
            if (candidate && validator->Accept(request, candidate)) return candidate;
        }
        break;
    case 6:
        if (traits->kind != 1 && traits->kind != 2) {
            candidate = choices->choice28;
            if (candidate && validator->Accept(request, candidate)) return candidate;
        }
        break;
    case 8:
        candidate = choices->choice2c;
        if (candidate && validator->Accept(request, candidate)) return candidate;
        candidate = choices->choice34;
        if (candidate && validator->Accept(request, candidate)) return candidate;
        candidate = choices->choice30;
        if (candidate && validator->Accept(request, candidate)) return candidate;
        return 0;
    case 9:
        candidate = choices->choice30;
        if (candidate && validator->Accept(request, candidate)) return candidate;
        candidate = choices->choice34;
        if (candidate && validator->Accept(request, candidate)) return candidate;
        candidate = choices->choice2c;
        if (candidate && validator->Accept(request, candidate)) return candidate;
        return 0;
    case 11:
        if (traits->ordering == 2) {
            candidate = choices->choice3c;
            if (candidate && validator->Accept(request, candidate)) return candidate;
        } else {
            candidate = choices->choice38;
            if (candidate && validator->Accept(request, candidate)) return candidate;
        }
        break;
    case 1: case 3: case 12: case 13: case 14:
        break;
    default: return 0;
    }
    type = 19;
    format = 5;
    width = 0;
    if (((PixelComponentReader093*)request)->GetEntryData(0, &type, &format, (char*)&width, (char*)&flag) && (format == 2 || format == 1)) {
        unsigned int count = request->FUN_00e8a240();
        if (width == 16) {
            if (count < 2) {
                candidate = choices->choice40;
                if (candidate && validator->Accept(request, candidate)) return candidate;
                candidate = choices->choice4c;
                if (candidate && validator->Accept(request, candidate)) return candidate;
            }
            if (count < 3) {
                candidate = choices->choice44;
                if (candidate && validator->Accept(request, candidate)) return candidate;
                candidate = choices->choice50;
                if (candidate && validator->Accept(request, candidate)) return candidate;
            }
            candidate = choices->choice48;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice54;
            if (candidate && validator->Accept(request, candidate)) return candidate;
        } else if (width == 32) {
            if (count < 2) {
                candidate = choices->choice4c;
                if (candidate && validator->Accept(request, candidate)) return candidate;
            }
            if (count < 3) {
                candidate = choices->choice50;
                if (candidate && validator->Accept(request, candidate)) return candidate;
            }
            candidate = choices->choice54;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            if (count < 2) {
                candidate = choices->choice40;
                if (candidate && validator->Accept(request, candidate)) return candidate;
            }
            if (count < 3) {
                candidate = choices->choice44;
                if (candidate && validator->Accept(request, candidate)) return candidate;
            }
            candidate = choices->choice48;
            if (candidate && validator->Accept(request, candidate)) return candidate;
        }
    }
    if (traits->kind == 3) {
        if (traits->ordering == 1) {
            candidate = choices->choice20;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice24;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice28;
            if (candidate && validator->Accept(request, candidate)) return candidate;
        } else {
            candidate = choices->choice24;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice28;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice20;
            if (candidate && validator->Accept(request, candidate)) return candidate;
        }
    }
    if (traits->kind == 1) {
        if (traits->ordering == 1) {
            candidate = choices->choice0c;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice10;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice14;
            if (candidate && validator->Accept(request, candidate)) return candidate;
        } else {
            candidate = choices->choice10;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice14;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice0c;
            if (candidate && validator->Accept(request, candidate)) return candidate;
        }
    } else {
        candidate = choices->choice14;
        if (candidate && validator->Accept(request, candidate)) return candidate;
        if (traits->ordering == 1) {
            candidate = choices->choice0c;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice10;
            if (candidate && validator->Accept(request, candidate)) return candidate;
        } else {
            candidate = choices->choice10;
            if (candidate && validator->Accept(request, candidate)) return candidate;
            candidate = choices->choice0c;
            if (candidate && validator->Accept(request, candidate)) return candidate;
        }
    }
    return 0;
}

struct FUN_00e8b0c0_Item {
    char m_uiStandInValue[0x4c];
    void* m_4c;
    char m_iValueAfterStandIn[0x68 - 0x50];
    int m_68;
};

struct FUN_00e8b0c0_Owner {
    char m_auiShapeKeys[0x3c];
    FUN_00e8b0c0_Item* m_3c;
};

struct FUN_00e8b0c0_Ret {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual FUN_00e8b0c0_Ret* v5(FUN_00e8b0c0_Item* a, void* b, FUN_00e8b0c0_Item* c, unsigned char d);
    int m_04;
    char m_auiShapeKeys[0x6c - 0x08];
    unsigned int m_6c;
};

struct FUN_00e8b0c0_Class {
    char m_00[8];
    FUN_00e8b0c0_Owner* m_08;
    char m_0c[8];
    char m_14[0x50];
    int m_64;
    char m_68[4];
    unsigned char m_6c;
    unsigned char m_6d;
    char m_6e[0x84 - 0x6e];
    int m_84;

    void __thiscall FUN_00e8b0c0();
    void __thiscall FUN_00e8aaf0(FUN_00e8b0c0_Ret* p, int idx);
};

extern "C" bool __stdcall SetProgram(void* a);

// If the item at m_08->m_3c changed (m_68 != m_84 or FUN_00e68760 true), calls v5, sets m_84, and calls FUN_00e8aaf0 per entry of the result if m_64.
// @fnv 0x00e8b0c0
void FUN_00e8b0c0_Class::FUN_00e8b0c0()
{
    if (m_6c != 0) {
        return;
    }
    bool found = false;
    FUN_00e8b0c0_Item* a = m_08->m_3c;
    if (a == 0) {
        return;
    }
    void* t4c = a->m_4c;
    if (SetProgram(t4c) != 0) {
        found = true;
    }
    if (a->m_68 == m_84 && !found) {
        return;
    }
    FUN_00e8b0c0_Ret* pResult = ((FUN_00e8b0c0_Ret*)FUN_00a76640())->v5(a, m_14, a, m_6d);
    m_84 = a->m_68;
    if (m_64 != 0) {
        for (unsigned int i = 0; i < pResult->m_6c; i++) {
            FUN_00e8aaf0(pResult, i);
        }
    }
    if (pResult != 0) {
        InterlockedIncrement((long volatile*)((char*)pResult + 4));
        if (InterlockedDecrement((long volatile*)((char*)pResult + 4)) == 0) {
            return pResult->v1();
        }
    }
}

struct FUN_00e98910_Target {
    virtual void vf00();
    virtual int __stdcall vf04();
};

extern int DAT_0101dce4;
extern int DAT_010f16cc;

struct FUN_00e98910_Class {
    int* unk00;
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
    FUN_00e98910_Target* unk80;
    void* unk84;

    FUN_00e98910_Class* __thiscall FUN_00e98910(int* context);
};

// @fnv 0x00e98910
FUN_00e98910_Class* __thiscall
FUN_00e98910_Class::FUN_00e98910(int* context) {
    this->unk00 = &DAT_0101dce4;
    this->unk04 = 0;

    InterlockedIncrement(&DAT_011f4400);

    this->unk00 = &DAT_010f16cc;
    this->unk08 = 0;
    this->unk0C = 0;
    this->unk10 = 0;
    this->unk14 = 0;
    this->unk18 = 0;
    this->unk1C = 0;
    this->unk20 = 0;
    this->unk24 = 0;
    this->unk28 = 0;
    this->unk2C = 0;
    this->unk30 = 0;
    this->unk34 = 0;
    this->unk38 = 0;
    this->unk3C = 0;
    this->unk40 = 0;
    this->unk44 = 0;
    this->unk48 = 0;
    this->unk4C = 0;
    this->unk50 = 0;
    this->unk54 = 0;
    this->unk58 = 0;
    this->unk5C = 0;
    this->unk60 = 0;
    this->unk64 = 0;
    this->unk68 = 0;
    this->unk6C = 0;
    this->unk70 = 0;
    this->unk74 = 0;
    this->unk78 = 0;
    this->unk7C = 0;
    this->unk84 = context;

    if (context != 0) {
        this->unk80 = reinterpret_cast<FUN_00e98910_Target*>(
            *reinterpret_cast<int*>(reinterpret_cast<char*>(context) + 0x288));
    }

    if (this->unk80 != 0) {
        this->unk80->vf04();
    }

    return this;
}

extern "C" void __cdecl NiFree(void*);
extern "C" void __cdecl FUN_00aa1490(void*, unsigned int);

struct E895A0_Sdo {
    void FUN_00e89560();
    void* DestroyScalarObject(unsigned char flags);
};

struct E895A0_Node : E895A0_Sdo {
    void* m_block;
    int m_04;
    E895A0_Node* m_next;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
};

struct E895A0_Object {
    void* m_00;
    int m_04;
    int m_08;
    E895A0_Node* m_0c;
    void __thiscall FUN_00e895a0();
};

// Sets m_08 to 0, frees node m_0c's block, calls FUN_00e89440(1) on its next node, deallocates the node, then calls NiFree on m_00.
// @fnv 0x00e895a0
void E895A0_Object::FUN_00e895a0()
{
    E895A0_Node* node = m_0c;
    m_08 = 0;
    if (node) {
        if (node->m_block)
            FUN_00aa1490((char*)node->m_block - 4, 0xb8);
        if (node->m_next)
            node->m_next->DestroyScalarObject(1);
        g_memoryManager.Deallocate(node);
    }
    NiFree(m_00);
}

extern "C++" void __cdecl operator delete(void*, int);
struct E95B80SV { void FUN_00e95b80(); };
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* p);
extern unsigned char kVtbl_NiDX9IndexBufferManager;

class NiRefObject2
{
public:
    virtual ~NiRefObject2() { InterlockedDecrement(&DAT_011f4400); }
    virtual void DeleteThis();

    unsigned int m_uiRefCount;
};

struct D3DResourceE8F
{
    virtual long __stdcall QueryInterface(void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

struct D3DDeviceE8F : D3DResourceE8F
{
    virtual void __stdcall V003();
    virtual void __stdcall V004();
    virtual void __stdcall V005();
    virtual void __stdcall V006();
    virtual void __stdcall V007();
    virtual void __stdcall V008();
    virtual void __stdcall V009();
    virtual void __stdcall V010();
    virtual void __stdcall V011();
    virtual void __stdcall V012();
    virtual void __stdcall V013();
    virtual void __stdcall V014();
    virtual void __stdcall V015();
    virtual void __stdcall V016();
    virtual void __stdcall V017();
    virtual void __stdcall V018();
    virtual void __stdcall V019();
    virtual void __stdcall V020();
    virtual void __stdcall V021();
    virtual void __stdcall V022();
    virtual void __stdcall V023();
    virtual void __stdcall V024();
    virtual void __stdcall V025();
    virtual void __stdcall V026();
    virtual void __stdcall V027();
    virtual void __stdcall V028();
    virtual void __stdcall V029();
    virtual void __stdcall V030();
    virtual void __stdcall V031();
    virtual void __stdcall V032();
    virtual void __stdcall V033();
    virtual void __stdcall V034();
    virtual void __stdcall V035();
    virtual void __stdcall V036();
    virtual void __stdcall V037();
    virtual void __stdcall V038();
    virtual void __stdcall V039();
    virtual void __stdcall V040();
    virtual void __stdcall V041();
    virtual void __stdcall V042();
    virtual void __stdcall V043();
    virtual void __stdcall V044();
    virtual void __stdcall V045();
    virtual void __stdcall V046();
    virtual void __stdcall V047();
    virtual void __stdcall V048();
    virtual void __stdcall V049();
    virtual void __stdcall V050();
    virtual void __stdcall V051();
    virtual void __stdcall V052();
    virtual void __stdcall V053();
    virtual void __stdcall V054();
    virtual void __stdcall V055();
    virtual void __stdcall V056();
    virtual void __stdcall V057();
    virtual void __stdcall V058();
    virtual void __stdcall V059();
    virtual void __stdcall V060();
    virtual void __stdcall V061();
    virtual void __stdcall V062();
    virtual void __stdcall V063();
    virtual void __stdcall V064();
    virtual void __stdcall V065();
    virtual void __stdcall V066();
    virtual void __stdcall V067();
    virtual void __stdcall V068();
    virtual void __stdcall V069();
    virtual void __stdcall V070();
    virtual void __stdcall V071();
    virtual void __stdcall V072();
    virtual void __stdcall V073();
    virtual void __stdcall V074();
    virtual void __stdcall V075();
    virtual void __stdcall V076();
    virtual void __stdcall V077();
    virtual void __stdcall V078();
    virtual void __stdcall V079();
    virtual void __stdcall V080();
    virtual void __stdcall V081();
    virtual void __stdcall V082();
    virtual void __stdcall V083();
    virtual void __stdcall V084();
    virtual void __stdcall V085();
    virtual void __stdcall V086();
    virtual void __stdcall V087();
    virtual void __stdcall V088();
    virtual void __stdcall V089();
    virtual void __stdcall V090();
    virtual void __stdcall V091();
    virtual void __stdcall V092();
    virtual void __stdcall V093();
    virtual void __stdcall V094();
    virtual void __stdcall V095();
    virtual void __stdcall V096();
    virtual void __stdcall V097();
    virtual void __stdcall V098();
    virtual void __stdcall V099();
    virtual void __stdcall V100();
    virtual void __stdcall V101();
    virtual void __stdcall V102();
    virtual void __stdcall V103();
    virtual long __stdcall SetIndices(D3DResourceE8F* pkIndexData);
};

struct IBEntryE8F
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    D3DResourceE8F* m_pkIndexBuffer;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
};

struct IBArrayE8F
{
    unsigned int m_uiUnk00;
    unsigned int m_uiUnk04;
    IBEntryE8F* m_apkEntries[5];
};

struct MapItemE8F
{
    MapItemE8F* m_pkNext;
    unsigned int m_uiKey;
    IBArrayE8F* m_pkVal;
};

class PointerMapE8F
{
public:
    virtual ~PointerMapE8F();
    virtual unsigned int KeyToHashIndex(unsigned int uiKey) const;

    void* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }

    void GetNext(void*& pos, unsigned int& uiKey, IBArrayE8F*& pkVal) const
    {
        MapItemE8F* pkItem = (MapItemE8F*)pos;
        uiKey = pkItem->m_uiKey;
        pkVal = pkItem->m_pkVal;
        if (pkItem->m_pkNext)
        {
            pos = pkItem->m_pkNext;
            return;
        }
        unsigned int i = KeyToHashIndex(pkItem->m_uiKey);
        for (++i; i < m_uiHashSize; i++)
        {
            pkItem = m_ppkHashTable[i];
            if (pkItem)
            {
                pos = pkItem;
                return;
            }
        }
        pos = 0;
    }

    void RemoveAll() { ((NiTMapBaseStub*)this)->RemoveAll(); }

    void Destroy()
    {
        *(void**)this = DAT_010f02d0;
        RemoveAll();
        *(void**)this = DAT_010f02b0;
        RemoveAll();
        NiFree(m_ppkHashTable);
    }

    unsigned int m_uiHashSize;
    MapItemE8F** m_ppkHashTable;
    unsigned int m_uiCount;
};

class IndexBufferOwnerE8F : public NiRefObject2
{
public:
    D3DDeviceE8F* m_pD3DDevice;
    D3DResourceE8F* m_pkUnk0C;
    unsigned int m_uiUnk10;
    D3DResourceE8F* m_pkUnk14;
    unsigned int m_uiUnk18;
    PointerMapE8F m_kMap0;
    PointerMapE8F m_kMap1;
    PointerMapE8F m_kMap2;

    void FUN_00e8f840();
};

// Releases all index buffers and arrays in the three maps, clears device indices, releases device resources, and destroys the maps.
// @fnv 0x00e8f840
void IndexBufferOwnerE8F::FUN_00e8f840()
{
    *(void**)this = &kVtbl_NiDX9IndexBufferManager;

    for (unsigned int i = 0; i < 3; i++)
    {
        PointerMapE8F* pkMap;
        switch (i)
        {
        case 0:
            pkMap = &m_kMap0;
            break;
        case 1:
            pkMap = &m_kMap1;
            break;
        case 2:
            pkMap = &m_kMap2;
            break;
        }

        void* pos = pkMap->GetFirstPos();
        while (pos)
        {
            unsigned int uiKey;
            IBArrayE8F* pkArray;
            pkMap->GetNext(pos, uiKey, pkArray);
            if (pkArray)
            {
                for (unsigned int j = 0; j < 5; j++)
                {
                    IBEntryE8F* pkEntry = pkArray->m_apkEntries[j];
                    if (pkEntry)
                    {
                        D3DResourceE8F* pkIB = pkEntry->m_pkIndexBuffer;
                        if (pkIB)
                            pkIB->Release();
                        ((E95B80SV*)pkEntry)->FUN_00e95b80();
                        operator delete(pkEntry, 0x38);
                    }
                }
                operator delete(pkArray, 0x1c);
            }
        }
    }

    m_kMap0.RemoveAll();
    m_kMap1.RemoveAll();
    m_kMap2.RemoveAll();

    m_pD3DDevice->SetIndices(0);

    if (m_pkUnk0C)
        m_pkUnk0C->Release();
    if (m_pkUnk14)
        m_pkUnk14->Release();
    if (m_pD3DDevice)
    {
        m_pD3DDevice->Release();
        m_pD3DDevice = 0;
    }

    m_kMap2.Destroy();
    m_kMap1.Destroy();
    m_kMap0.Destroy();

    this->NiRefObject2::~NiRefObject2();
}

using ::ConstantTarget;
using ::Vec4;
namespace ShaderSubtractData {
    extern "C" Vec4 DAT_0126f8a0;
    extern "C" Vec4 DAT_0126f8b0;
    extern "C" Vec4 DAT_0126f900;
}

// Subtracts DAT_0126f8b0 from DAT_0126f8a0 into DAT_0126f900 based on typeA and typeB, then calls target->SetConstant(reg, &DAT_0126f900.x, 0).
// @fnv 0x00e83320
int __stdcall FUN_00e83320(ConstantTarget* target, int reg, int typeA, int typeB, int aiUnused5, int aiUnused6) {
    switch (typeA) {
        case 3:
        case 4:
            switch (typeB) {
                case 3:
                case 4: {
                    Vec4 v;
                    v.x = ShaderSubtractData::DAT_0126f8a0.x - ShaderSubtractData::DAT_0126f8b0.x;
                    v.y = ShaderSubtractData::DAT_0126f8a0.y - ShaderSubtractData::DAT_0126f8b0.y;
                    v.z = ShaderSubtractData::DAT_0126f8a0.z - ShaderSubtractData::DAT_0126f8b0.z;
                    v.w = ShaderSubtractData::DAT_0126f8a0.w - ShaderSubtractData::DAT_0126f8b0.w;
                    ShaderSubtractData::DAT_0126f900 = v;
                    return target->SetConstant(reg, &ShaderSubtractData::DAT_0126f900.x, 0) ? 0 : 0x50;
                }
                case 7:
                case 10:
                    ShaderSubtractData::DAT_0126f900.x = ShaderSubtractData::DAT_0126f8a0.x - ShaderSubtractData::DAT_0126f8b0.x;
                    ShaderSubtractData::DAT_0126f900.y = ShaderSubtractData::DAT_0126f8a0.x - ShaderSubtractData::DAT_0126f8b0.y;
                    ShaderSubtractData::DAT_0126f900.z = ShaderSubtractData::DAT_0126f8a0.x - ShaderSubtractData::DAT_0126f8b0.z;
                    ShaderSubtractData::DAT_0126f900.w = ShaderSubtractData::DAT_0126f8a0.x - ShaderSubtractData::DAT_0126f8b0.w;
                    return target->SetConstant(reg, &ShaderSubtractData::DAT_0126f900.x, 0) ? 0 : 0x50;
            }
            break;
        case 7:
        case 10:
            switch (typeB) {
                case 3:
                case 4:
                    ShaderSubtractData::DAT_0126f900.x = ShaderSubtractData::DAT_0126f8a0.x - ShaderSubtractData::DAT_0126f8b0.x;
                    ShaderSubtractData::DAT_0126f900.y = ShaderSubtractData::DAT_0126f8a0.y - ShaderSubtractData::DAT_0126f8b0.x;
                    ShaderSubtractData::DAT_0126f900.z = ShaderSubtractData::DAT_0126f8a0.z - ShaderSubtractData::DAT_0126f8b0.x;
                    ShaderSubtractData::DAT_0126f900.w = ShaderSubtractData::DAT_0126f8a0.w - ShaderSubtractData::DAT_0126f8b0.x;
                    return target->SetConstant(reg, &ShaderSubtractData::DAT_0126f900.x, 0) ? 0 : 0x50;
                case 7:
                case 10:
                    ShaderSubtractData::DAT_0126f900.x = ShaderSubtractData::DAT_0126f8a0.x - ShaderSubtractData::DAT_0126f8b0.x;
                    ShaderSubtractData::DAT_0126f900.y = ShaderSubtractData::DAT_0126f8a0.y - ShaderSubtractData::DAT_0126f8b0.y;
                    ShaderSubtractData::DAT_0126f900.z = ShaderSubtractData::DAT_0126f8a0.z - ShaderSubtractData::DAT_0126f8b0.z;
                    ShaderSubtractData::DAT_0126f900.w = ShaderSubtractData::DAT_0126f8a0.w - ShaderSubtractData::DAT_0126f8b0.w;
                    return target->SetConstant(reg, &ShaderSubtractData::DAT_0126f900.x, 0) ? 0 : 0x50;
            }
            break;
    }
    return 1;
}

using ::ConstantTarget;
using ::Vec4;

namespace ShaderDivideDetail {
    extern "C" Vec4 DAT_0126f8a0;
    extern "C" Vec4 DAT_0126f8b0;
    extern "C" Vec4 DAT_0126f900;
}

struct S00e82e70_D3DXMATRIX {
    float _11, _12, _13, _14;
    float _21, _22, _23, _24;
    float _31, _32, _33, _34;
    float _41, _42, _43, _44;
};

extern S00e82e70_D3DXMATRIX DAT_0126f820;
extern S00e82e70_D3DXMATRIX DAT_0126f8c0;

extern "C" {
    S00e82e70_D3DXMATRIX* __stdcall D3DXMatrixInverse(S00e82e70_D3DXMATRIX* pOut, float* pDeterminant, const S00e82e70_D3DXMATRIX* pM);
    S00e82e70_D3DXMATRIX* __stdcall D3DXMatrixTranspose(S00e82e70_D3DXMATRIX* pOut, const S00e82e70_D3DXMATRIX* pM);
}

// Computes a divided matrix or vector from DAT_0126f820/DAT_0126f8a0 by DAT_0126f8b0, optionally inverting/transposing, then calls target->SetConstant.
// @fnv 0x00e82e70
int __stdcall FUN_00e82e70(ConstantTarget* target, int aiRegister, int type1, int type2, bool abInverse, bool abTranspose) {
    switch (type1) {
    case 9: {
        if (type2 < 3) {
            return 1;
        }
        if (type2 > 4) {
            return 1;
        }
        S00e82e70_D3DXMATRIX mat;
        float inv = 1.0f / ShaderDivideDetail::DAT_0126f8b0.x;
        mat._11 = DAT_0126f820._11 * inv;
        mat._12 = DAT_0126f820._12 * inv;
        mat._13 = DAT_0126f820._13 * inv;
        mat._14 = DAT_0126f820._14 * inv;
        mat._21 = DAT_0126f820._21 * inv;
        mat._22 = DAT_0126f820._22 * inv;
        mat._23 = DAT_0126f820._23 * inv;
        mat._24 = DAT_0126f820._24 * inv;
        mat._31 = DAT_0126f820._31 * inv;
        mat._32 = DAT_0126f820._32 * inv;
        mat._33 = DAT_0126f820._33 * inv;
        mat._34 = DAT_0126f820._34 * inv;
        mat._41 = DAT_0126f820._41 * inv;
        mat._42 = DAT_0126f820._42 * inv;
        mat._43 = DAT_0126f820._43 * inv;
        mat._44 = DAT_0126f820._44 * inv;
        DAT_0126f8c0 = mat;

        if (abInverse) {
            D3DXMatrixInverse(&DAT_0126f8c0, 0, &DAT_0126f8c0);
        }
        if (abTranspose) {
            D3DXMatrixTranspose(&DAT_0126f8c0, &DAT_0126f8c0);
        }
        return target->SetConstant(aiRegister, (const float*)&DAT_0126f8c0, 0) ? 0 : 0x50;
    }

    case 7:
    case 10:
        switch (type2) {
        case 3:
        case 4: {
            float inv = 1.0f / ShaderDivideDetail::DAT_0126f8b0.x;
            ShaderDivideDetail::DAT_0126f900.x = ShaderDivideDetail::DAT_0126f8a0.x * inv;
            ShaderDivideDetail::DAT_0126f900.y = ShaderDivideDetail::DAT_0126f8a0.y * inv;
            ShaderDivideDetail::DAT_0126f900.z = ShaderDivideDetail::DAT_0126f8a0.z * inv;
            ShaderDivideDetail::DAT_0126f900.w = ShaderDivideDetail::DAT_0126f8a0.w * inv;
            return target->SetConstant(aiRegister, (const float*)&ShaderDivideDetail::DAT_0126f900, 0) ? 0 : 0x50;
        }
        case 7:
        case 10: {
            ShaderDivideDetail::DAT_0126f900.x = ShaderDivideDetail::DAT_0126f8a0.x / ShaderDivideDetail::DAT_0126f8b0.x;
            ShaderDivideDetail::DAT_0126f900.y = ShaderDivideDetail::DAT_0126f8a0.y / ShaderDivideDetail::DAT_0126f8b0.y;
            ShaderDivideDetail::DAT_0126f900.z = ShaderDivideDetail::DAT_0126f8a0.z / ShaderDivideDetail::DAT_0126f8b0.z;
            ShaderDivideDetail::DAT_0126f900.w = ShaderDivideDetail::DAT_0126f8a0.w / ShaderDivideDetail::DAT_0126f8b0.w;
            return target->SetConstant(aiRegister, (const float*)&ShaderDivideDetail::DAT_0126f900, 0) ? 0 : 0x50;
        }
        default:
            return 1;
        }
        break;

    default:
        return 1;
    }
}
