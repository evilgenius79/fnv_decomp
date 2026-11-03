
// src/staging/blk_00c80000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00c80000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00c80000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
struct ScalarFactor
{
    __m128 value;
    __forceinline ScalarFactor(float x) : value(_mm_load_ss(&x))
    {}
};
struct ScaledVector
{
    __m128 value;
    __forceinline void Multiply(const ScalarFactor& factor)
    {
        value = _mm_mul_ps(_mm_shuffle_ps(factor.value, factor.value, 0), value);
    }
};
struct LocalTypeTag
{
    const char* name;
    LocalTypeTag* parent;
};
extern const LocalTypeTag DAT_012043f8;
extern const __m128 DAT_01267e30;
struct ScaledBackend
{
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
    __m128 firstVector;
    __m128 secondVector;
    void OnTrigger(const __m128*);
    void FUN_00561800(const __m128*);
};
struct PhysicsWrapper
{
    unsigned int unk00, unk04;
    ScaledBackend* backend;
    void FUN_00a29680();
};
struct CollisionState
{
    unsigned int unk00, unk04, unk08, unk0c;
    PhysicsWrapper* physics;
};
struct CollisionBase
{
    CollisionState* FUN_00653290(const LocalTypeTag*);
};
struct SceneBranch;
struct SceneObject
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual SceneBranch* GetBranch();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18;
    CollisionBase* collision;
};
struct SceneBranch : SceneObject
{
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
    SceneObject** children;
    unsigned short capacity;
    unsigned short count;
};
// @fnv 0x00c803a0
void __cdecl FUN_00c803a0(SceneObject* object, float scale)
{
    if (object)
    {
        if (object->collision)
        {
            CollisionState* state = object->collision->FUN_00653290(&DAT_012043f8);
            if (state && state->physics)
            {
                PhysicsWrapper* wrapper = state->physics;
                ScaledBackend* backend = wrapper->backend;
                ScaledVector values[2];
                values[0].value = backend ? backend->firstVector : DAT_01267e30;
                values[1].value = backend ? backend->secondVector : DAT_01267e30;
                values[0].Multiply(ScalarFactor(scale));
                values[1].Multiply(ScalarFactor(scale));
                if (backend)
                {
                    wrapper->FUN_00a29680();
                    backend->OnTrigger(&values[0].value);
                    wrapper->FUN_00a29680();
                }
                backend = wrapper->backend;
                if (backend)
                {
                    wrapper->FUN_00a29680();
                    backend->FUN_00561800(&values[1].value);
                    wrapper->FUN_00a29680();
                }
            }
        }
        SceneBranch* branch = object->GetBranch();
        if (branch)
        {
            for (unsigned int index = 0; index < branch->count; ++index)
            {
                FUN_00c803a0(branch->children[index], scale);
            }
        }
    }
}

void __cdecl FUN_00c7fcc0(void* first, const void* second, void* result, bool option);
union __declspec(align(16)) ResultBuffer
{
    void* hit;
    char storage[0x30];
    ResultBuffer() : hit(0)
    {}
};
// @fnv 0x00c806b0
void* FUN_00c806b0(void* first, const void* second, bool option)
{
    ResultBuffer result;
    FUN_00c7fcc0(first, second, &result, option);
    return result.hit;
}

struct FUN_00c86660_cls
{
    __m128 m_v00;
    __m128 m_v10;
    __m128 m_v20;
    __m128 m_v30;
    __m128 m_v40;
    __m128 m_v50;
    __m128 m_v60;
    __m128 m_v70;
    __m128 m_v80;
    __m128 m_v90;
    float m_fA0;
    float m_fA4;
    float m_fA8;
    unsigned char m_bAC;
    unsigned char m_bAD;
    unsigned char m_bAE;

    FUN_00c86660_cls* FUN_00c86660(const FUN_00c86660_cls* src);
};

// @fnv 0x00c86660
FUN_00c86660_cls* FUN_00c86660_cls::FUN_00c86660(const FUN_00c86660_cls* src)
{
    m_v00 = src->m_v00;
    m_v10 = src->m_v10;
    m_v20 = src->m_v20;
    m_v30 = src->m_v30;
    m_v40 = src->m_v40;
    m_v50 = src->m_v50;
    m_v60 = src->m_v60;
    m_v70 = src->m_v70;
    m_v80 = src->m_v80;
    m_v90 = src->m_v90;
    m_fA0 = src->m_fA0;
    m_fA4 = src->m_fA4;
    m_fA8 = src->m_fA8;
    m_bAC = src->m_bAC;
    m_bAD = src->m_bAD;
    m_bAE = src->m_bAE;
    return this;
}

class bhkLimitedHingeVector
{
  public:
    float x;
    float y;
    float z;
    float w;
    void FUN_004b4db0(const float* p);
};

