
// src/bshavok/bhkcollisionobject_h_unit_o2_nood_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/bshavok/bhkcollisionobject_h_unit_o2_nood_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/bshavok/bhkcollisionobject_h_unit_o2_nood_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /GS /EHsc /Gy /O2 (unit src/bshavok/bhkcollisionobject_h_unit.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
#include "bhkcollisionobject.h"

#include <xmmintrin.h>

extern __m128 DAT_01267e30;
extern __m128 DAT_01017d10;
extern float DAT_01017d00;

struct Node_00c658c0
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
    __m128 m_kPointA;
    __m128 m_kPointB;
    void OnTrigger(const __m128* v);
    void FUN_00561800(const __m128* v);
};

struct Owner_00c658c0
{
    int unk00;
    int unk04;
    Node_00c658c0* m_node;
    void FUN_00a29680();
};

struct Cls_00c658c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Owner_00c658c0* m_pOwnerObject;
    void FUN_00c658c0();
};

// @fnv 0x00c658c0
void Cls_00c658c0::FUN_00c658c0()
{
    Owner_00c658c0* o = m_pOwnerObject;
    if (o)
    {
        Node_00c658c0* n = o->m_node;
        const __m128* p = n ? &n->m_kPointA : &DAT_01267e30;
        __m128 eps = _mm_shuffle_ps(_mm_load_ss(&DAT_01017d00), _mm_load_ss(&DAT_01017d00), 0);
        __m128 d = _mm_sub_ps(*p, DAT_01267e30);
        __m128 ok = _mm_cmple_ps(_mm_and_ps(d, DAT_01017d10), eps);
        if ((_mm_movemask_ps(ok) & 7) != 7 && n)
        {
            o->FUN_00a29680();
            n->OnTrigger(&DAT_01267e30);
            o->FUN_00a29680();
        }
        n = o->m_node;
        p = n ? &n->m_kPointB : &DAT_01267e30;
        d = _mm_sub_ps(*p, DAT_01267e30);
        ok = _mm_cmple_ps(_mm_and_ps(d, DAT_01017d10), eps);
        if ((_mm_movemask_ps(ok) & 7) != 7 && n)
        {
            o->FUN_00a29680();
            n->FUN_00561800(&DAT_01267e30);
            o->FUN_00a29680();
        }
    }
}

