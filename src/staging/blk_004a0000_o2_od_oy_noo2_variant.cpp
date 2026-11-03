
// src/staging/blk_004a0000_o2_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /Od /Oy- /GS /EHsc /Gy (unit src/staging/blk_004a0000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

// src/staging/blk_004a0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

class NiPoint3
{
  public:
    union
    {
        struct
        {
            float x, y, z;
        };
        float components[3];
    };
    NiPoint3();
    NiPoint3(float, float, float);
    NiPoint3 ApplyScaled(float) const;
    NiPoint3 FUN_00439e90(const NiPoint3&) const;
    NiPoint3 FUN_00439ef0(const NiPoint3&) const;
    void FUN_004a0c10();
};
struct __declspec(align(16)) ImpactVector4
{
    union
    {
        struct
        {
            float x, y, z, w;
        };
        float components[4];
    };
};
struct HitBody;
struct ImpactHit
{
    ImpactVector4 normal;
    float fraction;
    int unk14, unk18, unk1c;
    unsigned int keys[8];
    int unk40, unk44, unk48, unk4c;
    HitBody* body;
    int unk54, unk58, unk5c;
};
struct HitArray
{
    ImpactHit* GetEntryAt(int);
    int FUN_00726070();
};
struct HitHolder
{
    HitArray* FUN_00460140();
};
struct FUN_004a3c20
{
    ImpactVector4 from, to;
    int filter, unk24, unk28, unk2c;
    ImpactVector4 normal;
    float fraction;
    int shapeKey, unk48, unk4c;
    unsigned int keys[8];
    int unk70, unk74, unk78, unk7c;
    HitBody* body;
    int unk84, unk88, unk8c;
    ImpactVector4 transform;
    int unkA0, unkA4, unkA8;
    bool flag;
    FUN_004a3c20();
    void FUN_004a3f70(unsigned int);
    void FUN_004a3da0(const NiPoint3&);
    void FUN_004a3eb0(const NiPoint3&);
    void FUN_004a3fb0(void*);
    HitHolder* FUN_008cdd90();
};
struct FUN_004a3a70
{
    unsigned int vtable;
    float earlyOut;
    int unk08, unk0c;
    unsigned int data;
    int size, capacity, unk1c;
    unsigned char hitStorage[8 * sizeof(ImpactHit)];
    FUN_004a3a70();
    ~FUN_004a3a70();
};
struct FUN_008c71b0
{
    unsigned int value;
    FUN_008c71b0(unsigned int);
    void FUN_004a39f0(int);
    unsigned int FUN_004a3a20();
};
struct FUN_004a37b0
{
    NiPoint3 position, normal, tangent;
    int unk24;
    void* reference;
    int unk2c;
    void* texture;
    int unk34;
    float width, height, depth, lifetime;
    int unk48;
    float radius;
    int unk50;
    float parallax, shininess, scale;
    NiPoint3 color;
    int unk6c;
    unsigned char rotation, unk71, unk72, flag73, flag74, flag75, flag76, unk77;
    int unk78, unk7c;
    FUN_004a37b0();
};
struct World
{
    void** vtable;
};
struct Cell
{
    World* FUN_004543c0();
};
struct Prompt
{
    void FUN_00476930(int, NiPoint3&);
};
struct Scene
{
    Prompt* FUN_006a9540();
    NiPoint3& FUN_0043c490();
};
struct Ref
{
    Cell* FUN_0084e3a0();
    Scene* FUN_00490e40();
    float FUN_00621b00();
    float FUN_00488d50();
    Ref* FUN_009611e0();
    void FUN_004a3fe0(FUN_004a37b0*, int, char);
};
struct RefHandle
{
    Ref* FUN_00559450();
};
struct HitBody
{
    RefHandle shape;
    unsigned int FUN_0043b540();
};
struct Shape
{
    unsigned int FUN_00c84f10(unsigned int);
};
struct ImpactData
{
    float GetModifierValue();
    float FUN_004a40a0();
    void* FUN_006733e0();
    bool FUN_004a4100();
    float FUN_004a41c0();
    bool FUN_004a41e0();
    bool CallMemberAtOffset54();
    bool FUN_004a4140();
    float FUN_004a40e0();
    float FUN_009a9350();
    float FUN_00598040();
    unsigned int GetNextFromSubobject();
};
struct Gate
{
    bool IsConsoleOpen();
};
Gate* __cdecl FUN_0071b160(int);
bool __cdecl IsStartMenuFlag1Set();
float __cdecl FUN_00476b70(float, float);
struct Splatter
{
    void FUN_006233c0(int);
    void FUN_004a1a10(int, unsigned char);
    void FUN_006231a0(World*);
};
Splatter* __cdecl FUN_00622a70(float, bool);
struct FloatSetting
{
    float* FUN_00403e20();
};
struct IntSetting
{
    int* FUN_0043d4d0();
};
extern FloatSetting DAT_011c5818, DAT_011c584c;
extern IntSetting DAT_011c5868;
extern const float DAT_01017868, DAT_0101e578, DAT_01018f5c, DAT_0101e574, DAT_0101e570;
struct ImageSpaceEffectParam
{
    float r, g, b, a;
    ImageSpaceEffectParam(float, float, float, float);
};
void* __cdecl FUN_004b3890(const NiPoint3&, const ImageSpaceEffectParam&, const NiPoint3&, const ImageSpaceEffectParam&,
                           bool);