class Vec4Tmp
{
  public:
    __m128 v;
    void FUN_00cb2fc0();
};

class bhkLimitedHingeVectorSet
{
  public:
    bhkLimitedHingeVector m_v0;
    bhkLimitedHingeVector m_v1;
    bhkLimitedHingeVector m_v2;
    void FUN_00c8bf50();
};

// @fnv 0x00c8bf50
void bhkLimitedHingeVectorSet::FUN_00c8bf50()
{
    bhkLimitedHingeVector& v1 = m_v1;
    bhkLimitedHingeVector& v2 = m_v2;
    Vec4Tmp a;
    a.v = _mm_setr_ps(m_v0.x, m_v0.y, m_v0.z, m_v0.w);
    Vec4Tmp b;
    b.v = _mm_setr_ps(v1.x, v1.y, v1.z, v1.w);
    Vec4Tmp c;
    c.v = _mm_setr_ps(v2.x, v2.y, v2.z, v2.w);
    a.FUN_00cb2fc0();
    m_v0.FUN_004b4db0((const float*)&a);
    v1.FUN_004b4db0((const float*)&b);
    v2.FUN_004b4db0((const float*)&c);
}

extern int DAT_010c69f4;

struct FUN_00c99ff0_base
{
    void FUN_00c69010(void* arg);
    char m_auiShapeKeys[0xa0];
};

struct FUN_00c99ff0_cls : FUN_00c99ff0_base
{
    __m128 m_a0;
    __m128 m_b0;
    __m128 m_c0;
    FUN_00c99ff0_cls* FUN_00c99ff0(void* a1, __m128* a2, __m128* a3);
};

// @fnv 0x00c99ff0
FUN_00c99ff0_cls* FUN_00c99ff0_cls::FUN_00c99ff0(void* a1, __m128* a2, __m128* a3)
{
    ((FUN_00c99ff0_base*)this)->FUN_00c69010(a1);
    *(int*)this = (int)&DAT_010c69f4;
    m_a0 = *a2;
    m_b0 = *a3;
    m_c0 = *(__m128*)((char*)a1 + 0x40);
    return this;
}

struct FnvMat4
{
    __m128 m_uiX;
    __m128 m_uiY;
    __m128 m_uiZ;
    __m128 m_w;
};

struct Obj00c9ec00
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
    FnvMat4 m_mat;
};

struct Owner00c9ec00
{
    int unk00;
    int unk04;
    Obj00c9ec00* unk08;
    void Noop00a29680();
    void FUN_00c9ec00(FnvMat4* out);
};

// @fnv 0x00c9ec00
void Owner00c9ec00::FUN_00c9ec00(FnvMat4* out)
{
    if (!this)
        return;
    Obj00c9ec00* p = unk08;
    if (!p)
        return;
    Noop00a29680();
    out->m_uiX = p->m_mat.m_uiX;
    out->m_uiY = p->m_mat.m_uiY;
    out->m_uiZ = p->m_mat.m_uiZ;
    out->m_w = p->m_mat.m_w;
    Noop00a29680();
}

struct __declspec(align(16)) hkVector4C9E
{
    __m128 m_vComponents;
};

struct hkRotationC9E
{
    hkVector4C9E m_kColumn0;
    hkVector4C9E m_kColumn1;
    hkVector4C9E m_kColumn2;
};

struct hkTransformC9E
{
    hkRotationC9E m_rotation;
    hkVector4C9E m_vTranslation;
};

struct NiMatrix3C9E
{
    float m_afEntries[3][3];
};

struct NiPoint3C9E
{
    float x, y, z;
};

struct NiTransformC9E
{
    NiMatrix3C9E m_kOrientation;
    NiPoint3C9E m_kTranslation;
    float m_fScale;
};

void __stdcall FUN_00c9ec00(hkTransformC9E* pkTransform);
void __cdecl FUN_00624b10(NiMatrix3C9E* pkOut, const hkRotationC9E* pkRotation);
void __cdecl FUN_00458620(NiPoint3C9E* pkOut, const hkVector4C9E* pkVector);

// @fnv 0x00c9ec60
void __stdcall FUN_00c9ec60(NiTransformC9E* pkOut)
{
    hkTransformC9E kTransform;
    FUN_00c9ec00(&kTransform);
    FUN_00624b10(&pkOut->m_kOrientation, &kTransform.m_rotation);
    FUN_00458620(&pkOut->m_kTranslation, &kTransform.m_vTranslation);
}

namespace fnv_00c9ecb0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int8 m128_i8[16];
    __int16 m128_i16[8];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int8 m128_u8[16];
    unsigned __int16 m128_u16[8];
    unsigned __int32 m128_u32[4];
};

