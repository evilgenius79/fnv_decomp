
// src/fallout/ai/combat/projectile_gf_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /Od /Oy- /GS /EHsc /Gy /GF (unit src/fallout/ai/combat/projectile.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

#include "projectile_decls.h"

// FUN_009c0d80 reconstruction WIP.
// Built on unverified prior work by "another contributor" (2026-10-24) and an earlier
// "you" attempt (2026-10-23); logic revalidated and conventions corrected under this
// claim by GLM (Z.ai), agent zai_coord_01. Credit for the overall control-flow
// reconstruction belongs to the prior contributors.
// Build flags: /MT /O2 /GS /EHsc /Gy. __cdecl, caller pops, 6 params.
struct Vec3
{
    float components[3];
    Vec3();
    void FUN_00439180(float);
    Vec3 ApplyScaled(float);
    Vec3 FUN_00439e90(const Vec3&);
    Vec3 FUN_00439ef0(const Vec3&);
    float FUN_00457990();
    float DotProduct(const Vec3&);
};
struct __declspec(align(16)) PhysicsVector
{
    float x, y, z, w;
};
struct EventInfo
{
    PhysicsVector normal;  // 16
    float time;            // 0x10
    int unk14, unk18, unk1c;
    char indexBytes[32];  // 0x20..0x40
    int unk40, unk44, unk48, unk4c;
    int eventHandle;  // 0x50
    EventInfo* FUN_00696c30(EventInfo* entry);
    EventInfo* FUN_009c1a70(EventInfo* entry);
};
struct EventCursor
{
    int FUN_00726070();
    EventInfo* GetEntryAt(int index);
};
struct EventStream
{
    EventCursor* FUN_00460140();
};
struct Filter
{
    unsigned int value;
};
struct FormBase
{
    int FUN_0043b4d0();
    bool FUN_009c19e0();
};
struct EventEntity
{
    void** vtable;
    FormBase* FUN_0043b4f0(unsigned int* out);
    void* FUN_005d43c0();
};
struct Scene
{
    EventStream* FUN_008cdd90();
    void FUN_004585f0(Vec3* out);
    void FUN_004587f0(Vec3* out);
    void FUN_005dbe60(Vec3* out);
    void FUN_009c1a20(Vec3* out);
    Filter* ConstructCF845(Filter* out);
};
struct AnimationPacket
{
    EventStream* FUN_008cdd90();
    PhysicsVector rayOrigin, rayDirection;  // 0x00..0x20
    unsigned int filter;                    // 0x20
    unsigned int unk24, unk28, unk2c;
    EventInfo hit;                  // 0x30..0x84
    PhysicsVector cachedDirection;  // 0x90
    void* world;                    // 0xa0
    int unka4, unka8;
    bool unkac;
    AnimationPacket();
    void FUN_004a3f70(unsigned int filterValue);
    void FUN_004a3da0(Vec3* origin);
    void FUN_007f68a0(Vec3* direction);
    void FUN_004a3fb0(void* collector);
};
struct HitEntry
{
    EventInfo info;
};
struct HitCollection
{
    HitEntry* entries;
    int size, capacity, allocator;
    HitEntry inlineHits[8];
};
struct __declspec(align(16)) Collector
{
    void** vtable;
    float earlyOutFraction;
    int unk08, unk0c;
    HitCollection hits;  // 0x10.. ; total size 0x340
    Collector();
    void FUN_004a3bc0();
    ~Collector()
    {
        FUN_004a3bc0();
    }
};
struct SoundSource
{
    const char* FUN_00511840();
};
struct RenderManager
{
    SoundSource* FUN_004fd3e0();
};
struct VisualNode
{
    Vec3* FUN_0045bb80();
};
struct Controller
{
    void** vtable;
    RenderManager* FUN_004181e0();
    Controller* FUN_00476c90();
    bool FUN_00444d00(int);
    void FUN_009795c0(float);
    void FUN_009c4e60(Vec3 point, bool flag);
    EventEntity* FUN_00874480();
};
struct AudioPlaybackHandle
{
    unsigned int soundID;
    bool assumeSuccess;
    int state;
    void FUN_00483710();
    ~AudioPlaybackHandle()
    {
        FUN_00483710();
    }
    void SetPos(float, float, float);
    void Play(int);
};
struct AudioSystem
{
    AudioPlaybackHandle FUN_00ad7480(const char* path, int flags, SoundSource* source);
    void* FUN_0044edb0();
};
struct WorldTarget
{
    void** vtable;
};
struct Color
{
    float red, green, blue, alpha;
    void FUN_00414430(float, float, float, float);
};
struct RenderElement
{
    void FUN_00a5a040();
    void FUN_00440460(Vec3* at);
};
struct AudioController
{
    void FUN_00458e20(RenderElement* element, float volume);
};
struct FloatSetting
{
    int type;
    float value;
    float* FUN_00403e20();
};
struct FormTypeDescriptor;
extern FormTypeDescriptor DAT_01268444;
extern AudioController* DAT_011dea10;
extern EventEntity* DAT_011dea3c;
extern unsigned char DAT_011f20a4;
extern FloatSetting DAT_011f210c;
extern float DAT_010162c0, DAT_01017870, DAT_0101712c;
extern double DAT_010231b0, DAT_01088210;
extern Vec3 DAT_011a9484;
extern int FUN_004b5820(int handle);
extern EventEntity* FUN_0056f930(int handle);
extern int FUN_004b5950(int handle);
extern EventEntity* FUN_004b5a80(int form);
extern void FUN_005ac750(Controller* player, void* sound, int flags);
extern bool FUN_0043b300(FormTypeDescriptor* descriptor, EventEntity* entity);
extern EventEntity* FUN_004b5260(int handle);
struct ParentEntity : EventEntity
{
    EventEntity* FUN_006fa820();
};
extern bool CanProjectileHit(EventEntity* reference, int eventHandle, Controller* player, int eventOwner);
extern bool FUN_009c5ba0(AnimationPacket* packet, int handle, int arg3, int arg4);
extern void FUN_004a3970(Vec3* out, EventInfo* info);
extern AudioSystem* FUN_00453a70();
extern Vec3 FUN_004a3760(float ratio, const Vec3& direction);
extern RenderElement* CreateOctahedron(float scale, Color* color, int arg3);
typedef int(__thiscall* GetKindFn)(EventEntity*);
typedef Vec3*(__thiscall* GetPositionFn)(EventEntity*);
typedef Vec3*(__thiscall* GetLocationFn)(WorldTarget*);
typedef VisualNode*(__thiscall* GetVisualFn)(Controller*);
typedef bool(__thiscall* DispatchFn)(Controller*, EventEntity*, Vec3*, Vec3*, int, int, int);
// @fnv 0x009c0d80
int __cdecl FUN_009c0d80(Scene* scene, Controller* player, int eventOwner, float* hitTime, bool acceptUnknown,
                         float maximumTime)
{
    if (eventOwner == 0 && player != 0)
        eventOwner = (int)player->FUN_004181e0();
    bool picked = false;
    int result = 0;
    if (scene != 0 && scene->FUN_008cdd90() != 0)
    {
        Vec3 initialPosition;
        Vec3 initialDirection;
        scene->FUN_004585f0(&initialPosition);
        scene->FUN_009c1a20(&initialDirection);
        bool partialMatch = false;
        EventEntity* lastReference = 0;
        for (int i = 0; !picked && i < scene->FUN_008cdd90()->FUN_00460140()->FUN_00726070(); ++i)
        {
            EventInfo info;
            info.FUN_00696c30(scene->FUN_008cdd90()->FUN_00460140()->GetEntryAt(i));
            if (info.time > maximumTime)
                continue;
            int handle = FUN_004b5820(info.eventHandle);
            EventEntity* reference = FUN_0056f930(handle);
            if (handle != 0)
            {
                bool candidate = true;
                int form = FUN_004b5950(info.eventHandle);
                EventEntity* entity2 = form != 0 ? FUN_004b5a80(form) : 0;
                if (entity2 != 0)
                {
                    candidate = false;
                    unsigned int filterA, filterB;
                    if (player != 0 && reference != 0 &&
                        (entity2->FUN_0043b4f0(&filterA)->FUN_0043b4d0() == 0x17 ||
                         entity2->FUN_0043b4f0(&filterB)->FUN_0043b4d0() == 0x18))
                    {
                        FUN_005ac750(player, reference->FUN_005d43c0(), 0x80);
                        if (player->FUN_00476c90() != 0)
                            FUN_005ac750(player->FUN_00476c90(), reference->FUN_005d43c0(), 0x100);
                    }
                    unsigned int filterC;
                    if (FUN_0043b300(&DAT_01268444, entity2) ||
                        (acceptUnknown && entity2->FUN_0043b4f0(&filterC)->FUN_0043b4d0() == 0x1e))
                    {
                        partialMatch = true;
                        lastReference = reference;
                        {
                            ParentEntity* parentId = (ParentEntity*)FUN_004b5260(handle);
                            EventEntity* parent2 = parentId != 0 ? parentId->FUN_006fa820() : 0;
                            if (parent2 != 0)
                            {
                                unsigned int filterD;
                                if (parent2->FUN_0043b4f0(&filterD)->FUN_009c19e0() ||
                                    ((GetKindFn)parent2->vtable[0x94 / 4])(parent2) == 0)
                                {
                                    AnimationPacket anim;
                                    Vec3 origin;
                                    scene->FUN_004585f0(&origin);
                                    Vec3 direction;
                                    scene->FUN_009c1a20(&direction);
                                    initialDirection.FUN_00439180(DAT_010162c0);
                                    direction.FUN_00439180(DAT_010162c0);
                                    Filter sceneFilter;
                                    anim.FUN_004a3f70(scene->ConstructCF845(&sceneFilter)->value);
                                    anim.FUN_004a3da0(&origin);
                                    anim.FUN_007f68a0(&direction);
                                    Collector collector;
                                    anim.FUN_004a3fb0(&collector);
                                    bool hit = FUN_009c5ba0(&anim, handle, 0, 1);
                                    if (hit)
                                    {
                                        if (anim.FUN_008cdd90()->FUN_00460140()->FUN_00726070() > 0)
                                        {
                                            info.FUN_009c1a70(anim.FUN_008cdd90()->FUN_00460140()->GetEntryAt(0));
                                            candidate = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            labelAfterPartial:
                if (!CanProjectileHit(reference, info.eventHandle, player, eventOwner))
                    candidate = false;
                if (candidate)
                {
                    if (player != 0)
                    {
                        Vec3 hitPoint = initialDirection.ApplyScaled(info.time);
                        Vec3 aimPoint = initialPosition.FUN_00439e90(hitPoint);
                        Vec3 tempPoint;
                        FUN_004a3970(&tempPoint, &info);
                        if (player->FUN_00444d00(1))
                        {
                            player->FUN_009795c0(hitPoint.FUN_00457990());
                            player->FUN_009c4e60(hitPoint, false);
                        }
                        int lastIndex = -1;
                        for (int k = 0; k < 8 && reinterpret_cast<int*>(info.indexBytes)[k] != -1; ++k)
                        {
                            lastIndex = reinterpret_cast<int*>(info.indexBytes)[k];
                        }
                        picked = ((DispatchFn)player->vtable[0x32c / 4])(player, reference, &aimPoint, &tempPoint,
                                                                         info.eventHandle, lastIndex, 0x24);
                        if (picked)
                            result = handle;
                    }
                    else
                    {
                        picked = true;
                        result = handle;
                    }
                    if (picked && hitTime != 0)
                        *hitTime = info.time;
                }
            }
        }
        if (player != 0)
        {
            if (!picked)
            {
                if (maximumTime != DAT_010231b0)
                {
                    Vec3 away = initialDirection.ApplyScaled(maximumTime);
                    Vec3 dst = initialPosition.FUN_00439e90(away);
                    if (player->FUN_00444d00(1))
                    {
                        player->FUN_009795c0(away.FUN_00457990());
                        player->FUN_009c4e60(away, false);
                    }
                    ((DispatchFn)player->vtable[0x32c / 4])(player, 0, &dst, &DAT_011a9484, 0, -1, 8);
                }
            }
            if (!picked && partialMatch)
            {
                if (lastReference != 0 && lastReference == DAT_011dea3c)
                {
                    Vec3 impact;
                    scene->FUN_005dbe60(&impact);
                    if (player->FUN_004181e0() != 0)
                    {
                        if (player->FUN_004181e0()->FUN_004fd3e0() != 0)
                        {
                            int flags = 0x102;
                            AudioPlaybackHandle sound =
                                FUN_00453a70()->FUN_00ad7480(player->FUN_004181e0()->FUN_004fd3e0()->FUN_00511840(),
                                                             flags, player->FUN_004181e0()->FUN_004fd3e0());
                            sound.SetPos(impact.components[0], impact.components[1], impact.components[2]);
                            sound.Play(0);
                            if (DAT_011f20a4 != 0 && ((GetVisualFn)player->vtable[0x1d0 / 4])(player) != 0)
                            {
                                Color color;
                                color.FUN_00414430(0.0f, 1.0f, 1.0f, DAT_01017870);
                                RenderElement* visual = CreateOctahedron(DAT_0101712c, &color, 1);
                                visual->FUN_00a5a040();
                                visual->FUN_00440460(((GetVisualFn)player->vtable[0x1d0 / 4])(player)->FUN_0045bb80());
                                DAT_011dea10->FUN_00458e20(visual, *DAT_011f210c.FUN_00403e20());
                            }
                        }
                    }
                }
            }
            else if (player->FUN_004181e0()->FUN_004fd3e0() != 0 &&
                     ((picked && lastReference != DAT_011dea3c) || !picked) && player->FUN_00874480() != DAT_011dea3c &&
                     FUN_00453a70()->FUN_0044edb0() != 0)
            {
                Vec3 at, saved, direction, extra, position;
                WorldTarget* world = (WorldTarget*)FUN_00453a70()->FUN_0044edb0();
                position = *((GetLocationFn)world->vtable[3])(world);
                if (lastReference != 0)
                    saved = *((GetPositionFn)lastReference->vtable[0x1f4 / 4])(lastReference);
                else
                    scene->FUN_004587f0(&saved);
                scene->FUN_004585f0(&at);
                direction = saved.FUN_00439ef0(at);
                extra = position.FUN_00439ef0(at);
                float mag = extra.DotProduct(direction);
                float len = direction.DotProduct(direction);
                float ratio = mag / len;
                Vec3 projected = at.FUN_00439e90(FUN_004a3760(ratio, direction));
                float distance = position.FUN_00439ef0(projected).FUN_00457990();
                if (distance < DAT_01088210)
                {
                    int flags = 0x102;
                    AudioPlaybackHandle sound =
                        FUN_00453a70()->FUN_00ad7480(player->FUN_004181e0()->FUN_004fd3e0()->FUN_00511840(), flags,
                                                     player->FUN_004181e0()->FUN_004fd3e0());
                    sound.SetPos(projected.components[0], projected.components[1], projected.components[2]);
                    sound.Play(0);
                    if (DAT_011f20a4 != 0)
                    {
                        Color color;
                        color.FUN_00414430(0.0f, 1.0f, 1.0f, DAT_01017870);
                        RenderElement* visual = CreateOctahedron(DAT_0101712c, &color, 1);
                        visual->FUN_00a5a040();
                        visual->FUN_00440460(&projected);
                        DAT_011dea10->FUN_00458e20(visual, *DAT_011f210c.FUN_00403e20());
                    }
                }
            }
        }
    }
    return result;
}
