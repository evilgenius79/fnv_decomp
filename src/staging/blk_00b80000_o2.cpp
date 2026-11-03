
// src/staging/blk_00b80000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

extern "C" void __cdecl operator delete(void*, unsigned int);

struct FUN_00b81290_class
{
    void __thiscall FUN_00b81130();
    void* __thiscall FUN_00b81290(int);
};
// Calls FUN_00b81130, then deletes this with size 0x70 when flags has bit 0 set, and returns this.
// @fnv 0x00b81290
void* __thiscall FUN_00b81290_class::FUN_00b81290(int flags)
{
    FUN_00b81130();
    if (flags & 1)
        operator delete(this, 0x70);
    return this;
}

extern "C" void __cdecl _delete(void*, unsigned int);
struct FUN_00b8d4d0_Class
{
    void __thiscall FUN_00b8d4d0();
};
struct FUN_00b8d580_Class : public FUN_00b8d4d0_Class
{
    FUN_00b8d580_Class* __thiscall FUN_00b8d580(unsigned int a);
};
// @fnv 0x00b8d580
FUN_00b8d580_Class* __thiscall FUN_00b8d580_Class::FUN_00b8d580(unsigned int auiFlags)
{
    FUN_00b8d4d0_Class::FUN_00b8d4d0();
    if (auiFlags & 1)
        _delete(this, 0xd0);
    return this;
}

void FUN_00c03a20();

void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00b91b50
{
    FUN_00b91b50* Method(bool flag);
};

// Calls FUN_00c03a20, then deletes this with size 0xd0 when flag bit 0 is set, and returns this.
// @fnv 0x00b91b50
FUN_00b91b50* FUN_00b91b50::Method(bool abFree)
{
    FUN_00c03a20();
    if (abFree & 1)
        operator delete(this, 0xd0);
    return this;
}

void __cdecl FUN_00b92450();

void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00b924d0_class
{
    FUN_00b924d0_class* __thiscall FUN_00b924d0(bool b);
};

// Calls FUN_00b92450, then frees this with operator delete when b has bit 0 set, and returns this.
// @fnv 0x00b924d0
FUN_00b924d0_class* __thiscall FUN_00b924d0_class::FUN_00b924d0(bool abFree)
{
    FUN_00b92450();
    if (abFree & 1)
        operator delete(this, 0xd4);
    return this;
}

extern "C" void __cdecl FUN_00b983d0(int, int, int, int);
extern "C" int DAT_011ffa1c;

// @fnv 0x00b985f0
void __cdecl FUN_00b985f0(int aiAmount)
{
    DAT_011ffa1c -= aiAmount;
    FUN_00b983d0(0, 0, 0, 0);
}

extern "C" void __cdecl _delete(void* p, size_t size);

struct FUN_00b9b380_class
{
    void FUN_00b9aa80();
    FUN_00b9b380_class* FUN_00b9b380(int a);
};

// Calls FUN_00b9aa80, then deletes this (size 0x98) when bit 0 of a is set, and returns this.
// @fnv 0x00b9b380
FUN_00b9b380_class* FUN_00b9b380_class::FUN_00b9b380(int aiFlags)
{
    FUN_00b9aa80();
    if (aiFlags & 1)
        _delete(this, 0x98);
    return this;
}

extern int DAT_010b06a0;
extern int DAT_010b06c0;
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void SetSize(unsigned int);
};
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct FUN_00b8d5b0 : ImageSpaceEffectShader
{
    FUN_00b8d5b0();
};
// @fnv 0x00b8d5b0
FUN_00b8d5b0::FUN_00b8d5b0()
{
    *(int**)this = &DAT_010b06c0;
    *(int**)((char*)this + 0x6c) = &DAT_010b06a0;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(2);
}

extern int DAT_010b06a0;
extern int DAT_010b06c0;

struct FUN_00b8d6c0_class
{
    FUN_00b8d6c0_class* __thiscall FUN_00b8d6c0(int flag);
};

// @fnv 0x00b8d6c0
FUN_00b8d6c0_class* __thiscall FUN_00b8d6c0_class::FUN_00b8d6c0(int aiFlags)
{
    *(int*)this = (int)&DAT_010b06c0;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b06a0;
    FUN_00c03a20();
    if (aiFlags & 1)
        _delete(this, 0xd0);
    return this;
}

namespace fnv_00b8d700 {
struct ImageSpaceTexture;
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void __thiscall SetSize(unsigned int);
};
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct FUN_00b8d700
{
    ImageSpaceEffectShader shader;
    FUN_00b8d700();
};
extern int DAT_010b083c;
extern int DAT_010b0860;
// @fnv 0x00b8d700
FUN_00b8d700::FUN_00b8d700()
{
    *(int*)this = (int)&DAT_010b0860;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b083c;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(3);
}
}  // namespace fnv_00b8d700

extern "C" void __cdecl _delete(void*, unsigned int);
extern int DAT_010b0a00;
extern int DAT_010b09dc;
struct FUN_00b8d950_class
{
    FUN_00b8d950_class* __thiscall FUN_00b8d950(bool flag);
};
// @fnv 0x00b8d950
FUN_00b8d950_class* __thiscall FUN_00b8d950_class::FUN_00b8d950(bool abFree)
{
    *(int*)this = (int)&DAT_010b0a00;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b09dc;
    FUN_00c03a20();
    if ((int)abFree & 1)
        _delete(this, 0xd0);
    return this;
}

namespace fnv_00b8d990 {
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void SetSize(unsigned int);
};
extern int DAT_010b0b98;
extern int DAT_010b0b78;
struct FUN_00b8d990 : public ImageSpaceEffectShader
{
    FUN_00b8d990();
};
// @fnv 0x00b8d990
FUN_00b8d990::FUN_00b8d990()
{
    *(int**)((char*)this + 0x00) = &DAT_010b0b98;
    *(int**)((char*)this + 0x6c) = &DAT_010b0b78;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(2);
}
}  // namespace fnv_00b8d990

extern int DAT_010b0b78;
extern int DAT_010b0b98;
void FUN_00c03a20();
void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00b8daa0_class
{
    int* vtbl;
    int m_6c;
    void* __thiscall FUN_00b8daa0(bool flag);
};

// @fnv 0x00b8daa0
void* __thiscall FUN_00b8daa0_class::FUN_00b8daa0(bool abFree)
{
    vtbl = (int*)&DAT_010b0b98;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b0b78;
    FUN_00c03a20();
    if (abFree & 1)
        operator delete(this, 0xd0);
    return this;
}

extern int DAT_010b0d40;
extern int DAT_010b0d1c;
extern "C" void __cdecl _delete(void*, unsigned int);
struct FUN_00b8dbf0_Class
{
    FUN_00b8dbf0_Class* __thiscall FUN_00b8dbf0(bool);
};
// @fnv 0x00b8dbf0
FUN_00b8dbf0_Class* __thiscall FUN_00b8dbf0_Class::FUN_00b8dbf0(bool abFree)
{
    *(void**)this = &DAT_010b0d40;
    *(void**)((char*)this + 0x6c) = &DAT_010b0d1c;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return this;
}

extern "C" void __cdecl _delete(void*, unsigned int);
extern int DAT_010b0e9c;
extern int DAT_010b0ec0;
void FUN_00c03a20();
struct FUN_00b8dd40_class
{
    FUN_00b8dd40_class* __thiscall FUN_00b8dd40(bool flag);
};
// @fnv 0x00b8dd40
FUN_00b8dd40_class* __thiscall FUN_00b8dd40_class::FUN_00b8dd40(bool abFree)
{
    *reinterpret_cast<int**>(this) = &DAT_010b0ec0;
    *reinterpret_cast<int**>(reinterpret_cast<char*>(this) + 0x6c) = &DAT_010b0e9c;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return this;
}

extern int DAT_010b1040;
extern int DAT_010b101c;

struct FUN_00b8de90_Class
{
    FUN_00b8de90_Class* __thiscall FUN_00b8de90(bool);
};

// @fnv 0x00b8de90
FUN_00b8de90_Class* __thiscall FUN_00b8de90_Class::FUN_00b8de90(bool abFree)
{
    *(int*)this = (int)&DAT_010b1040;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b101c;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return this;
}

extern "C" void __cdecl _delete(void*, unsigned int);
void __cdecl FUN_00c03a20();
extern "C" int DAT_010b119c;
extern "C" int DAT_010b11c0;

struct FUN_00b8dfe0_class
{
    int* __thiscall FUN_00b8dfe0(bool b);
};

// @fnv 0x00b8dfe0
int* __thiscall FUN_00b8dfe0_class::FUN_00b8dfe0(bool abFree)
{
    *(int**)(this) = &DAT_010b11c0;
    *(int**)((char*)this + 0x6c) = &DAT_010b119c;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return (int*)this;
}

namespace fnv_00b8e020 {
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
    void* m_vft;
    int m_6c;
    struct TextureArray
    {
        void SetSize(unsigned int n);
    } m_tex;
};
struct FUN_00b8e020 : ImageSpaceEffectShader
{
    FUN_00b8e020();
};
// @fnv 0x00b8e020
FUN_00b8e020::FUN_00b8e020()
{
    m_vft = (void*)0x010b1340;
    ((int*)this)[0x1b] = (int)0x010b1320;
    ((TextureArray*)((char*)this + 0x94))->SetSize(2);
}
}  // namespace fnv_00b8e020

extern int DAT_010b1340;
extern int DAT_010b1320;
void FUN_00c03a20();
struct FUN_00b8e130_class
{
    FUN_00b8e130_class* __thiscall FUN_00b8e130(bool flag);
};
// @fnv 0x00b8e130
FUN_00b8e130_class* __thiscall FUN_00b8e130_class::FUN_00b8e130(bool abFree)
{
    *(int*)this = (int)&DAT_010b1340;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b1320;
    FUN_00c03a20();
    if (abFree & 1)
        operator delete(this, 0xd0);
    return this;
}

extern "C" void __cdecl _delete(void* p, unsigned int size);
extern int DAT_010b14c0;
extern int DAT_010b14a0;
void FUN_00c03a20();

struct FUN_00b8e280_class
{
    FUN_00b8e280_class* __thiscall FUN_00b8e280(bool flag);
};

// @fnv 0x00b8e280
FUN_00b8e280_class* __thiscall FUN_00b8e280_class::FUN_00b8e280(bool abFree)
{
    *(void**)(this) = &DAT_010b14c0;
    *(void**)(this + 0x6c) = &DAT_010b14a0;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return this;
}

namespace fnv_00b8e2c0 {
extern int DAT_010b1640;
extern int DAT_010b1620;
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct ImageSpaceTextureArray
{
    void SetSize(unsigned int);
};
struct FUN_00b8e2c0 : public ImageSpaceEffectShader
{
    ImageSpaceTextureArray textures;
    FUN_00b8e2c0();
};
// @fnv 0x00b8e2c0
FUN_00b8e2c0::FUN_00b8e2c0()
{
    *(unsigned int*)this = (unsigned int)&DAT_010b1640;
    *(unsigned int*)((char*)this + 0x6c) = (unsigned int)&DAT_010b1620;
    ((ImageSpaceTextureArray*)((char*)this + 0x94))->SetSize(3);
}
}  // namespace fnv_00b8e2c0

namespace fnv_00b8ee20 {
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
    void SetSize(unsigned int);
};

extern int DAT_010b2140;
extern int DAT_010b211c;

struct FUN_00b8ee20_class : ImageSpaceEffectShader
{
    char pad[0x94 - sizeof(ImageSpaceEffectShader)];
    struct
    {
        unsigned int size;
        unsigned int capacity;
        void** elements;
        void SetSize(unsigned int n);
    } textures;
    FUN_00b8ee20_class();
};

// @fnv 0x00b8ee20
FUN_00b8ee20_class::FUN_00b8ee20_class()
{
    *(void**)this = (void*)&DAT_010b2140;
    *(void**)((char*)this + 0x6c) = (void*)&DAT_010b211c;
    textures.SetSize(2);
}
}  // namespace fnv_00b8ee20

extern "C" void __cdecl _delete(void*, unsigned int);
extern int DAT_010b211c;
extern int DAT_010b2140;
void FUN_00c03a20();
struct FUN_00b8ef60_class
{
    int m_vtbl;
    FUN_00b8ef60_class* __thiscall FUN_00b8ef60(bool del);
};
// @fnv 0x00b8ef60
FUN_00b8ef60_class* __thiscall FUN_00b8ef60_class::FUN_00b8ef60(bool abFree)
{
    m_vtbl = (int)&DAT_010b2140;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b211c;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return this;
}

extern "C" void __cdecl _delete(void* p, unsigned int size);
extern int DAT_010b2308;
extern int DAT_010b22e8;
void FUN_00c03a20();

struct FUN_00b8f120_class
{
    void* __thiscall FUN_00b8f120(unsigned char b);
};

// @fnv 0x00b8f120
void* __thiscall FUN_00b8f120_class::FUN_00b8f120(unsigned char abFree)
{
    *(int**)this = &DAT_010b2308;
    *(int**)((char*)this + 0x6c) = &DAT_010b22e8;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return this;
}

extern "C" void __cdecl _delete(void*, unsigned int);
extern "C" int DAT_010b2470;
extern "C" int DAT_010b2490;
void FUN_00c03a20();
struct FUN_00b8f2b0_class
{
    void* __thiscall FUN_00b8f2b0(bool flag);
};
// @fnv 0x00b8f2b0
void* __thiscall FUN_00b8f2b0_class::FUN_00b8f2b0(bool abFree)
{
    *(int*)this = (int)&DAT_010b2490;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b2470;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return this;
}

extern int DAT_010b25f0;
extern int DAT_010b2610;
struct FUN_00b8f470_class
{
    int* __thiscall FUN_00b8f470(bool);
};
// @fnv 0x00b8f470
int* __thiscall FUN_00b8f470_class::FUN_00b8f470(bool abFree)
{
    *reinterpret_cast<int**>(this) = &DAT_010b2610;
    *reinterpret_cast<int**>(reinterpret_cast<char*>(this) + 0x6c) = &DAT_010b25f0;
    FUN_00c03a20();
    if (abFree & 1)
        operator delete(this, 0xd0);
    return reinterpret_cast<int*>(this);
}

extern "C" void __cdecl _delete(void*, unsigned int);
extern int DAT_010b2784;
extern int DAT_010b27a8;
struct FUN_00b8f620_class
{
    void* vtbl;
    void* m_06c;
    void* __thiscall FUN_00b8f620(bool flag);
};
// Sets the vtbl and the pointer at offset 0x6c, calls FUN_00c03a20, and deletes this with size 208 when flag bit 0 is set.
// @fnv 0x00b8f620
void* __thiscall FUN_00b8f620_class::FUN_00b8f620(bool abDelete)
{
    vtbl = &DAT_010b27a8;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x6c) = &DAT_010b2784;
    FUN_00c03a20();
    if (abDelete & 1)
        _delete(this, 208);
    return this;
}

namespace fnv_00b8f660 {
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void SetSize(unsigned int);
};
extern int DAT_010b28fc;
extern int DAT_010b2920;
struct FUN_00b8f660 : public ImageSpaceEffectShader
{
    NiTPrimitiveArray_ImageSpaceTexture___ arr;
    FUN_00b8f660();
};
// @fnv 0x00b8f660
FUN_00b8f660::FUN_00b8f660()
{
    *(int*)this = (int)&DAT_010b2920;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b28fc;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(3);
}
}  // namespace fnv_00b8f660

extern "C" void __cdecl _delete(void*, unsigned int);
void FUN_00c03a20();
extern "C" void* DAT_010b28fc;
extern "C" void* DAT_010b2920;

struct FUN_00b8f6d0_class
{
    void* __thiscall FUN_00b8f6d0(bool flag);
};
// @fnv 0x00b8f6d0
void* __thiscall FUN_00b8f6d0_class::FUN_00b8f6d0(bool abFree)
{
    *(void**)this = &DAT_010b2920;
    *(void**)((char*)this + 0x6c) = &DAT_010b28fc;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return this;
}

extern "C" void __cdecl _delete(void* p, unsigned int size);
extern int DAT_010b2a74;
extern int DAT_010b2a98;

struct FUN_00b8f7a0_class
{
    int* __thiscall FUN_00b8f7a0(int arg);
};

// @fnv 0x00b8f7a0
int* __thiscall FUN_00b8f7a0_class::FUN_00b8f7a0(int aiFlags)
{
    *(int**)((char*)this + 0) = &DAT_010b2a98;
    *(int**)((char*)this + 0x6c) = &DAT_010b2a74;
    FUN_00c03a20();
    if (aiFlags & 1)
        _delete(this, 0xd0);
    return (int*)this;
}

extern "C" void __cdecl _delete(void*, unsigned int);
extern "C" int DAT_010b2bec;
extern "C" int DAT_010b2c10;
void FUN_00c03a20();
struct FUN_00b8f8f0_class
{
    FUN_00b8f8f0_class* __thiscall FUN_00b8f8f0(bool flag);
};
// @fnv 0x00b8f8f0
FUN_00b8f8f0_class* __thiscall FUN_00b8f8f0_class::FUN_00b8f8f0(bool abFree)
{
    *(int*)this = (int)&DAT_010b2c10;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b2bec;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return this;
}

namespace fnv_00b8f930 {
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void SetSize(unsigned int);
};
extern int DAT_010b2db0;
extern int DAT_010b2d8c;
struct FUN_00b8f930 : public ImageSpaceEffectShader
{
    char pad[0x94];
    NiTPrimitiveArray_ImageSpaceTexture___ arr;
    FUN_00b8f930();
};
// @fnv 0x00b8f930
FUN_00b8f930::FUN_00b8f930()
{
    *(int*)this = (int)&DAT_010b2db0;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b2d8c;
    arr.SetSize(2);
}
}  // namespace fnv_00b8f930

extern int DAT_010b2db0;
extern int DAT_010b2d8c;

struct FUN_00b8fa40_class
{
    int vtbl;
    int m_00b2d8c;
    int m_00b2db0;
    void __thiscall FUN_00c03a20();
    FUN_00b8fa40_class(bool flag);
    ~FUN_00b8fa40_class();
};

// @fnv 0x00b8fa40
FUN_00b8fa40_class::FUN_00b8fa40_class(bool abDelete)
{
    vtbl = (int)&DAT_010b2db0;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b2d8c;
    FUN_00c03a20();
    if (abDelete & 1)
        operator delete(this, 0xd0);
}

namespace fnv_00b8fa80 {
extern int DAT_010b2f50;
extern int DAT_010b2f30;
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void SetSize(unsigned int);
};
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct FUN_00b8fa80_class : public ImageSpaceEffectShader
{
    FUN_00b8fa80_class();
};
// @fnv 0x00b8fa80
FUN_00b8fa80_class::FUN_00b8fa80_class()
{
    *(int*)this = (int)&DAT_010b2f50;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b2f30;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(2);
}
}  // namespace fnv_00b8fa80

extern "C" void __cdecl _delete(void* p, unsigned int size);
extern int DAT_010b2f30;
extern int DAT_010b2f50;
struct FUN_00b8fba0_class
{
    void* __thiscall FUN_00b8fba0(int flag);
};
// @fnv 0x00b8fba0
void* __thiscall FUN_00b8fba0_class::FUN_00b8fba0(int aiFlags)
{
    *(int*)this = (int)&DAT_010b2f50;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b2f30;
    FUN_00c03a20();
    if (aiFlags & 1)
        _delete(this, 0xd0);
    return this;
}

namespace fnv_00b8fbe0 {
extern int DAT_010b30e0;
extern int DAT_010b30c0;
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct FUN_00b8fbe0 : public ImageSpaceEffectShader
{
    void SetSize(unsigned int size);
    FUN_00b8fbe0();
};
// @fnv 0x00b8fbe0
FUN_00b8fbe0::FUN_00b8fbe0()
{
    *(void**)this = (void*)&DAT_010b30e0;
    *(void**)((char*)this + 0x6c) = (void*)&DAT_010b30c0;
    ((FUN_00b8fbe0*)((char*)this + 0x94))->SetSize(2);
}
}  // namespace fnv_00b8fbe0

extern int DAT_010b30c0;
extern int DAT_010b30e0;
void FUN_00c03a20();
struct FUN_00b8fd00_Class
{
    FUN_00b8fd00_Class* __thiscall FUN_00b8fd00(bool flag);
};
// @fnv 0x00b8fd00
FUN_00b8fd00_Class* __thiscall FUN_00b8fd00_Class::FUN_00b8fd00(bool abFree)
{
    *(int*)this = (int)&DAT_010b30e0;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b30c0;
    FUN_00c03a20();
    if (abFree & 1)
        operator delete(this, 0xd0);
    return this;
}

namespace fnv_00b8fd40 {
extern int DAT_010b3268;
extern int DAT_010b3244;
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void SetSize(unsigned int);
};
struct FUN_00b8fd40 : public ImageSpaceEffectShader
{
    FUN_00b8fd40();
};
// @fnv 0x00b8fd40
FUN_00b8fd40::FUN_00b8fd40()
{
    *(void**)this = (void*)&DAT_010b3268;
    *(void**)((char*)this + 0x6c) = (void*)&DAT_010b3244;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(5);
}
}  // namespace fnv_00b8fd40

extern int DAT_010b3244;
extern int DAT_010b3268;
struct FUN_00b8fe60_class
{
    FUN_00b8fe60_class* __thiscall FUN_00b8fe60(bool b);
};
// @fnv 0x00b8fe60
FUN_00b8fe60_class* __thiscall FUN_00b8fe60_class::FUN_00b8fe60(bool abFree)
{
    *(int*)this = (int)&DAT_010b3268;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b3244;
    FUN_00c03a20();
    if (abFree & 1)
        operator delete(this, 0xd0);
    return this;
}

namespace fnv_00b8fea0 {
extern int DAT_010b33cc;
extern int DAT_010b33f0;
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void SetSize(unsigned int);
};
struct FUN_00b8fea0 : ImageSpaceEffectShader
{
    FUN_00b8fea0();
};
// @fnv 0x00b8fea0
FUN_00b8fea0::FUN_00b8fea0()
{
    *(int*)this = (int)&DAT_010b33f0;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b33cc;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(3);
}
}  // namespace fnv_00b8fea0

extern "C" void __cdecl _delete(void* p, unsigned int size);
extern int DAT_010b33cc;
extern int DAT_010b33f0;

struct FUN_00b8ffb0_class
{
    FUN_00b8ffb0_class* __thiscall FUN_00b8ffb0(bool b);
};

// @fnv 0x00b8ffb0
FUN_00b8ffb0_class* __thiscall FUN_00b8ffb0_class::FUN_00b8ffb0(bool abFree)
{
    *(int*)this = (int)&DAT_010b33f0;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b33cc;
    FUN_00c03a20();
    if ((unsigned char)abFree & 1)
        _delete(this, 0xd0);
    return this;
}

namespace fnv_00b8fff0 {
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void __thiscall SetSize(unsigned int);
};
extern int DAT_010b3574;
extern int DAT_010b3598;
struct FUN_00b8fff0 : public ImageSpaceEffectShader
{
    FUN_00b8fff0();
};
// @fnv 0x00b8fff0
FUN_00b8fff0::FUN_00b8fff0()
{
    *(int**)((char*)this + 0x00) = (int*)&DAT_010b3598;
    *(int**)((char*)this + 0x6c) = (int*)&DAT_010b3574;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(4);
}
}  // namespace fnv_00b8fff0

namespace fnv_00b91680 {
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void SetSize(unsigned int);
};
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct FUN_00b91680 : ImageSpaceEffectShader
{
    FUN_00b91680();
};
// @fnv 0x00b91680
FUN_00b91680::FUN_00b91680()
{
    *(void**)((char*)this + 0x0) = (void*)0x010b4c68;
    *(void**)((char*)this + 0x6c) = (void*)0x010b4c48;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(5);
}
}  // namespace fnv_00b91680

extern int DAT_010b4c48;
extern int DAT_010b4c68;

struct FUN_00b91780_shell
{
    int* vtbl;
    void FUN_00c03a20();
    FUN_00b91780_shell* __thiscall FUN_00b91780(bool flag);
};

// @fnv 0x00b91780
FUN_00b91780_shell* __thiscall FUN_00b91780_shell::FUN_00b91780(bool abFree)
{
    vtbl = &DAT_010b4c68;
    *(int**)((char*)this + 0x6c) = &DAT_010b4c48;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return this;
}

namespace fnv_00b917c0 {
extern "C" void __cdecl operator delete(void*, unsigned int);
extern int DAT_010b4de8;
extern int DAT_010b4dc8;
struct ImageSpaceEffectShader
{
    void* vtbl;
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void SetSize(unsigned int);
};
struct FUN_00b917c0 : public ImageSpaceEffectShader
{
    FUN_00b917c0();
    ~FUN_00b917c0();
};
// @fnv 0x00b917c0
FUN_00b917c0::FUN_00b917c0()
{
    vtbl = (void*)&DAT_010b4de8;
    *(void**)((char*)this + 0x6c) = (void*)&DAT_010b4dc8;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(2);
}
}  // namespace fnv_00b917c0

extern "C" void __cdecl _delete(void*, unsigned int);
extern int DAT_010b4de8;
extern int DAT_010b4dc8;
void FUN_00c03a20();
struct FUN_00b918c0_Class
{
    int __thiscall FUN_00b918c0(bool flag);
};
// @fnv 0x00b918c0
int FUN_00b918c0_Class::FUN_00b918c0(bool abFree)
{
    *(int*)this = (int)&DAT_010b4de8;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b4dc8;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return (int)this;
}

namespace fnv_00b91900 {
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void SetSize(unsigned int);
};
extern int DAT_010b4f60;
extern int DAT_010b4f80;
struct FUN_00b91900 : ImageSpaceEffectShader
{
    FUN_00b91900();
};
// @fnv 0x00b91900
FUN_00b91900::FUN_00b91900()
{
    *(void**)this = (void*)&DAT_010b4f80;
    *(void**)((char*)this + 0x6c) = (void*)&DAT_010b4f60;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(3);
}
}  // namespace fnv_00b91900

extern int DAT_010b4f80;
extern int DAT_010b4f60;
struct FUN_00b91a00_Class
{
    void* __thiscall FUN_00b91a00(bool flag);
};
// @fnv 0x00b91a00
void* __thiscall FUN_00b91a00_Class::FUN_00b91a00(bool abFree)
{
    *(void**)this = &DAT_010b4f80;
    *(void**)((char*)this + 0x6c) = &DAT_010b4f60;
    FUN_00c03a20();
    if (abFree & 1)
        operator delete(this, 0xd0);
    return this;
}

extern "C" void __cdecl _delete(void*, unsigned int);
extern void* DAT_010b52c0;
extern void* DAT_010b52a0;
void FUN_00c03a20();
struct FUN_00b91cb0_class
{
    void* vtbl;
    char pad[0x6c - sizeof(void*)];
    void* m_6c;
    FUN_00b91cb0_class* __thiscall FUN_00b91cb0(unsigned char flag);
};
// Resets the vtbl and m_6c pointers, calls FUN_00c03a20, and frees this with _delete when flag bit 0 is set, returning this.
// @fnv 0x00b91cb0
FUN_00b91cb0_class* __thiscall FUN_00b91cb0_class::FUN_00b91cb0(unsigned char flag)
{
    vtbl = &DAT_010b52c0;
    m_6c = &DAT_010b52a0;
    FUN_00c03a20();
    if (flag & 1)
        _delete(this, 0xd0);
    return this;
}

namespace fnv_00b91e40 {
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
    int f0;
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
    int fd8;
    int fdc;
    int fe0;
    int fe4;
    int fe8;
    int fec;
    int ff0;
    int ff4;
    int ff8;
    int ffc;
};
struct ImageSpaceTexture
{
    int a;
};
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void SetSize(unsigned int);
};
extern int DAT_010b5640;
extern int DAT_010b5620;
struct FUN_00b91e40 : ImageSpaceEffectShader
{
    FUN_00b91e40();
};
// @fnv 0x00b91e40
FUN_00b91e40::FUN_00b91e40()
{
    *reinterpret_cast<int**>(this) = &DAT_010b5640;
    *reinterpret_cast<int**>(reinterpret_cast<char*>(this) + 0x6c) = &DAT_010b5620;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(2);
}
}  // namespace fnv_00b91e40

void __cdecl FUN_00c03a20();
extern int DAT_010b5640;
extern int DAT_010b5620;
struct FUN_00b91f50_class
{
    void* vtbl;
    FUN_00b91f50_class* __thiscall FUN_00b91f50(bool flag);
};
// @fnv 0x00b91f50
FUN_00b91f50_class* __thiscall FUN_00b91f50_class::FUN_00b91f50(bool abFree)
{
    vtbl = &DAT_010b5640;
    *(void**)((char*)this + 0x6c) = &DAT_010b5620;
    FUN_00c03a20();
    if (abFree & 1)
        operator delete(this, 0xd0);
    return this;
}

namespace fnv_00b92180 {
extern int DAT_010b57b0;
extern int DAT_010b57d0;
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void SetSize(unsigned int);
};
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct FUN_00b92180 : ImageSpaceEffectShader
{
    FUN_00b92180();
};
// @fnv 0x00b92180
FUN_00b92180::FUN_00b92180()
{
    *(void**)((char*)this + 0) = (void*)&DAT_010b57d0;
    *(void**)((char*)this + 0x6c) = (void*)&DAT_010b57b0;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(3);
}
}  // namespace fnv_00b92180

extern int DAT_010b57b0;
extern int DAT_010b57d0;
void FUN_00c03a20();
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00b92290_shell
{
    FUN_00b92290_shell* __thiscall FUN_00b92290(bool flag);
};
// @fnv 0x00b92290
FUN_00b92290_shell* __thiscall FUN_00b92290_shell::FUN_00b92290(bool abFree)
{
    *(int*)this = (int)&DAT_010b57d0;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b57b0;
    FUN_00c03a20();
    if (abFree & 1)
        operator delete(this, 0xd0);
    return this;
}

extern "C" void __cdecl _delete(void* p, unsigned int size);
extern int DAT_010b5af0;
extern int DAT_010b5b10;
void FUN_00c03a20();
struct FUN_00b92570_class
{
    int vtbl;
    FUN_00b92570_class* __thiscall FUN_00b92570(bool del);
};
// @fnv 0x00b92570
FUN_00b92570_class* __thiscall FUN_00b92570_class::FUN_00b92570(bool abDelete)
{
    vtbl = (int)&DAT_010b5b10;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b5af0;
    FUN_00c03a20();
    if (abDelete & 1)
        _delete(this, 0xd0);
    return this;
}

namespace fnv_00b92690 {
extern int DAT_010b5cb8;
extern int DAT_010b5c94;
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void SetSize(unsigned int);
};
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct FUN_00b92690 : public ImageSpaceEffectShader
{
    void* m_vtbl;
    FUN_00b92690();
};
// @fnv 0x00b92690
FUN_00b92690::FUN_00b92690()
{
    m_vtbl = &DAT_010b5cb8;
    *(void**)((char*)this + 0x6c) = &DAT_010b5c94;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(2);
}
}  // namespace fnv_00b92690

extern "C" void __cdecl _delete(void*, unsigned int);
extern void* DAT_010b5cb8;
extern void* DAT_010b5c94;
void FUN_00c03a20();
struct FUN_00b927a0_class
{
    void* __thiscall FUN_00b927a0(bool b);
};
// @fnv 0x00b927a0
void* __thiscall FUN_00b927a0_class::FUN_00b927a0(bool abFree)
{
    *(void***)this = &DAT_010b5cb8;
    *(void**)((char*)this + 0x6c) = &DAT_010b5c94;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return this;
}

namespace fnv_00b927e0 {
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct ImageSpaceTexture
{
    void SetSize(unsigned int);
};
extern "C" int DAT_010b5e84;
extern "C" int DAT_010b5ea8;
struct FUN_00b927e0 : ImageSpaceEffectShader
{
    FUN_00b927e0();
    ImageSpaceTexture* mTextures;
};
// @fnv 0x00b927e0
FUN_00b927e0::FUN_00b927e0()
{
    *(unsigned int*)this = (unsigned int)&DAT_010b5ea8;
    *(unsigned int*)((char*)this + 0x6c) = (unsigned int)&DAT_010b5e84;
    ((ImageSpaceTexture*)((char*)this + 0x94))->SetSize(2);
}
}  // namespace fnv_00b927e0

extern "C" void __cdecl _delete(void* p, unsigned int size);
extern int DAT_010b5ea8;
extern int DAT_010b5e84;
void FUN_00c03a20();

struct FUN_00b928f0_shell
{
    void* vtbl;
    char pad[0x6c - 4];
    void* field_6c;
    FUN_00b928f0_shell(bool del);
};

// Sets the vtable and field_6c pointers, calls FUN_00c03a20, and deletes this with size 0xd0 when del is set.
// @fnv 0x00b928f0
FUN_00b928f0_shell::FUN_00b928f0_shell(bool abDelete)
{
    vtbl = &DAT_010b5ea8;
    field_6c = &DAT_010b5e84;
    FUN_00c03a20();
    if (abDelete & 1)
        _delete(this, 0xd0);
}

namespace fnv_00b92930 {
extern void* DAT_010b6028;
extern void* DAT_010b6048;
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void SetSize(unsigned int);
};
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct FUN_00b92930 : ImageSpaceEffectShader
{
    FUN_00b92930();
};
// @fnv 0x00b92930
FUN_00b92930::FUN_00b92930()
{
    *(void**)((char*)this + 0) = &DAT_010b6048;
    *(void**)((char*)this + 0x6c) = &DAT_010b6028;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(2);
}
}  // namespace fnv_00b92930

extern "C" int DAT_010b6028;
extern "C" int DAT_010b6048;

struct FUN_00b92a40_class
{
    int* vtbl;
    int pad[0x6c / 4 - 1];
    int* unk6c;
    FUN_00b92a40_class* __thiscall FUN_00b92a40(bool b);
};

// Sets the vtbl and unk6c pointers, calls FUN_00c03a20, and if b bit 0 is set deletes this with size 0xd0.
// @fnv 0x00b92a40
FUN_00b92a40_class* __thiscall FUN_00b92a40_class::FUN_00b92a40(bool abDelete)
{
    vtbl = &DAT_010b6048;
    unk6c = &DAT_010b6028;
    FUN_00c03a20();
    if (abDelete & 1)
        _delete(this, 0xd0);
    return this;
}

extern int DAT_010b61d0;
extern int DAT_010b61f0;
void FUN_00c03a20();
struct FUN_00b92b90
{
    FUN_00b92b90(bool b);
};
// @fnv 0x00b92b90
FUN_00b92b90::FUN_00b92b90(bool abDelete)
{
    int* p = (int*)this;
    *p = (int)&DAT_010b61f0;
    p[0x6c / 4] = (int)&DAT_010b61d0;
    FUN_00c03a20();
    if (abDelete & 1)
        _delete(this, 0xd0);
}

extern int DAT_010b6398;
extern int DAT_010b6374;

struct FUN_00b92ce0_class
{
    int vtbl;
    int pad[26];
    int* field_6c;
    FUN_00b92ce0_class* __thiscall FUN_00b92ce0(int flag);
};

// Sets the vtable and field_6c pointers, calls FUN_00c03a20, and if flag bit 0 is set frees this with size 0xd0.
// @fnv 0x00b92ce0
FUN_00b92ce0_class* __thiscall FUN_00b92ce0_class::FUN_00b92ce0(int flag)
{
    *(int**)this = &DAT_010b6398;
    field_6c = &DAT_010b6374;
    FUN_00c03a20();
    if (flag & 1)
        operator delete(this, 0xd0);
    return this;
}

extern int DAT_010b6524;
extern int DAT_010b6548;

struct FUN_00b92ea0_shell
{
    void* __thiscall FUN_00b92ea0(bool flag);
};

// Installs two static tables into the object, calls FUN_00c03a20, and if flag bit 0 is set frees the 0xd0-byte object, returning this.
// @fnv 0x00b92ea0
void* __thiscall FUN_00b92ea0_shell::FUN_00b92ea0(bool abFree)
{
    *reinterpret_cast<int**>(this) = &DAT_010b6548;
    *reinterpret_cast<int**>(reinterpret_cast<char*>(this) + 0x6c) = &DAT_010b6524;
    FUN_00c03a20();
    if (abFree & 1)
        operator delete(this, 0xd0);
    return this;
}

namespace fnv_00b92ee0 {
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void SetSize(unsigned int);
};
extern int DAT_010b66cc;
extern int DAT_010b66f0;
struct FUN_00b92ee0_class : public ImageSpaceEffectShader
{
    FUN_00b92ee0_class();
    ~FUN_00b92ee0_class();
};
// @fnv 0x00b92ee0
FUN_00b92ee0_class::FUN_00b92ee0_class()
{
    *(void**)((char*)this + 0) = &DAT_010b66f0;
    *(void**)((char*)this + 0x6c) = &DAT_010b66cc;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(3);
}
}  // namespace fnv_00b92ee0

extern "C" void __cdecl _delete(void* p, unsigned int size);
void __cdecl FUN_00c03a20();
extern "C" void* DAT_010b66cc;
extern "C" void* DAT_010b66f0;

struct FUN_00b92ff0_class
{
    void* vtbl;
    void* m_0004;
    void* m_0008;
    void* m_000c;
    void* m_0010;
    void* m_0014;
    void* m_0018;
    void* m_001c;
    void* m_0020;
    void* m_0024;
    void* m_0028;
    void* m_002c;
    void* m_0030;
    void* m_0034;
    void* m_0038;
    void* m_003c;
    void* m_0040;
    void* m_0044;
    void* m_0048;
    void* m_004c;
    void* m_0050;
    void* m_0054;
    void* m_0058;
    void* m_005c;
    void* m_0060;
    void* m_0064;
    void* m_0068;
    void* m_006c;
    FUN_00b92ff0_class* __thiscall FUN_00b92ff0(bool flag);
};

// Sets the vtable and m_006c, calls FUN_00c03a20, and if flag bit 0 is set frees this with size 0xd0.
// @fnv 0x00b92ff0
FUN_00b92ff0_class* __thiscall FUN_00b92ff0_class::FUN_00b92ff0(bool abFree)
{
    *reinterpret_cast<void***>(this) = &DAT_010b66f0;
    m_006c = &DAT_010b66cc;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return this;
}

extern "C" void __cdecl _delete(void*, unsigned int);
extern int DAT_010b687c;
extern int DAT_010b68a0;
void FUN_00c03a20();
struct FUN_00b93140_class
{
    void* __thiscall FUN_00b93140(bool);
};
// @fnv 0x00b93140
void* FUN_00b93140_class::FUN_00b93140(bool abFree)
{
    *(void**)this = &DAT_010b68a0;
    *(void**)((char*)this + 0x6c) = &DAT_010b687c;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return this;
}

namespace fnv_00b93180 {
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void SetSize(unsigned int);
};
struct FUN_00b93180 : public ImageSpaceEffectShader
{
    void* vtbl;
    void* p6c;
    FUN_00b93180();
};
// @fnv 0x00b93180
FUN_00b93180::FUN_00b93180()
{
    vtbl = (void*)0x010b6a40;
    ((void**)((char*)this + 0x6c))[0] = (void*)0x010b6a20;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(2);
}
}  // namespace fnv_00b93180

extern int DAT_010b6a20;
extern int DAT_010b6a40;
extern "C" void __cdecl _delete(void*, unsigned int);
void FUN_00c03a20();
struct FUN_00b93290_shell
{
    int* vft;
    int f1[26];
    int* f27;
    void __thiscall FUN_00c03a20();
    FUN_00b93290_shell* __thiscall FUN_00b93290(bool flag);
};
// Sets the vtable and f27 pointers, calls FUN_00c03a20, and if flag bit 0 is set deletes this with size 0xd0, returning this.
// @fnv 0x00b93290
FUN_00b93290_shell* __thiscall FUN_00b93290_shell::FUN_00b93290(bool abFree)
{
    vft = &DAT_010b6a40;
    f27 = &DAT_010b6a20;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return this;
}

extern "C" void __cdecl _delete(void*, unsigned int);
extern int DAT_010b6bb8;
extern int DAT_010b6bd8;
void FUN_00c03a20();
struct FUN_00b933e0_class
{
    int vtbl;
    FUN_00b933e0_class* __thiscall FUN_00b933e0(bool flag);
};
// @fnv 0x00b933e0
FUN_00b933e0_class* __thiscall FUN_00b933e0_class::FUN_00b933e0(bool abFree)
{
    *(int**)this = &DAT_010b6bd8;
    *(int**)((char*)this + 0x6c) = &DAT_010b6bb8;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return this;
}

extern "C" void __cdecl _delete(void*, unsigned int);
extern int DAT_010b6d90;
extern int DAT_010b6d70;
void FUN_00c03a20();
struct FUN_00b93710_class
{
    int __thiscall FUN_00b93710(bool flag);
};
// @fnv 0x00b93710
int __thiscall FUN_00b93710_class::FUN_00b93710(bool abFree)
{
    *(int*)this = (int)&DAT_010b6d90;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b6d70;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return (int)this;
}

extern "C" void __cdecl _delete(void*, unsigned int);
extern int DAT_010b6f38;
extern int DAT_010b6f14;
void FUN_00c03a20();
struct FUN_00b93a60_shell
{
    FUN_00b93a60_shell* __thiscall FUN_00b93a60(bool flag);
};
// @fnv 0x00b93a60
FUN_00b93a60_shell* __thiscall FUN_00b93a60_shell::FUN_00b93a60(bool abFree)
{
    *(int**)this = &DAT_010b6f38;
    *(int**)((char*)this + 0x6c) = &DAT_010b6f14;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return this;
}

extern "C" void __cdecl _delete(void*, unsigned int);
extern int DAT_010b70b8;
extern int DAT_010b70d8;
void FUN_00c03a20();
struct FUN_00b93bb0_class
{
    void* __thiscall FUN_00b93bb0(bool flag);
};
// @fnv 0x00b93bb0
void* __thiscall FUN_00b93bb0_class::FUN_00b93bb0(bool abFree)
{
    *(int*)this = (int)&DAT_010b70d8;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b70b8;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return this;
}

namespace fnv_00b93bf0 {
extern int DAT_010b7278;
extern int DAT_010b7258;
struct ImageSpaceEffectShader
{
    void* m_ppVirtualMethodTable;
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void __thiscall SetSize(unsigned int);
};
struct FUN_00b93bf0 : public ImageSpaceEffectShader
{
    FUN_00b93bf0();
};
// Initializes two pointers at offsets 0x0 and 0x6c and sets the primitive array at offset 0x94 to size 4.
// @fnv 0x00b93bf0
FUN_00b93bf0::FUN_00b93bf0()
{
    m_ppVirtualMethodTable = (void*)&DAT_010b7278;
    *(void**)((char*)this + 0x6c) = (void*)&DAT_010b7258;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(4);
}
}  // namespace fnv_00b93bf0

extern int DAT_010b7258;
extern int DAT_010b7278;
void FUN_00c03a20();
struct FUN_00b93d00_Class
{
    int* m_vtbl;
    int* m_6c;
    void FUN_00c03a20();
    FUN_00b93d00_Class* __thiscall FUN_00b93d00(bool flag);
};
// @fnv 0x00b93d00
FUN_00b93d00_Class* __thiscall FUN_00b93d00_Class::FUN_00b93d00(bool abFree)
{
    m_vtbl = &DAT_010b7278;
    *(int**)((char*)this + 0x6c) = &DAT_010b7258;
    FUN_00c03a20();
    if (abFree & 1)
        operator delete(this, 0xd0);
    return this;
}

namespace fnv_00b93d40 {
extern int DAT_010b73f4;
extern int DAT_010b7418;
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void SetSize(unsigned int);
};
struct FUN_00b93d40_class : public ImageSpaceEffectShader
{
    FUN_00b93d40_class();
};
// @fnv 0x00b93d40
FUN_00b93d40_class::FUN_00b93d40_class()
{
    *(void**)((char*)this) = &DAT_010b7418;
    *(void**)((char*)this + 0x6c) = &DAT_010b73f4;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(2);
}
}  // namespace fnv_00b93d40

extern "C" void __cdecl _delete(void*, unsigned int);
extern int DAT_010b73f4;
extern int DAT_010b7418;
struct FUN_00b93e50_class
{
    FUN_00b93e50_class* __thiscall FUN_00b93e50(bool b);
};
// @fnv 0x00b93e50
FUN_00b93e50_class* __thiscall FUN_00b93e50_class::FUN_00b93e50(bool abFree)
{
    *(int**)this = &DAT_010b7418;
    *(int**)((char*)this + 0x6c) = &DAT_010b73f4;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return this;
}

extern "C" void __cdecl _delete(void*, unsigned int);
extern "C" int DAT_010b7578;
extern "C" int DAT_010b7598;
void FUN_00c03a20();
struct FUN_00b93fa0_shell
{
    void* vtbl;
    void* m_004;
    void* m_008;
    void* m_00c;
    void* m_010;
    void* m_014;
    void* m_018;
    void* m_01c;
    void* m_020;
    void* m_024;
    void* m_028;
    void* m_02c;
    void* m_030;
    void* m_034;
    void* m_038;
    void* m_03c;
    void* m_040;
    void* m_044;
    void* m_048;
    void* m_04c;
    void* m_050;
    void* m_054;
    void* m_058;
    void* m_05c;
    void* m_060;
    void* m_064;
    void* m_068;
    void* m_06c;
    void FUN_00c03a20();
    void* __thiscall FUN_00b93fa0(bool flag);
};
// Sets the vtable and a member pointer, calls FUN_00c03a20, and if flag bit 0 is set frees this with _delete before returning this.
// @fnv 0x00b93fa0
void* __thiscall FUN_00b93fa0_shell::FUN_00b93fa0(bool abFree)
{
    *reinterpret_cast<void**>(this) = &DAT_010b7598;
    m_06c = &DAT_010b7578;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return this;
}

extern "C" void __cdecl _delete(void*, unsigned int);
void FUN_00c03a20();
extern int DAT_010b7700;
extern int DAT_010b7720;

struct FUN_00b940f0_class
{
    FUN_00b940f0_class* __thiscall FUN_00b940f0(bool flag);
};

// @fnv 0x00b940f0
FUN_00b940f0_class* __thiscall FUN_00b940f0_class::FUN_00b940f0(bool abFree)
{
    *(int**)this = &DAT_010b7720;
    *(int**)((char*)this + 0x6c) = &DAT_010b7700;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return this;
}

extern int DAT_010b78b8;
extern int DAT_010b7898;
struct FUN_00b94240_Class
{
    int* __thiscall FUN_00b94240(bool b);
};
// @fnv 0x00b94240
int* __thiscall FUN_00b94240_Class::FUN_00b94240(bool abFree)
{
    *(int**)this = &DAT_010b78b8;
    *(int**)((char*)this + 0x6c) = &DAT_010b7898;
    FUN_00c03a20();
    if ((char)abFree & 1)
        operator delete(this, 0xd0);
    return (int*)this;
}

namespace fnv_00b94280 {
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void SetSize(unsigned int);
};
extern int DAT_010b7a2c;
extern int DAT_010b7a50;
struct FUN_00b94280_class : public ImageSpaceEffectShader
{
    FUN_00b94280_class();
};
// @fnv 0x00b94280
FUN_00b94280_class::FUN_00b94280_class()
{
    *(int*)((char*)this + 0x00) = (int)&DAT_010b7a50;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b7a2c;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(2);
}
}  // namespace fnv_00b94280

extern "C" void __cdecl _delete(void*, unsigned int);
extern int DAT_010b7a50;
extern int DAT_010b7a2c;
void FUN_00c03a20();

struct FUN_00b94390_class
{
    FUN_00b94390_class* __thiscall FUN_00b94390(bool b);
};

// @fnv 0x00b94390
FUN_00b94390_class* __thiscall FUN_00b94390_class::FUN_00b94390(bool abFree)
{
    *reinterpret_cast<int**>(this) = &DAT_010b7a50;
    *reinterpret_cast<int**>(reinterpret_cast<char*>(this) + 0x6c) = &DAT_010b7a2c;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return this;
}

extern "C" void __cdecl _delete(void*, unsigned int);
extern int DAT_010b7bf0;
extern int DAT_010b7bcc;
void FUN_00c03a20();
struct FUN_00b944e0_class
{
    FUN_00b944e0_class* __thiscall FUN_00b944e0(bool flag);
};
// @fnv 0x00b944e0
FUN_00b944e0_class* __thiscall FUN_00b944e0_class::FUN_00b944e0(bool abFree)
{
    *(int*)this = (int)&DAT_010b7bf0;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b7bcc;
    FUN_00c03a20();
    if (abFree & 1)
        _delete(this, 0xd0);
    return this;
}

struct FUN_00b9cfd0_class
{
    void __thiscall AssignRefCounted(void* p);
};
// Replaces the ref-counted pointer at offset 0x1a0, releasing the old object and incrementing the new one's reference count.
// @fnv 0x00b9cfd0
void __thiscall FUN_00b9cfd0_class::AssignRefCounted(void* apObject)
{
    void* old = *(void**)((char*)this + 0x1a0);
    if (old != apObject)
    {
        if (old)
        {
            if (InterlockedDecrement((volatile long*)((char*)old + 4)) == 0)
                ((void(__thiscall**)(void*)) * (void**)((char*)old + 0))[1](old);
        }
        *(void**)((char*)this + 0x1a0) = apObject;
        if (apObject)
            InterlockedIncrement((volatile long*)((char*)apObject + 4));
    }
}

struct NiRenderer
{
    void* vtbl;
};
extern NiRenderer* DAT_011f9508;
extern int DAT_011ff9d8[];
extern unsigned int DAT_011ffd28;
extern unsigned int DAT_011ffd2c;
extern unsigned int DAT_011ffd30;
// Adds d to three counters indexed by DAT_011ffd28/2c/30, first issuing renderer calls 0xbe/0xbf/0xc0 with a, b, c when each counter is zero.
// @fnv 0x00b983d0
void __cdecl FUN_00b983d0(int a, int b, int c, int d)
{
    unsigned int e = DAT_011ffd28;
    if (DAT_011ff9d8[e] == 0)
        ((void(__thiscall*)(void*, unsigned int, int, int, int))(*(void***)*(
            void**)((char*)DAT_011f9508 + 0x8b8))[0x68 / 4])(*(void**)((char*)DAT_011f9508 + 0x8b8), 0xbe, a, 0, 0);
    DAT_011ff9d8[e] += d;
    e = DAT_011ffd2c;
    if (DAT_011ff9d8[e] == 0)
        ((void(__thiscall*)(void*, unsigned int, int, int, int))(*(void***)*(
            void**)((char*)DAT_011f9508 + 0x8b8))[0x68 / 4])(*(void**)((char*)DAT_011f9508 + 0x8b8), 0xbf, b, 0, 0);
    DAT_011ff9d8[e] += d;
    e = DAT_011ffd30;
    if (DAT_011ff9d8[e] == 0)
        ((void(__thiscall*)(void*, unsigned int, int, int, int))(*(void***)*(
            void**)((char*)DAT_011f9508 + 0x8b8))[0x68 / 4])(*(void**)((char*)DAT_011f9508 + 0x8b8), 0xc0, c, 0, 0);
    DAT_011ff9d8[e] += d;
}

extern int DAT_010b0518;
extern int DAT_010b04f4;

struct FUN_00b8d330 : public ImageSpaceEffectShader
{
    int* m_06c;
    NiTPrimitiveArray_ImageSpaceTexture___ m_94;
    FUN_00b8d330();
};

// @fnv 0x00b8d330
FUN_00b8d330::FUN_00b8d330()
{
    *(int**)(char*)this = (int*)&DAT_010b0518;
    *(int**)((char*)this + 0x6c) = (int*)&DAT_010b04f4;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(3);
}

struct FUN_00b8d850 : ImageSpaceEffectShader
{
    int m_000[0x6c / 4];
    int m_6c;
    int m_070[0x94 / 4 - 0x6c / 4];
    NiTPrimitiveArray_ImageSpaceTexture___ m_094;
    FUN_00b8d850();
};

// @fnv 0x00b8d850
FUN_00b8d850::FUN_00b8d850()
{
    m_000[0] = (int)&DAT_010b0a00;
    m_6c = (int)&DAT_010b09dc;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(2);
}

struct ImageSpaceTexture;
struct FUN_00b8dae0_class : public ImageSpaceEffectShader
{
    FUN_00b8dae0_class();
    ~FUN_00b8dae0_class();
};
// Initialises the object's vtable pointers and sets the embedded texture array at offset 0x94 to size 2.
// @fnv 0x00b8dae0
FUN_00b8dae0_class::FUN_00b8dae0_class()
{
    *(int*)this = (int)&DAT_010b0d40;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b0d1c;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(2);
}

struct FUN_00b8dc30_class : public ImageSpaceEffectShader
{
    FUN_00b8dc30_class();
};
// Initializes the object's vtable pointers and sets the size of the texture array at offset 0x94 to 2.
// @fnv 0x00b8dc30
FUN_00b8dc30_class::FUN_00b8dc30_class()
{
    int* v = (int*)this;
    v[0] = (int)&DAT_010b0ec0;
    v[0x1b] = (int)&DAT_010b0e9c;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(2);
}

struct FUN_00b8ded0 : ImageSpaceEffectShader
{
    int m_00b2d8c;
    int m_00b2db0;
    void FUN_00c03a20();
    FUN_00b8ded0();
    ~FUN_00b8ded0();
};
// Sets two vtable pointers and initialises the texture array at offset 0x94 with a size of 2.
// @fnv 0x00b8ded0
FUN_00b8ded0::FUN_00b8ded0()
{
    *(int*)this = (int)&DAT_010b11c0;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b119c;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(2);
}

struct FUN_00b8e170 : ImageSpaceEffectShader
{
    char m_00b8e170[0x95 - sizeof(ImageSpaceEffectShader)];
    NiTPrimitiveArray_ImageSpaceTexture___ m_00b8e204;
    FUN_00b8e170();
};
// Initialises the vtable pointers and sets the embedded texture array to size 2.
// @fnv 0x00b8e170
FUN_00b8e170::FUN_00b8e170()
{
    ((int*)this)[0] = (int)&DAT_010b14c0;
    ((int*)this)[0x1b] = (int)&DAT_010b14a0;
    m_00b8e204.SetSize(2);
}

struct FUN_00b8efa0 : public ImageSpaceEffectShader
{
    NiTPrimitiveArray_ImageSpaceTexture___ arr;
    FUN_00b8efa0();
};
// Initialises the vtable pointers and sets the embedded texture array at offset 0x94 to size 2.
// @fnv 0x00b8efa0
FUN_00b8efa0::FUN_00b8efa0()
{
    *(int*)this = (int)&DAT_010b2a98;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b2a74;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(2);
}

struct FUN_00b8f010_class : ImageSpaceEffectShader
{
    char m_00[0x94];
    NiTPrimitiveArray_ImageSpaceTexture___ m_094;
    FUN_00b8f010_class();
};
// Initialises the vtable pointers at offsets 0 and 0x6c and sets the texture array at 0x94 to size 2.
// @fnv 0x00b8f010
FUN_00b8f010_class::FUN_00b8f010_class()
{
    *(int*)this = (int)&DAT_010b2308;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b22e8;
    m_094.SetSize(2);
}

struct FUN_00b8f1b0 : ImageSpaceEffectShader
{
    int m_00b2470;
    int m_00b2490;
    FUN_00b8f1b0();
};

// Initialises the object's vtable pointers and sets the embedded primitive array at offset 0x94 to size 2.
// @fnv 0x00b8f1b0
FUN_00b8f1b0::FUN_00b8f1b0()
{
    *(int*)this = (int)&DAT_010b2490;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b2470;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(2);
}

struct FUN_00b8f360_class : public ImageSpaceEffectShader
{
    void* m_000;
    void* m_06c;
    FUN_00b8f360_class();
};
// Initialises two vtable pointers and sets the size of the texture array at offset 0x94 to 1.
// @fnv 0x00b8f360
FUN_00b8f360_class::FUN_00b8f360_class()
{
    m_000 = &DAT_010b2610;
    *(void**)((char*)this + 0x6c) = &DAT_010b25f0;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(1);
}

struct FUN_00b8f520_class : ImageSpaceEffectShader
{
    int m_06c;
    FUN_00b8f520_class();
};
// Initialises the object's vtable pointers and sets the embedded texture array at offset 0x94 to size 1.
// @fnv 0x00b8f520
FUN_00b8f520_class::FUN_00b8f520_class()
{
    ((int*)this)[0] = (int)&DAT_010b27a8;
    ((int*)this)[0x1b] = (int)&DAT_010b2784;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(1);
}

extern int DAT_010b2bec;
extern int DAT_010b2c10;
struct FUN_00b8f7e0 : ImageSpaceEffectShader
{
    int pad[0x1b - 1];
    int* vtbl2;
    void* arr;
    void arrSetSize(unsigned int);
    FUN_00b8f7e0();
};
// Initializes two vtable pointers and sets the embedded primitive array at offset 0x94 to size 4.
// @fnv 0x00b8f7e0
FUN_00b8f7e0::FUN_00b8f7e0()
{
    *reinterpret_cast<int**>(this) = &DAT_010b2c10;
    *reinterpret_cast<int**>(reinterpret_cast<char*>(this) + 0x6c) = &DAT_010b2bec;
    reinterpret_cast<NiTPrimitiveArray_ImageSpaceTexture___*>(reinterpret_cast<char*>(this) + 0x94)->SetSize(4);
}

extern void* DAT_010b52a0;
extern void* DAT_010b52c0;
struct FUN_00b91b80 : ImageSpaceEffectShader
{
    NiTPrimitiveArray_ImageSpaceTexture___ m_94;
    FUN_00b91b80();
};
// @fnv 0x00b91b80
FUN_00b91b80::FUN_00b91b80()
{
    *reinterpret_cast<void**>(this) = &DAT_010b52c0;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x6c) = &DAT_010b52a0;
    reinterpret_cast<NiTPrimitiveArray_ImageSpaceTexture___*>(reinterpret_cast<unsigned char*>(this) + 0x94)
        ->SetSize(3);
}

extern int DAT_010b5460;
extern int DAT_010b5480;

struct FUN_00b91cf0_class : ImageSpaceEffectShader
{
    FUN_00b91cf0_class();
    int* m_6c;
    NiTPrimitiveArray_ImageSpaceTexture___ m_94;
};

// @fnv 0x00b91cf0
FUN_00b91cf0_class::FUN_00b91cf0_class()
{
    *reinterpret_cast<int**>(this) = &DAT_010b5480;
    *reinterpret_cast<int**>(reinterpret_cast<char*>(this) + 0x6c) = &DAT_010b5460;
    reinterpret_cast<NiTPrimitiveArray_ImageSpaceTexture___*>(reinterpret_cast<char*>(this) + 0x94)->SetSize(2);
}

struct FUN_00b92a80_class : public ImageSpaceEffectShader
{
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
    int* m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    NiTPrimitiveArray_ImageSpaceTexture___ m_aiIndexedValues;
    FUN_00b92a80_class();
};
// @fnv 0x00b92a80
FUN_00b92a80_class::FUN_00b92a80_class()
{
    *reinterpret_cast<int**>(this) = &DAT_010b61f0;
    m_70 = &DAT_010b61d0;
    m_aiIndexedValues.SetSize(2);
}

struct FUN_00b92d90 : ImageSpaceEffectShader
{
    int m_00b6548;
    int m_00b6524;
    FUN_00b92d90();
};
// @fnv 0x00b92d90
FUN_00b92d90::FUN_00b92d90()
{
    *(int*)this = (int)&DAT_010b6548;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b6524;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(2);
}

extern int DAT_010b687c;
extern int DAT_010b68a0;
struct FUN_00b93030 : ImageSpaceEffectShader
{
    int m_00b2d8c;
    int m_00b2db0;
    void FUN_00c03a20();
    FUN_00b93030();
    ~FUN_00b93030();
};
// @fnv 0x00b93030
FUN_00b93030::FUN_00b93030()
{
    *reinterpret_cast<int**>(this) = &DAT_010b68a0;
    *reinterpret_cast<int**>(reinterpret_cast<char*>(this) + 0x6c) = &DAT_010b687c;
    reinterpret_cast<NiTPrimitiveArray_ImageSpaceTexture___*>(reinterpret_cast<char*>(this) + 0x94)->SetSize(2);
}

extern int DAT_010b7578;
extern int DAT_010b7598;

struct FUN_00b93e90 : ImageSpaceEffectShader
{
    void* m_000;
    void* m_004;
    void* m_008;
    void* m_00c;
    void* m_010;
    void* m_014;
    void* m_018;
    void* m_01c;
    void* m_020;
    void* m_024;
    void* m_028;
    void* m_02c;
    void* m_030;
    void* m_034;
    void* m_038;
    void* m_03c;
    void* m_040;
    void* m_044;
    void* m_048;
    void* m_04c;
    void* m_050;
    void* m_054;
    void* m_058;
    void* m_05c;
    void* m_060;
    void* m_064;
    void* m_068;
    void* m_06c;
    void* m_070;
    void* m_074;
    void* m_078;
    void* m_07c;
    void* m_080;
    void* m_084;
    void* m_088;
    void* m_08c;
    void* m_090;
    NiTPrimitiveArray_ImageSpaceTexture___ m_094;
    FUN_00b93e90();
};

// Initializes the object's pointers to two globals and sizes the texture array to 2.
// @fnv 0x00b93e90
FUN_00b93e90::FUN_00b93e90()
{
    m_000 = (void*)&DAT_010b7598;
    m_06c = (void*)&DAT_010b7578;
    m_094.SetSize(2);
}

struct FUN_00b93fe0 : ImageSpaceEffectShader
{
    int m_00b2d8c;
    int m_00b2db0;
    void FUN_00c03a20();
    FUN_00b93fe0();
    ~FUN_00b93fe0();
};
// @fnv 0x00b93fe0
FUN_00b93fe0::FUN_00b93fe0()
{
    *reinterpret_cast<int**>(this) = &DAT_010b7720;
    *reinterpret_cast<int**>((char*)this + 0x6c) = &DAT_010b7700;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(2);
}

extern int DAT_010b7bf0;
extern int DAT_010b7bcc;
struct FUN_00b943d0_class : public ImageSpaceEffectShader
{
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
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    NiTPrimitiveArray_ImageSpaceTexture___ arr;
    FUN_00b943d0_class();
};
// @fnv 0x00b943d0
FUN_00b943d0_class::FUN_00b943d0_class()
{
    *reinterpret_cast<int**>(this) = &DAT_010b7bf0;
    *reinterpret_cast<int**>(reinterpret_cast<char*>(this) + 0x6c) = &DAT_010b7bcc;
    arr.SetSize(2);
}

struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct GlobalObjectO2_00b8a9e0
{
    ~GlobalObjectO2_00b8a9e0();
    void* DestroyAndFree(bool);
};
// Runs the destructor, then deallocates this object via g_memoryManager if flag bit 0 is set, and returns this.
// @fnv 0x00b8aaf0
void* GlobalObjectO2_00b8a9e0::DestroyAndFree(bool abFree)
{
    this->GlobalObjectO2_00b8a9e0::~GlobalObjectO2_00b8a9e0();
    if (abFree & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

__declspec(thread) int g_tls_2b4 = 59;
struct FUN_00b8cad0_class
{
    void __thiscall SetValue(int value);
};
// Stores value at offset 0xac of this object, saving and restoring the thread-local g_tls_2b4 around the write.
// @fnv 0x00b8cad0
void __thiscall FUN_00b8cad0_class::SetValue(int value)
{
    int old = g_tls_2b4;
    *(int*)((char*)this + 0xac) = value;
    g_tls_2b4 = old;
}

extern int __tls_index;

struct FUN_00b8cb00_class
{
    unsigned char pad_000[0xb0];
    int m_00b0;
    void __thiscall FUN_00b8cb00(int value);
};

// Stores value into m_00b0 and re-reads/writes the thread-local tlsValue.
// @fnv 0x00b8cb00
void FUN_00b8cb00_class::FUN_00b8cb00(int value)
{
    static __declspec(thread) volatile int tlsValue = 59;
    int iTlsValue = tlsValue;
    m_00b0 = value;
    tlsValue = iTlsValue;
}

extern int DAT_010b083c;
extern int DAT_010b0860;
void FUN_00c03a20();
extern "C" void __cdecl _delete(void*, unsigned int);
struct FUN_00b8d810_class
{
    int* vtbl;
    int m_00b083c;
    void FUN_00c03a20();
    FUN_00b8d810_class(unsigned char flag);
};
// Sets the vtable and a pointer at offset 0x6c, calls FUN_00c03a20, and frees this with size 0xd0 when flag bit 0 is set.
// @fnv 0x00b8d810
FUN_00b8d810_class::FUN_00b8d810_class(unsigned char flag)
{
    vtbl = &DAT_010b0860;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b083c;
    FUN_00c03a20();
    if (flag & 1)
        _delete(this, 0xd0);
}

extern int _data_011c16bc;

struct FUN_00b8dd80_Class : public ImageSpaceEffectShader
{
    FUN_00b8dd80_Class();
};

// @fnv 0x00b8dd80
FUN_00b8dd80_Class::FUN_00b8dd80_Class()
{
    *(int**)this = &DAT_010b1040;
    *(int**)((char*)this + 0x6c) = &DAT_010b101c;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(2);
}

extern int DAT_010b5460;
extern int DAT_010b5480;
void FUN_00c03a20();
extern "C" void __cdecl _delete(void*, unsigned int);

struct FUN_00b91e00_class
{
    int* vtbl;
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
    int* m_6c;
    FUN_00b91e00_class(bool flag);
    ~FUN_00b91e00_class();
};

// Sets the vtable and m_6c pointers, calls FUN_00c03a20, and deletes this with size 0xd0 when flag bit 0 is set.
// @fnv 0x00b91e00
FUN_00b91e00_class::FUN_00b91e00_class(bool abDelete)
{
    vtbl = &DAT_010b5480;
    m_6c = &DAT_010b5460;
    FUN_00c03a20();
    if (abDelete & 1)
        _delete(this, 0xd0);
}

extern int _data_011c16bc;

struct FUN_00b92500_class : ImageSpaceEffectShader
{
    char pad[0x94 - sizeof(ImageSpaceEffectShader) + 1];
    NiTPrimitiveArray_ImageSpaceTexture___ m_ppData;  // +0x94
    FUN_00b92500_class();
};

// @fnv 0x00b92500
FUN_00b92500_class::FUN_00b92500_class()
{
    *(int*)this = (int)&DAT_010b5b10;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b5af0;
    m_ppData.SetSize(5);
}

extern int _data_011c16bc;

struct FUN_00b92bd0_class : ImageSpaceEffectShader
{
    FUN_00b92bd0_class();
};

// @fnv 0x00b92bd0
FUN_00b92bd0_class::FUN_00b92bd0_class()
{
    *(int*)this = (int)&DAT_010b6398;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b6374;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(2);
}

extern int _data_011c16bc;

struct FUN_00b932d0_class : ImageSpaceEffectShader
{
    char pad[0x6c];
    void* m_6c;
    char pad2[0x24];
    NiTPrimitiveArray_ImageSpaceTexture___ m_94;
    FUN_00b932d0_class();
};

// Initialises the vtable and m_6c pointers and sets the m_94 texture array size to 3.
// @fnv 0x00b932d0
FUN_00b932d0_class::FUN_00b932d0_class()
{
    *(void**)this = (void*)&DAT_010b6bd8;
    m_6c = (void*)&DAT_010b6bb8;
    m_94.SetSize(3);
}

struct FUN_00b93600_class : ImageSpaceEffectShader
{
    char pad[0x94 - sizeof(ImageSpaceEffectShader) + 1];
    NiTPrimitiveArray_ImageSpaceTexture___ m_ppData;  // +0x94
    FUN_00b93600_class();
};

// @fnv 0x00b93600
FUN_00b93600_class::FUN_00b93600_class()
{
    *(void**)this = (void*)&DAT_010b6d90;
    *(void**)((char*)this + 0x6c) = (void*)&DAT_010b6d70;
    m_ppData.SetSize(4);
}

struct FUN_00b93950_class : ImageSpaceEffectShader
{
    char pad[0x6c];
    int m_6c;
    char pad2[0x24];
    NiTPrimitiveArray_ImageSpaceTexture___ m_94;
    FUN_00b93950_class();
};

// @fnv 0x00b93950
FUN_00b93950_class::FUN_00b93950_class()
{
    *(int*)this = (int)&DAT_010b6f38;
    m_6c = (int)&DAT_010b6f14;
    m_94.SetSize(4);
}

extern int _data_011c16bc;

struct FUN_00b93aa0_class : ImageSpaceEffectShader
{
    void* vtbl_6c;
    FUN_00b93aa0_class();
};

// Sets the two vtables and sizes the NiTPrimitiveArray_ImageSpaceTexture___ at offset 0x94 to 4.
// @fnv 0x00b93aa0
FUN_00b93aa0_class::FUN_00b93aa0_class()
{
    *(int*)this = (int)&DAT_010b70d8;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b70b8;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x94))->SetSize(4);
}

extern int DAT_010b7898;
extern int DAT_010b78b8;
extern int _data_011c16bc;

struct FUN_00b94130_class : ImageSpaceEffectShader
{
    char pad[0x94 - sizeof(ImageSpaceEffectShader) + 1];
    NiTPrimitiveArray_ImageSpaceTexture___ m_ppData;  // +0x94
    FUN_00b94130_class();
};

// Initialises the vtable pointers at offsets 0 and 0x6c and sets the texture array's size to 2.
// @fnv 0x00b94130
FUN_00b94130_class::FUN_00b94130_class()
{
    *(int*)this = (int)&DAT_010b78b8;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b7898;
    m_ppData.SetSize(2);
}

struct FUN_00b988c0
{
    virtual ~FUN_00b988c0();
    int m_04;
    int m_08;
    int m_0c;
    FUN_00b988c0();
};

// @fnv 0x00b988c0
FUN_00b988c0::FUN_00b988c0()
{
    m_04 = 0;
    m_08 = 0;
    m_0c = 0;
}

namespace fnv_00b9b930 {
struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
extern MemoryManager _g_memoryManager;
struct FUN_00b9b930_class
{
    void __thiscall FUN_00b9b450();
    FUN_00b9b930_class* __thiscall FUN_00b9b930(bool del);
};
// Calls FUN_00b9b450, then frees this via _g_memoryManager if del is set, and returns this.
// @fnv 0x00b9b930
FUN_00b9b930_class* FUN_00b9b930_class::FUN_00b9b930(bool abDelete)
{
    FUN_00b9b450();
    if (abDelete & 1)
        _g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00b9b930

extern int DAT_011ff0f4;

// @fnv 0x00b811e0
int __cdecl FUN_00b811e0()
{
    return reinterpret_cast<int>(&DAT_011ff0f4);
}

struct FUN_00b811f0_cls
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
    unsigned int m_i68;
    void FUN_00b811f0(unsigned int value);
};

// @fnv 0x00b811f0
void FUN_00b811f0_cls::FUN_00b811f0(unsigned int value)
{
    m_i68 = value;
}

class BB81200Texture;

template <class T> class BB81200Pointer
{
  public:
    BB81200Pointer();
    ~BB81200Pointer();

    T* m_pObject;
};

class BB81200Shader
{
  public:
    BB81200Shader();
    virtual ~BB81200Shader();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int m_iType;
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
    int m_iPassCount;
    int unk5C;
};

class FUN_00b81200_cls : public BB81200Shader
{
  public:
    FUN_00b81200_cls();
    virtual ~FUN_00b81200_cls();

    BB81200Pointer<BB81200Texture> m_aspTextures[2];
    int m_iFirst;
    int m_iSecond;
};

// @fnv 0x00b81200
FUN_00b81200_cls::FUN_00b81200_cls()
{
    m_iFirst = 0;
    m_iSecond = 0;
    m_iPassCount = 7;
    m_iType = 0x17;
}

// Stand-in for the reference-counted object held by the two pointers at +0x60.
// Offset +0x00 holds the vtable pointer, +0x04 the interlocked reference count.
struct FNVRefCounted
{
    long m_refcount;
    virtual void FUN_release();
    virtual void FUN_release2();
};

// Stand-in for the object whose copy/merge operation this function performs.
// Only the members the function itself touches are named.
struct FUN_00b812b0_class
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
    FNVRefCounted* m_refs[2];
    int m_68;
    int unk6c;
    void __thiscall FUN_00ba8b10(FUN_00b812b0_class* dst, int flag);
    void __thiscall FUN_00b812b0(FUN_00b812b0_class* dst, int flag);
};

// @fnv 0x00b812b0
void FUN_00b812b0_class::FUN_00b812b0(FUN_00b812b0_class* dst, int flag)
{
    FUN_00ba8b10(dst, flag);
    for (int i = 0; i < 2; i++)
    {
        FNVRefCounted* pOldRef = dst->m_refs[i];
        if (pOldRef == m_refs[i])
            continue;
        if (pOldRef)
        {
            if (InterlockedDecrement(&pOldRef->m_refcount) == 0)
            {
                pOldRef->FUN_release2();
            }
        }
        FNVRefCounted* pNewRef = m_refs[i];
        dst->m_refs[i] = pNewRef;
        if (pNewRef)
        {
            InterlockedIncrement(&pNewRef->m_refcount);
        }
    }
    dst->m_68 = m_68;
}

struct InputFlag
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned char enabled;
};

extern "C" InputFlag* DAT_011ff4a0;
extern "C" InputFlag* DAT_011ff4a4;
extern "C" InputFlag* DAT_011ff4a8;
extern "C" InputFlag* DAT_011ff4ac;
extern "C" InputFlag* DAT_011ff4b0;
extern "C" InputFlag* DAT_011ff4b4;
extern "C" InputFlag* DAT_011ff4b8;
extern "C" InputFlag* DAT_011ff4bc;
extern "C" InputFlag* DAT_011ff4c0;
extern "C" unsigned int DAT_011ff248[];
extern "C" unsigned int DAT_011ff120[];
extern "C" unsigned char DAT_011ff118;
extern "C" unsigned char DAT_011ff119;
extern "C" unsigned char DAT_011ff11a;
extern "C" unsigned char DAT_011ff110;
extern "C" unsigned char DAT_011ff111;
extern "C" unsigned char DAT_011ff112;
extern "C" unsigned char DAT_011ff113;
extern "C" unsigned char DAT_011ff114;
extern "C" unsigned char DAT_011ff115;

// @fnv 0x00b815e0
void __cdecl UpdateInputFlags(int index)
{
    if (DAT_011ff4a0)
        DAT_011ff4a0->enabled = 1;
    DAT_011ff118 = (DAT_011ff248[index] >> 1) & 1;

    if (DAT_011ff4a4)
        DAT_011ff4a4->enabled = 1;
    DAT_011ff119 = (DAT_011ff248[index] >> 2) & 1;

    if (DAT_011ff4a8)
        DAT_011ff4a8->enabled = 1;
    DAT_011ff11a = (DAT_011ff248[index] >> 3) & 1;

    if (DAT_011ff4ac)
        DAT_011ff4ac->enabled = (DAT_011ff120[index] >> 1) & 1;
    DAT_011ff110 = (DAT_011ff120[index] >> 1) & 1;

    if (DAT_011ff4b0)
        DAT_011ff4b0->enabled = (DAT_011ff120[index] >> 2) & 1;
    DAT_011ff111 = (DAT_011ff120[index] >> 2) & 1;

    if (DAT_011ff4b4)
        DAT_011ff4b4->enabled = (DAT_011ff120[index] >> 3) & 1;
    DAT_011ff112 = (DAT_011ff120[index] >> 3) & 1;

    if (DAT_011ff4b8)
        DAT_011ff4b8->enabled = (DAT_011ff120[index] >> 4) & 1;
    DAT_011ff113 = (DAT_011ff120[index] >> 4) & 1;

    if (DAT_011ff4bc)
        DAT_011ff4bc->enabled = (DAT_011ff120[index] >> 5) & 1;
    DAT_011ff114 = (DAT_011ff120[index] >> 5) & 1;

    if (DAT_011ff4c0)
        DAT_011ff4c0->enabled = (DAT_011ff120[index] >> 6) & 1;
    DAT_011ff115 = (DAT_011ff120[index] >> 6) & 1;
}

struct FUN_00b81730_class
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void call(int value);

    int m_68[26];
    int m_6c[74];

    void CallAll();
};

// Calls call on each of the 74 entries in m_6c.
// @fnv 0x00b81730
void FUN_00b81730_class::CallAll()
{
    for (int i = 0; i < 74; ++i)
        call(m_6c[i]);
}

extern double DAT_01011588;

struct S_00b8a6e0_Foo
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
    float* unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    unsigned char unk54;
    unsigned char unk55;
    unsigned char unk56;

    void __thiscall FUN_00b8a6e0(int arg0, unsigned int arg1, unsigned int arg2);
};

// @fnv 0x00b8a6e0
void __thiscall S_00b8a6e0_Foo::FUN_00b8a6e0(int iSlot, unsigned int arg1, unsigned int arg2)
{
    float value0;
    float value1;

    if (iSlot < 3)
    {
        float zero = 0.0f;
        if (iSlot == 0 || reinterpret_cast<unsigned char*>(this)[iSlot + 0x54] != 0)
        {
            float num0 = static_cast<float>(arg1);
            value0 = static_cast<float>(DAT_01011588 / num0);

            float num1 = static_cast<float>(arg2);
            value1 = static_cast<float>(DAT_01011588 / num1);
        }
        else
        {
            value0 = zero;
            value1 = zero;
        }

        float* output = unk3c;
        iSlot <<= 2;
        output[iSlot] = value0;
        output[iSlot + 1] = value1;
        output[iSlot + 2] = zero;
        output[iSlot + 3] = zero;
    }
}

class B8C690Texture
{
  public:
    virtual ~B8C690Texture();
    virtual void DeleteThis();

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement((volatile long*)&m_uiRefCount))
            DeleteThis();
    }
};

class B8C690Shader
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
    NiPointer<B8C690Texture> m_spTexture0;
    NiPointer<B8C690Texture> m_spTexture2;
    NiPointer<B8C690Texture> m_spTexture1;
    int unk1FC;
    NiPointer<B8C690Texture> m_spTexture3;

    void ClearTextures();
};

// Clears all four texture smart pointers (m_spTexture0 through m_spTexture3) to null.
// @fnv 0x00b8c690
void B8C690Shader::ClearTextures()
{
    m_spTexture0 = 0;
    m_spTexture1 = 0;
    m_spTexture2 = 0;
    m_spTexture3 = 0;
}

extern __declspec(thread) int g_tls_2b4;
struct FUN_00b8cc20_class
{
    void __thiscall AccumulateComponentValues(int mode, int component, const float* values, float scale);
};
// Saves the TLS context, sets it to 39, and for two entries adds values[index]*scale into a component offset of this, then restores the context.
// @fnv 0x00b8cc20
void __thiscall FUN_00b8cc20_class::AccumulateComponentValues(int mode, int component, const float* values, float scale)
{
    int previousContext = g_tls_2b4;
    g_tls_2b4 = 39;
    int index = 0;
    float* destination = (float*)((char*)this + component * 4 + 0xb4);
    do
    {
        switch (mode)
        {
        case 0:
            destination[15] += values[index] * scale;
            break;
        case 1:
            destination[0] += values[index] * scale;
            break;
        case 3:
            destination[25] += values[index] * scale;
            break;
        }
        ++index;
        destination += 38;
    } while (index < 2);
    g_tls_2b4 = previousContext;
}

extern int DAT_010b0158;
extern int DAT_010b0674;
extern int DAT_010b066c;
extern int DAT_010a93ec;
extern int DAT_010a93cc;
void* __cdecl FUN_00ec61c0(void*, int, unsigned int);

struct ShaderArgument_00b8d3a0
{
    const void* source;
    unsigned int flags;
    unsigned int count;
    float components[16];
};

struct ShaderController_00b8d3a0
{
    void** vtable;
    void ConfigureAndRunShader();
};

typedef void(__thiscall* ConfigureShader_00b8d3a0)(ShaderController_00b8d3a0*, ShaderArgument_00b8d3a0*,
                                                   ShaderArgument_00b8d3a0*, const int*, const int*, const int*);
typedef void(__thiscall* RunShader_00b8d3a0)(ShaderController_00b8d3a0*);

// Builds two zeroed shader arguments from global sources, calls the vtable configure function with three globals, then runs the shader.
// @fnv 0x00b8d3a0
void ShaderController_00b8d3a0::ConfigureAndRunShader()
{
    ShaderArgument_00b8d3a0 first;
    first.source = &DAT_010b0158;
    first.flags = 0;
    first.count = 0;
    FUN_00ec61c0(first.components, 0, sizeof(first.components));

    ShaderArgument_00b8d3a0 second;
    second.source = &DAT_010b0674;
    second.flags = 0;
    second.count = 0;
    FUN_00ec61c0(second.components, 0, sizeof(second.components));

    ConfigureShader_00b8d3a0 configure = reinterpret_cast<ConfigureShader_00b8d3a0>(vtable[0x13c / 4]);
    configure(this, &first, &second, &DAT_010b066c, &DAT_010a93ec, &DAT_010a93cc);

    RunShader_00b8d3a0 run = reinterpret_cast<RunShader_00b8d3a0>(vtable[0x14c / 4]);
    run(this);
}

extern char DAT_01011584;
extern "C" void __cdecl FUN_00ec61c0(void* p, unsigned int v, unsigned int n);

struct FUN_00b8d620_frame
{
    const char* unk00;
    const char* unk04;
    const char* unk08;
    unsigned int unk0C;
    unsigned int unk10[15];
    const char* unk4C;
    unsigned int unk50;
    unsigned int unk54[17];
};

class FUN_00b8d620_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F(void* a, void* b, const char* c, const char* d, const char* e);
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    void InitAlphaMultShader();
};

// Fills a shader parameter frame with the base and copy HLSL paths, zeroes the remaining fields, then calls v4F to create the ALPHAMULT shader and v53.
// @fnv 0x00b8d620
void FUN_00b8d620_cls::InitAlphaMultShader()
{
    FUN_00b8d620_frame f;
    f.unk4C = "imagespace\\1x\\v\\base.v.hlsl";
    f.unk50 = 0;
    FUN_00ec61c0((char*)&f + 0x54, 0, 0x44);
    f.unk00 = "imagespace\\1x\\p\\copy.p.hlsl";
    f.unk04 = "ALPHAMULT";
    f.unk08 = (const char*)&DAT_01011584;
    f.unk0C = 0;
    FUN_00ec61c0((char*)&f + 0x10, 0, 0x3c);
    this->v4F((char*)&f + 0x4C, &f, "ALPHAMULT", "vs_1_1", "ps_2_0");
    this->v53();
}

extern char DAT_01011584;
extern "C" void __cdecl FUN_00ec61c0(void* p, unsigned int v, unsigned int n);

struct FUN_00b8d770_frame
{
    const char* unk00;
    const char* unk04;
    const char* unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14[14];
    const char* unk4C;
    unsigned int unk50;
    unsigned int unk54[17];
};

class FUN_00b8d770_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F(void* a, void* b, const char* c, const char* d, const char* e);
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    void CreateBlendShader();
};

// Fills a shader descriptor with base/blend HLSL paths and TEX2, zeroes the remaining fields, then calls v4F to create the BLEND shader and v53.
// @fnv 0x00b8d770
void FUN_00b8d770_cls::CreateBlendShader()
{
    FUN_00b8d770_frame f;
    f.unk00 = "imagespace\\1x\\v\\base.v.hlsl";
    f.unk04 = "TEX2";
    f.unk08 = (const char*)&DAT_01011584;
    f.unk0C = 0;
    f.unk10 = 0;
    FUN_00ec61c0((char*)&f + 0x14, 0, 0x38);
    f.unk4C = "imagespace\\2x\\p\\blend.p.hlsl";
    f.unk50 = 0;
    FUN_00ec61c0((char*)&f + 0x54, 0, 0x44);
    this->v4F(&f, (char*)&f + 0x4C, "BLEND", "vs_1_1", "ps_2_0");
    this->v53();
}

namespace fnv_00b8d8c0 {
extern "C" void* __cdecl FUN_00ec61c0(void*, int, unsigned);
struct S_00b8d8c0_Desc
{
    const char* unk00;
    const char* unk04;
    const void* unk08;
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
};
struct S_00b8d8c0_Cls
{
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
    virtual void v0a()
    {}
    virtual void v0b()
    {}
    virtual void v0c()
    {}
    virtual void v0d()
    {}
    virtual void v0e()
    {}
    virtual void v0f()
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
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v1a()
    {}
    virtual void v1b()
    {}
    virtual void v1c()
    {}
    virtual void v1d()
    {}
    virtual void v1e()
    {}
    virtual void v1f()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v2a()
    {}
    virtual void v2b()
    {}
    virtual void v2c()
    {}
    virtual void v2d()
    {}
    virtual void v2e()
    {}
    virtual void v2f()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v3a()
    {}
    virtual void v3b()
    {}
    virtual void v3c()
    {}
    virtual void v3d()
    {}
    virtual void v3e()
    {}
    virtual void v3f()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual void v45()
    {}
    virtual void v46()
    {}
    virtual void v47()
    {}
    virtual void v48()
    {}
    virtual void v49()
    {}
    virtual void v4a()
    {}
    virtual void v4b()
    {}
    virtual void v4c()
    {}
    virtual void v4d()
    {}
    virtual void v4e()
    {}
    virtual void v13c(S_00b8d8c0_Desc* a, S_00b8d8c0_Desc* b, const char* c, const char* d, const char* e);
    virtual void v140()
    {}
    virtual void v144()
    {}
    virtual void v148()
    {}
    virtual void v14c();
    void FUN_00b8d8c0();
};
// @fnv 0x00b8d8c0
void S_00b8d8c0_Cls::FUN_00b8d8c0()
{
    S_00b8d8c0_Desc s1;
    S_00b8d8c0_Desc s2;
    s1.unk00 = "imagespace\\1x\\v\\base.v.hlsl";
    s1.unk04 = 0;
    FUN_00ec61c0(&s1.unk08, 0, 0x44);
    s2.unk00 = "imagespace\\2x\\p\\blur.p.hlsl";
    s2.unk04 = 0;
    FUN_00ec61c0(&s2.unk08, 0, 0x44);
    v13c(&s1, &s2, "BLUR", "vs_1_1", "ps_2_a");
    v14c();
}
}  // namespace fnv_00b8d8c0

extern "C" void* DAT_01063f30;
extern "C" void __cdecl ShaderStringInit(void* buf, int zero, unsigned int cap);

struct ShaderBuildFrame
{
    const char* m_pszFile;
    const char* m_pszProfile;
    void* m_pBuildData;
    unsigned int m_uiValue1;
    unsigned int m_buf2[15];
    const char* m_pcProgramName;
    unsigned int m_uiNameHash;
    unsigned int m_buf1[17];
};

class FUN_00b8da00_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F(void* a, void* b, const char* c, const char* d, const char* e);
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    void InitBlur3Shader();
};

// Fills a ShaderBuildFrame with the base.v.hlsl and blur2.p.hlsl shader paths and profiles, then calls v4F with BLUR3, vs_1_1 and ps_2_a.
// @fnv 0x00b8da00
void FUN_00b8da00_cls::InitBlur3Shader()
{
    ShaderBuildFrame f;
    f.m_pcProgramName = "imagespace\\1x\\v\\base.v.hlsl";
    f.m_uiNameHash = 0;
    ShaderStringInit(f.m_buf1, 0, 0x44);
    f.m_pszFile = "imagespace\\2x\\p\\blur2.p.hlsl";
    f.m_pszProfile = "TEXTAP";
    f.m_pBuildData = &DAT_01063f30;
    f.m_uiValue1 = 0;
    ShaderStringInit(f.m_buf2, 0, 0x3c);
    this->v4F(&f.m_pcProgramName, &f.m_pszFile, "BLUR3", "vs_1_1", "ps_2_a");
    this->v53();
}

namespace fnv_00b8db50 {
extern "C" void* __cdecl FUN_00ec61c0(void*, int, unsigned);
struct S_00b8db50_Desc
{
    const char* unk00;
    const char* unk04;
    const void* unk08;
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
};
extern "C" int DAT_01063f18;
struct S_00b8db50_Cls
{
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
    virtual void v0a()
    {}
    virtual void v0b()
    {}
    virtual void v0c()
    {}
    virtual void v0d()
    {}
    virtual void v0e()
    {}
    virtual void v0f()
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
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v1a()
    {}
    virtual void v1b()
    {}
    virtual void v1c()
    {}
    virtual void v1d()
    {}
    virtual void v1e()
    {}
    virtual void v1f()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v2a()
    {}
    virtual void v2b()
    {}
    virtual void v2c()
    {}
    virtual void v2d()
    {}
    virtual void v2e()
    {}
    virtual void v2f()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v3a()
    {}
    virtual void v3b()
    {}
    virtual void v3c()
    {}
    virtual void v3d()
    {}
    virtual void v3e()
    {}
    virtual void v3f()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual void v45()
    {}
    virtual void v46()
    {}
    virtual void v47()
    {}
    virtual void v48()
    {}
    virtual void v49()
    {}
    virtual void v4a()
    {}
    virtual void v4b()
    {}
    virtual void v4c()
    {}
    virtual void v4d()
    {}
    virtual void v4e()
    {}
    virtual void v13c(S_00b8db50_Desc* a, S_00b8db50_Desc* b, const char* c, const char* d, const char* e);
    virtual void v140()
    {}
    virtual void v144()
    {}
    virtual void v148()
    {}
    virtual void v14c();
    void FUN_00b8db50();
};
// @fnv 0x00b8db50
void S_00b8db50_Cls::FUN_00b8db50()
{
    S_00b8db50_Desc s1;
    S_00b8db50_Desc s2;
    s1.unk00 = "imagespace\\1x\\v\\base.v.hlsl";
    s1.unk04 = 0;
    FUN_00ec61c0(&s1.unk08, 0, 0x44);
    s2.unk00 = "imagespace\\2x\\p\\blur2.p.hlsl";
    s2.unk04 = "TEXTAP";
    s2.unk08 = &DAT_01063f18;
    s2.unk0c = 0;
    FUN_00ec61c0(&s2.unk10, 0, 0x3c);
    v13c(&s1, &s2, "BLUR5", "vs_1_1", "ps_2_a");
    v14c();
}
}  // namespace fnv_00b8db50

extern "C" void __cdecl ZeroBlock(void* p, int value, unsigned int size);
extern "C" unsigned char DAT_01063f00;

struct SS0
{
    const char* unk00;
    const char* unk04;
    void* unk08;
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
};
struct SS1
{
    const char* unk00;
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
};

class FUN_00b8dca0_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F(SS1* a1, SS0* a2, const char* a3, const char* a4, const char* a5);
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    void CreateBlur7Shader();
};

// Fills two shader descriptor structs with HLSL paths and technique names, then calls v4F to create the "BLUR7" shader and v53.
// @fnv 0x00b8dca0
void FUN_00b8dca0_cls::CreateBlur7Shader()
{
    SS1 s1;
    SS0 s0;
    s1.unk00 = "imagespace\\1x\\v\\base.v.hlsl";
    s1.unk04 = 0;
    ZeroBlock(&s1.unk08, 0, 0x44);
    s0.unk00 = "imagespace\\2x\\p\\blur2.p.hlsl";
    s0.unk04 = "TEXTAP";
    s0.unk08 = &DAT_01063f00;
    s0.unk0C = 0;
    ZeroBlock(&s0.unk10, 0, 0x3c);
    this->v4F(&s1, &s0, "BLUR7", "vs_1_1", "ps_2_a");
    this->v53();
}

extern char DAT_01063ee8;
extern "C" void __cdecl FUN_00ec61c0(void* p, unsigned int v, unsigned int n);

struct FUN_00b8ddf0_frame
{
    const char* unk00;
    const char* unk04;
    const char* unk08;
    unsigned int unk0C;
    unsigned int unk10[15];
    const char* unk4C;
    unsigned int unk50;
    unsigned int unk54[17];
};

class FUN_00b8ddf0_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F(void* a, void* b, const char* c, const char* d, const char* e);
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    void CreateBlur9Shader();
};

// Fills a shader parameter frame with the base vertex shader and blur2 pixel shader paths, then calls v4F to create the "BLUR9" shader and v53.
// @fnv 0x00b8ddf0
void FUN_00b8ddf0_cls::CreateBlur9Shader()
{
    FUN_00b8ddf0_frame f;
    f.unk4C = "imagespace\\1x\\v\\base.v.hlsl";
    f.unk50 = 0;
    FUN_00ec61c0((char*)&f + 0x54, 0, 0x44);
    f.unk00 = "imagespace\\2x\\p\\blur2.p.hlsl";
    f.unk04 = "TEXTAP";
    f.unk08 = (const char*)&DAT_01063ee8;
    f.unk0C = 0;
    FUN_00ec61c0((char*)&f + 0x10, 0, 0x3c);
    this->v4F((char*)&f + 0x4C, &f, "BLUR9", "vs_1_1", "ps_2_a");
    this->v53();
}

namespace fnv_00b8df40 {
extern "C" void* __cdecl FUN_00ec61c0(void*, int, unsigned);
struct S_00b8df40_Desc
{
    const char* unk00;
    const char* unk04;
    const char* unk08;
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
};
struct S_00b8df40_Cls
{
    virtual void v00()
    {}
    virtual void v04()
    {}
    virtual void v08()
    {}
    virtual void v0c()
    {}
    virtual void v10()
    {}
    virtual void v14()
    {}
    virtual void v18()
    {}
    virtual void v1c()
    {}
    virtual void v20()
    {}
    virtual void v24()
    {}
    virtual void v28()
    {}
    virtual void v2c()
    {}
    virtual void v30()
    {}
    virtual void v34()
    {}
    virtual void v38()
    {}
    virtual void v3c()
    {}
    virtual void v40()
    {}
    virtual void v44()
    {}
    virtual void v48()
    {}
    virtual void v4c()
    {}
    virtual void v50()
    {}
    virtual void v54()
    {}
    virtual void v58()
    {}
    virtual void v5c()
    {}
    virtual void v60()
    {}
    virtual void v64()
    {}
    virtual void v68()
    {}
    virtual void v6c()
    {}
    virtual void v70()
    {}
    virtual void v74()
    {}
    virtual void v78()
    {}
    virtual void v7c()
    {}
    virtual void v80()
    {}
    virtual void v84()
    {}
    virtual void v88()
    {}
    virtual void v8c()
    {}
    virtual void v90()
    {}
    virtual void v94()
    {}
    virtual void v98()
    {}
    virtual void v9c()
    {}
    virtual void va0()
    {}
    virtual void va4()
    {}
    virtual void va8()
    {}
    virtual void vac()
    {}
    virtual void vb0()
    {}
    virtual void vb4()
    {}
    virtual void vb8()
    {}
    virtual void vbc()
    {}
    virtual void vc0()
    {}
    virtual void vc4()
    {}
    virtual void vc8()
    {}
    virtual void vcc()
    {}
    virtual void vd0()
    {}
    virtual void vd4()
    {}
    virtual void vd8()
    {}
    virtual void vdc()
    {}
    virtual void ve0()
    {}
    virtual void ve4()
    {}
    virtual void ve8()
    {}
    virtual void vec()
    {}
    virtual void vf0()
    {}
    virtual void vf4()
    {}
    virtual void vf8()
    {}
    virtual void vfc()
    {}
    virtual void v100()
    {}
    virtual void v104()
    {}
    virtual void v108()
    {}
    virtual void v10c()
    {}
    virtual void v110()
    {}
    virtual void v114()
    {}
    virtual void v118()
    {}
    virtual void v11c()
    {}
    virtual void v120()
    {}
    virtual void v124()
    {}
    virtual void v128()
    {}
    virtual void v12c()
    {}
    virtual void v130()
    {}
    virtual void v134()
    {}
    virtual void v138()
    {}
    virtual void v13c(S_00b8df40_Desc* a, S_00b8df40_Desc* b, const char* c, const char* d, const char* e);
    virtual void v140()
    {}
    virtual void v144()
    {}
    virtual void v148()
    {}
    virtual void v14c();
    void InitBlur11Shader();
};
// @fnv 0x00b8df40
void S_00b8df40_Cls::InitBlur11Shader()
{
    S_00b8df40_Desc s1;
    S_00b8df40_Desc s2;
    s1.unk00 = "imagespace\\1x\\v\\base.v.hlsl";
    s1.unk04 = 0;
    FUN_00ec61c0(&s1.unk08, 0, 0x44);
    s2.unk00 = "imagespace\\2x\\p\\blur2.p.hlsl";
    s2.unk04 = "TEXTAP";
    s2.unk08 = "11";
    s2.unk0c = 0;
    FUN_00ec61c0(&s2.unk10, 0, 0x3c);
    v13c(&s1, &s2, "BLUR11", "vs_1_1", "ps_2_a");
    v14c();
}
}  // namespace fnv_00b8df40

extern "C" void* fnv_zlib_memset(void* dst, int c, int n);

struct B8E090Macro
{
    const char* m_pcName;
    const char* m_pcDefinition;
};

struct B8E090ShaderFile
{
    const char* m_pcFile;
    B8E090Macro m_akMacros[9];
};

class B8E090ImageSpaceEffect
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
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void vfunc2D();
    virtual void vfunc2E();
    virtual void vfunc2F();
    virtual void vfunc30();
    virtual void vfunc31();
    virtual void vfunc32();
    virtual void vfunc33();
    virtual void vfunc34();
    virtual void vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc3A();
    virtual void vfunc3B();
    virtual void vfunc3C();
    virtual void vfunc3D();
    virtual void vfunc3E();
    virtual void vfunc3F();
    virtual void vfunc40();
    virtual void vfunc41();
    virtual void vfunc42();
    virtual void vfunc43();
    virtual void vfunc44();
    virtual void vfunc45();
    virtual void vfunc46();
    virtual void vfunc47();
    virtual void vfunc48();
    virtual void vfunc49();
    virtual void vfunc4A();
    virtual void vfunc4B();
    virtual void vfunc4C();
    virtual void vfunc4D();
    virtual void vfunc4E();
    virtual void CreateShaders(B8E090ShaderFile* pkVertex, B8E090ShaderFile* pkPixel, const char* pcName,
                               const char* pcVSVersion, const char* pcPSVersion);
    virtual void vfunc50();
    virtual void vfunc51();
    virtual void vfunc52();
    virtual void SetupShaders();

    void CreateBlur13Shaders();
};

// Builds vertex and pixel shader file descriptors for BLUR13 and calls CreateShaders followed by SetupShaders.
// @fnv 0x00b8e090
void B8E090ImageSpaceEffect::CreateBlur13Shaders()
{
    B8E090ShaderFile kVertexDelta;
    kVertexDelta.m_pcFile = "imagespace\\1x\\v\\base.v.hlsl";
    kVertexDelta.m_akMacros[0].m_pcName = 0;
    fnv_zlib_memset(&kVertexDelta.m_akMacros[0].m_pcDefinition, 0, sizeof(kVertexDelta) - 8);
    B8E090ShaderFile kPixel;
    kPixel.m_pcFile = "imagespace\\2x\\p\\blur2.p.hlsl";
    kPixel.m_akMacros[0].m_pcName = "TEXTAP";
    kPixel.m_akMacros[0].m_pcDefinition = "13";
    kPixel.m_akMacros[1].m_pcName = 0;
    fnv_zlib_memset(&kPixel.m_akMacros[1].m_pcDefinition, 0, sizeof(kPixel) - 0x10);
    CreateShaders(&kVertexDelta, &kPixel, "BLUR13", "vs_1_1", "ps_2_a");
    SetupShaders();
}

extern "C" void __cdecl FUN_00ec61c0(void* p, unsigned int v, unsigned int n);

struct FUN_00b8e1e0_frame
{
    const char* unk00;
    const char* unk04;
    const char* unk08;
    unsigned int unk0C;
    unsigned int unk10[15];
    const char* unk4C;
    unsigned int unk50;
    unsigned int unk54[17];
};

class FUN_00b8e1e0_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F(void* a, void* b, const char* c, const char* d, const char* e);
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    void InitBlur15Shader();
};

// Fills a shader frame with the BLUR15 imagespace shader paths and parameters, then passes it to v4F and calls v53.
// @fnv 0x00b8e1e0
void FUN_00b8e1e0_cls::InitBlur15Shader()
{
    FUN_00b8e1e0_frame f;
    f.unk4C = "imagespace\\1x\\v\\base.v.hlsl";
    f.unk50 = 0;
    FUN_00ec61c0((char*)&f + 0x54, 0, 0x44);
    f.unk00 = "imagespace\\2x\\p\\blur2.p.hlsl";
    f.unk04 = "TEXTAP";
    f.unk08 = "15";
    f.unk0C = 0;
    FUN_00ec61c0((char*)&f + 0x10, 0, 0x3c);
    this->v4F((char*)&f + 0x4C, &f, "BLUR15", "vs_1_1", "ps_2_a");
    this->v53();
}

extern int DAT_010b1fb0;
extern int DAT_010b1f8c;
extern "C" void __cdecl FUN_00aa1460(void*, unsigned int);
struct Shader
{
    int* vtable;
    int field_04;
    int field_08;
    int field_0c;
    int field_10;
    int field_14;
    int field_18;
    int field_1c;
    int field_20;
    int field_24;
    int field_28;
    int field_2c;
    int field_30;
    int field_34;
    int field_38;
    int field_3c;
    int field_40;
    int field_44;
    int field_48;
    int field_4c;
    int field_50;
    int field_54;
    int field_58;
    int field_5c;
    int field_60;
    int field_64;
    int field_68;
    int* vtable_6c;
    void __thiscall FUN_00c03a20();
    Shader* __thiscall DestroyShader(unsigned char flags);
};
// @fnv 0x00b8ede0
Shader* Shader::DestroyShader(unsigned char flags)
{
    vtable = &DAT_010b1fb0;
    vtable_6c = &DAT_010b1f8c;
    FUN_00c03a20();
    if (flags & 1)
        FUN_00aa1460(this, 0xd0);
    return this;
}

extern "C" void* fnv_zlib_memset(void* dst, int c, int n);

struct B8F080Macro
{
    const char* m_pcName;
    const char* m_pcDefinition;
};

struct B8F080ShaderFile
{
    const char* m_pcFile;
    B8F080Macro m_akMacros[9];
};

class B8F080ImageSpaceEffect
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
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void vfunc2D();
    virtual void vfunc2E();
    virtual void vfunc2F();
    virtual void vfunc30();
    virtual void vfunc31();
    virtual void vfunc32();
    virtual void vfunc33();
    virtual void vfunc34();
    virtual void vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc3A();
    virtual void vfunc3B();
    virtual void vfunc3C();
    virtual void vfunc3D();
    virtual void vfunc3E();
    virtual void vfunc3F();
    virtual void vfunc40();
    virtual void vfunc41();
    virtual void vfunc42();
    virtual void vfunc43();
    virtual void vfunc44();
    virtual void vfunc45();
    virtual void vfunc46();
    virtual void vfunc47();
    virtual void vfunc48();
    virtual void vfunc49();
    virtual void vfunc4A();
    virtual void vfunc4B();
    virtual void vfunc4C();
    virtual void vfunc4D();
    virtual void vfunc4E();
    virtual void CreateShaders(B8F080ShaderFile* pkVertex, B8F080ShaderFile* pkPixel, const char* pcName,
                               const char* pcVSVersion, const char* pcPSVersion);
    virtual void vfunc50();
    virtual void vfunc51();
    virtual void vfunc52();
    virtual void SetupShaders();

    void CreateCopyShaders();
};

// Builds vertex and pixel shader file descriptors with macros and calls CreateShaders for COPYRT1, then SetupShaders.
// @fnv 0x00b8f080
void B8F080ImageSpaceEffect::CreateCopyShaders()
{
    B8F080ShaderFile kVertexDelta;
    kVertexDelta.m_pcFile = "imagespace\\1x\\v\\base.v.hlsl";
    kVertexDelta.m_akMacros[0].m_pcName = 0;
    fnv_zlib_memset(&kVertexDelta.m_akMacros[0].m_pcDefinition, 0, sizeof(kVertexDelta) - 8);
    B8F080ShaderFile kPixel;
    kPixel.m_pcFile = "imagespace\\1x\\p\\copy.p.hlsl";
    kPixel.m_akMacros[0].m_pcName = "TWO_TARGETS";
    kPixel.m_akMacros[0].m_pcDefinition = "";
    kPixel.m_akMacros[1].m_pcName = 0;
    fnv_zlib_memset(&kPixel.m_akMacros[1].m_pcDefinition, 0, sizeof(kPixel) - 0x10);
    CreateShaders(&kVertexDelta, &kPixel, "COPYRT1", "vs_1_1", "ps_2_0");
    SetupShaders();
}

extern "C" void FUN_00ec61c0(void* a, unsigned int b, unsigned int c);
extern "C" int FUN_00b4f380(int a);
struct FUN_00b8f220_cls
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
    virtual void v13c(void* a, void* b, const char* c, const char* d, int e);
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    void InitStencilCopyShader();
};
// @fnv 0x00b8f220
void FUN_00b8f220_cls::InitStencilCopyShader()
{
    unsigned int f[0x26];
    f[0x13] = (unsigned int)"imagespace\\1x\\v\\base.v.hlsl";
    f[0x14] = 0;
    FUN_00ec61c0(&f[0x15], 0, 0x44);
    f[0] = (unsigned int)"imagespace\\1x\\p\\copy.p.hlsl";
    f[1] = 0;
    FUN_00ec61c0(&f[2], 0, 0x44);
    int r = FUN_00b4f380(1);
    this->v13c((void*)&f[0x13], (void*)&f[0], "STENCILCOPY", "vs_1_1", r);
    this->v14c();
}

extern char DAT_01011584;
extern "C" void FUN_00ec61c0(void* p, unsigned int v, unsigned int n);
extern "C" int FUN_00b4f380(int a);

struct FUN_00b8f3d0_frame
{
    const char* unk00;
    const char* unk04;
    const char* unk08;
    unsigned int unk0C;
    unsigned int unk10[15];
    const char* unk4C;
    unsigned int unk50;
    unsigned int unk54[17];
};

class FUN_00b8f3d0_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F(void* a, void* b, const char* c, const char* d, unsigned int e);
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    void CreateStencilCopyNoTexNoDepth();
};

// Builds a shader parameter frame with base/copy HLSL paths and NOTEX, then calls v4F with "STENCILCOPYNOTEXNODEPTH" and vs_1_1.
// @fnv 0x00b8f3d0
void FUN_00b8f3d0_cls::CreateStencilCopyNoTexNoDepth()
{
    FUN_00b8f3d0_frame f;
    f.unk4C = "imagespace\\1x\\v\\base.v.hlsl";
    f.unk50 = 0;
    FUN_00ec61c0((char*)&f + 0x54, 0, 0x44);
    f.unk00 = "imagespace\\1x\\p\\copy.p.hlsl";
    f.unk04 = "NOTEX";
    f.unk08 = (const char*)&DAT_01011584;
    f.unk0C = 0;
    FUN_00ec61c0((char*)&f + 0x10, 0, 0x3c);
    unsigned int r = FUN_00b4f380(1);
    this->v4F(&f.unk4C, &f, "STENCILCOPYNOTEXNODEPTH", "vs_1_1", r);
    this->v53();
}

extern char DAT_01011584;
extern "C" void __cdecl FUN_00ec61c0(void* p, unsigned int v, unsigned int n);

struct FUN_00b8f590_frame
{
    const char* unk00;
    const char* unk04;
    const char* unk08;
    unsigned int unk0C;
    unsigned int unk10[15];
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54[17];
};

class FUN_00b8f590_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F(void* a, void* b, const char* c, const char* d, unsigned int e);
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    void FUN_00b8f590();
};

// Fills a shader frame with the base.v.hlsl path, NOTEX and NULL names, zeroes its parameter blocks, then calls v4F and v53.
// @fnv 0x00b8f590
void FUN_00b8f590_cls::FUN_00b8f590()
{
    FUN_00b8f590_frame f;
    f.unk00 = "imagespace\\1x\\v\\base.v.hlsl";
    f.unk04 = "NOTEX";
    f.unk08 = (const char*)&DAT_01011584;
    f.unk0C = 0;
    FUN_00ec61c0((char*)&f + 0x10, 0, 0x3c);
    f.unk4C = 0;
    f.unk50 = 0;
    FUN_00ec61c0((char*)&f + 0x54, 0, 0x44);
    this->v4F(&f, (char*)&f + 0x4C, "NULL", "vs_1_1", 0);
    this->v53();
}

extern "C" void* fnv_zlib_memset(void* dst, int c, int n);

struct B8F850Macro
{
    const char* m_pcName;
    const char* m_pcDefinition;
};

struct B8F850ShaderFile
{
    const char* m_pcFile;
    B8F850Macro m_akMacros[9];
};

class B8F850ImageSpaceEffect
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
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void vfunc2D();
    virtual void vfunc2E();
    virtual void vfunc2F();
    virtual void vfunc30();
    virtual void vfunc31();
    virtual void vfunc32();
    virtual void vfunc33();
    virtual void vfunc34();
    virtual void vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc3A();
    virtual void vfunc3B();
    virtual void vfunc3C();
    virtual void vfunc3D();
    virtual void vfunc3E();
    virtual void vfunc3F();
    virtual void vfunc40();
    virtual void vfunc41();
    virtual void vfunc42();
    virtual void vfunc43();
    virtual void vfunc44();
    virtual void vfunc45();
    virtual void vfunc46();
    virtual void vfunc47();
    virtual void vfunc48();
    virtual void vfunc49();
    virtual void vfunc4A();
    virtual void vfunc4B();
    virtual void vfunc4C();
    virtual void vfunc4D();
    virtual void vfunc4E();
    virtual void CreateShaders(B8F850ShaderFile* pkVertex, B8F850ShaderFile* pkPixel, const char* pcName,
                               const char* pcVSVersion, const char* pcPSVersion);
    virtual void vfunc50();
    virtual void vfunc51();
    virtual void vfunc52();
    virtual void SetupShaders();

    void CreateDepthOfFieldShaders();
};

// Builds the base vertex and DepthOfField pixel shader file descriptors and calls CreateShaders with "DOF", then SetupShaders.
// @fnv 0x00b8f850
void B8F850ImageSpaceEffect::CreateDepthOfFieldShaders()
{
    B8F850ShaderFile kVertexDelta;
    kVertexDelta.m_pcFile = "imagespace\\1x\\v\\base.v.hlsl";
    kVertexDelta.m_akMacros[0].m_pcName = "TEX2";
    kVertexDelta.m_akMacros[0].m_pcDefinition = "";
    kVertexDelta.m_akMacros[1].m_pcName = 0;
    kVertexDelta.m_akMacros[1].m_pcDefinition = 0;
    fnv_zlib_memset(&kVertexDelta.m_akMacros[2], 0, sizeof(kVertexDelta) - 0x14);
    B8F850ShaderFile kPixel;
    kPixel.m_pcFile = "imagespace\\2x\\p\\DepthOfField.p.hlsl";
    kPixel.m_akMacros[0].m_pcName = 0;
    kPixel.m_akMacros[0].m_pcDefinition = 0;
    fnv_zlib_memset(&kPixel.m_akMacros[1], 0, sizeof(kPixel) - 0xc);
    CreateShaders(&kVertexDelta, &kPixel, "DOF", "vs_1_1", "ps_2_0");
    SetupShaders();
}

extern char DAT_01011584;
extern "C" void __cdecl FUN_00ec61c0(void* p, unsigned int v, unsigned int n);

struct ShaderSourceB
{
    const char* m_00;
    const char* m_04;
    const char* m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14[0xe];
};

struct ShaderSourceC
{
    const char* m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c[0x10];
};

struct FUN_00b8f9a0_frame
{
    ShaderSourceB a;
    ShaderSourceC b;
};

class FUN_00b8f9a0_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F(void* a, void* b, const char* c, const char* d, const char* e);
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    void InitRadialBlurShader();
};

// Fills a shader-source frame with base.v.hlsl and RadialBlur.p.hlsl paths, zeroes the remaining fields, then calls v4F with RBLUR/vs_1_1/ps_2_0 and v53.
// @fnv 0x00b8f9a0
void FUN_00b8f9a0_cls::InitRadialBlurShader()
{
    FUN_00b8f9a0_frame f;

    f.a.m_00 = "imagespace\\1x\\v\\base.v.hlsl";
    f.a.m_04 = "TEX2";
    f.a.m_08 = (const char*)&DAT_01011584;
    f.a.m_0c = 0;
    f.a.m_10 = 0;
    FUN_00ec61c0(f.a.m_14, 0, 0x38);

    f.b.m_00 = "imagespace\\2x\\p\\RadialBlur.p.hlsl";
    f.b.m_04 = 0;
    f.b.m_08 = 0;
    FUN_00ec61c0(f.b.m_0c, 0, 0x40);

    this->v4F(&f.a, &f.b, "RBLUR", "vs_1_1", "ps_2_0");
    this->v53();
}

namespace fnv_00b8faf0 {
extern char DAT_01011584;
extern "C" void __cdecl FUN_00ec61c0(void* p, unsigned int v, unsigned int n);

struct ShaderSourceB
{
    const char* m_00;
    const char* m_04;
    const char* m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14[0xe];
};

struct FUN_00b8faf0_frame
{
    ShaderSourceB lo;
    ShaderSourceB hi;
};

class FUN_00b8faf0_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F(void* a, void* b, const char* c, const char* d, const char* e);
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    void CreateRadialBlurShader();
};

// @fnv 0x00b8faf0
void FUN_00b8faf0_cls::CreateRadialBlurShader()
{
    FUN_00b8faf0_frame f;

    f.hi.m_00 = "imagespace\\1x\\v\\base.v.hlsl";
    f.hi.m_04 = "TEX2";
    f.hi.m_08 = (const char*)&DAT_01011584;
    f.hi.m_0c = 0;
    f.hi.m_10 = 0;
    FUN_00ec61c0(f.hi.m_14, 0, 0x38);

    f.lo.m_00 = "imagespace\\2x\\p\\RadialBlur.p.hlsl";
    f.lo.m_04 = "NUM_STEPS";
    f.lo.m_08 = "6.0f";
    f.lo.m_0c = 0;
    f.lo.m_10 = 0;
    FUN_00ec61c0(f.lo.m_14, 0, 0x38);

    this->v4F(&f.hi, &f.lo, "RBLURM", "vs_1_1", "ps_2_0");
    this->v53();
}
}  // namespace fnv_00b8faf0

namespace fnv_00b8fc50 {
extern "C" void FUN_00ec61c0(void* a, unsigned int b, unsigned int c);
extern int DAT_01011584;
struct FUN_00b8fc50_cls
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
    virtual void v13c(void* a, void* b, const char* c, const char* d, const char* e);
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    void FUN_00b8fc50();
};
// Fills two shader parameter blocks (base.v.hlsl/TEX2 and RadialBlur.p.hlsl/NUM_STEPS=10.0f), passes them to v13c with RBLURH/vs_1_1/ps_2_0, then calls v14c.
// @fnv 0x00b8fc50
void FUN_00b8fc50_cls::FUN_00b8fc50()
{
    unsigned int f[0x26];
    f[0x13] = (unsigned int)"imagespace\\1x\\v\\base.v.hlsl";
    f[0x14] = (unsigned int)"TEX2";
    f[0x15] = (unsigned int)&DAT_01011584;
    f[0x16] = 0;
    f[0x17] = 0;
    FUN_00ec61c0(&f[0x18], 0, 0x38);
    f[0] = (unsigned int)"imagespace\\2x\\p\\RadialBlur.p.hlsl";
    f[1] = (unsigned int)"NUM_STEPS";
    f[2] = (unsigned int)"10.0f";
    f[3] = 0;
    f[4] = 0;
    FUN_00ec61c0(&f[5], 0, 0x38);
    this->v13c((void*)&f[0x13], (void*)&f[0], "RBLURH", "vs_1_1", "ps_2_0");
    this->v14c();
}
}  // namespace fnv_00b8fc50

namespace fnv_00b8fdb0 {
extern char DAT_01011584;
extern "C" void __cdecl FUN_00ec61c0(void* p, unsigned int v, unsigned int n);

struct ShaderSourceB
{
    const char* m_00;
    const char* m_04;
    const char* m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14[0xe];
};

struct FUN_00b8fdb0_frame
{
    ShaderSourceB lo;
    ShaderSourceB hi;
};

class FUN_00b8fdb0_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F(void* a, void* b, const char* c, const char* d, const char* e);
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    void CreateDepthOfFieldMaskShader();
};

// @fnv 0x00b8fdb0
void FUN_00b8fdb0_cls::CreateDepthOfFieldMaskShader()
{
    FUN_00b8fdb0_frame f;

    f.hi.m_00 = "imagespace\\1x\\v\\base.v.hlsl";
    f.hi.m_04 = "TEX2";
    f.hi.m_08 = (const char*)&DAT_01011584;
    f.hi.m_0c = 0;
    f.hi.m_10 = 0;
    FUN_00ec61c0(f.hi.m_14, 0, 0x38);

    f.lo.m_00 = "imagespace\\2x\\p\\DepthOfField.p.hlsl";
    f.lo.m_04 = "MASK";
    f.lo.m_08 = (const char*)&DAT_01011584;
    f.lo.m_0c = 0;
    f.lo.m_10 = 0;
    FUN_00ec61c0(f.lo.m_14, 0, 0x38);

    this->v4F(&f.hi, &f.lo, "DOFMASK", "vs_1_1", "ps_2_0");
    this->v53();
}
}  // namespace fnv_00b8fdb0

extern int DAT_010b4ad0;
extern int DAT_010b4aac;
extern "C" void __cdecl FUN_00aa1460(void*, unsigned int);
void FUN_00c03a20();
struct ImageSpacePass
{
    int* primaryVtable;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    int* secondaryVtable;
    ImageSpacePass* FUN_00b91640(unsigned char flag);
};
// @fnv 0x00b91640
ImageSpacePass* ImageSpacePass::FUN_00b91640(unsigned char abFree)
{
    primaryVtable = &DAT_010b4ad0;
    secondaryVtable = &DAT_010b4aac;
    FUN_00c03a20();
    if (abFree & 1)
        FUN_00aa1460(this, 0xd0);
    return this;
}

namespace fnv_00b916f0 {
extern "C" void* __cdecl FUN_00ec61c0(void* destination, int value, unsigned int size);

extern "C" const char str_010b0158[];
extern "C" const char str_010b0130[];
extern "C" const char str_010b0124[];
extern "C" const char str_010a93cc[];
extern "C" const char str_010a93ec[];
extern "C" const char str_010b4dbc[];
extern "C" int DAT_01011584;

struct FUN_00b916f0_First
{
    const char* shader;
    int unk04;
    unsigned int data[0x44 / sizeof(unsigned int)];
};

struct FUN_00b916f0_Second
{
    const char* shader;
    const char* name;
    const int* terminator;
    unsigned int data[0x40 / sizeof(unsigned int)];
};

struct FUN_00b916f0_Object
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
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
    virtual void vfF0();
    virtual void vfF4();
    virtual void vfF8();
    virtual void vfFC();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10C();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11C();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12C();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13C(FUN_00b916f0_First* first, FUN_00b916f0_Second* second, const char* macro,
                       const char* vertexShader, const char* pixelShader);
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14C();

    void __thiscall InitializeShader();
};

// Fills two shader descriptor structs with string pointers and zeroed data, passes them with macro and shader names to vf13C, then calls vf14C.
// @fnv 0x00b916f0
void __thiscall FUN_00b916f0_Object::InitializeShader()
{
    FUN_00b916f0_First first;
    FUN_00b916f0_Second second;

    first.shader = str_010b0158;
    first.unk04 = 0;
    FUN_00ec61c0(first.data, 0, sizeof(first.data));

    second.shader = str_010b0124;
    second.name = str_010b0130;
    second.terminator = &DAT_01011584;
    FUN_00ec61c0(second.data, 0, sizeof(second.data));

    vf13C(&first, &second, str_010b4dbc, str_010a93ec, str_010a93cc);
    vf14C();
}
}  // namespace fnv_00b916f0

extern "C" void __cdecl FUN_00ec61c0(void* p, unsigned int v, unsigned int n);

struct FUN_00b91830_src
{
    const char* unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C[16];
};

class FUN_00b91830_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F(void* a, void* b, const char* c, const char* d, const char* e);
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    void CreateMapShader();
};

// Builds two shader descriptors for base.v.hlsl and map_P20.p.hlsl, passes them to v4F with MAP/vs_1_1/ps_2_0, then calls v53.
// @fnv 0x00b91830
void FUN_00b91830_cls::CreateMapShader()
{
    FUN_00b91830_src lo;
    FUN_00b91830_src hi;
    hi.unk00 = "imagespace\\1x\\v\\base.v.hlsl";
    hi.unk04 = 0;
    hi.unk08 = 0;
    FUN_00ec61c0(hi.unk0C, 0, 0x40);
    lo.unk00 = "imagespace\\2x\\p\\map_P20.p.hlsl";
    lo.unk04 = 0;
    lo.unk08 = 0;
    FUN_00ec61c0(lo.unk0C, 0, 0x40);
    this->v4F(&hi, &lo, "MAP", "vs_1_1", "ps_2_0");
    this->v53();
}

extern "C" void FUN_00ec61c0(void* a, unsigned int b, unsigned int c);
struct FUN_00b91970_cls
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
    virtual void v13c(void* a, void* b, const char* c, const char* d, const char* e);
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    void InitMenuBGShader();
};
// @fnv 0x00b91970
void FUN_00b91970_cls::InitMenuBGShader()
{
    unsigned int f[0x26];
    f[0x13] = (unsigned int)"imagespace\\1x\\v\\menuBG.v.hlsl";
    f[0x14] = 0;
    f[0x15] = 0;
    FUN_00ec61c0(&f[0x16], 0, 0x40);
    f[0] = (unsigned int)"imagespace\\1x\\p\\menuBG.p.hlsl";
    f[1] = 0;
    f[2] = 0;
    FUN_00ec61c0(&f[3], 0, 0x40);
    this->v13c((void*)&f[0x13], (void*)&f[0], "MENUBG", "vs_2_0", "ps_2_0");
    this->v14c();
}

extern "C" char DAT_010b5140;
extern "C" char DAT_010b511c;
struct FUN_00b91a40 : ImageSpaceEffectShader
{
    void* primaryVTable;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4c;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5c;
    void* unk60;
    void* unk64;
    void* unk68;
    void* secondaryVTable;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7c;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8c;
    void* unk90;
    NiTPrimitiveArray_ImageSpaceTexture___ textures;
    FUN_00b91a40();
};
// Initialises the two vtables and sets the textures array size to 2.
// @fnv 0x00b91a40
FUN_00b91a40::FUN_00b91a40()
{
    primaryVTable = &DAT_010b5140;
    secondaryVTable = &DAT_010b511c;
    textures.SetSize(2);
}

extern "C" void* fnv_zlib_memset(void* dst, int c, int n);

struct B91AB0Macro
{
    const char* m_pcName;
    const char* m_pcDefinition;
};

struct B91AB0ShaderFile
{
    const char* m_pcFile;
    B91AB0Macro m_akMacros[9];
};

class B91AB0GPUProgramCache
{
  public:
    static const char* GetPixelShaderProfile(bool bHighest);
};

class B91AB0ImageSpaceEffect
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
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void vfunc2D();
    virtual void vfunc2E();
    virtual void vfunc2F();
    virtual void vfunc30();
    virtual void vfunc31();
    virtual void vfunc32();
    virtual void vfunc33();
    virtual void vfunc34();
    virtual void vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc3A();
    virtual void vfunc3B();
    virtual void vfunc3C();
    virtual void vfunc3D();
    virtual void vfunc3E();
    virtual void vfunc3F();
    virtual void vfunc40();
    virtual void vfunc41();
    virtual void vfunc42();
    virtual void vfunc43();
    virtual void vfunc44();
    virtual void vfunc45();
    virtual void vfunc46();
    virtual void vfunc47();
    virtual void vfunc48();
    virtual void vfunc49();
    virtual void vfunc4A();
    virtual void vfunc4B();
    virtual void vfunc4C();
    virtual void vfunc4D();
    virtual void vfunc4E();
    virtual void CreateShaders(B91AB0ShaderFile* pkVertex, B91AB0ShaderFile* pkPixel, const char* pcName,
                               const char* pcVSVersion, const char* pcPSVersion);
    virtual void vfunc50();
    virtual void vfunc51();
    virtual void vfunc52();
    virtual void SetupShaders();

    void CreateCopyUnpackShaders();
};

// Builds vertex and pixel shader file descriptors for COPYUNPACK, gets the pixel shader profile, then calls CreateShaders and SetupShaders.
// @fnv 0x00b91ab0
void B91AB0ImageSpaceEffect::CreateCopyUnpackShaders()
{
    B91AB0ShaderFile kVertexDelta;
    kVertexDelta.m_pcFile = "imagespace\\1x\\v\\base.v.hlsl";
    kVertexDelta.m_akMacros[0].m_pcName = 0;
    fnv_zlib_memset(&kVertexDelta.m_akMacros[0].m_pcDefinition, 0, sizeof(kVertexDelta) - 8);
    B91AB0ShaderFile kPixel;
    kPixel.m_pcFile = "imagespace\\1x\\p\\copy.p.hlsl";
    kPixel.m_akMacros[0].m_pcName = 0;
    fnv_zlib_memset(&kPixel.m_akMacros[0].m_pcDefinition, 0, sizeof(kPixel) - 8);
    const char* pcPSVersion = B91AB0GPUProgramCache::GetPixelShaderProfile(true);
    CreateShaders(&kVertexDelta, &kPixel, "COPYUNPACK", "vs_1_1", pcPSVersion);
    SetupShaders();
}

namespace fnv_00b91bf0 {
extern "C" void* __cdecl FUN_00ec61c0(void* destination, int value, unsigned int size);
extern "C" int DAT_01011584;

struct FUN_00b91bf0_First
{
    const char* shader;
    const char* name;
    const int* terminator;
    int unk08;
    int unk0C;
    unsigned int data[0x38 / sizeof(unsigned int)];
};

struct FUN_00b91bf0_Second
{
    const char* shader;
    const char* name;
    const char* value;
    const char* macro;
    const int* terminator;
    int unk14;
    unsigned int data[0x34 / sizeof(unsigned int)];
};

struct FUN_00b91bf0_Object
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
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
    virtual void vfF0();
    virtual void vfF4();
    virtual void vfF8();
    virtual void vfFC();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10C();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11C();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12C();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13C(const FUN_00b91bf0_First* first, const FUN_00b91bf0_Second* second, const char* macro,
                       const char* vertexShader, const char* pixelShader);
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14C();

    void __thiscall InitMotionBlurShader();
};

// @fnv 0x00b91bf0
void __thiscall FUN_00b91bf0_Object::InitMotionBlurShader()
{
    FUN_00b91bf0_First first;
    FUN_00b91bf0_Second second;

    first.shader = "imagespace\\1x\\v\\base.v.hlsl";
    first.name = "TEX2";
    first.terminator = &DAT_01011584;
    first.unk08 = 0;
    first.unk0C = 0;
    FUN_00ec61c0(first.data, 0, sizeof(first.data));

    second.shader = "imagespace\\2x\\p\\MotionBlur.p.hlsl";
    second.name = "NUM_SAMPLES";
    second.value = "40.0f";
    second.macro = "NO_VELOCITY";
    second.terminator = &DAT_01011584;
    second.unk14 = 0;
    FUN_00ec61c0(second.data, 0, sizeof(second.data));

    vf13C(&first, &second, "MOTBLUR", "vs_1_1", "ps_2_0");
    vf14C();
}
}  // namespace fnv_00b91bf0

extern "C" void FUN_00ec61c0(void* a, unsigned int b, unsigned int c);
extern "C" int FUN_00b4f380(int a);
struct FUN_00b91d60_cls
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
    virtual void v13c(void* a, void* b, const char* c, const char* d, int e);
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    void InitNoiseScrollAndBlendShader();
};
// @fnv 0x00b91d60
void FUN_00b91d60_cls::InitNoiseScrollAndBlendShader()
{
    unsigned int f[0x26];
    f[0x13] = (unsigned int)"imagespace\\1x\\v\\base.v.hlsl";
    f[0x14] = 0;
    f[0x15] = 0;
    FUN_00ec61c0(&f[0x16], 0, 0x40);
    f[0] = (unsigned int)"imagespace\\2x\\p\\noise_P20.p.hlsl";
    f[1] = (unsigned int)"SCROLL_AND_BLEND";
    f[2] = 0;
    f[3] = 0;
    f[4] = 0;
    FUN_00ec61c0(&f[5], 0, 0x38);
    int r = FUN_00b4f380(1);
    this->v13c((void*)&f[0x13], (void*)&f[0], "NOISESCROLLANDBLEND", "vs_1_1", r);
    this->v14c();
}

extern "C" void FUN_00ec61c0(void* a, unsigned int b, unsigned int c);
extern "C" int FUN_00b4f380(int a);
struct FUN_00b91eb0_cls
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
    virtual void v13c(void* a, void* b, const char* c, const char* d, int e);
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    void InitNoiseNormalMapShader();
};
// @fnv 0x00b91eb0
void FUN_00b91eb0_cls::InitNoiseNormalMapShader()
{
    unsigned int f[0x26];
    f[0x13] = (unsigned int)"imagespace\\1x\\v\\base.v.hlsl";
    f[0x14] = 0;
    f[0x15] = 0;
    FUN_00ec61c0(&f[0x16], 0, 0x40);
    f[0] = (unsigned int)"imagespace\\2x\\p\\noise_P20.p.hlsl";
    f[1] = (unsigned int)"NORMALMAP";
    f[2] = 0;
    f[3] = 0;
    f[4] = 0;
    FUN_00ec61c0(&f[5], 0, 0x38);
    int r = FUN_00b4f380(1);
    this->v13c((void*)&f[0x13], (void*)&f[0], "NOISENORMALMAP", "vs_1_1", r);
    this->v14c();
}

namespace fnv_00b921f0 {
struct FUN_00b921f0_Desc;
struct FUN_00b921f0_Vt
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
    virtual void v079(FUN_00b921f0_Desc*, FUN_00b921f0_Desc*, const char*, const char*, const char*);
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
};

struct FUN_00b921f0_Buf
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c, m_30, m_34;
};

struct FUN_00b921f0_Desc
{
    const char* m_pPath;
    const char* m_pName;
    const float* m_pfValue;
    int m_i0c;
    int m_i10;
    FUN_00b921f0_Buf m_kDefines;
};

extern const float DAT_01011584;
extern "C" void* __cdecl FUN_00ec61c0(void*, int, unsigned int);

struct FUN_00b921f0_Class : public FUN_00b921f0_Vt
{
    void CreateRefractionShader();
};

// @fnv 0x00b921f0
void FUN_00b921f0_Class::CreateRefractionShader()
{
    FUN_00b921f0_Desc kDesc1;
    kDesc1.m_pPath = "imagespace\\1x\\v\\base.v.hlsl";
    kDesc1.m_pName = "TEX2";
    kDesc1.m_pfValue = &DAT_01011584;
    kDesc1.m_i0c = 0;
    kDesc1.m_i10 = 0;
    FUN_00ec61c0(&kDesc1.m_kDefines, 0, 0x38);

    FUN_00b921f0_Desc kDesc2;
    kDesc2.m_pPath = "imagespace\\2x\\p\\refraction_P20.p.hlsl";
    kDesc2.m_pName = 0;
    kDesc2.m_pfValue = 0;
    FUN_00ec61c0(&kDesc2.m_i0c, 0, 0x40);

    v079(&kDesc1, &kDesc2, "REFRACT", "vs_1_1", "ps_2_0");
    v083();
}
}  // namespace fnv_00b921f0

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct RefObj_b922d0
{
    virtual ~RefObj_b922d0();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement((volatile long*)&m_uiRefCount))
            DeleteThis();
    }
};

struct RefPtr_b922d0
{
    RefObj_b922d0* m_pObject;
    RefPtr_b922d0() : m_pObject(0)
    {}
    ~RefPtr_b922d0()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    RefPtr_b922d0& operator=(RefObj_b922d0* pObject)
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

extern RefObj_b922d0* DAT_011f9520;

struct SubBase1_b922d0
{
    virtual void v0();
    int unk[26];
};

struct SubBase2_b922d0
{
    virtual void w0();
    int unk2[9];
    NiTPrimitiveArray_ImageSpaceTexture___ m_kArr94;
    int unk3[14];
};

struct Base_c04570 : SubBase1_b922d0, SubBase2_b922d0
{
    Base_c04570();
    ~Base_c04570();
};

struct FUN_00b922d0 : Base_c04570
{
    RefPtr_b922d0 m_spD0;
    FUN_00b922d0();
    ~FUN_00b922d0();
};

// Sets the array size to 2 and assigns the global reference-counted object DAT_011f9520 to m_spD0.
// @fnv 0x00b922d0
FUN_00b922d0::FUN_00b922d0()
{
    m_kArr94.SetSize(2);
    m_spD0 = DAT_011f9520;
}

namespace fnv_00b92390 {
extern "C" char DAT_010b5ad4;
extern "C" char DAT_010b33c4;
extern "C" char DAT_01011584;
extern "C" char DAT_010b0820;
extern "C" char DAT_010b5acc;
extern "C" char DAT_010a93ec;
extern "C" int __cdecl FUN_00b4f380(int value);
extern "C" void* __cdecl FUN_00ec61c0(void* destination, int value, unsigned int size);

struct ShaderConstants
{
    unsigned int value00, value01, value02, value03, value04;
    unsigned int value05, value06, value07, value08, value09;
    unsigned int value10, value11, value12, value13, value14;
};

struct ShaderPassParameters
{
    const void* shader;
    const void* renderer;
    const void* state;
    unsigned int mode;
    ShaderConstants constants;
};

struct ShaderEffect
{
    void** vtable;
    void __thiscall ConfigureShaderPasses();
};

typedef void(__thiscall* ConfigureEffect)(ShaderEffect*, ShaderPassParameters*, ShaderPassParameters*, const void*,
                                          const void*, int);
typedef void(__thiscall* FinalizeEffect)(ShaderEffect*);

// @fnv 0x00b92390
void __thiscall ShaderEffect::ConfigureShaderPasses()
{
    ShaderPassParameters first;
    first.shader = &DAT_010b5ad4;
    first.renderer = &DAT_010b33c4;
    first.state = &DAT_01011584;
    first.mode = 0;
    FUN_00ec61c0(&first.constants, 0, sizeof(first.constants));

    ShaderPassParameters second;
    second.shader = &DAT_010b0820;
    second.renderer = &DAT_010b33c4;
    second.state = &DAT_01011584;
    second.mode = 0;
    FUN_00ec61c0(&second.constants, 0, sizeof(second.constants));

    int enabled = FUN_00b4f380(1);
    ConfigureEffect configure = (ConfigureEffect)vtable[0x13c / 4];
    configure(this, &first, &second, &DAT_010b5acc, &DAT_010a93ec, enabled);

    FinalizeEffect finalize = (FinalizeEffect)vtable[0x14c / 4];
    finalize(this);
}
}  // namespace fnv_00b92390

struct SpawnRef_b7231
{
    virtual ~SpawnRef_b7231();
    virtual void Delete();
    long m_iRefCount;
};

struct SpawnPtr_b7231
{
    SpawnRef_b7231* m_pObject;

    ~SpawnPtr_b7231()
    {
        SpawnRef_b7231* obj = m_pObject;
        if (obj)
        {
            if (InterlockedDecrement(&obj->m_iRefCount) == 0)
                obj->Delete();
        }
    }
};

struct SpawnPrimary_b7231
{
    virtual ~SpawnPrimary_b7231();
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
};

struct SpawnSecondary_b7231
{
    virtual void v00();
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
};

class FUN_00b92450_cls : public SpawnPrimary_b7231, public SpawnSecondary_b7231
{
  public:
    virtual ~FUN_00b92450_cls();
    SpawnPtr_b7231 m_ref;
};

// Destructor of a class holding a reference-counted pointer; the member's destructor releases the object.
// @fnv 0x00b92450
FUN_00b92450_cls::~FUN_00b92450_cls()
{}

extern "C" void* fnv_zlib_memset(void* dst, int c, int n);

struct B92700Macro
{
    const char* m_pcName;
    const char* m_pcDefinition;
};

struct B92700ShaderFile
{
    const char* m_pcFile;
    B92700Macro m_akMacros[9];
};

class B92700GPUProgramCache
{
  public:
    static const char* GetPixelShaderProfile(bool bHighest);
};

class B92700WaterEffect
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
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void vfunc2D();
    virtual void vfunc2E();
    virtual void vfunc2F();
    virtual void vfunc30();
    virtual void vfunc31();
    virtual void vfunc32();
    virtual void vfunc33();
    virtual void vfunc34();
    virtual void vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc3A();
    virtual void vfunc3B();
    virtual void vfunc3C();
    virtual void vfunc3D();
    virtual void vfunc3E();
    virtual void vfunc3F();
    virtual void vfunc40();
    virtual void vfunc41();
    virtual void vfunc42();
    virtual void vfunc43();
    virtual void vfunc44();
    virtual void vfunc45();
    virtual void vfunc46();
    virtual void vfunc47();
    virtual void vfunc48();
    virtual void vfunc49();
    virtual void vfunc4A();
    virtual void vfunc4B();
    virtual void vfunc4C();
    virtual void vfunc4D();
    virtual void vfunc4E();
    virtual void CreateShaders(B92700ShaderFile* pkVertex, B92700ShaderFile* pkPixel, const char* pcName,
                               const char* pcVSVersion, const char* pcPSVersion);
    virtual void vfunc50();
    virtual void vfunc51();
    virtual void vfunc52();
    virtual void SetupShaders();

    void CreateClearSimulationShaders();
};

// Builds vertex and pixel shader file descriptors for water displacement clear simulation and passes them to CreateShaders, then calls SetupShaders.
// @fnv 0x00b92700
void B92700WaterEffect::CreateClearSimulationShaders()
{
    B92700ShaderFile kVertexDelta;
    kVertexDelta.m_pcFile = "water\\2_ab\\v\\displace.v.hlsl";
    kVertexDelta.m_akMacros[0].m_pcName = 0;
    fnv_zlib_memset(&kVertexDelta.m_akMacros[0].m_pcDefinition, 0, sizeof(kVertexDelta) - 0x8);
    B92700ShaderFile kPixel;
    kPixel.m_pcFile = "water\\2_ab\\p\\displace.p.hlsl";
    kPixel.m_akMacros[0].m_pcName = "CLEAR_SIMULATION";
    kPixel.m_akMacros[0].m_pcDefinition = 0;
    kPixel.m_akMacros[1].m_pcName = 0;
    fnv_zlib_memset(&kPixel.m_akMacros[1].m_pcDefinition, 0, sizeof(kPixel) - 0x10);
    const char* pcPSVersion = B92700GPUProgramCache::GetPixelShaderProfile(true);
    CreateShaders(&kVertexDelta, &kPixel, "WATERDISPLACEMENTCLEARSIMULATION", "vs_1_1", pcPSVersion);
    SetupShaders();
}

extern char DAT_01011584;
extern "C" void __cdecl FUN_00ec61c0(void* p, unsigned int v, unsigned int n);
extern "C" int FUN_00b4f380(int a);

struct FUN_00b92850_frame
{
    const char* unk00;
    const char* unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10[15];
    const char* unk4C;
    unsigned int unk50;
    unsigned int unk54[17];
};

class FUN_00b92850_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F(void* a, void* b, const char* c, const char* d, unsigned int e);
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    void InitWaterDisplacementTexOffset();
};

// @fnv 0x00b92850
void FUN_00b92850_cls::InitWaterDisplacementTexOffset()
{
    FUN_00b92850_frame f;
    f.unk4C = "water\\2_ab\\v\\displace.v.hlsl";
    f.unk50 = 0;
    FUN_00ec61c0((char*)&f + 0x54, 0, 0x44);
    f.unk00 = "water\\2_ab\\p\\displace.p.hlsl";
    f.unk04 = "TEXCOORD_OFFSET";
    f.unk08 = 0;
    f.unk0C = 0;
    FUN_00ec61c0((char*)&f + 0x10, 0, 0x3C);
    unsigned int r = FUN_00b4f380(1);
    this->v4F(&f.unk4C, &f, "WATERDISPLACEMENTTEXOFFSET", "vs_1_1", r);
    this->v53();
}

namespace fnv_00b929a0 {
struct FUN_00b929a0_str16
{
    const char* a;
    const char* b;
    int c;
    int d;
};
struct FUN_00b929a0_obj
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
};
int __cdecl FUN_00b4f380(int x);
void __cdecl FUN_00ec61c0(void* p, int z, unsigned int n);
class FUN_00b929a0_cls
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
    virtual void v4f(void* a, void* b, const char* c, const char* d, int e);
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    void InitWadingRippleShader();
};
// @fnv 0x00b929a0
void FUN_00b929a0_cls::InitWadingRippleShader()
{
    struct Frame
    {
        FUN_00b929a0_str16 s2;
        FUN_00b929a0_obj o2;

        FUN_00b929a0_str16 s1;
        FUN_00b929a0_obj o1;
    } f;
    f.s1.a = "water\\2_ab\\v\\displace.v.hlsl";
    f.s1.b = "RIPPLE_MAKER_WADING";
    f.s1.c = 0;
    f.s1.d = 0;
    FUN_00ec61c0(&f.o1, 0, sizeof(f.o1));
    f.s2.a = "water\\2_ab\\p\\displace.p.hlsl";
    f.s2.b = "RIPPLE_MAKER_WADING";
    f.s2.c = 0;
    f.s2.d = 0;
    FUN_00ec61c0(&f.o2, 0, sizeof(f.o2));
    int r = FUN_00b4f380(1);
    this->v4f(&f.s1, &f.s2, "WATERDISPLACEMENTWADINGRIPPLE", "vs_1_1", r);
    this->v53();
}
}  // namespace fnv_00b929a0

extern "C" void* fnv_zlib_memset(void* dst, int c, int n);

struct B92AF0Macro
{
    const char* m_pcName;
    const char* m_pcDefinition;
};

struct B92AF0ShaderFile
{
    const char* m_pcFile;
    B92AF0Macro m_akMacros[9];
};

class B92AF0GPUProgramCache
{
  public:
    static const char* GetPixelShaderProfile(bool bHighest);
};

class B92AF0WaterEffect
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
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void vfunc2D();
    virtual void vfunc2E();
    virtual void vfunc2F();
    virtual void vfunc30();
    virtual void vfunc31();
    virtual void vfunc32();
    virtual void vfunc33();
    virtual void vfunc34();
    virtual void vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc3A();
    virtual void vfunc3B();
    virtual void vfunc3C();
    virtual void vfunc3D();
    virtual void vfunc3E();
    virtual void vfunc3F();
    virtual void vfunc40();
    virtual void vfunc41();
    virtual void vfunc42();
    virtual void vfunc43();
    virtual void vfunc44();
    virtual void vfunc45();
    virtual void vfunc46();
    virtual void vfunc47();
    virtual void vfunc48();
    virtual void vfunc49();
    virtual void vfunc4A();
    virtual void vfunc4B();
    virtual void vfunc4C();
    virtual void vfunc4D();
    virtual void vfunc4E();
    virtual void CreateShaders(B92AF0ShaderFile* pkVertex, B92AF0ShaderFile* pkPixel, const char* pcName,
                               const char* pcVSVersion, const char* pcPSVersion);
    virtual void vfunc50();
    virtual void vfunc51();
    virtual void vfunc52();
    virtual void SetupShaders();

    void CreateRainRippleShaders();
};

// Builds vertex and pixel shader files for the rain ripple water displacement effect, then creates and sets up the shaders.
// @fnv 0x00b92af0
void B92AF0WaterEffect::CreateRainRippleShaders()
{
    B92AF0ShaderFile kVertexDelta;
    kVertexDelta.m_pcFile = "water\\2_ab\\v\\displace.v.hlsl";
    kVertexDelta.m_akMacros[0].m_pcName = "RIPPLE_MAKER_RAIN";
    kVertexDelta.m_akMacros[0].m_pcDefinition = 0;
    kVertexDelta.m_akMacros[1].m_pcName = 0;
    fnv_zlib_memset(&kVertexDelta.m_akMacros[1].m_pcDefinition, 0, sizeof(kVertexDelta) - 0x10);
    B92AF0ShaderFile kPixel;
    kPixel.m_pcFile = "water\\2_ab\\p\\displace.p.hlsl";
    kPixel.m_akMacros[0].m_pcName = "RIPPLE_MAKER_RAIN";
    kPixel.m_akMacros[0].m_pcDefinition = 0;
    kPixel.m_akMacros[1].m_pcName = 0;
    fnv_zlib_memset(&kPixel.m_akMacros[1].m_pcDefinition, 0, sizeof(kPixel) - 0x10);
    const char* pcPSVersion = B92AF0GPUProgramCache::GetPixelShaderProfile(true);
    CreateShaders(&kVertexDelta, &kPixel, "WATERDISPLACEMENTRAINRIPPLE", "vs_1_1", pcPSVersion);
    SetupShaders();
}

extern "C" void* fnv_zlib_memset(void* dst, int c, int n);

struct B92C40Macro
{
    const char* m_pcName;
    const char* m_pcDefinition;
};

struct B92C40ShaderFile
{
    const char* m_pcFile;
    B92C40Macro m_akMacros[9];
};

class B92C40GPUProgramCache
{
  public:
    static const char* GetPixelShaderProfile(bool bHighest);
};

class B92C40WaterEffect
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
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void vfunc2D();
    virtual void vfunc2E();
    virtual void vfunc2F();
    virtual void vfunc30();
    virtual void vfunc31();
    virtual void vfunc32();
    virtual void vfunc33();
    virtual void vfunc34();
    virtual void vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc3A();
    virtual void vfunc3B();
    virtual void vfunc3C();
    virtual void vfunc3D();
    virtual void vfunc3E();
    virtual void vfunc3F();
    virtual void vfunc40();
    virtual void vfunc41();
    virtual void vfunc42();
    virtual void vfunc43();
    virtual void vfunc44();
    virtual void vfunc45();
    virtual void vfunc46();
    virtual void vfunc47();
    virtual void vfunc48();
    virtual void vfunc49();
    virtual void vfunc4A();
    virtual void vfunc4B();
    virtual void vfunc4C();
    virtual void vfunc4D();
    virtual void vfunc4E();
    virtual void CreateShaders(B92C40ShaderFile* pkVertex, B92C40ShaderFile* pkPixel, const char* pcName,
                               const char* pcVSVersion, const char* pcPSVersion);
    virtual void vfunc50();
    virtual void vfunc51();
    virtual void vfunc52();
    virtual void SetupShaders();

    void CreateWadingHeightmapShaders();
};

// Builds vertex and pixel shader files for water displacement with the HEIGHTMAP_WADING macro, then creates and sets up the shaders.
// @fnv 0x00b92c40
void B92C40WaterEffect::CreateWadingHeightmapShaders()
{
    B92C40ShaderFile kVertexDelta;
    kVertexDelta.m_pcFile = "water\\2_ab\\v\\displace.v.hlsl";
    kVertexDelta.m_akMacros[0].m_pcName = "HEIGHTMAP_WADING";
    kVertexDelta.m_akMacros[0].m_pcDefinition = 0;
    kVertexDelta.m_akMacros[1].m_pcName = 0;
    fnv_zlib_memset(&kVertexDelta.m_akMacros[1].m_pcDefinition, 0, sizeof(kVertexDelta) - 0x10);
    B92C40ShaderFile kPixel;
    kPixel.m_pcFile = "water\\2_ab\\p\\displace.p.hlsl";
    kPixel.m_akMacros[0].m_pcName = "HEIGHTMAP_WADING";
    kPixel.m_akMacros[0].m_pcDefinition = 0;
    kPixel.m_akMacros[1].m_pcName = 0;
    fnv_zlib_memset(&kPixel.m_akMacros[1].m_pcDefinition, 0, sizeof(kPixel) - 0x10);
    const char* pcPSVersion = B92C40GPUProgramCache::GetPixelShaderProfile(true);
    CreateShaders(&kVertexDelta, &kPixel, "WATERDISPLACEMENTWADINGHEIGHTMAP", "vs_1_1", pcPSVersion);
    SetupShaders();
}

extern char DAT_01011584;
extern "C" void __cdecl FUN_00ec61c0(void* p, unsigned int v, unsigned int n);
extern "C" int FUN_00b4f380(int a);

struct FUN_00b92e00_frame
{
    const char* unk00;
    const char* unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10[15];
    const char* unk4C;
    unsigned int unk50;
    unsigned int unk54[17];
};

class FUN_00b92e00_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F(void* a, void* b, const char* c, const char* d, unsigned int e);
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    void FUN_00b92e00();
};

// @fnv 0x00b92e00
void FUN_00b92e00_cls::FUN_00b92e00()
{
    FUN_00b92e00_frame f;
    f.unk4C = "water\\2_ab\\v\\displace.v.hlsl";
    f.unk50 = 0;
    FUN_00ec61c0((char*)&f + 0x54, 0, 0x44);
    f.unk00 = "water\\2_ab\\p\\displace.p.hlsl";
    f.unk04 = "HEIGHTMAP_RAIN";
    f.unk08 = 0;
    f.unk0C = 0;
    FUN_00ec61c0((char*)&f + 0x10, 0, 0x3C);
    unsigned int r = FUN_00b4f380(1);
    this->v4F(&f.unk4C, &f, "WATERDISPLACEMENTRAINHEIGHTMAP", "vs_1_1", r);
    this->v53();
}

extern "C" void* fnv_zlib_memset(void* dst, int c, int n);

struct B92F50Macro
{
    const char* m_pcName;
    const char* m_pcDefinition;
};

struct B92F50ShaderFile
{
    const char* m_pcFile;
    B92F50Macro m_akMacros[9];
};

class B92F50GPUProgramCache
{
  public:
    static const char* GetPixelShaderProfile(bool bHighest);
};

class B92F50WaterEffect
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
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void vfunc2D();
    virtual void vfunc2E();
    virtual void vfunc2F();
    virtual void vfunc30();
    virtual void vfunc31();
    virtual void vfunc32();
    virtual void vfunc33();
    virtual void vfunc34();
    virtual void vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc3A();
    virtual void vfunc3B();
    virtual void vfunc3C();
    virtual void vfunc3D();
    virtual void vfunc3E();
    virtual void vfunc3F();
    virtual void vfunc40();
    virtual void vfunc41();
    virtual void vfunc42();
    virtual void vfunc43();
    virtual void vfunc44();
    virtual void vfunc45();
    virtual void vfunc46();
    virtual void vfunc47();
    virtual void vfunc48();
    virtual void vfunc49();
    virtual void vfunc4A();
    virtual void vfunc4B();
    virtual void vfunc4C();
    virtual void vfunc4D();
    virtual void vfunc4E();
    virtual void CreateShaders(B92F50ShaderFile* pkVertex, B92F50ShaderFile* pkPixel, const char* pcName,
                               const char* pcVSVersion, const char* pcPSVersion);
    virtual void vfunc50();
    virtual void vfunc51();
    virtual void vfunc52();
    virtual void SetupShaders();

    void CreateDisplacementShaders();
};

// Builds vertex and pixel shader file descriptors for water displacement with BLEND_HEIGHTMAPS, then calls CreateShaders and SetupShaders.
// @fnv 0x00b92f50
void B92F50WaterEffect::CreateDisplacementShaders()
{
    B92F50ShaderFile kVertexDelta;
    kVertexDelta.m_pcFile = "water\\2_ab\\v\\displace.v.hlsl";
    kVertexDelta.m_akMacros[0].m_pcName = 0;
    fnv_zlib_memset(&kVertexDelta.m_akMacros[0].m_pcDefinition, 0, sizeof(kVertexDelta) - 8);
    B92F50ShaderFile kPixel;
    kPixel.m_pcFile = "water\\2_ab\\p\\displace.p.hlsl";
    kPixel.m_akMacros[0].m_pcName = "BLEND_HEIGHTMAPS";
    kPixel.m_akMacros[0].m_pcDefinition = 0;
    kPixel.m_akMacros[1].m_pcName = 0;
    fnv_zlib_memset(&kPixel.m_akMacros[1].m_pcDefinition, 0, sizeof(kPixel) - 0x10);
    const char* pcPSVersion = B92F50GPUProgramCache::GetPixelShaderProfile(true);
    CreateShaders(&kVertexDelta, &kPixel, "WATERDISPLACEMENTBLENDHEIGHTMAPS", "vs_1_1", pcPSVersion);
    SetupShaders();
}

extern "C" void* fnv_zlib_memset(void* dst, int c, int n);

struct B930A0Macro
{
    const char* m_pcName;
    const char* m_pcDefinition;
};

struct B930A0ShaderFile
{
    const char* m_pcFile;
    B930A0Macro m_akMacros[9];
};

class B930A0GPUProgramCache
{
  public:
    static const char* GetPixelShaderProfile(bool bHighest);
};

class B930A0WaterEffect
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
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void vfunc2D();
    virtual void vfunc2E();
    virtual void vfunc2F();
    virtual void vfunc30();
    virtual void vfunc31();
    virtual void vfunc32();
    virtual void vfunc33();
    virtual void vfunc34();
    virtual void vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc3A();
    virtual void vfunc3B();
    virtual void vfunc3C();
    virtual void vfunc3D();
    virtual void vfunc3E();
    virtual void vfunc3F();
    virtual void vfunc40();
    virtual void vfunc41();
    virtual void vfunc42();
    virtual void vfunc43();
    virtual void vfunc44();
    virtual void vfunc45();
    virtual void vfunc46();
    virtual void vfunc47();
    virtual void vfunc48();
    virtual void vfunc49();
    virtual void vfunc4A();
    virtual void vfunc4B();
    virtual void vfunc4C();
    virtual void vfunc4D();
    virtual void vfunc4E();
    virtual void CreateShaders(B930A0ShaderFile* pkVertex, B930A0ShaderFile* pkPixel, const char* pcName,
                               const char* pcVSVersion, const char* pcPSVersion);
    virtual void vfunc50();
    virtual void vfunc51();
    virtual void vfunc52();
    virtual void SetupShaders();

    void CreateSmoothHeightmapShaders();
};

// Builds vertex and pixel shader files for the smooth heightmap water effect and calls CreateShaders with the pixel shader profile, then SetupShaders.
// @fnv 0x00b930a0
void B930A0WaterEffect::CreateSmoothHeightmapShaders()
{
    B930A0ShaderFile kVertexDelta;
    kVertexDelta.m_pcFile = "water\\2_ab\\v\\displace.v.hlsl";
    kVertexDelta.m_akMacros[0].m_pcName = "HEIGHTMAP_SMOOTH";
    kVertexDelta.m_akMacros[0].m_pcDefinition = 0;
    kVertexDelta.m_akMacros[1].m_pcName = 0;
    fnv_zlib_memset(&kVertexDelta.m_akMacros[1].m_pcDefinition, 0, sizeof(kVertexDelta) - 0x10);
    B930A0ShaderFile kPixel;
    kPixel.m_pcFile = "water\\2_ab\\p\\displace.p.hlsl";
    kPixel.m_akMacros[0].m_pcName = "HEIGHTMAP_SMOOTH";
    kPixel.m_akMacros[0].m_pcDefinition = 0;
    kPixel.m_akMacros[1].m_pcName = 0;
    fnv_zlib_memset(&kPixel.m_akMacros[1].m_pcDefinition, 0, sizeof(kPixel) - 0x10);
    const char* pcPSVersion = B930A0GPUProgramCache::GetPixelShaderProfile(true);
    CreateShaders(&kVertexDelta, &kPixel, "WATERSMOOTHHEIGHTMAP", "vs_1_1", pcPSVersion);
    SetupShaders();
}

extern char DAT_01011584;
extern "C" void __cdecl FUN_00ec61c0(void* p, unsigned int v, unsigned int n);
extern "C" int FUN_00b4f380(int a);

struct FUN_00b931f0_frame
{
    const char* unk00;
    const char* unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10[15];
    const char* unk4C;
    unsigned int unk50;
    unsigned int unk54[17];
};

class FUN_00b931f0_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F(void* a, void* b, const char* c, const char* d, unsigned int e);
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    void FUN_00b931f0();
};

// @fnv 0x00b931f0
void FUN_00b931f0_cls::FUN_00b931f0()
{
    FUN_00b931f0_frame f;
    f.unk4C = "water\\2_ab\\v\\displace.v.hlsl";
    f.unk50 = 0;
    FUN_00ec61c0((char*)&f + 0x54, 0, 0x44);
    f.unk00 = "water\\2_ab\\p\\displace.p.hlsl";
    f.unk04 = "NORMALS";
    f.unk08 = 0;
    f.unk0C = 0;
    FUN_00ec61c0((char*)&f + 0x10, 0, 0x3C);
    unsigned int r = FUN_00b4f380(1);
    this->v4F(&f.unk4C, &f, "WATERDISPLACEMENTNORMALS", "vs_1_1", r);
    this->v53();
}

extern "C" void FUN_00ec61c0(void* a, unsigned int b, unsigned int c);
extern "C" int FUN_00b4f380(int a);
struct FUN_00b93340_cls
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
    virtual void v13c(void* a, void* b, const char* c, const char* d, int e);
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    void InitWaterSpectrumShader();
};
// Fills two shader descriptor blocks (base.v.hlsl and waterhmap.p.hlsl with WATER_SPECTRUM), then calls v13c with FFTWATERSPECTRUM/vs_1_1 and v14c.
// @fnv 0x00b93340
void FUN_00b93340_cls::InitWaterSpectrumShader()
{
    unsigned int f[0x26];
    f[0x13] = (unsigned int)"imagespace\\1x\\v\\base.v.hlsl";
    f[0x14] = 0;
    f[0x15] = 0;
    FUN_00ec61c0(&f[0x16], 0, 0x40);
    f[0] = (unsigned int)"water\\2_ab\\p\\waterhmap.p.hlsl";
    f[1] = (unsigned int)"WATER_SPECTRUM";
    f[2] = 0;
    f[3] = 0;
    f[4] = 0;
    FUN_00ec61c0(&f[5], 0, 0x38);
    int r = FUN_00b4f380(1);
    this->v13c((void*)&f[0x13], (void*)&f[0], "FFTWATERSPECTRUM", "vs_1_1", r);
    this->v14c();
}

struct StageReturn
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
    unsigned int m_uiRefCount;
    void ReturnToPool();
    void DecRef()
    {
        if (--m_uiRefCount == 0)
            ReturnToPool();
    }
};
void AssignStageFromPool(StageReturn*& out);

struct StageReturnRef
{
    StageReturn* m_p;
    StageReturnRef() : m_p(0)
    {}
    ~StageReturnRef()
    {
        if (m_p)
        {
            m_p->DecRef();
        }
    }
};

struct RefTarget_b93420
{
    virtual void v00();
    virtual void DeleteThis();
    long m_lRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_lRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_lRefCount))
            DeleteThis();
    }
};

struct StateBlock_b93420
{
    void SetState(int a, int b, int c);
};
StateBlock_b93420* CreateStateBlock_b93420();

struct Pass_b93420
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
    StateBlock_b93420* m_pkStates;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    RefTarget_b93420* m_pkPixelShader;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    RefTarget_b93420* m_pkVertexShader;
    void SetDestructibleData(int list, StageReturn* stage);
    void SetVertexShader(RefTarget_b93420* shader)
    {
        if (m_pkVertexShader != shader)
        {
            if (m_pkVertexShader)
                m_pkVertexShader->DecRefCount();
            m_pkVertexShader = shader;
            if (shader)
                shader->IncRefCount();
        }
    }
    void SetPixelShader(RefTarget_b93420* shader)
    {
        if (m_pkPixelShader != shader)
        {
            if (m_pkPixelShader)
                m_pkPixelShader->DecRefCount();
            m_pkPixelShader = shader;
            if (shader)
                shader->IncRefCount();
        }
    }
    StateBlock_b93420* GetStates()
    {
        if (!m_pkStates)
            m_pkStates = CreateStateBlock_b93420();
        return m_pkStates;
    }
};

void FUN_00e804d0(Pass_b93420** pp);
void ConfigureBeamStage(StageReturn* stage, unsigned int index, int a, int b, int c);

struct Shader_b93420
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
    virtual void InitPasses();
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
    Pass_b93420* m_pRenderPass;
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
    unsigned short m_usStageCount;
    unsigned short unk9e;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    RefTarget_b93420* m_pkVertex;
    RefTarget_b93420* m_pkPixel;
    bool FUN_00b93420();
};

// @fnv 0x00b93420
bool Shader_b93420::FUN_00b93420()
{
    StageReturnRef stage;
    FUN_00e804d0(&m_pRenderPass);
    for (unsigned int i = 0; i < m_usStageCount; i++)
    {
        AssignStageFromPool(stage.m_p);
        ConfigureBeamStage(stage.m_p, i, 1, 2, 1);
        m_pRenderPass->SetDestructibleData(m_pRenderPass->unk14, stage.m_p);
    }
    m_pRenderPass->GetStates()->SetState(7, 0, 1);
    m_pRenderPass->GetStates()->SetState(0xe, 0, 1);
    m_pRenderPass->GetStates()->SetState(0x1b, 0, 1);
    m_pRenderPass->GetStates()->SetState(0xf, 0, 1);
    m_pRenderPass->GetStates()->SetState(0xa8, 0xf, 1);
    InitPasses();
    m_pRenderPass->SetVertexShader(m_pkVertex);
    m_pRenderPass->SetPixelShader(m_pkPixel);
    return true;
}

namespace fnv_00b93670 {
extern "C" void __cdecl FUN_00ec61c0(void* object, int value, int capacity);
extern "C" int __cdecl FUN_00b4f380(int value);

struct S_00b93670_frame
{
    char* unk00;
    char* unk04;
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
    char* unk4c;
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
};

class S_00b93670_cls
{
  public:
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
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
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual void v64() = 0;
    virtual void v65() = 0;
    virtual void v66() = 0;
    virtual void v67() = 0;
    virtual void v68() = 0;
    virtual void v69() = 0;
    virtual void v70() = 0;
    virtual void v71() = 0;
    virtual void v72() = 0;
    virtual void v73() = 0;
    virtual void v74() = 0;
    virtual void v75() = 0;
    virtual void v76() = 0;
    virtual void v77() = 0;
    virtual void v78() = 0;
    virtual void v79(void* a, void* b, const char* c, const char* d, int e) = 0;
    virtual void v80() = 0;
    virtual void v81() = 0;
    virtual void v82() = 0;
    virtual void v83() = 0;

    void InitHorizontalButterflyShader();
};

// @fnv 0x00b93670
void S_00b93670_cls::InitHorizontalButterflyShader()
{
    S_00b93670_frame shaderFrame;

    shaderFrame.unk4c = "imagespace\\1x\\v\\base.v.hlsl";
    shaderFrame.unk50 = 0;
    shaderFrame.unk54 = 0;
    FUN_00ec61c0(&shaderFrame.unk58, 0, 0x40);

    shaderFrame.unk00 = "water\\2_ab\\p\\waterhmap.p.hlsl";
    shaderFrame.unk04 = "HORIZONTAL_BUTTERFLY";
    shaderFrame.unk08 = 0;
    shaderFrame.unk0c = 0;
    shaderFrame.unk10 = 0;
    FUN_00ec61c0(&shaderFrame.unk14, 0, 0x38);

    int renderer = FUN_00b4f380(1);

    this->v79(&shaderFrame.unk4c, &shaderFrame.unk00, "FFTHORIZONTALBUTTERFLY", "vs_1_1", renderer);
    this->v83();
}
}  // namespace fnv_00b93670

extern "C" void FUN_00ec61c0(void* a, unsigned int b, unsigned int c);
extern "C" int FUN_00b4f380(int a);
struct FUN_00b939c0_cls
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
    virtual void v13c(void* a, void* b, const char* c, const char* d, int e);
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    void InitVerticalButterflyShader();
};
// @fnv 0x00b939c0
void FUN_00b939c0_cls::InitVerticalButterflyShader()
{
    unsigned int f[0x26];
    f[0x13] = (unsigned int)"imagespace\\1x\\v\\base.v.hlsl";
    f[0x14] = 0;
    f[0x15] = 0;
    FUN_00ec61c0(&f[0x16], 0, 0x40);
    f[0] = (unsigned int)"water\\2_ab\\p\\waterhmap.p.hlsl";
    f[1] = (unsigned int)"VERTICAL_BUTTERFLY";
    f[2] = 0;
    f[3] = 0;
    f[4] = 0;
    FUN_00ec61c0(&f[5], 0, 0x38);
    int r = FUN_00b4f380(1);
    this->v13c((void*)&f[0x13], (void*)&f[0], "FFTVERTICALBUTTERFLY", "vs_1_1", r);
    this->v14c();
}

namespace fnv_00b93b10 {
void __cdecl FUN_00ec61c0(void* apDest, int aiValue, unsigned int auiSize);
int __cdecl FUN_00b4f380(int aiValue);

struct ShaderSourceA
{
    const char* m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c[0x10];
};

struct ShaderSourceB
{
    const char* m_00;
    const char* m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14[0xe];
};

class FUN_00b93b10_cls
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
    virtual void v79(ShaderSourceA* apSource, ShaderSourceB* apDefines, const char* apEntry, const char* apProfile,
                     int aiFlags);
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();

    void FUN_00b93b10();
};

// @fnv 0x00b93b10
void FUN_00b93b10_cls::FUN_00b93b10()
{
    ShaderSourceA source;
    ShaderSourceB sourceB;

    source.m_00 = "imagespace\\1x\\v\\base.v.hlsl";
    source.m_04 = 0;
    source.m_08 = 0;
    FUN_00ec61c0(source.m_0c, 0, 0x40);

    sourceB.m_00 = "water\\2_ab\\p\\waterhmap.p.hlsl";
    sourceB.m_04 = "HORIZONTAL_SCRAMBLE";
    sourceB.m_08 = 0;
    sourceB.m_0c = 0;
    sourceB.m_10 = 0;
    FUN_00ec61c0(sourceB.m_14, 0, 0x38);

    int flags = FUN_00b4f380(1);
    this->v79(&source, &sourceB, "FFTHORIZONTALSCRAMBLE", "vs_1_1", flags);
    this->v83();
}
}  // namespace fnv_00b93b10

extern "C" void FUN_00ec61c0(void* a, unsigned int b, unsigned int c);
extern "C" int FUN_00b4f380(int a);
struct FUN_00b93c60_cls
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
    virtual void v13c(void* a, void* b, const char* c, const char* d, int e);
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    void InitVerticalScrambleShader();
};
// @fnv 0x00b93c60
void FUN_00b93c60_cls::InitVerticalScrambleShader()
{
    unsigned int f[0x26];
    f[0x13] = (unsigned int)"imagespace\\1x\\v\\base.v.hlsl";
    f[0x14] = 0;
    f[0x15] = 0;
    FUN_00ec61c0(&f[0x16], 0, 0x40);
    f[0] = (unsigned int)"water\\2_ab\\p\\waterhmap.p.hlsl";
    f[1] = (unsigned int)"VERTICAL_SCRAMBLE";
    f[2] = 0;
    f[3] = 0;
    f[4] = 0;
    FUN_00ec61c0(&f[5], 0, 0x38);
    int r = FUN_00b4f380(1);
    this->v13c((void*)&f[0x13], (void*)&f[0], "FFTVERTICALSCRAMBLE", "vs_1_1", r);
    this->v14c();
}

namespace fnv_00b93db0 {
extern "C" void* __cdecl FUN_00ec61c0(void* destination, int value, unsigned int size);
extern "C" const char* __cdecl FUN_00b4f380(bool flag);

struct FUN_00b93db0_Block40
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1C;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2C;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3C;
};

struct FUN_00b93db0_Block38
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1C;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2C;
    unsigned int m_30;
    unsigned int m_34;
};

struct FUN_00b93db0_First
{
    const char* shader;
    int unk04;
    int unk08;
    FUN_00b93db0_Block40 data;
};

struct FUN_00b93db0_Second
{
    const char* shader;
    const char* name;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00b93db0_Block38 data;
};

struct FUN_00b93db0_Object
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
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
    virtual void vfF0();
    virtual void vfF4();
    virtual void vfF8();
    virtual void vfFC();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10C();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11C();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12C();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void __thiscall vf13C(const FUN_00b93db0_First* first, const FUN_00b93db0_Second* second,
                                  const char* fftNormals, const char* vertexShader, const char* gpuProfile);
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14C();

    void __thiscall FUN_00b93db0();
};

// @fnv 0x00b93db0
void __thiscall FUN_00b93db0_Object::FUN_00b93db0()
{
    FUN_00b93db0_First first;
    FUN_00b93db0_Second second;

    first.shader = "imagespace\\1x\\v\\base.v.hlsl";
    first.unk04 = 0;
    first.unk08 = 0;
    FUN_00ec61c0(&first.data, 0, sizeof(first.data));

    second.shader = "water\\2_ab\\p\\waterhmap.p.hlsl";
    second.name = "NORMALS";
    second.unk08 = 0;
    second.unk0C = 0;
    second.unk10 = 0;
    FUN_00ec61c0(&second.data, 0, sizeof(second.data));

    const char* gpuProfile = FUN_00b4f380(true);

    vf13C(&first, &second, "FFTNORMALS", "vs_1_1", gpuProfile);
    vf14C();
}
}  // namespace fnv_00b93db0

extern "C" void FUN_00ec61c0(void* a, unsigned int b, unsigned int c);
extern "C" int FUN_00b4f380(int a);
struct FUN_00b93f00_cls
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
    virtual void v13c(void* a, void* b, const char* c, const char* d, int e);
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    void CreateFilterShader();
};
// @fnv 0x00b93f00
void FUN_00b93f00_cls::CreateFilterShader()
{
    unsigned int f[0x26];
    f[0x13] = (unsigned int)"imagespace\\1x\\v\\base.v.hlsl";
    f[0x14] = 0;
    f[0x15] = 0;
    FUN_00ec61c0(&f[0x16], 0, 0x40);
    f[0] = (unsigned int)"water\\2_ab\\p\\waterhmap.p.hlsl";
    f[1] = (unsigned int)"FILTER";
    f[2] = 0;
    f[3] = 0;
    f[4] = 0;
    FUN_00ec61c0(&f[5], 0, 0x38);
    int r = FUN_00b4f380(1);
    this->v13c((void*)&f[0x13], (void*)&f[0], "FFTFILTER", "vs_1_1", r);
    this->v14c();
}

extern void* FUN_00ec61c0(void* p, int c, unsigned int n);
extern const char* FUN_00b4f380(bool b);
struct S_00b94050_A
{
    const char* path;
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
};
struct S_00b94050_B
{
    const char* path;
    const char* define;
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
};
struct S_00b94050_Obj
{
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
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void FUN_x13c(S_00b94050_A* a, S_00b94050_B* b, const char* n, const char* p, const char* prof);
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void FUN_x14c();
    void InitDisplayNormalsShaders();
};
// Builds two shader descriptors (base.v.hlsl and waterhmap.p.hlsl with DISPLAY_NORMALS), gets a profile name, then calls FUN_x13c and FUN_x14c.
// @fnv 0x00b94050
void S_00b94050_Obj::InitDisplayNormalsShaders()
{
    S_00b94050_A a;
    a.path = "imagespace\\1x\\v\\base.v.hlsl";
    a.unk04 = 0;
    a.unk08 = 0;
    FUN_00ec61c0(&a.unk0c, 0, 0x40);
    S_00b94050_B b;
    b.path = "water\\2_ab\\p\\waterhmap.p.hlsl";
    b.define = "DISPLAY_NORMALS";
    b.unk08 = 0;
    b.unk0c = 0;
    b.unk10 = 0;
    FUN_00ec61c0(&b.unk14, 0, 0x38);
    const char* prof = FUN_00b4f380(true);
    FUN_x13c(&a, &b, "FFTDISPLAYNORMALS", "vs_1_1", prof);
    FUN_x14c();
}

namespace fnv_00b942f0 {
extern "C" void __cdecl FUN_00ec61c0(void* p, unsigned int v, unsigned int n);
extern "C" unsigned int __cdecl FUN_00b4f380(int a);

struct FUN_00b942f0_frame
{
    const char* unk00;
    const char* unk04;
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
    const char* unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
};

class FUN_00b942f0_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F(void* a, void* b, const char* c, const char* d, unsigned int e);
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    void InitWaterHmapDisplayAmplitude();
};

// @fnv 0x00b942f0
void FUN_00b942f0_cls::InitWaterHmapDisplayAmplitude()
{
    FUN_00b942f0_frame f;
    f.unk4C = "imagespace\\1x\\v\\base.v.hlsl";
    f.unk50 = 0;
    f.unk54 = 0;
    FUN_00ec61c0((char*)&f + 0x58, 0, 0x40);
    f.unk00 = "water\\2_ab\\p\\waterhmap.p.hlsl";
    f.unk04 = "DISPLAY_AMPLITUDE";
    f.unk08 = 0;
    f.unk0C = 0;
    f.unk10 = 0;
    FUN_00ec61c0((char*)&f + 0x14, 0, 0x38);
    unsigned int r = FUN_00b4f380(1);
    this->v4F((char*)&f + 0x4c, (char*)&f, "FFTDISPLAYAMPLITUDE", "vs_1_1", r);
    this->v53();
}
}  // namespace fnv_00b942f0

extern "C" void FUN_00ec61c0(void* a, unsigned int b, unsigned int c);
extern "C" int FUN_00b4f380(int a);
struct FUN_00b94440_cls
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
    virtual void v13c(void* a, void* b, const char* c, const char* d, int e);
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    void InitWaterHeightShader();
};
// Fills two shader descriptor blocks, resolves a value via FUN_00b4f380(1), then calls v13c with the descriptors and v14c.
// @fnv 0x00b94440
void FUN_00b94440_cls::InitWaterHeightShader()
{
    unsigned int f[0x26];
    f[0x13] = (unsigned int)"imagespace\\1x\\v\\base.v.hlsl";
    f[0x14] = 0;
    f[0x15] = 0;
    FUN_00ec61c0(&f[0x16], 0, 0x40);
    f[0] = (unsigned int)"water\\2_ab\\p\\waterhmap.p.hlsl";
    f[1] = (unsigned int)"DISPLAY_WATER_HEIGHT";
    f[2] = 0;
    f[3] = 0;
    f[4] = 0;
    FUN_00ec61c0(&f[5], 0, 0x38);
    int r = FUN_00b4f380(1);
    this->v13c((void*)&f[0x13], (void*)&f[0], "FFTDISPLAYWATERHEIGHT", "vs_1_1", r);
    this->v14c();
}

struct B9697Obj
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual int __stdcall v4B(void* p);
};

struct B9697Args
{
    int a0;
    int a1;
    int a2;
    int a3;
};

extern int DAT_011ffa10;
extern unsigned char* DAT_011f4748;

// If DAT_011ffa10 is zero, packs the four arguments into a B9697Args and passes it to v4B of the object at DAT_011f4748+0x288, then adds a4 to DAT_011ffa10.
// @fnv 0x00b97d20
void __cdecl AccumulateAndDispatch(int a0, int a1, int a2, int a3, int aiDelta)
{
    if (DAT_011ffa10 == 0)
    {
        B9697Args args;
        args.a0 = a0;
        args.a1 = a1;
        args.a2 = a2;
        args.a3 = a3;
        B9697Obj* obj = *(B9697Obj**)(DAT_011f4748 + 0x288);
        obj->v4B(&args);
    }
    DAT_011ffa10 += aiDelta;
}

extern int DAT_011ffa30[];
extern int DAT_011ff9d8[];

// Looks up the index for a, and if its counter is zero calls virtual method 26 on the object at DAT_011f9508+0x8b8, then adds c to the counter.
// @fnv 0x00b97d90
void __cdecl FUN_00b97d90(unsigned int uiIndex, unsigned int b, unsigned int uiDelta)
{
    int idx = DAT_011ffa30[uiIndex];
    if (DAT_011ff9d8[idx] == 0)
    {
        void* obj = *(void**)((char*)DAT_011f9508 + 0x8b8);
        void** vt = *(void***)obj;
        ((void(__thiscall*)(void*, unsigned int, unsigned int, int, int))vt[26])(obj, uiIndex, b, 0, 0);
    }
    DAT_011ff9d8[idx] += uiDelta;
}

extern NiRenderer* DAT_011f9508;
extern int DAT_011ff9d8[];
extern unsigned int DAT_011ffa68;

struct FUN_00b97e30_obj
{
    virtual void vfn00();
    virtual void vfn01();
    virtual void vfn02();
    virtual void vfn03();
    virtual void vfn04();
    virtual void vfn05();
    virtual void vfn06();
    virtual void vfn07();
    virtual void vfn08();
    virtual void vfn09();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26(int a, int b, int c, int d);
};

// @fnv 0x00b97e30
void FUN_00b97e30(unsigned char a1, unsigned int uiAmount)
{
    unsigned int idx = DAT_011ffa68;
    if (DAT_011ff9d8[idx] == 0)
    {
        FUN_00b97e30_obj* obj = *reinterpret_cast<FUN_00b97e30_obj**>(reinterpret_cast<char*>(DAT_011f9508) + 0x8b8);
        obj->vfn26(14, a1, 0, 0);
    }
    DAT_011ff9d8[idx] += uiAmount;
}

struct Dispatcher
{
    void** vtable;
    __forceinline void Notify(int eventType, int argument, int unused1, int unused2)
    {
        typedef void(__thiscall * Notification)(Dispatcher*, int, int, int, int);
        Notification call = reinterpret_cast<Notification>(vtable[26]);
        call(this, eventType, argument, unused1, unused2);
    }
};

__forceinline Dispatcher* GetDispatcher(NiRenderer* renderer)
{
    return *reinterpret_cast<Dispatcher**>(reinterpret_cast<char*>(renderer) + 0x8b8);
}

extern NiRenderer* DAT_011f9508;
extern int DAT_011ff9d8[];
extern int DAT_011ffa94;
extern int DAT_011ffa90;
extern int DAT_011ad888[];

// For two channels, sends a notification when the channel counter is zero, then adds increment to each channel counter.
// @fnv 0x00b97f20
void __cdecl FUN_00b97f20(int index, int secondValue, int increment)
{
    int firstChannel = DAT_011ffa94;
    if (DAT_011ff9d8[firstChannel] == 0)
    {
        GetDispatcher(DAT_011f9508)->Notify(0x19, DAT_011ad888[index], 0, 0);
    }
    DAT_011ff9d8[firstChannel] += increment;
    int secondChannel = DAT_011ffa90;
    if (DAT_011ff9d8[secondChannel] == 0)
    {
        GetDispatcher(DAT_011f9508)->Notify(0x18, secondValue, 0, 0);
    }
    DAT_011ff9d8[secondChannel] += increment;
}

namespace fnv_00b988e0 {
struct EventHandler
{
    void** vtable;
};
struct UIService
{
    void** vtable;
};

extern "C" EventHandler* DAT_011ffe2c;
extern "C" unsigned int DAT_011ffe30;
extern "C" unsigned char DAT_011ad8ec;
extern "C" void* DAT_011f4748;

typedef void(__thiscall* NotifyEvent)(EventHandler*, unsigned int);
typedef void(__thiscall* FinishEvent)(EventHandler*);
typedef void(__stdcall* DispatchUI)(UIService*, unsigned int, unsigned int, unsigned int);

// @fnv 0x00b988e0
void __cdecl FUN_00b988e0()
{
    EventHandler* eventHandler = DAT_011ffe2c;
    if (eventHandler != 0)
    {
        NotifyEvent pfnNotify = (NotifyEvent)eventHandler->vtable[0x104 / 4];
        pfnNotify(eventHandler, DAT_011ffe30);

        if (DAT_011ad8ec == 0)
        {
            eventHandler = DAT_011ffe2c;
            FinishEvent pfnFinish = (FinishEvent)eventHandler->vtable[0x114 / 4];
            pfnFinish(eventHandler);
        }

        const unsigned int eventCode = DAT_011ffe30;
        if (eventCode == 0xfe || eventCode == 0x10b)
        {
            UIService* pUIService = *(UIService**)((char*)DAT_011f4748 + 0x288);
            DispatchUI pfnDispatchUI = (DispatchUI)pUIService->vtable[0x114 / 4];
            pfnDispatchUI(pUIService, 7, 8, 0);
        }
        else if (eventCode == 0x230)
        {
            UIService* pUIService = *(UIService**)((char*)DAT_011f4748 + 0x288);
            DispatchUI pfnDispatchUI = (DispatchUI)pUIService->vtable[0x114 / 4];
            pfnDispatchUI(pUIService, 2, 8, 0);
        }
    }
    DAT_011ffe2c = 0;
    DAT_011ffe30 = 0;
}
}  // namespace fnv_00b988e0

struct FUN_00b9abc0_class
{
    void __thiscall DispatchPass(unsigned int arg1, unsigned int arg2);
};

struct FUN_00b9b3b0_class
{
    void* m_000;
    void* m_004;
    void* m_008;
    void* m_00c;
    void* m_010;
    void* m_014;
    void* m_018;
    void* m_01c;
    void* m_020;
    void* m_024;
    void* m_028;
    void* m_02c;
    void* m_030;
    void* m_034;
    void* m_038;
    FUN_00b9abc0_class* m_003c;

    void __thiscall DispatchToSlot(unsigned int arg1, unsigned int arg2, unsigned int arg3);
};

// @fnv 0x00b9b3b0
void __thiscall FUN_00b9b3b0_class::DispatchToSlot(unsigned int arg1, unsigned int uiIndex, unsigned int arg3)
{
    reinterpret_cast<FUN_00b9abc0_class**>(&m_003c)[uiIndex]->DispatchPass(arg1, arg3);
}

struct B9B3D0Pass;

class B9B3D0Stage
{
  public:
    void Setup(B9B3D0Pass* pkPass, bool bForce);
};

class B9B3D0Shader
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
    int m_iMode;
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
    B9B3D0Stage* m_apkLowStages[8];
    B9B3D0Stage* m_apkHighStages[8];

    void SetupStage(B9B3D0Pass* pkPass, int iStage);
};

// Calls Setup on the high or low stage array entry at iStage, depending on whether m_iMode is positive.
// @fnv 0x00b9b3d0
void B9B3D0Shader::SetupStage(B9B3D0Pass* pkPass, int iStage)
{
    if (m_iMode > 0)
        m_apkHighStages[iStage]->Setup(pkPass, false);
    else
        m_apkLowStages[iStage]->Setup(pkPass, false);
}

extern unsigned char DAT_011ad900[256];
extern "C" void _ReadWriteBarrier(void);

class FUN_00b9b400_cls
{
  public:
    unsigned char unk00[0x98];
    unsigned char m_table98[256];
    unsigned char m_table198[256];

    void FUN_00b9b400(unsigned int key);
};

// Fills m_table198 and m_table98 with 256 bytes from DAT_011ad900 starting at an offset derived from key.
// @fnv 0x00b9b400
void FUN_00b9b400_cls::FUN_00b9b400(unsigned int key)
{
    unsigned int shift = ((key * 0x5391313du) + 0x22fc2945u) >> 0x18;
    for (unsigned int i = 0; i < 0x100; i++)
    {
        unsigned char v = DAT_011ad900[(i + shift) & 0xff];
        m_table198[i] = v;
        _ReadWriteBarrier();
        m_table98[i] = v;
    }
}

// ImageSpace effect destructor: delete the two owned shaders, then the texture members and base go.

class B9B450Shader
{
  public:
    virtual ~B9B450Shader();
};

class B9B450ShaderArray
{
  public:
    void* m_pVtbl;
    B9B450Shader** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    B9B450Shader*& GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }
    void SetAt(unsigned int uiIndex, B9B450Shader* const& rpkShader);
};

class B9B450Texture
{
  public:
    ~B9B450Texture();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class B9B450EffectBase
{
  public:
    virtual ~B9B450EffectBase();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    B9B450ShaderArray m_kShaders;
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
};

class FUN_00b9b450 : public B9B450EffectBase
{
  public:
    virtual ~FUN_00b9b450();

    B9B450Texture m_kTexture0;
    B9B450Texture m_kTexture1;
    B9B450Texture m_kTexture2;
    B9B450Texture m_kTexture3;
};

// Destructor deletes the two shaders stored in m_kShaders and clears their slots.
// @fnv 0x00b9b450
FUN_00b9b450::~FUN_00b9b450()
{
    if (m_kShaders.GetAt(0))
    {
        delete m_kShaders.GetAt(0);
        m_kShaders.SetAt(0, 0);
    }
    if (m_kShaders.GetAt(1))
    {
        delete m_kShaders.GetAt(1);
        m_kShaders.SetAt(1, 0);
    }
}

struct B9B830Setting
{
    unsigned char m_ucR;
    unsigned char m_ucG;
    unsigned char m_ucB;
    int m_iA;
    int m_iB;
    int m_iC;

    B9B830Setting() : m_ucR(0), m_ucG(0), m_ucB(0), m_iA(0), m_iB(0), m_iC(0)
    {}
};

struct B9B830Vector
{
    int unk00;
    float x;
    float y;
    float z;
};

class B9B830ImageSpaceEffect
{
  public:
    B9B830ImageSpaceEffect();
    virtual ~B9B830ImageSpaceEffect();
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
};

class FUN_00b9b830;
extern FUN_00b9b830* g_pkB9B830Instance;
extern unsigned char g_aucB9B830Table[256];
extern B9B830Vector g_akB9B830Vectors[5];

class FUN_00b9b830 : public B9B830ImageSpaceEffect
{
  public:
    B9B830Setting m_kSettingA;
    B9B830Setting m_kSettingB;
    B9B830Setting m_kSettingC;
    B9B830Setting m_kSettingD;
    unsigned char m_aucTableA[256];
    unsigned char m_aucTableB[256];
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    bool m_bModifierActive;

    FUN_00b9b830();
    virtual ~FUN_00b9b830();
};

// Registers this instance globally, clears the flag, copies the 256-byte table into both tables, and zeroes the five vectors.
// @fnv 0x00b9b830
FUN_00b9b830::FUN_00b9b830()
{
    g_pkB9B830Instance = this;
    m_bModifierActive = false;
    for (unsigned int i = 0; i < 256; i++)
        m_aucTableA[i] = m_aucTableB[i] = g_aucB9B830Table[i];
    for (int j = 0; j < 5; j++)
    {
        g_akB9B830Vectors[j].x = 0.0f;
        g_akB9B830Vectors[j].y = 0.0f;
        g_akB9B830Vectors[j].z = 0.0f;
    }
}

struct MemMgr
{
    void* Allocate(unsigned int size);
    void Deallocate(void* p);
};
extern MemMgr g_memMgr;

struct ISEffectParam
{
    int unk00;
};

struct ISParam : ISEffectParam
{
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
    char unk54;
    char bActive;
    char unk56;
    char unk57;
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

    ISParam();
    void Init(int a, int b);
    static void* operator new(unsigned int size)
    {
        return g_memMgr.Allocate(size);
    }
    static void operator delete(void* p)
    {
        g_memMgr.Deallocate(p);
    }
};

struct ParamArray
{
    void SetAt(unsigned int index, ISEffectParam* const& value);
};

struct TexArray
{
    void SetSize(unsigned int size);
};

struct TexSet
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
    int tex0;
    int tex1;
};

struct TexOwner
{
    int unk00;
    int unk04;
    TexSet* texSet;
};

extern float DAT_011f9410;

struct ISEffectX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ParamArray params;
    int unk1c;
    int unk20;
    int unk24;
    TexArray textures;
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
    bool bInitialized;
    bool IsFormInitialized() const
    {
        return bInitialized;
    }
    void SetupBase(int n);
    void CreateTargets(int size);
    void SetEffectAt(int index, int tex, ISParam* param, int flags);
    void InitFromTexOwner(TexOwner* owner, int unused);
};

// @fnv 0x00b9b950
void ISEffectX::InitFromTexOwner(TexOwner* owner, int unused)
{
    SetupBase(2);
    textures.SetSize(4);
    if (!IsFormInitialized())
    {
        CreateTargets((unsigned int)DAT_011f9410);
        bInitialized = true;
    }
    ISParam* param = new ISParam;
    param->Init(3, 6);
    param->bActive = 0;
    params.SetAt(0, param);
    int t0 = owner->texSet->tex0;
    SetEffectAt(0, t0, param, 0);
    ISParam* param2 = new ISParam;
    param2->Init(3, 6);
    param2->bActive = 0;
    params.SetAt(1, param2);
    int t1 = owner->texSet->tex1;
    SetEffectAt(1, t1, param2, 0);
}

extern "C" double gModifierZero;
extern float g_fB9BB10Duration;

static inline float B9BB10Max(float f)
{
    return f < gModifierZero ? 0.0f : f;
}
static inline float B9BB10Min(float f)
{
    return 1.0f < f ? 1.0f : f;
}

class B9BB10Effect
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
    float m_fValue;
    float m_fTimer;

    void FUN_00b9bb10(float fValue, bool bReset);
};

// Sets m_fValue when it differs from fValue, resetting m_fTimer to 1.0 or rescaling it by the clamped ratio against g_fB9BB10Duration.
// @fnv 0x00b9bb10
void B9BB10Effect::FUN_00b9bb10(float fValue, bool bReset)
{
    if (m_fValue != fValue)
    {
        if (bReset)
        {
            m_fTimer = 1.0f;
        }
        else
        {
            float fTimerRatio = m_fTimer / g_fB9BB10Duration;
            m_fTimer = g_fB9BB10Duration * (1.0f - B9BB10Min(B9BB10Max(fTimerRatio)));
        }
        m_fValue = fValue;
    }
}

class NiCullingProcess;

struct ShaderPropStub
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
    virtual void Reset();
};

struct GeomStub
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
    ShaderPropStub* pProp30;
    ShaderPropStub* pProp34;
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
    int iType;
};

class NiAVObject
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
    GeomStub* pGeom;
    void Cull(NiCullingProcess& kCuller);
};

struct ListNode
{
    ListNode* next;
    ListNode* prev;
    NiAVObject* data;
};

struct FlagsStub
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
    unsigned char flags30;
};

struct RendererStub
{
    bool IsBusy();
};

struct ManagerStub
{
    int unk00;
    int unk04;
    RendererStub* pRenderer;
};

extern unsigned int(__cdecl* DAT_011f91ec)(NiAVObject*);
extern GeomStub** DAT_011f91e0;
extern unsigned int DAT_011f91e4;
extern unsigned char g_cullFlags;
extern ManagerStub* g_manager;

void __cdecl SetPassA(unsigned int, int);
void __cdecl SetPassB(unsigned int, int);

struct CullerOwner
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
    ListNode* pList;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    FlagsStub* pFlags;
    bool CullSceneObjects(NiCullingProcess& kCuller);
};

static inline NiAVObject*& GetNext(ListNode*& pos)
{
    NiAVObject*& p = pos->data;
    pos = pos->next;
    return p;
}

// @fnv 0x00b9d020
bool CullerOwner::CullSceneObjects(NiCullingProcess& kCuller)
{
    if (pFlags->flags30 & 1)
        return true;
    ListNode* pos = pList;
    while (pos)
    {
        NiAVObject* obj = GetNext(pos);
        if (!obj || !obj->pGeom)
            continue;
        GeomStub* g = obj->pGeom;
        if (DAT_011f91ec)
            DAT_011f91ec(obj);
        if (!(g_cullFlags & 1) || !g)
            continue;
        bool bRendererBusy = g_manager->pRenderer->IsBusy();
        if (g->iType >= 1 && g->iType <= 5)
        {
            if (!bRendererBusy)
            {
                if (obj->unkbc)
                {
                    DAT_011f91e0 = 0;
                    DAT_011f91e4 = 0x5c;
                    SetPassA(0x5c, 0);
                }
                else
                {
                    DAT_011f91e0 = 0;
                    DAT_011f91e4 = 0x58;
                    SetPassA(0x58, 0);
                }
                g->pProp34->Reset();
                g->pProp30->Reset();
            }
        }
        else if (g->iType == 0x11)
        {
            if (!bRendererBusy)
            {
                if (obj->unkbc)
                {
                    DAT_011f91e0 = 0;
                    DAT_011f91e4 = 0x1ca;
                    SetPassB(0x1ca, 0);
                }
                else
                {
                    DAT_011f91e0 = 0;
                    DAT_011f91e4 = 0x1c8;
                    SetPassB(0x1c8, 0);
                }
                g->pProp34->Reset();
                g->pProp30->Reset();
            }
        }
        else
        {
            continue;
        }
        obj->Cull(kCuller);
    }
    return true;
}

namespace fnv_00b9de90 {
struct NiUpdateData
{
    float time;
    bool a, b, c, d, e;
    NiUpdateData()
    {
        time = 0;
        a = false;
        b = false;
        c = false;
        d = false;
        e = false;
    }
};
struct NiAVObject
{
    void Update(const NiUpdateData&);
};
struct FUN_00bd8290 : NiAVObject
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
    FUN_00bd8290(int);
    void FUN_00bd7200(unsigned int);
    void FUN_00bd74a0();
    ~FUN_00bd8290()
    {
        FUN_00bd74a0();
    }
};
struct Input
{
    int unk00, unk04, unk08, unk0c;
};
struct TagGuard
{
    int old;
    TagGuard() : old(g_tls_2b4)
    {
        g_tls_2b4 = 32;
    }
    ~TagGuard()
    {
        g_tls_2b4 = old;
    }
};
struct Target
{
    bool FUN_00b9c020(int, FUN_00bd8290*);
    bool FUN_00b9de90(int, int, int, int, Input*, unsigned short);
};
// @fnv 0x00b9de90
bool Target::FUN_00b9de90(int a, int b, int c, int aiUnused, Input* input, unsigned short flags)
{
    int value = input->unk0c;
    TagGuard tagGuard;
    FUN_00bd8290 node(0);
    node.unk058 = a;
    node.unk05c = b;
    node.unk060 = c;
    node.FUN_00bd7200(flags);
    NiUpdateData update;
    node.Update(update);
    return FUN_00b9c020(value, &node);
}
}  // namespace fnv_00b9de90

extern __declspec(thread) int g_iAllocTagB8C;

struct AllocTagScopeB8C
{
    int m_iSaved;

    AllocTagScopeB8C(int aiAllocationTag)
    {
        m_iSaved = g_iAllocTagB8C;
        g_iAllocTagB8C = aiAllocationTag;
    }
    ~AllocTagScopeB8C()
    {
        g_iAllocTagB8C = m_iSaved;
    }
};

class RendererTargetB8C;
class SourceB8C;

template <class T> class NiPointerB8C
{
  public:
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }

    T* m_pObject;
};

class ImageSpaceTextureB8C
{
  public:
    ImageSpaceTextureB8C()
        : m_bIsRenderedTexture(false), m_bOwned(false), m_bFlag(false), m_pkTexture(0), m_pkTarget(0), m_iFilter(0)
    {}
    ~ImageSpaceTextureB8C();

    void SetTexture(SourceB8C* pkSource);

    bool m_bIsRenderedTexture;
    bool m_bOwned;
    bool m_bFlag;
    void* m_pkTexture;
    void* m_pkTarget;
    int m_iFilter;
};

class ImageSpaceEffectB8C
{
  public:
    virtual void vfn00();
    virtual void Render(RendererTargetB8C* pkTarget, void* pvArg1, void* pvArg2, void* pvArg3);

    void SetupTextures(unsigned int uiIndex, ImageSpaceTextureB8C* pkTexture, void* pvCamera);
};

class ImageSpaceManagerB8C
{
  public:
    void FUN_00b8c730(unsigned int uiEffect, void* pvArg1, SourceB8C* pkSource, void* pvArg2, void* pvArg3);

    void* m_ppVirtualMethodTable;
    int unk04;
    ImageSpaceEffectB8C** m_ppkEffects;
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
    NiPointerB8C<RendererTargetB8C> m_spMainTarget;
    int unk1F4;
    NiPointerB8C<RendererTargetB8C> m_spAltTarget;
    bool m_bUseAltTarget;
};

// Sets up a texture from pkSource on the effect at index uiEffect, renders it to the main or alt target, then clears the texture.
// @fnv 0x00b8c730
void ImageSpaceManagerB8C::FUN_00b8c730(unsigned int uiEffectIndex, void* pvArg1, SourceB8C* pkSource, void* pvArg2,
                                        void* pvArg3)
{
    AllocTagScopeB8C kScope(0x27);
    ImageSpaceEffectB8C* pkEffect = m_ppkEffects[uiEffectIndex];
    ImageSpaceTextureB8C kTexture;
    kTexture.SetTexture(pkSource);
    if (pkEffect)
    {
        pkEffect->SetupTextures(0, &kTexture, 0);
        pkEffect->Render(m_bUseAltTarget ? m_spAltTarget : m_spMainTarget, pvArg1, pvArg2, pvArg3);
        pkEffect->SetupTextures(0, 0, 0);
    }
}

class BSRenderedTexture;
struct NiAccumulator;
struct NiCamera;
extern __declspec(thread) int g_tlsMemContext;
struct ScopedMemoryContext
{
    int iOldContext;
    ScopedMemoryContext(int aiContext)
    {
        iOldContext = g_tlsMemContext;
        g_tlsMemContext = aiContext;
    }
    ~ScopedMemoryContext()
    {
        g_tlsMemContext = iOldContext;
    }
};
struct ImageSpaceTexture
{
    bool m_bTextureFlag2;
    bool bPointFilter;
    bool bClamp;
    void* pTexture;
    void* pRenderedTexture;
    int m_eTextureFilterMode;
    ImageSpaceTexture()
        : m_bTextureFlag2(false), bPointFilter(false), bClamp(false), pTexture(0), pRenderedTexture(0),
          m_eTextureFilterMode(0)
    {}
    ~ImageSpaceTexture();
    void FUN_00ba37a0(BSRenderedTexture* apTexture);
};
struct HolderForAccum
{
    virtual void Unk_00();
    virtual void Render(NiObject* apGeometry, int aiArg1, int aiArg2, int aiArg3);
    void SetAccumulatorAt(unsigned int auiIndex, NiAccumulator* apTexture, const NiCamera* apCamera);
};
struct FUN_00b8c830_class
{
    char pad[0x1f0];
    NiPointer<NiObject> m_kGeometry;
    int iPad1f4;
    NiPointer<NiObject> spAltGeometry;
    bool bUseAlt;
    void RenderWithTextures(HolderForAccum* apShader, int aiArg1, BSRenderedTexture* apSource0,
                            BSRenderedTexture* apSource1, int aiArg2, int aiArg3);
};
// Wraps two BSRenderedTextures into ImageSpaceTextures, binds them to the shader slots 0 and 1, renders the geometry, then unbinds the slots.
// @fnv 0x00b8c830
void FUN_00b8c830_class::RenderWithTextures(HolderForAccum* apShader, int aiArg1, BSRenderedTexture* apSource0,
                                            BSRenderedTexture* apSource1, int aiArg2, int aiArg3)
{
    ScopedMemoryContext kContext(0x27);
    ImageSpaceTexture kTexture0;
    ImageSpaceTexture kTexture1;
    kTexture0.FUN_00ba37a0(apSource0);
    kTexture1.FUN_00ba37a0(apSource1);
    if (apShader)
    {
        apShader->SetAccumulatorAt(0, (NiAccumulator*)&kTexture1, 0);
        apShader->SetAccumulatorAt(1, (NiAccumulator*)&kTexture0, 0);
        apShader->Render(bUseAlt ? spAltGeometry : m_kGeometry, aiArg1, aiArg2, aiArg3);
        apShader->SetAccumulatorAt(0, 0, 0);
        apShader->SetAccumulatorAt(1, 0, 0);
    }
}

class BB8D440Texture;

class BB8D440ImageSpaceTexture
{
  public:
    BB8D440Texture* GetTexture() const;
};

template <class T> class BB8D440Pointer
{
  public:
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    bool operator!=(const T* pObject) const
    {
        return m_pObject != pObject;
    }

    T* m_pObject;
};

struct BB8D440Data
{
    int unk00;
    int unk04;
    BB8D440Pointer<BB8D440ImageSpaceTexture> m_spTexture;
};

class BB8D440Effect
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
    BB8D440Data* m_pUserData;

    int HasTexture();
};

// @fnv 0x00b8d440
int BB8D440Effect::HasTexture()
{
    if (m_pUserData->m_spTexture != 0 && m_pUserData->m_spTexture->GetTexture())
        return 1;
    return 0;
}

struct BufferDescriptor
{
    char* label;
    int flag;
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
};
struct Renderer
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
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
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual void v64() = 0;
    virtual void v65() = 0;
    virtual void v66() = 0;
    virtual void v67() = 0;
    virtual void v68() = 0;
    virtual void v69() = 0;
    virtual void v70() = 0;
    virtual void v71() = 0;
    virtual void v72() = 0;
    virtual void v73() = 0;
    virtual void v74() = 0;
    virtual void v75() = 0;
    virtual void v76() = 0;
    virtual void v77() = 0;
    virtual void v78() = 0;
    virtual void v79(void*, void*, const void*, const void*, int) = 0;
    virtual void v80() = 0;
    virtual void v81() = 0;
    virtual void v82() = 0;
    virtual void v83() = 0;
    void InitBuffers();
};
extern "C" char str_010b0158[], str_010b0820[], str_010b22e0[], str_010a93ec[];
void* __cdecl FUN_00ec61c0(void*, int, unsigned int);
int __cdecl FUN_00b4f380(int);
// @fnv 0x00b8f710
void Renderer::InitBuffers()
{
    BufferDescriptor primary;
    BufferDescriptor secondaryDesc;
    primary.label = str_010b0158;
    primary.flag = 0;
    FUN_00ec61c0(&primary.field08, 0, 68);
    secondaryDesc.label = str_010b0820;
    secondaryDesc.flag = 0;
    FUN_00ec61c0(&secondaryDesc.field08, 0, 68);
    int resource = FUN_00b4f380(1);
    this->v79(&primary, &secondaryDesc, str_010b22e0, str_010a93ec, resource);
    this->v83();
}

void* __cdecl FUN_00ec61c0(void*, int, unsigned int);

extern "C" char str_010a93cc[];
extern "C" char str_010a93ec[];
extern "C" char str_010b0158[];
extern "C" char str_010b09d4[];
extern "C" char str_010b3544[];
extern "C" char str_010b3550[];
extern char DAT_01011584;

struct S_00b8ff10_Local1
{
    const char* unk00;
    const char* unk04;
    void* unk08;
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
};

struct S_00b8ff10_Local2
{
    const char* unk00;
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
};

struct S_00b8ff10_Base
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;

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
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;

    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;

    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;

    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;

    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual void v64() = 0;
    virtual void v65() = 0;
    virtual void v66() = 0;
    virtual void v67() = 0;
    virtual void v68() = 0;
    virtual void v69() = 0;

    virtual void v70() = 0;
    virtual void v71() = 0;
    virtual void v72() = 0;
    virtual void v73() = 0;
    virtual void v74() = 0;
    virtual void v75() = 0;
    virtual void v76() = 0;
    virtual void v77() = 0;
    virtual void v78() = 0;
};

struct FUN_00b8ff10_class : public S_00b8ff10_Base
{
    virtual void v79(void*, void*, const char*, const char*, const char*);
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();

    void __thiscall FUN_00b8ff10();
};

// @fnv 0x00b8ff10
void FUN_00b8ff10_class::FUN_00b8ff10()
{
    S_00b8ff10_Local1 local1;
    S_00b8ff10_Local2 local2;

    local1.unk00 = str_010b0158;
    local1.unk04 = str_010b09d4;
    local1.unk08 = (void*)&DAT_01011584;
    local1.unk0c = 0;

    FUN_00ec61c0(&local1.unk10, 0, 0x3c);

    local2.unk00 = str_010b3550;
    local2.unk04 = 0;

    FUN_00ec61c0(&local2.unk08, 0, 0x44);

    v79(&local1, &local2, str_010b3544, str_010a93ec, str_010a93cc);
    v83();
}

extern Pass_b93420* g_pkCurrentPass_b91f90;

struct Shader_b91f90 : Shader_b93420
{
    bool InitShaderPass();
};

// @fnv 0x00b91f90
bool Shader_b91f90::InitShaderPass()
{
    StageReturnRef stage;
    FUN_00e804d0(&m_pRenderPass);
    for (unsigned int i = 0; i < m_usStageCount; i++)
    {
        AssignStageFromPool(stage.m_p);
        ConfigureBeamStage(stage.m_p, i, 1, 2, 1);
        m_pRenderPass->SetDestructibleData(m_pRenderPass->unk14, stage.m_p);
    }
    m_pRenderPass->GetStates()->SetState(7, 0, 1);
    m_pRenderPass->GetStates()->SetState(0xe, 0, 1);
    m_pRenderPass->GetStates()->SetState(0x1b, 0, 1);
    m_pRenderPass->GetStates()->SetState(0xf, 0, 1);
    m_pRenderPass->GetStates()->SetState(0xa8, 0xf, 1);
    InitPasses();
    m_pRenderPass->SetVertexShader(m_pkVertex);
    m_pRenderPass->SetPixelShader(m_pkPixel);
    g_pkCurrentPass_b91f90 = m_pRenderPass;
    return true;
}

// Shadow/depth state stack: set the Z-enable render state on the first push at the current level, then count.

class B7DE0RenderState
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void SetRenderState(int eState, unsigned int uiValue, int iUnk1, int iUnk2);
};

class B7DE0Renderer
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
    B7DE0RenderState* m_pCurrentRenderState;
};

extern B7DE0Renderer* g_pkB7DE0Renderer;
extern unsigned int g_uiB7DE0Level;
extern int g_aiB7DE0PushCounts[];

// If the current level's push count is zero, sets render state 7 on the renderer, then adds iCount to that level's push count.
// @fnv 0x00b97de0
void __cdecl FUN_00b97de0(bool bEnable, int iCount)
{
    unsigned int uiTreeBlockIndex = g_uiB7DE0Level;
    if (g_aiB7DE0PushCounts[uiTreeBlockIndex] == 0)
        g_pkB7DE0Renderer->m_pCurrentRenderState->SetRenderState(7, bEnable, 0, 0);
    g_aiB7DE0PushCounts[uiTreeBlockIndex] += iCount;
}

extern unsigned int DAT_011ffa50;
struct FUN_00b98480_Sub
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
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26(int a, int b, int c, int d);
};
// If the counter at DAT_011ff9d8[idx] is zero, calls f26(8, 2 or 3, 0, 0) on the object at DAT_011f9508+0x8b8, then adds param_2 to the counter.
// @fnv 0x00b98480
void __cdecl FUN_00b98480(char abFlag, int aiAmount)
{
    unsigned int idx = DAT_011ffa50;
    if (DAT_011ff9d8[idx] == 0)
    {
        FUN_00b98480_Sub* sub = *(FUN_00b98480_Sub**)((char*)DAT_011f9508 + 0x8b8);
        int secondArg = (abFlag == 0) + 2;
        sub->f26(8, secondArg, 0, 0);
    }
    DAT_011ff9d8[idx] += aiAmount;
}

struct UShortNode
{
    unsigned short m_item;
    UShortNode* m_pkNext;
};

struct FUN_00b98970_shell
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
    UShortNode m_list2c;
    bool HasListedItemInRange(unsigned int aMin, unsigned int aMax);
};

// Walks the m_list2c list and returns true if any item within [aMin, aMax] equals one of the hard-coded values.
// @fnv 0x00b98970
bool FUN_00b98970_shell::HasListedItemInRange(unsigned int aMin, unsigned int aMax)
{
    for (UShortNode* p = &m_list2c; p; p = p->m_pkNext)
    {
        unsigned int uiValue = p->m_item;
        if (uiValue <= aMax && uiValue >= aMin)
        {
            if (uiValue == 0x28a || uiValue == 0x28d || uiValue == 0x28e || uiValue == 0x291 || uiValue == 0x292 ||
                uiValue == 0x295 || uiValue == 0x296 || uiValue == 0x299 || uiValue == 0x2ac || uiValue == 0x2af ||
                uiValue == 0x2b4 || uiValue == 0x2b5 || uiValue == 0x2b0 || uiValue == 0x2b3 || uiValue == 0x2b8 ||
                uiValue == 0x2bb || uiValue == 0x29b || uiValue == 0x29c || uiValue == 0x29f || uiValue == 0x2a0 ||
                uiValue == 0x2a3 || uiValue == 0x2a4 || uiValue == 0x2a7 || uiValue == 0x2a8 || uiValue == 0x2be ||
                uiValue == 0x2c1 || uiValue == 0x2c6 || uiValue == 0x2c7 || uiValue == 0x2c2 || uiValue == 0x2c5 ||
                uiValue == 0x2ca || uiValue == 0x2cd || uiValue == 0x2bd)
            {
                return true;
            }
        }
    }
    return false;
}

namespace fnv_00b9b540 {
extern float DAT_011ffe48;
extern float DAT_011ffe4c, DAT_011ffe50;
extern float DAT_011ffe5c, DAT_011ffe60;
extern float DAT_011ffe6c, DAT_011ffe70;
extern float DAT_011ffe7c, DAT_011ffe80, DAT_011ffe84;
extern float DAT_011ffe8c, DAT_011ffe90, DAT_011ffe94;

struct ImageSpaceTexture
{
    int unk00, unk04, unk08, unk0c;
    void FUN_00ba3840(unsigned int);
    void FUN_00ba3760(unsigned int);
    void FUN_00ba39a0();
};
struct PassConstants
{
    void FUN_00b8a790(unsigned int, float, float, float, float);
};
struct ShaderPrimary
{
    virtual void PrimarySlot0();
    int unk04, unk08, unk0c, unk10, unk14, unk18;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    int unk38, unk3c, unk40, unk44, unk48, unk4c, unk50;
    int unk54, unk58, unk5c, unk60, unk64, unk68;
};
struct ShaderStage
{
    virtual void Slot0();
    virtual void Render(void*, void*, PassConstants*, bool);
    void SetAccumulatorAt(unsigned int, ImageSpaceTexture*, unsigned int);
};
struct ShaderObject : ShaderPrimary, ShaderStage
{
};
struct EffectB9B540
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual bool Initialize(void*);
    unsigned char unk04;
    bool needsInitialize;
    unsigned short unk06;
    int unk08;
    ShaderStage** shaders;
    int unk10, unk14, unk18;
    PassConstants** constants;
    int unk20, unk24, unk28;
    ImageSpaceTexture** textures;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48;
    int unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    ImageSpaceTexture temporaryTexture;
    void FUN_00b9b540(void*, void*, void*, void*);
};
// Initializes the effect if needed, sets shader constants, binds textures, renders both shader stages and releases the temporary texture.
// @fnv 0x00b9b540
void EffectB9B540::FUN_00b9b540(void* renderer, void* target, void* input, void* unused)
{
    if (needsInitialize)
        needsInitialize = Initialize(input);
    temporaryTexture.FUN_00ba3840(50);
    ShaderStage* shader = static_cast<ShaderObject*>(shaders[0]);
    PassConstants* parameters = constants[0];
    parameters->FUN_00b8a790(0, DAT_011ffe4c, DAT_011ffe50, 0.0f, 0.0f);
    parameters->FUN_00b8a790(1, DAT_011ffe5c, DAT_011ffe60, 0.0f, 0.0f);
    parameters->FUN_00b8a790(2, DAT_011ffe6c, DAT_011ffe70, 0.0f, 0.0f);
    parameters->FUN_00b8a790(3, DAT_011ffe48, 0.0f, 0.0f, 0.0f);
    parameters->FUN_00b8a790(4, DAT_011ffe7c, DAT_011ffe80, DAT_011ffe84, 0.0f);
    parameters->FUN_00b8a790(5, DAT_011ffe8c, DAT_011ffe90, DAT_011ffe94, 0.0f);
    shader->SetAccumulatorAt(0, &temporaryTexture, 0);
    shader->SetAccumulatorAt(1, textures[1], 1);
    textures[0]->FUN_00ba3760(3);
    textures[1]->FUN_00ba3760(3);
    shader->Render(renderer, target, parameters, true);
    shader = static_cast<ShaderObject*>(shaders[1]);
    parameters = constants[1];
    parameters->FUN_00b8a790(0, DAT_011ffe4c, DAT_011ffe50, 0.0f, 0.0f);
    parameters->FUN_00b8a790(1, DAT_011ffe5c, DAT_011ffe60, 0.0f, 0.0f);
    parameters->FUN_00b8a790(2, DAT_011ffe6c, DAT_011ffe70, 0.0f, 0.0f);
    parameters->FUN_00b8a790(3, DAT_011ffe48, 0.0f, 0.0f, 0.0f);
    shader->SetAccumulatorAt(0, textures[0], 0);
    shader->SetAccumulatorAt(1, &temporaryTexture, 0);
    textures[0]->FUN_00ba3760(3);
    textures[1]->FUN_00ba3760(3);
    shader->Render(renderer, target, parameters, true);
    temporaryTexture.FUN_00ba39a0();
}
}  // namespace fnv_00b9b540

struct ImageSpaceShaderHDRBase
{
    virtual void vf00();
    ~ImageSpaceShaderHDRBase();
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
};

struct ImageSpaceShaderSecondary
{
    virtual void vf00();
};

struct ImageSpaceTextureArray
{
    void** m_pVtbl;
    ImageSpaceTexture** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetAt(unsigned int index, ImageSpaceTexture* const& value) throw();
};

struct FUN_00b8d4d0 : ImageSpaceShaderHDRBase, ImageSpaceShaderSecondary
{
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    ImageSpaceTextureArray m_94;
    void ReleaseTexture();
    ~FUN_00b8d4d0();
};

// Releases the texture, destroys and deallocates the texture stored at index 2 of m_94, then clears that slot.
// @fnv 0x00b8d4d0
FUN_00b8d4d0::~FUN_00b8d4d0()
{
    ReleaseTexture();
    if (m_94.m_pBase[2] != 0)
    {
        ImageSpaceTexture* pTexture = m_94.m_pBase[2];
        if (pTexture != 0)
        {
            pTexture->~ImageSpaceTexture();
            g_memoryManager.Deallocate(pTexture);
        }
        m_94.SetAt(2, 0);
    }
}

struct Header6c
{
    static void* operator new(unsigned int n);
    virtual void h0();
    int hdr_00_4, hdr_00_8, hdr_00_c, hdr_00_10, hdr_00_14, hdr_00_18, hdr_00_1c, hdr_00_20, hdr_00_24, hdr_00_28,
        hdr_00_2c, hdr_00_30, hdr_00_34, hdr_00_38, hdr_00_3c, hdr_00_40, hdr_00_44, hdr_00_48, hdr_00_4c, hdr_00_50,
        hdr_00_54, hdr_00_58, hdr_00_5c, hdr_00_60, hdr_00_64, hdr_00_68;
};
struct AllocSvc
{
    void* __thiscall FUN_00aa3e40(unsigned int n);
};
extern AllocSvc DAT_011f6238;
struct NiMemObj
{
    static void* operator new(unsigned int n)
    {
        return DAT_011f6238.FUN_00aa3e40(n);
    }
};
struct ISEffect
{
    virtual void e0();
};
struct ISSBase : ISEffect
{
    ISSBase();
    ~ISSBase();
    int iss_00_4, iss_00_8, iss_00_c, iss_00_10, iss_00_14, iss_00_18, iss_00_1c, iss_00_20, iss_00_24, iss_00_28,
        iss_00_2c, iss_00_30, iss_00_34, iss_00_38, iss_00_3c, iss_00_40, iss_00_44, iss_00_48, iss_00_4c, iss_00_50,
        iss_00_54, iss_00_58, iss_00_5c, iss_00_60;
};
struct Registry
{
    int r_00;
    void** r_04;
    unsigned short r_08;
    unsigned short r_0a;
    unsigned short r_0c;
    unsigned short r_0e;
    __declspec(noinline) void SetAt(unsigned int index, void* const& value)
    {
        if (index >= r_0a)
        {
            r_0a = (unsigned short)(index + 1);
            if (value)
                ++r_0c;
        }
        else if (value)
        {
            if (!r_04[index])
                ++r_0c;
        }
        else
        {
            if (r_04[index])
                --r_0c;
        }
        r_04[index] = value;
    }

    __forceinline void Assign(unsigned short index, ISSBase* value)
    {
        if (index >= r_0a)
        {
            r_0a = (unsigned short)(index + 1);
            if (value)
                ++r_0c;
        }
        else if (value)
        {
            if (!r_04[index])
                ++r_0c;
        }
        else
        {
            if (r_04[index])
                --r_0c;
        }
        r_04[index] = value;
    }
    __forceinline void AssignKnownU(unsigned int index, void* value)
    {
        if (index >= r_0a)
        {
            r_0a = (unsigned short)(index + 1);
            ++r_0c;
        }
        else if (!r_04[index])
        {
            ++r_0c;
        }
        r_04[index] = value;
    }
};
struct CBA4640 : NiMemObj
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void Call20(int n);
    virtual void Call24(int n);
    int data_00_0, data_00_4, data_00_8, data_00_c, data_00_10, data_00_14, data_00_18, data_00_1c, data_00_20,
        data_00_24, data_00_28, data_00_2c, data_00_30, data_00_34, data_00_38, data_00_3c, data_00_40, data_00_44,
        data_00_48, data_00_4c, data_00_50, data_00_54, data_00_58;
    CBA4640();
};
struct CC05680 : NiMemObj
{
    int data_00_0, data_00_4, data_00_8, data_00_c, data_00_10, data_00_14, data_00_18, data_00_1c, data_00_20,
        data_00_24, data_00_28, data_00_2c, data_00_30, data_00_34, data_00_38, data_00_3c, data_00_40, data_00_44,
        data_00_48, data_00_4c, data_00_50, data_00_54, data_00_58, data_00_5c, data_00_60, data_00_64;
    CC05680();
};
struct CBD93D0 : NiMemObj
{
    int data_00_0, data_00_4, data_00_8, data_00_c, data_00_10, data_00_14, data_00_18, data_00_1c, data_00_20,
        data_00_24, data_00_28, data_00_2c, data_00_30, data_00_34, data_00_38, data_00_3c, data_00_40, data_00_44,
        data_00_48, data_00_4c, data_00_50, data_00_54, data_00_58, data_00_5c, data_00_60, data_00_64;
    CBD93D0();
};
struct CC03810 : NiMemObj
{
    int data_00_0, data_00_4, data_00_8, data_00_c, data_00_10, data_00_14, data_00_18, data_00_1c, data_00_20,
        data_00_24, data_00_28, data_00_2c, data_00_30, data_00_34, data_00_38, data_00_3c, data_00_40, data_00_44,
        data_00_48, data_00_4c, data_00_50, data_00_54, data_00_58, data_00_5c, data_00_60, data_00_64, data_00_68,
        data_00_6c, data_00_70, data_00_74, data_00_78;
    CC03810();
};
struct CBAD500 : NiMemObj
{
    int data_00_0, data_00_4, data_00_8, data_00_c, data_00_10, data_00_14, data_00_18, data_00_1c, data_00_20,
        data_00_24, data_00_28, data_00_2c, data_00_30, data_00_34, data_00_38, data_00_3c, data_00_40, data_00_44,
        data_00_48, data_00_4c, data_00_50, data_00_54, data_00_58, data_00_5c, data_00_60, data_00_64, data_00_68,
        data_00_6c;
    CBAD500();
};
struct CC05420 : NiMemObj
{
    int data_00_0, data_00_4, data_00_8, data_00_c, data_00_10, data_00_14, data_00_18, data_00_1c, data_00_20,
        data_00_24, data_00_28, data_00_2c, data_00_30, data_00_34, data_00_38, data_00_3c, data_00_40, data_00_44,
        data_00_48, data_00_4c, data_00_50, data_00_54, data_00_58, data_00_5c, data_00_60, data_00_64, data_00_68,
        data_00_6c, data_00_70, data_00_74, data_00_78;
    CC05420();
};
struct CC04D20 : NiMemObj
{
    int data_00_0, data_00_4, data_00_8, data_00_c, data_00_10, data_00_14, data_00_18, data_00_1c, data_00_20,
        data_00_24, data_00_28, data_00_2c, data_00_30, data_00_34, data_00_38, data_00_3c, data_00_40, data_00_44,
        data_00_48, data_00_4c, data_00_50, data_00_54, data_00_58, data_00_5c, data_00_60, data_00_64, data_00_68,
        data_00_6c, data_00_70, data_00_74, data_00_78, data_00_7c, data_00_80, data_00_84, data_00_88, data_00_8c,
        data_00_90, data_00_94, data_00_98, data_00_9c, data_00_a0, data_00_a4, data_00_a8, data_00_ac, data_00_b0,
        data_00_b4, data_00_b8, data_00_bc, data_00_c0, data_00_c4;
    CC04D20();
};
struct CBB8900 : NiMemObj
{
    int data_00_0, data_00_4, data_00_8, data_00_c, data_00_10, data_00_14, data_00_18, data_00_1c, data_00_20,
        data_00_24, data_00_28, data_00_2c, data_00_30, data_00_34, data_00_38, data_00_3c, data_00_40, data_00_44,
        data_00_48, data_00_4c, data_00_50, data_00_54;
    CBB8900();
};
struct CBC0600 : NiMemObj
{
    int data_00_0, data_00_4, data_00_8, data_00_c, data_00_10, data_00_14, data_00_18, data_00_1c, data_00_20,
        data_00_24, data_00_28, data_00_2c, data_00_30, data_00_34, data_00_38, data_00_3c, data_00_40, data_00_44,
        data_00_48, data_00_4c, data_00_50, data_00_54;
    CBC0600();
};
struct CBD7120 : NiMemObj
{
    int data_00_0, data_00_4, data_00_8, data_00_c, data_00_10, data_00_14, data_00_18, data_00_1c, data_00_20,
        data_00_24, data_00_28, data_00_2c, data_00_30, data_00_34, data_00_38, data_00_3c, data_00_40, data_00_44,
        data_00_48, data_00_4c, data_00_50, data_00_54, data_00_58, data_00_5c, data_00_60, data_00_64, data_00_68,
        data_00_6c, data_00_70, data_00_74, data_00_78, data_00_7c, data_00_80, data_00_84, data_00_88, data_00_8c,
        data_00_90, data_00_94, data_00_98, data_00_9c, data_00_a0, data_00_a4, data_00_a8, data_00_ac, data_00_b0,
        data_00_b4, data_00_b8;
    CBD7120();
};
struct CC049C0 : NiMemObj
{
    int data_00_0, data_00_4, data_00_8, data_00_c, data_00_10, data_00_14, data_00_18, data_00_1c, data_00_20,
        data_00_24, data_00_28, data_00_2c, data_00_30, data_00_34, data_00_38, data_00_3c, data_00_40, data_00_44,
        data_00_48, data_00_4c, data_00_50, data_00_54, data_00_58, data_00_5c, data_00_60, data_00_64, data_00_68,
        data_00_6c, data_00_70, data_00_74;
    CC049C0();
};
struct CBA4880 : NiMemObj
{
    int data_00_0, data_00_4, data_00_8, data_00_c, data_00_10, data_00_14, data_00_18, data_00_1c, data_00_20,
        data_00_24, data_00_28, data_00_2c, data_00_30, data_00_34, data_00_38, data_00_3c, data_00_40, data_00_44,
        data_00_48, data_00_4c, data_00_50, data_00_54, data_00_58, data_00_5c, data_00_60, data_00_64, data_00_68,
        data_00_6c, data_00_70, data_00_74, data_00_78, data_00_7c, data_00_80, data_00_84;
    CBA4880();
};
struct CB5A590 : NiMemObj
{
    int data_00_0, data_00_4, data_00_8, data_00_c, data_00_10, data_00_14, data_00_18, data_00_1c, data_00_20,
        data_00_24, data_00_28, data_00_2c, data_00_30, data_00_34, data_00_38, data_00_3c, data_00_40, data_00_44,
        data_00_48, data_00_4c, data_00_50, data_00_54, data_00_58, data_00_5c, data_00_60, data_00_64, data_00_68,
        data_00_6c, data_00_70, data_00_74, data_00_78, data_00_7c, data_00_80, data_00_84, data_00_88, data_00_8c,
        data_00_90, data_00_94, data_00_98, data_00_9c, data_00_a0, data_00_a4, data_00_a8, data_00_ac, data_00_b0,
        data_00_b4, data_00_b8, data_00_bc, data_00_c0, data_00_c4, data_00_c8, data_00_cc, data_00_d0;
    CB5A590();
};
struct CB5A410 : NiMemObj
{
    int data_00_0, data_00_4, data_00_8, data_00_c, data_00_10, data_00_14, data_00_18, data_00_1c, data_00_20,
        data_00_24, data_00_28, data_00_2c, data_00_30, data_00_34, data_00_38, data_00_3c, data_00_40, data_00_44,
        data_00_48, data_00_4c, data_00_50, data_00_54, data_00_58, data_00_5c, data_00_60, data_00_64, data_00_68,
        data_00_6c, data_00_70;
    CB5A410();
};
struct CBAA160 : NiMemObj
{
    int data_00_0, data_00_4, data_00_8, data_00_c, data_00_10, data_00_14, data_00_18, data_00_1c, data_00_20,
        data_00_24, data_00_28, data_00_2c, data_00_30, data_00_34, data_00_38, data_00_3c, data_00_40, data_00_44,
        data_00_48, data_00_4c, data_00_50, data_00_54;
    CBAA160();
};
struct CC04600 : NiMemObj
{
    int data_00_0, data_00_4, data_00_8, data_00_c, data_00_10, data_00_14, data_00_18, data_00_1c, data_00_20,
        data_00_24, data_00_28, data_00_2c, data_00_30, data_00_34, data_00_38, data_00_3c, data_00_40, data_00_44,
        data_00_48, data_00_4c, data_00_50, data_00_54, data_00_58, data_00_5c, data_00_60;
    CC04600();
};
struct CBA15E0 : NiMemObj
{
    int data_00_0, data_00_4, data_00_8, data_00_c, data_00_10, data_00_14, data_00_18, data_00_1c, data_00_20,
        data_00_24, data_00_28, data_00_2c, data_00_30, data_00_34, data_00_38, data_00_3c, data_00_40, data_00_44,
        data_00_48, data_00_4c, data_00_50, data_00_54, data_00_58, data_00_5c, data_00_60, data_00_64, data_00_68,
        data_00_6c, data_00_70, data_00_74, data_00_78, data_00_7c, data_00_80, data_00_84, data_00_88, data_00_8c,
        data_00_90, data_00_94, data_00_98, data_00_9c, data_00_a0, data_00_a4, data_00_a8, data_00_ac, data_00_b0,
        data_00_b4, data_00_b8;
    CBA15E0();
};
struct CBA02F0 : NiMemObj
{
    int data_00_0, data_00_4, data_00_8, data_00_c, data_00_10, data_00_14, data_00_18, data_00_1c, data_00_20,
        data_00_24, data_00_28, data_00_2c, data_00_30, data_00_34, data_00_38, data_00_3c, data_00_40, data_00_44,
        data_00_48, data_00_4c, data_00_50, data_00_54, data_00_58, data_00_5c, data_00_60, data_00_64, data_00_68,
        data_00_6c, data_00_70;
    CBA02F0();
};
struct CB9B830 : NiMemObj
{
    int data_00_0, data_00_4, data_00_8, data_00_c, data_00_10, data_00_14, data_00_18, data_00_1c, data_00_20,
        data_00_24, data_00_28, data_00_2c, data_00_30, data_00_34, data_00_38, data_00_3c, data_00_40, data_00_44,
        data_00_48, data_00_4c, data_00_50, data_00_54, data_00_58, data_00_5c, data_00_60, data_00_64, data_00_68,
        data_00_6c, data_00_70, data_00_74, data_00_78, data_00_7c, data_00_80, data_00_84, data_00_88, data_00_8c,
        data_00_90, data_00_94, data_00_98, data_00_9c, data_00_a0, data_00_a4, data_00_a8, data_00_ac, data_00_b0,
        data_00_b4, data_00_b8, data_00_bc, data_00_c0, data_00_c4, data_00_c8, data_00_cc, data_00_d0, data_00_d4,
        data_00_d8, data_00_dc, data_00_e0, data_00_e4, data_00_e8, data_00_ec, data_00_f0, data_00_f4, data_00_f8,
        data_00_fc, data_00_100, data_00_104, data_00_108, data_00_10c, data_00_110, data_00_114, data_00_118,
        data_00_11c, data_00_120, data_00_124, data_00_128, data_00_12c, data_00_130, data_00_134, data_00_138,
        data_00_13c, data_00_140, data_00_144, data_00_148, data_00_14c, data_00_150, data_00_154, data_00_158,
        data_00_15c, data_00_160, data_00_164, data_00_168, data_00_16c, data_00_170, data_00_174, data_00_178,
        data_00_17c, data_00_180, data_00_184, data_00_188, data_00_18c, data_00_190, data_00_194, data_00_198,
        data_00_19c, data_00_1a0, data_00_1a4, data_00_1a8, data_00_1ac, data_00_1b0, data_00_1b4, data_00_1b8,
        data_00_1bc, data_00_1c0, data_00_1c4, data_00_1c8, data_00_1cc, data_00_1d0, data_00_1d4, data_00_1d8,
        data_00_1dc, data_00_1e0, data_00_1e4, data_00_1e8, data_00_1ec, data_00_1f0, data_00_1f4, data_00_1f8,
        data_00_1fc, data_00_200, data_00_204, data_00_208, data_00_20c, data_00_210, data_00_214, data_00_218,
        data_00_21c, data_00_220, data_00_224, data_00_228, data_00_22c, data_00_230, data_00_234, data_00_238,
        data_00_23c, data_00_240, data_00_244, data_00_248, data_00_24c, data_00_250, data_00_254, data_00_258,
        data_00_25c, data_00_260, data_00_264, data_00_268, data_00_26c, data_00_270, data_00_274, data_00_278,
        data_00_27c, data_00_280, data_00_284, data_00_288, data_00_28c, data_00_290, data_00_294, data_00_298,
        data_00_29c, data_00_2a0, data_00_2a4, data_00_2a8, data_00_2ac, data_00_2b0, data_00_2b4, data_00_2b8;
    CB9B830();
};
struct CC033C0 : NiMemObj
{
    int data_00_0, data_00_4, data_00_8, data_00_c, data_00_10, data_00_14, data_00_18, data_00_1c, data_00_20,
        data_00_24, data_00_28, data_00_2c, data_00_30, data_00_34, data_00_38, data_00_3c, data_00_40, data_00_44,
        data_00_48, data_00_4c, data_00_50, data_00_54, data_00_58, data_00_5c, data_00_60, data_00_64;
    CC033C0();
};
struct CBB9180 : NiMemObj
{
    int data_00_0, data_00_4, data_00_8, data_00_c, data_00_10, data_00_14, data_00_18, data_00_1c, data_00_20,
        data_00_24, data_00_28, data_00_2c, data_00_30, data_00_34, data_00_38, data_00_3c, data_00_40, data_00_44,
        data_00_48, data_00_4c, data_00_50, data_00_54;
    CBB9180();
};
void* __cdecl FUN_00aa13e0(unsigned int n);
struct CB8EFA0
{
    CB8EFA0* __thiscall FUN_00b8efa0();
};
struct CB8F010
{
    CB8F010* __thiscall FUN_00b8f010();
};
struct CB8F660
{
    CB8F660* __thiscall FUN_00b8f660();
};
struct CB8F520
{
    CB8F520* __thiscall FUN_00b8f520();
};
struct CB8F1B0
{
    CB8F1B0* __thiscall FUN_00b8f1b0();
};
struct CB8F360
{
    CB8F360* __thiscall FUN_00b8f360();
};
struct CB92180
{
    CB92180* __thiscall FUN_00b92180();
};
struct CB8D330
{
    CB8D330* __thiscall FUN_00b8d330();
};
struct CB8D850
{
    CB8D850* __thiscall FUN_00b8d850();
};
struct CB8FEA0
{
    CB8FEA0* __thiscall FUN_00b8fea0();
};
struct CB8D5B0
{
    CB8D5B0* __thiscall FUN_00b8d5b0();
};
struct CB8D700
{
    CB8D700* __thiscall FUN_00b8d700();
};
struct CB922D0
{
    CB922D0* __thiscall FUN_00b922d0();
};
struct CB8EE20
{
    CB8EE20* __thiscall FUN_00b8ee20();
};
struct CB8F7E0
{
    CB8F7E0* __thiscall FUN_00b8f7e0();
};
struct CB8FD40
{
    CB8FD40* __thiscall FUN_00b8fd40();
};
struct CB917C0
{
    CB917C0* __thiscall FUN_00b917c0();
};
struct CB91900
{
    CB91900* __thiscall FUN_00b91900();
};
struct CB91B80
{
    CB91B80* __thiscall FUN_00b91b80();
};
struct CB8F930
{
    CB8F930* __thiscall FUN_00b8f930();
};
struct CB8FA80
{
    CB8FA80* __thiscall FUN_00b8fa80();
};
struct CB8FBE0
{
    CB8FBE0* __thiscall FUN_00b8fbe0();
};
struct CB8BEA0
{
    CB8BEA0* __thiscall FUN_00b8bea0();
};
struct CB8FFF0
{
    CB8FFF0* __thiscall FUN_00b8fff0();
};
struct CB90190
{
    CB90190* __thiscall FUN_00b90190();
};
struct CB90330
{
    CB90330* __thiscall FUN_00b90330();
};
struct CB90520
{
    CB90520* __thiscall FUN_00b90520();
};
struct CB906B0
{
    CB906B0* __thiscall FUN_00b906b0();
};
struct CB90830
{
    CB90830* __thiscall FUN_00b90830();
};
struct CB909C0
{
    CB909C0* __thiscall FUN_00b909c0();
};
struct CB90B50
{
    CB90B50* __thiscall FUN_00b90b50();
};
struct CB91000
{
    CB91000* __thiscall FUN_00b91000();
};
struct CB911A0
{
    CB911A0* __thiscall FUN_00b911a0();
};
struct CB91340
{
    CB91340* __thiscall FUN_00b91340();
};
struct CB914E0
{
    CB914E0* __thiscall FUN_00b914e0();
};
struct CB90CE0
{
    CB90CE0* __thiscall FUN_00b90ce0();
};
struct CB90E70
{
    CB90E70* __thiscall FUN_00b90e70();
};
struct CB91680
{
    CB91680* __thiscall FUN_00b91680();
};
struct CB8BCE0
{
    CB8BCE0* __thiscall FUN_00b8bce0();
};
struct CB92500
{
    CB92500* __thiscall FUN_00b92500();
};
struct CB91A40
{
    CB91A40* __thiscall FUN_00b91a40();
};
struct CB8D990
{
    CB8D990* __thiscall FUN_00b8d990();
};
struct CB8DAE0
{
    CB8DAE0* __thiscall FUN_00b8dae0();
};
struct CB8DC30
{
    CB8DC30* __thiscall FUN_00b8dc30();
};
struct CB8DD80
{
    CB8DD80* __thiscall FUN_00b8dd80();
};
struct CB8DED0
{
    CB8DED0* __thiscall FUN_00b8ded0();
};
struct CB8E020
{
    CB8E020* __thiscall FUN_00b8e020();
};
struct CB8E170
{
    CB8E170* __thiscall FUN_00b8e170();
};
struct CB8E2C0
{
    CB8E2C0* __thiscall FUN_00b8e2c0();
};
struct CB8E460
{
    CB8E460* __thiscall FUN_00b8e460();
};
struct CB8E600
{
    CB8E600* __thiscall FUN_00b8e600();
};
struct CB8E7A0
{
    CB8E7A0* __thiscall FUN_00b8e7a0();
};
struct CB8E940
{
    CB8E940* __thiscall FUN_00b8e940();
};
struct CB8EAE0
{
    CB8EAE0* __thiscall FUN_00b8eae0();
};
struct CB8EC80
{
    CB8EC80* __thiscall FUN_00b8ec80();
};
struct CB932D0
{
    CB932D0* __thiscall FUN_00b932d0();
};
struct CB93600
{
    CB93600* __thiscall FUN_00b93600();
};
struct CB93950
{
    CB93950* __thiscall FUN_00b93950();
};
struct CB93AA0
{
    CB93AA0* __thiscall FUN_00b93aa0();
};
struct CB93BF0
{
    CB93BF0* __thiscall FUN_00b93bf0();
};
struct CB93D40
{
    CB93D40* __thiscall FUN_00b93d40();
};
struct CB93E90
{
    CB93E90* __thiscall FUN_00b93e90();
};
struct CB93FE0
{
    CB93FE0* __thiscall FUN_00b93fe0();
};
struct CB94130
{
    CB94130* __thiscall FUN_00b94130();
};
struct CB94280
{
    CB94280* __thiscall FUN_00b94280();
};
struct CB943D0
{
    CB943D0* __thiscall FUN_00b943d0();
};
struct CB92690
{
    CB92690* __thiscall FUN_00b92690();
};
struct CB927E0
{
    CB927E0* __thiscall FUN_00b927e0();
};
struct CB92930
{
    CB92930* __thiscall FUN_00b92930();
};
struct CB92A80
{
    CB92A80* __thiscall FUN_00b92a80();
};
struct CB92BD0
{
    CB92BD0* __thiscall FUN_00b92bd0();
};
struct CB92D90
{
    CB92D90* __thiscall FUN_00b92d90();
};
struct CB92EE0
{
    CB92EE0* __thiscall FUN_00b92ee0();
};
struct CB93030
{
    CB93030* __thiscall FUN_00b93030();
};
struct CB93180
{
    CB93180* __thiscall FUN_00b93180();
};
struct CB91CF0
{
    CB91CF0* __thiscall FUN_00b91cf0();
};
struct CNB91E40 : Header6c, ISSBase
{
    CNB91E40();
};
struct CNB8C070 : Header6c, ISSBase
{
    CNB8C070();
};
struct TailObj
{
    virtual void t0();
    virtual void t1();
    virtual void t2();
    virtual void t3();
    virtual void t4();
    virtual void t5();
    virtual void t6();
    virtual void t7();
    virtual void t8();
    virtual void t9();
    virtual void t10();
    virtual void t11();
    virtual void t12();
    virtual void t13();
    virtual void t14();
    virtual void t15();
    virtual void t16();
    virtual void t17();
    virtual void t18();
    virtual void t19();
    virtual void t20();
    virtual void t21();
    virtual void t22();
    virtual void t23();
    virtual void t24();
    virtual void t25();
    virtual void t26();
    virtual void t27();
    virtual void t28();
    virtual void t29();
    virtual void t30();
    virtual void t31();
    virtual void t32();
    virtual void t33();
    virtual void t34();
    virtual void t35();
    virtual void t36();
    virtual void t37();
    virtual void t38();
    virtual void t39();
    virtual void t40();
    virtual void t41();
    virtual void t42();
    virtual void t43();
    virtual void t44();
    virtual void t45();
    virtual void t46();
    virtual void t47();
    virtual void t48();
    virtual void t49();
    virtual void t50();
    virtual void t51();
    virtual void t52();
    virtual void t53();
    virtual void t54();
    virtual void t55();
    virtual void t56();
    virtual void t57();
    virtual void t58();
    virtual void t59();
    virtual void t60();
    virtual void t61();
    virtual void t62();
    virtual void t63();
    virtual void t64();
    virtual void t65();
    virtual void t66();
    virtual void t67();
    virtual void t68();
    virtual void t69();
    virtual void t70();
    virtual void t71();
    virtual void Call120();
};
struct ShaderHeader : TailObj
{
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
};
struct ShaderLayout : ShaderHeader, ISSBase
{
};
struct Temp
{
    void* p;
    ~Temp();
};
struct CNB8EFA0 : Header6c, ISSBase
{
    CNB8EFA0();
};
struct CNB8F010 : Header6c, ISSBase
{
    CNB8F010();
};
struct CNB8F660 : Header6c, ISSBase
{
    CNB8F660();
};
struct CNB8F520 : Header6c, ISSBase
{
    CNB8F520();
};
struct CNB8F1B0 : Header6c, ISSBase
{
    CNB8F1B0();
};
struct CNB8F360 : Header6c, ISSBase
{
    CNB8F360();
};
struct CNB92180 : Header6c, ISSBase
{
    CNB92180();
};
struct CNB8D330 : Header6c, ISSBase
{
    CNB8D330();
};
struct CNB8D850 : Header6c, ISSBase
{
    CNB8D850();
};
struct CNB8FEA0 : Header6c, ISSBase
{
    CNB8FEA0();
};
struct CNB8D5B0 : Header6c, ISSBase
{
    CNB8D5B0();
};
struct CNB8D700 : Header6c, ISSBase
{
    CNB8D700();
};
struct ISSBase68 : ISSBase
{
    ISSBase68();
    ~ISSBase68();
    int iss_00_64;
};
struct CNB922D0 : Header6c, ISSBase68
{
    CNB922D0();
};
struct CNB8EE20 : Header6c, ISSBase
{
    CNB8EE20();
};
struct CNB8F7E0 : Header6c, ISSBase
{
    CNB8F7E0();
};
struct CNB8FD40 : Header6c, ISSBase
{
    CNB8FD40();
};
struct CNB917C0 : Header6c, ISSBase
{
    CNB917C0();
};
struct CNB91900 : Header6c, ISSBase
{
    CNB91900();
};
struct CNB91B80 : Header6c, ISSBase
{
    CNB91B80();
};
struct CNB8F930 : Header6c, ISSBase
{
    CNB8F930();
};
struct CNB8FA80 : Header6c, ISSBase
{
    CNB8FA80();
};
struct CNB8FBE0 : Header6c, ISSBase
{
    CNB8FBE0();
};
struct CNB8BEA0 : Header6c, ISSBase
{
    CNB8BEA0();
};
struct CNB8FFF0 : Header6c, ISSBase
{
    CNB8FFF0();
};
struct CNB90190 : Header6c, ISSBase
{
    CNB90190();
};
struct CNB90330 : Header6c, ISSBase
{
    CNB90330();
};
struct CNB90520 : Header6c, ISSBase
{
    CNB90520();
};
struct CNB906B0 : Header6c, ISSBase
{
    CNB906B0();
};
struct CNB90830 : Header6c, ISSBase
{
    CNB90830();
};
struct CNB909C0 : Header6c, ISSBase
{
    CNB909C0();
};
struct CNB90B50 : Header6c, ISSBase
{
    CNB90B50();
};
struct CNB91000 : Header6c, ISSBase
{
    CNB91000();
};
struct CNB911A0 : Header6c, ISSBase
{
    CNB911A0();
};
struct CNB91340 : Header6c, ISSBase
{
    CNB91340();
};
struct CNB914E0 : Header6c, ISSBase
{
    CNB914E0();
};
struct CNB90CE0 : Header6c, ISSBase
{
    CNB90CE0();
};
struct CNB90E70 : Header6c, ISSBase
{
    CNB90E70();
};
struct CNB91680 : Header6c, ISSBase
{
    CNB91680();
};
struct CNB8BCE0 : Header6c, ISSBase
{
    CNB8BCE0();
};
struct CNB92500 : Header6c, ISSBase
{
    CNB92500();
};
struct CNB91A40 : Header6c, ISSBase
{
    CNB91A40();
};
struct CNB8D990 : Header6c, ISSBase
{
    CNB8D990();
};
struct CNB8DAE0 : Header6c, ISSBase
{
    CNB8DAE0();
};
struct CNB8DC30 : Header6c, ISSBase
{
    CNB8DC30();
};
struct CNB8DD80 : Header6c, ISSBase
{
    CNB8DD80();
};
struct CNB8DED0 : Header6c, ISSBase
{
    CNB8DED0();
};
struct CNB8E020 : Header6c, ISSBase
{
    CNB8E020();
};
struct CNB8E170 : Header6c, ISSBase
{
    CNB8E170();
};
struct CNB8E2C0 : Header6c, ISSBase
{
    CNB8E2C0();
};
struct CNB8E460 : Header6c, ISSBase
{
    CNB8E460();
};
struct CNB8E600 : Header6c, ISSBase
{
    CNB8E600();
};
struct CNB8E7A0 : Header6c, ISSBase
{
    CNB8E7A0();
};
struct CNB8E940 : Header6c, ISSBase
{
    CNB8E940();
};
struct CNB8EAE0 : Header6c, ISSBase
{
    CNB8EAE0();
};
struct CNB8EC80 : Header6c, ISSBase
{
    CNB8EC80();
};
struct CNB932D0 : Header6c, ISSBase
{
    CNB932D0();
};
struct CNB93600 : Header6c, ISSBase
{
    CNB93600();
};
struct CNB93950 : Header6c, ISSBase
{
    CNB93950();
};
struct CNB93AA0 : Header6c, ISSBase
{
    CNB93AA0();
};
struct CNB93BF0 : Header6c, ISSBase
{
    CNB93BF0();
};
struct CNB93D40 : Header6c, ISSBase
{
    CNB93D40();
};
struct CNB93E90 : Header6c, ISSBase
{
    CNB93E90();
};
struct CNB93FE0 : Header6c, ISSBase
{
    CNB93FE0();
};
struct CNB94130 : Header6c, ISSBase
{
    CNB94130();
};
struct CNB94280 : Header6c, ISSBase
{
    CNB94280();
};
struct CNB943D0 : Header6c, ISSBase
{
    CNB943D0();
};
struct CNB92690 : Header6c, ISSBase
{
    CNB92690();
};
struct CNB927E0 : Header6c, ISSBase
{
    CNB927E0();
};
struct CNB92930 : Header6c, ISSBase
{
    CNB92930();
};
struct CNB92A80 : Header6c, ISSBase
{
    CNB92A80();
};
struct CNB92BD0 : Header6c, ISSBase
{
    CNB92BD0();
};
struct CNB92D90 : Header6c, ISSBase
{
    CNB92D90();
};
struct CNB92EE0 : Header6c, ISSBase
{
    CNB92EE0();
};
struct CNB93030 : Header6c, ISSBase
{
    CNB93030();
};
struct CNB93180 : Header6c, ISSBase
{
    CNB93180();
};
struct CNB91CF0 : Header6c, ISSBase
{
    CNB91CF0();
};
struct B94520Cls
{
    int m_00;
    Registry m_04;
    void __thiscall FUN_00b94520();
};
// @fnv 0x00b94520
void __thiscall B94520Cls::FUN_00b94520()
{
    {
        m_04.SetAt(13, new CC05680);
    }
    {
        m_04.SetAt(2, new CBD93D0);
    }
    {
        m_04.SetAt(8, new CC03810);
    }
    {
        m_04.SetAt(1, new CBAD500);
    }
    {
        m_04.SetAt(0, new CC05420);
    }
    {
        m_04.SetAt(3, new CC04D20);
    }
    {
        m_04.SetAt(10, new CBB8900);
    }
    {
        m_04.SetAt(11, new CBC0600);
    }
    {
        m_04.SetAt(4, new CBD7120);
    }
    {
        m_04.SetAt(12, new CC049C0);
    }
    {
        m_04.SetAt(7, new CBA4880);
    }
    {
        m_04.SetAt(5, new CB5A590);
    }
    {
        m_04.SetAt(6, new CB5A410);
    }
    {
        m_04.SetAt(14, new CBAA160);
    }
    {
        m_04.SetAt(15, new CC04600);
    }
    {
        m_04.SetAt(31, new CBA15E0);
    }
    {
        m_04.SetAt(32, new CBA02F0);
    }
    {
        m_04.SetAt(33, new CB9B830);
    }
    {
        m_04.SetAt(9, new CC033C0);
    }
    {
        m_04.SetAt(30, new CBB9180);
    }
    {
        for (unsigned int i = 0; i < 7; i++)
        {
            CBA4640* obj = new CBA4640;
            obj->Call20(i + 1);
            obj->Call24(0);
            m_04.AssignKnownU(i + 16, obj);
            CBA4640* obj2 = new CBA4640;
            obj2->Call20(i + 1);
            obj2->Call24(1);
            m_04.AssignKnownU(i + 23, obj2);
        }
    }
    {
        m_04.Assign(34, new CNB8EFA0);
    }
    {
        m_04.Assign(35, new CNB8F010);
    }
    {
        m_04.Assign(36, new CNB8F660);
    }
    {
        m_04.Assign(37, new CNB8F520);
    }
    {
        m_04.Assign(38, new CNB8EFA0);
    }
    {
        m_04.Assign(39, new CNB8F1B0);
    }
    {
        m_04.Assign(40, new CNB8F360);
    }
    {
        m_04.Assign(41, new CNB92180);
    }
    {
        m_04.Assign(42, new CNB8D330);
    }
    {
        m_04.Assign(43, new CNB8D850);
    }
    {
        m_04.Assign(44, new CNB8FEA0);
    }
    {
        m_04.Assign(45, new CNB8D5B0);
    }
    {
        m_04.Assign(46, new CNB8D700);
    }
    {
        m_04.Assign(47, new CNB922D0);
    }
    {
        m_04.Assign(50, new CNB8EE20);
    }
    {
        m_04.Assign(51, new CNB8F7E0);
    }
    {
        m_04.Assign(52, new CNB8FD40);
    }
    {
        m_04.Assign(48, new CNB917C0);
    }
    {
        m_04.Assign(49, new CNB91900);
    }
    {
        m_04.Assign(53, new CNB91B80);
    }
    {
        m_04.Assign(54, new CNB8F930);
    }
    {
        m_04.Assign(55, new CNB8FA80);
    }
    {
        m_04.Assign(56, new CNB8FBE0);
    }
    {
        m_04.Assign(57, new CNB8BEA0);
    }
    {
        m_04.Assign(58, new CNB8FFF0);
    }
    {
        m_04.Assign(59, new CNB90190);
    }
    {
        m_04.Assign(60, new CNB90330);
    }
    {
        m_04.Assign(61, new CNB90520);
    }
    {
        m_04.Assign(62, new CNB906B0);
    }
    {
        m_04.Assign(63, new CNB90830);
    }
    {
        m_04.Assign(64, new CNB909C0);
    }
    {
        m_04.Assign(65, new CNB90B50);
    }
    {
        m_04.Assign(67, new CNB91000);
    }
    {
        m_04.Assign(66, new CNB911A0);
    }
    {
        m_04.Assign(69, new CNB91340);
    }
    {
        m_04.Assign(68, new CNB914E0);
    }
    {
        m_04.Assign(70, new CNB90CE0);
    }
    {
        m_04.Assign(71, new CNB90E70);
    }
    {
        m_04.Assign(72, new CNB91680);
    }
    {
        m_04.Assign(73, new CNB8BCE0);
    }
    {
        m_04.Assign(75, new CNB92500);
    }
    {
        m_04.Assign(76, new CNB91A40);
    }
    {
        m_04.Assign(78, new CNB8D990);
    }
    {
        m_04.Assign(79, new CNB8DAE0);
    }
    {
        m_04.Assign(80, new CNB8DC30);
    }
    {
        m_04.Assign(81, new CNB8DD80);
    }
    {
        m_04.Assign(82, new CNB8DED0);
    }
    {
        m_04.Assign(83, new CNB8E020);
    }
    {
        m_04.Assign(84, new CNB8E170);
    }
    {
        m_04.Assign(85, new CNB8E2C0);
    }
    {
        m_04.Assign(86, new CNB8E460);
    }
    {
        m_04.Assign(87, new CNB8E600);
    }
    {
        m_04.Assign(88, new CNB8E7A0);
    }
    {
        m_04.Assign(89, new CNB8E940);
    }
    {
        m_04.Assign(90, new CNB8EAE0);
    }
    {
        m_04.Assign(91, new CNB8EC80);
    }
    {
        m_04.Assign(93, new CNB932D0);
    }
    {
        m_04.Assign(94, new CNB93600);
    }
    {
        m_04.Assign(95, new CNB93950);
    }
    {
        m_04.Assign(96, new CNB93AA0);
    }
    {
        m_04.Assign(97, new CNB93BF0);
    }
    {
        m_04.Assign(98, new CNB93D40);
    }
    {
        m_04.Assign(99, new CNB93E90);
    }
    {
        m_04.Assign(100, new CNB93FE0);
    }
    {
        m_04.Assign(101, new CNB94130);
    }
    {
        m_04.Assign(102, new CNB94280);
    }
    {
        m_04.Assign(103, new CNB932D0);
    }
    {
        m_04.Assign(104, new CNB943D0);
    }
    {
        m_04.Assign(105, new CNB92690);
    }
    {
        m_04.Assign(106, new CNB927E0);
    }
    {
        m_04.Assign(107, new CNB92930);
    }
    {
        m_04.Assign(108, new CNB92A80);
    }
    {
        m_04.Assign(109, new CNB92BD0);
    }
    {
        m_04.Assign(110, new CNB92D90);
    }
    {
        m_04.Assign(111, new CNB92EE0);
    }
    {
        m_04.Assign(112, new CNB93030);
    }
    {
        m_04.Assign(113, new CNB93180);
    }
    {
        m_04.Assign(114, new CNB91CF0);
    }
    {
        m_04.SetAt(0x73, (ISSBase*)new CNB91E40);
    }
    {
        m_04.SetAt(0x4d, (ISSBase*)new CNB8C070);
    }
    for (unsigned int off = 34; off < 116; ++off)
    {
        if (m_04.r_04[off])
        {
            ShaderLayout* shader = static_cast<ShaderLayout*>(static_cast<ISSBase*>(m_04.r_04[off]));
            shader->Call120();
        }
    }
}

namespace nb {
struct Snd
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
    virtual void v1a(int type, int value, int a, int b);
};
struct Main
{
    char pad[0x8b8];
    Snd* m_8b8;
};
}
extern int DAT_011ffa8c;
extern int DAT_011ad888[];
// @fnv 0x00b97e80
void __cdecl FUN_00b97e80(int idx, int amount)
{
    int i = DAT_011ffa8c;
    if (!DAT_011ff9d8[i])
        ((nb::Main*)DAT_011f9508)->m_8b8->v1a(0x17, DAT_011ad888[idx], 0, 0);
    DAT_011ff9d8[i] += amount;
}

extern unsigned int DAT_011ffa6c;
// @fnv 0x00b97ed0
void __cdecl FUN_00b97ed0(unsigned char aByteValue, int aiDelta)
{
    unsigned int index = DAT_011ffa6c;
    if (DAT_011ff9d8[index] == 0)
    {
        GetDispatcher(DAT_011f9508)->Notify(0xf, aByteValue, 0, 0);
    }
    DAT_011ff9d8[index] += aiDelta;
}

namespace fnv_00b9af60 {
struct Bound_af60
{
    float x;
    float y;
    float z;
    float radius;
};
extern Bound_af60 DAT_011f4288;
struct Props_af60
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int m_1c;
    unsigned int m_20;
};
struct Geom_af60
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Bound_af60* m_20;
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
    Props_af60* m_a8;
    Bound_af60* GetBound()
    {
        return m_20 ? m_20 : &DAT_011f4288;
    }
};
struct Item_af60
{
    Geom_af60* m_00;
    unsigned short m_04;
};
struct Node1_af60
{
    Node1_af60* m_next;
    Node1_af60* m_pSecondNode;
    Item_af60* m_data;
};
struct NodeList1_af60
{
    Node1_af60* m_pFirstNode;
    Node1_af60* m_pTail;
    Node1_af60* m_free;
    int m_uiItemCount;
    void RemoveHead()
    {
        Node1_af60* n = m_pFirstNode;
        if (n)
        {
            if (n == m_pTail)
            {
                m_pTail = 0;
            }
            Node1_af60* next = 0;
            if (m_pFirstNode->m_next)
            {
                next = n->m_next;
                next->m_pSecondNode = 0;
            }
            if (m_free)
            {
                m_free->m_pSecondNode = m_pFirstNode;
            }
            m_pFirstNode->m_next = m_free;
            m_uiItemCount--;
            m_free = m_pFirstNode;
            m_pFirstNode = next;
        }
    }
};
struct List1_af60
{
    unsigned short unk00;
    unsigned short m_02;
    int unk04;
    int unk08;
    int unk0c;
    NodeList1_af60 m_kNode;
};
struct Sub2c_af60
{
    void FUN_00b64ec0();
};
struct Obj_af60
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
    virtual void SetState(int a, int b, int c);
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
    Sub2c_af60 m_2c;
};
struct Entry_af60
{
    unsigned char m_flags;
    unsigned char unk01;
    unsigned short m_02;
    int unk04;
    Obj_af60* m_08;
    int m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float m_20;
    void FUN_00b9a410();
};
struct Node2_af60
{
    Node2_af60* m_next;
    Node2_af60* m_pSecondNode;
    Entry_af60* m_data;
};
struct List2_af60
{
    Node2_af60* m_pFirstNode;
    Node2_af60* m_pTail;
    int m_uiItemCount;
    void RemoveHead();
};
struct Lock_af60
{
    int m_pOwnerObject;
    void Lock(int a);
};
struct Mgr_af60
{
    void FUN_00aa4060(Entry_af60* e);
};
struct Point3_af60
{
    float x;
    float y;
    float z;
    Point3_af60(float ax, float ay, float az) : x(ax), y(ay), z(az)
    {}
};
struct Cam_af60
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
    float m_68;
    int unk6c;
    int unk70;
    float m_74;
    int unk78;
    int unk7c;
    float m_80;
};
extern Lock_af60 DAT_011c5f80;
extern int DAT_011c5f84;
extern Node2_af60* DAT_011c5f58;
extern Mgr_af60 DAT_011f6238;
extern int DAT_011f91b8;
extern char DAT_011ad80f;
extern float DAT_01200458;
extern int DAT_011ff9dc;
extern int DAT_011ff9e4;
extern double DAT_01016978;
void __cdecl ClearPassList(int* p, int a);
void __cdecl FUN_00b97e30(int a, int b);
void __cdecl SendFloatAdd(float f, int a);
void __cdecl FUN_00b994f0(Item_af60* item, unsigned int a, int b, int c, int d);
extern "C" int __cdecl _isnan(double);
struct Renderer_af60
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
    List1_af60* m_70[2];
    List2_af60 m_78[2];
    void UpdateVisibility(int idx, Cam_af60* cam, bool flag, float maxDist);
};
inline void List2_af60::RemoveHead()
{
    Node2_af60* n = m_pFirstNode;
    m_pFirstNode = n->m_next;
    if (m_pFirstNode)
    {
        m_pFirstNode->m_pSecondNode = 0;
    }
    else
    {
        m_pTail = 0;
    }
    n->m_data = 0;
    DAT_011c5f80.Lock(0);
    n->m_pSecondNode = 0;
    n->m_next = DAT_011c5f58;
    DAT_011c5f84 -= 1;
    DAT_011c5f58 = n;
    if (DAT_011c5f84 == 0)
    {
        DAT_011c5f80.m_pOwnerObject = 0;
    }
    m_uiItemCount--;
}
static __forceinline float CalcDist(Item_af60* a, const Point3_af60& dir, bool flag)
{
    if (flag)
    {
        Bound_af60* b = a->m_00->GetBound();
        Bound_af60* b2 = a->m_00->GetBound();
        float d = b->x * dir.x + b->y * dir.y + b->z * dir.z;
        return d - b2->radius;
    }
    Bound_af60* b = a->m_00->GetBound();
    return b->x * dir.x + b->y * dir.y + b->z * dir.z;
}
// @fnv 0x00b9af60
void Renderer_af60::UpdateVisibility(int idx, Cam_af60* cam, bool abUseRadius, float maxDist)
{
    Point3_af60 dir(cam->m_68, cam->m_74, cam->m_80);
    List1_af60* pList = m_70[idx];
    Node1_af60* n = pList->m_kNode.m_pFirstNode;
    Item_af60* a = n ? n->m_data : 0;
    float dist = 0.0f;
    if (a)
    {
        dist = CalcDist(a, dir, abUseRadius);
    }
    Entry_af60* e = m_78[idx].m_uiItemCount ? m_78[idx].m_pFirstNode->m_data : 0;
    maxDist -= DAT_01016978;
    do
    {
        while (e && (e->m_20 > dist || !a) && e->m_20 >= maxDist)
        {
            if ((e->m_flags & 1) > 0)
            {
                ClearPassList(&e->m_0c, 1);
            }
            else if (e->m_08)
            {
                e->m_08->SetState(1, 0x2f1, 1);
            }
            if (e->m_08)
            {
                e->m_08->m_2c.FUN_00b64ec0();
            }
            e->m_02 = 0;
            e->FUN_00b9a410();
            DAT_011f6238.FUN_00aa4060(e);
            m_78[idx].RemoveHead();
            e = m_78[idx].m_uiItemCount ? m_78[idx].m_pFirstNode->m_data : 0;
        }
        if (a && dist >= maxDist)
        {
            Props_af60* p = a->m_00->m_a8;
            if (p && !(DAT_011f91b8 == 9 && (p->m_1c == 0x15 || p->m_1c == 0x11)))
            {
                bool restore;
                if ((p->m_20 & 0x4000000) > 0 || (p->m_20 & 0x8000000) > 0)
                {
                    float f = DAT_01200458;
                    restore = true;
                    if (!DAT_011ad80f)
                    {
                        f = 0.0f;
                    }
                    FUN_00b97e30(0, 1);
                    SendFloatAdd(f, 1);
                }
                else
                {
                    restore = false;
                }
                FUN_00b994f0(a, a->m_04, 1, 1, 1);
                if (restore)
                {
                    DAT_011ff9dc -= 1;
                    FUN_00b97e30(1, 0);
                    DAT_011ff9e4 -= 1;
                    SendFloatAdd(0.0f, 0);
                }
            }
            List1_af60* l = m_70[idx];
            if (l->m_kNode.m_pFirstNode)
            {
                l->m_02--;
                l->m_kNode.RemoveHead();
            }
            l = m_70[idx];
            Node1_af60* node = l->m_kNode.m_pFirstNode;
            a = node ? node->m_data : 0;
            if (a)
            {
                dist = CalcDist(a, dir, abUseRadius);
            }
        }
    } while (((a && dist >= maxDist) || (e && e->m_20 >= maxDist)) && !_isnan(dist));
}
}  // namespace fnv_00b9af60

class NiPoint3
{
  public:
    float x, y, z;

    inline float operator*(const NiPoint3& pt) const
    {
        return x * pt.x + y * pt.y + z * pt.z;
    }
};

class NiPlane
{
  public:
    NiPoint3 m_kPlaneNormal;
    float m_fPlaneConstant;

    inline float Distance(const NiPoint3& kPoint) const
    {
        return m_kPlaneNormal * kPoint - m_fPlaneConstant;
    }
};

class NiFrustumPlanes
{
  public:
    NiPlane m_akPlanes[6];
    unsigned int m_uiActivePlaneMask;

    inline bool IsPlaneActive(unsigned int ePlane) const
    {
        return (m_uiActivePlaneMask & (1u << ePlane)) ? true : false;
    }
    inline void DisablePlane(unsigned int ePlane)
    {
        m_uiActivePlaneMask = m_uiActivePlaneMask & ~(1u << ePlane);
    }
    inline const NiPlane& GetPlane(unsigned int ePlane) const
    {
        return m_akPlanes[ePlane];
    }
};

struct NiSphere
{
    NiPoint3 m_kCenter;
    float m_fBoundRadius;
};

class ShadowSceneLight
{
  public:
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
    NiFrustumPlanes m_kFrustumPlanes;

    bool TestSphereFrustum(const NiSphere& kSphere);
};

// @fnv 0x00b9bbb0
bool ShadowSceneLight::TestSphereFrustum(const NiSphere& kSphere)
{
    bool bInside = true;
    for (unsigned int i = 0; i < 6; i++)
    {
        if (m_kFrustumPlanes.IsPlaneActive(i))
        {
            float fDist = m_kFrustumPlanes.GetPlane(i).Distance(kSphere.m_kCenter);
            if (fDist <= -kSphere.m_fBoundRadius)
            {
                bInside = false;
                break;
            }
            if (kSphere.m_fBoundRadius <= fDist)
                m_kFrustumPlanes.DisablePlane(i);
        }
    }
    return bInside;
}

struct Size
{
    unsigned int n;
};
void __cdecl UpdateInputFlags(Size, int);

struct WaterBits
{
    int idx;
};
extern "C" int UpdateInputFlags(WaterBits, int);

struct FunB815E0Arg
{
    int v;
    FunB815E0Arg(int v_) : v(v_)
    {}
};

void __cdecl UpdateInputFlags(FunB815E0Arg arg, int flags);

struct FUN_00b815e0_a0_t
{
    int v;
};
int __cdecl UpdateInputFlags(FUN_00b815e0_a0_t, int);

struct Wrap13
{
    int v;
};

void __cdecl UpdateInputFlags(Wrap13 w, int zero);

struct W36
{
    int v;
};
int __cdecl UpdateInputFlags(W36 w, int flag);

namespace fnv_00b8202e {
struct W1
{
    int v;
};
extern "C" void __cdecl UpdateInputFlags(W1 w, int param);
}  // namespace fnv_00b8202e

void __cdecl UpdateInputFlags(Size, int);

namespace fnv_00b82054 {
struct IndexW
{
    int v;
    IndexW(int v_) : v(v_)
    {}
};

extern "C" void __cdecl UpdateInputFlags(IndexW index, int flag);

}  // namespace fnv_00b82054

namespace fnv_00b82067 {
struct W82067
{
    int v;
};

extern "C" void __cdecl UpdateInputFlags(W82067 w, int index);

}  // namespace fnv_00b82067

void __cdecl UpdateInputFlags(Size, int);

struct W8208d
{
    int v;
    W8208d(int v_) : v(v_)
    {}
};
void __cdecl UpdateInputFlags(W8208d w, int value);

namespace fnv_00b820ec {
struct S42
{
    int v;
    S42(int v_) : v(v_)
    {}
};
extern "C" void __cdecl UpdateInputFlags(S42 a, int b);
}  // namespace fnv_00b820ec

struct W1b82125
{
    int v;
};
int __cdecl UpdateInputFlags(W1b82125 a, int b);

struct P
{
    int v;
};
void __cdecl UpdateInputFlags(P p, int b);

namespace fnv_00b8215e {
struct IndexW44
{
    unsigned int v;
    IndexW44(unsigned int value) : v(value)
    {}
};
extern "C" void __cdecl UpdateInputFlags(IndexW44 index, int flag);
}  // namespace fnv_00b8215e

namespace fnv_00b82171 {
struct W82171
{
    int v;
};

extern "C" void __cdecl UpdateInputFlags(W82171 w, int index);

}  // namespace fnv_00b82171

namespace fnv_00b821aa {
struct W
{
    int v;
};
extern "C" void __cdecl UpdateInputFlags(W w, int extra);
}  // namespace fnv_00b821aa

struct WaterIndexWrap
{
    int index;
};

void __cdecl UpdateInputFlags(WaterIndexWrap w, int flag);

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
struct RefObj
{
    virtual ~RefObj();
    virtual void DeleteThis();
    long m_ref;
    void DecRef()
    {
        if (InterlockedDecrement(&m_ref) == 0)
            DeleteThis();
    }
};
struct RPtr
{
    RefObj* m_p;
    void Clear()
    {
        if (m_p)
        {
            m_p->DecRef();
            m_p = 0;
        }
    }
};
struct Tex
{
    int unk00[0x19];
    int m_64;
    void FUN_00e80190();
    void DecRef()
    {
        if (--m_64 == 0)
            FUN_00e80190();
    }
};
struct TPtr
{
    Tex* m_p;
    void Clear()
    {
        if (m_p)
        {
            m_p->DecRef();
            m_p = 0;
        }
    }
};
struct Vector4f
{
    int a, b, c, d;
};
extern Vector4f g_kQuad;
extern RPtr g_aPtrA[3];
extern RPtr g_aPtrB[6];
extern Vector4f g_aQuadA[11];
extern Vector4f g_aQuadB[31];
struct Owner
{
    int unk00[0x1b];
    TPtr m_aTex[0x4a];
    RPtr m_194, m_198, m_19c;
    RPtr m_aPtr[0x26];
    bool FUN_00be0870();
    bool FUN_00b861d0();
};
// Calls FUN_00be0870, clears all RPtr and TPtr members and global arrays, resets quad vectors to g_kQuad, and returns the result.
// @fnv 0x00b861d0
bool Owner::FUN_00b861d0()
{
    bool r = FUN_00be0870();
    m_194.Clear();
    m_198.Clear();
    m_19c.Clear();
    for (int i = 0; i < 0x4a; i++)
        m_aTex[i].Clear();
    for (int i = 0; i < 0x26; i++)
        m_aPtr[i].Clear();
    for (int i = 0; i < 3; i++)
        g_aPtrA[i].Clear();
    for (int i = 0; i < 6; i++)
        g_aPtrB[i].Clear();
    for (int i = 0; i < 11; i++)
        g_aQuadA[i] = g_kQuad;
    for (int i = 0; i < 31; i++)
        g_aQuadB[i] = g_kQuad;
    return r;
}

struct FUN_00e80190_Class
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
    void __thiscall FUN_00e80190();
};

struct Self_b89970
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
    FUN_00e80190_Class* unk6c;
    char FUN_00be0870();
    char FUN_00b89970();
};

// Calls FUN_00be0870, then if unk6c is set decrements its unk64 (calling FUN_00e80190 at zero) and clears unk6c; returns the FUN_00be0870 result.
// @fnv 0x00b89970
char Self_b89970::FUN_00b89970()
{
    char result = FUN_00be0870();
    FUN_00e80190_Class* p = unk6c;
    if (p)
    {
        if (--p->unk64 == 0)
            p->FUN_00e80190();
        unk6c = 0;
    }
    return result;
}

extern __declspec(thread) unsigned int t_uiMemContextB979;
inline unsigned int GetMemContextB979()
{
    return t_uiMemContextB979;
}
inline void SetMemContextB979(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContextB979 = m_uiGeometryShaderFlags;
}
class AutoMemContextB979
{
  public:
    AutoMemContextB979(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContextB979();
        SetMemContextB979(m_uiGeometryShaderFlags);
    }
    ~AutoMemContextB979()
    {
        SetMemContextB979(m_uiPrevious);
    }
    unsigned int m_uiPrevious;
};
struct RenderTargetB979;
struct RendererB979;
class ImageSpaceEffectB979
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual bool IsActive();
};
struct RenderTargetManagerB979
{
    RenderTargetB979* GetRenderTarget(RendererB979* pkRenderer, int eType, int iA, int iB, int iC);
    void ReleaseRenderTarget(RenderTargetB979* pkTarget);
};
extern RenderTargetManagerB979* g_pkRenderTargetManagerB979;
class ImageSpaceManagerB979
{
  public:
    void PrepareEndOfFrameEffects();
    void RenderEffect(int iEffect, RendererB979* pkRenderer, RenderTargetB979* pkSource, RenderTargetB979* pkDest,
                      int iFlags, bool bEndFrame);
    void RenderEndOfFrameEffects(RendererB979* pkRenderer, RenderTargetB979** ppkSource, RenderTargetB979** ppkDest);
    RenderTargetB979* m_pkCurrentTarget;
    int unk004;
    ImageSpaceEffectB979** m_ppkEffects;
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
    int m_iNumActiveEffects;
    int m_iLastEffect;
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
    RenderTargetB979* m_pkSwapTarget;
};

// Prepares end-of-frame effects, then iterates active effects to render them, swapping source and destination render targets between passes.
// @fnv 0x00b97900
void ImageSpaceManagerB979::RenderEndOfFrameEffects(RendererB979* pkRenderer, RenderTargetB979** ppkSource,
                                                    RenderTargetB979** ppkDest)
{
    AutoMemContextB979 kContext(39);
    PrepareEndOfFrameEffects();
    m_pkCurrentTarget = *ppkDest;
    if (m_iLastEffect != -1)
    {
        RenderTargetB979* pkSource = *ppkSource;
        RenderTargetB979* pkTemp = 0;
        RenderTargetB979* pkDest;
        if (m_iNumActiveEffects == 1)
            pkDest = *ppkDest;
        else
        {
            pkDest = m_pkSwapTarget;
            if (m_iNumActiveEffects > 2)
                pkTemp = g_pkRenderTargetManagerB979->GetRenderTarget(pkRenderer, 3, 0, 0, 0);
        }
        int iRendered = 0;
        for (int i = 0; i <= m_iLastEffect; i++)
        {
            if (iRendered == 1 && pkTemp)
                pkDest = pkTemp;
            if (i == m_iLastEffect)
                pkDest = *ppkDest;
            ImageSpaceEffectB979* pkEffect = m_ppkEffects[i];
            if (pkEffect && pkEffect->IsActive())
            {
                RenderEffect(i, pkRenderer, pkSource, pkDest, 0, true);
                iRendered++;
                RenderTargetB979* pkSwap = pkSource;
                pkSource = pkDest;
                pkDest = pkSwap;
            }
        }
        if (pkTemp)
            g_pkRenderTargetManagerB979->ReleaseRenderTarget(pkTemp);
    }
    else
        RenderEffect(34, pkRenderer, *ppkSource, *ppkDest, 0, true);
}

// @fnv 0x00b988a0
int __cdecl CompareShorts(unsigned short a, unsigned short b)
{
    return a < b ? -1 : 1;
}

extern float DAT_011f9410;

struct B9B400Cls
{
    int m_000;
    __declspec(noinline) void FUN_00b9b400(unsigned int v);
};

void B9B400Cls::FUN_00b9b400(unsigned int v)
{
    m_000 = (int)v;
}

struct FUN_00b9b7f0_cls
{
    int m_000;
    int m_004;
    int m_008;
    int m_00c;
    int m_010;
    int m_014;
    int m_018;
    int m_01c;
    int m_020;
    int m_024;
    int m_028;
    int m_02c;
    int m_030;
    int m_034;
    int m_038;
    int m_03c;
    int m_040;
    int m_044;
    int m_048;
    int m_04c;
    int m_050;
    int m_054;
    int m_058;
    int m_05c;
    int m_060;
    int m_064;
    int m_068;
    int m_06c;
    int m_070;
    int m_074;
    int m_078;
    int m_07c;
    int m_080;
    int m_084;
    int m_088;
    int m_08c;
    int m_090;
    int m_094;
    int m_098;
    int m_09c;
    int m_0a0;
    int m_0a4;
    int m_0a8;
    int m_0ac;
    int m_0b0;
    int m_0b4;
    int m_0b8;
    int m_0bc;
    int m_0c0;
    int m_0c4;
    int m_0c8;
    int m_0cc;
    int m_0d0;
    int m_0d4;
    int m_0d8;
    int m_0dc;
    int m_0e0;
    int m_0e4;
    int m_0e8;
    int m_0ec;
    int m_0f0;
    int m_0f4;
    int m_0f8;
    int m_0fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    int m_140;
    int m_144;
    int m_148;
    int m_14c;
    int m_150;
    int m_154;
    int m_158;
    int m_15c;
    int m_160;
    int m_164;
    int m_168;
    int m_16c;
    int m_170;
    int m_174;
    int m_178;
    int m_17c;
    int m_180;
    int m_184;
    int m_188;
    int m_18c;
    int m_190;
    int m_194;
    int m_198;
    int m_19c;
    int m_1a0;
    int m_1a4;
    int m_1a8;
    int m_1ac;
    int m_1b0;
    int m_1b4;
    int m_1b8;
    int m_1bc;
    int m_1c0;
    int m_1c4;
    int m_1c8;
    int m_1cc;
    int m_1d0;
    int m_1d4;
    int m_1d8;
    int m_1dc;
    int m_1e0;
    int m_1e4;
    int m_1e8;
    int m_1ec;
    int m_1f0;
    int m_1f4;
    int m_1f8;
    int m_1fc;
    int m_200;
    int m_204;
    int m_208;
    int m_20c;
    int m_210;
    int m_214;
    int m_218;
    int m_21c;
    int m_220;
    int m_224;
    int m_228;
    int m_22c;
    int m_230;
    int m_234;
    int m_238;
    int m_23c;
    int m_240;
    int m_244;
    int m_248;
    int m_24c;
    int m_250;
    int m_254;
    int m_258;
    int m_25c;
    int m_260;
    int m_264;
    int m_268;
    int m_26c;
    int m_270;
    int m_274;
    int m_278;
    int m_27c;
    int m_280;
    int m_284;
    int m_288;
    int m_28c;
    int m_290;
    int m_294;
    int m_298;
    int m_29c;
    int m_2a0;
    int m_2a4;
    int m_2a8;
    int m_2ac;
    int m_2b0;
    int m_2b4;
    unsigned char m_2b8;
    void FUN_00b9b7f0();
};

// Calls FUN_00b9b400 on this with DAT_011f9410 and sets m_2b8 to 1.
// @fnv 0x00b9b7f0
void FUN_00b9b7f0_cls::FUN_00b9b7f0()
{
    ((B9B400Cls*)this)->FUN_00b9b400((unsigned int)DAT_011f9410);
    m_2b8 = 1;
}

extern float DAT_011f9410;

struct FX
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
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
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
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
    int m_f8;
    int m_fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    int m_140;
    int m_144;
    int m_148;
    int m_14c;
    int m_150;
    int m_154;
    int m_158;
    int m_15c;
    int m_160;
    int m_164;
    int m_168;
    int m_16c;
    int m_170;
    int m_174;
    int m_178;
    int m_17c;
    int m_180;
    int m_184;
    int m_188;
    int m_18c;
    int m_190;
    int m_194;
    int m_198;
    int m_19c;
    int m_1a0;
    int m_1a4;
    int m_1a8;
    int m_1ac;
    int m_1b0;
    int m_1b4;
    int m_1b8;
    int m_1bc;
    int m_1c0;
    int m_1c4;
    int m_1c8;
    int m_1cc;
    int m_1d0;
    int m_1d4;
    int m_1d8;
    int m_1dc;
    int m_1e0;
    int m_1e4;
    int m_1e8;
    int m_1ec;
    int m_1f0;
    int m_1f4;
    int m_1f8;
    int m_1fc;
    int m_200;
    int m_204;
    int m_208;
    int m_20c;
    int m_210;
    int m_214;
    int m_218;
    int m_21c;
    int m_220;
    int m_224;
    int m_228;
    int m_22c;
    int m_230;
    int m_234;
    int m_238;
    int m_23c;
    int m_240;
    int m_244;
    int m_248;
    int m_24c;
    int m_250;
    int m_254;
    int m_258;
    int m_25c;
    int m_260;
    int m_264;
    int m_268;
    int m_26c;
    int m_270;
    int m_274;
    int m_278;
    int m_27c;
    int m_280;
    int m_284;
    int m_288;
    int m_28c;
    int m_290;
    int m_294;
    int m_298;
    int m_29c;
    int m_2a0;
    int m_2a4;
    int m_2a8;
    int m_2ac;
    int m_2b0;
    int m_2b4;
    bool m_2b8;
    bool __thiscall EnsureInitialized(int unused);
    void __thiscall FUN_00b9b400(unsigned int value);
};

__declspec(noinline) void FX::FUN_00b9b400(unsigned int value)
{
    m_iWordAt00 = (int)value;
}

// If m_2b8 is false, calls FUN_00b9b400 with DAT_011f9410 and sets m_2b8 to true, then returns true.
// @fnv 0x00b9bac0
bool FX::EnsureInitialized(int unused)
{
    if (!m_2b8)
    {
        FUN_00b9b400((unsigned int)DAT_011f9410);
        m_2b8 = true;
    }
    return true;
}

struct ReleaseObject
{
    virtual void v00();
    virtual void v04();
    int m_iObjectReferenceCount;
};

struct FUN_0045cec0
{
    ReleaseObject* m_pObject;
    ~FUN_0045cec0();
};

struct FUN_00baa0e0
{
    virtual void v00();
    ~FUN_00baa0e0();
};

struct FUN_00b81130 : public FUN_00baa0e0
{
    virtual void v01();
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
    FUN_0045cec0 m_60[2];
    ~FUN_00b81130();
};

// Releases the two ReleaseObject slots by decrementing their reference counts and calling v04 when the count reaches zero.
// @fnv 0x00b81130
FUN_00b81130::~FUN_00b81130()
{
    ReleaseObject** slot = &m_60[0].m_pObject;
    for (int n = 2; n != 0; n--)
    {
        ReleaseObject* p = *slot;
        if (p != 0)
        {
            if (InterlockedDecrement((volatile long*)&p->m_iObjectReferenceCount) == 0)
            {
                p->v04();
            }
            *slot = 0;
        }
        slot++;
    }
}

struct S00b81f70_Key
{
    int m_iValue;
};

int __cdecl UpdateInputFlags(S00b81f70_Key kKey, int iFlags);

extern void __cdecl UpdateInputFlags(struct SCount a1, int a2);

struct SCount
{
    int v;
};

struct S00b8201b_Key
{
    int m_iValue;
};

int __cdecl UpdateInputFlags(S00b8201b_Key kKey, int iFlags);

namespace fnv_00b820a0 {
struct FUN_00b815e0_arg
{
    int index;
};

extern "C" void __cdecl UpdateInputFlags(FUN_00b815e0_arg arg, int extra);

}  // namespace fnv_00b820a0

struct W82197
{
    unsigned int n;
};
void __cdecl UpdateInputFlags(W82197, int);

extern "C" void __stdcall FUN_00ec5fce(void* apBase, unsigned int aiSize, unsigned int aiCount, void* apDtor);
void __cdecl FUN_00aa10f0(void* apMemory);
extern "C" void FUN_0045cec0();

struct AllocFree_b9960 : AllocSvc
{
    void FUN_00aa4060(void* apMemory);
};
static inline AllocFree_b9960& GetAllocFree()
{
    return static_cast<AllocFree_b9960&>(DAT_011f6238);
}

class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct Elem_b11320
{
    int unk00;
    ~Elem_b11320();
    static void operator delete[](void* p)
    {
        GetAllocFree().FUN_00aa4060(p);
    }
};
struct Sub58_b9960
{
    virtual ~Sub58_b9960()
    {
        delete[] m_04;
    }
    Elem_b11320* m_04;
    int unk08;
    int unk0C;
};

struct Sub68_b9960
{
    virtual ~Sub68_b9960()
    {
        FUN_00aa10f0(m_04);
    }
    void* m_04;
    int unk08;
    int unk0C;
};

struct Sub78_b9960
{
    int unk00;
    int unk04;
    ~Sub78_b9960();
};

class FUN_00b8a8e0_base
{
  public:
    virtual ~FUN_00b8a8e0_base();
    int unk04;
};

class FUN_00b8a8e0 : public FUN_00b8a8e0_base
{
  public:
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
    NiPointer<NiRefObject> m_4c;
    NiPointer<NiRefObject> m_50;
    int unk54;
    Sub58_b9960 m_58;
    Sub68_b9960 m_68;
    Sub78_b9960 m_78;

    virtual ~FUN_00b8a8e0();
    void Cleanup();
};

// Destructor that calls Cleanup; the member and base destructors then run implicitly.
// @fnv 0x00b8a8e0
FUN_00b8a8e0::~FUN_00b8a8e0()
{
    Cleanup();
}

class WaterFFTDisplayEffect : public B8F080ImageSpaceEffect
{
  public:
    void FUN_00b941a0();
};

// Creates vertex and pixel shaders for the FFT display high-water effect and calls SetupShaders.
// @fnv 0x00b941a0
void WaterFFTDisplayEffect::FUN_00b941a0()
{
    B8F080ShaderFile kVertexDelta = {"imagespace\\1x\\v\\base.v.hlsl", {{NULL, NULL}}};
    B8F080ShaderFile kPixel = {"water\\2_ab\\p\\waterhmap.p.hlsl", {{"DISPLAY_HIGHW", NULL}, {NULL, NULL}}};
    const char* pcPS = (const char*)FUN_00b4f380(1);
    CreateShaders(&kVertexDelta, &kPixel, "FFTDISPLAYHIGHW", "vs_1_1", pcPS);
    SetupShaders();
}

struct EffectManager975
{
    int unk00;
    int unk04;
    ImageSpaceEffectB979** effects;
    void FUN_00b8c980(ImageSpaceEffectB979*, int, int, int, int, int);
    void FUN_00b975f0(unsigned int index, int a, int b, int c, int d, int e);
};

// Calls FUN_00b8c980 with effects[index] and the five int arguments while a memory context of 0x27 is set.
// @fnv 0x00b975f0
void EffectManager975::FUN_00b975f0(unsigned int uiEffectIndex, int a, int b, int c, int d, int e)
{
    ScopedMemoryContext context(0x27);
    FUN_00b8c980(effects[uiEffectIndex], a, b, c, d, e);
}

void NiFree(void* memory);

extern "C" int DAT_010b9d24;

extern "C" int DAT_01202410;
extern "C" void __fastcall FUN_00b8a7e0(void*);
struct Manager97690
{
    void FUN_00b6da10(unsigned int);
};
extern Manager97690* DAT_011f91a8;

struct TextureArray97690
{
    void** vtbl;
    void** pBase;
    unsigned short usMaxSize;
    unsigned short usSize;
    unsigned short usESize;
    unsigned short usGrowBy;
    ~TextureArray97690()
    {
        vtbl = (void**)&DAT_010b9d24;
        NiFree(pBase);
    }
};

struct FUN_00b97690
{
    int m_vtbl00;
    TextureArray97690 m_textures;
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
    bool active;
    char unk1e5;
    char unk1e6;
    char unk1e7;
    char unk1e8;
    char unk1e9;
    char unk1ea;
    char unk1eb;
    char unk1ec;
    char unk1ed;
    char unk1ee;
    char unk1ef;
    NiPointer<B8C690Texture> ref1f0;
    NiPointer<B8C690Texture> ref1f4;
    NiPointer<B8C690Texture> ref1f8;
    int unk1fc;
    NiPointer<B8C690Texture> ref200;
    ImageSpaceTexture m_texture;
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
    unsigned int m_textureId;
    void ShutdownAllEffects();
    void ClearTextures();
    ~FUN_00b97690();
};
// If active, calls ShutdownAllEffects, ClearTextures and FUN_00b8a7e0, clears active, and passes m_textureId to DAT_011f91a8->FUN_00b6da10.
// @fnv 0x00b97690
FUN_00b97690::~FUN_00b97690()
{
    if (active)
    {
        ShutdownAllEffects();
        ClearTextures();
        FUN_00b8a7e0(&DAT_01202410);
        active = false;
        DAT_011f91a8->FUN_00b6da10(m_textureId);
    }
}

#include <math.h>
class B9DBE0Point3
{
  public:
    B9DBE0Point3 operator+(const B9DBE0Point3& kPt) const
    {
        B9DBE0Point3 kResult;
        kResult.x = x + kPt.x;
        kResult.y = y + kPt.y;
        kResult.z = z + kPt.z;
        return kResult;
    }
    B9DBE0Point3 operator-(const B9DBE0Point3& kPt) const
    {
        B9DBE0Point3 kResult;
        kResult.x = x - kPt.x;
        kResult.y = y - kPt.y;
        kResult.z = z - kPt.z;
        return kResult;
    }
    float Length() const
    {
        return (float)sqrt(x * x + y * y + z * z);
    }

    float x;
    float y;
    float z;
};

struct B9DBE0Bound
{
    B9DBE0Point3 m_kCenter;
    float m_fBoundRadius;
};

struct B9DBE0Camera
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
    B9DBE0Point3 m_kWorldPos;
};

extern B9DBE0Camera* DAT_011f91c8;

struct B9DBE0Params
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
    B9DBE0Point3 m_kOffset;
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
    float m_fFadeRange;
};

class B9DBE0Fader
{
  public:
    int unk00;
    int unk04;
    int unk08;
    float m_fFade;
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
    B9DBE0Params* m_pkParams;

    float ComputeFade(const B9DBE0Bound* pkBound);
};

// Stores in m_fFade the distance from the camera position plus offset to the bound center, minus the bound radius, divided by the fade range, and returns it.
// @fnv 0x00b9dbe0
float B9DBE0Fader::ComputeFade(const B9DBE0Bound* pkBound)
{
    B9DBE0Point3 kCameraPos = DAT_011f91c8->m_kWorldPos;
    B9DBE0Params* pkParams = m_pkParams;
    B9DBE0Point3 kPos = pkParams->m_kOffset + kCameraPos;
    B9DBE0Point3 kDiff = kPos - pkBound->m_kCenter;
    float fDist = kDiff.Length();
    m_fFade = (fDist - pkBound->m_fBoundRadius) / pkParams->m_fFadeRange;
    return m_fFade;
}

// sub ecx,0x6c; jmp target: MSVC adjustor thunk for the secondary base (PrimaryBase is 0x6c bytes).
struct PrimaryBase
{
    virtual void FUN_00b8d430();
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
};

struct SecondaryBase
{
    virtual void FUN_00b8d430();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b8d430
    virtual void FUN_00b8d430();
};

Derived::Derived()
{}

namespace fnv_00b8d6f0 {
// sub ecx,0x6c; jmp target  ==  MSVC adjustor thunk.
// PrimaryBase = vptr + 26 int fields = 4 + 26*4 = 0x6c bytes.
struct PrimaryBase
{
    virtual void FUN_00b8d6f0();
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
};

struct SecondaryBase
{
    virtual void FUN_00b8d6f0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b8d6f0
    virtual void FUN_00b8d6f0();
};

Derived::Derived()
{}
}  // namespace fnv_00b8d6f0

namespace fnv_00b8d840 {
// The original function is an MSVC this-adjusting thunk: it moves `this` back by the size
// of the first base (0x6c) and tail-jumps to the implementation of the virtual function
// declared in the second base.  The compiler emits such a thunk for the second base's
// vtable slot when the derived class inherits the same virtual from both bases.
struct PrimaryBase
{
    virtual void FUN_00b8d840();
    int unk04;
    int unk08[25];
};

struct SecondaryBase
{
    virtual void FUN_00b8d840();
};

struct Derived : public PrimaryBase, public SecondaryBase
{
    Derived();
// @fnv 0x00b8d840
    virtual void FUN_00b8d840();
};

Derived::Derived()
{}
}  // namespace fnv_00b8d840

namespace fnv_00b8d980 {
// Adjustor thunk for FUN_00b8d980: "sub ecx, 0x6c; jmp FUN_00b8d950".
//
// This is the MSVC "this adjusting thunk" that MSVC emits for a virtual
// function that a class inherits from a secondary base: the thunk converts the
// secondary base sub-object pointer (this + 0x6c) back into the derived
// object pointer (sub ecx, 0x6c) and then tail jumps to the final overrider.
//
// The offset that is subtracted is the size of the primary base, so the
// primary base is laid out as a vtable pointer plus 26 int members
// (4 + 26 * 4 = 0x6c bytes).  Both bases declare the same virtual function,
// the derived class redeclares it and only defines its constructor, which is
// what makes the compiler emit the vtables and the adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_00b8d980();
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
};

struct SecondaryBase
{
    virtual void FUN_00b8d980();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b8d980
    virtual void FUN_00b8d980();
};

Derived::Derived()
{}
}  // namespace fnv_00b8d980

// FUN_00b8dad0 : MSVC this-adjusting thunk  (sub ecx, 0x6c ; jmp <impl>)
struct A1_00b8dad0
{
    A1_00b8dad0();
    virtual void FUN_00b8dad0();
    char pad[0x68];
};
struct A2_00b8dad0
{
    A2_00b8dad0();
    virtual void FUN_00b8dad0();
};
struct Own_00b8dad0 : A1_00b8dad0, A2_00b8dad0
{
    Own_00b8dad0();
    virtual void key_fn();
// @fnv 0x00b8dad0
    void FUN_00b8dad0();
};
Own_00b8dad0::Own_00b8dad0()
{}
void Own_00b8dad0::key_fn()
{}
Own_00b8dad0* make_00b8dad0()
{
    static Own_00b8dad0 o;
    return &o;
}

namespace fnv_00b8dc20 {
// MSVC adjustor thunk: the primary base occupies 0x6c bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_00b8dc20();
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
};

struct SecondaryBase
{
    virtual void FUN_00b8dc20();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b8dc20
    virtual void FUN_00b8dc20();
};

Derived::Derived()
{}
}  // namespace fnv_00b8dc20

// FUN_00b8dd70 : MSVC this-adjusting thunk  (sub ecx, 0x6c ; jmp <impl>)
struct A1_00b8dd70
{
    A1_00b8dd70();
    virtual void FUN_00b8dd70();
    char pad[0x68];
};
struct A2_00b8dd70
{
    A2_00b8dd70();
    virtual void FUN_00b8dd70();
};
struct Own_00b8dd70 : A1_00b8dd70, A2_00b8dd70
{
    Own_00b8dd70();
    virtual void key_fn();
// @fnv 0x00b8dd70
    void FUN_00b8dd70();
};
Own_00b8dd70::Own_00b8dd70()
{}
void Own_00b8dd70::key_fn()
{}
Own_00b8dd70* make_00b8dd70()
{
    static Own_00b8dd70 o;
    return &o;
}

// Adjustor thunk for FUN_00b8dec0: "sub ecx, 0x6c; jmp FUN_00b8de90".
//
// This is the MSVC "this adjusting thunk" that the compiler emits for a
// virtual function which a derived class overrides and which also exists in
// the derived class' secondary base: the thunk moves the secondary-base
// sub-object pointer back to the derived object pointer (sub ecx, 0x6c) and
// tail jumps to the final overrider.
//
// The subtracted offset is the size of the primary base, so the primary base
// is laid out as a vtable pointer plus 26 int members (4 + 26 * 4 = 0x6c).
// Both bases declare the same virtual function; the derived class redeclares
// it and defines only its constructor, which is what makes the compiler emit
// the vtables and the adjusting thunk. The virtual stays undefined, so the
// thunk's jump is a relocation to an external symbol.
struct ThunkPrimaryBase
{
    virtual void FUN_00b8dec0();
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
};

struct ThunkSecondaryBase
{
    virtual void FUN_00b8dec0();
};

struct ThunkDerived : ThunkPrimaryBase, ThunkSecondaryBase
{
    ThunkDerived();
// @fnv 0x00b8dec0
    virtual void FUN_00b8dec0();
};

ThunkDerived::ThunkDerived()
{}

namespace fnv_00b8e010 {
// sub ecx,0x6c; jmp target == MSVC adjustor thunk: Derived overrides a virtual shared by two bases;
// the second base's vtable entry moves this back by sizeof(PrimaryBase) = 0x6c.
struct PrimaryBase
{
    virtual void FUN_00b8e010();
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
};

struct SecondaryBase
{
    virtual void FUN_00b8e010();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b8e010
    virtual void FUN_00b8e010();
};

Derived::Derived()
{}
}  // namespace fnv_00b8e010

namespace fnv_00b8e160 {
// Adjustor thunk for FUN_00b8e160: "sub ecx, 0x6c; jmp FUN_00b8e130".
//
// MSVC "this adjusting thunk": the derived class inherits a virtual function
// from a secondary base, so the thunk converts the secondary base sub-object
// pointer back to the derived object pointer (sub ecx, 0x6c) and tail jumps
// to the final overrider.  The subtracted offset is the size of the primary
// base: vtable pointer plus 26 int members (4 + 26*4 = 0x6c).
struct PrimaryBase
{
    virtual void FUN_00b8e160();
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
};

struct SecondaryBase
{
    virtual void FUN_00b8e160();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b8e160
    virtual void FUN_00b8e160();
};

Derived::Derived()
{}
}  // namespace fnv_00b8e160

// Adjustor thunk: the secondary-base (+0x6c) vtable entry for an override defined on the derived class.

class B8E2B0Primary
{
  public:
    virtual void* FUN_00b8e2b0(bool bFree);
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
};

class B8E2B0Secondary
{
  public:
    virtual void* FUN_00b8e2b0(bool bFree);
};

class B8E2B0Shader : public B8E2B0Primary, public B8E2B0Secondary
{
  public:
    B8E2B0Shader();
// @fnv 0x00b8e2b0
    virtual void* FUN_00b8e2b0(bool bFree);
};

B8E2B0Shader::B8E2B0Shader()
{}

namespace fnv_00b8ee10 {
struct Base1
{
    virtual void FUN_00b8ee10();
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
};
struct Base2
{
    virtual void FUN_00b8ee10();
};
struct Derived : Base1, Base2
{
    Derived();
// @fnv 0x00b8ee10
    virtual void FUN_00b8ee10();
};
Derived::Derived()
{}
}  // namespace fnv_00b8ee10

namespace fnv_00b8ef90 {
// FUN_00b8ef90: 8-byte thiscall adjustor thunk ("sub ecx,0x6c; jmp FUN_00b8ef60").
// MSVC emits it for a class that derives from two bases: the primary base occupies
// 0x6c bytes (vtable pointer + 26 int members), the secondary base declares the
// same virtual, and the derived class redeclares that virtual without defining
// it, so the secondary base's vtable slot points at this thunk.
struct PrimaryBase
{
    virtual void FUN_00b8ef90();
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
};

struct SecondaryBase
{
    virtual void FUN_00b8ef90();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b8ef90
    virtual void FUN_00b8ef90();
};

Derived::Derived()
{}
}  // namespace fnv_00b8ef90

namespace fnv_00b8f2e0 {
// MSVC adjustor thunk: the primary base occupies 0x6c bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_00b8f2e0();
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
};

struct SecondaryBase
{
    virtual void FUN_00b8f2e0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b8f2e0
    virtual void FUN_00b8f2e0();
};

Derived::Derived()
{}
}  // namespace fnv_00b8f2e0

namespace fnv_00b8f4a0 {
// Adjustor thunk for FUN_00b8f4a0: "sub ecx, 0x6c; jmp FUN_00b8f470".
//
// This is the MSVC "this adjusting thunk" emitted for a virtual function that a
// class inherits from a secondary base: the thunk moves the secondary-base
// sub-object pointer back to the derived object pointer (sub ecx, 0x6c) and
// tail jumps to the final overrider.
//
// The subtracted offset is the size of the primary base, so the primary base is
// laid out as a vtable pointer plus 26 int members (4 + 26 * 4 = 0x6c). Both
// bases declare the same virtual function; the derived class redeclares it and
// defines only its constructor, which is what makes the compiler emit the
// vtables and the adjusting thunk. The virtual stays undefined so the thunk's
// jump remains a relocation to an external symbol.
struct PrimaryBase
{
    virtual int* FUN_00b8f4a0(bool);
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
};

struct SecondaryBase
{
    virtual int* FUN_00b8f4a0(bool);
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b8f4a0
    virtual int* FUN_00b8f4a0(bool);
};

Derived::Derived()
{}
}  // namespace fnv_00b8f4a0

// FUN_00b8f650 : 8-byte MSVC adjustor thunk.
//   sub ecx, 0x6c ; jmp FUN_00b8f620
// It is the vtable entry of the second base of a class whose first base is
// 0x6c bytes long: the thunk converts the second-base pointer back to the
// complete object pointer and tail-jumps to the shared implementation.
struct ImageSpacePrimaryBase
{
    virtual void FUN_00b8f650();
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
};

struct ImageSpaceSecondaryBase
{
    virtual void FUN_00b8f650();
};

struct ImageSpaceDerived : ImageSpacePrimaryBase, ImageSpaceSecondaryBase
{
    ImageSpaceDerived();
// @fnv 0x00b8f650
    virtual void FUN_00b8f650();
};

ImageSpaceDerived::ImageSpaceDerived()
{}

namespace fnv_00b8f700 {
// MSVC adjustor thunk: the primary base occupies 0x6c bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_00b8f700();
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
};

struct SecondaryBase
{
    virtual void FUN_00b8f700();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b8f700
    virtual void FUN_00b8f700();
};

Derived::Derived()
{}
}  // namespace fnv_00b8f700

namespace fnv_00b8f7d0 {
// FUN_00b8f7d0 : 8-byte MSVC adjustor thunk.
//   sub ecx, 0x6c ; jmp FUN_00b8f7a0
// It is the vtable entry of a secondary base of a class whose first base is
// 0x6c bytes long: the thunk converts the secondary-base pointer back to the
// complete object pointer and tail-jumps to the shared implementation.
struct ImageSpacePrimaryBase
{
    virtual void FUN_00b8f7d0();
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
};

struct ImageSpaceSecondaryBase
{
    virtual void FUN_00b8f7d0();
};

struct ImageSpaceDerived : ImageSpacePrimaryBase, ImageSpaceSecondaryBase
{
    ImageSpaceDerived();
// @fnv 0x00b8f7d0
    virtual void FUN_00b8f7d0();
};

ImageSpaceDerived::ImageSpaceDerived()
{}
}  // namespace fnv_00b8f7d0

namespace fnv_00b8f920 {
// sub ecx,0x6c; jmp FUN_00b8f8f0 == MSVC adjustor thunk for a second base's virtual.
// PrimaryBase = vptr (4) + 26 named ints (104) = 0x6c.
struct PrimaryBase
{
    virtual void FUN_00b8f920();
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
};

struct SecondaryBase
{
    virtual void FUN_00b8f920();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b8f920
    virtual void FUN_00b8f920();
};

Derived::Derived()
{}
}  // namespace fnv_00b8f920

namespace fnv_00b8fa70 {
// Adjustor thunk for FUN_00b8fa70: "sub ecx, 0x6c; jmp FUN_00b8fa40".
//
// This is the MSVC "this adjusting thunk" emitted for a virtual function
// inherited from a secondary base: the thunk moves the secondary-base
// sub-object pointer back to the derived object pointer (sub ecx, 0x6c) and
// tail jumps to the final overrider.
//
// The subtracted offset is the size of the primary base, so the primary base
// is laid out as a vtable pointer plus 26 int members (4 + 26 * 4 = 0x6c).
// Both bases declare the same virtual function; the derived class redeclares
// it and defines only its constructor, which is what makes the compiler emit
// the vtables and the adjusting thunk. The virtual stays undefined so the
// thunk's jump is a relocation to an external symbol.
struct PrimaryBase
{
    virtual void FUN_00b8fa70();
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
};

struct SecondaryBase
{
    virtual void FUN_00b8fa70();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b8fa70
    virtual void FUN_00b8fa70();
};

Derived::Derived()
{}
}  // namespace fnv_00b8fa70

// FUN_00b8fbd0 : 8-byte MSVC adjustor thunk.
//   sub ecx, 0x6c ; jmp FUN_00b8fba0
struct AdjPrimaryBase
{
    virtual void FUN_00b8fbd0();
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
};

struct AdjSecondaryBase
{
    virtual void FUN_00b8fbd0();
};

struct AdjDerived : AdjPrimaryBase, AdjSecondaryBase
{
    AdjDerived();
// @fnv 0x00b8fbd0
    virtual void FUN_00b8fbd0();
};

AdjDerived::AdjDerived()
{}

struct S_Base1
{
    virtual void FUN_00b8fd30();
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
};
struct S_Base2
{
    virtual void FUN_00b8fd30();
};
struct S_Derived : S_Base1, S_Base2
{
    S_Derived();
// @fnv 0x00b8fd30
    virtual void FUN_00b8fd30();
};
S_Derived::S_Derived()
{}

namespace fnv_00b8fe90 {
// sub ecx,0x6c; jmp target  ==  MSVC adjustor thunk (multiple inheritance, primary base size 0x6c).
// Derived overrides a virtual that both of its bases declare, so the second base's vtable slot
// gets a thunk that moves `this` back by the size of the first base (0x6c) and tail-jumps to
// the derived implementation. Only the constructor is defined, so the vtables (and the thunk)
// get emitted.
struct PrimaryBase
{
    virtual void FUN_00b8fe90();
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
};

struct SecondaryBase
{
    virtual void FUN_00b8fe90();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b8fe90
    virtual void FUN_00b8fe90();
};

Derived::Derived()
{}
}  // namespace fnv_00b8fe90

namespace fnv_00b917b0 {
// Adjustor thunk for FUN_00b917b0: sub ecx,0x6c; jmp FUN_00b91780.
// The derived class inherits a virtual from the primary base; the secondary base's
// vtable slot therefore holds a thunk that steps this back over the primary base (0x6c bytes).
struct PrimaryBase
{
    virtual void FUN_00b917b0();
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
};

struct SecondaryBase
{
    virtual void FUN_00b917b0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b917b0
    virtual void FUN_00b917b0();
};

Derived::Derived()
{}
}  // namespace fnv_00b917b0

namespace fnv_00b918f0 {
// sub ecx,0x6c; jmp FUN_00b918f0  ==  MSVC adjustor thunk for a virtual that both bases declare.
// PrimaryBase size is 0x6c: vptr + 26 int fields (0x04..0x68).
struct PrimaryBase
{
    virtual int FUN_00b918f0(bool flag);
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
};

struct SecondaryBase
{
    virtual int FUN_00b918f0(bool flag);
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b918f0
    virtual int FUN_00b918f0(bool flag);
};

Derived::Derived()
{}
}  // namespace fnv_00b918f0

namespace fnv_00b91a30 {
// Adjustor thunk for FUN_00b91a30: "sub ecx, 0x6c; jmp FUN_00b91a00".
// PrimaryBase = vptr + 26 int fields (4 + 26*4 = 0x6c); SecondaryBase declares
// the same virtual; Derived redeclares it and defines only its constructor.
struct PrimaryBase
{
    virtual void FUN_00b91a30();
    int unk4;
    int unk8;
    int unkC;
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
};

struct SecondaryBase
{
    virtual void FUN_00b91a30();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b91a30
    virtual void FUN_00b91a30();
};

Derived::Derived()
{}
}  // namespace fnv_00b91a30

// FUN_00b91b40: [thunk] adjustor for FUN_00b91b50's secondary-slot override
// (dual-slot override, declared-only; primary base sized 0x6C = adjustor delta).

struct Prim6c
{
    virtual void FUN_00b91b40();
    int p04, p08, p0c, p10, p14, p18, p1c, p20, p24, p28, p2c, p30, p34, p38, p3c, p40, p44, p48, p4c, p50, p54, p58,
        p5c, p60, p64, p68;
};

struct Sec6c
{
    virtual void FUN_00b91b40();
};

struct Host6c : Prim6c, Sec6c
{
// @fnv 0x00b91b40
    virtual void FUN_00b91b40();
};

static Host6c g_thunk6c;

namespace fnv_00b91ce0 {
// Adjustor thunk for FUN_00b91ce0: sub ecx,0x6c; jmp FUN_00b91cb0.
// Derived overrides a virtual declared by both bases; primary base size 0x6c = vptr + 26 ints.
struct PrimaryBase
{
    virtual void FUN_00b91ce0();
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
};

struct SecondaryBase
{
    virtual void FUN_00b91ce0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b91ce0
    virtual void FUN_00b91ce0();
};

Derived::Derived()
{}
}  // namespace fnv_00b91ce0

namespace fnv_00b91e30 {
// MSVC adjustor thunk: the primary base occupies 0x6c bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_00b91e30();
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
};

struct SecondaryBase
{
    virtual void FUN_00b91e30();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b91e30
    virtual void FUN_00b91e30();
};

Derived::Derived()
{}
}  // namespace fnv_00b91e30

namespace fnv_00b91f80 {
// sub ecx,0x6c; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x6c).
struct PrimaryBase
{
    virtual void FUN_00b91f80();
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4C;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5C;
    int m_i60;
    int m_i64;
    int m_i68;
};

struct SecondaryBase
{
    virtual void FUN_00b91f80();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b91f80
    virtual void FUN_00b91f80();
};

Derived::Derived()
{}
}  // namespace fnv_00b91f80

namespace fnv_00b922c0 {
// Adjustor thunk: sub ecx,0x6c; jmp <base implementation>
// The derived class overrides a virtual that both of its bases declare, so the
// secondary base's vtable holds a thunk that moves `this` back by the size of
// the primary base (vptr 4 + 26 int fields 104 = 0x6c) before jumping.
struct PrimaryBase
{
    virtual void FUN_00b922c0();
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
};

struct SecondaryBase
{
    virtual void FUN_00b922c0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b922c0
    virtual void FUN_00b922c0();
};

Derived::Derived()
{}
}  // namespace fnv_00b922c0

namespace fnv_00b92440 {
// sub ecx,0x6c; jmp FUN_00b924d0  == MSVC adjustor thunk (multiple inheritance, primary base size 0x6c).
struct PrimaryBase
{
    virtual void FUN_00b92440();
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
};

struct SecondaryBase
{
    virtual void FUN_00b92440();
};

struct SpawnedObject : PrimaryBase, SecondaryBase
{
    SpawnedObject();
// @fnv 0x00b92440
    virtual void FUN_00b92440();
};

SpawnedObject::SpawnedObject()
{}
}  // namespace fnv_00b92440

namespace fnv_00b925a0 {
// Adjustor thunk for FUN_00b925a0: "sub ecx, 0x6c; jmp FUN_00b92570".
// PrimaryBase = vptr + 26 int fields (4 + 26*4 = 0x6c); SecondaryBase declares
// the same virtual; Derived redeclares it and defines only its constructor.
struct PrimaryBase
{
    virtual void FUN_00b925a0();
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
};

struct SecondaryBase
{
    virtual void FUN_00b925a0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b925a0
    virtual void FUN_00b925a0();
};

Derived::Derived()
{}
}  // namespace fnv_00b925a0

namespace fnv_00b927d0 {
// sub ecx,0x6c; jmp FUN_00b927d0  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its
// bases declare, so the secondary base's vtable slot gets a thunk that moves `this` back by sizeof(PrimaryBase).
struct ThunkPrimaryBase
{
    virtual void FUN_00b927d0();
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
};

struct ThunkSecondaryBase
{
    virtual void FUN_00b927d0();
};

struct ThunkDerived : ThunkPrimaryBase, ThunkSecondaryBase
{
    ThunkDerived();
// @fnv 0x00b927d0
    virtual void FUN_00b927d0();
};

ThunkDerived::ThunkDerived()
{}
}  // namespace fnv_00b927d0

namespace fnv_00b92920 {
// Adjustor thunk for FUN_00b92920: sub ecx,0x6c; jmp FUN_00b928f0.
// Derived overrides a virtual declared by both bases, so the secondary base's
// vtable slot holds a thunk that shifts `this` back by sizeof(PrimaryBase).
// sizeof(PrimaryBase) = vptr (4) + 26 int fields (104) = 0x6c.
struct PrimaryBase
{
    virtual void FUN_00b92920();
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
};

struct SecondaryBase
{
    virtual void FUN_00b92920();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b92920
    virtual void FUN_00b92920();
};

Derived::Derived()
{}
}  // namespace fnv_00b92920

namespace fnv_00b92a70 {
// Adjustor thunk for FUN_00b92a70: sub ecx,0x6c; jmp FUN_00b92a40.
// The derived class overrides a virtual that both bases declare, so the secondary
// base's vtable slot holds a thunk that shifts `this` back by sizeof(PrimaryBase).
// sizeof(PrimaryBase) = vptr (4) + 26 int fields (104) = 0x6c.
struct PrimaryBase
{
    virtual void FUN_00b92a70();
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
};

struct SecondaryBase
{
    virtual void FUN_00b92a70();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b92a70
    virtual void FUN_00b92a70();
};

Derived::Derived()
{}
}  // namespace fnv_00b92a70

namespace fnv_00b92bc0 {
struct Base1
{
    virtual void FUN_00b92bc0();
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
};
struct Base2
{
    virtual void FUN_00b92bc0();
};
struct Derived : Base1, Base2
{
    Derived();
// @fnv 0x00b92bc0
    virtual void FUN_00b92bc0();
};
Derived::Derived()
{}
}  // namespace fnv_00b92bc0

namespace fnv_00b92d10 {
// Virtual adjustor thunk for FUN_00b92d10:
//   sub ecx, 0x6c ; jmp FUN_00b92ce0
// The thunk lives in the vftable of the secondary base of a class that
// overrides a virtual declared by both of its bases; it moves `this` back
// to the start of the primary base (0x6c bytes) and tail-jumps to the
// final overrider.
struct PrimaryBase
{
    virtual void FUN_00b92d10();
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
};

struct SecondaryBase
{
    virtual void FUN_00b92d10();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b92d10
    virtual void FUN_00b92d10();
};

Derived::Derived()
{}
}  // namespace fnv_00b92d10

// Adjustor thunk: the secondary-base (+0x6c) vtable entry for an override defined on the derived class.

class B92ED0Primary
{
  public:
    virtual void* FUN_00b92ed0(bool bFree);
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
};

class B92ED0Secondary
{
  public:
    virtual void* FUN_00b92ed0(bool bFree);
};

class B92ED0Shader : public B92ED0Primary, public B92ED0Secondary
{
  public:
    B92ED0Shader();
// @fnv 0x00b92ed0
    virtual void* FUN_00b92ed0(bool bFree);
};

B92ED0Shader::B92ED0Shader()
{}

namespace fnv_00b93020 {
// Adjustor thunk for FUN_00b93020: "sub ecx, 0x6c; jmp FUN_00b92ff0".
//
// This is the MSVC "this adjusting thunk" that the compiler emits for a
// virtual function inherited from a secondary base: the thunk moves the
// secondary-base sub-object pointer back to the derived object pointer
// (sub ecx, 0x6c) and tail jumps to the final overrider.
//
// The subtracted offset is the size of the primary base, so the primary base
// is laid out as a vtable pointer plus 26 int members (4 + 26 * 4 = 0x6c).
// Both bases declare the same virtual function; the derived class redeclares
// it and defines only its constructor, which is what makes the compiler emit
// the vtables and the adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_00b93020();
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
};

struct SecondaryBase
{
    virtual void FUN_00b93020();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b93020
    virtual void FUN_00b93020();
};

Derived::Derived()
{}
}  // namespace fnv_00b93020

namespace fnv_00b93170 {
struct Base1
{
    virtual void FUN_00b93170();
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
};
struct Base2
{
    virtual void FUN_00b93170();
};
struct Derived : Base1, Base2
{
    Derived();
// @fnv 0x00b93170
    virtual void FUN_00b93170();
};
Derived::Derived()
{}
}  // namespace fnv_00b93170

namespace fnv_00b932c0 {
// sub ecx,0x6c; jmp target == MSVC adjustor thunk (secondary base vtable slot).
struct ThunkPrimaryBase
{
    virtual void FUN_00b932c0();
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
};

struct ThunkSecondaryBase
{
    virtual void FUN_00b932c0();
};

struct ThunkDerived : ThunkPrimaryBase, ThunkSecondaryBase
{
    ThunkDerived();
// @fnv 0x00b932c0
    virtual void FUN_00b932c0();
};

ThunkDerived::ThunkDerived()
{}
}  // namespace fnv_00b932c0

namespace fnv_00b93410 {
// Adjustor thunk for FUN_00b93410: "sub ecx, 0x6c; jmp FUN_00b933e0".
// PrimaryBase = vptr + 26 int fields (4 + 26*4 = 0x6c). Both bases declare the
// shared virtual; Derived redeclares it and defines only its constructor.
struct PrimaryBase
{
    virtual void FUN_00b93410(bool flag);
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
};

struct SecondaryBase
{
    virtual void FUN_00b93410(bool flag);
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b93410
    virtual void FUN_00b93410(bool flag);
};

Derived::Derived()
{}
}  // namespace fnv_00b93410

namespace fnv_00b93740 {
// Adjustor thunk for FUN_00b93740: sub ecx,0x6c; jmp FUN_00b93710.
// Derived overrides a virtual that both bases declare, so the secondary base's
// vtable slot holds a thunk that steps `this` back over the primary base (0x6c bytes).
struct PrimaryBase
{
    virtual void FUN_00b93740();
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
};

struct SecondaryBase
{
    virtual void FUN_00b93740();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b93740
    virtual void FUN_00b93740();
};

Derived::Derived()
{}
}  // namespace fnv_00b93740

namespace fnv_00b93a90 {
// Adjustor thunk for FUN_00b93a90: "sub ecx, 0x6c; jmp FUN_00b93a60".
// A derived class overrides a virtual that both a primary and a secondary base declare;
// the compiler emits an adjustor thunk that moves 'this' back by the primary base size
// (vptr + 26 ints = 0x6c) before tail-jumping to the base implementation.
struct PrimaryBase
{
    virtual void FUN_00b93a90();
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
};

struct SecondaryBase
{
    virtual void FUN_00b93a90();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b93a90
    virtual void FUN_00b93a90();
};

Derived::Derived()
{}
}  // namespace fnv_00b93a90

// Compiler-generated vtable adjustor thunk: secondary base sits at 0x6C inside
// the primary, override declared only (stays external), static global forces
// vtable emission -> [thunk] adjustor{0x6C} = sub ecx,0x6C; jmp override.
struct Prim_b93be0
{
    virtual void FUN_00b93be0();
    int p04;
    int p08;
    int p0c;
    int p10;
    int p14;
    int p18;
    int p1c;
    int p20;
    int p24;
    int p28;
    int p2c;
    int p30;
    int p34;
    int p38;
    int p3c;
    int p40;
    int p44;
    int p48;
    int p4c;
    int p50;
    int p54;
    int p58;
    int p5c;
    int p60;
    int p64;
    int p68;
};
struct Sec_b93be0
{
    virtual void FUN_00b93be0();
};
struct ThunkHost_b93be0 : Prim_b93be0, Sec_b93be0
{
// @fnv 0x00b93be0
    virtual void FUN_00b93be0();
};
static ThunkHost_b93be0 g_b93be0_thunk;

namespace fnv_00b93d30 {
// MSVC adjustor thunk: the primary base occupies 0x6c bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_00b93d30();
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
};

struct SecondaryBase
{
    virtual void FUN_00b93d30();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b93d30
    virtual void FUN_00b93d30();
};

Derived::Derived()
{}
}  // namespace fnv_00b93d30

namespace fnv_00b93e80 {
// Adjustor thunk for FUN_00b93e80: sub ecx,0x6c; jmp FUN_00b93e50.
// Primary base = vptr + 26 ints = 0x6c; derived redeclares the virtual and defines only its ctor.
struct PrimaryBase
{
    virtual void FUN_00b93e80();
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
};

struct SecondaryBase
{
    virtual void FUN_00b93e80();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b93e80
    virtual void FUN_00b93e80();
};

Derived::Derived()
{}
}  // namespace fnv_00b93e80

// Adjustor thunk: sub ecx,0x6C; jmp FUN_00b93fa0 (secondary-base slot in a
// 0x6C-sized primary base). VC9 only emits `sub reg,imm` in its own thunks,
// so reproduce via an MI dual-slot override declared but never defined.
struct PrimBase6c
{
    virtual void* FUN_00b93fd0(bool flag);
    int p04;
    int p08;
    int p0c;
    int p10;
    int p14;
    int p18;
    int p1c;
    int p20;
    int p24;
    int p28;
    int p2c;
    int p30;
    int p34;
    int p38;
    int p3c;
    int p40;
    int p44;
    int p48;
    int p4c;
    int p50;
    int p54;
    int p58;
    int p5c;
    int p60;
    int p64;
    int p68;
};

struct SecBaseAdj
{
    virtual void* FUN_00b93fd0(bool flag);
};

struct ThunkHostAdj : PrimBase6c, SecBaseAdj
{
// @fnv 0x00b93fd0
    virtual void* FUN_00b93fd0(bool flag);
};

static ThunkHostAdj g_adjThunk;

namespace fnv_00b94120 {
// Adjustor thunk (this-adjusting thunk) for a class that inherits the same
// virtual function through two bases.  The secondary base lives 0x6c bytes
// into the object, so a call routed through the secondary base's vtable slot
// has to move `this` back by 0x6c before it can tail-jump to the shared
// implementation that expects the primary base pointer.
struct ThunkPrimaryBase
{
    virtual void FUN_00b94120(bool flag);
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
};

struct ThunkSecondaryBase
{
    virtual void FUN_00b94120(bool flag);
};

struct ThunkDerived : ThunkPrimaryBase, ThunkSecondaryBase
{
    ThunkDerived();
// @fnv 0x00b94120
    virtual void FUN_00b94120(bool flag);
};

ThunkDerived::ThunkDerived()
{}
}  // namespace fnv_00b94120

namespace fnv_00b943c0 {
// MSVC adjustor thunk: the primary base occupies 0x6c bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_00b943c0();
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
};

struct SecondaryBase
{
    virtual void FUN_00b943c0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b943c0
    virtual void FUN_00b943c0();
};

Derived::Derived()
{}
}  // namespace fnv_00b943c0

namespace fnv_00b94510 {
struct ThunkBaseA
{
    virtual void* FUN_00b94510(bool bFlag);
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
};
struct ThunkBaseB
{
    virtual void* FUN_00b94510(bool bFlag);
};
struct ThunkDerived : ThunkBaseA, ThunkBaseB
{
    ThunkDerived();
// @fnv 0x00b94510
    virtual void* FUN_00b94510(bool bFlag);
};
ThunkDerived::ThunkDerived()
{}
}  // namespace fnv_00b94510

extern int DAT_0126f74c;

struct S_00b81760
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

    void __thiscall FUN_00b81760(int arg);
};

// Stores the value of a member field selected by arg into the global DAT_0126f74c.
// @fnv 0x00b81760
void S_00b81760::FUN_00b81760(int arg)
{
    switch (arg)
    {
    case 650:
        DAT_0126f74c = unk0b0;
        break;
    case 651:
        DAT_0126f74c = unk0bc;
        break;
    case 652:
        DAT_0126f74c = unk0b8;
        break;
    case 653:
        DAT_0126f74c = unk0b4;
        break;
    case 654:
        DAT_0126f74c = unk0c0;
        break;
    case 655:
        DAT_0126f74c = unk0cc;
        break;
    case 656:
        DAT_0126f74c = unk0c8;
        break;
    case 657:
        DAT_0126f74c = unk0c4;
        break;
    case 658:
        DAT_0126f74c = unk0d0;
        break;
    case 659:
        DAT_0126f74c = unk0dc;
        break;
    case 660:
        DAT_0126f74c = unk0d8;
        break;
    case 661:
        DAT_0126f74c = unk0d4;
        break;
    case 662:
        DAT_0126f74c = unk0e0;
        break;
    case 663:
        DAT_0126f74c = unk0ec;
        break;
    case 664:
        DAT_0126f74c = unk0e8;
        break;
    case 665:
        DAT_0126f74c = unk0e4;
        break;
    case 666:
        DAT_0126f74c = unk100;
        break;
    case 684:
        DAT_0126f74c = unk06c;
        break;
    case 685:
        DAT_0126f74c = unk078;
        break;
    case 686:
        DAT_0126f74c = unk074;
        break;
    case 687:
        DAT_0126f74c = unk070;
        break;
    case 688:
        DAT_0126f74c = unk08c;
        break;
    case 689:
        DAT_0126f74c = unk098;
        break;
    case 690:
        DAT_0126f74c = unk094;
        break;
    case 691:
        DAT_0126f74c = unk090;
        break;
    case 692:
        DAT_0126f74c = unk07c;
        break;
    case 693:
        DAT_0126f74c = unk080;
        break;
    case 694:
        DAT_0126f74c = unk084;
        break;
    case 695:
        DAT_0126f74c = unk088;
        break;
    case 696:
        DAT_0126f74c = unk09c;
        break;
    case 697:
        DAT_0126f74c = unk0a8;
        break;
    case 698:
        DAT_0126f74c = unk0a4;
        break;
    case 699:
        DAT_0126f74c = unk0a0;
        break;
    case 648:
        DAT_0126f74c = unk0f8;
        break;
    case 700:
        DAT_0126f74c = unk0fc;
        break;
    case 575:
        DAT_0126f74c = unk0f0;
        break;
    case 576:
        DAT_0126f74c = unk0f4;
        break;
    case 667:
        DAT_0126f74c = unk148;
        break;
    case 670:
        DAT_0126f74c = unk154;
        break;
    case 669:
        DAT_0126f74c = unk150;
        break;
    case 668:
        DAT_0126f74c = unk14c;
        break;
    case 671:
        DAT_0126f74c = unk158;
        break;
    case 674:
        DAT_0126f74c = unk164;
        break;
    case 673:
        DAT_0126f74c = unk160;
        break;
    case 672:
        DAT_0126f74c = unk15c;
        break;
    case 675:
        DAT_0126f74c = unk168;
        break;
    case 678:
        DAT_0126f74c = unk174;
        break;
    case 677:
        DAT_0126f74c = unk170;
        break;
    case 676:
        DAT_0126f74c = unk16c;
        break;
    case 679:
        DAT_0126f74c = unk178;
        break;
    case 682:
        DAT_0126f74c = unk184;
        break;
    case 681:
        DAT_0126f74c = unk180;
        break;
    case 680:
        DAT_0126f74c = unk17c;
        break;
    case 683:
        DAT_0126f74c = unk190;
        break;
    case 702:
        DAT_0126f74c = unk104;
        break;
    case 703:
        DAT_0126f74c = unk110;
        break;
    case 704:
        DAT_0126f74c = unk10c;
        break;
    case 705:
        DAT_0126f74c = unk108;
        break;
    case 706:
        DAT_0126f74c = unk124;
        break;
    case 707:
        DAT_0126f74c = unk130;
        break;
    case 708:
        DAT_0126f74c = unk12c;
        break;
    case 709:
        DAT_0126f74c = unk128;
        break;
    case 710:
        DAT_0126f74c = unk114;
        break;
    case 711:
        DAT_0126f74c = unk118;
        break;
    case 712:
        DAT_0126f74c = unk11c;
        break;
    case 713:
        DAT_0126f74c = unk120;
        break;
    case 714:
        DAT_0126f74c = unk134;
        break;
    case 715:
        DAT_0126f74c = unk140;
        break;
    case 716:
        DAT_0126f74c = unk13c;
        break;
    case 717:
        DAT_0126f74c = unk138;
        break;
    case 649:
        DAT_0126f74c = unk188;
        break;
    case 718:
        DAT_0126f74c = unk18c;
        break;
    case 701:
        DAT_0126f74c = unk0ac;
        break;
    default:
        break;
    }
}

struct PointB9
{
    float x;
    float y;
    float z;
    float Length() const;
    void Unitize();
    PointB9 operator-(const PointB9& o) const
    {
        PointB9 r;
        r.x = x - o.x;
        r.y = y - o.y;
        r.z = z - o.z;
        return r;
    }
    PointB9 operator-() const
    {
        PointB9 r;
        r.x = -x;
        r.y = -y;
        r.z = -z;
        return r;
    }
    PointB9& operator*=(float f)
    {
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }
    float operator*(const PointB9& o) const
    {
        return x * o.x + y * o.y + z * o.z;
    }
};

inline float MaxF(float a, float b)
{
    return a > b ? a : b;
}
inline float MinF(float a, float b)
{
    return a < b ? a : b;
}
inline float MinR(float a, double b)
{
    if (a > b)
        return (float)b;
    return a;
}
inline float MaxR(float a, double b)
{
    if (a < b)
        return (float)b;
    return a;
}
inline float MinE(float a, float b)
{
    if (a > b)
        return b;
    return a;
}
inline float MaxE(float a, float b)
{
    if (a < b)
        return b;
    return a;
}
inline float Sat(float v)
{
    if (v > 1.0)
        v = 1.0;
    if (v < 0.0)
        v = 0.0;
    return v;
}
inline float Sat2(float v)
{
    if (v > 1.0)
        return 1.0f;
    if (v < 0.0)
        return 0.0f;
    return v;
}
extern "C" double gModifierZero;
inline float Clamp3(float v, float lo, float hi)
{
    v = v > hi ? hi : v;
    return v < lo ? lo : v;
}
inline void StoreF(float& d, float v)
{
    d = v;
}
inline void ClampHi(float& v)
{
    if (v > 1.0)
        v = 1.0f;
}
inline void ClampLo(float& v)
{
    if (v < 0.0)
        v = 0.0f;
}
inline double DMin(double a, double b)
{
    return a > b ? b : a;
}
inline double DMax(double a, double b)
{
    return a > b ? a : b;
}
inline float FMin(float a, float b)
{
    return a > b ? b : a;
}
inline float FMax(float a, float b)
{
    return a > b ? a : b;
}
inline const float& RMin(const float& a, const float& b)
{
    return a > b ? b : a;
}
inline const float& RMax(const float& a, const float& b)
{
    return a > b ? a : b;
}
float FUN_00404010(float a, float b);
float FUN_0040ebd0(float a, float b);

struct LightStandIn
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
    unsigned char flags30;
    char unk31;
    char unk32;
    char unk33;
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
    PointB9 worldPos;
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
    float scale;
    int unkc8;
    int unkcc;
    int unkd0;
    PointB9 range;
    float radius;
    __forceinline void Snapshot(PointB9& pos, PointB9& r, float s) const
    {
        pos = worldPos;
        r = range;
        r *= s;
    }
    float GetScale() const
    {
        return scale;
    }
    PointB9 GetRange() const
    {
        return range;
    }
    const PointB9& GetPos() const
    {
        return worldPos;
    }
    PointB9 GetPosV() const
    {
        return worldPos;
    }
    PointB9 ScaledRange() const
    {
        PointB9 r = range;
        r *= GetScale();
        return r;
    }
};

struct ShadowLightStandIn
{
    int unk00;
    int unk04;
    int unk08;
    float fade;
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
    bool unkec;
    char unked;
    char unkee;
    char unkef;
    int unkf0;
    bool castsShadows;
    char unkf5;
    char unkf6;
    char unkf7;
    LightStandIn* light;
    float FUN_00b9bdf0(PointB9 pos, PointB9 target, LightStandIn* other);
};

// Returns 0 if excluded, else a fade (distance based when castsShadows) times the clamped direction dot product times the largest light range component.
// @fnv 0x00b9bdf0
float ShadowLightStandIn::FUN_00b9bdf0(PointB9 pos, PointB9 target, LightStandIn* other)
{
    LightStandIn* l = light;
    if (l == other || unkec == true || (l->flags30 & 1))
        return 0.0f;

    {
        PointB9 lightPos, r;
        l->Snapshot(lightPos, r, l->GetScale());
        float radius = l->radius;
        fade = 1.0f;
        PointB9 toLight = pos - lightPos;
        if (castsShadows)
        {
            float d = toLight.Length() / radius;
            d = FUN_0040ebd0(1.0f, FUN_00404010(0.0f, d));
            fade = 1.0f - d * d;
        }
        PointB9 dir = target - pos;
        dir.Unitize();
        toLight.Unitize();
        float dot = (float)(-dir * toLight);
        float hi = 1.0 < dot ? 1.0f : dot;
        float clamped = hi < gModifierZero ? 0.0f : hi;
        float m = MaxF(r.x, MaxF(r.y, r.z));
        return fade = fade * clamped * m;
    }
}

struct PassShader : Shader_b93420
{
    bool ConfigureBeamPass();
};
// Allocates m_usStageCount stages, configures each as a beam stage, sets render states, and assigns vertex and pixel shaders to m_pRenderPass.
// @fnv 0x00b93750
bool PassShader::ConfigureBeamPass()
{
    StageReturnRef stage;
    FUN_00e804d0(&m_pRenderPass);
    unsigned int next = 0;
    for (unsigned int i = 0; i < m_usStageCount;)
    {
        AssignStageFromPool(stage.m_p);
        if (next < (unsigned int)(m_usStageCount - 1))
            ConfigureBeamStage(stage.m_p, next, 3, 2, 1);
        else
            ConfigureBeamStage(stage.m_p, next, 1, 2, 1);
        m_pRenderPass->SetDestructibleData(m_pRenderPass->unk14, stage.m_p);
        i = next + 1;
        next = i;
    }
    m_pRenderPass->GetStates()->SetState(7, 0, 1);
    m_pRenderPass->GetStates()->SetState(14, 0, 1);
    m_pRenderPass->GetStates()->SetState(27, 0, 1);
    m_pRenderPass->GetStates()->SetState(15, 0, 1);
    m_pRenderPass->GetStates()->SetState(168, 15, 1);
    InitPasses();
    m_pRenderPass->SetVertexShader(m_pkVertex);
    m_pRenderPass->SetPixelShader(m_pkPixel);
    return true;
}

extern const double DAT_01017cf8;
extern const double DAT_010b7e90 = (double)1.4f;
extern double DAT_010b7e98, DAT_010731a8;
extern const float DAT_01016264, DAT_01032adc;

extern double DAT_01012060;
extern double DAT_01012070, DAT_010231d8, DAT_010217d8, DAT_0101de30;
static float ClipHighD(float x, double d)
{
    if (x > d)
        return 1.0f;
    return x;
}
static float ClipUpperRadius(float x)
{
    if (x > DAT_010231d8)
        return DAT_01032adc;
    return x;
}
class B9Point3
{
  public:
    float x, y, z;
    B9Point3()
    {}
    B9Point3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    B9Point3 operator*(float f) const
    {
        return B9Point3(x * f, y * f, z * f);
    }
    B9Point3 operator+(const B9Point3& p) const
    {
        return B9Point3(x + p.x, y + p.y, z + p.z);
    }
    B9Point3 operator-(const B9Point3& p) const
    {
        return B9Point3(x - p.x, y - p.y, z - p.z);
    }
    B9Point3& operator+=(const B9Point3& p)
    {
        x += p.x;
        y += p.y;
        z += p.z;
        return *this;
    }
    B9Point3 operator-() const
    {
        return B9Point3(-x, -y, -z);
    }
    float Length() const
    {
        return (float)sqrt(x * x + y * y + z * z);
    }
    __declspec(noinline) void FUN_004a0c10();
};
struct NiColor
{
    float r, g, b;
    NiColor()
    {}
    NiColor(float x, float y, float z) : r(x), g(y), b(z)
    {}
    NiColor operator*(float f) const
    {
        NiColor result = *this;
        result *= f;
        return result;
    }
    NiColor operator+(const NiColor& c) const
    {
        NiColor result = *this;
        result += c;
        return result;
    }
    NiColor& operator*=(float f)
    {
        r *= f;
        g *= f;
        b *= f;
        return *this;
    }
    NiColor& operator+=(const NiColor& c)
    {
        r += c.r;
        g += c.g;
        b += c.b;
        return *this;
    }
};
struct B9UpdateData
{
    float time;
    bool updateControllers, multithread, geomorph, updateBounds, unused;
    B9UpdateData()
        : time(0), updateControllers(false), multithread(false), geomorph(false), updateBounds(false), unused(false)
    {}
};
struct B9Bounds
{
    int unk00, unk04, unk08;
    B9Point3 center;
    B9Point3 extent;
};
struct B9Light
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
    unsigned int flags;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    B9Point3 translation;
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
    B9Point3 worldPosition;
    float worldScale;
    int unk9c;
    int unka0;
    int unka4;
    unsigned int revision;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    float active;
    int unkc8;
    int unkcc;
    int unkd0;
    NiColor diffuse;
    B9Point3 attenuation;
    int unkec;
    B9Point3 direction;
    void SetDiffuse(const NiColor& c)
    {
        diffuse = c;
        ++revision;
    }
    void SetAttenuation(const B9Point3& a)
    {
        attenuation = a;
        ++revision;
    }
    B9Bounds* FUN_00a5bdd0(int);
    void FUN_00a59c60(B9UpdateData&);
};
struct B9Entry
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
    bool disabled;
    int unkf0;
    int unkf4;
    B9Light* light;
};
struct B9List
{
    B9Entry* FUN_00b70600(void** position);
    B9Entry* FUN_00b70700(void** position);
};
struct B9Manager
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
    B9Entry* primary;
    B9Entry* GetListItemAt(unsigned int index);
};
static inline B9Manager* B9Mgr()
{
    return reinterpret_cast<B9Manager*>(DAT_011f91c8);
}
extern int DAT_012031e4;
extern B9Point3 DAT_011f426c;
extern NiColor DAT_011f4998;
extern float DAT_011ffea0[];
extern float DAT_011fff40[];
struct B9D150
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
    B9Light* output;
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
    B9Light* object;
    void UpdateOutputLight(B9List* lights, B9Point3 position);
};
static float FinalClamp(float x)
{
    float low = x < DAT_010217d8 ? 0.8f : x;
    return ClipHighD(low, DAT_01012070);
}
static float WeightLowerBound(float x)
{
    if (x < DAT_01012060)
        return 0.0f;
    return x;
}
static float WeightUpperBound(float limit, float x)
{
    return limit < x ? limit : x;
}
// Computes a weighted blend of nearby B9Light sources into output light translation, diffuse color, and attenuation distance.
// @fnv 0x00b9d150
void B9D150::UpdateOutputLight(B9List* lights, B9Point3 position)
{
    B9Bounds* bounds = object->FUN_00a5bdd0(DAT_012031e4);
    position = object->worldPosition;
    if (bounds)
    {
        float scale = object->worldScale;
        position += bounds->center * scale;
    }
    B9Point3 extent = bounds ? bounds->extent * object->worldScale : DAT_011f426c;
    float largest = extent.x > extent.y ? extent.x : extent.y;
    float radius = largest > extent.z ? largest : extent.z;
    float total = 0.0f;
    unsigned int count = 0;
    unsigned short index = 0;
    void* cursor;
    B9Entry* entry = lights ? lights->FUN_00b70600(&cursor) : B9Mgr()->GetListItemAt(0);

    if (entry)
    {
        do
        {
            if (count >= 40)
                break;
            if (!entry->disabled)
            {
                B9Light* light = entry->light;
                if (!(light->flags & 1) && light->active > 0.0f)
                {
                    B9Point3 delta = light->worldPosition - position;
                    float weight = 1.0f - (delta.Length() - radius) / light->attenuation.x;
                    float clipped = WeightUpperBound(1.0f, (float)WeightLowerBound(weight));
                    DAT_011ffea0[count] = DAT_011fff40[count] = clipped;
                    ++count;
                    total += clipped;
                }
            }
            ++index;
            entry = lights ? lights->FUN_00b70700(&cursor) : B9Mgr()->GetListItemAt(index);
        } while (entry);
    }
    float distance = 0.0f;
    B9Manager* manager = B9Mgr();
    B9Point3 direction = DAT_011f426c;
    NiColor color = DAT_011f4998;
    B9Light* primary = manager->primary->light;
    B9Point3 fallback = -primary->direction;
    fallback.z *= radius * DAT_010b7e98;
    fallback.FUN_004a0c10();
    if (total == 0.0f)
    {
        direction = fallback;
        color = primary->diffuse;
        direction.FUN_004a0c10();
        float zmin = (float)(radius / DAT_010731a8);
        if (zmin > direction.z)
            direction.z = zmin;
    }
    else
    {
        unsigned int scan = 0;
        entry = lights ? lights->FUN_00b70600(&cursor) : manager->GetListItemAt(0);
        for (unsigned int i = 0; i < count; ++i)
        {
            if (entry && !entry->disabled)
            {
                if (!(entry->light->flags & 1))
                {
                    B9Light* light = entry->light;
                    float contribution = DAT_011ffea0[i] / total;
                    if (contribution > 0.0f)
                    {
                        double other = 1.0 - DAT_011ffea0[i];
                        float& acc = distance;
                        acc += (entry->light->attenuation.x * DAT_011ffea0[i] + other * 1000.0) * contribution;
                        B9Point3 delta = entry->light->worldPosition - position;
                        delta.FUN_004a0c10();
                        delta = delta * DAT_011ffea0[i] + fallback * (float)other;
                        direction += delta * contribution;
                        color += (light->diffuse * DAT_011ffea0[i] + primary->diffuse * (float)other) * contribution;
                    }
                }
            }
            entry = lights ? lights->FUN_00b70700(&cursor) : B9Mgr()->GetListItemAt(++scan);
        }
        direction.FUN_004a0c10();
        if (direction.z < DAT_0101de30)
            direction.z = DAT_01016264;
    }
    direction.FUN_004a0c10();
    float limitedDistance = ClipUpperRadius(radius);
    output->translation = position + (direction * limitedDistance) * (float)DAT_010b7e90;
    distance = (float)(limitedDistance * 8.0);
    B9UpdateData update;
    output->FUN_00a59c60(update);
    float intensity = (float)(color.r * (double)0.4f + color.g * (double)0.4f + color.b * (double)0.4f);
    float clamped = FinalClamp(intensity);
    output->SetDiffuse(NiColor(clamped, clamped, clamped));
    output->SetAttenuation(B9Point3(distance, 0.0f, 0.0f));
}

void B9Point3::FUN_004a0c10()
{
    float n = Length();
    if (n > DAT_01017cf8)
    {
        float inv = 1.0f / n;
        x *= inv;
        y *= inv;
        z *= inv;
    }
    else
    {
        x = y = z = 0.0f;
    }
}

int __cdecl UpdateInputFlags(int id, int flags);

// Maps code (575, 648 to 718) to a small id with a switch, defaulting to 0, and returns FUN_00b815e0(id, 0).
// @fnv 0x00b81d60
int __stdcall FUN_00b81d60(int code)
{
    int id = 0;
    switch (code)
    {
    case 650:
        id = 17;
        break;
    case 651:
        id = 20;
        break;
    case 652:
        id = 19;
        break;
    case 653:
        id = 18;
        break;
    case 654:
        id = 21;
        break;
    case 655:
        id = 24;
        break;
    case 656:
        id = 23;
        break;
    case 657:
        id = 22;
        break;
    case 658:
        id = 25;
        break;
    case 659:
        id = 28;
        break;
    case 660:
        id = 27;
        break;
    case 661:
        id = 26;
        break;
    case 662:
        id = 29;
        break;
    case 663:
        id = 32;
        break;
    case 664:
        id = 31;
        break;
    case 665:
        id = 30;
        break;
    case 666:
        id = 37;
        break;
    case 684:
        id = 0;
        break;
    case 685:
        id = 3;
        break;
    case 686:
        id = 2;
        break;
    case 687:
        id = 1;
        break;
    case 688:
        id = 8;
        break;
    case 689:
        id = 11;
        break;
    case 690:
        id = 10;
        break;
    case 691:
        id = 9;
        break;
    case 692:
        id = 4;
        break;
    case 693:
        id = 5;
        break;
    case 694:
        id = 6;
        break;
    case 695:
        id = 7;
        break;
    case 696:
        id = 12;
        break;
    case 697:
        id = 15;
        break;
    case 698:
        id = 14;
        break;
    case 699:
        id = 13;
        break;
    case 648:
        id = 35;
        break;
    case 700:
        id = 36;
        break;
    case 575:
        id = 33;
        break;
    case 576:
        id = 34;
        break;
    case 667:
        id = 55;
        break;
    case 670:
        id = 58;
        break;
    case 669:
        id = 57;
        break;
    case 668:
        id = 56;
        break;
    case 671:
        id = 59;
        break;
    case 674:
        id = 62;
        break;
    case 673:
        id = 61;
        break;
    case 672:
        id = 60;
        break;
    case 675:
        id = 63;
        break;
    case 678:
        id = 66;
        break;
    case 677:
        id = 65;
        break;
    case 676:
        id = 64;
        break;
    case 679:
        id = 67;
        break;
    case 682:
        id = 70;
        break;
    case 681:
        id = 69;
        break;
    case 680:
        id = 68;
        break;
    case 683:
        id = 73;
        break;
    case 702:
        id = 38;
        break;
    case 703:
        id = 41;
        break;
    case 704:
        id = 40;
        break;
    case 705:
        id = 39;
        break;
    case 706:
        id = 46;
        break;
    case 707:
        id = 49;
        break;
    case 708:
        id = 48;
        break;
    case 709:
        id = 47;
        break;
    case 710:
        id = 42;
        break;
    case 711:
        id = 43;
        break;
    case 712:
        id = 44;
        break;
    case 713:
        id = 45;
        break;
    case 714:
        id = 50;
        break;
    case 715:
        id = 53;
        break;
    case 716:
        id = 52;
        break;
    case 717:
        id = 51;
        break;
    case 649:
        id = 71;
        break;
    case 718:
        id = 72;
        break;
    case 701:
        id = 16;
        break;
    }
    return UpdateInputFlags(id, 0);
}

class B8EE90CinematicShader : public B92700WaterEffect
{
  public:
    void FUN_00b8ee90();
};

// @fnv 0x00b8ee90
void B8EE90CinematicShader::FUN_00b8ee90()
{
    B92700ShaderFile kVertexShader;
    kVertexShader.m_pcFile = "imagespace\\1x\\v\\base.v.hlsl";
    kVertexShader.m_akMacros[0].m_pcName = 0;
    FUN_00ec61c0(&kVertexShader.m_akMacros[0].m_pcDefinition, 0, 0x44);

    B92700ShaderFile kPixelShader = {
        "imagespace\\2x\\p\\cinematic.p.hlsl", "TINT", "", "SATURATION", "", "BRIGHT", "", "CONTRAST", "", 0};

    CreateShaders(&kVertexShader, &kPixelShader, "Cinematic", "vs_1_1", "ps_2_a");
    SetupShaders();
}