struct hkVector4
{
    __m128 m_vComponents;
};

struct hkMatrix4
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_kColumn3;
};

struct bhkLimitedHingeVector
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void FUN_004b4db0(const float* v);
};

struct HingeVectorSet
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    bhkLimitedHingeVector m_akVectors[4];
};

struct FUN_00c9ecb0_cls
{
    void FillOutputFromState(HingeVectorSet* set);
    void FUN_00c9ec00(hkMatrix4& m);
    void FUN_00c9ecb0(HingeVectorSet* set);
};

// @fnv 0x00c9ecb0
void FUN_00c9ecb0_cls::FUN_00c9ecb0(HingeVectorSet* set)
{
    FillOutputFromState(set);
    hkMatrix4 m;
    FUN_00c9ec00(m);
    bhkLimitedHingeVector* vectors = set->m_akVectors;
    vectors[0].FUN_004b4db0(m.m_kColumn0.m_vComponents.m128_f32);
    vectors[1].FUN_004b4db0(m.m_kColumn1.m_vComponents.m128_f32);
    vectors[2].FUN_004b4db0(m.m_kColumn2.m_vComponents.m128_f32);
    vectors[3].FUN_004b4db0(m.m_kColumn3.m_vComponents.m128_f32);
}
}  // namespace fnv_00c9ecb0

#include <xmmintrin.h>
extern "C" void _ReadWriteBarrier(void);
namespace fnv_00c88520 {
struct FnvMat4
{
    __m128 m_uiX;
    __m128 m_uiY;
    __m128 m_uiZ;
    __m128 m_w;
};
struct Vec3
{
    float x, y, z;
};
struct Transform
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Vec3 translate;
    float scale;
    Transform FUN_0062c250(const Transform& rhs) const;
};
struct Quaternion
{
    float w, x, y, z;
    void FUN_00a6df40(const Transform& matrix);
};
struct __declspec(align(16)) FourFloatVector
{
    float elements[4];
    void FUN_005611c0();
};
struct SceneObject;
struct CastObject
{
    int unk00, unk04, unk08, unk0c;
    SceneObject* unk10;
    SceneObject* GetBody()
    {
        if (this)
            return unk10;
        return 0;
    }
    CastObject* FUN_00653290(const void* type);
};
struct SceneObject
{
    void** vtable;
    int unk04, unk08, unk0c, unk10, unk14;
    SceneObject* unk18;
    CastObject* unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c,
        unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94;
    float unk98;
};
struct Wrapper
{
    int unk00, unk04;
    SceneObject* unk08;
    int unk0c;
    SceneObject* unk10;
    SceneObject* GetSource()
    {
        if (this)
            return unk08;
        return 0;
    }
    SceneObject* GetDestination()
    {
        if (this)
            return unk10;
        return 0;
    }
};
struct LockObject
{
    unsigned int owner;
    unsigned int count;
    void Lock(const char*);
};

extern char DAT_012043f8;
extern unsigned int DAT_01267b80;
extern unsigned int DAT_01267b84;

Wrapper* __cdecl FUN_00c802d0(SceneObject*);
void __cdecl AccumulateParentTransforms(SceneObject*, SceneObject*, Transform*);
void __cdecl FUN_00624ad0(Transform*, FnvMat4*);
void __cdecl FUN_004a3e00(FourFloatVector&, const Vec3&);

// @fnv 0x00c88520
void __cdecl FUN_00c88520(SceneObject* a0, SceneObject* a1)
{
    Wrapper* p = a0 ? FUN_00c802d0(a0) : 0;
    SceneObject* source = p->GetSource();
    _ReadWriteBarrier();
    SceneObject* destination = p->GetDestination();
    CastObject* cast = a1 && a1->unk1c ? a1->unk1c->FUN_00653290(&DAT_012043f8) : 0;
    _ReadWriteBarrier();
    SceneObject* body = cast->GetBody();
    if (destination && body && source && a1 && a1->unk18)
    {
        FnvMat4 world;
        Transform converted;
        Transform relative;
        ((void(__thiscall*)(SceneObject*, FnvMat4*))body->vtable[61])(body, &world);
        FUN_00624ad0(&converted, &world);
        converted.scale = a1->unk98;
        AccumulateParentTransforms(source, a1, &relative);
        Transform combined = converted.FUN_0062c250(relative);
        Quaternion q;
        q.FUN_00a6df40(combined);
        __m128 position;
        FUN_004a3e00(*reinterpret_cast<FourFloatVector*>(&position), combined.translate);
        __m128 rotation;
        rotation.m128_f32[0] = q.x;
        rotation.m128_f32[1] = q.y;
        rotation.m128_f32[2] = q.z;
        rotation.m128_f32[3] = q.w;
        reinterpret_cast<FourFloatVector*>(&rotation)->FUN_005611c0();
        reinterpret_cast<LockObject*>(&DAT_01267b80)->Lock(0);
        ((void(__thiscall*)(SceneObject*, FourFloatVector*, FourFloatVector*))destination->vtable[58])(
            destination, reinterpret_cast<FourFloatVector*>(&position), reinterpret_cast<FourFloatVector*>(&rotation));
        if (--DAT_01267b84 == 0)
            DAT_01267b80 = 0;
    }
}
}  // namespace fnv_00c88520