struct TESView
{
    void FUN_00458e20(void*, float);
    Ref* FUN_00457620(const NiPoint3&);
    Ref* FUN_004519d0(NiPoint3);
};
extern TESView* g_TES;
Shape* __cdecl FUN_004a3a40(Ref*);
NiPoint3 __cdecl FUN_004a3760(float, const NiPoint3&);
NiPoint3& __cdecl FUN_004a3970(NiPoint3&, const ImpactVector4&);
Ref* __cdecl FUN_00c7fa90(HitBody*);
void* __cdecl FUN_0056f930(Ref*);
bool __cdecl IsAcousticSpaceFormTypeAllowed(void*, bool);
float __cdecl FUN_004a4240();
float __cdecl FUN_00406cc0(float);
struct ImpactTask
{
    int remaining;
    bool finished;
    unsigned char unk05;
    unsigned short unk06;
    ImpactData* impact;
    RefHandle reference;
    void FUN_004a2d50();
};
// @fnv 0x004a2d50
void ImpactTask::FUN_004a2d50()
{
    if (FUN_0071b160(1)->IsConsoleOpen() || IsStartMenuFlag1Set())
        return;
    if (!reference.FUN_00559450()->FUN_0084e3a0() || !reference.FUN_00559450()->FUN_00490e40())
    {
        finished = true;
        return;
    }
    if (remaining > 0 && impact && reference.FUN_00559450()->FUN_00621b00() <= reference.FUN_00559450()->FUN_00488d50())
    {
        NiPoint3 direction;
        reference.FUN_00559450()->FUN_00490e40()->FUN_006a9540()->FUN_00476930(2, direction);
        direction.FUN_004a0c10();
        NiPoint3 origin = reference.FUN_00559450()->FUN_00490e40()->FUN_0043c490();
        float radius = FUN_00476b70(impact->FUN_004a40a0(), impact->GetModifierValue());
        Splatter* splatter = FUN_00622a70(radius, true);
        splatter->FUN_006233c0(0);
        splatter->FUN_004a1a10(8, 0);
        splatter->FUN_004a1a10(29, 0);
        Cell* cell = reference.FUN_00559450()->FUN_0084e3a0();
        World* world = cell ? cell->FUN_004543c0() : 0;
        FUN_004a3c20 ray;
        if (world)
        {
            splatter->FUN_006231a0(world);
            float distance = *DAT_011c5818.FUN_00403e20();
            NiPoint3 end = origin.FUN_00439e90(direction.ApplyScaled(distance));
            end.x += FUN_00476b70(DAT_0101e578, DAT_01017868);
            end.y += FUN_00476b70(DAT_0101e578, DAT_01017868);
            end.z += FUN_00476b70(DAT_0101e578, DAT_01017868);
            float drop = -*DAT_011c584c.FUN_00403e20() *
                         (reference.FUN_00559450()->FUN_00621b00() / reference.FUN_00559450()->FUN_00488d50());
            end.z += drop;
            if (*DAT_011c5868.FUN_0043d4d0() > 0)
            {
                void* line = FUN_004b3890(origin, ImageSpaceEffectParam(0, 1, 0, 1), end,
                                          ImageSpaceEffectParam(0, 1, 1, 1), true);
                g_TES->FUN_00458e20(line, DAT_01018f5c);
            }
            FUN_008c71b0 filter(0);
            filter.FUN_004a39f0(39);
            ray.FUN_004a3f70(filter.value);
            ray.FUN_004a3da0(origin);
            ray.FUN_004a3eb0(end);
            FUN_004a3a70 collector;
            ray.FUN_004a3fb0(&collector);
            bool rayHit = ((bool(__thiscall*)(World*, FUN_004a3c20*))world->vtable[50])(world, &ray);
            int count = ray.FUN_008cdd90()->FUN_00460140()->FUN_00726070();
            bool placed = false;
            for (int hit = 0; !placed && hit < count; ++hit)
            {
                HitBody* body = ray.FUN_008cdd90()->FUN_00460140()->GetEntryAt(hit)->body;
                if (body)
                {
                    unsigned int key = -1;
                    for (int keyIndex = 0;
                         keyIndex < 8 && ray.FUN_008cdd90()->FUN_00460140()->GetEntryAt(hit)->keys[keyIndex] != -1;
                         ++keyIndex)
                    {
                        key = ray.FUN_008cdd90()->FUN_00460140()->GetEntryAt(hit)->keys[keyIndex];
                    }
                    Shape* shape = FUN_004a3a40(body->shape.FUN_00559450());
                    if (!shape)
                        continue;
                    unsigned int material = shape->FUN_00c84f10(key);
                    void* texture = impact ? impact->FUN_006733e0() : 0;
                    if (!texture)
                        continue;
                    NiPoint3 position = origin.FUN_00439e90(FUN_004a3760(
                        ray.FUN_008cdd90()->FUN_00460140()->GetEntryAt(hit)->fraction, end.FUN_00439ef0(origin)));
                    NiPoint3 normal;
                    FUN_004a3970(normal, ray.FUN_008cdd90()->FUN_00460140()->GetEntryAt(hit)->normal);
                    bool landscape = FUN_008c71b0(body->FUN_0043b540()).FUN_004a3a20() == 1;
                    Ref* target = 0;
                    if (landscape)
                    {
                        target = g_TES->FUN_00457620(position);
                        if (target && target->FUN_009611e0())
                            target = target->FUN_009611e0();
                    }
                    else
                        target = FUN_00c7fa90(body);
                    void* object = FUN_0056f930(target);
                    if (!landscape && (!object || !IsAcousticSpaceFormTypeAllowed(object, true)))
                        continue;
                    Ref* owner = g_TES->FUN_004519d0(position);
                    FUN_004a37b0 decal;
                    decal.position = position;
                    decal.normal = normal;
                    decal.width = radius;
                    decal.height = radius;
                    decal.depth = DAT_0101e574;
                    decal.lifetime = FUN_004a4240();
                    decal.rotation = (unsigned char)(int)FUN_00406cc0(FUN_00476b70(0, DAT_0101e570));
                    decal.reference = target;
                    decal.texture = texture;
                    decal.flag73 = impact->FUN_004a4100();
                    decal.radius = impact->FUN_004a41c0();
                    decal.flag76 = impact->FUN_004a41e0();
                    decal.flag74 = impact->CallMemberAtOffset54();
                    decal.flag75 = impact->FUN_004a4140();
                    decal.parallax = impact->FUN_004a40e0();
                    decal.shininess = impact->FUN_009a9350();
                    decal.scale = impact->FUN_00598040();
                    decal.color =
                        NiPoint3((unsigned char)(impact->GetNextFromSubobject() & 255) / 255.0,
                                 (unsigned char)(((unsigned short)impact->GetNextFromSubobject() >> 8) & 255) / 255.0,
                                 (unsigned char)((impact->GetNextFromSubobject() >> 16) & 255) / 255.0);
                    owner->FUN_004a3fe0(&decal, 1, 0);
                    placed = true;
                }
            }
            if (placed)
                --remaining;
        }
    }
    else
        finished = true;
}