#include <xmmintrin.h>
namespace fnv_00c65b00 {
#include <xmmintrin.h>

class NiPoint3
{
  public:
    float x, y, z;
};
class ThreeByThreeMatrix
{
  public:
    float entry[3][3];
};
struct Transform
{
    ThreeByThreeMatrix rotate;
    NiPoint3 translate;
    float scale;
};
class NiAVObject
{
  public:
    void* vtable;
    int refCount;
    const char* name;
    void* extraData;
    int extraCount;
    void* controller;
    NiAVObject* parent;
    void* collision;
    void* worldBound;
    void* propertyHead;
    void* propertyTail;
    int propertyCount;
    unsigned int flags;
    Transform local;
    Transform world;
    void UpdateWorldLoc();
    unsigned char flagSet(unsigned bit) const
    {
        return (flags >> bit) & 1;
    }
};
struct Quaternion
{
    float w, x, y, z;
    void FUN_00a6df40(const ThreeByThreeMatrix*);
};
struct __declspec(align(16)) FourFloatVector
{
    __m128 quad;
};
struct __declspec(align(16)) HavokQuaternion
{
    float x, y, z, w;
    void FUN_005611c0();
};
void __cdecl FUN_004a3e00(FourFloatVector*, const NiPoint3*);
struct MotionData
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
    unsigned char motionType;
    unsigned char motionFlags;
    unsigned short motionQuality;
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
    FourFloatVector linearVelocity;
    FourFloatVector angularVelocity;
};
struct Body;
struct BodyVTable
{
    void* method00;
    void* method04;
    void* method08;
    void* method0c;
    void* method10;
    void* method14;
    void* method18;
    void* method1c;
    void* method20;
    void* method24;
    void* method28;
    void* method2c;
    void* method30;
    void* method34;
    void* method38;
    void* method3c;
    void* method40;
    void* method44;
    void* method48;
    void* method4c;
    void* method50;
    void* method54;
    void* method58;
    void* method5c;
    void* method60;
    void* method64;
    void* method68;
    void* method6c;
    void* method70;
    void* method74;
    void* method78;
    void* method7c;
    void* method80;
    void* method84;
    void* method88;
    void* method8c;
    void* method90;
    void* method94;
    void* method98;
    void* method9c;
    void* methoda0;
    void* methoda4;
    void* methoda8;
    void* methodac;
    void* methodb0;
    void* methodb4;
    void* methodb8;
    void* methodbc;
    void* methodc0;
    void* methodc4;
    void* methodc8;
    void* methodcc;
    void* methodd0;
    void(__thiscall* getPosition)(Body*, FourFloatVector*);
    void* methodd8;
    void* methoddc;
    void* methode0;
    void* methode4;
    void(__thiscall* SetGeometryTransform)(Body*, const FourFloatVector*, const HavokQuaternion*);
};
struct PhysicsLock
{
    int owner;
    int count;
    void Lock(const char*);
    void unlock()
    {
        if (--count == 0)
            owner = 0;
    }
};
extern PhysicsLock DAT_01267b80;
extern FourFloatVector DAT_01267e30;
extern float DAT_01017d00;
extern FourFloatVector DAT_01017d10;
struct Body
{
    BodyVTable* vtable;
    int refCount;
    MotionData* data;
    void* FUN_00c87a40();
    void FUN_00c8e160(const NiPoint3*, const Quaternion*, PhysicsLock*);
    FourFloatVector* FUN_00560d80();
    FourFloatVector* FUN_00560e10();
    void FUN_00561690(const FourFloatVector*);
    void FUN_005617c0(const FourFloatVector*);
};
char __cdecl FUN_00c8cce0(int*);
struct CollisionSync
{
    void* vtable;
    int refCount;
    NiAVObject* node;
    unsigned short flags;
    Body* body;
    bool FUN_0047b470();
    unsigned char flagSet(unsigned bit) const
    {
        return (flags >> bit) & 1;
    }
    void FUN_00c65b00();
};
__declspec(noinline) FourFloatVector* Body::FUN_00560e10()
{
    FourFloatVector* p = data ? &data->angularVelocity : &DAT_01267e30;
    __m128 m = _mm_and_ps(p->quad, DAT_01017d10.quad);
    __m128 v0 = _mm_mul_ps(_mm_shuffle_ps(m, m, 0), _mm_set1_ps(1.0f));
    __m128 v1 = _mm_mul_ps(_mm_shuffle_ps(m, m, 85), _mm_set1_ps(2.0f));
    __m128 v2 = _mm_mul_ps(_mm_shuffle_ps(m, m, 170), _mm_set1_ps(3.0f));
    __m128 v3 = _mm_mul_ps(_mm_shuffle_ps(m, m, 255), _mm_set1_ps(4.0f));
    __m128 v4 = _mm_mul_ps(_mm_shuffle_ps(m, m, 27), _mm_set1_ps(5.0f));
    __m128 v5 = _mm_mul_ps(_mm_shuffle_ps(m, m, 78), _mm_set1_ps(6.0f));
    __m128 v6 = _mm_mul_ps(_mm_shuffle_ps(m, m, 177), _mm_set1_ps(7.0f));
    __m128 v7 = _mm_mul_ps(_mm_shuffle_ps(m, m, 228), _mm_set1_ps(8.0f));
    __m128 v8 = _mm_mul_ps(_mm_shuffle_ps(m, m, 0), _mm_set1_ps(9.0f));
    __m128 v9 = _mm_mul_ps(_mm_shuffle_ps(m, m, 85), _mm_set1_ps(10.0f));
    __m128 v10 = _mm_mul_ps(_mm_shuffle_ps(m, m, 170), _mm_set1_ps(11.0f));
    __m128 v11 = _mm_mul_ps(_mm_shuffle_ps(m, m, 255), _mm_set1_ps(12.0f));
    __m128 total = _mm_add_ps(
        _mm_add_ps(
            _mm_add_ps(
                _mm_add_ps(
                    _mm_add_ps(
                        _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_add_ps(v0, v1), v2), v3), v4), v5),
                                   v6),
                        v7),
                    v8),
                v9),
            v10),
        v11);
    return _mm_movemask_ps(_mm_cmpeq_ps(total, DAT_01267e30.quad)) == 15 ? &DAT_01267e30 : p;
}
// @fnv 0x00c65b00
void CollisionSync::FUN_00c65b00()
{

    FourFloatVector forcedPos;
    HavokQuaternion forcedQ;
    FourFloatVector distancePos, old;

    HavokQuaternion nearQ;
    FourFloatVector flaggedPos;
    HavokQuaternion flaggedQ;
    NiAVObject* n = node;
    Body* b = body;
    if (!n)
        return;
    n->UpdateWorldLoc();
    if (!b)
        return;
    int type = b->data ? b->data->motionType : 5;
    if (type == 5 && b->FUN_00c87a40())
        return;
    if (!b->data)
        return;
    const Transform* world = &n->world;
    Quaternion rot;
    rot.FUN_00a6df40(&world->rotate);
    if (flagSet(6))
    {

        FUN_004a3e00(&forcedPos, &world->translate);

        forcedQ.x = rot.x;
        forcedQ.y = rot.y;
        forcedQ.z = rot.z;
        forcedQ.w = rot.w;
        forcedQ.FUN_005611c0();
        DAT_01267b80.Lock(0);
        b->vtable->SetGeometryTransform(b, &forcedPos, &forcedQ);
        DAT_01267b80.unlock();
    }
    else if (!n->flagSet(22) && !n->flagSet(27) && !n->flagSet(3) && !n->flagSet(4))
    {

        FUN_004a3e00(&distancePos, &world->translate);
        b->vtable->getPosition(b, &old);
        __m128 delta = _mm_sub_ps(distancePos.quad, old.quad);
        __m128 sq = _mm_mul_ps(delta, delta);
        __m128 y = _mm_shuffle_ps(sq, sq, 0x55);
        __m128 z = _mm_shuffle_ps(sq, sq, 0xaa);
        float dist;
        _mm_store_ss(&dist, _mm_add_ss(z, _mm_add_ss(y, sq)));
        if (dist > 1.0f)
        {
            if (FUN_0047b470())
            {
                b->FUN_00c8e160(&world->translate, &rot, &DAT_01267b80);
                return;
            }
            if (FUN_00c8cce0(&type))
            {
                b->FUN_00c8e160(&world->translate, &rot, &DAT_01267b80);
                return;
            }

            FourFloatVector nearPos;
            FUN_004a3e00(&nearPos, &world->translate);

            nearQ.x = rot.x;
            nearQ.y = rot.y;
            nearQ.z = rot.z;
            nearQ.w = rot.w;
            nearQ.FUN_005611c0();
            DAT_01267b80.Lock(0);
            b->vtable->SetGeometryTransform(b, &nearPos, &nearQ);
            DAT_01267b80.unlock();
        }
        else
        {
            const FourFloatVector* linearPtr = b->FUN_00560d80();
            __m128 scalarTolerance = _mm_load_ss(&DAT_01017d00);
            __m128 tolerance = _mm_shuffle_ps(scalarTolerance, scalarTolerance, 0);
            __m128 cmp =
                _mm_cmple_ps(_mm_and_ps(_mm_sub_ps(linearPtr->quad, DAT_01267e30.quad), DAT_01017d10.quad), tolerance);
            if ((_mm_movemask_ps(cmp) & 15) != 15)
                b->FUN_00561690(&DAT_01267e30);
            __m128 angular = b->FUN_00560e10()->quad;
            cmp = _mm_cmple_ps(_mm_and_ps(_mm_sub_ps(angular, DAT_01267e30.quad), DAT_01017d10.quad), tolerance);
            if ((_mm_movemask_ps(cmp) & 15) != 15)
                b->FUN_005617c0(&DAT_01267e30);
        }
    }
    else
    {
        if (FUN_0047b470())
        {
            b->FUN_00c8e160(&world->translate, &rot, &DAT_01267b80);
            return;
        }
        if (FUN_00c8cce0(&type))
        {
            b->FUN_00c8e160(&world->translate, &rot, &DAT_01267b80);
            return;
        }

        FUN_004a3e00(&flaggedPos, &world->translate);

        flaggedQ.x = rot.x;
        flaggedQ.y = rot.y;
        flaggedQ.z = rot.z;
        flaggedQ.w = rot.w;
        flaggedQ.FUN_005611c0();
        DAT_01267b80.Lock(0);
        b->vtable->SetGeometryTransform(b, &flaggedPos, &flaggedQ);
        DAT_01267b80.unlock();
    }
}
}  // namespace fnv_00c65b00