#include <string.h>
extern __declspec(thread) int g_tlsMemContext;
inline int GetMemContext()
{
    return g_tlsMemContext;
}
inline void SetMemContext(int aiMemoryContext)
{
    g_tlsMemContext = aiMemoryContext;
}
struct MemContextGuard
{
    int m_iSaved;
    MemContextGuard(int aiMemoryContext)
    {
        m_iSaved = GetMemContext();
        SetMemContext(aiMemoryContext);
    }
    ~MemContextGuard()
    {
        SetMemContext(m_iSaved);
    }
};
struct StrArr
{
    void** vtable;
    char** data;
    unsigned short capacity, size, used, growBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
    __forceinline void Add(char* value)
    {
        unsigned int index = size;
        if (index >= capacity)
            SetSize(index + growBy);
        SetAt(index, value);
    }
    __forceinline void Append(char* value)
    {
        unsigned int index = size;
        if (index >= capacity)
            SetSize(index + growBy);
        if (index >= size)
        {
            size = (unsigned short)(index + 1);
            if (value)
                ++used;
        }
        else if (value)
        {
            if (!data[index])
                ++used;
        }
        else if (data[index])
        {
            --used;
        }
        data[index] = value;
    }
};
struct BaseCall
{
    void** vtable;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    void FUN_00a6d830(StrArr*);
};
class NiPoint3
{
  public:
    float x, y, z;
};
struct KeyData : BaseCall
{
    NiPoint3* keys;
    unsigned int unk40, unk44;
    unsigned int count;
    void FUN_00c9bbb0(StrArr* strings);
};
class GlobalObjectO2_00a7b610
{
  public:
    const char* name;
};
extern GlobalObjectO2_00a7b610 g_012681f0;
char* FUN_00a7d330(const char*);
char* FUN_00a7d510(const char*, unsigned int);
int _sprintf_s(char*, unsigned int, const char*, ...);
int _strcpy_s(char*, unsigned int, const char*);
class MemoryManager
{
  public:
    void* Allocate(unsigned int);
};
extern MemoryManager g_memoryManager;

// @fnv 0x00c9bbb0
void KeyData::FUN_00c9bbb0(StrArr* strings)
{
    MemContextGuard kGuard(16);
    FUN_00a6d830(strings);
    strings->Add(FUN_00a7d330(g_012681f0.name));
    unsigned int uiNumKeys = count;
    strings->Add(FUN_00a7d510("iKeys", uiNumKeys));
    for (unsigned int i = 0; i < count; ++i)
    {
        char buffer[64];
        const NiPoint3& kKey = keys[i];
        _sprintf_s(buffer, 64, "Key%d: %.4f, %.4f, %.4f", i, kKey.x, kKey.y, kKey.z);
        unsigned int length = strlen(buffer) + 1;
        char* copy = (char*)g_memoryManager.Allocate(length);
        _strcpy_s(copy, length, buffer);
        strings->Append(copy);
    }
}

struct TlsBlock
{

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

    unsigned int context;
};

extern __declspec(thread) TlsBlock tlsBlock;

struct ContextScope
{

    unsigned int previous;

    ContextScope(unsigned int value)
    {
        previous = tlsBlock.context;
        tlsBlock.context = value;
    }

    ~ContextScope()
    {
        tlsBlock.context = previous;
    }
};

struct TypeInfo
{
    const char* name;
    TypeInfo* parent;
};

extern TypeInfo DAT_0126818c, DAT_01268158, DAT_012681f0, DAT_01267e64;

extern const float DAT_01050de4, DAT_0101e2bc, DAT_01016248, DAT_01017718, DAT_01011d78;

struct __declspec(align(16)) Transform
{

    __m128 rotation0, rotation1, rotation2, translation;

    Transform()
    {}

    __forceinline Transform(const Transform& r)
    {
        __m128 a = r.rotation0, b = r.rotation1, c = r.rotation2, d = r.translation;
        rotation0 = a;
        rotation1 = b;
        rotation2 = c;
        translation = d;
    }

    void FUN_00cb2fc0();
};

struct Point3
{
    float x, y, z;
};

struct NiTransformLocal
{
    float r00, r01, r02, r10, r11, r12, r20, r21, r22;
    Point3 translation;
    float scale;
};

