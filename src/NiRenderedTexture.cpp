// NiRenderedTexture.cpp: NiRenderedTexture (6 functions)

#include "NiRenderedTexture.h"

// @fnv 0x00a7fc00
NiRenderedTexture* NiRenderedTexture::Create(const NiFixedString& name, unsigned int width, unsigned int height,
                                             NiRenderer* renderer, NiTexture::TextureFormatPreferences& preferences,
                                             Ni2DBuffer::MultiSamplePreference msaa, NiRenderedTexture* reuseTexture,
                                             unsigned int aliasOffset)
{
    if (!renderer)
        return 0;
    NiDX9Renderer* dxRenderer = static_cast<NiDX9Renderer*>(renderer);
    bool dimensionsPowerOfTwo = false;
    if (width)
    {
        dimensionsPowerOfTwo = (width & (width - 1)) == 0;
        if (dimensionsPowerOfTwo)
        {
            if (height)
                dimensionsPowerOfTwo = (height & (height - 1)) == 0;
            else
                dimensionsPowerOfTwo = false;
        }
    }
    if (!dimensionsPowerOfTwo)
    {
        if (!(dxRenderer->Unk_28() & 8) && !(dxRenderer->Unk_28() & 4))
            return 0;
    }
    NiRenderedTexture* texture = new NiRenderedTexture;
    texture->m_kTextureFormatPreferences = preferences;
    texture->m_pReuseTexture = reuseTexture;
    texture->m_uiAliasOffset = aliasOffset;
    Ni2DBuffer* buffer = Ni2DBuffer::Create(width, height);
    Ni2DBuffer* oldBuffer = texture->m_spRenderTargetBuffer.m_pObject;
    if (oldBuffer != buffer)
    {
        if (oldBuffer && InterlockedDecrement(reinterpret_cast<volatile long*>(&oldBuffer->m_uiRefCount)) == 0)
            oldBuffer->DeleteThis();
        texture->m_spRenderTargetBuffer.m_pObject = buffer;
        if (buffer)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&buffer->m_uiRefCount));
    }
    texture->m_bUseDepthBuffer = ms_bUseDepthBuffer;
    texture->m_ePixelFormat = ms_eDepthStencilFormat;
    texture->m_bUseMipMaps = ms_bUseMipMaps;
    if (!dxRenderer->CreateRenderedTexture(texture, msaa))
    {
        delete texture;
        return 0;
    }
    texture->m_eMultiSamplePreference = msaa;
    texture->m_pReuseTexture = 0;
    return texture;
}

// Declarations needed
// InterlockedDecrement might be needed if not in headers, but let's assume it is or use a helper if needed.
// The error log didn't complain about InterlockedDecrement, only LONG.

void __fastcall DestroyFogProperty(void*);
void __fastcall FUN_00a5f800(void*);
void __cdecl __Dummy_00b6fef0(void*, unsigned int);
extern int DAT_0109b944;

// Need to declare InterlockedDecrement if it's not found.
// extern "C" long __cdecl InterlockedDecrement(long*);

// @fnv 0x00a7fd30
void* __fastcall DestroyRenderedTexture(NiRenderedTexture* self, int, unsigned char flags)
{
    void* p30 = *(void**)((char*)self + 0x30);
    if (p30)
    {
        // InterlockedDecrement((long*)((char*)p30 + 4))
        // The assembly uses a call to an address.
        // If I use InterlockedDecrement, it matches the semantics.
        if (InterlockedDecrement((long*)((char*)p30 + 4)) == 0)
        {
            void** vtbl = *(void***)p30;
            ((void(__thiscall*)(void*))vtbl[1])(p30);
        }
    }

    void* p24 = *(void**)((char*)self + 0x24);
    *(void**)self = &DAT_0109b944;
    if (p24)
    {
        void** vtbl24 = *(void***)p24;
        ((void(__thiscall*)(void*, int))vtbl24[0])(p24, 1);
    }

    FUN_00a5f800(self);
    DestroyFogProperty(self);

    if (flags & 1)
    {
        __Dummy_00b6fef0(self, 0x48);
    }

    return self;
}

struct FUN_00a7fbd0_shell : public NiRenderedTexture
{
    void* GetRTTI();
};

extern char const* const g_012708e4_arg1[];

// NiTexture::GetRTTI, emitted in this unit: it returns the NiRTTI at 0x011f4ac4, which is the base RTTI that
// NiRenderedTexture's own NiRTTI (0x012708e4) is constructed with, i.e. NiTexture::ms_RTTI.
// @fnv 0x00a7fbd0
void* FUN_00a7fbd0_shell::GetRTTI()
{
    return reinterpret_cast<void*>(const_cast<char const**>(g_012708e4_arg1));
}

struct FUN_00a7fbe0_shell : public NiRenderedTexture
{
    unsigned int GetWidth();
};

// NiRenderedTexture::GetWidth: the width (Ni2DBuffer +0x8) of the render target buffer (this +0x30).
// @fnv 0x00a7fbe0
unsigned int FUN_00a7fbe0_shell::GetWidth()
{
    void* p = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x30);
    if (p)
        return *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(p) + 8);
    return 0;
}

struct FUN_00a7fbf0_shell : public NiRenderedTexture
{
    unsigned int GetHeight();
};

// NiRenderedTexture::GetHeight: the height (Ni2DBuffer +0xc) of the render target buffer (this +0x30).
// @fnv 0x00a7fbf0
unsigned int FUN_00a7fbf0_shell::GetHeight()
{
    NiRenderedTexture* this_ = static_cast<NiRenderedTexture*>(this);
    void* ptr = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this_) + 0x30);
    if (ptr)
        return *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(ptr) + 0xc);
    return 0;
}

struct FnvCpu_FUN_00be0b90_CpuObject
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
    int value;
    int FUN_00be0b90();
};
// @fnv 0x00be0b90
int FnvCpu_FUN_00be0b90_CpuObject::FUN_00be0b90()
{
    return value;
}