#include <xmmintrin.h>
struct FUN_004b4cf0_shell
{
    __m128* FUN_004b4cf0(unsigned int index);
};

struct FUN_004b4ab0_Class
{
    __m128 value;
    void FUN_004b4ad0(FUN_004b4cf0_shell* matrix, __m128* vector);
};

// @fnv 0x004b4ad0
void FUN_004b4ab0_Class::FUN_004b4ad0(FUN_004b4cf0_shell* matrix, __m128* vector)
{
    __m128 row0 = *matrix->FUN_004b4cf0(0);
    __m128 row1 = *matrix->FUN_004b4cf0(1);
    __m128 row2 = *matrix->FUN_004b4cf0(2);
    __m128 low = _mm_unpacklo_ps(row0, row1);
    __m128 high = _mm_shuffle_ps(_mm_unpackhi_ps(row0, row1), row2, 0xe4);
    row0 = _mm_movelh_ps(low, row2);
    row1 = _mm_shuffle_ps(_mm_movehl_ps(row0, low), row2, 0xd4);
    row2 = high;
    __m128 sx = _mm_shuffle_ps(*vector, *vector, 0);
    __m128 x = _mm_mul_ps(row0, sx);
    __m128 sy = _mm_shuffle_ps(*vector, *vector, 0x55);
    __m128 y = _mm_mul_ps(row1, sy);
    __m128 sz = _mm_shuffle_ps(*vector, *vector, 0xaa);
    __m128 z = _mm_mul_ps(row2, sz);
    value = _mm_add_ps(_mm_add_ps(x, y), z);
}