struct Backend
{
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

    Transform transform;
};

struct PhysicsObject;

struct PhysicsList
{
    PhysicsObject* object;
    PhysicsList* next;
    void PopAndRelease();
};

struct World;

struct Filter
{
    unsigned int value;
    __forceinline void Layer(unsigned x)
    {
        value = (value & ~0x7f) | (x & 0x7f);
    }
};

struct PhysicsObject
{

    virtual void slot00();

    virtual void slot04();

    virtual TypeInfo* GetType();

    virtual void slot0c();

    virtual void slot10();

    virtual void slot14();

    virtual void slot18();

    virtual void slot1c();

    virtual int GetKind();

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

    virtual World* GetWorld();

    virtual void slot98();

    virtual void slot9c();

    virtual void Detach();

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

    virtual void SetMotion(int);

    int unk04;

    Backend* underlying;

    PhysicsObject** alternate;

    int unk10;

    PhysicsList objects;

    int GetLinkedRecordValue();

    void* FUN_00c87a40();

    int FUN_00517630();

    void FUN_00c8ef80(void*);

    __declspec(noalias) Filter FUN_0043b4f0();

    void FUN_00626cb0(unsigned int);

    bool FUN_008cffa0();

    void UpdateMatchingNodes(World*);
};

struct Key
{
    float time, value, tangent;
};

struct Controller
{
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

    Key* keys;
    int unk40, unk44;
    unsigned int count;
};

struct SceneNode;

struct CollisionWrapper
{
    int unk00, unk04;
    SceneNode* host;
    int unk0c;
    PhysicsObject* body;
};

struct SceneNode
{
    int unk00, unk04;
    SceneNode* host;
    int unk0c;
    PhysicsObject* body;

    unsigned int unk014;

    unsigned int unk018;

    unsigned int unk01c;

    unsigned int unk020;

    World* world;

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

    NiTransformLocal transform;

    Controller* FUN_00a5c570(TypeInfo*);
};

struct World
{
    void FUN_0056d2c0(PhysicsObject*);
};

struct ConstraintData
{
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

    float strength;
    int unkc0;
    float tau, damping;

    void FUN_00cb8b60(Transform*, Transform*, __m128*, __m128*);
};

class hkSerializableCinfo
{

  public:
    ConstraintData* data;

    int references, unkc, unk10;

    __forceinline hkSerializableCinfo() : data(0), references(1), unkc(0), unk10(0)
    {}
};

struct hkConstraintCinfo : hkSerializableCinfo
{

    __forceinline hkConstraintCinfo()
    {}

    virtual __forceinline ~hkConstraintCinfo()
    {
        SetChildObject(0);
    }

    void SetChildObject(int);
};

struct hkLimitedHingeConstraintCinfo : hkConstraintCinfo
{

    __forceinline hkLimitedHingeConstraintCinfo()
    {}

    virtual __forceinline ~hkLimitedHingeConstraintCinfo()
    {}

    void FUN_00caa3f0();

    void FUN_009ba320(PhysicsObject*, PhysicsObject*);
};

typedef hkLimitedHingeConstraintCinfo ConstraintInfo;

void* FUN_00aa13e0(unsigned int);

void FUN_00aa1450(void*);

struct FUN_00c88380
{

    int* vtable;
    int references;
    void* object;
    int unk0c;

    static void* operator new(unsigned int n)
    {
        return FUN_00aa13e0(n);
    }

    static void operator delete(void* p)
    {
        FUN_00aa1450(p);
    }

    FUN_00c88380(ConstraintInfo*);
};

void FUN_00c88520(SceneNode*, SceneNode*);

CollisionWrapper* FUN_00c802d0(SceneNode*);

__declspec(noalias) unsigned char FUN_00c8cce0(int*);

Transform* FUN_0056df80(Transform*, NiTransformLocal*);

World* FUN_00621480(World*);

SceneNode* FUN_00653270(TypeInfo*, CollisionWrapper*);

void UpdateChainCollision(SceneNode*, World*);

static __forceinline void Normalize3(__m128& v)
{

    __m128 h = _mm_set_ss(0.5f), t = _mm_set_ss(3.0f), z = _mm_set_ss(0.0f);
    __m128 p = _mm_mul_ps(v, v);

    __m128 a = _mm_shuffle_ps(p, p, 0x55);

    __m128 b = _mm_add_ss(a, p);

    __m128 n = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), b);

    __m128 mask = _mm_cmpeq_ss(n, z);

    __m128 r = _mm_rsqrt_ss(n);

    __m128 result = _mm_andnot_ps(mask, _mm_mul_ss(_mm_mul_ss(h, r), _mm_sub_ss(t, _mm_mul_ss(_mm_mul_ss(n, r), r))));

    v = _mm_mul_ps(v, _mm_shuffle_ps(result, result, 0));
}

union AxisVector
{
    struct
    {
        float x, y, z, w;
    } f;
    __m128 q;
};

static __forceinline PhysicsObject* AsType(PhysicsObject* object, TypeInfo* target)
{

    TypeInfo* type = object->GetType();

    while (type)
    {
        if (type == target)
            return object;
        type = type->parent;
    }

    return 0;
}

__forceinline unsigned char DynamicValue(const int& m)
{
    return FUN_00c8cce0(const_cast<int*>(&m));
}
// @fnv 0x00c88a40
void __cdecl FUN_00c88a40(bool create, Filter filter, SceneNode* first, SceneNode* second, bool force)
{

    ContextScope contextScope(16);

    if (!first || !second)
        return;

    {

        FUN_00c88520(first, second);

        CollisionWrapper* __restrict resolvedFirst = FUN_00c802d0(first);

        CollisionWrapper* resolvedSecond = FUN_00c802d0(second);

        if (resolvedFirst && resolvedSecond)
        {
            PhysicsObject* sourceBody = resolvedFirst->body;

            PhysicsObject* targetBody;

            targetBody = resolvedSecond->body;

            PhysicsList* listEntry;

            listEntry = &sourceBody->objects;

            bool skipped;

            skipped = false;

            while (listEntry)
            {

                PhysicsObject* listObject = listEntry->object;

                if (!listObject)
                    break;

                if (AsType(listObject, &DAT_0126818c))
                {

                    PhysicsObject* body;

                    body = listObject->underlying ? (PhysicsObject*)listObject->underlying->unk00c
                                                  : (listObject->alternate ? *listObject->alternate : 0);

                    if (body->GetKind() > 100 || body->GetKind() == 18 || body->GetKind() == 19)
                    {

                        skipped = true;

                        listEntry = listEntry->next;

                        continue;
                    }

                    if (listObject->GetLinkedRecordValue())
                        listObject->Detach();
                }
                else
                {

                    if (AsType(listObject, &DAT_01268158) && listObject->FUN_00c87a40())
                        listObject->Detach();
                }

                listEntry->PopAndRelease();
            }

            if (create)
            {

                ConstraintInfo info;

                info.FUN_00caa3f0();

                if (force)
                    sourceBody->SetMotion(4);

                else
                {

                    int sourceMotion = sourceBody->FUN_00517630();

                    int targetMotion = targetBody->FUN_00517630();

                    if (FUN_00c8cce0(&sourceMotion) != FUN_00c8cce0(&targetMotion))
                    {

                        long motionType;

                        Controller* controller = resolvedSecond->host->FUN_00a5c570(&DAT_012681f0);

                        if (controller && controller->count)
                        {

                            if (controller->keys[controller->count - 1].value < 1.0f)
                                motionType = 1;

                            else
                                motionType = 4;
                        }
                        else
                        {

                            motionType = DynamicValue(targetBody->FUN_00517630()) ? 1 : 4;
                        }

                        sourceBody->SetMotion(motionType);
                    }
                }

                info.FUN_009ba320(sourceBody, targetBody);

                Transform sourceTransform = (sourceBody ? sourceBody->underlying : 0)->transform;

                Transform targetTransform = (targetBody ? targetBody->underlying : 0)->transform;

                Transform convertedTransform;

                FUN_0056df80(&convertedTransform, &first->transform);

                sourceTransform.FUN_00cb2fc0();

                targetTransform.FUN_00cb2fc0();

                info.data->tau = DAT_01050de4;

                info.data->damping = 0.1f;

                info.data->strength = 1.0f;

                Point3 direction;

                direction.x = resolvedFirst->host->transform.r00;

                direction.y = resolvedFirst->host->transform.r10;

                direction.z = resolvedFirst->host->transform.r20;

                AxisVector axis;

                axis.f.x = direction.x;

                axis.f.y = direction.y;

                axis.f.z = direction.z;

                axis.f.w = 0.0f;

                Normalize3(axis.q);

                info.data->FUN_00cb8b60(&sourceTransform, &targetTransform, &sourceTransform.translation, &axis.q);

                FUN_00c88380* newConstraint = new FUN_00c88380(&info);

                sourceBody->FUN_00c8ef80(newConstraint);

                Filter sourceFilter = sourceBody->FUN_0043b4f0();

                unsigned layer = targetBody->FUN_0043b4f0().value & 0x7f;

                unsigned bits = (sourceFilter.value & 0xe080) | (filter.value & 0xffff1400) | 0x1400;

                bits = (bits & ~0x7f) | (layer & 0x7f);

                sourceBody->FUN_00626cb0(bits);

                World* world = FUN_00621480(targetBody->GetWorld());

                if (!world)
                {

                    SceneNode* fallbackNode;

                    fallbackNode = FUN_00653270(&DAT_01267e64, resolvedSecond);

                    if (fallbackNode)
                        world = fallbackNode->world;
                }

                if (world && targetBody->FUN_008cffa0())
                {

                    if (!sourceBody->GetWorld())
                        world->FUN_0056d2c0(sourceBody);

                    else
                        sourceBody->UpdateMatchingNodes(world);
                }

                if (skipped)
                    UpdateChainCollision(first, world);

                return;
            }

            return;
        }
        if (!resolvedFirst)
            return;
    }
}

class NiAVObject;
struct KnockDownNode;
struct CollisionObject;
struct RigidBody;
class NiTimeController;
struct PhysicsBody;
class NiRTTI;

struct hkVector4
{
    __m128 v;
};
class NiPoint3_helper : public NiPoint3
{
  public:
    NiPoint3 operator*(float scale) const;
};
struct bhkFilter
{
    unsigned int value;
};
struct VirtualObject
{
    virtual void VirtualUnknown00();
    virtual void VirtualUnknown04();
    virtual void VirtualUnknown08();
    virtual KnockDownNode* GetNode();
    virtual void VirtualUnknown10();
    virtual void VirtualUnknown14();
    virtual void VirtualUnknown18();
    virtual void VirtualUnknown1c();
    virtual void VirtualUnknown20();
    virtual void VirtualUnknown24();
    virtual void VirtualUnknown28();
    virtual void VirtualUnknown2c();
    virtual void VirtualUnknown30();
    virtual void VirtualUnknown34();
    virtual void VirtualUnknown38();
    virtual void VirtualUnknown3c();
    virtual void VirtualUnknown40();
    virtual void VirtualUnknown44();
    virtual void VirtualUnknown48();
    virtual void VirtualUnknown4c();
    virtual void VirtualUnknown50();
    virtual void VirtualUnknown54();
    virtual void VirtualUnknown58();
    virtual void VirtualUnknown5c();
    virtual void VirtualUnknown60();
    virtual void VirtualUnknown64();
    virtual void VirtualUnknown68();
    virtual void VirtualUnknown6c();
    virtual void VirtualUnknown70();
    virtual void VirtualUnknown74();
    virtual void VirtualUnknown78();
    virtual void VirtualUnknown7c();
    virtual void VirtualUnknown80();
    virtual void VirtualUnknown84();
    virtual void VirtualUnknown88();
    virtual void Update(float);
    virtual void VirtualUnknown90();
    virtual void VirtualUnknown94();
    virtual void VirtualUnknown98();
    virtual void VirtualUnknown9c();
    virtual void VirtualUnknowna0();
    virtual void VirtualUnknowna4();
    virtual void VirtualUnknowna8();
    virtual void VirtualUnknownac();
    virtual void SetMotion(int, int, int);
    virtual void VirtualUnknownb4();
    virtual void VirtualUnknownb8();
    virtual void VirtualUnknownbc();
    virtual void VirtualUnknownc0();
    virtual void VirtualUnknownc4();
    virtual void VirtualUnknownc8();
    virtual void VirtualUnknowncc();
    virtual void VirtualUnknownd0();
    virtual void VirtualUnknownd4();
    virtual void VirtualUnknownd8();
    virtual void VirtualUnknowndc();
    virtual void VirtualUnknowne0();
    virtual void SetBodyMotion(int);
};
struct PhysicsBody
{
    void* unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int filterInfo;
};
struct RigidBody : public VirtualObject
{
    unsigned int unk04;
    PhysicsBody* body;
    bhkFilter FUN_0043b4f0();
    unsigned int GetFilter();
};
struct CollisionObject : public VirtualObject
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    RigidBody* rigidBody;
    unsigned int unk14;
    float beginValue, endValue;
    void ApplyMotion();
};
class NiObject : public VirtualObject
{
  public:
    NiObject* DynamicCast(const NiRTTI* rtti);
};
class NiAVObject : public VirtualObject
{
  public:
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    NiObject* collision;
    NiTimeController* GetController(const NiRTTI* rtti);
};
struct KnockDownNode
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
    NiAVObject** children;
    unsigned short capacity, childCount;
};
struct NiInterpControllerTriple
{
    float time, value, tangent;
    NiInterpControllerTriple();
};
struct ControllerKeys
{
    void* vtable;
    NiInterpControllerTriple* data;
    unsigned int capacity, size, effectiveSize, growBy;
    void Reserve(unsigned int count);
};
class NiTimeController : public VirtualObject
{
  public:
    unsigned int unk04;
    unsigned short flags, unk0a;
    float frequency, phase, startTime, stopTime;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    ControllerKeys keys;
    float unk50, unk54;
    unsigned int mode;
    void Reset();
    void AddKey(const NiInterpControllerTriple& key);
};
struct BodyState
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    PhysicsBody physics;
};
inline unsigned int RigidBody::GetFilter()
{
    BodyState* state = (BodyState*)body;
    if (state)
    {
        PhysicsBody* physics = &state->physics;
        if (physics)
            return physics->filterInfo;
    }
    return 0;
}
extern unsigned int DAT_012683f4;
extern float DAT_011b1210[32];
extern float DAT_01015f5c, DAT_011b0f88, DAT_011b0f8c, DAT_011afe64;
hkVector4& FUN_004a3e00(hkVector4& result, const NiPoint3& point);
void FUN_00cb94a0(NiAVObject* object, const hkVector4& velocity, float scale);
struct PhysicsMotion
{
    void ApplyImpulse(float duration, const hkVector4& velocity);
};
inline void* operator new(unsigned int, void* p)
{
    return p;
}
inline void* operator new[](unsigned int, void* p)
{
    return p;
}
struct PlainKey
{
    float time, value, tangent;
};
union KeyVectorStorage
{
    PlainKey keys[2];
    hkVector4 vector;
};
// @fnv 0x00c9b670
void __cdecl FUN_00c9b670(NiAVObject* object, const NiPoint3& velocity, unsigned int context, float time, bool disable)
{
    NiPoint3 sharedPoint;
    KeyVectorStorage work;
    if (object)
    {
        CollisionObject* collision = 0;
        if (object->collision)
            collision = (CollisionObject*)object->collision->DynamicCast((const NiRTTI*)&DAT_01267e64);
        if (collision)
        {
            collision->ApplyMotion();
            unsigned int filter = 0;
            if (collision->rigidBody)
                filter = collision->rigidBody->GetFilter();
            float speed = DAT_011b1210[(filter >> 8) & 31];
            NiTimeController* controller = object->GetController((const NiRTTI*)&DAT_012681f0);
            if (controller && speed >= 0.0f)
            {
                if (!disable)
                {
                    float begin = collision->beginValue;
                    float end = collision->endValue;
                    controller->Reset();
                    unsigned int count = 2;
                    controller->mode = count;
                    if (controller->keys.effectiveSize == 0)
                    {
                        NiInterpControllerTriple* values = new (&work.keys) NiInterpControllerTriple[2];
                        values[0].value = begin;
                        values[0].tangent = end;
                        values[0].time = 0.0f;
                        values[1].value = 0.0f;
                        values[1].tangent = 0.0f;
                        values[1].time = speed;
                        controller->keys.Reserve(2);
                        NiInterpControllerTriple* p = values;
                        do
                        {
                            controller->AddKey(*p);
                            ++p;
                        } while (--count != 0);
                        controller->startTime = time;
                        controller->stopTime = speed;
                        controller->flags = (controller->flags & 0xfef5) | 0xc5;
                        controller->phase = 0.0f;
                        controller->frequency = 1.0f;
                        controller->Update(DAT_01015f5c);
                    }
                    NiAVObject* active = const_cast<NiAVObject* volatile&>(object);
                    if (!active->GetController((const NiRTTI*)&DAT_012683f4))
                    {
                        new (&sharedPoint) NiPoint3(static_cast<const NiPoint3_helper&>(velocity) * DAT_011b0f88);
                        NiPoint3& scaled = sharedPoint;
                        FUN_00cb94a0(active, FUN_004a3e00(work.vector, scaled), DAT_011b0f8c);
                    }
                }
                else
                {
                    collision->SetMotion(1, 0, 0);
                }
            }
        }
        else if (object->collision)
        {
            CollisionObject* fallback = (CollisionObject*)object->collision->DynamicCast((const NiRTTI*)&DAT_012043f8);
            if (fallback && fallback->rigidBody)
            {
                RigidBody* body = fallback->rigidBody;
                unsigned int filter = body->FUN_0043b4f0().value;
                unsigned int layer = filter & 0x7f;
                if ((layer != 8 && layer != 29) || (filter & 0x1f00) == 0x1400)
                {
                    body->SetBodyMotion(1);
                    if (!disable)
                    {
                        new (&sharedPoint) NiPoint3(static_cast<const NiPoint3_helper&>(velocity) * DAT_011b0f88);
                        NiPoint3& scaled = sharedPoint;
                        ((PhysicsMotion*)body->body)->ApplyImpulse(DAT_011afe64, FUN_004a3e00(work.vector, scaled));
                    }
                }
            }
        }
        KnockDownNode* node = object->GetNode();
        if (node)
        {
            for (unsigned int i = 0; i < node->childCount; ++i)
                FUN_00c9b670(node->children[i], velocity, context, time, disable);
        }
    }
}
